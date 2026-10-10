#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "shadow.h"

// シェードマンのスプライトをロードしている (Entity0623_Init_Helper_0821c758)
typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_8
  u8 unk_18[0x15C - 0x18];    // 0x018, まだ未解析
  HitboxData hitbox_15c;      // 0x15C
  u8 unk_1ac[0x31C - 0x1AC];  // 0x1AC, まだ未解析
  AuxShadow shadow_31c;       // 0x31C
  u8 unk_388[3076 - 0x388];   // 0x388, まだ未解析
} Entity0623;
static_assert(sizeof(Entity0623) == 3076);

INCASM("asm/entity_0623.inc");

void FUN_0821c918(Entity0623*);
void FUN_08022b04(Entity0623*);  // asm/boss.inc
void FUN_0822129c(Entity0623*);
void FUN_0821d800(Entity0623*);
void FUN_08221194(Entity0623*);
void FUN_08221450(Entity0623*);

s32 Entity0623_Update(Entity0623* p) {
  FUN_0822129c(p);
  FUN_0821d800(p);
  FUN_08221194(p);
  FUN_08221450(p);
  return 0;
}

s32 Entity0623_Destroy(Entity0623* p) {
  FUN_0821c918(p);
  AuxShadow_Remove(&p->shadow_31c);
  Hitbox_Unregister(&p->hitbox_15c);
  FUN_08022b04(p);
  return 0;
}

NAKED s32 Entity0623_Init(Entity0623* p, u32 id) { INCFUNC("asm/func/Entity0623_Init.inc"); }

Entity0623* Entity0623_Create(u32 id) {
  Entity0623* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity0623));
  if (p != NULL) {
    SetEntityRoutine(p, Entity0623_Update, Entity0623_Destroy);
    if (Entity0623_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

const u8 u8_ARRAY_085affa8[16] = {9, 9, 9, 9, 6, 6, 11, 11, 6, 8, 9, 9, 10, 10, 6, 6};  // 0x085affa8

void FUN_0821ce18(Entity0623*);
void FUN_0821ce7c(Entity0623*);
void FUN_0821d074(Entity0623*);
void FUN_0821d0c8(Entity0623*);
void FUN_0821d124(Entity0623*);
void FUN_0821d18c(Entity0623*);
void FUN_0821d1e0(Entity0623*);
void FUN_0821d240(Entity0623*);
void FUN_0821d294(Entity0623*);
void FUN_0821d2f4(Entity0623*);
void FUN_0821d348(Entity0623*);
void FUN_0821d39c(Entity0623*);
void FUN_0821d3fc(Entity0623*);

// clang-format off
void (*const PTR_ARRAY_085affb8[13])(Entity0623*) = {
    FUN_0821ce18,
    FUN_0821ce7c,
    FUN_0821d074,
    FUN_0821d0c8,
    FUN_0821d124,
    FUN_0821d18c,
    FUN_0821d1e0,
    FUN_0821d240,
    FUN_0821d294,
    FUN_0821d2f4,
    FUN_0821d348,
    FUN_0821d39c,
    FUN_0821d3fc,
}; // 0x085affb8
// clang-format on

void FUN_0821d4b4(Entity0623*);
void FUN_0821d578(Entity0623*);

void (*const PTR_ARRAY_085affec[2])(Entity0623*) = {
    FUN_0821d4b4,
    FUN_0821d578,
};  // 0x085affec

void FUN_0821d5a8(Entity0623*);
void FUN_0821d5d8(Entity0623*);
void FUN_0821d630(Entity0623*);
void FUN_0821d660(Entity0623*);
void FUN_0821d690(Entity0623*);
void FUN_0821d6c0(Entity0623*);
void FUN_0821d6f0(Entity0623*);

// clang-format off
void (*const PTR_ARRAY_085afff4[7])(Entity0623*) = {
    FUN_0821d5a8,
    FUN_0821d5d8,
    FUN_0821d630,
    FUN_0821d660,
    FUN_0821d690,
    FUN_0821d6c0,
    FUN_0821d6f0,
};  // 0x085afff4
// clang-format on

void FUN_0821d744(Entity0623*);

void (*const PTR_ARRAY_085b0010[1])(Entity0623*) = {
    FUN_0821d744,
};  // 0x085b0010

void FUN_0821d760(Entity0623*);

void (*const PTR_ARRAY_085b0014[1])(Entity0623*) = {
    FUN_0821d760,
};  // 0x085b0014

void FUN_0821d77c(Entity0623*);

void (*const PTR_ARRAY_085b0018[1])(Entity0623*) = {
    FUN_0821d77c,
};  // 0x085b0018

void FUN_0821d798(Entity0623*);
void FUN_0821d7c8(Entity0623*);
void FUN_0821d7e4(Entity0623*);

void (*const PTR_ARRAY_085b001c[3])(Entity0623*) = {
    FUN_0821d798,
    FUN_0821d7c8,
    FUN_0821d7e4,
};  // 0x085b001c

void FUN_0821deec(Entity0623*);
void FUN_0821df64(Entity0623*);
void FUN_0821dfdc(Entity0623*);
void FUN_0821e0a8(Entity0623*);
void FUN_0821e220(Entity0623*);
void FUN_0821e3f0(Entity0623*);
void FUN_0821e738(Entity0623*);
void FUN_0821ea6c(Entity0623*);
void FUN_0821f0e4(Entity0623*);
void FUN_0821f818(Entity0623*);
void FUN_0821ff34(Entity0623*);
void FUN_082201ec(Entity0623*);
void FUN_08220430(Entity0623*);
void FUN_082206a8(Entity0623*);
void FUN_08220758(Entity0623*);
void FUN_0822098c(Entity0623*);
void FUN_082209cc(Entity0623*);
void FUN_08220a68(Entity0623*);
void FUN_08220b64(Entity0623*);
void FUN_08220bf0(Entity0623*);
void FUN_08220cc4(Entity0623*);
void FUN_08220de0(Entity0623*);

// clang-format off
void (*const PTR_ARRAY_085b0028[22])(Entity0623*) = {
    FUN_0821deec,
    FUN_0821df64,
    FUN_0821dfdc,
    FUN_0821e0a8,
    FUN_0821e220,
    FUN_0821e3f0,
    FUN_0821e738,
    FUN_0821ea6c,
    FUN_0821f0e4,
    FUN_0821f818,
    FUN_0821ff34,
    FUN_082201ec,
    FUN_08220430,
    FUN_082206a8,
    FUN_08220758,
    FUN_0822098c,
    FUN_082209cc,
    FUN_08220a68,
    FUN_08220b64,
    FUN_08220bf0,
    FUN_08220cc4,
    FUN_08220de0,
}; // 0x085b0028
// clang-format on
