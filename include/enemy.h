#ifndef __INCLUDE_ENEMY_H__
#define __INCLUDE_ENEMY_H__

#include "collision_map.h"
#include "eff_082473e0.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "mover.h"
#include "msgbus.h"
#include "shadow.h"
#include "sprite.h"
#include "struct.h"

struct EnemyTarget;

// data.c の "../enemy/system/eneinline.h" という文字列から察するに EnemyXXX_Init の関数サイズがすべて異様に大きいのは、共通部分を eneinline.h にまとめていてそれをインライン展開しているからだと思われる(なんで？)

// MainSprite_AdvanceAnim の呼び出し(例: 0x081a64f4) で MainSprite にオフセットでアクセスしているので同じ構造体にありそう, また EnemyのInit関数で Malloc(128) しているのも根拠 (例: 0x08101da6)
typedef struct {
  MainSpriteGfx gfx;  // 0x00
  MainSprite s;       // 0x20
} EnemySpriteData;
static_assert(sizeof(EnemySpriteData) == 128);

// spriteKind == 0 のときの Enemy.sprite の見え方, 同じ128バイトを AuxSprite 系として使う
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxSpriteGfx gfx;       // 0x2C, 根拠: FUN_080f6868 が Video_SetAuxSpritePltt に渡す
  AuxAnimState anim;      // 0x48, AuxAnim_SetAnim に animFile と一緒に渡る
  AuxAnimFile* animFile;  // 0x58
} EnemyAuxSpriteData;
static_assert(sizeof(EnemyAuxSpriteData) == 92);

// Enemy.unk_222 (0x222)
typedef u16 EnemyFlags222;
#define ENEMY222_UNK_0 (1 << 0)  // FUN_080f624c が unk_1e4 < 0x100000 のときだけ立てる
#define ENEMY222_UNK_1 (1 << 1)  // FUN_080f0320 が落とす
#define ENEMY222_UNK_2 (1 << 2)  // FUN_080f0e78 が見る

// Enemy.flags (0x178)
typedef u32 EnemyFlags;
#define ENEFLAG_UNK_0 (1 << 0)    // 0x00000001, bit1 と合わせて FUN_080ec968 が「数えない敵」の判定に使う
#define ENEFLAG_UNK_1 (1 << 1)    // 0x00000002, 同上
#define ENEFLAG_UNK_3 (1 << 3)    // 0x00000008, FUN_080ec92c が巡回カーソルの通過印として立てる
#define ENEFLAG_UNK_4 (1 << 4)    // 0x00000010, FUN_080ecbe8 が立てる
#define ENEFLAG_UNK_6 (1 << 6)    // 0x00000040, FUN_080f46a4 がまとめて落とす
#define ENEFLAG_UNK_7 (1 << 7)    // 0x00000080, FUN_080f46a4 がまとめて落とす
#define ENEFLAG_UNK_8 (1 << 8)    // 0x00000100, FUN_080f46a4 がまとめて落とす
#define ENEFLAG_UNK_10 (1 << 10)  // 0x00000400, FUN_080f54e4 が状態23へ移すときに立てる
#define ENEFLAG_UNK_12 (1 << 12)  // 0x00001000, FUN_080ed068 / FUN_080edebc が立てる
#define ENEFLAG_UNK_13 (1 << 13)  // 0x00002000, Cmd_1E97 が立てる
#define ENEFLAG_UNK_14 (1 << 14)  // 0x00004000, FUN_080f46a4 がまとめて落とす
#define ENEFLAG_UNK_16 (1 << 16)  // 0x00010000, FUN_080f46a4 がまとめて落とす
#define ENEFLAG_UNK_17 (1 << 17)  // 0x00020000, Cmd_1E97 が立てる
#define ENEFLAG_UNK_22 (1 << 22)  // 0x00400000, FUN_080f2364 が立っているときだけ経路を進める
#define ENEFLAG_UNK_20 (1 << 20)  // 0x00100000, FUN_080f0a0c が UNK_24 と揃って立っているときだけ相手を取りに行く
#define ENEFLAG_UNK_21 (1 << 21)  // 0x00200000, FUN_080e5b2c が立っているときだけ ENEFLAG2_UNK_24 などを落とす
#define ENEFLAG_UNK_24 (1 << 24)  // 0x01000000, 同上
#define ENEFLAG_UNK_25 (1 << 25)  // 0x02000000, FUN_080f6868 が立てる
#define ENEFLAG_UNK_26 (1 << 26)  // 0x04000000, FUN_080f65a8 が落とす
#define ENEFLAG_UNK_27 (1 << 27)  // 0x08000000, FUN_080f0320 が追う相手を見つけたときに立てる

