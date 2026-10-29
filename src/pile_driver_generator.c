#include "eff_082473e0.h"
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

static void (*const sGeneratorUpdates[8])(Generator*);

// 状態番号と更新関数を入れ替える, 状態3と5に入るときは効果音を鳴らす
void Generator_SetState(Generator* p, s32 state) {
  p->state = state;
  p->stateTimer = 0;
  p->updateCallback = sGeneratorUpdates[p->state];
  if (p->state == 3) {
    PlaySound_082406e0(SE_GENERATOR_ENABLED);
  } else if (p->state == 5) {
    PlaySound_082406e0(SE_GENERATOR_DISABLED);
  }
}

// スプライトを本来の位置から ±5 揺らす
void FUN_080b2888(Generator* p) {
  p->sprite.pos = p->pos;
  p->unk_ed = 1;
  {
    u16* table = gRandomTable;
    p->sprite.pos.x += Mod(_Random(table), 10) - 5;
    p->sprite.pos.z += Mod(_Random(table), 10) - 5;
  }
}

// 1P が半径 128 の内側に入っていれば, ジェネレーターから見た向きで半径 130 の位置まで押し出す
void Generator_PushPlayer(Generator* p) {
  s32 dx = gPlayerPtr[0]->mover.pos.x - p->pos.x;
  s32 dz = gPlayerPtr[0]->mover.pos.z - p->pos.z;

  if (abs(dx) < 0x80 && abs(dz) < 0x80 && dx * dx + dz * dz < 0x4000) {
    s32 angle = ArcTan2_8(dx, dz);

    gPlayerPtr[0]->mover.pos.x = (COS(angle) * 130 >> 12) + p->pos.x;
    gPlayerPtr[0]->mover.pos.z = (SIN(angle) * 130 >> 12) + p->pos.z;
  }
}

// 攻撃属性を持つ判定を受けたらダメージを溜め、上限に届いたら state 3 へ進む
NON_MATCH void FUN_080b29a4(HitboxData* a, HitboxData* b, Generator* p) {
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
  INCFUNC("asm/func/FUN_080b29a4.inc");
#endif
}

// state 0 のハンドラ
void FUN_080b2a14(Generator* p) {}

// ジェネレーターの出現 (state 1), unk_dc フレーム待ってから姿と食らい判定を出し, アニメ 1 周で state 2 に進む
// 残差は 145/161 (初稿のみ), AuxAnim 手動送り (終端判定つき) の壁と, 前半の hurtbox / sprite への書き込みの並び
// Tier A-C は未着手
NON_MATCH void FUN_080b2a18(Generator* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;
  bool32 done;

  if (p->unk_dc != 0) {
    p->unk_dc--;
    return;
  }
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  p->hurtbox.flags &= ~HBFLAG_HIDDEN;
  p->sprite.priority = 2;
  anim = &p->anim;
  spr = &p->sprite;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    p->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick < anim->wait) {
    done = FALSE;
  } else {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        done = TRUE;
      } else {
        anim->cmdIdx--;
        done = FALSE;
      }
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
        done = TRUE;
      } else {
        done = FALSE;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }
  if (done) {
    Hitbox_Register(&p->hurtbox);
    Generator_SetState(p, 2);
  }
#else
  INCFUNC("asm/func/FUN_080b2a18.inc");
#endif
}

// ジェネレーターの待機 (state 1), アニメ 1 を1コマ進めてパレットを 451 にする
// 残差は AuxAnim 手動送りの壁 (125/126), Player 側 (FUN_080772ec) と同じ
// Tier A-C は FUN_080772ec で試済
NON_MATCH void FUN_080b2b68(Generator* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;

  anim = &p->anim;
  AuxAnim_SetAnim(anim, p->animFile, 1, p->animVariant, p->animFlags);
  spr = &p->sprite;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    p->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      s32 idx = anim->cmdIdx;

      if (idx == 0) {
        idx = anim->cmdCount;
      }
      anim->cmdIdx = idx - 1;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }
  p->plttID = 451;
