#include "coffin.h"
#include "entity.h"
#include "global.h"
#include "input.h"
#include "map_inline.h"
#include "msgbus.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

// ワープ魔方陣

typedef struct {
  Particle ptcl;  // 0x00
  bool8 active;   // 0x28, 立っている枠だけ WarpMagicSquare_Update が WarpMagicSquarePtcl_Update に渡す
  u8 life;        // 0x29, 24 から数え下ろし, 0 で消える
  u8 unk_2a[2];   // 0x2A
  Vec3 vel;       // 0x2C, 毎フレーム 15/16 に減衰する
} WarpMagicSquarePtcl;
static_assert(sizeof(WarpMagicSquarePtcl) == 52);

typedef struct WarpMagicSquare {
  Entity e;                                         // 0x000, ENTITY_UNK_9
  MsgQueue mq;                                      // 0x018, CLS_ETC, 7 で浮き上がって光り, 8 でプレイヤー抜きのワープ演出を流す
  u16 nearState;                                    // 0x04C, プレイヤーが近いかを 0/1 で覚え, 変わったフレームだけ効果音を鳴らす
  u16 design;                                       // 0x04E, '.d=6', 魔方陣の絵柄 (ポーズ 0..7, +8 で光った絵), パレットと光の柱の色もこれで決まる
  AuxSprite sprite;                                 // 0x050, lift の高さに浮かせて重ねる光った魔方陣
  AuxSpriteGfx gfx;                                 // 0x07C, SPRITE_MAGIC_SQUARE
  Vec3 pos;                                         // 0x098, '.p', y はタイルの attr から計算し直す
  AuxSprite sprite2;                                // 0x0A0, 床に置く魔方陣, ワープ演出の間は消える
  AuxSpriteGfx gfx2;                                // 0x0CC, SPRITE_MAGIC_SQUARE
  AuxSprite pillars[3];                             // 0x0E8, 縦に積む光の柱
  AuxSpriteGfx pillarGfx[3];                        // 0x16C, SPRITE_MAGIC_SQUARE, パレットは plttID + 2
  u16 pillarLevel;                                  // 0x1C0, 光の柱の伸び具合 0..7, 2 段階ごとに柱が1本増える
  bool8 vanishOnArrive;                             // 0x1C2, '.s', 到着の演出が終わったら回りながら縮んで消える
  bool8 withCoffin;                                 // 0x1C3, COFFIN_SOLAR が近くにあって一緒にワープする
  u16 plttID;                                       // 0x1C4, 暗い色, +1 で半分光った色, +2 で光った色
  u16 glow;                                         // 0x1C6, 光り具合 0..8
  WarpMagicSquarePtcl ptcls[8];                     // 0x1C8
  u8 lift;                                          // 0x368, sprite を浮かせる高さ 0..24
  bool8 enabled;                                    // 0x369, '.a', 偽だと A ボタンで拒否音を鳴らすだけ
  u16 readyTimer;                                   // 0x36A, イベント中以外に 10 まで数え, 10 になるまでワープさせない
  s32 departScriptID;                               // 0x36C, '.C', プレイヤーが中心に着いたときに流す
  s32 arriveScriptID;                               // 0x370, '.i', 到着の演出が終わったときに流す
  s32 warpScriptID;                                 // 0x374, '.o', 出発の演出の最後に warpScriptArg を引数にして流す
  s32 warpScriptArg;                                // 0x378, '.n'
  s32 coffinScriptID;                               // 0x37C, '.c', withCoffin のとき出発の演出の最後に流す
  u16 unk_380;                                      // 0x380, '.f' があるとき 1, 読まれない
  u16 stateTimer;                                   // 0x382, updateCallback を差し替えるたびに 0 に戻る
  void (*updateCallback)(struct WarpMagicSquare*);  // 0x384
} WarpMagicSquare;
static_assert(sizeof(WarpMagicSquare) == 904);

