#include "cwolf_target.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "global.h"
#include "link_session.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "vm.h"

struct Sandworm;

// SandwormSegment.flags (0x0FD)
typedef u8 SandwormSegmentFlags;
#define SANDSEGFLAG_DESTROYED (1 << 0)  // 0x01, 壊れた節
#define SANDSEGFLAG_FOLLOW (1 << 1)     // 0x02, 1つ前の節の位置を引き継ぐ
#define SANDSEGFLAG_UNK_2 (1 << 2)      // 0x04, 尾の節, アニメ 7
#define SANDSEGFLAG_UNK_3 (1 << 3)      // 0x08, 後ろの節 (5 番から尾の手前まで), アニメ 6 の variant 2
#define SANDSEGFLAG_UNK_4 (1 << 4)      // 0x10, 中の節 (3, 4 番), アニメ 6 の variant 1
#define SANDSEGFLAG_UNK_5 (1 << 5)      // 0x20, 前の節 (0..2 番), アニメ 6 の variant 0
#define SANDSEGFLAG_FLASH (1 << 6)      // 0x40, 被弾して白く光っている
#define SANDSEGFLAG_UNK_7 (1 << 7)      // 0x80

// サンドウォームの体の節1つ, SerpentSegment と同じ大きさで flags が u8 になった形
typedef struct {
  AuxSprite sprite;            // 0x000
  AuxSpriteGfx gfx;            // 0x02C, ID は固定でない
  Hitbox hitbox;               // 0x048, 節ごとの攻撃判定
  Hitbox hurtbox;              // 0x098, 節ごとの食らい判定
  AuxAnimState anim;           // 0x0E8
  AuxAnimFile* animFile;       // 0x0F8, ID は固定でない
  u8 angle;                    // 0x0FC, 節の向き
  SandwormSegmentFlags flags;  // 0x0FD
  u8 unk_fe[2];                // 0x0FE
  u8 knockbackAngle;           // 0x100, 弾かれる向き
  u8 swayAngle;                // 0x101
  u8 wobbleAngle;              // 0x102
  u8 flashTimer;               // 0x103
  u8 unk_104[8];               // 0x104
  Vec3 targetPos;              // 0x10C, 1つ前の節の位置, sprite.pos がここへ寄っていく
  Vec3 velocity;               // 0x114
  struct Sandworm* owner;      // 0x11C
  u16 unk_120;                 // 0x120
  u8 unk_122[2];               // 0x122
} SandwormSegment;
static_assert(sizeof(SandwormSegment) == 292);

// Sandworm.flags (0x1008)
typedef u16 SandwormFlags;
#define SANDFLAG_OCCLUSION (1 << 0)  // 0x01, occlusionMover を OcclusionMask に載せている
#define SANDFLAG_UNK_1 (1 << 1)      // 0x02, 立っていると副状態 (0, 0, 4) へ移して落とす
#define SANDFLAG_UNK_2 (1 << 2)      // 0x04, 立っていると攻撃判定に atk の [1] を載せ, HBF_ANGLE を外す
#define SANDFLAG_UNK_3 (1 << 3)      // 0x08, 着地して地中へ潜り始めると立つ
#define SANDFLAG_UNK_4 (1 << 4)      // 0x10, 立っていると移動の跡を床に残す
#define SANDFLAG_DYING (1 << 5)      // 0x20, 立っていると受けたダメージを damageAccum に足さない
#define SANDFLAG_UNK_6 (1 << 6)      // 0x40, 節の食らい判定に当たるたびに立つ
#define SANDFLAG_UNK_7 (1 << 7)      // 0x80, Sandworm_SubLeap で跳んでから着地するまで立つ
#define SANDFLAG_UNK_8 (1 << 8)      // 0x100

// 中ボス, ENEK_SANDWORM(ENEID_SANDWORM), Serpent と同じく節を連ねた体を持つ
// マミー(mummy.c)と同様に視覚を持たず聴覚のみで敵を感知(その分、聴覚は鋭い)
// 技名: 接触, 体当たり, 尻尾攻撃, 岩
typedef struct Sandworm {
  Enemy e;
  u8 unk_654[4];                // 0x654
  SandwormSegment segments[8];  // 0x658
  Vec3 wanderTarget;            // 0xF78
  Vec3 wanderBase;              // 0xF80
  u16 wanderTimer;              // 0xF88
  u8 unk_f8a;                   // 0xF8A
  u8 unk_f8b;                   // 0xF8B
  Vec3 lastTrailPos;            // 0xF8C, 最後に跡を残した位置
  u16 tunnelTimer;              // 0xF94, Sandworm_SubTunnel の残りフレーム数, tunnelTime から数え下ろす
  s8 unk_f96;                   // 0xF96
  s8 diveCount;                 // 0xF97, 地中へ潜り終えるたびに 1 増える, 4 を超えると潜るのをやめる
  u16 unk_f98;                  // 0xF98, 40, hp が unk_546 を上回っていれば 80
  u16 wanderTime;               // 0xF9A, Sandworm_SubWander でうろつくフレーム数, 220 / 600
  u16 wormMoveTime0;            // 0xF9C, 呼ぶワームの尻尾 (WormTail) の pattern 0 の moveTime, 30 / 80
  u16 wormMoveTime1;            // 0xF9E, 呼ぶワームの pattern 1 の moveTime, 64 / 100
  u16 wormEmergeDelay0;         // 0xFA0, 呼ぶワームの pattern 0 の emergeDelay, 8 / 40
  u16 wormEmergeDelay1;         // 0xFA2, 呼ぶワームの pattern 1 の emergeDelay, 10 / 30
  u16 tunnelTime;               // 0xFA4, tunnelTimer の初期値, 100..163 / 200..263
  u16 unk_fa6;                  // 0xFA6, 1 / 3
  u16 scriptID;                 // 0xFA8, '.d'
  u16 damageAccum;              // 0xFAA, 受けたダメージの累計
  u8 followInterval;            // 0xFAC, 節が1つ前の節の位置を引き継ぐ間隔 (フレーム)
  u8 hoverPhase;                // 0xFAD
  u8 unk_fae[2];                // 0xFAE
  u16 crawlTimer;               // 0xFB0, Sandworm_SubCrawl で進んだフレーム数, 60 を超えると副状態 18 へ移る
  u16 tailDefense;              // 0xFB2, '.P', 尾の節の食らい判定の防御力, 他の節はこの 2 倍
  u8 recentTileIdx;             // 0xFB4, recentTiles の次に書く添字
  u8 blockedTimer;              // 0xFB5, 進めずに止まっているフレーム数
  u16 turnTileIdx;              // 0xFB6
  u16 recentTiles[6];           // 0xFB8, 最近通ったタイルの索引
  Mover occlusionMover;         // 0xFC4, SANDSEGFLAG_UNK_2 の節に付けて OcclusionMask に載せる Mover, id は mover.id + 1
  SandwormFlags flags;          // 0x1008
  u8 swayAngle;                 // 0x100A
  u8 shiftTimer;                // 0x100B
  s8 waveDir;                   // 0x100C
  u8 unk_100d[3];               // 0x100D
  s16 waveOffset;               // 0x1010
  s16 segmentCount;             // 0x1012, 節の数
  u8 unk_1014[8];               // 0x1014
  u16 unk_101c;                 // 0x101C
  u8 unk_101e;                  // 0x101E
  u8 unk_101f;                  // 0x101F
  u8 unk_1020;                  // 0x1020
  u8 unk_1021;                  // 0x1021
  u8 segmentsLeft;              // 0x1022, 壊れていない節の数
  u8 hpPerSegment;              // 0x1023
  s32 unk_1024;                 // 0x1024
  SandwormSegment* unk_1028;    // 0x1028
  NavAgent navAgent;            // 0x102C, Enemy.navAgent が指す
  Vec3 pathNodePos;             // 0x1050, Enemy.pathNodePos が指す
  Vec3 turnTilePos;             // 0x1058, turnTileIdx のタイルの中心
  Vec3 homePos;                 // 0x1060, 生成時の mover.pos
} Sandworm;
static_assert(sizeof(Sandworm) == 4200);

