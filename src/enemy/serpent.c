#include "cwolf_target.h"
#include "eff_elemcond.h"
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

struct Serpent;

// SerpentSegment.flags (0x122)
typedef u16 SerpentSegmentFlags;
#define SERPSEGFLAG_DESTROYED (1 << 0)  // 0x01, 壊れた節
#define SERPSEGFLAG_FOLLOW (1 << 1)     // 0x02, 1つ前の節の位置を引き継ぐ
#define SERPSEGFLAG_UNK_2 (1 << 2)      // 0x04, 立っていると節のアニメを 11 番にする
#define SERPSEGFLAG_FLASH (1 << 6)      // 0x40, 被弾して白く光っている
#define SERPSEGFLAG_UNK_8 (1 << 8)      // 0x100
#define SERPSEGFLAG_UNK_7 (1 << 7)      // 0x80

// サーペントの体の節1つ, SalamanderSegment に食らい判定を足した形
typedef struct {
  AuxSprite sprite;           // 0x000
  AuxSpriteGfx gfx;           // 0x02C, ID は固定でない
  Hitbox hitbox;              // 0x048, 節ごとの攻撃判定
  Hitbox hurtbox;             // 0x098, 節ごとの食らい判定, 防御力は Serpent.segmentDefense (尾だけ tailDefense)
  AuxAnimState anim;          // 0x0E8
  AuxAnimFile* animFile;      // 0x0F8, ID は固定でない
  u8 angle;                   // 0x0FC, 節の向き
  u8 unk_fd[3];               // 0x0FD
  u8 knockbackAngle;          // 0x100, 弾かれる向き, hurtbox.knockback と合わせて velocity にする
  u8 swayAngle;               // 0x101, 奇数番目の節を横に揺らす sin の角度
  u8 wobbleAngle;             // 0x102, velocity を sin で揺らす角度
  u8 flashTimer;              // 0x103, 白く光らせるフレーム数, 6
  u8 unk_104[8];              // 0x104
  Vec3 targetPos;             // 0x10C, 1つ前の節の位置, sprite.pos がここへ寄っていく
  Vec3 velocity;              // 0x114
  struct Serpent* owner;      // 0x11C
  u16 unk_120;                // 0x120
  SerpentSegmentFlags flags;  // 0x122
} SerpentSegment;
static_assert(sizeof(SerpentSegment) == 292);

// Serpent.flags (0xF2C)
typedef u16 SerpentFlags;
#define SERPFLAG_UNK_1 (1 << 1)    // 0x02, 立っていると副状態 (0, 0, 4) へ移して落とす
#define SERPFLAG_UNK_2 (1 << 2)    // 0x04, 立っていると攻撃判定に atk の [1] を載せ, HBF_ANGLE を外す
#define SERPFLAG_UNK_3 (1 << 3)    // 0x08, 着水して潜り始めると立つ
#define SERPFLAG_UNK_4 (1 << 4)    // 0x10, 立っていると移動の速さを倍にする
#define SERPFLAG_DYING (1 << 5)    // 0x20, hp が尽きると立つ, 立っていると受けたダメージを damageAccum に足さない
#define SERPFLAG_UNK_6 (1 << 6)    // 0x40, 節の食らい判定に当たるたびに立つ
#define SERPFLAG_UNK_7 (1 << 7)    // 0x80, Serpent_SubLeap で跳んでから着地するまで立つ
#define SERPFLAG_FADING (1 << 8)   // 0x100, Serpent_StartPaletteFade が立て, 立っている間 Serpent_StepPaletteFade がフェードを進める
#define SERPFLAG_UNK_10 (1 << 10)  // 0x400
#define SERPFLAG_UNK_11 (1 << 11)  // 0x800
#define SERPFLAG_UNK_12 (1 << 12)  // 0x1000, 立っていると尾から3つめの節に OBP 426 の色を載せない
#define SERPFLAG_UNK_13 (1 << 13)  // 0x2000
#define SERPFLAG_UNK_14 (1 << 14)  // 0x4000, 泡を吐く間に unk_e3d へ向けて首を振る
#define SERPFLAG_UNK_15 (1 << 15)  // 0x8000

// 中ボス, ENEK_SERPENT(ENEID_SERPENT), Salamander と同じく節を連ねた体を持つ
typedef struct Serpent {
  Enemy e;
  u8 unk_654[4];               // 0x654
  SerpentSegment segments[6];  // 0x658
  Vec3 wanderTarget;           // 0xD30, wanderBase から ±64 ずらした行き先
  Vec3 wanderBase;             // 0xD38
  u16 wanderTimer;             // 0xD40, 0 になると wanderTarget を選び直す, 30..93
  u8 unk_d42;                  // 0xD42
  u8 unk_d43;                  // 0xD43
  Vec3 unk_d44;                // 0xD44
  u16 unk_d4c;                 // 0xD4C
  s8 unk_d4e;                  // 0xD4E
  s8 diveCount;                // 0xD4F, 水へ潜り終えるたびに 1 増える, 4 を超えると潜るのをやめる
  u16 unk_d50;                 // 0xD50, 40, 弱っていれば 80
  u16 swimTimeMax;             // 0xD52, swimTimer の上限, 100, 弱っていれば 200
  u16 unk_d54;                 // 0xD54, 80..143, 弱っていれば 160..223
  u16 unk_d56;                 // 0xD56, 1, 弱っていれば 3
  WormPaletteFade fade;        // 0xD58
  u8 unk_e3c;                  // 0xE3C
  u8 unk_e3d;                  // 0xE3D
  u8 unk_e3e;                  // 0xE3E
  bool8 rapidBubbles;          // 0xE3F, 泡を吐く間, 小さい泡を 8 フレームごとに2つずつ吐く (FALSE なら小さい泡を 10 フレーム, 大きい泡を 32 フレームごと)
  u8 unk_e40;                  // 0xE40
  u8 waitTimer;                // 0xE41, 0 になるまで毎フレーム減らし, 尽きると waitTime から戻す
  u8 waitTime;                 // 0xE42, waitTimer に戻す値, 30, hp が unk_546 以下なら半分を入れる
  u8 recentNodeIdx;            // 0xE43, recentNodes の次に書く添字, 0..2 を巡回する
  s8 recentNodes[3];           // 0xE44, 最近行き先に選んだ経路ノードの番号, 次の候補から外す, 空きは -1
  u8 unk_e47;                  // 0xE47
  rgb555 tailPltts[4][16];     // 0xE48, 尾から3つの節に載せる OBP 426..428 の色と, SERPSEGFLAG_UNK_8 の節に載せる OBP 429 の色
  u16 scriptID;                // 0xEC8, '.d'
  u16 unk_eca;                 // 0xECA
  u8 followInterval;           // 0xECC, 節が1つ前の節の位置を引き継ぐ間隔 (フレーム)
  u8 hoverPhase;               // 0xECD
  u8 unk_ece[2];               // 0xECE
  u16 swimTimer;               // 0xED0, Serpent_SubSwim で泳いだフレーム数, swimTimeMax を超えると潜りに移る
  u8 segmentDefense;           // 0xED2, '.P[0]=44', 尾以外の節の食らい判定の防御力, 弱点は頭と尾
  u8 tailDefense;              // 0xED3, '.P[1]=44', 尾の節の食らい判定の防御力 (尾は弱点)
  u8 recentTileIdx;            // 0xED4, recentTiles の次に書く添字
  u8 blockedTimer;             // 0xED5, 水場の外へ進めず止まっているフレーム数
  u16 turnTileIdx;             // 0xED6
  u16 damageAccum;             // 0xED8, 受けたダメージの累計
  u8 unk_eda[2];               // 0xEDA
  u16 recentTiles[6];          // 0xEDC, 最近通ったタイルの索引
  u8 unk_ee8[0xF2C - 0xEE8];   // 0xEE8
  SerpentFlags flags;          // 0xF2C
  u8 swayAngle;                // 0xF2E, 頭の位置を sin で揺らす角度
  u8 shiftTimer;               // 0xF2F, 0 になるたびに 12 に戻して頭, 中, 尾の節の位置を1つずつ後ろへ送る
  s8 waveDir;                  // 0xF30, 1 / -1, waveOffset を動かす向き
  u8 unk_f31[3];               // 0xF31
  s16 waveOffset;              // 0xF34, -振幅..振幅 を往復する
  s16 segmentCount;            // 0xF36, 節の数
  u8 unk_f38[8];               // 0xF38
  u16 unk_f40;                 // 0xF40, 行き先を選び直すたびに 40
  u8 unk_f42;                  // 0xF42
  u8 unk_f43;                  // 0xF43
  u8 unk_f44;                  // 0xF44
  u8 unk_f45;                  // 0xF45, 4方向の向き
  u8 segmentsLeft;             // 0xF46, 壊れていない節の数
  u8 hpPerSegment;             // 0xF47, hp / (segmentCount + 1)
  s32 unk_f48;                 // 0xF48, 0x7FFFFFFF でなければ unk_f4c の節を弾いて 0x7FFFFFFF に戻す
  SerpentSegment* unk_f4c;     // 0xF4C
  NavAgent navAgent;           // 0xF50, Enemy.navAgent が指す
  Vec3 pathNodePos;            // 0xF74, Enemy.pathNodePos が指す
  Vec3 turnTilePos;            // 0xF7C, turnTileIdx のタイルの中心
  Vec3 homePos;                // 0xF84, 生成時の mover.pos
  Vec3 leapDest;               // 0xF8C, 跳ぶ先の水場
} Serpent;
static_assert(sizeof(Serpent) == 3988);

// anim 番の variant を流す, MainSprite では anim + variant 番を flags の向きと逆再生で流し, 同じものが流れていれば何もしない
static inline void Serpent_PlayDirAnim(Serpent* p, u32 anim, u32 variant, u32 flags) {
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
static inline s32 Serpent_AngleDiff(s32 a, s32 b) {
  s32 d = a - b;

  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  return d;
}

// angle が target まで回りきった (差が 32 未満) なら TRUE
static inline bool32 Serpent_IsTurnedTo(s32 target, s32 angle) {
  if (Serpent_AngleDiff(target, angle) < 32) return TRUE;
  return FALSE;
}

static inline bool8 Serpent_TestSegmentFlags(SerpentSegment* seg, SerpentSegmentFlags bit) {
  if (seg->flags & bit) return TRUE;
  return FALSE;
}

static inline void Serpent_SetFlags(Serpent* p, SerpentFlags bit) { p->flags |= bit; }
static inline void Serpent_ClearFlags(Serpent* p, SerpentFlags bit) { p->flags &= ~bit; }

static inline bool8 Serpent_TestFlags(Serpent* p, SerpentFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

void Serpent_SetSegmentPos(Serpent* p, s32 idx, Vec3* pos);
void Serpent_SetAllSegmentsPos(Serpent* p, Vec3* pos);
void Serpent_HideLiveSegmentsFrom(Serpent* p, s32 idx);
void Serpent_EmitSegmentBubbles(Serpent* p, s32 idx, s32 interval);
void Serpent_PickNextTile(Serpent* p);
void Serpent_ResetWaitTimer(Serpent* p);
void Serpent_ResetRecentTiles(Serpent* p);
void Serpent_GetAnimVariant(u16 angle, u32* variant, u32* xflip);
void Serpent_AnimateSegments(Serpent* p, s32 idx);
void Serpent_PullSegments(Serpent* p, s32 followDiv, s32 linkDiv, s32 followDistSq);
s32 Serpent_UpdateSegmentsBuried(Serpent* p);
void Serpent_WobbleSegments(Serpent* p, s32 amplitude, s32 step, s32 horizontal);
s32 Enemy_UpdateMovement(Enemy* p);
s32 FUN_080e1f48(Enemy* p);
s32 Enemy_UpdateHitboxes(Enemy* p);
bool32 Enemy_ProcessRequests(Enemy* p);
bool32 Enemy_ShakeSprite(Enemy* p);
void FUN_080f06ac(Enemy* p);
void HUD_ShowEnemyGauge(s32 moverID, s32 hp, u16 maxHP, u16 cells, s32 flash);
void FUN_0818a47c(Serpent* p);
void Serpent_AnimateSegments2(Serpent* p, s32 idx);
s32 Serpent_DestroyTailSegment(Serpent* p);
void Serpent_StateDying(Serpent* p, s32 timer);
void Serpent_FindWaterAcross(Serpent* p, Vec3* out, Vec3* pos);
void Serpent_FindNearestPathNode(Serpent* p, Vec3* out, Vec3* pos);
bool8 Serpent_IsRecentTile(Serpent* p, u32 tileIdx);
void Entity080df420_Spawn(WorldPos* pos, Vec3* vel, s32 kind, s32 unk_f0, s32 iframes, s32 power, s32 knockback, HitboxAttrs attrs, s32 atkIframes);
void Serpent_AddRecentTile(Serpent* p, u32 tileIdx);
void Serpent_PickPathNode(Serpent* p, Vec3* out, Vec3* pos, s32 limitSq, bool32 far);
void Serpent_FindWaterEdge(Serpent* p, Vec3* out, Vec3* pos);
void Serpent_SpawnSegmentSplashes(Serpent* p, s32 idx);
void Serpent_SpawnBubble(Vec3* pos, s32 y);
void DefeatedEnemyLog_Add(u16 a, u16 b);
void Enemy_AddKillCount(Enemy* p);
void Serpent_DestroyAllSegments(Serpent* p);
void Serpent_StatePounce(Serpent* p);
void Serpent_EmitSegmentBubbles(Serpent* p, s32 idx, s32 interval);
void Serpent_AdvanceSwayIfMoving(Serpent* p, s32 speed);
void Serpent_ResetWave(Serpent* p);
void Serpent_UpdateWave(Serpent* p, s32 amplitude, s32 speed);
void Serpent_SpawnSplashes(Serpent* p);
bool8 Serpent_TryHearNoise(Serpent* p);
void Serpent_RunScript(Serpent* p);
void Serpent_SetSegmentVelocity(Serpent* p, Vec3* velocity, s32 idx);
void FUN_08189958(Serpent* p, s32 timer);
void Serpent_RestartSegmentAnims(Serpent* p, s32 idx, s32 variant, s32 flags);
void Serpent_SprayBubbles(Vec3* pos, s32 count, s32 angle, bool32 clockwise);
void Serpent_StateSpitBubbles(Serpent* p, s32 timer);
void Serpent_StartPaletteFade(Serpent* p, s32 toPlttID, s32 fromPlttID, s32 steps);
void Serpent_FlashSegment(SerpentSegment* seg);
void Serpent_StateLand(Serpent* p, s32 timer);
void Serpent_AimJumpAtPlayer(Serpent* p);
void Serpent_OnSegmentHit(Hitbox* a, Hitbox* b, SerpentSegment* seg);
void Serpent_SetSegmentsSunk(Serpent* p, s32 from, s32 to, bool32 sunk);
s32 Serpent_UpdateSegmentsBuried(Serpent* p);
void Serpent_StateHover(Serpent* p, s32 timer);
void Entity081ee7a8_SpawnEx(Vec3* pos, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17);
s8 NoiseManager_FindFirstHeardNoise(s32 x, s32 y, s32 size, u8 mask, u16 moverID);
void FUN_080e8f20(Enemy* p, s32 param_2);
void FUN_080df478(void);
void* Entity081f26bc_Spawn(Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 ofsX, s32 ofsY);

void Serpent_SubCircle(Serpent*);
void Serpent_SubTurn(Serpent*);
void Serpent_SubSwim(Serpent*);
void Serpent_SubHop(Serpent*);
void Serpent_SubLeap(Serpent*);
void FUN_0818bdf0(Serpent*);
void Serpent_SubLeapAcross(Serpent*);
void Serpent_SubSubmerge(Serpent*);
void FUN_0818cfb8(Serpent*);
void Serpent_SubLeapOut(Serpent*);
void Serpent_SubWander(Serpent*);
void FUN_0818dd0c(Serpent*);
void Serpent_SubDive(Serpent*);
void FUN_0818de20(Serpent*);
void FUN_0818c080(Serpent*);
void Serpent_SubDying(Serpent*);
void FUN_0818d5b0(Serpent*);
void FUN_0818c31c(Serpent*);

// clang-format off
void (*const sSerpentHandlerTable2[24])(Serpent*) = {
    Serpent_SubCircle,
    Serpent_SubTurn,
    Serpent_SubSwim,
    (void*)FUN_080f2364,
    Serpent_SubHop,
    Serpent_SubLeap,
    FUN_0818bdf0,
    NULL,
    NULL,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    Serpent_SubLeapAcross,
    Serpent_SubSubmerge,
    FUN_0818cfb8,
    Serpent_SubLeapOut,
    Serpent_SubWander,
    FUN_0818dd0c,
    Serpent_SubDive,
    FUN_0818de20,
    FUN_0818c080,
    Serpent_SubDying,
    FUN_0818d5b0,
    FUN_0818c31c,
};  // 0x085ADCF4
// clang-format on

// 歩きアニメのコマ (cmdIdx & 3) ごとの移動の速さ
const u32 sSerpentMoveSpeeds[4] = {16, 16, 19, 24};  // 0x085ADD54

void FUN_08193ca4(Serpent*);
void FUN_08193dc8(Serpent*);
void FUN_08193fa4(Serpent*);
void FUN_081940d8(Serpent*);

void (*const sSerpentHandlerTable4[4])(Serpent*) = {
    FUN_08193ca4,
    FUN_08193dc8,
    FUN_08193fa4,
    FUN_081940d8,
};  // 0x085ADD64

void Serpent_OnDamageMsg(Serpent*, u16*);

// メッセージ表
void (*const sSerpentMsgHandlers[7])(Serpent*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    Serpent_OnDamageMsg,
};  // 0x085ADD74

void Serpent_OnHit(Hitbox* a, Hitbox* b, Serpent* p) {
  if (!Enemy_IsDead(&p->e)) {
    if (b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 食らい判定, 死に際でなければ敵共通の処理を通して SERPFLAG_UNK_6 を立てる
// 784/796命令, Salamander_OnHurt / Golem_OnHurt と同じ共通 inline (Enemy_HandleHurt) の壁, 1回目の下書きで切り上げ
NON_MATCH void Serpent_OnHurt(Hitbox* a, Hitbox* b, Serpent* p) {
#ifdef NONMATCHING_C
  if (!Enemy_IsDead(&p->e) && !Serpent_TestFlags((p->e).owner, SERPFLAG_DYING)) {
    Enemy_HandleHurt(a, b, &p->e);
    SET_FLAGS(((Serpent*)(p->e).owner)->flags, SERPFLAG_UNK_6);
  }
#else
  INCFUNC("asm/func/Serpent_OnHurt.inc");
#endif
}

void Serpent_StateMove(Serpent* p) {
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Serpent_AnimateSegments2((p->e).owner, 15);
  } else {
    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Serpent_AnimateSegments2((p->e).owner, 15);
  }
}

// Serpent_StateMove と同じ処理で animTable[17] を流す, どこからも呼ばれない
void FUN_081892fc(Serpent* p) {
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Serpent_PlayDirAnim(p, (p->e).animTable[17].anim, variant, flags);
    Serpent_AnimateSegments2((p->e).owner, 15);
  } else {
    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Serpent_PlayDirAnim(p, (p->e).animTable[17].anim, variant, flags);
    Serpent_AnimateSegments2((p->e).owner, 15);
  }
}

void Serpent_StateWait(Serpent* p) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Serpent_AnimateSegments((p->e).owner, 15);
}

void Serpent_StateTurn(Serpent* p) {}

void FUN_0818960c(Serpent* p) {}

void FUN_08189610(Serpent* p) {}

// 向きと逆へ下がりながら浮き上がり, 残りの節の数で決まる高さに着いたら FUN_08189958 の状態へ移る
void Serpent_StateRise(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 limit;
  s32 n;
  s32 i;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    u32 variant, flags;

    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Serpent_RestartSegmentAnims(q, 15, variant, flags);
    SET_FLAGS(q->flags, SERPFLAG_UNK_1);
  }
  Vec3_Clear(&(p->e).jumpVel);
  limit = q->segmentsLeft > 3 ? 300 : 200;
  if ((p->e).heightAboveFloor >= limit) {
    Enemy_EnterState(&p->e, FUN_08189958, ES_UNK_38);
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
    Serpent_HideLiveSegmentsFrom(q, 4);
    n = 0;
    for (i = 0; i < q->segmentCount; i++) {
      if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED | SERPSEGFLAG_UNK_2)) {
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

// 色を OBP 424 へ寄せながら後ろへ下がって浮き, 一度止まってから前へ弧を描いて跳ぶ, フェードが終わったら Serpent_StateSpitBubbles の状態へ移る
// 残差は後半の SetPolar で angle と sp を置くレジスタの入れ替えだけ (261/261命令), 試済: v を1つにまとめる, angle / speed のローカル (u8/u32), POLAR 直書き
NON_MATCH void FUN_08189958(Serpent* p, s32 timer) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  Vec3 v;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->unk_e3c = 1;
    q->unk_e3d = 0;
    q->fade.timer = 64;
    Serpent_StartPaletteFade(p, 424, 419, 64);
    SET_FLAGS(q->flags, SERPFLAG_UNK_12);
  }
  if (timer < 20) {
    u32 angle = ((p->e).mover.angle + 0x80) & 0xFF;

    Vec3_SetPolar(&v, angle, q->unk_e3c);
    (p->e).mover.pos.x += v.x;
    (p->e).mover.pos.z += v.z;
    if (Mod(timer, 5) == 0) {
      q->unk_e3c += 2;
      (p->e).heightAboveFloor += 10;
    }
  } else if (timer < 42) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  } else if (timer < 64) {
    u32 angle = (p->e).mover.angle;
    s32 speed = q->unk_e3c;

    Vec3_SetPolar(&v, angle, speed);
    (p->e).mover.pos.x += v.x;
    (p->e).mover.pos.z += v.z;
    (p->e).heightAboveFloor += POLAR_X(32, q->unk_e3d);
    q->unk_e3d += 10;
    if (Mod(timer, 6) == 0) {
      q->unk_e3c++;
    }
    if (timer == 52) {
      AuxShadow_Show(&(p->e).auxShadow);
    }
  }
  Serpent_HideLiveSegmentsFrom(q, 4);
  if (q->fade.timer == 0) {
    Enemy_EnterState(&p->e, Serpent_StateSpitBubbles, ES_UNK_41);
  }
#else
  INCFUNC("asm/func/FUN_08189958.inc");
#endif
}

