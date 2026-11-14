#ifndef __DATA_SCRIPTS_STAT_H__
#define __DATA_SCRIPTS_STAT_H__

// data/scripts/scripts.bokc で include する用, 名前は include/game.h の gStat のマクロと同じ
// 中身は .bokc のメモリ参照の綴りそのままにする (ダンパーはこの綴りと完全に一致する参照だけを名前で出す)
// .bokc では括弧が式の命令 (0x30) になってバイト列が変わるので, C のマクロと違って外側を括弧で囲まないこと
// 型はフィールドとスクリプトに合わせる, C のマクロが u16 / u32 で読むものも .bokc は s16 / s32 で読む (.bokc に u32 は無い)

#define SAVED_HP *((s16 *)(stat + 0x28))
#define SAVED_MAX_HP *((s16 *)(stat + 0x2A))
#define SAVED_ENE *((s16 *)(stat + 0x2C))
#define SAVED_MAX_ENE *((s16 *)(stat + 0x2E))
#define PLAYER_X *((s16 *)(stat + 0x30))
#define PLAYER_Y *((s16 *)(stat + 0x32))
#define PLAYER_Z *((s16 *)(stat + 0x34))
#define PLAYER_DIR *((s16 *)(stat + 0x36))
#define SABATA_HP *((s16 *)(stat + 0x38))
#define SABATA_ENE *((s16 *)(stat + 0x3A))
#define PLAYER_EXP *((s32 *)(stat + 0x50))
#define HEATSTROKE *((s16 *)(stat + 0x1BA))
#define THERMAL *((s32 *)(stat + 0x1BC))
#define DARK_DEBTS *((s32 *)(stat + 0x1C4))
#define TREE_EXP *((s32 *)(stat + 0x1D8))
#define TORTURE_COUNT *((s16 *)(stat + 0x1EC))
#define LAP *((s16 *)(stat + 0x240))
#define ROOM *((s16 *)(stat + 0x242))
#define PLAYER_KIND *((s16 *)(stat + 0x250))  // C の PLAYER_KIND は Player_SaveState の一致のために u16 だが, フィールドもスクリプトも s16
#define STAGE_ID *((s16 *)(stat + 0x254))
#define BERSERK_COUNTER *((s32 *)(stat + 0x2A8))
#define BOSS_HP *((s32 *)(stat + 0x2B8))
#define BOSS_HP_MAX *((s32 *)(stat + 0x2BC))
#define PLAY_TIME *((s32 *)(stat + 0x2B4))
#define SOLAR_STAND *((s32 *)(stat + 0x3BC))
#define SOLAR_BANK *((s16 *)(stat + 0x910))
#define LINK_BATTLE_POINT *((s16 *)(stat + 0x912))
#define PLAYER_ACTION *((s16 *)(stat + 0x930))
#define SUN_ANGLE *((s16 *)(stat + 0x932))
#define MAP_FLAGS *((s16 *)(stat + 0x934))
#define UNK_946 *((s16 *)(stat + 0x946))

// 添字付きの参照, [要素数, 添字] の要素数は VM が読み捨てるがバイト列には残るので, 宣言の要素数をそのまま書く
// 引数 i は括弧で囲まない (.bokc では括弧が式の命令になる)
#define STATS(n) ((s16 *)(stat + 0x18))[4, n]
#define STAT_BONUS(n) ((s16 *)(stat + 0x20))[4, n]
#define WEAPON_EXP(kind) ((s16 *)(stat + 0x46))[5, kind]
#define ENEMY_KILL_COUNT(i) ((s16 *)(stat + 0x1F2))[27, i]
#define FRIENDSHIP(i) ((s16 *)(stat + 0x2FE))[5, i]

#endif // __DATA_SCRIPTS_STAT_H__
