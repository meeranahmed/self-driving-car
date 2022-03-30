#include <SoftwareSerial.h>

char Dir;
char readStringEsp();

int enA = 5;
int in1 = 8;
int in2 = 9;
int enB = 6;
int in3 =10;
int in4 = 11;
void setup(){
Serial.begin(9600); 
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);


}

void Forword(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4,HIGH); 
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  Serial.print("NO FORMAT");       // prints a label

  }
  
void Backword(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);  
  digitalWrite(in4, LOW)  ; 
  analogWrite(enA, 100);
  analogWrite(enB, 100);
}
void Right(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  analogWrite(enA, 0);
  analogWrite(enB, 170);
  Serial.print("NO FORMAT"); 
  }
void Left(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  analogWrite(enA, 170);
  analogWrite(enB, 0);
  }  
void Stop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);  
  digitalWrite(in4, LOW); 
  analogWrite(enA, 0);
  analogWrite(enB, 0); 
  }



void loop() {
//   put your man code here, to run repeatedly:
//delay(500);
//Left();
//Forword();
//Right();
//Backword();

  Dir = readStringEsp();
  Serial.println(Dir);

  if(Dir == 's'){
   Serial.println("Stop");
   Stop();
   }
  else if(Dir == 'b'){
    Serial.println("back");
    Backword();
    }
  else if(Dir == '1'){
    Serial.println("Forword");
    Forword();
    }
  else if(Dir == 'l'){
    Serial.println("Left");
    Left();
    }  
  else if(Dir == 'r'){
    Serial.println("Right");
    Right();
    } 
  }  

char readStringEsp() {
  char dataRecieved ;
  char chBuffer;
  while (Serial.available() > 0) {
    chBuffer =  (char) Serial.read();
    dataRecieved = chBuffer;
    Serial.println(dataRecieved);
    return dataRecieved;
   }  
   }