// 色を戻しながら口の前から泡を吐く (小さい泡を速く連射するか, 小さい泡と大きい泡を混ぜて吐く), 弱っていれば首を振りながら吐く, フェードが終わったら FUN_0818a47c の状態へ移る
// 残差は入場時の hp 比較で 0x184 を作るレジスタ (r1/r2) の1か所だけ (951/951), 試済: unk_546 >= hp, 三項演算子, SET_FLAGS 直書き, <= 127, RandomNext, 定数の16進
NON_MATCH void Serpent_StateSpitBubbles(Serpent* p, s32 timer) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  WorldPos pos;
  Vec3 vel;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    u32 variant, flags;

    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Serpent_PlayDirAnim(p, (p->e).animTable[18].anim, variant, flags);
    Serpent_StartPaletteFade(p, 419, 424, 128);
    if ((Random() & 0xFF) < 128) {
      q->rapidBubbles = TRUE;
    } else {
      q->rapidBubbles = FALSE;
    }
    if ((p->e).hp <= (p->e).unk_546) {
      q->unk_e3d = (p->e).mover.angle + 0x30;
      q->unk_e3c = 10;
      Serpent_SetFlags(q, SERPFLAG_UNK_14);
    }
    PlaySound_082406e0(SONG_990);
  }
  if (Serpent_TestFlags(q, SERPFLAG_UNK_14)) {
    s32 diff = Serpent_AngleDiff(q->unk_e3d, (p->e).mover.angle);
    Vec3 v;
    u32 variant, flags;

    if (Mod(timer, 2) == 0) {
      if (abs(diff) < 8) {
        (p->e).mover.angle = q->unk_e3d;
        if (timer <= 48) {
          q->unk_e3d = (p->e).mover.angle - 102;
          q->unk_e3c = 10;
        }
      } else if (diff < 0) {
        (p->e).mover.angle -= 2;
      } else {
        (p->e).mover.angle += 2;
      }
      q->unk_e3c = FixToInt(1, q->unk_e3c);
    }
    Vec3_SetPolar(&v, (p->e).mover.angle, q->unk_e3c);
    (p->e).mover.pos.x += v.x;
    (p->e).mover.pos.z += v.z;
    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Serpent_PlayDirAnim(p, (p->e).animTable[18].anim, variant, flags);
  }
  {
    u32 variant, flip;

    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flip);
    pos = (p->e).mover.pos;
    switch (variant) {
      case 0: {
        pos.x -= 82;
        pos.z -= 96;
        break;
      }
      case 1: {
        if (flip) {
          pos.x -= 128;
        } else {
          pos.x += 32;
          pos.z -= 132;
        }
        break;
      }
      case 2: {
        if (flip) {
          pos.x -= 100;
          pos.z += 82;
        } else {
          pos.x += 128;
          pos.z -= 64;
        }
        break;
      }
      case 3: {
        if (flip) {
          pos.z += 96;
        } else {
          pos.x += 128;
          pos.z += 0;
        }
        break;
      }
      case 4: {
        pos.x += 64;
        pos.z += 64;
        break;
      }
    }
  }
  if (q->rapidBubbles) {
    if (Mod((p->e).subStateTimer, 8) == 0) {
      Vec3_SetPolar(&vel, (p->e).mover.angle + (RandomNext() & 0x3F) - 16, (RandomNext() & 7) + 8);
      Entity080df420_Spawn(&pos, &vel, 4, 400, 12, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
      Vec3_SetPolar(&vel, (p->e).mover.angle + (RandomNext() & 0x3F) - 16, (RandomNext() & 7) + 8);
      Entity080df420_Spawn(&pos, &vel, 4, 400, 12, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
    }
  } else {
    if (Mod((p->e).subStateTimer, 10) == 0) {
      Vec3_SetPolar(&vel, (p->e).mover.angle + (RandomNext() & 0x3F) - 32, (RandomNext() & 7) + 4);
      Entity080df420_Spawn(&pos, &vel, 4, 60, 12, (p->e).atkPower[2], (p->e).atkKnockback[2], (p->e).atkAttrs[2], (p->e).atkIframes[2]);
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
    }
    if (Mod((p->e).subStateTimer, 32) == 0) {
      Vec3_SetPolar(&vel, (p->e).mover.angle + (RandomNext() & 0x3F) - 32, (RandomNext() & 7) + 8);
      Entity080df420_Spawn(&pos, &vel, 8, 400, 12, (p->e).atkPower[3], (p->e).atkKnockback[3], (p->e).atkAttrs[3], (p->e).atkIframes[3]);
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
    }
  }
  if (q->fade.timer == 0) {
    Enemy_EnterState(&p->e, FUN_0818a47c, ES_UNK_42);
    Serpent_ClearFlags(q, SERPFLAG_UNK_12 | SERPFLAG_UNK_14);
  }
#else
  INCFUNC("asm/func/Serpent_StateSpitBubbles.inc");
#endif
}

void FUN_0818a47c(Serpent* p) {
  Serpent* q = (p->e).owner;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->unk_eca = q->segmentCount - 1;
  }
  q->segments[5].sprite.pos.y -= 128;
  Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Serpent_AnimateSegments2((p->e).owner, 15);
  if ((p->e).s->aux.spr.flags & SPRFLAG_HIDDEN) {
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_13);
    q->unk_eca = 0;
    AuxShadow_Hide(&(p->e).auxShadow);
    (p->e).subStateDone = 1;
  }
}

// 前の節を追う節に頭の移動量を 1/(i+1) にした速さを与え, 頭と節のアニメを流す
void FUN_0818a604(Serpent* p) {
  Serpent* q = (p->e).owner;
  u32 variant, flags;
  s32 i;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  for (i = 0; i < q->segmentCount; i++) {
    if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED | SERPSEGFLAG_UNK_2)) {
      q->segments[i].velocity.x = Div((p->e).mover.delta.x, i + 1);
      q->segments[i].velocity.y = 0;
      q->segments[i].velocity.z = Div((p->e).mover.delta.z, i + 1);
    }
  }
  Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Serpent_AnimateSegments2((p->e).owner, 15);
}

// 向きと逆へ下がりながら浮き上がり, 床から 256 を超えたら Serpent_StateHover の状態へ移る
void Serpent_StateLeapBack(Serpent* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
  Vec3_Clear(&(p->e).jumpVel);
  if ((p->e).heightAboveFloor > 255) {
    Enemy_EnterState(&p->e, Serpent_StateHover, ES_UNK_34);
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
    Serpent_PullSegments(p, 10, 12, 0x1000);
    Serpent_WobbleSegments(p, 20, 24, 0);
  }
}

// 宙で前後に揺れながら追う節の前の2つを頭の後ろに並べ, 60 フレーム後に Serpent_StatePounce へ移る
// 残差は speed を作る ands の演算子の並びだけ (320/320命令), Salamander_StateHover と同じ壁, 1回目の下書きで切り上げ
NON_MATCH void Serpent_StateHover(Serpent* p, s32 timer) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
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
    if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED | SERPSEGFLAG_UNK_2)) {
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
  Serpent_PullSegments(p, 64, 12, 0xFFFF);
  if (timer > 60) {
    Enemy_EnterState(&p->e, Serpent_StatePounce, ES_UNK_35);
  }
#else
  INCFUNC("asm/func/Serpent_StateHover.inc");
#endif
}

// プレイヤーへ向けて跳びかかり, 着地したら Serpent_StateLand の状態へ移る
void Serpent_StatePounce(Serpent* p) {
  Serpent* q = (p->e).owner;
  u32 variant, flags;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Serpent_AimJumpAtPlayer(p);
    (p->e).mover.angle = ArcTan2_8((p->e).jumpVel.x, (p->e).jumpVel.z);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_1);
  }
  Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Serpent_WobbleSegments(p, 18, 6, 0);
  Serpent_AnimateSegments2((p->e).owner, 15);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Serpent_StateLand, ES_UNK_36);
  } else {
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  }
}

// 着地してから節を引き寄せつつ 40 フレーム待ち, 終わったら副状態を進める
void Serpent_StateLand(Serpent* p, s32 timer) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
  Serpent_AnimateSegments((p->e).owner, 15);
  Serpent_PullSegments(p, 20, 12, 0x4000);
  if (timer > 40) {
    Serpent_GetAnimVariant((p->e).mover.angle, &variant, &flags);
    Serpent_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags);
    Serpent_AnimateSegments2((p->e).owner, 15);
    (p->e).subStateDone = 1;
  }
}

void Serpent_ClearStateBegun(Serpent* p) {
  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
}

// 被弾して減った hp に合わせて尾の節を壊し, 弾かれ終えたら副状態 5 へ移る
// 223/227命令, 敵共通の StateDamaged の壁 (原典はフラグのアドレスを先にスタックへ作り置く), 1回目の下書きで切り上げ
NON_MATCH void Serpent_StateDamaged(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 n;

    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    PlaySound_082406e0(CRY_BOKU_DAMAGED);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP);
    for (n = Div((p->e).hp, q->hpPerSegment); n < q->segmentsLeft; n++) {
      Serpent_DestroyTailSegment(p);
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
  INCFUNC("asm/func/Serpent_StateDamaged.inc");
#endif
}

// 泡を吹きながら点滅して消え, 節を全部壊して撃破スクリプト, 図鑑, 撃破数, 経験値を処理してから止まる
void Serpent_StateDying(Serpent* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_SetEmote(&p->e, 0, 127, 0);
    Enemy_SetEmote(&p->e, 1, 127, 0);
    Enemy_SetEmote(&p->e, 3, 127, 0);
    Enemy_FadeParticles(&p->e, 4);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    Hitbox_Hide(&(p->e).hurtbox);
    PlaySound_082406e0(SONG_420);
  }
  if (Mod(timer, 10) == 0) {
    Serpent_SprayBubbles(&(p->e).mover.pos, 5, (p->e).mover.angle, FALSE);
    Serpent_SprayBubbles(&(p->e).mover.pos, 5, (p->e).mover.angle, TRUE);
  }
  if (Sprite_UpdateVanishBlink(&(p->e).s->aux.spr.flags, timer, 10, 30)) {
    s32 idx;

    Serpent_SprayBubbles(&(p->e).mover.pos, 8, (p->e).mover.angle, FALSE);
    Serpent_SprayBubbles(&(p->e).mover.pos, 8, (p->e).mover.angle, TRUE);
    Serpent_DestroyAllSegments(p);
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
      DefeatedEnemyLog_Add(gMapInitScriptID, (p->e).mover.id);
    }
    (p->e).stunTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    (p->e).subStateDone = 1;
  }
}

// 尾の方を沈めて行き先へ泳ぎ, 着いたら次の行き先を決める, 向きが 32 より離れていれば向き直りへ, swimTimeMax を超えたら潜りの副状態 18 へ移る
void Serpent_SubSwim(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->waveDir = 1;
    q->waveOffset = 0;
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Serpent_ResetWave(p);
    if (!Serpent_TestFlags(q, SERPFLAG_UNK_15)) {
      PlaySound_082406e0(SONG_997);
      Serpent_SetFlags(q, SERPFLAG_UNK_15);
    }
    Serpent_SetSegmentsSunk(p, 2, 6, TRUE);
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Serpent_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    if (abs(Serpent_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
      Enemy_ResetState(&p->e, 0, 0, 1);
      return;
    }
  }
  Serpent_AdvanceSwayIfMoving(p, speed);
  Serpent_PullSegments(p, 10, 8, 0x4000);
  q->segments[4].velocity.y = FixToInt(8, SIN((p->e).subStateTimer));
  Serpent_EmitSegmentBubbles(p, Mod((p->e).unk_1ca, 6), 30);
  if (q->swimTimer > q->swimTimeMax) {
    Enemy_ResetState(&p->e, 0, 0, 18);
    q->unk_d4e = q->unk_d56;
  } else {
    q->swimTimer++;
    (p->e).subStateTimer++;
  }
}

