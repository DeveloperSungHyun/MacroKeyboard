#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "USB.h"
#include "USBHIDConsumerControl.h"  //미디어
#include "USBHIDMouse.h"            //마우스
#include "USBHIDKeyboard.h"         //키보드
#include "KeyValue_Data.h"
#include "KeyListner.h"
#include "OLED_Display.h"
#include "KeyData.h"

void Key_Interface(int LayerNumber);

USBHIDConsumerControl ConsumerControl;
USBHIDMouse Mouse;
USBHIDKeyboard Keyboard;

KeyData key_data1;

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

KeyListner key_listner;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void OLED_Display::OLED_Display_Init() {
  key_listner.ControllerKeyInit(35, 36, 37, 38, 39, 40, 6, 5, 4, 37, 38, 39, 17);

  USB.begin();

  ConsumerControl.begin();
  Mouse.begin();
  Keyboard.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;  // Don't proceed, loop forever
  }
  delay(10);
  display.clearDisplay();
  display.display();
}


//=============================================================================================메인뷰
int OLED_Display::OLED_MainView(char* ViewName, int LayerNumber, char (*LayerName)[20]) {
  display.clearDisplay();

  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(0, 0);              // Start at top-left corner
  display.print(ViewName);

  display.drawLine(0, 9, 128, 9, SSD1306_WHITE);

  display.drawLine(0, 30, 20, 30, SSD1306_WHITE);
  display.drawLine(20, 30, 30, 9, SSD1306_WHITE);

  display.drawLine(25, 21, 128, 21, SSD1306_WHITE);

  display.setCursor(35, 12);  // Start at top-left corner
  display.println("Layey_Name");
  display.setCursor(28, 23);  // Start at top-left corner
  display.println(LayerName[LayerNumber]);

  display.setTextSize(2);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text
  display.setCursor(7, 13);             // Start at top-left corner
  display.print(LayerNumber);

  //display.drawLine(0, 32, 128, 32, SSD1306_WHITE);

  bool SettingButton = true;

  long timer = millis();
  while (true) {
    if (key_listner.Get_SettingButton() == true && SettingButton == true) {
      timer = millis();
      SettingButton = false;
    } else if (key_listner.Get_SettingButton() == false && SettingButton == false) {
      SettingButton = true;
      return 1;
    } else if (key_listner.Get_SettingButton() == true) {
      if (millis() - timer >= 1000) return 2;
    }

    Key_Interface(LayerNumber);


    key_listner.PinReset();  //입력 인터페이스 값 초기화
    display.display();
  }
}


