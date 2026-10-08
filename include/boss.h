#ifndef __INCLUDE_BOSS_H__
#define __INCLUDE_BOSS_H__

#include "gba/gba.h"

typedef s32 BossID;  // see include/constants/miscs.h

// 各Bossの構造体の最初の方は共通部分っぽい？ (もしそうなら、 ENEMY_HDR のように BOSS_HDR を定義するか, struct Boss を作る予定)
//
// 共通部分として確定しているフィールド (根拠: Boss_PlayAnimFacing / Boss_PlayAnim が全ボスから呼ばれ、この4つだけを触る)
//   0xA0  u8   facing       0..3 の向き, 1 か 2 のときだけ呼び出し側の variant を使い、2 以上で左右反転する
//   0xAE  u8   animVariant  facing から決まるアニメ番号のオフセット
//   0xAF  u8   xflip        0 以外なら MainSprite に SPRFLAG_XFLIP を立てる
//   0xB0  u16  animID       animVariant + 呼び出し側のアニメ番号, MainSprite_SetAnim に渡した値
// MainSprite / MainSpriteGfx は共通部分に入っていない (ボスごとに位置が違うので引数で渡される, 例: bee_0803aee4 は +0x280 / +0x260)

void* FUN_08022a2c(BossID id);

#endif  // __INCLUDE_BOSS_H__
