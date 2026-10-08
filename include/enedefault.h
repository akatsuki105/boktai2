#ifndef __INCLUDE_ENEDEFAULT_H__
#define __INCLUDE_ENEDEFAULT_H__

#include "gba/gba.h"
#include "mover.h"
#include "types.h"

struct Enemy;

// EnemyTarget.flags (0x04)
typedef u8 EnemyTargetFlags;
#define ENEMYTARGET_REGISTERED (1 << 0)  // EnemyTargetManager_Add が立てる
#define ENEMYTARGET_LINKED (1 << 1)      // enemy と紐付き中, EnemyTargetManager_Sweep が落とす

struct EnemyTarget;

// EnemyTargetManager のリストにぶら下がるノード, 登録側 (Player, ImmortalCoffin など) の構造体に埋め込まれている
typedef struct EnemyTarget {
  Mover* owner;              // 0x00, EnemyTargetManager_FindOwnerByID が owner->id で検索する
  EnemyTargetFlags flags;    // 0x04
  u8 kindMask;               // 0x05, 登録者の種別, EnemyTargetManager_Claim は & で、EnemyTargetManager_FindByKind は == で引く
  u16 timer;                 // 0x06, 再登録までの待ちフレーム数, 毎フレーム -1
  struct Enemy* enemy;       // 0x08, 紐付いた敵, 解除時に NULL に戻る
  struct EnemyTarget* next;  // 0x0C
} EnemyTarget;
static_assert(sizeof(EnemyTarget) == 16);

#endif  // __INCLUDE_ENEDEFAULT_H__
