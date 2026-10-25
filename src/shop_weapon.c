#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "inventory.h"
#include "shop.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

#define SPECIAL_COL 8  // 追加UI(整頓 or 売る)
#define SLOT_SORT 0x21
#define SLOT_SELL 0x22

struct WeaponShop;
typedef void(WeaponShopFunc)(struct WeaponShop* p);

// 武器屋のショップメニュー
typedef struct WeaponShop {
  Entity e;                        // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;              // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx icons;             // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;              // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[58];          // 0x0078, [38] がカーソル
  Tilemaps* tilemap;               // 0x1638, TILEMAP_9F57
  rgb555* bgPltt;                  // 0x163C, BGP_A41A[208]
  u8* unk_1640;                    // 0x1640, '.s' があれば VM_GetPC_Proxy の戻り値
  u8* unk_1644;                    // 0x1644, '.w' があれば VM_GetPC_Proxy の戻り値
  char* unk_1648;                  // 0x1648, '.c' を VM_ParseStringRef して GetStringByID した文字列
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
  u16 stateTimer;                  // 0x168E, WeaponShop_SetState / FUN_080bcdf8 が差し替えのたびに 0 に戻す
  ShopSpritePair pair0;            // 0x1690
  u8 unk_1770[0x1784 - 0x1770];    // 0x1770, まだ未解析
  ShopCursor cursor;               // 0x1784, ShopCursor_Init(&cursor, 1, 4, 0, 20)
  ShopSpritePair pair1;            // 0x17B4
  u32 unk_1894;                    // 0x1894, '.e' (なければ 0)
  WeaponShopFunc* updateCallback;  // 0x1898
  WeaponShopFunc* unk_189c;        // 0x189C, FUN_080bcdf8 が入れる, 読み手は未調査
} WeaponShop;
static_assert(sizeof(WeaponShop) == 6304);

void GetRegisteredWeaponData(s32 idx, WeaponData* data);
void SetWeaponData(slot32_t n, const WeaponData* data);
void GetWeaponData(slot32_t n, WeaponData* data);
bool32 IsWeaponRegistered(slot32_t n);
s32 FUN_0807a6cc(WeaponData* w);
void FUN_08094d1c(u8* param_1, s8* param_2);
void FUN_08094d48(unknown* w, u8* pc);
s32 GetWeaponWearPose(WeaponData* w);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);

void WeaponShop_ConfirmSort(WeaponShop* p);
void WeaponShop_HandleActionInput(WeaponShop* p);
void WeaponShop_SwapSelectedWeapon(WeaponShop* p);
void FUN_080bde60(WeaponShop* p);
void FUN_080bdf94(WeaponShop* p);
void WeaponShop_Close(WeaponShop* p);
void FUN_080bd9e8(WeaponShop* p);
void WeaponShop_AnimateSale(WeaponShop* p);
void WeaponShop_HandleTabInput(WeaponShop* p);

