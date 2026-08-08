#ifndef __INCLUDE_GBA_AGBRFU_H__
#define __INCLUDE_GBA_AGBRFU_H__

// pret's librfu.h
// AgbRFU_xx

#include "gba/defines.h"

#define LIBRFU_VERSION 1024

// REQコールバックで返されるREQコマンドID
#define ID_RESET_REQ 0x0010
#define ID_LINK_STATUS_REQ 0x0011
#define ID_VERSION_STATUS_REQ 0x0012  // not defined in SDK header
#define ID_SYSTEM_STATUS_REQ 0x0013
#define ID_SLOT_STATUS_REQ 0x0014    // not defined in SDK header
#define ID_CONFIG_STATUS_REQ 0x0015  // not defined in SDK header
#define ID_GAME_CONFIG_REQ 0x0016
#define ID_SYSTEM_CONFIG_REQ 0x0017
#define ID_SC_START_REQ 0x0019
#define ID_SC_POLL_REQ 0x001a
#define ID_SC_END_REQ 0x001b
#define ID_SP_START_REQ 0x001c
#define ID_SP_POLL_REQ 0x001d
#define ID_SP_END_REQ 0x001e
#define ID_CP_START_REQ 0x001f
#define ID_CP_POLL_REQ 0x0020
#define ID_CP_END_REQ 0x0021
#define ID_DATA_TX_REQ 0x0024
#define ID_DATA_TX_AND_CHANGE_REQ 0x0025
#define ID_DATA_RX_REQ 0x0026
#define ID_MS_CHANGE_REQ 0x0027  // 本IDは、REQコールバックで返される時は、rfu_REQ_changeMasterSlaveの実行完了を意味します。
#define ID_DISCONNECT_REQ 0x0030
#define ID_TEST_MODE_REQ 0x0031  // not defined in SDK header
#define ID_CPR_START_REQ 0x0032
#define ID_CPR_POLL_REQ 0x0033
#define ID_CPR_END_REQ 0x0034
#define ID_UNK35_REQ 0x0035  // not defined in SDK header
#define ID_UNK36_REQ 0x0036  // not defined in SDK header
#define ID_RESUME_RETRANSMIT_AND_CHANGE_REQ 0x0037
#define ID_STOP_MODE_REQ 0x003d
#define ID_CLOCK_SLAVE_MS_CHANGE_ERROR_BY_DMA_REQ 0x00ff  // 本IDは、AGBがクロックスレーブの時に、RFUが情報通知と共にAGBをクロックマスターに戻そうとした瞬間にHDMA等の自動起動DMAが発生して、その情報（REQコマンド）のやりとりに失敗した時にREQコールバックで通知されます。

// MSCコールバックで返されるREQコマンドID
#define ID_DISCONNECTED_AND_CHANGE_REQ 0x0029
#define ID_DATA_READY_AND_CHANGE_REQ 0x0028
#define ID_DRAC_REQ_WITH_ACK_FLAG 0x0128

// --------------------------------------------------------------------------
//
// データ定義
//
// --------------------------------------------------------------------------

#define RFU_ID 0x00008001  // AGB-RFUの機器ID番号 rfu_REQBN_softReset_and_checkID の実行で返されるID

#define RFU_MBOOT_DOWNLOADER_SERIAL_NO 0x0000  // マルチブート用のダウンローダー（カートリッジなしで起動するプログラム）のゲームシリアルNo

#define RFU_API_BUFF_SIZE_RAM 0x0e64  // rfu_initializeAPIで指定するバッファに必要なサイズ（ライブラリのSIO割り込みルーチンをRAMで動作させる高速通信版）
#define RFU_API_BUFF_SIZE_ROM 0x0504  // rfu_initializeAPIで指定するバッファに必要なサイズ（ライブラリのSIO割り込みルーチンをROMで動作させる低速通信版）

#define RFU_CHILD_MAX 4  // 一台の親機に接続できる最大の子機の台数

#define RFU_GAME_NAME_LENGTH 13  // rfu_REQB_configGameDataで設定可能なゲームネーム長
#define RFU_USER_NAME_LENGTH 8   // rfu_REQB_configGameDataで設定可能なユーザーネーム長

#define RFU_H_DMA_MAX_CPU_CYCLE 42  // RFU使用時に動作可能なH-DMAおよびVブランク起動DMAの最大CPUサイクル数

