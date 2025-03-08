#include "BluetoothSerial.h"

//Becuri
#define B1 16
#define B2 17
#define B3 5
#define B4 18
#define B5 19
#define B6 21
#define B7 22
#define B8 15

//Ecran
#define A 0
#define B 32
#define C 27
#define D 14
#define E 26
#define F 13
#define G 12
#define DP 1
#define DIGIT1 25
#define DIGIT2 23


BluetoothSerial ESP_BT;

bool run2=false;
bool run0=false;
bool run8=false;


void setup(){
  Serial.begin(115200);
  ESP_BT.begin("Mihai si Adrian Echipa 10");
  Serial.println("Bluetooth Device is Ready to Pair"); 
  delay(1000); // give me time to bring up serial monitor

  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(B3, OUTPUT);
  pinMode(B4, OUTPUT);
  pinMode(B5, OUTPUT);
  pinMode(B6, OUTPUT);
  pinMode(B7, OUTPUT);
  pinMode(B8, OUTPUT);

  pinMode(A, OUTPUT); //A
  pinMode(B, OUTPUT); //B
  pinMode(C , OUTPUT); //C
  pinMode(D, OUTPUT); //D
  pinMode(E, OUTPUT); //E
  pinMode(F, OUTPUT); //F
  pinMode(G, OUTPUT); //G
  pinMode(DP, OUTPUT); //DP
  pinMode(DIGIT1,OUTPUT);
  pinMode(DIGIT2,OUTPUT);

  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(33, INPUT);
}


void grup1On(){
  digitalWrite (B1, HIGH);
  delay(500);

  digitalWrite (B2, HIGH);
  delay(500);

  digitalWrite (B3, HIGH);
  delay(500);

  digitalWrite (B4, HIGH);
}


void grup2On(){
  digitalWrite (B8, HIGH);
  delay(1000);

  digitalWrite (B7, HIGH);
  delay(1000);

  digitalWrite (B6, HIGH);
  delay(1000);

  digitalWrite (B5, HIGH);
}


void grup1si2On(){
  digitalWrite (B1, HIGH);
  digitalWrite (B2, HIGH);
  digitalWrite (B3, HIGH);
  digitalWrite (B4, HIGH);
   
  digitalWrite (B5, LOW);
  digitalWrite (B6, LOW);
  digitalWrite (B7, LOW);
  digitalWrite (B8, LOW);

  delay (2000);

  digitalWrite (B1, LOW);
  digitalWrite (B2, LOW);
  digitalWrite (B3, LOW);
  digitalWrite (B4, LOW);

  digitalWrite (B5, HIGH);
  digitalWrite (B6, HIGH);
  digitalWrite (B7, HIGH);
  digitalWrite (B8, HIGH);

  delay (2000);
}


void grupOff(){
  digitalWrite (B1, LOW);
  digitalWrite (B2, LOW);
  digitalWrite (B3, LOW);
  digitalWrite (B4, LOW);
  digitalWrite (B5, LOW);
  digitalWrite (B6, LOW);
  digitalWrite (B7, LOW);
  digitalWrite (B8, LOW);
}


void mesaj2(){
  digitalWrite(DIGIT1,LOW);
  digitalWrite(DIGIT2,HIGH);
  digitalWrite(A,LOW); //a
  digitalWrite(B,LOW); //b
  digitalWrite(C,LOW); //c
  digitalWrite(D,HIGH); //d
  digitalWrite(E,HIGH); //e
  digitalWrite(F,HIGH); //f
  digitalWrite(G,HIGH); // g
  digitalWrite(DP,LOW); // DP
 
  delay(5);

  digitalWrite(DIGIT1,HIGH);
  digitalWrite(DIGIT2,LOW);
  digitalWrite(A,LOW); //a
  digitalWrite(B,HIGH); //b
  digitalWrite(C,HIGH); //c
  digitalWrite(D,LOW); //d
  digitalWrite(E,LOW); //e
  digitalWrite(F,LOW); //f
  digitalWrite(G,LOW); // g
  digitalWrite(DP,LOW); // DP
 
   delay(5);
}

