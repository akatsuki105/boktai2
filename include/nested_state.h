#ifndef __INCLUDE_NESTED_STATE_H__
#define __INCLUDE_NESTED_STATE_H__

#include "gba/gba.h"

// 3段の入れ子状態機械, 上の段を書き換えると下の段の状態とカウンタが全部 0 に戻る
// ドヴァリン (やそれに属するEntity) がそれぞれの構造体に埋め込んで使う (っぽいので調査をしたら名前を変える予定)
typedef struct {
  u8 state0;   // 0x00
  u8 state1;   // 0x01
  u8 state2;   // 0x02
  u8 _;        // 0x03, padding
  u32 timer0;  // 0x04, state0 を書き換えたときだけ 0 に戻る, 進めるのは呼び出し元
  u32 timer1;  // 0x08, state0 か state1 を書き換えると 0 に戻る
  u32 timer2;  // 0x0C, どの段を書き換えても 0 に戻る
} NestedState;
static_assert(sizeof(NestedState) == 16);

void NestedState_Reset0(NestedState* s);
void NestedState_Set0(NestedState* s, u8 state);
void NestedState_Advance0(NestedState* s);
void NestedState_Reset1(NestedState* s);
void NestedState_Set1(NestedState* s, u8 state);
void NestedState_Advance1(NestedState* s);
void NestedState_Reset2(NestedState* s);
void NestedState_Set2(NestedState* s, u8 state);
void NestedState_Advance2(NestedState* s);

#endif  // __INCLUDE_NESTED_STATE_H__
