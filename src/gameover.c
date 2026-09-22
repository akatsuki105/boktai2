#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// "GAME OVER" の1文字ぶん。8個並べて1つのロゴになる
typedef struct {
  AuxSprite sprite;  // 0x00, GameOverManager_SetupLetters が AuxSprite_Setup に渡す。flags は 0x1033 = SPRFLAG_GAMEOVER|SPRFLAG_OAM_DIRECT|SPRFLAG_SCREEN_COORD|SPRFLAG_AFFINE|SPRFLAG_HIDDEN で、metaspriteIdx に 0..7 が入る
  AuxSpriteGfx gfx;  // 0x2C, GameOverManager_SetupLetters の Video_GetAuxSprite(&gfx, SPRITE_GAMEOVER)
  s16 baseX;         // 0x48, GameOverManager_SetupLetters が 56 + i * 16 (i >= 4 ならさらに +16) を入れる。 GameOverManager_UpdateLetters がここから sprite.pos.x を作る
  s16 baseY;         // 0x4A, GameOverManager_SetupLetters が 72 を入れる
  u8 unk_4c[4];      // 0x4C
} GameOverLetter;
static_assert(sizeof(GameOverLetter) == 80);

// 常駐して、ゲームオーバー条件を満たしたらゲームオーバー処理を行う
typedef struct GameOverManager {
  Entity e;                   // 0x000, ENTITY_UNK_11
  GameOverLetter letters[8];  // 0x018, "GAME OVER" の8文字。GameOverManager_SetupLetters が組み立て、GameOverManager_UpdateLetters が毎フレーム拡大率と位置を書き直す
  MainSpriteGfx menuGfx;      // 0x298, GameOverManager_SetupMenu の GetFile(SPRITE_SETS, UI_START_MENU) を OpenSpriteSetFile したもの
  MainSprite menu;            // 0x2B8, コンティニューの選択肢。cursor に応じてポーズ 135 / 136 を貼る。 flags に SPRFLAG_GAMEOVER を含む
  rgb555 menuPltt[16];        // 0x318, GameOverManager_SetupMenu が gObjPlttData[0x2A90] から CpuSet でコピーし、menu.pltt をここに向ける。GameOverManager_UpdateMenuPltt が最後の1色 (index 15) を点滅させる
  u8* script;                 // 0x338, kw: '.r', GameOverManager_StateOpenMenu が TextBox_Start に渡す
  s16 scaleX;                 // 0x33C, 6.6固定小数 (0x40 = 等倍)。GameOverManager_UpdateLetters が毎フレーム全 letters の sprite.scaleX へコピーする
  s16 scaleY;                 // 0x33E, 同上で sprite.scaleY
  u8 state;                   // 0x340, GameOverManager_Update が呼ぶ PTR_ARRAY_085ad034 の添字 (0..4)
  u8 animState;               // 0x341, GameOverManager_UpdateAnim が呼ぶ PTR_ARRAY_085ad014 の添字 (0..8)。ロゴの拡大縮小の段階
  bool8 spritesAdded;         // 0x342, GameOverManager_AddSprites が描画リストへ登録したら 1。GameOverManager_Destroy はこれが立っているときだけ外す
  u8 cursor;                  // 0x343, 選択肢のカーソル。0 で menu のポーズ 135、 1 で 136
  u16 plttTimer;              // 0x344, 0..49 を回り、GameOverManager_UpdateMenuPltt が menuPltt[15] の明度を切り替える
  u16 timer;                  // 0x346, 各 state / animState で 0 から数え直す汎用カウンタ
  u16 cost[2];                // 0x348, kw: '.c' (default: 500,250), コンティニューに必要な太陽エネルギー量で gStat->solarBank と比較する
  u8 costIdx;                 // 0x34C, cost の添字。GameOverManager_StateWaitFlag が gPlayerPtr[0]->unk_37c が 28 か 29 のとき 1 にする
  u8 unk_34d[3];              // 0x34D, padding?
  s32 scriptId;               // 0x350, kw: '.p', コンティニューを選ばずに終わるとき cost[costIdx] を引数にして Script_ExecById へ渡す
} GameOverManager;
static_assert(sizeof(GameOverManager) == 852);

extern GameOverManager* gGameOverManager;  // 0x03000150

typedef void (*GameOverFunc)(GameOverManager* p);

