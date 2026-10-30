#include "camera.h"
#include "entity.h"
#include "game.h"
#include "gba/m4a_internal.h"
#include "global.h"
#include "input.h"
#include "particle.h"
#include "registry.h"
#include "solar_sensor.h"
#include "sound.h"
#include "sprite.h"
#include "struct.h"
#include "time.h"
#include "video.h"
#include "vm.h"

COMMON_DATA u8 u8_03003524[0x03003530 - 0x03003524] = {};  // todo

COMMON_DATA u32 gSpriteListIdx = 0;  // 0x03003530, 描画リストの選択 (0: 通常, 1: スタートメニュー中)

COMMON_DATA Procedure gDrawAuxSprites = NULL;  // 0x03003534, VideoRender_Update が1番目に呼ぶ描画パス, gAuxSpriteLists を辿る, 場面ごとに Video_SetDrawPasses が差し替え、止めるときは nop_0822b09c が入る
COMMON_DATA u8 u8_03003538[8] = {};            // 16byte alignment padding?

COMMON_DATA CameraCoords gCameraCoords = {};  // 0x03003540

COMMON_DATA Procedure gDrawParticles = NULL;    // 0x03003554, VideoRender_Update が3番目に呼ぶ描画パス, gParticleLists を辿る, 止めるときは nop_0822e738 が入る
COMMON_DATA Procedure gDrawMainSprites = NULL;  // 0x03003558, VideoRender_Update が2番目に呼ぶ描画パス, gMainSpriteLists を辿る
COMMON_DATA u8 u8_0300355c[4] = {};             // 16byte alignment padding?

COMMON_DATA AuxSprite* gAuxSpriteLists[2] = {};    // 0x03003560
COMMON_DATA MainSprite* gMainSpriteLists[2] = {};  // 0x03003568
COMMON_DATA Particle* gParticleLists[2] = {};      // 0x03003570, 根拠: Video_AddParticleIntoDrawList

COMMON_DATA s16 gAuxSpriteTileCount = 0;   // 0x03003578, このフレームに Video_AllocObjTiles が積んだ SpriteAux のタイル数, 根拠: CopyObjTileDataToVram が ldrsh で読んで DMA 先の起点計算に使う
COMMON_DATA u16 u16_0300357a = 0;          // todo
COMMON_DATA u16 gMainSpriteTileCount = 0;  // 0x0300357C, MainSprite_DrawInternal が積んだタイル数を加算していくが、読み出す箇所が見つかっていない
COMMON_DATA u16 u16_0300357e = 0;          // todo

COMMON_DATA u16 gObjPlttLen = 0;          // 0x03003580, = ObjPlttFile.length
COMMON_DATA rgb555* gObjPlttData = NULL;  // 0x03003584, = ObjPlttFile.body

COMMON_DATA s16 gObjTileCursor = 0;  // 0x03003588, 次に確保する OBJ VRAM のタイル番号 (上限 0x400), Video_ResetObjTileAlloc で gParticleFileTileCount に戻される

COMMON_DATA ParticleFile* gParticleFile = NULL;         // 0x0300358C, 現在ロードされているParticleFileへのポインタ, ParticleFile は ParticleFile0 しかないので NULL or &ParticleFile0 になるはず
COMMON_DATA u16 gObjTileRequestCount = 0;               // 0x03003590, gObjTileRequests に積まれている件数
COMMON_DATA ALIGNED(4) s16 gParticleFileTileCount = 0;  // 0x03003594, ParticleFile.tileCount のタイル数

COMMON_DATA u8* gAuxSpriteTiles = NULL;            // 0x03003598, &AuxSpriteFile + offsetToTiles
COMMON_DATA AuxSubsprite* gAuxSubsprites = NULL;   // 0x0300359C, &AuxSpriteFile + offsetToSubsprites
COMMON_DATA AuxSpriteFile* gAuxSpriteFile = NULL;  // 0x030035A0

COMMON_DATA u32 gMainSpriteTileRequestCount = 0;  // 0x030035A4, gMainSpriteTileRequests に積まれている件数
COMMON_DATA u8 u8_030035a8[8] = {};               // todo

// 根拠: Video_BuildOAM が 4 バイト刻みで 32 個まで読み、+0 を gSineTable の添字、+1/+2 を Div の除数にして OAM のアフィンパラメータを組む
COMMON_DATA ObjAffineParams gObjAffineParams[32] = {};  // 0x030035B0

