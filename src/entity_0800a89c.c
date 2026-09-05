#include "animation.h"
#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"

// 精霊虫に関係?
typedef struct Entity0800a89c {
  Entity e;                // 0x0, ENTITY_UNK_8
  bool32 isSabata;         // 0x18
  u32 unk_1c;              // 0x1C
  ParticleGroup* group0;   // 0x20, PTCL_GROUP_0
  AnimationFile* anim_24;  // 0x24
  u8 unk_28[0x7D8 - 0x28];
  Player* player;  // 0x7D8, 根拠: 0x0800a860
} Entity0800a89c;
static_assert(sizeof(Entity0800a89c) == 2012);

extern Entity0800a89c* gEntity0800a89c;

const u16 u16_ARRAY_085aa6d0[24] = {
    0x4, 0x0, 0x5, 0x0, 0x6, 0x0, 0x6, 0x0, 0x5, 0x0, 0x4, 0x0, 0x9, 0x0, 0xA, 0x0, 0xB, 0x0, 0xB, 0x0, 0xA, 0x0, 0x9, 0x0,
};

const u32 u32_ARRAY_085aa700[3] = {10, 10, 120};

// --------------------------------------------

// 精霊虫の効果
void ApplySolBug(Player* p, s32 amount);
void ApplyLunaBug(Player* p, s32 amount);
void ApplyDarkBug(Player* p, s32 amount);

void (*const PTR_ARRAY_085aa70c[3])(Player*, s32) = {
    ApplySolBug,
    ApplyLunaBug,
    ApplyDarkBug,
};  // 0x085AA70C

// --------------------------------------------

const SoundID32 gSpiritBugsSoundIDs[3] = {0x11C, 0x11B, 0x11A};

const SoundID32 gSoundIDs_085aa724[3] = {0x293, 0x292, 0x291};

// --------------------------------------------

// まだ引数あるかも
void FUN_0800b064(Entity0800a89c*, unknown* r1, unknown* r2, unknown* r3);
void FUN_0800b068(Entity0800a89c*, unknown* r1, unknown* r2, unknown* r3);
void FUN_0800b7a0(Entity0800a89c*, unknown* r1, unknown* r2, unknown* r3);
void FUN_0800be38(Entity0800a89c*, unknown* r1, unknown* r2, unknown* r3);
void FUN_0800bcf0(Entity0800a89c*, unknown* r1, unknown* r2, unknown* r3);
void FUN_0800b404(Entity0800a89c*, unknown* r1, unknown* r2, unknown* r3);
void FUN_0800ba78(Entity0800a89c*, unknown* r1, unknown* r2, unknown* r3);

// clang-format off
void* const PTR_ARRAY_085aa730[15] = {
    FUN_0800b064,
    FUN_0800b068,
    FUN_0800b7a0,
    FUN_0800be38,
    FUN_0800bcf0,
    FUN_0800b064,
    FUN_0800b068,
    FUN_0800b7a0,
    FUN_0800be38,
    FUN_0800bcf0,
    FUN_0800b064,
    FUN_0800b404,
    FUN_0800ba78,
    FUN_0800be38,
    FUN_0800bcf0,
};  // 0x085AA730
// clang-format on

// --------------------------------------------

void FUN_0800a488(void) { gEntity0800a89c = NULL; }

INCASM("asm/entity_0800a89c.inc");

NAKED u32 FUN_0800af7c(void) { INCFUNC("asm/func/FUN_0800af7c.inc"); }

NAKED void FUN_0800afb8(void) { INCFUNC("asm/func/FUN_0800afb8.inc"); }
