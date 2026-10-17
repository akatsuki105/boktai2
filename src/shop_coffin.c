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

struct CoffinShop;
typedef void(CoffinShopFunc)(struct CoffinShop*);

// 棺桶屋のショップメニュー
typedef struct CoffinShop {
  Entity e;                        // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;              // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx gfx1;              // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;              // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[38];          // 0x0078, [1..16] と [17..28] がアイテム枠2面, [30] がカーソル
  Tilemaps* tilemap;               // 0x0EB8, TILEMAP_9F57
  rgb555* bgPltt;                  // 0x0EBC, BGP_A41A[208]
  u8* unk_ec0;                     // 0x0EC0, '.s' があれば VM_GetPC_Proxy の戻り値
  u8* unk_ec4;                     // 0x0EC4, '.i' があれば VM_GetPC_Proxy の戻り値
  u8 unk_ec8;                      // 0x0EC8, CoffinShop_SetSubState の第3引数
  u8 unk_ec9;                      // 0x0EC9, FUN_080bf29c が FUN_080b977c に渡す
  u16 stateTimer;                  // 0x0ECA, CoffinShop_SetState が fn を差し替えるときに 0 に戻す
  s8 items[16];                    // 0x0ECC, '.O' から12個読んで残りは -1. [12..15] には [8..11] の写し
  MenuSpritePair pair0;            // 0x0EDC, SPRITE_INVENTORY_ICONS
  u8 unk_fbc[0xFD0 - 0xFBC];       // 0x0FBC, まだ未解析
  MenuCursor cursor;               // 0x0FD0, MenuCursor_Init(&cursor, 1, 4, 0, 29)
  MenuSpritePair pair1;            // 0x1000, SPRITE_UI_START_MENU
  u8 kind;                         // 0x10E0, 0=太陽バンク 1=暗黒ローン それ以外=太陽スタンド
  u8 unk_10e1;                     // 0x10E1, _Init が 0 を入れる
  u8 unk_10e2;                     // 0x10E2, _Init が 0 を入れる
  u8 unk_10e3;                     // 0x10E3, まだ未解析
  u32 unk_10e4;                    // 0x10E4, '.e' (なければ 0)
  CoffinShopFunc* updateCallback;  // 0x10E8
  CoffinShopFunc* unk_10ec;        // 0x10EC, CoffinShop_SetSubState が入れる, 読み手は未調査
} CoffinShop;
static_assert(sizeof(CoffinShop) == 4336);

void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);

void FUN_080bf058(CoffinShop* p);
void CoffinShop_HandleSelectInput(CoffinShop* p);
void FUN_080bf29c(CoffinShop* p);
void CoffinShop_BuyCoffin(CoffinShop* p);
void FUN_080bf854(CoffinShop* p);
void CoffinShop_Close(CoffinShop* p);

void CoffinShop_SetState(CoffinShop* p, CoffinShopFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080beaf4(CoffinShop* p, s32 val) { p->unk_ec8 = val; }

void CoffinShop_SetSubState(CoffinShop* p, CoffinShopFunc* fn, s32 val) {
  p->unk_10ec = fn;
  FUN_080beaf4(p, val);
  p->stateTimer = 0;
}

void CoffinShop_ShowMessage(CoffinShop* p, s32 line, u8* unused1, s32 unused2) {
  FUN_08049e5c();
  p->sprites[29].flags |= SPRFLAG_HIDDEN;
  MessageWindow_Start(p->unk_ec0);
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_ShowLine(line);
}

void CoffinShop_UpdateDescription(CoffinShop* p) {
  item32_t id;

  if (p->cursor.row <= 3) {
    id = GetValuableItemID((u8)p->cursor.slot);
  } else if (p->cursor.row <= 7) {
    id = p->items[(u8)p->cursor.slot - 16];
  } else {
    id = -1;
  }

  if (id < 0) {
    p->sprites[29].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    FUN_08049e5c();
  } else {
    s32 base;

    p->sprites[29].flags &= ~SPRFLAG_HIDDEN;
    MessageWindow_Start(p->unk_ec4);
    MessageWindow_SetRect(2, 16, 28, 2);
    MessageWindow_SetInstant(1);
    MessageWindow_ShowLine(id);
    base = VM_ParseStringRef(p->unk_ec4) + 78;
    FUN_08049e30(Textbox_LookupString(base + id));
  }
}

void CoffinShop_DrawItemIcons(CoffinShop* p) {
  s32 i;
  s32 j;
  s32 n;

  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      item32_t id;

      n = i * 4 + j;
      id = GetValuableItemID(n);

      if (id >= 0) {
        p->sprites[n + 1].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[n + 1], &p->gfx1, id + 0x68, 1);
        if (id >= ITEM_OAK_COFFIN && id <= ITEM_IRON_MAIDEN) {
          FUN_080b95bc(&p->sprites[n + 1], 0x2DF);
        } else {
          FUN_080b95bc(&p->sprites[n + 1], 0x2E0);
        }
      } else {
        p->sprites[n + 1].flags |= SPRFLAG_HIDDEN;
      }
    }
  }

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 4; j++) {
      item32_t id;

      n = i * 4 + j;
      id = p->items[n];

      if (id >= 0) {
        p->sprites[n + 17].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[n + 17], &p->gfx1, id + 0x68, 1);
        if ((s16)gStat->solarBank < gItemDB[id].price) {
          FUN_080b95bc(&p->sprites[n + 17], 0x2E0);
        } else {
          FUN_080b95bc(&p->sprites[n + 17], 0x2DF);
        }
      } else {
        p->sprites[n + 17].flags |= SPRFLAG_HIDDEN;
      }
    }
  }
}

