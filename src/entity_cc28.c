#include "entity.h"
#include "global.h"
#include "item.h"
#include "menu.h"
#include "player.h"
#include "sprite.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// メニューのインベントリ操作に関係してそう
typedef struct EntityCC28 EntityCC28;
typedef void(EntityCC28Func)(EntityCC28* p);  // _Update が p->fn(p) として呼ぶ

typedef struct {
  MainSprite sprite;      // 0x0000
  u8 unk_60;              // 0x0060
  u8 unk_61;              // 0x0061
  u8 unk_62[100 - 0x62];  // 0x0062, まだ未解析
} EntityCC28Sprite100;
static_assert(sizeof(EntityCC28Sprite100) == 100);

typedef struct {
  MainSprite sprite;       // 0x0000
  u8 unk_60;               // 0x0060
  u8 unk_61;               // 0x0061
  u8 unk_62[0x64 - 0x62];  // 0x0062, まだ未解析
  u8 unk_64;               // 0x0064
  u8 unk_65;               // 0x0065
  u8 unk_66[104 - 0x66];   // 0x0066, まだ未解析
} EntityCC28Sprite104;
static_assert(sizeof(EntityCC28Sprite104) == 104);

struct EntityCC28 {
  Entity e;                        // 0x0000, ENTITY_UNK_12
  void* unk_18;                    // 0x0018
  u8 unk_1c[0x20 - 0x1C];          // 0x001C, まだ未解析
  void* unk_20[2];                 // 0x0020
  void* unk_28;                    // 0x0028
  u8 unk_2c[0x34 - 0x2C];          // 0x002C, まだ未解析
  void* unk_34[2];                 // 0x0034
  u8 unk_3c[0x5C - 0x3C];          // 0x003C, まだ未解析
  u32 unk_5c;                      // 0x005C
  MainSpriteGfx gfx[9];            // 0x0060
  BgState savedBg1;                // 0x0180
  u16 savedTilemap1[1024];         // 0x01B0
  u16 unk_9b0;                     // 0x09B0
  u8 unk_9b2[0x9B4 - 0x9B2];       // 0x09B2, まだ未解析
  u16 unk_9b4;                     // 0x09B4
  u8 unk_9b6[0x9B8 - 0x9B6];       // 0x09B6, まだ未解析
  u16 unk_9b8;                     // 0x09B8
  u8 unk_9ba[0x9D8 - 0x9BA];       // 0x09BA, まだ未解析
  u16 unk_9d8;                     // 0x09D8
  u16 unk_9da;                     // 0x09DA
  u8 unk_9dc;                      // 0x09DC
  u8 unk_9dd;                      // 0x09DD
  s8 unk_9de;                      // 0x09DE
  u8 unk_9df[0x9E0 - 0x9DF];       // 0x09DF, まだ未解析
  Player* player;                  // 0x09E0
  u8 unk_9e4[0x9EC - 0x9E4];       // 0x09E4, まだ未解析
  u16 unk_9ec;                     // 0x09EC
  u16 unk_9ee;                     // 0x09EE
  void* fn_9f0;                    // 0x09F0
  EntityCC28Func* fn;              // 0x09F4
  s8 unk_9f8;                      // 0x09F8
  u8 unk_9f9[0x9FA - 0x9F9];       // 0x09F9, まだ未解析
  s16 unk_9fa;                     // 0x09FA
  u16 unk_9fc;                     // 0x09FC
  u8 unk_9fe[0x9FF - 0x9FE];       // 0x09FE, まだ未解析
  u8 unk_9ff;                      // 0x09FF
  u16 unk_a00;                     // 0x0A00
  u16 unk_a02;                     // 0x0A02
  u16 unk_a04;                     // 0x0A04
  u16 unk_a06;                     // 0x0A06
  u16 unk_a08;                     // 0x0A08
  s16 unk_a0a;                     // 0x0A0A
  u8 unk_a0c;                      // 0x0A0C
  u8 unk_a0d;                      // 0x0A0D
  u16 unk_a0e;                     // 0x0A0E
  u16 unk_a10;                     // 0x0A10
  s16 unk_a12;                     // 0x0A12
  u8 unk_a14;                      // 0x0A14
  u8 unk_a15;                      // 0x0A15
  u16 unk_a16;                     // 0x0A16
  u8 unk_a18[0xA1C - 0xA18];       // 0x0A18, まだ未解析
  s16 unk_a1c;                     // 0x0A1C
  s16 unk_a1e;                     // 0x0A1E
  u16 unk_a20;                     // 0x0A20
  s16 unk_a22;                     // 0x0A22
  u8 unk_a24;                      // 0x0A24
  u8 unk_a25[0xA2A - 0xA25];       // 0x0A25, まだ未解析
  u8 unk_a2a;                      // 0x0A2A
  u8 unk_a2b[0xA2F - 0xA2B];       // 0x0A2B, まだ未解析
  u8 unk_a2f;                      // 0x0A2F
  u8 unk_a30;                      // 0x0A30
  u8 unk_a31;                      // 0x0A31
  u8 unk_a32[0xA34 - 0xA32];       // 0x0A32, まだ未解析
  MainSprite unk_a34;              // 0x0A34
  u8 unk_a94;                      // 0x0A94
  u8 unk_a95;                      // 0x0A95
  u8 unk_a96;                      // 0x0A96
  u8 unk_a97;                      // 0x0A97
  u8 unk_a98;                      // 0x0A98
  u8 unk_a99;                      // 0x0A99
  u8 unk_a9a;                      // 0x0A9A
  u8 unk_a9b;                      // 0x0A9B
  u16* unk_a9c;                    // 0x0A9C
  MainSprite unk_aa0[2];           // 0x0AA0
  u32 unk_b60;                     // 0x0B60
  u8 unk_b64[0xBB8 - 0xB64];       // 0x0B64, まだ未解析
  u32 unk_bb8;                     // 0x0BB8
  u8 unk_bbc[0xBBF - 0xBBC];       // 0x0BBC, まだ未解析
  u8 unk_bbf;                      // 0x0BBF
  u8 unk_bc0[0xBD4 - 0xBC0];       // 0x0BC0, まだ未解析
  u16 unk_bd4;                     // 0x0BD4
  u16 unk_bd6;                     // 0x0BD6
  u16 unk_bd8;                     // 0x0BD8
  u8 unk_bda[0xBE4 - 0xBDA];       // 0x0BDA, まだ未解析
  AuxSpriteGfx unk_be4;            // 0x0BE4
  u8 unk_c00;                      // 0x0C00
  u8 unk_c01;                      // 0x0C01
  u8 unk_c02;                      // 0x0C02
  u8 unk_c03;                      // 0x0C03
  u32 unk_c04;                     // 0x0C04
  u8 unk_c08;                      // 0x0C08
  u8 unk_c09;                      // 0x0C09
  u8 unk_c0a[0xC0C - 0xC0A];       // 0x0C0A, まだ未解析
  EntityCC28Sprite100 unk_c0c[4];  // 0x0C0C
  u8 unk_d9c;                      // 0x0D9C
  u8 unk_d9d;                      // 0x0D9D
  u8 unk_d9e[0xDA0 - 0xD9E];       // 0x0D9E, まだ未解析
  u8* unk_da0;                     // 0x0DA0
  EntityCC28Sprite104 unk_da4[4];  // 0x0DA4
  u8 unk_f44[0xF56 - 0xF44];       // 0x0F44, まだ未解析
  u8 state2;                       // 0x0F56
  u8 unk_f57[0xFC4 - 0xF57];       // 0x0F57, まだ未解析
  MainSprite sprites[115];         // 0x0FC4
  u8 unk_3ae4;                     // 0x3AE4
  u8 unk_3ae5[0x3AE6 - 0x3AE5];    // 0x3AE5, まだ未解析
  u8 unk_3ae6;                     // 0x3AE6
  u8 unk_3ae7;                     // 0x3AE7
  u8 unk_3ae8;                     // 0x3AE8
  u8 unk_3ae9[0x3AEB - 0x3AE9];    // 0x3AE9, まだ未解析
  u8 unk_3aeb;                     // 0x3AEB
  u8 unk_3aec;                     // 0x3AEC
  u8 unk_3aed;                     // 0x3AED
  u8 selectedSlot;                 // 0x3AEE
  u8 unk_3aef[0x3AF0 - 0x3AEF];    // 0x3AEF, まだ未解析
  u8 unk_3af0;                     // 0x3AF0
  u8 unk_3af1[0x3B10 - 0x3AF1];    // 0x3AF1, まだ未解析
  u8 unk_3b10;                     // 0x3B10
  u8 unk_3b11[0x3B13 - 0x3B11];    // 0x3B11, まだ未解析
  u8 unk_3b13;                     // 0x3B13
  u16 unk_3b14;                    // 0x3B14
  u16 unk_3b16;                    // 0x3B16
  u16 unk_3b18;                    // 0x3B18
  u8 unk_3b1a;                     // 0x3B1A
  u8 unk_3b1b;                     // 0x3B1B
  u16 unk_3b1c;                    // 0x3B1C
  u16 unk_3b1e;                    // 0x3B1E
  u16 unk_3b20;                    // 0x3B20
  u16 unk_3b22;                    // 0x3B22
  u8 unk_3b24;                     // 0x3B24
  u8 unk_3b25;                     // 0x3B25
  u8 unk_3b26[0x3B28 - 0x3B26];    // 0x3B26, まだ未解析
  s16 unk_3b28[32];                // 0x3B28
  s16 unk_3b68[2];                 // 0x3B68
  u8 unk_3b6c[0x3B70 - 0x3B6C];    // 0x3B6C, まだ未解析
  s16 unk_3b70[2];                 // 0x3B70
  u8 unk_3b74[0x3F9C - 0x3B74];    // 0x3B74, まだ未解析
  u8 inValuableInventory;          // 0x3F9C
  u8 unk_3f9d;                     // 0x3F9D
  u8 unk_3f9e;                     // 0x3F9E
  u8 unk_3f9f;                     // 0x3F9F
  u8 unk_3fa0[140];                // 0x3FA0
  void* unk_402c[3];               // 0x402C
  u32 unk_4038;                    // 0x4038
  u8 unk_403c[20];                 // 0x403C
  u16 unk_4050;                    // 0x4050
  u16 unk_4052;                    // 0x4052
  u16 unk_4054;                    // 0x4054
  u16 unk_4056;                    // 0x4056
  u16 unk_4058[2];                 // 0x4058
};
static_assert(sizeof(EntityCC28) == 16476);

