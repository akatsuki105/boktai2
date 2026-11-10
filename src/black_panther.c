#include "actor.h"
#include "camera.h"
#include "emote.h"
#include "entity.h"
#include "file.h"
#include "game.h"
#include "global.h"
#include "mover.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// GameInfo.blackPantherResult の中身
#define MINIGAME_ENDED (*(u16*)&gStat->blackPantherResult[0])      // ミニゲームの開始で 0, Cmd_B294 で 1
#define MINIGAME_NO_DAMAGE (*(u16*)&gStat->blackPantherResult[2])  // Cmd_B294 が BlackPanther.damaged の逆を書く
#define MINIGAME_SCORE (*(u16*)&gStat->blackPantherResult[4])      // BlackPanther.score の写し
#define MINIGAME_MAX_COMBO (*(u16*)&gStat->blackPantherResult[6])  // BlackPanther.maxCombo の写し

struct BlackPanther;
struct BlackPantherEntry;

// ミニゲーム"ブラックパンサー"のレーンを流れてくるおじゃまキャラ, kind 0: 爆弾, 1: バット, 2: ビー
typedef struct BlackPantherObj {
  bool8 active;                                                           // 0x00
  bool8 hit;                                                              // 0x01, 当たると立ち, 次の更新でコンボを切って消える
  s8 score;                                                               // 0x02, 避けたときの得点, sunGauge が高いほど増える
  u8 lane;                                                                // 0x03, 0..2, u16_ARRAY_085ab740 の添字
  u16 speed;                                                              // 0x04, 1フレームに進む量, sunGauge が高いほど速い
  u16 flags;                                                              // 0x06, bit0: 今のフレームで当たり判定の対象
  s32 kind;                                                               // 0x08, sMinigameOjamaSpriteIDs の添字
  u32 timer;                                                              // 0x0C, 毎フレーム +1
  u32 unk_10;                                                             // 0x10, 32 を入れるだけで読むコードは見つかっていない
  u8 lanes[2];                                                            // 0x14, コウモリが timer に合わせて行き来する2レーン
  u8 unk_16[0x1C - 0x16];                                                 // 0x16
  AuxSpriteGfx gfx;                                                       // 0x1C, ID は kind で変わる
  AuxSprite sprite;                                                       // 0x38
  AuxAnimState anim;                                                      // 0x64
  void (*updateCallback)(struct BlackPanther*, struct BlackPantherObj*);  // 0x74
} BlackPantherObj;
static_assert(sizeof(BlackPantherObj) == 120);

// ミニゲームの登場キャラ1人分, 2つのステートを持ち ctrl* が行動の段取りを, state が今の動きを表す
typedef struct {
  s32 idx;                                // 0x000, BlackPantherEntry_ARRAY_085ab748 の添字, '.C'
  SpriteID32 spriteID;                    // 0x004
  u8 lane;                                // 0x008, 0..2, u16_ARRAY_085ab740 の添字
  u8 nextLane;                            // 0x009, レーン移動の行き先
  u8 flags;                               // 0x00A, 毎フレーム 0 に戻る, bit0: スプライトと影を隠す, bit1: ジャンプ中の攻撃判定
  u8 ctrlState;                           // 0x00B, PTR_ARRAY_085ab95c の添字
  bool8 ctrlBegun;                        // 0x00C, ctrlState に入った最初のフレームで立っている
  u8 state;                               // 0x00D, BlackPantherEntry.fns の添字
  bool8 stateBegun;                       // 0x00E, state に入った最初のフレームで立っている
  u8 angle;                               // 0x00F
  u8 dir4;                                // 0x010, 4方向の向き
  u8 dir8;                                // 0x011, 8方向の向き
  u8 unk_12[2];                           // 0x012
  s32 hitRange;                           // 0x014, Z 方向にこの範囲のおじゃまキャラに当たる
  u32 unk_18;                             // 0x018, 0 を書くだけで読むコードは見つかっていない
  u32 stateTimer;                         // 0x01C
  s32 animKind;                           // 0x020, 4 未満は anims の添字, 4 以上は ActorAnim_ARRAY_085ab924 の添字 + 4
  Emote* emote;                           // 0x024
  s32 emoteKind;                          // 0x028
  s16 emoteTimer;                         // 0x02C, 毎フレーム減り 3 で止まる
  s16 emoteDuration;                      // 0x02E
  Mover mover;                            // 0x030
  Vec3 pos;                               // 0x074, 毎フレーム sprite と mover へ写す
  SpriteHolder sprite;                    // 0x07C
  AuxSprite shadowSprite;                 // 0x110, SPRITE_EFF_1C1B の pose 7, 足元のタイルの高さに置く
  ParticleShadow shadow;                  // 0x13C
  const struct BlackPantherEntry* entry;  // 0x17C
  const ActorAnim* anims;                 // 0x180
} BlackPantherElem;
static_assert(sizeof(BlackPantherElem) == 388);

