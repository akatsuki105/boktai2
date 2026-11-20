#include "cwolf_target.h"
#include "debris.h"
#include "eff_elemcond.h"
#include "emote.h"
#include "enemy.h"
#include "enemy/dog.h"
#include "enemy_inline.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "inventory.h"
#include "link_session.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

typedef Dog DogLink;  // ドッグ(dog.c) の通信対戦用版

bool8 FUN_080f9f20(Enemy* p);
void FUN_080fa77c(Enemy* p);

void DogLink_StateFireBreath(DogLink* p, s32 timer);
struct Entity081ee2a0Elem* Entity081ee2a0_SpawnEx(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind, u32 priority);
struct Entity081f1770Elem* Entity081f1770_Spawn(Vec3* pos, u32 angle, SpriteFlags flags);
s32 FUN_081cb3a4(DogLink* p);
void FUN_081c6048(DogLink* p);
bool8 FUN_081c70c8(DogLink* p);
void FUN_081c7228(DogLink* p);
void FUN_081c9ed8(DogLink* p);
void FUN_081ca14c(DogLink* p);
s32 ItemIconPopupManager_AddIcon(ItemCategory32 category, item32_t itemID, u32 kind, u32 playerIdx, Vec3* pos, Vec3* destPos, u32 duration, u32 key);
bool8 PickItemToSteal(s16* outSlot, s16* outItem, s16* outRot);

void DogLink_OnHit(Hitbox* a, Hitbox* b, DogLink* p);
void DogLink_OnHurt(Hitbox* a, Hitbox* b, DogLink* p);
void DogLink_OnStealHit(Hitbox* a, Hitbox* b, DogLink* p);

void DogLink_StateWakeUp(DogLink* p, s32 timer);

void DogLink_StatePounce(DogLink* p);

void FUN_081ca614(DogLink* p, s32 timer);

const STRING_DATA char s_eneinline_082522bc[] = "../dog/../system/eneinline.h";
const STRING_DATA char s_dogcom_c_082522dc[] = "../dog/dogcom.c";
const STRING_DATA char s_eneinline_082522ec[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252308[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252324[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252340[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_0825235c[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252378[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_08252394[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082523b0[] = "../enemy/system/eneinline.h";
const STRING_DATA char s_eneinline_082523cc[] = "../enemy/system/eneinline.h";

static inline bool8 Dog_TestUnk6a8(Dog* p, u32 bit) {
  if (p->unk_6a8 & bit) return TRUE;
  return FALSE;
}

static inline void Dog_ClearUnk6a8(Dog* p, u32 bit) { p->unk_6a8 &= ~bit; }
static inline void Dog_SetUnk6a8(Dog* p, u32 bit) { p->unk_6a8 |= bit; }

static inline AuxAnimState* Enemy_GetAuxAnim(Enemy* p) { return &p->s->aux.anim; }

// anim 番の variant を流す, MainSprite では anim + variant 番を flip の向きで流し, 同じものが流れていれば何もしない
static inline void Dog_PlayTurnAnim(Dog* p, u32 anim, u32 variant, u32 flip) {
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = anim;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flip);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 mode;

    anim += variant;
    if ((p->e).playingAnim == anim && !(p->e).animForceRestart && ((flip == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flip == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    (p->e).playingAnim = anim;
    mode = (flip & ANIM_PLAY_REVERSE) ? MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE : MAIN_ANIM_FORCE_POSE;
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, mode);
    if (flip & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = FALSE;
}

const u16 u16_ARRAY_085ae018[2][8] = {
    {450, 480,  480, 540, 450, 459, 459, 540},
    {800, 1280, 560, 360, 300, 306, 306, 360}
};  // 0x085AE018

void FUN_081ca7f4(DogLink*);
void FUN_081ca8cc(DogLink*);

void (*const PTR_ARRAY_085ae038[2])(DogLink*) = {
    FUN_081ca7f4,
    FUN_081ca8cc,
};  // 0x085AE038

void FUN_081cb148(DogLink*);
void FUN_081cb274(DogLink*);

void (*const PTR_ARRAY_085ae040[2])(DogLink*) = {
    FUN_081cb148,
    FUN_081cb274,
};  // 0x085AE040

void FUN_081cbaa8(DogLink*);
void FUN_081cb400(DogLink*);
void FUN_081cb7e8(DogLink*);
void FUN_081cc1a4(DogLink*);
void FUN_081cc380(DogLink*);
void FUN_081cc444(DogLink*);

// clang-format off
void (*const PTR_ARRAY_085ae048[20])(DogLink*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f9c20,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f9e34,
    (void*)FUN_080f9ee0,
    (void*)FUN_080f0e78,
    (void*)FUN_080f11d0,
    FUN_081cbaa8,
    FUN_081cb400,
    FUN_081cb7e8,
    FUN_081cc1a4,
    FUN_081cc380,
    FUN_081cc444,
};  // 0x085AE048
// clang-format on

// dog.c の enemy_dog_08149f6c の通信対戦版
// 134/133 命令, dog.c の enemy_dog_08149f6c の C をそのまま当てただけ, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH void FUN_081c5c94(DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;

  q->unk_6c0 = q->unk_6c2;
  if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    Dog_ClearUnk6a8(q, 4 | 8);
    Enemy_ResetState(&p->e, 0, 1, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  } else {
    Enemy_BeginChase(&p->e);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8) || !FUN_081c70c8(p)) {
      if (!Dog_TestUnk6a8(q, 8)) {
        FUN_081c7228(p);
      }
      return;
    }
    FUN_081c6048(p);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
#else
  INCFUNC("asm/func/FUN_081c5c94.inc");
#endif
}

// dog.c の FUN_0814a098 と同じ
// 269/277 命令, dog.c の FUN_0814a098 の C をそのまま当てただけ, 残差は FUN_0814a098 と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081c5dc0(DogLink* p) {
#ifdef NONMATCHING_C
  WorldPos* dst;

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    (p->e).animSpeedDiv = 2;
    (p->e).pendingDelay = 20;
    (p->e).pendingHandler = (p->e).handlerChase;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 12;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      (p->e).chaseTimer += 300;
      if ((p->e).chaseTimer > (p->e).chaseTimeMax) {
        (p->e).chaseTimer = (p->e).chaseTimeMax;
      }
    }
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).animSpeedDiv = 2;
    (p->e).pendingDelay = 60;
    (p->e).pendingHandler = (p->e).handlerMove;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
  }
  dst = (p->e).pathNodePos;
  dst->x = (p->e).pathWalker.node->x;
  dst->z = (p->e).pathWalker.node->y;
  dst->y = TileHeightAt(dst);
  (p->e).pathNodePos->val = 0;
  if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
    (p->e).onRouteFailed(&p->e);
  }
#else
  INCFUNC("asm/func/FUN_081c5dc0.inc");
#endif
}

// dog.c の enemy_dog_0814a320 の通信対戦版
// 300/301 命令, dog.c の enemy_dog_0814a320 の C をそのまま当てただけ, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH void FUN_081c6048(DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  if ((p->e).playerDistSq < (p->e).unk_1e8) {
    Vec3 diff;
    s32 d;
    s32 ad;

    Vec3_Delta(&diff, &(p->e).mover.pos, &(p->e).playerMover->pos);
    d = ArcTan2_8(diff.x, diff.z) - (p->e).mover.angle;
    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    ad = abs(d);
    if (ad <= 23) {
      if ((p->e).variant <= 1 || (p->e).variant == 4) {
        if ((p->e).playerDistSq < q->unk_6ac && q->unk_6c8 == 0) {
          Enemy_ResetState(&p->e, 0, 2, 0);
          Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
          Enemy_ClearPendingState(&p->e, s_dogcom_c_082522dc, 111);
          return;
        }
      } else {
        if ((p->e).playerDistSq < q->unk_6ac && q->unk_6c8 == 0) {
          Enemy_ResetState(&p->e, 0, 2, 0);
          Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
          Enemy_ClearPendingState(&p->e, s_dogcom_c_082522dc, 124);
          return;
        }
        if ((p->e).playerDistSq < q->unk_6b0 && ad <= 5 && q->unk_6ca == 0) {
          Enemy_ResetState(&p->e, 0, 2, 1);
          Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
          Enemy_ClearPendingState(&p->e, s_dogcom_c_082522dc, 129);
          return;
        }
      }
      if (!Dog_TestUnk6a8(q, 8)) {
        FUN_081c7228(p);
      }
    } else if (!Dog_TestUnk6a8(q, 8)) {
      FUN_081c7228(p);
    }
  } else if (!Dog_TestUnk6a8(q, 8)) {
    FUN_081c7228(p);
  }
#else
  INCFUNC("asm/func/FUN_081c6048.inc");
#endif
}

// dog.c の Dog_TryTurnToward と同じ
bool8 DogLink_TryTurnToward(DogLink* p, u32 angle) {
  s32 diff = angle - (p->e).mover.angle;

  if (diff > 128) {
    diff -= 256;
  } else if (diff < -128) {
    diff += 256;
  }
  if (abs(diff) < (p->e).unk_1fd || (p->e).state == ES_UNK_2) {
    return FALSE;
  }
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    Enemy_ResetState(&p->e, 0, 0, 13);
  } else {
    Enemy_ResetState(&p->e, 0, 0, 6);
  }
  (p->e).unk_1dc = Angle_ToDir8(angle);
  return TRUE;
}

// dog.c の Dog_InitAnims と同じ
void DogLink_InitAnims(DogLink* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 14, 1, 0);
  Enemy_SetAnimEntry(&p->e, 11, 2, 0);
  Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  Enemy_SetAnimEntry(&p->e, 2, 13, 0);
  Enemy_SetAnimEntry(&p->e, 15, 5, 0);
  Enemy_SetAnimEntry(&p->e, 5, 6, 0);
  Enemy_SetAnimEntry(&p->e, 16, 7, 0);
  Enemy_SetAnimEntry(&p->e, 17, 8, 0);
  Enemy_SetAnimEntry(&p->e, 3, 9, 0);
  Enemy_SetAnimEntry(&p->e, 6, 10, 0);
  Enemy_SetAnimEntry(&p->e, 7, 11, 0);
  Enemy_SetAnimEntry(&p->e, 10, 12, 0);
}

