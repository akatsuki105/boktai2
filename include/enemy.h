#ifndef __INCLUDE_ENEMY_H__
#define __INCLUDE_ENEMY_H__

#include "gba/gba.h"
#include "sprite.h"
#include "struct.h"

typedef struct {
  Entity2UnkData unk_0;  // 0x000
  SpriteData* sprite;    // 0x044
  // まだ800バイトくらいありそう,　個々のエネミーの解析をしていって共通部分がわかってきたらEnemy構造体にまとめていき、最後に個々のエネミーの共通部分を Enemy で置き換える
} Enemy;

// data.c の "../enemy/system/eneinline.h" という文字列から察するに EnemyXXX_Init の関数サイズがすべて異様に大きいのは、共通部分を eneinline.h にまとめていてそれをインライン展開しているからだと思われる(なんで？)

#endif  // __INCLUDE_ENEMY_H__