// 無線状態を示すリンク強度アイコンの段階を判定するための値（rfuLinkStatus->strength[0-3]の値）
#define RFU_LINK_ICON_LEVEL4_MAX 255  // 90% -100%  (値が 229~255 なら、アイコンレベル4)
#define RFU_LINK_ICON_LEVEL4_MIN 229
#define RFU_LINK_ICON_LEVEL3_MAX 228  // 50% - 89%  (値が 127~228 なら、アイコンレベル3)
#define RFU_LINK_ICON_LEVEL3_MIN 127
#define RFU_LINK_ICON_LEVEL2_MAX 126  // 10% - 49%  (値が  25~126 なら、アイコンレベル2)
#define RFU_LINK_ICON_LEVEL2_MIN 25
#define RFU_LINK_ICON_LEVEL1_MAX 24  //  0% -  9%   (値が   0~ 24 なら、アイコンレベル1)
#define RFU_LINK_ICON_LEVEL1_MIN 0

// *******************************************************
// ライブラリ関数で使用する引数用定義データ
// *******************************************************
// rfu_REQ_configGameDataのu16 mboot_flagで指定
#define RFU_MBOOT_FLAG 0x01  // このフラグを立てることで、マルチブート用のプログラムと接続が可能となる

// rfu_REQ_configSystemのu16 availSlot_flag中で使用する AvailSlot（接続可能なスロット数）
#define AVAIL_SLOT4 0x0000
#define AVAIL_SLOT3 0x0001
#define AVAIL_SLOT2 0x0002
#define AVAIL_SLOT1 0x0003

// rfu_setRecvBufferで指定するu8 connType_flag
#define TYPE_UNI 0x10  // UNI型
#define TYPE_NI 0x20   // NI 型

// rfu_clearSlotで指定するu8 connType_flag
#define TYPE_UNI_SEND 0x01  // UNI型 送信
#define TYPE_UNI_RECV 0x02  // UNI型 受信
#define TYPE_NI_SEND 0x04   // NI 型 送信
#define TYPE_NI_RECV 0x08   // NI 型 受信

// *******************************************************
// ライブラリ関数の戻り値で返される定義データ
// *******************************************************

// rfu_REQ_pollConnectParentのu8 *statusの値（接続試みステータス）
#define CP_STATUS_DONE 0x00          // 接続成功
#define CP_STATUS_IN_PROCESS 0x01    // 接続試み中
#define CP_STATUS_SLOT_CLOSED 0x02   // 親機が子機との接続モードにない
#define CP_STATUS_DISCONNECTED 0x03  // 接続中に親機に切断された
#define CP_STATUS_UNKNOWN 0xff       // REQ-API実行エラーによりステータス読めず

// rfu_REQ_pollRecoveryConnectの引数u8 *statusの値（リンク復旧ステータス）
#define RC_STATUS_DONE 0x00              // 接続復旧成功
#define RC_STATUS_FAILED 0x01            // 接続復旧失敗（これ以上試みても無意味）
#define RC_STATUS_SEARCHING_PARENT 0x02  // 親機を探索中
#define RC_STATUS_UNKNOWN 0xff           // REQ-API実行エラーによりステータス読めず

// rfu_REQBN_watchLinkの引数u8 *linkLossReasonの値（リンク切れ理由)
#define REASON_DISCONNECTED 0x00  // rfuLL_disconnectにより完全に切断され、リンク復旧不可能な状態（子機側のみ検出可能）
#define REASON_LINK_LOSS 0x01     // リンク切れが発生しており、リンク復旧が可能な可能性がある状態

// rfu_getMasterSlaveで返される値
#define AGB_CLK_SLAVE 0   // AGBクロックスレーブ
#define AGB_CLK_MASTER 1  // AGBクロックマスター

// *******************************************************
// ライブラリ関数のエラーコード群
// *******************************************************

