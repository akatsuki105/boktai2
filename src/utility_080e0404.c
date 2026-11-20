#include "collision_map.h"
#include "dust.h"
#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "vec3.h"
#include "video.h"

Enemy* Enemy_GetNextActive(u32 id);
void FlamethrowerManager_ClearGlobal(void);
void Entity081e9cac_ClearGlobal(void);
void OctorokManager_ClearGlobal(void);
void Entity081edcc4_ClearGlobal(void);
void Entity081ee2a0_ClearGlobal(void);
void PitfallWarningManager_ClearGlobal(void);
void Entity081eee80_ClearGlobal(void);
void Entity081f0298_ClearGlobal(void);
void Entity081f0b90_ClearGlobal(void);
void Entity081f1770_ClearGlobal(void);
void Entity081f3324_ClearGlobal(void);
void ThunderboltManager_ClearGlobal(void);
void WormTail_ClearGlobal(void);
void Entity081f7974_ClearGlobal(void);
void Entity081f7de4_ClearGlobal(void);
void FireballManager_ClearGlobal(void);
void OrbitalFlameManager_ClearGlobal(void);
void LinkBattleLobby_ClearGlobal(void);
void Entity081fa164_ClearGlobal(void);
void FlameManager_ClearGlobal(void);
void PitfallManager_ClearGlobal(void);
void LeverSwitchManager_ClearGlobal(void);
void EnemyManager_ClearGlobal(void);
void EmoteManager_Clear(void);
void BloodEmitter_ClearGlobal(void);
void Cmd_ClearEnemyRespawnInfo(void);
void EnemyTargetManager_ClearGlobal(void);
void FUN_081eb33c(void);
void BombManager_ClearGlobal(void);
void SpiderWebManager_ClearGlobal(void);
void Entity081d2180_ClearGlobal(void);
void FUN_080ddb1c(void);
void FUN_08241000(void);
void Entity081efa9c_ClearGlobal(void);
void FUN_080de168(void);
void DebrisManager_ClearGlobal(void);
void Entity081f53a8_ClearGlobal(void);
void FUN_081d6438(void);
void FUN_080df46c(void);
void TomahawkManager_ClearGlobal(void);
void FUN_081d81b8(void);
void Entity081f9cb8_ClearInstance(void);
void LinkShopManager_ClearGlobal(void);
void LinkBattleCoinManager_ClearGlobal(void);
void LinkConnect_ClearGlobal(void);
void ClearLinkSession(void);

const u8 u8_ARRAY_085ad374[80] = {
    0, 0, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0,
};  // 0x085AD374

// tileIdx のタイルの中央の座標を pos に入れる
static inline void SetPosFromTile(Vec3* pos, s32 tileIdx) {
  s32 x = Mod(tileIdx, gCollisionMap->tiledata->width);
  s32 z = Div(tileIdx, gCollisionMap->tiledata->width);

  pos->x = x * 256 + 128;
  pos->y = (TileAtIndex(tileIdx)->heightStairs & 0xF) << 8;
  pos->z = z * 256 + 128;
}

