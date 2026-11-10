#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

// flags の bit3 で obj が指すスプライト
typedef struct {
  AuxSprite sprite;  // 0x00
  AuxSpriteGfx gfx;  // 0x2C
} Entity081f26bcSprite;
static_assert(sizeof(Entity081f26bcSprite) == 72);

// flags の bit4 で obj が指す粒子
typedef struct {
  Particle ptcl;         // 0x00
  ParticleGroup* group;  // 0x28
} Entity081f26bcPtcl;
static_assert(sizeof(Entity081f26bcPtcl) == 44);

// 動く破片 1 つ, Entity081f26bc_Spawn で出す
typedef struct {
  void* obj;           // 0x00, flags の bit3 なら AuxSprite + AuxSpriteGfx (0x48), bit4 なら Particle + ParticleGroup* (0x2C) を Malloc したもの
  AuxAnimState anim;   // 0x04
  Vec3 vel;            // 0x14
  HitboxData hitbox;   // 0x1C, flags の bit2 と bit8 が立っているときだけ登録する
  u16 flags;           // 0x6C, bit2: hitbox あり, bit3: AuxSprite, bit4: Particle, bit7: vel が 0 でない, bit8: hitbox が有効
  u8 state;            // 0x6E, sEntity081f26bcStates の添字, 0: 空き, 3: 点滅して消える
  s8 idx;              // 0x6F, elems の添字, 空きなら -1
  u16 life;            // 0x70
  u16 unk_72;          // 0x72
  u16 vanishTimer;     // 0x74, 点滅して消える状態の経過フレーム
  bool8 stateEntered;  // 0x76
  u8 hitboxWait;       // 0x77, 攻撃判定を次に有効にするまでのフレーム数, 有効にすると 3 から数え直す
} Entity081f26bcElem;
static_assert(sizeof(Entity081f26bcElem) == 120);

// 破片を 24 個まで動かす
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  u32 usedMask;                  // 0x018, bit i が立っていれば elems[i] が使用中
  Entity081f26bcElem elems[24];  // 0x01C
} Entity081f26bc;
static_assert(sizeof(Entity081f26bc) == 2908);

static Entity081f26bc* gEntity081f26bc;  // 0x030001EC

static inline bool8 Entity081f26bc_IsUsed(Entity081f26bc* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

void Entity081f26bc_StateNone(Entity081f26bc* p, Entity081f26bcElem* e);
void Entity081f26bc_StatePlayAnim(Entity081f26bc* p, Entity081f26bcElem* e);
void Entity081f26bc_StateBounce(Entity081f26bc* p, Entity081f26bcElem* e);
void Entity081f26bc_StateVanish(Entity081f26bc* p, Entity081f26bcElem* e);
void Entity081f26bc_OnHit(void);
s32 Entity081f26bc_Update(Entity081f26bc* p);
s32 Entity081f26bc_Destroy(Entity081f26bc* p);
s32 Entity081f26bc_Init(Entity081f26bc* p);
Entity081f26bc* Entity081f26bc_Create(void);

void (*const sEntity081f26bcStates[4])(Entity081f26bc*, Entity081f26bcElem*) = {
    Entity081f26bc_StateNone,
    Entity081f26bc_StatePlayAnim,
    Entity081f26bc_StateBounce,
    Entity081f26bc_StateVanish,
};  // 0x085AE538

// 攻撃判定を持つ破片の判定を, 1 フレームに 6 個まで, それぞれ 3 フレームおきに有効にする
void Entity081f26bc_ScheduleHitboxes(Entity081f26bc* p) {
  Entity081f26bcElem* elems = p->elems;
  s32 count = 0;
  s32 i;

  for (i = 0; i < 24; i++) {
    if (Entity081f26bc_IsUsed(p, i) && (elems->flags & 4)) {
      if (elems[i].hitboxWait != 0) {
        elems[i].hitboxWait--;
      } else if (count < 6) {
        elems[i].hitboxWait = 3;
        elems[i].flags |= 0x100;
        count++;
      }
    }
  }
}

// 攻撃判定が有効なら pos へ動かして登録する
void Entity081f26bc_UpdateHitbox(Entity081f26bcElem* e, Vec3* pos) {
  if (!(e->flags & 4)) {
    return;
  }
  if (e->flags & 0x100) {
    if (pos != NULL) {
      Hitbox_SetPos(&e->hitbox, pos, 0);
    }
    Hitbox_Register(&e->hitbox);
  }
}

void Entity081f26bc_OnHit(void) {}

// 破片の攻撃判定を作る
void Entity081f26bc_InitHitbox(Entity081f26bcElem* e, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) {
  Vec3 size;
  Vec3 offset;
  HitboxData* hitbox;

  VEC3_SET(size, Q8(0.0625), Q8(0.125), Q8(0.0625));
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &e->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Entity081f26bc_OnHit, e);
  if (e->flags & 8) {
    Hitbox_SetPos(hitbox, &((AuxSprite*)e->obj)->pos, 0);
  } else {
    Hitbox_SetPos(hitbox, &((Particle*)e->obj)->pos, 0);
  }
}

