#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "player.h"
#include "vm.h"

// bit0/bit1 で fn を選び、bit3 で x/z のどちらを見るかが変わる
typedef enum {
  FLAG_0 = (1 << 0),  // updateCallback: FUN_080a01d8
  FLAG_1 = (1 << 1),
  FLAG_2 = (1 << 2),
  AXIS_X = (1 << 3),
  AXIS_Z = (1 << 4),
  FLAG_5 = (1 << 5),
  FLAG_6 = (1 << 6),
  FLAG_7 = (1 << 7),
} Entity71BAFlags;

// 条件 (プレイヤーのタイル位置・高さ・フォーム) が揃っている間だけ、あるタイルの当たり判定を上書きする
// 小さな穴(PLAYER_MOUSE, GOOD_MINI のときのみ通れる穴) や 小さな窓(PLAYER_BAT のときのみ通れる穴), 太陽床 とかを扱う?
typedef struct Entity71BA {
  Entity e;                                    // 0x00, ENTITY_UNK_8
  u16 id;                                      // 0x18
  u8 _[2];                                     // 0x1A, padding
  u8 flags;                                    // 0x1C, '.t=9', see Entity71BAFlags
  bool8 tileOverrideActive;                    // 0x1D, tileOverride を衝突マップに繋いであるか, _Destroy が立っていれば Map_RemoveTileOverride で外す
  u16 tileIdx;                                 // 0x1E, gCollisionMap->rowOffsets[z] + x, '.p' の x/z から _Init が計算する
  u16 height;                                  // 0x20, '.p[1]' (>> 8 した値)
  bool16 unk_22;                               // 0x22, FUN_080a035c が 0/1 を入れ替えるたび gPlayerPtr[0]->wallLockCount を +1/-1 する
  MapTileOverride tileOverride;                // 0x24
  u32 scriptID;                                // 0x34, '.R'
  void (*updateCallback)(struct Entity71BA*);  // 0x38
} Entity71BA;
static_assert(sizeof(Entity71BA) == 60);

void Player_EnterLanding(Player* p);

static inline bool32 Entity71BA_IsPlayerMini(void) {
  u16 timer = gGoodCondTimer;

  return timer != 0 && gGoodCondID == GOOD_MINI;
}

bool32 Entity71BA_IsPlayerOnTile(Entity71BA* p) {
  if (GetCollisionTileIdx(&gPlayerPtr[0]->mover.pos) == p->tileIdx) {
    return TRUE;
  }
  return FALSE;
}

bool32 Entity71BA_IsPlayerAtHeight(Entity71BA* p) {
  if (gPlayerPtr[0]->mover.pos.y == p->height << 8) {
    return TRUE;
  }
  return FALSE;
}

// 残差は AND の結果を置くレジスタだけ (原典はマスク側, こちらは値側), Tier A-C は試済
NON_MATCH bool32 Entity71BA_IsPlayerWithinTileOffset(Entity71BA* p, s32 param_2) {
#ifdef NONMATCHING_C
  u16 v;

  if (p->flags & AXIS_X) {
    v = gPlayerPtr[0]->mover.pos.x;
  } else {
    v = gPlayerPtr[0]->mover.pos.z;
  }
  if ((v & 0xFF) <= param_2) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Entity71BA_IsPlayerWithinTileOffset.inc");
#endif
}

s32 FUN_080a0140(Entity71BA* p) {
  if (gPlayerPtr[0]->action == PACT_WALL) {
    Dir8U8 dir = gPlayerPtr[0]->actionDir;

    if (dir == DIR8_UP_RIGHT && (p->flags & AXIS_Z)) {
      return TRUE;
    }
    if (dir == DIR8_UP_LEFT && (p->flags & AXIS_X)) {
      return TRUE;
    }
    return FALSE;
  }
  if (gPlayerPtr[0]->kind == PLAYER_BAT) {
    return TRUE;
  }
  if (Entity71BA_IsPlayerMini() || gPlayerPtr[0]->kind == PLAYER_MOUSE) {
    if (Entity71BA_IsPlayerWithinTileOffset(p, Q8(0.16))) {
      return TRUE;
    }
  }
  return FALSE;
}

