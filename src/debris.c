#include "debris.h"
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

// DEBRIS_SPRITE のとき obj が指すスプライト
typedef struct {
  AuxSprite sprite;  // 0x00
  AuxSpriteGfx gfx;  // 0x2C
} DebrisSprite;
static_assert(sizeof(DebrisSprite) == 72);

// DEBRIS_PTCL のとき obj が指す粒子
typedef struct {
  Particle ptcl;         // 0x00
  ParticleGroup* group;  // 0x28
} DebrisPtcl;
static_assert(sizeof(DebrisPtcl) == 44);

// 動く破片 1 つ, Debris_Spawn で出す
typedef struct Debris {
  void* obj;           // 0x00, DEBRIS_SPRITE なら DebrisSprite, DEBRIS_PTCL なら DebrisPtcl を Malloc したもの
  AuxAnimState anim;   // 0x04
  Vec3 vel;            // 0x14
  Hitbox hitbox;       // 0x1C, DEBRIS_HAS_HITBOX と DEBRIS_HITBOX_ON が立っているときだけ登録する
  DebrisFlags flags;   // 0x6C, see DebrisFlags
  u8 state;            // 0x6E, sDebrisStates の添字, 0: 空き, 3: 点滅して消える
  s8 idx;              // 0x6F, elems の添字, 空きなら -1
  u16 life;            // 0x70
  u16 unk_72;          // 0x72
  u16 vanishTimer;     // 0x74, 点滅して消える状態の経過フレーム
  bool8 stateEntered;  // 0x76
  u8 hitboxWait;       // 0x77, 攻撃判定を次に有効にするまでのフレーム数, 有効にすると 3 から数え直す
} Debris;
static_assert(sizeof(Debris) == 120);

// 破片を 24 個まで動かす
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  u32 usedMask;                  // 0x018, bit i が立っていれば elems[i] が使用中
  Debris elems[24];  // 0x01C
} DebrisManager;
static_assert(sizeof(DebrisManager) == 2908);

static DebrisManager* gDebrisManager;  // 0x030001EC

static inline bool8 DebrisManager_IsUsed(DebrisManager* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

void Debris_StateNone(DebrisManager* p, Debris* e);
void Debris_StateFly(DebrisManager* p, Debris* e);
void Debris_StateBounce(DebrisManager* p, Debris* e);
void Debris_StateVanish(DebrisManager* p, Debris* e);
void Debris_OnHit(void);
s32 DebrisManager_Update(DebrisManager* p);
s32 DebrisManager_Destroy(DebrisManager* p);
s32 DebrisManager_Init(DebrisManager* p);
DebrisManager* DebrisManager_Create(void);

void (*const sDebrisStates[4])(DebrisManager*, Debris*) = {
    Debris_StateNone,
    Debris_StateFly,
    Debris_StateBounce,
    Debris_StateVanish,
};  // 0x085AE538

// 攻撃判定を持つ破片の判定を, 1 フレームに 6 個まで, それぞれ 3 フレームおきに有効にする
void DebrisManager_ScheduleHitboxes(DebrisManager* p) {
  Debris* elems = p->elems;
  s32 count = 0;
  s32 i;

  for (i = 0; i < 24; i++) {
    if (DebrisManager_IsUsed(p, i) && (elems->flags & DEBRIS_HAS_HITBOX)) {
      if (elems[i].hitboxWait != 0) {
        elems[i].hitboxWait--;
      } else if (count < 6) {
        elems[i].hitboxWait = 3;
        elems[i].flags |= DEBRIS_HITBOX_ON;
        count++;
      }
    }
  }
}

// 攻撃判定が有効なら pos へ動かして登録する
void Debris_UpdateHitbox(Debris* e, Vec3* pos) {
  if (!(e->flags & DEBRIS_HAS_HITBOX)) {
    return;
  }
  if (e->flags & DEBRIS_HITBOX_ON) {
    if (pos != NULL) {
      Hitbox_SetPos(&e->hitbox, pos, 0);
    }
    Hitbox_Register(&e->hitbox);
  }
}

void Debris_OnHit(void) {}

// 破片の攻撃判定を作る
void Debris_InitHitbox(Debris* e, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes) {
  Vec3 size;
  Vec3 offset;
  Hitbox* hitbox;

  VEC3_SET(size, Q8(0.0625), Q8(0.125), Q8(0.0625));
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &e->hitbox;
  Hitbox_Init(hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, iframes);
  Hitbox_SetHandler(hitbox, Debris_OnHit, e);
  if (e->flags & DEBRIS_SPRITE) {
    Hitbox_SetPos(hitbox, &((AuxSprite*)e->obj)->pos, 0);
  } else {
    Hitbox_SetPos(hitbox, &((Particle*)e->obj)->pos, 0);
  }
}

void Debris_StateNone(DebrisManager* p, Debris* e) {}

// 空いている破片を1つ確保して 0 で埋める
Debris* DebrisManager_AllocDebris(DebrisManager* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    if (!DebrisManager_IsUsed(p, i)) {
      Debris* e = &p->elems[i];

      p->usedMask |= 1 << i;
      ClearMemory(e, sizeof(Debris));
      e->idx = i;
      return e;
    }
  }
  return NULL;
}

