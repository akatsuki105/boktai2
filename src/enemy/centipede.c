#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "global.h"
#include "malloc.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"

// ENEID_CENTIPEDE, センチピード
// 巨大なムカデ型モンスター
// 攻撃が通用するのは頭のみで、ダメージを与えるごとに体が短くなっていく
// 技: 接触, 体当たり
struct Centipede;

// CentipedeSegment.flags (0x0FD)
typedef u8 CentipedeSegmentFlags;
#define CENTSEGFLAG_DESTROYED (1 << 0)  // 0x01, 壊れた節
#define CENTSEGFLAG_FOLLOW (1 << 1)     // 0x02, 1つ前の節の位置を引き継ぐ
#define CENTSEGFLAG_TAIL (1 << 2)       // 0x04, 尾の節

// センチピードの体の節1つ, SandwormSegment から末尾の 4 バイトを除いた形
typedef struct {
  AuxSprite sprite;             // 0x000
  AuxSpriteGfx gfx;             // 0x02C, ID は固定でない
  Hitbox hitbox;                // 0x048, 節ごとの攻撃判定
  Hitbox hurtbox;               // 0x098, 節ごとの食らい判定
  AuxAnimState anim;            // 0x0E8
  AuxAnimFile* animFile;        // 0x0F8, ID は固定でない
  u8 angle;                     // 0x0FC, 節の向き
  CentipedeSegmentFlags flags;  // 0x0FD
  u8 unk_fe[2];                 // 0x0FE
  u8 knockbackAngle;            // 0x100, 弾かれる向き
  u8 swayAngle;                 // 0x101
  u8 wobbleAngle;               // 0x102
  u8 flashTimer;                // 0x103
  u8 unk_104[8];                // 0x104
  Vec3 targetPos;               // 0x10C, 1つ前の節の位置, sprite.pos がここへ寄っていく
  Vec3 velocity;                // 0x114
  struct Centipede* owner;      // 0x11C
} CentipedeSegment;
static_assert(sizeof(CentipedeSegment) == 288);

// Centipede.flags (0xB30)
typedef u16 CentipedeFlags;
#define CENTFLAG_OCCLUSION (1 << 0)  // 0x01, occlusionMover を OcclusionMask に載せている
#define CENTFLAG_UNK_1 (1 << 1)      // 0x02, 立っていると副状態 (0, 0, 4) へ移して落とす
#define CENTFLAG_UNK_2 (1 << 2)      // 0x04, CENTFLAG_UNK_1 で副状態を移したときに立つ

typedef struct Centipede {
  Enemy e;
  u8 unk_654[4];                 // 0x654
  CentipedeSegment segments[4];  // 0x658
  u8 followInterval;             // 0xAD8, 節が1つ前の節の位置を引き継ぐ間隔 (フレーム)
  u8 hoverPhase;                 // 0xAD9
  u8 unk_ada[2];                 // 0xADA
  u8 recentTileIdx;              // 0xADC, recentTiles の次に書く添字
  u8 blockedTimer;               // 0xADD, 進めずに止まっているフレーム数
  u16 turnTileIdx;               // 0xADE
  u16 recentTiles[6];            // 0xAE0, 最近通ったタイルの索引
  Mover occlusionMover;          // 0xAEC, CENTSEGFLAG_TAIL の節に付けて OcclusionMask に載せる Mover, id は mover.id + 1
  CentipedeFlags flags;          // 0xB30
  u8 swayAngle;                  // 0xB32
  u8 shiftTimer;                 // 0xB33
  s8 waveDir;                    // 0xB34
  u8 unk_b35[3];                 // 0xB35
  s16 waveOffset;                // 0xB38
  s16 segmentCount;              // 0xB3A, 節の数
  u8 unk_b3c[8];                 // 0xB3C
  u16 unk_b44;                   // 0xB44, 0 でなければ這う間に節を強く引き寄せて 1 ずつ減らす
  u16 hoverTime;                 // 0xB46, '.P=300', 宙で揺れる状態を続けるフレーム数
  u8 unk_b48;                    // 0xB48
  u8 unk_b49;                    // 0xB49
  u8 segmentsLeft;               // 0xB4A, 壊れていない節の数
  u8 hpPerSegment;               // 0xB4B
  s32 hitDistSq;                 // 0xB4C, このフレームに当たった節のうち一番近い当たりの水平距離の2乗, 0x7FFFFFFF でなければ hitSegment を弾いて 0x7FFFFFFF に戻す
  CentipedeSegment* hitSegment;  // 0xB50, hitDistSq の当たりを受けた節
  u16 footstepDelay;             // 0xB54, 0 になるまで足音を鳴らさない
  u8 unk_b56[2];                 // 0xB56
  NavAgent navAgent;             // 0xB58, Enemy.navAgent が指す
  Vec3 pathNodePos;              // 0xB7C, Enemy.pathNodePos が指す
  Vec3 turnTilePos;              // 0xB84
  Vec3 homePos;                  // 0xB8C, 生成時の mover.pos
} Centipede;
static_assert(sizeof(Centipede) == 2964);

