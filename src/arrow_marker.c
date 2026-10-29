#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "particle.h"
#include "registry.h"
#include "vm.h"

// ロードゾーンの目印を矢印マーカーで表示するエンティティ
typedef struct {
  Entity e;             // 0x00, ENTITY_UNK_9
  u16 mode;             // 0x18, '.m', 1 なら矢印を隠して点滅を止める
  u8 unk_1a[2];         // 0x1A, まだ未解析, padding?
  u16 count;            // 0x1C, arrows に積んだ数
  u16 blinkTimer;       // 0x1E, 毎フレーム +1 して 72 で 0 に戻り、 48 未満の間だけ表示する
  Particle arrows[17];  // 0x20
} ArrowManager;
static_assert(sizeof(ArrowManager) == 712);

// 0xA61C
void Map_SetLoadingZoneIndicatorMode(void) {
  if (VM_SeekToNamedArg('m')) {
    ArrowManager* p = Registry_Find(0xFD22);

    if (p != NULL) {
      p->mode = VM_GetValue();
      if (p->mode == 1) {
        s32 i;

        for (i = 0; i < p->count; i++) {
          p->arrows[i].flags |= SPRFLAG_HIDDEN;
        }

        p->blinkTimer = 0;
      }
    }
  }
}

/**
 * @param kind 0: PTCL0_ARROW, 1: PTCL0_ARROW_RED, 2: PTCL0_ARROW_GREEN, 3: PTCL0_ARROW_WHITE
 * @param param_f 0: タイルの高さに合わせる, それ以外: 無視
 */
void Map_AddLoadingZoneIndicator(WorldPos* pos, s32 dir, s32 kind, bool32 param_f) {
  ArrowManager* p = Registry_Find(0xFD22);
  ParticleGroup* g;
  Particle* ptcl;

  if (p == NULL) {
    return;
  }

  g = GetParticleGroup(PTCL_GROUP_0);
  ptcl = &p->arrows[p->count];
  Particle_Add(ptcl, g, 0);
  if (kind == 0) {
    Particle_SetPose(ptcl, g, PTCL0_ARROW);
  } else {
    Particle_SetPose(ptcl, g, 52 + kind);
  }

  Particle_SetOffset(ptcl, -8, -8);
  ptcl->pos = *pos;
  if (!param_f) {
    s32 idx = GetCollisionTileIdx(pos);
    CollisionMapTile* tile;
    if (gCollisionMap->tiledata == NULL) {
      tile = NULL;
    } else {
      tile = &gCollisionMap->tiledata->tiles[idx];
    }
    ptcl->pos.y = ((tile->heightStairs & 0xF) * Q8(1)) + Q8(0.5);
  }

  ptcl->priority = 1;
  if (dir != 0) {
    if (dir == 1) {
      ptcl->flags |= SPRFLAG_XFLIP;
    } else if (dir == 2) {
      ptcl->flags |= SPRFLAG_XFLIP | SPRFLAG_YFLIP;
    } else {
      ptcl->flags |= SPRFLAG_YFLIP;
    }
  }

  p->count++;
}

// スクリプトから目印を1つ積む, '.d' の向きは 4方向に丸めて渡す
void Map_AddLoadingZoneIndicatorScripted(void) {
  WorldPos pos;
  s32 dir;
  s32 kind;
  bool32 param_f;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }

  param_f = VM_SeekToNamedArg('f') ? VM_GetValue() : 0;
  dir = VM_SeekToNamedArg('d') ? VM_GetValue() : 0;
  kind = VM_SeekToNamedArg('t') ? VM_GetValue() : 0;

  Map_AddLoadingZoneIndicator(&pos, ((dir >> 1) + 1) & 3, kind, param_f);
}

NAKED s32 FUN_080a64cc(Zone* zone) { INCFUNC("asm/func/FUN_080a64cc.inc"); }

// 0x8089, '.n' のゾーンの中心に目印を1つ置く
void Map_SpawnLoadingZoneIndicator(void) {
  u16 count;
  WorldPos pos;
  s32 dir;
  s32 kind;

  s32 id = VM_SeekToNamedArg('n') ? VM_GetValue() : 0;
  Zone* zone = FindZonesByID(id, &count);
  if (zone == NULL) {
    return;
  }
  pos.x = (zone->x1 + zone->x2) >> 1;
  pos.z = (zone->y1 + zone->y2) >> 1;
  pos.y = TileHeightAt(&pos);

  dir = FUN_080a64cc(zone);
  if (dir < 0) {
    return;
  }

  kind = VM_SeekToNamedArg('t') ? VM_GetValue() : 0;

  Map_AddLoadingZoneIndicator(&pos, dir, kind, FALSE);
}

// マーカー表示設定が有効な間だけ、矢印を点滅させながら表示する
// 残差1命令 (64/63): show と mode のレジスタが逆 (原典は show が r1) で, 原典は 0 と分かっている mode のレジスタを blinkTimer = 0 に流用できる
NON_MATCH s32 ArrowManager_Update(ArrowManager* p) {
#ifdef NONMATCHING_C
  bool32 show = FALSE;
  s32 i;

  if (p->mode == 0 && gStat->markerEnabled != 0) {
    if (p->blinkTimer < 48) {
      show = TRUE;
    }

    p->blinkTimer++;
    if (p->blinkTimer >= 72) {
      p->blinkTimer = 0;
    }
  } else {
    p->blinkTimer = 0;
  }

  if (show) {
    for (i = 0; i < p->count; i++) {
      p->arrows[i].flags &= ~SPRFLAG_HIDDEN;
    }
  } else {
    for (i = 0; i < p->count; i++) {
      p->arrows[i].flags |= SPRFLAG_HIDDEN;
    }
  }

  return 0;
#else
  INCFUNC("asm/func/ArrowManager_Update.inc");
#endif
}

s32 ArrowManager_Destroy(ArrowManager* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    Particle_Remove(&p->arrows[i]);
  }

  return 0;
}

s32 ArrowManager_Init(ArrowManager* p) {
  p->mode = 0;
  p->count = 0;
  p->blinkTimer = 0;
  Registry_Add(0xFD22, p, 0);
  return 0;
}

// 0xD852
ArrowManager* ArrowManager_Create(void) {
  ArrowManager* p = CreateEntity(ENTITY_UNK_9, sizeof(ArrowManager));

  if (p != NULL) {
    SetEntityRoutine(p, ArrowManager_Update, ArrowManager_Destroy);
    if (ArrowManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