COMMON_DATA OamData gOAMBuffer[128] = {};  // 0x03003630, OAM のバッファ

COMMON_DATA u16 gOAMPrioCounts[4] = {};  // 0x03003A30, 優先度ごとに積まれたスプライト数, 根拠: Video_BuildOAM が優先度順に gOAMBuffer へ並べ替えるのに使う

COMMON_DATA s32 gOAMCount = 0;  // 0x03003A38, gOAMBuffer に並べ終えたスプライト数, 根拠: Video_BuildOAM

COMMON_DATA s32 gStagedOAMCount = 0;  // 0x03003A3C, gStagedOAMBuffer に積まれたスプライト数, 根拠: Video_BuildOAM

// 描画パスが積む並べ替え前のスプライト, attr3 は本来のアフィン番号ではなく (優先度 << 8 | 次の要素の添字) として使われる
COMMON_DATA OamData gStagedOAMBuffer[128] = {};  // 0x03003A40, 根拠: Video_BuildOAM

COMMON_DATA s32 gObjAffineCount = 0;  // 0x03003E40, gObjAffineParams に積まれた件数 (32 で打ち止め), 根拠: Video_BuildOAM

COMMON_DATA u8 u8_03003e44[0x03003E50 - 0x03003E44] = {};  // todo
COMMON_DATA u16 gBgAffineAngle = 0;                        // 0x03003E50, BG のアフィン変換の角度 (gSineTable の添字), 根拠: Video_SetBGAffine
COMMON_DATA u8 u8_03003e52[0x03003E60 - 0x03003E52] = {};  // todo

COMMON_DATA void* gBGTileDataSrcAddrs[4] = {};  // 0x03003E60, BG ごとのタイルデータ転送元, 根拠: Video_RequestBGTileData

COMMON_DATA s16 gBgAffineMatrix[4] = {};  // 0x03003E70, BGnPA/PB/PC/PD の控え, StageBGRegs が gStagedBgAffineMatrix へ丸ごと写す

COMMON_DATA u16 gStagedDISPCNT = 0;  // 0x03003E78, Video_SetupBG / Video_SetupBGLayout が表示する BG のビットを立て、VideoCommit_Update が DISPCNT に流し込む

COMMON_DATA u8 u8_03003e7a[0x03003E80 - 0x03003E7A] = {};  // todo

COMMON_DATA u16 gBGTileDataTileCounts[4] = {};  // 0x03003E80, BG ごとの転送タイル枚数, 根拠: Video_RequestBGTileData

COMMON_DATA s16 gBgAffineCenterY = 0;                      // 0x03003E88, 根拠: Video_SetBGAffine が BGnY の算出に使う
COMMON_DATA u8 u8_03003e8a[2] = {};                        // todo
COMMON_DATA u16 gBg2AffineMode = 0;                        // 0x03003E8C, 0 なら StageBGRegs が BG2/BG3 のオフセットを積み, 0 以外なら控えの書き戻しを行う
COMMON_DATA u8 u8_03003e8e[0x03003E90 - 0x03003E8E] = {};  // todo
COMMON_DATA s16 gStagedBgAffineMatrix[4] = {};             // 0x03003E90, StageBGRegs が gBgAffineMatrix から写す先
COMMON_DATA s32 gBgAffineRefX = 0;                         // 0x03003E98, BGnX の控え, StageBGRegs が gStagedBgAffineRef[0] へ写す
COMMON_DATA s16 gBgAffineScaleY = 0;                       // 0x03003E9C, 8.8 固定小数の Y 倍率, Video_InitBGMode が 0x100 (等倍) を書く
COMMON_DATA u8 u8_03003e9e[0x03003EA0 - 0x03003E9E] = {};  // todo
COMMON_DATA s32 gBgAffineRefY = 0;                         // 0x03003EA0, BGnY の控え, StageBGRegs が gStagedBgAffineRef[1] へ写す
COMMON_DATA u8 u8_03003ea4[0x03003EA8 - 0x03003EA4] = {};  // todo

COMMON_DATA u16 gBGTileDataVramOffsets[4] = {};  // 0x03003EA8, BG ごとの転送先 VRAM オフセット, 根拠: Video_RequestBGTileData

