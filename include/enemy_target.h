#ifndef __INCLUDE_ENEMY_TARGET_H__
#define __INCLUDE_ENEMY_TARGET_H__

#include "gba/gba.h"
#include "mover.h"
#include "types.h"

struct Enemy;

// EnemyTarget.flags (0x04)
typedef u8 EnemyTargetFlags;
#define ENEMYTARGET_REGISTERED (1 << 0)  // EnemyTargetManager_Add が立てる
#define ENEMYTARGET_LINKED (1 << 1)      // enemy と紐付き中, EnemyTargetManager_Sweep が落とす

// 敵から攻撃を受ける対象(Player, Coffin など)につける
typedef struct EnemyTarget {
  Mover* owner;              // 0x00, EnemyTargetManager_FindOwnerByID が owner->id で検索する
  EnemyTargetFlags flags;    // 0x04
  u8 kindMask;               // 0x05, 登録者の種別, EnemyTargetManager_Claim は & で、EnemyTargetManager_FindByKind は == で引く
  u16 cooldown;              // 0x06, 再登録までの待ちフレーム数
  struct Enemy* enemy;       // 0x08, 紐付いた敵, 解除時に NULL に戻る
  struct EnemyTarget* next;  // 0x0C
} EnemyTarget;
static_assert(sizeof(EnemyTarget) == 16);

void EnemyTargetManager_Remove(EnemyTarget* t);
void EnemyTargetManager_Release(EnemyTarget* t);
EnemyTarget* EnemyTargetManager_FindByKind(u32 kindMask);
bool8 FUN_080f8d20(EnemyTarget* t);

#endif  // __INCLUDE_ENEMY_TARGET_H__
