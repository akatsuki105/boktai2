#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

// EntityC60FItem.flags
typedef u32 EntityC60FItemFlags;
#define C60FITEM_TILE_OVERRIDE (1 << 5)  // 衝突タイルの上書きを持っている, 落とすときに Map_RemoveTileOverride で取り消す
#define C60FITEM_FIXED_AREA (1 << 7)     // state を回さず zoneID を gStat->zoneID と比べる

typedef struct {
  AuxSprite sprite;              // 0x000
  AuxSpriteGfx gfx;              // 0x02C
  Mover unk_48;                  // 0x048
  AuxAnimState anim;             // 0x08C
  Vec3 pos;                      // 0x09C, Hitbox_SetPos に渡す
  HitboxData hurtbox;            // 0x0A4, FUN_081d6eb8 が組み立てる
  u16 hp;                        // 0x0F4
  u16 maxHp;                     // 0x0F6
  s32 unk_f8;                    // 0x0F8
  u16 slotIndex;                 // 0x0FC, 確保時に自分のスロット番号が入る
  s16 state;                     // 0x0FE, PTR_FUN_081D6F60_085AE118[state]
  EntityC60FItemFlags flags;     // 0x100
  bool8 stateEntered;            // 0x104
  u8 unk_105;                    // 0x105
  u16 timer;                     // 0x106
  u8 unk_108;                    // 0x108, 0 でないときだけ _Destroy が FUN_08002a58 / Mover_Unlink を呼ぶ
  u8 unk_109;                    // 0x109
  ZoneID16 zoneID;               // 0x10A, unk_100 の bit7 が立っているとき gStat->zoneID と比較される
  MapTileOverride tileOverride;  // 0x10C, unk_100 の bit5 が立っているとき _Destroy が Map_RemoveTileOverride に渡す
} EntityC60FItem;
static_assert(sizeof(EntityC60FItem) == 284);

// 最大32個の EntityC60FItem をビットマスクで管理するシングルトン
typedef struct {
  Entity e;                   // 0x00, ENTITY_UNK_10
  AuxAnimFile* anim0;         // 0x18, ANIM_1003
  AuxAnimFile* anim1;         // 0x1C, ANIM_931E
  EntityC60FItem* items[32];  // 0x20
  u32 activeMask;             // 0xA0, bit i が立っていれば items[i] が確保済み
  u8 unk_a4;                  // 0xA4, _Init と _Update が 0xFF を書く, 読み手が見つかっていない
  u8 unk_a5[3];               // 0xA5, padding?
} EntityC60F;
static_assert(sizeof(EntityC60F) == 168);

void FUN_08015c90(s32 count, u32 kind, u32 flags, u32 animSpeed, Vec3* pos);

IWRAM_DATA EntityC60F* gEntityC60F = NULL;  // 0x0300019C

static inline bool8 EntityC60F_IsActive(EntityC60F* p, s32 i) {
  u32* mask = &p->activeMask;

  if (*mask & (1 << i)) {
    return TRUE;
  }

  return FALSE;
}

static inline bool8 EntityC60FItem_HasFlag(EntityC60FItem* p, u32 mask) {
  if (TEST_FLAGS(p->flags, mask)) {
    return TRUE;
  }

  return FALSE;
}

// 170/182 命令, ハンドラの判定をすべて bool8 inline にする形が途中まで
NON_MATCH void FUN_081d6d28(HitboxData* a, HitboxData* b, EntityC60FItem* p) {
#ifdef NONMATCHING_C
  if (EntityC60FItem_HasFlag(p, 8)) {
    return;
  }

  if ((p->unk_109 != 1 && (a->weakness & 0x10)) || EntityC60FItem_HasFlag(p, 2)) {
    b->damage = 0;
    b->knockbackPower = 0;
    return;
  }

  if (a->attributes & 8) {
    b->hitResult = 1;
    if (p->unk_109 == 0) {
      if (p->unk_105 != 0) {
        p->unk_105--;
      } else {
        FUN_08015c90(2, 0, 0, 64, &p->pos);
        p->unk_105 = 3;
        PlaySound_082406e0(SONG_348);
      }
    } else if (p->unk_109 == 1) {
      if (p->unk_105 != 0) {
        p->unk_105--;
      } else {
        FUN_08015c90(2, 2, 0, 64, &p->pos);
        p->unk_105 = 2;
        PlaySound_082406e0(SONG_348);
      }
    }
    if (EntityC60FItem_HasFlag(p, 4)) {
      if (p->unk_109 == 1) {
        p->hp -= 200;
        if ((s16)p->hp < 0) {
          p->hp = 0;
        }
      } else {
        p->hp -= a->damage;
        if ((s16)p->hp < 0) {
          p->hp = 0;
        }
      }
    }
  }

  if (p->unk_109 == 1 && a->owner != NULL && a->fn != NULL && (a->weakness & 0x10)) {
    ((void (*)(HitboxData*, HitboxData*, void*))a->fn)(a, b, a->owner);
  }
#else
  INCFUNC("asm/func/FUN_081d6d28.inc");
#endif
}