// 今いるタイルの中で unk_1dc の向きへ向き直り, 向ききったら副状態 2 (SERPFLAG_UNK_4 なら 14) へ移る
void Serpent_SubTurn(Serpent* p) {
  Serpent* q = (p->e).owner;
  Vec3 v;
  s32 speed;
  s32 diff;
  s32 tile;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->turnTileIdx = (p->e).tileIdx;
    TilePosAtIndex(&q->turnTilePos, q->turnTileIdx);
    if (!Serpent_TestFlags(q, SERPFLAG_UNK_15)) {
      PlaySound_082406e0(SONG_997);
      Serpent_SetFlags(q, SERPFLAG_UNK_15);
    }
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  diff = Serpent_AngleDiff((p->e).unk_1dc, (p->e).mover.angle);
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
    (p->e).mover.delta.x += Div(v.x, 8);
    (p->e).mover.delta.z += Div(v.z, 8);
  }
  Serpent_PullSegments(p, 12, 8, 0x4000);
  q->segments[3].velocity.y = FixToInt(8, COS((p->e).subStateTimer & 0xFF));
  if (Serpent_TestFlags(q, SERPFLAG_UNK_4)) {
    Serpent_SpawnSplashes(p);
    if (Serpent_TryHearNoise(p)) {
      return;
    }
  } else {
    Serpent_EmitSegmentBubbles(p, 0, 20);
  }
  if (abs(diff) <= 7) {
    if (q->turnTileIdx == tile) {
      if (Serpent_TestFlags(q, SERPFLAG_UNK_4)) {
        Enemy_ResetState(&p->e, 0, 0, 14);
      } else {
        Enemy_ResetState(&p->e, 0, 0, 2);
      }
    }
  } else if (diff > 0) {
    (p->e).mover.angle += (p->e).animSpeedDiv * 4;
  } else {
    (p->e).mover.angle -= (p->e).animSpeedDiv * 4;
  }
  (p->e).subStateTimer++;
}

// 向きを少しずつ回しながら泳いで円を描き, 240 フレームを過ぎてプレイヤーの方を向いたら副状態 2 へ移る
void Serpent_SubCircle(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 speed, followDiv, turn, followDistSq;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    sound_08240740(SONG_997);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_15);
  }
  Vec3_Clear(&(p->e).jumpVel);
  if ((p->e).subStateTimer > 239 && Serpent_IsTurnedTo((p->e).playerAngle, (p->e).mover.angle)) {
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
  Serpent_PullSegments(p, followDiv, 12, followDistSq);
  (p->e).subStateTimer++;
}

void FUN_0818bdf0(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Serpent_StateRise, ES_UNK_37);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    sound_08240740(SONG_997);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_15);
  }
  if ((p->e).subStateDone) {
    Serpent_PickNextTile(p);
    Enemy_ResetState(&p->e, 0, 0, 2);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  } else {
    (p->e).subStateTimer++;
  }
}

// angle の向きへ速さ 32 で大きく跳び, 着地したら次の行き先を決めて副状態 20 へ移る
void Serpent_SubLeap(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).angle, 32);
    (p->e).jumpVel.y = 32;
    (p->e).unk_1bc = 2;
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_4);
    SET_FLAGS(q->flags, SERPFLAG_UNK_7);
  }
  Serpent_PullSegments(p, 6, 12, 0x1000);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Serpent_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 20);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_7);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_0818c080(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  }
  Serpent_PullSegments(p, 6, 12, 0x1000);
  if ((p->e).subStateTimer < 100) {
    if (Mod((p->e).subStateTimer, 20) == 0) {
      Serpent_WobbleSegments(p, 40, 24, 0);
    }
  } else if (Mod((p->e).subStateTimer, 40) == 0) {
    Serpent_WobbleSegments(p, 20, 44, 1);
  }
  if ((p->e).subStateTimer > 200) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 17);
    q->diveCount = 0;
    q->unk_d4e = 3;
  } else {
    (p->e).subStateTimer++;
  }
}

// 向いている方へ速さ 4 で跳ね, 着地したら次の行き先を決めて移動に戻る
void Serpent_SubHop(Serpent* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).mover.angle, 4);
    (p->e).jumpVel.y = 0;
    (p->e).unk_1bc = 2;
  }
  Serpent_PullSegments(p, 6, 12, 0x1000);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Serpent_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_0818c31c(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.pos.y = (p->e).floorY - 256;
    Serpent_SetAllSegmentsPos(q, &(p->e).mover.pos);
  }
  Serpent_EmitSegmentBubbles(p, 0, 10);
  Serpent_HideLiveSegmentsFrom(q, 0);
  if ((p->e).subStateTimer > 40) {
    Enemy_ResetState(&p->e, 0, 0, 12);
  } else {
    (p->e).subStateTimer++;
  }
}

// 水面から跳び出して水場 (音のした所, プレイヤー, 経路ノードの先) へ向けて跳び, 着水したら副状態 13 へ移る
// 残差はレジスタ選び 5 か所 (乱数表の番地 r5/r1, unk_204 の定数 r0/r5, ArcTan2_8 と距離の ldrsh の添字), reload の回し順が1つずれている形, 試済: 宣言位置, DistSq, <= 203, (u8)Random(), towardNoise の位置, 旗の inline/直書き混在
NON_MATCH void Serpent_SubLeapAcross(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3 d;
    u32 dist;
    bool32 towardNoise;

    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    towardNoise = FALSE;
    Serpent_SetSegmentsSunk(p, 0, 6, FALSE);
    if (Serpent_TestFlags(q, SERPFLAG_UNK_10)) {
      if (Serpent_TestFlags(q, SERPFLAG_UNK_11)) {
        Serpent_FindWaterAcross(p, &q->leapDest, &(p->e).unk_204);
        Serpent_ClearFlags(q, SERPFLAG_UNK_11);
        towardNoise = TRUE;
      } else if ((Random() & 0xFF) < 204) {
        Serpent_FindWaterAcross(p, &q->leapDest, &gPlayerPtr[0]->mover.pos);
      } else {
        Serpent_PickPathNode(p, &q->leapDest, &(p->e).mover.pos, 0x90000, TRUE);
      }
    } else {
      Serpent_FindWaterAcross(p, &q->leapDest, &(p->e).unk_204);
      towardNoise = TRUE;
    }
    Vec3_Delta(&d, &(p->e).mover.pos, &q->leapDest);
    (p->e).mover.angle = ArcTan2_8(d.x, d.z);
    dist = d.x * d.x + d.z * d.z;
    if (dist < 1024 * 1024) {
      (p->e).jumpVel.x = Div(d.x, 48);
      (p->e).jumpVel.y = 48;
      (p->e).heightAboveFloor = 0;
      (p->e).jumpVel.z = Div(d.z, 48);
    } else if (dist < 1400 * 1400) {
      (p->e).jumpVel.x = Div(d.x, 62);
      (p->e).jumpVel.y = 62;
      (p->e).heightAboveFloor = 0;
      (p->e).jumpVel.z = Div(d.z, 62);
    } else {
      if (towardNoise) {
        Serpent_FindNearestPathNode(p, &q->leapDest, &(p->e).unk_204);
      } else {
        Serpent_PickPathNode(p, &q->leapDest, &(p->e).mover.pos, 0x40000, TRUE);
      }
      Vec3_Delta(&d, &(p->e).mover.pos, &q->leapDest);
      (p->e).mover.angle = ArcTan2_8(d.x, d.z);
      (p->e).jumpVel.x = Div(d.x, 56);
      (p->e).jumpVel.y = 56;
      (p->e).heightAboveFloor = 0;
      (p->e).jumpVel.z = Div(d.z, 56);
    }
    (p->e).unk_1bc = 0;
    Serpent_SetFlags(q, SERPFLAG_UNK_2);
    Serpent_ClearFlags(q, SERPFLAG_UNK_4);
    AuxShadow_Show(&(p->e).auxShadow);
    Serpent_SpawnBubble(&(p->e).mover.pos, (p->e).floorY);
    PlaySound_082406e0(SONG_999);
    sound_08240740(SONG_997);
    Serpent_ClearFlags(q, SERPFLAG_UNK_15);
  }
  if ((p->e).subStateTimer < 10) {
    Vec3 v;
    s32 i;

    Vec3_Clear(&v);
    v.y = 16;
    for (i = 0; i < 3; i++) {
      Serpent_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 20) {
    Vec3 v;
    s32 i;

    Vec3_Clear(&v);
    v.y = 32;
    for (i = 0; i < 6; i++) {
      Serpent_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 60) {
    Vec3 v;
    s32 i;

    Vec3_Clear(&v);
    v.y = 64;
    for (i = 0; i < 6; i++) {
      Serpent_SetSegmentVelocity(p, &v, i);
    }
  }
  Serpent_PullSegments(p, 4, 8, 0x1000);
  Serpent_UpdateSegmentsBuried(q);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Vec3 d;

    Serpent_SpawnBubble(&(p->e).mover.pos, (p->e).floorY);
    PlaySound_082406e0(SONG_436);
    Serpent_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    Enemy_ResetState(&p->e, 0, 0, 13);
    AuxShadow_Hide(&(p->e).auxShadow);
    if (Serpent_TestFlags(q, SERPFLAG_UNK_10)) {
      q->waitTimer = q->waitTime;
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Serpent_SubLeapAcross.inc");
#endif
}

// 着水して水中へ潜り, 潜りきったら副状態 14 か (潜った回数が少なければ) 12 へ移る
void Serpent_SubDive(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.pos.y = (p->e).floorY;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Serpent_ClearFlags(q, SERPFLAG_UNK_2);
    (p->e).jumpVel.y = 24;
    (p->e).unk_1bc = 0;
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Serpent_ClearFlags(q, SERPFLAG_UNK_3);
    Serpent_ClearFlags(q, SERPFLAG_UNK_15);
  }
  Serpent_PullSegments(p, 6, 6, 0x1000);
  for (i = 0; i < q->segmentCount; i++) {
    Vec3 d;

    Vec3_Diff(&d, &q->segments[i].sprite.pos, &(p->e).mover.pos);
    if (d.x * d.x + d.z * d.z > 32000) {
      q->segments[i].sprite.pos.y = (p->e).floorY;
    }
  }
  Serpent_UpdateSegmentsBuried(q);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    Serpent_SpawnBubble(&(p->e).mover.pos, (p->e).floorY);
    PlaySound_082406e0(SONG_479);
    sound_08240740(SONG_997);
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    Serpent_SetFlags(q, SERPFLAG_UNK_3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
  }
  if (Serpent_TestFlags(q, SERPFLAG_UNK_3)) {
    (p->e).mover.pos.y -= 128;
    if (Serpent_UpdateSegmentsBuried(q) < 0) {
      if (q->unk_d4e > 0) {
        Enemy_ResetState(&p->e, 0, 0, 14);
        q->unk_d4e--;
      } else if (q->diveCount > 4) {
        Enemy_ResetState(&p->e, 0, 0, 14);
      } else {
        Enemy_ResetState(&p->e, 0, 0, 12);
        (p->e).mover.pos.y = (p->e).floorY;
        CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
        (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
        q->diveCount++;
      }
      return;
    }
  }
  (p->e).subStateTimer++;
}

// 水中へ沈み, 節が全部潜ったら SERPFLAG_UNK_10 なら waitTimer 後に浮かび直し, そうでなければ unk_d50 フレーム後に次の副状態へ移る
void Serpent_SubSubmerge(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Serpent_ClearFlags(q, SERPFLAG_UNK_2);
    q->unk_eca = 0;
    Serpent_ClearFlags(q, SERPFLAG_UNK_15);
    if (Serpent_TestFlags(q, SERPFLAG_DYING)) {
      PlaySound_082406e0(SONG_436);
    }
  }
  if ((p->e).mover.pos.y > -2048) {
    (p->e).mover.pos.y -= 128;
    if ((p->e).s->aux.spr.flags == 0 && (p->e).mover.pos.y < (p->e).floorY) {
      WorldPos pos = (p->e).mover.pos;

      pos.y = (p->e).floorY;
      Serpent_SprayBubbles(&pos, 2, (p->e).mover.angle, FALSE);
      (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
      if (!Serpent_TestFlags(q, SERPFLAG_DYING)) {
        PlaySound_082406e0(SONG_479);
      }
    }
  } else {
    (p->e).mover.pos.y = -2048;
  }
  if ((p->e).subStateTimer > 30) {
    Serpent_PullSegments(p, 10, 4, 0);
  } else {
    Serpent_PullSegments(p, 12, 6, 0xA410);
  }
  for (i = 0; i < q->segmentCount; i++) {
    Vec3 d;

    Vec3_Diff(&d, &q->segments[i].sprite.pos, &(p->e).mover.pos);
    if (d.x * d.x + d.z * d.z > 32000 && q->segments[i].sprite.pos.y < (p->e).floorY) {
      q->segments[i].sprite.pos.y = (p->e).floorY;
    }
  }
  Serpent_EmitSegmentBubbles(p, 0, 10);
  if (Serpent_UpdateSegmentsBuried(q) < 0) {
    sound_08240740(SONG_997);
    Serpent_ClearFlags(q, SERPFLAG_UNK_15);
    if (Serpent_TestFlags(q, SERPFLAG_DYING)) {
      if ((p->e).subStateTimer > 160) {
        Enemy_ResetState(&p->e, 0, 0, 19);
      }
    } else if (Serpent_TestFlags(q, SERPFLAG_UNK_10)) {
      if (q->waitTimer != 0) {
        q->waitTimer--;
        return;
      }
      (p->e).mover.pos.y = (p->e).floorY - 256;
      Serpent_SetAllSegmentsPos(q, &(p->e).mover.pos);
      (p->e).mover.pos.y = (p->e).floorY;
      Enemy_ResetState(&p->e, 0, 0, 12);
      CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
      Serpent_SprayBubbles(&(p->e).mover.pos, 2, (p->e).mover.angle, FALSE);
      (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
      q->unk_e40++;
      q->waitTimer = q->waitTime;
      if ((p->e).hp <= (p->e).unk_546) {
        if (q->unk_e40 > 4) {
          q->unk_e40 = 0;
          Serpent_ClearFlags(q, SERPFLAG_UNK_10);
        }
      } else if (q->unk_e40 > 2) {
        q->unk_e40 = 0;
        Serpent_ClearFlags(q, SERPFLAG_UNK_10);
      }
      return;
    } else if ((p->e).subStateTimer > q->unk_d50) {
      if (q->unk_d4e > 0) {
        Enemy_ResetState(&p->e, 0, 0, 14);
        q->unk_d4e--;
      } else {
        Enemy_ResetState(&p->e, 0, 0, 22);
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      }
      return;
    }
  }
  (p->e).subStateTimer++;
}

// SERPFLAG_UNK_4 を立てて陸の上を行き先へ這い進み, ときどき向き直りへ移る, unk_d4c が尽きたら副状態 15 へ移る
// 残差は乱数を引く所で乱数表の番地を置くレジスタ (r1 / r2) だけ (439/439命令), 試済: 入れ子の if, (u8) / & 0xFF の比較
NON_MATCH void FUN_0818cfb8(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    if (!Serpent_TestFlags(q, SERPFLAG_UNK_4)) {
      WorldPos pos;

      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Serpent_ResetWave(p);
      Serpent_HideLiveSegmentsFrom(q, 0);
      (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
      (p->e).mover.pos.y = (p->e).floorY - 256;
      Serpent_SetAllSegmentsPos(q, &(p->e).mover.pos);
      SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
      Serpent_ClearFlags(q, SERPFLAG_UNK_2);
      pos = (p->e).mover.pos;
      pos.y = (p->e).floorY;
      Serpent_SprayBubbles(&pos, 2, (p->e).mover.angle, FALSE);
      q->unk_d44 = (p->e).mover.pos;
      q->unk_d4c = q->unk_d54;
      Serpent_SetFlags(q, SERPFLAG_UNK_4);
      if (!Serpent_TestFlags(q, SERPFLAG_UNK_15)) {
        PlaySound_082406e0(SONG_997);
        Serpent_SetFlags(q, SERPFLAG_UNK_15);
      }
    }
  }
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Vec3 d;

    Serpent_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    if ((Random() & 0xFF) < 64 && abs(Serpent_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
      Enemy_ResetState(&p->e, 0, 0, 1);
      return;
    }
  }
  Serpent_AdvanceSwayIfMoving(p, speed);
  Serpent_PullSegments(p, 20, 12, 0x4000);
  Serpent_UpdateWave(p, 120, 10);
  Serpent_HideLiveSegmentsFrom(q, 0);
  if (Mod((p->e).subStateTimer, 4) == 0) {
    Serpent_SpawnSplashes(p);
  }
  if (Serpent_TryHearNoise(p)) {
    return;
  }
  if (q->unk_d4c == 0) {
    Enemy_ResetState(&p->e, 0, 0, 15);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_4);
  } else {
    q->unk_d4c--;
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_0818cfb8.inc");
#endif
}

// プレイヤーの方を向いて泡を立てながら水中から跳び出し, 上昇が止まったら副状態 (0, 2, 1) へ移る
void Serpent_SubLeapOut(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3 pos;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).mover.angle = (p->e).playerAngle;
    Serpent_FindWaterEdge(p, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_2);
    (p->e).jumpVel.y = 42;
    (p->e).heightAboveFloor = 0;
    pos = (p->e).mover.pos;
    pos.y = (p->e).floorY - 2024;
    Serpent_SetAllSegmentsPos(q, &pos);
    Serpent_SpawnBubble(&(p->e).mover.pos, (p->e).floorY);
    PlaySound_082406e0(SONG_414);
    sound_08240740(SONG_997);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_15);
    Serpent_SetSegmentsSunk(p, 0, 6, FALSE);
    SET_FLAGS(q->flags, SERPFLAG_UNK_13);
  }
  if ((p->e).jumpVel.y <= 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    if ((p->e).unk_1ca == 0 || Mod((p->e).unk_1ca, 5) == 0) {
      Serpent_SpawnSegmentSplashes(p, 3);
    }
    Serpent_PullSegments(p, 4, 8, 0x1000);
    Serpent_UpdateSegmentsBuried(q);
    Serpent_HideLiveSegmentsFrom(q, 4);
    (p->e).subStateTimer++;
  }
}

