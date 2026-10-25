#include "collision_map.h"

#include "file.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "map_inline.h"
#include "mover.h"
#include "random.h"
#include "registry.h"
#include "vm.h"

IWRAM_DATA bool32 bool32_0300077c = FALSE;  // 0x0300077C

void Map_ClearEvent(CollisionMapEvent* ev);
CollisionMapEvent* Map_FindEventByID(u32 id);
void Map_RunZoneEventScript(ZoneEventSource* src, CollisionMapEvent* ev, u16 msg);
s32 FUN_0823a88c(u8* pc, ScriptArgs* args);                      // src/entity_0823acbc.c
s32 VM_ExecById_Proxy_0823a8a4(u32 scriptID, ScriptArgs* args);  // src/entity_0823acbc.c
extern u32 gNextMapEventID;                                      // src/iwram2.c

// 索引 idx のタイルを返す, 上書きがあればそちらを返す
static inline CollisionMapTile* TileAtIndex(s32 idx) {
  MapTileOverride* ov = Map_FindTileOverride(idx, 1);

  if (ov != NULL) {
    return &ov->tile;
  }
  return &gCollisionMap->tiledata->tiles[idx];
}

void Map_InitCollisionMap(void) {
  CollisionMapData* p = Malloc(sizeof(CollisionMapData));
  ClearMemory(p, sizeof(CollisionMapData));
  Registry_Add(0x56C2, p, 1);
  gCollisionMap = p;
  Map_ResetCollisionMap();
}

// 読み込み済みのコリジョンマップを空にする, navMesh だけは消さない
bool32 Map_ResetCollisionMap(void) {
  s32 i;

  if (gCollisionMap == NULL) {
    return FALSE;
  }

  gCollisionMap->tiledata = NULL;
  gCollisionMap->unk_8 = 0;
  gCollisionMap->zones = NULL;
  gCollisionMap->paths = NULL;
  gCollisionMap->tileOverrides = NULL;
  gNextMapEventID = 0;
  gCollisionMap->eventCount = 0;

  for (i = 0; i < 64; i++) {
    Map_ClearEvent(&gCollisionMap->events[i]);
    gCollisionMap->unk_d24[i] = 0;
  }
  return TRUE;
}

// 隣接タイルへの索引差分を -w / 1 / w / -1 で埋める
void Map_BuildNeighborOffsets(void) {
  CollisionMapTileData* tiledata = gCollisionMap->tiledata;

  gCollisionMap->neighborOffsets[0] = -tiledata->width;
  gCollisionMap->neighborOffsets[1] = 1;
  gCollisionMap->neighborOffsets[2] = tiledata->width;
  gCollisionMap->neighborOffsets[3] = -1;
}

// 行ごとのタイル索引オフセット表を作る, rowOffsets[z] = z * width
// 残差1命令: 原典は rowOffsets の先頭を1本のレジスタに残したままカーソルへ複写する, こちらは先頭をそのままカーソルに使う
// Tier A/B と C の添字形・guard+do/while は試済
NON_MATCH void Map_BuildRowOffsets(void) {
#ifdef NONMATCHING_C
  s32 width = gCollisionMap->tiledata->width;
  u16* dst = gCollisionMap->rowOffsets;
  s32 offset = 0;
  s32 i;

  for (i = 0; i < gCollisionMap->tiledata->height; i++) {
    *dst = offset;
    offset += width;
    dst++;
  }
#else
  INCFUNC("asm/func/Map_BuildRowOffsets.inc");
#endif
}

void UpdateMapSize_0823279c(void) {
  gMapBlockW = (gCollisionMap->tiledata)->width;
  gMapBlockH = (gCollisionMap->tiledata)->height;
}

// このゲームでこの関数が呼ばれることはない
s32 Map_LoadTileData(FileID id) {
  gCollisionMap->tiledata = GetFile(0xAE1B, id);  // これNULLを返すっぽいけど...
  Map_BuildNeighborOffsets();
  Map_BuildRowOffsets();
  UpdateMapSize_0823279c();
  return 0;
}

void Map_SetTileData(CollisionMapTileData* tiledata) {
  gCollisionMap->tiledata = tiledata;
  Map_BuildNeighborOffsets();
  Map_BuildRowOffsets();
  UpdateMapSize_0823279c();
}

// pos のタイルを MoverTile に取り込む, 前と今を同じ値で埋める
void Map_InitMoverTile(MoverTile* p, Vec3* pos) {
  CollisionMapTileData* td;
  CollisionMapTile* tile;
  s32 bx;
  s32 bz;
  s32 idx;

  if (gCollisionMap->tiledata == NULL) {
    return;
  }

  td = gCollisionMap->tiledata;
  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  p->tileIdx[0] = p->tileIdx[1] = idx;

  tile = &td->tiles[p->tileIdx[1]];
  p->height[1] = tile->heightStairs & 0xF;
  p->stairs[1] = tile->heightStairs >> 4;
  p->attr[1] = tile->attr;
  p->height[0] = p->height[1];
  p->stairs[0] = p->stairs[1];
  p->attr[0] = p->attr[1];
}

// from から to へ 4タイル以内で真っ直ぐ行ける向きを 8bit の角度で返す, 無ければ -1
// 残差7命令: 原典は & 3 と & 0xFF をループ内で実際に計算し、配列先頭と定数2つを高位レジスタ (r8/r9/sl) に抱えている
// こちらは dir が 0..3 と分かるので agbcc が両方のマスクを畳んでしまう, マスクが残る書き方が未発見
NON_MATCH s32 Map_FindDirToTile(s32 from, s32 to) {
#ifdef NONMATCHING_C
  s32 angle = 0xC0;
  s32 dir;

  for (dir = 0; dir < 4; dir++) {
    s32 step = gCollisionMap->neighborOffsets[dir & 3];
    s32 idx = from;
    s32 i;

    for (i = 0; i < 4; i++) {
      idx += step;
      if (idx == to) {
        return (u8)angle;
      }
    }

    angle += 0x40;
  }
  return -1;
#else
  INCFUNC("asm/func/Map_FindDirToTile.inc");
#endif
}

u16 Map_GetTileHeightAt(Vec3* pos) { return TileHeightAt(pos); }

// pos のタイルの attr を返す, マップ外なら tiles[0] の値
TileAttr Map_GetTileAttr(Vec3* pos) {
  CollisionMapTileData* td;
  CollisionMapTile* tile;
  s32 bx;
  s32 bz;
  s32 idx;

  if (gCollisionMap->tiledata == NULL) {
    return 0;
  }

  td = gCollisionMap->tiledata;
  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  tile = &td->tiles[idx];
  return tile->attr;
}

// pos1 と pos2 のタイル高さの差を返す
u16 Map_GetTileHeightDiff(Vec3* pos1, Vec3* pos2) {
  s32 diff = TileHeightAt(pos1) - TileHeightAt(pos2);
  return abs(diff);
}

// pos1 から pos2 へ移れるか, 階段タイルどうしの繋がりと段差を見て判定する
// 残差21命令 (305/326): 原典は TileAtIndex の展開を <= 0x7F の両側それぞれに持ち, こちらは2つが丸ごと融合する
// Tier A-C は試済: 索引の u16 切り捨てを別変数経由に, 分岐ごとの複製 (TileAtIndex 導入で 294→305)
NON_MATCH bool32 FUN_08232b00(Vec3* pos1, Vec3* pos2, u8 val) {
#ifdef NONMATCHING_C
  CollisionMapTile* tile1;
  CollisionMapTile* tile2;
  CollisionMapTile* tile3;
  CollisionMapTile* base;
  MapTileOverride* ov;
  TileAttr attr2;
  TileAttr mask;
  s32 limit;
  s32 stairs1;
  s32 stairs2;
  s32 height;
  s32 idx1;
  s32 idx2;
  s32 raw;
  s32 bx;
  s32 bz;
  s32 d;

  bx = (s8)(pos2->x >> 8);
  bz = (s8)(pos2->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    raw = 0;
  } else {
    raw = gCollisionMap->rowOffsets[bz] + bx;
  }
  idx2 = (u16)raw;

  ov = Map_FindTileOverride(idx2, 1);
  tile2 = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx2];

  attr2 = tile2->attr;
  if (val == 4) {
    mask = TATTR_WALL;
    limit = 0x80;
  } else {
    mask = TATTR_UNK_0;
    limit = 0x64;
  }

  if (attr2 & mask) {
    return FALSE;
  }
  if (Map_GetTileHeightDiff(pos1, pos2) > limit) {
    return FALSE;
  }

  bx = (s8)(pos1->x >> 8);
  bz = (s8)(pos1->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    raw = 0;
  } else {
    raw = gCollisionMap->rowOffsets[bz] + bx;
  }
  idx1 = (u16)raw;

  ov = Map_FindTileOverride(idx1, 1);
  tile1 = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx1];

  stairs1 = tile1->heightStairs >> 4;
  stairs2 = tile2->heightStairs >> 4;
  d = idx2 - idx1;
  if (stairs1 == STAIRS_VERTICAL) {
    if (d != 1 && d != -1) {
      return TRUE;
    }
    if ((gStat->unk_934 & SF934_LAVA_FROZEN) && (attr2 & TATTR_LAVA)) {
      return FALSE;
    }
    if (stairs2 != 0) {
      return TRUE;
    }

    if ((u8)pos2->z <= 0x7F) {
      tile3 = TileAtIndex(idx2 - gMapBlockW);
    } else {
      tile3 = TileAtIndex(idx2 + gMapBlockW);
    }

    if (tile3->heightStairs >> 4 != 0) {
      return FALSE;
    }
    height = tile3->heightStairs & 0xF;
    base = tile2;
  } else if (stairs1 == STAIRS_HORIZONTAL) {
    if (d != gMapBlockW && d != -gMapBlockW) {
      return TRUE;
    }
    if ((gStat->unk_934 & SF934_LAVA_FROZEN) && (attr2 & TATTR_LAVA)) {
      return FALSE;
    }
    if (stairs2 != 0) {
      return TRUE;
    }

    if ((u8)pos2->x <= 0x7F) {
      tile3 = TileAtIndex(idx2 - 1);
    } else {
      tile3 = TileAtIndex(idx2 + 1);
    }

    if (tile3->heightStairs >> 4 != 0) {
      return FALSE;
    }
    height = tile3->heightStairs & 0xF;
    base = tile2;
  } else {
    if (d == gMapBlockW || d == -gMapBlockW) {
      if (stairs2 != STAIRS_HORIZONTAL) {
        return TRUE;
      }
      if ((u8)pos2->x <= 0x7F) {
        tile3 = TileAtIndex(idx1 - 1);
      } else {
        tile3 = TileAtIndex(idx1 + 1);
      }
    } else if (d == 1 || d == -1) {
      if (stairs2 != STAIRS_VERTICAL) {
        return TRUE;
      }
      if ((u8)pos2->z <= 0x7F) {
        tile3 = TileAtIndex(idx1 - gMapBlockW);
      } else {
        tile3 = TileAtIndex(idx1 + gMapBlockW);
      }
    } else {
      return TRUE;
    }

    if (tile3->heightStairs >> 4 != 0) {
      return FALSE;
    }
    height = tile3->heightStairs & 0xF;
    base = tile1;
  }

  if (height != (base->heightStairs & 0xF)) {
    return FALSE;
  }
  if (tile3->attr & mask) {
    return FALSE;
  }

  return TRUE;
