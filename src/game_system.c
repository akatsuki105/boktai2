#include "camera.h"
#include "eeprom.h"
#include "global.h"
#include "hitbox.h"
#include "input.h"
#include "link.h"
#include "link_session.h"
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

// 起動時に GameSystem_Boot が登録する常駐タスク, 静的に置くので他のEntity と違って GameSystem_Create と GameSystem_Init を持たない
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_1
  s32 state;           // 0x18, 0: マップ開始, 1: マップ中
  s32 mapChangeTimer;  // 0x1C, マップ切り替えの要求から完了までの 3 フレームを数える
} GameSystem;
static_assert(sizeof(GameSystem) == 32);

IWRAM_DATA GameSystem gGameSystem = {};  // 0x030016A0

IWRAM_DATA SystemSaveData gSystemSaveDataBuffer = {};  // 0x030016C0

extern struct LinkConnect* gLinkConnect;  // 0x03002C64

extern bool32 gPlayTimeEnabled;
extern bool32 gDispcntLocked;                     // 0x03002CA8
extern u32 u32_0300478c;                          // 0x0300478C
extern struct LinkShopManager* gLinkShopManager;  // 0x03002C6C
extern u16 gHBlankDmaCount;                       // 0x03003510
extern s16 gHBlankDmaMode;                        // 0x03003514
extern u32 u32_03004790;                          // 0x03004790
extern u32 gSystemFrameCounter;                   // 0x03004794
extern u32 gMapChanging;                          // 0x030047AC
extern u32 u32_030047b0;                          // 0x030047B0
extern u32 gUnpausedFrameCounter;                 // 0x030047BC
extern u32 u32_030047c4;                          // 0x030047C4
extern u32 u32_03004860;                          // 0x03004860
extern u32 u32_0300479c;                          // 0x0300479C
extern u32 u32_030047c0;                          // 0x030047C0

void VM_CountSubroutine(void);
u32 FUN_082321e0(u8* pc);
void ResetParticlePlttSlots(void);
void Save_BackupStatAndWorld(void);
void FUN_0823cd04(void);
void* HitboxManager_Create(void);
bool8 Save_ReadSystemData(void);
void entity_08230ca4(s32 r0);
void RestoreGameState(void);
void Time_UpdateSunTimers(void);
s32 FUN_0823b130(void);
void FUN_082324b0(void);
void FUN_0823d280(void);

// システムセーブデータの置き場を IWRAM のバッファに向ける
void GameSystem_InitSaveDataPtr(void) { gSystemSaveData = &gSystemSaveDataBuffer; }

static s32 UNUSED VM_ExecByPointer_Proxy_0823a880(u8* pc, ScriptArgs* args) { return VM_ExecByPointer(pc, args); }

s32 VM_ExecByPointer_Proxy_0823a88c(u8* pc, ScriptArgs* args) { return VM_ExecByPointer(pc, args); }

static s32 UNUSED VM_ExecById_Proxy_0823a898(u32 scriptID, ScriptArgs* args) { return VM_ExecByID(scriptID, args); }

s32 VM_ExecById_Proxy_0823a8a4(u32 scriptID, ScriptArgs* args) { return VM_ExecByID(scriptID, args); }