// ロゴの拡大縮小の段階ごとの処理。animState が添字
#define gGameOverAnimFns ((GameOverFunc*)0x085AD014)

// ゲームオーバー進行の段階ごとの処理。state が添字
#define gGameOverStateFns ((GameOverFunc*)0x085AD034)

void FUN_0823a8f4(u32 val);

static inline u32 TestFlag030047a4(u32 flags) { return (gFlag030047a4 | u32_030047a0) & flags; }

void FUN_0822e110(void);
void FUN_0822adac(void);
void FUN_0822f244(void);
s32 FUN_0809c08c(s32 mode);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
u8* FUN_0823d340(void);

// animState 0。BGM を切り替えて、横に潰れた状態からロゴのアニメーションを始める
void GameOverManager_AnimStart(GameOverManager* p) {
  Sound_StopAll();
  PlaySound_082406e0(0x2);
  PlaySound_082406e0(0x12C);
  p->scaleX = 0x0A;
  p->scaleY = 0x40;
  p->animState = 1;
}

// animState 1。縦を一気に引き伸ばす
void GameOverManager_AnimStretchY(GameOverManager* p) {
  p->scaleX++;
  p->scaleY += 0x1E;
  if (p->scaleY > 0x7E) {
    p->scaleY = 0x7F;
    p->animState = 2;
  }
}

// animState 2。伸びきった縦を 0x60 まで戻す
void GameOverManager_AnimShrinkY1(GameOverManager* p) {
  p->scaleX++;
  p->scaleY -= 0x03;
  if (p->scaleY <= 0x60) {
    p->scaleY = 0x60;
    p->animState = 3;
  }
}

// animState 3。縦を等倍 (0x40) まで戻しつつ横を少し速く広げる
void GameOverManager_AnimShrinkY2(GameOverManager* p) {
  p->scaleX += 0x02;
  p->scaleY -= 0x03;
  if (p->scaleY <= 0x40) {
    p->scaleY = 0x40;
    p->animState = 4;
  }
}

// animState 4。横も等倍 (0x40) まで広げて、そこでロゴが完成する
void GameOverManager_AnimGrowX(GameOverManager* p) {
  p->scaleX += 0x03;
  if (p->scaleX > 0x3F) {
    p->scaleX = 0x40;
    p->animState = 5;
    p->timer = 0;
  }
}

// animState 5。等倍のロゴを 20 フレーム見せてから次へ進む
void GameOverManager_AnimHold(GameOverManager* p) {
  p->timer++;
  if (p->timer > 19) {
    p->animState = 6;
    p->timer = 0;
  }
}

