#ifndef __INCLUDE_LINK_SHOP_H__
#define __INCLUDE_LINK_SHOP_H__

#include "global.h"

// 回線に流す1通分のメッセージ, .kind 以外の意味は kind ごとに変わる
typedef struct LinkShopMsg {
  u16 kind;     // 0x00, 0 = 太陽バンクの残高, 1 = 名前, 2 = 武器の本数, 3-5/6-8/10-12 は呼び出し側が決める
  u16 unk_02;   // 0x02, LinkShopManager_Send の第3引数をそのまま乗せる, 読むのは受け取った側の onRecv
  s32 data[3];  // 0x04, kind 1 では GameInfo.name の12バイト, kind 0 は残高, kind 2 は売れる武器の本数2種
} LinkShopMsg;
static_assert(sizeof(LinkShopMsg) == 16);

#endif  // __INCLUDE_LINK_SHOP_H__
