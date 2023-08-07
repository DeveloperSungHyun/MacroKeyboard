#pragma once
typedef struct LayerData {

  char* LayerName;  //레이어 이름
  //========================
  int KeyType_Button_1;
  int ComKey_Button_1;
  int Button_1;

  int KeyType_Button_2;
  int ComKey_Button_2;
  int Button_2;

  int KeyType_Button_3;
  int ComKey_Button_3;
  int Button_3;

  int KeyType_Button_4;
  int ComKey_Button_4;
  int Button_4;

  int KeyType_Button_5;
  int ComKey_Button_5;
  int Button_5;

  int KeyType_Button_6;
  int ComKey_Button_6;
  int Button_6;
  //=========================
  int KeyType_RotaryUp;
  int ComKey_RotaryUp;
  int RotaryUp;

  int KeyType_RotaryDown;
  int ComKey_RotaryDown;
  int RotaryDown;

  int KeyType_RotaryPush;
  int ComKey_RotaryPush;
  int RotaryPush;
  //=========================
  int KeyType_WheelUp;
  int ComKey_WheelUp;
  int WheelUp;

  int KeyType_WheelDown;
  int ComKey_WheelDown;
  int WheelDown;

  int KeyType_WheelPush;
  int ComKey_WheelPush;
  int WheelPush;


} LayerData;