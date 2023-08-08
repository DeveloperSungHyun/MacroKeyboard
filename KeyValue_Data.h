#define NORMAL_KEY 1
#define SUB_YEY 2
#define SPECIAL 3
#define APP 4
#define MEDIA 5

//================================================================================================키보드 -> KEYBOARD
int Combination_Key_Value[16][4] = {  // CTRL, SHIFT, ALT, WIN
  { 0, 0, 0, 0 },
  { KEY_LEFT_CTRL, 0, 0, 0 },
  { 0, KEY_LEFT_SHIFT, 0, 0 },
  { KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 0, 0 },
  { 0, 0, KEY_LEFT_ALT, 0 },
  { KEY_LEFT_CTRL, 0, KEY_LEFT_ALT, 0 },
  { 0, KEY_LEFT_SHIFT, KEY_LEFT_ALT, 0 },
  { KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_LEFT_ALT, 0 },
  { 0, 0, 0, KEY_LEFT_GUI },
  { KEY_LEFT_CTRL, 0, 0, KEY_LEFT_GUI },
  { 0, KEY_LEFT_SHIFT, 0, KEY_LEFT_GUI },
  { KEY_LEFT_CTRL, KEY_LEFT_SHIFT, 0, KEY_LEFT_GUI },
  { 0, 0, KEY_LEFT_ALT, KEY_LEFT_GUI },
  { KEY_LEFT_CTRL, 0, KEY_LEFT_ALT, KEY_LEFT_GUI },
  { 0, KEY_LEFT_SHIFT, KEY_LEFT_ALT, KEY_LEFT_GUI },
  { KEY_LEFT_CTRL, KEY_LEFT_SHIFT, KEY_LEFT_ALT, KEY_LEFT_GUI }
};

int Normal_Key_Value[48] = {  //키보드 기본키
  '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12
};

int Sub_Key_Value[15] = {  //기능키
  KEY_ESC, KEY_TAB, KEY_BACKSPACE, KEY_RETURN, KEY_INSERT, KEY_DELETE, KEY_CAPS_LOCK, KEY_UP_ARROW, KEY_DOWN_ARROW, KEY_LEFT_ARROW, KEY_RIGHT_ARROW, KEY_HOME, KEY_END, KEY_PAGE_UP, KEY_PAGE_DOWN
};

char special_Key_Value[32] = {  //특수문자
  33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126
};

//======================================================================================어플리케이션 -> CONSUMERCONTROL
int App_Value[4] = {
  CONSUMER_CONTROL_CONFIGURATION, CONSUMER_CONTROL_EMAIL_READER, CONSUMER_CONTROL_CALCULATOR, CONSUMER_CONTROL_LOCAL_BROWSER
};

int Media_Value[8] = {
  CONSUMER_CONTROL_PLAY_PAUSE, CONSUMER_CONTROL_SCAN_NEXT, CONSUMER_CONTROL_SCAN_PREVIOUS, CONSUMER_CONTROL_VOLUME_INCREMENT, CONSUMER_CONTROL_VOLUME_DECREMENT, CONSUMER_CONTROL_MUTE, CONSUMER_CONTROL_BRIGHTNESS_INCREMENT, CONSUMER_CONTROL_BRIGHTNESS_DECREMENT
};