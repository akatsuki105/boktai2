#include "camera.h"
#include "eeprom.h"
#include "entity_9a9f.h"
#include "global.h"
#include "hitbox.h"
#include "input.h"
#include "link.h"
#include "mover.h"
#include "msgbus.h"
#include "random.h"
#include "registry.h"
#include "save.h"
#include "solar_sensor.h"
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

IWRAM_DATA Entity0823acbc gEntity0823acbc = {};  // 0x030016A0

IWRAM_DATA SystemSaveData gSystemSaveDataBuffer = {};  // 0x030016C0

extern struct LinkConnect* gLinkConnect;  // 0x03002C64

extern bool32 gDispcntLocked;                     // 0x03002CA8
extern u32 u32_0300478c;                          // 0x0300478C
extern struct LinkShopManager* gLinkShopManager;  // 0x03002C6C
extern u16 u16_03003510;                          // 0x03003510
extern u16 u16_03003514;                          // 0x03003514
extern u32 u32_03004790;                          // 0x03004790
extern u32 u32_03004794;                          // 0x03004794
extern u32 u32_030047ac;                          // 0x030047AC
extern u32 u32_030047b0;                          // 0x030047B0
extern u32 u32_030047bc;                          // 0x030047BC
extern u32 u32_030047c4;                          // 0x030047C4
extern u32 u32_03004860;                          // 0x03004860

void VM_CountSubroutine(void);
u32 FUN_082321e0(u8* pc);
void ResetParticlePlttSlots(void);
void Save_BackupStatAndWorld(void);
void FUN_0823cd04(void);
bool32 Map_ResetCollisionMap(void);
void* HitboxManager_Create(void);
bool8 Save_ReadSystemData(void);
void entity_08230ca4(s32 r0);
void RestoreGameState(void);
void Time_UpdateSunTimers(void);

static inline void DisableEntityFlags(u32 flags) { gEntityDisableFlags |= flags; }
static inline void EnableEntityFlags(u32 flags) { gEntityDisableFlags &= ~flags; }

static inline u32 TestFlag030047a4(u32 flags) { return (gFlag030047a4 | u32_030047a0) & flags; }

static inline void ShowBG(u32 bits) { gStagedDISPCNT |= bits; }

void FUN_0823a870(void) { gSystemSaveData = &gSystemSaveDataBuffer; }

s32 FUN_0823a880(u8* pc, ScriptArgs* args) { return VM_ExecByPointer(pc, args); }

s32 FUN_0823a88c(u8* pc, ScriptArgs* args) { return VM_ExecByPointer(pc, args); }

static s32 FUN_0823a898(u32 scriptID, ScriptArgs* args) { return VM_ExecByID(scriptID, args); }

s32 VM_ExecById_Proxy_0823a8a4(u32 scriptID, ScriptArgs* args) { return VM_ExecByID(scriptID, args); }

bool32 FUN_0823a8b0(void) {
  if (TestFlag030047a4(FLAG030047A4_GAMEOVER)) {
    return TRUE;
  }
  if (u32_030047b0 != 0) {
    return TRUE;
  }
  if (u32_03004790 != 0) {
    return TRUE;
  }
  return FALSE;
}

void FUN_0823a8f4(u32 val) {
  if (val == 0) {
    u32_03004798 = 320;
  } else {
    SoftReset_0823a928();
  }
}

void FUN_0823a910(void) { bool32_03004788 = TRUE; }

void FUN_0823a91c(void) { bool32_03004788 = FALSE; }

s32 SoftReset_0823a928(void) {
  gHBlankEffectBuffer = NULL;
  gHBlankEffectReg = NULL;
  u16_03003510 = 0;
  u16_03003514 = 0;
  gEepromIdle = FALSE;
  m4aMPlayAllStop();
  m4aSoundVSyncOff();
  WaitForVBlank();
  WaitForVBlank();
  Sensor_Disable();
  RtcIoDisable();

  if (gEntity9A9F != NULL || gLinkConnect != NULL) {
    Sio_Disconnect();
  } else if (gLinkShopManager != NULL) {
    Sio_Stop();
  }

  rfu_setREQCallback(NULL);
  rfu_REQ_stopMode();
  if (rfu_waitREQComplete() == 0) {
    SoftResetExram(0xDC);
  } else {
    SoftResetExram(0xDC);
  }
  return 0;
}

void FUN_0823a9c4(void) {
  gObjBlendEnabled = 0;
  Video_ResetBG();
  FUN_0823cd04();
  Map_ResetCollisionMap();
  HitboxManager_Create();
  ShowBG(DISPCNT_BG0_ON);
}

void FUN_0823a9f4(void) {
  FUN_0824082c();
  EnableEntityFlags(ENTITY_DISABLE_1);
}

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
  ResetParticlePlttSlots();
}

void FUN_0823aa84(void) {
  MoverList_ClearPtr();
  Camera_0823b744();
}

