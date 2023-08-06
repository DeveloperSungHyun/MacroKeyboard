#include "KeyData.h"
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