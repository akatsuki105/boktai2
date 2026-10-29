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

// solar_bank.c と同形

// 暗黒ローンのメニュー(太陽バンクや暗黒カードは別)
typedef struct DarkLoans {
  Entity e;                                   // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx0;                         // 0x018, SPRITE_UI_DARKLOAN
  MainSpriteGfx gfx1;                         // 0x038
  MainSprite sprites[20];                     // 0x058
  AuxSprite auxSprite;                        // 0x7D8
  AuxSpriteGfx auxGfx;                        // 0x804
  TilemapFile* tilemap;                       // 0x820, TILEMAP_C091
  rgb555* pltt;                               // 0x824, BGP_EAA8 の body[208]
  u8* script;                                 // 0x828, MessageWindow_Start に渡す本文
  u16 unk_82c;                                // 0x82C
  u16 unk_82e;                                // 0x82E
  u32 unk_830;                                // 0x830, '.d'
  u32 unk_834;                                // 0x834, '.e'
  u16 unk_838;                                // 0x838
  u16 unk_83a;                                // 0x83A
  u16 unk_83c;                                // 0x83C
  u16 unk_83e;                                // 0x83E
  u16 unk_840;                                // 0x840
  u16 unk_842;                                // 0x842, はい/いいえ の選択, 1 ならはい
  u16 unk_844;                                // 0x844, DarkLoans_SetUpdate が updateCallback を差し替えるときに 0 に戻す
  bool16 unk_846;                             // 0x846, '.o', 0 なら FUN_080b4b04、それ以外は FUN_080b4e8c を呼ぶ
  u16 unk_848;                                // 0x848
  u16 unk_84a;                                // 0x84A
  void (*updateCallback)(struct DarkLoans*);  // 0x84C, DarkLoans_Update が毎フレーム呼ぶ
} DarkLoans;
static_assert(sizeof(DarkLoans) == 2128);

void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
void FUN_080b54ec(DarkLoans* p);
void FUN_080b539c(DarkLoans* p);
void FUN_080b5528(DarkLoans* p);
void dark_loans_080b5020(DarkLoans* p);
void FUN_080b4c5c(DarkLoans* p);
void FUN_080b4d98(DarkLoans* p);
void FUN_080b4f48(DarkLoans* p);
void FUN_080b4f08(DarkLoans* p);
void FUN_080b54a0(DarkLoans* p);
void FUN_080b5434(DarkLoans* p);

// 返済額 (darkDebts + 借りる額 * 利率) を4桁の数字スプライトで出す
void FUN_080b4818(DarkLoans* p) {
  s32 digits[4];
  s32 n = gStat->darkDebts + p->unk_82e * p->unk_82c;
  s32 i;

  if (n == 0) {
    for (i = 0; i < 4; i++) {
      digits[i] = 0;
    }
  } else {
    digits[0] = Div(n, 1000);
    n -= digits[0] * 1000;
    digits[1] = Div(n, 100);
    n -= digits[1] * 100;
    digits[2] = Div(n, 10);
    digits[3] = n - digits[2] * 10;
  }
  for (i = 0; i < 4; i++) {
    MainSprite_SetPose(&p->sprites[6 + i], &p->gfx1, digits[i] + 20, PLAYMODE_LOOP);
  }
}

