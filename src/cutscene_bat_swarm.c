#include "entity.h"
#include "file.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "random.h"
#include "shadow.h"
#include "sprite_aux.h"
#include "sprite_pltt.h"
#include "vec3.h"
#include "video.h"

typedef struct {
  bool8 stateEntered;     // 0x00, state を変えると 1, 各 UpdateState 関数は 0 以外なら状態の入り口の処理をして 0 に落とす
  u8 state;               // 0x01, sElemUpdates の添字, CutsceneBat_Init が 0 を入れ、各 UpdateState 関数が次の番号を書く
  bool8 animFinished;     // 0x02, 直前の更新でアニメが一巡したか
  u8 bobPhase;            // 0x03, 上下に揺らす sin の位相, 毎フレーム 4 進む
  u16 timer;              // 0x04, state に入ってからのフレーム数
  s8 angle;               // 0x06, 8bit の向き, 各 UpdateState 関数が ArcTan2_8 の結果を入れ gSineTable の添字にする
  s8 moveAngle;           // 0x07, 進む向き, 顔の向き angle とは別
  u8 moveTime;            // 0x08, moveAngle へ進む残りフレーム数
  u8 unk_09;              // 0x09
  u16 baseY;              // 0x0A, pos.y を 1 ずつ寄せていく高さ
  u16 speed;              // 0x0C, 進む速さ
  u8 unk_0e[2];           // 0x0E
  Vec3 pos;               // 0x10
  Vec3 target;            // 0x18, 向かう先の座標
  Vec3 orbitCenter;       // 0x20, state 4 で target へ寄せていく周回の中心
  Vec3 orbitOffset;       // 0x28, state 4 の orbitCenter からのずれ
  AuxAnimState anim;      // 0x30
  AuxSprite sprite;       // 0x40
  AuxSpriteGfx gfx;       // 0x6C, SPRITE_BAT
  ParticleShadow shadow;  // 0x88, ParticleShadow_Init(&shadow, &sprite.pos, 0) のあと Hide する
} CutsceneBat;
static_assert(sizeof(CutsceneBat) == 200);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_11
  u32 unk_18;                // 0x018, _Init が 0 を入れる, 0 の間は Update が要素を動かさない
  u32 frameCount;            // 0x01C, 要素を動かしたフレーム数
  AuxAnimFile* anim;         // 0x020, ANIM_BAT
  CutsceneBat elems[16];  // 0x024
  s8 fadeDir;                // 0xCA4, pltt のブレンドの向き (0: 63 まで上げる, 1: 0 まで下げる, 2: 32 まで上げる, 負: 止める)
  s8 fadeLevel;              // 0xCA5, BlendPltt の t
  u16 targetMoverID;         // 0xCA6, cmd 2 の args[0], 0 でなければ Update が毎フレーム Mover_FindByID_Proxy で引いて targetMover に入れる
  rgb555 pltt[16];           // 0xCA8, BlendPltt(&pltt, gObjPlttData+0x2630, gObjPlttData+0x2650, 0x40, 6), elems[i].gfx.pltt がここを指す
  Mover* targetMover;        // 0xCC8, 要素が state 3 / 4 で追いかける Mover
  Vec3 center;               // 0xCCC, 要素が向きを向ける中心の座標
  MsgQueue mq;               // 0xCD4
} CutsceneBatSwarm;
static_assert(sizeof(CutsceneBatSwarm) == 3336);

// gMsgBus をこの inline 越しに読むと, メッセージ取り出しのループで原典どおり毎回プールから読み直す形になる
static inline MsgBus* GetMsgBus(void) { return gMsgBus; }

// 要素のパレットを plttID に戻し, 色はブレンド済みの p->pltt を使わせる
static inline void CutsceneBatSwarm_SetElemPltt(CutsceneBatSwarm* p, AuxSpriteGfx* gfx, s32 plttID) {
  Video_SetAuxSpritePltt(gfx, plttID);
  gfx->pltt = p->pltt;
}

// 要素を state へ切り替えて, 次の更新で入り口の処理をさせる
static inline void CutsceneBat_SetState(CutsceneBat* e, u8 state) {
  e->state = state;
  e->stateEntered = TRUE;
  e->timer = 0;
}

