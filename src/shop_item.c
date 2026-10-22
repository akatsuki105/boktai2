#include "armor.h"
#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "inventory.h"
#include "item.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

#define SPECIAL_COL 8  // 追加UI(整頓 or 売る)
#define SLOT_SORT 0x21
#define SLOT_SELL 0x22

struct ItemShop;
typedef void(ItemShopFunc)(struct ItemShop*);

// 果実屋(リタ) と 道具屋(キッド) のショップメニュー
typedef struct ItemShop {
  Entity e;                      // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;            // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx icons;           // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;            // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[49];        // 0x0078, [35] がカーソル
  Tilemaps* tilemap;             // 0x12D8, TILEMAP_9F57
  rgb555* bgPltt;                // 0x12DC, BGP_A41A[208]
  u8* unk_12e0;                  // 0x12E0, '.s' があれば VM_GetPC_Proxy の戻り値
  u8* unk_12e4;                  // 0x12E4, '.i' があれば VM_GetPC_Proxy の戻り値
  u8* unk_12e8;                  // 0x12E8, '.a' があれば VM_GetPC_Proxy の戻り値
  s8 unk_12ec;                   // 0x12EC, _Init の第2引数, 1 なら items1 も読む (RitaShop_Create は 0, KidShop_Create は 1)
  u8 unk_12ed;                   // 0x12ED, FUN_080bb160 が 0 を入れる
  u8 unk_12ee;                   // 0x12EE, FUN_080ba048 が FUN_080ba054 の第3引数を入れる
  u8 unk_12ef;                   // 0x12EF, FUN_080baae8 などが読む
  u16 stateTimer;                // 0x12F0, ItemShop_SetState が差し替えのたびに 0 に戻す
  u16 unk_12f2;                  // 0x12F2, FUN_080baa40 の戻り値
  s8 items0[16];                 // 0x12F4, '.I' の個数だけ '.T' から読んで残りは -1. [12..15] には [8..11] の写し
  s8 items1[16];                 // 0x1304, '.A' の個数だけ '.R' から読んで残りは -1. [12..15] には [8..11] の写し
  ShopSpritePair pair0;          // 0x1314, _Destroy が FUN_080b9a0c に渡す
  u8 unk_13f4[0x1408 - 0x13F4];  // 0x13F4, まだ未解析
  ShopCursor cursor;             // 0x1408, ShopCursor_Init(&cursor, 1, 4, 0, 20)
  ShopSpritePair pair1;          // 0x1438, _Destroy が FUN_080b9894 に渡す
  u8 unk_1518[2];                // 0x1518, まだ未解析
  u8 kind;                       // 0x151A, _Update が FUN_080b94cc / FUN_080b9400 に渡す
  u8 unk_151b;                   // 0x151B, _Init が 0 を入れる
  u8 unk_151c;                   // 0x151C, _Init が 0 を入れる
  u8 unk_151d[0x1534 - 0x151D];  // 0x151D, まだ未解析
  u32 unk_1534;                  // 0x1534, '.e' (なければ 0)
  ItemShopFunc* updateCallback;  // 0x1538
  ItemShopFunc* unk_153c;        // 0x153C, FUN_080ba054 が入れる, 読み手は未調査
} ItemShop;
static_assert(sizeof(ItemShop) == 5440);

void FUN_080baae8(ItemShop* p);
s32 FUN_08049e6c(s32 idx, s32 value);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void FUN_080bbc60(ItemShop* p);
void FUN_080bc2d8(ItemShop* p);
s32 FindEmptyArmorSlot(ItemShop* p);
void FUN_080bb0e8(ItemShop* p);
void FUN_080bca7c(ItemShop* p);
u32 Item_GetRotStageIcon(s32 slot);

