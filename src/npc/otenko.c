#include "global.h"
#include "msgbus.h"
#include "npc.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

COMMON_DATA NPC* gOtenkoNPC = NULL;  // 0x03002C90, Cmd_BB34 が作ったおてんこの NPC, 破棄時に NULL

static inline void NPC_SetUnk1F0(NPC* npc, s32 a, s32 b) {
  npc->pathSpeed = a;
  npc->unk_1f2 = b;
  npc->unk_1f4 = a;
  npc->unk_1f8 = b;
}

// 向きを変え, 8 方向と 4 方向の向きも合わせる
static inline void NPC_SetAngle(NPC* npc, u32 angle) {
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  npc->unk_1b = npc->mover.angle;
}

NAKED void FUN_08204d2c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08204d2c.inc"); }

NAKED void FUN_08204d60(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08204d60.inc"); }

NAKED void FUN_08204d94(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08204d94.inc"); }

NAKED void FUN_08204dd8(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08204dd8.inc"); }

NAKED void FUN_08204e0c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08204e0c.inc"); }

void FUN_08204e40(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae83c[21])(NPCManager*, NPC*) = {
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
  PTR_ARRAY_085ae83c[npc->state](p, npc);
}

void FUN_08204e58(NPCManager* p, NPC* npc) { FUN_08204e40(p, npc); }

NAKED void FUN_08204e64(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08204e64.inc"); }

NAKED void FUN_08204f94(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08204f94.inc"); }

NAKED void FUN_08205018(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08205018.inc"); }

NAKED void FUN_082050fc(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082050fc.inc"); }

NAKED void FUN_08205178(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08205178.inc"); }

NAKED void FUN_08205438(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08205438.inc"); }

NAKED void FUN_0820556c(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820556c.inc"); }

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08205664(NPC* npc) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae890[19])(NPCManager*, NPC*, s32) = {
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

  NPCUpdate* fn;

  if (npc->unk_05 == 0 || npc->unk_05 > 19) {  // 本来は >= 19 と書くべきものと思われる...
    return 0;
  }

  fn = PTR_ARRAY_085ae890[npc->unk_05];
  npc->unk_06 = npc->unk_05;
  npc->unk_2cc = fn;
  npc->unk_10 = 0;
  npc->unk_09 = 1;
  npc->unk_18 = 0;
  return 1;
}

NAKED void FUN_082056a0(NPC* npc) { INCFUNC("asm/func/FUN_082056a0.inc"); }

NAKED s32 FUN_082058d8(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082058d8.inc"); }

NAKED s32 FUN_08205990(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08205990.inc"); }

NAKED s32 FUN_082059bc(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082059bc.inc"); }

s32 FUN_082059d8(NPCManager* p, NPC* npc) {
  FUN_08204e58(p, npc);
  return 0;
}

NAKED s32 FUN_082059e4(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082059e4.inc"); }

// 0xBB34, HashName("おてんこ"), おてんこの NPC を作って NPCManager に繋ぐ
void Cmd_BB34(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  NPC* npc;
  NPCOtenkoWork* work;

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

  npc = NPC_Alloc(id, kind);
  if (npc == NULL) {
    return;
  }
  gOtenkoNPC = npc;
  if (FUN_08040f0c(npc, id, &pos, angle) < 0) {
    return;
  }
  if (FUN_08040f48(npc, 1, SPRITE_OTENKO_00, ANIM_OTENKO, 0) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, Q8(1.563), 0);
  FUN_08040fc0(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_08205664);
  NPC_SetCb(npc, 0, FUN_082058d8);
  NPC_SetCb(npc, 1, FUN_082059d8);
  NPC_SetCb(npc, 2, FUN_082059e4);
  NPC_SetCb(npc, 3, FUN_08205990);
  NPC_SetOnDestroy(npc, FUN_082059bc);
  FUN_08040df4(p, npc, SPRITE_OTENKO_00, 0);
  NPCManager_LinkNPC(p, npc);
  FUN_08041e10(p, npc);
  work = &npc->work.otenko;
  npc->unk_0c = 0;
  work->unk_08 = 0;

  switch (VM_GetNamedArgValue('i', 0)) {
    case 0: {
      NPC_StartState(npc, 1);
      NPC_SetUpdate(npc, FUN_080421bc, 2);
      break;
    }
    case 1: {
      NPC_StartState(npc, 0);
      NPC_SetUpdate(npc, FUN_08042178, 1);
      SpriteHolder_SetFlags(&npc->sprite, SPRFLAG_HIDDEN);
      NPC_HideShadow(npc);
      break;
    }
    case 2: {
      npc->unk_217 = 1;
      NPC_StartState(npc, 18);
      NPC_SetUpdate(npc, FUN_08205178, 16);
      break;
    }
  }

  FUN_0804135c(npc, 0, 0, 0, 0, 0);
  NPC_SetUnk1F0(npc, 16, 20);
  npc->unk_1fc = 256;
  npc->unk_200 = 400;
}

// 0x8918, おてんこ ('.n' があればその NPC) を状態 16 に移し, '.p' で位置, '.d' で向きを入れる, '.w' が正ならプレイヤーの方を向かせる
void Cmd_8918(void) {
  NPC* npc;

  if (gOtenkoNPC == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    NPCManager* p = gNPCManager;

    if (p == NULL) {
      return;
    }
    npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (npc == NULL) {
      return;
    }
  } else {
    npc = gOtenkoNPC;
  }

  NPC_StartState(npc, 16);
  NPC_SetUpdate(npc, FUN_08205018, 14);

  if (VM_SeekToNamedArg('p')) {
    npc->mover.pos.x = VM_GetValue();
    npc->mover.pos.y = VM_GetValue();
    npc->mover.pos.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('d')) {
    NPC_SetAngle(npc, VM_GetValue());
  }
  if (VM_GetNamedArgValue('w', 0) > 0) {
    Player* player = gPlayerPtr[0];
    WorldPos* pos = &npc->mover.pos;

    NPC_SetAngle(npc, ArcTan2_8(player->mover.pos.x - pos->x, player->mover.pos.z - pos->z));
  }
}

// 0x6CBE, おてんこ ('.n' があればその NPC) を状態 17 に移して隠す
void Cmd_6CBE(void) {
  NPC* npc;

  if (gOtenkoNPC == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    NPCManager* p = gNPCManager;

    if (p == NULL) {
      return;
    }
    npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (npc == NULL) {
      return;
    }
  } else {
    npc = gOtenkoNPC;
  }

  NPC_StartState(npc, 17);
  NPC_SetUpdate(npc, FUN_082050fc, 15);
  SpriteHolder_SetFlags(&npc->sprite, SPRFLAG_HIDDEN);
  NPC_HideShadow(npc);
}

// 0x4EBF, おてんこ ('.n' があればその NPC) を状態 18 に移す
void Cmd_4EBF(void) {
  NPC* npc;

  if (gOtenkoNPC == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    NPCManager* p = gNPCManager;

    if (p == NULL) {
      return;
    }
    npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
    if (npc == NULL) {
      return;
    }
  } else {
    npc = gOtenkoNPC;
  }

  npc->unk_217 = 1;
  NPC_StartState(npc, 18);
  NPC_SetUpdate(npc, FUN_08205178, 16);
}

// 0x11D9
void Cmd_11D9(void) {
  if (gOtenkoNPC != NULL) {
    NPCOtenkoWork* work = &gOtenkoNPC->work.otenko;

    work->unk_08 = 1;
  }
}
