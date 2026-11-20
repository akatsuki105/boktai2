#include "entity.h"
#include "global.h"
#include "random.h"
#include "sprite_aux.h"
#include "vec3.h"

// ドゥラスロールの花びら?

// SPR_DUNEYRR_AUX の poseIdx
#define POSE_PETAL(idx) (54 + (idx))

// Entity080601a8 が持つ粒子1個, Entity080601a8_Spawn が角度と速度を与えて飛ばし、
// Entity080601a8_StateFly が毎フレーム sprite.pos を動かして lifetime で解放する
typedef struct Entity080601a8Elem {
  u8 state;          // 0x00, sEntity080601a8States の添字 (0 = 何もしない, 1 = 飛行中)
  bool8 stateBegun;  // 0x01, 立っていると次の state 1 の更新で angleStep などを決めて落とす
  u16 timer;         // 0x02, 毎フレーム +1
  s16 speed;         // 0x04, gSineTable との積が移動量になる
  s16 velY;          // 0x06, 毎フレーム sprite.pos.y に加算される
  s8 angle;          // 0x08, gSineTable の添字 (向き), 毎フレーム angleStep が足される
  s8 angleStep;      // 0x09, state 1 の最初の更新で (rand & 3) - 2
  u8 pose;           // 0x0A, 0..3, POSE_PETAL(pose), 生成時は乱数, poseDuration ごとに乱数で 1 か 2 進める
  u8 poseTimer;      // 0x0B, 毎フレーム +1、 poseDuration に達したら pose を進めて0に戻す
  u8 poseDuration;   // 0x0C, state 1 の最初の更新で (rand & 3) + 7
  u8 unk_d;          // 0x0D, Entity080601a8_Spawn の第6引数が入る, 読み手は未発見
  u16 lifetime;      // 0x0E, timer がこれ以上になると解放される
  AuxSprite sprite;  // 0x10
} Entity080601a8Elem;
static_assert(sizeof(Entity080601a8Elem) == 60);

// 粒子を32個まで抱えるエンティティ, 空きスロットは activeMask のビットで管理する
typedef struct Entity080601a8 {
  Entity e;                      // 0x00, ENTITY_UNK_8
  u32 unk_18;                    // 0x18, 読み手も書き手も未発見
  u32 activeMask;                // 0x1C, 1 << i で elems[i] が使用中
  u32 unk_20;                    // 0x20, 読み手も書き手も未発見
  u32 unk_24;                    // 0x24, 読み手も書き手も未発見
  AuxSpriteGfx gfx;              // 0x28, SPR_DUNEYRR_AUX
  Entity080601a8Elem elems[32];  // 0x44
} Entity080601a8;
static_assert(sizeof(Entity080601a8) == 1988);

// スロットを飛行前の状態に戻す
void Entity080601a8_InitElem(Entity080601a8* p, Entity080601a8Elem* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  elem->state = 0;
  elem->stateBegun = 1;
  elem->timer = 0;
  elem->angle = 0;
  elem->speed = 0;
  elem->velY = 0;
  elem->angleStep = 0;
  AuxSprite_Setup(sprite, &p->gfx, 0);
  sprite->poseIdx = POSE_PETAL(0);
}

void Entity080601a8_ReleaseElem(Entity080601a8* p, Entity080601a8Elem* elem, s32 idx) {
  AuxSprite_Remove(&elem->sprite);
  p->activeMask &= ~(1 << idx);
}

void Entity080601a8_StateIdle(Entity080601a8* p, Entity080601a8Elem* elem, s32 idx) {}

// state 1, 向きを少しずつ回しながら飛んで y は velY ずつ動き, poseDuration ごとに絵柄と左右反転を乱数で替え, lifetime で枠を空ける
// 177/177命令, 残差は2回目と3回目の乱数で乱数表の番地を読み直すか前のものを使い回すかの割り当てだけ
// 試済: pose 送りの三項演算子の向き (< 128 ? 1 : 2 で分岐は揃う), 送りを if/else と局所変数で, (u8) キャスト, flip を RandomNext, 効いた手: 位置は Vec3_Sum(&pos, &d, &pos)
NON_MATCH void Entity080601a8_StateFly(Entity080601a8* p, Entity080601a8Elem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3 d;

  if (elem->stateBegun) {
    elem->stateBegun = 0;
    elem->angleStep = (RandomNext() & 3) - 2;
    elem->poseTimer = 0;
    elem->poseDuration = (RandomNext() & 3) + 7;
  }
  elem->angle += elem->angleStep;
  Vec3_SetPolar(&d, elem->angle, elem->speed);
  d.y = elem->velY;
  Vec3_Sum(&sprite->pos, &d, &sprite->pos);
  if (++elem->poseTimer >= elem->poseDuration) {
    bool32 flip;

    elem->pose = (elem->pose + ((Random() & 0xFF) < 128 ? 1 : 2)) & 3;
    flip = (Random() & 0xFF) > 127 ? TRUE : FALSE;
    elem->sprite.poseIdx = POSE_PETAL(elem->pose);
    if (flip) {
      elem->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      elem->sprite.flags &= ~SPRFLAG_XFLIP;
    }
    elem->poseTimer = 0;
  }
  if (elem->timer >= elem->lifetime) {
    Entity080601a8_ReleaseElem(p, elem, idx);
    elem->state = 0;
    elem->stateBegun = 1;
    elem->timer = 0;
  }
#else
  INCFUNC("asm/func/Entity080601a8_StateFly.inc");
#endif
}