void CoffinShop_DrawPrice(CoffinShop* p) {
  s32 slot = (u8)p->cursor.slot;
  s32 id = p->items[slot - 16];

  if (id >= 0) {
    WorldPos pos;
    s32 price = gItemDB[id].price;

    FUN_080b9938(&pos.x, slot);
    FUN_080b9658(&p->gfx2, &p->sprites[32], &pos, price, 0);
  } else {
    FUN_080b9724(&p->sprites[32]);
  }
}

// 貴重品欄で棺桶が入っている最初の枠を返す
s32 CoffinShop_FindCoffinSlot(void) {
  s32 i;

  for (i = 0; i < VALUABLE_CAP; i++) {
    item32_t id = GetValuableItemID(i);
    if (id >= ITEM_OAK_COFFIN && id <= ITEM_IRON_MAIDEN) {
      return i;
    }
  }

  return ITEM_OAK_COFFIN;
}

void CoffinShop_StartSwapAnim(CoffinShop* p) {
  WorldPos from[2];
  WorldPos to[2];
  s32 unk1[2];
  s32 anims[2];
  s32 strIDs[2];
  s32 coffinSlot = CoffinShop_FindCoffinSlot();
  item32_t heldID = GetValuableItemID(coffinSlot);

  p->sprites[coffinSlot + 1].flags |= SPRFLAG_HIDDEN;
  unk1[0] = 1;
  anims[0] = heldID + 0x68;
  strIDs[0] = 0x2DF;
  FUN_080b9938(&from[0].x, coffinSlot);
  FUN_080b9938(&to[0].x, heldID - 0x28);

  p->sprites[(u8)p->cursor.savedSlot + 1].flags |= SPRFLAG_HIDDEN;
  unk1[1] = 1;
  anims[1] = p->items[(u8)p->cursor.savedSlot - 16] + 0x68;
  strIDs[1] = 0x2DF;
  FUN_080b9938(&from[1].x, (u8)p->cursor.savedSlot);
  FUN_080b9938(&to[1].x, (u8)p->cursor.slot);

  FUN_080b9a28(&p->pair0.gfx, unk1, from, to, anims, strIDs, 12);
  PlaySound_082406e0(0x38A);
}

// カーソルが選べる棺桶の上にいるかどうかで pair1 のスプライトを切り替える
void FUN_080bef00(CoffinShop* p, s32 param_2) {
  s32 r;

  if (param_2 == 0) {
    FUN_080b98c0(&p->pair1.gfx, 0, -1);
    return;
  }

  r = 0;
  if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    r = 4;
  } else if (p->cursor.row <= 3) {
    item32_t id = GetValuableItemID((u8)p->cursor.slot);

    if ((u8)p->cursor.slot == CoffinShop_FindCoffinSlot()) {
      r = 4;
    } else {
      r = 4;
      r &= id >> 31;
    }
  }

  if (r == 4) {
    FUN_080b98c0(&p->pair1.gfx, 7, -1);
  } else {
    FUN_080b98c0(&p->pair1.gfx, -1, -1);
  }
}

