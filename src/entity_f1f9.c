#include "entity_f1f9.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "shadow.h"
#include "sprite_aux.h"

// 最大4個の EntityF1F9Item をビットマスクで管理するシングルトン
typedef struct EntityF1F9 {
  Entity e;                 // 0x000, ENTITY_UNK_10
  void* animFile;           // 0x018, GetFile(DIR_ANIMATION, 0x74C9)
  EntityF1F9Item items[4];  // 0x01C, _Update と _Destroy が 0x1C + i*0x158 で引く
  u32 activeMask;           // 0x57C, bit i が立っていれば items[i] が使用中。_Init が 0 にする
} EntityF1F9;
static_assert(sizeof(EntityF1F9) == 1408);

extern EntityF1F9* gEntityF1F9;  // 0x03000198

// src/entity_c60f.c
void FUN_081d6444(EntityF1F9Item* item);
void FUN_081d6c24(EntityF1F9Item* item);

void FUN_081d5820(EntityF1F9Item* item, u16 n) { item->flags |= n; }

void FUN_081d5834(EntityF1F9Item* item, u16 n) { item->flags &= ~n; }

bool8 FUN_081d5848(EntityF1F9Item* item, u16 n) {
  if (item->flags & n) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 FUN_081d5864(EntityF1F9* p) { INCFUNC("asm/func/FUN_081d5864.inc"); }

NAKED s32 FUN_081d58c4(unknown* p) { INCFUNC("asm/func/FUN_081d58c4.inc"); }

NAKED void FUN_081d5924(unknown* p) { INCFUNC("asm/func/FUN_081d5924.inc"); }

// 無敵時間を数えつつ、点滅用のパレットを選ぶ
NON_MATCH void FUN_081d5cac(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  if (item->hitbox.unk_44 != 0) {
    item->hitbox.flags |= HBFLAG_UNK_2;
    item->hitbox.unk_44--;
  } else {
    item->hitbox.flags &= ~HBFLAG_UNK_2;
  }
  if (item->unk_153 != 0) {
    Video_SetAuxSpritePltt(item->sprite.gfx, 0x132);
    item->unk_153--;
  } else {
    Video_SetAuxSpritePltt(item->sprite.gfx, 0x17C);
  }
#else
  INCFUNC("asm/func/FUN_081d5cac.inc");
#endif
}

// state 0 のハンドラ。何もしない
void FUN_081d5d14(EntityF1F9* p, EntityF1F9Item* item) {}

// state 1 のハンドラ
void FUN_081d5d18(EntityF1F9* p, EntityF1F9Item* item) {
  if (item->unk_156 != 0) {
    item->unk_154 = 0;
    AuxSprite_Show(&item->sprite);
    item->unk_156 = 0;
  }
  FUN_081d5cac(item);
  FUN_081d6444(item);
  if (item->unk_154 & 1) {
    FUN_081d6c24(item);
  }
  item->unk_154++;
}

NAKED void FUN_081d5d70(EntityF1F9* p, EntityF1F9Item* item) { INCFUNC("asm/func/FUN_081d5d70.inc"); }

NAKED void FUN_081d5f54(unknown* p) { INCFUNC("asm/func/FUN_081d5f54.inc"); }

NAKED void FUN_081d60c8(EntityF1F9* p, EntityF1F9Item* item) { INCFUNC("asm/func/FUN_081d60c8.inc"); }

NAKED void FUN_081d6200(EntityF1F9* p, EntityF1F9Item* item) { INCFUNC("asm/func/FUN_081d6200.inc"); }

NAKED s32 EntityF1F9_Update(EntityF1F9* p) { INCFUNC("asm/func/EntityF1F9_Update.inc"); }

NAKED s32 EntityF1F9_Destroy(EntityF1F9* p) { INCFUNC("asm/func/EntityF1F9_Destroy.inc"); }

s32 EntityF1F9_Init(EntityF1F9* p) {
  p->animFile = GetFile(DIR_ANIMATION, 0x74C9);
  gEntityF1F9 = p;
  p->activeMask = 0;
  return 0;
}

EntityF1F9* EntityF1F9_Create(void) {
  EntityF1F9* p;

  if (gEntityF1F9 != NULL) {
    return gEntityF1F9;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(EntityF1F9));
  if (p != NULL) {
    SetEntityRoutine(p, EntityF1F9_Update, EntityF1F9_Destroy);
    if (EntityF1F9_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d6438(void) { gEntityF1F9 = NULL; }