void Entity081f26bc_StateNone(Entity081f26bc* p, Entity081f26bcElem* e) {}

// 空いている破片を1つ確保して 0 で埋める
Entity081f26bcElem* Entity081f26bc_AllocElem(Entity081f26bc* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    if (!Entity081f26bc_IsUsed(p, i)) {
      Entity081f26bcElem* e = &p->elems[i];

      p->usedMask |= 1 << i;
      ClearMemory(e, sizeof(Entity081f26bcElem));
      e->idx = i;
      return e;
    }
  }
  return NULL;
}

// Entity081f26bc_StateVanish と同じ壁, 原典は anim を ip に追い出して使うたび低位レジスタへ移す (380/396)
NON_MATCH void Entity081f26bc_StatePlayAnim(Entity081f26bc* p, Entity081f26bcElem* e) {
#ifdef NONMATCHING_C
  bool32 finished;
  Vec3* pos;

  if (e->stateEntered) {
    if (e->flags & 8) {
      AuxSprite_Show(e->obj);
    } else {
      Particle_Show(e->obj);
    }
    e->vanishTimer = 0;
    e->stateEntered = FALSE;
  }
  Entity081f26bc_UpdateHitbox(e, NULL);
  if (e->flags & 8) {
    finished = AuxSprite_AdvanceAnim(e->obj, &e->anim);
    pos = &((AuxSprite*)e->obj)->pos;
  } else {
    Entity081f26bcPtcl* ptcl = e->obj;

    finished = Particle_AdvanceAnim(&ptcl->ptcl, ptcl->group, &e->anim);
    pos = &((Particle*)e->obj)->pos;
  }
  if (e->flags & 0x80) {
    Vec3_Add(pos, &e->vel);
  }
  e->vanishTimer++;
  if (finished && e->life == 0) {
    if (e->flags & 1) {
      CLEAR_BIT(gEntity081f26bc->usedMask, e->idx);
      e->state = 0;
      if (e->flags & 8) {
        AuxSprite* spr = e->obj;

        if (spr->active) {
          AuxSprite_Remove(spr);
          Free(e->obj);
        }
      } else {
        Particle* ptcl = e->obj;

        if (ptcl->active) {
          Particle_Remove(ptcl);
          Free(e->obj);
        }
      }
      e->idx = -1;
      e->flags = 0;
    } else {
      e->state = 3;
    }
    e->stateEntered = TRUE;
  } else if (e->life != 0) {
    e->life--;
  }
#else
  INCFUNC("asm/func/Entity081f26bc_StatePlayAnim.inc");
#endif
}