// anim 番の variant を流す, MainSprite では anim + variant 番を flags の向きと逆再生で流し, 同じものが流れていれば何もしない
static inline void Sandworm_PlayDirAnim(Sandworm* p, u32 anim, u32 variant, u32 flags) {
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

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

// a - b を -128..128 に丸めた角度の差
static inline s32 Sandworm_AngleDiff(s32 a, s32 b) {
  s32 d = a - b;

  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  return d;
}

// angle が target まで回りきった (差が 32 未満) なら TRUE
static inline bool32 Sandworm_IsTurnedTo(s32 target, s32 angle) {
  if (Sandworm_AngleDiff(target, angle) < 32) return TRUE;
  return FALSE;
}

// pos に vel を足した位置を out に入れる
static inline void Sandworm_AddVelocity(Vec3* out, Vec3* pos, Vec3* vel) {
  out->x = vel->x + pos->x;
  out->y = vel->y + pos->y;
  out->z = vel->z + pos->z;
}

// cur のタイルから dir の向きの隣 next へ進めるなら next を, 進めないなら -1 を返す, 階段は上り下りの向きと段差が合うときだけ通す
static inline s32 Sandworm_CheckStep(s32 cur, s32 next, s32 dir) {
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

// tile の dir の向きの隣のタイルの索引
static inline s32 Sandworm_NeighborTile(s32 tile, s32 dir) {
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

static inline bool8 Sandworm_TestSegmentFlags(SandwormSegment* seg, SandwormSegmentFlags bit) {
  if (seg->flags & bit) return TRUE;
  return FALSE;
}

static inline void Sandworm_SetFlags(Sandworm* p, SandwormFlags bit) { p->flags |= bit; }
static inline void Sandworm_ClearFlags(Sandworm* p, SandwormFlags bit) { p->flags &= ~bit; }

static inline bool8 Sandworm_TestFlags(Sandworm* p, SandwormFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

void Sandworm_SetSegmentPos(Sandworm* p, s32 idx, Vec3* pos);
s32 Enemy_UpdateMovement(Enemy* p);
s32 FUN_080e1f48(Enemy* p);
s32 Enemy_UpdateHitboxes(Enemy* p);
bool32 Enemy_ProcessRequests(Enemy* p);
bool32 Enemy_ShakeSprite(Enemy* p);
void FUN_080f06ac(Enemy* p);
void HUD_ShowEnemyGauge(s32 moverID, s32 hp, u16 maxHP, u16 cells, s32 flash);
void Sandworm_AnimateSegments(Sandworm* p, s32 idx);
void Sandworm_GetAnimVariant(u16 angle, u32* variant, u32* xflip);
void Sandworm_ResetRecentTiles(Sandworm* p);
void Sandworm_StateHover(Sandworm* p, s32 timer);
void Sandworm_StatePounce(Sandworm* p);
void Sandworm_StateLand(Sandworm* p, s32 timer);
void Sandworm_AnimateSegments2(Sandworm* p, s32 param_2);
void Sandworm_AimJumpAtPlayer(Sandworm* p);
void Sandworm_FlashSegment(SandwormSegment* seg);
void Sandworm_StateFall(Sandworm* p);
void Sandworm_PickNextTile(Sandworm* p);
s32 Sandworm_DestroyTailSegment(Sandworm* p);
void Sandworm_StateWakeUp(Sandworm* p, s32 timer);
void Sandworm_StateRespawn(Sandworm* p);
void Sandworm_OnReset(Sandworm* p);
void Entity081f7974_Spawn(Vec3* pos, s32 delay);
void Sandworm_ScatterParticles(Vec3* pos, s32 count);
void Sandworm_DestroyAllSegmentsWithParticles(Sandworm* p);
void EnemyRespawnInfo_Add(u16 a, u16 b);
void Enemy_AddKillCount(Enemy* p);
void Sandworm_AdvanceSwayIfMoving(Sandworm* p, s32 speed);
void Sandworm_UpdateWave(Sandworm* p, s32 amplitude, s32 speed);
void Sandworm_ResetWave(Sandworm* p);
void Sandworm_RestartSegmentAnims(Sandworm* p, s32 idx, s32 variant, s32 flags);
void Sandworm_SetSegmentVelocity(Sandworm* p, Vec3* velocity, s32 idx);
void Sandworm_RunScript(Sandworm* p);
void Sandworm_LeaveTrail(Sandworm* p);
void Sandworm_HideLiveSegments(Sandworm* p);
void Sandworm_ThrowRocksUp(Sandworm* p, Vec3* pos);
bool8 Sandworm_TrySummonWorms(Sandworm* p);
void FUN_081719b8(Sandworm* p);
bool8 Sandworm_IsRecentTile(Sandworm* p, u32 tileIdx);
void Sandworm_AddRecentTile(Sandworm* p, u32 tileIdx);
void FUN_081719b4(Sandworm* p);
s32 Sandworm_UpdateSegmentsBuried(Sandworm* p);
void Sandworm_ThrowRocks(Sandworm* p, Vec3* pos);
void Sandworm_SetAllSegmentsPos(Sandworm* p, Vec3* pos);
s8 NoiseManager_FindFirstHeardNoise(s32 x, s32 y, s32 size, u8 mask, u16 moverID);
void FUN_080e8f20(Enemy* p, s32 param_2);
bool8 WormTail_IsIdle(void);
void WormTail_RequestDive(void);
s32 Entity081efa9c_Spawn(Vec3* pos, Vec3* vel, u32 spriteID, u32 animID, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12, s32 param_13, s32 param_14, s32 param_15);
void WormTail_Spawn(Vec3* pos, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 moveTime, s32 unk_6, s32 unk_7, s32 emergeDelay, s32 pattern, u32 defense, HitboxAttrs hurtAttrs, u32 weakness);
void Sandworm_PullSegments(Sandworm* p, s32 followDiv, s32 linkDiv, s32 followDistSq);
void Sandworm_WobbleSegments(Sandworm* p, s32 amplitude, s32 step, s32 horizontal);
void Entity081ee7a8_SpawnEx(Vec3* pos, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17);

const STRING_DATA char s_eneinline_08252168[] = "../system/eneinline.h";

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
  p->burnTimer = 0;
  p->unk_460 = 0;
  p->unk_462 = 0;
  Enemy_ClearPendingState(p, s_eneinline_08252168, 2434);
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

void Sandworm_SubCircle(Sandworm*);
void Sandworm_SubTurn(Sandworm*);
void Sandworm_SubCrawl(Sandworm*);
void Sandworm_SubHop(Sandworm*);
void Sandworm_SubLeap(Sandworm*);
void FUN_0817324c(Sandworm*);
void Sandworm_SubCrawlAway(Sandworm*);
void Sandworm_SubCrawlToward(Sandworm*);
void Sandworm_SubBreach(Sandworm*);
void Sandworm_SubSubmerge(Sandworm*);
void Sandworm_SubTunnel(Sandworm*);
void Sandworm_SubLeapOut(Sandworm*);
void Sandworm_SubWander(Sandworm*);
void Sandworm_SubBurrow(Sandworm*);
void Sandworm_SubDive(Sandworm*);
void Sandworm_SubAppear(Sandworm*);
void FUN_081738e0(Sandworm*);
void Sandworm_SubDying(Sandworm*);

// clang-format off
void (*const sSandwormHandlerTable2[22])(Sandworm*) = {
    Sandworm_SubCircle,
    Sandworm_SubTurn,
    Sandworm_SubCrawl,
    (void*)FUN_080f2364,
    Sandworm_SubHop,
    Sandworm_SubLeap,
    FUN_0817324c,
    Sandworm_SubCrawlAway,
    Sandworm_SubCrawlToward,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    Sandworm_SubBreach,
    Sandworm_SubSubmerge,
    Sandworm_SubTunnel,
    Sandworm_SubLeapOut,
    Sandworm_SubWander,
    Sandworm_SubBurrow,
    Sandworm_SubDive,
    Sandworm_SubAppear,
    FUN_081738e0,
    Sandworm_SubDying,
};  // 0x085ADAE4
// clang-format on

// 歩きアニメのコマ (cmdIdx & 3) ごとの移動の速さ
const u32 sSandwormMoveSpeeds[4] = {14, 15, 19, 24};  // 0x085ADB3C

void FUN_0817a05c(Sandworm*);

void (*const sSandwormHandlerTable4[1])(Sandworm*) = {
    FUN_0817a05c,
};  // 0x085ADB4C

void Sandworm_OnDamageMsg(Sandworm*, u16*);

// メッセージ表
void (*const sSandwormMsgHandlers[7])(Sandworm*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    Sandworm_OnDamageMsg,
};  // 0x085ADB50

void Sandworm_OnHit(Hitbox* a, Hitbox* b, Sandworm* p) {
  if (!Enemy_IsDead(&p->e)) {
    if (b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 食らい判定, 死に際でなければ敵共通の処理を通して SANDFLAG_UNK_6 を立てる
// 784/796命令, Serpent/Salamander_OnHurt と同じ共通 inline (Enemy_HandleHurt) の壁, 1回目の下書きで切り上げ
NON_MATCH void Sandworm_OnHurt(Hitbox* a, Hitbox* b, Sandworm* p) {
#ifdef NONMATCHING_C
  if (!Enemy_IsDead(&p->e) && !Sandworm_TestFlags((p->e).owner, SANDFLAG_DYING)) {
    Enemy_HandleHurt(a, b, &p->e);
    SET_FLAGS(((Sandworm*)(p->e).owner)->flags, SANDFLAG_UNK_6);
  }
#else
  INCFUNC("asm/func/Sandworm_OnHurt.inc");
#endif
}

void Sandworm_StateMove(Sandworm* p) {
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Sandworm_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Sandworm_AnimateSegments2((p->e).owner, 15);
  } else {
    Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Sandworm_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Sandworm_AnimateSegments2((p->e).owner, 15);
    if ((p->e).jumpVel.y < 0) {
      Enemy_EnterState(&p->e, Sandworm_StateFall, ES_UNK_40);
    }
  }
}

// jumpVel.y が負になると Sandworm_StateMove から移る, animTable[17] を流す
void Sandworm_StateFall(Sandworm* p) {
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Sandworm_PlayDirAnim(p, (p->e).animTable[17].anim, variant, flags);
    Sandworm_AnimateSegments2((p->e).owner, 15);
  } else {
    Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Sandworm_PlayDirAnim(p, (p->e).animTable[17].anim, variant, flags);
    Sandworm_AnimateSegments2((p->e).owner, 15);
  }
}

void Sandworm_StateWait(Sandworm* p) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Sandworm_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Sandworm_AnimateSegments((p->e).owner, 15);
}

void Sandworm_StateTurn(Sandworm* p) {}

void Sandworm_StateNap(Sandworm* p, s32 timer) {
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
    Enemy_EnterState(&p->e, Sandworm_StateWakeUp, ES_WAKE_UP);
  }
}

void Sandworm_StateWakeUp(Sandworm* p, s32 timer) {
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

// 姿と影を隠して 27 フレーム待ち, アニメ 9 を流しながら Sandworm_StateRespawn (状態13) へ移る
void Sandworm_StateRespawnWait(Sandworm* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (timer > 26) {
    Enemy_PlayAnim(&p->e, 9);
    Enemy_EnterState(&p->e, Sandworm_StateRespawn, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
}

// 姿と影を戻して hp 1 と無敵 60 フレームで現れ, アニメが終わったら生成時の状態に戻す
void Sandworm_StateRespawn(Sandworm* p) {
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
    Sandworm_OnReset(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

// どこからも参照されない, アニメ 11 を流し, 流れ終えたら副状態を終える
void FUN_081716cc(Sandworm* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 11);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = TRUE;
  }
}

// 向きと逆へ下がりながら浮き上がり, 残りの節の数で決まる高さに着いたら FUN_081719b4 の状態へ移る
void Sandworm_StateRise(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 limit;
  s32 n;
  s32 i;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    u32 variant, flags;

    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Sandworm_RestartSegmentAnims(q, 15, variant, flags);
    SET_FLAGS(q->flags, SANDFLAG_UNK_1);
  }
  Vec3_Clear(&(p->e).jumpVel);
  limit = q->segmentsLeft > 3 ? 300 : 200;
  if ((p->e).heightAboveFloor >= limit) {
    Enemy_EnterState(&p->e, FUN_081719b4, ES_UNK_38);
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
    Sandworm_PullSegments(p, 14, 12, 12000);
    n = 0;
    for (i = 0; i < q->segmentCount; i++) {
      if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED | SANDSEGFLAG_UNK_2)) {
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

void FUN_081719b4(Sandworm* p) {}

// 前の節を追う節に頭の移動量を 1/(i+1) にした速さを与えて引き寄せ, 頭と節のアニメを流す
void FUN_081719b8(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  u32 variant, flags;
  s32 i;

  // 入場時の処理は空, Enemy_ConsumeStateBegun を文として置くと一致しない
  if (Enemy_ConsumeStateBegun(&p->e)) {
  }
  for (i = 0; i < q->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED | SANDSEGFLAG_UNK_2)) {
      q->segments[i].velocity.x = Div((p->e).mover.delta.x, i + 1);
      q->segments[i].velocity.y = 0;
      q->segments[i].velocity.z = Div((p->e).mover.delta.z, i + 1);
    }
  }
  Sandworm_PullSegments(p, 24, 12, 0x40000);
  Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Sandworm_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Sandworm_AnimateSegments2((p->e).owner, 15);
}

// 向きと逆へ下がりながら浮き上がり, 床から 256 を超えたら Sandworm_StateHover の状態へ移る
void Sandworm_StateLeapBack(Sandworm* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  Vec3_Clear(&(p->e).jumpVel);
  if ((p->e).heightAboveFloor > 255) {
    Enemy_EnterState(&p->e, Sandworm_StateHover, ES_UNK_34);
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
    Sandworm_PullSegments(p, 10, 12, 0x1000);
    Sandworm_WobbleSegments(p, 20, 24, 0);
  }
}

// 宙で前後に揺れながら追う節の前の2つを頭の後ろに並べ, 60 フレーム後に Sandworm_StatePounce へ移る
// 残差は speed を作る ands の演算子の並びだけ (320/320命令), Serpent/Salamander_StateHover と同じ壁, 1回目の下書きで切り上げ
NON_MATCH void Sandworm_StateHover(Sandworm* p, s32 timer) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
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
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED | SANDSEGFLAG_UNK_2)) {
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
  Sandworm_PullSegments(p, 64, 12, 0xFFFF);
  if (timer > 60) {
    Enemy_EnterState(&p->e, Sandworm_StatePounce, ES_UNK_35);
  }
#else
  INCFUNC("asm/func/Sandworm_StateHover.inc");
#endif
}

// プレイヤーへ向けて跳びかかり, 着地したら Sandworm_StateLand の状態へ移る
void Sandworm_StatePounce(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Sandworm_AimJumpAtPlayer(p);
    (p->e).mover.angle = ArcTan2_8((p->e).jumpVel.x, (p->e).jumpVel.z);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    CLEAR_FLAGS(q->flags, SANDFLAG_UNK_1);
  }
  Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Sandworm_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Sandworm_WobbleSegments(p, 18, 6, 0);
  Sandworm_AnimateSegments2((p->e).owner, 15);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Sandworm_StateLand, ES_UNK_36);
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
}

// 着地してから節を引き寄せつつ 40 フレーム待ち, 終わったら副状態を進める
void Sandworm_StateLand(Sandworm* p, s32 timer) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Sandworm_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Sandworm_AnimateSegments((p->e).owner, 15);
  Sandworm_PullSegments(p, 20, 12, 0x6400);
  if (timer > 40) {
    Sandworm_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Sandworm_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Sandworm_AnimateSegments2((p->e).owner, 15);
    (p->e).subStateDone = 1;
  }
}

void Sandworm_ClearStateBegun(Sandworm* p) {
  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
}

// 被弾して減った hp に合わせて尾の節を壊し, 弾かれ終えたら副状態 5 へ移る
// 222/227命令, 敵共通の StateDamaged の壁 (原典はフラグのアドレスを先にスタックへ作り置く), Serpent_StateDamaged と同じ, 1回目の下書きで切り上げ
NON_MATCH void Sandworm_StateDamaged(Sandworm* p) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 n;

    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    PlaySound_082406e0(CRY_BOKU_DAMAGED);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
    for (n = Div((p->e).hp, q->hpPerSegment); n < q->segmentsLeft; n++) {
      Sandworm_DestroyTailSegment(p);
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
  INCFUNC("asm/func/Sandworm_StateDamaged.inc");
#endif
}

// 粒を撒きながら点滅して消え, 節を全部壊して撃破スクリプト, 図鑑, 撃破数, 経験値を処理してから止まる
void Sandworm_StateDying(Sandworm* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetEmote(&p->e, 0, 127, 0);
    Enemy_SetEmote(&p->e, 1, 127, 0);
    Enemy_SetEmote(&p->e, 3, 127, 0);
    Enemy_FadeParticles(&p->e, 4);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBF_HIDDEN;
    PlaySound_082406e0(SONG_419);
  }
  if (Mod(timer, 10) == 0) {
    Sandworm_ScatterParticles(&(p->e).mover.pos, 10);
  }
  if (Sprite_UpdateVanishBlink(&(p->e).s->aux.spr.flags, timer, 10, 30)) {
    s32 idx;

    Sandworm_ScatterParticles(&(p->e).mover.pos, 16);
    Sandworm_DestroyAllSegmentsWithParticles(p);
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
    UNK_948(0) = (UNK_948(0) < 9999) ? (UNK_948(0) + 1) : 9999;
    TOTAL_ENEMY_KILL = (TOTAL_ENEMY_KILL < 9999) ? (TOTAL_ENEMY_KILL + 1) : 9999;
    Enemy_AddKillCount(&p->e);
    AddPlayerExp((p->e).exp);
    Player_AddWeaponExp((p->e).weaponExpMask, (p->e).weaponExp);
    if (!IsLinkPlay() && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_11)) {
      EnemyRespawnInfo_Add(gMapInitScriptID, (p->e).mover.id);
    }
    (p->e).stunTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    (p->e).subStateDone = 1;
  }
}

// 体をくねらせて行き先へ這い進み, 着いたら次の行き先を決める, 向きが 32 より離れていれば向き直りへ, 60 フレームを超えたら副状態 18 へ移る
void Sandworm_SubCrawl(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->waveDir = 1;
    q->waveOffset = 0;
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Sandworm_ResetWave(p);
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Sandworm_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    if (abs(Sandworm_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
      Enemy_ResetState(&p->e, 0, 0, 1);
      return;
    }
  }
  Sandworm_AdvanceSwayIfMoving(p, speed);
  if (q->unk_101c != 0) {
    Sandworm_PullSegments(p, 18, 12, 0x1000);
    q->unk_101c--;
  } else {
    Sandworm_PullSegments(p, 20, 12, 0x6400);
  }
  Sandworm_UpdateWave(p, 120, 10);
  if (q->crawlTimer > 60) {
    Enemy_ResetState(&p->e, 0, 0, 18);
    q->unk_f96 = q->unk_fa6;
  } else {
    q->crawlTimer++;
    (p->e).subStateTimer++;
  }
}