// おそらく ゲームの周回数が偶数のときに遊べる ミニゲーム"ブラックパンサー" のシーン用Entity
typedef struct BlackPanther {
  Entity e;                      // 0x0000, ENTITY_UNK_11
  s32 frameCounter;              // 0x0018, _Update が毎フレーム +1
  s32 endScriptID;               // 0x001C, '.p=0', 逃げられたときのアニメが終わったら1度だけ実行して 0 に戻す
  u32 unk_20;                    // 0x0020, 3 を入れるだけで読むコードは見つかっていない
  s32 gap;                       // 0x0024, ライバルとの距離, gapTarget へ 4 ずつ近づく, 1000 に達すると逃げられて終わる
  s32 gapTarget;                 // 0x0028, 0..1000, おじゃまキャラに当たると +100, 避けると減る
  s32 sunGauge;                  // 0x002C, _Update が毎フレーム gStat->sunGauge を写す
  bool8 spawnEnabled;            // 0x0030, おじゃまキャラを出すか
  u8 unk_31;                     // 0x0031, _Update が 0 まで減らし、0 になった瞬間 FUN_08054ae4 を呼ぶ
  bool8 damaged;                 // 0x0032, 1度でも当たると立つ, idx 0 のキャラの anims が 10 件後ろへずれ, bonusScore2 がもらえなくなる
  bool8 scorePopupActive;        // 0x0033
  s32 scorePopupTimer;           // 0x0034, 60 で消える
  s32 scorePopup;                // 0x0038, 獲得した得点の表示
  s32 score;                     // 0x003C, 0..9999, gStat+0x3B0 へ写す
  s32 shownScore;                // 0x0040, score へ 4 ずつ近づく, 画面の数字
  u16 comboTier;                 // 0x0044, 0/1/2, combo の大小で決まり、変わると SE 0x28B が鳴って auxSprites1 の表示が変わる
  u16 finished;                  // 0x0046, 逃げられると 1, 立っていると Cmd_E70E と Cmd_B294 の一部を飛ばす
  u32 unk_48;                    // 0x0048, 1 を書くだけで読むコードは見つかっていない
  s32 spawnCount;                // 0x004C, 今までに出したおじゃまキャラの数
  u32 combo;                     // 0x0050, 30 と 100 で comboTier が上がる
  u32 maxCombo;                  // 0x0054, gStat+0x3B2 へ写す
  u32 fadeMode;                  // 0x0058, 1 で画面を明転, 2 で暗転 (gObjBrightness を 4 ずつ動かす), 終わると 0 に戻る
  u32 hideHud;                   // 0x005C, 立っていると数字とコンボ表示を毎フレーム隠す
  Vec3 pos;                      // 0x0060, '.c', Camera_MoveTo に渡す
  MainSpriteGfx gfx[7];          // 0x0068, BlackPantherEntry.unk_08 が 2 の要素だけ
  BlackPantherElem elems[5];     // 0x0148
  BlackPantherObj objs[32];      // 0x08DC
  AuxAnimFile* animFiles[4];     // 0x17DC, ANIM_871C / ANIM_BAT / ANIM_BEE / ANIM_6830
  AuxSpriteGfx auxGfx1;          // 0x17EC, SPRITE_EFF_1C1B, plttID に 0x7584 を入れ、パレットを pltt に向ける
  rgb555 pltt[16];               // 0x1808, _Init が全部 RGB(20, 20, 20) で埋める
  MainSpriteGfx mainGfx;         // 0x1828, SPRITE_UI_START_MENU
  MainSprite mainSprites1[4];    // 0x1848, poseIdx 30 で登録
  MainSprite mainSprites2[4];    // 0x19C8, 同上だが最初は非表示
  MainSprite mainSprites3[3];    // 0x1B48, 同上
  AuxSpriteGfx auxGfx2;          // 0x1C68, SPRITE_PANTHER_BONUS, ブラックパンサー(ミニゲーム)用
  AuxSprite auxSprites1[6];      // 0x1C84, poseIdx は 3,4,7,8,9,10, unk_44 に応じて表示が切り替わる
  AuxSpriteGfx auxGfx3;          // 0x1D8C, SPRITE_COMBO_SCORE, ブラックパンサー(ミニゲーム)用
  AuxSprite auxSprites2[2];      // 0x1DA8
  u32 unk_1e00;                  // 0x1E00, 1 を書くだけで読むコードは見つかっていない
  u8 unk_1e04[0x1E0C - 0x1E04];  // 0x1E04
  s32 bombScore;                 // 0x1E0C, 爆弾を避けたときの得点の基本値
  s32 batScore;                  // 0x1E10, コウモリの同上
  s32 beeScore;                  // 0x1E14, ハチの同上
  s32 bonusScore1;               // 0x1E18, ライバルにジャンプで追いついたときの得点
  s32 bonusScore2;               // 0x1E1C, 1度も当たらずに終えたときの得点
} BlackPanther;
static_assert(sizeof(BlackPanther) == 7712);

static BlackPanther* sBlackPanther;  // 0x03000120

static inline void BlackPantherElem_SetState(BlackPantherElem* elem, u8 state) {
  elem->state = state;
  elem->stateBegun = TRUE;
  elem->stateTimer = 0;
}

static inline void BlackPantherElem_SetAngle(BlackPantherElem* elem, u8 angle) {
  elem->angle = angle;
  elem->dir8 = Angle_ToDir8(angle);
  elem->dir4 = Angle_ToDir4(angle);
}

static inline void BlackPantherElem_SetCtrlState(BlackPantherElem* elem, u8 state) {
  elem->ctrlState = state;
  elem->ctrlBegun = TRUE;
  elem->unk_18 = 0;
}

// 0x085AB748 の8件のテーブル, BlackPantherElem_Init が 0x38 刻みで引く
typedef struct BlackPantherEntry {
  SpriteID32 id;                                      // 0x00, ActorManager_FindSpriteData の第1引数
  s32 idx;                                            // 0x04, ActorManager_FindSpriteData の第2引数
  u32 unk_08;                                         // 0x08, BlackPantherElem_InitSprite に渡す, 2 の要素だけ BlackPanther.gfx[] に入る
  u32 unk_0c;                                         // 0x0C, BlackPantherElem_InitSprite に渡す, SPRITE_MOUSE の要素だけ ANIM_MOUSE
  void (*fns[10])(BlackPanther*, BlackPantherElem*);  // 0x10, BlackPantherElem_Update が BlackPantherElem + 0x0D で引く
} BlackPantherEntry;
static_assert(sizeof(BlackPantherEntry) == 56);

