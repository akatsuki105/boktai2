#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "vm.h"

typedef enum {
  F_UNK_0 = (1 << 0),
  F_UNK_1 = (1 << 1),
  F_UNK_2 = (1 << 2),
  F_UNK_3 = (1 << 3),
  F_UNK_4 = (1 << 4),
} Entity55C2Flags;

// 食らい判定を1つ持ち、当たったらスクリプトの引数で指定された条件を見て反応するエンティティ
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_8
  HitboxData hurtbox;  // 0x18, _Destroy が Hitbox_Unregister に渡す
  u16 id;              // 0x68, _Create / _Init の引数, Hitbox_Init の第2引数にもなる
  s16 hp;              // 0x6A, '.l=100' を入れる
  u16 maxHP;           // 0x6C, '.l=100' を入れる, hp が 0になった処理の後にこれを再設定する
  u16 flags;           // 0x6E, '.f', Entity55C2Flags
  u32 unk_70;          // 0x70, '.w'
  u32 unk_74;          // 0x74, '.a'
  u32 ignoreMask;      // 0x78, '.S'
  u16 unk_7c;          // 0x7C
  u16 unk_7e;          // 0x7E, '.i'
  u16 unk_80;          // 0x80, '.D'
  u16 unk_82;          // 0x82, '.d'
  Vec3 hurtPos;        // 0x84
} Entity55C2;
static_assert(sizeof(Entity55C2) == 140);

// 当たった相手の weakness と attributes が flags で指定された条件を満たしていたら、与ダメージを足して当たった位置を覚える
void Entity55C2_OnHurt(HitboxData* a, HitboxData* b, Entity55C2* p) {
  s32 okWeakness = 0;
  s32 okAttributes;

  if (p->flags & F_UNK_3) {
    okWeakness = 1;
  } else if (p->flags & F_UNK_1) {
    if (p->unk_70 == a->weakness) {
      okWeakness = 1;
    }
  } else if (p->unk_70 & a->weakness) {
    okWeakness = 1;
  }

  okAttributes = 0;
  if (p->flags & F_UNK_4) {
    okAttributes = 1;
  } else if (p->flags & F_UNK_2) {
    if (p->unk_74 == a->attributes) {
      okAttributes = 1;
    }
  } else if (p->unk_74 & a->attributes) {
    okAttributes = 1;
  }

  if (okWeakness && okAttributes) {
    b->damage += a->damage;
    p->hurtPos = a->pos;
  }
}

// 被弾した分だけ hp を削り, 0 を切ったら '.d' のスクリプト, まだ残っていれば '.D' のスクリプトを呼ぶ
s32 Entity55C2_Update(Entity55C2* p) {
  HitboxData* hurtbox = &p->hurtbox;
  s32 argv[3];

  if (p->unk_7c != 0) {
    p->unk_7c--;
    p->hurtbox.flags |= HBFLAG_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBFLAG_HIDDEN;
  }

  if (hurtbox->damage != 0) {
    p->unk_7c = p->unk_7e;
    p->hp -= hurtbox->damage;

    if (p->hp < 0) {
      if (p->unk_82 != 0) {
        ScriptArgs sa;

        argv[0] = p->hurtPos.x, argv[1] = p->hurtPos.y, argv[2] = p->hurtPos.z;
        VM_ExecByID(p->unk_82, &sa);
      }
      if (p->flags & 1) {
        KillEntity((Entity*)p);
      } else {
        p->hp = p->maxHP;
      }
    } else if (p->unk_80 != 0) {
      ScriptArgs sa;

      argv[0] = p->hurtPos.x, argv[1] = p->hurtPos.y, argv[2] = p->hurtPos.z;
      VM_ExecByID(p->unk_80, &sa);
    }

    hurtbox->damage = 0;
  }

  return 0;
}

s32 Entity55C2_Destroy(Entity55C2* p) {
  Hitbox_Unregister(&p->hurtbox);
  return 0;
}

// スクリプトの名前付き引数から判定と反応条件を組み立てる
s32 Entity55C2_Init(Entity55C2* p, u32 id) {
  Vec3 pos, size, offset;

  p->id = id;
  p->maxHP = VM_GetNamedArgValue('l', 100);
  p->hp = p->maxHP;
  p->ignoreMask = VM_GetNamedArgValue('S', HIM_4);

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }

  if (VM_SeekToNamedArg('s')) {
    VEC3_SET(size, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(size, 0, 0, 0);
  }

  if (VM_SeekToNamedArg('o')) {
    VEC3_SET(offset, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(offset, 0, 0, 0);
  }

  Hitbox_Init(&p->hurtbox, id, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, p->ignoreMask, &size, &offset);
  Hitbox_SetPos(&p->hurtbox, &pos, 0);
  Hitbox_SetHandler(&p->hurtbox, Entity55C2_OnHurt, p);
  Hitbox_SetPowerAndAttributes(&p->hurtbox, 0, 0, 0);
  Hitbox_Register(&p->hurtbox);

  p->flags = VM_GetNamedArgValue('f', 0);
  if (VM_SeekToNamedArg('w')) {
    p->unk_70 = VM_GetValue();
  } else {
    p->unk_70 = 0;
    p->flags |= F_UNK_3;
  }
  if (VM_SeekToNamedArg('a')) {
    p->unk_74 = VM_GetValue();
  } else {
    p->unk_74 = 0;
    p->flags |= F_UNK_4;
  }

  p->unk_80 = VM_GetNamedArgValue('D', 0);
  p->unk_82 = VM_GetNamedArgValue('d', 0);
  p->unk_7c = 0;
  p->unk_7e = VM_GetNamedArgValue('i', 0);
  return 0;
}

// 0x55C2
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
