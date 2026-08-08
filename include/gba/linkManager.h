#ifndef __INCLUDE_GBA_LINKMANAGER_H__
#define __INCLUDE_GBA_LINKMANAGER_H__

#include "gba/agbrfu.h"
#include "gba/types.h"

// リンクマネージャーの動作モード(rfu_LMAN_establishConnectionの引数u8 parent_childで指定）
// #define MODE_CHILD									0		//
// CHILDモードでリンクマネージャーを起動 #define MODE_PARENT
// 1		// PARENTモードでリンクマネージャーを起動 ※この値は、AgbRFU_LL.hで定義されているものを使用します。
#define MODE_P_C_SWITCH 2  // 親子切り替えモードでリンクマネージャーを起動

// リンクマネージャーAPIによって返されるエラーコード（rfu_LMAN_...関数の返り値）
#define LMAN_ERROR_MANAGER_BUSY 1       // リンクマネージャーが既に動作中。
#define LMAN_ERROR_AGB_CLK_SLAVE 2      // AGBがクロックスレーブの為、リンクマネージャーを動作できない。
#define LMAN_ERROR_PID_NOT_FOUND 3      // 指定されたPIDの親機情報がrfuLinkStatus->partner[0-3]に存在しない。
#define LMAN_ERROR_ILLEGAL_PARAMETER 4  // 指定された引数が異常。
#define LMAN_ERROR_NOW_LINK_RECOVERY 5  // 現在リンク復旧ONで、新しい設定がリンク復旧OFFとされた時、リンク復旧が動作中のため新しい設定は無視された。
#define LMAN_ERROR_NOW_COMMUNICATION 6  // 現在NI通信中なので、新しい設定を無視した。
#define LMAN_ERROR_NOW_SEARCH_PARENT 7  // 現在SearchParent中なので、新しい設定を無視した。

// リンクマネージャーの動作によって発生するLMANコールバックの引数u8 msg, u8
// param_countおよびlman.param[0-1]で返されるメッセージおよびそれに付随するパラメーターの内容
//		msg名											msg番号	param数
// param[0] param[1]	説明
#define LMAN_MSG_INITIALIZE_COMPLETED \
  0x00  //	0		-				-
        // RFUのリセットおよび初期設定が完了した時に発生
#define LMAN_MSG_NEW_CHILD_CONNECT_DETECTED \
  0x10  //	1	接続を検出した		-		RFUレベルでの新しい子機の接続を検出した際に発生。
        //		スロットをビットで示す
#define LMAN_MSG_NEW_CHILD_CONNECT_ACCEPTED \
  0x11  //	1	接続を受け入れた	-
        // RFUレベルで接続されている子機からゲーム識別情報を受信し、それの受け入れ判定が成功した際（ゲームシリアル№一致）に発生。
        //		スロットをビットで示す
#define LMAN_MSG_NEW_CHILD_CONNECT_REJECTED \
  0x12                                             //	1	接続を拒否した		-
                                                   // RFUレベルで接続されている子機からの接続受け入れ判定が失敗（ゲーム識別情報の受信失敗もしくはゲームシリアル№不一致）し、その接続を切断した時に発生。
                                                   //		スロットをビットで示す
#define LMAN_MSG_SEARCH_CHILD_PERIOD_EXPIRED 0x13  //	0		-				-		SearchChild動作期間が終了した時に発生。
#define LMAN_MSG_END_WAIT_CHILD_NAME \
  0x14  //	0		-				-
        // SearchChild動作期間が終了した後、全ての子機からのゲーム識別情報の受信が終了した時に発生。
#define LMAN_MSG_PARENT_FOUND \
  0x20  //	1	発見した親機のうち	-
        // SearchParent動作中に有効な（ゲームシリアル№が一致する）親機を発見した時に発生。