const u16 u16_ARRAY_085ab740[4] = {0x760, 0x800, 0x8A0, 0x800};  // 0x085AB740

// スプライトと影を隠したまま待つ
void BlackPantherElem_StateHidden(BlackPanther*, BlackPantherElem*);
void FUN_08053dcc(BlackPanther*, BlackPantherElem*);
void FUN_08053dfc(BlackPanther*, BlackPantherElem*);
void FUN_08053e2c(BlackPanther*, BlackPantherElem*);
void BlackPantherElem_StateJump(BlackPanther*, BlackPantherElem*);
void BlackPantherElem_StateChangeLane(BlackPanther*, BlackPantherElem*);
void FUN_08053fd0(BlackPanther*, BlackPantherElem*);
void FUN_08054054(BlackPanther*, BlackPantherElem*);
void FUN_080540d4(BlackPanther*, BlackPantherElem*);
void FUN_08054130(BlackPanther*, BlackPantherElem*);
void FUN_08054170(BlackPanther*, BlackPantherElem*);
void FUN_080541cc(BlackPanther*, BlackPantherElem*);
void FUN_080541fc(BlackPanther*, BlackPantherElem*);
// 隠れた状態へ移す
void BlackPantherElem_CtrlHide(BlackPanther*, BlackPantherElem*);
void FUN_080542ac(BlackPanther*, BlackPantherElem*);
void BlackPantherElem_CtrlPlayer(BlackPanther*, BlackPantherElem*);
void FUN_08054444(BlackPanther*, BlackPantherElem*);
void FUN_08054490(BlackPanther*, BlackPantherElem*);
void FUN_080544b4(BlackPanther*, BlackPantherElem*);
void FUN_08054520(BlackPanther*, BlackPantherElem*);
// 画面の奥へ走り去る
void BlackPantherElem_CtrlEscape(BlackPanther*, BlackPantherElem*);
void FUN_08054698(BlackPanther*, BlackPantherElem*);
void FUN_08054700(BlackPanther*, BlackPantherElem*);
void FUN_0805474c(BlackPanther*, BlackPantherElem*);
void FUN_080547a8(BlackPanther*, BlackPantherElem*);
void FUN_080547f4(BlackPanther*, BlackPantherElem*);

// clang-format off
const BlackPantherEntry BlackPantherEntry_ARRAY_085ab748[8] = {
    {
        .id = SPRITE_KURO,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {BlackPantherElem_StateHidden, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, BlackPantherElem_StateJump, BlackPantherElem_StateChangeLane, FUN_08053fd0, FUN_080540d4, FUN_08054130, FUN_08054130},
    },
    {
        .id = SPRITE_DJANGO_SABATA,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {BlackPantherElem_StateHidden, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, BlackPantherElem_StateJump, BlackPantherElem_StateChangeLane, FUN_08053dcc, BlackPantherElem_StateHidden, BlackPantherElem_StateHidden, FUN_080541cc},
    },
    {
        .id = SPRITE_DJANGO_SABATA,
        .idx = 1,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {BlackPantherElem_StateHidden, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, BlackPantherElem_StateJump, BlackPantherElem_StateChangeLane, FUN_08053dcc, BlackPantherElem_StateHidden, BlackPantherElem_StateHidden, FUN_080541fc},
    },
    {
        .id = SPRITE_RITA,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {BlackPantherElem_StateHidden, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, BlackPantherElem_StateJump, BlackPantherElem_StateChangeLane, FUN_08053dcc, BlackPantherElem_StateHidden, BlackPantherElem_StateHidden, FUN_080541fc},
    },
    {
        .id = SPRITE_ZAJI,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {BlackPantherElem_StateHidden, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, BlackPantherElem_StateJump, BlackPantherElem_StateChangeLane, FUN_08053dcc, BlackPantherElem_StateHidden, BlackPantherElem_StateHidden, FUN_080541fc},
    },
    {
        .id = SPRITE_SUMIRE,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {BlackPantherElem_StateHidden, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, BlackPantherElem_StateJump, BlackPantherElem_StateChangeLane, FUN_08053dcc, BlackPantherElem_StateHidden, FUN_08054170, FUN_080541fc},
    },
    {
        .id = SPRITE_LADY,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {BlackPantherElem_StateHidden, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, BlackPantherElem_StateJump, BlackPantherElem_StateChangeLane, FUN_08053dcc, BlackPantherElem_StateHidden, BlackPantherElem_StateHidden, FUN_080541fc},
    },
    {
        .id = SPRITE_MOUSE,
        .idx = 0,
        .unk_08 = 1,
        .unk_0c = ANIM_MOUSE,
        .fns = {BlackPantherElem_StateHidden, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, BlackPantherElem_StateJump, BlackPantherElem_StateChangeLane, FUN_08054054, BlackPantherElem_StateHidden, BlackPantherElem_StateHidden, BlackPantherElem_StateHidden},
    },
};  // 0x085AB748
// clang-format on

// 何かのIDの並びに見えるが特定できていない
const u16 u16_ARRAY_085ab908[5] = {0x6BDC, 0xF450, 0x094D, 0x6530, 0x2803};  // 0x085AB908

// BlackPantherElem_Init が BlackPantherEntry_ARRAY_085ab748 と同じ添字で引く, 9件目は未使用
const u16 u16_ARRAY_085ab912[9] = {250, 350, 350, 350, 350, 300, 350, 250, 0};  // 0x085AB912

