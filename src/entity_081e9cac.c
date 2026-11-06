#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "player.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

typedef struct {
  u8 state;            // 0x00, 下位3bitが状態関数表の添字, bit3 が立つと timer を張り直して anim を 2 番に戻す
  u8 unk_01;           // 0x01, 生成時に 0xFF
  u8 angle;            // 0x02, 8bit の向き, 上位3bitで anim の variant と hitPos のずらし方が決まる
  Vec3 pos;            // 0x04, 毎フレーム vel を足して sprite.pos に写す
  Vec3 vel;            // 0x0C
  HitboxData hitbox;   // 0x14
  AuxSprite sprite;    // 0x64
  AuxSprite sprite2;   // 0x90, 生成時は隠れている
  AuxAnimState anim;   // 0xBC, sprite のアニメ
  AuxAnimState anim2;  // 0xCC, sprite2 のアニメ
  Vec3 hitPos;         // 0xDC, sprite.pos を angle の向きにずらした hitbox の位置
  s8 idx;              // 0xE4, elems の添字, 空きは -1
  u16 stateEntered;    // 0xE6, 状態 3 に入ったときに 1, 状態 3 の最初のフレームで 0 に戻る
  s16 anim2Done;       // 0xE8, anim2 が一巡すると 1
  u16 hitboxId;        // 0xEA, Hitbox_Init の id
  u16 frameCount;      // 0xEC, 0 以外の間 hitbox を登録する
  s16 timer;           // 0xEE
  s16 lifetime;        // 0xF0, 0 になると状態 3 に移る
} Entity081e9cacElem;
static_assert(sizeof(Entity081e9cacElem) == 244);

typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_10
  AuxAnimFile* animFile;         // 0x18, ANIM_D6C8
  AuxSpriteGfx gfx;              // 0x1C, SPRITE_2D41
  u32 activeMask;                // 0x38, elems の使用中ビット
  Entity081e9cacElem elems[12];  // 0x3C
} Entity081e9cac;
static_assert(sizeof(Entity081e9cac) == 2988);

IWRAM_DATA Entity081e9cac* gEntity081e9cac = NULL;  // 0x030001B4

extern const void* const PTR_ARRAY_082523e8[4];

void Entity081e9cac_GetAnimVariant(s32 angle, u8* variant, AuxAnimPlayFlags* flags);
Entity081e9cac* Entity081e9cac_Create(void);
bool8 Entity081e9cacElem_CheckFloor(Entity081e9cacElem* elem);
void Entity081e9cacElem_UpdateHitPos(Entity081e9cacElem* elem);
Entity081e9cacElem* Entity081e9cac_Spawn(Vec3* pos, Vec3* offset, Vec3* vel, u32 angle, u32 hitboxId, s32 power, s32 knockbackPower, s32 invincibleTime, s32 lifetime);

static inline bool8 Entity081e9cac_IsElemUsed(Entity081e9cac* p, s32 i) {
  if (TEST_FLAGS(p->activeMask, 1 << i)) return TRUE;
  return FALSE;
}

// 148/149命令, 原典は elem を r3 に写して r2 を向きの計算に回し, 定数 1 を r4 に置く
NON_MATCH void Entity081e9cacElem_OnHit(HitboxData* a, HitboxData* b, Entity081e9cacElem* elem) {
#ifdef NONMATCHING_C
  if (!(b->flags & HBFLAG_UNK_7) && (b->flags & HBFLAG_UNK_0)) {
    if (b->ignoreMask & 0xF) {
      s32 hit;

      if (!(((Player*)b->owner)->flag20 & PFLAG20_UNK_3)) {
        hit = TRUE;
      } else {
        s32 d = FixToInt(6, (elem->angle + 0x20) & 0xFF) - FixToInt(6, (b->angle + 0x20) & 0xFF);

        hit = (d < 0 ? -d : d) == 2;
      }
      if (hit) {
        Vec3 d;

        elem->state = 3;
        elem->stateEntered = TRUE;
        Vec3_Diff(&d, &a->pos, &b->pos);
        a->halfSize.val = FixToInt(5, ArcTan2_8(d.x, d.z));
        b->hitState |= 1;
      }
    } else {
      Vec3 d;

      elem->state = 3;
      elem->stateEntered = TRUE;
      Vec3_Diff(&d, &a->pos, &b->pos);
      a->halfSize.val = FixToInt(5, ArcTan2_8(d.x, d.z));
    }
  }
#else
  INCFUNC("asm/func/Entity081e9cacElem_OnHit.inc");
#endif
}

