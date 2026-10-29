#include "eff_082473e0.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_target.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

// Enemy の共通部分?
// 原典のファイル名は enedefault.c, 根拠: FUN_080f00ec / FUN_080f0430 が、抜き取られた assert の引数として文字列 "enedefault.c" (0x08251F80) と行番号を積む

extern const char s_enedefault_c_08251f80[];  // "enedefault.c"

void FUN_080f897c(Enemy* p);
void FUN_080e6794(Enemy* p, s32 priority);
s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);
void FUN_080e81dc(Enemy* p, s32 param_2);
void FUN_080f22e8(Enemy* p);
void FUN_080f230c(Enemy* p);
void FUN_080f2330(Enemy* p);
void FUN_080f229c(Enemy* p);
Mover* EnemyTargetManager_FindOwnerByID(u16 id);
s32 FUN_080e191c(Enemy* p);
s32 FUN_080e1f48(Enemy* p);
s32 FUN_080e35b4(Enemy* p);
bool32 FUN_080eafdc(Enemy* p);
bool32 FUN_080eb168(Enemy* p);
void FUN_080e6204(Enemy* p);
EnemyTarget* EnemyTargetManager_Claim(Enemy* p, s32 kindMask);
s32 FUN_080f8abc(Enemy* p);
bool8 FUN_080e5ed4(Enemy* p, NavAgent* agent, u32 rangeX, u32 rangeZ, s32 speed);
bool8 FUN_080e60b8(Enemy* p, NavAgent* agent, u32 rangeX, u32 rangeZ, s32 speed);
bool32 FUN_08235fd8(u16* p);

const EnemyHandler gEnemyHandlerTable0[4] = {
    FUN_080f22e8,
    FUN_080f230c,
    FUN_080f2330,
    FUN_080f229c,
};  // 0x085AD3D4

void FUN_080f34ec(Enemy* p);
void FUN_080f35fc(Enemy* p);
void FUN_080f3574(Enemy* p);

const EnemyHandler gEnemyHandlerTable1[3] = {
    FUN_080f34ec,
    FUN_080f35fc,
    FUN_080f3574,
};  // 0x085AD3E4

void FUN_080f2644(Enemy* p);
void FUN_080f2864(Enemy* p);
void FUN_080f248c(Enemy* p);
void FUN_080f2364(Enemy* p);
void FUN_080f2ec0(Enemy* p);
void FUN_080f2d04(Enemy* p);
void FUN_080f2a40(Enemy* p);
void FUN_080f31c4(Enemy* p);
void FUN_080f19cc(Enemy* p);
void FUN_080f33e8(Enemy* p);
void FUN_080f34a0(Enemy* p);
void FUN_080f0e78(Enemy* p);
void FUN_080f11d0(Enemy* p);
void FUN_080f12c4(Enemy* p);

const EnemyHandler gEnemyHandlerTable2[15] = {
    FUN_080f2644,
    FUN_080f2864,
    FUN_080f248c,
    FUN_080f2364,
    NULL,
    FUN_080f2ec0,
    FUN_080f2d04,
    FUN_080f2a40,
    FUN_080f31c4,
    FUN_080f19cc,
    FUN_080f33e8,
    FUN_080f34a0,
    FUN_080f0e78,
    FUN_080f11d0,
    FUN_080f12c4,
};  // 0x085AD3F0

const EnemyHandler gEnemyHandlerTable3[1] = {
    NULL,
};  // 0x085AD42C

const EnemyHandler gEnemyHandlerTable4[1] = {
    NULL,
};  // 0x085AD430

void FUN_080f2254(Enemy* p);

const EnemyHandler gEnemyHandlerTable5[1] = {
    FUN_080f2254,
};  // 0x085AD434

void FUN_080f1c54(Enemy* p);
void FUN_080f1cb8(Enemy* p);
void FUN_080f1cf0(Enemy* p);

const EnemyHandler gEnemyHandlerTable6[3] = {
    FUN_080f1c54,
    FUN_080f1cb8,
    FUN_080f1cf0,
};  // 0x085AD438

void FUN_080f2278(Enemy* p);

const EnemyHandler gEnemyHandlerTable7[1] = {
    FUN_080f2278,
};  // 0x085AD444

void FUN_080f1de4(Enemy* p);
void FUN_080f1e0c(Enemy* p);
void FUN_080f1e78(Enemy* p);
void FUN_080f1ef8(Enemy* p);
void FUN_080f2074(Enemy* p);
void FUN_080f2160(Enemy* p);

const EnemyHandler gEnemyHandlerTable8[6] = {
    FUN_080f1de4,
    FUN_080f1e0c,
    FUN_080f1e78,
    FUN_080f1ef8,
    FUN_080f2074,
    FUN_080f2160,
};  // 0x085AD448

void FUN_080f22c0(Enemy* p);
void FUN_080f22c4(Enemy* p);

const EnemyHandler gEnemyHandlerTable9[2] = {
    FUN_080f22c0,
    FUN_080f22c4,
};  // 0x085AD460

// 下位状態を指定の組に戻して経過フレームを0に巻き戻す, subStateBegun は巻き戻した印
static inline void Enemy_ResetState(Enemy* p, u8 subState0, u8 subState1, u8 subState2) {
  p->subState0 = subState0;
  p->subState1 = subState1;
  p->subState2 = subState2;
  p->subStateTimer = 0;
  p->subStateBegun = 1;
}

// 下位状態の3段目を差し替えて経過フレームを0に巻き戻す
static inline void Enemy_SetSubState2(Enemy* p, u32 subState) {
  p->subState2 = subState;
  p->subStateTimer = 0;
  p->subStateBegun = 1;
}

// 状態ハンドラを差し替えて入場フラグを立てる
static inline void Enemy_EnterState(Enemy* p, void* handler, s32 state) {
  p->stateBegun = TRUE;
  p->subStateDone = 0;
  p->state = state;
  p->handlerState = handler;
  p->stateTimer = 0;
}

// スプライトの座標を指す, spriteKind で AuxSprite か MainSprite かが変わる
static inline Vec3* Enemy_GetSpritePos(Enemy* p) {
  if (p->spriteKind == 0) {
    return &((AuxSprite*)p->sprite)->pos;
  }
  return &p->sprite->s.pos;
}

// 状態に入った最初の呼び出しだけ TRUE, 入場フラグを下ろす
static inline bool8 Enemy_ConsumeStateBegun(Enemy* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    return TRUE;
  }
  return FALSE;
}

// 下位状態を巻き戻した直後の呼び出しだけ TRUE, 巻き戻しの印を下ろす
static inline bool8 Enemy_ConsumeSubStateBegun(Enemy* p) {
  if (p->subStateBegun) {
    p->subStateBegun = 0;
    return TRUE;
  }
  return FALSE;
}

// 歩きアニメの速さを 64 / animSpeedDiv にする, 怯みなどの印が立っていれば等速に戻す
static inline void Enemy_UpdateWalkAnimSpeed(Enemy* p) {
  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    p->animSpeedDiv = 1;
  } else if (p->animSpeedDiv == 0) {
    p->animSpeedDiv = 1;
  }

  if (p->spriteKind == 0) {
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)p->sprite)->anim, Div(64, p->animSpeedDiv));
  } else {
    MainSprite_SetAnimSpeed(&p->sprite->s, (u16)Div(64, p->animSpeedDiv));
  }
}

// スプライトの座標を mover.pos に揃える, spriteKind で AuxSprite か MainSprite かが変わる
static inline void Enemy_SyncSpritePos(Enemy* p) {
  if (p->spriteKind == 0) {
    ((AuxSprite*)p->sprite)->pos = p->mover.pos;
  } else {
    p->sprite->s.pos = p->mover.pos;
  }
}

// スプライトの OAM 優先度を変える, spriteKind で AuxSprite か MainSprite かが変わる
static inline void Enemy_SetSpritePriority(Enemy* p, u8 priority) {
  if (p->spriteKind == 0) {
    ((AuxSprite*)p->sprite)->priority = priority;
  } else {
    p->sprite->s.priority = priority;
  }
}

void PlayEnemyDeathCry(Enemy* p);
void FUN_080e7b6c(Enemy* p);
void FUN_080f8ae0(Enemy* p);

// ENEFLAG_UNK_21 が立っていればそれに付随する印と値を片付け, ENEFLAG_UNK_4 / UNK_7 も落とす
static inline void Enemy_ClearUnk21Flags(Enemy* p) {
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
  CLEAR_FLAGS(p->flags, ENEFLAG_UNK_4 | ENEFLAG_UNK_7);
}

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

static inline bool8 IsLinkPlay(void) {
  if (gGameFlags & (FLAG030047A4_LINK | FLAG030047A4_UNK_14)) return TRUE;
  return FALSE;
}

void FUN_080ee738(Enemy* p);
void FUN_080e49c4(Enemy* p);
void FUN_080e4a68(Enemy* p);
void FUN_080ee2c8(Enemy* p);
bool8 FUN_080f3718(Enemy* p);
void Entity4B15_ShowTrackingMarker(s32 playerIdx, Vec3* pos);
void FUN_080e5098(Enemy* p, s32 param_2, s32 param_3);
void FUN_080e499c(Enemy* p);
void FUN_080e64b4(Enemy* p, s32 count);
void FUN_080f5c0c(Enemy* p);
void FUN_080f5208(Enemy* p);
bool8 FUN_080fa7a4(Enemy* p);
void FUN_080faad8(Enemy* p);
void FUN_080ce544(u32 param_1, u32 param_2);
void FUN_080ec5b4(u16 a, u16 b);
s8 FUN_08240dc8(s32 x, s32 y, s32 size, u8 mask, u16 param_5);
void FUN_080e8f20(Enemy* p, s32 param_2);
bool8 FUN_080eb2a0(Enemy* p);
void FUN_0809c344(s32 param_1, s32 param_2, u16 param_3, u16 param_4, s32 param_5);
void FUN_080e6408(Enemy* p, s32 count, u32 kind, s32 rangeX, s32 rangeY, u32 param_6);
void FUN_080e9178(Enemy* p);
void FUN_080e64e4(Enemy* p);
void FUN_080efc44(Enemy* p, s32 param_2, s32 param_3);

// FUN_080f2644 / FUN_080f2864 が添字として引く, 用途は未解析
const u8 u8_ARRAY_085ad468[5] = {0, 1, 2, 3, 4};  // 0x085AD468

// 全 Enemy*_Init が Enemy のフィールドに代入する既定のメッセージハンドラ表, Enemy_DispatchMsg が table[msg[0]](p, msg) で呼ぶ
void (*const gEnemyDefaultMsgHandlers[6])(Enemy*, u16*) = {
    FUN_080f09a4,
    FUN_080f07d0,
    FUN_080f0914,
    FUN_080f0868,
    FUN_080e6624,
    FUN_080e664c,
};  // 0x085AD470

// --------------------------------------------

// "enedefault.c" を参照しているので、この関数が "enedefault.c" 内にあるのは間違いない
// 攻撃対象を手放して状態16へ移し, 感情アイコンを出して, 通信プレイでなければ見つかった回数を数える
// 残差は224/226命令, 頭打ちの 9999 を原典は r1 に読んでから r0 へ移し, 各回数のオフセットを r3 で作るが, こちらは r0 に直接読み r1 を使う
// 試済: 回数を増やす inline (s16* を受ける形は後半がまとめられて 210), 三項演算子 (246), 分岐の向きの反転 (変化なし), switch (比較が増える)
NON_MATCH void FUN_080f00ec(Enemy* p) {
#ifdef NONMATCHING_C
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_26)) {
    return;
  }

  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
    EnemyTargetManager_Release(p->target);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
    p->target = NULL;
  }
  CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
  p->unk_21e = 0;
  p->unk_220 = 0;
  p->unk_202 = 0;
  Enemy_ClearPendingState(p, s_enedefault_c_08251f80, 272);
  Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
  Enemy_ResetState(p, 3, 1, 0);
  CLEAR_FLAGS(p->flags, ENEFLAG_UNK_7);
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_0);
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
  p->unk_542 = 0xFF;
  Enemy_SetEmote(p, 0, 0, p->kind);

  if (IsLinkPlay()) {
    return;
  }
  if (TEST_FLAGS(p->flags2, ENEFLAG2_UNK_15)) {
    return;
  }
  if (p->playerMover->unk_4 == 0) {
    if (gStat->unk_950[0] < 9999) {
      gStat->unk_950[0]++;
    } else {
      gStat->unk_950[0] = 9999;
    }
    if (gStat->alertCount < 9999) {
      gStat->alertCount++;
    } else {
      gStat->alertCount = 9999;
    }
  } else if (p->playerMover->unk_4 == 1) {
    if (gStat->unk_950[1] < 9999) {
      gStat->unk_950[1]++;
    } else {
      gStat->unk_950[1] = 9999;
    }
  } else if (p->playerMover->unk_4 == 2) {
    if (gStat->unk_950[2] < 9999) {
      gStat->unk_950[2]++;
    } else {
      gStat->unk_950[2] = 9999;
    }
  } else if (p->playerMover->unk_4 == 3) {
    if (gStat->unk_950[3] < 9999) {
      gStat->unk_950[3]++;
    } else {
      gStat->unk_950[3] = 9999;
    }
  }
#else
  INCFUNC("asm/func/FUN_080f00ec.inc");
#endif
}

// 追う相手が決まっていれば向きをそちらへ合わせて 1 を返す, いなければ 0
s32 FUN_080f0320(Enemy* p) {
  if (p->unk_1d4 > 0) {
    FUN_080f00ec(p);
    CLEAR_FLAGS(p->unk_222, ENEMY222_UNK_1);
    Enemy_SetFlag4(p, ENEFLAG4_UNK_7);
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_8);
    Enemy_SetFlag(p, ENEFLAG_UNK_27);
    p->playerMover = EnemyTargetManager_FindOwnerByID(p->unk_1d4);
    p->unk_25e = GetCollisionTileIdx(&p->playerMover->pos);
    {
      Vec3 d;
      Vec3* dst = &d;
      WorldPos* pos = &p->mover.pos;

      Vec3_Diff(dst, &p->playerMover->pos, pos);
      p->mover.angle = ArcTan2_8(d.x, d.z);
    }
    return 1;
  }

  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_3)) {
    p->flags &= ~ENEFLAG_UNK_27;
  }
  return 0;
}