s32 Entity080601a8_Update(Entity080601a8* p) {
  static void (*const sEntity080601a8States[2])(Entity080601a8*, Entity080601a8Elem*, s32) = {
      Entity080601a8_StateIdle,
      Entity080601a8_StateFly,
  };  // 0x085ABAA4

  Entity080601a8Elem* e = p->elems;
  s32 i;

  for (i = 0; i < 32; i++, e++) {
    if (p->activeMask & 1 << i) {
      sEntity080601a8States[e->state](p, e, i);
      e->timer++;
    }
  }
  return 0;
}

s32 Entity080601a8_Destroy(Entity080601a8* p) {
  Entity080601a8Elem* e = p->elems;
  s32 i;

  for (i = 0; i < 32; i++, e++) {
    if (p->activeMask & (1 << i)) {
      Entity080601a8_ReleaseElem(p, e, i);
    }
  }

  return 0;
}

s32 Entity080601a8_Init(Entity080601a8* p, s32 plttID, rgb555* pltt) {
  Entity080601a8Elem* e;
  s32 i;

  p->activeMask = 0;
  Video_GetAuxSprite(&p->gfx, SPR_DUNEYRR_AUX);
  Video_SetAuxSpritePltt(&p->gfx, 758);
  if (pltt != NULL) {
    p->gfx.plttID = plttID;
    p->gfx.pltt = pltt;
  }

  for (e = p->elems, i = 0; i < 32; i++, e++) {
    Entity080601a8_InitElem(p, e, i);
  }
  return 0;
}

Entity080601a8* Entity080601a8_Create(s32 plttID, rgb555* pltt) {
  Entity080601a8* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity080601a8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080601a8_Update, Entity080601a8_Destroy);
    if (Entity080601a8_Init(p, plttID, pltt) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// 空きスロットを探して添字を *outIdx に入れて返す
Entity080601a8Elem* Entity080601a8_FindFreeElem(Entity080601a8* p, u32* outIdx) {
  Entity080601a8Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 32; i++, elem++) {
    if (!(p->activeMask & (1 << i))) {
      *outIdx = i;
      return elem;
    }
  }

  *outIdx = 0;
  return NULL;
}

// 空いている枠に花びらを1枚出して pos から angle の向きへ飛ばす, 絵柄と左右反転は乱数で決める, 枠がなければ -1
// 96/96命令, 残差は引数を写すレジスタの順だけ, 原典は p を r6 に velY を r8 に置くが, こちらは p を r8 に置く (CrashNoiseRingManager_Spawn と同じ形)
// 試済: elem の宣言の初期化, flags を sprite 経由, 表示と描画リスト追加の inline, 効いた手: poseIdx は AuxSprite_SetPoseIdx(&elem->sprite, ...), flags は elem->sprite 直書き
NON_MATCH s32 Entity080601a8_Spawn(Entity080601a8* p, u32 angle, s32 speed, s32 velY, s32 lifetime, u32 unk_d, Vec3* pos) {
#ifdef NONMATCHING_C
  Entity080601a8Elem* elem;
  u32 idx;
  bool32 flip;

  elem = Entity080601a8_FindFreeElem(p, &idx);
  if (elem == NULL) {
    return -1;
  }
  elem->state = 1;
  elem->stateBegun = 1;
  elem->timer = 0;
  elem->lifetime = lifetime;
  elem->angle = angle;
  elem->speed = speed;
  elem->velY = velY;
  elem->sprite.pos = *pos;
  elem->pose = RandomNext() & 3;
  flip = (RandomNext() & 0xFF) > 127 ? TRUE : FALSE;
  elem->unk_d = unk_d;
  AuxSprite_SetPoseIdx(&elem->sprite, POSE_PETAL(elem->pose));
  if (flip) {
    elem->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    elem->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  Video_AddAuxSpriteIntoDrawList(&elem->sprite, 0);
  p->activeMask |= 1 << idx;
  return 0;
#else
  INCFUNC("asm/func/Entity080601a8_Spawn.inc");
#endif
}