// BlackPantherElem.animKind が 4 以上のときのアニメ, 添字は animKind - 4
const ActorAnim ActorAnim_ARRAY_085ab924[12] = {
    {.dirMode = 1, .unk_1 = 0, .pose = 32 },
    {.dirMode = 1, .unk_1 = 0, .pose = 27 },
    {.dirMode = 3, .unk_1 = 0, .pose = 0  },
    {.dirMode = 3, .unk_1 = 0, .pose = 16 },
    {.dirMode = 1, .unk_1 = 0, .pose = 10 },
    {.dirMode = 1, .unk_1 = 0, .pose = 7  },
    {.dirMode = 3, .unk_1 = 1, .pose = 393},
    {.dirMode = 2, .unk_1 = 1, .pose = 531},
    {.dirMode = 2, .unk_1 = 1, .pose = 11 },
    {.dirMode = 1, .unk_1 = 0, .pose = 7  },
    {.dirMode = 1, .unk_1 = 0, .pose = 10 },
    {.dirMode = 2, .unk_1 = 1, .pose = 2  },
};  // 0x085AB924

// ミニゲーム"ブラックパンサー"で使用されるおじゃまキャラのスプライトID
const SpriteID16 sMinigameOjamaSpriteIDs[4] = {SPRITE_BOMB, SPRITE_BAT, SPRITE_BEE, 0};  // 0x085AB954

// BlackPantherElem_Update が BlackPantherElem + 0x0B で引く
void (*const PTR_ARRAY_085ab95c[13])(BlackPanther*, BlackPantherElem*) = {
    BlackPantherElem_CtrlHide,
    FUN_080542ac,
    BlackPantherElem_CtrlPlayer,
    FUN_08054444,
    FUN_08054490,
    FUN_080544b4,
    FUN_08054520,
    BlackPantherElem_CtrlEscape,
    FUN_08054698,
    FUN_08054700,
    FUN_0805474c,
    FUN_080547a8,
    FUN_080547f4,
};  // 0x085AB95C

void BlackPanther_ClearGlobal(void) { sBlackPanther = NULL; }

NAKED void BlackPantherElem_ShowEmote(BlackPantherElem* elem, u32 kind, s32 param_3, s32 param_4) { INCFUNC("asm/func/BlackPantherElem_ShowEmote.inc"); }

// 残差3箇所 (44/44): 原典は dir4 > 1 の枝を先に置く
// Tier A/B は試済 (sprite ローカル, 比較の書き方), 未: if の条件を反転して枝の順を入れ替える
NON_MATCH s32 BlackPantherElem_SetAnimMode2(BlackPantherElem* elem, s32 pose, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
#ifdef NONMATCHING_C
  SpriteHolder* sprite = &elem->sprite;
  u32 variant;
  u32 xflip;

  if (elem->sprite.kind == 1) {
    if (elem->dir4 < 2) {
      variant = elem->dir4;
      xflip = FALSE;
    } else {
      variant = 3 - elem->dir4;
      xflip = TRUE;
    }
  } else {
    variant = 0;
    if (elem->dir4 == 1 || elem->dir4 == 2) {
      variant = param_4;
    }
    xflip = elem->dir4 > 1;
  }
  return SpriteHolder_SetAnim(sprite, pose, variant, xflip, param_3, param_5, param_6);
#else
  INCFUNC("asm/func/BlackPantherElem_SetAnimMode2.inc");
#endif
}

// 残差11箇所 (34/33): 原典は sprite を先に r4 へ作り, 2 つの枝の両方で xflip の比較を持って末尾の代入を共有する
// Tier A-C は試済 (xflip の if 分岐, variant と xflip の型), 未: 比較を分岐の外に置かない形
NON_MATCH s32 BlackPantherElem_SetAnimMode1(BlackPantherElem* elem, s32 pose, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
#ifdef NONMATCHING_C
  SpriteHolder* sprite = &elem->sprite;
  u32 variant;
  u32 xflip;

  if (elem->sprite.kind == 1) {
    variant = elem->dir4;
    xflip = variant > 1;
  } else {
    variant = 0;
    xflip = elem->dir4 > 1;
  }
  return SpriteHolder_SetAnim(sprite, pose, variant, xflip, param_3, param_5, param_6);
#else
  INCFUNC("asm/func/BlackPantherElem_SetAnimMode1.inc");
#endif
}

s32 BlackPantherElem_SetAnimMode3(BlackPantherElem* elem, s32 pose, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
  u32 variant;
  u32 xflip;

  if (elem->sprite.kind == 1) {
    if (IS_8DIR_LEFT(elem->dir8)) {
      variant = 8 - elem->dir8;
      xflip = TRUE;
    } else {
      variant = elem->dir8;
      xflip = FALSE;
    }
  } else {
    u32 dir;
    if (IS_8DIR_LEFT(elem->dir8)) {
      dir = elem->dir8;
      variant = 8 - dir;
      xflip = TRUE;
    } else {
      variant = elem->dir8;
      xflip = FALSE;
      dir = variant;
    }
    elem->dir8 = dir * param_4;
  }
  return SpriteHolder_SetAnim(&elem->sprite, pose, variant, xflip, param_3, param_5, param_6);
}

