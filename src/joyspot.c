#include "entity.h"
#include "global.h"
#include "save.h"
#include "solar.h"
#include "text.h"
#include "vm.h"

// ジョイスポット: GBAワイヤレスアダプタを利用して、玩具店の店頭などでデータ配信や対戦が楽しめるサービス
typedef struct {
  Entity e;             // 0x00, ENTITY_UNK_2
  u8 state;             // 0x18, sJoyspotManagerUpdates の添字
  bool8 stateChanged;   // 0x19, 各ハンドラが入り口で1回だけ処理して 0 に戻す
  u8 linkError;         // 0x1A, JoyspotManager_WatchLink が bit0、JoyspotManager_SetLinkError が 理由 | 0xF0 を立てる, 非0 なら state が 9 になる
  bool8 partnerFound;   // 0x1B, Rfu_FindPartnerRecord が見つけたら 1
  u16 watchLinkResult;  // 0x1C, rfu_REQBN_watchLink の戻り値
  u8 retryCount;        // 0x1E, 3 未満なら state 5 へ戻し、以上なら state 8 へ進める
  u8 saveResult;        // 0x1F, Save_WriteSystemData の戻り値
  u8 contentIdx;        // 0x20, gJoyspotContentIDs の何番目を受け取ったか, TextPanel_SetMessage の添字として +3 される
  u8 unk_21[3];         // 0x21, まだ未解析
  u32 timer;            // 0x24, 毎フレーム +1, state を変えるとき 0 に戻る
  u8* scriptM;          // 0x28, '.m'
  u8* scriptS;          // 0x2C, '.s'
  s32 panelID;          // 0x30, TextPanel_Create(1, 7, 28, 6) の戻り値, 負なら未作成
  s32 scriptID;         // 0x34, '.e', state 8 が 20フレーム後に VM_ExecByID へ渡す
  u8 unk_38;            // 0x38, まだ未解析
  u8 linkLossSlot;      // 0x39, rfu_REQBN_watchLink の bmLinkLossSlot
  u8 linkLossReason;    // 0x3A, rfu_REQBN_watchLink の linkLossReason
  u8 linkRecoverySlot;  // 0x3B, rfu_REQBN_watchLink の parentBmLinkRecoverySlot
  u8 partnerRecord[8];  // 0x3C, Rfu_FindPartnerRecord の dst, 先頭2バイトを JoyspotManager_FindContentIdx が gJoyspotContentIDs の4つと比べる
  u8 unk_44[8];         // 0x44, Rfu_FindPartnerRecord の buf
} JoyspotManager;
static_assert(sizeof(JoyspotManager) == 76);

IWRAM_DATA s32 s32_030000d4 = 0;                    // 0x030000D4
IWRAM_DATA JoyspotManager* gJoyspotManager = NULL;  // 0x030000D8

COMMON_DATA u32 u32_03002b54 = 0;  // 0x03002B54

// clang-format off
// ジョイスポットでの配信コンテンツのID
const u8 gJoyspotContentIDs[8] = {
  0x67, 0x8E, // BB (Blind Box) Lv.3
  0xAA, 0x8F, // BB Lv.4
  0xE0, 0x90, // BB Lv.5 + バレンタイン
  0xD6, 0x8F, // ???(スネーク)関連のイベント配信
};  // 0x085AB5B0
// clang-format on

void SignalStrengthIcon_CreateAt(s32 x, s32 y);

static inline void JoyspotManager_SetState(JoyspotManager* p, u8 state) {
  p->state = state;
  p->stateChanged = 1;
  p->timer = 0;
}

s32 JoyspotManager_IsActive(void) {
  if (gJoyspotManager != NULL) {
    return 1;
  }
  return 0;
}

// リンク状態を見て, 切れていたら linkError の bit0 を立てる
void JoyspotManager_WatchLink(void) {
  JoyspotManager* p = gJoyspotManager;

  if (p != NULL) {
    p->watchLinkResult = rfu_REQBN_watchLink(0, &p->linkLossSlot, &p->linkLossReason, &p->linkRecoverySlot);
    if (p->watchLinkResult != 0) {
      p->linkError |= 1;
    }
    rfu_REQ_recvData();
  }
}

// 第1引数は使っておらず、グローバルの方に書く
void JoyspotManager_SetLinkError(JoyspotManager* _, u16 reason) {
  if (gJoyspotManager != NULL && reason != 0) {
    gJoyspotManager->linkError |= 0xF0 | reason;
  }
}

NAKED s32 JoyspotManager_InitAdapter(JoyspotManager* unused) { INCFUNC("asm/func/JoyspotManager_InitAdapter.inc"); }

NAKED void JoyspotManager_Disconnect(void) { INCFUNC("asm/func/JoyspotManager_Disconnect.inc"); }

NAKED void JoyspotManager_SetupBG(JoyspotManager* p, s32 param_2) { INCFUNC("asm/func/JoyspotManager_SetupBG.inc"); }

void JoyspotManager_Start(JoyspotManager* p) {
  JoyspotManager_SetupBG(p, 3);
  p->panelID = TextPanel_Create(1, 7, 28, 6);

  if (JoyspotManager_InitAdapter(p) >= 0) {
    JoyspotManager_SetState(p, 1);
    if (p->panelID >= 0) {
      TextPanel_SetScript(p->panelID, p->scriptM);
      TextPanel_SetMessage(p->panelID, 2);
      TextPanel_Start(p->panelID);
    }
    rfu_REQ_startSearchParent();
    rfu_waitREQComplete();
  } else {
    JoyspotManager_SetState(p, 0);
    if (p->panelID >= 0) {
      TextPanel_SetScript(p->panelID, p->scriptM);
      TextPanel_SetMessage(p->panelID, 1);
      TextPanel_Start(p->panelID);
    }
  }
}

