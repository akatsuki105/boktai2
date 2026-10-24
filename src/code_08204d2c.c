#include "entity_286f.h"
#include "global.h"

static rgb555 rgb555_ARRAY_03000228[16];  // 0x03000228

COMMON_DATA u32 u32_03002c90 = 0;                          // 0x03002C90
COMMON_DATA u8 u8_03002c94[0x03002C98 - 0x03002C94] = {};  // unused?

// src/entity_286f.c
void FUN_08042178(Entity286F*, Entity286FNode*, s32);
void FUN_080421bc(Entity286F*, Entity286FNode*, s32);
void FUN_08042200(Entity286F*, Entity286FNode*, s32);
void FUN_0804234c(Entity286F*, Entity286FNode*, s32);
void FUN_08042414(Entity286F*, Entity286FNode*, s32);
void FUN_08042638(Entity286F*, Entity286FNode*, s32);
void FUN_08042868(Entity286F*, Entity286FNode*, s32);
void FUN_080428b8(Entity286F*, Entity286FNode*, s32);
void FUN_08042a48(Entity286F*, Entity286FNode*, s32);
void FUN_08042cf0(Entity286F*, Entity286FNode*, s32);
void FUN_08042d50(Entity286F*, Entity286FNode*, s32);
void FUN_08042f34(Entity286F*, Entity286FNode*, s32);
void FUN_08043108(Entity286F*, Entity286FNode*, s32);
void FUN_08043360(Entity286F*, Entity286FNode*, s32);
void FUN_0804355c(Entity286F*, Entity286FNode*);
void FUN_08043588(Entity286F*, Entity286FNode*);
void FUN_080435b4(Entity286F*, Entity286FNode*);
void FUN_080435f0(Entity286F*, Entity286FNode*);
void FUN_0804364c(Entity286F*, Entity286FNode*);
void FUN_08043688(Entity286F*, Entity286FNode*);
void FUN_080436c4(Entity286F*, Entity286FNode*);
void FUN_08043774(Entity286F*, Entity286FNode*);
void FUN_08043960(Entity286F*, Entity286FNode*);
void FUN_08043a24(Entity286F*, Entity286FNode*);
void FUN_08043bcc(Entity286F*, Entity286FNode*);
void FUN_08043c94(Entity286F*, Entity286FNode*);
void FUN_08043cc4(Entity286F*, Entity286FNode*);
void FUN_08043cf4(Entity286F*, Entity286FNode*);
void FUN_08043da8(Entity286F*, Entity286FNode*);
void FUN_08043e54(Entity286F*, Entity286FNode*);

NAKED void FUN_08204d2c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08204d2c.inc"); }

