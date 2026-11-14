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
void Cmd_SetLoadingZoneIndicatorMode(void) {
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
void Cmd_AddLoadingZoneIndicator(void) {
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

#ifdef NONMATCHING_C
static inline u32 Tile_Stairs(CollisionMapTile* t) { return (t->heightStairs >> 4) & 0xF; }

// 索引 idx のタイル, タイルデータが無ければ NULL
static inline CollisionMapTile* ArrowMarker_TileAt(s32 idx) {
  if (gCollisionMap->tiledata == NULL) {
    return NULL;
  }
  return &gCollisionMap->tiledata->tiles[idx];
}
#endif

// ゾーンの4辺のうち, 内側と外側のタイルが段差なしでつながっている辺を探し, 矢印の向き (0〜3) を返す, 無ければ -1
// 残差 670 対 678, 段差の種類を u32 の (x >> 4) & 0xF を返す inline で読み, 何もしない case を足すと分岐の木は揃う, 残りは外側タイルの値の写しのレジスタと, 縦の辺で定数 1 が既知のレジスタで代用されずに末尾が共通化される差
// u8 ローカル, ビットフィールド, case の中身を2つの if に分ける形は試済
NON_MATCH s32 Map_GetLoadingZoneDir(Zone* zone) {
#ifdef NONMATCHING_C
  WorldPos a, b;
  s32 idxA, idxB;
  CollisionMapTile* ta;
  CollisionMapTile* tb;

  a.x = zone->x2 - 16;
  a.z = (zone->y2 + zone->y1) >> 1;
  b = a;
  b.x += 32;
  idxA = GetCollisionTileIdx(&a);
  idxB = GetCollisionTileIdx(&b);
  if (idxA == idxB) {
    return 0;
  }
  ta = ArrowMarker_TileAt(idxA);
  tb = ArrowMarker_TileAt(idxB);
  switch (Tile_Stairs(ta)) {
    case STAIRS_NONE: {
      if (Tile_Stairs(tb) == STAIRS_NONE && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF) && !(tb->attr & TATTR_UNK_0)) {
        return 0;
      }
      if (Tile_Stairs(tb) == STAIRS_HORIZONTAL && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF) && !(tb->attr & TATTR_UNK_0)) {
        return 0;
      }
      break;
    }
    case STAIRS_VERTICAL: {
      break;
    }
    case STAIRS_HORIZONTAL: {
      if ((Tile_Stairs(tb) == STAIRS_NONE || Tile_Stairs(tb) == STAIRS_HORIZONTAL) && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF) + 1 && !(tb->attr & TATTR_UNK_0)) {
        return 0;
      }
      break;
    }
  }

  a.x = (zone->x2 + zone->x1) >> 1;
  a.z = zone->y2 - 16;
  b = a;
  b.z += 32;
  idxA = GetCollisionTileIdx(&a);
  idxB = GetCollisionTileIdx(&b);
  if (idxA == idxB) {
    return 1;
  }
  ta = ArrowMarker_TileAt(idxA);
  tb = ArrowMarker_TileAt(idxB);
  switch (Tile_Stairs(ta)) {
    case STAIRS_NONE: {
      if (Tile_Stairs(tb) == STAIRS_NONE && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF) && !(tb->attr & TATTR_UNK_0)) {
        return 1;
      }
      if (Tile_Stairs(tb) == STAIRS_VERTICAL && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF) && !(tb->attr & TATTR_UNK_0)) {
        return 1;
      }
      break;
    }
    case STAIRS_VERTICAL: {
      if ((Tile_Stairs(tb) == STAIRS_NONE || Tile_Stairs(tb) == STAIRS_VERTICAL) && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF) + 1 && !(tb->attr & TATTR_UNK_0)) {
        return 1;
      }
      break;
    }
    case STAIRS_HORIZONTAL: {
      break;
    }
  }

  a.x = zone->x1 + 16;
  a.z = (zone->y2 + zone->y1) >> 1;
  b = a;
  b.x -= 32;
  idxA = GetCollisionTileIdx(&a);
  idxB = GetCollisionTileIdx(&b);
  if (idxA == idxB) {
    return 2;
  }
  ta = ArrowMarker_TileAt(idxA);
  tb = ArrowMarker_TileAt(idxB);
  switch (Tile_Stairs(ta)) {
    case STAIRS_NONE: {
      if (Tile_Stairs(tb) == STAIRS_NONE && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF) && !(tb->attr & TATTR_UNK_0)) {
        return 2;
      }
      if (Tile_Stairs(tb) == STAIRS_HORIZONTAL && (ta->heightStairs & 0xF) + 1 == (tb->heightStairs & 0xF) && !(tb->attr & TATTR_UNK_0)) {
        return 2;
      }
      break;
    }
    case STAIRS_VERTICAL: {
      break;
    }
    case STAIRS_HORIZONTAL: {
      if (((Tile_Stairs(tb) == STAIRS_NONE && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF)) || (Tile_Stairs(tb) == STAIRS_HORIZONTAL && (ta->heightStairs & 0xF) + 1 == (tb->heightStairs & 0xF))) && !(tb->attr & TATTR_UNK_0)) {
        return 2;
      }
      break;
    }
  }

  a.x = (zone->x2 + zone->x1) >> 1;
  a.z = zone->y1 + 16;
  b = a;
  b.z -= 32;
  idxA = GetCollisionTileIdx(&a);
  idxB = GetCollisionTileIdx(&b);
  if (idxA == idxB) {
    return 3;
  }
  ta = ArrowMarker_TileAt(idxA);
  tb = ArrowMarker_TileAt(idxB);
  switch (Tile_Stairs(ta)) {
    case STAIRS_NONE: {
      if (Tile_Stairs(tb) == STAIRS_NONE && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF) && !(tb->attr & TATTR_UNK_0)) {
        return 3;
      }
      if (Tile_Stairs(tb) == STAIRS_VERTICAL && (ta->heightStairs & 0xF) + 1 == (tb->heightStairs & 0xF) && !(tb->attr & TATTR_UNK_0)) {
        return 3;
      }
      break;
    }
    case STAIRS_VERTICAL: {
      if (((Tile_Stairs(tb) == STAIRS_NONE && (ta->heightStairs & 0xF) == (tb->heightStairs & 0xF)) || (Tile_Stairs(tb) == STAIRS_VERTICAL && (ta->heightStairs & 0xF) + 1 == (tb->heightStairs & 0xF))) && !(tb->attr & TATTR_UNK_0)) {
        return 3;
      }
      break;
    }
    case STAIRS_HORIZONTAL: {
      break;
    }
  }
  return -1;