// 命令数は一致, 残差はレジスタ割当だけ (range が r5)
NON_MATCH s32 FUN_080e0404(Vec3* out, s32 param_2, Vec3* base, s32 range) {
#ifdef NONMATCHING_C
  s32 tile = GetCollisionTileIdx(base);
  s32 x = Mod(tile, gCollisionMap->tiledata->width);
  s32 z = Div(tile, gCollisionMap->tiledata->width);
  s32 height = TileAtIndex(tile)->heightStairs & 0xF;
  s32 n = range * 2 + 1;
  s32 tx = Mod(Random(), n) + (x - range);
  s32 tz = Mod(Random(), n) + (z - range);

  if ((s8)u8_ARRAY_085ad374[tx - 5 + (tz - 8) * 8] == height) {
    SetPosFromTile(out, tx + gCollisionMap->tiledata->width * tz);
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_080e0404.inc");
#endif
}

void FUN_080e0588(s32 param_1, s32 param_2, s32* param_3, s32* param_4, s32 angle) {
  s32 y1 = Div(param_1, gCollisionMap->tiledata->width);
  s32 y2 = Div(param_2, gCollisionMap->tiledata->width);
  s32 width = gCollisionMap->tiledata->width;
  s32 x1 = param_1 - width * y1;
  s32 x2 = param_2 - y2 * width;

  *param_3 = x2 - x1;
  *param_4 = y2 - y1;
}

// 命令の並びはほぼ一致, 残差は Mod / Div の前のレジスタ割当
NON_MATCH s32 FUN_080e05f0(Vec3* pos, Vec3* fallback, s32 tile1, s32 tile2) {
#ifdef NONMATCHING_C
  if (tile2 == -255) {
    if (tile1 == tile2) {
      SetPosFromTile(fallback, abs(gCollisionMap->tiledata->width * 12 + 10));
    } else {
      SetPosFromTile(pos, abs(tile1));
      return 1;
    }
  } else {
    SetPosFromTile(pos, abs(tile2));
  }
  return -1;
#else
  INCFUNC("asm/func/FUN_080e05f0.inc");
#endif
}

// 残差は dir == 0 の -255 が末尾と共有される分岐と col + 1 の控え, ループの形は確定
NON_MATCH s32 FUN_080e0748(s32 col, s32 row, s32 tile, s32 value, s32 dir) {
#ifdef NONMATCHING_C
  s32 i;
  s32 end;
  s32 idx;
  s32 width;

  if (dir == 0) {
    return -255;
  }
  if (dir < 0) {
    for (i = 1; i <= -dir && row - i >= 0 && (s8)u8_ARRAY_085ad374[col + (row - i) * 8] == value; i++) {
    }
    end = row + 1 - i;
  } else {
    for (i = 1; i <= dir && row + i < 10 && (s8)u8_ARRAY_085ad374[col + (row + i) * 8] == value; i++) {
    }
    end = row - 1 + i;
  }
  width = gCollisionMap->tiledata->width;
  idx = col + width * (end + 8) + 5;
  if (idx != tile) {
    return idx;
  }
  if (dir < 0) {
    if (end - 2 >= 0 && (s8)u8_ARRAY_085ad374[col + (end - 2) * 8] == value) {
      return width * 2 - idx;
    }
  } else {
    if (end + 2 < 10 && (s8)u8_ARRAY_085ad374[col + (end + 2) * 8] == value) {
      return -(idx + width * 2);
    }
  }
  return -255;
#else
  INCFUNC("asm/func/FUN_080e0748.inc");
#endif
}

// 命令数は一致, 残差は dir == 0 の -255 が末尾と共有される分岐と col + 1 の控え
NON_MATCH s32 FUN_080e0884(s32 col, s32 row, s32 tile, s32 value, s32 dir) {
#ifdef NONMATCHING_C
  s32 i;
  s32 end;
  s32 idx;

  if (dir == 0) {
    return -255;
  }
  if (dir < 0) {
    for (i = 1; i <= -dir && col - i >= 0 && (s8)u8_ARRAY_085ad374[col - i + row * 8] == value; i++) {
    }
    end = col + 1 - i;
  } else {
    for (i = 1; i <= dir && col + i < 8 && (s8)u8_ARRAY_085ad374[col + i + row * 8] == value; i++) {
    }
    end = col - 1 + i;
  }
  idx = end + gCollisionMap->tiledata->width * (row + 8) + 5;
  if (idx != tile) {
    return idx;
  }
  if (dir < 0) {
    if (end - 2 >= 0 && (s8)u8_ARRAY_085ad374[end - 2 + row * 8] == value) {
      return 2 - idx;
    }
  } else {
    if (end + 2 < 8 && (s8)u8_ARRAY_085ad374[end + 2 + row * 8] == value) {
      return -(idx + 2);
    }
  }
  return -255;
#else
  INCFUNC("asm/func/FUN_080e0884.inc");
#endif
}

// 251/280 命令, 歩く向きごとのループの原典の形は未解決, Tier A の途中
NON_MATCH s32 FUN_080e09b8(s32 tile, s32 angle) {
#ifdef NONMATCHING_C
  s32 dir = ((angle + 0x20) >> 6) & 3;
  u8 height = TileAtIndex(tile)->heightStairs & 0xF;
  s32 ret = 0;

  switch (dir) {
    case 0: {
      while (TRUE) {
        s32 next = tile + 1;
        u8 stairs = TileAtIndex(next)->heightStairs;

        if (TileAtIndex(next)->attr & 0x80) {
          return (ret != 0) ? ret : tile;
        }
        if ((stairs & 0xF) != height) {
          if (ret != 0) {
            return ret;
          }
          next = tile;
        }
        ret = next;
        tile++;
      }
      break;
    }
    case 1: {
      while (TRUE) {
        s32 next = tile + gCollisionMap->tiledata->width;
        u8 stairs = TileAtIndex(next)->heightStairs;

        if (TileAtIndex(next)->attr & 0x80) {
          return (ret != 0) ? ret : tile;
        }
        if ((stairs & 0xF) != height) {
          if (ret != 0) {
            return ret;
          }
          next = tile;
        }
        ret = next;
        tile += gCollisionMap->tiledata->width;
      }
      break;
    }
    case 2: {
      while (TRUE) {
        s32 next = tile - 1;
        u8 stairs = TileAtIndex(next)->heightStairs;

        if (TileAtIndex(next)->attr & 0x80) {
          return (ret != 0) ? ret : tile;
        }
        if ((stairs & 0xF) != height) {
          if (ret != 0) {
            return ret;
          }
          next = tile;
        }
        ret = next;
        tile--;
      }
      break;
    }
    case 3: {
      while (TRUE) {
        s32 next = tile - gCollisionMap->tiledata->width;
        u8 stairs = TileAtIndex(next)->heightStairs;

        if (TileAtIndex(next)->attr & 0x80) {
          return (ret != 0) ? ret : tile;
        }
        if ((stairs & 0xF) != height) {
          if (ret != 0) {
            return ret;
          }
          next = tile;
        }
        ret = next;
        tile -= gCollisionMap->tiledata->width;
      }
      break;
    }
  }
  return tile;
#else
  INCFUNC("asm/func/FUN_080e09b8.inc");
#endif
}

// 414/414 命令まで届いたが, 引数のレジスタ割当と分岐後の比較の置き方が違う
NON_MATCH s32 FUN_080e0c28(Vec3* out, Vec3* a, Vec3* b, s32 mode, s32 param_5) {
#ifdef NONMATCHING_C
  s32 tileA;
  s32 tileB;
  s32 height;

  if (gCollisionMap == NULL) {
    return FALSE;
  }

  tileA = GetCollisionTileIdx(a);
  tileB = GetCollisionTileIdx(b);
  {
    MapTileOverride* ov = Map_FindTileOverride(tileA, 1);

    height = (ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileA])->heightStairs & 15;
  }
  if ((height << 8) != b->y) {
    return FALSE;
  }

  if (tileA == tileB) {
    *out = *b;
  } else {
    Vec3 pos;
    Vec3 diff;

    {
      MapTileOverride* ov;
      s32 col = Mod(tileA, gCollisionMap->tiledata->width);
      s32 row = Div(tileA, gCollisionMap->tiledata->width);

      pos.x = col * 256 + 128;
      ov = Map_FindTileOverride(tileA, 1);
      pos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileA])->heightStairs & 15) << 8;
      pos.z = row * 256 + 128;
    }
    Vec3_Diff(&diff, &pos, a);
    if (diff.x * diff.x + diff.z * diff.z != 0) {
      *out = pos;
    } else {
      s32 dirA;
      s32 dirB;
      s32 angle;
      s32 col;
      s32 row;
      s32 first;
      s32 result;

      Vec3_Diff(&pos, b, a);
      angle = ArcTan2_8(pos.x, pos.z);
      FUN_080e0588(tileA, tileB, &dirA, &dirB, angle);
      col = Mod(tileA, gCollisionMap->tiledata->width) - 5;
      row = Div(tileA, gCollisionMap->tiledata->width) - 8;
      if (mode == 0) {
        if (dirB != 0) {
          first = result = FUN_080e0748(col, row, tileA, height, dirB);
          if (first < 0) {
            result = FUN_080e0884(col, row, tileA, height, dirA);
          }
        } else {
          first = result = FUN_080e0884(col, row, tileA, height, dirA);
        }
      } else {
        if (dirA != 0) {
          first = result = FUN_080e0884(col, row, tileA, height, dirA);
          if (first < 0) {
            result = FUN_080e0748(col, row, tileA, height, dirB);
          }
        } else {
          first = result = FUN_080e0748(col, row, tileA, height, dirB);
        }
      }
      if (result < 0) {
        if (FUN_080e05f0(out, b, result, first) != -1) {
          return FALSE;
        }
      } else if (result == tileB) {
        if (param_5 == 1) {
          s32 tile = FUN_080e09b8(result, angle);

          {
            MapTileOverride* ov;
            s32 col = Mod(tile, gCollisionMap->tiledata->width);
            s32 row = Div(tile, gCollisionMap->tiledata->width);

            out->x = col * 256 + 128;
            ov = Map_FindTileOverride(tile, 1);
            out->y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 15) << 8;
            out->z = row * 256 + 128;
          }
          *b = *out;
        } else {
          *out = *b;
        }
      } else {
        {
          MapTileOverride* ov;
          s32 col = Mod(result, gCollisionMap->tiledata->width);
          s32 row = Div(result, gCollisionMap->tiledata->width);

          out->x = col * 256 + 128;
          ov = Map_FindTileOverride(result, 1);
          out->y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[result])->heightStairs & 15) << 8;
          out->z = row * 256 + 128;
        }
      }
    }
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080e0c28.inc");
#endif
}

