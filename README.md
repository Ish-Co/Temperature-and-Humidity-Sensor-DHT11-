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
    ****
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
    ****
NOTE: Your code will loop so many times in a minute which can cause your heater to turn ON and OFF as it loops over and over which will damage your heater.
Therefore, a set a variable equal to 0 which let the microcontroller to run 
```
int counter = 0; 
```
which will run 
