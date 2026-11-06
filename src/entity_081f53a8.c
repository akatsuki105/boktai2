#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  AuxSprite sprite;        // 0x000, priority 1, flags に bit0 を立てて作る
  AuxSpriteGfx gfx;        // 0x02C, SPRITE_SKELETON_MISC
  AuxAnimState animState;  // 0x048, 親の anim のアニメ 0x14
  HitboxData hitbox0;      // 0x058
  HitboxData hitbox1;      // 0x0A8
  Vec3* chaseTarget;       // 0x0F8, state 2 で向きを寄せていく相手の座標
  u8 unk_fc[104];          // 0x0FC, まだ未解析
  Vec3 vel;                // 0x164, state 2 の毎フレームの移動量, state 1 は angle の向きへランダムな距離だけ離れた 2 段上の点を書くが読まれない
  u16 unk_16c;             // 0x16C, 生成時と解放時に 0 が入る
  u8 state;                // 0x16E, PTR_ARRAY_085ae578 の添字 (0: 待機, 3: 消える)
  s8 slotIdx;              // 0x16F, activeMask 上の自分のビット番号, 空きは -1
  u16 timer;               // 0x170, state に入ってからのフレーム数
  bool8 stateBegun;        // 0x172, 立っていると次の更新で state の初期化をする
  u8 speed;                // 0x173, 10 フレームごとに 1 ずつ maxSpeed まで上がる, 生成時に 4
  bool8 animFinished;      // 0x174, 直前の更新でアニメが一巡したか
  u8 angle;                // 0x175, 飛んでいく向き
  u8 unk_176[2];           // 0x176
  u16 lifetime;            // 0x178, state 2 の残りフレーム数, 尽きると state 3 へ移る
  u16 easeTime;            // 0x17A, state 1 は拡大, state 2 は高さ合わせの残りフレーム数
  u16 turnDelay;           // 0x17C, 尽きるまで向きを変えない, 生成時に 60
  u16 turnTime;            // 0x17E, 向きを chaseTarget へ寄せる残りフレーム数
  u16 maxSpeed;            // 0x180
  u8 unk_182[2];           // 0x182
} Entity081f53a8Elem;
static_assert(sizeof(Entity081f53a8Elem) == 388);

// スケルトン関連なのは確定, スケルトンの補助Entity?
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  AuxAnimFile* anim;            // 0x018, ANIM_1DC3
  u32 activeMask;               // 0x01C, 立っているビットの枠だけ Update と Destroy が触る
  Entity081f53a8Elem elems[8];  // 0x020
} Entity081f53a8;
static_assert(sizeof(Entity081f53a8) == 3136);

static Entity081f53a8* gEntity081f53a8;  // 0x030001F8

static inline bool8 Entity081f53a8_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

s32 Entity081f53a8_Update(Entity081f53a8* p);
s32 Entity081f53a8_Destroy(Entity081f53a8* p);
s32 Entity081f53a8_Init(Entity081f53a8* p);
Entity081f53a8* Entity081f53a8_Create(void);
void Entity081f53a8_OnHit(HitboxData* a, HitboxData* b, Entity081f53a8Elem* elem);
void Entity081f53a8_OnHurt(HitboxData* a, HitboxData* b, Entity081f53a8Elem* elem);
void Entity081f53a8_SpawnDebris(Vec3* pos, u8 angle);
Entity081f53a8Elem* Entity081f53a8_TryAllocElem(Entity081f53a8* p);
void Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, s32 kind);

// 攻撃が当たったら相手から見た向きに破片を撒いて消える
// 残差: 乱数ブロックで gRandTableIdx のアドレスと値のレジスタが入れ替わる (r0/r1), 他は一致
NON_MATCH void Entity081f53a8_OnHit(HitboxData* a, HitboxData* b, Entity081f53a8Elem* elem) {
#ifdef NONMATCHING_C
  Vec3 d;
  u32 angle;
  HitboxData* hitbox;

  Vec3_Delta(&d, &b->pos, &a->pos);
  if (d.x == 0 && d.z == 0) {
    angle = Random() & 0xFF;
  } else {
    angle = ArcTan2_8(d.x, d.z);
  }
  Entity081f53a8_SpawnDebris(&elem->sprite.pos, angle);
  Entity081f53a8_SpawnDebris(&elem->sprite.pos, angle);
  hitbox = &elem->hitbox0;
  hitbox->flags |= HBFLAG_HIDDEN;
  hitbox = &elem->hitbox1;
  hitbox->flags |= HBFLAG_HIDDEN;
  elem->state = 3;
  elem->stateBegun = TRUE;
#else
  INCFUNC("asm/func/Entity081f53a8_OnHit.inc");
#endif
}

