#include "armor.h"
#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "inventory.h"
#include "item.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

struct Warehouse;
typedef void(WarehouseFunc)(struct Warehouse*);

// 倉庫のメニュー (処理的にはショップメニューと同様)
typedef struct Warehouse {
  Entity e;                       // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;             // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx icons;            // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;             // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[47];         // 0x0078, [44] がカーソル
  ShopSpritePair pair0;           // 0x1218, SPRITE_INVENTORY_ICONS
  u8 unk_12f8[0x130C - 0x12F8];   // 0x12F8, まだ未解析
  ShopSpritePair pair1;           // 0x130C, SPRITE_UI_START_MENU
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
  ShopCursor cursor;              // 0x1428, ShopCursor_Init(&cursor, 0, 0, 0, 4)
  u8 unk_1458[32];                // 0x1458, [0..15] と [16..31] を別の用途で使う
  u8 kind;                        // 0x1478, 0=太陽バンク 1=暗黒ローン それ以外=太陽スタンド
  u8 unk_1479;                    // 0x1479
  u8 unk_147a[0x1490 - 0x147A];   // 0x147A, まだ未解析
  u32 unk_1490;                   // 0x1490, '.e'
  WarehouseFunc* updateCallback;  // 0x1494
  WarehouseFunc* unk_1498;        // 0x1498, Warehouse_SetSubState が入れる
} Warehouse;
static_assert(sizeof(Warehouse) == 5276);

s32 Marquee_SetVarValue(s32 idx, s32 value);
s32 FUN_080b9da0(ShopCursor* p, u8 mask);
u32 Item_GetRotStageIcon(s32 slot);
bool32 IsWeaponRegistered(slot32_t n);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void GetWeaponData(slot32_t n, WeaponData* data);
void FUN_08094d1c(u8* param_1, s8* param_2);
void FUN_08094d48(unknown* w, u8* pc);
s32 GetWeaponWearPose(WeaponData* w);
void FUN_080b649c(Warehouse* p);
s32 Warehouse_FindRegisteredSlot(Warehouse* p, s32 n);
void FUN_080b685c(Warehouse* p);
void FUN_080b73b8(Warehouse* p);
void FUN_080b7794(Warehouse* p);
void FUN_080b5b94(Warehouse* p);
void FUN_080b69b8(Warehouse* p);
void FUN_080b8404(Warehouse* p);
void FUN_080b87c4(Warehouse* p);
void FUN_080b7900(Warehouse* p);
void FUN_080b9248(Warehouse* p);
void FUN_080b6834(Warehouse* p);
void FUN_080b86bc(Warehouse* p);
void FUN_080b8728(Warehouse* p);
void FUN_080b7670(Warehouse* p);
void FUN_080b76dc(Warehouse* p);
void FUN_080b6754(Warehouse* p);
void FUN_080b67c0(Warehouse* p);
void FUN_080b7750(Warehouse* p);
void FUN_080b879c(Warehouse* p);
void FUN_080b61c4(Warehouse* p);
void FUN_080b601c(Warehouse* p);
s32 FUN_080b5f18(Warehouse* p);
void FUN_080b5e48(Warehouse* p, s32 param_2);
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
  s32 i;

  for (i = 0; i < 16; i++) {
    p->unk_1458[i] = i;
  }
  for (i = 16; i < 32; i++) {
    p->unk_1458[i] = i + val;
  }
}

// BG bg のタイルマップで (x, y) のエントリを指す (32x32 でラップ)
static BgMapEntry* FUN_080b5b30(s32 bgID, s32 x, s32 y) {
  BgState* bg = &gBgStates[bgID];
  BgMapEntry* tilemap = bg->tilemap;

  return tilemap + (x & 0x1F) + (y & 0x1F) * 32;
}

void Warehouse_ShowMessage(Warehouse* p, s32 line, u8* pc, s32 val) {
  Marquee_Clear();
  p->sprites[39].flags |= SPRFLAG_HIDDEN;
  MessageWindow_Start(p->unk_1400);
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_ShowLine(line);
}

// カーソル位置の道具の説明文とアイコンを出す, 対象がなければ説明窓を閉じる
void FUN_080b5b94(Warehouse* p) {
  s32 id;
  s32 pose;

  if (p->cursor.shopColX <= 7) {
    id = GetNormalItemID(p->unk_1458[(u8)p->cursor.slot]);
    pose = Item_GetRotStageIcon(p->unk_1458[(u8)p->cursor.slot]);
  } else {
    id = -1;
    pose = ICON_TIMER_NONE;
  }

  if (id < 0) {
    p->sprites[39].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    s32 base;

    p->sprites[39].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[39], &p->icons, pose, PLAYMODE_LOOP);
    MessageWindow_Start(p->unk_13f4);
    MessageWindow_SetRect(2, 16, 28, 2);
    MessageWindow_SetInstant(1);
    MessageWindow_ShowLine(id);
    VM_ParseStringRef(p->unk_13f4);
    base = VM_ParseStringRef(p->unk_13f4);
    if (gStat->playerKind == 5) {
      if (id == 1) {
        Marquee_SetText(GetStringByID(base + 0xEA));
        return;
      }
      if (id == 0xD) {
        Marquee_SetText(GetStringByID(base + 0xA9));
        return;
      }
    }

    if (gStat->playerKind == 0 || gStat->playerKind == 5) {
      base += 0x4E;
    } else {
      base += 0x9C;
    }
    Marquee_SetText(GetStringByID(base + id));
  }
}

// 1つ目のループはスタック位置とレジスタ番号だけ違う, 2つ目のループは j が逆順カウントに変換される (189/186命令)
// 原典は2つ目のループも j を 0..3 で数え, slot を別に1ずつ増やす
NON_MATCH void FUN_080b5cac(Warehouse* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  p->unk_1412 = -1;
  p->unk_1413 = -1;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      s32 slot = i * 4 + j;
      item32_t id = GetNormalItemID(p->unk_1458[slot]);

      if (id >= 0) {
        p->sprites[slot + 3].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[slot + 3], &p->icons, id + 0x68, PLAYMODE_LOOP);
      } else {
        if (p->unk_1412 < 0) {
          p->unk_1412 = slot;
        }
        p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
      }
      FUN_080b95bc(&p->sprites[slot + 3], 0x2DF);
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      s32 slot = 16 + i * 4 + j;
      item32_t id = GetNormalItemID(p->unk_1458[slot]);

      if (id >= 0) {
        p->sprites[slot + 3].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[slot + 3], &p->icons, id + 0x68, PLAYMODE_LOOP);
      } else {
        if (p->unk_1413 < 0) {
          p->unk_1413 = slot;
        }
        p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
      }
    }
  }

  for (i = 0; i < 4; i++) {
    p->sprites[40 + i].flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_080b5cac.inc");
#endif
}

