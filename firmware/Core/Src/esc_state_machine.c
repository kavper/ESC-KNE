#include "esc_state_machine.h"

static uint8_t state = 0;

void ESC_reset(){
    state = 0;
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