COMMON_DATA s16 gBgAffineCenterX = 0;                      // 0x03003EB0, 根拠: Video_SetBGAffine が BGnX の算出に使う
COMMON_DATA u8 u8_03003eb2[2] = {};                        // todo
COMMON_DATA s16 gBgAffineScaleX = 0;                       // 0x03003EB4, 8.8 固定小数の X 倍率, Video_InitBGMode が 0x100 (等倍) を書く
COMMON_DATA u8 u8_03003eb6[0x03003EB8 - 0x03003EB6] = {};  // todo
COMMON_DATA u32 gStagedBgAffineRef[2] = {};                // 0x03003EB8, StageBGRegs が gBgAffineRefX / gBgAffineRefY から写す先
COMMON_DATA u16 gStagedBGOfs[8] = {};                      // 0x03003EC0, BG0HOFS..BG3VOFS に流し込む値の控え, BG ごとに (H, V) の順, 根拠: StageBGRegs

COMMON_DATA BgState gBgStates[4] = {};  // 0x03003ED0, BG0-3 の状態, 根拠: FUN_0822eef4, StageBGRegs (stride 0x30, +0x20/+0x22 を BGnHOFS/BGnVOFS に使う)

COMMON_DATA u16 gWIN0H = 0;  // 0x03003F90, WIN0H に書いた値の控え, 根拠: Video_SaveWindowRect / Video_RestoreWindowRect / Video_SetWindowRect

COMMON_DATA u8 u8_03003f92[0x03003F98 - 0x03003F92] = {};  // todo

COMMON_DATA u16 gWIN1V = 0;  // 0x03003F98, WIN1V に書いた値の控え

COMMON_DATA u8 u8_03003f9a[0x03003F9C - 0x03003F9A] = {};  // todo

COMMON_DATA u16 gWIN0V = 0;  // 0x03003F9C, WIN0V に書いた値の控え

COMMON_DATA u8 u8_03003f9e[0x03003FA8 - 0x03003F9E] = {};  // todo

COMMON_DATA u16 gWIN1H = 0;  // 0x03003FA8, WIN1H に書いた値の控え

COMMON_DATA u8 u8_03003faa[0x03003FB0 - 0x03003FAA] = {};  // todo

// idx は ((OAM1.14-15 << 2) | (OAM0.14-15)), ie. ((sizeidx << 2) | shape)
COMMON_DATA u8 gOAMTileHeightTable[16] = {};      // 0x03003FB0, タイル(8px)単位
COMMON_DATA u8 gOAMHeightTable[16] = {};          // 0x03003FC0, ピクセル単位
COMMON_DATA u8 gOAMTileCounts[16] = {};           // 0x03003FD0, タイル枚数
COMMON_DATA u8 gOAMTileWidthTable[16] = {};       // 0x03003FE0, タイル(8px)単位
COMMON_DATA u32 gOAMShapeSizeAttrTable[16] = {};  // 0x03003FF0, OAM0.14-15(shape) と OAM1.14-15(size) のビットを attr0|attr1<<16 形式で格納, AuxSprite_DrawInternal / MainSprite_DrawInternal が OR する
COMMON_DATA u8 gOAMWidthTable[16] = {};           // 0x03004030, ピクセル単位

COMMON_DATA s32 gBgBrightness = 0;          // 0x03004040, BG の明るさ, Q6(1) が等倍で 0 なら gBgPlttBlendColor 一色, ApplyBgPlttBlend が gBgBrightness2 と掛けて BG パレットに適用する, data3d.c も色のスケールに使う
COMMON_DATA s32 gObjPlttSlotCursor = 0;     // 0x03004044, gObjPlttSlotIDs の確保位置 (最大 16), ResetObjPlttSlotCursor が毎フレーム gObjPlttSlotReserved + 2 に戻す, 根拠: AllocBlendPlttSlot (AllocParticlePlttSlot は gObjPlttSlotCount の方を使う)
COMMON_DATA s32 gBgBrightnessApplied = 0;   // 0x03004048, ApplyBgPlttBlend が最後に適用した BG の明るさ, gObjBrightnessApplied の BG 版
COMMON_DATA s32 gObjBrightnessApplied = 0;  // 0x0300404C, FUN_0822d248 が最後に適用した gObjBrightness, 等倍のまま変わっていなければ加工を省くための控え