// dog.c の Dog_OnReset と同じ
// 146/147 命令, dog.c の Dog_OnReset の C をそのまま当てただけ, 残差は Dog_OnReset と同じ形 (1回で打ち切り)
NON_MATCH void DogLink_OnReset(DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;
  EnemyAuxSprite* aux;

  q->unk_6a8 = 0;
  q->unk_6c0 = 0;
  q->unk_6d0 = -1;
  q->unk_6d4 = 0;
  q->unk_6d6 = 0;
  q->unk_6d7 = 0;
  ClearMemory(&q->unk_708, sizeof(Vec3));
  Enemy_StepTowardPathNode(&p->e);
  Enemy_PlayAnim(&p->e, 0);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
#else
  INCFUNC("asm/func/DogLink_OnReset.inc");
#endif
}

// dog.c の FUN_0814a8c8 と同じ
void FUN_081c65f0(DogLink* p) { CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1); }

// dog.c の FUN_0814a8dc と同じ
// 221/221 命令, dog.c の FUN_0814a8dc の C をそのまま当てただけ, 残差は FUN_0814a8dc と同じ形 (1回で打ち切り)
NON_MATCH s32 FUN_081c6604(DogLink* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (anim->tick == 0) {
    bool32 run = Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_7);

    Enemy_SetFlag2(&p->e, ENEFLAG2_UNK_16);
    if ((p->e).variant == 2 && (anim->cmdIdx == 7 || anim->cmdIdx == 5 || anim->cmdIdx == 1)) {
      Vec3 pos;
      Vec3 off;
      Vec3 vel;
      s32 life;

      pos.x = (RandomNext() & 63) - 48;
      pos.z = (RandomNext() & 63) - 48;
      Vec3_Sum(&pos, &(p->e).mover.pos, &pos);
      Vec3_SetPolar(&off, ((p->e).mover.angle + 128) & 0xFF, 80);
      Vec3_Sum(&pos, &off, &pos);
      pos.y = (p->e).mover.pos.y;
      Vec3_Clear(&vel);
      life = (Random() & 63) + 20;
      Debris_Spawn(&pos, &vel, PTCL_GROUP_0, ANIM_D1B8, 3, 0, DEBRIS_FREE_ON_END | DEBRIS_PTCL | DEBRIS_BOUNCE, 0, 1, 0, 0, life, 4, 1, 0x00200004, 30, 8, 8);
    }
    return u16_ARRAY_085ae018[run][anim->cmdIdx & 7];
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081c6604.inc");
#endif
}

// dog.c の FUN_0814aad4 と同じ
void FUN_081c67fc(DogLink* p) {
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_9)) {
    Enemy_SetAnimEntry(&p->e, 1, 4, 0);
  } else {
    Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_9)) {
    (p->e).animSpeedDiv = 2;
  }
}

// dog.c の Dog_InitHitboxes と同じ
void DogLink_InitHitboxes(DogLink* p) {
  DogLink* self = (p->e).owner;
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset, hit2Size, hit2Offset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, DogLink_OnHurt, p);
  VEC3_SET(hitSize, 64, 120, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, DogLink_OnHit, 0, p);
  VEC3_SET(hit2Size, 0, 120, 0);
  VEC3_SET(hit2Offset, 0, 128, 0);
  Enemy_InitHitboxWithAtk(&p->e, &self->unk_658, &hit2Size, &hit2Offset, DogLink_OnStealHit, 1, p);
  Hitbox_SetFlags(&self->unk_658, HBF_ANGLE);
}

// dog.c の Dog_UpdateHitboxes と同じ
void DogLink_UpdateHitboxes(DogLink* p) {
  DogLink* q = (p->e).owner;
  WorldPos pos;
  Vec3 big;
  Vec3 size;
  s32 angle;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  pos = (p->e).mover.pos;
  angle = FixToInt(6, ((p->e).mover.angle + 0x20) & 0xFF) << 6;
  if (Dog_TestUnk6a8(q, 2)) {
    pos.x += POLAR_X(512, angle);
    pos.z += POLAR_Z(512, angle);
  } else {
    pos.x += POLAR_X(128, angle);
    pos.z += POLAR_Z(128, angle);
  }
  Hitbox_SetPos(&q->unk_658, &pos, 0);
  q->unk_658.angle = angle;
  pos = (p->e).mover.pos;
  switch (FixToInt(6, angle)) {
    case 0:
    case 2: {
      if (Dog_TestUnk6a8(q, 2)) {
        big.x = 240;
        big.z = 128;
      }
      size.x = 120;
      size.z = 64;
      break;
    }
    case 1:
    case 3: {
      if (Dog_TestUnk6a8(q, 2)) {
        big.x = 128;
        big.z = 240;
      }
      size.x = 64;
      size.z = 120;
      break;
    }
  }
  size.y = 100;
  Hitbox_SetHalfSize(&(p->e).hitbox, &size);
  Hitbox_SetPos(&(p->e).hitbox, &pos, 0);
  Hitbox_SetHalfSize(&(p->e).hurtbox, &size);
  Hitbox_SetPos(&(p->e).hurtbox, &pos, 0);
  if (Dog_TestUnk6a8(q, 2)) {
    Hitbox_SetHalfSize(&q->unk_658, &big);
  } else {
    Hitbox_SetHalfSize(&q->unk_658, &size);
  }
}

// dog.c の FUN_0814ae80 と同じ
void FUN_081c6ba8(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (q->unk_6c8 != 0) {
    q->unk_6c8--;
  }
  if (q->unk_6ca != 0) {
    q->unk_6ca--;
  }
}

// dog.c の FUN_0814aeb0 と同じ
void FUN_081c6bd8(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (q->unk_6c6 != 0) {
    q->unk_6c6--;
  }
}

// dog.c の FUN_0814aed0 と同じ
void FUN_081c6bf8(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP | ENEFLAG3_STUN | ENEFLAG3_PETRIFIED | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_14 | ENEFLAG3_UNK_15) &&
      !TEST_FLAGS((p->e).flags, ENEFLAG_UNK_4) && (p->e).state < 2) {
    if (q->unk_6c0 != 0) {
      q->unk_6c0--;
    } else {
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
        q->unk_6c0 = q->unk_6c4;
      } else {
        q->unk_6c0 = q->unk_6c2;
      }
      SET_FLAGS(q->unk_6a8, 1);
      if (Dog_TestUnk6a8((p->e).owner, 1)) {
        Enemy_ResetState(&p->e, 0, 0, 15);
        Dog_ClearUnk6a8((p->e).owner, 1);
      }
    }
  }
}

// dog.c の Dog_RunDefeatScript と同じ
void DogLink_RunDefeatScript(DogLink* p) {
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_19)) {
    DogLink* q = (p->e).owner;

    if ((p->e).unk_198 != 0) {
      u32 argv[10];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      if (q->unk_6d0 < 0) {
        argv[6] = -1;
        argv[7] = -1;
      } else {
        argv[6] = q->unk_6d2;
        argv[7] = q->unk_6d4;
      }
      argv[8] = (p->e).kind;
      argv[9] = (p->e).variant;
      sa.argc = 10;
      sa.argv = argv;
      VM_ExecByID((p->e).unk_198, &sa);
    }
  }
}

// dog.c の Dog_PickWalkDest と同じ
// 331/344 命令, dog.c の Dog_PickWalkDest の C をそのまま当てただけ, 残差は Dog_PickWalkDest と同じ形 (1回で打ち切り)
NON_MATCH bool8 DogLink_PickWalkDest(DogLink* p, u32 angle) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;
  u32 target;
  s32 i;
  WorldPos pos;

  for (i = 0; i < 4; i++) {
    u32 tileIdx = (p->e).tileIdx;
    s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
    s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
    s32 idx;
    s32 n;

    switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
      case 0: {
        idx = tileIdx + 1;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx++;
        }
        target = idx - 1;
        break;
      }
      case 1: {
        idx = tileIdx + gCollisionMap->tiledata->width;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx += gCollisionMap->tiledata->width;
        }
        target = idx - gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        idx = tileIdx - 1;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx--;
        }
        target = idx + 1;
        break;
      }
      case 3: {
        idx = tileIdx - gCollisionMap->tiledata->width;
        for (n = 0; n < 1; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx -= gCollisionMap->tiledata->width;
        }
        target = idx + gCollisionMap->tiledata->width;
        break;
      }
      default: {
        target = (p->e).tileIdx;
        break;
      }
    }
    if (target != (p->e).tileIdx) {
      break;
    }
    if (q->unk_6d6) {
      (p->e).mover.angle += 64;
    } else {
      (p->e).mover.angle -= 64;
    }
  }
  q->unk_6d6 = (u8)Random() < 128;
  (p->e).mover.angle = angle;
  TilePosAtIndex(&pos, target);
  if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &pos)) {
    q->unk_6d7++;
    return TRUE;
  }
  (p->e).onRouteFailed(&p->e);
  return FALSE;
#else
  INCFUNC("asm/func/DogLink_PickWalkDest.inc");
#endif
}