//      有効な親機（ゲームシリアル№一致）が格納されているrfuLinkStatus->partner[x]のインデックス番号をビットで示す
#define LMAN_MSG_SEARCH_PARENT_PERIOD_EXPIRED 0x21  //	0		-				-		SearchParent期間が終了した時に発生。
#define LMAN_MSG_CONNECT_PARENT_SUCCESSED 0x22      //	1	接続スロット番号	-		RFUレベルでの親機との接続が成功した時に発生。
#define LMAN_MSG_CONNECT_PARENT_FAILED 0x23         //	1	接続失敗理由		-		RFUレベルでの親機との接続が失敗した時に発生。
#define LMAN_MSG_CHILD_NAME_SEND_COMPLETED \
  0x24  //	0		-				-
        // RFUレベルでの親機との接続が成功した後に、自身のゲーム識別情報を親機に送信完了した時に発生。
#define LMAN_MSG_CHILD_NAME_SEND_FAILED_AND_DISCONNECTED \
  0x25  //	0		-				-
        // RFUレベルでの親機との接続が成功した後に、自身のゲーム識別情報を親機に送信失敗した時に発生。
#define LMAN_MSG_LINK_LOSS_DETECTED_AND_DISCONNECTED \
  0x30  //	1	リンク切れを検出し	-
        // リンク切れを検出し、そのスロットをDISCONNECTした時に発生。（リンク復旧がOFFの時のみ発生）
        //      リンク復旧を行わずにDISCONNECTしたスロットをビットで示す
#define LMAN_MSG_LINK_LOSS_DETECTED_AND_START_RECOVERY \
  0x31  //	1	リンク切れを検出し	-
        // リンク切れを検出し、リンク復旧処理を開始した時に発生。（リンク復旧がONの時のみ発生）
        //      リンク復旧を開始したスロットをビットで示す
#define LMAN_MSG_LINK_RECOVERY_SUCCESSED \
  0x32  //	1	リンク復旧が成功	-
        // リンク復旧が成功した時に発生。（リンク復旧がONの時のみ発生）
        //      したスロットをビットで示す
#define LMAN_MSG_LINK_RECOVERY_FAILED_AND_DISCONNECTED \
  0x33  //	1	リンク復旧が失敗	-
        // リンク復旧が失敗し、そのスロットをDISCONNECTした時に発生。（リンク復旧がONの時のみ発生）
        //      し、DISCONNECTしたスロットをビットで示す
#define LMAN_MSG_LINK_DISCONNECTED_BY_USER \
  0x40  //	1	DISCONNECTした		-
        // ユーザーによるrfu_REQ_disconnectの実行によって接続がDISCONNECTされた時に発生。
        //      スロットをビットで示す
//      ※子機において、リンク復旧中にrfu_REQ_disconnectで切断を行った場合は、リンク復旧も停止しますが、メッセージはこのDISCONNECTED_BY_USERしか返りませんのでご注意下さい。
#define LMAN_MSG_CHANGE_AGB_CLOCK_SLAVE \
  0x41  //	0		-				-
        // 子機において、接続成功後や、リンク復旧成功後に、AGB-RFU間のクロックをAGBクロックスレーブに切り替えた際に発生。（MSCコールバックの終了時に行われるAGBクロックスレーブ化においては、本メッセージは発生しません。）
#define LMAN_MSG_CHANGE_AGB_CLOCK_MASTER \
  0x45  //	0		-				-
        // 子機において、AGB-RFU間のクロックがAGBクロックマスターに切り替わった際に発生します。
#define LMAN_MSG_RFU_POWER_DOWN \
  0x42  //	0		-				-
        // rfu_LMAN_powerDownRFUによってRFUが省電力モードに入った際に発生。
#define LMAN_MSG_MANAGER_STOPPED \
  0x43  //	0		-				-
        // rfu_LMAN_stopLMAN(0)によってリンクマネージャーが停止された時に発生。（但し、SearchChild, SearchParent,
        // ConnectParent, LinkRecovery時は、それぞれの動作終了に対応したメッセージ（〜PERIOD_EXPIRED, 〜SUCCESSED,
        // 〜FAILED)が返され、本メッセージは返されません。）
#define LMAN_MSG_MANAGER_FORCED_STOPPED_AND_RFU_RESET \
  0x44  //	0		-				-
        // rfu_LMAN_stopLMAN(1)によってリンクマネージャーが強制的に停止され、RFUがリセットされたときに発生。

