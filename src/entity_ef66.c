#include "entity.h"
#include "global.h"

// u16_03002b90 に風向きを書き続けるシングルトン
typedef struct {
  Entity e;         // 0x00, ENTITY_UNK_9
  u16 id;           // 0x18, EntityEF66_Init の第2引数
  u16 mode;         // 0x1A, '.m=1', 0/1/2 で初期化の内容が変わる
  u16 angleBase;    // 0x1C, '.p[0]=3'
  u16 angleRange;   // 0x1E, '.p[1]', 0 以外なら乱数で angleBase に足す幅
  u16 holdBase;     // 0x20, '.t[0]=0x78'
  u16 holdRange;    // 0x22, '.t[1]', 0 以外なら乱数で holdBase に足す幅
  s16 angleMin;     // 0x24, angleBase << 4
  s16 angleTarget;  // 0x26, (angleBase + 乱数 % angleRange) << 4
  u16 angle;        // 0x28, 12bit で回る値, >> 4 したものを u16_03002b90 に入れる
  u16 speed;        // 0x2A, 乱数表から入る1バイト, *0x10 して angle に足す
  s16 timer;        // 0x2C, 0 まで減ると speed と angleTarget を引き直す
  u8 unk_2e[2];     // 0x2E, 詰め物
} EntityEF66;
static_assert(sizeof(EntityEF66) == 48);

IWRAM_DATA EntityEF66* gEntityEF66 = NULL;  // 0x03000148

NAKED void FUN_080a11b8(void) { INCFUNC("asm/func/FUN_080a11b8.inc"); }

NAKED void FUN_080a11d4(void) { INCFUNC("asm/func/FUN_080a11d4.inc"); }

NAKED void FUN_080a1244(void) { INCFUNC("asm/func/FUN_080a1244.inc"); }

NAKED void FUN_080a12d8(void) { INCFUNC("asm/func/FUN_080a12d8.inc"); }

NAKED s32 EntityEF66_Update(EntityEF66* p) { INCFUNC("asm/func/EntityEF66_Update.inc"); }

NAKED s32 EntityEF66_Destroy(EntityEF66* p) { INCFUNC("asm/func/EntityEF66_Destroy.inc"); }

NAKED s32 EntityEF66_Init(EntityEF66* p, u16 id) { INCFUNC("asm/func/EntityEF66_Init.inc"); }

NAKED EntityEF66* EntityEF66_Create(u16 param_1) { INCFUNC("asm/func/EntityEF66_Create.inc"); }
