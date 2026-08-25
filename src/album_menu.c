#include "game.h"
#include "global.h"
#include "sprite.h"

typedef struct {
  Entity e;    // 0x0, ENTITY_UNK_8
  void* p_18;  // 0x18,  0x08653534 固定?
  u8 unk_1c[4];
  u32 frameCounter;   // 0x20, フレームカウンタ (多分カーソルの点滅とかで使う)
  u8 page;            // 0x24, 現在のページ (0: ページ1, 1: ページ2, 2: ページ3)
  u8 cursor;          // 0x25, 現在のカーソルの位置番号,  = (cursorY * 5) + cursorX
  u8 cursorX;         // 0x26, 現在のカーソルのX位置 (0..4)
  u8 cursorY;         // 0x27, 現在のカーソルのY位置 (0..1)
  SpriteData sprite;  // 0x28
  u8 unk_a8[2176 - 0xA8];
} AlbumMenu;
static_assert(sizeof(AlbumMenu) == 2176);

const u8 gAlbumPhotoSlotCounts[3] = {10, 10, 7};  // アルバムの各ページのブロマイドスロット数

const u16 u16_ARRAY_085af9b4[54] = {
    0x0, 0x0, 0x1, 0x0, 0x2, 0x0, 0x3, 0x0, 0x5, 0x0, 0x6, 0x0, 0x4, 0x0, 0x7, 0x0, 0x8, 0x0, 0x1D, 0x0, 0x9, 0x0, 0xA, 0x0, 0xB, 0x0, 0xC, 0x0, 0xD, 0x0, 0xE, 0x0, 0xF, 0x0, 0x10, 0x0, 0x15, 0x0, 0x16, 0x0, 0x17, 0x0, 0x11, 0x0, 0x12, 0x0, 0x14, 0x0, 0x13, 0x0, 0x18, 0x0, 0x19, 0x0,
};  // 0x085af9b4

// 使われてなさそう (代わりに VM_UnlockPhoto を使っている)
void Unused_UnlockPhoto(u32 photoIdx) { gStat->photo |= (1 << photoIdx); }

u32 CheckPhotoUnlocked(u32 photoIdx) { return gStat->photo & (1 << photoIdx); }

NAKED void VM_UnlockPhoto(void) { INCFUNC("asm/func/VM_UnlockPhoto.inc"); }

NAKED s32 CountUnlockedPhotos(void) { INCFUNC("asm/func/CountUnlockedPhotos.inc"); }

s32 AlbumMenu_GetPhotoSlotCount(s32 page) { return gAlbumPhotoSlotCounts[page]; }

u32 FUN_08211160(u32 n) { return n; }

NAKED s32 FUN_08211164(s32 page) { INCFUNC("asm/func/FUN_08211164.inc"); }

NAKED bool32 AlbumMenu_CheckCursorPos(u32 x, s32 y, s32 page) { INCFUNC("asm/func/AlbumMenu_CheckCursorPos.inc"); }

NAKED bool32 FUN_082111b8(void) { INCFUNC("asm/func/FUN_082111b8.inc"); }

NAKED void FUN_082111cc(AlbumMenu* p) { INCFUNC("asm/func/FUN_082111cc.inc"); }

NAKED void FUN_0821126c(AlbumMenu* p) { INCFUNC("asm/func/FUN_0821126c.inc"); }

NAKED void FUN_08211300(AlbumMenu* p) { INCFUNC("asm/func/FUN_08211300.inc"); }

NAKED void FUN_08211324(AlbumMenu* p) { INCFUNC("asm/func/FUN_08211324.inc"); }

NAKED void FUN_08211378(AlbumMenu* p) { INCFUNC("asm/func/FUN_08211378.inc"); }

NAKED s32 FUN_082113d4(AlbumMenu* p) { INCFUNC("asm/func/FUN_082113d4.inc"); }

NAKED void FUN_08211640(AlbumMenu* p) { INCFUNC("asm/func/FUN_08211640.inc"); }

NAKED void FUN_08211730(AlbumMenu* p) { INCFUNC("asm/func/FUN_08211730.inc"); }

NAKED void FUN_082117bc(AlbumMenu* p, u32 n) { INCFUNC("asm/func/FUN_082117bc.inc"); }

NAKED s32 AlbumMenu_Update(AlbumMenu* p) { INCFUNC("asm/func/AlbumMenu_Update.inc"); }

NAKED s32 AlbumMenu_Destroy(AlbumMenu* p) { INCFUNC("asm/func/AlbumMenu_Destroy.inc"); }

NAKED s32 AlbumMenu_Init(AlbumMenu* p, u32 n) { INCFUNC("asm/func/AlbumMenu_Init.inc"); }

NAKED AlbumMenu* AlbumMenu_Create(u32 n) { INCFUNC("asm/func/AlbumMenu_Create.inc"); }
