#include "entity.h"
#include "global.h"
#include "link_session.h"
#include "particle.h"
#include "player.h"
#include "vec3.h"

typedef struct PitfallWarning {
  Particle ptcl;   // 0x00, PTCL0_WARNING
  u16 flags;       // 0x28, bit0 は ptcl を表示中
  u8 state;        // 0x2A
  s8 idx;          // 0x2B
  u16 spawned;     // 0x2C, 生成時に 1, 次のフレームで 0 に戻る
  u16 blinkTimer;  // 0x2E
} PitfallWarning;
static_assert(sizeof(PitfallWarning) == 48);

// 雷が光っている間, バットに変身している間, GOOD_SEE の間、 落とし穴に(点滅して)表示される警告マーク
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  ParticleGroup* group0;        // 0x018, PTCL_GROUP_0
  PitfallWarning warnings[12];  // 0x01C
  u32 activeMask;               // 0x25C, warnings の使用中ビット
} PitfallWarningManager;
static_assert(sizeof(PitfallWarningManager) == 608);

static PitfallWarningManager* sPitfallWarningManager;  // 0x030001D4

extern s32 gLightningTimer;

static inline bool8 PitfallWarningManager_IsWarningUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

PitfallWarningManager* PitfallWarningManager_Create(void);

void PitfallWarning_UpdateState0(PitfallWarningManager* p, PitfallWarning* warning) {}

PitfallWarning* PitfallWarningManager_AllocWarning(PitfallWarningManager* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!PitfallWarningManager_IsWarningUsed(&p->activeMask, i)) {
      PitfallWarning* warning = &p->warnings[i];

      p->activeMask |= 1 << i;
      warning->idx = i;
      return warning;
    }
  }
  return NULL;
}

// 千里眼の判定を 0/1 に落とす inline (GetLocalPlayerIdx と Player の goodCond 判定) にすると 120/120 命令まで揃うが, 0 の初期化を原典はタイマーを読んだ後に置く, BambooShootManager_Init と同じ壁
NON_MATCH void PitfallWarning_UpdateState1(PitfallWarningManager* p, PitfallWarning* warning) {
#ifdef NONMATCHING_C
  Particle* ptcl = &warning->ptcl;
  bool8 visible = FALSE;

  if (warning->spawned) {
    warning->spawned = 0;
  }
  if (gGameFlags & GAMEFLAG_LINK) {
    if (gLinkSession != NULL && gLinkSession->playerIdx >= 0) {
      Player* pl = gPlayerPtr[gLinkSession->playerIdx];

      if (pl != NULL && pl->goodCondTimer != 0 && pl->goodCondID == GOOD_SEE) {
        visible = TRUE;
      }
    }
  } else if (gLightningTimer > 0 || gStat->playerKind == PLAYER_BAT || (gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE)) {
    visible = TRUE;
  }
  if (visible) {
    if (!(warning->flags & 1)) {
      ptcl->flags &= ~SPRFLAG_HIDDEN;
      warning->flags |= 1;
    }
    if (warning->blinkTimer != 0) {
      warning->blinkTimer--;
    } else {
      if (warning->ptcl.flags & SPRFLAG_HIDDEN) {
        warning->ptcl.flags &= ~SPRFLAG_HIDDEN;
      } else {
        warning->ptcl.flags |= SPRFLAG_HIDDEN;
      }
      warning->blinkTimer = 38;
    }
  } else {
    ptcl->flags |= SPRFLAG_HIDDEN;
    warning->flags &= ~1;
    warning->blinkTimer = 38;
  }
#else
  INCFUNC("asm/func/PitfallWarning_UpdateState1.inc");
#endif
}

void PitfallWarning_UpdateState2(PitfallWarningManager* p, PitfallWarning* warning) {
  PitfallWarningManager* p2;

  if (warning->spawned) {
    warning->spawned = 0;
  }
  p2 = sPitfallWarningManager;
  CLEAR_BIT(p2->activeMask, warning->idx);
  warning->state = 0;
  Particle_Remove(&warning->ptcl);
  warning->idx = -1;
  warning->flags = 0;
}

// pos の少し上に点滅する目印を1つ出す
PitfallWarning* PitfallWarning_Spawn(Vec3* pos) {
  PitfallWarningManager* p = sPitfallWarningManager;
  PitfallWarning* warning;

  if (p == NULL) {
    p = PitfallWarningManager_Create();
    if (p == NULL) {
      return NULL;
    }
  }
  warning = PitfallWarningManager_AllocWarning(p);
  if (warning == NULL) {
    return NULL;
  }
  warning->state = 1;
  warning->flags = 0;
  warning->blinkTimer = 0;
  warning->spawned = 1;
  warning->ptcl.pos = *pos;
  warning->ptcl.pos.y += 30;
  Particle_Add(&warning->ptcl, p->group0, 0);
  Particle_SetOffset(&warning->ptcl, -8, -8);
  Particle_SetPose(&warning->ptcl, p->group0, PTCL0_WARNING);
  warning->ptcl.flags |= SPRFLAG_HIDDEN;
  warning->ptcl.priority = 1;
  return warning;
}

s32 PitfallWarningManager_Update(PitfallWarningManager* p) {
  static void (*const sPitfallWarningUpdates[3])(PitfallWarningManager*, PitfallWarning*) = {
      PitfallWarning_UpdateState0,
      PitfallWarning_UpdateState1,
      PitfallWarning_UpdateState2,
  };  // 0x085AE4E0

  PitfallWarning* warnings = p->warnings;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 12; i++) {
    if (PitfallWarningManager_IsWarningUsed(&p->activeMask, i)) {
      sPitfallWarningUpdates[warnings[i].state](p, &warnings[i]);
    }
  }
  return 0;
}

s32 PitfallWarningManager_Destroy(PitfallWarningManager* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (PitfallWarningManager_IsWarningUsed(&p->activeMask, i)) {
      Particle_Remove(&p->warnings[i].ptcl);
    }
  }
  sPitfallWarningManager = NULL;
  return 0;
}

s32 PitfallWarningManager_Init(PitfallWarningManager* p) {
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  p->activeMask = 0;
  sPitfallWarningManager = p;
  return 0;
}

PitfallWarningManager* PitfallWarningManager_Create(void) {
  PitfallWarningManager* p;

  if (sPitfallWarningManager != NULL) {
    return sPitfallWarningManager;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(PitfallWarningManager));
  if (p != NULL) {
    SetEntityRoutine(p, PitfallWarningManager_Update, PitfallWarningManager_Destroy);
    if (PitfallWarningManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void PitfallWarningManager_ClearGlobal(void) { sPitfallWarningManager = NULL; }
