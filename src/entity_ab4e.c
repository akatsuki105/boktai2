#include "entity.h"
#include "global.h"
#include "player.h"
#include "sprite.h"

typedef struct {
  u8 unk_0[4];                // 0x000, まだ未解析
  u8 state;                   // 0x004, _Update が 0x085AB434 の関数表の添字として引く
  u8 unk_5[2];                // 0x005, まだ未解析
  u8 gfxIndex;                // 0x007, EntityAB4E.gfx の添字
  u8 unk_8;                   // 0x008, まだ未解析
  bool8 active;               // 0x009, _Update / _Destroy がこれを見て処理する
  u8 unk_a[6];                // 0x00A, まだ未解析
  s32 timer;                  // 0x010, _Update が毎フレーム 1 足す
  u8 unk_14[0x37 - 0x14];     // 0x014, まだ未解析
  bool8 unk_37;               // 0x037, _Update が毎フレーム 0 に戻し, state のハンドラが立てる
  u8 unk_38[0x60 - 0x38];     // 0x038, まだ未解析
  Mover unk_60;               // 0x060, _Update が Mover_ApplyMove に渡す
  MainSprite sprite;          // 0x0A4, _Update が MainSprite_AdvanceAnim に渡す
  ParticleShadow shadow;      // 0x104, _Destroy が ParticleShadow_Remove に渡す
  u8 unk_144[0x174 - 0x144];  // 0x144, まだ未解析
  s16 unk_174;                // 0x174, 0/1 で FUN_080da9c4 の呼び分けをする
  s16 unk_176;                // 0x176, FUN_080da9c4 に渡す
  s16 counter;                // 0x178, 毎フレーム減らし, 0 になると period に戻す
  s16 period;                 // 0x17A, counter の初期値
  u32 handle;                 // 0x17C, FUN_080da9c4 の戻り値
} EntityAB4EElem;
static_assert(sizeof(EntityAB4EElem) == 384);

typedef struct {
  Entity e;                  // 0x0000, ENTITY_UNK_5
  Vec3* playerPos;           // 0x0018, &gPlayerPtr[0]->mover.pos
  s16 unk_1c;                // 0x001C, '.t'
  bool8 minuteChanged;       // 0x001E, 分が変わったフレームだけ立つ
  u8 prevMinute;             // 0x001F, 前フレームの Time_GetMinute
  u8 hour;                   // 0x0020, Time_GetHour
  u8 minute;                 // 0x0021, Time_GetMinute
  u8 unk_22;                 // 0x0022, まだ未解析
  u8 count1;                 // 0x0023, points1 の要素数
  u8 count2;                 // 0x0024, points2 の要素数
  u8 unk_25;                 // 0x0025, _Update が FUN_08018a08 の戻り値を入れる
  u8 unk_26[2];              // 0x0026, まだ未解析
  u32 unk_28;                // 0x0028, _Init が 0 を入れる
  Vec3 points1[16];          // 0x002C, '.h'
  Vec3 points2[16];          // 0x00AC, '.s'
  EntityAB4EElem elems[16];  // 0x012C
  MainSpriteGfx gfx[8];      // 0x192C, '.d' の8個の ID から作る
  Player* player;            // 0x1A2C, gPlayerPtr[0]
} EntityAB4E;
static_assert(sizeof(EntityAB4E) == 6704);

IWRAM_DATA EntityAB4E* gEntityAB4E = NULL;  // 0x030000C0

const u16 u16_ARRAY_085ab404[8] = {0, 16, 0, 0, 0, 0, 0, 0};  // 0x085AB404

const u16 u16_ARRAY_085ab414[8] = {5, 21, 0, 0, 0, 0, 0, 0};  // 0x085AB414

const u16 u16_ARRAY_085ab424[8] = {7, 23, 0, 0, 0, 0, 0, 0};  // 0x085AB424