// プレイヤーと逆の向きの行き先を選んで這い進み, 80 フレームを超えたら副状態 8 へ移る
void Sandworm_SubCrawlAway(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Sandworm_ResetWave(p);
    q->unk_1021 = (((p->e).playerAngle + 0x80) & 0xFF) >> 6;
    q->unk_1020 = 0;
    Sandworm_PickNextTile(p);
  }
  if ((p->e).unk_544 == 0) {
    (p->e).unk_544 = 1;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Sandworm_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
  }
  Sandworm_AdvanceSwayIfMoving(p, speed);
  if (q->unk_101c != 0) {
    Sandworm_PullSegments(p, 18, 12, 0x1000);
    q->unk_101c--;
  } else {
    Sandworm_PullSegments(p, 20, 12, 0x6400);
  }
  Sandworm_UpdateWave(p, 120, 10);
  if ((p->e).subStateTimer > 80) {
    Enemy_ResetState(&p->e, 0, 0, 8);
  } else {
    (p->e).subStateTimer++;
  }
}

// プレイヤーの方の行き先を選んで這い進み, 800 フレームを超えたら次の行き先を決めて副状態 2 へ移る
void Sandworm_SubCrawlToward(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Sandworm_ResetWave(p);
    q->unk_1021 = (((p->e).playerAngle + 0x20) & 0xFF) >> 6;
    q->unk_1020 = 0;
    Sandworm_PickNextTile(p);
  }
  if ((p->e).unk_544 == 0) {
    (p->e).unk_544 = 1;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Sandworm_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
  }
  Sandworm_AdvanceSwayIfMoving(p, speed);
  if (q->unk_101c != 0) {
    Sandworm_PullSegments(p, 18, 12, 0x1000);
    q->unk_101c--;
  } else {
    Sandworm_PullSegments(p, 20, 12, 0x6400);
  }
  Sandworm_UpdateWave(p, 120, 10);
  if ((p->e).subStateTimer > 800) {
    Sandworm_PickNextTile(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
}

// 向きを少しずつ回しながら進んで円を描き, 240 フレームを過ぎてプレイヤーの方を向いたら副状態 2 へ移る
void Sandworm_SubCircle(Sandworm* p) {
  s32 speed, followDiv, turn, followDistSq;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  Vec3_Clear(&(p->e).jumpVel);
  if ((p->e).subStateTimer > 239 && Sandworm_IsTurnedTo((p->e).playerAngle, (p->e).mover.angle)) {
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_ResetState(&p->e, 0, 0, 2);
    return;
  }
  if ((p->e).subStateTimer < 120) {
    speed = 80;
    followDiv = 8;
    turn = 2;
    followDistSq = 6240;
  } else if ((p->e).subStateTimer < 200) {
    speed = 40;
    followDiv = 8;
    turn = 4;
    followDistSq = 1240;
  } else {
    speed = 40;
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
  Sandworm_PullSegments(p, followDiv, 12, followDistSq);
  (p->e).subStateTimer++;
}

// Sandworm_StateRise の状態に入り, 終わったら次の行き先を決めて副状態 2 へ移る
void FUN_0817324c(Sandworm* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Sandworm_StateRise, ES_UNK_37);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  if ((p->e).subStateDone) {
    Sandworm_PickNextTile(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  } else {
    (p->e).subStateTimer++;
  }
}

// 今いるタイルの中で unk_1dc の向きへ向き直り, 向ききったら副状態 2 (SANDFLAG_UNK_4 なら 14) へ移る
void Sandworm_SubTurn(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  Vec3 v;
  s32 speed;
  s32 diff;
  s32 tile;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->turnTileIdx = (p->e).tileIdx;
    TilePosAtIndex(&q->turnTilePos, q->turnTileIdx);
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Sandworm_TestFlags(q, SANDFLAG_UNK_4)) {
    (p->e).mover.pos.y = (p->e).floorY - 1024;
  }
  diff = Sandworm_AngleDiff((p->e).unk_1dc, (p->e).mover.angle);
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
  Sandworm_LeaveTrail(p);
  Sandworm_PullSegments(p, 12, 12, 42000);
  if (abs(diff) <= 7) {
    if (q->turnTileIdx == tile) {
      if (Sandworm_TestFlags(q, SANDFLAG_UNK_4)) {
        Enemy_ResetState(&p->e, 0, 0, 14);
      } else {
        Enemy_ResetState(&p->e, 0, 0, 2);
      }
    }
  } else if (diff > 0) {
    (p->e).mover.angle += (p->e).animSpeedDiv * 2;
  } else {
    (p->e).mover.angle -= (p->e).animSpeedDiv * 2;
  }
  (p->e).subStateTimer++;
}

// angle の向きへ速さ 32 で大きく跳び, 着地したら次の行き先を決めて副状態 20 へ (hp が尽きていれば 13 へ) 移る
void Sandworm_SubLeap(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).angle, 32);
    (p->e).jumpVel.y = 32;
    (p->e).heightAboveFloor = 0;
    (p->e).unk_1bc = 2;
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_4);
    SET_FLAGS(q->flags, SANDFLAG_UNK_7);
  }
  Sandworm_PullSegments(p, 6, 12, 0x1000);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    if (Sandworm_TestFlags(q, SANDFLAG_DYING)) {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 13);
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 20);
      Sandworm_PickNextTile(p);
      PlaySound_082406e0(SONG_985);
    }
    Sandworm_ClearFlags(q, SANDFLAG_UNK_7);
  } else {
    (p->e).subStateTimer++;
  }
}

// 節を引き寄せて揺らしながら 200 フレーム待ち, 終わったら SANDFLAG_UNK_8 を立てて移動に戻る
void FUN_081738e0(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  }
  Sandworm_PullSegments(p, 6, 12, 0x1000);
  if ((p->e).subStateTimer < 100) {
    if (Mod((p->e).subStateTimer, 20) == 0) {
      Sandworm_WobbleSegments(p, 40, 24, 0);
    }
  } else if (Mod((p->e).subStateTimer, 40) == 0) {
    Sandworm_WobbleSegments(p, 20, 44, 1);
  }
  if ((p->e).subStateTimer > 200) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 17);
    SET_FLAGS(q->flags, SANDFLAG_UNK_8);
    q->diveCount = 0;
    q->unk_f96 = 3;
  } else {
    (p->e).subStateTimer++;
  }
}

// 向いている方へ速さ 4 で跳ね, 着地したら次の行き先を決めて移動に戻る
void Sandworm_SubHop(Sandworm* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).mover.angle, 4);
    (p->e).jumpVel.y = 0;
    (p->e).unk_1bc = 2;
  }
  Sandworm_PullSegments(p, 6, 12, 0x1000);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Sandworm_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
}

// 地中からプレイヤーの方 (半分の確率で 0x20 ずらす) へ跳び出して節を順に跳ね上げ, 着地したら粒を撒いて潜り副状態 13 へ移る
// 395/395命令, 残差は最初の枝で &playerAngle と &jumpVel の定数を作る一時レジスタの入れ替えだけ (reload の回し順の壁), Tier C (乱数の書き方, 角度のマスク) は試済
NON_MATCH void Sandworm_SubBreach(Sandworm* p) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    if ((Random() & 0xFF) < 0x80) {
      Vec3_SetPolar(&(p->e).jumpVel, (p->e).playerAngle, 20);
      (p->e).mover.angle = (p->e).playerAngle;
    } else {
      Vec3_SetPolar(&(p->e).jumpVel, ((p->e).playerAngle + 0x20) & 0xFF, 20);
      (p->e).mover.angle = (p->e).playerAngle + 0x20;
    }
    (p->e).mover.pos.y = (p->e).floorY - 256;
    Sandworm_SetAllSegmentsPos(q, &(p->e).mover.pos);
    (p->e).mover.pos.y = (p->e).floorY;
    (p->e).jumpVel.y = 42;
    (p->e).heightAboveFloor = 0;
    (p->e).unk_1bc = 0;
    SET_FLAGS(q->flags, SANDFLAG_UNK_2);
    PlaySound_082406e0(SONG_998);
  }
  if ((p->e).subStateTimer < 10) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 16;
    for (i = 0; i < 4; i++) {
      Sandworm_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 20) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 32;
    for (i = 0; i < 8; i++) {
      Sandworm_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 60) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 64;
    for (i = 0; i < 8; i++) {
      Sandworm_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 80) {
    Vec3 v;

    Vec3_Clear(&v);
    for (i = 0; i < 8; i++) {
      if (i < 4) {
        v.y = 84;
        Sandworm_SetSegmentVelocity(p, &v, i);
      } else {
        v.y = 148;
        Sandworm_SetSegmentVelocity(p, &v, i);
      }
    }
  }
  Sandworm_PullSegments(p, 6, 12, 0x1000);
  Sandworm_UpdateSegmentsBuried(q);
  if (!((p->e).s->aux.spr.flags & SPRFLAG_HIDDEN)) {
    AuxShadow_Show(&(p->e).auxShadow);
  }
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Vec3 d;

    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    Sandworm_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    Sandworm_ScatterParticles(&(p->e).mover.pos, 3);
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    Enemy_ResetState(&p->e, 0, 0, 13);
    PlaySound_082406e0(SONG_325);
    AuxShadow_Hide(&(p->e).auxShadow);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Sandworm_SubBreach.inc");
#endif
}

// 着地して地中へ潜り, 潜りきったら副状態 14 か (潜った回数が少なければ) 12 へ移る
void Sandworm_SubDive(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Sandworm_ClearFlags(q, SANDFLAG_UNK_2);
    (p->e).jumpVel.y = 32;
    (p->e).unk_1bc = 0;
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Sandworm_ClearFlags(q, SANDFLAG_UNK_3);
  }
  if ((p->e).subStateTimer > 80) {
    Sandworm_PullSegments(p, 12, 4, 0);
  } else {
    Sandworm_PullSegments(p, 12, 4, 0xFFFF);
  }
  for (i = 0; i < q->segmentCount; i++) {
    Vec3 d;

    Vec3_Diff(&d, &q->segments[i].sprite.pos, &(p->e).mover.pos);
    if (d.x * d.x + d.z * d.z > 32000) {
      q->segments[i].sprite.pos.y = (p->e).floorY;
    }
  }
  Sandworm_UpdateSegmentsBuried(q);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Sandworm_ScatterParticles(&(p->e).mover.pos, 3);
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    Sandworm_SetFlags(q, SANDFLAG_UNK_3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    PlaySound_082406e0(SONG_988);
  }
  if (Sandworm_TestFlags(q, SANDFLAG_UNK_3)) {
    (p->e).mover.pos.y -= 16;
    if (Sandworm_UpdateSegmentsBuried(q) < 0) {
      if (q->unk_f96 > 0) {
        Enemy_ResetState(&p->e, 0, 0, 14);
        q->unk_f96--;
      } else if (q->diveCount > 4) {
        Enemy_ResetState(&p->e, 0, 0, 14);
      } else {
        Enemy_ResetState(&p->e, 0, 0, 12);
        CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
        Sandworm_ScatterParticles(&(p->e).mover.pos, 3);
        q->diveCount++;
      }
      return;
    }
  }
  (p->e).subStateTimer++;
}

// 地中深くへ潜って体を沈め, 潜りきったら unk_f98 フレーム待って副状態 14 か 12 へ (倒れかけなら小さなワームを潜らせて 19 へ) 移る
void Sandworm_SubSubmerge(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Sandworm_ClearFlags(q, SANDFLAG_UNK_2);
    if (Sandworm_TestFlags(q, SANDFLAG_DYING)) {
      WormTail_RequestDive();
      PlaySound_082406e0(SONG_988);
    }
  }
  if ((p->e).mover.pos.y > -2048) {
    Vec3 v;

    Vec3_SetPolar(&v, (p->e).mover.angle, 8);
    (p->e).mover.pos.y -= 100;
    if ((p->e).s->aux.spr.flags == 0 && (p->e).mover.pos.y < (p->e).floorY) {
      Sandworm_ScatterParticles(&(p->e).mover.pos, 3);
      (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
      if (!Sandworm_TestFlags(q, SANDFLAG_DYING)) {
        PlaySound_082406e0(SONG_421);
      }
    }
  } else {
    (p->e).mover.pos.y = -2048;
  }
  if ((p->e).subStateTimer > 30) {
    Sandworm_PullSegments(p, 12, 4, 0);
  } else {
    Sandworm_PullSegments(p, 12, 6, 42000);
  }
  for (i = 0; i < q->segmentCount; i++) {
    Vec3 d;

    Vec3_Diff(&d, &q->segments[i].sprite.pos, &(p->e).mover.pos);
    if (d.x * d.x + d.z * d.z > 32000) {
      if (q->segments[i].sprite.pos.y < (p->e).floorY) {
        q->segments[i].sprite.pos.y = (p->e).floorY;
      }
    }
  }
  if (Sandworm_UpdateSegmentsBuried(q) < 0) {
    if (Sandworm_TestFlags(q, SANDFLAG_DYING)) {
      if ((p->e).subStateTimer > 160) {
        Enemy_ResetState(&p->e, 0, 0, 19);
      }
    } else if ((p->e).subStateTimer > q->unk_f98) {
      if (q->unk_f96 > 0) {
        Enemy_ResetState(&p->e, 0, 0, 14);
        q->unk_f96--;
      } else if (q->diveCount > 4) {
        Enemy_ResetState(&p->e, 0, 0, 14);
      } else {
        Enemy_ResetState(&p->e, 0, 0, 12);
        CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
        Sandworm_ScatterParticles(&(p->e).mover.pos, 3);
        q->diveCount++;
      }
      return;
    }
  }
  (p->e).subStateTimer++;
}

