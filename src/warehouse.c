#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "game.h"
#include "global.h"
#include "input.h"
#include "inventory.h"
#include "menu.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

struct Warehouse;
typedef void(WarehouseFunc)(struct Warehouse*);

// 倉庫のメニュー (処理的にはショップメニューと同様)
typedef struct Warehouse {
  Entity e;                       // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;             // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx gfx1;             // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;             // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[47];         // 0x0078, [44] がカーソル
  MenuSpritePair pair0;           // 0x1218, SPRITE_INVENTORY_ICONS
  u8 unk_12f8[0x130C - 0x12F8];   // 0x12F8, まだ未解析
  MenuSpritePair pair1;           // 0x130C, SPRITE_UI_START_MENU
  Tilemaps* tilemap;              // 0x13EC, TILEMAP_9F57
  rgb555* bgPltt;                 // 0x13F0, BGP_A41A
  u8* unk_13f4;                   // 0x13F4, '.i' の VM_GetPC_Proxy の戻り値
  u8* unk_13f8;                   // 0x13F8, '.w' の VM_GetPC_Proxy の戻り値
  u8* unk_13fc;                   // 0x13FC, '.a' の VM_GetPC_Proxy の戻り値
  u8* unk_1400;                   // 0x1400, '.s' の VM_GetPC_Proxy の戻り値
  u8 unk_1404;                    // 0x1404
  u8 unk_1405[7];                 // 0x1405, まだ未解析
  u8 unk_140c;                    // 0x140C
  u8 unk_140d;                    // 0x140D
  u16 stateTimer;                 // 0x140E, Warehouse_SetState が updateCallback を差し替えるときに 0 に戻す
  u8 unk_1410;                    // 0x1410, FUN_080b8920 が 0 を入れる
  u8 count;                       // 0x1411, '.n' の値, kinds の個数
  s8 unk_1412;                    // 0x1412
  s8 unk_1413;                    // 0x1413
  u8 kinds[5];                    // 0x1414, '.l' から count 個
  u8 unk_1419[5];                 // 0x1419, kinds ごとに 'P' / 'Z' / 'S'
  u8 unk_141e[5];                 // 0x141E, kinds ごとに 3 / 5 / 7
  u8 unk_1423[5];                 // 0x1423, kinds ごとに 44 / 45 / 16
  MenuCursor cursor;              // 0x1428, MenuCursor_Init(&cursor, 0, 0, 0, 4)
  u8 unk_1458[32];                // 0x1458, [0..15] と [16..31] を別の用途で使う
  u8 kind;                        // 0x1478, 0=太陽バンク 1=暗黒ローン それ以外=太陽スタンド
  u8 unk_1479;                    // 0x1479
  u8 unk_147a[0x1490 - 0x147A];   // 0x147A, まだ未解析
  u32 unk_1490;                   // 0x1490, '.e'
  WarehouseFunc* updateCallback;  // 0x1494
  WarehouseFunc* unk_1498;        // 0x1498, Warehouse_SetSubState が入れる
} Warehouse;
static_assert(sizeof(Warehouse) == 5276);

void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void FUN_080b6230(Warehouse* p);
void FUN_080b68bc(Warehouse* p);
void FUN_080b68f4(Warehouse* p);
void FUN_080b77f4(Warehouse* p);
void FUN_080b783c(Warehouse* p);
void FUN_080b8824(Warehouse* p);
void FUN_080b7118(Warehouse* p);
void FUN_080b8170(Warehouse* p);
void FUN_080b885c(Warehouse* p);
void FUN_080b90dc(Warehouse* p);