// anim 番の variant を流す, MainSprite では anim + variant 番を flags の向きと逆再生で流し, 同じものが流れていれば何もしない
static inline void Centipede_PlayDirAnim(Centipede* p, u32 anim, u32 variant, u32 flags) {
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = anim;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 mode;

    anim += variant;
    if ((p->e).playingAnim == anim && !(p->e).animForceRestart && ((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    (p->e).playingAnim = anim;
    mode = (flags & ANIM_PLAY_REVERSE) ? MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE : MAIN_ANIM_FORCE_POSE;
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = FALSE;
}

static inline s32 Centipede_AngleDiff(s32 a, s32 b) {
  s32 d = a - b;

  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  return d;
}

static inline bool32 Centipede_IsTurnedTo(s32 target, s32 angle) {
  if (Centipede_AngleDiff(target, angle) < 32) return TRUE;
  return FALSE;
}

static inline void Centipede_AddVelocity(Vec3* out, Vec3* pos, Vec3* vel) {
  out->x = vel->x + pos->x;
  out->y = vel->y + pos->y;
  out->z = vel->z + pos->z;
}

static inline s32 Centipede_CheckStep(s32 cur, s32 next, s32 dir) {
  s32 nextStairs = TileAtIndex(next)->heightStairs >> 4;
  s32 curStairs = TileAtIndex(cur)->heightStairs >> 4;
  TileAttr attr = TileAtIndex(next)->attr;
  WorldPos pos;
  s32 nextHeight, curHeight, diff, step;

  TilePosAtIndex(&pos, next);
  nextHeight = TileHeightAtIndex(next, &pos);
  TilePosAtIndex(&pos, cur);
  curHeight = TileHeightAtIndex(cur, &pos);
  diff = nextHeight - curHeight;
  step = (((curHeight + 0xFF) >> 8) - ((nextHeight + 0xFF) >> 8)) << 8;
  if (attr & (TATTR_PLAYER_WALL | TATTR_ENEMY_WALL | TATTR_FALLDEATH)) {
    return -1;
  }
  if (diff != 0) {
    if (nextStairs == STAIRS_VERTICAL) {
      if (dir == 1) {
        if (step != (curStairs == STAIRS_VERTICAL ? 256 : 0)) {
          return -1;
        }
      } else if (dir == 3) {
        if (step != -256) {
          return -1;
        }
      } else {
        return -1;
      }
    } else if (nextStairs == STAIRS_HORIZONTAL) {
      if (dir == 0) {
        if (step != (curStairs == STAIRS_HORIZONTAL ? 256 : 0)) {
          return -1;
        }
      } else if (dir == 2) {
        if (step != -256) {
          return -1;
        }
      } else {
        return -1;
      }
    }
    if (curStairs == STAIRS_VERTICAL) {
      if (dir == 1) {
        if (step != 256) {
          return -1;
        }
      } else if (dir == 3) {
        if (step != (nextStairs == STAIRS_VERTICAL ? -256 : 0)) {
          return -1;
        }
      } else {
        return -1;
      }
    } else if (curStairs == STAIRS_HORIZONTAL) {
      if (dir == 0) {
        if (step != 256) {
          return -1;
        }
      } else if (dir == 2) {
        if (step != (nextStairs == STAIRS_HORIZONTAL ? -256 : 0)) {
          return -1;
        }
      } else {
        return -1;
      }
    }
    if ((curStairs == STAIRS_HORIZONTAL && nextStairs == STAIRS_HORIZONTAL) || (curStairs == STAIRS_VERTICAL && nextStairs == STAIRS_VERTICAL)) {
      if (abs(diff) > 256) {
        return -1;
      }
    } else if (abs(diff) > 255) {
      return -1;
    }
  }
  return next;
}

static inline s32 Centipede_NeighborTile(s32 tile, s32 dir) {
  switch (dir) {
    case 0: {
      return tile + 1;
    }
    case 1: {
      return tile + gCollisionMap->tiledata->width;
    }
    case 2: {
      return tile - 1;
    }
    case 3: {
      return tile - gCollisionMap->tiledata->width;
    }
  }
  return tile;
}

static inline bool8 Centipede_TestSegmentFlags(CentipedeSegment* seg, CentipedeSegmentFlags bit) {
  if (seg->flags & bit) return TRUE;
  return FALSE;
}

static inline void Centipede_SetFlags(Centipede* p, CentipedeFlags bit) { p->flags |= bit; }
static inline void Centipede_ClearFlags(Centipede* p, CentipedeFlags bit) { p->flags &= ~bit; }

static inline bool8 Centipede_TestFlags(Centipede* p, CentipedeFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

void Centipede_SetSegmentPos(Centipede* p, s32 idx, Vec3* pos);
void FUN_08137e98(Centipede* p);
bool8 Centipede_IsRecentTile(Centipede* p, u32 tileIdx);
void Centipede_AddRecentTile(Centipede* p, u32 tileIdx);
void Centipede_StateRespawn(Centipede* p);
void Centipede_StateWakeUp(Centipede* p, s32 timer);
void Centipede_GetAnimVariant(u16 angle, u32* variant, u32* xflip);
void Centipede_AnimateSegments(Centipede* p, s32 param_2);
void Centipede_StateHover(Centipede* p, s32 timer);
void Centipede_StateLand(Centipede* p, s32 timer);
void Centipede_AimJumpAtPlayer(Centipede* p);
void Centipede_AnimateSegmentsKeepFrame(Centipede* p, s32 idx);
void Centipede_StaggerSegmentAnims(Centipede* p);
void Centipede_OnReset(Centipede* p);
void Centipede_ResetWave(Centipede* p);
void Centipede_AdvanceSwayIfMoving(Centipede* p, s32 speed);
void Centipede_UpdateWave(Centipede* p, s32 amplitude, s32 speed);
void Centipede_StateRise(Centipede* p);
void Centipede_StatePounce(Centipede* p);
void Centipede_BlinkSegments(Centipede* p, s32 timer);
void Centipede_DestroyAllSegmentsWithSmoke(Centipede* p);
void Centipede_StateRiseHover(Centipede* p, s32 timer);
void Centipede_RestartSegmentAnims(Centipede* p, s32 idx, s32 variant, s32 flags);
void Centipede_PickNextTile(Centipede* p);
void Centipede_ResetRecentTiles(Centipede* p);
s32 Centipede_DestroyTailSegment(Centipede* p);
void Centipede_PullSegments(Centipede* p, s32 param_2, s32 param_3);
void Centipede_WobbleSegments(Centipede* p, s32 param_2, s32 param_3, s32 param_4);
void Centipede_EmitSmokeAround(WorldPos* pos);

const STRING_DATA char s_eneinline_08252030[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_08252048[] = "../system/eneinline.h";

// 生成時に退避しておいた状態とフラグに戻し, 一時的な値を全部初期化する
static inline void Enemy_RestoreInitialState(Enemy* p) {
  p->flags = p->initFlags;
  p->flags2 = p->initFlags2;
  p->mover.angle = p->initAngle;
  p->subState0 = p->initSubState0;
  p->subState1 = p->initSubState1;
  p->subState2 = p->initSubState2;
  p->handlerState = p->initHandlerState;
  p->state = p->initState;
  p->flags5 = p->initFlags5;
  p->heightAboveFloor = p->initHeightAboveFloor;
  p->hp = p->maxHp;
  p->flags4 = 0;
  p->unk_222 = 0;
  p->flags3 = 0;
  p->subStateDone = FALSE;
  p->subStateBegun = TRUE;
  p->stateBegun = TRUE;
  p->animForceRestart = FALSE;
  p->chaseTimer = 0;
  p->stunTimer = 0;
  p->unk_544 = 0;
  p->nodeWait = 0;
  p->hitTargetID = 0;
  p->playerMover = NULL;
  p->angle = 0;
  p->unk_21c = 0;
  p->animSpeedDiv = 1;
  p->weaponExpMask = 0;
  p->flags6 = 0;
  p->unk_4a0 = 0;
  p->unk_48c = 0;
  p->unk_4be = 0;
  p->unk_48d = 0;
  p->unk_48e = 0;
  ClearMemory(p->unk_458, 8);
  p->unk_464 = 0;
  p->unk_460 = 0;
  p->unk_462 = 0;
  Enemy_ClearPendingState(p, s_eneinline_08252048, 2434);
  p->lookAngle = 0;
  p->lookBaseAngle = 0;
  p->unk_542 = 0xFF;
  p->savedHandlerState = NULL;
  p->savedSubState0 = 0;
  p->savedSubState1 = 0;
  p->savedSubState2 = 0;
  p->savedState = 0;
  EnemyManager_TryEndPaletteFade(p);
}

void Centipede_SubCircle(Centipede*);
void Centipede_SubTurn(Centipede*);
void Centipede_SubCrawl(Centipede*);
void Centipede_SubHop(Centipede*);
void Centipede_SubLeap(Centipede*);
void FUN_08134e88(Centipede*);
void Centipede_SubCrawlAway(Centipede*);
void Centipede_SubCrawlToward(Centipede*);

void (*const sCentipedeHandlerTable2[12])(Centipede*) = {
    Centipede_SubCircle,
    Centipede_SubTurn,
    Centipede_SubCrawl,
    (void*)FUN_080f2364,
    Centipede_SubHop,
    Centipede_SubLeap,
    FUN_08134e88,
    Centipede_SubCrawlAway,
    Centipede_SubCrawlToward,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
};  // 0x085AD72C

const u32 sCentipedeMoveSpeeds[4] = {28, 31, 38, 48};  // 0x085AD75C

void FUN_08138b34(Centipede*);

void (*const sCentipedeHandlerTable4[1])(Centipede*) = {
    FUN_08138b34,
};  // 0x085AD76C

void Centipede_OnHit(Hitbox* a, Hitbox* b, Centipede* p) {
  if (!Enemy_IsDead(&p->e)) {
    if (b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 食らい判定, 生きていれば敵共通の処理を通し, 副状態を落とす印を見る
// 760/771命令, 敵共通の Enemy_HandleHurt の壁 (Sandworm/Skeleton/Mummy_OnHurt ほか全員 NON_MATCH, a と b のレジスタも入れ替わる), 1回目の下書きで切り上げ
NON_MATCH void Centipede_OnHurt(Hitbox* a, Hitbox* b, Centipede* p) {
#ifdef NONMATCHING_C
  if (Enemy_IsDead(&p->e)) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
  FUN_08137e98(p);
#else
  INCFUNC("asm/func/Centipede_OnHurt.inc");
#endif
}

// 向きに合った移動のアニメを流し, 入ったときは節の歩きのコマもずらす
void Centipede_StateMove(Centipede* p) {
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Centipede_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Centipede_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Centipede_AnimateSegmentsKeepFrame((p->e).owner, 15);
    Centipede_StaggerSegmentAnims((p->e).owner);
  } else {
    Centipede_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Centipede_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Centipede_AnimateSegmentsKeepFrame((p->e).owner, 15);
  }
}

void Centipede_StateWait(Centipede* p) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Centipede_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Centipede_PlayDirAnim(p, (p->e).animTable[17].anim, variant, flags);
  Centipede_AnimateSegments((p->e).owner, 18);
}

void Centipede_StateTurn(Centipede* p) {}

void Centipede_StateNap(Centipede* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 8);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_STUN)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
    }
  }
  if (Mod(timer, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait < 1 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, Centipede_StateWakeUp, ES_WAKE_UP);
  }
}

void Centipede_StateWakeUp(Centipede* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
  }
  if (timer == 40) {
    Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart && timer > 120) {
    (p->e).subStateDone = 1;
  }
}

// 姿と影を隠して 27 フレーム待ち, アニメ 9 を流しながら状態 13 へ移る
void Centipede_StateRespawnWait(Centipede* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (timer > 26) {
    Enemy_PlayAnim(&p->e, 9);
    Enemy_EnterState(&p->e, Centipede_StateRespawn, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
}

// 姿と影を戻して hp 1 と無敵 60 フレームで現れ, アニメが終わったら生成時の状態に戻す
void Centipede_StateRespawn(Centipede* p) {
  AuxAnimState* anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    ParticleShadow_Show(&(p->e).shadow);
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).hp = 1;
    (p->e).hurtbox.iframes = 60;
  }
  anim = &(p->e).s->aux.anim;
  if (anim->cmdIdx == 3 && anim->tick == 4) {
    PlaySound_082406e0(NOISE_UNK_128 | NOISE_HEARTBEAT);
  }
  if ((p->e).animForceRestart) {
    Centipede_OnReset(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

void FUN_08133168(Centipede* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 11);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = TRUE;
  }
}

// 向きと逆へ下がりながら浮き上がり, 残りの節の数で決まる高さに着いたら 状態 38へ移る
void Centipede_StateRise(Centipede* p) {
  Centipede* q = (p->e).owner;
  s32 limit;
  s32 n;
  s32 i;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    u32 variant, flags;

    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Centipede_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Centipede_RestartSegmentAnims(q, 18, variant, flags);
    SET_FLAGS(q->flags, CENTFLAG_UNK_1);
  }
  Vec3_Clear(&(p->e).jumpVel);
  limit = q->segmentsLeft > 3 ? 300 : 200;
  if ((p->e).heightAboveFloor >= limit) {
    Enemy_EnterState(&p->e, Centipede_StateRiseHover, ES_UNK_38);
  } else {
    s32 speed;
    u32 angle;

    if ((p->e).stateTimer < 30) {
      speed = 1;
      (p->e).heightAboveFloor += 10;
    } else {
      speed = 2;
      (p->e).heightAboveFloor += 40;
    }
    angle = ((p->e).mover.angle + 0x80) & 0xFF;
    (p->e).mover.delta.x += POLAR_X(speed, angle);
    (p->e).mover.delta.z += POLAR_Z(speed, angle);
    Centipede_PullSegments(p, 14, 12000);
    n = 0;
    for (i = 0; i < q->segmentCount; i++) {
      if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED | CENTSEGFLAG_TAIL)) {
        switch (n) {
          case 0: {
            q->segments[i].sprite.pos.x = (p->e).mover.pos.x - POLAR_X(54, (p->e).mover.angle);
            q->segments[i].sprite.pos.z = (p->e).mover.pos.z - POLAR_Z(54, (p->e).mover.angle);
            break;
          }
          case 1: {
            q->segments[i].sprite.pos.x = (p->e).mover.pos.x - POLAR_X(20, (p->e).mover.angle);
            q->segments[i].sprite.pos.z = (p->e).mover.pos.z - POLAR_Z(20, (p->e).mover.angle);
            break;
          }
          default: {
            q->segments[i].sprite.pos.x = (p->e).mover.pos.x;
            q->segments[i].sprite.pos.z = (p->e).mover.pos.z;
            break;
          }
        }
        n++;
      }
    }
  }
}

// 宙で前後に揺れながら追う節の前の2つを頭の後ろに並べ, hoverTime を過ぎたら副状態を終える
// 308/306命令, Sandworm_StateHover と同じ壁 (speed を作る ands の並び), 加えて q と i のレジスタが入れ替わる, 試済: ands の被演算子の順
NON_MATCH void Centipede_StateRiseHover(Centipede* p, s32 timer) {
#ifdef NONMATCHING_C
  Centipede* q = (p->e).owner;
  u32 phase;
  u32 angle;
  s32 speed;
  s32 n;
  s32 i;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->hoverPhase = 0;
  }
  phase = q->hoverPhase;
  if ((s8)q->hoverPhase >= 0) {
    angle = (p->e).mover.angle;
  } else {
    angle = ((p->e).mover.angle + 0x80) & 0xFF;
  }
  speed = (phase & 0x7F) >> 4;
  (p->e).mover.delta.x += POLAR_X(speed, angle);
  (p->e).mover.delta.z += POLAR_Z(speed, angle);
  q->hoverPhase += 12;
  n = 0;
  for (i = 0; i < q->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED | CENTSEGFLAG_TAIL)) {
      q->segments[i].velocity.x = Div((p->e).mover.delta.x, i + 1);
      q->segments[i].velocity.y = 0;
      q->segments[i].velocity.z = Div((p->e).mover.delta.z, i + 1);
      switch (n) {
        case 0: {
          q->segments[i].sprite.pos.x = (p->e).mover.pos.x - POLAR_X(54, (p->e).mover.angle);
          q->segments[i].sprite.pos.z = (p->e).mover.pos.z - POLAR_Z(54, (p->e).mover.angle);
          break;
        }
        case 1: {
          q->segments[i].sprite.pos.x = (p->e).mover.pos.x - POLAR_X(20, (p->e).mover.angle);
          q->segments[i].sprite.pos.z = (p->e).mover.pos.z - POLAR_Z(20, (p->e).mover.angle);
          break;
        }
        default: {
          q->segments[i].sprite.pos.x = (p->e).mover.pos.x;
          q->segments[i].sprite.pos.z = (p->e).mover.pos.z;
          break;
        }
      }
      n++;
    }
  }
  if (timer > q->hoverTime) {
    (p->e).subStateDone = 1;
    (p->e).unk_1bc = 2;
    Centipede_ClearFlags(q, CENTFLAG_UNK_1);
  } else {
    Centipede_PullSegments(p, 64, 0xFFFF);
  }
#else
  INCFUNC("asm/func/Centipede_StateRiseHover.inc");
#endif
}

// 向きと逆へ下がりながら浮き上がり, 床から 256 を超えたら状態 34 へ移る
void Centipede_StateLeapBack(Centipede* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  Vec3_Clear(&(p->e).jumpVel);
  if ((p->e).heightAboveFloor > 255) {
    Enemy_EnterState(&p->e, Centipede_StateHover, ES_UNK_34);
  } else {
    s32 speed;
    u32 angle;

    if ((p->e).subStateTimer < 30) {
      speed = 1;
      (p->e).heightAboveFloor += 10;
    } else {
      speed = 2;
      (p->e).heightAboveFloor += 40;
    }
    angle = ((p->e).mover.angle + 0x80) & 0xFF;
    (p->e).mover.delta.x += POLAR_X(speed, angle);
    (p->e).mover.delta.z += POLAR_Z(speed, angle);
    Centipede_PullSegments(p, 10, 0x1000);
    Centipede_WobbleSegments(p, 20, 24, 0);
  }
}