#else
  INCFUNC("asm/func/FUN_08232b00.inc");
#endif
}

// dst のタイルへ入れないとき, 境界に沿って片方の軸だけ滑らせた位置を探して dst に書き戻す
s32 FUN_08232df8(MoverTile* tile, Vec3* pos, Vec3* dst, u8 param_4) {
  CollisionMapTileData* td;
  Vec3 v;
  s32 idx;
  s32 dir;
  s32 n;
  s32 bx;
  s32 bz;
  s32 raw;

  if (gCollisionMap->tiledata == NULL) {
    return 0;
  }
  td = gCollisionMap->tiledata;

  bx = (s8)(dst->x >> 8);
  bz = (s8)(dst->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    raw = 0;
  } else {
    raw = gCollisionMap->rowOffsets[bz] + bx;
  }
  idx = (u16)raw;

  if (tile->tileIdx[1] == idx) {
    return 0;
  }
  if (FUN_08232b00(pos, dst, param_4)) {
    return 0;
  }

  // 索引差分を 8方向 (0:北西 1:北 2:北東 3:西 4:東 5:南西 6:南 7:南東) に畳む
  dir = idx - tile->tileIdx[1];
  if (dir <= -td->width + 1) {
    n = dir + 1;
    dir = n + td->width;
  } else if (dir == -1) {
    dir = 3;
  } else if (dir == 1) {
    dir = 4;
  } else if (dir >= td->width - 1) {
    n = dir + 6;
    dir = n - td->width;
  }

  switch (dir) {
    case 0: {
      if (tile->tileIdx[0] == idx + 1) {
        v = *dst;
        v.x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        v = *dst;
        v.z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        dst->x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
        dst->z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
      } else {
        v = *dst;
        v.z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        v = *dst;
        v.x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        dst->x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
        dst->z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
      }
      break;
    }
    case 1: {
      dst->z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
      break;
    }
    case 2: {
      if (tile->tileIdx[0] == idx - 1) {
        v = *dst;
        v.x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        v = *dst;
        v.z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        dst->x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        dst->z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
      } else {
        v = *dst;
        v.z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        v = *dst;
        v.x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        dst->x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        dst->z = (Div(tile->tileIdx[1], td->width) << 8) + 1;
      }
      break;
    }
    case 3: {
      dst->x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
      break;
    }
    case 4: {
      dst->x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
      break;
    }
    case 5: {
      if (tile->tileIdx[0] == idx + 1) {
        v = *dst;
        v.x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        v = *dst;
        v.z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        dst->x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
        dst->z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
      } else {
        v = *dst;
        v.z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        v = *dst;
        v.x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        dst->x = (Mod(tile->tileIdx[1], td->width) << 8) + 1;
        dst->z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
      }
      break;
    }
    case 6: {
      dst->z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
      break;
    }
    case 7: {
      if (tile->tileIdx[0] == idx - 1) {
        v = *dst;
        v.x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        v = *dst;
        v.z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        dst->x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        dst->z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
      } else {
        v = *dst;
        v.z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        v = *dst;
        v.x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        if (FUN_08232b00(pos, &v, param_4)) {
          *dst = v;
          break;
        }

        dst->x = ((Mod(tile->tileIdx[1], td->width) + 1) << 8) - 1;
        dst->z = ((Div(tile->tileIdx[1], td->width) + 1) << 8) - 1;
      }
      break;
    }
  }

  return 1;
}

// dst のタイルが変わっていたら今の値を [0] へ押し出して [1] を更新し, pos を dst とそのタイルの高さで埋める
void Map_UpdateMoverTile(MoverTile* mTile, Vec3* pos, Vec3* dst) {
  if (gCollisionMap->tiledata != NULL) {
    u16 idx = GetCollisionTileIdx(dst);
    MapTileOverride* ov = Map_FindTileOverride(idx, 1);
    CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];

    if (mTile->tileIdx[1] != idx) {
      mTile->tileIdx[0] = mTile->tileIdx[1];
      mTile->stairs[0] = mTile->stairs[1];
      mTile->height[0] = mTile->height[1];
      mTile->attr[0] = mTile->attr[1];
      mTile->tileIdx[1] = idx;
      mTile->stairs[1] = tile->heightStairs >> 4;
      mTile->height[1] = tile->heightStairs & 0xF;
      mTile->attr[1] = tile->attr;
    }

    *pos = *dst;
    pos->y = TileHeightAt(dst);
  }
}

// pos から offset だけ動いた先のタイルを MoverTile に反映する
// unused_4 と unused_5 は読まれていない
void FUN_08233428(MoverTile* tile, Vec3* pos, Vec3* offset, s32 unused_4, s32 unused_5, u8 param_6) {
  Vec3 dst;

  dst.x = pos->x + offset->x;
  dst.y = pos->y + offset->y;
  dst.z = pos->z + offset->z;
  dst.val = 16;
  tile->unk_0[0] = FUN_08232df8(tile, pos, &dst, param_6);
  Map_UpdateMoverTile(tile, pos, &dst);
}

