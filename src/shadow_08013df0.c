#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "shadow.h"
#include "sprite.h"
#include "vm.h"

// スクリプトから ID を指定して置く影, ScriptShadowManager がリストで管理する
typedef struct ScriptShadow {
  u16 id;                     // 0x00, ScriptShadowManager_Find がこの値で探す, ScriptShadow_Create でスクリプトの値をセット
  u8 mode;                    // 0x02, 0 ならリスト外 (ScriptShadowManager_Add で 1, ScriptShadowManager_Remove で 0), ScriptShadow_Create / ScriptShadow_SetMode がスクリプトの値を入れ 1 なら ParticleShadow_Show, 2 なら ParticleShadow_Hide
  u8 unk_03;                  // 0x03
  Vec3 pos;                   // 0x04, 影を置く座標, ScriptShadow_Create / ScriptShadow_Move がコピーし、shadow の持ち主座標として渡す
  ParticleShadow shadow;      // 0x0C, 根拠: ParticleShadow_Init / ParticleShadow_Remove
  struct ScriptShadow* prev;  // 0x4C
  struct ScriptShadow* next;  // 0x50
} ScriptShadow;
static_assert(sizeof(ScriptShadow) == 84);  // 根拠: ScriptShadow_Create の Malloc(0x54)

typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_9
  ScriptShadow* shadows;  // 0x18, 影のリストの先頭, Init で 0, ScriptShadowManager_Add / ScriptShadowManager_Remove / ScriptShadowManager_Find / Destroy
} ScriptShadowManager;
static_assert(sizeof(ScriptShadowManager) == 28);

COMMON_DATA ScriptShadowManager* gScriptShadowManager = NULL;  // 0x03002B40

ScriptShadowManager* ScriptShadowManager_Create(void);

// 管理エンティティを返す (なければ作る)
ScriptShadowManager* ScriptShadowManager_Get(void) {
  ScriptShadowManager* p = gScriptShadowManager;
  if (p == NULL) {
    p = ScriptShadowManager_Create();
  }
  return p;
}

// ID が一致する影を探す (なければ NULL)
ScriptShadow* ScriptShadowManager_Find(ScriptShadowManager* p, u32 id) {
  ScriptShadow* shadow;

  for (shadow = p->shadows; shadow != NULL; shadow = shadow->next) {
    if (shadow->id == id) return shadow;
  }
  return NULL;
}

// 影のリストの先頭に繋ぐ
s32 ScriptShadowManager_Add(ScriptShadowManager* p, ScriptShadow* shadow) {
  ScriptShadow* head;

  if (shadow->mode != 0) return -1;

  shadow->prev = NULL;
  head = p->shadows;
  shadow->next = head;
  if (head != NULL) {
    head->prev = shadow;
  }
  p->shadows = shadow;
  shadow->mode = 1;
  return 0;
}

