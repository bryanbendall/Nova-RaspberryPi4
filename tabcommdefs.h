#ifndef TABCOMMDEFS_H
#define TABCOMMDEFS_H

//States
#define OFF									0
#define ON									1

//Pin Control
#define DISABLE								0
#define ENABLE								1
#define AUTO_CONTROL						2
#define REQUEST_PIN_STATUS					3
#define STOP_PIN_MONITOR					4

#define TAB_WIPER_STATE_OFF					0
#define TAB_WIPER_STATE_DELAY				1
#define TAB_WIPER_STATE_LOW					2
#define TAB_WIPER_STATE_HIGH				3
#define TAB_WIPER_STATE_AUTO				4

//Commands

//Climate Screen
#define TAB_CLIMATE_AUTO					0x41
#define TAB_CLIMATE_POWER					0x42
#define TAB_CLIMATE_AC						0x43
#define TAB_CLIMATE_TEMP					0x44
#define TAB_CLIMATE_LEVEL					0x45
#define TAB_CLIMATE_FAN						0x46
#define TAB_CLIMATE_DRIVERS_HEATED_SEAT		0x47
#define TAB_CLIMATE_PASS_HEADTE_SEAT		0x48

//Guages Screen
#define TAB_GUAGE_FUEL_LEVEL				0x49
#define TAB_GUAGE_WATER_LEVEL				0x4A

//Headlight Screen
#define TAB_LIGHT_AUTO						0x4B
#define TAB_LIGHT_OFF						0x4C
#define TAB_LIGHT_RUNNING					0x4D
#define TAB_LIGHT_PARKING					0x4E
#define TAB_LIGHT_LOW_BEAM					0x4F
#define TAB_LIGHT_HIGH_BEAM					0x50
#define TAB_LIGHT_SENSITIVITY				0x51
#define TAB_LIGHT_INTERIOR					0x52

//Windows Screen
#define TAB_WINDOW_DRIVER_UP				0x53
#define TAB_WINDOW_DRIVER_DOWN				0x54
#define TAB_WINDOW_DRIVER_UP_EXP			0x55
#define TAB_WINDOW_DRIVER_DOWN_EXP			0x56
#define TAB_WINDOW_PASS_UP					0x57
#define TAB_WINDOW_PASS_DOWN				0x58
#define TAB_WINDOW_PASS_UP_EXP				0x59
#define TAB_WINDOW_PASS_DOWN_EXP			0x5A

//Wiper Screen
#define TAB_WIPER_SQUIRTER					0x5B
#define TAB_WIPER_MODE						0x5C
#define TAB_WIPER_DELAY						0x5D

//System Controls
#define TAB_SCREEN_CONTROL					0x5E
#define TAB_UNLOCK							0x5F

#define TAB_SCREEN_OFF						0X00
#define TAB_SCREEN_ON						0X01
#define TAB_SCREEN_LOCK						0X02

#define TAB_OVER_CURRENT					0x60
#define TAB_PIN_STATUS						0x61
#define TAB_REQUEST_CHARGE                  0x62

#endif // TABCOMMDEFS_H