// カーソルの位置で道具を動かせるかを見て pair1 のスプライトを切り替える
void FUN_080b5e48(Warehouse* p, s32 param_2) {
  s32 ok;

  if (param_2 == 0) {
    if (p->cursor.shopColX == 8) {
      FUN_080b98c0(&p->pair1.gfx, 0, 4);
    } else {
      FUN_080b98c0(&p->pair1.gfx, 0, -1);
    }
    return;
  }

  if (GetNormalItemID(p->unk_1458[(u8)p->cursor.savedSlot]) < 0) {
    ok = GetNormalItemID(p->unk_1458[(u8)p->cursor.slot]) >= 0;
  } else if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    ok = ((u8)p->cursor.slot < 16 ? p->unk_1413 : p->unk_1412) >= 0;
  } else {
    ok = 1;
  }

  if (ok == 1) {
    FUN_080b98c0(&p->pair1.gfx, 3, -1);
  } else {
    FUN_080b98c0(&p->pair1.gfx, -1, -1);
  }
}

// 退避中の道具をカーソル位置へ置けるか判定する, 0: 不可 1: 可 2: スロット32 の上
s32 FUN_080b5f18(Warehouse* p) {
  if (GetNormalItemID(p->unk_1458[(u8)p->cursor.savedSlot]) < 0) {
    if (GetNormalItemID(p->unk_1458[(u8)p->cursor.slot]) < 0) {
      return 0;
    }
    return 1;
  }

  if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    if ((u8)p->cursor.slot < 16) {
      if (p->unk_1413 < 0) {
        return 0;
      }
      p->cursor.shopColX = p->unk_1413 & 3;
      p->cursor.shopRowY = (p->unk_1413 - 16) >> 2;
      p->cursor.slot = p->unk_1413;
      return 1;
    }

    if (p->unk_1412 < 0) {
      return 0;
    }
    p->cursor.shopColX = ((p->unk_1412 - 16) & 3) + 4;
    p->cursor.shopRowY = (p->unk_1412 - 16) >> 2;
    p->cursor.slot = p->unk_1412;
    return 1;
  }

  if ((u8)p->cursor.slot == 32) {
    return 2;
  }
  return 1;
}

void FUN_080b5fd0(Warehouse* p) { SwapNormalItem(p->unk_1458[(u8)p->cursor.slot], p->unk_1458[(u8)p->cursor.savedSlot]); }

void FUN_080b6000(Warehouse* p) { RemoveItem(p->unk_1458[(u8)p->cursor.savedSlot]); }

// カーソル位置と退避位置の2つの道具を入れ替えるアニメを仕込む
void FUN_080b601c(Warehouse* p) {
  WorldPos a[2];
  WorldPos b[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];
  s32 i;

  for (i = 0; i < 2; i++) {
    s32 slot = (i == 0) ? (u8)p->cursor.savedSlot : (u8)p->cursor.slot;
    s32 id;

    p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
    id = GetNormalItemID(p->unk_1458[slot]);
    if (id >= 0) {
      unk1[i] = 1;
    } else {
      unk1[i] = 0;
    }
    anims[i] = id + 0x68;
    strIDs[i] = 0x2DF;
    Shop_GetSlotPos(&a[i].x, slot);
  }

  for (i = 0; i < 2; i++) {
    b[i] = a[1 - i];
  }

  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// 預けた道具を金庫側へ飛ばす演出を仕込む
void FUN_080b6114(Warehouse* p) {
  WorldPos a[2];
  WorldPos b[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  p->sprites[(u8)p->cursor.savedSlot + 3].flags |= SPRFLAG_HIDDEN;
  anims[0] = GetNormalItemID(p->unk_1458[(u8)p->cursor.savedSlot]) + 0x68;
  strIDs[0] = 0x2DF;
  Shop_GetSlotPos(&a[0].x, (u8)p->cursor.savedSlot);
  Shop_GetSlotPos(&b[0].x, 32);
  unk1[1] = 0;
  anims[1] = 0x68;
  strIDs[1] = 0x2DF;
  VEC3_SET(a[1], 0, 0, 0);
  VEC3_SET(b[1], 0, 0, 0);
  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

void FUN_080b61c4(Warehouse* p) {
  p->sprites[45].flags |= SPRFLAG_HIDDEN;
  p->sprites[44].flags &= ~SPRFLAG_HIDDEN;
  FUN_080b5cac(p);
  FUN_080b9fe8(&p->cursor);
  ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
  FUN_080b9d94(&p->cursor, 4);
  FUN_080b5b94(p);
  FUN_080b5e48(p, 0);
  Warehouse_SetSubState(p, FUN_080b6230, 1);
}

// 道具の一覧画面の入力待ち, SELECT+A でタブ切り替え, A で整理/全部預ける/入れ替え元の選択
void FUN_080b6230(Warehouse* p) {
  FUN_080b95d0(&p->cursor, &p->sprites[35], &p->sprites[37], &p->sprites[38]);

  if (FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
  }

  if (gInput[0].down & SELECT_BUTTON) {
    FUN_080b5ac8(p, 0);
    MainSprite_SetPose(&p->sprites[44], &p->gfx0, 56, PLAYMODE_LOOP);
    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_CURSOR_MOVE);
      p->kind++;
      if (p->kind > 2) {
        p->kind = 0;
      }
    }
  } else {
    FUN_080b5ac8(p, 1);
    MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);

    if (gInput[0].pressed & A_BUTTON) {
      if ((u8)p->cursor.slot == 33) {
        PlaySound_082406e0(SE_SELECT);
        FUN_080b9fd8(&p->cursor);
        Warehouse_ShowMessage(p, 3, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 1);
        FUN_080b98c0(&p->pair1.gfx, -1, -1);
        Warehouse_SetSubState(p, FUN_080b6754, 0);
      } else if ((u8)p->cursor.slot == 34) {
        PlaySound_082406e0(SE_SELECT);
        FUN_080b9fd8(&p->cursor);
        Warehouse_ShowMessage(p, 4, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 1);
        FUN_080b98c0(&p->pair1.gfx, -1, -1);
        Warehouse_SetSubState(p, FUN_080b67c0, 0);
      } else {
        FUN_080b9fd8(&p->cursor);
        p->sprites[45].flags &= ~SPRFLAG_HIDDEN;
        p->sprites[45].pos = p->sprites[44].pos;
        if (GetNormalItemID(p->unk_1458[(u8)p->cursor.savedSlot]) >= 0) {
          FUN_080b9d94(&p->cursor, 24);
        } else {
          FUN_080b9d94(&p->cursor, 28);
        }
        PlaySound_082406e0(SE_SELECT);
        Warehouse_SetSubState(p, FUN_080b649c, 0);
        FUN_080b5e48(p, 1);
      }
    } else if (ShopCursor_Move(&p->cursor)) {
      ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
      FUN_080b5b94(p);
      FUN_080b5e48(p, 0);
    }
  }
}

