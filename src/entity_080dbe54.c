#include "entity.h"
#include "file.h"
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

void FUN_080db7e4(void) {}

NAKED void FUN_080db7e8(Entity080dbe54* p, u32 param_2) { INCFUNC("asm/func/FUN_080db7e8.inc"); }

NAKED void FUN_080db970(Entity080dbe54* p, u32 param_2) { INCFUNC("asm/func/FUN_080db970.inc"); }

NAKED s32 FUN_080db9b4(Entity080dbe54* p) { INCFUNC("asm/func/FUN_080db9b4.inc"); }

NAKED s32 FUN_080dba00(Entity080dbe54* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) { INCFUNC("asm/func/FUN_080dba00.inc"); }

s32 FUN_080dbcec(Entity080dbe54* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
  return FUN_080dba00(p, param_2, param_3, param_4, param_5, param_6, 1);
}

s32 FUN_080dbd08(Entity080dbe54* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
  return FUN_080dba00(p, param_2, param_3, param_4, param_5, param_6, 0);
}

NAKED s32 Entity080dbe54_Update(Entity080dbe54* p) { INCFUNC("asm/func/Entity080dbe54_Update.inc"); }

NAKED s32 Entity080dbe54_Destroy(Entity080dbe54* p) { INCFUNC("asm/func/Entity080dbe54_Destroy.inc"); }

void FUN_080dbe14(Entity080dbe54* p) {
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, 0xD1B8);
}

s32 Entity080dbe54_Init(Entity080dbe54* p, u32 param_2) {
  p->unk_724 = param_2;
  FUN_080dbe14(p);
  return 0;
}

NAKED Entity080dbe54* Entity080dbe54_Create(void) { INCFUNC("asm/func/Entity080dbe54_Create.inc"); }

void FUN_080dbea4(void) { gEntity080dbe54 = NULL; }
