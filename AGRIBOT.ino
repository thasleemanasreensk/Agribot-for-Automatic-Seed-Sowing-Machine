#include<SoftwareSerial.h>
SoftwareSerial BT(0,1);
String readvoice;
char c;
int f=6;
int motor1 =2;
int motor2 =3;
int motor3 =4;
int motor4 =5;
int ir1=8;
int s=A0;
int b=9;
int led=10;
void setup()
{
   // dht.begin();
  pinMode(f,OUTPUT);
    pinMode(b,OUTPUT);
    pinMode(ir1,INPUT);
      pinMode(s,INPUT);
  Serial.begin(9600);
  pinMode(motor1, OUTPUT); pinMode(motor3, OUTPUT);
  pinMode(motor2, OUTPUT); pinMode(motor4, OUTPUT);
  Serial.println("Welcome user");
  Serial.println("waiting for your command");
}
void loop()
{  int x=digitalRead(ir1);
   Serial.println("ir");
    Serial.println(x);
//    int y=analogRead(s);
//   Serial.println("gas");
//    Serial.println(y);
//      delay(1000);
//       int z=digitalRead(f);
//   Serial.println("fir");
//    Serial.println(z);
//    delay(2000);
// if(z==0)
// {
//    digitalWrite(b,HIGH);
//  }
//  else
//  {
//     digitalWrite(b,LOW);
//  }
    if(x==0)
  {
   digitalWrite(b,HIGH);
   delay(1000);
  } 
  else
  {
      digitalWrite(b,LOW);
      delay(1000);
  } 
//  if(y>=400)
//  {
//   digitalWrite(b,HIGH);
//  } 
//  else
//  {
//      digitalWrite(b,LOW);
//  } 
   while (Serial.available())
  {
    c = Serial.read();
  Serial.println(c);
  delay(1000);
  if(c =='a')
  {
    Serial.println("forward");
    delay(1000);
    digitalWrite(motor1,1); digitalWrite(motor2,0);
    digitalWrite(motor3,1);digitalWrite(motor4,0);
    //digitalWrite(fan,LOW);
    }
  if(c =='b')
  {
    Serial.println("backward");
    delay(1000);
    digitalWrite(motor1,0); digitalWrite(motor2,1);
   digitalWrite(motor3,0); digitalWrite(motor4,1);
    //digitalWrite(fan,LOW);
    
  }
  if(c =='c')
  {
    
    Serial.println("left");
    delay(1000);
    digitalWrite(motor1,0);digitalWrite(motor2,0);
    digitalWrite(motor3,1); digitalWrite(motor4,0); 
    //digitalWrite(fan,LOW);
    
  }
  if(c =='d')
  {
    Serial.println("right");
    delay(1000);
   digitalWrite(motor1,1); digitalWrite(motor2,0);
    digitalWrite(motor3,0); digitalWrite(motor4,0);
    //digitalWrite(fan,LOW);
    
  }
  
  if(c =='e')
  {
    Serial.println("stop");
    delay(1000);
    digitalWrite(motor1,0); digitalWrite(motor2,0);
    digitalWrite(motor3,0); digitalWrite(motor4,0);
    //digitalWrite(fan,LOW);
    
  }
   if(c =='s')
  {
    Serial.println("onn");
    digitalWrite(f,HIGH);
    
  }
  
  if(c =='m')
  {
    Serial.println("off");
    digitalWrite(f,LOW);
    
  }
  }
 }
  