#else
  INCFUNC("asm/func/FUN_080b2b68.inc");
#endif
}

// ジェネレーターの起動 (state 3), アニメのコマ 5 / 6 以降でパレットを切り替え, アニメ 1 周で state 4 (稼働) に進む
// 残差は 175/182 (初稿のみ), AuxAnim 手動送り (終端判定つき) の壁と, 先頭のパレット判定の分岐の並び
// Tier A-C は未着手
NON_MATCH void FUN_080b2c70(Generator* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;
  bool32 done;

  if (p->unk_ce == 0) {
    if (p->anim.cmdIdx == 5 && p->anim.tick == 0) {
      p->plttID = 452;
    }
  } else if (p->anim.cmdIdx == 5 && p->anim.tick == 0) {
    p->plttID = 452;
  } else if (p->anim.cmdIdx >= 6) {
    p->plttID = p->unk_ea ? 453 : 452;
  }
  anim = &p->anim;
  spr = &p->sprite;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    p->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick < anim->wait) {
    done = FALSE;
  } else {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        done = TRUE;
      } else {
        anim->cmdIdx--;
        done = FALSE;
      }
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
        done = TRUE;
      } else {
        done = FALSE;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }
  if (done) {
    p->unk_ec = 1;
    Generator_SetState(p, 4);
  }
#else
  INCFUNC("asm/func/FUN_080b2c70.inc");
#endif
}

// ジェネレーターの稼働 (state 4), アニメ 3 を1コマ進め, unk_ea でパレットを 452 / 453 に切り替える
// 残差は AuxAnim 手動送りの壁 (134/136), FUN_080772ec と同じ
// Tier A-C は FUN_080772ec で試済
NON_MATCH void FUN_080b2dec(Generator* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;

  anim = &p->anim;
  AuxAnim_SetAnim(anim, p->animFile, 3, p->animVariant, p->animFlags);
  spr = &p->sprite;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    p->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      s32 idx = anim->cmdIdx;

      if (idx == 0) {
        idx = anim->cmdCount;
      }
      anim->cmdIdx = idx - 1;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }
  p->plttID = p->unk_ea ? 453 : 452;
#else
  INCFUNC("asm/func/FUN_080b2dec.inc");
#endif
}

// ジェネレーターの停止 (state 5), 停止アニメ 4 を流してパレットを暗くし, 終わったら state 2 (unk_ce なら 90 フレーム揺れる state 6) に移る
// AuxAnim 手動送り (終端判定つき) の壁を2か所に持つ, 初稿のみ
// Tier A-C は未着手
NON_MATCH void FUN_080b2f0c(Generator* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;
  bool32 done;

  if (p->unk_ce == 0) {
    if (p->anim.cmdIdx == 5 && p->anim.tick == 0) {
      p->plttID = 451;
    }
    anim = &p->anim;
    AuxAnim_SetAnim(anim, p->animFile, 4, p->animVariant, p->animFlags);
    spr = &p->sprite;
    cmd = &anim->cmds[anim->cmdIdx];
    spr->poseIdx = *cmd >> 6;
    if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
      p->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      p->sprite.flags &= ~SPRFLAG_XFLIP;
    }
    if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
      spr->flags |= SPRFLAG_YFLIP;
    } else {
      spr->flags &= ~SPRFLAG_YFLIP;
    }
    anim->tick++;
    if (anim->tick < anim->wait) {
      done = FALSE;
    } else {
      anim->tick = 0;
      if (anim->flags & ANIM_PLAY_REVERSE) {
        if (anim->cmdIdx == 0) {
          anim->cmdIdx = anim->cmdCount - 1;
          done = TRUE;
        } else {
          anim->cmdIdx--;
          done = FALSE;
        }
      } else {
        anim->cmdIdx++;
        if (anim->cmdIdx >= anim->cmdCount) {
          anim->cmdIdx = 0;
          done = TRUE;
        } else {
          done = FALSE;
        }
      }
      cmd = &anim->cmds[anim->cmdIdx];
      anim->duration = *cmd & 0xF;
      anim->wait = anim->duration * anim->speed >> 6;
      if (anim->wait == 0) {
        anim->wait = 1;
      }
    }
    if (done) {
      p->unk_d2 = 0;
      Generator_SetState(p, 2);
    }
    return;
  }

  if (p->anim.cmdIdx == 5 && p->anim.tick == 0) {
    p->plttID = 452;
  } else if (p->anim.cmdIdx == 6 && p->anim.tick == 0) {
    p->plttID = 451;
  }
  anim = &p->anim;
  AuxAnim_SetAnim(anim, p->animFile, 4, p->animVariant, p->animFlags);
  spr = &p->sprite;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    p->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick < anim->wait) {
    done = FALSE;
  } else {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        done = TRUE;
      } else {
        anim->cmdIdx--;
        done = FALSE;
      }
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
        done = TRUE;
      } else {
        done = FALSE;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }
  if (done) {
    p->unk_d2 = 0;
    p->unk_de = 90;
    Generator_SetState(p, 6);
  }
