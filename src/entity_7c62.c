#include "entity.h"
#include "global.h"
#include "mover.h"
#include "sprite_aux.h"

struct Entity7C62;

typedef void(Entity7C62Func)(struct Entity7C62* p);

// プレイヤーが近づくと浮き上がり、A ボタンでその場所へ飛ばす足場 (Mover 付き)
typedef struct Entity7C62 {
  Entity e;                        // 0x000, ENTITY_UNK_9
  u16 id;                          // 0x018, Entity7C62_Init の第2引数, mover の id を兼ねる
  u8 nearState;                    // 0x01A, プレイヤーが近いかを 0/1 で覚え、変わったフレームだけ効果音を鳴らす
  bool8 moverLinked;               // 0x01B, '.h=0', 立っていれば mover を使う
  u8 unk_1c[4];                    // 0x01C, 触られていない
  Mover mover;                     // 0x020
  AuxSprite sprite;                // 0x064, flags に 0x200 が立つ, rise が 0 の間は隠す
  AuxSpriteGfx gfx;                // 0x090, SPRITE_MAGIC_CIRCLE
  Vec3 pos;                        // 0x0AC, '.p', y はタイルの attr から計算し直す, 起動するとプレイヤーをここへ移す
  AuxSprite sprite2;               // 0x0B4, flags に BLINK_EVEN が立つ2枚目
  AuxSpriteGfx gfx2;               // 0x0E0, SPRITE_MAGIC_CIRCLE
  u16 plttID;                      // 0x0FC, 106
  u16 highlight;                   // 0x0FE, 近いと 8 まで増え離れると減る
  u16 rise;                        // 0x100, 近いと 2 ずつ 0x18 まで増え離れると減る, 0 のときは sprite を隠す
  u16 readyTimer;                  // 0x102, 10 を越えていないと A ボタンで起動できない
  u16 scriptArgs[2];               // 0x104, '.A'
  s32 scriptID;                    // 0x108, '.s', 0 なら実行しない
  u16 stateTimer;                  // 0x10C, updateCallback を差し替えるたびに 0 に戻る
  u8 unk_10e[2];                   // 0x10E, 触られていない, padding?
  Entity7C62Func* updateCallback;  // 0x110
} Entity7C62;
static_assert(sizeof(Entity7C62) == 276);

NAKED bool32 Entity7C62_IsPlayerNear(Entity7C62* p) { INCFUNC("asm/func/Entity7C62_IsPlayerNear.inc"); }

NAKED void Entity7C62_SetUpdateCallback(Entity7C62* p, Entity7C62Func* fn) { INCFUNC("asm/func/Entity7C62_SetUpdateCallback.inc"); }

NAKED void Entity7C62_UpdateIdle(Entity7C62* p) { INCFUNC("asm/func/Entity7C62_UpdateIdle.inc"); }

NAKED void Entity7C62_UpdateActivated(Entity7C62* p) { INCFUNC("asm/func/Entity7C62_UpdateActivated.inc"); }

NAKED void Entity7C62_UpdateDone(Entity7C62* p) { INCFUNC("asm/func/Entity7C62_UpdateDone.inc"); }

NAKED s32 Entity7C62_Update(Entity7C62* p) { INCFUNC("asm/func/Entity7C62_Update.inc"); }

NAKED s32 Entity7C62_Destroy(Entity7C62* p) { INCFUNC("asm/func/Entity7C62_Destroy.inc"); }

NAKED s32 Entity7C62_Init(Entity7C62* p, u32 id) { INCFUNC("asm/func/Entity7C62_Init.inc"); }

NAKED Entity7C62* Entity7C62_Create(u32 id, u32 _) { INCFUNC("asm/func/Entity7C62_Create.inc"); }
