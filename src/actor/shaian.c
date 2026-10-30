#include "actor.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_08205efc(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08205efc.inc"); }

NAKED void FUN_08205f38(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08205f38.inc"); }

NAKED void FUN_08205f74(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08205f74.inc"); }

void FUN_08205fb0(ActorManager* p, Actor* actor) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae8dc[19])(ActorManager*, Actor*) = {
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
      FUN_08205efc,
      FUN_08205f38,
      FUN_08205f74,
  };  // 0x085AE8DC
  // clang-format on
  PTR_ARRAY_085ae8dc[actor->state](p, actor);
}

void FUN_08205fc8(ActorManager* p, Actor* actor) { FUN_08205fb0(p, actor); }

s32 FUN_08205fd4(ActorManager* p, Actor* actor) {
  FUN_08205fc8(p, actor);
  return 0;
}

NAKED void FUN_08205fe0(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08205fe0.inc"); }

NAKED void FUN_0820602c(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820602c.inc"); }

NAKED void FUN_08206084(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08206084.inc"); }

// clang-format off
static void (*const PTR_ARRAY_085ae928[17])(ActorManager*, Actor*, s32) = {
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
    FUN_08205fe0,
    FUN_0820602c,
    FUN_08206084,
};  // 0x085AE928
// clang-format on

NAKED s32 FUN_08206118(Actor* actor) { INCFUNC("asm/func/FUN_08206118.inc"); }

NAKED s32 FUN_08206154(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08206154.inc"); }

NAKED void FUN_08206188(Actor* actor) { INCFUNC("asm/func/FUN_08206188.inc"); }

NAKED void FUN_08206354(Actor* actor) { INCFUNC("asm/func/FUN_08206354.inc"); }

NAKED s32 FUN_082063ec(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082063ec.inc"); }

s32 FUN_0820640c(ActorManager* p, Actor* actor) {
  FUN_080412fc(p, actor);
  FUN_08206354(actor);
  return 0;
}

s32 FUN_08206424(ActorManager* p, Actor* actor) { return MsgQueue_Unregister(&actor->mq); }

// 0x3004, シャイアンの Actor を作って ActorManager に繋ぐ
void Cmd_3004(void) {
  ActorManager* p = gActorManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteFlags flags;
  Actor* actor;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 1);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  flags = 0;

  actor = Actor_Alloc(id, kind);
  if (actor == NULL) {
    return;
  }
  if (FUN_08040f0c(actor, id, &pos, angle) < 0) {
    return;
  }
  if (FUN_08040f48(actor, 2, SPRITE_SHAIAN, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&actor->mover, 0, Q8(1.875), 0);
  actor->unk_2b0 = actor->mover.pos;
  FUN_08040fc0(actor, &actor->unk_2b0, 2, 7, 48);
  MsgQueue_Register(&actor->mq, id, 5);
  actor->mover.angle = angle;
  actor->unk_1a = Angle_ToDir8(angle);
  actor->unk_19 = Angle_ToDir4(angle);
  Actor_SetFn(actor, FUN_08206118);
  Actor_SetCb(actor, 0, FUN_082063ec);
  Actor_SetCb(actor, 1, FUN_08205fd4);
  Actor_SetCb(actor, 2, FUN_08206154);
  Actor_SetCb(actor, 3, FUN_0820640c);
  Actor_SetOnDestroy(actor, FUN_08206424);
  FUN_08040df4(p, actor, SPRITE_SHAIAN, 0);
  ActorManager_LinkActor(p, actor);
  FUN_08041e10(p, actor);

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
  }
}
