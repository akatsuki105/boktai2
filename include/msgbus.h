#ifndef __INCLUDE_MSGBUS_H__
#define __INCLUDE_MSGBUS_H__

#include "entity.h"
#include "gba/gba.h"
#include "types.h"

// エンティティ間のメッセージ機構, 実装は src/msgbus.c、データは src/demo.c,
// 送り主はほとんどがデモ(イベント/カットシーン)スクリプトだが、VM やプレイヤーからも直接送られる
// MsgBus (src/msgbus.c 内のシングルトン) が受け口の名簿を持ち、メッセージを宛先へ配る

// MsgBus 経由で受け手に届くメッセージ, 可変長で、実体サイズは 8 + ceil(argc/2)*4 バイト
// 組み立ての手本は FUN_08041b28 ('.n'/'.k'/'.f'/'.a'/'.p' から1件作って送る)
typedef struct {
  u16 targetID;    // 0x00, 宛先, MsgQueue.targetID と照合される (生成元のサブルーチンID)
  u8 targetClass;  // 0x02, 宛先の種別 1..10, MsgQueue.targetClass と照合される, 根拠: MsgBus_FindQueue
  bool8 waitFlag;  // 0x03, 非0なら受け手が処理を終えるまでデモの進行が止まる, 根拠: MsgQueue_BeginWait / MsgQueue_EndWait
  u16 unk_4;       // 0x04, '.f', 読み手は未発見
  u8 cmd;          // 0x06, 処理の種類, 意味は targetClass ごとに別, 根拠: Demo_HandleMsgs などの switch
  u8 argc;         // 0x07, args の個数 0..9
  s16 args[1];     // 0x08, 実体は argc 個 (可変長)
} MsgPacket;

// 受け手側に埋め込まれるメッセージの受け口, MsgQueue_Register で MsgBus のリストに登録する
typedef struct MsgQueue {
  u16 targetID;           // 0x00, MsgQueue_Register の第2引数
  u8 targetClass;         // 0x02, MsgQueue_Register の第3引数
  bool8 waitFlag;         // 0x03, MsgPacket.waitFlag の写し, MsgQueue_EndWait で完了を通知してクリアする
  u8 unk_4[2];            // 0x04, 書き手も読み手も未発見, padding?
  u8 count[2];            // 0x06, 面ごとに積まれた件数, 根拠: MsgBus_SwapBuffers
  MsgPacket* msgs[2][4];  // 0x08, MsgBus.bufIdx で面を選ぶダブルバッファ, 根拠: MsgBus_Post
  u8 unk_28[4];           // 0x28, 書き手も読み手も未発見
  struct MsgQueue* prev;  // 0x2C
  struct MsgQueue* next;  // 0x30
} MsgQueue;
static_assert(sizeof(MsgQueue) == 52);

// メッセージバス兼デモ再生機, シングルトン (gMsgBus) で、これがいないとメッセージ機構そのものが動かない
// 受け口: 全ての MsgQueue を queues のリストで持ち、登録・解除・ダブルバッファの面切り替えを一手に引き受ける
// 再生: デモスクリプト (PTR_ARRAY_08dbd564) を demoID/step で読み進め、各 MsgPacket を宛先の受け口へ配る
// 自身も targetClass 1 の宛先で、cmd 0=スクリプト実行 / 1=ウェイト / 2=外部待ち を Demo_HandleMsgs で処理する
typedef struct {
  Entity e;            // ENTITY_UNK_2
  s16 demoID;          // 0x18, '.d', DemoTable_GetMsg の第1添字
  s16 step;            // 0x1A, ('.c'-1) から1ずつ進む, 第2添字
  u16 msgIdx;          // 0x1C, 第3添字, 0件のステップに来たらデモ終了
  bool8 advanceReq;    // 0x1E, Demo_RequestNextStep が立て、Update が step を進めて落とす
  bool8 stepBegun;     // 0x1F, ステップが切り替わった回だけ 1, この回にメッセージを配る
  u16 endScriptID;     // 0x20, '.e', デモ終了時に実行するスクリプト
  u8 scriptCount;      // 0x22, scriptKeys/scriptIDs の件数
  bool8 running;       // 0x23, デモ再生中か？
  u8 bufIdx;           // 0x24, MsgQueue のダブルバッファの現在面
  u8 unk_25[3];        // 0x25, padding?
  u16 scriptKeys[16];  // 0x28, Demo_FindScriptID で検索されるキー
  u16 scriptIDs[16];   // 0x48, scriptKeys に対応するスクリプトID
  s32 waitTimer;       // 0x68, cmd 1 の待ちフレーム数, 根拠: Demo_CmdWait
  u32 unk_6c;          // 0x6C
  u32 extWait;         // 0x70, cmd 2 で 1 になり、Demo_Resume が外部から解除する
  MsgQueue* queues;    // 0x74, 登録済みの受け口のリスト先頭
  MsgQueue mq;         // 0x78, 自分宛て (targetClass 1) の受け口
} MsgBus;
static_assert(sizeof(MsgBus) == 172);

extern MsgBus* gMsgBus;  // 0x03002B4C;

// --------------------------------------------

// 受け口の登録・解除, 受け手の _Init / _Destroy から呼ぶ
s32 MsgQueue_Register(MsgQueue* mq, u32 targetID, s32 targetClass);
s32 MsgQueue_Unregister(MsgQueue* mq);

// メッセージを1件投函する
s32 MsgPacket_Send(MsgPacket* msg);

// 受け手側の完了通知, BeginWait は配る側、EndWait は処理し終えた受け手が呼ぶ
bool32 MsgQueue_BeginWait(MsgQueue* mq, MsgPacket* msg);
bool32 MsgQueue_EndWait(MsgQueue* mq, u32 waitFlag);

// --------------------------------------------

// デモスクリプトの3段テーブル (src/demo.c), デモ表[demoID] -> デモ[step] -> ステップ[idx] -> メッセージ
extern const MsgPacket* const* const* const gDemoTable[125];
MsgPacket* DemoTable_GetMsg(s32 demoID, s32 step, s32 idx);

s32 Demo_Start(void);         // 実行中のスクリプトの'.d'/'.c'/'.e'/'.p' からデモを開始する
s32 Demo_Stop(void);          // 再生状態を全部クリアする
s32 Demo_Resume(void);        // cmd 2 (Demo_CmdWaitExternal) で止まっているデモを外部から再開する
bool32 Demo_IsRunning(void);  // 再生中なら TRUE

#endif  // __INCLUDE_MSGBUS_H__