// 借りる額と返済額をそれぞれ4桁の数字スプライトで出す
void dark_loans_080b48c8(DarkLoans* p) {
  s32 digits[4];
  s32 n = p->unk_82e;
  s32 i;

  if (n == 0) {
    for (i = 0; i < 4; i++) {
      digits[i] = 0;
    }
  } else {
    digits[0] = Div(n, 1000);
    n -= digits[0] * 1000;
    digits[1] = Div(n, 100);
    n -= digits[1] * 100;
    digits[2] = Div(n, 10);
    digits[3] = n - digits[2] * 10;
  }
  for (i = 0; i < 4; i++) {
    p->sprites[10 + i].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[10 + i], &p->gfx0, digits[i] + 8, PLAYMODE_LOOP);
  }
  p->sprites[14].flags &= ~SPRFLAG_HIDDEN;

  n = p->unk_82e * p->unk_82c;
  if (n == 0) {
    for (i = 0; i < 4; i++) {
      digits[i] = 0;
    }
  } else {
    digits[0] = Div(n, 1000);
    n -= digits[0] * 1000;
    digits[1] = Div(n, 100);
    n -= digits[1] * 100;
    digits[2] = Div(n, 10);
    digits[3] = n - digits[2] * 10;
  }
  for (i = 0; i < 4; i++) {
    p->sprites[15 + i].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[15 + i], &p->gfx0, digits[i] + 8, PLAYMODE_LOOP);
  }
}

// ENE ゲージの量に合わせてゲージ先端のスプライトを横に置く
void FUN_080b4a50(DarkLoans* p) {
  s32 ene = (s16)gStat->savedEne + p->unk_82e;
  s32 maxEne = (s16)gStat->savedMaxEne;
  s32 x;

  if (ene == 0) {
    x = 0;
  } else {
    x = Div((ene - 1) * 79, maxEne - 1) + 1;
  }
  p->sprites[19].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[19].pos.x = x - 152;
  p->sprites[19].pos.y = -40;
}

void FUN_080b4abc(DarkLoans* p) {
  s32 i;

  for (i = 0; i < 20; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
  p->auxSprite.flags |= SPRFLAG_HIDDEN;
}

// 毎フレーム呼ぶ処理を差し替える
void DarkLoans_SetUpdate(DarkLoans* p, void* fn) {
  p->updateCallback = fn;
  p->unk_844 = 0;
}

// 借りる前の最初の画面にする
void FUN_080b4b04(DarkLoans* p) {
  Video_SetBGLayer(0, p->tilemap, 3);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  FUN_080b4abc(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[0], &p->gfx0, 4, PLAYMODE_ONCE_AND_STOP, 0);
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
  MessageWindow_ShowLine(0);
  FUN_0823ce68(2, 5, 4, 4, 4, 0xFFFF, 0);
  DarkLoans_SetUpdate(p, FUN_080b4f08);
}

// 借りるかどうかの はい/いいえ 画面にする
void FUN_080b4ba4(DarkLoans* p) {
  Video_SetBGLayer(0, p->tilemap, 3);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  FUN_080b4abc(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[0], &p->gfx0, 7, PLAYMODE_ONCE_AND_STOP, 0);
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
  p->unk_842 = 1;
  p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[1], &p->gfx1, 4, PLAYMODE_LOOP, 0);
  MessageWindow_ShowLine(1);
  p->unk_82e = 0;
  DarkLoans_SetUpdate(p, FUN_080b4f48);
}

// 借りる額を選ぶ画面にする
void FUN_080b4c5c(DarkLoans* p) {
  s32 i;

  Video_SetBGLayer(0, p->tilemap, 4);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  FUN_080b4abc(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[0], &p->gfx0, 5, PLAYMODE_LOOP, 0);
  p->sprites[5].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[5], &p->gfx0, 18, PLAYMODE_LOOP);
  p->unk_82e = 0;
  for (i = 0; i < 4; i++) {
    p->sprites[6 + i].flags &= ~SPRFLAG_HIDDEN;
  }
  FUN_080b4818(p);
  FUN_080b4a50(p);
  p->sprites[14].flags &= ~SPRFLAG_HIDDEN;
  for (i = 0; i < 4; i++) {
    p->sprites[10 + i].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[15 + i].flags &= ~SPRFLAG_HIDDEN;
  }
  dark_loans_080b48c8(p);
  p->unk_848 = 0;
  p->unk_84a = 0;
  p->auxSprite.flags &= ~SPRFLAG_HIDDEN;
  Video_SetAuxSpritePltt(&p->auxGfx, 0x143);
  MessageWindow_ShowLine(4);
  p->unk_83a = 0;
  p->unk_83c = 0;
  p->unk_83e = 0;
  p->unk_840 = 0;
  p->unk_838 = 0;
  DarkLoans_SetUpdate(p, dark_loans_080b5020);
}

