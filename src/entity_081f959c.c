#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

// リッチ+ のオービタルフレイム? (回転する火の玉を8つ出して自身の周回させる攻撃)

// center の周りを円を描いて回り, lifetime が尽きると縮んで消える攻撃判定付きのエフェクト1個
typedef struct {
  AuxSprite sprite;       // 0x00, pos は毎フレーム center + offset になる
  AuxAnimState anim;      // 0x2C, animIdx 7, variant 0
  HitboxData hitbox;      // 0x3C
  Vec3 center;            // 0x8C, 回る中心の座標
  Vec3 offset;            // 0x94, center からのずれ, y は常に 0
  u32 angle;              // 0x9C, 中心から見た向き, 下位12ビットが小数部で >> 12 が gSineTable の添字
  s32 angleSpeed;         // 0xA0, 毎フレーム angle に足す (dir が 0 以下なら引く) 量
  s16 dir;                // 0xA4, 正なら angle を増やし, 0 以下なら減らす
  u8 unk_a6[2];           // 0xA6
  s16 radius;             // 0xA8, 中心からの距離, 128 倍して使う, 負なら反対側を回る
  s16 scaleTime;          // 0xAA, 拡大縮小の残りフレーム数 (出現 30, 消滅 20)
  AuxAnimFile* animFile;  // 0xAC, ANIM_121B
  s32 lifetime;           // 0xB0, state 2 の残りフレーム数, 尽きると state 3 へ移る
  u16 unk_b4;             // 0xB4, 生成時に 0 が入るだけ
  u8 state;               // 0xB6, PTR_ARRAY_085ae5d0 の添字 (0:待機 1:出現 2:周回 3:消滅)
  s8 slotIdx;             // 0xB7, usedMask 上の自分のビット番号, 空きは -1
  u16 timer;              // 0xB8, state に入ってからのフレーム数
  bool8 stateBegun;       // 0xBA, 立っていると次の更新で state の初期化をする
  u8 unk_bb;              // 0xBB
} Entity081f959cElem;
static_assert(sizeof(Entity081f959cElem) == 188);

// 周回するエフェクトを8個まで同時に出すシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_EFF_F422
  u8 unk_34[4];                 // 0x034
  u32 usedMask;                 // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f959cElem elems[8];  // 0x03C
} Entity081f959c;
static_assert(sizeof(Entity081f959c) == 1564);

static Entity081f959c* gEntity081f959c;  // 0x0300020C

static inline bool8 Entity081f959c_IsUsed(Entity081f959c* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

s32 Entity081f959c_Update(Entity081f959c* p);
s32 Entity081f959c_Destroy(Entity081f959c* p);
s32 Entity081f959c_Init(Entity081f959c* p);
Entity081f959c* Entity081f959c_Create(void);
void Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, s32 kind);

void Entity081f959c_OnHit(HitboxData* a, HitboxData* b, Entity081f959cElem* elem) {}

void Entity081f959c_InitHitbox(Entity081f959cElem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 unk_6, s32 unk_7, s32 unk_8) {
  Vec3 size;
  Vec3 offset;
  HitboxData* hitbox;

  VEC3_SET(size, 24, 128, 24);
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_10 | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Entity081f959c_OnHit, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
}

// 攻撃判定をスプライトの位置に合わせて登録する
void Entity081f959c_UpdateHitbox(Entity081f959cElem* elem) {
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  Hitbox_Register(&elem->hitbox);
}

