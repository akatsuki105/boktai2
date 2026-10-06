#include "entity.h"
#include "global.h"
#include "menu.h"
#include "sprite.h"
#include "tilemap.h"
#include "weapon.h"

typedef struct Entity744F Entity744F;
typedef void(Entity744FFunc)(Entity744F* p);

// 武器を並べて選ばせるメニュー, 武器IDをスクリプトから受け取り種別ごとの列に振り分ける
struct Entity744F {
  Entity e;                        // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;              // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx gfx1;              // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;              // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[58];          // 0x0078, [38] がカーソル
  Tilemaps* tilemap;               // 0x1638, TILEMAP_9F57
  rgb555* bgPltt;                  // 0x163C, BGP_A41A + 0x1B4
  u8* unk_1640;                    // 0x1640, '.s' があれば FUN_0823d340 の戻り値
  u8* unk_1644;                    // 0x1644, '.w' があれば FUN_0823d340 の戻り値
  char* unk_1648;                  // 0x1648, '.c' を VM_ParseStringRef して Textbox_LookupString した文字列
  u8 unk_164c[0x1654 - 0x164C];    // 0x164C, まだ未解析
  u8 unk_1654;                     // 0x1654, _Init が 0 を入れる
  u8 unk_1655;                     // 0x1655, FUN_080bcdf8 の第3引数
  u8 unk_1656;                     // 0x1656, まだ未解析
  u8 kind;                         // 0x1657, _Update が FUN_080b94cc / FUN_080b9400 に渡す
  u8 unk_1658;                     // 0x1658, _Init が 0 を入れる
  u8 unk_1659;                     // 0x1659, _Init が 0 を入れる
  u8 unk_165a[2];                  // 0x165A, まだ未解析
  weapon8_t swords[16];            // 0x165C, '.P' のうち gWeaponDB[].kind == WK_SWORD のものを 12 個まで詰めて残りは 0
  weapon8_t spears[16];            // 0x166C, 同じく WK_SPEAR
  weapon8_t hammers[16];           // 0x167C, 同じく WK_HAMMER
  u16 emptySlot;                   // 0x168C, FindEmptyWeaponSlot の戻り値
  u16 stateTimer;                  // 0x168E, Entity744F_SetState / FUN_080bcdf8 が差し替えのたびに 0 に戻す
  MenuSpritePair pair0;            // 0x1690, _Destroy が FUN_080b9a0c に渡す
  u8 unk_1770[0x1784 - 0x1770];    // 0x1770, まだ未解析
  MenuCursor cursor;               // 0x1784, FUN_080b9ff8(&cursor, 1, 4, 0, 20)
  MenuSpritePair pair1;            // 0x17B4, _Destroy が FUN_080b9894 に渡す
  u32 unk_1894;                    // 0x1894, '.e' (なければ 0)
  Entity744FFunc* updateCallback;  // 0x1898
  Entity744FFunc* unk_189c;        // 0x189C, FUN_080bcdf8 が入れる, 読み手は未調査
};
static_assert(sizeof(Entity744F) == 6304);

void Entity744F_SetState(Entity744F* p, Entity744FFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080bcdec(Entity744F* p, u8 val) { p->unk_1655 = val; }

NAKED void FUN_080bcdf8(Entity744F* p, Entity744FFunc* fn, u8 val) { INCFUNC("asm/func/FUN_080bcdf8.inc"); }

NAKED void FUN_080bce20(Entity744F* p, s32 param_2) { INCFUNC("asm/func/FUN_080bce20.inc"); }

NAKED s32 FUN_080bce64(s32 slot) { INCFUNC("asm/func/FUN_080bce64.inc"); }

NAKED void SplitDecimal3(s32 value, s32* digits) { INCFUNC("asm/func/SplitDecimal3.inc"); }

NAKED void FUN_080bcf04(Entity744F* p, WeaponData* data) { INCFUNC("asm/func/FUN_080bcf04.inc"); }

NAKED void FUN_080bd01c(Entity744F* p, unknown* param_2) { INCFUNC("asm/func/FUN_080bd01c.inc"); }

NAKED void FUN_080bd058(Entity744F* p) { INCFUNC("asm/func/FUN_080bd058.inc"); }

NAKED void FUN_080bd180(Entity744F* p) { INCFUNC("asm/func/FUN_080bd180.inc"); }

NAKED void FUN_080bd390(Entity744F* p) { INCFUNC("asm/func/FUN_080bd390.inc"); }

NAKED s32 FindRegisteredWeaponSlot(s32 weapon) { INCFUNC("asm/func/FindRegisteredWeaponSlot.inc"); }

NAKED void FUN_080bd47c(Entity744F* p) { INCFUNC("asm/func/FUN_080bd47c.inc"); }

NAKED void FUN_080bd57c(Entity744F* p) { INCFUNC("asm/func/FUN_080bd57c.inc"); }

NAKED void FUN_080bd624(Entity744F* p) { INCFUNC("asm/func/FUN_080bd624.inc"); }

NAKED void FUN_080bd6d0(Entity744F* p, s32 param_2) { INCFUNC("asm/func/FUN_080bd6d0.inc"); }

NAKED s32 FUN_080bd83c(Entity744F* p) { INCFUNC("asm/func/FUN_080bd83c.inc"); }

s32 FindEmptyWeaponSlot(void) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (GetWeaponID(i) == WEAPON_NONE) {
      return i;
    }
  }

  return -1;
}

