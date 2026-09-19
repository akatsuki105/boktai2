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

// Enemy.flags (0x178)
typedef u32 EnemyFlags;
#define ENEFLAG_UNK_0 (1 << 0)    // 0x00000001, bit1 と合わせて FUN_080ec968 が「数えない敵」の判定に使う
#define ENEFLAG_UNK_1 (1 << 1)    // 0x00000002, 同上
#define ENEFLAG_UNK_3 (1 << 3)    // 0x00000008, FUN_080ec92c が巡回カーソルの通過印として立てる
#define ENEFLAG_UNK_4 (1 << 4)    // 0x00000010, FUN_080ecbe8 が立てる
#define ENEFLAG_UNK_12 (1 << 12)  // 0x00001000, FUN_080ed068 / FUN_080edebc が立てる
#define ENEFLAG_UNK_13 (1 << 13)  // 0x00002000, FUN_080ef5a8 が立てる
#define ENEFLAG_UNK_17 (1 << 17)  // 0x00020000, FUN_080ef5a8 が立てる

// Enemy.flags2 (0x17C)
typedef u32 EnemyFlags2;
#define ENEFLAG2_UNK_17 (1 << 17)  // 0x00020000, FUN_080ecf18 / FUN_080ed020 が「数えない敵」の判定に使う
#define ENEFLAG2_UNK_21 (1 << 21)  // 0x00200000, FUN_080edebc がパレット転送の向きとして反転させる
#define ENEFLAG2_UNK_24 (1 << 24)  // 0x01000000, FUN_080ef5a8 が落とす
#define ENEFLAG2_UNK_25 (1 << 25)  // 0x02000000, Enemy_Init_080ec640 が見る
#define ENEFLAG2_UNK_26 (1 << 26)  // 0x04000000, FUN_080ef4e4 が VM キーワード 0x66 で立て下げする

// Enemy.flags3 (0x180)
typedef u16 EnemyFlags3;
#define ENEFLAG3_UNK_12 (1 << 12)  // 0x1000, FUN_080ee738 が見る
#define ENEFLAG3_UNK_14 (1 << 14)  // 0x4000, FUN_080ec9b0 が立て FUN_080edebc が落とす

// Enemy.flags4 (0x182)
typedef u16 EnemyFlags4;
#define ENEFLAG4_UNK_1 (1 << 1)    // 0x0002, Enemy_Sleep が立てる
#define ENEFLAG4_UNK_12 (1 << 12)  // 0x1000, 立っていると FUN_080edebc が破棄側へ回す

// Enemy.flags5 (0x474)
typedef u16 EnemyFlags5;
#define ENEFLAG5_UNK_8 (1 << 8)  // 0x0100, FUN_080ed834 / FUN_080ed8f0 / FUN_080ed9d0 が見る

// handlerUpdate / handlerDestroy の型. 引数は unk_1cc ひとつで、戻り値は誰も使っていない
typedef void (*EnemyHandler)(void* p);

// handlerMsg の型. FUN_080ec758 / FUN_080ec79c / FUN_080ec848 が (enemy, payload) で呼ぶ
typedef void (*EnemyMsgHandler)(void* p, void* payload);