void ItemShop_SetState(ItemShop* p, ItemShopFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080ba048(ItemShop* p, s32 val) { p->unk_12ee = val; }

void FUN_080ba054(ItemShop* p, ItemShopFunc* fn, s32 val) {
  p->unk_153c = fn;
  FUN_080ba048(p, val);
  p->stateTimer = 0;
}

void FUN_080ba07c(ItemShop* p, s32 line) {
  FUN_08049e5c();
  p->sprites[33].flags |= SPRFLAG_HIDDEN;
  MessageWindow_Start(p->unk_12e0);
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_ShowLine(line);
}

// value を百の位・十の位・一の位に分解する
void SplitDecimal3_080ba0c0(s32 value, s32* digits) {
  digits[0] = Div(value, 100);
  value -= digits[0] * 100;
  digits[1] = Div(value, 10);
  digits[2] = value - digits[1] * 10;
}

NAKED void FUN_080ba0f0(ItemShop* p, s32 param_2) { INCFUNC("asm/func/FUN_080ba0f0.inc"); }

// 道具の買値を返す, 果実系は nutsRate を掛けて 1〜9999 に収める (太陽光に応じて値段が変わる設定)
s32 Item_GetBuyPrice(u32 itemID) {
  if (itemID <= 4 || itemID == 6 || itemID == 7 || itemID == 9 || itemID == 10) {
    s32 price = Div(gItemDB[itemID].price * gStat->nutsRate, 100);

    if (price <= 0) {
      price = 1;
    }
    if (price > 9999) {
      price = 9999;
    }
    return price;
  }

  return gItemDB[itemID].price;
}

// アイテムの売値, 腐敗の段階ごとに買値の 50% から 10% ずつ下げ, 20% を下限にする
s32 FUN_080ba288(s32 slot) {
  u32 stage = Item_GetRotStageIcon(slot);
  s32 pct = 50;
  s32 price;

  if (stage != ICON_TIMER_NONE) {
    pct = 50 - (stage - ICON_TIMER_100) * 10;
    if (pct > 50) {
      pct = 50;
    }
    if (pct < 20) {
      pct = 20;
    }
  }

  price = Div(pct * Item_GetBuyPrice(GetNormalItemID(slot)), 100);
  if (price <= 0) {
    price = 1;
  }
  if (price > 9999) {
    price = 9999;
  }
  return price;
}

// カーソル位置の道具の説明文とアイコンを出す, 対象がなければ説明窓を閉じる
void FUN_080ba2d8(ItemShop* p) {
  s32 id;
  s32 pose;

  if (p->cursor.shopColX <= 3) {
    id = GetNormalItemID((u8)p->cursor.slot);
    pose = Item_GetRotStageIcon((u8)p->cursor.slot);
  } else if (p->cursor.shopColX <= 7) {
    u16 durability;

    id = p->items0[(u8)p->cursor.slot - 16];
    durability = gItemDB[id].durability;
    pose = ICON_TIMER_100;
    if (durability == 0) {
      pose = ICON_TIMER_NONE;
    }
  } else {
    id = -1;
    pose = ICON_TIMER_NONE;
  }

  if (id < 0) {
    p->sprites[33].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    FUN_08049e5c();
  } else {
    s32 base;

    p->sprites[33].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[33], &p->icons, pose, 1);
    MessageWindow_Start(p->unk_12e4);
    MessageWindow_SetRect(2, 16, 28, 2);
    MessageWindow_SetInstant(1);
    MessageWindow_ShowLine(id);
    base = VM_ParseStringRef(p->unk_12e4);
    if (gStat->playerKind == 5) {
      if (id == 1) {
        FUN_08049e30(Textbox_LookupString(base + 0xEA));
        return;
      }
      if (id == 0xD) {
        FUN_08049e30(Textbox_LookupString(base + 0xA9));
        return;
      }
    }

    if (gStat->playerKind == 0 || gStat->playerKind == 5) {
      base += 0x4E;
    } else {
      base += 0x9C;
    }
    FUN_08049e30(Textbox_LookupString(base + id));
  }
}

NAKED void FUN_080ba410(ItemShop* p) { INCFUNC("asm/func/FUN_080ba410.inc"); }

// カーソル位置の道具の値段表示を更新する, 対象がなければ表示を消す
void FUN_080ba57c(ItemShop* p) {
  s32 id;
  s32 price;
  s32 kind;

  if (p->cursor.shopColX <= 3) {
    id = GetNormalItemID((u8)p->cursor.slot);
    if (id >= 0) {
      price = FUN_080ba288((u8)p->cursor.slot);
      kind = 1;
    }
  } else if (p->cursor.shopColX <= 7) {
    id = p->items0[(u8)p->cursor.slot - 16];
    if (id >= 0) {
      price = Item_GetBuyPrice(id);
      kind = 0;
    }
  } else {
    id = -1;
    price = 0;
    kind = 0;
  }

  if (id >= 0) {
    Vec3 pos;

    FUN_080b9938(&pos.x, (u8)p->cursor.slot);
    FUN_080b9658(&p->gfx2, &p->sprites[37], &pos, price, kind);
  } else {
    FUN_080b9724(&p->sprites[37]);
  }
}

// カーソル位置と退避位置の2本の道具を入れ替えるアニメを仕込む
// 残差2命令 (100/102): shop_weapon.c の FUN_080bd47c と同じ残差クラスで, 原典は3本のポインタをスタックに退避するが agbcc は高位レジスタに置く
NON_MATCH void FUN_080ba624(ItemShop* p) {
#ifdef NONMATCHING_C
  WorldPos a[2];
  WorldPos b[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];
  s32* strPtr = strIDs;
  s32* animPtr = anims;
  s32* flagPtr = unk1;
  WorldPos* ap;
  WorldPos* bp;
  s32 i;

  for (i = 0; i < 2; i++) {
    s32 slot = (i == 0) ? (u8)p->cursor.savedSlot : (u8)p->cursor.slot;
    s32 id;

    p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
    id = GetNormalItemID(slot);
    if (id >= 0) {
      *flagPtr = 1;
    } else {
      *flagPtr = 0;
    }

    *animPtr++ = id + 0x68;
    *strPtr++ = 0x2DF;
    FUN_080b9938(&a[i].x, slot);
    flagPtr++;
  }

  bp = b;
  ap = &a[1];
  for (i = 1; i >= 0; i--) {
    *bp++ = *ap--;
  }

  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
#else
  INCFUNC("asm/func/FUN_080ba624.inc");
#endif
}

