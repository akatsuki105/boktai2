#include "enemy.h"
#include "entity.h"
#include "global.h"

// エネミー全体の管理者. シングルトンで、生存中のエネミーを gEnemyListHead のリストで持つ
typedef struct EnemyManager {
  Entity e;                     // 0x00, ENTITY_UNK_8
  Unk_0203f400* msgRecords;     // 0x18, FUN_080ec8a4 が FUN_08230f94(msgRecordID, &msgRecords) で先頭を受け取り、戻り値の件数だけ走査する
  EnemyListNode* list;          // 0x1C, FUN_080ec614 が Malloc(8) した番兵ノード. gEnemyListHead と同じ値
  EnemyListNode* cursor;        // 0x20, FUN_080ec92c が1フレームおきに1つ進める巡回カーソル
  u32 msgRecordID;              // 0x24, EnemyManager_Init の第2引数. FUN_08230f94 の検索キー
  u16 unk_28;                   // 0x28, 読み手も書き手も未発見
  u16 frameCounter;             // 0x2A, EnemyManager_Update が毎フレーム +1
  u32 flags;                    // 0x2C, bit3/4/5/11/12=sharedEntity の生成済みフラグ, bit13=パレット遷移中, bit14/15/16=種族 0x0B/0x17/0x1B を今フレーム更新済み(Updateで毎回クリア), bit17=遷移でなく即時差し替え
  u8 unk_30;                    // 0x30, EnemyManager_Init が 3、FUN_080ef584 が VM_GetKeywordValue(0x6C, 3) を代入. FUN_080ec5b4 がレコードの3語目へコピーする
  u8 unk_31;                    // 0x31, 読み手も書き手も未発見
  s16 enemyCount;               // 0x32, Enemy_Init_080ec640 で +1 / FUN_080ec6fc で -1. 0x13 を超えると新規生成を拒否する
  Entity* sharedEntity[8];      // 0x34, FUN_080eca74 が種族に応じて生成する共有エンティティのキャッシュ. [0]=Entity080db520, [1]=FUN_081e8d0c, [2]=FUN_080da848, [6]=FUN_081ea120, [7]=FUN_081ea820
  u16 sharedEntityId[8];        // 0x54, FUN_080eca74 が sharedEntity[i]->e.id を控える
  EnemyPaletteFade palFade[3];  // 0x64, FUN_080eeb14 が種族 0x0B/0x17/0x1B の順に添字 0/1/2 を選ぶ
} EnemyManager;
static_assert(sizeof(EnemyManager) == 640);

extern EnemyManager* gEnemyManager;  // 0x03002C5C

INCASM("asm/enemy_manager.inc");

// 後続の enemy_080ef84c.c も enemy_manager.c に含めるかは不明

NAKED void FUN_080ee9d4(EnemyManager* p) { INCFUNC("asm/func/FUN_080ee9d4.inc"); }

NAKED s32 EnemyManager_Update(EnemyManager* p) { INCFUNC("asm/func/EnemyManager_Update.inc"); }

NAKED s32 EnemyManager_Destroy(EnemyManager* p) { INCFUNC("asm/func/EnemyManager_Destroy.inc"); }

NAKED s32 EnemyManager_Init(EnemyManager* p, u16 msgRecordID, u32 _) { INCFUNC("asm/func/EnemyManager_Init.inc"); }

NAKED EnemyManager* EnemyManager_Create(u16 msgRecordID, u16 _) { INCFUNC("asm/func/EnemyManager_Create.inc"); }

NAKED void FUN_080eeb08(void) { INCFUNC("asm/func/FUN_080eeb08.inc"); }

NAKED void FUN_080eeb14(u32 plttDst, u32 plttSrc, u32 _, u8 kind, u32 immediate) { INCFUNC("asm/func/FUN_080eeb14.inc"); }

NAKED bool32 FUN_080eec74(EnemyManager* p, Enemy* enemy) { INCFUNC("asm/func/FUN_080eec74.inc"); }

NAKED bool32 FUN_080eee70(void) { INCFUNC("asm/func/FUN_080eee70.inc"); }

NAKED void FUN_080eeee0(void) { INCFUNC("asm/func/FUN_080eeee0.inc"); }

NAKED void FUN_080eef6c(Enemy* p) { INCFUNC("asm/func/FUN_080eef6c.inc"); }

NAKED void FUN_080eefec(void) { INCFUNC("asm/func/FUN_080eefec.inc"); }

NAKED void FUN_080ef048(void) { INCFUNC("asm/func/FUN_080ef048.inc"); }

NAKED void FUN_080ef154(void) { INCFUNC("asm/func/FUN_080ef154.inc"); }

NAKED void FUN_080ef4e4(void) { INCFUNC("asm/func/FUN_080ef4e4.inc"); }

NAKED void FUN_080ef534(void) { INCFUNC("asm/func/FUN_080ef534.inc"); }

NAKED void FUN_080ef55c(void) { INCFUNC("asm/func/FUN_080ef55c.inc"); }

NAKED void FUN_080ef584(void) { INCFUNC("asm/func/FUN_080ef584.inc"); }

NAKED void FUN_080ef5a8(void) { INCFUNC("asm/func/FUN_080ef5a8.inc"); }

NAKED EnemyManager* GetEnemyManager(void) { INCFUNC("asm/func/GetEnemyManager.inc"); }
