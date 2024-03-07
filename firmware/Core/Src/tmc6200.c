#include "tmc6200.h"
#include <spi.h>


int32_t tmc6200_readInt(uint8_t motor, uint8_t address)
{	
	int32_t rxbuffer;
	
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
