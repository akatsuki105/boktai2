#include "collision_map.h"
#include "enemy.h"
#include "entity.h"
#include "flamethrower.h"
#include "global.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"

void Entity081e9cac_ClearGlobal(void);
void Entity081ea820_ClearGlobal(void);
void Entity081edcc4_ClearGlobal(void);
void Entity081ee2a0_ClearGlobal(void);
void Entity081eeb28_ClearGlobal(void);
void FUN_081eeecc(void);
void FUN_081f02e4(void);
void Entity081f0b90_ClearGlobal(void);
void FUN_081f17bc(void);
void FUN_081f3370(void);
void FUN_081f45a0(void);
void FUN_081f7438(void);
void FUN_081f79c0(void);
void FUN_081f7e30(void);
void FUN_081f8a74(void);
void FUN_081f95e8(void);
void FUN_081dc688(void);
void Entity081fa164_ClearGlobal(void);
void FUN_081eafb0(void);
void Entity081d0e20_ClearGlobal(void);
void FUN_081d1738(void);
void FUN_080eeb08(void);
void EmoteManager_Clear(void);
void FUN_080dbea4(void);
void FUN_080dc498(void);
void Cmd_300F(void);
void EnemyTargetManager_ClearGlobal(void);
void FUN_081eb33c(void);
void FUN_080dd244(void);
void FUN_080db56c(void);
void FUN_081d21cc(void);
void FUN_080ddb1c(void);
void FUN_08241000(void);
void FUN_081efae8(void);
void FUN_080de168(void);
void FUN_081f2708(void);
void FUN_081f53f4(void);
void FUN_081d6438(void);
void FUN_080df46c(void);
void Entity080e01bc_ClearGlobal(void);
void FUN_081d81b8(void);
void Entity081f9cb8_ClearInstance(void);
void LinkShopManager_ClearGlobal(void);
void FUN_081e0c14(void);
void LinkConnect_ClearGlobal(void);
void ClearEntity9A9F(void);

// スクリプトから積まれた生成要求1件, 生成物が死ぬと Entity778B_Update が同じ設定で作り直す
typedef struct {
  Vec3 pos;               // 0x00, '.p'
  Vec3 unk_08;            // 0x08, '.a'
  s16 unk_10;             // 0x10, '.f[1]'..'.f[2]' の乱数, 太陽ゲージが満たないときは (10 - sunGauge) / 10 倍される
  s16 unk_12;             // 0x12, '.t', 同じく太陽ゲージで減る
  u16 unk_14;             // 0x14, '.n'
  u16 unk_16;             // 0x16, 0 で固定
  u8 unk_18;              // 0x18, '.d'
  u8 unk_19;              // 0x19, '.f[0]'
  u16 slotIdx;            // 0x1A, usedMask 上の自分のビット番号
  Flamethrower* spawned;  // 0x1C, 生成物, unk_136 が負 (解放済み) になったら作り直す
} Entity778BElem;
static_assert(sizeof(Entity778BElem) == 32);

// 生成要求を12件まで抱えるシングルトン, ゲームオーバー中と gPlayerStates の FLAG03002BC0_UNK_2 が立っている間は止まる
typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_10
  Entity778BElem elems[12];  // 0x018
  u32 usedMask;              // 0x198, elems のどのスロットが使用中かのビットマスク
} Entity778B;
static_assert(sizeof(Entity778B) == 412);

IWRAM_DATA Entity778B* gEntity778B = NULL;  // 0x03000180

static inline bool8 Entity778B_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081eaf6c_Create(void);
void Entity778B_ClearGlobal(void);
Enemy* FUN_080edce8(u32 id);
Flamethrower* FUN_081ead54(Entity778BElem* elem, u32 id, s32 unk_12, s32 unk_18, s32 unk_19, s32 param_6, s32 x, s32 y, s32 z, s32 unk_10, s32 unk_16);

// 通信中以外は太陽ゲージが満たないぶんだけ減らす
static inline s32 Entity778B_ScaleBySun(s32 value) {
  if (gGameFlags & FLAG030047A4_LINK) {
    return value;
  }
  return Div(value * (10 - gStat->sunGauge), 10);
}

static inline void Entity778BElem_Spawn(Entity778BElem* elem) {
  s32 unk_12 = Entity778B_ScaleBySun(elem->unk_12);
  s32 unk_10 = Entity778B_ScaleBySun(elem->unk_10);

  elem->spawned = FUN_081ead54(elem, elem->unk_14, unk_12, elem->unk_18, elem->unk_19, -1, elem->unk_08.x, elem->unk_08.y, elem->unk_08.z, unk_10, elem->unk_16);
}

