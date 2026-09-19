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

// 各エネミー共通部. 最小のエネミー(Mimic)が1684バイトなのに対しここは0x654=1620バイトあり、構造体のほとんどが共通部分だとわかる
// サイズの根拠: Enemy_Init_080f3680 が 0x62C から 0x650 まで10本のテーブルポインタを書き込む
#define ENEMY_HDR                                                                                                   \
  Entity2UnkData unk_0;      /* 0x000 */                                                                            \
  EnemySpriteData* sprite;   /* 0x044 */                                                                            \
  EntityMsgBox msgbox;       /* 0x048 */                                                                            \
  u8 unk_7c[0x11C - 0x7C];   /* 0x07C */                                                                            \
  u16 unk_11c;               /* 0x11C, FUN_080edebc が 0 を書く */                                                  \
  u8 unk_11e[0x178 - 0x11E]; /* 0x11E */                                                                            \
  u32 flags;                 /* 0x178, bit0/1=活動停止判定, bit3=FUN_080ec92c が毎フレーム1体だけに立てる */        \
  u32 flags2;                /* 0x17C, bit21=FUN_080edebc がパレット転送の向きとして反転させる */                   \
  u16 flags3;                /* 0x180, bit14=FUN_080ec9b0 が立て FUN_080edebc が落とす */                           \
  u16 flags4;                /* 0x182, bit12 が立っていると FUN_080edebc が破棄側へ回す */                          \
  s16 unk_184;               /* 0x184, FUN_080ee254 が ldrsh で 1 未満かを判定 */                                   \
  u8 unk_186[0x1CC - 0x186]; /* 0x186 */                                                                            \
  void* unk_1cc;             /* 0x1CC, handlerUpdate/handlerDestroy の唯一の引数. 破棄時にこれが Free される */     \
  u8 unk_1d0[0x1DF - 0x1D0]; /* 0x1D0 */                                                                            \
  u8 kind;                   /* 0x1DF, 種族. 0x02/0x03/0x0B/0x0E/0x17/0x1B で分岐する */                            \
  u8 unk_1e0[0x25D - 0x1E0]; /* 0x1E0 */                                                                            \
  u8 spriteKind;             /* 0x25D, 0 なら sprite を AuxSprite 系、非0なら MainSprite 系として扱う */            \
  u8 unk_25e[0x260 - 0x25E]; /* 0x25E */                                                                            \
  void* unk_260;             /* 0x260, FUN_080eca74 が EnemyManager.sharedEntity の値を書き込む */                  \
  void* unk_264;             /* 0x264, 同上 (kind==0x0E のとき) */                                                  \
  u8 unk_268[0x468 - 0x268]; /* 0x268 */                                                                            \
  u8 unk_468;                /* 0x468, FUN_080f34ec 系が 2 か 3 を書く */                                           \
  u8 unk_469;                /* 0x469, handlerTables[1] [5] [7] [9] の添字 (ldrb) */                                \
  u8 unk_46a;                /* 0x46A, handlerTables[2] [3] [4] [6] [8] の添字 (ldrb) */                            \
  u8 unk_46b;                /* 0x46B, 0 が書かれる。読み手は FUN_080fa384 ほか */                                  \
  u8 unk_46c;                /* 0x46C, FUN_080f2644 が非0を条件にして 0 に戻す */                                   \
  u8 unk_46d;                /* 0x46D, FUN_080f54e4 が非0を条件にして 0 に戻す */                                   \
  u8 unk_46e;                /* 0x46E */                                                                            \
  u8 unk_46f;                /* 0x46F, FUN_080edebc が非0を条件にする */                                            \
  u8 unk_470[0x478 - 0x470]; /* 0x470 */                                                                            \
  u16 unk_478;               /* 0x478, パレット番号. EnemySpriteData の +0x32 / +0x5A に書かれる */                 \
  u16 unk_47a;               /* 0x47A, unk_480 と足して遷移先パレット番号になる */                                  \
  u8 unk_47c[0x480 - 0x47C]; /* 0x47C */                                                                            \
  s16 unk_480;               /* 0x480, FUN_080eca74 が 1 と比較 */                                                  \
  u8 unk_482[0x484 - 0x482]; /* 0x482 */                                                                            \
  u32 unk_484;               /* 0x484, handlerTables を切り替えるときに 0 でクリアされる */                         \
  u8 unk_488[0x48E - 0x488]; /* 0x488 */                                                                            \
  u8 unk_48e;                /* 0x48E, FUN_080ec9b0 のカウントダウン */                                             \
  u8 unk_48f;                /* 0x48F */                                                                            \
  u16 unk_490;               /* 0x490, gStat->unk_248 と一致するかを FUN_080edebc が見る */                         \
  u8 unk_492[0x4BE - 0x492]; /* 0x492 */                                                                            \
  u16 unk_4be;               /* 0x4BE, FUN_080edebc が 0 を書く */                                                  \
  u8 unk_4c0[0x57C - 0x4C0]; /* 0x4C0 */                                                                            \
  void* handlerMsg;          /* 0x57C, FUN_080ec758/080ec79c/080ec848 が (enemy, payload) で呼ぶ */                 \
  u8 unk_580[0x600 - 0x580]; /* 0x580 */                                                                            \
  void* unk_600;             /* 0x600, EnemyBat_Init がアドレスを取る。呼び出しは未発見 */                          \
  u8 unk_604[0x608 - 0x604]; /* 0x604 */                                                                            \
  void* unk_608;             /* 0x608, fn(p) として呼ばれる。FUN_080f22c4 ほか19関数が使う */                       \
  void* unk_60c;             /* 0x60C, 関数ポインタ表。FUN_080f09e0 が fn = unk_60c[arg[0]] を fn(p, arg) で呼ぶ */ \
  u8 unk_610[0x614 - 0x610]; /* 0x610 */                                                                            \
  void* unk_614;             /* 0x614, fn(p)。FUN_080fa384 が NULL でないときだけ呼ぶ */                            \
  void* unk_618;             /* 0x618, fn(p)。FUN_080f2364 / FUN_080f0430 */                                        \
  void* handlerUpdate;       /* 0x61C, FUN_080edebc が (unk_1cc) で毎フレーム呼ぶ */                                \
  void* handlerDestroy;      /* 0x620, FUN_080ee218 が (unk_1cc) で呼び、その後 unk_1cc を Free する */             \
  void* unk_624;             /* 0x624, fn(p)。FUN_080f06b0 が戻り値の下位1バイトを見る */                           \
  void* unk_628;             /* 0x628, fn(p)。FUN_080f06b0 が unk_624 の戻り値が 0 のときだけ呼ぶ */                \
  void* handlerTables[10];   /* 0x62C, 状態ごとの関数ポインタ表を10本。Enemy_Init_080f3680 が 0x62C から順にまとめて書き込む */