// dog.c の FUN_0814b3a0 と同じ
// 32/32 命令, dog.c の FUN_0814b3a0 の C をそのまま当てただけ, 残差は FUN_0814b3a0 と同じ形 (1回で打ち切り)
NON_MATCH bool8 FUN_081c70c8(DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;

  if ((p->e).variant <= 1 || (p->e).variant == 4) {
    if (q->unk_6c8 == 0) {
      return TRUE;
    }
  } else {
    if (q->unk_6c8 == 0) {
      return TRUE;
    }
    if (q->unk_6ca == 0) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_081c70c8.inc");
#endif
}

// dog.c の Dog_NoticeAttacker と同じ
bool8 DogLink_NoticeAttacker(DogLink* p) {
  if ((p->e).hitTargetID > 0) {
    Vec3 diff;

    Enemy_Alert(&p->e);
    CLEAR_FLAGS((p->e).unk_222, ENEMY222_UNK_1);
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
    (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
    (p->e).unk_25e = GetCollisionTileIdx(&(p->e).playerMover->pos);
    Vec3_Delta(&diff, &(p->e).mover.pos, &(p->e).playerMover->pos);
    (p->e).mover.angle = ArcTan2_8(diff.x, diff.z);
    Dog_ClearUnk6a8((p->e).owner, 4 | 8);
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  }
  return FALSE;
}

// dog.c の enemy_dog_0814b500 と同じ
// 273/274 命令, dog.c の enemy_dog_0814b500 の C をそのまま当てただけ, 残差は enemy_dog_0814b500 と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081c7228(DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;

  Enemy_ClearPendingState(&p->e, s_dogcom_c_082522dc, 656);
  if (q->unk_6d7 <= 3) {
    if (((p->e).playerDistSq < q->unk_6b8 || !FUN_081c70c8(p)) && q->unk_6d7 <= 3) {
      u8 angle = (p->e).mover.angle;

      (p->e).mover.angle = (p->e).playerAngle + 128;
      if (DogLink_PickWalkDest(p, angle)) {
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_ResetState(&p->e, 0, 0, 17);
      }
      return;
    }
    if ((p->e).playerDistSq > q->unk_6bc) {
      if ((p->e).state == ES_UNK_26) {
        return;
      }
      if ((*(u32*)&(p->e).subState0 & 0xFFFFFF) == ENEMY_SUBSTATE(0, 0, 12)) {
        return;
      }
      if (IsLinkPlay()) {
        if (!Enemy_TargetNearestLinkPlayer(&p->e)) {
          return;
        }
      } else {
        (p->e).playerMover = &gPlayerPtr[0]->mover;
      }
      if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
        (p->e).onRouteFailed(&p->e);
        return;
      }
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      return;
    }
  }
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, FUN_081ca14c, ES_UNK_42);
#else
  INCFUNC("asm/func/FUN_081c7228.inc");
#endif
}

// dog.c の FUN_0814b78c と同じ
void FUN_081c74b4(DogLink* p) {
  if (p->unk_6d8 != 0) {
    p->unk_6d8--;
  }
}

// dog.c の Dog_SpawnSpark と同じ
// 79/78 命令, dog.c の Dog_SpawnSpark の C をそのまま当てただけ, 残差は Dog_SpawnSpark と同じ形 (1回で打ち切り)
NON_MATCH void DogLink_SpawnSpark(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 angle;
  s32 speed;

  angle = RandomNext() & 0xFF;
  speed = RandomNext() & 31;
  Vec3_SetPolar(&vel, angle, speed);
  vel.y = (Random() & 63) - 48;
  Entity081ee2a0_SpawnEx(pos, &vel, 60, 3, 3);
#else
  INCFUNC("asm/func/DogLink_SpawnSpark.inc");
#endif
}

// dog.c の Dog_OnHit と同じ
void DogLink_OnHit(Hitbox* a, Hitbox* b, DogLink* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// dog.c の Dog_OnStealHit と同じ
// 304/359 命令, dog.c の Dog_OnStealHit の C をそのまま当てただけ, 残差は Dog_OnStealHit と同じ形 (1回で打ち切り)
NON_MATCH void DogLink_OnStealHit(Hitbox* a, Hitbox* b, DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e)) {
    s16 x = a->center.x;
    s16 z = a->center.z;

    switch ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) {
      case 0: {
        x -= 256;
        break;
      }
      case 1: {
        z -= 256;
        break;
      }
      case 2: {
        x += 256;
        break;
      }
      case 3: {
        z += 256;
        break;
      }
    }
    a->angle = ArcTan2_8(b->center.x - x, b->center.z - z);
    Enemy_SetHitTarget(&p->e, b);
    if (!IsLinkPlay() && b->ignoreMask == HIM_0 && q->unk_6d0 < 0 && ((p->e).variant == 0 || (p->e).variant == 4)) {
      WorldPos pos = gPlayerPtr[0]->mover.pos;

      pos.y += 200;
      if (PickItemToSteal(&q->unk_6d0, &q->unk_6d2, &q->unk_6d4)) {
        if (ItemIconPopupManager_AddIcon(0, q->unk_6d2, 3, 0, &pos, &(p->e).mover.pos, 24, (u32)p) < 0) {
          q->unk_6d0 = -1;
        } else {
          RemoveItem(q->unk_6d0);
          switch (q->unk_6d2) {
            case 8:
            case 11:
            case 14:
            case 17: {
              s32 heal = Div((p->e).maxHp * q->unk_6d9, 100);

              if ((p->e).hp - heal <= 0) {
                heal = (u16)(p->e).hp;
              }
              (p->e).unk_48a = heal;
              q->unk_6d0 = -1;
              (p->e).playerMover = &gPlayerPtr[0]->mover;
              (p->e).unk_4a0 = 1;
              (p->e).weaponExpMask = 0;
              (p->e).flags6 = 0;
              (p->e).weaponExpMask = 0;
              (p->e).flags6 = 0;
              (p->e).hurtbox.damage = (p->e).unk_48a;
              (p->e).hurtbox.knockback = 1;
              (p->e).hurtbox.iframes = 30;
              (p->e).unk_48c = 1;
              if ((p->e).flags5 & ENEFLAG5_UNK_1) {
                (p->e).playerMover = &gPlayerPtr[0]->mover;
              }
              if ((p->e).playerMover != NULL) {
                s32 dx = (p->e).playerMover->pos.x - (p->e).mover.pos.x;
                s32 dz = (p->e).playerMover->pos.z - (p->e).mover.pos.z;

                (p->e).playerAngle = ArcTan2_8(dx, dz);
                (p->e).playerDistSq = dx * dx + dz * dz;
              }
              break;
            }
          }
        }
      }
    }
  }
#else
  INCFUNC("asm/func/DogLink_OnStealHit.inc");
#endif
}

// dog.c の Dog_OnHurt と同じ
// 759/770 命令, dog.c の Dog_OnHurt の C をそのまま当てただけ, 残差は Dog_OnHurt と同じ形 (1回で打ち切り)
NON_MATCH void DogLink_OnHurt(Hitbox* a, Hitbox* b, DogLink* p) {
#ifdef NONMATCHING_C
  if (Hitbox_TestFlags(a, HBF_BLOCK)) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
#else
  INCFUNC("asm/func/DogLink_OnHurt.inc");
#endif
}

// dog.c の FUN_0814c28c と同じ
void FUN_081c7fb4(DogLink* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
}

// dog.c の FUN_0814c2b0 と同じ
void FUN_081c7fd8(DogLink* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

// dog.c の Dog_StateTurn と同じ
void DogLink_StateTurn(DogLink* p) {
  Mover* mover = &(p->e).mover;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 dir;
    u32 target;

    (p->e).mover.angle = Angle_ToDir4((p->e).mover.angle) * 64 - 64;
    dir = Angle_ToDir4((p->e).mover.angle);
    if ((p->e).subState2 != 6 && !Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_10)) {
      target = mover->path->node->delay >> 12;
      (p->e).unk_1dc = target;
    } else {
      target = (p->e).unk_1dc;
    }
    if (dir == FixToInt(1, target)) {
      (p->e).subStateDone = 1;
      if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_10)) {
        Enemy_PlayAnim(&p->e, 0);
        Enemy_ResetState(&p->e, 3, 1, 0);
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
        return;
      }
      Enemy_PlayAnim(&p->e, 0);
      return;
    }
    switch (dir) {
      case 0: {
        if (target - 2 < 4) {
          Dog_PlayTurnAnim(p, 13, 1, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Dog_PlayTurnAnim(p, 13, 0, ANIM_PLAY_XFLIP);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 1: {
        if (target - 4 < 4) {
          Dog_PlayTurnAnim(p, 13, 2, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Dog_PlayTurnAnim(p, 13, 3, 0);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 2: {
        if (target - 1 > 4) {
          Dog_PlayTurnAnim(p, 13, 3, ANIM_PLAY_XFLIP);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Dog_PlayTurnAnim(p, 13, 2, ANIM_PLAY_XFLIP);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
      case 3: {
        if (target < 4) {
          Dog_PlayTurnAnim(p, 13, 0, 0);
          SET_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        } else {
          Dog_PlayTurnAnim(p, 13, 1, ANIM_PLAY_XFLIP);
          CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_16);
        }
        break;
      }
    }
    (p->e).animForceRestart = FALSE;
  }
  if (Enemy_GetAuxAnim(&p->e)->tick == 1) {
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_16)) {
      mover->angle += 32;
    } else {
      mover->angle -= 32;
    }
  }
  {
    u16 speedDiv = (p->e).animSpeedDiv;

    if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_7)) {
      (p->e).animSpeedDiv = 3;
    }
    Enemy_UpdateWalkAnimSpeed(&p->e);
    (p->e).animSpeedDiv = speedDiv;
  }
  if ((p->e).animForceRestart) {
    s32 dir = Angle_ToDir8((p->e).mover.angle);
    s32 d = abs((p->e).unk_1dc - dir);

    if (d <= 0) {
      (p->e).subStateDone = 1;
      (p->e).mover.angle = Angle_ToDir4((p->e).mover.angle) * 64 - 64;
      Enemy_PlayAnim(&p->e, 0);
      if (Enemy_GetFlag3(&p->e, ENEFLAG3_UNK_10)) {
        Enemy_ResetState(&p->e, 3, 1, 0);
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
      }
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
    }
  }
}

// dog.c の FUN_0814c970 と同じ
void FUN_081c8698(DogLink* p) {}

// dog.c の Dog_StateNap と同じ
void DogLink_StateNap(DogLink* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 6);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_STUN)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
    }
  }
  if (Mod(timer, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait <= 0 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, DogLink_StateWakeUp, ES_WAKE_UP);
  }
}

// dog.c の Dog_StateWakeUp と同じ
void DogLink_StateWakeUp(DogLink* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
  }
  if (timer == 40) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart && timer > 120) {
    (p->e).subStateDone = 1;
  }
}

