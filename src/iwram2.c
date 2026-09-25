#include "camera.h"
#include "entity.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "input.h"
#include "particle.h"
#include "save.h"
#include "solar_sensor.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "video.h"
#include "vm.h"

struct Dvalinn;
struct Entity5941;
struct EntityCBB0;
struct EnemyManager;
struct Entity9A9F;
struct Player;
struct CollisionMapData;

IWRAM_DATA u32 u32_03002b54 = 0;                    // gUnkEntity1Ptr_03002b58 と同じ場所っぽい, rfu_syncVBlank の戻り値が入る
IWRAM_DATA Entity* gUnkEntity1Ptr_03002b58 = NULL;  // 0x03002B58, Malloc(908) で確保したバッファを指すポインタ, RFU関連? (FUN_0804e2c0)

IWRAM_DATA u8 u8_03002b5c[36] = {};            // todo
IWRAM_DATA u16 u16_03002b80 = 0;               // 0x03002B80, ApplyLxModifiers が 1 なら太陽レベル +4、2 なら日光なしにする
IWRAM_DATA u8 u8_03002b82[22] = {};            // todo
IWRAM_DATA u16 gPlayerCount = 0;               // Playerの数, シングルプレイ中は1, 通信対戦中時は参加人数になる
IWRAM_DATA u8 u8_03002b9a[38] = {};            // todo
IWRAM_DATA u32 u32_03002bc0 = 0;               // 0x03002BC0, ビットフラグ, FUN_080093f8 が bit0 と bit1-2 を見る
IWRAM_DATA u8 u8_03002bc4[28] = {};            // todo
IWRAM_DATA struct Player* gPlayerPtr[4] = {};  // 0x03002BE0, 通信対戦時に自分が子機の場合も自キャラが 0 になるかは不明
IWRAM_DATA u8 u8_03002bf0[8] = {};             // todo

IWRAM_DATA struct Entity5941* gEntity5941 = NULL;  // 0x03002BF8

IWRAM_DATA u8 u8_03002bfc[0x03002C58 - 0x03002bfc] = {};  // todo

IWRAM_DATA struct EntityCBB0* gEntityCBB0 = NULL;  // 0x03002C58

IWRAM_DATA struct EnemyManager* gEnemyManager = NULL;    // 0x03002C5C
IWRAM_DATA struct EnemyListNode* gEnemyListHead = NULL;  // 0x03002C60, 生存中のエネミーの単方向リスト. EnemyManager.list と同じ値
IWRAM_DATA struct LinkConnect* gLinkConnect = NULL;      // 0x03002C64
IWRAM_DATA struct Entity9A9F* gEntity9A9F = NULL;        // 0x03002C68

IWRAM_DATA u8 u8_03002c6c[0x03002C80 - 0x03002C6C] = {};  // todo

IWRAM_DATA struct Dvalinn* gDvalinn = NULL;  // 0x03002C80

IWRAM_DATA u8 u8_03002c84[0x03002CA0 - 0x03002C84] = {};  // todo

IWRAM_DATA vu16* gHBlankEffectReg = NULL;  // 0x03002CA0, HBlank 毎に gHBlankEffectBuffer の値を書き込む I/O レジスタ, 根拠: FUN_0822f0d8, FUN_0822eef4

IWRAM_DATA s32 gOamDirty = 0;  // 0x03002CA4, MainSprite_DrawInternal / FUN_0822db5c が bit0 を立て、VideoCommit_Update が gOAMBuffer を OAM へ転送して落とす。bit0 以外は使われていない

IWRAM_DATA s32 s32_03002ca8 = 0;  // 0x03002CA8, 0 以外だと VideoCommit_Update が DISPCNT の表示ビットを組み直さない

IWRAM_DATA u8 u8_03002cac[0x03002CB0 - 0x03002CAC] = {};  // todo

