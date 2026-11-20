#include "cwolf_target.h"
#include "debris.h"
#include "eff_elemcond.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "global.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "vm.h"

struct Salamander;

// SalamanderSegment.flags (0xAD)
typedef u8 SalamanderSegmentFlags;
#define SALSEGFLAG_DESTROYED (1 << 0)  // 0x01, 壊れた節, 位置の更新を飛ばされて隠される
#define SALSEGFLAG_FOLLOW (1 << 1)     // 0x02, 立っていて SALSEGFLAG_DESTROYED が落ちている節だけが1つ前の節の位置を引き継ぐ
#define SALSEGFLAG_UNK_2 (1 << 2)      // 0x04, 尾の節だけに立つ
#define SALSEGFLAG_UNK_3 (1 << 3)      // 0x08, 後ろの2節に立つ
#define SALSEGFLAG_UNK_4 (1 << 4)      // 0x10, 後ろの2節以外に立つ
#define SALSEGFLAG_FLASH (1 << 6)      // 0x40, 被弾して白く光っている

// サラマンダーの体の節1つ, 補助スプライトとアニメを持ち, 先頭から順に頭の跡を追う
typedef struct {
  AuxSprite sprite;              // 0x00
  AuxSpriteGfx gfx;              // 0x2C, ID は固定でない
  Hitbox hitbox;                 // 0x48, 節ごとの攻撃判定
  AuxAnimState anim;             // 0x98, cmdIdx を節ごとに 0..8 でずらして始める
  AuxAnimFile* animFile;         // 0xA8, ID は固定でない
  u8 angle;                      // 0xAC, 節の向き
  SalamanderSegmentFlags flags;  // 0xAD
  u8 unk_ae[3];                  // 0xAE
  u8 swayAngle;                  // 0xB1, 奇数番目の節を横に揺らす sin の角度
  u8 wobbleAngle;                // 0xB2, velocity を sin で揺らす角度, 頭から節ごとに 24 ずつずらして始める
  u8 flashTimer;                 // 0xB3, 白く光らせるフレーム数, 6
  u8 unk_b4[8];                  // 0xB4
  Vec3 targetPos;                // 0xBC, 1つ前の節の位置, sprite.pos がここへ寄っていく
  Vec3 velocity;                 // 0xC4, sprite.pos に足したあと半分に減らす
  struct Salamander* owner;      // 0xCC
} SalamanderSegment;
static_assert(sizeof(SalamanderSegment) == 208);

// Salamander.flags (0xCA0)
typedef u16 SalamanderFlags;
#define SALAFLAG_UNK_1 (1 << 1)  // 0x02, 立っていると副状態 (0, 0, 4) へ移して落とす
#define SALAFLAG_UNK_2 (1 << 2)  // 0x04, 立っていると攻撃判定に atk の [1] を載せ, HBF_ANGLE を外す
#define SALAFLAG_UNK_3 (1 << 3)  // 0x08, 着地して地中へ潜り始めると立つ
#define SALAFLAG_UNK_4 (1 << 4)  // 0x10, SALAFLAG_DYING と同じく立っていると当たり判定を全部隠す
#define SALAFLAG_DYING (1 << 5)  // 0x20, 死に際の爆発に入ると立つ, 立っていると受けたダメージを damageAccum に足さない
#define SALAFLAG_UNK_6 (1 << 6)  // 0x40, 食らい判定を通るたびに立つ
#define SALAFLAG_UNK_7 (1 << 7)  // 0x80, SALAFLAG_UNK_2 / SALAFLAG_DYING と同じく立っていると行き詰まりの数えを止める
#define SALAFLAG_UNK_8 (1 << 8)  // 0x100, 着地したときに立っていれば効果音を変えて落とす
#define SALAFLAG_UNK_9 (1 << 9)  // 0x200, 立っていると地中から跳び出すときに足元で爆発させない (1回で落ちる)

// サラマンダー, リッチ+(ENEID_LICH_P) が出してくる炎の蛇 (技名はインフェルノ?), 火の粉を撒き散らしながらステージを跳ねまわる
// リッチ+ の技なので敵IDとかはない?
typedef struct Salamander {
  Enemy e;
  u8 unk_654[4];                  // 0x654
  SalamanderSegment segments[6];  // 0x658
  u8 unk_b38[0xB57 - 0xB38];      // 0xB38
  s8 diveCount;                   // 0xB57, 地中へ潜り終えるたびに 1 増える, 4 を超えると潜るのをやめる
  WormPaletteFade fade;           // 0xB58, OBP 421 と 422 の間を 20 歩ずつ行き来する
  bool8 fadeToAlt;                // 0xC3C, 1 なら次のフェードは OBP 422 へ, 0 なら OBP 421 へ向かう
  u8 unk_c3d[3];                  // 0xC3D
  u16 scriptID;                   // 0xC40, '.d', 一度実行すると 0
  u16 damageAccum;                // 0xC42, 受けたダメージの累計
  u8 followInterval;              // 0xC44, 節が1つ前の節の位置を引き継ぐ間隔 (フレーム)
  u8 hoverPhase;                  // 0xC45, 宙での揺れ, bit7 で前後の向き, bit4-6 で速さ, 1回に 12 ずつ進む
  u8 unk_c46[2];                  // 0xC46
  u16 unk_c48;                    // 0xC48
  u16 unk_c4a;                    // 0xC4A, '.P=300'
  u8 recentTileIdx;               // 0xC4C, recentTiles の次に書く添字, 0..3 を巡回する
  u8 unk_c4d;                     // 0xC4D
  u16 turnTileIdx;                // 0xC4E, 向き直りを始めたタイルの索引, そこから出ないようにする
  u16 recentTiles[6];             // 0xC50, 最近通ったタイルの索引, 行き先の候補から外す, 書くのは先頭4つだけ
  u8 unk_c5c[0xCA0 - 0xC5C];      // 0xC5C
  SalamanderFlags flags;          // 0xCA0
  u8 swayAngle;                   // 0xCA2, 頭の位置を sin で揺らす角度
  u8 shiftTimer;                  // 0xCA3, 0 になるたびに 12 に戻して頭, 中, 尾の節の位置を1つずつ後ろへ送る
  s8 waveDir;                     // 0xCA4, 1 / -1, waveOffset を動かす向き
  u8 unk_ca5[3];                  // 0xCA5
  s16 waveOffset;                 // 0xCA8, -振幅..振幅 を往復する
  s16 segmentCount;               // 0xCAA, 節の数, 6
  u8 unk_cac[0xCB4 - 0xCAC];      // 0xCAC
  u16 unk_cb4;                    // 0xCB4, 行き先を選び直すたびに 40
  u8 unk_cb6;                     // 0xCB6
  u8 riseSpeed;                   // 0xCB7, 地中から出てくるときの上昇の速さ, 14 フレームごとに 12 ずつ増える
  u8 unk_cb8;                     // 0xCB8
  u8 unk_cb9;                     // 0xCB9, 4方向の向き
  u8 segmentsLeft;                // 0xCBA, 壊れていない節の数, 初期値 6
  u8 hpPerSegment;                // 0xCBB, hp / (segmentCount + 1)
  s32 unk_cbc;                    // 0xCBC, 初期値 0x7FFFFFFF
  u8 unk_cc0[4];                  // 0xCC0
  NavAgent navAgent;              // 0xCC4, Enemy.navAgent が指す
  Vec3 pathNodePos;               // 0xCE8, Enemy.pathNodePos が指す
  Vec3 turnTilePos;               // 0xCF0, turnTileIdx のタイルの中心
  Vec3 homePos;                   // 0xCF8, 生成時の mover.pos
} Salamander;
static_assert(sizeof(Salamander) == 3328);

// a - b を -128..128 に丸めた角度の差
static inline s32 Salamander_AngleDiff(s32 a, s32 b) {
  s32 d = a - b;

  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  return d;
}

