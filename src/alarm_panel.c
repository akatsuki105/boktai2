#include "entity.h"
#include "global.h"
#include "mover.h"
#include "sprite_aux.h"

// 太陽警報機(太陽ゲージが1以上のときに踏むと警報を出して敵にバレる)
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_8
  u16 id;              // 0x18
  u8 unk_1a[2];        // 0x1A, まだ未解析, padding?
  bool16 moverLinked;  // 0x1C, '.h=0', 立っていれば mover を使う
  u16 stateTimer;      // 0x1E, Init が 0 を書く
  Mover mover;         // 0x20, '.p' は mover.pos に直接入る
  AuxSprite sprite;    // 0x64, '.r' があれば flags に bit2 を立てる
  AuxSpriteGfx gfx;    // 0x90, SPRITE_TRAP_FLOOR, パレット 70
  AuxSprite sprite2;   // 0xAC, flags に BLINK_ODD|UNK_0 が立つ, 位置は x と z が 0x80 手前
  AuxSpriteGfx gfx2;   // 0xD8, SPRITE_TRAP_FLOOR, パレット 69
  u32 unk_f4;          // 0xF4, '.R=0'
} AlarmPanel;
static_assert(sizeof(AlarmPanel) == 248);

NAKED s32 FUN_080a16b0(AlarmPanel* p) { INCFUNC("asm/func/FUN_080a16b0.inc"); }

NAKED s32 AlarmPanel_Update(AlarmPanel* p) { INCFUNC("asm/func/AlarmPanel_Update.inc"); }

NAKED s32 AlarmPanel_Destroy(AlarmPanel* p) { INCFUNC("asm/func/AlarmPanel_Destroy.inc"); }

NAKED s32 AlarmPanel_Init(AlarmPanel* p, u16 id) { INCFUNC("asm/func/AlarmPanel_Init.inc"); }

// 0x25F3, HashName("太陽警報機")
NAKED AlarmPanel* AlarmPanel_Create(u32 id) { INCFUNC("asm/func/AlarmPanel_Create.inc"); }
