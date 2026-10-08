#include "entity.h"
#include "global.h"

// おいしい水の効果時間を数え、0 になったらアイテムを消してスクリプトを実行するシングルトン
typedef struct EntityBA36 {
  Entity e;      // 0x00, ENTITY_UNK_8
  u16 timer;     // 0x18, '.c=1800', 残りフレーム数, _Update が毎フレーム -1. アドレスを FUN_0809c544 に渡して画面に出す
  u8 unk_1a[2];  // 0x1A, このモジュールは触らない, Entity4063 では同じ位置が bool16 cancelled
  u32 scriptID;  // 0x1C, '.p=0', timer が 0 になったとき VM_ExecByID に渡す, 0 なら何も実行しない
} EntityBA36;
static_assert(sizeof(EntityBA36) == 32);

extern EntityBA36* gEntityBA36;  // 0x03002C40

NAKED void EntityBA36_SetRemaining(void) { INCFUNC("asm/func/EntityBA36_SetRemaining.inc"); }

NAKED s32 EntityBA36_GetRemaining(void) { INCFUNC("asm/func/EntityBA36_GetRemaining.inc"); }

NAKED s32 EntityBA36_Update(EntityBA36* p) { INCFUNC("asm/func/EntityBA36_Update.inc"); }

NAKED s32 EntityBA36_Destroy(EntityBA36* p) { INCFUNC("asm/func/EntityBA36_Destroy.inc"); }

NAKED s32 EntityBA36_Init(EntityBA36* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/EntityBA36_Init.inc"); }

NAKED EntityBA36* EntityBA36_Create(u32 param_1, u32 param_2) { INCFUNC("asm/func/EntityBA36_Create.inc"); }
