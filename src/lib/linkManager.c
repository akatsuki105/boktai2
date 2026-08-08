#include "gba/gba.h"
#include "global.h"

// pret: AgbRfu_LinkManager

//-----------------------------------------------------------------
// 定数定義
//-----------------------------------------------------------------

// rfu_LMAN_checkRecvChildNameで使用する定数
#define RN_ACCEPT 0x01            // 子機受け入れOKフラグ
#define RN_NAME_TIMER_CLEAR 0x02  // 名前受信タイマークリアフラグ
#define RN_DISCONNECT 0x04        // 子機切断フラグ

// rfu_LMAN_linkWatcherにおいて、lman.linkRecovery_start_flagで使用する定数
#define LINK_RECOVERY_OFF 0x00         // リンク復旧OFF
#define LINK_RECOVERY_START 0x01       // リンク復旧起動
#define LINK_RECOVERY_EXE 0x02         // リンク復旧動作中
#define LINK_RECOVERY_IMPOSSIBLE 0x04  // リンク復旧不可能な状態

// lman.fastSearchParent_flagの値
#define FSP_ON 0x01
#define FSP_START 0x02

// lman.p_c_switch_flagの値
#define PCSWITCH_1ST_SC_START 0x01
#define PCSWITCH_1ST_SC 0x02
#define PCSWITCH_2ND_SP_START 0x03
#define PCSWITCH_2ND_SP 0x04
#define PCSWITCH_3RD_SC_START 0x05
#define PCSWITCH_3RD_SC 0x06
#define PCSWITCH_CP 0x07
#define PCSWITCH_SC_LOCK 0x08
#define PCSWITCH_FORCE_SP_START 0x09

// 親子切り替えサーチの設定時間
#define PCSWITCH_ALL_PERIOD 180  // 全体周期180フレーム
#define PCSWITCH_SP_PERIOD 40    // 子機期間40フレーム

static void rfu_LMAN_clearVariables();
static void rfu_LMAN_endManager();
static void rfu_LMAN_REQ_callback(u16 REQ_commandID, u16 REQ_result);
static void rfu_LMAN_MSC_callback(u16 REQ_commandID);
static void rfu_LMAN_PARENT_checkRecvChildName();
static void rfu_LMAN_CHILD_checkSendChildName();
static void rfu_LMAN_CHILD_checkSendChildName2();
static void rfu_LMAN_CHILD_linkRecoveryProcess();
static u8 rfu_LMAN_CHILD_checkEnableParentCandidate();
void rfu_LMAN_occureCallback(u8 msg, u8 param_count);
void rfu_LMAN_disconnect(u8 bm_disconnectSlot);
void rfu_LMAN_reflectCommunicationStatus(u8 bm_disconnectedSlot);
void rfu_LMAN_checkNICommunicateStatus();
static u8 rfu_LMAN_linkWatcher(u16 REQ_commandID);
static void rfu_LMAN_settingPCSWITCH(u32 rand);
static void rfu_LMAN_managerChangeAgbClockMaster();

u32 rfu_LMAN_REQBN_softReset_and_checkID() {
  u32 id;

  id = rfu_REQBN_softReset_and_checkID();
  if (id == RFU_ID) {  // ver.1.0.11sp追加
    lman.RFU_powerOn_flag = 1;
  }

  if ((lman.state == LMAN_FORCED_STOP_AND_RFU_RESET) || (lman.state == LMAN_STATE_SOFT_RESET_AND_CHECK_ID)) {
  } else {  // ver.1.0.13sp追加
    lman.state = lman.next_state = 0;
  }
  lman.pcswitch_flag = 0;
  lman.acceptSlot_flag = lman.acceptCount = lman.reserveDisconnectSlot_flag = 0;
  lman.parent_child = MODE_NEUTRAL;
  rfu_LMAN_managerChangeAgbClockMaster();  // 子機でクロックスレーブ時はクロックマスターに戻す。
  return id;
}

void rfu_LMAN_REQ_sendData(u8 clockChange_flag) {
  if (gRfuLinkStatus->parent_child == MODE_CHILD) {
    if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_ON) {
      clockChange_flag = 1;
    } else {
      clockChange_flag = 0;  // 子機はAGBクロックスレーブフラグがONではない時は、再クロックスレーブ化は行わない。
    }
  } else {                    // if(gRfuLinkStatus->parent_child==MODE_PARENT)
    lman.parentAck_flag = 0;  // 親機は新規のデータ送信ごとにACKフラグをクリアする。
  }
  rfu_REQ_sendData(clockChange_flag);
}

u8 rfu_LMAN_initializeManager(void (*LMAN_callback_p)(u8, u8), void (*MSC_callback_p)(u16)) {
  if ((u32)LMAN_callback_p == 0) return LMAN_ERROR_ILLEGAL_PARAMETER;
  CpuFill16(0, &lman, sizeof(LINK_MANAGER));
  lman.parent_child = MODE_NEUTRAL;
  lman.LMAN_callback = LMAN_callback_p;  // ユーザー定義のLMANコールバック関数を定義
  lman.MSC_callback = MSC_callback_p;    // ユーザー定義のMSCコールバック関数を設定

  rfu_setMSCCallback(rfu_LMAN_MSC_callback);  // リンクマネージャー用MSCコールバックルーチンのセット ※リンクマネージャー使用時は、本MSCコールバックを経由してユーザー定義のMSCコールバックに分岐します。
  rfu_setREQCallback(rfu_LMAN_REQ_callback);  // リンクマネージャー用REQコールバックルーチンのセット ※リンクマネージャー使用時は、ユーザー定義のREQコールバックは発生しません。
  return 0;
}

static void rfu_LMAN_endManager() {
  CpuFill16(0, &lman, sizeof(LINK_MANAGER) - 8);
  lman.parent_child = MODE_NEUTRAL;
}

void rfu_LMAN_initializeRFU(INIT_PARAM* init_parameters) {
  rfu_LMAN_clearVariables();

  lman.state = LMAN_STATE_SOFT_RESET_AND_CHECK_ID;
  lman.next_state = LMAN_STATE_RESET;
  lman.init_param = init_parameters;

  lman.linkRecovery_enable = init_parameters->linkRecovery_enable;
  lman.linkRecoveryTimer.count_max = init_parameters->linkRecovery_period;
  lman.NI_failCounter_limit = init_parameters->NI_failCounter_limit;
  if (init_parameters->fastSearchParent_flag)  // ver.1.0.7sp追加
    lman.fastSearchParent_flag = FSP_ON;
}

static void rfu_LMAN_clearVariables() {
  u8 i;

  lman.state = lman.next_state = LMAN_STATE_READY;
  lman.parent_child = MODE_NEUTRAL;
  lman.pcswitch_flag = 0;
  lman.child_slot = 0;
  lman.connectSlot_flag_old = 0;
  lman.nameAcceptTimer.active = 0;
  lman.linkRecoveryTimer.active = 0;

  for (i = 0; i < RFU_CHILD_MAX; i++) {
    lman.nameAcceptTimer.count[i] = 0;
    lman.linkRecoveryTimer.count[i] = 0;
  }
}

void rfu_LMAN_powerDownRFU() { lman.state = LMAN_STATE_STOP_MODE; }

u8 rfu_LMAN_establishConnection(u8 parent_child, u16 connect_period, u16 name_accept_period, u16* acceptable_serialNo_list) {
  u8 i;
  u16* serial_list;

  // エラーチェック
  if (lman.state != LMAN_STATE_READY) {  // リンクマネージャーが動作中ならエラー
    if ((lman.state == LMAN_STATE_WAIT_RECV_CHILD_NAME) && (parent_child == MODE_PARENT)) {
      // ※但し、LMAN_STATE_WAIT_RECV_CHILD_NAME中にPARENTで開始する場合はＯＫ
    } else {
      lman.param[0] = LMAN_ERROR_MANAGER_BUSY;
      rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
      return LMAN_ERROR_MANAGER_BUSY;
    }
  }

  if (rfu_getMasterSlave() == AGB_CLK_SLAVE) {  // AGBがクロックスレーブならエラー
    lman.param[0] = LMAN_ERROR_AGB_CLK_SLAVE;
    rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
    return LMAN_ERROR_AGB_CLK_SLAVE;
  }

  serial_list = acceptable_serialNo_list;  // シリアル№リストが16個以内で終端されていなければエラー
  for (i = 0; i < 16; i++)
    if (*serial_list++ == 0xffff) break;
  if (i == 16) {
    lman.param[0] = LMAN_ERROR_ILLEGAL_PARAMETER;
    rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
    return LMAN_ERROR_ILLEGAL_PARAMETER;
  }

  // 関数本体
  if (parent_child > MODE_PARENT) {  // MODE_PARENT以上はすべてMODE_P_C_SWITCHとみなす
    lman.pcswitch_flag = PCSWITCH_1ST_SC_START;
    parent_child = MODE_PARENT;  // 親子切り替えモード時は、とりあえず親機でスタート
    connect_period = 0;          // 親子切り替えモード時は、サーチ期間は無視する
  } else {
    lman.pcswitch_flag = 0;
  }

  if (parent_child) {
    lman.state = LMAN_STATE_START_SEARCH_CHILD;
  } else {
    lman.state = LMAN_STATE_START_SEARCH_PARENT;

    if (lman.fastSearchParent_flag)  // ver.1.0.7sp追加
      lman.fastSearchParent_flag = FSP_START;
  }
  lman.parent_child = parent_child;
  lman.connect_period = connect_period;
  lman.nameAcceptTimer.count_max = name_accept_period;
  lman.acceptable_serialNo_list = acceptable_serialNo_list;

  return 0;
}