// 宙で前後に揺れながら追う節の前の2つを頭の後ろに並べ, 60 フレーム後に Centipede_StatePounce の状態へ移る
// 残差は speed を作る ands の並びだけ (307/307命令), Sandworm/Serpent/Salamander_StateHover と同じ壁, 原典は 0x7F 側に結果を置く, 試済: 被演算子の順, phase の型 (u8/s8/s32), % 128 や / 16, hoverPhase の読み直し (ands は合うが読む位置とレジスタがずれる)
NON_MATCH void Centipede_StateHover(Centipede* p, s32 timer) {
#ifdef NONMATCHING_C
  Centipede* q = (p->e).owner;
  u32 phase;
  u32 angle;
  s32 speed;
  s32 n;
  s32 i;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->hoverPhase = 0;
  }
  phase = q->hoverPhase;
  if ((s8)q->hoverPhase >= 0) {
    angle = (p->e).mover.angle;
  } else {
    angle = ((p->e).mover.angle + 0x80) & 0xFF;
  }
  speed = (phase & 0x7F) >> 4;
  (p->e).mover.delta.x += POLAR_X(speed, angle);
  (p->e).mover.delta.z += POLAR_Z(speed, angle);
  q->hoverPhase += 12;
  n = 0;
  for (i = 0; i < q->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED | CENTSEGFLAG_TAIL)) {
      q->segments[i].velocity.x = Div((p->e).mover.delta.x, i + 1);
      q->segments[i].velocity.y = 0;
      q->segments[i].velocity.z = Div((p->e).mover.delta.z, i + 1);
      switch (n) {
        case 0: {
          q->segments[i].sprite.pos.x = (p->e).mover.pos.x - POLAR_X(54, (p->e).mover.angle);
          q->segments[i].sprite.pos.z = (p->e).mover.pos.z - POLAR_Z(54, (p->e).mover.angle);
          break;
        }
        case 1: {
          q->segments[i].sprite.pos.x = (p->e).mover.pos.x - POLAR_X(20, (p->e).mover.angle);
          q->segments[i].sprite.pos.z = (p->e).mover.pos.z - POLAR_Z(20, (p->e).mover.angle);
          break;
        }
        default: {
          q->segments[i].sprite.pos.x = (p->e).mover.pos.x;
          q->segments[i].sprite.pos.z = (p->e).mover.pos.z;
          break;
        }
      }
      n++;
    }
  }
  Centipede_PullSegments(p, 64, 0xFFFF);
  if (timer > 60) {
    Enemy_EnterState(&p->e, Centipede_StatePounce, ES_UNK_35);
  }
#else
  INCFUNC("asm/func/Centipede_StateHover.inc");
#endif
}

// プレイヤーへ向けて跳びかかり, 着地したら状態 36 へ移る
void Centipede_StatePounce(Centipede* p) {
  Centipede* q = (p->e).owner;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Centipede_AimJumpAtPlayer(p);
    (p->e).mover.angle = ArcTan2_8((p->e).jumpVel.x, (p->e).jumpVel.z);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    CLEAR_FLAGS(q->flags, CENTFLAG_UNK_1);
    SET_FLAGS(q->flags, CENTFLAG_UNK_2);
    PlaySound_082406e0(SONG_982);
  }
  Centipede_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Centipede_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Centipede_WobbleSegments(p, 18, 6, 0);
  Centipede_AnimateSegmentsKeepFrame((p->e).owner, 15);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Centipede_StateLand, ES_UNK_36);
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
}

// 着地してから節を引き寄せつつ 40 フレーム待ち, 終わったら副状態を進める
void Centipede_StateLand(Centipede* p, s32 timer) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Centipede_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Centipede_PlayDirAnim(p, (p->e).animTable[17].anim, variant, flags);
  Centipede_AnimateSegments((p->e).owner, 18);
  Centipede_PullSegments(p, 20, 0x6400);
  if (timer > 40) {
    Centipede_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Centipede_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Centipede_AnimateSegmentsKeepFrame((p->e).owner, 15);
    (p->e).subStateDone = 1;
  }
}

void Centipede_ClearStateBegun(Centipede* p) {
  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
}

// 被弾して減った hp に合わせて尾の節を壊し, 弾かれ終えたら副状態 5 へ移る
// 217/224命令, 敵共通の StateDamaged の壁 (原典はフラグと unk_20c/unk_214 のアドレスを if より前にレジスタとスタックへ作り置く), Sandworm/Serpent_StateDamaged と同じ, 1回目の下書きで切り上げ
NON_MATCH void Centipede_StateDamaged(Centipede* p) {
#ifdef NONMATCHING_C
  Centipede* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 n;

    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
    for (n = Div((p->e).hp, q->hpPerSegment); n < q->segmentsLeft; n++) {
      Centipede_DestroyTailSegment(p);
    }
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  if (Enemy_StepSlide(&p->e)) {
    (p->e).subStateDone = 1;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 5);
    (p->e).mover.angle = (p->e).playerAngle;
    (p->e).animSpeedDiv = 1;
  }
#else
  INCFUNC("asm/func/Centipede_StateDamaged.inc");
#endif
}

// 煙を出しながら点滅して消え, 節を全部壊して撃破スクリプトと図鑑を処理してから止まる
// 375/375命令, 残差は乱数表と定数アドレスの一時レジスタの割り当てだけ (原典は乱数表を r4, 0x46B を r7, 0x178 を r2 に置く), 試済: Random/RandomNext, idx と size の宣言位置
NON_MATCH void Centipede_StateDying(Centipede* p, s32 timer) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    u32 variant, flags;

    Centipede_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Centipede_PlayDirAnim(p, (p->e).animTable[17].anim, variant, flags);
    Centipede_AnimateSegments((p->e).owner, 18);
    (p->e).animForceRestart = FALSE;
    Enemy_SetEmote(&p->e, 0, 127, 0);
    Enemy_SetEmote(&p->e, 1, 127, 0);
    Enemy_SetEmote(&p->e, 3, 127, 0);
    Enemy_FadeParticles(&p->e, 4);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBF_HIDDEN;
  }
  if (Mod(timer, 10) == 0) {
    Vec3 size;

    VEC3_SET(size, 60, 60, 40);
    EmitSmoke(&(p->e).mover.pos, (Random() & 3) + 1, &size, (p->e).mover.angle + 0x80, 10, 8, 2, 2);
  }
  Centipede_BlinkSegments(p, timer);
  if (Sprite_UpdateVanishBlink(&(p->e).s->aux.spr.flags, timer, 10, 30)) {
    s32 idx;

    (p->e).subStateDone = 1;
    Centipede_DestroyAllSegmentsWithSmoke(p);
    Centipede_EmitSmokeAround(&(p->e).mover.pos);
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      FUN_080e6658(&p->e);
    }
    if ((p->e).defeatScriptID != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      argv[6] = (p->e).unk_4a0;
      argv[7] = (p->e).mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID((p->e).defeatScriptID, &sa);
    }
    idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    (p->e).stunTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
  }
#else
  INCFUNC("asm/func/Centipede_StateDying.inc");
#endif
}

// 体をくねらせて行き先へ這い進み, 着いたら次の行き先を決める, プレイヤーを見つけたら副状態 7 へ, 向きが 32 より離れていれば向き直りへ移る
void Centipede_SubCrawl(Centipede* p) {
  Centipede* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->waveDir = 1;
    q->waveOffset = 0;
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Centipede_ResetWave(p);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    Enemy_ResetState(&p->e, 0, 0, 7);
    return;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Centipede_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    if (abs(Centipede_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
      Enemy_ResetState(&p->e, 0, 0, 1);
      return;
    }
  }
  Centipede_AdvanceSwayIfMoving(p, speed);
  if (q->unk_b44 != 0) {
    Centipede_PullSegments(p, 18, 0x1000);
    q->unk_b44--;
  } else {
    Centipede_PullSegments(p, 20, 0x6400);
  }
  Centipede_UpdateWave(p, 120, 10);
  (p->e).subStateTimer++;
}

// プレイヤーと逆の向きの行き先を選んで這い進み, 80 フレームを超えたら副状態 8 へ移る
void Centipede_SubCrawlAway(Centipede* p) {
  Centipede* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Centipede_ResetWave(p);
    q->unk_b49 = (((p->e).playerAngle + 0x80) & 0xFF) >> 6;
    q->unk_b48 = 0;
    Centipede_PickNextTile(p);
  }
  if ((p->e).unk_544 == 0) {
    (p->e).unk_544 = 1;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Centipede_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
  }
  Centipede_AdvanceSwayIfMoving(p, speed);
  if (q->unk_b44 != 0) {
    Centipede_PullSegments(p, 18, 0x1000);
    q->unk_b44--;
  } else {
    Centipede_PullSegments(p, 20, 0x6400);
  }
  Centipede_UpdateWave(p, 120, 10);
  if ((p->e).subStateTimer > 80) {
    Enemy_ResetState(&p->e, 0, 0, 8);
  } else {
    (p->e).subStateTimer++;
  }
}

// プレイヤーの方の行き先を選んで這い進み, プレイヤーを見つけたら副状態 0 へ, 800 フレームを超えたら次の行き先を決めて副状態 2 へ移る
void Centipede_SubCrawlToward(Centipede* p) {
  Centipede* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Centipede_ResetWave(p);
    q->unk_b49 = (((p->e).playerAngle + 0x20) & 0xFF) >> 6;
    q->unk_b48 = 0;
    Centipede_PickNextTile(p);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    Enemy_ResetState(&p->e, 0, 0, 0);
    return;
  }
  if ((p->e).unk_544 == 0) {
    (p->e).unk_544 = 1;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Centipede_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
  }
  Centipede_AdvanceSwayIfMoving(p, speed);
  if (q->unk_b44 != 0) {
    Centipede_PullSegments(p, 18, 0x1000);
    q->unk_b44--;
  } else {
    Centipede_PullSegments(p, 20, 0x6400);
  }
  Centipede_UpdateWave(p, 120, 10);
  if ((p->e).subStateTimer > 800) {
    Centipede_PickNextTile(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
}

// 足音を鳴らしつつ向きを少しずつ回しながら進んで円を描き, 116 フレームを過ぎてプレイヤーの方を向いたら副状態 6 へ移る
void Centipede_SubCircle(Centipede* p) {
  s32 speed, followDiv, turn, followDistSq;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  if (Mod((p->e).subStateTimer, 48) == 0) {
    PlaySound_082406e0(SONG_983);
  }
  Vec3_Clear(&(p->e).jumpVel);
  if ((p->e).subStateTimer > 115 && Centipede_IsTurnedTo((p->e).playerAngle, (p->e).mover.angle)) {
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_ResetState(&p->e, 0, 0, 6);
    return;
  }
  if ((p->e).subStateTimer < 64) {
    speed = 20;
    followDiv = 8;
    turn = 4;
    followDistSq = 6240;
  } else if ((p->e).subStateTimer < 116) {
    speed = 14;
    followDiv = 8;
    turn = 8;
    followDistSq = 1240;
  } else {
    speed = 3;
    followDiv = 8;
    turn = 6;
    followDistSq = 1240;
  }
  {
    s32 dx = POLAR_X(speed, (p->e).mover.angle);
    s32 dz = POLAR_Z(speed, (p->e).mover.angle);

    (p->e).mover.angle += turn;
    (p->e).mover.delta.x += dx;
    (p->e).mover.delta.z += dz;
  }
  Centipede_PullSegments(p, followDiv, followDistSq);
  (p->e).subStateTimer++;
}

// 状態 37 に入って音を鳴らし, その状態でプレイヤーを見つければ副状態 (0, 2, 0) へ, 終われば次の行き先を決めて副状態 2 へ移る
void FUN_08134e88(Centipede* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Centipede_StateRise, ES_UNK_37);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    PlaySound_082406e0(SE_411);
  }
  if ((p->e).state == ES_UNK_38 && (p->e).tryDetectPlayer(&p->e)) {
    Enemy_ResetState(&p->e, 0, 2, 0);
  } else if ((p->e).subStateDone) {
    Centipede_PickNextTile(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  } else {
    (p->e).subStateTimer++;
  }
}

