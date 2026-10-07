#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "sound.h"

typedef struct {
  Entity e;                // 0x0, ENTITY_UNK_11
  u8 unk_18[0x1C - 0x18];  // 0x18
  EntityMsgBox msgbox;     // 0x1C, EntityD3A9_Init が EntityMsgBus_Register に渡す
} EntityD3A9;
static_assert(sizeof(EntityD3A9) == 80);

void FUN_080c0ae4(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  PlaySound_082406e0(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0b00(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  PlaySound_08240718(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0b1c(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  sound_08240264(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0b38(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  Sound_FadeInBGM(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0b54(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  Sound_FadeOutBGMTemporarily(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0b70(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  Sound_FadeOutBGM(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0b8c(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  FUN_082404b0(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0ba8(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  FUN_082404fc(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0bc4(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  FUN_08240568(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

void FUN_080c0be0(EntityD3A9* p, EntityMsgBox* node, EntityMsg* msg) {
  FUN_082405c0(msg->args[0]);
  EntityMsgBox_EndWait(node, 1);
}

NAKED void* EntityD3A9_Update_Internal(EntityD3A9* p) { INCFUNC("asm/func/EntityD3A9_Update_Internal.inc"); }

s32 EntityD3A9_Update(EntityD3A9* p) {
  EntityD3A9_Update_Internal(p);
  return 0;
}

s32 EntityD3A9_Destroy(EntityD3A9* _) { return 0; }

s32 EntityD3A9_Init(EntityD3A9* p, u32 n) {
  EntityMsgBus_Register(&p->msgbox, n, 8);
  return 0;
}

// 0xD3A9
EntityD3A9* EntityD3A9_Create(u32 n) {
  EntityD3A9* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityD3A9));

  if (p != NULL) {
    SetEntityRoutine(p, EntityD3A9_Update, EntityD3A9_Destroy);
    if (EntityD3A9_Init(p, n) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
