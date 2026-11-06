#include "entity.h"
#include "global.h"
#include "random.h"
#include "registry.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vm.h"

typedef struct {
  AuxSprite sprite;  // 0x00
  AuxSpriteGfx gfx;  // 0x2C, SPRITE_CC88
  Vec3 vel;          // 0x48, 毎フレーム sprite.pos に足す
  bool8 active;      // 0x50
  u8 unk_51[3];      // 0x51
  u16 animTimer;     // 0x54, 4 フレームごとに poseIdx を 0〜3 で回す
  u16 turnTimer;     // 0x56, 0 になると向きと速さを選び直す, 15〜30
  u16 angle;         // 0x58, 発生源の向き, 選び直すときはこれから ±15 ずらす
  u16 speed;         // 0x5A, 5〜8
} EntityB6FFElem;
static_assert(sizeof(EntityB6FFElem) == 92);

// 一定間隔で要素を撒く発生源
typedef struct {
  Vec3 pos;   // 0x00, '.c'
  u16 angle;  // 0x08, '.r=32'
  u16 timer;  // 0x0A, 32 に届くと要素を1つ撒いて 0 に戻る
} EntityB6FFEmitter;
static_assert(sizeof(EntityB6FFEmitter) == 12);

typedef struct {
  Entity e;                       // 0x000, ENTITY_UNK_10
  u16 unk_18;                     // 0x018, EntityB6FF_Create の引数, 読み手が見つかっていない
  u8 unk_1a[2];                   // 0x01A, まだ未解析
  EntityB6FFEmitter emitters[3];  // 0x01C
  EntityB6FFElem elems[24];       // 0x040, _Destroy が stride 0x5C で24枚 AuxSprite_Remove する
  u16 nextElem;                   // 0x8E0, 次に撒く elems の添字
  u8 unk_8e2[2276 - 0x8E2];       // 0x8E2
} EntityB6FF;
static_assert(sizeof(EntityB6FF) == 2276);

void EntityB6FFElem_Spawn(EntityB6FFElem* elem, Vec3* pos, u16 angle);
void EntityB6FF_InitElems(EntityB6FF* p);

// 145/140命令, 1回目の下書きで切り上げ, 原典は elem を r3 に置く
NON_MATCH void EntityB6FFElem_Update(EntityB6FFElem* elem) {
#ifdef NONMATCHING_C
  elem->sprite.pos.x += elem->vel.x;
  elem->sprite.pos.y += elem->vel.y;
  elem->sprite.pos.z += elem->vel.z;
  elem->sprite.poseIdx = (++elem->animTimer >> 2) & 3;
  if (--elem->turnTimer == 0) {
    s32 turn = ((Random() >> 3) & 0x1F) - 15;
    u32 angle;
    s32 speed;

    if (turn > 0) {
      elem->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      elem->sprite.flags &= ~SPRFLAG_XFLIP;
    }
    angle = turn + elem->angle;
    speed = ((Random() >> 3) & 3) + elem->speed - 1;
    elem->vel.x = FixToInt(12, speed * COS(angle));
    elem->vel.z = FixToInt(12, speed * SIN(angle));
    elem->turnTimer = (Random() & 0xF) + 15;
  }
#else
  INCFUNC("asm/func/EntityB6FFElem_Update.inc");
#endif
}

// 135/136命令, 原典は pos.x を ldrh で読み直してから -255 する, 加算順の入れ替えは試済
NON_MATCH void EntityB6FFElem_Spawn(EntityB6FFElem* elem, Vec3* pos, u16 angle) {
#ifdef NONMATCHING_C
  u32 a;
  s32 speed;

  elem->sprite.pos = *pos;
  elem->sprite.pos.x = elem->sprite.pos.x - 255 + ((Random() >> 3) & 0x1FF);
  elem->sprite.pos.z = elem->sprite.pos.z - 255 + ((Random() >> 3) & 0x1FF);
  elem->angle = angle;
  a = (Random() & 0x1F) + elem->angle - 15;
  speed = (Random() & 3) + elem->speed - 1;
  elem->vel.x = FixToInt(12, speed * COS(a));
  elem->vel.z = FixToInt(12, speed * SIN(a));
  elem->turnTimer = (Random() & 0xF) + 15;
  elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  elem->active = TRUE;
#else
  INCFUNC("asm/func/EntityB6FFElem_Spawn.inc");
#endif
}

// 74/75命令, 1回目の下書きで切り上げ
NON_MATCH s32 EntityB6FF_Update(EntityB6FF* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 24; i++) {
    if (p->elems[i].active) {
      EntityB6FFElem_Update(&p->elems[i]);
    }
  }
  for (i = 0; i < 3; i++) {
    EntityB6FFEmitter* em = &p->emitters[i];

    if (++em->timer >= 32) {
      EntityB6FFElem_Spawn(&p->elems[p->nextElem], &em->pos, em->angle);
      if (++p->nextElem >= 24) {
        p->nextElem = 0;
      }
      em->timer = 0;
    }
  }
#else
  INCFUNC("asm/func/EntityB6FF_Update.inc");
#endif
}

s32 EntityB6FF_Destroy(EntityB6FF* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    AuxSprite_Remove(&p->elems[i].sprite);
  }
  return 0;
}

// 1回目の下書きで切り上げ, ループの添字とレジスタの割り当てが違う
NON_MATCH void EntityB6FF_InitElems(EntityB6FF* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 24; i++) {
    EntityB6FFElem* elem = &p->elems[i];

    Video_GetAuxSprite(&elem->gfx, SPRITE_CC88);
    AuxSprite_Add(&elem->sprite, &elem->gfx, 0);
    elem->sprite.poseIdx = 0;
    elem->sprite.flags |= SPRFLAG_HIDDEN;
    elem->speed = ((Random() >> 3) & 3) + 5;
    elem->active = FALSE;
  }
#else
  INCFUNC("asm/func/EntityB6FF_InitElems.inc");
#endif
}

// 95/96命令, 残差は乱数テーブルの読みのレジスタと最後の空ループのあたり, 分岐の向きの入れ替えは試済
NON_MATCH s32 EntityB6FF_Init(EntityB6FF* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (VM_SeekToNamedArg('c')) {
    for (i = 0; i < 3; i++) {
      p->emitters[i].pos.x = VM_GetValue();
      p->emitters[i].pos.y = VM_GetValue();
      p->emitters[i].pos.z = VM_GetValue();
    }
  } else {
    for (i = 0; i < 3; i++) {
      p->emitters[i].pos.x = 0;
      p->emitters[i].pos.y = 0;
      p->emitters[i].pos.z = 0;
    }
  }
  if (VM_SeekToNamedArg('r')) {
    for (i = 0; i < 3; i++) {
      p->emitters[i].angle = VM_GetValue();
      p->emitters[i].timer = Random() & 0x1F;
    }
  } else {
    for (i = 0; i < 3; i++) {
      p->emitters[i].angle = 32;
      p->emitters[i].timer = Random() & 0x1F;
    }
  }
  for (i = 0; i < 3; i++) {
  }
  EntityB6FF_InitElems(p);
  Registry_Add(0x3969, p, 0);
#else
  INCFUNC("asm/func/EntityB6FF_Init.inc");
#endif
}

EntityB6FF* EntityB6FF_Create(u32 param_1) {
  EntityB6FF* p = CreateEntity(ENTITY_UNK_10, sizeof(EntityB6FF));

  if (p != NULL) {
    p->unk_18 = param_1;
    SetEntityRoutine(p, EntityB6FF_Update, EntityB6FF_Destroy);
    if (EntityB6FF_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
