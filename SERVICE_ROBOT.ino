// OUR WEBSITE 
// Http://eccentrictech.website3.me
// YOUTUBE ECENTRIC TECH

// ALL CONNECTIONS MUST BE ACCORDING TO       CIRCUIT DIAGRAM 

#include<Servo.h>
Servo myservo;
int Speed = 250;
int trig = 9;
int echo = 8;
char t; 
  
      
void setup()
     {
    myservo.attach(10);
pinMode(2,OUTPUT);   
pinMode(3,OUTPUT);   
pinMode(4,OUTPUT);   
pinMode(5,OUTPUT);  
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);   
Serial.begin(9600);
 
}
long dura, dis;

 
void loop ()
 
 { digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);  
  dura = pulseIn(echo, HIGH);
  dis = dura/58.2; 

  
 if(Serial.available()){
   t = Serial.read();
  Serial.println(t);

switch (t) {
            case 'F':      //FRONT
            forward();
            break;        
            case 'S':
            stop();
            break;
            case 'B':
            backward();
            break;
            case 'L':
            left();
            break;
            case 'R':
            right();
            break;  
/*PATH 1 */ case 'X':
            forward();
            delay(3000);
            stop();
            delay(50);
            left();
            delay(900);
            stop();
            delay(50);
            forward();
            delay(3000);
            stop();
            delay(50);
            right();
            delay(900);
            stop();
            delay(50);
            forward();
            delay(3000);
            stop();
            break;
            
            case 'W':
            digitalWrite(13,HIGH); 
            break;
            case 'w':
            digitalWrite(13,LOW); 
            break;
            case 'U':
            digitalWrite(12,HIGH); 
            break;
            case 'u':
            digitalWrite(12,LOW); 
            break; 
      
       
   
  }                             
 } 
}
void forward()
    
    {
        digitalWrite(4,Speed);
        digitalWrite(3,Speed);
        digitalWrite(6,Speed);
        digitalWrite(7,Speed);
}
void backward()
    {   digitalWrite(5,Speed);
        digitalWrite(2,Speed);
        digitalWrite(6,Speed);
        digitalWrite(7,Speed);
}

void left(){
  
        digitalWrite(3,Speed);
        digitalWrite(5,Speed);  
        digitalWrite(6,Speed);
        digitalWrite(7,Speed);
}
void right(){

        digitalWrite(4,Speed);
        digitalWrite(2,Speed);
        digitalWrite(6,Speed);                 
        digitalWrite(7,Speed);
    }
 

void stop(){
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
} 


 