// Enemy.flags2 (0x17C)
typedef u32 EnemyFlags2;
#define ENEFLAG2_UNK_0 (1 << 0)    // 0x00000001, FUN_080f56ec が立っていればエモートを 2 番にして落とす
#define ENEFLAG2_UNK_1 (1 << 1)    // 0x00000002, FUN_080f6c74 が状態29へ入るときに落とす
#define ENEFLAG2_UNK_2 (1 << 2)    // 0x00000004, 立っていると FUN_080f84d4 が反応しない
#define ENEFLAG2_UNK_4 (1 << 4)    // 0x00000010, FUN_080f47c8 が立っているときだけ状態14へ遷移する
#define ENEFLAG2_UNK_5 (1 << 5)    // 0x00000020, FUN_080f2864 が下位状態の終わりで立て, 経路ノードを進めるときに落とす
#define ENEFLAG2_UNK_9 (1 << 9)    // 0x00000200, Enemy_SetEmote が FUN_080d9cec に 0/1 で渡す
#define ENEFLAG2_UNK_6 (1 << 6)    // 0x00000040, FUN_080f5c0c が落とす
#define ENEFLAG2_UNK_8 (1 << 8)    // 0x00000100, FUN_080f5c0c が落とす
#define ENEFLAG2_UNK_11 (1 << 11)  // 0x00000800, FUN_080e49c4 が立っているときだけ ENEFLAG4_UNK_12 へ進む
#define ENEFLAG2_UNK_14 (1 << 14)  // 0x00004000, FUN_080f6868 が落とす
#define ENEFLAG2_UNK_15 (1 << 15)  // 0x00008000, 立っていると FUN_080f00ec が見つかった回数を数えない
#define ENEFLAG2_UNK_16 (1 << 16)  // 0x00010000, FUN_080e191c がアニメの頭で Entity1DBE_TouchElemNear を呼んで落とす
#define ENEFLAG2_UNK_17 (1 << 17)  // 0x00020000, FUN_080ecf18 / FUN_080ed020 が「数えない敵」の判定に使う
#define ENEFLAG2_UNK_18 (1 << 18)  // 0x00040000, FUN_080e6978 が状態21へ入るときに立てる
#define ENEFLAG2_UNK_19 (1 << 19)  // 0x00080000, FUN_080f44f4 が立てる
#define ENEFLAG2_UNK_20 (1 << 20)  // 0x00100000, 立っていると FUN_080e4b3c が落下させず水平に滑らせる
#define ENEFLAG2_UNK_21 (1 << 21)  // 0x00200000, FUN_080edebc がパレット転送の向きとして反転させる
#define ENEFLAG2_UNK_22 (1 << 22)  // 0x00400000, FUN_080e850c が立っていれば鳴らさずに落とす
#define ENEFLAG2_UNK_24 (1 << 24)  // 0x01000000, Cmd_1E97 が落とす
#define ENEFLAG2_UNK_25 (1 << 25)  // 0x02000000, Enemy_Init_080ec640 が見る
#define ENEFLAG2_UNK_26 (1 << 26)  // 0x04000000, Cmd_E1C6 が '.f' で立て下げする
#define ENEFLAG2_UNK_27 (1 << 27)  // 0x08000000, FUN_080f6c74 が立っているときだけ状態29へ移す

// Enemy.flags3 (0x180)
typedef u16 EnemyFlags3;
#define ENEFLAG3_UNK_0 (1 << 0)    // 0x0001, FUN_080fc174 が落とす
#define ENEFLAG3_UNK_1 (1 << 1)    // 0x0002, FUN_080f1cb8 が見る
#define ENEFLAG3_UNK_2 (1 << 2)    // 0x0004, Enemy_PlayVoice が UNK_1 と一緒に見る
#define ENEFLAG3_UNK_3 (1 << 3)    // 0x0008, FUN_080f1ef8 がまとめて見る
#define ENEFLAG3_UNK_4 (1 << 4)    // 0x0010, FUN_080f0a0c が UNK_12 と並べて見る
#define ENEFLAG3_UNK_5 (1 << 5)    // 0x0020, FUN_080f65a8 が立てる
#define ENEFLAG3_UNK_6 (1 << 6)    // 0x0040, Enemy_IsDead が死亡扱いにする
#define ENEFLAG3_UNK_7 (1 << 7)    // 0x0080, FUN_080f62b0 が UNK_8/9 とまとめて落とす
#define ENEFLAG3_UNK_8 (1 << 8)    // 0x0100, FUN_080f8400 が落とす
#define ENEFLAG3_UNK_9 (1 << 9)    // 0x0200, FUN_080e6148 が経路を外れたときに落とす
#define ENEFLAG3_UNK_10 (1 << 10)  // 0x0400, FUN_080f00ec が落とす
#define ENEFLAG3_UNK_11 (1 << 11)  // 0x0800, FUN_080e59d0 が一度だけ処理する印として立てる
#define ENEFLAG3_UNK_12 (1 << 12)  // 0x1000, FUN_080ee738 が見る
#define ENEFLAG3_UNK_13 (1 << 13)  // 0x2000, FUN_08101bc0 が unk_4be より優先して見る
#define ENEFLAG3_UNK_14 (1 << 14)  // 0x4000, FUN_080ec9b0 が立て FUN_080edebc が落とす
#define ENEFLAG3_UNK_15 (1 << 15)  // 0x8000, FUN_080f1ef8 がまとめて見る

// Enemy.flags4 (0x182)
typedef u16 EnemyFlags4;
#define ENEFLAG4_UNK_0 (1 << 0)    // 0x0001, FUN_080f6e34 がまとめて落とす
#define ENEFLAG4_UNK_1 (1 << 1)    // 0x0002, Enemy_Sleep が立てる
#define ENEFLAG4_UNK_2 (1 << 2)    // 0x0004, FUN_080eafdc が真っ先に見て UNK_0/1/7/8/11 とまとめて落とす
#define ENEFLAG4_UNK_3 (1 << 3)    // 0x0008, FUN_080f6e34 がまとめて落とす
#define ENEFLAG4_UNK_4 (1 << 4)    // 0x0010, FUN_080fc174 が立てる
#define ENEFLAG4_UNK_5 (1 << 5)    // 0x0020, FUN_080e72b0 が4フレームおきに立てる
#define ENEFLAG4_UNK_6 (1 << 6)    // 0x0040, FUN_080f6e34 がまとめて落とす
#define ENEFLAG4_UNK_7 (1 << 7)    // 0x0080, FUN_080f6e34 がまとめて落とす
#define ENEFLAG4_UNK_8 (1 << 8)    // 0x0100, FUN_080f6e34 がまとめて落とす
#define ENEFLAG4_UNK_10 (1 << 10)  // 0x0400, FUN_080f48ac が被弾の通知で立てる
#define ENEFLAG4_UNK_11 (1 << 11)  // 0x0800, FUN_080f6e34 がまとめて落とす
#define ENEFLAG4_UNK_13 (1 << 13)  // 0x2000, 立っていると FUN_080e191c が Mover_ApplyMove で動かし, 足元のタイルの効果を調べる
#define ENEFLAG4_UNK_14 (1 << 14)  // 0x4000, FUN_080e35b4 が立っているときだけ当たり判定を出す
#define ENEFLAG4_UNK_12 (1 << 12)  // 0x1000, 立っていると FUN_080edebc が破棄側へ回す