void Warehouse_SetState(Warehouse* p, WarehouseFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080b5ac8(Warehouse* p, s32 val) { p->unk_140c = val; }

void Warehouse_SetSubState(Warehouse* p, WarehouseFunc* fn, s32 val) {
  p->unk_1498 = fn;
  FUN_080b5ac8(p, val);
  p->stateTimer = 0;
}

// 前半16バイトに 0..15 を、後半16バイトに val を足した 16..31 を詰める
void FUN_080b5afc(Warehouse* p, s32 val) {
  u8* q;
  s32 i;

  for (i = 15, q = &p->unk_1458[15]; i >= 0; i--) {
    *q-- = i;
  }

  for (i = 16; i <= 31; i++) {
    p->unk_1458[i] = i + val;
  }
}

// BG bg のタイルマップで (x, y) のエントリを指す (32x32 でラップ)
static BgMapEntry* FUN_080b5b30(s32 bgID, s32 x, s32 y) {
  BgState* bg = &gBgStates[bgID];
  BgMapEntry* tilemap = bg->tilemap;

  return tilemap + (x & 0x1F) + (y & 0x1F) * 32;
}

void Warehouse_ShowMessage(Warehouse* p, s32 line) {
  FUN_08049e5c();
  p->sprites[39].flags |= SPRFLAG_HIDDEN;
  MessageWindow_Start(p->unk_1400);
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_ShowLine(line);
}

NAKED void FUN_080b5b94(Warehouse* p) { INCFUNC("asm/func/FUN_080b5b94.inc"); }

NAKED void FUN_080b5cac(Warehouse* p) { INCFUNC("asm/func/FUN_080b5cac.inc"); }

NAKED void FUN_080b5e48(Warehouse* p, s32 param_2) { INCFUNC("asm/func/FUN_080b5e48.inc"); }

NAKED s32 FUN_080b5f18(Warehouse* p) { INCFUNC("asm/func/FUN_080b5f18.inc"); }

void FUN_080b5fd0(Warehouse* p) { SwapNormalItem(p->unk_1458[(u8)p->cursor.slot], p->unk_1458[(u8)p->cursor.savedSlot]); }

void FUN_080b6000(Warehouse* p) { RemoveItem(p->unk_1458[(u8)p->cursor.savedSlot]); }

NAKED void FUN_080b601c(Warehouse* p) { INCFUNC("asm/func/FUN_080b601c.inc"); }

NAKED void FUN_080b6114(Warehouse* p) { INCFUNC("asm/func/FUN_080b6114.inc"); }

void FUN_080b61c4(Warehouse* p) {
  p->sprites[45].flags |= SPRFLAG_HIDDEN;
  p->sprites[44].flags &= ~SPRFLAG_HIDDEN;
  FUN_080b5cac(p);
  FUN_080b9fe8(&p->cursor);
  FUN_080b9fc4(&p->cursor, &p->sprites[44]);
  FUN_080b9d94(&p->cursor, 4);
  FUN_080b5b94(p);
  FUN_080b5e48(p, 0);
  Warehouse_SetSubState(p, FUN_080b6230, 1);
}

NAKED void FUN_080b6230(Warehouse* p) { INCFUNC("asm/func/FUN_080b6230.inc"); }

NAKED void FUN_080b649c(Warehouse* p) { INCFUNC("asm/func/FUN_080b649c.inc"); }

NAKED void FUN_080b6684(Warehouse* p) { INCFUNC("asm/func/FUN_080b6684.inc"); }

void FUN_080b6754(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(0xDD);
    SortInventory(0);
    p->cursor.savedRow = 0;
    p->cursor.savedCol = 0;
    p->cursor.savedSlot = 0;
    FUN_080b61c4(p);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b61c4(p);
  }
}

void FUN_080b67c0(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(0xDD);
    SortInventory(p->unk_1458[16]);
    p->cursor.savedRow = 4;
    p->cursor.savedCol = 0;
    p->cursor.savedSlot = 16;
    FUN_080b61c4(p);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b61c4(p);
  }
}

void FUN_080b6834(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    FUN_080b5fd0(p);
    FUN_080b61c4(p);
  }
}

void FUN_080b685c(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    p->sprites[44].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    FUN_080b6114(p);
    Warehouse_SetSubState(p, FUN_080b68bc, 0);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b61c4(p);
  }
}

void FUN_080b68bc(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    FUN_080b6000(p);
    PlaySound_082406e0(0x10E);
    Warehouse_SetSubState(p, FUN_080b68f4, 0);
  }
}

void FUN_080b68f4(Warehouse* p) {
  p->stateTimer++;
  if (p->stateTimer <= 11) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[35].pos.y = 64;
    } else {
      p->sprites[35].pos.y = 64 - ((20 - p->stateTimer) >> 3);
    }
  } else if (p->stateTimer <= 15) {
    p->sprites[35].pos.y = 64;
  } else {
    FUN_080b61c4(p);
  }
}

