#include "esc_state_machine.h"


void ESC_init(ESC_StateMachine_t *esc){
    esc->state = 0;
}

void ESC_reset(ESC_StateMachine_t *esc){
    esc->state = 0;    
}

void ESC_nextState(ESC_StateMachine_t *esc){
switch (esc->state)
{
case 0:
    /* code */
    HAL_GPIO_WritePin(esc->U_H_port, esc->U_H_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(esc->U_L_port, esc->U_L_pin, GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(esc->V_H_port, esc->V_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->V_L_port, esc->V_L_pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(esc->W_H_port, esc->W_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->W_L_port, esc->W_L_pin, GPIO_PIN_RESET);
    break;
case 1:
    /* code */
    HAL_GPIO_WritePin(esc->U_H_port, esc->U_H_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(esc->U_L_port, esc->U_L_pin, GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(esc->V_H_port, esc->V_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->V_L_port, esc->V_L_pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(esc->W_H_port, esc->W_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->W_L_port, esc->W_L_pin, GPIO_PIN_SET);
    break;
case 2:
    /* code */
    HAL_GPIO_WritePin(esc->U_H_port, esc->U_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->U_L_port, esc->U_L_pin, GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(esc->V_H_port, esc->V_H_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(esc->V_L_port, esc->V_L_pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(esc->W_H_port, esc->W_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->W_L_port, esc->W_L_pin, GPIO_PIN_SET);
    break;
case 3:
    /* code */
    HAL_GPIO_WritePin(esc->U_H_port, esc->U_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->U_L_port, esc->U_L_pin, GPIO_PIN_SET);
    
    HAL_GPIO_WritePin(esc->V_H_port, esc->V_H_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(esc->V_L_port, esc->V_L_pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(esc->W_H_port, esc->W_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->W_L_port, esc->W_L_pin, GPIO_PIN_RESET);
    break;
case 4:
    /* code */
    HAL_GPIO_WritePin(esc->U_H_port, esc->U_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->U_L_port, esc->U_L_pin, GPIO_PIN_SET);
    
    HAL_GPIO_WritePin(esc->V_H_port, esc->V_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->V_L_port, esc->V_L_pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(esc->W_H_port, esc->W_H_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(esc->W_L_port, esc->W_L_pin, GPIO_PIN_RESET);
    break;
case 5:
    /* code */
    HAL_GPIO_WritePin(esc->U_H_port, esc->U_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->U_L_port, esc->U_L_pin, GPIO_PIN_RESET);
    
    HAL_GPIO_WritePin(esc->V_H_port, esc->V_H_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(esc->V_L_port, esc->V_L_pin, GPIO_PIN_SET);

    HAL_GPIO_WritePin(esc->W_H_port, esc->W_H_pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(esc->W_L_port, esc->W_L_pin, GPIO_PIN_RESET);
    break;

default:
    break;
}

esc->state = (esc->state + 1) % 5;

}