NAKED void FUN_08204d60(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08204d60.inc"); }

NAKED void FUN_08204d94(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08204d94.inc"); }

NAKED void FUN_08204dd8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08204dd8.inc"); }

NAKED void FUN_08204e0c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08204e0c.inc"); }

NAKED void FUN_08204e40(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08204e40.inc"); }

void FUN_08204e58(Entity286F* p, Entity286FNode* node) { FUN_08204e40(p, node); }

NAKED void FUN_08204e64(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08204e64.inc"); }

NAKED void FUN_08204f94(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08204f94.inc"); }

NAKED void FUN_08205018(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08205018.inc"); }

NAKED void FUN_082050fc(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082050fc.inc"); }

NAKED void FUN_08205178(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08205178.inc"); }

NAKED void FUN_08205438(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08205438.inc"); }

NAKED void FUN_0820556c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820556c.inc"); }

NAKED s32 FUN_08205664(Entity286FNode* node) { INCFUNC("asm/func/FUN_08205664.inc"); }

NAKED void FUN_082056a0(Entity286FNode* node) { INCFUNC("asm/func/FUN_082056a0.inc"); }

NAKED s32 FUN_082058d8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082058d8.inc"); }

NAKED s32 FUN_08205990(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08205990.inc"); }

NAKED s32 FUN_082059bc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082059bc.inc"); }

NAKED s32 FUN_082059d8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082059d8.inc"); }

NAKED s32 FUN_082059e4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082059e4.inc"); }

// 0xBB34, HashName("おてんこ")
NAKED void FUN_08205a18(void) { INCFUNC("asm/func/FUN_08205a18.inc"); }

// 0x8918
NAKED void FUN_08205cb0(void) { INCFUNC("asm/func/FUN_08205cb0.inc"); }

// 0x6CBE
NAKED void FUN_08205dec(void) { INCFUNC("asm/func/FUN_08205dec.inc"); }

// 0x4EBF
NAKED void FUN_08205e68(void) { INCFUNC("asm/func/FUN_08205e68.inc"); }

// 0x11D9
NAKED void FUN_08205ee0(void) { INCFUNC("asm/func/FUN_08205ee0.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085ae8dc (state) / PTR_ARRAY_085ae928 (unk_2cc) を使うノード種別

NAKED void FUN_08205efc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08205efc.inc"); }

NAKED void FUN_08205f38(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08205f38.inc"); }

NAKED void FUN_08205f74(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08205f74.inc"); }

NAKED void FUN_08205fb0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08205fb0.inc"); }

void FUN_08205fc8(Entity286F* p, Entity286FNode* node) { FUN_08205fb0(p, node); }

NAKED s32 FUN_08205fd4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08205fd4.inc"); }

NAKED void FUN_08205fe0(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08205fe0.inc"); }

NAKED void FUN_0820602c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820602c.inc"); }

NAKED void FUN_08206084(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08206084.inc"); }

NAKED s32 FUN_08206118(Entity286FNode* node) { INCFUNC("asm/func/FUN_08206118.inc"); }

NAKED s32 FUN_08206154(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206154.inc"); }

NAKED void FUN_08206188(Entity286FNode* node) { INCFUNC("asm/func/FUN_08206188.inc"); }

NAKED void FUN_08206354(Entity286FNode* node) { INCFUNC("asm/func/FUN_08206354.inc"); }

NAKED s32 FUN_082063ec(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082063ec.inc"); }

NAKED s32 FUN_0820640c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820640c.inc"); }

NAKED s32 FUN_08206424(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206424.inc"); }

// 0x3004
NAKED void FUN_08206434(void) { INCFUNC("asm/func/FUN_08206434.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085ae96c (state) / PTR_ARRAY_085ae9c8 (unk_2cc) を使うノード種別

NAKED void FUN_082066c8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082066c8.inc"); }

NAKED void FUN_082066f0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082066f0.inc"); }

NAKED void FUN_08206718(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206718.inc"); }

NAKED void FUN_0820673c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820673c.inc"); }

NAKED void FUN_08206764(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206764.inc"); }

NAKED void FUN_0820678c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820678c.inc"); }

NAKED void FUN_082067c0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082067c0.inc"); }

NAKED void FUN_08206898(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206898.inc"); }

void FUN_082068b0(Entity286F* p, Entity286FNode* node) { FUN_08206898(p, node); }

NAKED s32 FUN_082068bc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082068bc.inc"); }

NAKED void FUN_082068c8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082068c8.inc"); }

NAKED void FUN_08206918(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08206918.inc"); }

NAKED void FUN_08206968(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08206968.inc"); }

NAKED void FUN_082069b8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082069b8.inc"); }

NAKED void FUN_08206a08(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08206a08.inc"); }

NAKED void FUN_08206a7c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08206a7c.inc"); }

NAKED void FUN_08206ad4(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08206ad4.inc"); }

NAKED s32 FUN_08206b0c(Entity286FNode* node) { INCFUNC("asm/func/FUN_08206b0c.inc"); }

NAKED s32 FUN_08206b48(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206b48.inc"); }

NAKED void FUN_08206b7c(Entity286FNode* node) { INCFUNC("asm/func/FUN_08206b7c.inc"); }

NAKED s32 FUN_08206d8c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206d8c.inc"); }

NAKED s32 FUN_08206dac(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206dac.inc"); }

NAKED s32 FUN_08206db8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08206db8.inc"); }

// 0xC347
NAKED void FUN_08206dc8(void) { INCFUNC("asm/func/FUN_08206dc8.inc"); }

// 0x8894
NAKED void FUN_082070bc(void) { INCFUNC("asm/func/FUN_082070bc.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aea1c (unk_2cc) / PTR_ARRAY_085aea70 (state) を使うノード種別

NAKED void FUN_08207120(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08207120.inc"); }

NAKED void FUN_08207170(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08207170.inc"); }

NAKED void FUN_082071c0(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082071c0.inc"); }

NAKED void FUN_08207210(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08207210.inc"); }

NAKED void FUN_08207298(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08207298.inc"); }

NAKED void FUN_082072f0(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082072f0.inc"); }

NAKED void FUN_0820738c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820738c.inc"); }

NAKED s32 FUN_082073dc(Entity286FNode* node) { INCFUNC("asm/func/FUN_082073dc.inc"); }

NAKED s32 FUN_08207418(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207418.inc"); }

NAKED void FUN_0820744c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820744c.inc"); }

NAKED void FUN_08207474(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207474.inc"); }

NAKED void FUN_082074a8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082074a8.inc"); }

NAKED void FUN_082074d0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082074d0.inc"); }

NAKED void FUN_082074f8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082074f8.inc"); }

NAKED void FUN_0820752c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820752c.inc"); }

NAKED void FUN_08207550(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207550.inc"); }

NAKED void FUN_08207578(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207578.inc"); }

void FUN_08207590(Entity286F* p, Entity286FNode* node) { FUN_08207578(p, node); }

NAKED s32 FUN_0820759c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820759c.inc"); }

NAKED void FUN_082075a8(Entity286FNode* node) { INCFUNC("asm/func/FUN_082075a8.inc"); }

NAKED s32 FUN_082077bc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082077bc.inc"); }

NAKED s32 FUN_082077dc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082077dc.inc"); }

NAKED s32 FUN_082077e8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082077e8.inc"); }

// 0xF33F
NAKED void FUN_082077f8(void) { INCFUNC("asm/func/FUN_082077f8.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aeacc (state) / PTR_ARRAY_085aeb18 (unk_2cc) を使うノード種別

NAKED void FUN_08207ac4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207ac4.inc"); }

NAKED void FUN_08207af0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207af0.inc"); }

NAKED void FUN_08207b1c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207b1c.inc"); }

NAKED void FUN_08207b48(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207b48.inc"); }

void FUN_08207b60(Entity286F* p, Entity286FNode* node) { FUN_08207b48(p, node); }

NAKED s32 FUN_08207b6c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207b6c.inc"); }

NAKED void FUN_08207b78(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08207b78.inc"); }

NAKED void FUN_08207bbc(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08207bbc.inc"); }

NAKED void FUN_08207c00(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08207c00.inc"); }

NAKED s32 FUN_08207c44(Entity286FNode* node) { INCFUNC("asm/func/FUN_08207c44.inc"); }

NAKED s32 FUN_08207c80(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207c80.inc"); }

NAKED void FUN_08207cb4(Entity286FNode* node) { INCFUNC("asm/func/FUN_08207cb4.inc"); }

NAKED s32 FUN_08207e94(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207e94.inc"); }

NAKED s32 FUN_08207eb4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207eb4.inc"); }

NAKED s32 FUN_08207ec0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08207ec0.inc"); }

// 0xB189
NAKED void FUN_08207ed0(void) { INCFUNC("asm/func/FUN_08207ed0.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aeb5c (state) / PTR_ARRAY_085aebc4 (unk_2cc) を使うノード種別

NAKED void FUN_08208160(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08208160.inc"); }

NAKED void FUN_08208194(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08208194.inc"); }

NAKED void FUN_082081c0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082081c0.inc"); }

NAKED void FUN_082081ec(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082081ec.inc"); }

NAKED void FUN_08208214(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08208214.inc"); }

NAKED void FUN_08208240(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08208240.inc"); }

NAKED void FUN_08208274(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08208274.inc"); }

NAKED void FUN_0820829c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820829c.inc"); }

NAKED void FUN_082082c0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082082c0.inc"); }

NAKED void FUN_082082f4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082082f4.inc"); }

NAKED void FUN_08208320(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08208320.inc"); }

void FUN_08208338(Entity286F* p, Entity286FNode* node) { FUN_08208320(p, node); }

NAKED s32 FUN_08208344(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08208344.inc"); }

NAKED void FUN_08208350(Entity286FNode* node, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08208350.inc"); }

NAKED void FUN_08208458(Entity286FNode* node, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08208458.inc"); }

NAKED void FUN_0820848c(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820848c.inc"); }

NAKED void FUN_082084ec(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082084ec.inc"); }

NAKED void FUN_08208628(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208628.inc"); }

NAKED void FUN_082086d8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082086d8.inc"); }

NAKED void FUN_08208808(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208808.inc"); }

NAKED void FUN_08208858(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208858.inc"); }

NAKED void FUN_082088a8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082088a8.inc"); }

NAKED void FUN_082088f8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_082088f8.inc"); }

NAKED void FUN_08208990(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208990.inc"); }

NAKED void FUN_08208b50(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208b50.inc"); }

NAKED void FUN_08208c64(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208c64.inc"); }

NAKED void FUN_08208ce8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208ce8.inc"); }

NAKED void FUN_08208e18(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208e18.inc"); }

NAKED void FUN_08208ec8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_08208ec8.inc"); }

NAKED s32 FUN_08209134(Entity286FNode* node) { INCFUNC("asm/func/FUN_08209134.inc"); }

NAKED s32 FUN_0820919c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820919c.inc"); }

NAKED void FUN_082091f0(Entity286FNode* node) { INCFUNC("asm/func/FUN_082091f0.inc"); }

NAKED s32 FUN_082094f8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082094f8.inc"); }

NAKED s32 FUN_08209518(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209518.inc"); }

NAKED s32 FUN_08209524(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209524.inc"); }

NAKED void FUN_08209534(s32 param_1) { INCFUNC("asm/func/FUN_08209534.inc"); }

// 0xD774
NAKED void FUN_082097dc(void) { INCFUNC("asm/func/FUN_082097dc.inc"); }

// 0x82C8
NAKED void FUN_082097e8(void) { INCFUNC("asm/func/FUN_082097e8.inc"); }

// 0x9DFE
NAKED void FUN_082097f4(void) { INCFUNC("asm/func/FUN_082097f4.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aec24 (state) / PTR_ARRAY_085aec68 (unk_2cc) を使うノード種別

NAKED void FUN_08209838(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209838.inc"); }

NAKED void FUN_08209874(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209874.inc"); }

void FUN_0820988c(Entity286F* p, Entity286FNode* node) { FUN_08209874(p, node); }

NAKED s32 FUN_08209898(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209898.inc"); }

NAKED s32 FUN_082098a4(Entity286FNode* node) { INCFUNC("asm/func/FUN_082098a4.inc"); }

NAKED s32 FUN_082098e0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_082098e0.inc"); }

NAKED void FUN_08209914(Entity286FNode* node) { INCFUNC("asm/func/FUN_08209914.inc"); }

NAKED s32 FUN_08209ad4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209ad4.inc"); }

NAKED s32 FUN_08209af4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209af4.inc"); }

NAKED s32 FUN_08209b00(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209b00.inc"); }

// 0x40A6
NAKED void FUN_08209b10(void) { INCFUNC("asm/func/FUN_08209b10.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aeca4 (state) / PTR_ARRAY_085aece4 (unk_2cc) を使うノード種別

NAKED void FUN_08209da0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209da0.inc"); }

void FUN_08209db8(Entity286F* p, Entity286FNode* node) { FUN_08209da0(p, node); }

NAKED s32 FUN_08209dc4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209dc4.inc"); }

NAKED s32 FUN_08209dd0(Entity286FNode* node) { INCFUNC("asm/func/FUN_08209dd0.inc"); }

NAKED s32 FUN_08209e0c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209e0c.inc"); }

NAKED void FUN_08209e40(Entity286FNode* node) { INCFUNC("asm/func/FUN_08209e40.inc"); }

NAKED s32 FUN_08209f8c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209f8c.inc"); }

NAKED s32 FUN_08209fac(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209fac.inc"); }

NAKED s32 FUN_08209fb8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_08209fb8.inc"); }

// 0x5470
NAKED void FUN_08209fc8(void) { INCFUNC("asm/func/FUN_08209fc8.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aed1c (state) / PTR_ARRAY_085aed5c (unk_2cc) を使うノード種別

NAKED void FUN_0820a258(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a258.inc"); }

void FUN_0820a270(Entity286F* p, Entity286FNode* node) { FUN_0820a258(p, node); }

NAKED s32 FUN_0820a27c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a27c.inc"); }

NAKED s32 FUN_0820a288(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a288.inc"); }

NAKED s32 FUN_0820a2c4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a2c4.inc"); }

NAKED void FUN_0820a2f8(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a2f8.inc"); }

NAKED s32 FUN_0820a444(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a444.inc"); }

NAKED s32 FUN_0820a464(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a464.inc"); }

NAKED s32 FUN_0820a470(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a470.inc"); }

// 0xA133
NAKED void FUN_0820a480(void) { INCFUNC("asm/func/FUN_0820a480.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aed94 (state) / PTR_ARRAY_085aedd4 (unk_2cc) を使うノード種別

NAKED void FUN_0820a710(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a710.inc"); }

void FUN_0820a728(Entity286F* p, Entity286FNode* node) { FUN_0820a710(p, node); }

NAKED s32 FUN_0820a734(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a734.inc"); }

NAKED s32 FUN_0820a740(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a740.inc"); }

NAKED s32 FUN_0820a77c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a77c.inc"); }

NAKED void FUN_0820a7b0(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a7b0.inc"); }

NAKED s32 FUN_0820a8fc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a8fc.inc"); }

NAKED s32 FUN_0820a91c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a91c.inc"); }

NAKED s32 FUN_0820a928(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820a928.inc"); }

// 0x3F96
NAKED void FUN_0820a938(void) { INCFUNC("asm/func/FUN_0820a938.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aee0c (state) / PTR_ARRAY_085aee5c (unk_2cc) を使うノード種別

NAKED void FUN_0820abc8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820abc8.inc"); }

NAKED void FUN_0820abec(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820abec.inc"); }

NAKED void FUN_0820ac10(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820ac10.inc"); }

NAKED void FUN_0820ac44(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820ac44.inc"); }

NAKED void FUN_0820ac80(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820ac80.inc"); }

void FUN_0820ac98(Entity286F* p, Entity286FNode* node) { FUN_0820ac80(p, node); }

NAKED s32 FUN_0820aca4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820aca4.inc"); }

NAKED void FUN_0820acb0(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820acb0.inc"); }

NAKED void FUN_0820afb0(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820afb0.inc"); }

NAKED void FUN_0820aff0(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820aff0.inc"); }

NAKED s32 FUN_0820b044(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b044.inc"); }

NAKED s32 FUN_0820b080(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b080.inc"); }

NAKED void FUN_0820b0b4(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b0b4.inc"); }

NAKED s32 FUN_0820b2bc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b2bc.inc"); }

NAKED s32 FUN_0820b2dc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b2dc.inc"); }

NAKED s32 FUN_0820b2e8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b2e8.inc"); }

// 0xCE28
NAKED void FUN_0820b2f8(void) { INCFUNC("asm/func/FUN_0820b2f8.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aeea4 (state) / PTR_ARRAY_085aeef0 (unk_2cc) を使うノード種別

NAKED void FUN_0820b5c4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b5c4.inc"); }

NAKED void FUN_0820b5f8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b5f8.inc"); }

NAKED void FUN_0820b62c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b62c.inc"); }

NAKED void FUN_0820b650(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b650.inc"); }

NAKED void FUN_0820b678(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b678.inc"); }

NAKED void FUN_0820b6b4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b6b4.inc"); }

void FUN_0820b6cc(Entity286F* p, Entity286FNode* node) { FUN_0820b6b4(p, node); }

NAKED s32 FUN_0820b6d8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820b6d8.inc"); }

NAKED void FUN_0820b6e4(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820b6e4.inc"); }

NAKED void FUN_0820b7c4(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820b7c4.inc"); }

NAKED void FUN_0820b8a0(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820b8a0.inc"); }

NAKED void FUN_0820b934(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820b934.inc"); }

NAKED void FUN_0820b9e8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820b9e8.inc"); }

NAKED s32 FUN_0820ba38(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820ba38.inc"); }

NAKED s32 FUN_0820ba74(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820ba74.inc"); }

NAKED void FUN_0820baa8(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820baa8.inc"); }

NAKED s32 FUN_0820bc90(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820bc90.inc"); }

NAKED s32 FUN_0820bcb0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820bcb0.inc"); }

NAKED s32 FUN_0820bcbc(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820bcbc.inc"); }

// 0xD229
NAKED void FUN_0820bccc(void) { INCFUNC("asm/func/FUN_0820bccc.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aef34 (state) / PTR_ARRAY_085aef78 (unk_2cc) を使うノード種別

NAKED void FUN_0820bf5c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820bf5c.inc"); }

NAKED void FUN_0820bf88(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820bf88.inc"); }

void FUN_0820bfa0(Entity286F* p, Entity286FNode* node) { FUN_0820bf88(p, node); }

NAKED s32 FUN_0820bfac(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820bfac.inc"); }

NAKED void FUN_0820bfb8(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820bfb8.inc"); }

NAKED void FUN_0820c014(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c014.inc"); }

NAKED void FUN_0820c034(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c034.inc"); }

NAKED void FUN_0820c054(Entity286F* p, Entity286FNode* node, s32 elapsed) { INCFUNC("asm/func/FUN_0820c054.inc"); }

NAKED s32 FUN_0820c1a4(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c1a4.inc"); }

NAKED s32 FUN_0820c1e0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c1e0.inc"); }

NAKED void FUN_0820c214(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c214.inc"); }

NAKED s32 FUN_0820c3a4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c3a4.inc"); }

NAKED s32 FUN_0820c3c4(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c3c4.inc"); }

NAKED s32 FUN_0820c3d0(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c3d0.inc"); }

// 0x56AD
NAKED void FUN_0820c3e0(void) { INCFUNC("asm/func/FUN_0820c3e0.inc"); }

// ---------------------------------------------------------------------------
// ここから PTR_ARRAY_085aefb4 (unk_2cc) / PTR_ARRAY_085aeff0 (state) を使うノード種別

NAKED s32 FUN_0820c658(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c658.inc"); }

NAKED s32 FUN_0820c694(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c694.inc"); }

NAKED void FUN_0820c6c8(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c6c8.inc"); }

NAKED void FUN_0820c704(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c704.inc"); }

NAKED void FUN_0820c71c(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c71c.inc"); }

NAKED s32 FUN_0820c728(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c728.inc"); }

NAKED void FUN_0820c734(Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c734.inc"); }

NAKED s32 FUN_0820c904(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c904.inc"); }

NAKED s32 FUN_0820c924(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c924.inc"); }

NAKED s32 FUN_0820c930(Entity286F* p, Entity286FNode* node) { INCFUNC("asm/func/FUN_0820c930.inc"); }

// 0x8EA3
NAKED void FUN_0820c940(void) { INCFUNC("asm/func/FUN_0820c940.inc"); }

// clang-format off
void (*const PTR_ARRAY_085ae83c[21])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08204d2c,
    FUN_08204d60,
    FUN_08204d94,
    FUN_08204dd8,
    FUN_08204e0c,
};  // 0x085AE83C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085ae890[19])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08204e64,
    FUN_08204f94,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08205018,
    FUN_082050fc,
    FUN_08205178,
    FUN_08205438,
    FUN_0820556c,
};  // 0x085AE890
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085ae8dc[19])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08205efc,
    FUN_08205f38,
    FUN_08205f74,
};  // 0x085AE8DC
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085ae928[17])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08205fe0,
    FUN_0820602c,
    FUN_08206084,
};  // 0x085AE928
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085ae96c[23])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_082066c8,
    FUN_082066f0,
    FUN_08206718,
    FUN_0820673c,
    FUN_08206764,
    FUN_0820678c,
    FUN_082067c0,
};  // 0x085AE96C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085ae9c8[21])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_082068c8,
    FUN_08206918,
    FUN_08206968,
    FUN_08206ad4,
    FUN_082069b8,
    FUN_08206a08,
    FUN_08206a7c,
};  // 0x085AE9C8
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aea1c[21])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08207120,
    FUN_08207170,
    FUN_082071c0,
    FUN_08207210,
    FUN_08207298,
    FUN_082072f0,
    FUN_0820738c,
};  // 0x085AEA1C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aea70[23])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820744c,
    FUN_08207474,
    FUN_082074a8,
    FUN_082074d0,
    FUN_082074f8,
    FUN_0820752c,
    FUN_08207550,
};  // 0x085AEA70
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aeacc[19])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08207ac4,
    FUN_08207af0,
    FUN_08207b1c,
};  // 0x085AEACC
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aeb18[17])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08207b78,
    FUN_08207bbc,
    FUN_08207c00,
};  // 0x085AEB18
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aeb5c[26])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08208160,
    FUN_08208194,
    FUN_082081c0,
    FUN_082081ec,
    FUN_08208214,
    FUN_08208240,
    FUN_08208274,
    FUN_0820829c,
    FUN_082082c0,
    FUN_082082f4,
};  // 0x085AEB5C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aebc4[24])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_0820848c,
    FUN_082084ec,
    FUN_08208628,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08208ec8,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_082086d8,
    FUN_08208808,
    FUN_08208858,
    FUN_082088a8,
    FUN_082088f8,
    FUN_08208990,
    FUN_08208b50,
    FUN_08208c64,
    FUN_08208ce8,
    FUN_08208e18,
};  // 0x085AEBC4
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aec24[17])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_08209838,
};  // 0x085AEC24
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aec68[15])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08043360,
};  // 0x085AEC68
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aeca4[16])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
};  // 0x085AECA4
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aece4[14])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
};  // 0x085AECE4
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aed1c[16])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
};  // 0x085AED1C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aed5c[14])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
};  // 0x085AED5C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aed94[16])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
};  // 0x085AED94
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aedd4[14])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
};  // 0x085AEDD4
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aee0c[20])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820abc8,
    FUN_0820abec,
    FUN_0820ac10,
    FUN_0820ac44,
};  // 0x085AEE0C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aee5c[18])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_0820acb0,
    FUN_0820afb0,
    FUN_0820aff0,
    FUN_08043360,
};  // 0x085AEE5C
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aeea4[19])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0820b5c4,
    FUN_0820b5f8,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820b62c,
    FUN_0820b650,
    FUN_0820b678,
};  // 0x085AEEA4
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aeef0[17])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_0820b6e4,
    FUN_0820b7c4,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_0820b8a0,
    FUN_0820b934,
    FUN_0820b9e8,
};  // 0x085AEEF0
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aef34[17])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820bf5c,
};  // 0x085AEF34
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aef78[15])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_0820bfb8,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_0820c054,
};  // 0x085AEF78
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aefb4[15])(Entity286F*, Entity286FNode*, s32) = {
    NULL,
    FUN_08042178,
    FUN_080421bc,
    FUN_08042200,
    FUN_0804234c,
    FUN_08042414,
    FUN_08042638,
    FUN_08042868,
    FUN_080428b8,
    FUN_08042a48,
    FUN_08042cf0,
    FUN_08042d50,
    FUN_08042f34,
    FUN_08043108,
    FUN_08043360,
};  // 0x085AEFB4
// clang-format on

// clang-format off
void (*const PTR_ARRAY_085aeff0[17])(Entity286F*, Entity286FNode*) = {
    FUN_0804355c,
    FUN_08043588,
    FUN_080435b4,
    FUN_080435f0,
    FUN_0804364c,
    FUN_08043688,
    FUN_080436c4,
    FUN_08043774,
    FUN_08043960,
    FUN_08043a24,
    FUN_08043bcc,
    FUN_08043c94,
    FUN_08043cc4,
    FUN_08043cf4,
    FUN_08043da8,
    FUN_08043e54,
    FUN_0820c6c8,
};  // 0x085AEFF0
// clang-format on
