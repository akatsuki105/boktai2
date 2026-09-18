#include "camera.h"
#include "global.h"
#include "msgbus.h"
#include "sound.h"
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

void FUN_0822d0e4(void);
void FUN_08230dc4(bool32 val);
void FUN_0823b1ec(void);

NAKED s32 FUN_0823a6c0(void) { INCFUNC("asm/func/FUN_0823a6c0.inc"); }

NAKED s32 FUN_0823a6fc(void) { INCFUNC("asm/func/FUN_0823a6fc.inc"); }

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

s32 FUN_0823a880(u8* pc, ScriptArgs* args) { return Script_ExecByPointer(pc, args); }

s32 FUN_0823a88c(u8* pc, ScriptArgs* args) { return Script_ExecByPointer(pc, args); }

static s32 FUN_0823a898(u32 scriptID, ScriptArgs* args) { return Script_ExecById(scriptID, args); }

s32 Script_ExecById_Proxy_0823a8a4(u32 scriptID, ScriptArgs* args) { return Script_ExecById(scriptID, args); }

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

NAKED s32 SoftReset_0823a928(void) { INCFUNC("asm/func/SoftReset_0823a928.inc"); }

NAKED void FUN_0823a9c4(void) { INCFUNC("asm/func/FUN_0823a9c4.inc"); }

static inline void EnableEntityFlags(u32 flags) { gEntityDisableFlags &= ~flags; }

static inline void DisableEntityFlags(u32 flags) { gEntityDisableFlags |= flags; }

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
  FUN_08230dc4(FALSE);
  FUN_0822d0e4();
}

void FUN_0823aa84(void) {
  FUN_0823b1ec();
  Camera_0823b744();
}

NAKED s32 Entity0823acbc_Update(Entity0823acbc* p) { INCFUNC("asm/func/Entity0823acbc_Update.inc"); }

s32 Entity0823acbc_Destroy(Entity0823acbc* _) {}

NAKED void FUN_0823acbc(void) { INCFUNC("asm/func/FUN_0823acbc.inc"); }

NAKED s32 FUN_0823ad98(void) { INCFUNC("asm/func/FUN_0823ad98.inc"); }

NAKED unknown* FUN_0823adc0(void) { INCFUNC("asm/func/FUN_0823adc0.inc"); }

NAKED bool32 FUN_0823add0(void) { INCFUNC("asm/func/FUN_0823add0.inc"); }

NAKED bool32 UNUSED FUN_0823ae14(unknown* p) { INCFUNC("asm/func/FUN_0823ae14.inc"); }