// 今いるタイルの中で unk_1dc の向きへ向き直り, 向ききったら副状態 2 へ移る, プレイヤーを探すが見つけても何もしない
void Centipede_SubTurn(Centipede* p) {
  Centipede* q = (p->e).owner;
  Vec3 v;
  s32 speed;
  s32 diff;
  s32 tile;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->turnTileIdx = (p->e).tileIdx;
    TilePosAtIndex(&q->turnTilePos, q->turnTileIdx);
  }
  (p->e).tryDetectPlayer(&p->e);
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  diff = Centipede_AngleDiff((p->e).unk_1dc, (p->e).mover.angle);
  if (abs(diff) > 8) {
    s32 dx = POLAR_X(speed, (p->e).mover.angle);
    s32 dz = POLAR_Z(speed, (p->e).mover.angle);

    (p->e).mover.delta.x += dx;
    (p->e).mover.delta.z += dz;
  }
  Vec3_Sum(&v, &(p->e).mover.pos, &(p->e).mover.delta);
  tile = GetCollisionTileIdx(&v);
  if (q->turnTileIdx != tile) {
    Vec3_Diff(&v, &q->turnTilePos, &v);
    (p->e).mover.delta.x += Div(v.x, 10);
    (p->e).mover.delta.z += Div(v.z, 10);
  }
  Centipede_PullSegments(p, 12, 42000);
  if (abs(diff) <= 7) {
    if (q->turnTileIdx == tile) {
      Enemy_ResetState(&p->e, 0, 0, 2);
    }
  } else if (diff > 0) {
    (p->e).mover.angle += (p->e).animSpeedDiv * 2;
  } else {
    (p->e).mover.angle -= (p->e).animSpeedDiv * 2;
  }
  (p->e).subStateTimer++;
}

// angle の向きへ hurtbox.knockback の 1/8 の速さで跳び, 着地したら次の行き先を決めて移動に戻る
void Centipede_SubLeap(Centipede* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).angle, (p->e).hurtbox.knockback >> 3);
    (p->e).jumpVel.y = 32;
    (p->e).unk_1bc = 2;
  }
  Centipede_PullSegments(p, 6, 0x1000);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Centipede_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
    PlaySound_082406e0(SONG_983);
  } else {
    (p->e).subStateTimer++;
  }
}

// 向いている方へ速さ 4 で跳ね, 着地したら次の行き先を決めて移動に戻る
void Centipede_SubHop(Centipede* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).mover.angle, 4);
    (p->e).jumpVel.y = 0;
    (p->e).unk_1bc = 2;
  }
  Centipede_PullSegments(p, 6, 0x1000);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Centipede_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
}

void Centipede_SetHandlerTable2(Centipede* p) { (p->e).handlerTables[2] = (void*)sCentipedeHandlerTable2; }

void Centipede_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *variant = 8 - dir;
    *xflip = 1;
  } else {
    *variant = dir;
    *xflip = 0;
  }
}

// 4 方向の隣のタイルから進めるものを選び, 最近通っていないものを行き先にする, 無ければ乱数で選ぶか真っすぐ進むか unk_b49 の逆へ向かう
// 1099/1217命令の下書き, Sandworm/Salamander_PickNextTile と同じ壁 (原典は判定の塊を2か所に展開し, 4 方向の数えを sp に置く), 1回目の下書きで切り上げ
NON_MATCH void Centipede_PickNextTile(Centipede* p) {
#ifdef NONMATCHING_C
  Centipede* q = (p->e).owner;
  NavAgent* agent = (p->e).navAgent;
  s32 facing = (((p->e).mover.angle + 0x20) & 0xFF) >> 6;
  s32 cands[4];
  s32 n;
  s32 straight;
  s32 dir;
  s32 i;
  s32 tile;

  for (i = 0; i < 4; i++) {
    cands[i] = -1;
  }
  n = 0;
  straight = -1;
  if (q->unk_b48 == 2) {
    dir = (facing + 1) & 3;
  } else if (q->unk_b48 == 3) {
    dir = (facing + Random()) & 3;
  } else {
    dir = facing;
  }
  if (q->unk_b48 > 16) {
    q->unk_b49 = (((p->e).playerAngle + 0x20) & 0xFF) >> 6;
    q->unk_b48 = 0;
  }
  for (i = 0; i < 4; i++) {
    if (abs(dir - q->unk_b49) != 2 && abs(dir - facing) != 2) {
      tile = Centipede_CheckStep((p->e).tileIdx, Centipede_NeighborTile((p->e).tileIdx, dir), dir);
      if (tile >= 0) {
        if (dir == facing) {
          straight = tile;
        } else {
          cands[n++] = tile;
        }
      }
    }
    dir = (dir + 1) & 3;
  }
  if (n != 0) {
    for (i = 0; i < n; i++) {
      if (!Centipede_IsRecentTile(p, cands[i])) {
        TilePosAtIndex(&agent->dest, cands[i]);
        Centipede_AddRecentTile(p, cands[i]);
        q->unk_b48++;
        q->unk_b44 = 40;
        return;
      }
    }
    i = Mod(Random(), n);
    TilePosAtIndex(&agent->dest, cands[i]);
    Centipede_AddRecentTile(p, cands[i]);
    q->unk_b48++;
    q->unk_b44 = 40;
  } else if (straight != -1 && !Centipede_IsRecentTile(p, straight)) {
    TilePosAtIndex(&agent->dest, straight);
    Centipede_AddRecentTile(p, straight);
    q->unk_b48 += 8;
    q->unk_b44 = 40;
  } else {
    dir = (q->unk_b49 + 2) & 3;
    tile = Centipede_CheckStep((p->e).tileIdx, Centipede_NeighborTile((p->e).tileIdx, dir), dir);
    if (tile >= 0) {
      TilePosAtIndex(&agent->dest, tile);
      Centipede_AddRecentTile(p, tile);
      q->unk_b48 += 2;
      q->unk_b44 = 40;
    } else {
      q->unk_b49 = (q->unk_b49 + 1) & 3;
    }
  }
#else
  INCFUNC("asm/func/Centipede_PickNextTile.inc");
#endif
}

// 12 フレームごとに尾の節を中の節の位置へ, 中の節を頭の節の位置へ, 頭の節を pos へ送る
void Centipede_ShiftKeySegments(Centipede* p, Vec3* pos) {
  Centipede* q = (p->e).owner;

  if (q->shiftTimer != 0) {
    q->shiftTimer--;
  } else {
    q->shiftTimer = 12;
    Centipede_SetSegmentPos(q, q->segmentCount - 1, &q->segments[q->segmentCount >> 1].sprite.pos);
    Centipede_SetSegmentPos(q, q->segmentCount >> 1, &q->segments[0].sprite.pos);
    Centipede_SetSegmentPos(q, 0, pos);
  }
}

// 4 つの節を作り, 尾は逆向きのアニメ 1, 他はアニメ 2 をコマをずらして流し, 先頭の節に前の節を追わせる
void Centipede_InitSegments(Centipede* p, SpriteID32 sprID, u32 animFID, u32 angle) {
  Centipede* q = (p->e).owner;
  s32 n;
  s32 cmdIdx;
  s32 i;

  q->segmentCount = 4;
  q->segmentsLeft = q->segmentCount;
  q->hitDistSq = 0x7FFFFFFF;
  q->hpPerSegment = Div((p->e).hp, q->segmentCount + 1);
  n = 0;
  cmdIdx = 0;
  for (i = 0; i < q->segmentCount; i++) {
    CentipedeSegment* seg = &q->segments[i];
    u32 variant, xflip;

    Video_GetAuxSprite(&seg->gfx, sprID);
    AuxSprite_Add(&seg->sprite, &seg->gfx, 0);
    seg->angle = angle;
    seg->animFile = GetFile(DIR_ANIMATION, animFID);
    if (i == q->segmentCount - 1) {
      Centipede_GetAnimVariant((seg->angle + 0x80) & 0xFF, &variant, &xflip);
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 1, variant, xflip);
      SET_FLAGS(seg->flags, CENTSEGFLAG_TAIL);
    } else {
      Centipede_GetAnimVariant(seg->angle, &variant, &xflip);
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 2, variant, xflip);
      seg->anim.cmdIdx = cmdIdx;
      if (++cmdIdx > 3) {
        cmdIdx = 0;
      }
    }
    seg->owner = q;
    if (n == 0) {
      seg->wobbleAngle = i * 24;
      SET_FLAGS(q->segments[i].flags, CENTSEGFLAG_FOLLOW);
    } else {
      n++;
    }
  }
}

// 壊れていない尾以外の節の歩きアニメのコマを 0..3 で1つずつずらす
void Centipede_StaggerSegmentAnims(Centipede* p) {
  s32 cmdIdx = 0;
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Centipede_TestSegmentFlags(&p->segments[i], CENTSEGFLAG_DESTROYED | CENTSEGFLAG_TAIL)) {
      p->segments[i].anim.cmdIdx = cmdIdx;
      if (++cmdIdx > 3) {
        cmdIdx = 0;
      }
    }
  }
}

// Centipede_AnimateSegments と同じだが, 尾以外の節は流し直してもアニメのコマと経過フレームを保つ
void Centipede_AnimateSegmentsKeepFrame(Centipede* p, s32 idx) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Centipede_TestSegmentFlags(&p->segments[i], CENTSEGFLAG_DESTROYED)) {
      u32 variant, xflip;

      if (Centipede_TestSegmentFlags(&p->segments[i], CENTSEGFLAG_TAIL)) {
        Centipede_GetAnimVariant((p->segments[i].angle + 0x80) & 0xFF, &variant, &xflip);
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, 1, variant, xflip);
      } else {
        u16 cmdIdx, tick;

        Centipede_GetAnimVariant(p->segments[i].angle, &variant, &xflip);
        cmdIdx = p->segments[i].anim.cmdIdx;
        tick = p->segments[i].anim.tick;
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, xflip);
        AuxAnim_SetAnimSpeed(&p->segments[i].anim, Div(Q6(1), (p->e).animSpeedDiv));
        p->segments[i].anim.cmdIdx = cmdIdx;
        p->segments[i].anim.tick = tick;
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

// 壊れていない節に向きに合った animTable[idx] (尾は逆向きの anim 1) を流し, 1コマ進める
void Centipede_AnimateSegments(Centipede* p, s32 idx) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Centipede_TestSegmentFlags(&p->segments[i], CENTSEGFLAG_DESTROYED)) {
      u32 variant, xflip;

      if (Centipede_TestSegmentFlags(&p->segments[i], CENTSEGFLAG_TAIL)) {
        Centipede_GetAnimVariant((p->segments[i].angle + 0x80) & 0xFF, &variant, &xflip);
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, 1, variant, xflip);
      } else {
        Centipede_GetAnimVariant(p->segments[i].angle, &variant, &xflip);
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, xflip);
        AuxAnim_SetAnimSpeed(&p->segments[i].anim, Div(Q6(1), (p->e).animSpeedDiv));
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

void Centipede_BlinkSegments(Centipede* p, s32 timer) {
  Centipede* q = (p->e).owner;
  CentipedeSegment* segs = q->segments;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Centipede_TestSegmentFlags(&segs[i], CENTSEGFLAG_DESTROYED)) {
      Sprite_UpdateVanishBlink(&segs[i].sprite.flags, timer, 10, 30);
    }
  }
}