// delta だけ動かした先で当たり判定の四隅を調べ, 塞がっていれば壁に沿って滑らせた位置で MoverTile を更新する
// p->unk_0[0] に 1 が入ったら何かに当たったという意味
// 残差31命令 (929/960): 原典は p が r7, こちらは r8 に載るため p->unk_0[0] の書き込みが融合せず, 連鎖して Map_UpdateMoverTile の共有ブロックの切り方と freeX のスピル有無が変わる
// Tier A-C は試済: 共有末尾を switch の break にする形 (1015→929 と改善), 宣言順の入れ替え
NON_MATCH void FUN_0823349c(MoverTile* p, Vec3* pos, Vec3* delta, u16 sizeX, u16 sizeZ, u8 unk_4) {
#ifdef NONMATCHING_C
  Vec3 dst;
  Vec3 probe;
  s32 dir;
  s32 bx;
  s32 bz;
  s32 idx;

  dir = 0;
  if (delta->x > 0) {
    dir = 0x10;
  } else if (delta->x < 0) {
    dir = 0x20;
  }
  if (delta->z > 0) {
    dir |= 1;
  } else if (delta->z < 0) {
    dir |= 2;
  }

  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  p->tileIdx[1] = idx;

  dst.x = pos->x + delta->x;
  dst.y = pos->y + delta->y;
  dst.z = pos->z + delta->z;
  dst.val = 16;

  switch (dir) {
    case 0x00: {
      Map_UpdateMoverTile(p, pos, &dst);
      p->unk_0[0] = 0;
      return;
    }
    case 0x10: {
      probe = dst;
      probe.x += sizeX;
      probe.z += sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x -= sizeX;
        probe.z -= sizeZ;
        break;
      }

      probe = dst;
      probe.x += sizeX;
      probe.z -= sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x -= sizeX;
        probe.z += sizeZ;
        break;
      }

      Map_UpdateMoverTile(p, pos, &dst);
      p->unk_0[0] = 0;
      return;
    }
    case 0x20: {
      probe = dst;
      probe.x -= sizeX;
      probe.z += sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x += sizeX;
        probe.z -= sizeZ;
        break;
      }

      probe = dst;
      probe.x -= sizeX;
      probe.z -= sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x += sizeX;
        probe.z += sizeZ;
        break;
      }

      Map_UpdateMoverTile(p, pos, &dst);
      p->unk_0[0] = 0;
      return;
    }
    case 0x01: {
      probe = dst;
      probe.x += sizeX;
      probe.z += sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x -= sizeX;
        probe.z -= sizeZ;
        break;
      }

      probe = dst;
      probe.x -= sizeX;
      probe.z += sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x += sizeX;
        probe.z -= sizeZ;
        break;
      }

      Map_UpdateMoverTile(p, pos, &dst);
      p->unk_0[0] = 0;
      return;
    }
    case 0x02: {
      probe = dst;
      probe.x += sizeX;
      probe.z -= sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x -= sizeX;
        probe.z += sizeZ;
        break;
      }

      probe = dst;
      probe.x -= sizeX;
      probe.z -= sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x += sizeX;
        probe.z += sizeZ;
        break;
      }

      Map_UpdateMoverTile(p, pos, &dst);
      p->unk_0[0] = 0;
      return;
    }
    case 0x11: {
      Vec3 tryX;
      Vec3 tryZ;
      s32 freeX;
      s32 freeZ;

      probe = dst;
      probe.x += sizeX;
      probe.z += sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x -= sizeX;
        probe.z -= sizeZ;
        break;
      }

      tryX = *pos;
      tryX.x += delta->x + sizeX;
      freeX = FUN_08232b00(pos, &tryX, unk_4);

      tryZ = *pos;
      tryZ.z += delta->z + sizeZ;
      freeZ = FUN_08232b00(pos, &tryZ, unk_4);

      if (freeX != 0 && freeZ != 0) {
        Map_UpdateMoverTile(p, pos, &dst);
        p->unk_0[0] = 0;
        return;
      }

      if (freeX == 0) {
        if (freeZ == 0) {
          // 両方塞がっているのでタイルの角に寄せる
          probe.x = ((Mod(p->tileIdx[1], gMapBlockW) + 1) << 8) - 1;
          probe.z = ((Div(p->tileIdx[1], gMapBlockW) + 1) << 8) - 1;
          probe.x -= sizeX;
          probe.z -= sizeZ;
          break;
        }

        // X方向だけ塞がっているので Z 方向の移動だけ通す
        FUN_08232df8(p, pos, &tryX, unk_4);
        tryX.x -= sizeX;
        tryX.z += delta->z;
        Map_UpdateMoverTile(p, pos, &tryX);
        p->unk_0[0] = 1;
        return;
      }

      // Z方向だけ塞がっているので X 方向の移動だけ通す
      FUN_08232df8(p, pos, &tryZ, unk_4);
      tryZ.x += delta->x;
      tryZ.z -= sizeZ;
      Map_UpdateMoverTile(p, pos, &tryZ);
      p->unk_0[0] = 1;
      return;
    }
    case 0x21: {
      Vec3 tryX;
      Vec3 tryZ;
      s32 freeX;
      s32 freeZ;

      probe = dst;
      probe.x -= sizeX;
      probe.z += sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x += sizeX;
        probe.z -= sizeZ;
        break;
      }

      tryX = *pos;
      tryX.x += delta->x - sizeX;
      freeX = FUN_08232b00(pos, &tryX, unk_4);

      tryZ = *pos;
      tryZ.z += delta->z + sizeZ;
      freeZ = FUN_08232b00(pos, &tryZ, unk_4);

      if (freeX != 0 && freeZ != 0) {
        Map_UpdateMoverTile(p, pos, &dst);
        p->unk_0[0] = 0;
        return;
      }

      if (freeX == 0) {
        if (freeZ == 0) {
          // 両方塞がっているのでタイルの角に寄せる
          probe.x = (Mod(p->tileIdx[1], gMapBlockW) << 8) + 1;
          probe.z = ((Div(p->tileIdx[1], gMapBlockW) + 1) << 8) - 1;
          probe.x += sizeX;
          probe.z -= sizeZ;
          break;
        }

        // X方向だけ塞がっているので Z 方向の移動だけ通す
        FUN_08232df8(p, pos, &tryX, unk_4);
        tryX.x += sizeX;
        tryX.z += delta->z;
        Map_UpdateMoverTile(p, pos, &tryX);
        p->unk_0[0] = 1;
        return;
      }

      // Z方向だけ塞がっているので X 方向の移動だけ通す
      FUN_08232df8(p, pos, &tryZ, unk_4);
      tryZ.x += delta->x;
      tryZ.z -= sizeZ;
      Map_UpdateMoverTile(p, pos, &tryZ);
      p->unk_0[0] = 1;
      return;
    }
    case 0x12: {
      Vec3 tryX;
      Vec3 tryZ;
      s32 freeX;
      s32 freeZ;

      probe = dst;
      probe.x += sizeX;
      probe.z -= sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x -= sizeX;
        probe.z += sizeZ;
        break;
      }

      tryX = *pos;
      tryX.x += delta->x + sizeX;
      freeX = FUN_08232b00(pos, &tryX, unk_4);

      tryZ = *pos;
      tryZ.z += delta->z - sizeZ;
      freeZ = FUN_08232b00(pos, &tryZ, unk_4);

      if (freeX != 0 && freeZ != 0) {
        Map_UpdateMoverTile(p, pos, &dst);
        p->unk_0[0] = 0;
        return;
      }

      if (freeX == 0) {
        if (freeZ == 0) {
          // 両方塞がっているのでタイルの角に寄せる
          probe.x = ((Mod(p->tileIdx[1], gMapBlockW) + 1) << 8) - 1;
          probe.z = (Div(p->tileIdx[1], gMapBlockW) << 8) + 1;
          probe.x -= sizeX;
          probe.z += sizeZ;
          break;
        }

        // X方向だけ塞がっているので Z 方向の移動だけ通す
        FUN_08232df8(p, pos, &tryX, unk_4);
        tryX.x -= sizeX;
        tryX.z += delta->z;
        Map_UpdateMoverTile(p, pos, &tryX);
        p->unk_0[0] = 1;
        return;
      }

      // Z方向だけ塞がっているので X 方向の移動だけ通す
      FUN_08232df8(p, pos, &tryZ, unk_4);
      tryZ.x += delta->x;
      tryZ.z += sizeZ;
      Map_UpdateMoverTile(p, pos, &tryZ);
      p->unk_0[0] = 1;
      return;
    }
    case 0x22: {
      Vec3 tryX;
      Vec3 tryZ;
      s32 freeX;
      s32 freeZ;

      probe = dst;
      probe.x -= sizeX;
      probe.z -= sizeZ;
      if (FUN_08232df8(p, pos, &probe, unk_4)) {
        probe.x += sizeX;
        probe.z += sizeZ;
        break;
      }

      tryX = *pos;
      tryX.x += delta->x - sizeX;
      freeX = FUN_08232b00(pos, &tryX, unk_4);

      tryZ = *pos;
      tryZ.z += delta->z - sizeZ;
      freeZ = FUN_08232b00(pos, &tryZ, unk_4);

      if (freeX != 0 && freeZ != 0) {
        Map_UpdateMoverTile(p, pos, &dst);
        p->unk_0[0] = 0;
        return;
      }

      if (freeX == 0) {
        if (freeZ == 0) {
          // 両方塞がっているのでタイルの角に寄せる
          probe.x = (Mod(p->tileIdx[1], gMapBlockW) << 8) + 1;
          probe.z = (Div(p->tileIdx[1], gMapBlockW) << 8) + 1;
          probe.x += sizeX;
          probe.z += sizeZ;
          break;
        }

        // X方向だけ塞がっているので Z 方向の移動だけ通す
        FUN_08232df8(p, pos, &tryX, unk_4);
        tryX.x += sizeX;
        tryX.z += delta->z;
        Map_UpdateMoverTile(p, pos, &tryX);
        p->unk_0[0] = 1;
        return;
      }

      // Z方向だけ塞がっているので X 方向の移動だけ通す
      FUN_08232df8(p, pos, &tryZ, unk_4);
      tryZ.x += delta->x;
      tryZ.z += sizeZ;
      Map_UpdateMoverTile(p, pos, &tryZ);
      p->unk_0[0] = 1;
      return;
    }
    default: {
      return;
    }
  }

  Map_UpdateMoverTile(p, pos, &probe);
  p->unk_0[0] = 1;

#else
  INCFUNC("asm/func/FUN_0823349c.inc");
#endif
}

// src から target へ動くとき, タイルの境界で止めた位置を dst に返す (戻り値は抜けた辺の種別, 0 なら抜けない)
s32 FUN_08233d50(Vec3* dst, Vec3* src, Vec3* target) {
  Vec3 out;
  s32 bz0;
  s32 bx1;
  s32 bz1;
  s32 dx;
  s32 fx;
  s32 fz;
  s32 rx;
  s32 rz;
  s32 dz;
  s32 bx0;
  s32 edge;
  s32 t;

  dx = target->x - src->x;
  dz = target->z - src->z;
  out.y = src->y;
  fx = (u8)src->x;
  fz = (u8)src->z;
  rx = 0x100 - fx;
  rz = 0x100 - fz;
  bx0 = src->x & 0xFF00;
  bz0 = src->z & 0xFF00;
  bx1 = bx0 + 0x100;
  bz1 = bz0 + 0x100;

  if (target->x >= bx0 && target->x <= bx1 && target->z >= bz0 && target->z <= bz1) {
    *dst = *target;
    return 1;
  }

  if (dx == 0) {
    if (dz == 0) {
      *dst = *target;
      return 1;
    }

    if (dz > 0) {
      out.z = bz1;
    } else {
      out.z = bz0;
    }
    out.x = src->x;
    *dst = out;
    t = 3;
    if (dz > 0) {
      t = 2;
    }
    return t;
  }

  if (dz == 0) {
    if (dx > 0) {
      out.x = bx1;
    } else {
      out.x = bx0;
    }
    out.z = src->z;
    *dst = out;
    t = 4;
    if (dx > 0) {
      t = 5;
    }
    return t;
  }

  if (dx > 0) {
    edge = 0x1000;
  } else {
    edge = 0x100;
  }
  if (dz > 0) {
    edge |= 0x10;
  } else {
    edge |= 1;
  }

  if (edge & 0x10) {
    t = Div(rz * dx, dz < 0 ? -dz : dz);
    out.x = t + src->x;
    out.z = bz1;
    if (out.x >= bx0 && out.x <= bx1) {
      if ((out.x & 0xFF00) > (src->x & 0xFF00)) {
        out.x = src->x | 0xFF;
      }
      *dst = out;
      return 3;
    }
  }

  if (edge & 1) {
    t = Div(fz * dx, dz < 0 ? -dz : dz);
    out.x = t + src->x;
    out.z = bz0 - 1;
    if (out.x >= bx0 && out.x <= bx1) {
      if ((out.x & 0xFF00) > (src->x & 0xFF00)) {
        out.x = src->x | 0xFF;
      }
      *dst = out;
      return 2;
    }
  }

  if (edge & 0x100) {
    out.x = bx0 - 1;
    t = Div(fx * dz, dx < 0 ? -dx : dx);
    out.z = t + src->z;
    if (out.z >= bz0 && out.z <= bz1) {
      if ((out.z & 0xFF00) > (src->z & 0xFF00)) {
        out.z = src->z | 0xFF;
      }
      *dst = out;
      return 4;
    }
  }

  if (edge & 0x1000) {
    out.x = bx1;
    t = Div(rx * dz, dx < 0 ? -dx : dx);
    out.z = t + src->z;
    if (out.z >= bz0 && out.z <= bz1) {
      if ((out.z & 0xFF00) > (src->z & 0xFF00)) {
        out.z = src->z | 0xFF;
      }
      *dst = out;
      return 5;
    }
  }

  return 0;
}