u8 rfu_LMAN_CHILD_connectParent(u16 pid, u16 connect_period) {
  u8 i;

  // エラーチェック
  if (lman.state != LMAN_STATE_READY) {
    if ((lman.state < LMAN_STATE_START_SEARCH_PARENT) || (lman.state > LMAN_STATE_END_SEARCH_PARENT)) {  // ver.1.0.9sp
                                                                                                         // 2003.10.29変更。fastSearchとの兼ね合いで、すべてのSP実行中にはOKとする。
      lman.param[0] = LMAN_ERROR_MANAGER_BUSY;
      rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
      return LMAN_ERROR_MANAGER_BUSY;  // リンクマネージャーが親機サーチ以外の動作中ならエラー
    }
  }

  if (rfu_getMasterSlave() == AGB_CLK_SLAVE) {
    lman.param[0] = LMAN_ERROR_AGB_CLK_SLAVE;
    rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
    return LMAN_ERROR_AGB_CLK_SLAVE;  // AGBがクロックスレーブならエラー
  }

  for (i = 0; i < gRfuLinkStatus->findParentCount; i++)
    if (gRfuLinkStatus->partner[i].id == pid) break;
  if ((gRfuLinkStatus->findParentCount == 0) || (i == gRfuLinkStatus->findParentCount)) {
    lman.param[0] = LMAN_ERROR_PID_NOT_FOUND;
    rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
    return LMAN_ERROR_PID_NOT_FOUND;  // findParentCountが0か、指定されたPIDがSearchParentで発見した親機リストに存在しなければエラー
  }

  // 関数本体
  if ((lman.state == LMAN_STATE_READY) || (lman.state == LMAN_STATE_START_SEARCH_PARENT)) {  // v1.0.9追加 2003.10.29
    lman.state = LMAN_STATE_START_CONNECT_PARENT;
    lman.next_state = LMAN_STATE_POLL_CONNECT_PARENT;
  } else {
    lman.state = LMAN_STATE_END_SEARCH_PARENT;
    lman.next_state = LMAN_STATE_START_CONNECT_PARENT;
  }
  lman.work = pid;
  lman.connect_period = connect_period;

  if (lman.pcswitch_flag)              // ver.1.0.10sp追加
    lman.pcswitch_flag = PCSWITCH_CP;  // 親子切り替えONの時には、一時停止する。

  return 0;
}

void rfu_LMAN_PARENT_stopWaitLinkRecoveryAndDisconnect(u8 bm_targetSlot) {
  u8 i;

  if ((bm_targetSlot & lman.linkRecoveryTimer.active) == 0) return;

  // リンク復旧待ちタイマーの停止
  lman.linkRecoveryTimer.active &= ~bm_targetSlot;
  for (i = 0; i < RFU_CHILD_MAX; i++) {
    if (bm_targetSlot & (0x01 << i)) lman.linkRecoveryTimer.count[i] = 0;
  }

  // 対象子機のDISCONNECTおよびLMANコールバックの発生
  i = gRfuLinkStatus->linkLossSlot_flag & bm_targetSlot;
  if (i) {
    rfu_LMAN_disconnect(i);
  }

  lman.param[0] = i;  // 2003.07.24 ver.1.0.5追加
  rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, i);
}

void rfu_LMAN_stopManager(u8 forced_stop_and_RFU_reset_flag) {
  u8 msg = 0;

  lman.pcswitch_flag = 0;  // ver.1.0.10  2003.10.30追加
                           // 本関数コールで、親子切り替えサーチは停止します。
  if (forced_stop_and_RFU_reset_flag) {
    rfu_LMAN_clearVariables();
    lman.state = LMAN_FORCED_STOP_AND_RFU_RESET;
    return;
  }

  // 関数本体
  switch (lman.state) {
      // SearchChild
    case LMAN_STATE_START_SEARCH_CHILD:
      lman.state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
      lman.next_state = LMAN_STATE_READY;
      msg = LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED;
      break;
    case LMAN_STATE_POLL_SEARCH_CHILD:
    case LMAN_STATE_END_SEARCH_CHILD:
      lman.state = LMAN_STATE_END_SEARCH_CHILD;
      lman.next_state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
      break;
    case LMAN_STATE_WAIT_RECV_CHILD_NAME:  // ver.1.0.12sp追加。名前受信待ちの時は即停止しない。
      break;
      // SearchParent
    case LMAN_STATE_START_SEARCH_PARENT:
      lman.state = lman.next_state = LMAN_STATE_READY;
      msg = LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED;
      break;
    case LMAN_STATE_POLL_SEARCH_PARENT:
    case LMAN_STATE_END_SEARCH_PARENT:
      lman.state = LMAN_STATE_END_SEARCH_PARENT;
      lman.next_state = LMAN_STATE_READY;
      break;

      // ConnectParent
    case LMAN_STATE_START_CONNECT_PARENT:
      lman.state = lman.next_state = LMAN_STATE_READY;
      msg = LMAN_MSG_CONNECT_PARENT_FAILED;
      break;
    case LMAN_STATE_POLL_CONNECT_PARENT:
    case LMAN_STATE_END_CONNECT_PARENT:
      lman.state = LMAN_STATE_END_CONNECT_PARENT;
      break;
    case LMAN_STATE_SEND_CHILD_NAME:  // ver.1.0.12sp追加。名前送信待ちの時は即停止しない。
      break;

      // LinkRecovery
    case LMAN_STATE_START_LINK_RECOVERY:  // ※ここは特殊な挙動をする。
      lman.state = lman.state_bak[0];     // リンク復旧が開始される前にリンクマネージャーが停止されたなら、DISCONNECTしてリンク復旧失敗＆DISCONNECTを通知
      lman.next_state = lman.state_bak[1];

      rfu_LMAN_disconnect(gRfuLinkStatus->linkLossSlot_flag);  // ここは子機による実行で、実際にREQコマンドはRFUに出されない。

      lman.param[0] = gRfuLinkStatus->linkLossSlot_flag;
      rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED, 1);
      return;

    case LMAN_STATE_POLL_LINK_RECOVERY:
    case LMAN_STATE_END_LINK_RECOVERY:
      lman.state = LMAN_STATE_END_LINK_RECOVERY;
      break;

      // others
    default:
      lman.state = lman.next_state = LMAN_STATE_READY;
      msg = LMAN_MSG_MANAGER_STOPPED;
      break;
  }

  if (lman.state == LMAN_STATE_READY) {  // リンクマネージャーが即停止可能な場合は、停止後にLMANコールバック発生。
    rfu_LMAN_occureCallback(msg, 0);     // LMANコールバック発生
  }
}

