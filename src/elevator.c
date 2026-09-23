#include "entity.h"
#include "global.h"

typedef struct {
  u8 unk_00[176];  // 0x00
  u16 unk_b0;      // 0xB0
  u8 unk_b2[218];  // 0xB2
} ElevatorUnkData;
static_assert(sizeof(ElevatorUnkData) == 396);

typedef struct Elevator {
  Entity e;                    // 0x0000, ENTITY_UNK_5
  u8 unk_18[4];                // 0x0018
  ElevatorUnkData unk_1c[12];  // 0x001C
  u32 unk_12ac;                // 0x12AC
  u8 unk_12b0[8];              // 0x12B0
} Elevator;
static_assert(sizeof(Elevator) == 4792);

extern Elevator* gElevator;  // 0x03000194

INCASM("asm/elevator.inc");
