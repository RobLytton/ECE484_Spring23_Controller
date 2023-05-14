#include <RH_ASK.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include "Colors.h"
int NUMPIXELS = 4;
int LEDPIN = 6;

#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); 
int sound = 8;
long lastSound = millis();
int soundTime = 5;
int green = A4;
int blue = A5;
int red = A3;

RH_ASK driver;
String x = "";

int currPix = 0;

unsigned long lastCom = millis();
void setup() {
  // put your setup code here, to run once:
  driver.init();
  pixels.begin();
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t buf[12];

  if (driver.recv(buf, 12)) {
    x = ((String)(char*)buf);
    x.trim();
    if(abs(millis() - lastCom) > 250) {
      lastCom = millis();
      currPix++;
      currPix %= NUMPIXELS;
      if(x != "Stop") {
          lcd.clear();
          lcd.println(x);
      }
    }
    
  if(x == "Up") {
    tone(sound, 4000, soundTime);
    
    pixels.fill(LightPurple,currPix,1);
  } else if (x == "Up Right") {
    tone(sound, 3750, soundTime);
    
    pixels.fill(LightBlue,currPix,1);
  } else if (x == "Right") {
    tone(sound, 3000, soundTime);
    
    pixels.fill(DarkGreen,currPix,1);
  } else if (x == "Down Right") {
    tone(sound, 2750, soundTime);
    
    pixels.fill(Cyan,currPix,1);
  } else if (x == "Down") {
    tone(sound, 2500, soundTime);
  
    pixels.fill(Magenta,currPix,1);
  } else if (x == "Down Left") {
    tone(sound, 2250, soundTime);
    
    pixels.fill(Purple,currPix,1);
  } else if (x == "Left") {
    tone(sound, 2000, soundTime);
    
    pixels.fill(Orange,currPix,1);
  } else if (x == "Up Left") {
    tone(sound, 1750, soundTime);
    
    pixels.fill(Yellow,currPix,1);
  } else if (x == "Button 1") {
    tone(sound, 1500, soundTime);
    
    pixels.fill(Red,currPix,1);
  } else if (x == "Button 2") {
    tone(sound, 1250, soundTime);
    
    pixels.fill(Blue,currPix,1);
  } else if (x == "Button 3") {
    
    pixels.fill(Green,currPix,1);
    tone(sound, 1000, soundTime);
  } else {
    noTone(sound);
    
  }
  pixels.show();
  
     
  } 
 
  
  
    
  
 
  
}
