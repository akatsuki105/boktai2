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

struct EntityD9AE;
struct Entity83B2;
struct Entity0866;
struct Entity0800a89c;
struct Entity329B;
struct Entity95F8;
struct Entity0801381c;
struct Entity08013b68;
struct Entity080146e0;
struct Entity08015220;
struct Entity08015584;
struct Entity08016ba4;
struct Entity08016dbc;
struct Entity08017750;
struct EntityE435;
struct GameOverManager;
struct LevelUpper;
struct EntityB3D1;
struct Entity0804e9ac;
struct EntityD53D;
struct Entity080607a8;
struct Entity080de11c;
struct Entity081d0e20;
struct Entity081d16ec;
struct Entity081eaf6c;

IWRAM_DATA u8 u8_03000000[32] = {};  // todo, rfu_MBOOT_CHILD_inheritanceLinkStatus で RFU_LINK_STATUS の本体がここにあるが、メインゲーム開始時に別の構造体で上書きされてるように見える (つまり union)

IWRAM_DATA struct EntityD9AE* gEntityD9AE = NULL;  // 0x03000020

IWRAM_DATA u8 u8_03000024[0x3C - 0x24] = {};  // todo

IWRAM_DATA struct Entity83B2* gEntity83B2 = NULL;  // 0x0300003C

IWRAM_DATA struct Entity0866* gEntity0866 = NULL;          // 0x03000040
IWRAM_DATA struct Entity0800a89c* gEntity0800a89c = NULL;  // 0x03000044
IWRAM_DATA struct Entity329B* gEntity329B = NULL;          // 0x03000048
IWRAM_DATA struct Entity95F8* gEntity95F8 = NULL;          // 0x0300004C
IWRAM_DATA struct Entity0801381c* gEntity0801381c = NULL;  // 0x03000050
IWRAM_DATA struct Entity08013b68* gEntity08013b68 = NULL;  // 0x03000054
IWRAM_DATA struct Entity080146e0* gEntity080146e0 = NULL;  // 0x03000058
IWRAM_DATA struct Entity08015220* gEntity08015220 = NULL;  // 0x0300005C
IWRAM_DATA struct Entity08015584* gEntity08015584 = NULL;  // 0x03000060
IWRAM_DATA struct Entity08016ba4* gEntity08016ba4 = NULL;  // 0x03000064
IWRAM_DATA struct Entity08016dbc* gEntity08016dbc = NULL;  // 0x03000068
IWRAM_DATA struct Entity08017750* gEntity08017750 = NULL;  // 0x0300006C
IWRAM_DATA struct EntityE435* gEntityE435 = NULL;          // 0x03000070

IWRAM_DATA u8 u8_03000074[0xA0 - 0x74] = {};  // todo

IWRAM_DATA void* gBossList[8] = {};  // 0x030000A0, idx is BossID

IWRAM_DATA u8 u8_030000c0[0xD0 - 0xC0] = {};  // todo

IWRAM_DATA Entity* gCredits = NULL;  // 0x030000D0

IWRAM_DATA u8 u8_030000d4[0xE4 - 0xD4] = {};

IWRAM_DATA struct Entity0804e9ac* gEntity0804e9ac = NULL;  // 0x030000E4
IWRAM_DATA struct EntityD53D* gEntityD53D = NULL;          // 0x030000E8

IWRAM_DATA u8 u8_030000ec[0x138 - 0x0EC] = {};

IWRAM_DATA struct Entity080607a8* gEntity080607a8 = NULL;  // 0x03000138

IWRAM_DATA u8 u8_0300013c[20] = {};

IWRAM_DATA struct GameOverManager* gGameOverManager = NULL;  // 0x03000150
IWRAM_DATA struct LevelUpper* gLevelUpper = NULL;            // 0x03000154
IWRAM_DATA struct EntityB3D1* gEntityB3D1 = NULL;            // 0x03000158

IWRAM_DATA u8 u8_0300015c[24] = {};

IWRAM_DATA struct Entity080de11c* gEntity080de11c = NULL;  // 0x03000174

IWRAM_DATA u8 u8_03000178[0x188 - 0x178] = {};

IWRAM_DATA struct Entity081d0e20* gEntity081d0e20 = NULL;  // 0x03000188
IWRAM_DATA struct Entity081d16ec* gEntity081d16ec = NULL;  // 0x0300018C

IWRAM_DATA u8 u8_03000190[0x194 - 0x190] = {};  // todo

IWRAM_DATA Elevator* gElevator = NULL;  // 0x03000194

IWRAM_DATA u8 u8_03000198[0x1C0 - 0x198] = {};

IWRAM_DATA struct Entity081eaf6c* gEntity081eaf6c = NULL;  // 0x030001C0

IWRAM_DATA u8 u8_030001c4[0x248 - 0x1c4] = {};