s32 BlackPantherElem_SetAnimMode0(BlackPantherElem* elem, s32 pose, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { return SpriteHolder_SetAnim(&elem->sprite, pose, 0, 0, param_3, param_5, param_6); }

NAKED s32 BlackPantherElem_PlayAnim(BlackPanther* p, BlackPantherElem* elem, s32 kind, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/BlackPantherElem_PlayAnim.inc"); }

NAKED void* BlackPantherElem_InitSprite(BlackPanther* p, BlackPantherElem* elem, s32 param_3, u32 fileID, s32 param_5, s32 param_6, s32 param_7) { INCFUNC("asm/func/BlackPantherElem_InitSprite.inc"); }

// ライバルとの距離の目標を増減する, 0..1000 に収める
void BlackPanther_AddGap(BlackPanther* p, s32 delta) {
  p->gapTarget += delta;
  if (p->gapTarget < 0) {
    p->gapTarget = 0;
  } else if (p->gapTarget > 1000) {
    p->gapTarget = 1000;
  }
}

s32 BlackPanther_GetComboMultiplier(BlackPanther* p) {
  switch (p->comboTier) {
    case 1: {
      return Q6(2);
    }
    case 2: {
      return Q6(5);
    }
    case 0:
    default: {
      return Q6(1);
    }
  }
}

// base に倍率 (Q6) を掛けて得点に足す, showPopup なら base を画面にも出す
void BlackPanther_AddScore(BlackPanther* p, s32 base, s32 multiplier, s32 showPopup) {
  if (showPopup) {
    p->scorePopupActive = TRUE;
    p->scorePopupTimer = 0;
    p->scorePopup = base;
  }
  p->score += FixToInt(6, base * multiplier);
  if (p->score >= 10000) {
    p->score = 9999;
  } else if (p->score < 0) {
    p->score = 0;
  }
}

// コンボを増やして最大コンボを更新する
void BlackPanther_IncrementCombo(BlackPanther* p) {
  p->combo++;
  if (p->combo > 999) {
    p->score = 999;  // 間違えてスコアを999にしてる...
  }
  if (p->combo > p->maxCombo) {
    p->maxCombo = p->combo;
  }
}

void BlackPanther_ResetCombo(BlackPanther* p) { p->combo = 0; }

void BlackPantherObj_SetUpdate(BlackPantherObj* obj, void* fn) { obj->updateCallback = fn; }

NAKED void BlackPantherObj_Init(BlackPanther* p, BlackPantherObj* obj, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/BlackPantherObj_Init.inc"); }

void BlackPantherObj_Remove(BlackPanther* p, BlackPantherObj* obj) {
  AuxSprite_Remove(&obj->sprite);
  obj->active = FALSE;
}

NAKED void BlackPantherObj_UpdateBomb(BlackPanther* p, BlackPantherObj* obj) { INCFUNC("asm/func/BlackPantherObj_UpdateBomb.inc"); }

NAKED void BlackPantherObj_UpdateBat(BlackPanther* p, BlackPantherObj* obj) { INCFUNC("asm/func/BlackPantherObj_UpdateBat.inc"); }

NAKED void BlackPantherObj_UpdateBee(BlackPanther* p, BlackPantherObj* obj) { INCFUNC("asm/func/BlackPantherObj_UpdateBee.inc"); }

void BlackPanther_UpdateObjs(BlackPanther* p) {
  BlackPantherObj* obj = p->objs;
  s32 i;

  for (i = 0; i < 32; i++, obj++) {
    if (obj->active) {
      obj->flags = 0;
      if (obj->updateCallback != NULL) {
        obj->updateCallback(p, obj);
      }
      obj->timer++;
    }
  }
}

void BlackPanther_RemoveObjs(BlackPanther* p) {
  BlackPantherObj* obj = p->objs;
  s32 i;

  for (i = 0; i < 32; i++, obj++) {
    if (obj->active) {
      BlackPantherObj_Remove(p, obj);
    }
  }
}

BlackPantherObj* BlackPanther_FindFreeObj(BlackPanther* p) {
  BlackPantherObj* obj = p->objs;
  s32 i;

  for (i = 0; i < 32; i++, obj++) {
    if (!obj->active) {
      return obj;
    }
  }
  return NULL;
}

// 残差1箇所 (44/44): bombScore を読む定数の仮レジスタが原典は r2, こちらは r1
// Tier A-C は試済 (lane と score のローカル化), 未: 引数の型
NON_MATCH void BlackPanther_SpawnBomb(BlackPanther* p) {
#ifdef NONMATCHING_C
  BlackPantherObj* obj = BlackPanther_FindFreeObj(p);

  if (obj != NULL) {
    s32 lane = Mod(Random(), 3);

    BlackPantherObj_Init(p, obj, p->bombScore, lane, 0);
    AuxAnim_SetAnim(&obj->anim, p->animFiles[0], 2, 0, 0);
    BlackPantherObj_SetUpdate(obj, BlackPantherObj_UpdateBomb);
  }
#else
  INCFUNC("asm/func/BlackPanther_SpawnBomb.inc");
#endif
}

NAKED void BlackPanther_SpawnBat(BlackPanther* p) { INCFUNC("asm/func/BlackPanther_SpawnBat.inc"); }

NAKED void BlackPanther_SpawnBee(BlackPanther* p) { INCFUNC("asm/func/BlackPanther_SpawnBee.inc"); }

NAKED bool32 BlackPantherElem_CheckObjHit(BlackPanther* p, BlackPantherElem* elem, s32 param_3) { INCFUNC("asm/func/BlackPantherElem_CheckObjHit.inc"); }

void BlackPantherElem_StateHidden(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
  }
  elem->flags |= 1;
  elem->stateTimer++;
}

void FUN_08053dcc(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    BlackPantherElem_PlayAnim(p, elem, 0, 1, 0, 0);
  }
  elem->stateTimer++;
}

void FUN_08053dfc(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    BlackPantherElem_PlayAnim(p, elem, 1, 1, 0, 0);
  }
  elem->stateTimer++;
}

