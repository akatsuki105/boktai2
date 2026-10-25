#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "vm.h"

// 衝突マップのノード (MapTileOverride) を id 付きで持つラッパ, id を指定して一括で消したり、 登録を外したり (Entity08004fac_DisableNodesById) 戻したり (同 Enable) できる
typedef struct Entity08004facNode {
  u16 id;                           // 0x00, 一括で操作するためのキー
  bool8 active;                     // 0x02, 1 なら tileOverride を衝突マップへ登録済み
  u8 unk_3;                         // 0x03, Entity08004fac_AddNode の第3引数, SetNodeParamsById が書き換える
  u8 stairs;                        // 0x04, Map_AddTileOverride の第3引数
  u8 height;                        // 0x05, Map_AddTileOverride の第4引数
  u16 attr;                         // 0x06, Map_AddTileOverride の第6引数
  u16 tileIdx;                      // 0x08, gCollisionMap->rowOffsets[y] + x
  u8 unk_a[0x0C - 0x0A];            // 0x0A, padding?
  MapTileOverride tileOverride;     // 0x0C, Map_AddTileOverride / Map_RemoveTileOverride に渡す
  struct Entity08004facNode* prev;  // 0x1C
  struct Entity08004facNode* next;  // 0x20
} Entity08004facNode;
static_assert(sizeof(Entity08004facNode) == 36);

typedef struct {
  Entity e;                  // 0x00, ENTITY_UNK_8
  Entity08004facNode* head;  // 0x18, ノードの双方向リストの先頭, Init が NULL、LinkNode が先頭挿入する
} Entity08004fac;
static_assert(sizeof(Entity08004fac) == 28);

Entity08004fac* Entity08004fac_Create(u32 param_1, u32 param_2);

IWRAM_DATA Entity08004fac* gEntity08004fac = NULL;  // 0x03000024

void FUN_08004c78(void) { gEntity08004fac = NULL; }

s32 Entity08004fac_LinkNode(Entity08004facNode* node) {
  node->prev = NULL;
  node->next = gEntity08004fac->head;

  if (node->next != NULL) {
    node->next->prev = node;
  }

  gEntity08004fac->head = node;
  return 0;
}

s32 Entity08004fac_UnlinkNode(Entity08004facNode* node) {
  Entity08004facNode* prev = node->prev;
  Entity08004facNode* next = node->next;

  if (prev != NULL) {
    prev->next = next;
  } else {
    gEntity08004fac->head = next;
  }

  if (next != NULL) {
    next->prev = prev;
  }

  return 0;
}

// id 付きのノードを作って衝突マップへ登録する
s32 Entity08004fac_AddNode(s32 id, Vec3* pos, s32 unk_3, s32 stairs, s32 attr) {
  Entity08004facNode* node;
  s32 bx;
  s32 bz;
  s32 idx;

  if (gEntity08004fac == NULL) {
    if (Entity08004fac_Create(0x2153, 0) == NULL) {
      return 0;
    }
  }

  node = Malloc(sizeof(Entity08004facNode));
  if (node == NULL) {
    return -1;
  }

  ClearMemory(node, sizeof(Entity08004facNode));
  node->id = id;
  node->active = TRUE;
  node->unk_3 = unk_3;
  node->stairs = stairs;

  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  node->tileIdx = idx;

  node->height = FixToInt(8, pos->y);
  node->attr = attr;
  Map_AddTileOverride(&node->tileOverride, node->tileIdx, node->stairs, node->height, 0xFF, node->attr);
  Entity08004fac_LinkNode(node);
  return 0;
}

// 衝突マップから外してリストから抜き、ノードを解放する
s32 Entity08004fac_FreeNode(Entity08004facNode* node) {
  if (node->active) {
    Map_RemoveTileOverride(&node->tileOverride);
    node->active = FALSE;
  }

  if (gEntity08004fac != NULL) {
    Entity08004fac_UnlinkNode(node);
  }

  Free(node);
  return 0;
}

s32 Entity08004fac_FreeAllNodes(void) {
  Entity08004facNode* node;

  if (gEntity08004fac == NULL) return -1;

  node = gEntity08004fac->head;
  while (node != NULL) {
    Entity08004facNode* next = node->next;

    Entity08004fac_FreeNode(node);
    node = next;
  }

  return 0;
}

// id が一致するノードをすべて解放する
s32 Entity08004fac_FreeNodesById(u16 id) {
  Entity08004facNode* node;

  if (gEntity08004fac == NULL) {
    return -1;
  }

  node = gEntity08004fac->head;
  while (node != NULL) {
    Entity08004facNode* next = node->next;

    if (node->id == id) {
      Entity08004fac_FreeNode(node);
    }
    node = next;
  }
  return 0;
}

