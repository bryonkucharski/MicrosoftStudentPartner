/*
    * An example of Webhooks using Particle.subscribe and Particle.publish using the Particle Core
    * Make a "connection" to the webhook created on your particle account by callling Particle.subscribe()
    * Trigger the webhook and send the HTTP Reauest to a RestAPI by calling particle.publish()
    * Created by Bryon Kucharski
    * Used for the Microsoft Student Partner October Workshop at Wentworth Institute of Technology
*/

int redLED = D0;
int greenLED = D1;
int blueLED = D2;


void setup() {
    
    //begin serial port at 9600 Baud Rate
    Serial.begin(9600);
    
    //set LED Pins to output
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    pinMode(blueLED, OUTPUT);
    
   //Subscribe to events created on your account. In this case, we want a response from the Boston_Temp Webhook
   //myHandler function will be called when the webhook is called.
    Particle.subscribe("hook-response/Boston_Temp", myHandler, MY_DEVICES);
}

void loop() {

    Serial.print("\n--Starting Request--\n");

   // Trigger the webhook called Boston_Temp through the Particle Cloud
    Particle.publish("Boston_Temp");
    
    //flash blue led
    toggleLED(blueLED);
    
    Serial.print("--Response Recieved--\n");
    
    //wait one minute for another request
    delay(60000);

}

//function called when Boston_Temp webhook is triggered
void myHandler(const char *event, const char *data)
{
    //flash red led
    toggleLED(redLED);
    
    //displays the full name of the published event
    Serial.print("Event Recieved: ");
    Serial.print(event);
    
    //displays the data that came along with the event
    Serial.print("\nData Recieved: ");
    Serial.print(data);
    
    Serial.print("\n");
    
    //flash green led
    toggleLED(greenLED);
}
//turns on led for one second then turns off.
void toggleLED(int ledPin)
{
    digitalWrite(ledPin,HIGH);
    delay(1000);
    digitalWrite(ledPin,LOW);
}
