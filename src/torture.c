#include "camera.h"
#include "entity.h"
#include "global.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

struct Torture;
typedef void(TortureFunc)(struct Torture*);

// 暗黒ローンのおしおき, 返済できなかったときにボタン連打で返済分を発電させるイベント
typedef struct Torture {
  Entity e;                     // 0x000, ENTITY_UNK_8
  u8 unk_18[0x020 - 0x018];     // 0x018, まだ未解析
  AuxSprite sprite0;            // 0x020, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx0;            // 0x04C, SPRITE_DARKGENERATOR
  u16 sprite0Phase;             // 0x068, 0..11 を回り, 4 で割った値が sprite0 のコマ
  u8 unk_6a[2];                 // 0x06A, まだ未解析
  AuxSprite sprite1;            // 0x06C, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx1;            // 0x098, SPRITE_DARKGENERATOR
  u16 unk_b4;                   // 0x0B4
  u16 unk_b6;                   // 0x0B6, _Init が '.N' から 1/2/3/4 を入れる
  AuxSprite sprite2;            // 0x0B8
  AuxSpriteGfx gfx2;            // 0x0E4, SPRITE_DARKGENERATOR
  AuxSprite mashMeter[7];       // 0x100, 連打数 (最大 7) だけコマ 1 (先頭 4 枚) / 2 を出し, 残りは 0
  AuxSpriteGfx meterGfx;        // 0x234, SPRITE_PANTHER_BONUS
  AuxSprite bonusSprites[6];    // 0x250, bonusGfx のコマ 3, 4, 7, 8, 9, 10 を (132, 48) から 8 ずつ右へ並べる
  AuxSpriteGfx bonusGfx;        // 0x358, SPRITE_PANTHER_BONUS
  u16 bonusTimer;               // 0x374, 倍率表示を動かす残りフレーム数, 出すとき 10 (4 までは上へ, 残りは下へ), 下げるとき 4 で 0 になったら隠す
  u8 unk_376[2];                // 0x376, まだ未解析
  MainSpriteGfx uiGfx;          // 0x378, SPRITE_UI_START_MENU
  MainSprite mainSprites[5];    // 0x398, _Destroy が stride 0x60 で5枚 MainSprite_Remove する
  u16 unk_578;                  // 0x578, '.p'
  u16 unk_57a;                  // 0x57A
  u16 soundTimer;               // 0x57C, 0..9 を回り, 0 のときに連打数に応じた効果音を鳴らす
  u16 unk_57e;                  // 0x57E, _Init が 0 を入れる
  u8 unk_580[0x588 - 0x580];    // 0x580, まだ未解析
  u16 mashFrames;               // 0x588, 連打数が 3 を超えているフレームが続いた数, 3 以下で 0 に戻る
  u16 rate2Frames;              // 0x58A, '.t[0]=180', mashFrames がこれを超えると Torture_GetMashRate が 2
  u16 rate5Frames;              // 0x58C, '.t[1]=300', mashFrames がこれを超えると 5
  u16 rate10Frames;             // 0x58E, mashFrames がこれを超えると 10
  u16 mashRate;                 // 0x590, 今の倍率 (1 / 2 / 5 / 10), Torture_GetMashRate の値, Torture_Finish が 1 に戻す
  u8 unk_592[2];                // 0x592, まだ未解析
  u32 unk_594;                  // 0x594
  u32 unk_598;                  // 0x598
  u32 unk_59c;                  // 0x59C
  u32 unk_5a0;                  // 0x5A0
  u32 unk_5a4;                  // 0x5A4
  u32 unk_5a8;                  // 0x5A8
  u32 unk_5ac;                  // 0x5AC
  u8 unk_5b0[2];                // 0x5B0, まだ未解析
  u16 unk_5b2;                  // 0x5B2, '.r=300'
  u8 unk_5b4[0x5B6 - 0x5B4];    // 0x5B4, まだ未解析
  u16 stateTimer;               // 0x5B6
  TortureFunc* updateCallback;  // 0x5B8
} Torture;
static_assert(sizeof(Torture) == 1468);

IWRAM_DATA Torture* gTorture = NULL;  // 0x03000158

void Torture_ClearInstance(void) { gTorture = NULL; }