typedef struct {
  ENEMY_HDR;  // 共通部分
} Enemy;
static_assert(sizeof(Enemy) == 1620);

// data.c の "../enemy/system/eneinline.h" という文字列から察するに EnemyXXX_Init の関数サイズがすべて異様に大きいのは、共通部分を eneinline.h にまとめていてそれをインライン展開しているからだと思われる(なんで？)

// 生存中のエネミーを繋ぐ単方向リストのノード, 根拠: FUN_080ec614 が Malloc(8) して gEnemyListHead に繋ぐ
typedef struct EnemyListNode {
  struct EnemyListNode* next;  // 0x00, FUN_080ec6fc が削除時に前ノードの next へ付け替える
  Enemy* enemy;                // 0x04, Enemy_Init_080ec640 が登録対象を書く
} EnemyListNode;
static_assert(sizeof(EnemyListNode) == 8);

// 16色パレットのクロスフェード. FUN_080eeb14 が開始し、FUN_080eec74 が毎フレーム1段進める
typedef struct {
  u16 pltt[16];  // 0x00, r/g/b から合成した BGR555 の出力. EnemySpriteData のパレットポインタに直接繋がれる
  u16 timer;     // 0x20, FUN_080eeb14 が 0x20 をセットし FUN_080eec74 が毎フレーム -1
  u16 plttID;    // 0x22, 遷移先のパレット番号
  s16 r[16];     // 0x24, 5.5固定小数の現在値. 毎フレーム stepR が加算される
  s16 g[16];     // 0x44
  s16 b[16];     // 0x64
  s8 stepR[16];  // 0x84, FUN_080eeb14 が (遷移先 - 現在) を書く
  s8 stepG[16];  // 0x94
  s8 stepB[16];  // 0xA4
} EnemyPaletteFade;
static_assert(sizeof(EnemyPaletteFade) == 180);

extern EnemyListNode* gEnemyListHead;  // 0x03002C60

#endif  // __INCLUDE_ENEMY_H__
