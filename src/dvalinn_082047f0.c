#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct Entity082047f0Elem {
  AuxAnimState anim;  // 0x00
  AuxSprite sprite;   // 0x10
  s16 radius;         // 0x3C, mover からの距離
  u8 angleOffset;     // 0x3E, mover の向きに足す角度, 符号付きで読む, elems[0] が負で elems[1] が正
  bool8 animDone;     // 0x3F, anim が終端まで進むと 1
  u8 unk_40;          // 0x40, Init が 0 を書くだけで読み手は未発見
  u8 unk_41;          // 0x41, Init が 0 を書くだけで読み手は未発見
  u8 state;           // 0x42, モード内の段階, 2 が終わりのアニメ
  bool8 stateInited;  // 0x43, state に入った最初の更新で立てる
} Entity082047f0Elem;
static_assert(sizeof(Entity082047f0Elem) == 68);

// ドヴァリンの両脇に付く 2 つのスプライト, mover の 4 方向の向きに合わせて位置を求める
typedef struct Entity082047f0 {
  Entity e;                     // 0x000, ENTITY_UNK_8
  AuxAnimFile* animFile;        // 0x018, ANIM_38E2
  AuxSpriteGfx gfx;             // 0x01C, SPRITE_DVALIN_2E78
  Entity082047f0Elem elems[2];  // 0x038
  Mover* mover;                 // 0x0C0, ドヴァリンの mover
  u32 flags;                    // 0x0C4, bit0 が立っている間は elems の位置を更新しない
  u8 unk_c8;                    // 0x0C8, 読み手も書き手も未発見, padding?
  u8 dir;                       // 0x0C9, mover->angle の Angle_ToDir4
  u8 mode;                      // 0x0CA, sEntity082047f0Updates の添字, 2 つとも終わると 0 に戻る
  bool8 endRequested;           // 0x0CB, Entity082047f0_RequestEnd が立てると終わりのアニメへ進む
} Entity082047f0;
static_assert(sizeof(Entity082047f0) == 204);

void* Entity081f26bc_Spawn(Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime, s32 ofsX, s32 ofsY);

// mover の向きを 4 方向に丸めて, その左右に elems を置く
void Entity082047f0_UpdateElemPos(Entity082047f0* p) {
  Vec3 offset;
  Entity082047f0Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 2; i++) {
    u32 angle = ((p->mover->angle - 32) & ~63) + 64;

    angle += (s8)elem->angleOffset;
    Vec3_SetPolar(&offset, angle, elem->radius);
    Vec3_Sum(&elem->sprite.pos, &p->mover->pos, &offset);
    elem++;
  }
}

void Entity082047f0_HideElems(Entity082047f0* p) {
  Entity082047f0Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 2; i++) {
    AuxSprite_Hide(&elem->sprite);
    elem++;
  }
}

void Entity082047f0_ShowElems(Entity082047f0* p) {
  Entity082047f0Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 2; i++) {
    AuxSprite_Show(&elem->sprite);
    elem++;
  }
}

void Entity082047f0_SetFlags(Entity082047f0* p, u32 flags) { p->flags |= flags; }

void Entity082047f0_ClearFlags(Entity082047f0* p, u32 flags) { p->flags &= ~flags; }

void Entity082047f0_SetPltt(Entity082047f0* p, rgb555* pltt) {
  Entity082047f0Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 2; i++) {
    elem->sprite.gfx->pltt = pltt;
    elem++;
  }
}

// 向きに合わせた variant と反転で anim を再生する
// 命令列は一致, 残差は variant が r6 で flags が r3 に載る割当 (原典は variant が r3, flags r5, anim r6), if/else の形と p->dir 直読みは確定
NON_MATCH void Entity082047f0_SetElemAnim(Entity082047f0* p, AuxAnimState* anim, s32 animIdx, s32 flags) {
#ifdef NONMATCHING_C
  u8 variant;
  u8 xflip;

  if (p->dir == 1 || p->dir == 2) {
    variant = 0;
  } else {
    variant = 1;
  }
  xflip = p->dir > 1;
  AuxAnim_SetAnim(anim, p->animFile, animIdx, variant, xflip | flags);
#else
  INCFUNC("asm/func/Entity082047f0_SetElemAnim.inc");
#endif
}