// 壊れていない節の animTable[idx] (尾は anim 1) を variant と flags で頭から流し直し, 1コマ進める
void Centipede_RestartSegmentAnims(Centipede* p, s32 idx, s32 variant, s32 flags) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Centipede_TestSegmentFlags(&p->segments[i], CENTSEGFLAG_DESTROYED)) {
      if (Centipede_TestSegmentFlags(&p->segments[i], CENTSEGFLAG_TAIL)) {
        AuxAnim_RestartAnim(&p->segments[i].anim, p->segments[i].animFile, 1, variant, flags);
      } else {
        AuxAnim_RestartAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, flags);
        AuxAnim_SetAnimSpeed(&p->segments[i].anim, Div(Q6(1), (p->e).animSpeedDiv));
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

void Centipede_HideDestroyedSegments(Centipede* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&p->segments[i], CENTSEGFLAG_DESTROYED)) {
      p->segments[i].sprite.flags = SPRFLAG_HIDDEN;
    }
  }
}

void Centipede_RemoveSegmentSprites(Centipede* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    AuxSprite_Remove(&p->segments[i].sprite);
  }
}

// 壊れていない節を1つ前の節 (先頭は頭) の方へ向ける
void Centipede_FaceSegmentsForward(Centipede* p) {
  Centipede* q = (p->e).owner;
  Vec3 diff;
  Vec3 prev = (p->e).mover.pos;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
      Vec3_Diff(&diff, &prev, &q->segments[i].sprite.pos);
      q->segments[i].angle = ArcTan2_8(diff.x, diff.z);
      prev = q->segments[i].sprite.pos;
    }
  }
}

void Centipede_ResetWave(Centipede* p) {
  Centipede* q = (p->e).owner;

  q->waveOffset = 0;
  q->waveDir = 1;
}

void Centipede_RemoveOcclusionMover(Centipede* p) {
  Centipede* q = (p->e).owner;

  if (Centipede_TestFlags(q, CENTFLAG_OCCLUSION)) {
    CLEAR_FLAGS(q->flags, CENTFLAG_OCCLUSION);
    FUN_08002a58(&q->occlusionMover);
    Mover_Unlink(&q->occlusionMover);
  }
}

void Centipede_SyncOcclusionMover(Centipede* p) {
  Centipede* q = (p->e).owner;
  s32 idx = 0xFF;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_TAIL)) {
      idx = i;
      break;
    }
  }
  if (idx != 0xFF && Centipede_TestFlags(q, CENTFLAG_OCCLUSION)) {
    q->occlusionMover.pos = q->segments[idx].sprite.pos;
    q->occlusionMover.auxSprite = &q->segments[idx].sprite;
  }
}

void Centipede_AddOcclusionMover(Centipede* p) {
  Centipede* q = (p->e).owner;
  s32 idx = 0xFF;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_TAIL)) {
      idx = i;
      break;
    }
  }
  if (idx != 0xFF) {
    Mover_Init(&q->occlusionMover, (p->e).mover.id + 1, &q->segments[idx].sprite.pos, 0, MOVER_OBJECT, q);
    q->occlusionMover.auxSprite = &q->segments[idx].sprite;
    FUN_08002a48(&q->occlusionMover);
    SET_FLAGS(q->flags, CENTFLAG_OCCLUSION);
  }
}

void Centipede_UpdateWave(Centipede* p, s32 amplitude, s32 speed) {
  Centipede* q = (p->e).owner;

  if (q->waveOffset >= amplitude) {
    q->waveOffset = amplitude;
    q->waveDir = -1;
  } else if (q->waveOffset <= -amplitude) {
    q->waveOffset = -amplitude;
    q->waveDir = 1;
  }
  q->waveOffset += q->waveDir * speed;
}

void Centipede_InitFollowInterval(Centipede* p) { ((Centipede*)(p->e).owner)->followInterval = 1; }

// 生きている間, followInterval フレームごとに前の節を追う節の targetPos を1つ前の節の位置 (先頭は頭) に送る
void Centipede_FollowSegments(Centipede* p) {
  if (!Enemy_IsDead(&p->e)) {
    Centipede* q = (p->e).owner;

    if (Mod((p->e).unk_1ca, q->followInterval) == 0) {
      Vec3 prev = (p->e).s->aux.spr.pos;
      s32 i;

      for (i = 0; i < q->segmentCount; i++) {
        if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
          Vec3 cur = q->segments[i].sprite.pos;

          q->segments[i].targetPos = prev;
          prev = cur;
        }
      }
    }
  }
}

void Centipede_WobbleSegments(Centipede* p, s32 amplitude, s32 step, s32 horizontal) {
  Centipede* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
      if (horizontal == 0) {
        q->segments[i].velocity.y += FixToInt(12, SIN(q->segments[i].wobbleAngle) * amplitude);
      } else {
        q->segments[i].velocity.x += FixToInt(12, COS(q->segments[i].wobbleAngle) * amplitude);
        q->segments[i].velocity.z += FixToInt(12, SIN(q->segments[i].wobbleAngle) * amplitude);
      }
      q->segments[i].wobbleAngle += step;
    }
  }
}

// startPos から endPos への曲線上に first から last の手前までの節を等間隔に並べる
// 235/227命令, Sandworm/Serpent/Salamander_PlaceSegmentsOnCurve と同じ Hermite 曲線の壁, 原典は v の項にも 0 の変数を掛け (t3 - t2) を足す, 1回目の下書きで切り上げ
NON_MATCH void Centipede_PlaceSegmentsOnCurve(Centipede* p, Vec3* startPos, Vec3* endPos, s32 first, s32 last) {
#ifdef NONMATCHING_C
  Centipede* q = (p->e).owner;
  WorldPos start = *startPos;
  WorldPos end = *endPos;
  s32 step = Div(1024, last - (first - 1));
  s32 n = 0;
  s32 i;

  for (i = first; i < last; i++) {
    Vec3 d, v, pos;
    s32 t, t2, t3, k, z, m;

    n++;
    t = step * n;
    Vec3_Diff(&d, &end, &start);
    CpuFill32(0, &v, sizeof(v));
    t2 = FixToInt(10, t * t);
    t3 = FixToInt(10, t2 * t);
    z = 0;
    k = z * (t3 - 2 * t2 + t);
    m = v.x * (2 * t3 - 3 * t2 + 1) * z + d.x * (3 * t2 - 2 * t3) + k + (t3 - t2);
    pos.x = start.x + FixToInt(10, m);
    m = v.y * (2 * t3 - 3 * t2 + 1) * z + d.y * (3 * t2 - 2 * t3) + k + (t3 - t2);
    pos.y = start.y + FixToInt(10, m);
    m = v.z * (2 * t3 - 3 * t2 + 1) * z + d.z * (3 * t2 - 2 * t3) + k + (t3 - t2);
    pos.z = start.z + FixToInt(10, m);
    q->segments[i].sprite.pos = pos;
  }
#else
  INCFUNC("asm/func/Centipede_PlaceSegmentsOnCurve.inc");
#endif
}

// 前の節を追う節を targetPos へ 1/followDiv ずつ寄せ, 頭から順に離れすぎた節を 1/4 ずつ引き寄せる, 間に追わない節があれば曲線上に並べ直す
void Centipede_PullSegments(Centipede* p, s32 followDiv, s32 followDistSq) {
  Centipede* q = (p->e).owner;
  Vec3 d1, d2, prev;
  s32 first, count;
  s32 i;

  prev = (p->e).s->aux.spr.pos;
  for (i = 0; i < q->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
      Vec3_Diff(&d1, &q->segments[i].targetPos, &q->segments[i].sprite.pos);
      if (d1.x * d1.x + d1.y * d1.y + d1.z * d1.z > followDistSq) {
        followDiv = followDiv >= 1 ? followDiv : 1;
        q->segments[i].sprite.pos.x += Div(d1.x, followDiv);
        q->segments[i].sprite.pos.y += Div(d1.y, followDiv);
        q->segments[i].sprite.pos.z += Div(d1.z, followDiv);
      }
    }
  }
  Centipede_SyncOcclusionMover(p);
  prev = (p->e).s->aux.spr.pos;
  first = 0xFF;
  count = 0;
  for (i = 0; i < q->segmentCount; i++) {
    if (!Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
      if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW)) {
        if (first != 0xFF) {
          Centipede_PlaceSegmentsOnCurve(p, &prev, &q->segments[i].sprite.pos, first, first + count);
        } else {
          Vec3_Diff(&d2, &prev, &q->segments[i].sprite.pos);
          if (d2.x * d2.x + d2.y * d2.y + d2.z * d2.z > 6724) {
            q->segments[i].sprite.pos.x += Div(d2.x, 4);
            q->segments[i].sprite.pos.y += Div(d2.y, 4);
            q->segments[i].sprite.pos.z += Div(d2.z, 4);
          }
        }
        prev = q->segments[i].sprite.pos;
        first = 0xFF;
        count = 0;
      } else {
        if (first == 0xFF) {
          first = i;
        }
        count++;
      }
    }
  }
  Centipede_FaceSegmentsForward(p);
}

void Centipede_SetAllSegmentsPos(Centipede* p, Vec3* pos) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    p->segments[i].sprite.pos = *pos;
    p->segments[i].targetPos = *pos;
  }
}

void Centipede_InitHitboxes(Centipede* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Centipede_OnHurt, p);
  VEC3_SET(hitSize, 64, 100, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Centipede_OnHit, 0, p);
}

void Centipede_OnReset(Centipede* p) {
  Centipede* q = (p->e).owner;

  q->flags &= (u16)~CENTFLAG_UNK_1;
  q->blockedTimer = 0;
  q->turnTileIdx = 0;
  q->unk_b49 = Random() & 3;
  q->hoverPhase = 0;
  q->footstepDelay = 0;
  Enemy_SetSpritePos(&p->e, &q->homePos);
  (p->e).mover.pos = q->homePos;
  Centipede_ResetRecentTiles(p);
  Centipede_SetAllSegmentsPos(q, &(p->e).mover.pos);
  Centipede_PickNextTile(p);
  ClearMemory((p->e).pathNodePos, 8);
  Enemy_ResetState(&p->e, 0, 0, 2);
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
}

// 頭と奇数番目の節を sin で揺らし, 偶数番目の節を前後の位置の中ほどに置く
// 344/282命令, Sandworm/Serpent/Salamander_SwayBody と同じ Hermite 曲線の壁 (原典は 2*t3=256 と 3*t2=768 をループの外でレジスタに置き, y と z の項に 0 との OR が残る), 1回目の下書きで切り上げ
NON_MATCH void Centipede_SwayBody(Centipede* p) {
#ifdef NONMATCHING_C
  Centipede* q = (p->e).owner;
  Vec3 prev, d, v, pos;
  s32 sign;
  s32 i;

  (p->e).s->aux.spr.pos.x += FixToInt(12, COS(q->swayAngle) * 2);
  (p->e).s->aux.spr.pos.z += FixToInt(12, SIN(q->swayAngle) * 16);
  q->swayAngle += 8;
  sign = 1;
  for (i = 1; i < q->segmentCount - 1; i += 2) {
    q->segments[i].sprite.pos.x += FixToInt(12, SIN(q->segments[i].swayAngle) * 4) * sign;
    q->segments[i].swayAngle += 8;
    sign = -sign;
  }
  prev = (p->e).s->aux.spr.pos;
  for (i = 0; i < q->segmentCount - 1; i += 2) {
    s32 t, t2, t3, k, m;

    Vec3_Diff(&d, &q->segments[i + 1].sprite.pos, &prev);
    CpuFill32(0, &v, sizeof(v));
    t = 512;
    t2 = FixToInt(10, t * t);
    t3 = FixToInt(10, t2 * t);
    k = 0;
    k *= t3 - 2 * t2 + t;
    m = v.x * (2 * t3 - 3 * t2 + 1) + d.x * (3 * t2 - 2 * t3) + k;
    pos.x = prev.x + FixToInt(10, m);
    m = v.y * (2 * t3 - 3 * t2 + 1) + d.y * (3 * t2 - 2 * t3) + k;
    pos.y = prev.y + FixToInt(10, m);
    m = v.z * (2 * t3 - 3 * t2 + 1) + d.z * (3 * t2 - 2 * t3) + k;
    pos.z = prev.z + FixToInt(10, m);
    q->segments[i].sprite.pos = pos;
    prev = q->segments[i + 1].sprite.pos;
  }
#else
  INCFUNC("asm/func/Centipede_SwayBody.inc");
#endif
}