// 持っている道具を売る演出を仕込む, 元のアイコンを隠して入れ替え先へ飛ばす
void FUN_080ba710(ItemShop* p) {
  s32 unk1[2];
  WorldPos a[2];
  WorldPos b[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  p->sprites[(u8)p->cursor.savedSlot + 3].flags |= SPRFLAG_HIDDEN;
  anims[0] = GetNormalItemID((u8)p->cursor.savedSlot) + 0x68;
  strIDs[0] = 0x2DF;
  FUN_080b9938(&a[0].x, (u8)p->cursor.savedSlot);
  FUN_080b9938(&b[0].x, (u8)p->cursor.slot);
  unk1[1] = 0;
  anims[1] = 0x68;
  strIDs[1] = 0x2DF;
  a[1].x = 0;
  a[1].y = 0;
  a[1].z = 0;
  b[1].x = 0;
  b[1].y = 0;
  b[1].z = 0;
  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// 道具の入れ替え演出を仕込む, 元の位置と入れ替え先の位置をそれぞれ求めて渡す
void FUN_080ba7bc(ItemShop* p) {
  s32 unk1[2];
  WorldPos a[2];
  WorldPos b[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  anims[0] = p->items0[(u8)p->cursor.savedSlot - 16] + 0x68;
  strIDs[0] = 0x2DF;
  FUN_080b9938(&a[0].x, (u8)p->cursor.savedSlot);
  FUN_080b9938(&b[0].x, (u8)p->cursor.slot);
  unk1[1] = 0;
  anims[1] = 0x68;
  strIDs[1] = 0x2DF;
  a[1].x = 0;
  a[1].y = 0;
  a[1].z = 0;
  b[1].x = 0;
  b[1].y = 0;
  b[1].z = 0;
  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// カーソルの状態から操作ガイドの表示種別を決めて反映する
void FUN_080ba85c(ItemShop* p, s32 param_2) {
  s32 kind;

  if (param_2 == 0) {
    if (p->cursor.shopColX == SPECIAL_COL) {
      FUN_080b98c0(&p->pair1.gfx, 0, 4);
    } else {
      FUN_080b98c0(&p->pair1.gfx, 0, -1);
    }
    return;
  }

  kind = 0;
  if (p->cursor.savedShopColX <= 3) {
    if (GetNormalItemID((u8)p->cursor.savedSlot) >= 0) {
      if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
        kind = 5;
      } else if ((u8)p->cursor.slot == SLOT_SELL) {
        kind = 5;
      } else {
        kind = 1;
      }
    } else {
      kind = GetNormalItemID((u8)p->cursor.slot) >= 0;
    }
  } else if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    kind = 4;
  } else if (p->cursor.shopColX <= 3) {
    kind = (GetNormalItemID((u8)p->cursor.slot) < 0) ? 4 : 0;
  }

  switch (kind) {
    case 4: {
      FUN_080b98c0(&p->pair1.gfx, 7, -1);
      break;
    }
    case 5: {
      FUN_080b98c0(&p->pair1.gfx, 6, -1);
      break;
    }
    case 1: {
      FUN_080b98c0(&p->pair1.gfx, 3, -1);
      break;
    }
    default: {
      FUN_080b98c0(&p->pair1.gfx, -1, -1);
      break;
    }
  }
}

// カーソルの入れ替え操作の可否を判定し, 必要ならカーソルを移し替えて種別コードを返す
// 残差0命令 (74/74), レジスタ名だけ違う: 原典は unk_12f2 の値を r1, 定数 3 を r0 に置くが, こちらは逆になる
NON_MATCH s32 FUN_080ba980(ItemShop* p) {
#ifdef NONMATCHING_C
  if (p->cursor.savedShopColX <= 3) {
    if (GetNormalItemID((u8)p->cursor.savedSlot) >= 0) {
      if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
        p->cursor.slot = SLOT_SELL;
        return 5;
      }
      if ((u8)p->cursor.slot == SLOT_SELL) {
        return 5;
      }
      return 1;
    }

    if (GetNormalItemID((u8)p->cursor.slot) < 0) {
      return 0;
    }
    return 1;
  }

  if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    s32 n = p->unk_12f2;

    p->cursor.slot = n;
    p->cursor.shopColX = n & 3;
    p->cursor.shopRowY = (u8)p->cursor.slot >> 2;
    return 4;
  }

  if (p->cursor.shopColX <= 3 && GetNormalItemID((u8)p->cursor.slot) < 0) {
    return 4;
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_080ba980.inc");
#endif
}

// 道具欄の空きスロット番号を返す, 空きがなければ -1 (p は読まない)
s32 FUN_080baa40(ItemShop* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (GetNormalItemID(i) < 0) {
      return i;
    }
  }
  return -1;
}

