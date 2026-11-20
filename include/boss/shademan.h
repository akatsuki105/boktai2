#ifndef __INCLUDE_BOSS_SHADEMAN_H__
#define __INCLUDE_BOSS_SHADEMAN_H__

#include "entity.h"
#include "gba/gba.h"
#include "sprite_aux.h"
#include "types.h"

// シェードマンの技"クラッシュノイズ"のスピーカー1つ, 現れて震えてから 1P へ輪っかを撃ち, volleyMax 回撃つと消える
typedef struct {
  bool8 active;       // 0x00
  u8 state;           // 0x01, sCrashNoiseSpeakerStates の添字
  bool8 stateBegun;   // 0x02, 立っていると次の更新で state の初期化をする
  u8 angle;           // 0x03, 撃ち始めに 1P へ向けた向き, 輪っかはこれから ±8 ずらして飛ばす
  u16 power;          // 0x04, 以下 0x0C までは CrashNoiseRingManager_Spawn に渡す輪っかの引数
  u16 speed;          // 0x06
  u16 knockback;      // 0x08
  u16 iframes;        // 0x0A
  u16 kind;           // 0x0C
  u8 volleyCount;     // 0x0E, 撃ち終えた回数
  u8 volleyMax;       // 0x0F, この回数撃ったら消える
  u8 shotsPerVolley;  // 0x10, 1回に 16 フレームおきに撃つ輪っかの数
  u8 unk_11[3];       // 0x11, padding?
  u32 timer;          // 0x14, state に入ってからのフレーム数
  Vec3 pos;           // 0x18, 置いた位置, 震えたあとに sprite.pos をここへ戻す
  AuxSprite sprite;   // 0x20
} CrashNoiseSpeaker;
static_assert(sizeof(CrashNoiseSpeaker) == 76);

// クラッシュノイズのスピーカーを最大 8 個まで置く
typedef struct CrashNoiseSpeakerManager {
  Entity e;                             // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx[2];                  // 0x018, SPR_SPEAKER
  u32 ringLifetime;                     // 0x050, 輪っかが消えるまでのフレーム数, CrashNoiseRingManager_Create にそのまま渡す
  CrashNoiseSpeaker elems[8];           // 0x054
  struct CrashNoiseRingManager* rings;  // 0x2B4
} CrashNoiseSpeakerManager;
static_assert(sizeof(CrashNoiseSpeakerManager) == 696);

#endif  // __INCLUDE_BOSS_SHADEMAN_H__
