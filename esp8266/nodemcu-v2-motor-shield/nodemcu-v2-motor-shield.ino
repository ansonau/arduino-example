#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "your_network_ssid";
const char* password = "your_network_password";

ESP8266WebServer server(80);

void handleRoot() {
  server.send(200, "text/plain", "hello from Robot!");
}

void motor_forward(){
    digitalWrite(16, 1);
    digitalWrite(5, 0);
    digitalWrite(4, 1);
    digitalWrite(0, 0);
  }
void motor_stop(){
    digitalWrite(16, 0);
    digitalWrite(5, 0);
    digitalWrite(4, 0);
    digitalWrite(0, 0);
  }
void motor_back(){
    digitalWrite(16, 0);
    digitalWrite(5, 1);
    digitalWrite(4, 0);
    digitalWrite(0, 1);
  }

void motor_left(){
    digitalWrite(16, 0);
    digitalWrite(5, 1);
    digitalWrite(4, 1);
    digitalWrite(0, 0);
  }
void motor_right(){
    digitalWrite(16, 1);
    digitalWrite(5, 0);
    digitalWrite(4, 0);
    digitalWrite(0, 1);
  }

void setup(void){

  // prepare Motor Output Pins
  pinMode(16, OUTPUT);
  digitalWrite(16, 0);
  
  // prepare GPIO5 relay 1
  pinMode(5, OUTPUT);
  digitalWrite(5, 0);
  
  pinMode(4, OUTPUT);
  digitalWrite(4, 0);
  
  pinMode(0, OUTPUT);
  digitalWrite(0, 0);
  
  
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);

  server.on("/fw", []() {
    motor_forward();
    server.send(200, "text/plain", "Forward");
  });
  server.on("/bk", []() {
    motor_back();
    server.send(200, "text/plain", "Back");
  });

  server.on("/st", []() {
    motor_stop();
    server.send(200, "text/plain", "Stop");
  });
  server.on("/lt", []() {
    motor_left();
    server.send(200, "text/plain", "Left");
  });
  server.on("/rt", []() {
    motor_right();
    server.send(200, "text/plain", "Right");
  });

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}