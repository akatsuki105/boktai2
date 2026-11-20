#include "constants/sprite.h"
#include "constants/sprite_palette.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vec3.h"
#include "video.h"

// コウモリ1匹
typedef struct {
  u8 angle;               // 0x000, 進む向き, gSineTable の添字, 被弾すると当たった向きになる
  u8 speed;               // 0x001, state 3 の1フレームの移動量, gSineTable との積を 12bit 右シフトして vel にする
  s8 state;               // 0x002, sEntity0805e67cStates の添字 (0: 何もしない, 1: 散開, 2: targetPos を狙う, 3: 直進, 4: 被弾)
  bool8 stateEntered;     // 0x003, state が変わると 1, 各 state の最初のフレームで 0 に戻す
  u32 timer;              // 0x004, state に入ってからのフレーム数, state 3 は 120, state 4 は 20 フレームで消える
  u8 scatterTime;         // 0x008, state 1 に留まるフレーム数, 4..35 の乱数
  u8 scatterSpeed;        // 0x009, state 1 の1フレームの移動量, 20
  u8 aimTime;             // 0x00A, state 2 に留まるフレーム数, 添字 * 8 + 15
  u8 unk_0b;              // 0x00B
  Vec3 vel;               // 0x00C, 1フレームに sprite.pos へ足す量, y は常に 0
  Hitbox hitbox;          // 0x014, state 3 の間, 添字の偶奇が frameParity と合うフレームだけ登録する
  Hitbox hurtbox;         // 0x064, state 2, 3 の間だけ HBF_HIDDEN を落とす, 当たると state 4 へ移る
  AuxAnimState anim;      // 0x0B4, コマ送りは自前で行う
  AuxSprite sprite;       // 0x0C4
  AuxSpriteGfx gfx;       // 0x0F0, SPR_BAT, パレット 611 (被弾直後の 6 フレームは 306), 群れで出すと pltt は Entity0805e67c.pltt を指す
  ParticleShadow shadow;  // 0x10C
} Entity0805e67cElem;
static_assert(sizeof(Entity0805e67cElem) == 332);

// シェードマンが出すコウモリを最大16匹まとめて動かす, 1匹ずつ直進させるか, 群れで左右へ散らしてから targetPos を狙って直進させる
typedef struct Entity0805e67c {
  Entity e;                      // 0x000, ENTITY_UNK_8
  u32 activeMask;                // 0x018, 1 << i で elems[i] が使用中, 0 の間は何も更新しない
  u32 timer;                     // 0x01C, activeMask が 0 でない間のフレーム数
  AuxAnimFile* anim;             // 0x020, ANIM_BAT
  Entity0805e67cElem elems[16];  // 0x024
  bool8 fadeActive;              // 0x14E4, 立っている間 pltt を毎フレーム作り直す, fadeLevel が 0 に戻ると 0
  s8 fadeLevel;                  // 0x14E5, pltt をパレット 611 から 615 へ寄せる度合い, 32 で 615 そのもの, 群れを出すと 20 から 31 まで上がって 0 まで下がる
  bool8 fadeOut;                 // 0x14E6, 0: fadeLevel を上げる, 1: 下げる
  u8 frameParity;                // 0x14E7, timer の最下位ビット
  rgb555 pltt[16];               // 0x14E8, 群れで出した要素の gfx.pltt がここを指す
  Vec3 targetPos;                // 0x1508, gPlayerPtr[0]->mover.pos の写し, gPlayerPtr[0] がいなければ前の値のまま
} Entity0805e67c;
static_assert(sizeof(Entity0805e67c) == 5392);

// 4 方向の向き dir を左右反転とアニメの variant に分ける, ringo_bat_swarm.c の RingoBat_GetAnimVariant と同じ
static inline void Entity0805e67c_GetAnimVariant(u8 dir, u8* variant, u8* xflip) {
  if (dir == DIR4_EAST || dir == DIR4_SOUTH) {
    *variant = 1;
  } else {
    *variant = 0;
  }
  if (dir > DIR4_EAST) {
    *xflip = TRUE;
  } else {
    *xflip = FALSE;
  }
}