void WeaponShop_SetState(WeaponShop* p, WeaponShopFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080bcdec(WeaponShop* p, s32 val) { p->unk_1655 = val; }

void FUN_080bcdf8(WeaponShop* p, WeaponShopFunc* fn, s32 val) {
  p->unk_189c = fn;
  FUN_080bcdec(p, val);
  p->stateTimer = 0;
}

void FUN_080bce20(WeaponShop* p, s32 line, u8* unused1, s32 unused2) {
  Marquee_Clear();
  p->sprites[33].flags |= SPRFLAG_HIDDEN;
  MessageWindow_Start(p->unk_1640);
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_ShowLine(line);
}

// 売値 = price * (特殊効果なしなら quality*5+50, あるなら 効果数*20+100) / 100, 最低 1
// 残差はレジスタ割当が1つずれて price のコピーと v の退避が省かれる4命令 (47/51命令), Tier A-C は試済
NON_MATCH s32 WeaponShop_GetSellPrice(s32 slot) {
#ifdef NONMATCHING_C
  s32 v;
  s32 n;
  s32 i;
  Weapon* w = GetWeapon(slot);
  u32 price = gWeaponDB[w->id].price;

  if (price == 0) {
    return 0;
  }

  n = 0;
  for (i = 0; i < 3; i++) {
    if ((u8)w->effects[i] != 0) {
      n++;
    }
  }

  if (n == 0) {
    v = price * ((s8)w->quality * 5 + 50);
  } else {
    v = (n * 20 + 100) * price;
  }

  v = Div(v, 100);
  if (v > 0) {
    return v;
  }

  return 1;
#else
  INCFUNC("asm/func/WeaponShop_GetSellPrice.inc");
#endif
}

// value を百の位・十の位・一の位に分解する
static void SplitDecimal3(s32 value, s32* digits) {
  digits[0] = Div(value, 100);
  value -= digits[0] * 100;
  digits[1] = Div(value, 10);
  digits[2] = value - digits[1] * 10;
}

// 装備4枠の数値表示を更新する, data の枠だけ現在値との大小でパレットを変える
// 残差は p がレジスタに乗らずスタックに退避される1命令だけ (132/133命令), Tier A-C は試済
NON_MATCH void FUN_080bcf04(WeaponShop* p, WeaponData* data) {
#ifdef NONMATCHING_C
  s32 digits[3];
  WeaponData w;
  s32 col;
  s32 i;
  s32 j;

  switch (data->kind) {
    case WK_SWORD: {
      col = 0;
      break;
    }
    case WK_SPEAR: {
      col = 1;
      break;
    }
    case WK_HAMMER: {
      col = 2;
      break;
    }
    case WK_GUN: {
      col = 3;
      break;
    }
    default: {
      col = -1;
      break;
    }
  }

  for (i = 0; i < 4; i++) {
    s32 cur;

    GetRegisteredWeaponData(i, &w);
    cur = FUN_0807a6cc(&w);

    if (i != col) {
      SplitDecimal3(cur, digits);
      for (j = 0; j < 3; j++) {
        MainSprite_SetPose(&p->sprites[i * 3 + 40 + j], &p->gfx0, digits[j], 1);
      }
    } else {
      s32 v = FUN_0807a6cc(data);
      s32 ofs = 0;

      if (v != cur) {
        ofs = 2;
        if (v > cur) {
          ofs = 1;
        }
      }

      SplitDecimal3(v, digits);
      for (j = 0; j < 3; j++) {
        MainSprite_SetPose(&p->sprites[i * 3 + 40 + j], &p->gfx0, digits[j] + ofs * 10, 1);
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080bcf04.inc");
#endif
}

void WeaponShop_WritePS(WeaponShop* p, WeaponData* data) {
  s32 i = 0;
  char* src = p->unk_1648;

  while (*src != '\0' && i <= 10) {
    data->PS[i] = *src;
    src++;
    i++;
  }

  data->PS[i] = '\0';
}

// カーソル下の武器の説明欄 (アイコン, 名前, 性能) を出す
// 残差は在庫側の添字で -16 が swords のベースに畳まれる1命令だけ (114/114命令), Tier A-C は試済
NON_MATCH void FUN_080bd058(WeaponShop* p) {
#ifdef NONMATCHING_C
  WeaponData w;

  if (p->cursor.shopColX <= 3) {
    GetWeaponData((u8)p->cursor.slot, &w);
  } else if (p->cursor.shopColX <= 7) {
    w = gWeaponDB[(s8)p->swords[(u8)p->cursor.slot + p->unk_1654 * 16 - 16]];
    *(u8*)&w.effects[0] = 0;
    WeaponShop_WritePS(p, &w);
  } else {
    w = gWeaponDB[0];
  }

  if (w.id == 0) {
    p->sprites[33].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    p->sprites[33].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[33], &p->icons, GetWeaponWearPose(&w), 1);
    MessageWindow_Start(p->unk_1644);
    MessageWindow_SetRect(2, 16, 28, 2);
    FUN_08094d1c((u8*)&w, (s8*)p->unk_164c);
    FUN_08094d48(&w, p->unk_1644);
  }

  FUN_080bcf04(p, &w);
#else
  INCFUNC("asm/func/FUN_080bd058.inc");
#endif
}

// 手持ち16枠と在庫12枠のアイコン, 登録武器4枠のカーソル位置を更新する
// 残差はスタック退避の本数とレジスタ割当だけ (238/238命令), Tier A-C は試済
NON_MATCH void FUN_080bd180(WeaponShop* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      s32 slot = i * 4 + j;
      weapon32_t id = GetWeaponID(slot);

      if (id > 0) {
        p->sprites[3 + i * 4 + j].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[3 + i * 4 + j], &p->icons, id, 1);
      } else {
        p->sprites[3 + i * 4 + j].flags |= SPRFLAG_HIDDEN;
      }

      // 装備中か売値がない武器は売ることができないので、それらのアイコンはパレットを 735 にする
      if (IsWeaponRegistered(slot) == 0 && WeaponShop_GetSellPrice(slot) != 0) {
        FUN_080b95bc(&p->sprites[3 + i * 4 + j], 735);
      } else {
        FUN_080b95bc(&p->sprites[3 + i * 4 + j], 736);
      }
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      s32 slot = i * 4 + j;
      weapon32_t id = gWeaponDB[(s8)p->swords[slot + p->unk_1654 * 16]].id;

      if (id > 0) {
        p->sprites[19 + i * 4 + j].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[19 + i * 4 + j], &p->icons, id, 1);
        if (gStat->solarBank < gWeaponDB[id].price) {
          FUN_080b95bc(&p->sprites[19 + i * 4 + j], 0x2E0);
        } else {
          FUN_080b95bc(&p->sprites[19 + i * 4 + j], 0x2DF);
        }
      } else {
        p->sprites[19 + i * 4 + j].flags |= SPRFLAG_HIDDEN;
      }
    }
  }

  for (i = 0; i < 4; i++) {
    if (gStat->registeredWeapon[i] < 0) {
      p->sprites[34 + i].flags |= SPRFLAG_HIDDEN;
    } else {
      p->sprites[34 + i].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[34 + i].pos.x = (gStat->registeredWeapon[i] & 3) * 24 + 144;
      p->sprites[34 + i].pos.y = ((s16)gStat->registeredWeapon[i] >> 2) * 24 + 32;
    }
  }
