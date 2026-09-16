#ifndef __INCLUDE_INPUT_H__
#define __INCLUDE_INPUT_H__

#include "gba/gba.h"

// 1人分のキー入力, active high (押されていたらbitが立つ)
typedef struct Input {
  Keys16 down;      // 0x00, 現在押されているボタン
  Keys16 pressed;   // 0x02, 前のフレームでは押されていなかったが、今回押されたボタン
  Keys16 released;  // 0x04, 前のフレームでは押されていたが、今回離されたボタン
  u8 unk_06[2];     // 0x06
} Input;
static_assert(sizeof(Input) == 8);  // ReadKeyInput が 8 バイト刻みで 5 人分を更新する

extern bool32 gUseLinkInput;  // 0x030044D0, TRUE なら通信で受け取ったキーから gInput を作る

extern Keys16 gRawKeyInput;  // 0x03004508, ReadKeyInput が読んだ KEYINPUT の生の値 (active low), 通信対戦時は | 0x2000 して相手に送る

extern Keys16 gLinkKeyInput[5];  // 0x03004510, 通信で受け取った各プレイヤーのキー (KEYINPUT と同じ active low), 0xFFFF はデータなし

extern Input gInput[5];  // 0x030044E0, [0] が自分, 通信対戦時は gLinkKeyInput の受信データから全員分を作る

#endif  // __INCLUDE_INPUT_H__
