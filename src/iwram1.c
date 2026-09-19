#include "elevator.h"
#include "entity.h"
#include "font.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "solar.h"
#include "solar_sensor.h"
#include "time.h"
#include "vm.h"

struct Entity8ECD;
struct GameOverManager;
struct LevelUpper;
struct EntityB3D1;
struct SignalStrengthIcon;
struct EntityD53D;
struct Entity080607a8;
struct Entity080de11c;
struct Entity081d0e20;
struct Entity081d16ec;
struct Entity081eaf6c;
struct Entity081eb2f0;

IWRAM_DATA u8 u8_03000074[0x80 - 0x74] = {};  // todo

IWRAM_DATA s32 s32_03000080 = 0;                   // 0x03000080
IWRAM_DATA struct Entity8ECD* gEntity8ECD = NULL;  // 0x03000084

IWRAM_DATA u8 u8_03000088[0xA0 - 0x88] = {};  // todo

IWRAM_DATA void* gBossList[8] = {};  // 0x030000A0, idx is BossID

IWRAM_DATA u8 u8_030000c0[0xD0 - 0xC0] = {};  // todo

IWRAM_DATA Entity* gCredits = NULL;  // 0x030000D0

IWRAM_DATA u8 u8_030000d4[0xE4 - 0xD4] = {};

IWRAM_DATA struct SignalStrengthIcon* gSignalStrengthIcon = NULL;  // 0x030000E4
IWRAM_DATA struct EntityD53D* gEntityD53D = NULL;                  // 0x030000E8

IWRAM_DATA u8 u8_030000ec[0x138 - 0x0EC] = {};

IWRAM_DATA struct Entity080607a8* gEntity080607a8 = NULL;  // 0x03000138

IWRAM_DATA u8 u8_0300013c[20] = {};

IWRAM_DATA struct GameOverManager* gGameOverManager = NULL;  // 0x03000150
IWRAM_DATA struct LevelUpper* gLevelUpper = NULL;            // 0x03000154
IWRAM_DATA struct EntityB3D1* gEntityB3D1 = NULL;            // 0x03000158

IWRAM_DATA u8 u8_0300015c[24] = {};

IWRAM_DATA struct Entity080de11c* gEntity080de11c = NULL;  // 0x03000174

IWRAM_DATA u8 u8_03000178[0x184 - 0x178] = {};
IWRAM_DATA struct EntityD854* gEntityD854 = NULL;  // 0x03000184

IWRAM_DATA struct Entity081d0e20* gEntity081d0e20 = NULL;  // 0x03000188
IWRAM_DATA struct Entity081d16ec* gEntity081d16ec = NULL;  // 0x0300018C

IWRAM_DATA u8 u8_03000190[0x194 - 0x190] = {};  // todo

IWRAM_DATA Elevator* gElevator = NULL;  // 0x03000194

IWRAM_DATA u8 u8_03000198[0x1C0 - 0x198] = {};

IWRAM_DATA struct Entity081eaf6c* gEntity081eaf6c = NULL;  // 0x030001C0
IWRAM_DATA struct Entity081eb2f0* gEntity081eb2f0 = NULL;  // 0x030001C4

IWRAM_DATA u8 u8_030001c8[0x248 - 0x1c8] = {};