// REQ-API関数実行時のREQコールバックでu16 REQ_resultで返されるエラーコード
#define ERR_REQ_CMD 0x0000
#define ERR_REQ_CMD_CLOCK_DRIFT (ERR_REQ_CMD | 0x0001)    // REQコマンド送信でクロックドリフトが発生している
#define ERR_REQ_CMD_SENDING (ERR_REQ_CMD | 0x0002)        // REQコマンド送信中なので、次のコマンドを発行できない
#define ERR_REQ_CMD_ACK_REJECTION (ERR_REQ_CMD | 0x0003)  // REQコマンドを発行したら、拒否された
#define ERR_REQ_CMD_CLOCK_SLAVE (ERR_REQ_CMD | 0x0004)    // REQコマンドを発行しようとしたが、AGBがクロックスレーブのためできなかった
#define ERR_REQ_CMD_IME_DISABLE (ERR_REQ_CMD | 0x0006)    // REQコマンドを発行しようとしたが、IMEレジスタが０のためできなかった

#define ERR_PID_NOT_FOUND 0x0100  // 指定PIDがrfuLinkStatus->partner[0-3].idのりスト内に存在しない

// rfu_initializeAPIの返り値で返されるエラーコード
#define ERR_RFU_API_BUFF_SIZE 0x0001
#define ERR_RFU_API_BUFF_ADR 0x0002

// rfu_REQBN_softReset_and_checkIDの返り値で返されるエラーコード
#define ERR_ID_CHECK_IME_DISABLE 0xffffffff  // rfu_REQBN_softReset_and_checkID実行時にREG_IME=0だったのでIDチェックを実行できない

// rfu_getConnectParentStatus,rfu_CHILD_getConnectRecoveryStatusで返されるエラーコード
#define ERR_REQ_CMD_ID (ERR_REQ_CMD | 0x0010)  // 本関数実行に必要なREQコマンドが実行されていない

// rfu_NI_setSendData,rfu_UNI_setSendData,rfu_NI_CHILD_setSendGameNameで返されるエラーコード
#define ERR_MODE 0x0300
#define ERR_MODE_NOT_PARENT (ERR_MODE | 0x0000)     // not in SDK
#define ERR_MODE_NOT_CONNECTED (ERR_MODE | 0x0001)  // RFUが接続モード（親or子）でない

#define ERR_SLOT 0x0400
#define ERR_SLOT_NO (ERR_SLOT | 0x0000)             // 指定スロット№がおかしい
#define ERR_SLOT_NOT_CONNECTED (ERR_SLOT | 0x0001)  // 指定スロットが接続されていない
#define ERR_SLOT_BUSY (ERR_SLOT | 0x0002)           // 指定スロットが既に通信中である
#define ERR_SLOT_NOT_SENDING (ERR_SLOT | 0x0003)    // 指定スロットが現在送信中でない（※これはrfu_UNI_re_setSendDataで返される）
#define ERR_SLOT_TARGET (ERR_SLOT | 0x0004)         // 指定対象スロットがおかしい

#define ERR_SUBFRAME_SIZE 0x0500  // 指定サブフレームサイズが残り通信フレームサイズより大きいか、リンク層サブフレームヘッダサイズより小さい

// rfu_clearSlot,rfu_setRecvBuffer,rfu_changeSendTargetで返されるエラーコード
#define ERR_COMM_TYPE 0x0600  // 指定通信形式がおかしい

// rfu_REQ_recvDataで返される（NI型、UNI型データ受信時）のエラーコード
#define ERR_DATA_RECV \
  0x0700  // エラー発生の通知は、下記形式で行われます。
          // 「ERR_DATA_RECV | (0x0010<<UNIでエラーが発生したスロット№)｜(0x0001<<NIでエラーが発生したスロット№)」
          // そして実際のエラーコードはrfuSlotStatus_NI or _UNI[x]->recv.errorCodeに格納されます。

// NI型通信時のエラーコード（rfuSlotStatus_NI[x]->recv.errorCodeに入るコード）
#define ERR_RECV_BUFF_OVER (ERR_DATA_RECV | 0x0001)            // 受信データサイズが受信バッファより大きい（※このエラーはNI,UNI共通）
#define ERR_RECV_REPLY_SUBFRAME_SIZE (ERR_DATA_RECV | 0x0002)  // 既に他の通信で全てのフレームが使用されていて、受信応答用のサブフレームが確保できない

// UNI型通信時のエラーコード（rfuSlotStatus_UNI[x]->recv.errorCodeに入るコード）
#define ERR_RECV_DATA_OVERWRITED (ERR_DATA_RECV | 0x0008)  // rfuSlotStatus_UNI[x]->recv.newData_flag=1の時に新しいデータを受信した