// cur のタイルから dir の向きの隣 next へ進めるなら next を, 進めないなら -1 を返す, 階段は上り下りの向きと段差が合うときだけ通す
static inline s32 Salamander_CheckStep(s32 cur, s32 next, s32 dir) {
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
static inline s32 Salamander_NeighborTile(s32 tile, s32 dir) {
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

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

// anim 番の variant を流す, MainSprite では anim + variant 番を flags の向きと逆再生で流し, 同じものが流れていれば何もしない
static inline void Salamander_PlayDirAnim(Salamander* p, u32 anim, u32 variant, u32 flags) {
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

static inline bool8 Salamander_TestSegmentFlags(SalamanderSegment* seg, SalamanderSegmentFlags bit) {
  if (seg->flags & bit) return TRUE;
  return FALSE;
}

static inline bool8 Salamander_TestFlags(Salamander* p, SalamanderFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

static inline void Salamander_SetFlags(Salamander* p, SalamanderFlags bit) { p->flags |= bit; }
static inline void Salamander_ClearFlags(Salamander* p, SalamanderFlags bit) { p->flags &= ~bit; }

const STRING_DATA char s_eneinline_08252224[] = "../system/eneinline.h";
const STRING_DATA char s_eneinline_0825223c[] = "../system/eneinline.h";

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
  Enemy_ClearPendingState(p, s_eneinline_0825223c, 2434);
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

void Entity081f9cb8_Spawn(Vec3* pos, s32 delay, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes);
void Salamander_GetAnimVariant(u16 angle, u32* variant, u32* xflip);
void Salamander_AnimateSegments(Salamander* p);
void Salamander_SetSegmentPos(Salamander* p, s32 idx, Vec3* pos);
void Salamander_StateRespawn(Salamander* p);
s32 Enemy_UpdateMovement(Enemy* p);
s32 FUN_080e1f48(Enemy* p);
s32 Enemy_UpdateHitboxes(Enemy* p);
bool32 Enemy_ProcessRequests(Enemy* p);
bool32 Enemy_ShakeSprite(Enemy* p);
void FUN_080f06ac(Enemy* p);
void Salamander_PickNextTile(Salamander* p);
void Salamander_StateWakeUp(Salamander* p, s32 timer);
void Salamander_ScatterSpark(Vec3* pos);
void Salamander_SpawnFireDebris(Vec3* pos);
void Salamander_StateDying(Salamander* p);
void Salamander_ResetRecentTiles(Salamander* p);
void Salamander_StateLand(Salamander* p, s32 timer);
void Salamander_AimJumpAtPlayer(Salamander* p);
void Salamander_OnReset(Salamander* p);
void FUN_081a7838(Salamander* p);
bool8 Salamander_IsRecentTile(Salamander* p, u32 tileIdx);
void Salamander_AddRecentTile(Salamander* p, u32 tileIdx);
void Salamander_SetSegmentVelocity(Salamander* p, Vec3* velocity, s32 idx);
void Salamander_SpawnSpark(Vec3* pos);
void Salamander_ExplodeAtFeet(Salamander* p);
void Salamander_StatePounce(Salamander* p);
void WormTail_RequestDive(void);
void Salamander_ResetWave(Salamander* p);
void Salamander_AdvanceSwayIfMoving(Salamander* p, s32 speed);
void Salamander_UpdateWave(Salamander* p, s32 amplitude, s32 speed);
s32 SpawnAttackBox(Vec3* pos, u32 kind, u32 variant, s32 power, s32 knockback, s32 iframes, s32 ignoreMask);
void Salamander_SpawnFireDebris(Vec3* pos);
void Salamander_DestroyAllSegments(Salamander* p);
void Salamander_SetAllSegmentsPos(Salamander* p, Vec3* pos);
void Salamander_SpawnExplosion(Vec3* pos);
void Salamander_SpawnFireDebris2(Vec3* pos);
s32 Salamander_UpdateSegmentsBuried(Salamander* p);
void Salamander_StateHover(Salamander* p, s32 timer);
void Salamander_WobbleSegments(Salamander* p, s32 amplitude, s32 step, s32 horizontal);
void Salamander_PullSegments(Salamander* p, s32 followDiv, s32 linkDiv, s32 followDistSq);
bool8 Salamander_DestroyTailSegment(Salamander* p);
void Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, s32 kind);
struct Explosion* Explosion_CreateWithAttrs(Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 plttOffset, s32 delay);
void Salamander_SubEmerge(Salamander*);
void Salamander_SubTurn(Salamander*);
void Salamander_SubCrawl(Salamander*);
void Salamander_SubHop(Salamander*);
void FUN_081a8748(Salamander*);
void Salamander_SubLeapOut(Salamander*);
void Salamander_SubBurrow(Salamander*);
void FUN_081a94bc(Salamander*);
void Salamander_SubDive(Salamander*);
void Salamander_SubDyingBlast(Salamander*);

void (*const sSalamanderHandlerTable2[11])(Salamander*) = {
    Salamander_SubEmerge,
    Salamander_SubTurn,
    Salamander_SubCrawl,
    (void*)FUN_080f2364,
    Salamander_SubHop,
    FUN_081a8748,
    Salamander_SubLeapOut,
    Salamander_SubBurrow,
    FUN_081a94bc,
    Salamander_SubDive,
    Salamander_SubDyingBlast,
};  // 0x085ADEA8

void FUN_081acd90(Salamander*);

void (*const sSalamanderHandlerTable4[1])(Salamander*) = {
    FUN_081acd90,
};  // 0x085ADED4

void Salamander_OnDamageMsg(Salamander*, u16*);

// メッセージ表
void (*const sSalamanderMsgHandlers[7])(Salamander*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    Salamander_OnDamageMsg,
};  // 0x085ADED8

void Salamander_OnHit(Hitbox* a, Hitbox* b, Salamander* p) {
  if (!Enemy_IsDead(&p->e)) {
    if (b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 食らい判定, 死に際でなければ敵共通の処理を通して SALAFLAG_UNK_6 を立てる
// 786/798命令, 敵共通の Enemy_HandleHurt に死亡中の判定と SALAFLAG_UNK_6 を足しただけ, Golem_OnHurt と同じ共通 inline の壁 (a / b のレジスタとノックバック判定の配置), 1回目の下書きで切り上げ
NON_MATCH void Salamander_OnHurt(Hitbox* a, Hitbox* b, Salamander* p) {
#ifdef NONMATCHING_C
  if (!Enemy_IsDead(&p->e) && !Salamander_TestFlags((p->e).owner, SALAFLAG_DYING)) {
    Enemy_HandleHurt(a, b, &p->e);
    SET_FLAGS(((Salamander*)(p->e).owner)->flags, SALAFLAG_UNK_6);
  }
#else
  INCFUNC("asm/func/Salamander_OnHurt.inc");
#endif
}

void Salamander_StateMove(Salamander* p) {
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Salamander_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Salamander_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Salamander_AnimateSegments((p->e).owner);
  } else {
    Salamander_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Salamander_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Salamander_AnimateSegments((p->e).owner);
  }
}

void FUN_081a701c(Salamander* p) {
  u32 variant, xflip;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Salamander_GetAnimVariant((p->e).mover.angle, &variant, &xflip);
    Salamander_AnimateSegments((p->e).owner);
  } else {
    Salamander_GetAnimVariant((p->e).mover.angle, &variant, &xflip);
    Salamander_AnimateSegments((p->e).owner);
  }
}

void Salamander_StateWait(Salamander* p) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Salamander_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Salamander_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
}

void Salamander_StateTurn(Salamander* p) {}

void Salamander_StateNap(Salamander* p, s32 timer) {
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
    Enemy_EnterState(&p->e, Salamander_StateWakeUp, ES_WAKE_UP);
  }
}

void Salamander_StateWakeUp(Salamander* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
  }
  if (timer == 40) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart && timer > 120) {
    (p->e).subStateDone = 1;
  }
}

// 姿と影を隠して 27 フレーム待ち, Salamander_StateRespawn へ移る
void Salamander_StateRespawnWait(Salamander* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    ParticleShadow_Hide(&(p->e).shadow);
  } else if (timer > 26) {
    Enemy_PlayAnim(&p->e, 9);
    Enemy_EnterState(&p->e, Salamander_StateRespawn, ES_UNK_13);
  } else {
    (p->e).animForceRestart = 0;
  }
}

// 姿と影を戻して hp 1 と無敵 60 フレームで現れ, アニメが終わったら生成時の状態に戻す
void Salamander_StateRespawn(Salamander* p) {
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
    Salamander_OnReset(p);
    Enemy_RestoreInitialState(&p->e);
  }
}

// 向きと逆へ下がりながら浮き上がり, 追う節の前の2つを頭の後ろに並べる, 残りの節が多いほど高く上がってから止まる
void Salamander_StateRise(Salamander* p) {
  Salamander* q = (p->e).owner;
  s32 limit;
  s32 n;
  s32 i;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    u32 variant, flags;

    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Salamander_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    SET_FLAGS(q->flags, SALAFLAG_UNK_1);
  }
  Vec3_Clear(&(p->e).jumpVel);
  limit = q->segmentsLeft > 3 ? 300 : 200;
  if ((p->e).heightAboveFloor >= limit) {
    Enemy_EnterState(&p->e, FUN_081a7838, ES_UNK_38);
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
    Salamander_PullSegments(p, 14, 12, 12000);
    n = 0;
    for (i = 0; i < q->segmentCount; i++) {
      if (Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_FOLLOW) && !Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED | SALSEGFLAG_UNK_2)) {
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

void FUN_081a7838(Salamander* p) {}

// 向きと逆へ下がりながら浮き上がり, 床から 256 を超えたら Salamander_StateHover の状態へ移る
void Salamander_StateLeapBack(Salamander* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  Vec3_Clear(&(p->e).jumpVel);
  if ((p->e).heightAboveFloor > 255) {
    Enemy_EnterState(&p->e, Salamander_StateHover, ES_UNK_34);
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
    Salamander_PullSegments(p, 10, 12, 0x1000);
    Salamander_WobbleSegments(p, 20, 24, 0);
  }
}

// 宙で前後に揺れながら追う節の前の2つを頭の後ろに並べ, 60 フレーム後に Salamander_StatePounce へ移る
// 315/315命令, 残差は speed を作る ands の演算子の並び (原典は 0x7F を持つレジスタに結果を書く) だけ, 試済: s8 フィールド, bit7 判定, 位相をローカルに受ける (u32/u8), speed に受けて上書き, 定数を左に置く
NON_MATCH void Salamander_StateHover(Salamander* p, s32 timer) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
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
    if (Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_FOLLOW) && !Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED | SALSEGFLAG_UNK_2)) {
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
  Salamander_PullSegments(p, 64, 12, 0xFFFF);
  if (timer > 60) {
    Enemy_EnterState(&p->e, Salamander_StatePounce, ES_UNK_35);
  }
#else
  INCFUNC("asm/func/Salamander_StateHover.inc");
#endif
}

// プレイヤーへ向けて跳びかかり, 着地したら Salamander_StateLand の状態へ移る
void Salamander_StatePounce(Salamander* p) {
  Salamander* q = (p->e).owner;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Salamander_AimJumpAtPlayer(p);
    (p->e).mover.angle = ArcTan2_8((p->e).jumpVel.x, (p->e).jumpVel.z);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    CLEAR_FLAGS(q->flags, SALAFLAG_UNK_1);
  }
  Salamander_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Salamander_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Salamander_WobbleSegments(p, 18, 6, 0);
  Salamander_AnimateSegments((p->e).owner);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Salamander_StateLand, ES_UNK_36);
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
}

