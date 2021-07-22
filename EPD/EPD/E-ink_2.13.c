/**
  ******************************************************************************
  * @lib    E-Ink Display 2.13" lib
  * @author  Shylov Stanislav
  * @version V1.0.7
  * @date    02.11.2018 
  ******************************************************************************
	*/


#include "E-ink_2.13.h"


extern SPI_HandleTypeDef hspi2;

extern void update (void);
# define Display_Busy_Timeout 3000

////const unsigned char lut_full_update[] =
////{
////    0x22, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x11, 
////    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
////    0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 0x1E, 
////    0x01, 0x00, 0x00, 0x00, 0x00, 0x00
////};

////const unsigned char lut_partial_update[] =
////{
////    0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
////    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
////    0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
////    0x00, 0x00, 0x00, 0x00, 0x00, 0x00
////};
const unsigned char lut_full_update[]= {
    0x80,0x60,0x40,0x00,0x00,0x00,0x00,             //LUT0: BB:     VS 0 ~7
    0x10,0x60,0x20,0x00,0x00,0x00,0x00,             //LUT1: BW:     VS 0 ~7
    0x80,0x60,0x40,0x00,0x00,0x00,0x00,             //LUT2: WB:     VS 0 ~7
    0x10,0x60,0x20,0x00,0x00,0x00,0x00,             //LUT3: WW:     VS 0 ~7
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT4: VCOM:   VS 0 ~7

    0x03,0x03,0x00,0x00,0x02,                       // TP0 A~D RP0
    0x09,0x09,0x00,0x00,0x02,                       // TP1 A~D RP1
    0x03,0x03,0x00,0x00,0x02,                       // TP2 A~D RP2
    0x00,0x00,0x00,0x00,0x00,                       // TP3 A~D RP3
    0x00,0x00,0x00,0x00,0x00,                       // TP4 A~D RP4
    0x00,0x00,0x00,0x00,0x00,                       // TP5 A~D RP5
    0x00,0x00,0x00,0x00,0x00,                       // TP6 A~D RP6

    0x15,0x41,0xA8,0x32,0x30,0x0A,
};

const unsigned char lut_partial_update[]= { //20 bytes
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT0: BB:     VS 0 ~7
    0x80,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT1: BW:     VS 0 ~7
    0x40,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT2: WB:     VS 0 ~7
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT3: WW:     VS 0 ~7
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,             //LUT4: VCOM:   VS 0 ~7

    0x0A,0x00,0x00,0x00,0x00,                       // TP0 A~D RP0
    0x00,0x00,0x00,0x00,0x00,                       // TP1 A~D RP1
    0x00,0x00,0x00,0x00,0x00,                       // TP2 A~D RP2
    0x00,0x00,0x00,0x00,0x00,                       // TP3 A~D RP3
    0x00,0x00,0x00,0x00,0x00,                       // TP4 A~D RP4
    0x00,0x00,0x00,0x00,0x00,                       // TP5 A~D RP5
    0x00,0x00,0x00,0x00,0x00,                       // TP6 A~D RP6

    0x15,0x41,0xA8,0x32,0x30,0x0A,
};