// A+B+START+SELECT のソフトリセットを見張り、マップのスクリプト実行からマップ切り替えの完了までを状態として進める
// 残差は5命令で、原典は &gDispcntLocked と定数 1 を呼び出しをまたいで r7/r8 に残し、scriptID も callee-saved に置いて VM_ExecByID の後にもう一度テストする。こちらは2つの if を agbcc が畳んでしまい scriptID が呼び出しを越えて生きない。Tier A-C は試済、未: 自然な形で scriptID を呼び出し越しに生かす手
NON_MATCH s32 Entity0823acbc_Update(Entity0823acbc* p) {
#ifdef NONMATCHING_C
  if (!gSoftResetInhibit) {
    if ((gInput[0].down & B_BUTTON) && (gInput[0].down & A_BUTTON) && (gInput[0].down & START_BUTTON) && (gInput[0].down & SELECT_BUTTON)) {
      SoftReset_0823a928();
      return 0;
    }
  } else {
    gSoftResetInhibit = FALSE;
  }

  switch (p->unk_18) {
    case 0: {
      u16 scriptID;

      u32_03004860 = 0;
      gDispcntLocked = TRUE;
      u32_03004798 = 0;
      p->unk_1c = 0;
      FUN_0823a9c4();
      VM_ClearScratchpad_Proxy();

      scriptID = gMapInitScriptID;
      if (scriptID != 0) {
        VM_ExecByID(scriptID, NULL);
      }
      if (scriptID == 0) {
        VM_ExecSpecial();
      }

      gDispcntLocked = FALSE;
      p->unk_18 = 1;
      u32_030047ac = 0;
      break;
    }
    case 1: {
      if (p->unk_1c < 1) {
        if (u32_03004798 != 0) {
          if (gEntityDisableFlags & ENTITY_DISABLE_1) {
            break;
          }
          if (FUN_0823a8b0() == 0) {
            u32_0300478c = 0;
            u32_030047c4 = 0;
            u32_030047ac = 1;
            EnableEntityFlags(ENTITY_DISABLE_1 | ENTITY_DISABLE_2 | ENTITY_DISABLE_3);
            entity_08230ca4(1);
            p->unk_1c = 3;
            gStagedDISPCNT &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON);
            gBgBrightness2 = 0x40;
            break;
          }
        }
        if ((gEntityDisableFlags & ENTITY_DISABLE_1) == 0) {
          u32_030047bc++;
        }
      } else {
        p->unk_1c--;
        if (p->unk_1c < 1) {
          FUN_0823aa70();
          FUN_0823aa74();
          if (gFlag030047a4 & FLAG030047A4_UNK_9) {
            gFlag030047a4 &= ~FLAG030047A4_UNK_9;
            if (gEntityDisableFlags & ENTITY_DISABLE_3) {
              EnableEntityFlags(ENTITY_DISABLE_3);
            }
          }
          if (u32_03004798 & 0x10) {
            Save_BackupStatAndWorld();
          } else if (u32_03004798 & 0x100) {
            RestoreGameState();
            SetMapInitScriptID((s16)gStat->mapInitScriptID);
          }
          p->unk_18 = 0;
        }
      }
      break;
    }
  }

  if (gSaveSucceeded) {
    Time_UpdateSunTimers();
    gSaveSucceeded = FALSE;
  }
  if (gSystemSaveData->frameCounter < 0xFFFFFFFF) {
    gSystemSaveData->frameCounter++;
  }
  u32_03004794++;
  if (bool32_03004788) {
    if (gStat->playTime < 0x7FFFFFFF) {
      gStat->playTime++;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Entity0823acbc_Update.inc");
#endif
}

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

// 0xA222
// システムデータを読み込み、読めなかったら初期値で作り直す
// 残差2件: 原典は ok が入ったレジスタを 0 の供給元として使い回すが、こちらは movs r2, #0 を別に作る。そのぶん ok と gSystemSaveData のポインタの割り当てが r4/r5 で逆になる
// 値をアドレスより先に作る順序は、 textSpeed と calibration を static inline の setter 経由にすると消えた (それだけでは一致しないので直接アクセスに戻した)。Tier A-C 試済
NON_MATCH bool32 Save_ReadSystemDataOrInit(void) {
#ifdef NONMATCHING_C
  bool8 ok = Save_ReadSystemData();
  if (!ok) {
    if (gSystemSaveData != NULL) {
      ClearMemory(gSystemSaveData, sizeof(SystemSaveData));
    }
    gStat->textSpeed = 5;
    gSystemSaveData->calibration = 230;
    gSystemSaveData->currentSlot = ok;
    gSystemSaveData->unk_09 = ok;
    gSystemSaveData->unk_0a = ok;
  }
  return ok;
#else
  INCFUNC("asm/func/Save_ReadSystemDataOrInit.inc");
#endif
}

NON_MATCH bool32 UNUSED FUN_0823ae14(Entity0823acbc* p) {
#ifdef NONMATCHING_C
  u32_03004798 = 0;
  p->unk_1c = 0;
  FUN_0823a9c4();
  VM_ClearScratchpad_Proxy();
  if (gMapInitScriptID != 0) VM_ExecByID(gMapInitScriptID, NULL);
  if (gMapInitScriptID == 0) VM_ExecSpecial();
  return TRUE;
#else
  INCFUNC("asm/func/FUN_0823ae14.inc");
#endif
}