// 着地してから節を引き寄せつつ 40 フレーム待ち, 終わったら副状態を進める
void Salamander_StateLand(Salamander* p, s32 timer) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Salamander_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Salamander_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Salamander_AnimateSegments((p->e).owner);
  Salamander_PullSegments(p, 20, 12, 0x4000);
  if (timer > 40) {
    Salamander_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Salamander_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Salamander_AnimateSegments((p->e).owner);
    (p->e).subStateDone = 1;
  }
}

void Salamander_ClearStateBegun(Salamander* p) {
  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
}

// 爆発して火の粉と破片を撒き, 節を全部壊して撃破スクリプトと図鑑登録をしてから止まる
// Curoro_StateDying と同じ後半, 原典は状態フィールドのアドレスをループの前にスタックへ作り置く (フレーム 0x5C, こちらは 0x4C), 敵共通の inline の壁, 2回目で切り上げ
NON_MATCH void Salamander_StateDying(Salamander* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 idx;

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
    PlaySound_082406e0(SONG_987);
  }
  SpawnAttackBox(&(p->e).mover.pos, 2, 0, 128, 64, 40, 16);
  for (i = 0; i < 12; i++) {
    Salamander_SpawnFireDebris(&(p->e).mover.pos);
  }
  Salamander_DestroyAllSegments(p);
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
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  Enemy_ResetState(&p->e, 1, 0, 2);
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_12);
  (p->e).subStateDone = 1;
#else
  INCFUNC("asm/func/Salamander_StateDying.inc");
#endif
}

// 行き先へ這い進み, 着いたらプレイヤーの位置を次の行き先にする, 向きが 32 より離れていれば向き直りの副状態へ移る
void Salamander_SubCrawl(Salamander* p) {
  Salamander* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->waveDir = 1;
    q->waveOffset = 0;
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Salamander_ResetWave(p);
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;
    s32 diff;

    (p->e).navAgent->dest = gPlayerPtr[0]->mover.pos;
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    diff = (p->e).unk_1dc - (p->e).mover.angle;
    if (diff > 128) {
      diff -= 256;
    } else if (diff < -128) {
      diff += 256;
    }
    if (abs(diff) > 32) {
      Enemy_ResetState(&p->e, 0, 0, 1);
      return;
    }
  }
  Salamander_AdvanceSwayIfMoving(p, speed);
  Salamander_PullSegments(p, 12, 18, 0x4000);
  Salamander_UpdateSegmentsBuried(q);
  Salamander_UpdateWave(p, 120, 10);
  (p->e).subStateTimer++;
}

// プレイヤーの足元の地中に潜って爆発を3つ起こし, 120 フレーム後に渦を巻きながら上昇して出てくる
void Salamander_SubEmerge(Salamander* p) {
  Salamander* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3 pos;

    (p->e).mover.pos = gPlayerPtr[0]->mover.pos;
    (p->e).mover.pos.y = (p->e).floorY - 512;
    (p->e).s->aux.spr.pos = (p->e).mover.pos;
    Salamander_SetAllSegmentsPos(q, &(p->e).mover.pos);
    (p->e).mover.pos.y = (p->e).floorY;
    (p->e).mover.angle = 0x40;
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Vec3_Clear(&(p->e).jumpVel);
    q->riseSpeed = 1;
    pos = (p->e).mover.pos;
    Salamander_SpawnExplosion(&pos);
    pos.x -= 100;
    pos.z += 128;
    Salamander_SpawnExplosion(&pos);
    pos = (p->e).mover.pos;
    pos.x += 100;
    pos.z += 128;
    Salamander_SpawnExplosion(&pos);
  }
  if (++(p->e).subStateTimer > 119) {
    AuxShadow_Show(&(p->e).auxShadow);
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
    if ((p->e).heightAboveFloor > 512) {
      Enemy_ResetState(&p->e, 0, 0, 10);
    } else {
      s32 speed = 30;
      s32 followDistSq = 1240;
      s32 dx, dz;

      if (Mod((p->e).subStateTimer, 14) == 0) {
        q->riseSpeed += 12;
        Salamander_SpawnFireDebris2(&(p->e).mover.pos);
      }
      (p->e).heightAboveFloor += q->riseSpeed;
      dx = POLAR_X(speed, (p->e).mover.angle);
      dz = POLAR_Z(speed, (p->e).mover.angle);
      (p->e).mover.angle += 9;
      (p->e).mover.delta.x += dx;
      (p->e).mover.delta.z += dz;
      Salamander_PullSegments(p, 8, 4, followDistSq);
      Salamander_UpdateSegmentsBuried(q);
    }
  }
}

void FUN_081a8748(Salamander* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Salamander_StateRise, ES_UNK_37);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  if ((p->e).subStateDone) {
    Salamander_PickNextTile(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  } else {
    (p->e).subStateTimer++;
  }
}

// 今のタイルの中に留まりながら unk_1dc の向きへ向き直り, 向き終えたら這い進む副状態へ戻る
void Salamander_SubTurn(Salamander* p) {
  Salamander* q = (p->e).owner;
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
  diff = Salamander_AngleDiff((p->e).unk_1dc, (p->e).mover.angle);
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
  Salamander_PullSegments(p, 12, 12, 0xA410);
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

// 向いている方へ速さ 4 で跳ね, 着地したら次の行き先を決めて移動に戻る
void Salamander_SubHop(Salamander* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).mover.angle, 4);
    (p->e).jumpVel.y = 0;
    (p->e).unk_1bc = 2;
  }
  Salamander_PullSegments(p, 6, 12, 0x1000);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Salamander_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
}

// 地中からプレイヤーの方へ跳び出し, 節を順に跳ね上げながら火の粉を撒き, 着地したら次の行き先を決める
// 371/366命令, 残差は火の粉を出すループだけ (原典は先頭判定を複写しない形で i*208 を毎回掛ける), 試済: continue, goto ループ (他の割当が崩れる)
NON_MATCH void Salamander_SubLeapOut(Salamander* p) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).mover.pos.y = (p->e).floorY - 512;
    (p->e).s->aux.spr.pos = (p->e).mover.pos;
    Salamander_SetAllSegmentsPos(q, &(p->e).mover.pos);
    (p->e).mover.pos.y = (p->e).floorY;
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).playerAngle, 24);
    (p->e).mover.angle = (p->e).playerAngle;
    (p->e).jumpVel.y = 40;
    (p->e).unk_1bc = 0;
    Salamander_SetFlags(q, SALAFLAG_UNK_2);
    PlaySound_082406e0(SONG_413);
    AuxShadow_Show(&(p->e).auxShadow);
    if (Salamander_TestFlags(q, SALAFLAG_UNK_9)) {
      Salamander_ClearFlags(q, SALAFLAG_UNK_9);
    } else {
      Salamander_ExplodeAtFeet(p);
    }
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
  }
  if ((p->e).subStateTimer < 10) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 16;
    for (i = 0; i < 3; i++) {
      Salamander_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 20) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 24;
    for (i = 0; i < 6; i++) {
      Salamander_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 60) {
    Vec3 v;

    Vec3_Clear(&v);
    for (i = 0; i < 6; i++) {
      if (i < 3) {
        v.y = 44;
        Salamander_SetSegmentVelocity(p, &v, i);
      } else {
        v.y = 62;
        Salamander_SetSegmentVelocity(p, &v, i);
      }
    }
  }
  if (Mod((p->e).subStateTimer, 12) == 0) {
    Salamander_SpawnFireDebris2(&(p->e).mover.pos);
  }
  if (Mod((p->e).subStateTimer, 16) == 0) {
    for (i = 0; i < q->segmentCount; i++) {
      if (!(i & 1)) {
        Salamander_SpawnSpark(&q->segments[i].sprite.pos);
      }
    }
  }
  Salamander_PullSegments(p, 4, 4, 0x1000);
  Salamander_UpdateSegmentsBuried(q);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Vec3 d;

    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    Salamander_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    Enemy_ResetState(&p->e, 0, 0, 7);
    PlaySound_082406e0(SONG_325);
    AuxShadow_Hide(&(p->e).auxShadow);
    Salamander_ExplodeAtFeet(p);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Salamander_SubLeapOut.inc");
#endif
}

// 着地したら姿を隠して地中へ潜り, 節が全部潜り終えたら副状態 (0, 0, 6) へ移る
void Salamander_SubDive(Salamander* p) {
  Salamander* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Salamander_ClearFlags(q, SALAFLAG_UNK_2);
    (p->e).jumpVel.y = 32;
    (p->e).unk_1bc = 0;
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Salamander_ClearFlags(q, SALAFLAG_UNK_3);
  }
  if ((p->e).subStateTimer > 80) {
    Salamander_PullSegments(p, 4, 4, 0);
  } else {
    Salamander_PullSegments(p, 12, 4, 0x1000);
  }
  for (i = 0; i < q->segmentCount; i++) {
    Vec3 d;

    Vec3_Diff(&d, &q->segments[i].sprite.pos, &(p->e).mover.pos);
    if (d.x * d.x + d.z * d.z > 32000) {
      q->segments[i].sprite.pos.y = (p->e).floorY;
    }
  }
  Salamander_UpdateSegmentsBuried(q);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    Salamander_SetFlags(q, SALAFLAG_UNK_3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    PlaySound_082406e0(SONG_988);
  }
  if (Salamander_TestFlags(q, SALAFLAG_UNK_3)) {
    (p->e).mover.pos.y -= 16;
    if (Salamander_UpdateSegmentsBuried(q) < 0) {
      Enemy_ResetState(&p->e, 0, 0, 6);
      (p->e).mover.pos.y = (p->e).floorY;
      CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
      (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
      q->diveCount++;
      return;
    }
  }
  (p->e).subStateTimer++;
}

