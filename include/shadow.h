#ifndef __INCLUDE_SHADOW_H__
#define __INCLUDE_SHADOW_H__

#include "gba/gba.h"
#include "particle.h"
#include "sprite_aux.h"
#include "types.h"

// 持ち主の足元に置く影, ParticleShadowManager がリストで管理して毎フレーム fn を呼ぶ
// AuxShadow と違って"しょぼい"影
typedef struct ParticleShadow {
  u8 active;                                       // 0x00, ParticleShadowManager_Add でリストに入れると 1, ParticleShadowManager_Remove で外すと 0
  u8 q_kind;                                       // 0x01, 0 なら fn = ParticleShadow_FollowGround (床に追従), それ以外は ParticleShadow_UpdateNone (何もしない)
  u8 q_flags;                                      // 0x02, bit0: ParticleShadow_FollowGround で当たり判定マップでなく pos->y を高さに使う
  u8 unk_03;                                       // 0x03
  u16 unk_04;                                      // 0x04, ParticleShadow_Init で 0
  u16 unk_06;                                      // 0x06, ParticleShadow_Init で 0
  Vec3* pos;                                       // 0x08, 持ち主の座標
  Particle particle;                               // 0x0C
  void (*updateCallback)(struct ParticleShadow*);  // 0x34, ParticleShadowManager_Update が影を引数にして呼ぶ
  struct ParticleShadow* prev;                     // 0x38
  struct ParticleShadow* next;                     // 0x3C
} ParticleShadow;
static_assert(sizeof(ParticleShadow) == 64);  // ScriptShadowManager の要素 (Malloc(0x54)) で +0x0C から +0x4C (prev) まで

// 持ち主の足元に置く影 (AuxSprite 版), AuxShadowManager がリストで管理して毎フレーム fn を呼ぶ
// 高さが増えるほど scale を小さくする, ParticleShadow と違った"高級"な影
typedef struct AuxShadow {
  u8 active;                                  // 0x00, AuxShadowManager_Add でリストに入れると 1, AuxShadowManager_Remove で外すと 0
  u8 kind;                                    // 0x01, 0 なら fn = AuxShadow_FollowGround (床に追従), それ以外は AuxShadow_UpdateNone
  u8 flags;                                   // 0x02, bit0: AuxShadow_FollowGround で当たり判定マップでなく pos->y を高さに使う
  u8 unk_03;                                  // 0x03
  u16 unk_04;                                 // 0x04, AuxShadow_Init で 0
  u16 unk_06;                                 // 0x06, AuxShadow_Init で 0
  Vec3* pos;                                  // 0x08, 持ち主の座標, AuxShadow_FollowGround が x/y/z を読む
  AuxSprite sprite;                           // 0x0C, 根拠: AuxSprite_Add / AuxSprite_Remove
  AuxSpriteGfx gfx;                           // 0x38, 根拠: Video_GetAuxSprite(EFF_1C1B) / AuxSprite_Add
  s8 scale;                                   // 0x54, AuxShadow_FollowGround が高さから計算して sprite.scaleX/Y に入れる, 1 未満なら 1
  u8 farScale;                                // 0x55, 高さが farHeight を超えたときの scale
  u8 baseScale;                               // 0x56, 接地時の scale, 高さに応じてここから引く
  u8 unk_57;                                  // 0x57, AuxShadow_Init の第6引数
  s16 farHeight;                              // 0x58
  s16 nearHeight;                             // 0x5A
  u16 farShift;                               // 0x5C, nearHeight 以上 farHeight 以下のとき baseScale - (高さ >> farShift)
  u16 nearShift;                              // 0x5E, nearHeight 未満のとき baseScale - (高さ >> nearShift)
  void (*updateCallback)(struct AuxShadow*);  // 0x60, AuxShadowManager_Update が影を引数にして呼ぶ
  struct AuxShadow* prev;                     // 0x64
  struct AuxShadow* next;                     // 0x68
} AuxShadow;
static_assert(sizeof(AuxShadow) == 108);  // next (0x68) までは確定, それ以降に続くかは未確認

s32 ParticleShadow_Init(ParticleShadow* shadow, Vec3* ownerPos, s32 kind);
void ParticleShadow_UpdateNone(ParticleShadow* shadow);
s32 ParticleShadow_Remove(ParticleShadow* shadow);
void ParticleShadow_Show(ParticleShadow* shadow);
void ParticleShadow_Hide(ParticleShadow* shadow);

s32 AuxShadow_Init(AuxShadow* shadow, Vec3* pos, s32 scale, s32 farScale, s32 baseScale, s32 unk_57, s32 farHeight, s32 nearHeight, s32 farShift, s32 nearShift, s32 kind);
s32 AuxShadow_Remove(AuxShadow* shadow);
void AuxShadow_Show(AuxShadow* shadow);
void AuxShadow_Hide(AuxShadow* shadow);

#endif  // __INCLUDE_SHADOW_H__