// 道具の一覧の入力待ち, SELECT で整理の確認へ, A で入れ替え, B で戻る
void FUN_080b649c(Warehouse* p) {
  FUN_080b95d0(&p->cursor, &p->sprites[35], &p->sprites[37], &p->sprites[38]);

  if (FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags |= SPRFLAG_HIDDEN;
  } else {
    if (p->stateTimer < 30) {
      p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->sprites[36].flags |= SPRFLAG_HIDDEN;
    }
    if (++p->stateTimer >= 60) {
      p->stateTimer = 0;
    }
  }

  MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);

  if ((gInput[0].pressed & SELECT_BUTTON) && !FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
    Shop_GetSlotPos(&p->sprites[44].pos.x, 32);
    MainSprite_SetPose(&p->sprites[44], &p->gfx0, 56, PLAYMODE_LOOP);
    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    PlaySound_082406e0(SE_CHOICE);
    Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
    FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
    Warehouse_SetSubState(p, FUN_080b685c, 0);
  } else if (gInput[0].pressed & A_BUTTON) {
    s32 r = FUN_080b5f18(p);

    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    switch (r) {
      case 1: {
        FUN_080b601c(p);
        Warehouse_SetSubState(p, FUN_080b6834, 0);
        break;
      }
      case 2: {
        Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
        Warehouse_SetSubState(p, FUN_080b685c, 0);
        break;
      }
      default: {
        PlaySound_082406e0(SE_NG);
        break;
      }
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b61c4(p);
  } else if (ShopCursor_Move(&p->cursor)) {
    ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
    FUN_080b5b94(p);
    FUN_080b5e48(p, 1);
  }
}

// 道具の預け入れの確認, A で個数の入力へ, B で選択へ戻る
void FUN_080b6684(Warehouse* p) {
  MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);
  p->sprites[36].flags |= SPRFLAG_HIDDEN;
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_DRUMROLL);
    ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
    FUN_080b5b94(p);
    Warehouse_SetSubState(p, FUN_080b649c, 0);
  } else if (gInput[0].pressed & A_BUTTON) {
    p->sprites[44].flags |= SPRFLAG_HIDDEN;
    p->sprites[39].flags |= SPRFLAG_HIDDEN;
    PlaySound_082406e0(SE_CHOICE);
    Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
    FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
    Warehouse_SetSubState(p, FUN_080b685c, 0);
  }
}

void FUN_080b6754(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortInventory(0);
    p->cursor.savedShopColX = 0;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 0;
    FUN_080b61c4(p);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b61c4(p);
  }
}

void FUN_080b67c0(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortInventory(p->unk_1458[16]);
    p->cursor.savedShopColX = 4;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 16;
    FUN_080b61c4(p);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
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
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b61c4(p);
  }
}

void FUN_080b68bc(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    FUN_080b6000(p);
    PlaySound_082406e0(SE_TRASH);
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
  ShopCursor_Init(&p->cursor, 0, 0, 0, 4);
  ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
  FUN_080b5b94(p);
  FUN_080b5e48(p, 0);
  Warehouse_SetSubState(p, FUN_080b6230, 1);
}

// カーソルの武器の見た目と説明を出す, 武器がなければ消す
void FUN_080b69b8(Warehouse* p) {
  WeaponData w;

  if (p->cursor.shopColX < 8) {
    GetWeaponData(p->unk_1458[(u8)p->cursor.slot], &w);
  } else {
    w.id = WEAPON_NONE;
  }

  if (w.id == WEAPON_NONE) {
    p->sprites[39].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    s32 pose = GetWeaponWearPose(&w);

    p->sprites[39].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[39], &p->icons, pose, PLAYMODE_LOOP);
    MessageWindow_Start(p->unk_13f8);
    MessageWindow_SetRect(2, 16, 28, 2);
    FUN_08094d1c((u8*)&w, (s8*)&p->unk_1404);
    FUN_08094d48(&w, p->unk_13f8);
  }
}

// FUN_080b5cac の武器版で残差も同じ, 2つ目のループの j が逆順カウントに変換される (230/229命令)
NON_MATCH void FUN_080b6a74(Warehouse* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  p->unk_1412 = -1;
  p->unk_1413 = -1;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      s32 slot = i * 4 + j;
      weapon32_t id = GetWeaponID(p->unk_1458[slot]);

      if (id > 0) {
        p->sprites[slot + 3].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[slot + 3], &p->icons, id, PLAYMODE_LOOP);
      } else {
        if (p->unk_1412 < 0) {
          p->unk_1412 = slot;
        }
        p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
      }

      if (IsWeaponRegistered(slot)) {
        FUN_080b95bc(&p->sprites[slot + 3], 736);
      } else {
        FUN_080b95bc(&p->sprites[slot + 3], 735);
      }
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      s32 slot = 16 + i * 4 + j;
      weapon32_t id = GetWeaponID(p->unk_1458[slot]);

      if (id > 0) {
        p->sprites[slot + 3].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[slot + 3], &p->icons, id, PLAYMODE_LOOP);
      } else {
        if (p->unk_1413 < 0) {
          p->unk_1413 = slot;
        }
        p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
      }
    }
  }

  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) < 0) {
      p->sprites[40 + i].flags |= SPRFLAG_HIDDEN;
    } else {
      p->sprites[40 + i].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[40 + i].pos.x = (REGISTERED_WEAPON(i) & 3) * 24 + 144;
      p->sprites[40 + i].pos.y = ((s16)REGISTERED_WEAPON(i) >> 2) * 24 + 32;
    }
  }
#else
  INCFUNC("asm/func/FUN_080b6a74.inc");
#endif
}

s32 Warehouse_FindRegisteredSlot(Warehouse* p, s32 n) {
  s32 i;

  if (n > 15) {
    return -1;
  }

  for (i = 0; i < 4; i++) {
    if ((s16)REGISTERED_WEAPON(i) == n) {
      return i;
    }
  }

  return -1;
}