// dog.c の FUN_0814caa0 と同じ
// 97/94 命令, dog.c の FUN_0814caa0 の C をそのまま当てただけ, 残差は FUN_0814caa0 と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081c87c8(DogLink* p) {
#ifdef NONMATCHING_C
  u16 saved;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 11);
    (p->e).animForceRestart = FALSE;
  }
  saved = (p->e).animSpeedDiv;
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    (p->e).animSpeedDiv = 3;
  }
  Enemy_UpdateWalkAnimSpeed(&p->e);
  (p->e).animSpeedDiv = saved;
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
#else
  INCFUNC("asm/func/FUN_081c87c8.inc");
#endif
}

// dog.c の FUN_0814cb8c と同じ
void FUN_081c88b4(DogLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 11);
    (p->e).animForceRestart = FALSE;
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = TRUE;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_SetAngleToward(&p->e, (p->e).navAgent->waypoint.x, (p->e).navAgent->waypoint.z);
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      (p->e).animSpeedDiv = 2;
    } else {
      Enemy_PlayAnim(&p->e, 0);
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 7);
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    }
  }
}

// dog.c の Dog_StateDamaged と同じ
// 1771/1782 命令, dog.c の Dog_StateDamaged の C をそのまま当てただけ, 残差は Dog_StateDamaged と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081c8a24(DogLink* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).jumpVel.x = FixToInt(2, (p->e).jumpVel.x);
    (p->e).jumpVel.z = FixToInt(2, (p->e).jumpVel.z);
    Enemy_PlayAnim(&p->e, 3);
    (p->e).flags3 = ((p->e).flags3 & ~ENEFLAG3_UNK_8) | ENEFLAG3_UNK_5;
  }
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  if (!Enemy_StepSlide(&p->e)) {
    return;
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).subStateDone = 1;
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (TEST_FLAGS((p->e).flags6, HBATTR_STUN)) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_STUN_REQUEST);
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      return;
    }
    (p->e).onRouteFailed(&p->e);
  } else {
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).pathNodePos->val = 0;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!found) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 7);
    (p->e).animSpeedDiv = 4;
  }
#else
  INCFUNC("asm/func/FUN_081c8a24.inc");
#endif
}

// dog.c の Dog_StateFireBreathWindup の通信対戦版
void DogLink_StateFireBreathWindup(DogLink* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
  }
  Enemy_GetAuxAnim(&p->e)->cmdIdx = 0;
  Enemy_GetAuxAnim(&p->e)->tick = 0;
  if (Mod(timer, 4) == 0) {
    s32 dir = (((p->e).mover.angle + 0x20) & 0xFF) >> 6;
    Vec3 pos = (p->e).mover.pos;

    switch (dir) {
      case 0: {
        pos.x += 128;
        break;
      }
      case 1: {
        pos.z += 128;
        break;
      }
      case 2: {
        pos.x -= 160;
        break;
      }
      case 3: {
        pos.z -= 128;
        break;
      }
    }
    DogLink_SpawnSpark(&pos);
  }
  if (timer > 30) {
    Enemy_EnterState(&p->e, DogLink_StateFireBreath, ES_UNK_37);
  }
}

// dog.c の Dog_StateFireBreath と同じ
void DogLink_StateFireBreath(DogLink* p, s32 timer) {
  DogLink* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
    Entity081f1770_Spawn(&(p->e).mover.pos, (p->e).mover.angle, 0);
    PlaySound_082406e0(SONG_933);
  }
  if (timer >= 13 && timer <= 23) {
    Hitbox_Register(&q->unk_658);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// dog.c の FUN_0814deb0 と同じ
void FUN_081c9bd8(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 15);
    q->unk_708 = (p->e).playerMover->pos;
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, DogLink_StatePounce, ES_UNK_34);
  }
}

// dog.c の Dog_StatePounce と同じ
// 289/289 命令, dog.c の Dog_StatePounce の C をそのまま当てただけ, 残差は Dog_StatePounce と同じ形 (1回で打ち切り)
NON_MATCH void DogLink_StatePounce(DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Vec3 v;
    s32 target;
    s32 face;
    s32 d;

    q = (p->e).owner;
    Vec3_Delta(&v, &(p->e).mover.pos, &q->unk_708);
    target = ArcTan2_8(v.x, v.z);
    face = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) * 64;
    d = target - face;
    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (abs(d) < 16) {
      Vec3_SetPolar(&v, target, 24);
    } else if (d > 0) {
      Vec3_SetPolar(&v, (u8)(face + 16), 24);
    } else {
      Vec3_SetPolar(&v, (u8)(face - 17), 24);
    }
    (p->e).jumpVel.x = v.x;
    (p->e).jumpVel.y = 32;
    (p->e).jumpVel.z = v.z;
    PlaySound_082406e0(CRY_DOG_ALERT);
  }
  Hitbox_Register(&q->unk_658);
  if ((p->e).mover.tile->unk_0[0] & 1) {
    (p->e).jumpVel.x = FixToInt(1, (p->e).jumpVel.x);
    (p->e).jumpVel.z = FixToInt(1, (p->e).jumpVel.z);
  }
  Enemy_PlayAnim(&p->e, 5);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    Enemy_EnterState(&p->e, FUN_081c9ed8, ES_UNK_35);
  }
#else
  INCFUNC("asm/func/DogLink_StatePounce.inc");
#endif
}

// dog.c の FUN_0814e1b0 と同じ
void FUN_081c9ed8(DogLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 16);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// dog.c の FUN_0814e1fc と同じ
void FUN_081c9f24(DogLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 14);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// dog.c の Dog_StateLookAround と同じ
// 193/198 命令, dog.c の Dog_StateLookAround の C をそのまま当てただけ, 残差は Dog_StateLookAround と同じ形 (1回で打ち切り)
NON_MATCH void DogLink_StateLookAround(DogLink* p, s32 timer) {
#ifdef NONMATCHING_C
  u8* count;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    (p->e).animSpeedDiv = 2;
  }
  count = &(p->e).unk_542;
  if ((s8)*count > 0) {
    if (timer > 20) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
      if ((s8)*count == 1) {
        (p->e).unk_1dc = (((p->e).lookBaseAngle >> 5) + 3) & 7;
      } else {
        u8 cur = (p->e).mover.angle;
        s32 angle;
        s32 i;

        i = 0;
        while (TRUE) {
          angle = (Random() & 3) << 6;
          if (angle != cur) {
            break;
          }
          if (++i > 3) {
            angle = cur;
            break;
          }
        }
        (p->e).unk_1dc = ((angle >> 5) + 3) & 7;
      }
      (p->e).unk_542--;
    }
  } else {
    *count |= 0xFF;
    if (timer > 6) {
      Enemy_EnterState(&p->e, (p->e).savedHandlerState, (p->e).savedState);
      Enemy_ResetState(&p->e, (p->e).savedSubState0, (p->e).savedSubState1, (p->e).savedSubState2);
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_10);
    }
  }
#else
  INCFUNC("asm/func/DogLink_StateLookAround.inc");
#endif
}

// dog.c の FUN_0814e420 と同じ
void FUN_081ca148(DogLink* p) {}

// dog.c の FUN_0814e424 と同じ
void FUN_081ca14c(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    return;
  }
  Enemy_PlayAnim(&p->e, 11);
  if (FUN_081c70c8(p)) {
    Enemy_PlayAnim(&p->e, 0);
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
      ((EnemyHandler)(p->e).onRouteFailed)(&p->e);
    } else {
      Dog_ClearUnk6a8(q, 4);
      Enemy_ResetState(&p->e, 0, 0, 17);
    }
  }
}

// dog.c の FUN_0814e530 の通信対戦版
void FUN_081ca258(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    return;
  }
  if (Dog_TestUnk6a8(q, 4)) {
    if ((p->e).playerDistSq > q->unk_6bc) {
      Enemy_ResetState(&p->e, 0, 0, 19);
      (p->e).unk_1dc = (FixToInt(5, (p->e).playerAngle) + 3) & 7;
    } else {
      Dog_ClearUnk6a8(q, 4);
      if (q->unk_6d7 < 4) {
        if (DogLink_PickWalkDest(p, (p->e).mover.angle)) {
          Enemy_ResetState(&p->e, 0, 0, 17);
        }
      } else {
        Enemy_ResetState(&p->e, 0, 0, 19);
        (p->e).unk_1dc = (FixToInt(5, (p->e).playerAngle) + 3) & 7;
      }
    }
  } else {
    Enemy_PlayAnim(&p->e, 1);
  }
}

// dog.c の Dog_StateDying と同じ
void DogLink_StateDying(DogLink* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    (p->e).animForceRestart = FALSE;
    Enemy_SetEmote(&p->e, 0, 127, 0);
    Enemy_SetEmote(&p->e, 1, 127, 0);
    Enemy_SetEmote(&p->e, 3, 127, 0);
    Enemy_FadeParticles(&p->e, 4);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBF_HIDDEN;
  }
  Enemy_ClearDamage(&p->e);
  Enemy_UpdateJump(&p->e);
  Enemy_SnapToFloor(&p->e);
  if ((p->e).animForceRestart) {
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      s32 idx;

      (p->e).subStateDone = 1;
      DogLink_RunDefeatScript(p);
      if ((p->e).defeatScriptID != 0) {
        u32 argv[8];
        ScriptArgs sa;

        argv[0] = (p->e).mover.pos.x;
        argv[1] = (p->e).mover.pos.y;
        argv[2] = (p->e).mover.pos.z;
        argv[3] = (p->e).unk_19c;
        argv[4] = (p->e).unk_1a0;
        argv[5] = (p->e).unk_1a4;
        argv[6] = (p->e).unk_4a0;
        argv[7] = (p->e).mover.id;
        sa.argc = 8;
        sa.argv = argv;
        VM_ExecByID((p->e).defeatScriptID, &sa);
      }
      idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
      if (idx < 32) {
        gStat->enemyDexSeen[0] |= 1 << idx;
      } else {
        gStat->enemyDexSeen[1] |= 1 << (idx - 32);
      }
      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_14)) {
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        Enemy_ResetState(&p->e, 1, 0, 2);
      }
      ParticleShadow_Hide(&(p->e).shadow);
      Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    } else {
      Enemy_EnterState(&p->e, FUN_081ca614, ES_UNK_38);
    }
  }
}