// 狙う相手を1つ確保できたら, unk_1f8 があれば追いかけ, なければ状態16へ移して感情アイコンを出す, 移ったら TRUE
// 残差は271/275命令, 原典は flags3 の検査結果 (0) と &p->flags をスタックに退避し, &p->target を range0Sq を見る前に作って r10 に持つ
// 追いかける部分は enemy.c の Enemy_StepToward と同じ形の inline で揃う, 試済: 攻撃対象を手放す3行を inline にする (278, 検査結果の退避は揃う)
NON_MATCH bool8 FUN_080f0430(Enemy* p) {
#ifdef NONMATCHING_C
  EnemyTarget* target;
  u16 tile;

  if (p->flags3 & ENEFLAG3_UNK_4) {
    return FALSE;
  }
  if (p->unk_618(p)) {
    return TRUE;
  }
  if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_20)) {
    return FALSE;
  }
  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  if (p->range0Sq == 0) {
    return FALSE;
  }
  target = EnemyTargetManager_Claim(p, 6);
  if (target == NULL) {
    return FALSE;
  }

  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
    EnemyTargetManager_Release(p->target);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
    p->target = NULL;
  }
  p->playerMover = target->owner;
  tile = target->owner->tile->tileIdx[1];
  CLEAR_FLAGS(p->unk_222, ENEMY222_UNK_1);

  if (p->unk_1f8 != 0) {
    if (TEST_FLAGS(p->flags, ENEFLAG_UNK_26)) {
      if (p->unk_25e != tile) {
        NavAgent* agent = p->navAgent;
        WorldPos* dst = &p->playerMover->pos;
        bool8 moved = FALSE;

        if (Map_IsPosInAgentIsland(agent, &p->mover.pos, dst)) {
          s32 result = FUN_08235f40(agent, &p->mover.pos, dst);

          if (result != 0) {
            if (result != 2) {
              ClearMemory(&p->mover.delta, 8);
            }
            moved = TRUE;
          }
        }
        if (!moved) {
          Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
        }
        p->unk_25e = tile;
      }
    } else {
      FUN_080f00ec(p);
    }
    Enemy_SetFlag4(p, ENEFLAG4_UNK_7);
    SET_FLAGS(p->flags, ENEFLAG_UNK_27);
    return FALSE;
  }

  if (p->unk_544 != 0) {
    return FALSE;
  }
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_7)) {
    return FALSE;
  }
  SET_FLAGS(p->flags, ENEFLAG_UNK_7);
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_8);
  Enemy_ClearPendingState(p, s_enedefault_c_08251f80, 378);
  Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
  Enemy_ResetState(p, 3, 1, 0);
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
  p->unk_542 = 0xFF;
  Enemy_PlayAnim(p, 0);
  p->unk_202 = 180;
  Enemy_SetEmote(p, 0, 1, p->kind);
  Enemy_SetFlag4(p, ENEFLAG4_UNK_8);
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080f0430.inc");
#endif
}

void FUN_080f06ac(Enemy* p) {}

// 毎フレームの更新, 今のゾーンにいなければ活動を止め, 止まっていれば復帰を待つ
bool32 FUN_080f06b0(Enemy* p) {
  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), FLAG030047A4_GAMEOVER) || TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    return FALSE;
  }

  if (!Enemy_TestFlag(p, ENEFLAG_UNK_1)) {
    if (!IsCurrentZone(p->zoneID)) {
      FUN_080f07d0(p, NULL);
      return FALSE;
    }

    if (!Enemy_IsDead(p) && !p->unk_624(p)) {
      p->unk_628(p);
    }
    FUN_080eafdc(p);
    FUN_080e1f48(p);
    p->unk_580(p->unk_1cc);
    FUN_080e35b4(p);
    FUN_080e191c(p);
    FUN_080eb168(p);
    FUN_080f06ac(p);
    return TRUE;
  }

  if (!Enemy_TestFlag(p, ENEFLAG_UNK_0) && IsCurrentZone(p->zoneID)) {
    FUN_080f0914(p, NULL);
  }
  FUN_080f06ac(p);
  return FALSE;
}

// 活動を止める, スプライトを隠して影も消す
void FUN_080f07d0(Enemy* p, u16* msg) {
  if (Enemy_IsDead(p)) {
    return;
  }
  if (Enemy_TestFlag(p, ENEFLAG_UNK_1)) {
    return;
  }

  Enemy_SetFlag(p, ENEFLAG_UNK_1);
  Enemy_ClearSpriteFlags(p, SPRFLAG_AFFINE);
  Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
  p->hitbox.flags |= HBFLAG_HIDDEN;
  if (p->unk_44c == 0) {
    ParticleShadow_Hide(&p->shadow);
  }
}

// 経路追従をやり直して状態12へ移す
void FUN_080f0868(Enemy* p, u16* _) {
  if (Enemy_TestFlag(p, ENEFLAG_UNK_0)) {
    FUN_080e4a68(p);
    if (p->unk_44c == 0) {
      ParticleShadow_Show(&p->shadow);
    }
    p->hitbox.flags &= ~HBFLAG_HIDDEN;
    FUN_080ee2c8(p);
    Enemy_ResetState(p, 3, 0, 0);
    Enemy_EnterState(p, p->unk_584, 12);
  }
}

// 活動停止から復帰する, 影を出し直してアフィンを解除する
void FUN_080f0914(Enemy* p, u16* msg) {
  if (Enemy_IsDead(p)) {
    return;
  }
  if (Enemy_TestFlag(p, ENEFLAG_UNK_0)) {
    return;
  }
  if (!Enemy_TestFlag(p, ENEFLAG_UNK_1)) {
    return;
  }

  Enemy_ClearFlag(p, ENEFLAG_UNK_1);
  if (p->unk_44c == 0) {
    ParticleShadow_Show(&p->shadow);
  }
  p->hitbox.flags &= ~HBFLAG_HIDDEN;
  p->hitbox.invincibleTime = 0;
  if (p->spriteKind == 0) {
    AuxSprite_ClearFlags((AuxSprite*)p->sprite, SPRFLAG_HIDDEN);
  } else {
    MainSprite_ClearFlags(&p->sprite->s, SPRFLAG_HIDDEN);
  }
}

void FUN_080f09a4(Enemy* p, u16* msg) {
  if ((Enemy_IsDead(p) == 0) && (Enemy_TestFlag(p, ENEFLAG_UNK_0) == 0) && (Enemy_TestFlag(p, ENEFLAG_UNK_1) != 0)) {
    FUN_080ee738(p);
    p->hitbox.invincibleTime = 0;
  }
}

// メッセージの種類で p->unk_60c のハンドラ表を引いて呼ぶ
void Enemy_DispatchMsg(Enemy* p, u16* msg) {
  if (msg != NULL) {
    u32 idx = msg[0];
    EnemyMsgHandler* table = p->unk_60c;
    table[idx](p, msg);
  }
}

// 条件が揃っていれば攻撃対象を1つ確保して状態16へ移る, 確保できたら TRUE
// 残差は129/134命令, 分岐の形は || の早期 return + if (target != NULL) で揃うが, p を r6 でなく r5 に置き, 確保後の初期化の格納順も詰まる (原典は 0 を r2/r5 に持って並べ直さない)
// 試済: 早期 return を6本に分ける / && の入れ子 / Enemy_TestFlag 経由, いずれも失敗ブロックが末尾に寄って悪化
NON_MATCH bool8 FUN_080f0a0c(Enemy* p) {
#ifdef NONMATCHING_C
  EnemyTarget* target;

  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_4 | ENEFLAG3_UNK_12) || !TEST_FLAGS(p->flags, ENEFLAG_UNK_24) || !TEST_FLAGS(p->flags, ENEFLAG_UNK_20) || TEST_FLAGS(p->flags, ENEFLAG_UNK_7) || (p->target != NULL && (p->target->kindMask & 1 || p->target->kindMask & 4)) ||
      p->range0Sq == 0) {
    return FALSE;
  }
  target = EnemyTargetManager_Claim(p, 1);
  if (target != NULL) {
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    p->target = target;
    Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
    Enemy_ResetState(p, 3, 1, 0);
    Enemy_ClearFlag(p, ENEFLAG_UNK_4);
    Enemy_SetFlag4(p, ENEFLAG4_UNK_11);
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080f0a0c.inc");
#endif
}

// 経路の今のノードを目標にし直し, 攻撃対象へ一歩動ければ感情アイコンを出して状態14へ, 動けなければノードへ向かって状態1へ移す
// 残差は342/349命令, 原典は p を r7 に置き, 攻撃対象へ一歩動く部分で p->target を navAgent より先に, owner を &pos の後に読む
// 試済: Enemy_StepToward 形の inline (dst を引数, EnemyTarget* を引数) はどちらも 352 前後で寄らない
NON_MATCH void FUN_080f0b3c(Enemy* p) {
#ifdef NONMATCHING_C
  Vec3* target;
  PathWalker* walker;
  bool8 moved;

  Enemy_PlayAnim(p, 0);
  target = p->unk_4a8;
  walker = &p->pathWalker;
  target->x = walker->node->x;
  target->z = walker->node->y;
  target->y = TileHeightAt(target);

  {
    EnemyTarget* t = p->target;
    NavAgent* agent = p->navAgent;
    WorldPos* pos = &p->mover.pos;
    WorldPos* dst = &t->owner->pos;

    if (!Map_IsPosInAgentIsland(agent, pos, dst)) {
      Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
      moved = FALSE;
    } else {
      s32 result = FUN_08235f40(agent, pos, dst);

      if (result != 0) {
        if (result != 2) {
          ClearMemory(&p->mover.delta, 8);
        }
        moved = TRUE;
      } else {
        Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
        moved = FALSE;
      }
    }
  }

  if (!moved) {
    WorldPos dst;
    WorldPos* d = &dst;
    NavAgent* agent;

    walker = &p->pathWalker;
    d->x = walker->node->x;
    d->z = walker->node->y;
    d->y = TileHeightAt(d);
    agent = p->navAgent;
    if (!Map_IsPosInAgentIsland(agent, &p->mover.pos, &dst)) {
      Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
    } else {
      s32 result = FUN_08235f40(agent, &p->mover.pos, &dst);

      if (result == 0) {
        Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
      } else if (result != 2) {
        ClearMemory(&p->mover.delta, 8);
      }
    }
    Enemy_EnterState(p, p->unk_5a0, 1);
    Enemy_ResetState(p, 0, 0, 2);
    return;
  }

  Enemy_SetEmote(p, 0, 1, p->kind);
  Enemy_ResetState(p, 3, 1, 0);
  Enemy_EnterState(p, FUN_080e6794, 14);
  p->unk_554 = 30;
  p->unk_558 = p->unk_5a0;
  p->unk_550 = 0;
  p->unk_551 = 0;
  p->unk_552 = 7;
  SET_FLAGS(p->flags, ENEFLAG_UNK_4);
  SET_FLAGS(p->flags3, ENEFLAG3_UNK_12);
  p->unk_4a8->val = 0;
#else
  INCFUNC("asm/func/FUN_080f0b3c.inc");
#endif
}

// 経路の目標へ歩かせ, 向きが変わるときは unk_222 の印に応じて, 今の状態を退避してから乱数の新しい向きで状態27へ移る
// 残差は351/351命令, 原典は退避と状態27への切り替えの格納先アドレスを (乱数のループの外で) 15個ほどスタックに作り置く (sub sp, #0x44), こちらは 0x34
// 退避をループの中に入れるとアドレスの作り置きが出る, unk_222 の検査は bool8 を返す inline で 0/1 の作り置きが揃う, 試済: for で break してから退避する (0x24)
NON_MATCH void FUN_080f0e78(Enemy* p) {
#ifdef NONMATCHING_C
  s32 speed;

  if (p->subStateBegun) {
    p->subStateBegun = 0;
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }

  speed = p->unk_588(p);
  Enemy_UpdateWalkAnimSpeed(p);

  if (FUN_08235fd8(&p->navAgent->flags)) {
    if (!FUN_080e60b8(p, p->navAgent, 32, 32, speed)) {
      p->subStateTimer++;
      return;
    }
    if (!TEST_FLAGS(p->unk_222, ENEMY222_UNK_2)) {
      if (FUN_080eb2a0(p)) {
        return;
      }
      if (TEST_FLAGS(p->unk_222, ENEMY222_UNK_0)) {
        u32 angle2 = ((p->unk_1dc + 5) & 7) << 5;
        u8 angle;
        s32 i;
        u32 a;

        if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_10)) {
          return;
        }
        if (TEST_FLAGS(p->unk_222, ENEMY222_UNK_2)) {
          return;
        }
        angle = p->mover.angle;
        i = 0;
        while (TRUE) {
          a = (Random() & 3) << 6;
          if (a != angle || ++i > 3) {
            p->unk_540 = a;
            p->unk_548 = p->handlerState;
            p->unk_54f = p->state;
            p->unk_54c = p->subState0;
            p->unk_54d = p->subState1;
            p->unk_54e = p->subState2;
            p->unk_541 = angle2;
            Enemy_EnterState(p, p->unk_5bc, 27);
            Enemy_ResetState(p, 3, 1, 0);
            p->unk_542 = 2;
            return;
          }
        }
        return;
      }
    }
    p->subState2 = 13;
    p->subStateTimer = 0;
    p->subStateBegun = 1;
    p->subStateTimer++;
    return;
  }
  if (FUN_080e5ed4(p, p->navAgent, 32, 32, speed)) {
    p->subState2 = 14;
    p->subStateTimer = 0;
    p->subStateBegun = 1;
    return;
  }
  p->subStateTimer++;
#else
  INCFUNC("asm/func/FUN_080f0e78.inc");
#endif
}

// いろんなEnemyで使われるハンドラ
void FUN_080f11d0(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_590, 2);
  }

  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }
  if (p->subStateDone) {
    Enemy_PlayAnim(p, 0);
    Enemy_SetSubState2(p, 12);
    Enemy_EnterState(p, p->unk_5b8, 26);
  } else {
    p->subStateTimer++;
  }
}

