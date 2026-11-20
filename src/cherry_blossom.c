#include "entity.h"
#include "global.h"
#include "random.h"
#include "registry.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vm.h"

typedef struct {
  AuxSprite sprite;  // 0x00
  AuxSpriteGfx gfx;  // 0x2C, SPR_PETAL_CC88
  Vec3 vel;          // 0x48, 毎フレーム sprite.pos に足す
  bool8 active;      // 0x50
  u8 unk_51[3];      // 0x51
  u16 animTimer;     // 0x54, 4 フレームごとに poseIdx を 0〜3 で回す
  u16 turnTimer;     // 0x56, 0 になると向きと速さを選び直す, 15〜30
  u16 angle;         // 0x58, 発生源の向き, 選び直すときはこれから ±15 ずらす
  u16 speed;         // 0x5A, 5〜8
} CherryBlossomPetal;
static_assert(sizeof(CherryBlossomPetal) == 92);

// 一定間隔で花びらを撒く発生源
typedef struct {
  Vec3 pos;   // 0x00, '.c'
  u16 angle;  // 0x08, '.r=32'
  u16 timer;  // 0x0A, 32 に届くと花びらを1つ撒いて 0 に戻る
} CherryBlossomEmitter;
static_assert(sizeof(CherryBlossomEmitter) == 12);

typedef struct {
  Entity e;                          // 0x000, ENTITY_UNK_10
  u16 id;                            // 0x018
  u8 unk_1a[2];                      // 0x01A, padding?
  CherryBlossomEmitter emitters[3];  // 0x01C
  CherryBlossomPetal petals[24];     // 0x040
  u16 nextPetal;                     // 0x8E0, 次に撒く petals の添字
  u8 unk_8e2[2];                     // 0x8E2, padding?
} CherryBlossomEffect;
static_assert(sizeof(CherryBlossomEffect) == 2276);

// 145/140命令, 1回目の下書きで切り上げ, 原典は petal を r3 に置く
NON_MATCH void CherryBlossomPetal_Update(CherryBlossomPetal* petal) {
#ifdef NONMATCHING_C
  petal->sprite.pos.x += petal->vel.x;
  petal->sprite.pos.y += petal->vel.y;
  petal->sprite.pos.z += petal->vel.z;
  petal->sprite.poseIdx = (++petal->animTimer >> 2) & 3;
  if (--petal->turnTimer == 0) {
    s32 turn = ((Random() >> 3) & 0x1F) - 15;
    u32 angle;
    s32 speed;

    if (turn > 0) {
      petal->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      petal->sprite.flags &= ~SPRFLAG_XFLIP;
    }
    angle = turn + petal->angle;
    speed = ((Random() >> 3) & 3) + petal->speed - 1;
    petal->vel.x = FixToInt(12, speed * COS(angle));
    petal->vel.z = FixToInt(12, speed * SIN(angle));
    petal->turnTimer = (Random() & 0xF) + 15;
  }
#else
  INCFUNC("asm/func/CherryBlossomPetal_Update.inc");
#endif
}

// 135/136命令, 原典は pos.x を ldrh で読み直してから -255 する, 加算順の入れ替えは試済
NON_MATCH void CherryBlossomPetal_Spawn(CherryBlossomPetal* petal, Vec3* pos, u16 angle) {
#ifdef NONMATCHING_C
  u32 a;
  s32 speed;

  petal->sprite.pos = *pos;
  petal->sprite.pos.x = petal->sprite.pos.x - 255 + ((Random() >> 3) & 0x1FF);
  petal->sprite.pos.z = petal->sprite.pos.z - 255 + ((Random() >> 3) & 0x1FF);
  petal->angle = angle;
  a = (Random() & 0x1F) + petal->angle - 15;
  speed = (Random() & 3) + petal->speed - 1;
  petal->vel.x = FixToInt(12, speed * COS(a));
  petal->vel.z = FixToInt(12, speed * SIN(a));
  petal->turnTimer = (Random() & 0xF) + 15;
  petal->sprite.flags &= ~SPRFLAG_HIDDEN;
  petal->active = TRUE;
#else
  INCFUNC("asm/func/CherryBlossomPetal_Spawn.inc");
#endif
}

// 74/75命令, 1回目の下書きで切り上げ
NON_MATCH s32 CherryBlossomEffect_Update(CherryBlossomEffect* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 24; i++) {
    if (p->petals[i].active) {
      CherryBlossomPetal_Update(&p->petals[i]);
    }
  }
  for (i = 0; i < 3; i++) {
    CherryBlossomEmitter* em = &p->emitters[i];

    if (++em->timer >= 32) {
      CherryBlossomPetal_Spawn(&p->petals[p->nextPetal], &em->pos, em->angle);
      if (++p->nextPetal >= 24) {
        p->nextPetal = 0;
      }
      em->timer = 0;
    }
  }
#else
  INCFUNC("asm/func/CherryBlossomEffect_Update.inc");
#endif
}

s32 CherryBlossomEffect_Destroy(CherryBlossomEffect* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    AuxSprite_Remove(&p->petals[i].sprite);
  }
  return 0;
}

// 1回目の下書きで切り上げ, ループの添字とレジスタの割り当てが違う
NON_MATCH void CherryBlossomEffect_InitPetals(CherryBlossomEffect* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 24; i++) {
    CherryBlossomPetal* petal = &p->petals[i];

    Video_GetAuxSprite(&petal->gfx, SPR_PETAL_CC88);
    AuxSprite_Add(&petal->sprite, &petal->gfx, 0);
    petal->sprite.poseIdx = 0;
    petal->sprite.flags |= SPRFLAG_HIDDEN;
    petal->speed = ((Random() >> 3) & 3) + 5;
    petal->active = FALSE;
  }
#else
  INCFUNC("asm/func/CherryBlossomEffect_InitPetals.inc");
#endif
}

// 95/96命令, 残差は乱数テーブルの読みのレジスタと最後の空ループのあたり, 分岐の向きの入れ替えは試済
NON_MATCH s32 CherryBlossomEffect_Init(CherryBlossomEffect* p) {
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
  CherryBlossomEffect_InitPetals(p);
  Registry_Add(0x3969, p, 0);
#else
  INCFUNC("asm/func/CherryBlossomEffect_Init.inc");
#endif
}

// 0xB6FF, HashName("桜吹雪エフェクト")
CherryBlossomEffect* CherryBlossomEffect_Create(u32 id, u32 _) {
  CherryBlossomEffect* p = CreateEntity(ENTITY_UNK_10, sizeof(CherryBlossomEffect));

  if (p != NULL) {
    p->id = id;
    SetEntityRoutine(p, CherryBlossomEffect_Update, CherryBlossomEffect_Destroy);
    if (CherryBlossomEffect_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