// from から to を向く 8bit の向き
static inline s32 CutsceneBatSwarm_AngleTo(Vec3* from, Vec3* to) { return ArcTan2_8(to->x - from->x, to->z - from->z); }

// 4 方向の向き dir を左右反転とアニメの variant に分ける
static inline void CutsceneBatSwarm_GetAnimVariant(u8 dir, u8* variant, u8* xflip) {
  if (dir == DIR4_EAST || dir == DIR4_SOUTH) {
    *variant = 1;
  } else {
    *variant = 0;
  }
  if (dir > DIR4_EAST) {
    *xflip = TRUE;
  } else {
    *xflip = FALSE;
  }
}

// 要素1つ分のスプライトと影を用意して, 状態を0番から始める
// 残差は冒頭の 0 だけ (47/47命令), 原典は state と angle を r1 の 0, timer と CpuFill32 を r6 の 0 で書く, RingoBat_Init / VampireSword_Init と同じ壁
// パレットは CutsceneBatSwarm_SetElemPltt, 座標は Vec3_Clear(pos) で揃った, 試済: 状態遷移の inline (CutsceneBat_SetState の引数を u8 / u16 / u32 / s32 にしても同じ), 状態と角度を引数で受ける inline
NON_MATCH s32 CutsceneBat_Init(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
#ifdef NONMATCHING_C
  AuxSpriteGfx* gfx;
  AuxSprite* sprite;
  Vec3* pos;

  e->state = 0;
  e->stateEntered = TRUE;
  e->timer = 0;
  e->angle = 0;
  gfx = &e->gfx;
  Video_GetAuxSprite(gfx, SPRITE_BAT);
  CutsceneBatSwarm_SetElemPltt(p, gfx, 611);
  sprite = &e->sprite;
  AuxSprite_Add(sprite, gfx, SPRFLAG_HIDDEN);
  sprite->priority = 2;
  pos = &sprite->pos;
  Vec3_Clear(pos);
  ParticleShadow_Init(&e->shadow, pos, 0);
  ParticleShadow_Hide(&e->shadow);
#else
  INCFUNC("asm/func/CutsceneBat_Init.inc");
#endif
}

// 要素の影とスプライトを描画リストから外す
s32 CutsceneBat_Destroy(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
  ParticleShadow_Remove(&e->shadow);
  AuxSprite_Remove(&e->sprite);
}

// 要素の向きから象限を出して, アニメーションの variant と左右反転をそれで決めて再生を始める
void CutsceneBat_SetAnim(CutsceneBatSwarm* p, CutsceneBat* e, s32 animIdx) {
  u8 variant;
  u8 xflip;

  CutsceneBatSwarm_GetAnimVariant(Angle_ToDir4(e->angle), &variant, &xflip);
  AuxAnim_SetAnim(&e->anim, p->anim, animIdx, variant, xflip);
}

// pos をスプライトへ写してアニメを進め, 高さを baseY へ寄せながら上下に揺らす
void CutsceneBat_UpdateSprite(CutsceneBat* e) {
  AuxSprite* sprite = &e->sprite;

  e->sprite.pos = e->pos;
  e->animFinished = AuxSprite_AdvanceAnim(sprite, &e->anim);
  if (e->pos.y > e->baseY) {
    e->pos.y--;
  } else if (e->pos.y < e->baseY) {
    e->pos.y++;
  }
  sprite->pos.y += POLAR_Z(32, e->bobPhase);
  e->bobPhase += 4;
}

