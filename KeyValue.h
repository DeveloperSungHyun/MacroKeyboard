//================================================================================================키보드 -> KEYBOARD
int Combination_Key_Value[4] = {
  KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_LEFT_ALT, KEY_LEFT_GUI
};
char Combination_Key_display[4][20] = {
  "CTRL", "SHIFT", "ALT", "WIN"
};
//=====
int Normal_Key_Value[48] = {  //키보드 기본키
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
  'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12
};
char Normal_Key_display[48][20] = {  //키보드 기본키
  "1", "2", "3", "4", "5", "6", "7", "8", "9",
  "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
  "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12"
};
//=====
int Sub_Key_Value[15] = {  //기능키
  KEY_ESC, KEY_TAB, KEY_BACKSPACE, KEY_RETURN, KEY_INSERT, KEY_DELETE, KEY_CAPS_LOCK, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_HOME, KEY_END, KEY_PAGE_UP, KEY_PAGE_DOWN
};
char Sub_Key_display[15][20] = {  //기능키
  "ESC", "TAB", "BACKSPACE", "ENTER", "INSERT", "DELETE", "CAPS_LOCK", "UP", "DOWN", "LEFT", "RIGHT", "HOME", "END", "PAGE_UP", "PAGE_DOWN"
};
//=====
char special_Key_Value[32] = {  //특수문자
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126
};

//======================================================================================어플리케이션 -> CONSUMERCONTROL
int App_Value[4] = {
  CONSUMER_CONTROL_CONFIGURATION, CONSUMER_CONTROL_EMAIL_READER, CONSUMER_CONTROL_CALCULATOR, CONSUMER_CONTROL_LOCAL_BROWSER
};
char App_display[4][20] = {
  "MusicPlayer", "Meail", "Calculate", "FileExplorer"
};

//=======================================================================================미디어 -> CONSUMERCONTROL
int Media_Value[8] = {
  CONSUMER_CONTROL_PLAY_PAUSE, CONSUMER_CONTROL_SCAN_NEXT, CONSUMER_CONTROL_SCAN_PREVIOUS, CONSUMER_CONTROL_VOLUME_INCREMENT, CONSUMER_CONTROL_VOLUME_DECREMENT, CONSUMER_CONTROL_MUTE, CONSUMER_CONTROL_BRIGHTNESS_INCREMENT, CONSUMER_CONTROL_BRIGHTNESS_DECREMENT
};

char Media_display[8][20] = {
  "Stop & Play", "Next", "Back", "VolumeUp", "VolumeDown", "Mute", "backlight_Up", "backlight_Down"
};