// カーソル位置と退避位置の2本の武器を入れ替えるアニメを仕込む
void FUN_080b6ca8(Warehouse* p) {
  WorldPos a[2];
  WorldPos b[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];
  s32 i;

  for (i = 0; i < 2; i++) {
    s32 slot = (i == 0) ? (u8)p->cursor.savedSlot : (u8)p->cursor.slot;
    s32 r;
    s32 id;

    p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
    r = Warehouse_FindRegisteredSlot(p, slot);
    if (r >= 0) {
      p->sprites[r + 40].flags |= SPRFLAG_HIDDEN;
    }

    id = GetWeaponID(p->unk_1458[slot]);
    if (id > 0) {
      unk1[i] = 1;
    } else {
      unk1[i] = 0;
    }

    anims[i] = id;
    strIDs[i] = 0x2DF;
    Shop_GetSlotPos(&a[i].x, slot);
  }

  for (i = 0; i < 2; i++) {
    b[i] = a[1 - i];
  }

  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// 預けた武器を金庫側へ飛ばす演出を仕込む
void FUN_080b6dc4(Warehouse* p) {
  WorldPos a[2];
  WorldPos b[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  p->sprites[(u8)p->cursor.savedSlot + 3].flags |= SPRFLAG_HIDDEN;
  anims[0] = GetWeaponID(p->unk_1458[(u8)p->cursor.savedSlot]);
  strIDs[0] = 0x2DF;
  Shop_GetSlotPos(&a[0].x, (u8)p->cursor.savedSlot);
  Shop_GetSlotPos(&b[0].x, 32);
  unk1[1] = 0;
  anims[1] = 0;
  strIDs[1] = 0x2DF;
  VEC3_SET(a[1], 0, 0, 0);
  VEC3_SET(b[1], 0, 0, 0);
  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// 退避位置に武器がない分岐は ok を使わない (原典もその分岐で FUN_080b98c0 を呼ばない)
// 残差は ok=1 の置き場所と 0x1413/0x1412 の選択の合流位置, レジスタ r1/r2 の入れ替わり (114/113命令)
NON_MATCH void FUN_080b6e70(Warehouse* p, s32 param_2) {
#ifdef NONMATCHING_C
  s32 ok;

  if (param_2 == 0) {
    if (p->cursor.shopColX == 8) {
      FUN_080b98c0(&p->pair1.gfx, 0, 4);
    } else {
      FUN_080b98c0(&p->pair1.gfx, 0, -1);
    }
    return;
  }

  if (GetWeaponID(p->unk_1458[(u8)p->cursor.savedSlot]) == 0) {
    if (GetWeaponID(p->unk_1458[(u8)p->cursor.slot]) == 0) {
      ok = 0;
    } else if (Warehouse_FindRegisteredSlot(p, (u8)p->cursor.slot) < 0) {
      ok = 1;
    } else {
      ok = 1;
      if (p->cursor.savedShopColX > 3) {
        ok = 0;
      }
    }
  } else {
    if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
      if (FUN_080b9da0(&p->cursor, 2)) {
        ok = 0;
      } else {
        ok = ((u8)p->cursor.slot < 16 ? p->unk_1413 : p->unk_1412) >= 0;
      }
    } else if (Warehouse_FindRegisteredSlot(p, (u8)p->cursor.slot) >= 0) {
      ok = 1;
      if (p->cursor.savedShopColX > 3) {
        ok = 0;
      }
    } else if (Warehouse_FindRegisteredSlot(p, (u8)p->cursor.savedSlot) >= 0) {
      ok = 1;
      if (p->cursor.shopColX > 3) {
        ok = 0;
      }
    } else {
      ok = 1;
    }

    if (ok == 1) {
      FUN_080b98c0(&p->pair1.gfx, 3, -1);
    } else {
      FUN_080b98c0(&p->pair1.gfx, -1, -1);
    }
  }
#else
  INCFUNC("asm/func/FUN_080b6e70.inc");
#endif
}

// 退避中の武器をカーソル位置へ置けるか判定する, 0: 不可 1: 可 2: スロット32 の上
s32 FUN_080b6fa4(Warehouse* p) {
  if (GetWeaponID(p->unk_1458[(u8)p->cursor.savedSlot]) == 0) {
    if (GetWeaponID(p->unk_1458[(u8)p->cursor.slot]) == 0) {
      return 0;
    }
    if (Warehouse_FindRegisteredSlot(p, (u8)p->cursor.slot) < 0) {
      return 1;
    }
    if (p->cursor.savedShopColX > 3) {
      return 0;
    }
    return 1;
  }

  if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    if (FUN_080b9da0(&p->cursor, 2)) {
      return 0;
    }
    if ((u8)p->cursor.slot < 16) {
      if (p->unk_1413 < 0) {
        return 0;
      }
      p->cursor.shopColX = p->unk_1413 & 3;
      p->cursor.shopRowY = (p->unk_1413 - 16) >> 2;
      p->cursor.slot = p->unk_1413;
      return 1;
    }

    if (p->unk_1412 < 0) {
      return 0;
    }
    p->cursor.shopColX = ((p->unk_1412 - 16) & 3) + 4;
    p->cursor.shopRowY = (p->unk_1412 - 16) >> 2;
    p->cursor.slot = p->unk_1412;
    return 1;
  }

  if ((u8)p->cursor.slot == 32) {
    return 2;
  }
  if (Warehouse_FindRegisteredSlot(p, (u8)p->cursor.slot) >= 0) {
    if (p->cursor.savedShopColX > 3) {
      return 0;
    }
    return 1;
  }
  if (Warehouse_FindRegisteredSlot(p, (u8)p->cursor.savedSlot) >= 0 && p->cursor.shopColX > 3) {
    return 0;
  }
  return 1;
}

void FUN_080b70ac(Warehouse* p) {
  p->sprites[45].flags |= SPRFLAG_HIDDEN;
  p->sprites[44].flags &= ~SPRFLAG_HIDDEN;
  FUN_080b6a74(p);
  FUN_080b9fe8(&p->cursor);
  ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
  FUN_080b9d94(&p->cursor, 4);
  FUN_080b69b8(p);
  FUN_080b6e70(p, 0);
  Warehouse_SetSubState(p, FUN_080b7118, 1);
}

// 武器の一覧画面の入力待ち, SELECT+A でタブ切り替え, A で整理/全部預ける/入れ替え元の選択
void FUN_080b7118(Warehouse* p) {
  FUN_080b95d0(&p->cursor, &p->sprites[35], &p->sprites[37], &p->sprites[38]);

  if (FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
  }

  MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);

  if (gInput[0].down & SELECT_BUTTON) {
    FUN_080b5ac8(p, 0);
    MainSprite_SetPose(&p->sprites[44], &p->gfx0, 56, PLAYMODE_LOOP);
    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_CURSOR_MOVE);
      p->kind++;
      if (p->kind > 2) {
        p->kind = 0;
      }
    }
  } else {
    FUN_080b5ac8(p, 1);
    MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);

    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_SELECT);
      if ((u8)p->cursor.slot == 33) {
        PlaySound_082406e0(SE_SELECT);
        FUN_080b9fd8(&p->cursor);
        Warehouse_ShowMessage(p, 3, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 1);
        FUN_080b98c0(&p->pair1.gfx, -1, -1);
        Warehouse_SetSubState(p, FUN_080b7670, 0);
      } else if ((u8)p->cursor.slot == 34) {
        PlaySound_082406e0(SE_SELECT);
        FUN_080b9fd8(&p->cursor);
        Warehouse_ShowMessage(p, 4, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 1);
        FUN_080b98c0(&p->pair1.gfx, -1, -1);
        Warehouse_SetSubState(p, FUN_080b76dc, 0);
      } else {
        weapon32_t id;

        FUN_080b9fd8(&p->cursor);
        p->sprites[45].flags &= ~SPRFLAG_HIDDEN;
        p->sprites[45].pos = p->sprites[44].pos;
        id = GetWeaponID(p->unk_1458[(u8)p->cursor.savedSlot]);
        if (id > 0) {
          if (Warehouse_FindRegisteredSlot(p, (u8)p->cursor.savedSlot) >= 0) {
            FUN_080b9d94(&p->cursor, 30);
          } else if ((id >= WEAPON_BROKEN_GUN && id <= WEAPON_MEGA_BUSTER) || id == WEAPON_ASTRO_SWORD || id == WEAPON_ASTRO_SPEAR || id == WEAPON_ASTRO_HAMMER) {
            FUN_080b9d94(&p->cursor, 28);
          } else {
            FUN_080b9d94(&p->cursor, 24);
          }
        } else {
          FUN_080b9d94(&p->cursor, 28);
        }
        FUN_080b6e70(p, 1);
        Warehouse_SetSubState(p, FUN_080b73b8, 0);
      }
    } else if (ShopCursor_Move(&p->cursor)) {
      ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
      FUN_080b69b8(p);
      FUN_080b6e70(p, 0);
    }
  }
}

