#include "menu.h"
#include "archives.h"
#include "stdbool.h"
#define X_Coord_String				5
#define X_Coord_String_Value 181
extern const unsigned char gImage_Power[54];
extern const unsigned char gImage_User_icon[54];
extern const unsigned char gImage_Warning[54];
extern const unsigned char gImage_Signal[54];

strPtr StriNg;
extern Indexes Indexes_str;
Indexes Ind2;
uint8_t password_flag = 0;

int key_code = 0;
int8_t menu_struct [32] = {1,0,0,0};
int8_t menu_column = 0;
uint8_t max_column = 3;
int8_t IndexCnt = 0;
struct type_ar{
	uint8_t hour: 1;
	uint8_t day: 1;
	uint8_t month: 1;
	uint8_t year: 1;
	uint8_t event: 1;
	uint8_t intervention: 1;
};
struct type_ar Type_Ar;
//unsigned char menu_max[] = {7, 7, 7, 7, 7,7};
//const char *menu_items[10][10]= 
//{
//{"������","������� �����", "������������", "��������� �������", "���������� � �������"},
//{"�������","��������","��������","�������","��������� ��������","������������","�������� ������"},
//{"���.,��","����","�����","4","5","6","7"},
//{"���� ����������","����","�����","������� �� ������ �����","���������� ���","����� �����������","���������� �������", "��������� �������"},
//{"Streamex V1","�������� �����","��_��:","��_����","����������� ��:","����� ���������:","6","7"},
//{"Gff V1","fggg","��_gg:","��_�45554","����������� ��:","����� ���������:","6","7"},

//};
const unsigned char Logo [] = {
0xFA, 0x00, 0x80, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0,
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8,
0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8,
0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xE0,
0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x3E,
0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
0x0F, 0x0F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F,
0x0F, 0x0F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C,
0x7C, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xE0, 0xE0, 0xE0, 0xE0, 0xF0, 0xF0, 0xF0, 0x7F,
0x7F, 0x7F, 0x7F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x7F, 0x7F, 0x7F, 0x7F, 0xF0,
0xF0, 0xF0, 0xE0, 0xE0, 0xE0, 0xE0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x80, 0xF0, 0xF0, 0xF0, 0xF0, 0xFC, 0xFC, 0xFC, 0x7E, 0x7E, 0x7E, 0x0F,
0x0F, 0x0F, 0x0F, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x80, 0x80, 0xF0, 0xF0, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xF0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x0F,
0x0F, 0x0F, 0x0F, 0x7E, 0x7E, 0x7E, 0xFC, 0xFC, 0xFC, 0xF0, 0xF0, 0xF0, 0xF0, 0x80, 0x80, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0x80, 0xC0, 0xE0, 0xE0, 0xF0, 0x70, 0x3E, 0x3E, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F,
0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xC0, 0xFE, 0xFF, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFE,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x01, 0x01, 0x01, 0x0F, 0x0F, 0x0F, 0x1F, 0x1F, 0x3F, 0x3E, 0x3E, 0x70, 0xF0, 0xE0,
0xE0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xF0, 0xF8, 0x7F, 0x3F, 0x0F, 0x0F,
0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0xC0, 0xC0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x80, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xC0, 0x00, 0x00, 0x00,
0x80, 0xC0, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0x80, 0x80, 0x80,
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80,
0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x80, 0x80,
0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0F, 0x0F, 0x3F, 0x7F, 0xF8, 0xF0,
0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0,
0xF8, 0x7F, 0x3F, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x07, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xFF,
0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xE0, 0xE0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00,
0x00, 0x00, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF,
0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xE0, 0xF8, 0xFE, 0xFF, 0x7F, 0x7F, 0x7F,
0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xF8, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x78, 0x7E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xFE, 0xF8, 0xF8, 0x78, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xE0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x01, 0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFE, 0xF8, 0xE0, 0xE0, 0xF8, 0xFF, 0x7F, 0x3F, 0x1F, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x3F, 0x7F, 0xF8, 0xE0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x3F, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xF8, 0x30, 0x00, 0x00, 0x00, 0x03, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x0F, 0x07, 0x03, 0x03, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x03, 0x03, 0xF7, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0x03, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x00, 0x00, 0x00,
0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7,
0xC3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x3F, 0x3F, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x3F, 0xFF, 0xFF, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x0F, 0x1F, 0x1F, 0x1F, 0x1F,
0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00,
0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x1C, 0x1C, 0x1C,
0x0C, 0x0F, 0x0F, 0x0F, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xE0, 0xE0, 0xE0, 0xF0, 0x3C, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x3F,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0x1C, 0x1C, 0x1C, 0x0C, 0x0F, 0x0F, 0x0F, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0xCF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1F, 0x7F, 0xFC,
0xF8, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7F, 0xFE, 0xFE,
0xFE, 0xFC, 0xFC, 0xF8, 0xF8, 0xF8, 0xE0, 0xE0, 0xE0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xFF, 0xFF, 0xFF,
0x7F, 0x1F, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x7F, 0x7F, 0xFF,
0xFF, 0xFF, 0xFF, 0x1E, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x7F,
0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0x7C, 0x1C, 0x02, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x07, 0x03, 0x01, 0x00,
0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F,
0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x1F, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC, 0x7C,
0x1C, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0xFC, 0xFE, 0x1F, 0x07, 0x07, 0x07,
0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x1F, 0x1F, 0xFE, 0xFC, 0xF0,
0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFC, 0xF0, 0xF0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00,
0xE0, 0xE0, 0xF0, 0xF0, 0xFC, 0xFE, 0x1F, 0x0F, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x03,
0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x01, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x01,
0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F,
0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x00, 0xE0, 0xE0, 0xF0, 0xF0, 0xFC, 0xFC,
0xFE, 0x1F, 0x0F, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x03, 0x03,
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F, 0x0E, 0x7E, 0x7C, 0xF8,
0xF8, 0xF0, 0xF0, 0xF0, 0x80, 0x80, 0x01, 0x03, 0x03, 0x07, 0x07, 0x0F, 0x7F, 0x7F, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0x7E, 0x0E, 0x0F, 0x07, 0x07, 0x03, 0x01, 0x01,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0xFC, 0x7C,
0x7C, 0x7E, 0x0E, 0x0E, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x0F, 0x0F, 0x3F,
0x3F, 0x3F, 0x3F, 0x7E, 0x7E, 0x7E, 0xF0, 0xF0, 0xF0, 0xC0, 0xC0, 0xC1, 0x81, 0x81, 0x81, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0,
0xC0, 0xC0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xFE, 0x7E, 0x7E, 0x7E, 0x7F, 0x3F, 0x3F, 0x3F, 0x0F,
0x0F, 0x0F, 0x0F, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x0F, 0x0F, 0x0F, 0xFF, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xFC,
0xFC, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xFE,
0xFE, 0xFE, 0xFE, 0xFE, 0x0F, 0x0F, 0x0F, 0x0F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01,
0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x0F,
0x0F, 0x0F, 0x0F, 0x0F, 0x3F, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C, 0x7C,
0x7C, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0,
0xC0, 0xC0, 0xC0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x7C, 0x7C, 0x7C, 0x7C,
0x7C, 0x7C, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x03, 0x03,
0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F,
0x7F, 0x7F, 0x7F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};


