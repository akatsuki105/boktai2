#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sound.h"
#include "sprite_aux.h"

// src/boss/ringo.c の "ヴァンパイアソード", 小さい剣を何本か自分の周りに浮かべて次々に飛ばす攻撃

typedef struct {
  u8 unk_0;            // 0x000, まだ未解析
  bool8 stateEntered;  // 0x001, state を変えるたびに 1 を書く
  u8 state;            // 0x002, sVampireSwordStates の添字
  u8 plttState;        // 0x003, いま設定してあるパレットの種別
  u8 plttWanted;       // 0x004, 0 で 301, 1 で 304, 2 で 305 にする
  u8 unk_5[3];         // 0x005, まだ未解析
  u16 timer;           // 0x008, state を変えるたびに 0 に戻る
  u16 duration;        // 0x00A, timer がここに届くと state 1 へ移る
  u8 unk_c;            // 0x00C, 初期化で 0 を書く
  s8 angle;            // 0x00D, sprite の +0x06 に -(angle + 0x60) として入れる向き
  u8 unk_e[14];        // 0x00E, まだ未解析
  HitboxData hitbox;   // 0x01C, flags 0x2001, ignoreMask 0x10, 攻撃側
  HitboxData hurtbox;  // 0x06C, flags 0x4005, ignoreMask 0x10, 被弾側
  AuxSprite sprite;    // 0x0BC, AFFINE|UNK_0, +0x1C の Vec3 を両方の Hitbox_SetPos に渡す
  AuxSpriteGfx gfx;    // 0x0E8, SPRITE_SLAVE_SWORD_AX
} VampireSword;
static_assert(sizeof(VampireSword) == 260);

typedef struct VampireSwordManager {
  Entity e;               // 0x000, ENTITY_UNK_8
  u32 activeMask;         // 0x018, 立っているビットの枠だけ Update が回す
  u16 attackID;           // 0x01C, Init の第2引数, 各枠の Hitbox_SetAttack に渡す
  u16 power;              // 0x01E, 10, 各枠の Hitbox_SetPowerAndAttributes に渡す
  VampireSword elems[8];  // 0x020
} VampireSwordManager;
static_assert(sizeof(VampireSwordManager) == 2112);

// 状態を入れ替えて経過フレームを0に戻す
static inline void VampireSword_SetState(VampireSword* p, u8 state) {
  p->state = state;
  p->stateEntered = TRUE;
  p->timer = 0;
}

void VampireSword_StateWait(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateAppear(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateAim(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateFly(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateVanish(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateBounce(VampireSwordManager*, VampireSword*, s32);

// VampireSwordManager_Update が引く
void (*const sVampireSwordStates[6])(VampireSwordManager*, VampireSword*, s32) = {
    VampireSword_StateWait,
    VampireSword_StateAppear,
    VampireSword_StateAim,
    VampireSword_StateFly,
    VampireSword_StateVanish,
    VampireSword_StateBounce,
};  // 0x085AB9EC

// 空いている枠を先頭から探して添字も返す
VampireSword* VampireSwordManager_FindFree(VampireSwordManager* p, u32* outIndex) {
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
void VampireSword_OnHurt(HitboxData* a, HitboxData* b, VampireSword* owner) {
  VampireSword_SetState(owner, 5);
  PlaySound_082406e0(SONG_368);
}

void VampireSword_OnHit(void) {}

NAKED s32 VampireSword_Init(VampireSwordManager* p, VampireSword* elem, s32 index) { INCFUNC("asm/func/VampireSword_Init.inc"); }

// 原典は return を書き忘れている
s32 VampireSword_Destroy(VampireSwordManager* p, VampireSword* elem, s32 index) {
  Hitbox_Unregister(&elem->hurtbox);
  AuxSprite_Remove(&elem->sprite);
}

// 枠を片付けて使用中ビットを落とす, 原典は return を書き忘れている
s32 VampireSword_Release(VampireSwordManager* p, VampireSword* elem, s32 index) {
  HitboxData* hitbox;

  elem->sprite.flags |= SPRFLAG_HIDDEN;
  hitbox = &elem->hurtbox;
  hitbox->flags |= HBFLAG_HIDDEN;
  p->activeMask &= ~(1 << index);
}

// duration まで待ってから state 1 へ移る
void VampireSword_StateWait(VampireSwordManager* p, VampireSword* elem, s32 index) {
  if (elem->stateEntered != 0) {
    elem->stateEntered = FALSE;
  }
  if (elem->timer >= elem->duration) {
    VampireSword_SetState(elem, 1);
    PlaySound_082406e0(SONG_365);
  }
  elem->timer++;
}

NAKED void VampireSword_StateAppear(VampireSwordManager* p, VampireSword* elem, s32 index) { INCFUNC("asm/func/VampireSword_StateAppear.inc"); }

NAKED void VampireSword_StateAim(VampireSwordManager* p, VampireSword* elem, s32 index) { INCFUNC("asm/func/VampireSword_StateAim.inc"); }

NAKED void VampireSword_StateFly(VampireSwordManager* p, VampireSword* elem, s32 index) { INCFUNC("asm/func/VampireSword_StateFly.inc"); }

// 0x20 フレーム経ったら枠を片付ける
void VampireSword_StateVanish(VampireSwordManager* p, VampireSword* elem, s32 index) {
  if (elem->stateEntered != 0) {
    HitboxData* hitbox;

    elem->stateEntered = FALSE;
    hitbox = &elem->hurtbox;
    hitbox->flags |= HBFLAG_HIDDEN;
    elem->plttWanted = 0;
  }
  if (elem->timer >= 32) {
    VampireSword_Release(p, elem, index);
  } else {
    elem->timer++;
  }
}

NAKED void VampireSword_StateBounce(VampireSwordManager* p, VampireSword* elem, s32 index) { INCFUNC("asm/func/VampireSword_StateBounce.inc"); }

NAKED s32 VampireSwordManager_Update(VampireSwordManager* p) { INCFUNC("asm/func/VampireSwordManager_Update.inc"); }

s32 VampireSwordManager_Destroy(VampireSwordManager* p) {
  VampireSword* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    VampireSword_Destroy(p, elem, i);
  }
  return 0;
}

s32 VampireSwordManager_Init(VampireSwordManager* p, u32 attackID) {
  VampireSword* elem;
  s32 i;

  p->attackID = attackID;
  p->power = 10;
  elem = &p->elems[0];
  for (i = 0; i < 8; i++, elem++) {
    VampireSword_Init(p, elem, i);
  }
  return 0;
}

VampireSwordManager* VampireSwordManager_Create(u32 attackID) {
  VampireSwordManager* p = CreateEntity(ENTITY_UNK_8, sizeof(VampireSwordManager));

  if (p != NULL) {
    SetEntityRoutine(p, VampireSwordManager_Update, VampireSwordManager_Destroy);
    if (VampireSwordManager_Init(p, attackID) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 VampireSwordManager_Spawn(VampireSwordManager* p, Vec3* pos, u32 kind, Vec3* target, u32 param_5, u32 param_6) { INCFUNC("asm/func/VampireSwordManager_Spawn.inc"); }