void Entity081e9cacElem_InitHitbox(Entity081e9cacElem* elem, s32 power, s32 knockbackPower, s32 invincibleTime) {
  HitboxData* hitbox = &elem->hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 32, 82, 32);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, elem->hitboxId, HBFLAG_HITBOX | HBFLAG_UNK_9 | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 0, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockbackPower, 0x10, HBATTR_14 | HBATTR_CLOUD, invincibleTime);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, Entity081e9cacElem_OnHit, elem);
  hitbox->angle = elem->angle;
}

void Entity081e9cacElem_UpdateState0(Entity081e9cacElem* elem) {}

// state の bit3 が立っていたら anim を 2 番からやり直し, timer の間 sprite を隠す
void Entity081e9cacElem_UpdateRestart(Entity081e9cac* p, Entity081e9cacElem* elem) {
  if ((elem->state >> 3) & 1) {
    u8 variant;
    AuxAnimPlayFlags flags;

    elem->sprite.flags |= SPRFLAG_HIDDEN;
    elem->timer = 3;
    elem->state &= 7;
    Entity081e9cac_GetAnimVariant(elem->angle, &variant, &flags);
    AuxAnim_RestartAnim(&elem->anim, p->animFile, 2, variant, flags);
  }
  if (elem->timer <= 0) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  } else {
    elem->timer--;
  }
}

void Entity081e9cacElem_UpdateState1(Entity081e9cacElem* elem) {
  elem->sprite2.flags &= ~SPRFLAG_HIDDEN;
  AuxSprite_AdvanceAnim(&elem->sprite2, &elem->anim2);
}

void Entity081e9cacElem_SetLifetime(Entity081e9cacElem* elem, s32 lifetime) { elem->lifetime = lifetime; }

// sprite2 を出してアニメ 1 番から状態 2 (飛行) に移す
void Entity081e9cacElem_Launch(Entity081e9cacElem* elem) {
  Entity081e9cac* p = gEntity081e9cac;
  u8 variant;
  AuxAnimPlayFlags flags;

  if (p != NULL && elem != NULL) {
    elem->sprite2.flags &= ~SPRFLAG_HIDDEN;
    Entity081e9cac_GetAnimVariant(elem->angle, &variant, &flags);
    AuxAnim_RestartAnim(&elem->anim2, p->animFile, 1, variant, flags);
    AuxSprite_AdvanceAnim(&elem->sprite2, &elem->anim2);
    elem->anim2Done = 0;
    elem->state = 2;
  }
}

Entity081e9cacElem* Entity081e9cacElem_Remove(Entity081e9cacElem* elem) {
  Entity081e9cac* p = gEntity081e9cac;

  if (p == NULL || elem == NULL || elem->idx < 0) {
    return NULL;
  }
  if (Entity081e9cac_IsElemUsed(p, elem->idx) && elem->state == 1) {
    AuxSprite_Remove(&elem->sprite);
    AuxSprite_Remove(&elem->sprite2);
    CLEAR_BIT(p->activeMask, elem->idx);
    elem->idx = -1;
    elem->anim2Done = 0;
    elem->state = 0;
    return NULL;
  }
  return elem;
}