// 全要素を args の中心の周りに並べて state 5 から動かし始め, パレットを暗い側から戻していく
// 残差: 原典は要素のポインタを2本 (r4 はフィールド用, r6 は引数に渡すアドレス用) 持ち, どちらも 200 ずつ進めて i をスタックに置く, &p->elems[i] から強度削減で2本に分けた形に見える, こちらは e++ の1本で4命令短い, 試済: ループ内で &p->elems[i] を取る形 (281/281 命令だが i * 200 の muls が残る), p->elems[i] の直接参照
NON_MATCH s32 CutsceneBatSwarm_HandleCmd0(CutsceneBatSwarm* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  Vec3 center;
  s32 i;
  s32 speed;
  s32 dist;
  s32 targetDist;
  s32 angle;
  s32 spread;
  CutsceneBat* e;

  VEC3_SET(center, msg->args[0], msg->args[1], msg->args[2]);
  speed = msg->args[3];
  dist = msg->args[4];
  targetDist = msg->args[5];
  angle = msg->args[6];
  spread = msg->args[7];
  p->center = center;
  p->frameCount = 0;
  p->fadeDir = 1;
  p->fadeLevel = 63;
  {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[613 * 16];

    BlendPltt(p->pltt, src1, src2, 63, 6);
  }
  e = p->elems;
  for (i = 0; i < 16; i++, e++) {
    e->state = 5;
    e->stateEntered = TRUE;
    e->timer = 0;
    e->angle = angle;
    if (spread != 0) {
      e->angle += Mod(Random(), spread);
    }
    e->speed = speed;
    Vec3_SetPolar(&e->pos, e->angle, dist);
    Vec3_Add(&e->pos, &center);
    Vec3_SetPolar(&e->target, e->angle, targetDist);
    Vec3_Add(&e->target, &center);
    e->bobPhase = Random();
    e->baseY = (i << 4) + e->pos.y;
    e->moveTime = (Random() & 7) + 7;
    e->sprite.pos = e->pos;
    AuxSprite_Show(&e->sprite);
    CutsceneBat_SetAnim(p, e, 0);
    Video_SetAuxSpritePltt(&e->gfx, 611);
    e->gfx.pltt = p->pltt;
    ParticleShadow_Show(&e->shadow);
  }
  p->unk_18 = 1;
  return 0;
#else
  INCFUNC("asm/func/CutsceneBatSwarm_HandleCmd0.inc");
#endif
}

// 全要素を args の中心の周りに並べて state 0 から動かし始め, パレットを暗い側から戻していく
// 残差: CutsceneBatSwarm_HandleCmd0 と同じ, 原典は要素のポインタを2本 (フィールド用と引数に渡すアドレス用) 持ち i をスタックに置く, ループ内で &p->elems[i] を取ると命令数は揃うが i * 200 の muls が残る
NON_MATCH s32 CutsceneBatSwarm_HandleCmd1(CutsceneBatSwarm* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  Vec3 center;
  s32 i;
  s32 speed;
  s32 dist;
  s32 targetDist;
  s32 angle;
  s32 spread;
  CutsceneBat* e;

  VEC3_SET(center, msg->args[0], msg->args[1], msg->args[2]);
  speed = msg->args[3];
  dist = msg->args[4];
  targetDist = msg->args[5];
  angle = msg->args[6];
  spread = msg->args[7];
  p->center = center;
  p->frameCount = 0;
  p->fadeDir = 1;
  p->fadeLevel = 63;
  {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[613 * 16];

    BlendPltt(p->pltt, src1, src2, 63, 6);
  }
  e = p->elems;
  for (i = 0; i < 16; i++, e++) {
    e->state = 0;
    e->stateEntered = TRUE;
    e->timer = 0;
    e->angle = angle;
    if (spread != 0) {
      e->angle += Mod(Random(), spread);
    }
    e->speed = speed;
    Vec3_SetPolar(&e->pos, e->angle, dist);
    Vec3_Add(&e->pos, &center);
    Vec3_SetPolar(&e->target, e->angle, targetDist);
    Vec3_Add(&e->target, &center);
    e->bobPhase = Random();
    e->baseY = (i << 4) + e->pos.y;
    e->moveTime = (Random() & 7) + 7;
    e->sprite.pos = e->pos;
    AuxSprite_Show(&e->sprite);
    CutsceneBat_SetAnim(p, e, 0);
    Video_SetAuxSpritePltt(&e->gfx, 611);
    e->gfx.pltt = p->pltt;
    ParticleShadow_Show(&e->shadow);
  }
  p->unk_18 = 1;
  return 0;
#else
  INCFUNC("asm/func/CutsceneBatSwarm_HandleCmd1.inc");
#endif
}

