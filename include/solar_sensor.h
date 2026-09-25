#ifndef __INCLUDE_SOLAR_SENSOR_H__
#define __INCLUDE_SOLAR_SENSOR_H__

#include "gba/gba.h"
#include "types.h"

void Sensor_Enable(void);
void Sensor_Disable(void);
s32 Sensor_GetRawLevel(void);

#endif  // __INCLUDE_SOLAR_SENSOR_H__