void Torture_SetState(Torture* p, TortureFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

// プレイヤー1の連打の履歴を空にする
void Torture_ResetMash(void) {
  s32 i;

  for (i = 0; i < 32; i++) {
    gPlayerPtr[0]->mashHistory[i] = FALSE;
  }

  gPlayerPtr[0]->mashHits = 0;
}

NAKED void FUN_080bfaac(Torture* p) { INCFUNC("asm/func/FUN_080bfaac.inc"); }

// unk_b4 を unk_b6 ずつ進めて, 8 で割った値を sprite1 のコマ番号にする
void FUN_080bfb74(Torture* p) {
  AuxSprite_SetPoseIdx(&p->sprite1, p->unk_b4 >> 3);
  p->unk_b4 += p->unk_b6;

  if (p->unk_b4 > 23) {
    p->unk_b4 = 0;
  }
}

// 連打のアニメ速度に合わせて sprite0 のコマを進め, 10 フレームおきに連打数に応じた効果音を鳴らす
// step の決め方は条件式の中で代入する形でだけ一致する, if のネストや代入を別の文にすると mashAnimSpeed を読み直す
void Torture_AnimateSprite0(Torture* p) {
  s32 step;

  if (gPlayerPtr[0]->mashAnimSpeed == 0 || (step = Div(128, gPlayerPtr[0]->mashAnimSpeed)) <= 0) {
    step = 1;
  }
  p->sprite0Phase += step;
  if (p->sprite0Phase > 11) {
    p->sprite0Phase -= 12;
  }
  AuxSprite_SetPoseIdx(&p->sprite0, p->sprite0Phase >> 2);
  if (p->soundTimer == 0) {
    if (gPlayerPtr[0]->mashHits < 2) {
      PlaySound_082406e0(SONG_570);
    } else if (gPlayerPtr[0]->mashHits < 4) {
      PlaySound_082406e0(SONG_571);
    } else if (gPlayerPtr[0]->mashHits < 6) {
      PlaySound_082406e0(SONG_572);
    } else {
      PlaySound_082406e0(SONG_573);
    }
  }
  p->soundTimer++;
  if (p->soundTimer > 9) {
    p->soundTimer = 0;
  }
}

// 暗黒ローンの借金 (darkDebts) を4桁の数字で mainSprites[1..4] に出す
void Torture_DrawDebts(Torture* p) {
  s32 digits[4];
  s32 debts;
  s32 i;

  debts = gStat->darkDebts;
  digits[0] = Div(debts, 1000);
  debts -= digits[0] * 1000;
  digits[1] = Div(debts, 100);
  debts -= digits[1] * 100;
  digits[2] = Div(debts, 10);
  debts -= digits[2] * 10;
  digits[3] = debts;
  for (i = 0; i < 4; i++) {
    MainSprite_SetPose(&p->mainSprites[1 + i], &p->uiGfx, digits[i] + 30, PLAYMODE_LOOP);
  }
}

void Torture_ShowMainSprites(Torture* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    p->mainSprites[i].flags &= ~SPRFLAG_HIDDEN;
  }
}