// 道具リストの選択画面に戻る, カーソルを復帰させて一覧を描き直す
void FUN_080baa64(ItemShop* p) {
  p->sprites[36].flags |= SPRFLAG_HIDDEN;
  p->sprites[35].flags &= ~SPRFLAG_HIDDEN;
  p->unk_12f2 = FUN_080baa40(p);
  FUN_080b9fe8(&p->cursor);
  FUN_080b9fc4(&p->cursor, &p->sprites[35]);
  FUN_080b9d94(&p->cursor, 20);
  FUN_080ba410(p);
  FUN_080ba57c(p);
  FUN_080ba2d8(p);
  FUN_080ba85c(p, 0);
  FUN_080ba054(p, FUN_080baae8, 1);
}

NAKED void FUN_080baae8(ItemShop* p) { INCFUNC("asm/func/FUN_080baae8.inc"); }

NAKED void FUN_080bad30(ItemShop* p) { INCFUNC("asm/func/FUN_080bad30.inc"); }

// 購入の結果に応じて効果音を鳴らし, 決定ならカーソルの退避値を戻してから FUN_080baa64 へ戻る
void FUN_080baeb0(ItemShop* p) {
  s32 ret = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (ret == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortInventory(0);
    p->cursor.savedShopColX = 0;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 0;
    FUN_080baa64(p);
  } else if (ret == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080baa64(p);
  }
}

// 決定されたらカーソルの退避位置と現在位置のアイテムを入れ替える
void ItemShop_SwapSelectedItem(ItemShop* p) {
  if (FUN_080b9adc(&p->pair0)) {
    SwapNormalItem((u8)p->cursor.savedSlot, (u8)p->cursor.slot);
    FUN_080baa64(p);
  }
}

void FUN_080bafa4(ItemShop* p);

// カーソル確定の入力待ち, 決定なら FUN_080bafa4 へ, キャンセルなら SE を鳴らして戻る
void FUN_080baf50(ItemShop* p) {
  s32 r = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080ba7bc(p);
    FUN_080ba054(p, FUN_080bafa4, 0);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080baa64(p);
  }
}

// 購入を確定する, 所持金から買値を引いてカーソル位置のスロットに道具を入れる
void FUN_080bafa4(ItemShop* p) {
  if (FUN_080b9adc(&p->pair0)) {
    s32 slot = (u8)p->cursor.slot;
    s32 idx = (u8)p->cursor.savedSlot - 16;

    gStat->solarBank -= Item_GetBuyPrice(p->items0[idx]);
    SetItem(slot, p->items0[idx]);
    p->unk_151b = 1;
    PlaySound_082406e0(SE_EQUIP);
    FUN_080baa64(p);
  }
}

void FUN_080bb070(ItemShop* p);

// カーソル確定の入力待ち, 決定なら FUN_080bb070 へ, キャンセルなら SE を鳴らして戻る
void FUN_080bb01c(ItemShop* p) {
  s32 r = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080ba710(p);
    FUN_080ba054(p, FUN_080bb070, 0);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080baa64(p);
  }
}

// 売却を確定する, 売値を所持金に足して (9999 で打ち止め) 道具を手放す
// 残差4命令 (39/43): 原典は打ち止めの代入で gStat をプール経由で読み直して &solarBank を組み立て直すが, agbcc は直前のアドレスを使い回す
NON_MATCH void FUN_080bb070(ItemShop* p) {
#ifdef NONMATCHING_C
  if (FUN_080b9adc(&p->pair0)) {
    s32 slot = (u8)p->cursor.savedSlot;

    gStat->solarBank += FUN_080ba288(slot);
    if ((s16)gStat->solarBank > 9999) {
      gStat->solarBank = 9999;
    }
    RemoveItem(slot);
    p->unk_151c = 1;
    FUN_080ba054(p, FUN_080bb0e8, 0);
  }
#else
  INCFUNC("asm/func/FUN_080bb070.inc");
#endif
}

// 売却後の演出, カーソルの絵を少し持ち上げてから元の状態へ戻す
void FUN_080bb0e8(ItemShop* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SONG_630);
  }

  p->stateTimer++;
  if (p->stateTimer <= 11) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[31].pos.y = 32;
    } else {
      p->sprites[31].pos.y = 32 - ((20 - p->stateTimer) >> 3);
    }
  } else if (p->stateTimer <= 15) {
    p->sprites[31].pos.y = 32;
  } else {
    FUN_080baa64(p);
  }
}

