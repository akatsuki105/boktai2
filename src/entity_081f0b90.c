#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"
#include "vm.h"

typedef struct {
  AuxSprite sprites[4];   // 0x000, 画面座標で描く, 状態 1 では 3 枚を縦に 32 ずつずらし, 状態 2 では 4 枚を十字に広げる
  AuxAnimState anims[4];  // 0x0B0
  Vec3 pos;               // 0x0F0, 生成位置 (ワールド座標)
  Vec3 hitPos;            // 0x0F8, pos から y を 0x300 下げた hitbox の位置
  HitboxData hitbox;      // 0x100
  s16 unk_150;            // 0x150
  u8 state;               // 0x152, PTR_ARRAY_085ae518 の添字, 1 で 5 フレーム判定を出し, 2 で広がり, アニメが一巡すると 3 で片付く
  s8 idx;                 // 0x153, elems の添字, 空きは -1
  u16 scriptID;           // 0x154, 片付けるときに 0 でなければ VM_ExecByID で実行する
  u8 unk_156[2];          // 0x156
  u16 timer;              // 0x158, 状態に入ってからのフレーム数
  bool8 stateEntered;     // 0x15A, 状態が変わったときに 1, 次の状態関数の最初で 0 に戻る
} Entity081f0b90Elem;
static_assert(sizeof(Entity081f0b90Elem) == 348);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_SKELETON_MISC
  AuxAnimFile* animFile;        // 0x034, ANIM_1DC3
  u32 activeMask;               // 0x038, elems の使用中ビット
  Entity081f0b90Elem elems[4];  // 0x03C
} Entity081f0b90;
static_assert(sizeof(Entity081f0b90) == 1452);

static Entity081f0b90* gEntity081f0b90;  // 0x030001E4

