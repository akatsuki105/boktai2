#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vec3.h"

// 不使用?

typedef struct {
  Mover mover;        // 0x00, id は 0x0309 + idx
  AuxSprite sprite;   // 0x44, mover の sprite に結びつけるが AuxSprite_Add されない
  Vec3 pos;           // 0x70, 毎フレーム vel を足してタイルの高さに合わせる
  Vec3 vel;           // 0x78
  HitboxData hitbox;  // 0x80
  s16 count;          // 0xD0, 動くたびに 1 減り, 0 になると状態 2 で片付く
  u8 kind;            // 0xD2, 2 なら hitbox の属性が変わり, 移動のたびに周りへ Entity081eee80_Spawn を8個出す
  u8 unk_d3;          // 0xD3
  u16 tileIdx;        // 0xD4, pos のタイル番号
  s8 idx;             // 0xD6, elems の添字, 空きは -1
  u8 state;           // 0xD7, PTR_ARRAY_085ae4bc の添字
  u16 timer;          // 0xD8, 0 になるまで動かない
} Entity081edcc4Elem;
static_assert(sizeof(Entity081edcc4Elem) == 220);

// 不使用?
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  Entity081edcc4Elem elems[2];  // 0x018
  u32 activeMask;               // 0x1D0, elems の使用中ビット
} Entity081edcc4;
static_assert(sizeof(Entity081edcc4) == 468);

static Entity081edcc4* gEntity081edcc4;  // 0x030001C8

s32 Entity081eb2f0_Spawn(Vec3* pos, u32 prio, u32 param_3);
s32 Entity081eee80_Spawn(Vec3* pos, s32 priority, s32 delay, s32 angle, s32 speed, s32 animShift, s32 plttOffset);
Entity081edcc4* Entity081edcc4_Create(void);

static inline bool8 Entity081edcc4_IsElemUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