void FUN_0821bd3c(void);

// パレットを plttID にする
static inline void Entity0805e67c_SetPltt(AuxSpriteGfx* gfx, u16 plttID) { Video_SetAuxSpritePltt(gfx, plttID); }

// 状態を入れ替えて経過フレームを0に戻す
static inline void Entity0805e67c_SetState(Entity0805e67cElem* elem, s8 state) {
  elem->state = state;
  elem->stateEntered = TRUE;
  elem->timer = 0;
}

// 攻撃の向きへ弾かれて被弾の状態へ移る
void Entity0805e67c_OnHurt(Hitbox* a, Hitbox* b, Entity0805e67cElem* elem) {
  if (TEST_FLAGS(a->flags, HBF_ANGLE)) {
    elem->angle = a->angle;
  } else {
    elem->angle = ArcTan2_8(b->center.x - a->center.x, b->center.z - a->center.z);
  }
  Entity0805e67c_SetState(elem, 4);
}

void Entity0805e67c_OnHit(Hitbox* a, Hitbox* b, Entity0805e67cElem* elem) {}

// 要素1つ分のスプライトと影と当たり判定を用意する, 原典は return を書き忘れている
s32 Entity0805e67c_InitElem(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) {
  AuxSpriteGfx* gfx;
  AuxSprite* sprite;
  Vec3* pos;
  Hitbox* hitbox;
  Vec3 halfSize, offset;

  elem->angle = 0;
  elem->speed = 0;
  Entity0805e67c_SetState(elem, 0);
  gfx = &elem->gfx;
  Video_GetAuxSprite(gfx, SPR_BAT);
  Entity0805e67c_SetPltt(gfx, 611);
  sprite = &elem->sprite;
  AuxSprite_Add(sprite, gfx, SPRFLAG_HIDDEN);
  sprite->priority = 2;
  pos = &sprite->pos;
  Vec3_Clear(pos);
  ParticleShadow_Init(&elem->shadow, pos, 0);
  ParticleShadow_Hide(&elem->shadow);

  hitbox = &elem->hurtbox;
  VEC3_SET(halfSize, 32, 240, 32);
  VEC3_SET(offset, 0, 120, 0);
  Hitbox_Init(hitbox, 0, HBF_HURTBOX | HBF_ACTOR | HBF_HIDDEN | HBF_DAMAGE, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hitbox, pos, 0);
  Hitbox_SetHandler(hitbox, Entity0805e67c_OnHurt, elem);
  Hitbox_SetPowerAndAttributes(hitbox, 0, HBATTR_BEAST, 0);
  Hitbox_Register(hitbox);

  hitbox = &elem->hitbox;
  VEC3_SET(halfSize, 32, 240, 32);
  VEC3_SET(offset, 0, 120, 0);
  Hitbox_Init(hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hitbox, pos, 0);
  Hitbox_SetHandler(hitbox, Entity0805e67c_OnHit, elem);
  Hitbox_SetAttack(hitbox, 10, 30, HBSRC_12, 0, 8);
}

// 原典は return を書き忘れている
s32 Entity0805e67c_DestroyElem(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) {
  Hitbox_Unregister(&elem->hurtbox);
  ParticleShadow_Remove(&elem->shadow);
  AuxSprite_Remove(&elem->sprite);
}

// sprite と影を隠して食らい判定を外し, 使用中ビットを落とす, 原典は return を書き忘れている
s32 Entity0805e67c_ReleaseElem(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) {
  Hitbox* hurtbox;

  elem->sprite.flags |= SPRFLAG_HIDDEN;
  hurtbox = &elem->hurtbox;
  hurtbox->flags |= HBF_HIDDEN;
  ParticleShadow_Hide(&elem->shadow);
  p->activeMask &= ~(1 << idx);
}

// angle の向きに合わせた variant と左右反転で animIdx のアニメを流す
void Entity0805e67c_SetElemAnim(Entity0805e67c* p, Entity0805e67cElem* elem, u32 animIdx) {
  u8 variant;
  u8 xflip;

  Entity0805e67c_GetAnimVariant(Angle_ToDir4(elem->angle), &variant, &xflip);
  AuxAnim_SetAnim(&elem->anim, p->anim, animIdx, variant, xflip);
}