static u8 rfu_LMAN_linkWatcher(u16 REQ_commandID) {
  u8 i, bm_linkLossSlot, reason, bm_linkRecoverySlot, bm_disconnectSlot;
  u8 disconnect_occure_flag = 0;

  //----------------------------------
  // 【親子共通】RFU-APIのリンクウォッチを実行
  //----------------------------------
  rfu_REQBN_watchLink(REQ_commandID, &bm_linkLossSlot, &reason, &bm_linkRecoverySlot);

  //----------------------------------
  // 【親子共通】リンク切れ検出 ＆ リンク復旧タイマー起動 ＆ リンク復旧不可の接続を切断
  //----------------------------------
  if (bm_linkLossSlot) {
    lman.param[0] = bm_linkLossSlot;
    lman.param[1] = reason;

    // リンク復旧がONの時
    if (lman.linkRecovery_enable) {                        // リンク復旧がONの時は、リンク復旧処理を開始する。
      lman.linkRecovery_start_flag = LINK_RECOVERY_START;  // 基本はリンク復旧スタート
      if ((lman.parent_child == MODE_CHILD) && (reason == REASON_DISCONNECTED)) {
        lman.linkRecovery_start_flag = LINK_RECOVERY_IMPOSSIBLE;  // 子機でかつリンク切れ原因が「切断」の時は、リンク復旧不可能なので、DISCONNECTする。
      }
      // リンク復旧可能か？
      if (lman.linkRecovery_start_flag == LINK_RECOVERY_START) {
        for (i = 0; i < RFU_CHILD_MAX; i++) {  // リンク復旧に入った場合は、リンク復旧待ちタイマーを起動する
          if (bm_linkLossSlot & (0x01 << i)) {
            lman.linkRecoveryTimer.active |= (0x01 << i);
            lman.linkRecoveryTimer.count[i] = lman.linkRecoveryTimer.count_max;
          }
        }
        rfu_LMAN_occureCallback(LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY,
                                1);  // LMANコールバック発生 param0=bm_linkLossSlot
      } else {                       // LINK_RECOVERY_IMPOSSIBLE
        lman.linkRecovery_start_flag = LINK_RECOVERY_OFF;
        rfu_LMAN_disconnect(bm_linkLossSlot);  // リンク復旧不可能な場合は、DISCONNECTしてリンク復旧失敗を通知する。
        disconnect_occure_flag = 1;
        rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED,
                                1);  // LMANコールバック発生 param0=bm_linkLossSlot
      }
    } else {
      // リンク復旧がOFFの時は、完全にDISCONNECTする。
      rfu_LMAN_disconnect(bm_linkLossSlot);
      disconnect_occure_flag = 1;
      rfu_LMAN_occureCallback(LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED, 2);
    }

    rfu_LMAN_managerChangeAgbClockMaster();  // 子機がAGBクロックスレーブの時はAGBクロックマスターに戻す。
  }

  //------------------------------
  // 【親機のみ】リンク復旧待ち処理 ＆ リンク復旧待ち期限切れの接続を切断
  //------------------------------
  if (gRfuLinkStatus->parent_child == MODE_PARENT) {
    // リンク復旧の検出
    if (bm_linkRecoverySlot) {
      for (i = 0; i < RFU_CHILD_MAX; i++) {  // リンク復旧を検出したスロットの復旧待ちタイマーの停止
        if ((lman.linkRecoveryTimer.active & (0x01 << i)) && (bm_linkRecoverySlot & (0x01 << i))) lman.linkRecoveryTimer.count[i] = 0;
      }
      lman.linkRecoveryTimer.active &= ~bm_linkRecoverySlot;

      lman.param[0] = bm_linkRecoverySlot;
      rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_SUCCESSED, 1);  // LMANコールバック発生 param0=bm_linkReocverySlot
    }

    // リンク復旧タイマーのカウントダウンおよびリンク復旧待ち期限切れの接続を切断
    if (lman.linkRecoveryTimer.active) {
      bm_disconnectSlot = 0;
      for (i = 0; i < RFU_CHILD_MAX; i++) {
        if (lman.linkRecoveryTimer.active & (0x01 << i)) {
          if (lman.linkRecoveryTimer.count[i]) {  // count値が"0"の時は無限にリンク復旧を待つ。
            if (--lman.linkRecoveryTimer.count[i] == 0) {
              lman.linkRecoveryTimer.active &= ~(0x01 << i);
              bm_disconnectSlot |= 0x01 << i;
            }
          }
        }
      }
      if (bm_disconnectSlot) {  // リンク復旧待ちタイマー期限切れのスロットはDISCONNECTする。
        rfu_LMAN_disconnect(bm_disconnectSlot);
        disconnect_occure_flag = 1;
        lman.param[0] = bm_disconnectSlot;
        rfu_LMAN_occureCallback(LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED,
                                1);  // LMANコールバック発生 param0=bm_linkLossSlot
      }
    }

    if (lman.linkRecoveryTimer.active == 0) {
      lman.linkRecovery_start_flag = LINK_RECOVERY_OFF;
    }
  }

  return disconnect_occure_flag;  // 切断を行った場合は、その旨をリターンする。（リンクマネージャー側で、それ以降のREQ-API実行を行わない。）
}

void rfu_LMAN_syncVBlank() {
  if (rfu_syncVBlank()) {  // rfu_LMAN_syncVBlankで検出したウォッチドッグタイマーエラーをここでユーザーに通知する。
    rfu_LMAN_occureCallback(LMAN_MSG_WATCH_DOG_TIMER_ERROR, 0);
    rfu_LMAN_managerChangeAgbClockMaster();  // ver.1.0.12sp追加　クロックスレーブ時はクロックマスターに戻す。
  }
}

void rfu_LMAN_manager_entity(u32 rand) {
  u8 msg;

  if (((u32)lman.LMAN_callback == 0x00000000) && (lman.state)) {
    lman.state = LMAN_STATE_READY;  // ※ver.1.0.11sp追加　リンクマネージャーの初期設定が終了していないのに、リンクマネージャーを動作した時は、リンクマネージャーを停止してリターンする。
    return;
  }

  if (lman.pcswitch_flag)  // ※2003.10.30 ver.1.0.10追加
    rfu_LMAN_settingPCSWITCH(rand);

  while (1) {  // ※2003.07.22 ver.1.0.5追加
    if (lman.state != LMAN_STATE_READY) {
      rfu_waitREQComplete();  // 現在他のREQコマンドが実行中の場合はその終了を待つ。

      lman.active = 1;  // activeフラグを１にしてREQコマンドを実行することで、通常のユーザー発行のREQコマンドの実行と区別する。

      switch (lman.state) {
        case LMAN_FORCED_STOP_AND_RFU_RESET:
          if (rfu_LMAN_REQBN_softReset_and_checkID() == RFU_ID) {
            msg = LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET;
          } else {
            msg = LMAN_MSG_RFU_FATAL_ERROR;
          }
          lman.state = lman.next_state = LMAN_STATE_READY;
          rfu_LMAN_occureCallback(msg, 0);  // LMANコールバック発生
          break;

        case LMAN_STATE_SOFT_RESET_AND_CHECK_ID:
          if (rfu_LMAN_REQBN_softReset_and_checkID() == RFU_ID) {
            lman.state = lman.next_state;
            lman.next_state = LMAN_STATE_CONFIG_SYSTEM;
          } else {
            lman.state = lman.next_state = LMAN_STATE_READY;
            rfu_LMAN_occureCallback(LMAN_MSG_RFU_FATAL_ERROR, 0);  // LMANコールバック発生
          }
          break;
        case LMAN_STATE_RESET:
          rfu_REQ_reset();
          break;
        case LMAN_STATE_CONFIG_SYSTEM:
          rfu_REQ_configSystem(lman.init_param->availSlot_flag, lman.init_param->maxMFrame, lman.init_param->MC_TimerCount);
          break;
        case LMAN_STATE_CONFIG_GAME_DATA:
          rfu_REQ_configGameData(lman.init_param->mboot_flag, lman.init_param->serialNo, lman.init_param->gameName, lman.init_param->userName);
          break;
        case LMAN_STATE_START_SEARCH_CHILD:
          rfu_REQ_startSearchChild();
          break;
        case LMAN_STATE_POLL_SEARCH_CHILD:
          rfu_REQ_pollSearchChild();
          break;
        case LMAN_STATE_END_SEARCH_CHILD:
          rfu_REQ_endSearchChild();
          break;
        case LMAN_STATE_START_SEARCH_PARENT:
          rfu_REQ_startSearchParent();
          break;
        case LMAN_STATE_POLL_SEARCH_PARENT:
          rfu_REQ_pollSearchParent();
          break;
        case LMAN_STATE_END_SEARCH_PARENT:
          rfu_REQ_endSearchParent();
          break;
        case LMAN_STATE_START_CONNECT_PARENT:
          rfu_REQ_startConnectParent(lman.work);
          break;
        case LMAN_STATE_POLL_CONNECT_PARENT:
          rfu_REQ_pollConnectParent();
          break;
        case LMAN_STATE_END_CONNECT_PARENT:
          rfu_REQ_endConnectParent();
          break;
        case LMAN_STATE_START_LINK_RECOVERY:
          rfu_REQ_CHILD_startConnectRecovery(gRfuLinkStatus->linkLossSlot_flag);
          break;
        case LMAN_STATE_POLL_LINK_RECOVERY:
          rfu_REQ_CHILD_pollConnectRecovery();
          break;
        case LMAN_STATE_END_LINK_RECOVERY:
          rfu_REQ_CHILD_endConnectRecovery();
          break;
        case LMAN_STATE_MS_CHANGE:
          rfu_REQ_changeMasterSlave();
          break;
        case LMAN_STATE_STOP_MODE:
          rfu_REQ_stopMode();
          break;
        default:  // リンクマネージャーがREQコマンドを実行する状態でない時はアクティブフラグを０にする。
          break;
      }
      rfu_waitREQComplete();

      lman.active = 0;  // リンクマネージャー内のREQコマンド実行完了でactiveフラグを０にする。
    }

    if ((lman.state == LMAN_STATE_END_LINK_RECOVERY) || (lman.state == LMAN_STATE_MS_CHANGE)) {
      // ※2003.07.22 ver.1.0.5追加　リンク復旧終了とAGBクロックスレーブ化だけは一気に実行する。
    } else {
      break;
    }
  }
  // ver.1.0.8
  // entity最後部に移動。rfu_LMAN_linkWatcherもしくはrfu_LMAN_PARENT_checkRecvChildNameによる子機切断直後にSC_POLLが実行されると、RFUの処理が追いつかずにACK_REJECTIONエラーになってします。
  if (gRfuLinkStatus->parent_child == MODE_PARENT) {  // ver.1.0.8追加	リンク監視をリンクマネージャー内に取り込み。
    if (rfu_LMAN_linkWatcher(0x0000))                 // ver.1.0.12sp変更
                                                      // リンクマネージャーで切断を行った際には、その後の処理を行わずにリターンする。
      return;
  }
  rfu_LMAN_PARENT_checkRecvChildName();  // 親機動作における、子機からのゲーム識別情報の受信判定
  rfu_LMAN_CHILD_checkSendChildName();   // 子機動作における、親機へのゲーム識別情報の送信判定
  rfu_LMAN_CHILD_linkRecoveryProcess();  // 子機におけるリンク復旧処理の起動をここでチェックする。
  rfu_LMAN_checkNICommunicateStatus();   // NI送受信ステータスを参照して、通信対象の絞り込みを行う。 ver.1.0.4追加
}