// 地中を深く沈みながら進み, 節が全部潜ったら 60 フレーム後に出てくる副状態へ, 5 回潜ったら最初の副状態へ戻る
void Salamander_SubBurrow(Salamander* p) {
  Salamander* q = (p->e).owner;
  Vec3 d;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Salamander_ClearFlags(q, SALAFLAG_UNK_2);
    if (Salamander_TestFlags(q, SALAFLAG_DYING)) {
      WormTail_RequestDive();
      PlaySound_082406e0(SONG_988);
    }
  }
  if ((p->e).mover.pos.y > -2048) {
    Vec3 v;

    Vec3_SetPolar(&v, (p->e).mover.angle, 8);
    (p->e).mover.pos.y -= 100;
    if ((p->e).s->aux.spr.flags == 0 && (p->e).mover.pos.y < (p->e).floorY) {
      (p->e).s->aux.spr.flags = SPRFLAG_HIDDEN;
      PlaySound_082406e0(SONG_479);
    }
  } else {
    (p->e).mover.pos.y = -2048;
  }
  if ((p->e).subStateTimer > 30) {
    Salamander_PullSegments(p, 12, 4, 0);
  } else {
    Salamander_PullSegments(p, 12, 6, 0xA410);
  }
  for (i = 0; i < q->segmentCount; i++) {
    Vec3_Delta(&d, &(p->e).mover.pos, &q->segments[i].sprite.pos);
    if (d.x * d.x + d.z * d.z > 32000) {
      if (q->segments[i].sprite.pos.y < (p->e).floorY) {
        q->segments[i].sprite.pos.y = (p->e).floorY;
      }
    }
  }
  if (Salamander_UpdateSegmentsBuried(q) < 0) {
    if (q->diveCount > 4) {
      Enemy_ResetState(&p->e, 0, 0, 0);
      return;
    }
    if ((p->e).subStateTimer > 60) {
      Enemy_ResetState(&p->e, 0, 0, 6);
      (p->e).mover.pos.y = (p->e).floorY;
      CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
      (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
      q->diveCount++;
      return;
    }
  }
  (p->e).subStateTimer++;
}

void FUN_081a94bc(Salamander* p) {
  Salamander* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    CLEAR_FLAGS(q->flags, SALAFLAG_UNK_2);
    (p->e).jumpVel.y = -64;
    (p->e).unk_1bc = 0;
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
  }
  Salamander_PullSegments(p, 6, 12, 0xFFFF);
  Salamander_UpdateSegmentsBuried(q);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    if (Salamander_TestFlags(q, SALAFLAG_UNK_8)) {
      PlaySound_082406e0(SONG_988);
      Salamander_ClearFlags(q, SALAFLAG_UNK_8);
    } else {
      PlaySound_082406e0(SONG_325);
    }
    Enemy_ResetState(&p->e, 0, 0, 7);
  }
  (p->e).subStateTimer++;
}

// 決まったフレームごとに尾から節を1つずつ爆発させ, 120 フレーム過ぎたら Salamander_StateDying へ移る
void Salamander_SubDyingBlast(Salamander* p) {
  Salamander* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS(q->flags, SALAFLAG_DYING);
    return;
  }
  switch ((p->e).subStateTimer) {
    case 10:
    case 30:
    case 50:
    case 70:
    case 80:
    case 90:
    case 95: {
      Salamander_DestroyTailSegment(p);
      break;
    }
  }
  if ((p->e).subStateTimer > 100 && Mod((p->e).subStateTimer, 4) == 0) {
    Salamander_SpawnFireDebris(&(p->e).mover.pos);
  }
  if ((p->e).subStateTimer > 120) {
    Enemy_EnterState(&p->e, Salamander_StateDying, ES_DYING);
    Enemy_ResetState(&p->e, 3, 0, 0);
  } else {
    (p->e).subStateTimer++;
  }
}

void Salamander_SetHandlerTable2(Salamander* p) { (p->e).handlerTables[2] = (void*)sSalamanderHandlerTable2; }

// 届いたダメージ量を damageAccum に足す
void Salamander_OnDamageMsg(Salamander* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && !Salamander_TestFlags((p->e).owner, SALAFLAG_DYING)) {
    ((Salamander*)(p->e).owner)->damageAccum += *msg;
  }
}

void Salamander_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *variant = 8 - dir;
    *xflip = 1;
  } else {
    *variant = dir;
    *xflip = 0;
  }
}

// 4 方向の隣のタイルから進めるものを選び, 最近通っていないものを行き先にする, 無ければ乱数で選ぶか真っすぐ進むか unk_cb9 の逆へ向かう
// 1099/1196命令の下書き, 段差の判定を Salamander_CheckStep に, 隣のタイルを Salamander_NeighborTile にまとめた (原典は判定の塊を2か所に展開し, 4 方向の数えを sp に置く), 1回目の下書きで切り上げ
NON_MATCH void Salamander_PickNextTile(Salamander* p) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
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
  if (q->unk_cb8 == 2) {
    dir = (facing + 1) & 3;
  } else if (q->unk_cb8 == 3) {
    dir = (facing + Random()) & 3;
  } else {
    dir = facing;
  }
  if (q->unk_cb8 > 16) {
    q->unk_cb9 = (((p->e).playerAngle + 0x20) & 0xFF) >> 6;
    q->unk_cb8 = 0;
  }
  for (i = 0; i < 4; i++) {
    if (abs(dir - q->unk_cb9) != 2 && abs(dir - facing) != 2) {
      tile = Salamander_CheckStep((p->e).tileIdx, Salamander_NeighborTile((p->e).tileIdx, dir), dir);
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
      if (!Salamander_IsRecentTile(p, cands[i])) {
        TilePosAtIndex(&agent->dest, cands[i]);
        Salamander_AddRecentTile(p, cands[i]);
        q->unk_cb8++;
        q->unk_cb4 = 40;
        return;
      }
    }
    i = Mod(Random(), n);
    TilePosAtIndex(&agent->dest, cands[i]);
    Salamander_AddRecentTile(p, cands[i]);
    q->unk_cb8++;
    q->unk_cb4 = 40;
  } else if (straight != -1 && !Salamander_IsRecentTile(p, straight)) {
    TilePosAtIndex(&agent->dest, straight);
    Salamander_AddRecentTile(p, straight);
    q->unk_cb8 += 8;
    q->unk_cb4 = 40;
  } else {
    dir = (q->unk_cb9 + 2) & 3;
    tile = Salamander_CheckStep((p->e).tileIdx, Salamander_NeighborTile((p->e).tileIdx, dir), dir);
    if (tile >= 0) {
      TilePosAtIndex(&agent->dest, tile);
      Salamander_AddRecentTile(p, tile);
      q->unk_cb8 += 2;
      q->unk_cb4 = 40;
    } else {
      q->unk_cb9 = (q->unk_cb9 + 1) & 3;
    }
  }
#else
  INCFUNC("asm/func/Salamander_PickNextTile.inc");
#endif
}

// 12 フレームごとに尾へ中の節, 中へ頭の節, 頭へ pos の位置を送る
void Salamander_ShiftKeySegments(Salamander* p, Vec3* pos) {
  Salamander* q = (p->e).owner;

  if (q->shiftTimer != 0) {
    q->shiftTimer--;
  } else {
    q->shiftTimer = 12;
    Salamander_SetSegmentPos(q, q->segmentCount - 1, &q->segments[q->segmentCount >> 1].sprite.pos);
    Salamander_SetSegmentPos(q, q->segmentCount >> 1, &q->segments[0].sprite.pos);
    Salamander_SetSegmentPos(q, 0, pos);
  }
}

// 節を6つ作り, スプライトとアニメを載せる, 尾と後ろの2節は anim 15, それより前は向きに合わせた anim 14 を流す
void Salamander_InitSegments(Salamander* p, u32 sprID, u32 animFID, u32 angle) {
  Salamander* q = (p->e).owner;
  s32 cmdIdx;
  s32 i;

  q->segmentCount = 6;
  q->segmentsLeft = q->segmentCount;
  q->unk_cbc = 0x7FFFFFFF;
  q->hpPerSegment = Div((p->e).hp, q->segmentCount + 1);
  cmdIdx = 0;
  for (i = 0; i < q->segmentCount; i++) {
    SalamanderSegment* seg = &q->segments[i];
    u32 variant, xflip;

    Video_GetAuxSprite(&seg->gfx, sprID);
    AuxSprite_Add(&seg->sprite, &seg->gfx, 0);
    Video_SetAuxSpritePltt(&seg->gfx, 421);
    seg->angle = angle;
    seg->animFile = GetFile(DIR_ANIMATION, animFID);
    Salamander_GetAnimVariant(seg->angle, &variant, &xflip);
    seg->owner = q;
    if (i == q->segmentCount - 1) {
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 15, 0, 0);
      SET_FLAGS(seg->flags, SALSEGFLAG_FOLLOW | SALSEGFLAG_UNK_2 | SALSEGFLAG_UNK_3);
    } else if (i < q->segmentCount - 2) {
      seg->wobbleAngle = i * 24;
      SET_FLAGS(seg->flags, SALSEGFLAG_FOLLOW | SALSEGFLAG_UNK_4);
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 14, variant, xflip);
    } else {
      SET_FLAGS(seg->flags, SALSEGFLAG_FOLLOW | SALSEGFLAG_UNK_3);
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 15, 0, 0);
    }
    seg->anim.cmdIdx = cmdIdx;
    if (++cmdIdx > 8) {
      cmdIdx = 0;
    }
  }
}

