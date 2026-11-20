#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "particle.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

// 太陽鍛冶のチュートリアル, 材料を選ぶ枠と SUN ゲージ・TIME の画面で, 叩くタイミングの評価 (GREAT/GOOD/BAD) を出す

// ForgeTutorial_ShowRating が撒いてから ForgeTutorial_UpdateRatings が進める、sprites[8..12] 1枚ぶんの再生状態
typedef struct {
  u16 state;  // 0x0, 0=停止, 1..3 が進行段階
  u16 timer;  // 0x2, state ごとの経過フレーム数
} ForgeTutorialEffect;
static_assert(sizeof(ForgeTutorialEffect) == 4);

typedef struct {
  Entity e;                        // 0x000, ENTITY_UNK_11
  bool8 pending;                   // 0x018, ForgeTutorial_SetState が 1 を立て、FUN_0801e26c が立っていたら 0 に戻して真を返す
  u8 state;                        // 0x019, sForgeTutorialStateFuncs の添字, ForgeTutorial_SetState で切り替える, 0..12 の間だけ HUD を描く
  u8 unk_1a;                       // 0x01A, まだ未解析
  u8 unk_1b;                       // 0x01B, _Init が 0 を入れる
  u8 unk_1c;                       // 0x01C, FUN_0801e290 の第2引数
  u8 unk_1d;                       // 0x01D, FUN_0801e290 の第3引数
  u8 unk_1e;                       // 0x01E, FUN_0801e290 が呼ばれるたび +1, _Init が 0 を入れる
  u8 hideTime;                     // 0x01F, 立っているフレームは TIME の数字を消す, 点滅の演出が立てて ForgeTutorial_UpdateHUD が落とす
  u8 hideSunGauge;                 // 0x020, 立っているフレームは SUN ゲージを消す, 点滅の演出が立てて ForgeTutorial_UpdateHUD が落とす
  u8 unk_21;                       // 0x021, FUN_0801eb64 が 16 を入れて毎フレーム 1 減らすフェードの残りフレーム数
  u8 unk_22;                       // 0x022, FUN_0801eb64 が A を押したときに立てる
  u8 unk_23;                       // 0x023, まだ未解析
  u32 stateTimer;                  // 0x024, state を切り替えてからのフレーム数, FUN_0801ec4c / FUN_0801f308 が符号なしで閾値と比べる
  Tilemaps* tilemap;               // 0x028, MP_KAJI or MP_SYSTEM
  rgb555* plttSrc;                 // 0x02C, BGP_KAJI
  s16 unk_30;                      // 0x030, FUN_0801eaac が markerX の下限として比べる
  s16 unk_32;                      // 0x032, FUN_0801eaac が markerX の上限として比べる
  s16 unk_34;                      // 0x034, FUN_0801ea34 が ×32 して markerX32 の目標値として比べる
  s16 markerX;                     // 0x036, ゲージの目盛り sprites[5] の位置 (0..176), markerX32 >> 5, FUN_0801ed18 が 0xB0 を入れる, FUN_0801f130 が unk_34 と比べる
  u8 zone;                         // 0x038, markerX が unk_30 未満なら 1, unk_32 未満なら 2, それ以上なら 3, sprites[7] のアニメを切り替える
  u8 unk_39;                       // 0x039, FUN_0801eaac が判定結果を入れ、PlayForgeStrikeSE へ渡す
  u8 ratingIdx;                    // 0x03A, ForgeTutorial_ShowRating が使う 0..4 を回るカウンタ, effects[] と sprites[8..12] の添字
  u8 unk_3b[0x040 - 0x03B];        // 0x03B, まだ未解析
  u32 sunLevel;                    // 0x040, SUN ゲージの溜まった目盛りの数 (0..10), FUN_0801ed18 が 8 フレームごとに 1 減らし、FUN_0801ec6c が 10 まで増やす, 0 でなければ markerX32 を加算する
  u8 unk_44[0x050 - 0x044];        // 0x044, まだ未解析
  s32 unk_50;                      // 0x050
  s32 unk_54;                      // 0x054, FUN_0801e9b0 が >>5 して sprites[2]/[3] の X 座標にする
  s32 markerX32;                   // 0x058, markerX の 32 倍, ForgeTutorial_Update が 0..0x1600 に収める, FUN_0801f1d4 が毎フレーム 24/32 倍に減衰させる
  s32 unk_5c;                      // 0x05C
  s32 unk_60;                      // 0x060
  u8 unk_64;                       // 0x064
  u8 unk_65;                       // 0x065, まだ未解析
  u8 unk_66;                       // 0x066, ForgeTutorial_ShowRating が MainSprite_SetPose のポーズ番号 (+0x14) に使う
  u8 unk_67;                       // 0x067, FUN_0801e980 / FUN_0801e998 が sprites[0].pos.x へ写す
  u8 unk_68;                       // 0x068, まだ未解析
  u8 unk_69;                       // 0x069, FUN_0801f0e4 が 60 を入れる
  u8 unk_6a;                       // 0x06A, FUN_0801f0e4 が 3 を入れる
  u8 unk_6b;                       // 0x06B, FUN_0801f0a4 / FUN_0801f0e4 が使うカウンタ
  u32 unk_6c;                      // 0x06C, 状態ごとの経過フレーム数, 各状態関数が毎フレーム +1 する
  u8 unk_70[0x07C - 0x070];        // 0x070, まだ未解析
  s32 unk_7c;                      // 0x07C, FUN_0801eaac が 100 を上限に加点する
  s32 unk_80;                      // 0x080, FUN_0801eaac がぴったり合った回数を数える
  s32 unk_84;                      // 0x084, FUN_0801eaac が範囲内で外した回数を数える
  s32 unk_88;                      // 0x088, FUN_0801eaac が範囲外だった回数を数える
  s32 timeFrames;                  // 0x08C, TIME に出すフレーム数, FUN_0801e4b0 が 3600 (60 秒) を入れる
  s32 endScriptID;                 // 0x090, '.e=0', 終わるときに VM_ExecByID するスクリプト ID
  u8 unk_94[0x09C - 0x094];        // 0x094, まだ未解析
  ForgeTutorialEffect effects[5];  // 0x09C, sprites[8..12] と1対1で対応する再生状態
  MainSpriteGfx gfx0;              // 0x0B0, SPR_UI_MISC
  MainSpriteGfx gfx1;              // 0x0D0, SPR_UI_START_MENU
  MainSpriteGfx gfx2;              // 0x0F0, SPR_INVENTORY_ICONS
  MainSpriteGfx gfx3;              // 0x110, SPR_MARKERS
  ParticleGroup* ptclGroup;        // 0x130, PTCL_GROUP_0
  Particle ptcls[4];               // 0x134, _Destroy が stride 0x28 で4個 Particle_Remove する
  WeaponData weapon;               // 0x1D4, _Init が gWeaponDB[0x0F] を丸ごとコピーする
  MainSprite sprites[13];          // 0x1F8, ForgeTutorial_AddHUDSprites が13個まとめて MainSprite_Add し、FUN_0801e960 がまとめて Remove する
  MainSprite sprite;               // 0x6D8, _Destroy が MainSprite_Remove に渡す
  rgb555 pltt[16];                 // 0x738, FUN_0801e4b0 が gObjPlttData + 0x53E0 から16色コピーして sprites[5].pltt に渡す
  u8* messageScript;               // 0x758, '.E' の後の VM_GetPC_Proxy(), MessageWindow_Start に渡す
  u8 unk_75c[1884 - 0x75C];        // 0x75C, まだ未解析
} ForgeTutorial;
static_assert(sizeof(ForgeTutorial) == 1884);

