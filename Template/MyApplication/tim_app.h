#ifndef TIM_APP_H
#define TIM_APP_H

#include "bsp_system.h"

#ifdef __cplusplus
extern "C" {
#endif

void pwm_set_duty(float duty, uint8_t tim_x);
void pwm_set_frequency(int frequency, uint8_t tim_x);
void tim_proc(void);

#ifdef __cplusplus
}
#endif

#endif /* TIM_APP_H */