void WarpMagicSquare_UpdateDepartSink(WarpMagicSquare* p);
void WarpMagicSquare_UpdateDormant(WarpMagicSquare* p);
void WarpMagicSquare_UpdateSpinIn(WarpMagicSquare* p);
void WarpMagicSquare_UpdatePillars(WarpMagicSquare* p);
bool32 FUN_08086af0(void);
void Player_LockHidden(Player* p);
void FUN_080a6e88(bool32 stopSound);
void WarpMagicSquare_UpdateDemoParticles(WarpMagicSquare* p);
void WarpMagicSquare_UpdateSpinOut(WarpMagicSquare* p);
void WarpMagicSquare_UpdateLit(WarpMagicSquare* p);
void WarpMagicSquare_UpdateDepartPillarsUp(WarpMagicSquare* p);
void Player_LockWarpOut(Player* p, DirS32 dir, u32 scriptID);
bool32 FUN_08086ab8(void);
void FUN_080a6edc(void);
void WarpMagicSquare_UpdateLightUp(WarpMagicSquare* p);
void WarpMagicSquare_UpdateDemoSink(WarpMagicSquare* p);
void WarpMagicSquare_UpdateDemoPillarsUp(WarpMagicSquare* p);
void WarpMagicSquare_UpdateDemoPillarsDown(WarpMagicSquare* p);
void WarpMagicSquare_UpdateIdle(WarpMagicSquare* p);
void WarpMagicSquare_UpdateArriveWait(WarpMagicSquare* p);
void Player_LockWarpIn(Player* p, DirS32 dir, u32 scriptID);
void WarpMagicSquare_UpdateDepartParticles(WarpMagicSquare* p);
void WarpMagicSquare_UpdateArriveParticles(WarpMagicSquare* p);
void WarpMagicSquare_UpdateArrivePillarsDown(WarpMagicSquare* p);
void WarpMagicSquare_UpdateDemoWait(WarpMagicSquare* p);
void WarpMagicSquare_UpdateDepartWait(WarpMagicSquare* p);

void WarpMagicSquarePtcl_Update(WarpMagicSquarePtcl* ptcl) {
  if (--ptcl->life == 0) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->active = FALSE;
  } else {
    ptcl->ptcl.pos.x += ptcl->vel.x;
    ptcl->ptcl.pos.y += ptcl->vel.y;
    ptcl->ptcl.pos.z += ptcl->vel.z;
    Particle_SetPose(&ptcl->ptcl, GetParticleGroup(PTCL_GROUP_2), ((ptcl->life >> 2) & 1) + 2);
    ptcl->vel.x = FixToInt(4, ptcl->vel.x * 15);
    ptcl->vel.y = FixToInt(4, ptcl->vel.y * 15);
    ptcl->vel.z = FixToInt(4, ptcl->vel.z * 15);
  }
}

// 88/81命令, WarpMagicSquarePtcl_SpawnRise と同じ形の残差, 1回目の下書きで切り上げ
NON_MATCH void WarpMagicSquarePtcl_SpawnFall(WarpMagicSquarePtcl* ptcl, Vec3* pos) {
#ifdef NONMATCHING_C
  ptcl->ptcl.pos = *pos;
  ptcl->ptcl.pos.x = ptcl->ptcl.pos.x - 15 + (Random() & 0x1F);
  ptcl->ptcl.pos.y = ptcl->ptcl.pos.y + 0x300 + (u8)Random();
  ptcl->ptcl.pos.z = ptcl->ptcl.pos.z - 15 + (Random() & 0x1F);
  ptcl->life = 24;
  ptcl->vel.x = 0;
  ptcl->vel.y = -((Random() & 0x1F) + 32);
  ptcl->vel.z = 0;
  ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  ptcl->active = TRUE;
#else
  INCFUNC("asm/func/WarpMagicSquarePtcl_SpawnFall.inc");
#endif
}

