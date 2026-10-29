#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "player.h"

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

NAKED bool32 Entity71BA_IsPlayerOnTile(Entity71BA* p) { INCFUNC("asm/func/Entity71BA_IsPlayerOnTile.inc"); }

bool32 Entity71BA_IsPlayerAtHeight(Entity71BA* p) {
  if (gPlayerPtr[0]->mover.pos.y == p->height << 8) {
    return TRUE;
  }
  return FALSE;
}

// 残差は AND の結果を置くレジスタだけ (原典はマスク側, こちらは値側)
NON_MATCH bool32 FUN_080a0104(Entity71BA* p, s32 param_2) {
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
  INCFUNC("asm/func/FUN_080a0104.inc");
#endif
}

NAKED s32 FUN_080a0140(Entity71BA* p) { INCFUNC("asm/func/FUN_080a0140.inc"); }

NAKED void FUN_080a01d8(Entity71BA* p) { INCFUNC("asm/func/FUN_080a01d8.inc"); }

NAKED s32 FUN_080a0268(Entity71BA* p) { INCFUNC("asm/func/FUN_080a0268.inc"); }

NAKED void Entity71BA_ClampPlayer(Entity71BA* p, s32 param_2) { INCFUNC("asm/func/Entity71BA_ClampPlayer.inc"); }

NAKED void FUN_080a035c(Entity71BA* p) { INCFUNC("asm/func/FUN_080a035c.inc"); }

// 小さい状態 (赤いキノコの効果中, バット,マウス) かを返す
// 残差0命令 (28/28), 命令順だけ違う: 原典は 0/1 の初期値 0 を最初のグローバル読み出しの後に置く
NON_MATCH bool32 IsPlayerSmall(void) {
#ifdef NONMATCHING_C
  bool32 isMini = gGoodCondTimer != 0 && gGoodCondID == GOOD_MINI;

  if (isMini) {
    return TRUE;
  }
  if (gPlayerPtr[0]->kind == PLAYER_BAT) {
    return TRUE;
  }
  if (gPlayerPtr[0]->kind == PLAYER_MOUSE) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/IsPlayerSmall.inc");
#endif
}

NAKED void Entity71BA_UpdateTileOverride(Entity71BA* p) { INCFUNC("asm/func/Entity71BA_UpdateTileOverride.inc"); }

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

NAKED s32 Entity71BA_Init(Entity71BA* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/Entity71BA_Init.inc"); }

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