#else
  INCFUNC("asm/func/Map_GetLoadingZoneDir.inc");
#endif
}

// 0x8089, '.n' のゾーンの中心に目印を1つ置く
void Cmd_SpawnLoadingZoneIndicator(void) {
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

  dir = Map_GetLoadingZoneDir(zone);
  if (dir < 0) {
    return;
  }

  kind = VM_SeekToNamedArg('t') ? VM_GetValue() : 0;

  Map_AddLoadingZoneIndicator(&pos, dir, kind, FALSE);
}

// マーカー表示設定が有効な間だけ、矢印を点滅させながら表示する
// 残差はブロックの並びだけ (63 対 63), 条件を mode != 0 || markerEnabled == 0 で先に 0 を書く形にすると 0 の書き込みが show / mode のレジスタで代用されて命令は揃うが, 原典はタイマー側を先に置く
// 宣言順, ++ の比較, show = (blinkTimer < 48), bool16 show, mode == 0 && ... の形は試済 (64 対 63)
NON_MATCH s32 ArrowManager_Update(ArrowManager* p) {
#ifdef NONMATCHING_C
  bool32 show = FALSE;
  s32 i;

  if (p->mode != 0 || gStat->markerEnabled == 0) {
    p->blinkTimer = 0;
  } else {
    if (p->blinkTimer < 48) {
      show = TRUE;
    }

    p->blinkTimer++;
    if (p->blinkTimer >= 72) {
      p->blinkTimer = 0;
    }
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
