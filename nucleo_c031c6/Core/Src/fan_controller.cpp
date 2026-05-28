#include "fan_controller.h"

#include "hardware_abstraction.h"

uint8_t FanController_CalculatePWM(
    float temperature,
    float threshold)
{
    if(temperature <= threshold)
    {
        return 0;
    }

    if(temperature >= threshold + 20)
    {
        return 255;
    }

    return (uint8_t)(
        ((temperature - threshold) / 20.0f) * 255.0f);
}

void FanController_SetPWM(uint8_t pwm)
{
    HAL_HW_SetFanPWM(pwm);
}