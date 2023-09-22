/*
* MIT License
* Developped by Rob Lytton 
* This code acts as the receiver for the console
* It prints the commands to the serial port as well as
* sends colors and sounds to the buzzer
*/

// Receiver --------------------
#include <RH_ASK.h> // receiver library
#include <SPI.h>
RH_ASK driver;
String command = "";

// LED STRIP ---------------------------//
#include <Adafruit_NeoPixel.h> 
#include "Colors.h" // predefined colors file
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, LEDPIN, NEO_GRB + NEO_KHZ800);
int NUMPIXELS = 4;
int LEDPIN = 6;
int currPix = 0;

// LCD ------------------------
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); 

// Sound --------------------------

int soundTime = 5;
int sound = 8;

unsigned long lastCom = millis();  // counts so led strip is constanlty updating
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
    command = ((String)(char*)buf);
    command.trim();
    if(abs(millis() - lastCom) > 250) {
      lastCom = millis();
      currPix++;
      currPix %= NUMPIXELS;
      if(command != "Stop") {
          lcd.clear();
          lcd.println(command);
      }
    }
    
  if(command == "Up") {
    tone(sound, 4000, soundTime);
    
    pixels.fill(LightPurple,currPix,1);
  } else if (command == "Up Right") {
    tone(sound, 3750, soundTime);
    
    pixels.fill(LightBlue,currPix,1);
  } else if (command == "Right") {
    tone(sound, 3000, soundTime);
    
    pixels.fill(DarkGreen,currPix,1);
  } else if (command == "Down Right") {
    tone(sound, 2750, soundTime);
    
    pixels.fill(Cyan,currPix,1);
  } else if (command == "Down") {
    tone(sound, 2500, soundTime);
  
    pixels.fill(Magenta,currPix,1);
  } else if (command == "Down Left") {
    tone(sound, 2250, soundTime);
    
    pixels.fill(Purple,currPix,1);
  } else if (command == "Left") {
    tone(sound, 2000, soundTime);
    
    pixels.fill(Orange,currPix,1);
  } else if (command == "Up Left") {
    tone(sound, 1750, soundTime);
    
    pixels.fill(Yellow,currPix,1);
  } else if (command == "Button 1") {
    tone(sound, 1500, soundTime);
    
    pixels.fill(Red,currPix,1);
  } else if (command == "Button 2") {
    tone(sound, 1250, soundTime);
    
    pixels.fill(Blue,currPix,1);
  } else if (command == "Button 3") {
    
    pixels.fill(Green,currPix,1);
    tone(sound, 1000, soundTime);
  } else {
    noTone(sound);
    
  }
  pixels.show();
  
     
  } 
  
  void soundLights(int& freq, int& color) {
      const int soundPin = 8;
      const int soundTime = 5;
      tone(sound, freg, soundTime);
      pixels.fill(color,currPix,1);
      currPix++;
  }
}