void FUN_080b695c(Warehouse* p, s32 val) {
  FUN_080b5afc(p, val);
  FUN_080b5cac(p);
  MenuCursor_Init(&p->cursor, 0, 0, 0, 4);
  FUN_080b9fc4(&p->cursor, &p->sprites[44]);
  FUN_080b5b94(p);
  FUN_080b5e48(p, 0);
  Warehouse_SetSubState(p, FUN_080b6230, 1);
}

NAKED void FUN_080b69b8(Warehouse* p) { INCFUNC("asm/func/FUN_080b69b8.inc"); }

NAKED void FUN_080b6a74(Warehouse* p) { INCFUNC("asm/func/FUN_080b6a74.inc"); }

s32 Warehouse_FindRegisteredSlot(Warehouse* p, s32 n) {
  s32 i;

  if (n > 15) {
    return -1;
  }

  for (i = 0; i < 4; i++) {
    if ((s16)gStat->registeredWeapon[i] == n) {
      return i;
    }
  }

  return -1;
}

NAKED void FUN_080b6ca8(Warehouse* p) { INCFUNC("asm/func/FUN_080b6ca8.inc"); }

NAKED void FUN_080b6dc4(Warehouse* p) { INCFUNC("asm/func/FUN_080b6dc4.inc"); }

NAKED void FUN_080b6e70(Warehouse* p, s32 param_2) { INCFUNC("asm/func/FUN_080b6e70.inc"); }

NAKED s32 FUN_080b6fa4(Warehouse* p) { INCFUNC("asm/func/FUN_080b6fa4.inc"); }

void FUN_080b70ac(Warehouse* p) {
  p->sprites[45].flags |= SPRFLAG_HIDDEN;
  p->sprites[44].flags &= ~SPRFLAG_HIDDEN;
  FUN_080b6a74(p);
  FUN_080b9fe8(&p->cursor);
  FUN_080b9fc4(&p->cursor, &p->sprites[44]);
  FUN_080b9d94(&p->cursor, 4);
  FUN_080b69b8(p);
  FUN_080b6e70(p, 0);
  Warehouse_SetSubState(p, FUN_080b7118, 1);
}

NAKED void FUN_080b7118(Warehouse* p) { INCFUNC("asm/func/FUN_080b7118.inc"); }

NAKED void FUN_080b73b8(Warehouse* p) { INCFUNC("asm/func/FUN_080b73b8.inc"); }

NAKED void FUN_080b75a0(Warehouse* p) { INCFUNC("asm/func/FUN_080b75a0.inc"); }

void FUN_080b7670(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(0xDD);
    SortWeapons(0);
    p->cursor.savedRow = 0;
    p->cursor.savedCol = 0;
    p->cursor.savedSlot = 0;
    FUN_080b70ac(p);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b70ac(p);
  }
}

void FUN_080b76dc(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(0xDD);
    SortWeapons(p->unk_1458[16]);
    p->cursor.savedRow = 4;
    p->cursor.savedCol = 0;
    p->cursor.savedSlot = 16;
    FUN_080b70ac(p);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b70ac(p);
  }
}

void FUN_080b7750(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    SwapWeaponSlot(p->unk_1458[(u8)p->cursor.slot], p->unk_1458[(u8)p->cursor.savedSlot]);
    FUN_080b70ac(p);
  }
}

void FUN_080b7794(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    p->sprites[44].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    FUN_080b6dc4(p);
    Warehouse_SetSubState(p, FUN_080b77f4, 0);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b70ac(p);
  }
}

void FUN_080b77f4(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    FUN_08242c08(p->unk_1458[(u8)p->cursor.savedSlot]);
    PlaySound_082406e0(0x10E);
    Warehouse_SetSubState(p, FUN_080b783c, 0);
  }
}

void FUN_080b783c(Warehouse* p) {
  p->stateTimer++;
  if (p->stateTimer <= 11) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[35].pos.y = 64;
    } else {
      p->sprites[35].pos.y = 64 - ((20 - p->stateTimer) >> 3);
    }
  } else if (p->stateTimer <= 15) {
    p->sprites[35].pos.y = 64;
  } else {
    FUN_080b70ac(p);
  }
}

void FUN_080b78a4(Warehouse* p, s32 val) {
  FUN_080b5afc(p, val);
  FUN_080b6a74(p);
  MenuCursor_Init(&p->cursor, 0, 0, 0, 4);
  FUN_080b9fc4(&p->cursor, &p->sprites[44]);
  FUN_080b69b8(p);
  FUN_080b6e70(p, 0);
  Warehouse_SetSubState(p, FUN_080b7118, 1);
}

