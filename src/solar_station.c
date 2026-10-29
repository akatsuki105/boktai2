#include "camera.h"
#include "camera_inline.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "input.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

// 太陽スタンド
typedef struct {
  Entity e;                // 0x000, ENTITY_UNK_8
  AuxSprite sprite;        // 0x018, ->gfx
  AuxSpriteGfx gfx;        // 0x044, SPRITE_SOLAR_STATION
  MainSpriteGfx digitGfx;  // 0x060, SPRITE_UI_START_MENU (SMENU_NUM_BOLD を残高表示に使う)
  MainSprite digits[4];    // 0x080, 太陽スタンドの上に表示される残高
  HitboxData hurtbox;      // 0x200, _Destroy が Hitbox_Unregister に渡す
  Vec3 unk_250;            // 0x250, FUN_0809f4b0 が sprite.pos を写して補正する
  Player* player;          // 0x258, _Init が gPlayerPtr[0] を入れる, NULL なら _Init が失敗する
  u16 id;                  // 0x25C, _Create / _Init の第2引数, Hitbox_Init の第2引数にもなる
  u8 state;                // 0x25E, _Update の分岐, 0 なら SolarStation_UpdateIdle, 1 なら SolarStation_UpdateInUse
  u8 flashTimer;           // 0x25F, SolarStation_UpdateFlash のパレット切り替えの経過フレーム, PFLAG20_UNK_6 が落ちると 4 から数え下ろす
  u8 playerNear;           // 0x260, 1P が同じ高さで半タイル以内にいて操作できる状態なら 1
  bool8 forceShowDigits;   // 0x261, FUN_0809f30c がスクリプトのレコードから立て直す, SolarStation_UpdateDigits は playerNear と2バイトまとめて読んでどちらかが立っていれば残高を出す
  u16 unk_262;             // 0x262, _Init が sprite.flags bit2 のとき 7、そうでなければ 1 を入れる
} SolarStation;
static_assert(sizeof(SolarStation) == 612);

void FUN_0807a528(Player* p, Vec3* pos, u16 param_3);

// 1P が近くで A を押したら FUN_0807a528 で使用を始めさせて state 1 に移る, 近くにいる間は playerNear を立てる
// 残差 117/116 命令: 3つの格納 (state = 1, playerNear = 0 ×2) を原典は末尾の1つの strb に寄せて mode 不一致の塊を先に置く, 小人判定の 0 の作り置きが早い (IsPlayerSmall と同じ残差), ほかはレジスタ割り当て
// Tier A は試済 (mode 判定を if/else と早期 return, kind を switch と個別 if, 小人判定を bool8 inline), 未: 格納先アドレスと値をローカルに受けて1か所で書く形
NON_MATCH void SolarStation_UpdateIdle(SolarStation* p) {
#ifdef NONMATCHING_C
  if (p->player->mover.pos.y == p->unk_250.y) {
    s32 dx = abs(p->player->mover.pos.x - p->unk_250.x);
    s32 dz = abs(p->player->mover.pos.z - p->unk_250.z);

    if (dx <= Q8(0.5) && dz <= Q8(0.5)) {
      bool32 isMini;

      if (p->player->mode != PMODE_ACTIVE) {
        p->playerNear = 0;
        return;
      }
      p->playerNear = 1;
      isMini = gGoodCondTimer != 0 && gGoodCondID == GOOD_MINI;
      if (isMini) {
        return;
      }
      if (p->player->kind == PLAYER_BAT) {
        return;
      }
      if (p->player->kind == PLAYER_MOUSE) {
        return;
      }
      if (p->player->kind == PLAYER_SLEEPING) {
        return;
      }
      if (p->player->formRequest == 0 && (p->player->input->pressed & A_BUTTON) && p->player->action == PACT_UNK_7) {
        FUN_0807a528(p->player, &p->unk_250, p->unk_262);
        p->state = 1;
      }
      return;
    }
  }
  p->playerNear = 0;
#else
  INCFUNC("asm/func/SolarStation_UpdateIdle.inc");
#endif
}

