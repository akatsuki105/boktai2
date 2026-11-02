#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "map_inline.h"
#include "player.h"
#include "vm.h"

// 条件 (プレイヤーのタイル位置・高さ・フォーム) が揃っている間だけ、あるタイルの当たり判定を上書きする
typedef struct Entity71BA {
  Entity e;                                    // 0x00, ENTITY_UNK_8
  u16 unk_18;                                  // 0x18
  u8 unk_1a[2];                                // 0x1A, padding?
  u8 flags;                                    // 0x1C, '.t=9', bit0/bit1 で fn を選び、bit3 で x/z のどちらを見るかが変わる
  bool8 tileOverrideActive;                    // 0x1D, tileOverride を衝突マップに繋いであるか, _Destroy が立っていれば Map_RemoveTileOverride で外す
  u16 tileIdx;                                 // 0x1E, gCollisionMap->rowOffsets[z] + x, '.p' の x/z から _Init が計算する
  u16 height;                                  // 0x20, '.p[1]' (>> 8 した値)
  bool16 unk_22;                               // 0x22, FUN_080a035c が 0/1 を入れ替えるたび gPlayerPtr[0]->unk_3f3 を +1/-1 する
  MapTileOverride tileOverride;                // 0x24
  u32 unk_34;                                  // 0x34, '.R'
  void (*updateCallback)(struct Entity71BA*);  // 0x38, .flags bit0 なら FUN_080a01d8, bit1 なら FUN_080a035c, どちらでもなければ _UpdateTileOverride
} Entity71BA;
static_assert(sizeof(Entity71BA) == 60);

void FUN_0807a334(Player* p);
void FUN_0807a44c(Player* p, s32 dir);

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

  if (p->flags & 8) {
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
  if (gPlayerPtr[0]->action == 4) {
    u8 dir = gPlayerPtr[0]->actionDir;

    if (dir == 1 && (p->flags & 0x10)) {
      return TRUE;
    }
    if (dir == 7 && (p->flags & 8)) {
      return TRUE;
    }
    return FALSE;
  }
  if (gPlayerPtr[0]->kind == PLAYER_BAT) {
    return TRUE;
  }
  if (Entity71BA_IsPlayerMini() || gPlayerPtr[0]->kind == PLAYER_MOUSE) {
    if (Entity71BA_IsPlayerWithinTileOffset(p, 40)) {
      return TRUE;
    }
  }
  return FALSE;
}

void FUN_080a01d8(Entity71BA* p) {
  if (Entity71BA_IsPlayerAtHeight(p)) {
    if (Entity71BA_IsPlayerOnTile(p) && !FUN_080a0140(p)) {
      if (p->tileOverrideActive) {
        Map_RemoveTileOverride(&p->tileOverride);
        p->tileOverrideActive = FALSE;
        FUN_0807a334(gPlayerPtr[0]);
        if (p->unk_34 != 0) {
          VM_ExecByID(p->unk_34, NULL);
        }
      }
    } else if (!p->tileOverrideActive) {
      Map_AddTileOverride(&p->tileOverride, p->tileIdx, 0, p->height, 0xFF, 0x82A);
      p->tileOverrideActive = TRUE;
    }
  } else if (p->tileOverrideActive) {
    Map_RemoveTileOverride(&p->tileOverride);
    p->tileOverrideActive = FALSE;
  }
}

s32 FUN_080a0268(Entity71BA* p) {
  if (gPlayerPtr[0]->action == 4) {
    u8 dir = gPlayerPtr[0]->actionDir;

    if (dir == 1 && (p->flags & 0x10)) {
      return TRUE;
    }
    if (dir == 7 && (p->flags & 8)) {
      return TRUE;
    }
    return FALSE;
  }
  if (Entity71BA_IsPlayerMini() || gPlayerPtr[0]->kind == PLAYER_BAT || gPlayerPtr[0]->kind == PLAYER_MOUSE) {
    if (Entity71BA_IsPlayerWithinTileOffset(p, 40)) {
      return TRUE;
    }
  }
  return FALSE;
}

