/* 
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-web-server-websocket-sliders/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "SPIFFS.h"
#include <Arduino_JSON.h>

// Include Wire Library for I2C
#include <Wire.h>
// Include Adafruit PCA9685 Servo Library
#include <Adafruit_PWMServoDriver.h>

// Replace with your network credentials
const char* ssid = "RoboticArm";
const char* password = "BESIT007";

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
// Create a WebSocket object

AsyncWebSocket ws("/ws");

// Creat object to represent PCA9685 at default I2C address
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);

// Define maximum and minimum number of "ticks" for the servo motors
// Range from 0 to 4095
// This determines the pulse width

#define SERVOMIN  80  // Minimum value
#define SERVOMAX  500  // Maximum value

// Set PWM pin
const int Pin1 = 0;
const int Pin2 = 1;
const int Pin3 = 2;
const int Pin4 = 3;
const int Pin5 = 4;
const int Pin6 = 5;

String message = "";
String sliderValue1 = "90";
String sliderValue2 = "90";
String sliderValue3 = "90";
String sliderValue4 = "90";
String sliderValue5 = "90";
String sliderValue6 = "90";

int IAngle1;
int IAngle2;
int IAngle3;
int IAngle4;
int IAngle5;
int IAngle6;

int FAngle1;
int FAngle2;
int FAngle3;
int FAngle4;
int FAngle5;
int FAngle6;

int dutyCycle1;
int dutyCycle2;
int dutyCycle3;
int dutyCycle4;
int dutyCycle5;
int dutyCycle6;


//Json Variable to Hold Slider Values
JSONVar sliderValues;

//Get Slider Values
String getSliderValues(){
  sliderValues["sliderValue1"] = String(sliderValue1);
  sliderValues["sliderValue2"] = String(sliderValue2);
  sliderValues["sliderValue3"] = String(sliderValue3);
  sliderValues["sliderValue4"] = String(sliderValue4);
  sliderValues["sliderValue5"] = String(sliderValue5);
  sliderValues["sliderValue6"] = String(sliderValue6);

  String jsonString = JSON.stringify(sliderValues);
  return jsonString;
}

// Initialize SPIFFS
void initFS() {
  if (!SPIFFS.begin()) {
    Serial.println("An error has occurred while mounting SPIFFS");
  }
  else{
   Serial.println("SPIFFS mounted successfully");
  }
}

// Initialize WiFi
void initWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
}

void notifyClients(String sliderValues) {
  ws.textAll(sliderValues);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;
    message = (char*)data;
    if (message.indexOf("1s") >= 0) {
      sliderValue1 = message.substring(2);
      // dutyCycle1 = map(sliderValue1.toInt(), 0, 100, 0, 255);
      dutyCycle1 = map(sliderValue1.toInt(), 0, 180, SERVOMIN, SERVOMAX);
      Serial.println(dutyCycle1);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }
    if (message.indexOf("2s") >= 0) {
      sliderValue2 = message.substring(2);
      //dutyCycle2 = map(sliderValue2.toInt(), 0, 100, 0, 255);
      dutyCycle2 = map(sliderValue2.toInt(), 0, 180, SERVOMIN, SERVOMAX);
      Serial.println(dutyCycle2);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }    
    if (message.indexOf("3s") >= 0) {
      sliderValue3 = message.substring(2);
      //dutyCycle3 = map(sliderValue3.toInt(), 0, 100, 0, 255);
      dutyCycle3 = map(sliderValue3.toInt(), 0, 180, SERVOMIN, SERVOMAX);
      Serial.println(dutyCycle3);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    } 
    if (message.indexOf("4s") >= 0) {
      sliderValue4 = message.substring(2);
      //dutyCycle3 = map(sliderValue3.toInt(), 0, 100, 0, 255);
      dutyCycle4 = map(sliderValue4.toInt(), 0, 180, SERVOMIN, SERVOMAX);
      Serial.println(dutyCycle4);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }  
    if (message.indexOf("5s") >= 0) {
      sliderValue5 = message.substring(2);
      //dutyCycle3 = map(sliderValue3.toInt(), 0, 100, 0, 255);
      dutyCycle5 = map(sliderValue5.toInt(), 0, 180, SERVOMIN, SERVOMAX);
      Serial.println(dutyCycle5);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());
    }  
    if (message.indexOf("6s") >= 0) {
      sliderValue6 = message.substring(2);
      //dutyCycle3 = map(sliderValue3.toInt(), 0, 100, 0, 255);
      dutyCycle6 = map(sliderValue6.toInt(), 0, 180, SERVOMIN, SERVOMAX);
      Serial.println(dutyCycle6);
      Serial.print(getSliderValues());
      notifyClients(getSliderValues());      
    }
    if (strcmp((char*)data, "getValues") == 0) {
      notifyClients(getSliderValues());
    }
  }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  switch (type) {
    case WS_EVT_CONNECT:
      Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
      break;
    case WS_EVT_DISCONNECT:
      Serial.printf("WebSocket client #%u disconnected\n", client->id());
      break;
    case WS_EVT_DATA:
      handleWebSocketMessage(arg, data, len);
      break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
      break;
  }
}

void initWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}


void setup() {
  
  Serial.begin(115200);

  // Initialize PCA9685
  pca9685.begin();

  // Set PWM Frequency to 50Hz
  pca9685.setPWMFreq(50);
  
  initFS();
  
  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  initWebSocket();
  
  // Web Server Root URL
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");
  });
  
  server.serveStatic("/", SPIFFS, "/");

  // Start server
  server.begin();
  Serial.println("HTTP server started");

}

void loop() {
  
  pca9685.setPWM(Pin1, 0, dutyCycle1);
  pca9685.setPWM(Pin2, 0, dutyCycle2);
  pca9685.setPWM(Pin3, 0, dutyCycle3);
  pca9685.setPWM(Pin4, 0, dutyCycle4);
  pca9685.setPWM(Pin5, 0, dutyCycle5);
  pca9685.setPWM(Pin6, 0, dutyCycle6);

  ws.cleanupClients();
}
