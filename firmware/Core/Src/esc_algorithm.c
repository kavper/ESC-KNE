#include "esc_algorithm.h"

static uint8_t state = 0;


HAL_StatusTypeDef ESC_init(ESC_stateMachine_t *esc){
    // return HAL_ADCEx_Calibration_Start(esc->hadc);
    return HAL_OK;
}

void ESC_reset(){
    state = 0;
}

/**
 * @brief This is slow ESC_measureVoltage implementation
 *        for testing purposes only.
 *        
 *        TODO: use DMA
 * 
 * @note This function can only be used in sequence and discontinuous
 *       ADC conversion mode only. Chanel ranks: (Rank 1: CH2, 
 *       Rank 2: CH3, RANK 3: CH4)
 * 
 * @param esc 
 */
void ESC_measureVoltage(ESC_stateMachine_t *esc){
    HAL_ADC_Start(esc->hadc);
    HAL_ADC_PollForConversion(esc->hadc, HAL_MAX_DELAY);
    esc->volt_u = (3.3f * HAL_ADC_GetValue(esc->hadc)) / MAX_ADC_VALUE;

    HAL_ADC_Start(esc->hadc);
    HAL_ADC_PollForConversion(esc->hadc, HAL_MAX_DELAY);
    esc->volt_v = (3.3f * HAL_ADC_GetValue(esc->hadc)) / MAX_ADC_VALUE;
    
    HAL_ADC_Start(esc->hadc);
    HAL_ADC_PollForConversion(esc->hadc, HAL_MAX_DELAY);
    esc->volt_w = (3.3f * HAL_ADC_GetValue(esc->hadc)) / MAX_ADC_VALUE;

    HAL_ADC_Stop(esc->hadc);
}

void ESC_nextState(){
switch (state)
{
case 0:
    /* code */
    HAL_GPIO_WritePin(U_H_GPIO_Port, U_H_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(U_L_GPIO_Port, U_L_Pin, GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(V_H_GPIO_Port, V_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(V_L_GPIO_Port, V_L_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(W_H_GPIO_Port, W_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(W_L_GPIO_Port, W_L_Pin, GPIO_PIN_RESET);
    break;
case 1:
    /* code */
    HAL_GPIO_WritePin(U_H_GPIO_Port, U_H_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(U_L_GPIO_Port, U_L_Pin, GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(V_H_GPIO_Port, V_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(V_L_GPIO_Port, V_L_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(W_H_GPIO_Port, W_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(W_L_GPIO_Port, W_L_Pin, GPIO_PIN_SET);
    break;
case 2:
    /* code */
    HAL_GPIO_WritePin(U_H_GPIO_Port, U_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(U_L_GPIO_Port, U_L_Pin, GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(V_H_GPIO_Port, V_H_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(V_L_GPIO_Port, V_L_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(W_H_GPIO_Port, W_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(W_L_GPIO_Port, W_L_Pin, GPIO_PIN_SET);
    break;
case 3:
    /* code */
    HAL_GPIO_WritePin(U_H_GPIO_Port, U_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(U_L_GPIO_Port, U_L_Pin, GPIO_PIN_SET);
    
    HAL_GPIO_WritePin(V_H_GPIO_Port, V_H_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(V_L_GPIO_Port, V_L_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(W_H_GPIO_Port, W_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(W_L_GPIO_Port, W_L_Pin, GPIO_PIN_RESET);
    break;
case 4:
    /* code */
    HAL_GPIO_WritePin(U_H_GPIO_Port, U_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(U_L_GPIO_Port, U_L_Pin, GPIO_PIN_SET);
    
    HAL_GPIO_WritePin(V_H_GPIO_Port, V_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(V_L_GPIO_Port, V_L_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(W_H_GPIO_Port, W_H_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(W_L_GPIO_Port, W_L_Pin, GPIO_PIN_RESET);
    break;
case 5:
    /* code */
    HAL_GPIO_WritePin(U_H_GPIO_Port, U_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(U_L_GPIO_Port, U_L_Pin, GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(V_H_GPIO_Port, V_H_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(V_L_GPIO_Port, V_L_Pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(W_H_GPIO_Port, W_H_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(W_L_GPIO_Port, W_L_Pin, GPIO_PIN_RESET);
    break;

default:
    break;
}

state = (state + 1) % 6;

}
