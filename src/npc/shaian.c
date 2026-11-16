#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_08205efc(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08205efc.inc"); }

NAKED void FUN_08205f38(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08205f38.inc"); }

NAKED void FUN_08205f74(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08205f74.inc"); }

void FUN_08205fb0(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae8dc[19])(NPCManager*, NPC*) = {
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
  PTR_ARRAY_085ae8dc[npc->state](p, npc);
}

void FUN_08205fc8(NPCManager* p, NPC* npc) { FUN_08205fb0(p, npc); }

s32 FUN_08205fd4(NPCManager* p, NPC* npc) {
  FUN_08205fc8(p, npc);
  return 0;
}

NAKED void FUN_08205fe0(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08205fe0.inc"); }

NAKED void FUN_0820602c(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820602c.inc"); }

NAKED void FUN_08206084(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08206084.inc"); }

// clang-format off
static void (*const PTR_ARRAY_085ae928[17])(NPCManager*, NPC*, s32) = {
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

NAKED s32 FUN_08206118(NPC* npc) { INCFUNC("asm/func/FUN_08206118.inc"); }

NAKED s32 FUN_08206154(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08206154.inc"); }

NAKED void FUN_08206188(NPC* npc) { INCFUNC("asm/func/FUN_08206188.inc"); }

NAKED void FUN_08206354(NPC* npc) { INCFUNC("asm/func/FUN_08206354.inc"); }

NAKED s32 FUN_082063ec(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082063ec.inc"); }

s32 FUN_0820640c(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  FUN_08206354(npc);
  return 0;
}

s32 FUN_08206424(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0x3004, シャイアンの NPC を作って NPCManager に繋ぐ
void Cmd_3004(void) {
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

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 1);
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
  if (FUN_08040f48(npc, 2, SPRITE_SHAIAN, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, Q8(1.875), 0);
  npc->unk_2b0 = npc->mover.pos;
  FUN_08040fc0(npc, &npc->unk_2b0, 2, 7, 48);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_08206118);
  NPC_SetCb(npc, 0, FUN_082063ec);
  NPC_SetCb(npc, 1, FUN_08205fd4);
  NPC_SetCb(npc, 2, FUN_08206154);
  NPC_SetCb(npc, 3, FUN_0820640c);
  NPC_SetOnDestroy(npc, FUN_08206424);
  FUN_08040df4(p, npc, SPRITE_SHAIAN, 0);
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
  }
}
