#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "random.h"
#include "sound.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

// elems 1 つ, delay フレーム待ってから爆発して消える
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxAnimState anim;      // 0x2C
  HitboxData hitbox;      // 0x3C
  AuxAnimFile* animFile;  // 0x8C, ANIM_121B
  u16 unk_90;             // 0x90, 0 を書くだけで読み手は未発見
  u8 state;               // 0x92, sEntity081f9cb8Updates の添字
  s8 idx;                 // 0x93, elems の添字, 解放すると -1
  u16 delay;              // 0x94, state 1 で待つフレーム数
  u8 unk_96[2];           // 0x96
  u16 timer;              // 0x98
  u8 unk_9a;              // 0x9A
  bool8 stateEntered;     // 0x9B, state を変えたら立てる, 入った最初の更新で落とす
} Entity081f9cb8Elem;
static_assert(sizeof(Entity081f9cb8Elem) == 156);

// 爆発を最大 8 個まとめて管理するシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_EFF_F422
  u8 unk_34[4];                 // 0x034
  u32 usedMask;                 // 0x038, 使用中の elems のビット
  Entity081f9cb8Elem elems[8];  // 0x03C
} Entity081f9cb8;
static_assert(sizeof(Entity081f9cb8) == 1308);

static Entity081f9cb8* gEntity081f9cb8;  // 0x03000210

Entity081f9cb8* Entity081f9cb8_Create(void);
void Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 param_3, s32 param_4);
struct Entity081f26bcElem* Entity081f26bc_Spawn(
    Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 ofsX, s32 ofsY);

static inline bool8 Entity081f9cb8_IsUsed(Entity081f9cb8* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) {
    return TRUE;
  } else {
    return FALSE;
  }
}

void Entity081f9cb8_OnHit(void) {}

void Entity081f9cb8_InitHitbox(Entity081f9cb8Elem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 unk_6, s32 unk_7, s32 unk_8) {
  Vec3 size;
  Vec3 offset;
  HitboxData* hitbox;

  VEC3_SET(size, Q8(0.25), Q8(0.5), Q8(0.25));
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_10 | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Entity081f9cb8_OnHit, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
}

void Entity081f9cb8_RegisterHitbox(Entity081f9cb8Elem* elem) {
  HitboxData* hitbox = &elem->hitbox;

  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  Hitbox_Register(hitbox);
}

Entity081f9cb8Elem* Entity081f9cb8_AllocElem(Entity081f9cb8* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity081f9cb8_IsUsed(p, i)) {
      Entity081f9cb8Elem* elem = &p->elems[i];

      SET_BIT(p->usedMask, i);
      elem->idx = i;
      return elem;
    }
  }
  return NULL;
}

// 残差は1命令, gRandTableIdx のアドレスがレジスタに載らず再ロードされる割当の差, table 先読みと & 0xFF の形は確定
NON_MATCH void Entity081f9cb8_SpawnWaitEffect(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 angle;
  s32 speed;
  u16* table = gRandomTable;

  angle = _Random(table) & 0xFF;
  speed = (_Random(table) & 63) - 32;
  Vec3_SetPolar(&vel, angle, speed);
  vel.y = (Random() & 15) + 30;
  Entity081ee2a0_SpawnDefault(pos, &vel, 30, 3);
#else
  INCFUNC("asm/func/Entity081f9cb8_SpawnWaitEffect.inc");
#endif
}

// 残差は1命令, gRandTableIdx のアドレスがレジスタに載らない割当の差 (Entity081f9cb8_SpawnWaitEffect と同じ), 前後半で table を分ける形は確定
NON_MATCH void Entity081f9cb8_SpawnDebris(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 life;

  {
    u16* table = gRandomTable;
    u32 angle = _Random(table) & 0xFF;
    s32 speed = (_Random(table) & 15) + 4;

    Vec3_SetPolar(&vel, angle, speed);
  }
  {
    u16* table = gRandomTable;

    vel.y = (_Random(table) & 31) + 12;
    life = (_Random(table) & 63) + 20;
  }
  Entity081f26bc_Spawn(pos, &vel, PTCL_GROUP_0, ANIM_D1B8, 3, 0, 49, 0, 2, 0, 0, life, 4, 1, 0x200004, 30, 8, 8);
#else
  INCFUNC("asm/func/Entity081f9cb8_SpawnDebris.inc");
#endif
}

void Entity081f9cb8_UpdateUnused(Entity081f9cb8* p, Entity081f9cb8Elem* elem) {}

void Entity081f9cb8_UpdateWait(Entity081f9cb8* p, Entity081f9cb8Elem* elem) {
  if (elem->stateEntered) {
    elem->timer = 0;
    elem->stateEntered = FALSE;
  }
  if (Mod(elem->timer, 6) == 0) {
    Entity081f9cb8_SpawnWaitEffect(&elem->sprite.pos);
  }
  if (elem->timer > elem->delay) {
    elem->state = 2;
    elem->stateEntered = TRUE;
  } else {
    elem->timer++;
  }
}

