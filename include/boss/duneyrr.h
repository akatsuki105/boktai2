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
  HitboxData hurtbox;     // 0x070, ハンドラは Entity08059a1cElem_OnHurt
  HitboxData hitbox;      // 0x0C0
  ParticleShadow shadow;  // 0x110
} Entity08059a1cElem;
static_assert(sizeof(Entity08059a1cElem) == 336);

// Duneyrr関係
typedef struct Entity08059a1c {
  Entity e;                     // 0x000, ENTITY_UNK_8
  AuxAnimFile* anim;            // 0x018, ANIM_31F4
  u32 activeMask;               // 0x01C, bit i が立っていれば elems[i] が使用中
  u32 frameCount;               // 0x020
  u16 power;                    // 0x024, 各部品の hitbox の power
  u16 knockbackPower;           // 0x026
  u16 unk_28;                   // 0x028, 各部品の hitbox の unk_44
  u16 dustPower;                // 0x02A, FUN_0805965c が DustManager_Emit に渡す鱗粉の power
  s32 circlingCount;            // 0x02C, state 1 (center の周りを回る) の部品の数
  u8 unk_30[0x34 - 0x30];       // 0x030
  Vec3 center;                  // 0x034
  Entity08059a1cElem elems[8];  // 0x03C
  struct Player* player;        // 0xABC
} Entity08059a1c;
static_assert(sizeof(Entity08059a1c) == 2752);

Entity08059a1c* Entity08059a1c_Create(s32 power, s32 knockbackPower, s32 param_3, s32 param_4);
s32 Entity08059a1c_AddElem(Entity08059a1c* p, u32 angle, u32 param_3);

#endif  // __INCLUDE_BOSS_DUNEYRR_H__