static void rfu_LMAN_settingPCSWITCH(u32 rand) {
  // 第3SC期間の開始設定
  if (lman.pcswitch_flag == PCSWITCH_3RD_SC_START) {
    lman.parent_child = MODE_PARENT;
    lman.state = LMAN_STATE_START_SEARCH_CHILD;
    lman.connect_period = lman.pcswitch_period_bak;
    //		lman.pcswitch_period_bak=0;			// 4TH_SPの追加で、ここが０クリアされるとまずい。

    if (lman.connect_period) {
      lman.pcswitch_flag = PCSWITCH_3RD_SC;
    } else {
      lman.pcswitch_flag = PCSWITCH_1ST_SC_START;  // 第3SC期間が0なら、第1SC期間の開始へ
    }
  }
  // 第1SC期間の開始設定
  if (lman.pcswitch_flag == PCSWITCH_1ST_SC_START) {  // ここでは、ランダム値をもとに第1SC期間および第3SC期間の算出
    lman.parent_child = MODE_PARENT;
    lman.state = LMAN_STATE_START_SEARCH_CHILD;
    lman.connect_period = rand % (PCSWITCH_ALL_PERIOD - PCSWITCH_SP_PERIOD);                      // 第1SC期間は、0 <= x <= (全体周期-SP期間）
    lman.pcswitch_period_bak = (PCSWITCH_ALL_PERIOD - PCSWITCH_SP_PERIOD) - lman.connect_period;  // 第3SC期間は、0 <= x <= (全体周期-SP期間-第1SC期間）

    if (lman.connect_period) {
      lman.pcswitch_flag = PCSWITCH_1ST_SC;
    } else {
      lman.pcswitch_flag = PCSWITCH_2ND_SP_START;  // 第1SC期間が0なら、第2SP期間の開始へ
    }
  }
  // 第2SP期間の開始設定
  if (lman.pcswitch_flag == PCSWITCH_2ND_SP_START) {  // 第2SP期間は固定期間。
    lman.parent_child = MODE_CHILD;
    lman.connect_period = PCSWITCH_SP_PERIOD;
    lman.pcswitch_flag = PCSWITCH_2ND_SP;
    lman.state = LMAN_STATE_START_SEARCH_PARENT;
  }
}

