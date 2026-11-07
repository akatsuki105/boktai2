#include "enemy.h"
#include "enemy_inline.h"
#include "global.h"
#include "malloc.h"
#include "player.h"
#include "sound.h"

// クロウ(ENEID_CROW), ガーゴイル(ENEID_GARGOYLE)
typedef struct {
  Enemy e;
  u8 unk_654[1728 - sizeof(Enemy)];
} Crow;
static_assert(sizeof(Crow) == 1728);

void FUN_08144b70(Crow* p);
void FUN_081436b4(Crow*);
void FUN_081439d8(Crow*);
void FUN_08143dd4(Crow*);
void FUN_08143ef8(Crow*);
void FUN_08143fac(Crow*);
void FUN_08144cd0(Crow*);
void FUN_08144ec8(Crow*);
void FUN_081452cc(Crow*);

void (*const PTR_ARRAY_085ad828[5])(Crow*) = {
    FUN_08143dd4,
    FUN_081439d8,
    FUN_081436b4,
    FUN_08143ef8,
    FUN_08143fac,
};  // 0x085AD828

const u32 u32_ARRAY_085ad83c[4] = {4, 6, 8, 10};  // 0x085AD83C

void (*const PTR_ARRAY_085ad84c[3])(Crow*) = {
    FUN_08144cd0,
    FUN_08144ec8,
    FUN_081452cc,
};  // 0x085AD84C

void FUN_08144160(Crow*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085ad858[7])(Crow*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_08144160,
};  // 0x085AD858

NAKED void Crow_OnHit(HitboxData* a, HitboxData* b, Crow* p) { INCFUNC("asm/func/Crow_OnHit.inc"); }

NAKED void Crow_OnHurt(HitboxData* a, HitboxData* b, Crow* p) { INCFUNC("asm/func/Crow_OnHurt.inc"); }

void FUN_08142fd8(Crow* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
  FUN_08144b70(p);
}

NAKED void FUN_08143004(Crow* p, s32 timer) { INCFUNC("asm/func/FUN_08143004.inc"); }

NAKED void FUN_08143094(Crow* p) { INCFUNC("asm/func/FUN_08143094.inc"); }

NAKED void FUN_0814312c(Crow* p) { INCFUNC("asm/func/FUN_0814312c.inc"); }

NAKED void FUN_081431e0(Crow* p) { INCFUNC("asm/func/FUN_081431e0.inc"); }

void FUN_081432ec(Crow* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 15);
}

NAKED void FUN_08143310(Crow* p, s32 timer) { INCFUNC("asm/func/FUN_08143310.inc"); }

NAKED void FUN_081434e0(Crow* p, s32 timer) { INCFUNC("asm/func/FUN_081434e0.inc"); }

NAKED void FUN_081436b4(Crow* p) { INCFUNC("asm/func/FUN_081436b4.inc"); }

NAKED void FUN_081439d8(Crow* p) { INCFUNC("asm/func/FUN_081439d8.inc"); }

NAKED void FUN_08143dd4(Crow* p) { INCFUNC("asm/func/FUN_08143dd4.inc"); }

NAKED void FUN_08143ef8(Crow* p) { INCFUNC("asm/func/FUN_08143ef8.inc"); }

NAKED void FUN_08143fac(Crow* p) { INCFUNC("asm/func/FUN_08143fac.inc"); }

void FUN_0814414c(Crow* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad828; }

NAKED void FUN_08144160(Crow* p, u16* msg) { INCFUNC("asm/func/FUN_08144160.inc"); }

NAKED void Crow_OnReset(Crow* p) { INCFUNC("asm/func/Crow_OnReset.inc"); }

NAKED void FUN_08144414(Crow* p) { INCFUNC("asm/func/FUN_08144414.inc"); }

NAKED void FUN_08144608(Crow* p) { INCFUNC("asm/func/FUN_08144608.inc"); }

void Crow_InitHitboxes(Crow* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 42, 96, 42);
  VEC3_SET(hurtOffset, 0, 0, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Crow_OnHurt, p);
  VEC3_SET(hitSize, 16, 84, 16);
  VEC3_SET(hitOffset, 0, 0, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Crow_OnHit, 0, p);
}

