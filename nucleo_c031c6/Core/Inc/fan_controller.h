#ifndef FAN_CONTROLLER_H
#define FAN_CONTROLLER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint8_t FanController_CalculatePWM(
    float temperature,
    float threshold);

void FanController_SetPWM(uint8_t pwm);

#ifdef __cplusplus
}
#endif

#endif