static void rfu_LMAN_REQ_callback(u16 REQ_commandID, u16 REQ_result) {
  u8 i, status, *STWI_buffp;

  //----------------------------------------------
  // リンクマネージャーが実行したREQ-APIの結果処理
  //----------------------------------------------
  if (lman.active) {
    lman.active = 0;  // LMANコールバック中でユーザーがDISCONNECTした時にLMAN_MSG_LINK_DISCONNECTED_BY_USERがきちんと発生するように一時的にlman.activeを０にする。

    switch (REQ_commandID) {  // ※このswitchの中で直接returnしては駄目。lman.activeの復帰が行われない

        // INITIALIZE

      case ID_RESET_REQ:
        if (REQ_result == 0) {  // lman.acceptSlot_flagとlman.childClockSlave_flagのクリアは後ろのif(REQ_result==0){}の中で行っている。
          lman.state = lman.next_state;
          lman.next_state = LMAN_STATE_CONFIG_GAME_DATA;
        }
        break;

      case ID_SYSTEM_CONFIG_REQ:
        if (REQ_result == 0) {
          lman.state = lman.next_state;
          lman.next_state = LMAN_STATE_READY;
        }
        break;

      case ID_GAME_CONFIG_REQ:
        if (REQ_result == 0) {
          lman.state = lman.next_state = LMAN_STATE_READY;

          rfu_LMAN_occureCallback(LMAN_MSG_INITIALIZE_COMPLETED, 0);  // LMANコールバック発生
        }
        break;

        // SEARCH CHILD

      case ID_SC_START_REQ:
        if (REQ_result == 0) {
          lman.state = lman.next_state = LMAN_STATE_POLL_SEARCH_CHILD;
        }
        break;

      case ID_SC_POLL_REQ:
        if (lman.connect_period) {  // connect_period==0の時は無期限でSC_POLLを実行
          if (--lman.connect_period == 0) {
            lman.state = LMAN_STATE_END_SEARCH_CHILD;
            lman.next_state = LMAN_STATE_WAIT_RECV_CHILD_NAME;
          }
        }
        break;

      case ID_SC_END_REQ:
        if (REQ_result == 0) {
          lman.state = lman.next_state;
          lman.next_state = LMAN_STATE_READY;                                  // connect_period経過、もしくはリンクマネージャー停止によりサーチ動作が終了したら、REQコールバックを発生させる。
          if (lman.pcswitch_flag == 0) {                                       // 親子切り替えサーチモードでないときのみ、コールバック発生。
            rfu_LMAN_occureCallback(LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED, 0);  // LMANコールバック発生
          }
        }
        break;

        // SEARCH PARENT

      case ID_SP_START_REQ:
        if (REQ_result == 0) {
          if ((lman.fastSearchParent_flag == FSP_ON) && (lman.connect_period > 1)) {
            lman.connect_period--;  // ver.1.0.7sp追加
          }
          lman.state = lman.next_state = LMAN_STATE_POLL_SEARCH_PARENT;
        }
        break;

      case ID_SP_POLL_REQ:
        if (REQ_result == 0) {
          // 有効な親機の抽出およびLMANコールバックでの通知
          status = rfu_LMAN_CHILD_checkEnableParentCandidate();
          lman.param[0] = status;
          //				if(gRfuLinkStatus->findParentCount)
          if (status) {                                         // ver.1.0.7変更　有効な（所望するゲームシリアル№である）親機が存在する時のみLMANメッセージ通知を行う。
            rfu_LMAN_occureCallback(LMAN_MSG_PARENT_FOUND, 1);  // LMANコールバック発生 param0=enable_parent_slot (specified bit)
          }
          if ((lman.fastSearchParent_flag) && (lman.connect_period != 1)) {  // ver.1.0.81sp追加　lman.connect_period==1の時はSPを終了させない。
            if (gRfuLinkStatus->findParentCount == RFU_CHILD_MAX) {          // ファーストサーチONの時は、今回発見した親機が４台だったら、一旦サーチを終了して、サーチを再度やり直す。
              rfu_REQ_endSearchParent();
              rfu_waitREQComplete();
              lman.state = LMAN_STATE_START_SEARCH_PARENT;
              lman.fastSearchParent_flag = FSP_ON;
            }
          }
        }
        if (lman.connect_period) {  // connect_period==0の時は、無期限でSP_POLLを実行
          if (--lman.connect_period == 0) {
            lman.state = LMAN_STATE_END_SEARCH_PARENT;
            lman.next_state = LMAN_STATE_READY;
          }
        }
        break;

      case ID_SP_END_REQ:
        if (REQ_result == 0) {
          lman.state = lman.next_state;  // 次のステートへ。	通常：STATE_READYへ, rfu_LMAN_startConnectParent実行時：STATE_START_CONNECT_PARENTへ。
          if (lman.pcswitch_flag == 0) {
            if (lman.state == LMAN_STATE_READY)                                   // connect_period経過、もしくはリンクマネージャー停止によりサーチ動作が終了したら、REQコールバックを発生させる。
              rfu_LMAN_occureCallback(LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED, 0);  // LMANコールバック発生
          } else if (lman.pcswitch_flag != PCSWITCH_CP) {
            lman.state = LMAN_STATE_START_SEARCH_CHILD;
            lman.pcswitch_flag = PCSWITCH_3RD_SC_START;
          }
        }
        break;

        // CONNECT PARENT

      case ID_CP_START_REQ:
        if (REQ_result == 0) {
          lman.state = lman.next_state = LMAN_STATE_POLL_CONNECT_PARENT;
        }
        break;

      case ID_CP_POLL_REQ:
        if (REQ_result == 0) {
          if (rfu_getConnectParentStatus(&status, &lman.child_slot) == 0) {
            if (status == CP_STATUS_DONE)  // 「接続成功」を検出したら、ConnectParent終了
              lman.state = LMAN_STATE_END_CONNECT_PARENT;
          }
        }
        if (lman.connect_period) {         // connect_period==0の時は無期限でCP_POLLを実行
          if (--lman.connect_period == 0)  // 接続処理期限切れの場合、ConnectParent終了
            lman.state = LMAN_STATE_END_CONNECT_PARENT;
        }
        break;

      case ID_CP_END_REQ:
        if (REQ_result == 0) {
          if (rfu_getConnectParentStatus(&status, &lman.child_slot) == 0) {  // 接続処理の最終判定
            if (status == CP_STATUS_DONE) {                                  // 「接続成功」
              lman.state = LMAN_STATE_MS_CHANGE;
              lman.next_state = LMAN_STATE_SEND_CHILD_NAME;
              lman.work = LMAN_MSG_CONNECT_PARENT_SUCCESSED;
              lman.param[0] = lman.child_slot;
            } else {                                            // FAILED
              lman.state = lman.next_state = LMAN_STATE_READY;  // 「接続失敗」
              lman.work = LMAN_MSG_CONNECT_PARENT_FAILED;
              lman.param[0] = status;

              if (lman.pcswitch_flag) {                      // ver.1.0.12sp変更（子機状態に戻る）
                lman.pcswitch_flag = PCSWITCH_2ND_SP_START;  // 親子切り替えモード時の時は、接続失敗後は再度親子切り替えモードに戻る。
                lman.state = LMAN_STATE_START_SEARCH_PARENT;
              }
            }
            rfu_LMAN_occureCallback(lman.work, 1);  // LMANコールバック発生	SUCCESS:param0=child connect slot (slotNo) FAIL:param0=connect parent status
            lman.work = 0;
          }
        }
        break;

        // LINK RECOVERY

      case ID_CPR_START_REQ:
        if (REQ_result == 0) {
          lman.param[0] = gRfuLinkStatus->linkLossSlot_flag;  // lman.param[0]にリンク復旧を開始したスロットを格納する。
          lman.state = lman.next_state = LMAN_STATE_POLL_LINK_RECOVERY;
          for (lman.child_slot = 0; lman.child_slot < RFU_CHILD_MAX; lman.child_slot++)  // child_slotの再算出
            if (gRfuLinkStatus->linkLossSlot_flag & (0x01 << lman.child_slot))           // 一台の子機が複数スロットの接続を持っていた場合のリンク復旧タイマーは、接続スロット番号の最小のものが使用される。
              break;
        }
        break;

      case ID_CPR_POLL_REQ:
        if (REQ_result == 0) {
          if (rfu_CHILD_getConnectRecoveryStatus(&status) == 0) {
            if ((status == RC_STATUS_DONE) || (status == RC_STATUS_FAILED))  // リンク復旧成功もしくはリンク復旧失敗確定の場合
              lman.state = LMAN_STATE_END_LINK_RECOVERY;
          }
        }
        if (lman.linkRecoveryTimer.count[lman.child_slot]) {                                                    // linkRecoveryTimer.count==0の時は無期限でCPR_POLLを実行
          if (--lman.linkRecoveryTimer.count[lman.child_slot] == 0) lman.state = LMAN_STATE_END_LINK_RECOVERY;  // リンク復旧期限切れ
        }
        break;

      case ID_CPR_END_REQ:
        if (REQ_result == 0) {
          if (rfu_CHILD_getConnectRecoveryStatus(&status) == 0) {
            if (status == RC_STATUS_DONE) {       // リンク復旧成功
              lman.state = LMAN_STATE_MS_CHANGE;  // リンク復旧に成功したら、AGBをクロックスレーブにした後に、元のステートに復帰する。
              lman.next_state = LMAN_STATE_BACK_STATE;
              lman.work = LMAN_MSG_LINK_RECOVERY_SUCCESSED;
            } else {
              lman.state = lman.next_state = LMAN_STATE_READY;         // リンク復旧に失敗した時は、元のステートに復帰する。
              rfu_LMAN_disconnect(gRfuLinkStatus->linkLossSlot_flag);  // リンク復旧に失敗したスロットを切断。
              lman.work = LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED;
            }

            lman.linkRecoveryTimer.count[lman.child_slot] = 0;  // リンク復旧タイマーのクリア
            lman.linkRecoveryTimer.active = 0;
            lman.linkRecovery_start_flag = LINK_RECOVERY_OFF;
            rfu_LMAN_occureCallback(lman.work, 1);  // LMANコールバック発生
            lman.work = 0;
          }
        }
        break;

        // OTHERS

      case ID_MS_CHANGE_REQ:
        if (REQ_result == 0) {
          if (lman.next_state == LMAN_STATE_BACK_STATE) {
            lman.state = lman.state_bak[0];
            lman.next_state = lman.state_bak[1];
            lman.childClockSlave_flag = RFU_CHILD_CLOCK_SLAVE_ON;
            rfu_LMAN_occureCallback(LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE, 0);  // LMANコールバック発生
          } else if (lman.next_state == LMAN_STATE_SEND_CHILD_NAME) {
            lman.state = lman.next_state;
            lman.childClockSlave_flag = RFU_CHILD_CLOCK_SLAVE_ON;
            rfu_LMAN_occureCallback(LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE, 0);  // LMANコールバック発生

            // 子機のゲームネーム送信設定を行う。
            lman.nameAcceptTimer.active |= 0x01 << lman.child_slot;
            lman.nameAcceptTimer.count[lman.child_slot] = lman.nameAcceptTimer.count_max;
            rfu_clearSlot(TYPE_NI_SEND, lman.child_slot);
            status = rfu_NI_CHILD_setSendGameName(lman.child_slot, 14);
            if (status) {
              lman.state = lman.next_state = LMAN_STATE_READY;  // ver.1.0.10sp変更　名前送信失敗時には切断する。
              rfu_LMAN_managerChangeAgbClockMaster();           // AGBクロックマスターに戻す。
              rfu_LMAN_disconnect(gRfuLinkStatus->connectSlot_flag | gRfuLinkStatus->linkLossSlot_flag);
              lman.param[0] = status;
              rfu_LMAN_occureCallback(LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED, 1);
              // LMANコールバック発生	param0=send setting function error code
            }
          }
        }
        break;

      case ID_DISCONNECT_REQ:
        break;

      case ID_STOP_MODE_REQ:
        if (REQ_result == 0) {  // lman.acceptSlot_flagとlman.childClockSlave_flagのクリアは後ろのif(REQ_result==0){}の中で行っている。
          lman.state = lman.next_state = LMAN_STATE_READY;
          rfu_LMAN_occureCallback(LMAN_MSG_RFU_POWER_DOWN, 0);  // LMANコールバック発生
        }
        break;

      default:
        break;
    }

    lman.active = 1;  // lman.activeフラグの復帰

  } else {                                                                                                                  // lman.active==0
    if ((REQ_result == ERR_REQ_CMD_ACK_REJECTION) && (lman.msc_exe_flag)) {                                                 // ver.1.0.3追加 MSCコールバック内でRFUがリンク切れと判断した場合のエラー検出を追加
      if ((REQ_commandID == ID_DATA_TX_REQ) || (REQ_commandID == ID_DATA_RX_REQ) || (REQ_commandID == ID_MS_CHANGE_REQ)) {  // MSCコールバック内で実行される可能性のある上記REQ-APIがACK_REJECTIONなら、RFUのステートを確認して、NEUTRALステートだったら「リンク切れ」と判定する。
        rfu_REQ_RFUStatus();                                                                                                // RFUステータスの取得
        rfu_waitREQComplete();
        rfu_getRFUStatus(&status);
        if ((status == 0) && (gRfuLinkStatus->parent_child == MODE_CHILD)) {  // RFUステータスがNEUTRALで、かつAGB側がRFUはまだCHILDだと判断しているならリンク切れとさせる
          STWI_buffp = rfu_getSTWIRecvBuffer() + 4;
          *STWI_buffp++ = gRfuLinkStatus->connectSlot_flag;  // ※強制的にリンク切れと判断させるために、かなり無茶をしている。
          *STWI_buffp = REASON_LINK_LOSS;                    // （RFUからID_DISCONNECTED_AND_CHANGE_REQがあったかのように見せかけている）
          rfu_LMAN_linkWatcher(ID_DISCONNECTED_AND_CHANGE_REQ);
          REQ_result = 0;  // REQ-APIエラーを消す。
        }
      }
    }
  }

  //----------------------------------------------
  // 誰が実行したかに関係なく行うREQ-APIの結果処理
  //----------------------------------------------
  switch (REQ_commandID) {
    case ID_DISCONNECT_REQ:
      if (REQ_result == 0) {                                 // ver.1.0.10sp変更
        lman.param[0] = *(rfu_getSTWIRecvBuffer() + 8);      // rfu_REQ_disconnect実行時にこのアドレスに切断されたスロットが格納されている。
        rfu_LMAN_reflectCommunicationStatus(lman.param[0]);  // 切断スロットをNI,UNI通信ステータスに反映させる。

        // リンク復旧中のスロットがDISCONNECTされた場合は、それを停止する。
        if (lman.linkRecoveryTimer.active) {  // ver.1.0.11sp追加
          lman.linkRecoveryTimer.active &= ~lman.param[0];
          for (i = 0; i < RFU_CHILD_MAX; i++) {
            if (lman.param[0] & (0x01 << i)) {
              lman.linkRecoveryTimer.count[i] = 0;
            }
          }
          if (lman.parent_child == MODE_CHILD) {  // 子機の場合はリンクマネージャーも停止する。
            lman.state = lman.next_state = LMAN_STATE_READY;
          }
        }

        // 接続認証子機スロットのクリア。（lman.acceptSlot_flagとacceptCountを落とす。）
        status = lman.acceptSlot_flag & lman.param[0];
        for (i = 0; i < RFU_CHILD_MAX; i++) {
          if ((status & (0x01 << i)) && (lman.acceptCount > 0)) {  // acceptされているスロットが切断されていたら、acceptCountを減らす。
            lman.acceptCount--;
          }
        }
        lman.acceptSlot_flag &= ~lman.param[0];

        // pcswitch_flagがONの時は親子切り替えサーチを再開する。
        if (lman.pcswitch_flag) {  // ver.1.0.12sp追加
          if (gRfuLinkStatus->parent_child == MODE_NEUTRAL) {
            if (lman.pcswitch_flag == PCSWITCH_SC_LOCK) {  // 親子切り替えがSC_LOCKの場合はSC_POLLから再開。
              lman.connect_period = lman.pcswitch_period_bak;
              lman.pcswitch_flag = PCSWITCH_3RD_SC;
              lman.state = LMAN_STATE_POLL_SEARCH_CHILD;
            } else {
              if ((lman.state != LMAN_STATE_POLL_SEARCH_CHILD) && (lman.state != LMAN_STATE_END_SEARCH_CHILD)) {
                lman.pcswitch_flag = PCSWITCH_1ST_SC_START;  // そうでない場合は、SC状態でなければ親子切り替えの最初から動作させる。
                lman.state = LMAN_STATE_START_SEARCH_CHILD;
              }
            }
          }
        }

        if ((gRfuLinkStatus->parent_child == MODE_NEUTRAL) && (lman.state == 0)) {  // RFUがニュートラルに戻って、リンクマネージャーも停止していたら、リンクマネージャーもニュートラルへ。
          lman.parent_child = MODE_NEUTRAL;
        }

        if (lman.active == 0) {  // ユーザーによる切断の場合は、LMANコールバック発生
          rfu_LMAN_occureCallback(LMAN_MSG_LINK_DISCONNECTED_BY_USER, 1);
        }
      }
      break;

    case ID_DATA_RX_REQ:                     // ※2003.09.09 ver.1.0.6追加 データ受信コマンド完了時にLMANコールバック発生
      rfu_LMAN_CHILD_checkSendChildName2();  // ver.1.0.12sp追加　子機のゲーム識別情報送信結果の判定を行う。

      if (gRfuLinkStatus->parent_child != MODE_NEUTRAL) {              // これは上の名前送信成功通知コールバックの中で切断が行われた場合に受信成功コールバックを発生させないことで、次に続くrfu_REQ_sendDataを実行させないようにしたもの。
        rfu_LMAN_occureCallback(LMAN_MSG_RECV_DATA_REQ_COMPLETED, 0);  // データ受信成功通知を行う。
      }
      break;

    case ID_RESET_REQ:
    case ID_STOP_MODE_REQ:
      // リセットもしくはストップモード化によるlman.acceptSlotのオールクリア	// ※ver.1.0.10sp追加
      if (REQ_result == 0) {
        lman.acceptSlot_flag = lman.acceptCount = lman.reserveDisconnectSlot_flag = 0;
        lman.parent_child = MODE_NEUTRAL;
        rfu_LMAN_managerChangeAgbClockMaster();  // クロックスレーブ時はクロックマスターに戻す。

        if (REQ_commandID == ID_STOP_MODE_REQ) {  // ver.1.0.11sp追加 RFUをパワーダウンしたら、マネージャーを全クリアして終了する。
          rfu_LMAN_endManager();
        }
      }
      break;

    default:
      break;
  }

  //----------------------------------------------
  // REQ-API実行エラー通知
  //----------------------------------------------
  if (REQ_result) {  // リンクマネージャーもしくはユーザーによるREQ-API実行でエラーが発生した時は、その旨を通知する。
    // REQ-API実行エラー通知
    if ((REQ_commandID == ID_SP_START_REQ) && (REQ_result)) {  // ver.1.0.12sp RFUのハードバグ対策
      if (lman.pcswitch_flag == PCSWITCH_2ND_SP) {             // 親子切り替えサーチ字のSC_END時に「子機接続なし」とRFUが返していても、実はRFU内部ではPARENTになっている時がある。
        gRfuLinkStatus->parent_child = MODE_PARENT;            // このままSP_STARTを実行すると、ERR_CMD_ACK_REJECTIONになるので、内部でこれを検出したら全スロット切断を行ってそのまま進行させる。
        gRfuLinkStatus->connectSlot_flag = 0x0f;
        rfu_LMAN_disconnect(0x0f);
        rfu_waitREQComplete();
        return;
      }
    }

    lman.param[0] = REQ_commandID;
    lman.param[1] = REQ_result;
    if (lman.active) lman.state = lman.next_state = LMAN_STATE_READY;  // ver.1.0.5追加　LinkManagerが実行したREQ-APIエラー時はリンクマネージャー停止

    rfu_LMAN_occureCallback(LMAN_MSG_REQ_API_ERROR, 2);  // LMANコールバック発生	param0=REQ_commandID	param1=REQ_result
    rfu_LMAN_managerChangeAgbClockMaster();              // 子機でクロックスレーブ時はクロックマスターに戻す。
  }
  // 自動起動DMAによるRFUエラー発生の通知
  if (REQ_commandID == ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ) {  // ver.1.0.7追加　H-DMA、サウンドDMA等の自動起動DMAによって
    rfu_LMAN_occureCallback(LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA, 0);
    rfu_LMAN_managerChangeAgbClockMaster();  // ver.1.0.12sp追加
  }
}

