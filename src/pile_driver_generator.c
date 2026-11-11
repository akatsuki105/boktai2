#include "eff_elemcond.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "pile_driver.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"

// Generator.state
enum {
  STATE_0 = 0,
  STATE_1 = 1,
  STATE_2 = 2,
  TURN_ON = 3,
  STATE_4 = 4,
  TURN_OFF = 5,
  STATE_6 = 6,
  STATE_7 = 7,
};

static void (*const sGeneratorUpdates[8])(Generator*);

// 状態番号と更新関数を入れ替える, 状態3と5に入るときは効果音を鳴らす
void Generator_SetState(Generator* p, s32 state) {
  p->state = state;
  p->stateTimer = 0;
  p->updateCallback = sGeneratorUpdates[p->state];
  if (p->state == TURN_ON) {
    PlaySound_082406e0(SE_GENERATOR_ENABLED);
  } else if (p->state == TURN_OFF) {
    PlaySound_082406e0(SE_GENERATOR_DISABLED);
  }
}

// スプライトを本来の位置から ±5 揺らす
void FUN_080b2888(Generator* p) {
  p->sprite.pos = p->pos;
  p->unk_ed = 1;
  {
    p->sprite.pos.x += Mod(RandomNext(), 10) - 5;
    p->sprite.pos.z += Mod(RandomNext(), 10) - 5;
  }
}

// 1P が半径 128 の内側に入っていれば, ジェネレーターから見た向きで半径 130 の位置まで押し出す
void Generator_PushPlayer(Generator* p) {
  s32 dx = gPlayerPtr[0]->mover.pos.x - p->pos.x;
  s32 dz = gPlayerPtr[0]->mover.pos.z - p->pos.z;

  if (abs(dx) < Q8(0.5) && abs(dz) < Q8(0.5) && dx * dx + dz * dz < (Q8(0.5) * Q8(0.5))) {
    s32 angle = ArcTan2_8(dx, dz);

    gPlayerPtr[0]->mover.pos.x = (COS(angle) * 130 >> 12) + p->pos.x;
    gPlayerPtr[0]->mover.pos.z = (SIN(angle) * 130 >> 12) + p->pos.z;
  }
}

// 攻撃属性を持つ判定を受けたらダメージを溜め、上限に届いたら state 3 へ進む
NON_MATCH void Generator_OnHurt(HitboxData* a, HitboxData* b, Generator* p) {
#ifdef NONMATCHING_C
  if (Hitbox_TestAttr(a, 0x7F) && p->unk_e0 == 0 && p->state == 2) {
    s32 power = a->power - b->power;

    if (power < 0) {
      power = 1;
    }
    p->unk_eb = 4;
    p->unk_d2 += power;
    if (p->unk_d2 < p->unk_d4) {
      p->unk_e0 = 12;
      PlaySound_082406e0(SE_UNK_295);
    } else {
      p->unk_d2 = p->unk_d4;
      Generator_SetState(p, 3);
    }
  }
#else
  INCFUNC("asm/func/Generator_OnHurt.inc");
#endif
}

// state 0 のハンドラ
void FUN_080b2a14(Generator* p) {}

// ジェネレーターの出現 (state 1), unk_dc フレーム待ってから姿と食らい判定を出し, アニメ 1 周で state 2 に進む
void FUN_080b2a18(Generator* p) {
  AuxAnimState* anim;

  if (p->unk_dc != 0) {
    p->unk_dc--;
    return;
  }
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  p->hurtbox.flags &= ~HBFLAG_HIDDEN;
  p->sprite.priority = 2;
  anim = &p->anim;
  AuxAnim_SetAnim(anim, p->animFile, 0, p->animVariant, p->animFlags);
  if (AuxSprite_AdvanceAnim(&p->sprite, anim)) {
    Hitbox_Register(&p->hurtbox);
    Generator_SetState(p, 2);
  }
}

// ジェネレーターの待機 (state 1), アニメ 1 を1コマ進めてパレットを 451 にする
void FUN_080b2b68(Generator* p) {
  AuxAnimState* anim = &p->anim;

  AuxAnim_SetAnim(anim, p->animFile, 1, p->animVariant, p->animFlags);
  AuxSprite_AdvanceAnim(&p->sprite, anim);
  p->plttID = OBP_GENERATOR(0);
}

// ジェネレーターの起動 (state 3), アニメのコマ 5 / 6 以降でパレットを切り替え, アニメ 1 周で state 4 (稼働) に進む
void FUN_080b2c70(Generator* p) {
  AuxAnimState* anim;

  if (p->unk_ce != 0) {
    if (p->anim.cmdIdx == 5 && p->anim.tick == 0) {
      p->plttID = OBP_GENERATOR(1);
    } else if (p->anim.cmdIdx > 5) {
      if (p->unk_ea) {
        p->plttID = OBP_GENERATOR(2);
      } else {
        p->plttID = OBP_GENERATOR(1);
      }
    }
  } else if (p->anim.cmdIdx == 5 && p->anim.tick == 0) {
    p->plttID = OBP_GENERATOR(1);
  }
  anim = &p->anim;
  AuxAnim_SetAnim(anim, p->animFile, 2, p->animVariant, p->animFlags);
  if (AuxSprite_AdvanceAnim(&p->sprite, anim)) {
    p->unk_ec = 1;
    Generator_SetState(p, 4);
  }
}