// 断ったときの画面にして閉じる待ちへ移る
void FUN_080b4d98(DarkLoans* p) {
  Video_SetBGLayer(0, p->tilemap, 5);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  FUN_080b4abc(p);
  PlaySound_082406e0(SONG_705);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[0], &p->gfx0, 6, PLAYMODE_ONCE_AND_STOP, 0);
  MessageWindow_ShowLine(3);
  DarkLoans_SetUpdate(p, FUN_080b539c);
}

// おしおき回数に応じた説明文を出して閉じる待ちへ移る
void FUN_080b4e04(DarkLoans* p) {
  Video_SetBGLayer(0, p->tilemap, 5);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  FUN_080b4abc(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  if (gStat->tortureCount <= 3) {
    MessageWindow_ShowLine(9);
  } else if (gStat->tortureCount <= 5) {
    MessageWindow_ShowLine(10);
  } else if (gStat->tortureCount <= 7) {
    MessageWindow_ShowLine(11);
  } else {
    MessageWindow_ShowLine(12);
  }
  DarkLoans_SetUpdate(p, FUN_080b54a0);
}

// '.o' が立っているときの開始画面にする
void FUN_080b4e8c(DarkLoans* p) {
  Video_SetBGLayer(0, p->tilemap, 5);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  FUN_080b4abc(p);
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[0], &p->gfx0, 6, PLAYMODE_ONCE_AND_STOP, 0);
  FUN_0823ce68(2, 5, 4, 4, 4, 0xFFFF, 0);
  MessageWindow_ShowLine(13);
  DarkLoans_SetUpdate(p, FUN_080b5528);
}

void FUN_080b4f08(DarkLoans* p) {
  MainSprite_AdvanceAnim(&p->sprites[0], &p->gfx0);
  if (p->unk_844 == 0x20) {
    PlaySound_082406e0(SONG_704);
  }
  p->unk_844++;
  if (p->unk_844 > 0x68) {
    FUN_080b4ba4(p);
  }
}

// はい/いいえ の入力待ち, A で決定, B で断る, 左右で切り替え
void FUN_080b4f48(DarkLoans* p) {
  MainSprite_AdvanceAnim(&p->sprites[0], &p->gfx0);
  if (gInput[0].pressed & A_BUTTON) {
    if (p->unk_842 != 0) {
      PlaySound_082406e0(SE_SELECT);
      FUN_080b4c5c(p);
    } else {
      PlaySound_082406e0(SE_CANCEL);
      FUN_080b4d98(p);
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b4d98(p);
  } else if (gInput[0].pressed & (DPAD_RIGHT | DPAD_LEFT)) {
    PlaySound_082406e0(SE_CURSOR_MOVE);
    p->unk_842 = 1 - p->unk_842;
    if (p->unk_842 != 0) {
      MainSprite_SetAnim(&p->sprites[1], &p->gfx1, 4, PLAYMODE_LOOP, 0);
    } else {
      MainSprite_SetAnim(&p->sprites[1], &p->gfx1, 5, PLAYMODE_LOOP, 0);
    }
  } else {
    MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx1);
  }
}