// 道具リストの画面を組み立てる, 枠のタイルを直接書き込んでカーソルを初期化する
// 残差3命令 (119/116): 枠タイルの定数 6個を, 原典は 2本のレジスタを交互に増減させて作るが agbcc は1本で +1 ずつ繋ぐ
NON_MATCH void FUN_080bb160(ItemShop* p) {
#ifdef NONMATCHING_C
  BgMapEntry* tm;

  p->unk_12ed = 0;
  p->unk_12f2 = FUN_080baa40(p);
  tm = gBgStates[0].tilemap;
  Video_SetBGLayer(0, p->tilemap, 2);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  tm[114] = 0xF050;
  tm[115] = 0xF051;
  tm[116] = 0xF052;
  tm[117] = 0xF060;
  tm[118] = 0xF061;
  tm[119] = 0xF062;
  tm[120] = 0xF010;
  tm[121] = 0xF010;
  tm[122] = 0xF010;
  tm[123] = 0xF010;
  tm[124] = 0xF010;
  FUN_080b94cc(p->kind);
  FUN_080b9400(p->kind);
  ShopCursor_Init(&p->cursor, 1, 4, 0, 20);
  FUN_080b9fc4(&p->cursor, &p->sprites[35]);
  FUN_080ba410(p);
  FUN_080ba57c(p);
  FUN_080ba2d8(p);
  if (gStat->armor < 0) {
    FUN_080ba0f0(p, -1);
  } else {
    FUN_080ba0f0(p, GetInventoryArmor(gStat->armor));
  }
  FUN_080ba85c(p, 0);
  FUN_080ba054(p, FUN_080baae8, 1);
#else
  INCFUNC("asm/func/FUN_080bb160.inc");
#endif
}

// カーソル位置の防具の説明文と性能値を出す, 対象がなければ説明窓を閉じる
void FUN_080bb294(ItemShop* p) {
  s32 id;

  if (p->cursor.shopColX <= 3) {
    id = ARMORS((u8)p->cursor.slot);
  } else if (p->cursor.shopColX <= 7) {
    id = p->items1[(u8)p->cursor.slot - 16];
  } else {
    id = -1;
  }

  if (id < 0) {
    p->sprites[33].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    FUN_08049e5c();
  } else {
    p->sprites[33].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[33], &p->icons, ICON_TIMER_NONE, 1);
    MessageWindow_Start(p->unk_12e8);
    MessageWindow_SetRect(2, 16, 28, 2);
    FUN_08049e6c(0, gArmorDB[id].defence);
    FUN_08049e6c(1, gArmorDB[id].weight);
    MessageWindow_SetInstant(1);
    MessageWindow_ShowLine(id);
    {
      s32 base = VM_ParseStringRef(p->unk_12e8) + 0x25;

      FUN_08049e30(Textbox_LookupString(base + id));
    }
  }

  FUN_080ba0f0(p, id);
}

NAKED void FUN_080bb388(ItemShop* p) { INCFUNC("asm/func/FUN_080bb388.inc"); }

// カーソル位置の防具の値段表示を更新する, 対象がなければ表示を消す
void FUN_080bb5bc(ItemShop* p) {
  s32 id;
  s32 price;
  s32 kind;

  if (p->cursor.shopColX <= 3) {
    id = ARMORS((u8)p->cursor.slot);
    price = Div(gArmorDB[id].price * 50, 100);
    kind = 1;
  } else if (p->cursor.shopColX <= 7) {
    id = p->items1[(u8)p->cursor.slot - 16];
    price = gArmorDB[id].price;
    kind = 0;
  } else {
    id = -1;
    price = 0;
    kind = 0;
  }

  if (id >= 0 && price > 0) {
    Vec3 pos;

    FUN_080b9938(&pos.x, (u8)p->cursor.slot);
    FUN_080b9658(&p->gfx2, &p->sprites[37], &pos, price, kind);
  } else {
    FUN_080b9724(&p->sprites[37]);
  }
}

// カーソル位置と退避位置の2枚の防具を入れ替えるアニメを仕込む
// 残差0命令 (118/118), 退避先だけ違う: FUN_080ba624 と同じ残差クラスで, 原典は3本のポインタをスタックに置くが agbcc は高位レジスタに置く
NON_MATCH void FUN_080bb688(ItemShop* p) {
#ifdef NONMATCHING_C
  WorldPos a[2];
  WorldPos b[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];
  s32* strPtr = strIDs;
  s32* animPtr = anims;
  s32* flagPtr = unk1;
  WorldPos* ap;
  WorldPos* bp;
  s32 i;

  for (i = 0; i < 2; i++) {
    s32 slot = (i == 0) ? (u8)p->cursor.savedSlot : (u8)p->cursor.slot;
    s32 id;

    p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
    if (slot == gStat->armor) {
      p->sprites[34].flags |= SPRFLAG_HIDDEN;
    }

    id = ARMORS(slot);
    if (id >= 0) {
      *flagPtr = 1;
    } else {
      *flagPtr = 0;
    }

    *animPtr++ = id + 0x43;
    *strPtr++ = 0x2DF;
    FUN_080b9938(&a[i].x, slot);
    flagPtr++;
  }

  bp = b;
  ap = &a[1];
  for (i = 1; i >= 0; i--) {
    *bp++ = *ap--;
  }

  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
#else
  INCFUNC("asm/func/FUN_080bb688.inc");
#endif
}