// 各エネミー共通部. 最小のエネミー(Mimic)が1684バイトなのに対しここは0x654=1620バイトあり、構造体のほとんどが共通部分だとわかる
// サイズの根拠: Enemy_Init_080f3680 が 0x62C から 0x650 まで10本のテーブルポインタを書き込む
#define ENEMY_HDR                                                                                                     \
  Entity2UnkData unk_0;        /* 0x000 */                                                                            \
  EnemySpriteData* sprite;     /* 0x044 */                                                                            \
  EntityMsgBox msgbox;         /* 0x048 */                                                                            \
  u8 unk_7c[0x11C - 0x7C];     /* 0x07C */                                                                            \
  u16 unk_11c;                 /* 0x11C, FUN_080edebc が 0 を書く */                                                  \
  u8 unk_11e[0x178 - 0x11E];   /* 0x11E */                                                                            \
  EnemyFlags flags;            /* 0x178, bit0/1=活動停止判定, bit3=FUN_080ec92c が毎フレーム1体だけに立てる */        \
  EnemyFlags2 flags2;          /* 0x17C, bit21=FUN_080edebc がパレット転送の向きとして反転させる */                   \
  EnemyFlags3 flags3;          /* 0x180, bit14=FUN_080ec9b0 が立て FUN_080edebc が落とす */                           \
  EnemyFlags4 flags4;          /* 0x182, bit12 が立っていると FUN_080edebc が破棄側へ回す */                          \
  s16 unk_184;                 /* 0x184, FUN_080ee254 が ldrsh で 1 未満かを判定 */                                   \
  u8 unk_186[0x190 - 0x186]; /* 0x186 */ \
  u16 unk_190;               /* 0x190, Enemy_Sleep が unk_192 へ写す */ \
  u16 unk_192;               /* 0x192, Enemy_Sleep / FUN_080ed564 / FUN_080ee738 が書く */ \
  u8 unk_194[0x1C8 - 0x194]; /* 0x194 */ \
  u16 unk_1c8;                 /* 0x1C8, 状態を切り替えるときに 0 でクリアされる */                                   \
  u8 unk_1ca[0x1CC - 0x1CA];   /* 0x1CA */                                                                            \
  void* unk_1cc;               /* 0x1CC, handlerUpdate/handlerDestroy の唯一の引数. 破棄時にこれが Free される */     \
  u8 unk_1d0[0x1DF - 0x1D0];   /* 0x1D0 */                                                                            \
  u8 kind;                     /* 0x1DF, 種族. 0x02/0x03/0x0B/0x0E/0x17/0x1B で分岐する */                            \
  u8 unk_1e0[0x25D - 0x1E0];   /* 0x1E0 */                                                                            \
  u8 spriteKind;               /* 0x25D, 0 なら sprite を AuxSprite 系、非0なら MainSprite 系として扱う */            \
  u8 unk_25e[0x260 - 0x25E];   /* 0x25E */                                                                            \
  void* unk_260;               /* 0x260, FUN_080eca74 が EnemyManager.sharedEntity の値を書き込む */                  \
  void* unk_264;               /* 0x264, 同上 (kind==0x0E のとき) */                                                  \
  u8 unk_268[0x468 - 0x268];   /* 0x268 */                                                                            \
  u8 unk_468;                  /* 0x468, FUN_080f34ec 系が 2 か 3 を書く */                                           \
  u8 unk_469;                  /* 0x469, handlerTables[1] [5] [7] [9] の添字 (ldrb) */                                \
  u8 unk_46a;                  /* 0x46A, handlerTables[2] [3] [4] [6] [8] の添字 (ldrb) */                            \
  u8 unk_46b;                  /* 0x46B, 0 が書かれる。読み手は FUN_080fa384 ほか */                                  \
  u8 unk_46c;                  /* 0x46C, FUN_080f2644 が非0を条件にして 0 に戻す */                                   \
  u8 unk_46d;                  /* 0x46D, FUN_080f54e4 が非0を条件にして 0 に戻す */                                   \
  u8 unk_46e;                  /* 0x46E */                                                                            \
  u8 unk_46f;                  /* 0x46F, FUN_080edebc が非0を条件にする */                                            \
  u8 unk_470[0x474 - 0x470]; /* 0x470 */ \
  EnemyFlags5 flags5;        /* 0x474 */ \
  u8 unk_476[0x478 - 0x476]; /* 0x476 */ \
  u16 unk_478;                 /* 0x478, パレット番号. EnemySpriteData の +0x32 / +0x5A に書かれる */                 \
  u16 unk_47a;                 /* 0x47A, unk_480 と足して遷移先パレット番号になる */                                  \
  u8 unk_47c[0x480 - 0x47C];   /* 0x47C */                                                                            \
  s16 unk_480;                 /* 0x480, FUN_080eca74 が 1 と比較 */                                                  \
  u8 unk_482[0x484 - 0x482];   /* 0x482 */                                                                            \
  u32 unk_484;                 /* 0x484, handlerTables を切り替えるときに 0 でクリアされる */                         \
  u8 unk_488[0x48E - 0x488];   /* 0x488 */                                                                            \
  u8 unk_48e;                  /* 0x48E, FUN_080ec9b0 のカウントダウン */                                             \
  u8 unk_48f;                  /* 0x48F */                                                                            \
  u16 unk_490;                 /* 0x490, gStat->unk_248 と一致するかを FUN_080edebc が見る */                         \
  u8 unk_492[0x498 - 0x492];   /* 0x492 */                                                                            \
  u32 unk_498;                 /* 0x498, FUN_080ef5a8 が 0x40 を書く */                                               \
  u8 unk_49c[0x4A0 - 0x49C];   /* 0x49C */                                                                            \
  u32 unk_4a0;                 /* 0x4A0, FUN_080ef5a8 が 0x20 を書く */                                               \
  u8 unk_4a4[0x4BE - 0x4A4];   /* 0x4A4 */                                                                            \
  u16 unk_4be;                 /* 0x4BE, FUN_080edebc が 0 を書く */                                                  \
  u8 unk_4c0[0x553 - 0x4C0];   /* 0x4C0 */                                                                            \
  u8 state;                    /* 0x553, 状態番号. handlerState と同時に書き換えられる */                             \
  u8 unk_554[0x55C - 0x554];   /* 0x554 */                                                                            \
  u32 unk_55c;                 /* 0x55C, flags の初期値. FUN_080ee738 が flags へそのままコピーする */                \
  u32 unk_560;                 /* 0x560, flags2 の初期値. 同じく flags2 へコピーされる */                             \
  u8 unk_564[0x578 - 0x564];   /* 0x564 */                                                                            \
  void* handlerState;          /* 0x578, 状態ハンドラ. Thumb のコードアドレスが入る */                                \
  EnemyMsgHandler handlerMsg;  /* 0x57C, FUN_080ec758/080ec79c/080ec848 が (enemy, payload) で呼ぶ */                 \
  u8 unk_580[0x594 - 0x580]; /* 0x580 */ \
  void* unk_594;             /* 0x594, Enemy_Sleep が非NULLのときだけ動く */ \
  u8 unk_598[0x5C0 - 0x598]; /* 0x598 */ \
  void* unk_5c0;               /* 0x5C0, 既定の状態ハンドラ. FUN_080ed724 が handlerState へコピーする */             \
  u8 unk_5c4[0x600 - 0x5C4];   /* 0x5C4 */                                                                            \
  void* unk_600;               /* 0x600, EnemyBat_Init がアドレスを取る。呼び出しは未発見 */                          \
  u8 unk_604[0x608 - 0x604];   /* 0x604 */                                                                            \
  void* unk_608;               /* 0x608, fn(p) として呼ばれる。FUN_080f22c4 ほか19関数が使う */                       \
  void* unk_60c;               /* 0x60C, 関数ポインタ表。FUN_080f09e0 が fn = unk_60c[arg[0]] を fn(p, arg) で呼ぶ */ \
  u8 unk_610[0x614 - 0x610];   /* 0x610 */                                                                            \
  void* unk_614;               /* 0x614, fn(p)。FUN_080fa384 が NULL でないときだけ呼ぶ */                            \
  void* unk_618;               /* 0x618, fn(p)。FUN_080f2364 / FUN_080f0430 */                                        \
  EnemyHandler handlerUpdate;  /* 0x61C, FUN_080edebc が (unk_1cc) で毎フレーム呼ぶ */                                \
  EnemyHandler handlerDestroy; /* 0x620, FUN_080ee218 が (unk_1cc) で呼び、その後 unk_1cc を Free する */             \
  void* unk_624;               /* 0x624, fn(p)。FUN_080f06b0 が戻り値の下位1バイトを見る */                           \
  void* unk_628;               /* 0x628, fn(p)。FUN_080f06b0 が unk_624 の戻り値が 0 のときだけ呼ぶ */                \
  void* handlerTables[10];     /* 0x62C, 状態ごとの関数ポインタ表を10本。Enemy_Init_080f3680 が 0x62C から順にまとめて書き込む */

