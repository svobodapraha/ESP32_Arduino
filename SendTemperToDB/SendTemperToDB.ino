/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include "WiFi.h"
#include "HTTPClient.h"
#include <tsys01.h>
#include <Wire.h> 
static tsys01  MainTempSensor; 
 


//const char* ssid     = "cegelec_mobile";
//const char* password = "1netolicky";

const char* ssid     = "libuse";
const char* password = "stabasta";


void setup()
{
//Serial
    Serial.begin(115200);
    delay(10);


//wifi    
    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

//i2c and temp sensor
    pinMode(27, OUTPUT);  //9
    pinMode(26, OUTPUT);  //10
    pinMode(25, OUTPUT);  //11
  
    digitalWrite(27, LOW);  //9
    digitalWrite(26, HIGH); //10
    digitalWrite(25, LOW);  //11
    delay(2);
    Wire.begin(5, 4);
    MainTempSensor.begin(); 

    
}

void loop()
{
    static int iCounter = 0;
    iCounter++;
 
    //measure temp
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
      temperature = -63.5;
    } 
    




    //send to DB
    if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;

    String asGetReguest = "http://svobodav.php5.cz/test_get.php/?";
    asGetReguest += "Number=";
    asGetReguest += String(iCounter);
    asGetReguest +=  "&";
    asGetReguest +="Temperature=";
    asGetReguest += String(temperature);
     
    http.begin(asGetReguest); //Specify the URL
    int httpCode = http.GET();                                        //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(60000);
}