void PlayForgeStrikeSE(u32 _, s32 kind);
void Video_DrawBGNumber(s32 bg, s32 x, s32 y, u32 n, u32 baseTile, s32 digits, u32 pltt);

// unk_1a を次の段へ進め、段ごとの経過フレーム数を測り直す
static inline void SetSubState(ForgeTutorial* p, u8 state) {
  p->unk_1a = state;
  p->unk_6c = 0;
}

bool32 FUN_0801e26c(ForgeTutorial* p) {
  if (p->pending == TRUE) {
    p->pending = FALSE;
    return TRUE;
  }
  return FALSE;
}

void ForgeTutorial_SetState(ForgeTutorial* p, u8 a) {
  p->state = a;
  p->stateTimer = 0;
  p->pending = TRUE;
}

void FUN_0801e290(ForgeTutorial* p, u8 a, u8 b) {
  p->unk_1c = a;
  p->unk_1d = b;
  p->unk_1e++;
  ForgeTutorial_SetState(p, 0);
}

s32 FUN_0801e2a8(ForgeTutorial* p, s32 bgIndex) {
  p->tilemap = GetFile(DIR_TILE_MAP, MP_KAJI);
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, &bgIndex);
  SetBGPrioDirect(2, 2);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  p->plttSrc = GetBgPlttFile(BGP_KAJI)->body;
  CpuCopy32(&p->plttSrc[208], &gBgPlttBuffer[208], 48 * sizeof(rgb555));
  return 0;
}