void Torture_HideMainSprites(Torture* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    p->mainSprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

void Torture_CountMashFrames(Torture* p) {
  if (gPlayerPtr[0]->mashHits > 3) {
    p->mashFrames++;
  } else {
    p->mashFrames = 0;
  }
}

// mashFrames がどの区間にあるかを 10 / 5 / 1 / 2 で返す
s32 Torture_GetMashRate(Torture* p) {
  if (p->mashFrames > p->rate10Frames) {
    return 10;
  }
  if (p->mashFrames > p->rate5Frames) {
    return 5;
  }
  if (p->mashFrames > p->rate2Frames) {
    return 2;
  }
  return 1;
}

// 倍率が 1 なら bonusSprites を下げておき, 2 / 5 / 10 なら数字のコマを合わせて出して効果音を鳴らす
void Torture_ShowMashRate(Torture* p) {
  s32 i;

  if (p->mashRate == 1) {
    for (i = 0; i < 6; i++) {
      p->bonusSprites[i].pos.y = 48;
    }
    p->bonusTimer = 4;
    return;
  }
  if (p->mashRate == 2) {
    AuxSprite_SetPoseIdx(&p->bonusSprites[1], 4);
  } else if (p->mashRate == 5) {
    AuxSprite_SetPoseIdx(&p->bonusSprites[1], 5);
  } else if (p->mashRate == 10) {
    AuxSprite_SetPoseIdx(&p->bonusSprites[1], 6);
  }
  for (i = 0; i < 6; i++) {
    p->bonusSprites[i].flags &= ~SPRFLAG_HIDDEN;
    p->bonusSprites[i].pos.y = 56;
  }
  p->bonusTimer = 10;
  PlaySound_082406e0(SONG_651);
}

// bonusTimer の間だけ倍率表示を跳ねさせ, 倍率が 1 に戻ったときは下げてから隠す
void Torture_UpdateBonusSprites(Torture* p) {
  s32 i;

  if (p->bonusTimer != 0) {
    if (p->mashRate == 1) {
      p->bonusTimer--;
      if (p->bonusTimer == 0) {
        for (i = 0; i < 6; i++) {
          p->bonusSprites[i].flags |= SPRFLAG_HIDDEN;
        }
      } else {
        for (i = 0; i < 6; i++) {
          p->bonusSprites[i].pos.y += 2;
        }
      }
    } else {
      if (p->bonusTimer > 3) {
        for (i = 0; i < 6; i++) {
          p->bonusSprites[i].pos.y -= 2;
        }
      } else {
        for (i = 0; i < 6; i++) {
          p->bonusSprites[i].pos.y += 2;
        }
      }
      p->bonusTimer--;
    }
  }
}

void Torture_HideBonusSprites(Torture* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    p->bonusSprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

// 連打数 (最大 7) だけ mashMeter を点け, 先頭 4 枚とそれ以降でコマを変え, 残りは消す
void Torture_UpdateMashMeter(Torture* p) {
  s32 n = gPlayerPtr[0]->mashHits;
  s32 i;

  if (n > 7) {
    n = 7;
  }
  for (i = 0; i < n; i++) {
    if (i < 4) {
      AuxSprite_SetPoseIdx(&p->mashMeter[i], 1);
    } else {
      AuxSprite_SetPoseIdx(&p->mashMeter[i], 2);
    }
  }
  for (; i < 7; i++) {
    AuxSprite_SetPoseIdx(&p->mashMeter[i], 0);
  }
}

void Torture_ShowMashMeter(Torture* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    p->mashMeter[i].flags &= ~SPRFLAG_HIDDEN;
  }
}

void Torture_HideMashMeter(Torture* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    p->mashMeter[i].flags |= SPRFLAG_HIDDEN;
  }
}

void Torture_ShowHud(Torture* p) {
  Torture_ShowMainSprites(p);
  Torture_ShowMashMeter(p);
}

void Torture_HideHud(Torture* p) {
  Torture_HideMainSprites(p);
  Torture_HideBonusSprites(p);
  Torture_HideMashMeter(p);
}

void FUN_080c0248(Torture* p);

void Torture_Start(Torture* p) {
  FUN_080bfaac(p);
  Torture_ShowHud(p);
  p->unk_57a = 0x20;
  Torture_SetState(p, FUN_080c0248);
}

// unk_57e を引数にして unk_5ac のスクリプトを起動する
void FUN_080c0014(Torture* p) {
  ScriptArgs args;
  u32 argv[1];

  if (p->unk_5ac != 0) {
    args.argc = 1;
    args.argv = argv;
    argv[0] = p->unk_57e;
    VM_ExecByID(p->unk_5ac, &args);
  }
}

// unk_5a8 のスクリプトを引数1個で起動する
void FUN_080c0058(Torture* p) {
  u32 arg;
  ScriptArgs args;

  if (p->unk_5a8 != 0) {
    args.argc = 1, args.argv = &arg;
    VM_ExecByID(p->unk_5a8, &args);
  }
}

void EntityCF58_CreateWithCallback(s32 param_1, s32 param_2, void* fn, void* arg);  // src/entity_a0a6.c
void Sound_SetBGMTempo(u32 tempo);

// プレイヤーを決まった座標へ戻してから Torture_Start を予約する
void Cmd_StartTorture(void) {
  Torture* p = gTorture;

  if (p != NULL) {
    EntityCF58_CreateWithCallback(0, 0, Torture_Start, p);
    Player_Lock(gPlayerPtr[0], DIR8_UP_LEFT);
    VEC3_SET(gPlayerPtr[0]->mover.pos, Q8(3.5), Q8(1), Q8(5.5));
  }
}

NAKED s32 FUN_080c00d4(Torture* p) { INCFUNC("asm/func/FUN_080c00d4.inc"); }

void Torture_UpdateDone(Torture* _) {}

