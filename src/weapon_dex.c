#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct {
  SpriteSet tmpl;            // 0x00
  SpriteState icons[5 * 4];  // 0x20
} WeaponIconSprites;

typedef struct {
  u32 unk_0;  // 0x00
  u8 unk_4[8];
  SpriteSet spriteSet;  // 0x0C
  SpriteState sprite;   // 0x2C
  Vec3* pos;            // 0x8C
  SpriteFlags* flags;   // 0x90
} WeaponDexData;
static_assert(sizeof(WeaponDexData) == 148);  // 根拠: 0x08055e54

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  void* p_18;                   // 0x018,  0x08653534 固定?
  rgb555* pltt_1c;              // 0x01C, 根拠: 0x08210b06
  u32 frameCounter;             // 0x020, フレームカウンタ (多分カーソルの点滅とかで使う)
  u8 page;                      // 0x024, 武器図鑑のページ (0: 剣, 1: 槍, 2: ハンマー, 3: 銃)
  weapon8_t selected;           // 0x025, カーソル位置の武器, 図鑑登録されてなくても、カーソル位置に対応する武器のIDが入る
  u8 cursorX;                   // 0x026, 現在のカーソルのX位置 (0..4)
  u8 cursorY;                   // 0x027, 現在のカーソルのY位置 (0..3)
  SpriteSet spriteSet;          // 0x028
  SpriteState sprite_48;        // 0x048
  SpriteState cursor;           // 0x0A8, カーソルのスプライト
  SpriteState unk_108[5];       // 0x108
  SpriteState unk_2e8[2];       // 0x2E8
  SpriteState sprite_3a8;       // 0x3A8
  SpriteState sprite_408;       // 0x408
  WeaponIconSprites icons;      // 0x488
  SpriteState sprite_c08;       // 0xC08
  u8 unk_c68[0xC8A - 0xC68];    // 0xC68
  u8 unk_c8a;                   // 0xC8A, 根拠: 0x08210602
  u8 unk_c8b;                   // 0xC8B
  q_SpriteNode44 node_c8c;      // 0xC8C, 根拠: 0x08210ef8
  ActorSpriteState sprite_cb8;  // 0xCB8, 根拠: 0x08210a2e
  WeaponDexData data_cd4;       // 0xCD4, 根拠: FUN_08055e34
  rgb555 pltt_d68[16];          // 0xD68, 根拠: 0x08210a20
  u8 unk_d88[0xD94 - 0xD88];
  u32 scriptID_d94;  // 0xD94, 0x0AFE が入っていた, 図鑑を閉じる時に呼ばれている (in 0x08210e5e)
  bool32 closed;     // 0xD98, 図鑑を閉じる時にセットされる
  u8 unk_d9c[8];
} WeaponDexMenu;
static_assert(sizeof(WeaponDexMenu) == 3492);

static const u8 sWeaponDexItemCounts[4] = {19, 19, 19, 3};  // 0x085af9ac, 武器図鑑の各ページのエントリ数

bool32 IsWeaponAlreadyFound(weapon32_t n);

INCASM("asm/weapon_dex.inc");

s32 WeaponDexMenu_GetPageEntryCount(s32 page) { return sWeaponDexItemCounts[page]; }

s32 FUN_0820fee8(s32 n) { return n; }

NAKED weapon32_t WeaponDexMenu_GetPage1stEntry(s32 page) { INCFUNC("asm/func/WeaponDexMenu_GetPage1stEntry.inc"); }

NAKED bool32 WeaponDexMenu_CheckCursorPos(u32 x, s32 y, s32 page) { INCFUNC("asm/func/WeaponDexMenu_CheckCursorPos.inc"); }

// ページ内で図鑑登録済みの武器の数を数える
s32 WeaponDexMenu_CountFoundInPage(s32 page) {
  s32 i;
  s32 count = WeaponDexMenu_GetPageEntryCount(page);
  weapon32_t first = WeaponDexMenu_GetPage1stEntry(page);
  s32 found = 0;
  for (i = 0; i < count; i++) {
    if (IsWeaponAlreadyFound(first + i)) {
      found++;
    }
  }
  return found;
}

// ページ内の武器が全て図鑑登録済みか
bool32 WeaponDexMenu_IsPageComplete(s32 page) { return WeaponDexMenu_CountFoundInPage(page) >= WeaponDexMenu_GetPageEntryCount(page); }

NAKED void FUN_0820ff98(WeaponDexMenu* p, s32 val) { INCFUNC("asm/func/FUN_0820ff98.inc"); }

NAKED void FUN_0820ffe8(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_0820ffe8.inc"); }

NAKED void FUN_0821053c(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_0821053c.inc"); }

NAKED void FUN_08210610(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210610.inc"); }

void FUN_082106a4(WeaponDexMenu* p) {
  SpriteState* cursor = &p->cursor;
  cursor->pos.x = p->cursorX * 24;
  cursor->pos.y = p->cursorY * 24;
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

WeaponDexMenu* WeaponDexMenu_Create(u32 id) {
  WeaponDexMenu* p = CreateEntity(ENTITY_UNK_8, sizeof(WeaponDexMenu));
  if (p != NULL) {
    SetEntityRoutine(p, WeaponDexMenu_Update, WeaponDexMenu_Destroy);
    if (WeaponDexMenu_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED void FUN_082110a4(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_082110a4.inc"); }
