#pragma once

class OLED_Display {
private:


public:
  void OLED_Display_Init();
  int OLED_MainView(char* ViewName, int LayerNumber, char (*LayerName)[20]);
  int OLED_ListView(char* ViewName, char (*Text)[20], int set_Cursor, int list_size);
  int OLED_IconListView(char* ViewName, unsigned char (*icon)[200], char (*IconName)[15], int list_size);
  char* OLED_TextEditView();
};