#define LMAN_MSG_RECV_DATA_REQ_COMPLETED \
  0x50  //	2		-				-
        // rfu_REQ_recvDataの実行が完了した場合に発生。（※本メッセージは、RFUからのデータ受信を通知するものではありません。）

#define LMAN_MSG_REQ_API_ERROR \
  0xf0  //	2	REQ_commandID	REQ_result
        // REQ-APIがエラーとなった。リンクマネージャーおよびユーザーのどちらが実行したREQ-APIについても本メッセージが発生。
#define LMAN_MSG_WATCH_DOG_TIMER_ERROR \
  0xf1  //  0		-				-
        //  AGBがクロックスレーブになっている時に6秒が経過してもMSCコールバックが発生しなかった場合に発生。
#define LMAN_MSG_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA \
  0xf2                                       //  0		-				-
                                             //  AGBがクロックスレーブの時に、RFUが情報通知と共にAGBをクロックマスターに戻そうとした瞬間にHDMA等の自動起動DMAが発生して、その情報（REQコマンド）のやりとりに失敗した時に発生。
#define LMAN_MSG_LMAN_API_ERROR_RETURN 0xf3  //  1	リターンエラーコード			-		LMAN-APIの実行がエラーリターンとなった際に発生。
#define LMAN_MSG_RFU_FATAL_ERROR \
  0xff  //	0		-				-
        // リンクマネージャーがrfu_REQBN_softReset_and_checkIDの実行でRFUを認識できなかった時に発生。

// lman.childClockSlave_flagの値
#define RFU_CHILD_CLOCK_SLAVE_OFF 0      // 子機はAGBクロックスレーブモードで動作していない。（子機は接続が確立していなかったり、リンク復旧中の場合は、このモードになります。）
#define RFU_CHILD_CLOCK_SLAVE_ON 1       // 子機はAGBクロックスレーブモードで動作している。 （子機は接続が確立した時点で、自動的にこのモードになります。）
#define RFU_CHILD_CLOCK_SLAVE_OFF_REQ 2  // 子機はAGBクロックスレーブモードの終了を要求していいる。

// リンクマネージャーのステート（lman.state, lman.next_stateの値）
#define LMAN_STATE_READY 0x00                     // 待機中
#define LMAN_STATE_SOFT_RESET_AND_CHECK_ID 0x01   // rfu_REQBN_softResetAndCheckID 実行要求中（以下同）
#define LMAN_STATE_RESET 0x02                     // rfu_REQ_reset
#define LMAN_STATE_CONFIG_SYSTEM 0x03             // rfu_REQ_configSystem
#define LMAN_STATE_CONFIG_GAME_DATA 0x04          // rfu_REQ_configGameData
#define LMAN_STATE_START_SEARCH_CHILD 0x05        // rfu_REQ_startSearchChild
#define LMAN_STATE_POLL_SEARCH_CHILD 0x06         // rfu_REQ_pollSearchChild
#define LMAN_STATE_END_SEARCH_CHILD 0x07          // rfu_REQ_endSearchChild
#define LMAN_STATE_WAIT_RECV_CHILD_NAME 0x08      // 接続子機からのゲームネーム受信待ち状態
#define LMAN_STATE_START_SEARCH_PARENT 0x09       // rfu_REQ_startSearchParent
#define LMAN_STATE_POLL_SEARCH_PARENT 0x0a        // rfu_REQ_pollSearchParent
#define LMAN_STATE_END_SEARCH_PARENT 0x0b         // rfu_REQ_endSearchParent
#define LMAN_STATE_START_CONNECT_PARENT 0x0c      // rfu_REQ_startConnectParent
#define LMAN_STATE_POLL_CONNECT_PARENT 0x0d       // rfu_REQ_pollConnectParent
#define LMAN_STATE_END_CONNECT_PARENT 0x0e        // rfu_REQ_endConnectParent
#define LMAN_STATE_SEND_CHILD_NAME 0x0f           // 子機のゲームネーム送信中
#define LMAN_STATE_START_LINK_RECOVERY 0x10       // rfu_REQ_CHILD_startConnectRecovery
#define LMAN_STATE_POLL_LINK_RECOVERY 0x11        // rfu_REQ_CHILD_pollConnectRecovery
#define LMAN_STATE_END_LINK_RECOVERY 0x12         // rfu_REQ_CHILD_endConnectRecovery
#define LMAN_STATE_MS_CHANGE 0x13                 // rfu_REQ_changeMasterSlave
#define LMAN_STATE_WAIT_CLOCK_MASTER 0x14         // AGB-RFU間のクロックがAGBクロックマスターになるのを待っている状態
#define LMAN_STATE_STOP_MODE 0x15                 // rfu_REQ_stopMode
#define LMAN_STATE_BACK_STATE 0x16                // リンク復旧処理の終了後に、リンクマネージャーのステートをリンク復旧処理開始前の状態に戻す
#define LMAN_FORCED_STOP_AND_RFU_RESET 0x17       // rfu_LMAN_stopLMAN(1)によってリンクマネージャーが強制停止されようとしている状態
#define LMAN_STATE_WAIT_CHANGE_CLOCK_MASTER 0x18  // 子機がゲームネーム送信に失敗して、AGBクロックマスターに戻そうとしているところ。

