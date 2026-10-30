#include "actor.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_0820bf5c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820bf5c.inc"); }

void FUN_0820bf88(ActorManager* p, Actor* actor) {
  static void (*const PTR_ARRAY_085aef34[17])(ActorManager*, Actor*) = {
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
      FUN_0820bf5c,
  };  // 0x085AEF34
  PTR_ARRAY_085aef34[actor->state](p, actor);
}

void FUN_0820bfa0(ActorManager* p, Actor* actor) { FUN_0820bf88(p, actor); }

s32 FUN_0820bfac(ActorManager* p, Actor* actor) {
  FUN_0820bfa0(p, actor);
  return 0;
}

NAKED void FUN_0820bfb8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820bfb8.inc"); }

NAKED void FUN_0820c014(Actor* actor) { INCFUNC("asm/func/FUN_0820c014.inc"); }

NAKED void FUN_0820c034(Actor* actor) { INCFUNC("asm/func/FUN_0820c034.inc"); }

NAKED void FUN_0820c054(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820c054.inc"); }

void (*const PTR_ARRAY_085aef78[15])(ActorManager*, Actor*, s32) = {
    NULL,
    FUN_08042178,
    FUN_0820bfb8,
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
    FUN_0820c054,
};  // 0x085AEF78

NAKED s32 FUN_0820c1a4(Actor* actor) { INCFUNC("asm/func/FUN_0820c1a4.inc"); }

NAKED s32 FUN_0820c1e0(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820c1e0.inc"); }

NAKED void FUN_0820c214(Actor* actor) { INCFUNC("asm/func/FUN_0820c214.inc"); }

NAKED s32 FUN_0820c3a4(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820c3a4.inc"); }

s32 FUN_0820c3c4(ActorManager* p, Actor* actor) {
  FUN_080412fc(p, actor);
  return 0;
}

s32 FUN_0820c3d0(ActorManager* p, Actor* actor) { return MsgQueue_Unregister(&actor->mq); }

// 0x56AD, ロックマンの Actor を作って ActorManager に繋ぐ
void Cmd_56AD(void) {
  ActorManager* p = gActorManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  Actor* actor;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);  // 0xB548, HashName("ロックマン")
  kind = VM_GetNamedArgValue('k', 15);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  spriteID = SPRITE_MEGAMAN;
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

  Mover_SetUnk30(&actor->mover, 0, 400, 0);
  FUN_08040fc0(actor, actor->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&actor->mq, id, 5);
  actor->mover.angle = angle;
  actor->unk_1a = Angle_ToDir8(angle);
  actor->unk_19 = Angle_ToDir4(angle);
  Actor_SetFn(actor, FUN_0820c1a4);
  Actor_SetCb(actor, 0, FUN_0820c3a4);
  Actor_SetCb(actor, 1, FUN_0820bfac);
  Actor_SetCb(actor, 2, FUN_0820c1e0);
  Actor_SetCb(actor, 3, FUN_0820c3c4);
  Actor_SetOnDestroy(actor, FUN_0820c3d0);
  FUN_08040df4(p, actor, spriteID, 0);
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