static inline CollisionMapTile* Entity778B_GetTile(s32 tileIdx) {
  MapTileOverride* ov = Map_FindTileOverride(tileIdx, 1);

  return (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
}

// tileIdx のタイルの中央の座標を pos に入れる
static inline void Entity778B_SetPosFromTile(Vec3* pos, s32 tileIdx) {
  s32 x = Mod(tileIdx, gCollisionMap->tiledata->width);
  s32 z = Div(tileIdx, gCollisionMap->tiledata->width);

  pos->x = x * 256 + 128;
  pos->y = (Entity778B_GetTile(tileIdx)->heightStairs & 0xF) << 8;
  pos->z = z * 256 + 128;
}

const u8 u8_ARRAY_085ad374[80] = {
    0, 0, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0,
};  // 0x085AD374

// 命令数は一致, 残差はレジスタ割当だけ (range が r5)
NON_MATCH s32 FUN_080e0404(Vec3* out, s32 param_2, Vec3* base, s32 range) {
#ifdef NONMATCHING_C
  s32 tile = GetCollisionTileIdx(base);
  s32 x = Mod(tile, gCollisionMap->tiledata->width);
  s32 z = Div(tile, gCollisionMap->tiledata->width);
  s32 height = Entity778B_GetTile(tile)->heightStairs & 0xF;
  s32 n = range * 2 + 1;
  s32 tx = Mod(Random(), n) + (x - range);
  s32 tz = Mod(Random(), n) + (z - range);

  if ((s8)u8_ARRAY_085ad374[tx - 5 + (tz - 8) * 8] == height) {
    Entity778B_SetPosFromTile(out, tx + gCollisionMap->tiledata->width * tz);
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
      s32 tile = gCollisionMap->tiledata->width * 12 + 10;

      if (tile < 0) {
        tile = -tile;
      }
      Entity778B_SetPosFromTile(fallback, tile);
    } else {
      if (tile1 < 0) {
        tile1 = -tile1;
      }
      Entity778B_SetPosFromTile(pos, tile1);
      return 1;
    }
  } else {
    if (tile2 < 0) {
      tile2 = -tile2;
    }
    Entity778B_SetPosFromTile(pos, tile2);
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
  u8 height = Entity778B_GetTile(tile)->heightStairs & 0xF;
  s32 ret = 0;

  switch (dir) {
    case 0: {
      while (TRUE) {
        s32 next = tile + 1;
        u8 stairs = Entity778B_GetTile(next)->heightStairs;

        if (Entity778B_GetTile(next)->attr & 0x80) {
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
        u8 stairs = Entity778B_GetTile(next)->heightStairs;

        if (Entity778B_GetTile(next)->attr & 0x80) {
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
        u8 stairs = Entity778B_GetTile(next)->heightStairs;

        if (Entity778B_GetTile(next)->attr & 0x80) {
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
        u8 stairs = Entity778B_GetTile(next)->heightStairs;

        if (Entity778B_GetTile(next)->attr & 0x80) {
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
  Entity778B_ClearGlobal();
  FUN_081eafb0();
  Entity081d0e20_ClearGlobal();
  FUN_081d1738();
  FUN_080eeb08();
  EmoteManager_Clear();
  FUN_080dbea4();
  FUN_080dc498();
  Cmd_300F();
  EnemyTargetManager_ClearGlobal();
  Entity081e9cac_ClearGlobal();
  Entity081ea820_ClearGlobal();
  Entity081edcc4_ClearGlobal();
  FUN_081eb33c();
  FUN_080dd244();
  Entity081ee2a0_ClearGlobal();
  FUN_080db56c();
  FUN_081d21cc();
  Entity081eeb28_ClearGlobal();
  FUN_081eeecc();
  FUN_080ddb1c();
  FUN_08241000();
  FUN_081efae8();
  FUN_080de168();
  FUN_081f02e4();
  Entity081f0b90_ClearGlobal();
  FUN_081f17bc();
  FUN_081f2708();
  FUN_081f3370();
  FUN_081f45a0();
  FUN_081f53f4();
  FUN_081d6438();
  FUN_081f7438();
  FUN_081f79c0();
  FUN_081f7e30();
  FUN_080df46c();
  Entity080e01bc_ClearGlobal();
  FUN_081d81b8();
  FUN_081f8a74();
  FUN_081f95e8();
  Entity081f9cb8_ClearInstance();
  LinkShopManager_ClearGlobal();
  FUN_081dc688();
  FUN_081e0c14();
  Entity081fa164_ClearGlobal();
  LinkConnect_ClearGlobal();
  ClearEntity9A9F();
}

Enemy* FUN_080e1080(Vec3* pos, Vec3* size, u32* id) {
  s32 i = 0;
  Enemy* p;

  do {
    p = FUN_080edce8(*id);
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
    p = FUN_080edce8(*id);
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

  if (player != NULL && !TEST_FLAGS(gPlayerStates[idx], 8) && TEST_FLAGS(player->flag20, PFLAG20_UNK_14)) {
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
  count = (s16*)&gStat->unk_222;
  *count = (*count < 9999) ? *count + 1 : 9999;
  kills = gStat->killCounts[4] + 1;
  if (kills > 9999) {
    kills = 9999;
  } else if (kills < 0) {
    kills = 0;
  }
  gStat->killCounts[4] = kills;
}

// 原典は usedMask をループ外で読み, return 値を i << 5 から作り直す, Tier A のみ試済
NON_MATCH Entity778BElem* FUN_080e1334(u32 id) {
#ifdef NONMATCHING_C
  Entity778B* p = gEntity778B;

  if (p != NULL) {
    s32 i;

    for (i = 0; i < 12; i++) {
      if (Entity778B_IsActive(&p->usedMask, i)) {
        if (p->elems[i].unk_14 == id) {
          return &p->elems[i];
        }
      }
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_080e1334.inc");
#endif
}

// 空いている枠を確保して返す, 無ければ NULL
Entity778BElem* Entity778B_AllocElem(Entity778B* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Entity778B_IsActive(&p->usedMask, i)) {
      p->usedMask |= 1 << i;
      p->elems[i].slotIdx = i;
      return &p->elems[i];
    }
  }
  return NULL;
}

s32 Entity778B_Update(Entity778B* p) {
  Entity778BElem* elems = p->elems;

  if (p->usedMask != 0 && !TEST_FLAGS((gGameFlags | gDebugGameFlags), FLAG030047A4_GAMEOVER) && !TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    Entity778BElem* elem = elems;
    s32 i;

    for (i = 0; i < 12; i++) {
      if (elem->spawned != NULL && (s16)elem->spawned->unk_136 < 0) {
        Entity778BElem_Spawn(elem);
      }
      elem++;
    }
  }
  return 0;
}

s32 Entity778B_Destroy(Entity778B* p) {
  gEntity778B = NULL;
  return 0;
}

s32 Entity778B_Init(Entity778B* p, s32 unused) {
  Entity081eaf6c_Create();
  gEntity778B = p;
  return 0;
}

// 0x778B
Entity778B* Entity778B_Create(s32 param_1) {
  if (gEntity778B == NULL) {
    Entity778B* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity778B));

    if (p != NULL) {
      SetEntityRoutine(p, Entity778B_Update, Entity778B_Destroy);
      if (Entity778B_Init(p, param_1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity778B;
}

// 命令列は一致, 残差はレジスタだけ (原典は 0x942 を r6 に載せ, オフセットの定数を r3 に置く)
NON_MATCH void Entity778B_AddElemScripted(void) {
#ifdef NONMATCHING_C
  Entity778BElem* elem;

  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), FLAG030047A4_GAMEOVER) || gEntity778B == NULL) {
    return;
  }
  elem = Entity778B_AllocElem(gEntity778B);
  if (elem == NULL) {
    return;
  }
  if (VM_SeekToNamedArg('p')) {
    elem->pos.x = VM_GetValue();
    elem->pos.y = VM_GetValue();
    elem->pos.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('a')) {
    elem->unk_08.x = VM_GetValue();
    elem->unk_08.y = VM_GetValue();
    elem->unk_08.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('f')) {
    s32 min;
    s32 range;

    elem->unk_19 = VM_GetValue();
    min = VM_GetValue();
    range = VM_GetValue() - min;
    if (range == 0) {
      elem->unk_10 = 0;
    } else {
      elem->unk_10 = min + Mod(Random(), range);
    }
  }
  elem->unk_14 = VM_GetNamedArgValue('n', 0);
  elem->unk_18 = VM_GetNamedArgValue('d', 0);
  elem->unk_12 = VM_GetNamedArgValue('t', 0);
  elem->unk_16 = 0;
  if (VM_GetNamedArgValue('s', 0)) {
    elem->unk_16 = 1;
  }
  Entity778BElem_Spawn(elem);
#else
  INCFUNC("asm/func/Entity778B_AddElemScripted.inc");
#endif
}

void Entity778B_ClearGlobal(void) { gEntity778B = NULL; }

// '.n' で指された生成要求を使用中マスクから外して消す
void Cmd_9700(void) {
  Entity778B* p = gEntity778B;
  Entity778BElem* e;
  s32 id;
  s32 slot;

  if (p == NULL) {
    return;
  }
  id = VM_GetNamedArgValue('n', -1);
  if (id < 0) {
    return;
  }

  e = FUN_080e1334(id);
  if (e == NULL) {
    return;
  }

  slot = (s16)e->slotIdx;
  p->usedMask &= ~(1 << slot);
  ClearMemory(e, sizeof(Entity778BElem));
}
