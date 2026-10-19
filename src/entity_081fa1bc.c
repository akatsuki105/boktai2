#include "entity.h"
#include "global.h"
#include "particle.h"

// 不使用
// 粒子1個を出して 301 フレーム数えたら自分を消すだけのエンティティ
// 呼び出し元がリポジトリにも Ghidra にも無く, CreateEntity も見つからないため 80 バイトは下限
typedef struct Entity081fa1bc {
  Entity e;              // 0x00
  Particle ptcl;         // 0x18, pos は _Init の第2引数の写し, 初期コマは 0x20, offset は (-8, -8)
  ParticleGroup* group;  // 0x40, PTCL_GROUP_0
  s16 timer;             // 0x44, 毎フレーム +1, 300 を超えると KillEntity する
  Vec3 pos;              // 0x48, '_Init' の第2引数の写し, ptcl.pos の初期値
} Entity081fa1bc;
static_assert(sizeof(Entity081fa1bc) == 80);

INCASM("asm/entity_081fa1bc.inc");