// 4011/4145命令の下書き, 進めないときに曲がる向きを探す走査を8回展開して書いた, 原典は elem をスタックに置き走査ごとに幅や添字を別のレジスタとスタックに持つ
NON_MATCH static bool8 FUN_081eb348(Entity081edcc4Elem* elem, s32 angle, u32 tileIdx) {
#ifdef NONMATCHING_C
  s32 newDir;
  bool8 canMove;
  bool8 reached;

  if (elem->kind != 0) {
    // 向いている先のタイルへそのまま進めるか
    {
      u32 cur = elem->tileIdx;

      canMove = FALSE;
      switch (((angle + 0x20) >> 6) & 3) {
        case 0:
        case 2: {
          MapTileOverride* ov;
          CollisionMapTile* tile;

          ov = Map_FindTileOverride(cur, 1);
          tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[cur];
          if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
            canMove = TRUE;
            break;
          }
          ov = Map_FindTileOverride(tileIdx, 1);
          tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
          if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
            canMove = TRUE;
            break;
          }
          ov = Map_FindTileOverride(tileIdx, 1);
          tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
          if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
            break;
          }
          {
            MapTileOverride* ov = Map_FindTileOverride(tileIdx, 1);
            CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
            s32 stairs = tile->heightStairs >> 4;
            s32 height = (tile->heightStairs & 0xF) << 8;

            switch (stairs) {
              case STAIRS_VERTICAL: {
                height -= elem->pos.z & 0xFF;
                break;
              }
              case STAIRS_HORIZONTAL: {
                height -= elem->pos.x & 0xFF;
                break;
              }
            }
            canMove = height == elem->pos.y;
          }
          break;
        }
        case 1:
        case 3: {
          MapTileOverride* ov;
          CollisionMapTile* tile;

          ov = Map_FindTileOverride(cur, 1);
          tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[cur];
          if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
            canMove = TRUE;
            break;
          }
          ov = Map_FindTileOverride(tileIdx, 1);
          tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
          if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
            canMove = TRUE;
            break;
          }
          ov = Map_FindTileOverride(tileIdx, 1);
          tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
          if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
            break;
          }
          {
            MapTileOverride* ov = Map_FindTileOverride(tileIdx, 1);
            CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
            s32 stairs = tile->heightStairs >> 4;
            s32 height = (tile->heightStairs & 0xF) << 8;

            switch (stairs) {
              case STAIRS_VERTICAL: {
                height -= elem->pos.z & 0xFF;
                break;
              }
              case STAIRS_HORIZONTAL: {
                height -= elem->pos.x & 0xFF;
                break;
              }
            }
            canMove = height == elem->pos.y;
          }
          break;
        }
      }
    }
    if (canMove) {
      return FALSE;
    }
    // 進めないときは同じ高さで通れるタイルが続く横の向きへ曲がる, 通信中は向きと直交する2方向のうち先に見つかった方
    if (gGameFlags & GAMEFLAG_LINK) {
      s32 cur = elem->tileIdx;

      switch (((angle + 0x20) >> 6) & 3) {
        case 0:
        case 2: {
          reached = FALSE;
          {
            s32 to = cur - gCollisionMap->tiledata->width;
            s32 level = (s8)(elem->pos.y >> 8);
            s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
            s32 i;
            s32 col;

            if (cur < to) {
              i = cur + 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col < gCollisionMap->tiledata->width; col++) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i++;
              }
              if (!reached) {
                for (i = cur + gCollisionMap->tiledata->width; i < size; i += gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            } else {
              i = cur - 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col >= 0; col--) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i--;
              }
              if (!reached) {
                for (i = cur - gCollisionMap->tiledata->width; i >= 0; i -= gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            }
          }
          if (reached) {
            newDir = 3;
            break;
          }
          reached = FALSE;
          {
            s32 to = cur + gCollisionMap->tiledata->width;
            s32 level = (s8)(elem->pos.y >> 8);
            s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
            s32 i;
            s32 col;

            if (cur < to) {
              i = cur + 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col < gCollisionMap->tiledata->width; col++) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i++;
              }
              if (!reached) {
                for (i = cur + gCollisionMap->tiledata->width; i < size; i += gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            } else {
              i = cur - 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col >= 0; col--) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i--;
              }
              if (!reached) {
                for (i = cur - gCollisionMap->tiledata->width; i >= 0; i -= gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            }
          }
          if (!reached) {
            elem->state = 2;
            return TRUE;
          }
          newDir = 1;
          break;
        }
        case 1:
        case 3: {
          reached = FALSE;
          {
            s32 to = cur + 1;
            s32 level = (s8)(elem->pos.y >> 8);
            s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
            s32 i;
            s32 col;

            if (cur < to) {
              i = cur + 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col < gCollisionMap->tiledata->width; col++) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i++;
              }
              if (!reached) {
                for (i = cur + gCollisionMap->tiledata->width; i < size; i += gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            } else {
              i = cur - 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col >= 0; col--) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i--;
              }
              if (!reached) {
                for (i = cur - gCollisionMap->tiledata->width; i >= 0; i -= gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            }
          }
          if (reached) {
            newDir = 0;
            break;
          }
          reached = FALSE;
          {
            s32 to = cur - 1;
            s32 level = (s8)(elem->pos.y >> 8);
            s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
            s32 i;
            s32 col;

            if (cur < to) {
              i = cur + 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col < gCollisionMap->tiledata->width; col++) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i++;
              }
              if (!reached) {
                for (i = cur + gCollisionMap->tiledata->width; i < size; i += gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            } else {
              i = cur - 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col >= 0; col--) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i--;
              }
              if (!reached) {
                for (i = cur - gCollisionMap->tiledata->width; i >= 0; i -= gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            }
          }
          if (!reached) {
            elem->state = 2;
            return TRUE;
          }
          newDir = 2;
          break;
        }
        default: {
          elem->state = 2;
          return TRUE;
        }
      }
    } else {
      s32 cur = elem->tileIdx;
      s32 toPlayer;
      u8 ok[4];

      if (gPlayerPtr[0] == NULL) {
        toPlayer = 0;
      } else {
        Vec3 d;

        Vec3_Delta(&d, &elem->pos, &gPlayerPtr[0]->mover.pos);
        toPlayer = ((ArcTan2_8(d.x, d.z) + 0x20) & 0xFF) >> 6;
      }
      ClearMemory(ok, 4);
      switch (((angle + 0x20) >> 6) & 3) {
        case 0:
        case 2: {
          reached = FALSE;
          {
            s32 to = cur - gCollisionMap->tiledata->width;
            s32 level = (s8)(elem->pos.y >> 8);
            s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
            s32 i;
            s32 col;

            if (cur < to) {
              i = cur + 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col < gCollisionMap->tiledata->width; col++) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i++;
              }
              if (!reached) {
                for (i = cur + gCollisionMap->tiledata->width; i < size; i += gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            } else {
              i = cur - 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col >= 0; col--) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i--;
              }
              if (!reached) {
                for (i = cur - gCollisionMap->tiledata->width; i >= 0; i -= gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            }
          }
          if (reached) {
            ok[3] = TRUE;
          }
          reached = FALSE;
          {
            s32 to = cur + gCollisionMap->tiledata->width;
            s32 level = (s8)(elem->pos.y >> 8);
            s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
            s32 i;
            s32 col;

            if (cur < to) {
              i = cur + 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col < gCollisionMap->tiledata->width; col++) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i++;
              }
              if (!reached) {
                for (i = cur + gCollisionMap->tiledata->width; i < size; i += gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            } else {
              i = cur - 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col >= 0; col--) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i--;
              }
              if (!reached) {
                for (i = cur - gCollisionMap->tiledata->width; i >= 0; i -= gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            }
          }
          if (reached) {
            ok[1] = TRUE;
          }
          break;
        }
        case 1:
        case 3: {
          reached = FALSE;
          {
            s32 to = cur + 1;
            s32 level = (s8)(elem->pos.y >> 8);
            s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
            s32 i;
            s32 col;

            if (cur < to) {
              i = cur + 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col < gCollisionMap->tiledata->width; col++) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i++;
              }
              if (!reached) {
                for (i = cur + gCollisionMap->tiledata->width; i < size; i += gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            } else {
              i = cur - 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col >= 0; col--) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i--;
              }
              if (!reached) {
                for (i = cur - gCollisionMap->tiledata->width; i >= 0; i -= gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            }
          }
          if (reached) {
            ok[0] = TRUE;
          }
          reached = FALSE;
          {
            s32 to = cur - 1;
            s32 level = (s8)(elem->pos.y >> 8);
            s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
            s32 i;
            s32 col;

            if (cur < to) {
              i = cur + 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col < gCollisionMap->tiledata->width; col++) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i++;
              }
              if (!reached) {
                for (i = cur + gCollisionMap->tiledata->width; i < size; i += gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            } else {
              i = cur - 1;
              for (col = Mod(i, gCollisionMap->tiledata->width); col >= 0; col--) {
                MapTileOverride* ov;
                CollisionMapTile* tile;

                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs & 0xF) != level) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                  break;
                }
                ov = Map_FindTileOverride(i, 1);
                tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
                  {
                    MapTileOverride* ov = Map_FindTileOverride(i, 1);
                    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                    s32 stairs = tile->heightStairs >> 4;
                    s32 height = (tile->heightStairs & 0xF) << 8;

                    switch (stairs) {
                      case STAIRS_VERTICAL: {
                        height -= elem->pos.z & 0xFF;
                        break;
                      }
                      case STAIRS_HORIZONTAL: {
                        height -= elem->pos.x & 0xFF;
                        break;
                      }
                    }
                    elem->pos.y = height;
                  }
                  reached = TRUE;
                  break;
                }
                if (i == to) {
                  reached = TRUE;
                  break;
                }
                i--;
              }
              if (!reached) {
                for (i = cur - gCollisionMap->tiledata->width; i >= 0; i -= gCollisionMap->tiledata->width) {
                  MapTileOverride* ov;
                  CollisionMapTile* tile;

                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs & 0xF) != level) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
                    break;
                  }
                  ov = Map_FindTileOverride(i, 1);
                  tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                  if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
                    {
                      MapTileOverride* ov = Map_FindTileOverride(i, 1);
                      CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[i];
                      s32 stairs = tile->heightStairs >> 4;
                      s32 height = (tile->heightStairs & 0xF) << 8;

                      switch (stairs) {
                        case STAIRS_VERTICAL: {
                          height -= elem->pos.z & 0xFF;
                          break;
                        }
                        case STAIRS_HORIZONTAL: {
                          height -= elem->pos.x & 0xFF;
                          break;
                        }
                      }
                      elem->pos.y = height;
                    }
                    reached = TRUE;
                    break;
                  }
                  if (i == to) {
                    reached = TRUE;
                    break;
                  }
                }
              }
            }
          }
          if (reached) {
            ok[2] = TRUE;
          }
          break;
        }
      }
      // プレイヤーの方へ曲がれるならそちらを, だめなら曲がれる向きの若い方を選ぶ
      if (ok[toPlayer] == TRUE) {
        newDir = toPlayer;
      } else {
        s32 i;

        newDir = -1;
        for (i = 0; i < 4; i++) {
          if (ok[i]) {
            newDir = i;
            break;
          }
        }
      }
      if (newDir < 0) {
        elem->state = 2;
        return TRUE;
      }
    }
    {
      s32 vx = abs(elem->vel.x);
      s32 vz = abs(elem->vel.z);
      s32 speed = vz;
      if (speed < vx) {
        speed = vx;
      }
      switch (newDir) {
        case 0: {
          elem->vel.x = speed;
          elem->vel.z = 0;
          break;
        }
        case 1: {
          elem->vel.x = 0;
          elem->vel.z = speed;
          break;
        }
        case 2: {
          elem->vel.x = -speed;
          elem->vel.z = 0;
          break;
        }
        case 3: {
          elem->vel.x = 0;
          elem->vel.z = -speed;
          break;
        }
      }
    }
    return TRUE;
  }
  {
    u32 cur = elem->tileIdx;

    canMove = FALSE;
    switch (((angle + 0x20) >> 6) & 3) {
      case 0:
      case 2: {
        MapTileOverride* ov;
        CollisionMapTile* tile;

        ov = Map_FindTileOverride(cur, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[cur];
        if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
          canMove = TRUE;
          break;
        }
        ov = Map_FindTileOverride(tileIdx, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
        if ((tile->heightStairs >> 4) == STAIRS_HORIZONTAL) {
          canMove = TRUE;
          break;
        }
        ov = Map_FindTileOverride(tileIdx, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
        if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
          break;
        }
        {
          MapTileOverride* ov = Map_FindTileOverride(tileIdx, 1);
          CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
          s32 stairs = tile->heightStairs >> 4;
          s32 height = (tile->heightStairs & 0xF) << 8;

          switch (stairs) {
            case STAIRS_VERTICAL: {
              height -= elem->pos.z & 0xFF;
              break;
            }
            case STAIRS_HORIZONTAL: {
              height -= elem->pos.x & 0xFF;
              break;
            }
          }
          canMove = height == elem->pos.y;
        }
        break;
      }
      case 1:
      case 3: {
        MapTileOverride* ov;
        CollisionMapTile* tile;

        ov = Map_FindTileOverride(cur, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[cur];
        if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
          canMove = TRUE;
          break;
        }
        ov = Map_FindTileOverride(tileIdx, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
        if ((tile->heightStairs >> 4) == STAIRS_VERTICAL) {
          canMove = TRUE;
          break;
        }
        ov = Map_FindTileOverride(tileIdx, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
        if (tile->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) {
          break;
        }
        {
          MapTileOverride* ov = Map_FindTileOverride(tileIdx, 1);
          CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
          s32 stairs = tile->heightStairs >> 4;
          s32 height = (tile->heightStairs & 0xF) << 8;

          switch (stairs) {
            case STAIRS_VERTICAL: {
              height -= elem->pos.z & 0xFF;
              break;
            }
            case STAIRS_HORIZONTAL: {
              height -= elem->pos.x & 0xFF;
              break;
            }
          }
          canMove = height == elem->pos.y;
        }
        break;
      }
    }
  }
  if (canMove) {
    return FALSE;
  }
  elem->state = 2;
  return TRUE;
#else
  INCFUNC("asm/func/FUN_081eb348.inc");
#endif
}

static void Entity081edcc4Elem_OnHit(HitboxData* a, HitboxData* b, Entity081edcc4Elem* elem) {}

// from と to が離れていれば中間点に Entity081eb2f0_Spawn で置けるかを確かめる
static bool8 Entity081edcc4_CanReach(Vec3* from, Vec3* to, u32 param_3) {
  Vec3 d;

  Vec3_Delta(&d, from, to);
  if (d.x * d.x + d.z * d.z > 0x3FF) {
    d.x = from->x + Div(d.x, 2);
    d.y = from->y;
    d.z = from->z + Div(d.z, 2);
    if (Entity081eb2f0_Spawn(&d, 2, param_3) < 0) {
      goto blocked;
    }
  }
  return TRUE;
blocked:
  return FALSE;
}

static void Entity081edcc4Elem_UpdateState0(Entity081edcc4* p, Entity081edcc4Elem* elem) {}

// 417/386命令の下書き, 移動前のタイル番号で高さを引く部分と pos の各成分を指すポインタの持ち方が原典と違う
NON_MATCH static void Entity081edcc4Elem_UpdateState1(Entity081edcc4* p, Entity081edcc4Elem* elem) {
#ifdef NONMATCHING_C
  s32 angle;
  Vec3 spot;
  Vec3 prev;
  u32 tileIdx;
  s32 i;

  if (elem->unk_d3) {
    elem->unk_d3 = 0;
  }
  if (elem->timer != 0) {
    elem->timer--;
    return;
  }
  elem->tileIdx = GetCollisionTileIdx(&elem->pos);
  angle = ArcTan2_8(elem->vel.x, elem->vel.z);
  prev = elem->pos;
  elem->pos.x += elem->vel.x;
  {
    u32 idx = elem->tileIdx;
    MapTileOverride* ov = Map_FindTileOverride(idx, 1);
    CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
    s32 stairs = tile->heightStairs >> 4;
    s32 height = (tile->heightStairs & 0xF) << 8;

    switch (stairs) {
      case STAIRS_VERTICAL: {
        height -= elem->pos.z & 0xFF;
        break;
      }
      case STAIRS_HORIZONTAL: {
        height -= elem->pos.x & 0xFF;
        break;
      }
    }
    elem->pos.y = height;
  }
  elem->pos.z += elem->vel.z;
  tileIdx = GetCollisionTileIdx(&elem->pos);
  Hitbox_SetPos(&elem->hitbox, &elem->pos, 0);
  Hitbox_Register(&elem->hitbox);
  if (FUN_081eb348(elem, angle, tileIdx)) {
    elem->pos = prev;
  } else {
    elem->pos.y = TileHeightAt(&elem->pos);
  }
  elem->mover.pos = elem->pos;
  spot.x = elem->pos.x;
  spot.y = elem->pos.y;
  spot.z = elem->pos.z;
  switch (angle >> 6) {
    case 0:
    case 2: {
      spot.z = spot.z - 60 + Mod(Random(), 120);
      break;
    }
    case 1:
    case 3: {
      spot.x = spot.x - 60 + Mod(Random(), 120);
      break;
    }
  }
  if (elem->kind == 2) {
    for (i = 0; i < 4; i++) {
      Entity081eee80_Spawn(&spot, 1, 0, i << 6, 0x54, 1, 0);
    }
    for (i = 0; i < 2; i++) {
      Entity081eee80_Spawn(&spot, 1, 8, i << 6, 0x22, 1, 0);
      Entity081eee80_Spawn(&spot, 1, 14, i << 6, 0x40, 1, 0);
    }
    elem->timer = 8;
  } else {
    if (Entity081eb2f0_Spawn(&spot, 2, elem->kind) < 0 || !Entity081edcc4_CanReach(&prev, &spot, elem->kind)) {
      elem->state = 2;
      return;
    }
    elem->timer = (Random() & 7) + 3;
  }
  if (elem->count == 0) {
    elem->state = 2;
    return;
  }
  elem->count--;
  if (elem->kind != 2) {
    PlaySound_082406e0(SONG_482);
  }
#else
  INCFUNC("asm/func/Entity081edcc4Elem_UpdateState1.inc");
#endif
}

static void Entity081edcc4Elem_UpdateState2(Entity081edcc4* p, Entity081edcc4Elem* elem) {
  elem->state = 0;
  CLEAR_BIT(p->activeMask, elem->idx);
  FUN_08002a58(&elem->mover);
  Mover_Unlink(&elem->mover);
  ClearMemory(elem, sizeof(Entity081edcc4Elem));
  elem->idx = -1;
}

Entity081edcc4Elem* Entity081edcc4_AllocElem(Entity081edcc4* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    if (!Entity081edcc4_IsElemUsed(&p->activeMask, i)) {
      Entity081edcc4Elem* elem = &p->elems[i];

      elem->idx = i;
      p->activeMask |= 1 << i;
      return elem;
    }
  }
  return NULL;
}

// 152/152命令, Hitbox_Init の flags 0x2001 を原典はスタック引数を積んだ後に読むが, こちらは先に読む
NON_MATCH s32 Entity081edcc4_Spawn(Vec3* pos, Vec3* vel, u32 count, u32 kind, s32 power, s32 knockback, s32 iframes) {
#ifdef NONMATCHING_C
  Entity081edcc4* p;
  Entity081edcc4Elem* elem;
  HitboxData* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  if (pos == NULL) {
    return -1;
  }
  p = gEntity081edcc4;
  if (p == NULL) {
    p = Entity081edcc4_Create();
    if (p == NULL) {
      return -1;
    }
  }
  elem = Entity081edcc4_AllocElem(p);
  if (elem == NULL) {
    return -1;
  }
  elem->pos = *pos;
  elem->vel = *vel;
  elem->count = count;
  elem->kind = kind;
  elem->timer = 0;
  elem->state = 1;
  hitbox = &elem->hitbox;
  VEC3_SET(halfSize, 64, 64, 64);
  VEC3_SET(offset, 0, 64, 0);
  if (elem->kind == 2) {
    Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0, &halfSize, &offset);
    Hitbox_SetAttack(hitbox, power, knockback, 0x40, HBATTR_INKA | HBATTR_18 | HBATTR_FLAME, iframes);
  } else {
    Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
    Hitbox_SetAttack(hitbox, power, knockback, 0x10, 0, iframes);
  }
  hitbox->id = elem->mover.id;
  Hitbox_SetPos(hitbox, &elem->pos, 0);
  Hitbox_SetHandler(hitbox, Entity081edcc4Elem_OnHit, elem);
  Mover_Init(&elem->mover, 0x0309 + elem->idx, &elem->pos, 0, 7, elem);
  Mover_SetAuxSprite(&elem->mover, &elem->sprite);
  FUN_08002a48(&elem->mover);
  return 0;
#else
  INCFUNC("asm/func/Entity081edcc4_Spawn.inc");
#endif
}

