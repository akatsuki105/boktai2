#ifndef __INCLUDE_ENEMY_H__
#define __INCLUDE_ENEMY_H__

#include "gba/gba.h"
#include "sprite.h"
#include "struct.h"

// FUN_082372cc の呼び出し(例: 0x081a64f4) で SpriteState にオフセットでアクセスしているので同じ構造体にありそう, また EnemyのInit関数で Malloc(128) しているのも根拠 (例: 0x08101da6)
typedef struct {
  SpriteSet tmpl;  // 0x00, スプライトのROMデータを指す構造体
  SpriteState s;   // 0x20
} EnemySpriteData;
static_assert(sizeof(EnemySpriteData) == 128);

#define ENEMY_HDR                      \
  Entity2UnkData unk_0;    /* 0x000 */ \
  EnemySpriteData* sprite; /* 0x044 */
// まだ800バイトくらいありそう,　個々のエネミーの解析をしていって共通部分がわかってきたらEnemy構造体にまとめていき、最後に個々のエネミーの共通部分を ENEMY_HDR で置き換える

// data.c の "../enemy/system/eneinline.h" という文字列から察するに EnemyXXX_Init の関数サイズがすべて異様に大きいのは、共通部分を eneinline.h にまとめていてそれをインライン展開しているからだと思われる(なんで？)

#endif  // __INCLUDE_ENEMY_H__