/*
**************************************************************************************
*								Command function
*
*/
//Init 
void EPD_init (const unsigned char* lut)
{	

uint16_t count;
    EPD_reset();

    if(lut == 	lut_full_update) {
        EPD_busy();
        EPD_command(0x12); // soft reset
        EPD_busy();

        EPD_command(0x74); //set analog block control
        EPD_data(0x54);
        EPD_command(0x7E); //set digital block control
        EPD_data(0x3B);

        EPD_command(0x01); //Driver output control
        EPD_data(0xF9);
        EPD_data(0x00);
        EPD_data(0x00);

        EPD_command(0x11); //data entry mode
        EPD_data(0x01);

        EPD_command(0x44); //set Ram-X address start/end position
        EPD_data(0x00);
        EPD_data(0x0F);    //0x0C-->(15+1)*8=128

        EPD_command(0x45); //set Ram-Y address start/end position
        EPD_data(0xF9);   //0xF9-->(249+1)=250
        EPD_data(0x00);
        EPD_data(0x00);
        EPD_data(0x00);
        
        EPD_command(0x3C); //BorderWavefrom
        EPD_data(0x03);

        EPD_command(0x2C);     //VCOM Voltage
        EPD_data(0x55);    //

        EPD_command(0x03);
        EPD_data(lut_full_update[70]);

        EPD_command(0x04); //
        EPD_data(lut_full_update[71]);
        EPD_data(lut_full_update[72]);
        EPD_data(lut_full_update[73]);

        EPD_command(0x3A);     //Dummy Line
        EPD_data(lut_full_update[74]);
        EPD_command(0x3B);     //Gate time
        EPD_data(lut_full_update[75]);

        EPD_command(0x32);
        for(count = 0; count < 70; count++)
            EPD_data(lut_full_update[count]);

        EPD_command(0x4E);   // set RAM x address count to 0;
        EPD_data(0x00);
        EPD_command(0x4F);   // set RAM y address count to 0X127;
        EPD_data(0xF9);
        EPD_data(0x00);
       if(EPD_busy()==-1)return;
    } else {
        EPD_command(0x2C);     //VCOM Voltage
        EPD_data(0x26);

               if(EPD_busy()==-1)return;


        EPD_command(0x32);
        for(count = 0; count < 70; count++)
            EPD_data(lut_partial_update[count]);

        EPD_command(0x37);
        EPD_data(0x00);
        EPD_data(0x00);
        EPD_data(0x00);
        EPD_data(0x00);
        EPD_data(0x40);
        EPD_data(0x00);
        EPD_data(0x00);

        EPD_command(0x22);
        EPD_data(0xC0);
        EPD_command(0x20);
               if(EPD_busy()==-1)return;


        EPD_command(0x3C); //BorderWavefrom
        EPD_data(0x01);
    }
	
	
}

static void EPD_TurnOnDisplay(void)
{
    EPD_command(0x22);
    EPD_data(0xC7);
    EPD_command(0x20);
    if(EPD_busy()==-1)return;

}

//
//static void EPD_SetLut(const unsigned char* lut) 
//{
//  EPD_command(WRITE_LUT_REGISTER);
//  /* the length of look-up table is 30 bytes */
//  for (int i = 0; i < 70; i++) {
//    EPD_data(lut[i]);
//  } 
//}
//Send command 
void EPD_command (unsigned char command)
{
	dc0;
	cs0;
	HAL_SPI_Transmit(&hspi2, &command, 1, 0x10);
	cs1;
}
//Send data
void EPD_data (unsigned char data)
{
	dc1;
	cs0;
	HAL_SPI_Transmit(&hspi2, &data, 1, 0x10);
	cs1;
}
//Wait busy display
int8_t EPD_busy (void)
{
uint32_t time = HAL_GetTick();
	while (busy==GPIO_PIN_SET)
	{
		if((HAL_GetTick()-time)>Display_Busy_Timeout) { return -1;}

	}
	return 0;
}
//Reset display
void EPD_reset(void)
{
	uint32_t a,b;
	a=b=HAL_GetTick();
	res0;
	while((b-a)<200){
	b=HAL_GetTick();
	}
	
	res1;
	a=b=HAL_GetTick();
	while((b-a)<200){
	b=HAL_GetTick();
	}	
}
//Sleep mode
void EPD_sleep(void) 
	{
EPD_command(0x22); //POWER OFF
    EPD_data(0xC3);
    EPD_command(0x20);

    EPD_command(0x10); //enter deep sleep
    EPD_data(0x01);
    //HAL_Delay(100);
}
//Update display
void EPD_update (void)
{
	  EPD_command(DISPLAY_UPDATE_CONTROL_2);
    EPD_data(0xC7);		
    EPD_command(MASTER_ACTIVATION);
           if(EPD_busy()==-1)return;

}
//Clear display
void EPD_clear (unsigned char color)
{
//    EPD_SetMemoryArea(0, 0, EPD_WIDTH - 1, EPD_HEIGHT - 1);
//    /* set the frame memory line by line */
//    for (int j = 0; j < EPD_HEIGHT; j++) {
//        EPD_SetMemoryPointer(0, j);
//        EPD_command(WRITE_RAM);
//        for (int i = 0; i < EPD_WIDTH / 8; i++) {
//        EPD_data(color);
//        }
//    }
//    EPD_busy();
	uint16_t Width, Height;
    Width = (EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1);
    Height = EPD_HEIGHT;
    EPD_command(0x24);
    for (uint16_t j = 0; j < Height; j++) {
        for (uint16_t  i = 0; i < Width; i++) {
            EPD_data(color);
        }
    }
    EPD_TurnOnDisplay();

}

