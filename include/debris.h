#ifndef __INCLUDE_DEBRIS_H__
#define __INCLUDE_DEBRIS_H__

#include "gba/gba.h"
#include "hitbox.h"
#include "sprite_common.h"
#include "types.h"

// Debris.flags
typedef u16 DebrisFlags;
#define DEBRIS_FREE_ON_END (1 << 0)  // 0x0001, アニメが終わったら点滅せずにすぐ消す
#define DEBRIS_HAS_HITBOX (1 << 2)   // 0x0004, 攻撃判定を持つ, Debris_Spawn で power > 0 なら立つ
#define DEBRIS_SPRITE (1 << 3)       // 0x0008, AuxSprite で描く (obj は DebrisSprite)
#define DEBRIS_PTCL (1 << 4)         // 0x0010, Particle で描く (obj は DebrisPtcl)
#define DEBRIS_BOUNCE (1 << 5)       // 0x0020, DEBRIS_PTCL のとき床で跳ねる状態で始める
#define DEBRIS_MOVING (1 << 7)       // 0x0080, vel が 0 でない, 跳ねて止まったら落とす
#define DEBRIS_HITBOX_ON (1 << 8)    // 0x0100, 今フレーム攻撃判定を登録する, DebrisManager_ScheduleHitboxes が立てる

struct Debris;

struct Debris* Debris_Spawn(Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 ofsX, s32 ofsY);

#endif  // __INCLUDE_DEBRIS_H__
