#include "collision_map.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "particle.h"
#include "registry.h"
#include "vm.h"

// ロードゾーンの目印を粒子で表示するエンティティ
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_9
  u16 mode;            // 0x18, '.m', 1 なら粒子を隠して点滅を止める
  u8 unk_1a[2];        // 0x1A, まだ未解析
  u16 count;           // 0x1C, ptcls に積んだ数
  u16 blinkTimer;      // 0x1E, 毎フレーム +1 して 0x48 で 0 に戻り、0x30 未満の間だけ表示する
  Particle ptcls[17];  // 0x20
} EntityD852;
static_assert(sizeof(EntityD852) == 712);

// pos のタイルの高さを返す, 階段タイルなら上る向きの座標の端数ぶんだけ下げる
static inline s32 GetTileHeightAt(WorldPos* pos) {
  MapTileOverride* ov;
  CollisionMapTile* tile;
  s32 stairs;
  s32 height;
  s32 bx;
  s32 bz;
  s32 idx;

  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }

  ov = Map_FindTileOverride(idx, 1);
  if (ov != NULL) {
    tile = &ov->tile;
  } else {
    tile = &gCollisionMap->tiledata->tiles[idx];
  }

  stairs = tile->heightStairs >> 4;
  height = (tile->heightStairs & 0xF) << 8;
  switch (stairs) {
    case 1: {
      height -= pos->z & 0xFF;
      break;
    }
    case 2: {
      height -= pos->x & 0xFF;
      break;
    }
  }

  return height;
}

void Map_SetLoadingZoneIndicatorMode(void) {
  if (VM_SeekToNamedArg('m')) {
    EntityD852* p = Registry_Find(0xFD22);

    if (p != NULL) {
      p->mode = VM_GetValue();
      if (p->mode == 1) {
        s32 i;

        for (i = 0; i < p->count; i++) {
          p->ptcls[i].flags |= SPRFLAG_HIDDEN;
        }

        p->blinkTimer = 0;
      }
    }
  }
}

// 目印の粒子を1つ積む, param_4 が 0 ならタイルの高さに合わせ、dir で向きを反転する
void Map_AddLoadingZoneIndicator(WorldPos* pos, s32 dir, s32 kind, s32 param_4) {
  EntityD852* p = Registry_Find(0xFD22);
  ParticleGroup* g;
  Particle* ptcl;

  if (p == NULL) {
    return;
  }

  g = GetParticleGroup(PTCL_GROUP_0);
  ptcl = &p->ptcls[p->count];
  Particle_Add(ptcl, g, 0);
  if (kind == 0) {
    Particle_SetFrame(ptcl, g, 0x33);
  } else {
    Particle_SetFrame(ptcl, g, kind + 0x34);
  }

  Particle_SetOffset(ptcl, -8, -8);
  ptcl->pos = *pos;
  if (param_4 == 0) {
    CollisionMapTile* tile;
    s32 bx = (s8)(pos->x >> 8);
    s32 bz = (s8)(pos->z >> 8);
    s32 idx;

    if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
      idx = 0;
    } else {
      idx = gCollisionMap->rowOffsets[bz] + bx;
    }

    if (gCollisionMap->tiledata == NULL) {
      tile = NULL;
    } else {
      tile = &gCollisionMap->tiledata->tiles[idx];
    }

    ptcl->pos.y = ((tile->heightStairs & 0xF) << 8) + 0x80;
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
  s32 param_3;

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }

  if (VM_SeekToNamedArg('f')) {
    param_3 = VM_GetValue();
  } else {
    param_3 = 0;
  }

  if (VM_SeekToNamedArg('d')) {
    dir = VM_GetValue();
  } else {
    dir = 0;
  }

  if (VM_SeekToNamedArg('t')) {
    kind = VM_GetValue();
  } else {
    kind = 0;
  }

  Map_AddLoadingZoneIndicator(&pos, ((dir >> 1) + 1) & 3, kind, param_3);
}

NAKED s32 FUN_080a64cc(Zone* zone) { INCFUNC("asm/func/FUN_080a64cc.inc"); }

// '.n' のゾーンの中心に目印を1つ置く
void Map_SpawnLoadingZoneIndicator(void) {
  u16 count;
  WorldPos pos;
  Zone* zone;
  s32 id;
  s32 dir;
  s32 kind;

  if (VM_SeekToNamedArg('n')) {
    id = VM_GetValue();
  } else {
    id = 0;
  }

  zone = FindZonesByID(id, &count);
  if (zone == NULL) {
    return;
  }

  pos.x = (zone->x1 + zone->x2) >> 1;
  pos.z = (zone->y1 + zone->y2) >> 1;
  pos.y = GetTileHeightAt(&pos);

  dir = FUN_080a64cc(zone);
  if (dir < 0) {
    return;
  }

  if (VM_SeekToNamedArg('t')) {
    kind = VM_GetValue();
  } else {
    kind = 0;
  }

  Map_AddLoadingZoneIndicator(&pos, dir, kind, 0);
}

// マーカー表示設定が有効な間だけ、0x48 フレーム周期で 0x30 フレームぶん粒子を見せる
// 残差1命令 (64/63): show と mode のレジスタが逆 (原典は show が r1) で, 原典は 0 と分かっている mode のレジスタを blinkTimer = 0 に流用できる
NON_MATCH s32 EntityD852_Update(EntityD852* p) {
#ifdef NONMATCHING_C
  s32 show = 0;
  s32 i;

  if (p->mode == 0 && gStat->markerEnabled != 0) {
    if (p->blinkTimer <= 0x2F) {
      show = 1;
    }

    p->blinkTimer++;
    if (p->blinkTimer > 0x47) {
      p->blinkTimer = 0;
    }
  } else {
    p->blinkTimer = 0;
  }

  if (show) {
    for (i = 0; i < p->count; i++) {
      p->ptcls[i].flags &= ~SPRFLAG_HIDDEN;
    }
  } else {
    for (i = 0; i < p->count; i++) {
      p->ptcls[i].flags |= SPRFLAG_HIDDEN;
    }
  }

  return 0;
#else
  INCFUNC("asm/func/EntityD852_Update.inc");
#endif
}

s32 EntityD852_Destroy(EntityD852* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    Particle_Remove(&p->ptcls[i]);
  }

  return 0;
}

s32 EntityD852_Init(EntityD852* p) {
  p->mode = 0;
  p->count = 0;
  p->blinkTimer = 0;
  Registry_Add(0xFD22, p, 0);
  return 0;
}

EntityD852* EntityD852_Create(void) {
  EntityD852* p = CreateEntity(ENTITY_UNK_9, sizeof(EntityD852));

  if (p != NULL) {
    SetEntityRoutine(p, EntityD852_Update, EntityD852_Destroy);
    if (EntityD852_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