// CENTSEGFLAG_DESTROYED が落ちている節の1つおきに CENTSEGFLAG_FOLLOW を落とす
void Centipede_UnfollowAlternateSegments(Centipede* p) {
  Centipede* q = (p->e).owner;
  CentipedeSegment* segs = q->segments;
  s32 n = 0;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Centipede_TestSegmentFlags(&segs[i], CENTSEGFLAG_DESTROYED)) {
      if (n == 1) {
        n = 0;
      } else {
        CLEAR_FLAGS(segs[i].flags, CENTSEGFLAG_FOLLOW);
        n++;
      }
    }
  }
}

// 節が 3 つ以上残っていれば, 尾から見て最初の壊れていない尾以外の節を壊して煙を出す, 壊せたら TRUE
s32 Centipede_DestroyTailSegment(Centipede* p) {
  Centipede* q = (p->e).owner;
  CentipedeSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft <= 2) {
    return FALSE;
  }
  for (i = q->segmentCount - 1; i >= 0; i--) {
    if (!Centipede_TestSegmentFlags(&segs[i], CENTSEGFLAG_DESTROYED | CENTSEGFLAG_TAIL)) {
      Hitbox_Unregister(&segs[i].hurtbox);
      SET_FLAGS(segs[i].flags, CENTSEGFLAG_DESTROYED);
      q->segmentsLeft--;
      Centipede_EmitSmokeAround(&segs[i].sprite.pos);
      return TRUE;
    }
  }
  return FALSE;
}

// 残っている節を尾から全て壊し, それぞれの位置に煙を出す
void Centipede_DestroyAllSegmentsWithSmoke(Centipede* p) {
  Centipede* q = (p->e).owner;
  CentipedeSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft != 0) {
    for (i = q->segmentCount - 1; i >= 0; i--) {
      if (!Centipede_TestSegmentFlags(&segs[i], CENTSEGFLAG_DESTROYED)) {
        Hitbox_Unregister(&segs[i].hurtbox);
        SET_FLAGS(segs[i].flags, CENTSEGFLAG_DESTROYED);
        q->segmentsLeft--;
        Centipede_EmitSmokeAround(&segs[i].sprite.pos);
      }
    }
  }
}

// 残っている節を尾から全て壊し, 食らい判定を外す
void Centipede_DestroyAllSegments(Centipede* p) {
  Centipede* q = (p->e).owner;
  CentipedeSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft != 0) {
    for (i = q->segmentCount - 1; i >= 0; i--) {
      if (!Centipede_TestSegmentFlags(&segs[i], CENTSEGFLAG_DESTROYED)) {
        Hitbox_Unregister(&segs[i].hurtbox);
        SET_FLAGS(segs[i].flags, CENTSEGFLAG_DESTROYED);
        q->segmentsLeft--;
      }
    }
  }
}

void Centipede_AdvanceSwayIfMoving(Centipede* p, s32 speed) {
  if (speed != 0) {
    ((Centipede*)(p->e).owner)->swayAngle += 4;
  }
}

// jumpVel が速いほど広い向きの範囲へ, 前の節を追う節をばらばらの向きに速さ 12 で散らし, CENTFLAG_UNK_2 が立っていれば音を鳴らして落とす
void Centipede_ScatterSegments(Centipede* p) {
  Centipede* q = (p->e).owner;
  Vec3* vel = &(p->e).jumpVel;
  s32 spread = vel->x * vel->x + vel->y * vel->y + vel->z * vel->z;
  s32 i;

  if (spread > 1024) {
    spread = 0xFF;
  } else if (spread > 128) {
    spread = 0x7F;
  } else {
    spread = 0x3F;
  }
  for (i = 0; i < q->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
      Vec3_SetPolar(&q->segments[i].velocity, Random() & spread, 12);
    }
  }
  if (Centipede_TestFlags(q, CENTFLAG_UNK_2)) {
    PlaySound_082406e0(SONG_980);
    Centipede_ClearFlags(q, CENTFLAG_UNK_2);
  }
}

// 前の節を追っている節を床の高さに合わせる, 床と 256 以上離れていれば頭の高さへ, 潜っていれば床へ, 浮いていれば差の 1/10 ずつ下げる
// 194/193命令, Sandworm_SnapSegmentsToFloor と同じ壁 (原典は節の座標を誘導変数にし, 頭の高さへ戻す3か所を別レジスタで書いて cross-jump させない), 試済: 二重の abs 判定の向き, pos 経由の格納
NON_MATCH void Centipede_SnapSegmentsToFloor(Centipede* p) {
#ifdef NONMATCHING_C
  if (!Enemy_IsDead(&p->e)) {
    Centipede* q = (p->e).owner;
    s32 i;

    if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_20)) {
      for (i = 0; i < q->segmentCount; i++) {
        if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
          Vec3* pos = &q->segments[i].sprite.pos;
          s32 height = TileHeightAt(pos);

          if (pos->y != height) {
            if (pos->y < height) {
              if (abs(height - pos->y) > 255) {
                q->segments[i].sprite.pos.y = (p->e).mover.pos.y;
              } else if (abs(height - pos->y) <= 255) {
                q->segments[i].sprite.pos.y = height;
              } else {
                q->segments[i].sprite.pos.y = (p->e).mover.pos.y;
              }
            } else if (abs(height - pos->y) > 256) {
              q->segments[i].sprite.pos.y = (p->e).mover.pos.y;
            } else {
              q->segments[i].sprite.pos.y += Div(height - pos->y, 10);
            }
          }
        }
      }
    }
  }
#else
  INCFUNC("asm/func/Centipede_SnapSegmentsToFloor.inc");
#endif
}

// 生きている間, 前の節を追う節を velocity だけ動かし, velocity を半分に減らす
void Centipede_ApplySegmentVelocity(Centipede* p) {
  if (!Enemy_IsDead(&p->e)) {
    Centipede* q = (p->e).owner;
    s32 i;

    for (i = 0; i < q->segmentCount; i++) {
      if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_FOLLOW) && !Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
        q->segments[i].sprite.pos.x += q->segments[i].velocity.x;
        q->segments[i].sprite.pos.y += q->segments[i].velocity.y;
        q->segments[i].sprite.pos.z += q->segments[i].velocity.z;
        q->segments[i].velocity.x = FixToInt(1, q->segments[i].velocity.x);
        q->segments[i].velocity.y = FixToInt(1, q->segments[i].velocity.y);
        q->segments[i].velocity.z = FixToInt(1, q->segments[i].velocity.z);
      }
    }
  }
}

void FUN_08137e98(Centipede* p) {
  Centipede* q = (p->e).owner;

  if (Centipede_TestFlags(q, CENTFLAG_UNK_1)) {
    Enemy_ResetState(&p->e, 0, 0, 4);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    (p->e).unk_544 = 180;
    (p->e).unk_1bc = 2;
    Centipede_SetFlags(q, CENTFLAG_UNK_2);
  }
  Centipede_ClearFlags(q, CENTFLAG_UNK_1);
}

void Centipede_OnSegmentHit(Hitbox* a, Hitbox* b, CentipedeSegment* seg) {}

// 節の食らい判定に当たったとき, その節がこのフレームで一番近い当たりならダメージを受けて弾かれる向きを決め, hitSegment として覚える
// 残差は seg を r8 と sl の2本に持ち ArcTan2_8 の向きだけ sl 側で書く形 (129/132命令), 試済: Vec3_Delta の順, 別名の局所変数, 向きを決める inline
NON_MATCH void Centipede_OnSegmentHurt(Hitbox* a, Hitbox* b, CentipedeSegment* seg) {
#ifdef NONMATCHING_C
  Centipede* q = seg->owner;

  if (!Enemy_IsDead(&q->e)) {
    Vec3 d;
    u32 distSq;

    Vec3_Delta(&d, &b->center, &a->center);
    distSq = d.x * d.x + d.z * d.z;
    if (distSq < q->hitDistSq) {
      Hitbox_ApplyDamage(a, b);
      b->iframes = a->iframes;
      b->knockback = a->knockback;
      if (a->flags & HBF_ANGLE) {
        seg->knockbackAngle = a->angle;
      } else if (d.x == 0 && d.z == 0) {
        seg->knockbackAngle = Random();
      } else {
        seg->knockbackAngle = ArcTan2_8(d.x, d.z);
      }
      q->hitDistSq = distSq;
      q->hitSegment = seg;
    }
    FUN_08137e98(q);
  }
#else
  INCFUNC("asm/func/Centipede_OnSegmentHurt.inc");
#endif
}

// hitSegment の節を knockbackAngle の向きへ弾く
void Centipede_KnockBackSegment(Centipede* p) {
  if (p->hitDistSq != 0x7FFFFFFF) {
    CentipedeSegment* seg = p->hitSegment;

    p->hitDistSq = 0x7FFFFFFF;
    Vec3_SetPolar(&seg->velocity, seg->knockbackAngle, seg->hurtbox.knockback);
  }
}

