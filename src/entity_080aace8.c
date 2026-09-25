#include "entity.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"
#include "global.h"

struct Entity080aace8Particle;
typedef void (*Entity080aace8ParticleFunc)(struct Entity080aace8Particle* ptcl);
struct Entity080aace8;
typedef void (*Entity080aace8Func)(struct Entity080aace8* p);

// 演出で飛ばす粒子1個ぶんの枠。8個を使い回す
typedef struct Entity080aace8Particle {
  Particle ptcl;                   // 0x00, _Destroy が Particle_Remove に渡す
  u8 unk_28[2];                    // 0x28
  u16 active;                      // 0x2A, FUN_080aa208 が 0 の枠を飛ばす
  u8 unk_2c[12];                   // 0x2C
  Entity080aace8ParticleFunc fn;   // 0x38, FUN_080aa208 が active な枠について呼ぶ
} Entity080aace8Particle;
static_assert(sizeof(Entity080aace8Particle) == 60);

typedef struct Entity080aace8 {
  Entity e;                          // 0x000, ENTITY_UNK_11
  Player* player;                    // 0x018, _Init の第2引数
  MainSprite sprite;                 // 0x01C, _Destroy が MainSprite_Remove に渡す
  u8 unk_7c[8];                      // 0x07C
  Vec3 screen;                       // 0x084, player->unk_24.pos の y に +0x96 した点を投影した画面座標
  u8 unk_8c[0x58];                   // 0x08C
  AuxSprite auxSprites[2];           // 0x0E4, 根拠: _Destroy の stride 0x2C × 2
  u8 unk_13c[0x28];                  // 0x13C
  Entity080aace8Particle ptcls[8];   // 0x164, 根拠: _Destroy の stride 0x3C × 8
  u8 unk_344[4];                     // 0x344
  u16 unk_348;                       // 0x348, _Init の第3引数。0 のときだけ _Destroy が auxSprites を外す
  u8 unk_34a[2];                     // 0x34A
  Entity080aace8Func updateCallback; // 0x34C, _Update が毎フレーム呼ぶ
} Entity080aace8;
static_assert(sizeof(Entity080aace8) == 848);

NAKED void FUN_080aa08c(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa08c.inc"); }

NAKED void FUN_080aa0e4(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa0e4.inc"); }

void FUN_080aa208(Entity080aace8* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active != 0) {
      p->ptcls[i].fn(&p->ptcls[i]);
    }
  }
}

NAKED void FUN_080aa23c(Entity080aace8Particle* ptcl) { INCFUNC("asm/func/FUN_080aa23c.inc"); }

NAKED void FUN_080aa29c(Entity080aace8Particle* ptcl) { INCFUNC("asm/func/FUN_080aa29c.inc"); }

NAKED void FUN_080aa4e8(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa4e8.inc"); }

NAKED void FUN_080aa5d0(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa5d0.inc"); }

NAKED void FUN_080aa658(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa658.inc"); }

NAKED void FUN_080aa708(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa708.inc"); }

NAKED void FUN_080aa834(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa834.inc"); }

s32 Entity080aace8_Update(Entity080aace8* p) {
  FUN_080aa208(p);
  p->updateCallback(p);
  return 0;
}

s32 Entity080aace8_Destroy(Entity080aace8* p) {
  s32 i;

  MainSprite_Remove(&p->sprite);
  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  if (p->unk_348 == 0) {
    for (i = 0; i < 2; i++) {
      AuxSprite_Remove(&p->auxSprites[i]);
    }
  }
  return 0;
}

NAKED void FUN_080aa940(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa940.inc"); }

NAKED void FUN_080aa9d0(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aa9d0.inc"); }

NAKED void FUN_080aaa2c(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aaa2c.inc"); }

NAKED void FUN_080aaaa8(Entity080aace8* p) { INCFUNC("asm/func/FUN_080aaaa8.inc"); }

NAKED s32 Entity080aace8_Init(Entity080aace8* p, Player* player, u16 param_3) { INCFUNC("asm/func/Entity080aace8_Init.inc"); }

NAKED Entity080aace8* Entity080aace8_Create(Player* player, u16 param_2) { INCFUNC("asm/func/Entity080aace8_Create.inc"); }
