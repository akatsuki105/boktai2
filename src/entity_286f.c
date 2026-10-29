#include "entity_286f.h"

#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sprite.h"
#include "vm.h"

COMMON_DATA Entity286F* gEntity286F = NULL;  // 0x03002B50

// キャラクターごとのアニメ表, 区切りは sEntity286FSprites の data が指す位置
// clang-format off
const Entity286FAnim sEntity286FAnims[135] = {
    // SPRITE_DJANGO_SABATA idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   5},

    // SPRITE_DJANGO_SABATA idx 1
    {dirMode : 3, unk_1 : 1, pose : 414},
    {dirMode : 3, unk_1 : 1, pose : 419},
    {dirMode : 3, unk_1 : 1, pose : 414},
    {dirMode : 3, unk_1 : 1, pose : 419},

    // SPRITE_MOUSE idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   1},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   1},

    // SPRITE_SKELETONS idx 0
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   6},
    {dirMode : 2, unk_1 : 1, pose :  30},
    {dirMode : 2, unk_1 : 1, pose :   6},

    // SPRITE_BOKU idx 0
    {dirMode : 2, unk_1 : 0, pose :   7},
    {dirMode : 2, unk_1 : 0, pose :   8},
    {dirMode : 2, unk_1 : 0, pose :   9},
    {dirMode : 2, unk_1 : 0, pose :   8},

    // SPRITE_OTENKO_00 idx 0
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 0, unk_1 : 0, pose :   1},
    {dirMode : 0, unk_1 : 0, pose :  10},
    {dirMode : 0, unk_1 : 0, pose :   3},
    {dirMode : 0, unk_1 : 0, pose :  19},
    {dirMode : 0, unk_1 : 0, pose :   0},

    // SPRITE_SMITH_MARCELLO idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   7},
    {dirMode : 1, unk_1 : 0, pose :   9},
    {dirMode : 1, unk_1 : 0, pose :  10},
    {dirMode : 1, unk_1 : 0, pose :  11},
    {dirMode : 1, unk_1 : 0, pose :  12},
    {dirMode : 1, unk_1 : 0, pose :  13},
    {dirMode : 1, unk_1 : 0, pose :  14},
    {dirMode : 1, unk_1 : 0, pose :  15},

    // SPRITE_SHAIAN idx 0
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  12},
    {dirMode : 1, unk_1 : 1, pose :  40},
    {dirMode : 1, unk_1 : 1, pose :  41},
    {dirMode : 0, unk_1 : 1, pose :   0},

    // SPRITE_RITA idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 2, pose :   7},
    {dirMode : 2, unk_1 : 2, pose :  11},
    {dirMode : 2, unk_1 : 2, pose :  12},
    {dirMode : 1, unk_1 : 1, pose :  15},
    {dirMode : 2, unk_1 : 3, pose :  17},
    {dirMode : 2, unk_1 : 3, pose :  18},
    {dirMode : 2, unk_1 : 3, pose :  19},

    // SPRITE_ZAJI idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 2, pose :  10},
    {dirMode : 1, unk_1 : 0, pose :  14},
    {dirMode : 0, unk_1 : 1, pose :   7},
    {dirMode : 0, unk_1 : 1, pose :   8},
    {dirMode : 0, unk_1 : 1, pose :   9},
    {dirMode : 0, unk_1 : 1, pose :  17},
    {dirMode : 0, unk_1 : 1, pose :  16},

    // SPRITE_SUMIRE idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 0, unk_1 : 1, pose :   7},
    {dirMode : 0, unk_1 : 1, pose :   8},
    {dirMode : 0, unk_1 : 1, pose :  10},
    {dirMode : 0, unk_1 : 1, pose :   9},

    // SPRITE_KURO idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 1, unk_1 : 1, pose :   9},
    {dirMode : 2, unk_1 : 1, pose :   7},
    {dirMode : 1, unk_1 : 1, pose :  10},
    {dirMode : 1, unk_1 : 1, pose :  11},
    {dirMode : 1, unk_1 : 1, pose :  12},
    {dirMode : 1, unk_1 : 1, pose :  13},
    {dirMode : 1, unk_1 : 1, pose :  14},
    {dirMode : 1, unk_1 : 1, pose :  15},
    {dirMode : 3, unk_1 : 1, pose :  16},
    {dirMode : 2, unk_1 : 1, pose :  21},
    {dirMode : 1, unk_1 : 1, pose :  25},
    {dirMode : 2, unk_1 : 1, pose :  23},
    {dirMode : 1, unk_1 : 1, pose :  26},
    {dirMode : 1, unk_1 : 1, pose :  27},
    {dirMode : 1, unk_1 : 1, pose :  28},
    {dirMode : 1, unk_1 : 1, pose :  29},
    {dirMode : 1, unk_1 : 1, pose :  30},
    {dirMode : 1, unk_1 : 1, pose :  31},
    {dirMode : 0, unk_1 : 1, pose :  32},

    // SPRITE_KID idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   7},

    // SPRITE_LADY idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   7},

    // SPRITE_COFFINSELLER_UNKNOWN idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},

    // SPRITE_ENNIO_LUIS idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},

    // SPRITE_DAINN idx 0
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 1, unk_1 : 1, pose :   3},
    {dirMode : 1, unk_1 : 1, pose :   2},

    // SPRITE_SMITH_MARCELLO idx 1
    {dirMode : 3, unk_1 : 1, pose :  16},
    {dirMode : 2, unk_1 : 1, pose :  21},
    {dirMode : 3, unk_1 : 1, pose :  16},
    {dirMode : 2, unk_1 : 1, pose :  23},

    // SPRITE_COFFINSELLER_UNKNOWN idx 1
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 1, pose :  10},
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 1, pose :  12},

    // SPRITE_ENNIO_LUIS idx 1
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  12},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},

    // SPRITE_MEGAMAN idx 0
    {dirMode : 0, unk_1 : 1, pose :   0},
};  // 0x085AAFF4
// clang-format on

