#include "entity.h"
#include "font.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "solar_sensor.h"
#include "time.h"
#include "vm.h"

IWRAM_DATA u8 u8_03000124[0x130 - 0x124] = {};

IWRAM_DATA struct Entity0805fe30* gEntity0805fe30 = NULL;      // 0x03000130
IWRAM_DATA void* gEntity08060470 = NULL;                       // 0x03000134
IWRAM_DATA struct ExplosionManager* gExplosionManager = NULL;  // 0x03000138
IWRAM_DATA struct EntityCC28* gEntityCC28 = NULL;              // 0x0300013C
IWRAM_DATA struct Entity5CCC* gEntity5CCC = NULL;              // 0x03000140
IWRAM_DATA struct Entity1DBE* gEntity1DBE = NULL;              // 0x03000144

IWRAM_DATA u8 u8_03000148[8] = {};

IWRAM_DATA struct GameOverManager* gGameOverManager = NULL;  // 0x03000150
IWRAM_DATA struct LevelUpper* gLevelUpper = NULL;            // 0x03000154
IWRAM_DATA struct EntityB3D1* gEntityB3D1 = NULL;            // 0x03000158
IWRAM_DATA struct Entity080da848* gEntity080da848 = NULL;    // 0x0300015C
IWRAM_DATA struct Entity080db520* gEntity080db520 = NULL;    // 0x03000160