// Enemy.flags5 (0x474)
typedef u16 EnemyFlags5;
#define ENEFLAG5_UNK_3 (1 << 3)    // 0x0008, 立っていると FUN_080e4444 が経路の島を確かめずにプレイヤーを見つけたことにする
#define ENEFLAG5_UNK_5 (1 << 5)    // 0x0020, 立っていると Enemy_SnapToFloor が mover.pos.y を床に合わせない
#define ENEFLAG5_UNK_6 (1 << 6)    // 0x0040, 立っていると FUN_080f6c74 が当たり判定の向きを外す
#define ENEFLAG5_UNK_7 (1 << 7)    // 0x0080, 立っていると FUN_080f6604 が経験値も図鑑への登録も行わない
#define ENEFLAG5_UNK_8 (1 << 8)    // 0x0100, Cmd_62AA / Cmd_4FD1 / Cmd_60FB が見る
#define ENEFLAG5_UNK_9 (1 << 9)    // 0x0200, FUN_080f6604 が見る
#define ENEFLAG5_UNK_11 (1 << 11)  // 0x0800, 立っていると FUN_080e35b4 が当たり判定を隠す

// Enemy.flags6 (0x49C)
typedef u32 EnemyFlags6;
#define ENEFLAG6_UNK_2 (1 << 2)    // 0x00000004, FUN_080f6868 が立っているときだけ働く
#define ENEFLAG6_UNK_14 (1 << 14)  // 0x00004000, FUN_080f6e34 が見る
#define ENEFLAG6_UNK_18 (1 << 18)  // 0x00040000, FUN_080f6e34 が見る
#define ENEFLAG6_UNK_19 (1 << 19)  // 0x00080000, FUN_080f6e34 が見る

struct Enemy;

// handlerUpdate / handlerDestroy の型, 引数は unk_1cc ひとつで、戻り値は誰も使っていない
typedef void (*EnemyHandler)(struct Enemy*);

// handlerMsg の型, FUN_080ec758 / FUN_080ec79c / FUN_080ec848 が (enemy, payload) で呼ぶ
typedef void (*EnemyMsgHandler)(void* p, void* payload);

// Enemy.animTable の要素, 添字は呼び出し側が固定値で渡す動作の種類
typedef struct {
  u8 anim;      // 0x00, Enemy_PlayAnim が MainSprite_SetAnim に渡すアニメ番号のもと
  u8 unk_1;     // 0x01, Enemy_PlayAnim が anim と or して使う
  u8 unk_2[2];  // 0x02
} EnemyAnimEntry;
static_assert(sizeof(EnemyAnimEntry) == 4);

