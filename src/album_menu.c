#include "entity.h"
#include "game.h"
#include "global.h"
#include "sprite.h"
#include "video.h"
#include "vm.h"

typedef struct {
  Entity e;    // 0x0, ENTITY_UNK_8
  void* p_18;  // 0x18,  0x08653534 固定?
  u8 unk_1c[4];
  u32 frameCounter;               // 0x020, フレームカウンタ (多分カーソルの点滅とかで使う)
  u8 page;                        // 0x024, 現在のページ (0: ページ1, 1: ページ2, 2: ページ3)
  u8 cursor;                      // 0x025, 現在のカーソルの位置番号,  = (cursorY * 5) + cursorX
  u8 cursorX;                     // 0x026, 現在のカーソルのX位置 (0..4)
  u8 cursorY;                     // 0x027, 現在のカーソルのY位置 (0..1)
  MainSpriteGfx spriteSet_28;     // 0x028
  MainSprite sprites_48[2];       // 0x048
  MainSprite sprites_108[5];      // 0x108
  MainSprite sprites_2e8[2];      // 0x2E8
  MainSprite sprites_3a8[2];      // 0x3A8
  MainSpriteGfx spriteSet_468;    // 0x468
  MainSprite sprites_488[5 * 2];  // 0x488
  u8 unk_848[24];                 // 0x848
  s16 unk_860;                    // 0x860, unk_868 の位相から決まる値
  u8 unk_862[6];                  // 0x862
  s16 unk_868;                    // 0x868, 0..49 を回るカウンタ
  u8 unk_86a[2];                  // 0x86A
  s32 panelID;                    // 0x86C, TextPanel_Create の戻り値。_Destroy が TextPanel_Hide に渡す
  u8* scriptPc;                   // 0x870, TextPanel_SetScript に渡す本文の位置
  u8* unk_874;                    // 0x874, 取得済みの写真の説明文
  u8* unk_878;                    // 0x878, 未取得の写真の説明文
  u8 unk_87c[4];                  // 0x87C
} AlbumMenu;
static_assert(sizeof(AlbumMenu) == 2176);

s32 TextPanel_Hide(s32 id);
s32 TextPanel_Start(s32 id);
s32 TextPanel_SetScript(s32 id, u8* scriptPc);
s32 TextPanel_SetMessage(s32 id, s32 msgIdx);
s32 FUN_08049fa8(void);
s32 FUN_08049e5c(void);
void FUN_082376a4(MainSprite* p, MainSpriteGfx* gfx, s32 value, s32 counts, s32 base, s32 x, s32 y, s32 dx, s32 zeroSuppress);
s32 FUN_08049e30(char* str);

const u8 gAlbumPhotoSlotCounts[3] = {10, 10, 7};  // アルバムの各ページのブロマイドスロット数

const u16 u16_ARRAY_085af9b4[54] = {
    0x0, 0x0, 0x1, 0x0, 0x2, 0x0, 0x3, 0x0, 0x5, 0x0, 0x6, 0x0, 0x4, 0x0, 0x7, 0x0, 0x8, 0x0, 0x1D, 0x0, 0x9, 0x0, 0xA, 0x0, 0xB, 0x0, 0xC, 0x0, 0xD, 0x0, 0xE, 0x0, 0xF, 0x0, 0x10, 0x0, 0x15, 0x0, 0x16, 0x0, 0x17, 0x0, 0x11, 0x0, 0x12, 0x0, 0x14, 0x0, 0x13, 0x0, 0x18, 0x0, 0x19, 0x0,
};  // 0x085af9b4

// 使われてなさそう (代わりに VM_UnlockPhoto を使っている)
void Unused_UnlockPhoto(u32 photoIdx) { gStat->photo |= (1 << photoIdx); }

u32 CheckPhotoUnlocked(u32 photoIdx) { return gStat->photo & (1 << photoIdx); }

// スクリプトの 'i' が指すブロマイドを取得済みにする
void VM_UnlockPhoto(void) {
  if (VM_SeekToKeyword('i')) {
    s32 idx = Script_GetValue();
    gStat->photo |= 1 << idx;
  }
}

// 取得済みのブロマイドの枚数
s32 CountUnlockedPhotos(void) {
  s32 count = 0;
  s32 i = 0;
  s32 flags = gStat->photo;

  for (; i < 27; i++) {
    if ((flags >> i) & 1) {
      count++;
    }
  }
  return count;
}

s32 AlbumMenu_GetPhotoSlotCount(s32 page) { return gAlbumPhotoSlotCounts[page]; }

u32 FUN_08211160(u32 n) { return n; }

// そのページより前のページに入る枚数の合計
s32 FUN_08211164(s32 page) {
  s32 total = 0;
  s32 i;

  for (i = 0; i < page; i++) {
    total += AlbumMenu_GetPhotoSlotCount(i);
  }
  return total;
}

// そのマスに写真が入りうるか
NON_MATCH bool32 AlbumMenu_CheckCursorPos(s32 x, s32 y, s32 page) {
#ifdef NONMATCHING_C
  if (x >= 0 && x <= 4 && y >= 0 && y <= 1 && AlbumMenu_GetPhotoSlotCount(page) >= x + y * 5 + 1) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/AlbumMenu_CheckCursorPos.inc");
#endif
}

// 27枚以上集まっているか
bool32 FUN_082111b8(void) { return CountUnlockedPhotos() > 26; }

