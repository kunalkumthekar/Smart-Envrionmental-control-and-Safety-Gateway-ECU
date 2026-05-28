#include "app.h"

#include "sensor_manager.h"
#include "fan_controller.h"
#include "state_machine.h"
#include "diagnostics.h"
#include "hardware_abstraction.h"

void App_Run(void)
{
    float temperature;
    float threshold;

    unsigned char fault;
    unsigned char emergency;

    uint8_t pwm;

    SystemState state;

    temperature = Sensor_ReadTemperature();

    threshold = Sensor_ReadThreshold();

    fault = Sensor_CheckFault();

    emergency = HAL_HW_GetEmergencyStop();

    state = updateSystemState(
        temperature,
        threshold,
        fault,
        10,
        emergency);

    Diagnostics_LogState(state);

    Diagnostics_LogTemperature(temperature);

    switch(state)
    {
        case SYSTEM_IDLE:

            FanController_SetPWM(0);

            HAL_HW_SetStatusLED(0);

            HAL_HW_SetFaultLED(0);

            break;

        case SYSTEM_COOLING:

            pwm = FanController_CalculatePWM(
                temperature,
                threshold);

            FanController_SetPWM(pwm);

            HAL_HW_SetStatusLED(1);

            HAL_HW_SetFaultLED(0);

            break;

        case SYSTEM_WARNING:

            FanController_SetPWM(255);

            HAL_HW_SetStatusLED(1);

            HAL_HW_SetFaultLED(1);

            break;

        case SYSTEM_FAULT:

            FanController_SetPWM(0);

            HAL_HW_SetFaultLED(1);

            Diagnostics_LogFault(
                "FAULT DETECTED\r\n");

            break;

        case SYSTEM_EMERGENCY_STOP:

            FanController_SetPWM(0);

            HAL_HW_SetFaultLED(1);

            Diagnostics_LogFault(
                "EMERGENCY STOP\r\n");

            break;

        default:
            break;
    }
}