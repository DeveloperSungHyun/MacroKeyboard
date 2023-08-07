#define KEYBOARD 1
#define APP 2
#define MEDIA 3

char Combination_Key_display[4][20] = {
  "CTRL", "SHIFT", "ALT", "WIN"
};

char Normal_Key_display[48][20] = {  //키보드 기본키
  "1", "2", "3", "4", "5", "6", "7", "8", "9",
  "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
  "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12"
};

char Sub_Key_display[15][20] = {  //기능키
  "ESC", "TAB", "BACKSPACE", "ENTER", "INSERT", "DELETE", "CAPS_LOCK", "UP", "DOWN", "LEFT", "RIGHT", "HOME", "END", "PAGE_UP", "PAGE_DOWN"
};

char App_display[4][20] = {
  "MusicPlayer", "Meail", "Calculate", "FileExplorer"
};

char Media_display[8][20] = {
  "Stop & Play", "Next", "Back", "VolumeUp", "VolumeDown", "Mute", "backlight_Up", "backlight_Down"
};