#include "LayerData.h"

class KeyData {
private:
public:
  void Set_KeyData(int LayerNumber, LayerData layer_data);
  LayerData Get_KeyData(int LayerNumber);
  void EEPROM_DataInit();
  void EEPROM_DataSave();
  void EEPROM_DataLoad();
};