void Entity71BA_ClampPlayer(Entity71BA* p, s32 param_2) {
  if (p->flags & 8) {
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

void FUN_080a035c(Entity71BA* p) {
  bool32 ret = Entity71BA_IsPlayerAtHeight(p);

  if (ret) {
    ret = Entity71BA_IsPlayerOnTile(p);
    if (ret) {
      if (!p->unk_22) {
        gPlayerPtr[0]->unk_3f3[0]++;
        if (p->flags & 8) {
          gPlayerPtr[0]->actionDir = 7;
        } else {
          gPlayerPtr[0]->actionDir = 1;
        }
        p->unk_22 = TRUE;
      }
      if (p->tileOverrideActive) {
        Map_RemoveTileOverride(&p->tileOverride);
        p->tileOverrideActive = FALSE;
      }
      Entity71BA_ClampPlayer(p, 40);
      if (gPlayerPtr[0]->action != 4 && !Entity71BA_IsPlayerMini() && gPlayerPtr[0]->kind != PLAYER_BAT && gPlayerPtr[0]->kind != PLAYER_MOUSE) {
        if (p->flags & 8) {
          FUN_0807a44c(gPlayerPtr[0], 7);
        } else {
          FUN_0807a44c(gPlayerPtr[0], 1);
        }
      }
      return;
    }
    if (p->unk_22) {
      gPlayerPtr[0]->unk_3f3[0]--;
      p->unk_22 = ret;
    }
    if (!FUN_080a0268(p)) {
      if (!p->tileOverrideActive) {
        Map_AddTileOverride(&p->tileOverride, p->tileIdx, 0, p->height, 0xFF, 0x80B);
        p->tileOverrideActive = TRUE;
      }
      return;
    }
  } else {
    if (p->unk_22) {
      gPlayerPtr[0]->unk_3f3[0]--;
      p->unk_22 = ret;
    }
  }
  if (p->tileOverrideActive) {
    Map_RemoveTileOverride(&p->tileOverride);
    p->tileOverrideActive = ret;
  }
}

// 小さい状態 (赤いキノコの効果中, バット,マウス) かを返す
bool32 IsPlayerSmall(Entity71BA* p) {
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
        u8 keep = p->flags & 0x20;

        if (keep) {
          p->tileOverride.tile.attr |= 0x40;
        } else {
          Map_RemoveTileOverride(&p->tileOverride);
          p->tileOverrideActive = keep;
          FUN_0807a334(gPlayerPtr[0]);
        }
        if (p->unk_34 != 0) {
          VM_ExecByID(p->unk_34, NULL);
        }
      }
    } else if (IsPlayerSmall(p) && Entity71BA_IsPlayerWithinTileOffset(p, 64)) {
      if (!p->tileOverrideActive) {
        Map_AddTileOverride(&p->tileOverride, p->tileIdx, 0, p->height, 0xFF, 0x82A);
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

s32 Entity71BA_Init(Entity71BA* p, u32 param_2, u32 param_3) {
  Vec3 pos;
  u32 scriptID;

  p->unk_18 = param_2;
  p->tileOverrideActive = FALSE;
  p->flags = VM_SeekToNamedArg('t') ? VM_GetValue() : 9;
  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
  }
  p->tileIdx = GetCollisionTileIdx(&pos);
  p->height = pos.y >> 8;
  scriptID = VM_SeekToNamedArg('R');
  if (scriptID) {
    scriptID = VM_GetValue();
  }
  p->unk_34 = scriptID;
  if (p->flags & 1) {
    p->updateCallback = FUN_080a01d8;
  } else if (p->flags & 2) {
    p->updateCallback = FUN_080a035c;
  } else {
    p->updateCallback = Entity71BA_UpdateTileOverride;
  }
  return 0;
}

Entity71BA* Entity71BA_Create(u32 param_1, u32 param_2) {
  Entity71BA* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity71BA));

  if (p != NULL) {
    SetEntityRoutine(p, Entity71BA_Update, Entity71BA_Destroy);
    if (Entity71BA_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