// ジェネレーターの稼働 (state 4), アニメ 3 を1コマ進め, unk_ea でパレットを 452 / 453 に切り替える
void FUN_080b2dec(Generator* p) {
  AuxAnimState* anim = &p->anim;

  AuxAnim_SetAnim(anim, p->animFile, 3, p->animVariant, p->animFlags);
  AuxSprite_AdvanceAnim(&p->sprite, anim);
  if (p->unk_ea) {
    p->plttID = OBP_GENERATOR(2);
  } else {
    p->plttID = OBP_GENERATOR(1);
  }
}

// ジェネレーターの停止 (state 5), 停止アニメ 4 を流してパレットを暗くし, 終わったら state 2 (unk_ce なら 90 フレーム揺れる state 6) に移る
void FUN_080b2f0c(Generator* p) {
  AuxAnimState* anim;

  if (p->unk_ce != 0) {
    if (p->anim.cmdIdx == 5 && p->anim.tick == 0) {
      p->plttID = OBP_GENERATOR(1);
    } else if (p->anim.cmdIdx == 6 && p->anim.tick == 0) {
      p->plttID = OBP_GENERATOR(0);
    }
    anim = &p->anim;
    AuxAnim_SetAnim(anim, p->animFile, 4, p->animVariant, p->animFlags);
    if (AuxSprite_AdvanceAnim(&p->sprite, anim)) {
      p->unk_d2 = 0;
      p->unk_de = 90;
      Generator_SetState(p, 6);
    }
  } else {
    if (p->anim.cmdIdx == 5 && p->anim.tick == 0) {
      p->plttID = OBP_GENERATOR(0);
    }
    anim = &p->anim;
    AuxAnim_SetAnim(anim, p->animFile, 4, p->animVariant, p->animFlags);
    if (AuxSprite_AdvanceAnim(&p->sprite, anim)) {
      p->unk_d2 = 0;
      Generator_SetState(p, 2);
    }
  }
}

// ジェネレーターの被弾 (state 6), アニメ 1 を進めながら unk_de フレームの間揺れ, 終わったら元の位置に戻して state 2 に戻る
void FUN_080b31b4(Generator* p) {
  AuxAnimState* anim = &p->anim;

  AuxAnim_SetAnim(anim, p->animFile, 1, p->animVariant, p->animFlags);
  AuxSprite_AdvanceAnim(&p->sprite, anim);
  if (--p->unk_de == 0) {
    p->unk_ed = 0;
    p->sprite.pos = p->pos;
    Generator_SetState(p, 2);
  } else {
    FUN_080b2888(p);
  }
}

// 起動中はゲージ音を鳴らし、待機中は16フレームで state 4 へ進む
void FUN_080b32e0(Generator* p) {
  if (p->unk_f9 != 0) {
    p->unk_f9--;
  }
  if (p->unk_f2 == 0) {
    if (p->stateTimer == 0) {
      ElementalCondEmitter_Reset(&p->condEmitter);
    }
    p->stateTimer++;
    if (p->stateTimer > 15) {
      p->sprite.pos = p->pos;
      p->plttID = OBP_GENERATOR(2);
      Generator_SetState(p, 4);
      p->hurtbox.damage = 0;
      p->stateTimer = 0;
    } else {
      p->plttID = p->unk_f0 - 1;
    }
  } else {
    p->plttID = p->unk_f0;
    p->unk_f2--;
    if (p->unk_f2 < p->unk_f4) {
      ElementalCondEmitter_FadeParticle(&p->condEmitter);
      p->unk_f4 -= 250;
    }
  }
}

static void (*const sGeneratorUpdates[8])(Generator*) = {
    [STATE_0] = FUN_080b2a14,
    [STATE_1] = FUN_080b2a18,
    [STATE_2] = FUN_080b2b68,
    [TURN_ON] = FUN_080b2c70,
    [STATE_4] = FUN_080b2dec,
    [TURN_OFF] = FUN_080b2f0c,
    [STATE_6] = FUN_080b31b4,
    [STATE_7] = FUN_080b32e0,
};  // 0x085AD0B8

