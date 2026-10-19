#ifndef __INCLUDE_BOSS_H__
#define __INCLUDE_BOSS_H__

#include "entity.h"
#include "gba/gba.h"

typedef s32 BossID;
#define BOSS_DUNEYRR 0             // ドゥネイル
#define BOSS_UNK_1 1               // ?
#define BOSS_DURATHROR 2           // ドゥラスロール
#define BOSS_DVALINN 3             // ドヴァリン
#define BOSS_UNK_4 4               // ?
#define BOSS_JORMUNGANDR 5         // ヨルムンガンド
#define BOSS_SHADEMAN 6            // シェードマン(シングルプレイ用)
#define BOSS_SHADEMAN_CROSSOVER 7  // シェードマン(クロスオーバーバトル用)

// Boss の共通部分の定義 (各ボスの構造体はこれを先頭に持つことを想定)
// 最終的には、 各ボスの構造体の先頭は struct Boss にする予定だが、まだ共通部分のサイズが確定してないので、保留
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
} Boss;

// 各Bossの構造体の最初の方は共通部分っぽい？ (もしそうなら、 ENEMY_HDR のように BOSS_HDR を定義するか, struct Boss を作る予定)
//
// 共通部分として確定しているフィールド (根拠: Boss_PlayAnimFacing / Boss_PlayAnim が全ボスから呼ばれ、この4つだけを触る)
//   0xA0  u8   facing       0..3 の向き, 1 か 2 のときだけ呼び出し側の variant を使い、2 以上で左右反転する
//   0xAE  u8   animVariant  facing から決まるアニメ番号のオフセット
//   0xAF  u8   xflip        0 以外なら MainSprite に SPRFLAG_XFLIP を立てる
//   0xB0  u16  animID       animVariant + 呼び出し側のアニメ番号, MainSprite_SetAnim に渡した値
// MainSprite / MainSpriteGfx は共通部分に入っていない (ボスごとに位置が違うので引数で渡される, 例: bee_0803aee4 は +0x280 / +0x260)

void FUN_08022a0c(Boss*, BossID);
void* FUN_08022a2c(BossID);
void FUN_08022b04(Boss*);
void FUN_08022e20(Boss*);
void FUN_08022ec0(Boss*);

#endif  // __INCLUDE_BOSS_H__
