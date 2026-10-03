#include "camera.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "msgbus.h"
#include "registry.h"
#include "save.h"
#include "sound.h"
#include "sprite_main.h"
#include "video.h"
#include "vm.h"

// Entity0823acbc は 他のEntity と違って Entity0823acbc_Create と Entity0823acbc_Init を持たない
typedef struct {
  Entity e;  // ENTITY_UNK_1
  s32 unk_18;
  s32 unk_1c;
} Entity0823acbc;
static_assert(sizeof(Entity0823acbc) == 32);

IWRAM_DATA Entity0823acbc gEntity0823acbc = {};        // 0x030016A0
IWRAM_DATA SystemSaveData gSystemSaveDataBuffer = {};  // 0x030016C0

u32 FUN_082321e0(u8* pc);
void FUN_0822d0e4(void);

static inline void DisableEntityFlags(u32 flags) { gEntityDisableFlags |= flags; }
static inline void EnableEntityFlags(u32 flags) { gEntityDisableFlags &= ~flags; }

NAKED s32 FUN_0823a6c0(void) { INCFUNC("asm/func/FUN_0823a6c0.inc"); }

// 通信カートリッジの応答を待つ, 応答があれば 1、待ち時間を使い切ったら -1
s32 FUN_0823a6fc(void) {
  if (rfu_REQBN_softReset_and_checkID() == RFU_ID) {
    return 1;
  }
  if (gVBlankCount > 449) {
    return -1;
  }
  return 0;
}

NAKED void FUN_0823a730(unknown* p, u32 param_2, u32 param_3, u16 param_4, u32 param_5, unknown* param_6, unknown* param_7) { INCFUNC("asm/func/FUN_0823a730.inc"); }

void FUN_0823a76c(u8* p) {
  CpuFill32(0, p, 516);
  p[0] = 1;
}

NAKED bool32 FUN_0823a790(unknown* p, unknown* src) { INCFUNC("asm/func/FUN_0823a790.inc"); }

NAKED bool32 FUN_0823a7d8(unknown* p, unknown* dst) { INCFUNC("asm/func/FUN_0823a7d8.inc"); }

// デモ表から demoID/step/idx のメッセージを1件引く (どの段でも NULL に当たったら終端)
EntityMsg* DemoTable_GetMsg(s32 demoID, s32 step, s32 idx) {
  const EntityMsg* const* const* demo;
  const EntityMsg* const* stp;

  demo = gDemoTable[demoID];
  if (demo != NULL) {
    stp = demo[step];
    if (stp != NULL) {
      return (EntityMsg*)stp[idx];
    }
  }
  return NULL;
}

void FUN_0823a870(void) { gSystemSaveData = &gSystemSaveDataBuffer; }

s32 FUN_0823a880(u8* pc, ScriptArgs* args) { return VM_ExecByPointer(pc, args); }

s32 FUN_0823a88c(u8* pc, ScriptArgs* args) { return VM_ExecByPointer(pc, args); }

static s32 FUN_0823a898(u32 scriptID, ScriptArgs* args) { return VM_ExecByID(scriptID, args); }

s32 VM_ExecById_Proxy_0823a8a4(u32 scriptID, ScriptArgs* args) { return VM_ExecByID(scriptID, args); }

NAKED bool32 FUN_0823a8b0(void) { INCFUNC("asm/func/FUN_0823a8b0.inc"); }

void FUN_0823a8f4(u32 val) {
  if (val == 0) {
    u32_03004798 = 320;
  } else {
    SoftReset_0823a928();
  }
}

void FUN_0823a910(void) { bool32_03004788 = TRUE; }

void FUN_0823a91c(void) { bool32_03004788 = FALSE; }

void Save_BackupStatAndWorld(void);
void FUN_0823cd04(void);
bool32 Map_ResetCollisionMap(void);
void* HitboxManager_Create(void);

NAKED s32 SoftReset_0823a928(void) { INCFUNC("asm/func/SoftReset_0823a928.inc"); }

static inline void ShowBG(u32 bits) { gStagedDISPCNT |= bits; }

void FUN_0823a9c4(void) {
  gObjBlendEnabled = 0;
  vram_0822b778();
  FUN_0823cd04();
  Map_ResetCollisionMap();
  HitboxManager_Create();
  ShowBG(DISPCNT_BG0_ON);
}

void FUN_0823a9f4(void) {
  FUN_0824082c();
  EnableEntityFlags(ENTITY_DISABLE_1);
}

static inline u32 TestFlag030047a4(u32 flags) { return (gFlag030047a4 | u32_030047a0) & flags; }

void FUN_0823aa10(void) {
  if (!TestFlag030047a4(FLAG030047A4_UNK_0)) {
    FUN_082407e0();
    DisableEntityFlags(ENTITY_DISABLE_1);
  }
}

// 他の停止フラグが立っていなければ、gEntityDisableFlags の bit1 による停止を切り替える
void FUN_0823aa44(void) {
  if (!(gEntityDisableFlags & ~ENTITY_DISABLE_1)) {
    if (!(gEntityDisableFlags & ENTITY_DISABLE_1)) {
      FUN_0823aa10();
    } else {
      FUN_0823a9f4();
    }
  }
}

void FUN_0823aa70(void) {}

void FUN_0823aa74(void) {
  Registry_Sweep(FALSE);
  FUN_0822d0e4();
}

void FUN_0823aa84(void) {
  MoverList_ClearPtr();
  Camera_0823b744();
}

NAKED s32 Entity0823acbc_Update(Entity0823acbc* p) { INCFUNC("asm/func/Entity0823acbc_Update.inc"); }

s32 Entity0823acbc_Destroy(Entity0823acbc* _) {}

NAKED void FUN_0823acbc(void) { INCFUNC("asm/func/FUN_0823acbc.inc"); }

s32 FUN_0823ad98(void) {
  u8* pc = VM_GetPC();

  if (pc == NULL) {
    Save_BackupStatAndWorld();
  } else {
    while (*pc != 0) {
      pc = FUN_08232160(pc);
    }
  }

  return 0;
}

u32 FUN_0823adc0(void) { return FUN_082321e0(VM_GetPC()); }

NAKED bool32 FUN_0823add0(void) { INCFUNC("asm/func/FUN_0823add0.inc"); }

NON_MATCH bool32 UNUSED FUN_0823ae14(Entity0823acbc* p) {
#ifdef NONMATCHING_C
  u32_03004798 = 0;
  p->unk_1c = 0;
  FUN_0823a9c4();
  VM_ClearScratchpad_Proxy();

  if (gMapInitScriptID != 0) {
    VM_ExecByID(gMapInitScriptID, NULL);
  }

  if (gMapInitScriptID == 0) {
    VM_ExecSpecial();
  }

  return TRUE;
#else
  INCFUNC("asm/func/FUN_0823ae14.inc");
#endif
}
