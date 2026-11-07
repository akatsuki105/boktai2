#include "coffin.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vec3.h"
#include "vm.h"

// 太陽樹の下に群がってる白い鳥 (クロウと見た目が同じだけで敵ではない)

// 鳥1羽
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxAnimState anim;      // 0x2C
  AuxSpriteGfx gfx;       // 0x3C, SPRITE_CROW
  Vec3 vel;               // 0x58
  Vec3 size;              // 0x60, Coffin との判定の半径
  u16 state;              // 0x68
  u8 unk_6a[2];           // 0x6A, まだ未解析
  s16 slotIdx;            // 0x6C, usedMask 上の自分のビット番号
  u16 flags;              // 0x6E, 根拠: Entity8CC7Elem_SetFlags / _ClearFlags / _TestFlags
  u16 timer;              // 0x70
  u16 unk_72;             // 0x72
  bool8 unk_74;           // 0x74
  u8 angle;               // 0x75
  u16 tileIdx;            // 0x76
  u8 unk_78;              // 0x78
  u8 noShadow;            // 0x79, 0 なら _Destroy が ParticleShadow_Remove を呼ぶ
  u16 unk_7a;             // 0x7A
  ParticleShadow shadow;  // 0x7C, noShadow が 0 のとき生きている影
} Entity8CC7Elem;
static_assert(sizeof(Entity8CC7Elem) == 188);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_9
  AuxAnimFile* anim;         // 0x018, ANIM_CROW
  Entity8CC7Elem elems[20];  // 0x01C, usedMask のビットが立っている要素だけ _Destroy が片付ける
  u32 usedMask;              // 0xECC, elems[i] が使用中なら bit i が立つ, _Init が 0 クリアする
  u32 unk_ed0;               // 0xED0, _Init が 0xE10 (3600) を入れる
} Entity8CC7;
static_assert(sizeof(Entity8CC7) == 3796);

static Entity8CC7* sEntity8CC7;  // 0x030001A4

Entity8CC7* Entity8CC7_Create();

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

static inline bool8 Entity8CC7_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity8CC7Elem_SetFlags(Entity8CC7Elem* e, u16 bits) { e->flags |= bits; }

void Entity8CC7Elem_ClearFlags(Entity8CC7Elem* e, u16 bits) { e->flags &= ~bits; }

// 残差は 7 命令 vs 11 命令 で、原典は 0/1 を分岐で作る (!= 0 も ?1:0 もビット演算に畳まれる)
bool8 Entity8CC7Elem_TestFlags(Entity8CC7Elem* e, u32 bits) {
  if (e->flags & bits) {
    return TRUE;
  }
  return FALSE;
}

Entity8CC7Elem* Entity8CC7_AllocElem(Entity8CC7* p) {
  s32 i;

  for (i = 0; i < 20; i++) {
    if (!Entity8CC7_IsActive(&p->usedMask, i)) {
      Entity8CC7Elem* e = &p->elems[i];

      SET_BIT(p->usedMask, i);
      ClearMemory(e, sizeof(Entity8CC7Elem));
      e->slotIdx = i;
      return e;
    }
  }
  return NULL;
}

// 0x8CC7
// 212/214 命令, 原典は e を 2 本のレジスタ (r5, r7) に持つ
NON_MATCH void Cmd_8CC7(void) {
#ifdef NONMATCHING_C
  Entity8CC7* p = sEntity8CC7;
  Entity8CC7Elem* e;

  if (p == NULL) {
    p = Entity8CC7_Create();
    if (p == NULL) {
      return;
    }
  }
  e = Entity8CC7_AllocElem(p);
  if (e == NULL) {
    return;
  }
  Video_GetAuxSprite(&e->gfx, SPRITE_CROW);
  AuxSprite_Add(&e->sprite, &e->gfx, 0);
  Video_SetAuxSpritePltt(e->sprite.gfx, 335);
  e->state = 1;
  e->unk_74 = TRUE;
  if (VM_SeekToNamedArg('p')) {
    e->sprite.pos.x = VM_GetValue();
    e->sprite.pos.y = VM_GetValue();
    e->sprite.pos.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('r')) {
    e->size.x = VM_GetValue();
    e->size.y = VM_GetValue();
    e->size.z = VM_GetValue();
  } else {
    e->size.x = Q8(1);
    e->size.y = Q8(1);
    e->size.z = Q8(1);
  }
  e->sprite.priority = 2;
  e->flags = 0;
  AuxAnim_SetAnim(&e->anim, p->anim, 4, 0, Random() & ANIM_PLAY_XFLIP);
  AuxSprite_AdvanceAnim(&e->sprite, &e->anim);
  e->noShadow = ParticleShadow_Init(&e->shadow, &e->sprite.pos, 0);
#else
  INCFUNC("asm/func/Cmd_8CC7.inc");
#endif
}

// 8bit の向きを4方位に丸めて, 左右反転するかどうかと一緒に返す
void FUN_081d8c80(u32 angle, u8* out1, u8* out2) {
  s32 dir = (((((u16)angle + 0x20) & 0xFF) >> 6) + 1) & 3;

  if (dir > 1) {
    *out2 = 1;
    *out1 = 3 - dir;
  } else {
    *out2 = 0;
    *out1 = dir;
  }
}