// 1P を見失ったあと 60 フレーム待ってから, 1P のいるタイルへ向かえるならそちらへ一歩動き, 同じタイルなら状態26か状態1へ移り, 向きを乱数で変える状態27を予約する
// 命令数は 779/779 で同じ, 残差は原典が状態や下位状態のフィールドのアドレスを一度作ってスタック (フレーム 0x70, こちらは 0x40) に持ち越し, 後の Enemy_EnterState / Enemy_ResetState で使い回す点
// 試済: Enemy_EnterState / Enemy_ResetState を直書きにする (772 命令で遠ざかる)
NON_MATCH void FUN_080f12c4(Enemy* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5a4, 0);
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_7);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }
  if (p->subStateTimer <= 60) {
    p->subStateTimer++;
    return;
  }

  p->unk_222 &= ~(ENEMY222_UNK_1 | ENEMY222_UNK_2);
  Enemy_EnterState(p, FUN_080e6794, 14);
  p->unk_554 = p->unk_543;
  p->unk_558 = p->unk_5b8;
  p->unk_550 = 0;
  p->unk_551 = 0;
  p->unk_552 = 12;
  Enemy_ResetState(p, 3, 1, 0);
  {
    Vec3* dst = p->unk_4a8;
    PathWalker* walker = &p->pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }

  if (IsLinkPlay()) {
    Mover* m = p->playerMover;

    idx = -1;
    if (m != NULL && m->unk_4 <= 3) {
      idx = m->unk_4;
    }
    if (m == NULL || idx < 0) {
      p->unk_5c4(p);
      return;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&p->playerMover->pos);
    idx = 0;
  }

  if (tile != p->unk_256 && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    WorldPos tilePos;
    bool8 moved = FALSE;

    {
      s32 x = Mod(tile, gCollisionMap->tiledata->width);
      s32 z = Div(tile, gCollisionMap->tiledata->width);
      MapTileOverride* ov;

      tilePos.x = (x << 8) + 0x80;
      ov = Map_FindTileOverride(tile, 1);
      tilePos.y = ((ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[tile])->heightStairs & 0xF) << 8;
      tilePos.z = (z << 8) + 0x80;
    }
    {
      NavAgent* agent = p->navAgent;
      WorldPos* pos = &p->mover.pos;

      if (Map_IsPosInAgentIsland(agent, pos, &tilePos)) {
        s32 result = FUN_08235f40(agent, pos, &tilePos);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&p->mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      p->unk_5c4(p);
    }
    return;
  }

  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_10)) {
    return;
  }
  p->unk_222 &= ~ENEMY222_UNK_2;
  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_7)) {
    Enemy_EnterState(p, p->unk_5b8, 26);
    Enemy_ResetState(p, 0, 0, 12);
  } else {
    Enemy_EnterState(p, p->unk_5a0, 1);
    Enemy_ResetState(p, 0, 0, 5);
    {
      Vec3* dst = p->unk_4a8;
      PathWalker* walker = &p->pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    p->unk_4a8->y = TileHeightAt(p->unk_4a8);
    p->unk_4a8->val = 0;
  }

  {
    u8 angle = p->mover.angle;

    if (!TEST_FLAGS(p->flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS(p->unk_222, ENEMY222_UNK_2)) {
      s32 i;
      u32 a;

      for (i = 0; i <= 3; i++) {
        a = (Random() & 3) << 6;
        if (a != angle) {
          break;
        }
      }
      if (i > 3) {
        a = angle;
      }
      p->unk_540 = a;
      p->unk_548 = p->handlerState;
      p->unk_54f = p->state;
      p->unk_54c = p->subState0;
      p->unk_54d = p->subState1;
      p->unk_54e = p->subState2;
      p->unk_541 = angle;
      Enemy_EnterState(p, p->unk_5bc, 27);
      Enemy_ResetState(p, 3, 1, 0);
      p->unk_542 = 6;
    }
  }
  FUN_080e7b6c(p);
  p->animSpeedDiv = 2;
#else
  INCFUNC("asm/func/FUN_080f12c4.inc");
#endif
}

// 下位状態の経過が 60 を超えたら, 状態14へ移して経路の今のノードへ向かわせ, 着いているかで次の予約を決める
// 残差は273/272命令, 原典は &p->flags を r4 から r7 へ写して最後の flags の書き換えまで持ち越し, 一歩動く部分の失敗側でもう一度 &p->flags3 を作る
// enemy.c の Enemy_StepToward と同じ inline, (p, handler, s0, s1, s2, priority) の予約 inline でここまで寄る, 試済: 最後の flags の落とし方 3通り, 一歩動く部分を早期 return の形に (278)
NON_MATCH void FUN_080f19cc(Enemy* p) {
#ifdef NONMATCHING_C
  if (p->subStateBegun) {
    p->subStateBegun = 0;
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }

  if (p->subStateTimer > 60) {
    WorldPos dst;
    WorldPos* d;
    PathWalker* walker;

    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_8);
    Enemy_SetEmote(p, 0, 2, p->kind);
    Enemy_ResetState(p, 3, 1, 0);
    Enemy_EnterState(p, FUN_080e6794, 14);
    SET_FLAGS(p->flags, ENEFLAG_UNK_4);
    d = &dst;
    walker = &p->pathWalker;
    d->x = walker->node->x;
    d->z = walker->node->y;
    d->y = TileHeightAt(d);
    dst.y = p->mover.pos.y;
    {
      NavAgent* agent = p->navAgent;
      bool8 moved = FALSE;

      if (Map_IsPosInAgentIsland(agent, &p->mover.pos, &dst)) {
        s32 result = FUN_08235f40(agent, &p->mover.pos, &dst);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&p->mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
      }
    }
    p->unk_4a8->val = 1;
    if (!Enemy_IsPosInRect(p, &dst, 32, 32)) {
      CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7);
      p->unk_554 = 30;
      p->unk_558 = p->unk_5a0;
      p->unk_550 = 0;
      p->unk_551 = 0;
      p->unk_552 = 7;
    } else {
      CLEAR_FLAGS(p->flags, ENEFLAG_UNK_4 | ENEFLAG_UNK_6 | ENEFLAG_UNK_7);
      p->unk_554 = 30;
      p->unk_558 = p->unk_5a4;
      p->unk_550 = 0;
      p->unk_551 = 0;
      p->unk_552 = 0;
    }
    p->animSpeedDiv = 1;
  }
  p->subStateTimer++;
#else
  INCFUNC("asm/func/FUN_080f19cc.inc");
#endif
}

// ENEFLAG3_UNK_5 が落ちている間は状態を 0/0/10 に戻してから unk_484 を1つ進める
void FUN_080f1c54(Enemy* p) {
  if (p->subStateBegun != 0) {
    p->subStateBegun = 0;
  }

  if (Enemy_GetFlag3(p, ENEFLAG3_UNK_5) == 0) {
    Enemy_ResetState(p, 0, 0, 10);
  }

  p->subStateTimer++;
}

void FUN_080f1cb8(Enemy* p) {
  if (p->subStateBegun != 0) {
    p->subStateBegun = 0;
  }
  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_1)) {
    p->subStateTimer++;
  }
}

// 巻き戻しの直後にスプライトを画面外 (y = 30000) へ飛ばし, 隠して死亡扱いにする
void FUN_080f1cf0(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_GetSpritePos(p)->y = 30000;
  }
  VEC3_SET(p->mover.pos, 0, 30000, 0);
  Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
  Enemy_ResetState(p, 3, 0, 0);
  Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
  FUN_080e49c4(p);
  Enemy_SetFlag3(p, ENEFLAG3_UNK_6);
  p->subStateTimer++;
}

void FUN_080f1de4(Enemy* p) {
  if (p->subStateBegun != 0) {
    p->subStateBegun = 0;
  }
  p->subStateTimer++;
}

// 巻き戻しの印が立っていたら状態16(入場フラグを食うだけのハンドラ)へ移す
void FUN_080f1e0c(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
  }
  p->subStateTimer++;
}

// 巻き戻しの印が立っていたら unk_5a4 のハンドラへ移し、そうでなければ最初のフレームでデモの待ちを解除する
void FUN_080f1e78(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5a4, 0);
  } else {
    if (p->subStateTimer == 0) {
      MsgQueue_EndWait(&p->mq, 1);
    }
    p->subStateTimer++;
  }
}

// 入場時は状態1へ入り直すだけ, 以降は経路の目標へ歩かせ, 着いたら待ちを解いて下位状態を 2/0/2 にして状態0へ移す
void FUN_080f1ef8(Enemy* p) {
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5a0, 1);
    return;
  }

  Enemy_PlayAnim(p, 1);
  speed = p->unk_588(p);
  Enemy_UpdateWalkAnimSpeed(p);

  if (FUN_080e5ed4(p, p->navAgent, 32, 32, speed)) {
    MsgQueue_EndWait(&p->mq, 1);
    Enemy_ResetState(p, 2, 0, 2);
    Enemy_EnterState(p, p->unk_5a4, 0);
  } else {
    p->subStateTimer++;
  }
}

// 残差6命令 (89/95): begun の 0/1 が分岐に畳まれる
NON_MATCH void FUN_080f2074(Enemy* p) {
#ifdef NONMATCHING_C
  bool8 restart = p->subStateBegun;
  bool32 begun = FALSE;

  if (restart) {
    p->subStateBegun = 0;
    begun = TRUE;
  }
  if (begun) {
    void* handler = p->unk_590;

    p->stateBegun = TRUE;
    p->subStateDone = 0;
    p->state = 1;
    p->handlerState = p->unk_59c;
    p->stateTimer = 0;
  } else if (p->subStateDone) {
    void* handler;

    MsgQueue_EndWait(&p->mq, 1);
    handler = p->unk_5a4;
    p->stateBegun = TRUE;
    p->subStateDone = 0;
    p->state = 0;
    p->handlerState = p->unk_59c;
    p->stateTimer = 0;
    p->subState0 = 2;
    p->subState1 = 0;
    p->subState2 = 2;
    p->subStateTimer = 0;
    p->subStateBegun = 1;
  } else {
    p->subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_080f2074.inc");
#endif
}

// 巻き戻しの直後は状態17へ移り, 下位状態が済んだらデモの待ちを解いて状態16へ移り破棄側へ回す
void FUN_080f2160(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5d0, 17);
  } else if (p->subStateDone) {
    MsgQueue_EndWait(&p->mq, 1);
    Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
    Enemy_ResetState(p, 3, 0, 0);
    Enemy_SetFlag4(p, ENEFLAG4_UNK_12);
  } else {
    p->subStateTimer++;
  }
}

void FUN_080f2254(Enemy* p) {
  u32 idx = p->subState2;
  EnemyHandler* table = p->handlerTables[6];
  table[idx](p);
}

void FUN_080f2278(Enemy* p) {
  u32 idx = p->subState2;
  EnemyHandler* table = p->handlerTables[8];
  table[idx](p);
}

void FUN_080f229c(Enemy* p) {
  u32 idx = p->subState1;
  EnemyHandler* table = p->handlerTables[9];
  table[idx](p);
}

void FUN_080f22c0(Enemy* _) {}

void FUN_080f22c4(Enemy* p) {
  if (!p->unk_608(p)) {
    FUN_080f0a0c(p);
  }
}

void FUN_080f22e8(Enemy* p) {
  u32 idx = p->subState1;
  EnemyHandler* table = p->handlerTables[1];
  table[idx](p);
}

void FUN_080f230c(Enemy* p) {
  u32 idx = p->subState1;
  EnemyHandler* table = p->handlerTables[5];
  table[idx](p);
}

void FUN_080f2330(Enemy* p) {
  if (FUN_080f3718(p)) {
    u32 idx = p->subState1;
    EnemyHandler* table = p->handlerTables[7];
    table[idx](p);
  }
}

// 経路ノードの待ちを数えながら移動し, 下位状態が終わったら次のノードへ進めて下位状態を組み直す
void FUN_080f2364(Enemy* p) {
  PathWalker* walker = p->mover.path;

  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5c0, 5);
    p->nodeWait = walker->node->delay & 0xFFF;
  }

  if (p->nodeWait > 0) {
    p->nodeWait--;
  }

  if (!p->unk_618(p) && p->subStateDone && TEST_FLAGS(p->flags, ENEFLAG_UNK_22)) {
    Map_AdvancePathWalker(walker);
    FUN_080e6204(p);
    if (Map_IsPosOutsidePathNode(walker, &p->mover.pos, 32, 32)) {
      Enemy_ResetState(p, 0, 0, 2);
    } else {
      Enemy_ResetState(p, 0, 0, 0);
    }
  }
}

// 入場時は状態1へ入り直し, 以降は経路の目標へ歩かせる, 経路が終わっていれば着いたところで下位状態を 0/0/0 に, まだなら向きが変われば 0/0/6 に戻す
void FUN_080f248c(Enemy* p) {
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5a0, 1);
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }

  Enemy_PlayAnim(p, 1);
  speed = p->unk_588(p);
  Enemy_UpdateWalkAnimSpeed(p);

  if (!FUN_08235fd8(&p->navAgent->flags)) {
    if (FUN_080e5ed4(p, p->navAgent, 32, 32, speed)) {
      Enemy_ResetState(p, 0, 0, 0);
      return;
    }
  } else if (FUN_080e60b8(p, p->navAgent, 32, 32, speed)) {
    Enemy_ResetState(p, 0, 0, 6);
  }
  p->subStateTimer++;
}