IWRAM_DATA IntrFunc gIntrTable[13] = {};  // 0x03002cb0
IWRAM_DATA vu32 gVblankFlag = FALSE;      // 0x03002cb4
IWRAM_DATA u8 u8_03002ce8[8] = {};        // todo
IWRAM_DATA u32 gFrameCounter = 0;         // 0x03002CF0, bit0 が点滅の偶奇を決める, 根拠: MainSprite_DrawList が tst #1 で SPRFLAG_BLINK_ODD / SPRFLAG_BLINK_EVEN を選ぶ
IWRAM_DATA u8 u8_03002cf4[12] = {};       // todo

IWRAM_DATA u32 IntrMain_Buffer[0x200] = {0};  // 0x03002D00, INTR_MAIN のRAMコード

IWRAM_DATA s32 s32_03003500 = 0;  // 0x03003500, VBlankIntr が書き、VideoCommit_Update が 0 に戻す

IWRAM_DATA u8 u8_03003504[0x03003510 - 0x03003504] = {};  // todo

IWRAM_DATA u16 u16_03003510 = 0;             // 0x03003510, FUN_0822f0d8, FUN_0822eef4 が 1 を書く
IWRAM_DATA u8 u8_03003512[2] = {};           // todo
IWRAM_DATA u16 u16_03003514 = 0;             // 0x03003514, FUN_0822f0d8 は 0、FUN_0822eef4 は 1 を書く
IWRAM_DATA u8 u8_03003516[2] = {};           // todo
IWRAM_DATA u16* gHBlankEffectBuffer = NULL;  // 0x03003518, スキャンライン毎(160 ライン)の値のバッファ (= u8_ARRAY_02036c00), 根拠: FUN_0822f0d8, FUN_0822eef4

IWRAM_DATA u16 u16_0300351c = 0;                          // 0x0300351C, EEPROM_BeginAccess (EEPROM アクセス前) が 0、EEPROM_EndAccess (アクセス後) が 1 を書く
IWRAM_DATA u8 u8_0300351e[0x03003530 - 0x0300351E] = {};  // todo

IWRAM_DATA u32 gSpriteListIdx = 0;  // 0x03003530, 描画リストの選択 (0: 通常, 1: スタートメニュー中)

IWRAM_DATA Procedure gDrawAuxSprites = NULL;  // 0x03003534, VideoRender_Update が1番目に呼ぶ描画パス。gAuxSpriteLists を辿る。場面ごとに Video_SetDrawPasses が差し替え、止めるときは nop_0822b09c が入る
IWRAM_DATA u8 u8_03003538[8] = {};            // 16byte alignment padding?

IWRAM_DATA CameraCoords gCameraCoords = {};  // 0x03003540

IWRAM_DATA Procedure gDrawParticles = NULL;    // 0x03003554, VideoRender_Update が3番目に呼ぶ描画パス。gParticleLists を辿る。止めるときは nop_0822e738 が入る
IWRAM_DATA Procedure gDrawMainSprites = NULL;  // 0x03003558, VideoRender_Update が2番目に呼ぶ描画パス。gMainSpriteLists を辿る
IWRAM_DATA u8 u8_0300355c[4] = {};             // 16byte alignment padding?

IWRAM_DATA AuxSprite* gAuxSpriteLists[2] = {};    // 0x03003560
IWRAM_DATA MainSprite* gMainSpriteLists[2] = {};  // 0x03003568
IWRAM_DATA Particle* gParticleLists[2] = {};      // 0x03003570, 根拠: Video_AddParticleIntoDrawList

IWRAM_DATA u16 gAuxSpriteTileCount = 0;  // 0x03003578, このフレームに FUN_0822b270 が積んだアクタースプライトのタイル数, 根拠: FUN_0822b308 が DMA 先の起点計算に使う
IWRAM_DATA u16 u16_0300357a = 0;         // todo
IWRAM_DATA u16 u16_0300357c = 0;         // 0x0300357C, MainSprite_DrawInternal が積んだタイル数を加算していくが、読み出す箇所が見つかっていない
IWRAM_DATA u16 u16_0300357e = 0;         // todo

