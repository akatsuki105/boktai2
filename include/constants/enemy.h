#ifndef __INCLUDE_CONSTANTS_ENEMY_H__
#define __INCLUDE_CONSTANTS_ENEMY_H__

// EnemyCategoryID, GameInfo.enemyKillCount[24] の idx?
// http://raid.s500.xrea.com/code/gba/U32J/ によると 0x0203C5F2 から　敵の倒した数　をカウントしている
#define ENEMY_CAT_GHOUL 0   // グール系(グール, ゾンビ)
#define ENEMY_CAT_MUMMY 1   // マミー系(マミー, ガスト)
#define ENEMY_CAT_SPIDER 2  // スパイダー系(スパイダー, ポイズンスパイダー)
#define ENEMY_CAT_GOLEM 3
#define ENEMY_CAT_SKELETON 4
#define ENEMY_CAT_LICH 5
#define ENEMY_CAT_CENTIPEDE 6
#define ENEMY_CAT_COCKATRICE 7
#define ENEMY_CAT_MIMIC 8
#define ENEMY_CAT_SWORD 9
#define ENEMY_CAT_AXE 10
#define ENEMY_CAT_OCTOPUS 11
#define ENEMY_CAT_KLOROFOLUN 12  // クロロホルルン系
#define ENEMY_CAT_BAT 13
#define ENEMY_CAT_CLAW 14
#define ENEMY_CAT_BANDIT 15
#define ENEMY_CAT_SLIME 16
#define ENEMY_CAT_BEE 17
#define ENEMY_CAT_GHOST 18
#define ENEMY_CAT_SAND_WORM 19
#define ENEMY_CAT_SERPENT 20
#define ENEMY_CAT_CHEYENNE 21          // シャイアン
#define ENEMY_CAT_ROOT_OF_DARKNESS 22  // 暗黒の根

#endif  // __INCLUDE_CONSTANTS_ENEMY_H__