// 各エネミー共通部, 最小のエネミー(Mimic)が1684バイトなのに対しここは0x654=1620バイトあり、構造体のほとんどが共通部分だとわかる
// サイズの根拠: Enemy_InitHandlerTables が 0x62C から 0x650 まで10本のテーブルポインタを書き込む
#define ENEMY_HDR                                                                                                                                                                                                        \
  Mover mover;                     /* 0x000 */                                                                                                                                                                           \
  EnemySpriteData* sprite;         /* 0x044 */                                                                                                                                                                           \
  MsgQueue mq;                     /* 0x048 */                                                                                                                                                                           \
  Entity5941Node node5941;         /* 0x07C, Entity5941_Register で敵のリストに繋がるノード, flags の bit0 を FUN_080f6604 が ENEFLAG5_UNK_9 のときに立てる */                                                           \
  MoverTile moverTile;             /* 0x08C, ENEFLAG_UNK_13 が立っていて ENEFLAG5_UNK_5 が無いとき FUN_080e191c が mover.tile に繋ぐ */                                                                                  \
  PathWalker pathWalker;           /* 0x09C, 経路追従の状態, mover.path がここを指す, 根拠: FUN_080ee2c8 が Map_InitPathWalker(&pathWalker, ...) のあと mover.path に代入する */                                         \
  ZoneEventSource zoneSource;      /* 0x0A8, FUN_080e191c が毎フレーム FUN_08234660 に渡す */                                                                                                                            \
  HitboxData hitbox;               /* 0x0D8, Enemy_RegisterHitbox ほかが組んで登録する */                                                                                                                                \
  HitboxData atkHitbox;            /* 0x128, Enemy_InitAtkHitbox が atkPower ほかの攻撃パラメータを載せて組む攻撃判定 */                                                                                                 \
  EnemyFlags flags;                /* 0x178, bit0/1=活動停止判定, bit3=FUN_080ec92c が毎フレーム1体だけに立てる */                                                                                                       \
  EnemyFlags2 flags2;              /* 0x17C, bit21=FUN_080edebc がパレット転送の向きとして反転させる */                                                                                                                  \
  EnemyFlags3 flags3;              /* 0x180, bit14=FUN_080ec9b0 が立て FUN_080edebc が落とす */                                                                                                                          \
  EnemyFlags4 flags4;              /* 0x182, bit12 が立っていると FUN_080edebc が破棄側へ回す */                                                                                                                         \
  s16 hp;                          /* 0x184, 0 以下で死亡扱い, 根拠: Enemy_IsDead / Cmd_E019 が生存判定に使い FUN_080ed068 が全滅処理で 0 を書く */                                                                      \
  u8 power;                        /* 0x186, Hitbox_SetPowerAndAttributes の power */                                                                                                                                    \
  u8 unk_187[0x189 - 0x187];       /* 0x187 */                                                                                                                                                                           \
  u8 weaponExp;                    /* 0x189, 倒されたとき Player_AddWeaponExp に渡す量 */                                                                                                                                \
  u16 attrs;                       /* 0x18A, Hitbox_SetPowerAndAttributes の attrs (HitboxAttributes の下位16bit) */                                                                                                     \
  u16 weakness;                    /* 0x18C, Hitbox_SetPowerAndAttributes の weakness */                                                                                                                                 \
  u16 unk_18e;                     /* 0x18E, FUN_080e48e8 が第3引数を入れる, unk_190 と対 */                                                                                                                             \
  s16 unk_190;                     /* 0x190, Enemy_Sleep が unk_192 へ写す */                                                                                                                                            \
  u16 unk_192;                     /* 0x192, Enemy_Sleep / Cmd_C12A / FUN_080ee738 が書く */                                                                                                                             \
  u16 unk_194;                     /* 0x194, Enemy の _Init が &unk_194 を控える (unk_196 と対) */                                                                                                                       \
  u16 scriptID;                    /* 0x196, 0 以外なら FUN_080e6750 が VM_ExecByID(scriptID, NULL) で実行する */                                                                                                        \
  u16 unk_198;                     /* 0x198, 条件がそろうと FUN_080e6658 が VM_ExecByID するスクリプト ID */                                                                                                             \
  u16 unk_19a;                     /* 0x19A, 0 でなければ倒されたとき FUN_080f5208 が VM_ExecByID するスクリプト ID */                                                                                                   \
  u32 unk_19c;                     /* 0x19C, unk_198 のスクリプトの第4引数 */                                                                                                                                            \
  u32 unk_1a0;                     /* 0x1A0, 同じく第5引数 */                                                                                                                                                            \
  u32 unk_1a4;                     /* 0x1A4, 同じく第6引数 */                                                                                                                                                            \
  u8 unk_1a8[0x1BC - 0x1A8];       /* 0x1A8 */                                                                                                                                                                           \
  u16 unk_1bc;                     /* 0x1BC, 着地したとき FUN_080e4b3c が縦の速さに掛ける割合 (1/10 単位), 0 なら止まる */                                                                                               \
  s16 heightAboveFloor;            /* 0x1BE, 床からの高さ, Enemy_SnapToFloor が mover.pos.y = floorY + heightAboveFloor にする */                                                                                        \
  Vec3 jumpVel;                    /* 0x1C0, 跳ねるときの速さ, FUN_080e4b3c が heightAboveFloor と mover.delta に足し込む */                                                                                             \
  u16 stateTimer;                  /* 0x1C8, 状態を切り替えるときに 0 でクリアされる */                                                                                                                                  \
  u16 unk_1ca;                     /* 0x1CA, FUN_080e4b3c が 4 の倍数のときだけ速さを半分にする */                                                                                                                       \
  void* unk_1cc;                   /* 0x1CC, handlerUpdate/handlerDestroy の唯一の引数, 破棄時にこれが Free される */                                                                                                    \
  s32 exp;                         /* 0x1D0, 倒されたとき AddPlayerExp に渡す量 */                                                                                                                                       \
  s32 unk_1d4;                     /* 0x1D4, FUN_080fadd4 が MsgPacket.unk_4 を書く */                                                                                                                                   \
  Mover* playerMover;              /* 0x1D8, FUN_080faa98 が gPlayerPtr[n]->mover を書く */                                                                                                                              \
  u8 unk_1dc;                      /* 0x1DC */                                                                                                                                                                           \
  u8 angle;                        /* 0x1DD, 8bit の向き, gSineTable の索引 */                                                                                                                                           \
  u8 facing;                       /* 0x1DE, 0..3 の向き, Enemy_SetAnimFacing が mover.angle から作る */                                                                                                                 \
  u8 kind;                         /* 0x1DF, 種族, ENEK_* in "include/constants/enemy.h", グラフィックが全く同じものは同じ kind を持つ (逆にスケルトンAやスケルトンFはスケルトンと見た目が少し違うので別の kind 扱い) */ \
  u16 range0;                      /* 0x1E0, 二乗が range0Sq に入る */                                                                                                                                                   \
  u16 range1;                      /* 0x1E2, 二乗が range1Sq に入る */                                                                                                                                                   \
  u32 unk_1e4;                     /* 0x1E4, FUN_080f624c が 0x000FFFFF と比較する */                                                                                                                                    \
  u32 unk_1e8;                     /* 0x1E8, FUN_080e4444 が MPF_BRIGHT のとき range0Sq の代わりの近さの閾値に使う距離の2乗 */                                                                                           \
  u32 range0Sq;                    /* 0x1EC, range0 の二乗 */                                                                                                                                                            \
  u32 range1Sq;                    /* 0x1F0, range1 の二乗 */                                                                                                                                                            \
  u32 range2Sq;                    /* 0x1F4, range2 の二乗 */                                                                                                                                                            \
  u32 unk_1f8;                     /* 0x1F8, 0 でなければ FUN_080f0430 が狙う相手を追いかけ続ける */                                                                                                                     \
  u8 unk_1fc;                      /* 0x1FC */                                                                                                                                                                           \
  u8 unk_1fd;                      /* 0x1FD */                                                                                                                                                                           \
  s16 unk_1fe;                     /* 0x1FE, Enemy_SetEmote が FUN_08240cf0 の第3引数に渡す */                                                                                                                           \
  u16 range2;                      /* 0x200, 二乗が range2Sq に入る */                                                                                                                                                   \
  u16 unk_202;                     /* 0x202, FUN_080f9bfc が 0 でクリアする */                                                                                                                                           \
  Vec3 unk_204;                    /* 0x204, FUN_080f84d4 が音のした場所として向かう座標 */                                                                                                                              \
  Vec3 unk_20c;                    /* 0x20C, mover.pos から angle 方向へ伸ばした点 */                                                                                                                                    \
  Vec3 unk_214;                    /* 0x214, mover.pos の控え */                                                                                                                                                         \
  u8 unk_21c;                      /* 0x21C, FUN_080e5b2c が 0 に戻す */                                                                                                                                                 \
  u8 unk_21d;                      /* 0x21D */                                                                                                                                                                           \
  u16 unk_21e;                     /* 0x21E, FUN_080f9bfc が 0 でクリアする */                                                                                                                                           \
  u16 unk_220;                     /* 0x220, FUN_080f9bfc が 0 でクリアする */                                                                                                                                           \
  u16 unk_222;                     /* 0x222, bit0 は FUN_080f624c が unk_1e4 の大小で立て落としする */                                                                                                                   \
  u16 atkPower[4];                 /* 0x224, Hitbox_SetAttack の power */                                                                                                                                                \
  u16 atkUnk40[4];                 /* 0x22C, Hitbox_SetAttack の unk_40 */                                                                                                                                               \
  u16 atkInvincibleTime[4];        /* 0x234, Hitbox_SetAttack の invincibleTime */                                                                                                                                       \
  HitboxAttributes atkAttrs[4];    /* 0x23C, Hitbox_SetAttack の attrs */                                                                                                                                                \
  u16 unk_24c;                     /* 0x24C, unk_24e の上限 */                                                                                                                                                           \
  u16 unk_24e;                     /* 0x24E, FUN_080f62b0 が 0 に戻す */                                                                                                                                                 \
  u8 unk_250;                      /* 0x250, '.r[0]' */                                                                                                                                                                  \
  u8 unk_251;                      /* 0x251 */                                                                                                                                                                           \
  u8 unk_252;                      /* 0x252, '.r[1]' */                                                                                                                                                                  \
  u8 unk_253;                      /* 0x253 */                                                                                                                                                                           \
  u16 maxHp;                       /* 0x254, hp の初期値, FUN_0809c344 へ渡す */                                                                                                                                         \
  u16 unk_256;                     /* 0x256, FUN_080e4384 が引数座標のタイル索引と突き合わせる */                                                                                                                        \
  u16 prevTileIdx;                 /* 0x258, 前のフレームの unk_256 */                                                                                                                                                   \
  u16 unk_25a;                     /* 0x25A, FUN_0809c344 の第4引数 */                                                                                                                                                   \
  u8 prevPathNode;                 /* 0x25C, 直前にいた経路ノード番号, FUN_080e7204 が次のノードを選ぶときに避ける */                                                                                                    \
  u8 spriteKind;                   /* 0x25D, 0 なら sprite を AuxSprite 系、非0なら MainSprite 系として扱う */                                                                                                           \
  u16 unk_25e;                     /* 0x25E, FUN_080f0320 が追う相手の足元のタイル索引を書く */                                                                                                                          \
  void* unk_260;                   /* 0x260, FUN_080eca74 が EnemyManager.sharedEntity の値を書き込む */                                                                                                                 \
  void* unk_264;                   /* 0x264, 同上 (kind==ENEK_OCTOPUS のとき) */                                                                                                                                         \
  ParticleShadow shadow;           /* 0x268 */                                                                                                                                                                           \
  u8 unk_2a8[0x314 - 0x2A8];       /* 0x2A8 */                                                                                                                                                                           \
  Eff082473e0Emitter emitter;      /* 0x314, 根拠: FUN_080e64b4 が Eff082473e0Emitter_FadeParticle に渡す (sizeof 312 で 0x44B まで) */                                                                                  \
  u8 unk_44c;                      /* 0x44C */                                                                                                                                                                           \
  u8 unk_44d;                      /* 0x44D, 0 以外だと FUN_080e64b4 がパーティクルを消さない */                                                                                                                         \
  u16 unk_44e;                     /* 0x44E, unk_4be がこの値か 2 倍のとき FUN_080f5c0c が粒子を吹き出させる */                                                                                                          \
  u8 unk_450[0x452 - 0x450];       /* 0x450 */                                                                                                                                                                           \
  u8 unk_452;                      /* 0x452, FUN_080e8614 が粒子を出す向きに足すずれ, 毎フレーム unk_453 * 4 ずつ動き 0x40 で折り返す */                                                                                 \
  s8 unk_453;                      /* 0x453, unk_452 の増分, 折り返すたびに符号が反転する */                                                                                                                             \
  struct Emote* emote;             /* 0x454, EmoteManager, FUN_080f6bac が Emote_RemovePtcl に渡す */                                                                                                                    \
  u16 unk_458[4];                  /* 0x458, unk_460 番目に FUN_080f6868 が 580 を書く */                                                                                                                                \
  u16 unk_460;                     /* 0x460, FUN_080f6c74 が 0 に戻す */                                                                                                                                                 \
  u16 unk_462;                     /* 0x462, FUN_080f6c74 が 0 に戻す */                                                                                                                                                 \
  u16 unk_464;                     /* 0x464, FUN_080f6c74 が 0 に戻す */                                                                                                                                                 \
  s16 nodeWait;                    /* 0x466, 経路ノードの待ちフレームの残り, FUN_080f2364 が node->delay から入れて毎フレーム 1 減らす */                                                                                \
  u8 subState0;                    /* 0x468, FUN_080f34ec 系が 2 か 3 を書く */                                                                                                                                          \
  u8 subState1;                    /* 0x469, handlerTables[1] [5] [7] [9] の添字 (ldrb) */                                                                                                                               \
  u8 subState2;                    /* 0x46A, handlerTables[2] [3] [4] [6] [8] の添字 (ldrb) */                                                                                                                           \
  u8 subStateDone;                 /* 0x46B, 0 が書かれる, 読み手は FUN_080fa384 ほか */                                                                                                                                 \
  u8 subStateBegun;                /* 0x46C, FUN_080f2644 が非0を条件にして 0 に戻す */                                                                                                                                  \
  bool8 stateBegun;                /* 0x46D, 状態に入った直後のフレームだけ 1, 各状態ハンドラが入場処理をして 0 に戻す (Enemy_ClearStateBegun は食うだけ) */                                                             \
  bool8 animForceRestart;          /* 0x46E, 1 なら Enemy_PlayAnim が同じアニメ番号でも再生し直す, 再生後に 0 に戻る */                                                                                                  \
  u8 unk_46f;                      /* 0x46F, FUN_080edebc が非0を条件にする */                                                                                                                                           \
  u16 unk_470;                     /* 0x470, 0 でなければ FUN_080e8614 が毎フレーム減らし, 4 フレームおきに粒子を出す */                                                                                                 \
  u16 floorY;                      /* 0x472, 足元の床の高さ, Enemy_SnapToFloor が取り直す, mover.pos.y との差が 256 以下のときだけ unk_198 を実行する */                                                                 \
  EnemyFlags5 flags5;              /* 0x474 */                                                                                                                                                                           \
  u16 unk_476;                     /* 0x476, ENEFLAG2_UNK_14 のときに FUN_080f5c0c が使うパレット番号 */                                                                                                                 \
  u16 unk_478;                     /* 0x478, パレット番号, EnemySpriteData の +0x32 / +0x5A に書かれる */                                                                                                                \
  u16 unk_47a;                     /* 0x47A, variant と足して遷移先パレット番号になる */                                                                                                                                 \
  u8 unk_47c[0x47E - 0x47C];       /* 0x47C */                                                                                                                                                                           \
  u16 unk_47e;                     /* 0x47E, FUN_080f6868 が使うパレット番号 */                                                                                                                                          \
  u16 variant;                     /* 0x480, 敵の変種(kind が ビー系 なら variant で ビー,ポイズンビー,キラービー を決める) */                                                                                           \
  u16 animSpeedDiv;                /* 0x482, 歩きアニメの速さの割る数, 速さは 64 / animSpeedDiv, 0 なら 1 に直される */                                                                                                  \
  s32 subStateTimer;               /* 0x484, handlerTables を切り替えるときに 0 でクリアされる */                                                                                                                        \
  u8 unk_488[0x48A - 0x488];       /* 0x488 */                                                                                                                                                                           \
  u16 unk_48a;                     /* 0x48A, FUN_080e499c が 0 を書く */                                                                                                                                                 \
  u8 unk_48c;                      /* 0x48C, FUN_080e499c が 0 を書く */                                                                                                                                                 \
  u8 unk_48d;                      /* 0x48D */                                                                                                                                                                           \
  u8 unk_48e;                      /* 0x48E, FUN_080ec9b0 のカウントダウン */                                                                                                                                            \
  u8 unk_48f;                      /* 0x48F */                                                                                                                                                                           \
  ZoneID16 zoneID;                 /* 0x490, gStat->zoneID と一致するかを FUN_080edebc が見る */                                                                                                                         \
  u8 unk_492[0x494 - 0x492];       /* 0x492 */                                                                                                                                                                           \
  u16 unk_494;                     /* 0x494, FUN_080f6868 が 6000 を書く */                                                                                                                                              \
  u8 unk_496[0x498 - 0x496];       /* 0x496 */                                                                                                                                                                           \
  u32 weaponExpMask;               /* 0x498, 倒されたとき Player_AddWeaponExp に渡すマスク, Cmd_1E97 が 0x40 を書く */                                                                                                   \
  EnemyFlags6 flags6;              /* 0x49C, FUN_080f6e34 が bit14/18/19 を見る */                                                                                                                                       \
  u32 unk_4a0;                     /* 0x4A0, Cmd_1E97 が 0x20 を書く */                                                                                                                                                  \
  NavAgent* navAgent;              /* 0x4A4, 経路移動の状態, Map_InitNavAgent / Map_StepNavPath に渡す (実体はここではなく別に確保される) */                                                                             \
  Vec3* unk_4a8;                   /* 0x4A8, FUN_080f62b0 が経路の今のノードの座標を書き込む先 */                                                                                                                        \
  Vec3 prevPos;                    /* 0x4AC, 前のフレームの mover.pos */                                                                                                                                                 \
  u8 unk_4b4[2];                   /* 0x4B4, 経路番号の組, FUN_080f6868 が unk_4b6 で選んでいない方を Mover_SetPath に渡す */                                                                                            \
  u8 unk_4b6;                      /* 0x4B6 */                                                                                                                                                                           \
  u8 playingAnim;                  /* 0x4B7, 再生中のアニメ番号, Enemy_PlayAnim が同じ番号なら流し直さない */                                                                                                            \
  struct EnemyTarget* target;      /* 0x4B8, 確保中の狙う相手, EnemyTargetManager_Claim の戻り値が入る */                                                                                                                \
  u8 unk_4bc[0x4BE - 0x4BC];       /* 0x4BC */                                                                                                                                                                           \
  u16 unk_4be;                     /* 0x4BE, FUN_080edebc が 0 を書く */                                                                                                                                                 \
  EnemyAnimEntry animTable[27];    /* 0x4C0, Enemy_SetAnimEntry が書き Enemy_PlayAnim が引く */                                                                                                                          \
  u8 unk_52c[0x540 - 0x52C];       /* 0x52C */                                                                                                                                                                           \
  u8 unk_540;                      /* 0x540, FUN_080f0e78 が乱数で選んだ新しい向き */                                                                                                                                    \
  u8 unk_541;                      /* 0x541, FUN_080f0e78 が unk_1dc から作る向き */                                                                                                                                     \
  u8 unk_542;                      /* 0x542, FUN_080f00ec が 0xFF を書く */                                                                                                                                              \
  u8 unk_543;                      /* 0x543 */                                                                                                                                                                           \
  u16 unk_544;                     /* 0x544, 0 でなければ FUN_080f0430 が状態16へ移らない */                                                                                                                             \
  u8 unk_546[0x548 - 0x546];       /* 0x546 */                                                                                                                                                                           \
  void* unk_548;                   /* 0x548, FUN_080f0e78 が退避する handlerState */                                                                                                                                     \
  u8 unk_54c;                      /* 0x54C, 同じく subState0 */                                                                                                                                                         \
  u8 unk_54d;                      /* 0x54D, 同じく subState1 */                                                                                                                                                         \
  u8 unk_54e;                      /* 0x54E, 同じく subState2 */                                                                                                                                                         \
  u8 unk_54f;                      /* 0x54F, 同じく state */                                                                                                                                                             \
  u8 unk_550;                      /* 0x550, 状態遷移が通ったとき subState0 へ写される */                                                                                                                                \
  u8 unk_551;                      /* 0x551, 同じく subState1 へ */                                                                                                                                                      \
  u8 unk_552;                      /* 0x552, 同じく subState2 へ */                                                                                                                                                      \
  u8 state;                        /* 0x553, 状態番号, handlerState と同時に書き換えられる */                                                                                                                            \
  s32 unk_554;                     /* 0x554, 遷移要求の優先度, 引数がこれ以上のときだけ遷移が通る (FUN_080e6794 など) */                                                                                                 \
  void* unk_558;                   /* 0x558, 遷移が通ったとき handlerState へ写される */                                                                                                                                 \
  u32 unk_55c;                     /* 0x55C, flags の初期値, FUN_080ee738 が flags へそのままコピーする */                                                                                                               \
  u32 unk_560;                     /* 0x560, flags2 の初期値, 同じく flags2 へコピーされる */                                                                                                                            \
  u8 unk_564[0x578 - 0x564];       /* 0x564 */                                                                                                                                                                           \
  void* handlerState;              /* 0x578, 状態ハンドラ, Thumb のコードアドレスが入る */                                                                                                                               \
  EnemyMsgHandler handlerMsg;      /* 0x57C, FUN_080ec758/080ec79c/080ec848 が (enemy, payload) で呼ぶ */                                                                                                                \
  EnemyHandler unk_580;            /* 0x580, FUN_080f06b0 が (unk_1cc) で毎フレーム呼ぶ */                                                                                                                               \
  void* unk_584;                   /* 0x584, 状態12のハンドラ, FUN_080f0868 が handlerState へ写す */                                                                                                                    \
  s32 (*unk_588)(struct Enemy*);   /* 0x588, fn(p), FUN_080f1ef8 が移動の速さとして使う */                                                                                                                               \
  bool8 (*unk_58c)(struct Enemy*); /* 0x58C, fn(p), FUN_080f6604 が hp が残っているときに呼んで結果を返す */                                                                                                             \
  void* unk_590;                   /* 0x590, 状態ハンドラの控え, FUN_080f2074 が handlerState へ写す */                                                                                                                  \
  void* unk_594;                   /* 0x594, Enemy_Sleep が非NULLのときだけ動く */                                                                                                                                       \
  void* unk_598;                   /* 0x598, 状態8のハンドラ, FUN_080f56ec が止まったときに handlerState へ写す */                                                                                                       \
  void* unk_59c;                   /* 0x59C, 状態ハンドラの控え, FUN_080f5b34 が handlerState へ写す */                                                                                                                  \
  void* unk_5a0;                   /* 0x5A0, 状態1のハンドラ, FUN_080f1ef8 が入場時に handlerState へ写す */                                                                                                             \
  void* unk_5a4;                   /* 0x5A4, 状態ハンドラの控え, FUN_080f1e78 が handlerState へ写す */                                                                                                                  \
  void* unk_5a8;                   /* 0x5A8, 状態19のハンドラ, FUN_080f2d04 が handlerState へ写す */                                                                                                                    \
  EnemyHandler unk_5ac;            /* 0x5AC, fn(p), FUN_080eafdc が ENEFLAG4_UNK_7 のときに呼ぶ */                                                                                                                       \
  EnemyHandler unk_5b0;            /* 0x5B0, fn(p), FUN_080eafdc が ENEFLAG4_UNK_8 のときに呼ぶ */                                                                                                                       \
  EnemyHandler unk_5b4;            /* 0x5B4, fn(p), FUN_080e4b3c が着地したときに呼ぶ */                                                                                                                                 \
  void* unk_5b8;                   /* 0x5B8, 状態26のハンドラ, FUN_080f11d0 が handlerState へ写す */                                                                                                                    \
  void* unk_5bc;                   /* 0x5BC, 状態27のハンドラ, FUN_080f0e78 が handlerState へ写す */                                                                                                                    \
  void* unk_5c0;                   /* 0x5C0, 既定の状態ハンドラ, Cmd_7659 が handlerState へコピーする */                                                                                                                \
  EnemyHandler unk_5c4;            /* 0x5C4, fn(p), FUN_080faa98 が座標の検索に失敗したときだけ呼ぶ */                                                                                                                   \
  void* unk_5c8;                   /* 0x5C8, 状態9のハンドラ, FUN_080f84d4 が handlerState へ写す */                                                                                                                     \
  void* unk_5cc;                   /* 0x5CC, 状態18のハンドラ, FUN_080f64f0 / FUN_080f8400 が handlerState へ写す */                                                                                                     \
  void* unk_5d0;                   /* 0x5D0, 状態17のハンドラ */                                                                                                                                                         \
  void* unk_5d4;                   /* 0x5D4, 状態21のハンドラ, FUN_080e6978 が handlerState へ写す */                                                                                                                    \
  void* unk_5d8;                   /* 0x5D8, 状態22のハンドラ, NULL なら FUN_080f54e4 */                                                                                                                                 \
  u8 unk_5dc[0x5E8 - 0x5DC];       /* 0x5DC */                                                                                                                                                                           \
  void* unk_5e8;                   /* 0x5E8, 状態25のハンドラ, FUN_080f2ec0 が攻撃対象に近づいたとき handlerState へ写す */                                                                                              \
  void* unk_5ec;                   /* 0x5EC, 状態32のハンドラ, FUN_080f48ac が吹き飛ばしの通知で handlerState へ写す */                                                                                                  \
  EnemyHandler unk_5f0;            /* 0x5F0, fn(p), FUN_080e72b0 がアニメの再生し直しの合図で呼ぶ */                                                                                                                     \
  u8 unk_5f4[0x600 - 0x5F4];       /* 0x5F4 */                                                                                                                                                                           \
  void* unk_600;                   /* 0x600, EnemyBat_Init がアドレスを取る, 呼び出しは未発見 */                                                                                                                         \
  u8 unk_604[0x608 - 0x604];       /* 0x604 */                                                                                                                                                                           \
  bool8 (*unk_608)(struct Enemy*); /* 0x608, FUN_080f22c4 ほか19関数が使う */                                                                                                                                            \
  void* unk_60c;                   /* 0x60C, 関数ポインタ表, Enemy_DispatchMsg が fn = unk_60c[arg[0]] を fn(p, arg) で呼ぶ */                                                                                           \
  u8 unk_610[0x614 - 0x610];       /* 0x610 */                                                                                                                                                                           \
  void* unk_614;                   /* 0x614, fn(p), FUN_080fa384 が NULL でないときだけ呼ぶ */                                                                                                                           \
  bool8 (*unk_618)(struct Enemy*); /* 0x618, fn(p), FUN_080f2364 / FUN_080f0430 */                                                                                                                                       \
  EnemyHandler handlerUpdate;      /* 0x61C, FUN_080edebc が (unk_1cc) で毎フレーム呼ぶ */                                                                                                                               \
  EnemyHandler handlerDestroy;     /* 0x620, FUN_080ee218 が (unk_1cc) で呼び、その後 unk_1cc を Free する */                                                                                                            \
  bool8 (*unk_624)(struct Enemy*); /* 0x624, fn(p), FUN_080f06b0 が戻り値の下位1バイトを見る */                                                                                                                          \
  EnemyHandler unk_628;            /* 0x628, fn(p), FUN_080f06b0 が unk_624 の戻り値が 0 のときだけ呼ぶ */                                                                                                               \
  void* handlerTables[10];         /* 0x62C, 状態ごとの関数ポインタ表を10本, Enemy_InitHandlerTables が 0x62C から順にまとめて書き込む */

