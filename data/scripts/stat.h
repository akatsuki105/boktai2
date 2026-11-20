#ifndef __DATA_SCRIPTS_STAT_H__
#define __DATA_SCRIPTS_STAT_H__

// data/scripts/scripts.bokc で include する用, 名前は include/game.h の gStat のマクロと同じ
// 中身は .bokc のメモリ参照の綴りそのままにする (ダンパーはこの綴りと完全に一致する参照だけを名前で出す)
// .bokc では括弧が式の命令 (0x30) になってバイト列が変わるので, C のマクロと違って外側を括弧で囲まないこと
// 型はフィールドとスクリプトに合わせる, C のマクロが u16 / u32 で読むものも .bokc は s16 / s32 で読む (.bokc に u32 は無い)

#define UNK_008 *((s16 *)(stat + 0x8))
#define UNK_00A *((s16 *)(stat + 0xA))
#define UNK_00C *((s16 *)(stat + 0xC))
#define UNK_00E *((s16 *)(stat + 0xE))
#define CONTROL_UP *((s16 *)(stat + 0x10))
#define TEXT_SPEED *((s16 *)(stat + 0x12))
#define MARKER_ENABLE *((s16 *)(stat + 0x14))
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
#define PLAYER_LV *((s16 *)(stat + 0x40))
#define PLAYER_EXP *((s32 *)(stat + 0x50))
#define HEATSTROKE *((s16 *)(stat + 0x1BA))
#define THERMAL *((s32 *)(stat + 0x1BC))
#define DARK_DEBTS *((s32 *)(stat + 0x1C4))
#define UNK_1D4 *((s32 *)(stat + 0x1D4))
#define TREE_EXP *((s32 *)(stat + 0x1D8))
#define UNK_1DE *((s16 *)(stat + 0x1DE))
#define UNK_1E0 *((s32 *)(stat + 0x1E0))
#define UNK_1E4 *((s32 *)(stat + 0x1E4))
#define TOTAL_ALERT *((s16 *)(stat + 0x1E8))
#define TORTURE_COUNT *((s16 *)(stat + 0x1EC))
#define TITLES *((s16 *)(stat + 0x1EE))
#define TOTAL_ENEMY_KILL *((s16 *)(stat + 0x1F0))
#define BANK_RATE *((s16 *)(stat + 0x23A))
#define LAP *((s16 *)(stat + 0x240)) // 正確にはそのセーブデータでのストーリークリア回数, 1周目でラスボス撃破後の後日談のときは 1 になる
#define ROOM *((s16 *)(stat + 0x242))
#define UNK_244 *((s16 *)(stat + 0x244))
#define MAP_INIT_SCRID *((s32 *)(stat + 0x24C))
#define PLAYER_KIND *((s16 *)(stat + 0x250))  // C の PLAYER_KIND は Player_SaveState の一致のために u16 だが, フィールドもスクリプトも s16
#define UNK_252 *((s16 *)(stat + 0x252))
#define STAGE_ID *((s16 *)(stat + 0x254))
#define UNK_256 *((s16 *)(stat + 0x256))
#define UNK_258 *((s16 *)(stat + 0x258))
#define UNK_25A *((s16 *)(stat + 0x25A))
#define BERSERK_COUNTER *((s32 *)(stat + 0x2A8))
#define BOSS_HP *((s32 *)(stat + 0x2B8))
#define BOSS_HP_MAX *((s32 *)(stat + 0x2BC))
#define PLAY_TIME *((s32 *)(stat + 0x2B4))
#define PHOTOS *((s32 *)(stat + 0x3A8))
#define BP_SCORE *((s16 *)(stat + 0x3B0))
#define BP_MAX_COMBO *((s16 *)(stat + 0x3B2))
#define BP_BEST_SCORE *((s16 *)(stat + 0x3B4))
#define BP_BEST_COMBO *((s16 *)(stat + 0x3B6))
#define SOLAR_STAND *((s32 *)(stat + 0x3BC))
#define SOLAR_BANK *((s16 *)(stat + 0x910))
#define LINK_BATTLE_POINT *((s16 *)(stat + 0x912))
#define LINK_BATTLE_COUNT *((s16 *)(stat + 0x914))
#define LINK_BATTLE_WINS *((s16 *)(stat + 0x916))
#define LINK_SELL_COUNT *((s16 *)(stat + 0x918))
#define LINK_BUY_COUNT *((s16 *)(stat + 0x91A))
#define PLAYER_ACTION *((s16 *)(stat + 0x930))
#define SUN_ANGLE *((s16 *)(stat + 0x932))
#define MAP_FLAGS *((s16 *)(stat + 0x934))
#define UNK_938 *((s16 *)(stat + 0x938))
#define UNK_946 *((s16 *)(stat + 0x946))

// 添字付きの参照, [要素数, 添字] の要素数は VM が読み捨てるがバイト列には残るので, 宣言の要素数をそのまま書く
// 引数 i は括弧で囲まない (.bokc では括弧が式の命令になる)
#define STATS(n) ((s16 *)(stat + 0x18))[4, n]
#define STAT_BONUS(n) ((s16 *)(stat + 0x20))[4, n]
#define WEAPON_EXP(kind) ((s16 *)(stat + 0x46))[5, kind]
#define ENEMY_KILL_COUNT(i) ((s16 *)(stat + 0x1F2))[27, i]
#define FRIENDSHIP(i) ((s16 *)(stat + 0x2FE))[5, i]
#define ENEMY_DEX(i) ((s32 *)(stat + 0x388))[2, i]
#define ARMOR_DEX(i) ((s32 *)(stat + 0x3A0))[2, i]
#define PLAYER_NAME(i) ((s32 *)(stat + 0x3C0))[4, i]
#define WEAPON_DEX(i) ((s32 *)(stat + 0x920))[2, i]

#endif // __DATA_SCRIPTS_STAT_H__
