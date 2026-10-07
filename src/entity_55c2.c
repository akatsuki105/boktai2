#include "entity.h"
#include "entity_c9bc.h"
#include "global.h"
#include "hitbox.h"

// ヒットボックスを1つ持ち、当たったらスクリプトの引数で指定された条件を見て反応するエンティティ
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  HitboxData hitbox;  // 0x18, _Destroy が Hitbox_Unregister に渡す
  u16 id;             // 0x68, _Create / _Init の引数, Hitbox_Init の第2引数にもなる
  u16 unk_6a;         // 0x6A, _Init が '.l=100' を入れる (unk_6c と同じ値)
  u16 unk_6c;         // 0x6C, _Init が '.l=100' を入れる
  u16 flags;          // 0x6E, _Init が '.f' を入れ、'.w' が無ければ bit3、'.a' が無ければ bit4 を足す
  u32 unk_70;         // 0x70, _Init が '.w' を入れる, 無ければ 0 で flags bit3
  u32 unk_74;         // 0x74, _Init が '.a' を入れる, 無ければ 0 で flags bit4
  u32 unk_78;         // 0x78, _Init が '.S=0x10' を入れ、Hitbox_Init の第5引数に渡す
  u16 unk_7c;         // 0x7C, _Init が 0 を入れる
  u16 unk_7e;         // 0x7E, _Init が '.i' を入れる
  u16 unk_80;         // 0x80, _Init が '.D' を入れる
  u16 unk_82;         // 0x82, _Init が '.d' を入れる
  Vec3 hitPos;        // 0x84, _OnHit が当たったヒットボックスの pos を写す
} Entity55C2;
static_assert(sizeof(Entity55C2) == 140);

// 空いている要素を1つ返す, 全部使用中なら NULL
EntityC9BCElem* EntityC9BC_FindFreeElem(EntityC9BC* p) {
  EntityC9BCElem* elem = p->elems;
  u32 i;

  for (i = 0; i < p->count; i++, elem++) {
    if (!elem->active) {
      return elem;
    }
  }

  return NULL;
}

// 使用中の要素から obj.id が一致するものを返す, 無ければ NULL
EntityC9BCElem* EntityC9BC_FindElemById(EntityC9BC* p, u32 id) {
  EntityC9BCElem* elem = p->elems;
  u32 i;

  for (i = 0; i < p->count; i++, elem++) {
    if (elem->active && elem->obj.id == id) {
      return elem;
    }
  }

  return NULL;
}

NAKED s32 VM_SubA062(void) { INCFUNC("asm/func/VM_SubA062.inc"); }

// 当たった相手の weakness と attributes が flags で指定された条件を満たしていたら、与ダメージを足して当たった位置を覚える
void Entity55C2_OnHit(HitboxData* a, HitboxData* b, Entity55C2* p) {
  s32 okWeakness = 0;
  s32 okAttributes;

  if (p->flags & 8) {
    okWeakness = 1;
  } else if (p->flags & 2) {
    if (p->unk_70 == a->weakness) {
      okWeakness = 1;
    }
  } else if (p->unk_70 & a->weakness) {
    okWeakness = 1;
  }

  okAttributes = 0;
  if (p->flags & 0x10) {
    okAttributes = 1;
  } else if (p->flags & 4) {
    if (p->unk_74 == a->attributes) {
      okAttributes = 1;
    }
  } else if (p->unk_74 & a->attributes) {
    okAttributes = 1;
  }

  if (okWeakness && okAttributes) {
    b->damage += a->damage;
    p->hitPos = a->pos;
  }
}

NAKED s32 Entity55C2_Update(Entity55C2* p) { INCFUNC("asm/func/Entity55C2_Update.inc"); }

s32 Entity55C2_Destroy(Entity55C2* p) {
  Hitbox_Unregister(&p->hitbox);
  return 0;
}

NAKED s32 Entity55C2_Init(Entity55C2* p, u32 id) { INCFUNC("asm/func/Entity55C2_Init.inc"); }

Entity55C2* Entity55C2_Create(u32 id) {
  Entity55C2* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity55C2));

  if (p != NULL) {
    SetEntityRoutine(p, Entity55C2_Update, Entity55C2_Destroy);
    if (Entity55C2_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