// 地属性の攻撃を受けたら当てられた向きに破片を撒いて消える
void Entity081f53a8_OnHurt(HitboxData* a, HitboxData* b, Entity081f53a8Elem* elem) {
  if (TEST_FLAGS(a->attributes, HBATTR_EARTH)) {
    HitboxData* hitbox;

    Entity081f53a8_SpawnDebris(&elem->sprite.pos, a->angle);
    Entity081f53a8_SpawnDebris(&elem->sprite.pos, a->angle);
    hitbox = &elem->hitbox0;
    hitbox->flags |= HBFLAG_HIDDEN;
    hitbox = &elem->hitbox1;
    hitbox->flags |= HBFLAG_HIDDEN;
    elem->state = 3;
    elem->stateBegun = TRUE;
  }
}

void Entity081f53a8_InitHitbox(Entity081f53a8Elem* elem, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime) {
  Vec3 size;
  Vec3 offset;

  VEC3_SET(size, 64, 128, 64);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(&elem->hitbox0, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(&elem->hitbox0, power, knockbackPower, 0, attrs, invincibleTime);
  Hitbox_SetHandler(&elem->hitbox0, Entity081f53a8_OnHit, elem);
  Hitbox_SetPos(&elem->hitbox0, &elem->sprite.pos, 0);
  VEC3_SET(size, 92, 128, 92);
  Hitbox_Init(&elem->hitbox1, 0, HBFLAG_HURTBOX | HBFLAG_HIDDEN | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetPowerAndAttributes(&elem->hitbox1, 0, 0, 0);
  Hitbox_SetHandler(&elem->hitbox1, Entity081f53a8_OnHurt, elem);
  Hitbox_SetPos(&elem->hitbox1, &elem->sprite.pos, 0);
  elem->hitbox1.invincibleTime = 60;
}

// 判定2つを今の位置で登録し直し, hitbox1 は unk_44 が残っている間だけ有効にする
void Entity081f53a8_UpdateHitbox(Entity081f53a8Elem* elem) {
  HitboxData* hitbox0 = &elem->hitbox0;
  Vec3* pos = &elem->sprite.pos;
  HitboxData* hitbox1;

  Hitbox_SetPos(hitbox0, pos, 0);

  hitbox1 = &elem->hitbox1;
  Hitbox_SetPos(hitbox1, pos, 0);
  Hitbox_Register(hitbox0);
  Hitbox_Register(hitbox1);

  if (hitbox1->invincibleTime != 0) {
    hitbox1->invincibleTime--;
    hitbox1->flags |= HBFLAG_HIDDEN;
  } else {
    Hitbox_ClearFlags(hitbox1, HBFLAG_HIDDEN);
  }
}

void Entity081f53a8_UpdateIdle(Entity081f53a8* p, Entity081f53a8Elem* elem) {}

// state 3, 崩れるアニメを流し, 終わったらスロットを空ける
void Entity081f53a8_UpdateVanish(Entity081f53a8* p, Entity081f53a8Elem* elem) {
  if (elem->stateBegun) {
    AuxAnim_SetAnim(&elem->animState, p->anim, 24, 0, 0);
    elem->stateBegun = FALSE;
  }
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->animState)) {
    CLEAR_BIT(p->activeMask, elem->slotIdx);
    elem->state = 0;
    if (elem->sprite.active) {
      AuxSprite_Remove(&elem->sprite);
    }
    Hitbox_Unregister(&elem->hitbox1);
    elem->slotIdx = -1;
    elem->unk_16c = 0;
  }
}

// angle を中心に扇状に破片を6個飛ばす
// 残差: ループ外へ出す定数の割当 (乱数表を r10, 0x3FF を r9) が逆になり, 最初の乱数で表のアドレスを取り直さない
NON_MATCH void Entity081f53a8_SpawnDebris(Vec3* pos, u8 angle) {
#ifdef NONMATCHING_C
  Vec3 vel;
  s32 i;

  for (i = 0; i < 6; i++) {
    u8 dir = angle - 42 + i * 14;
    s32 speed = (Random() & 3) + 4;
    u16* table;

    Vec3_SetPolar(&vel, dir, speed);
    table = gRandomTable;
    vel.y = _Random(table) & 15;
    Entity081ee2a0_SpawnDefault(pos, &vel, (_Random(table) & 15) + 30, 5);
  }
#else
  INCFUNC("asm/func/Entity081f53a8_SpawnDebris.inc");
#endif
}