// dog.c の FUN_0814e8ec と同じ
void FUN_081ca614(DogLink* p, s32 timer) {
  Enemy_ClearDamage(&p->e);
  Enemy_UpdateJump(&p->e);
  Enemy_SnapToFloor(&p->e);
  if (Sprite_UpdateVanishBlink(&(p->e).s->aux.spr.flags, timer, 10, 30)) {
    s32 idx;

    (p->e).subStateDone = 1;
    DogLink_RunDefeatScript(p);
    if ((p->e).defeatScriptID != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      argv[6] = (p->e).unk_4a0;
      argv[7] = (p->e).mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID((p->e).defeatScriptID, &sa);
    }
    idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_14)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 1, 0, 2);
    }
    ParticleShadow_Hide(&(p->e).shadow);
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  } else if (Enemy_TestSpriteFlags(&p->e, SPRFLAG_HIDDEN)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else {
    ParticleShadow_Show(&(p->e).shadow);
  }
}

// dog.c の FUN_0814fba4 の通信対戦版
void FUN_081ca7f4(DogLink* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_081c87c8, ES_UNK_10);
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    Enemy_RunScript(&p->e);
    Enemy_BeginChase(&p->e);
  }
  if ((p->e).subStateDone) {
    FUN_081c6048(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// dog.c の FUN_0814fc7c と同じ
// 938/926 命令, dog.c の FUN_0814fc7c の C をそのまま当てただけ, 残差は FUN_0814fc7c と同じ形 (1回で打ち切り)
NON_MATCH void FUN_081ca8cc(DogLink* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer <= 60) {
    (p->e).subStateTimer++;
    return;
  }

  Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    bool8 moved;

    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_4)) {
      (p->e).pendingDelay = 30;
      (p->e).pendingHandler = (p->e).handlerMove;
      (p->e).pendingSubState0 = 0;
      (p->e).pendingSubState1 = 0;
      (p->e).pendingSubState2 = 2;
      (p->e).animSpeedDiv = 1;
      return;
    }
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = (p->e).handlerMove;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 7;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      Vec3* dst = (p->e).pathNodePos;

      moved = FALSE;
      if (Map_IsPosInAgentIsland(agent, pos, dst)) {
        s32 result = Map_TryFindNavRoute(agent, pos, dst);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
      Enemy_ResetState(&p->e, 3, 0, 0);
    } else {
      (p->e).pathNodePos->val = 1;
    }
    return;
  }

  (p->e).pendingDelay = 30;
  (p->e).pendingHandler = (p->e).handlerChase;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 12;
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }

  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->kind <= 3) {
      idx = m->kind;
    }
    if (m == NULL || idx < 0) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }

  // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
  if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    u8 angle;

    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
      return;
    }
    (p->e).unk_222 &= ~ENEMY222_UNK_2;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 5);
      {
        Vec3* dst = (p->e).pathNodePos;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
      (p->e).pathNodePos->val = 0;
    }
    angle = (p->e).mover.angle;
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      s32 i;
      u32 a;

      for (i = 0; i < 4; i++) {
        a = (Random() & 3) << 6;
        if (a != angle) {
          break;
        }
      }
      if (i >= 4) {
        a = angle;
      }
      (p->e).lookAngle = a;
      (p->e).savedHandlerState = (p->e).handlerState;
      (p->e).savedState = (p->e).state;
      (p->e).savedSubState0 = (p->e).subState0;
      (p->e).savedSubState1 = (p->e).subState1;
      (p->e).savedSubState2 = (p->e).subState2;
      (p->e).lookBaseAngle = angle;
      Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
      Enemy_ResetState(&p->e, 3, 1, 0);
      (p->e).unk_542 = 6;
    }
    Enemy_StepToFloorEdge(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }

  {
    WorldPos tilePos;
    bool8 moved = FALSE;

    {
      s32 x = Mod(tile, gCollisionMap->tiledata->width);
      s32 z = Div(tile, gCollisionMap->tiledata->width);
      MapTileOverride* ov;

      tilePos.x = (x << 8) + 0x80;
      ov = Map_FindTileOverride(tile, 1);
      tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
      tilePos.z = (z << 8) + 0x80;
    }
    {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;

      if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
        s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      (p->e).onRouteFailed(&p->e);
    }
  }
#else
  INCFUNC("asm/func/FUN_081ca8cc.inc");
#endif
}

// dog.c の FUN_081504e8 と同じ
void FUN_081cb138(DogLink* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ae038; }

// dog.c の FUN_08150534 の通信対戦版
void FUN_081cb148(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Dog_ClearUnk6a8(q, 8);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, FUN_081c9bd8, ES_UNK_33);
    Dog_ClearUnk6a8((p->e).owner, 2);
    Hitbox_SetAttack(&q->unk_658, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    q->unk_6d7 = 0;
    q->unk_6c8 = q->unk_6cc;
  }
  if ((p->e).subStateDone) {
    q->unk_6c8 = q->unk_6cc;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    FUN_081c7228(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// dog.c の FUN_08150660 の通信対戦版
void FUN_081cb274(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Dog_ClearUnk6a8(q, 8);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, DogLink_StateFireBreathWindup, ES_UNK_36);
    Dog_SetUnk6a8((p->e).owner, 2);
    Hitbox_SetAttack(&q->unk_658, (p->e).atkPower[2], (p->e).atkKnockback[2], 0, (p->e).atkAttrs[2], (p->e).atkIframes[2]);
    q->unk_6d7 = 0;
  }
  if ((p->e).subStateDone) {
    q->unk_6ca = q->unk_6ce;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    FUN_081c7228(p);
  } else {
    (p->e).subStateTimer++;
  }
}

// dog.c の FUN_0815077c と同じ
void FUN_081cb390(DogLink* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ae040; }

// dog.c の FUN_081504f8 の通信対戦版, FUN_080f9f20 の判定を足したもの, 判定の中身が空だと結果の u8 化が消えるので return を置いた形で一致する
s32 FUN_081cb3a4(DogLink* p) {
  FUN_081c67fc(p);
  FUN_081c6bf8(p);
  FUN_080fa77c(&p->e);
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_STUN | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_6 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_13) && FUN_080f9f20(&p->e)) {
    return 1;
  }
  return 1;
}

// dog.c の FUN_08150510 の通信対戦版
s32 FUN_081cb3dc(DogLink* p) {
  DogLink_UpdateHitboxes(p);
  FUN_081c6ba8(p);
  FUN_081c6bd8(p);
  FUN_081c74b4(p);
  return 1;
}

// dog.c の FUN_08150790 の通信対戦版, 吠えながら待ち, 吠えるコマの終わりに近くの通信対戦プレイヤーがいれば飛びかかりの副状態 16 へ移る
// 437/430 命令, dog.c の FUN_08150790 (NON_MATCH) の C から FUN_080f0a0c の判定を抜き, 距離をプレイヤー0 でなく一番近い通信対戦プレイヤーで見る形にしたもの (1回で打ち切り)
NON_MATCH void FUN_081cb400(DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;
  AuxAnimState* anim;
  WorldPos d;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_081c9f24, ES_UNK_39);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  anim = &(p->e).s->aux.anim;
  if ((anim->cmdIdx == 6 || anim->cmdIdx == 12 || anim->cmdIdx == 19 || anim->cmdIdx == 25) && anim->tick == anim->wait - 1) {
    s32 count = gLinkSession != NULL ? gLinkSession->recordCount : -1;
    s32 bestIdx = -1;
    u32 best = 0x7FFFFFFF;
    s32 i;

    for (i = 0; i < count; i++) {
      if (gPlayerPtr[i] != NULL && !TEST_FLAGS(gPlayerModes[i], PMODE_UNK_3)) {
        u32 distSq;

        Vec3_Delta(&d, &(p->e).mover.pos, &gPlayerPtr[i]->mover.pos);
        distSq = d.x * d.x + d.z * d.z;
        if (distSq < q->unk_6b4 && distSq < best) {
          bestIdx = i;
          best = distSq;
        }
      }
    }
    if (bestIdx >= 0) {
      Enemy_SetEmote(&p->e, 0, 1, (p->e).kind);
      Enemy_ResetState(&p->e, 0, 0, 16);
      q->unk_708 = gPlayerPtr[bestIdx]->mover.pos;
      if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
        (p->e).chaseTimer += 300;
        if ((p->e).chaseTimer > (p->e).chaseTimeMax) {
          (p->e).chaseTimer = (p->e).chaseTimeMax;
        }
      }
      return;
    }
  }
  if ((p->e).subStateDone) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_ResetState(&p->e, 0, 0, 12);
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    } else {
      d.x = (p->e).pathWalker.node->x;
      d.z = (p->e).pathWalker.node->y;
      d.y = TileHeightAt(&d);
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 2);
      if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &d)) {
        (p->e).onRouteFailed(&p->e);
      }
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_081cb400.inc");
#endif
}

// dog.c の FUN_08150b18 の通信対戦版 (FUN_080f0a0c の判定が無い)
void FUN_081cb7e8(DogLink* p) {
  DogLink* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_081c87c8, ES_UNK_10);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if ((p->e).subStateDone) {
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &q->unk_708)) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_ResetState(&p->e, 0, 0, 12);
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    } else {
      WorldPos* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
      (p->e).pathNodePos->val = 0;
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 7);
      (p->e).animSpeedDiv = 2;
    }
  } else {
    (p->e).subStateTimer++;
  }
}

