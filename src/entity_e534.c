#include "entity.h"
#include "file.h"
#include "global.h"
#include "inline.h"
#include "mover.h"
#include "msgbus.h"
#include "random.h"
#include "shadow.h"
#include "sprite_aux.h"
#include "sprite_pltt.h"
#include "trig.h"
#include "vec3.h"
#include "video.h"

typedef struct {
  bool8 active;           // 0x00, EntityE534Elem_Init が 1 を入れる, 各 UpdateState 関数は 0 以外なら状態の入り口の処理をして 0 に落とす
  u8 state;               // 0x01, sElemUpdates の添字, EntityE534Elem_Init が 0 を入れ、各 UpdateState 関数が次の番号を書く
  bool8 animFinished;     // 0x02, 直前の更新でアニメが一巡したか
  u8 bobPhase;            // 0x03, 上下に揺らす sin の位相, 毎フレーム 4 進む
  u16 unk_04;             // 0x04, EntityE534Elem_Init が 0 を入れる
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
} EntityE534Elem;
static_assert(sizeof(EntityE534Elem) == 200);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_11
  u32 unk_18;                // 0x018, _Init が 0 を入れる, 0 の間は Update が要素を動かさない
  u32 frameCount;            // 0x01C, 要素を動かしたフレーム数
  AuxAnimFile* anim;         // 0x020, ANIM_BAT
  EntityE534Elem elems[16];  // 0x024
  s8 fadeDir;                // 0xCA4, pltt のブレンドの向き (0: 63 まで上げる, 1: 0 まで下げる, 2: 32 まで上げる, 負: 止める)
  s8 fadeLevel;              // 0xCA5, BlendPltt の t
  u16 unk_ca6;               // 0xCA6, _Init が 0 を入れる, 0 でなければ Update が Mover_FindByID_Proxy で引いて unk_cc8 に入れる
  rgb555 pltt[16];           // 0xCA8, BlendPltt(&pltt, gObjPlttData+0x2630, gObjPlttData+0x2650, 0x40, 6), elems[i].gfx.pltt がここを指す
  Mover* unk_cc8;            // 0xCC8, _Init が 0 を入れる
  Vec3 center;               // 0xCCC, 要素が向きを向ける中心の座標
  MsgQueue mq;               // 0xCD4
} EntityE534;
static_assert(sizeof(EntityE534) == 3336);

void LerpVec3(Vec3* dst, Vec3* a, Vec3* b, s32 t, s32 shift);

// 4 方向の向き dir を左右反転とアニメの variant に分ける
static inline void EntityE534_GetAnimVariant(u8 dir, u8* variant, u8* xflip) {
  if (dir == 1 || dir == 2) {
    *variant = 1;
  } else {
    *variant = 0;
  }
  if (dir > 1) {
    *xflip = TRUE;
  } else {
    *xflip = FALSE;
  }
}

// 要素1つ分のスプライトと影を用意して, 状態を0番から始める
// 残差: 先頭の 0 の書き込みで state と angle が使う 0 のレジスタ (原典 r1) と unk_04 と CpuFill32 が使う 0 (原典 r6) の組み合わせが違う, 命令数は一致
NON_MATCH s32 EntityE534Elem_Init(EntityE534* p, EntityE534Elem* e, s32 idx) {
#ifdef NONMATCHING_C
  AuxSpriteGfx* gfx;
  AuxSprite* sprite;

  e->state = 0;
  e->active = TRUE;
  e->unk_04 = 0;
  e->angle = 0;
  gfx = &e->gfx;
  Video_GetAuxSprite(gfx, SPRITE_BAT);
  Video_SetAuxSpritePltt(gfx, 611);
  gfx->pltt = p->pltt;
  sprite = &e->sprite;
  AuxSprite_Add(sprite, gfx, SPRFLAG_HIDDEN);
  sprite->priority = 2;
  CpuFill32(0, &sprite->pos, sizeof(Vec3));
  ParticleShadow_Init(&e->shadow, &sprite->pos, 0);
  ParticleShadow_Hide(&e->shadow);
#else
  INCFUNC("asm/func/EntityE534Elem_Init.inc");
#endif
}

// 要素の影とスプライトを描画リストから外す
s32 EntityE534Elem_Destroy(EntityE534* p, EntityE534Elem* e, s32 idx) {
  ParticleShadow_Remove(&e->shadow);
  AuxSprite_Remove(&e->sprite);
}

