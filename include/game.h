#ifndef GUARD_ZOKTAI_GAME_H
#define GUARD_ZOKTAI_GAME_H

#include "global.h"
#include "time.h"
#include "weapon.h"

#define REGISTERED_WEAPON(n) (*(gStat->registeredWeapon + n))
#define REGISTERED_MAGIC(n) (*(gStat->registeredMagic + n))

// 0x0203C400 (ハードリセット時, ソフトリセット時は配置先が変動する)
typedef struct {
  u32 magicNumber;            // 0x000, gScriptDirectoryBuildTime = 0x40A8186C がセットされる, ロード時にチェックしてそう
  u8 unk_004[14];             // 0x004
  u16 unk_012;                // 0x012
  u8 unk_14[4];               // 0x014
  u16 stats[STAT_KINDS * 2];  // 0x018, ステータスポイントの割り振り と (多分タロットカードの)ドーピングボーナス, ステータス画面には合計値が表示される
  u16 savedHP;                // 0x028, コンティニュー用？
  u16 savedMaxHP;             // 0x02A
  u16 savedEne;               // 0x02C
  u16 savedMaxEne;            // 0x02E

  // ここから .unk_3ba まで FUN_08231ca8 で ClearMemory されているので、ここから .unk_3ba(の直前) までが別の構造体として定義されているかもしれない
  Vec3 playerPos;                // 0x030, プレイヤーの座標
  u16 sabataHP;                  // 0x038
  u16 sabataEne;                 // 0x03A
  u8 unk_03c[4];                 // 0x03C
  s16 lv;                        // 0x040
  u16 statusPoint;               // 0x042
  u16 unk_44;                    // 0x044
  s16 weaponExp[5];              // 0x046, 剣/槍/ハンマー/拳/銃 の経験値, 100たまると1レベルアップなので、 100 で割るとレベル(ステータスに表示される数値)になる
  u32 exp;                       // 0x050, 総経験値
  u32 unlockedMagic;             // 0x054
  s16 equippedWeaponIdx;         // 0x058
  s16 equippedMagicIdx;          // 0x05A, 登録された4つの魔法のうち、フィールドで選択している魔法のインデックス(0~3)
  slot16_t armor;                // 0x05C
  u8 unk_5e[2];                  // 0x05E
  slot16_t registeredWeapon[4];  // 0x060
  magic16_t registeredMagic[4];  // 0x068
  item16_t items[16 + 16 + 16];  // 0x070
  s16 rotTimer[16 + 16 + 16];    // 0x0D0, if MSB is set, item is chocolate-covered
  item16_t valuables[16];        // 0x130
  armor16_t armors[16];          // 0x150
  u8 unk_170[40];                // 0x170
  BCDDate date;                  // 0x198
  u32 hour;                      // 0x19C
  u32 minute;                    // 0x1A0
  bool32 isClockTowerBellDone;   // 0x1A4, すでに夕方か(時計塔の鐘の音がなったか)
  Datetime overheatTime;         // 0x1A8
  s16 unk_1b8;                   // 0x1B8
  s16 heatstroke;                // 0x1BA, オーバーヒート時に太陽ゲージが3以上あると増える, 5000を超えると気絶
  s32 thermal;                   // 0x1BC, 30000に到達したらオーバーヒート
  u8 unk_1c0[4];                 // 0x1C0
  u32 darkDebts;                 // 0x1C4, 実際に返す必要のある額
  u8 unk_1c8[12];                // 0x1C8
  u32 loan_1d4;                  // 0x1D4
  u32 treeExp;                   // 0x1D8
  u8 unk_1dc[18];                // 0x1DC
  u16 titles;                    // 0x1EE, 獲得した称号のビットマスク
  s16 totalEnemyKillCount;       // 0x1F0
  s16 enemyKillCount[24];        // 0x1F2, idx: include/constants/enemy.h の EnemyCategoryID?
  u16 unk_222;                   // 0x222
  u8 unk_224[22];                // 0x224
  s16 solarBankInterestRate;     // 0x23A, Solar bank interest rate (stored as (1+r)*64, e.g. 14.0625% = 73). Defaults to 65 when starting a new game.
  u8 unk_23c[4];                 // 0x23C
  s16 unk_240;                   // 0x240
  u8 unk_242[4];                 // 0x242
  u16 unk_246;                   // 0x246, FUN_08231ca8
  s32 unk_248;                   // 0x248, Entity83B2_Update で何かのIDとして使う? これをいじると Entity83B2 が機能しなくなる (戻すと機能する)
  s32 mapInitScriptID;           // 0x24C, Current map's init script ID
  s16 playerKind;                // 0x250, see PlayerKind in player.h
  coffin16_t coffin;             // 0x252
  s16 areaID;                    // 0x254, current area ID
  u8 unk_256[10];                // 0x256
  u32 unlockedMap;               // 0x260
  u8 unk_264[68];                // 0x264
  u32 darkDjangoAtkCounter;      // 0x2A8
  u32 unk_2ac;                   // 0x2AC
  s16 unk_2b0[2];                // 0x2B0
  u32 playTime;                  // 0x2B4, ゲーム開始からの経過時間(秒)
  u8 unk_2b8[8];                 // 0x2B8
  u8 unk_2c0[56];                // 0x2C0
  u16 side;                      // 0x2F8, 赤(SolarDjango)寄りか黒(Dark)寄りか, 次の3つのどれかを取る, 0: 赤, 1: 中立, 2: 黒
  u16 style;                     // 0x2FA, プレイ中、最も使用フレーム数が多かった攻撃種別, see AttackStyle
  u16 forge;                     // 0x2FC, 0..127, 用途まだ不明
  s16 unk_2fe[5];                // 0x2FE
  u8 unk_308[128];               // 0x308
  s32 unk_388;                   // 0x388
  s32 unk_38c;                   // 0x38C
  u8 unk_390[16];                // 0x390
  u32 armorDex[2];               // 0x3A0
  u32 photo;                     // 0x3A8, ブロマイドの取得フラグ, アルバム画面のカーソル位置とbitが対応してそう
  u8 unk_3ac[12];                // 0x3AC

  // セーブ時には ここからweaponDexまで をセーブデータとして扱っている (根拠: FUN_08241224)
  u8 unk_3b8[2];                 // 0x3B8
  u8 unk_3ba[2];                 // 0x3BA
  u32 solarStand;                // 0x3BC
  u8 name[16];                   // 0x3C0, JP: 5文字, EN: 9文字
  Weapon weapons[16 + 16 + 16];  // 0x3D0
  u16 solarBank;                 // 0x910
  u8 unk_912[2];                 // 0x912
  u16 linkBattles;               // 0x914, 根拠: bokpass
  u8 unk_916[2];                 // 0x916
  u8 unk_918[8];                 // 0x918, bokpass に記述があるが、用途も型も不明
  u32 weaponDex[2];              // 0x920
  //

  // これ以降はセーブデータには含まれない(太陽ゲージなどのtmpデータ?)
  u8 unk_928[12];  // 0x928
  u16 unk_934;     // 0x934, UpdateOverheat
  u8 unk_936[4];   // 0x936
  s16 unk_93a;     // 0x93A
  u8 unk_93c[4];   // 0x93C
  u16 lx;          // 0x940, 太陽光の強さ(ルクス), ライジングサンの効果も反映される,
  s16 sunGauge;    // 0x942, 現在の太陽ゲージ ライジングサンによる太陽ゲージも反映される, ゲームと同じく 0..10
  u8 unk_944[20];  // 0x944
} GameInfo;
static_assert(sizeof(GameInfo) == 2392);

typedef struct {
  u8 unk_000[1024];  // 0x000
} World;
static_assert(sizeof(World) == 1024);

typedef struct {
  u8 unk_000[1024];  // 0x000
} UnkGameStruct;
static_assert(sizeof(UnkGameStruct) == 1024);  // Script_StorePointer で World と別扱いしているので World とはサイズが同じだけの別の構造体として定義しておく

// --------------------------------------------

extern UnkGameStruct* gScratch;  // 0x03004690, 多分VM用のスクラッチパッド
extern World* gWorldBackup;      // 0x03004694, ハード起動時は 0x0203DE00, 特定のタイミング(トランジションや死亡時)で、 gWorld の内容をこっちに反映する, ゲームをセーブする際にはこのデータを EEPROM に書き込む
extern World* gWorld;            // 0x03004698, ハード起動時は 0x0203DA00, ゲームプレイ中はこのデータを参照・更新する
extern GameInfo* gStatBackup;    // 0x0300469C, ハード起動時は 0x0203CF00, gWorldBackup と同じ
extern GameInfo* gStat;          // 0x030046A0, ハード起動時は 0x0203C400

#endif  // GUARD_ZOKTAI_GAME_H