// dog.c の FUN_08150de8 の通信対戦版
// 781/773 命令, dog.c の FUN_08150de8 の C をそのまま当てただけ, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH void FUN_081cbaa8(DogLink* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer <= 20) {
    (p->e).subStateTimer++;
    return;
  }

  (p->e).unk_222 &= ~(ENEMY222_UNK_1 | ENEMY222_UNK_2);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  (p->e).pendingDelay = (p->e).unk_543;
  (p->e).pendingHandler = (p->e).handlerChase;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 12;
  Enemy_ResetState(&p->e, 3, 1, 0);
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }

  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->kind <= 3) {
      idx = m->kind;
    }
    if (m == NULL || idx < 0) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }

  if (tile != (p->e).tileIdx && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    WorldPos tilePos;
    bool8 moved = FALSE;

    {
      s32 x = Mod(tile, gCollisionMap->tiledata->width);
      s32 z = Div(tile, gCollisionMap->tiledata->width);
      MapTileOverride* ov;

      tilePos.x = (x << 8) + 0x80;
      ov = Map_FindTileOverride(tile, 1);
      tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
      tilePos.z = (z << 8) + 0x80;
    }
    {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;

      if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
        s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      (p->e).onRouteFailed(&p->e);
    }
    return;
  }

  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
    return;
  }
  (p->e).unk_222 &= ~ENEMY222_UNK_2;
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
    Enemy_ResetState(&p->e, 0, 0, 12);
  } else {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 5);
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
    (p->e).pathNodePos->val = 0;
  }

  {
    u8 angle = (p->e).mover.angle;

    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      s32 i;
      u32 a;

      for (i = 0; i <= 3; i++) {
        a = (Random() & 3) << 6;
        if (a != angle) {
          break;
        }
      }
      if (i > 3) {
        a = angle;
      }
      (p->e).lookAngle = a;
      (p->e).savedHandlerState = (p->e).handlerState;
      (p->e).savedState = (p->e).state;
      (p->e).savedSubState0 = (p->e).subState0;
      (p->e).savedSubState1 = (p->e).subState1;
      (p->e).savedSubState2 = (p->e).subState2;
      (p->e).lookBaseAngle = angle;
      Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
      Enemy_ResetState(&p->e, 3, 1, 0);
      (p->e).unk_542 = 6;
    }
  }
  Enemy_StepToFloorEdge(&p->e);
  (p->e).animSpeedDiv = 2;
#else
  INCFUNC("asm/func/FUN_081cbaa8.inc");
#endif
}

// dog.c の FUN_081514f0 の通信対戦版 (FUN_080f0a0c の判定が無い)
void FUN_081cc1a4(DogLink* p) {
  DogLink* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_081ca258, ES_UNK_41);
    Dog_SetUnk6a8(q, 8);
  }
  speed = (p->e).getMoveSpeed(&p->e);
  (p->e).animSpeedDiv = 2;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Dog_SetUnk6a8(q, 4);
      return;
    }
  } else if (Enemy_TurnTowardWaypoint(&p->e, (p->e).navAgent, 32, 32, speed)) {
    Enemy_ResetState(&p->e, 0, 0, 18);
  }
  if (FUN_081c70c8(p)) {
    if ((p->e).tryDetectPlayer(&p->e)) {
      return;
    }
  }
  (p->e).subStateTimer++;
}

// dog.c の FUN_081516d8 の通信対戦版 (FUN_080f0a0c の判定が無い)
void FUN_081cc380(DogLink* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (!FUN_081c70c8(p) || !(p->e).tryDetectPlayer(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 0, 0, 17);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// dog.c の FUN_081517a8 の通信対戦版 (FUN_080f0a0c の判定が無い)
void FUN_081cc444(DogLink* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (!FUN_081c70c8(p) || !(p->e).tryDetectPlayer(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, FUN_081ca14c, ES_UNK_42);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// dog.c の FUN_081518ac と同じ
void FUN_081cc53c(DogLink* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ae048; }

// dog.c の Dog_OnDamaged の通信対戦版
// 1828/1830 命令, dog.c の Dog_OnDamaged の C をそのまま当てただけ, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH bool8 DogLink_OnDamaged(DogLink* p) {
#ifdef NONMATCHING_C
  DogLink* q = (p->e).owner;
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_STUN | ENEFLAG3_UNK_15)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags6, HBATTR_BLOW | HBATTR_STUN)) {
    Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_24);
    q->unk_6a8 &= ~8;
    return TRUE;
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  if ((p->e).unk_4be != 0) {
    return FALSE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    if ((p->e).unk_48d == 0 && ((p->e).unk_48c & 8)) {
      (p->e).unk_4be = 45;
      (p->e).unk_48d = 65;
      Enemy_PlayAnim(&p->e, 3);
    }
    if ((p->e).playerMover == NULL) {
      return FALSE;
    }
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    if (FUN_081c70c8(p)) {
      {
        Vec3* dst = (p->e).pathNodePos;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      found = FALSE;
      haveTile = TRUE;
      if (IsLinkPlay()) {
        Mover* m = (p->e).playerMover;

        idx = -1;
        if (m != NULL && m->kind <= 3) {
          idx = m->kind;
        }
        if (m == NULL || idx < 0) {
          haveTile = FALSE;
        } else {
          tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
        }
      } else {
        tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
        idx = 0;
      }
      if (haveTile) {
        if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
          // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
            u8 angle;

            (p->e).unk_222 &= ~ENEMY222_UNK_2;
            if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
              Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
              Enemy_ResetState(&p->e, 0, 0, 12);
            } else {
              Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
              Enemy_ResetState(&p->e, 0, 0, 5);
              {
                Vec3* dst = (p->e).pathNodePos;
                PathWalker* walker = &(p->e).pathWalker;

                dst->x = walker->node->x;
                dst->z = walker->node->y;
                dst->y = TileHeightAt(dst);
              }
              (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
              (p->e).pathNodePos->val = 0;
            }
            angle = (p->e).mover.angle;
            if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
              s32 i;
              u32 a;

              for (i = 0; i < 4; i++) {
                a = (Random() & 3) << 6;
                if (a != angle) {
                  break;
                }
              }
              if (i >= 4) {
                a = angle;
              }
              (p->e).lookAngle = a;
              (p->e).savedHandlerState = (p->e).handlerState;
              (p->e).savedState = (p->e).state;
              (p->e).savedSubState0 = (p->e).subState0;
              (p->e).savedSubState1 = (p->e).subState1;
              (p->e).savedSubState2 = (p->e).subState2;
              (p->e).lookBaseAngle = angle;
              Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
              Enemy_ResetState(&p->e, 3, 1, 0);
              (p->e).unk_542 = 6;
            }
            Enemy_StepToFloorEdge(&p->e);
            (p->e).animSpeedDiv = 2;
          }
        } else {
          WorldPos tilePos;

          {
            s32 x = Mod(tile, gCollisionMap->tiledata->width);
            s32 z = Div(tile, gCollisionMap->tiledata->width);
            MapTileOverride* ov;

            tilePos.x = (x << 8) + 0x80;
            ov = Map_FindTileOverride(tile, 1);
            tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
            tilePos.z = (z << 8) + 0x80;
          }
          {
            NavAgent* agent = (p->e).navAgent;
            WorldPos* pos = &(p->e).mover.pos;

            if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
              s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

              if (result != 0) {
                if (result != 2) {
                  ClearMemory(&(p->e).mover.delta, 8);
                }
                found = TRUE;
              }
            }
            if (!found) {
              CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
            }
          }
          if (!found) {
            haveTile = FALSE;
          }
        }
      }
      if (!haveTile) {
        (p->e).onRouteFailed(&p->e);
      }
      if (!found) {
        NavAgent* agent = (p->e).navAgent;
        WorldPos* pos = &(p->e).mover.pos;
        WorldPos* target = &(p->e).playerMover->pos;

        if (Map_IsPosInAgentIsland(agent, pos, target)) {
          s32 result = Map_TryFindNavRoute(agent, pos, target);

          if (result != 0) {
            if (result != 2) {
              ClearMemory(&(p->e).mover.delta, 8);
            }
            found = TRUE;
          }
        }
        if (!found) {
          CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
        }
      }
      if (!found) {
        (p->e).onRouteFailed(&p->e);
        return FALSE;
      }
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      return TRUE;
    }
    if (q->unk_6d8 != 0) {
      return TRUE;
    }
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 18);
    (p->e).unk_1dc = (FixToInt(5, ((p->e).playerAngle + 0xA0) & 0xFF) + 3) & 7;
    {
      u8 angle = (p->e).mover.angle;

      (p->e).mover.angle = (((angle + 0xA0) & 0xFF) >> 6) << 6;
      q->unk_6d8 = 90;
      if (DogLink_PickWalkDest(p, angle)) {
        return TRUE;
      }
    }
    return FALSE;
  }
  if ((p->e).unk_48d == 0 && ((p->e).unk_48c & 8)) {
    (p->e).unk_4be = 45;
    (p->e).unk_48d = 65;
    Enemy_PlayAnim(&p->e, 3);
  }
  if ((p->e).playerMover == NULL) {
    return FALSE;
  }
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
  (p->e).pathNodePos->val = 0;
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  found = FALSE;
  haveTile = TRUE;
  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->kind <= 3) {
      idx = m->kind;
    }
    if (m == NULL || idx < 0) {
      haveTile = FALSE;
    } else {
      tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
    }
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }
  if (haveTile) {
    if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
      // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
        u8 angle;

        (p->e).unk_222 &= ~ENEMY222_UNK_2;
        if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
          Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
          Enemy_ResetState(&p->e, 0, 0, 12);
        } else {
          Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
          Enemy_ResetState(&p->e, 0, 0, 5);
          {
            Vec3* dst = (p->e).pathNodePos;
            PathWalker* walker = &(p->e).pathWalker;

            dst->x = walker->node->x;
            dst->z = walker->node->y;
            dst->y = TileHeightAt(dst);
          }
          (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
          (p->e).pathNodePos->val = 0;
        }
        angle = (p->e).mover.angle;
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
          s32 i;
          u32 a;

          for (i = 0; i < 4; i++) {
            a = (Random() & 3) << 6;
            if (a != angle) {
              break;
            }
          }
          if (i >= 4) {
            a = angle;
          }
          (p->e).lookAngle = a;
          (p->e).savedHandlerState = (p->e).handlerState;
          (p->e).savedState = (p->e).state;
          (p->e).savedSubState0 = (p->e).subState0;
          (p->e).savedSubState1 = (p->e).subState1;
          (p->e).savedSubState2 = (p->e).subState2;
          (p->e).lookBaseAngle = angle;
          Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
          Enemy_ResetState(&p->e, 3, 1, 0);
          (p->e).unk_542 = 6;
        }
        Enemy_StepToFloorEdge(&p->e);
        (p->e).animSpeedDiv = 2;
      }
    } else {
      WorldPos tilePos;

      {
        s32 x = Mod(tile, gCollisionMap->tiledata->width);
        s32 z = Div(tile, gCollisionMap->tiledata->width);
        MapTileOverride* ov;

        tilePos.x = (x << 8) + 0x80;
        ov = Map_FindTileOverride(tile, 1);
        tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
        tilePos.z = (z << 8) + 0x80;
      }
      {
        NavAgent* agent = (p->e).navAgent;
        WorldPos* pos = &(p->e).mover.pos;

        if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
          s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

          if (result != 0) {
            if (result != 2) {
              ClearMemory(&(p->e).mover.delta, 8);
            }
            found = TRUE;
          }
        }
        if (!found) {
          CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
        }
      }
      if (!found) {
        haveTile = FALSE;
      }
    }
  }
  if (!haveTile) {
    (p->e).onRouteFailed(&p->e);
  }
  if (!found) {
    NavAgent* agent = (p->e).navAgent;
    WorldPos* pos = &(p->e).mover.pos;
    WorldPos* target = &(p->e).playerMover->pos;

    if (Map_IsPosInAgentIsland(agent, pos, target)) {
      s32 result = Map_TryFindNavRoute(agent, pos, target);

      if (result != 0) {
        if (result != 2) {
          ClearMemory(&(p->e).mover.delta, 8);
        }
        found = TRUE;
      }
    }
    if (!found) {
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
    }
  }
  if (!found) {
    (p->e).onRouteFailed(&p->e);
    return FALSE;
  }
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  Enemy_ResetState(&p->e, 0, 0, 7);
  (p->e).animSpeedDiv = 4;
  return TRUE;