// 要素の向きから象限を出して, アニメーションの variant と左右反転をそれで決めて再生を始める
void EntityE534Elem_SetAnim(EntityE534* p, EntityE534Elem* e, s32 animIdx) {
  u8 variant;
  u8 xflip;

  EntityE534_GetAnimVariant(Angle_ToDir4(e->angle), &variant, &xflip);
  AuxAnim_SetAnim(&e->anim, p->anim, animIdx, variant, xflip);
}

// pos をスプライトへ写してアニメを進め, 高さを baseY へ寄せながら上下に揺らす
void EntityE534Elem_UpdateSprite(EntityE534Elem* e) {
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
// 残差: 原典は要素のポインタを2本 (r4/r6) 持ち, i と spread をスタックに逃がす, こちらは1本で4命令短い
NON_MATCH s32 EntityE534_HandleCmd0(EntityE534* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  Vec3 center;
  s32 i;
  s32 speed;
  s32 dist;
  s32 targetDist;
  s32 angle;
  s32 spread;
  EntityE534Elem* e;

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
    e->active = TRUE;
    e->unk_04 = 0;
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
    EntityE534Elem_SetAnim(p, e, 0);
    Video_SetAuxSpritePltt(&e->gfx, 611);
    e->gfx.pltt = p->pltt;
    ParticleShadow_Show(&e->shadow);
  }
  p->unk_18 = 1;
  return 0;
#else
  INCFUNC("asm/func/EntityE534_HandleCmd0.inc");
#endif
}

// 全要素を args の中心の周りに並べて state 0 から動かし始め, パレットを暗い側から戻していく
// 残差: 原典は要素のポインタを2本 (r4/r6) 持ち, i と spread をスタックに逃がす, こちらは1本で4命令短い
NON_MATCH s32 EntityE534_HandleCmd1(EntityE534* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  Vec3 center;
  s32 i;
  s32 speed;
  s32 dist;
  s32 targetDist;
  s32 angle;
  s32 spread;
  EntityE534Elem* e;

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
    e->active = TRUE;
    e->unk_04 = 0;
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
    EntityE534Elem_SetAnim(p, e, 0);
    Video_SetAuxSpritePltt(&e->gfx, 611);
    e->gfx.pltt = p->pltt;
    ParticleShadow_Show(&e->shadow);
  }
  p->unk_18 = 1;
  return 0;
#else
  INCFUNC("asm/func/EntityE534_HandleCmd1.inc");
#endif
}

// args[0] の Mover の今の位置へ向けて全要素を飛ばし始める
// 残差: 原典は ArcTan2_8 の結果を書いたレジスタのまま (結果 - 16) + 乱数 にするが, こちらは angle を読み直す, p と e のレジスタ (r5/r6) と巻き上げた乱数定数の割当も逆
NON_MATCH s32 EntityE534_HandleCmd2(EntityE534* p, MsgQueue* mq, MsgPacket* msg) {
#ifdef NONMATCHING_C
  Mover* m;
  s32 speed;
  Vec3 target;
  EntityE534Elem* e;
  s32 i;

  p->unk_ca6 = msg->args[0];
  m = Mover_FindByID_Proxy(p->unk_ca6);
  if (m == NULL) {
    return -1;
  }
  target = m->pos;
  speed = msg->args[1];
  p->frameCount = 0;
  e = p->elems;
  for (i = 0; i < 16; i++, e++) {
    e->state = 3;
    e->active = TRUE;
    e->unk_04 = 0;
    e->target = target;
    e->angle = ArcTan2_8(e->target.x - e->pos.x, e->target.z - e->pos.z);
    e->angle += (RandomNext() & 31) - 16;
    e->speed = speed;
    e->moveTime = (RandomNext() & 7) + 7;
  }
  p->unk_18 = 1;
  return 0;
#else
  INCFUNC("asm/func/EntityE534_HandleCmd2.inc");
#endif
}