static s32 Entity081edcc4_Update(Entity081edcc4* p) {
  static void (*const PTR_ARRAY_085ae4bc[3])(Entity081edcc4*, Entity081edcc4Elem*) = {
      Entity081edcc4Elem_UpdateState0,
      Entity081edcc4Elem_UpdateState1,
      Entity081edcc4Elem_UpdateState2,
  };  // 0x085AE4BC

  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 2; i++) {
    if (Entity081edcc4_IsElemUsed(&p->activeMask, i)) {
      Entity081edcc4Elem* elem = &p->elems[i];

      PTR_ARRAY_085ae4bc[elem->state](p, elem);
    }
  }
  return 0;
}

static s32 Entity081edcc4_Destroy(Entity081edcc4* p) {
  gEntity081edcc4 = NULL;
  return 0;
}

static s32 Entity081edcc4_Init(Entity081edcc4* p) {
  gEntity081edcc4 = p;
  return 0;
}

Entity081edcc4* Entity081edcc4_Create(void) {
  Entity081edcc4* p;

  if (gEntity081edcc4 != NULL) {
    return gEntity081edcc4;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081edcc4));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081edcc4_Update, Entity081edcc4_Destroy);
    if (Entity081edcc4_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081edcc4_ClearGlobal(void) { gEntity081edcc4 = NULL; }