// 1P が太陽スタンドを使っている間 (PACT_UNK_8) は貯金から ENE を1ずつ移し, 離れたらパレットを戻して state 0 に戻る
void SolarStation_UpdateInUse(SolarStation* p) {
  if (p->player->action == PACT_UNK_8) {
    if (TEST_FLAGS(p->player->flag20, PFLAG20_UNK_6)) {
      if (gStat->solarStand > 0 && p->player->ene < p->player->maxEne) {
        gStat->solarStand--;
        p->player->ene++;
      }
    }
  } else {
    Video_SetAuxSpritePltt(&p->gfx, 317);
    p->state = 0;
  }
  p->playerNear = 1;
}

// 1P の PFLAG20_UNK_6 が立っている間はパレットを2フレームごとに切り替えて光らせ, 落ちたら数フレームかけて元のパレットに戻す
void SolarStation_UpdateFlash(SolarStation* p) {
  if (Player_TestFlag20(p->player, PFLAG20_UNK_6)) {
    switch ((p->flashTimer >> 1) & 3) {
      case 1: {
        Video_SetAuxSpritePltt(&p->gfx, 319);
        break;
      }
      case 0:
      case 2: {
        Video_SetAuxSpritePltt(&p->gfx, 318);
        break;
      }
      case 3: {
        Video_SetAuxSpritePltt(&p->gfx, 317);
        break;
      }
    }
    p->flashTimer++;
  } else {
    if (p->flashTimer > 4) {
      p->flashTimer = 4;
    }
    if (p->flashTimer != 0) {
      Video_SetAuxSpritePltt(&p->gfx, 318);
      p->flashTimer--;
    } else {
      Video_SetAuxSpritePltt(&p->gfx, 317);
      p->flashTimer = 0;
    }
  }
}

// playerNear か forceShowDigits が立っていれば貯金の残高 (9999 まで) を4桁の数字でスタンドの上に出し, どちらも落ちていれば隠す
void SolarStation_UpdateDigits(SolarStation* p) {
  s32 digit[4];
  Vec3 vp;
  s32 rest;
  s32 i;

  if (*(u16*)&p->playerNear != 0) {  // 原典は playerNear と forceShowDigits を ldrh で一度に読む
    if ((s32)gStat->solarStand > 9999) {
      gStat->solarStand = 9999;
    }
    digit[0] = Div(gStat->solarStand, 1000);
    rest = gStat->solarStand - digit[0] * 1000;
    digit[1] = Div(rest, 100);
    rest -= digit[1] * 100;
    digit[2] = Div(rest, 10);
    rest -= digit[2] * 10;
    digit[3] = rest;
    WorldToScreen(&vp, &p->sprite.pos);
    vp.x -= 16;
    vp.y -= 44;
    for (i = 0; i < 4; i++) {
      p->digits[i].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->digits[i], &p->digitGfx, SMENU_NUM_BOLD(digit[i]), PLAYMODE_LOOP);
      p->digits[i].pos = vp;
      vp.x += 8;
    }
  } else {
    for (i = 0; i < 4; i++) {
      p->digits[i].flags |= SPRFLAG_HIDDEN;
    }
  }
}

// 自分の id で登録されたスクリプトのレコードを全部見て、forceShowDigits を最後の指示どおりに設定する
void FUN_0809f30c(SolarStation* p) {
  ScriptRecord* rec;
  s32 n = FUN_08230f94(p->id, &rec);

  while (n-- > 0) {
    switch (rec->values[0]) {
      case 0: {
        p->forceShowDigits = TRUE;
        break;
      }
      case 1: {
        p->forceShowDigits = FALSE;
        break;
      }
    }
    rec++;
  }
}

s32 SolarStation_Update(SolarStation* p) {
  FUN_0809f30c(p);

  switch (p->state) {
    case 0: {
      SolarStation_UpdateIdle(p);
      break;
    }
    case 1: {
      SolarStation_UpdateInUse(p);
      break;
    }
  }

  SolarStation_UpdateFlash(p);
  SolarStation_UpdateDigits(p);
  return 0;
}

