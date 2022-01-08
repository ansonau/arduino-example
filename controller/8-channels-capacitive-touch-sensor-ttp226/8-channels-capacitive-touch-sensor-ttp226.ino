int key1=2; //OUT1
int key2=3; //OUT2
int key3=4; //OUT3
int key4=5; //OUT4
int key5=6; //OUT5
int key6=7; //OUT6
int key7=8; //OUT7
int key8=9; //OUT8
int ks1;
int ks2;
int ks3;
int ks4;
int ks5;
int ks6;
int ks7;
int ks8;

void setup(){
    Serial.begin(9600);
    pinMode(key1,INPUT);
    pinMode(key2,INPUT);
    pinMode(key3,INPUT);
    pinMode(key4,INPUT);
    pinMode(key5,INPUT);
    pinMode(key6,INPUT);
    pinMode(key7,INPUT);
    pinMode(key8,INPUT);
}

void loop(){
    int ks1=digitalRead(key1);
    if(ks1==HIGH){
        Serial.println("1");
    }
    int ks2=digitalRead(key2);
    if(ks2==HIGH){
       Serial.println("2");
    }
    int ks3=digitalRead(key3);
    if(ks3==HIGH){
       Serial.println("3");
    }
    int ks4=digitalRead(key4);
    if(ks4==HIGH){
        Serial.println("4");
    }
    int ks5=digitalRead(key5);
    if(ks5==HIGH){
        Serial.println("5");
    }
    int ks6=digitalRead(key6);
    if(ks6==HIGH){
       Serial.println("6");
    }
    int ks7=digitalRead(key7);
    if(ks7==HIGH){
      Serial.println("7");
    }
    int ks8=digitalRead(key8);
    if(ks8==HIGH){
      Serial.println("8");
    }
    delay(100);
}