// シングルトンのポインタをまとめて消す
void FUN_080e0fbc(void) {
  FlamethrowerManager_ClearGlobal();
  FlameManager_ClearGlobal();
  PitfallManager_ClearGlobal();
  LeverSwitchManager_ClearGlobal();
  EnemyManager_ClearGlobal();
  EmoteManager_Clear();
  DustManager_ClearGlobal();
  BloodEmitter_ClearGlobal();
  Cmd_ClearEnemyRespawnInfo();
  EnemyTargetManager_ClearGlobal();
  Entity081e9cac_ClearGlobal();
  OctorokManager_ClearGlobal();
  Entity081edcc4_ClearGlobal();
  FUN_081eb33c();
  BombManager_ClearGlobal();
  Entity081ee2a0_ClearGlobal();
  SpiderWebManager_ClearGlobal();
  Entity081d2180_ClearGlobal();
  PitfallWarningManager_ClearGlobal();
  Entity081eee80_ClearGlobal();
  FUN_080ddb1c();
  FUN_08241000();
  Entity081efa9c_ClearGlobal();
  FUN_080de168();
  Entity081f0298_ClearGlobal();
  Entity081f0b90_ClearGlobal();
  Entity081f1770_ClearGlobal();
  DebrisManager_ClearGlobal();
  Entity081f3324_ClearGlobal();
  ThunderboltManager_ClearGlobal();
  Entity081f53a8_ClearGlobal();
  FUN_081d6438();
  WormTail_ClearGlobal();
  Entity081f7974_ClearGlobal();
  Entity081f7de4_ClearGlobal();
  FUN_080df46c();
  TomahawkManager_ClearGlobal();
  FUN_081d81b8();
  FireballManager_ClearGlobal();
  OrbitalFlameManager_ClearGlobal();
  Entity081f9cb8_ClearInstance();
  LinkShopManager_ClearGlobal();
  LinkBattleLobby_ClearGlobal();
  LinkBattleCoinManager_ClearGlobal();
  Entity081fa164_ClearGlobal();
  LinkConnect_ClearGlobal();
  ClearLinkSession();
}

