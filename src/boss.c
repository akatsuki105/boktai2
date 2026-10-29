#include "boss.h"

#include "camera.h"
#include "emote.h"
#include "global.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// 各ボスのシングルトン, idx は BossID
IWRAM_DATA Boss* gBossList[8] = {};  // 0x030000A0

void FUN_0802326c(Boss* p);
void FUN_08015d3c(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand);

// hp の割合 (0..128) を作り直す
static inline void Boss_UpdateHPRatio(Boss* p) {
  if (p->maxHP != 0) {
    p->hpRatio = Div(p->hp << 7, p->maxHP);
  } else {
    p->hpRatio = 0;
  }
}

void Boss_Register(Boss* p, BossID id) { gBossList[id] = p; }

void Boss_Unregister(BossID id) { gBossList[id] = NULL; }

void* Boss_Get(BossID id) { return gBossList[id]; }

Boss* FUN_08022a3c(void) {
  Boss* found = NULL;
  s32 i;

  for (i = 0; i < 8; i++) {
    Boss* p = gBossList[i];

    if (p != NULL && p->isDemo == 0) {
      if (found != NULL) {
        return found;
      }
      found = p;
    }
  }
  return found;
}

s32 Boss_Init(Boss* p, u32 id, BossID bossID, Vec3* pos, u32 angle) {
  Vec3 v;

  p->bossID = bossID;
  Mover_Init(&p->mover, id, pos, angle, 5, p);
  VEC3_SET(v, 0, Q8(1), 0);
  FUN_0823b47c(&p->mover, &v);
  Boss_SetAngle(p, angle);
  MsgQueue_Register(&p->msgQueue, id, CLS_BOSS);
  return 0;
}

s32 Boss_Destroy(Boss* p) {
  MsgQueue_Unregister(&p->msgQueue);
  Mover_Unlink(&p->mover);
  Boss_Unregister(p->bossID);
  return 0;
}

// 残差1命令 (61/62), 原典は gStat->gaugeMax への書き込みのあと gStat を読み直すが agbcc は値を使い回す (agbcc-levers.md の A cached global pointer that the target reloads per store と同じ)
// 試済: 間に基本ブロックを挟む, 固定アドレス (*(GameInfo**)0x030046A0) で参照, 未: per-TU フラグ
NON_MATCH s32 Boss_InitHP(Boss* p, s32 hp, s32 maxHP, s32 hurtboxPower) {
#ifdef NONMATCHING_C
  p->maxHP = maxHP;
  p->hp = hp;
  p->hurtboxPower = hurtboxPower;
  if (p->hp > p->maxHP) {
    p->hp = p->maxHP;
  }
  Boss_UpdateHPRatio(p);
  gStat->gaugeMax = p->maxHP;
  gStat->gaugeValue = p->hp;
  return 0;
#else
  INCFUNC("asm/func/Boss_InitHP.inc");
#endif
}

s32 Boss_SetHP(Boss* p, s32 hp) {
  p->hp = hp;
  if (p->hp > p->maxHP) {
    p->hp = p->maxHP;
  } else if (p->hp < 0) {
    p->hp = 0;
  }
  Boss_UpdateHPRatio(p);
  if (p->hpRatio < 64) {
    p->lowHP = TRUE;
  } else {
    p->lowHP = FALSE;
  }
  return 0;
}

s32 FUN_08022c24(Boss* p, u32 param_2, u32 param_3) {
  p->unk_ac = param_2;
  p->unk_ad = param_3;
  return 0;
}