// not in SDK header
#define ERR_RECV_UNK (ERR_DATA_RECV | 0x0001 | 0x0008)

// *******************************************************
// ライブラリのグローバル変数で使用される定義データ
// *******************************************************

// gRfuLinkStatus-------------------------------------------
// 接続状態 (refer to gRfuLinkStatus->parentChild)
#define MODE_NEUTRAL 0xFF  // Initialization
#define MODE_CHILD 0x00    // Child
#define MODE_PARENT 0x01   // Parent

// rfuSlotStatus_NI,_UNI-----------------------------------
// NI(Numbered Information)、UNI(Un-Numbered Information)型通信用定義データ

// NI,UNI型通信で共通の定義データ
#define LLF_P_SIZE 87         // 親の最大リンク層通信フレームサイズ（１回の最大送信バイト数）
#define LLF_C_SIZE 16         // 子の        〃
#define LLSF_P_HEADER_SIZE 3  // 親の１個のリンク層サブフレーム(NI,UNIフレーム）が使用するヘッダサイズ
#define LLSF_C_HEADER_SIZE 2  // 子の        〃

// リンク層通信コード
#define LCOM_NULL 0x0000
#define LCOM_NI_START 0x0001
#define LCOM_NI 0x0002
#define LCOM_NI_END 0x0003
#define LCOM_UNI 0x0004

// スロット状態データ用フラグ
#define SLOT_BUSY_FLAG 0x8000  // スロット使用中
#define SLOT_SEND_FLAG 0x0020  // 送信
#define SLOT_RECV_FLAG 0x0040  // 受信

// NI,UNI型共通スロット待機状態データ(rfuSlotStatus_NI[x]->send or ->recv.stateおよびrfuSlotStatus_UNIの同ステート)
#define SLOT_STATE_READY 0x0000  // スロット初期状態

// NI型通信用　状態データ（rfuSlotStatus_NI[x]->send or ->recv.state)
#define SLOT_STATE_SEND_START (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_NI_START)  // 送信開始
#define SLOT_STATE_SENDING (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_NI)           // 送信中
#define SLOT_STATE_SEND_LAST (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_NI_END)     // 送信終了確認
#define SLOT_STATE_SEND_NULL (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_NULL)       // 送信終了通達のためのNULLサブフレーム送信
#define SLOT_STATE_SEND_SUCCESS (SLOT_SEND_FLAG | 0x006)                         // 送信成功
#define SLOT_STATE_SEND_FAILED \
  (SLOT_SEND_FLAG | 0x007)                                                       // 送信失敗
                                                                                 // 送信が成功／失敗したスロットの判別はrfuSlotStatus_NI[x]->send.bmSlotと同bmSlot_orgを比較
#define SLOT_STATE_RECV_START (SLOT_BUSY_FLAG | SLOT_RECV_FLAG | LCOM_NI_START)  // 受信開始
#define SLOT_STATE_RECEIVING (SLOT_BUSY_FLAG | SLOT_RECV_FLAG | LCOM_NI)         // 受信中
#define SLOT_STATE_RECV_LAST (SLOT_BUSY_FLAG | SLOT_RECV_FLAG | LCOM_NI_END)     // 受信終了確認
#define SLOT_STATE_RECV_SUCCESS (SLOT_RECV_FLAG | 0x006)                         // 受信成功
#define SLOT_STATE_RECV_FAILED (SLOT_RECV_FLAG | 0x007)                          // 受信失敗
#define SLOT_STATE_RECV_SUCCESS_AND_SENDSIDE_UNKNOWN (SLOT_RECV_FLAG | 0x008)    // データ受信は成功したが、通信の終端が完了しなかったので、送信側のステータスが成功か失敗か不明な状態
#define SLOT_STATE_RECV_IGNORE (SLOT_RECV_FLAG | 0x009)                          // 受信無視（無視理由はrfuSlotStatus_NI[x]->recv.errorCodeを参照）

// UNI型通信用　状態データ(rfuSlotStatus_UNI[x]->send.state参照)
#define SLOT_STATE_SEND_UNI (SLOT_BUSY_FLAG | SLOT_SEND_FLAG | LCOM_UNI)  // 送信中

// --------------------------------------------
// SDK には記載されていない

typedef struct {
  u8 data[0x74];
} RfuPacket8;