// pos から dir 方向へ最大 count 歩たどり, pos との段差が limit 以上になる手前で止まる
// 残差4命令 (140/144): 原典は FUN_08233d50 の戻り値を r3 に置いてスタックに溢れさせ, 死んだ初期化 0 まで残るが, こちらは退避レジスタに収まる
// Tier A-C は試済: TileIndexAt 相当の static inline を足すと &cur のレジスタ化までは再現できたが命令数は変わらず
NON_MATCH s32 FUN_082340c8(Vec3* pos, Vec3* dir, s32 count, s32 limit) {
#ifdef NONMATCHING_C
  Vec3 cur;
  Vec3 next;
  MapTileOverride* ov;
  CollisionMapTile* tile;
  s32 stairs;
  s32 height;
  s32 bx;
  s32 bz;
  s32 idx;
  s32 r;
  s32 i;

  if (gCollisionMap->tiledata == NULL) {
    return 0;
  }

  r = 0;
  cur = *pos;
  bx = (s8)(cur.x >> 8);
  bz = (s8)(cur.z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }

  for (i = 0; i < count; i++) {
    r = FUN_08233d50(&next, &cur, dir);
    if (r > 1) {
      bx = (s8)(next.x >> 8);
      bz = (s8)(next.z >> 8);
      if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
        idx = 0;
      } else {
        idx = gCollisionMap->rowOffsets[bz] + bx;
      }
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
        height -= (u8)next.z;
        break;
      }
      case 2: {
        height -= (u8)next.x;
        break;
      }
    }

    if (height - pos->y >= limit) {
      return 0;
    }
    if (r == 1) {
      return 1;
    }
    cur = next;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_082340c8.inc");
#endif
}

void Map_InitTileOverride(MapTileOverride* p, s32 tileIdx, s32 stairs, s32 height, s32 occluder, s32 attr) {
  p->tileIdx = tileIdx;
  p->flags = 0;
  p->tile.heightStairs = (stairs << 4) | height;
  p->tile.occluder = occluder;
  p->tile.attr = attr;
}

// tileIdx の上書き情報のうち、mask のビットを持たず height の下位4bitが最大のものを返す
MapTileOverride* Map_FindTileOverride(u32 tileIdx, u32 mask) {
  MapTileOverride* p = gCollisionMap->tileOverrides;
  MapTileOverride* best = NULL;

  while (p != NULL) {
    if (!(p->flags & mask) && p->tileIdx == tileIdx) {
      if (best == NULL || (best->tile.heightStairs & 0xF) < (p->tile.heightStairs & 0xF)) {
        best = p;
      }
    }

    p = p->next;
  }
  return best;
}

// 上書き情報を初期化して、コリジョンマップが持つ双方向リストの先頭に繋ぐ
s32 Map_AddTileOverride(MapTileOverride* p, s32 tileIdx, s32 stairs, s32 height, s32 occluder, s32 attr) {
  Map_InitTileOverride(p, tileIdx, stairs, height, occluder, attr);
  p->prev = NULL;
  p->next = gCollisionMap->tileOverrides;
  if (p->next != NULL) {
    p->next->prev = p;
  }

  gCollisionMap->tileOverrides = p;
  return 0;
}

// 衝突マップのタイル上書きリストからノードを外す
void Map_RemoveTileOverride(MapTileOverride* p) {
  MapTileOverride* prev = p->prev;
  MapTileOverride* next = p->next;

  if (prev != NULL) {
    prev->next = next;
  } else {
    gCollisionMap->tileOverrides = next;
  }

  if (next != NULL) {
    next->prev = prev;
  }
}

// タイルの境界付近にいるとき, 隣や斜め隣のタイルの方が高いかを見る
s32 FUN_082342cc(Vec3* pos, s32 limit) {
  Vec3 v;
  s32 h;

  s32 x0 = (pos->x & 0xFF00) + 0x80;
  s32 y0 = pos->y & 0xFF00;
  s32 z0 = (pos->z & 0xFF00) + 0x80;

  CollisionMapTile* tile = GetTileAt(pos);
  if (tile == NULL) {
    return 0;
  }

  h = tile->heightStairs & 0xF;

  if ((pos->x & 0xFF) < limit) {
    if ((pos->z & 0xFF) >= limit) {
      v.x = x0, v.y = y0, v.z = z0 + 0xFF;
      if (h < (GetTileAt(&v)->heightStairs & 0xF)) {
        return 1;
      }
    }
  } else if ((pos->z & 0xFF) >= limit) {
    VEC3_SET(v, x0 + 0xFF, y0, z0);
    if (h < (GetTileAt(&v)->heightStairs & 0xF)) {
      return 1;
    }

    v.x = x0, v.y = y0, v.z = z0 + 0xFF;
    if (h < (GetTileAt(&v)->heightStairs & 0xF)) {
      return 1;
    }

    v.x = x0 + 0xFF, v.y = y0, v.z = z0 + 0xFF;
    if (h < (GetTileAt(&v)->heightStairs & 0xF)) {
      return 1;
    }
  } else {
    VEC3_SET(v, x0 + 0xFF, y0, z0);
    if (h < (GetTileAt(&v)->heightStairs & 0xF)) {
      return 1;
    }
  }

  return 0;
}

bool32 FUN_082345ec(void) { return bool32_0300077c; }

// このゲームでこの関数が呼ばれることはない
s32 Map_LoadZones(FileID id) {
  gCollisionMap->zones = GetFile(0xDCFB, id);
  bool32_0300077c = FALSE;
  return 0;
}

void Map_SetZones(ZoneData* zones) {
  gCollisionMap->zones = zones;
  bool32_0300077c = FALSE;
}

// 範囲内に残っているイベントを一通り引き直す
void FUN_0823463c(ZoneEventSource* src) {
  s32 i;

  for (i = 0; i < src->activeCount; i++) {
    Map_FindEventByID(src->activeEvents[i]);
  }
}

// src の位置を全ゾーンイベントと突き合わせ, 範囲に入った/出たイベントのスクリプトを走らせる
// 残差8命令 (221/229): 原典は hitIdx をスタックに置いて書き込みを残し, ループ条件を先頭と末尾の両方に展開して &gCollisionMap を r10 に巻き上げる
// hitIdx はどこからも読まれないので agbcc が消してしまう
NON_MATCH void FUN_08234660(ZoneEventSource* src) {
#ifdef NONMATCHING_C
  s32 hitIdx = 0;
  s32 count;
  s32 i;

  bool32_0300077c = TRUE;
  count = src->activeCount;
  for (i = 0; i < gCollisionMap->eventCount; i++) {
    CollisionMapEvent* ev = &gCollisionMap->events[i];
    bool32 pass;
    bool32 inside;

    if (ev->unk_6 != src->id && ev->unk_6 != 0x14C9) {
      continue;
    }

    if (ev->flags & 0x10) {
      pass = (gInput[0].pressed & ev->keys) != 0;
    } else {
      pass = TRUE;
    }

    inside = FALSE;
    if (pass) {
      Vec3* pos = src->pos;
      s32 j;

      for (j = 0; j < ev->zoneCount; j++) {
        Zone* zone = &ev->zones[j];

        if (pos->x >= zone->x1 && pos->x < zone->x2 && pos->z >= zone->y1 && pos->z < zone->y2) {
          inside = TRUE;
          break;
        }
      }
    }

    if (inside) {
      s32 k;

      for (k = 0; k < count; k++) {
        if (src->activeEvents[k] == ev->id) {
          hitIdx = k;
          if (ev->unk_4 == 0xA5BF || ev->unk_4 == 0x1516 || ev->unk_4 == 0x1517) {
            Map_RunZoneEventScript(src, ev, 0xA5BF);
          }
          break;
        }
      }
      if (k >= count) {
        src->activeEvents[count] = ev->id;
        hitIdx = count;
        if (ev->unk_4 == 0xDD2 || ev->unk_4 == 0x14C9 || ev->unk_4 == 0x1516 || ev->unk_4 == 0x1517) {
          Map_RunZoneEventScript(src, ev, 0xDD2);
        }
        count++;
      }
    } else {
      bool32 removed = FALSE;
      s32 k;

      for (k = 0; k < count; k++) {
        if (src->activeEvents[k] == ev->id) {
          hitIdx = k;
          if (k < count) {
            while (k < count) {
              if (k < count - 1) {
                src->activeEvents[k] = src->activeEvents[k + 1];
              } else {
                src->activeEvents[k] = 0;
              }
              k++;
            }
          }
          removed = TRUE;
          break;
        }
      }

      if (removed) {
        count--;
        if (ev->unk_4 == 0xD5CC || ev->unk_4 == 0x14C9 || ev->unk_4 == 0x1516) {
          Map_RunZoneEventScript(src, ev, 0xD5CC);
        }
      }
    }
  }

  src->activeCount = count;
#else
  INCFUNC("asm/func/FUN_08234660.inc");
#endif
}

