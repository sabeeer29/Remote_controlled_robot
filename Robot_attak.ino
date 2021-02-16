//---------ELECTRONOOBS----------//
//--------BT app control---------//
#include <Servo.h>


Servo myservo1; int angle_PortOuvert1=100;  int angle_PortFerme1=18;
Servo myservo2; int angle_PortOuvert2=85;  int angle_PortFerme2=165;


 
int speed1=255;
int speed2=255;

int Md1=2; //in2
int Md2=3;//in1

int Mg1=4;//in3
int Mg2=5;//in4

char ordre ;

void avancer(){
  analogWrite(Md2,0);
  analogWrite(Md1,255);  
  analogWrite(Mg1,0);
  analogWrite(Mg2,255);  
}


void arriere(){
 analogWrite(Md2,255);
  analogWrite(Md1,0);
  analogWrite(Mg1,255);
  analogWrite(Mg2,0);

}


void tour_droite(){

analogWrite(Md2,0);
  analogWrite(Md1,255);  
 analogWrite(Mg1,255);
  analogWrite(Mg2,0);
}


void tour_gauche(){
  analogWrite(Md2,255);
  analogWrite(Md1,0);
  analogWrite(Mg1,0);
  analogWrite(Mg2,255);  
}

void stope(){
  analogWrite(Md2,0);
  analogWrite(Md1,0);
  analogWrite(Mg1,0);
  analogWrite(Mg2,0);  
}





void initialisation(){
   myservo1.write(angle_PortFerme1);
   myservo2.write(angle_PortFerme2);
}

void ouverture(){
  myservo1.write(angle_PortOuvert1);
   myservo2.write(angle_PortOuvert2);
}


void fermeture(){
  myservo1.write(angle_PortFerme1);
   myservo2.write(angle_PortFerme2);
}

int Received=48;




void setup(){
pinMode(Md1,OUTPUT);
pinMode(Md2,OUTPUT);
pinMode(Mg1,OUTPUT);
pinMode(Mg2,OUTPUT);

myservo1.attach(8); 
myservo2.attach(9); 

initialisation();  

Serial.begin(9600);

}



void loop(){
 


 
 if(Serial.available()>0)
 { 
    Received = Serial.read();
    
 }



Serial.println(Received);
 switch(Received) {

  case 48:Received=48; stope(); break;
  case 50:avancer();break;
  case 51: arriere();break;
  case 52: tour_gauche();break;
  case 49: tour_droite();break;
  case 54:ouverture();Received=48; break;
  case 55:fermeture();Received=48;  break; 
}

  

 
}
