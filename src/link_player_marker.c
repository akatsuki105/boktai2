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
} LinkPlayerMarkerElem;
static_assert(sizeof(LinkPlayerMarkerElem) == 56);

typedef struct {
  Entity e;                       // 0x000, ENTITY_UNK_11
  Vec3 origin;                    // 0x018, (120, 80, 0), 向きを測る基準点, gCameraVpCoords と同じく x と z だけ使う
  LinkPlayerMarkerElem elems[4];  // 0x020, 添字はプレイヤー番号
  ParticleGroup* group;           // 0x100, PTCL_GROUP_0
} LinkPlayerMarker;
static_assert(sizeof(LinkPlayerMarker) == 260);

static LinkPlayerMarker* gLinkPlayerMarker;  // 0x03000090

static inline void LinkPlayerMarkerElem_SetState(LinkPlayerMarkerElem* elem, u8 state) {
  elem->state = state;
  elem->timer = 0;
  elem->stateEntered = TRUE;
}

static inline s32 LinkPlayerMarker_GetLocalPlayerIdx(void) {
  if (gLinkSession == NULL) {
    return -1;
  }
  return gLinkSession->playerIdx;
}

// 状態に入った最初の呼び出しだけ TRUE, 入場フラグを下ろす
static inline bool8 LinkPlayerMarkerElem_ConsumeEnter(LinkPlayerMarkerElem* elem) {
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    return TRUE;
  }
  return FALSE;
}

void LinkPlayerMarker_ClearInstance(void) { gLinkPlayerMarker = NULL; }

void LinkPlayerMarkerElem_Init(LinkPlayerMarker* p, LinkPlayerMarkerElem* elem) {
  Particle* ptcl;

  LinkPlayerMarkerElem_SetState(elem, 0);
  elem->angle = 0;
  ptcl = &elem->ptcl;
  Particle_Add(ptcl, p->group, SPRFLAG_SCREEN_COORD | SPRFLAG_AFFINE | SPRFLAG_HIDDEN);
  Particle_SetOffset(ptcl, -4, -4);
  Particle_SetPose(ptcl, p->group, PTCL0_ARROW);
  elem->ptcl.priority = 1;
  VEC3_SET(elem->target, 0, 0, 0);
}

void LinkPlayerMarkerElem_Destroy(LinkPlayerMarker* p, LinkPlayerMarkerElem* elem) { Particle_Remove(&elem->ptcl); }

// state 0 (非表示) の更新, 入場時に Particle を隠すだけ
void LinkPlayerMarkerElem_UpdateIdle(LinkPlayerMarker* p, LinkPlayerMarkerElem* elem) {
  if (LinkPlayerMarkerElem_ConsumeEnter(elem)) {
    elem->ptcl.flags |= SPRFLAG_HIDDEN;
  }
  elem->timer++;
}

void LinkPlayerMarkerElem_UpdateTracking(LinkPlayerMarker* p, LinkPlayerMarkerElem* elem) {
  Vec3 screen;
  Vec3* s;
  Vec3* origin;
  s32 dx;
  s32 dz;

  LinkPlayerMarkerElem_ConsumeEnter(elem);
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
    LinkPlayerMarkerElem_SetState(elem, 0);
  }
  elem->timer++;
}

// 向きは出した瞬間に 1 度だけ測る, それ以外は LinkPlayerMarkerElem_UpdateTracking と同じ
void LinkPlayerMarkerElem_UpdateFixed(LinkPlayerMarker* p, LinkPlayerMarkerElem* elem) {
  if (LinkPlayerMarkerElem_ConsumeEnter(elem)) {
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
    LinkPlayerMarkerElem_SetState(elem, 0);
  }
  elem->timer++;
}

s32 LinkPlayerMarker_Update(LinkPlayerMarker* p) {
  void (*const handlers[3])(LinkPlayerMarker*, LinkPlayerMarkerElem*) = {
      LinkPlayerMarkerElem_UpdateIdle,
      LinkPlayerMarkerElem_UpdateTracking,
      LinkPlayerMarkerElem_UpdateFixed,
  };
  LinkPlayerMarkerElem* e = p->elems;
  s32 i;

  for (i = 0; i < 4; i++, e++) {
    handlers[e->state](p, e);
  }
  return 0;
}

s32 LinkPlayerMarker_Destroy(LinkPlayerMarker* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    LinkPlayerMarkerElem_Destroy(p, &p->elems[i]);
  }
  gLinkPlayerMarker = NULL;
  return 0;
}

s32 LinkPlayerMarker_Init(LinkPlayerMarker* p) {
  s32 i;

  gLinkPlayerMarker = p;
  p->group = GetParticleGroup(PTCL_GROUP_0);
  VEC3_SET(p->origin, 120, 80, 0);

  for (i = 0; i < 4; i++) {
    LinkPlayerMarkerElem_Init(p, &p->elems[i]);
  }
  return 0;
}

LinkPlayerMarker* LinkPlayerMarker_Create(void) {
  if (gLinkPlayerMarker == NULL) {
    LinkPlayerMarker* p = CreateEntity(ENTITY_UNK_11, sizeof(LinkPlayerMarker));

    if (p != NULL) {
      SetEntityRoutine(p, LinkPlayerMarker_Update, LinkPlayerMarker_Destroy);
      if (LinkPlayerMarker_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gLinkPlayerMarker;
}

// playerIdx 番のプレイヤーを指す矢印のマーカーを pos に出して追わせる, 自分自身には出さない
void LinkPlayerMarker_ShowTracking(s32 playerIdx, Vec3* pos) {
  if (gLinkPlayerMarker != NULL && LinkPlayerMarker_GetLocalPlayerIdx() != playerIdx) {
    LinkPlayerMarkerElem* elem = &gLinkPlayerMarker->elems[playerIdx];

    elem->target = *pos;
    Particle_SetPose(&elem->ptcl, gLinkPlayerMarker->group, PTCL0_ARROW);
    LinkPlayerMarkerElem_SetState(elem, 1);
  }
}

// playerIdx 番のプレイヤーを指す赤い矢印のマーカーを pos に止めて出す, 自分自身には出さない
void LinkPlayerMarker_ShowFixed(s32 playerIdx, Vec3* pos) {
  if (gLinkPlayerMarker != NULL && LinkPlayerMarker_GetLocalPlayerIdx() != playerIdx) {
    LinkPlayerMarkerElem* elem = &gLinkPlayerMarker->elems[playerIdx];

    elem->target = *pos;
    Particle_SetPose(&elem->ptcl, gLinkPlayerMarker->group, PTCL0_ARROW_RED);
    LinkPlayerMarkerElem_SetState(elem, 2);
  }
}
