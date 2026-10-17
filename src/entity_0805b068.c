#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

typedef struct {
  bool8 active;             // 0x000, 初期化で 1 を書く
  u8 state;                 // 0x001, PTR_ARRAY_085aba04 の添字
  u8 unk_2[4];              // 0x002, まだ未解析
  u16 timer;                // 0x006, 初期化で 0 を書く
  u8 unk_8[2];              // 0x008, まだ未解析
  u8 angle;                 // 0x00A, 被弾したとき攻撃元への角度を入れる
  u8 unk_b;                 // 0x00B, 初期化で 0 を書く
  u8 unk_c[6];              // 0x00C, まだ未解析
  u16 hp;                   // 0x012, 被弾で相手の damage の分だけ減り、0 で state 6 へ移る
  Vec3 pos;                 // 0x014, 両方の Hitbox_SetPos に渡す
  u8 unk_1c[0x44 - 0x1C];   // 0x01C, まだ未解析
  Vec3* target;             // 0x044, 向きを合わせる相手の座標
  u8 unk_48[0x48 - 0x48];   // 0x048
  HitboxData attackHitbox;  // 0x048, flags 0x2001, ignoreMask 0x10, 攻撃側
  HitboxData bodyHitbox;    // 0x098, flags 0x5005, ignoreMask 0x10, 被弾側
  AuxAnimState animState;   // 0x0E8, sprites[0] の再生状態
  AuxSprite sprites[4];     // 0x0F8, [0] は priority 1 でアニメ付き, [1..3] は priority 2
  AuxSpriteGfx gfx;         // 0x1A8, SPRITE_EFF_3668, パレット 200
} Entity0805b068Elem;
static_assert(sizeof(Entity0805b068Elem) == 452);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  u32 activeMask;               // 0x018, 立っているビットの枠だけ Update が回す
  u16 attackID;                 // 0x01C, Init の第2引数, 各枠の Hitbox_SetAttack に渡す
  u16 power;                    // 0x01E, Init の第3引数, 各枠の Hitbox_SetPowerAndAttributes に渡す
  AuxAnimFile* anim;            // 0x020, ANIM_78E1
  Entity0805b068Elem elems[8];  // 0x024
} Entity0805b068;

// 状態を入れ替えて経過フレームを0に戻す
static inline void Entity0805b068Elem_SetState(Entity0805b068Elem* p, u8 state) {
  p->state = state;
  p->active = TRUE;
  p->timer = 0;
}
static_assert(sizeof(Entity0805b068) == 3652);

