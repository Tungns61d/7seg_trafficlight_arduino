

#include "SevSeg.h"

//Create an instance of the object.
SevSeg myDisplay;

//Create global variables
unsigned long timer;
unsigned long timer_1;
unsigned long timer_2;


int time_green = 5;
int time_red = 4;
int time_yellow = 2;


int dici_green=time_green*10+10;
int dici_red=time_red*10+10;
int dici_yellow=time_yellow*10+10;

long interval = (time_green+time_red+time_yellow)*1000+3000;//12000; 
//-----------------------------
const int redPin =  A0;      // the number of the red LED pin

const int yellowPin =  A1;      // the number of the yellow LED pin

const int greenPin =  A2;      // the number of the green LED pin

// Variables will change:

int redState = LOW;             // redState used to set the red LED

int yellowState = LOW;             // yellowState used to set the yellow LED

int greenState = LOW;             // greenState used to set the green LED

long StartTime = 0;        // will store last time the traffic sequence was started


char tempString[10];
//char tempString_1[10];
//char tempString_2[10];
//char tempString_3[10];

void setup()
{

  int displayType = COMMON_ANODE; //Your display is either common cathode or common anode

  
    //This pinout is for a bubble dispaly
       //Declare what pins are connected to the GND pins (cathodes)
       int digit1 = 9; //Pin 12
       int digit2 = 10; //Pin 9
       int digit3 = 11; //Pin 8
       int digit4 = 12; //Pin 6
       
       //Declare what pins are connected to the segments (anodes)
       int segA = 2; //Pin 11
       int segB = 3; //Pin 7
       int segC = 4; //Pin 4
       int segD = 5; //Pin 2
       int segE = 6; //Pin 1
       int segF = 7; //Pin 10
       int segG = 8; //Pin 5
       int segDP= 13; //Pin 
       //----------------
       pinMode(redPin, OUTPUT);  

pinMode(yellowPin, OUTPUT);      

pinMode(greenPin, OUTPUT);
   //--------------------------
  int numberOfDigits = 4; //Do you have a 1, 2 or 4 digit display?

  myDisplay.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);
  
  myDisplay.SetBrightness(100); //Set the display to 100% brightness level
  
  
  timer= millis();
  timer_1 = millis();
  timer_2 = millis();
  

}

void loop()
{
  //Example ways of displaying a decimal number
   //Used for sprintf
    myDisplay.DisplayString(tempString, 0); 
  
  
  unsigned long CheckTime = millis();
  
  unsigned long elapsedTime = CheckTime - StartTime;
    
  if(elapsedTime > interval) {

 StartTime = CheckTime;   

  }  
  
  if (elapsedTime < time_green*1000+1000){
    //dici_green=time_green*10+10;
  count_green();
  
  //--------------
  
  redState = LOW;             

yellowState = LOW;            

greenState = HIGH;  
  }
  
  int sum1=time_green*1000+time_yellow*1000+2000;
  if (elapsedTime > time_green*1000+1000 &&elapsedTime <= sum1){
//dici_yellow=time_yellow*10+10;
  count_yellow();

//---------------
 redState = LOW;             

yellowState = HIGH;            

greenState = LOW ;  
  }


  if (elapsedTime > sum1){
//dici_red=time_red*10+10;
  count_red();
  
  //----------------
redState = HIGH;             

yellowState = LOW;            

greenState = LOW ;  
  }
  digitalWrite(redPin,redState);

 digitalWrite(greenPin,greenState);

 digitalWrite(yellowPin,yellowState);

  
  //if(dici_yellow==0) dici_yellow=dici_green;
//count_from_15();
}

void count_yellow(){
  
  sprintf(tempString, "%5d", dici_yellow);
  Serial.print(dici_yellow);


  if (millis() - timer_1>=100)
  {
    timer_1 = millis();
    dici_yellow--;
    
  }
 if(dici_yellow==0){
   dici_yellow=time_yellow*10+10;
 }
 
}


  
void count_red(){
  
  sprintf(tempString, "%5d", dici_red);
  


  if (millis() - timer_2>= 100)
  {
    timer_2 = millis();
    dici_red--;
    
  }  
  
  if(dici_red==0){
   dici_red=time_red*10+10;
 }
}
  
    void count_green(){
  
  sprintf(tempString, "%5d", dici_green);
  
  


  if (millis() - timer >= 100)
  {
    timer = millis();
    dici_green--;
    
  }  
  if(dici_green==0){
   dici_green=time_green*10+10;
 }
   
  
}


