#ifndef __INCLUDE_ELEVATOR_H__
#define __INCLUDE_ELEVATOR_H__

#include "gba/gba.h"

typedef u16 ElevatorFlagsU16;
typedef u32 ElevatorFlagsU32;

#define ELEV_RIDING (1 << 0)  // 0x0001, エレベータに乗っている
#define ELEV_UNK_1 (1 << 1)   // 0x0002, Elevator_CheckPlayerFallInWater が ELEV_RIDING と同じに扱う, 立てる側は未発見
#define ELEV_MOVING (1 << 2)  // 0x0004, 動いているエレベータに乗っている, 立っていると FUN_08079644 が移動をエレベータの中心から ±100 に収める

#endif  // __INCLUDE_ELEVATOR_H__