// 78/76命令, 1回目の下書きで切り上げ, 原典は退避レジスタが1本少なく乱数テーブルの読みを使い回す
NON_MATCH void WarpMagicSquarePtcl_SpawnRise(WarpMagicSquarePtcl* ptcl, Vec3* pos) {
#ifdef NONMATCHING_C
  ptcl->ptcl.pos = *pos;
  ptcl->ptcl.pos.x = ptcl->ptcl.pos.x - 15 + (Random() & 0x1F);
  ptcl->ptcl.pos.y += (u8)Random();
  ptcl->ptcl.pos.z = ptcl->ptcl.pos.z - 15 + (Random() & 0x1F);
  ptcl->life = 24;
  ptcl->vel.x = 0;
  ptcl->vel.y = (Random() & 0x1F) + 24;
  ptcl->vel.z = 0;
  ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  ptcl->active = TRUE;
#else
  INCFUNC("asm/func/WarpMagicSquarePtcl_SpawnRise.inc");
#endif
}

s32 WarpMagicSquare_IsPlayerNear(WarpMagicSquare* p) {
  s32 dx = abs(gStat->playerX - p->pos.x);
  s32 dz = abs(gStat->playerZ - p->pos.z);

  if (dx <= Q8(0.375) && dz <= Q8(0.375) && dx * dx + dz * dz <= Q8(0.375) * Q8(0.375)) {
    return TRUE;
  }
  return FALSE;
}

s32 WarpMagicSquare_IsSolarCoffinNear(WarpMagicSquare* p) {
  WorldPos* pos = Coffin_GetPos();

  if (pos != NULL && gCoffin->coffinID == COFFIN_SOLAR && gCoffin->state < 5) {
    s32 dy = abs(pos->y - p->pos.y);

    if (dy < Q8(1)) {
      s32 dx = pos->x - p->pos.x;
      s32 dz = pos->z - p->pos.z;

      if (dx <= Q8(1.485) && dz <= Q8(1.485) && dx * dx + dz * dz <= Q8(1.485) * Q8(1.485)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

// 256/254命令の下書き, (2 - lvl) * 171 + 1026 の掛け算と定数の足し方, 段ごとの sub スプライトのアドレスの作り方が原典と違う
NON_MATCH void WarpMagicSquare_UpdatePillars(WarpMagicSquare* p) {
#ifdef NONMATCHING_C
  if (p->pillarLevel != 0) {
    if (p->pillarLevel <= 2) {
      p->pillars[0].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[0].pos.y = (2 - p->pillarLevel) * 171 + 1026 + p->pos.y;
      p->pillars[1].flags |= SPRFLAG_HIDDEN;
      p->pillars[2].flags |= SPRFLAG_HIDDEN;
      p->sprite.poseIdx = p->design;
    } else if (p->pillarLevel <= 4) {
      p->pillars[0].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[0].pos.y = 1026 + p->pos.y;
      p->pillars[1].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[1].pos.y = (4 - p->pillarLevel) * 171 + 684 + p->pos.y;
      p->pillars[2].flags |= SPRFLAG_HIDDEN;
      p->sprite.poseIdx = p->design;
    } else if (p->pillarLevel <= 6) {
      p->pillars[0].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[0].pos.y = 1026 + p->pos.y;
      p->pillars[1].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[1].pos.y = 684 + p->pos.y;
      p->pillars[2].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[2].pos.y = (6 - p->pillarLevel) * 171 + 342 + p->pos.y;
      p->sprite.poseIdx = p->design;
      p->sprite.priority = 3;
    } else {
      p->pillars[0].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[0].pos.y = 1026 + p->pos.y;
      p->pillars[1].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[1].pos.y = 684 + p->pos.y;
      p->pillars[2].flags &= ~SPRFLAG_HIDDEN;
      p->pillars[2].pos.y = 342 + p->pos.y;
      p->sprite.poseIdx = p->design + 8;
      p->sprite.flags |= SPRFLAG_BLINK_ODD;
      p->sprite.priority = 1;
    }
  } else {
    p->pillars[0].flags |= SPRFLAG_HIDDEN;
    p->pillars[1].flags |= SPRFLAG_HIDDEN;
    p->pillars[2].flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/WarpMagicSquare_UpdatePillars.inc");
#endif
}

// 更新関数を差し替えて経過フレームを0に戻す
void WarpMagicSquare_SetUpdateCallback(WarpMagicSquare* p, void* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void WarpMagicSquare_UpdateDormant(WarpMagicSquare* p) {
  p->sprite.flags |= SPRFLAG_HIDDEN;
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
}

void WarpMagicSquare_UpdateLightUp(WarpMagicSquare* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_CIRCLE_IN);
    p->stateTimer++;
  }
  if (p->glow < 8) {
    p->glow++;
  }
  if (p->lift < 23) {
    p->lift += 2;
  } else {
    p->lift = 24;
  }
  if (p->lift == 0) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.pos.y = p->pos.y + p->lift;
  }
  if (p->glow >= 8) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
  } else if (p->glow != 0) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
  if (p->lift > 23) {
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateLit);
    MsgQueue_EndWait(&p->mq, 1);
  }
}

void WarpMagicSquare_UpdateLit(WarpMagicSquare* p) {
  p->lift = 0x18;
  p->glow = 8;
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  p->sprite.pos.y = p->pos.y + p->lift;
  Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
}

void WarpMagicSquare_UpdateDemoSink(WarpMagicSquare* p) {
  if (p->lift >= 2) {
    p->lift -= 2;
  } else {
    p->lift = 0;
  }
  p->sprite.pos.y = p->pos.y + p->lift;
  if (p->lift == 0) {
    p->sprite.flags &= ~SPRFLAG_BLINK_ODD;
    p->sprite.priority = 3;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDemoPillarsUp);
  }
}

