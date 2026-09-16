#include "entity.h"
#include "global.h"
#include "sprite.h"

// 0x085af0ec
typedef struct {
  u16 unk_0;     // 0x000
  u16 unk_2;     // 0x002
  u16 unk_4;     // 0x004
  u16 unk_6;     // 0x006
  u16 unk_8;     // 0x008
  u8 unk_9;      // 0x009
  u8 unk_a;      // 0x00a
  u32 unk_c;     // 0x00c
  u32 unk_10;    // 0x010
  s8 unk_14;     // 0x014
  s8 unk_15;     // 0x015
  u8 unk_16[6];  // 0x016
  // TODO: まだ下にたくさんメンバがある
} Unk_085af0ec;

typedef struct EntityC946 {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[0x1c - 0x18];
  u32 unk_1c;  // 0x01C
  u8 unk_20[0x30c - 0x20];
  q_SpriteNode44 node_30c;      // 0x30C
  ActorSpriteState sprite_338;  // 0x338
  u16 x_354;                    // 0x354
  u16 y_356;                    // 0x356
  u8 unk_358[884 - 0x358];
} EntityC946;
static_assert(sizeof(EntityC946) == 884);

INCASM("asm/entity_c946.inc");

NAKED s32 FUN_0820f9dc(EntityC946* p, s32 val) { INCFUNC("asm/func/FUN_0820f9dc.inc"); }

NAKED void FUN_0820fa80(EntityC946* p, s32 val) { INCFUNC("asm/func/FUN_0820fa80.inc"); }

NAKED void EntityC946_Update_Helper_0820fb20(EntityC946* p) { INCFUNC("asm/func/EntityC946_Update_Helper_0820fb20.inc"); }

NAKED s32 EntityC946_Update(EntityC946* p) { INCFUNC("asm/func/EntityC946_Update.inc"); }

NAKED s32 EntityC946_Destroy(EntityC946* p) { INCFUNC("asm/func/EntityC946_Destroy.inc"); }

NAKED s32 EntityC946_Init(EntityC946* p, u32 _) { INCFUNC("asm/func/EntityC946_Init.inc"); }

EntityC946* EntityC946_Create(u32 arg, u32 _) {
  EntityC946* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityC946));
  if (p != NULL) {
    SetEntityRoutine(p, EntityC946_Update, EntityC946_Destroy);
    if (EntityC946_Init(p, arg) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED void FUN_0820fe94(EntityC946* p, u32 val) { INCFUNC("asm/func/FUN_0820fe94.inc"); }

INCBIN(".rodata", "data/entity_c946.bin");  // ./tmp/bin.sh ./baserom.gba 0x085af0ec 0x085af9ac ./data/entity_c946.bin
