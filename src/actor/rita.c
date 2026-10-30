#include "actor.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_082066c8(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082066c8.inc"); }

NAKED void FUN_082066f0(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082066f0.inc"); }

NAKED void FUN_08206718(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08206718.inc"); }

NAKED void FUN_0820673c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820673c.inc"); }

NAKED void FUN_08206764(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08206764.inc"); }

NAKED void FUN_0820678c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820678c.inc"); }

NAKED void FUN_082067c0(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082067c0.inc"); }

void FUN_08206898(ActorManager* p, Actor* actor) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae96c[23])(ActorManager*, Actor*) = {
      FUN_0804355c,
      FUN_08043588,
      FUN_080435b4,
      FUN_080435f0,
      FUN_0804364c,
      FUN_08043688,
      FUN_080436c4,
      FUN_08043774,
      FUN_08043960,
      FUN_08043a24,
      FUN_08043bcc,
      FUN_08043c94,
      FUN_08043cc4,
      FUN_08043cf4,
      FUN_08043da8,
      FUN_08043e54,
      FUN_082066c8,
      FUN_082066f0,
      FUN_08206718,
      FUN_0820673c,
      FUN_08206764,
      FUN_0820678c,
      FUN_082067c0,
  };  // 0x085AE96C
  // clang-format on
  PTR_ARRAY_085ae96c[actor->state](p, actor);
}

void FUN_082068b0(ActorManager* p, Actor* actor) { FUN_08206898(p, actor); }

s32 FUN_082068bc(ActorManager* p, Actor* actor) {
  FUN_082068b0(p, actor);
  return 0;
}

NAKED void FUN_082068c8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_082068c8.inc"); }

NAKED void FUN_08206918(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08206918.inc"); }

NAKED void FUN_08206968(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08206968.inc"); }

NAKED void FUN_082069b8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_082069b8.inc"); }

NAKED void FUN_08206a08(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08206a08.inc"); }

NAKED void FUN_08206a7c(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08206a7c.inc"); }

NAKED void FUN_08206ad4(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08206ad4.inc"); }

// clang-format off
void (*const PTR_ARRAY_085ae9c8[21])(ActorManager*, Actor*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_082068c8,
    FUN_08206918,
    FUN_08206968,
    FUN_08206ad4,
    FUN_082069b8,
    FUN_08206a08,
    FUN_08206a7c,
};  // 0x085AE9C8
// clang-format on

NAKED s32 FUN_08206b0c(Actor* actor) { INCFUNC("asm/func/FUN_08206b0c.inc"); }

NAKED s32 FUN_08206b48(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08206b48.inc"); }

NAKED void FUN_08206b7c(Actor* actor) { INCFUNC("asm/func/FUN_08206b7c.inc"); }

NAKED s32 FUN_08206d8c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08206d8c.inc"); }

s32 FUN_08206dac(ActorManager* p, Actor* actor) {
  FUN_080412fc(p, actor);
  return 0;
}

s32 FUN_08206db8(ActorManager* p, Actor* actor) { return MsgQueue_Unregister(&actor->mq); }

// 0xC347, リタの Actor を作って ActorManager に繋ぐ
void Cmd_C347(void) {
  ActorManager* p = gActorManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  Actor* actor;
  ActorRitaWork* work;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 2);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  spriteID = SPRITE_RITA;
  flags = 0;

  actor = Actor_Alloc(id, kind);
  if (actor == NULL) {
    return;
  }
  if (FUN_08040f0c(actor, id, &pos, angle) < 0) {
    return;
  }
  if (FUN_08040f48(actor, 2, spriteID, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&actor->mover, 0, Q8(1.37), 0);
  FUN_08040fc0(actor, actor->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&actor->mq, id, 5);
  actor->mover.angle = angle;
  actor->unk_1a = Angle_ToDir8(angle);
  actor->unk_19 = Angle_ToDir4(angle);
  Actor_SetFn(actor, FUN_08206b0c);
  Actor_SetCb(actor, 0, FUN_08206d8c);
  Actor_SetCb(actor, 1, FUN_082068bc);
  Actor_SetCb(actor, 2, FUN_08206b48);
  Actor_SetCb(actor, 3, FUN_08206dac);
  Actor_SetOnDestroy(actor, FUN_08206db8);
  FUN_08040df4(p, actor, spriteID, 0);
  ActorManager_LinkActor(p, actor);
  FUN_08041e10(p, actor);
  work = &actor->work.rita;
  work->unk_04 = 0;

  switch (VM_GetNamedArgValue('i', 0)) {
    case 0: {
      Actor_StartState(actor, 1);
      Actor_SetUpdate(actor, FUN_080421bc, 2);
      break;
    }
    case 1: {
      Actor_StartState(actor, 0);
      Actor_SetUpdate(actor, FUN_08042178, 1);
      SpriteHolder_SetFlags(&actor->sprite, SPRFLAG_HIDDEN);
      Actor_HideShadow(actor);
      break;
    }
    case 2: {
      actor->unk_217 = 1;
      if (actor->unk_1ef >= 0) {
        Actor_StartState(actor, FUN_08043510(actor));
        Actor_SetUpdate(actor, FUN_080421bc, 2);
      } else {
        Actor_StartState(actor, 6);
        Actor_SetUpdate(actor, FUN_08042868, 7);
      }
      break;
    }
    case 3: {
      actor->unk_217 = 1;
      work->unk_04 = 1;
      Actor_StartState(actor, 22);
      Actor_SetUpdate(actor, FUN_08042868, 7);
      break;
    }
    case 4: {
      Actor_StartState(actor, 18);
      Actor_SetUpdate(actor, FUN_08206ad4, 17);
      break;
    }
  }
}

// 0x8894, '.n' の Actor (リタ) を状態 22 に移す
void Cmd_8894(void) {
  ActorManager* p = gActorManager;
  Actor* actor;
  ActorRitaWork* work;

  if (p == NULL) {
    return;
  }

  actor = ActorManager_FindActorByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (actor == NULL) {
    return;
  }

  work = &actor->work.rita;
  actor->unk_217 = 1;
  Actor_StartState(actor, 22);
  Actor_SetUpdate(actor, FUN_08042868, 7);
  work->unk_04 = 1;
}
