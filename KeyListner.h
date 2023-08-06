//컨트롤 키 입력

#pragma once
class KeyListner {
private:

public:
  void ControllerKeyInit(int Button_1, int Button_2, int Button_3, int Button_4, int Button_5, int Button_6,
               int Rotary_A, int Rotary_B, int Rotary_C, int Wheel_A, int Wheel_B, int Wheel_C, int SettingButton);

  bool Get_Button_1();
  bool Get_Button_2();
  bool Get_Button_3();
  bool Get_Button_4();
  bool Get_Button_5();
  bool Get_Button_6();

  bool Get_RotaryUp();
  bool Get_RotaryDown();
  bool Get_RotaryPush();

  bool Get_WheelUp();
  bool Get_WheelDown();
  bool Get_WheelPush();

  bool Get_SettingButton();


  void PinReset();
  
};