#else
  INCFUNC("asm/func/FUN_080bd180.inc");
#endif
}

// カーソル下の武器の値段スプライトを出す (行0〜3 は手持ちの売値, 4〜7 は在庫の定価)
// 残差は &cursor.slot の算出位置と 0x1654 のプール定数を +8 して swords の base に使い回す点だけ (69/69命令), Tier A-C は試済
NON_MATCH void FUN_080bd390(WeaponShop* p) {
#ifdef NONMATCHING_C
  WorldPos pos;
  s32 id;
  s32 price;
  s32 flag;

  if (p->cursor.shopColX <= 3) {
    id = GetWeaponID((u8)p->cursor.slot);
    price = WeaponShop_GetSellPrice((u8)p->cursor.slot);
    flag = 1;
  } else if (p->cursor.shopColX <= 7) {
    id = (s8)p->swords[p->unk_1654 * 16 - 16 + (u8)p->cursor.slot];
    price = gWeaponDB[id].price;
    flag = 0;
  } else {
    id = 0;
    price = 0;
    flag = 0;
  }

  if (id > 0 && price > 0) {
    FUN_080b9938(&pos.x, (u8)p->cursor.slot);
    FUN_080b9658(&p->gfx2, &p->sprites[52], &pos, price, flag);
  } else {
    FUN_080b9724(&p->sprites[52]);
  }
#else
  INCFUNC("asm/func/FUN_080bd390.inc");
#endif
}

// 登録スロットから weapon を探して添字を返す, 無ければ -1
s32 FindRegisteredWeaponSlot(s32 weapon) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (REGISTERED_WEAPON(i) == weapon) {
      return i;
    }
  }
  return -1;
}

// カーソル位置と退避位置の2本の武器を入れ替えるアニメを仕込む
// 残差はプロローグの配列ベース退避の順序と p が r8/r9 のどちらに乗るかだけ (112/112命令), Tier A-C は試済
NON_MATCH void FUN_080bd47c(WeaponShop* p) {
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
    s32 r;
    s32 id;

    p->sprites[slot + 3].flags |= SPRFLAG_HIDDEN;
    r = FindRegisteredWeaponSlot(slot);
    if (r >= 0) {
      p->sprites[r + 34].flags |= SPRFLAG_HIDDEN;
    }

    id = GetWeaponID(slot);
    if (id > 0) {
      *flagPtr = 1;
    } else {
      *flagPtr = 0;
    }

    *animPtr++ = id;
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
  INCFUNC("asm/func/FUN_080bd47c.inc");
#endif
}