// 節ごとに食らい判定 (防御力は power, 属性なし) と攻撃判定を組む
void Centipede_InitSegmentHitboxes(Centipede* p) {
  Centipede* q = (p->e).owner;
  Vec3 halfSize, offset;
  s32 i;

  VEC3_SET(halfSize, 64, 128, 64);
  VEC3_SET(offset, 0, 128, 0);
  for (i = 0; i < q->segmentCount; i++) {
    CentipedeSegment* seg = &q->segments[i];

    Hitbox_Init(&seg->hurtbox, (p->e).mover.id, HBF_HURTBOX | HBF_ANGLE | HBF_3 | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    Hitbox_SetPowerAndAttributes(&seg->hurtbox, (p->e).power, 0, 0);
    Hitbox_SetPos(&seg->hurtbox, &seg->sprite.pos, 0);
    Hitbox_SetHandler(&seg->hurtbox, Centipede_OnSegmentHurt, seg);
  }
  VEC3_SET(halfSize, 64, 100, 64);
  VEC3_SET(offset, 0, 128, 0);
  for (i = 0; i < q->segmentCount; i++) {
    CentipedeSegment* seg = &q->segments[i];

    Hitbox_Init(&seg->hitbox, (p->e).mover.id, HBF_HITBOX | HBF_ONCE | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    Hitbox_SetAttack(&seg->hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetPos(&seg->hitbox, &seg->sprite.pos, 0);
    Hitbox_SetHandler(&seg->hitbox, Centipede_OnSegmentHit, seg);
  }
}

void Centipede_InitAnims(Centipede* p) {
  Enemy_SetAnimEntry(&p->e, 14, 0, 0);
  Enemy_SetAnimEntry(&p->e, 15, 2, 0);
  Enemy_SetAnimEntry(&p->e, 16, 1, 0);
  Enemy_SetAnimEntry(&p->e, 17, 3, 0);
  Enemy_SetAnimEntry(&p->e, 18, 4, 0);
}

// 歩きアニメのコマの頭で sCentipedeMoveSpeeds の速さを返し, コマの途中は 0
s32 Centipede_GetMoveSpeed(Centipede* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (anim->tick == 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    return sCentipedeMoveSpeeds[anim->cmdIdx & 3];
  }
  return 0;
}

// 生きている間, 跳ぶ先が高い段差や壁, 水場なら跳ぶのをやめ, 進めないまま 30 フレームより長く経ったら次の行き先を選んで向き直る
void Centipede_KeepOnGround(Centipede* p) {
  if (!Enemy_IsDead(&p->e)) {
    Centipede* q = (p->e).owner;
    WorldPos next;
    s32 idx;
    u32 attr;
    s32 height;

    Centipede_AddVelocity(&next, &(p->e).mover.pos, &(p->e).jumpVel);
    idx = GetCollisionTileIdx(&next);
    attr = TileAttrAtIndex(idx);
    height = TileHeightAtIndex(idx, &next);
    if ((p->e).floorY < height || (attr & (TATTR_FALLDEATH | 3))) {
      (p->e).jumpVel.x = 0;
      (p->e).jumpVel.z = 0;
    }
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
    if ((p->e).mover.tile->unk_0[0] & 1) {
      if (++q->blockedTimer > 30) {
        q->unk_b49 = (q->unk_b49 + 1) & 3;
        Centipede_PickNextTile(p);
        Vec3_Delta(&next, &(p->e).mover.pos, &(p->e).navAgent->dest);
        (p->e).unk_1dc = ArcTan2_8(next.x, next.z);
        if (abs(Centipede_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
          Enemy_ResetState(&p->e, 0, 0, 1);
        }
      }
    } else {
      q->blockedTimer = 0;
    }
  }
}

// pos から6方向へ煙を出して音を鳴らす
void Centipede_EmitSmokeAround(WorldPos* pos) {
  Vec3 size;

  VEC3_SET(size, 80, 60, 60);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0x40, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0x80, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0xF0, 4, 20, 2, 1);
  PlaySound_082406e0(SE_UNDEAD_EXORCISM);
}

// unk_544 が 0 なら歩きアニメを速く, 60 以上なら遅くし, 地面にいれば 24 フレームごとに足音を鳴らす
void Centipede_UpdateAnimSpeed(Centipede* p) {
  if (!Enemy_IsDead(&p->e)) {
    Centipede* q = (p->e).owner;

    if ((p->e).unk_544 != 0) {
      if ((p->e).unk_544 < 60) {
        (p->e).animSpeedDiv = 2;
      } else {
        if ((p->e).heightAboveFloor == 0 && (p->e).jumpVel.y == 0) {
          if (q->footstepDelay != 0) {
            q->footstepDelay--;
          } else if (Mod((p->e).unk_544, 24) == 0) {
            PlaySound_082406e0(SONG_984);
          }
        }
        (p->e).animSpeedDiv = 3;
      }
    } else {
      (p->e).animSpeedDiv = 1;
    }
  }
}

void Centipede_ResetRecentTiles(Centipede* p) {
  Centipede* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    q->recentTiles[i] = (p->e).tileIdx;
  }
  q->recentTileIdx = 0;
}

bool8 Centipede_IsRecentTile(Centipede* p, u32 tileIdx) {
  Centipede* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    if (q->recentTiles[i] == tileIdx) {
      return TRUE;
    }
  }
  return FALSE;
}

void Centipede_AddRecentTile(Centipede* p, u32 tileIdx) {
  Centipede* q = (p->e).owner;

  q->recentTiles[q->recentTileIdx] = tileIdx;
  q->recentTileIdx = (q->recentTileIdx + 1) & 3;
}

void Centipede_OnAttackRequest(Centipede* p) {
  Enemy_ResetState(&p->e, 0, 2, 0);
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
}

void FUN_08138808(Centipede* p) {}

// 範囲内のプレイヤーが正面の 1/4 にいて高さの差も小さければ, 向きをプレイヤーの方へ決めて TRUE
bool8 Centipede_TryDetectPlayer(Centipede* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    u32 range;

    (p->e).flags &= ~ENEFLAG_UNK_3;
    if ((p->e).state == ES_UNK_38) {
      range = (p->e).unk_1e8 * 2;
    } else {
      range = (p->e).unk_1e8;
    }
    if ((p->e).playerDistSq <= range) {
      Vec3 diff;

      Vec3_Delta(&diff, &(p->e).mover.pos, &(p->e).playerMover->pos);
      if ((((ArcTan2_8(diff.x, diff.z) + 16) & 0xFF) >> 6) == ((((p->e).mover.angle + 16) & 0xFF) >> 6) && abs(diff.y) <= 511) {
        Centipede* q = (p->e).owner;

        q->unk_b49 = (((p->e).playerAngle + 0x80) & 0xFF) >> 6;
        q->unk_b48 = 14;
        return TRUE;
      }
    }
  }
  return FALSE;
}