// facing が 2 以上なら左右反転してアニメを切り替える, 向きによる variant は使わない
void Boss_PlayAnimFlip(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx, u32 animIdx, u32 playMode, u32 flags) {
  p->animVariant = 0;
  p->animID = animIdx;
  MainSprite_SetAnim(sprite, gfx, p->animID, playMode, flags);
  if (p->facing > 1) {
    p->xflip = TRUE;
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    p->xflip = FALSE;
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
}

void Boss_PlayAnimFacing(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx, u32 animIdx, u32 playMode, u32 variant, u32 flags) {
  if (p->facing == 1 || p->facing == 2) {
    p->animVariant = variant;
  } else {
    p->animVariant = 0;
  }
  if (p->facing > 1) {
    p->xflip = TRUE;
  } else {
    p->xflip = FALSE;
  }
  p->animID = p->animVariant + animIdx;
  MainSprite_SetAnim(sprite, gfx, p->animID, playMode, flags);
  if (p->xflip) {
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
}

// 8方向の dir でアニメの向きを選び、5..7 は 3..1 を左右反転して使う, variant は読まない
void Boss_PlayAnimDir8(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx, u32 animIdx, u32 playMode, u32 variant, u32 flags) {
  u8 dir = p->dir;

  if (dir >= 5 && dir <= 7) {
    p->animVariant = 8 - dir;
    p->xflip = TRUE;
  } else {
    p->animVariant = dir;
    p->xflip = FALSE;
  }
  p->animID = p->animVariant + animIdx;
  MainSprite_SetAnim(sprite, gfx, p->animID, playMode, flags);
  if (p->xflip) {
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
}

void Boss_PlayAnim(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx, u32 animIdx, u32 playMode, u32 flags) {
  p->animVariant = 0;
  p->xflip = FALSE;
  p->animID = animIdx;
  MainSprite_SetAnim(sprite, gfx, p->animID, playMode, flags);
  if (p->xflip) {
    sprite->flags |= SPRFLAG_XFLIP;
  } else {
    sprite->flags &= ~SPRFLAG_XFLIP;
  }
}

s32 Boss_AdvanceAnim(Boss* p, MainSprite* sprite, MainSpriteGfx* gfx) {
  p->animDone = MainSprite_AdvanceAnim(sprite, gfx);
  p->prevAnimID = p->animID;
  return 0;
}

// state を 0 に戻し、targetPos への向きと距離、hp の割合を作り直す
void FUN_08022e20(Boss* p) {
  Mover* mover;
  s32 dx;
  s32 dz;

  p->state = 0;
  p->unk_dc = 0;
  mover = &p->mover;
  dx = p->targetPos.x - mover->pos.x;
  dz = p->targetPos.z - mover->pos.z;
  p->targetAngle = (u8)ArcTan2_8(dx, dz);
  p->targetDistSq = dx * dx + dz * dz;
  p->unk_dc = 1;
  Boss_UpdateHPRatio(p);
  if (p->hpRatio < 64) {
    p->lowHP = TRUE;
  } else {
    p->lowHP = FALSE;
  }
}

void FUN_08022ec0(Boss* p) {
  if (p->hp > 0) {
    gStat->gaugeValue = p->hp;
  } else {
    gStat->gaugeValue = 0;
  }
  if (p->unk_ac != 0) {
    Camera_Shake(p->unk_ad);
    p->unk_ac--;
  }
  if (p->unk_154 != 0 && (p->frameCount & 3) == 0) {
    FUN_0802326c(p);
  }
  if (p->unk_155 != 0 && (p->frameCount & 3) <= 1) {
    SET_FLAGS(p->flags, BOSSFLAG_HIDDEN);
  }
  if (p->unk_156 != 0) {
    SET_FLAGS(p->flags, BOSSFLAG_HIDDEN);
  }
}

// 毎フレームの状態処理, フラグを戻して timer を進め、updateCallback に増やす前の timer を渡す
void Boss_UpdateState(Boss* p) {
  u32 timer;

  p->flags = 0;
  p->subStateDone = 0;
  timer = p->timer++;
  if (p->updateCallback != NULL) {
    p->updateCallback(p, timer);
  }
}

void FUN_08022fac(Boss* p, u32 scriptA, u32 scriptB) {
  p->unk_e4 = scriptA;
  p->unk_e6 = scriptB;
}

void FUN_08022fb8(Boss* p, Vec3* pos) {
  u32 argv[8];
  ScriptArgs sa;
  s32 i;

  if (p->unk_e4 != 0) {
    u16 id = p->unk_e4;

    if (!TEST_FLAGS(gPlayerStates[0], 4)) {
      argv[0] = pos->x;
      argv[1] = pos->y;
      argv[2] = pos->z;
      for (i = 0; i < 4; i++) {
        argv[3 + i] = p->unk_e8[i];
      }
      sa.argc = 7, sa.argv = argv;
      VM_ExecByID(id, &sa);
    }
  }
}

void FUN_08023024(Boss* p, Vec3* pos) {
  u32 argv[8];
  ScriptArgs sa;
  s32 i;

  if (p->unk_e6 != 0) {
    u16 id = p->unk_e6;

    if (!TEST_FLAGS(gPlayerStates[0], 4)) {
      argv[0] = pos->x;
      argv[1] = pos->y;
      argv[2] = pos->z;
      for (i = 0; i < 4; i++) {
        argv[3 + i] = p->unk_e8[i];
      }
      sa.argc = 7, sa.argv = argv;
      VM_ExecByID(id, &sa);
    }
  }
}

void Boss_GiveWeaponExp(Boss* p, s32 amount) { Player_AddWeaponExp(p->weaponExpMask, amount); }

s32 FUN_080230a0(Vec3* out) {
  Boss* p = FUN_08022a3c();

  if (p == NULL) {
    return -1;
  }
  *out = p->mover.pos;
  return 0;
}

WorldPos* FUN_080230c4(void) {
  Boss* p = FUN_08022a3c();
  if (p == NULL) {
    return NULL;
  }
  return &p->mover.pos;
}

void Boss_ShowEmote(Boss* p, u32 kind, s32 param_3, s32 param_4) {
  switch (kind) {
    case 0: {
      p->emote = Emote_Show(p->emote, &p->mover, EMOTE_0, 1, NULL, 0, 0, 100);
      PlaySound_082406e0(SONG_433);
      break;
    }
    case 2: {
      p->emote = Emote_Show(p->emote, &p->mover, EMOTE_0, 0, NULL, 0, 0, 100);
      PlaySound_082406e0(SONG_492);
      break;
    }
    case 1: {
      p->emote = Emote_Show(p->emote, &p->mover, EMOTE_0, 3, NULL, 0, 0, 100);
      PlaySound_082406e0(SONG_492);
      break;
    }
    case 3: {
      p->emote = Emote_Show(p->emote, &p->mover, EMOTE_0, 2, NULL, 0, 0, 100);
      PlaySound_082406e0(SONG_493);
      break;
    }
    case 4: {
      p->unk_150 = param_3;
      p->unk_152 = param_4;
      p->emote = Emote_Show(p->emote, &p->mover, EMOTE_1, 0, &p->unk_150, p->unk_152, 0, 100);
      break;
    }
    case 5: {
      p->unk_150 = param_3;
      p->unk_152 = param_4;
      p->emote = Emote_Show(p->emote, &p->mover, EMOTE_3, 0, &p->unk_150, p->unk_152, 0, 100);
      break;
    }
    case 6: {
      p->emote = Emote_Show(p->emote, &p->mover, EMOTE_5, 0, NULL, 0, 0, 100);
      break;
    }
    case 7: {
      p->emote = Emote_Show(p->emote, &p->mover, EMOTE_4, 0, NULL, 0, 0, 100);
      break;
    }
    case 8: {
      break;
    }
  }
}

// ボスの位置から乱数でずらした位置で FUN_08015d3c を呼ぶ (unk_154 が立っている間、4 フレームに1回)
// 残差は y の & 0x1F の定数を作る位置だけ (74 対 74), 原典は &pos.y のアドレスを作ってから定数を作る
// 効いたもの: dx を u32 にする (z の dx - 0x7F が畳まれなくなる), 試済: y を式のまま書く (ldrsh になる), 未: Tier C
NON_MATCH void FUN_0802326c(Boss* p) {
#ifdef NONMATCHING_C
  u16* table = gRandomTable;
  Vec3 pos;
  u32 dx = _Random(table) & 0x7F;
  u32 dy;

  pos.x = p->mover.pos.x + dx;
  dy = _Random(table) & 0x1F;
  pos.y = p->mover.pos.y + dy;
  pos.z = p->mover.pos.z - (dx - 0x7F);
  FUN_08015d3c(&pos, 1, 0, 0x40, 12, 12, 4, 4);
#else
  INCFUNC("asm/func/FUN_0802326c.inc");
#endif
}

// 0x99FA, 今のボスの unk_154 / unk_155 / unk_156 を名前付き引数で立て下ろしする
void Cmd_SetBossFlags(void) {
  Boss* p = FUN_08022a3c();

  if (p != NULL) {
    if (VM_SeekToNamedArg('s')) {
      p->unk_154 = 1;
      PlaySound_082406e0(SONG_451);
    }
    if (VM_SeekToNamedArg('e')) {
      p->unk_154 = 0;
    }
    if (VM_SeekToNamedArg('b')) {
      p->unk_155 = 1;
    }
    if (VM_SeekToNamedArg('i')) {
      p->unk_156 = 1;
    }
  }
}
