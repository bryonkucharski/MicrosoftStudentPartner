/*
    * Demonstration of turning on each color of an RGB LED for one second
    * Created by Bryon Kucharski
    * Used in the Microsoft Student Partner October Workshop at Wentworth Institute of Technology
*/


int redLED = D0;            //assign red led to digital pin 0
int greenLED = D1;          //assign green led to digital pin 1
int blueLED = D2;           //assign green led to digital pin 2

void setup() {

  pinMode(redLED, OUTPUT);  //set red led as output
  pinMode(greenLED OUTPUT); //set green led as output
  pinMode(blueLED, OUTPUT); //let blue led as output
}

void loop() 
{

  
  digitalWrite(redLED, HIGH); //turn on red led 
  delay(1000);                //wait a second
  digitalWrite(redLED, LOW);  // turn off red led
  delay(1000);                //wait a second
  
  digitalWrite(greenLED, HIGH); //turn on green led
  delay(1000);                  //wait a second
  digitalWrite(greenLED, LOW);  //turn off green led
  delay(1000);                 // wait a second
  
  digitalWrite(blueLED, HIGH);  //turn on blue led
  delay(1000);                  //wait a second
  digitalWrite(blueLED, LOW);   //turn off blue led
  delay(1000);                  //wait a second
  
}
