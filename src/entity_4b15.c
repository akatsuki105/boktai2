#include "camera_inline.h"
#include "entity.h"
#include "global.h"
#include "link_session.h"
#include "particle.h"
#include "trig.h"

// 画面の基準点から見て他プレイヤーがいる方向を指すマーカー, 4人分を1枠ずつ持つ
typedef struct {
  u8 state;            // 0x00, 0 非表示, 1 毎フレーム向きを計算し直す, 2 向きは出した時だけ決める
  u8 angle;            // 0x01, gSineTable の添字, Particle の回転量には -0x60 - angle を入れる
  bool8 stateEntered;  // 0x02, state を変えた直後だけ立つ
  u8 unk_3;            // 0x03, どの関数も触っていない
  u32 timer;           // 0x04, 0xB3 を越えると state 0 に戻る, state 1 では下位5bitで点滅させる
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

static Entity4B15* gEntity4B15;  // 0x03000090

static inline void Entity4B15Elem_SetState(Entity4B15Elem* elem, u8 state) {
  elem->state = state;
  elem->timer = 0;
  elem->stateEntered = TRUE;
}

static inline s32 Entity4B15_GetLocalPlayerIdx(void) {
  if (gLinkSession == NULL) {
    return -1;
  }
  return gLinkSession->playerIdx;
}

// 状態に入った最初の呼び出しだけ TRUE, 入場フラグを下ろす
static inline bool8 Entity4B15Elem_ConsumeEnter(Entity4B15Elem* elem) {
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    return TRUE;
  }
  return FALSE;
}

void FUN_08019ae8(void) { gEntity4B15 = NULL; }

void Entity4B15Elem_Init(Entity4B15* p, Entity4B15Elem* elem) {
  Particle* ptcl;

  Entity4B15Elem_SetState(elem, 0);
  elem->angle = 0;
  ptcl = &elem->ptcl;
  Particle_Add(ptcl, p->group, SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE | SPRFLAG_HIDDEN);
  Particle_SetOffset(ptcl, -4, -4);
  Particle_SetPose(ptcl, p->group, PTCL0_ARROW);
  elem->ptcl.priority = 1;
  VEC3_SET(elem->target, 0, 0, 0);
}

void Entity4B15Elem_Destroy(Entity4B15* p, Entity4B15Elem* elem) { Particle_Remove(&elem->ptcl); }

// state 0 (非表示) の更新, 入場時に Particle を隠すだけ
void Entity4B15Elem_UpdateIdle(Entity4B15* p, Entity4B15Elem* elem) {
  if (Entity4B15Elem_ConsumeEnter(elem)) {
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
  }
  elem->timer++;
}

void Entity4B15Elem_UpdateTracking(Entity4B15* p, Entity4B15Elem* elem) {
  Vec3 screen;
  Vec3* s;
  Vec3* origin;
  s32 dx;
  s32 dz;

  Entity4B15Elem_ConsumeEnter(elem);
  WorldToScreen(&screen, &elem->target);
  origin = &p->origin;
  s = &screen;
  elem->angle = ArcTan2_8(s->x - origin->x, s->z - origin->z);
  dx = s->x - origin->x;
  dz = s->z - origin->z;
  if ((u32)(dx * dx + dz * dz) < 0x1000 || (elem->timer & 31) > 16) {
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
  } else {
    elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
    elem->ptcl.pos.x = POLAR_X(50, elem->angle) + 120;
    elem->ptcl.pos.y = POLAR_Z(50, elem->angle) + 80;
    elem->ptcl.pos.z = 0;
    elem->ptcl.rotation = -0x60 - elem->angle;
  }
  if (elem->timer > 179) {
    Entity4B15Elem_SetState(elem, 0);
  }
  elem->timer++;
}

// 向きは出した瞬間に 1 度だけ測る, それ以外は Entity4B15Elem_UpdateTracking と同じ
void Entity4B15Elem_UpdateFixed(Entity4B15* p, Entity4B15Elem* elem) {
  if (Entity4B15Elem_ConsumeEnter(elem)) {
    Vec3 screen;
    Vec3* s;
    Vec3* origin;
    s32 dx;
    s32 dz;

    WorldToScreen(&screen, &elem->target);
    origin = &p->origin;
    s = &screen;
    elem->angle = ArcTan2_8(s->x - origin->x, s->z - origin->z);
    dx = s->x - origin->x;
    dz = s->z - origin->z;
    if ((u32)(dx * dx + dz * dz) < 0x1000 || (elem->timer & 31) > 16) {
      elem->ptcl.flags |= SPRFLAG_HIDDEN;
    } else {
      elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
      elem->ptcl.pos.x = POLAR_X(50, elem->angle) + 120;
      elem->ptcl.pos.y = POLAR_Z(50, elem->angle) + 80;
      elem->ptcl.pos.z = 0;
      elem->ptcl.rotation = -0x60 - elem->angle;
    }
  } else {
    Vec3 screen;
    Vec3* s;
    Vec3* origin;
    s32 dx;
    s32 dz;

    WorldToScreen(&screen, &elem->target);
    origin = &p->origin;
    s = &screen;
    dx = s->x - origin->x;
    dz = s->z - origin->z;
    if ((u32)(dx * dx + dz * dz) < 0x1000 || (elem->timer & 31) > 16) {
      elem->ptcl.flags |= SPRFLAG_HIDDEN;
    } else {
      elem->ptcl.flags &= ~SPRFLAG_HIDDEN;
      elem->ptcl.pos.x = POLAR_X(50, elem->angle) + 120;
      elem->ptcl.pos.y = POLAR_Z(50, elem->angle) + 80;
      elem->ptcl.pos.z = 0;
      elem->ptcl.rotation = -0x60 - elem->angle;
    }
  }
  if (elem->timer >= SECOND(1)) {
    Entity4B15Elem_SetState(elem, 0);
  }
  elem->timer++;
}

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

// 引数を (poseIdx, state) に取る inline で包むと残差は末尾の定数 0 と 1 のレジスタの入れ替わりだけになる
NON_MATCH void Entity4B15_ShowTrackingMarker(s32 playerIdx, Vec3* pos) {
#ifdef NONMATCHING_C
  if (gEntity4B15 != NULL && Entity4B15_GetLocalPlayerIdx() != playerIdx) {
    Entity4B15Elem* elem = &gEntity4B15->elems[playerIdx];

    elem->target = *pos;
    Particle_SetPose(&elem->ptcl, gEntity4B15->group, PTCL0_ARROW);
    Entity4B15Elem_SetState(elem, 1);
  }
#else
  INCFUNC("asm/func/Entity4B15_ShowTrackingMarker.inc");
#endif
}

// 引数を (poseIdx, state) に取る inline で包むと残差は末尾の movs の 2 命令の順序だけになる
NON_MATCH void Entity4B15_ShowFixedMarker(s32 playerIdx, Vec3* pos) {
#ifdef NONMATCHING_C
  if (gEntity4B15 != NULL && Entity4B15_GetLocalPlayerIdx() != playerIdx) {
    Entity4B15Elem* elem = &gEntity4B15->elems[playerIdx];

    elem->target = *pos;
    Particle_SetPose(&elem->ptcl, gEntity4B15->group, PTCL0_ARROW_RED);
    Entity4B15Elem_SetState(elem, 2);
  }
#else
  INCFUNC("asm/func/Entity4B15_ShowFixedMarker.inc");
#endif
}
