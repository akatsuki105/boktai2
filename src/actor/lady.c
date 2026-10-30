#include "actor.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "sprite.h"
#include "vm.h"

void FUN_08209da0(ActorManager* p, Actor* actor) {
  static void (*const PTR_ARRAY_085aeca4[16])(ActorManager*, Actor*) = {
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
  };  // 0x085AECA4
  PTR_ARRAY_085aeca4[actor->state](p, actor);
}

void FUN_08209db8(ActorManager* p, Actor* actor) { FUN_08209da0(p, actor); }

s32 FUN_08209dc4(ActorManager* p, Actor* actor) {
  FUN_08209db8(p, actor);
  return 0;
}

void (*const PTR_ARRAY_085aece4[14])(ActorManager*, Actor*, s32) = {
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
};  // 0x085AECE4

NAKED s32 FUN_08209dd0(Actor* actor) { INCFUNC("asm/func/FUN_08209dd0.inc"); }

NAKED s32 FUN_08209e0c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08209e0c.inc"); }

NAKED void FUN_08209e40(Actor* actor) { INCFUNC("asm/func/FUN_08209e40.inc"); }

NAKED s32 FUN_08209f8c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08209f8c.inc"); }

s32 FUN_08209fac(ActorManager* p, Actor* actor) {
  FUN_080412fc(p, actor);
  return 0;
}

s32 FUN_08209fb8(ActorManager* p, Actor* actor) { return MsgQueue_Unregister(&actor->mq); }

// 0x5470, レディの Actor を作って ActorManager に繋ぐ
void Cmd_5470(void) {
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
  kind = VM_GetNamedArgValue('k', 8);
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
  if (FUN_08040f48(actor, 2, SPRITE_LADY, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&actor->mover, 0, 400, 0);
  FUN_08040fc0(actor, actor->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&actor->mq, id, 5);
  actor->mover.angle = angle;
  actor->unk_1a = Angle_ToDir8(angle);
  actor->unk_19 = Angle_ToDir4(angle);
  Actor_SetFn(actor, FUN_08209dd0);
  Actor_SetCb(actor, 0, FUN_08209f8c);
  Actor_SetCb(actor, 1, FUN_08209dc4);
  Actor_SetCb(actor, 2, FUN_08209e0c);
  Actor_SetCb(actor, 3, FUN_08209fac);
  Actor_SetOnDestroy(actor, FUN_08209fb8);
  FUN_08040df4(p, actor, SPRITE_LADY, 0);
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
