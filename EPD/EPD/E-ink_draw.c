/**
  ******************************************************************************
  * @lib    E-Ink Display draw lib
  * @author  Shylov Stanislav
  * @version V1.1.6
  * @date    02.11.2018 
  ******************************************************************************
	*/

#include "E-ink_draw.h"


unsigned char orient = HORIZONTAL;
unsigned char invet_color = 0;
unsigned char image[4000];

void Paint_Clear (unsigned char color)
{
	
	for (int i = 0; i < 4000; i++) 
			{
						image[i] = color;
        }

}

void Paint_Pixel(unsigned char x, unsigned char y, unsigned char colored) 
{
    int point_temp;
    if (orient == VERTICAL) {
        if( x >= EPD_WIDTH  || y >= EPD_HEIGHT) {
            return;
        }
        Paint_AbsolutePixel(x, y, colored);
    } 
	else if (orient == HORIZONTAL) {
        if( x >= EPD_HEIGHT ||  y >= EPD_WIDTH) {
          return;
        }
        point_temp = x;
        x = EPD_WIDTH - y;
        y = point_temp;

        Paint_AbsolutePixel(x, y, colored);
    } 
	
	

}


void Paint_AbsolutePixel(unsigned char x, unsigned char y, unsigned char colored) 
{
    if ( x >= EPD_WIDTH ||  y >= EPD_HEIGHT) 
		{
        return;
    }
    if (invet_color == 1) {
        if (colored == BLACK) {
            image[(x + y * EPD_WIDTH) / 8] |= 0x80 >> (x % 8);
        } else {
            image[(x + y * EPD_WIDTH) / 8] &= ~(0x80 >> (x % 8));
        }
    } else {
        if (colored == BLACK) {
            image[(x + y * EPD_WIDTH) / 8] &= ~(0x80 >> (x % 8));
        } else {
            image[(x + y * EPD_WIDTH) / 8] |= 0x80 >> (x % 8);
        }
    }
}

void Paint_HorLine(unsigned char x, unsigned char y, unsigned char line_width, unsigned char colored) 
{
    int i;
    for (i = x; i < x + line_width; i++) {
        Paint_Pixel(i, y, colored);
    }
}

void Paint_Line(unsigned char x, unsigned char y, unsigned char x_end, unsigned char y_end, unsigned char colored) 
{
    int i, j;
    for (i = x; i < x_end; i++) 
		{
			for (j = y; j < y_end; j++) 
			{
        Paint_Pixel(i, j, colored);
			}
       
    }
}


void Paint_VertLine(unsigned char x, unsigned char y, unsigned char line_height, unsigned char colored) 
{
    for (unsigned char i = y; i < y + line_height; i++) {
        Paint_Pixel(x, i, colored);
    }
}

void Paint_Char(unsigned char x, unsigned char y, char ascii_char, sFONT* font, unsigned char colored) 
{
    int i, j;
	//int char_info;
	if(ascii_char>127)
	{
		ascii_char = ascii_char - 65;
	}
	font->Width = font->info[(ascii_char - ' ')*2];

		
		const unsigned char* ptr = &font->table[font->info[(ascii_char - ' ')*2+1]];
	
	
    for (j = 0; j < font->Height; j++) {
        for (i = 0; i < font->Width; i++) {
            if (*ptr & (0x80 >> (i % 8))) {
                Paint_Pixel(x + i, y + j, colored);
            }
            if (i % 8 == 7) {
                ptr++;
            }
        }
        if (font->Width % 8 != 0) {
            ptr++;
        }
    }
}


void Paint_String(unsigned char x, unsigned char y, const char* text, sFONT* font, unsigned char colored, unsigned char alignment) 
{
	int string_length = 0;
	const char* a_text = text;
	while (*a_text != 0) 
		{
				if(*text>127)
					{
					font->Width = font->info[(*a_text - ' ' - 65)*2];
					}
				else
					{
						font->Width = font->info[(*a_text - ' ')*2];
					}
			string_length += font->Width+ font->Space;
			a_text++;
		}

    const char* p_text = text;
    int refcolumn;
    
	if (alignment == LEFT)
	{
		refcolumn = x;
	}
	if (alignment == CENTER)
	{
		refcolumn = x - (string_length/2);
	}	
	if (alignment == RIGHT)
	{
		refcolumn = x - string_length;
	}	
	
    /* Send the string character by character on EPD */
				while (*p_text != 0) {
        Paint_Char(refcolumn, y, *p_text, font, colored);
        refcolumn += font->Width + font->Space;
        p_text++;
    }
}
void Paint_Icon(unsigned char x, unsigned char y, const unsigned char* icon, unsigned char colored) 
{
    int i, j;	
	
    for (j = 0; j < Icon_height; j++) {
        for (i = 0; i < Icon_widht; i++) {
            if (*icon & (0x80 >> (i % 8))) {
                Paint_Pixel(x + i, y + j, colored);
            }
            if (i % 8 == 7) {
                icon++;
            }
        }
        if (Icon_widht % 8 != 0) {
            icon++;
        }
    }
}

void Paint_Image(unsigned char x_coord, unsigned char y_coord, unsigned char *buf, unsigned char color){
//width--; height--;
	uint16_t width, height;
	width=(buf[0]|buf[1])-1;
	height = (buf[2]|buf[3])-1;
uint16_t u=4;
	for(uint8_t y=y_coord;y<=y_coord+height;y=y+8){
for(uint8_t x=x_coord;x<=x_coord+width;x++){
	for(uint8_t e=0;e<=7;e++){
	if(buf[u]&(1<<e)){Paint_Pixel(x,y+e,color);}else{Paint_Pixel(x,y+e,~color);}
	}
u++;
}

	}
}


