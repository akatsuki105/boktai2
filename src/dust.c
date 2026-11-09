#include "dust.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "sprite_animation.h"

// 土煙1つ分, DustManager.activeMask のビットが立っている枠だけ生きている
typedef struct {
  Vec3 pos;         // 0x00, 粒子の座標, 毎フレーム vel を足して ptcls[idx].pos に写す
  Vec3 vel;         // 0x08, 毎フレーム 7/10 に減衰する
  bool16 pausable;  // 0x10, 立っていればイベント中や通信で止められている間は更新しない
  u8 state;         // 0x12, sDustStates の添字, 出したとき 1, アニメが一巡すると 2
  s8 idx;           // 0x13, 自分の添字, ptcls と activeMask のビットを指す, 解放後は 0xFF
  u16 timer;        // 0x14, 毎フレーム +1
  s16 delay;        // 0x16, 0..15 の乱数, 0 を超えている間は数え下げるだけで何もしない
} Dust;
static_assert(sizeof(Dust) == 24);

typedef struct DustManager {
  Entity e;                // 0x000, ENTITY_UNK_9
  AuxAnimFile* anim;       // 0x018, ANIM_D1B8
  ParticleGroup* group0;   // 0x01C, PTCL_GROUP_0
  Particle ptcls[32];      // 0x020, dusts[i].idx が添字
  AuxAnimState anims[32];  // 0x520, dusts[i].idx が添字, ANIM_D1B8 の再生状態
  u32 activeMask;          // 0x720, 使用中の dusts のビットマスク
  u32 unk_724;             // 0x724
  Dust dusts[32];          // 0x728
} DustManager;
static_assert(sizeof(DustManager) == 2600);

static DustManager* gDustManager;  // 0x03000164

static inline void DustManager_SetGlobal(DustManager* p) { gDustManager = p; }

static inline bool8 DustManager_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Dust_StateIdle(DustManager* p, Dust* dust) {}

// state 1 の更新, 粒子を減速しながら動かしてアニメを1コマ進め, 一巡したら state 2 へ移す
void Dust_StateActive(DustManager* p, Dust* dust) {
  Particle* ptcl = &p->ptcls[dust->idx];

  if (dust->delay > 0) {
    dust->delay--;
    return;
  }

  ptcl->flags &= ~SPRFLAG_HIDDEN;
  dust->pos.x += dust->vel.x;
  dust->pos.y += dust->vel.y;
  dust->pos.z += dust->vel.z;
  dust->vel.x = Div(dust->vel.x * 7, 10);
  dust->vel.y = Div(dust->vel.y * 7, 10);
  dust->vel.z = Div(dust->vel.z * 7, 10);
  ptcl->pos = dust->pos;

  if (Particle_AdvanceAnim(ptcl, p->group0, &p->anims[dust->idx])) {
    dust->state = 2;
  }
  dust->timer++;
}

// スロットを解放する
void Dust_StateRelease(DustManager* p, Dust* dust) {
  Particle_Remove(&p->ptcls[dust->idx]);
  dust->state = 0;
  CLEAR_BIT(p->activeMask, dust->idx);
  ClearMemory(dust, sizeof(Dust));
  dust->idx = -1;
}

// 空いている枠を確保して返す, 空きが無ければ NULL
Dust* DustManager_Alloc(DustManager* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    if (!DustManager_IsActive(&p->activeMask, i)) {
      Dust* dust = &p->dusts[i];

      dust->idx = i;
      p->activeMask |= 1 << i;
      return dust;
    }
  }
  return NULL;
}

NAKED s32 DustManager_SpawnEx(Vec3* pos, Vec3* velRange, Vec3* posRange, u32 count, u32 priority, u32 animFlags, u32 pausable) { INCFUNC("asm/func/DustManager_SpawnEx.inc"); }

s32 DustManager_Spawn(Vec3* pos, Vec3* velRange, Vec3* posRange, u32 count, u32 priority, u32 animFlags) { return DustManager_SpawnEx(pos, velRange, posRange, count, priority, animFlags, TRUE); }

s32 DustManager_SpawnNoPause(Vec3* pos, Vec3* velRange, Vec3* posRange, u32 count, u32 priority, u32 animFlags) { return DustManager_SpawnEx(pos, velRange, posRange, count, priority, animFlags, FALSE); }

void (*const sDustStates[3])(DustManager*, Dust*) = {
    Dust_StateIdle,
    Dust_StateActive,
    Dust_StateRelease,
};  // 0x085AD320

NAKED s32 DustManager_Update(DustManager* p) { INCFUNC("asm/func/DustManager_Update.inc"); }

// 使用中の枠の粒子をまとめて外す
s32 DustManager_Destroy(DustManager* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    if (DustManager_IsActive(&p->activeMask, i)) {
      Dust* dust = &p->dusts[i];

      Particle_Remove(&p->ptcls[dust->idx]);
    }
  }
  DustManager_SetGlobal(NULL);
  return 0;
}

void DustManager_LoadFiles(DustManager* p) {
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);
}

s32 DustManager_Init(DustManager* p, u32 param_2) {
  p->unk_724 = param_2;
  DustManager_LoadFiles(p);
  return 0;
}

DustManager* DustManager_Create(u32 _, u32 __) {
  if (gDustManager == NULL) {
    DustManager* p = CreateEntity(ENTITY_UNK_9, sizeof(DustManager));
    DustManager_SetGlobal(p);
    if (p != NULL) {
      SetEntityRoutine(p, DustManager_Update, DustManager_Destroy);
      if (DustManager_Init(p, 0) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gDustManager;
}

void DustManager_ClearGlobal(void) { gDustManager = NULL; }
