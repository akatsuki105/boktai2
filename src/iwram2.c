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
struct EntityAA65;
struct EntityC9BC;
struct Entity0800f110;
struct Entity08013df0;
struct Entity4E69;
struct Dvalinn;
struct Entity5941;
struct EntityCBB0;
struct Player;
struct Unk030046a4;

IWRAM_DATA u16 gMapInitScriptID = 0;               // 0x03002B28
IWRAM_DATA struct Entity4AE5* gEntity4AE5 = NULL;  // 0x03002B2C

IWRAM_DATA u8 u8_03002b30[0x34 - 0x30] = {};  // todo

IWRAM_DATA struct EntityAA65* gEntityAA65 = NULL;          // 0x03002B34
IWRAM_DATA struct EntityC9BC* gEntityC9BC = NULL;          // 0x03002B38
IWRAM_DATA struct Entity0800f110* gEntity0800f110 = NULL;  // 0x03002B3C
IWRAM_DATA struct Entity08013df0* gEntity08013df0 = NULL;  // 0x03002B40

IWRAM_DATA u8 u8_03002b44[0x4C - 0x44] = {};  // todo

IWRAM_DATA struct Entity4E69* gEntity4E69 = NULL;  // 0x03002B4C

IWRAM_DATA u8 u8_03002b50[8] = {};  // todo

IWRAM_DATA Entity* gUnkEntity1Ptr_03002b58 = NULL;  // 0x03002B58, Malloc(908) で確保したバッファを指すポインタ, RFU関連? (FUN_0804e2c0)

IWRAM_DATA u8 u8_03002b5c[60] = {};            // todo
IWRAM_DATA u16 gPlayerCount = 0;               // Playerの数, シングルプレイ中は1, 通信対戦中時は参加人数になる
IWRAM_DATA u8 u8_03002b9a[70] = {};            // todo
IWRAM_DATA struct Player* gPlayerPtr[4] = {};  // 0x03002BE0, 通信対戦時に自分が子機の場合も自キャラが 0 になるかは不明
IWRAM_DATA u8 u8_03002bf0[8] = {};             // todo

IWRAM_DATA struct Entity5941* gEntity5941 = NULL;  // 0x03002BF8

IWRAM_DATA u8 u8_03002bfc[0x03002C58 - 0x03002bfc] = {};  // todo

IWRAM_DATA struct EntityCBB0* gEntityCBB0 = NULL;  // 0x03002C58

IWRAM_DATA u8 u8_03002c5c[0x03002C68 - 0x03002C5C] = {};  // todo

IWRAM_DATA Entity_03002c68* gEntity_03002c68 = NULL;  // 0x03002C68

IWRAM_DATA u8 u8_03002c6c[0x03002C80 - 0x03002C6C] = {};  // todo

IWRAM_DATA struct Dvalinn* gDvalinn = NULL;  // 0x03002C80

IWRAM_DATA u8 u8_03002c84[0x03002CA0 - 0x03002C84] = {};  // todo

IWRAM_DATA vu16* gHBlankEffectReg = NULL;  // 0x03002CA0, HBlank 毎に gHBlankEffectBuffer の値を書き込む I/O レジスタ, 根拠: FUN_0822f0d8, FUN_0822eef4

IWRAM_DATA u8 u8_03002ca4[0x03002CB0 - 0x03002CA4] = {};  // todo

IWRAM_DATA IntrFunc gIntrTable[13] = {};  // 0x03002cb0
IWRAM_DATA vu32 gVblankFlag = FALSE;      // 0x03002cb4
IWRAM_DATA u8 u8_03002ce8[24] = {};       // todo

IWRAM_DATA u32 IntrMain_Buffer[0x200] = {0};  // 0x03002D00, INTR_MAIN のRAMコード

IWRAM_DATA u8 u8_03003500[0x03003510 - 0x03003500] = {};  // todo

IWRAM_DATA u16 u16_03003510 = 0;             // 0x03003510, FUN_0822f0d8, FUN_0822eef4 が 1 を書く
IWRAM_DATA u8 u8_03003512[2] = {};           // todo
IWRAM_DATA u16 u16_03003514 = 0;             // 0x03003514, FUN_0822f0d8 は 0、FUN_0822eef4 は 1 を書く
IWRAM_DATA u8 u8_03003516[2] = {};           // todo
IWRAM_DATA u16* gHBlankEffectBuffer = NULL;  // 0x03003518, スキャンライン毎(160 ライン)の値のバッファ (= u8_ARRAY_02036c00), 根拠: FUN_0822f0d8, FUN_0822eef4

IWRAM_DATA u8 u8_0300351c[0x03003530 - 0x0300351C] = {};  // todo

