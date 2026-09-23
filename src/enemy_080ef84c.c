#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"

// Enemy の共通部分?

// EntityD854Node.flags (0x04)
typedef u8 EntityD854NodeFlags;
#define D854NODEFLAG_REGISTERED (1 << 0)  // FUN_080f8c58 が立てる
#define D854NODEFLAG_LINKED (1 << 1)      // enemy と紐付き中. FUN_080f8da4 が落とす

// EntityD854 のリストにぶら下がるノード。登録側 (Player など) の構造体に埋め込まれている
typedef struct EntityD854Node {
  Entity2UnkData* owner;        // 0x00, FUN_080f8c58 の第2引数. FUN_080f8d60 が owner->id で検索する
  EntityD854NodeFlags flags;    // 0x04
  u8 kindMask;                  // 0x05, FUN_080f8c58 の第3引数. FUN_080f9a38 は & で、FUN_080f8cf0 は == で引く
  u16 timer;                    // 0x06, FUN_080f9b34 が毎フレーム -1. FUN_080f8da4 が 0x78、FUN_080f8e3c が 0xF0 をセット
  Enemy* enemy;                 // 0x08, 紐付いた敵. FUN_080f8da4 が解除時に NULL にする
  struct EntityD854Node* next;  // 0x0C
} EntityD854Node;
static_assert(sizeof(EntityD854Node) == 16);

// gSubroutineTable の 0xD854 から生成されるシングルトン. 実体のポインタは gEntityD854 (0x03000184)
typedef struct {
  Entity e;              // 0x00, ENTITY_UNK_8
  u32 unk_18;            // 0x18, FUN_080f8c10 が 0 でクリアする
  s32 count;             // 0x1C, head のリストの登録数. 6件以上だと FUN_080f8c58 が登録を拒否する
  u32 unk_20;            // 0x20, EntityD854_Update が毎フレーム +1. FUN_080f8da4 は30フレームに1回だけ走る
  u16 unk_24;            // 0x24, EntityD854_Init が引数をそのまま書く
  u16 unk_26;            // 0x26, 読み手も書き手も未発見
  EntityD854Node* head;  // 0x28, 単方向リストの先頭
} EntityD854;
static_assert(sizeof(EntityD854) == 44);

extern EntityD854* gEntityD854;  // 0x03000184

bool32 FUN_0808672c(void);
s32 FUN_080fa958(Vec3* pos);
void FUN_080ee738(Enemy* p);
bool8 FUN_080f3718(Enemy* p);
s32 FUN_08240b98(u32 param_1, s8 param_2);
void FUN_080e8ae4(unknown* param_1, u32 param_2, u32 param_3);

NAKED void FUN_080ef84c(Enemy* p, s32 val1, s32 val2, s32 val3) { INCFUNC("asm/func/FUN_080ef84c.inc"); }

NAKED void FUN_080ef86c(Enemy* p, s32 val1) { INCFUNC("asm/func/FUN_080ef86c.inc"); }