IWRAM_DATA u16 gObjPlttLen = 0;          // 0x03003580, = ObjPlttFile.length
IWRAM_DATA rgb555* gObjPlttData = NULL;  // 0x03003584, = ObjPlttFile.body

IWRAM_DATA s16 gObjTileCursor = 0;  // 0x03003588, 次に確保する OBJ VRAM のタイル番号 (上限 0x400). Video_ResetObjTileAlloc で gParticleFileTileCount に戻される

IWRAM_DATA ParticleFile* gParticleFile = NULL;         // 0x0300358C, 現在ロードされているParticleFileへのポインタ, ParticleFile は ParticleFile0 しかないので NULL or &ParticleFile0 になるはず
IWRAM_DATA u16 gParticle_03003590 = 0;                 // 0x03003590, まだ不明
IWRAM_DATA ALIGNED(4) s16 gParticleFileTileCount = 0;  // 0x03003594, ParticleFile.tileCount のタイル数

IWRAM_DATA u8* gAuxSpriteTiles = NULL;            // 0x03003598, &AuxSpriteFile + offsetToTiles
IWRAM_DATA AuxSubsprite* gAuxSubsprites = NULL;   // 0x0300359C, &AuxSpriteFile + offsetToSubsprites
IWRAM_DATA AuxSpriteFile* gAuxSpriteFile = NULL;  // 0x030035A0

IWRAM_DATA u8 u8_030035A4[140] = {};  // todo

IWRAM_DATA OamData gOAMBuffer[128] = {};  // 0x03003630, OAM のバッファ

IWRAM_DATA u16 u16_ARRAY_03003a30[4] = {};  // 0x03003A30, Video_ResetFrameState が毎フレーム 0 に戻す

IWRAM_DATA s32 s32_03003a38 = 0;  // 0x03003A38, Video_ResetFrameState が毎フレーム 0 に戻す

IWRAM_DATA s32 s32_03003a3c = 0;  // 0x03003A3C, Video_ResetFrameState が毎フレーム 0 に戻す

IWRAM_DATA u8 u8_03003a40[0x03003E40 - 0x03003A40] = {};  // todo

IWRAM_DATA s32 s32_03003e40 = 0;  // 0x03003E40, Video_ResetFrameState が毎フレーム 0 に戻す

IWRAM_DATA u8 u8_03003e44[0x03003E60 - 0x03003E44] = {};  // todo

IWRAM_DATA void* gBGTileDataSrcAddrs[4] = {};  // 0x03003E60, BG ごとのタイルデータ転送元, 根拠: FUN_0822b9d4

IWRAM_DATA u8 u8_03003e70[0x03003E78 - 0x03003E70] = {};  // todo

IWRAM_DATA u16 gStagedDISPCNT = 0;  // 0x03003E78, Video_SetupBG / Video_SetupBGLayout が表示する BG のビットを立て、VideoCommit_Update が DISPCNT に流し込む

IWRAM_DATA u8 u8_03003e7a[0x03003E80 - 0x03003E7A] = {};  // todo

IWRAM_DATA u16 gBGTileDataTileCounts[4] = {};  // 0x03003E80, BG ごとの転送タイル枚数, 根拠: FUN_0822b9d4

IWRAM_DATA u8 u8_03003e88[0x03003EA8 - 0x03003E88] = {};  // todo

IWRAM_DATA u16 gBGTileDataVramOffsets[4] = {};  // 0x03003EA8, BG ごとの転送先 VRAM オフセット, 根拠: FUN_0822b9d4

IWRAM_DATA u8 u8_03003eb0[0x03003ED0 - 0x03003EB0] = {};  // todo

IWRAM_DATA BgState gBgStates[4] = {};  // 0x03003ED0, BG0-3 の状態, 根拠: FUN_0822eef4, StageBGRegs (stride 0x30, +0x20/+0x22 を BGnHOFS/BGnVOFS に使う)

IWRAM_DATA u16 gWIN0H = 0;  // 0x03003F90, WIN0H に書いた値の控え, 根拠: Video_SaveWindowRect / Video_RestoreWindowRect / Video_SetWindowRect

