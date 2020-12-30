# Temperature-and-Humidity-Sensor-DHT11-
A mini project that can serve as Home Thermostat or other purposes using DHT11 -Temperature and Humidity sensor

**Important**
1. Try this project without pluging it to your heater.
2. Set up your all the necessery wiring compile and upload your code to the microcontroller. 
3. Copy the actual temperature value of your envirement from the serial monitor
4. Change the value in line 13 to your envirement temperature.
```
int heatSetTo = 72;             //Temperature set to 72 F 
```
5. Compile and upload your code again. 
Your output might look like this,
```
Current humidity = 44%
temperature = 71 F
Heater Status = ON
...
Current humidity = 44%
temperature = 72 F
Heater Status = OFF
...
Current humidity = 44%
temperature = 71 F
Heater Status = ON
...
```
NOTE: Your code will loop so many times in a minute which can cause your heater to turn ON and OFF as it loops over and over which will damage your heater.
Therefore, a variable was implemented in the code and set equal to 0 to let the condition execute when the microcontroller is first powered.
```
int counter = 0; 
```
Everytime the program enters the condition, the counter will reset to value given 
```
counter = 120;                                   //Reset the counter to 120 `
```
Lastly, exit the condition wait 5 seconds, decrement the counter loop for (120) again till counter is 0
```
delay(5000);                                      //wait 5 seconds 
counter--;                                        //Decrement counter and loop again
```
>As a result, everytime the program turn ON or OFF the heater, it will loop 120 times and everyloop will wait 5 seconds (120*5s = 10 minutes) before turning ON or OFF the heater again. which allows you to keep updating the temperature every 5 seconds in the meantime.

**Wiring Diagram**


**Code**

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
        counter = 120;                                  //Reset the counter to 120 
        if (temp > heatSetTo)                           //If min temperature has been reached
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
    Serial.print("Heater Status = ");                   //Print the heater status 
    if(trigPin) 
        Serial.println("ON");
    else
        Serial.println("OFF");
    Serial.print("Counter = ");                         //Print the counter value
    Serial.println(counter);

    delay(5000);                                        //wait 5 seconds 
    counter--;                                          //Decrement counter and loop again
}