//=============================================================================================리스트뷰
int OLED_Display::OLED_ListView(char* ViewName, char (*Text)[20], int set_Cursor, int list_size) {
  char* OledTextList[list_size + 1];
  for (int i = 0; i < 10; i++) {
    OledTextList[i] = Text[i];
  }
  OledTextList[list_size] = " -EXIT-";

  int Cursor = set_Cursor;
  int n = 0;

  display.setTextSize(1);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text

  //============================

  bool RotaryPush = true;
  bool SettingButton = true;
  while (true) {
    display.clearDisplay();

    display.setTextSize(1);               // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);  // Draw white text
    display.setCursor(0, 0);              // Start at top-left corner
    display.print(ViewName);

    display.drawLine(0, 9, 128, 9, SSD1306_WHITE);

    if (key_listner.Get_RotaryUp()) {
      if (Cursor < list_size) Cursor++;
    }
    if (key_listner.Get_RotaryDown()) {
      if (Cursor > 0) Cursor--;
    }

    if (key_listner.Get_RotaryPush() == true && RotaryPush == true) {
      RotaryPush = false;
    } else if (key_listner.Get_RotaryPush() == false && RotaryPush == false) {
      RotaryPush = true;
      return Cursor;
    }

    if (key_listner.Get_SettingButton() == true && SettingButton == true) {
      SettingButton = false;
    } else if (key_listner.Get_SettingButton() == false && SettingButton == false) {
      SettingButton = true;
      return -1;
    }

    if (n + 5 < Cursor && n + 5 < list_size) {
      n++;
    }

    if (n > Cursor && n > 0) {
      n--;
    }

    // display.drawLine(0, 10, 128, 10, SSD1306_WHITE);
    // display.drawLine(0, 21, 128, 21, SSD1306_WHITE);
    // display.drawLine(0, 32, 128, 32, SSD1306_WHITE);
    // display.drawLine(0, 43, 128, 43, SSD1306_WHITE);
    // display.drawLine(0, 54, 128, 54, SSD1306_WHITE);


    display.setCursor(0, 12);
    if (Cursor - n == 0) display.print(">");
    else display.print(" ");
    display.print(n);
    display.print(":");
    display.print(OledTextList[n + 0]);

    display.setCursor(0, 21);
    if (Cursor - n == 1) display.print(">");
    else display.print(" ");
    display.print(n + 1);
    display.print(":");
    display.print(OledTextList[n + 1]);

    display.setCursor(0, 30);
    if (Cursor - n == 2) display.print(">");
    else display.print(" ");
    display.print(n + 2);
    display.print(":");
    display.print(OledTextList[n + 2]);

    display.setCursor(0, 39);
    if (Cursor - n == 3) display.print(">");
    else display.print(" ");
    display.print(n + 3);
    display.print(":");
    display.print(OledTextList[n + 3]);

    display.setCursor(0, 48);
    if (Cursor - n == 4) display.print(">");
    else display.print(" ");
    display.print(n + 4);
    display.print(":");
    display.print(OledTextList[n + 4]);

    display.setCursor(0, 57);
    if (Cursor - n == 5) display.print(">");
    else display.print(" ");
    if (n + 5 != 10) {
      display.print(n + 5);
      display.print(":");
    }
    display.print(OledTextList[n + 5]);

    key_listner.PinReset();  //입력 인터페이스 값 초기화
    display.display();
  }

  return 0;
}

//=============================================================================================아이콘리스트뷰
int OLED_Display::OLED_IconListView(char* ViewName, unsigned char (*icon)[200], char (*IconName)[15], int list_size) {

  display.setTextSize(2);               // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);  // Draw white text

  int Cursor = 0;
  int n = 0;

  bool RotaryPush = true;
  bool SettingButton = true;

  bool dume = false;

  if (key_listner.Get_SettingButton() == true) dume = true;
  while (true) {
    display.clearDisplay();

    display.setTextSize(1);               // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);  // Draw white text
    display.setCursor(0, 0);              // Start at top-left corner
    display.print(ViewName);

    display.drawLine(0, 9, 128, 9, SSD1306_WHITE);

    display.setTextSize(2);  // Normal 1:1 pixel scale

    if (key_listner.Get_RotaryUp()) {
      if (Cursor < list_size - 1) {
        Cursor++;
      }
    }
    if (key_listner.Get_RotaryDown()) {
      if (Cursor > 0) {
        Cursor--;
      }
    }

    if (key_listner.Get_RotaryPush() == true && RotaryPush == true) {
      RotaryPush = false;
    } else if (key_listner.Get_RotaryPush() == false && RotaryPush == false) {
      RotaryPush = true;
      return Cursor;
    }

    if (dume == false) {
      if (key_listner.Get_SettingButton() == true && SettingButton == true) {
        SettingButton = false;
      } else if (key_listner.Get_SettingButton() == false && SettingButton == false) {
        SettingButton = true;
        return -1;
      }
    } else {
      if (key_listner.Get_SettingButton() == false) dume = false;
    }

    display.drawBitmap(2, 20, icon[Cursor], 40, 40, 1);

    display.setCursor(53, 32);  // Start at top-left corner
    display.print(IconName[Cursor]);

    key_listner.PinReset();  //입력 인터페이스 값 초기화
    display.display();
  }
}