// 状態0の更新, 経路ノードの待ちを数え, 待ち終えたら unk_194 のスクリプトを流して次のノードへ進め, コマンドに応じて次の下位状態を選ぶ
void FUN_080f2644(Enemy* p) {
  Mover* mover = &p->mover;
  PathWalker* walker = &p->pathWalker;
  u32 cmd;

  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5a4, 0);
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }

  cmd = walker->node->command >> 4;
  if (cmd == 1) {
    Enemy_ResetState(p, 0, 0, cmd);
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_5);
    return;
  }

  if (walker->unk_3++ >= (walker->node->delay & 0xFFF)) {
    if (p->unk_194 != 0) {
      u32 argv[3];
      ScriptArgs sa;

      argv[0] = p->pathWalker.nodeIdx;
      argv[1] = p->mover.id;
      argv[2] = p->kind;
      sa.argc = 3;
      sa.argv = argv;
      VM_ExecByID(p->unk_194, &sa);
    }
    Map_AdvancePathWalker(walker);
    FUN_080e6204(p);
    cmd = walker->node->command >> 4;
    if (cmd == 4) {
      p->animSpeedDiv = 2;
      cmd = 2;
    } else {
      p->animSpeedDiv = 1;
      if (cmd == 0) {
        if (Map_IsPosOutsidePathNode(walker, &mover->pos, 32, 32)) {
          Enemy_ResetState(p, 0, 0, 2);
        } else {
          Enemy_ResetState(p, 0, 0, 0);
        }
        return;
      }
    }
    Enemy_ResetState(p, 0, 0, u8_ARRAY_085ad468[cmd]);
    return;
  }
  p->subStateTimer++;
}

// 状態2の更新, 経路ノードの待ちを数え, 待ち終えたらノードのコマンドに応じて次の下位状態を選ぶ
void FUN_080f2864(Enemy* p) {
  Mover* mover = &p->mover;
  PathWalker* walker = &p->pathWalker;

  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_590, 2);
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }

  if (p->subStateDone) {
    Enemy_SetFlag2(p, ENEFLAG2_UNK_5);
  }
  if (Enemy_GetFlag2(p, ENEFLAG2_UNK_5)) {
    if (walker->unk_3++ >= (walker->node->delay & 0xFFF)) {
      u32 cmd = walker->node->command >> 4;

      if (u8_ARRAY_085ad468[cmd] == 1) {
        Enemy_ClearFlag2(p, ENEFLAG2_UNK_5);
        Map_AdvancePathWalker(walker);
        FUN_080e6204(p);
        cmd = walker->node->command >> 4;
      }
      if (cmd == 4) {
        p->animSpeedDiv = 2;
        cmd = 2;
      } else {
        p->animSpeedDiv = 1;
        if (cmd == 0) {
          if (Map_IsPosOutsidePathNode(walker, &mover->pos, 32, 32) == TRUE) {
            Enemy_ResetState(p, 0, 0, 2);
          } else {
            Enemy_ResetState(p, 0, 0, 0);
          }
          return;
        }
      }
      Enemy_ResetState(p, 0, 0, u8_ARRAY_085ad468[cmd]);
      return;
    }
  }
  p->subStateTimer++;
}

// 経路の目標へ歩かせる, 経路が終わっていなければ向きが変わったところで 0/0/6 に, 終わっていれば着いたところで目標の有無で 0/0/2 か 0/0/5 にして状態0へ移す
void FUN_080f2a40(Enemy* p) {
  s32 speed;

  if (p->subStateBegun) {
    p->subStateBegun = 0;
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }

  Enemy_PlayAnim(p, 1);
  speed = p->unk_588(p);
  Enemy_UpdateWalkAnimSpeed(p);

  if (FUN_08235fd8(&p->navAgent->flags)) {
    if (FUN_080e60b8(p, p->navAgent, 32, 32, speed)) {
      Enemy_ResetState(p, 0, 0, 6);
      Enemy_EnterState(p, p->unk_5a4, 0);
    }
  } else if (FUN_080e5ed4(p, p->navAgent, 32, 32, speed)) {
    p->unk_202 = 0;
    if (p->unk_4a8->val != 0) {
      Enemy_ResetState(p, 0, 0, 2);
      FUN_080e6204(p);
      Enemy_ClearUnk21Flags(p);
      p->animSpeedDiv = 1;
      ClearMemory(p->unk_4a8, 8);
    } else {
      Enemy_ResetState(p, 0, 0, 5);
    }
    Enemy_EnterState(p, p->unk_5a4, 0);
    return;
  }
  p->subStateTimer++;
}

// 状態2の更新, 下位状態が終わったら ENEFLAG3_UNK_4 なら状態19へ, そうでなければ ENEFLAG_UNK_4 で下位状態を選んで状態1へ移す
void FUN_080f2d04(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_590, 2);
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }

  if (p->subStateDone) {
    if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_4)) {
      Enemy_ResetState(p, 0, 0, 8);
      Enemy_EnterState(p, p->unk_5a8, 19);
    } else {
      if (TEST_FLAGS(p->flags, ENEFLAG_UNK_4)) {
        Enemy_ResetState(p, 0, 0, 7);
      } else {
        Enemy_ResetState(p, 0, 0, 2);
      }
      Enemy_EnterState(p, p->unk_5a0, 1);
    }
  } else {
    p->subStateTimer++;
  }
}

// 状態0の待機, 攻撃対象に近づいていれば状態25へ, 30 で感情アイコンを出し, 60 を超えたら経路の今のノードへ向かって状態1へ移す
// 残差は327/330命令, 原典は最初の flags3 の検査で作った &p->flags3 を r8 に持って以降の flags3 の読み書きすべてに使い, 30 のときの unk_5f0 呼び出しをその場に置く
// 試済: 一歩動く部分を Enemy_StepToward 形の inline にする (322), Vec3_Diff は EnemyTarget* を先に取ると揃う
NON_MATCH void FUN_080f2ec0(Enemy* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5a4, 0);
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_7);
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    p->animSpeedDiv = 1;
  }
  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }

  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
    EnemyTarget* target = p->target;
    Vec3 d;
    Vec3* dst = &d;
    WorldPos* pos = &p->mover.pos;

    Vec3_Diff(dst, &target->owner->pos, pos);
    if ((u32)(d.x * d.x + d.z * d.z) < 0xFFFF) {
      Enemy_EnterState(p, p->unk_5e8, 25);
      Enemy_ResetState(p, 3, 1, 0);
      return;
    }
  }

  if (p->subStateTimer == 30) {
    Enemy_SetEmote(p, 0, 2, p->kind);
    if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
      p->unk_5f0(p);
      return;
    }
  }

  if (p->subStateTimer > 60) {
    bool8 moved;

    Enemy_ResetState(p, 0, 0, 7);
    Enemy_EnterState(p, p->unk_5a0, 1);
    p->unk_4a8->val = 1;
    moved = FALSE;
    {
      NavAgent* agent = p->navAgent;
      WorldPos* pos = &p->mover.pos;
      Vec3* dst = p->unk_4a8;

      if (Map_IsPosInAgentIsland(agent, pos, dst)) {
        s32 result = FUN_08235f40(agent, pos, dst);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&p->mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      p->unk_5c4(p);
      return;
    }
    if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
      p->unk_21c = 0;
      p->unk_21e = 0;
      p->unk_202 = 0;
    }
    return;
  }
  p->subStateTimer++;
#else
  INCFUNC("asm/func/FUN_080f2ec0.inc");
#endif
}

// 経路の目標へ歩かせる, 経路が終わっていなければ向きが変わったところで下位状態を 0/0/6 に, 終わっていれば着いたところで状態19へ移して次の行き先を選ぶ
// 残差は223/223命令, 原典は gRandomTable を r3 に読み (こちらは r1), node の計算で gCollisionMap->paths を walker->path より先に読む
// 試済: u16* table + _Random (table の読みが先頭へ上がる), Map_GetPathNodes 相当の inline, 乱数でノードを選ぶ部分の inline, 足し算の順序の入れ替え
NON_MATCH void FUN_080f31c4(Enemy* p) {
#ifdef NONMATCHING_C
  s32 speed;

  if (p->subStateBegun) {
    p->subStateBegun = 0;
  }
  speed = p->unk_588(p);
  Enemy_UpdateWalkAnimSpeed(p);

  if (FUN_08235fd8(&p->navAgent->flags)) {
    if (FUN_080e60b8(p, p->navAgent, 32, 32, speed)) {
      Enemy_ResetState(p, 0, 0, 6);
    }
  } else if (FUN_080e5ed4(p, p->navAgent, 32, 32, speed)) {
    Enemy_ResetState(p, 0, 0, 8);
    Enemy_EnterState(p, p->unk_5a8, 19);
    if (IsLinkPlay()) {
      if (!FUN_080fa7a4(p)) {
        FUN_080faad8(p);
      }
    } else {
      PathWalker* walker = p->mover.path;
      u8 next = Mod(Random() >> 3, walker->path->nodeCount);

      if (next == walker->nodeIdx) {
        next = Mod(next + 1, walker->path->nodeCount);
      }
      walker->nodeIdx = next;
      walker->unk_3 = 0;
      walker->node = (PathNode*)((u8*)gCollisionMap->paths + walker->path->nodeOffset) + walker->nodeIdx;
      FUN_080e6204(p);
    }
    return;
  }
  p->subStateTimer++;
#else
  INCFUNC("asm/func/FUN_080f31c4.inc");
#endif
}

void FUN_080f33e8(Enemy* p) {
  if (Enemy_ConsumeSubStateBegun(p)) {
    Enemy_EnterState(p, p->unk_5a4, 0);
  }

  if (p->unk_608(p)) {
    return;
  }
  if (FUN_080f0a0c(p)) {
    return;
  }
  if (p->subStateTimer > 0x3B) {
    Enemy_ResetState(p, 0, 0, 2);
  } else {
    p->subStateTimer++;
  }
}

void FUN_080f34a0(Enemy* p) {
  if (p->subStateBegun != 0) {
    p->subStateBegun = 0;
  }
  if (!p->unk_608(p)) {
    if (FUN_080f0a0c(p) == 0) {
      p->subStateTimer++;
    }
  }
}

// ゲームオーバー中なら状態を 2/0/1 に戻し、そうでなければ handlerTables[2] を回す
void FUN_080f34ec(Enemy* p) {
  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), FLAG030047A4_GAMEOVER) || TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    Enemy_ResetState(p, 2, 0, 1);
  } else {
    u32 idx = p->subState2;
    EnemyHandler* table = p->handlerTables[2];
    table[idx](p);
  }
}

// ゲームオーバー中なら状態を 2/0/1 に戻し、そうでなければ handlerTables[4] を回す
void FUN_080f3574(Enemy* p) {
  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), FLAG030047A4_GAMEOVER) || TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    Enemy_ResetState(p, 2, 0, 1);
  } else {
    u32 idx = p->subState2;
    EnemyHandler* table = p->handlerTables[4];
    table[idx](p);
  }
}

// ゲームオーバー中なら状態を 2/0/1 に戻し、そうでなければ handlerTables[3] を回す
void FUN_080f35fc(Enemy* p) {
  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), FLAG030047A4_GAMEOVER) || TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    Enemy_ResetState(p, 2, 0, 1);
  } else {
    u32 idx = p->subState2;
    EnemyHandler* table = p->handlerTables[3];
    table[idx](p);
  }
}

// 状態ごとのハンドラ表を10本割り当てる
void Enemy_InitHandlerTables(Enemy* p) {
  p->handlerTables[0] = (void*)gEnemyHandlerTable0;
  p->handlerTables[1] = (void*)gEnemyHandlerTable1;
  p->handlerTables[2] = (void*)gEnemyHandlerTable2;
  p->handlerTables[3] = (void*)gEnemyHandlerTable3;
  p->handlerTables[4] = (void*)gEnemyHandlerTable4;
  p->handlerTables[5] = (void*)gEnemyHandlerTable5;
  p->handlerTables[6] = (void*)gEnemyHandlerTable6;
  p->handlerTables[7] = (void*)gEnemyHandlerTable7;
  p->handlerTables[8] = (void*)gEnemyHandlerTable8;
  p->handlerTables[9] = (void*)gEnemyHandlerTable9;
}