void Entity0805e67c_UpdateIdle(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) {}

// angle の向きへ scatterSpeed で散り, scatterTime 経ったら targetPos を狙いに行く
void Entity0805e67c_UpdateScatter(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateEntered) {
    Hitbox* hurtbox;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    hurtbox->flags |= HBF_HIDDEN;
    Entity0805e67c_SetElemAnim(p, elem, 0);
    Vec3_SetPolar(&elem->vel, elem->angle, elem->scatterSpeed);
  }
  Vec3_Add(&sprite->pos, &elem->vel);
  if (elem->timer >= elem->scatterTime) {
    Entity0805e67c_SetState(elem, 2);
  } else {
    elem->timer++;
  }
}

// 16 フレームごとに targetPos の方を向き, aimTime 経ったら少しぶれた向きで直進する
// 残差 (107/103): 原典は p を r7 に置き &sprite->pos を判定の後で作る, 向きの x を sprite から z を pos から読む形は RingoBat_UpdateAim と同じ
// Tier A-C は試済 (AngleTo inline, pos を使わない形, 宣言順), 未: 判定の書き方
NON_MATCH void Entity0805e67c_UpdateAim(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos;

  if (elem->stateEntered) {
    Hitbox* hurtbox;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    Hitbox_ClearFlags(hurtbox, HBF_HIDDEN);
    Entity0805e67c_SetElemAnim(p, elem, 0);
  }
  pos = &sprite->pos;
  if ((elem->timer & 15) == (idx & 15)) {
    elem->angle = ArcTan2_8(p->targetPos.x - sprite->pos.x, p->targetPos.z - pos->z);
    Entity0805e67c_SetElemAnim(p, elem, 0);
  }
  Hitbox_SetPos(&elem->hurtbox, pos, 0);
  if (elem->timer >= elem->aimTime) {
    elem->angle = ArcTan2_8(p->targetPos.x - sprite->pos.x, p->targetPos.z - pos->z) + (Random() & 15) - 8;
    Entity0805e67c_SetState(elem, 3);
  } else {
    elem->timer++;
  }
#else
  INCFUNC("asm/func/Entity0805e67c_UpdateAim.inc");
#endif
}

// angle の向きへ speed で直進する, 攻撃判定は idx の偶奇が frameParity と合うフレームだけ出し, 120 フレームで消える
void Entity0805e67c_UpdateFly(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos;

  if (elem->stateEntered) {
    Hitbox* hurtbox;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    Hitbox_ClearFlags(hurtbox, HBF_HIDDEN);
    Entity0805e67c_SetElemAnim(p, elem, 0);
    Vec3_SetPolar(&elem->vel, elem->angle, elem->speed);
  }
  pos = &sprite->pos;
  Vec3_Add(pos, &elem->vel);
  Hitbox_SetPos(&elem->hurtbox, pos, 0);
  if ((idx & 1) == p->frameParity) {
    Hitbox_SetPos(&elem->hitbox, pos, 0);
    Hitbox_Register(&elem->hitbox);
  }
  if (elem->timer >= 120) {
    Entity0805e67c_ReleaseElem(p, elem, idx);
  } else {
    elem->timer++;
  }
}

// 白く光って弾かれた向きへ減速しながら飛び, 点滅して 20 フレームで消える
void Entity0805e67c_UpdateHurt(Entity0805e67c* p, Entity0805e67cElem* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateEntered) {
    Hitbox* hurtbox;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    hurtbox->flags |= HBF_HIDDEN;
    Video_SetAuxSpritePltt(&elem->gfx, OBP_WHITE_306);
    Entity0805e67c_SetElemAnim(p, elem, 1);
    FUN_0821bd3c();
    PlaySound_082406e0(CRY_BAT_DEATH);
  }
  Vec3_SetPolar(&elem->vel, elem->angle, (20 - elem->timer) * 2);
  Vec3_Add(&sprite->pos, &elem->vel);
  if (elem->timer >= 20) {
    Entity0805e67c_ReleaseElem(p, elem, idx);
  } else {
    if (elem->timer == 6) {
      Video_SetAuxSpritePltt(&elem->gfx, 611);
    }
    if ((elem->timer >> 2) & 1) {
      AuxSprite_Show(&elem->sprite);
    } else {
      AuxSprite_Hide(&elem->sprite);
    }
    elem->timer++;
  }
}