s32 FUN_080455fc(EntityAB4E*, EntityAB4EElem*, s32);
s32 FUN_08045890(EntityAB4E*, EntityAB4EElem*, s32);
s32 FUN_08045b6c(EntityAB4E*, EntityAB4EElem*, s32);
s32 FUN_08045e68(EntityAB4E*, EntityAB4EElem*, s32);
s32 FUN_08046254(EntityAB4E*, EntityAB4EElem*, s32);
s32 FUN_08046340(EntityAB4E*, EntityAB4EElem*, s32);
s32 FUN_08046970(EntityAB4E*, EntityAB4EElem*, s32);
s32 FUN_080465b0(EntityAB4E*, EntityAB4EElem*, s32);
s32 FUN_08046c98(EntityAB4E*, EntityAB4EElem*, s32);

s32 (*const PTR_ARRAY_085ab434[9])(EntityAB4E*, EntityAB4EElem*, s32) = {
    FUN_080455fc,
    FUN_08045890,
    FUN_08045b6c,
    FUN_08045e68,
    FUN_08046254,
    FUN_08046340,
    FUN_08046970,
    FUN_080465b0,
    FUN_08046c98,
};  // 0x085AB434

// 未使用の要素を先頭から探す
EntityAB4EElem* EntityAB4E_FindFreeElem(EntityAB4E* p) {
  EntityAB4EElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (!elem->active) {
      return elem;
    }
  }

  return NULL;
}

// 要素の Mover / 影 / スプライトを外して非アクティブにする
s32 FUN_080452f4(EntityAB4E* p, EntityAB4EElem* elem, s32 index) {
  Mover* mover;

  if (!elem->active) {
    return -1;
  }

  mover = &elem->unk_60;
  FUN_08002a58(mover);
  Mover_Unlink(mover);
  ParticleShadow_Remove(&elem->shadow);
  MainSprite_Remove(&elem->sprite);
  elem->active = FALSE;
}

NAKED void FUN_08045330(EntityAB4EElem* elem, unknown* param_2) { INCFUNC("asm/func/FUN_08045330.inc"); }

NAKED void FUN_080453b0(EntityAB4EElem* elem) { INCFUNC("asm/func/FUN_080453b0.inc"); }

NAKED s32 FUN_08045408(EntityAB4E* p) { INCFUNC("asm/func/FUN_08045408.inc"); }

NAKED s32 FUN_08045530(EntityAB4E* p, EntityAB4EElem* elem, s32 param_3) { INCFUNC("asm/func/FUN_08045530.inc"); }

NAKED s32 FUN_080455fc(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_080455fc.inc"); }

NAKED s32 FUN_08045890(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_08045890.inc"); }

NAKED s32 FUN_08045b6c(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_08045b6c.inc"); }

NAKED s32 FUN_08045e68(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_08045e68.inc"); }

NAKED s32 FUN_08046254(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_08046254.inc"); }

NAKED s32 FUN_08046340(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_08046340.inc"); }

NAKED s32 FUN_080465b0(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_080465b0.inc"); }

NAKED s32 FUN_08046970(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_08046970.inc"); }

NAKED s32 FUN_08046c98(EntityAB4E* p, EntityAB4EElem* elem, s32 index) { INCFUNC("asm/func/FUN_08046c98.inc"); }

NAKED s32 EntityAB4E_Update(EntityAB4E* p) { INCFUNC("asm/func/EntityAB4E_Update.inc"); }

s32 EntityAB4E_Destroy(EntityAB4E* p) {
  EntityAB4EElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (elem->active) {
      FUN_080452f4(p, elem, i);
    }
  }

  gEntityAB4E = NULL;
  return 0;
}

NAKED s32 EntityAB4E_Init(EntityAB4E* p) { INCFUNC("asm/func/EntityAB4E_Init.inc"); }

EntityAB4E* EntityAB4E_Create(void) {
  if (gEntityAB4E == NULL) {
    EntityAB4E* p = CreateEntity(ENTITY_UNK_5, sizeof(EntityAB4E));

    if (p != NULL) {
      SetEntityRoutine(p, EntityAB4E_Update, EntityAB4E_Destroy);
      if (EntityAB4E_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityAB4E;
}

NAKED s32 EntityAB4E_AddElemScripted(void) { INCFUNC("asm/func/EntityAB4E_AddElemScripted.inc"); }