// ENEFLAG5_UNK_8 が立っている間, 受け口に溜まったデモのメッセージを処理する (移動先の指定, 向き直り, エモート, 他の敵への中継など)
// 中継の payload は u16[2] で, cmd 6 は payload[2] まで書く (原典のはみ出し, 隣の x のスロットに乗る), 向きは FixToInt(5, angle) で符号付きの割り算になる
// flags5 の判定を bool8 を返す static inline にすると 569/567 命令, 残差は gMsgBus のプール定数をループ内で読み直さない点と, cmd 5〜7 で &p->kind を先に作らないぶん末尾の FUN_080ec848 呼び出しが1つに畳まれない点
NON_MATCH bool8 FUN_080f3718(Enemy* p) {
#ifdef NONMATCHING_C
  MsgQueue* mq;
  s32 i;
  u16 payload[2];
  s32 x;
  s32 y;

  if (!TEST_FLAGS(p->flags5, ENEFLAG5_UNK_8)) {
    return FALSE;
  }

  mq = &p->mq;
  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgBus* bus = gMsgBus;
    MsgPacket* msg = mq->msgs[bus->bufIdx][i];

    switch (msg->cmd) {
      case 0: {
        p->navAgent->unk_1c.x = msg->args[0];
        p->navAgent->unk_1c.y = msg->args[1];
        p->navAgent->unk_1c.z = msg->args[2];
        p->animSpeedDiv = msg->args[3];
        if (msg->args[4] != 0) {
          SET_FLAGS(p->flags3, ENEFLAG3_UNK_9);
        } else {
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
        }
        p->navAgent->unk_0c = p->navAgent->unk_1c;
        Enemy_ResetState(p, 2, 0, 3);
        Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
        break;
      }
      case 1: {
        s32 dir = (FixToInt(5, p->mover.angle) + 3) & 7;
        s32 diff = abs(msg->args[0] - dir);

        if (p->kind == ENEK_GHOST) {
          if (diff != 0) {
            p->unk_1dc = ((msg->args[0] + 5) & 7) << 5;
            Enemy_ResetState(p, 2, 0, 4);
            Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
            break;
          }
        } else {
          if (diff > 1) {
            p->unk_1dc = msg->args[0];
            Enemy_ResetState(p, 2, 0, 4);
            Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
            break;
          }
        }
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
      case 2: {
        p->mover.angle = ((msg->args[0] + 5) & 7) << 5;
        Enemy_ResetState(p, 2, 0, 2);
        Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
        break;
      }
      case 4: {
        Enemy_ResetState(p, 2, 0, 5);
        Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
        break;
      }
      case 5: {
        payload[0] = 6;
        FUN_080ec848(p->kind, payload, p->mover.id);
        break;
      }
      case 6: {
        payload[0] = 6;
        payload[1] = msg->args[0];
        payload[2] = msg->args[1];
        FUN_080ec848(p->kind, payload, p->mover.id);
        break;
      }
      case 7: {
        payload[0] = 7;
        FUN_080ec848(p->kind, payload, p->mover.id);
        break;
      }
      case 3: {
        switch (msg->args[0]) {
          case 1:
          case 2: {
            Enemy_SetEmote(p, 0, 0, p->kind);
            break;
          }
          case 0: {
            Enemy_SetEmote(p, 0, 1, p->kind);
            break;
          }
          case 3: {
            Enemy_SetEmote(p, 0, 2, p->kind);
            break;
          }
          case 4: {
            p->unk_192 = msg->args[1];
            p->unk_190 = msg->args[2];
            FUN_080e5610(p->kind, 1, &x, &y);
            p->emote = FUN_080d9cec(0, &p->mover.pos, p->mover.id, x, y, p->kind, &p->unk_192, p->unk_190, 0, p, &p->mover);
            break;
          }
          case 5: {
            s32 variant;

            p->unk_192 = msg->args[1];
            p->unk_190 = msg->args[2];
            variant = msg->args[3];
            FUN_080e5610(p->kind, 3, &x, &y);
            p->emote = FUN_080da6c4(7, &p->mover.pos, p->mover.id, y, 0, &p->unk_192, p->unk_190, variant, &p->mover, p);
            break;
          }
          case 6: {
            FUN_080e5610(p->kind, 1, &x, &y);
            p->emote = Emote_Show(p->emote, &p->mover, EMOTE_5, 0, NULL, 0, y, x);
            break;
          }
          case 7: {
            FUN_080e5610(p->kind, 1, &x, &y);
            p->emote = Emote_Show(p->emote, &p->mover, EMOTE_4, 0, NULL, 0, y, x);
            break;
          }
          case 8: {
            p->emote = Emote_Remove(p->emote, 0, p->mover.id);
            p->emote = Emote_Remove(p->emote, 1, p->mover.id);
            p->emote = Emote_Remove(p->emote, 2, p->mover.id);
            p->emote = Emote_Remove(p->emote, 4, p->mover.id);
            p->emote = Emote_Remove(p->emote, 5, p->mover.id);
            p->emote = Emote_RemovePtcl(p->emote, 3, p->mover.id);
            break;
          }
        }
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
    }
    MsgQueue_BeginWait(mq, msg);
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080f3718.inc");
#endif
}

// state に入った最初のフレームだけ11番のアニメを鳴らす
void FUN_080f3cdc(Enemy* p) {
  if (Enemy_ConsumeStateBegun(p)) {
    Enemy_PlayAnim(p, 0xB);
  }
  if (p->animForceRestart != 0) {
    p->subStateDone = 1;
  }
}

// 入場時に判定と影を出し直し, ENEFLAG2_UNK_4 が立っていれば経路の今のノードへ一歩動いて状態14へ, 動けなければ状態0へ, 体力が1以下なら状態17へ移る
// 一歩動く処理を bool8 を返す static inline (agent, pos, dst = p->unk_4a8 の順に取り, !island 側で先に片付けて return する2重の片付け形) にし, unk_550〜unk_558 を (p, handler, s0, s1, s2, priority) の inline で書くと 418/421 命令まで寄る
// 残差は &p->flags をレジスタ (r8) に持ち越して呼び出しをまたぐ形で, 入場処理の CLEAR(UNK_22) と経路処理後の SET(UNK_4) がアドレスを作り直す
NON_MATCH void UNUSED FUN_080f3d28(Enemy* p) {
#ifdef NONMATCHING_C
  bool8 moved;

  if (Enemy_ConsumeStateBegun(p)) {
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    FUN_080efc44(p, 3, 1);
    p->hitbox.flags |= HBFLAG_HIDDEN;
    p->hitbox.invincibleTime = 0;
    Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
    p->unk_192 = 0;
    Enemy_SetSpritePriority(p, 2);
    ParticleShadow_Show(&p->shadow);
    CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_19);
    CLEAR_FLAGS(p->flags5, ENEFLAG5_UNK_5);
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_22);
  }

  if (!TEST_FLAGS(p->flags2, ENEFLAG2_UNK_4)) {
    return;
  }
  if (p->hp <= 1) {
    p->hp = 0;
    SET_FLAGS(p->flags3, ENEFLAG3_UNK_3);
    Enemy_EnterState(p, p->unk_5d0, 17);
    Enemy_ResetState(p, 3, 0, 0);
    return;
  }

  SET_FLAGS(p->flags, ENEFLAG_UNK_22);
  CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_2);
  p->hitbox.flags &= ~HBFLAG_HIDDEN;
  {
    Vec3* dst = p->unk_4a8;
    PathWalker* walker = &p->pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  moved = FALSE;
  {
    NavAgent* agent = p->navAgent;
    WorldPos* pos = &p->mover.pos;
    Vec3* dst = p->unk_4a8;

    if (Map_IsPosInAgentIsland(agent, pos, dst)) {
      s32 result = FUN_08235f40(agent, pos, dst);

      if (result != 0) {
        if (result != 2) {
          ClearMemory(&p->mover.delta, 8);
        }
        moved = TRUE;
      }
    }
    if (!moved) {
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    }
  }
  if (!moved) {
    Enemy_EnterState(p, Enemy_ClearStateBegun, 0);
    Enemy_ResetState(p, 3, 0, 0);
    return;
  }

  p->unk_4a8->val = 1;
  Enemy_ResetState(p, 3, 1, 0);
  Enemy_EnterState(p, FUN_080e6794, 14);
  SET_FLAGS(p->flags, ENEFLAG_UNK_4);
  p->animSpeedDiv = 1;
  p->unk_554 = 30;
  p->unk_558 = p->unk_5a0;
  p->unk_550 = 0;
  p->unk_551 = 0;
  p->unk_552 = 7;
#else
  INCFUNC("asm/func/FUN_080f3d28.inc");
#endif
}

// 状態に入った最初のフレームだけ, 判定を隠して煙を6方向に出し, 断末魔とスクリプトを流して魔物図鑑の出会ったフラグを立て, 状態16へ移す
// 煙を (p, count, size, angle) の static inline で出すと count が &p->mover.pos より先に計算され, PlayEnemyDeathCry と種族3の判定を static inline にくくると種族3の判定がアドレスを作り直す, ここまでで 449/448 命令
// 残差は p->kind のアドレスで, 原典は最初の種族判定のアドレスを r4 に写して EnemyDex_GetEntryIdx の引数まで持ち越すが, こちらは作り直す
NON_MATCH void FUN_080f410c(Enemy* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(p)) {
    Vec3 size;
    s32 idx;

    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    p->hitbox.flags |= HBFLAG_HIDDEN;
    p->hitbox.invincibleTime = 0;
    p->unk_192 = 0;
    Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
    Enemy_ClearSpriteFlags(p, SPRFLAG_AFFINE);
    p->unk_192 = 0;
    Enemy_SetSpritePriority(p, 2);
    size.x = 0x50, size.y = 0x3C, size.z = 0x3C;
    EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
    EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0x40, 4, 20, 2, 1);
    EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
    EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0x80, 4, 20, 2, 1);
    EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
    EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0xF0, 4, 20, 2, 1);
    if (p->kind == ENEK_BOKU || p->kind == ENEK_MUMMY || p->kind == ENEK_SKELETON || p->kind == ENEK_SKELETON_A || p->kind == ENEK_SKELETON_F || p->kind == ENEK_DARKROOT) {
      PlaySound_082406e0(SONG_229);
    }
    PlayEnemyDeathCry(p);
    if (p->kind == ENEK_GOLEM) {
      FUN_080f8ae0(p);
    }
    if (p->unk_19a != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = p->mover.pos.x;
      argv[1] = p->mover.pos.y;
      argv[2] = p->mover.pos.z;
      argv[3] = p->unk_19c;
      argv[4] = p->unk_1a0;
      argv[5] = p->unk_1a4;
      argv[6] = p->unk_4a0;
      argv[7] = p->mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID(p->unk_19a, &sa);
    }
    idx = EnemyDex_GetEntryIdx(p->kind, p->variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
    Enemy_ResetState(p, 1, 0, 2);
    if (!IsLinkPlay() && !TEST_FLAGS(p->flags2, ENEFLAG2_UNK_11)) {
      FUN_080ec5b4(gMapInitScriptID, p->mover.id);
    }
    ParticleShadow_Hide(&p->shadow);
  }
#else
  INCFUNC("asm/func/FUN_080f410c.inc");
#endif
}

// 状態に入った最初のフレームだけ, 種族ごとの音を鳴らして当たり判定と影を隠し, スプライトを最前面にして下位状態を 3/0/0 に戻す
void FUN_080f44f4(Enemy* p) {
  if (Enemy_ConsumeStateBegun(p)) {
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    FUN_080efc44(p, 3, 1);
    switch (p->kind) {
      case ENEK_BOKU:
      case ENEK_28: {
        PlaySound_082406e0(CRY_BOKU_DAMAGED);
        break;
      }
      case ENEK_MUMMY: {
        PlaySound_082406e0(CRY_MUMMY_DAMAGED);
        break;
      }
      case ENEK_GOLEM:
      case ENEK_30: {
        FUN_080e81dc(p, 1);
        break;
      }
    }
    p->hitbox.flags |= HBFLAG_HIDDEN;
    p->hitbox.invincibleTime = 0;
    Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
    Enemy_ResetState(p, 3, 0, 0);
    p->unk_192 = 0;
    Enemy_SetSpritePriority(p, 3);
    Enemy_SetFlag2(p, ENEFLAG2_UNK_19);
    ParticleShadow_Hide(&p->shadow);
  }
}

// 状態に入った最初のフレームだけ, 種族ごとの音を鳴らして3番のアニメに切り替え, 下位状態を 3/0/0 に戻す
void FUN_080f46a4(Enemy* p) {
  if (Enemy_ConsumeStateBegun(p)) {
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    Enemy_PlayAnim(p, 3);
    switch (p->kind) {
      case ENEK_BOKU: {
        PlaySound_082406e0(CRY_BOKU_DAMAGED);
        break;
      }
      case ENEK_MUMMY: {
        PlaySound_082406e0(CRY_MUMMY_DAMAGED);
        break;
      }
      case ENEK_GOLEM: {
        FUN_080e81dc(p, 1);
        break;
      }
      case ENEK_SKELETON:
      case ENEK_SKELETON_F:
      case ENEK_SKELETON_A: {
        PlaySound_082406e0(SE_ENEMY_DAMAGED);
        break;
      }
    }
    p->hitbox.invincibleTime = 0;
    Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
    Enemy_ResetState(p, 3, 0, 0);
    p->unk_192 = 0;
  }
}

// 残差4命令 (98/102): begun の 0/1 が分岐に畳まれる
// 残りは ENEFLAG2_UNK_4 のマスク 0x10 の materialize 位置で, diamond が合えば追随する見込み
// stateBegun の判定を bool8 を返す static inline (Enemy_ConsumeStateBegun) にすると 0/1 の作り置きは出る, unk_550〜unk_558 の5つをまとめて書く inline も通すと 101/102 まで寄る
NON_MATCH void FUN_080f47c8(Enemy* p) {
#ifdef NONMATCHING_C
  bool8 stateBegun = p->stateBegun;
  bool32 begun = FALSE;

  if (stateBegun) {
    p->stateBegun = FALSE;
    begun = TRUE;
  }
  if (begun) {
    p->mover.angle = ((p->mover.angle + 0x80) & 0xFF) >> 6 << 6;
    Enemy_PlayAnim(p, 0);
  }

  if (p->flags2 & ENEFLAG2_UNK_4) {
    p->flags |= ENEFLAG_UNK_4;
    p->unk_554 = 0x1E;
    p->unk_558 = FUN_080f3cdc;
    p->unk_550 = 0;
    p->unk_551 = 1;
    p->unk_552 = 1;
    p->stateBegun = TRUE;
    p->subStateDone = 0;
    p->state = 14;
    p->handlerState = FUN_080e6794;
    p->stateTimer = 0;
    p->subState0 = 3;
    p->subState1 = 1;
    p->subState2 = 0;
    p->subStateTimer = 0;
    p->subStateBegun = 1;
    p->animSpeedDiv = 1;
  }
#else
  INCFUNC("asm/func/FUN_080f47c8.inc");
#endif
}