void (*const sEntity0805e67cStates[5])(Entity0805e67c*, Entity0805e67cElem*, s32) = {
    Entity0805e67c_UpdateIdle,
    Entity0805e67c_UpdateScatter,
    Entity0805e67c_UpdateAim,
    Entity0805e67c_UpdateFly,
    Entity0805e67c_UpdateHurt,
};  // 0x085ABA5C

// プレイヤーの位置を写し, 群れのパレットを寄せ戻ししながら, 使用中の要素の状態関数とアニメを進める
s32 Entity0805e67c_Update(Entity0805e67c* p) {
  Entity0805e67cElem* elem;
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  if (gPlayerPtr[0] != NULL) {
    p->targetPos = gPlayerPtr[0]->mover.pos;
  }
  if (p->fadeActive) {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[615 * 16];

    BlendPltt(p->pltt, src1, src2, p->fadeLevel, 5);
    if (!p->fadeOut) {
      if (++p->fadeLevel > 30) {
        p->fadeLevel = 31;
        p->fadeOut = TRUE;
      }
    } else {
      if (--p->fadeLevel <= 0) {
        p->fadeLevel = 0;
        p->fadeOut = FALSE;
        p->fadeActive = FALSE;
      }
    }
  }
  p->frameParity = p->timer & 1;
  elem = &p->elems[0];
  for (i = 0; i < 16; i++, elem++) {
    if (p->activeMask & (1 << i)) {
      sEntity0805e67cStates[elem->state](p, elem, i);
      AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
    }
  }
  p->timer++;
  return 0;
}

s32 Entity0805e67c_Destroy(Entity0805e67c* p) {
  Entity0805e67cElem* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    Entity0805e67c_DestroyElem(p, elem, i);
  }
  return 0;
}

s32 Entity0805e67c_Init(Entity0805e67c* p) {
  Entity0805e67cElem* elem;
  s32 i;

  p->activeMask = 0;
  p->anim = GetFile(DIR_ANIMATION, ANIM_BAT);
  elem = &p->elems[0];
  for (i = 0; i < 16; i++, elem++) {
    Entity0805e67c_InitElem(p, elem, i);
  }
  return 0;
}

Entity0805e67c* Entity0805e67c_Create(void) {
  Entity0805e67c* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity0805e67c));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0805e67c_Update, Entity0805e67c_Destroy);
    if (Entity0805e67c_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 空いている要素を1匹 pos から angle の向きへ直進させる
s32 Entity0805e67c_Spawn(Entity0805e67c* p, Vec3* pos, u32 angle, s32 speed, s32 power, s32 knockback, s32 iframes) {
  Entity0805e67cElem* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (!(p->activeMask & (1 << i))) {
      Hitbox* hurtbox;

      Entity0805e67c_SetState(elem, 3);
      elem->angle = angle;
      elem->speed = speed;
      elem->sprite.pos = *pos;
      Video_SetAuxSpritePltt(&elem->gfx, 611);
      AuxSprite_Show(&elem->sprite);
      Entity0805e67c_SetElemAnim(p, elem, 0);
      ParticleShadow_Show(&elem->shadow);
      Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
      Hitbox_SetAttack(&elem->hitbox, power, knockback, HBSRC_12, 0, iframes);
      hurtbox = &elem->hurtbox;
      Hitbox_SetPos(hurtbox, &elem->sprite.pos, 0);
      hurtbox->flags |= HBF_HIDDEN;
      p->activeMask |= 1 << i;
      break;
    }
  }
  return 0;
}