typedef struct {
  u32 command;
  u32 data[0x1C];
} RfuPacket32;

typedef union {
  RfuPacket32 rfuPacket32;
  RfuPacket8 rfuPacket8;
} RfuPacket;

typedef struct {
  vs32 state;
  u8 reqLength;
  u8 reqNext;
  u8 reqActiveCommand;
  u8 ackLength;
  u8 ackNext;
  u8 ackActiveCommand;
  u8 timerSelect;
  u8 unk_b;
#if LIBRFU_VERSION >= 1026
  s32 timerState;
#else
  u32 timerState;
#endif
  vu8 timerActive;
  u8 unk_11;
  vu16 error;
  vu8 msMode;
  u8 recoveryCount;
  u8 unk_16;
  u8 unk_17;
  void (*callbackM)();
  void (*callbackS)(u16);
  void (*callbackID)(void);
  RfuPacket* txPacket;
  RfuPacket* rxPacket;
  vu8 sending;
} STWIStatus;

// This struct is used as u8 array in SDK.
struct RfuIntrStruct {
  RfuPacket rxPacketAlloc;
  RfuPacket txPacketAlloc;
  u8 ALIGNED(2) block1[0x960];  // size of librfu_intr.s binary
  STWIStatus block2;
};

struct RfuFixed {
  void (*reqCallback)(u16, u16);
  void (*fastCopyPtr)(const u8**, u8**, s32);
  u16 fastCopyBuffer[24];
  u32 fastCopyBuffer2[12];
  u32 LLFBuffer[29];
  struct RfuIntrStruct* STWIBuffer;
};

struct RfuStatic {
  u8 flags;
  u8 NIEndRecvFlag;
  u8 recvRenewalFlag;
  u8 commExistFlag;
  u8 recvErrorFlag;
  u8 recoveryBmSlot;
  u8 nowWatchInterval;
  u8 nullFrameCount;
  u8 emberCount;
  u8 SCStartFlag;
  u8 linkEmergencyFlag[RFU_CHILD_MAX];
  u8 lsFixedCount[RFU_CHILD_MAX];
  u16 cidBak[RFU_CHILD_MAX];
  u16 linkEmergencyLimit;
  u16 reqResult;
  u16 tryPid;
  u16 watchdogTimer;
  u32 totalPacketSize;
};

extern struct RfuStatic* gRfuStatic;
extern struct RfuFixed* gRfuFixed;

// --------------------------------------------
// SDK に記載

// ゲーム識別情報データ構造 (pret's RfuTgtData)
typedef struct rfuTgtDataTag {         // SearchParent時                       それ以外（親機、子機の時）
  u16 id;                              // 親機候補のID                            接続相手のID
  u8 slot;                             // 親機候補のエントリ可能なスロット番号           接続スロット番号
  u8 mboot_flag;                       // 親機候補がマルチブートのダウンロード用         接続相手がマルチブートのダウンロード用 (pret: mbootFlag)
                                       //     プログラムか否かを示すフラグ             プログラムか否かを示すフラグ
  u16 serialNo;                        // 親機候補のゲームシリアル番号                接続相手のゲームシリアル番号
  u8 gname[RFU_GAME_NAME_LENGTH + 2];  // 親機候補のゲームネーム                    接続相手のゲームネーム
  u8 uname[RFU_USER_NAME_LENGTH + 1];  // 親機候補のユーザーネーム                   接続相手のユーザーネーム
  u8 padding[2];
} rfuTgtData;  // 32 Bytes