typedef struct Enemy {
  ENEMY_HDR;  // 共通部分
} Enemy;
static_assert(sizeof(Enemy) == 1620);

// ビットのセット/クリアはこのヘルパー経由で書く, フィールドごとに専用のものが要る
// (幅で共通化して u32* を渡す形にすると、if/else の両腕が同じ形になって str が1つに畳まれ一致しない)
// spriteKind に応じて AuxSprite / MainSprite のどちらのフラグを触るか振り分ける
static inline void Enemy_SetSpriteFlags(Enemy* p, SpriteFlags bits) {
  if (p->spriteKind == 0) {
    AuxSprite_SetFlags((AuxSprite*)p->sprite, bits);
  } else {
    MainSprite_SetFlags(&p->sprite->s, bits);
  }
}

static inline void Enemy_ClearSpriteFlags(Enemy* p, SpriteFlags bits) {
  if (p->spriteKind == 0) {
    AuxSprite_ClearFlags((AuxSprite*)p->sprite, bits);
  } else {
    MainSprite_ClearFlags(&p->sprite->s, bits);
  }
}

static inline void Enemy_SetFlag(Enemy* p, EnemyFlags bit) { p->flags |= bit; }
static inline void Enemy_ClearFlag(Enemy* p, EnemyFlags bit) { p->flags &= ~bit; }
static inline void Enemy_SetFlag2(Enemy* p, EnemyFlags2 bit) { p->flags2 |= bit; }
static inline void Enemy_ClearFlag2(Enemy* p, EnemyFlags2 bit) { p->flags2 &= ~bit; }
static inline EnemyFlags Enemy_TestFlag(Enemy* p, EnemyFlags bit) { return p->flags & bit; }
static inline void Enemy_SetFlag3(Enemy* p, EnemyFlags3 bit) { p->flags3 |= bit; }
static inline void Enemy_ClearFlag3(Enemy* p, EnemyFlags3 bit) { p->flags3 &= ~bit; }
static inline bool32 Enemy_TestFlag2(Enemy* p, EnemyFlags2 bit) { return (p->flags2 & bit) != 0; }
static inline EnemyFlags2 Enemy_GetFlag2(Enemy* p, EnemyFlags2 bit) { return p->flags2 & bit; }
static inline bool32 Enemy_TestFlag3(Enemy* p, EnemyFlags3 bit) { return (p->flags3 & bit) != 0; }
static inline EnemyFlags3 Enemy_GetFlag3(Enemy* p, EnemyFlags3 bit) { return p->flags3 & bit; }
static inline void Enemy_SetFlag4(Enemy* p, EnemyFlags4 bit) { p->flags4 |= bit; }
static inline void Enemy_ClearFlags4(Enemy* p, EnemyFlags4 bits) { p->flags4 &= ~bits; }

