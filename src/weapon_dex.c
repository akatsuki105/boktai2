#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "preview_stage.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"

typedef struct {
  MainSpriteGfx gfx;        // 0x00
  MainSprite icons[5 * 4];  // 0x20
} WeaponIconSprites;

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_8
  Tilemaps* tilemap;            // 0x018, TILEMAP_4F8F
  rgb555* pltt;                 // 0x01C, BGP_A41A
  u32 frameCounter;             // 0x020
  u8 page;                      // 0x024, 0: 剣, 1: 槍, 2: ハンマー, 3: 銃
  weapon8_t selected;           // 0x025, カーソル位置の武器, 未登録でも ID が入る
  u8 cursorX;                   // 0x026, 0..4
  u8 cursorY;                   // 0x027, 0..3
  MainSpriteGfx gfx;            // 0x028, SPRITE_UI_GALLERY
  MainSprite pageTitle;         // 0x048, ページ見出し, pose は page + 25
  MainSprite cursor;            // 0x0A8
  MainSprite countSprites[5];   // 0x108, "登録数 / 総数"
  MainSprite completeMarks[2];  // 0x2E8, ページが全部埋まったら出す
  MainSprite spr_3a8;           // 0x3A8
  MainSprite spr_408;           // 0x408
  WeaponIconSprites icons;      // 0x468, SPRITE_INVENTORY_ICONS
  MainSprite selectedIcon;      // 0xC08, カーソル位置の武器のアイコン
  rgb555 cursorPltt[16];        // 0xC68, cursor のパレットの複製, [12] を明滅させる
  u16 cursorBlinkTimer;         // 0xC88, 0..49 を回る
  u8 unk_c8a;                   // 0xC8A
  u8 unk_c8b;                   // 0xC8B
  AuxSprite spr_c8c;            // 0xC8C, preview の足元に置く
  AuxSpriteGfx gfx_cb8;         // 0xCB8, SPRITE_EFF_1C1B
  SpriteHolder preview;         // 0xCD4, SPRITE_DJANGO_SABATA
  rgb555 previewPltt[16];       // 0xD68, preview のパレットの複製, 5/6/13 番を差し替える
  u8 previewStep;               // 0xD88, プレビューの演技の段
  u8 previewTimer;              // 0xD89, 今の段に入ってからのフレーム数
  bool8 previewReset;           // 0xD8A, 立っていたらプレビューを最初の段からやり直す
  u8 unk_d8b;                   // 0xD8B
  u8* foundText;                // 0xD8C, '.w', 登録済みの武器の説明, 武器 ID の行を出す
  u8* unknownText;              // 0xD90, '.u', 未登録の武器の代わりに出す文
  u32 closeScriptID;            // 0xD94, '.e', 図鑑を閉じる時に実行するスクリプト, 0 なら無し
  bool32 closed;                // 0xD98
  char extValue[8];             // 0xD9C, メッセージ窓の埋め込み値 0 番
} WeaponDexMenu;
static_assert(sizeof(WeaponDexMenu) == 3492);

static const u8 sWeaponDexItemCounts[4] = {19, 19, 19, 3};  // 0x085af9ac, 武器図鑑の各ページのエントリ数

bool32 IsWeaponAlreadyFound(weapon32_t n);
void FUN_08094d48(unknown* w, u8* pc);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
s32 GetWeaponWearPose(WeaponData* w);
void FUN_08210bb0(WeaponDexMenu* p);

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

