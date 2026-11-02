#include "bg_pltt.h"
#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "tilemap.h"

// 通信対戦のスコア精算画面, 稼いだ点を1フレームずつ所持スコアへ移していく
typedef struct Entity501B {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  MainSprite digits[8];                        // 0x018, [0..3] が上段 (y=0x40), [4..7] が下段 (y=0x78), 各段とも [0] が1の位
  MainSpriteGfx gfx;                           // 0x318, SPRITE_UI_LINK
  u8 unk_338[0x358 - 0x338];                   // 0x338, まだ未解析
  MainSpriteGfxFile* file;                     // 0x358, SPRITE_SOLAR_STATION
  u8 unk_35c[4];                               // 0x35C, まだ未解析
  u16 poses[8];                                // 0x360, digits ごとの MainSprite_Add のポーズ番号
  AuxSprite solarStandSpr;                     // 0x370
  AuxSpriteGfx solarStandGfx;                  // 0x39C, SPRITE_SOLAR_STATION
  u8 unk_3b8[2];                               // 0x3B8, まだ未解析
  s16 timer;                                   // 0x3BA, 90 から毎フレーム減り, 0 で次の状態へ, ボタンで 1 に飛ばせる
  u16 score;                                   // 0x3BC, gEntity9A9F->unk_138[playerIdx] (9999 で頭打ち), 精算で減っていく
  s16 step;                                    // 0x3BE, 1フレームに score から gStat->field_0x912 へ移す量, 初期 2, ボタンで <<3
  s32 unk_3c0;                                 // 0x3C0, gEntity9A9F->unk_144[playerIdx] (±9999 で頭打ち)
  Tilemaps* tilemap0;                          // 0x3C4, TILEMAP_CD91 を BG2 に敷く
  Tilemaps* tilemap1;                          // 0x3C8, TILEMAP_A413 を BG0 に敷く
  rgb555* bgPltt;                              // 0x3CC, bg_link_col_arr
  void (*updateCallback)(struct Entity501B*);  // 0x3D0
  u8* unk_3d4;                                 // 0x3D4, '.s', TextPanel_SetScript に渡す
  u8* unk_3d8;                                 // 0x3D8, '.e'
  u32 flags;                                   // 0x3DC, bit0 を立てて step の <<3 を一度だけにする
  s32 textPanels[2];                           // 0x3E0, TextPanel_Create の戻り値
  u8 phase;                                    // 0x3E8, 状態を切り替えるたびに 0/1/2/3 が入る
  bool8 entered;                               // 0x3E9, 状態に入った最初のフレームだけ立つ, 各状態が初期化を済ませて 0 に戻す
  u16 stateTimer;                              // 0x3EA, 状態に入ってからのフレーム数
} Entity501B;
static_assert(sizeof(Entity501B) == 1004);

NAKED void Entity501B_InitBg(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitBg.inc"); }

NAKED void Entity501B_InitTextPanels(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitTextPanels.inc"); }

NAKED void Entity501B_HideTextPanels(Entity501B* p) { INCFUNC("asm/func/Entity501B_HideTextPanels.inc"); }

NAKED BgMapEntry* Entity501B_GetBgMapAddr(s32 bg, s32 x, s32 y) { INCFUNC("asm/func/Entity501B_GetBgMapAddr.inc"); }

NAKED void Entity501B_DrawBgNumber(s32 value, s32 divisor, s32 x, s32 y) { INCFUNC("asm/func/Entity501B_DrawBgNumber.inc"); }

NAKED void Entity501B_InitAuxSprite(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitAuxSprite.inc"); }

NAKED void Entity501B_RemoveAuxSprite(Entity501B* p) { INCFUNC("asm/func/Entity501B_RemoveAuxSprite.inc"); }

NAKED void Entity501B_InitSprites(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitSprites.inc"); }

NAKED void Entity501B_InitSpritePos(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitSpritePos.inc"); }

NAKED void Entity501B_HideSprites(Entity501B* p) { INCFUNC("asm/func/Entity501B_HideSprites.inc"); }

NAKED void Entity501B_RemoveSprites(Entity501B* p) { INCFUNC("asm/func/Entity501B_RemoveSprites.inc"); }

NAKED void Entity501B_SetNumber(Entity501B* p, s32 row, s32 value) { INCFUNC("asm/func/Entity501B_SetNumber.inc"); }

NAKED void Entity501B_SpinNumber(Entity501B* p, s32 row) { INCFUNC("asm/func/Entity501B_SpinNumber.inc"); }

NAKED void FUN_081e02ac(Entity501B* p) { INCFUNC("asm/func/FUN_081e02ac.inc"); }

NAKED void FUN_081e02ec(Entity501B* p) { INCFUNC("asm/func/FUN_081e02ec.inc"); }

NAKED void Entity501B_LoadScore(Entity501B* p) { INCFUNC("asm/func/Entity501B_LoadScore.inc"); }

NAKED void FUN_081e03d8(Entity501B* p) { INCFUNC("asm/func/FUN_081e03d8.inc"); }

NAKED void FUN_081e04a8(Entity501B* p) { INCFUNC("asm/func/FUN_081e04a8.inc"); }

NAKED void FUN_081e0544(Entity501B* p) { INCFUNC("asm/func/FUN_081e0544.inc"); }

NAKED void FUN_081e0588(Entity501B* p) { INCFUNC("asm/func/FUN_081e0588.inc"); }

NAKED void Entity501B_StateSaveDone(Entity501B* p) { INCFUNC("asm/func/Entity501B_StateSaveDone.inc"); }

NAKED void Entity501B_StateSaveFailed(Entity501B* p) { INCFUNC("asm/func/Entity501B_StateSaveFailed.inc"); }

NAKED void FUN_081e06d8(Entity501B* p) { INCFUNC("asm/func/FUN_081e06d8.inc"); }

NAKED void FUN_081e084c(Entity501B* p) { INCFUNC("asm/func/FUN_081e084c.inc"); }

NAKED void FUN_081e0a18(Entity501B* p) { INCFUNC("asm/func/FUN_081e0a18.inc"); }

NAKED s32 Entity501B_Update(Entity501B* p) { INCFUNC("asm/func/Entity501B_Update.inc"); }

NAKED s32 Entity501B_Destroy(Entity501B* p) { INCFUNC("asm/func/Entity501B_Destroy.inc"); }

NAKED s32 Entity501B_Init(Entity501B* p) { INCFUNC("asm/func/Entity501B_Init.inc"); }

NAKED Entity501B* Entity501B_Create(void) { INCFUNC("asm/func/Entity501B_Create.inc"); }
