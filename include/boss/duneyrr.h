#ifndef __INCLUDE_BOSS_DUNEYRR_H__
#define __INCLUDE_BOSS_DUNEYRR_H__

#include "boss.h"
#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "shadow.h"
#include "sprite.h"
#include "types.h"

struct Player;

// 8 個並ぶ部品
typedef struct {
  bool8 stateEntered;     // 0x000, state を変えると 1, 状態関数の最初のフレームで 0 に戻す
  u8 angle;               // 0x001
  u8 state;               // 0x002, PTR_ARRAY_085ab9dc の添字
  u8 unk_3;               // 0x003
  u16 dist;               // 0x004, startPos から targetPos までの距離
  u16 timer;              // 0x006, state を変えると 0 に戻る
  Vec3 startPos;          // 0x008
  Vec3 targetPos;         // 0x010, プレイヤーの位置
  AuxSpriteGfx gfx;       // 0x018, SPRITE_DUNEYRR_AUX
  AuxSprite sprite;       // 0x034
  AuxAnimState anim;      // 0x060
  HitboxData hurtbox;     // 0x070, ハンドラは DuneyrrPowderBall_OnHurt
  HitboxData hitbox;      // 0x0C0
  ParticleShadow shadow;  // 0x110
} DuneyrrPowderBall;
static_assert(sizeof(DuneyrrPowderBall) == 336);

// ドゥネイルの攻撃"鱗粉玉" (Phosphorous Powder Ball)
// プレイヤーに対して飛ばしたり、ステージ中央の燭台の周りに複数出して燭台の周りをグルグル回らせたりする
// 地形にぶつかると、粉エフェクトを出して消える
typedef struct DuneyrrPowderBallManager {
  Entity e;                    // 0x000, ENTITY_UNK_8
  AuxAnimFile* anim;           // 0x018, ANIM_31F4
  u32 activeMask;              // 0x01C, bit i が立っていれば balls[i] が使用中
  u32 frameCount;              // 0x020
  u16 power;                   // 0x024, 各部品の hitbox の power
  u16 knockbackPower;          // 0x026
  u16 invincibleTime;          // 0x028, 各部品の hitbox の invincibleTime
  u16 dustPower;               // 0x02A, FUN_0805965c が DustManager_Emit に渡す鱗粉の power
  s32 circlingCount;           // 0x02C, state 1 (center の周りを回る) の部品の数
  u8 unk_30[0x34 - 0x30];      // 0x030
  Vec3 center;                 // 0x034
  DuneyrrPowderBall balls[8];  // 0x03C
  struct Player* player;       // 0xABC
} DuneyrrPowderBallManager;
static_assert(sizeof(DuneyrrPowderBallManager) == 2752);

DuneyrrPowderBallManager* DuneyrrPowderBallManager_Create(s32 power, s32 knockbackPower, s32 param_3, s32 param_4);
s32 DuneyrrPowderBallManager_AddBall(DuneyrrPowderBallManager* p, u32 angle, u32 param_3);

#endif  // __INCLUDE_BOSS_DUNEYRR_H__