// 残差1命令 (19/18): agbcc は3ケースの switch を必ず中央 (case 2) 根で木にするが, 原典は case 1 根の一直線な木になる
NON_MATCH s32 FUN_080b4ffc(s32 val) {
#ifdef NONMATCHING_C
  switch (val >> 2) {
    case 1: {
      return 1;
    }
    case 2: {
      return 2;
    }
    case 3: {
      return 1;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_080b4ffc.inc");
#endif
}

// 借りる額を選ぶ入力待ち, A で借りて ENE と借金を増やす, 左右で額を増減, 返済額が 10000 を超えるなら警告を出す
// 残差は A で借りるときに原典が gStat を代入のたびに読み直すこと (こちらは1回だけ), 348/349 命令
NON_MATCH void dark_loans_080b5020(DarkLoans* p) {
#ifdef NONMATCHING_C
  s32 blink;

  MainSprite_AdvanceAnim(&p->sprites[0], &p->gfx0);
  if (gInput[0].pressed & A_BUTTON) {
    if (p->unk_82e == 0) {
      PlaySound_082406e0(SE_CANCEL);
    } else {
      s32 total;

      gStat->savedEne += p->unk_82e;
      gStat->darkDebts += p->unk_82c * p->unk_82e;
      total = gStat->loan_1d4 + p->unk_82c * p->unk_82e;
      if (total < 0) {
        total = 0x7FFFFFFF;
      }
      gStat->loan_1d4 = total;
      PlaySound_082406e0(SE_SELECT);
    }
    FUN_080b4d98(p);
    return;
  }
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_080b4ba4(p);
    return;
  }

  if ((gInput[0].down & DPAD_LEFT) && (s32)(gStat->darkDebts + p->unk_82c * (p->unk_82e + 1)) < 10000 && (s16)gStat->savedEne + p->unk_82e < (s16)gStat->savedMaxEne) {
    PlaySound_082406e0(SONG_893);
    p->unk_82e++;
    FUN_080b4818(p);
    FUN_080b4a50(p);
    dark_loans_080b48c8(p);
    p->unk_840 = 19;
    blink = FUN_080b4ffc(p->unk_83e);
    MainSprite_SetPose(&p->sprites[5], &p->gfx0, p->unk_840 + blink, PLAYMODE_LOOP);
    Video_SetAuxSpritePltt(&p->auxGfx, blink + 0x143);
    if (++p->unk_83e > 15) {
      p->unk_83e = 0;
    }
  } else if ((gInput[0].down & DPAD_RIGHT) && p->unk_82e != 0) {
    PlaySound_082406e0(SONG_893);
    p->unk_82e--;
    FUN_080b4818(p);
    FUN_080b4a50(p);
    dark_loans_080b48c8(p);
    p->unk_840 = 22;
    blink = FUN_080b4ffc(p->unk_83e);
    MainSprite_SetPose(&p->sprites[5], &p->gfx0, p->unk_840 + blink, PLAYMODE_LOOP);
    Video_SetAuxSpritePltt(&p->auxGfx, blink + 0x143);
    if (++p->unk_83e > 15) {
      p->unk_83e = 0;
    }
    if (p->unk_848 != 0) {
      p->unk_848 = 1;
    }
  } else if (p->unk_83e == 0) {
    Video_SetAuxSpritePltt(&p->auxGfx, 0x143);
    MainSprite_SetPose(&p->sprites[5], &p->gfx0, 18, PLAYMODE_LOOP);
  } else {
    blink = FUN_080b4ffc(p->unk_83e);
    MainSprite_SetPose(&p->sprites[5], &p->gfx0, p->unk_840 + blink, PLAYMODE_LOOP);
    Video_SetAuxSpritePltt(&p->auxGfx, blink + 0x143);
    if (++p->unk_83e > 15) {
      p->unk_83e = 0;
    }
  }

  if ((gInput[0].down & DPAD_LEFT) && (s32)(gStat->darkDebts + (p->unk_82e + 1) * p->unk_82c) > 9999) {
    p->unk_848 = 60;
  }
  if (p->unk_848 != 0) {
    if (p->unk_848-- == 1) {
      dark_loans_080b48c8(p);
      MessageWindow_ShowLine(4);
      p->unk_84a = 0;
    } else {
      s32 i;

      p->sprites[14].flags |= SPRFLAG_HIDDEN;
      for (i = 0; i < 4; i++) {
        p->sprites[10 + i].flags |= SPRFLAG_HIDDEN;
        p->sprites[15 + i].flags |= SPRFLAG_HIDDEN;
      }
      if (p->unk_84a == 0) {
        MessageWindow_ShowLine(6);
        p->unk_84a = 1;
      }
    }
  }
#else
  INCFUNC("asm/func/dark_loans_080b5020.inc");
#endif
}

// 150 フレーム待ってから, 借りた額があれば '.d' を実行して説明へ, なければ閉じる
void FUN_080b539c(DarkLoans* p) {
  MainSprite_AdvanceAnim(&p->sprites[0], &p->gfx0);
  p->unk_844++;
  if (p->unk_844 > 149) {
    if (p->unk_82e != 0) {
      MessageWindow_ShowLine(5);
      if (p->unk_830 != 0) {
        VM_ExecByID(p->unk_830, NULL);
      } else {
        MessageWindow_SetVarValue(0, 3);
      }
      DarkLoans_SetUpdate(p, FUN_080b5434);
    } else {
      FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
      DarkLoans_SetUpdate(p, FUN_080b54ec);
    }
  }
}

// 150 フレーム待ってから, おしおき回数が 0 なら閉じ, そうでなければ次の説明へ
void FUN_080b5434(DarkLoans* p) {
  p->unk_844++;
  if (p->unk_844 > 149) {
    if (gStat->tortureCount == 0) {
      FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
      DarkLoans_SetUpdate(p, FUN_080b54ec);
    } else {
      FUN_080b4e04(p);
    }
  }
}

void FUN_080b54a0(DarkLoans* p) {
  p->unk_844++;
  if (p->unk_844 > 0x95) {
    FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
    DarkLoans_SetUpdate(p, FUN_080b54ec);
  }
}

void FUN_080b54ec(DarkLoans* p) {
  p->unk_844++;
  if (p->unk_844 > 0x1F && p->unk_834 != 0) {
    VM_ExecByID(p->unk_834, NULL);
    KillEntity((Entity*)p);
  }
}

// 150 フレームで暗転させ, 182 フレームで '.e' のスクリプトを実行して閉じる
void FUN_080b5528(DarkLoans* p) {
  MainSprite_AdvanceAnim(&p->sprites[0], &p->gfx0);
  if (p->unk_844 == 150) {
    FUN_0823ce68(3, 5, 4, 4, 4, 0xFFFF, 0);
  }
  p->unk_844++;
  if (p->unk_844 > 181) {
    VM_ExecByID(p->unk_834, NULL);
    KillEntity((Entity*)p);
  }
}

s32 DarkLoans_Update(DarkLoans* p) {
  p->updateCallback(p);
  return 0;
}

s32 DarkLoans_Destroy(DarkLoans* p) {
  s32 i;

  for (i = 0; i < 20; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
  AuxSprite_Remove(&p->auxSprite);
  return 0;
}

void FUN_080b55d4(DarkLoans* p) {
  s32 indices[1];

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_83C0);
  indices[0] = 0;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, indices);
}

