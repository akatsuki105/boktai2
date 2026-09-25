#include "entity.h"
#include "animation.h"
#include "particle.h"
#include "global.h"

// 32枠ぶんの演出要素。activeMask のビットが立っている枠だけ生きている
typedef struct {
  u8 unk_0[0x12];  // 0x00
  u8 unk_12;       // 0x12, FUN_080db970 が解放時に 0 にする
  s8 idx;          // 0x13, 自分の添字。ptcls と activeMask のビットを指す。解放後は 0xFF
  u8 unk_14[4];    // 0x14
} Entity080dbe54Slot;
static_assert(sizeof(Entity080dbe54Slot) == 24);

typedef struct Entity080dbe54 {
  Entity e;                      // 0x000, ENTITY_UNK_9
  AuxAnimFile* anim;             // 0x018, FUN_080dbe14 が GetFile(0x922E, 0xD1B8) を入れる
  ParticleGroup* group;          // 0x01C, FUN_080dbe14 が GetParticleGroup(PTCL_GROUP_0) を入れる
  Particle ptcls[32];            // 0x020, slots[i].idx が添字
  u8 unk_520[0x200];             // 0x520
  u32 activeMask;                // 0x720, 使用中の slots のビットマスク
  u32 unk_724;                   // 0x724, _Init の第2引数
  Entity080dbe54Slot slots[32];  // 0x728, 根拠: FUN_080db970 の ClearMemory(slot, 0x18) と _Destroy の32回ループ
} Entity080dbe54;
static_assert(sizeof(Entity080dbe54) == 2600);

extern Entity080dbe54* gEntity080dbe54;  // 0x03000164

INCASM("asm/entity_080dbe54.inc");
