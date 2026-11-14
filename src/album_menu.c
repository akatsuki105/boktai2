#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

typedef struct {
  Entity e;                       // 0x0, ENTITY_UNK_8
  Tilemaps* tilemap;              // 0x18, TILEMAP_4F8F
  rgb555* pltt;                   // 0x1C, BGP_A41A のパレット
  u32 frameCounter;               // 0x020, フレームカウンタ (多分カーソルの点滅とかで使う)
  u8 page;                        // 0x024, 現在のページ (0: ページ1, 1: ページ2, 2: ページ3)
  u8 cursor;                      // 0x025, 現在のカーソルの位置番号, = (cursorY * 5) + cursorX
  u8 cursorX;                     // 0x026, 現在のカーソルのX位置 (0..4)
  u8 cursorY;                     // 0x027, 現在のカーソルのY位置 (0..1)
  MainSpriteGfx gfx1;             // 0x028
  MainSprite sprites_48[2];       // 0x048
  MainSprite sprites_108[5];      // 0x108
  MainSprite sprites_2e8[2];      // 0x2E8
  MainSprite sprites_3a8[2];      // 0x3A8
  MainSpriteGfx gfx2;             // 0x468
  MainSprite sprites_488[5 * 2];  // 0x488
  rgb555 cursorPltt[16];          // 0x848, カーソルのパレットの写し, [12] を unk_868 の位相で明滅させる
  s16 unk_868;                    // 0x868, 0..49 を回るカウンタ
  bool16 closed;                  // 0x86A, B で閉じたら TRUE, 以降は入力を見ない
  s32 panelID;                    // 0x86C, TextPanel_Create の戻り値, _Destroy が TextPanel_Hide に渡す
  u8* scriptPc;                   // 0x870, TextPanel_SetScript に渡す本文の位置
  u8* foundText;                  // 0x874, '.m', 取得済みの写真の説明文
  u8* unknownText;                // 0x878, '.h', 未取得の写真の説明文
  s32 closeScriptID;              // 0x87C, '.e'
} AlbumMenu;
static_assert(sizeof(AlbumMenu) == 2176);

const u8 gAlbumPhotoSlotCounts[3] = {10, 10, 7};  // アルバムの各ページのブロマイドスロット数

// 写真ごとの MainSprite のポーズ番号, 添字は写真の番号
const u32 gAlbumPhotoPoses[27] = {0, 1, 2, 3, 5, 6, 4, 7, 8, 29, 9, 10, 11, 12, 13, 14, 15, 16, 21, 22, 23, 17, 18, 20, 19, 24, 25};  // 0x085AF9B4

void UNUSED UnlockPhoto(u32 photoIdx) { SET_BIT(gStat->photo, photoIdx); }

u32 CheckPhotoUnlocked(u32 photoIdx) { return gStat->photo & (1 << photoIdx); }

