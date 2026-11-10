#ifndef __INCLUDE_RANDOM_H__
#define __INCLUDE_RANDOM_H__

#include "gba/gba.h"

extern u32 gRngValue;

// まずは Random または RandomNext を使い、それで一致しない場合にのみ、直接 gRandomTable や gRandTableIdx を使ったコードを書くこと
extern s32 gRandTableIdx;
extern u16 gRandomTable[1024];

// 通信対戦でスコア計算に使用する別の乱数テーブル, gRandomTable2 は　ROMの定数で固定値であり、通信対戦参加者が同じ乱数テーブルを使う必要がある場面で使うものと思われる
extern s32 gRandTableIdx2;
extern const u16 gRandomTable2[1024];

void CreateRandomTable(void);
u32 RandomLCG(void);

// 乱数を1つ引く, 候補選びや & 1 の分岐のように1つの値や判断を決めるときに使う
// 表はポインタとして引く, 配列の添字 gRandomTable[i] だと表の番地を先に作り, 添字を先に計算する原典と順番が合わない
static inline s32 Random(void) {
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  return ((u16*)gRandomTable)[gRandTableIdx];
}

// 乱数を1つ引く, x / y / z や角度と速さのように1つの物の値を続けて何個も決めるときに使う
// 先に表を手元に取ってから引くので, 続けて呼ぶと表の番地を1度だけ読んで使い回す形になる
static inline s32 RandomNext(void) {
  u16* table = gRandomTable;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  return table[gRandTableIdx];
}

// これで綺麗に書けないものが出てきた場合、別の形を検討する
#define Random2()                                  \
  ({                                               \
    gRandTableIdx2 = (gRandTableIdx2 + 1) & 0x3FF; \
    gRandomTable2[gRandTableIdx2];                 \
  })

#endif  // __INCLUDE_RANDOM_H__