// args[0] の Mover の今の位置へ向けて全要素を飛ばし始める
// 残差: 命令の並びは同じ (101/101), 原典は e = p->elems を乱数の定数の巻き上げとカウンタの初期化より後に置き, p を r5 / カウンタを r6 に持つ, 試済: ループ内で &p->elems[i] を取る形, p->elems[i] の直接参照, for の初期化式
NON_MATCH s32 CutsceneBatSwarm_HandleCmd2(CutsceneBatSwarm* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  Mover* m;
  s32 speed;
  Vec3 target;
  CutsceneBat* e;
  s32 i;

  p->targetMoverID = msg->args[0];
  m = Mover_FindByID_Proxy(p->targetMoverID);
  if (m == NULL) {
    return -1;
  }
  target = m->pos;
  speed = msg->args[1];
  p->frameCount = 0;
  e = p->elems;
  for (i = 0; i < 16; i++, e++) {
    e->state = 3;
    e->stateEntered = TRUE;
    e->timer = 0;
    e->target = target;
    e->angle = ArcTan2_8(e->target.x - e->pos.x, e->target.z - e->pos.z);
    e->angle += (RandomNext() & 31) - 16;
    e->speed = speed;
    e->moveTime = (RandomNext() & 7) + 7;
  }
  p->unk_18 = 1;
  return 0;
#else
  INCFUNC("asm/func/CutsceneBatSwarm_HandleCmd2.inc");
#endif
}

// 届いたメッセージを cmd ごとの処理に振り分ける
s32 CutsceneBatSwarm_HandleMsgs(CutsceneBatSwarm* p) {
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        CutsceneBatSwarm_HandleCmd0(p, mq, msg);
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
      case 1: {
        CutsceneBatSwarm_HandleCmd1(p, mq, msg);
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
      case 2: {
        CutsceneBatSwarm_HandleCmd2(p, mq, msg);
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
    }
  }
  return 0;
}

void CutsceneBat_UpdateState0(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
  Vec3 vel;

  if (e->stateEntered) {
    e->stateEntered = FALSE;
  }
  Vec3_SetPolar(&vel, e->angle, e->speed * 2);
  Vec3_Add(&e->pos, &vel);
  CutsceneBat_SetAnim(p, e, 0);
  if (e->timer >= idx + 2) {
    e->state = 1;
    e->stateEntered = TRUE;
    e->timer = 0;
  }
  e->timer++;
}

// state 2, 目標から左右に 64 前後ずれた向きへ少し飛び, center の方を向く
// 残差: 166/167 命令, 原典は moveAngle を足す側 (else) で乱数表の番地をプールから読み直すが, こちらは最初の Random の番地 (r5) を使い回す, center への向きは CutsceneBatSwarm_AngleTo, 状態の切り替えは CutsceneBat_SetState で揃った, 試済: RandomNext, 条件の向きを逆にする形
NON_MATCH void CutsceneBat_UpdateState2(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vel;

  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->moveAngle = e->angle = ArcTan2_8(e->target.x - e->pos.x, e->target.z - e->pos.z);
    if ((Random() & 0xFF) < 128) {
      e->moveAngle += 64 - (Random() & 63);
    } else {
      e->moveAngle += 64 + (Random() & 63);
    }
    e->moveTime = (Random() & 3) + 4;
  }
  if (e->moveTime != 0) {
    Vec3_SetPolar(&vel, e->moveAngle, e->speed);
    Vec3_Add(&e->pos, &vel);
    e->angle = CutsceneBatSwarm_AngleTo(&e->pos, &p->center);
    e->moveTime--;
  }
  CutsceneBat_SetAnim(p, e, 0);
  if (e->timer > 95) {
    CutsceneBat_SetState(e, 1);
  }
  e->timer++;
#else
  INCFUNC("asm/func/CutsceneBat_UpdateState2.inc");
#endif
}