const char y_menu[4] = 
{
	47,
	67,
	87,
	107
};
void StringsA (char *ScreenName){
Paint_String(125, MENU_TITLE_Y, ScreenName, &Font12, BLACK, CENTER);

for (unsigned char i = 0; i < 4; i++)
{
Paint_String(X_Coord_String, y_menu[i], StriNg.string[i], &Font12, BLACK, LEFT);
Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i], &Font12, BLACK, LEFT);

}
}
//#########$$$$$$$$$$$$$$###########################
void Strings (uint8_t idx, uint8_t numItems, char *ScreenName){

				menu_struct [idx+1] = 0;
			if(menu_struct [idx]>numItems)menu_struct [idx] = 0;
			if(menu_struct [idx]<0)menu_struct [idx] = numItems;

			//if (menu_struct[1]<=255 && menu_struct[1]>245) menu_struct[1]=0;
			//else if (menu_struct[1]>numItems && menu_struct[1]<245) menu_struct[1]=numItems;
			Paint_String(125, MENU_TITLE_Y, ScreenName, &Font12, BLACK, CENTER);
			if (menu_struct [idx] <4) 
			{
					for (unsigned char i = 0; i < 4; i++)
						{
							if (i==menu_struct[idx])
							{
								Paint_Line(0, y_menu[i]+2, 250, y_menu[i]+22, BLACK);
								Paint_String(X_Coord_String, y_menu[i], StriNg.string[i], &Font12, WHITE, LEFT);
								Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i], &Font12, WHITE, LEFT);
							}
							else {Paint_String(X_Coord_String, y_menu[i], StriNg.string[i], &Font12, BLACK, LEFT);
										Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i], &Font12, BLACK, LEFT);}
						}
			}
						if (menu_struct [idx] >3 && menu_struct [idx]<8){ // next page!!!
					for (unsigned char i = 0; i < 4; i++)
						{
							if (i==menu_struct[idx]-4)
							{
								Paint_Line(0, y_menu[i]+2, 250, y_menu[i]+22, BLACK);
								Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+4], &Font12, WHITE, LEFT);
								Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+4], &Font12, WHITE, LEFT);
							}
							else {Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+4], &Font12, BLACK, LEFT);
										Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+4], &Font12, BLACK, LEFT);}
						}	
					}

					if (menu_struct [idx] >7&& menu_struct [idx]<12){ // next page!!!
					for (unsigned char i = 0; i < 4; i++)
						{
							if (i==menu_struct[idx]-8)
							{
								Paint_Line(0, y_menu[i]+2, 250, y_menu[i]+22, BLACK);
								Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+8], &Font12, WHITE, LEFT);
								Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+8], &Font12, WHITE, LEFT);
							}
							else {Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+8], &Font12, BLACK, LEFT);
										Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+8], &Font12, BLACK, LEFT);}
						}	
					}
					
					if (menu_struct [idx] >11 && menu_struct [idx]<16){ // next page!!!
					for (unsigned char i = 0; i < 4; i++)
						{
							if (i==menu_struct[idx]-12)
							{
								Paint_Line(0, y_menu[i]+2, 250, y_menu[i]+22, BLACK);
								Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+12], &Font12, WHITE, LEFT);
								Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+12], &Font12, WHITE, LEFT);
							}
							else {Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+12], &Font12, BLACK, LEFT);
							  		Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+12], &Font12, BLACK, LEFT);}
						}	
					}
					if (menu_struct [idx] >15 && menu_struct [idx]<20){ // next page!!!
					for (unsigned char i = 0; i < 4; i++)
						{
							if (i==menu_struct[idx]-16)
							{
								Paint_Line(0, y_menu[i]+2, 250, y_menu[i]+22, BLACK);
								Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+16], &Font12, WHITE, LEFT);
								Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+16], &Font12, WHITE, LEFT);
							}
							else {Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+16], &Font12, BLACK, LEFT);
							  		Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+16], &Font12, BLACK, LEFT);}
						}	
					}
					
					if (menu_struct [idx] >19 && menu_struct [idx]<24){ // next page!!!
					for (unsigned char i = 0; i < 4; i++)
						{
							if (i==menu_struct[idx]-20)
							{
								Paint_Line(0, y_menu[i]+2, 250, y_menu[i]+22, BLACK);
								Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+20], &Font12, WHITE, LEFT);
								Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+20], &Font12, WHITE, LEFT);
							}
							else {Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+20], &Font12, BLACK, LEFT);
							  		Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+20], &Font12, BLACK, LEFT);}
						}	
					}
					
					if (menu_struct [idx] >23 && menu_struct [idx]<28){ // next page!!!
					for (unsigned char i = 0; i < 4; i++)
						{
							if (i==menu_struct[idx]-24)
							{
								Paint_Line(0, y_menu[i]+2, 250, y_menu[i]+22, BLACK);
								Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+24], &Font12, WHITE, LEFT);
								Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+24], &Font12, WHITE, LEFT);
							}
							else {Paint_String(X_Coord_String, y_menu[i], StriNg.string[i+24], &Font12, BLACK, LEFT);
							  		Paint_String(X_Coord_String_Value, y_menu[i], StriNg.string_val[i+24], &Font12, BLACK, LEFT);}
						}	
					}
}
//#########$$$$$$$$$$$$$$###########################
void keys(main_streamex *GEM, rt_clock *rt, uint8_t change){
static uint8_t uz_channel;
static uint8_t pressed;
//uint8_t change = 0;

if(GEM->int_flags.Button1==0&&pressed==1){pressed=0;}
if(GEM->int_flags.Button2==0&&pressed==2){pressed=0;}
if(GEM->int_flags.Button3==0&&pressed==3){pressed=0;}
if(GEM->int_flags.Button4==0&&pressed==4){pressed=0;}

if(GEM->int_flags.Button1==1&&pressed==0){key_code =3;pressed=1;}
if(GEM->int_flags.Button2==1&&pressed==0){key_code =5;pressed=2;}
if(GEM->int_flags.Button3==1&&pressed==0){key_code =2;pressed=3;}
if(GEM->int_flags.Button4==1&&pressed==0){key_code =4;pressed=4;}

//if(GEM->int_flags.Button1==1){key_code =3;change = 1;}
//if(GEM->int_flags.Button2==1){key_code =5;change = 1;}
//if(GEM->int_flags.Button3==1){key_code =2;change = 1;}
//if(GEM->int_flags.Button4==1){key_code =4;change = 1;}

	
if(GEM->sav.Channel_quantity==2){ // ������������ �������, ������� �����
if(menu_column == 0){
if(key_code == 2&&uz_channel<1){ //UP
uz_channel++;
}
if(key_code == 4&&uz_channel>0){ //DOWN
uz_channel--;
}
}
}

    if(key_code == 3&&menu_column<max_column) //ENTER
			{
					menu_column++;
				//if (menu_column>2) menu_column=2;

			}
    if(key_code == 5&&menu_column>0) //ESC
			{
					menu_column--;
			}
		 if(key_code == 4) //DOWN
			{
				menu_struct [menu_column] --;
				if(Type_Ar.day==1){Ind2.Day_index++;if(Ind2.Day_index>Indexes_str.Day_index-1){Ind2.Day_index=0;}}
				if(Type_Ar.event==1){Ind2.Event_index++;if(Ind2.Event_index>Indexes_str.Event_index-1){Ind2.Event_index=0;}}
				if(Type_Ar.hour==1){Ind2.Hour_index++;if(Ind2.Hour_index>Indexes_str.Hour_index-1){Ind2.Hour_index=0;}}
				if(Type_Ar.intervention==1){Ind2.Intervention_index++;if(Ind2.Intervention_index>Indexes_str.Intervention_index-1){Ind2.Intervention_index=0;}}
				if(Type_Ar.month==1){Ind2.Month_index++;if(Ind2.Month_index>Indexes_str.Month_index-1){Ind2.Month_index=0;}}
				if(Type_Ar.year==1){Ind2.Year_index++;if(Ind2.Year_index>Indexes_str.Year_index-1){Ind2.Year_index=0;}}	

			}	
		 if(key_code == 2) //UP
			{				
				menu_struct [menu_column] ++;
				if(Type_Ar.day==1){if(Ind2.Day_index>0){Ind2.Day_index--;}else{Ind2.Day_index=Indexes_str.Day_index-1;}}
				if(Type_Ar.event==1){if(Ind2.Event_index>0){Ind2.Event_index--;}else{Ind2.Event_index=Indexes_str.Event_index-1;}}
				if(Type_Ar.hour==1){if(Ind2.Hour_index>0){Ind2.Hour_index--;}else{Ind2.Hour_index=Indexes_str.Hour_index-1;}}
				if(Type_Ar.intervention==1){if(Ind2.Intervention_index>0){Ind2.Intervention_index--;}else{Ind2.Intervention_index=Indexes_str.Intervention_index-1;}}
				if(Type_Ar.month==1){if(Ind2.Month_index>0){Ind2.Month_index--;}else{Ind2.Month_index = Indexes_str.Month_index-1;}}
				if(Type_Ar.year==1){if(Ind2.Year_index>0){Ind2.Year_index--;}else{Ind2.Year_index = Indexes_str.Year_index-1;}}	
					
	
			}	
	key_code = 0;	
if(GEM->Status_.init_complete==false){Menu_struct(uz_channel,GEM, rt,lut_full_update, change);}else{Menu_struct(uz_channel,GEM, rt,lut_partial_update, change);}	
}
//#########$$$$$$$$$$$$$$###########################
//#########$$$$$$$$$$$$$$###########################
void Draw_Main_Archives_Hourly(uint8_t uz_channel, main_streamex *GEM)	{
Arch Arch_str;
	Type_Ar.day=0;
	Type_Ar.event=0;
	Type_Ar.hour=1;
	Type_Ar.intervention=0;
	Type_Ar.month=0;
	Type_Ar.year=0;
Read_Arch(&Arch_str, NULL, NULL,NULL, Ind2.Hour_index, 0);  // 0-hour arch, 1-day arch, 2-month arch, 3-year arch 4-intervention arch 5-event arch //
Ind2.Hour_index+=IndexCnt;
memset(&StriNg,0x00,sizeof(StriNg));


sprintf(StriNg.string[0], "���/���. %02d.%02d.%02d.%02d/%d",Arch_str.Hour, Arch_str.Day,Arch_str.Month,Arch_str.Year, Ind2.Hour_index); // � ������ 28 ��������!
sprintf(StriNg.string[1], "����������� %-8.3f", Arch_str.Temperature[uz_channel]);
sprintf(StriNg.string[2], "�������� %-8.3f", Arch_str.Preassure[uz_channel]);
sprintf(StriNg.string[3], "������ %-8.3f",Arch_str.Flow[uz_channel]);
	
//sprintf(StriNg.string_val[1], "%-8.3f", Arch_str.Temperature[uz_channel]); 
//sprintf(StriNg.string_val[2], "%-8.3f", Arch_str.Preassure[uz_channel]);
//sprintf(StriNg.string_val[3], "%-8.3f", Arch_str.Flow[uz_channel]);
	

StringsA("������� ������");
}
//#########$$$$$$$$$$$$$$###########################
void Draw_Main_Archives_Daily(uint8_t uz_channel,main_streamex *GEM){
Arch Arch_str;
	Type_Ar.day=1;
	Type_Ar.event=0;
	Type_Ar.hour=0;
	Type_Ar.intervention=0;
	Type_Ar.month=0;
	Type_Ar.year=0;

Read_Arch(&Arch_str, NULL, NULL,NULL, Ind2.Day_index, 1);  // 0-hour arch, 1-day arch, 2-month arch, 3-year arch 4-intervention arch 5-event arch //
Ind2.Day_index+=IndexCnt;
memset(&StriNg,0x00,sizeof(StriNg));
sprintf(StriNg.string[0], "���/���. %02d.%02d.%02d.%02d/%d",Arch_str.Hour, Arch_str.Day,Arch_str.Month,Arch_str.Year, Ind2.Day_index); // � ������ 28 ��������!
sprintf(StriNg.string[1], "����������� %-8.3f", Arch_str.Temperature[uz_channel]);
sprintf(StriNg.string[2], "�������� %-8.3f", Arch_str.Preassure[uz_channel]);
sprintf(StriNg.string[3], "������ %-8.3f",Arch_str.Flow[uz_channel]);
//sprintf(StriNg.string_val[1], "%-8.3f", Arch_str.Temperature[uz_channel]); 
//sprintf(StriNg.string_val[2], "%-8.3f", Arch_str.Preassure[uz_channel]);
//sprintf(StriNg.string_val[3], "%-8.3f", Arch_str.Flow[uz_channel]);
	

StringsA("�������� ������");
}
//#########$$$$$$$$$$$$$$###########################
void Draw_Main_Archives_Monthly(uint8_t uz_channel, main_streamex *GEM){
Year_MonthArch MonthArch_str;
	Type_Ar.day=0;
	Type_Ar.event=0;
	Type_Ar.hour=0;
	Type_Ar.intervention=0;
	Type_Ar.month=1;
	Type_Ar.year=0;
	

Read_Arch(NULL, &MonthArch_str, NULL,NULL, Ind2.Month_index, 2);  // 0-hour arch, 1-day arch, 2-month arch, 3-year arch 4-intervention arch 5-event arch //
Ind2.Month_index+=IndexCnt;
memset(&StriNg,0x00,sizeof(StriNg));
sprintf(StriNg.string[0], "���/���. %02d.%02d.%02d.%02d/%d",MonthArch_str.Hour, MonthArch_str.Day,MonthArch_str.Month,MonthArch_str.Year, Ind2.Month_index); // � ������ 28 ��������!
sprintf(StriNg.string[1], "����������� %-8.3f", MonthArch_str.Temperature[uz_channel]);
sprintf(StriNg.string[2], "�������� %-8.3f", MonthArch_str.Preassure[uz_channel]);
sprintf(StriNg.string[3], "������ %-8.3f",MonthArch_str.Flow[uz_channel]);

StringsA("�������� ������");
}
//#########$$$$$$$$$$$$$$###########################
void Draw_Main_Archives_Yearly(uint8_t uz_channel, main_streamex *GEM){
Year_MonthArch MonthArch_str;
	Type_Ar.day=0;
	Type_Ar.event=0;
	Type_Ar.hour=0;
	Type_Ar.intervention=0;
	Type_Ar.month=0;
	Type_Ar.year=1;

Read_Arch(NULL, &MonthArch_str, NULL,NULL, Ind2.Year_index, 3);  // 0-hour arch, 1-day arch, 2-month arch, 3-year arch 4-intervention arch 5-event arch //
Ind2.Year_index+=IndexCnt;
memset(&StriNg,0x00,sizeof(StriNg));
sprintf(StriNg.string[0], "���/���. %02d.%02d.%02d.%02d/%d",MonthArch_str.Hour, MonthArch_str.Day,MonthArch_str.Month,MonthArch_str.Year, Ind2.Year_index); // � ������ 28 ��������!
sprintf(StriNg.string[1], "����������� %-8.3f", MonthArch_str.Temperature[uz_channel]);
sprintf(StriNg.string[2], "�������� %-8.3f", MonthArch_str.Preassure[uz_channel]);
sprintf(StriNg.string[3], "������ %-8.3f",MonthArch_str.Flow[uz_channel]);


StringsA("������� ������");
}
//#########$$$$$$$$$$$$$$###########################
void Draw_Main_Archives_Event(uint8_t uz_channel, main_streamex *GEM){
Event_Arch Event_Arch;
	Type_Ar.day=0;
	Type_Ar.event=1;
	Type_Ar.hour=0;
	Type_Ar.intervention=0;
	Type_Ar.month=0;
	Type_Ar.year=0;
	
Read_Arch(NULL, NULL, &Event_Arch,NULL, Ind2.Event_index, 5);  // 0-hour arch, 1-day arch, 2-month arch, 3-year arch 4-intervention arch 5-event arch //
Ind2.Event_index+=IndexCnt;
memset(&StriNg,0x00,sizeof(StriNg));
sprintf(StriNg.string[0], "���/���. %02d.%02d.%02d.%02d/%d",Event_Arch.Hour, Event_Arch.Day,Event_Arch.Month,Event_Arch.Year, Ind2.Event_index); // � ������ 28 ��������!
sprintf(StriNg.string[1], "������ 0x%04x", Event_Arch.CodeEvent[uz_channel]);

StringsA("������ ��������� ��������");
}
//#########$$$$$$$$$$$$$$###########################
void Draw_Main_Archives_Intervention(uint8_t uz_channel, main_streamex *GEM){
Intervention_Arch Intervention_Arch;
	Type_Ar.day=0;
	Type_Ar.event=0;
	Type_Ar.hour=0;
	Type_Ar.intervention=1;
	Type_Ar.month=0;
	Type_Ar.year=0;
	
Read_Arch(NULL, NULL, NULL,&Intervention_Arch, Ind2.Intervention_index, 4);  // 0-hour arch, 1-day arch, 2-month arch, 3-year arch 4-intervention arch 5-event arch //
Ind2.Intervention_index+=IndexCnt;
memset(&StriNg,0x00,sizeof(StriNg));
sprintf(StriNg.string[0], "���/���. %02d.%02d.%02d.%02d/%d",Intervention_Arch.Hour, Intervention_Arch.Day,Intervention_Arch.Month,Intervention_Arch.Year, Ind2.Intervention_index); // � ������ 28 ��������!
sprintf(StriNg.string[1], "������ 0x%08llx", Intervention_Arch.CodeIntervention[uz_channel]);

StringsA("������ ������������");
}
//#########$$$$$$$$$$$$$$###########################
void Draw_Info(uint8_t uz_channel, main_streamex *GEM){
const uint8_t numItems = 9; // ������������ ������ � StriNg.string[]
memset(&StriNg,0x00,sizeof(StriNg));
if(GEM->sav.Language==1){ // rus
sprintf(StriNg.string[0], "������"); // � ������ 28 ��������!
sprintf(StriNg.string[1],  "%s", GEM->sav.Device_Model);
sprintf(StriNg.string[2], "�������� �����");
sprintf(StriNg.string[3], "%s", GEM->sav.Serial_number);
char d[12]; memcpy(d,GEM->sav.Date_production,10);
sprintf(StriNg.string[4], "���� ������������: %s", d);
sprintf(StriNg.string[5], "���� �������� ��: %s",GEM->par.Activation_Date);
sprintf(StriNg.string[6], "�� �����������");
sprintf(StriNg.string[7], "%s", GEM->par.ID_MCU);
sprintf(StriNg.string[8], "�� ����");
sprintf(StriNg.string[9], "%s", GEM->par.ID_FLASH);
	Strings(menu_column,numItems, "���������� � �������");

}	
if(GEM->sav.Language==2){ // UA
sprintf(StriNg.string[0], "������"); // � ������ 28 ��������!
sprintf(StriNg.string[1],  "%s", GEM->sav.Device_Model);
sprintf(StriNg.string[2], "���i���� �����");
sprintf(StriNg.string[3], "%s", GEM->sav.Serial_number);
char d[12]; memcpy(d,GEM->sav.Date_production,10);
sprintf(StriNg.string[4], "���� �����������: %s", d);
sprintf(StriNg.string[5], "����i� ��: %s",GEM->par.Activation_Date);
sprintf(StriNg.string[6], "I� �����������");
sprintf(StriNg.string[7], "%s", GEM->par.ID_MCU);
sprintf(StriNg.string[8], "I� ����");
sprintf(StriNg.string[9], "%s", GEM->par.ID_FLASH);
	Strings(menu_column,numItems, "I�������i� ��� ������");

}	
if(GEM->sav.Language==3){ // eng
sprintf(StriNg.string[0], "Model"); // � ������ 28 ��������!
sprintf(StriNg.string[1],  "%s", GEM->sav.Device_Model);
sprintf(StriNg.string[2], "Serial number");
sprintf(StriNg.string[3], "%s", GEM->sav.Serial_number);
char d[12]; memcpy(d,GEM->sav.Date_production,10);
sprintf(StriNg.string[4], "Date production: %s", d);
sprintf(StriNg.string[5], "Valid until: %s",GEM->par.Activation_Date);
sprintf(StriNg.string[6], "ID microcontroller");
sprintf(StriNg.string[7], "%s", GEM->par.ID_MCU);
sprintf(StriNg.string[8], "I� flash");
sprintf(StriNg.string[9], "%s", GEM->par.ID_FLASH);
	Strings(menu_column,numItems, "Device information");
}	

}
//#########$$$$$$$$$$$$$$###########################
void Draw_Network_Mode(uint8_t uz_channel, main_streamex *GEM){
const uint8_t numItems = 14;

memset(&StriNg,0x00,sizeof(StriNg));
if(GEM->sav.Language==1){ // rus

sprintf(StriNg.string[0], "����� ������� RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[1], "�������� RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[2], "�������� RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[3], "����. ������ RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[4], "���� ��� RS485:"); // � ������ 28 ��������!
	
	
sprintf(StriNg.string[5], "����� �������(APN):"); // � ������ 28 ��������!
sprintf(StriNg.string[6], "%s", GEM->sav.APN);
sprintf(StriNg.string[7], "������ 1");
sprintf(StriNg.string[8], "%s", GEM->sav.Server_1);
sprintf(StriNg.string[9], "������ 2");
sprintf(StriNg.string[10], "%s",GEM->sav.Server_2);  
sprintf(StriNg.string[11], "���� ������� 1"); 
sprintf(StriNg.string[12], "���� ������� 2"); 
sprintf(StriNg.string[13], "������ NTP"); 
sprintf(StriNg.string[14], "%s", GEM->sav.NTP_server); 

////////////////////////////////////////
/////////////////////////////////////////
sprintf(StriNg.string_val[0], " %d",GEM->sav.Modbus_Number); 
sprintf(StriNg.string_val[1], "%d",GEM->sav.Baudrate); 
sprintf(StriNg.string_val[2], "%d",GEM->sav.Parity); 
sprintf(StriNg.string_val[3], "%d",GEM->sav.Data_bits); 
sprintf(StriNg.string_val[4], "%d",GEM->sav.Stop_bits); 


sprintf(StriNg.string_val[11], "%4d",GEM->sav.Port_Server1); 
sprintf(StriNg.string_val[12], "%4d",GEM->sav.Port_Server2); 

Strings(menu_column,numItems,"��������� ����");
}
if(GEM->sav.Language==2){ // ua
sprintf(StriNg.string[0], "����� ������� RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[1], "����i���� RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[2], "�i��i��� RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[3], "����. ����� RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[4], "���� �i� RS485:"); // � ������ 28 ��������!
	
	
sprintf(StriNg.string[5], "����� �������(APN):"); // � ������ 28 ��������!
sprintf(StriNg.string[6], "%s", GEM->sav.APN);
sprintf(StriNg.string[7], "������ 1");
sprintf(StriNg.string[8], "%s", GEM->sav.Server_1);
sprintf(StriNg.string[9], "������ 2");
sprintf(StriNg.string[10], "%s",GEM->sav.Server_2);  
sprintf(StriNg.string[11], "���� ������� 1"); 
sprintf(StriNg.string[12], "���� ������� 2"); 
sprintf(StriNg.string[13], "������ NTP"); 
sprintf(StriNg.string[14], "%s", GEM->sav.NTP_server); 

////////////////////////////////////////
/////////////////////////////////////////
sprintf(StriNg.string_val[0], " %d",GEM->sav.Modbus_Number); 
sprintf(StriNg.string_val[1], "%d",GEM->sav.Baudrate); 
sprintf(StriNg.string_val[2], "%d",GEM->sav.Parity); 
sprintf(StriNg.string_val[3], "%d",GEM->sav.Data_bits); 
sprintf(StriNg.string_val[4], "%d",GEM->sav.Stop_bits); 


sprintf(StriNg.string_val[11], "%4d",GEM->sav.Port_Server1); 
sprintf(StriNg.string_val[12], "%4d",GEM->sav.Port_Server2); 

Strings(menu_column,numItems,"������������ �����i");


}
if(GEM->sav.Language==3){ // eng
sprintf(StriNg.string[0], "Device number RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[1], "Baudrate RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[2], "Parity RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[3], "Data bits RS485:"); // � ������ 28 ��������!
sprintf(StriNg.string[4], "Stop bits RS485:"); // � ������ 28 ��������!
	
	
sprintf(StriNg.string[5], "Access point(APN):"); // � ������ 28 ��������!
sprintf(StriNg.string[6], "%s", GEM->sav.APN);
sprintf(StriNg.string[7], "Server 1");
sprintf(StriNg.string[8], "%s", GEM->sav.Server_1);
sprintf(StriNg.string[9], "Server 2");
sprintf(StriNg.string[10], "%s",GEM->sav.Server_2);  
sprintf(StriNg.string[11], "Server port 1"); 
sprintf(StriNg.string[12], "Server port 2"); 
sprintf(StriNg.string[13], "Server NTP"); 
sprintf(StriNg.string[14], "%s", GEM->sav.NTP_server); 

////////////////////////////////////////
/////////////////////////////////////////
sprintf(StriNg.string_val[0], " %d",GEM->sav.Modbus_Number); 
sprintf(StriNg.string_val[1], "%d",GEM->sav.Baudrate); 
sprintf(StriNg.string_val[2], "%d",GEM->sav.Parity); 
sprintf(StriNg.string_val[3], "%d",GEM->sav.Data_bits); 
sprintf(StriNg.string_val[4], "%d",GEM->sav.Stop_bits); 


sprintf(StriNg.string_val[11], "%4d",GEM->sav.Port_Server1); 
sprintf(StriNg.string_val[12], "%4d",GEM->sav.Port_Server2); 

Strings(menu_column,numItems,"Network Settings");


}

}
//#########$$$$$$$$$$$$$$###########################
void Draw_Conf_Mode (uint8_t uz_channel, main_streamex *GEM){ // ������������
const uint8_t numItems = 12;
memset(&StriNg,0x00,sizeof(StriNg));

if(GEM->sav.Language==1){ // rus

if(GEM->sav.Language==1){memcpy(StriNg.string[4], "���� ����", 14);} // ���� �������// � ������ 28 ��������!


sprintf(StriNg.string[0], "���������� �������");// � ������ 28 ��������!
sprintf(StriNg.string[1], "����������� ���");
memcpy(StriNg.string[2], "���/��� �����", 14);// � ������ 28 ��������!
sprintf(StriNg.string[3], "������� ����");// � ������ 28 ��������!

//GEM->sav.
memcpy(StriNg.string[5], "���. ���. ����. ���.", 28);// � ������ 28 ��������!


if(GEM->sav.Units[uz_channel]==0){memcpy(StriNg.string[6], "��.���������", 14);} //  � ������ 28 ��������!
sprintf(StriNg.string[7], "���. ������ ");// � ������ 28 ��������!
sprintf(StriNg.string[8], "����. ������");
sprintf(StriNg.string[9], "���. ����. ");// � ������ 28 ��������!
sprintf(StriNg.string[10], "����. ����.");
sprintf(StriNg.string[11], "���. �������� ");// � ������ 28 ��������!
sprintf(StriNg.string[12], "����.��������");


////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


if(GEM->sav.Language==1){memcpy(StriNg.string_val[4], "���", 5);} // ���� �������// � ������ 28 ��������!


sprintf(StriNg.string_val[0], "%-2d", GEM->sav.Channel_quantity);// � ������ 28 ��������!
sprintf(StriNg.string_val[1], "%-2d", GEM->sav.Control_time);
if(GEM->sav.Winter_summer_time_OnOf==0){
memcpy(StriNg.string_val[2], "����", 5);}// � ������ 28 ��������!
else{memcpy(StriNg.string_val[2], "���", 5);}
sprintf(StriNg.string_val[3], "%-2d", GEM->sav.Time_Zone);// � ������ 28 ��������!

//GEM->sav.
if(GEM->sav.Mode_Comb_Channel==0){memcpy(StriNg.string_val[5], "���.", 7);}// � ������ 28 ��������!
if(GEM->sav.Mode_Comb_Channel==1){memcpy(StriNg.string_val[5], "Q1+Q2", 7);}
if(GEM->sav.Mode_Comb_Channel==2){memcpy(StriNg.string_val[5], "Q1+Q2/2", 7);}
if(GEM->sav.Mode_Comb_Channel==3){memcpy(StriNg.string_val[5], "Q1-Q2", 7);}
if(GEM->sav.Mode_Comb_Channel==4){memcpy(StriNg.string_val[5], "Q2-Q1", 7);}


if(GEM->sav.Units[uz_channel]==0){memcpy(StriNg.string_val[6], "�.���", 7);} //  � ������ 28 ��������!
if(GEM->sav.Units[uz_channel]==1){memcpy(StriNg.string_val[6], "�����", 7);} // 
if(GEM->sav.Units[uz_channel]==2){memcpy(StriNg.string_val[6], "�����", 7);} // 

sprintf(StriNg.string_val[7], "%-8.3f", GEM->sav.Minimum_flow[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[8], "%-8.3f", GEM->sav.Maximum_flow[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[9], "%-8.3f", GEM->sav.Minimum_temperature[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[10], "%-8.3f", GEM->sav.Maximum_temperature[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[11], "%-8.3f", GEM->sav.Minimum_preassure[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[12], "%-8.3f", GEM->sav.Maximum_preassure[uz_channel]);// � ������ 28 ��������!


Strings(menu_column,numItems, "������������");
}
if(GEM->sav.Language==2){ // ua
if(GEM->sav.Language==2){memcpy(StriNg.string[4], "���� ����", 14);} // ���� ����������


sprintf(StriNg.string[0], "�i���i��� �����i�");// � ������ 28 ��������!
sprintf(StriNg.string[1], "���������� ������");
memcpy(StriNg.string[2], "���/�i� ���", 14);// � ������ 28 ��������!
sprintf(StriNg.string[3], "������� ����");// � ������ 28 ��������!

//GEM->sav.
memcpy(StriNg.string[5], "���. ���. ����. ���.", 28);// � ������ 28 ��������!


if(GEM->sav.Units[uz_channel]==0){memcpy(StriNg.string[6], "��.���i�������", 14);} //  � ������ 28 ��������!
sprintf(StriNg.string[7], "�i�. ������� ");// � ������ 28 ��������!
sprintf(StriNg.string[8], "����. �������");
sprintf(StriNg.string[9], "�i�. ����.");// � ������ 28 ��������!
sprintf(StriNg.string[10], "����. ����.");
sprintf(StriNg.string[11], "�i�. ����");// � ������ 28 ��������!
sprintf(StriNg.string[12], "����.����");


////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


if(GEM->sav.Language==2){memcpy(StriNg.string_val[4], "���", 5);} // ���� ����������


sprintf(StriNg.string_val[0], "%-2d", GEM->sav.Channel_quantity);// � ������ 28 ��������!
sprintf(StriNg.string_val[1], "%-2d", GEM->sav.Control_time);
if(GEM->sav.Winter_summer_time_OnOf==0){
memcpy(StriNg.string_val[2], "����", 5);}// � ������ 28 ��������!
else{memcpy(StriNg.string_val[2], "���", 5);}
sprintf(StriNg.string_val[3], "%-2d", GEM->sav.Time_Zone);// � ������ 28 ��������!

//GEM->sav.
if(GEM->sav.Mode_Comb_Channel==0){memcpy(StriNg.string_val[5], "����.", 7);}// � ������ 28 ��������!
if(GEM->sav.Mode_Comb_Channel==1){memcpy(StriNg.string_val[5], "Q1+Q2", 7);}
if(GEM->sav.Mode_Comb_Channel==2){memcpy(StriNg.string_val[5], "Q1+Q2/2", 7);}
if(GEM->sav.Mode_Comb_Channel==3){memcpy(StriNg.string_val[5], "Q1-Q2", 7);}
if(GEM->sav.Mode_Comb_Channel==4){memcpy(StriNg.string_val[5], "Q2-Q1", 7);}


if(GEM->sav.Units[uz_channel]==0){memcpy(StriNg.string_val[6], "�.���", 7);} //  � ������ 28 ��������!
if(GEM->sav.Units[uz_channel]==1){memcpy(StriNg.string_val[6], "����", 7);} // 
if(GEM->sav.Units[uz_channel]==2){memcpy(StriNg.string_val[6], "�i���", 7);} // 

sprintf(StriNg.string_val[7], "%-8.3f", GEM->sav.Minimum_flow[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[8], "%-8.3f", GEM->sav.Maximum_flow[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[9], "%-8.3f", GEM->sav.Minimum_temperature[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[10], "%-8.3f", GEM->sav.Maximum_temperature[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[11], "%-8.3f", GEM->sav.Minimum_preassure[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[12], "%-8.3f", GEM->sav.Maximum_preassure[uz_channel]);// � ������ 28 ��������!


Strings(menu_column,numItems, "����i�����i�");

}
if(GEM->sav.Language==3){ // eng
if(GEM->sav.Language==3){memcpy(StriNg.string[4], "Menu language", 14);} // ���� ����������


sprintf(StriNg.string[0], "Channels quantity");// � ������ 28 ��������!
sprintf(StriNg.string[1], "Control time");
memcpy(StriNg.string[2], "Win/Sum time", 14);// � ������ 28 ��������!
sprintf(StriNg.string[3], "Timezone");// � ������ 28 ��������!

//GEM->sav.
memcpy(StriNg.string[5], "Oper. mod. comb. ch.", 28);// � ������ 28 ��������!


if(GEM->sav.Units[uz_channel]==0){memcpy(StriNg.string[6], "Units", 14);} //  � ������ 28 ��������!
sprintf(StriNg.string[7], "Min. consump.");// � ������ 28 ��������!
sprintf(StriNg.string[8], "Max. consump.");
sprintf(StriNg.string[9], "Min. temp.");// � ������ 28 ��������!
sprintf(StriNg.string[10], "Max. temp.");
sprintf(StriNg.string[11], "Min. preassure");// � ������ 28 ��������!
sprintf(StriNg.string[12], "Max. preassure");


////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////


if(GEM->sav.Language==3){memcpy(StriNg.string_val[4], "Eng", 5);} // ���� ����������


sprintf(StriNg.string_val[0], "%-2d", GEM->sav.Channel_quantity);// � ������ 28 ��������!
sprintf(StriNg.string_val[1], "%-2d", GEM->sav.Control_time);
if(GEM->sav.Winter_summer_time_OnOf==0){
memcpy(StriNg.string_val[2], "Off", 5);}// � ������ 28 ��������!
else{memcpy(StriNg.string_val[2], "On", 5);}
sprintf(StriNg.string_val[3], "%-2d", GEM->sav.Time_Zone);// � ������ 28 ��������!

//GEM->sav.
if(GEM->sav.Mode_Comb_Channel==0){memcpy(StriNg.string_val[5], "Off.", 7);}// � ������ 28 ��������!
if(GEM->sav.Mode_Comb_Channel==1){memcpy(StriNg.string_val[5], "Q1+Q2", 7);}
if(GEM->sav.Mode_Comb_Channel==2){memcpy(StriNg.string_val[5], "Q1+Q2/2", 7);}
if(GEM->sav.Mode_Comb_Channel==3){memcpy(StriNg.string_val[5], "Q1-Q2", 7);}
if(GEM->sav.Mode_Comb_Channel==4){memcpy(StriNg.string_val[5], "Q2-Q1", 7);}


if(GEM->sav.Units[uz_channel]==0){memcpy(StriNg.string_val[6], "m.cub", 7);} //  � ������ 28 ��������!
if(GEM->sav.Units[uz_channel]==1){memcpy(StriNg.string_val[6], "Tons", 7);} // 
if(GEM->sav.Units[uz_channel]==2){memcpy(StriNg.string_val[6], "Liters", 7);} // 

sprintf(StriNg.string_val[7], "%-8.3f", GEM->sav.Minimum_flow[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[8], "%-8.3f", GEM->sav.Maximum_flow[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[9], "%-8.3f", GEM->sav.Minimum_temperature[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[10], "%-8.3f", GEM->sav.Maximum_temperature[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[11], "%-8.3f", GEM->sav.Minimum_preassure[uz_channel]);// � ������ 28 ��������!
sprintf(StriNg.string_val[12], "%-8.3f", GEM->sav.Maximum_preassure[uz_channel]);// � ������ 28 ��������!


Strings(menu_column,numItems, "Configuration");

}


}
//#########$$$$$$$$$$$$$$###########################
void Draw_Setting_Mode (uint8_t uz_channel, main_streamex *GEM){ // ���������
const uint8_t numItems = 13;

memset(&StriNg,0x00,sizeof(StriNg));

if(GEM->sav.Language==1){ // rus
sprintf(StriNg.string[0], "�����. �������, ��"); // � ������ 28 ��������!
sprintf(StriNg.string[1], "����. ���., ����");
sprintf(StriNg.string[2], "����. ���. ���., ��");
sprintf(StriNg.string[3], "������� ���, ���");
sprintf(StriNg.string[4], "����. ���. ���, ��");
sprintf(StriNg.string[5], "����� ���. ���");  
sprintf(StriNg.string[6], "��. ����. ����, ���"); 
sprintf(StriNg.string[7], "��. ����. ����, ���");      
sprintf(StriNg.string[8], "��. ��������, ���");         
sprintf(StriNg.string[9], "��. � ������ ���, ���");        
sprintf(StriNg.string[10],"����������� Sg");
sprintf(StriNg.string[11], "������. ������");        
sprintf(StriNg.string[12],"����. ������. ��.,");
sprintf(StriNg.string[13],"���-�� ���������, ��");
sprintf(StriNg.string[14],"������");


sprintf(StriNg.string_val[0], "%-8.3f", GEM->sav.Interrior_diameter[uz_channel]); 
sprintf(StriNg.string_val[1], "%-8.3f", GEM->sav.Angle_installation[uz_channel]);
sprintf(StriNg.string_val[2], "%-8.3f", GEM->sav.Length_acoustic_channel[uz_channel]);
if(GEM->sav.PEA_Frequency[uz_channel]==1)sprintf(StriNg.string_val[3], "1");
if(GEM->sav.PEA_Frequency[uz_channel]==2)sprintf(StriNg.string_val[3], "0.5");
if(GEM->sav.PEA_Frequency[uz_channel]==3)sprintf(StriNg.string_val[3], "0.25");
if(GEM->sav.PEA_Frequency[uz_channel]==4)sprintf(StriNg.string_val[3], "0.125");

sprintf(StriNg.string_val[4], "%-8.3f", GEM->sav.Pocket_installation[uz_channel]); 
if(GEM->sav.Schema_installation[uz_channel]==1)sprintf(StriNg.string_val[5], "Z");
if(GEM->sav.Schema_installation[uz_channel]==2)sprintf(StriNg.string_val[5], "V");
if(GEM->sav.Schema_installation[uz_channel]==3)sprintf(StriNg.string_val[5], "N");
if(GEM->sav.Schema_installation[uz_channel]==4)sprintf(StriNg.string_val[5], "W");
if(GEM->sav.Schema_installation[uz_channel]==5)sprintf(StriNg.string_val[5], "�");

sprintf(StriNg.string_val[6], "%-5d", GEM->sav.Time_open_window[uz_channel]);
sprintf(StriNg.string_val[7], "%-5d", GEM->sav.Time_close_window[uz_channel]);
sprintf(StriNg.string_val[8], "%-8.3f", GEM->sav.Offset_time[uz_channel]);
sprintf(StriNg.string_val[9], "%-8.3f", GEM->sav.Prizm_delay[uz_channel]);
sprintf(StriNg.string_val[10],"%-8.3f", GEM->sav.Gydrodynamic_koefSG[uz_channel]);
if(GEM->sav.Receive_polarity[uz_channel]==1)sprintf(StriNg.string_val[11],"���.");
if(GEM->sav.Receive_polarity[uz_channel]==2)sprintf(StriNg.string_val[11],"�����.");

sprintf(StriNg.string_val[12],"%-5d", GEM->sav.Offset_komparator[uz_channel]);
sprintf(StriNg.string_val[13],"%-5d", GEM->sav.Pulse_quantity[uz_channel]);


sprintf(StriNg.string_val[14],"%8lld", GEM->par.Status);

Strings(menu_column,numItems,"��������� �������");
}
if(GEM->sav.Language==2){ // ua
sprintf(StriNg.string[0], "�����. �i�����, ��"); // � ������ 28 ��������!
sprintf(StriNg.string[1], "���. ���., ����");
sprintf(StriNg.string[2], "����. ���. ���., ��");
sprintf(StriNg.string[3], "������� ���, ���");
sprintf(StriNg.string[4], "����. ���. ���, ��");
sprintf(StriNg.string[5], "����� ���. ���");  
sprintf(StriNg.string[6], "��� �i���. �i��. ���"); 
sprintf(StriNg.string[7], "��� ����. �i��. ���");      
sprintf(StriNg.string[8], "��� ��i�����, ���");         
sprintf(StriNg.string[9], "��� � �����i ���, ���");        
sprintf(StriNg.string[10],"����i�i��� Sg");
sprintf(StriNg.string[11], "������. ������");        
sprintf(StriNg.string[12],"��i�. ������. ��.,");
sprintf(StriNg.string[13],"�i�-�� i������i�, ��");
sprintf(StriNg.string[14],"������");


sprintf(StriNg.string_val[0], "%-8.3f", GEM->sav.Interrior_diameter[uz_channel]); 
sprintf(StriNg.string_val[1], "%-8.3f", GEM->sav.Angle_installation[uz_channel]);
sprintf(StriNg.string_val[2], "%-8.3f", GEM->sav.Length_acoustic_channel[uz_channel]);
if(GEM->sav.PEA_Frequency[uz_channel]==1)sprintf(StriNg.string_val[3], "1");
if(GEM->sav.PEA_Frequency[uz_channel]==2)sprintf(StriNg.string_val[3], "0.5");
if(GEM->sav.PEA_Frequency[uz_channel]==3)sprintf(StriNg.string_val[3], "0.25");
if(GEM->sav.PEA_Frequency[uz_channel]==4)sprintf(StriNg.string_val[3], "0.125");

sprintf(StriNg.string_val[4], "%-8.3f", GEM->sav.Pocket_installation[uz_channel]); 
if(GEM->sav.Schema_installation[uz_channel]==1)sprintf(StriNg.string_val[5], "Z");
if(GEM->sav.Schema_installation[uz_channel]==2)sprintf(StriNg.string_val[5], "V");
if(GEM->sav.Schema_installation[uz_channel]==3)sprintf(StriNg.string_val[5], "N");
if(GEM->sav.Schema_installation[uz_channel]==4)sprintf(StriNg.string_val[5], "W");
if(GEM->sav.Schema_installation[uz_channel]==5)sprintf(StriNg.string_val[5], "�");

sprintf(StriNg.string_val[6], "%-5d", GEM->sav.Time_open_window[uz_channel]);
sprintf(StriNg.string_val[7], "%-5d", GEM->sav.Time_close_window[uz_channel]);
sprintf(StriNg.string_val[8], "%-8.3f", GEM->sav.Offset_time[uz_channel]);
sprintf(StriNg.string_val[9], "%-8.3f", GEM->sav.Prizm_delay[uz_channel]);
sprintf(StriNg.string_val[10],"%-8.3f", GEM->sav.Gydrodynamic_koefSG[uz_channel]);
if(GEM->sav.Receive_polarity[uz_channel]==1)sprintf(StriNg.string_val[11],"���.");
if(GEM->sav.Receive_polarity[uz_channel]==2)sprintf(StriNg.string_val[11],"�����.");

sprintf(StriNg.string_val[12],"%-5d", GEM->sav.Offset_komparator[uz_channel]);
sprintf(StriNg.string_val[13],"%-5d", GEM->sav.Pulse_quantity[uz_channel]);


sprintf(StriNg.string_val[14],"%8lld", GEM->par.Status);

Strings(menu_column,numItems,"������������ �������");

} 

if(GEM->sav.Language==3){ // eng
sprintf(StriNg.string[0], "Int. diameter, mm"); // � ������ 28 ��������!
sprintf(StriNg.string[1], "Install angle, deg");
sprintf(StriNg.string[2], "Length acoust. ch, mm");
sprintf(StriNg.string[3], "Frequency PEA, ���");
sprintf(StriNg.string[4], "Install deep PEA, ��");
sprintf(StriNg.string[5], "Install scheme PEA");  
sprintf(StriNg.string[6], "Time open win. uS"); 
sprintf(StriNg.string[7], "Time close win. uS");      
sprintf(StriNg.string[8], "Time bias, uS");         
sprintf(StriNg.string[9], "Time in prism PEA, uS");        
sprintf(StriNg.string[10],"Coefficient Sg");
sprintf(StriNg.string[11], "Rec. polarity");        
sprintf(StriNg.string[12],"Bias comp. pcs");
sprintf(StriNg.string[13],"Pulse quant. pcs");
sprintf(StriNg.string[14],"Status");


sprintf(StriNg.string_val[0], "%-8.3f", GEM->sav.Interrior_diameter[uz_channel]); 
sprintf(StriNg.string_val[1], "%-8.3f", GEM->sav.Angle_installation[uz_channel]);
sprintf(StriNg.string_val[2], "%-8.3f", GEM->sav.Length_acoustic_channel[uz_channel]);
if(GEM->sav.PEA_Frequency[uz_channel]==1)sprintf(StriNg.string_val[3], "1");
if(GEM->sav.PEA_Frequency[uz_channel]==2)sprintf(StriNg.string_val[3], "0.5");
if(GEM->sav.PEA_Frequency[uz_channel]==3)sprintf(StriNg.string_val[3], "0.25");
if(GEM->sav.PEA_Frequency[uz_channel]==4)sprintf(StriNg.string_val[3], "0.125");

sprintf(StriNg.string_val[4], "%-8.3f", GEM->sav.Pocket_installation[uz_channel]); 
if(GEM->sav.Schema_installation[uz_channel]==1)sprintf(StriNg.string_val[5], "Z");
if(GEM->sav.Schema_installation[uz_channel]==2)sprintf(StriNg.string_val[5], "V");
if(GEM->sav.Schema_installation[uz_channel]==3)sprintf(StriNg.string_val[5], "N");
if(GEM->sav.Schema_installation[uz_channel]==4)sprintf(StriNg.string_val[5], "W");
if(GEM->sav.Schema_installation[uz_channel]==5)sprintf(StriNg.string_val[5], "�");

sprintf(StriNg.string_val[6], "%-5d", GEM->sav.Time_open_window[uz_channel]);
sprintf(StriNg.string_val[7], "%-5d", GEM->sav.Time_close_window[uz_channel]);
sprintf(StriNg.string_val[8], "%-8.3f", GEM->sav.Offset_time[uz_channel]);
sprintf(StriNg.string_val[9], "%-8.3f", GEM->sav.Prizm_delay[uz_channel]);
sprintf(StriNg.string_val[10],"%-8.3f", GEM->sav.Gydrodynamic_koefSG[uz_channel]);
if(GEM->sav.Receive_polarity[uz_channel]==1)sprintf(StriNg.string_val[11],"Low");
if(GEM->sav.Receive_polarity[uz_channel]==2)sprintf(StriNg.string_val[11],"High");

sprintf(StriNg.string_val[12],"%-5d", GEM->sav.Offset_komparator[uz_channel]);
sprintf(StriNg.string_val[13],"%-5d", GEM->sav.Pulse_quantity[uz_channel]);


sprintf(StriNg.string_val[14],"%8lld", GEM->par.Status);

Strings(menu_column,numItems,"Settings");

}

	
}
//#########$$$$$$$$$$$$$$###########################
void Draw_Work_Mode (uint8_t uz_channel, main_streamex *GEM){ // ������� �����
const uint8_t numItems = 14;

memset(&StriNg,0x00,sizeof(StriNg));

sprintf(StriNg.string[0], "������, �.���/���"); // � ������ 28 ��������!
sprintf(StriNg.string[1], "C���. ���., �/���");
sprintf(StriNg.string[2], "����. ����., ���");
sprintf(StriNg.string[3], "����� �� ���., ���");
sprintf(StriNg.string[4], "����� ��. ���., ���");
sprintf(StriNg.string[5], "����. �.��, �/���");  
sprintf(StriNg.string[6], "�����������, ����"); 
sprintf(StriNg.string[7], "��������, ���");      
sprintf(StriNg.string[8], "����. �����.�����");         
sprintf(StriNg.string[9], "����. �����.������");        
sprintf(StriNg.string[10],"����. �������, �");
sprintf(StriNg.string[11], "��� ������, ��");        
sprintf(StriNg.string[12],"�������, ��");
sprintf(StriNg.string[13],"������� ����., �");
sprintf(StriNg.string[14],"������");


sprintf(StriNg.string_val[0], "%-8.3f", GEM->par.Hour_consumption[uz_channel]); 
sprintf(StriNg.string_val[1], "%-8.3f", GEM->par.Flow_speed[uz_channel]);
sprintf(StriNg.string_val[2], "%-8.3f", GEM->par.Delta_time[uz_channel]);
sprintf(StriNg.string_val[3], "%-8.3f", GEM->par.UP_time[uz_channel]);
sprintf(StriNg.string_val[4], "%-8.3f", GEM->par.DOWN_time[uz_channel]); 
sprintf(StriNg.string_val[5], "%-8.3f", GEM->par.Ultrasonic_speed[uz_channel]);
sprintf(StriNg.string_val[6], "%-8.3f", GEM->par.Temperature[uz_channel]);
sprintf(StriNg.string_val[7], "%-8.3f", GEM->par.Preassure[uz_channel]);
sprintf(StriNg.string_val[8], "%-2d", GEM->par.Discrete_input[uz_channel]);
sprintf(StriNg.string_val[9], "%-2d", GEM->par.Discrete_output[uz_channel]);
sprintf(StriNg.string_val[10],"%-4.2f", GEM->par.Battery_Voltage);
sprintf(StriNg.string_val[11],"%-6.2f", GEM->par.Current_value[uz_channel]);
sprintf(StriNg.string_val[12],"%-6.2f", GEM->flags.Freqency_out[uz_channel]);
sprintf(StriNg.string_val[13],"%-6.2f", GEM->flags.External_Voltage);
sprintf(StriNg.string_val[14],"%-8lld", GEM->par.Status);

Strings(menu_column,numItems,"������� �����");

}
//#########$$$$$$$$$$$$$$###########################
void Draw_Main_Archives (uint8_t uz_channel, main_streamex *GEM){ // ������
uint8_t numItems = 17; // ������������ ������ � StriNg.string[]
memset(&StriNg,0x00,sizeof(StriNg));

sprintf(StriNg.string[0], "�������"); // � ������ 28 ��������!
sprintf(StriNg.string[1], "��������");
sprintf(StriNg.string[2], "��������");
sprintf(StriNg.string[3], "�������");
sprintf(StriNg.string[4], "��������� ��������");
sprintf(StriNg.string[5], "������������");
sprintf(StriNg.string[6], "����� ��������� %d:%d:%d", GEM->Capacite_str.hours[uz_channel],GEM->Capacite_str.mins[uz_channel], GEM->Capacite_str.seconds[uz_channel]);
sprintf(StriNg.string[7], "����� ������� %d:%d:%d", GEM->Capacite_str.hours_stop[uz_channel],GEM->Capacite_str.mins_stop[uz_channel], GEM->Capacite_str.seconds_stop[uz_channel]);
sprintf(StriNg.string[8], "����� ������� %d:%d:%d", GEM->Capacite_str.hours_revers[uz_channel],GEM->Capacite_str.mins_revers[uz_channel], GEM->Capacite_str.seconds_revers[uz_channel]);

sprintf(StriNg.string[9], "����. ���. ����. %f",  GEM->Capacite_str.Hour_cap[uz_channel]);
sprintf(StriNg.string[10], "����. ���. ����. %f", GEM->Capacite_str.Day_cap[uz_channel]);
sprintf(StriNg.string[11], "����. ���. ����. %lf", GEM->Capacite_str.Month_cap[uz_channel]);
sprintf(StriNg.string[12], "����. ���. ����. %lf", GEM->Capacite_str.Year_cap[uz_channel]);
sprintf(StriNg.string[13], "����. ����. %lf", GEM->Capacite_str.Accumulated_cap[uz_channel]);

sprintf(StriNg.string[14], "���. ���. ����. %f", GEM->Capacite_str.Day_cap_revers[uz_channel]);
sprintf(StriNg.string[15], "���. ���. ����. %lf", GEM->Capacite_str.Month_cap_revers[uz_channel]);
sprintf(StriNg.string[16], "���. ���. ����. %lf", GEM->Capacite_str.Year_cap_revers[uz_channel]);
sprintf(StriNg.string[17], "���. ����. %lf", GEM->Capacite_str.Accumulated_cap_revers[uz_channel]);

if(GEM->sav.Channel_quantity>1){
numItems = 24;
sprintf(StriNg.string[18], "����. ���. ����. %f", GEM->Capacite_str.Day_cap_combo);
sprintf(StriNg.string[19], "����. ���. ����. %lf", GEM->Capacite_str.Month_cap_combo);
sprintf(StriNg.string[20], "����. ���. ����. %lf", GEM->Capacite_str.Year_cap_combo);
sprintf(StriNg.string[21], "����. ����. %lf", GEM->Capacite_str.Accumulated_cap_combo);
	
sprintf(StriNg.string[22], "����.�. ���. ����. %f", GEM->Capacite_str.Day_cap_combo);
sprintf(StriNg.string[23], "����.�. ���. ����. %lf", GEM->Capacite_str.Month_cap_combo);
sprintf(StriNg.string[24], "����.�. ���. ����. %lf", GEM->Capacite_str.Year_cap_combo);
sprintf(StriNg.string[25], "����.�. ����. %lf", GEM->Capacite_str.Accumulated_cap_combo);
	
}
	
sprintf(StriNg.string_val[0], "%-5d", Indexes_str.Hour_index); // � ������ 28 ��������!
sprintf(StriNg.string_val[1], "%-5d", Indexes_str.Day_index);
sprintf(StriNg.string_val[2], "%-5d", Indexes_str.Month_index);
sprintf(StriNg.string_val[3], "%-5d", Indexes_str.Year_index);
sprintf(StriNg.string_val[4], "%-5d", Indexes_str.Event_index);
sprintf(StriNg.string_val[5], "%-5d", Indexes_str.Intervention_index);

Strings(menu_column,numItems, "������");

}
//#########$$$$$$$$$$$$$$###########################
void Draw_Main_Menu (uint8_t uz_channel, main_streamex *GEM){ // ������� ����
const uint8_t numItems = 5; // ������������ ������ � StriNg.string[]
memset(&StriNg,0x00,sizeof(StriNg));
if(GEM->sav.Language==1){ // 
memcpy(StriNg.string[0], "������", 28);
memcpy(StriNg.string[1], "������� �����", 28);
memcpy(StriNg.string[2], "������������", 28);
memcpy(StriNg.string[3], "��������� �������", 28);
memcpy(StriNg.string[4], "��������� ����", 28);	
memcpy(StriNg.string[5], "���������� � �������", 28);
Strings(menu_column,numItems, "����");
	
	
}
if(GEM->sav.Language==2){
memcpy(StriNg.string[0], "���i��", 28);
memcpy(StriNg.string[1], "�o����� �����", 28);
memcpy(StriNg.string[2], "����i�����i�", 28);
memcpy(StriNg.string[3], "������������ �������", 28);
memcpy(StriNg.string[4], "������������ �����i", 28);		
memcpy(StriNg.string[5], "I�������i� ��� ������", 28);
Strings(menu_column,numItems, "����");

}
if(GEM->sav.Language==3){
memcpy(StriNg.string[0], "Archives", 28);
memcpy(StriNg.string[1], "Work mode", 28);
memcpy(StriNg.string[2], "Configuration", 28);
memcpy(StriNg.string[3], "Settings", 28);
memcpy(StriNg.string[4], "Network Settings", 28);
memcpy(StriNg.string[5], "Device information", 28);
Strings(menu_column,numItems, "Menu");

}


}
//#########$$$$$$$$$$$$$$###########################
void Startup_screen (main_streamex *GEM, rt_clock *rt, const unsigned char* lut){ 
	char str[32];
		Paint_Clear(0xff);
////			Paint_Line(0, 0, 250, 28, BLACK);
////			sprintf(str,"%02d:%02d",GEM->par.Hour,GEM->par.Minutes);
////			Paint_String(5, 7, str, &Font12, WHITE, LEFT);
////			sprintf(str,"%02d/%02d/%04d",GEM->par.Day,GEM->par.Month,GEM->par.Year+2000);
////			Paint_String(60, 7, str, &Font12, WHITE, LEFT);

////			if(GEM->sav.Language==1){	// rus
////			Paint_String(55, 40, "��������", &Font24, BLACK, LEFT);
////			Paint_String(12, 70, "�������������� ����������", &Font12, BLACK, LEFT);
////			Paint_String(5, 90, "�������", &Font12, BLACK, LEFT);
////			}

////			if(GEM->sav.Language==2){	// ua
////			Paint_String(55, 40, "���i����", &Font24, BLACK, LEFT);
////			Paint_String(12, 70, "�������������� ��������i�", &Font12, BLACK, LEFT);
////			Paint_String(5, 90, "�i�������", &Font12, BLACK, LEFT);
////			}
////				if(GEM->sav.Language==3){	// eng
////			Paint_String(55, 40, "Streamex", &Font24, BLACK, LEFT);
////			Paint_String(12, 70, "ultrasonic flowmeter", &Font12, BLACK, LEFT);
////			Paint_String(5, 90, "counter", &Font12, BLACK, LEFT);
////			}
Paint_Image(0,0,(uint8_t *)Logo, BLACK);

	/*									Update screen
**********************************************************************************/	
		EPD_init(lut);
		if(lut==lut_full_update){EPD_Display(image);}else{EPD_DisplayPart(image);}
		EPD_sleep();

}
//#########$$$$$$$$$$$$$$###########################
void DrawScr(const unsigned char* lut){
	/*									Update screen
**********************************************************************************/	
		EPD_init(lut);
		if(lut==lut_full_update){EPD_Display(image);}else{EPD_DisplayPart(image);}
//		EPD_update();
		EPD_sleep();
		

}
//#########$$$$$$$$$$$$$$###########################
void ResetCursors(void){
key_code = 0;
menu_struct[0] = 1;
for(uint8_t i = 1;i<sizeof(menu_struct);i++){
menu_struct[i] = 0;
}
menu_column = 0;
max_column = 3;
IndexCnt = 0;

}
//#########$$$$$$$$$$$$$$###########################
void Menu_struct (uint8_t uz_channel, main_streamex *GEM, rt_clock *rt, const unsigned char* lut, uint8_t change){ // change = 1 - refresh display
static rt_clock RT;	

	
if((rt->mins!=RT.mins||GEM->Status_.init_complete==false||change==1)&&GEM->Status_.Display_Error==false){	
char str[32];

	
		Paint_Clear(0xff);
		Paint_Line(0, 0, 250, 28, BLACK);
		sprintf(str,"%02d:%02d",GEM->par.Hour,GEM->par.Minutes);
		Paint_String(5, 7, str, &Font12, WHITE, LEFT);
		//if(GEM->flags.sleep_enable==1){ Paint_String(5, MENU_TITLE_Y, "���", &Font12, BLACK, LEFT);}else{Paint_String(5, MENU_TITLE_Y, "���.", &Font12, BLACK, LEFT);}
		//if(GEM->Status[0].lowBat_flag==1){ Paint_String(5, MENU_TITLE_Y, "Bad", &Font12, BLACK, LEFT);}else{Paint_String(5, MENU_TITLE_Y, "God", &Font12, BLACK, LEFT);}
//char A[12];
//	sprintf(A,"%d", HAL_GetTick()/1000);
//Paint_String(5, MENU_TITLE_Y, A, &Font12, BLACK, LEFT);
		sprintf(str,"%02d/%02d/%04d",GEM->par.Day,GEM->par.Month,GEM->par.Year+2000);
		Paint_String(60, 7, str, &Font12, WHITE, LEFT);
		if(uz_channel==0){Paint_String(185, 7, "����� 1", &Font12, WHITE, LEFT);}else{Paint_String(185, 7, "����� 2", &Font12, WHITE, LEFT);} 
/*									Mein screen
**********************************************************************************/	
		if (menu_column == 0)
		{
			menu_struct [1] = 0;
			menu_struct [2] = 0;
		if(GEM->sav.Language==1){	// rus
		//	**********************************************************************************/	
		if(GEM->Status_.activation==false){Paint_String(125, MENU_TITLE_Y, "�� �����������!", &Font12, BLACK, CENTER);DrawScr(lut);return;}	
		Paint_String(125, MENU_TITLE_Y, "����� ������", &Font12, BLACK, CENTER);
		if(GEM->Status_.NO_Signal_Ultrasonic[uz_channel]==false&&GEM->Status_.Q_less_Qmin[uz_channel]==false&&GEM->Status_.Q_more_Qmax[uz_channel]==false){
		if(GEM->sav.Units[uz_channel]==0){ //m.kub
    sprintf(str,"%012.2lf �",GEM->Capacite_str.Accumulated_cap[uz_channel]);
		Paint_String(8, 60, str, &Font24, BLACK, LEFT);
		Paint_String(235, 60, "3", &Font12, BLACK, LEFT);
		}
		if(GEM->sav.Units[uz_channel]==2){ //liters
    sprintf(str,"%012.2lf �",GEM->Capacite_str.Accumulated_cap[uz_channel]);
		Paint_String(8, 60, str, &Font24, BLACK, LEFT);
		}
	 }
		if(GEM->Status_.NO_Signal_Ultrasonic[uz_channel]==true){
		sprintf(str,"��� ������� ��.!!!");
		Paint_String(12, 60, str, &Font24, BLACK, LEFT);
		}else{
		if(GEM->Status_.Q_less_Qmin[uz_channel]==true){
		sprintf(str,"Q<Q���.");
		Paint_String(60, 60, str, &Font24, BLACK, LEFT);
		}
		if(GEM->Status_.Q_more_Qmax[uz_channel]==true){
		sprintf(str,"Q>Q����.");
		Paint_String(60, 60, str, &Font24, BLACK, LEFT);
		}
	}
//**********************************************************************************/	

if(GEM->sav.Temperature_In[uz_channel]==1){
if(GEM->Status_.NO_Signal_Temp[uz_channel]==false&&GEM->Status_.T_less_Tmin[uz_channel]==false&&GEM->Status_.T_more_Tmax[uz_channel]==false){
    sprintf(str,"%6.2f",GEM->par.Temperature[uz_channel]);
		Paint_String(12, 95, str, &Font12, BLACK, LEFT);
    Paint_String(65, 87, "o", &Font12, BLACK, LEFT);
    Paint_String(75, 95, "C", &Font12, BLACK, LEFT);
}
if(GEM->Status_.NO_Signal_Temp[uz_channel]==true){
sprintf(str,"��� ����. ����.");
Paint_String(5, 95, str, &Font12, BLACK, LEFT);
}else{
if(GEM->Status_.T_less_Tmin[uz_channel]==true){
sprintf(str,"T<T���.");
Paint_String(12, 95, str, &Font12, BLACK, LEFT);
}
if(GEM->Status_.T_more_Tmax[uz_channel]==true){
sprintf(str,"T>T����.");
Paint_String(12, 95, str, &Font12, BLACK, LEFT);
}
}

}
//**********************************************************************************/	
if(GEM->sav.Preassure_In[uz_channel]==1){
if(GEM->Status_.NO_Signal_Preassure[uz_channel]==false&&GEM->Status_.P_less_Pmin[uz_channel]==false&&GEM->Status_.P_more_Pmax[uz_channel]==false){
sprintf(str,"%5.2f  ���",GEM->par.Preassure[uz_channel]);
Paint_String(150, 95, str, &Font12, BLACK, LEFT);
}
if(GEM->Status_.NO_Signal_Preassure[uz_channel]==true){
sprintf(str,"��� ����. ����.");
Paint_String(130, 95, str, &Font12, BLACK, LEFT);
}else{
if(GEM->Status_.P_less_Pmin[uz_channel]==true){
sprintf(str,"P<P���.");
Paint_String(150, 95, str, &Font12, BLACK, LEFT);
}
if(GEM->Status_.P_more_Pmax[uz_channel]==true){
sprintf(str,"P>P����.");
Paint_String(150, 95, str, &Font12, BLACK, LEFT);
}
}
}
//**********************************************************************************/	
}//lang
}
/*									Mein menu
**********************************************************************************/	
		if (menu_column == 1)
		{
		Draw_Main_Menu(uz_channel, GEM);
		}
/*									Other menu
**********************************************************************************/		
			if (menu_column == 2)
			{
				memcpy((void*)&Ind2, (void*)&Indexes_str, sizeof(Indexes_str));
				Ind2.Day_index=Indexes_str.Day_index-1;
				Ind2.Event_index=Indexes_str.Event_index-1;
				Ind2.Hour_index=Indexes_str.Hour_index-1;
				Ind2.Intervention_index=Indexes_str.Intervention_index-1;
				Ind2.Month_index=Indexes_str.Month_index-1;
				Ind2.Year_index=Indexes_str.Year_index-1;
				
				
				if(menu_struct[menu_column-1]==0){max_column = 3;Draw_Main_Archives(uz_channel, GEM);} // ������
								if(menu_struct[menu_column-1]==1){max_column = 2;Draw_Work_Mode(uz_channel, GEM);} // ������� �����
												if(menu_struct[menu_column-1]==2){max_column = 2;Draw_Conf_Mode(uz_channel, GEM);} // ������������
																if(menu_struct[menu_column-1]==3){max_column = 2;Draw_Setting_Mode(uz_channel, GEM);} // ��������� �������
																				if(menu_struct[menu_column-1]==4){max_column = 2;Draw_Network_Mode(uz_channel, GEM);} // ��������� ����
																						if(menu_struct[menu_column-1]==5){max_column = 2;Draw_Info(uz_channel, GEM);} // ���������� � �������
//			if (menu_struct[2]<=255 && menu_struct[2]>245) menu_struct[2]=0;
//			else if (menu_struct[2]>menu_max[menu_struct[1]]-1 && menu_struct[2]<245) menu_struct[2]=menu_max[menu_struct[1]]-1;		
//			if (menu_struct[2]<4) build_menu(0, 4);
//			if (menu_struct[2]>3) build_menu(4, menu_max[menu_struct[1]]-4);
			}
			
/*									Other menu22
**********************************************************************************/		
			if (menu_column == 3)
			{
			if(menu_struct[menu_column-1]==0){if(Indexes_str.Hour_index!=0)Draw_Main_Archives_Hourly(uz_channel, GEM);}
								if(menu_struct[menu_column-1]==1){if(Indexes_str.Day_index!=0)Draw_Main_Archives_Daily(uz_channel, GEM);}
												if(menu_struct[menu_column-1]==2){if(Indexes_str.Month_index!=0)Draw_Main_Archives_Monthly(uz_channel, GEM);}
																if(menu_struct[menu_column-1]==3){if(Indexes_str.Year_index!=0)Draw_Main_Archives_Yearly(uz_channel, GEM);}
																				if(menu_struct[menu_column-1]==4){if(Indexes_str.Event_index!=0)Draw_Main_Archives_Event(uz_channel, GEM);}
																							if(menu_struct[menu_column-1]==5){if(Indexes_str.Intervention_index!=0)Draw_Main_Archives_Intervention(uz_channel, GEM);}

			
			}
		DrawScr(lut);
		RT.mins=rt->mins;

	}	
			

}
//#########$$$$$$$$$$$$$$###########################


