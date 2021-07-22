/**
  ******************************************************************************
  * @lib    E-Ink Display 2.13" lib
  * @author  Shylov Stanislav
  * @version V1.0.7
  * @date    02.11.2018 
  ******************************************************************************
	*/



#include "main.h"
#include <stdint.h>



#define res0			HAL_GPIO_WritePin(RST_EPD_GPIO_Port, RST_EPD_Pin, GPIO_PIN_RESET);
#define res1			HAL_GPIO_WritePin(RST_EPD_GPIO_Port, RST_EPD_Pin, GPIO_PIN_SET);

#define dc0				HAL_GPIO_WritePin(DC_EPD_GPIO_Port, DC_EPD_Pin, GPIO_PIN_RESET);
#define dc1				HAL_GPIO_WritePin(DC_EPD_GPIO_Port, DC_EPD_Pin, GPIO_PIN_SET);

#define cs0				HAL_GPIO_WritePin(CS_EPD_GPIO_Port, CS_EPD_Pin, GPIO_PIN_RESET);
#define cs1				HAL_GPIO_WritePin(CS_EPD_GPIO_Port, CS_EPD_Pin, GPIO_PIN_SET);

#define busy 			HAL_GPIO_ReadPin(BUSY_EPD_GPIO_Port,BUSY_EPD_Pin)

// Display resolution
#define EPD_WIDTH       128
#define EPD_HEIGHT      250



// EPD2IN13B commands
// EPD2IN13 commands
#define DRIVER_OUTPUT_CONTROL                       0x01
#define GATE_DRIVING_VOLTAGE_CONTROL								0x03
#define BOOSTER_SOFT_START_CONTROL                  0x0C
#define SOURSE_DRIVING_VOLTAGE_CONTROL							0x04
#define GATE_SCAN_START_POSITION                    0x0F
#define DEEP_SLEEP_MODE                             0x10
#define DATA_ENTRY_MODE_SETTING                     0x11
#define SW_RESET                                    0x12
#define TEMPERATURE_SENSOR_CONTROL                  0x1A
#define MASTER_ACTIVATION                           0x20
#define DISPLAY_UPDATE_CONTROL_1                    0x21
#define DISPLAY_UPDATE_CONTROL_2                    0x22
#define WRITE_RAM                                   0x24
#define VCOM_SENSE																	0x28
#define VCOM_SENSE_DURATION													0x29
#define PROGRAM_VCOM_OTP														0x2A
#define WRITE_VCOM_REGISTER                         0x2C
#define PROGRAM_WS_OTP															0x30
#define WRITE_LUT_REGISTER                          0x32
#define PROGRAM_OTP_SELECTION												0x36
#define OTP_SELECTION_CONTROL												0x37
#define SET_DUMMY_LINE_PERIOD                       0x3A
#define SET_GATE_TIME                               0x3B
#define BORDER_WAVEFORM_CONTROL                     0x3C
#define SET_RAM_X_ADDRESS_START_END_POSITION        0x44
#define SET_RAM_Y_ADDRESS_START_END_POSITION        0x45
#define SET_RAM_X_ADDRESS_COUNTER                   0x4E
#define SET_RAM_Y_ADDRESS_COUNTER                   0x4F
#define TERMINATE_FRAME_READ_WRITE                  0xFF







extern const unsigned char lut_full_update[];
extern const unsigned char lut_partial_update[];


void EPD_init (const unsigned char* lut);
void EPD_command (unsigned char command);
void EPD_data (unsigned char data);
int8_t EPD_busy (void);
void EPD_reset(void);
void EPD_sleep(void);
void EPD_update (void);
void EPD_clear (unsigned char color);
void EPD_SetMemoryArea(int x_start, int y_start, int x_end, int y_end);
void EPD_SetMemoryPointer(int x, int y);
void EPD_SetFrameMemory(const unsigned char* image_buffer, int x, int y, int image_width, int image_height);
void EPD_Display(const unsigned char* image_buffer);
void EPD_DisplayPart(const unsigned char* image_buffer);

//static void EPD_SetLut(const unsigned char* lut);