// 残差はレジスタ割当, 原典は vel と pos のアドレスを別の順で作り pos.y を ptcl 経由で読み書きする, vel / pos のローカル化は試済
NON_MATCH void Entity081f26bc_StateBounce(Entity081f26bc* p, Entity081f26bcElem* e) {
#ifdef NONMATCHING_C
  Particle* ptcl = e->obj;
  Vec3* pos;
  bool32 finished;

  if (e->stateEntered) {
    Particle_Show(ptcl);
    e->vanishTimer = 0;
    e->stateEntered = FALSE;
  }
  pos = &ptcl->pos;
  if (e->flags & 0x80) {
    s32 groundY;

    Vec3_Add(pos, &e->vel);
    groundY = (TileAtIndex(GetCollisionTileIdx(pos))->heightStairs & 0xF) << 8;
    if (pos->y <= groundY) {
      pos->y = groundY;
      e->vel.x = Div(e->vel.x * 5, 10);
      e->vel.y = Div(abs(e->vel.y) * 2, 10);
      e->vel.z = Div(e->vel.z * 5, 10);
      if (e->vel.x * e->vel.x + e->vel.y * e->vel.y + e->vel.z * e->vel.z == 0) {
        e->flags &= ~0x80;
      }
    } else if (Mod(e->vanishTimer, 4) != 0) {
      e->vel.y -= 2;
    }
  }
  Entity081f26bc_UpdateHitbox(e, pos);
  finished = Particle_AdvanceAnim(ptcl, ((Entity081f26bcPtcl*)e->obj)->group, &e->anim);
  if (e->life != 0) {
    if (e->anim.cmdIdx == 5 && e->anim.tick == e->anim.wait - 1) {
      e->anim.cmdIdx = 0;
      e->anim.tick = 0;
    }
    e->life--;
  }
  e->vanishTimer++;
  if (finished) {
    if (e->flags & 1) {
      CLEAR_BIT(gEntity081f26bc->usedMask, e->idx);
      e->state = 0;
      if (e->flags & 8) {
        AuxSprite* spr = e->obj;

        if (spr->active) {
          AuxSprite_Remove(spr);
          Free(e->obj);
        }
      } else {
        Particle* ptcl = e->obj;

        if (ptcl->active) {
          Particle_Remove(ptcl);
          Free(e->obj);
        }
      }
      e->idx = -1;
      e->flags = 0;
    } else {
      e->state = 3;
    }
    e->stateEntered = TRUE;
  }
#else
  INCFUNC("asm/func/Entity081f26bc_StateBounce.inc");
#endif
}

// 点滅して消える状態, アニメを進めながら点滅させ, 消えきったら obj を解放して枠を空ける
// 残差はレジスタ割当 (292/321), 原典は anim を ip に追い出して使うたび低位レジスタへ移すが, こちらは r4 に収まり &e->flags が r8 に回る
// 手動送りは AuxSprite_AdvanceAnim / Particle_AdvanceAnim で原典と同形, anim のローカル化 (関数頭 / 分岐内), 送り全体の inline 化は試済
NON_MATCH void Entity081f26bc_StateVanish(Entity081f26bc* p, Entity081f26bcElem* e) {
#ifdef NONMATCHING_C
  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->vanishTimer = 0;
  }
  if (e->flags & 8) {
    AuxSprite_AdvanceAnim(e->obj, &e->anim);
  } else {
    Entity081f26bcPtcl* ptcl = e->obj;

    Particle_AdvanceAnim(&ptcl->ptcl, ptcl->group, &e->anim);
  }
  if (Sprite_UpdateVanishBlink(e->flags & 8 ? &((AuxSprite*)e->obj)->flags : &((Particle*)e->obj)->flags, e->vanishTimer, 60, 40)) {
    CLEAR_BIT(gEntity081f26bc->usedMask, e->idx);
    e->state = 0;
    if (e->flags & 8) {
      AuxSprite* spr = e->obj;

      if (spr->active) {
        AuxSprite_Remove(spr);
        Free(e->obj);
      }
    } else {
      Particle* ptcl = e->obj;

      if (ptcl->active) {
        Particle_Remove(ptcl);
        Free(e->obj);
      }
    }
    e->idx = -1;
    e->flags = 0;
  } else {
    e->vanishTimer++;
  }
#else
  INCFUNC("asm/func/Entity081f26bc_StateVanish.inc");
#endif
}

// obj のスプライトを読み込み, アニメファイルを返す
AuxAnimFile* Entity081f26bc_LoadAuxSprite(Entity081f26bcElem* e, SpriteID32 spriteID, u32 animFileID) {
  Video_GetAuxSprite(&((Entity081f26bcSprite*)e->obj)->gfx, spriteID);
  return GetFile(DIR_ANIMATION, animFileID);
}