void FUN_08053e2c(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    if (elem->animKind != 3) {
      BlackPantherElem_PlayAnim(p, elem, 3, 1, 0, 4);
    }
  }
  elem->stateTimer++;
}

NAKED void BlackPantherElem_StateJump(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/BlackPantherElem_StateJump.inc"); }

NAKED void BlackPantherElem_StateChangeLane(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/BlackPantherElem_StateChangeLane.inc"); }

NAKED void FUN_08053fd0(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/FUN_08053fd0.inc"); }

NAKED void FUN_08054054(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/FUN_08054054.inc"); }

void FUN_080540d4(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    BlackPantherElem_PlayAnim(p, elem, 5, 2, 0, 4);
  }
  if (elem->stateTimer == 30) {
    PlaySound_082406e0(SE_MEOW_801);
  }
  if (SpriteHolder_IsAnimEnded(&elem->sprite) && p->endScriptID != 0) {
    VM_ExecByID(p->endScriptID, NULL);
    p->endScriptID = 0;
  }
  elem->stateTimer++;
}

void FUN_08054130(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    BlackPantherElem_PlayAnim(p, elem, p->damaged ? 7 : 6, 2, 0, 4);
  }
  elem->stateTimer++;
}

void FUN_08054170(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    if (p->damaged) {
      BlackPantherElem_PlayAnim(p, elem, 8, 2, 0, 4);
    } else {
      BlackPantherElem_PlayAnim(p, elem, 9, 2, 0, 4);
    }
    PlaySound_082406e0(SE_MEOW_799);
  }
  elem->stateTimer++;
}

void FUN_080541cc(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    BlackPantherElem_PlayAnim(p, elem, 10, 2, 0, 4);
  }
  elem->stateTimer++;
}

NAKED void FUN_080541fc(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/FUN_080541fc.inc"); }

void BlackPantherElem_CtrlHide(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
    BlackPantherElem_SetState(elem, 0);
  }
}

NAKED void FUN_080542ac(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/FUN_080542ac.inc"); }

NAKED void BlackPantherElem_CtrlPlayer(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/BlackPantherElem_CtrlPlayer.inc"); }

void FUN_08054444(BlackPanther* p, BlackPantherElem* elem) {
  p->unk_1e00 = 1;
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
    BlackPantherElem_SetAngle(elem, 0xC0);
  }
  if (elem->state == 3) {
    if (elem->lane != 1) {
      elem->nextLane = 1;
      BlackPantherElem_SetState(elem, 5);
    } else {
      BlackPantherElem_SetState(elem, 2);
    }
  }
}

void FUN_08054490(BlackPanther* p, BlackPantherElem* elem) {
  p->unk_1e00 = 1;
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
    BlackPantherElem_SetState(elem, 8);
  }
}

NAKED void FUN_080544b4(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/FUN_080544b4.inc"); }

NAKED void FUN_08054520(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/FUN_08054520.inc"); }

void BlackPantherElem_CtrlEscape(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
  }
  if (elem->pos.z < 1) {
    elem->pos.z = 0;
  } else {
    elem->pos.z -= 12;
  }
}

void FUN_08054698(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
    elem->pos.z = Q8(8.985);
    BlackPantherElem_SetState(elem, 1);
    elem->angle = 0x40;
    elem->dir8 = 5;
    elem->dir4 = 2;
  }
  if (elem->pos.z >= Q8(10.55)) {
    elem->pos.z = Q8(10.55);
    BlackPantherElem_SetCtrlState(elem, 9);
    BlackPantherElem_ShowEmote(elem, 0, 0, 0);
  } else {
    elem->pos.z += Q8(0.016);
  }
}

void FUN_08054700(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
    BlackPantherElem_SetState(elem, 3);
  }
  if (elem->pos.z >= Q8(13.282)) {
    elem->pos.z = Q8(13.282);
    BlackPantherElem_SetCtrlState(elem, 10);
  } else {
    elem->pos.z += Q8(0.032);
  }
}

void FUN_0805474c(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
    BlackPantherElem_SetState(elem, 8);
    BlackPantherElem_SetAngle(elem, 0x40);
    BlackPantherElem_SetCtrlState(&p->elems[0], 4);
    if (!p->damaged) {
      BlackPanther_AddScore(p, p->bonusScore2, Q6(1), 1);
      p->unk_48 = 1;
    }
  }
}

void FUN_080547a8(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
    VEC3_SET(elem->pos, u16_ARRAY_085ab740[1] - Q8(0.875), Q8(1), Q8(13.8));
    BlackPantherElem_SetState(elem, 9);
    BlackPantherElem_SetAngle(elem, 0);
  }
}

void FUN_080547f4(BlackPanther* p, BlackPantherElem* elem) {
  if (elem->ctrlBegun) {
    elem->ctrlBegun = FALSE;
    VEC3_SET(elem->pos, u16_ARRAY_085ab740[1] + Q8(0.125), Q8(1), Q8(13.8));
    BlackPantherElem_SetState(elem, 9);
    BlackPantherElem_SetAngle(elem, 0xC0);
    BlackPantherElem_ShowEmote(elem, 4, 180, 180);
  }
}

NAKED void BlackPantherElem_Init(BlackPanther* p, BlackPantherElem* elem, s32 idx, s32 param_4) { INCFUNC("asm/func/BlackPantherElem_Init.inc"); }

void BlackPantherElem_Destroy(BlackPanther* p, BlackPantherElem* elem) {
  AuxSprite_Remove(&elem->shadowSprite);
  ParticleShadow_Remove(&elem->shadow);
  SpriteHolder_Remove(&elem->sprite);
  Mover_Unlink(&elem->mover);
}

