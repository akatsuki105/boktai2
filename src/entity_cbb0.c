#include "entity_cbb0.h"

#include "entity.h"
#include "file.h"
#include "global.h"

// solar_generator.c で gEntityCBB0 を参照するのでヘッダに定義を置いた

const FileID FileID_ARRAY_085ad048[6] = {
    0x8446, 0x8546, 0x8646, 0x8746, 0x8846, 0x8946,
};  // 0x085AD048

void FUN_080af890(unknown*);
void FUN_080af8a0(unknown*);
void FUN_080afa20(unknown*);
void FUN_080afbd0(unknown*);
void FUN_080afe18(unknown*);
void FUN_080affdc(unknown*);
void FUN_080af97c(unknown*);
void FUN_080b009c(unknown*);
void FUN_080b01b4(unknown*);
void FUN_080b01ec(unknown*);

void (*const PTR_ARRAY_085ad054[10])(unknown*) = {
    FUN_080af890, FUN_080af8a0, FUN_080afa20, FUN_080afbd0, FUN_080afe18, FUN_080affdc, FUN_080af97c, FUN_080b009c, FUN_080b01b4, FUN_080b01ec,
};  // 0x085AD054

void FUN_080b1174(EntityCBB0*);
void FUN_080b11b4(EntityCBB0*);
void FUN_080b1404(EntityCBB0*);
void FUN_080b1434(EntityCBB0*);
void FUN_080b14b8(EntityCBB0*);
void FUN_080b1574(EntityCBB0*);
void FUN_080b165c(EntityCBB0*);
void FUN_080b1718(EntityCBB0*);
void FUN_080b176c(EntityCBB0*);
void FUN_080b17bc(EntityCBB0*);
void FUN_080b17f4(EntityCBB0*);
void FUN_080b1888(EntityCBB0*);
void FUN_080b18c4(EntityCBB0*);
void FUN_080b19c0(EntityCBB0*);
void FUN_080b1a84(EntityCBB0*);

void (*const PTR_ARRAY_085ad07c[15])(EntityCBB0*) = {
    FUN_080b1174, FUN_080b11b4, FUN_080b1404, FUN_080b1434, FUN_080b14b8, FUN_080b1574, FUN_080b165c, FUN_080b1718, FUN_080b176c, FUN_080b17bc, FUN_080b17f4, FUN_080b1888, FUN_080b18c4, FUN_080b19c0, FUN_080b1a84,
};  // 0x085AD07C

INCASM("asm/entity_cbb0.inc");

s32 FUN_080b2428(void) {
  gEntityCBB0 = NULL;
  return 0;
}

NAKED void FUN_080b2434(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b2434.inc"); }

NAKED u32 FUN_080b2474(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b2474.inc"); }

NAKED void FUN_080b24a4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b24a4.inc"); }

NAKED void FUN_080b252c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b252c.inc"); }

NAKED s32 EntityCBB0_Update(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Update.inc"); }

NAKED s32 EntityCBB0_Destroy(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Destroy.inc"); }

NAKED s32 EntityCBB0_Init(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Init.inc"); }

NAKED EntityCBB0* EntityCBB0_Create(u32 subroutineID) { INCFUNC("asm/func/EntityCBB0_Create.inc"); }