// 届いたメッセージを cmd ごとの処理に振り分ける
// 残差: 原典はループ入口で gMsgBus のアドレスを毎回プールから読み直すが, こちらは1本のレジスタに載せて1命令短い (Entity8EC8_HandleMessages と同系統)
NON_MATCH s32 EntityE534_HandleMsgs(EntityE534* p) {
#ifdef NONMATCHING_C
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        EntityE534_HandleCmd0(p, mq, msg);
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
      case 1: {
        EntityE534_HandleCmd1(p, mq, msg);
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
      case 2: {
        EntityE534_HandleCmd2(p, mq, msg);
        MsgQueue_EndWait(&p->mq, 1);
        break;
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/EntityE534_HandleMsgs.inc");
#endif
}

void EntityE534Elem_UpdateState0(EntityE534* p, EntityE534Elem* e, s32 idx) {
  Vec3 vel;

  if (e->active) {
    e->active = FALSE;
  }
  Vec3_SetPolar(&vel, e->angle, e->speed * 2);
  Vec3_Add(&e->pos, &vel);
  EntityE534Elem_SetAnim(p, e, 0);
  if (e->unk_04 >= idx + 2) {
    e->state = 1;
    e->active = TRUE;
    e->unk_04 = 0;
  }
  e->unk_04++;
}

// state 2, 目標から左右に 64 前後ずれた向きへ少し飛び, center の方を向く
// 残差: 原典は乱数を先に引いてから moveAngle を ldrb で読んで足し引きするが, こちらは moveAngle を先に ldrsb で読む
NON_MATCH void EntityE534Elem_UpdateState2(EntityE534* p, EntityE534Elem* e, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vel;

  if (e->active) {
    e->active = FALSE;
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
    e->angle = ArcTan2_8(p->center.x - e->pos.x, p->center.z - e->pos.z);
    e->moveTime--;
  }
  EntityE534Elem_SetAnim(p, e, 0);
  if (e->unk_04 > 95) {
    e->state = 1;
    e->active = TRUE;
    e->unk_04 = 0;
  }
  e->unk_04++;
#else
  INCFUNC("asm/func/EntityE534Elem_UpdateState2.inc");
#endif
}

// state 1, center の方を向いたまま target へ向きを散らしながら近づき, 200 以内に入ったら state 2 へ移る
// 残差: 乱数で向きを散らす所で, 原典は乱数を引いてから angle を ldrb で読む (EntityE534Elem_UpdateState6 と同じ壁)
NON_MATCH void EntityE534Elem_UpdateState1(EntityE534* p, EntityE534Elem* e, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vel;
  s32 dx;
  s32 dz;

  if (e->active) {
    e->active = FALSE;
    e->angle = ArcTan2_8(p->center.x - e->pos.x, p->center.z - e->pos.z);
    e->moveAngle = ArcTan2_8(e->target.x - e->pos.x, e->target.z - e->pos.z);
    e->moveAngle += (RandomNext() & 31) - 16;
    e->moveTime = (RandomNext() & 15) + 16;
  }
  dx = e->target.x - e->pos.x;
  dz = e->target.z - e->pos.z;
  if (dx * dx + dz * dz < 40000) {
    e->state = 2;
    e->active = TRUE;
    e->unk_04 = 0;
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
  e->angle = ArcTan2_8(p->center.x - e->pos.x, p->center.z - e->pos.z);
  EntityE534Elem_SetAnim(p, e, 0);
  e->unk_04++;
#else
  INCFUNC("asm/func/EntityE534Elem_UpdateState1.inc");
#endif
}

// state 3, unk_cc8 の Mover へ向きを散らしながら近づき, 64 以内に入ったら state 4 へ移る
// 残差: 乱数で向きを散らす所で, 原典は乱数を引いてから angle を ldrb で読む (EntityE534Elem_UpdateState6 と同じ壁)
NON_MATCH void EntityE534Elem_UpdateState3(EntityE534* p, EntityE534Elem* e, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3* pos;
  Vec3* target;
  s32 dx;
  s32 dz;

  if (p->unk_cc8 != NULL) {
    e->target = p->unk_cc8->pos;
  }
  pos = &e->pos;
  target = &e->target;
  if (e->active) {
    e->active = FALSE;
    e->angle = ArcTan2_8(target->x - pos->x, target->z - pos->z);
    e->angle += (RandomNext() & 31) - 16;
    e->moveTime = (RandomNext() & 15) + 16;
  }
  if (e->moveTime == 0) {
    e->angle = ArcTan2_8(target->x - pos->x, target->z - pos->z);
    e->angle += (RandomNext() & 15) - 8;
    e->moveTime = (RandomNext() & 15) + 16;
  } else {
    e->moveTime--;
  }
  dx = target->x - pos->x;
  dz = target->z - pos->z;
  if (dx * dx + dz * dz < 4096) {
    e->state = 4;
    e->active = TRUE;
    e->unk_04 = 0;
    return;
  }
  Vec3_SetPolar(&vel, e->angle, e->speed);
  Vec3_Add(pos, &vel);
  EntityE534Elem_SetAnim(p, e, 0);
  e->unk_04++;
#else
  INCFUNC("asm/func/EntityE534Elem_UpdateState3.inc");
#endif
}

// state 4, 周回の中心を target へ寄せながら, その周りを向きを散らしつつ飛び回る
// 残差: 乱数で向きを散らす所で, 原典は乱数を引いてから angle を ldrb で読む (EntityE534Elem_UpdateState6 と同じ壁)
NON_MATCH void EntityE534Elem_UpdateState4(EntityE534* p, EntityE534Elem* e, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vel;

  if (p->unk_cc8 != NULL) {
    e->target = p->unk_cc8->pos;
  }
  if (e->active) {
    e->active = FALSE;
    e->orbitCenter = e->pos;
    e->angle = Random();
    CpuFill32(0, &e->orbitOffset, sizeof(Vec3));
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
  EntityE534Elem_SetAnim(p, e, 0);
  e->unk_04++;
#else
  INCFUNC("asm/func/EntityE534Elem_UpdateState4.inc");
#endif
}

void EntityE534Elem_UpdateState5(EntityE534* p, EntityE534Elem* e, s32 idx) {
  Vec3 vel;

  if (e->active) {
    e->active = FALSE;
  }
  Vec3_SetPolar(&vel, e->angle, e->speed * 2);
  Vec3_Add(&e->pos, &vel);
  EntityE534Elem_SetAnim(p, e, 0);
  if (e->unk_04 >= idx + 2) {
    e->state = 6;
    e->active = TRUE;
    e->unk_04 = 0;
  }
  e->unk_04++;
}

// state 6, target へ向きを少し散らしながら近づき, 200 以内に入ったら state 2 へ移る
// 残差: 原典は乱数を引いてから angle を ldrb で読み (angle - 16) + 乱数 にする, 乱数を文式 ({ }) にすると読む順だけ揃う, pos のポインタを r7 に持つ割当も違う
NON_MATCH void EntityE534Elem_UpdateState6(EntityE534* p, EntityE534Elem* e, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vel;
  s32 dx;
  s32 dz;

  if (e->active) {
    e->active = FALSE;
    e->angle = ArcTan2_8(e->target.x - e->pos.x, e->target.z - e->pos.z);
    e->angle += (RandomNext() & 31) - 16;
    e->moveTime = (RandomNext() & 15) + 16;
  }
  dx = e->target.x - e->pos.x;
  dz = e->target.z - e->pos.z;
  if (dx * dx + dz * dz < 40000) {
    e->state = 2;
    e->active = TRUE;
    e->unk_04 = 0;
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
  EntityE534Elem_SetAnim(p, e, 0);
  e->unk_04++;
#else
  INCFUNC("asm/func/EntityE534Elem_UpdateState6.inc");
#endif
}

static void (*const sElemUpdates[7])(EntityE534*, EntityE534Elem*, s32) = {
    EntityE534Elem_UpdateState0,
    EntityE534Elem_UpdateState1,
    EntityE534Elem_UpdateState2,
    EntityE534Elem_UpdateState3,
    EntityE534Elem_UpdateState4,
    EntityE534Elem_UpdateState5,
    EntityE534Elem_UpdateState6,
};  // 0x085AA81C

s32 EntityE534_Update(EntityE534* p) {
  EntityE534Elem* e;
  s32 i;

  EntityE534_HandleMsgs(p);
  if (p->unk_18 == 0) {
    return 0;
  }
  if (p->unk_ca6 != 0) {
    p->unk_cc8 = Mover_FindByID_Proxy(p->unk_ca6);
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
    EntityE534Elem_UpdateSprite(e);
  }
  p->frameCount++;
  return 0;
}

s32 EntityE534_Destroy(EntityE534* p) {
  EntityE534Elem* e = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, e++) {
    EntityE534Elem_Destroy(p, e, i);
  }

  MsgQueue_Unregister(&p->mq);
  return 0;
}

s32 EntityE534_Init(EntityE534* p, u32 id) {
  EntityE534Elem* e;
  s32 i;

  p->unk_18 = 0;
  p->unk_ca6 = 0;
  p->unk_cc8 = NULL;
  p->anim = GetFile(DIR_ANIMATION, ANIM_BAT);
  {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[613 * 16];

    BlendPltt(p->pltt, src1, src2, 64, 6);
  }
  e = p->elems;
  for (i = 0; i < 16; i++, e++) {
    EntityE534Elem_Init(p, e, i);
  }
  MsgQueue_Register(&p->mq, id, 10);
  return 0;
}

EntityE534* EntityE534_Create(u32 id) {
  EntityE534* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityE534));

  if (p != NULL) {
    SetEntityRoutine(p, EntityE534_Update, EntityE534_Destroy);
    if (EntityE534_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