// 被弾フラグが立っていれば点滅を強め、収まったら元のパレットに戻していく
void Generator_UpdateFlash(Generator* p) {
  if (p->unk_e2 != 0) {
    if (p->flashTimer <= 11) {
      p->flashTimer++;
    }
    p->unk_e2 = 0;
  } else {
    if (p->flashTimer != 0) {
      p->flashTimer--;
    }
  }
  if (p->flashTimer == 12) {
    Video_SetAuxSpritePltt(&p->gfx, OBP_GENERATOR(4));
  } else if (p->flashTimer != 0) {
    Video_SetAuxSpritePltt(&p->gfx, OBP_GENERATOR(3));
  } else if (p->unk_eb != 0) {
    Video_SetAuxSpritePltt(&p->gfx, OBP_WHITE_306);
    p->unk_eb--;
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
}

s32 Generator_Update(Generator* p) {
  if (p->state != 0) Generator_PushPlayer(p);
  if (p->unk_da != 0) p->unk_da--;
  if (p->unk_e0 != 0) p->unk_e0--;
  p->updateCallback(p);
  Generator_UpdateFlash(p);
  if (p->unk_e8 != 0) {
    if (gPileDriver->unk_c10 == 0) {
      p->unk_e8 = 0;
    } else if (p->state != 4) {
      p->unk_e8 = 0;
    } else {
      p->hurtbox.damage = 0;
      p->unk_e8--;
    }
  }
  return 0;
}

s32 Generator_Destroy(Generator* p) {
  AuxSprite_Remove(&p->sprite);
  Hitbox_Unregister(&p->hurtbox);
  ElementalCondEmitter_Destroy(&p->condEmitter);
  return 0;
}

void Generator_InitHurtbox(Generator* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.391), Q8(0.782), Q8(0.391));
  VEC3_SET(offset, 0, Q8(0.782), 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, power, 0, 0);
  Hitbox_SetPos(hurtbox, &p->pos, 0);
  Hitbox_SetHandler(hurtbox, Generator_OnHurt, p);
}

// ジェネレーターを初期化する, スプライトと食らい判定を作り, 指定の state に合わせてアニメとパレットの初期状態を整える
// 397/395命令, 手動送り2か所を AuxSprite_AdvanceAnim にすると 86 → 81 hunk に縮むが, 主な残差はスタックフレーム (原典 0x8, こちらは 0x10) と引数の読み出し順
// 試済: param_9 を u16 にする (変化なし), 未: animVariant / animFlags / param_6 の型と、フィールドへの格納順
NON_MATCH s32 Generator_Init(Generator* p, Vec3* pos, s32 animVariant, s32 animFlags, s32 state, s32 param_6, s32 param_7, u32 power, s32 param_9) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;

  p->pos = *pos;
  p->unk_ce = param_6;
  p->animVariant = animVariant;
  p->animFlags = animFlags;
  p->unk_dc = param_9;
  p->unk_d4 = param_7;
  p->unk_d8 = Div(p->unk_d4, 6);
  spr = &p->sprite;
  Video_GetAuxSprite(&p->gfx, SPRITE_GENERATOR);
  AuxSprite_Add(spr, &p->gfx, 0);
  p->sprite.pos = p->pos;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_PILE);
  Generator_InitHurtbox(p, power);
  Generator_SetState(p, state);
  switch (p->state) {
    case 0: {
      p->unk_d2 = 0;
      p->plttID = OBP_GENERATOR(0);
      p->sprite.priority = 3;
      p->sprite.flags |= SPRFLAG_HIDDEN;
      break;
    }
    case 2: {
      p->unk_d2 = 0;
      p->plttID = OBP_GENERATOR(0);
      anim = &p->anim;
      AuxAnim_SetAnim(anim, p->animFile, 1, p->animVariant, p->animFlags);
      AuxSprite_AdvanceAnim(spr, anim);
      Hitbox_Register(&p->hurtbox);
      break;
    }
    case 4: {
      p->unk_d2 = p->unk_d4;
      p->plttID = OBP_GENERATOR(1);
      anim = &p->anim;
      AuxAnim_SetAnim(anim, p->animFile, 3, p->animVariant, p->animFlags);
      AuxSprite_AdvanceAnim(spr, anim);
      Hitbox_Register(&p->hurtbox);
      break;
    }
  }
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  p->unk_da = 0;
  p->unk_ec = 0;
  ElementalCondEmitter_Init(&p->condEmitter, &p->sprite.pos, ELEMCOND_NONE, 0, 0);
  p->unk_ea = 0;
  return 0;
#else
  INCFUNC("asm/func/Generator_Init.inc");
#endif
}

Generator* Generator_Create(Vec3* pos, s32 param_2, s32 param_3, s32 state, s32 param_5, s32 param_6, u32 power, s32 param_8) {
  Generator* p = CreateEntity(ENTITY_UNK_8, sizeof(Generator));

  if (p != NULL) {
    SetEntityRoutine(p, Generator_Update, Generator_Destroy);
    if (Generator_Init(p, pos, param_2, param_3, state, param_5, param_6, power, param_8) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
