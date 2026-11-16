#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_08207120(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08207120.inc"); }

NAKED void FUN_08207170(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08207170.inc"); }

NAKED void FUN_082071c0(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082071c0.inc"); }

NAKED void FUN_08207210(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08207210.inc"); }

NAKED void FUN_08207298(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_08207298.inc"); }

NAKED void FUN_082072f0(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_082072f0.inc"); }

NAKED void FUN_0820738c(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820738c.inc"); }

// clang-format off
void (*const PTR_ARRAY_085aea1c[21])(NPCManager*, NPC*, s32) = {
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
    FUN_08207120,
    FUN_08207170,
    FUN_082071c0,
    FUN_08207210,
    FUN_08207298,
    FUN_082072f0,
    FUN_0820738c,
};  // 0x085AEA1C
// clang-format on

NAKED s32 FUN_082073dc(NPC* npc) { INCFUNC("asm/func/FUN_082073dc.inc"); }

NAKED s32 FUN_08207418(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08207418.inc"); }

NAKED void FUN_0820744c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820744c.inc"); }

NAKED void FUN_08207474(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08207474.inc"); }

NAKED void FUN_082074a8(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082074a8.inc"); }

NAKED void FUN_082074d0(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082074d0.inc"); }

NAKED void FUN_082074f8(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082074f8.inc"); }

NAKED void FUN_0820752c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820752c.inc"); }

NAKED void FUN_08207550(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_08207550.inc"); }

void FUN_08207578(NPCManager* p, NPC* npc) {
  // clang-format off
  static void (*const PTR_ARRAY_085aea70[23])(NPCManager*, NPC*) = {
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
      FUN_0820744c,
      FUN_08207474,
      FUN_082074a8,
      FUN_082074d0,
      FUN_082074f8,
      FUN_0820752c,
      FUN_08207550,
  };  // 0x085AEA70
  // clang-format on
  PTR_ARRAY_085aea70[npc->state](p, npc);
}

void FUN_08207590(NPCManager* p, NPC* npc) { FUN_08207578(p, npc); }

s32 FUN_0820759c(NPCManager* p, NPC* npc) {
  FUN_08207590(p, npc);
  return 0;
}

NAKED void FUN_082075a8(NPC* npc) { INCFUNC("asm/func/FUN_082075a8.inc"); }

NAKED s32 FUN_082077bc(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_082077bc.inc"); }

s32 FUN_082077dc(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_082077e8(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0xF33F, ザジの NPC を作って NPCManager に繋ぐ
void Cmd_F33F(void) {
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
  kind = VM_GetNamedArgValue('k', 3);
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
  if (FUN_08040f48(npc, 2, SPRITE_ZAJI, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, 350, 0);
  FUN_08040fc0(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_082073dc);
  NPC_SetCb(npc, 0, FUN_082077bc);
  NPC_SetCb(npc, 1, FUN_0820759c);
  NPC_SetCb(npc, 2, FUN_08207418);
  NPC_SetCb(npc, 3, FUN_082077dc);
  NPC_SetOnDestroy(npc, FUN_082077e8);
  FUN_08040df4(p, npc, SPRITE_ZAJI, 0);
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
      NPC_StartState(npc, 21);
      NPC_SetUpdate(npc, FUN_082072f0, 19);
      break;
    }
  }
}
