#include "hardware_abstraction.h"
#include <stdint.h>

#ifdef UNIT_TEST

#include <stdio.h>

static uint8_t emergency_flag = 0;

void HAL_HW_Init(void)
{
}

float HAL_HW_ReadTemperatureSensor(void)
{
    return 35.0f;
}

float HAL_HW_ReadADCThreshold(void)
{
    return 30.0f;
}

void HAL_HW_SetFanPWM(uint8_t pwm)
{
    printf("PWM = %d\n", pwm);
}

void HAL_HW_UART_Log(const char* msg)
{
    printf("%s", msg);
}

void HAL_HW_SetStatusLED(uint8_t state)
{
    printf("STATUS LED = %d\n", state);
}

void HAL_HW_SetFaultLED(uint8_t state)
{
    printf("FAULT LED = %d\n", state);
}

uint8_t HAL_HW_GetEmergencyStop(void)
{
    return emergency_flag;
}

#else

#include "main.h"
#include "stm32c0xx_hal.h"

#include <string.h>

extern UART_HandleTypeDef huart2;
extern ADC_HandleTypeDef hadc1;

static volatile uint8_t emergency_flag = 0;

void HAL_HW_Init(void)
{
}

float HAL_HW_ReadTemperatureSensor(void)
{
    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, 100);
    uint16_t adc = HAL_ADC_GetValue(&hadc1);
    return (150.0f * adc) / 4095;
    // return 32.0f;
}

float HAL_HW_ReadADCThreshold(void)
{
    return 30.0f;
}

void HAL_HW_SetFanPWM(uint8_t pwm)
{
    (void)pwm;
}

void HAL_HW_UART_Log(const char* msg)
{
    HAL_UART_Transmit(
        &huart2,
        (uint8_t*)msg,
        strlen(msg),
        HAL_MAX_DELAY);
}

void HAL_HW_SetStatusLED(uint8_t state)
{
    HAL_GPIO_WritePin(
        GPIOC,
        GPIO_PIN_6,
        state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void HAL_HW_SetFaultLED(uint8_t state)
{
    HAL_GPIO_WritePin(
        GPIOC,
        GPIO_PIN_7,
        state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

uint8_t HAL_HW_GetEmergencyStop(void)
{
    return emergency_flag;
}

extern "C"
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if(GPIO_Pin == GPIO_PIN_13)
    {
        emergency_flag = 1;
        HAL_GPIO_WritePin(
        GPIOA,
        GPIO_PIN_12,
        emergency_flag ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
}

#endif