void FUN_0805a938(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805a988(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805a9e8(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805ab18(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805ab70(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805ad78(Entity0805b068*, Entity0805b068Elem*, s32);
void FUN_0805ae44(Entity0805b068*, Entity0805b068Elem*, s32);

// Entity0805b068_Update が引く
void (*const PTR_ARRAY_085aba04[7])(Entity0805b068*, Entity0805b068Elem*, s32) = {
    FUN_0805a938,
    FUN_0805a988,
    FUN_0805a9e8,
    FUN_0805ab18,
    FUN_0805ab70,
    FUN_0805ad78,
    FUN_0805ae44,
};  // 0x085ABA04

NAKED void FUN_0805a470(HitboxData* a, HitboxData* b, Entity0805b068Elem* owner) { INCFUNC("asm/func/FUN_0805a470.inc"); }

// 当たったら状態4 (被弾) へ入れ直す
void FUN_0805a52c(HitboxData* a, HitboxData* b, Entity0805b068Elem* owner) { Entity0805b068Elem_SetState(owner, 4); }

NAKED s32 FUN_0805a53c(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a53c.inc"); }

// 原典は return を書き忘れている
s32 FUN_0805a6c8(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) {
  AuxSprite* spr;
  s32 i;

  Hitbox_Unregister(&elem->bodyHitbox);
  spr = &elem->sprites[0];
  for (i = 3; i >= 0; i--, spr++) {
    AuxSprite_Remove(spr);
  }
}

// 枠を片付けて使用中ビットを落とす, 原典は return を書き忘れている
s32 FUN_0805a6ec(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) {
  AuxSprite* spr = &elem->sprites[0];
  HitboxData* hitbox;
  s32 i;

  for (i = 0; i < 4; i++, spr++) {
    spr->flags |= SPRFLAG_HIDDEN;
  }
  hitbox = &elem->bodyHitbox;
  hitbox->flags |= HBFLAG_UNK_2;
  p->activeMask &= ~(1 << index);
}

NAKED void FUN_0805a728(Entity0805b068Elem* elem) { INCFUNC("asm/func/FUN_0805a728.inc"); }

// sprites[1..3] を見せる
// 残差1命令, 原典は AND のマスクをループ変数の初期化より前に作る (FUN_0805a8d0 と同じ)
NON_MATCH void FUN_0805a8b0(Entity0805b068Elem* elem) {
#ifdef NONMATCHING_C
  AuxSprite* spr = &elem->sprites[1];
  s32 i;

  for (i = 2; i >= 0; i--, spr++) {
    spr->flags &= ~SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_0805a8b0.inc");
#endif
}

// sprites[1..3] を隠す
// 残差1命令, 原典は OR のマスク 1 をループ変数の初期化より前に作るが, こちらは後に作る
// Tier A-C 試済: 添字形の前進ループ (agbcc が反転する) / spr++ をループ本体に / AuxSprite_SetFlags 経由
NON_MATCH void FUN_0805a8d0(Entity0805b068Elem* elem) {
#ifdef NONMATCHING_C
  AuxSprite* spr = &elem->sprites[1];
  s32 i;

  for (i = 2; i >= 0; i--, spr++) {
    spr->flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_0805a8d0.inc");
#endif
}

// target の方向へ1フレーム2刻みで向きを寄せる
void FUN_0805a8f0(Entity0805b068Elem* elem) {
  Vec3* target = elem->target;
  s32 want = ArcTan2_8(target->x - elem->pos.x, target->z - elem->pos.z);
  s8 d;

  elem->unk_b = want;
  d = want - elem->angle;
  if (d < -2) {
    d = -2;
  } else if (d > 2) {
    d = 2;
  }
  elem->angle += d;
}

NAKED void FUN_0805a938(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a938.inc"); }

NAKED void FUN_0805a988(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a988.inc"); }

NAKED void FUN_0805a9e8(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805a9e8.inc"); }

NAKED void FUN_0805ab18(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805ab18.inc"); }

NAKED void FUN_0805ab70(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805ab70.inc"); }

NAKED void FUN_0805ad78(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805ad78.inc"); }

NAKED void FUN_0805ae44(Entity0805b068* p, Entity0805b068Elem* elem, s32 index) { INCFUNC("asm/func/FUN_0805ae44.inc"); }

NAKED s32 Entity0805b068_Update(Entity0805b068* p) { INCFUNC("asm/func/Entity0805b068_Update.inc"); }

s32 Entity0805b068_Destroy(Entity0805b068* p) {
  Entity0805b068Elem* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    FUN_0805a6c8(p, elem, i);
  }
  return 0;
}

s32 Entity0805b068_Init(Entity0805b068* p, u32 attackID, u32 power) {
  Entity0805b068Elem* elem;
  s32 i;

  p->attackID = attackID;
  p->power = power;
  p->anim = GetFile(DIR_ANIMATION, ANIM_78E1);
  elem = &p->elems[0];
  for (i = 0; i < 8; i++, elem++) {
    FUN_0805a53c(p, elem, i);
  }
  return 0;
}

Entity0805b068* Entity0805b068_Create(u32 param_1, u32 param_2) {
  Entity0805b068* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity0805b068));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0805b068_Update, Entity0805b068_Destroy);
    if (Entity0805b068_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 FUN_0805b0b0(unknown* p) { INCFUNC("asm/func/FUN_0805b0b0.inc"); }
