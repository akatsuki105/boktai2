#ifndef __INCLUDE_ENEMY_H__
#define __INCLUDE_ENEMY_H__

#include "gba/gba.h"
#include "msgbus.h"
#include "sprite.h"
#include "struct.h"

// MainSprite_AdvanceAnim の呼び出し(例: 0x081a64f4) で MainSprite にオフセットでアクセスしているので同じ構造体にありそう, また EnemyのInit関数で Malloc(128) しているのも根拠 (例: 0x08101da6)
typedef struct {
  MainSpriteGfx gfx;  // 0x00
  MainSprite s;       // 0x20
} EnemySpriteData;
static_assert(sizeof(EnemySpriteData) == 128);

#define ENEMY_HDR                      \
  Entity2UnkData unk_0;    /* 0x000 */ \
  EnemySpriteData* sprite; /* 0x044 */ \
  EntityMsgBox msgbox;     /* 0x048 */
// まだ800バイトくらいありそう,　個々のエネミーの解析をしていって共通部分がわかってきたらEnemy構造体にまとめていき、最後に個々のエネミーの共通部分を ENEMY_HDR で置き換える

typedef struct {
  ENEMY_HDR;  // 共通部分
} Enemy;

// data.c の "../enemy/system/eneinline.h" という文字列から察するに EnemyXXX_Init の関数サイズがすべて異様に大きいのは、共通部分を eneinline.h にまとめていてそれをインライン展開しているからだと思われる(なんで？)

#endif  // __INCLUDE_ENEMY_H__
