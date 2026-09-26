#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "video.h"

typedef struct {
  MainSpriteGfx gfx;        // 0x00
  MainSprite icons[5 * 4];  // 0x20
} WeaponIconSprites;

typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_8
  void* p_18;                 // 0x018,  0x08653534 固定?
  rgb555* pltt_1c;            // 0x01C, 根拠: 0x08210b06
  u32 frameCounter;           // 0x020, フレームカウンタ (多分カーソルの点滅とかで使う)
  u8 page;                    // 0x024, 武器図鑑のページ (0: 剣, 1: 槍, 2: ハンマー, 3: 銃)
  weapon8_t selected;         // 0x025, カーソル位置の武器, 図鑑登録されてなくても、カーソル位置に対応する武器のIDが入る
  u8 cursorX;                 // 0x026, 現在のカーソルのX位置 (0..4)
  u8 cursorY;                 // 0x027, 現在のカーソルのY位置 (0..3)
  MainSpriteGfx gfx;          // 0x028
  MainSprite sprite_48;       // 0x048
  MainSprite cursor;          // 0x0A8, カーソルのスプライト
  MainSprite unk_108[5];      // 0x108
  MainSprite unk_2e8[2];      // 0x2E8
  MainSprite sprite_3a8;      // 0x3A8
  MainSprite sprite_408;      // 0x408
  WeaponIconSprites icons;    // 0x468, gfx が 0x468、icons[20] が 0x488 から 0x60 刻み
  MainSprite sprite_c08;      // 0xC08
  u8 unk_c68[24];             // 0xC68
  u16 unk_c80;                // 0xC80, unk_c88 の位相から決まる値
  u8 unk_c82[6];              // 0xC82
  u16 unk_c88;                // 0xC88, 0..49 を回るカウンタ
  u8 unk_c8a;                 // 0xC8A, 根拠: 0x08210602
  u8 unk_c8b;                 // 0xC8B
  AuxSprite node_c8c;         // 0xC8C, 根拠: 0x08210ef8
  AuxSpriteGfx sprite_cb8;    // 0xCB8, 根拠: 0x08210a2e
  DexPreview preview;         // 0xCD4, 根拠: FUN_08055e34
  rgb555 pltt_d68[16];        // 0xD68, 根拠: 0x08210a20
  u8 unk_d88;                 // 0xD88, FUN_082110a4 が 1 増やすカウンタ
  u8 unk_d89;                 // 0xD89, FUN_082110a4 が 0 に戻す
  u8 unk_d8a[0xD94 - 0xD8A];  // 0xD8A
  u32 scriptID_d94;           // 0xD94, 0x0AFE が入っていた, 図鑑を閉じる時に呼ばれている (in 0x08210e5e)
  bool32 closed;              // 0xD98, 図鑑を閉じる時にセットされる
  u8 unk_d9c[8];
} WeaponDexMenu;
static_assert(sizeof(WeaponDexMenu) == 3492);

static const u8 sWeaponDexItemCounts[4] = {19, 19, 19, 3};  // 0x085af9ac, 武器図鑑の各ページのエントリ数

bool32 IsWeaponAlreadyFound(weapon32_t n);
void FUN_082376a4(MainSprite* p, MainSpriteGfx* gfx, s32 value, s32 counts, s32 base, s32 x, s32 y, s32 dx, s32 zeroSuppress);
s32 FUN_08049fa8(void);
void FUN_08055d7c(DexPreview* p);

INCASM("asm/weapon_dex.inc");

s32 WeaponDexMenu_GetPageEntryCount(s32 page) { return sWeaponDexItemCounts[page]; }

s32 FUN_0820fee8(s32 n) { return n; }

// そのページの先頭に並ぶ武器のID
weapon32_t WeaponDexMenu_GetPage1stEntry(s32 page) {
  switch (page) {
    case 0: {
      return WEAPON_GRADIUS;
    }
    case 1: {
      return WEAPON_SHORT_SPEAR;
    }
    case 2: {
      return WEAPON_CLUB;
    }
    case 3: {
      return WEAPON_GUN_DEL_SOL;
    }
    default: {
      return WEAPON_GRADIUS;
    }
  }
}

// そのマスに武器が並んでいるか
NON_MATCH bool32 WeaponDexMenu_CheckCursorPos(s32 x, s32 y, s32 page) {
#ifdef NONMATCHING_C
  if (x >= 0 && x <= 4 && y >= 0 && y <= 3 && WeaponDexMenu_GetPageEntryCount(page) >= x + y * 5 + 1) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/WeaponDexMenu_CheckCursorPos.inc");
#endif
}

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

// 武器の種別ごとの色をパレットの3か所に差し込む
NON_MATCH void FUN_0820ff98(WeaponDexMenu* p, s32 kind) {
#ifdef NONMATCHING_C
  rgb555* src = &gObjPlttData[40 * 16];

  src += kind * 3;
  p->pltt_d68[5] = src[0];
  p->pltt_d68[6] = src[1];
  p->pltt_d68[13] = src[2];
  p->preview.u.main.sprite.pltt = p->pltt_d68;
#else
  INCFUNC("asm/func/FUN_0820ff98.inc");
#endif
}

