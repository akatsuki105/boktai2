#include "cwolf_target.h"
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

    anim += variant;
    if ((p->e).playingAnim == anim && !(p->e).animForceRestart && ((flip == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flip == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    (p->e).playingAnim = anim;
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    if (flip == ANIM_PLAY_XFLIP) {
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
NAKED void FUN_081c5c94(DogLink* p) { INCFUNC("asm/func/FUN_081c5c94.inc"); }

// dog.c の FUN_0814a098 と同じ
NAKED void FUN_081c5dc0(DogLink* p) { INCFUNC("asm/func/FUN_081c5dc0.inc"); }

// dog.c の enemy_dog_0814a320 の通信対戦版
NAKED void FUN_081c6048(DogLink* p) { INCFUNC("asm/func/FUN_081c6048.inc"); }

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
NAKED void DogLink_OnReset(DogLink* p) { INCFUNC("asm/func/DogLink_OnReset.inc"); }

// dog.c の FUN_0814a8c8 と同じ
void FUN_081c65f0(DogLink* p) { CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1); }

// dog.c の FUN_0814a8dc と同じ
NAKED s32 FUN_081c6604(DogLink* p) { INCFUNC("asm/func/FUN_081c6604.inc"); }

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
NAKED bool8 DogLink_PickWalkDest(DogLink* p, u32 angle) { INCFUNC("asm/func/DogLink_PickWalkDest.inc"); }

// dog.c の FUN_0814b3a0 と同じ
NAKED bool8 FUN_081c70c8(DogLink* p) { INCFUNC("asm/func/FUN_081c70c8.inc"); }

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
NAKED void FUN_081c7228(DogLink* p) { INCFUNC("asm/func/FUN_081c7228.inc"); }

// dog.c の FUN_0814b78c と同じ
void FUN_081c74b4(DogLink* p) {
  if (p->unk_6d8 != 0) {
    p->unk_6d8--;
  }
}

// dog.c の Dog_SpawnSpark と同じ
NAKED void DogLink_SpawnSpark(Vec3* pos) { INCFUNC("asm/func/DogLink_SpawnSpark.inc"); }

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
NAKED void DogLink_OnStealHit(Hitbox* a, Hitbox* b, DogLink* p) { INCFUNC("asm/func/DogLink_OnStealHit.inc"); }

// dog.c の Dog_OnHurt と同じ
NAKED void DogLink_OnHurt(Hitbox* a, Hitbox* b, DogLink* p) { INCFUNC("asm/func/DogLink_OnHurt.inc"); }

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
NAKED void DogLink_StateTurn(DogLink* p) { INCFUNC("asm/func/DogLink_StateTurn.inc"); }

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
NAKED void FUN_081c87c8(DogLink* p) { INCFUNC("asm/func/FUN_081c87c8.inc"); }

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
NAKED void FUN_081c8a24(DogLink* p) { INCFUNC("asm/func/FUN_081c8a24.inc"); }

// dog.c の Dog_StateFireBreathWindup の通信対戦版
NAKED void DogLink_StateFireBreathWindup(DogLink* p, s32 timer) { INCFUNC("asm/func/DogLink_StateFireBreathWindup.inc"); }

// dog.c の Dog_StateFireBreath と同じ
NAKED void DogLink_StateFireBreath(DogLink* p, s32 timer) { INCFUNC("asm/func/DogLink_StateFireBreath.inc"); }

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
NAKED void DogLink_StatePounce(DogLink* p) { INCFUNC("asm/func/DogLink_StatePounce.inc"); }

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
NAKED void DogLink_StateLookAround(DogLink* p, s32 timer) { INCFUNC("asm/func/DogLink_StateLookAround.inc"); }

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
NAKED void FUN_081ca258(DogLink* p) { INCFUNC("asm/func/FUN_081ca258.inc"); }

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
NAKED void FUN_081ca7f4(DogLink* p) { INCFUNC("asm/func/FUN_081ca7f4.inc"); }

// dog.c の FUN_0814fc7c と同じ
NAKED void FUN_081ca8cc(DogLink* p) { INCFUNC("asm/func/FUN_081ca8cc.inc"); }

// dog.c の FUN_081504e8 と同じ
void FUN_081cb138(DogLink* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ae038; }

// dog.c の FUN_08150534 の通信対戦版
NAKED void FUN_081cb148(DogLink* p) { INCFUNC("asm/func/FUN_081cb148.inc"); }

// dog.c の FUN_08150660 の通信対戦版
NAKED void FUN_081cb274(DogLink* p) { INCFUNC("asm/func/FUN_081cb274.inc"); }

// dog.c の FUN_0815077c と同じ
void FUN_081cb390(DogLink* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ae040; }

NAKED s32 FUN_081cb3a4(DogLink* p) { INCFUNC("asm/func/FUN_081cb3a4.inc"); }

// dog.c の FUN_08150510 の通信対戦版
NAKED s32 FUN_081cb3dc(DogLink* p) { INCFUNC("asm/func/FUN_081cb3dc.inc"); }

NAKED void FUN_081cb400(DogLink* p) { INCFUNC("asm/func/FUN_081cb400.inc"); }

// dog.c の FUN_08150b18 の通信対戦版
NAKED void FUN_081cb7e8(DogLink* p) { INCFUNC("asm/func/FUN_081cb7e8.inc"); }

// dog.c の FUN_08150de8 の通信対戦版
NAKED void FUN_081cbaa8(DogLink* p) { INCFUNC("asm/func/FUN_081cbaa8.inc"); }

// dog.c の FUN_081514f0 の通信対戦版
NAKED void FUN_081cc1a4(DogLink* p) { INCFUNC("asm/func/FUN_081cc1a4.inc"); }

// dog.c の FUN_081516d8 の通信対戦版
NAKED void FUN_081cc380(DogLink* p) { INCFUNC("asm/func/FUN_081cc380.inc"); }

// dog.c の FUN_081517a8 の通信対戦版
NAKED void FUN_081cc444(DogLink* p) { INCFUNC("asm/func/FUN_081cc444.inc"); }

// dog.c の FUN_081518ac と同じ
void FUN_081cc53c(DogLink* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ae048; }

// dog.c の Dog_OnDamaged の通信対戦版
NAKED bool8 DogLink_OnDamaged(DogLink* p) { INCFUNC("asm/func/DogLink_OnDamaged.inc"); }

// dog.c の Dog_StateDamaged の通信対戦版
NAKED void DogLink_StateDamaged(DogLink* p) { INCFUNC("asm/func/DogLink_StateDamaged.inc"); }

// dog.c の FUN_081518c0 と同じ
NAKED s32 FUN_081ce654(DogLink* p) { INCFUNC("asm/func/FUN_081ce654.inc"); }

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
NAKED s32 DogLink_Init(DogLink* p) { INCFUNC("asm/func/DogLink_Init.inc"); }

// dog.c の Dog_Create の通信対戦版
NAKED void DogLink_Create(void) { INCFUNC("asm/func/DogLink_Create.inc"); }