COMMON_DATA rgb555 gObjectPlttBuffer[256] = {};  // 0x03004050, CommitPalette で OBJ_PLTT にコピーされる
COMMON_DATA rgb555 gBgPlttBuffer[256] = {};      // 0x03004250, BG パレットの作業用バッファ, ゲーム側はここに書き、加工が要らなければこのまま CommitPalette の転送元になる

COMMON_DATA s32 gObjPlttSlotReserved = 0;  // 0x03004450, ResetObjPlttSlotCursor が gObjPlttSlotCursor = これ + 2 として 0 に戻す
COMMON_DATA u16 gBgPlttFadeRowMask = 0;    // 0x03004454, bit i が立っているパレット行だけ ApplyBgPlttBlend が明るさ・ブレンドを掛ける
COMMON_DATA u8 u8_03004456[2] = {};        // todo

COMMON_DATA s32 gObjPlttSlotCount = 0;  // 0x03004458, 確保済みの OBJ パレットスロット数 (最大 2), 根拠: AllocParticlePlttSlot

COMMON_DATA s32 gObjBrightness = 0;  // 0x0300445C, OBJ の明るさ, Q6(1) が等倍で 0 なら gObjPlttBlendColor 一色, FUN_0822d248 が OBJ パレットに適用する, 掛ける相手はなく1本だけ

COMMON_DATA s32 gBgBrightness2 = 0;  // 0x03004460, BG の明るさのもう一方の係数, gBgBrightness と独立に暗くしたい演出 (BgPlttDimmer 等) が使う

COMMON_DATA rgb555 gObjPlttBlendColor = 0;  // 0x03004464, FUN_0822d248 が OBJ の各色をこの色へ寄せる, gBgPlttBlendColor の OBJ 版, 書き手: Entity6978 / Entity4DDF などのフェード

COMMON_DATA u8 u8_03004466[2] = {};  // todo

COMMON_DATA rgb555* gBGPlttBufferPointer = NULL;  // 0x03004468

COMMON_DATA s32 gGrayscaleTimer = 0;  // 0x0300446C

COMMON_DATA u16 gObjPlttSlotIDs[16] = {};  // 0x03004470, 各 OBJ パレットスロットに割り当てたパレット ID, 根拠: AllocParticlePlttSlot (2 個まで), AllocBlendPlttSlot (16 個まで)

COMMON_DATA u16 gObjPlttFadeSkipMask = 0;  // 0x03004490, FUN_0822d248 のフェードから除外する OBJ パレットを選ぶ, bit0 で ID 0x1D/0x26/0x27/0x117, bit1 で 0x2A9/0x27A を素通しにする, 書き手: Entity6978 ('.params[4]')

COMMON_DATA u8 u8_03004492[2] = {};     // todo
COMMON_DATA u16 gBgPlttBlendColor = 0;  // 0x03004494, ApplyBgPlttBlend が各色をこの色へ寄せる, 0 なら明るさだけ掛ける, 書き手: MapPltt_FadeOut (明転の完了時に RGB(4, 4, 4)), ResetPltt
COMMON_DATA u8 u8_03004496[2] = {};     // todo