typedef struct {
  ENEMY_HDR;  // 共通部分
} Enemy;
static_assert(sizeof(Enemy) == 1620);

// ビットのセット/クリアはこのヘルパー経由で書く。フィールドごとに専用のものが要る
// (幅で共通化して u32* を渡す形にすると、if/else の両腕が同じ形になって str が1つに畳まれ一致しない)
static inline void Enemy_SetFlag(Enemy* p, EnemyFlags bit) { p->flags |= bit; }
static inline void Enemy_SetFlag2(Enemy* p, EnemyFlags2 bit) { p->flags2 |= bit; }
static inline void Enemy_ClearFlag2(Enemy* p, EnemyFlags2 bit) { p->flags2 &= ~bit; }
static inline void Enemy_SetFlag4(Enemy* p, EnemyFlags4 bit) { p->flags4 |= bit; }

// data.c の "../enemy/system/eneinline.h" という文字列から察するに EnemyXXX_Init の関数サイズがすべて異様に大きいのは、共通部分を eneinline.h にまとめていてそれをインライン展開しているからだと思われる(なんで？)

// 生存中のエネミーを繋ぐ単方向リストのノード, 根拠: EnemyManager_InitList が Malloc(8) して gEnemyListHead に繋ぐ
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

u8 FUN_080e8a60(Enemy* p);
bool32 Enemy_Init_080ec640(Enemy* p);

#endif  // __INCLUDE_ENEMY_H__
