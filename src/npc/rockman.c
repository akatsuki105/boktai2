#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

NAKED void FUN_0820bf5c(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820bf5c.inc"); }

void FUN_0820bf88(NPCManager* p, NPC* npc) {
  static void (*const PTR_ARRAY_085aef34[17])(NPCManager*, NPC*) = {
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
  PTR_ARRAY_085aef34[npc->state](p, npc);
}

void FUN_0820bfa0(NPCManager* p, NPC* npc) { FUN_0820bf88(p, npc); }

s32 FUN_0820bfac(NPCManager* p, NPC* npc) {
  FUN_0820bfa0(p, npc);
  return 0;
}

NAKED void FUN_0820bfb8(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820bfb8.inc"); }

NAKED void FUN_0820c014(NPC* npc) { INCFUNC("asm/func/FUN_0820c014.inc"); }

NAKED void FUN_0820c034(NPC* npc) { INCFUNC("asm/func/FUN_0820c034.inc"); }

NAKED void FUN_0820c054(NPCManager* p, NPC* npc, s32 elapsed) { INCFUNC("asm/func/FUN_0820c054.inc"); }

void (*const PTR_ARRAY_085aef78[15])(NPCManager*, NPC*, s32) = {
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

NAKED s32 FUN_0820c1a4(NPC* npc) { INCFUNC("asm/func/FUN_0820c1a4.inc"); }

NAKED s32 FUN_0820c1e0(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820c1e0.inc"); }

NAKED void FUN_0820c214(NPC* npc) { INCFUNC("asm/func/FUN_0820c214.inc"); }

NAKED s32 FUN_0820c3a4(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820c3a4.inc"); }

s32 FUN_0820c3c4(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_0820c3d0(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0x56AD, ロックマンの NPC を作って NPCManager に繋ぐ
void Cmd_56AD(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  NPC* npc;

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
  spriteID = SPR_MEGAMAN;
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

  Mover_SetUnk30(&npc->mover, 0, 400, 0);
  FUN_08040fc0(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_0820c1a4);
  NPC_SetCb(npc, 0, FUN_0820c3a4);
  NPC_SetCb(npc, 1, FUN_0820bfac);
  NPC_SetCb(npc, 2, FUN_0820c1e0);
  NPC_SetCb(npc, 3, FUN_0820c3c4);
  NPC_SetOnDestroy(npc, FUN_0820c3d0);
  FUN_08040df4(p, npc, spriteID, 0);
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