void WarpMagicSquare_UpdateDemoPillarsUp(WarpMagicSquare* p) {
  if (p->pillarLevel <= 6) {
    p->pillarLevel++;
    WarpMagicSquare_UpdatePillars(p);
  } else {
    p->stateTimer++;
    if (p->stateTimer > 0x1F) {
      PlaySound_082406e0(SE_WARP_START);
      WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDemoWait);
    }
  }
}

void WarpMagicSquare_UpdateDemoWait(WarpMagicSquare* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDemoParticles);
  }
}

void WarpMagicSquare_UpdateDemoParticles(WarpMagicSquare* p) {
  if (p->stateTimer < 32 && !(p->stateTimer & 3)) {
    WarpMagicSquarePtcl_SpawnRise(&p->ptcls[p->stateTimer >> 2], &p->pos);
  }
  if (++p->stateTimer == 64) {
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDemoPillarsDown);
  }
}

void WarpMagicSquare_UpdateDemoPillarsDown(WarpMagicSquare* p) {
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  if (p->sprite.pos.y < p->pos.y + 22) {
    p->sprite.pos.y += 2;
  }
  if (p->pillarLevel != 0) {
    p->pillarLevel--;
    WarpMagicSquare_UpdatePillars(p);
  } else {
    p->sprite2.flags &= ~SPRFLAG_HIDDEN;
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateIdle);
    MsgQueue_EndWait(&p->mq, 1);
  }
}

// 122/123命令, 原典は &stateTimer を r5 に持ち越して拡大率の書き込みのたびに読み直す, 増やした値を t に受ける形は試済
NON_MATCH void WarpMagicSquare_UpdateSpinIn(WarpMagicSquare* p) {
#ifdef NONMATCHING_C
  u16 t = ++p->stateTimer;

  if (t < 64) {
    p->sprite.flags = (p->sprite.flags & ~SPRFLAG_HIDDEN) | SPRFLAG_AFFINE;
    p->sprite2.flags |= SPRFLAG_AFFINE;
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
    p->sprite.scaleX = t;
    p->sprite.scaleY = t;
    p->sprite.rotation = t << 2;
    p->sprite2.scaleX = p->sprite.scaleX;
    p->sprite2.scaleY = p->sprite.scaleX;
    p->sprite2.rotation = p->sprite.rotation;
    p->sprite.pos.y = p->pos.y + 22;
  } else if (t == 64) {
    p->sprite.flags &= ~SPRFLAG_AFFINE;
    p->sprite2.flags &= ~SPRFLAG_AFFINE;
    p->sprite.scaleX = Q6(1);
    p->sprite.scaleY = Q6(1);
    p->sprite2.scaleX = Q6(1);
    p->sprite2.scaleY = Q6(1);
  } else if (t >= 80) {
    if (--p->sprite.pos.y > p->pos.y) {
      Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
    } else {
      Video_SetAuxSpritePltt(&p->gfx, p->plttID);
      p->sprite.flags |= SPRFLAG_HIDDEN;
      WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateIdle);
    }
  }