static inline bool8 Entity081f0b90_IsElemUsed(Entity081f0b90* p, s32 i) {
  if (TEST_FLAGS(p->activeMask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081f0b90Elem_UpdateState0(Entity081f0b90*, Entity081f0b90Elem*);
void Entity081f0b90Elem_UpdateState2(Entity081f0b90*, Entity081f0b90Elem*);
void Entity081f0b90Elem_UpdateState3(Entity081f0b90*, Entity081f0b90Elem*);
void Entity081f0b90Elem_UpdateState1(Entity081f0b90*, Entity081f0b90Elem*);
Entity081f0b90Elem* Entity081f0b90_AllocElem(Entity081f0b90* p);
Entity081f0b90* Entity081f0b90_Create(void);
s32 Entity081f0b90_Update(Entity081f0b90* p);
s32 Entity081f0b90_Destroy(Entity081f0b90* p);
s32 Entity081f0b90_Init(Entity081f0b90* p);
Entity081f0b90Elem* Entity081f0b90_TryAllocElem(Entity081f0b90* p);
void Entity081f0b90Elem_InitHitbox(Entity081f0b90Elem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes);

void (*const PTR_ARRAY_085ae518[4])(Entity081f0b90*, Entity081f0b90Elem*) = {
    Entity081f0b90Elem_UpdateState0,
    Entity081f0b90Elem_UpdateState1,
    Entity081f0b90Elem_UpdateState2,
    Entity081f0b90Elem_UpdateState3,
};  // 0x085AE518

void Entity081f0b90Elem_ExecScript(Entity081f0b90Elem* elem) {
  if (elem->scriptID != 0) {
    VM_ExecByID(elem->scriptID, 0);
  }
}

void Entity081f0b90Elem_OnHit(HitboxData* a, HitboxData* b, Entity081f0b90Elem* elem) {}

void Entity081f0b90Elem_InitHitbox(Entity081f0b90Elem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  HitboxData* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 128, 32, 128);
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Entity081f0b90Elem_OnHit, elem);
}

void Entity081f0b90Elem_UpdateState0(Entity081f0b90* p, Entity081f0b90Elem* elem) {}

// 308/293命令の下書き, 原典は z 成分を 128 との muls で出し (x はシフト), elem と sprites のポインタの持ち方も違う
NON_MATCH void Entity081f0b90Elem_UpdateState2(Entity081f0b90* p, Entity081f0b90Elem* elem) {
#ifdef NONMATCHING_C
  bool32 finished;
  s32 i;

  if (elem->stateEntered) {
    for (i = 0; i < 4; i++) {
      AuxSprite* spr = &elem->sprites[i];
      Vec3 d;
      u32 yflip;
      u32 xflip;

      spr->flags &= ~SPRFLAG_SCREEN_COORD;
      spr->pos = elem->hitPos;
      Vec3_SetPolar(&d, i << 6, 128);
      Vec3_Add(&spr->pos, &d);
      switch (i) {
        case 0: {
          yflip = ANIM_PLAY_YFLIP;
          xflip = 0;
          break;
        }
        case 1: {
          yflip = ANIM_PLAY_YFLIP;
          xflip = ANIM_PLAY_XFLIP;
          break;
        }
        case 2: {
          yflip = 0;
          xflip = ANIM_PLAY_XFLIP;
          break;
        }
        default: {
          yflip = 0;
          xflip = 0;
          break;
        }
      }
      AuxAnim_SetAnim(&elem->anims[i], p->animFile, 16, 0, yflip | xflip);
      spr->flags &= ~SPRFLAG_HIDDEN;
    }
    elem->timer = 0;
    elem->stateEntered = FALSE;
  }
  for (i = 0; i < 4; i++) {
    finished = AuxSprite_AdvanceAnim(&elem->sprites[i], &elem->anims[i]);
  }
  Hitbox_SetPos(&elem->hitbox, &elem->hitPos, 0);
  Hitbox_Register(&elem->hitbox);
  if (finished) {
    elem->state = 3;
    elem->stateEntered = TRUE;
  } else {
    elem->timer++;
  }
#else
  INCFUNC("asm/func/Entity081f0b90Elem_UpdateState2.inc");
#endif
}

// スプライトを外して枠を返し, scriptID があれば実行する
void Entity081f0b90Elem_UpdateState3(Entity081f0b90* p, Entity081f0b90Elem* elem) {
  s32 i;

  if (elem->stateEntered) {
    CLEAR_BIT(p->activeMask, elem->idx);
    elem->state = 0;
    for (i = 0; i < 4; i++) {
      if (elem->sprites[i].active) {
        AuxSprite_Remove(&elem->sprites[i]);
      }
    }
    elem->idx = -1;
    elem->unk_150 = 0;
    Entity081f0b90Elem_ExecScript(elem);
    elem->stateEntered = FALSE;
  }
}

// 3 枚を縦に並べて画面座標で出し, 5 フレームだけ判定を出してから広がりの状態に移る
void Entity081f0b90Elem_UpdateState1(Entity081f0b90* p, Entity081f0b90Elem* elem) {
  s32 i;

  if (elem->stateEntered) {
    PlaySound_082406e0(SONG_945);
    elem->stateEntered = FALSE;
  }
  for (i = 0; i < 3; i++) {
    AuxSprite* spr = &elem->sprites[i];

    spr->flags &= ~SPRFLAG_HIDDEN;
    AuxSprite_AdvanceAnim(spr, &elem->anims[i]);
    {
      Vec3* v = &spr->pos;

      WorldToVp(v, &elem->pos);
      v->x = v->x - gCameraVpCoords.x + 120;
      v->y = v->y - gCameraVpCoords.y + 90;
      v->z = v->z - gCameraVpCoords.z;
    }
    spr->pos.y += i * 32;
  }
  if (elem->timer > 4) {
    elem->state = 2;
    elem->stateEntered = TRUE;
  } else {
    Hitbox_SetPos(&elem->hitbox, &elem->hitPos, 0);
    Hitbox_Register(&elem->hitbox);
    elem->timer++;
  }
}

Entity081f0b90Elem* Entity081f0b90_AllocElem(Entity081f0b90* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!Entity081f0b90_IsElemUsed(p, i)) {
      Entity081f0b90Elem* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      ClearMemory(elem, sizeof(Entity081f0b90Elem));
      elem->idx = i;
      return elem;
    }
  }
  return NULL;
}