// --------------------------------------------

extern void (*const gEnemyDefaultMsgHandlers[6])(Enemy*, u16*);

// --------------------------------------------

// Enemy全体で利用される
void Enemy_SetEmote(Enemy* p, u8 emote, u8 variant, u8 kind);
void Enemy_SetAnimFacing(Enemy* p, u8* variant, AuxAnimPlayFlags* flags);
void Enemy_ClearStateBegun(Enemy* p);
bool8 Enemy_IsPosInRect(Enemy* p, WorldPos* pos, u32 rx, u32 rz);
bool8 Enemy_IsDead(Enemy* p);  // NULL / 破棄待ち / 数えない敵 / hp が 0 以下なら TRUE
bool32 Enemy_Init_080ec640(Enemy* p);
Enemy* FindEnemyById(u32 id);
void Enemy_PlayAnim(Enemy* p, s32 animIdx);
void Enemy_TargetNearestPlayer(Enemy* p, Vec3* pos);
void Enemy_ClearPendingState(Enemy* p, const char* filename, s32 val);
s32 EnemyDex_GetEntryIdx(u32 kind, s32 variant);
bool32 FUN_080f06b0(Enemy* p);
void FUN_080ec79c(u8 enemyKind, void* payload);                 // 指定した種族(ENEK_xxx)の敵へメッセージを配送する
void FUN_080ec848(u8 enemyKind, void* payload, u16 moverID);    // 種族(ENEK_xxx) と mover.id で敵を1体だけ特定してメッセージを配送する
void FUN_080e5610(u8 enemyKind, u8 dir, s32* outX, s32* outY);  // 種族ごとの表から, 向きに応じて Enemy_SetEmote が使う2つの値を引く
void FUN_080e81dc(Enemy* p, s32 param_2);

