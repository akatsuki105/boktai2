#include "actor.h"
#include "global.h"
#include "msgbus.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

COMMON_DATA Actor* gOtenkoActor = NULL;  // 0x03002C90, Cmd_BB34 が作ったおてんこの Actor, 破棄時に NULL

static inline void Actor_SetUnk1F0(Actor* actor, s32 a, s32 b) {
  actor->unk_1f0 = a;
  actor->unk_1f2 = b;
  actor->unk_1f4 = a;
  actor->unk_1f8 = b;
}

// 向きを変え, 8 方向と 4 方向の向きも合わせる
static inline void Actor_SetAngle(Actor* actor, u32 angle) {
  actor->mover.angle = angle;
  actor->unk_1a = Angle_ToDir8(angle);
  actor->unk_19 = Angle_ToDir4(angle);
  actor->unk_1b = actor->mover.angle;
}

NAKED void FUN_08204d2c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08204d2c.inc"); }

NAKED void FUN_08204d60(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08204d60.inc"); }

NAKED void FUN_08204d94(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08204d94.inc"); }

NAKED void FUN_08204dd8(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08204dd8.inc"); }

NAKED void FUN_08204e0c(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08204e0c.inc"); }

void FUN_08204e40(ActorManager* p, Actor* actor) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae83c[21])(ActorManager*, Actor*) = {
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
      FUN_08204d2c,
      FUN_08204d60,
      FUN_08204d94,
      FUN_08204dd8,
      FUN_08204e0c,
  };  // 0x085AE83C
  // clang-format on
  PTR_ARRAY_085ae83c[actor->state](p, actor);
}

void FUN_08204e58(ActorManager* p, Actor* actor) { FUN_08204e40(p, actor); }

NAKED void FUN_08204e64(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08204e64.inc"); }

NAKED void FUN_08204f94(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08204f94.inc"); }

NAKED void FUN_08205018(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08205018.inc"); }

NAKED void FUN_082050fc(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_082050fc.inc"); }

NAKED void FUN_08205178(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08205178.inc"); }

NAKED void FUN_08205438(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08205438.inc"); }

NAKED void FUN_0820556c(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0820556c.inc"); }

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08205664(Actor* actor) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae890[19])(ActorManager*, Actor*, s32) = {
      NULL,
      FUN_08042178,
      FUN_080421bc,
      FUN_08204e64,
      FUN_08204f94,
      FUN_08042414,
      FUN_08042638,
      FUN_08042868,
      FUN_080428b8,
      FUN_08042a48,
      FUN_08042cf0,
      FUN_08042d50,
      FUN_08042f34,
      FUN_08043108,
      FUN_08205018,
      FUN_082050fc,
      FUN_08205178,
      FUN_08205438,
      FUN_0820556c,
  };  // 0x085AE890
  // clang-format on

  ActorUpdate* fn;

  if (actor->unk_05 == 0 || actor->unk_05 > 19) {  // 本来は >= 19 と書くべきものと思われる...
    return 0;
  }

  fn = PTR_ARRAY_085ae890[actor->unk_05];
  actor->unk_06 = actor->unk_05;
  actor->unk_2cc = fn;
  actor->unk_10 = 0;
  actor->unk_09 = 1;
  actor->unk_18 = 0;
  return 1;
}

NAKED void FUN_082056a0(Actor* actor) { INCFUNC("asm/func/FUN_082056a0.inc"); }

NAKED s32 FUN_082058d8(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082058d8.inc"); }

NAKED s32 FUN_08205990(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08205990.inc"); }

NAKED s32 FUN_082059bc(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082059bc.inc"); }

s32 FUN_082059d8(ActorManager* p, Actor* actor) {
  FUN_08204e58(p, actor);
  return 0;
}

NAKED s32 FUN_082059e4(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_082059e4.inc"); }

// 0xBB34, HashName("おてんこ"), おてんこの Actor を作って ActorManager に繋ぐ
void Cmd_BB34(void) {
  ActorManager* p = gActorManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  Actor* actor;
  ActorOtenkoWork* work;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 13);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);

  actor = Actor_Alloc(id, kind);
  if (actor == NULL) {
    return;
  }
  gOtenkoActor = actor;
  if (FUN_08040f0c(actor, id, &pos, angle) < 0) {
    return;
  }
  if (FUN_08040f48(actor, 1, SPRITE_OTENKO_00, ANIM_OTENKO, 0) < 0) {
    return;
  }

  Mover_SetUnk30(&actor->mover, 0, Q8(1.563), 0);
  FUN_08040fc0(actor, actor->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&actor->mq, id, 5);
  actor->mover.angle = angle;
  actor->unk_1a = Angle_ToDir8(angle);
  actor->unk_19 = Angle_ToDir4(angle);
  Actor_SetFn(actor, FUN_08205664);
  Actor_SetCb(actor, 0, FUN_082058d8);
  Actor_SetCb(actor, 1, FUN_082059d8);
  Actor_SetCb(actor, 2, FUN_082059e4);
  Actor_SetCb(actor, 3, FUN_08205990);
  Actor_SetOnDestroy(actor, FUN_082059bc);
  FUN_08040df4(p, actor, SPRITE_OTENKO_00, 0);
  ActorManager_LinkActor(p, actor);
  FUN_08041e10(p, actor);
  work = &actor->work.otenko;
  actor->unk_0c = 0;
  work->unk_08 = 0;

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
      Actor_StartState(actor, 18);
      Actor_SetUpdate(actor, FUN_08205178, 16);
      break;
    }
  }

  FUN_0804135c(actor, 0, 0, 0, 0, 0);
  Actor_SetUnk1F0(actor, 16, 20);
  actor->unk_1fc = 256;
  actor->unk_200 = 400;
}

// 0x8918, おてんこ ('.n' があればその Actor) を状態 16 に移し, '.p' で位置, '.d' で向きを入れる, '.w' が正ならプレイヤーの方を向かせる
void Cmd_8918(void) {
  Actor* actor;

  if (gOtenkoActor == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    ActorManager* p = gActorManager;

    if (p == NULL) {
      return;
    }
    actor = ActorManager_FindActorByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (actor == NULL) {
      return;
    }
  } else {
    actor = gOtenkoActor;
  }

  Actor_StartState(actor, 16);
  Actor_SetUpdate(actor, FUN_08205018, 14);

  if (VM_SeekToNamedArg('p')) {
    actor->mover.pos.x = VM_GetValue();
    actor->mover.pos.y = VM_GetValue();
    actor->mover.pos.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('d')) {
    Actor_SetAngle(actor, VM_GetValue());
  }
  if (VM_GetNamedArgValue('w', 0) > 0) {
    Player* player = gPlayerPtr[0];
    WorldPos* pos = &actor->mover.pos;

    Actor_SetAngle(actor, ArcTan2_8(player->mover.pos.x - pos->x, player->mover.pos.z - pos->z));
  }
}

// 0x6CBE, おてんこ ('.n' があればその Actor) を状態 17 に移して隠す
void Cmd_6CBE(void) {
  Actor* actor;

  if (gOtenkoActor == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    ActorManager* p = gActorManager;

    if (p == NULL) {
      return;
    }
    actor = ActorManager_FindActorByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (actor == NULL) {
      return;
    }
  } else {
    actor = gOtenkoActor;
  }

  Actor_StartState(actor, 17);
  Actor_SetUpdate(actor, FUN_082050fc, 15);
  SpriteHolder_SetFlags(&actor->sprite, SPRFLAG_HIDDEN);
  Actor_HideShadow(actor);
}

// 0x4EBF, おてんこ ('.n' があればその Actor) を状態 18 に移す
void Cmd_4EBF(void) {
  Actor* actor;

  if (gOtenkoActor == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    ActorManager* p = gActorManager;

    if (p == NULL) {
      return;
    }
    actor = ActorManager_FindActorByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (actor == NULL) {
      return;
    }
  } else {
    actor = gOtenkoActor;
  }

  actor->unk_217 = 1;
  Actor_StartState(actor, 18);
  Actor_SetUpdate(actor, FUN_08205178, 16);
}

// 0x11D9
void Cmd_11D9(void) {
  if (gOtenkoActor != NULL) {
    ActorOtenkoWork* work = &gOtenkoActor->work.otenko;

    work->unk_08 = 1;
  }
}
