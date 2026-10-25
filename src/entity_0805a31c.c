#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sound.h"
#include "sprite_aux.h"

typedef struct {
  u8 unk_0;                 // 0x000, まだ未解析
  bool8 stateEntered;       // 0x001, state を変えるたびに 1 を書く
  u8 state;                 // 0x002, PTR_ARRAY_085ab9ec の添字
  u8 plttState;             // 0x003, いま設定してあるパレットの種別
  u8 plttWanted;            // 0x004, 0 で 301, 1 で 304, 2 で 305 にする
  u8 unk_5[3];              // 0x005, まだ未解析
  u16 timer;                // 0x008, state を変えるたびに 0 に戻る
  u16 duration;             // 0x00A, timer がここに届くと state 1 へ移る
  u8 unk_c;                 // 0x00C, 初期化で 0 を書く
  s8 angle;                 // 0x00D, sprite の +0x06 に -(angle + 0x60) として入れる向き
  u8 unk_e[14];             // 0x00E, まだ未解析
  HitboxData attackHitbox;  // 0x01C, flags 0x2001, ignoreMask 0x10, 攻撃側
  HitboxData bodyHitbox;    // 0x06C, flags 0x4005, ignoreMask 0x10, 被弾側
  AuxSprite sprite;         // 0x0BC, AFFINE|UNK_0, +0x1C の Vec3 を両方の Hitbox_SetPos に渡す
  AuxSpriteGfx gfx;         // 0x0E8, SPRITE_5292
} Entity0805a31cElem;
static_assert(sizeof(Entity0805a31cElem) == 260);

typedef struct Entity0805a31c {
  Entity e;                     // 0x000, ENTITY_UNK_8
  u32 activeMask;               // 0x018, 立っているビットの枠だけ Update が回す
  u16 attackID;                 // 0x01C, Init の第2引数, 各枠の Hitbox_SetAttack に渡す
  u16 power;                    // 0x01E, 10, 各枠の Hitbox_SetPowerAndAttributes に渡す
  Entity0805a31cElem elems[8];  // 0x020
} Entity0805a31c;

// 状態を入れ替えて経過フレームを0に戻す
static inline void Entity0805a31cElem_SetState(Entity0805a31cElem* p, u8 state) {
  p->state = state;
  p->stateEntered = TRUE;
  p->timer = 0;
}
static_assert(sizeof(Entity0805a31c) == 2112);

void FUN_08059d60(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_08059d98(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_08059e9c(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_08059f1c(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_0805a09c(Entity0805a31c*, Entity0805a31cElem*, s32);
void FUN_0805a0dc(Entity0805a31c*, Entity0805a31cElem*, s32);

// Entity0805a31c_Update が引く
void (*const PTR_ARRAY_085ab9ec[6])(Entity0805a31c*, Entity0805a31cElem*, s32) = {
    FUN_08059d60,
    FUN_08059d98,
    FUN_08059e9c,
    FUN_08059f1c,
    FUN_0805a09c,
    FUN_0805a0dc,
};  // 0x085AB9EC

// 空いている枠を先頭から探して添字も返す
Entity0805a31cElem* FUN_08059b7c(Entity0805a31c* p, u32* outIndex) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!(p->activeMask & (1 << i))) {
      *outIndex = i;
      return &p->elems[i];
    }
  }
  return NULL;
}

// 当たったら状態5 (被弾) へ入れ直して効果音を鳴らす
void FUN_08059bb0(HitboxData* a, HitboxData* b, Entity0805a31cElem* owner) {
  Entity0805a31cElem_SetState(owner, 5);
  PlaySound_082406e0(SONG_368);
}

void FUN_08059bcc(void) {}

NAKED s32 FUN_08059bd0(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059bd0.inc"); }

// 原典は return を書き忘れている
s32 FUN_08059d1c(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) {
  Hitbox_Unregister(&elem->bodyHitbox);
  AuxSprite_Remove(&elem->sprite);
}

// 枠を片付けて使用中ビットを落とす, 原典は return を書き忘れている
s32 FUN_08059d38(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) {
  HitboxData* hitbox;

  elem->sprite.flags |= SPRFLAG_HIDDEN;
  hitbox = &elem->bodyHitbox;
  hitbox->flags |= HBFLAG_HIDDEN;
  p->activeMask &= ~(1 << index);
}

// duration まで待ってから state 1 へ移る
void FUN_08059d60(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) {
  if (elem->stateEntered != 0) {
    elem->stateEntered = FALSE;
  }
  if (elem->timer >= elem->duration) {
    Entity0805a31cElem_SetState(elem, 1);
    PlaySound_082406e0(SONG_365);
  }
  elem->timer++;
}

NAKED void FUN_08059d98(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059d98.inc"); }

NAKED void FUN_08059e9c(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059e9c.inc"); }

NAKED void FUN_08059f1c(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_08059f1c.inc"); }

// 0x20 フレーム経ったら枠を片付ける
void FUN_0805a09c(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) {
  if (elem->stateEntered != 0) {
    HitboxData* hitbox;

    elem->stateEntered = FALSE;
    hitbox = &elem->bodyHitbox;
    hitbox->flags |= HBFLAG_HIDDEN;
    elem->plttWanted = 0;
  }
  if (elem->timer > 0x1F) {
    FUN_08059d38(p, elem, index);
  } else {
    elem->timer++;
  }
}

NAKED void FUN_0805a0dc(Entity0805a31c* p, Entity0805a31cElem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a0dc.inc"); }

NAKED s32 Entity0805a31c_Update(Entity0805a31c* p) { INCFUNC("asm/func/Entity0805a31c_Update.inc"); }

s32 Entity0805a31c_Destroy(Entity0805a31c* p) {
  Entity0805a31cElem* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    FUN_08059d1c(p, elem, i);
  }
  return 0;
}

s32 Entity0805a31c_Init(Entity0805a31c* p, u32 attackID) {
  Entity0805a31cElem* elem;
  s32 i;

  p->attackID = attackID;
  p->power = 10;
  elem = &p->elems[0];
  for (i = 0; i < 8; i++, elem++) {
    FUN_08059bd0(p, elem, i);
  }
  return 0;
}

Entity0805a31c* Entity0805a31c_Create(u32 attackID) {
  Entity0805a31c* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity0805a31c));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0805a31c_Update, Entity0805a31c_Destroy);
    if (Entity0805a31c_Init(p, attackID) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 FUN_0805a360(Entity0805a31c* p, Vec3* pos, u32 kind, Vec3* target, u32 param_5, u32 param_6) { INCFUNC("asm/func/FUN_0805a360.inc"); }