// animState 6。オテンコの声を挟んでから、ロゴを横に引き伸ばして潰し、8文字を非表示にする
void GameOverManager_AnimClose(GameOverManager* p) {
  p->timer++;
  if (p->timer == 30) {
    PlaySound_082406e0(0x2F9);
    return;
  }
  if (p->timer <= 149) {
    return;
  }
  if (p->timer == 150) {
    PlaySound_082406e0(0x12D);
  }
  p->scaleX += 0x05;
  p->scaleY -= 0x05;
  if (p->scaleX > 0x7F) {
    s32 i;

    p->scaleX = 0x01;
    p->scaleY = 0x01;
    for (i = 0; i < 8; i++) {
      p->letters[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
    p->animState = 7;
    p->timer = 0;
  }
}

// animState 7。90 フレーム待ってから animState を 8 (終了) にする
void GameOverManager_AnimEnd(GameOverManager* p) {
  p->timer++;
  if (p->timer > 89) {
    p->animState = 8;
  }
}

// 現在の拡大率を8文字に配り、等倍を超えた分だけ中央から左右へ文字間を開く
NON_MATCH void GameOverManager_UpdateLetters(GameOverManager* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 spread = 0;

  for (i = 0; i < 8; i++) {
    p->letters[i].sprite.scaleX = p->scaleX;
    p->letters[i].sprite.scaleY = p->scaleY;
  }
  for (i = 3; i >= 0; i--) {
    if (p->scaleX > 0x40) {
      p->letters[i].sprite.pos.x = p->letters[i].baseX - spread;
      spread += (p->scaleX >> 2) - 0x10;
    } else {
      p->letters[i].sprite.pos.x = p->letters[i].baseX;
    }
  }
  spread = 0;
  for (i = 4; i < 8; i++) {
    if (p->scaleX > 0x40) {
      p->letters[i].sprite.pos.x = p->letters[i].baseX + spread;
      spread += (p->scaleX >> 2) - 0x10;
    } else {
      p->letters[i].sprite.pos.x = p->letters[i].baseX;
    }
  }
#else
  INCFUNC("asm/func/GameOverManager_UpdateLetters.inc");
#endif
}

// スクリプトコマンド 0xF04A。ゲームオーバー状態を解除して BGM を止める
void GameOver_CancelScripted(void) {
  gFlag030047a4 &= ~FLAG030047A4_GAMEOVER;
  sound_08240740(0x2);
  FUN_0823a8f4(0);
}

// 現在の animState の処理を呼んでから、その結果の拡大率を letters へ反映する
NON_MATCH void GameOverManager_UpdateAnim(GameOverManager* p) {
#ifdef NONMATCHING_C
  gGameOverAnimFns[p->animState](p);
  GameOverManager_UpdateLetters(p);
#else
  INCFUNC("asm/func/GameOverManager_UpdateAnim.inc");
#endif
}

// ロゴの8文字と選択肢のスプライトを描画リストへ入れる
void GameOverManager_AddSprites(GameOverManager* p) {
  AuxSprite* sprite = &p->letters[0].sprite;
  s32 i;

  for (i = 0; i < 8; i++) {
    Video_AddAuxSpriteIntoDrawList(sprite, 0);
    sprite = (AuxSprite*)((u8*)sprite + sizeof(GameOverLetter));
  }
  Video_AddMainSpriteIntoDrawList(&p->menu, 0);
  p->spritesAdded = TRUE;
}

// "GAME OVER" の8文字を横一列に並べる。4文字目の後に1文字分の隙間を空ける
NON_MATCH void GameOverManager_SetupLetters(GameOverManager* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 x = 56;

  p->scaleX = 0x01;
  p->scaleY = 0x01;
  for (i = 0; i < 8; i++) {
    p->letters[i].baseX = x;
    p->letters[i].baseY = 72;
    if (i > 3) {
      p->letters[i].baseX = x + 16;
    }
    Video_GetAuxSprite(&p->letters[i].gfx, 0x654B);
    AuxSprite_Setup(&p->letters[i].sprite, &p->letters[i].gfx, 0);
    p->letters[i].sprite.priority = 0;
    p->letters[i].sprite.flags = SPRFLAG_GAMEOVER | SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE | SPRFLAG_HIDDEN;
    p->letters[i].sprite.pos.x = p->letters[i].baseX;
    p->letters[i].sprite.pos.y = p->letters[i].baseY;
    p->letters[i].sprite.scaleX = p->scaleX;
    p->letters[i].sprite.scaleY = p->scaleY;
    p->letters[i].sprite.metaspriteIdx = i;
    x += 16;
  }
#else
  INCFUNC("asm/func/GameOverManager_SetupLetters.inc");
#endif
}

// 選択肢のパレットの最後の1色を、50 フレーム周期で赤く明滅させる
void GameOverManager_UpdateMenuPltt(GameOverManager* p) {
  rgb555 color;

  if (p->plttTimer <= 9) {
    color = 0x1F;
  } else if (p->plttTimer <= 17) {
    color = 0x1B;
  } else if (p->plttTimer <= 25) {
    color = 0x12;
  } else if (p->plttTimer <= 33) {
    color = 0x0A;
  } else {
    color = 0x1B;
    if (p->plttTimer <= 41) {
      color = 0x12;
    }
  }
  p->plttTimer++;
  if (p->plttTimer > 49) {
    p->plttTimer = 0;
  }
  p->menuPltt[15] = color;
}

NAKED void GameOverManager_SetupMenu(GameOverManager* p) { INCFUNC("asm/func/GameOverManager_SetupMenu.inc"); }

// スクリプトコマンド 0xDED5。ゲームオーバー演出を今すぐ始める
void GameOverManager_StartScripted(void) {
  GameOverManager* p = gGameOverManager;

  if (p == NULL) {
    return;
  }
  GameOverManager_AddSprites(p);
  FUN_0809c08c(7);
  p->state = 1;
  if (!VM_SeekToKeyword('f')) {
    return;
  }
  if (Script_GetValue() == 0) {
    return;
  }
  FUN_0823ce68(3, 5, 4, 4, 4, 0x1FFF, 2);
}

// state 0。ゲームオーバーのフラグが立つまで何もせず待つ
void GameOverManager_StateWaitFlag(GameOverManager* p) {
  if (!TestFlag030047a4(FLAG030047A4_GAMEOVER)) {
    return;
  }
  GameOverManager_AddSprites(p);
  FUN_0809c08c(7);
  if (gPlayerPtr[0]->unk_37c >= 28 && gPlayerPtr[0]->unk_37c <= 29) {
    p->costIdx = 1;
  } else {
    FUN_0823ce68(3, 5, 4, 4, 4, 0x1FFF, 2);
  }
  p->state = 1;
}

// state 1。32 フレーム待ってからロゴを表示し、bit12 付きのスプライトだけを描くパスへ切り替える
void GameOverManager_StateShowLogo(GameOverManager* p) {
  s32 i;

  p->timer++;
  if (p->timer <= 31) {
    return;
  }
  for (i = 0; i < 8; i++) {
    p->letters[i].sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  Video_SetDrawPasses(0, FUN_0822e110, FUN_0822adac, FUN_0822f244);
  p->state = 2;
}

// state 2。ロゴが完成したらメッセージ枠を開き、コンティニューに必要な太陽エネルギーが足りるかで表示行を変える
void GameOverManager_StateOpenMenu(GameOverManager* p) {
  GameOverManager_UpdateAnim(p);
  if (p->animState != 6) {
    return;
  }
  p->menu.flags &= ~SPRFLAG_HIDDEN;
  FUN_0809c08c(3);
  TextBox_SetRect(1, 13, 28, 4);
  TextBox_SetInstant(1);
  TextBox_Start(p->script);
  TextBox_SetVarValue(0, p->cost[p->costIdx]);
  if ((s16)gStat->solarBank >= p->cost[p->costIdx]) {
    TextBox_ShowLine(0);
  } else {
    TextBox_ShowLine(1);
  }
  p->state = 3;
}

NAKED void FUN_080a7800(GameOverManager* p) { INCFUNC("asm/func/FUN_080a7800.inc"); }

// state 4。ロゴが消えるまで待ってから、ゲームオーバー状態を解除して自分を消す
void GameOverManager_StateFinish(GameOverManager* p) {
  GameOverManager_UpdateAnim(p);
  if (p->animState == 8) {
    gFlag030047a4 &= ~FLAG030047A4_GAMEOVER;
    bool32_03004788 = FALSE;
    FUN_0823a8f4(p->cursor);
    KillEntity((Entity*)p);
  }
}

NON_MATCH s32 GameOverManager_Update(GameOverManager* p) {
#ifdef NONMATCHING_C
  gGameOverStateFns[p->state](p);
  return 0;
#else
  INCFUNC("asm/func/GameOverManager_Update.inc");
#endif
}

s32 GameOverManager_Destroy(GameOverManager* p) {
  if (p->spritesAdded) {
    AuxSprite* sprite = &p->letters[0].sprite;
    s32 i;

    for (i = 0; i < 8; i++) {
      AuxSprite_Remove(sprite);
      sprite = (AuxSprite*)((u8*)sprite + sizeof(GameOverLetter));
    }
    MainSprite_Remove(&p->menu);
  }
  gGameOverManager = NULL;
  return 0;
}

s32 GameOverManager_Init(GameOverManager* p) {
  GameOverManager_SetupLetters(p);
  GameOverManager_SetupMenu(p);
  p->state = 0;
  p->animState = 0;
  p->timer = 0;
  p->spritesAdded = FALSE;
  if (VM_SeekToKeyword('r')) {
    p->script = FUN_0823d340();
  }
  if (VM_SeekToKeyword('c')) {
    p->cost[0] = Script_GetValue();
    p->cost[1] = Script_GetValue();
  } else {
    p->cost[0] = 500;
    p->cost[1] = 250;
  }
  p->costIdx = 0;
  if (VM_SeekToKeyword('p')) {
    p->scriptId = Script_GetValue();
  } else {
    p->scriptId = 0;
  }
  gGameOverManager = p;
  return 0;
}

GameOverManager* GameOverManager_Create(void) {
  GameOverManager* p;

  if (gGameOverManager != NULL) {
    return gGameOverManager;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(GameOverManager));
  if (p != NULL) {
    SetEntityRoutine(p, GameOverManager_Update, GameOverManager_Destroy);
    if (GameOverManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