Enemy* FUN_080e1080(Vec3* pos, Vec3* size, u32* id) {
  s32 i = 0;
  Enemy* p;

  do {
    p = Enemy_GetNextActive(*id);
    if (p == NULL) {
      return NULL;
    }
    *id = p->mover.id;
    if (!Enemy_IsDead(p)) {
      if (pos->x <= p->mover.pos.x && pos->x + size->x >= p->mover.pos.x) {
        if (pos->z <= p->mover.pos.z && pos->z + size->z >= p->mover.pos.z) {
          return p;
        }
      }
    }
    i++;
  } while (i < 20);
  return NULL;
}

// 命令列は一致, 残差はレジスタ割当だけ (原典は i が r5, pos が sb, size が r6, id が r8)
NON_MATCH Enemy* FUN_080e1100(Vec3* pos, Vec3* size, u32* id) {
#ifdef NONMATCHING_C
  s32 i = 0;
  Enemy* p;

  do {
    p = Enemy_GetNextActive(*id);
    if (p == NULL) {
      return NULL;
    }
    if (!TEST_FLAGS(p->flags2, 0x400)) {
      *id = p->mover.id;
      if (!Enemy_IsDead(p)) {
        if (pos->x - size->x <= p->mover.pos.x && pos->x + size->x >= p->mover.pos.x) {
          if (pos->y - size->y <= p->mover.pos.y && pos->y + size->y >= p->mover.pos.y) {
            if (pos->z - size->z <= p->mover.pos.z && pos->z + size->z >= p->mover.pos.z) {
              return p;
            }
          }
        }
      }
    }
    i++;
  } while (i < 20);
  return NULL;
#else
  INCFUNC("asm/func/FUN_080e1100.inc");
#endif
}

