#include "elevator.h"
#include "entity.h"
#include "entity_unk.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "solar.h"
#include "solar_sensor.h"
#include "time.h"
#include "vm.h"

struct EntityD9AE;
struct Entity080146e0;
struct Entity8AAB;
struct GameOverManager;
struct LevelUpper;
struct Entity080607a8;
struct Entity080de11c;
struct HitboxManager;
struct Entity794C;

IWRAM_DATA u8 u8_03000000[32] = {};  // todo, rfu_MBOOT_CHILD_inheritanceLinkStatus で RFU_LINK_STATUS の本体がここにあるが、メインゲーム開始時に別の構造体で上書きされてるように見える (つまり union)

IWRAM_DATA struct EntityD9AE* gEntityD9AE = NULL;  // 0x03000020

IWRAM_DATA u8 u8_03000024[0x58 - 0x24] = {};  // todo

IWRAM_DATA struct Entity080146e0* gEntity080146e0 = NULL;  // 0x03000058

IWRAM_DATA u8 u8_0300005c[0xA0 - 0x5C] = {};  // todo

IWRAM_DATA void* gBossList[8] = {};  // 0x030000A0, idx is BossID

IWRAM_DATA u8 u8_030000c0[0xD0 - 0xC0] = {};  // todo

IWRAM_DATA Entity* gCredits = NULL;  // 0x030000D0

IWRAM_DATA u8 u8_030000d4[100] = {};

IWRAM_DATA struct Entity080607a8* gEntity080607a8 = NULL;  // 0x03000138

IWRAM_DATA u8 u8_0300013c[20] = {};

IWRAM_DATA struct GameOverManager* gGameOverManager = NULL;  // 0x03000150

IWRAM_DATA struct LevelUpper* gLevelUpper = NULL;  // 0x03000154

IWRAM_DATA u8 u8_03000158[28] = {};

IWRAM_DATA struct Entity080de11c* gEntity080de11c = NULL;  // 0x03000174

IWRAM_DATA u8 u8_03000178[28] = {};

IWRAM_DATA Elevator* gElevator = NULL;  // 0x03000194

IWRAM_DATA u8 u8_03000198[176] = {};

IWRAM_DATA struct Entity8AAB* gEntity8AAB = NULL;  // 0x03000248

IWRAM_DATA u8 u8_0300024c[12] = {};

IWRAM_DATA Entity gVideoManager = {};  // 0x03000258

IWRAM_DATA Entity gEntityKind13 = {};  // 0x03000270
IWRAM_DATA u8 u8_03000288[1184] = {};  // おそらく最初の方は gEntityKind13 の続きが入るが、どこまでが gEntityKind13 なのかは不明

IWRAM_DATA Entity gSystemManager = {};  // 0x03000728

IWRAM_DATA u8 u8_03000740[8] = {};

IWRAM_DATA ScriptTable gScriptTable = {};  // 0x03000748

IWRAM_DATA SubroutineTable* gCtrlHandlers = NULL;  // 0x03000768

IWRAM_DATA u8 u8_0300076c[4] = {};

IWRAM_DATA SubroutineTable gCtrlHandlers1 = {};  // 0x03000770
IWRAM_DATA bool32 bool32_0300077c = FALSE;       // 0x0300077C

IWRAM_DATA struct HitboxManager* gHitboxManager = NULL;  // 0x03000780

IWRAM_DATA u8 u8_03000784[0x030016A0 - 0x03000784] = {};

IWRAM_DATA Entity1_030016a0 gEntity1_030016a0 = {};    // 0x030016A0
IWRAM_DATA SystemSaveData gSystemSaveDataBuffer = {};  // 0x030016C0
IWRAM_DATA SubroutineTable gCtrlHandlers2 = {};
IWRAM_DATA u16 gSubroutineCount = 0;        // 0x030016f4
IWRAM_DATA EntityB8B9* gEntityB8B9 = NULL;  // 0x030016f8
IWRAM_DATA u32 DAT_030016fc = 0;
IWRAM_DATA struct Entity794C* gEntity794C = NULL;  // 0x03001700
IWRAM_DATA void* gEntityB639 = NULL;               // 0x03001704