// リンク状態データ構造 (pret's RfuLinkStatus)
typedef struct RFU_linkStatus_Tag {
  u8 parent_child;                        // 接続状態（0x01:MODE_PARENT, 0x00:MODE_CHILD, 0xFF:MODE_NEUTRAL） (pret: parentChild)
  u8 connectCount;                        // 接続本数 (pret: connCount)
  u8 connectSlot_flag;                    // 接続中のスロットをビットで示すフラグ （0x01<<接続スロット番号） (pret: connSlotFlag)
  u8 linkLossSlot_flag;                   // リンク切れが発生したスロットをビットで示すフラグ（〃） (pret: linkLossSlotFlag)
  u8 sendSlot_NI_flag;                    // NI型送信中のスロットをビットで示すフラグ (〃） (pret: sendSlotNIFlag)
  u8 recvSlot_NI_flag;                    // NI型受信中のスロットをビットで示すフラグ （〃） (pret: recvSlotNIFlag)
  u8 sendSlot_UNI_flag;                   // UNI型送信中のスロットをビットで示すフラグ （〃） (pret: sendSlotUNIFlag)
  u8 getName_flag;                        // 親：そのスロットに接続されている子のゲーム識別情報を取得済みかどうかをビットで示すフラグ（〃）
                                          // 子：そのスロットに接続されている親に自分のゲーム識別情報を送信済みかどうかをビットで示すフラグ（〃） (pret: getNameFlag)
  u8 findParentCount;                     // 子機の場合のみ有効な、rfu_REQ_xxxSearchParentで発見した親候補の数
  u8 watchInterval;                       // リンク監視実行間隔（AGBのピクチャーフレーム16.7ms単位）
  u8 strength[RFU_CHILD_MAX];             // リンク強度の値（0x00～0xff,  0x00でリンク切れ。rfu_REQBN_watchLinkが更新する）
  vu8 llf_ready_flag;                     // 次に送信するリンク層フレームが構築されているか。（rfu_constructLLFrameをコール時にこのフラグが立ち、rfu_REQ_sendDataで送信が行われるとクリアされる。） (pret: LLFReadyFlag)
  u8 remainLLFrameSize_P;                 // 親機の時のリンク層通信フレームの残りサイズ (pret: remainLLFrameSizeParent)
  u8 remainLLFrameSize_C[RFU_CHILD_MAX];  // 子機の時の各スロット毎のリンク層通信フレームの残りサイズ (pret: remainLLFrameSizeChild)

  rfuTgtData partner[RFU_CHILD_MAX];  // 親、子：接続が存在する時は、接続したスロット番号に対応した配列要素に接続相手のゲーム識別情報が格納される。
                                      // 子    ：rfu_REQ_xxxxSearchParent実行時に発見した親候補のゲーム識別情報が格納される。
  rfuTgtData my;                      // 自分のゲーム識別情報（要素slotの値は関係なし）
} RFU_LINK_STATUS;                    // 180 Bytes

#define WINDOW_COUNT 4

// NI型データ送信・受信用データ構造, (pret: NIComm)
typedef struct NIComm {
  // 現在の通信状態を示すパラメータ
  u16 state;  // スロットの通信状態

  u16 failCounter;               // 送受信失敗カウンタ（1PF=16.7ms中にデータ送受信が成功しなかった場合に、カウントアップします。）
  const u8* nowp[WINDOW_COUNT];  // 現在の送受信中アドレス（データ全体をWINDOW_COUNT分のブロックに分割して、それをpayloadSize単位で送信します。）
  u32 remainSize;                // 残り通信データサイズ
  u16 errorCode;                 // エラーコード
  u8 bmSlot;                     // 現在の通信先スロットをビットで表現（親の送信時は、bmSlotで複数の子を指定できるため、各子機のfailCounterをもとに通信打ち切りを行う）

  // ライブラリ内部で使用されるパラメータ
  u8 recv_ack_flag[WINDOW_COUNT];  // (pret: recvAckFlag)
  u8 ack;
  u8 phase;
  u8 n[WINDOW_COUNT];

  // 今回の通信内容を示すパラメータ
  const u8* src;    // 送信データ先頭アドレス（送信側のみ有効）
  u8 bmSlot_org;    // 送信開始時の通信先スロットをビットで表現（送信側のみ有効） (pret: bmSlotOrg)
  u8 dataType;      // 送受信データタイプ（0:ユーザデータ, 1:ゲーム識別情報）
  u16 payloadSize;  // １回の送信のペイロードサイズ
  u32 dataSize;     // 送受信データサイズ, rfu_NI_setSendData関数で指定したsubFrameSizeからリンク層ヘッダサイズを引いたもの
} NI_COMM;

// UNI型データ送信用データ構造, (pret: UNISend)
typedef struct UNI_SEND_Tag {
  u16 state;          // スロットの通信状態（SLOT_STATE_READY、SLOT_STATE_SEND_UNI）
  u8 dataReady_flag;  // 送信データ準備OKフラグ（0:データ送信済み、1:送信データready）, セットはrfu_UNI_re_setSendData, rfu_UNI_readySendDataで行い、クリアはrfu_REQ_sendDataによってデータが送信された際に行われる。 (pret: dataReadyFlag)
  u8 bmSlot;          // 送信先スロットをビットで表現
  u16 payloadSize;    // １回の送信のペイロードサイズ。rfu_UNI_setSendData, rfu_UNI_re_setSendDataで指定したsizeが入る
  const u8* src;      // 送信データ先頭アドレス
} UNI_SEND;

