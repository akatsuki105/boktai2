#include "hitbox.h"

#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;            // 0x0, ENTITY_UNK_11
  HitboxData* unk_18;  // 0x18
  HitboxData* unk_1c;  // 0x1C
  HitboxData* unk_20;  // 0x20
  HitboxData* unk_24;  // 0x24
  HitboxData data0;    // 0x28
  HitboxData data1;    // 0x78
  u16 unk_c8;          // 0xC8
  u16 unk_ca;          // 0xCA
} HitboxManager;
static_assert(sizeof(HitboxManager) == 204);

IWRAM_DATA HitboxManager* gHitboxManager = NULL;  // 0x03000780

// unk_18 のリストの末尾に p を繋ぐ。既に繋がっていれば何もしない
void FUN_08236388(HitboxData* p) {
  HitboxData* q;

  if (gHitboxManager == NULL) {
    return;
  }
  q = gHitboxManager->unk_18;
  while ((q = q->next) != NULL) {
    if (q == p) {
      return;
    }
  }
  gHitboxManager->unk_20->next = p;
  p->next = NULL;
  gHitboxManager->unk_20 = p;
  gHitboxManager->unk_c8++;
}

// unk_1c のリストの先頭に p を繋ぐ。既に繋がっていれば何もしない
NON_MATCH void FUN_082363c4(HitboxData* p) {
#ifdef NONMATCHING_C
  HitboxData* head;
  HitboxData* q;

  if (gHitboxManager == NULL) {
    return;
  }
  head = gHitboxManager->unk_1c;
  for (q = head->next; q != NULL; q = q->next) {
    if (q == p) {
      return;
    }
  }
  p->next = gHitboxManager->unk_1c->next;
  gHitboxManager->unk_1c->next = p;
  gHitboxManager->unk_ca++;
#else
  INCFUNC("asm/func/FUN_082363c4.inc");
#endif
}

void FUN_08236400(HitboxData* p) {
  if (p->flags & HBFLAG_UNK_13) {
    FUN_082363c4(p);
  } else {
    FUN_08236388(p);
  }
}

// unk_18 のリストから p を外す
void FUN_08236424(HitboxData* p) {
  HitboxData* prev;
  HitboxData* q;

  if (gHitboxManager == NULL) {
    return;
  }
  prev = gHitboxManager->unk_18;
  q = prev->next;
  if (q == NULL) {
    return;
  }
  do {
    if (q == p) {
      if (q == gHitboxManager->unk_20) {
        gHitboxManager->unk_20 = prev;
      }
      prev->next = q->next;
      gHitboxManager->unk_c8--;
      return;
    }
    prev = q;
    q = q->next;
  } while (q != NULL);
}

NAKED void FUN_0823646c(HitboxData* p, u32 param_2, u32 param_3, u32 param_4, u16 param_5, Vec3* size, Vec3* offset) { INCFUNC("asm/func/FUN_0823646c.inc"); }

void FUN_082364c4(HitboxData* p, Vec3* pos, u32 param_3) {
  p->vec3_c.x = pos->x;
  p->vec3_c.y = pos->y;
  p->vec3_c.z = pos->z;
  p->unk_8 = param_3;
}

void UNUSED FUN_082364d4(HitboxData* p, Vec3* param_2, Vec3* param_3, u32 param_4) {
  p->vec3_c = *param_2;
  p->vec3_14 = *param_3;
  p->unk_8 = param_4;
}

void FUN_082364f0(HitboxData* p, u16 param_2, u16 param_3) {
  p->unk_3c = param_2;
  p->unk_40 = param_3;
}

void FUN_082364f8(HitboxData* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
  p->unk_3c = param_2;
  p->unk_40 = param_3;
  p->unk_34 = param_4;
  p->unk_38 = param_5;
  p->unk_44 = param_6;
}

void FUN_08236514(HitboxData* p, u32 val1, u32 val2, u32 val3) {
  p->unk_3c = val1;
  p->unk_38 = val2;
  p->unk_34 = val3;
}

void FUN_0823651c(HitboxData* p, void* handler, void* owner) {
  p->fn = handler;
  p->owner = owner;
}

NAKED void FUN_08236524(HitboxData* a, HitboxData* b) { INCFUNC("asm/func/FUN_08236524.inc"); }

NAKED void FUN_08236640(unknown* a, unknown* b) { INCFUNC("asm/func/FUN_08236640.inc"); }

