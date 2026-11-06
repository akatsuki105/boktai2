#ifndef __INCLUDE_CROSSOVER_H__
#define __INCLUDE_CROSSOVER_H__

#include "global.h"

// クロスオーバーバトルで対戦する片側の状況, 自分の分は相手へ送り, 相手の分は届いた通信で埋まる
typedef struct {
  u8 ojama[4];     // 0x00, 赤/青/黄/緑のオジャマバットの数, 1色5匹・合計10匹まで
  u8 playerHP;     // 0x04, プレイヤーの体力の割合 (%), 初期値 100
  u8 bossHP;       // 0x05, シェードマンの体力の割合 (%), 初期値 100
  bool8 blocking;  // 0x06, インターバル画面で SELECT を押してブロッキングを選んだ
  u8 outcome;      // 0x07, ラウンドの決着, 0: なし, 1: シェードマン撃破, 2: プレイヤー死亡
  u32 clearTime;   // 0x08, 決着までにかかったフレーム数
} CrossoverBattleSide;
static_assert(sizeof(CrossoverBattleSide) == 12);

s32 Entity08051b70_StartSend(void (*onFinish)(void), CrossoverBattleSide* mine);
s32 Entity08051b70_StartExchange(void (*onFinish)(void), CrossoverBattleSide* mine, CrossoverBattleSide* rival, u8* incoming);

#endif  // __INCLUDE_CROSSOVER_H__