// 持っている防具を売る演出を仕込む, 元のアイコンを隠して入れ替え先へ飛ばす
void FUN_080bb798(ItemShop* p) {
  s32 unk1[2];
  WorldPos a[2];
  WorldPos b[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  p->sprites[(u8)p->cursor.savedSlot + 3].flags |= SPRFLAG_HIDDEN;
  anims[0] = ARMORS((u8)p->cursor.savedSlot) + 0x43;
  strIDs[0] = 0x2DF;
  FUN_080b9938(&a[0].x, (u8)p->cursor.savedSlot);
  FUN_080b9938(&b[0].x, (u8)p->cursor.slot);
  unk1[1] = 0;
  anims[1] = 0x43;
  strIDs[1] = 0x2DF;
  a[1].x = 0;
  a[1].y = 0;
  a[1].z = 0;
  b[1].x = 0;
  b[1].y = 0;
  b[1].z = 0;
  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// 防具の入れ替え演出を仕込む, 元の位置と入れ替え先の位置をそれぞれ求めて渡す
void FUN_080bb854(ItemShop* p) {
  s32 unk1[2];
  WorldPos a[2];
  WorldPos b[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  anims[0] = p->items1[(u8)p->cursor.savedSlot - 16] + 0x43;
  strIDs[0] = 0x2DF;
  FUN_080b9938(&a[0].x, (u8)p->cursor.savedSlot);
  FUN_080b9938(&b[0].x, (u8)p->cursor.slot);
  unk1[1] = 0;
  anims[1] = 0x68;
  strIDs[1] = 0x2DF;
  a[1].x = 0;
  a[1].y = 0;
  a[1].z = 0;
  b[1].x = 0;
  b[1].y = 0;
  b[1].z = 0;
  FUN_080b9a28(&p->pair0.gfx, unk1, a, b, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

NAKED void FUN_080bb8f4(ItemShop* p, s32 param_2) { INCFUNC("asm/func/FUN_080bb8f4.inc"); }

// 防具のカーソル入れ替え操作の可否を判定し, 必要ならカーソルを移し替えて種別コードを返す
// 残差1命令 (115/116): 原典は shopColX==SPECIAL_COL 側の return 5 を別ブロックで持つが, agbcc はもう一方の return 5 と畳む
NON_MATCH s32 FUN_080bba88(ItemShop* p) {
#ifdef NONMATCHING_C
  if (p->cursor.savedShopColX <= 3) {
    s32 slot = (u8)p->cursor.savedSlot;

    if (ARMORS(slot) >= 0) {
      if (p->cursor.shopColX == SPECIAL_COL) {
        if (gStat->armor == slot) {
          return 0;
        }
        if ((u8)p->cursor.slot != SLOT_SELL) {
          return 0;
        }
        return 5;
      }

      if ((u8)p->cursor.slot == slot) {
        if (p->cursor.unk_7 & 0x10) {
          return 0;
        }
        p->cursor.slot = SLOT_SELL;
        return 5;
      }
      return 1;
    }

    if (ARMORS((u8)p->cursor.slot) < 0) {
      return 0;
    }
    return 1;
  }

  if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    s32 n = p->unk_12f2;

    p->cursor.slot = n;
    p->cursor.shopColX = n & 3;
    p->cursor.shopRowY = (u8)p->cursor.slot >> 2;
    return 4;
  }

  if (p->cursor.shopColX <= 3 && ARMORS((u8)p->cursor.slot) < 0) {
    return 4;
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_080bba88.inc");
#endif
}

// 空いている鎧スロットの番号を返す, 無ければ -1
s32 FindEmptyArmorSlot(ItemShop* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (gStat->armors[i] < 0) {
      return i;
    }
  }

  return -1;
}

// 防具リストの選択画面に戻る, カーソルを復帰させて一覧を描き直す
void FUN_080bbbdc(ItemShop* p) {
  p->sprites[36].flags |= SPRFLAG_HIDDEN;
  p->sprites[35].flags &= ~SPRFLAG_HIDDEN;
  p->unk_12f2 = FindEmptyArmorSlot(p);
  FUN_080b9fe8(&p->cursor);
  FUN_080b9fc4(&p->cursor, &p->sprites[35]);
  FUN_080b9d94(&p->cursor, 20);
  FUN_080bb294(p);
  FUN_080bb388(p);
  FUN_080bb5bc(p);
  FUN_080bb8f4(p, 0);
  FUN_080ba054(p, FUN_080bbc60, 1);
}

NAKED void FUN_080bbc60(ItemShop* p) { INCFUNC("asm/func/FUN_080bbc60.inc"); }

NAKED void FUN_080bbeec(ItemShop* p) { INCFUNC("asm/func/FUN_080bbeec.inc"); }

// 購入の結果に応じて効果音を鳴らし, 決定ならカーソルの退避値を戻してから FUN_080bbbdc へ戻る
void FUN_080bc07c(ItemShop* p) {
  s32 ret = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (ret == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortArmors(0);
    p->cursor.savedShopColX = 0;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 0;
    FUN_080bbbdc(p);
  } else if (ret == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080bbbdc(p);
  }
}

// 決定されたらカーソルの退避位置と現在位置の鎧を入れ替える
void ItemShop_SwapSelectedArmor(ItemShop* p) {
  if (FUN_080b9adc(&p->pair0)) {
    SwapArmorSlot((u8)p->cursor.savedSlot, (u8)p->cursor.slot);
    FUN_080bbbdc(p);
  }
}

void FUN_080bc170(ItemShop* p);

// カーソル確定の入力待ち, 決定なら FUN_080bc170 へ, キャンセルなら SE を鳴らして戻る
void FUN_080bc11c(ItemShop* p) {
  s32 r = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080bb854(p);
    FUN_080ba054(p, FUN_080bc170, 0);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080bbbdc(p);
  }
}

// 防具の購入を確定する, 装備欄に入れて所持金から値段を引く
// 残差0命令 (44/44), 並び順だけ違う: 原典は savedSlot を読んで p を足してから 0x12F4 を作るが, agbcc は定数を先に作る
// Tier A-C は試済: 二重索引形 (FUN_080bafa4 ではこれで一致した), ポインタローカル形, 索引ローカルの追加
NON_MATCH void FUN_080bc170(ItemShop* p) {
#ifdef NONMATCHING_C
  if (FUN_080b9adc(&p->pair0)) {
    s32 slot = (u8)p->cursor.slot;
    s32 idx = (u8)p->cursor.savedSlot;

    SetArmorIntoInventory(slot, p->items0[idx]);
    gStat->solarBank -= gArmorDB[p->items0[idx]].price;
    p->unk_151b = 1;
    PlaySound_082406e0(SE_EQUIP);
    FUN_080bbbdc(p);
  }
#else
  INCFUNC("asm/func/FUN_080bc170.inc");
#endif
}

void FUN_080bc240(ItemShop* p);

// カーソル確定の入力待ち, 決定なら FUN_080bc240 へ, キャンセルなら SE を鳴らして戻る
void FUN_080bc1ec(ItemShop* p) {
  s32 r = FUN_080b977c(&p->sprites[48], &p->gfx0, &p->unk_12ef);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080bb798(p);
    FUN_080ba054(p, FUN_080bc240, 0);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080bbbdc(p);
  }
}

// 防具の売却を確定する, 値段の半額を所持金に足して (9999 で打ち止め) 装備欄から外す
// 残差4命令 (54/58): FUN_080bb070 と同じく, 原典は打ち止めの代入で gStat を読み直して &solarBank を組み立て直す
NON_MATCH void FUN_080bc240(ItemShop* p) {
#ifdef NONMATCHING_C
  if (FUN_080b9adc(&p->pair0)) {
    s32 slot = (u8)p->cursor.savedSlot;

    gStat->solarBank += Div(gArmorDB[ARMORS(slot)].price * 50, 100);
    if ((s16)gStat->solarBank > 9999) {
      gStat->solarBank = 9999;
    }
    RemoveArmorFromInventory(slot);
    p->unk_151c = 1;
    FUN_080ba054(p, FUN_080bc2d8, 0);
  }
#else
  INCFUNC("asm/func/FUN_080bc240.inc");
#endif
}

// 防具売却後の演出, カーソルの絵を少し持ち上げてから一覧へ戻す
void FUN_080bc2d8(ItemShop* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SONG_630);
  }

  p->stateTimer++;
  if (p->stateTimer <= 11) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[31].pos.y = 32;
    } else {
      p->sprites[31].pos.y = 32 - ((20 - p->stateTimer) >> 3);
    }
  } else if (p->stateTimer <= 15) {
    p->sprites[31].pos.y = 32;
  } else {
    FUN_080bbbdc(p);
  }
}