IWRAM_DATA u8 u8_03003f92[0x03003F98 - 0x03003F92] = {};  // todo

IWRAM_DATA u16 gWIN1V = 0;  // 0x03003F98, WIN1V に書いた値の控え

IWRAM_DATA u8 u8_03003f9a[0x03003F9C - 0x03003F9A] = {};  // todo

IWRAM_DATA u16 gWIN0V = 0;  // 0x03003F9C, WIN0V に書いた値の控え

IWRAM_DATA u8 u8_03003f9e[0x03003FA8 - 0x03003F9E] = {};  // todo

IWRAM_DATA u16 gWIN1H = 0;  // 0x03003FA8, WIN1H に書いた値の控え

IWRAM_DATA u8 u8_03003faa[0x03003FB0 - 0x03003FAA] = {};  // todo

// idx は ((OAM1.14-15 << 2) | (OAM0.14-15)), ie. ((sizeidx << 2) | shape)
IWRAM_DATA u8 gOAMTileHeightTable[16] = {};      // 0x03003FB0, タイル(8px)単位
IWRAM_DATA u8 gOAMHeightTable[16] = {};          // 0x03003FC0, ピクセル単位
IWRAM_DATA u8 gOAMTileCounts[16] = {};           // 0x03003FD0, タイル枚数
IWRAM_DATA u8 gOAMTileWidthTable[16] = {};       // 0x03003FE0, タイル(8px)単位
IWRAM_DATA u32 gOAMShapeSizeAttrTable[16] = {};  // 0x03003FF0, OAM0.14-15(shape) と OAM1.14-15(size) のビットを attr0|attr1<<16 形式で格納, AuxSprite_DrawInternal / MainSprite_DrawInternal が OR する
IWRAM_DATA u8 gOAMWidthTable[16] = {};           // 0x03004030, ピクセル単位

IWRAM_DATA s32 s32_03004040 = 0;        // 0x03004040, MapPltt_FadeIn / MapPltt_FadeOut が明るさとして書く
IWRAM_DATA s32 gObjPlttSlotCursor = 0;  // 0x03004044, gObjPlttSlotIDs の確保位置 (最大 16)。FUN_0822d114 が毎フレーム s32_03004450 + 2 に戻す, 根拠: FUN_0822d190 (FUN_0822d12c は gObjPlttSlotCount の方を使う)
IWRAM_DATA s32 s32_03004048 = 0;        // 0x03004048, Entity4AE5_Init が 0x40 を書く
IWRAM_DATA s32 s32_0300404c = 0;        // 0x0300404C, FUN_0822d014 が 0x40 を書く

IWRAM_DATA rgb555 gObjectPlttBuffer[256] = {};  // 0x03004050, CommitPalette で OBJ_PLTT にコピーされる
IWRAM_DATA rgb555 gBgPlttBuffer[256] = {};      // 0x03004250, BG パレットの作業用バッファ。ゲーム側はここに書き、加工が要らなければこのまま CommitPalette の転送元になる

IWRAM_DATA s32 s32_03004450 = 0;        // 0x03004450, FUN_0822d114 が gObjPlttSlotCursor = これ + 2 として 0 に戻す
IWRAM_DATA u16 gBgPlttFadeRowMask = 0;  // 0x03004454, bit i が立っているパレット行だけ FUN_0822d630 が明るさ・ブレンドを掛ける, 書き手: Entity4AE5_Init/Update
IWRAM_DATA u8 u8_03004456[2] = {};      // todo

IWRAM_DATA s32 gObjPlttSlotCount = 0;  // 0x03004458, 確保済みの OBJ パレットスロット数 (最大 2), 根拠: FUN_0822d12c

IWRAM_DATA s32 s32_0300445c = 0;  // 0x0300445C, FUN_0822d014 が 0x40 を書く

IWRAM_DATA s32 s32_03004460 = 0;  // 0x03004460, FUN_0822d630 が明るさ係数の一方として読む

