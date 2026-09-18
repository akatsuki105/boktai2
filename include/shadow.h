#ifndef __INCLUDE_SHADOW_H__
#define __INCLUDE_SHADOW_H__

#include "gba/gba.h"
#include "particle.h"
#include "types.h"

// 持ち主の足元に置く影, ParticleShadowManager がリストで管理して毎フレーム fn を呼ぶ
// AuxShadow と違って"しょぼい"影
typedef struct ParticleShadow {
  u8 active;                    // 0x00, ParticleShadowManager_Add でリストに入れると 1, ParticleShadowManager_Remove で外すと 0
  u8 q_kind;                    // 0x01, 0 なら fn = ParticleShadow_FollowGround (床に追従), それ以外は ParticleShadow_UpdateNone (何もしない)
  u8 q_flags;                   // 0x02, bit0: ParticleShadow_FollowGround で当たり判定マップでなく q_pos->y を高さに使う
  u8 unk_03;                    // 0x03
  u16 unk_04;                   // 0x04, ParticleShadow_Init で 0
  u16 unk_06;                   // 0x06, ParticleShadow_Init で 0
  Vec3* q_pos;                  // 0x08, 持ち主の座標
  Particle particle;            // 0x0C
  void* fn;                     // 0x34, ParticleShadowManager_Update が影を引数にして呼ぶ
  struct ParticleShadow* prev;  // 0x38
  struct ParticleShadow* next;  // 0x3C
} ParticleShadow;
static_assert(sizeof(ParticleShadow) == 64);  // ScriptShadowManager の要素 (Malloc(0x54)) で +0x0C から +0x4C (prev) まで

s32 ParticleShadow_Init(ParticleShadow* shadow, Vec3* ownerPos, s32 kind);
void ParticleShadow_UpdateNone(ParticleShadow* shadow);
s32 ParticleShadow_Remove(ParticleShadow* shadow);
void ParticleShadow_Show(ParticleShadow* shadow);
void ParticleShadow_Hide(ParticleShadow* shadow);

#endif  // __INCLUDE_SHADOW_H__
