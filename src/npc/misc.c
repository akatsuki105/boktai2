#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "npc.h"
#include "sprite.h"
#include "vm.h"

void (*const PTR_ARRAY_085aefb4[15])(NPCManager*, NPC*, s32) = {
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
    FUN_08043360,
};  // 0x085AEFB4

NAKED s32 FUN_0820c658(NPC* npc) { INCFUNC("asm/func/FUN_0820c658.inc"); }

NAKED s32 FUN_0820c694(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820c694.inc"); }

NAKED void FUN_0820c6c8(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820c6c8.inc"); }

void (*const PTR_ARRAY_085aeff0[17])(NPCManager*, NPC*) = {
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
    FUN_0820c6c8,
};  // 0x085AEFF0

void FUN_0820c704(NPCManager* p, NPC* npc) { PTR_ARRAY_085aeff0[npc->state](p, npc); }

void FUN_0820c71c(NPCManager* p, NPC* npc) { FUN_0820c704(p, npc); }

s32 FUN_0820c728(NPCManager* p, NPC* npc) {
  FUN_0820c71c(p, npc);
  return 0;
}

NAKED void FUN_0820c734(NPC* npc) { INCFUNC("asm/func/FUN_0820c734.inc"); }

NAKED s32 FUN_0820c904(NPCManager* p, NPC* npc) { INCFUNC("asm/func/FUN_0820c904.inc"); }

s32 FUN_0820c924(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_0820c930(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0x8EA3, ルイス, マルチェロ, ハテナ (共通点として、昼は外に立っていて、雨になると自宅に駆け込み、夜になると徒歩で自宅に帰る)
void Cmd_8EA3(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  Vec3 pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  s32 idx;
  NPC* npc;

  if (p == NULL) {
    return;
  }

  // 0x7E5F, HashName("ルイス")
  // 0xCB6B, HashName("マルチェロ")
  // 0x04B1, HashName("ハテナ")
  id = VM_GetNamedArgValue('n', 0);

  kind = VM_GetNamedArgValue('k', 14);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  spriteID = VM_GetNamedArgValue('c', SPRITE_SMITH_MARCELLO);
  flags = 0;
  idx = 1;

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
  NPC_SetFn(npc, FUN_0820c658);
  NPC_SetCb(npc, 0, FUN_0820c904);
  NPC_SetCb(npc, 1, FUN_0820c728);
  NPC_SetCb(npc, 2, FUN_0820c694);
  NPC_SetCb(npc, 3, FUN_0820c924);
  NPC_SetOnDestroy(npc, FUN_0820c930);
  FUN_08040df4(p, npc, spriteID, idx);
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