// 尾の方の節を沈めたまま水面から跳ね上がり, 着地したら次の行き先へ向きを変える
// 249/254命令, 原典は &floorY をスタックに退避し diveCount / swimTimer の 0 を呼び出しの前から r8 / r9 に持つ, 試済: flags2 の直書き, diff ローカル
NON_MATCH void FUN_0818d5b0(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3 pos;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).mover.pos.y = (p->e).floorY;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_2);
    (p->e).jumpVel.y = 32;
    (p->e).heightAboveFloor = 0;
    (p->e).unk_1bc = 0;
    pos = (p->e).mover.pos;
    pos.y = (p->e).floorY - 2024;
    Serpent_SetAllSegmentsPos(q, &pos);
    sound_08240740(SONG_997);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_15);
    Serpent_SetSegmentsSunk(p, 2, 6, TRUE);
  }
  Serpent_PullSegments(p, 6, 6, 0x1000);
  Serpent_UpdateSegmentsBuried(q);
  if ((p->e).flags2 & ENEFLAG2_UNK_4) {
    Vec3 d;
    s32 diff;

    (p->e).flags2 |= ENEFLAG2_UNK_20;
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_4);
    Serpent_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    q->diveCount = 0;
    q->swimTimer = 0;
    diff = Serpent_AngleDiff((p->e).unk_1dc, (p->e).mover.angle);
    if (abs(diff) > 32) {
      Enemy_ResetState(&p->e, 0, 0, 1);
    } else {
      Enemy_ResetState(&p->e, 0, 0, 2);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_0818d5b0.inc");
#endif
}

// 水面の近くで周りをうろつき, 300 フレームを過ぎたら次の行き先を選んで向き直りか泳ぎ (弱っていない時はたまに副状態 17) へ移る
// 残差は乱数を引く所で乱数表の番地を置くレジスタ (r1/r5) と &flags2 の定数レジスタの4か所だけ (540/540), SubLeapAcross, FUN_0818cfb8 と同じ形, 試済: Random の文式マクロ/RandomNext/% 256/(u8) 返し inline, 先の RandomNext を Random に, Enemy_ClearFlag2, d の宣言位置
NON_MATCH void Serpent_SubWander(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  s32 angle, diff;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->wanderTarget = (p->e).mover.pos;
    q->wanderBase = (p->e).mover.pos;
    q->wanderTarget.x += (RandomNext() & 0x7F) - 64;
    q->wanderTarget.z += (RandomNext() & 0x7F) - 64;
    q->unk_d42 = (p->e).mover.angle;
    q->wanderTimer = 60;
    Enemy_EnterState(&p->e, FUN_0818a604, ES_UNK_39);
    Serpent_ClearFlags(q, SERPFLAG_UNK_6);
    sound_08240740(SONG_997);
    Serpent_ClearFlags(q, SERPFLAG_UNK_15);
  }
  (p->e).mover.delta.x += Div(q->wanderTarget.x - (p->e).mover.pos.x, q->wanderTimer);
  (p->e).mover.delta.z += Div(q->wanderTarget.z - (p->e).mover.pos.z, q->wanderTimer);
  angle = ArcTan2_8((p->e).mover.delta.x, (p->e).mover.delta.z);
  diff = Serpent_AngleDiff(angle, (p->e).mover.angle);
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
  if ((p->e).subStateTimer > 300) {
    if ((p->e).unk_546 >= (p->e).hp) {
      if ((Random() & 0xFF) < 48) {
        Vec3 d;

        CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
        Serpent_PickNextTile(p);
        Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
        (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
        q->diveCount = 0;
        if (abs(Serpent_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
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
      Serpent_PickNextTile(p);
      Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
      (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
      q->diveCount = 0;
      q->swimTimer = 0;
      if (abs(Serpent_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
        Enemy_ResetState(&p->e, 0, 0, 1);
      } else {
        Enemy_ResetState(&p->e, 0, 0, 2);
      }
    } else {
      Enemy_ResetState(&p->e, 0, 0, 17);
    }
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Serpent_SubWander.inc");
#endif
}

void FUN_0818dd0c(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_2);
    (p->e).jumpVel.y = -64;
    (p->e).unk_1bc = 0;
    Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_20);
    sound_08240740(SONG_997);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_15);
  }
  Serpent_PullSegments(p, 6, 12, 0xFFFF);
  Serpent_UpdateSegmentsBuried(q);
  if (Enemy_GetFlag2(&p->e, ENEFLAG2_UNK_4)) {
    (p->e).s->aux.spr.flags |= SPRFLAG_HIDDEN;
    Enemy_ResetState(&p->e, 0, 0, 13);
  }
  (p->e).subStateTimer++;
}

// 決まった位置の水中からプレイヤーの方へ跳び出して '.d' のスクリプトを流し, 節を順に跳ね上げ, 上昇が止まったら副状態 21 へ移る
// 原典はパレット番号 plttBase + variant を枝の前に1度だけ作り, &flags5 と &q->flags を r8 / r5 に持つ, 試済: パレットを inline に (341/345 まで寄る), q のフラグを Serpent_ClearFlags, flags5 の直書き
NON_MATCH void FUN_0818de20(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  s32 i;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3 d;

    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).mover.pos.x = 1152;
    (p->e).mover.pos.y = -1024;
    (p->e).mover.pos.z = 384;
    (p->e).s->aux.spr.pos = (p->e).mover.pos;
    Serpent_SetAllSegmentsPos(q, &(p->e).mover.pos);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Serpent_ClearFlags(q, SERPFLAG_UNK_2);
    if ((p->e).spriteKind == 0) {
      Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + (p->e).variant);
    } else {
      (p->e).s->main.spr.pltt = &gObjPlttData[((p->e).plttBase + (p->e).variant) * 16];
    }
    Serpent_ClearFlags(q, SERPFLAG_FADING);
    Serpent_SetSegmentsSunk(p, 0, 6, FALSE);
    Vec3_Delta(&d, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    (p->e).mover.angle = ArcTan2_8(d.x, d.z);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).mover.angle, 22);
    (p->e).jumpVel.y = 48;
    (p->e).heightAboveFloor = 0;
    (p->e).unk_1bc = 0;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Serpent_RunScript(p);
    Serpent_SpawnBubble(&(p->e).mover.pos, (p->e).floorY);
    PlaySound_082406e0(SONG_999);
    sound_08240740(SONG_997);
    Serpent_ClearFlags(q, SERPFLAG_UNK_15);
    return;
  }
  if ((p->e).subStateTimer < 10) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 16;
    for (i = 0; i < 3; i++) {
      Serpent_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 20) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 32;
    for (i = 0; i < 6; i++) {
      Serpent_SetSegmentVelocity(p, &v, i);
    }
  } else if ((p->e).subStateTimer < 60) {
    Vec3 v;

    Vec3_Clear(&v);
    v.y = 64;
    for (i = 0; i < 6; i++) {
      Serpent_SetSegmentVelocity(p, &v, i);
    }
  }
  Serpent_PullSegments(p, 6, 12, 0x1000);
  if ((p->e).mover.pos.y >= (p->e).floorY) {
    (p->e).s->aux.spr.flags &= ~SPRFLAG_HIDDEN;
  }
  Serpent_UpdateSegmentsBuried(q);
  if ((p->e).jumpVel.y <= 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Enemy_ResetState(&p->e, 0, 0, 21);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_0818de20.inc");
#endif
}

// 尾から節を1つずつ壊していき, 100 フレームで Serpent_StateDying へ移る
void Serpent_SubDying(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_2);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    return;
  }
  switch ((p->e).subStateTimer) {
    case 10: {
      PlaySound_082406e0(SONG_423);
    }
    case 30:
    case 50:
    case 70:
    case 80:
    case 90:
    case 95:
    case 100: {
      Serpent_DestroyTailSegment(p);
      break;
    }
  }
  if ((p->e).subStateTimer == 25) {
    PlaySound_082406e0(SE_BLOCK_COLLISION);
  }
  Serpent_PullSegments(p, 6, 12, 12000);
  if ((p->e).subStateTimer > 100) {
    Enemy_EnterState(&p->e, Serpent_StateDying, ES_DYING);
    Enemy_ResetState(&p->e, 3, 0, 0);
  } else {
    (p->e).subStateTimer++;
  }
}

void Serpent_SetHandlerTable2(Serpent* p) { (p->e).handlerTables[2] = (void*)sSerpentHandlerTable2; }

// 届いたダメージ量を damageAccum に足す
void Serpent_OnDamageMsg(Serpent* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && !Serpent_TestFlags((p->e).owner, SERPFLAG_DYING)) {
    ((Serpent*)(p->e).owner)->damageAccum += *msg;
  }
}

// 溜まったダメージを hp から引いてゲージを出し, 尽きたら SERPFLAG_DYING を立てて倒れる状態へ移す
void Serpent_ApplyDamage(Serpent* p) {
  if (!Enemy_IsDead(&p->e)) {
    Serpent* q = (p->e).owner;

    if (!Serpent_TestFlags(q, SERPFLAG_DYING)) {
      if (q->damageAccum != 0 || (p->e).unk_48a != 0) {
        (p->e).hp -= q->damageAccum;
        if ((p->e).hp - (p->e).unk_48a <= 0) {
          (p->e).hurtbox.damage = 0;
          (p->e).hurtbox.hitResult = 0;
          (p->e).unk_48c = 0;
          (p->e).unk_48a = 0;
          (p->e).unk_4be = 0;
          (p->e).hp = 1;
          Serpent_SetFlags((p->e).owner, SERPFLAG_DYING);
          if (!Serpent_TestFlags(q, SERPFLAG_UNK_2)) {
            if (Serpent_TestFlags(q, SERPFLAG_UNK_13)) {
              Enemy_EnterState(&p->e, FUN_0818a47c, ES_UNK_42);
              Enemy_ResetState(&p->e, 0, 2, 2);
              SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
            } else {
              Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
              Enemy_ResetState(&p->e, 0, 0, 13);
            }
          }
          HUD_ShowEnemyGauge((p->e).mover.id, 0, (p->e).maxHp, (p->e).unk_25a, 0);
          FUN_080df478();
        } else {
          HUD_ShowEnemyGauge((p->e).mover.id, (p->e).hp, (p->e).maxHp, (p->e).unk_25a, 0);
        }
      }
      q->damageAccum = 0;
      (p->e).hurtbox.damage = 0;
    }
  }
}

// 今のタイルから dir の向きの隣が水 (TATTR_FALLDEATH) で床との高さの差が小さければその索引を, そうでなければ -1 を返す
s32 Serpent_CheckStep(Serpent* p, s32 dir) {
  s32 next;
  s32 nextStairs, curStairs;
  TileAttr attr;
  WorldPos pos;
  s32 diff;

  switch (dir) {
    case 0: {
      next = (p->e).tileIdx + 1;
      break;
    }
    case 1: {
      next = (p->e).tileIdx + gCollisionMap->tiledata->width;
      break;
    }
    case 2: {
      next = (p->e).tileIdx - 1;
      break;
    }
    case 3: {
      next = (p->e).tileIdx - gCollisionMap->tiledata->width;
      break;
    }
    default: {
      next = (p->e).tileIdx;
      break;
    }
  }
  nextStairs = TileAtIndex(next)->heightStairs >> 4;
  curStairs = TileAtIndex((p->e).tileIdx)->heightStairs >> 4;
  attr = TileAtIndex(next)->attr;
  TilePosAtIndex(&pos, next);
  diff = TileHeightAtIndex(next, &pos) - (p->e).floorY;
  if (!(attr & TATTR_FALLDEATH)) {
    return -1;
  }
  if (diff != 0 && abs(diff) > 254) {
    return -1;
  }
  return next;
}

void Serpent_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *variant = 8 - dir;
    *xflip = 1;
  } else {
    *variant = dir;
    *xflip = 0;
  }
}

// 4 方向の隣の水場のタイルから最近通っていないものを行き先にする, 無ければ乱数で選ぶか真っすぐ進むか unk_f45 の逆へ (陸でも) 向かう
// 776/802命令の下書き, Salamander_PickNextTile と同じ壁 (原典は sp を 0x40 使い段差判定の値を sp に置く, 4 方向のループは降順の数え), 1回目の下書きで切り上げ
NON_MATCH void Serpent_PickNextTile(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
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
  if (q->unk_f44 == 4) {
    dir = (facing + 1) & 3;
  } else if (q->unk_f44 == 5) {
    dir = (facing + Random()) & 3;
  } else {
    dir = facing;
  }
  if (q->unk_f44 > 16) {
    q->unk_f45 = (((p->e).playerAngle + 0x20) & 0xFF) >> 6;
    q->unk_f44 = 0;
  }
  for (i = 0; i < 4; i++) {
    if (abs(dir - q->unk_f45) != 2 && abs(dir - facing) != 2) {
      tile = Serpent_CheckStep(p, dir);
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
      if (!Serpent_IsRecentTile(p, cands[i])) {
        TilePosAtIndex(&agent->dest, cands[i]);
        Serpent_AddRecentTile(p, cands[i]);
        q->unk_f44++;
        q->unk_f40 = 40;
        return;
      }
    }
    i = Mod(Random(), n);
    TilePosAtIndex(&agent->dest, cands[i]);
    Serpent_AddRecentTile(p, cands[i]);
    q->unk_f44++;
    q->unk_f40 = 40;
  } else if (straight != -1 && !Serpent_IsRecentTile(p, straight)) {
    TilePosAtIndex(&agent->dest, straight);
    Serpent_AddRecentTile(p, straight);
    q->unk_f44 += 8;
    q->unk_f40 = 40;
  } else {
    s32 next;
    s32 nextStairs, curStairs;
    TileAttr attr;
    WorldPos pos;
    s32 nextHeight, curHeight, diff, step;

    dir = (q->unk_f45 + 2) & 3;
    switch (dir) {
      case 0: {
        next = (p->e).tileIdx + 1;
        break;
      }
      case 1: {
        next = (p->e).tileIdx + gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        next = (p->e).tileIdx - 1;
        break;
      }
      case 3: {
        next = (p->e).tileIdx - gCollisionMap->tiledata->width;
        break;
      }
      default: {
        next = (p->e).tileIdx;
        break;
      }
    }
    nextStairs = TileAtIndex(next)->heightStairs >> 4;
    curStairs = TileAtIndex((p->e).tileIdx)->heightStairs >> 4;
    attr = TileAtIndex(next)->attr;
    TilePosAtIndex(&pos, next);
    nextHeight = TileHeightAtIndex(next, &pos);
    TilePosAtIndex(&pos, (p->e).tileIdx);
    curHeight = TileHeightAtIndex((p->e).tileIdx, &pos);
    diff = nextHeight - curHeight;
    step = (((curHeight + 0xFF) >> 8) - ((nextHeight + 0xFF) >> 8)) << 8;
    tile = -1;
    if (!(attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
      tile = next;
      if (diff != 0) {
        if (nextStairs == STAIRS_VERTICAL) {
          if (dir == 1) {
            if (step != (curStairs == STAIRS_VERTICAL ? 256 : 0)) {
              tile = -1;
            }
          } else if (dir == 3) {
            if (step != -256) {
              tile = -1;
            }
          } else {
            tile = -1;
          }
        } else if (nextStairs == STAIRS_HORIZONTAL) {
          if (dir == 0) {
            if (step != (curStairs == STAIRS_HORIZONTAL ? 256 : 0)) {
              tile = -1;
            }
          } else if (dir == 2) {
            if (step != -256) {
              tile = -1;
            }
          } else {
            tile = -1;
          }
        }
        if (curStairs == STAIRS_VERTICAL) {
          if (dir == 1) {
            if (step != 256) {
              tile = -1;
            }
          } else if (dir == 3) {
            if (step != (nextStairs == STAIRS_VERTICAL ? -256 : 0)) {
              tile = -1;
            }
          } else {
            tile = -1;
          }
        } else if (curStairs == STAIRS_HORIZONTAL) {
          if (dir == 0) {
            if (step != 256) {
              tile = -1;
            }
          } else if (dir == 2) {
            if (step != (nextStairs == STAIRS_HORIZONTAL ? -256 : 0)) {
              tile = -1;
            }
          } else {
            tile = -1;
          }
        }
        if ((curStairs == STAIRS_HORIZONTAL && nextStairs == STAIRS_HORIZONTAL) || (curStairs == STAIRS_VERTICAL && nextStairs == STAIRS_VERTICAL)) {
          if (abs(diff) > 256) {
            tile = -1;
          }
        } else if (abs(diff) > 255) {
          tile = -1;
        }
      }
    }
    if (tile >= 0) {
      TilePosAtIndex(&agent->dest, tile);
      Serpent_AddRecentTile(p, tile);
      q->unk_f44 += 2;
      q->unk_f40 = 40;
    } else {
      q->unk_f45 = (q->unk_f45 + 1) & 3;
    }
  }
#else
  INCFUNC("asm/func/Serpent_PickNextTile.inc");
#endif
}

// 12 フレームごとに尾へ中の節, 中へ頭の節, 頭へ pos の位置を送る
void Serpent_ShiftKeySegments(Serpent* p, Vec3* pos) {
  Serpent* q = (p->e).owner;

  if (q->shiftTimer != 0) {
    q->shiftTimer--;
  } else {
    q->shiftTimer = 12;
    Serpent_SetSegmentPos(q, q->segmentCount - 1, &q->segments[q->segmentCount >> 1].sprite.pos);
    Serpent_SetSegmentPos(q, q->segmentCount >> 1, &q->segments[0].sprite.pos);
    Serpent_SetSegmentPos(q, 0, pos);
  }
}

// 節を6つ作り, スプライトとアニメを載せる, 尾は anim 11, それより前は anim 6 を cmdIdx を 0..3 でずらして流す
void Serpent_InitSegments(Serpent* p, SpriteID32 sprID, u32 animFID, u32 angle) {
  Serpent* q = (p->e).owner;
  s32 n;
  s32 cmdIdx;
  s32 i;

  q->segmentCount = 6;
  q->segmentsLeft = q->segmentCount;
  q->unk_f48 = 0x7FFFFFFF;
  q->hpPerSegment = Div((p->e).hp, q->segmentCount + 1);
  n = 0;
  cmdIdx = 0;
  for (i = 0; i < q->segmentCount; i++) {
    SerpentSegment* seg = &q->segments[i];
    u32 variant, xflip;

    Video_GetAuxSprite(&seg->gfx, sprID);
    AuxSprite_Add(&seg->sprite, &seg->gfx, 0);
    Video_SetAuxSpritePltt(&seg->gfx, 419);
    seg->angle = angle;
    seg->animFile = GetFile(DIR_ANIMATION, animFID);
    Serpent_GetAnimVariant(seg->angle, &variant, &xflip);
    if (i == q->segmentCount - 1) {
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 11, variant, xflip);
      SET_FLAGS(seg->flags, SERPSEGFLAG_UNK_2);
    } else {
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 6, variant, xflip);
      seg->anim.cmdIdx = cmdIdx;
      if (++cmdIdx > 3) {
        cmdIdx = 0;
      }
    }
    seg->owner = q;
    seg->unk_120 = 0;
    if (n == 0) {
      seg->wobbleAngle = i * 24;
      SET_FLAGS(seg->flags, SERPSEGFLAG_FOLLOW);
    } else {
      n++;
    }
  }
}