// SANDFLAG_UNK_4 を立てて地中を行き先へ這い進み跡を残す, ときどき岩を飛ばして向き直りへ移り, tunnelTimer が尽きたら副状態 15 へ移る
// 427/427命令, 残差は乱数を引く辺りの定数の一時レジスタだけ, Serpent の FUN_0818cfb8 と同じ壁, Tier C (乱数の書き方, 入れ子の if) は試済
NON_MATCH void Sandworm_SubTunnel(Sandworm* p) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    if (!Sandworm_TestFlags(q, SANDFLAG_UNK_4)) {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Sandworm_ResetWave(p);
      Sandworm_HideLiveSegments(q);
      (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
      (p->e).mover.pos.y = (p->e).floorY - 256;
      Sandworm_SetAllSegmentsPos(q, &(p->e).mover.pos);
      CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
      Sandworm_ClearFlags(q, SANDFLAG_UNK_2);
      Sandworm_ScatterParticles(&(p->e).mover.pos, 3);
      q->lastTrailPos = (p->e).mover.pos;
      q->tunnelTimer = q->tunnelTime;
      Sandworm_SetFlags(q, SANDFLAG_UNK_4);
      PlaySound_082406e0(SONG_996);
    }
  }
  Sandworm_LeaveTrail(p);
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  (p->e).mover.pos.y = (p->e).floorY - 1024;
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Sandworm_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    if ((Random() & 0xFF) < 64 && abs(Sandworm_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
      WorldPos pos;

      pos = (p->e).mover.pos;
      pos.y = (p->e).floorY;
      Sandworm_ThrowRocksUp(p, &pos);
      Enemy_ResetState(&p->e, 0, 0, 1);
      return;
    }
  }
  Sandworm_AdvanceSwayIfMoving(p, speed);
  Sandworm_PullSegments(p, 20, 12, 0x6400);
  Sandworm_UpdateWave(p, 120, 10);
  if (q->tunnelTimer == 0) {
    Enemy_ResetState(&p->e, 0, 0, 15);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    CLEAR_FLAGS(q->flags, SANDFLAG_UNK_4);
    sound_08240740(SONG_996);
  } else {
    q->tunnelTimer--;
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Sandworm_SubTunnel.inc");
#endif
}

// 粒を撒きながら地中から跳び出し, 上昇が止まったら副状態 16 へ移る
void Sandworm_SubLeapOut(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3 pos;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).mover.pos.y = (p->e).floorY;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
    CLEAR_FLAGS(q->flags, SANDFLAG_UNK_2);
    (p->e).jumpVel.y = 42;
    (p->e).heightAboveFloor = 0;
    Sandworm_ThrowRocks(p, &(p->e).mover.pos);
    Sandworm_ScatterParticles(&(p->e).mover.pos, 3);
    pos = (p->e).mover.pos;
    pos.y = (p->e).floorY - 2024;
    Sandworm_SetAllSegmentsPos(q, &pos);
    PlaySound_082406e0(SONG_995);
  }
  if ((p->e).jumpVel.y <= 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Enemy_ResetState(&p->e, 0, 0, 16);
  } else {
    Sandworm_PullSegments(p, 4, 4, 0xFFFF);
    Sandworm_UpdateSegmentsBuried(q);
    (p->e).subStateTimer++;
  }
}

// 地上の周りをうろつき (ワームを呼んでいる間はプレイヤーの方を向き), wanderTime を過ぎたら次の行き先を選んで向き直りか這い進み (たまに副状態 17) へ移る
// 612/634命令, 原典は最後の ResetState の枝を元気/弱りで別々に残し, こちらは尾を合流させる, Serpent_SubWander と同じ形, Tier A-C (枝の向き, 早期 return, 入れ子) は試済
NON_MATCH void Sandworm_SubWander(Sandworm* p) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
  s32 angle, diff;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->wanderTarget = (p->e).mover.pos;
    q->wanderBase = (p->e).mover.pos;
    q->wanderTarget.x += (RandomNext() & 0x7F) - 64;
    q->wanderTarget.z += (RandomNext() & 0x7F) - 64;
    q->unk_f8a = (p->e).mover.angle;
    q->wanderTimer = 60;
    Enemy_EnterState(&p->e, FUN_081719b8, ES_UNK_39);
    Sandworm_ClearFlags(q, SANDFLAG_UNK_6);
  }
  if (!WormTail_IsIdle()) {
    angle = (p->e).playerAngle;
  } else {
    (p->e).mover.delta.x += Div(q->wanderTarget.x - (p->e).mover.pos.x, q->wanderTimer);
    (p->e).mover.delta.z += Div(q->wanderTarget.z - (p->e).mover.pos.z, q->wanderTimer);
    angle = ArcTan2_8((p->e).mover.delta.x, (p->e).mover.delta.z);
  }
  diff = Sandworm_AngleDiff(angle, (p->e).mover.angle);
  if (abs(diff) < 32) {
    (p->e).mover.angle = angle;
  } else if (diff < 0) {
    (p->e).mover.angle -= 4;
  } else {
    (p->e).mover.angle += 4;
  }
  if (--q->wanderTimer == 0) {
    q->wanderTarget = q->wanderBase;
    q->wanderTarget.x += (RandomNext() & 0x7F) - 64;
    q->wanderTarget.z += (RandomNext() & 0x7F) - 64;
    q->wanderTimer = (RandomNext() & 0x3F) + 30;
  }
  if (Sandworm_TestFlags(q, SANDFLAG_UNK_6)) {
    WormTail_Spawn(&gPlayerPtr[0]->mover.pos, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2], q->wormMoveTime0, 32, 24, q->wormEmergeDelay0, 0, q->tailDefense, (p->e).attrs, (p->e).weakness);
    Sandworm_ClearFlags(q, SANDFLAG_UNK_6);
    q->unk_f96 -= 2;
    q->diveCount -= 2;
    (p->e).subStateTimer += 20;
  }
  if ((p->e).subStateTimer > q->wanderTime) {
    if (WormTail_IsIdle()) {
      if ((p->e).unk_546 >= (p->e).hp) {
        if ((Random() & 0xFF) < 48) {
          Vec3 d;

          CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
          Sandworm_PickNextTile(p);
          Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
          (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
          q->diveCount = 0;
          if (abs(Sandworm_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
            Enemy_ResetState(&p->e, 0, 0, 1);
          } else {
            Enemy_ResetState(&p->e, 0, 0, 2);
          }
        } else {
          Enemy_ResetState(&p->e, 0, 0, 17);
        }
      } else if ((Random() & 0xFF) < 194) {
        Vec3 d;

        CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
        Sandworm_PickNextTile(p);
        Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
        (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
        q->diveCount = 0;
        q->crawlTimer = 0;
        PlaySound_082406e0(SONG_422);
        if (abs(Sandworm_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
          Enemy_ResetState(&p->e, 0, 0, 1);
        } else {
          Enemy_ResetState(&p->e, 0, 0, 2);
        }
      } else {
        Enemy_ResetState(&p->e, 0, 0, 17);
      }
    }
  } else {
    Sandworm_TrySummonWorms(p);
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Sandworm_SubWander.inc");
#endif
}

// 跳ね上がって着地したら粒を撒いて姿を隠し (地中へ潜り), 副状態 13 へ移る
void Sandworm_SubBurrow(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    CLEAR_FLAGS(q->flags, SANDFLAG_UNK_2);
    (p->e).jumpVel.y = -64;
    (p->e).unk_1bc = 0;
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
  }
  Sandworm_PullSegments(p, 6, 12, 0xFFFF);
  Sandworm_UpdateSegmentsBuried(q);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Sandworm_ScatterParticles(&(p->e).mover.pos, 3);
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    if (Sandworm_TestFlags(q, SANDFLAG_UNK_8)) {
      PlaySound_082406e0(SONG_988);
      Sandworm_ClearFlags(q, SANDFLAG_UNK_8);
    } else {
      PlaySound_082406e0(SONG_325);
    }
    Enemy_ResetState(&p->e, 0, 0, 13);
  }
  (p->e).subStateTimer++;
}

// 決まった位置の地中からプレイヤーの方へ跳び出して '.d' のスクリプトを流し, 節を順に跳ね上げ, 上昇が弱まったら副状態 21 へ移る
void Sandworm_SubAppear(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3 d;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).mover.pos.x = 1152;
    (p->e).mover.pos.y = -1024;
    (p->e).mover.pos.z = 384;
    (p->e).s->aux.spr.pos = (p->e).mover.pos;
    Sandworm_SetAllSegmentsPos(q, &(p->e).mover.pos);
    Enemy_SetFlag5(&p->e, ENEFLAG5_UNK_5);
    Sandworm_ClearFlags(q, SANDFLAG_UNK_2);
    Vec3_Delta(&d, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    (p->e).mover.angle = ArcTan2_8(d.x, d.z);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).mover.angle, 24);
    (p->e).jumpVel.y = 48;
    (p->e).heightAboveFloor = 0;
    (p->e).unk_1bc = 0;
    Enemy_ClearFlag5(&p->e, ENEFLAG5_UNK_5);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Sandworm_RunScript(p);
    PlaySound_082406e0(SONG_421);
    sound_08240740(SONG_996);
    return;
  }
  if ((p->e).subStateTimer < 10) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 16;
    for (i = 0; i < 4; i++) {
      Sandworm_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 20) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 32;
    for (i = 0; i < 8; i++) {
      Sandworm_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 60) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 64;
    for (i = 0; i < 8; i++) {
      Sandworm_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 80) {
    Vec3 v;

    Vec3_Clear(&v);
    for (i = 0; i < 8; i++) {
      if (i < 4) {
        v.y = 84;
        Sandworm_SetSegmentVelocity(p, &v, i);
      } else {
        v.y = 148;
        Sandworm_SetSegmentVelocity(p, &v, i);
      }
    }
  }
  Sandworm_PullSegments(p, 6, 12, 0x1000);
  if ((p->e).mover.pos.y >= (p->e).floorY) {
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
  }
  Sandworm_UpdateSegmentsBuried(q);
  if ((p->e).jumpVel.y <= 12) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Enemy_ResetState(&p->e, 0, 0, 21);
  } else {
    (p->e).subStateTimer++;
  }
}

// 尾から節を1つずつ壊していき, 120 フレームで Sandworm_StateDying へ移る
void Sandworm_SubDying(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    CLEAR_FLAGS(q->flags, SANDFLAG_UNK_2);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    return;
  }
  switch ((p->e).subStateTimer) {
    case 10: {
      PlaySound_082406e0(SONG_453);
    }
    case 30:
    case 50:
    case 70:
    case 80:
    case 90:
    case 95:
    case 100: {
      Sandworm_DestroyTailSegment(p);
      break;
    }
  }
  if ((p->e).subStateTimer == 31) {
    PlaySound_082406e0(SONG_985);
  }
  Sandworm_PullSegments(p, 6, 12, 12000);
  if ((p->e).subStateTimer > 120) {
    Enemy_EnterState(&p->e, Sandworm_StateDying, ES_DYING);
    Enemy_ResetState(&p->e, 3, 0, 0);
  } else {
    (p->e).subStateTimer++;
  }
}

void Sandworm_SetHandlerTable2(Sandworm* p) { (p->e).handlerTables[2] = (void*)sSandwormHandlerTable2; }

void Sandworm_OnDamageMsg(Sandworm* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && !Sandworm_TestFlags((p->e).owner, SANDFLAG_DYING)) {
    ((Sandworm*)(p->e).owner)->damageAccum += *msg;
  }
}

// 溜まったダメージを hp から引いてゲージを出し, 尽きたら SANDFLAG_DYING を立てて倒れる副状態へ移す
void Sandworm_ApplyDamage(Sandworm* p) {
  if (!Enemy_IsDead(&p->e)) {
    Sandworm* q = (p->e).owner;

    if (!Sandworm_TestFlags(q, SANDFLAG_DYING)) {
      if (q->damageAccum != 0 || (p->e).unk_48a != 0) {
        (p->e).hp -= q->damageAccum;
        if ((p->e).hp - (p->e).unk_48a <= 0) {
          (p->e).hurtbox.damage = 0;
          (p->e).hurtbox.hitResult = 0;
          (p->e).unk_48c = 0;
          (p->e).unk_48a = 0;
          (p->e).unk_4be = 0;
          (p->e).hp = 1;
          Sandworm_SetFlags((p->e).owner, SANDFLAG_DYING);
          if (!Sandworm_TestFlags(q, SANDFLAG_UNK_2 | SANDFLAG_UNK_7)) {
            Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
            Enemy_ResetState(&p->e, 0, 0, 13);
          }
          HUD_ShowEnemyGauge((p->e).mover.id, 0, (p->e).maxHp, (p->e).unk_25a, 0);
        } else {
          HUD_ShowEnemyGauge((p->e).mover.id, (p->e).hp, (p->e).maxHp, (p->e).unk_25a, 0);
        }
      }
      (p->e).hurtbox.damage = 0;
      q->damageAccum = 0;
    }
  }
}

