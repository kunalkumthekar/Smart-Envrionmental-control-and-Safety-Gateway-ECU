#ifndef HARDWARE_ABSTRACTION_H
#define HARDWARE_ABSTRACTION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void HAL_HW_Init(void);

float HAL_HW_ReadTemperatureSensor(void);

float HAL_HW_ReadADCThreshold(void);

void HAL_HW_SetFanPWM(uint8_t pwm);

void HAL_HW_UART_Log(const char* msg);

void HAL_HW_SetStatusLED(uint8_t state);

void HAL_HW_SetFaultLED(uint8_t state);

uint8_t HAL_HW_GetEmergencyStop(void);

#ifdef __cplusplus
}
#endif

#endif