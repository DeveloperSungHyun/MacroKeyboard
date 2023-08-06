#pragma once
typedef struct LayerData {

  char* LayerName;  //레이어 이름
  //========================
  int KeyType_Button_1;
  bool ComKey_Button_1[4];
  int Button_1;

  int KeyType_Button_2;
  bool ComKey_Button_2[4];
  int Button_2;

  int KeyType_Button_3;
  bool ComKey_Button_3[4];
  int Button_3;

  int KeyType_Button_4;
  bool ComKey_Button_4[4];
  int Button_4;

  int KeyType_Button_5;
  bool ComKey_Button_5[4];
  int Button_5;

  int KeyType_Button_6;
  bool ComKey_Button_6[4];
  int Button_6;
  //=========================
  int KeyType_RotaryUp;
  bool ComKey_RotaryUp[4];
  int RotaryUp;

  int KeyType_RotaryDown;
  bool ComKey_RotaryDown[4];
  int RotaryDown;

  int KeyType_RotaryPush;
  bool ComKey_RotaryPush[4];
  int RotaryPush;
  //=========================
  int KeyType_WheelUp;
  bool ComKey_WheelUp[4];
  int WheelUp;

  int KeyType_WheelDown;
  bool ComKey_WheelDown[4];
  int WheelDown;

  int KeyType_WheelPush;
  bool ComKey_WheelPush[4];
  int WheelPush;


} LayerData;