char* OLED_Display::OLED_TextEditView() {
  char Char_Key[68] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_', '(', ')', '.', '/', '&'
  };

  static char NameText[16] = " ";
  for (int i = 0; i < 16; i++) NameText[i] = ' ';

  int cursor = 0;

  bool RotaryPush = true;
  bool SettingButton = true;
  while (true) {
    display.clearDisplay();

    display.setTextSize(1);               // Normal 1:1 pixel scale
    display.setTextColor(SSD1306_WHITE);  // Draw white text
    display.setCursor(0, 0);              // Start at top-left corner
    display.print("text");

    display.drawLine(0, 9, 109, 9, SSD1306_WHITE);
    display.setCursor(0, 12);
    display.print(NameText);
    display.drawLine(0, 21, 128, 21, SSD1306_WHITE);

    display.setCursor(0, 25);

    if (key_listner.Get_RotaryUp()) {
      if (cursor < 94) {
        cursor++;
      }
    }
    if (key_listner.Get_RotaryDown()) {
      if (cursor > 0) {
        cursor--;
      }
    }

    if (key_listner.Get_RotaryPush() == true && RotaryPush == true) {
      RotaryPush = false;
    } else if (key_listner.Get_RotaryPush() == false && RotaryPush == false) {
      RotaryPush = true;
      for (int i = 0; i < 15; i++) {
        if (!(NameText[i] >= '!' && NameText[i] <= '~')) {
          NameText[i] = Char_Key[cursor];
          NameText[i + 1] = '\0';
          break;
        }
      }
    }

    if (key_listner.Get_SettingButton() == true && SettingButton == true) {
      SettingButton = false;
    } else if (key_listner.Get_SettingButton() == false && SettingButton == false) {
      SettingButton = true;

      return NameText;
    }

    char c;
    for (int i = 0; i < 68; i++) {
      if (cursor == i) display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      else display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
      display.print(Char_Key[i]);
    }

    display.drawLine(110, 0, 110, 20, SSD1306_WHITE);

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(115, 2);
    display.print(Char_Key[cursor]);

    key_listner.PinReset();  //입력 인터페이스 값 초기화
    display.display();
  }
}


void Key_Interface(int LayerNumber) {
  if (key_listner.Get_Button_1() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_Button_1) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).Button_1]);
          ConsumerControl.release();
          delay(300);
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).Button_1]);
          ConsumerControl.release();
          delay(300);
          break;
        }
    }
  }
  if (key_listner.Get_Button_2() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_Button_2) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).Button_2]);
          ConsumerControl.release();
          delay(300);
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).Button_2]);
          ConsumerControl.release();
          delay(300);
          break;
        }
    }
  }
  if (key_listner.Get_Button_3() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_Button_3) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).Button_3]);
          ConsumerControl.release();
          delay(300);
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).Button_3]);
          ConsumerControl.release();
          delay(300);
          break;
        }
    }
  }
  if (key_listner.Get_Button_4() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_Button_4) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).Button_4]);
          ConsumerControl.release();
          delay(300);
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).Button_4]);
          ConsumerControl.release();
          delay(300);
          break;
        }
    }
  }
  if (key_listner.Get_Button_5() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_Button_5) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).Button_5]);
          ConsumerControl.release();
          delay(300);
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).Button_5]);
          ConsumerControl.release();
          delay(300);
          break;
        }
    }
  }
  if (key_listner.Get_Button_6() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_Button_6) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).Button_6]);
          ConsumerControl.release();
          delay(300);
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).Button_6]);
          ConsumerControl.release();
          delay(300);
          break;
        }
    }
  }

  //========================================

  if (key_listner.Get_RotaryUp() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_RotaryUp) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).RotaryUp]);
          ConsumerControl.release();
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).RotaryUp]);
          ConsumerControl.release();
          break;
        }
    }
  }
  if (key_listner.Get_RotaryDown() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_RotaryDown) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).RotaryDown]);
          ConsumerControl.release();
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).RotaryDown]);
          ConsumerControl.release();
          break;
        }
    }
  }
  if (key_listner.Get_RotaryPush() == true) {
    switch (key_data1.Get_KeyData(LayerNumber).KeyType_RotaryPush) {
      case KEYBOARD:
        {
          break;
        }
      case APP:
        {
          ConsumerControl.press(App_Value[key_data1.Get_KeyData(LayerNumber).RotaryPush]);
          ConsumerControl.release();
          delay(300);
          break;
        }
      case MEDIA:
        {
          ConsumerControl.press(Media_Value[key_data1.Get_KeyData(LayerNumber).RotaryPush]);
          ConsumerControl.release();
          delay(300);
          break;
        }
    }
  }
}