#else
  INCFUNC("asm/func/WarpMagicSquare_UpdateSpinIn.inc");
#endif
}

// プレイヤーが近いと浮き上がって光り, A ボタンでプレイヤーを pos へ飛ばす (Entity7C62_UpdateIdle と同じ形)
void WarpMagicSquare_UpdateIdle(WarpMagicSquare* p) {
  s32 near;

  if (!(gGameFlags & GAMEFLAG_EVENT)) {
    if (p->readyTimer < 10) {
      p->readyTimer++;
    }
  }
  near = WarpMagicSquare_IsPlayerNear(p);
  if (near) {
    if (p->enabled == 0) {
      if (TEST_FLAGS(gPlayerModes[0], PMODE_ACTIVE) && gPlayerPtr[0]->action != 0x18 && gPlayerPtr[0]->action != 0x19 && (gInput[0].pressed & A_BUTTON)) {
        PlaySound_082406e0(SE_SOLAR_STAND_DENY);
      }
    } else {
      if (p->nearState != 1) {
        PlaySound_082406e0(SE_CIRCLE_IN);
        p->nearState = 1;
      }
      if (p->glow < 8) {
        p->glow++;
      }
      if (p->lift < 23) {
        p->lift += 2;
      } else {
        p->lift = 24;
      }
      if (TEST_FLAGS(gPlayerModes[0], PMODE_ACTIVE) && (gInput[0].pressed & A_BUTTON) && !gPlayerPtr[0]->formRequest && p->readyTimer > 9) {
        p->glow = 8;
        Player_MoveTo(gPlayerPtr[0], &p->pos, 0, 4);
        WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDepartSink);
      }
    }
  } else {
    if (p->nearState != 0) {
      PlaySound_082406e0(SE_CIRCLE_OUT);
      p->nearState = near;
    }
    if (p->glow != 0) {
      p->glow--;
    }
    if (p->lift > 2) {
      p->lift -= 2;
    } else {
      p->lift = near;
    }
  }

  if (p->lift == 0) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.pos.y = p->pos.y + p->lift;
  }

  if (p->glow > 7) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
  } else if (p->glow != 0) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
}

void WarpMagicSquare_UpdateDepartSink(WarpMagicSquare* p) {
  if (p->lift >= 2) {
    p->lift -= 2;
  } else {
    p->lift = 0;
  }
  p->sprite.pos.y = p->pos.y + p->lift;
  if (p->lift == 0 && gPlayerPtr[0]->action == 0) {
    Player_LockWarpOut(gPlayerPtr[0], 4, 0);
    p->withCoffin = 0;
    if (WarpMagicSquare_IsSolarCoffinNear(p) && FUN_08086ab8()) {
      p->withCoffin = 1;
    }
    p->sprite.flags &= ~SPRFLAG_BLINK_ODD;
    p->sprite.priority = 3;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDepartPillarsUp);
    if (p->departScriptID != 0) {
      VM_ExecByID(p->departScriptID, NULL);
    }
  }
}

void WarpMagicSquare_UpdateDepartPillarsUp(WarpMagicSquare* p) {
  if (p->pillarLevel <= 6) {
    p->pillarLevel++;
    WarpMagicSquare_UpdatePillars(p);
  } else {
    p->stateTimer++;
    if (p->stateTimer > 0x1F) {
      PlaySound_082406e0(SE_WARP_START);
      WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDepartWait);
    }
  }
}

