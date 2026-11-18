#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

// エンニオ(時計塔の管理者NPC)でのみ利用

void FUN_0820a710(NPCManager* p, NPC* npc) {
  static void (*const PTR_ARRAY_085aed94[16])(NPCManager*, NPC*) = {
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
  };  // 0x085AED94
  PTR_ARRAY_085aed94[npc->state](p, npc);
}

void FUN_0820a728(NPCManager* p, NPC* npc) { FUN_0820a710(p, npc); }

s32 FUN_0820a734(NPCManager* p, NPC* npc) {
  FUN_0820a728(p, npc);
  return 0;
}

// clang-format off
void (*const PTR_ARRAY_085aedd4[14])(NPCManager*, NPC*, s32) = {
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
};  // 0x085AEDD4
// clang-format on

NAKED s32 FUN_0820a740(NPC* npc) { INCFUNC("asm/func/FUN_0820a740.inc"); }

NAKED s32 FUN_0820a77c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820a77c.inc"); }

NAKED void FUN_0820a7b0(NPC* npc) { INCFUNC("asm/func/FUN_0820a7b0.inc"); }

NAKED s32 FUN_0820a8fc(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820a8fc.inc"); }

s32 FUN_0820a91c(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_0820a928(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0x3F96, エンニオ の NPC を作って NPCManager に繋ぐ
void Cmd_3F96(void) {
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

  id = VM_GetNamedArgValue('n', 0);  // 0x2023, HashName("エンニオ")
  kind = VM_GetNamedArgValue('k', 10);
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
  if (FUN_08040f48(npc, 2, SPR_ENNIO_LUIS, 0, flags) < 0) {
    return;
  }

  Mover_SetUnk30(&npc->mover, 0, 350, 0);
  FUN_08040fc0(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_0820a740);
  NPC_SetCb(npc, 0, FUN_0820a8fc);
  NPC_SetCb(npc, 1, FUN_0820a734);
  NPC_SetCb(npc, 2, FUN_0820a77c);
  NPC_SetCb(npc, 3, FUN_0820a91c);
  NPC_SetOnDestroy(npc, FUN_0820a928);
  FUN_08040df4(p, npc, SPR_ENNIO_LUIS, 0);
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
