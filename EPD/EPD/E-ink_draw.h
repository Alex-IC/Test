/**
  ******************************************************************************
  * @lib    E-Ink Display draw lib
  * @author  Shylov Stanislav
  * @version V1.1.6
  * @date    02.11.2018 
  ******************************************************************************
	*/
#include <stdint.h>
#include "fonts.h"
#include "E-ink_2.13.h"
#include "Icons.h"


//*******Color******************
#define BLACK						0x00
#define WHITE						0xFF
//*******Screen orientation*****
#define VERTICAL				0x00
#define HORIZONTAL			0x01

#define LEFT						0x00
#define CENTER					0x01
#define RIGHT						0x02

extern unsigned char orient;
extern unsigned char invet_color;
extern unsigned char image[4000];

void Paint_Clear (unsigned char color);
void Paint_Pixel(unsigned char x, unsigned char y, unsigned char colored);
void Paint_AbsolutePixel(unsigned char x, unsigned char y, unsigned char colored);
void Paint_HorLine(unsigned char x, unsigned char y, unsigned char line_width, unsigned char colored);
void Paint_Line(unsigned char x, unsigned char y, unsigned char x_end, unsigned char y_end, unsigned char colored);
void Paint_VertLine(unsigned char x, unsigned char y, unsigned char line_height, unsigned char colored);
void Paint_Char(unsigned char x, unsigned char y, char ascii_char, sFONT* font, unsigned char colored);
void Paint_String(unsigned char x, unsigned char y, const char* text, sFONT* font, unsigned char colored, unsigned char alignment);
void Paint_Icon(unsigned char x, unsigned char y, const unsigned char* icon, unsigned char colored);
void Paint_Image(unsigned char x_coord, unsigned char y_coord, unsigned char *buf, unsigned char color);