s32 SolarStation_Destroy(SolarStation* p) {
  MainSprite* spr;
  s32 i;

  AuxSprite_Remove(&p->sprite);
  spr = p->digits;
  for (i = 0; i < 4; spr++, i++) {
    MainSprite_Remove(spr);
  }
  Hitbox_Unregister(&p->hurtbox);
  return 0;
}

// 太陽スタンドの絵を用意し、 '.p' で座標、'.f' で左右反転を決める
void SolarStation_InitSprite(SolarStation* p) {
  AuxSprite* sprite = &p->sprite;
  AuxSpriteGfx* gfx = &p->gfx;
  SpriteFlags flags;

  Video_GetAuxSprite(gfx, SPRITE_SOLAR_STATION);
  AuxSprite_Add(sprite, gfx, 0);
  sprite->poseIdx = 0;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(sprite->pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(sprite->pos, 0, 0, 0);
  }

  // xflip
  flags = VM_SeekToNamedArg('f');
  if (flags) {
    flags = VM_GetValue();
    if (flags) {
      flags = SPRFLAG_XFLIP;
    }
  }
  sprite->flags = flags;
}

// SPRITE_UI_START_MENU を開き, digits の4枚を非表示のスクリーン座標スプライトとして用意する
void SolarStation_InitMainSprites(SolarStation* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  Vec3 pos;
  s32 i;

  if (f != NULL) {
    p->digitGfx = *f;
    OpenMainSpriteFile(&p->digitGfx, f);
    VEC3_SET(pos, 0, 0, 0);
    for (i = 0; i < 4; i++) {
      MainSprite_Add(&p->digits[i], &p->digitGfx, SMENU_NUM_BOLD(0), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT, 1, PLAYMODE_PAUSE, 60, &pos);
    }
  }
}

// ヒットボックスの基準点を sprite の座標から作る, 左右反転の向きに合わせて1タイルぶんずらす
void FUN_0809f4b0(SolarStation* p) {
  p->unk_250 = p->sprite.pos;
  if (p->sprite.flags & SPRFLAG_XFLIP) {
    p->unk_250.x += Q8(1);
  } else {
    p->unk_250.z += Q8(1);
  }
}

// 太陽スタンドの食らい判定を sprite.pos に置いて登録する, 戻り値は書かれていない (pop {r1} で返す形だけ残っている)
s32 SolarStation_InitHitbox(SolarStation* p) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.391), Q8(0.586), Q8(0.391));
  VEC3_SET(offset, 0, Q8(0.586), 0);
  Hitbox_Init(hurtbox, p->id, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 0, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, 0, 0, 0);
  Hitbox_SetHandler(hurtbox, NULL, p);
  Hitbox_SetPos(hurtbox, &p->sprite.pos, 0);
  Hitbox_Register(hurtbox);
}

// 1P がいなければ失敗する, 絵と当たり判定と UI のスプライトを用意して状態を初期化する
s32 SolarStation_Init(SolarStation* p, u32 id, u32 param_3) {
  Player* player = gPlayerPtr[0];

  p->player = player;
  if (player == NULL) {
    return -1;
  }
  p->id = id;
  SolarStation_InitSprite(p);
  FUN_0809f4b0(p);
  SolarStation_InitHitbox(p);
  SolarStation_InitMainSprites(p);
  p->state = 0;
  p->playerNear = 0;
  p->forceShowDigits = FALSE;
  p->flashTimer = 0;
  if (p->sprite.flags & SPRFLAG_XFLIP) {
    p->unk_262 = 7;
  } else {
    p->unk_262 = 1;
  }
  return 0;
}

// 0xDC21, HashName("太陽スタンド")
SolarStation* SolarStation_Create(u32 id, u32 param_2) {
  SolarStation* p = CreateEntity(ENTITY_UNK_8, sizeof(SolarStation));
  if (p != NULL) {
    SetEntityRoutine(p, SolarStation_Update, SolarStation_Destroy);
    if (SolarStation_Init(p, id, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