// 種別に応じた大きさで当たり判定を作る
NON_MATCH void FUN_081d6eb8(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize;
  Vec3 offset;
  s32 radius, height;

  if (p->unk_109 == 1) {
    radius = 0x56, height = 0x80;
  } else {
    radius = 0x60, height = 0x10;
  }
  halfSize.x = radius, halfSize.y = height, halfSize.z = radius;
  offset.x = 0, offset.y = height, offset.z = 0;
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_1 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->pos, 0);
  Hitbox_SetHandler(hurtbox, FUN_081d6d28, p);
  Hitbox_Register(hurtbox);
#else
  INCFUNC("asm/func/FUN_081d6eb8.inc");
#endif
}

// state 0 のハンドラ, 何もしない
void FUN_081d6f60(EntityC60FItem* p) {}

EntityC60FItem* EntityC60F_AllocSlot(EntityC60F* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    if (!EntityC60F_IsActive(p, i)) {
      EntityC60FItem* item = Malloc(sizeof(EntityC60FItem));

      ClearMemory(item, sizeof(EntityC60FItem));
      p->activeMask |= 1 << i;
      item->slotIndex = i;
      p->items[i] = item;
      return item;
    }
  }

  return NULL;
}

// 下書き段階, AuxSprite_AdvanceAnim 周りの命令数が 20 以上ずれる
NON_MATCH void FUN_081d6fd4(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  EntityC60F* m = gEntityC60F;
  u8* hit;

  if (m == NULL) {
    return;
  }

  hit = &p->hurtbox.hitResult;
  if ((*hit & 1) || (p->flags & 4)) {
    if ((s16)p->hp <= 0) {
      p->flags = 40;
      AuxAnim_SetAnim(&p->anim, m->anim0, 1, 0, 0);
      AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
      p->state = 3;
      p->stateEntered = TRUE;
      *hit = 0;
      return;
    }

    if (p->flags & 1) {
      if (p->anim.cmdIdx != 3) {
        u16 idx = p->anim.cmdIdx;

        if (idx > 3) {
          idx = abs(idx - 6);
        }
        AuxAnim_RestartAnim(&p->anim, gEntityC60F->anim0, 0, 0, 0);
        p->anim.cmdIdx = idx;
      }
      p->flags = 34;
      return;
    }

    p->flags = 36;
    {
      s32 stage = Div((s16)p->hp, p->unk_f8);

      AuxAnim_SetAnim(&p->anim, m->anim0, 1, 0, 0);
      if (p->anim.cmdIdx < 3 - stage) {
        AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
      }
    }
  }

  if (!(*hit & 1)) {
    if ((s16)p->hp < (s16)p->maxHp) {
      p->hp += 10;
    } else if (p->flags & 4) {
      AuxAnim_SetAnim(&p->anim, m->anim0, 1, 0, ANIM_PLAY_REVERSE);
      if (p->flags & 4) {
        p->anim.cmdIdx = 3 - Div((s16)p->hp, p->unk_f8);
      }
      p->hp = p->maxHp;
      p->flags = 48;
    }
    p->unk_105 = 0;
  }
  *hit = 0;
#else
  INCFUNC("asm/func/FUN_081d6fd4.inc");
#endif
}

