//----------------------------
//Author      : Ismail Sghir
//Last updated: 12/30/2020
//----------------------------

#include <dht.h>
#define dht_apin A0

dht DHT;
int ledPin = 6;                 //LED pin
int trigPin = 7;                //Trigger pin
int counter = 0;                //Counter set to 0
int heatSetTo = 72;             //Temperature set to 72 F 

void setup()
{              
    pinMode(ledPin, OUTPUT);                //set pin 6 to OUTPUT for LED indicator
    pinMode(trigPin, OUTPUT);               //set pin 7 to OUTPUT to turn ON/OFF the heater
    Serial.begin(9600);                     //setup the serial monitor
    delay(2000);                            //wait 2s before reading data from sensor
 }

void loop()
{
 
    DHT.read11(dht_apin);                               //Read the values from the sensor
    int temp = ((int)DHT.temperature*1.8)+32;           //Convert temperature into int a F
    Serial.print("Current humidity = ");                //Print the humidity %
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");                     //Print the temperature
    Serial.print(temp);
    Serial.println(" F  ");
    
    //*** THIS CONDITION BELOW IS VERY IMPORTANT PLEASE CHECK README FILE FOR MORE DETAILS ***
    
    if (counter <= 0)                                   //checks if the counter is 0 or less
    {
      //120 * 5s = 600s = 10 min 
      //this will keep the heat status stable for 10 minutes
        counter = 24;                                   //Reset the counter to 24 
        if (temp > heatSetTo)                           //If temperature is 
        {
            digitalWrite(ledPin, LOW);                  //Turn OFF the indicator led       
            digitalWrite(trigPin, LOW);                 //Turn OFF the heater
        }
        else 
        {
            digitalWrite(ledPin, HIGH);                 //Turn ON the indicator led       
            digitalWrite(trigPin, HIGH);                //Turn ON the heater
        }
    }
    Serial.print("Heat Status = ");                     //Print the heat status 
    if(trigPin) 
        Serial.println("ON");
    else
        Serial.println("OFF");
    Serial.print("Counter = ");                         //Print the counter value
    Serial.println(counter);

    delay(5000);                                        //wait 5 seconds 
    counter--;                                          //Decrement counter and loop again
}