bool8 FUN_081d8cb0(Entity8CC7Elem* e) {
  if (gPlayerPtr[0] != NULL) {
    if (abs(e->sprite.pos.x - gPlayerPtr[0]->mover.pos.x) < e->size.x) {
      if (abs(e->sprite.pos.z - gPlayerPtr[0]->mover.pos.z) < e->size.z) {
        if (abs(e->sprite.pos.y - gPlayerPtr[0]->mover.pos.y) < e->size.y) {
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

bool8 FUN_081d8d20(Entity8CC7Elem* e) {
  WorldPos* pos = Coffin_GetPos();

  if (pos != NULL) {
    if (abs(e->sprite.pos.x - pos->x) < e->size.x) {
      if (abs(e->sprite.pos.z - pos->z) < e->size.z) {
        if (abs(e->sprite.pos.y - pos->y) < e->size.y) {
          return TRUE;
        }
      }
    }
  }
  return FALSE;
}

// 3600フレームごとに, 時間帯が 2 より後なら TRUE を返す
// 残差5命令, 原典は != 0 側 (デクリメント) を fall-through に置くが, agbcc は if/else をどちら向きに書いても == 0 側を先に並べる
NON_MATCH bool8 FUN_081d8d90(Entity8CC7* p) {
#ifdef NONMATCHING_C
  if (p->unk_ed0 != 0) {
    p->unk_ed0--;
    return FALSE;
  }

  p->unk_ed0 = 3600;
  if (Time_GetSpanOfTime() <= 2) {
    return FALSE;
  }

  return TRUE;
#else
  INCFUNC("asm/func/FUN_081d8d90.inc");
#endif
}

void nop_081d8dc0(Entity8CC7* p, Entity8CC7Elem* e) {}

// 441/441 命令, 乱数テーブルのアドレスを持つレジスタの割当だけが違う
NON_MATCH void FUN_081d8dc4(Entity8CC7* p, Entity8CC7Elem* e) {
#ifdef NONMATCHING_C
  s32 height;
  Vec3 next;
  Vec3* pos;

  if (e->unk_74) {
    u8 dir;
    u8 flip;

    e->sprite.flags &= ~SPRFLAG_HIDDEN;
    e->unk_72 = 0;
    e->unk_74 = FALSE;
    e->angle = Random();
    Vec3_SetPolar(&e->vel, e->angle, (Random() & 7) + 3);
    e->vel.y = (Random() & 15) + 4;
    e->tileIdx = GetCollisionTileIdx(&e->sprite.pos);
    FUN_081d8c80(e->angle, &dir, &flip);
    AuxAnim_SetAnim(&e->anim, p->anim, 4, dir, flip);
  }

  if (FUN_081d8cb0(e) || FUN_081d8d20(e) || TestMapFlag(MPF_RAIN) || FUN_081d8d90(p)) {
    e->state = 3;
    e->unk_74 = TRUE;
    return;
  }

  pos = &e->sprite.pos;
  height = TileHeightAt(pos);
  Vec3_Sum(&next, &e->vel, pos);
  if (GetCollisionTileIdx(&next) == e->tileIdx) {
    e->sprite.pos = next;
  } else {
    e->vel.x = 0;
    e->vel.z = 0;
    e->sprite.pos.y = next.y;
  }
  e->vel.y -= 2;
  if (height < e->sprite.pos.y) {
    AuxSprite_AdvanceAnim(&e->sprite, &e->anim);
    e->unk_72++;
  } else {
    e->sprite.pos.y = height;
    Vec3_Clear(&e->vel);
    e->state = 1;
    e->unk_74 = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_081d8dc4.inc");
#endif
}

void FUN_081d919c(Entity8CC7* p, Entity8CC7Elem* e) {
  bool32 finished;

  if (e->unk_74) {
    u16* table = gRandomTable;

    e->timer = (_Random(table) & 127) + 90;
    e->unk_74 = FALSE;
    if ((u8)_Random(table) < 24) {
      Entity8CC7Elem_SetFlags(e, 1);
      e->timer += 60;
    }
  }

  if (FUN_081d8cb0(e) || FUN_081d8d20(e) || TestMapFlag(MPF_RAIN) || FUN_081d8d90(p)) {
    e->state = 3;
    e->unk_74 = TRUE;
    return;
  }

  if (Entity8CC7Elem_TestFlags(e, 1) && e->timer <= 40) {
    u8 dir;
    u8 flip;

    FUN_081d8c80(e->angle, &dir, &flip);
    AuxAnim_SetAnim(&e->anim, p->anim, 6, dir, flip);
    Entity8CC7Elem_ClearFlags(e, 1);
  }

  finished = AuxSprite_AdvanceAnim(&e->sprite, &e->anim);
  if (e->timer != 0) {
    e->timer--;
  } else if (finished) {
    e->state = 2;
    e->unk_74 = TRUE;
  }
}

// 348/354 命令, 0 を保持するレジスタの置き方が違う
NON_MATCH void FUN_081d93b0(Entity8CC7* p, Entity8CC7Elem* e) {
#ifdef NONMATCHING_C
  u8 dir;
  u8 flip;

  if (e->unk_74) {
    u8* angle = &e->angle;
    u16* table;

    *angle = (((*angle + 32) & 0xFF) >> 6) << 6;
    table = gRandomTable;
    *angle = (_Random(table) & 31) - 16 + *angle;
    FUN_081d8c80(*angle, &dir, &flip);
    AuxAnim_SetAnim(&e->anim, p->anim, 7, dir, flip);
    e->unk_78 = 0;
    e->timer = 0;
    Vec3_Clear(&e->vel);
    Vec3_SetPolar(&e->vel, *angle, (_Random(table) & 7) + 2);
    e->unk_7a = gPlayerPtr[0]->mover.pos.y + 256 + (_Random(table) & 511);
    e->unk_74 = FALSE;
  }

  if (e->sprite.pos.y >= e->unk_7a) {
    e->state = 4;
    e->unk_74 = TRUE;
    return;
  }

  if (Mod(e->timer, 4) == 0) {
    e->vel.y += 2;
  }
  Vec3_Add(&e->sprite.pos, &e->vel);
  if (e->unk_78 != 0 && e->anim.cmdIdx == 5 && e->anim.tick == 0) {
    PlaySound_082406e0(CRY_CROW_WING);
  }
  if (AuxSprite_AdvanceAnim(&e->sprite, &e->anim)) {
    FUN_081d8c80(e->angle, &dir, &flip);
    AuxAnim_SetAnim(&e->anim, p->anim, 1, dir, flip);
    e->unk_78++;
  }
  e->timer++;
#else
  INCFUNC("asm/func/FUN_081d93b0.inc");
#endif
}

void FUN_081d96b8(Entity8CC7* p, Entity8CC7Elem* e) {
  if (e->unk_74) {
    u8 dir;
    u8 flip;

    e->unk_74 = FALSE;
    Vec3_SetPolar(&e->vel, e->angle, (Random() & 7) + 12);
    e->vel.y = 0;
    FUN_081d8c80(e->angle, &dir, &flip);
    AuxAnim_SetAnim(&e->anim, p->anim, 0, dir, flip);
    e->size.x = 2048, e->size.y = 2048, e->size.z = 2048;
    e->sprite.priority = 1;
  }

  e->sprite.pos.x += e->vel.x;
  e->sprite.pos.z += e->vel.z;
  AuxSprite_AdvanceAnim(&e->sprite, &e->anim);
  if (!FUN_081d8cb0(e)) {
    e->state = 5;
    e->unk_74 = TRUE;
  }
}

void FUN_081d98a0(Entity8CC7* p, Entity8CC7Elem* e) {
  if (e->unk_74) {
    AuxSprite_Remove(&e->sprite);
    if (!e->noShadow) {
      ParticleShadow_Remove(&e->shadow);
    }
    CLEAR_BIT(p->usedMask, e->slotIdx);
    e->slotIdx = -1;
    e->unk_74 = FALSE;
  }
  e->state = 0;
  e->unk_74 = TRUE;
}

void (*const PTR_ARRAY_085ae12c[6])(Entity8CC7*, Entity8CC7Elem*) = {
    nop_081d8dc0,
    FUN_081d919c,
    FUN_081d8dc4,
    FUN_081d93b0,
    FUN_081d96b8,
    FUN_081d98a0,
};  // 0x085AE12C

// 残差は 1 命令, usedMask のアドレスを r6 へ置く位置と elems の複写
NON_MATCH s32 Entity8CC7_Update(Entity8CC7* p) {
#ifdef NONMATCHING_C
  Entity8CC7Elem* elems = p->elems;

  if (p->usedMask != 0) {
    s32 i;

    for (i = 0; i < 20; i++) {
      if (Entity8CC7_IsActive(&p->usedMask, i)) {
        PTR_ARRAY_085ae12c[elems[i].state](p, &elems[i]);
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Entity8CC7_Update.inc");
#endif
}

s32 Entity8CC7_Destroy(Entity8CC7* p) {
  s32 i;

  for (i = 0; i < 20; i++) {
    if (Entity8CC7_IsActive(&p->usedMask, i)) {
      Entity8CC7Elem* e = &p->elems[i];

      AuxSprite_Remove(&e->sprite);
      if (!e->noShadow) {
        ParticleShadow_Remove(&e->shadow);
      }
    }
  }
  sEntity8CC7 = NULL;
  return 0;
}

s32 Entity8CC7_Init(Entity8CC7* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_CROW);
  sEntity8CC7 = p;
  p->usedMask = 0;
  p->unk_ed0 = 3600;
  return 0;
}

Entity8CC7* Entity8CC7_Create(u32 id) {
  if (sEntity8CC7 == NULL) {
    Entity8CC7* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity8CC7));

    if (p != NULL) {
      SetEntityRoutine(p, Entity8CC7_Update, Entity8CC7_Destroy);
      if (Entity8CC7_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return sEntity8CC7;
}

void ClearEntity8CC7(void) { sEntity8CC7 = NULL; }
