#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// リストに繋がれるノード, prev/next 以外はまだ未解析で全体の大きさも未確定
typedef struct Entity08016660Node {
  u8 unk_00;                        // 0x00, まだ未解析
  bool8 unk_01;                     // 0x01
  u8 fnIdx;                         // 0x02, PTR_ARRAY_085aa918 の添字
  u8 unk_03[0x06 - 0x03];           // 0x03, まだ未解析
  u16 timer;                        // 0x06, unk_08 を超えたら 0 に戻る
  u16 unk_08;                       // 0x08, timer の上限
  u8 unk_0a[0x78 - 0x0A];           // 0x0A, まだ未解析
  struct Entity08016660Node* prev;  // 0x78
  struct Entity08016660Node* next;  // 0x7C
} Entity08016660Node;

typedef struct {
  Entity e;                  // ENTITY_UNK_8
  AuxAnimFile* anim;         // 0x18, 根拠: Entity08016660_Init
  Entity08016660Node* list;  // 0x1C, FUN_08016094 が先頭挿入する双方向リスト
} Entity08016660;
static_assert(sizeof(Entity08016660) == 32);

static inline void Entity08016660Node_SetFn(Entity08016660Node* p, u32 idx) {
  p->fnIdx = idx;
  p->timer = 0;
}

COMMON_DATA Entity08016660* gEntity08016660 = NULL;  // 0x03002B44

void FUN_08016430(Entity08016660Node*);
void FUN_08016454(Entity08016660Node*);

void (*const PTR_ARRAY_085aa918[2])(Entity08016660Node*) = {
    FUN_08016430,
    FUN_08016454,
};  // 0x085AA918

void FUN_08016060(void) { gEntity08016660 = NULL; }

NAKED void FUN_0801606c(HitboxData* a, HitboxData* b, unknown* p) { INCFUNC("asm/func/FUN_0801606c.inc"); }

void nop_08016090(void) { return; }

// ノードをリストの先頭に繋ぐ
s32 FUN_08016094(Entity08016660* p, Entity08016660Node* node) {
  node->prev = NULL;
  node->next = p->list;
  if (node->next != NULL) {
    node->next->prev = node;
  }

  p->list = node;
  return 0;
}

// ノードをリストから外す
s32 FUN_080160b0(Entity08016660* p, Entity08016660Node* node) {
  Entity08016660Node* prev = node->prev;
  Entity08016660Node* next = node->next;

  if (prev != NULL) {
    prev->next = next;
  } else {
    p->list = next;
  }

  if (next != NULL) {
    next->prev = prev;
  }

  return 0;
}

NAKED s32 FUN_080160cc(Entity08016660Node* node) { INCFUNC("asm/func/FUN_080160cc.inc"); }

NAKED s32 FUN_08016110(u32 val1, u32 val2, u32 val3, u32 val4, Vec3* pos) { INCFUNC("asm/func/FUN_08016110.inc"); }

NAKED void UNUSED FUN_0801638c(void) { INCFUNC("asm/func/FUN_0801638c.inc"); }

// timer が上限を超えたら FUN_08016454 へ進める
void FUN_08016430(Entity08016660Node* p) {
  if (p->timer++ > p->unk_08) {
    Entity08016660Node_SetFn(p, 1);
    p->unk_01 = 1;
  }
}

NAKED void FUN_08016454(Entity08016660Node* p) { INCFUNC("asm/func/FUN_08016454.inc"); }

NAKED s32 Entity08016660_Update(Entity08016660* p) { INCFUNC("asm/func/Entity08016660_Update.inc"); }

s32 Entity08016660_Destroy(Entity08016660* p) {
  Entity08016660Node* node = p->list;

  while (node != NULL) {
    Entity08016660Node* next = node->next;

    FUN_080160cc(node);
    node = next;
  }

  gEntity08016660 = NULL;
  return 0;
}

s32 Entity08016660_Init(Entity08016660* p, u32 id) {
  gEntity08016660 = p;
  p->anim = GetFile(DIR_ANIMATION, ANIM_931E);
  p->list = NULL;
  return 0;
}

Entity08016660* Entity08016660_Create(u32 id) {
  Entity08016660* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity08016660));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08016660_Update, Entity08016660_Destroy);
    if (Entity08016660_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
