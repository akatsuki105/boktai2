#include "cwolf_target.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// クロウ(ENEID_CROW), ガーゴイル(ENEID_GARGOYLE)
typedef struct {
  Enemy e;
  u8 unk_654[0x658 - 0x654];  // 0x654
  u32 unk_658;                // 0x658
  u8 unk_65c[0x6A0 - 0x65C];  // 0x65C
  WorldPos curveStart;        // 0x6A0, 曲線の始点
  Vec3 curveEnd;              // 0x6A8, 曲線の終点
  u8 unk_6b0[1728 - 0x6B0];   // 0x6B0
} Crow;
static_assert(sizeof(Crow) == 1728);

void Crow_PlayWingSound(Crow* p);
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

// 当たった相手が HIM_0 だけを無視する判定のときだけ攻撃対象として覚える
void Crow_OnHit(HitboxData* a, HitboxData* b, Crow* p) {
  if (b->ignoreMask == HIM_0 && Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

NAKED void Crow_OnHurt(HitboxData* a, HitboxData* b, Crow* p) { INCFUNC("asm/func/Crow_OnHurt.inc"); }

void FUN_08142fd8(Crow* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
  Crow_PlayWingSound(p);
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
s32 Crow_GetMoveSpeed(Crow* p) {
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

void Crow_SetCurve(Crow* p, Vec3* pos) {
  Crow* q = (p->e).unk_1cc;

  q->curveStart = (p->e).mover.pos;
  q->curveEnd = *pos;
}

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

// 残差は q と flags2 のアドレスの r1/r2 入れ替えのみ, 試済: q のローカル有無, Enemy_SetFlag2
NON_MATCH void FUN_081447cc(Crow* p) {
#ifdef NONMATCHING_C
  Crow* q = (p->e).unk_1cc;

  Enemy_SetFlag2(&p->e, ENEFLAG2_UNK_20);
  q->unk_658 &= ~1;
  (p->e).atkHitbox.flags &= ~HBFLAG_HIDDEN;
#else
  INCFUNC("asm/func/FUN_081447cc.inc");
#endif
}

// 8方向の向きを, 左右反転で済む5方向とその反転の有無に分ける
void Crow_GetDirAndFlip(u16 angle, s32* outDir, s32* outFlip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *outDir = 8 - dir;
    *outFlip = 1;
  } else {
    *outDir = dir;
    *outFlip = 0;
  }
}

NAKED void FUN_0814483c(Crow* p, Vec3* pos) { INCFUNC("asm/func/FUN_0814483c.inc"); }

void FUN_081448d8(Crow* p) {
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  (p->e).unk_24e = 0;
}

NAKED void FUN_08144910(Crow* p) { INCFUNC("asm/func/FUN_08144910.inc"); }

NAKED void FUN_081449f8(Crow* p) { INCFUNC("asm/func/FUN_081449f8.inc"); }

void Crow_PlayWingSound(Crow* p) {
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

s32 Crow_Destroy(Crow* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove((AuxSprite*)(p->e).sprite);
  } else {
    MainSprite_Remove(&(p->e).sprite->s);
  }
  Free((p->e).sprite);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).unk_44c) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).unk_44c = 1;
  }
  if (!(p->e).unk_44d) {
    Eff082473e0Emitter_Destroy(&(p->e).emitter);
    (p->e).unk_44d = 1;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a58(&(p->e).mover);
  }
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

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