NAKED void FUN_0820ffe8(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_0820ffe8.inc"); }

NAKED void FUN_0821053c(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_0821053c.inc"); }

// 「登録数 / 総数」の数字を並べる
void FUN_08210610(WeaponDexMenu* p) {
  FUN_082376a4(&p->unk_108[0], &p->gfx, WeaponDexMenu_CountFoundInPage(p->page), 2, 0, 32, 96, 8, 0);
  p->unk_108[2].pos.x = 48;
  p->unk_108[2].pos.y = 96;
  MainSprite_SetPose(&p->unk_108[2], &p->gfx, 11, 0);
  FUN_082376a4(&p->unk_108[3], &p->gfx, WeaponDexMenu_GetPageEntryCount(p->page), 2, 0, 56, 96, 8, 0);
}

void FUN_082106a4(WeaponDexMenu* p) {
  MainSprite* cursor = &p->cursor;
  cursor->pos.x = p->cursorX * 24;
  cursor->pos.y = p->cursorY * 24;
}

// 50フレーム周期でカーソルの明るさを進める
void FUN_082106c8(WeaponDexMenu* p) {
  u16 level;

  if (p->unk_c88 <= 9) {
    level = 31;
  } else if (p->unk_c88 <= 17) {
    level = 27;
  } else if (p->unk_c88 <= 25) {
    level = 18;
  } else if (p->unk_c88 <= 33) {
    level = 10;
  } else if (p->unk_c88 <= 41) {
    level = 18;
  } else {
    level = 27;
  }
  p->unk_c88++;
  if (p->unk_c88 > 49) {
    p->unk_c88 = 0;
  }
  p->unk_c80 = level;
}

// ページ見出しを差し替え、そのページが埋まっていれば追加の2枚を出す
void FUN_08210718(WeaponDexMenu* p) {
  s32 i;

  MainSprite_SetPose(&p->sprite_48, &p->gfx, p->page + 25, 0);
  if (WeaponDexMenu_IsPageComplete(p->page)) {
    for (i = 0; i < 2; i++) {
      MainSprite_Show(&p->unk_2e8[i]);
    }
  } else {
    for (i = 0; i < 2; i++) {
      MainSprite_Hide(&p->unk_2e8[i]);
    }
  }
}

NAKED s32 FUN_08210774(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210774.inc"); }

NAKED void FUN_08210ab0(WeaponDexMenu* p) { INCFUNC("asm/func/FUN_08210ab0.inc"); }

// ページ内の武器アイコンを並べ、未登録の枠と余った枠は隠す
void FUN_08210bb0(WeaponDexMenu* p) {
  s32 count = WeaponDexMenu_GetPageEntryCount(p->page);
  MainSprite* icon = p->icons.icons;
  weapon32_t first = WeaponDexMenu_GetPage1stEntry(p->page);
  s32 i;

  for (i = 0; i < count; icon++, i++) {
    if (IsWeaponAlreadyFound(first + i)) {
      MainSprite_SetPose(icon, &p->icons.gfx, FUN_0820fee8(first + i), 0);
      icon->flags &= ~SPRFLAG_HIDDEN;
    } else {
      icon->flags |= SPRFLAG_HIDDEN;
    }
  }
  for (; i < 20; icon++, i++) {
    icon->flags |= SPRFLAG_HIDDEN;
  }
}

// 図鑑のページがある番号なら本体とカーソルを表示する
void FUN_08210c3c(WeaponDexMenu* p) {
  switch (p->page) {
    case 0: {
      p->sprite_48.flags &= ~SPRFLAG_HIDDEN;
      p->cursor.flags &= ~SPRFLAG_HIDDEN;
      break;
    }
    case 1: {
      p->sprite_48.flags &= ~SPRFLAG_HIDDEN;
      p->cursor.flags &= ~SPRFLAG_HIDDEN;
      break;
    }
    case 2: {
      p->sprite_48.flags &= ~SPRFLAG_HIDDEN;
      p->cursor.flags &= ~SPRFLAG_HIDDEN;
      break;
    }
    case 3: {
      p->sprite_48.flags &= ~SPRFLAG_HIDDEN;
      p->cursor.flags &= ~SPRFLAG_HIDDEN;
      break;
    }
  }
}

// ページを切り替えてアイコンとカーソルを並べ直す
void FUN_08210c70(WeaponDexMenu* p, u32 page) {
  p->page = page;
  FUN_08210ab0(p);
  FUN_08210c3c(p);
}

NAKED s32 WeaponDexMenu_Update(WeaponDexMenu* p) { INCFUNC("asm/func/WeaponDexMenu_Update.inc"); }

s32 WeaponDexMenu_Destroy(WeaponDexMenu* p) {
  s32 i;

  MainSprite_Remove(&p->sprite_48);
  MainSprite_Remove(&p->cursor);
  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->unk_108[i]);
  }
  for (i = 0; i < 20; i++) {
    MainSprite_Remove(&p->icons.icons[i]);
  }
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->unk_2e8[i]);
  }
  AuxSprite_Remove(&p->node_c8c);
  MainSprite_Remove(&p->sprite_3a8);
  MainSprite_Remove(&p->sprite_408);
  FUN_08055d7c(&p->preview);
  MainSprite_Remove(&p->sprite_c08);
  SetBGPrioDirect(0, 0);
  FUN_08049fa8();
  return 0;
}

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

void FUN_082110a4(WeaponDexMenu* p) {
  p->unk_d89 = 0;
  p->unk_d88++;
}