static void rfu_LMAN_MSC_callback(u16 REQ_commandID) {
  u8 active_bak, thisAck_flag;

  active_bak = lman.active;
  lman.active = 0;  // rfu_LMAN_sequencer_entity上でMSCコールバックが発生した場合を考慮して、MSCコールバック上ではリンクマネージャーは有効でないとする。
  lman.msc_exe_flag = 1;

  // 子機の場合は、リンクウォッチを行い、AGBクロックスレーブOFF要求にも応える。
  if (gRfuLinkStatus->parent_child == MODE_CHILD) {  // ※2003.10.24 ver.1.0.8追加	リンク監視をリンクマネージャー内に取り込み。
    rfu_LMAN_linkWatcher(REQ_commandID);

    if (lman.childClockSlave_flag != RFU_CHILD_CLOCK_SLAVE_ON) {
      rfu_LMAN_managerChangeAgbClockMaster();  // RFU_CHILD_CLOCK_SLAVE_OFF_REQの時は、OFFにしてコールバック通知。
      lman.msc_exe_flag = 0;
      lman.active = active_bak;
      return;
    }
  } else {  // if(gRfuLinkStatus->parent_child==MODE_PARENT)
    if (rfu_UNI_PARENT_getDRAC_ACK(&thisAck_flag) == 0) {
      lman.parentAck_flag |= thisAck_flag;  // ACKフラグをlman変数に保持する。
    }
  }

  // MSCコールバックは登録されている時しか動作しない。
  if ((u32)lman.MSC_callback) {
    lman.MSC_callback(REQ_commandID);
    rfu_waitREQComplete();

    // MSCコールバック内でAGBクロックスレーブOFF要求がきた場合はここで応える。
    if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_OFF_REQ) {
      rfu_LMAN_managerChangeAgbClockMaster();  // RFU_CHILD_CLOCK_SLAVE_OFF_REQの時は、OFFにしてコールバック通知。
    }
  }

  lman.msc_exe_flag = 0;
  lman.active = active_bak;
}

