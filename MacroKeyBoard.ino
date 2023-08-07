#include <string.h>
#include "KeyData.h"
#include "OLED_Display.h"
#include "LayerData.h"
#include "Icon.h"
#include "KeyValue_Text.h"

OLED_Display oled_display;
LayerData layer_data;
KeyData key_data;

char LayerName_List[10][20];

//========================================
int Layer_Number = 0;
int OLED_SceneNumber = 0;


void setup() {
  key_data.EEPROM_DataInit();

  key_data.EEPROM_DataLoad();

  //   pinMode(LED_BUILTIN, OUTPUT);
  // digitalWrite(LED_BUILTIN, LOW);

  oled_display.OLED_Display_Init();
  Serial.begin(115200);

  for (int i = 0; i < 10; i++) {
    if (key_data.Get_KeyData(i).LayerName != NULL) strcpy(LayerName_List[i], key_data.Get_KeyData(i).LayerName);
    Serial.println(key_data.Get_KeyData(i).LayerName);
  }
}

void loop() {
  switch (OLED_SceneNumber) {
    case 0:
      {
        Scene_Main();
        break;
      }
    case 1:
      {
        Scene_LayerList();
        break;
      }
    case 2:
      {
        Scene_SettingMode();
        break;
      }
  }
}

void Scene_Main() {
  int get_data = 0;
  get_data = oled_display.OLED_MainView("Home", Layer_Number, LayerName_List);
  if (get_data == 1) OLED_SceneNumber = 1;
  if (get_data == 2) {
    layer_data = key_data.Get_KeyData(Layer_Number);
    OLED_SceneNumber = 2;
  }
}

void Scene_LayerList() {
  int get_data = 0;
  get_data = oled_display.OLED_ListView("Layer_List", LayerName_List, Layer_Number, 10);
  if (get_data == -1 || get_data == 10) {
    OLED_SceneNumber = 0;
  } else {
    Layer_Number = get_data;
    layer_data = key_data.Get_KeyData(Layer_Number);
    if (key_data.Get_KeyData(Layer_Number).LayerName != NULL)
      strcpy(layer_data.LayerName, LayerName_List[Layer_Number]);

    Serial.println(layer_data.LayerName);
    Serial.println(Layer_Number);
    OLED_SceneNumber = 0;
  }
}

void Scene_SettingMode() {

  int get_data = 0;
  unsigned char icon[13][200];
  for (int i = 0; i < 200; i++) {
    icon[0][i] = Name[i];
    icon[1][i] = key1[i];
    icon[2][i] = key2[i];
    icon[3][i] = key3[i];
    icon[4][i] = key4[i];
    icon[5][i] = key5[i];
    icon[6][i] = key6[i];

    icon[7][i] = Rotary_A[i];
    icon[8][i] = Rotary_B[i];
    icon[9][i] = Rotary_C[i];

    icon[10][i] = Wheel_A[i];
    icon[11][i] = Wheel_B[i];
    icon[12][i] = Wheel_C[i];
  }

  get_data = oled_display.OLED_IconListView("Setting", icon, interface_icon, 13);

  if (get_data == -1) {
    OLED_SceneNumber = 0;

    key_data.Set_KeyData(Layer_Number, layer_data);  //데이터 임시저장
    //===================================================layer_data에 있는 데이터 초기화

    Serial.println(key_data.Get_KeyData(Layer_Number).Button_1);

    strcpy(LayerName_List[Layer_Number], key_data.Get_KeyData(Layer_Number).LayerName);

    key_data.EEPROM_DataSave();

  } else if (get_data == 0) {
    Scene_NameSettingView();  //이름 설정
  } else {
    Scene_FunctionType(get_data);  //키 설정
  }
}
void Scene_FunctionType(int Key_Number) {
  int get_data = 0;
  int listSize;

  unsigned char icon[4][200];
  for (int i = 0; i < 200; i++) {
    icon[0][i] = KeyBoard[i];
    icon[1][i] = Media[i];
    icon[2][i] = App[i];
    if (Key_Number > 0 && Key_Number < 7) icon[3][i] = Color[i];
  }

  if (Key_Number < 7) listSize = 4;
  else listSize = 3;

  get_data = oled_display.OLED_IconListView("Setting", icon, function_icon, listSize);

  switch (get_data) {
    case 0:
      {
        //키보드
        break;
      }
    case 1:
      {
        //미디어
        Scene_MediaDataList(Key_Number);
        break;
      }
    case 2:
      {
        //앱
        Scene_AppDataList(Key_Number);
        break;
      }
    case 3:
      {
        //색상
        break;
      }
  }
}

void Scene_NameSettingView() {
  char* text = oled_display.OLED_TextEditView();
  layer_data.LayerName = text;
}
void Scene_MediaDataList(int Key_Number) {
  int get_data = 0;
  get_data = oled_display.OLED_ListView("Setting", Media_display, 0, 8);

  KeyData_Set(Key_Number, get_data, MEDIA);
}
void Scene_AppDataList(int Key_Number) {
  int get_data = 0;
  get_data = oled_display.OLED_ListView("Setting", App_display, 0, 4);

  KeyData_Set(Key_Number, get_data, APP);
}

void KeyData_Set(int Key_Number, int get_data, int Type) {
  switch (Key_Number) {
    case 1:
      {
        layer_data.KeyType_Button_1 = Type;
        layer_data.Button_1 = get_data;
        break;
      }
    case 2:
      {
        layer_data.KeyType_Button_2 = Type;
        layer_data.Button_2 = get_data;
        break;
      }
    case 3:
      {
        layer_data.KeyType_Button_3 = Type;
        layer_data.Button_3 = get_data;
        break;
      }
    case 4:
      {
        layer_data.KeyType_Button_4 = Type;
        layer_data.Button_4 = get_data;
        break;
      }
    case 5:
      {
        layer_data.KeyType_Button_5 = Type;
        layer_data.Button_5 = get_data;
        break;
      }
    case 6:
      {
        layer_data.KeyType_Button_6 = Type;
        layer_data.Button_6 = get_data;
        break;
      }

    case 7:
      {
        layer_data.KeyType_RotaryUp = Type;
        layer_data.RotaryUp = get_data;
        break;
      }
    case 8:
      {
        layer_data.KeyType_RotaryDown = Type;
        layer_data.RotaryDown = get_data;
        break;
      }
    case 9:
      {
        layer_data.KeyType_RotaryPush = Type;
        layer_data.RotaryPush = get_data;
        break;
      }

    case 10:
      {
        layer_data.KeyType_WheelUp = Type;
        layer_data.WheelUp = get_data;
        break;
      }
    case 11:
      {
        layer_data.KeyType_WheelDown = Type;
        layer_data.WheelDown = get_data;
        break;
      }
    case 12:
      {
        layer_data.KeyType_WheelPush = Type;
        layer_data.WheelPush = get_data;
        break;
      }
  }
}