void Entity081e9cac_RemoveAll(void) {
  Entity081e9cac* p = gEntity081e9cac;
  s32 i;

  if (p != NULL && p->activeMask != 0) {
    for (i = 0; i < 12; i++) {
      if (Entity081e9cac_IsElemUsed(p, i)) {
        Entity081e9cacElem* elem = &p->elems[i];

        if (elem->state == 1) {
          AuxSprite_Remove(&elem->sprite);
          AuxSprite_Remove(&elem->sprite2);
          CLEAR_BIT(p->activeMask, elem->idx);
          elem->idx = -1;
          elem->anim2Done = 0;
          elem->state = 0;
        }
      }
    }
  }
}

// 飛行中, 寿命が尽きるか床に着くと状態 3 に移る
void Entity081e9cacElem_UpdateState2(Entity081e9cacElem* elem) {
  Entity081e9cac* p = gEntity081e9cac;
  AuxAnimState* anim = &elem->anim;
  AuxSprite* spr = &elem->sprite;
  u8 variant;
  AuxAnimPlayFlags flags;

  elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  if (elem->timer <= 0) {
    elem->pos.x += elem->vel.x;
    elem->pos.y += elem->vel.y;
    elem->pos.z += elem->vel.z;
    elem->sprite.pos.x = elem->pos.x;
    elem->sprite.pos.y = elem->pos.y;
    elem->sprite.pos.z = elem->pos.z;
  }
  Entity081e9cacElem_UpdateHitPos(elem);
  Entity081e9cac_GetAnimVariant(elem->angle, &variant, &flags);
  AuxAnim_SetAnim(anim, p->animFile, 2, variant, flags);
  AuxSprite_AdvanceAnim(spr, anim);
  if (elem->anim2Done != 1) {
    if (AuxSprite_AdvanceAnim(&elem->sprite2, &elem->anim2)) {
      elem->sprite2.flags |= SPRFLAG_HIDDEN;
      elem->anim2Done = 1;
    }
  }
  if (elem->frameCount != 0) {
    Hitbox_SetPos(&elem->hitbox, &elem->hitPos, 0);
    Hitbox_Register(&elem->hitbox);
  }
  elem->frameCount++;
  if (!Entity081e9cacElem_CheckFloor(elem)) {
    if (elem->lifetime > 0) {
      elem->lifetime--;
    } else {
      elem->state = 3;
      elem->stateEntered = TRUE;
    }
    Entity081e9cacElem_UpdateRestart(p, elem);
  }
}

// hitPos から vel で流しながら消えるアニメを流し, 終わったら枠を返す
void Entity081e9cacElem_UpdateState3(Entity081e9cacElem* elem) {
  Entity081e9cac* p = gEntity081e9cac;

  if (elem->stateEntered) {
    u8 variant;
    AuxAnimPlayFlags flags;

    Entity081e9cac_GetAnimVariant(elem->angle, &variant, &flags);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 3, 0, 0);
    elem->sprite.pos = elem->hitPos;
    elem->stateEntered = FALSE;
  }
  elem->sprite.pos.x += elem->vel.x;
  elem->sprite.pos.y += elem->vel.y;
  elem->sprite.pos.z += elem->vel.z;
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim)) {
    AuxSprite_Remove(&elem->sprite);
    AuxSprite_Remove(&elem->sprite2);
    CLEAR_BIT(p->activeMask, elem->idx);
    ClearMemory(elem, sizeof(Entity081e9cacElem));
    elem->idx = -1;
    elem->state = 0;
  }
}

Entity081e9cacElem* Entity081e9cac_AllocElem(Entity081e9cac* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Entity081e9cac_IsElemUsed(p, i)) {
      Entity081e9cacElem* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      elem->idx = i;
      return elem;
    }
  }
  return NULL;
}

void Entity081e9cac_GetAnimVariant(s32 angle, u8* variant, AuxAnimPlayFlags* flags) {
  angle = ((angle >> 5) + 3) & 7;
  switch (angle) {
    case FACE_DOWN_LEFT: {
      *variant = 3;
      *flags = ANIM_PLAY_XFLIP;
      break;
    }
    case FACE_LEFT: {
      *variant = 2;
      *flags = ANIM_PLAY_XFLIP;
      break;
    }
    case FACE_UP_LEFT: {
      *variant = 1;
      *flags = ANIM_PLAY_XFLIP;
      break;
    }
    default: {
      *variant = angle;
      *flags = 0;
      break;
    }
  }
}

