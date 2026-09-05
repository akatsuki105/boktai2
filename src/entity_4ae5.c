#include "entity.h"
#include "file.h"
#include "global.h"

// マップ切り替え時に毎回生成される(時間帯によるマップのパレット処理と思われる)
typedef struct Entity4AE5 {
  Entity e;        // ENTITY_UNK_11
  u16 unk_18;      // 0x18, 0xE231, 0x317B, 0xF68D, 0xA58E, 0x4AE5 などがあるが、意味は不明
  u8 unk_1a;       // 0x1A, なんかのbitfield
  u8 unk_1b;       // 0x1B, PTR_ARRAY_085aa634 の idx
  u8 bytesize_1c;  // 0x1C, 0x08001e62
  u8 unk_1d;       // 0x1D
  u8 unk_1e;       // 0x1E
  u8 unk_1f;       // 0x1F
  u8 unk_20;       // 0x20
  u8 unk_21[0x24 - 0x21];
  const rgb555* srcPltt1;  // 0x24, PLTTファイルのRGB555データその1
  const rgb555* srcPltt2;  // 0x28, PLTTファイルのRGB555データその2
  rgb555* dstPltt;         // 0x2C, gFastBgPlttBuffer
  rgb555* pltt_30;         // 0x030
  rgb555 pltt_34[256];     // 0x034
  rgb555 pltt_234[256];    // 0x234
  rgb555 pltt_434[256];    // 0x434
  FileID plttFileIDs[3];   // 0x634
  u8 unk_63a[0x63c - 0x63a];
  u16 unk_63c;      // 0x63C
  u16 unk_63e;      // 0x63E
  u8 bytesize_640;  // 0x640, 0x08001bf0
  u8 bytesize_641;  // 0x641, 0x080022da
  u8 bytesize_642;  // 0x642, 0x08001c76
  u8 bytesize_643;  // 0x643, 0x08001c96
  u8 unk_644;       // 0x644, PTR_ARRAY_085aa624 の idx
  u16 unk_648;      // 0x648, 0x08002276
  u16 unk_64a;      // 0x64A
  u16 spanOfTime;   // 0x64C
  u16 unk_64e;      // 0x64E, gClock.unk_0f
  u8 unk_650[0x664 - 0x650];
  s32 unk_664;      // 0x664, FUN_0800205c
  u16 unk_668[64];  // 0x668, FUN_0800205c
  u8 unk_6e8[16];   // 0x6E8
} Entity4AE5;
static_assert(sizeof(Entity4AE5) == 1784);

extern Entity4AE5* gEntity4AE5;  // 0x03002B2C

void FUN_08001878(void) { gEntity4AE5 = NULL; }

NAKED void FUN_08001884(rgb555* dst, rgb555* src1, rgb555* src2, u32 bytesize, u32 param_5, u32 param_6) { INCFUNC("asm/func/FUN_08001884.inc"); }

NAKED void FUN_08001944(rgb555* dst, rgb555* src, u32 bytesize, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_08001944.inc"); }

NAKED void FUN_080019dc(Entity4AE5* p) { INCFUNC("asm/func/FUN_080019dc.inc"); }

NAKED void FUN_08001a18(Entity4AE5* p, u32 rgb555val) { INCFUNC("asm/func/FUN_08001a18.inc"); }

NAKED void FUN_08001a34(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001a34.inc"); }

NAKED s32 FUN_08001a64(void* _) { INCFUNC("asm/func/FUN_08001a64.inc"); }

NAKED void FUN_08001a84(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001a84.inc"); }

NAKED void FUN_08001a94(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001a94.inc"); }

NAKED void FUN_08001ad0(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001ad0.inc"); }

NAKED void FUN_08001b2c(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001b2c.inc"); }

NAKED void FUN_08001b58(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001b58.inc"); }

NAKED void FUN_08001bd0(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001bd0.inc"); }

void (*const PTR_ARRAY_085aa624[4])(Entity4AE5*) = {
    FUN_08001a84,
    FUN_08001a94,
    FUN_08001ad0,
    FUN_08001b2c,
};  // 0x085aa624

NAKED void FUN_08001c10(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001c10.inc"); }

NAKED void FUN_08001cbc(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001cbc.inc"); }

NAKED void FUN_08001e20(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001e20.inc"); }

NAKED void FUN_08001ea4(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001ea4.inc"); }

NAKED void FUN_08001ef8(Entity4AE5* p) { INCFUNC("asm/func/FUN_08001ef8.inc"); }

NAKED void FUN_08001f54(s32 kw_i, FileID plttFileID, s32 kw_f) { INCFUNC("asm/func/FUN_08001f54.inc"); }

NAKED void VM_SubCA7D(void) { INCFUNC("asm/func/VM_SubCA7D.inc"); }

NAKED void FUN_0800205c(s32 val, s32 param_2, unknown* param3) { INCFUNC("asm/func/FUN_0800205c.inc"); }

NAKED void FUN_080020bc(void) { INCFUNC("asm/func/FUN_080020bc.inc"); }

// clang-format off
void (*const PTR_ARRAY_085aa634[7])(Entity4AE5*) = {
    (void*)NULL,
    FUN_08001e20,
    FUN_08001ef8,
    FUN_08001ea4,
    FUN_08001ef8,
    FUN_08001ea4,
    (void*)NULL,
}; // 0x085aa634
// clang-format on

NAKED s32 Entity4AE5_Update(Entity4AE5* p) { INCFUNC("asm/func/Entity4AE5_Update.inc"); }

s32 Entity4AE5_Destroy(Entity4AE5* p) { gEntity4AE5 = NULL; }

NAKED s32 Entity4AE5_Init(Entity4AE5* p, u32 val) { INCFUNC("asm/func/Entity4AE5_Init.inc"); }

NAKED Entity4AE5* Entity4AE5_Create(u32 val) { INCFUNC("asm/func/Entity4AE5_Create.inc"); }
