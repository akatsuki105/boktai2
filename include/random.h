#ifndef __INCLUDE_RANDOM_H__
#define __INCLUDE_RANDOM_H__

#include "gba/gba.h"

extern u32 gRngValue;

// まずは上位マクロの Random または _Random を使い、それで一致しない場合にのみ、直接 gRandomTable や gRandTableIdx を使ったコードを書くこと
extern s32 gRandTableIdx;
extern u16 gRandomTable[1024];

// 通信対戦でスコア計算に使用する別の乱数テーブル, gRandomTable2 は　ROMの定数で固定値であり、通信対戦参加者が同じ乱数テーブルを使う必要がある場面で使うものと思われる
extern s32 gRandTableIdx2;
extern const u16 gRandomTable2[1024];

void CreateRandomTable(void);
u32 RandomLCG(void);

// 今のところ、これが1番綺麗に書ける形, 複数箇所で使う場合は _Random を検討する
// static inline, statement expr, etc..., 数多くの検討したが正解(= 全ての使用箇所で綺麗にかける形)がどうしてもわからない
// インデックスとテーブルアクセス を分けて マクロ, static inline, statement expr, etc... も検討したがダメ, gRandomTable のアクセス方法, 他のデータ型の検討もやったがダメ
#define Random() (_Random(gRandomTable))

// 座標のノイズ値など、1度に複数の乱数を取得する場合 は これを使うと綺麗に書ける
// u16* table = gRandomTable; + 複数箇所で _Random(table, gRandTableIdx); と書くこと
#define _Random(__table) (gRandTableIdx = (gRandTableIdx + 1) & 0x3FF, *((__table) + gRandTableIdx))

// これで綺麗に書けないものが出てきた場合、別の形を検討する
#define Random2()                                  \
  ({                                               \
    gRandTableIdx2 = (gRandTableIdx2 + 1) & 0x3FF; \
    gRandomTable2[gRandTableIdx2];                 \
  })

#endif  // __INCLUDE_RANDOM_H__