typedef struct {
  SpriteID16 id;               // 0x0, NPCのスプライトIDばっかり
  u8 idx;                      // 0x2, 1つのグラフィックにn人分のグラフィックデータが入っているときにどのキャラクターかを示すインデックス?
  const Entity286FAnim* data;  // 0x4, そのキャラのアニメ表の先頭
} Entity286FSpriteEntry;

const Entity286FSpriteEntry sEntity286FSprites[21] = {
    {id : SPRITE_DJANGO_SABATA,        idx : 0, data : &sEntity286FAnims[0]  },
    {id : SPRITE_MOUSE,                idx : 0, data : &sEntity286FAnims[8]  },
    {id : SPRITE_SKELETONS,            idx : 0, data : &sEntity286FAnims[12] },
    {id : SPRITE_BOKU,                 idx : 0, data : &sEntity286FAnims[16] },
    {id : SPRITE_OTENKO_00,            idx : 0, data : &sEntity286FAnims[20] },
    {id : SPRITE_SMITH_MARCELLO,       idx : 0, data : &sEntity286FAnims[29] },
    {id : SPRITE_SHAIAN,               idx : 0, data : &sEntity286FAnims[40] },
    {id : SPRITE_RITA,                 idx : 0, data : &sEntity286FAnims[49] },
    {id : SPRITE_ZAJI,                 idx : 0, data : &sEntity286FAnims[60] },
    {id : SPRITE_SUMIRE,               idx : 0, data : &sEntity286FAnims[71] },
    {id : SPRITE_KURO,                 idx : 0, data : &sEntity286FAnims[79] },
    {id : SPRITE_KID,                  idx : 0, data : &sEntity286FAnims[100]},
    {id : SPRITE_LADY,                 idx : 0, data : &sEntity286FAnims[104]},
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 0, data : &sEntity286FAnims[108]},
    {id : SPRITE_ENNIO_LUIS,           idx : 0, data : &sEntity286FAnims[112]},
    {id : SPRITE_DAINN,                idx : 0, data : &sEntity286FAnims[116]},
    {id : SPRITE_DJANGO_SABATA,        idx : 1, data : &sEntity286FAnims[4]  },
    {id : SPRITE_SMITH_MARCELLO,       idx : 1, data : &sEntity286FAnims[122]},
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 1, data : &sEntity286FAnims[126]},
    {id : SPRITE_ENNIO_LUIS,           idx : 1, data : &sEntity286FAnims[130]},
    {id : SPRITE_MEGAMAN,              idx : 0, data : &sEntity286FAnims[134]}
};  // 0x085AB210

