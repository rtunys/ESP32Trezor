//============================
//ESP32 Web Server: Elektronicky trezor so servom
//============================

#include <WiFi.h>
#include <WebServer.h>
#include "webpageCode.h"
#include "webpageCodeB.h"
#include <ESP32Servo.h>

Servo myservo;

const char* ssid     = "Redmi";
const char* password = "internetveci";

static const int servoPin = 1;
static const int ledPin = 2;

int hodnota = 0;
int posOpen = 95;
int posClosed = 140;

WebServer server(80);

#include "funkcie.h"

//===================================================================

void setup()
{
  myservo.attach(servoPin);
  Serial.begin(115200); 
  delay(10);
  
  pinMode(ledPin, OUTPUT); 
  delay(10);

  Serial.println();
  Serial.print("Connecting to WiFi ");
  WiFi.begin(ssid, password);

  while (WiFi.status()!=WL_CONNECTED){
  delay(150); 
  Serial.print(".");
  }
  Serial.println(); 
  Serial.println("WiFi connected.");
  Serial.print("IP address: "); 
  Serial.println(WiFi.localIP());

  server.on("/", webPage);
  server.on("/servo", SERVOtlacidlo);
  server.begin();
}

//===================================================================

void loop() {
  server.handleClient();
  }