// 121/124命令, 原典は case 0〜2 の後半を共通化せず, hitPos と sprite.pos のアドレスを持つレジスタも逆, 試済: hitPos/pos のポインタ化, elem 直書き
NON_MATCH void Entity081e9cacElem_UpdateHitPos(Entity081e9cacElem* elem) {
#ifdef NONMATCHING_C
  Vec3* pos = &elem->sprite.pos;

  elem->hitPos = *pos;
  elem->hitPos = *pos;
  switch (elem->angle >> 5) {
    case 0: {
      elem->hitPos.x = pos->x + 128;
      elem->hitPos.z = pos->z - 64;
      elem->sprite2.pos.y = pos->y - 8;
      pos->y = pos->y + 16;
      break;
    }
    case 1: {
      elem->hitPos.x = pos->x + 128;
      elem->hitPos.z = pos->z + 128;
      elem->sprite2.pos.y = pos->y - 8;
      pos->y = pos->y + 16;
      break;
    }
    case 2: {
      elem->hitPos.x = pos->x - 32;
      elem->hitPos.z = pos->z + 128;
      elem->sprite2.pos.y = pos->y - 8;
      pos->y = pos->y + 16;
      break;
    }
    case 3: {
      elem->hitPos.x = pos->x - 96;
      elem->hitPos.z = pos->z + 32;
      elem->sprite2.pos.y = pos->y + 16;
      pos->y = pos->y - 8;
      pos->z = pos->z - 16;
      break;
    }
    case 4: {
      elem->hitPos.x = pos->x - 128;
      elem->hitPos.z = pos->z - 32;
      elem->sprite2.pos.y = pos->y + 16;
      pos->y = pos->y - 8;
      pos->z = pos->z - 16;
      break;
    }
    case 5: {
      elem->hitPos.x = pos->x - 64;
      elem->hitPos.z = pos->z - 96;
      elem->sprite2.pos.y = pos->y + 16;
      pos->y = pos->y - 8;
      pos->z = pos->z - 16;
      break;
    }
    case 6: {
      elem->hitPos.x = pos->x - 32;
      elem->hitPos.z = pos->z - 128;
      elem->sprite2.pos.y = pos->y + 16;
      pos->y = pos->y - 8;
      break;
    }
    case 7: {
      elem->hitPos.x = pos->x + 128;
      elem->hitPos.y = pos->y + 64;
      elem->hitPos.z = pos->z - 96;
      elem->sprite2.pos.y = pos->y + 16;
      pos->y = pos->y - 8;
      pos->z = pos->z - 16;
      break;
    }
  }
#else
  INCFUNC("asm/func/Entity081e9cacElem_UpdateHitPos.inc");
#endif
}

// angle の向きに speed で飛ぶ玉を出す
Entity081e9cacElem* Entity081e9cac_SpawnAtAngle(Vec3* pos, u32 angle, s32 speed, s32 lifetime, s32 power, s32 knockbackPower, s32 invincibleTime) {
  Vec3 vel;

  Vec3_SetPolar(&vel, angle, speed);
  return Entity081e9cac_Spawn(pos, NULL, &vel, angle, 0x309, power, knockbackPower, invincibleTime, lifetime);
}