// state 1, 拡大しながら現れ, 等倍になってアニメが一巡したら state 2 へ移る
void Entity081f53a8_UpdateAppear(Entity081f53a8* p, Entity081f53a8Elem* elem) {
  if (elem->stateBegun) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    elem->sprite.flags |= SPRFLAG_AFFINE;
    elem->animFinished = FALSE;
    Vec3_SetPolar(&elem->vel, elem->angle, (Random() & 0xFF) + 64);
    Vec3_Sum(&elem->vel, &elem->sprite.pos, &elem->vel);
    elem->vel.y = elem->sprite.pos.y + 512;
    elem->easeTime = 15;
    elem->timer = 0;
    elem->stateBegun = FALSE;
    elem->sprite.scaleX = 1;
    elem->sprite.scaleY = 1;
  }
  if (Mod(elem->timer, 8) == 0) {
    Entity081f53a8_SpawnDebris(&elem->sprite.pos, elem->angle + 128);
  }
  if (elem->easeTime != 0) {
    elem->sprite.scaleX += Div(64 - elem->sprite.scaleX, elem->easeTime);
    elem->sprite.scaleY += Div(64 - elem->sprite.scaleY, elem->easeTime);
    elem->easeTime--;
  }
  elem->animFinished = AuxSprite_AdvanceAnim(&elem->sprite, &elem->animState);
  if (elem->animFinished && elem->easeTime == 0) {
    elem->state = 2;
    elem->sprite.flags &= ~SPRFLAG_AFFINE;
    elem->stateBegun = TRUE;
  } else {
    elem->timer++;
  }
}

// state 2, chaseTarget の方へ少しずつ向きを変えながら加速して進み, lifetime が尽きたら消える state へ移る
// 残差: 乱数ブロックで gRandTableIdx のアドレスと値のレジスタが入れ替わる (Entity081f53a8_OnHit と同じ), 向きを変える量の乱数が angle の読み出しより後に来ない, elem の写しを r7 に置かない
NON_MATCH void Entity081f53a8_UpdateChase(Entity081f53a8* p, Entity081f53a8Elem* elem) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &elem->animState;

  if (elem->stateBegun) {
    AuxSprite_Show(&elem->sprite);
    elem->easeTime = 60;
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  if (elem->animFinished) {
    s32 r = Random() & 0xFF;

    if (r < 64) {
      AuxAnim_SetAnim(anim, p->anim, 21, 0, 0);
    } else if (r < 78) {
      AuxAnim_SetAnim(anim, p->anim, 22, 0, 0);
    } else {
      AuxAnim_SetAnim(anim, p->anim, 20, 0, 0);
    }
    elem->animFinished = FALSE;
  }
  if (elem->turnDelay == 0) {
    Vec3 d;
    s32 diff;

    Vec3_Delta(&d, &elem->sprite.pos, elem->chaseTarget);
    diff = ArcTan2_8(d.x, d.z) - elem->angle;
    if (diff > 128) {
      diff -= 256;
    } else if (diff < -128) {
      diff += 256;
    }
    if (elem->turnTime != 0) {
      s32 absDiff = diff;

      if (absDiff < 0) {
        absDiff = -absDiff;
      }
      if (absDiff > 2) {
        if (diff < 0) {
          elem->angle -= (u8)((Random() & 1) + 1);
        } else {
          elem->angle += (u8)((Random() & 1) + 1);
        }
        elem->turnTime--;
      } else {
        elem->turnTime = 0;
      }
    }
  } else {
    elem->turnDelay--;
  }
  Vec3_SetPolar(&elem->vel, elem->angle, elem->speed);
  if (Mod(elem->timer, 10) == 0 && elem->speed < elem->maxSpeed) {
    elem->speed++;
  }
  elem->sprite.pos.x += elem->vel.x;
  if (elem->easeTime != 0) {
    elem->sprite.pos.y += Div(elem->chaseTarget->y - (elem->sprite.pos.y - 200), elem->easeTime);
    elem->easeTime--;
  }
  elem->sprite.pos.z += elem->vel.z;
  elem->animFinished = AuxSprite_AdvanceAnim(&elem->sprite, anim);
  Entity081f53a8_UpdateHitbox(elem);
  elem->timer++;
  if (elem->lifetime == 0) {
    elem->state = 3;
    elem->stateBegun = TRUE;
  } else {
    elem->lifetime--;
  }
#else
  INCFUNC("asm/func/Entity081f53a8_UpdateChase.inc");
#endif
}