void WarpMagicSquare_UpdateDepartWait(WarpMagicSquare* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDepartParticles);
  }
}

// 72/72命令, 残差はレジスタの割り当てと ScriptArgs の組み立て順だけ, 1回目の下書きで切り上げ
NON_MATCH void WarpMagicSquare_UpdateDepartParticles(WarpMagicSquare* p) {
#ifdef NONMATCHING_C
  if (p->stateTimer < 32 && !(p->stateTimer & 3)) {
    WarpMagicSquarePtcl_SpawnRise(&p->ptcls[p->stateTimer >> 2], &p->pos);
  }
  if (++p->stateTimer == 64) {
    if (p->warpScriptID != 0) {
      u32 argv[1];
      ScriptArgs sa;

      sa.argc = 1;
      argv[0] = p->warpScriptArg;
      sa.argv = argv;
      VM_ExecByID(p->warpScriptID, &sa);
    }
    if (p->withCoffin && p->coffinScriptID != 0) {
      VM_ExecByID(p->coffinScriptID, NULL);
    }
  }
#else
  INCFUNC("asm/func/WarpMagicSquare_UpdateDepartParticles.inc");
#endif
}

void WarpMagicSquare_UpdateArriveDelay(WarpMagicSquare* p) {
  p->stateTimer++;
  if (p->stateTimer > 0x3B) {
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateArriveParticles);
  }
}

void WarpMagicSquare_UpdateArriveParticles(WarpMagicSquare* p) {
  if (p->stateTimer == 16) {
    Player_LockWarpIn(gPlayerPtr[0], 4, 0);
  }
  if (p->stateTimer < 32 && !(p->stateTimer & 3)) {
    WarpMagicSquarePtcl_SpawnFall(&p->ptcls[p->stateTimer >> 2], &p->pos);
  }
  if (++p->stateTimer > 32) {
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateArriveWait);
  }
}

void WarpMagicSquare_UpdateArriveWait(WarpMagicSquare* p) {
  p->stateTimer++;
  if (p->stateTimer > 0xF) {
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateArrivePillarsDown);
  }
}

void WarpMagicSquare_UpdateArrivePillarsDown(WarpMagicSquare* p) {
  p->sprite.flags &= ~SPRFLAG_HIDDEN;
  if (p->sprite.pos.y < p->pos.y + 22) {
    p->sprite.pos.y += 2;
  }
  if (p->pillarLevel != 0) {
    p->pillarLevel--;
    WarpMagicSquare_UpdatePillars(p);
  } else {
    Player_Unlock(gPlayerPtr[0]);
    FUN_080a6edc();
    p->sprite2.flags &= ~SPRFLAG_HIDDEN;
    if (p->vanishOnArrive != 0) {
      WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateSpinOut);
    } else {
      WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateIdle);
    }
    if (p->arriveScriptID != 0) {
      VM_ExecByID(p->arriveScriptID, NULL);
    }
  }
}

// 127/125命令, 残差は縮小率 64 - stateTimer を2回書くところ (原典は1回作って使い回す) と分岐の距離
NON_MATCH void WarpMagicSquare_UpdateSpinOut(WarpMagicSquare* p) {
#ifdef NONMATCHING_C
  if (p->lift > 2) {
    p->lift -= 2;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.pos.y = p->pos.y + p->lift;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
  if (p->glow != 0) {
    p->glow--;
  }
  if (p->glow >= 8) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
  } else if (p->glow != 0) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
  if (++p->stateTimer < 64) {
    p->sprite.flags |= SPRFLAG_AFFINE;
    p->sprite2.flags |= SPRFLAG_AFFINE;
    p->sprite.scaleX = Q6(1) - (u8)p->stateTimer;
    p->sprite.scaleY = Q6(1) - (u8)p->stateTimer;
    p->sprite.rotation = p->stateTimer << 2;
    p->sprite2.scaleX = p->sprite.scaleX;
    p->sprite2.scaleY = p->sprite.scaleX;
    p->sprite2.rotation = p->sprite.rotation;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    KillEntity(&p->e);
  }
#else
  INCFUNC("asm/func/WarpMagicSquare_UpdateSpinOut.inc");
#endif
}