// 258/258命令, AuxSprite_AdvanceAnim に渡す sprite の写しが原典は r8, こちらは ip, 試済: spr ローカル, &elem->sprite 直書き, priority の書き方
NON_MATCH Entity081e9cacElem* Entity081e9cac_Spawn(Vec3* pos, Vec3* offset, Vec3* vel, u32 angle, u32 hitboxId, s32 power, s32 knockbackPower, s32 invincibleTime, s32 lifetime) {
#ifdef NONMATCHING_C
  Entity081e9cac* p;
  Entity081e9cacElem* elem;
  AuxSprite* spr;
  AuxSprite* spr2;
  u8 variant;
  AuxAnimPlayFlags flags;

  if (gEntity081e9cac == NULL) {
    p = Entity081e9cac_Create();
    if (p == NULL) {
      return NULL;
    }
  } else {
    p = gEntity081e9cac;
  }
  elem = Entity081e9cac_AllocElem(p);
  if (elem == NULL) {
    return NULL;
  }
  spr = &elem->sprite;
  spr2 = &elem->sprite2;
  AuxSprite_Add(spr2, &p->gfx, 0);
  AuxSprite_Add(spr, &p->gfx, 0);
  elem->sprite.flags |= SPRFLAG_HIDDEN;
  spr2->flags |= SPRFLAG_HIDDEN;
  elem->frameCount = 0;
  spr->pos = *pos;
  if (offset != NULL) {
    spr->pos.x += offset->x;
    spr->pos.y += offset->y;
    spr->pos.z += offset->z;
  }
  elem->vel = *vel;
  elem->unk_01 = 0xFF;
  elem->angle = angle;
  elem->hitboxId = hitboxId;
  elem->lifetime = lifetime;
  elem->pos = spr->pos;
  elem->sprite2.pos = spr->pos;
  spr2->flags |= SPRFLAG_HIDDEN;
  Entity081e9cac_GetAnimVariant(elem->angle, &variant, &flags);
  AuxAnim_SetAnim(&elem->anim, p->animFile, 2, variant, flags);
  AuxAnim_RestartAnim(&elem->anim2, p->animFile, 0, variant, flags);
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  Entity081e9cacElem_InitHitbox(elem, power, knockbackPower, invincibleTime);
  Entity081e9cacElem_UpdateHitPos(elem);
  elem->state = 1;
  spr->priority = 1;
  elem->sprite2.priority = 1;
  return elem;
#else
  INCFUNC("asm/func/Entity081e9cac_Spawn.inc");
#endif
}

s32 Entity081e9cac_Update(Entity081e9cac* p) {
  void (*funcs[4])(Entity081e9cacElem*);
  s32 i;

  memcpy(funcs, PTR_ARRAY_082523e8, sizeof(funcs));
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, FLAG030047A4_GAMEOVER) || TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2) || p->activeMask == 0) {
    return 0;
  }
  for (i = 0; i < 12; i++) {
    if (Entity081e9cac_IsElemUsed(p, i)) {
      Entity081e9cacElem* elem = &p->elems[i];

      funcs[elem->state & 7](elem);
      elem->hitbox.flags &= ~HBFLAG_HIDDEN;
    }
  }
}

s32 Entity081e9cac_Destroy(Entity081e9cac* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Entity081e9cac_IsElemUsed(p, i)) {
      Entity081e9cacElem* elem = &p->elems[i];

      AuxSprite_Remove(&elem->sprite);
      AuxSprite_Remove(&elem->sprite2);
    }
  }
  gEntity081e9cac = NULL;
}

s32 Entity081e9cac_Init(Entity081e9cac* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_2D41);
  p->animFile = GetFile(DIR_ANIMATION, ANIM_D6C8);
  gEntity081e9cac = p;
  p->activeMask = 0;
}

Entity081e9cac* Entity081e9cac_Create(void) {
  Entity081e9cac* p;

  if (gEntity081e9cac != NULL) {
    return gEntity081e9cac;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081e9cac));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081e9cac_Update, Entity081e9cac_Destroy);
    if (Entity081e9cac_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081e9cac_ClearGlobal(void) { gEntity081e9cac = NULL; }

bool8 Entity081e9cacElem_CheckFloor(Entity081e9cacElem* elem) {
  if (elem->anim2Done == 1 || elem->frameCount > 4) {
    s32 y = elem->sprite.pos.y;

    if (y < (u32)TileHeightAt(&elem->hitPos)) {
      goto landed;
    }
  }
  return FALSE;
landed:
  elem->state = 3;
  elem->stateEntered = TRUE;
  return TRUE;
}
