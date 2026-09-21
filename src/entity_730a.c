#include "camera.h"
#include "entity.h"
#include "global.h"
#include "msgbus.h"

typedef struct {
  Entity e;                // ENTITY_UNK_3
  EntityMsgBox msgbox;     // 0x18
  u8 unk_4c[0x50 - 0x4C];  // 0x4C
  s32 unk_50;              // 0x50, FUN_0802284c が EntityMsg.args[0] を入れ、Entity730A_Update が毎フレーム減らす
  s32 unk_54;              // 0x54, FUN_0802284c が EntityMsg.args[1] を入れ、Entity730A_Update が FUN_0823b9cc に渡す
} Entity730A;
static_assert(sizeof(Entity730A) == 88);

Entity2UnkData* FUN_0823b2d0(u16 id);
void FUN_08019814(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void MapPltt_PushCommand(s32 val, s32 count, u32* args);
void FUN_08002800(s32 val, s32 count, s32* args);
void RingoDemoAnim_Create(Vec3* pos, EntityMsgBox* box);

void FUN_08022668(Entity730A* p, EntityMsgBox* node, EntityMsg* data) {
  Vec3 pos;

  pos.x = data->args[0];
  pos.y = data->args[1];
  pos.z = data->args[2];
  FUN_08019814(&pos, data->args[3], data->args[4], data->args[5], data->args[6]);
}

void FUN_080226a8(Entity730A* p, EntityMsgBox* node, EntityMsg* data) {
  Vec3 pos;
  Entity2UnkData* target = FUN_0823b2d0(data->args[0]);

  if (target != NULL) {
    pos.x = target->pos.x;
    pos.y = target->pos.y;
    pos.z = target->pos.z;
    FUN_08019814(&pos, data->args[1], data->args[2], data->args[3], data->args[4]);
  }
}

NON_MATCH void FUN_08022704(Entity730A* p, EntityMsgBox* node, EntityMsg* data) {
#ifdef NONMATCHING_C
  s16* args = data->args;
  u32 flags = 0;
  s32 kind;

  if (args[5] != 0) {
    flags = 0xFFF;
  }
  if (args[6] != 0) {
    flags |= 0x1000;
  }
  if (args[7] != 0) {
    flags |= 0xE000;
  }
  kind = 3;
  if (data->args[0] == 0) {
    kind = 2;
  }
  FUN_0823ce68(kind, args[1], args[2], args[3], args[4], flags, args[8]);
#else
  INCFUNC("asm/func/FUN_08022704.inc");
#endif
}

NON_MATCH void FUN_08022770(Entity730A* p, EntityMsgBox* node, EntityMsg* data) {
#ifdef NONMATCHING_C
  s16* args = data->args;
  u32 cmd[5];
  u32 flags = 0;
  s32 kind;

  if (args[5] != 0) {
    flags = 0xFFF;
  }
  if (args[6] != 0) {
    flags |= 0x1000;
  }
  if (args[7] != 0) {
    flags |= 0xE000;
  }
  cmd[0] = args[1];
  cmd[1] = args[2];
  cmd[2] = args[3];
  cmd[3] = args[4];
  cmd[4] = flags;
  if ((cmd[1] == 0) && (cmd[2] == 0) && (cmd[3] == 0)) {
    cmd[1] = 4;
    cmd[2] = 4;
    cmd[3] = 4;
  }
  kind = 3;
  if (args[0] == 0) {
    kind = 2;
  }
  MapPltt_PushCommand(kind, 5, cmd);
#else
  INCFUNC("asm/func/FUN_08022770.inc");
#endif
}

NON_MATCH void FUN_080227f4(Entity730A* p, EntityMsgBox* node, EntityMsg* data) {
#ifdef NONMATCHING_C
  s16* args = data->args;
  s32 cmd[5];
  s32 kind;

  cmd[0] = args[1];
  cmd[1] = args[2];
  cmd[2] = args[3];
  cmd[3] = args[4];
  cmd[4] = args[8];
  if ((cmd[1] == 0) && (cmd[2] == 0) && (cmd[3] == 0)) {
    cmd[1] = 4;
    cmd[2] = 4;
    cmd[3] = 4;
  }
  kind = 2;
  if (args[0] == 0) {
    kind = 1;
  }
  FUN_08002800(kind, 5, cmd);
#else
  INCFUNC("asm/func/FUN_080227f4.inc");
#endif
}

void FUN_0802284c(Entity730A* p, EntityMsgBox* node, EntityMsg* data) {
  p->unk_50 = data->args[0];
  p->unk_54 = data->args[1];
}

void FUN_0802285c(Entity730A* p, EntityMsgBox* node, EntityMsg* data) {
  p->unk_50 = 0;
  p->unk_54 = 0;
}

// 溜まったメッセージを cmd ごとのハンドラへ配る
NON_MATCH s32 Entity730A_Update_Helper_08022864(Entity730A* p) {
#ifdef NONMATCHING_C
  EntityMsgBox* box = &p->msgbox;
  EntityMsg* data;
  Vec3 pos;
  s32 i;

  for (i = 0; i < box->count[gEntityMsgBus->bufIdx]; i++) {
    data = box->msgs[gEntityMsgBus->bufIdx][i];
    EntityMsgBox_BeginWait(box, data);
    switch (data->cmd) {
      case 0: {
        FUN_08022668(p, box, data);
        break;
      }
      case 1: {
        FUN_080226a8(p, box, data);
        break;
      }
      case 2: {
        FUN_08022704(p, box, data);
        break;
      }
      case 3: {
        FUN_08022770(p, box, data);
        break;
      }
      case 4: {
        FUN_080227f4(p, box, data);
        break;
      }
      case 5: {
        FUN_0802284c(p, box, data);
        break;
      }
      case 6: {
        FUN_0802285c(p, box, data);
        break;
      }
      case 7: {
        pos.x = data->args[0];
        pos.y = data->args[1];
        pos.z = data->args[2];
        RingoDemoAnim_Create(&pos, box);
      }
      default: {
        continue;
      }
    }
    EntityMsgBox_EndWait(box, 1);
  }
  return 0;
#else
  INCFUNC("asm/func/Entity730A_Update_Helper_08022864.inc");
#endif
}

s32 Entity730A_Update(Entity730A* p) {
  Entity730A_Update_Helper_08022864(p);
  if (p->unk_50 != 0) {
    if (p->unk_50 > 0) {
      p->unk_50--;
    }
    FUN_0823b9cc(p->unk_54);
  }
  return 0;
}

s32 Entity730A_Destroy(Entity730A* p) {
  EntityMsgBus_Unregister(&p->msgbox);
  return 0;
}

s32 Entity730A_Init(Entity730A* p, u32 param) {
  EntityMsgBus_Register(&p->msgbox, param, 7);
  return 0;
}

Entity730A* Entity730A_Create(u32 param) {
  Entity730A* p = CreateEntity(ENTITY_UNK_3, sizeof(Entity730A));

  if (p != NULL) {
    SetEntityRoutine(p, Entity730A_Update, Entity730A_Destroy);
    if (Entity730A_Init(p, param) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
