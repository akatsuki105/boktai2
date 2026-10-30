#include "actor.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_0820b5c4(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820b5c4.inc"); }

NAKED void FUN_0820b5f8(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820b5f8.inc"); }

NAKED void FUN_0820b62c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820b62c.inc"); }

NAKED void FUN_0820b650(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820b650.inc"); }

NAKED void FUN_0820b678(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820b678.inc"); }

void FUN_0820b6b4(ActorManager* p, Actor* actor) {
  // clang-format off
  static void (*const PTR_ARRAY_085aeea4[19])(ActorManager*, Actor*) = {
      FUN_0804355c,
      FUN_08043588,
      FUN_080435b4,
      FUN_080435f0,
      FUN_0820b5c4,
      FUN_0820b5f8,
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
      FUN_0820b62c,
      FUN_0820b650,
      FUN_0820b678,
  };  // 0x085AEEA4
  // clang-format on
  PTR_ARRAY_085aeea4[actor->state](p, actor);
}

void FUN_0820b6cc(ActorManager* p, Actor* actor) { FUN_0820b6b4(p, actor); }

s32 FUN_0820b6d8(ActorManager* p, Actor* actor) {
  FUN_0820b6cc(p, actor);
  return 0;
}

NAKED void FUN_0820b6e4(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820b6e4.inc"); }

NAKED void FUN_0820b7c4(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820b7c4.inc"); }

NAKED void FUN_0820b8a0(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820b8a0.inc"); }

NAKED void FUN_0820b934(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820b934.inc"); }

NAKED void FUN_0820b9e8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820b9e8.inc"); }

// clang-format off
void (*const PTR_ARRAY_085aeef0[17])(ActorManager*, Actor*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_0820b6e4,
    FUN_0820b7c4,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_0820b8a0,
    FUN_0820b934,
    FUN_0820b9e8,
};  // 0x085AEEF0
// clang-format on

NAKED s32 FUN_0820ba38(Actor* actor) { INCFUNC("asm/func/FUN_0820ba38.inc"); }

NAKED s32 FUN_0820ba74(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820ba74.inc"); }

NAKED void FUN_0820baa8(Actor* actor) { INCFUNC("asm/func/FUN_0820baa8.inc"); }

NAKED s32 FUN_0820bc90(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820bc90.inc"); }

s32 FUN_0820bcb0(ActorManager* p, Actor* actor) {
  FUN_080412fc(p, actor);
  return 0;
}

s32 FUN_0820bcbc(ActorManager* p, Actor* actor) { return MsgQueue_Unregister(&actor->mq); }

// 0xD229, ダーインの Actor を作って ActorManager に繋ぐ
void Cmd_D229(void) {
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

  id = VM_GetNamedArgValue('n', 0);  // 0x7901, HashName("ダーイン")
  kind = VM_GetNamedArgValue('k', 12);
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
  if (FUN_08040f48(actor, 2, SPRITE_DAINN, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&actor->mover, 0, 400, 0);
  FUN_08040fc0(actor, actor->sprite.pos, 2, 7, 32);
  MsgQueue_Register(&actor->mq, id, 5);
  actor->mover.angle = angle;
  actor->unk_1a = Angle_ToDir8(angle);
  actor->unk_19 = Angle_ToDir4(angle);
  Actor_SetFn(actor, FUN_0820ba38);
  Actor_SetCb(actor, 0, FUN_0820bc90);
  Actor_SetCb(actor, 1, FUN_0820b6d8);
  Actor_SetCb(actor, 2, FUN_0820ba74);
  Actor_SetCb(actor, 3, FUN_0820bcb0);
  Actor_SetOnDestroy(actor, FUN_0820bcbc);
  FUN_08040df4(p, actor, SPRITE_DAINN, 0);
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