// 武器の一覧の入力待ち, SELECT で整理の確認へ, A で入れ替え, B で戻る
void FUN_080b73b8(Warehouse* p) {
  FUN_080b95d0(&p->cursor, &p->sprites[35], &p->sprites[37], &p->sprites[38]);

  if (FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags |= SPRFLAG_HIDDEN;
  } else {
    if (p->stateTimer < 30) {
      p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->sprites[36].flags |= SPRFLAG_HIDDEN;
    }
    if (++p->stateTimer >= 60) {
      p->stateTimer = 0;
    }
  }

  MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);

  if ((gInput[0].pressed & SELECT_BUTTON) && !FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
    Shop_GetSlotPos(&p->sprites[44].pos.x, 32);
    MainSprite_SetPose(&p->sprites[44], &p->gfx0, 56, PLAYMODE_LOOP);
    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    PlaySound_082406e0(SE_CHOICE);
    Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
    FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
    Warehouse_SetSubState(p, FUN_080b7794, 0);
  } else if (gInput[0].pressed & A_BUTTON) {
    s32 r = FUN_080b6fa4(p);

    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    switch (r) {
      case 1: {
        FUN_080b6ca8(p);
        Warehouse_SetSubState(p, FUN_080b7750, 0);
        break;
      }
      case 2: {
        Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
        Warehouse_SetSubState(p, FUN_080b7794, 0);
        break;
      }
      default: {
        PlaySound_082406e0(SE_NG);
        break;
      }
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b70ac(p);
  } else if (ShopCursor_Move(&p->cursor)) {
    ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
    FUN_080b69b8(p);
    FUN_080b6e70(p, 1);
  }
}

// 武器の預け入れの確認, A で個数の入力へ, B で選択へ戻る
void FUN_080b75a0(Warehouse* p) {
  MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);
  p->sprites[36].flags |= SPRFLAG_HIDDEN;
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_DRUMROLL);
    ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
    FUN_080b69b8(p);
    Warehouse_SetSubState(p, FUN_080b73b8, 0);
  } else if (gInput[0].pressed & A_BUTTON) {
    p->sprites[44].flags |= SPRFLAG_HIDDEN;
    p->sprites[39].flags |= SPRFLAG_HIDDEN;
    PlaySound_082406e0(SE_CHOICE);
    Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
    FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
    Warehouse_SetSubState(p, FUN_080b7794, 0);
  }
}

void FUN_080b7670(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortWeapons(0);
    p->cursor.savedShopColX = 0;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 0;
    FUN_080b70ac(p);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b70ac(p);
  }
}

void FUN_080b76dc(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortWeapons(p->unk_1458[16]);
    p->cursor.savedShopColX = 4;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 16;
    FUN_080b70ac(p);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
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
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b70ac(p);
  }
}

void FUN_080b77f4(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    RemoveWeapon(p->unk_1458[(u8)p->cursor.savedSlot]);
    PlaySound_082406e0(SE_TRASH);
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
  ShopCursor_Init(&p->cursor, 0, 0, 0, 4);
  ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
  FUN_080b69b8(p);
  FUN_080b6e70(p, 0);
  Warehouse_SetSubState(p, FUN_080b7118, 1);
}

// カーソルの防具の見た目と説明を出す, 防具がなければ消す
void FUN_080b7900(Warehouse* p) {
  s32 armor;

  if (p->cursor.shopColX < 8) {
    armor = ARMORS(p->unk_1458[(u8)p->cursor.slot]);
  } else {
    armor = -1;
  }

  if (armor < 0) {
    p->sprites[39].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    p->sprites[39].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[39], &p->icons, 207, PLAYMODE_LOOP);
    MessageWindow_Start(p->unk_13fc);
    MessageWindow_SetRect(2, 16, 28, 2);
    Marquee_SetVarValue(0, gArmorDB[armor].defence);
    Marquee_SetVarValue(1, gArmorDB[armor].weight);
    MessageWindow_SetInstant(1);
    MessageWindow_ShowLine(armor);
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->unk_13fc) + (37 + armor)));
  }
}

// FUN_080b5cac の防具版で残差も同じ, 2つ目のループの j が逆順カウントに変換される (258/257命令)
NON_MATCH void FUN_080b79d8(Warehouse* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  p->unk_1412 = -1;
  p->unk_1413 = -1;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      s32 slot = i * 4 + j;
      s32 id = ARMORS(p->unk_1458[slot]);

      if (id >= 0) {
        p->sprites[slot + 3].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[slot + 3], &p->icons, id + 0x43, PLAYMODE_LOOP);
      } else {
        if (p->unk_1412 < 0) {
          p->unk_1412 = slot;
        }
        p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
      }

      if (slot == gStat->armor) {
        FUN_080b95bc(&p->sprites[slot + 3], 736);
      } else {
        FUN_080b95bc(&p->sprites[slot + 3], 735);
      }
    }
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      s32 slot = 16 + i * 4 + j;
      s32 id = ARMORS(p->unk_1458[slot]);

      if (id >= 0) {
        p->sprites[slot + 3].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[slot + 3], &p->icons, id + 0x43, PLAYMODE_LOOP);
      } else {
        if (p->unk_1413 < 0) {
          p->unk_1413 = slot;
        }
        p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
      }
    }
  }

  if (gStat->armor >= 0) {
    p->sprites[40].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[40].pos.x = (gStat->armor & 3) * 24 + 144;
    p->sprites[40].pos.y = (gStat->armor >> 2) * 24 + 32;
  } else {
    p->sprites[40].flags |= SPRFLAG_HIDDEN;
  }

  for (i = 0; i < 3; i++) {
    p->sprites[41 + i].flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_080b79d8.inc");
#endif
}

