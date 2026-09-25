#include "eff_082473e0.h"

#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"

typedef struct Eff082473e0 {
  Entity e;                      // 0x00
  ParticleGroup* group;          // 0x18, Eff082473e0_Init が GetParticleGroup(PTCL_GROUP_0) を入れる。エミッタの粒子はここから取る
  AuxAnimFile* anim;             // 0x1C, Eff082473e0_Init が GetFile(DIR_ANIMATION, 0xD1B8) を入れる
  Eff082473e0Emitter* emitters;  // 0x20, 登録されているエミッタの双方向リストの先頭
} Eff082473e0;
static_assert(sizeof(Eff082473e0) == 36);

IWRAM_DATA Eff082473e0* gEff082473e0 = NULL;  // .bss, 0x030026B0

const u16 u16_ARRAY_08dbd810[4] = {3, 3, 1, 2};  // 0x08DBD810

s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);

void Eff082473e0_ClearGlobal(void) { gEff082473e0 = NULL; }

// kind 0 の更新。何もしない
void Eff082473e0Emitter_UpdateIdle(Eff082473e0* p, Eff082473e0Emitter* e) {}

// エミッタをリストの先頭に繋ぐ。既に繋がっていれば -1
s32 Eff082473e0Emitter_Register(Eff082473e0* p, Eff082473e0Emitter* e) {
  if (e->isRegistered) return -1;
  e->prev = NULL;
  e->next = p->emitters;
  if (e->next != NULL) {
    e->next->prev = e;
  }
  p->emitters = e;
  e->isRegistered = TRUE;
  return 0;
}

// エミッタをリストから外す。繋がっていなければ -1
s32 Eff082473e0Emitter_Unregister(Eff082473e0* p, Eff082473e0Emitter* e) {
  Eff082473e0Emitter* prev = e->prev;
  Eff082473e0Emitter* next = e->next;

  if (!e->isRegistered) return -1;
  if (prev != NULL) {
    prev->next = next;
  } else {
    p->emitters = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  e->isRegistered = FALSE;
  return 0;
}

// 生きている枠をひとつだけ消えかけ (state 2) にする
s32 Eff082473e0Emitter_FadeParticle(Eff082473e0Emitter* e) {
  bool32 found = FALSE;
  s32 i;

  for (i = 0; i < 4; i++) {
    Eff082473e0Particle* ptcl = &e->ptcls[i];
    if (ptcl->state == 1) {
      ptcl->state = 2;
      ptcl->unk_1 = 10;
      ptcl->unk_2 = 0;
      found = TRUE;
      break;
    }
  }
  if (found) {
    e->unk_3--;
  }
  return 0;
}

// 生きている枠をひとつ解放して、その場に粒子を撒き散らす
s32 Eff082473e0Emitter_BurstParticle(Eff082473e0Emitter* e, s32 count, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask) {
  bool32 found = FALSE;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (e->ptcls[i].state == 1) {
      Particle_Hide(&e->ptcls[i].ptcl);
      e->ptcls[i].state = 0;
      e->ptcls[i].unk_1 = 10;
      e->ptcls[i].unk_2 = 0;
      found = TRUE;
      FUN_08014730(count, e->kind, pos, vel, velRange, lifeBase, lifeRandMask);
      break;
    }
  }
  if (found) {
    e->unk_3--;
    e->activeCount--;
  }
  return 0;
}

// エミッタを待機状態に戻す。枠は全部空きにして粒子も隠す
void* Eff082473e0Emitter_Reset(Eff082473e0Emitter* e) {
  s32 i;

  e->activeCount = 0;
  e->unk_3 = 0;
  e->kind = 0;
  e->fn_12c = Eff082473e0Emitter_UpdateIdle;
  for (i = 0; i < 4; i++) {
    e->ptcls[i].state = 0;
    e->ptcls[i].unk_2 = 0;
    e->ptcls[i].unk_1 = 10;
    Particle_Hide(&e->ptcls[i].ptcl);
  }
}

NAKED s32 FUN_082467d0(Eff082473e0Emitter* e, u32 unk_1, u32 param_3, u32* param_4) { INCFUNC("asm/func/FUN_082467d0.inc"); }

// 枠を空きに戻して粒子を隠す
void Eff082473e0Particle_Clear(Eff082473e0Particle* ptcl) {
  ptcl->state = 0;
  ptcl->unk_2 = 0;
  ptcl->unk_1 = 10;
  ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
}

void FUN_082469d0(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) {}

NAKED void FUN_082469d4(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) { INCFUNC("asm/func/FUN_082469d4.inc"); }

NAKED void FUN_08246afc(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) { INCFUNC("asm/func/FUN_08246afc.inc"); }

void FUN_08246c10(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) {}

NAKED void FUN_08246c14(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) { INCFUNC("asm/func/FUN_08246c14.inc"); }

NAKED void FUN_08246d2c(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) { INCFUNC("asm/func/FUN_08246d2c.inc"); }

void FUN_08246e5c(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) {}

NAKED void FUN_08246e60(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) { INCFUNC("asm/func/FUN_08246e60.inc"); }

NAKED void FUN_08246f78(Eff082473e0* p, Eff082473e0Emitter* e, Eff082473e0Particle* ptcl) { INCFUNC("asm/func/FUN_08246f78.inc"); }