// UNIデータ受信用データ構造, (pret: UNIRecv)
typedef struct UNI_RECV_Tag {
  u16 state;          // スロットの通信状態（SLOT_STATE_READY、SLOT_STATE_RECEIVING、SLOT_STATE_RECV_IGNORE）
  u16 errorCode;      // 受信時のエラーコード
  u16 dataSize;       // 受信データのサイズ
  u8 newData_flag;    // 新着受信データあり／なしフラグ（0:新着データなし、1:新着データあり）, フラグのクリアはrfu_UNI_clearRecvNewDataFlagで行い、セットはrfu_REQ_recvDataによってデータが受信された際に行われる。 (pret: newDataFlag)
  u8 dataBlock_flag;  // 未参照受信データ上書きブロックフラグ（デフォルト0  ※未使用） (pret: dataBlockFlag)
} UNI_RECV;

// NI型通信用　スロット状態データ構造 (pret: RfuSlotStatusNI)
typedef struct RFU_SlotStatus_NI_Tag {
  NI_COMM send;      // 送信ステータス
  NI_COMM recv;      // 受信ステータス
  u8* recvBuff;      // 受信バッファアドレス (pret: recvBuffer)
  u32 recvBuffSize;  // 受信バッファサイズ (pret: recvBufferSize)
} RFU_SLOT_STATUS_NI;

// UNI型通信用 スロット状態データ構造 (pret: RfuSlotStatusUNI)
typedef struct RFU_SlotStatus_UNI_Tag {
  UNI_SEND send;     // 送信ステータス
  UNI_RECV recv;     // 受信ステータス
  u8* recvBuff;      // 受信バッファアドレス (pret: recvBuffer)
  u32 recvBuffSize;  // 受信バッファサイズ (pret: recvBufferSize)
} RFU_SLOT_STATUS_UNI;

// --------------------------------------------

// a.k.a. STWI_status
extern STWIStatus* gSTWIStatus;

extern RFU_LINK_STATUS* gRfuLinkStatus;

extern RFU_SLOT_STATUS_NI* gRfuSlotStatusNI[RFU_CHILD_MAX];
extern RFU_SLOT_STATUS_UNI* gRfuSlotStatusUNI[RFU_CHILD_MAX];

// librfu_sio32id
s32 AgbRFU_checkID(u8 maxTries);
void AgbRFU_SoftReset(void);

u16 rfu_waitREQComplete(void);

u32 rfu_REQBN_softReset_and_checkID(void);
void rfu_REQ_sendData(bool8 clockChangeFlag);
void rfu_setREQCallback(void (*callback)(u16 reqCommandId, u16 reqResult));
u16 rfu_getConnectParentStatus(u8* status, u8* connectSlotNo);
u16 rfu_CHILD_getConnectRecoveryStatus(u8* status);
void rfu_REQ_startSearchParent(void);
void rfu_REQ_pollSearchParent(void);
void rfu_REQ_endSearchParent(void);

void rfu_REQ_changeMasterSlave(void);
bool8 rfu_getMasterSlave(void);
void rfu_setMSCCallback(void (*callback)(u16 reqCommandId));
void rfu_clearAllSlot(void);
u16 rfu_clearSlot(u8 connTypeFlag, u8 slotStatusIndex);
u16 rfu_setRecvBuffer(u8 connType, u8 slotNo, void* buffer, u32 buffSize);

u8* rfu_getSTWIRecvBuffer(void);
void rfu_REQ_RFUStatus(void);
u16 rfu_getRFUStatus(u8* rfuState);
void rfu_REQ_noise(void);
void rfu_REQ_disconnect(u8 bmDisconnectSlot);

u16 rfu_NI_CHILD_setSendGameName(u8 slotNo, u8 subFrameSize);
u16 rfu_UNI_PARENT_getDRAC_ACK(u8* ackFlag);
u16 rfu_NI_stopReceivingData(u8 slotStatusIndex);
u16 rfu_changeSendTarget(u8 connType, u8 slotStatusIndex, u8 bmNewTgtSlot);