// FUN_080b6e70 の防具版, 退避位置に防具がない分岐は ok を使わない (原典もその分岐で FUN_080b98c0 を呼ばない)
// 残差は ok=1 が前に出て列判定の末尾が共有されないことと, 0x1413/0x1412 の読み込みが ldrsb になること (130/130命令)
NON_MATCH void FUN_080b7c18(Warehouse* p, s32 param_2) {
#ifdef NONMATCHING_C
  s32 saved;
  s32 ok;

  if (param_2 == 0) {
    if (p->cursor.shopColX == 8) {
      FUN_080b98c0(&p->pair1.gfx, 0, 4);
    } else {
      FUN_080b98c0(&p->pair1.gfx, 0, -1);
    }
    return;
  }

  saved = p->unk_1458[(u8)p->cursor.savedSlot];
  if (ARMORS(saved) < 0) {
    s32 slot = p->unk_1458[(u8)p->cursor.slot];

    if (ARMORS(slot) < 0) {
      ok = 0;
    } else if (slot != gStat->armor) {
      ok = 1;
    } else {
      ok = p->cursor.savedShopColX <= 3;
    }
  } else {
    if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
      if (FUN_080b9da0(&p->cursor, 2)) {
        ok = 0;
      } else {
        ok = ((u8)p->cursor.slot < 16 ? p->unk_1413 : p->unk_1412) >= 0;
      }
    } else if (p->unk_1458[(u8)p->cursor.slot] == gStat->armor) {
      ok = 1;
      if (p->cursor.savedShopColX > 3) {
        ok = 0;
      }
    } else if (saved == gStat->armor) {
      ok = 1;
      if (p->cursor.shopColX > 3) {
        ok = 0;
      }
    } else {
      ok = 1;
    }

    if (ok == 1) {
      FUN_080b98c0(&p->pair1.gfx, 3, -1);
    } else {
      FUN_080b98c0(&p->pair1.gfx, -1, -1);
    }
  }
#else
  INCFUNC("asm/func/FUN_080b7c18.inc");
#endif
}

// 退避中の防具をカーソル位置へ置けるか判定する, 0: 不可 1: 可 2: スロット32 の上
s32 FUN_080b7d68(Warehouse* p) {
  s32 saved = p->unk_1458[(u8)p->cursor.savedSlot];

  if (ARMORS(saved) < 0) {
    s32 slot = p->unk_1458[(u8)p->cursor.slot];

    if (ARMORS(slot) < 0) {
      return 0;
    }
    if (slot != gStat->armor) {
      return 1;
    }
    if (p->cursor.savedShopColX > 3) {
      return 0;
    }
    return 1;
  }

  if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    if (FUN_080b9da0(&p->cursor, 2)) {
      return 0;
    }
    if ((u8)p->cursor.slot < 16) {
      if (p->unk_1413 < 0) {
        return 0;
      }
      p->cursor.shopColX = p->unk_1413 & 3;
      p->cursor.shopRowY = (p->unk_1413 - 16) >> 2;
      p->cursor.slot = p->unk_1413;
      return 1;
    }

    if (p->unk_1412 < 0) {
      return 0;
    }
    p->cursor.shopColX = ((p->unk_1412 - 16) & 3) + 4;
    p->cursor.shopRowY = (p->unk_1412 - 16) >> 2;
    p->cursor.slot = p->unk_1412;
    return 1;
  }

  if ((u8)p->cursor.slot == 32) {
    return 2;
  }
  if (p->unk_1458[(u8)p->cursor.slot] == gStat->armor) {
    if (p->cursor.savedShopColX > 3) {
      return 0;
    }
    return 1;
  }
  if (saved == gStat->armor && p->cursor.shopColX > 3) {
    return 0;
  }
  return 1;
}

// カーソル位置と退避位置の防具を入れ替える (装備中なら装備スロットも追従)
void FUN_080b7e8c(Warehouse* p) {
  s32 a = p->unk_1458[(u8)p->cursor.slot];
  s32 b = p->unk_1458[(u8)p->cursor.savedSlot];
  s32 tmp = ARMORS(a);

  ARMORS(a) = ARMORS(b);
  ARMORS(b) = tmp;

  if ((s16)gStat->armor == a) {
    gStat->armor = b;
  } else if ((s16)gStat->armor == b) {
    gStat->armor = a;
  }
}

// 退避位置の防具を取り除く
void FUN_080b7ef0(Warehouse* p) { ARMORS(p->unk_1458[(u8)p->cursor.savedSlot]) = -1; }