Player* FUN_080e11a8(Vec3* pos, Vec3* size, s32 idx) {
  Player* player = gPlayerPtr[idx];

  if (player != NULL && !TEST_FLAGS(gPlayerModes[idx], PMODE_UNK_3) && TEST_FLAGS(player->flag20, PFLAG20_UPDATED)) {
    if (pos->x - size->x <= player->mover.pos.x && pos->x + size->x >= player->mover.pos.x) {
      if (pos->z - size->z <= player->mover.pos.z && pos->z + size->z >= player->mover.pos.z) {
        return player;
      }
    }
  }
  return NULL;
}

// 指定BGのタイルマップから (x, y) のエントリのアドレスを返す
static BgMapEntry* GetBgMapAddr(s32 bgIdx, s32 x, s32 y) {
  BgState* s = &gBgStates[bgIdx];
  BgMapEntry* map = s->tilemap;

  return map + (x & 31) + (y & 31) * 32;
}

// 指定BGのタイルマップの (x, y) から width × height を value で塗る
void FUN_080e1238(s32 x, s32 y, s32 width, s32 height, u32 value, s32 bgIdx) {
  s32 i;

  for (i = 0; i < height; i++) {
    BgMapEntry* dst = GetBgMapAddr(bgIdx, x, y + i);
    s32 j;

    for (j = 0; j < width; j++) {
      *dst = value;
      dst++;
    }
  }
}

// 0x8954
void Cmd_8954(void) {
  s16* count;
  s32 kills;

  count = &gStat->unk_948[0];
  *count = (*count < 9999) ? *count + 1 : 9999;
  count = &gStat->totalEnemyKillCount;
  *count = (*count < 9999) ? *count + 1 : 9999;
  count = &gStat->enemyKillCount[ENEF_24];
  *count = (*count < 9999) ? *count + 1 : 9999;
  kills = gStat->killCounts[4] + 1;
  if (kills > 9999) {
    kills = 9999;
  } else if (kills < 0) {
    kills = 0;
  }
  gStat->killCounts[4] = kills;
}
