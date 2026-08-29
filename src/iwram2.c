#include "camera.h"
#include "entity.h"
#include "entity_unk.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "particle.h"
#include "solar_sensor.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "vm.h"

struct Entity4AE5;

IWRAM_DATA u16 gMapInitScriptID = 0;               // 0x03002B28
IWRAM_DATA struct Entity4AE5* gEntity4AE5 = NULL;  // 0x03002B2C

IWRAM_DATA u8 u8_03002b30[28] = {};  // todo

IWRAM_DATA Entity4E69* gEntity4E69 = NULL;  // 0x03002B4C

IWRAM_DATA u8 u8_03002b50[8] = {};  // todo

IWRAM_DATA Entity* gUnkEntity1Ptr_03002b58 = NULL;  // 0x03002B58, Malloc(908) で確保したバッファを指すポインタ, RFU関連? (FUN_0804e2c0)

IWRAM_DATA u8 u8_03002b5c[60] = {};     // todo
IWRAM_DATA u16 gPlayerCount = 0;        // Playerの数, シングルプレイ中は1, 通信対戦中時は参加人数になる
IWRAM_DATA u8 u8_03002b9a[70] = {};     // todo
IWRAM_DATA Player* gPlayerPtr[4] = {};  // 0x03002BE0, 通信対戦時に自分が子機の場合も自キャラが 0 になるかは不明
IWRAM_DATA u8 u8_03002bf0[8] = {};      // todo

struct Entity5941;
IWRAM_DATA struct Entity5941* gEntity5941 = NULL;  // 0x03002BF8

IWRAM_DATA u8 u8_03002bfc[108] = {};  // todo

IWRAM_DATA Entity_03002c68* gEntity_03002c68 = NULL;  // 0x03002C68

IWRAM_DATA u8 u8_03002c6c[68] = {};  // todo

IWRAM_DATA IntrFunc gIntrTable[13] = {};  // 0x03002cb0
IWRAM_DATA vu32 gVblankFlag = FALSE;      // 0x03002cb4
IWRAM_DATA u8 u8_03002ce8[24] = {};       // todo

IWRAM_DATA u32 IntrMain_Buffer[0x200] = {0};  // 0x03002D00, INTR_MAIN のRAMコード

IWRAM_DATA u8 u8_03003500[132] = {};  // todo

IWRAM_DATA u16 gObjPlttLen = 0;          // 0x03003580, = ObjPlttFile.length
IWRAM_DATA rgb555* gObjPlttData = NULL;  // 0x03003584, = ObjPlttFile.body

IWRAM_DATA ParticleFile* gParticleFile = NULL;         // 0x0300358C, 現在ロードされているParticleFileへのポインタ, ParticleFile は ParticleFile0 しかないので NULL or &ParticleFile0 になるはず
IWRAM_DATA u16 gParticle_03003590 = 0;                 // 0x03003590, まだ不明
IWRAM_DATA ALIGNED(4) s16 gParticleFileTileCount = 0;  // 0x03003594, ParticleFile.tileCount のタイル数

IWRAM_DATA void* gActorSprite_03003598 = NULL;          // 0x03003598
IWRAM_DATA void* gActorSprite_0300359C = NULL;          // 0x0300359C
IWRAM_DATA ActorSpritesFile* gActorSpritesFile = NULL;  // 0x030035A0

IWRAM_DATA u8 u8_030035A4[140] = {};  // todo

IWRAM_DATA OamData gOAMBuffer[128] = {};  // 0x03003630, OAM のバッファ

IWRAM_DATA u8 u8_03003a30[1568] = {};  // todo

IWRAM_DATA u16 gObjectPlttBuffer[256] = {};  // 0x03004050, CommitPalette で OBJ_PLTT にコピーされる
IWRAM_DATA u16 gFastBgPlttBuffer[256] = {};  // 0x03004250

IWRAM_DATA u8 u8_03004450[104] = {};     // todo
IWRAM_DATA u16 u16_030044b8 = 0;         // 0x030044B8
IWRAM_DATA u32 gEntityDisableFlags = 0;  // 0x030044BC, gEntityDisableFlags & gEntityManager[kind].disableFlags != 0 のときはそのkindのEntityは更新しない, gEntityDisableFlagsの各bitは (1 << kind) ではなさそう
IWRAM_DATA u16 gEntityCount = 0;
IWRAM_DATA u8 u8_030044c2[90] = {};                       // todo
IWRAM_DATA u32 gRngValue = 0;                             // 0x0300451C
IWRAM_DATA EntityList gEntityManager[ENTITY_KINDS] = {};  // 0x03004520
IWRAM_DATA s32 gCount_Unk_0203b000 = 0;
IWRAM_DATA u32 gScriptDirectoryBuildTime = 0;  // 0x03004594, ScriptDirectory.buildTime
IWRAM_DATA u8 u8_03004598[8] = {};             // todo
IWRAM_DATA VM gVM = {};                        // 0x030045A0

IWRAM_DATA UnkGameStruct* gScratch = NULL;  // 0x03004690
IWRAM_DATA World* gWorldBackup = NULL;      // 0x03004694
IWRAM_DATA World* gWorld = NULL;            // 0x03004698
IWRAM_DATA GameInfo* gStatBackup = NULL;    // 0x0300469C
IWRAM_DATA GameInfo* gStat = NULL;          // 0x030046A0

struct Unk030046a4;
IWRAM_DATA struct Unk030046a4* gUnk030046a4 = NULL;  // Malloc(3620) で確保したバッファを指すポインタ (FUN_082326a0)
IWRAM_DATA s32 gMapBlockW = 0;                       // 0x030046A8
IWRAM_DATA s32 gMapBlockH = 0;                       // 0x030046AC

IWRAM_DATA u8 u8_030046b0[144] = {};  // todo

IWRAM_DATA LINK_MANAGER lman = {};  // 0x03004740

IWRAM_DATA bool32 bool32_03004788 = FALSE;  // 0x03004788

IWRAM_DATA u8 u8_0300478c[12] = {};
IWRAM_DATA u32 u32_03004798 = 0;
IWRAM_DATA u8 u32_0300479c[8] = {};
IWRAM_DATA u32 gFlag030047a4 = 0;
IWRAM_DATA SystemSaveData* gSystemSaveData = NULL;
IWRAM_DATA u8 u8_030047ac[28] = {};  // todo

IWRAM_DATA Vec3 gCameraVpCoords = {};  // 0x030047C8
IWRAM_DATA Camera* gCamera = NULL;     // 0x030047D0
IWRAM_DATA u8 u8_030047d4[12] = {};    // todo

IWRAM_DATA Clock gClock = {};               // 0x030047E0
IWRAM_DATA u32 pad_Clock_03004804[3] = {};  // 16バイトアラインのためのパディング

IWRAM_DATA RtcDataOrg gRTC = {};  // 0x03004810
IWRAM_DATA u32 u32_0300481c = 0;

IWRAM_DATA SoundID16 gSoundIDs[MUSIC_PLAYER_LENGTH] = {};  // 0x03004820
IWRAM_DATA u32 u32_03004860 = 0;
IWRAM_DATA u16 u16_03004864 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_03004868 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_0300486c = 0;
IWRAM_DATA ALIGNED(4) u16 u16_03004870 = 0;
IWRAM_DATA ALIGNED(4) u16 u16_ARRAY_03004874[6] = {};
IWRAM_DATA u8 u8_03004880[16] = {};

// --------------------------------------------
