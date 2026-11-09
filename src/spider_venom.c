#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "sprite.h"
#include "vec3.h"

// ポイズンスパイダーの飛ばす毒液

// 毒液1発分
typedef struct {
  AuxSprite sprite;   // 0x00
  AuxAnimState anim;  // 0x2C
  Vec3 vel;           // 0x3C, 毎フレーム sprite.pos に足す, y は毎フレーム 1 ずつ減る
  HitboxData hitbox;  // 0x44
  s16 flags;          // 0x94, bit5: 地形に当たって止まった
  u8 state;           // 0x96, PTR_ARRAY_085ae450 の添字, 0 は空き
  s8 idx;             // 0x97, activeMask のビット番号, 空きなら -1
  Vec3* ownerPos;     // 0x98, 投げた敵の mover.pos
  s16 timer;          // 0x9C, 点滅を始めてからのフレーム数
} SpiderVenomShot;
static_assert(sizeof(SpiderVenomShot) == 160);

// ポイズンスパイダーの飛ばす毒液の管理構造体
typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;          // 0x018, SPRITE_BOMB
  AuxAnimFile* animFile;     // 0x034, ANIM_871C
  u32 activeMask;            // 0x038, bit i が shots[i] の使用中
  SpiderVenomShot shots[4];  // 0x03C
} SpiderVenom;
static_assert(sizeof(SpiderVenom) == 700);

// SpiderVenomShot.flags
#define VENOM_SHOT_LANDED (1 << 5)  // 0x20, 地形に当たって止まった

static inline bool8 SpiderVenom_IsActive(SpiderVenom* p, s32 i) {
  if (p->activeMask & (1 << i)) return TRUE;
  return FALSE;
}

const u8 u8_ARRAY_085ae44c[4] = {8, 4, 2, 1};  // 0x085AE44C, SpiderVenomShot_BlinkOut が Mod の除数として引く

void nop_081e85bc(void) {}

void SpiderVenomShot_InitHitbox(SpiderVenomShot* elem, s32 power, s32 knockback, s32 iframes) {
  Vec3 size, offset;
  HitboxData* hitbox;

  VEC3_SET(size, Q8(0.0625), Q8(1), Q8(0.0625));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, HBATTR_POISON | HBATTR_EARTH, iframes);
  Hitbox_SetHandler(hitbox, nop_081e85bc, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
}

void nop_081e8660(SpiderVenom* p, SpiderVenomShot* elem) {}

void SpiderVenomShot_BlinkOut(SpiderVenom* p, SpiderVenomShot* elem) {
  AuxSprite* sprite = &elem->sprite;
  s32 i;

  if (elem->timer > 60) {
    i = 2;
  } else if (elem->timer > 40) {
    i = 1;
  } else {
    i = 0;
  }
  if (Mod(elem->timer, u8_ARRAY_085ae44c[i]) == 0) {
    if (sprite->flags & SPRFLAG_HIDDEN) {
      AuxSprite_Show(sprite);
    } else {
      AuxSprite_Hide(sprite);
    }
  }
  if (elem->timer > 90) {
    AuxSprite_Hide(sprite);
    p->activeMask &= ~(1 << elem->idx);
    elem->state = 0;
  }
  elem->timer++;
}

void SpiderVenomShot_StateBlink(SpiderVenom* p, SpiderVenomShot* elem) {
  SpiderVenomShot_BlinkOut(p, elem);
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  Hitbox_Register(&elem->hitbox);
}

// 命令数は一致 (378/378), 残差は VENOM_SHOT_LANDED 判定で定数 0x20 を ldrsh より先に作る順序と, Vec3_Add の dst/src の読み順の2点, 原典は flags を符号付きで読む (要素ポインタ + ビットを取る判定 inline で ldrsh までは出た)
NON_MATCH void SpiderVenomShot_StateFly(SpiderVenom* p, SpiderVenomShot* elem) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  AuxAnimState* anim;

  AuxSprite_Show(&elem->sprite);
  anim = &elem->anim;
  if (!TEST_FLAGS(elem->flags, VENOM_SHOT_LANDED)) {
    anim->cmdIdx = 0;
    anim->tick = 0;
  }
  if (AuxSprite_AdvanceAnim(sprite, anim)) {
    elem->timer = 0;
    AuxSprite_Hide(sprite);
    p->activeMask &= ~(1 << elem->idx);
    elem->state = 0;
    AuxSprite_Remove(sprite);
    elem->idx = -1;
    return;
  }

  if (!TEST_FLAGS(elem->flags, VENOM_SHOT_LANDED)) {
    Vec3 next = sprite->pos;
    Vec3* vel = &elem->vel;
    s16 h0, h1;

    Vec3_Add(&next, vel);
    elem->vel.y--;
    h0 = TileHeightAt(&sprite->pos);
    h1 = TileHeightAt(&next);
    sprite->pos = next;
    if (sprite->pos.y < h0 || sprite->pos.y < h1) {
      sprite->pos.x -= elem->vel.x;
      sprite->pos.z -= elem->vel.z;
      elem->flags |= VENOM_SHOT_LANDED;
      elem->vel.x = 0, elem->vel.y = 0, elem->vel.z = 0;
    }
  }
  Hitbox_SetPos(&elem->hitbox, &sprite->pos, 0);
  Hitbox_Register(&elem->hitbox);
