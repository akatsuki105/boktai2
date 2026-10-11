#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef u16 Entity081d16ecItemFlags;  // Entity081d16ecItem.flags
#define E081D16EC_FLAG_0 (1 << 0)     // まだ不明
#define E081D16EC_FLAG_1 (1 << 1)     // まだ不明
#define E081D16EC_FLAG_2 (1 << 2)     // まだ不明
#define E081D16EC_FLAG_3 (1 << 3)     // まだ不明
#define E081D16EC_FLAG_4 (1 << 4)     // まだ不明

// スプライトとヒットボックスを1つずつ持つ
typedef struct Entity081d16ecItem {
  AuxSprite sprite;               // 0x00, Entity081d16ec_Destroy が要素そのものを AuxSprite_Remove に渡す
  AuxAnimState anim;              // 0x2C, AuxAnim_SetAnim で再生する
  u8 unk_3c[28];                  // 0x3C
  Vec3 basePos;                   // 0x58, 揺れの基準位置, sprite.pos へ複写する
  HitboxData hitbox;              // 0x60, _Destroy が Hitbox_Unregister に渡す
  u16 state;                      // 0xB0, _Update が PTR_ARRAY_085AE0B8[state](p, item) を呼ぶ
  u16 unk_b2;                     // 0xB2
  u16 slotIndex;                  // 0xB4, FUN_081d0eac が確保時に自分のスロット番号を入れる
  Entity081d16ecItemFlags flags;  // 0xB6, see Entity081d16ecItemFlags
  u8 unk_b8[2];                   // 0xB8
  s16 unk_ba;                     // 0xBA, 0 か 1 でパレットを切り替える
  u8 unk_bc;                      // 0xBC
  u8 unk_bd;                      // 0xBD, 0 でない間はパレット 0x132 を強制して減らす
  u16 unk_be;                     // 0xBE, ヒットボックスの unk_4 に入れる
  u16 unk_c0;                     // 0xC0, bit0 で判定に使うフラグを切り替える
  u16 unk_c2;                     // 0xC2
  u16 unk_c4;                     // 0xC4, unk_c2 がこれ以下なら反応する
  u8 unk_c6;                      // 0xC6
  u8 unk_c7;                      // 0xC7, 0 でない間はスプライトを ±10 揺らして減らす
} Entity081d16ecItem;
static_assert(sizeof(Entity081d16ecItem) == 200);

// 最大12個の Entity081d16ecItem をビットマスクで管理するシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_9
  AuxAnimFile* anim;             // 0x018, ANIM_B952
  Entity081d16ecItem items[12];  // 0x01C
  u32 activeMask;                // 0x97C, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} Entity081d16ec;
static_assert(sizeof(Entity081d16ec) == 2432);

IWRAM_DATA Entity081d16ec* gEntity081d16ec = NULL;  // 0x0300018C

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

// 開閉アニメーションを折り返す, まだ再生していなければ頭から始める
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
      AuxAnim_SetAnim(&item->anim, p->anim, 1, 0, item->unk_bc);
      FUN_081d0e84(item, E081D16EC_FLAG_0);
    } else {
      AuxAnim_SetAnim(&item->anim, p->anim, 1, 0, item->unk_bc | ANIM_PLAY_REVERSE);
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

// state 0 のハンドラ, 何もしない
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

// state 3 のハンドラ, 何もしない
void FUN_081d15f8(Entity081d16ec* p, Entity081d16ecItem* item) {}

void (*const PTR_ARRAY_085ae0b8[4])(Entity081d16ec*, Entity081d16ecItem*) = {
    FUN_081d146c,
    FUN_081d14e0,
    FUN_081d12e0,
    FUN_081d15f8,
};  // 0x085AE0B8

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
  p->anim = GetFile(DIR_ANIMATION, ANIM_B952);
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

// 被弾中はスプライトを基準位置から ±10 の範囲で揺らす
void FUN_081d1744(Entity081d16ecItem* item) {
  if (item->unk_c7 == 0) {
    item->sprite.pos = item->basePos;
  } else {
    u16* table = gRandomTable;

    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    item->sprite.pos.x = item->basePos.x + Mod(table[gRandTableIdx], 20) - 10;
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    item->sprite.pos.z = item->basePos.z + Mod(table[gRandTableIdx], 20) - 10;
    item->unk_c7--;
  }
}

NAKED void FUN_081d17c8(HitboxData* a, HitboxData* b, Entity081d16ecItem* item) { INCFUNC("asm/func/FUN_081d17c8.inc"); }

void FUN_081d1924(Entity081d16ecItem* item) {
  HitboxData* hitbox = &item->hitbox;
  Vec3 offset;
  Vec3 halfSize;

  offset.x = 0, offset.y = 0x80, offset.z = 0;
  halfSize.x = 0x40, halfSize.y = 0x80, halfSize.z = 0x40;
  hitbox->unk_4 = item->unk_be;
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_14 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &item->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_081d17c8, item);
  Hitbox_Register(hitbox);
}

// '.n' が指す要素のフラグを返す
s32 FUN_081d19a8(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);
    if (item != NULL) {
      return item->flags;
    }
  }
  return -1;
}

void FUN_081d19cc(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      FUN_081d0e74(item, E081D16EC_FLAG_4 | E081D16EC_FLAG_3);
      FUN_081d0e84(item, E081D16EC_FLAG_2);
    }
  }
}

// '.n' が指す要素を '.c' のビットに応じて開閉させる
void FUN_081d19f8(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      s32 mode = VM_GetNamedArgValue('c', 0);

      if (mode & 1) {
        if (!FUN_081d0e94(item, E081D16EC_FLAG_0)) {
          item->hitbox.unk_44 = 24;
          FUN_081d11b8(item);
          FUN_081d0e74(item, E081D16EC_FLAG_4);
        }
      } else if (mode & 2) {
        if (!FUN_081d0e94(item, E081D16EC_FLAG_1)) {
          item->hitbox.unk_44 = 24;
          FUN_081d11b8(item);
          FUN_081d0e74(item, E081D16EC_FLAG_4);
        }
      }
    }
  }
}

void FUN_081d1a7c(void) {
  s32 id = VM_GetNamedArgValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      FUN_081d0e84(item, E081D16EC_FLAG_4);
    }
  }
}