#else
  INCFUNC("asm/func/FUN_080b2f0c.inc");
#endif
}

// ジェネレーターの被弾 (state 6), アニメ 1 を進めながら unk_de フレームの間揺れ, 終わったら元の位置に戻して state 2 に戻る
// 残差は AuxAnim 手動送りの壁 (142/143), FUN_080772ec と同じ
// Tier A-C は FUN_080772ec で試済
NON_MATCH void FUN_080b31b4(Generator* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;

  anim = &p->anim;
  AuxAnim_SetAnim(anim, p->animFile, 1, p->animVariant, p->animFlags);
  spr = &p->sprite;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    p->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      s32 idx = anim->cmdIdx;

      if (idx == 0) {
        idx = anim->cmdCount;
      }
      anim->cmdIdx = idx - 1;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }
  if (--p->unk_de == 0) {
    p->unk_ed = 0;
    p->sprite.pos = p->pos;
    Generator_SetState(p, 2);
  } else {
    FUN_080b2888(p);
  }
#else
  INCFUNC("asm/func/FUN_080b31b4.inc");
#endif
}

// 起動中はゲージ音を鳴らし、待機中は16フレームで state 4 へ進む
void FUN_080b32e0(Generator* p) {
  if (p->unk_f9 != 0) {
    p->unk_f9--;
  }
  if (p->unk_f2 == 0) {
    if (p->stateTimer == 0) {
      Eff082473e0Emitter_Reset(&p->eff_100);
    }
    p->stateTimer++;
    if (p->stateTimer > 15) {
      p->sprite.pos = p->pos;
      p->plttID = 453;
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
      Eff082473e0Emitter_FadeParticle(&p->eff_100);
      p->unk_f4 -= 250;
    }
  }
}

static void (*const sGeneratorUpdates[8])(Generator*) = {
    FUN_080b2a14,
    FUN_080b2a18,
    FUN_080b2b68,
    FUN_080b2c70,
    FUN_080b2dec,
    FUN_080b2f0c,
    FUN_080b31b4,
    FUN_080b32e0,
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
    Video_SetAuxSpritePltt(&p->gfx, 455);
  } else if (p->flashTimer != 0) {
    Video_SetAuxSpritePltt(&p->gfx, 454);
  } else if (p->unk_eb != 0) {
    Video_SetAuxSpritePltt(&p->gfx, 306);
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
  Eff082473e0Emitter_Destroy(&p->eff_100);
  return 0;
}

