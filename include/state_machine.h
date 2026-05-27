#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <stdint.h>

typedef enum {
    SYSTEM_INIT,
    SYSTEM_IDLE,
    SYSTEM_COOLING,
    SYSTEM_WARNING,
    SYSTEM_FAULT,
    SYSTEM_EMERGENCY_STOP
} SystemState;

SystemState updateSystemState(float temperature, float threshold, float tolerance 
                            uint8_t sensor_fault, uint8_t emergency_stop);

#endif