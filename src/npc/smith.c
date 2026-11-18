#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_0820abc8(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820abc8.inc"); }

NAKED void FUN_0820abec(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820abec.inc"); }

NAKED void FUN_0820ac10(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820ac10.inc"); }

NAKED void FUN_0820ac44(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820ac44.inc"); }

void FUN_0820ac80(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const PTR_ARRAY_085aee0c[20])(NPCManager*, NPC*) = {
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
      FUN_0820abc8,
      FUN_0820abec,
      FUN_0820ac10,
      FUN_0820ac44,
  };  // 0x085AEE0C
  // clang-format on
  PTR_ARRAY_085aee0c[npc->state](p, npc);
}

void FUN_0820ac98(NPCManager* p, NPC* npc) { FUN_0820ac80(p, npc); }

s32 FUN_0820aca4(NPCManager* p, NPC* npc) {
  FUN_0820ac98(p, npc);
  return 0;
}

NAKED void FUN_0820acb0(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820acb0.inc"); }

NAKED void FUN_0820afb0(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820afb0.inc"); }

NAKED void FUN_0820aff0(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820aff0.inc"); }

// clang-format off
void (*const PTR_ARRAY_085aee5c[18])(NPCManager*, NPC*, s32) = {
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
    FUN_0820acb0,
    FUN_0820afb0,
    FUN_0820aff0,
    FUN_08043360,
};  // 0x085AEE5C
// clang-format on

NAKED s32 FUN_0820b044(NPC* npc) { INCFUNC("asm/func/FUN_0820b044.inc"); }

NAKED s32 FUN_0820b080(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820b080.inc"); }

NAKED void FUN_0820b0b4(NPC* npc) { INCFUNC("asm/func/FUN_0820b0b4.inc"); }

NAKED s32 FUN_0820b2bc(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820b2bc.inc"); }

s32 FUN_0820b2dc(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_0820b2e8(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0xCE28, スミス の NPC を作って NPCManager に繋ぐ
void Cmd_CE28(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteFlags flags;
  NPC* npc;

  if (p == NULL) {
    return;
  }

  // 0x6740, HashName("スミス"), ストーリーイベント用
  // 0x77E5, ハッシュ不明, 通常のスミス
  id = VM_GetNamedArgValue('n', 0);

  kind = VM_GetNamedArgValue('k', 11);
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
  if (FUN_08040f48(npc, 2, SPR_SMITH_MARCELLO, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, 450, 0);
  FUN_08040fc0(npc, npc->sprite.pos, 2, 7, 32);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_0820b044);
  NPC_SetCb(npc, 0, FUN_0820b2bc);
  NPC_SetCb(npc, 1, FUN_0820aca4);
  NPC_SetCb(npc, 2, FUN_0820b080);
  NPC_SetCb(npc, 3, FUN_0820b2dc);
  NPC_SetOnDestroy(npc, FUN_0820b2e8);
  FUN_08040df4(p, npc, SPR_SMITH_MARCELLO, 0);
  NPCManager_LinkNPC(p, npc);
  FUN_08041e10(p, npc);

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
      NPC_StartState(npc, 17);
      NPC_SetUpdate(npc, FUN_0820afb0, 15);
      break;
    }
  }
}
