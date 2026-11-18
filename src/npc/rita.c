#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_082066c8(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082066c8.inc"); }

NAKED void FUN_082066f0(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082066f0.inc"); }

NAKED void FUN_08206718(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08206718.inc"); }

NAKED void FUN_0820673c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820673c.inc"); }

NAKED void FUN_08206764(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08206764.inc"); }

NAKED void FUN_0820678c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820678c.inc"); }

NAKED void FUN_082067c0(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082067c0.inc"); }

void FUN_08206898(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae96c[23])(NPCManager*, NPC*) = {
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
  PTR_ARRAY_085ae96c[npc->state](p, npc);
}

void FUN_082068b0(NPCManager* p, NPC* npc) { FUN_08206898(p, npc); }

s32 FUN_082068bc(NPCManager* p, NPC* npc) {
  FUN_082068b0(p, npc);
  return 0;
}

NAKED void FUN_082068c8(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082068c8.inc"); }

NAKED void FUN_08206918(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08206918.inc"); }

NAKED void FUN_08206968(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08206968.inc"); }

NAKED void FUN_082069b8(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082069b8.inc"); }

NAKED void FUN_08206a08(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08206a08.inc"); }

NAKED void FUN_08206a7c(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08206a7c.inc"); }

NAKED void FUN_08206ad4(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08206ad4.inc"); }

// clang-format off
void (*const PTR_ARRAY_085ae9c8[21])(NPCManager*, NPC*, s32) = {
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

NAKED s32 FUN_08206b0c(NPC* npc) { INCFUNC("asm/func/FUN_08206b0c.inc"); }

NAKED s32 FUN_08206b48(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08206b48.inc"); }

NAKED void FUN_08206b7c(NPC* npc) { INCFUNC("asm/func/FUN_08206b7c.inc"); }

NAKED s32 FUN_08206d8c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08206d8c.inc"); }

s32 FUN_08206dac(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_08206db8(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0xC347, リタの NPC を作って NPCManager に繋ぐ
void Cmd_C347(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  NPC* npc;
  NPCRitaWork* work;

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
  spriteID = SPR_RITA;
  flags = 0;

  npc = NPC_Alloc(id, kind);
  if (npc == NULL) {
    return;
  }
  if (FUN_08040f0c(npc, id, &pos, angle) < 0) {
    return;
  }
  if (FUN_08040f48(npc, 2, spriteID, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, Q8(1.37), 0);
  FUN_08040fc0(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_08206b0c);
  NPC_SetCb(npc, 0, FUN_08206d8c);
  NPC_SetCb(npc, 1, FUN_082068bc);
  NPC_SetCb(npc, 2, FUN_08206b48);
  NPC_SetCb(npc, 3, FUN_08206dac);
  NPC_SetOnDestroy(npc, FUN_08206db8);
  FUN_08040df4(p, npc, spriteID, 0);
  NPCManager_LinkNPC(p, npc);
  FUN_08041e10(p, npc);
  work = &npc->work.rita;
  work->unk_04 = 0;

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
      npc->unk_217 = 1;
      work->unk_04 = 1;
      NPC_StartState(npc, 22);
      NPC_SetUpdate(npc, FUN_08042868, 7);
      break;
    }
    case 4: {
      NPC_StartState(npc, 18);
      NPC_SetUpdate(npc, FUN_08206ad4, 17);
      break;
    }
  }
}

// 0x8894, '.n' の NPC (リタ) を状態 22 に移す
void Cmd_8894(void) {
  NPCManager* p = gNPCManager;
  NPC* npc;
  NPCRitaWork* work;

  if (p == NULL) {
    return;
  }

  npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (npc == NULL) {
    return;
  }

  work = &npc->work.rita;
  npc->unk_217 = 1;
  NPC_StartState(npc, 22);
  NPC_SetUpdate(npc, FUN_08042868, 7);
  work->unk_04 = 1;
}