// 影のリストから外す
s32 ScriptShadowManager_Remove(ScriptShadowManager* p, ScriptShadow* shadow) {
  ScriptShadow* prev = shadow->prev;
  ScriptShadow* next = shadow->next;

  if (shadow->mode == 0) return -1;

  if (prev != NULL) {
    prev->next = next;
  } else {
    p->shadows = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  shadow->mode = 0;
  return 0;
}

s32 ScriptShadowManager_Update(ScriptShadowManager* _) { return 0; }

// 残っている影をすべて外して解放する
s32 ScriptShadowManager_Destroy(ScriptShadowManager* p) {
  ScriptShadow* shadow = p->shadows;
  ScriptShadow* next;

  while (shadow != NULL) {
    next = shadow->next;
    ParticleShadow_Remove(&shadow->shadow);
    ScriptShadowManager_Remove(p, shadow);
    Free(shadow);
    shadow = next;
  }
  p->shadows = NULL;
  gScriptShadowManager = NULL;
  return 0;
}

s32 ScriptShadowManager_Init(ScriptShadowManager* p) {
  gScriptShadowManager = p;
  p->shadows = NULL;
  return 0;
}

ScriptShadowManager* ScriptShadowManager_Create(void) {
  ScriptShadowManager* p;

  if (gScriptShadowManager != NULL) return gScriptShadowManager;

  p = CreateEntity(ENTITY_UNK_9, sizeof(ScriptShadowManager));
  if (p != NULL) {
    SetEntityRoutine(p, ScriptShadowManager_Update, ScriptShadowManager_Destroy);
    if (ScriptShadowManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// ID を指定して影を作り、座標に置いてリストに繋ぐ (同じ ID があれば失敗)
s32 ScriptShadow_Create(u32 id, s32 mode, Vec3* pos) {
  ScriptShadowManager* mgr;
  ScriptShadow* shadow;
  Vec3* dst;

  mgr = ScriptShadowManager_Get();
  if (mgr == NULL) return -1;
  if (ScriptShadowManager_Find(mgr, id) != NULL) return -1;
  shadow = Malloc(sizeof(ScriptShadow));
  if (shadow == NULL) return -1;

  ClearMemory(shadow, sizeof(ScriptShadow));
  shadow->id = id;
  dst = &shadow->pos;
  shadow->pos = *pos;
  if (ParticleShadow_Init(&shadow->shadow, dst, mode == 2) >= 0 && ScriptShadowManager_Add(mgr, shadow) >= 0) {
    shadow->mode = mode;
    return 0;
  }
  Free(shadow);
  return -1;
}

// スクリプト命令: n=ID, m=モード, p=座標 で影を作る
s32 ScriptShadow_CreateFromScript(void) {
  s32 id = VM_GetKeywordValue('n', 0);
  s32 mode = VM_GetKeywordValue('m', 1);
  Vec3 pos;

  if (VM_SeekToKeyword('p')) {
    pos.x = Script_GetValue();
    pos.y = Script_GetValue();
    pos.z = Script_GetValue();
    return ScriptShadow_Create(id, mode, &pos);
  }
  return -1;
}

// ID の影を外して解放する
s32 ScriptShadow_Delete(u32 id) {
  ScriptShadowManager* mgr;
  ScriptShadow* shadow;

  mgr = ScriptShadowManager_Get();
  if (mgr == NULL) return -1;
  shadow = ScriptShadowManager_Find(mgr, id);
  if (shadow == NULL) return -1;

  ParticleShadow_Remove(&shadow->shadow);
  ScriptShadowManager_Remove(mgr, shadow);
  Free(shadow);
  return 0;
}

s32 ScriptShadow_DeleteFromScript(void) { return ScriptShadow_Delete(VM_GetKeywordValue('n', 0)); }

// ID の影のモードを変える (1 なら表示、2 なら非表示)
s32 ScriptShadow_SetMode(u32 id, s32 mode) {
  ScriptShadowManager* mgr = ScriptShadowManager_Get();
  ScriptShadow* shadow;

  if (mgr == NULL || (shadow = ScriptShadowManager_Find(mgr, id)) == NULL) return -1;

  shadow->mode = mode;
  if ((u8)mode == 1) {
    ParticleShadow_Show(&shadow->shadow);
  } else if ((u8)mode == 2) {
    ParticleShadow_Hide(&shadow->shadow);
  }
  return 0;
}

// スクリプト命令: n=ID, m=モード で影のモードを変える
s32 ScriptShadow_SetModeFromScript(void) {
  s32 id = VM_GetKeywordValue('n', 0);
  s32 mode = VM_GetKeywordValue('m', 1);
  return ScriptShadow_SetMode(id, mode);
}

// ID の影を別の座標に移す
s32 ScriptShadow_Move(u32 id, Vec3* pos) {
  ScriptShadowManager* mgr = ScriptShadowManager_Get();
  ScriptShadow* shadow;

  if (mgr != NULL && (shadow = ScriptShadowManager_Find(mgr, id)) != NULL) {
    shadow->pos = *pos;
    return 0;
  }
  return -1;
}

// スクリプト命令: n=ID, p=座標 で影を移す
s32 ScriptShadow_MoveFromScript(void) {
  s32 id = VM_GetKeywordValue('n', 0);
  Vec3 pos;

  if (VM_SeekToKeyword('p')) {
    pos.x = Script_GetValue();
    pos.y = Script_GetValue();
    pos.z = Script_GetValue();
    return ScriptShadow_Move(id, &pos);
  }
  return -1;
}
