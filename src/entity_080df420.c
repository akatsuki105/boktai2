#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"
#include "video.h"

// 1発ぶんのエフェクト
typedef struct {
  AuxSprite sprite;        // 0x00
  AuxAnimState anim;       // 0x2C
  HitboxData hitbox;       // 0x3C, 攻撃判定
  HitboxData hurtbox;      // 0x8C, 食らい判定
  Vec3 vel;                // 0xDC, 1フレームに進む量
  u8 unk_e4[0xEC - 0xE4];  // 0xE4, まだ未解析
  AuxAnimFile* animFile;   // 0xEC
  u16 unk_f0;              // 0xF0, FUN_080df148 の第4引数として子へ渡す
  u8 unk_f2;               // 0xF2
  u8 unk_f3;               // 0xF3, FUN_080df478 が 1 を入れる
  s16 flags;               // 0xF4, FUN_080de344 が bit2 を立てる
  u8 state;                // 0xF6, _Update が 0x085AD354 の関数表の添字として引く
  u8 index;                // 0xF7, FUN_080de174 が確保したスロット番号を入れる
  u16 timer;               // 0xF8, FUN_080de344 が毎フレーム減らし, 0 になると 3 に戻す
  u8 unk_fa[2];            // 0xFA, まだ未解析, padding?
} Entity080df420Elem;
static_assert(sizeof(Entity080df420Elem) == 252);

typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_10
  AuxSpriteGfx gfx;              // 0x18, SPRITE_EFF_F422
  u8 unk_34[4];                  // 0x34, まだ未解析
  u32 usedMask;                  // 0x38, elems のどのスロットが使用中か, FUN_080de174 が立てる
  s16 frame;                     // 0x3C, _Update が毎フレーム 1 足す
  u16 count;                     // 0x3E, FUN_080de174 が確保のたびに 1 足す
  Entity080df420Elem elems[24];  // 0x40
} Entity080df420;
static_assert(sizeof(Entity080df420) == 6112);

IWRAM_DATA Entity080df420* gEntity080df420 = NULL;  // 0x03000178

static inline void Entity080df420_SetGlobal(Entity080df420* p) { gEntity080df420 = p; }

static inline bool8 Entity080df420_IsUsed(Entity080df420* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

void nop_080de81c(Entity080df420*, Entity080df420Elem*);
void FUN_080de820(Entity080df420*, Entity080df420Elem*);

void (*const sEntity080df420Updates[2])(Entity080df420*, Entity080df420Elem*) = {
    nop_080de81c,
    FUN_080de820,
};  // 0x085AD354

void FUN_080debbc(unknown*, unknown*);
void FUN_080de3b4(HitboxData* a, HitboxData* b, Entity080df420Elem* elem);
void FUN_080de52c(HitboxData* a, HitboxData* b, Entity080df420Elem* elem);
void Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, s32 kind);
void FUN_08240cc4(s16 x, s16 z, s16 param_3, s16 param_4, u8 param_5);
void FUN_080df148(WorldPos* pos, Vec3* vel, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9);
void FUN_080defd0(unknown*, unknown*);

void (*const PTR_ARRAY_085ad35c[2])(unknown*, unknown*) = {
    FUN_080debbc,
    FUN_080defd0,
};  // 0x085AD35C

Entity080df420Elem* FUN_080de174(Entity080df420* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    if (!Entity080df420_IsUsed(p, i)) {
      Entity080df420Elem* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      p->count++;
      elem->index = i;
      return elem;
    }
  }
  return NULL;
}