// Debris_StateVanish と同じ壁, 原典は anim を ip に追い出して使うたび低位レジスタへ移す (380/396)
NON_MATCH void Debris_StateFly(DebrisManager* p, Debris* e) {
#ifdef NONMATCHING_C
  bool32 finished;
  Vec3* pos;

  if (e->stateEntered) {
    if (e->flags & DEBRIS_SPRITE) {
      AuxSprite_Show(e->obj);
    } else {
      Particle_Show(e->obj);
    }
    e->vanishTimer = 0;
    e->stateEntered = FALSE;
  }
  Debris_UpdateHitbox(e, NULL);
  if (e->flags & DEBRIS_SPRITE) {
    finished = AuxSprite_AdvanceAnim(e->obj, &e->anim);
    pos = &((AuxSprite*)e->obj)->pos;
  } else {
    DebrisPtcl* ptcl = e->obj;

    finished = Particle_AdvanceAnim(&ptcl->ptcl, ptcl->group, &e->anim);
    pos = &((Particle*)e->obj)->pos;
  }
  if (e->flags & DEBRIS_MOVING) {
    Vec3_Add(pos, &e->vel);
  }
  e->vanishTimer++;
  if (finished && e->life == 0) {
    if (e->flags & DEBRIS_FREE_ON_END) {
      CLEAR_BIT(gDebrisManager->usedMask, e->idx);
      e->state = 0;
      if (e->flags & DEBRIS_SPRITE) {
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
  INCFUNC("asm/func/Debris_StateFly.inc");
#endif
}

// 残差はレジスタ割当, 原典は vel と pos のアドレスを別の順で作り pos.y を ptcl 経由で読み書きする, vel / pos のローカル化は試済
NON_MATCH void Debris_StateBounce(DebrisManager* p, Debris* e) {
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
  if (e->flags & DEBRIS_MOVING) {
    s32 groundY;

    Vec3_Add(pos, &e->vel);
    groundY = (TileAtIndex(GetCollisionTileIdx(pos))->heightStairs & 0xF) << 8;
    if (pos->y <= groundY) {
      pos->y = groundY;
      e->vel.x = Div(e->vel.x * 5, 10);
      e->vel.y = Div(abs(e->vel.y) * 2, 10);
      e->vel.z = Div(e->vel.z * 5, 10);
      if (e->vel.x * e->vel.x + e->vel.y * e->vel.y + e->vel.z * e->vel.z == 0) {
        e->flags &= ~DEBRIS_MOVING;
      }
    } else if (Mod(e->vanishTimer, 4) != 0) {
      e->vel.y -= 2;
    }
  }
  Debris_UpdateHitbox(e, pos);
  finished = Particle_AdvanceAnim(ptcl, ((DebrisPtcl*)e->obj)->group, &e->anim);
  if (e->life != 0) {
    if (e->anim.cmdIdx == 5 && e->anim.tick == e->anim.wait - 1) {
      e->anim.cmdIdx = 0;
      e->anim.tick = 0;
    }
    e->life--;
  }
  e->vanishTimer++;
  if (finished) {
    if (e->flags & DEBRIS_FREE_ON_END) {
      CLEAR_BIT(gDebrisManager->usedMask, e->idx);
      e->state = 0;
      if (e->flags & DEBRIS_SPRITE) {
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
  INCFUNC("asm/func/Debris_StateBounce.inc");
#endif
}

// 点滅して消える状態, アニメを進めながら点滅させ, 消えきったら obj を解放して枠を空ける
// 残差はレジスタ割当 (292/321), 原典は anim を ip に追い出して使うたび低位レジスタへ移すが, こちらは r4 に収まり &e->flags が r8 に回る
// 手動送りは AuxSprite_AdvanceAnim / Particle_AdvanceAnim で原典と同形, anim のローカル化 (関数頭 / 分岐内), 送り全体の inline 化は試済
NON_MATCH void Debris_StateVanish(DebrisManager* p, Debris* e) {
#ifdef NONMATCHING_C
  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->vanishTimer = 0;
  }
  if (e->flags & DEBRIS_SPRITE) {
    AuxSprite_AdvanceAnim(e->obj, &e->anim);
  } else {
    DebrisPtcl* ptcl = e->obj;

    Particle_AdvanceAnim(&ptcl->ptcl, ptcl->group, &e->anim);
  }
  if (Sprite_UpdateVanishBlink(e->flags & 8 ? &((AuxSprite*)e->obj)->flags : &((Particle*)e->obj)->flags, e->vanishTimer, 60, 40)) {
    CLEAR_BIT(gDebrisManager->usedMask, e->idx);
    e->state = 0;
    if (e->flags & DEBRIS_SPRITE) {
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
  INCFUNC("asm/func/Debris_StateVanish.inc");
#endif
}

// obj のスプライトを読み込み, アニメファイルを返す
AuxAnimFile* Debris_LoadAuxSprite(Debris* e, SpriteID32 spriteID, u32 animFileID) {
  Video_GetAuxSprite(&((DebrisSprite*)e->obj)->gfx, spriteID);
  return GetFile(DIR_ANIMATION, animFileID);
}

// 破片を1つ出す, flags の bit3 ならスプライト, bit4 なら粒子として作る
Debris* Debris_Spawn(Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 ofsX, s32 ofsY) {
  DebrisManager* p = gDebrisManager;
  Debris* e;
  AuxAnimFile* animFile;

  if (p == NULL) {
    p = DebrisManager_Create();
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
  e = DebrisManager_AllocDebris(p);
  if (e == NULL) {
    return NULL;
  }
  e->flags = flags;
  e->stateEntered = TRUE;
  e->state = 1;
  e->vel = *vel;
  if (vel->x * vel->x + vel->y * vel->y + vel->z * vel->z != 0) {
    e->flags |= DEBRIS_MOVING;
  }
  e->life = life;
  if (e->flags & DEBRIS_SPRITE) {
    AuxSprite* sprite;

    e->obj = Malloc(sizeof(DebrisSprite));
    ClearMemory(e->obj, sizeof(DebrisSprite));
    sprite = e->obj;
    sprite->pos = *pos;
    animFile = Debris_LoadAuxSprite(e, sprID, animFID);
    AuxSprite_Add(sprite, &((DebrisSprite*)e->obj)->gfx, 0);
    AuxAnim_SetAnim(&e->anim, animFile, animIdx, animVariant, animFlags);
    Video_SetAuxSpritePltt(sprite->gfx, plttID);
    AuxSprite_AdvanceAnim(sprite, &e->anim);
    AuxSprite_Hide(sprite);
    sprite->flags |= sprFlags;
    sprite->priority = prio;
  } else if (e->flags & DEBRIS_PTCL) {
    Particle* ptcl;
    DebrisPtcl* obj;

    e->obj = Malloc(sizeof(DebrisPtcl));
    ClearMemory(e->obj, sizeof(DebrisPtcl));
    ptcl = e->obj;
    ptcl->pos = *pos;
    obj = e->obj;
    obj->group = GetParticleGroup(sprID);
    animFile = GetFile(DIR_ANIMATION, animFID);
    Particle_Add(ptcl, ((DebrisPtcl*)e->obj)->group, 0);
    Particle_SetOffset(ptcl, -ofsX, -ofsY);
    AuxAnim_SetAnim(&e->anim, animFile, animIdx, animVariant, animFlags);
    Particle_Hide(ptcl);
    ptcl->flags |= sprFlags;
    ptcl->priority = prio;
    if (e->flags & DEBRIS_BOUNCE) {
      e->state = 2;
    }
  }
  if (power > 0) {
    Debris_InitHitbox(e, power, knockback, attrs, iframes);
    e->flags |= DEBRIS_HAS_HITBOX;
  }
  return e;
}

// 使用中の破片を state ごとに動かす
s32 DebrisManager_Update(DebrisManager* p) {
  Debris* elems = p->elems;
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
  DebrisManager_ScheduleHitboxes(p);
  for (i = 0; i < 24; i++) {
    if (DebrisManager_IsUsed(p, i)) {
      sDebrisStates[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

// 使用中の破片の obj を外して解放する
s32 DebrisManager_Destroy(DebrisManager* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    if (DebrisManager_IsUsed(p, i)) {
      Debris* e = &p->elems[i];

      if (e->flags & DEBRIS_SPRITE) {
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
  gDebrisManager = NULL;
  return 0;
}

s32 DebrisManager_Init(DebrisManager* p) {
  p->usedMask = 0;
  gDebrisManager = p;
  return 0;
}

DebrisManager* DebrisManager_Create(void) {
  if (gDebrisManager == NULL) {
    DebrisManager* p = CreateEntity(ENTITY_UNK_10, sizeof(DebrisManager));

    if (p != NULL) {
      SetEntityRoutine(p, DebrisManager_Update, DebrisManager_Destroy);
      if (DebrisManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gDebrisManager;
}

void DebrisManager_ClearGlobal(void) { gDebrisManager = NULL; }
