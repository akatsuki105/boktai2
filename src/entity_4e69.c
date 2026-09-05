#include "entity.h"
#include "global.h"

typedef struct {
  u16 unk_0;  // 0x0, gFS の IDlo のようなもの？
  u16 unk_2;  // 0x2, gFS の IDhi のようなもの？
} UnkStruct08daadb8;
static_assert(sizeof(UnkStruct08daadb8) == 4);

// 太陽鍛治に関係？
typedef struct Entity4E69 {
  Entity e;         // ENTITY_UNK_2
  s16 unk_18;       // 0x18
  s16 unk_1a;       // 0x1A
  u16 unk_1c;       // 0x1C
  u8 unk_1e;        // 0x1E
  u8 unk_1f;        // 0x1F
  u16 scriptID_20;  // 0x20, 0x08022308
  u8 unk_22;        // 0x22
  u8 unk_23;        // 0x23
  u8 unk_24;        // 0x24
  u8 unk_25[0x70 - 0x25];
  u32 unk_70;           // 0x70
  UnkStruct52* unk_74;  // 0x74
  UnkStruct52 unk_78;   // 0x78
} Entity4E69;
static_assert(sizeof(Entity4E69) == 172);

extern Entity4E69* gEntity4E69;  // 0x03002B4C

NAKED UnkStruct52* FUN_080220bc(Entity4E69* p, u32 val1, u32 val2) { INCFUNC("asm/func/FUN_080220bc.inc"); }

s32 FUN_080220e8(Entity4E69* p, UnkStruct52* data) {
  if (p->unk_74 != NULL) {
    (p->unk_74)->unk_2c = data;
  }
  data->unk_2c = NULL;
  data->unk_30 = p->unk_74;
  p->unk_74 = data;
  return 0;
}

INCASM("asm/entity_4e69.inc");

NAKED void FUN_080221fc(Entity4E69* p, UnkStruct52* q, void* _) { INCFUNC("asm/func/FUN_080221fc.inc"); }

NAKED s32 FUN_08022210(Entity4E69* p) { INCFUNC("asm/func/FUN_08022210.inc"); }

NAKED s32 Entity4E69_Update(Entity4E69* p) { INCFUNC("asm/func/Entity4E69_Update.inc"); }

s32 Entity4E69_Destroy(Entity4E69* p) {
  FUN_08022428(&p->unk_78);
  gEntity4E69 = NULL;
  return 0;
}

NAKED s32 Entity4E69_Init(Entity4E69* p, u32 subroutineID) { INCFUNC("asm/func/Entity4E69_Init.inc"); }

NAKED Entity4E69* Entity4E69_Create(u32 subroutineID) { INCFUNC("asm/func/Entity4E69_Create.inc"); }
