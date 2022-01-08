#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#ifndef STASSID
#define STASSID "AP SSID"  //The name of AP
#define STAPSK  "xxxxx"    //Password
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

ESP8266WebServer server(80);

void handleRoot() {  //Content displayed when a visitor enters the main page
  server.send(200, "text/plain", "Hello From ESP8266 !");
}

void handleNotFound() {  //The content displayed when the page is not found
  server.send(404, "text/plain", "File Not Found");
}

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Waiting for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Display the IP in the monitor window

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);  //Bind the program that will be triggered by the main web page

  server.onNotFound(handleNotFound);  //Bind the program that will be triggered when the web page is not found

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}