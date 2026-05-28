#include "state_machine.h"

SystemState updateSystemState(float temperature, float threshold, float tolerance, 
                            uint8_t sensor_fault, uint8_t emergency_stop) {

        if(emergency_stop) {
            return SYSTEM_EMERGENCY_STOP;
        }

        if(sensor_fault) {
            return SYSTEM_FAULT;
        }

        if (temperature > threshold + tolerance) {
            return SYSTEM_WARNING;
        }

        if (temperature > threshold) {
            return SYSTEM_COOLING;
        }

        return SYSTEM_IDLE;
};