// 壊れていない節を床より下なら隠し上なら出す, 全部上なら 1, 全部下なら -1, 混ざっていれば 0 を返す
// 178/165命令, Salamander_HideBuriedSprites と同じ形の壁 (原典は i を sp に置き, 座標と flags を誘導変数で持つ), 1回目の下書きで切り上げ
NON_MATCH s32 Salamander_UpdateSegmentsBuried(Salamander* p) {
#ifdef NONMATCHING_C
  s32 n = 0;
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Salamander_TestSegmentFlags(&p->segments[i], SALSEGFLAG_DESTROYED)) {
      Vec3* pos = &p->segments[i].sprite.pos;
      s32 d;

      if (pos->y < TileHeightAt(pos)) {
        if (!(p->segments[i].sprite.flags & SPRFLAG_HIDDEN)) {
          p->segments[i].sprite.flags |= SPRFLAG_HIDDEN;
        }
        d = -1;
      } else {
        if (p->segments[i].sprite.flags & SPRFLAG_HIDDEN) {
          p->segments[i].sprite.flags &= ~SPRFLAG_HIDDEN;
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
  INCFUNC("asm/func/Salamander_UpdateSegmentsBuried.inc");
#endif
}

void Salamander_HideLiveSegments(Salamander* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Salamander_TestSegmentFlags(&p->segments[i], SALSEGFLAG_DESTROYED)) {
      SET_FLAGS(p->segments[i].sprite.flags, SPRFLAG_HIDDEN);
    }
  }
}

// 節ごとに向きに合わせたアニメを選び直し, animSpeedDiv に合わせた速さで1コマ送る
void Salamander_AnimateSegments(Salamander* p) {
  s32 div = (p->e).animSpeedDiv != 0 ? (p->e).animSpeedDiv : 1;
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    u32 variant, flags;

    Salamander_GetAnimVariant(p->segments[i].angle, &variant, &flags);
    if (Salamander_TestSegmentFlags(&p->segments[i], SALSEGFLAG_UNK_4)) {
      AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, 14, variant, flags);
    } else {
      AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[16].anim, 0, 0);
    }
    AuxAnim_SetAnimSpeed(&p->segments[i].anim, Div(64, div));
    AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
  }
}

// 壊れていない節を timer が 10 から点滅させ 30 で消す
void Salamander_BlinkSegments(Salamander* p, s32 timer) {
  Salamander* q = (p->e).owner;
  SalamanderSegment* segs = q->segments;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Salamander_TestSegmentFlags(&segs[i], SALSEGFLAG_DESTROYED)) {
      Sprite_UpdateVanishBlink(&segs[i].sprite.flags, timer, 10, 30);
    }
  }
}

void Salamander_HideDestroyedSegments(Salamander* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (Salamander_TestSegmentFlags(&p->segments[i], SALSEGFLAG_DESTROYED)) {
      p->segments[i].sprite.flags = SPRFLAG_HIDDEN;
    }
  }
}

void Salamander_RemoveSegmentSprites(Salamander* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    AuxSprite_Remove(&p->segments[i].sprite);
  }
}

void Salamander_SetSegmentPos(Salamander* p, s32 idx, Vec3* pos) { p->segments[idx].sprite.pos = *pos; }

// 壊れていない節を1つ前の節 (先頭は頭) の方へ向ける
void Salamander_FaceSegmentsForward(Salamander* p) {
  Salamander* q = (p->e).owner;
  Vec3 diff;
  Vec3 prev = (p->e).mover.pos;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED)) {
      Vec3_Diff(&diff, &prev, &q->segments[i].sprite.pos);
      q->segments[i].angle = ArcTan2_8(diff.x, diff.z);
      prev = q->segments[i].sprite.pos;
    }
  }
}

void Salamander_ResetWave(Salamander* p) {
  Salamander* q = (p->e).owner;

  q->waveOffset = 0;
  q->waveDir = 1;
}

// waveOffset を -amplitude..amplitude の間で speed ずつ往復させる
void Salamander_UpdateWave(Salamander* p, s32 amplitude, s32 speed) {
  Salamander* q = (p->e).owner;

  if (q->waveOffset >= amplitude) {
    q->waveOffset = amplitude;
    q->waveDir = -1;
  } else if (q->waveOffset <= -amplitude) {
    q->waveOffset = -amplitude;
    q->waveDir = 1;
  }
  q->waveOffset += q->waveDir * speed;
}

void Salamander_InitFollowInterval(Salamander* p) { ((Salamander*)(p->e).owner)->followInterval = 1; }

// followInterval フレームごとに, 前の節を追う節の targetPos を1つ前の節の位置 (先頭は頭) に送る
void Salamander_FollowSegments(Salamander* p) {
  Salamander* q = (p->e).owner;

  if (Mod((p->e).unk_1ca, q->followInterval) == 0) {
    Vec3 prev = (p->e).s->aux.spr.pos;
    s32 i;

    for (i = 0; i < q->segmentCount; i++) {
      if (Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_FOLLOW) && !Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED)) {
        Vec3 cur = q->segments[i].sprite.pos;

        q->segments[i].targetPos = prev;
        prev = cur;
      }
    }
  }
}

// 前の節を追っている節にだけ速度を与える
void Salamander_SetSegmentVelocity(Salamander* p, Vec3* velocity, s32 idx) {
  Salamander* q = (p->e).owner;

  if (Salamander_TestSegmentFlags(&q->segments[idx], SALSEGFLAG_FOLLOW) && !Salamander_TestSegmentFlags(&q->segments[idx], SALSEGFLAG_DESTROYED)) {
    q->segments[idx].velocity = *velocity;
  }
}

// 前の節を追っている節の velocity を wobbleAngle の sin で揺らす, horizontal が 0 なら縦, それ以外は水平に揺らす
void Salamander_WobbleSegments(Salamander* p, s32 amplitude, s32 step, s32 horizontal) {
  Salamander* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_FOLLOW) && !Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED)) {
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
// 207/209命令, Ghost_StepCurve と同じ Hermite 曲線の壁 (原典は 0 との掛け算が畳まれずに残る), 1回目の下書きで切り上げ
NON_MATCH void Salamander_PlaceSegmentsOnCurve(Salamander* p, Vec3* startPos, Vec3* endPos, s32 first, s32 last) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
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
    Vec3_Clear(&v);
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
    Salamander_SetSegmentPos(q, i, &pos);
  }
#else
  INCFUNC("asm/func/Salamander_PlaceSegmentsOnCurve.inc");
#endif
}

// 節を targetPos へ差の 1/followDiv ずつ寄せ, 1つ前の節 (先頭は頭) から 96 より離れた節は 1/linkDiv ずつ引き寄せて向きを揃える
void Salamander_PullSegments(Salamander* p, s32 followDiv, s32 linkDiv, s32 followDistSq) {
  Salamander* q = (p->e).owner;
  Vec3 d;
  Vec3 prev;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    Vec3_Diff(&d, &q->segments[i].targetPos, &q->segments[i].sprite.pos);
    if (d.x * d.x + d.y * d.y + d.z * d.z > followDistSq) {
      followDiv = followDiv >= 1 ? followDiv : 1;
      q->segments[i].sprite.pos.x += Div(d.x, followDiv);
      q->segments[i].sprite.pos.y += Div(d.y, followDiv);
      q->segments[i].sprite.pos.z += Div(d.z, followDiv);
    }
  }
  prev = (p->e).s->aux.spr.pos;
  for (i = 0; i < q->segmentCount; i++) {
    Vec3_Diff(&d, &prev, &q->segments[i].sprite.pos);
    if (d.x * d.x + d.y * d.y + d.z * d.z > 96 * 96) {
      q->segments[i].sprite.pos.x += Div(d.x, linkDiv);
      q->segments[i].sprite.pos.y += Div(d.y, linkDiv);
      q->segments[i].sprite.pos.z += Div(d.z, linkDiv);
    }
    prev = q->segments[i].sprite.pos;
  }
  Salamander_FaceSegmentsForward(p);
}

void Salamander_SetAllSegmentsPos(Salamander* p, Vec3* pos) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    p->segments[i].sprite.pos = *pos;
    p->segments[i].targetPos = *pos;
  }
}

void Salamander_InitHitboxes(Salamander* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 24, 128, 24);
  VEC3_SET(hurtOffset, 0, 0, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Salamander_OnHurt, p);
  VEC3_SET(hitSize, 32, 256, 32);
  VEC3_SET(hitOffset, 0, 0, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Salamander_OnHit, 0, p);
  Hitbox_SetFlags(&(p->e).hitbox, HBF_ONCE);
}

// 復帰時に作業値を消して homePos へ戻し, 節もそこへ集めて移動から始め直す
void Salamander_OnReset(Salamander* p) {
  Salamander* q = (p->e).owner;

  q->flags &= (u16)~SALAFLAG_UNK_1;
  q->unk_c4d = 0;
  q->turnTileIdx = 0;
  q->unk_cb9 = Random() & 3;
  q->hoverPhase = 0;
  Enemy_SetSpritePos(&p->e, &q->homePos);
  (p->e).mover.pos = q->homePos;
  Salamander_ResetRecentTiles(p);
  Salamander_SetAllSegmentsPos(q, &(p->e).mover.pos);
  Salamander_PickNextTile(p);
  ClearMemory((p->e).pathNodePos, 8);
  Enemy_ResetState(&p->e, 0, 0, 2);
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
}

// 頭と奇数番目の節を sin で揺らし, 偶数番目の節を前後の位置の中ほどに置く
// 300/281命令, Ghost_StepCurve と同じ Hermite の壁 (原典は t=512 の係数を一部だけ畳み, 0 との掛け算や or を残す), 1回目の下書きで切り上げ
NON_MATCH void Salamander_SwayBody(Salamander* p) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
  Vec3 prev, d, v, pos;
  s32 sign;
  s32 i;

  (p->e).s->aux.spr.pos.x += FixToInt(12, COS(q->swayAngle) * 2);
  (p->e).s->aux.spr.pos.y += FixToInt(12, SIN(q->swayAngle) * 16);
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
    Vec3_Clear(&v);
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
    Salamander_SetSegmentPos(q, i, &pos);
    prev = q->segments[i + 1].sprite.pos;
  }
#else
  INCFUNC("asm/func/Salamander_SwayBody.inc");
#endif
}

