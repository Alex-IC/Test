


#include "main.h"
#include "E-ink_draw.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>

#define KEY_PORT				NULL//GPIOB
#define KEY_UP					NULL//GPIO_PIN_6
#define KEY_DOWN				NULL//GPIO_PIN_4
#define KEY_LEFT				NULL//GPIO_PIN_3
#define KEY_RIGHT				NULL//GPIO_PIN_8
#define KEY_ENTER				NULL//GPIO_PIN_5
#define KEY_CANCEL			NULL//GPIO_PIN_7

#define MENU_TITLE_Y		27
#define MENU_X					5

typedef struct{
 char string[28][36];
 char string_val[28][12];	
}strPtr;

extern int key_code;

void keys(main_streamex *GEM, rt_clock *rt, uint8_t change);
void build_menu(unsigned char first_string, unsigned char strings);
void Menu_struct (uint8_t uz_channel, main_streamex *GEM, rt_clock *rt, const unsigned char* lut, uint8_t change);
void Startup_screen (main_streamex *GEM, rt_clock *rt, const unsigned char* lut);
void ResetCursors(void);

