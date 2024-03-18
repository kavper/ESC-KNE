#include "tmc6200.h"
#include <spi.h>

uint64_t tmc6200_readInt(uint8_t address)
{	

	// SPI data sent/received is 40 bit. That's why we should use uint64_t.

	uint64_t rxbuffer = {};
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

	HAL_SPI_TransmitReceive(TMC6200_SPI, address, rxbuffer, sizeof(address), 100);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
	return rxbuffer;
	
	

}

void tmc6200_write(int32_t address, int32_t value)
{

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);

	HAL_SPI_TransmitReceive(TMC6200_SPI, address | TMC6200_WRITE_BIT | value, NULL, sizeof(value), 100);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);

}


// This allows to convert uint64_t to individual bit array. We'll be using it to check individual bits later in tmc6200 register read.
// Note that first 8 bits (byte 1 of 5) is not the actual register content, but a 'status'
void uint64_to_bits(uint64_t data, int bits_array[]) {
    for (int i = 63; i >= 0; i--) {
        bits_array[i] = (data >> i) & 1;
    }
}


// Set main control mode
// Note: it's not ready to use as SPE_PORT & SPE_PIN are not defined as they're not connected to MCU.
void tmc6200_setMode(int mode) {
			HAL_GPIO_WritePin(SPE_PORT, SPE_PIN, mode);
	}

/* 
 * Functions used in standalone (non-SPI) mode
 * Pins used in this mode are SPI pins
 * CS  >> IDRV0
 * SCK >> IDRV1
 * SDI >> AMPLx10
 * SDO >> SINGLE
 * 
 * NOTE: Please make sure these pins are properly set to GPIO_Output in STM32CubeMX.
 */


// Sets max driver current in standalone mode
void tmc6200_setDriverStrength(int strength) {
	switch(strength){
		case(TMC6200_SINGLE_DRVSTREN_0_5A):
			HAL_GPIO_WritePin(SPI_PORT, SCK_IDRV1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SPI_PORT, CS_IDRV0_PIN, GPIO_PIN_RESET);
			break;
		case(TMC6200_SINGLE_DRVSTREN_0_5_1A):
			HAL_GPIO_WritePin(SPI_PORT, SCK_IDRV1_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(SPI_PORT, CS_IDRV0_PIN, GPIO_PIN_SET);
			break;
		case(TMC6200_SINGLE_DRVSTREN_1A):
			HAL_GPIO_WritePin(SPI_PORT, SCK_IDRV1_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SPI_PORT, CS_IDRV0_PIN, GPIO_PIN_RESET);
			break;
		case(TMC6200_SINGLE_DRVSTREN_1_5A):
			HAL_GPIO_WritePin(SPI_PORT, SCK_IDRV1_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(SPI_PORT, CS_IDRV0_PIN, GPIO_PIN_SET);
			break;
		
	}
}

// Sets sense amplification in standalone mode
void tmc6200_setSenseAmplification(int amp) {
	switch(amp){
		case(TMC6200_SINGLE_SENSEAMP_5):
			HAL_GPIO_WritePin(SPI_PORT, SDI_MOSI_AMLPX10_PIN, GPIO_PIN_RESET);
			break;
		case(TMC6200_SINGLE_SENSEAMP_10):
			HAL_GPIO_WritePin(SPI_PORT, SDI_MOSI_AMLPX10_PIN, GPIO_PIN_SET);
			break;
	}
}
// Switches between individual gate control and polarity/enable control in standalone mode
void tmc6200_setGateControl(int control) {
	switch(control){
		case(TMC6200_SINGLE_INDIVIDUAL):
			HAL_GPIO_WritePin(SPI_PORT, SDO_MISO_SINGLE_PIN, GPIO_PIN_RESET);
			break;
		case(TMC6200_SINGLE_POL_ENABLE):
			HAL_GPIO_WritePin(SPI_PORT, SDO_MISO_SINGLE_PIN, GPIO_PIN_SET);
			break;
	}
}

TMC6200_t TMC6200_getDefaultConf() {
	TMC6200_t ret;
	ret.drv_strength = TMC6200_SINGLE_DRVSTREN_0_5A;
	ret.sense_amp = TMC6200_SINGLE_SENSEAMP_5;
	ret.gate_ctrl = TMC6200_SINGLE_INDIVIDUAL;

	return ret;

}

void TMC6200_init(TMC6200_t *conf) {
	tmc6200_setDriverStrength(conf->drv_strength);
	tmc6200_setSenseAmplification(conf->sense_amp);
	tmc6200_setGateControl(conf->gate_ctrl);
}

