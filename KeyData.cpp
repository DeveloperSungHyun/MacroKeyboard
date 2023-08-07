#include "KeyData.h"
#include "EEPROM.h"
#include <string.h>


static LayerData layer_data_list[10];
void KeyData::Set_KeyData(int LayerNumber, LayerData layer_data) {
  layer_data_list[LayerNumber] = layer_data;
  //strcpy(layer_data_list[LayerNumber].LayerName, layer_data.LayerName);
  //layer_data_list[LayerNumber].LayerName = layer_data.LayerName;
}

LayerData KeyData::Get_KeyData(int LayerNumber) {
  return layer_data_list[LayerNumber];
}

void KeyData::EEPROM_DataInit() {
  Serial.begin(115200);
  if (!EEPROM.begin(1000)) {
    Serial.println("Failed to initialise EEPROM");
    Serial.println("Restarting...");
    delay(1000);
    ESP.restart();
  }
}

void KeyData::EEPROM_DataSave() {
  int address = 0;

  for (int i = 0; i < 10; i++) {
    EEPROM.writeString(address, layer_data_list[i].LayerName);
    address += 20;

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_Button_1);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_Button_1[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].Button_1);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_Button_2);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_Button_2[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].Button_2);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_Button_3);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_Button_3[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].Button_3);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_Button_4);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_Button_4[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].Button_4);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_Button_5);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_Button_5[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].Button_5);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_Button_6);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_Button_6[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].Button_6);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_RotaryUp);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_RotaryUp[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].RotaryUp);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_RotaryDown);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_RotaryDown[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].RotaryDown);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_RotaryPush);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_RotaryPush[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].RotaryPush);
    address += sizeof(char);
    //===================================================================

    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_WheelUp);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_WheelUp[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].WheelUp);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_WheelDown);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_WheelDown[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].WheelDown);
    address += sizeof(char);
    //===================================================================

    EEPROM.writeChar(address, (char)layer_data_list[i].KeyType_WheelPush);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      EEPROM.writeBool(address, layer_data_list[i].ComKey_WheelPush[b]);
      address += sizeof(bool);
    }
    EEPROM.writeChar(address, (char)layer_data_list[i].WheelPush);
    address += sizeof(char);
  }
  //===================================================================

  EEPROM.commit();
}
void KeyData::EEPROM_DataLoad() {
  // for(int i = 0; i < 10; i++){
  //   strcpy(layer_data_list[i].LayerName, &EEPROM.readUChar(0));
  // }
  int address = 0;

  for (int i = 0; i < 10; i++) {
    layer_data_list[i].LayerName = strcpy(new char[EEPROM.readString(address).length() + 1], EEPROM.readString(address).c_str());
    address += 20;

    layer_data_list[i].KeyType_Button_1 = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_Button_1[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].Button_1 = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_Button_2 = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_Button_2[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].Button_2 = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_Button_3 = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_Button_3[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].Button_3 = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_Button_4 = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_Button_4[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].Button_4 = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_Button_5 = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_Button_5[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].Button_5 = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_Button_6 = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_Button_6[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].Button_6 = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_RotaryUp = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_RotaryUp[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].RotaryUp = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_RotaryDown = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_RotaryDown[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].RotaryDown = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_RotaryPush = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_RotaryPush[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].RotaryPush = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_WheelUp = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_WheelUp[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].WheelUp = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_WheelDown = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_WheelDown[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].WheelDown = EEPROM.readChar(address);
    address += sizeof(char);
    //===================================================================

    layer_data_list[i].KeyType_WheelPush = EEPROM.readChar(address);
    address += sizeof(char);
    for (int b = 0; b < 4; b++) {
      layer_data_list[i].ComKey_WheelPush[b] = EEPROM.readBool(address);
      address += sizeof(bool);
    }
    layer_data_list[i].WheelPush = EEPROM.readChar(address);
    address += sizeof(char);
  }
  //===================================================================


  Serial.println(address);
}