// Entity5941 から届く通知, 0 = 攻撃が当たった (状態31へ移し, 状態フラグに応じて追跡や警戒を解き, 被ダメージ値を控える), 1 = 吹き飛ばし開始 (向きと value から跳ねる速さを作って状態32へ)
// 残差は 1006/1000 命令で, 同じ形の後始末 (ENEFLAG_UNK_21 の片付け, UNK_10 を落として unk_542 = 0xFF) が何度も出てくる区間のレジスタ割当とアドレスの持ち越しがずれる
// 原典は E 節 (ENEFLAG3_UNK_4) で -1 をスタックの1バイトに置いて2度目の unk_542 に OR で書くが, SET_FLAGS(p->unk_542, 0xFF) ではフレームが 0x10 になって再現しない
NON_MATCH bool32 FUN_080f48ac(Mover* mover, s32 msg, s32 value) {
#ifdef NONMATCHING_C
  Enemy* p = mover->owner;

  switch (msg) {
    case 0: {
      if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_15)) {
        goto done;
      }
      Hitbox_SetFlags(&p->atkHitbox, HBFLAG_HIDDEN);
      Hitbox_SetFlags(&p->hitbox, HBFLAG_HIDDEN);
      Enemy_EnterState(p, FUN_080f46a4, 31);
      Enemy_ResetState(p, 3, 0, 0);
      SET_FLAGS(p->flags3, ENEFLAG3_UNK_15);
      if (p->flags3 == 0) {
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_13);
        goto done;
      }

      if (Enemy_IsDead(p)) {
        if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
          EnemyTargetManager_Release(p->target);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
          p->target = NULL;
        }
        if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
          Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
          p->unk_21c = 0;
          p->unk_21e = 0;
          p->unk_202 = 0;
        }
        p->flags3 = ENEFLAG3_UNK_6;
        p->unk_48c = 0;
        CLEAR_FLAGS(p->flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
        goto done;
      }

      if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_13)) {
        p->animSpeedDiv = 1;
        p->unk_222 = 0;
        p->unk_24e = 0;
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
        if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
          Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
          p->unk_21c = 0;
          p->unk_21e = 0;
          p->unk_202 = 0;
        }
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
        p->unk_542 = 0xFF;
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26);
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_8 | ENEFLAG3_UNK_10);
        SET_FLAGS(p->flags4, ENEFLAG4_UNK_10);
        p->animSpeedDiv = 1;
        CLEAR_FLAGS(p->flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
      } else if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_2)) {
        p->animSpeedDiv = 1;
        p->unk_222 = 0;
        p->unk_24e = 0;
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
        if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
          Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
          p->unk_21c = 0;
          p->unk_21e = 0;
          p->unk_202 = 0;
        }
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
        p->unk_542 = 0xFF;
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26);
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_8 | ENEFLAG3_UNK_10 | ENEFLAG3_UNK_13);
        SET_FLAGS(p->flags4, ENEFLAG4_UNK_10);
        p->animSpeedDiv = 1;
        CLEAR_FLAGS(p->flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
        SET_FLAGS(p->flags, ENEFLAG_UNK_13);
      } else if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_1)) {
        p->animSpeedDiv = 1;
        p->unk_222 = 0;
        p->unk_24e = 0;
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
        if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
          Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
          p->unk_21c = 0;
          p->unk_21e = 0;
          p->unk_202 = 0;
        }
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
        p->unk_542 = 0xFF;
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26);
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_8 | ENEFLAG3_UNK_10 | ENEFLAG3_UNK_13);
        SET_FLAGS(p->flags4, ENEFLAG4_UNK_10);
        CLEAR_FLAGS(p->flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
      } else if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_15)) {
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_8 | ENEFLAG3_UNK_10 | ENEFLAG3_UNK_13);
        SET_FLAGS(p->flags4, ENEFLAG4_UNK_10);
        CLEAR_FLAGS(p->flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
      } else if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_4)) {
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
        p->unk_21e = 0;
        p->unk_220 = 0;
        p->unk_202 = 0;
        p->animSpeedDiv = 1;
        p->unk_222 = 0;
        p->unk_24e = 0;
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
        if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
          Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
          p->unk_21c = 0;
          p->unk_21e = 0;
          p->unk_202 = 0;
        }
        p->flags3 &= ~ENEFLAG3_UNK_10;
        p->unk_542 = 0xFF;
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_8 | ENEFLAG3_UNK_10 | ENEFLAG3_UNK_13);
        p->unk_192 = 0;
        p->animSpeedDiv = 6;
        if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
          EnemyTargetManager_Release(p->target);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
          p->target = NULL;
        }
        if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
          Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
          p->unk_21c = 0;
          p->unk_21e = 0;
          p->unk_202 = 0;
        }
        p->flags3 &= ~ENEFLAG3_UNK_10;
        p->unk_542 = 0xFF;
        SET_FLAGS(p->flags4, ENEFLAG4_UNK_10);
        CLEAR_FLAGS(p->flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
      }

      if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_15)) {
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_9);
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_14 | ENEFLAG_UNK_27);
        if (!TEST_FLAGS(p->flags3, ENEFLAG3_UNK_5)) {
          CLEAR_FLAGS(p->flags, ENEFLAG_UNK_7);
        }
        CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_2 | ENEFLAG2_UNK_20);
        if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
          EnemyTargetManager_Release(p->target);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
          p->target = NULL;
        }
        if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
          Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
          p->unk_21c = 0;
          p->unk_21e = 0;
          p->unk_202 = 0;
        }
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
        p->unk_542 = 0xFF;
        SET_FLAGS(p->flags4, ENEFLAG4_UNK_10);
        p->unk_48c = 0;
        if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_4)) {
          CLEAR_FLAGS(p->flags, ENEFLAG_UNK_13);
        } else {
          SET_FLAGS(p->flags, ENEFLAG_UNK_13);
        }
      } else {
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_13);
      }

      if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_10)) {
        if ((s8)p->unk_542 < 0 || (p->state != 27 && p->state != 2)) {
          p->unk_542 = 0xFF;
          CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
        }
      }

      if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_7)) {
        if (p->kind == ENEK_DOG) {
          p->animSpeedDiv = 2;
        } else if (p->kind >= ENEK_SKELETON && p->kind <= ENEK_SKELETON_A) {
          p->animSpeedDiv = 2;
        } else {
          p->animSpeedDiv = 3;
        }
      } else if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_9 | ENEFLAG3_UNK_12)) {
        if (p->kind == ENEK_DOG) {
          p->animSpeedDiv = 2;
        } else if (p->kind >= ENEK_SKELETON && p->kind <= ENEK_SKELETON_A) {
          p->animSpeedDiv = 2;
        } else {
          p->animSpeedDiv = 3;
        }
      } else {
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
        p->unk_222 = 0;
        p->unk_542 = 0xFF;
        p->unk_540 = 0;
        p->unk_541 = 0;
      }

    done:
      p->hitbox.knockbackPower = 0;
      if (value != 0) {
        p->unk_48a = value;
        p->unk_48c = 1;
        p->unk_4a0 = 1;
        p->flags6 = 0;
        p->weaponExpMask = 0;
        SET_FLAGS(p->flags4, ENEFLAG4_UNK_5);
      } else {
        p->unk_48a = value;
        p->unk_48c = 0;
        p->unk_4a0 = value;
        p->flags6 = value;
        p->weaponExpMask = value;
      }
      break;
    }
    case 1: {
      Hitbox_ClearFlags(&p->atkHitbox, HBFLAG_HIDDEN);
      Hitbox_ClearFlags(&p->hitbox, HBFLAG_HIDDEN);
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_15);
      {
        Vec3* vel = &p->jumpVel;
        u8 angle = p->mover.angle;

        VEC3_SET(*vel, POLAR_X(value, angle), 0, POLAR_Z(value, angle));
      }
      p->jumpVel.y = 4;
      Enemy_ResetState(p, 3, 0, 0);
      Enemy_EnterState(p, p->unk_5ec, 32);
      break;
    }
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080f48ac.inc");
#endif
}

// 状態23 (倒されて消える) の入場処理, 判定と印を片付けて unk_19a のスクリプトを流し, 魔物図鑑の出会ったフラグを立てて状態16へ移す
void FUN_080f5208(Enemy* p) {
  if (Enemy_ConsumeStateBegun(p)) {
    s32 idx;

    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
    Enemy_SetEmote(p, 0, 0x7F, 0);
    Enemy_SetEmote(p, 1, 0x7F, 0);
    Enemy_SetEmote(p, 3, 0x7F, 0);
    FUN_080e64b4(p, 4);
    p->subStateDone = 1;
    if (p->unk_19a != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = p->mover.pos.x;
      argv[1] = p->mover.pos.y;
      argv[2] = p->mover.pos.z;
      argv[3] = p->unk_19c;
      argv[4] = p->unk_1a0;
      argv[5] = p->unk_1a4;
      argv[6] = p->unk_4a0;
      argv[7] = p->mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID(p->unk_19a, &sa);
    }
    idx = EnemyDex_GetEntryIdx(p->kind, p->variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    p->unk_192 = 0;
    Enemy_EnterState(p, Enemy_ClearStateBegun, 16);
    Enemy_ResetState(p, 1, 0, 2);
    if (!IsLinkPlay() && !TEST_FLAGS(p->flags2, ENEFLAG2_UNK_11)) {
      FUN_080ec5b4(gMapInitScriptID, p->mover.id);
    }
    ParticleShadow_Hide(&p->shadow);
    switch (p->kind) {
      case ENEK_BOKU:
      case ENEK_28: {
        PlaySound_082406e0(CRY_BOKU_DAMAGED);
        break;
      }
      case ENEK_MUMMY: {
        PlaySound_082406e0(CRY_MUMMY_DAMAGED);
        break;
      }
      case ENEK_GOLEM:
      case ENEK_30: {
        FUN_080e81dc(p, 1);
        break;
      }
      case ENEK_COCKA:
      case ENEK_MIMIC: {
        PlaySound_082406e0(SE_ENEMY_DAMAGED);
        break;
      }
      case ENEK_DOG: {
        PlaySound_082406e0(SE_ENEMY_DAMAGED);
        break;
      }
    }
  }
}

// 入場時に判定と下位状態を片付け, param_2 が 6 を超えた分だけ沈めて, 8 を超えたら hp を 0 にして状態23へ移して隠す
void FUN_080f54e4(Enemy* p, s32 param_2) {
  if (Enemy_ConsumeStateBegun(p)) {
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    Enemy_PlayAnim(p, 3);
    if (p->kind != ENEK_SPIDER && p->kind != ENEK_SLIME) {
      Enemy_SetEmote(p, 0, 1, p->kind);
    }
    p->hitbox.flags |= HBFLAG_HIDDEN;
    Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
    Enemy_ResetState(p, 3, 0, 0);
    p->unk_192 = 0;
    p->animForceRestart = FALSE;
    p->hitbox.invincibleTime = 0;
    p->unk_4be = 0;
    Enemy_SetFlag2(p, ENEFLAG2_UNK_17);
  }

  if (param_2 <= 6) {
    return;
  }
  p->mover.pos.y -= (param_2 - 6) * 30;
  Enemy_SyncSpritePos(p);

  if (param_2 <= 8) {
    return;
  }
  p->hp = 0;
  Enemy_SetFlag3(p, ENEFLAG3_UNK_3);
  Enemy_SetFlag(p, ENEFLAG_UNK_10);
  Enemy_SetEmote(p, 0, 0x7F, 0);
  Enemy_SetEmote(p, 1, 0x7F, 0);
  Enemy_SetEmote(p, 3, 0x7F, 0);
  FUN_080e64b4(p, 4);
  Enemy_EnterState(p, FUN_080f5208, 23);
  Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
}

// 押し戻されている間の状態, 入場時に向きを4方向へ丸めて警戒を解き, 毎フレーム unk_20c と unk_214 の差の 1/4 (±200 まで) だけ押し戻し, 止まって unk_192 が尽きたら状態8へ移る
// &p->flags2 をポインタのローカルに取ると 447/447 命令, 押し戻し量が 0 かの判定を bool8 を返す static inline にすると末尾の 0/1 の作り置きも揃う
// 残差は入場処理で &p->unk_21e / &p->unk_202 などのアドレスを分岐の前に作ってレジスタに持ち越す形 (原典) が出ず, こちらは使うたびに作り直す
NON_MATCH void FUN_080f56ec(Enemy* p) {
#ifdef NONMATCHING_C
  s32 dx;
  s32 dz;

  if (Enemy_ConsumeStateBegun(p)) {
    p->mover.angle = (((p->mover.angle + 0x20) >> 6) & 3) << 6;
    Enemy_PlayAnim(p, 6);
    if (!TEST_FLAGS(p->flags2, ENEFLAG2_UNK_1)) {
      if (TEST_FLAGS(p->flags2, ENEFLAG2_UNK_0)) {
        Enemy_SetEmote(p, 3, 2, p->kind);
        CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_0);
      } else {
        Enemy_SetEmote(p, 3, 0, p->kind);
      }
      SET_FLAGS(p->flags2, ENEFLAG2_UNK_1);
      switch (p->kind) {
        case ENEK_BOKU: {
          PlaySound_082406e0(SONG_237);
          break;
        }
        case ENEK_MUMMY: {
          PlaySound_082406e0(SE_UNK_254);
          break;
        }
        case ENEK_GOLEM: {
          FUN_080e81dc(p, 2);
          break;
        }
        case ENEK_COCKA: {
          PlaySound_082406e0(SONG_462);
          break;
        }
        case ENEK_SKELETON:
        case ENEK_SKELETON_F:
        case ENEK_SKELETON_A: {
          PlaySound_082406e0(SONG_316);
          break;
        }
        case ENEK_DOG: {
          PlaySound_082406e0(SONG_316);
          break;
        }
      }
    }
    SET_FLAGS(p->flags3, ENEFLAG3_UNK_1);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9 | ENEFLAG3_UNK_10 | ENEFLAG3_UNK_12);
    p->animSpeedDiv = 1;
    p->unk_222 = 0;
    p->unk_24e = 0;
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
    if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
      p->unk_21c = 0;
      p->unk_21e = 0;
      p->unk_202 = 0;
    }
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
    p->unk_542 = 0xFF;
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_7);
    p->animSpeedDiv = 1;
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
  }

  if (p->spriteKind == 0) {
    AuxAnimState* anim = &((EnemyAuxSpriteData*)p->sprite)->anim;

    if (anim->cmdIdx == 2 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
      anim->tick = 0;
    }
  } else {
    MainSprite* s = &p->sprite->s;

    if (s->animCmdIdx == 2 && s->animCmdTimer == (s->animCmdLength != 0) && s->animCmdLength != 1) {
      s->animCmdTimer = 0;
    }
  }

  if ((u16)(p->unk_192 - 30) < 90) {
    if (Mod((s16)p->unk_192, 30) < 15 - Div((s16)p->unk_192, 10)) {
      SET_FLAGS(p->flags4, ENEFLAG4_UNK_5);
    }
  }

  dx = FixToInt(2, p->unk_20c.x - p->unk_214.x);
  dz = FixToInt(2, p->unk_20c.z - p->unk_214.z);
  if (dx > 200) {
    dx = 200;
  } else if (dx < -200) {
    dx = -200;
  }
  if (dz > 200) {
    dz = 200;
  } else if (dz < -200) {
    dz = -200;
  }
  p->mover.delta.x += dx;
  p->mover.delta.z += dz;
  p->unk_214.x += dx;
  p->unk_214.z += dz;
  if (dx == 0 && dz == 0) {
    if ((s16)p->unk_192 <= 0) {
      p->unk_192 = 0;
      p->angle = (FixToInt(5, p->mover.angle) + 7) & 7;
      Enemy_ResetState(p, 3, 1, 0);
      Enemy_EnterState(p, p->unk_598, 8);
      CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_1);
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5);
      Enemy_ResetState(p, 3, 1, 0);
      p->mover.angle = (p->mover.angle + 0x20) >> 6 << 6;
    }
  }
