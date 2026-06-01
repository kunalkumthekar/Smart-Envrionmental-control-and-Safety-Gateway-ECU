#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

//Adding below lines as this file shall be called upon in C++ compiler
#ifdef __cplusplus
extern "C" {
    #endif

#include <stdint.h>

typedef enum {
    SYSTEM_INIT,
    SYSTEM_IDLE,
    SYSTEM_COOLING,
    SYSTEM_WARNING,
    SYSTEM_FAULT,
    SYSTEM_EMERGENCY_STOP
} SystemState;

SystemState updateSystemState(float temperature, uint8_t threshold, uint8_t tolerance, 
                            uint8_t sensor_fault, uint8_t emergency_stop);

#ifdef __cplusplus
}
#endif // CPLUSCPLUS

#endif // STATE_MACHINE