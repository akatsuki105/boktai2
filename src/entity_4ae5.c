#include "file.h"
#include "global.h"

typedef struct Entity4AE5 {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[1564];
  FileID pltt_file_id_634[24];  // 0x634, FUN_08001f54
  s32 unk_664;                  // 0x664, FUN_0800205c
  u16 unk_668[64];              // 0x668, FUN_0800205c
  u8 unk_6e8[16];               // 0x6E8
} Entity4AE5;
static_assert(sizeof(Entity4AE5) == 1784);

extern Entity4AE5* gEntity4AE5;  // 0x03002B2C

void FUN_08001878(void) { gEntity4AE5 = NULL; }

INCASM("asm/entity_4ae5.inc");

NAKED void FUN_0800201c(void) { INCFUNC("asm/func/FUN_0800201c.inc"); }

NAKED void FUN_0800205c(s32 val, s32 param_2, UNK_PTR param3) { INCFUNC("asm/func/FUN_0800205c.inc"); }

NAKED void FUN_080020bc(void) { INCFUNC("asm/func/FUN_080020bc.inc"); }

NAKED s32 Entity4AE5_Update(Entity4AE5* p) { INCFUNC("asm/func/Entity4AE5_Update.inc"); }

s32 Entity4AE5_Destroy(Entity4AE5* p) { gEntity4AE5 = NULL; }

NAKED s32 Entity4AE5_Init(Entity4AE5* p, u32 val) { INCFUNC("asm/func/Entity4AE5_Init.inc"); }

NAKED Entity4AE5* Entity4AE5_Create(u32 val) { INCFUNC("asm/func/Entity4AE5_Create.inc"); }

// --------------------------------------------

void FUN_08001a84(Entity4AE5*);
void FUN_08001a94(Entity4AE5*);
void FUN_08001ad0(Entity4AE5*);
void FUN_08001b2c(Entity4AE5*);

void (*const PTR_ARRAY_085aa624[4])(Entity4AE5*) = {
    FUN_08001a84,
    FUN_08001a94,
    FUN_08001ad0,
    FUN_08001b2c,
};

void FUN_08001e20(Entity4AE5*);
void FUN_08001ea4(Entity4AE5*);
void FUN_08001ef8(Entity4AE5*);

// clang-format off
void (*const PTR_ARRAY_085aa634[7])(Entity4AE5*) = {
    (void*)NULL,
    FUN_08001e20,
    FUN_08001ef8,
    FUN_08001ea4,
    FUN_08001ef8,
    FUN_08001ea4,
    (void*)NULL,
};
// clang-format on