NAKED void FUN_080b7900(Warehouse* p) { INCFUNC("asm/func/FUN_080b7900.inc"); }

NAKED void FUN_080b79d8(Warehouse* p) { INCFUNC("asm/func/FUN_080b79d8.inc"); }

NAKED void FUN_080b7c18(Warehouse* p, s32 param_2) { INCFUNC("asm/func/FUN_080b7c18.inc"); }

NAKED s32 FUN_080b7d68(Warehouse* p) { INCFUNC("asm/func/FUN_080b7d68.inc"); }

// カーソル位置と退避位置の防具を入れ替える (装備中なら装備スロットも追従)
// 残差は armors のベース 0x150 を CSE してしまう1命令 (40/41命令), Tier A-C は試済
NON_MATCH void FUN_080b7e8c(Warehouse* p) {
#ifdef NONMATCHING_C
  s32 a = p->unk_1458[(u8)p->cursor.slot];
  s32 b = p->unk_1458[(u8)p->cursor.savedSlot];
  s32 tmp = (s16)gStat->armors[a];

  gStat->armors[a] = gStat->armors[b];
  gStat->armors[b] = tmp;

  if ((s16)gStat->armor == a) {
    gStat->armor = b;
  } else if ((s16)gStat->armor == b) {
    gStat->armor = a;
  }
#else
  INCFUNC("asm/func/FUN_080b7e8c.inc");
#endif
}

// 残差は -1 の materialize とアドレス加算の順序で2命令 (17/19命令), Tier A-C は試済
NON_MATCH void FUN_080b7ef0(Warehouse* p) {
#ifdef NONMATCHING_C
  gStat->armors[p->unk_1458[(u8)p->cursor.savedSlot]] = -1;
#else
  INCFUNC("asm/func/FUN_080b7ef0.inc");
#endif
}

NAKED void FUN_080b7f20(Warehouse* p) { INCFUNC("asm/func/FUN_080b7f20.inc"); }

NAKED void FUN_080b8044(Warehouse* p) { INCFUNC("asm/func/FUN_080b8044.inc"); }

void FUN_080b8104(Warehouse* p) {
  p->sprites[45].flags |= SPRFLAG_HIDDEN;
  p->sprites[44].flags &= ~SPRFLAG_HIDDEN;
  FUN_080b79d8(p);
  FUN_080b9fe8(&p->cursor);
  FUN_080b9fc4(&p->cursor, &p->sprites[44]);
  FUN_080b9d94(&p->cursor, 4);
  FUN_080b7900(p);
  FUN_080b7c18(p, 0);
  Warehouse_SetSubState(p, FUN_080b8170, 1);
}

NAKED void FUN_080b8170(Warehouse* p) { INCFUNC("asm/func/FUN_080b8170.inc"); }

NAKED void FUN_080b8404(Warehouse* p) { INCFUNC("asm/func/FUN_080b8404.inc"); }

NAKED void FUN_080b85ec(Warehouse* p) { INCFUNC("asm/func/FUN_080b85ec.inc"); }

void FUN_080b86bc(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(0xDD);
    SortArmors(0);
    p->cursor.savedRow = 0;
    p->cursor.savedCol = 0;
    p->cursor.savedSlot = 0;
    FUN_080b8104(p);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b8104(p);
  }
}

void FUN_080b8728(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(0xDD);
    SortArmors(p->unk_1458[16]);
    p->cursor.savedRow = 4;
    p->cursor.savedCol = 0;
    p->cursor.savedSlot = 16;
    FUN_080b8104(p);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b8104(p);
  }
}

void FUN_080b879c(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    FUN_080b7e8c(p);
    FUN_080b8104(p);
  }
}

void FUN_080b87c4(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    p->sprites[44].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    FUN_080b8044(p);
    Warehouse_SetSubState(p, FUN_080b8824, 0);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080b8104(p);
  }
}

void FUN_080b8824(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    FUN_080b7ef0(p);
    PlaySound_082406e0(0x10E);
    Warehouse_SetSubState(p, FUN_080b885c, 0);
  }
}