// 防具リストの画面を組み立ててカーソルを初期化する
void FUN_080bc350(ItemShop* p) {
  p->unk_12ed = 1;
  p->unk_12f2 = FindEmptyArmorSlot(p);
  Video_SetBGLayer(0, p->tilemap, 2);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  FUN_080b94cc(p->kind);
  FUN_080b9400(p->kind);
  ShopCursor_Init(&p->cursor, 1, 4, 0, 20);
  FUN_080b9fc4(&p->cursor, &p->sprites[35]);
  FUN_080bb388(p);
  FUN_080bb5bc(p);
  FUN_080bb294(p);
  FUN_080bb8f4(p, 0);
  FUN_080ba054(p, FUN_080bbc60, 1);
}

// 背景のタイルマップを読み込んで BG0 に割り当てる
void ItemShop_SetupBG(ItemShop* p) {
  s32 bgIndex;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_9F57);
  bgIndex = 0;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &bgIndex);
  Video_SetBGLayer(0, p->tilemap, 2);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
}

// BGP_A41A[208]以降を BG パレットバッファの 208 色目にコピーする
void ItemShop_LoadBgPltt(ItemShop* p) {
  p->bgPltt = &GetBgPlttFile(BGP_A41A)->body[208];
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

NAKED void FUN_080bc498(ItemShop* p) { INCFUNC("asm/func/FUN_080bc498.inc"); }

void FUN_080bc8c8(ItemShop* p) {
  if (VM_SeekToNamedArg('s')) {
    p->unk_12e0 = VM_GetPC_Proxy();
  }

  FUN_08049f5c();
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_SetBgPltt(BGP_A41A);
}

// '.I' の個数だけ '.T' から売り物の道具IDを読み, 余りは -1 で埋めて末尾4件を複製する
// 残差1命令 (56/57): 原典は -1 埋めのループで &items0 をプール経由で作り直すが, agbcc は1つ目のループのベースを使い回す
// Tier A-C は試済: 2つ目を for (i = count; ...) にすると命令数は合うが |= 0xFF が -1 の直接ストアに畳まれる
NON_MATCH void FUN_080bc908(ItemShop* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 i;

  if (VM_SeekToNamedArg('I')) {
    count = VM_GetValue();
  } else {
    count = 0;
  }

  if (VM_SeekToNamedArg('T')) {
    for (i = 0; i < count; i++) {
      p->items0[i] = VM_GetValue();
    }
    while (i < 12) {
      p->items0[i] |= 0xFF;
      i++;
    }
    for (i = 0; i < 4; i++) {
      p->items0[12 + i] = p->items0[8 + i];
    }
  }

  if (VM_SeekToNamedArg('i')) {
    p->unk_12e4 = VM_GetPC_Proxy();
  }
#else
  INCFUNC("asm/func/FUN_080bc908.inc");
#endif
}

// '.A' の個数だけ '.R' から売り物の防具IDを読み, 余りは -1 で埋めて末尾4件を複製する
// 残差1命令 (56/57): FUN_080bc908 と同じく, 原典は -1 埋めのループで &items1 を作り直す
NON_MATCH void FUN_080bc994(ItemShop* p) {
#ifdef NONMATCHING_C
  s32 count;
  s32 i;

  if (VM_SeekToNamedArg('A')) {
    count = VM_GetValue();
  } else {
    count = 0;
  }

  if (VM_SeekToNamedArg('R')) {
    for (i = 0; i < count; i++) {
      p->items1[i] = VM_GetValue();
    }
    while (i < 12) {
      p->items1[i] |= 0xFF;
      i++;
    }
    for (i = 0; i < 4; i++) {
      p->items1[12 + i] = p->items1[8 + i];
    }
  }

  if (VM_SeekToNamedArg('a')) {
    p->unk_12e8 = VM_GetPC_Proxy();
  }
#else
  INCFUNC("asm/func/FUN_080bc994.inc");
#endif
}

// VM の e 引数を unk_1534 に取り込む
void FUN_080bca20(ItemShop* p) {
  if (VM_SeekToNamedArg('e')) {
    p->unk_1534 = VM_GetValue();
  } else {
    p->unk_1534 = 0;
  }
}

void FUN_080bca50(ItemShop* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    ItemShop_SetState(p, FUN_080bca7c);
  }
}

