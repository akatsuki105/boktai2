#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_08208160(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08208160.inc"); }

NAKED void FUN_08208194(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08208194.inc"); }

NAKED void FUN_082081c0(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082081c0.inc"); }

NAKED void FUN_082081ec(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082081ec.inc"); }

NAKED void FUN_08208214(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08208214.inc"); }

NAKED void FUN_08208240(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08208240.inc"); }

NAKED void FUN_08208274(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08208274.inc"); }

NAKED void FUN_0820829c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820829c.inc"); }

NAKED void FUN_082082c0(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082082c0.inc"); }

NAKED void FUN_082082f4(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082082f4.inc"); }

// clang-format off
void (*const PTR_ARRAY_085aeb5c[26])(NPCManager*, NPC*) = {
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

void FUN_08208320(NPCManager* p, NPC* npc) { PTR_ARRAY_085aeb5c[npc->state](p, npc); }

void FUN_08208338(NPCManager* p, NPC* npc) { FUN_08208320(p, npc); }

s32 FUN_08208344(NPCManager* p, NPC* npc) {
  FUN_08208338(p, npc);
  return 0;
}

static rgb555 rgb555_ARRAY_03000228[16];  // 0x03000228

NAKED void FUN_08208350(NPC* npc, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08208350.inc"); }

NAKED void FUN_08208458(NPC* npc, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08208458.inc"); }

NAKED void FUN_0820848c(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820848c.inc"); }

NAKED void FUN_082084ec(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082084ec.inc"); }

NAKED void FUN_08208628(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208628.inc"); }

NAKED void FUN_082086d8(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082086d8.inc"); }

NAKED void FUN_08208808(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208808.inc"); }

NAKED void FUN_08208858(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208858.inc"); }

NAKED void FUN_082088a8(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082088a8.inc"); }

NAKED void FUN_082088f8(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082088f8.inc"); }

NAKED void FUN_08208990(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208990.inc"); }

NAKED void FUN_08208b50(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208b50.inc"); }

NAKED void FUN_08208c64(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208c64.inc"); }

NAKED void FUN_08208ce8(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208ce8.inc"); }

NAKED void FUN_08208e18(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208e18.inc"); }

NAKED void FUN_08208ec8(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08208ec8.inc"); }

// clang-format off
void (*const PTR_ARRAY_085aebc4[24])(NPCManager*, NPC*, s32) = {
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

NAKED s32 FUN_08209134(NPC* npc) { INCFUNC("asm/func/FUN_08209134.inc"); }

NAKED s32 FUN_0820919c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820919c.inc"); }

NAKED void FUN_082091f0(NPC* npc) { INCFUNC("asm/func/FUN_082091f0.inc"); }

NAKED s32 FUN_082094f8(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082094f8.inc"); }

s32 FUN_08209518(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_08209524(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// クロの NPC を作って NPCManager に繋ぐ, param_1 は work.kuro.unk_00 に入る
void FUN_08209534(s32 param_1) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteFlags flags;
  NPC* npc;
  NPCKuroWork* work;

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

  npc = NPC_Alloc(id, kind);
  if (npc == NULL) {
    return;
  }
  if (FUN_08040f0c(npc, id, &pos, angle) < 0) {
    return;
  }
  if (FUN_08040f48(npc, 2, SPRITE_KURO, 0, flags) < 0) {
    return;
  }

  work = &npc->work.kuro;
  work->unk_00 = param_1;
  work->unk_16 = 0;
  work->unk_18 = 0;
  work->unk_1c = 0;
  Mover_SetUnk30(&npc->mover, 0, 200, 0);
  FUN_08040fc0(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_08209134);
  NPC_SetCb(npc, 0, FUN_082094f8);
  NPC_SetCb(npc, 1, FUN_08208344);
  NPC_SetCb(npc, 2, FUN_0820919c);
  NPC_SetCb(npc, 3, FUN_08209518);
  NPC_SetOnDestroy(npc, FUN_08209524);
  npc->unk_1b = angle;
  FUN_08040df4(p, npc, SPRITE_KURO, 0);
  NPCManager_LinkNPC(p, npc);
  FUN_08041e10(p, npc);

  switch (VM_GetNamedArgValue('i', 0)) {
    case 0: {
      NPC_StartState(npc, 1);
      NPC_SetUpdate(npc, FUN_0820848c, 2);
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
      if (npc->pathIdx >= 0) {
        NPC_StartState(npc, FUN_08043510(npc));
        NPC_SetUpdate(npc, FUN_080421bc, 2);
      } else {
        NPC_StartState(npc, 6);
        NPC_SetUpdate(npc, FUN_08042868, 7);
      }
      break;
    }
    case 3: {
      NPC_StartState(npc, 20);
      NPC_SetUpdate(npc, FUN_082088f8, 18);
      break;
    }
  }
}

// 0xD774
void Cmd_D774(void) { FUN_08209534(0); }

// 0x82C8
void Cmd_82C8(void) { FUN_08209534(1); }

// 0x9DFE, '.n' の NPC を状態 25 に移す
void Cmd_9DFE(void) {
  NPCManager* p = gNPCManager;
  NPC* npc;

  if (p == NULL) {
    return;
  }

  npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (npc == NULL) {
    return;
  }

  npc->unk_217 = 1;
  NPC_StartState(npc, 25);
}