// 壊れていない節を床より下なら隠し上なら出す, 全部上なら 1, 全部下なら -1, 混ざっていれば 0 を返す
// 179/166命令, Salamander_UpdateSegmentsBuried と同じ壁 (原典は i を sp に置き座標と flags を誘導変数で持つ), 1回目の下書きで切り上げ
NON_MATCH s32 Serpent_UpdateSegmentsBuried(Serpent* p) {
#ifdef NONMATCHING_C
  s32 n = 0;
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_DESTROYED)) {
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
  INCFUNC("asm/func/Serpent_UpdateSegmentsBuried.inc");
#endif
}

// idx 番から後ろの壊れていない節を隠す
void Serpent_HideLiveSegmentsFrom(Serpent* p, s32 idx) {
  s32 i;

  for (i = idx; i < p->segmentCount; i++) {
    if (!Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_DESTROYED)) {
      SET_FLAGS(p->segments[i].sprite.flags, SPRFLAG_HIDDEN);
    }
  }
}

// Serpent_AnimateSegments と同じ処理
void Serpent_AnimateSegments2(Serpent* p, s32 idx) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_DESTROYED)) {
      u32 variant, flags;

      Serpent_GetAnimVariant(p->segments[i].angle, &variant, &flags);
      if (Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_UNK_2)) {
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, 11, variant, flags);
      } else {
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, flags);
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

// 壊れていない節に向きに合わせた animTable[idx] (SERPSEGFLAG_UNK_2 なら 11 番) を流して1コマ送る
void Serpent_AnimateSegments(Serpent* p, s32 idx) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_DESTROYED)) {
      u32 variant, flags;

      Serpent_GetAnimVariant(p->segments[i].angle, &variant, &flags);
      if (Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_UNK_2)) {
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, 11, variant, flags);
      } else {
        AuxAnim_SetAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, flags);
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

// 壊れていない節を timer が 10 から点滅させ 30 で消す
void Serpent_BlinkSegments(Serpent* p, s32 timer) {
  Serpent* q = (p->e).owner;
  SerpentSegment* segs = q->segments;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Serpent_TestSegmentFlags(&segs[i], SERPSEGFLAG_DESTROYED)) {
      Sprite_UpdateVanishBlink(&segs[i].sprite.flags, timer, 10, 30);
    }
  }
}

// 壊れていない節に animTable[idx] (SERPSEGFLAG_UNK_2 なら 11 番) を variant と flags で頭から流し直して1コマ送る
void Serpent_RestartSegmentAnims(Serpent* p, s32 idx, s32 variant, s32 flags) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (!Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_DESTROYED)) {
      if (Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_UNK_2)) {
        AuxAnim_RestartAnim(&p->segments[i].anim, p->segments[i].animFile, 11, variant, flags);
      } else {
        AuxAnim_RestartAnim(&p->segments[i].anim, p->segments[i].animFile, (p->e).animTable[idx].anim, variant, flags);
      }
      AuxSprite_AdvanceAnim(&p->segments[i].sprite, &p->segments[i].anim);
    }
  }
}

void Serpent_HideDestroyedSegments(Serpent* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    if (Serpent_TestSegmentFlags(&p->segments[i], SERPSEGFLAG_DESTROYED)) {
      p->segments[i].sprite.flags = SPRFLAG_HIDDEN;
    }
  }
}

void Serpent_RemoveSegmentSprites(Serpent* p) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    AuxSprite_Remove(&p->segments[i].sprite);
  }
}

void Serpent_SetSegmentPos(Serpent* p, s32 idx, Vec3* pos) { p->segments[idx].sprite.pos = *pos; }

// 壊れていない節を1つ前の節 (先頭は頭) の方へ向ける
void Serpent_FaceSegmentsForward(Serpent* p) {
  Serpent* q = (p->e).owner;
  Vec3 diff;
  Vec3 prev = (p->e).mover.pos;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (!Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
      Vec3_Diff(&diff, &prev, &q->segments[i].sprite.pos);
      q->segments[i].angle = ArcTan2_8(diff.x, diff.z);
      prev = q->segments[i].sprite.pos;
    }
  }
}

void Serpent_ResetWave(Serpent* p) {
  Serpent* q = (p->e).owner;

  q->waveOffset = 0;
  q->waveDir = 1;
}

void Serpent_UpdateWave(Serpent* p, s32 amplitude, s32 speed) {
  Serpent* q = (p->e).owner;

  if (q->waveOffset >= amplitude) {
    q->waveOffset = amplitude;
    q->waveDir = -1;
  } else if (q->waveOffset <= -amplitude) {
    q->waveOffset = -amplitude;
    q->waveDir = 1;
  }
  q->waveOffset += q->waveDir * speed;
}

void Serpent_InitFollowInterval(Serpent* p) { ((Serpent*)(p->e).owner)->followInterval = 1; }

// followInterval フレームごとに, 前の節を追う節の targetPos を1つ前の節の位置 (先頭は頭) に送る
void Serpent_FollowSegments(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Mod((p->e).unk_1ca, q->followInterval) == 0) {
    Vec3 prev = (p->e).s->aux.spr.pos;
    s32 i;

    for (i = 0; i < q->segmentCount; i++) {
      if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
        Vec3 cur = q->segments[i].sprite.pos;

        q->segments[i].targetPos = prev;
        prev = cur;
      }
    }
  }
}

void Serpent_SetSegmentVelocity(Serpent* p, Vec3* velocity, s32 idx) {
  Serpent* q = (p->e).owner;

  if (Serpent_TestSegmentFlags(&q->segments[idx], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[idx], SERPSEGFLAG_DESTROYED)) {
    q->segments[idx].velocity = *velocity;
  }
}

void Serpent_WobbleSegments(Serpent* p, s32 amplitude, s32 step, s32 horizontal) {
  Serpent* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
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
// 207/209命令, Salamander_PlaceSegmentsOnCurve と同じ Hermite 曲線の壁, 1回目の下書きで切り上げ
NON_MATCH void Serpent_PlaceSegmentsOnCurve(Serpent* p, Vec3* startPos, Vec3* endPos, s32 first, s32 last) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
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
    Serpent_SetSegmentPos(q, i, &pos);
  }
#else
  INCFUNC("asm/func/Serpent_PlaceSegmentsOnCurve.inc");
#endif
}

// unk_eca が 0 なら節を targetPos へ 1/followDiv ずつ寄せ, 頭から順に離れすぎた節を 1/linkDiv ずつ引き寄せる, 0 でなければ unk_eca 番の節から頭の方へ逆に引き寄せて頭も動かす
// 407/405命令, 残差は最初の if を飛ばす枝が2つめの if を素通りして else へ直に飛ぶ (原典は unk_eca の番地を r2 に持って飛ばない) だけ, 試済: 2つめの if の向きを逆に, unk_eca をポインタで読む
NON_MATCH void Serpent_PullSegments(Serpent* p, s32 followDiv, s32 linkDiv, s32 followDistSq) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  Vec3 d1, d2, prev, d3;
  s32 i;

  if (q->unk_eca == 0) {
    prev = (p->e).s->aux.spr.pos;
    for (i = 0; i < q->segmentCount; i++) {
      if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
        Vec3_Diff(&d1, &q->segments[i].targetPos, &q->segments[i].sprite.pos);
        if (d1.x * d1.x + d1.y * d1.y + d1.z * d1.z > followDistSq) {
          followDiv = followDiv >= 1 ? followDiv : 1;
          q->segments[i].sprite.pos.x += Div(d1.x, followDiv);
          q->segments[i].sprite.pos.y += Div(d1.y, followDiv);
          q->segments[i].sprite.pos.z += Div(d1.z, followDiv);
        }
      }
    }
  }
  if (q->unk_eca == 0) {
    prev = (p->e).s->aux.spr.pos;
    for (i = 0; i < q->segmentCount; i++) {
      Vec3_Diff(&d2, &prev, &q->segments[i].sprite.pos);
      if (d2.x * d2.x + d2.y * d2.y + d2.z * d2.z > 12724) {
        q->segments[i].sprite.pos.x += Div(d2.x, linkDiv);
        q->segments[i].sprite.pos.y += Div(d2.y, linkDiv);
        q->segments[i].sprite.pos.z += Div(d2.z, linkDiv);
      }
      prev = q->segments[i].sprite.pos;
    }
  } else {
    prev = q->segments[q->unk_eca].sprite.pos;
    for (i = q->unk_eca - 1; i >= 0; i--) {
      Vec3_Diff(&d3, &prev, &q->segments[i].sprite.pos);
      if (d3.x * d3.x + d3.y * d3.y + d3.z * d3.z > 12724) {
        q->segments[i].sprite.pos.x += Div(d3.x, linkDiv);
        q->segments[i].sprite.pos.y += Div(d3.y, linkDiv);
        q->segments[i].sprite.pos.z += Div(d3.z, linkDiv);
      }
      prev = q->segments[i].sprite.pos;
    }
    Vec3_Diff(&d3, &prev, &(p->e).mover.pos);
    if (d3.x * d3.x + d3.y * d3.y + d3.z * d3.z > 12724) {
      (p->e).mover.delta.x += Div(d3.x, linkDiv);
      (p->e).heightAboveFloor += Div(d3.y, linkDiv);
      (p->e).mover.delta.z += Div(d3.z, linkDiv);
    }
  }
  Serpent_FaceSegmentsForward(p);
#else
  INCFUNC("asm/func/Serpent_PullSegments.inc");
#endif
}

void Serpent_SetAllSegmentsPos(Serpent* p, Vec3* pos) {
  s32 i;

  for (i = 0; i < p->segmentCount; i++) {
    p->segments[i].sprite.pos = *pos;
    p->segments[i].targetPos = *pos;
  }
}

void Serpent_InitHitboxes(Serpent* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 128, 128, 128);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Serpent_OnHurt, p);
  VEC3_SET(hitSize, 82, 256, 82);
  VEC3_SET(hitOffset, 0, 0, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Serpent_OnHit, 0, p);
  Hitbox_SetFlags(&(p->e).hitbox, HBF_ONCE);
}

void Serpent_OnReset(Serpent* p) {
  Serpent* q = (p->e).owner;

  q->flags &= (u16)~SERPFLAG_UNK_1;
  q->blockedTimer = 0;
  q->turnTileIdx = 0;
  q->unk_f45 = Random() & 3;
  q->hoverPhase = 0;
  Enemy_SetSpritePos(&p->e, &q->homePos);
  (p->e).mover.pos = q->homePos;
  Serpent_ResetRecentTiles(p);
  Serpent_SetAllSegmentsPos(q, &(p->e).mover.pos);
  Serpent_PickNextTile(p);
  ClearMemory((p->e).pathNodePos, 8);
  Enemy_ResetState(&p->e, 0, 0, 2);
  Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
}

// 頭と奇数番目の節を sin で揺らし, 偶数番目の節を前後の位置の中ほどに置く
// Salamander_SwayBody と同じ Hermite 曲線の壁, 1回目の下書きで切り上げ
NON_MATCH void Serpent_SwayBody(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
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
    Serpent_SetSegmentPos(q, i, &pos);
    prev = q->segments[i + 1].sprite.pos;
  }
#else
  INCFUNC("asm/func/Serpent_SwayBody.inc");
#endif
}

// SERPSEGFLAG_DESTROYED が落ちている節の1つおきに SERPSEGFLAG_FOLLOW を落とす
// 56/49命令, 原典は &segments[0].flags を1本だけ持って進め q->segments の基点を作らない, 試済: seg++ / segments[i] / 反復内の seg ローカル / &= 直書き
NON_MATCH void Serpent_UnfollowAlternateSegments(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  SerpentSegment* seg = q->segments;
  s32 n = 0;
  s32 i;

  for (i = 0; i < q->segmentCount; seg++, i++) {
    if (!Serpent_TestSegmentFlags(seg, SERPSEGFLAG_DESTROYED)) {
      if (n == 1) {
        n = 0;
      } else {
        CLEAR_FLAGS(seg->flags, SERPSEGFLAG_FOLLOW);
        n++;
      }
    }
  }
#else
  INCFUNC("asm/func/Serpent_UnfollowAlternateSegments.inc");
#endif
}

// 尾から見て最初の壊れていない節を壊す, 壊せたら TRUE
s32 Serpent_DestroyTailSegment(Serpent* p) {
  Serpent* q = (p->e).owner;
  SerpentSegment* segs = q->segments;
  s32 i;

  for (i = q->segmentCount - 1; i >= 0; i--) {
    if (!Serpent_TestSegmentFlags(&segs[i], SERPSEGFLAG_DESTROYED)) {
      Hitbox_Unregister(&segs[i].hurtbox);
      SET_FLAGS(segs[i].flags, SERPSEGFLAG_DESTROYED);
      q->segmentsLeft--;
      Serpent_EmitSegmentBubbles(p, i, 0);
      return TRUE;
    }
  }
  return FALSE;
}

// 残っている節を尾から全て壊し, 食らい判定を外す
void Serpent_DestroyAllSegments(Serpent* p) {
  Serpent* q = (p->e).owner;
  SerpentSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft != 0) {
    for (i = q->segmentCount - 1; i >= 0; i--) {
      if (!Serpent_TestSegmentFlags(&segs[i], SERPSEGFLAG_DESTROYED)) {
        Hitbox_Unregister(&segs[i].hurtbox);
        SET_FLAGS(segs[i].flags, SERPSEGFLAG_DESTROYED);
        q->segmentsLeft--;
      }
    }
  }
}