// 状態に入ってからの時間が経つほど移動を速くする
s32 FUN_081446fc(Crow* p) {
  s32 t = (p->e).subStateTimer;
  s32 i;

  if (t < 30) {
    i = 0;
  } else if (t < 50) {
    i = 1;
  } else if (t < 70) {
    i = 2;
  } else {
    i = 3;
  }
  return u32_ARRAY_085ad83c[i];
}

NAKED void FUN_0814472c(Crow* p, Vec3* pos) { INCFUNC("asm/func/FUN_0814472c.inc"); }

void Crow_InitAnims(Crow* p) {
  Enemy_SetAnimEntry(&p->e, 0, 4, 0);
  Enemy_SetAnimEntry(&p->e, 1, 0, 0);
  Enemy_SetAnimEntry(&p->e, 2, 2, 0);
  Enemy_SetAnimEntry(&p->e, 3, 3, 0);
  Enemy_SetAnimEntry(&p->e, 15, 1, 0);
  Enemy_SetAnimEntry(&p->e, 16, 6, 0);
  Enemy_SetAnimEntry(&p->e, 17, 7, 0);
  Enemy_SetAnimEntry(&p->e, 18, 5, 0);
  Enemy_SetAnimEntry(&p->e, 10, 3, 0);
}

NAKED void FUN_081447cc(Crow* p) { INCFUNC("asm/func/FUN_081447cc.inc"); }

NAKED void FUN_0814480c(u16 angle, s32* outX, s32* outY) { INCFUNC("asm/func/FUN_0814480c.inc"); }

NAKED void FUN_0814483c(Crow* p, Vec3* pos) { INCFUNC("asm/func/FUN_0814483c.inc"); }

NAKED void FUN_081448d8(Crow* p) { INCFUNC("asm/func/FUN_081448d8.inc"); }

NAKED void FUN_08144910(Crow* p) { INCFUNC("asm/func/FUN_08144910.inc"); }

NAKED void FUN_081449f8(Crow* p) { INCFUNC("asm/func/FUN_081449f8.inc"); }

// 羽ばたきアニメの決まったコマで羽音を鳴らす
void FUN_08144b70(Crow* p) {
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (anim->cmdIdx == 5 && anim->tick == 0) {
    PlaySound_082406e0(CRY_CROW_WING);
  }
}

NAKED bool8 FUN_08144b90(Crow* p) { INCFUNC("asm/func/FUN_08144b90.inc"); }

NAKED void FUN_08144bfc(Crow* p) { INCFUNC("asm/func/FUN_08144bfc.inc"); }

s32 FUN_08144cb8(Crow* p) {
  FUN_08144414(p);
  return 1;
}

s32 FUN_08144cc4(Crow* p) {
  FUN_081449f8(p);
  return 1;
}

NAKED void FUN_08144cd0(Crow* p) { INCFUNC("asm/func/FUN_08144cd0.inc"); }

NAKED void FUN_08144ec8(Crow* p) { INCFUNC("asm/func/FUN_08144ec8.inc"); }

NAKED void FUN_081452cc(Crow* p) { INCFUNC("asm/func/FUN_081452cc.inc"); }

void FUN_08145424(Crow* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad84c; }

s32 FUN_08145438(Crow* p) {
  FUN_08144cb8(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  FUN_08144cc4(p);
  return 1;
}

s32 Crow_Update(Crow* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

NAKED s32 Crow_Destroy(Crow* p) { INCFUNC("asm/func/Crow_Destroy.inc"); }

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 Crow_Init(Crow* p) { INCFUNC("asm/func/Crow_Init.inc"); }

void Crow_Create(void) {
  Crow* p = Malloc(sizeof(Crow));

  if (p != NULL) {
    ClearMemory(p, sizeof(Crow));
    if (Crow_Init(p) < 0) {
      Crow_Destroy(p);
      Free(p);
    }
  }
}