// 48/59命令, camera.c の Camera_PollMessages と同じメッセージ取り出しのループの残差, 原典は p と mq を別々のレジスタに持って条件式で gMsgBus を毎回読み直す
NON_MATCH void WarpMagicSquare_HandleMessages(WarpMagicSquare* p) {
#ifdef NONMATCHING_C
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    if (msg->cmd == 7) {
      WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateLightUp);
    } else if (msg->cmd == 8) {
      WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDemoSink);
    }
  }
#else
  INCFUNC("asm/func/WarpMagicSquare_HandleMessages.inc");
#endif
}

s32 WarpMagicSquare_Update(WarpMagicSquare* p) {
  s32 i;

  WarpMagicSquare_HandleMessages(p);
  p->updateCallback(p);
  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active) {
      WarpMagicSquarePtcl_Update(&p->ptcls[i]);
    }
  }
  return 0;
}

s32 WarpMagicSquare_Destroy(WarpMagicSquare* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  AuxSprite_Remove(&p->sprite2);
  for (i = 0; i < 3; i++) {
    AuxSprite_Remove(&p->pillars[i]);
  }
  for (i = 0; i < 8; i++) {
    Particle_Remove((Particle*)&p->ptcls[i]);
  }
  MsgQueue_Unregister(&p->mq);
  return 0;
}

void WarpMagicSquare_InitPtcls(WarpMagicSquare* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle* pt = &p->ptcls[i].ptcl;

    Particle_Add(pt, GetParticleGroup(PTCL_GROUP_2), SPRFLAG_HIDDEN);
    Particle_SetOffset(pt, -4, -4);
    Particle_SetPltt(pt, 1);
    Particle_SetPose(pt, GetParticleGroup(PTCL_GROUP_2), 2);
    pt->priority = 1;
    pt->offsetZ = 20;
    pt->pos = p->pos;
    p->ptcls[i].active = FALSE;
  }
}

