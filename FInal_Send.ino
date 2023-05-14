#include <RH_ASK.h>
#include <SPI.h>

int x = A5;
int y = A4;
int s = 2;

int b1 = 8;
int b2 = 9;
int b3 = 10;

boolean pressed[4] = {0,0,0,0};
boolean action[4] = {0,0,0,0};
int buttonDelay = 100;

RH_ASK driver;

void setup() {
    pinMode(s, INPUT);
  
    pinMode(b1, INPUT);
    pinMode(b2, INPUT);
    Serial.begin(9600);
    driver.init();
}





void loop() {
  
  const char *meg1 =  "DL  "; // right stick Up
  const char *meg2 =  "DR  "; // left stick Up
  const char *meg3 =  "D   "; // right stick Down
  const char *meg4 =  "UL  "; // left stick Down
  const char *meg5 =  "UR  ";
  const char *meg6 =  "U   ";
  const char *meg7 =  "L   "; // left stick Down
  const char *meg8 =  "R   ";
  const char *meg9 =  "Stop";
  const char *meg10 = "B1  "; // button1
  const char *meg11 = "B2  "; // button2

  const char *meg12 = "B3  "; // button2
  
 
  
 
  
  
  if(analogRead(y) > 700) { // right stick is moved back moving left wheels back
       if(analogRead(x) > 700) {// right stick is moved back moving left wheels back
          Serial.println("Down Left");
          driver.send((uint8_t *)meg1, 12);
          driver.waitPacketSent();
       } else if(analogRead(x) < 400) { 
          Serial.println("Down Right");
          driver.send((uint8_t *)meg2, 12);
          driver.waitPacketSent();
       } else {
           driver.send((uint8_t *)meg3, 12);
           driver.waitPacketSent();
           Serial.println("Down");
       }
  } else if(analogRead(y) < 400) { //  right stick is moved Up moving left wheels Up 
      
       if(analogRead(x) > 700) {// right stick is moved back moving left wheels back
          Serial.println("Up Left");
          driver.send((uint8_t *)meg4, 12);
          driver.waitPacketSent();
       } else if(analogRead(x) < 400) { 
          driver.send((uint8_t *)meg5, 12);
          driver.waitPacketSent();
          Serial.println("Up Right");

       } else {
          Serial.println("Up");
          driver.send((uint8_t *)meg6, 12);
          driver.waitPacketSent();
       }
  } else {
       if(analogRead(x) > 700) {// right stick is moved back moving left wheels back
          Serial.println("Left");
          driver.send((uint8_t *)meg7, 12);
          driver.waitPacketSent();
       } else if(analogRead(x) < 400) { 
          Serial.println("Right");
          driver.send((uint8_t *)meg8, 12);
          driver.waitPacketSent();
       } else {
           Serial.println("Stop");
           driver.send((uint8_t *)meg9, 12);
           driver.waitPacketSent();
           
       }
  }

  if(digitalRead(b2) == HIGH && !pressed[1]) {
    Serial.println("Button 2 On");
    driver.send((uint8_t *)meg11, 12);
    driver.waitPacketSent();
    pressed[1] = true;
    delay(buttonDelay);
  } else if(digitalRead(b2) == LOW){
    
    pressed[1] = false;
  }

  
  if(digitalRead(b1) == HIGH && !pressed[0]) {
    Serial.println("Button 1 On");
    driver.send((uint8_t *)meg10, 12);
    driver.waitPacketSent();
    
    pressed[0] = true;
    delay(buttonDelay);
  } else if(digitalRead(b1) == LOW) {
    
    pressed[0] = false;
  }

  
  if(digitalRead(b3) == HIGH && !pressed[2]) {
    Serial.println("Button 3 On");
    driver.send((uint8_t *)meg12, 12);
    driver.waitPacketSent();
    pressed[2] = true;
    delay(buttonDelay);
  } else if(digitalRead(b3) == LOW){
    pressed[2] = false;
  }

  if(digitalRead(s) == HIGH && !pressed[3]) {
    Serial.println("Switch On");
    driver.send((uint8_t *)meg12, 12);
    driver.waitPacketSent();
    pressed[3] = true;
    delay(buttonDelay);
  } else if(digitalRead(s) == LOW){
    pressed[3] = false;
  }


  
  
  


  
  
 
  

  

  

}