void (*const PTR_ARRAY_08dbd818[3])(Eff082473e0*, Eff082473e0Emitter*, Eff082473e0Particle*) = {
    FUN_082469d0,
    FUN_082469d4,
    FUN_08246afc,
};  // 0x08DBD818

// kind 1 の更新。エミッタの座標を画面座標に落として、生きている枠の粒子をそこにぶら下げる
NON_MATCH void FUN_082470a8(Eff082473e0* p, Eff082473e0Emitter* e) {
#ifdef NONMATCHING_C
  Eff082473e0Particle* q;
  Vec3 screen;
  s32 x, z, a, b;
  s32 i;

  x = e->pos->x >> 1;
  z = e->pos->z >> 1;
  screen.x = ((x - z) * 48) / 256;
  a = ((x + z) * 48) / 256;
  b = (e->pos->y * 24) / 256;
  screen.x = screen.x - gCameraVpCoords.x + 120;
  screen.y = (a - b) - gCameraVpCoords.y + 90;
  screen.z = (a + b) - gCameraVpCoords.z;
  for (i = 0, q = e->ptcls; i < 4; i++, q++) {
    PTR_ARRAY_08dbd818[e->ptcls[i].state](p, e, q);
    if (e->ptcls[i].state != 0) {
      e->ptcls[i].ptcl.pos.x = screen.x + e->ptcls[i].pos.x;
      e->ptcls[i].ptcl.pos.y = screen.y + e->ptcls[i].pos.y;
      e->ptcls[i].ptcl.pos.z = screen.z + e->ptcls[i].pos.z;
      e->ptcls[i].unk_2++;
    }
  }
#else
  INCFUNC("asm/func/FUN_082470a8.inc");
#endif
}

void (*const PTR_ARRAY_08dbd824[3])(Eff082473e0*, Eff082473e0Emitter*, Eff082473e0Particle*) = {
    FUN_08246c10,
    FUN_08246c14,
    FUN_08246d2c,
};  // 0x08DBD824

NAKED void FUN_08247194(Eff082473e0* p, Eff082473e0Emitter* e) { INCFUNC("asm/func/FUN_08247194.inc"); }

void (*const PTR_ARRAY_08dbd830[3])(Eff082473e0*, Eff082473e0Emitter*, Eff082473e0Particle*) = {
    FUN_08246e5c,
    FUN_08246e60,
    FUN_08246f78,
};  // 0x08DBD830

NAKED void FUN_08247280(Eff082473e0* p, Eff082473e0Emitter* e) { INCFUNC("asm/func/FUN_08247280.inc"); }

s32 Eff082473e0_Update(Eff082473e0* p) {
  Eff082473e0Emitter* e = p->emitters;

  while (e != NULL) {
    e->fn_12c(p, e);
    e = e->next;
  }
  return 0;
}

s32 Eff082473e0_Destroy(Eff082473e0* _) {
  gEff082473e0 = NULL;
  return 0;
}

s32 Eff082473e0_Init(Eff082473e0* p, u32 _) {
  gEff082473e0 = p;
  p->emitters = NULL;
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, 0xD1B8);
  return 0;
}

Eff082473e0* Eff082473e0_Create(u32 unused1, u32 unused2) {
  if (gEff082473e0 == NULL) {
    Eff082473e0* p = CreateEntity(ENTITY_UNK_9, sizeof(Eff082473e0));
    if (p != NULL) {
      SetEntityRoutine(p, Eff082473e0_Update, Eff082473e0_Destroy);
      if (Eff082473e0_Init(p, unused1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEff082473e0;
}

// エミッタを初期化して Eff082473e0 に登録する。エンティティがまだ無ければ先に作る
s32 Eff082473e0Emitter_Init(Eff082473e0Emitter* e, Vec3* pos, s32 kind, s32 unk_4, s32 unk_5) {
  Eff082473e0* p = gEff082473e0;
  s32 i;

  if (p == NULL) {
    p = Eff082473e0_Create(0, 0);
    if (p == NULL) {
      return -1;
    }
  }
  e->isRegistered = 0;
  e->pos = pos;
  e->activeCount = 0;
  e->unk_3 = 0;
  e->kind = kind;
  e->unk_4 = unk_4;
  e->unk_5 = unk_5;
  e->fn_12c = Eff082473e0Emitter_UpdateIdle;
  for (i = 0; i < 4; i++) {
    e->ptcls[i].state = 0;
    e->ptcls[i].unk_2 = 0;
    e->ptcls[i].pos.x = 0, e->ptcls[i].pos.y = 0, e->ptcls[i].pos.z = 0;
    FUN_0822d9f0(&e->ptcls[i].ptcl, gEff082473e0->group, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD);
    Particle_SetOffset(&e->ptcls[i].ptcl, -8, -8);
    e->ptcls[i].ptcl.priority = 2;
    FUN_08236fac(&e->ptcls[i].anim, gEff082473e0->anim, 0, 0, 0);
  }
  Eff082473e0Emitter_Register(p, e);
  return 0;
}

// エミッタの後始末。粒子を消してリストから外す
s32 Eff082473e0Emitter_Destroy(Eff082473e0Emitter* e) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&e->ptcls[i].ptcl);
  }
  if (gEff082473e0 != NULL) {
    Eff082473e0Emitter_Unregister(gEff082473e0, e);
  }
  return 0;
}
