#include "entity.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "time.h"

IWRAM_DATA u8 u8_03002b28[48] = {};  // todo

IWRAM_DATA Entity* gUnkEntity1Ptr_03002b58 = NULL;  // 0x03002B58, Malloc(908) で確保したバッファを指すポインタ, RFU関連? (FUN_0804e2c0)

IWRAM_DATA u8 u8_03002b5c[60] = {};  // todo
IWRAM_DATA u16 u16_03002b98 = 0;
IWRAM_DATA u8 u8_03002b9a[70] = {};     // todo
IWRAM_DATA Player* gPlayerPtr[4] = {};  // 0x03002be0
IWRAM_DATA u8 u8_03002bf0[192] = {};    // todo

IWRAM_DATA IntrFunc gIntrTable[13] = {};  // 0x03002cb0
IWRAM_DATA bool32 gVblankFlag = FALSE;    // 0x03002cb4
IWRAM_DATA u8 u8_03002ce8[24] = {};       // todo

IWRAM_DATA u32 IntrMain_Buffer[0x200] = {0};  // 0x03002D00, INTR_MAIN のRAMコード

IWRAM_DATA u8 u8_03003500[304] = {};  // todo

IWRAM_DATA OamData gOAMBuffer[128] = {};  // 0x03003630, OAM のバッファ

IWRAM_DATA u8 u8_03003a30[1568] = {};  // todo

IWRAM_DATA u16 gObjectPlttBuffer[256] = {};  // 0x03004050, CommitPalette で OBJ_PLTT にコピーされる
IWRAM_DATA u16 gFastBgPlttBuffer[256] = {};  // 0x03004250

IWRAM_DATA u8 u8_03004450[108] = {};  // todo
IWRAM_DATA u32 u32_030044bc = 0;
IWRAM_DATA u16 gEntityCount = 0;
IWRAM_DATA u8 u8_030044c2[90] = {};                         // todo
IWRAM_DATA u32 gRNG_0300451c = 0;                           // 0x0300451C
IWRAM_DATA EntityHeader gEntityManager[ENTITY_KINDS] = {};  // 0x03004520
IWRAM_DATA s32 gCount_Unk_0203b000 = 0;
IWRAM_DATA u32 u32_03004594 = 0;
IWRAM_DATA u8 u8_03004598[8] = {};         // todo
IWRAM_DATA VM gVM = {};                    // 0x030045A0
IWRAM_DATA GamePointer gGamePointer = {};  // 0x03004690
IWRAM_DATA void* gUnkPtr = NULL;           // Malloc(3620) で確保したバッファを指すポインタ (FUN_082326a0)
IWRAM_DATA u8 u8_030046a8[152] = {};       // todo

IWRAM_DATA LINK_MANAGER lman = {};  // 0x03004740

IWRAM_DATA u8 u8_03004788[16] = {};
IWRAM_DATA u32 u32_03004798 = 0;
IWRAM_DATA u8 u32_0300479c[8] = {};
IWRAM_DATA u32 u32_030047a4 = 0;
IWRAM_DATA Unk_030016c0* gUnkPtr_030047a8 = NULL;
IWRAM_DATA u8 u32_030047ac[52] = {};  // todo

IWRAM_DATA Clock gClock = {};               // 0x030047E0
IWRAM_DATA u32 pad_Clock_03004804[3] = {};  // 16バイトアラインのためのパディング

IWRAM_DATA RtcDataOrg gRTC = {};  // 0x03004810
IWRAM_DATA u32 u32_0300481c = 0;

IWRAM_DATA sound_t gSoundIDs[32] = {};  // 0x03004820
IWRAM_DATA u32 u32_03004860 = 0;
IWRAM_DATA u16 u16_03004864 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_03004868 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_0300486c = 0;
IWRAM_DATA ALIGNED(4) u16 u16_03004870 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_ARRAY_03004874[6] = {};
IWRAM_DATA u8 u8_03004880[16] = {};

// --------------------------------------------

IWRAM_DATA struct SoundInfo gSoundInfo = {};  // 0x03004890
IWRAM_DATA MPlayFunc gMPlayJumpTable[36] = {};
IWRAM_DATA struct CgbChannel gCgbChans[4] = {};
IWRAM_DATA struct MusicPlayerInfo u8_030053a0[14] = {0};      // 0x030053A0
IWRAM_DATA struct MusicPlayerInfo gMPlayInfo_03005720 = {0};  // 0x03005720
IWRAM_DATA u8 gMPlayMemAccArea[16] = {};                      // 0x03005760
IWRAM_DATA struct MusicPlayerInfo gMPlayInfo_03005770 = {0};  // 0x03005770
IWRAM_DATA u8 u8_030057B0[32] = {};
IWRAM_DATA STWIStatus* gSTWIStatus = NULL;  // 0x030057D0
IWRAM_DATA u8 u8_030057D4[12] = {};
