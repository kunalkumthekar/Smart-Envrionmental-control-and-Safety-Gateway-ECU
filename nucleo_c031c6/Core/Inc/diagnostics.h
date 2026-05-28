#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H

#include "state_machine.h"

#ifdef __cplusplus
extern "C" {
#endif

void Diagnostics_LogState(SystemState state);

void Diagnostics_LogTemperature(float temperature);

void Diagnostics_LogFault(const char* msg);

#ifdef __cplusplus
}
#endif

#endif