// 空いているスロットを1つ 0 で埋めて確保する
Entity081f53a8Elem* Entity081f53a8_AllocElem(Entity081f53a8* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity081f53a8_IsActive(&p->activeMask, i)) {
      Entity081f53a8Elem* elem = &p->elems[i];

      ClearMemory(elem, sizeof(Entity081f53a8Elem));
      p->activeMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

Entity081f53a8Elem* Entity081f53a8_TryAllocElem(Entity081f53a8* p) {
  Entity081f53a8Elem* elem = Entity081f53a8_AllocElem(p);

  if (elem == NULL) {
    return NULL;
  }
  return elem;
}

void Entity081f53a8_Spawn(Vec3* pos, Vec3* chaseTarget, s32 power, s32 knockbackPower, HitboxAttributes attrs, s32 invincibleTime, s32 maxSpeed, s32 turnTime, s32 lifetime, u32 angle) {
  Entity081f53a8* p = gEntity081f53a8;
  Entity081f53a8Elem* elem;

  if (p == NULL) {
    p = Entity081f53a8_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity081f53a8_TryAllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->unk_16c = 0;
  elem->stateBegun = TRUE;
  elem->chaseTarget = chaseTarget;
  elem->turnTime = turnTime;
  elem->lifetime = lifetime;
  elem->speed = 4;
  elem->maxSpeed = maxSpeed;
  elem->turnDelay = 60;
  elem->angle = angle;
  Video_GetAuxSprite(&elem->gfx, SPRITE_SKELETON_MISC);
  AuxSprite_Add(&elem->sprite, &elem->gfx, 0);
  AuxAnim_SetAnim(&elem->animState, p->anim, 20, 0, 0);
  Video_SetAuxSpritePltt(elem->sprite.gfx, 0xFA);
  elem->sprite.pos = *pos;
  AuxSprite_Hide(&elem->sprite);
  elem->sprite.priority = 1;
  Entity081f53a8_InitHitbox(elem, power, knockbackPower, attrs, invincibleTime);
}

void (*const PTR_ARRAY_085ae578[4])(Entity081f53a8*, Entity081f53a8Elem*) = {
    Entity081f53a8_UpdateIdle,
    Entity081f53a8_UpdateAppear,
    Entity081f53a8_UpdateChase,
    Entity081f53a8_UpdateVanish,
};  // 0x085AE578

s32 Entity081f53a8_Update(Entity081f53a8* p) {
  s32 i;

  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, FLAG030047A4_GAMEOVER)) {
    return 0;
  }
  if (TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    return 0;
  }
  for (i = 0; i < 8; i++) {
    if (Entity081f53a8_IsActive(&p->activeMask, i)) {
      Entity081f53a8Elem* elem = &p->elems[i];

      PTR_ARRAY_085ae578[elem->state](p, elem);
    }
  }
  return 0;
}

s32 Entity081f53a8_Destroy(Entity081f53a8* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (Entity081f53a8_IsActive(&p->activeMask, i)) {
      Entity081f53a8Elem* elem = &p->elems[i];

      AuxSprite_Remove(&elem->sprite);
      Hitbox_Unregister(&elem->hitbox1);
    }
  }
  gEntity081f53a8 = NULL;
  return 0;
}

s32 Entity081f53a8_Init(Entity081f53a8* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_1DC3);
  p->activeMask = 0;
  gEntity081f53a8 = p;
  return 0;
}

Entity081f53a8* Entity081f53a8_Create(void) {
  if (gEntity081f53a8 == NULL) {
    Entity081f53a8* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity081f53a8));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081f53a8_Update, Entity081f53a8_Destroy);
      if (Entity081f53a8_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081f53a8;
}

void Entity081f53a8_ClearGlobal(void) { gEntity081f53a8 = NULL; }

// 使用中の要素をすべて消える state へ移す
void Entity081f53a8_VanishAll(void) {
  Entity081f53a8* p = gEntity081f53a8;

  if (p != NULL) {
    Entity081f53a8Elem* elems = p->elems;
    s32 i;

    for (i = 0; i < 8; i++) {
      if (Entity081f53a8_IsActive(&p->activeMask, i) && elems[i].state != 3) {
        elems[i].state = 3;
        elems[i].stateBegun = TRUE;
      }
    }
  }
}