//void EPD_SetMemoryArea(int x_start, int y_start, int x_end, int y_end) 
//{
//    EPD_command(SET_RAM_X_ADDRESS_START_END_POSITION);
//    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
//    EPD_data((x_start >> 3) & 0xFF);	
//    EPD_data((x_end >> 3) & 0xFF);
//    EPD_command(SET_RAM_Y_ADDRESS_START_END_POSITION);	
//    EPD_data(y_start & 0xFF);	
//    EPD_data((y_start >> 8) & 0xFF);
//    EPD_data(y_end & 0xFF);
//    EPD_data((y_end >> 8) & 0xFF);


//}

//----------------------------------------------------------//
void EPD_Display(const unsigned char* image_buffer)
{
    unsigned char Width, Height;
    Width = (EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1);
    Height = EPD_HEIGHT;

    EPD_command(0x24);
    for (unsigned char j = Height; j > 0; j--) {
        for (unsigned char i = 0; i < Width; i++) {
            EPD_data(image_buffer[i + j * Width]);
        }
    }
    EPD_TurnOnDisplay();
}
//----------------------------------------------------------//
void EPD_DisplayPart(const unsigned char* image_buffer)
{
    unsigned char Width, Height;
    Width = (EPD_WIDTH % 8 == 0)? (EPD_WIDTH / 8 ): (EPD_WIDTH / 8 + 1);
    Height = EPD_HEIGHT;
    EPD_command(0x24);
    for (unsigned char j = Height; j > 0; j--) {
        for (unsigned char i = 0; i < Width; i++) {
            EPD_data(image_buffer[i + j * Width]);
        }
    }
    
    EPD_command(0x26);   //Write Black and White image to RAM
    for (unsigned char j = Height; j > 0; j--) {
        for (unsigned char i = 0; i < Width; i++) {
            EPD_data(~image_buffer[i + j * Width]);
        }
    }
    EPD_TurnOnDisplay();
}
//----------------------------------------------------------//



//void EPD_SetMemoryPointer(int x, int y) 
//{
//    EPD_command(SET_RAM_X_ADDRESS_COUNTER);
//    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
//    EPD_data((x >> 3) & 0xFF);
//    EPD_command(SET_RAM_Y_ADDRESS_COUNTER);
//    EPD_data(y & 0xFF);	
//    EPD_data((y >> 8) & 0xFF);
//		EPD_busy();

//}

//void EPD_SetFrameMemory(const unsigned char* image_buffer, int x, int y, int image_width, int image_height)
//{
//   int x_end;
//    int y_end;

//    if (
//        image_buffer == NULL ||
//        x < 0 || image_width < 0 ||
//        y < 0 || image_height < 0
//    ) {
//        return;
//    }
//    /* x point must be the multiple of 8 or the last 3 bits will be ignored */
//    x &= 0xF8;
//    image_width &= 0xF8;
//    if (x + image_width >= EPD_WIDTH) {
//        x_end = EPD_WIDTH - 1;
//    } else {
//        x_end = x + image_width - 1;
//    }
//    if (y + image_height >= EPD_HEIGHT) {
//        y_end = EPD_HEIGHT - 1;
//    } else {
//        y_end = y + image_height - 1;
//    }
//    EPD_SetMemoryArea(x, y, x_end, y_end);
//    /* send the image data */
//    for (int j = y; j <= y_end; j++) {
//        EPD_SetMemoryPointer(x, j);
//        EPD_command(WRITE_RAM);
//        for (int i = x / 8; i <= x_end / 8; i++) {
//            EPD_data(image_buffer[(i - x / 8) + (j - y) * (image_width / 8)]);
//        }
//    }
// 
//}

