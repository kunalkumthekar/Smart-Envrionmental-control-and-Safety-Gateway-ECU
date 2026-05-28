#ifndef SENSOR_MANAGER_H
#define SENSOR_MANAGER_H

#ifdef __cplusplus
extern "C" {
#endif

float Sensor_ReadTemperature(void);

float Sensor_ReadThreshold(void);

unsigned char Sensor_CheckFault(void);

#ifdef __cplusplus
}
#endif

#endif