NAKED void BlackPantherElem_Update(BlackPanther* p, BlackPantherElem* elem) { INCFUNC("asm/func/BlackPantherElem_Update.inc"); }

void FUN_08054ae4(BlackPanther* p) {
  BlackPantherElem_SetCtrlState(&p->elems[0], 0);
  BlackPantherElem_SetCtrlState(&p->elems[1], 0);
  BlackPantherElem_SetCtrlState(&p->elems[3], 0);
  BlackPantherElem_SetCtrlState(&p->elems[2], 11);
  BlackPantherElem_SetCtrlState(&p->elems[4], 12);
  p->fadeMode = 1;
  gObjBrightness = 0;
  gObjPlttBlendColor = RGB(4, 4, 4);
}

missing BlackPanther_HideScorePopup(BlackPanther* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite_Hide(&p->mainSprites2[i]);
  }
}

// 表示する得点を score へ近づけて描く
void BlackPanther_UpdateScore(BlackPanther* p) {
  s32 diff = p->score - p->shownScore;

  if (diff > 4) {
    p->shownScore += 4;
  } else if (diff < -4) {
    p->shownScore -= 4;
  } else {
    p->shownScore = p->score;
  }
  MainSprite_SetNumber(p->mainSprites1, &p->mainGfx, p->shownScore, 4, 30, 32, 152, 8, 0);
}

NAKED void BlackPanther_UpdateScorePopup(BlackPanther* p) { INCFUNC("asm/func/BlackPanther_UpdateScorePopup.inc"); }

void BlackPanther_UpdateComboNumber(BlackPanther* p) { MainSprite_SetNumber(p->mainSprites3, &p->mainGfx, p->combo, 3, 30, 32, 144, 8, 0); }

NAKED void BlackPanther_UpdateHudHidden(BlackPanther* p) { INCFUNC("asm/func/BlackPanther_UpdateHudHidden.inc"); }

s32 BlackPanther_Update(BlackPanther* p) {
  BlackPantherElem* elem;
  s32 i;

  p->sunGauge = gStat->sunGauge;
  BlackPanther_UpdateObjs(p);
  elem = p->elems;
  for (i = 0; i < 5; i++, elem++) {
    BlackPantherElem_Update(p, elem);
  }
  Camera_MoveTo(&p->pos);

  if (p->combo >= 100) {
    if (p->comboTier != 2) {
      p->comboTier = 2;
      PlaySound_082406e0(SONG_651);
    }
  } else if (p->combo >= 30) {
    if (p->comboTier != 1) {
      p->comboTier = 1;
      PlaySound_082406e0(SONG_651);
    }
  } else {
    p->comboTier = 0;
  }

  if (p->comboTier != 0) {
    if (p->comboTier == 1) {
      AuxSprite_SetPoseIdx(&p->auxSprites1[1], 4);
    } else if (p->comboTier == 2) {
      AuxSprite_SetPoseIdx(&p->auxSprites1[1], 5);
    }
    for (i = 0; i < 6; i++) {
      AuxSprite_Show(&p->auxSprites1[i]);
    }
  } else {
    for (i = 0; i < 6; i++) {
      AuxSprite_Hide(&p->auxSprites1[i]);
    }
  }

  BlackPanther_UpdateScore(p);
  BlackPanther_UpdateScorePopup(p);
  BlackPanther_UpdateComboNumber(p);

  if (p->fadeMode == 1) {
    gObjBrightness += 4;
    if (gObjBrightness >= 64) {
      gObjBrightness = 64;
      p->fadeMode = 0;
    }
  } else if (p->fadeMode == 2) {
    gObjBrightness -= 4;
    if (gObjBrightness <= 0) {
      gObjBrightness = 0;
      p->fadeMode = 0;
    }
  }

  if (p->unk_31 != 0) {
    if (--p->unk_31 == 0) {
      FUN_08054ae4(p);
    }
  }

  BlackPanther_UpdateHudHidden(p);
  MINIGAME_SCORE = p->score;
  MINIGAME_MAX_COMBO = p->maxCombo;
  p->frameCounter++;
  return 0;
}

s32 BlackPanther_Destroy(BlackPanther* p) {
  BlackPantherElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 5; i++, elem++) {
    BlackPantherElem_Destroy(p, elem);
  }
  for (i = 0; i < 4; i++) {
    MainSprite_Remove(&p->mainSprites1[i]);
  }
  for (i = 0; i < 4; i++) {
    MainSprite_Remove(&p->mainSprites2[i]);
  }
  for (i = 0; i < 3; i++) {
    MainSprite_Remove(&p->mainSprites3[i]);
  }
  for (i = 0; i < 6; i++) {
    AuxSprite_Remove(&p->auxSprites1[i]);
  }
  for (i = 0; i < 2; i++) {
    AuxSprite_Remove(&p->auxSprites2[i]);
  }
  BlackPanther_RemoveObjs(p);
  SetBGPrioDirect(0, 0);
  SetBGPrioDirect(1, 1);
  SetBGPrioDirect(2, 2);
  SetBGPrioDirect(3, 3);
  sBlackPanther = NULL;
  return 0;
}