// おしおきを終える, 借金を 0 にして表示を消し, プレイヤーを操作不能に戻してから param_2 に応じた終わりのスクリプトを予約する
void Torture_Finish(Torture* p, s32 param_2) {
  gStat->darkDebts = 0;
  Torture_ResetMash();
  p->mashRate = 1;
  p->mashFrames = 0;
  Sound_SetBGMTempo(256);
  FUN_0823bca8(8);
  Torture_HideHud(p);
  gPlayerPtr[0]->mode = PMODE_LOCKED;
  gPlayerPtr[0]->action = 0;
  gPlayerPtr[0]->state = 0;
  if (param_2 == 0) {
    EntityCF58_CreateWithCallback(1, 0, FUN_080c0014, p);
  } else {
    EntityCF58_CreateWithCallback(1, 0, FUN_080c0058, p);
  }
  Torture_SetState(p, Torture_UpdateDone);
}

NAKED void FUN_080c0248(Torture* p) { INCFUNC("asm/func/FUN_080c0248.inc"); }

void Torture_UpdateScreenBlend(Torture* p) {
  Player* q = gPlayerPtr[0];

  if (q->mashHits <= 3) {
    REG_BLDCNT = BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_BD | BLDCNT_EFFECT_DARKEN;
    REG_BLDY = (4 - q->mashHits) * 2;
  } else {
    REG_BLDCNT = BLDCNT_TGT1_BG1 | BLDCNT_TGT1_BG2 | BLDCNT_TGT1_BG3 | BLDCNT_TGT1_BD | BLDCNT_EFFECT_LIGHTEN;
    REG_BLDY = q->mashHits - 4;
  }
  REG_BLDALPHA = 0;
}

s32 Torture_Update(Torture* p) {
  p->updateCallback(p);
  FUN_080bfb74(p);
  Torture_UpdateScreenBlend(p);
  return 0;
}

s32 Torture_Destroy(Torture* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite0);
  AuxSprite_Remove(&p->sprite1);
  AuxSprite_Remove(&p->sprite2);
  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->mainSprites[i]);
  }
  for (i = 0; i < 7; i++) {
    AuxSprite_Remove(&p->mashMeter[i]);
  }
  for (i = 0; i < 6; i++) {
    AuxSprite_Remove(&p->bonusSprites[i]);
  }
  gTorture = NULL;
  sound_08240740(SONG_574);
  return 0;
}

NAKED void FUN_080c05cc(Torture* p) { INCFUNC("asm/func/FUN_080c05cc.inc"); }

// bonusGfx を読み込み, bonusSprites を隠した状態で並べる
void Torture_InitBonusSprites(Torture* p) {
  Vec3 pos;
  s32 i;

  pos.x = 132, pos.y = 48, pos.z = 0;
  Video_GetAuxSprite(&p->bonusGfx, SPRITE_PANTHER_BONUS);
  for (i = 0; i < 6; i++) {
    AuxSprite_Add(&p->bonusSprites[i], &p->bonusGfx, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN);
    if (i < 2) {
      p->bonusSprites[i].poseIdx = i + 3;
    } else {
      p->bonusSprites[i].poseIdx = i + 5;
    }
    p->bonusSprites[i].pos = pos;
    p->bonusSprites[i].priority = 1;
    pos.x += 8;
  }
}

// meterGfx を読み込み, mashMeter をコマ 0 で (128, 56) から 8 ずつ右へ並べる
void Torture_InitMashMeter(Torture* p) {
  Vec3 pos;
  s32 i;

  pos.x = 128, pos.y = 56, pos.z = 0;
  Video_GetAuxSprite(&p->meterGfx, SPRITE_PANTHER_BONUS);
  for (i = 0; i < 7; i++) {
    AuxSprite_Add(&p->mashMeter[i], &p->meterGfx, SPRFLAG_SCREEN_COORD);
    AuxSprite_SetPoseIdx(&p->mashMeter[i], 0);
    p->mashMeter[i].pos = pos;
    p->mashMeter[i].priority = 1;
    pos.x += 8;
  }
}

NAKED s32 Torture_Init(Torture* p) { INCFUNC("asm/func/Torture_Init.inc"); }

// 0xB3D1
Torture* Torture_Create(void) {
  if (gTorture == NULL) {
    Torture* p = CreateEntity(ENTITY_UNK_8, sizeof(Torture));

    if (p != NULL) {
      SetEntityRoutine(p, Torture_Update, Torture_Destroy);
      if (Torture_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gTorture;
}
