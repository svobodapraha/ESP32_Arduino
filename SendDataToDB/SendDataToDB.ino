/*
 *  This sketch demonstrates how to scan WiFi networks.
 *  The API is almost the same as with the WiFi Shield library,
 *  the most obvious difference being the different file you need to include:
 */
#include "WiFi.h"
#include "HTTPClient.h"


//const char* ssid     = "cegelec_mobile";
//const char* password = "1netolicky";

const char* ssid     = "libuse";
const char* password = "stabasta";


void setup()
{
    Serial.begin(115200);
    delay(10);

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
}

void loop()
{
    static int iCounter = 0;
    iCounter++;
    
    if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;

    String asGetReguest = "http://svobodav.php5.cz/test_get.php/?Number=";
    asGetReguest += String(iCounter); 
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
 
  delay(3000);
}