// Serpent_DestroyAllSegments と同じ処理, どこからも呼ばれない
void Serpent_DestroyAllSegments2(Serpent* p) {
  Serpent* q = (p->e).owner;
  SerpentSegment* segs = q->segments;
  s32 i;

  if (q->segmentsLeft != 0) {
    for (i = q->segmentCount - 1; i >= 0; i--) {
      if (!Serpent_TestSegmentFlags(&segs[i], SERPSEGFLAG_DESTROYED)) {
        Hitbox_Unregister(&segs[i].hurtbox);
        SET_FLAGS(segs[i].flags, SERPSEGFLAG_DESTROYED);
        q->segmentsLeft--;
      }
    }
  }
}

void Serpent_AdvanceSwayIfMoving(Serpent* p, s32 speed) {
  if (speed != 0) {
    ((Serpent*)(p->e).owner)->swayAngle += 4;
  }
}

// jumpVel が速いほど広い向きの範囲へ, 前の節を追う節をばらばらの向きに速さ 12 で散らす
void Serpent_ScatterSegments(Serpent* p) {
  Serpent* q = (p->e).owner;
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
    if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
      Vec3_SetPolar(&q->segments[i].velocity, Random() & spread, 12);
    }
  }
}

// 前の節を追っている節を床の高さに合わせる, 潜っていれば床へ (深すぎれば頭の高さへ), 浮いていれば差の 1/10 ずつ下げる
// 159/160命令, Salamander_SnapSegmentsToFloor と同じ壁 (原典は節の座標を誘導変数にして p をレジスタに置く), 1回目の下書きで切り上げ
NON_MATCH void Serpent_SnapSegmentsToFloor(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  s32 i;

  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_20)) {
    for (i = 0; i < q->segmentCount; i++) {
      if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
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
  INCFUNC("asm/func/Serpent_SnapSegmentsToFloor.inc");
#endif
}

// 前の節を追う節を velocity だけ動かし, velocity を半分に減らす
void Serpent_ApplySegmentVelocity(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FOLLOW) && !Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
      q->segments[i].sprite.pos.x += q->segments[i].velocity.x;
      q->segments[i].sprite.pos.y += q->segments[i].velocity.y;
      q->segments[i].sprite.pos.z += q->segments[i].velocity.z;
      q->segments[i].velocity.x = FixToInt(1, q->segments[i].velocity.x);
      q->segments[i].velocity.y = FixToInt(1, q->segments[i].velocity.y);
      q->segments[i].velocity.z = FixToInt(1, q->segments[i].velocity.z);
    }
  }
}

void FUN_08190c00(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Serpent_TestFlags(q, SERPFLAG_UNK_1)) {
    Enemy_ResetState(&p->e, 0, 0, 4);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    (p->e).unk_544 = 180;
    (p->e).unk_1bc = 2;
  }
  CLEAR_FLAGS(q->flags, SERPFLAG_UNK_1);
}

// 節が受けたダメージを damageAccum に足してダメージ数字を出す
void Serpent_OnSegmentDamaged(Serpent* p, Hitbox* hitbox, SerpentSegment* seg) {
  if (!Enemy_IsDead(&p->e) && !Serpent_TestFlags((p->e).owner, SERPFLAG_DYING)) {
    Vec3 v;

    ((Serpent*)(p->e).owner)->damageAccum += hitbox->damage;
    Vec3_Clear(&v);
    CreateDamageNumber(hitbox, hitbox->damage, 0, &seg->sprite.pos, &v, 1);
  }
}

void Serpent_OnSegmentHit(Hitbox* a, Hitbox* b, SerpentSegment* seg) {}