s32 FUN_0801e328(ForgeTutorial* p) {
  s32 bgIndex;

  p->tilemap = GetFile(DIR_TILE_MAP, MP_SYSTEM);
  bgIndex = 2;
  Video_SetupBGLayout(0, 0, p->tilemap, 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(0, 0, 0, 0, -24);
  return 0;
}

// 次の評価スプライトに今回の評価のポーズを出して動かし始める
void ForgeTutorial_ShowRating(ForgeTutorial* p) {
  ForgeTutorialEffect* eff = &p->effects[p->ratingIdx];
  MainSprite* spr = &p->sprites[8 + p->ratingIdx];

  MainSprite_SetPose(spr, &p->gfx0, p->unk_66 + 20, PLAYMODE_PAUSE);
  MainSprite_Show(spr);
  eff->state = 1;
  eff->timer = 0;
  p->ratingIdx++;
  if (p->ratingIdx > 4) {
    p->ratingIdx = 0;
  }
}

// sprites[8..12] に出した打撃評価のポップアップを1フレーム進める
void ForgeTutorial_UpdateRatings(ForgeTutorial* p) {
  ForgeTutorialEffect* eff = p->effects;
  MainSprite* sprite = &p->sprites[8];
  s32 i;

  for (i = 0; i < 5; i++, eff++, sprite++) {
    switch (eff->state) {
      case 0: {
        break;
      }
      case 1: {
        sprite->pos.x = (8 - eff->timer) * 8 + 4;
        if (eff->timer >= 8) {
          sprite->pos.x = 4;
          eff->state = 2;
          eff->timer = 0;
        }
        break;
      }
      case 2: {
        if (eff->timer >= 64) {
          eff->state = 3;
          eff->timer = 0;
          sprite->flags |= SPRFLAG_BLINK_ODD;
        }
        break;
      }
      case 3: {
        if (eff->timer >= 8) {
          eff->state = 0;
          eff->timer = 0;
          sprite->flags = (sprite->flags & ~SPRFLAG_BLINK_ODD) | SPRFLAG_HIDDEN;
        }
        break;
      }
    }
    eff->timer++;
  }
}

// HUD のスプライト 13 枚を隠したまま追加する
void ForgeTutorial_AddHUDSprites(ForgeTutorial* p) {
  Vec3 pos;
  s32 i;

  Vec3_Clear(&pos);
  for (i = 0; i < 13; i++) {
    MainSprite_Add(&p->sprites[i], &p->gfx0, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_PAUSE, 60, &pos);
  }
}

// 残差1命令: sprites[4] の MainSprite_SetPose だけ、原典はポーズ番号 6 を r0/r1 の設定より先に materialize する
// 他の8箇所の SetPose は一致, この1箇所だけ -2 の定数を新しく作る (|= から &= ~ に変わる) 場所と重なっている
// Tier A-C は試済 (ポインタ走査ループ, y の誘導変数の明示, 宣言と同時の初期化), 未: inline 包みは sprites[1] の順序違いと両立しない
NON_MATCH s32 FUN_0801e4b0(ForgeTutorial* p) {
#ifdef NONMATCHING_C
  WeaponData* w = &p->weapon;
  MainSprite* spr;
  s32 i;
  s32 y;

  p->timeFrames = 3600;
  p->unk_34 = w->durability;
  p->unk_30 = p->unk_34 - 20;
  p->unk_32 = p->unk_34 + 20;

  if (p->unk_30 < 0) {
    p->unk_30 = 0;
  } else if (p->unk_30 > 176) {
    p->unk_30 = 176;
  }

  if (p->unk_32 < 0) {
    p->unk_32 = 0;
  } else if (p->unk_32 > 176) {
    p->unk_32 = 176;
  }

  p->markerX = 0;

  spr = &p->sprites[0];
  spr->pos.x = 0;
  MainSprite_SetPose(spr, &p->gfx0, 4, PLAYMODE_PAUSE);
  spr->priority = 2;
  spr->flags |= SPRFLAG_HIDDEN;

  spr = &p->sprites[1];
  spr->pos.x = 0;
  MainSprite_SetPose(spr, &p->gfx0, 3, PLAYMODE_PAUSE);
  spr->flags |= SPRFLAG_HIDDEN;
  spr->priority = 2;

  spr = &p->sprites[2];
  spr->pos.x = p->unk_30;
  MainSprite_SetPose(spr, &p->gfx0, 1, PLAYMODE_PAUSE);
  spr->priority = 2;
  spr->flags |= SPRFLAG_HIDDEN;

  spr = &p->sprites[3];
  spr->pos.x = p->unk_32;
  MainSprite_SetPose(spr, &p->gfx0, 2, PLAYMODE_PAUSE);
  spr->priority = 2;
  spr->flags |= SPRFLAG_HIDDEN;

  spr = &p->sprites[4];
  spr->pos.x = p->unk_34;
  MainSprite_SetPose(spr, &p->gfx0, 6, PLAYMODE_PAUSE);
  spr->priority = 2;
  spr->flags &= ~SPRFLAG_HIDDEN;

  spr = &p->sprites[5];
  spr->pos.x = p->markerX - 176;
  MainSprite_SetPose(spr, &p->gfx0, 9, PLAYMODE_PAUSE);
  spr->priority = 3;
  spr->flags &= ~SPRFLAG_HIDDEN;
  CpuCopy32(&gObjPlttData[671 * 16], p->pltt, sizeof(p->pltt));
  spr->plttID = 0x8100;
  spr->pltt = p->pltt;

  spr = &p->sprites[6];
  spr->pos.x = 0;
  MainSprite_SetPose(spr, &p->gfx0, 10, PLAYMODE_PAUSE);
  spr->priority = 3;
  spr->flags &= ~SPRFLAG_HIDDEN;

  spr = &p->sprites[7];
  spr->pos.x = 0;
  MainSprite_SetAnim(spr, &p->gfx0, 0, PLAYMODE_LOOP, 0);
  spr->priority = 2;
  spr->flags &= ~SPRFLAG_HIDDEN;

  spr = &p->sprites[8];
  y = 32;
  for (i = 0; i < 5; i++, spr++, y += 8) {
    spr->pos.x = 8, spr->pos.y = y;
    MainSprite_SetPose(spr, &p->gfx0, 22, PLAYMODE_PAUSE);
    spr->priority = 0;
    spr->flags |= SPRFLAG_HIDDEN;
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_0801e4b0.inc");
#endif
}

// unk_60 の進み具合に応じて、pltt[15] を (31, 4, 0) から元の色へ 1/32 刻みで寄せていく
void FUN_0801e6a0(ForgeTutorial* p) {
  rgb555* pal = &gObjPlttData[671 * 16];
  s32 t = Div(p->unk_60 * 32, 5);
  s32 u = 32 - t;
  s32 r = ((u * 31) + (pal[15] & 0x1F) * t) >> 5;
  s32 g = ((u * 4) + ((pal[15] >> 5) & 0x1F) * t) >> 5;
  s32 b = (((pal[15] >> 10) & 0x1F) * t) >> 5;

  p->pltt[15] = (r & 0x1F) + ((g & 0x1F) << 5) + ((b & 0x1F) << 10);
}

void FUN_0801e708(ForgeTutorial* p) {
  s32 i;

  for (i = 0; i < 13; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

// HUD を1フレーム進める, 目盛りの位置とゾーンのアニメ, SUN ゲージと TIME の表示, 評価のポップアップ, 原典は return を書いていない
s32 ForgeTutorial_UpdateHUD(ForgeTutorial* p) {
  MainSprite* spr;
  s32 i;

  spr = &p->sprites[5];
  spr->pos.x = p->markerX - 176;
  spr = &p->sprites[7];
  if (p->markerX < p->unk_30) {
    if (p->zone != 1) {
      p->zone = 1;
      MainSprite_SetAnim(spr, &p->gfx0, 0, PLAYMODE_LOOP, 0);
    }
  } else if (p->markerX < p->unk_32) {
    if (p->zone != 2) {
      p->zone = 2;
      MainSprite_SetAnim(spr, &p->gfx0, 1, PLAYMODE_LOOP, 0);
    }
  } else {
    if (p->zone != 3) {
      p->zone = 3;
      MainSprite_SetAnim(spr, &p->gfx0, 2, PLAYMODE_LOOP, 0);
    }
  }
  for (i = 0; i < 13; i++) {
    MainSprite_AdvanceAnim(&p->sprites[i], &p->gfx0);
  }
  if (p->hideSunGauge) {
    p->hideSunGauge = 0;
    for (i = -3; i <= 10; i++) {  // i=0 スタートだと一致する形がわからなかった
      Video_SetBGTile(2, i + 6, 16, 1, 0, 15);
    }
  } else {
    Video_SetBGTile(2, 3, 16, 2, 0, 13);
    Video_SetBGTile(2, 4, 16, 3, 0, 13);
    Video_SetBGTile(2, 5, 16, 4, 0, 13);
    for (i = 0; i < p->sunLevel; i++) {
      Video_SetBGTile(2, i + 6, 16, 5, 0, 13);
    }
    for (; i < 10; i++) {
      Video_SetBGTile(2, i + 6, 16, 6, 0, 13);
    }
    Video_SetBGTile(2, 16, 16, 7, 0, 15);
  }
  if (p->hideTime) {
    p->hideTime = 0;
    Video_SetBGTile(2, 21, 16, 1, 0, 15);
    Video_SetBGTile(2, 22, 16, 1, 0, 15);
    Video_SetBGTile(2, 23, 16, 1, 0, 15);
    Video_SetBGTile(2, 24, 16, 1, 0, 15);
    Video_SetBGTile(2, 25, 16, 1, 0, 15);
  } else {
    s32 frac = Div(Mod(p->timeFrames, 60) * 100, 60);
    Video_DrawBGNumber(2, 21, 16, Div(p->timeFrames, 60), 17, 2, 13);
    Video_SetBGTile(2, 23, 16, 27, 0, 13);
    Video_DrawBGNumber(2, 24, 16, frac, 17, 2, 13);
  }
  FUN_0801e6a0(p);
  ForgeTutorial_UpdateRatings(p);
}

void FUN_0801e960(ForgeTutorial* p) {
  MainSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 13; spr++, i++) {
    MainSprite_Remove(spr);
  }
}

void FUN_0801e980(ForgeTutorial* p) {
  MainSprite* spr = &p->sprites[0];

  spr->pos.x = p->unk_67;
  MainSprite_Show(spr);
}

void FUN_0801e998(ForgeTutorial* p) {
  MainSprite* spr = &p->sprites[0];

  spr->pos.x = p->unk_67;
  MainSprite_Hide(spr);
}

void FUN_0801e9b0(ForgeTutorial* p) {
  s32 x = p->unk_54 >> 5;
  MainSprite* spr;

  spr = &p->sprites[2];
  spr->pos.x = x - 24;
  if (spr->pos.x < 0) {
    spr->pos.x = 0;
  } else if (spr->pos.x > 0xB0) {
    spr->pos.x = 0xB0;
  }
  MainSprite_Show(spr);
  spr = &p->sprites[3];
  spr->pos.x = x + 24;
  if (spr->pos.x < 0) {
    spr->pos.x = 0;
  } else if (spr->pos.x > 0xB0) {
    spr->pos.x = 0xB0;
  }
  MainSprite_Show(spr);
}

void FUN_0801ea14(ForgeTutorial* p) {
  MainSprite* spr = &p->sprites[2];

  MainSprite_Hide(spr);
  spr = &p->sprites[3];
  MainSprite_Hide(spr);
}

// unk_50 を往復させながら markerX32 (= unk_54 + unk_50) を更新し、目標の unk_34 に届いていたら真を返す
s32 FUN_0801ea34(ForgeTutorial* p) {
  s32 reached = FALSE;

  if (p->unk_5c != 0) {
    p->unk_50 += (p->sunLevel + 2) * 4;
    if (p->unk_50 > 0x2FF) {
      p->unk_50 = 0x300;
      p->unk_5c = 0;
    }
  } else {
    p->unk_50 -= (p->sunLevel + 2) * 4;
    if (p->unk_50 <= -0x300) {
      p->unk_50 = -0x300;
      p->unk_5c = 1;
    }
  }
  p->markerX32 = p->unk_54 + p->unk_50;
  if (p->markerX32 < 0) {
    p->markerX32 = 0;
  } else if (p->markerX32 > 0xB0 * 32) {
    p->markerX32 = 0xB0 * 32;
  }
  if (p->markerX32 == p->unk_34 * 32) {
    reached = TRUE;
  }
  return reached;
}

// markerX が unk_30..unk_32 の範囲にどれだけ近く止まったかを採点し、成否に応じた効果音とポーズを選ぶ
void FUN_0801eaac(ForgeTutorial* p, s32 kind) {
  s32 diff = abs(p->unk_34 - p->markerX);
  p->unk_67 = p->markerX;
  FUN_0801e980(p);

  if (p->markerX >= p->unk_30 && p->markerX <= p->unk_32) {
    if (diff <= 1) {
      p->unk_39 = 1;
      p->unk_80++;
      p->unk_7c += 100;
      p->unk_66 = 0;
    } else {
      p->unk_39 = 0;
      if (diff <= 99) {
        p->unk_7c += 100 - diff;
      }
      p->unk_84++;
      p->unk_66 = 1;
    }
  } else {
    p->unk_88++;
    p->unk_66 = 2;
  }

  PlayForgeStrikeSE(p->unk_39, kind);
  ForgeTutorial_ShowRating(p);
  p->unk_60++;
}

// 残差4命令: Video_SetBGBlend の2箇所の呼び出しで、原典は読んだ値を r1 に置いて第2/第3引数を別レジスタ経由で渡す (こちらは値が r2 に乗り引数を直接作る)
// Tier A-B は試済 (ローカル変数の有無/スコープ, インライン包み), 未: Tier C
NON_MATCH void FUN_0801eb64(ForgeTutorial* p) {
#ifdef NONMATCHING_C
  if (FUN_0801e26c(p)) {
    MessageWindow_ShowLine(p->unk_1e);
    p->unk_22 = 0;
  }

  if (p->unk_1c != 0 && p->stateTimer <= 15) {
    u32 n = p->stateTimer >> 1;
    Video_SetBGBlend(0, 8 - n, n + 8);
  }

  if (p->stateTimer > 31 && p->unk_22 == 0 && (gInput[0].pressed & A_BUTTON)) {
    p->unk_21 = 16;
    p->unk_22 = 1;
    PlaySound_082406e0(SE_TEXT_SHOW);
    MainSprite_SetFlags(&p->sprite, SPRFLAG_HIDDEN);
  }

  if (p->unk_22 != 0) {
    if (p->unk_21 == 0) {
      p->unk_1b++;
      ForgeTutorial_SetState(p, p->unk_1b);
    } else {
      p->unk_21--;
      if (p->unk_1d != 0) {
        u32 n = p->unk_21;
        Video_SetBGBlend(0, 16 - n, (n >> 1) + 8);
      }
    }
  } else {
    if (p->stateTimer == 32) {
      MainSprite_ClearFlags(&p->sprite, SPRFLAG_HIDDEN);
    }
    MainSprite_AdvanceAnim(&p->sprite, &p->gfx3);
  }
#else
  INCFUNC("asm/func/FUN_0801eb64.inc");
#endif
}

void FUN_0801ec4c(ForgeTutorial* p) {
  FUN_0801e26c(p);
  if (p->stateTimer >= SECOND(1)) {
    FUN_0801e290(p, 0, 1);
  }
}

// 90フレーム点滅させてから sunLevel を溜めて markerX32 を 0x1600 まで引き上げる2段の演出
void FUN_0801ec6c(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    p->markerX = 0;
    SetSubState(p, 0);
  }

  switch (p->unk_1a) {
    case 0: {
      if ((p->stateTimer & 0x1F) <= 15) {
        p->hideSunGauge = 1;
      }
      if ((p->stateTimer & 0x1F) == 16) {
        PlaySound_082406e0(SONG_688);
      }
      if (p->unk_6c > 89) {
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 1: {
      if ((p->stateTimer & 7) == 0 && p->sunLevel <= 9) {
        p->sunLevel++;
      }
      if (p->sunLevel != 0) {
        p->markerX32 += p->sunLevel * 8;
        if (p->markerX32 > 0x15FF) {
          p->markerX32 = 0x1600;
        }
      } else {
        p->markerX32 = (p->markerX32 * 60) >> 6;
      }
      if (p->unk_6c > 139) {
        FUN_0801e290(p, 1, 1);
      }
      break;
    }
  }

  p->unk_6c++;
}

// sunLevel を 8 フレームごとに 1 減らし、残っている間は markerX32 を加算、尽きたら 60/64 倍に減衰させる
void FUN_0801ed18(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    p->markerX = 0xB0;
  }

  if ((p->stateTimer & 7) == 0 && p->sunLevel != 0) {
    p->sunLevel--;
  }

  if (p->sunLevel != 0) {
    p->markerX32 += p->sunLevel * 8;
    if (p->markerX32 > 0x15FF) {
      p->markerX32 = 0x1600;
    }
  } else {
    p->markerX32 = (p->markerX32 * 60) >> 6;
  }

  if (p->stateTimer > 139) {
    FUN_0801e290(p, 1, 1);
  }
}

// markerX が目標の手前に届くまで markerX32 を加速させ、届いたら sprites[5] を3回点滅させる
void FUN_0801ed7c(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    p->markerX = 0;
    p->unk_69 = 60;
    p->unk_6a = 3;
  }

  if ((p->stateTimer & 7) == 0 && p->sunLevel <= 3) {
    p->sunLevel++;
  }

  if (p->markerX < p->unk_34 - 40) {
    if (p->sunLevel != 0) {
      p->markerX32 += p->sunLevel * 8;
      if (p->markerX32 > 0x15FF) {
        p->markerX32 = 0x1600;
      }
    } else {
      p->markerX32 = (p->markerX32 * 60) >> 6;
    }
  } else {
    p->markerX32 = (p->unk_34 - 40) * 32;
    if (p->unk_6a != 0) {
      if (p->unk_69 != 0) {
        p->unk_69--;
        if (p->unk_69 == 10) {
          MainSprite* spr = &p->sprites[5];

          spr->flags |= SPRFLAG_HIDDEN;
        } else if (p->unk_69 == 0) {
          MainSprite* spr = &p->sprites[5];

          spr->flags &= ~SPRFLAG_HIDDEN;
          p->unk_69 = 30;
          p->unk_6a--;
          PlaySound_082406e0(SONG_688);
        }
      }
    }
  }

  if (p->unk_6a == 0 && p->stateTimer >= SECOND(4)) {
    FUN_0801e290(p, 1, 1);
  }
}

void FUN_0801ee6c(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    p->unk_69 = 60;
    p->unk_6a = 3;
  }
  if (p->unk_6a != 0) {
    if (p->unk_69 != 0) {
      p->unk_69--;
      if (p->unk_69 == 10) {
        MainSprite_Hide(&p->sprites[4]);
      } else if (p->unk_69 == 0) {
        MainSprite_Show(&p->sprites[4]);
        p->unk_69 = 30;
        p->unk_6a--;
        PlaySound_082406e0(SONG_688);
      }
    }
  }
  if (p->unk_6a == 0 && p->stateTimer >= SECOND(4)) {
    FUN_0801e290(p, 1, 1);
  }
}

// ptcls[0] を点滅させながら markerX32 を目標まで上げ、sprites[1] に位置を渡すまでの5段の演出
void FUN_0801eefc(ForgeTutorial* p) {
  Particle* ptcl = p->ptcls;

  if (FUN_0801e26c(p)) {
    ptcl->pos.x = 129, ptcl->pos.y = 120;
    ptcl->flags &= ~SPRFLAG_HIDDEN;
    SetSubState(p, 0);
    p->unk_6a = 3;
  }

  if (p->unk_1a <= 3) {
    if (p->unk_6a != 0) {
      if ((p->stateTimer & 0x1F) <= 15) {
        ptcl->flags |= SPRFLAG_HIDDEN;
      } else {
        ptcl->flags &= ~SPRFLAG_HIDDEN;
      }
      if ((p->unk_6c & 0x1F) == 16) {
        p->unk_6a--;
        PlaySound_082406e0(SONG_688);
      }
    } else {
      ptcl->flags &= ~SPRFLAG_HIDDEN;
    }
  }

  switch (p->unk_1a) {
    case 0: {
      if (p->unk_6c > 120) {
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 1: {
      if (p->markerX < p->unk_34) {
        if (p->sunLevel != 0) {
          p->markerX32 += p->sunLevel * 8;
          if (p->markerX32 > 0x15FF) {
            p->markerX32 = 0x1600;
          }
        } else {
          p->markerX32 = (p->markerX32 * 60) >> 6;
        }
      } else {
        p->markerX32 = p->unk_34 * 32;
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 2: {
      if (p->unk_6c > 60) {
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 3: {
      if (p->unk_6c > 8) {
        MainSprite* spr = &p->sprites[1];

        SetSubState(p, p->unk_1a + 1);
        ptcl->flags |= SPRFLAG_HIDDEN;
        p->unk_54 = p->markerX32;
        spr->pos.x = p->unk_54 >> 5;
        FUN_0801e9b0(p);
      }
      break;
    }
    case 4: {
      if (p->unk_6c > 60) {
        FUN_0801e290(p, 1, 1);
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
  }

  p->unk_6c++;
}

void FUN_0801f054(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    p->unk_5c = 0;
    p->unk_50 = 0;
    p->unk_60 = 0;
    p->unk_64 = 0;
    p->ratingIdx = 0;
    p->unk_6b = 0;
  }
  if (FUN_0801ea34(p)) {
    p->unk_6b++;
    if (p->unk_6b == 3) {
      FUN_0801e290(p, 1, 1);
    }
  }
}

void FUN_0801f0a4(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    p->unk_6b = 0;
  }
  if (FUN_0801ea34(p)) {
    p->unk_6b++;
    if (p->unk_6b == 3) {
      FUN_0801e290(p, 1, 1);
    }
  }
}

void FUN_0801f0e4(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    p->unk_69 = 60;
    p->unk_6a = 3;
    p->unk_6b = 0;
    FUN_0801eaac(p, 0);
  }
  if (p->unk_6c == 60) {
    FUN_0801e290(p, 1, 1);
  }
  FUN_0801ea34(p);
  p->unk_6c++;
}

// unk_1a を 0→1→2→3→4 と進める4段の演出, 各段は経過フレーム数か markerX が unk_34 に届くまで待つ
void FUN_0801f130(ForgeTutorial* p) {
  u8 state;

  if (FUN_0801e26c(p)) {
    SetSubState(p, 0);
    FUN_0801eaac(p, 1);
  }

  state = p->unk_1a;
  switch (state) {
    case 0: {
      if (p->unk_6c == 40) {
        FUN_0801eaac(p, 2);
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 1: {
      if (p->unk_6c == 40) {
        FUN_0801eaac(p, 1);
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 2: {
      if (p->markerX == p->unk_34) {
        FUN_0801eaac(p, 0);
        SetSubState(p, p->unk_1a + 1);
      }
      break;
    }
    case 3: {
      if (p->unk_6c == 20) {
        SetSubState(p, 4);
        FUN_0801e290(p, 1, 0);
      }
      break;
    }
  }

  FUN_0801ea34(p);
  p->unk_6c++;
}

void FUN_0801f1d4(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    FUN_0801ea14(p);
    FUN_0801e998(p);
  }
  p->markerX32 = (p->markerX32 * 24) >> 5;
  if (p->unk_6c == 120) {
    FUN_0801e290(p, 0, 1);
  }
  p->unk_6c++;
}

// 120フレーム点滅させたあと BG1-BG3 を消して背景を組み直す2段の演出
void FUN_0801f214(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    SetSubState(p, 0);
  }

  switch (p->unk_1a) {
    case 0: {
      if (p->unk_6c <= 89) {
        if ((p->unk_6c & 0x1F) <= 15) {
          p->hideTime = 1;
        }
        if ((p->unk_6c & 0x1F) == 16) {
          PlaySound_082406e0(SONG_688);
        }
      }
      if (p->unk_6c == 120) {
        SetSubState(p, p->unk_1a + 1);
        StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
      }
      break;
    }
    case 1: {
      if (p->unk_6c == 32) {
        SetSubState(p, 2);
        Video_GenerateBGMap(0, 0, 0, 0, -96);
        CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
        CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG2_ON);
        CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG3_ON);
        FUN_0801e708(p);
        StartBgObjPlttFade(2, 4, 4, 4, 4, 0xFFFF, 0);
        FUN_0801e290(p, 1, 0);
        p->sprite.pos.y = 140;
      }
      break;
    }
  }

  p->unk_6c++;
}

void FUN_0801f308(ForgeTutorial* p) {
  FUN_0801e26c(p);
  if (p->stateTimer > 63) {
    FUN_0801e290(p, 0, 0);
  }
}

// BGM をフェードアウトさせ、32フレーム後に BG0 を消して endScriptID のスクリプトを起動する
void FUN_0801f328(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
    Sound_FadeOutBGMTemporarily(5);
  }
  if (p->stateTimer > 31 && p->endScriptID != 0) {
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
    VM_ExecByID(p->endScriptID, NULL);
    p->endScriptID = 0;
  }
}

// FUN_0801f328 と同じ流れだが、スプライトと BG を全部消してからスクリプトを起動する
void FUN_0801f38c(ForgeTutorial* p) {
  if (FUN_0801e26c(p)) {
    MainSprite_Hide(&p->sprite);
    StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
    Sound_FadeOutBGMTemporarily(5);
  }
  if (p->stateTimer > 31 && p->endScriptID != 0) {
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG3_ON);
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG2_ON);
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
    FUN_0801e708(p);
    VM_ExecByID(p->endScriptID, NULL);
    p->endScriptID = 0;
  }
}

// START で最後の state 15 へ飛ばし, 今の state の処理, TIME の減算, 目盛りの位置の更新, HUD の描画をする
s32 ForgeTutorial_Update(ForgeTutorial* p) {
  static void (*const sForgeTutorialStateFuncs[16])(ForgeTutorial*) = {
      FUN_0801eb64,
      FUN_0801ec4c,
      FUN_0801ec6c,
      FUN_0801ed18,
      FUN_0801ed7c,
      FUN_0801ee6c,
      FUN_0801eefc,
      FUN_0801f054,
      FUN_0801f0a4,
      FUN_0801f0e4,
      FUN_0801f130,
      FUN_0801f1d4,
      FUN_0801f214,
      FUN_0801f308,
      FUN_0801f328,
      FUN_0801f38c,
  };  // 0x085AA98C

  if (gInput[0].pressed & START_BUTTON) {
    ForgeTutorial_SetState(p, 15);  // skip
  }
  sForgeTutorialStateFuncs[p->state](p);
  if (p->state != 0 && p->timeFrames != 0) {
    p->timeFrames--;
  }
  p->stateTimer++;
  if (p->markerX32 > 0xB0 * 32) {
    p->markerX32 = 0xB0 * 32;
  } else if (p->markerX32 < 0) {
    p->markerX32 = 0;
  }
  p->markerX = p->markerX32 >> 5;
  if (p->state <= 12) {
    ForgeTutorial_UpdateHUD(p);
  }
  return 0;
}

s32 ForgeTutorial_Destroy(ForgeTutorial* p) {
  Particle* ptcl;
  s32 i;

  FUN_0801e960(p);
  ptcl = p->ptcls;
  for (i = 0; i < 4; ptcl++, i++) {
    Particle_Remove(ptcl);
  }
  MainSprite_Remove(&p->sprite);
  return 0;
}

s32 ForgeTutorial_Init(ForgeTutorial* p) {
  MainSpriteGfxFile* f;
  Vec3 pos;
  s32 i;

  CopyMemory((u8*)&p->weapon, (u8*)&gWeaponDB[WEAPON_MURAMASA], sizeof(WeaponData));
  f = GetFile(DIR_MAIN_SPRITE, SPR_UI_MISC);
  if (f == NULL) {
    return -1;
  }
  p->gfx0 = *f;
  OpenMainSpriteFile(&p->gfx0, f);
  f = GetFile(DIR_MAIN_SPRITE, SPR_UI_START_MENU);
  if (f == NULL) {
    return -1;
  }
  p->gfx1 = *f;
  OpenMainSpriteFile(&p->gfx1, f);
  f = GetFile(DIR_MAIN_SPRITE, SPR_INVENTORY_ICONS);
  if (f == NULL) {
    return -1;
  }
  p->gfx2 = *f;
  OpenMainSpriteFile(&p->gfx2, f);
  f = GetFile(DIR_MAIN_SPRITE, SPR_MARKERS);
  if (f == NULL) {
    return -1;
  }
  p->gfx3 = *f;
  OpenMainSpriteFile(&p->gfx3, f);
  p->endScriptID = VM_GetNamedArgValue('e', 0);
  if (!VM_SeekToNamedArg('E')) {
    return -1;
  }
  p->messageScript = VM_GetPC_Proxy();
  if (p->messageScript == NULL) {
    return -1;
  }
  MessageWindow_Start(p->messageScript);
  MessageWindow_SetRect(1, 1, 30, 6);
  MessageWindow_SetBgPltt(BGP_KAJI);
  MessageWindow_SetInstant(1);
  FUN_0801e2a8(p, 1);
  FUN_0801e328(p);
  ForgeTutorial_AddHUDSprites(p);
  FUN_0801e4b0(p);
  p->ptclGroup = GetParticleGroup(PTCL_GROUP_0);
  for (i = 0; i < 4; i++) {
    Particle_Add(&p->ptcls[i], p->ptclGroup, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN);
    Particle_SetOffset(&p->ptcls[i], -8, -8);
    Particle_SetPose(&p->ptcls[i], p->ptclGroup, 51);
    p->ptcls[i].priority = 1;
    Vec3_Clear(&p->ptcls[i].pos);
  }
  StartBgObjPlttFade(0, 4, 4, 4, 4, 0xFFFF, 0);
  ForgeTutorial_SetState(p, 0);
  p->unk_1b = 0;
  p->unk_1e = 0;
  pos.x = 223, pos.y = 68, pos.z = 0;
  MainSprite_Add(&p->sprite, &p->gfx3, 8, SPRFLAG_NO_CLIP | SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, PLAYMODE_LOOP, 60, &pos);
  MainSprite_SetAnim(&p->sprite, &p->gfx3, 0, PLAYMODE_LOOP, 0);
  sound_08240264(BGM_SOLAR_FORGE);
  return 0;
}

// 0xEF6F, HashName("太陽鍛冶チュートリアル")
ForgeTutorial* ForgeTutorial_Create(void) {
  ForgeTutorial* p = CreateEntity(ENTITY_UNK_11, sizeof(ForgeTutorial));

  if (p != NULL) {
    SetEntityRoutine(p, ForgeTutorial_Update, ForgeTutorial_Destroy);
    if (ForgeTutorial_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
