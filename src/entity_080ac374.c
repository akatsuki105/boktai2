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

INCASM("asm/entity_080ac374.inc");