NAKED void FUN_080bd964(Entity744F* p) { INCFUNC("asm/func/FUN_080bd964.inc"); }

NAKED void FUN_080bd9e8(Entity744F* p) { INCFUNC("asm/func/FUN_080bd9e8.inc"); }

NAKED void FUN_080bdc64(Entity744F* p) { INCFUNC("asm/func/FUN_080bdc64.inc"); }

NAKED void FUN_080bddc0(Entity744F* p) { INCFUNC("asm/func/FUN_080bddc0.inc"); }

NAKED void FUN_080bde2c(Entity744F* p) { INCFUNC("asm/func/FUN_080bde2c.inc"); }

NAKED void FUN_080bde60(Entity744F* p) { INCFUNC("asm/func/FUN_080bde60.inc"); }

NAKED void FUN_080bdeb4(Entity744F* p) { INCFUNC("asm/func/FUN_080bdeb4.inc"); }

NAKED void FUN_080bdf94(Entity744F* p) { INCFUNC("asm/func/FUN_080bdf94.inc"); }

NAKED void FUN_080bdfe8(Entity744F* p) { INCFUNC("asm/func/FUN_080bdfe8.inc"); }

NAKED void FUN_080be060(Entity744F* p) { INCFUNC("asm/func/FUN_080be060.inc"); }

NAKED void FUN_080be0d8(Entity744F* p) { INCFUNC("asm/func/FUN_080be0d8.inc"); }

NAKED void FUN_080be144(Entity744F* p) { INCFUNC("asm/func/FUN_080be144.inc"); }

NAKED void FUN_080be1c8(Entity744F* p) { INCFUNC("asm/func/FUN_080be1c8.inc"); }

NAKED void FUN_080be204(Entity744F* p) { INCFUNC("asm/func/FUN_080be204.inc"); }

NAKED void FUN_080be650(Entity744F* p) { INCFUNC("asm/func/FUN_080be650.inc"); }

NAKED void FUN_080be690(Entity744F* p) { INCFUNC("asm/func/FUN_080be690.inc"); }

NAKED void FUN_080be7b4(Entity744F* p) { INCFUNC("asm/func/FUN_080be7b4.inc"); }

NAKED void FUN_080be7e4(Entity744F* p) { INCFUNC("asm/func/FUN_080be7e4.inc"); }

NAKED void FUN_080be810(Entity744F* p) { INCFUNC("asm/func/FUN_080be810.inc"); }

NAKED void FUN_080be948(Entity744F* p) { INCFUNC("asm/func/FUN_080be948.inc"); }

NAKED s32 Entity744F_Update(Entity744F* p) { INCFUNC("asm/func/Entity744F_Update.inc"); }

NAKED s32 Entity744F_Destroy(Entity744F* p) { INCFUNC("asm/func/Entity744F_Destroy.inc"); }

NAKED s32 Entity744F_Init(Entity744F* p) { INCFUNC("asm/func/Entity744F_Init.inc"); }

NAKED Entity744F* Entity744F_Create(void) { INCFUNC("asm/func/Entity744F_Create.inc"); }