// 空いている要素を群れで出す, 偶数番は angle - 96, 奇数番は angle + 96 の側へ散らしてから狙わせ, 群れのパレットを寄せ始める
s32 Entity0805e67c_SpawnSwarm(Entity0805e67c* p, Vec3* from, u32 angle, s32 speed, s32 power, s32 knockback, s32 iframes) {
  s32 angles[2];
  Entity0805e67cElem* elem;
  s32 i;

  angles[0] = angle - 96;
  angles[1] = angle + 96;
  elem = &p->elems[0];
  for (i = 0; i < 16; i++, elem++) {
    if (!(p->activeMask & (1 << i))) {
      AuxSprite* sprite;
      Vec3* pos;
      Hitbox* hurtbox;

      Entity0805e67c_SetState(elem, 1);
      elem->scatterTime = (Random() & 31) + 4;
      elem->scatterSpeed = 20;
      elem->aimTime = i * 8 + 15;
      elem->angle = angles[i & 1] + (Random() & 63) - 32;
      elem->speed = speed;
      sprite = &elem->sprite;
      pos = &sprite->pos;
      sprite->pos = *from;
      AuxSprite_Show(sprite);
      Entity0805e67c_SetElemAnim(p, elem, 0);
      Video_SetAuxSpritePltt(&elem->gfx, 615);
      elem->gfx.pltt = p->pltt;
      ParticleShadow_Show(&elem->shadow);
      Hitbox_SetPos(&elem->hitbox, pos, 0);
      Hitbox_SetAttack(&elem->hitbox, power, knockback, HBSRC_12, 0, iframes);
      hurtbox = &elem->hurtbox;
      Hitbox_SetPos(hurtbox, pos, 0);
      hurtbox->flags |= HBF_HIDDEN;
      p->activeMask |= 1 << i;
    }
  }
  p->fadeActive = TRUE;
  p->fadeLevel = 20;
  p->fadeOut = FALSE;
  {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[615 * 16];

    BlendPltt(p->pltt, src1, src2, p->fadeLevel, 5);
  }
  return 0;
}

// SpawnSwarm と同じだが先頭の count 匹の枠だけを使う, 偶数番は angle - 96, 奇数番は angle + 96 の側へ散らしてから狙わせ, 群れのパレットを寄せ始める
s32 Entity0805e67c_SpawnSwarmN(Entity0805e67c* p, Vec3* from, u32 angle, s32 speed, s32 power, s32 knockback, s32 iframes, s32 count) {
  s32 angles[2];
  Entity0805e67cElem* elem;
  s32 i;

  angles[0] = angle - 96;
  angles[1] = angle + 96;
  elem = &p->elems[0];
  for (i = 0; i < count; i++, elem++) {
    if (!(p->activeMask & (1 << i))) {
      AuxSprite* sprite;
      Vec3* pos;
      Hitbox* hurtbox;

      Entity0805e67c_SetState(elem, 1);
      elem->scatterTime = (Random() & 31) + 4;
      elem->scatterSpeed = 20;
      elem->aimTime = i * 8 + 15;
      elem->angle = angles[i & 1] + (Random() & 63) - 32;
      elem->speed = speed;
      sprite = &elem->sprite;
      pos = &sprite->pos;
      sprite->pos = *from;
      AuxSprite_Show(sprite);
      Entity0805e67c_SetElemAnim(p, elem, 0);
      Video_SetAuxSpritePltt(&elem->gfx, 615);
      elem->gfx.pltt = p->pltt;
      ParticleShadow_Show(&elem->shadow);
      Hitbox_SetPos(&elem->hitbox, pos, 0);
      Hitbox_SetAttack(&elem->hitbox, power, knockback, HBSRC_12, 0, iframes);
      hurtbox = &elem->hurtbox;
      Hitbox_SetPos(hurtbox, pos, 0);
      hurtbox->flags |= HBF_HIDDEN;
      p->activeMask |= 1 << i;
    }
  }
  p->fadeActive = TRUE;
  p->fadeLevel = 20;
  p->fadeOut = FALSE;
  {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[615 * 16];

    BlendPltt(p->pltt, src1, src2, p->fadeLevel, 5);
  }
  return 0;
}