// 下書き段階, AuxSprite_AdvanceAnim 周りの命令数が 20 以上ずれる
NON_MATCH void FUN_081d7358(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  EntityC60F* m = gEntityC60F;

  if (m == NULL) {
    return;
  }

  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  if (p->flags & 0x10) {
    if (AuxSprite_AdvanceAnim(&p->sprite, &p->anim)) {
      AuxAnim_SetAnim(&p->anim, m->anim0, 0, 0, 0);
      p->anim.cmdIdx = 3;
      p->flags = 33;
    }
  } else if (p->flags & 2) {
    AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
    if (p->anim.cmdIdx == 3) {
      p->flags = 36;
    }
  } else {
    FUN_081d6fd4(p);
    if (p->flags & 1) {
      AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d7358.inc");
#endif
}

// 169/167 命令, AuxSprite_AdvanceAnim の中のレジスタの持ち方が違う
NON_MATCH void FUN_081d76bc(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  if (gEntityC60F != NULL) {
    AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
    if (p->hurtbox.hitResult & 1) {
      if ((s16)p->hp <= 0) {
        p->flags = 40;
        p->state = 4;
        p->stateEntered = TRUE;
      } else {
        p->hurtbox.hitResult = 0;
      }
    } else if ((s16)p->hp < (s16)p->maxHp) {
      p->hp += 10;
    }
  }
#else
  INCFUNC("asm/func/FUN_081d76bc.inc");
#endif
}

// 生成した衝突タイルの上書きを取り消す
// フラグ判定を bool8 を返す static inline にすると 0/1 の作り置きは出るが, 原典は &flags を Map_RemoveTileOverride の呼び出しをまたいでレジスタに持つ
NON_MATCH void FUN_081d7814(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  if (p->state == 3 || p->state == 4) {
    if (p->flags & C60FITEM_TILE_OVERRIDE) {
      Map_RemoveTileOverride(&p->tileOverride);
      p->flags &= ~C60FITEM_TILE_OVERRIDE;
    }
  }
#else
  INCFUNC("asm/func/FUN_081d7814.inc");
#endif
}

// 243/243 命令, レジスタ割当だけの差
NON_MATCH void FUN_081d785c(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  EntityC60F* m = gEntityC60F;
  bool32 finished;

  if (m == NULL) {
    return;
  }

  if (p->stateEntered) {
    FUN_081d7814(p);
    p->timer = 0;
    p->stateEntered = FALSE;
  }

  finished = AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  if (p->timer < 32) {
    Vec3 pos;

    if (Mod(p->timer, 6) == 0) {
      pos = p->pos;
      pos.x -= 64;
      FUN_08015c90(1, 0, 0, 64, &pos);
    }
    if (Mod(p->timer, 10) == 0) {
      pos = p->pos;
      pos.x += 64;
      FUN_08015c90(1, 0, 0, 64, &pos);
    }
    if (Mod(p->timer, 16) == 0) {
      pos = p->pos;
      pos.z += 32;
      FUN_08015c90(1, 0, 0, 64, &pos);
    }
    if (Mod(p->timer, 7) == 0 && (s8)m->unk_a4 < 0) {
      PlaySound_082406e0(SONG_348);
      m->unk_a4 = 1;
    }
    p->timer++;
  } else if (finished) {
    p->state = 0;
  }
#else
  INCFUNC("asm/func/FUN_081d785c.inc");
#endif
}

// 277/279 命令, AuxSprite_AdvanceAnim の結果の受け方と r7 の持ち方が違う
NON_MATCH void FUN_081d7a60(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  EntityC60F* m = gEntityC60F;
  AuxAnimState* anim;

  if (m == NULL) {
    return;
  }

  anim = &p->anim;
  if (p->stateEntered) {
    FUN_081d7814(p);
    AuxAnim_SetAnim(anim, m->anim1, 4, 0, 0);
    AuxSprite_AdvanceAnim(&p->sprite, anim);
    p->timer = 0;
    p->stateEntered = FALSE;
    FUN_08015c90(1, 2, 0, 64, &p->sprite.pos);
  }

  if (AuxSprite_AdvanceAnim(&p->sprite, anim)) {
    p->state = 0;
    p->sprite.flags |= SPRFLAG_HIDDEN;
    FUN_08015c90(3, 2, 0, 64, &p->sprite.pos);
  }
#else
  INCFUNC("asm/func/FUN_081d7a60.inc");
#endif
}

// 0x377D
// 347/371 命令, AuxSprite_AdvanceAnim の結果の受け方とスタックの持ち方が違う, 下書き段階
NON_MATCH void Cmd_377D(void) {
#ifdef NONMATCHING_C
  EntityC60F* m = gEntityC60F;
  EntityC60FItem* p;
  Vec3* pos;
  s16 a;
  s16 b;

  if (m == NULL) {
    return;
  }
  p = EntityC60F_AllocSlot(m);
  if (p == NULL) {
    return;
  }

  p->flags = 1;
  pos = &p->pos;
  if (VM_SeekToNamedArg('p')) {
    pos->x = VM_GetValue();
    pos->y = VM_GetValue();
    pos->z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('a')) {
    a = VM_GetValue();
    b = VM_GetValue();
  } else {
    a = 0;
    b = 0;
  }
  p->hp = p->maxHp = VM_GetNamedArgValue('h', 0);
  p->sprite.pos = *pos;
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  AuxSprite_AdvanceAnim(&p->sprite, &p->anim);
  p->sprite.flags |= SPRFLAG_HIDDEN;

  p->unk_109 = VM_GetNamedArgValue('m', 0);
  if (p->unk_109 == 0) {
    Video_GetAuxSprite(&p->gfx, 0x4FDA);
    AuxAnim_SetAnim(&p->anim, m->anim0, 0, 0, 0);
    p->state = 1;
    p->sprite.priority = 3;
  } else if (p->unk_109 == 1) {
    Video_GetAuxSprite(&p->gfx, 0x863A);
    AuxAnim_SetAnim(&p->anim, m->anim1, 2, 0, 0);
    p->state = 2;
    p->flags |= 4;
    p->sprite.priority = 2;
  }

  p->unk_105 = 0;
  p->unk_f8 = Div((s16)p->hp, 3);
  FUN_081d6eb8(p);
  Map_AddTileOverride(&p->tileOverride, GetCollisionTileIdx(&p->sprite.pos), 0, p->sprite.pos.y >> 8, 0, 128);
  p->flags |= C60FITEM_TILE_OVERRIDE;
  if (VM_GetNamedArgValue('P', 0) != 0) {
    p->flags |= C60FITEM_FIXED_AREA;
  }
  p->zoneID = GetZoneAt(pos);
  if (VM_GetNamedArgValue('s', 0) == 0) {
    p->unk_108 = 0;
  } else {
    p->unk_108 = 1;
    Mover_Init(&p->unk_48, p->slotIndex + 111, pos, 0, 7, p);
    Mover_SetAuxSprite(&p->unk_48, &p->sprite);
    FUN_08002a48(&p->unk_48);
  }
#else
  INCFUNC("asm/func/Cmd_377D.inc");
#endif
}

void (*const PTR_ARRAY_085ae118[5])(EntityC60FItem*) = {
    FUN_081d6f60,
    FUN_081d7358,
    FUN_081d76bc,
    FUN_081d785c,
    FUN_081d7a60,
};  // 0x085AE118

// item->flags と zoneID の判定も bool8 inline, 定数をループ内に残す形が作れない
NON_MATCH s32 EntityC60F_Update(EntityC60F* p) {
#ifdef NONMATCHING_C
  EntityC60FItem** item = p->items;

  if (p->activeMask != 0) {
    s32 i;

    for (i = 0; i < 32; i++) {
      if (EntityC60F_IsActive(p, i)) {
        if (((*item)->flags & C60FITEM_FIXED_AREA) && gStat->zoneID != (*item)->zoneID) {
          (*item)->sprite.flags |= SPRFLAG_HIDDEN;
        } else {
          PTR_ARRAY_085ae118[(*item)->state](*item);
        }
      }
      item++;
    }
    p->unk_a4 = 0xFF;
  }

  return 0;
#else
  INCFUNC("asm/func/EntityC60F_Update.inc");
#endif
}

// item->flags の判定も bool8 inline を通している (movs #1/#0, cmp r0, #0), 定数をループ内に残して p->flags を読む形が inline で作れない
NON_MATCH s32 EntityC60F_Destroy(EntityC60F* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 32; i++) {
    if (EntityC60F_IsActive(p, i)) {
      EntityC60FItem* item = p->items[i];

      AuxSprite_Remove(&item->sprite);
      if (item->unk_108 != 0) {
        FUN_08002a58(&item->unk_48);
        Mover_Unlink(&item->unk_48);
      }
      if (item->flags & C60FITEM_TILE_OVERRIDE) {
        Map_RemoveTileOverride(&item->tileOverride);
        item->flags &= ~C60FITEM_TILE_OVERRIDE;
      }
      Free(item);
    }
  }

  gEntityC60F = NULL;
  return 0;
#else
  INCFUNC("asm/func/EntityC60F_Destroy.inc");
#endif
}

s32 EntityC60F_Init(EntityC60F* p) {
  p->anim0 = GetFile(DIR_ANIMATION, ANIM_1003);
  p->anim1 = GetFile(DIR_ANIMATION, ANIM_931E);
  gEntityC60F = p;
  p->activeMask = 0;
  p->unk_a4 = 255;
  return 0;
}

EntityC60F* EntityC60F_Create(void) {
  EntityC60F* p = CreateEntity(ENTITY_UNK_10, sizeof(EntityC60F));

  if (p != NULL) {
    SetEntityRoutine(p, EntityC60F_Update, EntityC60F_Destroy);
    if (EntityC60F_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d81b8(void) { gEntityC60F = NULL; }