void Sandworm_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *variant = 8 - dir;
    *xflip = 1;
  } else {
    *variant = dir;
    *xflip = 0;
  }
}

// 4 方向の隣のタイルから進めるものを選び, 最近通っていないものを行き先にする, 無ければ乱数で選ぶか真っすぐ進むか unk_1021 の逆へ向かう
// 1105/1202命令の下書き, Salamander_PickNextTile と同じ PickNextTile の壁 (原典は判定の塊を2か所に展開し, 4 方向の数えを sp に置く), 1回目の下書きで切り上げ
NON_MATCH void Sandworm_PickNextTile(Sandworm* p) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
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
  if (q->unk_1020 == 2) {
    dir = (facing + 1) & 3;
  } else if (q->unk_1020 == 3) {
    dir = (facing + Random()) & 3;
  } else {
    dir = facing;
  }
  if (q->unk_1020 > 16) {
    q->unk_1021 = (((p->e).playerAngle + 0x20) & 0xFF) >> 6;
    q->unk_1020 = 0;
  }
  for (i = 0; i < 4; i++) {
    if (abs(dir - q->unk_1021) != 2 && abs(dir - facing) != 2) {
      tile = Sandworm_CheckStep((p->e).tileIdx, Sandworm_NeighborTile((p->e).tileIdx, dir), dir);
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
      if (!Sandworm_IsRecentTile(p, cands[i])) {
        TilePosAtIndex(&agent->dest, cands[i]);
        Sandworm_AddRecentTile(p, cands[i]);
        q->unk_1020++;
        q->unk_101c = 40;
        return;
      }
    }
    i = Mod(Random(), n);
    TilePosAtIndex(&agent->dest, cands[i]);
    Sandworm_AddRecentTile(p, cands[i]);
    q->unk_1020++;
    q->unk_101c = 40;
  } else if (straight != -1 && !Sandworm_IsRecentTile(p, straight)) {
    TilePosAtIndex(&agent->dest, straight);
    Sandworm_AddRecentTile(p, straight);
    q->unk_1020 += 8;
    q->unk_101c = 40;
  } else {
    dir = (q->unk_1021 + 2) & 3;
    tile = Sandworm_CheckStep((p->e).tileIdx, Sandworm_NeighborTile((p->e).tileIdx, dir), dir);
    if (tile >= 0) {
      TilePosAtIndex(&agent->dest, tile);
      Sandworm_AddRecentTile(p, tile);
      q->unk_1020 += 2;
      q->unk_101c = 40;
    } else {
      q->unk_1021 = (q->unk_1021 + 1) & 3;
    }
  }
#else
  INCFUNC("asm/func/Sandworm_PickNextTile.inc");
#endif
}

void Sandworm_ShiftKeySegments(Sandworm* p, Vec3* pos) {
  Sandworm* q = (p->e).owner;

  if (q->shiftTimer != 0) {
    q->shiftTimer--;
  } else {
    q->shiftTimer = 12;
    Sandworm_SetSegmentPos(q, q->segmentCount - 1, &q->segments[q->segmentCount >> 1].sprite.pos);
    Sandworm_SetSegmentPos(q, q->segmentCount >> 1, &q->segments[0].sprite.pos);
    Sandworm_SetSegmentPos(q, 0, pos);
  }
}

// 節を8つ作り, スプライトとアニメを載せる, 尾は anim 7, それより前は anim 6 を前/中/後ろで variant 0..2 に分け cmdIdx を 0..3 でずらして流す
// 173/173命令, 残差は sprite と gfx の誘導変数の初期化順と bit の一時レジスタだけ, FOLLOW だけ segments[i] で書くと 180→173 命令に縮む, Tier A-C は試済 (局所の型と宣言順, 添字の書き方)
NON_MATCH void Sandworm_InitSegments(Sandworm* p, SpriteID32 sprID, u32 animFID, u32 angle) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
  s32 n;
  s32 cmdIdx;
  s32 i;

  q->segmentCount = 8;
  q->segmentsLeft = q->segmentCount;
  q->unk_1024 = 0x7FFFFFFF;
  q->hpPerSegment = Div((p->e).hp, q->segmentCount + 1);
  n = 0;
  cmdIdx = 0;
  for (i = 0; i < q->segmentCount; i++) {
    SandwormSegment* seg = &q->segments[i];

    Video_GetAuxSprite(&seg->gfx, sprID);
    AuxSprite_Add(&seg->sprite, &seg->gfx, 0);
    Video_SetAuxSpritePltt(&seg->gfx, 418);
    seg->angle = angle;
    seg->animFile = GetFile(DIR_ANIMATION, animFID);
    if (i == q->segmentCount - 1) {
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 7, 0, 0);
      SET_FLAGS(seg->flags, SANDSEGFLAG_UNK_2);
    } else {
      u32 variant, xflip;
      u8 v;
      u8 bit;

      Sandworm_GetAnimVariant(seg->angle, &variant, &xflip);
      if (i < 3) {
        v = 0;
        bit = SANDSEGFLAG_UNK_5;
      } else if (i < 5) {
        v = 1;
        bit = SANDSEGFLAG_UNK_4;
      } else {
        v = 2;
        bit = SANDSEGFLAG_UNK_3;
      }
      SET_FLAGS(seg->flags, bit);
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 6, v, 0);
      seg->anim.cmdIdx = cmdIdx;
      if (++cmdIdx > 3) {
        cmdIdx = 0;
      }
    }
    seg->owner = q;
    seg->unk_120 = 0;
    if (n == 0) {
      seg->wobbleAngle = i * 24;
      SET_FLAGS(q->segments[i].flags, SANDSEGFLAG_FOLLOW);
    } else {
      n++;
    }
  }
#else
  INCFUNC("asm/func/Sandworm_InitSegments.inc");
#endif
}

// pos から 64 ずつ向きを回して SPR_EFF_F422 の粒を count 個撒く
void Sandworm_ScatterParticles(Vec3* pos, s32 count) {
  s32 i;

  for (i = 0; i < count; i++) {
    if (i & 1) {
      Entity081ee7a8_SpawnEx(pos, 4, 8, 4, 12, 18, i << 6, 8, 56, 1, 2, 0x200, 0, SPR_EFF_F422, ANIM_121B, 0, 0, 0xD8);
    } else {
      Entity081ee7a8_SpawnEx(pos, 4, 8, 4, 12, 18, i << 6, 8, 56, 1, 2, 0x400, 0, SPR_EFF_F422, ANIM_121B, 0, 0, 0xD8);
    }
  }
}

// SANDFLAG_UNK_4 の間, 前の跡から十分離れるたびに足元の床へ跡のエフェクトを残す
void Sandworm_LeaveTrail(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Sandworm_TestFlags(q, SANDFLAG_UNK_4)) {
    Vec3 v;

    Vec3_Delta(&v, &(p->e).mover.pos, &q->lastTrailPos);
    if (v.x * v.x + v.z * v.z > 12000) {
      v = (p->e).mover.pos;
      v.y = (p->e).floorY;
      Entity081f7974_Spawn(&v, 12);
      q->lastTrailPos = (p->e).mover.pos;
    }
  }
}

// pos から大きい岩を1つ (速さ 40) と小さい岩を2つ (速さ 10) 乱数の向きへ飛ばす, 当たり判定は atk の [3]
// 292/294命令, 原典は乱数の 0xFF を r8 に括り出し pos を r9 に置く, Tier A-C (乱数の書き方, u8 角度, RandomNext) は試済
NON_MATCH void Sandworm_ThrowRocks(Sandworm* p, Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  s32 i;

  Vec3_SetPolar(&vel, (u8)Random(), 40);
  vel.y = (Random() & 0x3F) + 20;
  if ((Random() & 0xFF) < 0x80) {
    Entity081efa9c_Spawn(pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 1, 60, 0, 0, 573, 0, 1, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
  } else {
    Entity081efa9c_Spawn(pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 1, 60, 0, 0, 573, 0, 0, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
  }
  for (i = 0; i < 2; i++) {
    Vec3_SetPolar(&vel, Random(), 10);
    vel.y = (Random() & 0x1F) + 32;
    if (i & 1) {
      Entity081efa9c_Spawn(pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 2, 60, 0, 0, 573, 0, 1, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
    } else {
      Entity081efa9c_Spawn(pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 2, 60, 0, 0, 573, 0, 0, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
    }
  }
  PlaySound_082406e0(SONG_994);
#else
  INCFUNC("asm/func/Sandworm_ThrowRocks.inc");
#endif
}

// pos から大きい岩を1つ (速さ 10 で高く) と小さい岩を3つ乱数の向きへ飛ばす, 当たり判定は atk の [3]
// 292/294命令, Sandworm_ThrowRocks と同じ残差 (原典は乱数の 0xFF を r8 に括り出し pos を r9 に置く), 1回目の下書きで切り上げ
NON_MATCH void Sandworm_ThrowRocksUp(Sandworm* p, Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  s32 i;

  Vec3_SetPolar(&vel, (u8)Random(), 10);
  vel.y = (Random() & 0x3F) + 42;
  if ((Random() & 0xFF) < 0x80) {
    Entity081efa9c_Spawn(pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 1, 60, 0, 0, 573, 0, 1, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
  } else {
    Entity081efa9c_Spawn(pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 1, 60, 0, 0, 573, 0, 0, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
  }
  for (i = 0; i < 3; i++) {
    Vec3_SetPolar(&vel, Random(), 10);
    vel.y = (Random() & 0x1F) + 32;
    if (i & 1) {
      Entity081efa9c_Spawn(pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 2, 60, 0, 0, 573, 0, 1, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
    } else {
      Entity081efa9c_Spawn(pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 2, 60, 0, 0, 573, 0, 0, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
    }
  }
  PlaySound_082406e0(SONG_994);
#else
  INCFUNC("asm/func/Sandworm_ThrowRocksUp.inc");
#endif
}

// 壊れていない節を床より下なら隠し上なら出し, 出入りした節の位置に粒を撒く, 全部上なら 1, 全部下なら -1, 混ざっていれば 0 を返す
// 197/194命令, Serpent/Salamander_UpdateSegmentsBuried と同じ床の高さを見る節のループの壁, 1回目の下書きで切り上げ
NON_MATCH s32 Sandworm_UpdateSegmentsBuried(Sandworm* p) {
#ifdef NONMATCHING_C
  s32 n = 0;
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_DESTROYED)) {
      Vec3* pos = &p->segments[i].sprite.pos;
      s32 h = TileHeightAt(pos);
      Vec3 v;
      s32 d;

      if (pos->y < h) {
        if (!(p->segments[i].sprite.flags & SPRFLAG_HIDDEN)) {
          p->segments[i].sprite.flags |= SPRFLAG_HIDDEN;
          v = *pos;
          v.y = h;
          Sandworm_ScatterParticles(&v, 2);
        }
        d = -1;
      } else {
        if (p->segments[i].sprite.flags & SPRFLAG_HIDDEN) {
          p->segments[i].sprite.flags &= ~SPRFLAG_HIDDEN;
          v = *pos;
          v.y = h;
          Sandworm_ScatterParticles(&v, 2);
        }
        d = 1;
      }
      n += d;
    }
  }
  if (n >= p->segmentCount) {
    return 1;
  }
  if (n > -p->segmentCount) {
    return 0;
  }
  return -1;
#else
  INCFUNC("asm/func/Sandworm_UpdateSegmentsBuried.inc");
#endif
}

void Sandworm_HideLiveSegments(Sandworm* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_DESTROYED)) {
      SET_FLAGS(p->segments[i].sprite.flags, SPRFLAG_HIDDEN);
    }
  }
}

void Sandworm_HideLiveSegmentsFrom(Sandworm* p, s32 idx) {
  s32 i;

  for (i = idx; i < p->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_DESTROYED)) {
      SET_FLAGS(p->segments[i].sprite.flags, SPRFLAG_HIDDEN);
    }
  }
}

// 壊れていない節に animTable[idx] (尾は anim 7) を流し, 1コマ進める
void Sandworm_AnimateSegments2(Sandworm* p, s32 idx) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_DESTROYED)) {
      if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_2)) {
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, 7, 0, 0);
      } else {
        u8 variant;

        if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_5)) {
          variant = 0;
        } else if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_4)) {
          variant = 1;
        } else {
          variant = 2;
        }
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, 0);
        AuxAnim_SetAnimSpeed(&p->segments[i].anim, Div(Q6(1), (p->e).animSpeedDiv));
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

// Sandworm_AnimateSegments2 と同じ処理
void Sandworm_AnimateSegments(Sandworm* p, s32 idx) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_DESTROYED)) {
      if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_2)) {
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, 7, 0, 0);
      } else {
        u8 variant;

        if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_5)) {
          variant = 0;
        } else if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_4)) {
          variant = 1;
        } else {
          variant = 2;
        }
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, 0);
        AuxAnim_SetAnimSpeed(&p->segments[i].anim, Div(Q6(1), (p->e).animSpeedDiv));
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