// --------------------------------------------

// リンクマネージャーの初期設定動作（rfu_LMAN_initializeRFU）で使用するパラメータ群
typedef struct InitializeParametersTag {
  // rfu_REQ_configSystemの引数
  u8 maxMFrame;        // RFUレベルの最大再送回数
  u8 MC_TimerCount;    // MC_Timerのカウント数（×16.7ms）
  u16 availSlot_flag;  // 親機における接続可能な子機の最大数1〜4台をRFU-API定数「AVAIL_SLOT1〜4」で指定。※子機の場合は常にAVAIL_SLOT4を指定して下さい。

  // rfu_REQB_configGameDataの引数
  u8 mboot_flag;  // マルチブートフラグ
  u16 serialNo;   // ゲームシリアル№
  u8* gameName;   // ゲームネーム
  u8* userName;   // ユーザーネーム

  // 子機のファースト親機サーチ動作のON/OFFフラグ
  u8 fastSearchParent_flag;  // 子機の親機ファーストサーチ動作を行うかどうか

  // リンクリカバリー設定
  u8 linkRecovery_enable;   // リンク切れ発生時にリンク復旧処理を行うかどうか
  u16 linkRecovery_period;  // リンク復旧処理に費やす期間（×16.7ms）※0を指定することで、無期限に動作。

  // NI型データ送受信期限の設定
  u16 NI_failCounter_limit;  // NI型データ送受信時のfailCounterの期限（×16.7ms） ※0を指定することで、無期限に動作。
} INIT_PARAM;

// Vブランク周期でカウントされるタイマー
typedef struct VblankTimerTag {
  u8 active;                 // 0x00, タイマーのON/OFF（各接続スロット毎にbit0-3でON/OFFを示す）
  u16 count_max;             // 0x02, カウントの最大値（×16.7ms）
  u16 count[RFU_CHILD_MAX];  // 0x04, 各接続スロットに対応した現在のカウント値（×16.7ms）
} VBL_TIMER;