// state 1, center の方を向いたまま target へ向きを散らしながら近づき, 200 以内に入ったら state 2 へ移る
void CutsceneBat_UpdateState1(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
  Vec3 vel;
  Vec3* pos;
  s32 dx;
  s32 dz;

  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->angle = CutsceneBatSwarm_AngleTo(&e->pos, &p->center);
    e->moveAngle = CutsceneBatSwarm_AngleTo(&e->pos, &e->target);
    e->moveAngle += (RandomNext() & 31) - 16;
    e->moveTime = (RandomNext() & 15) + 16;
  }
  pos = &e->pos;
  dx = e->target.x - pos->x;
  dz = e->target.z - pos->z;
  if (dx * dx + dz * dz < 40000) {
    CutsceneBat_SetState(e, 2);
    return;
  }
  if (e->moveTime == 0) {
    e->moveAngle = ArcTan2_8(dx, dz);
    e->moveAngle += (RandomNext() & 31) - 16;
    e->moveTime = (RandomNext() & 31) + 32;
  } else {
    e->moveTime--;
  }
  Vec3_SetPolar(&vel, e->moveAngle, e->speed);
  Vec3_Add(&e->pos, &vel);
  e->angle = CutsceneBatSwarm_AngleTo(&e->pos, &p->center);
  CutsceneBat_SetAnim(p, e, 0);
  e->timer++;
}

// state 3, targetMover へ向きを散らしながら近づき, 64 以内に入ったら state 4 へ移る
void CutsceneBat_UpdateState3(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
  Vec3 vel;
  Vec3* pos;
  Vec3* target;
  s32 dx;
  s32 dz;

  if (p->targetMover != NULL) {
    e->target = p->targetMover->pos;
  }
  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->angle = CutsceneBatSwarm_AngleTo(&e->pos, &e->target);
    e->angle += (RandomNext() & 31) - 16;
    e->moveTime = (RandomNext() & 15) + 16;
  }
  if (e->moveTime == 0) {
    e->angle = CutsceneBatSwarm_AngleTo(&e->pos, &e->target);
    e->angle += (RandomNext() & 15) - 8;
    e->moveTime = (RandomNext() & 15) + 16;
  } else {
    e->moveTime--;
  }
  pos = &e->pos;
  target = &e->target;
  dx = target->x - pos->x;
  dz = target->z - pos->z;
  if (dx * dx + dz * dz < 4096) {
    CutsceneBat_SetState(e, 4);
    return;
  }
  Vec3_SetPolar(&vel, e->angle, e->speed);
  Vec3_Add(&e->pos, &vel);
  CutsceneBat_SetAnim(p, e, 0);
  e->timer++;
}

// state 4, 周回の中心を target へ寄せながら, その周りを向きを散らしつつ飛び回る
// 残差: 168/168 命令, moveTime が 0 のときの ArcTan2_8 の第1引数で orbitOffset.x のオフセット 0x28 を置く一時レジスタだけ (原典 r2, こちら r1), CpuFill32 は Vec3_Clear で揃った, 試済: 向きの inline, orbitOffset のポインタ, 符号反転をローカルに置く形
NON_MATCH void CutsceneBat_UpdateState4(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vel;

  if (p->targetMover != NULL) {
    e->target = p->targetMover->pos;
  }
  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->orbitCenter = e->pos;
    e->angle = Random();
    Vec3_Clear(&e->orbitOffset);
  }
  LerpVec3(&e->orbitCenter, &e->orbitCenter, &e->target, idx + 8, 5);
  if (e->moveTime == 0) {
    e->angle = ArcTan2_8(-e->orbitOffset.x, -e->orbitOffset.z);
    e->angle += (RandomNext() & 15) - 7;
    e->moveTime = (RandomNext() & 7) + 8;
  } else {
    e->moveTime--;
  }
  Vec3_SetPolar(&vel, e->angle, e->speed);
  Vec3_Add(&e->orbitOffset, &vel);
  e->pos.x = e->orbitCenter.x + e->orbitOffset.x;
  e->pos.z = e->orbitCenter.z + e->orbitOffset.z;
  CutsceneBat_SetAnim(p, e, 0);
  e->timer++;
#else
  INCFUNC("asm/func/CutsceneBat_UpdateState4.inc");
#endif
}

void CutsceneBat_UpdateState5(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
  Vec3 vel;

  if (e->stateEntered) {
    e->stateEntered = FALSE;
  }
  Vec3_SetPolar(&vel, e->angle, e->speed * 2);
  Vec3_Add(&e->pos, &vel);
  CutsceneBat_SetAnim(p, e, 0);
  if (e->timer >= idx + 2) {
    e->state = 6;
    e->stateEntered = TRUE;
    e->timer = 0;
  }
  e->timer++;
}

