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
>>As a result the everytime the program turn ON or OFF the heater, it will loop 120 times and everyloop will wait 5 seconds (120*5s = 10 minutes) before turning ON or OFF the heater again. which allows you to have the instatenous temperature updated every 5 seconds!