// ゲームオーバー中などマップ切り替えを待たせる状態なら TRUE を返す
bool32 GameSystem_IsMapChangeBlocked(void) {
  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), GAMEFLAG_GAMEOVER)) {
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

// ゲームオーバー画面の選択を処理する, 0 ならゲーム状態を復元してマップを読み直し, それ以外はソフトリセットする
void GameSystem_HandleGameOverChoice(u32 val) {
  if (val == 0) {
    gMapChangeFlags = MAPCHANGE_RESTART | MAPCHANGE_RESTORE;
  } else {
    GameSystem_SoftReset();
  }
}

// プレイ時間の計測を再開する
void Cmd_ResumePlayTime(void) { gPlayTimeEnabled = TRUE; }

// プレイ時間の計測を止める
void Cmd_StopPlayTime(void) { gPlayTimeEnabled = FALSE; }

// 割り込みと通信と音を止めてからソフトリセットする
s32 GameSystem_SoftReset(void) {
  gHBlankEffectBuffer = NULL;
  gHBlankEffectReg = NULL;
  gHBlankDmaCount = 0;
  gHBlankDmaMode = 0;
  gEepromIdle = FALSE;
  m4aMPlayAllStop();
  m4aSoundVSyncOff();
  WaitForVBlank();
  WaitForVBlank();
  Sensor_Disable();
  RtcIoDisable();

  if (gLinkSession != NULL || gLinkConnect != NULL) {
    Sio_Disconnect();
  } else if (gLinkShopManager != NULL) {
    Sio_Stop();
  }

  rfu_setREQCallback(NULL);
  rfu_REQ_stopMode();
  if (rfu_waitREQComplete() == 0) {
    SoftResetExram(RESET_REGS | RESET_SOUND_REGS | RESET_OAM | RESET_VRAM | RESET_PALETTE);
  } else {
    SoftResetExram(RESET_REGS | RESET_SOUND_REGS | RESET_OAM | RESET_VRAM | RESET_PALETTE);
  }
  return 0;
}

// マップ開始時に BG と当たり判定を初期化する
void GameSystem_ResetMap(void) {
  gObjBlendEnabled = 0;
  Video_ResetBG();
  FUN_0823cd04();
  Map_ResetCollisionMap();
  HitboxManager_Create();
  SET_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
}

// 止めていた音を再開し, SUSPEND_PAUSE による停止を解く
void GameSystem_Unpause(void) {
  Sound_Resume();
  CLEAR_FLAGS(gSuspendFlags, SUSPEND_PAUSE);
}

// ポーズ禁止でなければ音を止め, SUSPEND_PAUSE でエンティティを止める
void GameSystem_Pause(void) {
  if (!TEST_FLAGS((gGameFlags | gDebugGameFlags), GAMEFLAG_NO_PAUSE)) {
    FUN_082407e0();
    SET_FLAGS(gSuspendFlags, SUSPEND_PAUSE);
  }
}

// 他の原因で止まっていなければ, ポーズの切り替えをする
void GameSystem_TogglePause(void) {
  if (!(gSuspendFlags & ~SUSPEND_PAUSE)) {
    if (!(gSuspendFlags & SUSPEND_PAUSE)) {
      GameSystem_Pause();
    } else {
      GameSystem_Unpause();
    }
  }
}

void nop_0823aa70(void) {}

// マップ終了時に登録物を掃除し, パーティクルのパレット枠を空ける
void GameSystem_CleanupMap(void) {
  Registry_Sweep(FALSE);
  ResetParticlePlttSlots();
}

void FUN_0823aa84(void) {
  MoverList_ClearPtr();
  Camera_0823b744();
}

// A+B+START+SELECT のソフトリセットを見張り、マップのスクリプト実行からマップ切り替えの完了までを状態として進める
// 残差は5命令で、原典は &gDispcntLocked と定数 1 を呼び出しをまたいで r7/r8 に残し、scriptID も callee-saved に置いて VM_ExecByID の後にもう一度テストする。こちらは2つの if を agbcc が畳んでしまい scriptID が呼び出しを越えて生きない。Tier A-C は試済、未: 自然な形で scriptID を呼び出し越しに生かす手
NON_MATCH s32 GameSystem_Update(GameSystem* p) {
#ifdef NONMATCHING_C
  if (!gSoftResetInhibit) {
    if ((gInput[0].down & B_BUTTON) && (gInput[0].down & A_BUTTON) && (gInput[0].down & START_BUTTON) && (gInput[0].down & SELECT_BUTTON)) {
      GameSystem_SoftReset();
      return 0;
    }
  } else {
    gSoftResetInhibit = FALSE;
  }

  switch (p->state) {
    case 0: {
      u16 scriptID;

      u32_03004860 = 0;
      gDispcntLocked = TRUE;
      gMapChangeFlags = 0;
      p->mapChangeTimer = 0;
      GameSystem_ResetMap();
      VM_ClearScratchpad_Proxy();

      scriptID = gMapInitScriptID;
      if (scriptID != 0) {
        VM_ExecByID(scriptID, NULL);
      }
      if (scriptID == 0) {
        VM_ExecBoot();
      }

      gDispcntLocked = FALSE;
      p->state = 1;
      gMapChanging = 0;
      break;
    }
    case 1: {
      if (p->mapChangeTimer < 1) {
        if (gMapChangeFlags != 0) {
          if (gSuspendFlags & SUSPEND_PAUSE) {
            break;
          }
          if (GameSystem_IsMapChangeBlocked() == 0) {
            u32_0300478c = 0;
            u32_030047c4 = 0;
            gMapChanging = 1;
            CLEAR_FLAGS(gSuspendFlags, SUSPEND_PAUSE | SUSPEND_MENU | SUSPEND_EVENT);
            entity_08230ca4(1);
            p->mapChangeTimer = 3;
            gStagedDISPCNT &= ~(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON);
            gBgBrightness2 = 0x40;
            break;
          }
        }
        if (!(gSuspendFlags & SUSPEND_PAUSE)) {
          gUnpausedFrameCounter++;
        }
      } else {
        p->mapChangeTimer--;
        if (p->mapChangeTimer < 1) {
          nop_0823aa70();
          GameSystem_CleanupMap();
          if (gGameFlags & GAMEFLAG_EVENT) {
            gGameFlags &= ~GAMEFLAG_EVENT;
            if (gSuspendFlags & SUSPEND_EVENT) {
              CLEAR_FLAGS(gSuspendFlags, SUSPEND_EVENT);
            }
          }
          if (gMapChangeFlags & MAPCHANGE_BACKUP) {
            Save_BackupStatAndWorld();
          } else if (gMapChangeFlags & MAPCHANGE_RESTORE) {
            RestoreGameState();
            SetMapInitScriptID((s16)gStat->mapInitScriptID);
          }
          p->state = 0;
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
  gSystemFrameCounter++;
  if (gPlayTimeEnabled) {
    if (gStat->playTime < 0x7FFFFFFF) {
      gStat->playTime++;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/GameSystem_Update.inc");
#endif
}

s32 GameSystem_Destroy(GameSystem* _) {}

// 起動時の初期化: VM とゲームの状態を空にして乱数表を作り, 常駐のエンティティを登録する
// 残差: 原典は &gMapChangeFlags を 6つ目の 0 書き込みの前に積んでおき, textSpeed の 2 を gStat より先に作る (textSpeed を static inline の setter 経由にすると後者だけ消える)
NON_MATCH void GameSystem_Boot(void) {
#ifdef NONMATCHING_C
  VM_CountSubroutine();
  FUN_0823aa84();
  FUN_0823b130();
  FUN_082324b0();
  gGameFlags = 0;
  gDebugGameFlags = 0;
  u32_0300479c = 0;
  u32_030047c0 = 0;
  u32_0300478c = 0;
  u32_030047c4 = 0;
  gSoftResetInhibit = FALSE;
  u32_030047b0 = 0;
  u32_03004790 = 0;
  gUnpausedFrameCounter = 0;
  gSystemFrameCounter = 0;
  gMapChanging = 0;
  gPlayTimeEnabled = FALSE;
  gStat->mapFlags = 0;
  gMapChangeFlags = 0;
  u32_03004860 = 0;
  FUN_0823d280();
  CreateRandomTable();
  gStat->textSpeed = 2;
  SetEntityRoutine(&gGameSystem, GameSystem_Update, GameSystem_Destroy);
  gGameSystem.e.kind = ENTITY_UNK_1;
  gGameSystem.e.unk_16 = 1;
  gGameSystem.e.id = 0;
  AddEntity(&gGameSystem.e);
  gGameSystem.state = 0;
  gGameSystem.mapChangeTimer = 0;
#else
  INCFUNC("asm/func/GameSystem_Boot.inc");
#endif
}

// 引数がなければステータスとワールドを丸ごと退避し, あれば並べた変数だけを退避領域に書き写す
s32 Cmd_BackupState(void) {
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

// 退避領域に残っている変数の値を返す
u32 Cmd_GetBackupValue(void) { return FUN_082321e0(VM_GetPC()); }

// 0xA222
// システムデータを読み込み、読めなかったら初期値で作り直す
// 残差2件: 原典は ok が入ったレジスタを 0 の供給元として使い回すが、こちらは movs r2, #0 を別に作る。そのぶん ok と gSystemSaveData のポインタの割り当てが r4/r5 で逆になる
// 値をアドレスより先に作る順序は、 textSpeed と calibration を static inline の setter 経由にすると消えた (それだけでは一致しないので直接アクセスに戻した)。Tier A-C 試済
NON_MATCH bool32 Cmd_ReadSystemDataOrInit(void) {
#ifdef NONMATCHING_C
  bool8 ok = Save_ReadSystemData();
  if (!ok) {
    if (gSystemSaveData != NULL) {
      ClearMemory(gSystemSaveData, sizeof(SystemSaveData));
    }
    gStat->textSpeed = 5;
    gSystemSaveData->calibration = 230;
    gSystemSaveData->currentSlot = 0;
    gSystemSaveData->unk_09 = 0;
    gSystemSaveData->unk_0a = 0;
  }
  return ok;
#else
  INCFUNC("asm/func/Cmd_ReadSystemDataOrInit.inc");
#endif
}

// マップ初期化スクリプトがあればそれを, なければ特殊スクリプトを起動する
// 残差2命令, 原典は 2つ目の if を畳まず cmp/bne で再判定するが agbcc はどう書いても 1つ目の結果から b に畳む
// (ネストした if / 早期 return / 代入位置を動かす形はいずれも同じか悪化, 試済)
NON_MATCH bool32 UNUSED GameSystem_StartMap(GameSystem* p) {
#ifdef NONMATCHING_C
  u16 id = gMapInitScriptID;

  gMapChangeFlags = 0;
  p->mapChangeTimer = 0;
  GameSystem_ResetMap();
  VM_ClearScratchpad_Proxy();
  if (id != 0) {
    VM_ExecByID(id, NULL);
  }
  if (id == 0) {
    VM_ExecBoot();
  }
  return TRUE;
#else
  INCFUNC("asm/func/GameSystem_StartMap.inc");
#endif
}