void Entity081f9cb8_UpdateExplode(Entity081f9cb8* p, Entity081f9cb8Elem* elem) {
  if (elem->stateEntered) {
    AuxSprite_Show(&elem->sprite);
    elem->timer = 0;
    PlaySound_082406e0(SONG_325);
    elem->stateEntered = FALSE;
  }
  if (elem->anim.cmdIdx >= 1 && elem->anim.cmdIdx <= 3) {
    Entity081f9cb8_RegisterHitbox(elem);
    if (Mod(elem->timer, 6) == 0) {
      Entity081f9cb8_SpawnDebris(&elem->sprite.pos);
    }
  }
  elem->timer++;
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim)) {
    elem->state = 3;
    elem->stateEntered = TRUE;
  }
}

void Entity081f9cb8_UpdateRemove(Entity081f9cb8* p, Entity081f9cb8Elem* elem) {
  if (elem->stateEntered) {
    elem->timer = 0;
    AuxSprite_Remove(&elem->sprite);
    CLEAR_BIT(p->usedMask, elem->idx);
    elem->idx = -1;
    elem->state = 0;
    elem->stateEntered = FALSE;
  }
}

// delay フレーム後に pos で爆発させる
void Entity081f9cb8_Spawn(Vec3* pos, s32 delay, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  Entity081f9cb8* p = gEntity081f9cb8;
  Entity081f9cb8Elem* elem;

  if (p == NULL) {
    p = Entity081f9cb8_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity081f9cb8_AllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->delay = delay;
  if ((u16)delay == 0) {
    elem->state = 2;
  } else {
    elem->state = 1;
  }
  elem->unk_90 = 0;
  elem->stateEntered = TRUE;
  elem->sprite.pos = *pos;
  elem->animFile = GetFile(DIR_ANIMATION, ANIM_121B);
  AuxSprite_Add(&elem->sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, elem->animFile, 6, 0, 0);
  Video_SetAuxSpritePltt(elem->sprite.gfx, 217);
  elem->sprite.priority = 2;
  AuxSprite_Hide(&elem->sprite);
  Entity081f9cb8_InitHitbox(elem, power, knockback, attrs, iframes, 0, 0, 0);
}

s32 Entity081f9cb8_Update(Entity081f9cb8* p) {
  static void (*const sEntity081f9cb8Updates[4])(Entity081f9cb8*, Entity081f9cb8Elem*) = {
      Entity081f9cb8_UpdateUnused,
      Entity081f9cb8_UpdateWait,
      Entity081f9cb8_UpdateExplode,
      Entity081f9cb8_UpdateRemove,
  };  // 0x085AE5E0

  Entity081f9cb8Elem* elems = p->elems;

  if (p->usedMask != 0) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (Entity081f9cb8_IsUsed(p, i)) {
        sEntity081f9cb8Updates[elems[i].state](p, &elems[i]);
      }
    }
  }
  return 0;
}

s32 Entity081f9cb8_Destroy(Entity081f9cb8* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (Entity081f9cb8_IsUsed(p, i)) {
      AuxSprite_Remove(&p->elems[i].sprite);
    }
  }
  gEntity081f9cb8 = NULL;
  return 0;
}

s32 Entity081f9cb8_Init(Entity081f9cb8* p) {
  p->usedMask = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_F422);
  gEntity081f9cb8 = p;
  return 0;
}

Entity081f9cb8* Entity081f9cb8_Create(void) {
  Entity081f9cb8* p;

  if (gEntity081f9cb8 != NULL) {
    return gEntity081f9cb8;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081f9cb8));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081f9cb8_Update, Entity081f9cb8_Destroy);
    if (Entity081f9cb8_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081f9cb8_ClearInstance(void) { gEntity081f9cb8 = NULL; }

s32 Entity081f9cb8_ExistsAt(Vec3* pos) {
  Entity081f9cb8* p = gEntity081f9cb8;
  s32 i;

  if (p == NULL) {
    return FALSE;
  }
  for (i = 0; i < 8; i++) {
    if (p->elems[i].state == 1 || p->elems[i].state == 2) {
      if (p->elems[i].sprite.pos.x == pos->x) {
        if (p->elems[i].sprite.pos.y == pos->y) {
          if (p->elems[i].sprite.pos.z == pos->z) {
            return TRUE;
          }
        }
      }
    }
  }
  return FALSE;
}

void Entity081f9cb8_CancelAll(void) {
  Entity081f9cb8* p = gEntity081f9cb8;

  if (p != NULL) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (p->elems[i].state != 3 && p->elems[i].state != 0) {
        p->elems[i].state = 3;
        p->elems[i].stateEntered = TRUE;
      }
    }
  }
}

NAKED void FUN_081f9db4(void) { INCFUNC("asm/func/FUN_081f9db4.inc"); }