// angle に直交する面に沿って6方向へ火の粉を飛ばす
void FUN_080de1cc(Entity080df420Elem* elem, s32 angle) {
  Vec3 vel;
  s32 dir = ((angle + 32) & 0xFF) >> 6;

  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, 0, -30);
  } else {
    VEC3_SET(vel, -30, 0, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, 15, -15);
  } else {
    VEC3_SET(vel, -15, 15, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, 15, 15);
  } else {
    VEC3_SET(vel, 15, 15, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, 0, 30);
  } else {
    VEC3_SET(vel, 30, 0, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, -15, -15);
  } else {
    VEC3_SET(vel, -15, -15, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, -15, 15);
  } else {
    VEC3_SET(vel, 15, -15, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
}

// 待ちが切れた枠を1フレームに6つまで選んで攻撃判定を出させる
void FUN_080de344(Entity080df420* p) {
  Entity080df420Elem* elems = p->elems;

  if (p->count != 0) {
    s32 n = 0;
    s32 i;

    for (i = 0; i < 24; i++) {
      if (Entity080df420_IsUsed(p, i)) {
        if (elems[i].timer != 0) {
          elems[i].timer--;
        } else if (n <= 5) {
          elems[i].timer = 3;
          elems[i].flags |= 4;
          n++;
        }
      }
    }
  }
}

// 攻撃判定が当たったら, 分裂する弾なら6つの小さな弾を散らし, 火の粉と効果音を出して消滅へ移る
// 167/167命令, ループ外へ出す定数の順だけが違う (原典は &gRandTableIdx を半径 5 より先に sb へ置く), 試済: 角度を先にローカルへ
NON_MATCH void FUN_080de3b4(HitboxData* a, HitboxData* b, Entity080df420Elem* elem) {
#ifdef NONMATCHING_C
  if (elem->flags & 1) {
    s32 angle = ArcTan2_8(elem->vel.x, elem->vel.z);
    s32 i;

    for (i = 0; i < 6; i++) {
      Vec3 vel;

      Vec3_SetPolar(&vel, angle + (Random() & 0xFF), 5);
      FUN_080df148(&elem->sprite.pos, &vel, 4, elem->unk_f0, 12, elem->hitbox.power, elem->hitbox.knockbackPower, elem->hitbox.attributes, elem->hitbox.invincibleTime);
    }
  }
  FUN_080de1cc(elem, ArcTan2_8(elem->vel.x, elem->vel.z));
  FUN_08240cc4(elem->sprite.pos.x, elem->sprite.pos.z, 0, 0, 0x80);
  Hitbox_Hide(&elem->hitbox);
  Hitbox_Hide(&elem->hurtbox);
  PlaySound_082406e0(991);
  elem->state = 3;
  elem->unk_f3 = 1;
#else
  INCFUNC("asm/func/FUN_080de3b4.inc");
#endif
}

// 攻撃を食らったら, 分裂する弾なら6つの小さな弾を散らし, 火の粉と効果音を出して消滅へ移る
// 175/175命令, FUN_080de3b4 と同じループ外の定数の順に加え, スタックに置くポインタの並びが違う
NON_MATCH void FUN_080de52c(HitboxData* a, HitboxData* b, Entity080df420Elem* elem) {
#ifdef NONMATCHING_C
  if (b->invincibleTime != 0) {
    return;
  }
  if (elem->flags & 1) {
    s32 angle = ArcTan2_8(elem->vel.x, elem->vel.z);
    s32 i;

    for (i = 0; i < 6; i++) {
      Vec3 vel;

      Vec3_SetPolar(&vel, angle + (Random() & 0xFF), 5);
      FUN_080df148(&elem->sprite.pos, &vel, 4, elem->unk_f0, 12, elem->hitbox.power, elem->hitbox.knockbackPower, elem->hitbox.attributes, elem->hitbox.invincibleTime);
    }
  }
  FUN_080de1cc(elem, a->angle);
  FUN_08240cc4(elem->sprite.pos.x, elem->sprite.pos.z, 0, 0, 0x80);
  Hitbox_Hide(&elem->hitbox);
  Hitbox_Hide(&elem->hurtbox);
  PlaySound_082406e0(991);
  elem->state = 3;
  elem->unk_f3 = 1;
#else
  INCFUNC("asm/func/FUN_080de52c.inc");
#endif
}

// 攻撃判定と食らい判定を作る
// 96/98命令, 引数を受けるレジスタだけが違う (原典は elem を r6, power を sl, knockback を r7, attrs を r8 に置く), 試済: ローカルの宣言順, 2つ目の判定を hitbox++ で作る
NON_MATCH void FUN_080de6b0(Entity080df420Elem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime, s32 defPower, HitboxAttributes defAttrs, s32 defWeakness) {
#ifdef NONMATCHING_C
  HitboxData* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 32, 64, 32);
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_10 | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, invincibleTime);
  Hitbox_SetHandler(hitbox, FUN_080de3b4, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  hitbox = &elem->hurtbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, defPower, defAttrs, defWeakness);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_080de52c, elem);
  Hitbox_Register(hitbox);
