#include "diagnostics.h"

#include "hardware_abstraction.h"

#include <stdio.h>

void Diagnostics_LogState(SystemState state)
{
    switch(state)
    {
        case SYSTEM_IDLE:
            HAL_HW_UART_Log("STATE: IDLE\r\n");
            break;

        case SYSTEM_COOLING:
            HAL_HW_UART_Log("STATE: COOLING\r\n");
            break;

        case SYSTEM_WARNING:
            HAL_HW_UART_Log("STATE: WARNING\r\n");
            break;

        case SYSTEM_FAULT:
            HAL_HW_UART_Log("STATE: FAULT\r\n");
            break;

        case SYSTEM_EMERGENCY_STOP:
            HAL_HW_UART_Log("STATE: EMERGENCY STOP\r\n");
            break;

        default:
            HAL_HW_UART_Log("STATE: UNKNOWN\r\n");
            break;
    }
}

void Diagnostics_LogTemperature(float temperature)
{
    char buffer[64];

    sprintf(buffer, "TEMP: %.2f\r\n", temperature);

    HAL_HW_UART_Log(buffer);
}

void Diagnostics_LogFault(const char* msg)
{
    HAL_HW_UART_Log(msg);
}