void WeaponShop_StartMoveAnim(WeaponShop* p) {
  WorldPos from[2];
  WorldPos to[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];

  unk1[0] = 1;
  p->sprites[(u8)p->cursor.savedSlot + 3].flags |= SPRFLAG_HIDDEN;
  anims[0] = GetWeaponID((u8)p->cursor.savedSlot);
  strIDs[0] = 0x2DF;
  FUN_080b9938(&from[0].x, (u8)p->cursor.savedSlot);
  FUN_080b9938(&to[0].x, (u8)p->cursor.slot);
  unk1[1] = 0;
  anims[1] = 0;
  strIDs[1] = 0x2DF;
  VEC3_SET(from[1], 0, 0, 0);
  VEC3_SET(to[1], 0, 0, 0);
  FUN_080b9a28(&p->pair0.gfx, unk1, from, to, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
}

// unk_1654 のタブ (1=剣 2=槍 3=槌) の savedSlot 番目の武器を slot へ飛ばすアニメを仕込む
// 残差は &cursor.savedSlot の算出位置が2命令ぶん後ろにずれるだけ (67/67命令), Tier A-C は試済
NON_MATCH void FUN_080bd624(WeaponShop* p) {
#ifdef NONMATCHING_C
  WorldPos from[2];
  WorldPos to[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];
  s32 base;

  unk1[0] = 1;
  base = p->unk_1654 * 16 - 16;
  anims[0] = (s8)p->swords[base + (u8)p->cursor.savedSlot];
  strIDs[0] = 0x2DF;
  FUN_080b9938(&from[0].x, (u8)p->cursor.savedSlot);
  FUN_080b9938(&to[0].x, (u8)p->cursor.slot);
  unk1[1] = 0;
  anims[1] = 0;
  strIDs[1] = 0x2DF;
  from[1].x = 0;
  from[1].y = 0;
  from[1].z = 0;
  to[1].x = 0;
  to[1].y = 0;
  to[1].z = 0;
  FUN_080b9a28(&p->pair0.gfx, unk1, from, to, anims, strIDs, 12);
  PlaySound_082406e0(SE_SWAP_SLOT);
#else
  INCFUNC("asm/func/FUN_080bd624.inc");
#endif
}

// カーソル位置でできる操作に応じて pair1 のボタン表示を切り替える
// 残差は r が r6/r7 のどちらに乗るかと movs #5 の位置だけ (138/138命令), Tier A-C は試済
NON_MATCH void FUN_080bd6d0(WeaponShop* p, s32 param_2) {
#ifdef NONMATCHING_C
  s32 r;

  if (param_2 == 0) {
    if (p->cursor.shopColX == SPECIAL_COL) {
      FUN_080b98c0(&p->pair1.gfx, 0, 4);
    } else {
      FUN_080b98c0(&p->pair1.gfx, 0, -1);
    }

    return;
  }

  r = 0;
  if (p->cursor.savedShopColX <= 3) {
    s32 slot = (u8)p->cursor.savedSlot;

    if (GetWeaponID(slot) > 0) {
      if (p->cursor.shopColX == SPECIAL_COL) {
        if (FindRegisteredWeaponSlot(slot) < 0 && WeaponShop_GetSellPrice(slot) != 0 && (u8)p->cursor.slot == SLOT_SELL) {
          r = 5;
        }
      } else if ((u8)p->cursor.slot != (u8)p->cursor.savedSlot) {
        r = 1;
      } else if (FindRegisteredWeaponSlot(slot) < 0) {
        r = 5;
        if (WeaponShop_GetSellPrice(slot) == 0) {
          r = 0;
        }
      }
    } else if (GetWeaponID((u8)p->cursor.slot) > 0) {
      r = 1;
    }
  } else if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    r = 4;
  } else if (p->cursor.shopColX <= 3 && GetWeaponID((u8)p->cursor.slot) == 0) {
    r = 4;
  }

  switch (r) {
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
#else
  INCFUNC("asm/func/FUN_080bd6d0.inc");
#endif
}

s32 FUN_080bd83c(WeaponShop* p) {
  if (p->cursor.savedShopColX <= 3) {
    s32 slot = (u8)p->cursor.savedSlot;

    if (GetWeaponID(slot) > 0) {
      if (p->cursor.shopColX == SPECIAL_COL) {
        if (FindRegisteredWeaponSlot(slot) < 0 && WeaponShop_GetSellPrice(slot) != 0 && (u8)p->cursor.slot == SLOT_SELL) {
          return 5;
        }
      } else if ((u8)p->cursor.slot != (u8)p->cursor.savedSlot) {
        return 1;
      } else if (FindRegisteredWeaponSlot(slot) < 0 && WeaponShop_GetSellPrice(slot) != 0) {
        p->cursor.slot = SLOT_SELL;
        return 5;
      }
    } else if (GetWeaponID((u8)p->cursor.slot) > 0) {
      return 1;
    }
  } else if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    p->cursor.slot = p->emptySlot;
    p->cursor.shopColX = p->cursor.slot & 3;
    p->cursor.shopRowY = (u8)p->cursor.slot >> 2;
    return 4;
  } else if (p->cursor.shopColX <= 3 && GetWeaponID((u8)p->cursor.slot) == 0) {
    return 4;
  }

  return 0;
}

s32 FindEmptyWeaponSlot(WeaponShop* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (GetWeaponID(i) == WEAPON_NONE) {
      return i;
    }
  }

  return -1;
}

