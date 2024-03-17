#if !defined(ESC_ALGORITHM)
#define ESC_ALGORITHM
#include "stm32c031xx.h"
#include "main.h"

#define MAX_ADC_VALUE   4096U

typedef struct ESC_stateMachine_t
{
    ADC_HandleTypeDef *hadc; //adc handle

    float volt_u;
    float volt_v;
    float volt_w;
}ESC_stateMachine_t;

HAL_StatusTypeDef ESC_init(ESC_stateMachine_t *esc);
void ESC_measureVoltage(ESC_stateMachine_t *esc);
void ESC_nextState();
void ESC_reset();

#endif // ESC_STATE_MACHINE
