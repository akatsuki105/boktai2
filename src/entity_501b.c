#include "bg_pltt.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"

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
  u16 timer;                                   // 0x3BA, 90 から毎フレーム減り, 0 で次の状態へ, ボタンで 1 に飛ばせる
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

u8 Save_SwitchSlot(void);
s32 FUN_081dfa04(void);
void FUN_081e0588(Entity501B* p);
void Entity501B_StateSaveDone(Entity501B* p);
void Entity501B_StateSaveFailed(Entity501B* p);

// セッションの状態を返す, セッションが無ければ -1
static inline s32 Entity9A9F_GetState(void) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return -1;
  }
  return p->state;
}

// 状態関数を差し替えて, 切り替え直後の1フレームだけ立つフラグを付ける
static inline void Entity501B_SetState(Entity501B* p, void* fn, u8 phase) {
  p->updateCallback = fn;
  p->entered = TRUE;
  p->phase = phase;
}

NAKED void Entity501B_InitBg(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitBg.inc"); }

NAKED void Entity501B_InitTextPanels(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitTextPanels.inc"); }

void Entity501B_HideTextPanels(Entity501B* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    TextPanel_Hide(p->textPanels[i]);
  }
}

// BG のタイルマップから (x, y) のエントリのアドレスを得る
BgMapEntry* Entity501B_GetBgMapAddr(s32 bg, s32 x, s32 y) {
  BgState* state = &gBgStates[bg];
  BgMapEntry* tilemap = state->tilemap;

  return tilemap + (x & 31) + (y & 31) * 32;
}

NAKED void Entity501B_DrawBgNumber(s32 value, s32 divisor, s32 x, s32 y) { INCFUNC("asm/func/Entity501B_DrawBgNumber.inc"); }

NAKED void Entity501B_InitAuxSprite(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitAuxSprite.inc"); }

void Entity501B_RemoveAuxSprite(Entity501B* p) { AuxSprite_Remove(&p->solarStandSpr); }

NAKED void Entity501B_InitSprites(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitSprites.inc"); }

NAKED void Entity501B_InitSpritePos(Entity501B* p) { INCFUNC("asm/func/Entity501B_InitSpritePos.inc"); }

void Entity501B_HideSprites(Entity501B* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    p->digits[i].flags |= SPRFLAG_HIDDEN;
  }
}

void Entity501B_RemoveSprites(Entity501B* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    MainSprite_Remove(&p->digits[i]);
  }
}

NAKED void Entity501B_SetNumber(Entity501B* p, s32 row, s32 value) { INCFUNC("asm/func/Entity501B_SetNumber.inc"); }

NAKED void Entity501B_SpinNumber(Entity501B* p, s32 row) { INCFUNC("asm/func/Entity501B_SpinNumber.inc"); }

// 1フレームおきにカウントアップの音を鳴らし, 待ちが残っていれば上段の数字を回す
void FUN_081e02ac(Entity501B* p) {
  if (Mod(p->stateTimer, 2) == 0) {
    PlaySound_082406e0(SE_COUNT_UP);
  }
  if (p->timer != 0) {
    Entity501B_SpinNumber(p, 0);
  }
}

NAKED void FUN_081e02ec(Entity501B* p) { INCFUNC("asm/func/FUN_081e02ec.inc"); }

NAKED void Entity501B_LoadScore(Entity501B* p) { INCFUNC("asm/func/Entity501B_LoadScore.inc"); }

NAKED void FUN_081e03d8(Entity501B* p) { INCFUNC("asm/func/FUN_081e03d8.inc"); }

NAKED void FUN_081e04a8(Entity501B* p) { INCFUNC("asm/func/FUN_081e04a8.inc"); }

// セッションが状態 24 になったらセーブへ移る
void FUN_081e0544(Entity501B* p) {
  if (Entity9A9F_GetState() == 24) {
    Entity501B_SetState(p, FUN_081e0588, 6);
  }
}

// セーブの書き込みを試し, 結果に応じた状態へ移る
void FUN_081e0588(Entity501B* p) {
  if (Save_SwitchSlot()) {
    Entity501B_SetState(p, Entity501B_StateSaveDone, 7);
  } else {
    Entity501B_SetState(p, Entity501B_StateSaveFailed, 8);
  }
}

NAKED void Entity501B_StateSaveDone(Entity501B* p) { INCFUNC("asm/func/Entity501B_StateSaveDone.inc"); }

NAKED void Entity501B_StateSaveFailed(Entity501B* p) { INCFUNC("asm/func/Entity501B_StateSaveFailed.inc"); }

NAKED void FUN_081e06d8(Entity501B* p) { INCFUNC("asm/func/FUN_081e06d8.inc"); }

NAKED void FUN_081e084c(Entity501B* p) { INCFUNC("asm/func/FUN_081e084c.inc"); }

NAKED void FUN_081e0a18(Entity501B* p) { INCFUNC("asm/func/FUN_081e0a18.inc"); }

s32 Entity501B_Update(Entity501B* p) {
  if (!FUN_081dfa04()) {
    KillEntity((Entity*)p);
    return -1;
  }
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 Entity501B_Destroy(Entity501B* p) {
  Entity501B_HideTextPanels(p);
  Entity501B_RemoveSprites(p);
  Entity501B_RemoveAuxSprite(p);
  return 1;
}

NAKED s32 Entity501B_Init(Entity501B* p) { INCFUNC("asm/func/Entity501B_Init.inc"); }

Entity501B* Entity501B_Create(void) {
  Entity501B* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity501B));

  if (p != NULL) {
    SetEntityRoutine(p, Entity501B_Update, Entity501B_Destroy);
    if (Entity501B_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