// ゾーンイベントのスクリプトを 14 個の引数付きで起動する
// 原典は args[2] から args[13] までを1本のカーソルで書くが, agbcc が先頭4本だけ固定オフセットに畳んでしまう
// 命令数は68で一致, 残差はその畳み込み1箇所のみ, Tier A-C は試済
NON_MATCH void Map_RunZoneEventScript(ZoneEventSource* src, CollisionMapEvent* ev, u16 msg) {
#ifdef NONMATCHING_C
  u32 args[14];
  ScriptArgs sa;
  u32* arg;
  s32 i;

  args[0] = src->id;
  args[1] = ev->zoneID;
  arg = &args[2];
  *arg++ = msg;
  *arg++ = src->pos->x;
  *arg++ = src->pos->y;
  *arg++ = src->pos->z;
  for (i = 0; i < 4; i++) {
    *arg++ = ev->args1[i];
  }
  for (i = 0; i < 4; i++) {
    *arg++ = ev->args2[i];
  }

  sa.argc = 14;
  sa.argv = args;
  if (ev->flags & 0x20) {
    VM_ExecById_Proxy_0823a8a4((u32)ev->scriptPC, &sa);
  } else {
    FUN_0823a88c(ev->scriptPC, &sa);
  }
#else
  INCFUNC("asm/func/Map_RunZoneEventScript.inc");
#endif
}

// id を持つゾーンが1つでもあるか
bool32 Map_HasZoneByID(ZoneID16 id) {
  s32 i;

  for (i = 0; i < gCollisionMap->zones->count; i++) {
    if (gCollisionMap->zones->zones[i].id == id) {
      return TRUE;
    }
  }
  return FALSE;
}

// id を持つゾーンのうち最初の1つを返し、同じIDのゾーンの数を count に書く
Zone* FindZonesByID(ZoneID16 id, u16* count) {
  Zone* first;
  s32 i;

  *count = 0;
  first = NULL;
  for (i = 0; i < gCollisionMap->zones->count; i++) {
    Zone* zone = &gCollisionMap->zones->zones[i];

    if (zone->id == id) {
      if (first == NULL) {
        first = zone;
      }
      (*count)++;
    }
  }
  return first;
}

// id を持つイベントを返す, 無ければ NULL, 件数に events ではなく zones の件数を使っている
CollisionMapEvent* Map_FindEventByID(u32 id) {
  s32 i;

  for (i = 0; i < gCollisionMap->zones->count; i++) {
    if (gCollisionMap->events[i].id == id) {
      return &gCollisionMap->events[i];
    }
  }
  return NULL;
}

// 同じ zoneID が連続するように events へ挿し込む, 末尾から同じ zoneID を探し, 見つかればその次へ入れる
// 残差2命令 (166/168): 原典は &gCollisionMap を r8 に巻き上げて使い回すが, こちらはプール定数を参照ごとに読み直す
// Tier A-C は試済: found の宣言時初期化と代入文の分離
NON_MATCH void Map_InsertEvent(CollisionMapEvent* ev, u32 param_2) {
#ifdef NONMATCHING_C
  bool32 found;
  s32 i;

  if (gNextMapEventID == 0) {
    gNextMapEventID = 1;
  }
  ev->id = gNextMapEventID;
  gNextMapEventID++;

  found = FALSE;
  i = gCollisionMap->eventCount;
  while (i > 0) {
    if (ev->zoneID == gCollisionMap->events[i - 1].zoneID) {
      found = TRUE;
      break;
    }
    i--;
  }

  if (!found) {
    gCollisionMap->events[gCollisionMap->eventCount] = *ev;
    gCollisionMap->unk_d24[gCollisionMap->eventCount] = param_2;
  } else {
    s32 j;

    for (j = gCollisionMap->eventCount; j > i; j--) {
      gCollisionMap->events[j] = gCollisionMap->events[j - 1];
      gCollisionMap->unk_d24[j] = gCollisionMap->unk_d24[j - 1];
    }
    gCollisionMap->events[i] = *ev;
    gCollisionMap->unk_d24[i] = param_2;
  }

  gCollisionMap->eventCount++;
#else
  INCFUNC("asm/func/Map_InsertEvent.inc");
#endif
}

// スクリプトの 'n' 引数に並んだゾーンIDのイベントを events から取り除いて前へ詰める
// 命令数は84で一致, 残差はレジスタ割当のみ (原典は events を r4, unk_d24 を sl, 書き込み先のバイトオフセットを r3 に置く)
// Tier A/B と C の宣言順は試済
NON_MATCH s32 VM_Ctrl_RemoveZoneEvents(void) {
#ifdef NONMATCHING_C
  s32 count = gCollisionMap->eventCount;

  VM_SeekToNamedArg('n');
  while (VM_GetPC() != NULL) {
    CollisionMapEvent* events = gCollisionMap->events;
    u32* aux = gCollisionMap->unk_d24;
    s32 n = 0;
    u32 id = VM_GetValue();
    s32 i;

    for (i = 0; i < count; i++) {
      if (id != events[i].zoneID) {
        gCollisionMap->events[n] = events[i];
        gCollisionMap->unk_d24[n] = aux[i];
        n++;
      }
    }
    count = n;
  }

  gCollisionMap->eventCount = count;
  return 0;
#else
  INCFUNC("asm/func/VM_Ctrl_RemoveZoneEvents.inc");
#endif
}

void Map_ClearEvent(CollisionMapEvent* ev) { ClearMemory(ev, sizeof(CollisionMapEvent)); }

// 指定IDのゾーンの範囲と中心をスクリプトの戻り値として積む
s32 Cmd_GetZoneBounds(void) {
  u16 count;
  Zone* zone;

  if (VM_GetPC() == NULL) {
    return -1;
  }

  zone = FindZonesByID(VM_GetValue(), &count);
  if (zone == NULL) {
    return -1;
  }

  {
    u8 desc[8];

    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, zone->x1);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, zone->z1 << 4);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, zone->y1);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, zone->x2);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, zone->z2 << 4);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, zone->y2);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, FixToInt(1, zone->x2 + zone->x1));
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, FixToInt(1, zone->z2 + zone->z1) << 4);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, FixToInt(1, zone->y2 + zone->y1));
  }
  return 0;
}

// ゾーンの左上隅を Vec3 の単位 (z は 16 倍) で取り出す
void Map_GetZoneMin(u16 id, u16* out) {
  u16 count;
  Zone* zone = FindZonesByID(id, &count);

  if (zone != NULL) {
    out[0] = zone->x1;
    out[1] = zone->z1 << 4;
    out[2] = zone->y1;
  }
}

// ゾーンの右下隅を Vec3 の単位 (z は 16 倍) で取り出す
void Map_GetZoneMax(u16 id, u16* out) {
  u16 count;
  Zone* zone = FindZonesByID(id, &count);

  if (zone != NULL) {
    out[0] = zone->x2;
    out[1] = zone->z2 << 4;
    out[2] = zone->y2;
  }
}

// id のゾーンのどれかが pos を含んでいるか
bool8 Map_IsPosInZoneByID(ZoneID16 id, Vec3* pos) {
  u16 count;
  Zone* zone = FindZonesByID(id, &count);
  u16 i;

  if (zone == NULL) {
    return FALSE;
  }

  for (i = 0; i < count; i++) {
    if (pos->x >= zone->x1 && pos->x < zone->x2 && pos->z >= zone->y1 && pos->z < zone->y2) {
      return TRUE;
    }
    zone++;
  }
  return FALSE;
}

// このゲームでこの関数が呼ばれることはない
s32 Map_LoadPaths(FileID id) {
  gCollisionMap->paths = GetFile(0xD4FB, id);
  return 0;
}

void Map_SetPaths(PathData* paths) { gCollisionMap->paths = paths; }

// 経路をたどるカーソルを pathIdx / nodeIdx で初期化する
// 残差1命令: 原典は2回目の nodeCount を path と同じレジスタに読んで潰すため, 先に path のコピーを1本持つ
NON_MATCH bool32 Map_InitPathWalker(PathWalker* p, u32 pathIdx, u32 param_3, u32 nodeIdx) {
#ifdef NONMATCHING_C
  PathData* d = gCollisionMap->paths;
  Path* path;
  PathNode* nodes;

  if (pathIdx >= d->pathCount) {
    return FALSE;
  }

  path = &d->paths[pathIdx];
  if (path->nodeCount == 0) {
    return FALSE;
  }

  if (nodeIdx >= path->nodeCount) {
    nodeIdx = 0;
  }

  nodes = (PathNode*)((u8*)d + path->nodeOffset);
  p->pathIdx = pathIdx;
  p->unk_1 = param_3;
  p->nodeIdx = nodeIdx;
  p->unk_3 = 0;
  p->path = path;
  p->node = &nodes[p->nodeIdx];
  return TRUE;
#else
  INCFUNC("asm/func/Map_InitPathWalker.inc");
#endif
}