COMMON_DATA u8 gMosaicTargets = 0;                       // 0x03004498, bit0-3: BG0-3 の BGnCNT.6 を立てる, bit4: MOSAIC の OBJ 側(bit8-15)も書く, 根拠: Video_ApplyMosaic
COMMON_DATA u8 u8_03004499[3] = {};                      // todo
COMMON_DATA u16 gMosaicDirty = 0;                        // 0x0300449C, 1 なら次の Video_ApplyMosaic で I/O に反映して 0 に戻す
COMMON_DATA u16 u16_0300449e = 0;                        // todo
COMMON_DATA u32 gHBlankEffectBG = 0;                     // 0x030044A0, HBlankエフェクトの対象BG番号, 根拠: FUN_0822f0d8
COMMON_DATA void* gHBlankEffectTable = NULL;             // 0x030044A4, スキャンライン毎の値のテーブル, 根拠: FUN_0822eef4
COMMON_DATA s32 gHBlankEffectKind = 0;                   // 0x030044A8, HBlankエフェクトの種類 (0:BGnHOFS, 1:BGnVOFS, 2:MOSAIC, 3:BLDY), 根拠: FUN_0822f0d8
COMMON_DATA u32 gObjBlendEnabled = 0;                    // 0x030044AC, 0以外なら flags bit14 のスプライトを半透明にする, 根拠: MainSprite_DrawInternal
COMMON_DATA u8 gObjMosaicEnabled = 0;                    // 0x030044B0, bit0 が立っているスプライトだけ OAM attr0.12 (mosaic) を立てる, 根拠: MainSprite_DrawInternal / AuxSprite_DrawInternal
COMMON_DATA u8 u8_030044b1[3] = {};                      // todo
COMMON_DATA u16 gMosaicSize = 0;                         // 0x030044B4, MOSAIC レジスタに書く値 (bit0-3: BG H, bit4-7: BG V, bit8-11: OBJ H, bit12-15: OBJ V)
COMMON_DATA u16 u16_030044b6 = 0;                        // todo
COMMON_DATA u16 u16_030044b8 = 0;                        // 0x030044B8
COMMON_DATA EntityDisableFlags gEntityDisableFlags = 0;  // 0x030044BC, gEntityDisableFlags & gEntityManager[kind].disableFlags != 0 のときはそのkindのEntityは更新しない, gEntityDisableFlagsの各bitは (1 << kind) ではなさそう
COMMON_DATA u16 gEntityCount = 0;
COMMON_DATA u8 u8_030044c2[0x44D0 - 0x44C2] = {};          // todo
COMMON_DATA bool32 gUseLinkInput = FALSE;                  // 0x030044D0, TRUE なら ReadKeyInput が通信で受け取ったキー (gLinkKeyInput) から gInput を作る
COMMON_DATA u8 u8_030044d4[0x44E0 - 0x44D4] = {};          // todo
COMMON_DATA Input gInput[5] = {};                          // 0x030044E0
COMMON_DATA Keys16 gRawKeyInput = 0;                       // 0x03004508, ReadKeyInput が読んだ KEYINPUT の生の値 (active low), 通信対戦時は | 0x2000 して相手に送る (FUN_0804d698)
COMMON_DATA u8 padding_0300450a[0x4510 - 0x450A] = {};     // padding (Unused)
COMMON_DATA Keys16 gLinkKeyInput[5] = {};                  // 0x03004510, 通信で受け取った各プレイヤーのキー (KEYINPUT と同じ active low), 0xFFFF はデータなし
COMMON_DATA u32 gRngValue = 0;                             // 0x0300451C
COMMON_DATA EntityList gEntityManager[ENTITY_KINDS] = {};  // 0x03004520
COMMON_DATA s32 gRegistryCount = 0;
COMMON_DATA u32 gScriptDirectoryBuildTime = 0;  // 0x03004594, ScriptDirectory.buildTime
COMMON_DATA u8 u8_03004598[8] = {};             // todo
COMMON_DATA VM gVM = {};                        // 0x030045A0

COMMON_DATA Scratch* gScratch = NULL;      // 0x03004690
COMMON_DATA World* gWorldBackup = NULL;    // 0x03004694
COMMON_DATA World* gWorld = NULL;          // 0x03004698
COMMON_DATA GameInfo* gStatBackup = NULL;  // 0x0300469C
COMMON_DATA GameInfo* gStat = NULL;        // 0x030046A0

COMMON_DATA struct CollisionMapData* gCollisionMap = NULL;  // Malloc(3620) で確保したバッファを指すポインタ (Map_InitCollisionMap)
COMMON_DATA s32 gMapBlockW = 0;                             // 0x030046A8
COMMON_DATA s32 gMapBlockH = 0;                             // 0x030046AC
COMMON_DATA u32 gNextMapEventID = 0;                        // 0x030046B0, Map_InsertEvent が CollisionMapEvent.id に払い出す連番, 0 は使わない

COMMON_DATA s32 gRandTableIdx2 = 0;  // 0x030046B4, 通信対戦のスコア精算で使用する乱数テーブルのインデックス
COMMON_DATA s32 gRandTableIdx = 0;   // 0x030046B8

COMMON_DATA u16 gSioParentRecv = 0;  // 0x030046BC, 親が受け取った子のデータ (SIOMULTI1)
