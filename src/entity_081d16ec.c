#include "entity_081d16ec.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "sound.h"
#include "sprite.h"

// 最大12個の Entity081d16ecItem をビットマスクで管理するシングルトン
typedef struct Entity081d16ec {
  Entity e;                      // 0x000, ENTITY_UNK_9
  void* animFile;                // 0x018, GetFile(DIR_ANIMATION, 0xB952)
  Entity081d16ecItem items[12];  // 0x01C, _Update と _Destroy が 0x1C + i*200 で引く
  u32 activeMask;                // 0x97C, bit i が立っていれば items[i] が使用中。_Init が 0 にする
} Entity081d16ec;
static_assert(sizeof(Entity081d16ec) == 2432);

extern Entity081d16ec* gEntity081d16ec;  // 0x0300018C

void FUN_081d0e74(Entity081d16ecItem* item, Entity081d16ecItemFlags n) { item->flags |= n; }

void FUN_081d0e84(Entity081d16ecItem* item, Entity081d16ecItemFlags n) { item->flags &= ~n; }

bool8 FUN_081d0e94(Entity081d16ecItem* item, Entity081d16ecItemFlags n) {
  if (item->flags & n) {
    return TRUE;
  }
  return FALSE;
}

// 空いているスロットを1つ確保する
NON_MATCH Entity081d16ecItem* FUN_081d0eac(Entity081d16ec* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!(p->activeMask & (1 << i))) {
      Entity081d16ecItem* item = &p->items[i];

      p->activeMask |= 1 << i;
      ClearMemory(item, sizeof(Entity081d16ecItem));
      item->slotIndex = i;
      return item;
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_081d0eac.inc");
#endif
}

NAKED Entity081d16ecItem* FUN_081d0f08(s32 id) { INCFUNC("asm/func/FUN_081d0f08.inc"); }

NAKED void FUN_081d0f64(unknown* p) { INCFUNC("asm/func/FUN_081d0f64.inc"); }

// 開閉アニメーションを折り返す。まだ再生していなければ頭から始める
void FUN_081d11b8(Entity081d16ecItem* item) {
  Entity081d16ec* p = gEntity081d16ec;

  PlaySound_082406e0(0x14C);
  if (item->state == 2) {
    if (item->anim.flags & ANIM_PLAY_REVERSE) {
      item->anim.flags &= ~ANIM_PLAY_REVERSE;
    } else {
      item->anim.flags |= ANIM_PLAY_REVERSE;
    }
    item->anim.tick = item->anim.wait - item->anim.tick;
  } else {
    if (FUN_081d0e94(item, E081D16EC_FLAG_0)) {
      FUN_08236fac(&item->anim, p->animFile, 1, 0, item->unk_bc);
      FUN_081d0e84(item, E081D16EC_FLAG_0);
    } else {
      FUN_08236fac(&item->anim, p->animFile, 1, 0, item->unk_bc | ANIM_PLAY_REVERSE);
      FUN_081d0e84(item, E081D16EC_FLAG_1);
    }
    item->state = 2;
  }
}

// 無敵時間を数えつつ、点滅用のパレットを選ぶ
NON_MATCH void FUN_081d1260(Entity081d16ecItem* item) {
#ifdef NONMATCHING_C
  if (item->hitbox.unk_44 != 0) {
    item->hitbox.flags |= HBFLAG_UNK_2;
    item->hitbox.unk_44--;
  } else {
    item->hitbox.flags &= ~HBFLAG_UNK_2;
  }
  if (item->unk_bd != 0) {
    Video_SetAuxSpritePltt(item->sprite.gfx, 306);
    item->unk_bd--;
  } else {
    switch (item->unk_ba) {
      case 0: {
        Video_SetAuxSpritePltt(item->sprite.gfx, 313);
        break;
      }
      case 1: {
        Video_SetAuxSpritePltt(item->sprite.gfx, 314);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081d1260.inc");
#endif
}

NAKED void FUN_081d12e0(Entity081d16ec* p, Entity081d16ecItem* item) { INCFUNC("asm/func/FUN_081d12e0.inc"); }

// state 0 のハンドラ。何もしない
void FUN_081d146c(Entity081d16ec* p, Entity081d16ecItem* item) {}

// 条件が揃っていれば無敵時間を置いて開閉を始める
NON_MATCH void FUN_081d1470(Entity081d16ecItem* item) {
#ifdef NONMATCHING_C
  if (FUN_081d0e94(item, E081D16EC_FLAG_2)) {
    bool8 busy;

    if (item->unk_c0 & 1) {
      busy = FUN_081d0e94(item, E081D16EC_FLAG_0);
    } else {
      busy = FUN_081d0e94(item, E081D16EC_FLAG_1);
    }
    if (!busy) {
      item->hitbox.flags |= HBFLAG_UNK_2;
      if (!FUN_081d0e94(item, E081D16EC_FLAG_3)) {
        if (item->unk_c2 <= item->unk_c4) {
          item->hitbox.unk_44 = 24;
          FUN_081d11b8(item);
        }
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081d1470.inc");
#endif
}

NAKED void FUN_081d14e0(Entity081d16ec* p, Entity081d16ecItem* item) { INCFUNC("asm/func/FUN_081d14e0.inc"); }

// state 3 のハンドラ。何もしない
void FUN_081d15f8(Entity081d16ec* p, Entity081d16ecItem* item) {}

NAKED s32 Entity081d16ec_Update(Entity081d16ec* p) { INCFUNC("asm/func/Entity081d16ec_Update.inc"); }

NON_MATCH s32 Entity081d16ec_Destroy(Entity081d16ec* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 12; i++) {
    if (p->activeMask & (1 << i)) {
      AuxSprite_Remove(&p->items[i].sprite);
      Hitbox_Unregister(&p->items[i].hitbox);
    }
  }
  gEntity081d16ec = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity081d16ec_Destroy.inc");
#endif
}

s32 Entity081d16ec_Init(Entity081d16ec* p) {
  p->animFile = GetFile(DIR_ANIMATION, 0xB952);
  gEntity081d16ec = p;
  p->activeMask = 0;
  return 0;
}

Entity081d16ec* Entity081d16ec_Create(void) {
  Entity081d16ec* p;

  if (gEntity081d16ec != NULL) {
    return gEntity081d16ec;
  }
  p = CreateEntity(ENTITY_UNK_9, sizeof(Entity081d16ec));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081d16ec_Update, Entity081d16ec_Destroy);
    if (Entity081d16ec_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d1738(void) { gEntity081d16ec = NULL; }