// 破片を1つ出す, flags の bit3 ならスプライト, bit4 なら粒子として作る
Entity081f26bcElem* Entity081f26bc_Spawn(
    Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 ofsX, s32 ofsY) {
  Entity081f26bc* p = gEntity081f26bc;
  Entity081f26bcElem* e;
  AuxAnimFile* animFile;

  if (p == NULL) {
    p = Entity081f26bc_Create();
    if (p == NULL) {
      return NULL;
    }
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
    return NULL;
  }
  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return NULL;
  }
  e = Entity081f26bc_AllocElem(p);
  if (e == NULL) {
    return NULL;
  }
  e->flags = flags;
  e->stateEntered = TRUE;
  e->state = 1;
  e->vel = *vel;
  if (vel->x * vel->x + vel->y * vel->y + vel->z * vel->z != 0) {
    e->flags |= 0x80;
  }
  e->life = life;
  if (e->flags & 8) {
    AuxSprite* sprite;

    e->obj = Malloc(sizeof(Entity081f26bcSprite));
    ClearMemory(e->obj, sizeof(Entity081f26bcSprite));
    sprite = e->obj;
    sprite->pos = *pos;
    animFile = Entity081f26bc_LoadAuxSprite(e, sprID, animFID);
    AuxSprite_Add(sprite, &((Entity081f26bcSprite*)e->obj)->gfx, 0);
    AuxAnim_SetAnim(&e->anim, animFile, animIdx, animVariant, animFlags);
    Video_SetAuxSpritePltt(sprite->gfx, plttID);
    AuxSprite_AdvanceAnim(sprite, &e->anim);
    AuxSprite_Hide(sprite);
    sprite->flags |= sprFlags;
    sprite->priority = prio;
  } else if (e->flags & 0x10) {
    Particle* ptcl;
    Entity081f26bcPtcl* obj;

    e->obj = Malloc(sizeof(Entity081f26bcPtcl));
    ClearMemory(e->obj, sizeof(Entity081f26bcPtcl));
    ptcl = e->obj;
    ptcl->pos = *pos;
    obj = e->obj;
    obj->group = GetParticleGroup(sprID);
    animFile = GetFile(DIR_ANIMATION, animFID);
    Particle_Add(ptcl, ((Entity081f26bcPtcl*)e->obj)->group, 0);
    Particle_SetOffset(ptcl, -ofsX, -ofsY);
    AuxAnim_SetAnim(&e->anim, animFile, animIdx, animVariant, animFlags);
    Particle_Hide(ptcl);
    ptcl->flags |= sprFlags;
    ptcl->priority = prio;
    if (e->flags & 0x20) {
      e->state = 2;
    }
  }
  if (power > 0) {
    Entity081f26bc_InitHitbox(e, power, knockback, attrs, iframes);
    e->flags |= 4;
  }
  return e;
}

// 使用中の破片を state ごとに動かす
s32 Entity081f26bc_Update(Entity081f26bc* p) {
  Entity081f26bcElem* elems = p->elems;
  s32 i;

  if (p->usedMask == 0) {
    return 0;
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
    return 0;
  }
  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return 0;
  }
  Entity081f26bc_ScheduleHitboxes(p);
  for (i = 0; i < 24; i++) {
    if (Entity081f26bc_IsUsed(p, i)) {
      sEntity081f26bcStates[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

// 使用中の破片の obj を外して解放する
s32 Entity081f26bc_Destroy(Entity081f26bc* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    if (Entity081f26bc_IsUsed(p, i)) {
      Entity081f26bcElem* e = &p->elems[i];

      if (e->flags & 8) {
        AuxSprite* spr = e->obj;

        if (spr->active) {
          AuxSprite_Remove(spr);
          Free(e->obj);
        }
      } else {
        Particle* ptcl = e->obj;

        if (ptcl->active) {
          Particle_Remove(ptcl);
          Free(e->obj);
        }
      }
    }
  }
  gEntity081f26bc = NULL;
  return 0;
}

s32 Entity081f26bc_Init(Entity081f26bc* p) {
  p->usedMask = 0;
  gEntity081f26bc = p;
  return 0;
}

Entity081f26bc* Entity081f26bc_Create(void) {
  if (gEntity081f26bc == NULL) {
    Entity081f26bc* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081f26bc));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081f26bc_Update, Entity081f26bc_Destroy);
      if (Entity081f26bc_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081f26bc;
}

void Entity081f26bc_ClearGlobal(void) { gEntity081f26bc = NULL; }