// 518/509命令の下書き, sprite のポインタを r4 に置いて poseIdx を書く形と sub スプライトのループのレジスタが原典と違う, Entity7C62_Init が近い形
NON_MATCH s32 WarpMagicSquare_Init(WarpMagicSquare* p, u32 id, u32 param_3) {
#ifdef NONMATCHING_C
  s32 i;

  if (VM_SeekToNamedArg('p')) {
    p->pos.x = VM_GetValue();
    p->pos.y = VM_GetValue();
    p->pos.z = VM_GetValue();
    p->pos.y = TileHeightAt(&p->pos);
  } else {
    p->pos.x = 0;
    p->pos.y = 0;
    p->pos.z = 0;
  }
  if (VM_SeekToNamedArg('C')) {
    p->departScriptID = VM_GetValue();
  } else {
    p->departScriptID = 0;
  }
  if (VM_SeekToNamedArg('c')) {
    p->coffinScriptID = VM_GetValue();
  } else {
    p->coffinScriptID = 0;
  }
  if (VM_SeekToNamedArg('i')) {
    p->arriveScriptID = VM_GetValue();
  } else {
    p->arriveScriptID = 0;
  }
  if (VM_SeekToNamedArg('o')) {
    p->warpScriptID = VM_GetValue();
  } else {
    p->warpScriptID = 0;
  }
  if (VM_SeekToNamedArg('d')) {
    p->design = VM_GetValue();
  } else {
    p->design = 6;
  }
  if (VM_SeekToNamedArg('a')) {
    p->enabled = VM_GetValue();
  } else {
    p->enabled = 0;
  }
  if (VM_SeekToNamedArg('n')) {
    p->warpScriptArg = VM_GetValue();
  } else {
    p->warpScriptArg = 0;
  }
  p->plttID = (p->design >> 1) * 3 + 97;

  Video_GetAuxSprite(&p->gfx, SPRITE_MAGIC_SQUARE);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  p->sprite.poseIdx = p->design;
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  p->sprite.flags |= SPRFLAG_BLINK_ODD;
  p->sprite.priority = 3;
  p->sprite.pos = p->pos;

  Video_GetAuxSprite(&p->gfx2, SPRITE_MAGIC_SQUARE);
  AuxSprite_Add(&p->sprite2, &p->gfx2, 0);
  p->sprite2.poseIdx = p->design;
  Video_SetAuxSpritePltt(&p->gfx2, p->plttID);
  p->sprite2.flags |= SPRFLAG_BLINK_EVEN;
  p->sprite2.priority = 3;
  p->sprite2.pos = p->pos;

  for (i = 0; i < 3; i++) {
    Video_GetAuxSprite(&p->pillarGfx[i], SPRITE_MAGIC_SQUARE);
    AuxSprite_Add(&p->pillars[i], &p->pillarGfx[i], 0);
    p->pillars[i].poseIdx = (p->design & 1) + 16;
    Video_SetAuxSpritePltt(&p->pillarGfx[i], p->plttID + 2);
    p->pillars[i].flags |= SPRFLAG_BLINK_ODD | SPRFLAG_HIDDEN;
    p->pillars[i].priority = 1;
    p->pillars[i].pos = p->pos;
  }
  WarpMagicSquare_InitPtcls(p);
  MsgQueue_Register(&p->mq, id, 10);

  if (VM_SeekToNamedArg('D')) {
    p->nearState = 0;
    p->glow = 0;
    p->readyTimer = 0;
    p->lift = 0;
    WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateDormant);
  } else {
    s32 flash = 0;
    s32 script = 0;

    if (VM_SeekToNamedArg('f')) {
      flash = VM_GetValue();
    }
    if (VM_SeekToNamedArg('s')) {
      script = VM_GetValue();
    }
    if (flash) {
      s32 warp = 0;

      PlaySound_082406e0(SE_WARP_END);
      p->unk_380 = 1;
      FUN_080a6e88(FALSE);
      Player_SetPosAndSave(gPlayerPtr[0], &p->pos);
      Player_LockHidden(gPlayerPtr[0]);
      p->sprite.flags &= ~SPRFLAG_HIDDEN;
      Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
      p->sprite2.flags |= SPRFLAG_HIDDEN;
      p->pillarLevel = 7;
      WarpMagicSquare_UpdatePillars(p);
      p->glow = 8;
      p->nearState = 1;
      p->readyTimer = 10;
      p->lift = 24;
      p->vanishOnArrive = script;
      WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateArriveDelay);
      if (VM_SeekToNamedArg('w')) {
        warp = VM_GetValue();
      }
      if (warp && FUN_08086af0()) {
        FUN_08086a4c(&p->pos);
      }
    } else {
      p->nearState = 0;
      p->glow = 0;
      p->readyTimer = 0;
      p->lift = 0;
      if (script) {
        PlaySound_082406e0(SONG_350);
        p->sprite.flags |= SPRFLAG_AFFINE;
        p->sprite2.flags |= SPRFLAG_AFFINE;
        p->sprite.scaleX = 1;
        p->sprite.scaleY = 1;
        p->sprite2.scaleX = 1;
        p->sprite2.scaleY = 1;
        WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateSpinIn);
      } else {
        WarpMagicSquare_SetUpdateCallback(p, WarpMagicSquare_UpdateIdle);
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/WarpMagicSquare_Init.inc");
#endif
}

// 0xA8F1, HashName("ワープ魔方陣")
WarpMagicSquare* WarpMagicSquare_Create(u32 id, u32 param_2) {
  WarpMagicSquare* p = CreateEntity(ENTITY_UNK_9, sizeof(WarpMagicSquare));

  if (p != NULL) {
    SetEntityRoutine(p, WarpMagicSquare_Update, WarpMagicSquare_Destroy);
    if (WarpMagicSquare_Init(p, id, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
