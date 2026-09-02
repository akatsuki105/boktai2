#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct {
  SpriteSet tmpl;            // 0x00
  SpriteState icons[5 * 4];  // 0x20
} WeaponIconSprites;

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_8
  void* p_18;               // 0x018,  0x08653534 固定?
  u8 unk_1c[4];             // 0x01C, 0x0880C910 が入っていた
  u32 frameCounter;         // 0x020, フレームカウンタ (多分カーソルの点滅とかで使う)
  u8 page;                  // 0x024, 武器図鑑のページ (0: 剣, 1: 槍, 2: ハンマー, 3: 銃)
  weapon8_t selected;       // 0x025, カーソル位置の武器, 図鑑登録されてなくても、カーソル位置に対応する武器のIDが入る
  u8 cursorX;               // 0x026, 現在のカーソルのX位置 (0..4)
  u8 cursorY;               // 0x027, 現在のカーソルのY位置 (0..3)
  SpriteSet spriteSet;      // 0x028
  SpriteState sprite_48;    // 0x048
  SpriteState cursor;       // 0x0A8, カーソルのスプライト
  SpriteState unk_108[5];   // 0x108
  SpriteState unk_2e8[2];   // 0x2E8
  SpriteState sprite_3a8;   // 0x3A8
  SpriteState sprite_408;   // 0x408
  WeaponIconSprites icons;  // 0x488
  u8 unk_c08[396];          // 0xC08
  u32 scriptID_d94;         // 0xD94, 0x0AFE が入っていた, 図鑑を閉じる時に呼ばれている (in 0x08210e5e)
  bool32 closed;            // 0xD98, 図鑑を閉じる時にセットされる
  u8 unk_d9c[3492 - 0xD9C];
} WeaponDexMenu;
static_assert(sizeof(WeaponDexMenu) == 3492);

static const u8 sWeaponDexItemCounts[4] = {19, 19, 19, 3};  // 0x085af9ac, 武器図鑑の各ページのエントリ数

INCASM("asm/weapon_dex.inc");

s32 FUN_0820fedc(s32 page) { return sWeaponDexItemCounts[page]; }

s32 FUN_0820fee8(s32 n) { return n; }

NAKED weapon32_t WeaponDexMenu_GetPage1stEntry(s32 page) { INCFUNC("asm/func/WeaponDexMenu_GetPage1stEntry.inc"); }

NAKED bool32 WeaponDexMenu_CheckCursorPos(u32 x, s32 y, s32 page) { INCFUNC("asm/func/WeaponDexMenu_CheckCursorPos.inc"); }

NAKED s32 FUN_0820ff44(s32 page) { INCFUNC("asm/func/FUN_0820ff44.inc"); }

NAKED bool32 FUN_0820ff78(s32 page) { INCFUNC("asm/func/FUN_0820ff78.inc"); }

NAKED void FUN_0820ff98(WeaponDexMenu* p, s32 val) { INCFUNC("asm/func/FUN_0820ff98.inc"); }

NAKED void FUN_0820ffe8(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_0820ffe8.inc"); }

NAKED void FUN_0821053c(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_0821053c.inc"); }

NAKED void FUN_08210610(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210610.inc"); }

void FUN_082106a4(WeaponDexMenu* p) {
  SpriteState* cursor = &p->cursor;
  cursor->offsetX = p->cursorX * 24;
  cursor->offsetY = p->cursorY * 24;
}

NAKED void FUN_082106c8(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_082106c8.inc"); }

NAKED void FUN_08210718(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210718.inc"); }

NAKED s32 FUN_08210774(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210774.inc"); }

NAKED void FUN_08210ab0(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210ab0.inc"); }

NAKED void FUN_08210bb0(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210bb0.inc"); }

NAKED void FUN_08210c3c(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210c3c.inc"); }

NAKED void FUN_08210c70(WeaponDexMenu* p, u32 val) { INCFUNC("asm/func/FUN_08210c70.inc"); }

NAKED s32 WeaponDexMenu_Update(WeaponDexMenu* p) { INCFUNC("asm/func/WeaponDexMenu_Update.inc"); }

NAKED s32 WeaponDexMenu_Destroy(WeaponDexMenu* p) { INCFUNC("asm/func/WeaponDexMenu_Destroy.inc"); }

NAKED s32 WeaponDexMenu_Init(WeaponDexMenu* p, u32 _) { INCFUNC("asm/func/WeaponDexMenu_Init.inc"); }

NAKED WeaponDexMenu* WeaponDexMenu_Create(u32 _) { INCFUNC("asm/func/WeaponDexMenu_Create.inc"); }

NAKED void FUN_082110a4(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_082110a4.inc"); }
