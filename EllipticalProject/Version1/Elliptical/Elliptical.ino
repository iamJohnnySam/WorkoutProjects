#include <Wire.h>
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <LiquidCrystal_I2C.h>

// WIFI PASSWORD
const char* ssid     = "iamJohnnySam-WiFi2";
const char* password = "F82F488CC1F";

// VARIABLES
const long utcOffsetInSeconds = 19800;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
String page = "";
String text = "";
double count = 0;
double steps = 0;
bool check = LOW;

unsigned long Time = millis()/1000;
unsigned long RunTime = 0;
unsigned long Distance = 0;
unsigned int PulsesBetweenSeconds = 0;
bool activeStatus = LOW;
double cadence = 0;
const int cA = 10;
double cadenceAvg[cA];
int i = 0;
unsigned long prevStepTime = 0;

int dispPage = 1;

// WIFI
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

// LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  LCDsetup();
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D0, OUTPUT);
  pinMode(D3, INPUT_PULLUP);
  initWiFi();

  lcd.clear();
  prevStepTime = millis();
}

void loop() {
  checkSensor();

  if (millis()/1000 > Time){
    Time = millis()/1000;
    
    if (PulsesBetweenSeconds > 0){
      if (!activeStatus){
        lcd.clear();
      }
      activeStatus = HIGH;
      RunTime++;
      PulsesBetweenSeconds = 0;
    }
    else{
      activeStatus = LOW;
      lcd.clear();
    }
    
    updateLCD();
  }
}
