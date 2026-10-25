#include "entity.h"
#include "global.h"
#include "particle.h"

// 画面の基準点から見て他プレイヤーがいる方向を指すマーカー, 4人分を1枠ずつ持つ
typedef struct {
  u8 state;            // 0x00, 0 非表示, 1 毎フレーム向きを計算し直す, 2 向きは出した時だけ決める
  u8 angle;            // 0x01, gSineTable の添字, Particle の回転量には -0x60 - angle を入れる
  bool8 stateEntered;  // 0x02, state を変えた直後だけ立つ
  u8 unk_3;            // 0x03, どの関数も触っていない
  s32 timer;           // 0x04, 0xB3 を越えると state 0 に戻る, state 1 では下位5bitで点滅させる
  Particle ptcl;       // 0x08, 追従なら PTCL_GROUP_0 のフレーム 0x33, 固定なら 0x35
  Vec3 target;         // 0x30, 指し示すワールド座標
} Entity4B15Elem;
static_assert(sizeof(Entity4B15Elem) == 56);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_11
  Vec3 origin;              // 0x018, (120, 80, 0), 向きを測る基準点, gCameraVpCoords と同じく x と z だけ使う
  Entity4B15Elem elems[4];  // 0x020, 添字はプレイヤー番号
  ParticleGroup* group;     // 0x100, PTCL_GROUP_0
} Entity4B15;
static_assert(sizeof(Entity4B15) == 260);

IWRAM_DATA Entity4B15* gEntity4B15 = NULL;  // 0x03000090

void FUN_08019ae8(void) { gEntity4B15 = NULL; }

NAKED void Entity4B15Elem_Init(Entity4B15* p, Entity4B15Elem* elem) { INCFUNC("asm/func/Entity4B15Elem_Init.inc"); }

void Entity4B15Elem_Destroy(Entity4B15* p, Entity4B15Elem* elem) { Particle_Remove(&elem->ptcl); }

// state 0 (非表示) の更新, 入場時に Particle を隠すだけ
// 残差5命令, 原典は入場フラグを食ったかどうかを 0/1 に起こしてからもう一度判定する二段形だが agbcc はどの綴りでも分岐に畳む
NON_MATCH void Entity4B15Elem_UpdateIdle(Entity4B15* p, Entity4B15Elem* elem) {
#ifdef NONMATCHING_C
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
  }
  elem->timer++;
#else
  INCFUNC("asm/func/Entity4B15Elem_UpdateIdle.inc");
#endif
}

NAKED void Entity4B15Elem_UpdateTracking(Entity4B15* p, Entity4B15Elem* elem) { INCFUNC("asm/func/Entity4B15Elem_UpdateTracking.inc"); }

NAKED void Entity4B15Elem_UpdateFixed(Entity4B15* p, Entity4B15Elem* elem) { INCFUNC("asm/func/Entity4B15Elem_UpdateFixed.inc"); }

s32 Entity4B15_Update(Entity4B15* p) {
  void (*const handlers[3])(Entity4B15*, Entity4B15Elem*) = {
      Entity4B15Elem_UpdateIdle,
      Entity4B15Elem_UpdateTracking,
      Entity4B15Elem_UpdateFixed,
  };
  Entity4B15Elem* e = p->elems;
  s32 i;

  for (i = 0; i < 4; i++, e++) {
    handlers[e->state](p, e);
  }
  return 0;
}

s32 Entity4B15_Destroy(Entity4B15* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Entity4B15Elem_Destroy(p, &p->elems[i]);
  }
  gEntity4B15 = NULL;
  return 0;
}

s32 Entity4B15_Init(Entity4B15* p) {
  s32 i;

  gEntity4B15 = p;
  p->group = GetParticleGroup(PTCL_GROUP_0);
  VEC3_SET(p->origin, 120, 80, 0);

  for (i = 0; i < 4; i++) {
    Entity4B15Elem_Init(p, &p->elems[i]);
  }
  return 0;
}

Entity4B15* Entity4B15_Create(void) {
  if (gEntity4B15 == NULL) {
    Entity4B15* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity4B15));

    if (p != NULL) {
      SetEntityRoutine(p, Entity4B15_Update, Entity4B15_Destroy);
      if (Entity4B15_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity4B15;
}

NAKED void Entity4B15_ShowTrackingMarker(s32 playerIdx, Vec3* pos) { INCFUNC("asm/func/Entity4B15_ShowTrackingMarker.inc"); }

NAKED void Entity4B15_ShowFixedMarker(s32 playerIdx, Vec3* pos) { INCFUNC("asm/func/Entity4B15_ShowFixedMarker.inc"); }