void WeaponShop_ReturnToList(WeaponShop* p) {
  p->sprites[39].flags |= SPRFLAG_HIDDEN;
  p->sprites[38].flags &= ~SPRFLAG_HIDDEN;
  FUN_080b9fe8(&p->cursor);
  FUN_080b9fc4(&p->cursor, &p->sprites[38]);
  FUN_080b9d94(&p->cursor, 20);
  p->emptySlot = FindEmptyWeaponSlot(p);
  FUN_080bd058(p);
  FUN_080bd180(p);
  FUN_080bd390(p);
  FUN_080bd6d0(p, 0);
  FUN_080bcdf8(p, FUN_080bd9e8, 1);
}

// 一覧画面の入力待ち, SELECT でタブ切り替え, A で売買/入れ替えの確認へ
// 残差は ok フラグの初期化が畳まれる1命令と swords 添字のスケジューリングだけ (242/241命令), Tier A-C は試済
NON_MATCH void FUN_080bd9e8(WeaponShop* p) {
#ifdef NONMATCHING_C
  FUN_080b95d0(&p->cursor, 0, &p->sprites[32], &p->sprites[31]);

  if (gInput[0].down & SELECT_BUTTON) {
    FUN_080bcdec(p, 0);
    MainSprite_SetPose(&p->sprites[38], &p->gfx0, 56, 1);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_CURSOR_MOVE);
      p->kind++;
      if (p->kind > 2) {
        p->kind = 0;
      }
    }
  } else {
    FUN_080bcdec(p, 1);
    MainSprite_AdvanceAnim(&p->sprites[38], &p->gfx0);

    if (gInput[0].pressed & A_BUTTON) {
      if ((u8)p->cursor.slot == SLOT_SORT) {
        PlaySound_082406e0(SE_CHOICE);
        FUN_080bce20(p, 3, p->unk_1644, -1);
        FUN_080b98c0(&p->pair1.gfx, -1, -1);
        FUN_080b9740(&p->sprites[57], &p->gfx0, (char*)&p->unk_1656, 1);
        FUN_080bcdf8(p, WeaponShop_ConfirmSort, 0);
      } else if (p->cursor.shopColX > 3) {
        bool32 ok = TRUE;
        weapon32_t id = (s8)p->swords[p->unk_1654 * 16 - 16 + (u8)p->cursor.slot];

        if (id > 0 && (s16)gStat->solarBank >= gWeaponDB[id].price) {
          if ((s16)p->emptySlot < 0) {
            ok = FALSE;
          }
        } else {
          ok = FALSE;
        }

        if (!ok) {
          PlaySound_082406e0(SE_NG);
        } else {
          PlaySound_082406e0(SE_SELECT);
          FUN_080b9fd8(&p->cursor);
          p->sprites[39].flags &= ~SPRFLAG_HIDDEN;
          p->sprites[39].pos = p->sprites[38].pos;
          FUN_080b9d94(&p->cursor, 60);
          FUN_080bd6d0(p, 1);
          FUN_080bcdf8(p, WeaponShop_HandleActionInput, 0);
        }
      } else {
        weapon32_t id;

        PlaySound_082406e0(SE_SELECT);
        FUN_080b9fd8(&p->cursor);
        p->sprites[39].flags &= ~SPRFLAG_HIDDEN;
        p->sprites[39].pos = p->sprites[38].pos;
        id = GetWeaponID((u8)p->cursor.slot);

        if (FindRegisteredWeaponSlot((u8)p->cursor.slot) < 0 && id > 0 && gWeaponDB[id].price != 0) {
          FUN_080b9d94(&p->cursor, 14);
        } else {
          FUN_080b9d94(&p->cursor, 30);
        }

        FUN_080bd6d0(p, 1);
        FUN_080bcdf8(p, WeaponShop_HandleActionInput, 0);
      }
    } else if (ShopCursor_Move(&p->cursor)) {
      FUN_080b9fc4(&p->cursor, &p->sprites[38]);
      FUN_080bd058(p);
      FUN_080bd390(p);
      FUN_080bd6d0(p, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_080bd9e8.inc");
#endif
}

void WeaponShop_HandleActionInput(WeaponShop* p) {
  if (gInput[0].pressed & A_BUTTON) {
    s32 r = FUN_080bd83c(p);

    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    switch (r) {
      case 1: {
        FUN_080bd47c(p);
        FUN_080bcdf8(p, WeaponShop_SwapSelectedWeapon, 0);
        break;
      }
      case 4: {
        PlaySound_082406e0(SE_CHOICE);
        FUN_080bce20(p, 0, p->unk_1644, 0);
        FUN_080b9740(&p->sprites[57], &p->gfx0, (char*)&p->unk_1656, 1);
        FUN_080bcdf8(p, FUN_080bde60, 0);
        break;
      }
      case 5: {
        PlaySound_082406e0(SE_CHOICE);
        FUN_080bce20(p, 1, p->unk_1644, 0);
        FUN_080b9740(&p->sprites[57], &p->gfx0, (char*)&p->unk_1656, 0);
        FUN_080bcdf8(p, FUN_080bdf94, 0);
        break;
      }
      default: {
        PlaySound_082406e0(SE_NG);
        break;
      }
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    WeaponShop_ReturnToList(p);
  } else if (ShopCursor_Move(&p->cursor)) {
    FUN_080b9fc4(&p->cursor, &p->sprites[38]);
    FUN_080bd058(p);
    FUN_080bd6d0(p, 1);
  }

  FUN_080b95d0(&p->cursor, 0, &p->sprites[32], &p->sprites[31]);
  MainSprite_AdvanceAnim(&p->sprites[38], &p->gfx0);
}

void WeaponShop_ConfirmSort(WeaponShop* p) {
  s32 r = FUN_080b977c(&p->sprites[57], &p->gfx0, &p->unk_1656);

  if (r == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortWeapons(0);
    p->cursor.savedShopColX = 0;
    p->cursor.savedShopRowY = 0;
    p->cursor.savedSlot = 0;
    WeaponShop_ReturnToList(p);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    WeaponShop_ReturnToList(p);
  }
}

// 決定されたらカーソルの退避位置と現在位置の武器を入れ替える
void WeaponShop_SwapSelectedWeapon(WeaponShop* p) {
  if (FUN_080b9adc(&p->pair0)) {
    SwapWeaponSlot((u8)p->cursor.savedSlot, (u8)p->cursor.slot);
    WeaponShop_ReturnToList(p);
  }
}

void WeaponShop_BuyWeapon(WeaponShop* p);
void FUN_080bdfe8(WeaponShop* p);

// カーソル確定の入力待ち, 決定なら WeaponShop_BuyWeapon へ, キャンセルなら SE を鳴らして戻る
void FUN_080bde60(WeaponShop* p) {
  s32 r = FUN_080b977c(&p->sprites[57], &p->gfx0, &p->unk_1656);

  if (r == 1) {
    MessageWindow_Close();
    FUN_080bd624(p);
    FUN_080bcdf8(p, WeaponShop_BuyWeapon, 0);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    WeaponShop_ReturnToList(p);
  }
}

void WeaponShop_BuyWeapon(WeaponShop* p) {
  if (FUN_080b9adc(&p->pair0)) {
    s32 slot = (u8)p->cursor.slot;
    s32 idx = (u8)p->cursor.savedSlot - 16;
    WeaponData w = gWeaponDB[(s8)p->swords[idx + p->unk_1654 * 16]];

    *(u8*)&w.effects[0] = 0;
    WeaponShop_WritePS(p, &w);
    SetWeaponData(slot, &w);
    gStat->solarBank -= gWeaponDB[(s8)p->swords[idx + p->unk_1654 * 16]].price;
    p->unk_1658 = 1;
    PlaySound_082406e0(SE_EQUIP);
    WeaponShop_ReturnToList(p);
  }
}

// カーソル確定の入力待ち, 決定なら FUN_080bdfe8 へ, キャンセルなら SE を鳴らして戻る
void FUN_080bdf94(WeaponShop* p) {
  s32 r = FUN_080b977c(&p->sprites[57], &p->gfx0, &p->unk_1656);

  if (r == 1) {
    MessageWindow_Close();
    WeaponShop_StartMoveAnim(p);
    FUN_080bcdf8(p, FUN_080bdfe8, 0);
  } else if (r == 0) {
    PlaySound_082406e0(SE_CANCEL);
    WeaponShop_ReturnToList(p);
  }
}

// 残差は 9999 クランプで gStat を再ロードしない4命令 (39/43命令), Tier A-C は試済
NON_MATCH void FUN_080bdfe8(WeaponShop* p) {
#ifdef NONMATCHING_C
  if (FUN_080b9adc(&p->pair0)) {
    s32 slot = (u8)p->cursor.savedSlot;

    gStat->solarBank += WeaponShop_GetSellPrice(slot);
    if (gStat->solarBank > 9999) {
      gStat->solarBank = 9999;
    }

    RemoveWeapon(slot);
    p->unk_1659 = 1;
    FUN_080bcdf8(p, WeaponShop_AnimateSale, 0);
  }
#else
  INCFUNC("asm/func/FUN_080bdfe8.inc");
#endif
}

void WeaponShop_AnimateSale(WeaponShop* p) {
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
    WeaponShop_ReturnToList(p);
  }
}

void WeaponShop_OpenList(WeaponShop* p) {
  ShopCursor_Init(&p->cursor, 1, 4, 0, 20);
  FUN_080b9fc4(&p->cursor, &p->sprites[38]);
  p->emptySlot = FindEmptyWeaponSlot(p);
  FUN_080bd180(p);
  FUN_080bd390(p);
  FUN_080bd058(p);
  FUN_080bd6d0(p, 0);
  FUN_080bcdf8(p, FUN_080bd9e8, 1);
}

void WeaponShop_SetupBg(WeaponShop* p) {
  WeaponData w;
  s32 indices[1];

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_9F57);
  indices[0] = 0;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, indices);
  Video_SetBGLayer(0, p->tilemap, 4);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  GetRegisteredWeaponData(3, &w);
  if (w.kind == WK_GUN) {
    gBgStates[0].tilemap[457] = 0xF06E;
  }
}