// FLAG_0
void FUN_080a01d8(Entity71BA* p) {
  if (Entity71BA_IsPlayerAtHeight(p)) {
    if (Entity71BA_IsPlayerOnTile(p) && !FUN_080a0140(p)) {
      if (p->tileOverrideActive) {
        Map_RemoveTileOverride(&p->tileOverride);
        p->tileOverrideActive = FALSE;
        Player_EnterLanding(gPlayerPtr[0]);
        if (p->scriptID != 0) {
          VM_ExecByID(p->scriptID, NULL);
        }
      }
    } else if (!p->tileOverrideActive) {
      Map_AddTileOverride(&p->tileOverride, p->tileIdx, 0, p->height, 0xFF, TATTR_UNK_11 | TATTR_UNK_5 | TATTR_UNK_3 | TATTR_WALL);
      p->tileOverrideActive = TRUE;
    }
  } else if (p->tileOverrideActive) {
    Map_RemoveTileOverride(&p->tileOverride);
    p->tileOverrideActive = FALSE;
  }
}

s32 FUN_080a0268(Entity71BA* p) {
  if (gPlayerPtr[0]->action == PACT_WALL) {
    u8 dir = gPlayerPtr[0]->actionDir;

    if (dir == DIR8_UP_RIGHT && (p->flags & AXIS_Z)) {
      return TRUE;
    }
    if (dir == DIR8_UP_LEFT && (p->flags & AXIS_X)) {
      return TRUE;
    }
    return FALSE;
  }
  if (Entity71BA_IsPlayerMini() || gPlayerPtr[0]->kind == PLAYER_BAT || gPlayerPtr[0]->kind == PLAYER_MOUSE) {
    if (Entity71BA_IsPlayerWithinTileOffset(p, Q8(0.16))) {
      return TRUE;
    }
  }
  return FALSE;
}

void Entity71BA_ClampPlayer(Entity71BA* p, s32 param_2) {
  if (p->flags & AXIS_X) {
    if ((gPlayerPtr[0]->mover.pos.x & 0xFF) >= param_2) {
      gPlayerPtr[0]->mover.pos.x = ((gPlayerPtr[0]->mover.pos.x >> 8) << 8) + param_2;
      gPlayerPtr[0]->beast.pos.x = gPlayerPtr[0]->mover.pos.x;
    }
  } else {
    if ((gPlayerPtr[0]->mover.pos.z & 0xFF) >= param_2) {
      gPlayerPtr[0]->mover.pos.z = ((gPlayerPtr[0]->mover.pos.z >> 8) << 8) + param_2;
      gPlayerPtr[0]->beast.pos.z = gPlayerPtr[0]->mover.pos.z;
    }
  }
}

// FLAG_1
void FUN_080a035c(Entity71BA* p) {
  bool32 ret = Entity71BA_IsPlayerAtHeight(p);

  if (ret) {
    ret = Entity71BA_IsPlayerOnTile(p);
    if (ret) {
      if (!p->unk_22) {
        gPlayerPtr[0]->wallLockCount++;
        if (p->flags & AXIS_X) {
          gPlayerPtr[0]->actionDir = DIR8_UP_LEFT;
        } else {
          gPlayerPtr[0]->actionDir = DIR8_UP_RIGHT;
        }
        p->unk_22 = TRUE;
      }
      if (p->tileOverrideActive) {
        Map_RemoveTileOverride(&p->tileOverride);
        p->tileOverrideActive = FALSE;
      }
      Entity71BA_ClampPlayer(p, 40);
      if (gPlayerPtr[0]->action != PACT_WALL && !Entity71BA_IsPlayerMini() && gPlayerPtr[0]->kind != PLAYER_BAT && gPlayerPtr[0]->kind != PLAYER_MOUSE) {
        if (p->flags & AXIS_X) {
          Player_EnterWall(gPlayerPtr[0], DIR8_UP_LEFT);
        } else {
          Player_EnterWall(gPlayerPtr[0], DIR8_UP_RIGHT);
        }
      }
      return;
    }
    if (p->unk_22) {
      gPlayerPtr[0]->wallLockCount--;
      p->unk_22 = ret;
    }
    if (!FUN_080a0268(p)) {
      if (!p->tileOverrideActive) {
        Map_AddTileOverride(&p->tileOverride, p->tileIdx, 0, p->height, 0xFF, TATTR_UNK_11 | TATTR_UNK_3 | TATTR_WALL | TATTR_UNK_0);
        p->tileOverrideActive = TRUE;
      }
      return;
    }
  } else {
    if (p->unk_22) {
      gPlayerPtr[0]->wallLockCount--;
      p->unk_22 = ret;
    }
  }
  if (p->tileOverrideActive) {
    Map_RemoveTileOverride(&p->tileOverride);
    p->tileOverrideActive = ret;
  }
}