// id が一致するノードを衝突マップから外す
s32 Entity08004fac_DisableNodesById(u16 id) {
  Entity08004fac* p = gEntity08004fac;
  Entity08004facNode* node;

  if (p == NULL) {
    return -1;
  }

  node = p->head;
  while (node != NULL) {
    Entity08004facNode* next = node->next;

    if (node->id == id && node->active) {
      node->active = FALSE;
      Map_RemoveTileOverride(&node->tileOverride);
    }
    node = next;
  }
  return 0;
}

// id が一致するノードを衝突マップへ戻す
s32 Entity08004fac_EnableNodesById(u16 id) {
  Entity08004fac* p = gEntity08004fac;
  Entity08004facNode* node;

  if (p == NULL) {
    return -1;
  }

  node = p->head;
  while (node != NULL) {
    Entity08004facNode* next = node->next;

    if (node->id == id && !node->active) {
      node->active = TRUE;
      Map_AddTileOverride(&node->tileOverride, node->tileIdx, node->stairs, node->height, 0xFF, node->attr);
    }
    node = next;
  }
  return 0;
}

// id が一致するノードのパラメータを差し替える, -1 を渡した項目は変えない
s32 Entity08004fac_SetNodeParamsById(s32 id, s32 stairs, s32 unk_3, s32 attr, s32 tileIdx, s32 height) {
  Entity08004fac* p = gEntity08004fac;
  Entity08004facNode* node;

  if (p == NULL) {
    return -1;
  }

  node = p->head;
  while (node != NULL) {
    Entity08004facNode* next = node->next;

    if (node->id == id) {
      if (unk_3 != -1) {
        node->unk_3 = unk_3;
      }
      if (stairs != -1) {
        node->stairs = stairs;
      }
      if (tileIdx != -1) {
        node->tileIdx = tileIdx;
      }
      if (height != -1) {
        node->height = height;
      }
      if (attr != -1) {
        node->attr = attr;
      }
      Map_InitTileOverride(&node->tileOverride, node->tileIdx, node->stairs, node->height, 0xFF, node->attr);
    }
    node = next;
  }
  return 0;
}

s32 Entity08004fac_Update(Entity08004fac* p) { return 0; }

s32 Entity08004fac_Destroy(Entity08004fac* p) {
  Entity08004fac_FreeAllNodes();
  gEntity08004fac = NULL;
  return 0;
}

s32 Entity08004fac_Init(Entity08004fac* p, u32 param_2) {
  gEntity08004fac = p;
  p->head = NULL;
  return 0;
}

Entity08004fac* Entity08004fac_Create(u32 param_1, u32 param_2) {
  Entity08004fac* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity08004fac));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08004fac_Update, Entity08004fac_Destroy);
    if (Entity08004fac_Init(p, param_1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// 0x3E1F
s32 Cmd_3E1F(void) { return Entity08004fac_FreeNodesById(VM_GetNamedArgValue('n', 0)); }

// 0x8153, '.n' が指すノードを衝突マップから外す
s32 FUN_08005004(void) { return Entity08004fac_DisableNodesById(VM_GetNamedArgValue('n', 0)); }

// 0xF0CC, '.n' が指すノードを衝突マップへ戻す
s32 FUN_0800501c(void) { return Entity08004fac_EnableNodesById(VM_GetNamedArgValue('n', 0)); }

// 0xB8C7
// 残差3命令 (101/104). 原典は4つの VM 値を r8/r7/r6/r5 の低位レジスタに収めるが, こちらは r10/r9 を使った上に id をスタックへ退避してしまう
// 宣言と代入を分けても変化なし (101)
NON_MATCH s32 FUN_08005034(void) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id = VM_GetNamedArgValue('n', -1);
  s32 stairs = VM_GetNamedArgValue('t', -1);
  s32 unk_3 = VM_GetNamedArgValue('f', -1);
  s32 attr = VM_GetNamedArgValue('e', -1);
  s32 tileIdx;
  s32 height;

  if (VM_SeekToNamedArg('p')) {
    s32 bx;
    s32 bz;

    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();

    bx = (s8)(pos.x >> 8);
    bz = (s8)(pos.z >> 8);
    if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
      tileIdx = 0;
    } else {
      tileIdx = gCollisionMap->rowOffsets[bz] + bx;
    }
    height = FixToInt(8, pos.y);
  } else {
    height = -1;
    tileIdx = -1;
  }

  return Entity08004fac_SetNodeParamsById(id, stairs, unk_3, attr, tileIdx, height);
#else
  INCFUNC("asm/func/FUN_08005034.inc");
#endif
}

// 0xFEBB
s32 FUN_0800512c(void) {
  Vec3 pos;
  s32 id = VM_GetNamedArgValue('n', 0);
  s32 stairs = VM_GetNamedArgValue('t', 0);
  s32 unk_3 = VM_GetNamedArgValue('f', 0);
  s32 attr = VM_GetNamedArgValue('e', 0);

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }

  Entity08004fac_AddNode(id, &pos, unk_3, stairs, attr);
  return 0;
}