Entity081f0b90Elem* Entity081f0b90_TryAllocElem(Entity081f0b90* p) {
  Entity081f0b90Elem* elem = Entity081f0b90_AllocElem(p);

  if (elem != NULL) {
    return elem;
  }
  return NULL;
}

// 205/205命令, spr->pos.y に i * 32 を足すとき原典は pos.y を r2 に読むが, こちらは r1
NON_MATCH void Entity081f0b90_Spawn(Vec3* pos, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 _, u32 scriptID) {
#ifdef NONMATCHING_C
  Entity081f0b90* p = gEntity081f0b90;
  Entity081f0b90Elem* elem;
  Vec3 vp;
  s32 i;

  if (p == NULL) {
    p = Entity081f0b90_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity081f0b90_TryAllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->unk_150 = 0;
  elem->timer = 0;
  elem->stateEntered = TRUE;
  elem->pos = *pos;
  elem->scriptID = scriptID;
  elem->hitPos = *pos;
  elem->hitPos.y -= 0x300;
  {
    Vec3* v = &vp;

    WorldToVp(v, pos);
    v->x = v->x - gCameraVpCoords.x + 120;
    v->y = v->y - gCameraVpCoords.y + 90;
    v->z = v->z - gCameraVpCoords.z;
  }
  for (i = 0; i < 4; i++) {
    AuxSprite* spr = &elem->sprites[i];

    AuxSprite_Add(spr, &p->gfx, 0);
    spr->flags |= SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN;
    spr->priority = 1;
  }
  for (i = 0; i < 3; i++) {
    AuxSprite* spr = &elem->sprites[i];

    AuxAnim_SetAnim(&elem->anims[i], p->animFile, 15, 0, 0);
    elem->anims[i].cmdIdx = Random() & 3;
    Video_SetAuxSpritePltt(spr->gfx, 250);
    spr->pos = vp;
    spr->pos.y += i * 32;
  }
  Entity081f0b90Elem_InitHitbox(elem, power, knockback, attrs, iframes);
#else
  INCFUNC("asm/func/Entity081f0b90_Spawn.inc");
#endif
}

s32 Entity081f0b90_Update(Entity081f0b90* p) {
  Entity081f0b90Elem* elems = p->elems;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (Entity081f0b90_IsElemUsed(p, i)) {
      PTR_ARRAY_085ae518[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081f0b90_Destroy(Entity081f0b90* p) {
  s32 i, j;

  for (i = 0; i < 4; i++) {
    if (Entity081f0b90_IsElemUsed(p, i)) {
      Entity081f0b90Elem* elem = &p->elems[i];

      for (j = 0; j < 4; j++) {
        if (elem->sprites[j].active) {
          AuxSprite_Remove(&elem->sprites[j]);
        }
      }
    }
  }
  gEntity081f0b90 = NULL;
  return 0;
}

s32 Entity081f0b90_Init(Entity081f0b90* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_SKELETON_MISC);
  p->animFile = GetFile(DIR_ANIMATION, ANIM_1DC3);
  p->activeMask = 0;
  gEntity081f0b90 = p;
  return 0;
}

Entity081f0b90* Entity081f0b90_Create(void) {
  Entity081f0b90* p;

  if (gEntity081f0b90 != NULL) {
    return gEntity081f0b90;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081f0b90));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081f0b90_Update, Entity081f0b90_Destroy);
    if (Entity081f0b90_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081f0b90_ClearGlobal(void) { gEntity081f0b90 = NULL; }