// state 6, target へ向きを少し散らしながら近づき, 200 以内に入ったら state 2 へ移る
void CutsceneBat_UpdateState6(CutsceneBatSwarm* p, CutsceneBat* e, s32 idx) {
  Vec3 vel;
  Vec3* pos;
  s32 dx;
  s32 dz;

  if (e->stateEntered) {
    e->stateEntered = FALSE;
    e->angle = ArcTan2_8(e->target.x - e->pos.x, e->target.z - e->pos.z);
    e->angle += (RandomNext() & 31) - 16;
    e->moveTime = (RandomNext() & 15) + 16;
  }
  pos = &e->pos;
  dx = e->target.x - pos->x;
  dz = e->target.z - pos->z;
  if (dx * dx + dz * dz < 40000) {
    CutsceneBat_SetState(e, 2);
    return;
  }
  if (e->moveTime == 0) {
    e->angle = ArcTan2_8(dx, dz);
    e->angle += (RandomNext() & 31) - 16;
    e->moveTime = (RandomNext() & 31) + 32;
  } else {
    e->moveTime--;
  }
  Vec3_SetPolar(&vel, e->angle, e->speed);
  Vec3_Add(&e->pos, &vel);
  CutsceneBat_SetAnim(p, e, 0);
  e->timer++;
}

static void (*const sElemUpdates[7])(CutsceneBatSwarm*, CutsceneBat*, s32) = {
    CutsceneBat_UpdateState0,
    CutsceneBat_UpdateState1,
    CutsceneBat_UpdateState2,
    CutsceneBat_UpdateState3,
    CutsceneBat_UpdateState4,
    CutsceneBat_UpdateState5,
    CutsceneBat_UpdateState6,
};  // 0x085AA81C

s32 CutsceneBatSwarm_Update(CutsceneBatSwarm* p) {
  CutsceneBat* e;
  s32 i;

  CutsceneBatSwarm_HandleMsgs(p);
  if (p->unk_18 == 0) {
    return 0;
  }
  if (p->targetMoverID != 0) {
    p->targetMover = Mover_FindByID_Proxy(p->targetMoverID);
  }
  if (p->fadeDir == 0) {
    if (++p->fadeLevel > 62) {
      p->fadeLevel = 63;
      p->fadeDir = -1;
    }
  } else if (p->fadeDir == 1) {
    if (--p->fadeLevel <= 0) {
      p->fadeLevel = 0;
      p->fadeDir = -1;
    }
  } else if (p->fadeDir == 2) {
    if (++p->fadeLevel > 31) {
      p->fadeLevel = 32;
      p->fadeDir = -1;
    }
  }
  if (p->fadeDir >= 0) {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[613 * 16];

    BlendPltt(p->pltt, src1, src2, p->fadeLevel, 6);
  }
  e = p->elems;
  for (i = 0; i < 16; i++, e++) {
    sElemUpdates[e->state](p, e, i);
    CutsceneBat_UpdateSprite(e);
  }
  p->frameCount++;
  return 0;
}

s32 CutsceneBatSwarm_Destroy(CutsceneBatSwarm* p) {
  CutsceneBat* e = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, e++) {
    CutsceneBat_Destroy(p, e, i);
  }

  MsgQueue_Unregister(&p->mq);
  return 0;
}

s32 CutsceneBatSwarm_Init(CutsceneBatSwarm* p, u32 id) {
  CutsceneBat* e;
  s32 i;

  p->unk_18 = 0;
  p->targetMoverID = 0;
  p->targetMover = NULL;
  p->anim = GetFile(DIR_ANIMATION, ANIM_BAT);
  {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[613 * 16];

    BlendPltt(p->pltt, src1, src2, 64, 6);
  }
  e = p->elems;
  for (i = 0; i < 16; i++, e++) {
    CutsceneBat_Init(p, e, i);
  }
  MsgQueue_Register(&p->mq, id, 10);
  return 0;
}

CutsceneBatSwarm* CutsceneBatSwarm_Create(u32 id) {
  CutsceneBatSwarm* p = CreateEntity(ENTITY_UNK_11, sizeof(CutsceneBatSwarm));

  if (p != NULL) {
    SetEntityRoutine(p, CutsceneBatSwarm_Update, CutsceneBatSwarm_Destroy);
    if (CutsceneBatSwarm_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