// 空いているスロットを1つ確保する
Entity081f959cElem* Entity081f959c_AllocElem(Entity081f959c* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity081f959c_IsUsed(p, i)) {
      Entity081f959cElem* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

// pos の周りにランダムな向きで火の粉を1つ飛ばす
// 残差: gRandTableIdx のアドレスと 0xFF 定数を先にレジスタへ載せる割当が再現できない, Entity081f9cb8_SpawnWaitEffect と同じ壁
NON_MATCH void Entity081f959c_SpawnTrail(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 angle;
  s32 speed;

  angle = Random() & 0xFF;
  speed = (Random() & 31) - 16;
  Vec3_SetPolar(&vel, angle, speed);
  vel.y = (Random() & 63) - 48;
  Entity081ee2a0_SpawnDefault(pos, &vel, 60, 3);
#else
  INCFUNC("asm/func/Entity081f959c_SpawnTrail.inc");
#endif
}

void Entity081f959c_UpdateIdle(Entity081f959c* p, Entity081f959cElem* elem) {}

// state 1, 拡大しながら現れ, 等倍になったら周回へ移る
void Entity081f959c_UpdateAppear(Entity081f959c* p, Entity081f959cElem* elem) {
  if (elem->stateBegun) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    elem->sprite.flags |= SPRFLAG_AFFINE;
    elem->scaleTime = 30;
    elem->timer = 0;
    elem->stateBegun = FALSE;
    elem->sprite.scaleX = 1;
    elem->sprite.scaleY = 1;
  }
  if (Mod(elem->timer, 12) == 0) {
    Entity081f959c_SpawnTrail(&elem->sprite.pos);
  }
  if (elem->scaleTime > 0) {
    elem->sprite.scaleX += Div(64 - elem->sprite.scaleX, elem->scaleTime);
    elem->sprite.scaleY += Div(64 - elem->sprite.scaleY, elem->scaleTime);
    elem->scaleTime--;
  }
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  if (elem->scaleTime <= 0) {
    elem->state = 2;
    elem->sprite.flags &= ~SPRFLAG_AFFINE;
    elem->stateBegun = TRUE;
  } else {
    elem->timer++;
  }
}

// state 2, center の周りを回りながら攻撃判定を出し, lifetime が尽きたら消滅へ移る
// 残差: AuxSprite_AdvanceAnim 展開内の 0xFFFF 定数が r3 でなく r1 に載る, 他は一致
NON_MATCH void Entity081f959c_UpdateOrbit(Entity081f959c* p, Entity081f959cElem* elem) {
#ifdef NONMATCHING_C
  if (elem->stateBegun) {
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  if (elem->dir > 0) {
    elem->angle += elem->angleSpeed;
    if (elem->angle > 0xFF000) {
      elem->angle -= 0xFF000;
    }
  } else {
    elem->angle -= elem->angleSpeed;
  }
  Vec3_SetPolar(&elem->offset, elem->angle >> 12, elem->radius * 128);
  elem->offset.y = 0;
  Vec3_Sum(&elem->sprite.pos, &elem->offset, &elem->center);
  if (Mod(elem->timer, 30) == 0 && (Random() & 0xFF) < 128) {
    Entity081f959c_SpawnTrail(&elem->sprite.pos);
  }
  Entity081f959c_UpdateHitbox(elem);
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  elem->timer++;
  if (elem->lifetime > 0) {
    elem->lifetime--;
  } else {
    elem->state = 3;
    elem->stateBegun = TRUE;
  }
#else
  INCFUNC("asm/func/Entity081f959c_UpdateOrbit.inc");
#endif
}

// state 3, 縮みながら消え, 消えきったらスロットを空ける
void Entity081f959c_UpdateVanish(Entity081f959c* p, Entity081f959cElem* elem) {
  if (elem->stateBegun) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    elem->sprite.flags |= SPRFLAG_AFFINE;
    elem->scaleTime = 20;
    elem->timer = 0;
    elem->stateBegun = FALSE;
    elem->sprite.scaleX = 64;
    elem->sprite.scaleY = 64;
    elem->timer = 0;
  }
  if (Mod(elem->timer, 6) == 0) {
    Entity081f959c_SpawnTrail(&elem->sprite.pos);
  }
  if (elem->scaleTime > 0) {
    elem->sprite.scaleX += Div(1 - elem->sprite.scaleX, elem->scaleTime);
    elem->sprite.scaleY += Div(1 - elem->sprite.scaleY, elem->scaleTime);
    elem->scaleTime--;
  }
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  if (elem->scaleTime <= 0) {
    AuxSprite_Remove(&elem->sprite);
    CLEAR_BIT(p->usedMask, elem->slotIdx);
    elem->slotIdx = -1;
    elem->state = 0;
    elem->stateBegun = FALSE;
  } else {
    elem->timer++;
  }
}