void FUN_080b885c(Warehouse* p) {
  p->stateTimer++;
  if (p->stateTimer <= 11) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[35].pos.y = 64;
    } else {
      p->sprites[35].pos.y = 64 - ((20 - p->stateTimer) >> 3);
    }
  } else if (p->stateTimer <= 15) {
    p->sprites[35].pos.y = 64;
  } else {
    FUN_080b8104(p);
  }
}

void FUN_080b88c4(Warehouse* p, s32 val) {
  FUN_080b5afc(p, val);
  FUN_080b79d8(p);
  MenuCursor_Init(&p->cursor, 0, 0, 0, 4);
  FUN_080b9fc4(&p->cursor, &p->sprites[44]);
  FUN_080b7900(p);
  FUN_080b7c18(p, 0);
  Warehouse_SetSubState(p, FUN_080b8170, 1);
}

NAKED void FUN_080b8920(Warehouse* p) { INCFUNC("asm/func/FUN_080b8920.inc"); }

void Warehouse_SetupBg(Warehouse* p) {
  s32 indices[1];

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_9F57);
  indices[0] = 0;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, indices);
  Video_SetBGLayer(0, p->tilemap, 5);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
}

void Warehouse_LoadBgPltt(Warehouse* p) {
  p->bgPltt = &GetBgPlttFile(BGP_A41A)->body[208];
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

NAKED void FUN_080b8b60(Warehouse* p) { INCFUNC("asm/func/FUN_080b8b60.inc"); }

void Warehouse_SetupMessageWindow(Warehouse* p) {
  if (VM_SeekToNamedArg('i')) p->unk_13f4 = VM_GetPC_Proxy();
  if (VM_SeekToNamedArg('w')) p->unk_13f8 = VM_GetPC_Proxy();
  if (VM_SeekToNamedArg('a')) p->unk_13fc = VM_GetPC_Proxy();
  if (VM_SeekToNamedArg('s')) p->unk_1400 = VM_GetPC_Proxy();

  FUN_08049f5c();
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_SetBgPltt(BGP_A41A);
}

void FUN_080b8f08(Warehouse* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    Warehouse_SetState(p, FUN_080b90dc);
  }
}

s32 Warehouse_HandleTabInput(Warehouse* p) {
  if (gInput[0].pressed & L_BUTTON) {
    s32 v = p->unk_1410;

    if (v == 0) {
      v = p->count;
    }

    p->unk_1410 = v - 1;
    return 1;
  }

  if (gInput[0].pressed & R_BUTTON) {
    p->unk_1410++;
    if (p->unk_1410 >= p->count) {
      p->unk_1410 = 0;
    }

    return 1;
  }

  return 0;
}

NAKED void FUN_080b8fa4(Warehouse* p) { INCFUNC("asm/func/FUN_080b8fa4.inc"); }

NAKED void FUN_080b9030(Warehouse* p) { INCFUNC("asm/func/FUN_080b9030.inc"); }

NAKED void FUN_080b90dc(Warehouse* p) { INCFUNC("asm/func/FUN_080b90dc.inc"); }

void FUN_080b9248(Warehouse* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    if (p->unk_1490 != 0) {
      VM_ExecByID(p->unk_1490, NULL);
    }

    KillEntity((Entity*)p);
  }
}

s32 Warehouse_Update(Warehouse* p) {
  FUN_080b94cc(p->kind);
  FUN_080b9400(p->kind);
  p->updateCallback(p);
  return 0;
}

s32 Warehouse_Destroy(Warehouse* p) {
  s32 i;

  for (i = 0; i < 47; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  FUN_080b9a0c(&p->pair0);
  FUN_080b9894(&p->pair1);
  return 0;
}

s32 Warehouse_Init(Warehouse* p) {
  FUN_080b8920(p);
  Warehouse_SetupBg(p);
  Warehouse_LoadBgPltt(p);
  FUN_080b8b60(p);
  Warehouse_SetupMessageWindow(p);
  FUN_0823ce68(2, 5, 4, 4, 4, 0xFFFF, 0);
  FUN_080b695c(p, 0);
  PlaySound_082406e0(0x118);
  Warehouse_SetState(p, FUN_080b8f08);
  return 0;
}

Warehouse* Warehouse_Create(void) {
  Warehouse* p = CreateEntity(ENTITY_UNK_11, sizeof(Warehouse));

  if (p != NULL) {
    SetEntityRoutine(p, Warehouse_Update, Warehouse_Destroy);
    if (Warehouse_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