// カーソル位置と退避位置の2枚の防具を入れ替えるアニメを仕込む
void FUN_080b7f20(Warehouse* p) {
  WorldPos a[2];
  WorldPos b[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];
  s32 i;

  for (i = 0; i < 2; i++) {
    s32 slot = (i == 0) ? (u8)p->cursor.savedSlot : (u8)p->cursor.slot;
    s32 id;

    p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
    if (gStat->armor == p->unk_1458[slot]) {
      p->sprites[40].flags |= SPRFLAG_HIDDEN;
    }

    id = ARMORS(p->unk_1458[slot]);
    if (id >= 0) {
      unk1[i] = 1;
    } else {
      unk1[i] = 0;
    }

    anims[i] = id + 0x43;
    strIDs[i] = 0x2DF;
    Shop_GetSlotPos(&a[i].x, slot);
  }

  for (i = 0; i < 2; i++) {
    b[i] = a[1 - i];
  }

  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// 預けた防具を金庫側へ飛ばす演出を仕込む
void FUN_080b8044(Warehouse* p) {
  WorldPos a[2];
  WorldPos b[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  p->sprites[(u8)p->cursor.savedSlot + 3].flags |= SPRFLAG_HIDDEN;
  anims[0] = ARMORS(p->unk_1458[(u8)p->cursor.savedSlot]) + 0x43;
  strIDs[0] = 0x2DF;
  Shop_GetSlotPos(&a[0].x, (u8)p->cursor.savedSlot);
  Shop_GetSlotPos(&b[0].x, 32);
  unk1[1] = 0;
  anims[1] = 0x43;
  strIDs[1] = 0x2DF;
  VEC3_SET(a[1], 0, 0, 0);
  VEC3_SET(b[1], 0, 0, 0);
  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

void FUN_080b8104(Warehouse* p) {
  p->sprites[45].flags |= SPRFLAG_HIDDEN;
  p->sprites[44].flags &= ~SPRFLAG_HIDDEN;
  FUN_080b79d8(p);
  FUN_080b9fe8(&p->cursor);
  ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
  FUN_080b9d94(&p->cursor, 4);
  FUN_080b7900(p);
  FUN_080b7c18(p, 0);
  Warehouse_SetSubState(p, FUN_080b8170, 1);
}

// 防具の一覧画面の入力待ち, SELECT+A でタブ切り替え, A で整理/全部預ける/入れ替え元の選択
void FUN_080b8170(Warehouse* p) {
  FUN_080b95d0(&p->cursor, &p->sprites[35], &p->sprites[37], &p->sprites[38]);

  if (FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
  }

  if (gInput[0].down & SELECT_BUTTON) {
    FUN_080b5ac8(p, 0);
    MainSprite_SetPose(&p->sprites[44], &p->gfx0, 56, PLAYMODE_LOOP);
    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_CURSOR_MOVE);
      p->kind++;
      if (p->kind > 2) {
        p->kind = 0;
      }
    }
  } else {
    FUN_080b5ac8(p, 1);
    MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);

    if (gInput[0].pressed & A_BUTTON) {
      if ((u8)p->cursor.slot == 33) {
        PlaySound_082406e0(SE_SELECT);
        FUN_080b9fd8(&p->cursor);
        Warehouse_ShowMessage(p, 3, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 1);
        FUN_080b98c0(&p->pair1.gfx, -1, -1);
        Warehouse_SetSubState(p, FUN_080b86bc, 0);
      } else if ((u8)p->cursor.slot == 34) {
        PlaySound_082406e0(SE_SELECT);
        FUN_080b9fd8(&p->cursor);
        Warehouse_ShowMessage(p, 4, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 1);
        FUN_080b98c0(&p->pair1.gfx, -1, -1);
        Warehouse_SetSubState(p, FUN_080b8728, 0);
      } else {
        s32 idx;

        PlaySound_082406e0(SE_SELECT);
        FUN_080b9fd8(&p->cursor);
        p->sprites[45].flags &= ~SPRFLAG_HIDDEN;
        p->sprites[45].pos = p->sprites[44].pos;
        idx = p->unk_1458[(u8)p->cursor.savedSlot];
        if (ARMORS(idx) >= 0) {
          if (idx == gStat->armor) {
            FUN_080b9d94(&p->cursor, 30);
          } else {
            FUN_080b9d94(&p->cursor, 24);
          }
        } else {
          FUN_080b9d94(&p->cursor, 28);
        }
        FUN_080b7c18(p, 1);
        Warehouse_SetSubState(p, FUN_080b8404, 0);
      }
    } else if (ShopCursor_Move(&p->cursor)) {
      ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
      FUN_080b7900(p);
      FUN_080b7c18(p, 0);
    }
  }
}

// 防具の一覧の入力待ち, SELECT で整理の確認へ, A で入れ替え, B で戻る
void FUN_080b8404(Warehouse* p) {
  FUN_080b95d0(&p->cursor, &p->sprites[35], &p->sprites[37], &p->sprites[38]);

  if (FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags |= SPRFLAG_HIDDEN;
  } else {
    if (p->stateTimer < 30) {
      p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->sprites[36].flags |= SPRFLAG_HIDDEN;
    }
    if (++p->stateTimer >= 60) {
      p->stateTimer = 0;
    }
  }

  MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);

  if ((gInput[0].pressed & SELECT_BUTTON) && !FUN_080b9da0(&p->cursor, 4)) {
    p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
    Shop_GetSlotPos(&p->sprites[44].pos.x, 32);
    MainSprite_SetPose(&p->sprites[44], &p->gfx0, 56, PLAYMODE_LOOP);
    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    PlaySound_082406e0(SE_CHOICE);
    Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
    FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
    Warehouse_SetSubState(p, FUN_080b87c4, 0);
  } else if (gInput[0].pressed & A_BUTTON) {
    s32 r = FUN_080b7d68(p);

    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    switch (r) {
      case 1: {
        FUN_080b7f20(p);
        Warehouse_SetSubState(p, FUN_080b879c, 0);
        break;
      }
      case 2: {
        Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
        FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
        Warehouse_SetSubState(p, FUN_080b87c4, 0);
        break;
      }
      default: {
        PlaySound_082406e0(SE_NG);
        break;
      }
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b8104(p);
  } else if (ShopCursor_Move(&p->cursor)) {
    ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
    FUN_080b7900(p);
    FUN_080b7c18(p, 1);
  }
}

// 防具の選択後の確認, A で確認ウィンドウへ, B で選択へ戻る
void FUN_080b85ec(Warehouse* p) {
  MainSprite_AdvanceAnim(&p->sprites[44], &p->gfx0);
  p->sprites[36].flags |= SPRFLAG_HIDDEN;
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_DRUMROLL);
    ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
    FUN_080b7900(p);
    Warehouse_SetSubState(p, FUN_080b8404, 0);
  } else if (gInput[0].pressed & A_BUTTON) {
    p->sprites[44].flags |= SPRFLAG_HIDDEN;
    p->sprites[39].flags |= SPRFLAG_HIDDEN;
    PlaySound_082406e0(SE_CHOICE);
    Warehouse_ShowMessage(p, 2, p->unk_13f4, -1);
    FUN_080b9740(&p->sprites[46], &p->gfx0, (char*)&p->unk_140d, 0);
    Warehouse_SetSubState(p, FUN_080b87c4, 0);
  }
}

void FUN_080b86bc(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortArmors(0);
    p->cursor.savedShopColX = 0;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 0;
    FUN_080b8104(p);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b8104(p);
  }
}

void FUN_080b8728(Warehouse* p) {
  s32 r = FUN_080b977c(&p->sprites[46], &p->gfx0, &p->unk_140d);

  if (r == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortArmors(p->unk_1458[16]);
    p->cursor.savedShopColX = 4;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 16;
    FUN_080b8104(p);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
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
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b8104(p);
  }
}

