#include "entity.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "time.h"

IWRAM_DATA u8 u8_03000000[5824] = {};  // todo
IWRAM_DATA struct Unk_030016c0 gUnk030016c0 = {};
IWRAM_DATA struct Unk_030016e8 gUnk030016e8 = {};
IWRAM_DATA u16 gUnk085a9208Counter = 0;          // 0x030016f4
IWRAM_DATA struct Entity2* PTR_030016f8 = NULL;  // 0x030016f8
IWRAM_DATA u32 DAT_030016fc = 0;
IWRAM_DATA u32 DAT_03001700 = 0;
IWRAM_DATA u32 DAT_03001704 = 0;
IWRAM_DATA struct Entity5* PTR_03001708 = 0;
IWRAM_DATA u8 u8_0300170c[4252] = {};
IWRAM_DATA ALIGNED(4) u8 SoundMainRAM_Buffer[896] = {0};  // 0x030027a8
IWRAM_DATA u8 u8_03002b28[112] = {};                      // todo
IWRAM_DATA u16 u16_03002b98 = 0;
IWRAM_DATA u8 u8_03002b9a[70] = {};            // todo
IWRAM_DATA struct Player* gPlayerPtr[4] = {};  // 0x03002be0
IWRAM_DATA u8 u8_03002bf0[6348] = {};          // todo
IWRAM_DATA u32 u32_030044bc = 0;
IWRAM_DATA u16 gEntityCount = 0;
IWRAM_DATA u8 u8_030044c2[94] = {};                                // todo
IWRAM_DATA struct EntityHeader gEntityManager[ENTITY_KINDS] = {};  // 0x03004520
IWRAM_DATA s32 gCount_Unk_0203b000 = 0;
IWRAM_DATA u32 u32_03004594 = 0;
IWRAM_DATA u8 u8_03004598[8] = {};  // todo
IWRAM_DATA struct VM gVM = {};
IWRAM_DATA struct GamePointer gGamePointer = {};  // 0x03004690
IWRAM_DATA void* gUnkPtr = NULL;
IWRAM_DATA u8 u8_030046a8[240] = {};  // todo
IWRAM_DATA u32 u32_03004798 = 0;
IWRAM_DATA u8 u32_0300479c[8] = {};
IWRAM_DATA u32 u32_030047a4 = 0;
IWRAM_DATA struct Unk_030016c0* gUnkPtr_030047a8 = NULL;
IWRAM_DATA u8 u32_030047ac[52] = {};                // todo
IWRAM_DATA struct Clock gClock = {};                // 0x030047e0
IWRAM_DATA struct Unk_03004810 gUnk_03004810 = {};  // 0x03004810
IWRAM_DATA u32 u32_0300481c = 0;
IWRAM_DATA sound_t gSoundIDs[32] = {};  // 0x03004820
IWRAM_DATA u32 u32_03004860 = 0;
IWRAM_DATA u16 u16_03004864 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_03004868 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_0300486c = 0;
IWRAM_DATA ALIGNED(4) u16 u16_03004870 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_ARRAY_03004874[6] = {};
IWRAM_DATA u8 u8_03004880[16] = {};
IWRAM_DATA struct SoundInfo gSoundInfo = {};  // 0x03004890
IWRAM_DATA MPlayFunc gMPlayJumpTable[36] = {};
IWRAM_DATA struct CgbChannel gCgbChans[4] = {};
IWRAM_DATA u8 u8_030053a0[1148] = {};
IWRAM_DATA struct EEPROMConfig gEEPROMConfig = {};  // 0x0300581c
IWRAM_DATA u8 u8_03005828[10184] = {};
IWRAM_DATA struct SoundInfo* SOUND_INFO_PTR = NULL;  // 0x03007ff0