// '.i' が指すブロマイドを取得済みにする
void Cmd_UnlockPhoto(void) {
  if (VM_SeekToNamedArg('i')) {
    SET_BIT(gStat->photo, VM_GetValue());
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

u32 AlbumMenu_GetPhotoPose(u32 n) { return n; }

// そのページより前のページに入る枚数の合計
s32 AlbumMenu_GetPage1stPhoto(s32 page) {
  s32 total = 0;
  s32 i;

  for (i = 0; i < page; i++) {
    total += AlbumMenu_GetPhotoSlotCount(i);
  }
  return total;
}

// カーソル位置が実際に写真のあるマスか
bool32 AlbumMenu_CheckCursorPos(s32 x, s32 y, s32 page) {
  if (x < 0 || x > 4) {
    return FALSE;
  }
  if (y < 0) {
    return FALSE;
  }
  if (y > 1) {
    return FALSE;
  }
  if (AlbumMenu_GetPhotoSlotCount(page) < x + 1 + y * 5) {
    return FALSE;
  }
  return TRUE;
}

// 27枚以上集まっているか
bool32 FUN_082111b8(void) { return CountUnlockedPhotos() > 26; }

// カーソル位置の写真の説明をテキストパネルに出す
// 残差は文字列IDの加算のオペランド順だけ (57/57), 原典は戻り値 + cursor の順で戻り値を別レジスタに写す
// 戻り値 + cursor の順 (55/57), 戻り値をローカルに受ける形 (55/57) は試済
NON_MATCH void AlbumMenu_ShowDescription(AlbumMenu* p) {
#ifdef NONMATCHING_C
  if (CheckPhotoUnlocked(p->cursor)) {
    TextPanel_SetScript(p->panelID, p->scriptPc);
    TextPanel_SetMessage(p->panelID, p->cursor);
    TextPanel_Start(p->panelID);
    Marquee_Clear();
    Marquee_SetText(GetStringByID(p->cursor + VM_ParseStringRef(p->foundText)));
  } else {
    TextPanel_SetScript(p->panelID, p->scriptPc);
    TextPanel_SetMessage(p->panelID, 27);
    TextPanel_Start(p->panelID);
    Marquee_Clear();
    Marquee_SetText(GetStringByID(p->cursor + VM_ParseStringRef(p->unknownText)));
  }
#else
  INCFUNC("asm/func/AlbumMenu_ShowDescription.inc");
#endif
}

// 取得数 "n/27" の数字を並べる
void AlbumMenu_DrawCount(AlbumMenu* p) {
  MainSprite_SetNumber(&p->sprites_108[0], &p->gfx1, CountUnlockedPhotos(), 2, 0, 176, 104, 8, 0);
  MainSprite_SetPose(&p->sprites_108[2], &p->gfx1, 11, PLAYMODE_PAUSE);
  p->sprites_108[2].pos.x = 192;
  p->sprites_108[2].pos.y = 104;
  p->sprites_108[2].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetNumber(&p->sprites_108[3], &p->gfx1, 27, 2, 0, 200, 104, 8, 0);
}

// カーソルのスプライトをマス目に合わせて置き直す
void AlbumMenu_PlaceCursor(AlbumMenu* p) {
  MainSprite* cursor = &p->sprites_48[1];

  cursor->pos.x = p->cursorX * 40;
  cursor->pos.y = p->cursorY * 40;
}

// 50フレーム周期でカーソルの明るさを進める
void AlbumMenu_BlinkCursor(AlbumMenu* p) {
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
  p->cursorPltt[12] = level;
}

// ページ見出しを差し替え、全枚数が揃っていれば追加の2枚を出す
void AlbumMenu_UpdatePageTitle(AlbumMenu* p) {
  s32 i;

  MainSprite_SetPose(&p->sprites_48[0], &p->gfx1, p->page + 30, PLAYMODE_PAUSE);
  if (FUN_082111b8()) {
    for (i = 0; i < 2; i++) {
      MainSprite_ClearFlags(&p->sprites_2e8[i], SPRFLAG_HIDDEN);
    }
  } else {
    for (i = 0; i < 2; i++) {
      MainSprite_SetFlags(&p->sprites_2e8[i], SPRFLAG_HIDDEN);
    }
  }
}

#ifdef NONMATCHING_C
static inline void Vec3_Set(Vec3* v, s32 x, s32 y, s32 z) {
  v->x = x;
  v->y = y;
  v->z = z;
}

static inline void Vec3_Set4(Vec3* v, s32 x, s32 y, s32 z, s32 val) {
  v->x = x;
  v->y = y;
  v->z = z;
  v->val = val;
}
#endif

// ページ見出し, カーソル, 枚数, 完成マーク, 写真20枠, ページ送りの矢印を並べる
// 残差はループ変数とループ内の座標のレジスタの入れ替わりだけ (286/286)
// pos を &pos 経由の inline で書くと元と同じ strh 4本になる (WeaponDexMenu_InitSprites と同じ壁), 座標の式の順, ループ変数の宣言順は試済
NON_MATCH void AlbumMenu_InitSprites(AlbumMenu* p) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* f;
  Vec3 pos;
  MainSprite* photo;
  s32 i;
  s32 j;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_GALLERY);
  p->gfx1 = *f;
  OpenMainSpriteFile(&p->gfx1, f);

  Vec3_Set4(&pos, 0, 0, 0, 0);
  MainSprite_Add(&p->sprites_48[0], &p->gfx1, 30, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 1, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  Vec3_Set4(&pos, 0, 0, 0, 0);
  MainSprite_Add(&p->sprites_48[1], &p->gfx1, 33, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  CpuCopy32(p->sprites_48[1].pltt, p->cursorPltt, sizeof(p->cursorPltt));
  p->sprites_48[1].pltt = p->cursorPltt;

  for (i = 0; i < 5; i++) {
    Vec3_Set(&pos, i * 8 + 176, 104, 0);
    MainSprite_Add(&p->sprites_108[i], &p->gfx1, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
    p->sprites_108[i].flags |= SPRFLAG_HIDDEN;
  }

  Vec3_Set4(&pos, 0, 0, 0, 0);
  MainSprite_Add(&p->sprites_2e8[0], &p->gfx1, 13, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  p->sprites_2e8[0].flags |= SPRFLAG_HIDDEN;
  Vec3_Set4(&pos, 160, 0, 0, 0);
  MainSprite_Add(&p->sprites_2e8[1], &p->gfx1, 13, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  p->sprites_2e8[1].flags |= SPRFLAG_HIDDEN;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_PORTRAITS);
  p->gfx2 = *f;
  OpenMainSpriteFile(&p->gfx2, f);
  photo = p->sprites_488;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 5; j++) {
      Vec3_Set4(&pos, j * 40 + 24, i * 40 + 24, 0, 0);
      MainSprite_Add(photo, &p->gfx2, AlbumMenu_GetPhotoPose(p->cursor), SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
      photo->flags |= SPRFLAG_HIDDEN;
      photo++;
    }
  }

  Vec3_Set(&pos, 0, 0, 0);
  MainSprite_Add(&p->sprites_3a8[0], &p->gfx1, 34, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
  MainSprite_Add(&p->sprites_3a8[1], &p->gfx1, 35, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_ONCE_AND_STOP, 60, &pos);
#else
  INCFUNC("asm/func/AlbumMenu_InitSprites.inc");
#endif
}

// アルバムの BG とパレットを用意し, ページの写真の数だけマスを塗る
void AlbumMenu_SetupPageBG(AlbumMenu* p) {
  s32 bgIndex = 3;
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
  count = AlbumMenu_GetPhotoSlotCount(p->page);
  for (row = 0; row < 2; row++) {
    for (col = 0; col < 5; col++) {
      BgState* bg = &gBgStates[3];

      bg->width16 = 16;
      bg->hofs = 0;
      bg->vofs = 0;
      Video_FillBGRect(0, col * 5 + 3, row * 5 + 3, 4, 4, 2, 0, 0);
      n++;
      if (n >= count) {
        return;
      }
    }
  }
}

// ページ内の写真アイコンを並べ、未取得の枠と余った枠は隠す
void AlbumMenu_RefreshPhotos(AlbumMenu* p) {
  s32 count = AlbumMenu_GetPhotoSlotCount(p->page);
  s32 first = AlbumMenu_GetPage1stPhoto(p->page);
  MainSprite* photo = p->sprites_488;
  s32 i;

  for (i = 0; i < count; photo++, i++) {
    if (CheckPhotoUnlocked(first + i)) {
      MainSprite_SetPose(photo, &p->gfx2, gAlbumPhotoPoses[first + i], PLAYMODE_PAUSE);
      photo->flags &= ~SPRFLAG_HIDDEN;
    } else {
      photo->flags |= SPRFLAG_HIDDEN;
    }
  }
  for (; i < 10; photo++, i++) {
    photo->flags |= SPRFLAG_HIDDEN;
  }
}

// ページを切り替えて並べ直す
void AlbumMenu_SetPage(AlbumMenu* p, u32 page) {
  p->page = page;
  AlbumMenu_SetupPageBG(p);
}

s32 AlbumMenu_Update(AlbumMenu* p) {
  bool32 moved;
  bool32 pageChanged;

  if (p->closed) {
    return 0;
  }

  moved = FALSE;
  pageChanged = FALSE;
  if ((gInput[0].pressed & DPAD_UP) && AlbumMenu_CheckCursorPos(p->cursorX, p->cursorY - 1, p->page)) {
    p->cursorY--;
    moved = TRUE;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if ((gInput[0].pressed & DPAD_DOWN) && AlbumMenu_CheckCursorPos(p->cursorX, p->cursorY + 1, p->page)) {
    p->cursorY++;
    moved = TRUE;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if ((gInput[0].pressed & DPAD_LEFT) && AlbumMenu_CheckCursorPos(p->cursorX - 1, p->cursorY, p->page)) {
    p->cursorX--;
    moved = TRUE;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if ((gInput[0].pressed & DPAD_RIGHT) && AlbumMenu_CheckCursorPos(p->cursorX + 1, p->cursorY, p->page)) {
    p->cursorX++;
    moved = TRUE;
    PlaySound_082406e0(SE_CURSOR_MOVE);
  }

  if (gInput[0].pressed & L_BUTTON) {
    if (p->page != 0) {
      p->page--;
    } else {
      p->page = 2;
    }
    pageChanged = TRUE;
    p->cursorX = 0;
    p->cursorY = 0;
    moved = TRUE;
    PlaySound_082406e0(SE_MENU_PAGE);
  } else if (gInput[0].pressed & R_BUTTON) {
    if (p->page < 2) {
      p->page++;
    } else {
      p->page = 0;
    }
    pageChanged = TRUE;
    p->cursorX = 0;
    p->cursorY = 0;
    moved = TRUE;
    PlaySound_082406e0(SE_MENU_PAGE);
  }

  if (moved || pageChanged) {
    p->cursor = AlbumMenu_GetPage1stPhoto(p->page) + p->cursorX + p->cursorY * 5;
    if (pageChanged) {
      AlbumMenu_UpdatePageTitle(p);
      AlbumMenu_SetupPageBG(p);
      AlbumMenu_RefreshPhotos(p);
      AlbumMenu_DrawCount(p);
    }
  }
  if (moved) {
    AlbumMenu_PlaceCursor(p);
    AlbumMenu_ShowDescription(p);
  }

  if (gInput[0].pressed & B_BUTTON) {
    if (p->closeScriptID != 0) {
      VM_ExecByID(p->closeScriptID, NULL);
    }
    PlaySound_082406e0(SE_CLOSE_MENU);
    p->closed = TRUE;
  }

  AlbumMenu_BlinkCursor(p);
  p->frameCounter++;
  return 0;
}

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
  Marquee_CloseGlobal();
  SetBGPrioDirect(0, 0);
  return 0;
}

s32 AlbumMenu_Init(AlbumMenu* p, u32 n) {
  p->frameCounter = 0;
  p->page = 0;
  p->cursor = 0;
  p->cursorX = 0;
  p->cursorY = 0;
  p->unk_868 = 0;
  AlbumMenu_SetPage(p, 0);
  p->closed = 0;
  AlbumMenu_InitSprites(p);
  AlbumMenu_RefreshPhotos(p);
  AlbumMenu_DrawCount(p);
  AlbumMenu_UpdatePageTitle(p);

  if (!VM_SeekToNamedArg('m') || (p->foundText = VM_GetPC_Proxy()) == NULL || !VM_SeekToNamedArg('n') || (p->scriptPc = VM_GetPC_Proxy()) == NULL || !VM_SeekToNamedArg('h') || (p->unknownText = VM_GetPC_Proxy()) == NULL) {
    return -1;
  }
  p->closeScriptID = VM_GetNamedArgValue('e', 0);

  p->panelID = TextPanel_Create(1, 16, 29, 4);
  FUN_08049f5c();
  Marquee_Clear();
  AlbumMenu_ShowDescription(p);
  StartBgObjPlttFade(0, 4, 4, 4, 4, 0xFFFF, 0);
  PlaySound_082406e0(SE_OPEN_MENU);
  return 0;
}

// 0x52BF
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