// 節の食らい判定に当たったとき, ダメージを足して白く光らせ, 弱点に当たっていれば当たった向きに煙を出す
// 234/237命令, 原典は seg を下位レジスタ, &q->flags を r8 に置き乱数の番地を3回ぶん持ち越す (乱数3回の壁), 試済: フラグの inline, 早期 return
NON_MATCH void Serpent_OnSegmentHurt(Hitbox* a, Hitbox* b, SerpentSegment* seg) {
#ifdef NONMATCHING_C
  Serpent* q = seg->owner;

  if (!Enemy_IsDead(&q->e) && !Serpent_TestFlags(q, SERPFLAG_DYING) && seg->hurtbox.iframes == 0) {
    Hitbox_ApplyDamage(a, b);
    b->iframes = a->iframes;
    Serpent_OnSegmentDamaged(q, b, seg);
    a->damage += (q->e).unk_188;
    Serpent_FlashSegment(seg);
    SET_FLAGS(q->flags, SERPFLAG_UNK_6);
    if (Serpent_TestSegmentFlags(seg, SERPSEGFLAG_UNK_2)) {
      PlaySound_082406e0(SONG_993);
    } else {
      PlaySound_082406e0(SE_ENEMY_DAMAGED);
    }
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
  INCFUNC("asm/func/Serpent_OnSegmentHurt.inc");
#endif
}

// unk_f4c の節を knockbackAngle の向きへ弾く
void Serpent_KnockBackSegment(Serpent* p) {
  if (p->unk_f48 != 0x7FFFFFFF) {
    SerpentSegment* seg = p->unk_f4c;

    p->unk_f48 = 0x7FFFFFFF;
    Vec3_SetPolar(&seg->velocity, seg->knockbackAngle, seg->hurtbox.knockback);
  }
}

// 節ごとに食らい判定 (防御力は尾だけ tailDefense) を登録し, 攻撃判定を組む
void Serpent_InitSegmentHitboxes(Serpent* p) {
  Serpent* q = (p->e).owner;
  Vec3 halfSize, offset;
  s32 i;

  VEC3_SET(halfSize, 128, 256, 128);
  VEC3_SET(offset, 0, 256, 0);
  for (i = 0; i < q->segmentCount; i++) {
    SerpentSegment* seg = &q->segments[i];

    Hitbox_Init(&seg->hurtbox, (p->e).mover.id, HBF_HURTBOX | HBF_NPC | HBF_3 | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    if (i == q->segmentCount - 1) {
      Hitbox_SetPowerAndAttributes(&seg->hurtbox, q->tailDefense, (p->e).attrs, (p->e).weakness);
    } else {
      Hitbox_SetPowerAndAttributes(&seg->hurtbox, q->segmentDefense, (p->e).attrs, (p->e).weakness);
    }
    Hitbox_SetPos(&seg->hurtbox, &seg->sprite.pos, 0);
    Hitbox_SetHandler(&seg->hurtbox, Serpent_OnSegmentHurt, seg);
    Hitbox_Register(&seg->hurtbox);
  }
  VEC3_SET(halfSize, 64, 100, 64);
  VEC3_SET(offset, 0, 128, 0);
  for (i = 0; i < q->segmentCount; i++) {
    SerpentSegment* seg = &q->segments[i];

    Hitbox_Init(&seg->hitbox, (p->e).mover.id, HBF_HITBOX | HBF_ONCE | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    Hitbox_SetAttack(&seg->hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    Hitbox_SetPos(&seg->hitbox, &seg->sprite.pos, 0);
    Hitbox_SetHandler(&seg->hitbox, Serpent_OnSegmentHit, seg);
  }
}

void Serpent_InitAnims(Serpent* p) {
  Enemy_SetAnimEntry(&p->e, 14, 8, 0);
  Enemy_SetAnimEntry(&p->e, 18, 12, 0);
  Enemy_SetAnimEntry(&p->e, 17, 8, 0);
  Enemy_SetAnimEntry(&p->e, 15, 9, 0);
  Enemy_SetAnimEntry(&p->e, 16, 11, 0);
}

// 歩きのコマに合わせた速さ, SERPFLAG_UNK_4 で倍, 弱っていればさらに倍
s32 Serpent_GetMoveSpeed(Serpent* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if ((p->e).unk_546 > (p->e).hp) {
    if (Serpent_TestFlags((p->e).owner, SERPFLAG_UNK_4)) {
      return sSerpentMoveSpeeds[anim->cmdIdx & 3] * 4;
    }
  } else if (!Serpent_TestFlags((p->e).owner, SERPFLAG_UNK_4)) {
    return sSerpentMoveSpeeds[anim->cmdIdx & 3];
  }
  return sSerpentMoveSpeeds[anim->cmdIdx & 3] * 2;
}

// 跳ぶ先や進む先のタイルが水場でなければ移動を止め, 30 フレームより長く止まったら次の行き先を選んで向き直る
// 残差は最初の Vec3_Sum で &jumpVel と &mover.pos を作る順の1か所だけ, 試済: 引数順の入れ替え (読む順がずれる), 素の3行, Vec3_Add, pos/vel ローカル, blocked の初期化位置, 捨てる TileAtIndex
NON_MATCH void Serpent_KeepInWater(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  WorldPos next;
  s32 idx;
  u32 attr;
  s32 height;
  bool32 blocked;

  if (Serpent_TestFlags(q, SERPFLAG_DYING | SERPFLAG_UNK_7)) {
    q->blockedTimer = 0;
    return;
  }
  Vec3_Sum(&next, &(p->e).jumpVel, &(p->e).mover.pos);
  idx = GetCollisionTileIdx(&next);
  attr = TileAttrAtIndex(idx);
  height = TileHeightAtIndex(idx, &next);
  blocked = FALSE;
  if ((p->e).floorY < height) {
    (p->e).jumpVel.x = 0;
    (p->e).jumpVel.z = 0;
  }
  if (Serpent_TestFlags(q, SERPFLAG_UNK_2 | SERPFLAG_UNK_13)) {
    q->blockedTimer = 0;
    return;
  }
  Vec3_Sum(&next, &(p->e).jumpVel, &(p->e).mover.pos);
  next.x += (p->e).mover.delta.x;
  idx = GetCollisionTileIdx(&next);
  attr = TileAttrAtIndex(idx);
  height = TileHeightAtIndex(idx, &next);
  if (!(attr & TATTR_FALLDEATH) || height == 0) {
    (p->e).mover.delta.x = 0;
    blocked = TRUE;
  }
  Vec3_Sum(&next, &(p->e).jumpVel, &(p->e).mover.pos);
  next.z += (p->e).mover.delta.z;
  idx = GetCollisionTileIdx(&next);
  attr = TileAttrAtIndex(idx);
  height = TileHeightAtIndex(idx, &next);
  if (!(attr & TATTR_FALLDEATH) || height == 0) {
    (p->e).mover.delta.z = 0;
    blocked = TRUE;
  }
  Vec3_Sum(&next, &(p->e).jumpVel, &(p->e).mover.pos);
  next.x += (p->e).mover.delta.x;
  next.z += (p->e).mover.delta.z;
  idx = GetCollisionTileIdx(&next);
  attr = TileAttrAtIndex(idx);
  height = TileHeightAtIndex(idx, &next);
  if (!(attr & TATTR_FALLDEATH) || height == 0) {
    (p->e).mover.delta.x = 0;
    (p->e).mover.delta.z = 0;
    blocked = TRUE;
  }
  if (blocked) {
    if (++q->blockedTimer > 30) {
      q->unk_f45 = (q->unk_f45 + 1) & 3;
      Serpent_PickNextTile(p);
      Vec3_Delta(&next, &(p->e).mover.pos, &(p->e).navAgent->dest);
      (p->e).unk_1dc = ArcTan2_8(next.x, next.z);
      if (abs(Serpent_AngleDiff((p->e).unk_1dc, (p->e).mover.angle)) > 32) {
        Enemy_ResetState(&p->e, 0, 0, 1);
      }
    }
  } else {
    q->blockedTimer = 0;
  }
#else
  INCFUNC("asm/func/Serpent_KeepInWater.inc");
#endif
}

// interval フレームごとに idx 番の節の前と左右の水面に泡のエフェクトを出す
void Serpent_EmitSegmentBubbles(Serpent* p, s32 idx, s32 interval) {
  Serpent* q = (p->e).owner;

  if (interval == 0 || Mod((p->e).unk_1ca, interval) == 0) {
    WorldPos pos;
    Vec3 v;

    pos = q->segments[idx].sprite.pos;
    Vec3_SetPolar(&v, q->segments[idx].angle, 32);
    pos.x += v.x;
    pos.y = (p->e).floorY;
    pos.z += v.z;
    Entity081ee7a8_SpawnEx(&pos, 12, 8, 6, 12, 4, (q->segments[idx].angle + 0x80) & 0xFF, 8, 50, 2, 2, 0x200, 0, SPR_EFF_F422, ANIM_121B, 0, 0, 0xDA);
    pos = q->segments[idx].sprite.pos;
    Vec3_SetPolar(&v, (q->segments[idx].angle + 0x40) & 0xFF, 32);
    pos.x += v.x;
    pos.y = (p->e).floorY;
    pos.z += v.z;
    Serpent_SprayBubbles(&pos, 2, (p->e).mover.angle, FALSE);
    pos = q->segments[idx].sprite.pos;
    Vec3_SetPolar(&v, (q->segments[idx].angle - 0x40) & 0xFF, 32);
    pos.x += v.x;
    pos.y = (p->e).floorY;
    pos.z += v.z;
    Serpent_SprayBubbles(&pos, 1, (p->e).mover.angle, TRUE);
  }
}

// pos の上 (高さ y) に泡のエフェクトを出す
void Serpent_SpawnBubble(Vec3* pos, s32 y) {
  Vec3 at = *pos;
  Vec3 vel;

  at.y = y;
  at.z += 12;
  Vec3_Clear(&vel);
  Entity081f26bc_Spawn(&at, &vel, SPR_EFF_F422, ANIM_121B, 6, 0, 9, 0xDA, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

// 頭が水の上にいれば, 周りの水面に水しぶきを2つ出す
// 219/225命令, 原典は乱数表の番地をループ外へ出さず毎回読み i をレジスタに置く, 試済: += で足す, pos/tile をループ外で宣言, 宣言順, GetTileAt / TileAttrAtIndex
NON_MATCH void Serpent_SpawnSplashes(Serpent* p) {
#ifdef NONMATCHING_C
  Vec3 vel;
  s32 i;

  Vec3_Clear(&vel);
  for (i = 0; i < 2; i++) {
    WorldPos pos = (p->e).mover.pos;
    s32 tile = GetCollisionTileIdx(&pos);

    pos.x += (Random() & 0x7F) - 0x40;
    pos.y = (TileAtIndex(GetCollisionTileIdx(&pos))->heightStairs & 0xF) << 8;
    pos.z += (Random() & 0x7F) - 0x40;
    vel.x = (Random() & 7) - 4;
    vel.z = (Random() & 7) - 4;
    if (TileAtIndex(tile)->attr & TATTR_FALLDEATH) {
      Entity081f26bc_Spawn(&pos, &vel, SPR_DVALIN_00, ANIM_38E2, 3, i == 0 ? SPRFLAG_BLINK_ODD : SPRFLAG_BLINK_EVEN, 9, 0x23B, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
  }
#else
  INCFUNC("asm/func/Serpent_SpawnSplashes.inc");
#endif
}

// idx 番の節が水の上にいれば, 周りの水面に水しぶきを2つ出す
// 242/244命令, Serpent_SpawnSplashes と同じ残差 (原典は乱数表の番地をループ外へ出さず i をレジスタに置く), 1回目の下書きで切り上げ
NON_MATCH void Serpent_SpawnSegmentSplashes(Serpent* p, s32 idx) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  Vec3 vel;
  s32 i;

  Vec3_Clear(&vel);
  for (i = 0; i < 2; i++) {
    WorldPos pos = q->segments[idx].sprite.pos;
    s32 tile = GetCollisionTileIdx(&pos);

    pos.x += Mod(Random(), 200) - 100;
    pos.y = (TileAtIndex(GetCollisionTileIdx(&pos))->heightStairs & 0xF) << 8;
    pos.z += Mod(Random(), 200) - 100;
    vel.x = (Random() & 7) - 4;
    vel.z = (Random() & 7) - 4;
    if (TileAtIndex(tile)->attr & TATTR_FALLDEATH) {
      Entity081f26bc_Spawn(&pos, &vel, SPR_DVALIN_00, ANIM_38E2, 3, i == 0 ? SPRFLAG_BLINK_ODD : SPRFLAG_BLINK_EVEN, 9, 0x23B, i == 0 ? 2 : 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
  }
#else
  INCFUNC("asm/func/Serpent_SpawnSegmentSplashes.inc");
#endif
}

// pos から6方向へ煙を出す
void Serpent_EmitSmokeAround(WorldPos* pos) {
  Vec3 size;

  VEC3_SET(size, 80, 60, 60);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0x40, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0x80, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
  EmitSmoke(pos, (RandomNext() & 1) + 1, &size, 0xF0, 4, 20, 2, 1);
}

void Serpent_UpdateAnimSpeed(Serpent* p) {
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

void Serpent_ResetRecentTiles(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    q->recentTiles[i] = (p->e).tileIdx;
  }
  q->recentTileIdx = 0;
}

bool8 Serpent_IsRecentTile(Serpent* p, u32 tileIdx) {
  Serpent* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    if (q->recentTiles[i] == tileIdx) {
      return TRUE;
    }
  }
  return FALSE;
}

void Serpent_AddRecentTile(Serpent* p, u32 tileIdx) {
  Serpent* q = (p->e).owner;

  q->recentTiles[q->recentTileIdx] = tileIdx;
  q->recentTileIdx = (q->recentTileIdx + 1) & 3;
}

void Serpent_OnAttackRequest(Serpent* p) {
  Enemy_ResetState(&p->e, 0, 2, 0);
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
}

void FUN_0819218c(Serpent* p) {}

// 範囲内のプレイヤーが正面の 1/4 にいて高さの差も小さければ, 向きをプレイヤーの方へ決めて TRUE
bool8 Serpent_TryDetectPlayer(Serpent* p) {
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
        Serpent* q = (p->e).owner;

        q->unk_f45 = (((p->e).playerAngle + 0x80) & 0xFF) >> 6;
        q->unk_f44 = 14;
        return TRUE;
      }
    }
  }
  return FALSE;
}

// SERPFLAG_UNK_2 に合わせて攻撃判定の威力を atk の [0] か [1] に切り替える
void Serpent_SelectAttack(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (!Enemy_IsDead(&p->e) && !Serpent_TestFlags(q, SERPFLAG_DYING) && !TEST_FLAGS((p->e).flags3, ENEFLAG3_ASLEEP | ENEFLAG3_STUN | ENEFLAG3_PETRIFIED | ENEFLAG3_UNK_5 | ENEFLAG3_UNK_13 | ENEFLAG3_UNK_15)) {
    if (Serpent_TestFlags(q, SERPFLAG_UNK_2)) {
      Hitbox_ClearFlags(&(p->e).hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      Hitbox_SetFlags(&(p->e).hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&(p->e).hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
}

void FUN_0819235c(Serpent* p) {
  Serpent* q = (p->e).owner;
  SerpentSegment* segs = q->segments;
  s32 n = 0;
  s32 i;

  for (i = 0; i < 6; i++) {
    if (!Serpent_TestSegmentFlags(&segs[i], SERPSEGFLAG_DESTROYED)) {
      if (segs[i].unk_120 != 0) {
        segs[i].unk_120--;
      } else if (n < 2) {
        segs[i].unk_120 = 2;
        SET_FLAGS(segs[i].flags, SERPSEGFLAG_UNK_7);
        n++;
      }
    }
  }
}

// 頭と節の当たり判定を出し入れする, 節の攻撃判定はプレイヤーが近いときだけ載せて SERPFLAG_UNK_2 で atk の [0] / [1] を選ぶ
void Serpent_UpdateHitboxes(Serpent* p) {
  Serpent* q = (p->e).owner;
  Vec3 d;
  s32 i;

  if (Enemy_IsDead(&p->e) || Serpent_TestFlags(q, SERPFLAG_UNK_4 | SERPFLAG_DYING) || ((p->e).s->aux.spr.flags & SPRFLAG_HIDDEN)) {
    Hitbox_Hide(&(p->e).hitbox);
    Hitbox_Hide(&(p->e).hurtbox);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  } else {
    Hitbox_ClearFlags(&(p->e).hitbox, HBF_HIDDEN);
    Hitbox_ClearFlags(&(p->e).hurtbox, HBF_HIDDEN);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  for (i = 0; i < q->segmentCount; i++) {
    if (!Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_UNK_7)) {
      Hitbox_Hide(&q->segments[i].hitbox);
      Hitbox_Hide(&q->segments[i].hurtbox);
      continue;
    }
    Hitbox_SetPos(&q->segments[i].hurtbox, &q->segments[i].sprite.pos, 0);
    if ((q->segments[i].sprite.flags & (SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD)) || Serpent_TestFlags(q, SERPFLAG_DYING)) {
      Hitbox_Hide(&q->segments[i].hurtbox);
      continue;
    }
    Hitbox_ClearFlags(&q->segments[i].hurtbox, HBF_HIDDEN);
    Vec3_Delta(&d, &q->segments[i].sprite.pos, &gPlayerPtr[0]->mover.pos);
    if (d.x * d.x + d.z * d.z > 0xFFFF) {
      continue;
    }
    Hitbox_ClearFlags(&q->segments[i].hitbox, HBF_HIDDEN);
    Hitbox_SetPos(&q->segments[i].hitbox, &q->segments[i].sprite.pos, 0);
    Hitbox_Register(&q->segments[i].hitbox);
    if (Serpent_TestFlags(q, SERPFLAG_UNK_2)) {
      Hitbox_ClearFlags(&q->segments[i].hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&q->segments[i].hitbox, (p->e).atkPower[1], (p->e).atkKnockback[1], 0, (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      Hitbox_SetFlags(&q->segments[i].hitbox, HBF_ANGLE);
      Hitbox_SetAttack(&q->segments[i].hitbox, (p->e).atkPower[0], (p->e).atkKnockback[0], 0, (p->e).atkAttrs[0], (p->e).atkIframes[0]);
    }
  }
}

// 聞こえた音があれば副状態 23 へ移して waitTimer を張り直す
bool8 Serpent_TryHearNoise(Serpent* p) {
  Serpent* q;
  s32 idx;

  if (Enemy_IsDead(&p->e)) {
    idx = -1;
  } else {
    q = (p->e).owner;
    idx = NoiseManager_FindFirstHeardNoise((p->e).mover.pos.x, (p->e).mover.pos.z, (p->e).range2, (p->e).unk_21d, (p->e).mover.id);
  }
  if (idx < 0) {
    return FALSE;
  }
  FUN_080e8f20(&p->e, idx);
  q->diveCount = 0;
  Enemy_ResetState(&p->e, 0, 0, 23);
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  Serpent_ResetWaitTimer(p);
  FUN_080df478();
  return TRUE;
}

void Serpent_FlashSegment(SerpentSegment* seg) {
  SET_FLAGS(seg->flags, SERPSEGFLAG_FLASH);
  Video_SetAuxSpritePltt(&seg->gfx, OBP_WHITE_306);
  seg->flashTimer = 6;
}

// 被弾で白くした節を flashTimer が尽きたら元の色に戻し, 無敵時間中の節を点滅させる
void Serpent_UpdateSegmentFlash(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 i;

  for (i = 0; i < q->segmentCount; i++) {
    if (Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_FLASH)) {
      if (q->segments[i].flashTimer != 0) {
        q->segments[i].flashTimer--;
      } else {
        Video_SetAuxSpritePltt(&q->segments[i].gfx, 419);
        q->segments[i].flashTimer = 0;
        CLEAR_FLAGS(q->segments[i].flags, SERPSEGFLAG_FLASH);
      }
    }
    if (q->segments[i].hurtbox.iframes != 0) {
      if ((q->segments[i].hurtbox.iframes >> 2) & 1) {
        if (q->segments[i].sprite.pos.y >= (p->e).floorY) {
          q->segments[i].sprite.flags &= ~SPRFLAG_HIDDEN;
        }
      } else {
        q->segments[i].sprite.flags |= SPRFLAG_HIDDEN;
      }
      q->segments[i].hurtbox.iframes--;
      if (q->segments[i].hurtbox.iframes == 0) {
        if (q->segments[i].sprite.pos.y >= (p->e).floorY) {
          q->segments[i].sprite.flags &= ~SPRFLAG_HIDDEN;
        }
      }
    }
  }
}

// 床より下にある頭と節のスプライトを隠す, 頭は床より上で無敵時間が切れていれば戻す
void Serpent_HideBuriedSprites(Serpent* p) {
  Serpent* q = (p->e).owner;
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
    if (!Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
      if (q->segments[i].sprite.pos.y < (p->e).floorY || (p->e).floorY == 0) {
        q->segments[i].sprite.flags |= SPRFLAG_HIDDEN;
      }
    }
  }
}

// '.d' のスクリプトを自分の id を引数にして1度だけ実行する
void Serpent_RunScript(Serpent* p) {
  Serpent* q = (p->e).owner;

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

// hp が unk_546 (最大の 1/4) を下回ったかどうかで unk_d50..unk_d56 を選び直す
void Serpent_UpdateHpParams(Serpent* p) {
  Serpent* q = (p->e).owner;

  if ((p->e).unk_546 >= (p->e).hp) {
    q->unk_d50 = 40;
    q->swimTimeMax = 100;
    q->unk_d54 = (Random() & 0x3F) + 80;
    q->unk_d56 = 1;
  } else {
    q->unk_d50 = 80;
    q->swimTimeMax = 200;
    q->unk_d54 = (Random() & 0x3F) + 160;
    q->unk_d56 = 3;
  }
}

// angle の横から 24 ずつ回しながら泡を count 個撒く
void Serpent_SprayBubbles(Vec3* pos, s32 count, s32 angle, bool32 clockwise) {
  s32 i;

  for (i = 0; i < count; i++) {
    u8 dir;

    if (i & 1) {
      if (clockwise) {
        dir = angle + 0x40 + (i + 1) * 24;
      } else {
        dir = angle - 0x40 - (i + 1) * 24;
      }
      Entity081ee7a8_SpawnEx(pos, 12, 8, 6, 12, 4, dir, 8, 50, 2, 2, 0x200, 0, SPR_EFF_F422, ANIM_121B, 0, 0, 0xDA);
    } else {
      if (clockwise) {
        dir = angle + 0x40 + (i + 1) * 24;
      } else {
        dir = angle - 0x40 - (i + 1) * 24;
      }
      Entity081ee7a8_SpawnEx(pos, 12, 8, 6, 12, 10, dir, 8, 50, 2, 2, 0x400, 0, SPR_EFF_F422, ANIM_121B, 0, 0, 0xDA);
    }
  }
}

// OBP 419 の色を OBP 424 へ 3/10, 6/10 寄せた色と OBP 424 の色を tailPltts に作り, tailPltts[3] を消す
// 残差はスタック退避の位置 (&stepG と k*32 の入れ替え) とループ変数のレジスタだけ (207/207命令), 試済: src/dst の宣言順と代入順 (src/dst は一致), t を外へ出す, ポインタなし, k/i の宣言順
NON_MATCH void Serpent_InitTailPltts(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  rgb555* dst;
  rgb555* src;
  s16 stepR[16], stepG[16], stepB[16];
  s32 i, k;

  src = &gObjPlttData[419 * 16];
  dst = &gObjPlttData[424 * 16];
  for (i = 0; i < 16; i++) {
    stepR[i] = ((dst[i] & 31) - (src[i] & 31)) << 5;
    stepG[i] = (((dst[i] >> 5) & 31) - ((src[i] >> 5) & 31)) << 5;
    stepB[i] = (((dst[i] >> 10) & 31) - ((src[i] >> 10) & 31)) << 5;
    stepR[i] = Div(stepR[i], 10);
    stepG[i] = Div(stepG[i], 10);
    stepB[i] = Div(stepB[i], 10);
  }
  for (k = 0; k < 2; k++) {
    s32 t = (k + 1) * 3;

    for (i = 0; i < 16; i++) {
      s32 r = FixToInt(5, stepR[i] * t);
      s32 g = FixToInt(5, stepG[i] * t);
      s32 b = FixToInt(5, stepB[i] * t);

      q->tailPltts[k][i] = ((src[i] & 31) + r) | ((((src[i] >> 5) & 31) + g) << 5) | ((((src[i] >> 10) & 31) + b) << 10);
    }
  }
  for (i = 0; i < 16; i++) {
    q->tailPltts[2][i] = dst[i];
  }
  ClearMemory(q->tailPltts[3], 32);
#else
  INCFUNC("asm/func/Serpent_InitTailPltts.inc");
#endif
}

// idx 番の節のパレットを選ぶ, 沈んだ節と尾から3つの節は専用の色, それ以外は mode で フェード中の色 / OBP 424 / OBP 419 を載せる
void Serpent_SetSegmentPltt(Serpent* p, s32 idx, s32 mode) {
  Serpent* q = (p->e).owner;
  rgb555* pltt = q->fade.pltt;

  if (Serpent_TestSegmentFlags(&q->segments[idx], SERPSEGFLAG_UNK_8)) {
    q->segments[idx].gfx.plttID = 429;
    q->segments[idx].gfx.pltt = q->tailPltts[3];
  } else if (idx == q->segmentCount - 1) {
    q->segments[idx].gfx.plttID = 428;
    q->segments[idx].gfx.pltt = q->tailPltts[2];
  } else if (idx == q->segmentCount - 2) {
    q->segments[idx].gfx.plttID = 427;
    q->segments[idx].gfx.pltt = q->tailPltts[1];
  } else if (idx == q->segmentCount - 3 && !Serpent_TestFlags(q, SERPFLAG_UNK_12)) {
    q->segments[idx].gfx.plttID = 426;
    q->segments[idx].gfx.pltt = q->tailPltts[0];
  } else {
    switch (mode) {
      case 0: {
        q->segments[idx].gfx.plttID = 425;
        q->segments[idx].gfx.pltt = pltt;
        break;
      }
      case 1: {
        Video_SetAuxSpritePltt(&q->segments[idx].gfx, 424);
        break;
      }
      case 2: {
        Video_SetAuxSpritePltt(&q->segments[idx].gfx, 419);
        break;
      }
    }
  }
}

// 光っていない節のパレットを SERPFLAG_FADING に合わせて選び直す
void Serpent_UpdateSegmentPalettes(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 i;

  if (Serpent_TestFlags(q, SERPFLAG_FADING)) {
    for (i = 0; i < 6; i++) {
      if (q->segments[i].flashTimer == 0) {
        Serpent_SetSegmentPltt(p, i, 0);
      }
    }
  } else {
    for (i = 0; i < 6; i++) {
      if (q->segments[i].flashTimer == 0) {
        Serpent_SetSegmentPltt(p, i, 2);
      }
    }
  }
}

// fromPlttID の色から toPlttID の色へ steps 歩で寄せるフェードを始める
// 残差は p と steps を退避するスタック位置の入れ替えだけ (133/133命令), 試済: ローカルの宣言順, フラグの inline, fade を作る位置
NON_MATCH void Serpent_StartPaletteFade(Serpent* p, s32 toPlttID, s32 fromPlttID, s32 steps) {
#ifdef NONMATCHING_C
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
  SET_FLAGS(p->flags, SERPFLAG_FADING);
#else
  INCFUNC("asm/func/Serpent_StartPaletteFade.inc");
#endif
}

// SERPFLAG_FADING が立っている間フェードを1歩進めて頭のスプライトに載せ, 終わったら TRUE
// 残差は &flags と fade の誘導変数を退避するスタック位置の並びだけ (171/171命令), 試済: TEST_FLAGS / Enemy_TestFlag, 載せる処理の inline, 宣言順, fade ローカルなし
NON_MATCH s32 Serpent_StepPaletteFade(Serpent* p) {
#ifdef NONMATCHING_C
  Serpent* q;
  WormPaletteFade* fade;
  s32 i;

  if (Enemy_IsDead(&p->e)) {
    return FALSE;
  }
  q = (p->e).owner;
  if (!Serpent_TestFlags(q, SERPFLAG_FADING)) {
    return FALSE;
  }
  fade = &q->fade;
  if (fade->timer == 0) {
    if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
      (p->e).s->aux.gfx.plttID = 425;
      (p->e).s->aux.gfx.pltt = fade->pltt;
    }
    return TRUE;
  }
  for (i = 0; i < 16; i++) {
    fade->r[i] += fade->stepR[i];
    fade->g[i] += fade->stepG[i];
    fade->b[i] += fade->stepB[i];
    fade->pltt[i] = FixToInt(5, fade->r[i]) | (FixToInt(5, fade->g[i]) << 5) | (FixToInt(5, fade->b[i]) << 10);
  }
  fade->timer--;
  if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
    (p->e).s->aux.gfx.plttID = 425;
    (p->e).s->aux.gfx.pltt = fade->pltt;
  }
  if (fade->timer == 0) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Serpent_StepPaletteFade.inc");
#endif
}

// from..to 番の節を sunk なら点滅させて BG の後ろへ回し, それ以外は戻す, 範囲外の節は点滅を止める
// 残差はループ外へ出す定数の選び (原典は ~0x100 を sl に置き 0x200 を毎回作る), 試済: segs ローカル, 直書き |= &=, 節フラグの inline, continue
NON_MATCH void Serpent_SetSegmentsSunk(Serpent* p, s32 from, s32 to, bool32 sunk) {
#ifdef NONMATCHING_C
  Serpent* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    if (i >= from && i <= to) {
      if (!sunk) {
        CLEAR_FLAGS(q->segments[i].flags, SERPSEGFLAG_UNK_8);
        CLEAR_FLAGS(q->segments[i].sprite.flags, SPRFLAG_BLINK_ODD);
        q->segments[i].sprite.priority = 2;
      } else {
        SET_FLAGS(q->segments[i].flags, SERPSEGFLAG_UNK_8);
        SET_FLAGS(q->segments[i].sprite.flags, SPRFLAG_BLINK_ODD);
        q->segments[i].sprite.priority = 3;
      }
    } else {
      CLEAR_FLAGS(q->segments[i].sprite.flags, SPRFLAG_BLINK_ODD);
    }
  }
#else
  INCFUNC("asm/func/Serpent_SetSegmentsSunk.inc");
#endif
}

// 頭から pos の方へ 64 ずつたどり, 一度水から出た先で再び水に入ったタイルの中心を out に入れる, 壁なら横へ逸れ, 128 歩で見つからなければ経路 2 のノードを乱数で選ぶ
// 351/356命令, Serpent_FindWaterEdge と同じ残差 (原典は angle のレジスタを (angle >> 7) & 1 で上書きする), 1回目の下書きで切り上げ
NON_MATCH void Serpent_FindWaterAcross(Serpent* p, Vec3* out, Vec3* pos) {
#ifdef NONMATCHING_C
  PathWalker walker;
  Vec3 step;
  WorldPos cur = (p->e).mover.pos;
  u32 angle;
  bool32 leftWater;
  s32 i;

  Vec3_Diff(&step, pos, &cur);
  angle = ArcTan2_8(step.x, step.z);
  step.x = POLAR_X(64, angle);
  step.z = POLAR_Z(64, angle);
  leftWater = FALSE;
  for (i = 0; i < 128; i++) {
    s32 tile;

    cur.x += step.x;
    cur.z += step.z;
    tile = GetCollisionTileIdx(&cur);
    if (TileAtIndex(tile)->attr & TATTR_WALL) {
      cur.x -= step.x;
      cur.z -= step.z;
      if (!((angle >> 7) & 1)) {
        step.x = POLAR_X(64, 0x40);
        step.z = POLAR_Z(64, 0x40);
      } else {
        step.x = POLAR_X(64, 0x80);
        step.z = POLAR_Z(64, 0x80);
      }
      tile = GetCollisionTileIdx(&cur);
    }
    if (leftWater) {
      if (TileAtIndex(tile)->attr & TATTR_FALLDEATH) {
        TilePosAtIndex(out, tile);
        return;
      }
    } else if (!(TileAtIndex(tile)->attr & TATTR_FALLDEATH)) {
      leftWater = TRUE;
    }
  }
  Map_InitPathWalker(&walker, 2, 0, 0);
  walker.nodeIdx = Mod(Random(), walker.path->nodeCount);
  walker.waitTimer = 0;
  walker.node = Map_GetPathNodes(walker.path) + walker.nodeIdx;
  out->x = walker.node->x;
  out->y = (p->e).floorY;
  out->z = walker.node->y;
#else
  INCFUNC("asm/func/Serpent_FindWaterAcross.inc");
#endif
}

// 頭から pos の方へ 64 ずつ水の上をたどり, 水が切れる手前のタイルの中心を out に入れる, 壁なら横へ逸れ, 128 歩で切れなければ経路 2 のノードを乱数で選ぶ
// 338/334命令, 原典は壁に当たったとき angle のレジスタを (angle >> 7) & 1 で上書きし, sin 表の番地を r10 に置く (こちらは cur の番地), 試済: 宣言順, angle の型, angle = (angle >> 7) & 1 の上書き (先頭の割当は一致)
NON_MATCH void Serpent_FindWaterEdge(Serpent* p, Vec3* out, Vec3* pos) {
#ifdef NONMATCHING_C
  PathWalker walker;
  Vec3 step;
  WorldPos cur = (p->e).mover.pos;
  s32 i;
  s32 last;
  u32 angle;

  Vec3_Diff(&step, pos, &cur);
  angle = ArcTan2_8(step.x, step.z);
  step.x = POLAR_X(64, angle);
  step.z = POLAR_Z(64, angle);
  last = (p->e).tileIdx;
  for (i = 0; i < 128; i++) {
    s32 tile;

    cur.x += step.x;
    cur.z += step.z;
    tile = GetCollisionTileIdx(&cur);
    if (TileAtIndex(tile)->attr & TATTR_WALL) {
      cur.x -= step.x;
      cur.z -= step.z;
      if (!((angle >> 7) & 1)) {
        step.x = POLAR_X(64, 0x40);
        step.z = POLAR_Z(64, 0x40);
      } else {
        step.x = POLAR_X(64, 0x80);
        step.z = POLAR_Z(64, 0x80);
      }
      tile = GetCollisionTileIdx(&cur);
    }
    if (!(TileAtIndex(tile)->attr & TATTR_FALLDEATH)) {
      TilePosAtIndex(out, last);
      return;
    }
    last = tile;
  }
  Map_InitPathWalker(&walker, 2, 0, 0);
  walker.nodeIdx = Mod(Random(), walker.path->nodeCount);
  walker.waitTimer = 0;
  walker.node = Map_GetPathNodes(walker.path) + walker.nodeIdx;
  out->x = walker.node->x;
  out->y = (p->e).floorY;
  out->z = walker.node->y;
#else
  INCFUNC("asm/func/Serpent_FindWaterEdge.inc");
#endif
}

// waitTimer を張り直す, 弱っていれば半分の時間にする
void Serpent_ResetWaitTimer(Serpent* p) {
  Serpent* q = (p->e).owner;

  SET_FLAGS(q->flags, SERPFLAG_UNK_10 | SERPFLAG_UNK_11);
  q->unk_e40 = 0;
  if ((p->e).hp <= (p->e).unk_546) {
    q->waitTimer = q->waitTime >> 1;
  } else {
    q->waitTimer = q->waitTime;
  }
}

void Serpent_ResetRecentNodes(Serpent* p) {
  Serpent* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    q->recentNodes[i] = -1;
  }
  q->recentNodeIdx = 0;
}

void Serpent_AddRecentNode(Serpent* p, s32 node) {
  Serpent* q = (p->e).owner;

  q->recentNodes[q->recentNodeIdx] = node;
  q->recentNodeIdx++;
  if (q->recentNodeIdx > 2) {
    q->recentNodeIdx = 0;
  }
}

bool8 Serpent_IsRecentNode(Serpent* p, s32 node) {
  Serpent* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    if (q->recentNodes[i] == node) {
      return TRUE;
    }
  }
  return FALSE;
}

// 経路 2 のノードのうち pos に一番近いものの位置 (高さは floorY) を out に入れる
// 100/111命令, 原典は cur と d をスタックに置き d の成分を語単位の読み書きで更新する (アドレスを取られた形), 試済: 距離の inline (値渡し/ポインタ), d をポインタ経由, DistSq
NON_MATCH void Serpent_FindNearestPathNode(Serpent* p, Vec3* out, Vec3* pos) {
#ifdef NONMATCHING_C
  PathWalker walker;
  PathWalker cur;
  Vec3 d;
  s32 best = 0x7FFFFFFF;
  s32 bestIdx = -1;
  s32 i;

  Map_InitPathWalker(&walker, 2, 0, 0);
  for (i = 0; i < walker.path->nodeCount; i++) {
    s32 dist;

    cur.node = Map_GetPathNodes(walker.path) + i;
    d = *pos;
    d.x = cur.node->x - d.x;
    d.z = cur.node->y - d.z;
    dist = d.x * d.x + d.z * d.z;
    if (best > dist) {
      bestIdx = i;
      best = dist;
    }
  }
  if (best != 0x7FFFFFFF) {
    walker.nodeIdx = bestIdx;
    walker.waitTimer = 0;
    walker.node = Map_GetPathNodes(walker.path) + walker.nodeIdx;
    out->x = walker.node->x;
    out->y = (p->e).floorY;
    out->z = walker.node->y;
  }
#else
  INCFUNC("asm/func/Serpent_FindNearestPathNode.inc");
#endif
}

// 経路 2 のノードから最近選んでいないものを選び out に入れる, far なら limitSq より遠い中で一番近いもの, そうでなければ limitSq 以内で一番遠いもの, 無ければ Serpent_FindWaterAcross に任せる
// 139/153命令, Serpent_FindNearestPathNode と同じ壁 (原典は cur と d をスタックに置く), best の初期化も Map_InitPathWalker の後, 1回目の下書きで切り上げ
NON_MATCH void Serpent_PickPathNode(Serpent* p, Vec3* out, Vec3* pos, s32 limitSq, bool32 far) {
#ifdef NONMATCHING_C
  PathWalker walker;
  PathWalker cur;
  Vec3 d;
  Serpent* q = (p->e).owner;
  s32 best = far ? 0x7FFFFFFF : 0;
  s32 bestIdx = -1;
  s32 i;

  Map_InitPathWalker(&walker, 2, 0, 0);
  for (i = 0; i < walker.path->nodeCount; i++) {
    s32 dist;

    cur.node = Map_GetPathNodes(walker.path) + i;
    d = *pos;
    d.x = cur.node->x - d.x;
    d.z = cur.node->y - d.z;
    dist = d.x * d.x + d.z * d.z;
    if (dist == 0) {
      continue;
    }
    if (!far) {
      if (dist > limitSq || best >= dist) {
        continue;
      }
    } else if (dist < limitSq || best <= dist) {
      continue;
    }
    if (!Serpent_IsRecentNode(p, i)) {
      bestIdx = i;
      best = dist;
    }
  }
  if (best == 0) {
    Serpent_FindWaterAcross(p, &q->leapDest, &gPlayerPtr[0]->mover.pos);
  } else {
    Serpent_AddRecentNode(p, bestIdx);
    walker.nodeIdx = bestIdx;
    walker.waitTimer = 0;
    walker.node = Map_GetPathNodes(walker.path) + walker.nodeIdx;
    out->x = walker.node->x;
    out->y = (p->e).floorY;
    out->z = walker.node->y;
  }
#else
  INCFUNC("asm/func/Serpent_PickPathNode.inc");
#endif
}

// 106/125命令, FUN_081acd90 (サラマンダー) と同じ壁, 原典は jumpVel.x と jumpVel.z の abs を r3/r2 に求めて捨てる, 試済: 使わない引数の inline に abs を渡す (消える), 2回目で切り上げ
NON_MATCH void FUN_08193ca4(Serpent* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Serpent_StateHover, ES_UNK_34);
    (p->e).unk_1bc = 8;
  }
  Serpent_PullSegments(p, 4, 12, 0x4000);
  Serpent_UpdateWave(p, 430, 40);
  if ((p->e).subStateDone) {
    Serpent_PickNextTile(p);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08193ca4.inc");
#endif
}

void FUN_08193dc8(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    s32 i;

    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_EnterState(&p->e, Serpent_StateRise, ES_UNK_37);
    for (i = 0; i < 5; i++) {
      if (!Serpent_TestSegmentFlags(&q->segments[i], SERPSEGFLAG_DESTROYED)) {
        q->segments[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      }
    }
    Serpent_SpawnSegmentSplashes(p, 3);
  }
  Serpent_PullSegments(p, 4, 12, 0x4000);
  if ((p->e).unk_1ca == 0 || Mod((p->e).unk_1ca, 5) == 0) {
    Serpent_SpawnSegmentSplashes(p, 3);
  }
  if ((p->e).subStateDone) {
    Vec3 d;

    Serpent_SpawnBubble(&(p->e).mover.pos, (p->e).floorY);
    PlaySound_082406e0(SONG_479);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Serpent_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    Enemy_ResetState(&p->e, 0, 0, 14);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    AuxShadow_Hide(&(p->e).auxShadow);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_08193fa4(Serpent* p) {
  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  Serpent_PullSegments(p, 4, 12, 0x4000);
  Serpent_EmitSegmentBubbles(p, 3, 10);
  if ((p->e).subStateDone) {
    Vec3 d;

    Serpent_SpawnBubble(&(p->e).mover.pos, (p->e).floorY);
    PlaySound_082406e0(SONG_479);
    CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
    Serpent_PickNextTile(p);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).unk_1dc = ArcTan2_8(d.x, d.z);
    Enemy_ResetState(&p->e, 0, 2, 3);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    AuxShadow_Hide(&(p->e).auxShadow);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_081940d8(Serpent* p) {
  Serpent* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5);
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    CLEAR_FLAGS(q->flags, SERPFLAG_UNK_2);
  }
  Serpent_EmitSegmentBubbles(p, 0, 10);
  (p->e).mover.pos.y = -2048;
  Serpent_PullSegments(p, 4, 12, 0x4000);
  if ((p->e).subStateTimer > 160) {
    Enemy_ResetState(&p->e, 0, 0, 19);
  }
  (p->e).subStateTimer++;
}

void Serpent_SetHandlerTable4(Serpent* p) { (p->e).handlerTables[4] = (void*)sSerpentHandlerTable4; }

s32 Serpent_PreUpdate(Serpent* p) {
  Serpent_KnockBackSegment(p);
  Serpent_UpdateSegmentFlash(p);
  Serpent_UpdateHpParams(p);
  return 1;
}

s32 Serpent_PostUpdate(Serpent* p) {
  FUN_0819235c(p);
  Serpent_UpdateHitboxes(p);
  Serpent_SelectAttack(p);
  Serpent_UpdateAnimSpeed(p);
  Serpent_HideDestroyedSegments(p);
  Serpent_FollowSegments(p);
  Serpent_ApplySegmentVelocity(p);
  Serpent_SnapSegmentsToFloor(p);
  Serpent_KeepInWater(p);
  Serpent_HideBuriedSprites(p);
  Serpent_StepPaletteFade(p);
  Serpent_UpdateSegmentPalettes(p);
  return 1;
}

bool8 Serpent_OnDamaged(Serpent* p) {
  PlaySound_082406e0(SONG_992);
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  return TRUE;
}

s32 Serpent_UpdateFrame(Serpent* p) {
  Serpent_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Serpent_PostUpdate(p);
  return 1;
}

s32 Serpent_Update(Serpent* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), GAMEFLAG_GAMEOVER) || TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return FALSE;
  }

  if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_1)) {
    if (!IsCurrentZone((p->e).zoneID)) {
      Enemy_Suspend(&p->e, NULL);
      return FALSE;
    }

    Serpent_ApplyDamage(p);
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

s32 Serpent_Destroy(Serpent* p) {
  sound_08240740(SONG_997);
  Serpent_RemoveSegmentSprites(p);
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
// 1752/1952命令, Salamander_Init の下書きを Serpent 向けに直したもの (呼び出し列は一致), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline, フレーム 0x1C4, こちらは 0x50), 1回目の下書きで切り上げ
NON_MATCH s32 Serpent_Init(Serpent* p) {
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
  (p->e).kind = ENEK_SERPENT;
  Serpent_InitAnims(p);
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

  Mover_Init(&(p->e).mover, id, &pos, 0, 4, p);
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
    p->segmentDefense = VM_GetPC() != NULL ? VM_GetValue() : 44;
    p->tailDefense = VM_GetPC() != NULL ? VM_GetValue() : 44;
  }
  p->scriptID = VM_GetNamedArgValue('d', 0);
  p->swimTimer = 0;
  p->unk_f43 = 0;
  p->waitTime = 30;
  Serpent_ResetRecentTiles(p);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 419;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 419;
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

  Serpent_InitTailPltts(p);
  Serpent_InitHitboxes(p);
  Serpent_InitFollowInterval(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Serpent_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Serpent_GetMoveSpeed;
  (p->e).handlerTurn = Serpent_StateTurn;
  (p->e).handlerMove = Serpent_StateMove;
  (p->e).handlerWait = Serpent_StateWait;
  (p->e).handlerNap = FUN_0818960c;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Serpent_StateDamaged;
  (p->e).handlerDying = Serpent_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = FUN_08189610;
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
  (p->e).unk_5e0 = Serpent_ClearStateBegun;
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
  (p->e).msgHandlers = (void*)sSerpentMsgHandlers;
  (p->e).onReset = (EnemyHandler)Serpent_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).onAttackRequest = (EnemyHandler)Serpent_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)FUN_0819218c;
  (p->e).tryDetectPlayer = (void*)Serpent_TryDetectPlayer;
  (p->e).onDamaged = (void*)Serpent_OnDamaged;
  (p->e).unk_5b4 = (EnemyHandler)Serpent_ScatterSegments;
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
  Serpent_SetHandlerTable2(p);
  Serpent_SetHandlerTable4(p);
  Serpent_InitSegments(p, SPR_WORM, ANIM_WORM, (p->e).mover.angle);
  Serpent_SetAllSegmentsPos(p, &(p->e).mover.pos);
  Serpent_InitSegmentHitboxes(p);
  Serpent_PickNextTile(p);
  Serpent_ResetRecentNodes(p);
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
  (p->e).handlerUpdate = (EnemyHandler)Serpent_Update;
  (p->e).handlerDestroy = (EnemyHandler)Serpent_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Serpent_Init.inc");
#endif
}

// 0x13AC, HashName("サーペント")
void Serpent_Create(void) {
  Serpent* p = Malloc(sizeof(Serpent));

  if (p != NULL) {
    ClearMemory(p, sizeof(Serpent));
    if (Serpent_Init(p) < 0) {
      Serpent_Destroy(p);
      Free(p);
    }
  }
}

// プレイヤーへ向けて水平に 32 の速さで跳ね, 着くまでの時間から縦の速さを決める
void Serpent_AimJumpAtPlayer(Serpent* p) {
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
