/*
    * Demonstration of the Particle.function.
    * Use a POST HTTP request to call his function. The functions triggers/untriggers a relay based on paramater from HTTP Request.
    * example curl: -curl https://api.particle.io/v1/devices/{YOUR DEVICE ID GOES HERE}/relay -d access_token={YOUR ACCESS TOKEN GOES HERE} -d command=on
    * Created by Bryon Kucharski
    * Used in the Microsoft Student Partner October Workshop at Wentworth Institute of Technology
*/

int relayPin = D0; //assign relay trigger to digital pin 0

void setup() {
    
    pinMode(relayPin, OUTPUT); // set the relay trigger to output
    
    //Publish the function called relayToggle to the Particle Cloud API. This function could be called with any POST request
    //example: https://api.particle.io/v1/devices/{YOUR DEVICE ID GOES HERE}/relay
    Particle.function("relay",relayToggle);
    
}

void loop() {
    //empty loop
}
//function called by a HTTP Request
int relayToggle(String command)
{
    //if parameter from the HTTP Request is "on" set relay high and return 1
    //if parameter from the HTTP Request is "off" set the relay low and return 0;
    if(command == "on"){
        digitalWrite(relayPin, HIGH);
        return 1;
    }
   else if(command == "off"){
        digitalWrite(relayPin, LOW);
        return 0;
    }
    //error in request
    else{
        return -1;
    }
        
}