s32 FUN_080bef88(CoffinShop* p) {
  if ((u8)p->cursor.slot == (u8)p->cursor.savedSlot) {
    p->cursor.slot = CoffinShop_FindCoffinSlot();
    p->cursor.row = p->cursor.slot & 3;
    p->cursor.col = (u8)p->cursor.slot >> 2;
    return 4;
  }

  if (p->cursor.row <= 3) {
    item32_t id = GetValuableItemID((u8)p->cursor.slot);

    if ((u8)p->cursor.slot == CoffinShop_FindCoffinSlot()) {
      return 4;
    }

    if (id < 0) {
      return 4;
    }
  }

  return 0;
}

void FUN_080beff4(CoffinShop* p) {
  p->sprites[31].flags |= SPRFLAG_HIDDEN;
  FUN_080b9fe8(&p->cursor);
  FUN_080b9fc4(&p->cursor, &p->sprites[30]);
  FUN_080b9d94(&p->cursor, 29);
  CoffinShop_UpdateDescription(p);
  CoffinShop_DrawItemIcons(p);
  CoffinShop_DrawPrice(p);
  FUN_080bef00(p, 0);
  CoffinShop_SetSubState(p, FUN_080bf058, 1);
}

// 残差は買えない時の SE ブロックの配置のみ (cross-jump で末尾に寄る, 140/140命令), Tier A-C は試済
NON_MATCH void FUN_080bf058(CoffinShop* p) {
#ifdef NONMATCHING_C
  if (gInput[0].down & SELECT_BUTTON) {
    FUN_080beaf4(p, 0);
    MainSprite_SetPose(&p->sprites[30], &p->gfx0, 56, 1);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(0xDC);
      p->kind++;
      if (p->kind > 2) {
        p->kind = 0;
      }
    }
  } else {
    FUN_080beaf4(p, 1);
    MainSprite_AdvanceAnim(&p->sprites[30], &p->gfx0);
    if (gInput[0].pressed & A_BUTTON) {
      item32_t id = p->items[(u8)p->cursor.slot - 16];
      bool32 ok = TRUE;

      if (id >= 0) {
        if ((s16)gStat->solarBank < gItemDB[id].price) {
          ok = FALSE;
        }

        if (ok) {
          PlaySound_082406e0(0xDD);
          FUN_080b9fd8(&p->cursor);
          p->sprites[31].flags &= ~SPRFLAG_HIDDEN;
          p->sprites[31].pos = p->sprites[30].pos;
          FUN_080b9d94(&p->cursor, 60);
          FUN_080bef00(p, 1);
          CoffinShop_SetSubState(p, CoffinShop_HandleSelectInput, 0);
        } else {
          PlaySound_082406e0(0x192);
        }
      } else {
        PlaySound_082406e0(0x192);
      }
    } else if (FUN_080b9f70(&p->cursor)) {
      FUN_080b9fc4(&p->cursor, &p->sprites[30]);
      CoffinShop_UpdateDescription(p);
      CoffinShop_DrawPrice(p);
      FUN_080bef00(p, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_080bf058.inc");
#endif
}

void CoffinShop_HandleSelectInput(CoffinShop* p) {
  if (gInput[0].pressed & A_BUTTON) {
    s32 r = FUN_080bef88(p);

    FUN_080b98c0(&p->pair1.gfx, -1, -1);
    if (r == 4) {
      PlaySound_082406e0(0x107);
      CoffinShop_ShowMessage(p, 0, p->unk_ec4, 0);
      FUN_080b9740(&p->sprites[37], &p->gfx0, (char*)&p->unk_ec9, 1);
      CoffinShop_SetSubState(p, FUN_080bf29c, 0);
    } else {
      PlaySound_082406e0(0x192);
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(0xDE);
    FUN_080beff4(p);
  } else if (FUN_080b9f70(&p->cursor)) {
    FUN_080b9fc4(&p->cursor, &p->sprites[30]);
    CoffinShop_UpdateDescription(p);
    FUN_080bef00(p, 1);
  }

  MainSprite_AdvanceAnim(&p->sprites[30], &p->gfx0);
}

// カーソル確定の入力待ち, 決定なら CoffinShop_BuyCoffin へ, キャンセルなら SE を鳴らして戻る
void FUN_080bf29c(CoffinShop* p) {
  s32 r = FUN_080b977c(&p->sprites[37], &p->gfx0, &p->unk_ec9);

  if (r == 1) {
    MessageWindow_Close();
    CoffinShop_StartSwapAnim(p);
    CoffinShop_SetSubState(p, CoffinShop_BuyCoffin, 0);
  } else if (r == 0) {
    PlaySound_082406e0(0xDE);
    FUN_080beff4(p);
  }
}

void CoffinShop_BuyCoffin(CoffinShop* p) {
  if (FUN_080b9adc(&p->pair0)) {
    s32 coffinSlot = CoffinShop_FindCoffinSlot();
    item32_t heldID = GetValuableItemID(coffinSlot);
    item32_t buyID = p->items[(u8)p->cursor.savedSlot - 16];

    RemoveValuable(coffinSlot);
    SetValuable((u8)p->cursor.slot, buyID);
    gStat->solarBank -= gItemDB[buyID].price;
    p->items[heldID - ITEM_OAK_COFFIN] = heldID;
    p->items[buyID - ITEM_OAK_COFFIN] = 0xFF;
    p->unk_10e1 = 1;
    PlaySound_082406e0(0x111);
    FUN_080beff4(p);
  }
}

void FUN_080bf3a0(CoffinShop* p) {
  MenuCursor_Init(&p->cursor, 1, 4, 0, 29);
  FUN_080b9fc4(&p->cursor, &p->sprites[30]);
  CoffinShop_DrawItemIcons(p);
  CoffinShop_DrawPrice(p);
  CoffinShop_UpdateDescription(p);
  FUN_080bef00(p, 0);
  CoffinShop_SetSubState(p, FUN_080bf058, 1);
}

void CoffinShop_SetupBg(CoffinShop* p) {
  s32 indices[1];

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_9F57);
  indices[0] = 0;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, indices);
  Video_SetBGLayer(0, p->tilemap, 3);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
}

void CoffinShop_LoadBgPltt(CoffinShop* p) {
  p->bgPltt = &GetBgPlttFile(BGP_A41A)->body[208];
  CpuCopy32(p->bgPltt, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

// 残差は pos 初期化の 0 を引数の 0 と共有してしまう1命令だけ (277/278命令), Tier A-C は試済
NON_MATCH void FUN_080bf494(CoffinShop* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  MainSpriteGfxFile* f;
  s32 i;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  p->gfx1 = *f;
  OpenMainSpriteFile(&p->gfx1, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  p->gfx0 = *f;
  OpenMainSpriteFile(&p->gfx0, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_MISC);
  p->gfx2 = *f;
  OpenMainSpriteFile(&p->gfx2, f);

  pos.x = 0, pos.y = 0, pos.z = 0;
  MainSprite_Add(&p->sprites[0], &p->gfx2, 41, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);

  for (i = 0; i < 16; i++) {
    pos.y = (i >> 2) * 24 + 32;
    pos.x = (i & 3) * 24 + 144;
    MainSprite_Add(&p->sprites[1 + i], &p->gfx1, 104, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  }

  for (i = 0; i < 12; i++) {
    pos.y = (i >> 2) * 24 + 32;
    pos.x = (i & 3) * 24 + 8;
    MainSprite_Add(&p->sprites[17 + i], &p->gfx1, 104, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  }

  pos.x = 0;
  pos.y = 128;
  MainSprite_Add(&p->sprites[29], &p->gfx1, 207, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[31], &p->gfx0, 60, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);

  pos.x = 144;
  pos.y = 32;
  MainSprite_Add(&p->sprites[30], &p->gfx0, 57, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
  MainSprite_SetAnim(&p->sprites[30], &p->gfx0, 0, 1, 0);
  MainSprite_Add(&p->sprites[32], &p->gfx2, 24, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);

  pos.x -= 11;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[33 + i], &p->gfx2, 25, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, 0, 60, &pos);
    pos.x += 6;
  }

  pos.x = 0;
  pos.y = 0;
  MainSprite_Add(&p->sprites[37], &p->gfx0, 148, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);

  FUN_080b99a0(&p->pair0);
  FUN_080b9814(&p->pair1);
#else
  INCFUNC("asm/func/FUN_080bf494.inc");
#endif
}

void CoffinShop_SetupMessageWindow(CoffinShop* p) {
  if (VM_SeekToNamedArg('s')) {
    p->unk_ec0 = VM_GetPC_Proxy();
  }

  FUN_08049f5c();
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_SetInstant(1);
  MessageWindow_SetBgPltt(BGP_A41A);
}

// 残差は1つ目のループの v とアドレス一時変数の r1/r2 入れ替えのみ (68/68命令), Tier A-C は試済
NON_MATCH void FUN_080bf754(CoffinShop* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 count = VM_SeekToNamedArg('C') ? VM_GetValue() : 0;

  item32_t id = GetValuableItemID(CoffinShop_FindCoffinSlot());

  if (VM_SeekToNamedArg('O')) {
    for (i = 0; i < count; i++) {
      s32 v = VM_GetValue();
      p->items[i] = v;
      if (id == p->items[i]) {
        v |= 0xFF;
        p->items[i] = v;
      }
    }

    for (; i <= 11; i++) {
      p->items[i] = (u8)p->items[i] | 0xFF;
    }

    for (i = 0; i < 4; i++) {
      p->items[12 + i] = p->items[8 + i];
    }
  }

  if (VM_SeekToNamedArg('i')) {
    p->unk_ec4 = VM_GetPC_Proxy();
  }
#else
  INCFUNC("asm/func/FUN_080bf754.inc");
#endif
}

void CoffinShop_ReadScriptID(CoffinShop* p) {
  if (VM_SeekToNamedArg('e')) {
    p->unk_10e4 = VM_GetValue();
  } else {
    p->unk_10e4 = 0;
  }
}

void FUN_080bf828(CoffinShop* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    CoffinShop_SetState(p, FUN_080bf854);
  }
}

// B でショップを閉じにかかり, それ以外は unk_10ec のステートを回す
void FUN_080bf854(CoffinShop* p) {
  if (p->unk_ec8 != 0 && (gInput[0].pressed & B_BUTTON)) {
    PlaySound_082406e0(0x119);
    FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
    CoffinShop_SetState(p, CoffinShop_Close);
  } else {
    p->unk_10ec(p);
  }
}

// 32フレーム待ってから '.e' のスクリプトを起動して自分を消す
void CoffinShop_Close(CoffinShop* p) {
  p->stateTimer++;
  if (p->stateTimer > 31) {
    if (p->unk_10e4 != 0) {
      u32 argv[2];
      ScriptArgs args;

      args.argc = 2;
      argv[0] = p->unk_10e1;
      argv[1] = p->unk_10e2;
      args.argv = argv;
      VM_ExecByID(p->unk_10e4, &args);
    }

    KillEntity((Entity*)p);
  }
}

s32 CoffinShop_Update(CoffinShop* p) {
  FUN_080b94cc(p->kind);
  FUN_080b9400(p->kind);
  p->updateCallback(p);
  return 0;
}

s32 CoffinShop_Destroy(CoffinShop* p) {
  s32 i;

  for (i = 0; i < 38; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  FUN_080b9a0c(&p->pair0);
  FUN_080b9894(&p->pair1);
  return 0;
}

s32 CoffinShop_Init(CoffinShop* p) {
  FUN_080bf754(p);
  CoffinShop_SetupBg(p);
  CoffinShop_LoadBgPltt(p);
  FUN_080bf494(p);
  CoffinShop_SetupMessageWindow(p);
  CoffinShop_ReadScriptID(p);
  p->unk_10e1 = 0;
  p->unk_10e2 = 0;
  FUN_0823ce68(2, 5, 4, 4, 4, 0xFFFF, 0);
  FUN_080bf3a0(p);
  PlaySound_082406e0(0x118);
  CoffinShop_SetState(p, FUN_080bf828);
  return 0;
}

CoffinShop* CoffinShop_Create(void) {
  CoffinShop* p = CreateEntity(ENTITY_UNK_11, sizeof(CoffinShop));

  if (p != NULL) {
    SetEntityRoutine(p, CoffinShop_Update, CoffinShop_Destroy);
    if (CoffinShop_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
