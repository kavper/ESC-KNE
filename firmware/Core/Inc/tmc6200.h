#ifndef TMC6200
#define TMC6200



#include "stm32c0xx_hal.h"

#define TMC6200_SPI &hspi1
//
// SPI WRAPPER
//



//#define TMC6200_FIELD_READ(tdef, address, mask, shift) \
	FIELD_GET(HAL_SPI_Receive(&hspi1, address | mask)
//#define TMC6200_FIELD_UPDATE(tdef, address, mask, shift, value) \
	(tmc6200_writeInt(tdef, address, FIELD_SET(tmc6200_readInt(tdef, address), mask, shift, value)))
	
	
	#define TMC6200_OTP_PROG       0x06
	#define TMC6200_OTP_READ       0x07
	#define TMC6200_FACTORY_CONF   0x08
	#define TMC6200_SHORT_CONF     0x09
	#define TMC6200_DRV_CONF       0x0A

uint64_t tmc6200_readInt(uint8_t address);

//
// FIELDS
//

#define TMC6200_DISABLE_MASK 				0x01 // GCONF //
#define TMC6200_DISABLE_SHIFT 				0 //
#define TMC6200_SINGLELINE_MASK 			0x02 // GCONF // 0: Individual, 1: Combined LS/HS control
#define TMC6200_SINGLELINE_SHIFT 			1 // 0: Individual, 1: Combined LS/HS control
#define TMC6200_FAULTDIRECT_MASK 			0x04 // GCONF //
#define TMC6200_FAULTDIRECT_SHIFT 			2 //
#define TMC6200_UNUSED_MASK 				0x08 // GCONF //
#define TMC6200_UNUSED_SHIFT 				3 //
#define TMC6200_AMPLIFICATION_MASK			0x30 // GCONF // Amplification of current amplifier 0: 5*, 1: 10*, 3:20*
#define TMC6200_AMPLIFICATION_SHIFT 		4 // Amplification of current amplifier 0: 5*, 1: 10*, 3:20*
#define TMC6200_CURRENT_ZERO_MASK 			0x40 // GCONF // Current amplifier off
#define TMC6200_CURRENT_ZERO_SHIFT 			6 // Current amplifier off
#define TMC6200_TEST_MODE_MASK 				0x80 // GCONF //
#define TMC6200_TEST_MODE_SHIFT 			7 //
#define TMC6200_RESET_MASK 					0x01 // GSTAT // reset
#define TMC6200_RESET_SHIFT 				0 // reset
#define TMC6200_DRV_OTPW_MASK 				0x02 // GSTAT // drv_otpw
#define TMC6200_DRV_OTPW_SHIFT 				1 // drv_otpw
#define TMC6200_DRV_OT_MASK 				0x04 // GSTAT // drv_ot
#define TMC6200_DRV_OT_SHIFT 				2 // drv_ot
#define TMC6200_UV_CP_MASK 					0x08 // GSTAT // uv_cp
#define TMC6200_UV_CP_SHIFT 				3 // uv_cp
#define TMC6200_SHORTDET_U_MASK 			0x10 // GSTAT // shortdet_u
#define TMC6200_SHORTDET_U_SHIFT 			4 // shortdet_u
#define TMC6200_S2VSU_MASK 					0x40 // GSTAT // short to VS U
#define TMC6200_S2VSU_SHIFT 				6 // short to VS U
#define TMC6200_SHORTDET_V_MASK 			0x100 // GSTAT // shortdet_v
#define TMC6200_SHORTDET_V_SHIFT 			8 // shortdet_v
#define TMC6200_S2GV_MASK 					0x200 // GSTAT // short to gnd V
#define TMC6200_S2GV_SHIFT 					9 // short to gnd V
#define TMC6200_S2VSV_MASK 					0x400 // GSTAT // short to VS V
#define TMC6200_S2VSV_SHIFT 				10 // short to VS V
#define TMC6200_SHORTDET_W_MASK 			0x1000 // GSTAT // shortdet_W
#define TMC6200_SHORTDET_W_SHIFT 			12 // shortdet_W
#define TMC6200_S2VSW_MASK 					0x4000 // GSTAT // short to VS W
#define TMC6200_S2VSW_SHIFT 				14 // short to VS W
#define TMC6200_UL_MASK 					0x01 // IOIN / OUTPUT // UL
#define TMC6200_UL_SHIFT 					0 // UL
#define TMC6200_UH_MASK 					0x02 // IOIN / OUTPUT // UH
#define TMC6200_UH_SHIFT 					1 // UH
#define TMC6200_VL_MASK 					0x04 // IOIN / OUTPUT // VL
#define TMC6200_VL_SHIFT 					2 // VL
#define TMC6200_VH_MASK 					0x08 // IOIN / OUTPUT // VH
#define TMC6200_VH_SHIFT 					3 // VH
#define TMC6200_WL_MASK 					0x10 // IOIN / OUTPUT // WH
#define TMC6200_WL_SHIFT 					4 // WH
#define TMC6200_WH_MASK 					0x20 // IOIN / OUTPUT // WH
#define TMC6200_WH_SHIFT 					5 // WH
#define TMC6200_DRV_EN_MASK 				0x40 // IOIN / OUTPUT // DRV_EN
#define TMC6200_DRV_EN_SHIFT 				6 // DRV_EN
#define TMC6200_OTPW_MASK 					0x100 // IOIN / OUTPUT // Overtemp prewarning
#define TMC6200_OTPW_SHIFT 					8 // Overtemp prewarning
#define TMC6200_OT136C_MASK 				0x200 // IOIN / OUTPUT // Overtemp 136�C
#define TMC6200_OT136C_SHIFT 				9 // Overtemp 136�C
#define TMC6200_OT143C_MASK 				0x400 // IOIN / OUTPUT // Overtemp 143�C
#define TMC6200_OT143C_SHIFT 				10 // Overtemp 143�C
#define TMC6200_OT150C_MASK 				0x800 // IOIN / OUTPUT // Overtemp 150�C
#define TMC6200_OT150C_SHIFT 				11 // Overtemp 150�C
#define TMC6200_VERSION_MASK 				0xFF000000 // IOIN / OUTPUT // VERSION: 0x10=first version of the IC; Identical numbers mean full digital compatibility.
#define TMC6200_VERSION_SHIFT 				24 // VERSION: 0x10=first version of the IC; Identical numbers mean full digital compatibility.
#define TMC6200_OTPBIT_MASK 				0x07 // OTP_PROG // Selection of OTP bit to be programmed to the selected byte location (n=0..7: programs bit n to a logic 1)
#define TMC6200_OTPBIT_SHIFT 				0 // Selection of OTP bit to be programmed to the selected byte location (n=0..7: programs bit n to a logic 1)
#define TMC6200_OTPBYTE_MASK 				0x30 // OTP_PROG // Set to 00
#define TMC6200_OTPBYTE_SHIFT 				4 // Set to 00
#define TMC6200_OTPMAGIC_MASK 				0xFF00 // OTP_PROG // Set  to  0xbd  to  enable  programming.  A  programming time of  minimum 10ms per bit is  recommended (check by reading OTP_READ).
#define TMC6200_OTPMAGIC_SHIFT 				8 // Set  to  0xbd  to  enable  programming.  A  programming time of  minimum 10ms per bit is  recommended (check by reading OTP_READ).
#define TMC6200_OTP_BBM_MASK 				0xC0 // OTP_READ // Reset default for BBM time, 0: 4 clocks, 1: 1 clocks, 2: 2 clocks, 3: 3 clocks
#define TMC6200_OTP_BBM_SHIFT 				6 // Reset default for BBM time, 0: 4 clocks, 1: 1 clocks, 2: 2 clocks, 3: 3 clocks
#define TMC6200_OTP_S2_LEVEL_MASK 			0x20 // OTP_READ // Reset default for Short detection Levels
#define TMC6200_OTP_S2_LEVEL_SHIFT 			5 // Reset default for Short detection Levels
#define TMC6200_OTP_FCLKTRIM_MASK			0x1F // OTP_READ // Reset default for FCLKTRIM 0: lowest frequency setting 31: highest frequency setting Attention: This value is pre-programmed by factory clock trimming to the default clock frequency of 24MHz and differs between individual ICs! It should not be altered.
#define TMC6200_OTP_FCLKTRIM_SHIFT 			0 // Reset default for FCLKTRIM 0: lowest frequency setting 31: highest frequency setting Attention: This value is pre-programmed by factory clock trimming to the default clock frequency of 24MHz and differs between individual ICs! It should not be altered.
#define TMC6200_FCLKTRIM_MASK 				0x1F // FACTORY_CONF // FCLKTRIM (Reset default: OTP) 31:  Lowest  to  highest  clock  frequency.  Check  at charge  pump  output.  The  frequency  span  is  not guaranteed,  but  it  is  tested,  that  tuning  to  24MHz internal  clock  is  possible.  The  devices  come  preset  to 24MHz clock frequency by OTP programming.
#define TMC6200_FCLKTRIM_SHIFT 				0 // FCLKTRIM (Reset default: OTP) 31:  Lowest  to  highest  clock  frequency.  Check  at charge  pump  output.  The  frequency  span  is  not guaranteed,  but  it  is  tested,  that  tuning  to  24MHz internal  clock  is  possible.  The  devices  come  preset  to 24MHz clock frequency by OTP programming.
#define TMC6200_S2VS_LEVEL_MASK 			0x0F // SHORT_CONF // Short to VS detector level (15= lowest sensitivity) (Reset Default: OTP 6 or 12)
#define TMC6200_S2VS_LEVEL_SHIFT 			0 // Short to VS detector level (15= lowest sensitivity) (Reset Default: OTP 6 or 12)
#define TMC6200_S2GND_LEVEL_MASK 			0xF00 // SHORT_CONF // Short to GND detector level (15= lowest sensitivity) (Reset Default: OTP 6 or 12)
#define TMC6200_S2GND_LEVEL_SHIFT 			8 // Short to GND detector level (15= lowest sensitivity) (Reset Default: OTP 6 or 12)
#define TMC6200_SHORTFILTER_MASK 			0x30000 // SHORT_CONF // Spike filtering bandwidth for short detection (0=lowest) (Reset Default = %01)
#define TMC6200_SHORTFILTER_SHIFT 			16 // Spike filtering bandwidth for short detection (0=lowest) (Reset Default = %01)
#define TMC6200_SHORTDELAY_MASK 			0x100000 // SHORT_CONF // Detector delay (0=750ns, 1=1500ns) (Reset Default = 0)
#define TMC6200_SHORTDELAY_SHIFT 			20 // Detector delay (0=750ns, 1=1500ns) (Reset Default = 0)
#define TMC6200_RETRY_MASK 					0x3000000 // SHORT_CONF // 0: Half bridge disabled after first short detection, 1..3: Half bridge re-enabled in next chopper cycles 1 time to 3 times. With retry, the short-counter is decreased once each 256 chopper cycles per coil, unless the upper limit has been reached. (Reset Default = %10)
#define TMC6200_RETRY_SHIFT 				24 // 0: Half bridge disabled after first short detection, 1..3: Half bridge re-enabled in next chopper cycles 1 time to 3 times. With retry, the short-counter is decreased once each 256 chopper cycles per coil, unless the upper limit has been reached. (Reset Default = %10)
#define TMC6200_PROTECT_PARALLEL_MASK 		0x10000000 // SHORT_CONF // 0: Only the detected half bridge driver becomes shut down upon final short detection, 1: All half bridge drivers become shut down upon final short detection (Reset Default = 1)
#define TMC6200_PROTECT_PARALLEL_SHIFT 		28 // 0: Only the detected half bridge driver becomes shut down upon final short detection, 1: All half bridge drivers become shut down upon final short detection (Reset Default = 1)
#define TMC6200_DISABLE_S2G_MASK 			0x20000000 // SHORT_CONF // Disable Short to GND protection
#define TMC6200_DISABLE_S2G_SHIFT 			29 // Disable Short to GND protection
#define TMC6200_DISABLE_S2VS_MASK 			0x40000000 // SHORT_CONF // Disable Short to VS protection
#define TMC6200_DISABLE_S2VS_SHIFT 			30 // Disable Short to VS protection
#define TMC6200_BBMCLKS_MASK 				0x0F // DRV_CONF // Digital BBM time in multiple of 1 clock. The longer setting rules (BBMTIME vs. BBMCLKS). (Reset Default: OTP 1 to 4)
#define TMC6200_BBMCLKS_SHIFT 				0 // Digital BBM time in multiple of 1 clock. The longer setting rules (BBMTIME vs. BBMCLKS). (Reset Default: OTP 1 to 4)
#define TMC6200_OTSELECT_MASK 				0x30000 // DRV_CONF // Selection of over temperature level. 00: 150�C, 01: 143�C, 10: 136�C, 11: 120�C (Reset Default = %00)
#define TMC6200_OTSELECT_SHIFT 				16 // Selection of over temperature level. 00: 150�C, 01: 143�C, 10: 136�C, 11: 120�C (Reset Default = %00)
#define TMC6200_DRVSTRENGTH_MASK 			0xC0000 // DRV_CONF // Selection of gate driver current. 00: weak, 01: weak+TC (medium at > 120�C), 10: medium, 11: strong (Reset Default = %10)
#define TMC6200_DRVSTRENGTH_SHIFT 			18 // Selection of gate driver current. 00: weak, 01: weak+TC (medium at > 120�C), 10: medium, 11: strong (Reset Default = %10)

//
// CONSTANTS	
//


#define TMC6200_MOTORS           1
#define TMC6200_WRITE_BIT        TMC_WRITE_BIT
#define TMC6200_ADDRESS_MASK     TMC_ADDRESS_MASK
#define TMC6200_MAX_VELOCITY     8388096
#define TMC6200_MAX_ACCELERATION u16_MAX

// constants helper

#define TMC_WRITE_BIT 0x80

#define TMC_ADDRESS_MASK 0x7F

#define TMC_DEFAULT_MOTOR 0

//#define TMC_DIRECTION_RIGHT TRUE
//#define TMC_DIRECTION_LEFT FALSE

#define TMC_REGISTER_COUNT 128 // Default register count


//
//	REGISTERS
//

#define TMC6200_GCONF          0x00
#define TMC6200_GSTAT          0x01
#define TMC6200_IOIN_OUTPUT    0x04
#define TMC6200_OTP_PROG       0x06
#define TMC6200_OTP_READ       0x07
#define TMC6200_FACTORY_CONF   0x08
#define TMC6200_SHORT_CONF     0x09
#define TMC6200_DRV_CONF       0x0A


//
// Used four SPI/standalone configuration
//

#define TMC6200_SINGLE_DRVSTREN_0_5A 	0x01
#define TMC6200_SINGLE_DRVSTREN_0_5_1A  0x02
#define TMC6200_SINGLE_DRVSTREN_1A  	0x03
#define TMC6200_SINGLE_DRVSTREN_1_5A	0x04

#define TMC6200_SINGLE_SENSEAMP_5 		0x05
#define TMC6200_SINGLE_SENSEAMP_10		0x06

#define TMC6200_SINGLE_INDIVIDUAL		0x07
#define TMC6200_SINGLE_POL_ENABLE 		0x08

#define TMC6200_MODE_SPI 				GPIO_PIN_SET
#define TMC6200_MODE_STANDALONE 		GPIO_PIN_RESET


// NOTE: Please make sure these pins are properly set to GPIO_Output in STM32CubeMX.

#define SPE_PORT						0// NOTE: SPE pin is currently hard-soldered to 3.3V and is not connected to STM32. 
#define SPE_PIN							0// TODO: Define port/pin when it's connected properly.

#define SPI_PORT						GPIOB

#define CS_IDRV0_PIN 					GPIO_PIN_6
#define SCK_IDRV1_PIN 					GPIO_PIN_3
#define SDI_MOSI_AMLPX10_PIN 			GPIO_PIN_5
#define SDO_MISO_SINGLE_PIN 			GPIO_PIN_4

void tmc6200_setGateControl(int control);
void tmc6200_setSenseAmplification(int amp);
void tmc6200_setDriverStrength(int strength);
void tmc6200_setMode(int mode);
void uint64_to_bits(uint64_t data, int bits_array[]);

typedef struct {
	int drv_strength;
	int sense_amp;
	int gate_ctrl;
} TMC6200_t;

typedef struct {
	int drv_strength;
	int sense_amp;
	int gate_ctrl;
} TMC6200_adv_zt;

TMC6200_t TMC6200_getDefaultConf();
void TMC6200_init(TMC6200_t *conf);

#endif