void FUN_080b8824(Warehouse* p) {
  if (FUN_080b9adc(&p->pair0)) {
    FUN_080b7ef0(p);
    PlaySound_082406e0(SE_TRASH);
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
  ShopCursor_Init(&p->cursor, 0, 0, 0, 4);
  ShopCursor_PlaceSprite(&p->cursor, &p->sprites[44]);
  FUN_080b7900(p);
  FUN_080b7c18(p, 0);
  Warehouse_SetSubState(p, FUN_080b8170, 1);
}

// VM の名前付き引数からタブの種類を読み, タブごとの見出しタイルを決める
void FUN_080b8920(Warehouse* p) {
  s32 i;

  p->unk_1410 = 0;
  if (!VM_SeekToNamedArg('n')) {
    return;
  }
  p->count = VM_GetValue();

  if (!VM_SeekToNamedArg('l')) {
    return;
  }
  for (i = 0; i < p->count; i++) {
    p->kinds[i] = VM_GetValue();
  }

  for (i = 0; i < p->count; i++) {
    switch (p->kinds[i]) {
      case 0: {
        p->unk_1419[i] = 'P';
        p->unk_141e[i] = 3;
        p->unk_1423[i] = 44;
        break;
      }
      case 1: {
        p->unk_1419[i] = 'P';
        p->unk_141e[i] = 3;
        p->unk_1423[i] = 45;
        break;
      }
      case 2: {
        p->unk_1419[i] = 'Z';
        p->unk_141e[i] = 5;
        p->unk_1423[i] = 44;
        break;
      }
      case 3: {
        p->unk_1419[i] = 'Z';
        p->unk_141e[i] = 5;
        p->unk_1423[i] = 45;
        break;
      }
      case 4: {
        p->unk_1419[i] = 'S';
        p->unk_141e[i] = 7;
        p->unk_1423[i] = 16;
        break;
      }
      default: {
        return;
      }
    }
  }

  if (VM_SeekToNamedArg('e')) {
    p->unk_1490 = VM_GetValue();
  } else {
    p->unk_1490 = 0;
  }
}

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

// 画面のスプライトを全部登録する
// 残差は最初の MainSprite_Add の引数 0 を pos 初期化の 0 と共有してしまう1命令だけ (343/344命令), shop_weapon.c の FUN_080be204 と同じ
NON_MATCH void FUN_080b8b60(Warehouse* p) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* f;
  Vec3 pos;
  s32 i;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  p->icons = *f;
  OpenMainSpriteFile(&p->icons, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  p->gfx0 = *f;
  OpenMainSpriteFile(&p->gfx0, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_MISC);
  p->gfx2 = *f;
  OpenMainSpriteFile(&p->gfx2, f);

  pos.x = 0, pos.y = 0, pos.z = 0;
  MainSprite_Add(&p->sprites[0], &p->gfx2, 40, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[1], &p->gfx2, 35, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[2], &p->gfx2, 36, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  for (i = 0; i < 16; i++) {
    pos.y = (i >> 2) * 24 + 32;
    pos.x = (i & 3) * 24 + 144;
    MainSprite_Add(&p->sprites[3 + i], &p->icons, 104, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x = (i & 3) * 24 + 8;
    MainSprite_Add(&p->sprites[19 + i], &p->icons, 104, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  }

  pos.x = 0;
  pos.y = 128;
  MainSprite_Add(&p->sprites[33], &p->icons, ICON_TIMER_NONE, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 112;
  pos.y = 64;
  MainSprite_Add(&p->sprites[35], &p->icons, ICON_TRASH, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  FUN_080b95bc(&p->sprites[35], 736);

  pos.x = 0;
  pos.y = 0;
  MainSprite_Add(&p->sprites[36], &p->gfx2, 42, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 120;
  pos.y = 104;
  MainSprite_Add(&p->sprites[37], &p->icons, ICON_SORT, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 104;
  pos.y = 32;
  MainSprite_Add(&p->sprites[38], &p->icons, ICON_SORT, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 144;
  pos.y = 0;
  for (i = 0; i < 4; i++) {
    pos.y = i * 24 + 32;
    MainSprite_Add(&p->sprites[40 + i], &p->gfx0, SMENU_EQUIP_E, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  }

  MainSprite_Add(&p->sprites[45], &p->gfx0, SMENU_SELECTED, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 144;
  pos.y = 32;
  MainSprite_Add(&p->sprites[44], &p->gfx0, SMENU_CURSOR(1), SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetAnim(&p->sprites[44], &p->gfx0, 0, PLAYMODE_LOOP, 0);

  pos.x = 0;
  pos.y = 0;
  MainSprite_Add(&p->sprites[46], &p->gfx0, SMENU_YESNO(0), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);

  FUN_080b99a0(&p->pair0);
  FUN_080b9814(&p->pair1);
#else
  INCFUNC("asm/func/FUN_080b8b60.inc");
#endif
}

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

// 見出し行の文字タイルを BG0 の (18, 3) から並べる
void FUN_080b8fa4(Warehouse* p) {
  BgMapEntry* tm = FUN_080b5b30(0, 18, 3);
  s32 i, j;

  for (i = 0; i < p->unk_141e[p->unk_1410]; i++) {
    *tm++ = (p->unk_1419[p->unk_1410] + i) | 0xF000;
  }
  for (j = 0; j < 3; i++, j++) {
    *tm++ = (j + 0x60) | 0xF000;
  }
  for (; i < 10; i++) {
    *tm++ = 0xF010;
  }
}

// 見出し行の文字タイルを BG0 の (1, 3) から並べる
void FUN_080b9030(Warehouse* p) {
  BgMapEntry* tm = FUN_080b5b30(0, 1, 3);
  s32 i, j;

  for (i = 0; i < p->unk_141e[p->unk_1410]; i++) {
    *tm++ = (p->unk_1419[p->unk_1410] + i) | 0xF000;
  }
  for (j = 0; j < 3; i++, j++) {
    *tm++ = (j + 0x1D) | 0xF000;
  }
  *tm++ = p->unk_1423[p->unk_1410] | 0xF000;
  for (i++; i < 11; i++) {
    *tm++ = 0xF010;
  }
}

// 倉庫のメイン状態, L/R でタブを切り替え, B で閉じ, それ以外は現在のサブ状態を進める
void FUN_080b90dc(Warehouse* p) {
  if (p->unk_140c != 0) {
    if ((++p->unk_1479 >> 5) & 1) {
      p->sprites[1].flags |= SPRFLAG_HIDDEN;
      p->sprites[2].flags |= SPRFLAG_HIDDEN;
    } else {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
    }

    if (Warehouse_HandleTabInput(p)) {
      PlaySound_082406e0(SE_MENU_PAGE);
      switch (p->kinds[p->unk_1410]) {
        case 0: {
          FUN_080b695c(p, 0);
          break;
        }
        case 1: {
          FUN_080b695c(p, 16);
          break;
        }
        case 2: {
          FUN_080b78a4(p, 0);
          break;
        }
        case 3: {
          FUN_080b78a4(p, 16);
          break;
        }
        case 4: {
          FUN_080b88c4(p, 0);
          break;
        }
      }
      FUN_080b8fa4(p);
      FUN_080b9030(p);
    } else if (gInput[0].pressed & B_BUTTON) {
      PlaySound_082406e0(SE_CLOSE_MENU);
      FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
      Warehouse_SetState(p, FUN_080b9248);
      return;
    }
  } else {
    p->sprites[1].flags |= SPRFLAG_HIDDEN;
    p->sprites[2].flags |= SPRFLAG_HIDDEN;
    p->unk_1479 = 0;
  }

  p->unk_1498(p);
}

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
  PlaySound_082406e0(SE_OPEN_MENU);
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
