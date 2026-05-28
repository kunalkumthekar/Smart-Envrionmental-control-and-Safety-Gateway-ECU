#include "sensor_manager.h"

#include "hardware_abstraction.h"

float Sensor_ReadTemperature(void)
{
    return HAL_HW_ReadTemperatureSensor();
}

float Sensor_ReadThreshold(void)
{
    return HAL_HW_ReadADCThreshold();
}

unsigned char Sensor_CheckFault(void)
{
    float temp;

    temp = HAL_HW_ReadTemperatureSensor();

    if(temp < -40 || temp > 125)
    {
        return 1;
    }

    return 0;
}