IWRAM_DATA u16 u16_03004464 = 0;  // 0x03004464, FUN_0822d014 が 0x1084 を書く

IWRAM_DATA u8 u8_03004466[2] = {};  // todo

IWRAM_DATA rgb555* gBGPlttBufferPointer = NULL;  // 0x03004468

IWRAM_DATA s32 s32_0300446c = 0;  // 0x0300446C

IWRAM_DATA u16 gObjPlttSlotIDs[16] = {};  // 0x03004470, 各 OBJ パレットスロットに割り当てたパレット ID, 根拠: FUN_0822d12c (2 個まで), FUN_0822d190 (16 個まで)

IWRAM_DATA u16 u16_03004490 = 0;  // 0x03004490, FUN_0822d014 が 0 を書く

IWRAM_DATA u8 u8_03004492[2] = {};     // todo
IWRAM_DATA u16 gBgPlttBlendColor = 0;  // 0x03004494, FUN_0822d630 が各色をこの色へ寄せる。0 なら明るさだけ掛ける, 書き手: MapPltt_FadeOut (明転の完了時に 0x1084), FUN_0822d014
IWRAM_DATA u8 u8_03004496[2] = {};     // todo

IWRAM_DATA u8 gMosaicTargets = 0;                       // 0x03004498, bit0-3: BG0-3 の BGnCNT.6 を立てる, bit4: MOSAIC の OBJ 側(bit8-15)も書く, 根拠: Video_ApplyMosaic
IWRAM_DATA u8 u8_03004499[3] = {};                      // todo
IWRAM_DATA u16 gMosaicDirty = 0;                        // 0x0300449C, 1 なら次の Video_ApplyMosaic で I/O に反映して 0 に戻す
IWRAM_DATA u16 u16_0300449e = 0;                        // todo
IWRAM_DATA u32 gHBlankEffectBG = 0;                     // 0x030044A0, HBlankエフェクトの対象BG番号, 根拠: FUN_0822f0d8
IWRAM_DATA void* gHBlankEffectTable = NULL;             // 0x030044A4, スキャンライン毎の値のテーブル, 根拠: FUN_0822eef4
IWRAM_DATA s32 gHBlankEffectKind = 0;                   // 0x030044A8, HBlankエフェクトの種類 (0:BGnHOFS, 1:BGnVOFS, 2:MOSAIC, 3:BLDY), 根拠: FUN_0822f0d8
IWRAM_DATA u32 gObjBlendEnabled = 0;                    // 0x030044AC, 0以外なら flags bit14 のスプライトを半透明にする, 根拠: MainSprite_DrawInternal
IWRAM_DATA u8 gObjMosaicEnabled = 0;                    // 0x030044B0, bit0 が立っているスプライトだけ OAM attr0.12 (mosaic) を立てる, 根拠: MainSprite_DrawInternal / AuxSprite_DrawInternal
IWRAM_DATA u8 u8_030044b1[3] = {};                      // todo
IWRAM_DATA u16 gMosaicSize = 0;                         // 0x030044B4, MOSAIC レジスタに書く値 (bit0-3: BG H, bit4-7: BG V, bit8-11: OBJ H, bit12-15: OBJ V)
IWRAM_DATA u16 u16_030044b6 = 0;                        // todo
IWRAM_DATA u16 u16_030044b8 = 0;                        // 0x030044B8
IWRAM_DATA EntityDisableFlags gEntityDisableFlags = 0;  // 0x030044BC, gEntityDisableFlags & gEntityManager[kind].disableFlags != 0 のときはそのkindのEntityは更新しない, gEntityDisableFlagsの各bitは (1 << kind) ではなさそう
IWRAM_DATA u16 gEntityCount = 0;
IWRAM_DATA u8 u8_030044c2[0x44D0 - 0x44C2] = {};          // todo
IWRAM_DATA bool32 gUseLinkInput = FALSE;                  // 0x030044D0, TRUE なら ReadKeyInput が通信で受け取ったキー (gLinkKeyInput) から gInput を作る
IWRAM_DATA u8 u8_030044d4[0x44E0 - 0x44D4] = {};          // todo
IWRAM_DATA Input gInput[5] = {};                          // 0x030044E0
IWRAM_DATA Keys16 gRawKeyInput = 0;                       // 0x03004508, ReadKeyInput が読んだ KEYINPUT の生の値 (active low), 通信対戦時は | 0x2000 して相手に送る (FUN_0804d698)
IWRAM_DATA u8 padding_0300450a[0x4510 - 0x450A] = {};     // padding (Unused)
IWRAM_DATA Keys16 gLinkKeyInput[5] = {};                  // 0x03004510, 通信で受け取った各プレイヤーのキー (KEYINPUT と同じ active low), 0xFFFF はデータなし
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