// 次のノードへ進める, 末尾まで行ったら先頭に戻る
bool32 Map_AdvancePathWalker(PathWalker* p) {
  u8* base;
  PathNode* nodes;

  p->nodeIdx++;
  if (p->nodeIdx >= p->path->nodeCount) {
    p->nodeIdx = 0;
  }

  p->unk_3 = 0;
  base = (u8*)gCollisionMap->paths;
  nodes = (PathNode*)(base + p->path->nodeOffset);
  p->node = &nodes[p->nodeIdx];
  return TRUE;
}

// カーソルの指すノードへ向かう移動量を out に入れる, rx/rz の範囲内なら差分をそのまま入れて 1 を返す
bool8 Map_GetStepToPathNode(PathWalker* w, Vec3* pos, Vec3* out, u8* outAngle, u32 rx, u32 rz, s32 speed) {
  PathNode* node = w->node;
  Vec3 nodePos;
  s32 dx, dz;
  u8 angle;

  nodePos.x = node->x;
  nodePos.z = node->y;

  dx = nodePos.x - pos->x;
  dz = nodePos.z - pos->z;
  angle = ArcTan2_8(dx, dz);
  *outAngle = angle;

  if (abs(dx) <= rx && abs(dz) <= rz) {
    out->x = dx;
    out->z = dz;
    return TRUE;
  }
  out->x = POLAR_X(speed, angle);
  out->z = POLAR_Z(speed, angle);
  return FALSE;
}

Path* Map_GetPath(u8 idx) {
  PathData* d = gCollisionMap->paths;

  if (idx >= d->pathCount) return NULL;

  return &d->paths[idx];
}

// その経路の先頭ノードを指す
PathNode* Map_GetPathNodes(Path* path) {
  u8* base = (u8*)gCollisionMap->paths;

  return (PathNode*)(base + path->nodeOffset);
}

// 経路ノードの座標を Vec3 の X/Z に取り出す
void Map_ReadPathNodePos(Vec3* dst, PathNode* nodes, u8 idx) {
  dst->x = nodes[idx].x;
  dst->z = nodes[idx].y;
}

// パス pathIdx の nodeIdx 番目のノードの座標を *dst に入れる
s32 Map_GetPathNodePos(Vec3* dst, u8 pathIdx, u8 nodeIdx) {
  PathNode* nodes = Map_GetPathNodes(Map_GetPath(pathIdx));

  if (nodes == NULL) {
    dst->x = 0;
    dst->z = 0;
    return -1;
  }

  Map_ReadPathNodePos(dst, nodes, nodeIdx);
  return 0;
}

// スクリプトから経路番号とノード番号を読み、そのノードの座標を配列変数に3つ書き込む
// 残差2命令: 原典は pos をスタック先頭 (sp+0)、desc を sp+8 に置くが、agbcc はこちらでは逆に並べる
// 宣言順の入れ替え・ブロック内宣言は効かなかった
NON_MATCH s32 Cmd_GetPathNodePos(void) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 pathIdx = VM_GetValue();
  s32 nodeIdx = VM_GetValue();
  u8 desc[8];

  if (Map_GetPathNodePos(&pos, pathIdx, nodeIdx) < 0) {
    return -1;
  }

  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, pos.x);
  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, pos.y);
  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, pos.z);
  return 0;
#else
  INCFUNC("asm/func/Cmd_GetPathNodePos.inc");
#endif
}

// pos がカーソルの指すノードから rx, rz の範囲内にあるか調べる, 外なら 1
// 残差は nodePos.z のレジスタコピー1命令のみ (41/42), Tier A-C は試済
NON_MATCH s32 Map_IsPosOutsidePathNode(PathWalker* w, Vec3* pos, u32 rx, u32 rz) {
#ifdef NONMATCHING_C
  Vec3 nodePos;
  PathNode* node = w->node;

  nodePos.x = node->x;
  nodePos.z = node->y;
  if (abs(pos->x - nodePos.x) > rx) {
    return 1;
  }
  if (abs(pos->z - nodePos.z) > rz) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/Map_IsPosOutsidePathNode.inc");
#endif
}

// パス pathIdx のノードを1つランダムに選び, その座標と足元の高さを dst に入れてノード番号を返す
// Tier A/B と C のガード分割は試済, 同種の CSE 残差は JudgementParticle_UpdateStill などにもある
s32 Map_PickRandomPathNode(Vec3* dst, s32 pathIdx) {
  Path* path = Map_GetPath(pathIdx);
  s32 nodeIdx;

  if (path == NULL || path->nodeCount == 0) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return -1;
  }

  nodeIdx = Mod(Random(), path->nodeCount);
  Map_GetPathNodePos(dst, pathIdx, nodeIdx);
  dst->y = TileHeightAt(dst);
  return nodeIdx;
}

// pos に最も近い経路ノードを探して dst に入れ, そのノード番号を返す
s32 Map_FindNearestPathNode(Vec3* dst, Vec3* pos, s32 pathIdx) {
  s32 ret = -1;
  Path* path = Map_GetPath(pathIdx);
  PathNode* nodes;
  Vec3 node;
  u32 best;
  s32 i;

  if (path == NULL || path->nodeCount == 0) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return ret;
  }

  nodes = Map_GetPathNodes(path);
  if (nodes == NULL) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return ret;
  }

  best = -1;
  for (i = 0; i < path->nodeCount; i++) {
    s32 dx;
    s32 dz;
    u32 d;

    Map_ReadPathNodePos(&node, nodes, i);
    dx = pos->x - node.x;
    dz = pos->z - node.z;
    d = dx * dx + dz * dz;
    if (d < best) {
      ret = i;
      best = d;
      dst->x = node.x;
      dst->z = node.z;
    }
  }

  dst->y = TileHeightAt(dst);
  return ret;
}

// pos から最も遠い経路ノードを探して dst に入れ, そのノード番号を返す
s32 Map_FindFarthestPathNode(Vec3* dst, Vec3* pos, s32 pathIdx) {
  s32 ret = -1;
  Path* path = Map_GetPath(pathIdx);
  PathNode* nodes;
  Vec3 node;
  u32 best;
  s32 i;

  if (path == NULL || path->nodeCount == 0) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return ret;
  }

  nodes = Map_GetPathNodes(path);
  if (nodes == NULL) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return ret;
  }

  best = 0;
  for (i = 0; i < path->nodeCount; i++) {
    s32 dx;
    s32 dz;
    u32 d;

    Map_ReadPathNodePos(&node, nodes, i);
    dx = pos->x - node.x;
    dz = pos->z - node.z;
    d = dx * dx + dz * dz;
    if (d >= best) {
      ret = i;
      best = d;
      dst->x = node.x;
      dst->z = node.z;
    }
  }

  dst->y = TileHeightAt(dst);
  return ret;
}

// pos から minDistSq 以上離れたなかで最も近い経路ノードを探して dst に入れ, そのノード番号を返す
// 残差0命令 (164/164), レジスタ名だけ違う: 原典は dst を r6 / i を r5 に置くが, こちらは逆になる (先頭ノードの先読みで dst の参照が2つ増えるため)
NON_MATCH s32 FUN_08235408(Vec3* dst, Vec3* pos, s32 pathIdx, u32 minDistSq) {
#ifdef NONMATCHING_C
  s32 ret = -1;
  Path* path = Map_GetPath(pathIdx);
  PathNode* nodes;
  Vec3 node;
  u32 best;
  s32 i;

  if (path == NULL || path->nodeCount == 0) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return ret;
  }

  nodes = Map_GetPathNodes(path);
  if (nodes == NULL) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return ret;
  }

  Map_ReadPathNodePos(&node, nodes, 0);
  dst->x = node.x;
  dst->z = node.z;

  best = -1;
  for (i = 0; i < path->nodeCount; i++) {
    s32 dx;
    s32 dz;
    u32 d;

    Map_ReadPathNodePos(&node, nodes, i);
    dx = pos->x - node.x;
    dz = pos->z - node.z;
    d = dx * dx + dz * dz;
    if (d < best && d >= minDistSq) {
      ret = i;
      best = d;
      dst->x = node.x;
      dst->z = node.z;
    }
  }

  dst->y = TileHeightAt(dst);
  return ret;
#else
  INCFUNC("asm/func/FUN_08235408.inc");
#endif
}

// 経路上のランダムな位置から順に走査して, pos から minDistSq 以上離れた最初のノードを dst に入れる
s32 Map_FindPathNodeBeyond(Vec3* dst, Vec3* pos, s32 pathIdx, u32 minDistSq) {
  Path* path = Map_GetPath(pathIdx);
  s32 start;
  s32 i;

  if (path == NULL || path->nodeCount == 0) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return -1;
  }

  start = Mod(Random(), path->nodeCount);
  for (i = start; i < start + path->nodeCount; i++) {
    Vec3 node;
    s32 dx, dz;
    u32 d;

    s32 idx = Mod(i, path->nodeCount);
    Map_GetPathNodePos(&node, pathIdx, idx);
    dx = pos->x - node.x;
    dz = pos->z - node.z;
    d = dx * dx + dz * dz;
    if (d >= minDistSq) {
      dst->x = node.x;
      dst->z = node.z;
      dst->y = TileHeightAt(dst);
      return idx;
    }
  }
  return start;
}