static void rfu_LMAN_PARENT_checkRecvChildName() {
  u8 i, tgtSlot, newConnectSlot, flags, newAcceptSlot;
  u16* acceptableSerialNo;

  // 親機による子機サーチ状態でなければリターン。
  if ((lman.state < LMAN_STATE_START_SEARCH_CHILD) || (lman.state > LMAN_STATE_WAIT_RECV_CHILD_NAME)) return;

  // 新しいRFUレベルの接続の検出
  newConnectSlot = (gRfuLinkStatus->connectSlot_flag ^ lman.connectSlot_flag_old) & gRfuLinkStatus->connectSlot_flag;
  newConnectSlot &= ~gRfuLinkStatus->getName_flag;  // ~getName_flagでマスクしないと、リンク復旧した子機も新しい接続として検出してしまう。
  lman.connectSlot_flag_old = gRfuLinkStatus->connectSlot_flag;
  if (newConnectSlot) {  // 新しいRFUレベルでの接続を検出したらLMANコールバック発生
    lman.param[0] = newConnectSlot;
    rfu_LMAN_occureCallback(LMAN_MSG_NEW_CHILD_CONNECT_DETECTED, 1);  // LMANコールバック発生	param0=newConnectSlot (specified bit)
  }

  // 各子機からのゲームネーム受信状態のチェック
  newAcceptSlot = 0;
  for (i = 0; i < RFU_CHILD_MAX; i++) {
    tgtSlot = 0x01 << i;
    flags = 0;

    // リンク復旧ではない新しい接続を検出したならば、そのスロットのネーム受信タイマーを起動する
    if (newConnectSlot & tgtSlot) {
      lman.nameAcceptTimer.count[i] = lman.nameAcceptTimer.count_max;
      lman.nameAcceptTimer.active |= tgtSlot;
    } else if (lman.nameAcceptTimer.active & tgtSlot) {
      // ゲームネーム受信状態のチェック
      if (gRfuSlotStatusNI[i]->recv.state == SLOT_STATE_RECV_SUCCESS) {
        if (gRfuSlotStatusNI[i]->recv.dataType == 0x01) {  // ネームを受信した	dataType:0x01=DATA_TYPE_GAME_NAME
          flags |= RN_NAME_TIMER_CLEAR;

          // 接続してきた子機のゲームシリアル№のチェックを行い、アプリケーションレベルでのリンク受け入れを行う
          acceptableSerialNo = lman.acceptable_serialNo_list;
          while (*acceptableSerialNo != 0xffff) {
            if (gRfuLinkStatus->partner[i].serialNo == *acceptableSerialNo) {
              lman.acceptSlot_flag |= tgtSlot;  // ver.1.0.10sp 追加
              lman.acceptCount++;

              newAcceptSlot |= tgtSlot;
              flags |= RN_ACCEPT;
              break;
            }
            acceptableSerialNo++;
          }

          if ((flags & RN_ACCEPT) == 0) flags |= RN_DISCONNECT;
        }
      } else if (--lman.nameAcceptTimer.count[i] == 0) {  // ネーム受信タイマータイムアウト
        flags |= RN_NAME_TIMER_CLEAR | RN_DISCONNECT;
      }

      if (flags & RN_NAME_TIMER_CLEAR) {
        lman.nameAcceptTimer.active &= ~tgtSlot;
        lman.nameAcceptTimer.count[i] = 0;
        rfu_clearSlot(TYPE_NI_RECV, i);  // 通信スロットをクリアする。
      }
      if (flags & RN_DISCONNECT) {
        lman.reserveDisconnectSlot_flag |= tgtSlot;
      }
    }
  }

  // 接続を受け入れた子機を通知する。
  if (newAcceptSlot) {
    lman.param[0] = newAcceptSlot;
    rfu_LMAN_occureCallback(LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED, 1);  // LMANコールバック発生	param0=newAcceptSlot (specified bit)
  }

  // 接続を拒否した子機を強制切断する。								// ver.1.0.17変更
  if (lman.reserveDisconnectSlot_flag) {  // 接続を拒否してDISCONNECTした子機をLMANコールバックで通知
    flags = 1;
    if (gRfuLinkStatus->sendSlot_UNI_flag) {  // UNIデータ送信中は、有効な全メンバーからのACKを取得している時のみDISCONNECT可能とする。
      if ((lman.parentAck_flag & lman.acceptSlot_flag) != lman.acceptSlot_flag) {
        flags = 0;
      }
    }
    if (flags) {  // 接続認証に失敗した子機のDISCONNECT
      rfu_LMAN_disconnect(lman.reserveDisconnectSlot_flag);
      lman.param[0] = lman.reserveDisconnectSlot_flag;
      lman.reserveDisconnectSlot_flag = 0;
      rfu_LMAN_occureCallback(LMAN_MSG_NEW_CHILD_CONNECT_REJECTED, 1);
    }
  }

  // 子機サーチ終了後の名前受信猶予期間が終了したかどうかのチェックを行い、その後の動作に移行する。
  if ((lman.nameAcceptTimer.active == 0) && (lman.state == LMAN_STATE_WAIT_RECV_CHILD_NAME)) {
    // ver.1.0.10sp 2003.10.30追加 親子切り替えサーチ動作の追加
    if (lman.pcswitch_flag == 0) {  // 親子切り替えがOFFなら、マネージャー停止
      lman.state = lman.next_state = LMAN_STATE_READY;
      rfu_LMAN_occureCallback(LMAN_MSG_END_WAIT_CHILD_NAME, 0);
    } else {                                        // 親子切り替えがONなら、サーチモードを切り替える。
      if (lman.pcswitch_flag == PCSWITCH_1ST_SC) {  // 第1SC期間終了時は、第2SP期間へ
        lman.pcswitch_flag = PCSWITCH_2ND_SP_START;
        lman.state = LMAN_STATE_START_SEARCH_PARENT;
      } else {  // lman.pcswitch_flag==PCSWITCH_3RD_SC				// 第3SC期間終了時は、第1SC期間へ
        lman.pcswitch_flag = PCSWITCH_1ST_SC_START;
        lman.state = LMAN_STATE_START_SEARCH_CHILD;
      }

      if (lman.acceptSlot_flag) {  // サーチ切り替え時に、親機状態になっていたならば、親子切り替えを停止し、無期限で子機サーチを行うよう変化する。
        lman.connect_period = 0;   // ver.1.0.12sp　if文をrfuLinkStatus->parent_child==MODE_PARENTから今の形に変更。
        lman.pcswitch_flag = PCSWITCH_SC_LOCK;
        lman.state = LMAN_STATE_START_SEARCH_CHILD;
      }
    }
  }
}

static void rfu_LMAN_CHILD_checkSendChildName(void) {
  u16 imeBak = REG_IME;
  REG_IME = 0;
  if (lman.state == LMAN_STATE_SEND_CHILD_NAME) {
    if (--lman.nameAcceptTimer.count[lman.child_slot] == 0 || gRfuSlotStatusNI[lman.child_slot]->send.state == SLOT_STATE_SEND_FAILED) {
      rfu_LMAN_requestChangeAgbClockMaster();
      lman.state = LMAN_STATE_WAIT_CHANGE_CLOCK_MASTER;
      rfu_clearSlot(TYPE_NI_SEND, lman.child_slot);
      lman.nameAcceptTimer.active &= ~(1 << lman.child_slot);
      lman.nameAcceptTimer.count[lman.child_slot] = 0;
    }
  }
  REG_IME = imeBak;
  if (lman.state == LMAN_STATE_WAIT_CHANGE_CLOCK_MASTER) {
    if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_ON) {
      rfu_LMAN_requestChangeAgbClockMaster();
    }
    if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_OFF) {
      lman.state = lman.next_state = LMAN_STATE_READY;
      rfu_LMAN_disconnect(gRfuLinkStatus->connectSlot_flag | gRfuLinkStatus->linkLossSlot_flag);
      lman.param[0] = 0;
      rfu_LMAN_occureCallback(LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED, 1);
    }
  }
}

static void rfu_LMAN_CHILD_checkSendChildName2() {
  // ゲーム識別情報の送信成功判定およびその通知。
  if (lman.state == LMAN_STATE_SEND_CHILD_NAME) {
    if (gRfuSlotStatusNI[lman.child_slot]->send.state == SLOT_STATE_SEND_SUCCESS) {
      lman.state = lman.next_state = LMAN_STATE_READY;
      rfu_clearSlot(TYPE_NI_SEND, lman.child_slot);
      lman.nameAcceptTimer.active &= ~(0x01 << lman.child_slot);
      lman.nameAcceptTimer.count[lman.child_slot] = 0;
      rfu_LMAN_occureCallback(LMAN_MSG_CHILD_NAME_SEND_COMPLETED, 0);  // LMANコールバック発生
    }
  }
}

static void rfu_LMAN_CHILD_linkRecoveryProcess() {
  if (lman.parent_child != MODE_CHILD) return;
  if (lman.linkRecovery_start_flag == LINK_RECOVERY_START) {
    lman.state_bak[0] = lman.state;  // ※MSCコールバック内でlman.stateを変えると、メインループ上の関数との整合性がとれなくなるので、変更はリンクマネージャーentity上で行うようにする。
    lman.state_bak[1] = lman.next_state;
    lman.state = LMAN_STATE_START_LINK_RECOVERY;
    lman.next_state = LMAN_STATE_POLL_LINK_RECOVERY;
    lman.linkRecovery_start_flag = LINK_RECOVERY_EXE;
  }
}

static u8 rfu_LMAN_CHILD_checkEnableParentCandidate() {
  u8 i, enableParentSlot;
  u16* serialNo;

  // lman.accaptable_serialNo_listに一致する親機候補をビットで返す。
  enableParentSlot = 0;
  for (i = 0; i < gRfuLinkStatus->findParentCount; i++) {
    serialNo = lman.acceptable_serialNo_list;
    while (*serialNo != 0xffff) {
      if (gRfuLinkStatus->partner[i].serialNo == *serialNo) enableParentSlot |= 0x01 << i;
      serialNo++;
    }
  }
  return enableParentSlot;
}

void rfu_LMAN_occureCallback(u8 msg, u8 param_count) {
  if (lman.LMAN_callback) lman.LMAN_callback(msg, param_count);
  lman.param[0] = lman.param[1] = 0;
}

void rfu_LMAN_disconnect(u8 bm_disconnectSlot) {
  u8 active_bak;

  active_bak = lman.active;
  lman.active = 1;
  rfu_REQ_disconnect(bm_disconnectSlot);
  rfu_waitREQComplete();
  lman.active = active_bak;
}

