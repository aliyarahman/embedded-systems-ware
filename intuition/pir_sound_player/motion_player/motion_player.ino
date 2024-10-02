/***************************************************
/***********Notice and Trouble shooting***************
 1.Connection and Diagram can be found here
 <https://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299#Connection_Diagram>
 2.This code is tested on Arduino Uno, Leonardo, Mega boards.
 ****************************************************/

#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include "PIR.h"

int pirPin = 2; // Motion sensor pin
int rxPin = 10; // rx pin
int txPin = 11; // tx pin
int motionStatus = 0; // Current motion state starts off at "no motion"
int pirState = 0; // Last motion state starts off at "no motion"

SoftwareSerial sculptureSerial(rxPin, txPin); // Initialize serial ports for communication
DFRobotDFPlayerMini sculptureDFPlayer; // Initialize mp3 player

void printDetail(uint8_t type, int value);

void setup()
{
  pinMode(pirPin, INPUT); // Motion sensor inputs
  pinMode(rxPin, INPUT); // Receiving serial pin on mp3player
  pinMode(txPin, OUTPUT); // Transmitting serial pin on mp3player
  // PIR pir(pirPin); // Initialize the motion sensor
  Serial.begin(9600);
  sculptureSerial.begin(9600);
  sculptureDFPlayer.begin(sculptureSerial); // Tell mp3 player which serial hex to use
  sculptureDFPlayer.volume(30);  //Set volume value. From 0 to 30
  delay(3000);
  
  sculptureDFPlayer.play(1);  //Play the first mp3
}

void loop() {
  motionStatus = digitalRead(pirPin);

  if (motionStatus == HIGH) {
    // Play sound if someone comes into range and wasn't there before
    if (pirState == LOW) {
      Serial.println("Motion Detected");
      pirState = HIGH;
      fx.player.play();
      delay(5000); // This should be the length of the track
    }
  } else {
    // If there was motion and now there isn't, flip the state to "no motion"
    if (pirState == HIGH) {
      Serial.println("Motion Ended");
      pirState = LOW;

    // // Option 2: we won't use this because we don't want a sound if there is no motion
    // sculptureDFPlayer.play(1);
    // delay(5000); // This should be the length of the track
    }
  }
}