void mesaj0(){
  digitalWrite(DIGIT1,LOW);
  digitalWrite(DIGIT2,HIGH);
  digitalWrite(A,LOW); //a
  digitalWrite(B,LOW); //b
  digitalWrite(C,LOW); //c
  digitalWrite(D,HIGH); //d
  digitalWrite(E,HIGH); //e
  digitalWrite(F,HIGH); //f
  digitalWrite(G,HIGH); // g
  digitalWrite(DP,LOW); // DP
 
  delay(5);

  digitalWrite(DIGIT1,HIGH);
  digitalWrite(DIGIT2,LOW);
  digitalWrite(A,HIGH); //a
  digitalWrite(B,HIGH); //b
  digitalWrite(C,LOW); //c
  digitalWrite(D,HIGH); //d
  digitalWrite(E,HIGH); //e
  digitalWrite(F,LOW); //f
  digitalWrite(G,HIGH); // g
  digitalWrite(DP,LOW); // DP
 
  delay(5);
}

void mesaj8(){

  digitalWrite(DIGIT1,LOW);
  digitalWrite(DIGIT2,HIGH);
  digitalWrite(A,LOW); //a
  digitalWrite(B,LOW); //b
  digitalWrite(C,LOW); //c
  digitalWrite(D,HIGH); //d
  digitalWrite(E,HIGH); //e
  digitalWrite(F,HIGH); //f
  digitalWrite(G,HIGH); // g
  digitalWrite(DP,LOW); // DP
 
  delay(200);

  digitalWrite(DIGIT1,HIGH);
  digitalWrite(DIGIT2,LOW);
  digitalWrite(A,HIGH); //a
  digitalWrite(B,HIGH); //b
  digitalWrite(C,HIGH); //c
  digitalWrite(D,HIGH); //d
  digitalWrite(E,HIGH); //e
  digitalWrite(F,HIGH); //f
  digitalWrite(G,HIGH); // g
  digitalWrite(DP,LOW); // DP
 
  delay(200);
}


void sterge(){
  digitalWrite(DIGIT1,LOW);
  digitalWrite(DIGIT2,HIGH);
  digitalWrite(A,LOW); //a
  digitalWrite(B,LOW); //b
  digitalWrite(C,LOW); //c
  digitalWrite(D,LOW); //d
  digitalWrite(E,LOW); //e
  digitalWrite(F,LOW); //f
  digitalWrite(G,LOW); // g
  digitalWrite(DP,LOW); // DP
 
  delay(5);

  digitalWrite(DIGIT1,HIGH);
  digitalWrite(DIGIT2,LOW);
  digitalWrite(A,LOW); //a
  digitalWrite(B,LOW); //b
  digitalWrite(C,LOW); //c
  digitalWrite(D,LOW); //d
  digitalWrite(E,LOW); //e
  digitalWrite(F,LOW); //f
  digitalWrite(G,LOW); // g
  digitalWrite(DP,LOW); // DP

  delay(5);
}


void loop()
{

  //Pinul TOUCH2

  if(digitalRead(2)==1) {
    if(run2==false){
      ESP_BT.println("Pinul TOUCH2 este apasat");
      run2=true;
      grup1On();
    }
    mesaj2();
  }
  else if(digitalRead(2)==0) {
    if(run2==true){
      ESP_BT.println("Pinul TOUCH2 nu mai este apasat");
      run2=false;
      grupOff();
      sterge();
    } 
  }

  //Pinul TOUCH0
  
  if(digitalRead(4)==1){
    
   if(run0==false){
      ESP_BT.println("Pinul TOUCH0 este apasat");
      run0=true;
      grup2On();
    }
    mesaj0();
  } 
  else if(digitalRead(4)==0 && run0==true){
      ESP_BT.println("Pinul TOUCH0 nu mai este apasat");
      run0=false;
      grupOff();
      sterge();
  }


  //Pinul TOUCH8

  if(digitalRead(33)==1){
    mesaj8();  
    if(run8==false){
      ESP_BT.println("Pinul TOUCH8 este apasat");
      run8=true;
    }
    grup1si2On();
  } 
  else if(digitalRead(33)==0 && run8==true){
      ESP_BT.println("Pinul TOUCH8 nu mai este apasat");
      run8=false;
      grupOff();
      sterge();
  }
}