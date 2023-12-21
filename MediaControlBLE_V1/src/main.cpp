#include <Arduino.h>
#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Media_Control_AB");

#define PLAY_button 22
#define NEXT_button 23
#define PREV_button 1
#define DISC_button 2


int lastState_play = LOW;
int current_play;     

int lastState_next = LOW;
int current_next;

int lastState_prev = LOW;
int current_prev;

int lastState_disc = LOW;
int current_disc;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  pinMode(PLAY_button, INPUT_PULLUP);
  pinMode(NEXT_button, INPUT_PULLUP);
  pinMode(PREV_button, INPUT_PULLUP);
  pinMode(DISC_button, INPUT_PULLUP);
  
}

//https://github.com/T-vK/ESP32-BLE-Keyboard

void loop() {
  current_play = digitalRead(PLAY_button);
  current_next = digitalRead(NEXT_button);
  current_prev = digitalRead(PREV_button);
  current_disc = digitalRead(DISC_button);

  if(bleKeyboard.isConnected()) {

    if (lastState_play == 0 && current_play == 1){
      bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
     }
    if (lastState_next == 0 && current_next == 1){
      bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
     }
    if (lastState_prev == 0 && current_prev == 1){
      bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
     }
    if (lastState_disc == 0 && current_disc == 1){
      
     }
     


      lastState_play = current_play;
      lastState_next = current_next;
      lastState_prev = current_prev;
      lastState_disc = current_disc;
 }


}