NAKED void JoyspotManager_StateInitFailed(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateInitFailed.inc"); }

// record の先頭2バイトと一致する配信コンテンツIDの番号, 見つからなければ -1
s32 JoyspotManager_FindContentIdx(u8* record) {
  s32 i;

  for (i = 0; i < 4; i++) {
    s32 match = 0;
    s32 j = 0;
    const u8* id = &gJoyspotContentIDs[i * 2];

    while (j < 2) {
      if (record[j] == *id) {
        match++;
      }
      id++;
      j++;
    }
    if (match == 2) {
      return i;
    }
  }
  return -1;
}

// idx 番の配信コンテンツIDをセーブデータの eventFlags[idx] に書き写す
// 残差1命令, gSystemSaveData のプールアドレスのロードが id の初期化より前に出るかどうかだけ違う (ループ不変式の巻き上げ位置)
NON_MATCH void JoyspotManager_StoreContentID(s32 idx) {
#ifdef NONMATCHING_C
  s32 dst = idx * 2;
  const u8* id = &gJoyspotContentIDs[dst];
  s32 i;

  for (i = 0; i < 2; i++, dst++) {
    u8 v = *id;
    u8* flags = (u8*)gSystemSaveData->eventFlags;

    flags[dst] = v;
    id++;
  }
#else
  INCFUNC("asm/func/JoyspotManager_StoreContentID.inc");
#endif
}

NAKED void JoyspotManager_StateSearch(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateSearch.inc"); }

NAKED void JoyspotManager_StateRecvOk(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateRecvOk.inc"); }

NAKED void JoyspotManager_StateRecvFailed(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateRecvFailed.inc"); }

NAKED void JoyspotManager_StateNotFound(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateNotFound.inc"); }

NAKED void JoyspotManager_StateSave(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateSave.inc"); }

NAKED void JoyspotManager_StateSaveOk(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateSaveOk.inc"); }

NAKED void JoyspotManager_StateSaveFailed(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateSaveFailed.inc"); }

// 20フレーム待ってから '.e' のスクリプトを起動して自分を消す
void JoyspotManager_StateFinish(JoyspotManager* p) {
  if (p->stateChanged) {
    p->stateChanged = 0;
  }

  if (p->timer == 20 && p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
    KillEntity((Entity*)p);
  } else {
    p->timer++;
  }
}

NAKED void JoyspotManager_StateLinkError(JoyspotManager* p) { INCFUNC("asm/func/JoyspotManager_StateLinkError.inc"); }

// clang-format off
static void (*const sJoyspotManagerUpdates[10])(JoyspotManager*) = {
    JoyspotManager_StateInitFailed,   // 0, アダプタの初期化に失敗
    JoyspotManager_StateSearch,       // 1, 親を探して配信コンテンツIDを照合する
    JoyspotManager_StateRecvOk,       // 2, 受け取れた, キー入力で 5 へ
    JoyspotManager_StateRecvFailed,   // 3, 相手はいたが受け取れなかった
    JoyspotManager_StateNotFound,     // 4, 相手が見つからなかった
    JoyspotManager_StateSave,         // 5, 60フレーム後に Save_WriteSystemData
    JoyspotManager_StateSaveOk,       // 6, セーブ成功
    JoyspotManager_StateSaveFailed,   // 7, セーブ失敗, retryCount が 3 未満なら 5 へ戻る
    JoyspotManager_StateFinish,       // 8, 20フレーム後に scriptID を実行して KillEntity
    JoyspotManager_StateLinkError,    // 9, 通信エラー
};  // 0x085AB5B8
// clang-format on

s32 JoyspotManager_Update(JoyspotManager* p) {
  Taiyo_Disable();

  if (u32_03002b54 != 0) {
    p->linkError |= 0x70;
  }

  if (p->state != 8 && p->state != 9 && p->linkError != 0) {
    JoyspotManager_SetState(p, 9);
  }

  sJoyspotManagerUpdates[p->state](p);
  return 0;
}

s32 JoyspotManager_Destroy(JoyspotManager* p) {
  Taiyo_Enable();
  if (p->panelID >= 0) {
    TextPanel_Hide(p->panelID);
    TextPanel_Destroy(p->panelID);
  }
  gJoyspotManager = NULL;
  return 0;
}

s32 JoyspotManager_Init(JoyspotManager* p) {
  u32_03002b54 = 0;
  gJoyspotManager = p;
  Taiyo_Disable();

  if (!VM_SeekToNamedArg('m')) {
    return -1;
  }

  p->scriptM = VM_GetPC_Proxy();
  if (p->scriptM == NULL) {
    return -1;
  }

  if (VM_SeekToNamedArg('s')) {
    p->scriptS = VM_GetPC_Proxy();
    if (p->scriptS == NULL) {
      return -1;
    }
  } else {
    return -1;
  }

  p->scriptID = VM_GetNamedArgValue('e', 0);
  JoyspotManager_Start(p);
  SignalStrengthIcon_CreateAt(0, 0);
  return 0;
}

JoyspotManager* JoyspotManager_Create(void) {
  JoyspotManager* p = CreateEntity(ENTITY_UNK_2, sizeof(JoyspotManager));

  if (p != NULL) {
    SetEntityRoutine(p, JoyspotManager_Update, JoyspotManager_Destroy);
    if (JoyspotManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