s32 BlackPanther_Init(BlackPanther* p, u32 id, u32 _) {
  MainSpriteGfxFile* f;
  s32 idx[5];
  BlackPantherElem* elem;
  const u16* ids;
  s32* cur;
  rgb555 color;
  Vec3 pos;
  s32 i;

  sBlackPanther = p;
  gRandTableIdx = (gFrameCounter + Time_GetMinute() * 60 + Time_GetSecond()) & 0x3FF;
  SetBGPrioDirect(0, 3);
  SetBGPrioDirect(1, 3);
  SetBGPrioDirect(2, 3);
  SetBGPrioDirect(3, 3);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  if (f == NULL) {
    return -1;
  }
  p->mainGfx = *f;
  OpenMainSpriteFile(&p->mainGfx, f);

  p->animFiles[0] = GetFile(DIR_ANIMATION, ANIM_871C);
  p->animFiles[1] = GetFile(DIR_ANIMATION, ANIM_BAT);
  p->animFiles[2] = GetFile(DIR_ANIMATION, ANIM_BEE);
  p->animFiles[3] = GetFile(DIR_ANIMATION, ANIM_6830);

  for (i = 0; i < 7; i++) {
    if (BlackPantherEntry_ARRAY_085ab748[i].unk_08 == 2) {
      f = GetFile(DIR_MAIN_SPRITE, BlackPantherEntry_ARRAY_085ab748[i].id);
      if (f == NULL) {
        return -1;
      }
      p->gfx[i] = *f;
      OpenMainSpriteFile(&p->gfx[i], f);
    }
  }

  if (VM_SeekToNamedArg('c')) {
    p->pos.x = VM_GetValue();
    p->pos.y = VM_GetValue();
    p->pos.z = VM_GetValue();
  } else {
    p->pos.x = 0, p->pos.y = 0, p->pos.z = 0;
  }
  Camera_MoveTo(&p->pos);
  p->endScriptID = VM_GetNamedArgValue('p', 0);

  if (VM_SeekToNamedArg('C')) {
    for (i = 0; i < 5; i++) {
      idx[i] = VM_GetValue();
    }
  } else {
    idx[0] = 0;
    idx[1] = 7;
    idx[2] = 2;
    idx[3] = 5;
    idx[4] = 1;
  }

  Video_GetAuxSprite(&p->auxGfx1, SPRITE_EFF_1C1B);
  p->auxGfx1.plttID = 0x7584;
  p->auxGfx1.pltt = p->pltt;
  color = RGB(20, 20, 20);
  for (i = 0; i < 16; i++) {
    p->pltt[i] = color;
  }

  elem = p->elems;
  ids = u16_ARRAY_085ab908;
  cur = idx;
  for (i = 0; i < 5; i++, elem++) {
    BlackPantherElem_Init(p, elem, *cur++, *ids);
    ids++;
  }
  BlackPantherElem_SetCtrlState(&p->elems[0], 1);
  BlackPantherElem_SetCtrlState(&p->elems[1], 5);

  p->unk_20 = 3;
  p->gap = 200;
  p->gapTarget = 200;
  p->score = 0;

  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->mainSprites1[i], &p->mainGfx, 30, SPRFLAG_SCREEN_COORD, 0, 0, 60, 0);
    MainSprite_Add(&p->mainSprites2[i], &p->mainGfx, 30, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, 0);
  }

  p->spawnCount = 0;
  p->combo = 0;
  p->maxCombo = 0;

  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->mainSprites3[i], &p->mainGfx, 30, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, 0);
  }

  pos.x = 66, pos.y = 152, pos.z = 0;
  Video_GetAuxSprite(&p->auxGfx2, SPRITE_PANTHER_BONUS);
  for (i = 0; i < 6; i++) {
    AuxSprite_Add(&p->auxSprites1[i], &p->auxGfx2, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN);
    if (i < 2) {
      p->auxSprites1[i].poseIdx = i + 3;
    } else {
      p->auxSprites1[i].poseIdx = i + 5;
    }
    p->auxSprites1[i].pos = pos;
    p->auxSprites1[i].priority = 0;
    pos.x += 8;
  }

  pos.x = 0, pos.y = 144, pos.z = 0;
  Video_GetAuxSprite(&p->auxGfx3, SPRITE_COMBO_SCORE);
  for (i = 0; i < 2; i++) {
    AuxSprite_Add(&p->auxSprites2[i], &p->auxGfx3, SPRFLAG_SCREEN_COORD);
    AuxSprite_SetPoseIdx(&p->auxSprites2[i], i);
    p->auxSprites2[i].pos = pos;
    p->auxSprites2[i].priority = 0;
    pos.y += 8;
  }

  p->bombScore = 2;
  p->batScore = 4;
  p->beeScore = 6;
  p->bonusScore1 = 50;
  p->bonusScore2 = 500;
  p->finished = 0;
  p->hideHud = 0;
  MINIGAME_ENDED = 0;
  return 0;
}

// 0x5645
BlackPanther* BlackPanther_Create(u32 id, u32 _) {
  BlackPanther* p;

  if (sBlackPanther != NULL) {
    return sBlackPanther;
  }
  p = CreateEntity(ENTITY_UNK_11, sizeof(BlackPanther));
  if (p != NULL) {
    SetEntityRoutine(p, BlackPanther_Update, BlackPanther_Destroy);
    if (BlackPanther_Init(p, id, _) < 0) {
      KillEntity(&p->e);
      return NULL;
    }
  }
  return p;
}

// スクリプトからミニゲームを終わらせる, もう逃げられた後なら何もしない
void Cmd_E70E(void) {
  BlackPanther* p = sBlackPanther;

  if (p != NULL && p->finished == 0) {
    BlackPantherElem_SetCtrlState(&p->elems[0], 3);
    BlackPantherElem_SetCtrlState(&p->elems[1], 7);
    BlackPantherElem_SetCtrlState(&p->elems[3], 8);
    p->spawnEnabled = FALSE;
  }
}

NAKED void Cmd_B294(void) { INCFUNC("asm/func/Cmd_B294.inc"); }
