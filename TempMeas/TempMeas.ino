
#include <tsys01.h>
#include <Wire.h>
static tsys01  MainTempSensor; 

void setup() {
  // put your setup code here, to run once:
  
  //MainTempSensor.set_address(tsys01_i2c_address_csb_0);
  Serial.begin(115200);
  Serial.println("ON");
  pinMode(27, OUTPUT);  //9
  pinMode(26, OUTPUT);  //10
  pinMode(25, OUTPUT);  //11

  digitalWrite(27, LOW);  //9
  digitalWrite(26, HIGH); //10
  digitalWrite(25, LOW);  //11
  delay(5);
  Wire.begin(5, 4);
  MainTempSensor.begin();
  

  
} 



void loop()
{
 float temperature;
  if (MainTempSensor.is_connected())
  {    
    MainTempSensor.read_temperature(&temperature);
    
    Serial.print("- Temperature : ");
    Serial.print(temperature, 1);
    Serial.print((char)176);
    Serial.println("C");
    Serial.println();
  }
  else 
  {
    Serial.println("TSYS01 is disconnected");
  }
  delay(5);
  
}   