u16 rfu_syncVBlank(void);
u16 rfu_REQBN_watchLink(u16 reqCommandId, u8* bmLinkLossSlot, u8* linkLossReason, u8* parentBmLinkRecoverySlot);

void rfu_REQ_reset(void);
// Set RFU to Stop Mode (Power Down)
void rfu_REQ_stopMode(void);
// RFU Hardware Settings
void rfu_REQ_configSystem(u16 availSlotFlag, u8 maxMFrame, u8 mcTimer);
// Game Identification Information Configuration
void rfu_REQ_configGameData(u8 mbootFlag, u16 serialNo, const u8* gname, const u8* uname);

void rfu_REQ_startSearchChild(void);
void rfu_REQ_pollSearchChild(void);
void rfu_REQ_endSearchChild(void);
// Operate as child device; search for parent device
void rfu_REQ_startSearchParent(void);
void rfu_REQ_pollSearchParent(void);
void rfu_REQ_endSearchParent(void);
// Operate as child device; connect to specified parent device
void rfu_REQ_startConnectParent(u16 pid);
void rfu_REQ_pollConnectParent(void);
void rfu_REQ_endConnectParent(void);
u16 rfu_getConnectParentStatus(u8* status, u8* connectSlotNo);
// Restore link from child device
void rfu_REQ_CHILD_startConnectRecovery(u8 bmRecoverySlot);
void rfu_REQ_CHILD_pollConnectRecovery(void);
void rfu_REQ_CHILD_endConnectRecovery(void);
u16 rfu_CHILD_getConnectRecoveryStatus(u8* status);

// librfu_intr
void IntrSIO32(void);

// librfu_stwi
void STWI_init_all(struct RfuIntrStruct* interruptStruct, IntrFunc* interrupt, bool8 copyInterruptToRam);
void STWI_set_MS_mode(u8 mode);
void STWI_init_Callback_M(void);
void STWI_init_Callback_S(void);
void STWI_set_Callback_M(void* callbackM);
void STWI_set_Callback_S(void (*callbackS)(u16));
void STWI_init_timer(IntrFunc* interrupt, s32 timerSelect);
void AgbRFU_SoftReset(void);
void STWI_set_Callback_ID(void (*func)(void));
u16 STWI_read_status(u8 index);
u16 STWI_poll_CommandEnd(void);
void STWI_send_DataRxREQ(void);
void STWI_send_MS_ChangeREQ(void);
void STWI_send_StopModeREQ(void);
void STWI_send_SystemStatusREQ(void);
void STWI_send_GameConfigREQ(const u8* serial_gname, const u8* uname);
void STWI_send_ResetREQ(void);
void STWI_send_LinkStatusREQ(void);
void STWI_send_VersionStatusREQ(void);
void STWI_send_SlotStatusREQ(void);
void STWI_send_ConfigStatusREQ(void);
void STWI_send_ResumeRetransmitAndChangeREQ(void);
void STWI_send_SystemConfigREQ(u16 availSlotFlag, u8 maxMFrame, u8 mcTimer);
void STWI_send_SC_StartREQ(void);
void STWI_send_SC_PollingREQ(void);
void STWI_send_SC_EndREQ(void);
void STWI_send_SP_StartREQ(void);
void STWI_send_SP_PollingREQ(void);
void STWI_send_SP_EndREQ(void);
void STWI_send_CP_StartREQ(u16 unk1);
void STWI_send_CP_PollingREQ(void);
void STWI_send_CP_EndREQ(void);
void STWI_send_DataTxREQ(const void* in, u8 size);
void STWI_send_DataTxAndChangeREQ(const void* in, u8 size);
void STWI_send_DataReadyAndChangeREQ(u8 unk);
void STWI_send_DisconnectedAndChangeREQ(u8 unk0, u8 unk1);
void STWI_send_DisconnectREQ(u8 unk);
void STWI_send_TestModeREQ(u8 unk0, u8 unk1);
void STWI_send_CPR_StartREQ(u16 unk0, u16 unk1, u8 unk2);
void STWI_send_CPR_PollingREQ(void);
void STWI_send_CPR_EndREQ(void);

#endif  // __INCLUDE_GBA_AGBRFU_H__