void Generator_InitHurtbox(Generator* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.391), Q8(0.782), Q8(0.391));
  VEC3_SET(offset, 0, Q8(0.782), 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hurtbox, power, 0, 0);
  Hitbox_SetPos(hurtbox, &p->pos, 0);
  Hitbox_SetHandler(hurtbox, FUN_080b29a4, p);
}

// ジェネレーターを初期化する, スプライトと食らい判定を作り, 指定の state に合わせてアニメとパレットの初期状態を整える
// 残差は 394/395 (初稿のみ), スタックフレームが 0x10 対 0x8 で引数の読み出し位置と順がずれる, Ghidra は param_3/4/6 を u8, param_7/9 を u16 と見ている
// Tier B 未着手 (引数の型), AuxAnim 手動送りの壁も2か所に持つ
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
      p->plttID = 451;
      p->sprite.priority = 3;
      p->sprite.flags |= SPRFLAG_HIDDEN;
      break;
    }
    case 2: {
      p->unk_d2 = 0;
      p->plttID = 451;
      anim = &p->anim;
      AuxAnim_SetAnim(anim, p->animFile, 1, p->animVariant, p->animFlags);
      cmd = &anim->cmds[anim->cmdIdx];
      spr->poseIdx = *cmd >> 6;
      if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
        p->sprite.flags |= SPRFLAG_XFLIP;
      } else {
        p->sprite.flags &= ~SPRFLAG_XFLIP;
      }
      if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
        spr->flags |= SPRFLAG_YFLIP;
      } else {
        spr->flags &= ~SPRFLAG_YFLIP;
      }
      anim->tick++;
      if (anim->tick >= anim->wait) {
        anim->tick = 0;
        if (anim->flags & ANIM_PLAY_REVERSE) {
          s32 idx = anim->cmdIdx;

          if (idx == 0) {
            idx = anim->cmdCount;
          }
          anim->cmdIdx = idx - 1;
        } else {
          anim->cmdIdx++;
          if (anim->cmdIdx >= anim->cmdCount) {
            anim->cmdIdx = 0;
          }
        }
        cmd = &anim->cmds[anim->cmdIdx];
        anim->duration = *cmd & 0xF;
        anim->wait = anim->duration * anim->speed >> 6;
        if (anim->wait == 0) {
          anim->wait = 1;
        }
      }
      Hitbox_Register(&p->hurtbox);
      break;
    }
    case 4: {
      p->unk_d2 = p->unk_d4;
      p->plttID = 452;
      anim = &p->anim;
      AuxAnim_SetAnim(anim, p->animFile, 3, p->animVariant, p->animFlags);
      cmd = &anim->cmds[anim->cmdIdx];
      spr->poseIdx = *cmd >> 6;
      if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
        p->sprite.flags |= SPRFLAG_XFLIP;
      } else {
        p->sprite.flags &= ~SPRFLAG_XFLIP;
      }
      if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
        spr->flags |= SPRFLAG_YFLIP;
      } else {
        spr->flags &= ~SPRFLAG_YFLIP;
      }
      anim->tick++;
      if (anim->tick >= anim->wait) {
        anim->tick = 0;
        if (anim->flags & ANIM_PLAY_REVERSE) {
          s32 idx = anim->cmdIdx;

          if (idx == 0) {
            idx = anim->cmdCount;
          }
          anim->cmdIdx = idx - 1;
        } else {
          anim->cmdIdx++;
          if (anim->cmdIdx >= anim->cmdCount) {
            anim->cmdIdx = 0;
          }
        }
        cmd = &anim->cmds[anim->cmdIdx];
        anim->duration = *cmd & 0xF;
        anim->wait = anim->duration * anim->speed >> 6;
        if (anim->wait == 0) {
          anim->wait = 1;
        }
      }
      Hitbox_Register(&p->hurtbox);
      break;
    }
  }
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  p->unk_da = 0;
  p->unk_ec = 0;
  Eff082473e0Emitter_Init(&p->eff_100, &p->sprite.pos, 0, 0, 0);
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