#else
  INCFUNC("asm/func/DogLink_OnDamaged.inc");
#endif
}

// dog.c の Dog_StateDamaged の通信対戦版
// 1771/1779 命令, dog.c の Dog_StateDamaged の C をそのまま当てただけ, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH void DogLink_StateDamaged(DogLink* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;
  bool8 found;
  bool8 haveTile;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).jumpVel.x = FixToInt(2, (p->e).jumpVel.x);
    (p->e).jumpVel.z = FixToInt(2, (p->e).jumpVel.z);
    Enemy_PlayAnim(&p->e, 3);
    (p->e).flags3 = ((p->e).flags3 & ~ENEFLAG3_UNK_8) | ENEFLAG3_UNK_5;
  }
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  if (!Enemy_StepSlide(&p->e)) {
    return;
  }
  if (!(p->e).animForceRestart) {
    return;
  }
  (p->e).subStateDone = 1;
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  if (TEST_FLAGS((p->e).flags6, HBATTR_STUN)) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_STUN_REQUEST);
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (found) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
      return;
    }
    (p->e).onRouteFailed(&p->e);
  } else {
    (p->e).playerMover = &gPlayerPtr[0]->mover;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_4);
    (p->e).pathNodePos->val = 0;
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    found = FALSE;
    haveTile = TRUE;
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        haveTile = FALSE;
      } else {
        tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
      }
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (haveTile) {
      if (tile == (p->e).tileIdx || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
        // プレイヤーと同じタイルにいるか見えないときは歩きに戻して向きを乱数で変える予約を入れる
        if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
          u8 angle;

          (p->e).unk_222 &= ~ENEMY222_UNK_2;
          if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
            Enemy_ResetState(&p->e, 0, 0, 12);
          } else {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 5);
            {
              Vec3* dst = (p->e).pathNodePos;
              PathWalker* walker = &(p->e).pathWalker;

              dst->x = walker->node->x;
              dst->z = walker->node->y;
              dst->y = TileHeightAt(dst);
            }
            (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
            (p->e).pathNodePos->val = 0;
          }
          angle = (p->e).mover.angle;
          if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
            s32 i;
            u32 a;

            for (i = 0; i < 4; i++) {
              a = (Random() & 3) << 6;
              if (a != angle) {
                break;
              }
            }
            if (i >= 4) {
              a = angle;
            }
            (p->e).lookAngle = a;
            (p->e).savedHandlerState = (p->e).handlerState;
            (p->e).savedState = (p->e).state;
            (p->e).savedSubState0 = (p->e).subState0;
            (p->e).savedSubState1 = (p->e).subState1;
            (p->e).savedSubState2 = (p->e).subState2;
            (p->e).lookBaseAngle = angle;
            Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
            Enemy_ResetState(&p->e, 3, 1, 0);
            (p->e).unk_542 = 6;
          }
          Enemy_StepToFloorEdge(&p->e);
          (p->e).animSpeedDiv = 2;
        }
      } else {
        WorldPos tilePos;

        {
          s32 x = Mod(tile, gCollisionMap->tiledata->width);
          s32 z = Div(tile, gCollisionMap->tiledata->width);
          MapTileOverride* ov;

          tilePos.x = (x << 8) + 0x80;
          ov = Map_FindTileOverride(tile, 1);
          tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
          tilePos.z = (z << 8) + 0x80;
        }
        {
          NavAgent* agent = (p->e).navAgent;
          WorldPos* pos = &(p->e).mover.pos;

          if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
            s32 result = Map_TryFindNavRoute(agent, pos, &tilePos);

            if (result != 0) {
              if (result != 2) {
                ClearMemory(&(p->e).mover.delta, 8);
              }
              found = TRUE;
            }
          }
          if (!found) {
            CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
          }
        }
        if (!found) {
          haveTile = FALSE;
        }
      }
    }
    if (!haveTile) {
      (p->e).onRouteFailed(&p->e);
    }
    if (!found) {
      NavAgent* agent = (p->e).navAgent;
      WorldPos* pos = &(p->e).mover.pos;
      WorldPos* target = &(p->e).playerMover->pos;

      if (Map_IsPosInAgentIsland(agent, pos, target)) {
        s32 result = Map_TryFindNavRoute(agent, pos, target);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&(p->e).mover.delta, 8);
          }
          found = TRUE;
        }
      }
      if (!found) {
        CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!found) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 7);
    (p->e).animSpeedDiv = 4;
  }
#else
  INCFUNC("asm/func/DogLink_StateDamaged.inc");
#endif
}