// SALSEGFLAG_DESTROYED が落ちている節の1つおきに SALSEGFLAG_FOLLOW を落とす
void Salamander_UnfollowAlternateSegments(Salamander* p) {
  Salamander* q = (p->e).owner;
  SalamanderSegment* seg = q->segments;
  s32 n = 0;
  s32 i;

  for (i = 0; i < q->segmentCount; seg++, i++) {
    if (!Salamander_TestSegmentFlags(seg, SALSEGFLAG_DESTROYED)) {
      if (n == 1) {
        n = 0;
      } else {
        CLEAR_FLAGS(seg->flags, SALSEGFLAG_FOLLOW);
        n++;
      }
    }
  }
}

// 尾から見て最初の壊れていない節を壊し, 爆発と粒子を出す
// 77/78命令, 原典は外側の i を数え続け (こちらは &segs[i] のポインタに置き換わる), 当たった後に segs + i*208 を作り直す, 試済: 内側を q->segments[i] で書く, 内側の数え上げに i を使い回す
NON_MATCH bool8 Salamander_DestroyTailSegment(Salamander* p) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
  SalamanderSegment* segs = q->segments;
  s32 i, j;

  for (i = q->segmentCount - 1; i >= 0; i--) {
    if (!Salamander_TestSegmentFlags(&segs[i], SALSEGFLAG_DESTROYED)) {
      SET_FLAGS(segs[i].flags, SALSEGFLAG_DESTROYED);
      q->segmentsLeft--;
      Explosion_CreateWithAttrs(&segs[i].sprite.pos, 16, 64, 42, HBATTR_INKA | HBATTR_BLOW | HBATTR_FLAME, 60, 0, 0);
      for (j = 0; j < 8; j++) {
        Salamander_ScatterSpark(&segs[i].sprite.pos);
      }
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Salamander_DestroyTailSegment.inc");
#endif
}

void Salamander_DestroyAllSegments(Salamander* p) {
  Salamander* q = (p->e).owner;
  SalamanderSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft != 0) {
    for (i = q->segmentCount - 1; i >= 0; i--) {
      if (!Salamander_TestSegmentFlags(&segs[i], SALSEGFLAG_DESTROYED)) {
        SET_FLAGS(segs[i].flags, SALSEGFLAG_DESTROYED);
        q->segmentsLeft--;
      }
    }
  }
}

// Salamander_DestroyAllSegments と同じ処理, どこからも呼ばれない
void Salamander_DestroyAllSegments2(Salamander* p) {
  Salamander* q = (p->e).owner;
  SalamanderSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft != 0) {
    for (i = q->segmentCount - 1; i >= 0; i--) {
      if (!Salamander_TestSegmentFlags(&segs[i], SALSEGFLAG_DESTROYED)) {
        SET_FLAGS(segs[i].flags, SALSEGFLAG_DESTROYED);
        q->segmentsLeft--;
      }
    }
  }
}

// 前の節を追っている節を床の高さに合わせる, 潜っていれば床へ (深すぎれば頭の高さへ), 浮いていれば差の 1/10 ずつ下げる
// 158/160命令, 原典は節の座標そのものを誘導変数にし (こちらは節の先頭 + 0x1C), p を r10 に置く (こちらは sp に退避), Salamander_HideBuriedSprites と同じ形の壁, 試済: y をローカルに受ける, 式の中で読む, 座標をポインタで渡す, 外側の if に包む, ループ本体の頭で座標を取る
NON_MATCH void Salamander_SnapSegmentsToFloor(Salamander* p) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
  s32 i;

  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_20)) {
    for (i = 0; i < q->segmentCount; i++) {
      if (Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_FOLLOW) && !Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED)) {
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
  INCFUNC("asm/func/Salamander_SnapSegmentsToFloor.inc");
#endif
}

// 前の節を追っている節を velocity だけ動かし, velocity を半分に減らす
void Salamander_ApplySegmentVelocity(Salamander* p) {
  Salamander* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_FOLLOW) && !Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED)) {
      q->segments[i].sprite.pos.x += q->segments[i].velocity.x;
      q->segments[i].sprite.pos.y += q->segments[i].velocity.y;
      q->segments[i].sprite.pos.z += q->segments[i].velocity.z;
      q->segments[i].velocity.x = FixToInt(1, q->segments[i].velocity.x);
      q->segments[i].velocity.y = FixToInt(1, q->segments[i].velocity.y);
      q->segments[i].velocity.z = FixToInt(1, q->segments[i].velocity.z);
    }
  }
}

void Salamander_AdvanceSwayIfMoving(Salamander* p, s32 speed) {
  if (speed != 0) {
    ((Salamander*)(p->e).owner)->swayAngle += 4;
  }
}

// 前の節を追っている節に乱数の向きで速さ 12 を与える, 頭の跳ねる速さが大きいほど向きの幅を広げる
void Salamander_ScatterSegments(Salamander* p) {
  Salamander* q = (p->e).owner;
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
    if (Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_FOLLOW) && !Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED)) {
      Vec3_SetPolar(&q->segments[i].velocity, Random() & spread, 12);
    }
  }
}

void FUN_081aba6c(Salamander* p) {
  Salamander* q = (p->e).owner;

  if (Salamander_TestFlags(q, SALAFLAG_UNK_1)) {
    Enemy_ResetState(&p->e, 0, 0, 4);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    (p->e).unk_544 = 180;
    (p->e).unk_1bc = 2;
  }
  CLEAR_FLAGS(q->flags, SALAFLAG_UNK_1);
}

// 節が受けたダメージを damageAccum に足してダメージ数字を出す
void Salamander_OnSegmentDamaged(Salamander* p, Hitbox* hitbox, SalamanderSegment* seg) {
  if (!Enemy_IsDead(&p->e) && !Salamander_TestFlags((p->e).owner, SALAFLAG_DYING)) {
    Vec3 v;

    ((Salamander*)(p->e).owner)->damageAccum += hitbox->damage;
    Vec3_Clear(&v);
    CreateDamageNumber(hitbox, hitbox->damage, 0, &seg->sprite.pos, &v, 1);
  }
}

void Salamander_OnSegmentHit(Hitbox* a, Hitbox* b, SalamanderSegment* seg) {}

void Salamander_InitSegmentHitboxes(Salamander* p) {
  Salamander* q = (p->e).owner;
  Vec3 halfSize, offset;
  s32 i;

  VEC3_SET(halfSize, 64, 100, 64);
  VEC3_SET(offset, 0, 128, 0);
  for (i = 0; i < q->segmentCount; i++) {
    SalamanderSegment* seg = &q->segments[i];

    Hitbox_Init(&seg->hitbox, (p->e).mover.id, HBF_HITBOX | HBF_ONCE | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    Hitbox_SetAttack(&seg->hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetPos(&seg->hitbox, &seg->sprite.pos, 0);
    Hitbox_SetHandler(&seg->hitbox, Salamander_OnSegmentHit, seg);
  }
}

void Salamander_InitAnims(Salamander* p) {
  Enemy_SetAnimEntry(&p->e, 14, 13, 0);
  Enemy_SetAnimEntry(&p->e, 15, 14, 0);
  Enemy_SetAnimEntry(&p->e, 16, 15, 0);
  Enemy_SetAnimEntry(&p->e, 17, 14, 0);
}

s32 Salamander_GetMoveSpeed(Salamander* p) { return 24; }

// 次の位置のタイルが壁か床より高ければ水平に止め, 行き詰まりが 30 フレーム続いたら向きを変えて行き先を選び直す
// 246/245命令, 原典は先読みの座標と目的地へのずれに同じスタックの Vec3 を使い, pos を先に読んで jumpVel を足す, 試済: Vec3_Sum の引数の順, Vec3 の共有, 成分ごとの直書き
NON_MATCH void Salamander_CheckStuck(Salamander* p) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
  WorldPos next;
  s32 idx;
  TileAttr attr;

  Vec3_Sum(&next, &(p->e).mover.pos, &(p->e).jumpVel);
  idx = GetCollisionTileIdx(&next);
  attr = TileAtIndex(idx)->attr;
  if ((p->e).floorY < TileHeightAtIndex(idx, &next) || (attr & (TATTR_PLAYER_WALL | TATTR_ENEMY_WALL | TATTR_FALLDEATH))) {
    (p->e).jumpVel.x = 0;
    (p->e).jumpVel.z = 0;
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  if (Salamander_TestFlags(q, SALAFLAG_UNK_2 | SALAFLAG_DYING | SALAFLAG_UNK_7)) {
    q->unk_c4d = 0;
  } else if ((p->e).mover.tile->unk_0[0] & 1) {
    if (++q->unk_c4d > 30) {
      Vec3 d;
      s32 diff;

      q->unk_cb9 = (q->unk_cb9 + 1) & 3;
      Salamander_PickNextTile(p);
      Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
      (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
      diff = (p->e).unk_1dc - (p->e).mover.angle;
      if (diff > 128) {
        diff -= 256;
      } else if (diff < -128) {
        diff += 256;
      }
      if (abs(diff) > 32) {
        Enemy_ResetState(&p->e, 0, 0, 1);
      }
    }
  } else {
    q->unk_c4d = 0;
  }
#else
  INCFUNC("asm/func/Salamander_CheckStuck.inc");
#endif
}

// pos から6方向へ煙を出す
void Salamander_EmitSmokeAround(WorldPos* pos) {
  Vec3 size;

  VEC3_SET(size, 80, 60, 60);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0x40, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0x80, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0xF0, 4, 20, 2, 1);
}

// unk_544 が 0 なら歩きアニメを速く, 60 以上なら遅くする
void Salamander_UpdateAnimSpeed(Salamander* p) {
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

// 最近通ったタイルを全て今いるタイルで埋める
void Salamander_ResetRecentTiles(Salamander* p) {
  Salamander* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    q->recentTiles[i] = (p->e).tileIdx;
  }
  q->recentTileIdx = 0;
}

bool8 Salamander_IsRecentTile(Salamander* p, u32 tileIdx) {
  Salamander* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    if (q->recentTiles[i] == tileIdx) {
      return TRUE;
    }
  }
  return FALSE;
}

void Salamander_AddRecentTile(Salamander* p, u32 tileIdx) {
  Salamander* q = (p->e).owner;

  q->recentTiles[q->recentTileIdx] = tileIdx;
  q->recentTileIdx = (q->recentTileIdx + 1) & 3;
}

void Salamander_OnAttackRequest(Salamander* p) {
  Enemy_ResetState(&p->e, 0, 2, 0);
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
}

void FUN_081ac180(Salamander* p) {}

// 近くにいて正面の4分の1の向きに高さの差 511 以内でプレイヤーがいれば気付く
bool8 Salamander_TryDetectPlayer(Salamander* p) {
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
        Salamander* q = (p->e).owner;

        q->unk_cb9 = (((p->e).playerAngle + 0x80) & 0xFF) >> 6;
        q->unk_cb8 = 14;
        return TRUE;
      }
    }
  }
  return FALSE;
}