NAKED void FUN_080ef968(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080ef968.inc"); }

NAKED void FUN_080efa6c(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080efa6c.inc"); }

NAKED void FUN_080efb60(Enemy* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080efb60.inc"); }

NAKED void FUN_080efc44(Enemy* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080efc44.inc"); }

NAKED void FUN_080efd44(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080efd44.inc"); }

NAKED void FUN_080efe38(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080efe38.inc"); }

NAKED void Enemy_080eff14(Enemy* enemy, s32 param_2) { INCFUNC("asm/func/Enemy_080eff14.inc"); }

NAKED void FUN_080f00ec(Enemy* p) { INCFUNC("asm/func/FUN_080f00ec.inc"); }

NAKED s32 FUN_080f0320(Enemy* p) { INCFUNC("asm/func/FUN_080f0320.inc"); }

NAKED s32 FUN_080f0430(Enemy* p) { INCFUNC("asm/func/FUN_080f0430.inc"); }

void FUN_080f06ac(void) {}

NAKED bool32 FUN_080f06b0(Enemy* p) { INCFUNC("asm/func/FUN_080f06b0.inc"); }

NAKED void FUN_080f07d0(Enemy* p) { INCFUNC("asm/func/FUN_080f07d0.inc"); }

NAKED void FUN_080f0868(Enemy* p) { INCFUNC("asm/func/FUN_080f0868.inc"); }

NAKED void FUN_080f0914(Enemy* p) { INCFUNC("asm/func/FUN_080f0914.inc"); }

void FUN_080f09a4(Enemy* p) {
  if ((FUN_080e8a60(p) == 0) && (Enemy_TestFlag(p, ENEFLAG_UNK_0) == 0) && (Enemy_TestFlag(p, ENEFLAG_UNK_1) != 0)) {
    FUN_080ee738(p);
    p->unk_11c = 0;
  }
}

void FUN_080f09e0(Enemy* p, u16* msg) {
  if (msg != NULL) {
    u32 idx = msg[0];
    EnemyMsgHandler* table = p->unk_60c;
    table[idx](p, msg);
  }
}

NAKED bool8 FUN_080f0a0c(Enemy* p) { INCFUNC("asm/func/FUN_080f0a0c.inc"); }

NAKED void FUN_080f0b3c(Enemy* p) { INCFUNC("asm/func/FUN_080f0b3c.inc"); }

NAKED void FUN_080f0e78(Enemy* p) { INCFUNC("asm/func/FUN_080f0e78.inc"); }

NAKED void FUN_080f11d0(Enemy* p) { INCFUNC("asm/func/FUN_080f11d0.inc"); }

NAKED void FUN_080f12c4(Enemy* p) { INCFUNC("asm/func/FUN_080f12c4.inc"); }

NAKED void FUN_080f19cc(Enemy* p) { INCFUNC("asm/func/FUN_080f19cc.inc"); }

NAKED void FUN_080f1c54(Enemy* p) { INCFUNC("asm/func/FUN_080f1c54.inc"); }

void FUN_080f1cb8(Enemy* p) {
  if (p->unk_46c != 0) {
    p->unk_46c = 0;
  }
  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_1)) {
    p->unk_484++;
  }
}

NAKED void FUN_080f1cf0(Enemy* p) { INCFUNC("asm/func/FUN_080f1cf0.inc"); }

void FUN_080f1de4(Enemy* p) {
  if (p->unk_46c != 0) {
    p->unk_46c = 0;
  }
  p->unk_484++;
}

NAKED void FUN_080f1e0c(Enemy* p) { INCFUNC("asm/func/FUN_080f1e0c.inc"); }

NAKED void FUN_080f1e78(Enemy* p) { INCFUNC("asm/func/FUN_080f1e78.inc"); }

NAKED void FUN_080f1ef8(Enemy* p) { INCFUNC("asm/func/FUN_080f1ef8.inc"); }

NAKED void FUN_080f2074(Enemy* p) { INCFUNC("asm/func/FUN_080f2074.inc"); }

NAKED void FUN_080f2160(Enemy* p) { INCFUNC("asm/func/FUN_080f2160.inc"); }

void FUN_080f2254(Enemy* p) {
  u32 idx = p->unk_46a;
  EnemyHandler* table = p->handlerTables[6];
  table[idx](p);
}

void FUN_080f2278(Enemy* p) {
  u32 idx = p->unk_46a;
  EnemyHandler* table = p->handlerTables[8];
  table[idx](p);
}

void FUN_080f229c(Enemy* p) {
  u32 idx = p->unk_469;
  EnemyHandler* table = p->handlerTables[9];
  table[idx](p);
}

void FUN_080f22c0(void) {}

void FUN_080f22c4(Enemy* p) {
  bool8 (*fn)(Enemy* p) = p->unk_608;
  if (fn(p) == 0) {
    FUN_080f0a0c(p);
  }
}

void FUN_080f22e8(Enemy* p) {
  u32 idx = p->unk_469;
  EnemyHandler* table = p->handlerTables[1];
  table[idx](p);
}

void FUN_080f230c(Enemy* p) {
  u32 idx = p->unk_469;
  EnemyHandler* table = p->handlerTables[5];
  table[idx](p);
}

void FUN_080f2330(Enemy* p) {
  if (FUN_080f3718(p)) {
    u32 idx = p->unk_469;
    EnemyHandler* table = p->handlerTables[7];
    table[idx](p);
  }
}

NAKED void FUN_080f2364(Enemy* p) { INCFUNC("asm/func/FUN_080f2364.inc"); }

NAKED void FUN_080f248c(Enemy* p) { INCFUNC("asm/func/FUN_080f248c.inc"); }

NAKED void FUN_080f2644(Enemy* p) { INCFUNC("asm/func/FUN_080f2644.inc"); }

NAKED void FUN_080f2864(Enemy* p) { INCFUNC("asm/func/FUN_080f2864.inc"); }

NAKED void FUN_080f2a40(Enemy* p) { INCFUNC("asm/func/FUN_080f2a40.inc"); }

NAKED void FUN_080f2d04(Enemy* p) { INCFUNC("asm/func/FUN_080f2d04.inc"); }

NAKED void FUN_080f2ec0(Enemy* p) { INCFUNC("asm/func/FUN_080f2ec0.inc"); }

NAKED void FUN_080f31c4(Enemy* p) { INCFUNC("asm/func/FUN_080f31c4.inc"); }

NAKED void FUN_080f33e8(Enemy* p) { INCFUNC("asm/func/FUN_080f33e8.inc"); }

void FUN_080f34a0(Enemy* p) {
  bool8 (*fn)(Enemy* p);

  if (p->unk_46c != 0) {
    p->unk_46c = 0;
  }
  fn = p->unk_608;
  if (fn(p) == 0) {
    if (FUN_080f0a0c(p) == 0) {
      p->unk_484++;
    }
  }
}

NAKED void FUN_080f34ec(Enemy* p) { INCFUNC("asm/func/FUN_080f34ec.inc"); }

NAKED void FUN_080f3574(Enemy* p) { INCFUNC("asm/func/FUN_080f3574.inc"); }

NAKED void FUN_080f35fc(Enemy* p) { INCFUNC("asm/func/FUN_080f35fc.inc"); }

NAKED void Enemy_Init_080f3680(Enemy* p) { INCFUNC("asm/func/Enemy_Init_080f3680.inc"); }

NAKED bool8 FUN_080f3718(Enemy* p) { INCFUNC("asm/func/FUN_080f3718.inc"); }

NON_MATCH void FUN_080f3cdc(Enemy* p) {
#ifdef NONMATCHING_C
  bool32 fired = FALSE;

  if (p->unk_46d != 0) {
    p->unk_46d = 0;
    fired = TRUE;
  }
  if (fired) {
    FUN_080ef86c(p, 0xB);
  }
  if (p->unk_46e != 0) {
    p->unk_46b = 1;
  }
#else
  INCFUNC("asm/func/FUN_080f3cdc.inc");
#endif
}

NAKED void FUN_080f3d28(Enemy* p) { INCFUNC("asm/func/FUN_080f3d28.inc"); }

NAKED void FUN_080f410c(Enemy* p) { INCFUNC("asm/func/FUN_080f410c.inc"); }

NAKED void FUN_080f44f4(Enemy* p) { INCFUNC("asm/func/FUN_080f44f4.inc"); }

NAKED void FUN_080f46a4(Enemy* p) { INCFUNC("asm/func/FUN_080f46a4.inc"); }

NAKED void FUN_080f47c8(Enemy* p) { INCFUNC("asm/func/FUN_080f47c8.inc"); }

NAKED bool32 FUN_080f48ac(Enemy* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080f48ac.inc"); }

NAKED void FUN_080f5208(Enemy* p) { INCFUNC("asm/func/FUN_080f5208.inc"); }

NAKED void FUN_080f54e4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f54e4.inc"); }

NAKED void FUN_080f56ec(Enemy* p) { INCFUNC("asm/func/FUN_080f56ec.inc"); }

NAKED void FUN_080f5b34(Enemy* p) { INCFUNC("asm/func/FUN_080f5b34.inc"); }

NAKED void FUN_080f5c0c(Enemy* p) { INCFUNC("asm/func/FUN_080f5c0c.inc"); }

NAKED void FUN_080f5fac(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f5fac.inc"); }

NAKED void FUN_080f624c(Enemy* p) { INCFUNC("asm/func/FUN_080f624c.inc"); }

void FUN_080f62a8(void) {}

s32 FUN_080f62ac(void) { return 0; }

NAKED s32 FUN_080f62b0(Enemy* p) { INCFUNC("asm/func/FUN_080f62b0.inc"); }

NAKED bool32 FUN_080f64f0(Enemy* p) { INCFUNC("asm/func/FUN_080f64f0.inc"); }

NAKED bool32 FUN_080f65a8(Enemy* p) { INCFUNC("asm/func/FUN_080f65a8.inc"); }

NAKED s32 FUN_080f6604(Enemy* p) { INCFUNC("asm/func/FUN_080f6604.inc"); }

NAKED s32 FUN_080f6868(Enemy* p) { INCFUNC("asm/func/FUN_080f6868.inc"); }

NAKED s32 FUN_080f6af0(Enemy* p) { INCFUNC("asm/func/FUN_080f6af0.inc"); }

NAKED Enemy* FUN_080f6bac(Enemy* p) { INCFUNC("asm/func/FUN_080f6bac.inc"); }

NAKED bool32 FUN_080f6c74(Enemy* p) { INCFUNC("asm/func/FUN_080f6c74.inc"); }

void FUN_080f6e34(Enemy* p) {
  if ((p->flags6 & (ENEFLAG6_UNK_14 | ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) != 0) {
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  }
}

NAKED s32 FUN_080f6e64(Enemy* p) { INCFUNC("asm/func/FUN_080f6e64.inc"); }

NAKED bool32 FUN_080f8400(Enemy* p) { INCFUNC("asm/func/FUN_080f8400.inc"); }

NAKED s32 FUN_080f84d4(Enemy* p) { INCFUNC("asm/func/FUN_080f84d4.inc"); }

NAKED void FUN_080f8844(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f8844.inc"); }

NAKED void FUN_080f897c(unknown* param_1) { INCFUNC("asm/func/FUN_080f897c.inc"); }

s32 FUN_080f8abc(Enemy* p) {
  switch (p->unk_480) {
    case 0: {
      return 4;
    }
    case 1:
    case 3:
    case 5: {
      return 3;
    }
    default: {
      return 4;
    }
  }
}

NAKED void FUN_080f8ae0(Enemy* p) { INCFUNC("asm/func/FUN_080f8ae0.inc"); }

NAKED void FUN_080f8bb8(Entity2UnkData* owner) { INCFUNC("asm/func/FUN_080f8bb8.inc"); }

// 登録リストを空にする
void FUN_080f8c10(void) {
  EntityD854* p = gEntityD854;
  if (p != NULL) {
    p->count = 0;
    p->unk_20 = 0;
    p->unk_18 = 0;
    p->head = NULL;
  }
}

bool32 FUN_080f8c2c(EntityD854Node* node) {
  if ((node->flags & D854NODEFLAG_LINKED) != 0) {
    return FALSE;
  }
  if (node->timer != 0) {
    return FALSE;
  }
  if (node->kindMask == 1) {
    if (FUN_0808672c() == 0) {
      return FALSE;
    }
  }
  return TRUE;
}

NAKED bool32 FUN_080f8c58(EntityD854Node* node, Entity2UnkData* owner, u8 kindMask) { INCFUNC("asm/func/FUN_080f8c58.inc"); }

// 登録リストからノードを外す
void FUN_080f8cac(EntityD854Node* node) {
  EntityD854* p = gEntityD854;

  if (p != NULL) {
    EntityD854Node* cur = p->head;
    EntityD854Node* prev = NULL;

    while (cur != NULL) {
      if (cur == node) {
        if (prev == NULL) {
          p->head = cur->next;
        } else {
          prev->next = cur->next;
        }
        p->count--;
        return;
      }
      prev = cur;
      cur = cur->next;
    }
  }
}

void FUN_080f8cec(void) {}

EntityD854Node* FUN_080f8cf0(u32 kindMask) {
  EntityD854* p = gEntityD854;
  EntityD854Node* node;

  if (p == NULL) {
    return NULL;
  }
  node = p->head;
  if (node != NULL) {
    do {
      if (node->kindMask == kindMask) {
        return node;
      }
      node = node->next;
    } while (node != NULL);
  }
  return NULL;
}

bool32 FUN_080f8d20(EntityD854Node* node) {
  EntityD854* p = gEntityD854;
  EntityD854Node* cur;

  if (p == NULL) {
    return FALSE;
  }
  if (node == NULL) {
    return FALSE;
  }
  cur = p->head;
  if (cur != NULL) {
    do {
      if ((cur->flags & D854NODEFLAG_REGISTERED) != 0) {
        if (cur == node) {
          return TRUE;
        }
      }
      cur = cur->next;
    } while (cur != NULL);
  }
  return FALSE;
}

Entity2UnkData* FUN_080f8d60(u16 id) {
  EntityD854* p = gEntityD854;
  EntityD854Node* cur;

  if (p == NULL) {
    return NULL;
  }
  if (id == 0) {
    return NULL;
  }
  cur = p->head;
  if (cur != NULL) {
    do {
      if ((cur->flags & D854NODEFLAG_REGISTERED) != 0) {
        if (cur->owner->id == id) {
          return cur->owner;
        }
      }
      cur = cur->next;
    } while (cur != NULL);
  }
  return NULL;
}

NAKED void FUN_080f8da4(void) { INCFUNC("asm/func/FUN_080f8da4.inc"); }

// ノードと敵の紐付けを解除し、再登録までの待ち時間を置く
void FUN_080f8e3c(EntityD854Node* node) {
  EntityD854* p = gEntityD854;

  if ((p != NULL) && (node != NULL)) {
    EntityD854Node* cur = p->head;

    while (cur != NULL) {
      if ((cur == node) && ((cur->flags & D854NODEFLAG_REGISTERED) != 0)) {
        cur->flags &= ~D854NODEFLAG_LINKED;
        cur->enemy = NULL;
        cur->timer = 0xF0;
        FUN_080f8cec();
        return;
      }
      cur = cur->next;
    }
  }
}

NAKED bool32 FUN_080f8e84(Entity2UnkData* owner, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080f8e84.inc"); }

NAKED bool32 FUN_080f8f04(EntityD854Node* node, Enemy* enemy, unknown* param_3) { INCFUNC("asm/func/FUN_080f8f04.inc"); }

NAKED EntityD854Node* FUN_080f9a38(Enemy* p, u8 kindMask) { INCFUNC("asm/func/FUN_080f9a38.inc"); }

void FUN_080f9b34(void) {
  EntityD854* p = gEntityD854;

  if (p != NULL) {
    EntityD854Node* node = p->head;

    while (node != NULL) {
      if (node->timer != 0) {
        node->timer--;
      }
      node = node->next;
    }
  }
}

s32 EntityD854_Update(EntityD854* p) {
  FUN_080f8da4();
  FUN_080f9b34();
  p->unk_20++;
}

s32 EntityD854_Destroy(EntityD854* p) { gEntityD854 = NULL; }

s32 EntityD854_Init(EntityD854* p, u16 id) {
  gEntityD854 = p;
  FUN_080f8c10();
  p->unk_24 = id;
}

EntityD854* EntityD854_Create(u16 id) {
  if (gEntityD854 == NULL) {
    EntityD854* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityD854));
    if (p != NULL) {
      SetEntityRoutine(p, EntityD854_Update, EntityD854_Destroy);
      if (EntityD854_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityD854;
}

void FUN_080f9bec(void) { gEntityD854 = NULL; }

s32 FUN_080f9bf8(unknown* p, s32 val) { return val; }

void FUN_080f9bfc(Enemy* p) {
  p->unk_21e = 0;
  p->unk_220 = 0;
  p->unk_202 = 0;
  p->unk_1d8 = 0;
}

NAKED void FUN_080f9c20(Enemy* p) { INCFUNC("asm/func/FUN_080f9c20.inc"); }

NAKED void FUN_080f9e34(Enemy* p) { INCFUNC("asm/func/FUN_080f9e34.inc"); }

void FUN_080f9ee0(Enemy* p) {
  bool8 (*fn)(Enemy* p);

  if (p->unk_46c != 0) {
    p->unk_46c = 0;
  }
  fn = p->unk_608;
  if (fn(p) == 0) {
    p->unk_484++;
  }
}

NAKED s32 FUN_080f9f20(Enemy* p) { INCFUNC("asm/func/FUN_080f9f20.inc"); }

NAKED s32 FUN_080fa2ac(Enemy* p, Vec3* pos, u32 param_3) { INCFUNC("asm/func/FUN_080fa2ac.inc"); }

s32 FUN_080fa354(unknown* param_1, u32 param_2, s8 param_3) {
  s32 ret = FUN_08240b98(param_2, param_3);

  if (ret == 0xB546) {
    FUN_080e8ae4(param_1, param_2, param_2);
  }
  return ret;
}

NAKED s32 FUN_080fa384(Enemy* p) { INCFUNC("asm/func/FUN_080fa384.inc"); }

void FUN_080fa77c(Enemy* p) {
  if (p->unk_220 != 0) {
    p->unk_220 = p->unk_220 - 1;
  } else {
    p->unk_21e = 0;
  }
}

NAKED s32 FUN_080fa7a4(Enemy* p) { INCFUNC("asm/func/FUN_080fa7a4.inc"); }

NAKED s32 FUN_080fa958(Vec3* pos) { INCFUNC("asm/func/FUN_080fa958.inc"); }

bool32 FUN_080faa98(Enemy* p) {
  s32 idx = FUN_080fa958(&p->unk_0.pos);
  EnemyHandler fn;

  if (idx < 0) {
    fn = p->unk_5c4;
    fn(p);
    return FALSE;
  }
  p->unk_1d8 = &gPlayerPtr[idx]->unk_24;
  return TRUE;
}

NAKED void FUN_080faad8(Enemy* p) { INCFUNC("asm/func/FUN_080faad8.inc"); }

void FUN_080fadd4(unknown* param_1, EntityMsg* msg, Enemy* enemy) {
  if (FUN_080e8a60(enemy) == 0) {
    if ((msg->args[1] & 0xF) != 0) {
      enemy->unk_1d4 = msg->unk_4;
      Enemy_ClearFlag2(enemy, ENEFLAG2_UNK_24);
    }
  }
}

NAKED void FUN_080fae14(HitboxData* a, HitboxData* b, Enemy* enemy) { INCFUNC("asm/func/FUN_080fae14.inc"); }

NAKED void FUN_080fb4d0(unknown* p) { INCFUNC("asm/func/FUN_080fb4d0.inc"); }

void FUN_080fba28(Enemy* p) {
  if (p->unk_46d != 0) {
    p->unk_46d = 0;
  }
}

void FUN_080fba40(Enemy* p) {
  if (p->unk_46d != 0) {
    p->unk_46d = 0;
  }
  FUN_080ef86c(p, 0);
}

NAKED void FUN_080fba64(Enemy* p) { INCFUNC("asm/func/FUN_080fba64.inc"); }

NAKED void FUN_080fc0b8(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc0b8.inc"); }

NAKED void FUN_080fc174(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc174.inc"); }

NAKED void FUN_080fc1e4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc1e4.inc"); }

NAKED void FUN_080fc28c(Enemy* p) { INCFUNC("asm/func/FUN_080fc28c.inc"); }

NAKED void FUN_080fc4ec(Enemy* p) { INCFUNC("asm/func/FUN_080fc4ec.inc"); }

NAKED void FUN_080fc548(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc548.inc"); }

NAKED void FUN_080fc6f4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc6f4.inc"); }

NAKED void FUN_080fd08c(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fd08c.inc"); }

NAKED void FUN_080fe1bc(Enemy* p) { INCFUNC("asm/func/FUN_080fe1bc.inc"); }

NAKED void FUN_080fe274(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fe274.inc"); }

NAKED void FUN_080fe704(Enemy* p) { INCFUNC("asm/func/FUN_080fe704.inc"); }

NAKED void FUN_080fe7f4(Enemy* p) { INCFUNC("asm/func/FUN_080fe7f4.inc"); }

void FUN_080ff05c(Enemy* p) { p->handlerTables[3] = (void*)0x085AD488; }

NAKED void FUN_080ff06c(unknown* p) { INCFUNC("asm/func/FUN_080ff06c.inc"); }

NAKED void FUN_080ff270(unknown* p) { INCFUNC("asm/func/FUN_080ff270.inc"); }