// 後半48色のパレットを読み込んで BG パレットへ流す
void FUN_080b5614(DarkLoans* p) {
  BgPlttFile* f = GetBgPlttFile(BGP_EAA8);

  p->pltt = &f->body[208];
  CpuCopy32(p->pltt, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

// 画面のスプライトを全部登録する
// 残差は最初の MainSprite_Add の引数 0 を pos 初期化の 0 と共有してしまう1命令だけ (324/325命令), warehouse.c の FUN_080b8b60 と同じ
NON_MATCH void DarkLoans_Init_Helper_080b5650(DarkLoans* p) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* f;
  Vec3 pos;
  s32 i;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_DARKLOAN);
  p->gfx0 = *f;
  OpenMainSpriteFile(&p->gfx0, f);
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  p->gfx1 = *f;
  OpenMainSpriteFile(&p->gfx1, f);

  pos.x = 0, pos.y = 0, pos.z = 0;
  MainSprite_Add(&p->sprites[0], &p->gfx0, 4, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[2], &p->gfx0, p->unk_82c + 7, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x += 8;
  MainSprite_Add(&p->sprites[3], &p->gfx0, 8, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x += 8;
  MainSprite_Add(&p->sprites[4], &p->gfx0, 8, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = -8;
  pos.y = -8;
  MainSprite_Add(&p->sprites[1], &p->gfx1, SMENU_YESNO(0), SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 16;
  pos.y = -4;
  MainSprite_Add(&p->sprites[5], &p->gfx0, 18, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 144;
  pos.y = 40;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[6 + i], &p->gfx1, 20, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x += 8;
  }
  MainSprite_Add(&p->sprites[19], &p->gfx1, 71, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 1, PLAYMODE_PAUSE, 60, &pos);

  pos.x = -56;
  pos.y = 56;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[10 + i], &p->gfx0, 8, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x += 8;
  }

  pos.x = 88;
  pos.y = 56;
  MainSprite_Add(&p->sprites[14], &p->gfx0, p->unk_82c + 7, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = -48;
  pos.y = 72;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[15 + i], &p->gfx0, 8, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x += 8;
  }

  Video_GetAuxSprite(&p->auxGfx, SPRITE_SOLAR_STATION);
  AuxSprite_Add(&p->auxSprite, &p->auxGfx, 0);
  p->auxSprite.priority = 0;
  p->auxSprite.flags = SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT;
  Video_SetAuxSpritePltt(&p->auxGfx, 0x143);
  p->auxSprite.pos.x = 160;
  p->auxSprite.pos.y = 88;
  p->auxSprite.pos.z = 0;
#else
  INCFUNC("asm/func/DarkLoans_Init_Helper_080b5650.inc");
#endif
}

// '.r' があれば本文を差し替えて, メッセージ枠を開く
void DarkLoans_Init_Helper_080b593c(DarkLoans* p) {
  if (VM_SeekToNamedArg('r')) {
    p->script = VM_GetPC_Proxy();
  }

  MessageWindow_SetBgPltt(BGP_EAA8);
  MessageWindow_Start(p->script);
  MessageWindow_SetRect(1, 15, 28, 4);
  MessageWindow_SetInstant(1);
}

// 太陽ゲージが低いほど大きい値を返す
s32 DarkLoans_Init_Helper_080b5984(void) {
  s32 sun = gStat->sunGauge;

  if (sun <= 1) return 9;
  if (sun > 9) return 2;

  return 11 - sun;
}

s32 DarkLoans_Init(DarkLoans* p) {
  p->unk_82c = DarkLoans_Init_Helper_080b5984();
  FUN_080b55d4(p);
  FUN_080b5614(p);
  DarkLoans_Init_Helper_080b5650(p);
  DarkLoans_Init_Helper_080b593c(p);
  if (VM_SeekToNamedArg('d')) {
    p->unk_830 = VM_GetValue();
  } else {
    p->unk_830 = 0;
  }
  if (VM_SeekToNamedArg('e')) {
    p->unk_834 = VM_GetValue();
  } else {
    p->unk_834 = 0;
  }
  if (VM_SeekToNamedArg('o')) {
    p->unk_846 = VM_GetValue();
  } else {
    p->unk_846 = 0;
  }
  if (p->unk_846) {
    FUN_080b4e8c(p);
  } else {
    FUN_080b4b04(p);
  }
  return 0;
}

// 0xE9D3, HashName("暗黒ローン")
DarkLoans* DarkLoans_Create(void) {
  DarkLoans* p = CreateEntity(ENTITY_UNK_11, sizeof(DarkLoans));

  if (p != NULL) {
    SetEntityRoutine(p, DarkLoans_Update, DarkLoans_Destroy);
    if (DarkLoans_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