#else
  INCFUNC("asm/func/FUN_080f56ec.inc");
#endif
}

void FUN_080f5b34(Enemy* p) {
  if (Enemy_ConsumeStateBegun(p)) {
    Enemy_PlayAnim(p, 7);
    FUN_080e499c(p);
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_1);
  }

  if (p->animForceRestart) {
    p->unk_192 = 0;
    p->subStateDone = 1;
    SET_FLAGS(p->flags, ENEFLAG_UNK_4);
    Enemy_PlayAnim(p, 0);
    Enemy_ResetState(p, 3, 1, 0);
    Enemy_EnterState(p, p->unk_59c, 15);
  }
}

// 状態29 (日光で焼かれている) の更新, 入場時に印と粒子を片付けて焼けるパレットにし, unk_4be を数えながら粒子を出し, 尽きたら状態15へ移す
// 残差は392/392命令でレジスタと並び, 原典は2つ目の flags の CLEAR を ENEFLAG_UNK_21 の検査より先に行い, &unk_21e / &unk_202 を if の外で作って中と後の両方の格納に使う
// 試済: 入場時の片付けをまとめて1つの inline にする (399)
NON_MATCH void FUN_080f5c0c(Enemy* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(p)) {
    u16 pltt;

    p->mover.angle = (((p->mover.angle + 0x20) >> 6) & 3) << 6;
    Enemy_PlayAnim(p, 3);
    p->animSpeedDiv = 1;
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    p->animSpeedDiv = 1;
    p->unk_222 = 0;
    p->unk_24e = 0;
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
    if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
      p->unk_21c = 0;
      p->unk_21e = 0;
      p->unk_202 = 0;
    }
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
    p->unk_542 = 0xFF;
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    Eff082473e0Emitter_Reset(&p->emitter);
    FUN_080e6408(p, 3, 2, 10, 20, 3600);
    SET_FLAGS(p->flags, ENEFLAG_UNK_25);
    SET_FLAGS(p->flags2, ENEFLAG2_UNK_14);
    CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_6 | ENEFLAG2_UNK_8);
    pltt = TEST_FLAGS(p->flags2, ENEFLAG2_UNK_14) ? p->unk_476 : p->unk_47e;
    if (p->spriteKind == 0) {
      Video_SetAuxSpritePltt(&((EnemyAuxSpriteData*)p->sprite)->gfx, pltt);
    } else {
      p->sprite->s.pltt = &gObjPlttData[pltt * 16];
    }
  }

  if (p->unk_44e * 2 == p->unk_4be || p->unk_44e == p->unk_4be) {
    Vec3 vel;
    Vec3 velRange;
    Vec3 pos;

    vel.x = (Random() & 0xF) - 7;
    vel.y = (Random() & 0x1F) - 16;
    vel.z = (Random() & 0xF) - 7;
    velRange.x = 5, velRange.y = 10, velRange.z = 5;
    pos.x = p->emitter.pos->x;
    pos.y = p->emitter.pos->y + 0x80;
    pos.z = p->emitter.pos->z;
    Eff082473e0Emitter_BurstParticle(&p->emitter, 3, &pos, &vel, &velRange, 40, 40);
    Enemy_SetFlag4(p, ENEFLAG4_UNK_5);
  }
  if (p->unk_4be <= 10) {
    Enemy_SetFlag4(p, ENEFLAG4_UNK_5);
  }
  p->unk_494 = 65;
  if (p->unk_4be == 0) {
    p->hitbox.flags |= HBFLAG_ANGLE;
    FUN_080e64e4(p);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_13);
    Enemy_ResetState(p, 3, 1, 0);
    Enemy_EnterState(p, p->unk_59c, 15);
    p->angle = (FixToInt(5, (p->mover.angle + 0x80) & 0xFF) + 7) & 7;
  } else {
    p->unk_4be--;
  }
#else
  INCFUNC("asm/func/FUN_080f5c0c.inc");
#endif
}

// 入場時に向きを 8 方向に揃え, timer が 60 を超えてアニメが一巡したら経路の今のノードへ向かう, 向かえなければ状態0へ戻す
// 残差は279/280命令, 一歩動く部分を「p を受けて unk_4a8 を目標に読む bool8 inline (島の外なら落として FALSE, そうでなければ FUN_08235f40 の結果で TRUE / 落として FALSE)」,
// 予約を (p, handler, s0, s1, s2, priority) の inline にすると形は揃い, 残りは &p->kind や定数のレジスタと, 状態0へ戻すときの定数の作り順
NON_MATCH void FUN_080f5fac(Enemy* p, s32 timer) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(p)) {
    p->mover.angle = (((p->angle + 3) & 7) << 5) - 0x40;
    Enemy_PlayAnim(p, 0);
    p->animForceRestart = FALSE;
  }

  if (timer > 60 && p->animForceRestart) {
    Vec3* target;
    PathWalker* walker;
    bool8 moved;

    p->subStateDone = 1;
    Enemy_SetEmote(p, 0, 2, p->kind);
    target = p->unk_4a8;
    walker = &p->pathWalker;
    target->x = walker->node->x;
    target->z = walker->node->y;
    target->y = TileHeightAt(target);
    moved = FALSE;
    {
      NavAgent* agent = p->navAgent;
      WorldPos* pos = &p->mover.pos;
      Vec3* dst = p->unk_4a8;

      if (Map_IsPosInAgentIsland(agent, pos, dst)) {
        s32 result = FUN_08235f40(agent, pos, dst);

        if (result != 0) {
          if (result != 2) {
            ClearMemory(&p->mover.delta, 8);
          }
          moved = TRUE;
        }
      }
      if (!moved) {
        Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
      }
    }
    if (!moved) {
      Enemy_EnterState(p, Enemy_ClearStateBegun, 0);
      Enemy_ResetState(p, 3, 0, 0);
    } else {
      p->unk_4a8->val = 1;
      Enemy_ResetState(p, 3, 1, 0);
      Enemy_EnterState(p, FUN_080e6794, 14);
      SET_FLAGS(p->flags, ENEFLAG_UNK_4);
      p->animSpeedDiv = 1;
      p->unk_554 = 60;
      p->unk_558 = p->unk_5a0;
      p->unk_550 = 0;
      p->unk_551 = 0;
      p->unk_552 = 7;
    }
  }
#else
  INCFUNC("asm/func/FUN_080f5fac.inc");
#endif
}

// unk_1e4 が 0x100000 未満かどうかで unk_222 の bit0 を切り替えてから1番のアニメを鳴らす
void FUN_080f624c(Enemy* p) {
  if (p->stateBegun != 0) {
    p->stateBegun = 0;
  }

  if (p->unk_1e4 <= 0xFFFFF) {
    SET_FLAGS(p->unk_222, ENEMY222_UNK_0);
  } else {
    CLEAR_FLAGS(p->unk_222, ENEMY222_UNK_0);
  }

  Enemy_PlayAnim(p, 1);
}

void FUN_080f62a8(void) {}

s32 FUN_080f62ac(void) { return 0; }

// ENEFLAG_UNK_22 と UNK_20/21 のどちらかが立っていれば, 状態14へ移して経路の今のノードを目標にし直す, 移したら TRUE
// 残差は240/242命令, unk_550〜unk_558 の5つを (p, handler, s0, s1, s2, priority) を受ける inline で書くと handler の読みが定数より前に出て寄る
// 残りは &p->unk_558 を &p->unk_554 より先に作り, 0x5A4 のレジスタから 0x554 / 0x552 を, 0x550 から 0x4A8 を引いて作る並び, 試済: inline の中の代入をカンマでつなぐ
NON_MATCH bool32 FUN_080f62b0(Enemy* p) {
#ifdef NONMATCHING_C
  Vec3* target;
  PathWalker* walker;

  if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_22) || !TEST_FLAGS(p->flags, ENEFLAG_UNK_20 | ENEFLAG_UNK_21)) {
    return FALSE;
  }

  SET_FLAGS(p->flags, ENEFLAG_UNK_8);
  p->animSpeedDiv = 1;
  Enemy_PlayAnim(p, 0);
  Enemy_ResetState(p, 3, 1, 0);
  Enemy_EnterState(p, FUN_080e6794, 14);
  SET_FLAGS(p->flags, ENEFLAG_UNK_4);
  p->unk_554 = 30;
  p->unk_558 = p->unk_5a4;
  p->unk_550 = 0;
  p->unk_551 = 0;
  p->unk_552 = 9;
  target = p->unk_4a8;
  walker = &p->pathWalker;
  target->x = walker->node->x;
  target->z = walker->node->y;
  target->y = TileHeightAt(target);
  p->unk_4a8->val = 1;
  p->animSpeedDiv = 1;
  p->unk_222 = 0;
  p->unk_24e = 0;
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
  CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
  p->unk_542 = 0xFF;
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080f62b0.inc");
#endif
}

// 状態18へ移して飛行/浮遊系のフラグを落とす
bool32 FUN_080f64f0(Enemy* p) {
  if (p->flags6 & ENEFLAG6_UNK_18) {
    Enemy_SetFlag3(p, ENEFLAG3_UNK_5);
  }

  Enemy_EnterState(p, p->unk_5cc, 18);
  Enemy_ResetState(p, 3, 0, 0);
  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  return TRUE;
}

bool32 FUN_080f65a8(Enemy* p) {
  Enemy_SetFlag3(p, ENEFLAG3_UNK_5);
  Enemy_SetEmote(p, 3, 0, p->kind);
  Enemy_ClearFlag(p, ENEFLAG_UNK_26);
  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  return TRUE;
}

// hp が残っていれば unk_58c に任せる, 尽きていれば状態17へ移して経験値を渡し, 倒した数を数えて図鑑に載せる
// 残差は255/257命令, 頭打ちの 9999 を原典は r1 に読んでから r0 へ移す (FUN_080f00ec と同じ形), こちらは r0 に直接読む
// node5941.flags の bit0 は Entity5941Node* を受ける inline で立てると &p->node5941 からの +4 で揃い, flags5 の検査は bool8 を返す inline で 0/1 の作り置きが揃う, 試済: 頭打ちを MIN 風の三項演算子 / n のローカルで書く (248)
NON_MATCH bool8 FUN_080f6604(Enemy* p) {
#ifdef NONMATCHING_C
  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
    EnemyTargetManager_Release(p->target);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
    p->target = NULL;
  }
  if (p->hp <= 0) {
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11 | ENEFLAG4_UNK_14);
    p->unk_4be = 0;
    if (TEST_FLAGS(p->flags5, ENEFLAG5_UNK_9)) {
      SET_FLAGS(p->node5941.flags, 1);
    }
    Enemy_EnterState(p, p->unk_5d0, 17);
    Enemy_ResetState(p, 3, 0, 0);

    if (IsLinkPlay()) {
      FUN_080ce544(p->unk_4a0, p->weaponExpMask);
    } else {
      if ((p->unk_4a0 & 1) && !TEST_FLAGS(p->flags5, ENEFLAG5_UNK_7)) {
        if ((p->kind != ENEK_OCTOPUS || p->variant != 1) && p->kind != ENEK_SKELETON && p->kind != ENEK_SKELETON_A && p->kind != ENEK_SKELETON_F) {
          if (gStat->unk_948[0] < 9999) {
            gStat->unk_948[0]++;
          } else {
            gStat->unk_948[0] = 9999;
          }
          if (gStat->totalEnemyKillCount < 9999) {
            gStat->totalEnemyKillCount++;
          } else {
            gStat->totalEnemyKillCount = 9999;
          }
          FUN_080e9178(p);
        }
        AddPlayerExp(p->exp);
        Player_AddWeaponExp(p->weaponExpMask, p->weaponExp);
      }
      if (!TEST_FLAGS(p->flags5, ENEFLAG5_UNK_7) && !IsLinkPlay() && !TEST_FLAGS(p->flags2, ENEFLAG2_UNK_11)) {
        FUN_080ec5b4(gMapInitScriptID, p->mover.id);
      }
      p->hitbox.flags |= HBFLAG_HIDDEN;
    }
    return TRUE;
  }
  return p->unk_58c(p);
#else
  INCFUNC("asm/func/FUN_080f6604.inc");
#endif
}

