#ifndef __INCLUDE_ENEMY_MANAGER_H__
#define __INCLUDE_ENEMY_MANAGER_H__

#include "enemy.h"
#include "entity.h"
#include "gba/gba.h"
#include "vm.h"

// EnemyManager.flags (0x2C)
typedef u32 EnemyManagerFlags;
#define EMFLAG_UNK_3 (1 << 3)    // 0x00000008, sharedEntity[0] 生成済み
#define EMFLAG_UNK_4 (1 << 4)    // 0x00000010, sharedEntity[1] 生成済み
#define EMFLAG_UNK_5 (1 << 5)    // 0x00000020, sharedEntity[2] 生成済み
#define EMFLAG_UNK_11 (1 << 11)  // 0x00000800, sharedEntity[6] 生成済み
#define EMFLAG_UNK_12 (1 << 12)  // 0x00001000, sharedEntity[7] 生成済み
#define EMFLAG_UNK_13 (1 << 13)  // 0x00002000, パレット遷移中
#define EMFLAG_UNK_14 (1 << 14)  // 0x00004000, 種族 0x0B を今フレーム更新済み
#define EMFLAG_UNK_15 (1 << 15)  // 0x00008000, 種族 0x17 を今フレーム更新済み
#define EMFLAG_UNK_16 (1 << 16)  // 0x00010000, 種族 0x1B を今フレーム更新済み
#define EMFLAG_UNK_17 (1 << 17)  // 0x00020000, 遷移でなく即時差し替え

// 生存中のエネミーを繋ぐ単方向リストのノード, 根拠: EnemyManager_InitList が Malloc(8) して gEnemyListHead に繋ぐ
typedef struct EnemyListNode {
  struct EnemyListNode* next;  // 0x00, FUN_080ec6fc が削除時に前ノードの next へ付け替える
  Enemy* enemy;                // 0x04, Enemy_Init_080ec640 が登録対象を書く
} EnemyListNode;
static_assert(sizeof(EnemyListNode) == 8);

// 16色パレットのクロスフェード, FUN_080eeb14 が開始し、FUN_080eec74 が毎フレーム1段進める
typedef struct {
  u16 pltt[16];  // 0x00, r/g/b から合成した BGR555 の出力, EnemySpriteData のパレットポインタに直接繋がれる
  u16 timer;     // 0x20, FUN_080eeb14 が 0x20 をセットし FUN_080eec74 が毎フレーム -1
  u16 plttID;    // 0x22, 遷移先のパレット番号
  s16 r[16];     // 0x24, 5.5固定小数の現在値, 毎フレーム stepR が加算される
  s16 g[16];     // 0x44
  s16 b[16];     // 0x64
  s8 stepR[16];  // 0x84, FUN_080eeb14 が (遷移先 - 現在) を書く
  s8 stepG[16];  // 0x94
  s8 stepB[16];  // 0xA4
} EnemyPaletteFade;
static_assert(sizeof(EnemyPaletteFade) == 180);

// エネミー全体の管理者, シングルトンで、生存中のエネミーを gEnemyListHead のリストで持つ
typedef struct EnemyManager {
  Entity e;                     // 0x00, ENTITY_UNK_8
  ScriptRecord* msgRecords;     // 0x18, FUN_080ec8a4 が FUN_08230f94(msgRecordID, &msgRecords) で先頭を受け取り、戻り値の件数だけ走査する
  EnemyListNode* list;          // 0x1C, EnemyManager_InitList が Malloc(8) した番兵ノード, gEnemyListHead と同じ値
  EnemyListNode* cursor;        // 0x20, FUN_080ec92c が1フレームおきに1つ進める巡回カーソル
  u32 msgRecordID;              // 0x24, EnemyManager_Init の第2引数, FUN_08230f94 の検索キー
  u16 unk_28;                   // 0x28, 読み手も書き手も未発見
  u16 frameCounter;             // 0x2A, EnemyManager_Update が毎フレーム +1
  EnemyManagerFlags flags;      // 0x2C, bit3/4/5/11/12=sharedEntity の生成済みフラグ, bit13=パレット遷移中, bit14/15/16=種族 0x0B/0x17/0x1B を今フレーム更新済み(Updateで毎回クリア), bit17=遷移でなく即時差し替え
  u8 unk_30;                    // 0x30, EnemyManager_Init が 3、Cmd_2571 が '.l=3' を代入, FUN_080ec5b4 がレコードの3語目へコピーする
  u8 unk_31;                    // 0x31, 読み手も書き手も未発見, padding?
  s16 enemyCount;               // 0x32, Enemy_Init_080ec640 で +1 / FUN_080ec6fc で -1. 0x13 を超えると新規生成を拒否する
  Entity* sharedEntity[8];      // 0x34, FUN_080eca74 が種族に応じて生成する共有エンティティのキャッシュ, [0]=Entity080db520, [1]=Entity081e8d0c_Create, [2]=EmoteManager_Create, [6]=Entity081ea120_Create, [7]=Entity081ea820_Create
  u16 sharedEntityId[8];        // 0x54, FUN_080eca74 が sharedEntity[i]->e.id を控える
  EnemyPaletteFade palFade[3];  // 0x64, FUN_080eeb14 が種族 0x0B/0x17/0x1B の順に添字 0/1/2 を選ぶ
} EnemyManager;
static_assert(sizeof(EnemyManager) == 640);

extern EnemyManager* gEnemyManager;    // 0x03002C5C
extern EnemyListNode* gEnemyListHead;  // 0x03002C60

EnemyManager* GetEnemyManager(void);

void FUN_080ec7e8(u8 kind, u8 variant, void* payload);
void FUN_080eeee0(Enemy* p);

#endif  // __INCLUDE_ENEMY_MANAGER_H__
