#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

struct Entity4759;

typedef void(Entity4759Func)(struct Entity4759* p);

// プレイヤーが近づくと浮き上がり、A ボタンでその場所へ飛ばす足場
typedef struct Entity4759 {
  Entity e;                        // 0x00, ENTITY_UNK_9
  s16 nearState;                   // 0x18, プレイヤーが近いかを 0/1 で覚え、変わったフレームだけ効果音を鳴らす
  u8 variant;                      // 0x1A, '.t=0', 0 ならパレット 284, それ以外は 285
  u8 unk_1b;                       // 0x1B, どの関数も触っていない
  AuxSprite sprite;                // 0x1C, flags に 0x200 が立つ, rise が 0 の間は隠す
  AuxSpriteGfx gfx;                // 0x48, SPRITE_A152
  Vec3 pos;                        // 0x64, '.p', y はタイルの attr から計算し直す, 起動するとプレイヤーをここへ移す
  AuxSprite sprite2;               // 0x6C, flags に 0x400 が立つ, 起動が終わると隠す
  AuxSpriteGfx gfx2;               // 0x98, SPRITE_A152
  u16 plttID;                      // 0xB4, variant で選んだ 284 か 285
  u16 highlight;                   // 0xB6, 近いと 8 まで増え離れると減る, 8 でパレットが 286 になる
  u16 rise;                        // 0xB8, 近いと 2 ずつ 0x18 まで増え離れると減る, pos.y に足した値が sprite の y になる
  u16 readyTimer;                  // 0xBA, 10 を越えていないと A ボタンで起動できない
  u16 scriptArgs[2];               // 0xBC, '.A'
  s32 scriptID;                    // 0xC0, '.R', 起動が終わったときに実行する, 0 なら実行しない
  u16 stateTimer;                  // 0xC4, updateCallback を差し替えるたびに 0 に戻る
  u8 unk_c6[2];                    // 0xC6, 触られていない
  Entity4759Func* updateCallback;  // 0xC8
} Entity4759;
static_assert(sizeof(Entity4759) == 204);

NAKED bool32 Entity4759_IsPlayerNear(Entity4759* p) { INCFUNC("asm/func/Entity4759_IsPlayerNear.inc"); }

void Entity4759_SetUpdateCallback(Entity4759* p, Entity4759Func* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

NAKED void Entity4759_UpdateIdle(Entity4759* p) { INCFUNC("asm/func/Entity4759_UpdateIdle.inc"); }

NAKED void Entity4759_UpdateActivated(Entity4759* p) { INCFUNC("asm/func/Entity4759_UpdateActivated.inc"); }

void Entity4759_UpdateDone(Entity4759* p) {}

s32 Entity4759_Update(Entity4759* p) {
  p->updateCallback(p);
  return 0;
}

s32 Entity4759_Destroy(Entity4759* p) {
  AuxSprite_Remove(&p->sprite);
  AuxSprite_Remove(&p->sprite2);
  return 0;
}

NAKED s32 Entity4759_Init(Entity4759* p, u32 param_2, u32 param_3) { INCFUNC("asm/func/Entity4759_Init.inc"); }

Entity4759* Entity4759_Create(u32 param_1, u32 param_2) {
  Entity4759* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity4759));

  if (p != NULL) {
    SetEntityRoutine(p, Entity4759_Update, Entity4759_Destroy);
    if (Entity4759_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
