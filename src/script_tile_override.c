#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "map_inline.h"
#include "vm.h"

// スクリプトから MapTileOverride を操作するための窓口
// Cコードはこれを使わず、 自前で MapTileOverride を持って、 Map_AddTileOverride などを叩く

// 衝突マップのノード (MapTileOverride) を id 付きで持つラッパ, id を指定して一括で消したり、 登録を外したり (ScriptTileOverrideManager_DisableById) 戻したり (同 Enable) できる
typedef struct ScriptTileOverrideNode {
  u16 id;                         // 0x00, 一括で操作するためのキー
  bool8 active;                   // 0x02, 1 なら tileOverride を衝突マップへ登録済み
  u8 unk_3;                       // 0x03, ScriptTileOverrideManager_Add の第3引数, ScriptTileOverrideManager_SetParamsById が書き換える
  u8 stairs;                      // 0x04, Map_AddTileOverride の第3引数
  u8 height;                      // 0x05, Map_AddTileOverride の第4引数
  u16 attr;                       // 0x06, Map_AddTileOverride の第6引数
  u16 tileIdx;                    // 0x08, gCollisionMap->rowOffsets[y] + x
  u8 _[2];                        // 0x0A, padding
  MapTileOverride tileOverride;   // 0x0C, Map_AddTileOverride / Map_RemoveTileOverride に渡す
  struct ScriptTileOverrideNode* prev;  // 0x1C
  struct ScriptTileOverrideNode* next;  // 0x20
} ScriptTileOverrideNode;
static_assert(sizeof(ScriptTileOverrideNode) == 36);

typedef struct {
  Entity e;                // 0x00, ENTITY_UNK_8
  ScriptTileOverrideNode* head;  // 0x18, ノードの双方向リストの先頭, Init が NULL、ScriptTileOverrideManager_Link が先頭挿入する
} ScriptTileOverrideManager;
static_assert(sizeof(ScriptTileOverrideManager) == 28);

ScriptTileOverrideManager* ScriptTileOverrideManager_Create(u32 id, u32 _);

static ScriptTileOverrideManager* sScriptTileOverrideManager;  // 0x03000024

void ScriptTileOverrideManager_ClearGlobal(void) { sScriptTileOverrideManager = NULL; }

s32 ScriptTileOverrideManager_Link(ScriptTileOverrideNode* node) {
  node->prev = NULL;
  node->next = sScriptTileOverrideManager->head;

  if (node->next != NULL) {
    node->next->prev = node;
  }

  sScriptTileOverrideManager->head = node;
  return 0;
}

s32 ScriptTileOverrideManager_Unlink(ScriptTileOverrideNode* node) {
  ScriptTileOverrideNode* prev = node->prev;
  ScriptTileOverrideNode* next = node->next;

  if (prev != NULL) {
    prev->next = next;
  } else {
    sScriptTileOverrideManager->head = next;
  }

  if (next != NULL) {
    next->prev = prev;
  }

  return 0;
}

// id 付きのノードを作って衝突マップへ登録する
s32 ScriptTileOverrideManager_Add(s32 id, Vec3* pos, s32 unk_3, s32 stairs, s32 attr) {
  ScriptTileOverrideNode* node;

  if (sScriptTileOverrideManager == NULL) {
    if (ScriptTileOverrideManager_Create(0x2153, 0) == NULL) {
      return 0;
    }
  }

  node = Malloc(sizeof(ScriptTileOverrideNode));
  if (node == NULL) {
    return -1;
  }

  ClearMemory(node, sizeof(ScriptTileOverrideNode));
  node->id = id;
  node->active = TRUE;
  node->unk_3 = unk_3;
  node->stairs = stairs;
  node->tileIdx = GetCollisionTileIdx(pos);
  node->height = FixToInt(8, pos->y);
  node->attr = attr;
  Map_AddTileOverride(&node->tileOverride, node->tileIdx, node->stairs, node->height, 0xFF, node->attr);
  ScriptTileOverrideManager_Link(node);
  return 0;
}

// 衝突マップから外してリストから抜き、ノードを解放する
s32 ScriptTileOverrideManager_Free(ScriptTileOverrideNode* node) {
  if (node->active) {
    Map_RemoveTileOverride(&node->tileOverride);
    node->active = FALSE;
  }

  if (sScriptTileOverrideManager != NULL) {
    ScriptTileOverrideManager_Unlink(node);
  }

  Free(node);
  return 0;
}

s32 ScriptTileOverrideManager_FreeAll(void) {
  ScriptTileOverrideNode* node;

  if (sScriptTileOverrideManager == NULL) return -1;

  node = sScriptTileOverrideManager->head;
  while (node != NULL) {
    ScriptTileOverrideNode* next = node->next;

    ScriptTileOverrideManager_Free(node);
    node = next;
  }

  return 0;
}