void Entity082047f0_SpawnEffect(Vec3* pos) {
  Vec3 vel = {0, 0, 0, 0};

  Entity081f26bc_Spawn(pos, &vel, SPRITE_EFF_F422, ANIM_121B, 6, 0, 9, 0x237, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

void Entity082047f0_SetMode(Entity082047f0* p, u32 mode) {
  Entity082047f0Elem* elem;
  s32 i;

  p->mode = mode;
  p->endRequested = FALSE;
  elem = p->elems;
  for (i = 0; i < 2; i++) {
    elem->stateInited = FALSE;
    elem->state = 0;
    elem++;
  }
}

void Entity082047f0_RequestEnd(Entity082047f0* p) { p->endRequested = TRUE; }

s32 Entity082047f0_UpdateMode0(Entity082047f0* p, Entity082047f0Elem* elem, s32 idx) { return 0; }

// 乱数の variant でアニメを繰り返し, 終了要求が来たら消える
// 命令差は定数 1 の共有だけ (Random() & 1 の 1 と stateInited = TRUE の 1 が 1 本にまとまる), variant を u8/u16 引数の static inline 経由にすると 2 命令差まで縮むが一致せず
NON_MATCH s32 Entity082047f0_UpdateMode1(Entity082047f0* p, Entity082047f0Elem* elem, s32 idx) {
#ifdef NONMATCHING_C
  u8 variant;

  switch (elem->state) {
    case 0: {
      if (!elem->stateInited) {
        if (idx == 0) {
          elem->angleOffset = 0xE2;
        } else {
          elem->angleOffset = 0x1E;
        }
        elem->radius = 250;
        Entity082047f0_ShowElems(p);
        p->dir = Angle_ToDir4(p->mover->angle);
        variant = Random() & 1;
        AuxAnim_SetAnim(&elem->anim, p->animFile, 7, variant, p->dir > 1);
        elem->stateInited = TRUE;
      }
      elem->animDone = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
      if (elem->animDone) {
        elem->state++;
      }
      break;
    }
    case 1: {
      if (!elem->stateInited) {
        p->dir = Angle_ToDir4(p->mover->angle);
        variant = Random() & 1;
        AuxAnim_SetAnim(&elem->anim, p->animFile, 7, variant, p->dir > 1);
        elem->stateInited = TRUE;
      }
      elem->animDone = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
      if (elem->animDone) {
        if (p->endRequested) {
          elem->state = 2;
          elem->stateInited = FALSE;
        } else {
          variant = Random() & 1;
          AuxAnim_SetAnim(&elem->anim, p->animFile, 7, variant, p->dir > 1);
          elem->animDone = FALSE;
        }
      }
      break;
    }
    case 2: {
      Entity082047f0_SpawnEffect(&elem->sprite.pos);
      PlaySound_082406e0(SONG_438);
      AuxSprite_Hide(&elem->sprite);
      return 1;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Entity082047f0_UpdateMode1.inc");
#endif
}

s32 Entity082047f0_UpdateMode2(Entity082047f0* p, Entity082047f0Elem* elem, s32 idx) {
  switch (elem->state) {
    case 0: {
      if (!elem->stateInited) {
        if (idx == 0) {
          elem->angleOffset = 0xEC;
        } else {
          elem->angleOffset = 0x14;
        }
        elem->radius = 250;
        Entity082047f0_ShowElems(p);
        p->dir = Angle_ToDir4(p->mover->angle);
        Entity082047f0_SetElemAnim(p, &elem->anim, 4, 0);
        elem->stateInited = TRUE;
      }
      elem->animDone = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
      if (elem->animDone) {
        elem->stateInited = FALSE;
        elem->state = 1;
      }
      break;
    }
    case 1: {
      if (p->endRequested) {
        elem->stateInited = FALSE;
        elem->state = 2;
      }
      break;
    }
    case 2: {
      if (!elem->stateInited) {
        Entity082047f0_SetElemAnim(p, &elem->anim, 4, ANIM_PLAY_REVERSE);
        elem->stateInited = TRUE;
      }
      elem->animDone = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
      if (elem->animDone) {
        Entity082047f0_SpawnEffect(&elem->sprite.pos);
        PlaySound_082406e0(SONG_438);
        AuxSprite_Hide(&elem->sprite);
        return 1;
      }
      break;
    }
  }
  return 0;
}

// idx と向きで左右のアニメを選ぶ, 流れは Entity082047f0_UpdateMode2 と同じ
s32 Entity082047f0_UpdateMode3(Entity082047f0* p, Entity082047f0Elem* elem, s32 idx) {
  switch (elem->state) {
    case 0: {
      if (!elem->stateInited) {
        if (idx == 0) {
          elem->angleOffset = 0xEC;
        } else {
          elem->angleOffset = 0x14;
        }
        elem->radius = 250;
        Entity082047f0_ShowElems(p);
        p->dir = Angle_ToDir4(p->mover->angle);
        if (p->dir > 1) {
          if (idx == 0) {
            Entity082047f0_SetElemAnim(p, &elem->anim, 6, 0);
          } else {
            Entity082047f0_SetElemAnim(p, &elem->anim, 5, 0);
          }
        } else {
          if (idx == 0) {
            Entity082047f0_SetElemAnim(p, &elem->anim, 5, 0);
          } else {
            Entity082047f0_SetElemAnim(p, &elem->anim, 6, 0);
          }
        }
        elem->stateInited = TRUE;
      }
      elem->animDone = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
      if (elem->animDone) {
        elem->state++;
      }
      break;
    }
    case 1: {
      if (p->endRequested) {
        elem->stateInited = FALSE;
        elem->state = 2;
      }
      break;
    }
    case 2: {
      if (!elem->stateInited) {
        if (idx == 0) {
          Entity082047f0_SetElemAnim(p, &elem->anim, 5, ANIM_PLAY_REVERSE);
        } else {
          Entity082047f0_SetElemAnim(p, &elem->anim, 6, ANIM_PLAY_REVERSE);
        }
      }
      elem->animDone = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
      if (elem->animDone) {
        Entity082047f0_SpawnEffect(&elem->sprite.pos);
        PlaySound_082406e0(SONG_438);
        AuxSprite_Hide(&elem->sprite);
        return 1;
      }
      break;
    }
  }
  return 0;
}

void Entity082047f0_Update(Entity082047f0* p) {
  // Entity082047f0_Update が引数3つで呼んで戻り値を使う
  static s32 (*const sEntity082047f0Updates[4])(Entity082047f0*, Entity082047f0Elem*, s32) = {
      Entity082047f0_UpdateMode0,
      Entity082047f0_UpdateMode1,
      Entity082047f0_UpdateMode2,
      Entity082047f0_UpdateMode3,
  };  // 0x085AE824

  s32 finished = 0;
  Entity082047f0Elem* elem;
  s32 i;

  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return;
  }
  if (!(p->flags & 1)) {
    Entity082047f0_UpdateElemPos(p);
  }
  elem = p->elems;
  for (i = 0; i < 2; i++) {
    if (sEntity082047f0Updates[p->mode](p, elem, i) > 0) {
      finished++;
    }
    elem++;
  }
  if (finished > 1) {
    Entity082047f0_SetMode(p, 0);
    Entity082047f0_HideElems(p);
  }
}

s32 Entity082047f0_Destroy(Entity082047f0* p) {
  Entity082047f0Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 2; i++) {
    if (elem->sprite.active) {
      AuxSprite_Remove(&elem->sprite);
    }
    elem++;
  }
  return 0;
}

s32 Entity082047f0_Init(Entity082047f0* p, Mover* mover) {
  Entity082047f0Elem* elem;
  s32 i;

  p->animFile = GetFile(DIR_ANIMATION, ANIM_38E2);
  Video_GetAuxSprite(&p->gfx, SPRITE_DVALIN_2E78);
  p->mover = mover;
  p->mode = 0;
  elem = p->elems;
  for (i = 0; i < 2; i++) {
    if (i == 0) {
      elem->angleOffset = 0xE2;
    } else {
      elem->angleOffset = 0x1E;
    }
    elem->radius = 300;
    AuxSprite_Add(&elem->sprite, &p->gfx, 0);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 5, 0, 0);
    AuxSprite_Hide(&elem->sprite);
    elem->animDone = FALSE;
    elem->unk_40 = 0;
    elem->unk_41 = 0;
    elem->state = 0;
    elem->stateInited = FALSE;
    elem++;
  }
  Entity082047f0_UpdateElemPos(p);
  Entity082047f0_SetMode(p, 0);
  p->flags = 0;
  return 0;
}

Entity082047f0* Entity082047f0_Create(Mover* mover) {
  Entity082047f0* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity082047f0));

  if (p != NULL) {
    SetEntityRoutine(p, Entity082047f0_Update, Entity082047f0_Destroy);
    if (Entity082047f0_Init(p, mover) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
