#include "dust.h"

#include "entity.h"
#include "file.h"
#include "game.h"
#include "global.h"
#include "particle.h"
#include "random.h"
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

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

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

// pos の周りに土煙を count 個出す, 位置は posRange, 速度は velRange の範囲の乱数, MPF_COLD のマップでは別のアニメにする
s32 DustManager_SpawnEx(Vec3* pos, Vec3* velRange, Vec3* posRange, s32 count, u32 priority, u32 animFlags, u32 pausable) {
  DustManager* p;
  Particle* ptcl;
  s32 i;

  if (pos == NULL) {
    return -1;
  }
  p = gDustManager;
  if (p == NULL) {
    p = DustManager_Create(0, 0);
    if (p == NULL) {
      return -1;
    }
  }
  for (i = 0; i < count; i++) {
    Dust* dust = DustManager_Alloc(p);
    u32 animIdx;

    if (dust == NULL) {
      return -1;
    }
    ptcl = &p->ptcls[dust->idx];
    dust->pos = *pos;
    if (posRange->x != 0) {
      dust->pos.x += Mod(Random(), posRange->x * 2) - posRange->x;
    }
    if (posRange->y != 0) {
      dust->pos.y += Mod(Random(), posRange->y * 2) - posRange->y;
    }
    if (posRange->z != 0) {
      dust->pos.z += Mod(Random(), posRange->z * 2) - posRange->z;
    }
    if (velRange == NULL) {
      dust->vel.x = 0;
      dust->vel.y = 0;
      dust->vel.z = 0;
    } else {
      Vec3 vel;

      if (velRange->x == 0) {
        vel.x = 0;
      } else {
        vel.x = Mod(Random(), velRange->x);
      }
      if (velRange->y == 0) {
        vel.y = 0;
      } else {
        vel.y = Mod(Random(), velRange->y);
      }
      if (velRange->z == 0) {
        vel.z = 0;
      } else {
        vel.z = Mod(Random(), velRange->z);
      }
      dust->vel = vel;
    }
    dust->delay = Mod(Random(), 16);
    Particle_Add(ptcl, p->group0, 0);
    Particle_SetOffset(ptcl, -8, -8);
    animIdx = TestMapFlag(MPF_COLD) ? 14 : 13;
    AuxAnim_SetAnim(&p->anims[dust->idx], p->anim, animIdx, 0, Mod(Random(), 2) | animFlags);
    ptcl->flags |= SPRFLAG_BLINK_ODD | SPRFLAG_HIDDEN;
    ptcl->priority = priority;
    dust->state = 1;
    dust->pausable = pausable;
  }
  return 0;
}

s32 DustManager_Spawn(Vec3* pos, Vec3* velRange, Vec3* posRange, u32 count, u32 priority, u32 animFlags) { return DustManager_SpawnEx(pos, velRange, posRange, count, priority, animFlags, TRUE); }

s32 DustManager_SpawnNoPause(Vec3* pos, Vec3* velRange, Vec3* posRange, u32 count, u32 priority, u32 animFlags) { return DustManager_SpawnEx(pos, velRange, posRange, count, priority, animFlags, FALSE); }

void (*const sDustStates[3])(DustManager*, Dust*) = {
    Dust_StateIdle,
    Dust_StateActive,
    Dust_StateRelease,
};  // 0x085AD320

// 使用中の土煙を state ごとに動かす, pausable なものはイベント中や通信の待ち中は止める
// 残差はループ外に出すものの違い (67/69), 原典は 0x200 をループ外に出し &activeMask を毎周作るが, こちらは &activeMask を出し 0x200 を毎周作る
// TEST_FLAGS (両方出て r8 を使う), 条件の反転, 歩きポインタは試済
NON_MATCH s32 DustManager_Update(DustManager* p) {
#ifdef NONMATCHING_C
  if (p->activeMask != 0) {
    s32 i;

    for (i = 0; i < 32; i++) {
      if (DustManager_IsActive(&p->activeMask, i)) {
        Dust* dust = &p->dusts[i];

        if ((gGameFlags | gDebugGameFlags) & GAMEFLAG_CUTSCENE || (gGameFlags & GAMEFLAG_LINK && gSuspendFlags & (SUSPEND_LINK_WAIT | SUSPEND_PAUSE | SUSPEND_MENU))) {
          if (dust->pausable & TRUE) {
            continue;
          }
        }
        sDustStates[dust->state](p, dust);
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/DustManager_Update.inc");
#endif
}

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