// リンクマネージャーのステータス
typedef struct linkManagerTag {
  u8 acceptSlot_flag;                             // リンクマネージャーが接続を受け入れた子機の接続スロットをビットで示す。（リンク切れ状態ではこのビットは落ちず、完全な切断によって落ちる。）
  u8 acceptCount;                                 // リンクマネージャーが接続を受け入れた子機の数
  vu8 childClockSlave_flag;                       // 現在子機側でAGBクロックスレーブ状態が維持されているかを示すフラグ。
  vu8 parentAck_flag;                             // 親機のUNI通信でどの子機からACKを受け取っているかを示すフラグ。
  u8 state;                                       // 現在のリンクマネージャーのステート
  u8 next_state;                                  // 次にリンクマネージャーがコールされた際に移行するリンクマネージャーのステート
  u8 parent_child;                                // 親／子のいずれで動作しているかを示す
  u8 pcswitch_flag;                               // 親子切り替えサーチ動作フラグ
  u8 RFU_powerOn_flag;                            // RFUがパワーダウンしているかどうかを示すフラグ。
  u8 linkRecovery_enable;                         // リンク復旧処理のON/OFFフラグ
  u8 linkRecovery_start_flag;                     // リンク復旧起動フラグ
  u8 fastSearchParent_flag;                       // 子機の親機ファーストサーチ動作のON/OFFフラグ
  u8 connectSlot_flag_old;                        // 前回リンクマネージャーがコールされた際のrfuLinkStatus->connectSlot_flagの値(API内部で使用）
  u8 reserveDisconnectSlot_flag;                  // 子機接続認証でREJECTされ、切断待ちになっている子機のスロットをビットで示す。
  u8 active;                                      // リンクマネージャー動作中フラグ（API内部で使用）
  u8 msc_exe_flag;                                // MSCコールバック実行中フラグ（API内部で使用）
  u8 child_slot;                                  // 子機が接続したスロット番号（API内部で使用）
  u8 state_bak[2];                                // リンクマネージャーステートのbackup（API内部で使用）
  u16 param[2];                                   // LMANコールバック発生時に返されるパラメーターが格納されている領域。
  u16 NI_failCounter_limit;                       // NI型データ送受信時のfailCounterの期限（×16.7ms）　※0を指定することで、無期限に動作
  u16 connect_period;                             // 接続処理をどれだけの期間行うかのカウント数（×16.7ms）。※ 0を指定することで、無期限に動作する。
  u16 pcswitch_period_bak;                        // 親子切り替えサーチ時の第3SC期間のバックアップ
  u16 work;                                       // リンクマネージャーが使用するワーク領域
  u16* acceptable_serialNo_list;                  // 接続受け入れ可能なゲームシリアル№のリスト（※１）
  VBL_TIMER nameAcceptTimer;                      // 子機からのゲームネーム受信期限タイマー
  VBL_TIMER linkRecoveryTimer;                    // 親子共のリンク復旧処理期限タイマー ※ 0を指定することで、無期限に動作する。
  INIT_PARAM* init_param;                         // 初期設定処理を行う際のパラメータへのポインタ
  void (*LMAN_callback)(u8 msg, u8 param_count);  // リンクマネージャー動作によって発生するユーザー定義のLMANコールバックルーチンへのポインタ
  void (*MSC_callback)(u16 REQ_commandID);        // ユーザー定義のMSCコールバック関数。（リンクマネージャー定義時には、rfu_setMSCCallbackは用いず、rfu_LMAN_initializeManagerもしくはrfu_LMAN_setMSCCallbackを用いてMSCコールバックを定義します。
} LINK_MANAGER;                                   // 72 Bytes

extern LINK_MANAGER lman;

// 必ず使用する関数群
// RFU-APIのパック
u32 rfu_LMAN_REQBN_softReset_and_checkID();
void rfu_LMAN_REQ_sendData(u8 clockChange_flag);
// API初期化
u8 rfu_LMAN_initializeManager(void (*LMAN_callback_p)(u8, u8), void (*MSC_callback_p)(u16));
// 常駐関数
void rfu_LMAN_manager_entity(u32 rand);
void rfu_LMAN_syncVBlank();
// リンクマネージャーへの要求
void rfu_LMAN_initializeRFU(INIT_PARAM* init_parameters);
void rfu_LMAN_powerDownRFU();
u8 rfu_LMAN_establishConnection(u8 parent_child, u16 connect_period, u16 name_accept_period, u16* acceptable_serialNo_list);
u8 rfu_LMAN_CHILD_connectParent(u16 pid, u16 connect_period);
void rfu_LMAN_stopManager(u8 forced_stop_and_rfu_reset);
void rfu_LMAN_requestChangeAgbClockMaster(void);

// ユーザーが必要に応じて使用する関数。
void rfu_LMAN_setLMANCallback(void (*LMAN_callback_p)(u8, u8));
void rfu_LMAN_setMSCCallback(void (*MSC_callback_p)(u16));

#endif  // __INCLUDE_GBA_LINKMANAGER_H__