// BGP_A41A[208] 以降を BG パレットバッファの 208 色目にコピーする
void WeaponShop_LoadBgPltt(WeaponShop* p) {
  p->bgPltt = &GetBgPlttFile(BGP_A41A)->body[208];
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

// 画面のスプライトを全部登録する
// 残差は pos 初期化の 0 を引数の 0 と共有してしまう1命令だけ (480/481命令), shop_coffin.c の FUN_080bf494 と同じ原因, Tier A-C は試済
NON_MATCH void FUN_080be204(WeaponShop* p) {
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
  MainSprite_Add(&p->sprites[0], &p->gfx2, 39, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[1], &p->gfx2, 35, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[2], &p->gfx2, 36, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);

  for (i = 0; i < 16; i++) {
    pos.y = (i >> 2) * 24 + 32;
    pos.x = (i & 3) * 24 + 144;
    MainSprite_Add(&p->sprites[3 + i], &p->icons, 104, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  }

  for (i = 0; i < 12; i++) {
    pos.y = (i >> 2) * 24 + 32;
    pos.x = (i & 3) * 24 + 8;
    MainSprite_Add(&p->sprites[19 + i], &p->icons, 104, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  }

  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[34 + i], &p->gfx0, 65, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  }

  pos.x = 0;
  pos.y = 128;
  MainSprite_Add(&p->sprites[33], &p->icons, ICON_TIMER_100, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);

  pos.x = 120;
  pos.y = 104;
  MainSprite_Add(&p->sprites[32], &p->icons, ICON_SORT, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);

  pos.x = 104;
  pos.y = 32;
  MainSprite_Add(&p->sprites[31], &p->icons, ICON_SELL, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  FUN_080b95bc(&p->sprites[31], 736);
  MainSprite_Add(&p->sprites[39], &p->gfx0, 60, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);

  pos.x = 144;
  pos.y = 32;
  MainSprite_Add(&p->sprites[38], &p->gfx0, 57, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  MainSprite_SetAnim(&p->sprites[38], &p->gfx0, 0, 1, 0);
  MainSprite_Add(&p->sprites[52], &p->gfx2, 24, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);

  pos.x -= 11;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[53 + i], &p->gfx2, 25, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
    pos.x += 6;
  }

  pos.x = 40;
  pos.y = 104;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->sprites[40 + i], &p->gfx0, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
    pos.x += 8;
  }

  pos.x = 88;
  pos.y = 104;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->sprites[43 + i], &p->gfx0, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
    pos.x += 8;
  }

  pos.x = 40;
  pos.y = 112;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->sprites[46 + i], &p->gfx0, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
    pos.x += 8;
  }

  pos.x = 88;
  pos.y = 112;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->sprites[49 + i], &p->gfx0, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
    pos.x += 8;
  }

  pos.x = 0;
  pos.y = 0;
  MainSprite_Add(&p->sprites[57], &p->gfx0, 148, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);

  FUN_080b99a0(&p->pair0);
  FUN_080b9814(&p->pair1);
