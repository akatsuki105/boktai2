#include "entity.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"
#include "global.h"

// 8個を使い回す粒子の枠
typedef struct {
  Particle ptcl;  // 0x00, FUN_080abfec が Particle_Remove に渡す
  u8 unk_28[20];  // 0x28
} Entity080ac374Particle;
static_assert(sizeof(Entity080ac374Particle) == 60);

typedef struct {
  Entity e;                         // 0x000, ENTITY_UNK_11
  Player* player;                   // 0x018, _Init の第2引数
  Vec3 pos;                         // 0x01C, _Init の第4引数を8バイトまるごと写す。NULL なら x/y/z を 0 にする
  u8 unk_24;                        // 0x024, _Init の第3引数
  u8 unk_25;                        // 0x025, _Init が player->[0x37C] を写す
  u8 unk_26[2];                     // 0x026
  u16 unk_28;                       // 0x028, _Init の第5引数
  u16 unk_2a;                       // 0x02A, _Init の第6引数
  AuxSprite spr;                    // 0x02C, FUN_080ac21c が AuxSprite_Remove に渡す
  u8 unk_58[0x98 - 0x58];           // 0x058
  u8 unk_98;                        // 0x098, _Update が 0 かを見る。unk_9e と揃って 0 なら KillEntity
  u8 unk_99[5];                     // 0x099
  u8 unk_9e;                        // 0x09E, _Update が 0 かを見る
  u8 unk_9f[5];                     // 0x09F
  Entity080ac374Particle ptcls[8];  // 0x0A4, 根拠: FUN_080abfec の stride 0x3C × 8
} Entity080ac374;
static_assert(sizeof(Entity080ac374) == 644);

NAKED void FUN_080abd74(Entity080ac374* p) { INCFUNC("asm/func/FUN_080abd74.inc"); }

NAKED void FUN_080abe48(Entity080ac374* p, u32 param_2) { INCFUNC("asm/func/FUN_080abe48.inc"); }

NAKED void FUN_080abf9c(Entity080ac374* p) { INCFUNC("asm/func/FUN_080abf9c.inc"); }

void FUN_080abfec(Entity080ac374* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
}

NAKED void FUN_080ac008(Entity080ac374* p) { INCFUNC("asm/func/FUN_080ac008.inc"); }

NAKED void FUN_080ac090(Entity080ac374* p) { INCFUNC("asm/func/FUN_080ac090.inc"); }

NAKED void FUN_080ac100(Entity080ac374* p) { INCFUNC("asm/func/FUN_080ac100.inc"); }

NAKED void FUN_080ac13c(Entity080ac374* p) { INCFUNC("asm/func/FUN_080ac13c.inc"); }

NAKED void FUN_080ac18c(Entity080ac374* p) { INCFUNC("asm/func/FUN_080ac18c.inc"); }

void FUN_080ac21c(Entity080ac374* p) { AuxSprite_Remove(&p->spr); }

NAKED void FUN_080ac228(Entity080ac374* p, Vec3* pos) { INCFUNC("asm/func/FUN_080ac228.inc"); }

// 戻り値は呼んだ先が r0 に残した値をそのまま使う (return 文を書くと1命令増える)
s32 Entity080ac374_Update(Entity080ac374* p) {
  FUN_080ac18c(p);
  FUN_080abf9c(p);
  if (p->unk_98 == 0) {
    if (p->unk_9e == 0) {
      KillEntity((Entity*)p);
    }
  }
}

// 戻り値は FUN_080abfec が r0 に残した値をそのまま使う (return 文を書くと1命令増える)
s32 Entity080ac374_Destroy(Entity080ac374* p) {
  FUN_080ac21c(p);
  FUN_080abfec(p);
}

NAKED s32 Entity080ac374_Init(Entity080ac374* p, Player* player, u8 param_3, Vec3* pos, u16 param_5, u16 param_6) { INCFUNC("asm/func/Entity080ac374_Init.inc"); }

NAKED Entity080ac374* Entity080ac374_Create(Player* player, u8 param_2, Vec3* pos, u16 param_4, u16 param_5) { INCFUNC("asm/func/Entity080ac374_Create.inc"); }