// Enemy全体で利用される共通ハンドラ
void FUN_080e6624(Enemy* p, u16* msg);
void FUN_080e664c(Enemy* p, u16* msg);
void FUN_080f07d0(Enemy* p, u16* msg);
void FUN_080f0868(Enemy* p, u16* msg);
void FUN_080f0914(Enemy* p, u16* msg);
void FUN_080f09a4(Enemy* p, u16* msg);

// Enemy全体で利用される共通ハンドラ
void FUN_080f0e78(Enemy* p);
void FUN_080f11d0(Enemy* p);
void FUN_080f12c4(Enemy* p);
void FUN_080f19cc(Enemy* p);
void FUN_080f1c54(Enemy* p);
void FUN_080f1cb8(Enemy* p);
void FUN_080f1cf0(Enemy* p);
void FUN_080f1de4(Enemy* p);
void FUN_080f1e0c(Enemy* p);
void FUN_080f1e78(Enemy* p);
void FUN_080f1ef8(Enemy* p);
void FUN_080f2074(Enemy* p);
void FUN_080f2160(Enemy* p);
void FUN_080f2364(Enemy* p);
void FUN_080f248c(Enemy* p);
void FUN_080f2644(Enemy* p);
void FUN_080f2864(Enemy* p);
void FUN_080f2a40(Enemy* p);
void FUN_080f2d04(Enemy* p);
void FUN_080f2ec0(Enemy* p);
void FUN_080f31c4(Enemy* p);
void FUN_080f33e8(Enemy* p);
void FUN_080f34a0(Enemy* p);
void FUN_080f9c20(Enemy* p);
void FUN_080f9e34(Enemy* p);
void FUN_080f9ee0(Enemy* p);

#endif  // __INCLUDE_ENEMY_H__