NAKED void FUN_080bca7c(ItemShop* p) { INCFUNC("asm/func/FUN_080bca7c.inc"); }

// 32フレーム待ってから終了スクリプトを走らせて自分を破棄する
void FUN_080bcbf4(ItemShop* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    ScriptArgs sa;
    u32 args[2];

    if (p->unk_1534 != 0) {
      sa.argc = 2;
      args[0] = p->unk_151b;
      args[1] = p->unk_151c;
      sa.argv = args;
      VM_ExecByID(p->unk_1534, &sa);
    }
    KillEntity((Entity*)p);
  }
}

s32 ItemShop_Update(ItemShop* p) {
  FUN_080b94cc(p->kind);
  FUN_080b9400(p->kind);
  p->updateCallback(p);
  return 0;
}

s32 ItemShop_Destroy(ItemShop* p) {
  s32 i;

  for (i = 0; i < (s32)ARRAY_COUNT(p->sprites); i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  FUN_080b9a0c(&p->pair0);
  FUN_080b9894(&p->pair1);
  return 0;
}

// 売り物リストと画面を組み立てて最初の状態へ入る, param_2 が 1 なら防具リストも読む
s32 ItemShop_Init(ItemShop* p, s8 param_2) {
  p->unk_12ec = param_2;
  FUN_080bc908(p);
  if ((u8)p->unk_12ec == 1) {
    FUN_080bc994(p);
  }

  ItemShop_SetupBG(p);
  ItemShop_LoadBgPltt(p);
  FUN_080bc498(p);
  FUN_080bc8c8(p);
  FUN_080bca20(p);
  p->unk_151b = 0;
  p->unk_151c = 0;
  FUN_0823ce68(2, 5, 4, 4, 4, 0xFFFF, 0);
  FUN_080bb160(p);
  PlaySound_082406e0(SE_OPEN_MENU);
  ItemShop_SetState(p, FUN_080bca50);
  return 0;
}

// 0x3019, 果実屋(リタ), Hash元まだ未特定
ItemShop* RitaShop_Create(void) {
  ItemShop* p = CreateEntity(ENTITY_UNK_11, sizeof(ItemShop));

  if (p != NULL) {
    SetEntityRoutine(p, ItemShop_Update, ItemShop_Destroy);
    if (ItemShop_Init(p, 0) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 0x7300, HashName("道具屋")
ItemShop* KidShop_Create(void) {
  ItemShop* p = CreateEntity(ENTITY_UNK_11, sizeof(ItemShop));

  if (p != NULL) {
    SetEntityRoutine(p, ItemShop_Update, ItemShop_Destroy);
    if (ItemShop_Init(p, 1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
