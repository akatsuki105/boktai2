#include "entity.h"
#include "particle.h"
#include "sprite.h"
#include "global.h"

typedef void (*Entity080abd14SpriteFunc)(AuxSprite* spr);

// 12個を使い回す粒子の枠
typedef struct {
  Particle ptcl;  // 0x00, FUN_080ab6d8 が Particle_Remove に渡す
  u8 unk_28[28];  // 0x28
} Entity080abd14Particle;
static_assert(sizeof(Entity080abd14Particle) == 68);

typedef struct {
  Entity e;                          // 0x000, ENTITY_UNK_11
  u8 unk_18;                         // 0x018, _Init の第5引数。0 かどうかで鳴らす SE が変わる
  u8 unk_19;                         // 0x019, _Update が 0 以外なら 0x03002BF0 を1減らして 0 に戻す
  u8 unk_1a;                         // 0x01A, _Init の第6引数
  u8 unk_1b;                         // 0x01B, _Update が owner の状態が 4 のとき 1 にする
  void* owner;                       // 0x01C, _Init の第2引数。_Update が owner->[0x1C] == 4 を見る
  AuxSprite spr0;                    // 0x020, FUN_080abb08 が AuxSprite_Remove に渡す
  u8 unk_4c[0x68 - 0x4C];            // 0x04C
  AuxSprite spr1;                    // 0x068, FUN_080abb08 が AuxSprite_Remove に渡す
  u8 unk_94[0xB0 - 0x94];            // 0x094
  u8 unk_b0;                         // 0x0B0, _Destroy が 0 以外かを見る
  u8 unk_b1;                         // 0x0B1, _Destroy が 0 かを見る
  u8 unk_b2[6];                      // 0x0B2
  Entity080abd14SpriteFunc spriteFunc;  // 0x0B8, FUN_080abac8 が spr0 を渡して呼ぶ
  u8 unk_bc[4];                      // 0x0BC
  AuxSprite spr2;                    // 0x0C0, FUN_080ab8ec が AuxSprite_Remove に渡す
  u8 unk_ec[0x140 - 0xEC];           // 0x0EC
  Entity080abd14Particle ptcls[12];  // 0x140, 根拠: FUN_080ab6d8 の stride 0x44 × 12
} Entity080abd14;
static_assert(sizeof(Entity080abd14) == 1136);

NAKED void FUN_080ab018(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab018.inc"); }

NAKED void FUN_080ab074(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab074.inc"); }

NAKED void FUN_080ab134(Entity080abd14* p, u32 param_2) { INCFUNC("asm/func/FUN_080ab134.inc"); }

NAKED void FUN_080ab278(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab278.inc"); }

NAKED void FUN_080ab3a0(Entity080abd14* p, u32 param_2) { INCFUNC("asm/func/FUN_080ab3a0.inc"); }

NAKED void FUN_080ab4e8(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab4e8.inc"); }

NAKED void FUN_080ab540(Entity080abd14* p, u32 param_2) { INCFUNC("asm/func/FUN_080ab540.inc"); }

NAKED void FUN_080ab67c(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab67c.inc"); }

void FUN_080ab6d8(Entity080abd14* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
}

NAKED void FUN_080ab6f8(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab6f8.inc"); }

NAKED void FUN_080ab780(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab780.inc"); }

NAKED void FUN_080ab7f0(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab7f0.inc"); }

NAKED void FUN_080ab848(AuxSprite* spr) { INCFUNC("asm/func/FUN_080ab848.inc"); }

NAKED void FUN_080ab898(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab898.inc"); }

void FUN_080ab8ec(Entity080abd14* p) { AuxSprite_Remove(&p->spr2); }

NAKED void FUN_080ab8f8(Entity080abd14* p, u32 param_2) { INCFUNC("asm/func/FUN_080ab8f8.inc"); }

NAKED void FUN_080ab99c(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab99c.inc"); }

NAKED void FUN_080ab9e0(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab9e0.inc"); }

NAKED void FUN_080abac8(Entity080abd14* p) { INCFUNC("asm/func/FUN_080abac8.inc"); }

void FUN_080abb08(Entity080abd14* p) {
  AuxSprite_Remove(&p->spr0);
  AuxSprite_Remove(&p->spr1);
}

NAKED void FUN_080abb20(Entity080abd14* p, u32 param_2) { INCFUNC("asm/func/FUN_080abb20.inc"); }

NAKED s32 Entity080abd14_Update(Entity080abd14* p) { INCFUNC("asm/func/Entity080abd14_Update.inc"); }

NAKED s32 Entity080abd14_Destroy(Entity080abd14* p) { INCFUNC("asm/func/Entity080abd14_Destroy.inc"); }

NAKED s32 Entity080abd14_Init(Entity080abd14* p, void* owner, u32 param_3, u32 param_4, u8 param_5, u8 param_6) { INCFUNC("asm/func/Entity080abd14_Init.inc"); }

NAKED Entity080abd14* Entity080abd14_Create(void* owner, u32 param_2, u32 param_3, u32 param_4, u8 param_5, u8 param_6) { INCFUNC("asm/func/Entity080abd14_Create.inc"); }
