//Author    : Bhushan A Ugale
//Date      : 22-NOV-2019
//Location  : India

#include "voltage_sense.h"
#include "current_sense.h"
#include "DHT.h"
#include "lux_sense.h"
#define DHTPIN 2
#define DHTTYPE DHT11 
#include <WiFi.h>
//********************************Firebase*****************
#include "FirebaseESP32.h"
#define FIREBASE_HOST "YOUR-FIREBASE-HOST" //Do not include https:// in FIREBASE_HOST
#define FIREBASE_AUTH "YOUR-FIREBASE-AUTHENTICATION-KEY"
#define WIFI_SSID "YOUR-WIFI-SSID"
#define WIFI_PASSWORD "YOUR-WIFI-PASSWORD"
String path = "Date Wise";
String jsonStr;
//Define Firebase Data object
FirebaseData firebaseData;
//*********************************************************
int voltage_pin = 39;  //These pins are used for I/P only so you can use other pins for use.
int current_pin = 36; //These pins are used for I/P only so you can use other pins for use.
int lux_sensor =35;  //These pins are used for I/P only so you can use other pins for use.

int current,voltage,temp,hum,lux;
DHT dht(DHTPIN, DHTTYPE);
//********************************************************

 Voltage_sense vs;
 Current_sense cs;
 Lux_sense ls;
 
 void setup()
 {
    Serial.begin(115200);
    dht.begin(); 

 //********************Firebase Connection Setup**********************
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(firebaseData, 1000 * 60);
  Firebase.setwriteSizeLimit(firebaseData, "tiny");
  Serial.println("------------------------------------");
  Serial.println("Path exist test...");
  if (Firebase.pathExist(firebaseData, path))
  {
    Serial.println("Path " + path + " exists");
    
  }
  else
  {
    Serial.println("Path " + path + " is not exist");
  }

 //*******************************************************************    
 }

void loop()
{
  vs.Setup_voltage(voltage_pin);
  voltage = vs.Fine_voltage;
  //Serial.print("Voltage => "); 
  //Serial.println(voltage);
  
  cs.Setup_current(current_pin);
  current = cs.Fine_current;
  //Serial.print("Current => "); 
  //Serial.println(current);
  
  ls.Setup_lux(lux_sensor);
  lux = ls.Fine_lux;
  Serial.print("Lux => "); 
  Serial.println(lux);

  
   hum = dht.readHumidity();
   temp = dht.readTemperature();
        if (isnan(hum) || isnan(temp))
        {
            Serial.println("Failed to read from DHT sensor!");
            return;
        }
   
  //Serial.print("Temperature => "); 
  //Serial.println(temp);
  //Serial.print("Humidity => "); 
  //Serial.println(hum);
  delay(2000); 

  //checkData();
  setData();
  //updateData();
          
}