extern EntityCC28* gEntityCC28;  // 0x0300013C

const u16 u16_ARRAY_085ac064[16] = {
    0xD01B, 0xD000, 0xD000, 0xD41B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD81B, 0xD000, 0xD000, 0xDC1B,
};

// TODO: 他のEntityのrodataもまだ混ざってるかもしれない
INCRODATA(".rodata", "data/rodata3.bin");  // ./tools/bin.ts ./baserom.gba 0x085ac084 0x085ad014 ./data/rodata3.bin

NAKED void FUN_0808a33c(EntityCC28* p, unknown* param_2) { INCFUNC("asm/func/FUN_0808a33c.inc"); }

NAKED void FUN_0808a354(EntityCC28* p, EntityCC28Func* fn, s8 param_3) { INCFUNC("asm/func/FUN_0808a354.inc"); }

NAKED void FUN_0808a3c4(EntityCC28* p, TilemapFile* param_2, s16 param_3, s32 param_4, unknown* param_5) { INCFUNC("asm/func/FUN_0808a3c4.inc"); }

NAKED void FUN_0808a420(s32 param_1, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0808a420.inc"); }

NAKED s32 FUN_0808a440(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_0808a440.inc"); }

NAKED void FUN_0808a458(s32 param_1, u16 param_2) { INCFUNC("asm/func/FUN_0808a458.inc"); }

NAKED s32 MinS32(s32 a, s32 b) { INCFUNC("asm/func/MinS32.inc"); }

NAKED void FUN_0808a4ac(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_0808a4ac.inc"); }

NAKED void FUN_0808a5b0(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808a5b0.inc"); }

NAKED void FUN_0808a5e0(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808a5e0.inc"); }

NAKED s32 FUN_0808a610(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808a610.inc"); }

NAKED s32 FUN_0808a768(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808a768.inc"); }

void FUN_0808a9a0(void) {}

NAKED void FUN_0808a9a4(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808a9a4.inc"); }

NAKED void FUN_0808abec(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_0808abec.inc"); }

NAKED void FUN_0808ad5c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ad5c.inc"); }

NAKED void FUN_0808afac(EntityCC28* p) { INCFUNC("asm/func/FUN_0808afac.inc"); }

NAKED void FUN_0808b11c(EntityCC28* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0808b11c.inc"); }

NAKED void FUN_0808b1bc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808b1bc.inc"); }

NAKED void FUN_0808b30c(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0808b30c.inc"); }

NAKED void FUN_0808b360(s32 param_1) { INCFUNC("asm/func/FUN_0808b360.inc"); }

NAKED void FUN_0808b38c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808b38c.inc"); }

NAKED void FUN_0808b4c0(EntityCC28* p) { INCFUNC("asm/func/FUN_0808b4c0.inc"); }

NAKED void FUN_0808b604(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808b604.inc"); }

NAKED u32 FUN_0808b6a4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808b6a4.inc"); }

NAKED void FUN_0808b6fc(EntityCC28* p, s8 param_2) { INCFUNC("asm/func/FUN_0808b6fc.inc"); }

NAKED bool32 FUN_0808b760(EntityCC28* p) { INCFUNC("asm/func/FUN_0808b760.inc"); }

NAKED void FUN_0808b82c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808b82c.inc"); }

NAKED void FUN_0808b86c(EntityCC28* p, u16 param_2) { INCFUNC("asm/func/FUN_0808b86c.inc"); }

NAKED void FUN_0808b8a4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808b8a4.inc"); }

NAKED void FUN_0808b910(EntityCC28* p) { INCFUNC("asm/func/FUN_0808b910.inc"); }

NAKED void FUN_0808b97c(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808b97c.inc"); }

NAKED void FUN_0808b9c4(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808b9c4.inc"); }

NAKED void FUN_0808ba0c(s32 param_1, u16 param_2) { INCFUNC("asm/func/FUN_0808ba0c.inc"); }

NAKED void FUN_0808ba20(unknown* param_1, s16* param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808ba20.inc"); }

NAKED s32 FUN_0808ba64(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ba64.inc"); }

NAKED void FUN_0808bac4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808bac4.inc"); }

NAKED void FUN_0808c028(EntityCC28* p) { INCFUNC("asm/func/FUN_0808c028.inc"); }

NAKED void FUN_0808c164(EntityCC28* p, u16 param_2, u16 param_3, u8 param_4) { INCFUNC("asm/func/FUN_0808c164.inc"); }

NAKED bool32 FUN_0808c1cc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808c1cc.inc"); }

NAKED void FUN_0808c334(s32 param_1, s32 param_2, u16 param_3, s32 param_4, s16* param_5, s16* param_6, s32 param_7, u16 param_8) { INCFUNC("asm/func/FUN_0808c334.inc"); }

NAKED s32 FUN_0808c434(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_0808c434.inc"); }

NAKED void FUN_0808c510(unknown* param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808c510.inc"); }

NAKED void FUN_0808c548(EntityCC28* p) { INCFUNC("asm/func/FUN_0808c548.inc"); }

NAKED void FUN_0808c61c(EntityCC28* p, u16 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808c61c.inc"); }

NAKED s32 FUN_0808c648(s32 param_1) { INCFUNC("asm/func/FUN_0808c648.inc"); }

NAKED void FUN_0808c658(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808c658.inc"); }

NAKED void FUN_0808c700(EntityCC28* p) { INCFUNC("asm/func/FUN_0808c700.inc"); }

NAKED s32 FUN_0808c710(unknown* param_1, ParticleGroup* param_2) { INCFUNC("asm/func/FUN_0808c710.inc"); }

NAKED s32 FUN_0808c770(unknown* param_1) { INCFUNC("asm/func/FUN_0808c770.inc"); }

NAKED void FUN_0808c7c4(s32 param_1) { INCFUNC("asm/func/FUN_0808c7c4.inc"); }

NAKED void FUN_0808c834(s32 param_1, s32 param_2, s16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_0808c834.inc"); }

NAKED void FUN_0808c95c(s32 param_1, s32 param_2, s16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_0808c95c.inc"); }

NAKED void FUN_0808cacc(s32 param_1) { INCFUNC("asm/func/FUN_0808cacc.inc"); }

NAKED void FUN_0808cb00(s32 param_1) { INCFUNC("asm/func/FUN_0808cb00.inc"); }

NAKED void FUN_0808cb90(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cb90.inc"); }

NAKED void FUN_0808cbd8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cbd8.inc"); }

NAKED void FUN_0808cc14(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cc14.inc"); }

NAKED void FUN_0808cc84(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cc84.inc"); }

NAKED void FUN_0808ce98(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ce98.inc"); }

NAKED void FUN_0808cf14(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cf14.inc"); }

void FUN_0808cf50(EntityCC28* p) { MainSprite_Remove(&p->unk_a34); }

NAKED void FUN_0808cf64(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cf64.inc"); }

NAKED void FUN_0808cffc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cffc.inc"); }

NAKED void FUN_0808d01c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d01c.inc"); }

NAKED void FUN_0808d0c0(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d0c0.inc"); }

NAKED void FUN_0808d1a8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d1a8.inc"); }

NAKED void FUN_0808d200(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d200.inc"); }

NAKED void FUN_0808d268(void) { INCFUNC("asm/func/FUN_0808d268.inc"); }

NAKED void FUN_0808d2ac(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d2ac.inc"); }

NAKED void FUN_0808d39c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d39c.inc"); }

NAKED void FUN_0808d3d4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d3d4.inc"); }

NAKED s32 FUN_0808d49c(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0808d49c.inc"); }

NAKED void FUN_0808d4dc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d4dc.inc"); }

NAKED void FUN_0808d564(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d564.inc"); }

NAKED void FUN_0808d5cc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d5cc.inc"); }

NAKED void FUN_0808d774(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d774.inc"); }

NAKED void FUN_0808d908(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d908.inc"); }

NAKED void FUN_0808d93c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d93c.inc"); }

NAKED void FUN_0808d998(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d998.inc"); }

NAKED void FUN_0808d9c8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d9c8.inc"); }

NAKED s32 FUN_0808da14(EntityCC28* p) { INCFUNC("asm/func/FUN_0808da14.inc"); }

NAKED s32 FUN_0808da88(EntityCC28* p) { INCFUNC("asm/func/FUN_0808da88.inc"); }

NAKED void FUN_0808daa8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808daa8.inc"); }

NAKED void FUN_0808db68(EntityCC28* p) { INCFUNC("asm/func/FUN_0808db68.inc"); }

NAKED void FUN_0808dcdc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808dcdc.inc"); }

NAKED void FUN_0808dda4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808dda4.inc"); }

NAKED void FUN_0808dddc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808dddc.inc"); }

NAKED void FUN_0808de30(s32 param_1) { INCFUNC("asm/func/FUN_0808de30.inc"); }

NAKED void FUN_0808de50(s32 param_1) { INCFUNC("asm/func/FUN_0808de50.inc"); }

NAKED void FUN_0808de70(EntityCC28* p) { INCFUNC("asm/func/FUN_0808de70.inc"); }

NAKED void FUN_0808df7c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808df7c.inc"); }

NAKED void FUN_0808dfcc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808dfcc.inc"); }

NAKED void FUN_0808e008(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e008.inc"); }

NAKED void FUN_0808e0e0(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808e0e0.inc"); }

NAKED void FUN_0808e17c(s32 param_1) { INCFUNC("asm/func/FUN_0808e17c.inc"); }

NAKED void FUN_0808e1b8(s32 param_1) { INCFUNC("asm/func/FUN_0808e1b8.inc"); }

NAKED void FUN_0808e1f4(void) { INCFUNC("asm/func/FUN_0808e1f4.inc"); }

NAKED void FUN_0808e224(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e224.inc"); }

NAKED void FUN_0808e400(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e400.inc"); }

NAKED void FUN_0808e420(void) { INCFUNC("asm/func/FUN_0808e420.inc"); }

NAKED void FUN_0808e4f4(void) { INCFUNC("asm/func/FUN_0808e4f4.inc"); }

NAKED void FUN_0808e53c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e53c.inc"); }

NAKED void FUN_0808e5a8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e5a8.inc"); }

NAKED void FUN_0808e734(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e734.inc"); }

NAKED void FUN_0808e83c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e83c.inc"); }

NAKED s32 FUN_0808e8b8(s32 param_1) { INCFUNC("asm/func/FUN_0808e8b8.inc"); }

NAKED void FUN_0808e8dc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e8dc.inc"); }

NAKED void FUN_0808eb4c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808eb4c.inc"); }

NAKED void FUN_0808ebe8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ebe8.inc"); }

NAKED void FUN_0808ec18(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ec18.inc"); }

NAKED void FUN_0808ed74(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ed74.inc"); }

NAKED void FUN_0808ede4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ede4.inc"); }

NAKED void FUN_0808ee50(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ee50.inc"); }

NAKED void FUN_0808eeac(EntityCC28* p) { INCFUNC("asm/func/FUN_0808eeac.inc"); }

NAKED void FUN_0808eef8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808eef8.inc"); }

NAKED void FUN_0808ef58(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ef58.inc"); }

NAKED void FUN_0808f01c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f01c.inc"); }

NAKED void FUN_0808f09c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f09c.inc"); }

NAKED void FUN_0808f0d8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f0d8.inc"); }

NAKED s32 FUN_0808f140(void) { INCFUNC("asm/func/FUN_0808f140.inc"); }

NAKED void FUN_0808f170(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f170.inc"); }

NAKED void FUN_0808f1bc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f1bc.inc"); }

NAKED void FUN_0808f21c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f21c.inc"); }

NAKED void FUN_0808f2f0(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f2f0.inc"); }

NAKED void FUN_0808f3f8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f3f8.inc"); }

NAKED void FUN_0808f4ac(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f4ac.inc"); }

NAKED void FUN_0808f520(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f520.inc"); }

NAKED void FUN_0808f604(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f604.inc"); }

NAKED void FUN_0808f670(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f670.inc"); }

NAKED void FUN_0808f774(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f774.inc"); }

NAKED void FUN_0808f7cc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f7cc.inc"); }

NAKED void FUN_0808f81c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f81c.inc"); }

NAKED void FUN_0808f8bc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f8bc.inc"); }

NAKED void FUN_0808f920(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f920.inc"); }

NAKED void FUN_0808f95c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808f95c.inc"); }

NAKED void FUN_0808f98c(s32 param_1) { INCFUNC("asm/func/FUN_0808f98c.inc"); }

NAKED s32 FUN_0808f9a0(s32 param_1) { INCFUNC("asm/func/FUN_0808f9a0.inc"); }

NAKED s32 FUN_0808f9e8(s32 param_1) { INCFUNC("asm/func/FUN_0808f9e8.inc"); }

NAKED s32 FUN_0808fa48(s32 param_1) { INCFUNC("asm/func/FUN_0808fa48.inc"); }

NAKED s32 FUN_0808faa8(s32 param_1) { INCFUNC("asm/func/FUN_0808faa8.inc"); }

NAKED s32 FUN_0808fb08(s32 param_1) { INCFUNC("asm/func/FUN_0808fb08.inc"); }

NAKED s32 FUN_0808fb68(s32 param_1) { INCFUNC("asm/func/FUN_0808fb68.inc"); }

// MenuCursor の位置を退避する, FUN_080b9fd8 と同じ実装
void FUN_0808fbbc(MenuCursor* p) {
  p->savedRow = p->row;
  p->savedCol = p->col;
  p->savedSlot = p->slot;
}

// 退避した MenuCursor の位置を戻す, FUN_080b9fe8 と同じ実装
void FUN_0808fbcc(MenuCursor* p) {
  p->row = p->savedRow;
  p->col = p->savedCol;
  p->slot = p->savedSlot;
}

NAKED void FUN_0808fbdc(s32 param_1, u8 param_2, u8 param_3) { INCFUNC("asm/func/FUN_0808fbdc.inc"); }

NAKED void FUN_0808fbf4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808fbf4.inc"); }

NAKED s32 FUN_0808fc14(void) { INCFUNC("asm/func/FUN_0808fc14.inc"); }

NAKED void FUN_0808fc68(void) { INCFUNC("asm/func/FUN_0808fc68.inc"); }

NAKED void FUN_0808fc8c(void) { INCFUNC("asm/func/FUN_0808fc8c.inc"); }

NAKED void FUN_0808fcb4(void) { INCFUNC("asm/func/FUN_0808fcb4.inc"); }

NAKED void FUN_0808fcd8(void) { INCFUNC("asm/func/FUN_0808fcd8.inc"); }

NAKED void FUN_0808fd00(void) { INCFUNC("asm/func/FUN_0808fd00.inc"); }

NAKED void FUN_0808fd2c(u32 param_1) { INCFUNC("asm/func/FUN_0808fd2c.inc"); }

NAKED s32 FUN_0808fd44(void) { INCFUNC("asm/func/FUN_0808fd44.inc"); }

NAKED void FUN_0808fd8c(void) { INCFUNC("asm/func/FUN_0808fd8c.inc"); }

NAKED void FUN_0808fdc8(void) { INCFUNC("asm/func/FUN_0808fdc8.inc"); }

NAKED void FUN_0808fe1c(void) { INCFUNC("asm/func/FUN_0808fe1c.inc"); }

u32 FUN_0808fe70(u32 param_1) { return param_1 & 0xF; }

s32 FUN_0808fe78(s32 param_1) { return param_1 >> 4; }

NAKED void FUN_0808fe7c(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808fe7c.inc"); }

NAKED void FUN_0808ff84(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ff84.inc"); }

NAKED void FUN_08090004(EntityCC28* p) { INCFUNC("asm/func/FUN_08090004.inc"); }

NAKED void FUN_08090040(EntityCC28* p) { INCFUNC("asm/func/FUN_08090040.inc"); }

NAKED void FUN_08090120(EntityCC28* p) { INCFUNC("asm/func/FUN_08090120.inc"); }

NAKED void FUN_08090148(EntityCC28* p) { INCFUNC("asm/func/FUN_08090148.inc"); }

NAKED void FUN_08090698(void) { INCFUNC("asm/func/FUN_08090698.inc"); }

NAKED void FUN_080906c8(EntityCC28* p) { INCFUNC("asm/func/FUN_080906c8.inc"); }

NAKED bool32 FUN_08090724(EntityCC28* p) { INCFUNC("asm/func/FUN_08090724.inc"); }

NAKED void FUN_080907f0(EntityCC28* p) { INCFUNC("asm/func/FUN_080907f0.inc"); }

NAKED void FUN_08090a00(EntityCC28* p) { INCFUNC("asm/func/FUN_08090a00.inc"); }

s32 FUN_08090b10(EntityCC28* p) {
  u8 kind = p->player->kind;

  if (kind == PLAYER_SOLAR_DJANGO) return 0;
  if (kind == PLAYER_SABATA) return 2;

  return 1;
}

NAKED void FUN_08090b38(EntityCC28* p) { INCFUNC("asm/func/FUN_08090b38.inc"); }

NAKED void FUN_08090ca4(EntityCC28* p) { INCFUNC("asm/func/FUN_08090ca4.inc"); }

NAKED void FUN_08090d54(EntityCC28* p) { INCFUNC("asm/func/FUN_08090d54.inc"); }

void FUN_08090ee0(void) {
  if (VM_SeekToNamedArg('i')) {
    s32 bitidx = VM_GetValue();

    gStat->unk_264 |= 1 << bitidx;
  }
}

u32 FUN_08090f0c(u32 bitidx) { return gStat->unk_264 & (1 << bitidx); }

NAKED void FUN_08090f24(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08090f24.inc"); }

NAKED void FUN_0809107c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809107c.inc"); }

NAKED void FUN_08091270(EntityCC28* p) { INCFUNC("asm/func/FUN_08091270.inc"); }

NAKED void FUN_08091598(EntityCC28* p) { INCFUNC("asm/func/FUN_08091598.inc"); }

NAKED void FUN_08091684(void) { INCFUNC("asm/func/FUN_08091684.inc"); }

extern u16 u16_03002c10;

u32 FUN_080916bc(u32 bitidx) { return u16_03002c10 & (1 << bitidx); }

NAKED void FUN_080916d0(u8* param_1, u32 param_2) { INCFUNC("asm/func/FUN_080916d0.inc"); }

u32 item_08091774(item32_t n) { return gItemDB[n].unk_00 & 0xF; }

u32 item_08091788(item32_t n) { return (gItemDB[n].unk_00 & 0xF0) >> 4; }

u8 item_0809179c(item32_t n) { return (gItemDB[n].unk_00 & 0x100) >> 8; }

u8 item_080917b4(item32_t n) { return (gItemDB[n].unk_00 & 0x200) >> 9; }

// 0x080917cc
item32_t GetItemID(bool32 isValuable, s32 slot) {
  if (!isValuable) {
    return GetNormalItemID(slot);
  }
  return GetValuableItemID(slot);
}

NAKED void FUN_080917e4(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080917e4.inc"); }

NAKED void FUN_08091860(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08091860.inc"); }

NAKED void FUN_0809193c(EntityCC28* p, u32 param_2) { INCFUNC("asm/func/FUN_0809193c.inc"); }

NAKED void FUN_080919a4(EntityCC28* p, u16 param_2, s16 param_3) { INCFUNC("asm/func/FUN_080919a4.inc"); }

NAKED void FUN_08091a34(EntityCC28* p, s32 param_2, u8 param_3) { INCFUNC("asm/func/FUN_08091a34.inc"); }

NAKED void FUN_08091adc(EntityCC28* p, s8 param_2, u16 param_3) { INCFUNC("asm/func/FUN_08091adc.inc"); }

NAKED void FUN_08091b40(EntityCC28* p, u8 param_2) { INCFUNC("asm/func/FUN_08091b40.inc"); }

NAKED void FUN_08091b68(EntityCC28* p) { INCFUNC("asm/func/FUN_08091b68.inc"); }

NAKED void FUN_08091bbc(EntityCC28* p) { INCFUNC("asm/func/FUN_08091bbc.inc"); }

NAKED void FUN_08091be0(EntityCC28* p) { INCFUNC("asm/func/FUN_08091be0.inc"); }

NAKED void FUN_08091c50(EntityCC28* p, u8 param_2) { INCFUNC("asm/func/FUN_08091c50.inc"); }

NAKED void FUN_08091c78(void) { INCFUNC("asm/func/FUN_08091c78.inc"); }

NAKED void FUN_08091c90(void) { INCFUNC("asm/func/FUN_08091c90.inc"); }

NAKED u32 FUN_08091cb8(item32_t n) { INCFUNC("asm/func/FUN_08091cb8.inc"); }

NAKED bool32 FUN_08091e34(item32_t n) { INCFUNC("asm/func/FUN_08091e34.inc"); }

NAKED void FUN_08091e48(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_08091e48.inc"); }

NAKED void FUN_08091e64(EntityCC28* p, s32 selectedSlot) { INCFUNC("asm/func/FUN_08091e64.inc"); }

NAKED void FUN_0809200c(EntityCC28* p, s32 slotA, s32 slotB) { INCFUNC("asm/func/FUN_0809200c.inc"); }

NAKED u32 item_08092034(s32 slot) { INCFUNC("asm/func/item_08092034.inc"); }

NAKED void FUN_08092070(EntityCC28* p) { INCFUNC("asm/func/FUN_08092070.inc"); }

NAKED bool32 FUN_080921a8(EntityCC28* p) { INCFUNC("asm/func/FUN_080921a8.inc"); }

NAKED void FUN_080921e8(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_080921e8.inc"); }

NAKED void FUN_0809223c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809223c.inc"); }

NAKED void FUN_08092300(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08092300.inc"); }

NAKED void FUN_080923a0(EntityCC28* p) { INCFUNC("asm/func/FUN_080923a0.inc"); }

NAKED u32 FUN_080925d4(item32_t n) { INCFUNC("asm/func/FUN_080925d4.inc"); }

NAKED void FUN_08092608(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_08092608.inc"); }

NAKED s32 FUN_080926c4(EntityCC28* p) { INCFUNC("asm/func/FUN_080926c4.inc"); }

NAKED void FUN_08092744(EntityCC28* p) { INCFUNC("asm/func/FUN_08092744.inc"); }

NAKED void FUN_080927c4(EntityCC28* p) { INCFUNC("asm/func/FUN_080927c4.inc"); }

NAKED void FUN_08092868(EntityCC28* p, s32 param_2, u32* param_3) { INCFUNC("asm/func/FUN_08092868.inc"); }

NAKED void FUN_0809296c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809296c.inc"); }

NAKED void FUN_08092a1c(EntityCC28* p) { INCFUNC("asm/func/FUN_08092a1c.inc"); }

NAKED void FUN_08092a94(EntityCC28* p) { INCFUNC("asm/func/FUN_08092a94.inc"); }

NAKED void FUN_08092b3c(EntityCC28* p) { INCFUNC("asm/func/FUN_08092b3c.inc"); }

NAKED void FUN_08092bb8(EntityCC28* p) { INCFUNC("asm/func/FUN_08092bb8.inc"); }

NAKED void FUN_08092bf0(EntityCC28* p) { INCFUNC("asm/func/FUN_08092bf0.inc"); }

NAKED void FUN_08092c7c(EntityCC28* p, u8 param_2) { INCFUNC("asm/func/FUN_08092c7c.inc"); }

NAKED void FUN_08092cac(EntityCC28* p) { INCFUNC("asm/func/FUN_08092cac.inc"); }

NAKED s32 FUN_08092e20(EntityCC28* p) { INCFUNC("asm/func/FUN_08092e20.inc"); }

NAKED void FUN_0809312c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809312c.inc"); }

NAKED void FUN_08093158(EntityCC28* p) { INCFUNC("asm/func/FUN_08093158.inc"); }

NAKED void FUN_080931cc(EntityCC28* p) { INCFUNC("asm/func/FUN_080931cc.inc"); }

NAKED void FUN_08093264(EntityCC28* p) { INCFUNC("asm/func/FUN_08093264.inc"); }

NAKED void FUN_08093318(EntityCC28* p) { INCFUNC("asm/func/FUN_08093318.inc"); }

NAKED void FUN_080933b4(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_080933b4.inc"); }

NAKED void FUN_08093580(EntityCC28* p) { INCFUNC("asm/func/FUN_08093580.inc"); }

NAKED void FUN_08093608(EntityCC28* p) { INCFUNC("asm/func/FUN_08093608.inc"); }

NAKED void FUN_08093710(EntityCC28* p) { INCFUNC("asm/func/FUN_08093710.inc"); }

NAKED void FUN_080937d4(EntityCC28* p) { INCFUNC("asm/func/FUN_080937d4.inc"); }

NAKED void FUN_080938d0(EntityCC28* p) { INCFUNC("asm/func/FUN_080938d0.inc"); }

NAKED void FUN_08093990(EntityCC28* p) { INCFUNC("asm/func/FUN_08093990.inc"); }

NAKED void FUN_08093a54(EntityCC28* p) { INCFUNC("asm/func/FUN_08093a54.inc"); }

NAKED void FUN_08093b20(EntityCC28* p) { INCFUNC("asm/func/FUN_08093b20.inc"); }

NAKED void FUN_08093bb4(EntityCC28* p) { INCFUNC("asm/func/FUN_08093bb4.inc"); }

NAKED void FUN_08093c64(EntityCC28* p) { INCFUNC("asm/func/FUN_08093c64.inc"); }

NAKED void FUN_08093cc8(EntityCC28* p) { INCFUNC("asm/func/FUN_08093cc8.inc"); }

NAKED void FUN_08093d38(EntityCC28* p) { INCFUNC("asm/func/FUN_08093d38.inc"); }

NAKED void FUN_08093de8(EntityCC28* p) { INCFUNC("asm/func/FUN_08093de8.inc"); }

NAKED void FUN_08093e4c(EntityCC28* p) { INCFUNC("asm/func/FUN_08093e4c.inc"); }

NAKED void FUN_08093f28(EntityCC28* p) { INCFUNC("asm/func/FUN_08093f28.inc"); }

NAKED void FUN_08094070(EntityCC28* p) { INCFUNC("asm/func/FUN_08094070.inc"); }

NAKED void FUN_08094200(EntityCC28* p) { INCFUNC("asm/func/FUN_08094200.inc"); }

NAKED void FUN_08094440(EntityCC28* p) { INCFUNC("asm/func/FUN_08094440.inc"); }

NAKED void FUN_080944f4(EntityCC28* p) { INCFUNC("asm/func/FUN_080944f4.inc"); }

NAKED void FUN_0809455c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809455c.inc"); }

NAKED void FUN_0809458c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809458c.inc"); }

NAKED void FUN_080945f4(EntityCC28* p) { INCFUNC("asm/func/FUN_080945f4.inc"); }

NAKED void FUN_08094660(EntityCC28* p) { INCFUNC("asm/func/FUN_08094660.inc"); }

NAKED void FUN_080946dc(EntityCC28* p) { INCFUNC("asm/func/FUN_080946dc.inc"); }

NAKED void FUN_08094780(EntityCC28* p) { INCFUNC("asm/func/FUN_08094780.inc"); }

NAKED void FUN_08094838(EntityCC28* p) { INCFUNC("asm/func/FUN_08094838.inc"); }

NAKED void FUN_080948ac(EntityCC28* p) { INCFUNC("asm/func/FUN_080948ac.inc"); }

NAKED void FUN_08094988(void) { INCFUNC("asm/func/FUN_08094988.inc"); }

NAKED void FUN_080949b0(EntityCC28* p) { INCFUNC("asm/func/FUN_080949b0.inc"); }

NAKED void FUN_08094a94(EntityCC28* p, u32 permission) { INCFUNC("asm/func/FUN_08094a94.inc"); }

NAKED void FUN_08094c6c(s32 param_1, u8* param_2) { INCFUNC("asm/func/FUN_08094c6c.inc"); }

NAKED void FUN_08094cdc(s32 param_1, s32 param_2, u8* param_3, s8* param_4) { INCFUNC("asm/func/FUN_08094cdc.inc"); }

NAKED void FUN_08094d1c(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_08094d1c.inc"); }

NAKED void FUN_08094d30(s32 param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08094d30.inc"); }

NAKED void FUN_08094d48(unknown* w, u8* pc) { INCFUNC("asm/func/FUN_08094d48.inc"); }

NAKED s32 FUN_08094e70(s32 param_1) { INCFUNC("asm/func/FUN_08094e70.inc"); }

NAKED void FUN_08094eb0(EntityCC28* p) { INCFUNC("asm/func/FUN_08094eb0.inc"); }

NAKED void weapon_08094f88(EntityCC28* p) { INCFUNC("asm/func/weapon_08094f88.inc"); }

NAKED void FUN_080952f4(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_080952f4.inc"); }

NAKED void FUN_0809536c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809536c.inc"); }

NAKED void FUN_080954a8(EntityCC28* p, u32 param_2) { INCFUNC("asm/func/FUN_080954a8.inc"); }

NAKED void FUN_080956c4(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080956c4.inc"); }

NAKED u32 GetWeaponPermission(EntityCC28* p, s32 slot) { INCFUNC("asm/func/GetWeaponPermission.inc"); }

NAKED void weapon_08095820(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/weapon_08095820.inc"); }

NAKED s32 FUN_0809596c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809596c.inc"); }

NAKED void FUN_08095a5c(EntityCC28* p) { INCFUNC("asm/func/FUN_08095a5c.inc"); }

NAKED void FUN_08095ae8(EntityCC28* p) { INCFUNC("asm/func/FUN_08095ae8.inc"); }

NAKED void FUN_08095c60(EntityCC28* p) { INCFUNC("asm/func/FUN_08095c60.inc"); }

NAKED void weapon_08095d4c(EntityCC28* p) { INCFUNC("asm/func/weapon_08095d4c.inc"); }

NAKED void FUN_08096024(EntityCC28* p) { INCFUNC("asm/func/FUN_08096024.inc"); }

NAKED void FUN_080960c8(EntityCC28* p) { INCFUNC("asm/func/FUN_080960c8.inc"); }

NAKED void FUN_0809611c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809611c.inc"); }

NAKED void FUN_080961a4(EntityCC28* p) { INCFUNC("asm/func/FUN_080961a4.inc"); }

NAKED void FUN_0809620c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809620c.inc"); }

NAKED void FUN_080962b0(EntityCC28* p) { INCFUNC("asm/func/FUN_080962b0.inc"); }

NAKED void FUN_0809630c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809630c.inc"); }

NAKED void FUN_08096378(EntityCC28* p) { INCFUNC("asm/func/FUN_08096378.inc"); }

NAKED void FUN_080963f4(EntityCC28* p) { INCFUNC("asm/func/FUN_080963f4.inc"); }

NAKED void FUN_080964ac(EntityCC28* p) { INCFUNC("asm/func/FUN_080964ac.inc"); }

NAKED void FUN_0809651c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809651c.inc"); }

NAKED void FUN_08096630(EntityCC28* p, u8 param_2) { INCFUNC("asm/func/FUN_08096630.inc"); }

NAKED void FUN_0809673c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809673c.inc"); }

NAKED void FUN_080967c0(EntityCC28* p) { INCFUNC("asm/func/FUN_080967c0.inc"); }

NAKED void FUN_08096a34(EntityCC28* p) { INCFUNC("asm/func/FUN_08096a34.inc"); }

NAKED void FUN_08096af0(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_08096af0.inc"); }

NAKED void FUN_08096b44(EntityCC28* p) { INCFUNC("asm/func/FUN_08096b44.inc"); }

NAKED void FUN_08096bb8(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_08096bb8.inc"); }

NAKED void FUN_08096cac(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08096cac.inc"); }

NAKED s32 FUN_08096d40(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_08096d40.inc"); }

NAKED void FUN_08096d90(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_08096d90.inc"); }

NAKED s32 FUN_08096ec4(EntityCC28* p) { INCFUNC("asm/func/FUN_08096ec4.inc"); }

NAKED void FUN_08096f90(EntityCC28* p) { INCFUNC("asm/func/FUN_08096f90.inc"); }

NAKED void FUN_08096fa8(EntityCC28* p) { INCFUNC("asm/func/FUN_08096fa8.inc"); }

NAKED void FUN_08097034(EntityCC28* p) { INCFUNC("asm/func/FUN_08097034.inc"); }

NAKED void FUN_080971c4(EntityCC28* p) { INCFUNC("asm/func/FUN_080971c4.inc"); }

NAKED void FUN_0809748c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809748c.inc"); }

NAKED void FUN_08097530(EntityCC28* p) { INCFUNC("asm/func/FUN_08097530.inc"); }

NAKED void FUN_08097584(EntityCC28* p) { INCFUNC("asm/func/FUN_08097584.inc"); }

NAKED void FUN_08097604(EntityCC28* p) { INCFUNC("asm/func/FUN_08097604.inc"); }

NAKED void FUN_08097670(EntityCC28* p) { INCFUNC("asm/func/FUN_08097670.inc"); }

NAKED void FUN_080976ec(EntityCC28* p) { INCFUNC("asm/func/FUN_080976ec.inc"); }

NAKED void FUN_080977a4(EntityCC28* p) { INCFUNC("asm/func/FUN_080977a4.inc"); }

NAKED void FUN_08097888(EntityCC28* p) { INCFUNC("asm/func/FUN_08097888.inc"); }

NAKED void FUN_08097948(EntityCC28* p) { INCFUNC("asm/func/FUN_08097948.inc"); }

NAKED void FUN_080979b8(EntityCC28* p) { INCFUNC("asm/func/FUN_080979b8.inc"); }

NAKED void FUN_08097ab8(EntityCC28* p, u8 param_2) { INCFUNC("asm/func/FUN_08097ab8.inc"); }

NAKED void FUN_08097c04(EntityCC28* p) { INCFUNC("asm/func/FUN_08097c04.inc"); }

NAKED void FUN_08097ca0(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_08097ca0.inc"); }

NAKED s32 FUN_08097d20(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_08097d20.inc"); }

NAKED void FUN_08097d4c(EntityCC28* p) { INCFUNC("asm/func/FUN_08097d4c.inc"); }

NAKED void FUN_08097e3c(EntityCC28* p) { INCFUNC("asm/func/FUN_08097e3c.inc"); }

NAKED void FUN_08097f48(s32 param_1, s32 param_2, s16 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08097f48.inc"); }

NAKED void FUN_08097fb4(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_08097fb4.inc"); }

NAKED s32 FUN_080980a8(EntityCC28* p) { INCFUNC("asm/func/FUN_080980a8.inc"); }

NAKED void FUN_0809820c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809820c.inc"); }

NAKED void FUN_08098290(EntityCC28* p) { INCFUNC("asm/func/FUN_08098290.inc"); }

NAKED void FUN_080983a4(EntityCC28* p) { INCFUNC("asm/func/FUN_080983a4.inc"); }

NAKED void FUN_080984a0(EntityCC28* p) { INCFUNC("asm/func/FUN_080984a0.inc"); }

NAKED void FUN_080985ec(unknown* p) { INCFUNC("asm/func/FUN_080985ec.inc"); }

NAKED void FUN_08098684(EntityCC28* p) { INCFUNC("asm/func/FUN_08098684.inc"); }

NAKED void FUN_08098734(EntityCC28* p) { INCFUNC("asm/func/FUN_08098734.inc"); }

NAKED void FUN_08098758(EntityCC28* p) { INCFUNC("asm/func/FUN_08098758.inc"); }

NAKED void FUN_0809877c(s32 param_1) { INCFUNC("asm/func/FUN_0809877c.inc"); }

NAKED void FUN_080987a4(EntityCC28* p) { INCFUNC("asm/func/FUN_080987a4.inc"); }

NAKED void FUN_0809889c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809889c.inc"); }

NAKED s32 FUN_0809890c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809890c.inc"); }

NAKED s32 FUN_08098934(EntityCC28* p) { INCFUNC("asm/func/FUN_08098934.inc"); }

NAKED void FUN_0809895c(s32 param_1) { INCFUNC("asm/func/FUN_0809895c.inc"); }

NAKED void FUN_080989c4(EntityCC28* p) { INCFUNC("asm/func/FUN_080989c4.inc"); }

NAKED void FUN_08098a98(s32 param_1, s32 param_2, MainSpriteGfx* param_3, MainSprite* param_4, MainSprite* param_5) { INCFUNC("asm/func/FUN_08098a98.inc"); }

NAKED void FUN_08098af4(EntityCC28* p) { INCFUNC("asm/func/FUN_08098af4.inc"); }

NAKED void FUN_08098bdc(EntityCC28* p) { INCFUNC("asm/func/FUN_08098bdc.inc"); }

NAKED void FUN_08098c24(EntityCC28* p) { INCFUNC("asm/func/FUN_08098c24.inc"); }

NAKED void FUN_08098d98(EntityCC28* p) { INCFUNC("asm/func/FUN_08098d98.inc"); }

NAKED void FUN_08098e48(EntityCC28* p) { INCFUNC("asm/func/FUN_08098e48.inc"); }

NAKED void FUN_08098e88(EntityCC28* p) { INCFUNC("asm/func/FUN_08098e88.inc"); }

NAKED void FUN_08098edc(EntityCC28* p) { INCFUNC("asm/func/FUN_08098edc.inc"); }

NAKED void FUN_08098f48(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_08098f48.inc"); }

NAKED void FUN_08098f7c(EntityCC28* p) { INCFUNC("asm/func/FUN_08098f7c.inc"); }

NAKED void FUN_08099008(EntityCC28* p) { INCFUNC("asm/func/FUN_08099008.inc"); }

NAKED void FUN_080992c0(EntityCC28* p) { INCFUNC("asm/func/FUN_080992c0.inc"); }

NAKED void weapon_080993c4(EntityCC28* p) { INCFUNC("asm/func/weapon_080993c4.inc"); }

NAKED void weapon_080993e4(EntityCC28* p) { INCFUNC("asm/func/weapon_080993e4.inc"); }

NAKED void FUN_080995b0(EntityCC28* p, u8 param_2) { INCFUNC("asm/func/FUN_080995b0.inc"); }

NAKED void FUN_08099650(EntityCC28* p) { INCFUNC("asm/func/FUN_08099650.inc"); }

NAKED void FUN_080996e0(EntityCC28* p) { INCFUNC("asm/func/FUN_080996e0.inc"); }

NAKED void FUN_08099968(EntityCC28* p) { INCFUNC("asm/func/FUN_08099968.inc"); }

NAKED void FUN_08099b3c(s32 param_1) { INCFUNC("asm/func/FUN_08099b3c.inc"); }

NAKED s32 FUN_08099b5c(void) { INCFUNC("asm/func/FUN_08099b5c.inc"); }

NAKED s32 FUN_08099b84(s32 param_1) { INCFUNC("asm/func/FUN_08099b84.inc"); }

NAKED void FUN_08099b9c(EntityCC28* p) { INCFUNC("asm/func/FUN_08099b9c.inc"); }

NAKED void FUN_08099c1c(EntityCC28* p) { INCFUNC("asm/func/FUN_08099c1c.inc"); }

NAKED void FUN_08099c64(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_08099c64.inc"); }

NAKED s32 FUN_08099d2c(EntityCC28* p) { INCFUNC("asm/func/FUN_08099d2c.inc"); }

NAKED void FUN_08099e2c(EntityCC28* p) { INCFUNC("asm/func/FUN_08099e2c.inc"); }

NAKED void FUN_08099e70(EntityCC28* p) { INCFUNC("asm/func/FUN_08099e70.inc"); }

NAKED void FUN_08099f18(EntityCC28* p) { INCFUNC("asm/func/FUN_08099f18.inc"); }

NAKED void FUN_08099f58(EntityCC28* p) { INCFUNC("asm/func/FUN_08099f58.inc"); }

NAKED void FUN_0809a084(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a084.inc"); }

NAKED void FUN_0809a130(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a130.inc"); }

NAKED void FUN_0809a1a4(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a1a4.inc"); }

NAKED void FUN_0809a20c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a20c.inc"); }

NAKED void FUN_0809a274(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a274.inc"); }

NAKED void FUN_0809a324(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a324.inc"); }

NAKED void FUN_0809a368(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a368.inc"); }

NAKED void FUN_0809a3f4(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a3f4.inc"); }

NAKED void FUN_0809a448(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a448.inc"); }

NAKED void FUN_0809a4c0(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a4c0.inc"); }

NAKED void FUN_0809a510(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a510.inc"); }

NAKED void FUN_0809a574(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a574.inc"); }

NAKED void FUN_0809a5d8(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a5d8.inc"); }

NAKED void FUN_0809a67c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a67c.inc"); }

NAKED void FUN_0809a6a8(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a6a8.inc"); }

NAKED void FUN_0809a800(void) { INCFUNC("asm/func/FUN_0809a800.inc"); }

NAKED void FUN_0809a81c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a81c.inc"); }

NAKED s32 FUN_0809a93c(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_0809a93c.inc"); }

NAKED s32 FUN_0809a978(EntityCC28* p, s32 param_2) { INCFUNC("asm/func/FUN_0809a978.inc"); }

NAKED void FUN_0809a9b0(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a9b0.inc"); }

NAKED void FUN_0809aaf4(EntityCC28* p) { INCFUNC("asm/func/FUN_0809aaf4.inc"); }

NAKED void FUN_0809ab70(EntityCC28* p) { INCFUNC("asm/func/FUN_0809ab70.inc"); }

NAKED void FUN_0809abbc(void) { INCFUNC("asm/func/FUN_0809abbc.inc"); }

NAKED void FUN_0809ac30(EntityCC28* p) { INCFUNC("asm/func/FUN_0809ac30.inc"); }

NAKED void FUN_0809ae0c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809ae0c.inc"); }

NAKED void FUN_0809aeb0(EntityCC28* p) { INCFUNC("asm/func/FUN_0809aeb0.inc"); }

NAKED void FUN_0809b12c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809b12c.inc"); }

NAKED void FUN_0809b180(EntityCC28* p) { INCFUNC("asm/func/FUN_0809b180.inc"); }

NAKED void FUN_0809b2b8(EntityCC28* p) { INCFUNC("asm/func/FUN_0809b2b8.inc"); }

NAKED s32 FUN_0809b348(EntityCC28* p) { INCFUNC("asm/func/FUN_0809b348.inc"); }

NAKED s32 FUN_0809b3b0(EntityCC28* p) { INCFUNC("asm/func/FUN_0809b3b0.inc"); }

NAKED void FUN_0809b430(EntityCC28* p) { INCFUNC("asm/func/FUN_0809b430.inc"); }

NAKED void FUN_0809b468(EntityCC28* p) { INCFUNC("asm/func/FUN_0809b468.inc"); }

NAKED void FUN_0809bd14(EntityCC28* p) { INCFUNC("asm/func/FUN_0809bd14.inc"); }

NAKED void FUN_0809bed8(EntityCC28* p) { INCFUNC("asm/func/FUN_0809bed8.inc"); }

NAKED void FUN_0809bf88(EntityCC28* p) { INCFUNC("asm/func/FUN_0809bf88.inc"); }

NAKED void FUN_0809c010(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c010.inc"); }

NAKED void FUN_0809c040(void) { INCFUNC("asm/func/FUN_0809c040.inc"); }

NAKED s32 FUN_0809c068(void) { INCFUNC("asm/func/FUN_0809c068.inc"); }

NAKED void FUN_0809c08c(u8 param_1) { INCFUNC("asm/func/FUN_0809c08c.inc"); }

NAKED void FUN_0809c1c0(void) { INCFUNC("asm/func/FUN_0809c1c0.inc"); }

NAKED void FUN_0809c1e8(void) { INCFUNC("asm/func/FUN_0809c1e8.inc"); }

void FUN_0809c214(void) { FUN_0809c1c0(); }

void FUN_0809c220(void) { FUN_0809c1e8(); }

NAKED void Textbox_CloseBox(void) { INCFUNC("asm/func/Textbox_CloseBox.inc"); }

NAKED void FUN_0809c244(void) { INCFUNC("asm/func/FUN_0809c244.inc"); }

NAKED void FUN_0809c264(void) { INCFUNC("asm/func/FUN_0809c264.inc"); }

NAKED void FUN_0809c28c(void) { INCFUNC("asm/func/FUN_0809c28c.inc"); }

NAKED void FUN_0809c2d0(void) { INCFUNC("asm/func/FUN_0809c2d0.inc"); }

NAKED void FUN_0809c314(void) { INCFUNC("asm/func/FUN_0809c314.inc"); }

NAKED void FUN_0809c344(s32 param_1, s32 param_2, u16 param_3, u8 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0809c344.inc"); }

NAKED void FUN_0809c3c0(s32 param_1, u16 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0809c3c0.inc"); }

NAKED void FUN_0809c430(void) { INCFUNC("asm/func/FUN_0809c430.inc"); }

NAKED void FUN_0809c464(void) { INCFUNC("asm/func/FUN_0809c464.inc"); }

NAKED void FUN_0809c4f4(void) { INCFUNC("asm/func/FUN_0809c4f4.inc"); }

NAKED void FUN_0809c544(s32 param_1) { INCFUNC("asm/func/FUN_0809c544.inc"); }

NAKED void FUN_0809c58c(void) { INCFUNC("asm/func/FUN_0809c58c.inc"); }

NAKED void FUN_0809c5dc(void) { INCFUNC("asm/func/FUN_0809c5dc.inc"); }

NAKED void FUN_0809c5f4(void) { INCFUNC("asm/func/FUN_0809c5f4.inc"); }

NAKED void FUN_0809c63c(void) { INCFUNC("asm/func/FUN_0809c63c.inc"); }

NAKED void FUN_0809c668(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c668.inc"); }

NAKED void FUN_0809c70c(void) { INCFUNC("asm/func/FUN_0809c70c.inc"); }

NAKED void FUN_0809c780(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0809c780.inc"); }

NAKED void FUN_0809c880(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c880.inc"); }

NAKED s32 FUN_0809c8e8(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c8e8.inc"); }

NAKED s32 FUN_0809c928(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c928.inc"); }

NAKED void FUN_0809c960(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c960.inc"); }

NAKED void FUN_0809ca08(EntityCC28* p) { INCFUNC("asm/func/FUN_0809ca08.inc"); }

NAKED s32 FUN_0809cae0(EntityCC28* p, unknown* param_2) { INCFUNC("asm/func/FUN_0809cae0.inc"); }

NAKED EntityCC28* EntityCC28_Create_0809cb74(u32 val, unknown* param_2) { INCFUNC("asm/func/EntityCC28_Create_0809cb74.inc"); }

NAKED s32 FUN_0809cbd0(EntityCC28* p) { INCFUNC("asm/func/FUN_0809cbd0.inc"); }

NAKED s32 FUN_0809cc04(EntityCC28* p) { INCFUNC("asm/func/FUN_0809cc04.inc"); }

NAKED s32 FUN_0809cc48(EntityCC28* p) { INCFUNC("asm/func/FUN_0809cc48.inc"); }

NAKED EntityCC28* EntityCC28_Create_0809ce04(u32 val, unknown* param_2) { INCFUNC("asm/func/EntityCC28_Create_0809ce04.inc"); }

EntityCC28* EntityCC28_Create(u32 val, unknown* param_2) {
  if (gFlag030047a4 & FLAG030047A4_LINK) {
    return EntityCC28_Create_0809cb74(val, param_2);
  }
  return EntityCC28_Create_0809ce04(val, param_2);
}