#else
  INCFUNC("asm/func/FUN_080be204.inc");
#endif
}

void FUN_080be650(WeaponShop* p) {
  if (VM_SeekToNamedArg('s')) {
    p->unk_1640 = VM_GetPC_Proxy();
  }

  FUN_08049f5c();
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_SetBgPltt(BGP_A41A);
}

void WeaponShop_ReadScriptArgs(WeaponShop* p) {
  s32 i;
  s32 count = VM_SeekToNamedArg('W') ? VM_GetValue() : 0;

  if (VM_SeekToNamedArg('P')) {
    s32 nSword = 0;
    s32 nSpear = 0;
    s32 nHammer = 0;

    for (i = 0; i < count; i++) {
      weapon32_t id = VM_GetValue();

      switch (gWeaponDB[id].kind) {
        case WK_SWORD: {
          p->swords[nSword] = id;
          nSword++;
          break;
        }
        case WK_SPEAR: {
          p->spears[nSpear] = id;
          nSpear++;
          break;
        }
        case WK_HAMMER: {
          p->hammers[nHammer] = id;
          nHammer++;
          break;
        }
      }
    }

    for (; nSword <= 11; nSword++) {
      p->swords[nSword] = 0;
    }
    for (; nSpear <= 11; nSpear++) {
      p->spears[nSpear] = 0;
    }
    for (; nHammer <= 11; nHammer++) {
      p->hammers[nHammer] = 0;
    }
  }

  if (VM_SeekToNamedArg('w')) {
    p->unk_1644 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('c')) {
    p->unk_1648 = VM_GetPC_Proxy();
    if (p->unk_1648 != 0) {
      p->unk_1648 = GetStringByID(VM_ParseStringRef((u8*)p->unk_1648) + 1);
    }
  }
}

