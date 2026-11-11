#ifndef __INCLUDE_BOSS_DURATHROR_H__
#define __INCLUDE_BOSS_DURATHROR_H__

#include "boss.h"
#include "entity.h"
#include "gba/gba.h"
#include "types.h"

struct DurathrorImpale;  // "大棘": 地面から大きな棘を生やして突き刺そうとする攻撃, ドゥラスロール第3形態の攻撃パターンの1つ
struct DurathrorImpale* DurathrorImpale_Create(void);
s32 DurathrorImpale_Spawn(struct DurathrorImpale* p, s32 power, u32 duration, Vec3* pos);

s32 FallingObject_Spawn(u16 id, s32 type, u32 flags, s32 duration, s32 fallSpeed, s32 hp, s32 power, s32 knockback, Vec3* pos);  // 棘鉄球

#endif  // __INCLUDE_BOSS_DURATHROR_H__