void Salamander_SelectAttack(Salamander* p) {
  Salamander* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !Salamander_TestFlags(q, SALAFLAG_DYING) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP | ENEFLAG3_STUN | ENEFLAG3_PETRIFIED | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    if (Salamander_TestFlags(q, SALAFLAG_UNK_2)) {
      Hitbox_ClearFlags(&(p->e).hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      Hitbox_SetFlags(&(p->e).hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
}

// 死んでいるか SALAFLAG_UNK_4 / SALAFLAG_DYING なら当たり判定を全部隠す, それ以外は頭の攻撃判定を姿に合わせ, 壊れていない節の攻撃判定を位置に置いて登録する
void Salamander_UpdateHitboxes(Salamander* p) {
  Salamander* q = (p->e).owner;
  s32 i;

  if (Enemy_IsDead(&p->e) || Salamander_TestFlags(q, SALAFLAG_UNK_4 | SALAFLAG_DYING)) {
    Hitbox_Hide(&(p->e).hitbox);
    Hitbox_Hide(&(p->e).hurtbox);
    for (i = 0; i < q->segmentCount; i++) {
      q->segments[i].hitbox.flags |= HBF_HIDDEN;
    }
    return;
  }
  if ((p->e).s->aux.spr.flags & SPRFLAG_HIDDEN) {
    Hitbox_Hide(&(p->e).hitbox);
  } else {
    Hitbox_ClearFlags(&(p->e).hitbox, HBF_HIDDEN);
  }
  for (i = 0; i < q->segmentCount; i++) {
    if (!Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED)) {
      Hitbox_ClearFlags(&q->segments[i].hitbox, HBF_HIDDEN);
      Hitbox_SetPos(&q->segments[i].hitbox, &q->segments[i].sprite.pos, 0);
      Hitbox_Register(&q->segments[i].hitbox);
      if (Salamander_TestFlags(q, SALAFLAG_UNK_2)) {
        Hitbox_ClearFlags(&q->segments[i].hitbox, HBF_ANGLE);
        Hitbox_SetAttack(&q->segments[i].hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
      } else {
        Hitbox_SetFlags(&q->segments[i].hitbox, HBF_ANGLE);
        Hitbox_SetAttack(&q->segments[i].hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
      }
    }
  }
}

void Salamander_FlashSegment(SalamanderSegment* seg) {
  SET_FLAGS(seg->flags, SALSEGFLAG_FLASH);
  Video_SetAuxSpritePltt(&seg->gfx, OBP_WHITE_306);
  seg->flashTimer = 6;
}

void Salamander_SetSegmentFadePltt(Salamander* p, s32 idx) {
  Salamander* q = (p->e).owner;
  rgb555* pltt = q->fade.pltt;

  q->segments[idx].gfx.plttID = 421;
  q->segments[idx].gfx.pltt = pltt;
}

void Salamander_SetAllSegmentsFadePltt(Salamander* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    Salamander_SetSegmentFadePltt(p, i);
  }
}

// fromPlttID の色から toPlttID の色へ steps 歩で寄せるフェードを始める
void Salamander_StartPaletteFade(Salamander* p, s32 toPlttID, s32 fromPlttID, s32 steps) {
  WormPaletteFade* fade = &p->fade;
  rgb555* dst = &gObjPlttData[toPlttID * 16];
  rgb555* src = &gObjPlttData[fromPlttID * 16];
  s32 i;

  fade->plttID = toPlttID;
  for (i = 0; i < 16; i++) {
    s32 color = src[i];

    fade->stepR[i] = ((dst[i] & 31) - (color & 31)) << 5;
    fade->stepG[i] = (((dst[i] >> 5) & 31) - ((color >> 5) & 31)) << 5;
    fade->stepB[i] = (((dst[i] >> 10) & 31) - ((color >> 10) & 31)) << 5;
    fade->stepR[i] = Div(fade->stepR[i], steps);
    fade->stepG[i] = Div(fade->stepG[i], steps);
    fade->stepB[i] = Div(fade->stepB[i], steps);
    fade->r[i] = (color & 31) << 5;
    fade->g[i] = ((color >> 5) & 31) << 5;
    fade->b[i] = ((color >> 10) & 31) << 5;
  }
  fade->timer = steps;
}

// フェードを1歩進めて pltt に書き出す, 歩数を使い切ったら TRUE を返す
bool8 Salamander_StepPaletteFade(Salamander* p) {
  Salamander* q;
  WormPaletteFade* fade;
  s32 i;

  if (Enemy_IsDead(&p->e)) {
    return FALSE;
  }
  q = (p->e).owner;
  fade = &q->fade;
  if (fade->timer == 0) {
    return TRUE;
  }
  for (i = 0; i < 16; i++) {
    fade->r[i] += fade->stepR[i];
    fade->g[i] += fade->stepG[i];
    fade->b[i] += fade->stepB[i];
    fade->pltt[i] = FixToInt(5, fade->r[i]) | (FixToInt(5, fade->g[i]) << 5) | (FixToInt(5, fade->b[i]) << 10);
  }
  if (--fade->timer == 0) {
    return TRUE;
  }
  return FALSE;
}

// フェードが終わるたびに OBP 421 と 422 の向きを入れ替えて次のフェードを始める
// 残差は &q->fadeToAlt の持ち方 (35/33命令), 原典は StepPaletteFade の後に1度だけ作り q のレジスタに持ち越す, 試済: 呼び出しを2つに分ける, 引数だけ選ぶ, アドレスをローカルに取る
NON_MATCH void Salamander_UpdatePaletteFade(Salamander* p) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
  s32 to, from;

  if (Salamander_StepPaletteFade(p)) {
    if (q->fadeToAlt) {
      to = 422, from = 421;
    } else {
      to = 421, from = 422;
    }
    Salamander_StartPaletteFade(p, to, from, 20);
    q->fadeToAlt ^= 1;
  }
#else
  INCFUNC("asm/func/Salamander_UpdatePaletteFade.inc");
#endif
}

// 頭と全ての節のパレットをフェード用のパレットに繋ぎ, OBP 422 から 421 へのフェードを始める
void Salamander_InitPaletteFade(Salamander* p) {
  Salamander* q = (p->e).owner;

  Salamander_StartPaletteFade(p, 421, 422, 20);
  q->fadeToAlt = TRUE;
  (p->e).s->aux.gfx.plttID = 421;
  (p->e).s->aux.gfx.pltt = q->fade.pltt;
  Salamander_SetAllSegmentsFadePltt(p);
}

// 床より下にある頭と節, 壊れた節のスプライトを隠す
// 135/138命令, 原典は節の flags のポインタを Map_FindTileOverride の呼び出しをまたいで sp に退避し, i を r8 に置く, 試済: 高さを式の中で求める, 高さをローカルに受ける, 座標のポインタをローカルに取る
NON_MATCH void Salamander_HideBuriedSprites(Salamander* p) {
#ifdef NONMATCHING_C
  Salamander* q = (p->e).owner;
  s32 i;

  if ((p->e).mover.pos.y < (p->e).floorY) {
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < q->segmentCount; i++) {
    Vec3* pos = &q->segments[i].sprite.pos;

    if (pos->y < TileHeightAt(pos) || Salamander_TestSegmentFlags(&q->segments[i], SALSEGFLAG_DESTROYED)) {
      q->segments[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
  }
#else
  INCFUNC("asm/func/Salamander_HideBuriedSprites.inc");
#endif
}

// '.d' のスクリプトを1度だけ実行する
void Salamander_RunScript(Salamander* p) {
  Salamander* q = (p->e).owner;

  if (q->scriptID != 0) {
    VM_ExecByID(q->scriptID, NULL);
    q->scriptID = 0;
  }
}

// Salamander_SpawnFireDebris の速さを 4..19 にしたもの
// 117/116命令, Salamander_SpawnFireDebris と同じ壁, 1回目の下書きで切り上げ
NON_MATCH void Salamander_SpawnFireDebris2(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 life;

  {
    u32 angle = RandomNext() & 0xFF;
    s32 speed = (RandomNext() & 0xF) + 4;

    Vec3_SetPolar(&vel, angle, speed);
  }
  {
    vel.y = (RandomNext() & 0x1F) - 16;
    life = (RandomNext() & 0x3F) + 20;
  }
  Debris_Spawn(pos, &vel, PTCL_GROUP_0, ANIM_D1B8, 3, 0, DEBRIS_FREE_ON_END | DEBRIS_PTCL | DEBRIS_BOUNCE, 0, 2, 0, 0, life, 4, 1, HBATTR_INKA | HBATTR_FLAME, 30, 8, 8);
#else
  INCFUNC("asm/func/Salamander_SpawnFireDebris2.inc");
#endif
}

// pos から攻撃判定付きの炎の破片を1つ, ランダムな向きと速さで飛ばす
// 116/115命令, Salamander_SpawnSpark / Entity081f9cb8_SpawnDebris と同じ壁 (gRandTableIdx のアドレスを1本のレジスタに持ち越す), 試済: SpawnDebris の下書きの形, idx のアドレスを inline でローカルに取る形
NON_MATCH void Salamander_SpawnFireDebris(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 life;

  {
    u32 angle = RandomNext() & 0xFF;
    s32 speed = RandomNext() & 0x1F;

    Vec3_SetPolar(&vel, angle, speed);
  }
  {
    vel.y = (RandomNext() & 0x1F) - 16;
    life = (RandomNext() & 0x3F) + 20;
  }
  Debris_Spawn(pos, &vel, PTCL_GROUP_0, ANIM_D1B8, 3, 0, DEBRIS_FREE_ON_END | DEBRIS_PTCL | DEBRIS_BOUNCE, 0, 2, 0, 0, life, 4, 1, HBATTR_INKA | HBATTR_FLAME, 30, 8, 8);
#else
  INCFUNC("asm/func/Salamander_SpawnFireDebris.inc");
#endif
}

// pos から火の粉を1つ, 水平方向はランダムな向きと速さ, 上へ 20..35 で飛ばす
// 77/76命令, 原典は gRandTableIdx のアドレスを3回の乱数で1本のレジスタに持ち越す, 試済: 成分ごとの代入, カンマ代入, Vec3_SetPolar, angle を u8 で受ける
NON_MATCH void Salamander_SpawnSpark(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 angle = RandomNext() & 0xFF;
  s32 speed = RandomNext() & 0x1F;

  Vec3_SetPolar(&vel, angle, speed);
  vel.y = (Random() & 0xF) + 20;
  Entity081ee2a0_SpawnDefault(pos, &vel, 30, 3);
#else
  INCFUNC("asm/func/Salamander_SpawnSpark.inc");
#endif
}

// pos から火の粉を1つ, ランダムな向きと速さで四方へ散らす
// 79/78命令, Salamander_SpawnSpark と同じ壁 (gRandTableIdx のアドレスを3回の乱数で1本のレジスタに持ち越す), 1回目の下書きで切り上げ
NON_MATCH void Salamander_ScatterSpark(Vec3* pos) {
#ifdef NONMATCHING_C
  Vec3 vel;
  u32 angle = RandomNext() & 0xFF;
  s32 speed = (RandomNext() & 0x1F) - 16;

  Vec3_SetPolar(&vel, angle, speed);
  vel.y = (Random() & 0x1F) - 16;
  Entity081ee2a0_SpawnDefault(pos, &vel, 60, 3);
#else
  INCFUNC("asm/func/Salamander_ScatterSpark.inc");
#endif
}

// 足元の床の高さで炎属性の爆発をすぐに起こす
void Salamander_ExplodeAtFeet(Salamander* p) {
  Vec3 pos = (p->e).mover.pos;

  pos.y = (p->e).floorY;
  Entity081f9cb8_Spawn(&pos, 0, 120, 60, HBATTR_INKA | HBATTR_BLOW | HBATTR_FLAME, 60);
}

// 炎属性の爆発を 120 フレーム後に pos で起こす
void Salamander_SpawnExplosion(Vec3* pos) { Entity081f9cb8_Spawn(pos, 120, 120, 60, HBATTR_INKA | HBATTR_BLOW | HBATTR_FLAME, 60); }

// 106/125命令, 原典は jumpVel.x と jumpVel.z の abs を求めて捨てる 19 命令を持つ (結果は使われない), 試済: abs を文で書く, 使わない変数に受ける, abs の比較で同じ呼び出しを両側に置く (比較が残る)
NON_MATCH void FUN_081acd90(Salamander* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Salamander_StateHover, ES_UNK_34);
    (p->e).unk_1bc = 8;
  }
  Salamander_PullSegments(p, 4, 12, 0x4000);
  Salamander_UpdateWave(p, 430, 40);
  if ((p->e).subStateDone) {
    Salamander_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_081acd90.inc");
#endif
}

void Salamander_SetHandlerTable4(Salamander* p) { (p->e).handlerTables[4] = (void*)sSalamanderHandlerTable4; }

s32 Salamander_PreUpdate(Salamander* p) {
  Salamander_UpdatePaletteFade(p);
  return 1;
}

s32 Salamander_PostUpdate(Salamander* p) {
  Salamander_UpdateHitboxes(p);
  Salamander_SelectAttack(p);
  Salamander_FollowSegments(p);
  Salamander_ApplySegmentVelocity(p);
  Salamander_SnapSegmentsToFloor(p);
  Salamander_HideBuriedSprites(p);
  CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_14);
  return 1;
}

// 被弾してもダメージ状態に移らない
bool8 Salamander_OnDamaged(Salamander* p) {
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5 | ENEFLAG3_UNK_8);
  return FALSE;
}

s32 Salamander_UpdateFrame(Salamander* p) {
  Salamander_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Salamander_PostUpdate(p);
  return 1;
}

// Enemy_Update から, 生きているときに unk_628 を呼ぶ所を抜いたもの
s32 Salamander_Update(Salamander* p) {
  Enemy* e = &p->e;

  e->playerMover = &gPlayerPtr[0]->mover;
  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), GAMEFLAG_GAMEOVER) || TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return FALSE;
  }

  if (!Enemy_TestFlag(e, ENEFLAG_UNK_1)) {
    if (!IsCurrentZone(e->zoneID)) {
      Enemy_Suspend(e, NULL);
      return FALSE;
    }

    Enemy_ProcessRequests(e);
    FUN_080e1f48(e);
    e->handlerFrame(e->owner);
    Enemy_UpdateHitboxes(e);
    Enemy_UpdateMovement(e);
    Enemy_ShakeSprite(e);
    FUN_080f06ac(e);
    return TRUE;
  }

  if (!Enemy_TestFlag(e, ENEFLAG_UNK_0) && IsCurrentZone(e->zoneID)) {
    Enemy_Resume(e, NULL);
  }
  FUN_080f06ac(e);
  return FALSE;
}