void Sandworm_BlinkSegments(Sandworm* p, s32 timer) {
  Sandworm* q = (p->e).owner;
  SandwormSegment* segs = q->segments;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&segs[i], SANDSEGFLAG_DESTROYED)) {
      Sprite_UpdateVanishBlink(&segs[i].sprite.flags, timer, 10, 30);
    }
  }
}

// 壊れていない節の animTable[idx] (尾は anim 7) を頭から流し直し, 1コマ進める, variant と flags は受け取るだけで使わない
void Sandworm_RestartSegmentAnims(Sandworm* p, s32 idx, s32 variant, s32 flags) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_DESTROYED)) {
      if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_2)) {
        AuxAnim_RestartAnim(&p->segments[i].anim, p->segments[i].animFile, 7, 0, 0);
      } else {
        u8 variant;

        if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_5)) {
          variant = 0;
        } else if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_UNK_4)) {
          variant = 1;
        } else {
          variant = 2;
        }
        AuxAnim_RestartAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, 0);
        AuxAnim_SetAnimSpeed(&p->segments[i].anim, Div(Q6(1), (p->e).animSpeedDiv));
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

void Sandworm_HideDestroyedSegments(Sandworm* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&p->segments[i], SANDSEGFLAG_DESTROYED)) {
      p->segments[i].sprite.flags = SPRFLAG_HIDDEN;
    }
  }
}

void Sandworm_RemoveSegmentSprites(Sandworm* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    AuxSprite_Remove(&p->segments[i].sprite);
  }
}

void Sandworm_SetSegmentPos(Sandworm* p, s32 idx, Vec3* pos) { p->segments[idx].sprite.pos = *pos; }

// 壊れていない節を1つ前の節 (先頭は頭) の方へ向ける
void Sandworm_FaceSegmentsForward(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  Vec3 diff;
  Vec3 prev = (p->e).mover.pos;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
      Vec3_Diff(&diff, &prev, &q->segments[i].sprite.pos);
      q->segments[i].angle = ArcTan2_8(diff.x, diff.z);
      prev = q->segments[i].sprite.pos;
    }
  }
}

void Sandworm_ResetWave(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  q->waveOffset = 0;
  q->waveDir = 1;
}

void Sandworm_RemoveOcclusionMover(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Sandworm_TestFlags(q, SANDFLAG_OCCLUSION)) {
    CLEAR_FLAGS(q->flags, SANDFLAG_OCCLUSION);
    FUN_08002a58(&q->occlusionMover);
    Mover_Unlink(&q->occlusionMover);
  }
}

void Sandworm_SyncOcclusionMover(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 idx = 0xFF;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_UNK_2)) {
      idx = i;
      break;
    }
  }
  if (idx != 0xFF && Sandworm_TestFlags(q, SANDFLAG_OCCLUSION)) {
    q->occlusionMover.pos = q->segments[idx].sprite.pos;
    q->occlusionMover.auxSprite = &q->segments[idx].sprite;
  }
}

void Sandworm_AddOcclusionMover(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 idx = 0xFF;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_UNK_2)) {
      idx = i;
      break;
    }
  }
  if (idx != 0xFF) {
    Mover_Init(&q->occlusionMover, (p->e).mover.id + 1, &q->segments[idx].sprite.pos, 0, MOVER_OBJECT, q);
    q->occlusionMover.auxSprite = &q->segments[idx].sprite;
    FUN_08002a48(&q->occlusionMover);
    SET_FLAGS(q->flags, SANDFLAG_OCCLUSION);
  }
}

void Sandworm_UpdateWave(Sandworm* p, s32 amplitude, s32 speed) {
  Sandworm* q = (p->e).owner;

  if (q->waveOffset >= amplitude) {
    q->waveOffset = amplitude;
    q->waveDir = -1;
  } else if (q->waveOffset <= -amplitude) {
    q->waveOffset = -amplitude;
    q->waveDir = 1;
  }
  q->waveOffset += q->waveDir * speed;
}

void Sandworm_InitFollowInterval(Sandworm* p) { ((Sandworm*)(p->e).owner)->followInterval = 1; }

// followInterval フレームごとに, 前の節を追う節の targetPos を1つ前の節の位置 (先頭は頭) に送る
void Sandworm_FollowSegments(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Mod((p->e).unk_1ca, q->followInterval) == 0) {
    Vec3 prev = (p->e).s->aux.spr.pos;
    s32 i;

    for (i = 0; i < q->segmentCount; i++) {
      if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
        Vec3 cur = q->segments[i].sprite.pos;

        q->segments[i].targetPos = prev;
        prev = cur;
      }
    }
  }
}

void Sandworm_SetSegmentVelocity(Sandworm* p, Vec3* velocity, s32 idx) {
  Sandworm* q = (p->e).owner;

  if (Sandworm_TestSegmentFlags(&q->segments[idx], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[idx], SANDSEGFLAG_DESTROYED)) {
    q->segments[idx].velocity = *velocity;
  }
}

void Sandworm_WobbleSegments(Sandworm* p, s32 amplitude, s32 step, s32 horizontal) {
  Sandworm* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
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
// 207/209命令, Serpent/Salamander_PlaceSegmentsOnCurve と同じ Hermite 曲線の壁, 1回目の下書きで切り上げ
NON_MATCH void Sandworm_PlaceSegmentsOnCurve(Sandworm* p, Vec3* startPos, Vec3* endPos, s32 first, s32 last) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
  WorldPos start = *startPos;
  WorldPos end = *endPos;
  s32 step = Div(1024, last - (first - 1));
  s32 n = 0;
  s32 i;

  for (i = first; i < last; i++) {
    Vec3 d, v, pos;
    s32 t, t2, t3, k, m;

    n++;
    t = step * n;
    Vec3_Diff(&d, &end, &start);
    CpuFill32(0, &v, sizeof(v));
    t2 = FixToInt(10, t * t);
    t3 = FixToInt(10, t2 * t);
    k = 0;
    k *= t3 - 2 * t2 + t;
    m = v.x * (2 * t3 - 3 * t2 + 1) + d.x * (3 * t2 - 2 * t3) + k;
    pos.x = start.x + FixToInt(10, m);
    m = v.y * (2 * t3 - 3 * t2 + 1) + d.y * (3 * t2 - 2 * t3) + k;
    pos.y = start.y + FixToInt(10, m);
    m = v.z * (2 * t3 - 3 * t2 + 1) + d.z * (3 * t2 - 2 * t3) + k;
    pos.z = start.z + FixToInt(10, m);
    Sandworm_SetSegmentPos(q, i, &pos);
  }
#else
  INCFUNC("asm/func/Sandworm_PlaceSegmentsOnCurve.inc");
#endif
}

// 前の節を追う節を targetPos へ 1/followDiv ずつ寄せ, 頭から順に離れすぎた節を 1/linkDiv ずつ引き寄せる
void Sandworm_PullSegments(Sandworm* p, s32 followDiv, s32 linkDiv, s32 followDistSq) {
  Sandworm* q = (p->e).owner;
  Vec3 d1, d2, prev;
  s32 i;

  prev = (p->e).s->aux.spr.pos;
  for (i = 0; i < q->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
      Vec3_Diff(&d1, &q->segments[i].targetPos, &q->segments[i].sprite.pos);
      if (d1.x * d1.x + d1.y * d1.y + d1.z * d1.z > followDistSq) {
        followDiv = followDiv >= 1 ? followDiv : 1;
        q->segments[i].sprite.pos.x += Div(d1.x, followDiv);
        q->segments[i].sprite.pos.y += Div(d1.y, followDiv);
        q->segments[i].sprite.pos.z += Div(d1.z, followDiv);
      }
    }
  }
  prev = (p->e).s->aux.spr.pos;
  for (i = 0; i < q->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
      Vec3_Diff(&d2, &prev, &q->segments[i].sprite.pos);
      if (d2.x * d2.x + d2.y * d2.y + d2.z * d2.z > 12724) {
        q->segments[i].sprite.pos.x += Div(d2.x, linkDiv);
        q->segments[i].sprite.pos.y += Div(d2.y, linkDiv);
        q->segments[i].sprite.pos.z += Div(d2.z, linkDiv);
      }
      prev = q->segments[i].sprite.pos;
    }
  }
  Sandworm_FaceSegmentsForward(p);
}

void Sandworm_SetAllSegmentsPos(Sandworm* p, Vec3* pos) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    p->segments[i].sprite.pos = *pos;
    p->segments[i].targetPos = *pos;
  }
}

void Sandworm_InitHitboxes(Sandworm* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 128, 128, 128);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Sandworm_OnHurt, p);
  VEC3_SET(hitSize, 82, 82, 82);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Sandworm_OnHit, 0, p);
  Hitbox_SetFlags(&(p->e).hitbox, HBF_ONCE);
}

void Sandworm_OnReset(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  q->flags &= (u16)~SANDFLAG_UNK_1;
  q->blockedTimer = 0;
  q->turnTileIdx = 0;
  q->unk_1021 = Random() & 3;
  q->hoverPhase = 0;
  Enemy_SetSpritePos(&p->e, &q->homePos);
  (p->e).mover.pos = q->homePos;
  Sandworm_ResetRecentTiles(p);
  Sandworm_SetAllSegmentsPos(q, &(p->e).mover.pos);
  Sandworm_PickNextTile(p);
  ClearMemory((p->e).pathNodePos, 8);
  Enemy_ResetState(&p->e, 0, 0, 2);
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
}

// 頭と奇数番目の節を sin で揺らし, 偶数番目の節を前後の位置の中ほどに置く
// 308/279命令, Serpent/Salamander_SwayBody と同じ Hermite 曲線の壁, 1回目の下書きで切り上げ
NON_MATCH void Sandworm_SwayBody(Sandworm* p) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
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
    Sandworm_SetSegmentPos(q, i, &pos);
    prev = q->segments[i + 1].sprite.pos;
  }
#else
  INCFUNC("asm/func/Sandworm_SwayBody.inc");
#endif
}

// SANDSEGFLAG_DESTROYED が落ちている節の1つおきに SANDSEGFLAG_FOLLOW を落とす
void Sandworm_UnfollowAlternateSegments(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  SandwormSegment* segs = q->segments;
  s32 n = 0;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&segs[i], SANDSEGFLAG_DESTROYED)) {
      if (n == 1) {
        n = 0;
      } else {
        CLEAR_FLAGS(segs[i].flags, SANDSEGFLAG_FOLLOW);
        n++;
      }
    }
  }
}

// 尾から見て最初の壊れていない節を壊す, 壊せたら TRUE
s32 Sandworm_DestroyTailSegment(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  SandwormSegment* segs = q->segments;
  s32 i;

  for (i = q->segmentCount - 1; i >= 0; i--) {
    if (!Sandworm_TestSegmentFlags(&segs[i], SANDSEGFLAG_DESTROYED)) {
      Hitbox_Unregister(&segs[i].hurtbox);
      SET_FLAGS(segs[i].flags, SANDSEGFLAG_DESTROYED);
      q->segmentsLeft--;
      Sandworm_ScatterParticles(&segs[i].sprite.pos, 10);
      return TRUE;
    }
  }
  return FALSE;
}

// 残っている節を尾から全て壊し, それぞれの位置に粒を撒く
void Sandworm_DestroyAllSegmentsWithParticles(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  SandwormSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft != 0) {
    for (i = q->segmentCount - 1; i >= 0; i--) {
      if (!Sandworm_TestSegmentFlags(&segs[i], SANDSEGFLAG_DESTROYED)) {
        Hitbox_Unregister(&segs[i].hurtbox);
        SET_FLAGS(segs[i].flags, SANDSEGFLAG_DESTROYED);
        q->segmentsLeft--;
        Sandworm_ScatterParticles(&segs[i].sprite.pos, 10);
      }
    }
  }
}

// 残っている節を尾から全て壊し, 食らい判定を外す
void Sandworm_DestroyAllSegments(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  SandwormSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft != 0) {
    for (i = q->segmentCount - 1; i >= 0; i--) {
      if (!Sandworm_TestSegmentFlags(&segs[i], SANDSEGFLAG_DESTROYED)) {
        Hitbox_Unregister(&segs[i].hurtbox);
        SET_FLAGS(segs[i].flags, SANDSEGFLAG_DESTROYED);
        q->segmentsLeft--;
      }
    }
  }
}

void Sandworm_AdvanceSwayIfMoving(Sandworm* p, s32 speed) {
  if (speed != 0) {
    ((Sandworm*)(p->e).owner)->swayAngle += 4;
  }
}

// jumpVel が速いほど広い向きの範囲へ, 前の節を追う節をばらばらの向きに速さ 12 で散らす
void Sandworm_ScatterSegments(Sandworm* p) {
  Sandworm* q = (p->e).owner;
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
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
      Vec3_SetPolar(&q->segments[i].velocity, Random() & spread, 12);
    }
  }
}

// 前の節を追っている節を床の高さに合わせる, 潜っていれば床へ (深すぎれば頭の高さへ), 浮いていれば差の 1/10 ずつ下げる
// 159/160命令, Serpent/Salamander_SnapSegmentsToFloor と同じ壁 (原典は節の座標を誘導変数にして p をレジスタに置く), 1回目の下書きで切り上げ
NON_MATCH void Sandworm_SnapSegmentsToFloor(Sandworm* p) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
  s32 i;

  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_20)) {
    for (i = 0; i < q->segmentCount; i++) {
      if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
        Vec3* pos = &q->segments[i].sprite.pos;
        s32 height = TileHeightAt(pos);

        if (pos->y != height) {
          if (pos->y < height) {
            if (abs(height - pos->y) > 255) {
              q->segments[i].sprite.pos.y = (p->e).mover.pos.y;
            } else {
              q->segments[i].sprite.pos.y = height;
            }
          } else {
            q->segments[i].sprite.pos.y += Div(height - pos->y, 10);
          }
        }
      }
    }
  }