// pos を中心に radius の円周上を回る火の玉を1つ出す
void Entity081f959c_Spawn(Vec3* pos, u32 angle, s32 angleSpeed, s32 radius, s32 dir, s32 lifetime, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  Entity081f959c* p = gEntity081f959c;
  Entity081f959cElem* elem;
  AuxSprite* sprite;
  Vec3 offset;

  if (p == NULL) {
    p = Entity081f959c_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity081f959c_AllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->lifetime = lifetime;
  elem->unk_b4 = 0;
  elem->angle = angle << 12;
  elem->angleSpeed = angleSpeed;
  elem->radius = radius;
  elem->dir = dir;
  elem->stateBegun = TRUE;
  elem->center = *pos;
  sprite = &elem->sprite;
  elem->sprite.pos = elem->center;
  Vec3_SetPolar(&offset, elem->angle >> 12, elem->radius * 128);
  sprite->pos.x += offset.x;
  sprite->pos.z += offset.z;
  elem->animFile = GetFile(DIR_ANIMATION, ANIM_121B);
  AuxSprite_Add(sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, elem->animFile, 7, 0, 0);
  Video_SetAuxSpritePltt(sprite->gfx, 217);
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  sprite->priority = 2;
  AuxSprite_Show(sprite);
  Entity081f959c_InitHitbox(elem, power, knockback, attrs, iframes, 0, 0, 0);
}

void (*const PTR_ARRAY_085ae5d0[4])(Entity081f959c*, Entity081f959cElem*) = {
    Entity081f959c_UpdateIdle,
    Entity081f959c_UpdateAppear,
    Entity081f959c_UpdateOrbit,
    Entity081f959c_UpdateVanish,
};  // 0x085AE5D0

s32 Entity081f959c_Update(Entity081f959c* p) {
  Entity081f959cElem* elems = p->elems;
  s32 i;

  if (p->usedMask == 0) {
    return 0;
  }
  for (i = 0; i < 8; i++) {
    if (Entity081f959c_IsUsed(p, i)) {
      PTR_ARRAY_085ae5d0[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081f959c_Destroy(Entity081f959c* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (Entity081f959c_IsUsed(p, i)) {
      AuxSprite_Remove(&p->elems[i].sprite);
    }
  }
  gEntity081f959c = NULL;
  return 0;
}

s32 Entity081f959c_Init(Entity081f959c* p) {
  p->usedMask = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_F422);
  gEntity081f959c = p;
  return 0;
}

Entity081f959c* Entity081f959c_Create(void) {
  if (gEntity081f959c == NULL) {
    Entity081f959c* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081f959c));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081f959c_Update, Entity081f959c_Destroy);
      if (Entity081f959c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081f959c;
}

void Entity081f959c_ClearGlobal(void) { gEntity081f959c = NULL; }

// 出現中か周回中のものが1つでもあれば TRUE
bool32 Entity081f959c_IsAnyActive(void) {
  Entity081f959c* p = gEntity081f959c;
  s32 i;

  if (p == NULL) {
    return FALSE;
  }
  for (i = 0; i < 8; i++) {
    if (p->elems[i].state == 1 || p->elems[i].state == 2) {
      return TRUE;
    }
  }
  return FALSE;
}

// 出現中と周回中のものをすべて消滅へ移す
void Entity081f959c_VanishAll(void) {
  Entity081f959c* p = gEntity081f959c;
  s32 i;

  if (p != NULL) {
    for (i = 0; i < 8; i++) {
      if (p->elems[i].state != 3 && p->elems[i].state != 0) {
        p->elems[i].state = 3;
      }
    }
  }
}