// カーソル位置がそのページに実在するマスか
bool32 WeaponDexMenu_CheckCursorPos(s32 x, s32 y, s32 page) {
  if (x < 0 || x > 4) {
    return FALSE;
  }
  if (y < 0) {
    return FALSE;
  }
  if (y > 3) {
    return FALSE;
  }
  if (WeaponDexMenu_GetPageEntryCount(page) < x + 1 + y * 5) {
    return FALSE;
  }
  return TRUE;
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

// 武器種 kind の色をプレビュー用パレットに差し込む
void WeaponDexMenu_SetPreviewColors(WeaponDexMenu* p, s32 kind) {
  rgb555* src = &gObjPlttData[40 * 16];
  MainSprite* sprite;

  src += kind * 3;
  p->previewPltt[5] = *src++;
  p->previewPltt[6] = *src++;
  p->previewPltt[13] = *src++;
  sprite = &p->preview.u.main.sprite;
  sprite->pltt = p->previewPltt;
}

// プレビューの主人公にページごとの武器の型を順に演じさせる
// 462/535命令, 中身が同じ case (page 0 の 1 と 3 など) がこちらでは相互ジャンプで1つにまとまる, 原典は reload の一時レジスタの回り方が case ごとにずれて別々に残る
// こちらは冒頭の &p->previewTimer が r8 に残り page 1-3 で使い回される, 原典は毎回作り直す, 試済: first = (p->previewTimer++ == 0)
NON_MATCH void WeaponDexMenu_UpdatePreview(WeaponDexMenu* p) {
#ifdef NONMATCHING_C
  bool32 first;

  if (p->previewReset) {
    p->previewStep = 0;
    p->previewTimer = 0;
    p->previewReset = 0;
  }
  first = (p->previewTimer == 0);
  p->previewTimer++;

  switch (p->page) {
    case 0: {
      switch (p->previewStep) {
        case 0: {
          if (first) {
            WeaponDexMenu_SetPreviewColors(p, 0);
            SpriteHolder_SetAnim(&p->preview, 3, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 1: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 112, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 2: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 117, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 3: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 112, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 4: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 122, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            SpriteHolder_SetAnim(&p->preview, 122, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          break;
        }
      }
      break;
    }
    case 1: {
      switch (p->previewStep) {
        case 0: {
          if (first) {
            WeaponDexMenu_SetPreviewColors(p, 0);
            SpriteHolder_SetAnim(&p->preview, 3, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 1: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 132, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 2: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 147, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 3: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 132, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            SpriteHolder_SetAnim(&p->preview, 132, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          break;
        }
      }
      break;
    }
    case 2: {
      switch (p->previewStep) {
        case 0: {
          if (first) {
            WeaponDexMenu_SetPreviewColors(p, 0);
            SpriteHolder_SetAnim(&p->preview, 3, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 1: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 152, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 2: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 162, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 3: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 157, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            SpriteHolder_SetAnim(&p->preview, 157, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          break;
        }
      }
      break;
    }
    case 3: {
      switch (p->previewStep) {
        case 0: {
          if (first) {
            WeaponDexMenu_SetPreviewColors(p, 8);
            SpriteHolder_SetAnim(&p->preview, 3, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 1: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 82, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 2: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 92, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            p->previewTimer = 0;
            p->previewStep++;
          }
          break;
        }
        case 3: {
          if (first) {
            SpriteHolder_SetAnim(&p->preview, 87, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          if (SpriteHolder_IsAnimEnded(&p->preview)) {
            SpriteHolder_SetAnim(&p->preview, 87, 0, TRUE, PLAYMODE_ONCE_AND_STOP, 0, MAIN_ANIM_FORCE_POSE);
          }
          break;
        }
      }
      break;
    }
  }
  SpriteHolder_AdvanceAnim(&p->preview);
#else
  INCFUNC("asm/func/WeaponDexMenu_UpdatePreview.inc");
#endif
}

// カーソル位置の武器の説明を出す, 未登録なら代わりの文を出す
void WeaponDexMenu_ShowDescription(WeaponDexMenu* p) {
  if (IsWeaponAlreadyFound(p->selected)) {
    MainSprite* sprite;
    s32 pose;

    MessageWindow_Start(p->foundText);
    p->extValue[0] = '\0';
    MessageWindow_ShowLine(p->selected);
    MessageWindow_SetExtendValue(0, p->extValue);
    Marquee_Clear();
    FUN_08094d48((unknown*)&gWeaponDB[p->selected], p->foundText);
    p->unk_c8a |= 4;
    p->unk_c8a &= ~2;
    pose = GetWeaponWearPose((WeaponData*)&gWeaponDB[p->selected]);
    sprite = &p->selectedIcon;
    MainSprite_SetPose(sprite, &p->icons.gfx, pose, PLAYMODE_LOOP);
    sprite->flags &= ~SPRFLAG_HIDDEN;
  } else {
    MessageWindow_Start(p->unknownText);
    MessageWindow_ShowLine(0);
    MessageWindow_SetInstant(TRUE);
    Marquee_Clear();
    p->unk_c8a |= 2;
  }
}

// "登録数 / 総数" を描画
void FUN_08210610(WeaponDexMenu* p) {
  MainSprite_SetNumber(&p->countSprites[0], &p->gfx, WeaponDexMenu_CountFoundInPage(p->page), 2, 0, 32, 96, 8, 0);  // 登録数
  p->countSprites[2].pos.x = 48;
  p->countSprites[2].pos.y = 96;
  MainSprite_SetPose(&p->countSprites[2], &p->gfx, 11, PLAYMODE_PAUSE);                                              // "/"
  MainSprite_SetNumber(&p->countSprites[3], &p->gfx, WeaponDexMenu_GetPageEntryCount(p->page), 2, 0, 56, 96, 8, 0);  // 総数
}

void FUN_082106a4(WeaponDexMenu* p) {
  MainSprite* cursor = &p->cursor;
  cursor->pos.x = p->cursorX * 24;
  cursor->pos.y = p->cursorY * 24;
}

// 50フレーム周期でカーソルの明るさを進める
void FUN_082106c8(WeaponDexMenu* p) {
  u16 level;

  if (p->cursorBlinkTimer <= 9) {
    level = 31;
  } else if (p->cursorBlinkTimer <= 17) {
    level = 27;
  } else if (p->cursorBlinkTimer <= 25) {
    level = 18;
  } else if (p->cursorBlinkTimer <= 33) {
    level = 10;
  } else if (p->cursorBlinkTimer <= 41) {
    level = 18;
  } else {
    level = 27;
  }
  p->cursorBlinkTimer++;
  if (p->cursorBlinkTimer > 49) {
    p->cursorBlinkTimer = 0;
  }
  p->cursorPltt[12] = level;
}

// ページ見出しを差し替え、そのページが埋まっていれば追加の2枚を出す
void FUN_08210718(WeaponDexMenu* p) {
  s32 i;

  MainSprite_SetPose(&p->pageTitle, &p->gfx, p->page + 25, PLAYMODE_PAUSE);
  if (WeaponDexMenu_IsPageComplete(p->page)) {
    for (i = 0; i < 2; i++) {
      MainSprite_ClearFlags(&p->completeMarks[i], SPRFLAG_HIDDEN);
    }
  } else {
    for (i = 0; i < 2; i++) {
      MainSprite_SetFlags(&p->completeMarks[i], SPRFLAG_HIDDEN);
    }
  }
}

// UI, 武器アイコン20枠, プレビューの主人公と影
// 351/356命令, 原典の Vec3 pos/pos2 は最初のストアから strh 4本 (こちらは &pos が出る前の DImode 疑似レジスタで 32bit ストアに畳まれる), 行ループの y = i*24+24 も原典は強度削減されない
// 試済: Vec3* 経由の書き込み (strh にはなるが p が r10 に出てフレーム 0x34), Vec3 pos[2], (i+1)*24, Vec3_Set 系 inline
NON_MATCH s32 WeaponDexMenu_InitSprites(WeaponDexMenu* p) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* f;
  Vec3 pos;
  Vec3 pos2;
  MainSprite* icon;
  s32 i;
  s32 j;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_GALLERY);
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);

  pos.x = 0, pos.y = 0, pos.z = 0, pos.val = 0;
  MainSprite_Add(&p->pageTitle, &p->gfx, 25, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  pos.x = 0, pos.y = 0, pos.z = 0, pos.val = 0;
  MainSprite_Add(&p->cursor, &p->gfx, 29, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  CpuCopy32(p->cursor.pltt, p->cursorPltt, sizeof(p->cursorPltt));
  p->cursor.pltt = p->cursorPltt;

  pos.x = 0, pos.y = 0, pos.z = 0, pos.val = 0;
  MainSprite_Add(&p->completeMarks[0], &p->gfx, 13, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  p->completeMarks[0].flags |= SPRFLAG_HIDDEN;
  pos.x = 160, pos.y = 0, pos.z = 0, pos.val = 0;
  MainSprite_Add(&p->completeMarks[1], &p->gfx, 13, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  p->completeMarks[1].flags |= SPRFLAG_HIDDEN;

  pos.x = 0, pos.y = 0, pos.z = 0;
  MainSprite_Add(&p->spr_3a8, &p->gfx, 34, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  MainSprite_Add(&p->spr_408, &p->gfx, 35, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  p->icons.gfx = *f;
  OpenMainSpriteFile(&p->icons.gfx, f);
  icon = p->icons.icons;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 5; j++) {
      pos.x = j * 24 + 112, pos.y = i * 24 + 24, pos.z = 0, pos.val = 0;
      MainSprite_Add(icon, &p->icons.gfx, 29, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
      icon->flags |= SPRFLAG_HIDDEN;
      icon++;
    }
  }
  FUN_08210bb0(p);

  pos2.x = 0, pos2.y = 128, pos2.z = 0;
  MainSprite_Add(&p->selectedIcon, &p->icons.gfx, 29, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos2);

  CpuFill32(0, &pos, sizeof(Vec3));
  for (i = 0; i < 5; i++) {
    MainSprite_Add(&p->countSprites[i], &p->gfx, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  }
  FUN_08210610(p);

  pos.x = 54, pos.y = 72, pos.z = 0;
  if (SpriteHolder_InitMain(&p->preview, SPRITE_DJANGO_SABATA, SPRFLAG_SCREEN_COORD, &pos) < 0) {
    return -1;
  }
  SpriteHolder_SetPriority(&p->preview, 3);
  CpuCopy32(p->preview.u.main.sprite.pltt, p->previewPltt, sizeof(p->previewPltt));
  p->preview.u.main.sprite.pltt = p->previewPltt;

  Video_GetAuxSprite(&p->gfx_cb8, SPRITE_EFF_1C1B);
  AuxSprite_Add(&p->spr_c8c, &p->gfx_cb8, SPRFLAG_AFFINE | SPRFLAG_SCREEN_COORD | SPRFLAG_BLINK_ODD);
  AuxSprite_SetPoseIdx(&p->spr_c8c, 5);
  p->spr_c8c.priority = 3;
  p->spr_c8c.pos.x = p->preview.pos->x;
  p->spr_c8c.pos.y = p->preview.pos->y;
  p->spr_c8c.pos.z = p->preview.pos->z;
  p->spr_c8c.scaleX = 64;
  p->spr_c8c.scaleY = 64;
#else
  INCFUNC("asm/func/WeaponDexMenu_InitSprites.inc");
#endif
}

// 図鑑の BG とパレットを用意し, ページの武器の数だけマスを塗る
void WeaponDexMenu_SetupPageBG(WeaponDexMenu* p) {
  s32 bgIndex = 2;
  BgPlttFile* f;
  s32 n;
  s32 row;
  s32 count;
  s32 col;

  ClearBGTilemapBuffer(0);
  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_4F8F);
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &bgIndex);
  SetBGPrioDirect(0, 3);
  Video_GenerateBGMap(0, 0, 0, 0, 0);

  f = GetBgPlttFile(BGP_A41A);
  p->pltt = f->body;
  CpuCopy16(&f->body[208], &gBgPlttBuffer[208], 48 * sizeof(rgb555));

  n = 0;
  count = WeaponDexMenu_GetPageEntryCount(p->page);
  for (row = 0; row < 4; row++) {
    for (col = 0; col < 5; col++) {
      BgState* bg = &gBgStates[3];

      bg->width16 = 16;
      bg->hofs = 0;
      bg->vofs = 0;
      Video_FillBGRect(0, col * 3 + 14, row * 3 + 3, 2, 2, 2, 0, 0);
      n++;
      if (n >= count) {
        return;
      }
    }
  }
  WeaponDexMenu_ShowDescription(p);
}

// ページ内の武器アイコンを並べ、未登録の枠と余った枠は隠す
void FUN_08210bb0(WeaponDexMenu* p) {
  s32 count = WeaponDexMenu_GetPageEntryCount(p->page);
  MainSprite* icon = p->icons.icons;
  weapon32_t first = WeaponDexMenu_GetPage1stEntry(p->page);
  s32 i;

  for (i = 0; i < count; icon++, i++) {
    if (IsWeaponAlreadyFound(first + i)) {
      MainSprite_SetPose(icon, &p->icons.gfx, FUN_0820fee8(first + i), PLAYMODE_PAUSE);
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
      p->pageTitle.flags &= ~SPRFLAG_HIDDEN;
      p->cursor.flags &= ~SPRFLAG_HIDDEN;
      break;
    }
    case 1: {
      p->pageTitle.flags &= ~SPRFLAG_HIDDEN;
      p->cursor.flags &= ~SPRFLAG_HIDDEN;
      break;
    }
    case 2: {
      p->pageTitle.flags &= ~SPRFLAG_HIDDEN;
      p->cursor.flags &= ~SPRFLAG_HIDDEN;
      break;
    }
    case 3: {
      p->pageTitle.flags &= ~SPRFLAG_HIDDEN;
      p->cursor.flags &= ~SPRFLAG_HIDDEN;
      break;
    }
  }
}

// ページを切り替えてアイコンとカーソルを並べ直す
void FUN_08210c70(WeaponDexMenu* p, u32 page) {
  p->page = page;
  WeaponDexMenu_SetupPageBG(p);
  FUN_08210c3c(p);
}

// 十字キーでカーソル, L/R でページを動かし, B で図鑑を閉じる
s32 WeaponDexMenu_Update(WeaponDexMenu* p) {
  bool32 moved;
  bool32 pageChanged;

  if (p->closed) {
    return 0;
  }

  moved = FALSE;
  pageChanged = FALSE;
  if ((gInput[0].pressed & DPAD_UP) && WeaponDexMenu_CheckCursorPos(p->cursorX, p->cursorY - 1, p->page)) {
    p->cursorY--;
    moved = TRUE;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if ((gInput[0].pressed & DPAD_DOWN) && WeaponDexMenu_CheckCursorPos(p->cursorX, p->cursorY + 1, p->page)) {
    p->cursorY++;
    moved = TRUE;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if ((gInput[0].pressed & DPAD_LEFT) && WeaponDexMenu_CheckCursorPos(p->cursorX - 1, p->cursorY, p->page)) {
    p->cursorX--;
    moved = TRUE;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if ((gInput[0].pressed & DPAD_RIGHT) && WeaponDexMenu_CheckCursorPos(p->cursorX + 1, p->cursorY, p->page)) {
    p->cursorX++;
    moved = TRUE;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  }

  if (gInput[0].pressed & L_BUTTON) {
    if (p->page != 0) {
      p->page--;
    } else {
      p->page = 3;
    }
    pageChanged = TRUE;
    p->cursorX = 0;
    p->cursorY = 0;
    moved = TRUE;
    PlaySound_082406e0(SONG_266);
  } else if (gInput[0].pressed & R_BUTTON) {
    if (p->page < 3) {
      p->page++;
    } else {
      p->page = 0;
    }
    pageChanged = TRUE;
    p->cursorX = 0;
    p->cursorY = 0;
    moved = TRUE;
    PlaySound_082406e0(SONG_266);
  }

  if (moved) {
    p->selected = WeaponDexMenu_GetPage1stEntry(p->page) + p->cursorX + p->cursorY * 5;
  }
  if (pageChanged) {
    FUN_08210718(p);
    WeaponDexMenu_SetupPageBG(p);
    FUN_08210bb0(p);
    FUN_08210610(p);
    p->previewReset = 1;
  }
  if (moved) {
    FUN_082106a4(p);
    WeaponDexMenu_ShowDescription(p);
  }

  if (gInput[0].pressed & B_BUTTON) {
    if (p->closeScriptID != 0) {
      VM_ExecByID(p->closeScriptID, NULL);
    }
    PlaySound_082406e0(SE_CLOSE_MENU);
    p->closed = TRUE;
  }

  WeaponDexMenu_UpdatePreview(p);
  FUN_082106c8(p);
  p->frameCounter++;
  return 0;
}

s32 WeaponDexMenu_Destroy(WeaponDexMenu* p) {
  s32 i;

  MainSprite_Remove(&p->pageTitle);
  MainSprite_Remove(&p->cursor);
  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->countSprites[i]);
  }
  for (i = 0; i < 20; i++) {
    MainSprite_Remove(&p->icons.icons[i]);
  }
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->completeMarks[i]);
  }
  AuxSprite_Remove(&p->spr_c8c);
  MainSprite_Remove(&p->spr_3a8);
  MainSprite_Remove(&p->spr_408);
  SpriteHolder_Remove(&p->preview);
  MainSprite_Remove(&p->selectedIcon);
  SetBGPrioDirect(0, 0);
  Marquee_CloseGlobal();
  return 0;
}

s32 WeaponDexMenu_Init(WeaponDexMenu* p, u32 _) {
  p->frameCounter = 0;
  p->page = 0;
  p->selected = WEAPON_GRADIUS;
  p->cursorX = 0;
  p->cursorY = 0;
  p->previewStep = 0;
  p->previewTimer = 0;
  p->previewReset = 0;
  p->cursorBlinkTimer = 0;
  FUN_08210c70(p, 0);
  p->closed = FALSE;
  p->unk_c8a = 0;
  WeaponDexMenu_InitSprites(p);
  FUN_08210718(p);

  if (!VM_SeekToNamedArg('u') || (p->unknownText = VM_GetPC_Proxy()) == NULL || !VM_SeekToNamedArg('w') || (p->foundText = VM_GetPC_Proxy()) == NULL) {
    return -1;
  }
  p->closeScriptID = VM_GetNamedArgValue('e', 0);

  FUN_0823ce68(0, 4, 4, 4, 4, 0xFFFF, 0);
  PlaySound_082406e0(SE_OPEN_MENU);
  Marquee_Clear();
  FUN_08049f5c();
  p->unk_c8a = 0;
  MessageWindow_SetInstant(TRUE);
  MessageWindow_Start(p->foundText);
  MessageWindow_SetRect(2, 16, 28, 2);
  WeaponDexMenu_ShowDescription(p);
  return 0;
}

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
  p->previewTimer = 0;
  p->previewStep++;
}