#else
  INCFUNC("asm/func/Sandworm_SnapSegmentsToFloor.inc");
#endif
}

// 前の節を追う節を velocity だけ動かし, velocity を半分に減らす
void Sandworm_ApplySegmentVelocity(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FOLLOW) && !Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
      q->segments[i].sprite.pos.x += q->segments[i].velocity.x;
      q->segments[i].sprite.pos.y += q->segments[i].velocity.y;
      q->segments[i].sprite.pos.z += q->segments[i].velocity.z;
      q->segments[i].velocity.x = FixToInt(1, q->segments[i].velocity.x);
      q->segments[i].velocity.y = FixToInt(1, q->segments[i].velocity.y);
      q->segments[i].velocity.z = FixToInt(1, q->segments[i].velocity.z);
    }
  }
}

void FUN_08178a34(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (Sandworm_TestFlags(q, SANDFLAG_UNK_1)) {
    Enemy_ResetState(&p->e, 0, 0, 4);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    (p->e).unk_544 = 180;
    (p->e).unk_1bc = 2;
  }
  CLEAR_FLAGS(q->flags, SANDFLAG_UNK_1);
}

void Sandworm_OnSegmentDamaged(Sandworm* p, Hitbox* hitbox, SandwormSegment* seg) {
  if (!Enemy_IsDead(&p->e) && !Sandworm_TestFlags((p->e).owner, SANDFLAG_DYING)) {
    Vec3 v;

    ((Sandworm*)(p->e).owner)->damageAccum += hitbox->damage;
    Vec3_Clear(&v);
    CreateDamageNumber(hitbox, hitbox->damage, 0, &seg->sprite.pos, &v, 1);
  }
}

void Sandworm_OnSegmentHit(Hitbox* a, Hitbox* b, SandwormSegment* seg) {}

// 節の食らい判定に当たったとき, ダメージを足して白く光らせ, 弱点に当たっていれば当たった向きに煙を出す
// 218/221命令, Serpent_OnSegmentHurt と同じ壁 (原典は &q->flags を r8 に置き seg を下位レジスタに置く), 1回目の下書きで切り上げ
NON_MATCH void Sandworm_OnSegmentHurt(Hitbox* a, Hitbox* b, SandwormSegment* seg) {
#ifdef NONMATCHING_C
  Sandworm* q = seg->owner;

  if (!Enemy_IsDead(&q->e) && !Sandworm_TestFlags(q, SANDFLAG_DYING) && seg->hurtbox.iframes == 0) {
    Hitbox_ApplyDamage(a, b);
    b->iframes = a->iframes;
    Sandworm_OnSegmentDamaged(q, b, seg);
    Sandworm_FlashSegment(seg);
    a->damage += (q->e).unk_188;
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
    SET_FLAGS(q->flags, SANDFLAG_UNK_6);
    if (b->hitResult & HBRESULT_WEAK) {
      u8 angle;
      Vec3 size;
      WorldPos pos;

      if (a->flags & HBF_ANGLE) {
        angle = a->angle;
      } else {
        Vec3 d;

        Vec3_Diff(&d, &a->pos, &b->pos);
        if (d.x == 0 && d.z == 0) {
          angle = Random();
        } else {
          angle = ArcTan2_8(d.x, d.z);
        }
      }
      pos = seg->sprite.pos;
      pos.y += (u8)Random();
      angle = (s8)angle + (Random() & 0x1F) - 16;
      VEC3_SET(size, 60, 120, 40);
      EmitSmoke(&pos, 2, &size, angle, (Random() & 7) + 4, (Random() & 7) + 8, 2, 1);
    }
  }
#else
  INCFUNC("asm/func/Sandworm_OnSegmentHurt.inc");
#endif
}

// unk_1028 の節を knockbackAngle の向きへ弾く
void Sandworm_KnockBackSegment(Sandworm* p) {
  if (p->unk_1024 != 0x7FFFFFFF) {
    SandwormSegment* seg = p->unk_1028;

    p->unk_1024 = 0x7FFFFFFF;
    Vec3_SetPolar(&seg->velocity, seg->knockbackAngle, seg->hurtbox.knockback);
  }
}

// 節ごとに食らい判定 (防御力は尾が tailDefense, 他はその 2 倍) と攻撃判定を組む
void Sandworm_InitSegmentHitboxes(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  Vec3 halfSize, offset;
  s32 i;

  VEC3_SET(halfSize, 64, 128, 64);
  VEC3_SET(offset, 0, 128, 0);
  for (i = 0; i < q->segmentCount; i++) {
    SandwormSegment* seg = &q->segments[i];

    Hitbox_Init(&seg->hurtbox, (p->e).mover.id, HBF_HURTBOX | HBF_ACTOR | HBF_3 | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    if (i == q->segmentCount - 1) {
      Hitbox_SetPowerAndAttributes(&seg->hurtbox, q->tailDefense, (p->e).attrs, (p->e).weakness);
    } else {
      Hitbox_SetPowerAndAttributes(&seg->hurtbox, q->tailDefense * 2, (p->e).attrs, (p->e).weakness);
    }
    Hitbox_SetPos(&seg->hurtbox, &seg->sprite.pos, 0);
    Hitbox_SetHandler(&seg->hurtbox, Sandworm_OnSegmentHurt, seg);
  }
  VEC3_SET(halfSize, 48, 100, 48);
  VEC3_SET(offset, 0, 128, 0);
  for (i = 0; i < q->segmentCount; i++) {
    SandwormSegment* seg = &q->segments[i];

    Hitbox_Init(&seg->hitbox, (p->e).mover.id, HBF_HITBOX | HBF_ONCE | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    Hitbox_SetAttack(&seg->hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetPos(&seg->hitbox, &seg->sprite.pos, 0);
    Hitbox_SetHandler(&seg->hitbox, Sandworm_OnSegmentHit, seg);
  }
}

void Sandworm_InitAnims(Sandworm* p) {
  Enemy_SetAnimEntry(&p->e, 14, 5, 0);
  Enemy_SetAnimEntry(&p->e, 17, 10, 0);
  Enemy_SetAnimEntry(&p->e, 15, 6, 0);
  Enemy_SetAnimEntry(&p->e, 16, 7, 0);
}

// 歩きアニメのコマの頭でだけ進む速さ, SANDFLAG_UNK_4 で倍, 弱っていればさらに倍
s32 Sandworm_GetMoveSpeed(Sandworm* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if ((p->e).unk_546 > (p->e).hp) {
    if (anim->tick == 0) {
      if (Sandworm_TestFlags((p->e).owner, SANDFLAG_UNK_4)) {
        return sSandwormMoveSpeeds[anim->cmdIdx & 3] * 4;
      }
      return sSandwormMoveSpeeds[anim->cmdIdx & 3] * 2;
    }
  } else if (anim->tick == 0) {
    if (Sandworm_TestFlags((p->e).owner, SANDFLAG_UNK_4)) {
      return sSandwormMoveSpeeds[anim->cmdIdx & 3] * 2;
    }
    return sSandwormMoveSpeeds[anim->cmdIdx & 3];
  }
  return 0;
}

// 跳ぶ先が高い段差や壁, 水場なら跳ぶのをやめ, 進めないまま 30 フレームより長く経ったら次の行き先を選んで向き直る
void Sandworm_KeepOnGround(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  WorldPos next;
  s32 idx;
  u32 attr;
  s32 height;

  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (Sandworm_TestFlags(q, SANDFLAG_DYING | SANDFLAG_UNK_7)) {
    q->blockedTimer = 0;
    return;
  }
  Sandworm_AddVelocity(&next, &(p->e).mover.pos, &(p->e).jumpVel);
  idx = GetCollisionTileIdx(&next);
  attr = TileAttrAtIndex(idx);
  height = TileHeightAtIndex(idx, &next);
  if ((p->e).floorY < height || (attr & (TATTR_FALLDEATH | 3))) {
    (p->e).jumpVel.x = 0;
    (p->e).jumpVel.z = 0;
  }
  if (Sandworm_TestFlags(q, SANDFLAG_UNK_2 | SANDFLAG_DYING | SANDFLAG_UNK_7)) {
    q->blockedTimer = 0;
    return;
  }
  if ((p->e).mover.tile->unk_0[0] & 1) {
    if (++q->blockedTimer > 30) {
      q->unk_1021 = (q->unk_1021 + 1) & 3;
      Sandworm_PickNextTile(p);
      Vec3_Delta(&next, &(p->e).mover.pos, &(p->e).navAgent->dest);
      (p->e).unk_1dc = ArcTan2_8(next.x, next.z);
      if (abs(Sandworm_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
        Enemy_ResetState(&p->e, 0, 0, 1);
      }
    }
  } else {
    q->blockedTimer = 0;
  }
}

// pos から6方向へ煙を出す
void Sandworm_EmitSmokeAround(WorldPos* pos) {
  Vec3 size;

  VEC3_SET(size, 80, 60, 60);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0x40, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0x80, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0xF0, 4, 20, 2, 1);
}

void Sandworm_UpdateAnimSpeed(Sandworm* p) {
  if ((p->e).unk_544 != 0) {
    if ((p->e).unk_544 < 60) {
      (p->e).animSpeedDiv = 2;
    } else {
      (p->e).animSpeedDiv = 3;
    }
  } else {
    (p->e).animSpeedDiv = 1;
  }
}

void Sandworm_ResetRecentTiles(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    q->recentTiles[i] = (p->e).tileIdx;
  }
  q->recentTileIdx = 0;
}

bool8 Sandworm_IsRecentTile(Sandworm* p, u32 tileIdx) {
  Sandworm* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    if (q->recentTiles[i] == tileIdx) {
      return TRUE;
    }
  }
  return FALSE;
}

void Sandworm_AddRecentTile(Sandworm* p, u32 tileIdx) {
  Sandworm* q = (p->e).owner;

  q->recentTiles[q->recentTileIdx] = tileIdx;
  q->recentTileIdx = (q->recentTileIdx + 1) & 3;
}

void Sandworm_OnAttackRequest(Sandworm* p) {
  Enemy_ResetState(&p->e, 0, 2, 0);
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
}

void FUN_081795a8(Sandworm* p) {}

// 範囲内のプレイヤーが正面の 1/4 にいて高さの差も小さければ, 向きをプレイヤーの方へ決めて TRUE
bool8 Sandworm_TryDetectPlayer(Sandworm* p) {
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
        Sandworm* q = (p->e).owner;

        q->unk_1021 = (((p->e).playerAngle + 0x80) & 0xFF) >> 6;
        q->unk_1020 = 14;
        return TRUE;
      }
    }
  }
  return FALSE;
}