// id が一致するノードをすべて解放する
s32 ScriptTileOverrideManager_FreeById(u16 id) {
  ScriptTileOverrideNode* node;

  if (sScriptTileOverrideManager == NULL) {
    return -1;
  }

  node = sScriptTileOverrideManager->head;
  while (node != NULL) {
    ScriptTileOverrideNode* next = node->next;

    if (node->id == id) {
      ScriptTileOverrideManager_Free(node);
    }
    node = next;
  }
  return 0;
}

// id が一致するノードを衝突マップから外す
s32 ScriptTileOverrideManager_DisableById(u16 id) {
  ScriptTileOverrideManager* p = sScriptTileOverrideManager;
  ScriptTileOverrideNode* node;

  if (p == NULL) {
    return -1;
  }

  node = p->head;
  while (node != NULL) {
    ScriptTileOverrideNode* next = node->next;

    if (node->id == id && node->active) {
      node->active = FALSE;
      Map_RemoveTileOverride(&node->tileOverride);
    }
    node = next;
  }
  return 0;
}

// id が一致するノードを衝突マップへ戻す
s32 ScriptTileOverrideManager_EnableById(u16 id) {
  ScriptTileOverrideManager* p = sScriptTileOverrideManager;
  ScriptTileOverrideNode* node;

  if (p == NULL) {
    return -1;
  }

  node = p->head;
  while (node != NULL) {
    ScriptTileOverrideNode* next = node->next;

    if (node->id == id && !node->active) {
      node->active = TRUE;
      Map_AddTileOverride(&node->tileOverride, node->tileIdx, node->stairs, node->height, 0xFF, node->attr);
    }
    node = next;
  }
  return 0;
}

// id が一致するノードのパラメータを差し替える, -1 を渡した項目は変えない
s32 ScriptTileOverrideManager_SetParamsById(s32 id, s32 stairs, s32 unk_3, s32 attr, s32 tileIdx, s32 height) {
  ScriptTileOverrideManager* p = sScriptTileOverrideManager;
  ScriptTileOverrideNode* node;

  if (p == NULL) {
    return -1;
  }

  node = p->head;
  while (node != NULL) {
    ScriptTileOverrideNode* next = node->next;

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

s32 ScriptTileOverrideManager_Update(ScriptTileOverrideManager* p) { return 0; }

s32 ScriptTileOverrideManager_Destroy(ScriptTileOverrideManager* p) {
  ScriptTileOverrideManager_FreeAll();
  sScriptTileOverrideManager = NULL;
  return 0;
}

s32 ScriptTileOverrideManager_Init(ScriptTileOverrideManager* p, u32 id) {
  sScriptTileOverrideManager = p;
  p->head = NULL;
  return 0;
}

ScriptTileOverrideManager* ScriptTileOverrideManager_Create(u32 id, u32 _) {
  ScriptTileOverrideManager* p = CreateEntity(ENTITY_UNK_8, sizeof(ScriptTileOverrideManager));

  if (p != NULL) {
    SetEntityRoutine(p, ScriptTileOverrideManager_Update, ScriptTileOverrideManager_Destroy);
    if (ScriptTileOverrideManager_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// 0x3E1F
s32 Cmd_FreeTileOverrides(void) { return ScriptTileOverrideManager_FreeById(VM_GetNamedArgValue('n', 0)); }

// 0x8153, '.n' が指すノードを衝突マップから外す
s32 Cmd_DisableTileOverrides(void) { return ScriptTileOverrideManager_DisableById(VM_GetNamedArgValue('n', 0)); }

// 0xF0CC, '.n' が指すノードを衝突マップへ戻す
s32 Cmd_EnableTileOverrides(void) { return ScriptTileOverrideManager_EnableById(VM_GetNamedArgValue('n', 0)); }

// 0xB8C7
s32 Cmd_SetTileOverrideParams(void) {
  s32 id = VM_GetNamedArgValue('n', -1);
  s32 stairs = VM_GetNamedArgValue('t', -1);
  s32 unk_3 = VM_GetNamedArgValue('f', -1);
  s32 attr = VM_GetNamedArgValue('e', -1);
  s32 tileIdx, height;

  if (VM_SeekToNamedArg('p')) {
    Vec3 pos;
    pos.x = VM_GetValue(), pos.y = VM_GetValue(), pos.z = VM_GetValue();
    tileIdx = GetCollisionTileIdx(&pos);
    height = FixToInt(8, pos.y);
  } else {
    height = -1;
    tileIdx = -1;
  }

  return ScriptTileOverrideManager_SetParamsById(id, stairs, unk_3, attr, tileIdx, height);
}

// 0xFEBB
s32 Cmd_AddTileOverride(void) {
  Vec3 pos;
  s32 id = VM_GetNamedArgValue('n', 0);
  s32 stairs = VM_GetNamedArgValue('t', 0);
  s32 unk_3 = VM_GetNamedArgValue('f', 0);
  s32 attr = VM_GetNamedArgValue('e', 0);

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue(), pos.y = VM_GetValue(), pos.z = VM_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }

  ScriptTileOverrideManager_Add(id, &pos, unk_3, stairs, attr);
  return 0;
}
