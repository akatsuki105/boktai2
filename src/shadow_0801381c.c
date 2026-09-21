#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "particle.h"
#include "shadow.h"
#include "sprite.h"

typedef struct ParticleShadowManager {
  Entity e;               // ENTITY_UNK_9
  ParticleGroup* group0;  // 0x18, PTCL_GROUP_0
  ParticleShadow* head;   // 0x1C, 影のリストの先頭, 対象座標から床の高さを求めて影パーティクルを配置し、床がなければ非表示にする
} ParticleShadowManager;
static_assert(sizeof(ParticleShadowManager) == 32);

IWRAM_DATA ParticleShadowManager* gParticleShadowManager = NULL;  // 0x03000050

void ParticleShadow_FollowGround(ParticleShadow* shadow);

void FUN_08013634(void) { gParticleShadowManager = NULL; }

// リネーム案: ShadowList_Add
s32 ParticleShadowManager_Add(ParticleShadowManager* p, ParticleShadow* shadow) {
  ParticleShadow* head;

  if (shadow->active != 0) return -1;

  shadow->prev = NULL;
  head = p->head;
  shadow->next = head;
  if (head != NULL) {
    head->prev = shadow;
  }
  p->head = shadow;
  shadow->active = 1;
  return 0;
}

// リネーム案: ShadowList_Remove
s32 ParticleShadowManager_Remove(ParticleShadowManager* p, ParticleShadow* shadow) {
  ParticleShadow* prev = shadow->prev;
  ParticleShadow* next = shadow->next;

  if (shadow->active == 0) return -1;

  if (prev != NULL) {
    prev->next = next;
  } else {
    p->head = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  shadow->active = 0;
  return 0;
}

// 影を表示し、床に追従する更新関数に切り替えてすぐ1回呼ぶ, リネーム案: Shadow_Show
void ParticleShadow_Show(ParticleShadow* shadow) {
  shadow->particle.flags &= ~SPRFLAG_HIDDEN;
  shadow->updateCallback = ParticleShadow_FollowGround;
  shadow->updateCallback(shadow);
}

// 影を非表示にし、何もしない更新関数に切り替える, リネーム案: Shadow_Hide
void ParticleShadow_Hide(ParticleShadow* shadow) {
  shadow->particle.flags |= SPRFLAG_HIDDEN;
  shadow->updateCallback = ParticleShadow_UpdateNone;
}

// 非表示中の影の更新関数 (何もしない), リネーム案: Shadow_UpdateNone
void ParticleShadow_UpdateNone(ParticleShadow* shadow) {}

// 持ち主の足元の床の高さに影を置き、床がない・持ち主より高い・特定の床なら非表示にする, リネーム案: Shadow_FollowGround
NON_MATCH void ParticleShadow_FollowGround(ParticleShadow* shadow) {
#ifdef NONMATCHING_C
  s32 idx;  // 元は idx が r7、ptcl が r6。この形だと逆になる
  Particle* ptcl = &shadow->particle;
  Vec3* dst = &shadow->particle.pos;
  Vec3* pos = shadow->pos;
  s32 bx = pos->x >> 8;
  s32 bz = pos->z >> 8;
  u8* tile;
  u32 kind;
  u32 h;

  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  if (shadow->q_flags & 1) {
    dst->y = pos->y;
  } else {
    tile = (u8*)FUN_08234224(idx, 1);
    if (tile != NULL) {
      tile += 4;
    } else {
      tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
    }
    h = *tile;
    kind = h >> 4;
    h = (h & 0xF) << 8;
    switch (kind) {
      case 1: {
        h -= (u8)pos->z;
        break;
      }
      case 2: {
        h -= (u8)pos->x;
        break;
      }
    }
    dst->y = h;
  }
  if (pos->y >= dst->y && dst->y != 0) {
    tile = (u8*)FUN_08234224(idx, 1);
    if (tile != NULL) {
      tile += 4;
    } else {
      tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
    }
    if (!(((u16*)tile)[1] & 0x20)) {
      goto show;
    }
  }
  ptcl->flags |= 1;
  return;

show:
  ptcl->flags &= ~1;
  dst->x = pos->x;
  dst->z = pos->z;
#else
  INCFUNC("asm/func/ParticleShadow_FollowGround.inc");
#endif
}

// 影のリストをたどり、それぞれの更新関数を呼ぶ
s32 ParticleShadowManager_Update(ParticleShadowManager* p) {
  ParticleShadow* shadow;

  for (shadow = p->head; shadow != NULL; shadow = shadow->next) {
    shadow->updateCallback(shadow);
  }
  return 0;
}

s32 ParticleShadowManager_Destroy(ParticleShadowManager* p) {
  gParticleShadowManager = NULL;
  return 0;
}

s32 ParticleShadowManager_Init(ParticleShadowManager* p, void* data) {
  gParticleShadowManager = p;
  p->head = NULL;
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  return 0;
}

ParticleShadowManager* ParticleShadowManager_Create(void* data, u32 _) {
  ParticleShadowManager* p = CreateEntity(ENTITY_UNK_9, sizeof(ParticleShadowManager));
  if (p != NULL) {
    SetEntityRoutine(p, ParticleShadowManager_Update, ParticleShadowManager_Destroy);
    if (ParticleShadowManager_Init(p, data) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 影を初期化して描画リストと影のリストに繋ぐ (管理エンティティがなければ作る), リネーム案: Shadow_Init
s32 ParticleShadow_Init(ParticleShadow* shadow, Vec3* ownerPos, s32 kind) {
  if (gParticleShadowManager == NULL && ParticleShadowManager_Create(NULL, 0) == NULL) return -1;

  shadow->active = 0;
  shadow->pos = ownerPos;
  shadow->q_kind = kind;
  shadow->q_flags = 0;
  shadow->unk_04 = 0;
  shadow->unk_06 = 0;
  if ((u8)kind == 0) {
    shadow->updateCallback = ParticleShadow_FollowGround;
  } else {
    shadow->updateCallback = ParticleShadow_UpdateNone;
  }
  FUN_0822d9f0(&shadow->particle, gParticleShadowManager->group0, SPRFLAG_BLINK_ODD);
  Particle_SetOffset(&shadow->particle, -8, -8);
  shadow->particle.tileNum = gParticleShadowManager->group0->tile + (shadow->particle.spriteWidth >> 3) * (shadow->particle.spriteHeight >> 3) * 34;
  shadow->particle.offsetZ = -4;
  shadow->particle.priority = 2;
  ParticleShadowManager_Add(gParticleShadowManager, shadow);
  return 0;
}

// 影を描画リストと影のリストから外す, リネーム案: Shadow_Remove
s32 ParticleShadow_Remove(ParticleShadow* shadow) {
  Particle_Remove(&shadow->particle);
  if (gParticleShadowManager != NULL) {
    ParticleShadowManager_Remove(gParticleShadowManager, shadow);
  }
  return 0;
}