// 経路のランダムな位置から1周走査して, min..max の範囲に入る最後のノードを dst に入れる
// 残差2命令 (179/181): 原典は idx を r7 に置き node.x を store 直前に読み直すが, こちらは idx をスタックに溢れさせて node.x を巻き上げる
// Tier A-C は試済: ret の宣言位置 (prologue の -1 はこれで一致した), 範囲判定を 0/1 フラグに起こす形 (182 と悪化), idx の宣言位置
NON_MATCH s32 FUN_082356c4(Vec3* dst, Vec3* min, Vec3* max, s32 pathIdx) {
#ifdef NONMATCHING_C
  s32 ret = -1;
  Path* path = Map_GetPath(pathIdx);
  PathNode* nodes;
  Vec3 node;
  s32 start;
  s32 i;

  if (path == NULL || path->nodeCount == 0) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return ret;
  }

  nodes = Map_GetPathNodes(path);
  if (nodes == NULL) {
    dst->x = 0, dst->y = 0, dst->z = 0;
    return ret;
  }

  start = Mod(Random(), path->nodeCount);
  Map_ReadPathNodePos(&node, nodes, 0);
  dst->x = node.x;
  dst->z = node.z;

  for (i = start; i < start + path->nodeCount; i++) {
    s32 idx = Mod(i, path->nodeCount);

    Map_ReadPathNodePos(&node, nodes, idx);
    if (node.x >= min->x && node.x <= max->x && node.z >= min->z && node.z <= max->z) {
      ret = idx;
      dst->x = node.x;
      dst->z = node.z;
    }
  }

  dst->y = TileHeightAt(dst);
  return ret;
#else
  INCFUNC("asm/func/FUN_082356c4.inc");
#endif
}

// kind ごとの移動判定に振り分ける, どれも失敗したら Map_PickRandomPathNode で戻す
// kind に応じた探索で経路ノードを1つ選ぶ, 見つからなければ乱択にする
// 残差1命令 (56/55): 原典は param_5 の2乗を一旦別レジスタで作ってから minDistSq へ写すが, agbcc は宛先レジスタの中で直接 muls する
// Tier A-C は試済: 宣言時初期化/代入文の分離, Square 相当の static inline
NON_MATCH s32 FUN_0823585c(Vec3* dst, Vec3* pos, u32 kind, s32 param_4, s32 param_5, Vec3* min, Vec3* max) {
#ifdef NONMATCHING_C
  s32 ret = -1;
  u32 minDistSq = param_5 * param_5;

  switch (kind) {
    case 0: {
      ret = Map_PickRandomPathNode(dst, param_4);
      break;
    }
    case 1: {
      ret = Map_FindNearestPathNode(dst, pos, param_4);
      break;
    }
    case 2: {
      ret = Map_FindFarthestPathNode(dst, pos, param_4);
      break;
    }
    case 3: {
      ret = FUN_08235408(dst, pos, param_4, minDistSq);
      break;
    }
    case 4: {
      ret = Map_FindPathNodeBeyond(dst, pos, param_4, minDistSq);
      break;
    }
    case 5: {
      ret = FUN_082356c4(dst, min, max, param_4);
      break;
    }
  }

  if (ret < 0) {
    ret = Map_PickRandomPathNode(dst, param_4);
  }
  return ret;
#else
  INCFUNC("asm/func/FUN_0823585c.inc");
#endif
}

// このゲームでは使われない (呼び出す条件を満たさない)
// 残差1命令, 原典は GetFile の戻り値を r1 へ写して r0 にプールを取るが gcc は逆に割り当てる
NON_MATCH s32 Map_LoadNavMesh(FileID id) {
#ifdef NONMATCHING_C
  gCollisionMap->navMesh = GetFile(0xF63B, id);
  return 0;
#else
  INCFUNC("asm/func/Map_LoadNavMesh.inc");
#endif
}

void Map_SetNavMesh(NavMesh* navMesh) { gCollisionMap->navMesh = navMesh; }

// pos が rects[idx] の矩形の中にあるか, 矩形は1タイル単位なので 8bit 左シフトして比べる
bool32 Map_IsPosInNavRect(NavRect* rects, Vec3* pos, u32 idx) {
  NavRect* rect = &rects[idx];

  if (pos->x >= (rect->minX << 8) && pos->x < (rect->maxX << 8) && pos->z >= (rect->minY << 8) && pos->z < (rect->maxY << 8)) {
    return TRUE;
  }
  return FALSE;
}

// a と b の距離を distanceMap (上三角だけを詰めた行列) から引く, 同じなら 0
// 残差は最後の4命令のレジスタだけ (原典は引き算の結果を左辺のレジスタに残す), 命令数は31で一致, Tier A/B と C の lo/hi 変数化・複合代入は試済
NON_MATCH u16 Map_GetNavDistance(u16* distanceMap, u16 n, s32 a, s32 b) {
#ifdef NONMATCHING_C
  s32 idx;

  if (a == b) {
    return 0;
  }

  if (a <= b) {
    idx = a * n + b - ((a + 2) * (a + 1) >> 1);
  } else {
    idx = b * n + a - ((b + 2) * (b + 1) >> 1);
  }

  return distanceMap[idx];
#else
  INCFUNC("asm/func/Map_GetNavDistance.inc");
#endif
}

// pos を含むナビ島が agent->islandIdx と同じかを返す, 壁タイルの上なら FALSE
// dst のタイルが壁でなく, かつ agent と同じ島のナビ矩形に入っているか
bool32 Map_IsPosInAgentIsland(NavAgent* agent, WorldPos* pos, WorldPos* dst) {
  NavMesh* navMesh = gCollisionMap->navMesh;
  s32 i;
  if (GetTileAttrAt(dst) & TATTR_WALL) {
    return FALSE;
  }

  for (i = 0; i < navMesh->countIslands; i++) {
    NavIsland* island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[i]);
    NavRect* rects = (NavRect*)((u8*)island + island->offsetToRects);
    s32 j;

    for (j = 0; j < island->countRects; j++) {
      if (Map_IsPosInNavRect(rects, dst, j)) {
        if (i == agent->islandIdx) {
          return TRUE;
        }
        return FALSE;
      }
    }
  }
  return FALSE;
}

// pos から dst へ向かう経路を引き直す, 両者が同じナビ矩形群で繋がっていればそのまま進ませ, そうでなければ距離表が最小になるポータルの組を選ぶ
// 残差1命令 (593/592): 原典は agent->flags = 0 の3箇所がスクラッチレジスタ違いで融合せず, その影響で flags = 6 のブロックが最終代入の前に置かれる
// Tier A-C は試済: 戻り値の形, ループ変数の共有, NavRect ポインタの宣言順
NON_MATCH s32 FUN_08235a84(NavAgent* agent, WorldPos* pos, WorldPos* dst) {
#ifdef NONMATCHING_C
  u16 dstRects[6];
  u16 posRects[6];
  NavMesh* navMesh;
  NavIsland* island;
  NavRect* rects;
  NavPortal* portals;
  u16* distanceMap;
  NavRect* posRect;
  NavRect* dstRect;
  NavPortal* portal;
  u32 best;
  s32 nextPortal;
  s32 goalPortal;
  u16 dstCount;
  u16 posCount;
  s32 island0;
  s32 rect0;
  s32 i;
  s32 j;
  s32 k;
  s32 m;
  s32 n;

  if (agent->unk_0c.x == dst->x && agent->unk_0c.z == dst->z && agent->unk_14.x == pos->x && agent->unk_14.z == pos->z) {
    return 2;
  }

  navMesh = gCollisionMap->navMesh;
  agent->unk_0c.x = dst->x;
  agent->unk_0c.z = dst->z;

  // dst を含むナビ矩形を探す
  island0 = 0xFF;
  rect0 = 0xFF;
  island = NULL;
  rects = NULL;
  for (i = 0; i < navMesh->countIslands; i++) {
    island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[i]);
    rects = (NavRect*)((u8*)island + island->offsetToRects);
    for (j = 0; j < island->countRects; j++) {
      if (Map_IsPosInNavRect(rects, dst, j)) {
        island0 = i;
        rect0 = j;
        i = navMesh->countIslands;
        j = island->countRects;
      }
    }
  }

  if (rect0 == 0xFF) {
    agent->flags = 0;
    return 0;
  }
  if (agent->islandIdx != island0) {
    agent->flags = 0;
    return 0;
  }
  if (agent->rectIdx == rect0) {
    agent->unk_0c = *dst;
    agent->unk_1c = *dst;
    agent->unk_14 = *pos;
    agent->flags = 6;
    return 1;
  }
  if (island == NULL || rects == NULL) {
    return 0;
  }

  portals = (NavPortal*)((u8*)island + island->offsetToPortals);
  distanceMap = (u16*)((u8*)island + island->offsetToDistanceMap);

  // dst を含む矩形をポータル伝いに集める
  for (i = 0; i < 6; i++) {
    dstRects[i] = 0xFF;
  }
  dstRect = &rects[rect0];
  dstRects[0] = rect0;
  dstCount = 1;
  for (i = 0; i < 12 && dstRect->portals[i] != 0xFF && dstCount <= 5; i++) {
    portal = &portals[dstRect->portals[i]];
    for (j = 0; j < 6 && portal->rects[j] != 0xFF && dstCount <= 5; j++) {
      if (portal->rects[j] != dstRects[0] && Map_IsPosInNavRect(rects, dst, portal->rects[j])) {
        s32 fresh = 1;

        for (n = 0; n < dstCount; n++) {
          if (dstRects[n] == portal->rects[j]) {
            fresh = 0;
          }
        }
        if (fresh) {
          dstRects[dstCount] = portal->rects[j];
          dstCount++;
        }
      }
    }
  }

  // pos を含む矩形も同じように集める
  for (i = 0; i < 6; i++) {
    posRects[i] = 0xFF;
  }
  posRect = &rects[agent->rectIdx];
  posRects[0] = agent->rectIdx;
  posCount = 1;
  for (i = 0; i < 12 && posRect->portals[i] != 0xFF && posCount <= 5; i++) {
    portal = &portals[posRect->portals[i]];
    for (j = 0; j < 6 && portal->rects[j] != 0xFF && posCount <= 5; j++) {
      if (portal->rects[j] != posRects[0] && Map_IsPosInNavRect(rects, pos, portal->rects[j])) {
        s32 fresh = 1;

        for (n = 0; n < posCount; n++) {
          if (posRects[n] == portal->rects[j]) {
            fresh = 0;
          }
        }
        if (fresh) {
          posRects[posCount] = portal->rects[j];
          posCount++;
        }
      }
    }
  }

  // 同じ矩形で繋がっているならポータルを経由しなくてよい
  for (i = 0; i < posCount; i++) {
    for (j = 0; j < dstCount; j++) {
      if (posRects[i] == dstRects[j]) {
        agent->unk_0c = *dst;
        agent->unk_1c = *dst;
        agent->unk_14 = *pos;
        agent->flags = 6;
        return 1;
      }
    }
  }

  // 距離表が最小になるポータルの組を選ぶ, 同値なら pos に近い方
  best = 0xFFFF;
  nextPortal = 0xFF;
  goalPortal = 0xFF;
  for (i = 0; i < posCount; i++) {
    posRect = &rects[posRects[i]];

    for (j = 0; j < dstCount; j++) {
      dstRect = &rects[dstRects[j]];

      for (k = 0; k < 12 && dstRect->portals[k] != 0xFF; k++) {
        for (m = 0; m < 12 && posRect->portals[m] != 0xFF; m++) {
          s32 d = Map_GetNavDistance(distanceMap, island->countPortals, dstRect->portals[k], posRect->portals[m]);

          if (d < best) {
            best = d;
            nextPortal = posRect->portals[m];
            goalPortal = dstRect->portals[k];
          } else if (d == best && best != 0xFFFF) {
            s32 dx = pos->x - portals[posRect->portals[m]].x;
            s32 dz = pos->z - portals[posRect->portals[m]].y;
            s32 cur = dx * dx + dz * dz;
            s32 ox = pos->x - portals[nextPortal].x;
            s32 oz = pos->z - portals[nextPortal].y;

            if (cur < ox * ox + oz * oz) {
              nextPortal = posRect->portals[m];
              goalPortal = dstRect->portals[k];
            }
          }
        }
      }
    }
  }

  if (best > 0xFFFE) {
    agent->flags = 0;
    return 0;
  }

  agent->goalPortal = goalPortal;
  agent->unk_0c = *dst;
  agent->unk_14 = *pos;
  agent->nextPortal = nextPortal;
  agent->unk_1c.x = portals[nextPortal].x;
  agent->unk_1c.y = 0;
  agent->unk_1c.z = portals[nextPortal].y;
  agent->flags = 3;
  return 1;
