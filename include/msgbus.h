#ifndef __INCLUDE_MSGBUS_H__
#define __INCLUDE_MSGBUS_H__

#include "gba/gba.h"
#include "types.h"

// エンティティ間のメッセージ機構。実装は src/msgbus.c、データは src/demo.c。
// 送り主はほとんどがデモ(イベント/カットシーン)スクリプトだが、VM やプレイヤーからも直接送られる。
// EntityMsgBus (src/msgbus.c 内のシングルトン) が受け口の名簿を持ち、メッセージを宛先へ配る。

// EntityMsgBus 経由でエンティティに届くメッセージ。可変長で、実体サイズは 8 + ceil(argc/2)*4 バイト
// 組み立ての手本は FUN_08041b28 (VM のキーワード 'n'/'k'/'f'/'a'/'p' から1件作って送る)
typedef struct EntityMsg {
  u16 targetID;    // 0x00, 宛先。EntityMsgBox.targetID と照合される (生成元のサブルーチンID), 根拠: EntityMsgBus_FindBox
  u8 targetClass;  // 0x02, 宛先の種別 1..10。EntityMsgBox.targetClass と照合される, 根拠: EntityMsgBus_FindBox
  u8 waitFlag;     // 0x03, 非0なら受け手が処理を終えるまでデモの進行が止まる, 根拠: EntityMsgBox_BeginWait / EntityMsgBox_EndWait
  u16 unk_4;       // 0x04, FUN_08041b28 が strh で書く (キーワード 'f')。読み手は未発見
  u8 cmd;          // 0x06, 処理の種類。意味は targetClass ごとに別, 根拠: Demo_HandleMsgs などの switch
  u8 argc;         // 0x07, args の個数 0..9
  s16 args[1];     // 0x08, 実体は argc 個 (可変長)
} EntityMsg;

// エンティティに埋め込まれるメッセージの受け口。EntityMsgBus_Register で EntityMsgBus のリストに登録する
typedef struct EntityMsgBox {
  u16 targetID;               // 0x00, EntityMsgBus_Register の第2引数
  u8 targetClass;             // 0x02, EntityMsgBus_Register の第3引数
  u8 waitFlag;                // 0x03, EntityMsg.waitFlag の写し。EntityMsgBox_EndWait で完了を通知してクリアする
  u8 unk_4[2];                // 0x04, 書き手も読み手も未発見
  u8 count[2];                // 0x06, 面ごとに積まれた件数, 根拠: EntityMsgBus_SwapBuffers
  EntityMsg* msgs[2][4];      // 0x08, EntityMsgBus.bufIdx で面を選ぶダブルバッファ, 根拠: EntityMsgBus_Post
  u8 unk_28[4];               // 0x28, 書き手も読み手も未発見
  struct EntityMsgBox* prev;  // 0x2C
  struct EntityMsgBox* next;  // 0x30
} EntityMsgBox;
static_assert(sizeof(EntityMsgBox) == 52);  // 52バイトなのは確定, EntityMsgBus_LinkBox で オフセット 0x34 に 4バイト書き込み, また EntityMsgBus の オフセット 0x78 にこの構造体があるが、 EntityMsgBus は 172バイトなので、 172 - 0x78 = 52 なので、 52バイト

// --------------------------------------------

// 受け口の登録・解除。エンティティの _Init / _Destroy から呼ぶ
s32 EntityMsgBus_Register(EntityMsgBox* p, u32 targetID, s32 targetClass);
s32 EntityMsgBus_Unregister(EntityMsgBox* p);

// メッセージを1件投函する
s32 EntityMsg_Send(EntityMsg* p);

// 受け手側の完了通知。BeginWait は配る側、EndWait は処理し終えた受け手が呼ぶ
bool32 EntityMsgBox_BeginWait(EntityMsgBox* p, EntityMsg* data);
bool32 EntityMsgBox_EndWait(EntityMsgBox* p, u32 val);

// --------------------------------------------

// デモスクリプトの3段テーブル (src/demo.c)。デモ表[demoID] -> デモ[step] -> ステップ[idx] -> メッセージ
extern const EntityMsg* const* const* const gDemoTable[125];
EntityMsg* DemoTable_GetMsg(s32 demoID, s32 step, s32 idx);

s32 Demo_Start(void);         // 実行中のスクリプトのキーワード 'd'/'c'/'e'/'p' からデモを開始する
s32 Demo_Stop(void);          // 再生状態を全部クリアする
s32 Demo_Resume(void);        // cmd 2 (Demo_CmdWaitExternal) で止まっているデモを外部から再開する
bool32 Demo_IsRunning(void);  // 再生中なら TRUE

#endif  // __INCLUDE_MSGBUS_H__
