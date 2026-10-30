#include "actor.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_08208160(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08208160.inc"); }

NAKED void FUN_08208194(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08208194.inc"); }

NAKED void FUN_082081c0(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082081c0.inc"); }

NAKED void FUN_082081ec(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082081ec.inc"); }

NAKED void FUN_08208214(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08208214.inc"); }

NAKED void FUN_08208240(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08208240.inc"); }

NAKED void FUN_08208274(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08208274.inc"); }

NAKED void FUN_0820829c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820829c.inc"); }

NAKED void FUN_082082c0(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082082c0.inc"); }

NAKED void FUN_082082f4(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082082f4.inc"); }

// clang-format off
void (*const PTR_ARRAY_085aeb5c[26])(ActorManager*, Actor*) = {
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
    FUN_08208160,
    FUN_08208194,
    FUN_082081c0,
    FUN_082081ec,
    FUN_08208214,
    FUN_08208240,
    FUN_08208274,
    FUN_0820829c,
    FUN_082082c0,
    FUN_082082f4,
};  // 0x085AEB5C
// clang-format on

void FUN_08208320(ActorManager* p, Actor* actor) { PTR_ARRAY_085aeb5c[actor->state](p, actor); }

void FUN_08208338(ActorManager* p, Actor* actor) { FUN_08208320(p, actor); }

s32 FUN_08208344(ActorManager* p, Actor* actor) {
  FUN_08208338(p, actor);
  return 0;
}

static rgb555 rgb555_ARRAY_03000228[16];  // 0x03000228

NAKED void FUN_08208350(Actor* actor, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08208350.inc"); }

NAKED void FUN_08208458(Actor* actor, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08208458.inc"); }

NAKED void FUN_0820848c(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820848c.inc"); }

NAKED void FUN_082084ec(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_082084ec.inc"); }

NAKED void FUN_08208628(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208628.inc"); }

NAKED void FUN_082086d8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_082086d8.inc"); }

NAKED void FUN_08208808(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208808.inc"); }

NAKED void FUN_08208858(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208858.inc"); }

NAKED void FUN_082088a8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_082088a8.inc"); }

NAKED void FUN_082088f8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_082088f8.inc"); }

NAKED void FUN_08208990(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208990.inc"); }

NAKED void FUN_08208b50(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208b50.inc"); }

NAKED void FUN_08208c64(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208c64.inc"); }

NAKED void FUN_08208ce8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208ce8.inc"); }

NAKED void FUN_08208e18(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208e18.inc"); }

NAKED void FUN_08208ec8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08208ec8.inc"); }

// clang-format off
void (*const PTR_ARRAY_085aebc4[24])(ActorManager*, Actor*, s32) = {
    NULL,
    FUN_08042178,
    FUN_0820848c,
    FUN_082084ec,
    FUN_08208628,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08208ec8,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_082086d8,
    FUN_08208808,
    FUN_08208858,
    FUN_082088a8,
    FUN_082088f8,
    FUN_08208990,
    FUN_08208b50,
    FUN_08208c64,
    FUN_08208ce8,
    FUN_08208e18,
};  // 0x085AEBC4
// clang-format on

NAKED s32 FUN_08209134(Actor* actor) { INCFUNC("asm/func/FUN_08209134.inc"); }

NAKED s32 FUN_0820919c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_0820919c.inc"); }

NAKED void FUN_082091f0(Actor* actor) { INCFUNC("asm/func/FUN_082091f0.inc"); }

NAKED s32 FUN_082094f8(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082094f8.inc"); }

s32 FUN_08209518(ActorManager* p, Actor* actor) {
  FUN_080412fc(p, actor);
  return 0;
}

s32 FUN_08209524(ActorManager* p, Actor* actor) { return MsgQueue_Unregister(&actor->mq); }

// クロの Actor を作って ActorManager に繋ぐ, param_1 は work.kuro.unk_00 に入る
void FUN_08209534(s32 param_1) {
  ActorManager* p = gActorManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteFlags flags;
  Actor* actor;
  ActorKuroWork* work;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 5);
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
  if (FUN_08040f48(actor, 2, SPRITE_KURO, 0, flags) < 0) {
    return;
  }

  work = &actor->work.kuro;
  work->unk_00 = param_1;
  work->unk_16 = 0;
  work->unk_18 = 0;
  work->unk_1c = 0;
  Mover_SetUnk30(&actor->mover, 0, 200, 0);
  FUN_08040fc0(actor, actor->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&actor->mq, id, 5);
  actor->mover.angle = angle;
  actor->unk_1a = Angle_ToDir8(angle);
  actor->unk_19 = Angle_ToDir4(angle);
  Actor_SetFn(actor, FUN_08209134);
  Actor_SetCb(actor, 0, FUN_082094f8);
  Actor_SetCb(actor, 1, FUN_08208344);
  Actor_SetCb(actor, 2, FUN_0820919c);
  Actor_SetCb(actor, 3, FUN_08209518);
  Actor_SetOnDestroy(actor, FUN_08209524);
  actor->unk_1b = angle;
  FUN_08040df4(p, actor, SPRITE_KURO, 0);
  ActorManager_LinkActor(p, actor);
  FUN_08041e10(p, actor);

  switch (VM_GetNamedArgValue('i', 0)) {
    case 0: {
      Actor_StartState(actor, 1);
      Actor_SetUpdate(actor, FUN_0820848c, 2);
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
      Actor_StartState(actor, 20);
      Actor_SetUpdate(actor, FUN_082088f8, 18);
      break;
    }
  }
}

// 0xD774
void Cmd_D774(void) { FUN_08209534(0); }

// 0x82C8
void Cmd_82C8(void) { FUN_08209534(1); }

// 0x9DFE, '.n' の Actor を状態 25 に移す
void Cmd_9DFE(void) {
  ActorManager* p = gActorManager;
  Actor* actor;

  if (p == NULL) {
    return;
  }

  actor = ActorManager_FindActorByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (actor == NULL) {
    return;
  }

  actor->unk_217 = 1;
  Actor_StartState(actor, 25);
}