// カーソル位置の写真の説明をテキストパネルに出す
NON_MATCH void FUN_082111cc(AlbumMenu* p) {
#ifdef NONMATCHING_C
  if (CheckPhotoUnlocked(p->cursor)) {
    TextPanel_SetScript(p->panelID, p->scriptPc);
    TextPanel_SetMessage(p->panelID, p->cursor);
    TextPanel_Start(p->panelID);
    FUN_08049e5c();
    FUN_08049e30(Textbox_LookupString(VM_ParseStringRef(p->unk_874) + p->cursor));
  } else {
    TextPanel_SetScript(p->panelID, p->scriptPc);
    TextPanel_SetMessage(p->panelID, 27);
    TextPanel_Start(p->panelID);
    FUN_08049e5c();
    FUN_08049e30(Textbox_LookupString(VM_ParseStringRef(p->unk_878) + p->cursor));
  }
#else
  INCFUNC("asm/func/FUN_082111cc.inc");
#endif
}

// 「取得数 / 27」の数字を並べる
void FUN_0821126c(AlbumMenu* p) {
  FUN_082376a4(&p->sprites_108[0], &p->spriteSet_28, CountUnlockedPhotos(), 2, 0, 176, 104, 8, 0);
  MainSprite_SetPose(&p->sprites_108[2], &p->spriteSet_28, 11, 0);
  p->sprites_108[2].pos.x = 192;
  p->sprites_108[2].pos.y = 104;
  p->sprites_108[2].flags &= ~SPRFLAG_HIDDEN;
  FUN_082376a4(&p->sprites_108[3], &p->spriteSet_28, 27, 2, 0, 200, 104, 8, 0);
}

// カーソルのスプライトをマス目に合わせて置き直す
void FUN_08211300(AlbumMenu* p) {
  MainSprite* cursor = &p->sprites_48[1];

  cursor->pos.x = p->cursorX * 40;
  cursor->pos.y = p->cursorY * 40;
}

// 50フレーム周期でカーソルの明るさを進める
void FUN_08211324(AlbumMenu* p) {
  s16 level;

  if (p->unk_868 <= 9) {
    level = 31;
  } else if (p->unk_868 <= 17) {
    level = 27;
  } else if (p->unk_868 <= 25) {
    level = 18;
  } else if (p->unk_868 <= 33) {
    level = 10;
  } else if (p->unk_868 <= 41) {
    level = 18;
  } else {
    level = 27;
  }
  p->unk_868++;
  if (p->unk_868 > 49) {
    p->unk_868 = 0;
  }
  p->unk_860 = level;
}

// ページ見出しを差し替え、全枚数が揃っていれば追加の2枚を出す
void FUN_08211378(AlbumMenu* p) {
  s32 i;

  MainSprite_SetPose(&p->sprites_48[0], &p->spriteSet_28, p->page + 30, 0);
  if (FUN_082111b8()) {
    for (i = 0; i < 2; i++) {
      MainSprite_Show(&p->sprites_2e8[i]);
    }
  } else {
    for (i = 0; i < 2; i++) {
      MainSprite_Hide(&p->sprites_2e8[i]);
    }
  }
}

NAKED s32 FUN_082113d4(AlbumMenu* p) { INCFUNC("asm/func/FUN_082113d4.inc"); }

NAKED void FUN_08211640(AlbumMenu* p) { INCFUNC("asm/func/FUN_08211640.inc"); }

// ページ内の写真アイコンを並べ、未取得の枠と余った枠は隠す
NON_MATCH void FUN_08211730(AlbumMenu* p) {
#ifdef NONMATCHING_C
  s32 count = AlbumMenu_GetPhotoSlotCount(p->page);
  s32 first = FUN_08211164(p->page);
  MainSprite* photo = p->sprites_488;
  s32 i;

  for (i = 0; i < count; photo++, i++) {
    s32 idx = first + i;

    if (CheckPhotoUnlocked(idx)) {
      MainSprite_SetPose(photo, &p->spriteSet_468, u16_ARRAY_085af9b4[idx * 2], 0);
      photo->flags &= ~SPRFLAG_HIDDEN;
    } else {
      photo->flags |= SPRFLAG_HIDDEN;
    }
  }
  for (; i < 10; photo++, i++) {
    photo->flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_08211730.inc");
#endif
}

// ページを切り替えて並べ直す
void FUN_082117bc(AlbumMenu* p, u32 page) {
  p->page = page;
  FUN_08211640(p);
}

NAKED s32 AlbumMenu_Update(AlbumMenu* p) { INCFUNC("asm/func/AlbumMenu_Update.inc"); }

s32 AlbumMenu_Destroy(AlbumMenu* p) {
  s32 i;

  MainSprite_Remove(&p->sprites_48[0]);
  MainSprite_Remove(&p->sprites_48[1]);
  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->sprites_108[i]);
  }
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites_2e8[i]);
  }
  for (i = 0; i < 10; i++) {
    MainSprite_Remove(&p->sprites_488[i]);
  }
  MainSprite_Remove(&p->sprites_3a8[0]);
  MainSprite_Remove(&p->sprites_3a8[1]);
  TextPanel_Hide(p->panelID);
  FUN_08049fa8();
  SetBGPrioDirect(0, 0);
  return 0;
}

NAKED s32 AlbumMenu_Init(AlbumMenu* p, u32 n) { INCFUNC("asm/func/AlbumMenu_Init.inc"); }

AlbumMenu* AlbumMenu_Create(s32 n) {
  AlbumMenu* p = CreateEntity(ENTITY_UNK_8, sizeof(AlbumMenu));

  if (p != NULL) {
    SetEntityRoutine(p, AlbumMenu_Update, AlbumMenu_Destroy);
    if (AlbumMenu_Init(p, n) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