// ENEFLAG3_UNK_8 に合わせて攻撃判定の威力を atk の [0] か [1] に切り替える
void Centipede_SelectAttack(Centipede* p) {
  if (!Enemy_IsDead(&p->e) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP | ENEFLAG3_STUN | ENEFLAG3_PETRIFIED | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      Hitbox_ClearFlags(&(p->e).hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      Hitbox_SetFlags(&(p->e).hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
}

// 生きている間, 壊れていない節の食らい判定を載せ, プレイヤーが近い節だけ攻撃判定も載せて ENEFLAG3_UNK_8 で atk の [0] / [1] を選ぶ
void Centipede_UpdateHitboxes(Centipede* p) {
  Centipede* q = (p->e).owner;
  Vec3 d;
  s32 i;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  for (i = 0; i < q->segmentCount; i++) {
    if (Centipede_TestSegmentFlags(&q->segments[i], CENTSEGFLAG_DESTROYED)) {
      continue;
    }
    Hitbox_SetPos(&q->segments[i].hurtbox, &q->segments[i].sprite.pos, 0);
    Hitbox_Register(&q->segments[i].hurtbox);
    Vec3_Delta(&d, &q->segments[i].sprite.pos, &gPlayerPtr[0]->mover.pos);
    if (d.x * d.x + d.z * d.z > 0xFFFF) {
      continue;
    }
    Hitbox_SetPos(&q->segments[i].hitbox, &q->segments[i].sprite.pos, 0);
    Hitbox_Register(&q->segments[i].hitbox);
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
      Hitbox_ClearFlags(&q->segments[i].hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&q->segments[i].hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      Hitbox_SetFlags(&q->segments[i].hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&q->segments[i].hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
}

// 105/124命令, Sandworm の FUN_0817a05c, Serpent の FUN_08193ca4 と同じ壁 (原典は jumpVel.x と jumpVel.z の abs を r3/r2 に求めて捨てる), 試済: 同じ呼び出しの if/else で分岐を cross-jump に畳ませる (abs が比較ごと残る)
NON_MATCH void FUN_08138b34(Centipede* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Centipede_StateHover, ES_UNK_34);
    (p->e).unk_1bc = 8;
  }
  Centipede_PullSegments(p, 4, 0x6400);
  Centipede_UpdateWave(p, 430, 40);
  if ((p->e).subStateDone) {
    Centipede_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08138b34.inc");
#endif
}

void Centipede_SetHandlerTable4(Centipede* p) { (p->e).handlerTables[4] = (void*)sCentipedeHandlerTable4; }

s32 Centipede_PreUpdate(Centipede* p) {
  Centipede_KnockBackSegment(p);
  return 1;
}

s32 Centipede_PostUpdate(Centipede* p) {
  Centipede_UpdateHitboxes(p);
  Centipede_SelectAttack(p);
  Centipede_UpdateAnimSpeed(p);
  Centipede_HideDestroyedSegments(p);
  Centipede_FollowSegments(p);
  Centipede_ApplySegmentVelocity(p);
  Centipede_SnapSegmentsToFloor(p);
  Centipede_KeepOnGround(p);
  return 1;
}

// hp が残る被弾への反応, 無敵時間を延ばして減った hp の分だけ尾の節を壊し, プレイヤーの方へ向き直って副状態 5 へ移る
bool8 Centipede_OnDamaged(Centipede* p) {
  Centipede* q = (p->e).owner;

  PlaySound_082406e0(SONG_412);
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  SET_FLAGS(q->flags, CENTFLAG_UNK_2);
  (p->e).unk_544 = 240;
  (p->e).hurtbox.iframes += 30;
  q->footstepDelay = 16;
  CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
  {
    Centipede* owner = (p->e).owner;
    s32 n;

    for (n = Div((p->e).hp, owner->hpPerSegment); n < owner->segmentsLeft; n++) {
      Centipede_DestroyTailSegment(p);
    }
  }
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  Enemy_ResetState(&p->e, 0, 0, 5);
  (p->e).mover.angle = (p->e).playerAngle;
  (p->e).animSpeedDiv = 1;
  return TRUE;
}

s32 Centipede_UpdateFrame(Centipede* p) {
  Centipede_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Centipede_PostUpdate(p);
  return 1;
}

s32 Centipede_Update(Centipede* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

s32 Centipede_Destroy(Centipede* p) {
  Centipede_RemoveSegmentSprites(p);
  Centipede_RemoveOcclusionMover(p);
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove(&(p->e).s->aux.spr);
  } else {
    MainSprite_Remove(&(p->e).s->main.spr);
  }
  Free((p->e).s);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).shadowRemoved) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).shadowRemoved = 1;
  }
  if (!(p->e).emitterRemoved) {
    ElementalCondEmitter_Destroy(&(p->e).emitter);
    (p->e).emitterRemoved = 1;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a58(&(p->e).mover);
  }
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
// 1731/1898命令の下書き, Sandworm/Serpent/Salamander_Init と同じ敵共通 inline の壁 (原典はフィールドの番地をスタックに作り置く), 1回目の下書きで切り上げ
NON_MATCH s32 Centipede_Init(Centipede* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  p->flags = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_CENTIPEDE;
  Centipede_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPR_WORM);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_WORM);
    k = (p->e).kind;
    if (k == ENEK_CURORO || k == ENEK_GHOST) {
      aux->spr.priority = 1;
    }
    (p->e).facing = 0;
  } else {
    EnemyMainSprite* spr;
    MainSpriteGfxFile* f;
    Vec3 origin;

    (p->e).s = Malloc(sizeof(EnemySprite));
    ClearMemory((p->e).s, sizeof(EnemySprite));
    spr = &(p->e).s->main;
    Vec3_Clear(&origin);
    f = GetFile(DIR_MAIN_SPRITE, SPR_WORM);
    spr->gfx = *f;
    OpenMainSpriteFile(&spr->gfx, f);
    MainSprite_Add(&spr->spr, &spr->gfx, 0, 0, 2, 2, 60, &origin);
    (p->e).playingAnim = 0xFF;
  }

  (p->e).flags = 0;
  (p->e).flags2 = 0;
  (p->e).unk_46f = 0;
  (p->e).unk_1bc = 8;
  (p->e).flags5 = VM_GetNamedArgValue('M', 0);
  Vec3_Clear(&pos);
  (p->e).unk_4b6 = 0;
  if (!VM_SeekToNamedArg('r')) {
    (p->e).unk_250 = 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = 0;
    (p->e).prevPathNode = 0;
    (p->e).unk_4b4[(p->e).unk_4b6] = 0;
    (p->e).unk_4b4[(p->e).unk_4b6 ^ 1] = 0;
    onPath = FALSE;
  } else {
    u8 sel;

    (p->e).unk_250 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).prevPathNode = (p->e).unk_252;
    (p->e).unk_4b4[(p->e).unk_4b6] = (p->e).unk_250;
    sel = (p->e).unk_4b6;
    (p->e).unk_4b4[sel ^ 1] = VM_GetPC() != NULL ? VM_GetValue() : (p->e).unk_250;
    Map_GetPathNodePos(&pos, (p->e).unk_250, (p->e).unk_252);
    (p->e).tileIdx = GetCollisionTileIdx(&pos);
    pos.y = TileHeightAt(&pos);
    (p->e).floorY = pos.y;
    onPath = TRUE;
  }

  id = VM_GetNamedArgValue('N', 0);
  if (!VM_SeekToNamedArg('e')) {
    range0 = 48;
    range3 = 64;
  } else {
    range0 = VM_GetPC() != NULL ? VM_GetValue() : 48;
    range3 = VM_GetPC() != NULL ? (u8)VM_GetValue() : 64;
  }
  if (!VM_SeekToNamedArg('n')) {
    range1 = 0;
    (p->e).unk_1fe = 0;
  } else {
    range1 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_1fe = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  range2 = range0;

  if (VM_SeekToNamedArg('a')) {
    for (i = 0; i < 4; i++) {
      (p->e).atkPower[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkKnockback[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkAttrs[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      (p->e).atkIframes[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  if (!VM_SeekToNamedArg('l')) {
    hpParam3 = 0;
    hpParam4 = 0;
    (p->e).chaseTimeMax = 0;
  } else {
    hpParam3 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    hpParam4 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    (p->e).chaseTimeMax = VM_GetPC() != NULL ? VM_GetValue() : 300;
  }
  if (VM_GetNamedArgValue('b', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_9);
  }
  (p->e).scriptID = VM_GetNamedArgValue('F', 0);
  (p->e).unk_194 = VM_GetNamedArgValue('R', 0);
  if (VM_SeekToNamedArg('A')) {
    (p->e).maxHp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_546 = (p->e).maxHp >> 1;
    (p->e).power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_187 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_188 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).attrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weakness = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  Enemy_InitHpAndState(&p->e, (p->e).maxHp, hpParam3, hpParam4);
  Enemy_SetRanges(&p->e, 0, range0, range2, range1, range3);
  if (VM_SeekToNamedArg('X')) {
    (p->e).exp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weaponExp = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  (p->e).unk_25a = VM_GetNamedArgValue('K', 2);
  if (VM_GetNamedArgValue('H', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_11);
  }
  if (VM_GetNamedArgValue('L', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_15);
  }

  Mover_Init(&(p->e).mover, id, &pos, 0, MOVER_ENEMY, p);
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, Enemy_OnCWolfMessage);
  }
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? &(p->e).s->aux.spr : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 64, 64);
  }
  kind = (p->e).kind;
  if (kind != ENEK_BAT && kind != ENEK_CROW && kind != ENEK_MIMIC && kind != ENEK_SLIME && kind != ENEK_BEE && kind != ENEK_CENTIPEDE && kind != ENEK_SANDWORM && kind != ENEK_SERPENT && kind != ENEK_AX && kind != ENEK_SHAIAN && kind != ENEK_SALAMANDER) {
    Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_250, (p->e).unk_251, (p->e).unk_252);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_3)) {
    (p->e).unk_1e8 = Div((p->e).range0Sq * 7, 10);
  } else {
    (p->e).unk_1e8 = (p->e).range0Sq;
  }
  (p->e).zoneSource.id = (p->e).mover.id;
  (p->e).zoneSource.pos = &(p->e).mover.pos;
  if (onPath) {
    (p->e).mover.angle = ((((p->e).pathWalker.node->delay >> 12 & 7) + 5) & 7) << 5;
  }
  if (VM_SeekToNamedArg('p')) {
    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).tileIdx = GetCollisionTileIdx(&(p->e).mover.pos);
    (p->e).floorY = TileHeightAtIndex((p->e).tileIdx, &(p->e).mover.pos);
    (p->e).heightAboveFloor = (p->e).mover.pos.y - (p->e).floorY;
    (p->e).mover.pos.y = (p->e).floorY;
    p->homePos = (p->e).mover.pos;
  }
  if (VM_SeekToNamedArg('P')) {
    p->hoverTime = VM_GetPC() != NULL ? VM_GetValue() : 300;
  }
  Centipede_ResetRecentTiles(p);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 417;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 417;
  if ((p->e).spriteKind == 0) {
    Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + (p->e).variant);
  } else {
    (p->e).s->main.spr.pltt = &gObjPlttData[((p->e).plttBase + (p->e).variant) * 16];
  }
  if ((p->e).spriteKind == 1) {
    s16 n;

    if ((p->e).kind >= ENEK_SKELETON && (p->e).kind <= ENEK_LICH) {
      n = Enemy_CountByKind(ENEK_SKELETON) + 1 + Enemy_CountByKind(ENEK_SKELETON_F) + Enemy_CountByKind(ENEK_SKELETON_A) + Enemy_CountByKind(ENEK_LICH);
    } else {
      n = Enemy_CountByKind((p->e).kind) + 1;
    }
    (p->e).s->main.spr.plttID = n + 220;
  }

  Centipede_InitHitboxes(p);
  Centipede_InitFollowInterval(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Centipede_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Centipede_GetMoveSpeed;
  (p->e).handlerTurn = Centipede_StateTurn;
  (p->e).handlerMove = Centipede_StateMove;
  (p->e).handlerWait = Centipede_StateWait;
  (p->e).handlerNap = Centipede_StateNap;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Centipede_StateDamaged;
  (p->e).handlerDying = Centipede_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = Centipede_StateRespawnWait;
  (p->e).unk_604 = FUN_080f62ac;
  (p->e).tryDetectPlayer = FUN_080f0430;
  (p->e).unk_21d = 1;
  (p->e).msgHandlers = (void*)gEnemyDefaultMsgHandlers;
  (p->e).unk_5f0 = FUN_080e73c8;
  (p->e).unk_5e4 = NULL;
  (p->e).onReset = NULL;
  (p->e).unk_5fc = NULL;
  (p->e).unk_600 = NULL;
  (p->e).unk_614 = NULL;
  (p->e).unk_618 = FUN_080f0320;
  (p->e).handlerLookAround = Enemy_080eff14;
  (p->e).unk_5e8 = FUN_080e72b0;
  (p->e).unk_5e0 = Centipede_ClearStateBegun;
  (p->e).unk_5ec = Enemy_StateBlownAway;
  (p->e).unk_5d8 = Enemy_StateFallDeath;
  (p->e).unk_5a8 = NULL;
  (p->e).unk_624 = FUN_080f6e64;
  (p->e).onDamaged = Enemy_OnDamaged;
  (p->e).unk_628 = (void*)FUN_080f84d4;
  (p->e).handlerChase = FUN_080f624c;
  (p->e).handlerStun = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  (p->e).onReset = (EnemyHandler)Centipede_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).onAttackRequest = (EnemyHandler)Centipede_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)FUN_08138808;
  (p->e).tryDetectPlayer = (void*)Centipede_TryDetectPlayer;
  (p->e).onDamaged = (void*)Centipede_OnDamaged;
  (p->e).unk_5b4 = (EnemyHandler)Centipede_ScatterSegments;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9 | ENEFLAG_UNK_20);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_6);
  Enemy_InitShadowAndEmitter(&p->e);

  (p->e).unk_198 = VM_GetNamedArgValue('I', 0);
  if (VM_SeekToNamedArg('G')) {
    u32* arg = &(p->e).unk_19c;

    for (i = 0; i < 5; i++) {
      *arg++ = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  (p->e).defeatScriptID = VM_GetNamedArgValue('D', 0);
  {
    s32 u = VM_GetNamedArgValue('u', 0);

    (p->e).unk_496[0] = 0x21;
    (p->e).unk_496[1] = 0;
    if (u != 0) {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_18);
      if (u == 2) {
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_18 | ENEFLAG_UNK_19);
      }
    }
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_2)) {
    Enemy_ResetState(&p->e, 0, 0, 0);
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  } else {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_13);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_1)) {
    (p->e).zoneID = GetZoneAt(&(p->e).mover.pos);
  } else {
    (p->e).zoneID = gStat->zoneID;
  }
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_6)) {
    (p->e).hurtbox.flags &= ~HBF_ANGLE;
  }
  if (VM_GetNamedArgValue('S', 0) != 0 || gStat->zoneID != (p->e).zoneID) {
    Enemy_Suspend(&p->e, NULL);
  }
  Enemy_PlayAnim(&p->e, 0);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux = &(p->e).s->aux;

    AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
  } else {
    MainSprite_AdvanceAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx);
  }
  (p->e).hitTargetID = 0;
  kind = (p->e).kind;
  if (!IsLinkPlay() && (kind == ENEK_BOKU || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DOG || kind == ENEK_BEE || kind == ENEK_GHOST)) {
    MsgQueue_Register(&(p->e).mq, (p->e).mover.id, 3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_8);
  }
  Centipede_PickNextTile(p);
  Enemy_ResetState(&p->e, 0, 0, 2);
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  Enemy_InitHandlerTables(&p->e);
  Centipede_SetHandlerTable2(p);
  Centipede_SetHandlerTable4(p);
  Centipede_InitSegments(p, SPR_WORM, ANIM_WORM, (p->e).mover.angle);
  Centipede_SetAllSegmentsPos(p, &(p->e).mover.pos);
  Centipede_InitSegmentHitboxes(p);
  Centipede_PickNextTile(p);
  Centipede_AddOcclusionMover(p);
  (p->e).initFlags5 = (p->e).flags5;
  (p->e).initHeightAboveFloor = (p->e).heightAboveFloor;
  (p->e).initFlags = (p->e).flags;
  (p->e).initFlags2 = (p->e).flags2;
  (p->e).initAngle = (p->e).mover.angle;
  (p->e).initSubState0 = (p->e).subState0;
  (p->e).initSubState1 = (p->e).subState1;
  (p->e).initSubState2 = (p->e).subState2;
  (p->e).initHandlerState = (p->e).handlerState;
  (p->e).initState = (p->e).state;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)Centipede_Update;
  (p->e).handlerDestroy = (EnemyHandler)Centipede_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Centipede_Init.inc");
#endif
}

// 0x0AC7, HashName("センチビート")
void Centipede_Create(void) {
  Centipede* p = Malloc(sizeof(Centipede));

  if (p != NULL) {
    ClearMemory(p, sizeof(Centipede));
    if (Centipede_Init(p) < 0) {
      Centipede_Destroy(p);
      Free(p);
    }
  }
}

// プレイヤーへ向けて水平に 32 の速さで跳ね, 着くまでの時間から縦の速さを決める
void Centipede_AimJumpAtPlayer(Centipede* p) {
  EnemyAuxSprite* s = &(p->e).s->aux;
  Vec3 diff;
  s32 angle;
  s32 t;

  Vec3_Delta(&diff, &s->spr.pos, &gPlayerPtr[0]->mover.pos);
  angle = ArcTan2_8(diff.x, diff.z);
  (p->e).jumpVel.x = POLAR_X(32, angle);
  (p->e).jumpVel.z = POLAR_Z(32, angle);
  if ((p->e).jumpVel.x != 0) {
    t = Div(diff.x, (p->e).jumpVel.x);
  } else if ((p->e).jumpVel.z != 0) {
    t = Div(diff.z, (p->e).jumpVel.z);
  } else {
    t = 0;
  }
  (p->e).jumpVel.y = FixToInt(1, t);
}

void Centipede_SetSegmentPos(Centipede* p, s32 idx, Vec3* pos) { p->segments[idx].sprite.pos = *pos; }
