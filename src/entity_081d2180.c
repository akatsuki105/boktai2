#include "entity.h"
#include "entity_081d16ec.h"
#include "game.h"
#include "global.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

// Entity081d2180 が抱える要素
typedef struct Entity081d2180Item {
  AuxSprite sprite;  // 0x00, Entity081d2180_Destroy が要素そのものを AuxSprite_Remove に渡す
  u8 unk_2c[44];     // 0x2C
  u16 unk_58;        // 0x58, gStat->unk_248 と一致しなければ要素を隠す
  u16 unk_5a;        // 0x5A, FUN_081d1bf8 の第2引数
  u8 unk_5c[34];     // 0x5C
  s16 state;         // 0x7E, _Update が PTR_FUN_081D1AE8_085AE0C8[state](item) を呼ぶ
  u16 flags;         // 0x80
  u16 unk_82;        // 0x82
  u16 unk_84;        // 0x84, FUN_081d1bf8 が 0 を入れる
  u16 unk_86;        // 0x86
} Entity081d2180Item;
static_assert(sizeof(Entity081d2180Item) == 136);

// 最大8個の Entity081d2180Item をビットマスクで管理するシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  Entity081d2180Item items[8];  // 0x018, _Update と _Destroy が 0x88 刻みで8個走査する
  u32 activeMask;               // 0x458, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} Entity081d2180;

extern Entity081d2180* gEntity081d2180;  // 0x03000190

static_assert(sizeof(Entity081d2180) == 1116);

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

// スクリプトの 'n' が指す要素のフラグを返す
s32 FUN_081d19a8(void) {
  s32 id = VM_GetKeywordValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);
    if (item != NULL) {
      return item->flags;
    }
  }
  return -1;
}

void FUN_081d19cc(void) {
  s32 id = VM_GetKeywordValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      FUN_081d0e74(item, E081D16EC_FLAG_4 | E081D16EC_FLAG_3);
      FUN_081d0e84(item, E081D16EC_FLAG_2);
    }
  }
}

// スクリプトの 'n' が指す要素を 'c' のビットに応じて開閉させる
void FUN_081d19f8(void) {
  s32 id = VM_GetKeywordValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      s32 mode = VM_GetKeywordValue('c', 0);

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
  s32 id = VM_GetKeywordValue('n', 0);

  if (id != 0) {
    Entity081d16ecItem* item = FUN_081d0f08(id);

    if (item != NULL) {
      FUN_081d0e84(item, E081D16EC_FLAG_4);
    }
  }
}

NAKED s32 FUN_081d1a9c(unknown* p) { INCFUNC("asm/func/FUN_081d1a9c.inc"); }

// state 0 のハンドラ, 何もしない
void FUN_081d1ae8(Entity081d2180Item* item) {}

#ifdef NONMATCHING_C
static inline bool32 IsCurrentArea(u16 id) {
  if (gStat->unk_248 == id) {
    return TRUE;
  }
  return FALSE;
}
#endif

// 現在のエリアの要素でなければ隠す
NON_MATCH bool32 FUN_081d1aec(Entity081d2180Item* item) {
#ifdef NONMATCHING_C
  if (IsCurrentArea(item->unk_58)) {
    AuxSprite_Show(&item->sprite);
    return TRUE;
  }
  AuxSprite_Hide(&item->sprite);
  return FALSE;
#else
  INCFUNC("asm/func/FUN_081d1aec.inc");
#endif
}

NAKED void FUN_081d1b34(unknown* p) { INCFUNC("asm/func/FUN_081d1b34.inc"); }

NON_MATCH void FUN_081d1bf8(Entity081d2180Item* item, s32 param_2) {
#ifdef NONMATCHING_C
  item->unk_5a = param_2;
  if (item->flags & 1) {
    item->flags = (item->flags | 2) & ~1;
    item->unk_84 = 0;
    FUN_081d1b34(item);
    AuxSprite_SetPoseIdx(&item->sprite, 1);
    Video_SetAuxSpritePltt(item->sprite.gfx, 0x120);
    if (item->flags & 4) {
      PlaySound_082406e0(0x389);
    } else {
      PlaySound_082406e0(0x155);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d1bf8.inc");
#endif
}

NAKED void FUN_081d1c64(unknown* p) { INCFUNC("asm/func/FUN_081d1c64.inc"); }

NAKED void FUN_081d1cdc(Entity081d2180Item* item) { INCFUNC("asm/func/FUN_081d1cdc.inc"); }

NAKED void FUN_081d1dec(unknown* p) { INCFUNC("asm/func/FUN_081d1dec.inc"); }

NAKED s32 Entity081d2180_Update(Entity081d2180* p) { INCFUNC("asm/func/Entity081d2180_Update.inc"); }

NON_MATCH s32 Entity081d2180_Destroy(Entity081d2180* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->activeMask & (1 << i)) {
      AuxSprite_Remove(&p->items[i].sprite);
    }
  }
  gEntity081d2180 = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity081d2180_Destroy.inc");
#endif
}

s32 Entity081d2180_Init(Entity081d2180* p) {
  gEntity081d2180 = p;
  p->activeMask = 0;
  return 0;
}

Entity081d2180* Entity081d2180_Create(void) {
  Entity081d2180* p;

  if (gEntity081d2180 != NULL) {
    return gEntity081d2180;
  }
  p = CreateEntity(ENTITY_UNK_8, sizeof(Entity081d2180));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081d2180_Update, Entity081d2180_Destroy);
    if (Entity081d2180_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d21cc(void) { gEntity081d2180 = NULL; }