#else
  INCFUNC("asm/func/FUN_080de6b0.inc");
#endif
}

// 攻撃判定を出す印が立っていれば判定を表に出して登録し, 立っていなければ隠す
void FUN_080de7a0(Entity080df420Elem* elem) {
  if (elem->hurtbox.invincibleTime != 0) {
    elem->hurtbox.invincibleTime--;
  }
  if (!(elem->flags & 4)) {
    Hitbox_Hide(&elem->hitbox);
    Hitbox_Hide(&elem->hurtbox);
  } else {
    elem->flags &= ~4;
    Hitbox_ClearFlags(&elem->hitbox, HBFLAG_HIDDEN);
    Hitbox_ClearFlags(&elem->hurtbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
    Hitbox_SetPos(&elem->hurtbox, &elem->sprite.pos, 0);
    Hitbox_Register(&elem->hitbox);
  }
}

void nop_080de81c(Entity080df420* p, Entity080df420Elem* elem) {}

NAKED void FUN_080de820(Entity080df420* p, Entity080df420Elem* param_2) { INCFUNC("asm/func/FUN_080de820.inc"); }

NAKED void FUN_080debbc(unknown* p, unknown* param_2) { INCFUNC("asm/func/FUN_080debbc.inc"); }

NAKED void FUN_080defd0(unknown* p, unknown* param_2) { INCFUNC("asm/func/FUN_080defd0.inc"); }

NAKED void FUN_080df148(WorldPos* pos, Vec3* vel, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9) { INCFUNC("asm/func/FUN_080df148.inc"); }

s32 Entity080df420_Update(Entity080df420* p) {
  Entity080df420Elem* elems = p->elems;
  s32 i;

  if (p->usedMask != 0 && !TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER) && !TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    FUN_080de344(p);
    for (i = 0; i < 24; i++) {
      if (Entity080df420_IsUsed(p, i)) {
        sEntity080df420Updates[elems[i].state](p, &elems[i]);
      }
    }
    p->frame++;
  }
  return 0;
}

s32 Entity080df420_Destroy(Entity080df420* p) {
  s32 i;
  Entity080df420Elem* e;

  for (i = 0, e = p->elems; i < 24; e++, i++) {
    if (Entity080df420_IsUsed(p, i)) {
      AuxSprite_Remove(&e->sprite);
    }
  }
  Entity080df420_SetGlobal(NULL);
  return 0;
}

s32 Entity080df420_Init(Entity080df420* p) {
  p->usedMask = 0;
  p->frame = 0;
  p->count = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_F422);
  Entity080df420_SetGlobal(p);
  return 0;
}

Entity080df420* Entity080df420_Create(void) {
  Entity080df420* p;

  if (gEntity080df420 != NULL) {
    return gEntity080df420;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080df420));
  if (p != NULL) {
    SetEntityRoutine(p, Entity080df420_Update, Entity080df420_Destroy);
    if (Entity080df420_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void FUN_080df46c(void) { gEntity080df420 = NULL; }

// 使用中の枠を全部 state 3 へ移す
void FUN_080df478(void) {
  Entity080df420* p = gEntity080df420;
  Entity080df420Elem* e;
  s32 i;

  if (p == NULL) {
    return;
  }
  if (p->usedMask == 0) {
    return;
  }

  for (i = 0; i < 24; i++) {
    e = &p->elems[i];
    if (Entity080df420_IsUsed(p, i)) {
      e->state = 3;
      e->unk_f3 = 1;
    }
  }
}