// dog.c の FUN_081518c0 と同じ
s32 FUN_081ce654(DogLink* p) {
  DogLink* self = p;

  FUN_081cb3a4(p);
  if ((p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }
  FUN_081cb3dc(self);
  return 1;
}

// dog.c の Dog_Update と同じ
s32 DogLink_Update(DogLink* p) {
  Enemy_Update(&p->e);
  return 0;
}

// dog.c の Dog_Destroy と同じ
s32 DogLink_Destroy(DogLink* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove(&(p->e).s->aux.spr);
  } else {
    MainSprite_Remove(&(p->e).s->main.spr);
  }
  Free((p->e).s);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).shadowRemoved) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).shadowRemoved = 1;
  }
  if (!(p->e).emitterRemoved) {
    ElementalCondEmitter_Destroy(&(p->e).emitter);
    (p->e).emitterRemoved = 1;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a58(&(p->e).mover);
  }
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// dog.c の Dog_Init の通信対戦版
// 1687/1841 命令, dog.c の Dog_Init の C をそのまま当てただけ, 通信対戦版の差分は未調査 (1回で打ち切り)
NON_MATCH s32 DogLink_Init(DogLink* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  p->unk_6a8 = 0;
  p->unk_6d6 = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_DOG;
  DogLink_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPR_DOG);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_DOG);
    k = (p->e).kind;
    if (k == ENEK_CURORO || k == ENEK_GHOST) {
      aux->spr.priority = 1;
    }
    (p->e).facing = 0;
  } else {
    EnemyMainSprite* spr;
    MainSpriteGfxFile* f;
    Vec3 origin;

    (p->e).s = Malloc(sizeof(EnemySprite));
    ClearMemory((p->e).s, sizeof(EnemySprite));
    spr = &(p->e).s->main;
    Vec3_Clear(&origin);
    f = GetFile(DIR_MAIN_SPRITE, SPR_DOG);
    spr->gfx = *f;
    OpenMainSpriteFile(&spr->gfx, f);
    MainSprite_Add(&spr->spr, &spr->gfx, 0, 0, 2, 2, 60, &origin);
    (p->e).playingAnim = 0xFF;
  }

  (p->e).flags = 0;
  (p->e).flags2 = 0;
  (p->e).unk_46f = 0;
  (p->e).unk_1bc = 8;
  (p->e).flags5 = VM_GetNamedArgValue('M', 0);
  Vec3_Clear(&pos);
  (p->e).unk_4b6 = 0;
  if (!VM_SeekToNamedArg('r')) {
    (p->e).unk_250 = 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = 0;
    (p->e).prevPathNode = 0;
    (p->e).unk_4b4[(p->e).unk_4b6] = 0;
    (p->e).unk_4b4[(p->e).unk_4b6 ^ 1] = 0;
    onPath = FALSE;
  } else {
    u8 sel;

    (p->e).unk_250 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).prevPathNode = (p->e).unk_252;
    (p->e).unk_4b4[(p->e).unk_4b6] = (p->e).unk_250;
    sel = (p->e).unk_4b6;
    (p->e).unk_4b4[sel ^ 1] = VM_GetPC() != NULL ? VM_GetValue() : (p->e).unk_250;
    Map_GetPathNodePos(&pos, (p->e).unk_250, (p->e).unk_252);
    (p->e).tileIdx = GetCollisionTileIdx(&pos);
    pos.y = TileHeightAt(&pos);
    (p->e).floorY = pos.y;
    onPath = TRUE;
  }

  id = VM_GetNamedArgValue('N', 0);
  if (!VM_SeekToNamedArg('e')) {
    range0 = 48;
    range3 = 64;
  } else {
    range0 = VM_GetPC() != NULL ? VM_GetValue() : 48;
    range3 = VM_GetPC() != NULL ? (u8)VM_GetValue() : 64;
  }
  if (!VM_SeekToNamedArg('n')) {
    range1 = 0;
    (p->e).unk_1fe = 0;
  } else {
    range1 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_1fe = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  range2 = range0;

  if (VM_SeekToNamedArg('a')) {
    for (i = 0; i < 4; i++) {
      (p->e).atkPower[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkKnockback[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkAttrs[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      (p->e).atkIframes[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  if (!VM_SeekToNamedArg('l')) {
    hpParam3 = 0;
    hpParam4 = 0;
    (p->e).chaseTimeMax = 0;
  } else {
    hpParam3 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    hpParam4 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    (p->e).chaseTimeMax = VM_GetPC() != NULL ? VM_GetValue() : 300;
  }
  if (VM_GetNamedArgValue('b', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_9);
  }
  (p->e).scriptID = VM_GetNamedArgValue('F', 0);
  (p->e).unk_194 = VM_GetNamedArgValue('R', 0);
  if (VM_SeekToNamedArg('A')) {
    (p->e).maxHp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_546 = (p->e).maxHp >> 1;
    (p->e).power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_187 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_188 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).attrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weakness = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  Enemy_InitHpAndState(&p->e, (p->e).maxHp, hpParam3, hpParam4);
  Enemy_SetRanges(&p->e, 0, range0, range2, range1, range3);
  if (VM_SeekToNamedArg('X')) {
    (p->e).exp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weaponExp = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  (p->e).unk_25a = VM_GetNamedArgValue('K', 2);
  if (VM_GetNamedArgValue('H', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_11);
  }
  if (VM_GetNamedArgValue('L', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_15);
  }

  Mover_Init(&(p->e).mover, id, &pos, 0, MOVER_ENEMY, p);
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, Enemy_OnCWolfMessage);
  }
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? &(p->e).s->aux.spr : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 64, 64);
  }
  kind = (p->e).kind;
  if (kind != ENEK_BAT && kind != ENEK_CROW && kind != ENEK_MIMIC && kind != ENEK_SLIME && kind != ENEK_BEE && kind != ENEK_CENTIPEDE && kind != ENEK_SANDWORM && kind != ENEK_SERPENT && kind != ENEK_AX && kind != ENEK_SHAIAN && kind != ENEK_SALAMANDER) {
    Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_250, (p->e).unk_251, (p->e).unk_252);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_3)) {
    (p->e).unk_1e8 = Div((p->e).range0Sq * 7, 10);
  } else {
    (p->e).unk_1e8 = (p->e).range0Sq;
  }
  (p->e).zoneSource.id = (p->e).mover.id;
  (p->e).zoneSource.pos = &(p->e).mover.pos;
  if (onPath) {
    (p->e).mover.angle = ((((p->e).pathWalker.node->delay >> 12 & 7) + 5) & 7) << 5;
  }
  if (VM_SeekToNamedArg('P')) {
    p->unk_6cc = VM_GetPC() != NULL ? VM_GetValue() : 200;
    p->unk_6ce = VM_GetPC() != NULL ? VM_GetValue() : 320;
  }
  if (VM_SeekToNamedArg('Y')) {
    p->unk_6b4 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_6b4 *= p->unk_6b4;
    p->unk_6c2 = VM_GetPC() != NULL ? VM_GetValue() : 640;
    p->unk_6c4 = VM_GetPC() != NULL ? VM_GetValue() : 640;
  }
  p->unk_6d9 = VM_GetNamedArgValue('d', 50);
  if (p->unk_6d9 == 0) {
    p->unk_6d9 = 50;
  }
  p->unk_6d0 = -1;
  p->unk_6d4 = 0;
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 501;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 501;
  if ((p->e).spriteKind == 0) {
    Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + (p->e).variant);
  } else {
    (p->e).s->main.spr.pltt = &gObjPlttData[((p->e).plttBase + (p->e).variant) * 16];
  }
  if ((p->e).spriteKind == 1) {
    s16 n;

    if ((p->e).kind >= ENEK_SKELETON && (p->e).kind <= ENEK_LICH) {
      n = Enemy_CountByKind(ENEK_SKELETON) + 1 + Enemy_CountByKind(ENEK_SKELETON_F) + Enemy_CountByKind(ENEK_SKELETON_A) + Enemy_CountByKind(ENEK_LICH);
    } else {
      n = Enemy_CountByKind((p->e).kind) + 1;
    }
    (p->e).s->main.spr.plttID = n + 220;
  }

  DogLink_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)FUN_081ce654;
  (p->e).getMoveSpeed = (void*)FUN_081c6604;
  (p->e).handlerTurn = DogLink_StateTurn;
  (p->e).handlerMove = FUN_081c7fb4;
  (p->e).handlerWait = FUN_081c7fd8;
  (p->e).handlerNap = DogLink_StateNap;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = DogLink_StateDamaged;
  (p->e).handlerDying = DogLink_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = FUN_081c88b4;
  (p->e).unk_584 = FUN_081c8698;
  (p->e).unk_604 = FUN_080f62ac;
  (p->e).tryDetectPlayer = FUN_080f0430;
  (p->e).unk_21d = 1;
  (p->e).msgHandlers = (void*)gEnemyDefaultMsgHandlers;
  (p->e).unk_5f0 = FUN_080e73c8;
  (p->e).unk_5e4 = NULL;
  (p->e).onReset = NULL;
  (p->e).unk_5fc = NULL;
  (p->e).unk_600 = NULL;
  (p->e).unk_614 = NULL;
  (p->e).unk_618 = FUN_080f0320;
  (p->e).handlerLookAround = Enemy_080eff14;
  (p->e).unk_5e8 = FUN_080e72b0;
  (p->e).unk_5e0 = FUN_081ca148;
  (p->e).unk_5ec = Enemy_StateBlownAway;
  (p->e).unk_5d8 = Enemy_StateFallDeath;
  (p->e).unk_5a8 = NULL;
  (p->e).unk_624 = FUN_080f6e64;
  (p->e).onDamaged = Enemy_OnDamaged;
  (p->e).unk_628 = (void*)FUN_080f84d4;
  (p->e).handlerChase = FUN_080f624c;
  (p->e).handlerStun = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  Map_InitNavAgent(&p->navAgent, &(p->e).mover.pos);
  Enemy_StepTowardPathNode(&p->e);
  (p->e).onReset = (EnemyHandler)DogLink_OnReset;
  (p->e).unk_5fc = (void*)FUN_081c65f0;
  (p->e).onAttackRequest = (EnemyHandler)FUN_081c5c94;
  (p->e).unk_5b0 = (EnemyHandler)FUN_081c5dc0;
  (p->e).onDamaged = (void*)DogLink_OnDamaged;
  (p->e).handlerLookAround = DogLink_StateLookAround;
  (p->e).unk_618 = (void*)DogLink_NoticeAttacker;
  (p->e).unk_1bc = 0;
  (p->e).unk_543 = 20;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_21 | ENEFLAG_UNK_22 | ENEFLAG_UNK_24);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3);
  Enemy_InitShadowAndEmitter(&p->e);

  (p->e).unk_198 = VM_GetNamedArgValue('I', 0);
  if (VM_SeekToNamedArg('G')) {
    u32* arg = &(p->e).unk_19c;

    for (i = 0; i < 5; i++) {
      *arg++ = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  (p->e).defeatScriptID = VM_GetNamedArgValue('D', 0);
  {
    s32 u = VM_GetNamedArgValue('u', 0);

    (p->e).unk_496[0] = 0x21;
    (p->e).unk_496[1] = 0;
    if (u != 0) {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_18);
      if (u == 2) {
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_18 | ENEFLAG_UNK_19);
      }
    }
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_2)) {
    Enemy_ResetState(&p->e, 0, 0, 0);
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  } else {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_13);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_1)) {
    (p->e).zoneID = GetZoneAt(&(p->e).mover.pos);
  } else {
    (p->e).zoneID = gStat->zoneID;
  }
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_6)) {
    (p->e).hurtbox.flags &= ~HBF_ANGLE;
  }
  if (VM_GetNamedArgValue('S', 0) != 0 || gStat->zoneID != (p->e).zoneID) {
    Enemy_Suspend(&p->e, NULL);
  }
  Enemy_PlayAnim(&p->e, 0);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux = &(p->e).s->aux;

    AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
  } else {
    MainSprite_AdvanceAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx);
  }
  (p->e).hitTargetID = 0;
  kind = (p->e).kind;
  if (!IsLinkPlay() && (kind == ENEK_BOKU || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DOG || kind == ENEK_BEE || kind == ENEK_GHOST)) {
    MsgQueue_Register(&(p->e).mq, (p->e).mover.id, 3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_8);
  }
  {
    DogLink* q = (p->e).owner;

    if ((p->e).variant < 2 || (p->e).variant == 4) {
      q->unk_6ac = 0x40000;
    } else {
      q->unk_6ac = 0x40000;
      q->unk_6b0 = 0x38400;
    }
    q->unk_6b8 = 0xFFFF;
    q->unk_6bc = q->unk_6ac;
  }
  Enemy_InitHandlerTables(&p->e);
  FUN_081cc53c(p);
  FUN_081cb138(p);
  FUN_081cb390(p);
  (p->e).initFlags5 = (p->e).flags5;
  (p->e).initHeightAboveFloor = (p->e).heightAboveFloor;
  (p->e).initFlags = (p->e).flags;
  (p->e).initFlags2 = (p->e).flags2;
  (p->e).initAngle = (p->e).mover.angle;
  (p->e).initSubState0 = (p->e).subState0;
  (p->e).initSubState1 = (p->e).subState1;
  (p->e).initSubState2 = (p->e).subState2;
  (p->e).initHandlerState = (p->e).handlerState;
  (p->e).initState = (p->e).state;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)DogLink_Update;
  (p->e).handlerDestroy = (EnemyHandler)DogLink_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/DogLink_Init.inc");
#endif
}

// dog.c の Dog_Create の通信対戦版
void DogLink_Create(void) {
  DogLink* p = Malloc(sizeof(DogLink));

  if (p != NULL) {
    ClearMemory(p, sizeof(DogLink));
    if (DogLink_Init(p) < 0) {
      DogLink_Destroy(p);
      Free(p);
    }
  }
}
