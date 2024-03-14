#if !defined(ESC_STATE_MACHINE)
#define ESC_STATE_MACHINE
#include "stm32c031xx.h"
#include "main.h"

typedef struct ESC_StateMachine_t
{
    uint32_t U_H_pin;
    GPIO_TypeDef *U_H_port;

    uint32_t U_L_pin;
    GPIO_TypeDef *U_L_port;
    
    uint32_t V_H_pin;
    GPIO_TypeDef *V_H_port;

    uint32_t V_L_pin;
    GPIO_TypeDef *V_L_port;

    uint32_t W_H_pin;
    GPIO_TypeDef *W_H_port;

    uint32_t W_L_pin;
    GPIO_TypeDef *W_L_port;

    uint32_t state;
}ESC_StateMachine_t;


void ESC_init(ESC_StateMachine_t *esc); 
void ESC_nextState(ESC_StateMachine_t *esc);
void ESC_reset(ESC_StateMachine_t *esc);

#endif // ESC_STATE_MACHINE