IWRAM_DATA u32 u32_03003530 = 0;  // 0x03003530, PTR_ARRAY_03003568 の idx, 根拠: FUN_0822f1d8

IWRAM_DATA u8 u8_03003534[0x60 - 0x34] = {};  // todo

IWRAM_DATA q_SpriteNode44* PTR_ARRAY_03003560[2] = {};  // 0x03003560
IWRAM_DATA SpriteState* PTR_ARRAY_03003568[2] = {};     // 0x03003568, 根拠: FUN_0822f1d8

IWRAM_DATA Particle* PTR_ARRAY_03003570[2] = {};  // 0x03003570, 根拠: FUN_0822a398

IWRAM_DATA u16 gActorSpriteTileCount = 0;  // 0x03003578, このフレームに FUN_0822b270 が積んだアクタースプライトのタイル数, 根拠: FUN_0822b308 が DMA 先の起点計算に使う
IWRAM_DATA u16 u16_0300357a = 0;           // todo
IWRAM_DATA u16 u16_0300357c = 0;           // 0x0300357C, DrawSprite_0822f6fc が積んだタイル数を加算していくが、読み出す箇所が見つかっていない
IWRAM_DATA u16 u16_0300357e = 0;           // todo

IWRAM_DATA u16 gObjPlttLen = 0;          // 0x03003580, = ObjPlttFile.length
IWRAM_DATA rgb555* gObjPlttData = NULL;  // 0x03003584, = ObjPlttFile.body

IWRAM_DATA s16 gObjTileCursor = 0;  // 0x03003588, 次に確保する OBJ VRAM のタイル番号 (上限 0x400). Video_ResetObjTileAlloc で gParticleFileTileCount に戻される

IWRAM_DATA ParticleFile* gParticleFile = NULL;         // 0x0300358C, 現在ロードされているParticleFileへのポインタ, ParticleFile は ParticleFile0 しかないので NULL or &ParticleFile0 になるはず
IWRAM_DATA u16 gParticle_03003590 = 0;                 // 0x03003590, まだ不明
IWRAM_DATA ALIGNED(4) s16 gParticleFileTileCount = 0;  // 0x03003594, ParticleFile.tileCount のタイル数

IWRAM_DATA u8* gActorSpriteTiles = NULL;                   // 0x03003598, &ActorSpritesFile + offsetToTiles
IWRAM_DATA ActorSubsprite* gActorSpriteSubsprites = NULL;  // 0x0300359C, &ActorSpritesFile + offsetToSubsprites
IWRAM_DATA ActorSpritesFile* gActorSpritesFile = NULL;     // 0x030035A0

IWRAM_DATA u8 u8_030035A4[140] = {};  // todo

IWRAM_DATA OamData gOAMBuffer[128] = {};  // 0x03003630, OAM のバッファ

IWRAM_DATA u8 u8_03003a30[0x03003ED0 - 0x03003A30] = {};  // todo

IWRAM_DATA BgState gBgStates[4] = {};  // 0x03003ED0, BG0-3 の状態, 根拠: FUN_0822eef4, StageBGRegs (stride 0x30, +0x20/+0x22 を BGnHOFS/BGnVOFS に使う)

IWRAM_DATA u8 u8_03003f90[0x03003FB0 - 0x03003F90] = {};  // todo, WIN0H/WIN1H/WIN0V/WIN1V の控えを含む (FUN_0822cd24, FUN_0822cdcc)

// idx は ((OAM1.14-15 << 2) | (OAM0.14-15)), ie. ((sizeidx << 2) | shape)
IWRAM_DATA u8 gOAMTileHeightTable[16] = {};  // 0x03003FB0, タイル(8px)単位
IWRAM_DATA u8 gOAMHeightTable[16] = {};      // 0x03003FC0, ピクセル単位
IWRAM_DATA u8 gOAMTileCounts[16] = {};       // 0x03003FD0, タイル枚数
IWRAM_DATA u8 gOAMTileWidthTable[16] = {};   // 0x03003FE0, タイル(8px)単位
IWRAM_DATA u32 gOAMShapeSizeAttrTable[16] = {};  // 0x03003FF0, OAM0.14-15(shape) と OAM1.14-15(size) のビットを attr0|attr1<<16 形式で格納, DrawSprite_0822a574 / DrawSprite_0822f6fc が OR する
IWRAM_DATA u8 gOAMWidthTable[16] = {};       // 0x03004030, ピクセル単位

IWRAM_DATA u8 u8_03004040[4] = {};  // todo
IWRAM_DATA s32 s32_03004044 = 0;    // 0x03004044, gObjPlttSlotIDs の使用数 (最大 16), 根拠: FUN_0822d190 (FUN_0822d12c は gObjPlttSlotCount の方を使う)
IWRAM_DATA u8 u8_03004048[8] = {};  // todo