// VM の e 引数を unk_1894 に取り込む
void FUN_080be7b4(WeaponShop* p) {
  if (VM_SeekToNamedArg('e')) {
    p->unk_1894 = VM_GetValue();
  } else {
    p->unk_1894 = 0;
  }
}

void FUN_080be7e4(WeaponShop* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    WeaponShop_SetState(p, WeaponShop_HandleTabInput);
  }
}

void WeaponShop_HandleTabInput(WeaponShop* p) {
  if (p->unk_1655 != 0) {
    p->unk_165a[0]++;
    if ((p->unk_165a[0] >> 5) & 1) {
      p->sprites[1].flags |= SPRFLAG_HIDDEN;
      p->sprites[2].flags |= SPRFLAG_HIDDEN;
    } else {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
    }

    if (gInput[0].pressed & L_BUTTON) {
      if (p->unk_1654 == 0) {
        p->unk_1654 = 2;
      } else {
        p->unk_1654--;
      }

      PlaySound_082406e0(SONG_266);
      WeaponShop_OpenList(p);
    } else if (gInput[0].pressed & R_BUTTON) {
      if (p->unk_1654 == 2) {
        p->unk_1654 = 0;
      } else {
        p->unk_1654++;
      }

      PlaySound_082406e0(SONG_266);
      WeaponShop_OpenList(p);
    } else if (gInput[0].pressed & B_BUTTON) {
      PlaySound_082406e0(SE_CLOSE_MENU);
      FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
      WeaponShop_SetState(p, WeaponShop_Close);
      return;
    }
  } else {
    p->sprites[1].flags |= SPRFLAG_HIDDEN;
    p->sprites[2].flags |= SPRFLAG_HIDDEN;
    p->unk_165a[0] = 0;
  }

  p->unk_189c(p);
}

void WeaponShop_Close(WeaponShop* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    if (p->unk_1894 != 0) {
      u32 argv[2];
      ScriptArgs args;

      args.argc = 2;
      argv[0] = p->unk_1658;
      argv[1] = p->unk_1659;
      args.argv = argv;
      VM_ExecByID(p->unk_1894, &args);
    }

    KillEntity((Entity*)p);
  }
}

s32 WeaponShop_Update(WeaponShop* p) {
  FUN_080b94cc(p->kind);
  FUN_080b9400(p->kind);
  p->updateCallback(p);
  return 0;
}

s32 WeaponShop_Destroy(WeaponShop* p) {
  MainSprite* sprite = p->sprites;
  s32 i;

  for (i = 0; i < 58; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  FUN_080b9a0c(&p->pair0);
  FUN_080b9894(&p->pair1);
  return 0;
}

s32 WeaponShop_Init(WeaponShop* p) {
  WeaponShop_ReadScriptArgs(p);
  WeaponShop_SetupBg(p);
  WeaponShop_LoadBgPltt(p);
  FUN_080be204(p);
  FUN_080be650(p);
  FUN_080be7b4(p);
  FUN_0823ce68(2, 5, 4, 4, 4, 0xFFFF, 0);
  p->unk_1654 = 0;
  WeaponShop_OpenList(p);
  p->unk_1658 = 0;
  p->unk_1659 = 0;
  PlaySound_082406e0(SE_OPEN_MENU);
  WeaponShop_SetState(p, FUN_080be7e4);
  return 0;
}

// 0x744F, HashName("武器屋")
WeaponShop* WeaponShop_Create(void) {
  WeaponShop* p = CreateEntity(ENTITY_UNK_11, sizeof(WeaponShop));

  if (p != NULL) {
    SetEntityRoutine(p, WeaponShop_Update, WeaponShop_Destroy);
    if (WeaponShop_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
