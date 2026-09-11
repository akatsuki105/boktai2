#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"

// Entity95A8_Init で太陽ダケのスプライトをロードしているので太陽ダケのEntityだと思われる
typedef struct {
  Entity e;                 // ENTITY_UNK_8
  u16 q_unk_18;             // 0x18
  u8 unk_1a[0x20 - 0x1A];   // 0x1A
  u32 q_unk_20;             // 0x20
  u16 q_unk_24;             // 0x24
  u16 q_unk_26;             // 0x26
  u16 q_unk_28;             // 0x28
  u16 q_unk_2a;             // 0x2A
  u16 q_unk_2c;             // 0x2C
  u16 q_unk_2e;             // 0x2E
  u8 q_unk_30;              // 0x30
  u8 unk_31;                // 0x31
  u16 q_unk_32;             // 0x32
  u16 q_unk_34;             // 0x34
  u16 q_unk_36;             // 0x36
  u16 q_unk_38;             // 0x38
  u8 unk_3a[2];             // 0x3A
  ActorSpriteState sprite;  // 0x3C
  q_SpriteNode44 q_node;    // 0x58, sprite を指す描画ノード
  u8 unk_84[64];            // 0x84, FUN_080138fc に渡される別の構造体 (未解析)
  HitboxData hitbox;        // 0xC4, 0x0800c33a
} SolarBamboo;
static_assert(sizeof(SolarBamboo) == 276);

const u16 u16_ARRAY_085aa76c[4] = {
    0x6F,
    0x3,
    0x3,
    0x3,
};  // 0x085aa76c

NAKED void FUN_0800c0b0(HitboxData* a, HitboxData* b, SolarBamboo* p) { INCFUNC("asm/func/FUN_0800c0b0.inc"); }

NAKED s32 Entity95A8_Update(SolarBamboo* p) { INCFUNC("asm/func/Entity95A8_Update.inc"); }

NAKED s32 Entity95A8_Destroy(SolarBamboo* p) { INCFUNC("asm/func/Entity95A8_Destroy.inc"); }

NAKED s32 Entity95A8_Init(SolarBamboo* p, u32 param, u32 _) { INCFUNC("asm/func/Entity95A8_Init.inc"); }

SolarBamboo* Entity95A8_Create(u32 param, u32 _) {
  SolarBamboo* p = CreateEntity(ENTITY_UNK_8, sizeof(SolarBamboo));
  if (p != NULL) {
    SetEntityRoutine(p, Entity95A8_Update, Entity95A8_Destroy);
    if (Entity95A8_Init(p, param, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