IWRAM_DATA struct CollisionMapData* gCollisionMap = NULL;  // Malloc(3620) で確保したバッファを指すポインタ (FUN_082326a0)
IWRAM_DATA s32 gMapBlockW = 0;                             // 0x030046A8
IWRAM_DATA s32 gMapBlockH = 0;                             // 0x030046AC
IWRAM_DATA u32 u32_030046b0 = 0;                           // 0x030046B0

IWRAM_DATA u32 gRandTableIdx2 = 0;  // 0x030046B4
IWRAM_DATA u32 gRandTableIdx = 0;   // 0x030046B8

IWRAM_DATA u16 gSioParentRecv = 0;       // 0x030046BC, 親が受け取った子のデータ (SIOMULTI1)
IWRAM_DATA s32 gSioTimerIntrCount = 0;   // 0x030046C0, 親のタイマー3割り込み回数
IWRAM_DATA u32 u32_030046c4 = 0;         // 0x030046C4
IWRAM_DATA s32 gSioSerialIntrCount = 0;  // 0x030046C8, 子のシリアル割り込み回数
IWRAM_DATA s32 gSioMultiId = 0;          // 0x030046CC, 0 = 親, 1 = 子, -1 = 未確定
IWRAM_DATA u16 gSioChildRecv = 0;        // 0x030046D0, 子が受け取った親のデータ (SIOMULTI0)
IWRAM_DATA s32 gSioStatus = 0;           // 0x030046D4, 負ならエラー

IWRAM_DATA u8 u8_030046d8[0x740 - 0x6D8] = {};  // todo

IWRAM_DATA LINK_MANAGER lman = {};  // 0x03004740

IWRAM_DATA bool32 bool32_03004788 = FALSE;  // 0x03004788

IWRAM_DATA u8 u8_0300478c[12] = {};
IWRAM_DATA u32 u32_03004798 = 0;
IWRAM_DATA u32 u32_0300479c = 0;
IWRAM_DATA u32 u32_030047a0 = 0;
IWRAM_DATA u32 gFlag030047a4 = 0;

IWRAM_DATA SystemSaveData* gSystemSaveData = NULL;
IWRAM_DATA u8 u8_030047ac[8] = {};            // todo
IWRAM_DATA u32 u32_030047b4 = 0;              // 0x030047B4, Save_WriteCore でセーブ成功時に 1 がセットされる
IWRAM_DATA bool32 gSoftResetInhibit = FALSE;  // 0x030047B8, 立てたフレームはソフトリセットのコマンド判定を飛ばす。Entity0823acbc_Update が読んで 0 に戻す
IWRAM_DATA u32 u32_030047bc = 0;              // 0x030047BC, Entity0823acbc_Update が ENTITY_DISABLE_1 が落ちている間だけ毎フレーム +1 する。読み手は未発見
IWRAM_DATA u32 u32_030047c0 = 0;              // 0x030047C0, FUN_0823ACBC と FUN_0823CD04 の一括クリアでしか触られない。読み手も本来の書き手も未発見
IWRAM_DATA u32 u32_030047c4 = 0;              // 0x030047C4, Entity0823acbc_Update が 0 を書くほかは一括クリアのみ。読み手は未発見