const NPCFootStepSound sNPCFootStepSounds[21] = {
    {id : SPRITE_DJANGO_SABATA,        idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_MOUSE,                idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_SKELETONS,            idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_BOKU,                 idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_OTENKO_00,            idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_SMITH_MARCELLO,       idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_SHAIAN,               idx : 0, soundSet : 0, stepFrames : {4, 0, 4, 0}    },
    {id : SPRITE_RITA,                 idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_ZAJI,                 idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_SUMIRE,               idx : 0, soundSet : 2, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_KURO,                 idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_KID,                  idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_LADY,                 idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_ENNIO_LUIS,           idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_DAINN,                idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_DJANGO_SABATA,        idx : 1, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_SMITH_MARCELLO,       idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_ENNIO_LUIS,           idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_MEGAMAN,              idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
};  // 0x085AB2B8

const SoundID16 sFootStepSEs[6] = {SONG_201, SONG_202, SONG_603, SONG_604, SONG_603, SONG_604};  // 0x085AB360

// 状態を差し替えて経過フレーム数を 0 に戻す
static inline void Entity286FNode_SetState(Entity286FNode* node, u32 state) {
  node->state = state;
  node->timer = 0;
}

// id と idx の組に対応するデータを表から探す
const Entity286FAnim* Entity286F_FindSpriteData(SpriteID32 id, s32 idx) {
  s32 i;

  for (i = 0; i < 21; i++) {
    if (sEntity286FSprites[i].id == id && sEntity286FSprites[i].idx == idx) {
      return sEntity286FSprites[i].data;
    }
  }

  return NULL;
}

// スプライトIDとキャラ番号の組に対応する表の行, 無ければ NULL
const NPCFootStepSound* FUN_08040dc0(SpriteID32 id, s32 idx) {
  s32 i;

  for (i = 0; i < 21; i++) {
    if (sNPCFootStepSounds[i].id == id && sNPCFootStepSounds[i].idx == idx) {
      return &sNPCFootStepSounds[i];
    }
  }
  return NULL;
}

s32 FUN_08040df4(Entity286F* p, Entity286FNode* node, SpriteID32 id, s32 idx) {
  node->unk_2b8 = Entity286F_FindSpriteData(id, idx);

  if (node->unk_2b8 != NULL) {
    node->unk_2bc = FUN_08040dc0(id, idx);
    if (node->unk_2bc != NULL) {
      return 0;
    }
  }
  return -1;
}

// ノードをリストの先頭に繋ぐ
void Entity286F_LinkNode(Entity286F* p, Entity286FNode* node) {
  if (p->head != NULL) {
    p->head->prev = node;
  }

  node->prev = NULL;
  node->next = p->head;
  p->head = node;
  node->active = 1;
}

// リンクリストからノードを外す
void FUN_08040e68(Entity286F* p, Entity286FNode* node) {
  if (node->prev != NULL) {
    node->prev->next = node->next;
  } else {
    p->head = node->next;
  }
  if (node->next != NULL) {
    node->next->prev = node->prev;
  }
}

// mover.id が id のノードを探す
Entity286FNode* Entity286F_FindNodeByMoverID(Entity286F* p, u32 id) {
  Entity286FNode* node = p->head;

  while (node != NULL) {
    if (node->mover.id == id) {
      return node;
    }
    node = node->next;
  }

  return NULL;
}

// ノードを1つ確保して種類だけ入れる
Entity286FNode* Entity286FNode_Alloc(Entity286F* p, u32 kind) {
  Entity286FNode* node;

  if (gEntity286F == NULL) {
    return NULL;
  }

  node = Malloc(sizeof(Entity286FNode));
  if (node == NULL) {
    return NULL;
  }

  ClearMemory(node, sizeof(Entity286FNode));
  node->kind = kind;
  return node;
}

// ノードの Mover を初期化して unk_a0 を結び付ける
// 残差は命令の並び順のみ (命令列は 27 対 27), 原典は unk_1b の strb と mover のアドレス計算を
// 引数の u16/u8 マスクより前に置くが agbcc はマスクを先に出す
NON_MATCH s32 FUN_08040f0c(Entity286FNode* node, u16 id, Vec3* pos, u8 angle) {
#ifdef NONMATCHING_C
  Mover* mover = &node->mover;

  node->unk_1b = angle;
  Mover_Init(mover, id, pos, angle, 7, node);
  FUN_0823b464(mover, (u32)&node->zoneEvent);
  mover->flags |= MOVER_FLAG_2;
#else
  INCFUNC("asm/func/FUN_08040f0c.inc");
#endif
}

NAKED s32 FUN_08040f48(Entity286FNode* node, s32 assetType, u32 fileID, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_08040f48.inc"); }

NAKED s32 FUN_08040fc0(Entity286FNode* node, Vec3* pos, s8 param_3, u32 param_4, s8 param_5) { INCFUNC("asm/func/FUN_08040fc0.inc"); }

// 影を描画リストから外す
s32 Entity286FNode_RemoveShadow(Entity286FNode* node) {
  if (node->shadowKind == 1) {
    ParticleShadow_Remove(&node->shadow.ptcl);
  } else if (node->shadowKind == 2) {
    AuxShadow_Remove(&node->shadow.aux);
  }

  return 0;
}

// 影を隠す
s32 Entity286FNode_HideShadow(Entity286FNode* node) {
  if (node->shadowKind == 1) {
    ParticleShadow_Hide(&node->shadow.ptcl);
  } else if (node->shadowKind == 2) {
    AuxShadow_Hide(&node->shadow.aux);
  }

  return 0;
}

// 影を表示する
s32 Entity286FNode_ShowShadow(Entity286FNode* node) {
  if (node->shadowKind == 1) {
    ParticleShadow_Show(&node->shadow.ptcl);
  } else if (node->shadowKind == 2) {
    AuxShadow_Show(&node->shadow.aux);
  }

  return 0;
}

s32 FUN_08002a48(Mover*);

s32 FUN_080410cc(Entity286FNode* node) {
  if (FUN_08002a48(&node->mover) < 0) {
    return -1;
  }
  node->unk_1ee = 1;
  return 0;
}

// 登録済みなら mover をリストから外す
s32 Entity286FNode_RemoveMover(Entity286FNode* node) {
  if (node->unk_1ee == 0) {
    return -1;
  }

  FUN_08002a58(&node->mover);
  node->unk_1ee = 0;
  return 0;
}

s32 Entity286FNode_ApplyPltt(Entity286FNode* node, u16 plttID) {
  SpriteHolder* sprite = &node->sprite;

  node->curPlttID = plttID;
  return SpriteHolder_SetPlttID(sprite, node->curPlttID);
}

s32 Entity286FNode_SetPltt(Entity286FNode* node, u16 param_2) {
  node->plttID = param_2;
  return Entity286FNode_ApplyPltt(node, node->plttID);
}

s32 Entity286FNode_RefreshPltt(Entity286FNode* node) { return Entity286FNode_ApplyPltt(node, node->plttID); }

// ノードを表から外して Free する
s32 FUN_0804114c(Entity286FNode* node) {
  Entity286F* p = gEntity286F;

  if (p != NULL && node->active) {
    FUN_08040e68(p, node);
    Entity286FNode_RemoveMover(node);
    Mover_Unlink(&node->mover);
    SpriteHolder_Remove(&node->sprite);
    Entity286FNode_RemoveShadow(node);
    node->active = 0;
    Free(node);
    return 0;
  }
  return -1;
}

// 登録済みのコールバックを順に呼ぶ
s32 FUN_080411a0(Entity286F* p, Entity286FNode* node) {
  s32 i;

  if (!node->active) {
    return -1;
  }

  for (i = 0; i < 4; i++) {
    if (node->cbs[i] != NULL) {
      node->cbs[i](p, node);
    }
  }
  return 0;
}

NAKED s32 FUN_080411d8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080411d8.inc"); }

void FUN_080412f4(void) {}

void FUN_080412f8(void) {}

NAKED s32 FUN_080412fc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080412fc.inc"); }

NAKED s32 FUN_0804135c(Entity286FNode* node, s32 param_2, u16 param_3, s8 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_0804135c.inc"); }

// unk_19 から再生の引数2つを作ってアニメを設定する
// 残差1命令 (34 対 33), 原典は b を r3 (第4引数レジスタ) に直接置くが, こちらは r4 に取るので呼び出し直前に移し替える
// 宣言順 / s32・bool32 / SpriteHolder* ローカル / 呼び出しを2本に分ける形は試済
NON_MATCH s32 FUN_080413b8(Entity286FNode* node, u32 pose, u32 param_3, s32 param_4, u32 param_5, u32 param_6) {
#ifdef NONMATCHING_C
  u32 a;
  u32 b;

  if (node->sprite.kind == 1) {
    a = node->unk_19;
    b = a > 1;
  } else {
    a = 0;
    b = node->unk_19 > 1;
  }
  return SpriteHolder_SetAnim(&node->sprite, pose, a, b, param_3, param_5, param_6);
#else
  INCFUNC("asm/func/FUN_080413b8.inc");
#endif
}

NAKED s32 FUN_080413fc(Entity286FNode* node, s32 param_2, u16 param_3, s8 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_080413fc.inc"); }

s32 FUN_08041460(Entity286FNode* node, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { return SpriteHolder_SetAnim(&node->sprite, pose, 0, 0, param_3, param_5, param_6); }

NAKED s32 FUN_08041480(Entity286FNode* node, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08041480.inc"); }

NAKED void FUN_080414fc(Entity286FNode* node, s32 param_2) { INCFUNC("asm/func/FUN_080414fc.inc"); }

// 2点が x/z は range 未満, y は 0xFF 以内に収まっているかを返す
bool32 UNUSED FUN_0804157c(Vec3* a, Vec3* b, s32 range) {
  s32 dx, dy, dz;

  dx = abs(b->x - a->x);
  if (dx >= range) {
    return FALSE;
  }
  dy = abs(b->y - a->y);
  if (dy > 0xFF) {
    return FALSE;
  }
  dz = abs(b->z - a->z);
  if (dz >= range) {
    return FALSE;
  }
  return TRUE;
}

NAKED void FUN_080415cc(Entity286FNode* node, s32 param_2, u16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_080415cc.inc"); }

NAKED void FUN_080417dc(Mover* mover) { INCFUNC("asm/func/FUN_080417dc.inc"); }

NAKED void FUN_08041918(Entity286F* p) { INCFUNC("asm/func/FUN_08041918.inc"); }

// 0xDDD0
NAKED s32 Cmd_DDD0(void) { INCFUNC("asm/func/Cmd_DDD0.inc"); }

NAKED s32 Cmd_5517(void) { INCFUNC("asm/func/Cmd_5517.inc"); }

NAKED s32 Cmd_43D6(void) { INCFUNC("asm/func/Cmd_43D6.inc"); }

// '.n' の Mover ID のノードの unk_227 が 13〜15 かどうか
bool32 Cmd_6688(void) {
  Entity286F* p = gEntity286F;
  Entity286FNode* node;

  if (p == NULL) {
    return FALSE;
  }

  node = Entity286F_FindNodeByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (node == NULL) {
    return FALSE;
  }

  if (node->unk_227 >= 13 && node->unk_227 <= 15) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 FUN_08041e10(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08041e10.inc"); }

void FUN_08042178(Entity286F* p, Entity286FNode* node, s32 elapsed) {
  if (node->unk_09 != 0) {
    node->unk_09 = 0;
    node->unk_07 = 0;
    FUN_08041480(node, 0, 2, 0, 4);
  }
  SET_FLAGS(node->flags, E286FNODE_UNK_8);
  node->fn(node);
}

void FUN_080421bc(Entity286F* p, Entity286FNode* node, s32 elapsed) {
  if (node->unk_09 != 0) {
    node->unk_09 = 0;
    node->unk_07 = 0;
    FUN_08041480(node, 0, 1, 0, 4);
  }
  SET_FLAGS(node->flags, E286FNODE_UNK_12);
  node->fn(node);
}

NAKED void FUN_08042200(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08042200.inc"); }

NAKED void FUN_0804234c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0804234c.inc"); }

NAKED void FUN_08042414(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08042414.inc"); }

NAKED void FUN_08042638(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08042638.inc"); }

void FUN_08042868(Entity286F* p, Entity286FNode* node, s32 elapsed) {
  if (node->unk_09 != 0) {
    node->unk_09 = 0;
    node->unk_07 = 0;
    FUN_08041480(node, node->unk_1e8, node->unk_1e9, 0, 4);
  }
  SET_FLAGS(node->flags, E286FNODE_UNK_12);
  node->fn(node);
}

NAKED void FUN_080428b8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_080428b8.inc"); }

NAKED void FUN_08042a48(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08042a48.inc"); }

NAKED void FUN_08042cf0(Entity286F* p, Entity286FNode* node, s32 param_3) { INCFUNC("asm/func/FUN_08042cf0.inc"); }

NAKED void FUN_08042d50(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08042d50.inc"); }

NAKED void FUN_08042f34(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08042f34.inc"); }

NAKED void FUN_08043108(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08043108.inc"); }

NAKED void FUN_08043360(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08043360.inc"); }

NAKED s32 FUN_080434ac(Entity286FNode* node, Entity286FRecord* rec) { INCFUNC("asm/func/FUN_080434ac.inc"); }

// レコードの位置が 0x28 以内にあるときだけ FUN_080434ac へ進む
// 残差はアドレスの作り方だけ (36 対 36), 原典は node+0x198 を作って [r0, #8] で読むが agbcc は node+0x1A0 に畳む
// u8 配列経由のキャストでも畳まれる
NON_MATCH s32 FUN_08043510(Entity286FNode* node) {
#ifdef NONMATCHING_C
  Entity286FRecord* rec = node->unk_1a0;
  s32 dx = rec->x - node->mover.pos.x;
  s32 dz;

  if (dx < 0) {
    dx = -dx;
  }
  if (dx > 0x28) {
    return 9;
  }

  dz = rec->y - node->mover.pos.z;
  if (dz < 0) {
    dz = -dz;
  }
  if (dz > 0x28) {
    return 9;
  }

  return FUN_080434ac(node, rec);
#else
  INCFUNC("asm/func/FUN_08043510.inc");
#endif
}

// 待ちが解除されたら unk_05 を 1 にしてメッセージの待ちを終える
void FUN_0804355c(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 2 にしてメッセージの待ちを終える
void FUN_08043588(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 2;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 1 に移してメッセージの待ちを終える
void FUN_080435b4(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 3;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 1);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 4 にして, unk_07 が立っていたら state を移してメッセージの待ちを終える
void FUN_080435f0(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 4;
  }

  if (node->unk_07) {
    if (node->unk_217) {
      Entity286FNode_SetState(node, node->unk_227);
      node->unk_08 = 1;
    } else {
      Entity286FNode_SetState(node, 1);
      node->unk_08 = 1;
    }
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 5 にして, unk_07 が立っていたら state 1 に移してメッセージの待ちを終える
void FUN_0804364c(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 5;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 1);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 6 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08043688(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 6;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }

  node->timer++;
}

NAKED void FUN_080436c4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_080436c4.inc"); }

NAKED void FUN_08043774(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043774.inc"); }

NAKED void FUN_08043960(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043960.inc"); }

NAKED void FUN_08043a24(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043a24.inc"); }

NAKED void FUN_08043bcc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043bcc.inc"); }

// 待ちが解除されたら unk_05 を 10 にして, unk_07 が立っていたら state 12 へ進む
void FUN_08043c94(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 10;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 12);
    node->unk_08 = 1;
  }

  node->timer++;
}

// 待ちが解除されたら unk_05 を 11 にして, unk_07 が立っていたら state 14 へ進む
void FUN_08043cc4(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 11;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 14);
    node->unk_08 = 1;
  }

  node->timer++;
}

NAKED void FUN_08043cf4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043cf4.inc"); }

NAKED void FUN_08043da8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043da8.inc"); }

NAKED void FUN_08043e54(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08043e54.inc"); }

NAKED s32 Entity286F_Update(Entity286F* p) { INCFUNC("asm/func/Entity286F_Update.inc"); }

s32 Entity286F_Destroy(Entity286F* p) {
  Entity286FNode* node = p->head;

  while (node != NULL) {
    Entity286FNode* next = node->next;

    if (node->onDestroy != NULL) {
      node->onDestroy(p, node);
    }
    FUN_0804114c(node);
    node = next;
  }

  gEntity286F = NULL;
  return 0;
}

s32 Entity286F_Init(Entity286F* p) {
  Player* pl;

  gEntity286F = p;
  p->frameCount = 0;
  p->head = NULL;
  p->unk_28 = 0;
  p->unk_2c[0] = 0;
  p->unk_2c[1] = 0;
  pl = gPlayerPtr[0];
  p->player = pl;
  if (pl != NULL) {
    p->playerPos = &pl->mover.pos;
  } else {
    p->playerPos = NULL;
  }
  return 0;
}

Entity286F* Entity286F_Create(void) {
  if (gEntity286F == NULL) {
    Entity286F* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity286F));

    if (p != NULL) {
      SetEntityRoutine(p, Entity286F_Update, Entity286F_Destroy);
      if (Entity286F_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity286F;
}

void FUN_080440ac(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 2;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080440d0(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 3;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 4 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08044104(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 4;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

void FUN_08044138(Entity286F* p, Entity286FNode* node) {
  static void (*const PTR_ARRAY_085ab36c[3])(Entity286F*, Entity286FNode*) = {
      FUN_080440ac,
      FUN_080440d0,
      FUN_08044104,
  };  // 0x085AB36C
  PTR_ARRAY_085ab36c[node->state](p, node);
}

void FUN_08044150(Entity286F* p, Entity286FNode* node) { FUN_08044138(p, node); }

s32 FUN_0804415c(Entity286F* p, Entity286FNode* node) {
  FUN_08044150(p, node);
  return 0;
}

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08044168(Entity286FNode* node) {
  static void (*const PTR_ARRAY_085ab378[14])(Entity286F*, Entity286FNode*, s32) = {
      NULL,
      FUN_08042178,
      FUN_080421bc,
      FUN_08042200,
      FUN_0804234c,
      FUN_08042414,
      FUN_08042638,
  };  // 0x085AB378

  Entity286FNodeUpdate* fn;

  if (node->unk_05 == 0 || node->unk_05 > 14) {  // 本来は >= 14 と書くべきものと思われる...
    return 0;
  }

  fn = PTR_ARRAY_085ab378[node->unk_05];
  node->unk_06 = node->unk_05;
  node->unk_2cc = fn;
  node->unk_10 = 0;
  node->unk_09 = 1;
  node->unk_18 = 0;
  return 1;
}

// ノードの待ちを解除して unk_2cc を呼ぶ
s32 FUN_080441a4(Entity286F* p, Entity286FNode* node) {
  u32 elapsed;

  node->flags = 0;
  node->unk_07 = 0;
  elapsed = node->unk_10++;

  if (node->unk_2cc != NULL) {
    node->unk_2cc(p, node, elapsed);
  }

  return 0;
}

NAKED void FUN_080441d8(Entity286FNode* node) { INCFUNC("asm/func/FUN_080441d8.inc"); }

s32 FUN_080442d4(Entity286F* p, Entity286FNode* node) {
  FUN_080441d8(node);
  FUN_080411d8(p, node);
  node->unk_05 = 0;
  return 0;
}

s32 FUN_080442f4(Entity286F* p, Entity286FNode* node) {
  FUN_080412fc(p, node);
  return 0;
}

s32 FUN_08044300(Entity286F* p, Entity286FNode* node) { return MsgQueue_Unregister(&node->mq); }

// 0x920F, Unused?
NAKED void Cmd_920F(void) { INCFUNC("asm/func/Cmd_920F.inc"); }

void FUN_0804454c(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 2 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08044570(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 2;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080445a4(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 3;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

void FUN_080445d8(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 4;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 5 にして, unk_07 が立っていたら state 5 に移してメッセージの待ちを終える
void FUN_080445fc(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 5;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 5);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

void FUN_08044634(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08 != 0) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 6;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 7 にして, unk_07 が立っていたら state 7 に移してメッセージの待ちを終える
void FUN_08044658(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 7;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 7);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 8 にしてメッセージの待ちを終える
void FUN_08044690(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 8;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 9 にしてメッセージの待ちを終える
void FUN_080446b4(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 9;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 10 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080446d8(Entity286F* p, Entity286FNode* node) {
  if (node->unk_08) {
    node->unk_08 = 0;
    node->unk_07 = 0;
    node->unk_05 = 10;
  }

  if (node->unk_07) {
    Entity286FNode_SetState(node, 0);
    node->unk_08 = 1;
    MsgQueue_EndWait(&node->mq, 1);
  }
}

void FUN_0804470c(Entity286F* p, Entity286FNode* node) {
  static void (*const PTR_ARRAY_085ab3b0[10])(Entity286F*, Entity286FNode*) = {
      FUN_0804454c,
      FUN_08044570,
      FUN_080445a4,
      FUN_080445d8,
      FUN_080445fc,
      FUN_08044634,
      FUN_08044658,
      FUN_08044690,
      FUN_080446b4,
      FUN_080446d8,
  };  // 0x085AB3B0
  PTR_ARRAY_085ab3b0[node->state](p, node);
}

void FUN_08044724(Entity286F* p, Entity286FNode* node) { FUN_0804470c(p, node); }

s32 FUN_08044730(Entity286F* p, Entity286FNode* node) {
  FUN_08044724(p, node);
  return 0;
}

void FUN_0804473c(Entity286F* p, Entity286FNode* node, s32 elapsed) {
  if (node->unk_09 != 0) {
    node->unk_09 = 0;
    node->unk_07 = 0;
    FUN_08041480(node, 0, 1, 0, 4);
  }
  if ((u8)node->fn(node) != 1) {
    FUN_08041480(node, 0, 1, 0, 1);
  }
}

NAKED void FUN_0804478c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0804478c.inc"); }

NAKED void FUN_080448c8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_080448c8.inc"); }

NAKED void FUN_0804494c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0804494c.inc"); }

NAKED void FUN_080449c0(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_080449c0.inc"); }

void FUN_08044a54(Entity286F* p, Entity286FNode* node, s32 _) {
  if (node->unk_09) {
    node->unk_09 = 0;
    node->unk_07 = 0;
    FUN_08041480(node, 7, 2, 0, 1);
    node->unk_20 = 0;
  }
  node->fn(node);
}

NAKED void FUN_08044a90(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08044a90.inc"); }

void FUN_08044d9c(Entity286F* p, Entity286FNode* node, s32 _) {
  if (node->unk_09) {
    node->unk_09 = 0;
    node->unk_07 = 0;
    FUN_08041480(node, 7, 2, 0, 4);
    node->unk_20 = 0;
  }

  node->fn(node);
}

NAKED void FUN_08044dd8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08044dd8.inc"); }

NAKED void FUN_08044e6c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08044e6c.inc"); }

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08044ee0(Entity286FNode* node) {
  static void (*const PTR_ARRAY_085ab3d8[11])(Entity286F*, Entity286FNode*, s32) = {
      NULL,
      FUN_0804473c,
      FUN_0804478c,
      FUN_080448c8,
      FUN_0804494c,
      FUN_080449c0,
      FUN_08044a54,
      FUN_08044a90,
      FUN_08044d9c,
      FUN_08044dd8,
      FUN_08044e6c,
  };  // 0x085AB3D8

  Entity286FNodeUpdate* fn;

  if (node->unk_05 == 0 || node->unk_05 > 11) {  // 本来は >= 11 と書くべきものと思われる...
    return 0;
  }

  fn = PTR_ARRAY_085ab3d8[node->unk_05];
  node->unk_06 = node->unk_05;
  node->unk_2cc = fn;
  node->unk_10 = 0;
  node->unk_09 = 1;
  node->unk_18 = 0;
  return 1;
}

// ノードの待ちを解除して unk_2cc を呼ぶ
s32 FUN_08044f1c(Entity286F* p, Entity286FNode* node) {
  s32 elapsed;

  node->flags = 0;
  node->unk_07 = 0;
  elapsed = node->unk_10++;

  if (node->unk_2cc != NULL) {
    node->unk_2cc(p, node, elapsed);
  }

  return 0;
}

NAKED void FUN_08044f50(Entity286FNode* node) { INCFUNC("asm/func/FUN_08044f50.inc"); }

s32 FUN_08045088(Entity286F* p, Entity286FNode* node) {
  FUN_08044f50(node);
  FUN_080411d8(p, node);
  node->unk_05 = 0;
  return 0;
}

s32 FUN_080450a8(Entity286F* p, Entity286FNode* node) {
  FUN_080412fc(p, node);
  return 0;
}

s32 FUN_080450b4(Entity286F* p, Entity286FNode* node) { return MsgQueue_Unregister(&node->mq); }

// 0x0E7C
NAKED void Cmd_0E7C(void) { INCFUNC("asm/func/Cmd_0E7C.inc"); }
