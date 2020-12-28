#include <dht.h>
#define dht_apin A0

dht DHT;

int stat = 0;
int counter = 0;
void setup()
{
  pinMode(8, OUTPUT);
  Serial.begin(9600);
  delay(500);
  Serial.println("*** Program Start Here ***");
  delay(1000);//Wait before accessing Sensor
}

void loop()
{
 
    DHT.read11(dht_apin);
    int temp = ((int)DHT.temperature*1.8)+32;
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(temp);
    Serial.println(" F  ");

    if (counter <= 0)
    {//Open main condition

      //120 * 5s = 600s = 10 min 
      //this will keep the heat status stable for 10 minutes
      counter = 24;
      if (temp > 72)
      {
        stat = 0;
        digitalWrite(8, stat);
      }
      else 
      {
        stat = 1;
        digitalWrite(8, stat);
      }
      
    }//Close main condition      
    Serial.print("Heat Status = ");
    Serial.println(stat);
    Serial.print("Counter = ");
    Serial.println(counter);

    delay(5000);
    counter--;

 
}