s32 Salamander_Destroy(Salamander* p) {
  Salamander_RemoveSegmentSprites(p);
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
// 1840/2004命令, Golem_Init の下書きを Salamander 向けに直したもの (呼び出し列は一致), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline, フレーム 0x1E0, こちらは 0x7C), 1回目の下書きで切り上げ
NON_MATCH s32 Salamander_Init(Salamander* p) {
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
  (p->e).kind = ENEK_SALAMANDER;
  Salamander_InitAnims(p);
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
    p->unk_c4a = VM_GetPC() != NULL ? VM_GetValue() : 300;
  }
  p->scriptID = VM_GetNamedArgValue('d', 0);
  p->unk_c48 = 0;
  Salamander_ResetRecentTiles(p);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 421;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 421;
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

  Salamander_InitHitboxes(p);
  Salamander_InitFollowInterval(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Salamander_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Salamander_GetMoveSpeed;
  (p->e).handlerTurn = Salamander_StateTurn;
  (p->e).handlerMove = Salamander_StateMove;
  (p->e).handlerWait = Salamander_StateWait;
  (p->e).handlerNap = Salamander_StateNap;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = NULL;
  (p->e).handlerDying = Salamander_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = Salamander_StateRespawnWait;
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
  (p->e).unk_5e0 = Salamander_ClearStateBegun;
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
  (p->e).msgHandlers = (void*)sSalamanderMsgHandlers;
  (p->e).onReset = (EnemyHandler)Salamander_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).onAttackRequest = (EnemyHandler)Salamander_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)FUN_081ac180;
  (p->e).tryDetectPlayer = (void*)Salamander_TryDetectPlayer;
  (p->e).onDamaged = (void*)Salamander_OnDamaged;
  (p->e).unk_5b4 = (EnemyHandler)Salamander_ScatterSegments;
  (p->e).unk_1bc = 0;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9 | ENEFLAG_UNK_20);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_6);
  Enemy_InitShadowAndEmitter(&p->e);
  (p->e).shadowRemoved = AuxShadow_Init(&(p->e).auxShadow, &(p->e).mover.pos, 64, 64, 64, 100, 0, 0, 5, 1, 0);
  AuxShadow_SetSprite(&(p->e).auxShadow, SPR_EFF_1C1B, 6);
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
  Salamander_SetHandlerTable2(p);
  Salamander_SetHandlerTable4(p);
  Salamander_InitSegments(p, SPR_WORM, ANIM_WORM, (p->e).mover.angle);
  Salamander_SetAllSegmentsPos(p, &(p->e).mover.pos);
  Salamander_InitSegmentHitboxes(p);
  Salamander_PickNextTile(p);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  Enemy_ResetState(&p->e, 3, 0, 0);
  (p->e).pendingDelay = 120;
  (p->e).pendingHandler = (p->e).handlerMove;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 6;
  (p->e).mover.pos.y = (p->e).floorY;
  SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_9);
  Salamander_SpawnExplosion(&(p->e).mover.pos);
  (p->e).mover.pos.y = (p->e).floorY - 512;
  Salamander_SetAllSegmentsPos(p, &(p->e).mover.pos);
  Salamander_HideLiveSegments(p);
  (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
  (p->e).hurtbox.flags |= HBF_HIDDEN;
  Salamander_InitPaletteFade(p);
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
  (p->e).handlerUpdate = (EnemyHandler)Salamander_Update;
  (p->e).handlerDestroy = (EnemyHandler)Salamander_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Salamander_Init.inc");
#endif
}

// 0x522C, HashName("サラマンダー")
void Salamander_Create(void) {
  Salamander* p = Malloc(sizeof(Salamander));

  if (p != NULL) {
    ClearMemory(p, sizeof(Salamander));
    if (Salamander_Init(p) < 0) {
      Salamander_Destroy(p);
      Free(p);
    }
  }
}

// プレイヤーへ向けて水平に 32 の速さで跳ね, 着くまでの時間から縦の速さを決める
void Salamander_AimJumpAtPlayer(Salamander* p) {
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