IWRAM_DATA rgb555 gObjectPlttBuffer[256] = {};  // 0x03004050, CommitPalette で OBJ_PLTT にコピーされる
IWRAM_DATA rgb555 gFastBgPlttBuffer[256] = {};  // 0x03004250

IWRAM_DATA s32 s32_03004450 = 0;  // 0x03004450, FUN_0822d114 が s32_03004044 = これ + 2 として 0 に戻す
IWRAM_DATA u8 u8_03004454[4] = {};  // todo

IWRAM_DATA s32 gObjPlttSlotCount = 0;  // 0x03004458, 確保済みの OBJ パレットスロット数 (最大 2), 根拠: FUN_0822d12c

IWRAM_DATA u8 u8_0300445c[0x4468 - 0x445C] = {};  // todo

IWRAM_DATA rgb555* gBGPlttBufferPointer = NULL;  // 0x03004468

IWRAM_DATA u8 u8_0300446c[0x4470 - 0x446C] = {};  // todo

IWRAM_DATA u16 gObjPlttSlotIDs[16] = {};  // 0x03004470, 各 OBJ パレットスロットに割り当てたパレット ID, 根拠: FUN_0822d12c (2 個まで), FUN_0822d190 (16 個まで)

IWRAM_DATA u8 u8_03004490[0x4498 - 0x4490] = {};  // todo

IWRAM_DATA u8 gMosaicTargets = 0;            // 0x03004498, bit0-3: BG0-3 の BGnCNT.6 を立てる, bit4: MOSAIC の OBJ 側(bit8-15)も書く, 根拠: Video_ApplyMosaic
IWRAM_DATA u8 u8_03004499[3] = {};           // todo
IWRAM_DATA u16 gMosaicDirty = 0;             // 0x0300449C, 1 なら次の Video_ApplyMosaic で I/O に反映して 0 に戻す
IWRAM_DATA u16 u16_0300449e = 0;             // todo
IWRAM_DATA u32 gHBlankEffectBG = 0;          // 0x030044A0, HBlankエフェクトの対象BG番号, 根拠: FUN_0822f0d8
IWRAM_DATA void* gHBlankEffectTable = NULL;  // 0x030044A4, スキャンライン毎の値のテーブル, 根拠: FUN_0822eef4
IWRAM_DATA s32 gHBlankEffectKind = 0;        // 0x030044A8, HBlankエフェクトの種類 (0:BGnHOFS, 1:BGnVOFS, 2:MOSAIC, 3:BLDY), 根拠: FUN_0822f0d8
IWRAM_DATA u32 gObjBlendEnabled = 0;         // 0x030044AC, 0以外なら flags bit14 のスプライトを半透明にする, 根拠: DrawSprite_0822f6fc
IWRAM_DATA u8 gObjMosaicEnabled = 0;         // 0x030044B0, bit0 が立っているスプライトだけ OAM attr0.12 (mosaic) を立てる, 根拠: DrawSprite_0822f6fc / DrawSprite_0822a574
IWRAM_DATA u8 u8_030044b1[3] = {};           // todo
IWRAM_DATA u16 gMosaicSize = 0;              // 0x030044B4, MOSAIC レジスタに書く値 (bit0-3: BG H, bit4-7: BG V, bit8-11: OBJ H, bit12-15: OBJ V)
IWRAM_DATA u16 u16_030044b6 = 0;             // todo
IWRAM_DATA u16 u16_030044b8 = 0;             // 0x030044B8
IWRAM_DATA u32 gEntityDisableFlags = 0;      // 0x030044BC, gEntityDisableFlags & gEntityManager[kind].disableFlags != 0 のときはそのkindのEntityは更新しない, gEntityDisableFlagsの各bitは (1 << kind) ではなさそう
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

IWRAM_DATA struct Unk030046a4* gCollisionMap = NULL;  // Malloc(3620) で確保したバッファを指すポインタ (FUN_082326a0)
IWRAM_DATA s32 gMapBlockW = 0;                        // 0x030046A8
IWRAM_DATA s32 gMapBlockH = 0;                        // 0x030046AC

IWRAM_DATA u8 u8_030046b0[144] = {};  // todo

IWRAM_DATA LINK_MANAGER lman = {};  // 0x03004740

IWRAM_DATA bool32 bool32_03004788 = FALSE;  // 0x03004788

IWRAM_DATA u8 u8_0300478c[12] = {};
IWRAM_DATA u32 u32_03004798 = 0;
IWRAM_DATA u32 u32_0300479c = 0;
IWRAM_DATA u32 u32_030047a0 = 0;
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