// SANDFLAG_UNK_2 に合わせて攻撃判定の威力を atk の [0] か [1] に切り替える
void Sandworm_SelectAttack(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !Sandworm_TestFlags(q, SANDFLAG_DYING) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP | ENEFLAG3_STUN | ENEFLAG3_PETRIFIED | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    if (Sandworm_TestFlags(q, SANDFLAG_UNK_2)) {
      Hitbox_ClearFlags(&(p->e).hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      Hitbox_SetFlags(&(p->e).hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
}

void FUN_08179778(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  SandwormSegment* segs = q->segments;
  s32 n = 0;
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Sandworm_TestSegmentFlags(&segs[i], SANDSEGFLAG_DESTROYED)) {
      if (segs[i].unk_120 != 0) {
        segs[i].unk_120--;
      } else if (n < 2) {
        segs[i].unk_120 = 3;
        SET_FLAGS(segs[i].flags, SANDSEGFLAG_UNK_7);
        n++;
      }
    }
  }
}

// 頭と節の当たり判定を出し入れする, 節の攻撃判定はプレイヤーが近いときだけ載せて SANDFLAG_UNK_2 で atk の [0] / [1] を選ぶ
void Sandworm_UpdateHitboxes(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  Vec3 d;
  s32 i;

  if (Enemy_IsDead(&p->e) || Sandworm_TestFlags(q, SANDFLAG_UNK_4 | SANDFLAG_DYING) || ((p->e).s->aux.spr.flags & SPRFLAG_HIDDEN)) {
    Hitbox_Hide(&(p->e).hitbox);
    Hitbox_Hide(&(p->e).hurtbox);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  } else {
    Hitbox_ClearFlags(&(p->e).hitbox, HBF_HIDDEN);
    Hitbox_ClearFlags(&(p->e).hurtbox, HBF_HIDDEN);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  for (i = 0; i < q->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
      continue;
    }
    if (!Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_UNK_7) || (q->segments[i].sprite.flags & SPRFLAG_HIDDEN) || Sandworm_TestFlags(q, SANDFLAG_DYING)) {
      Hitbox_Hide(&q->segments[i].hitbox);
      Hitbox_Hide(&q->segments[i].hurtbox);
      continue;
    }
    Hitbox_SetPos(&q->segments[i].hurtbox, &q->segments[i].sprite.pos, 0);
    Hitbox_Register(&q->segments[i].hurtbox);
    Hitbox_ClearFlags(&q->segments[i].hurtbox, HBF_HIDDEN);
    Vec3_Delta(&d, &q->segments[i].sprite.pos, &gPlayerPtr[0]->mover.pos);
    if (d.x * d.x + d.z * d.z > 0xFFFF) {
      continue;
    }
    Hitbox_ClearFlags(&q->segments[i].hitbox, HBF_HIDDEN);
    Hitbox_SetPos(&q->segments[i].hitbox, &q->segments[i].sprite.pos, 0);
    Hitbox_Register(&q->segments[i].hitbox);
    if (Sandworm_TestFlags(q, SANDFLAG_UNK_2)) {
      Hitbox_ClearFlags(&q->segments[i].hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&q->segments[i].hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      Hitbox_SetFlags(&q->segments[i].hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&q->segments[i].hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
}

// 聞こえた音があれば, その場所へ地中からワームの尻尾 (WormTail) を呼ぶ, 動きは乱数で2通り
// 163/162命令, 引数の番地を作るレジスタが1つずれる (原典は 0x21D の r7 を使い回し IsDead の 0 を r8 に残す), Tier C (局所変数, 乱数の書き方) は試済
NON_MATCH bool8 Sandworm_TrySummonWorms(Sandworm* p) {
#ifdef NONMATCHING_C
  if (!Enemy_IsDead(&p->e)) {
    Sandworm* q = (p->e).owner;

    if (WormTail_IsIdle()) {
      s32 idx = NoiseManager_FindFirstHeardNoise((p->e).mover.pos.x, (p->e).mover.pos.z, (p->e).range2, (p->e).unk_21d | 2, (p->e).mover.id);

      if (idx >= 0) {
        FUN_080e8f20(&p->e, idx);
        if ((Random() & 0xFF) < 0x80) {
          WormTail_Spawn(&(p->e).unk_204, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2], q->wormMoveTime0, 32, 24, q->wormEmergeDelay0, 0, q->tailDefense, (p->e).attrs, (p->e).weakness);
        } else {
          WormTail_Spawn(&(p->e).unk_204, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2], q->wormMoveTime1, 32, 24, q->wormEmergeDelay1, 1, q->tailDefense, (p->e).attrs, (p->e).weakness);
        }
        return TRUE;
      }
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Sandworm_TrySummonWorms.inc");
#endif
}

void Sandworm_FlashSegment(SandwormSegment* seg) {
  SET_FLAGS(seg->flags, SANDSEGFLAG_FLASH);
  Video_SetAuxSpritePltt(&seg->gfx, OBP_WHITE_306);
  seg->flashTimer = 6;
}

// 被弾で白くした節を flashTimer が尽きたら元の色に戻し, 無敵時間中の節を点滅させる
void Sandworm_UpdateSegmentFlash(Sandworm* p) {
  Sandworm* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_FLASH)) {
      if (q->segments[i].flashTimer != 0) {
        q->segments[i].flashTimer--;
      } else {
        Video_SetAuxSpritePltt(&q->segments[i].gfx, 418);
        q->segments[i].flashTimer = 0;
        CLEAR_FLAGS(q->segments[i].flags, SANDSEGFLAG_FLASH);
      }
    }
    if (q->segments[i].hurtbox.iframes != 0) {
      if ((q->segments[i].hurtbox.iframes >> 2) & 1) {
        q->segments[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      } else {
        q->segments[i].sprite.flags |= SPRFLAG_HIDDEN;
      }
      q->segments[i].hurtbox.iframes--;
      if (q->segments[i].hurtbox.iframes == 0) {
        q->segments[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      }
    }
  }
}

// 床より下にある頭と節のスプライトを隠し, 床より上で無敵時間が切れていれば戻す
// 198/185命令, 床の高さを見る節のループの壁 (Serpent/Salamander と同じ), 2回目で切り上げ
NON_MATCH void Sandworm_HideBuriedSprites(Sandworm* p) {
#ifdef NONMATCHING_C
  Sandworm* q = (p->e).owner;
  s32 i;

  if ((p->e).state == ES_DYING) {
    return;
  }
  if ((p->e).mover.pos.y < (p->e).floorY || (p->e).floorY == 0) {
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
  } else if ((p->e).hurtbox.iframes == 0) {
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
  }
  for (i = 0; i < q->segmentCount; i++) {
    if (!Sandworm_TestSegmentFlags(&q->segments[i], SANDSEGFLAG_DESTROYED)) {
      if (q->segments[i].sprite.pos.y < TileHeightAt(&q->segments[i].sprite.pos) || (p->e).floorY == 0) {
        q->segments[i].sprite.flags |= SPRFLAG_HIDDEN;
      } else if (q->segments[i].hurtbox.iframes == 0) {
        q->segments[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      }
    }
  }
#else
  INCFUNC("asm/func/Sandworm_HideBuriedSprites.inc");
#endif
}

void Sandworm_RunScript(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if (q->scriptID != 0) {
    u32 argv[1];
    ScriptArgs sa;

    argv[0] = (p->e).mover.id;
    sa.argc = 1;
    sa.argv = argv;
    VM_ExecByID(q->scriptID, &sa);
    q->scriptID = 0;
  }
}

// hp が unk_546 (最大の 1/4) を上回っているかどうかで unk_f98..unk_fa6 を選び直す
void Sandworm_UpdateHpParams(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  if ((p->e).unk_546 >= (p->e).hp) {
    q->unk_f98 = 40;
    q->wanderTime = 220;
    q->wormMoveTime0 = 30;
    q->wormEmergeDelay0 = 8;
    q->wormMoveTime1 = 64;
    q->wormEmergeDelay1 = 10;
    q->tunnelTime = (Random() & 0x3F) + 100;
    q->unk_fa6 = 1;
  } else {
    q->unk_f98 = 80;
    q->wanderTime = 600;
    q->wormMoveTime0 = 80;
    q->wormEmergeDelay0 = 40;
    q->wormMoveTime1 = 100;
    q->wormEmergeDelay1 = 30;
    q->tunnelTime = (Random() & 0x3F) + 200;
    q->unk_fa6 = 3;
  }
}

// 106/125命令, Serpent の FUN_08193ca4 と同じ壁 (原典は jumpVel.x と jumpVel.z の abs を求めて捨てる), 1回目の下書きで切り上げ
NON_MATCH void FUN_0817a05c(Sandworm* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Sandworm_StateHover, ES_UNK_34);
    (p->e).unk_1bc = 8;
  }
  Sandworm_PullSegments(p, 4, 12, 0x6400);
  Sandworm_UpdateWave(p, 430, 40);
  if ((p->e).subStateDone) {
    Sandworm_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_0817a05c.inc");
#endif
}

void Sandworm_SetHandlerTable4(Sandworm* p) { (p->e).handlerTables[4] = (void*)sSandwormHandlerTable4; }

s32 Sandworm_PreUpdate(Sandworm* p) {
  Sandworm_KnockBackSegment(p);
  Sandworm_UpdateSegmentFlash(p);
  Sandworm_UpdateHpParams(p);
  return 1;
}

s32 Sandworm_PostUpdate(Sandworm* p) {
  FUN_08179778(p);
  Sandworm_UpdateHitboxes(p);
  Sandworm_SelectAttack(p);
  Sandworm_UpdateAnimSpeed(p);
  Sandworm_HideDestroyedSegments(p);
  Sandworm_FollowSegments(p);
  Sandworm_ApplySegmentVelocity(p);
  Sandworm_SnapSegmentsToFloor(p);
  Sandworm_KeepOnGround(p);
  Sandworm_HideBuriedSprites(p);
  return 1;
}

// hp が残る被弾への反応, 姿を見せて移動中なら向き直って副状態 5 へ移し, 影を隠す
bool8 Sandworm_OnDamaged(Sandworm* p) {
  Sandworm* q = (p->e).owner;

  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8);
  PlaySound_082406e0(SONG_987);
  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  if (!((p->e).s->aux.spr.flags & SPRFLAG_HIDDEN) && *(u16*)&(p->e).subState0 == 0 && ((p->e).subState2 == 1 || (p->e).subState2 == 2 || (p->e).subState2 == 12 || (p->e).subState2 == 15)) {
    (p->e).unk_544 = 240;
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 5);
    (p->e).mover.angle = (p->e).playerAngle;
    (p->e).animSpeedDiv = 1;
    q->crawlTimer = 0;
    CLEAR_FLAGS(q->flags, SANDFLAG_UNK_2);
    AuxShadow_Hide(&(p->e).auxShadow);
  }
  return TRUE;
}

s32 Sandworm_UpdateFrame(Sandworm* p) {
  Sandworm_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Sandworm_PostUpdate(p);
  return 1;
}

s32 Sandworm_Update(Sandworm* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), GAMEFLAG_GAMEOVER) || TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return FALSE;
  }

  if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_1)) {
    if (!IsCurrentZone((p->e).zoneID)) {
      Enemy_Suspend(&p->e, NULL);
      return FALSE;
    }

    Sandworm_ApplyDamage(p);
    if (!Enemy_IsDead(&p->e) && !(p->e).unk_624(&p->e)) {
      (p->e).unk_628(&p->e);
    }
    Enemy_ProcessRequests(&p->e);
    FUN_080e1f48(&p->e);
    (p->e).handlerFrame((p->e).owner);
    Enemy_UpdateHitboxes(&p->e);
    Enemy_UpdateMovement(&p->e);
    Enemy_ShakeSprite(&p->e);
    FUN_080f06ac(&p->e);
    return TRUE;
  }

  if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_0) && IsCurrentZone((p->e).zoneID)) {
    Enemy_Resume(&p->e, NULL);
  }
  FUN_080f06ac(&p->e);
  return FALSE;
}

s32 Sandworm_Destroy(Sandworm* p) {
  sound_08240740(SONG_996);
  Sandworm_RemoveSegmentSprites(p);
  if (!(p->e).shadowRemoved) {
    AuxShadow_Remove(&(p->e).auxShadow);
    (p->e).shadowRemoved = 0xFF;
  }
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
// 1735/1932命令の下書き, Serpent_Init / Salamander_Init と同じ敵共通 inline の壁 (原典はフィールドの番地をスタックに作り置く), 1回目の下書きで切り上げ
NON_MATCH s32 Sandworm_Init(Sandworm* p) {
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
  (p->e).kind = ENEK_SANDWORM;
  Sandworm_InitAnims(p);
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
    p->tailDefense = VM_GetPC() != NULL ? VM_GetValue() : 300;
  }
  p->scriptID = VM_GetNamedArgValue('d', 0);
  p->crawlTimer = 0;
  Sandworm_ResetRecentTiles(p);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 418;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 418;
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

  Sandworm_InitHitboxes(p);
  Sandworm_InitFollowInterval(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Sandworm_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Sandworm_GetMoveSpeed;
  (p->e).handlerTurn = Sandworm_StateTurn;
  (p->e).handlerMove = Sandworm_StateMove;
  (p->e).handlerWait = Sandworm_StateWait;
  (p->e).handlerNap = Sandworm_StateNap;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Sandworm_StateDamaged;
  (p->e).handlerDying = Sandworm_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = Sandworm_StateRespawnWait;
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
  (p->e).unk_5e0 = Sandworm_ClearStateBegun;
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
  (p->e).msgHandlers = (void*)sSandwormMsgHandlers;
  (p->e).onReset = (EnemyHandler)Sandworm_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).onAttackRequest = (EnemyHandler)Sandworm_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)FUN_081795a8;
  (p->e).tryDetectPlayer = (void*)Sandworm_TryDetectPlayer;
  (p->e).onDamaged = (void*)Sandworm_OnDamaged;
  (p->e).unk_5b4 = (EnemyHandler)Sandworm_ScatterSegments;
  (p->e).unk_1bc = 0;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9 | ENEFLAG_UNK_20);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_25);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_6 | ENEFLAG5_UNK_7);
  Enemy_InitShadowAndEmitter(&p->e);
  (p->e).shadowRemoved = AuxShadow_Init(&(p->e).auxShadow, &(p->e).mover.pos, 64, 64, 64, 100, 0, 0, 5, 1, 0);
  AuxShadow_SetSprite(&(p->e).auxShadow, SPR_EFF_1C1B, 7);
  AuxShadow_SetAffine(&(p->e).auxShadow, 0);
  AuxShadow_Hide(&(p->e).auxShadow);
  (p->e).emitterRemoved = 1;

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
  Enemy_InitHandlerTables(&p->e);
  Sandworm_SetHandlerTable2(p);
  Sandworm_SetHandlerTable4(p);
  Sandworm_InitSegments(p, SPR_WORM, ANIM_WORM, (p->e).mover.angle);
  Sandworm_SetAllSegmentsPos(p, &(p->e).mover.pos);
  Sandworm_InitSegmentHitboxes(p);
  Sandworm_PickNextTile(p);
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
  (p->e).handlerUpdate = (EnemyHandler)Sandworm_Update;
  (p->e).handlerDestroy = (EnemyHandler)Sandworm_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Sandworm_Init.inc");
#endif
}

// 0x706D, HashName("サンドウォーム")
void Sandworm_Create(void) {
  Sandworm* p = Malloc(sizeof(Sandworm));

  if (p != NULL) {
    ClearMemory(p, sizeof(Sandworm));
    if (Sandworm_Init(p) < 0) {
      Sandworm_Destroy(p);
      Free(p);
    }
  }
}

// プレイヤーへ向けて水平に 32 の速さで跳ね, 着くまでの時間から縦の速さを決める
void Sandworm_AimJumpAtPlayer(Sandworm* p) {
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