// 小さい状態 (赤いキノコの効果中, バット,マウス) かを返す
static bool32 IsPlayerSmall(Entity71BA* p) {
  if (Entity71BA_IsPlayerMini() || gPlayerPtr[0]->kind == PLAYER_BAT || gPlayerPtr[0]->kind == PLAYER_MOUSE) {
    return TRUE;
  }
  return FALSE;
}

void Entity71BA_UpdateTileOverride(Entity71BA* p) {
  if (Entity71BA_IsPlayerAtHeight(p)) {
    if (Entity71BA_IsPlayerOnTile(p)) {
      if (IsPlayerSmall(p)) {
        Entity71BA_ClampPlayer(p, 64);
      } else if (p->tileOverrideActive) {
        u8 keep = p->flags & FLAG_5;

        if (keep) {
          p->tileOverride.tile.attr |= TATTR_FALLDEATH;
        } else {
          Map_RemoveTileOverride(&p->tileOverride);
          p->tileOverrideActive = keep;
          Player_EnterLanding(gPlayerPtr[0]);
        }
        if (p->scriptID != 0) {
          VM_ExecByID(p->scriptID, NULL);
        }
      }
    } else if (IsPlayerSmall(p) && Entity71BA_IsPlayerWithinTileOffset(p, Q8(0.25))) {
      if (!p->tileOverrideActive) {
        Map_AddTileOverride(&p->tileOverride, p->tileIdx, 0, p->height, 0xFF, TATTR_UNK_11 | TATTR_UNK_5 | TATTR_UNK_3 | TATTR_WALL);
        p->tileOverrideActive = TRUE;
      }
    } else if (p->tileOverrideActive) {
      Map_RemoveTileOverride(&p->tileOverride);
      p->tileOverrideActive = FALSE;
    }
  } else if (p->tileOverrideActive) {
    Map_RemoveTileOverride(&p->tileOverride);
    p->tileOverrideActive = FALSE;
  }
}

s32 Entity71BA_Update(Entity71BA* p) {
  if (!(gPlayerPtr[0]->mode & PMODE_DEAD)) {
    p->updateCallback(p);
  }
  return 0;
}

// 原典は return を書き忘れている
s32 Entity71BA_Destroy(Entity71BA* p) {
  if (p->tileOverrideActive) {
    Map_RemoveTileOverride(&p->tileOverride);
  }
}

s32 Entity71BA_Init(Entity71BA* p, u32 id, u32 _) {
  Vec3 pos;
  u32 scriptID;

  p->id = id;
  p->tileOverrideActive = FALSE;
  p->flags = VM_SeekToNamedArg('t') ? VM_GetValue() : (AXIS_X | FLAG_0);
  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue(), pos.y = VM_GetValue(), pos.z = VM_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }
  p->tileIdx = GetCollisionTileIdx(&pos);
  p->height = pos.y >> 8;
  scriptID = VM_SeekToNamedArg('R');
  if (scriptID) {
    scriptID = VM_GetValue();
  }
  p->scriptID = scriptID;
  if (p->flags & FLAG_0) {
    p->updateCallback = FUN_080a01d8;
  } else if (p->flags & FLAG_1) {
    p->updateCallback = FUN_080a035c;
  } else {
    p->updateCallback = Entity71BA_UpdateTileOverride;
  }
  return 0;
}

// 0x71BA
Entity71BA* Entity71BA_Create(u32 id, u32 _) {
  Entity71BA* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity71BA));

  if (p != NULL) {
    SetEntityRoutine(p, Entity71BA_Update, Entity71BA_Destroy);
    if (Entity71BA_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