#else
  INCFUNC("asm/func/SpiderVenomShot_StateFly.inc");
#endif
}

SpiderVenomShot* SpiderVenom_AllocShot(SpiderVenom* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!SpiderVenom_IsActive(p, i)) {
      SpiderVenomShot* elem = &p->shots[i];

      p->activeMask |= 1 << i;
      p->shots[i].idx = i;
      return elem;
    }
  }
  return NULL;
}

SpiderVenomShot* FUN_081e8a88(SpiderVenom* p) {
  SpiderVenomShot* elem = SpiderVenom_AllocShot(p);

  if (elem == NULL) {
    return NULL;
  }
  return elem;
}

// 残差は先頭で引数を r1 に写す死んだ adds 1命令だけ (14/15), Tier A-B (三項 / 範囲 if / switch, dir ローカルの有無) は試済
NON_MATCH s32 SpiderVenom_AngleToXFlip(s32 angle) {
#ifdef NONMATCHING_C
  s32 dir = ((angle + 0x20) >> 6) & 3;

  switch (dir) {
    case 1:
    case 2: {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/SpiderVenom_AngleToXFlip.inc");
#endif
}

void SpiderVenom_Spawn(SpiderVenom* p, Mover* mover, Mover* target, s32 power, s32 knockback, s32 iframes) {
  SpiderVenomShot* elem;
  AuxSprite* sprite;

  if (p == NULL) {
    return;
  }
  elem = FUN_081e8a88(p);
  if (elem == NULL) {
    return;
  }

  elem->ownerPos = &mover->pos;
  elem->state = 1;
  elem->flags = 0;
  SpiderVenomShot_InitHitbox(elem, power, knockback, iframes);
  sprite = &elem->sprite;
  AuxSprite_Add(sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, p->animFile, 0, 0, SpiderVenom_AngleToXFlip(mover->angle));
  sprite->pos = mover->pos;
  if (target->unk_4 > 3) {
    elem->vel.x = 0, elem->vel.y = 0, elem->vel.z = 0;
  } else {
    Player* player = target->owner;
    Vec3 d;
    s32 tx, tz;

    Vec3_Delta(&d, &sprite->pos, &player->mover.pos);
    elem->hitbox.angle = ArcTan2_8(d.x, d.z);
    elem->vel.x = POLAR_X(20, elem->hitbox.angle);
    elem->vel.z = POLAR_Z(20, elem->hitbox.angle);
    tx = 0;
    tz = 0;
    if (elem->vel.x != 0) {
      tx = Div(d.x, elem->vel.x);
    }
    if (elem->vel.z != 0) {
      tz = Div(d.z, elem->vel.z);
    }
    if (tx > tz) {
      elem->vel.y = FixToInt(1, tx);
    } else {
      elem->vel.y = FixToInt(1, tz);
    }
  }
  AuxSprite_Hide(sprite);
  sprite->priority = 1;
}

s32 SpiderVenom_Update(SpiderVenom* p) {
  static void (*const PTR_ARRAY_085ae450[3])(SpiderVenom*, SpiderVenomShot*) = {
      nop_081e8660,
      SpiderVenomShot_StateFly,
      SpiderVenomShot_StateBlink,
  };  // 0x085AE450

  s32 i;

  for (i = 0; i < 4; i++) {
    if (SpiderVenom_IsActive(p, i)) {
      SpiderVenomShot* elem = &p->shots[i];

      PTR_ARRAY_085ae450[p->shots[i].state](p, elem);
    }
  }
  return 0;
}

s32 SpiderVenom_Destroy(SpiderVenom* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (SpiderVenom_IsActive(p, i)) {
      AuxSprite_Remove(&p->shots[i].sprite);
    }
  }
  return 0;
}

s32 SpiderVenom_Init(SpiderVenom* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_BOMB);
  p->animFile = GetFile(DIR_ANIMATION, ANIM_871C);
  p->activeMask = 0;
  return 0;
}

SpiderVenom* SpiderVenom_Create(void) {
  SpiderVenom* p = CreateEntity(ENTITY_UNK_10, sizeof(SpiderVenom));

  if (p != NULL) {
    SetEntityRoutine(p, SpiderVenom_Update, SpiderVenom_Destroy);
    if (SpiderVenom_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
