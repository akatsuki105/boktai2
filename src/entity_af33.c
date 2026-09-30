#include "entity.h"
#include "global.h"
#include "sprite_main.h"

typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_2
  u32 unk_18;             // 0x018, _Init が 0 を入れる
  u16 unk_1c;             // 0x01C, _Init が 0 を入れる
  u16 unk_1e;             // 0x01E, _Init が 0 を入れる
  u32 unk_20;             // 0x020, _Init が 0 を入れる
  u32 unk_24;             // 0x024, _Init が 0 を入れる
  u8 unk_28[16];          // 0x028, _Init が 0x28/0x2B/0x2C/0x2D/0x33 に 0、0x29/0x32 に 1 を入れる
  u8 unk_38[4];           // 0x038, _Init が 4バイト 0 クリアする
  u8 unk_3c[36];          // 0x03C, _Init が 0xC 刻みで2回まわして埋める, 各回 0x40+i*0xC に {100,100,0,0} と u32 0
  void* unk_60;           // 0x060, _Init が Entity08052250_Create() の戻り値を入れる
  void* unk_64;           // 0x064, _Init が Entity08052ffc_Create() の戻り値を入れる
  u32 count78;            // 0x068, unk_78 に積んだ '.w' の件数
  u32 count98;            // 0x06C, unk_98 に積んだ '.m' の件数
  u32 mask70;             // 0x070, unk_78 を配るときに使用済みスロットのビットを立てる
  u32 mask74;             // 0x074, unk_98 を配るときに使用済みスロットのビットを立てる
  u16 unk_78[16];         // 0x078, '.w' の値を最大16個
  u16 unk_98[16];         // 0x098, '.m' の値を最大16個
  u8* script;             // 0x0B8, '.s' の後の FUN_0823d340() の戻り値, NULL なら _Init が失敗する
  s32 windowID;           // 0x0BC, _Destroy が TextPanel_Destroy に渡す
  u32 unk_c0;             // 0x0C0, 読み手も書き手も見つかっていない
  u32 unk_c4;             // 0x0C4, _Init が '.e' を入れる
  u32 unk_c8;             // 0x0C8, _Init が 0 を入れる
  MainSpriteGfx gfx;      // 0x0CC, SPRITE_INVENTORY_ICONS
  MainSprite sprites[2];  // 0x0EC, _Destroy が MainSprite_Remove に渡す2枚
  u16 unk_1ac;            // 0x1AC, _Init が '.M=11' を入れる
  u16 unk_1ae[4];         // 0x1AE, _Init が '.p' の値を4つ入れる
  u8 unk_1b6[6];          // 0x1B6, 読み手も書き手も見つかっていない
} EntityAF33;
static_assert(sizeof(EntityAF33) == 444);

void FUN_0804ff10(EntityAF33*);
void FUN_0804ffa8(EntityAF33*);
void FUN_08050070(EntityAF33*);
void FUN_0805010c(EntityAF33*);
void FUN_08050218(EntityAF33*);

INCASM("asm/entity_af33.inc");

NAKED void FUN_080502a8(EntityAF33* p) { INCFUNC("asm/func/FUN_080502a8.inc"); }

NAKED void FUN_0805043c(EntityAF33* p) { INCFUNC("asm/func/FUN_0805043c.inc"); }

NAKED void FUN_080504e0(EntityAF33* p) { INCFUNC("asm/func/FUN_080504e0.inc"); }

NAKED void FUN_08050558(EntityAF33* p) { INCFUNC("asm/func/FUN_08050558.inc"); }

NAKED void FUN_08050598(EntityAF33* p) { INCFUNC("asm/func/FUN_08050598.inc"); }

NAKED void FUN_08050674(EntityAF33* p) { INCFUNC("asm/func/FUN_08050674.inc"); }

NAKED void FUN_08050754(EntityAF33* p) { INCFUNC("asm/func/FUN_08050754.inc"); }

void (*const PTR_ARRAY_085ab6a4[12])(EntityAF33*) = {
    FUN_0804ff10, FUN_0804ffa8, FUN_08050070, FUN_0805010c, FUN_08050218, FUN_080502a8, FUN_0805043c, FUN_080504e0, FUN_08050558, FUN_08050598, FUN_08050674, FUN_08050754,
};  // 0x085AB6A4

NAKED s32 EntityAF33_Update(EntityAF33* p) { INCFUNC("asm/func/EntityAF33_Update.inc"); }

NAKED s32 EntityAF33_Destroy(EntityAF33* p) { INCFUNC("asm/func/EntityAF33_Destroy.inc"); }

NAKED s32 EntityAF33_Init(EntityAF33* p) { INCFUNC("asm/func/EntityAF33_Init.inc"); }

EntityAF33* EntityAF33_Create(void) {
  EntityAF33* p = CreateEntity(ENTITY_UNK_2, sizeof(EntityAF33));
  if (p != NULL) {
    SetEntityRoutine(p, EntityAF33_Update, EntityAF33_Destroy);
    if (EntityAF33_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