NAKED void FUN_08236768(void* a, void* b, void* c) { INCFUNC("asm/func/FUN_08236768.inc"); }
NAKED void FUN_082367e4(void* a, void* b, void* c) { INCFUNC("asm/func/FUN_082367e4.inc"); }
NAKED bool32 FUN_082368d4(void* a, void* b, void* c, void* d, void* e) { INCFUNC("asm/func/FUN_082368d4.inc"); }
NAKED bool32 FUN_082369cc(void* a, void* b, void* c, void* d, void* e) { INCFUNC("asm/func/FUN_082369cc.inc"); }
NAKED bool32 Unused_FUN_08236ac4(void* a, void* b, void* c, void* d, void* e) { INCFUNC("asm/func/Unused_FUN_08236ac4.inc"); }
NAKED bool32 Unused_FUN_08236bbc(void* a, void* b, void* c, void* d) { INCFUNC("asm/func/Unused_FUN_08236bbc.inc"); }
NAKED bool32 Unused_FUN_08236c18(void* a, void* b) { INCFUNC("asm/func/Unused_FUN_08236c18.inc"); }

// 各 Hitbox の判定範囲を vec3_c + vec3_14 で更新する。unk_18 側は HBFLAG_UNK_2 が立っていれば飛ばす
void FUN_08236d10(void* unused1, void* unused2, HitboxData* unk_1c, HitboxData* unk_18) {
  HitboxData* p;
  HitboxData* q;
  HitboxData* p2;
  HitboxData* q2;

  q = unk_1c->next;
  if (q != NULL) {
    do {
      p = q;
      q = q->next;
      p->box.w = p->vec3_c.x + p->vec3_14.x;
      p->box.h = p->vec3_c.y + p->vec3_14.y;
      p->box.d = p->vec3_c.z + p->vec3_14.z;
    } while (q != NULL);
  }
  q2 = unk_18->next;
  if (q2 != NULL) {
    do {
      p2 = q2;
      q2 = q2->next;
      if (!(p2->flags & HBFLAG_UNK_2)) {
        p2->box.w = p2->vec3_c.x + p2->vec3_14.x;
        p2->box.h = p2->vec3_c.y + p2->vec3_14.y;
        p2->box.d = p2->vec3_c.z + p2->vec3_14.z;
      }
    } while (q2 != NULL);
  }
}

NAKED void Entity08236ed0_Update_Helper_08236d70(void* unused1, void* unused2, HitboxData* unk_1c, HitboxData* unk_18) { INCFUNC("asm/func/Entity08236ed0_Update_Helper_08236d70.inc"); }

NAKED s32 Entity08236ed0_Update(HitboxManager* p) { INCFUNC("asm/func/Entity08236ed0_Update.inc"); }

s32 Entity08236ed0_Destroy(HitboxManager* p) {
  gHitboxManager = NULL;
  return 0;
}

// なぜかこの Entity だけ 他の Entity_Init 関数とシグネチャが違う
void Entity08236ed0_Init(void) {
  HitboxManager* p = gHitboxManager;

  if (p != NULL) {
    p->unk_18 = &p->data0;
    p->unk_1c = &p->data1;
    p->data0.next = NULL;
    p->data1.next = NULL;
    p->unk_20 = &p->data0;
    p->unk_24 = &p->data1;
    p->unk_c8 = 0;
    p->unk_ca = 0;
  }
}

HitboxManager* Entity08236ed0_Create(void) {
  HitboxManager* p;

  if (gHitboxManager == NULL) {
    p = CreateEntity(ENTITY_UNK_11, sizeof(HitboxManager));
    if (p != NULL) {
      SetEntityRoutine(p, Entity08236ed0_Update, Entity08236ed0_Destroy);
      gHitboxManager = p;
      Entity08236ed0_Init();
    }
    return p;
  }
  return gHitboxManager;
}

HitboxManager* FUN_08236f0c(void) { return gHitboxManager; }

// AABBのOverlapを判定する関数
NON_MATCH bool32 Hitbox_CheckOverlap(HitboxData* a, HitboxData* b) {
#ifdef NONMATCHING_C
  bool32 ret;
  bool32 hit;
  s32 sum;

  ret = FALSE;
  sum = (s16)(a->box.x + b->box.x);
  hit = FALSE;
  if (a->box.w - sum <= b->box.w && b->box.w - sum <= a->box.w) {
    hit = TRUE;
  }
  if (hit) {
    sum = (s16)(a->box.y + b->box.y);
    hit = FALSE;
    if (a->box.h - sum <= b->box.h && b->box.h - sum <= a->box.h) {
      hit = TRUE;
    }
    if (hit) {
      sum = (s16)(a->box.z + b->box.z);
      hit = FALSE;
      if (a->box.d - sum <= b->box.d && b->box.d - sum <= a->box.d) {
        hit = TRUE;
      }
      if (hit) {
        ret = TRUE;
      }
    }
  }
  return ret;
#else
  INCFUNC("asm/func/Hitbox_CheckOverlap.inc");
#endif
}