void rfu_LMAN_reflectCommunicationStatus(u8 bm_disconnectedSlot) {
  u8 i;

  // NI,UNI通信を行っている場合は、その送受信対象から切断子機を除く
  if (gRfuLinkStatus->sendSlot_NI_flag) {
    for (i = 0; i < RFU_CHILD_MAX; i++) {
      if ((gRfuSlotStatusNI[i]->send.state & SLOT_BUSY_FLAG)  // NI送信対象から切断子機を除く
          && (gRfuSlotStatusNI[i]->send.bmSlot & bm_disconnectedSlot)) {
        rfu_changeSendTarget(TYPE_NI, i, gRfuSlotStatusNI[i]->send.bmSlot & (~bm_disconnectedSlot));
      }
    }
  }
  if (gRfuLinkStatus->recvSlot_NI_flag) {
    for (i = 0; i < RFU_CHILD_MAX; i++) {
      if ((gRfuSlotStatusNI[i]->recv.state & SLOT_BUSY_FLAG)  // 切断子機からのNI受信を停止する
          && (gRfuSlotStatusNI[i]->recv.bmSlot & bm_disconnectedSlot)) {
        rfu_NI_stopReceivingData(i);
      }
    }
  }
  if (gRfuLinkStatus->sendSlot_UNI_flag) {
    gRfuLinkStatus->sendSlot_UNI_flag &= (~bm_disconnectedSlot);

    for (i = 0; i < RFU_CHILD_MAX; i++) {
      if ((gRfuSlotStatusUNI[i]->send.state == SLOT_STATE_SEND_UNI)  // UNI送信対象から切断子機を除く
          && (gRfuSlotStatusUNI[i]->send.bmSlot & bm_disconnectedSlot)) {
        gRfuSlotStatusUNI[i]->send.bmSlot &= (~bm_disconnectedSlot);
      }
    }
  }
}

void rfu_LMAN_checkNICommunicateStatus() {
  u8 i, x, sendFailSlot;

  if (lman.NI_failCounter_limit == 0)  // NI通信期限が無期限ならリターン
    return;

  // NI送信のfailCounterチェック
  if (gRfuLinkStatus->sendSlot_NI_flag) {
    for (i = 0; i < RFU_CHILD_MAX; i++) {
      if (gRfuSlotStatusNI[i]->send.state & SLOT_BUSY_FLAG) {
        sendFailSlot = 0;
        for (x = 0; x < RFU_CHILD_MAX; x++) {
          if (gRfuSlotStatusNI[i]->send.bmSlot & (0x01 << x)) {
            if (gRfuSlotStatusNI[x]->send.failCounter > lman.NI_failCounter_limit) sendFailSlot |= 0x01 << x;
          }
          if (sendFailSlot) {
            rfu_changeSendTarget(TYPE_NI, i, gRfuSlotStatusNI[i]->send.bmSlot ^ sendFailSlot);
          }  // 送信の場合は送信対象の絞り込みを行う
        }
      }
    }
  }

  // NI受信のfailCounterチェック
  if (gRfuLinkStatus->recvSlot_NI_flag) {
    for (i = 0; i < RFU_CHILD_MAX; i++) {
      if (gRfuSlotStatusNI[i]->recv.state & SLOT_BUSY_FLAG) {
        if (gRfuSlotStatusNI[i]->recv.failCounter > lman.NI_failCounter_limit) rfu_NI_stopReceivingData(i);  // 受信の場合は対象が１台だけなので即受信停止。
      }
    }
  }
}

// リンクマネージャー使用時のMSCコールバックの設定を行います。MSCコールバックの指定は、rfu_LMAN_initializeManagerでも行えますので、本関数は再設定を行いたい場合に使用します。
void rfu_LMAN_setMSCCallback(void (*MSC_callback_p)(u16)) {
  lman.MSC_callback = MSC_callback_p;         // ユーザー定義のMSCコールバック関数を設定
  rfu_setMSCCallback(rfu_LMAN_MSC_callback);  // リンクマネージャー用MSCコールバックルーチンのセット
}

// リンクマネージャー使用時のLMANコールバックの設定を行います。LMANコールバックの指定は、rfu_LMAN_initializeManagerでも行えますので、本関数は再設定を行いたい場合に使用します。
void rfu_LMAN_setLMANCallback(void (*LMAN_callback_p)(u8, u8)) { lman.LMAN_callback = LMAN_callback_p; }

// リンクマネージャー使用時のリンク復旧動作の設定を行います。リンク復旧動作の設定は、rfu_LMAN_initializeRFUのinit_parameters内でも行えますので、本関数は再設定を行いたい場合に使用します。
u8 rfu_LMAN_setLinkRecovery(u8 enable_flag, u16 recovery_period) {
  u16 imeBak;
  if (lman.linkRecovery_enable && enable_flag == 0 && lman.linkRecoveryTimer.active) {
    return LMAN_ERROR_NOW_LINK_RECOVERY;
  }
  imeBak = REG_IME;
  REG_IME = 0;
  lman.linkRecovery_enable = enable_flag;
  lman.linkRecoveryTimer.count_max = recovery_period;
  REG_IME = imeBak;
  return 0;
}

// リンクマネージャー使用時のNIデータ通信のfailCounter期限を再設定します。NI通信時に通信ステータスのfailCounter値が本関数で設定された値に達すると、その通信対象は通信から除外されます。なお、NIデータ通信のfailCounter期限の設定は、rfu_LMAN_initializeRFUのinit_parameters内でも行えますので、本関数は再設定を行いたい場合に使用します。
u8 rfu_LMAN_setNIFailCounterLimit(u16 NI_failCounter_limit) {
  if (gRfuLinkStatus->sendSlot_NI_flag | gRfuLinkStatus->recvSlot_NI_flag) {  // 現在通信中なら、エラー通知して再設定は行わない。
    lman.param[0] = LMAN_ERROR_NOW_COMMUNICATION;
    rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
    return LMAN_ERROR_NOW_COMMUNICATION;
  }
  lman.NI_failCounter_limit = NI_failCounter_limit;
  return 0;
}

// リンクマネージャー使用時の子機による親機サーチ時のファーストサーチ動作のON/OFF設定を行います。本動作の設定は、rfu_LMAN_initializeRFUのinit_parameters内でも行えますので、本関数は再設定を行いたい場合に使用します。
u8 rfu_LMAN_setFastSearchParent(u8 enable_flag) {
  if ((lman.state == LMAN_STATE_START_SEARCH_PARENT) || (lman.state == LMAN_STATE_POLL_SEARCH_PARENT) || (lman.state == LMAN_STATE_END_SEARCH_PARENT)) {  // 現在SearchParent中なら、エラーを返して設定は行わない。
    lman.param[0] = LMAN_ERROR_NOW_SEARCH_PARENT;
    rfu_LMAN_occureCallback(LMAN_MSG_LMAN_API_ERROR_RETURN, 1);
    return LMAN_ERROR_NOW_SEARCH_PARENT;
  }
  if (enable_flag) {
    lman.fastSearchParent_flag = FSP_ON;
  } else {
    lman.fastSearchParent_flag = 0;
  }
  return 0;
}

// リンクマネージャー使用時に、リンク切れ等によって、子機がAGBクロックスレーブを継続できなくなった際に、AGBをクロックマスターに切り替えて、メッセージを通知する。
static void rfu_LMAN_managerChangeAgbClockMaster() {
  if (lman.childClockSlave_flag != RFU_CHILD_CLOCK_SLAVE_OFF) {  // 子機でクロックスレーブ時はクロックマスターに戻す。
    lman.childClockSlave_flag = RFU_CHILD_CLOCK_SLAVE_OFF;
    rfu_LMAN_occureCallback(LMAN_MSG_CHANGE_AGB_CLOCK_MASTER, 0);
  }
}

// リンクマネージャー使用時に、子機がAGBクロックスレーブになっている時に、AGBクロックマスターに戻るよう要求。
void rfu_LMAN_requestChangeAgbClockMaster() {
  if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_OFF) {
    rfu_LMAN_occureCallback(LMAN_MSG_CHANGE_AGB_CLOCK_MASTER, 0);
  } else if (lman.childClockSlave_flag == RFU_CHILD_CLOCK_SLAVE_ON) {
    lman.childClockSlave_flag = RFU_CHILD_CLOCK_SLAVE_OFF_REQ;
  }
}

// 親子切り替えサーチ時に接続を行おうとする際に、強制的に一定時間SPを行わせる
void rfu_LMAN_forceChangeSP(void) {
  if (lman.pcswitch_flag) {
    switch (lman.state) {
      case LMAN_STATE_START_SEARCH_CHILD:
        lman.pcswitch_flag = PCSWITCH_2ND_SP_START;
        lman.state = LMAN_STATE_START_SEARCH_PARENT;
        break;
      case LMAN_STATE_POLL_SEARCH_CHILD:
        lman.pcswitch_flag = PCSWITCH_1ST_SC;
        lman.connect_period = 1;
        break;
      case LMAN_STATE_END_SEARCH_CHILD:
      case LMAN_STATE_WAIT_RECV_CHILD_NAME:
        lman.pcswitch_flag = PCSWITCH_1ST_SC;
        break;
      case LMAN_STATE_START_SEARCH_PARENT:
      case LMAN_STATE_POLL_SEARCH_PARENT:
        lman.connect_period = PCSWITCH_SP_PERIOD;
        break;
      case LMAN_STATE_END_SEARCH_PARENT:
        lman.connect_period = PCSWITCH_SP_PERIOD;
        lman.state = LMAN_STATE_POLL_SEARCH_PARENT;
        break;
    }
  }
}