// 種族1が ENEFLAG6_UNK_2 の印で倒されたとき, 粒子と数字を出して hp を減らし, 別の経路へ逃がす, 処理したら TRUE
// 残差は270/270命令で CpuFill32 の前後3命令の並びだけ, 原典は &v を 0 の一時変数より先に r5 へ作る
// 他は次の inline で揃う: 自分の画面のプレイヤーが倒したかを返す bool8 (中で if (gEntity9A9F == NULL) return -1; の番号取得 inline を呼ぶ), spriteKind でパレットを切り替える (plttID を引数に取る)
// 試済: v を関数の先頭で宣言 (変化なし)
NON_MATCH bool8 FUN_080f6868(Enemy* p) {
#ifdef NONMATCHING_C
  u8 kind = p->kind;
  bool8 show;
  s32 damage;

  if (kind == ENEK_MUMMY && (p->flags6 & ENEFLAG6_UNK_2) && !TEST_FLAGS(p->flags3, ENEFLAG3_UNK_13)) {
    SET_FLAGS(p->flags3, ENEFLAG3_UNK_4);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15);
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_1);
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_14);
    if (p->emitter.activeCount <= 3) {
      FUN_080e6408(p, 1, 1, 10, 20, -1);
      p->unk_458[p->unk_460] = 580;
      p->unk_462 |= 1 << p->unk_460;
      p->unk_460++;
    }
    damage = 1 << p->emitter.activeCount;
    p->unk_48a = damage;
    p->hp -= damage;

    show = TRUE;
    if (IsLinkPlay() && !(p->unk_4a0 & 0x20) && p->unk_4a0 != 0) {
      switch (gEntity9A9F != NULL ? gEntity9A9F->playerIdx : -1) {
        case 0: {
          show = p->unk_4a0 == 1;
          break;
        }
        case 1: {
          show = p->unk_4a0 == 2;
          break;
        }
        case 2: {
          show = p->unk_4a0 == 4;
          break;
        }
        case 3: {
          show = p->unk_4a0 == 8;
          break;
        }
      }
    }
    if (show) {
      Vec3 v;

      FUN_0809c344(p->mover.id, p->hp, p->maxHp, p->unk_25a, 1);
      CpuFill32(0, &v, sizeof(v));
      if (p->unk_48a != 0 || !(p->weaponExpMask & 0x4000)) {
        CreateDamageNumber(&p->hitbox, p->unk_48a, 0, &p->mover.pos, &v, 1);
      }
    }
    Mover_SetPath(&p->mover, &p->pathWalker, p->unk_4b4[p->unk_4b6 ^ 1], 0, 0);
    p->unk_464 = 600;
    if (p->spriteKind == 0) {
      Video_SetAuxSpritePltt(&((EnemyAuxSpriteData*)p->sprite)->gfx, p->unk_47e);
    } else {
      p->sprite->s.pltt = &gObjPlttData[p->unk_47e * 16];
    }
    SET_FLAGS(p->flags, ENEFLAG_UNK_25);
    p->unk_494 = 6000;
    PlaySound_082406e0(289);
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080f6868.inc");
#endif
}

// 残差13命令 (98/85) でこちらが長い: 原典は delta をスタックに置き strh/ldrsh で往復するが agbcc は Vec3 をレジスタに展開し, そのぶん p が r8 に追い出されてフィールドアクセスごとに mov/add が余る
// Tier A-C は試済: src/pos のローカルポインタで 102→98, delta を関数スコープへ上げるのは無影響, s16 ローカル3つは 72 / s32 は 70 と逆に短くなる
NON_MATCH s32 FUN_080f6af0(Enemy* p) {
#ifdef NONMATCHING_C
  if (p->kind == ENEK_GOLEM && (p->flags3 & ENEFLAG3_UNK_8) && (p->weaponExpMask & 0x80)) {
    Vec3* src = &p->unk_20c;
    Vec3* pos = &p->mover.pos;
    Vec3 delta;

    delta.x = src->x - pos->x;
    delta.y = src->y - pos->y;
    delta.z = src->z - pos->z;
    p->jumpVel.x = Div(delta.x, 0x24);
    p->jumpVel.y = 0x14;
    p->jumpVel.z = Div(delta.z, 0x24);
    p->mover.angle = ArcTan2_8(delta.x, delta.z);
    FUN_080f897c(p);
    FUN_080e81dc(p, 6);
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_080f6af0.inc");
#endif
}

// 種族10(かつ ENEFLAG6_UNK_14 付き)の敵だけ状態3に戻して hitbox.invincibleTime を 0x26 にする, 原典はフラグが立っていない経路の return を書き忘れている
bool32 FUN_080f6bac(Enemy* p) {
  if (p->kind != ENEK_COCKA) {
    return FALSE;
  }
  if (p->flags6 & ENEFLAG6_UNK_14) {
    p->unk_192 = p->unk_190;
    FUN_080e5098(p, 0, 0);
    FUN_080e499c(p);
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    Enemy_SetFlag3(p, ENEFLAG3_UNK_1);
    Enemy_ResetState(p, 3, 0, 0);
    p->hitbox.invincibleTime = 0x26;
    if (Enemy_GetFlag3(p, ENEFLAG3_UNK_1)) {
      Emote_RemovePtcl(p->emote, 3, p->mover.id);
    }
    return TRUE;
  }
}

// 条件が揃っていれば状態29 (FUN_080f5c0c) へ移して感情アイコンと粒子を片付ける, 既に状態29なら何もせず TRUE
// 残差は187/185命令, 原典は &p->flags2 を r6, &p->flags3 を r8 に置いて末尾の flags3 の検査まで持ち越すが, こちらは2つが入れ替わり末尾でアドレスを組み直す
// flags5 の検査の 0/1 の作り置きは bool8 を返す inline で揃う, 試済: 条件を素の & / Enemy_TestFlag3 で書く, flags2 を Enemy_ClearFlag2 で落とす, 早期 return を並べる形 (179), いずれも同じか悪化
NON_MATCH bool32 FUN_080f6c74(Enemy* p) {
#ifdef NONMATCHING_C
  if (TEST_FLAGS(p->flags2, ENEFLAG2_UNK_27) && !TEST_FLAGS(p->flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_15) && TEST_FLAGS(p->flags3, ENEFLAG3_UNK_13) && p->unk_4be != 0) {
    if (p->state == 29) {
      return TRUE;
    }

    Enemy_EnterState(p, FUN_080f5c0c, 29);
    Enemy_ResetState(p, 3, 0, 0);
    FUN_080e499c(p);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_4);
    CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_1);
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    Enemy_SetEmote(p, 0, 0x7F, 0);
    Enemy_SetEmote(p, 1, 0x7F, 0);
    Enemy_SetEmote(p, 3, 0x7F, 0);
    FUN_080e64b4(p, 4);
    p->unk_464 = 0;
    p->unk_460 = 0;
    p->unk_462 = 0;

    if (TEST_FLAGS(p->flags5, ENEFLAG5_UNK_6)) {
      p->hitbox.flags &= ~HBFLAG_ANGLE;
    } else if (TEST_FLAGS(p->flags6, ENEFLAG6_UNK_14 | ENEFLAG6_UNK_19) || TEST_FLAGS(p->flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_13)) {
      p->hitbox.flags &= ~HBFLAG_ANGLE;
    } else {
      p->hitbox.flags |= HBFLAG_ANGLE;
    }
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080f6c74.inc");
#endif
}

void FUN_080f6e34(Enemy* p) {
  if ((p->flags6 & (ENEFLAG6_UNK_14 | ENEFLAG6_UNK_18 | ENEFLAG6_UNK_19)) != 0) {
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  }
}

NAKED s32 FUN_080f6e64(Enemy* p) { INCFUNC("asm/func/FUN_080f6e64.inc"); }

// 種族ごとの効果音を鳴らしてから状態18へ移す
bool32 FUN_080f8400(Enemy* p) {
  Enemy_ClearFlag3(p, ENEFLAG3_UNK_8);
  switch (p->kind) {
    case ENEK_BAT: {
      PlaySound_082406e0(SONG_264);
      break;
    }
    case ENEK_CROW: {
      PlaySound_082406e0(SONG_265);
      break;
    }
  }

  Enemy_EnterState(p, p->unk_5cc, 18);
  Enemy_ResetState(p, 3, 0, 0);
  Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_3 | ENEFLAG4_UNK_6 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  return TRUE;
}

// 近くで音がしたら音のした場所へ向かわせる, 初めて気付いたときは感情アイコンを出して状態9へ移し TRUE
// 残差は368/380命令, 入口の条件の塊を bool8 を返す inline, 一歩動く部分を Enemy_StepToward 形の inline にするとここまで寄る
// 原典は FUN_08240dc8 の結果を u8 (lsrs) で持って FUN_080e8f20 に渡すときに s8 へ戻し, レジスタの割当も全体に1つずつずれる
NON_MATCH bool32 FUN_080f84d4(Enemy* p) {
#ifdef NONMATCHING_C
  s8 idx;
  bool8 noticed;
  Vec3* target;
  PathWalker* walker;

  Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
  if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_21) || (p->flags2 & ENEFLAG2_UNK_2) || TEST_FLAGS(p->flags, ENEFLAG_UNK_8) ||
      TEST_FLAGS(p->flags3, ENEFLAG3_UNK_0 | ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2 | ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15) || TEST_FLAGS(p->flags, ENEFLAG_UNK_27) || p->unk_4be != 0 || p->hitbox.invincibleTime != 0) {
    return FALSE;
  }

  p->unk_21c = 0;
  noticed = FALSE;
  idx = FUN_08240dc8(p->mover.pos.x, p->mover.pos.z, p->range2, p->unk_21d, p->mover.id);
  if (idx < 0) {
    return FALSE;
  }

  if (p->unk_202 == 0) {
    CLEAR_FLAGS(p->flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    p->unk_21e = 0;
    p->unk_220 = 0;
    p->unk_202 = 0;
    p->unk_202 = 180;
    Enemy_SetEmote(p, 0, 1, p->kind);
    Enemy_EnterState(p, p->unk_5c8, 9);
    Enemy_ResetState(p, 0, 0, 11);
    noticed = TRUE;
  }
  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
    EnemyTargetManager_Release(p->target);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
    p->target = NULL;
  }
  FUN_080e8f20(p, idx);
  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_7)) {
    p->unk_24e += 300;
    if (p->unk_24e > p->unk_24c) {
      p->unk_24e = p->unk_24c;
    }
  }

  target = p->unk_4a8;
  walker = &p->pathWalker;
  target->x = walker->node->x;
  target->z = walker->node->y;
  target->y = TileHeightAt(target);
  p->unk_4a8->y = p->mover.pos.y;
  p->unk_4a8->val = 0;
  {
    NavAgent* agent = p->navAgent;
    bool8 moved = FALSE;

    if (Map_IsPosInAgentIsland(agent, &p->mover.pos, &p->unk_204)) {
      s32 result = FUN_08235f40(agent, &p->mover.pos, &p->unk_204);

      if (result != 0) {
        if (result != 2) {
          ClearMemory(&p->mover.delta, 8);
        }
        moved = TRUE;
      }
    }
    if (!moved) {
      Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
      p->unk_5c4(p);
      return TRUE;
    }
  }
  SET_FLAGS(p->flags, ENEFLAG_UNK_4);
  SET_FLAGS(p->flags3, ENEFLAG3_UNK_9);
  p->animSpeedDiv = 2;
  Enemy_SetFlag2(p, ENEFLAG2_UNK_24);
  Enemy_TargetNearestPlayer(p, &p->unk_204);
  if (noticed) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080f84d4.inc");
#endif
}

// param_2 が正なら, 向きと逆の方へ破片のパーティクルを 2〜3 個飛ばす
// 残差1命令 (138/139), 原典は gRandomTable を先に sl へ置いてから &gRandTableIdx を読むが, こちらは &gRandTableIdx を先に読み, table と 0x3FF の r9/r10 が入れ替わる
// Random() と count のローカルでここまで寄る, u16* table + _Random(table) は table が定数に戻されて 144 命令に悪化
NON_MATCH void FUN_080f8844(Enemy* p, s32 param_2) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 velRange;
  u32 angle;
  s32 count;

  if (param_2 <= 0) {
    return;
  }

  angle = (p->angle + 0x80) & 0xFF;
  vel.x = COS(angle) >> 10;
  vel.y = Random() & 7;
  vel.z = SIN(angle) >> 10;
  velRange.x = (Random() & 7) + 3;
  velRange.y = (Random() & 7) + 3;
  velRange.z = (Random() & 7) + 3;
  count = (Random() & 1) + 2;
  FUN_08014730(count, FUN_080f8abc(p), &p->mover.pos, &vel, &velRange, 45, 31);
#else
  INCFUNC("asm/func/FUN_080f8844.inc");
#endif
}

// 移動量の半分の速さで, 破片のパーティクルを 4〜7 個ばらまく
// 残差は132/139命令, 原典は delta.x / delta.z を ldrsh の後にもう一度 s16 へ符号拡張し, 負の側の結果も s16 に戻してから格納する, table は r6 で 3 は r5 に置く
// s16 を受けて s16 を返す inline (FixToInt(1, v)) にすると入口の符号拡張が揃って 136 命令, 負の側の拡張は if/return 形でも出ない
NON_MATCH void FUN_080f897c(Enemy* p) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 velRange;
  u16* table;
  s32 count;

  vel.x = FixToInt(1, p->mover.delta.x);
  vel.y = Random() & 7;
  vel.z = FixToInt(1, p->mover.delta.z);
  table = gRandomTable;
  velRange.x = (_Random(table) & 3) + 15;
  velRange.y = (_Random(table) & 7) + 15;
  velRange.z = (_Random(table) & 3) + 15;
  count = (_Random(table) & 3) + 4;
  FUN_08014730(count, FUN_080f8abc(p), &p->mover.pos, &vel, &velRange, 45, 31);
#else
  INCFUNC("asm/func/FUN_080f897c.inc");
#endif
}

s32 FUN_080f8abc(Enemy* p) {
  switch (p->variant) {
    case 0: {
      return 4;
    }
    case 1:
    case 3:
    case 5: {
      return 3;
    }
    default: {
      return 4;
    }
  }
}

// 残差3命令 (96/93) でこちらが長い: 原典は定数 0x18 を使用箇所ごとに movs で作るが agbcc は r9 に巻き上げて使い回す, 他はレジスタ順列
// Tier A-C は試済: table の代入を vel.x の後に下げると 97, Random() 形も 97 と悪化
NON_MATCH void FUN_080f8ae0(Enemy* p) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 velRange;
  u16* table = gRandomTable;
  vel.x = -12;
  vel.y = _Random(table) & 7;
  vel.z = -12;
  velRange.x = 24;
  velRange.y = (_Random(table) & 7) + 3;
  velRange.z = 24;
  FUN_08014730((_Random(table) & 3) + 4, FUN_080f8abc(p), &p->mover.pos, &vel, &velRange, 0x3C, 0x3F);
#else
  INCFUNC("asm/func/FUN_080f8ae0.inc");
#endif
}

void FUN_080f8bb8(Mover* owner) {
  if (IsLinkPlay()) {
    s32 idx;

    switch (owner->unk_4) {
      case 0: {
        idx = 0;
        break;
      }
      case 1: {
        idx = 1;
        break;
      }
      case 2: {
        idx = 2;
        break;
      }
      case 3: {
        idx = 3;
        break;
      }
      default: {
        return;
      }
    }
    Entity4B15_ShowTrackingMarker(idx, &owner->pos);
  }
}
