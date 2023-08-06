#include "Arduino.h"
#include "KeyListner.h"

bool RotaryUp, RotaryDown;

int Pin_Button_1;
int Pin_Button_2;
int Pin_Button_3;
int Pin_Button_4;
int Pin_Button_5;
int Pin_Button_6;

int Pin_Rotary_A;
int Pin_Rotary_B;
int Pin_Rotary_C;

int Pin_Wheel_A;
int Pin_Wheel_B;
int Pin_Wheel_C;

int Pin_SettingButton;

void RotaryInterrupt();

void KeyListner::ControllerKeyInit(
  int Button_1, int Button_2, int Button_3, int Button_4, int Button_5, int Button_6,
  int Rotary_A, int Rotary_B, int Rotary_C, int Wheel_A, int Wheel_B, int Wheel_C, int SettingButton) {

  Pin_Button_1 = Button_1;
  Pin_Button_2 = Button_2;
  Pin_Button_3 = Button_3;
  Pin_Button_4 = Button_4;
  Pin_Button_5 = Button_5;
  Pin_Button_6 = Button_6;

  Pin_Rotary_A = Rotary_A;
  Pin_Rotary_B = Rotary_B;
  Pin_Rotary_C = Rotary_C;

  Pin_Wheel_A = Wheel_A;
  Pin_Wheel_B = Wheel_B;
  Pin_Wheel_C = Wheel_C;

  Pin_SettingButton = SettingButton;

  pinMode(Pin_Button_1, INPUT_PULLDOWN);
  pinMode(Pin_Button_2, INPUT);
  pinMode(Pin_Button_3, INPUT);
  pinMode(Pin_Button_4, INPUT);
  pinMode(Pin_Button_5, INPUT);
  pinMode(Pin_Button_6, INPUT);

  pinMode(Pin_Rotary_A, INPUT);
  pinMode(Pin_Rotary_B, INPUT);
  pinMode(Pin_Rotary_C, INPUT);

  pinMode(Pin_Wheel_A, INPUT);
  pinMode(Pin_Wheel_B, INPUT);
  pinMode(Pin_Wheel_C, INPUT);

  pinMode(Pin_SettingButton, INPUT);

  attachInterrupt(digitalPinToInterrupt(Pin_Rotary_A), RotaryInterrupt, FALLING);
}

void RotaryInterrupt() {
  for (int i = 0; i < 100; i++) {
    if (digitalRead(Pin_Rotary_A) == true) return;
  }

  if (digitalRead(Pin_Rotary_B)) {
    RotaryUp = true;
  } else {
    RotaryDown = true;
  }
}


bool KeyListner::Get_Button_1() {
  return digitalRead(Pin_Button_1);
}
bool KeyListner::Get_Button_2() {
  return digitalRead(Pin_Button_2);
}
bool KeyListner::Get_Button_3() {
  return digitalRead(Pin_Button_3);
}
bool KeyListner::Get_Button_4() {
  return digitalRead(Pin_Button_4);
}
bool KeyListner::Get_Button_5() {
  return digitalRead(Pin_Button_5);
}
bool KeyListner::Get_Button_6() {
  return digitalRead(Pin_Button_6);
}

bool KeyListner::Get_RotaryUp() {
  return RotaryUp;
}
bool KeyListner::Get_RotaryDown() {
  return RotaryDown;
}
bool KeyListner::Get_RotaryPush() {
  return digitalRead(Pin_Rotary_C);
}

bool KeyListner::Get_WheelUp() {
  return digitalRead(Pin_Wheel_A);
}
bool KeyListner::Get_WheelDown() {
  return digitalRead(Pin_Wheel_B);
}
bool KeyListner::Get_WheelPush() {
  return digitalRead(Pin_Wheel_C);
}

bool KeyListner::Get_SettingButton() {
  return digitalRead(Pin_SettingButton);
}

void KeyListner::PinReset(){
  RotaryUp = false;
  RotaryDown = false;
}