#else
  INCFUNC("asm/func/FUN_08235a84.inc");
#endif
}

// dst のタイルが壁なら進行をやめさせ, そうでなければ FUN_08235a84 に任せる
s32 FUN_08235f40(NavAgent* agent, WorldPos* pos, WorldPos* dst) {
  TileAttr attr = GetTileAttrAt(dst);
  if (attr & TATTR_WALL) {
    agent->flags = 0;
    return 0;
  }
  return FUN_08235a84(agent, pos, dst);
}

void FUN_08235fd0(u16* p) { *p = 0; }

bool32 FUN_08235fd8(u16* p) {
  if (*p & 2) {
    *p &= ~2;
    return TRUE;
  }

  return FALSE;
}

// pos が agent のいる矩形から外れていたら, 隣のポータル先 -> 同じ島 -> 他の島 の順に探して agent を移す
// 残差0命令 (149/149), レジスタ割当だけ違う: 原典は navMesh をスタックに溢れさせて pos を r10 / portal を r9 に置くが, こちらは navMesh が r10 を取り portal が低位レジスタに落ちる
// Tier A-C は試済: portals/rect の bare block, j の宣言位置 (関数スコープにして命令数は一致した)
NON_MATCH void FUN_08235ffc(NavMesh* navMesh, NavAgent* agent, Vec3* pos) {
#ifdef NONMATCHING_C
  NavIsland* island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[agent->islandIdx]);
  NavRect* rects = (NavRect*)((u8*)island + island->offsetToRects);
  NavPortal* portals;
  NavRect* rect;
  s32 i;
  s32 j;

  if (Map_IsPosInNavRect(rects, pos, agent->rectIdx)) {
    return;
  }

  portals = (NavPortal*)((u8*)island + island->offsetToPortals);
  rect = &rects[agent->rectIdx];
  for (i = 0; i < 12 && rect->portals[i] != 0xFF; i++) {
    NavPortal* portal = &portals[rect->portals[i]];

    for (j = 0; j < 6; j++) {
      if (portal->rects[j] == 0xFF) {
        break;
      }
      if (portal->rects[j] != agent->rectIdx && Map_IsPosInNavRect(rects, pos, portal->rects[j])) {
        agent->rectIdx = portal->rects[j];
        return;
      }
    }
  }

  for (i = 0; i < island->countRects; i++) {
    if (i != agent->rectIdx && Map_IsPosInNavRect(rects, pos, i)) {
      agent->rectIdx = i;
      return;
    }
  }

  for (i = 0; i < navMesh->countIslands; i++) {
    if (i != agent->islandIdx) {
      island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[i]);
      rects = (NavRect*)((u8*)island + island->offsetToRects);
      for (j = 0; j < island->countRects; j++) {
        if (Map_IsPosInNavRect(rects, pos, j)) {
          agent->islandIdx = i;
          agent->rectIdx = j;
          return;
        }
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_08235ffc.inc");
#endif
}

// 向かっているポータルに近づいたら, そこから距離が最小のポータルを次の目標にする
// 残差0命令 (151/151), レジスタ名だけ違う: 原典は unk_0a の値を r4, portal を r5 に置くが, こちらは逆になる
// Tier A-C は試済: portal ローカルを外す形 (153 と悪化), 索引をローカルに退避する形 (無影響)
NON_MATCH void FUN_08236130(NavMesh* navMesh, NavAgent* agent, Vec3* pos) {
#ifdef NONMATCHING_C
  NavIsland* island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[agent->islandIdx]);
  NavRect* rects = (NavRect*)((u8*)island + island->offsetToRects);
  NavPortal* portals = (NavPortal*)((u8*)island + island->offsetToPortals);
  u16* distanceMap = (u16*)((u8*)island + island->offsetToDistanceMap);
  NavPortal* portal = &portals[agent->nextPortal];
  s32 dx = pos->x - portal->x;
  s32 dz = pos->z - portal->y;
  s32 best;
  s32 bestPortal;
  s32 i;

  if (dx * dx + dz * dz > 3600) {
    return;
  }

  if (agent->goalPortal == agent->nextPortal) {
    agent->unk_1c = agent->unk_0c;
    agent->flags = 6;
    return;
  }

  best = 0xFFFF;
  bestPortal = 0xFF;
  for (i = 0; i < 6 && portal->rects[i] != 0xFF; i++) {
    NavRect* rect = &rects[portal->rects[i]];
    s32 j;

    for (j = 0; j < 12 && rect->portals[j] != 0xFF; j++) {
      if (rect->portals[j] != bestPortal) {
        s32 d = Map_GetNavDistance(distanceMap, island->countPortals, agent->goalPortal, rect->portals[j]);

        if (d < best) {
          best = d;
          bestPortal = rect->portals[j];
        }
      }
    }
  }

  if (best > 0xFFFE) {
    agent->flags = 0;
  } else {
    agent->nextPortal = bestPortal;
    agent->unk_1c.x = portals[bestPortal].x;
    agent->unk_1c.y = 0;
    agent->unk_1c.z = portals[bestPortal].y;
    agent->flags |= 2;
  }
#else
  INCFUNC("asm/func/FUN_08236130.inc");
#endif
}

// ナビメッシュ上の移動を1歩進める, flags の bit0 が立っているときだけ後段も回す
void Map_StepNavPath(NavAgent* agent, Vec3* pos) {
  NavMesh* navMesh = gCollisionMap->navMesh;

  FUN_08235ffc(navMesh, agent, pos);
  if (agent->flags & 1) {
    FUN_08236130(navMesh, agent, pos);
  }
}

// pos を含むナビ矩形の番号を返す, 見つからなければ 0xFF
s32 Map_FindNavRectAt(Vec3* pos) {
  NavMesh* navMesh = gCollisionMap->navMesh;
  s32 i;

  for (i = 0; i < navMesh->countIslands; i++) {
    NavIsland* island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[i]);
    NavRect* rects = (NavRect*)((u8*)island + island->offsetToRects);
    s32 j;

    for (j = 0; j < island->countRects; j++) {
      if (Map_IsPosInNavRect(rects, pos, j)) {
        return j;
      }
    }
  }
  return 0xFF;
}

// pos を含むナビ矩形を総当たりで探して NavAgent を初期化する, 見つからなければ 0xFF のまま
s32 Map_InitNavAgent(NavAgent* agent, WorldPos* pos) {
  NavMesh* navMesh = gCollisionMap->navMesh;
  s32 i;

  agent->islandIdx = 0xFF;
  agent->rectIdx = 0xFF;
  for (i = 0; i < navMesh->countIslands; i++) {
    NavIsland* island = (NavIsland*)((u8*)navMesh + navMesh->islandOffsets[i]);
    NavRect* rects = (NavRect*)((u8*)island + island->offsetToRects);
    s32 j;

    for (j = 0; j < island->countRects; j++) {
      if (Map_IsPosInNavRect(rects, pos, j)) {
        agent->islandIdx = i;
        agent->rectIdx = j;
      }
    }
  }

  agent->flags = 0;
  agent->unk_0c = *pos;
  agent->unk_1c = *pos;
  agent->unk_14 = *pos;
}
