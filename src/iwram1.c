#include "entity.h"
#include "font.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "solar_sensor.h"
#include "time.h"
#include "vm.h"

struct GameOverManager;
struct LevelUpper;
struct EntityB3D1;
struct Entity080da848;
struct Entity080db520;
struct Entity080dbe54;
struct Entity080dc44c;
struct Entity080dd1f8;
struct SignalStrengthIcon;
struct EntityD53D;
struct EntityAF33;
struct Entity723E;
struct Entity08051b70;
struct Entity0805fe30;
struct ExplosionManager;
struct EntityCC28;
struct Entity5CCC;
struct Entity1DBE;
struct AttackBoxManager;
struct Entity080de11c;
struct Entity080df420;
struct Entity081d0e20;
struct Entity081d16ec;
struct Entity081d2180;
struct Elevator;
struct EntityF1F9;
struct EntityC60F;
struct Entity7B9F;
struct Entity8CC7;
struct LinkBattleLobby;
struct Entity150F;
struct Entity081ea120;
struct Entity081ea820;
struct Entity081eaf6c;
struct Entity081eb2f0;

IWRAM_DATA u8 u8_030000e0[0xE4 - 0xE0] = {};

IWRAM_DATA struct SignalStrengthIcon* gSignalStrengthIcon = NULL;  // 0x030000E4
IWRAM_DATA struct EntityD53D* gEntityD53D = NULL;                  // 0x030000E8

IWRAM_DATA u8 u8_030000ec[0x0F0 - 0x0EC] = {};

IWRAM_DATA struct EntityAF33* gEntityAF33 = NULL;  // 0x030000F0

IWRAM_DATA u8 u8_030000f4[0x118 - 0x0F4] = {};

IWRAM_DATA struct Entity08051b70* gEntity08051b70 = NULL;  // 0x03000118
IWRAM_DATA struct Entity723E* gEntity723E = NULL;          // 0x0300011C

IWRAM_DATA u8 u8_03000120[0x130 - 0x120] = {};

IWRAM_DATA struct Entity0805fe30* gEntity0805fe30 = NULL;      // 0x03000130
IWRAM_DATA void* gEntity08060470 = NULL;                       // 0x03000134
IWRAM_DATA struct ExplosionManager* gExplosionManager = NULL;  // 0x03000138
IWRAM_DATA struct EntityCC28* gEntityCC28 = NULL;              // 0x0300013C
IWRAM_DATA struct Entity5CCC* gEntity5CCC = NULL;              // 0x03000140
IWRAM_DATA struct Entity1DBE* gEntity1DBE = NULL;              // 0x03000144

IWRAM_DATA u8 u8_03000148[8] = {};

IWRAM_DATA struct GameOverManager* gGameOverManager = NULL;    // 0x03000150
IWRAM_DATA struct LevelUpper* gLevelUpper = NULL;              // 0x03000154
IWRAM_DATA struct EntityB3D1* gEntityB3D1 = NULL;              // 0x03000158
IWRAM_DATA struct Entity080da848* gEntity080da848 = NULL;      // 0x0300015C
IWRAM_DATA struct Entity080db520* gEntity080db520 = NULL;      // 0x03000160
IWRAM_DATA struct Entity080dbe54* gEntity080dbe54 = NULL;      // 0x03000164
IWRAM_DATA struct Entity080dc44c* gEntity080dc44c = NULL;      // 0x03000168
IWRAM_DATA struct Entity080dd1f8* gEntity080dd1f8 = NULL;      // 0x0300016C
IWRAM_DATA struct AttackBoxManager* gAttackBoxManager = NULL;  // 0x03000170
IWRAM_DATA struct Entity080de11c* gEntity080de11c = NULL;      // 0x03000174
IWRAM_DATA struct Entity080df420* gEntity080df420 = NULL;      // 0x03000178

IWRAM_DATA u8 u8_0300017c[0x184 - 0x17c] = {};
IWRAM_DATA struct EntityD854* gEntityD854 = NULL;  // 0x03000184

IWRAM_DATA struct Entity081d0e20* gEntity081d0e20 = NULL;    // 0x03000188
IWRAM_DATA struct Entity081d16ec* gEntity081d16ec = NULL;    // 0x0300018C
IWRAM_DATA struct Entity081d2180* gEntity081d2180 = NULL;    // 0x03000190
IWRAM_DATA struct Elevator* gElevator = NULL;                // 0x03000194
IWRAM_DATA struct EntityF1F9* gEntityF1F9 = NULL;            // 0x03000198
IWRAM_DATA struct EntityC60F* gEntityC60F = NULL;            // 0x0300019C
IWRAM_DATA struct Entity7B9F* gEntity7B9F = NULL;            // 0x030001A0
IWRAM_DATA struct Entity8CC7* gEntity8CC7 = NULL;            // 0x030001A4
IWRAM_DATA struct LinkBattleLobby* gLinkBattleLobby = NULL;  // 0x030001A8
IWRAM_DATA u32 bool32_030001ac = FALSE;                      // 0x030001AC
IWRAM_DATA struct Entity150F* gEntity150F = NULL;            // 0x030001B0

IWRAM_DATA u8 u8_030001b4[0x1B8 - 0x1B4] = {};

IWRAM_DATA struct Entity081ea120* gEntity081ea120 = NULL;  // 0x030001B8
IWRAM_DATA struct Entity081ea820* gEntity081ea820 = NULL;  // 0x030001BC
IWRAM_DATA struct Entity081eaf6c* gEntity081eaf6c = NULL;  // 0x030001C0
IWRAM_DATA struct Entity081eb2f0* gEntity081eb2f0 = NULL;  // 0x030001C4

IWRAM_DATA u8 u8_030001c8[0x218 - 0x1c8] = {};
