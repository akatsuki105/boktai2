#include "entity.h"
#include "file.h"
#include "global.h"
#include "inventory.h"
#include "item.h"
#include "menu.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

struct EntityCC28;
typedef void(EntityCC28Func)(struct EntityCC28* p);  // _Update が p->fn(p) として呼ぶ

typedef struct {
  MainSprite sprite;      // 0x0000
  s8 unk_60;              // 0x0060, 根拠: EntityCC28_ApplyWeapon が ldrsb で読んで配列の添字にする
  u8 unk_61;              // 0x0061
  u8 unk_62[100 - 0x62];  // 0x0062, まだ未解析
} EntityCC28Sprite100;
static_assert(sizeof(EntityCC28Sprite100) == 100);

typedef struct {
  Weapon* weapon;         // 0x0000, 根拠: EntityCC28_ApplyWeapon が Player_ApplyWeapon の第2引数に渡す
  MainSprite sprite;      // 0x0004
  u8 unk_64;              // 0x0064
  u8 unk_65;              // 0x0065
  u8 unk_66[104 - 0x66];  // 0x0066, まだ未解析
} EntityCC28Sprite104;
static_assert(sizeof(EntityCC28Sprite104) == 104);

// メニューのインベントリ操作に関係してそう
typedef struct EntityCC28 {
  Entity e;                        // 0x0000, ENTITY_UNK_12
  void* unk_18;                    // 0x0018
  u8 unk_1c[0x20 - 0x1C];          // 0x001C, まだ未解析
  void* unk_20[2];                 // 0x0020
  void* unk_28;                    // 0x0028
  TilemapFile* unk_2c;             // 0x002C, 根拠: FUN_0808ebe8 が FUN_0808a3c4 の第2引数に渡す
  u8 unk_30[0x34 - 0x30];          // 0x0030, まだ未解析
  void* unk_34[2];                 // 0x0034
  unknown* unk_3c;                 // 0x003C, 根拠: FUN_0808ebe8 が FUN_0808a3c4 の第5引数に渡す
  u8 unk_40[0x58 - 0x40];          // 0x0040, まだ未解析
  u8* unk_58;                      // 0x0058, 根拠: EntityCC28_ShowLineInstant が TextBox_Start に渡す
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
  EntityCC28Func* updateCallback;  // 0x09F0
  EntityCC28Func* fn;              // 0x09F4
  s8 unk_9f8;                      // 0x09F8
  u8 unk_9f9[0x9FA - 0x9F9];       // 0x09F9, まだ未解析
  s16 unk_9fa;                     // 0x09FA
  u16 unk_9fc;                     // 0x09FC
  u8 unk_9fe;                      // 0x09FE
  s8 unk_9ff;                      // 0x09FF, 根拠: FUN_0809c1e8 が ldrsb で読んで負かどうかを見る
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
  AuxSprite sprite_b60;            // 0x0B60, 根拠: EntityCC28_RemoveSprites が AuxSprite_Remove に渡す
  u8 unk_b8c[0xBB8 - 0xB8C];       // 0x0B8C, まだ未解析
  AuxSprite sprite_bb8;            // 0x0BB8, 根拠: 同上
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
  EntityCC28Sprite104 unk_da0[4];  // 0x0DA0
  u8 unk_f40[0xF56 - 0xF40];       // 0x0F40, まだ未解析
  u8 state2;                       // 0x0F56
  u8 unk_f57[0xF64 - 0xF57];       // 0x0F57, まだ未解析
  MainSprite sprites[116];         // 0x0F64, 根拠: EntityCC28_RemoveSprites が 116個ぶん MainSprite_Remove に渡す
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
  u8 unk_3fa0[2];                  // 0x3FA0
  u16 unk_3fa2;                    // 0x3FA2, 根拠: FUN_08091bbc が 0 を入れる
  u8 unk_3fa4[0x3FB0 - 0x3FA4];    // 0x3FA4
  u8 unk_3fb0;                     // 0x3FB0, 根拠: FUN_08091b40 が 1 を入れる
  u8 unk_3fb1;                     // 0x3FB1, 根拠: 同上, 引数の値が入る
  u8 unk_3fb2[0x3FB8 - 0x3FB2];    // 0x3FB2
  u8 unk_3fb8;                     // 0x3FB8, 根拠: FUN_08091c50 が 1 を入れる
  u8 unk_3fb9;                     // 0x3FB9, 根拠: 同上, 引数の値が入る
  u8 unk_3fba[0x3FF0 - 0x3FBA];    // 0x3FBA
  s8 unk_3ff0[16];                 // 0x3FF0, 根拠: FUN_0809890c / FUN_08098934 が 8..11 と 12..15 を負かどうかで見る
  u8 unk_4000[0x401D - 0x4000];    // 0x4000
  u8 unk_401d;                     // 0x401D, 根拠: FUN_08091bbc が 1 を入れる
  u8 unk_401e[0x402C - 0x401E];    // 0x401E
  void* unk_402c[3];               // 0x402C
  u32 unk_4038;                    // 0x4038
  u8 unk_403c[20];                 // 0x403C
  u16 unk_4050;                    // 0x4050
  u16 unk_4052;                    // 0x4052
  u16 unk_4054;                    // 0x4054
  u16 unk_4056;                    // 0x4056
  u16 unk_4058[2];                 // 0x4058
} EntityCC28;
static_assert(sizeof(EntityCC28) == 16476);

extern EntityCC28* gEntityCC28;  // 0x0300013C

extern EntityCC28Func* const sEntityCC28State2Fns[];  // 0x085ACFDC

void FUN_08092bf0(EntityCC28* p);
void FUN_080931cc(EntityCC28* p);
void FUN_08093158(EntityCC28* p);

const u16 u16_ARRAY_085ac064[16] = {0xD01B, 0xD000, 0xD000, 0xD41B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD81B, 0xD000, 0xD000, 0xDC1B};

void FUN_0808a33c(EntityCC28* p, EntityCC28Func* fn) {
  p->updateCallback = fn;
  p->unk_9ec = 0;
}

// 状態関数を差し替えて, hide で2枚のスプライトの表示/非表示を切り替える
NAKED void EntityCC28_SetState(EntityCC28* p, EntityCC28Func* fn, s8 hide) { INCFUNC("asm/func/EntityCC28_SetState.inc"); }

NAKED void FUN_0808a3c4(EntityCC28* p, TilemapFile* param_2, s16 param_3, s32 param_4, unknown* param_5) { INCFUNC("asm/func/FUN_0808a3c4.inc"); }

// 残差は 18 命令 vs 14 命令 で、原典は (x&31)*2 と (y&31)*64 をバイト単位で別々に足している
NON_MATCH BgMapEntry* FUN_0808a420(s32 bg, u32 x, u32 y) {
#ifdef NONMATCHING_C
  return gBgStates[bg].tilemap + (x & 31) + (y & 31) * 32;
#else
  INCFUNC("asm/func/FUN_0808a420.inc");
#endif
}

// param_2 で 0x11 / 0x91 / 0x31 を選んで param_1 に足す
// param_2 で 0x11 / 0x91 / 0x31 を選んで param_1 に足す
s32 FUN_0808a440(s32 param_1, s32 param_2) {
  s32 off = 0x11;

  if (param_2 != 0) {
    off = 0x31;
    if (param_2 == 1) {
      off = 0x91;
    }
  }

  return param_1 + off;
}

NAKED void FUN_0808a458(s32 param_1, u16 param_2) { INCFUNC("asm/func/FUN_0808a458.inc"); }

s32 MinS32(s32 a, s32 b) {
  s32 min = b;

  if (a <= b) {
    min = a;
  }
  return min;
}

NAKED void FUN_0808a4ac(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_0808a4ac.inc"); }

// HP を FUN_0808a4ac に渡す
void EntityCC28_DrawHP(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { FUN_0808a4ac(p, param_2, p->player->hp, p->player->maxHP, param_3, param_4); }

// EN を FUN_0808a4ac に渡す
void EntityCC28_DrawEne(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { FUN_0808a4ac(p, param_2, p->player->ene, p->player->maxEne, param_3, param_4); }

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

// sprite_f64 を表示してポーズを差し替える
void FUN_0808b86c(EntityCC28* p, u32 poseIdx) {
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[0], p->gfx, poseIdx + 0x29, 1);
}

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

// 画面下2行のテキストボックスに1行表示する
void EntityCC28_ShowBottomLine(u8* pc, s32 line, s32 playSound) {
  if (playSound) {
    PlaySound_082406e0(0x107);
  }

  FUN_08049e5c();
  TextBox_Start(pc);
  TextBox_SetRect(0, 16, 30, 2);
  TextBox_ShowLine(line);
}

NAKED void FUN_0808c548(EntityCC28* p) { INCFUNC("asm/func/FUN_0808c548.inc"); }

NAKED void FUN_0808c61c(EntityCC28* p, u16 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808c61c.inc"); }

s32 FUN_0808c648(s32 param_1) {
  if (param_1 == 0) {
    return 0x93;
  }
  return param_1 + 0xA0;
}

NAKED void FUN_0808c658(EntityCC28* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808c658.inc"); }

void FUN_0808c700(EntityCC28* p) { FUN_0808c658(p, -1, -1); }

NAKED s32 FUN_0808c710(unknown* param_1, ParticleGroup* param_2) { INCFUNC("asm/func/FUN_0808c710.inc"); }

NAKED s32 FUN_0808c770(unknown* param_1) { INCFUNC("asm/func/FUN_0808c770.inc"); }

NAKED void FUN_0808c7c4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808c7c4.inc"); }

NAKED void FUN_0808c834(s32 param_1, s32 param_2, s16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_0808c834.inc"); }

NAKED void FUN_0808c95c(s32 param_1, s32 param_2, s16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_0808c95c.inc"); }

NAKED void FUN_0808cacc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cacc.inc"); }

NAKED void FUN_0808cb00(s32 param_1) { INCFUNC("asm/func/FUN_0808cb00.inc"); }

NAKED void FUN_0808cb90(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cb90.inc"); }

NAKED void FUN_0808cbd8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cbd8.inc"); }

NAKED void FUN_0808cc14(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cc14.inc"); }

NAKED void FUN_0808cc84(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cc84.inc"); }

NAKED void FUN_0808ce98(EntityCC28* p) { INCFUNC("asm/func/FUN_0808ce98.inc"); }

NAKED void FUN_0808cf14(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cf14.inc"); }

void FUN_0808cf50(EntityCC28* p) { MainSprite_Remove(&p->unk_a34); }

NAKED void FUN_0808cf64(EntityCC28* p) { INCFUNC("asm/func/FUN_0808cf64.inc"); }

void FUN_0808cffc(EntityCC28* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->unk_aa0[i]);
  }
}

NAKED void FUN_0808d01c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d01c.inc"); }

NAKED void FUN_0808d0c0(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d0c0.inc"); }

NAKED void FUN_0808d1a8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d1a8.inc"); }

NAKED void FUN_0808d200(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d200.inc"); }

NAKED void FUN_0808d268(void) { INCFUNC("asm/func/FUN_0808d268.inc"); }

NAKED void FUN_0808d2ac(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d2ac.inc"); }

// 4組のスプライトを隠す
void EntityCC28_HideSprites(EntityCC28* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->unk_c0c[i].sprite.flags |= SPRFLAG_HIDDEN;
    p->unk_da0[i].sprite.flags |= SPRFLAG_HIDDEN;
  }
}

NAKED void FUN_0808d3d4(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d3d4.inc"); }

NAKED s32 FUN_0808d49c(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0808d49c.inc"); }

NAKED void FUN_0808d4dc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d4dc.inc"); }

NAKED void FUN_0808d564(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d564.inc"); }

NAKED void FUN_0808d5cc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d5cc.inc"); }

NAKED void FUN_0808d774(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d774.inc"); }

NAKED void FUN_0808d908(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d908.inc"); }

NAKED void FUN_0808d93c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d93c.inc"); }

// 4つめのスプライトが指す武器を Player に適用する
void EntityCC28_ApplyWeapon(EntityCC28* p) { Player_ApplyWeapon(p->player, p->unk_da0[p->unk_c0c[3].unk_60].weapon); }

NAKED void FUN_0808d9c8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808d9c8.inc"); }

NAKED s32 FUN_0808da14(EntityCC28* p) { INCFUNC("asm/func/FUN_0808da14.inc"); }

s32 FUN_0808da88(EntityCC28* p) {
  if (FUN_0808da14(p) != 0) {
    FUN_0808d908(p);
    return 1;
  }
  return 0;
}

NAKED void FUN_0808daa8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808daa8.inc"); }

NAKED void FUN_0808db68(EntityCC28* p) { INCFUNC("asm/func/FUN_0808db68.inc"); }

NAKED void FUN_0808dcdc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808dcdc.inc"); }

// 4組のスプライトを描画リストから外す
// 残差は adds のオペランド順と pool ロードの位置だけ (命令数は同じ), 原典は (i * 100) + p の順で足している
// 要素ポインタのローカルを挟むとレジスタが1本増えて悪化し, 添字を u32 にしても変わらない
NON_MATCH void FUN_0808dda4(EntityCC28* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite_Remove(&p->unk_c0c[i].sprite);
    MainSprite_Remove(&p->unk_da0[i].sprite);
  }
#else
  INCFUNC("asm/func/FUN_0808dda4.inc");
#endif
}

NAKED void FUN_0808dddc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808dddc.inc"); }

void FUN_0808de30(EntityCC28* p) {
  FUN_0808d5cc(p);
  FUN_0808d4dc(p);
  FUN_0808d3d4(p);
  EntityCC28_ApplyWeapon(p);
}

void FUN_0808de50(EntityCC28* p) {
  FUN_0808d774(p);
  FUN_0808d564(p);
  FUN_0808d3d4(p);
  FUN_0808d93c(p);
}

NAKED void FUN_0808de70(EntityCC28* p) { INCFUNC("asm/func/FUN_0808de70.inc"); }

NAKED void FUN_0808df7c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808df7c.inc"); }

NAKED void FUN_0808dfcc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808dfcc.inc"); }

NAKED void FUN_0808e008(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e008.inc"); }

NAKED void FUN_0808e0e0(s32 param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808e0e0.inc"); }

NAKED void FUN_0808e17c(s32 param_1) { INCFUNC("asm/func/FUN_0808e17c.inc"); }

NAKED void FUN_0808e1b8(s32 param_1) { INCFUNC("asm/func/FUN_0808e1b8.inc"); }

// BG0 の (9, 0x11) から2行ぶん 12 タイルを 0xD000 で埋める
void FUN_0808e1f4(void) {
  BgMapEntry* e;
  s32 x, y;

  for (y = 0; y < 2; y++) {
    e = FUN_0808a420(0, 9, y + 0x11);

    for (x = 0; x < 12; x++) {
      *e = 0xD000;
      e++;
    }
  }
}

NAKED void FUN_0808e224(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e224.inc"); }

void FUN_0808e224(EntityCC28*);

void FUN_0808e400(EntityCC28* p) {
  if (!(gEntityDisableFlags & 1)) {
    FUN_0808e224(p);
  }
}

NAKED void FUN_0808e420(void) { INCFUNC("asm/func/FUN_0808e420.inc"); }

NAKED void FUN_0808e4f4(void) { INCFUNC("asm/func/FUN_0808e4f4.inc"); }

NAKED void FUN_0808e53c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e53c.inc"); }

NAKED void FUN_0808e5a8(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e5a8.inc"); }

NAKED void FUN_0808e734(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e734.inc"); }

NAKED void FUN_0808e83c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e83c.inc"); }

s32 FUN_0808e8b8(s32 param_1) {
  switch (param_1 >> 2) {
    case 0: {
      return 0;
    }
    case 1: {
      return 1;
    }
    case 2: {
      return 2;
    }
    case 3: {
      return 1;
    }
  }

  return 0;
}

NAKED void FUN_0808e8dc(EntityCC28* p) { INCFUNC("asm/func/FUN_0808e8dc.inc"); }

NAKED void FUN_0808eb4c(EntityCC28* p) { INCFUNC("asm/func/FUN_0808eb4c.inc"); }

// タイルマップを読み込み直して、状態関数を FUN_0808ee50 に切り替える
void FUN_0808ee50(EntityCC28* p);

void FUN_0808ebe8(EntityCC28* p) {
  FUN_0808a3c4(p, p->unk_2c, 0, 3, p->unk_3c);
  FUN_0808eb4c(p);
  FUN_0808a33c(p, FUN_0808ee50);
}

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

// 太陽ゲージをメニューの表示段階 (2..9) に直す
s32 FUN_0808f140(void) {
  s32 gauge = gStat->sunGauge;

  if (gauge <= 1) {
    return 9;
  }
  if (gauge > 9) {
    return 2;
  }

  return 11 - gauge;
}

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

// 残差は命令2本の順序だけ (原典は ~DISPCNT_BG1_ON のプール読みを gStagedDISPCNT の ldrh より先に出す)
NON_MATCH void FUN_0808f95c(EntityCC28* p) {
#ifdef NONMATCHING_C
  p->unk_401e[0] = FUN_0808f140();
  gStagedDISPCNT &= ~DISPCNT_BG1_ON;
  FUN_0808f21c(p);
#else
  INCFUNC("asm/func/FUN_0808f95c.inc");
#endif
}

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

void FUN_0808fc8c(void) {
  if (VM_SeekToNamedArg('f')) {
    gStat->unk_256 = VM_GetValue();
  }
}

void FUN_0808fcb4(void) {
  if (VM_SeekToNamedArg('s')) {
    gStat->unk_258 = VM_GetValue();
  }
}

void FUN_0808fcd8(void) {
  if (VM_SeekToNamedArg('f')) {
    gStat->unk_25a = VM_GetValue();
  }
}

// VM の i 引数で指定されたマップを解放済みにする
void UnlockMap(void) {
  if (VM_SeekToNamedArg('i')) {
    gStat->unlockedMap |= 1 << VM_GetValue();
  }
}

u32 IsMapUnlocked(u32 mapIdx) { return gStat->unlockedMap & (1 << mapIdx); }

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

// BG1 のタイルマップ全面を 0xE002 で埋める
void EntityCC28_FillBg1(void) {
  s32 x, y;

  for (y = 0; y < 32; y++) {
    for (x = 0; x < 32; x++) {
      *FUN_0808a420(1, x, y) = 0xE002;
    }
  }
}

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
extern u16 u16_03002c14;  // src/iwram2.c

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

void FUN_08091b40(EntityCC28* p, u8 val) {
  p->unk_3fb0 = 1;
  p->unk_3fb1 = val;
  p->unk_3ae4 = 1;
}

NAKED void FUN_08091b68(EntityCC28* p) { INCFUNC("asm/func/FUN_08091b68.inc"); }

void FUN_08091bbc(EntityCC28* p) {
  p->unk_3fa2 = 0;
  p->unk_401d = 1;
  p->unk_3ae4 = 1;
}

NAKED void FUN_08091be0(EntityCC28* p) { INCFUNC("asm/func/FUN_08091be0.inc"); }

void FUN_08091c50(EntityCC28* p, u8 val) {
  p->unk_3fb8 = 1;
  p->unk_3fb9 = val;
  p->unk_3ae4 = 1;
}

void FUN_08091c78(void) {
  s32 i;

  for (i = 0; i < 16; i++) {
    SetRotCount2(i, 0);
  }
}

NAKED void FUN_08091c90(void) { INCFUNC("asm/func/FUN_08091c90.inc"); }

NAKED u32 FUN_08091cb8(item32_t n) { INCFUNC("asm/func/FUN_08091cb8.inc"); }

// 残差は 11 命令 vs 9 命令 で、u8 を返す item_0809179c の戻り値がこちらでは 1 回切り詰められる
NON_MATCH bool32 FUN_08091e34(item32_t n) {
#ifdef NONMATCHING_C
  if (item_0809179c(n) == 1) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08091e34.inc");
#endif
}

void FUN_08091e48(EntityCC28* p, s32 slot) {
  if (p->inValuableInventory == 0) {
    RemoveItem(slot);
  }
}

NAKED void FUN_08091e64(EntityCC28* p, s32 selectedSlot) { INCFUNC("asm/func/FUN_08091e64.inc"); }

void FUN_0809200c(EntityCC28* p, s32 slotA, s32 slotB) {
  if (p->inValuableInventory == 0) {
    SwapNormalItem(slotA, slotB);
  } else {
    SwapValuable(slotA, slotB);
  }
}

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

// 16フレーム待ってから次の状態へ進む
void FUN_08092bb8(EntityCC28* p) {
  if (p->unk_9ee <= 15) {
    p->unk_9ee++;
  } else if (FUN_0808c1cc(p)) {
    EntityCC28_SetState(p, FUN_08092bf0, 1);
  }
}

NAKED void FUN_08092bf0(EntityCC28* p) { INCFUNC("asm/func/FUN_08092bf0.inc"); }

void FUN_08092c7c(EntityCC28* p, u8 val) {
  p->unk_3f9d = val;
  TextBox_Close();
  FUN_08049e5c();
  FUN_08049f84();
  EntityCC28_SetState(p, FUN_080931cc, 1);
}

NAKED void FUN_08092cac(EntityCC28* p) { INCFUNC("asm/func/FUN_08092cac.inc"); }

NAKED s32 FUN_08092e20(EntityCC28* p) { INCFUNC("asm/func/FUN_08092e20.inc"); }

void FUN_0809312c(EntityCC28* p) {
  s32 v = FUN_08092e20(p);

  if (v >= 0) {
    p->unk_3f9d = v;
    EntityCC28_SetState(p, FUN_08093158, 1);
  }
}

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

// はい/いいえの選択結果で、決定なら効果音を鳴らして次へ進み、キャンセルならテキストボックスを閉じる
void FUN_0809455c(EntityCC28* p) {
  s32 v = FUN_0808b760(p);

  if (v == 0) {
    PlaySound_082406e0(0xDE);
    FUN_08092744(p);
  } else if (v == 1) {
    TextBox_Close();
    FUN_08093f28(p);
  }
}

NAKED void FUN_0809458c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809458c.inc"); }

NAKED void FUN_080945f4(EntityCC28* p) { INCFUNC("asm/func/FUN_080945f4.inc"); }

NAKED void FUN_08094660(EntityCC28* p) { INCFUNC("asm/func/FUN_08094660.inc"); }

NAKED void FUN_080946dc(EntityCC28* p) { INCFUNC("asm/func/FUN_080946dc.inc"); }

NAKED void FUN_08094780(EntityCC28* p) { INCFUNC("asm/func/FUN_08094780.inc"); }

NAKED void FUN_08094838(EntityCC28* p) { INCFUNC("asm/func/FUN_08094838.inc"); }

NAKED void FUN_080948ac(EntityCC28* p) { INCFUNC("asm/func/FUN_080948ac.inc"); }

void FUN_08094988(void) {
  s32 i;

  for (i = 0; i < 3; i++) {
    *FUN_0808a420(0, i + 14, 8) = 0xF001;
  }
}

NAKED void FUN_080949b0(EntityCC28* p) { INCFUNC("asm/func/FUN_080949b0.inc"); }

NAKED void FUN_08094a94(EntityCC28* p, u32 permission) { INCFUNC("asm/func/FUN_08094a94.inc"); }

NAKED void FUN_08094c6c(s32 param_1, u8* param_2) { INCFUNC("asm/func/FUN_08094c6c.inc"); }

NAKED void FUN_08094cdc(s32 param_1, s32 param_2, u8* param_3, s8* param_4) { INCFUNC("asm/func/FUN_08094cdc.inc"); }

void FUN_08094d1c(u8* param_1, s8* param_2) { FUN_08094cdc(0, -1, param_1, param_2); }

void FUN_08094d30(s32 param_1, u8* param_2, s8* param_3) { FUN_08094cdc(1, param_1, param_2, param_3); }

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

void FUN_08096f90(EntityCC28* p) { MainSprite_AdvanceAnim(&p->sprites[13], p->gfx); }

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

// unk_3ff0 から value の位置を探す
s32 FUN_08097d20(EntityCC28* p, s32 value) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (value == p->unk_3ff0[i]) {
      return i;
    }
  }

  return -1;
}

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

void FUN_0809877c(EntityCC28* p) {
  FUN_08098734(p);
  FUN_08097d4c(p);
  FUN_08098758(p);
  FUN_08097e3c(p);
  FUN_0808bac4(p);
}

NAKED void FUN_080987a4(EntityCC28* p) { INCFUNC("asm/func/FUN_080987a4.inc"); }

NAKED void FUN_0809889c(EntityCC28* p) { INCFUNC("asm/func/FUN_0809889c.inc"); }

// unk_3ff0 の 8..11 に埋まっているものがあるか
s32 FUN_0809890c(EntityCC28* p) {
  s32 i;

  for (i = 8; i < 12; i++) {
    if (p->unk_3ff0[i] >= 0) {
      return 1;
    }
  }

  return 0;
}

// unk_3ff0 の 12..15 に埋まっているものがあるか
s32 FUN_08098934(EntityCC28* p) {
  s32 i;

  for (i = 12; i < 16; i++) {
    if (p->unk_3ff0[i] >= 0) {
      return 1;
    }
  }

  return 0;
}

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

// line が負ならテキストボックスを閉じ, そうでなければ画面下2行にその行を即時表示する
void EntityCC28_ShowLineInstant(EntityCC28* p, s32 line) {
  if (line < 0) {
    TextBox_Close();
  } else {
    TextBox_SetInstant(1);
    TextBox_Start(p->unk_58);
    TextBox_SetRect(0, 18, 30, 2);
    TextBox_ShowLine(line);
  }
}

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

// メッセージ速度の設定値を 1 と 2 で入れ替えて返す
s32 FUN_08099b5c(void) {
  if (gStat->messageSpeed == 1) {
    return 2;
  }
  if (gStat->messageSpeed == 2) {
    return 1;
  }
  return 0;
}

s32 FUN_08099b84(s32 n) {
  if (n == 0) {
    return 4;
  }
  if (n == 1) {
    return 2;
  }
  return 1;
}

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

void FUN_0809a67c(EntityCC28* p) {
  sEntityCC28State2Fns[p->state2](p);
  FUN_0808b4c0(p);
}

NAKED void FUN_0809a6a8(EntityCC28* p) { INCFUNC("asm/func/FUN_0809a6a8.inc"); }

void FUN_0809a800(void) { LoadParticleFile(GetFile(DIR_PARTICLE, 0x3002)); }

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

// スプライトを全部描画リストから外す
void EntityCC28_RemoveSprites(EntityCC28* p) {
  MainSprite* sprite = p->sprites;
  s32 i;

  for (i = 0; i < 116; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  AuxSprite_Remove(&p->sprite_b60);
  AuxSprite_Remove(&p->sprite_bb8);
}

NAKED void FUN_0809b468(EntityCC28* p) { INCFUNC("asm/func/FUN_0809b468.inc"); }

NAKED void FUN_0809bd14(EntityCC28* p) { INCFUNC("asm/func/FUN_0809bd14.inc"); }

NAKED void FUN_0809bed8(EntityCC28* p) { INCFUNC("asm/func/FUN_0809bed8.inc"); }

NAKED void FUN_0809bf88(EntityCC28* p) { INCFUNC("asm/func/FUN_0809bf88.inc"); }

// VM の q 引数があればその値を, なければ 1 を unk_da0[3] に書き込む
void FUN_0809c010(EntityCC28* p) {
  if (VM_SeekToNamedArg('q')) {
    p->unk_da0[3].unk_65 = VM_GetValue();
  } else {
    p->unk_da0[3].unk_65 = 1;
  }
}

NAKED void FUN_0809c040(void) { INCFUNC("asm/func/FUN_0809c040.inc"); }

s32 FUN_0809c068(void) {
  if (gEntityCC28 == NULL) {
    return -1;
  }
  return gEntityCC28->unk_9fc;
}

NAKED s32 FUN_0809c08c(s32 mode) { INCFUNC("asm/func/FUN_0809c08c.inc"); }

void FUN_0809c1c0(void) {
  if (gEntityCC28 != NULL) {
    gEntityCC28->unk_9ff = gEntityCC28->unk_9fe;
  }
}

void FUN_0809c1e8(void) {
  EntityCC28* p = gEntityCC28;

  if (p != NULL) {
    if (p->unk_9ff >= 0) {
      FUN_0809c08c(p->unk_9ff);
      p->unk_9ff = 0xFF;
    }
  }
}

void FUN_0809c214(void) { FUN_0809c1c0(); }

void FUN_0809c220(void) { FUN_0809c1e8(); }

void Textbox_CloseBox(void) {
  if (VM_SeekToNamedArg('m')) {
    FUN_0809c08c(VM_GetValue());
  }
}

void FUN_0809c244(void) {
  if (gEntityCC28 != NULL) {
    FUN_0809c08c(gEntityCC28->unk_9fe);
  }
}

void FUN_0809c264(void) {
  if (gEntityCC28 != NULL && gEntityCC28->unk_9fc == 0) {
    FUN_0809bf88(gEntityCC28);
  }
}

NAKED void FUN_0809c28c(void) { INCFUNC("asm/func/FUN_0809c28c.inc"); }

NAKED void FUN_0809c2d0(void) { INCFUNC("asm/func/FUN_0809c2d0.inc"); }

// VM の f 引数を unk_da0[3] に書き込む
void FUN_0809c314(void) {
  if (gEntityCC28 != NULL) {
    if (VM_SeekToNamedArg('f')) {
      gEntityCC28->unk_da0[3].unk_65 = VM_GetValue();
    }
  }
}

NAKED void FUN_0809c344(s32 param_1, s32 param_2, u16 param_3, u8 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0809c344.inc"); }

NAKED void FUN_0809c3c0(s32 param_1, u16 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0809c3c0.inc"); }

void FUN_0809c430(void) {
  EntityCC28* p = gEntityCC28;

  if (p != NULL) {
    if (p->unk_9fe == 1 || p->unk_9fe == 2) {
      p->unk_a22 = 4;
    }
  }
}

NAKED void FUN_0809c464(void) { INCFUNC("asm/func/FUN_0809c464.inc"); }

NAKED void FUN_0809c4f4(void) { INCFUNC("asm/func/FUN_0809c4f4.inc"); }

NAKED void FUN_0809c544(s32 param_1) { INCFUNC("asm/func/FUN_0809c544.inc"); }

NAKED void FUN_0809c58c(void) { INCFUNC("asm/func/FUN_0809c58c.inc"); }

void FUN_0809c5dc(void) {
  if (gEntityCC28 != NULL) {
    FUN_0808abec(gEntityCC28, 2);
  }
}

NAKED void FUN_0809c5f4(void) { INCFUNC("asm/func/FUN_0809c5f4.inc"); }

// 残差は 17 命令 vs 16 命令 で、&& と入れ子の if どちらでも 1 命令多い
NON_MATCH void FUN_0809c63c(void) {
#ifdef NONMATCHING_C
  if (gEntityCC28 != NULL && VM_SeekToNamedArg('i')) {
    gEntityCC28->unk_3fa0[0] = VM_GetValue();
  }
#else
  INCFUNC("asm/func/FUN_0809c63c.inc");
#endif
}

NAKED void FUN_0809c668(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c668.inc"); }

NAKED void FUN_0809c70c(void) { INCFUNC("asm/func/FUN_0809c70c.inc"); }

NAKED void FUN_0809c780(EntityCC28* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0809c780.inc"); }

NAKED void FUN_0809c880(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c880.inc"); }

NAKED s32 FUN_0809c8e8(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c8e8.inc"); }

s32 EntityCC28_Destroy(EntityCC28* p) {
  FUN_0808cf50(p);
  FUN_0808cffc(p);
  MainSprite_Remove(&p->unk_c0c[0].sprite);
  MainSprite_Remove(&p->unk_da0[0].sprite);
  gEntityCC28 = NULL;
  return 0;
}

NAKED void FUN_0809c960(EntityCC28* p) { INCFUNC("asm/func/FUN_0809c960.inc"); }

NAKED void FUN_0809ca08(EntityCC28* p) { INCFUNC("asm/func/FUN_0809ca08.inc"); }

NAKED s32 FUN_0809cae0(EntityCC28* p, unknown* param_2) { INCFUNC("asm/func/FUN_0809cae0.inc"); }

NAKED EntityCC28* EntityCC28_Create_0809cb74(u32 val, unknown* param_2) { INCFUNC("asm/func/EntityCC28_Create_0809cb74.inc"); }

s32 EntityCC28_Update_0809cbd0(EntityCC28* p) {
  Player* player = gPlayerPtr[0];

  p->player = player;

  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }

  FUN_0808c7c4(p);
  return 0;
}

s32 EntityCC28_Destroy_0809cc04(EntityCC28* p) {
  FUN_0808dda4(p);
  FUN_0808cf50(p);
  FUN_0808cacc(p);
  EntityCC28_RemoveSprites(p);
  FUN_0808cffc(p);
  u16_03002c14 = p->state2;
  gEntityCC28 = NULL;
  return 0;
}

NAKED s32 FUN_0809cc48(EntityCC28* p) { INCFUNC("asm/func/FUN_0809cc48.inc"); }

NAKED EntityCC28* EntityCC28_Create_0809ce04(u32 val, unknown* param_2) { INCFUNC("asm/func/EntityCC28_Create_0809ce04.inc"); }

EntityCC28* EntityCC28_Create(u32 val, unknown* param_2) {
  if (gFlag030047a4 & FLAG030047A4_LINK) {
    return EntityCC28_Create_0809cb74(val, param_2);
  }
  return EntityCC28_Create_0809ce04(val, param_2);
}

// 0x085AC084〜0x085ACEC7 は下の3本のポインタ表が指すデータ本体
// PTR_ARRAY_085acec8 が指すものは1レコード16バイト, PTR_ARRAY_085acf04 と PTR_ARRAY_085acf40 が指すものは1レコード4バイト
const u8 u8_ARRAY_085ac084[2][16] = {
    {0x00, 0x00, 0x00, 0x00, 0x40, 0x20, 0xFF, 0xFF, 0xFF, 0x01, 0x08, 0xFF, 0xFF, 0xFF, 0x01, 0x00},
    {0x01, 0x01, 0x00, 0x00, 0x20, 0x20, 0xFF, 0xFF, 0x00, 0xFF, 0x04, 0xFF, 0xFF, 0x00, 0xFF, 0x01},
};  // 0x085AC084

const u8 u8_ARRAY_085ac0a4[13][4] = {
    {0x00, 0x24, 0x34, 0x00},
    {0x00, 0x2E, 0x2C, 0x00},
    {0x00, 0x3C, 0x26, 0x00},
    {0x00, 0x4A, 0x1E, 0x00},
    {0x00, 0x52, 0x16, 0x00},
    {0x00, 0x5A, 0x0E, 0x00},
    {0x01, 0x15, 0x2B, 0x00},
    {0x01, 0x22, 0x28, 0x00},
    {0x01, 0x2C, 0x32, 0x00},
    {0x01, 0x1B, 0x1F, 0x00},
    {0x01, 0x19, 0x17, 0x00},
    {0x01, 0x22, 0x12, 0x00},
    {0x01, 0x2B, 0x0F, 0x00},
};  // 0x085AC0A4

const u8 u8_ARRAY_085ac0d8[6][16] = {
    {0x02, 0x02, 0x00, 0x00, 0x4A, 0x42, 0xFF, 0x01, 0xFF, 0x04, 0x0A, 0xFF, 0xFF, 0xFF, 0x04, 0x02},
    {0x02, 0x03, 0x0A, 0x22, 0x4A, 0x42, 0x00, 0xFF, 0xFF, 0x05, 0x01, 0xFF, 0xFF, 0xFF, 0x05, 0x03},
    {0x03, 0x04, 0x0A, 0x00, 0x40, 0x40, 0xFF, 0x03, 0x00, 0xFF, 0x02, 0xFF, 0xFF, 0x00, 0xFF, 0x04},
    {0x03, 0x05, 0x00, 0x00, 0x40, 0x40, 0x02, 0x04, 0x00, 0xFF, 0x03, 0xFF, 0xFF, 0x00, 0xFF, 0x05},
    {0x03, 0x06, 0x00, 0x00, 0x40, 0x40, 0x03, 0x05, 0x00, 0xFF, 0x07, 0xFF, 0xFF, 0x00, 0xFF, 0x06},
    {0x03, 0x07, 0x13, 0x14, 0x40, 0x40, 0x04, 0xFF, 0x01, 0xFF, 0x01, 0xFF, 0xFF, 0x01, 0xFF, 0x07},
};  // 0x085AC0D8

// clang-format off
const u8 u8_ARRAY_085ac138[40][4] = {
    {0x00, 0x26, 0x56, 0x00},
    {0x00, 0x36, 0x44, 0x00},
    {0x00, 0x24, 0x34, 0x00},
    {0x00, 0x49, 0x2F, 0x00},
    {0x00, 0x37, 0x1F, 0x00},
    {0x00, 0x58, 0x40, 0x00},
    {0x00, 0x43, 0x55, 0x00},
    {0x00, 0x58, 0x5A, 0x00},
    {0x01, 0x2C, 0x17, 0x00},
    {0x01, 0x24, 0x20, 0x00},
    {0x01, 0x1A, 0x2A, 0x00},
    {0x01, 0x23, 0x33, 0x00},
    {0x01, 0x2E, 0x28, 0x00},
    {0x01, 0x3A, 0x22, 0x00},
    {0x01, 0x42, 0x1A, 0x00},
    {0x01, 0x4C, 0x12, 0x00},
    {0x01, 0x59, 0x0B, 0x00},
    {0x01, 0x65, 0x0F, 0x00},
    {0x02, 0x19, 0x27, 0x00},
    {0x02, 0x28, 0x36, 0x00},
    {0x02, 0x2A, 0x58, 0x00},
    {0x02, 0x14, 0x42, 0x00},
    {0x03, 0x25, 0x28, 0x00},
    {0x03, 0x36, 0x2C, 0x00},
    {0x03, 0x48, 0x38, 0x00},
    {0x03, 0x54, 0x4E, 0x00},
    {0x03, 0x28, 0x42, 0x00},
    {0x03, 0x3E, 0x58, 0x00},
    {0x04, 0x2E, 0x28, 0x00},
    {0x04, 0x3A, 0x2A, 0x00},
    {0x04, 0x30, 0x34, 0x00},
    {0x04, 0x3A, 0x34, 0x00},
    {0x04, 0x3D, 0x43, 0x00},
    {0x04, 0x53, 0x4D, 0x00},
    {0x04, 0x3E, 0x58, 0x00},
    {0x04, 0x28, 0x42, 0x00},
    {0x05, 0x2C, 0x32, 0x00},
    {0x05, 0x12, 0x23, 0x00},
    {0x05, 0x1C, 0x18, 0x00},
    {0x05, 0x26, 0x0E, 0x00},
};  // 0x085AC138
// clang-format on

const u8 u8_ARRAY_085ac1d8[14][4] = {
    {0x01, 0x00, 0x29, 0x12},
    {0x04, 0x00, 0x20, 0x2B},
    {0x04, 0x01, 0x16, 0x09},
    {0x11, 0x02, 0x0D, 0x24},
    {0x01, 0x03, 0x1B, 0x1B},
    {0x01, 0x04, 0x18, 0x28},
    {0x02, 0x04, 0x20, 0x2E},
    {0x11, 0x04, 0x1B, 0x18},
    {0x11, 0x04, 0x23, 0x22},
    {0x04, 0x04, 0x2A, 0x2B},
    {0x04, 0x05, 0x17, 0x17},
    {0x04, 0x04, 0x1B, 0x24},
    {0x04, 0x05, 0x08, 0x10},
    {0x00, 0x00, 0x00, 0x00},
};  // 0x085AC1D8

const u8 u8_ARRAY_085ac210[7][16] = {
    {0x04, 0x08, 0x07, 0x00, 0x47, 0x40, 0xFF, 0x01, 0xFF, 0x02, 0x02, 0xFF, 0xFF, 0xFF, 0x02, 0x08},
    {0x04, 0x09, 0x00, 0x00, 0x47, 0x40, 0x00, 0xFF, 0xFF, 0x02, 0x09, 0xFF, 0xFF, 0xFF, 0x02, 0x09},
    {0x05, 0x0A, 0x01, 0x00, 0x27, 0x2F, 0xFF, 0x03, 0x01, 0xFF, 0x06, 0xFF, 0xFF, 0x01, 0xFF, 0x0A},
    {0x05, 0x0B, 0x07, 0x00, 0x27, 0x2F, 0x02, 0x04, 0x01, 0xFF, 0x03, 0xFF, 0xFF, 0x01, 0xFF, 0x0B},
    {0x05, 0x0C, 0x02, 0x09, 0x27, 0x2F, 0x03, 0x05, 0x01, 0xFF, 0x03, 0xFF, 0xFF, 0x01, 0xFF, 0x0C},
    {0x05, 0x0D, 0x00, 0x0F, 0x27, 0x2F, 0x04, 0xFF, 0x01, 0xFF, 0x01, 0xFF, 0xFF, 0x01, 0xFF, 0x0D},
    {0x16, 0x0D, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x0E},
};  // 0x085AC210

// clang-format off
const u8 u8_ARRAY_085ac280[60][4] = {
    {0x01, 0x2A, 0x58, 0x00},
    {0x01, 0x33, 0x4F, 0x00},
    {0x01, 0x3B, 0x47, 0x00},
    {0x01, 0x42, 0x48, 0x00},
    {0x01, 0x3A, 0x40, 0x00},
    {0x01, 0x42, 0x40, 0x00},
    {0x01, 0x4A, 0x40, 0x00},
    {0x01, 0x42, 0x38, 0x00},
    {0x01, 0x4A, 0x38, 0x00},
    {0x01, 0x28, 0x42, 0x00},
    {0x01, 0x22, 0x3A, 0x00},
    {0x01, 0x32, 0x38, 0x00},
    {0x01, 0x28, 0x2E, 0x00},
    {0x01, 0x1F, 0x25, 0x00},
    {0x01, 0x17, 0x31, 0x00},
    {0x01, 0x42, 0x5C, 0x00},
    {0x01, 0x4F, 0x69, 0x00},
    {0x01, 0x48, 0x4E, 0x00},
    {0x01, 0x3C, 0x30, 0x00},
    {0x01, 0x46, 0x26, 0x00},
    {0x01, 0x56, 0x48, 0x00},
    {0x01, 0x5E, 0x54, 0x00},
    {0x01, 0x60, 0x3E, 0x00},
    {0x01, 0x69, 0x35, 0x00},
    {0x01, 0x5C, 0x26, 0x00},
    {0x01, 0x4E, 0x18, 0x00},
    {0x01, 0x43, 0x0F, 0x00},
    {0x01, 0x52, 0x30, 0x00},
    {0x00, 0x28, 0x4E, 0x00},
    {0x00, 0x1E, 0x42, 0x00},
    {0x00, 0x31, 0x59, 0x00},
    {0x00, 0x3A, 0x4F, 0x00},
    {0x00, 0x38, 0x46, 0x00},
    {0x00, 0x34, 0x36, 0x00},
    {0x00, 0x49, 0x47, 0x00},
    {0x00, 0x52, 0x3E, 0x00},
    {0x00, 0x5C, 0x36, 0x00},
    {0x00, 0x46, 0x5E, 0x00},
    {0x00, 0x56, 0x52, 0x00},
    {0x00, 0x5D, 0x4B, 0x00},
    {0x00, 0x64, 0x44, 0x00},
    {0x00, 0x65, 0x51, 0x00},
    {0x00, 0x46, 0x36, 0x00},
    {0x00, 0x3F, 0x2F, 0x00},
    {0x00, 0x46, 0x2A, 0x00},
    {0x00, 0x2F, 0x2F, 0x00},
    {0x00, 0x40, 0x20, 0x00},
    {0x06, 0x00, 0x00, 0x00},
    {0x02, 0x20, 0x20, 0x00},
    {0x03, 0x20, 0x20, 0x00},
    {0x04, 0x29, 0x0F, 0x00},
    {0x04, 0x1B, 0x1D, 0x00},
    {0x04, 0x16, 0x10, 0x00},
    {0x04, 0x29, 0x23, 0x00},
    {0x04, 0x0D, 0x19, 0x00},
    {0x04, 0x23, 0x31, 0x00},
    {0x04, 0x10, 0x28, 0x00},
    {0x05, 0x14, 0x26, 0x00},
    {0x05, 0x24, 0x22, 0x00},
    {0x05, 0x2C, 0x18, 0x00},
};  // 0x085AC280
// clang-format on

const u8 u8_ARRAY_085ac370[8][4] = {
    {0x11, 0x01, 0x1D, 0x2A},
    {0x11, 0x00, 0x1B, 0x17},
    {0x01, 0x01, 0x26, 0x1A},
    {0x11, 0x01, 0x2A, 0x37},
    {0x02, 0x04, 0x09, 0x12},
    {0x05, 0x01, 0x15, 0x2B},
    {0x05, 0x02, 0x0E, 0x0F},
    {0x00, 0x00, 0x00, 0x00},
};  // 0x085AC370

const u8 u8_ARRAY_085ac390[7][16] = {
    {0x06, 0x0E, 0x03, 0x05, 0x4A, 0x42, 0xFF, 0x01, 0xFF, 0x04, 0x0A, 0xFF, 0xFF, 0xFF, 0x04, 0x0F},
    {0x06, 0x0F, 0x03, 0x05, 0x4A, 0x42, 0x00, 0x02, 0xFF, 0x05, 0x0B, 0xFF, 0xFF, 0xFF, 0x05, 0x10},
    {0x06, 0x10, 0x00, 0x00, 0x4A, 0x42, 0x01, 0xFF, 0xFF, 0x06, 0x09, 0xFF, 0xFF, 0xFF, 0xFF, 0x11},
    {0x07, 0x11, 0x18, 0x07, 0x4A, 0x42, 0xFF, 0x04, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x12},
    {0x07, 0x12, 0x1A, 0x07, 0x4A, 0x42, 0x03, 0x05, 0x00, 0xFF, 0x07, 0xFF, 0xFF, 0x00, 0xFF, 0x13},
    {0x07, 0x13, 0x11, 0x0C, 0x4A, 0x42, 0x04, 0x06, 0x01, 0xFF, 0x07, 0xFF, 0xFF, 0x01, 0xFF, 0x14},
    {0x07, 0x14, 0x00, 0x00, 0x4A, 0x42, 0x05, 0xFF, 0x02, 0xFF, 0x05, 0xFF, 0xFF, 0xFF, 0xFF, 0x15},
};  // 0x085AC390

// clang-format off
const u8 u8_ARRAY_085ac400[104][4] = {
    {0x02, 0x11, 0x5C, 0x00},
    {0x02, 0x1D, 0x53, 0x00},
    {0x02, 0x30, 0x56, 0x00},
    {0x02, 0x3E, 0x59, 0x00},
    {0x02, 0x25, 0x59, 0x00},
    {0x02, 0x2B, 0x44, 0x00},
    {0x02, 0x35, 0x3F, 0x00},
    {0x02, 0x3E, 0x3E, 0x00},
    {0x02, 0x46, 0x46, 0x00},
    {0x02, 0x39, 0x50, 0x00},
    {0x02, 0x36, 0x5B, 0x00},
    {0x02, 0x37, 0x69, 0x00},
    {0x02, 0x49, 0x62, 0x00},
    {0x02, 0x4F, 0x55, 0x00},
    {0x02, 0x3A, 0x2C, 0x00},
    {0x02, 0x40, 0x28, 0x00},
    {0x02, 0x3C, 0x34, 0x00},
    {0x02, 0x47, 0x35, 0x00},
    {0x01, 0x3D, 0x21, 0x00},
    {0x01, 0x33, 0x23, 0x00},
    {0x01, 0x37, 0x2B, 0x00},
    {0x01, 0x41, 0x2D, 0x00},
    {0x00, 0x32, 0x24, 0x00},
    {0x00, 0x37, 0x2B, 0x00},
    {0x00, 0x41, 0x2B, 0x00},
    {0x00, 0x3B, 0x1F, 0x00},
    {0x00, 0x27, 0x19, 0x00},
    {0x02, 0x28, 0x2A, 0x00},
    {0x01, 0x22, 0x20, 0x00},
    {0x00, 0x22, 0x20, 0x00},
    {0x01, 0x22, 0x20, 0x00},
    {0x01, 0x27, 0x19, 0x00},
    {0x02, 0x2D, 0x23, 0x00},
    {0x02, 0x39, 0x19, 0x00},
    {0x01, 0x31, 0x0D, 0x00},
    {0x01, 0x38, 0x10, 0x00},
    {0x00, 0x58, 0x1A, 0x00},
    {0x00, 0x4C, 0x23, 0x00},
    {0x02, 0x4C, 0x1F, 0x00},
    {0x02, 0x4C, 0x1F, 0x00},
    {0x01, 0x46, 0x15, 0x00},
    {0x01, 0x46, 0x15, 0x00},
    {0x01, 0x46, 0x15, 0x00},
    {0x00, 0x46, 0x15, 0x00},
    {0x00, 0x46, 0x15, 0x00},
    {0x00, 0x46, 0x15, 0x00},
    {0x00, 0x33, 0x0F, 0x00},
    {0x02, 0x59, 0x17, 0x00},
    {0x02, 0x52, 0x2C, 0x00},
    {0x02, 0x5D, 0x23, 0x00},
    {0x01, 0x57, 0x19, 0x00},
    {0x01, 0x57, 0x19, 0x00},
    {0x01, 0x4E, 0x22, 0x00},
    {0x02, 0x6D, 0x21, 0x00},
    {0x00, 0x5F, 0x25, 0x00},
    {0x00, 0x57, 0x2B, 0x00},
    {0x00, 0x4D, 0x31, 0x00},
    {0x01, 0x5E, 0x24, 0x00},
    {0x01, 0x56, 0x2A, 0x00},
    {0x01, 0x4D, 0x31, 0x00},
    {0x02, 0x2D, 0x2D, 0x00},
    {0x02, 0x34, 0x26, 0x00},
    {0x02, 0x40, 0x1E, 0x00},
    {0x01, 0x2C, 0x1E, 0x00},
    {0x01, 0x3A, 0x14, 0x00},
    {0x02, 0x36, 0x34, 0x00},
    {0x02, 0x35, 0x22, 0x00},
    {0x02, 0x4B, 0x2D, 0x00},
    {0x02, 0x41, 0x23, 0x00},
    {0x02, 0x5E, 0x30, 0x00},
    {0x02, 0x48, 0x3E, 0x00},
    {0x02, 0x50, 0x36, 0x00},
    {0x02, 0x60, 0x2A, 0x00},
    {0x01, 0x48, 0x2E, 0x00},
    {0x01, 0x52, 0x24, 0x00},
    {0x00, 0x2D, 0x1D, 0x00},
    {0x00, 0x38, 0x16, 0x00},
    {0x00, 0x56, 0x24, 0x00},
    {0x02, 0x74, 0x1A, 0x00},
    {0x05, 0x20, 0x20, 0x00},
    {0x04, 0x0E, 0x2A, 0x00},
    {0x04, 0x14, 0x2E, 0x00},
    {0x03, 0x12, 0x28, 0x00},
    {0x03, 0x22, 0x20, 0x00},
    {0x03, 0x2E, 0x16, 0x00},
    {0x04, 0x2A, 0x16, 0x00},
    {0x04, 0x33, 0x1F, 0x00},
    {0x06, 0x68, 0x2E, 0x00},
    {0x06, 0x73, 0x27, 0x00},
    {0x06, 0x73, 0x27, 0x00},
    {0x06, 0x68, 0x2E, 0x00},
    {0x06, 0x5F, 0x38, 0x00},
    {0x06, 0x54, 0x44, 0x00},
    {0x06, 0x48, 0x4F, 0x00},
    {0x02, 0x6E, 0x32, 0x00},
    {0x02, 0x5E, 0x36, 0x00},
    {0x02, 0x52, 0x3C, 0x00},
    {0x02, 0x64, 0x34, 0x00},
    {0x01, 0x55, 0x31, 0x00},
    {0x02, 0x66, 0x3A, 0x00},
    {0x06, 0x19, 0x5B, 0x00},
    {0x06, 0x0E, 0x51, 0x00},
    {0x02, 0x2F, 0x36, 0x00},
    {0x06, 0x7A, 0x20, 0x00},
};  // 0x085AC400
// clang-format on

const u8 u8_ARRAY_085ac5a0[11][4] = {
    {0x11, 0x01, 0x20, 0x11},
    {0x01, 0x02, 0x2C, 0x14},
    {0x01, 0x02, 0x38, 0x0E},
    {0x01, 0x02, 0x32, 0x12},
    {0x01, 0x02, 0x1E, 0x14},
    {0x01, 0x00, 0x1E, 0x12},
    {0x01, 0x02, 0x2B, 0x0F},
    {0x02, 0x02, 0x32, 0x18},
    {0x05, 0x02, 0x0D, 0x29},
    {0x05, 0x02, 0x35, 0x12},
    {0x00, 0x00, 0x00, 0x00},
};  // 0x085AC5A0

const u8 u8_ARRAY_085ac5cc[6][16] = {
    {0x08, 0x15, 0x08, 0x09, 0x4A, 0x46, 0xFF, 0x01, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x16},
    {0x08, 0x16, 0x18, 0x1C, 0x68, 0x46, 0x00, 0x02, 0xFF, 0x03, 0x0B, 0xFF, 0xFF, 0xFF, 0x03, 0x17},
    {0x08, 0x17, 0x23, 0x29, 0x81, 0x46, 0x01, 0xFF, 0xFF, 0x04, 0x09, 0xFF, 0xFF, 0xFF, 0x04, 0x18},
    {0x09, 0x18, 0x00, 0x00, 0x4A, 0x46, 0x00, 0x04, 0x01, 0xFF, 0x07, 0xFF, 0xFF, 0x01, 0xFF, 0x19},
    {0x09, 0x19, 0x05, 0x07, 0x4A, 0x46, 0x03, 0x05, 0x02, 0xFF, 0x07, 0xFF, 0xFF, 0x02, 0xFF, 0x1A},
    {0x09, 0x1A, 0x0F, 0x16, 0x4A, 0x46, 0x04, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x1B},
};  // 0x085AC5CC

// clang-format off
const u8 u8_ARRAY_085ac62c[21][4] = {
    {0x02, 0x27, 0x27, 0x00},
    {0x02, 0x1E, 0x1E, 0x00},
    {0x02, 0x14, 0x14, 0x00},
    {0x01, 0x29, 0x28, 0x00},
    {0x01, 0x1E, 0x1E, 0x00},
    {0x01, 0x16, 0x16, 0x00},
    {0x00, 0x36, 0x35, 0x00},
    {0x00, 0x2D, 0x2D, 0x00},
    {0x00, 0x20, 0x22, 0x00},
    {0x00, 0x11, 0x13, 0x00},
    {0x00, 0x07, 0x09, 0x00},
    {0x00, 0x1E, 0x0C, 0x00},
    {0x05, 0x26, 0x28, 0x00},
    {0x05, 0x11, 0x11, 0x00},
    {0x05, 0x0B, 0x0D, 0x00},
    {0x04, 0x23, 0x27, 0x00},
    {0x04, 0x20, 0x20, 0x00},
    {0x04, 0x1D, 0x19, 0x00},
    {0x03, 0x2B, 0x23, 0x00},
    {0x03, 0x20, 0x20, 0x00},
    {0x03, 0x15, 0x1D, 0x00},
};  // 0x085AC62C
// clang-format on

const u8 u8_ARRAY_085ac680[3][4] = {
    {0x11, 0x02, 0x11, 0x11},
    {0x05, 0x02, 0x14, 0x14},
    {0x05, 0x00, 0x0A, 0x0B},
};  // 0x085AC680

const u8 u8_ARRAY_085ac68c[13][16] = {
    {0x0A, 0x27, 0x08, 0x0B, 0x30, 0x30, 0x01, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x28},
    {0x0A, 0x26, 0x08, 0x0B, 0x30, 0x30, 0x02, 0x00, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x27},
    {0x0A, 0x25, 0x08, 0x0B, 0x30, 0x30, 0x03, 0x01, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x26},
    {0x0A, 0x24, 0x08, 0x0B, 0x30, 0x30, 0x04, 0x02, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x25},
    {0x0A, 0x23, 0x08, 0x09, 0x30, 0x30, 0x05, 0x03, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x24},
    {0x0A, 0x22, 0x0B, 0x0A, 0x30, 0x30, 0x06, 0x04, 0xFF, 0xFF, 0x03, 0x06, 0xFF, 0xFF, 0xFF, 0x23},
    {0x0B, 0x21, 0x0B, 0x0A, 0x30, 0x30, 0x07, 0x05, 0xFF, 0xFF, 0x03, 0xFF, 0x05, 0xFF, 0xFF, 0x22},
    {0x0B, 0x20, 0x01, 0x00, 0x38, 0x38, 0x08, 0x06, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x21},
    {0x0B, 0x1F, 0x0B, 0x0A, 0x3A, 0x3A, 0x09, 0x07, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x20},
    {0x0B, 0x1E, 0x0B, 0x0A, 0x3A, 0x3A, 0x0A, 0x08, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F},
    {0x0B, 0x1D, 0x0B, 0x0A, 0x3A, 0x3A, 0x0B, 0x09, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x1E},
    {0x0B, 0x1C, 0x0B, 0x08, 0x3A, 0x3A, 0x0C, 0x0A, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x1D},
    {0x0B, 0x1B, 0x06, 0x04, 0x32, 0x28, 0xFF, 0x0B, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x1C},
};  // 0x085AC68C

// clang-format off
const u8 u8_ARRAY_085ac75c[61][4] = {
    {0x00, 0x10, 0x0E, 0x00},
    {0x00, 0x30, 0x32, 0x00},
    {0x00, 0x36, 0x2C, 0x00},
    {0x01, 0x10, 0x0E, 0x00},
    {0x01, 0x0C, 0x14, 0x00},
    {0x01, 0x2C, 0x2A, 0x00},
    {0x01, 0x36, 0x2C, 0x00},
    {0x01, 0x30, 0x36, 0x00},
    {0x01, 0x23, 0x1D, 0x00},
    {0x02, 0x10, 0x0E, 0x00},
    {0x02, 0x30, 0x32, 0x00},
    {0x02, 0x20, 0x20, 0x00},
    {0x03, 0x10, 0x0E, 0x00},
    {0x03, 0x2E, 0x30, 0x00},
    {0x03, 0x3A, 0x3A, 0x00},
    {0x04, 0x10, 0x0E, 0x00},
    {0x04, 0x30, 0x32, 0x00},
    {0x04, 0x1F, 0x21, 0x00},
    {0x04, 0x25, 0x27, 0x00},
    {0x05, 0x21, 0x1D, 0x00},
    {0x05, 0x29, 0x23, 0x00},
    {0x05, 0x10, 0x0E, 0x00},
    {0x05, 0x0D, 0x05, 0x00},
    {0x05, 0x11, 0x09, 0x00},
    {0x05, 0x15, 0x0D, 0x00},
    {0x05, 0x19, 0x11, 0x00},
    {0x05, 0x17, 0x07, 0x00},
    {0x05, 0x30, 0x32, 0x00},
    {0x05, 0x39, 0x2F, 0x00},
    {0x05, 0x0B, 0x13, 0x00},
    {0x06, 0x14, 0x0A, 0x00},
    {0x06, 0x30, 0x32, 0x00},
    {0x06, 0x3A, 0x2C, 0x00},
    {0x06, 0x20, 0x1A, 0x00},
    {0x06, 0x26, 0x20, 0x00},
    {0x07, 0x26, 0x24, 0x00},
    {0x07, 0x42, 0x3E, 0x00},
    {0x07, 0x3A, 0x2E, 0x00},
    {0x07, 0x1C, 0x1E, 0x00},
    {0x08, 0x10, 0x0E, 0x00},
    {0x08, 0x30, 0x32, 0x00},
    {0x08, 0x1F, 0x1D, 0x00},
    {0x08, 0x23, 0x1F, 0x00},
    {0x08, 0x25, 0x23, 0x00},
    {0x09, 0x10, 0x10, 0x00},
    {0x09, 0x16, 0x0A, 0x00},
    {0x09, 0x30, 0x2E, 0x00},
    {0x09, 0x36, 0x2A, 0x00},
    {0x09, 0x1F, 0x1D, 0x00},
    {0x09, 0x25, 0x23, 0x00},
    {0x0A, 0x0E, 0x0C, 0x00},
    {0x0A, 0x30, 0x30, 0x00},
    {0x0A, 0x1C, 0x1A, 0x00},
    {0x0A, 0x21, 0x1F, 0x00},
    {0x0A, 0x26, 0x24, 0x00},
    {0x0A, 0x28, 0x18, 0x00},
    {0x0A, 0x33, 0x0D, 0x00},
    {0x0A, 0x3A, 0x3A, 0x00},
    {0x0B, 0x0F, 0x11, 0x00},
    {0x0B, 0x2F, 0x31, 0x00},
    {0x0C, 0x20, 0x20, 0x00},
};  // 0x085AC75C
// clang-format on

const u8 u8_ARRAY_085ac850[17][4] = {
    {0x02, 0x00, 0x1A, 0x17},
    {0x02, 0x01, 0x05, 0x06},
    {0x02, 0x05, 0x1C, 0x19},
    {0x12, 0x06, 0x11, 0x0D},
    {0x11, 0x07, 0x10, 0x0F},
    {0x11, 0x07, 0x1E, 0x1D},
    {0x11, 0x09, 0x0C, 0x0B},
    {0x02, 0x09, 0x0A, 0x07},
    {0x02, 0x09, 0x19, 0x16},
    {0x11, 0x0A, 0x0C, 0x0B},
    {0x11, 0x0A, 0x0E, 0x0D},
    {0x11, 0x0A, 0x12, 0x11},
    {0x05, 0x01, 0x08, 0x0B},
    {0x05, 0x05, 0x10, 0x0D},
    {0x05, 0x00, 0x19, 0x14},
    {0x05, 0x0A, 0x18, 0x17},
    {0x00, 0x00, 0x00, 0x00},
};  // 0x085AC850

const u8 u8_ARRAY_085ac894[6][16] = {
    {0x0C, 0x28, 0x1A, 0x1D, 0x45, 0x45, 0xFF, 0x01, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x29},
    {0x0C, 0x29, 0x08, 0x08, 0x46, 0x46, 0x00, 0x02, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x2A},
    {0x0C, 0x2A, 0x0A, 0x11, 0x46, 0x50, 0x01, 0x03, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x2B},
    {0x0C, 0x2B, 0x01, 0x0F, 0x46, 0x46, 0x02, 0x04, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x2C},
    {0x0C, 0x2C, 0x1C, 0x10, 0x5A, 0x46, 0x03, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x2D},
    {0x16, 0x2C, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x2E},
};  // 0x085AC894

// clang-format off
const u8 u8_ARRAY_085ac8f4[62][4] = {
    {0x00, 0x21, 0x1F, 0x00},
    {0x01, 0x45, 0x47, 0x00},
    {0x01, 0x41, 0x4D, 0x00},
    {0x01, 0x4F, 0x3F, 0x00},
    {0x01, 0x3D, 0x3F, 0x00},
    {0x01, 0x36, 0x36, 0x00},
    {0x01, 0x3E, 0x2C, 0x00},
    {0x01, 0x4C, 0x2A, 0x00},
    {0x01, 0x56, 0x38, 0x00},
    {0x01, 0x5C, 0x46, 0x00},
    {0x01, 0x50, 0x52, 0x00},
    {0x01, 0x44, 0x5A, 0x00},
    {0x01, 0x32, 0x54, 0x00},
    {0x01, 0x28, 0x48, 0x00},
    {0x01, 0x1F, 0x3F, 0x00},
    {0x01, 0x28, 0x38, 0x00},
    {0x01, 0x2D, 0x2F, 0x00},
    {0x05, 0x2C, 0x48, 0x00},
    {0x02, 0x3C, 0x42, 0x00},
    {0x02, 0x41, 0x39, 0x00},
    {0x02, 0x48, 0x4C, 0x00},
    {0x02, 0x4E, 0x44, 0x00},
    {0x02, 0x5A, 0x52, 0x00},
    {0x02, 0x53, 0x59, 0x00},
    {0x02, 0x47, 0x5B, 0x00},
    {0x02, 0x3D, 0x52, 0x00},
    {0x02, 0x34, 0x4A, 0x00},
    {0x02, 0x2A, 0x42, 0x00},
    {0x02, 0x33, 0x39, 0x00},
    {0x02, 0x2B, 0x33, 0x00},
    {0x02, 0x3B, 0x2F, 0x00},
    {0x02, 0x46, 0x26, 0x00},
    {0x02, 0x4E, 0x30, 0x00},
    {0x05, 0x2C, 0x48, 0x00},
    {0x03, 0x55, 0x39, 0x00},
    {0x03, 0x5B, 0x3F, 0x00},
    {0x03, 0x4C, 0x44, 0x00},
    {0x03, 0x42, 0x4E, 0x00},
    {0x03, 0x40, 0x38, 0x00},
    {0x03, 0x2C, 0x34, 0x00},
    {0x03, 0x36, 0x2A, 0x00},
    {0x03, 0x3F, 0x23, 0x00},
    {0x03, 0x51, 0x2B, 0x00},
    {0x03, 0x2B, 0x47, 0x00},
    {0x03, 0x2C, 0x54, 0x00},
    {0x03, 0x34, 0x5E, 0x00},
    {0x04, 0x27, 0x3D, 0x00},
    {0x04, 0x30, 0x34, 0x00},
    {0x04, 0x36, 0x44, 0x00},
    {0x04, 0x40, 0x24, 0x00},
    {0x04, 0x4C, 0x2A, 0x00},
    {0x04, 0x56, 0x34, 0x00},
    {0x04, 0x43, 0x33, 0x00},
    {0x04, 0x4C, 0x3E, 0x00},
    {0x04, 0x56, 0x4A, 0x00},
    {0x04, 0x5E, 0x44, 0x00},
    {0x04, 0x42, 0x4E, 0x00},
    {0x04, 0x4A, 0x5A, 0x00},
    {0x04, 0x39, 0x56, 0x00},
    {0x04, 0x31, 0x53, 0x00},
    {0x04, 0x2C, 0x48, 0x00},
    {0x05, 0x2C, 0x48, 0x00},
};  // 0x085AC8F4
// clang-format on

const u8 u8_ARRAY_085ac9ec[12][4] = {
    {0x01, 0x01, 0x21, 0x25},
    {0x01, 0x01, 0x25, 0x21},
    {0x11, 0x01, 0x11, 0x22},
    {0x11, 0x02, 0x17, 0x22},
    {0x01, 0x02, 0x24, 0x1A},
    {0x11, 0x03, 0x2C, 0x1E},
    {0x11, 0x03, 0x24, 0x1F},
    {0x11, 0x03, 0x21, 0x22},
    {0x01, 0x03, 0x18, 0x15},
    {0x01, 0x03, 0x17, 0x20},
    {0x01, 0x04, 0x1C, 0x15},
    {0x01, 0x04, 0x23, 0x16},
};  // 0x085AC9EC

const u8 u8_ARRAY_085aca1c[5][16] = {
    {0x0E, 0x00, 0x1C, 0x05, 0x60, 0x40, 0xFF, 0x01, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x2F},
    {0x0E, 0x01, 0x1C, 0x06, 0x60, 0x40, 0x00, 0x02, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x30},
    {0x0E, 0x02, 0x16, 0x00, 0x60, 0x40, 0x01, 0x03, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x31},
    {0x0E, 0x03, 0x00, 0x15, 0x60, 0x40, 0x02, 0x04, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x32},
    {0x0E, 0x04, 0x1E, 0x1B, 0x60, 0x40, 0x03, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x33},
};  // 0x085ACA1C

// clang-format off
const u8 u8_ARRAY_085aca6c[44][4] = {
    {0x00, 0x16, 0x16, 0x00},
    {0x00, 0x0F, 0x19, 0x00},
    {0x00, 0x2B, 0x1D, 0x00},
    {0x00, 0x2F, 0x27, 0x00},
    {0x00, 0x28, 0x26, 0x00},
    {0x01, 0x1A, 0x18, 0x00},
    {0x01, 0x15, 0x1D, 0x00},
    {0x01, 0x12, 0x22, 0x00},
    {0x01, 0x0B, 0x1D, 0x00},
    {0x01, 0x0E, 0x20, 0x00},
    {0x01, 0x2B, 0x1B, 0x00},
    {0x01, 0x34, 0x24, 0x00},
    {0x01, 0x31, 0x2D, 0x00},
    {0x01, 0x27, 0x25, 0x00},
    {0x02, 0x6A, 0x54, 0x00},
    {0x02, 0x61, 0x47, 0x00},
    {0x02, 0x55, 0x3F, 0x00},
    {0x02, 0x4C, 0x34, 0x00},
    {0x02, 0x3F, 0x3F, 0x00},
    {0x02, 0x40, 0x30, 0x00},
    {0x02, 0x36, 0x26, 0x00},
    {0x02, 0x33, 0x31, 0x00},
    {0x02, 0x2F, 0x39, 0x00},
    {0x02, 0x2C, 0x36, 0x00},
    {0x02, 0x2A, 0x28, 0x00},
    {0x02, 0x27, 0x31, 0x00},
    {0x02, 0x1E, 0x30, 0x00},
    {0x02, 0x18, 0x3A, 0x00},
    {0x02, 0x17, 0x29, 0x00},
    {0x02, 0x10, 0x30, 0x00},
    {0x03, 0x3F, 0x10, 0x00},
    {0x03, 0x3A, 0x20, 0x00},
    {0x03, 0x30, 0x22, 0x00},
    {0x03, 0x37, 0x31, 0x00},
    {0x03, 0x28, 0x2E, 0x00},
    {0x03, 0x21, 0x27, 0x00},
    {0x03, 0x44, 0x1E, 0x00},
    {0x03, 0x4B, 0x23, 0x00},
    {0x03, 0x51, 0x2D, 0x00},
    {0x03, 0x54, 0x22, 0x00},
    {0x03, 0x5F, 0x2F, 0x00},
    {0x04, 0x1F, 0x21, 0x00},
    {0x04, 0x23, 0x25, 0x00},
    {0x04, 0x1B, 0x1D, 0x00},
};  // 0x085ACA6C
// clang-format on

const u8 u8_ARRAY_085acb1c[6][4] = {
    {0x05, 0x02, 0x37, 0x27},
    {0x05, 0x03, 0x10, 0x13},
    {0x12, 0x01, 0x06, 0x0F},
    {0x11, 0x03, 0x23, 0x10},
    {0x01, 0x03, 0x23, 0x0D},
    {0x00, 0x00, 0x00, 0x00},
};  // 0x085ACB1C

const u8 u8_ARRAY_085acb34[1][16] = {
    {0x16, 0x2C, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F},
};  // 0x085ACB34

const u8 u8_ARRAY_085acb44[1][4] = {
    {0x00, 0x2C, 0x48, 0x00},
};  // 0x085ACB44

const u8 u8_ARRAY_085acb48[3][16] = {
    {0x10, 0x05, 0x0B, 0x07, 0x3C, 0x38, 0xFF, 0x01, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x34},
    {0x10, 0x06, 0x00, 0x00, 0x3C, 0x38, 0x00, 0x02, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x35},
    {0x10, 0x07, 0x25, 0x0D, 0x3C, 0x38, 0x01, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x36},
};  // 0x085ACB48

// clang-format off
const u8 u8_ARRAY_085acb78[35][4] = {
    {0x00, 0x1C, 0x17, 0x00},
    {0x00, 0x15, 0x11, 0x00},
    {0x00, 0x09, 0x1E, 0x00},
    {0x00, 0x17, 0x26, 0x00},
    {0x00, 0x18, 0x1E, 0x00},
    {0x00, 0x1C, 0x22, 0x00},
    {0x00, 0x27, 0x23, 0x00},
    {0x00, 0x2F, 0x2B, 0x00},
    {0x00, 0x35, 0x33, 0x00},
    {0x01, 0x1F, 0x53, 0x00},
    {0x01, 0x28, 0x62, 0x00},
    {0x01, 0x30, 0x5A, 0x00},
    {0x01, 0x38, 0x62, 0x00},
    {0x01, 0x2C, 0x49, 0x00},
    {0x01, 0x3C, 0x58, 0x00},
    {0x01, 0x45, 0x53, 0x00},
    {0x01, 0x48, 0x64, 0x00},
    {0x01, 0x4D, 0x5B, 0x00},
    {0x01, 0x57, 0x51, 0x00},
    {0x01, 0x4F, 0x49, 0x00},
    {0x01, 0x61, 0x37, 0x00},
    {0x01, 0x5F, 0x4B, 0x00},
    {0x01, 0x45, 0x3F, 0x00},
    {0x01, 0x3B, 0x2F, 0x00},
    {0x01, 0x32, 0x34, 0x00},
    {0x01, 0x2A, 0x30, 0x00},
    {0x01, 0x25, 0x29, 0x00},
    {0x01, 0x2E, 0x1C, 0x00},
    {0x01, 0x33, 0x27, 0x00},
    {0x02, 0x1B, 0x15, 0x00},
    {0x02, 0x15, 0x19, 0x00},
    {0x02, 0x1E, 0x20, 0x00},
    {0x02, 0x1D, 0x29, 0x00},
    {0x02, 0x23, 0x33, 0x00},
    {0x02, 0x15, 0x31, 0x00},
};  // 0x085ACB78
// clang-format on

const u8 u8_ARRAY_085acc04[3][4] = {
    {0x05, 0x01, 0x0D, 0x2B},
    {0x05, 0x00, 0x1B, 0x18},
    {0x11, 0x01, 0x25, 0x22},
};  // 0x085ACC04

const u8 u8_ARRAY_085acc10[2][16] = {
    {0x11, 0x09, 0x00, 0x00, 0x40, 0x40, 0x01, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x38},
    {0x11, 0x08, 0x00, 0x00, 0x40, 0x40, 0xFF, 0x00, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x37},
};  // 0x085ACC10

// clang-format off
const u8 u8_ARRAY_085acc30[20][4] = {
    {0x00, 0x13, 0x62, 0x00},
    {0x00, 0x1E, 0x60, 0x00},
    {0x00, 0x2A, 0x58, 0x00},
    {0x00, 0x36, 0x4A, 0x00},
    {0x00, 0x41, 0x3F, 0x00},
    {0x00, 0x4B, 0x47, 0x00},
    {0x00, 0x4F, 0x33, 0x00},
    {0x00, 0x57, 0x3D, 0x00},
    {0x00, 0x5B, 0x25, 0x00},
    {0x00, 0x66, 0x20, 0x00},
    {0x00, 0x6D, 0x27, 0x00},
    {0x01, 0x0C, 0x34, 0x00},
    {0x01, 0x13, 0x2B, 0x00},
    {0x01, 0x1F, 0x31, 0x00},
    {0x01, 0x0E, 0x20, 0x00},
    {0x01, 0x1B, 0x23, 0x00},
    {0x01, 0x22, 0x1C, 0x00},
    {0x01, 0x29, 0x17, 0x00},
    {0x01, 0x2F, 0x0F, 0x00},
    {0x01, 0x37, 0x07, 0x00},
};  // 0x085ACC30
// clang-format on

const u8 u8_ARRAY_085acc80[4][16] = {
    {0x12, 0x0A, 0x06, 0x0A, 0x3C, 0x38, 0xFF, 0x01, 0xFF, 0xFF, 0x02, 0xFF, 0xFF, 0xFF, 0xFF, 0x39},
    {0x12, 0x0B, 0x0F, 0x08, 0x3C, 0x38, 0x00, 0x02, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x3A},
    {0x12, 0x0C, 0x00, 0x00, 0x3C, 0x38, 0x01, 0x03, 0xFF, 0xFF, 0x03, 0xFF, 0xFF, 0xFF, 0xFF, 0x3B},
    {0x12, 0x0D, 0x24, 0x06, 0x3C, 0x38, 0x02, 0xFF, 0xFF, 0xFF, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0x3C},
};  // 0x085ACC80

// clang-format off
const u8 u8_ARRAY_085accc0[47][4] = {
    {0x00, 0x4C, 0x18, 0x00},
    {0x00, 0x46, 0x10, 0x00},
    {0x00, 0x41, 0x18, 0x00},
    {0x00, 0x3A, 0x0C, 0x00},
    {0x00, 0x32, 0x0E, 0x00},
    {0x00, 0x29, 0x14, 0x00},
    {0x00, 0x1F, 0x1F, 0x00},
    {0x00, 0x38, 0x16, 0x00},
    {0x00, 0x39, 0x21, 0x00},
    {0x00, 0x27, 0x25, 0x00},
    {0x00, 0x1B, 0x2F, 0x00},
    {0x01, 0x2F, 0x0F, 0x00},
    {0x01, 0x27, 0x15, 0x00},
    {0x01, 0x1F, 0x0D, 0x00},
    {0x01, 0x2F, 0x1D, 0x00},
    {0x01, 0x25, 0x27, 0x00},
    {0x01, 0x1B, 0x33, 0x00},
    {0x01, 0x21, 0x1D, 0x00},
    {0x01, 0x18, 0x16, 0x00},
    {0x01, 0x0D, 0x23, 0x00},
    {0x01, 0x16, 0x1D, 0x00},
    {0x01, 0x19, 0x23, 0x00},
    {0x01, 0x1B, 0x29, 0x00},
    {0x01, 0x13, 0x2B, 0x00},
    {0x01, 0x3A, 0x1C, 0x00},
    {0x02, 0x16, 0x5A, 0x00},
    {0x02, 0x23, 0x4B, 0x00},
    {0x02, 0x2C, 0x42, 0x00},
    {0x02, 0x39, 0x45, 0x00},
    {0x02, 0x34, 0x3A, 0x00},
    {0x02, 0x2C, 0x32, 0x00},
    {0x02, 0x3C, 0x32, 0x00},
    {0x02, 0x41, 0x2D, 0x00},
    {0x02, 0x45, 0x36, 0x00},
    {0x02, 0x38, 0x29, 0x00},
    {0x02, 0x4C, 0x2C, 0x00},
    {0x02, 0x52, 0x24, 0x00},
    {0x02, 0x45, 0x25, 0x00},
    {0x02, 0x41, 0x21, 0x00},
    {0x02, 0x49, 0x1D, 0x00},
    {0x02, 0x57, 0x33, 0x00},
    {0x02, 0x60, 0x3A, 0x00},
    {0x02, 0x68, 0x42, 0x00},
    {0x02, 0x6C, 0x2E, 0x00},
    {0x02, 0x60, 0x28, 0x00},
    {0x03, 0x1A, 0x1A, 0x00},
    {0x03, 0x24, 0x22, 0x00},
};  // 0x085ACCC0
// clang-format on

const u8 u8_ARRAY_085acd7c[10][4] = {
    {0x05, 0x02, 0x08, 0x2F},
    {0x05, 0x03, 0x13, 0x0F},
    {0x01, 0x02, 0x20, 0x14},
    {0x01, 0x02, 0x22, 0x16},
    {0x01, 0x02, 0x24, 0x10},
    {0x11, 0x01, 0x0E, 0x0C},
    {0x11, 0x01, 0x1A, 0x0E},
    {0x01, 0x00, 0x1E, 0x08},
    {0x01, 0x00, 0x1E, 0x0C},
    {0x01, 0x00, 0x20, 0x08},
};  // 0x085ACD7C

const u8 u8_ARRAY_085acda4[1][16] = {
    {0x13, 0x0E, 0x00, 0x00, 0x47, 0x40, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x3D},
};  // 0x085ACDA4

// clang-format off
const u8 u8_ARRAY_085acdb4[25][4] = {
    {0x00, 0x30, 0x50, 0x00},
    {0x00, 0x2E, 0x3E, 0x00},
    {0x00, 0x34, 0x38, 0x00},
    {0x00, 0x3A, 0x32, 0x00},
    {0x00, 0x40, 0x2C, 0x00},
    {0x00, 0x46, 0x26, 0x00},
    {0x00, 0x4B, 0x21, 0x00},
    {0x00, 0x34, 0x44, 0x00},
    {0x00, 0x3A, 0x3E, 0x00},
    {0x00, 0x20, 0x38, 0x00},
    {0x00, 0x46, 0x32, 0x00},
    {0x00, 0x4C, 0x2C, 0x00},
    {0x00, 0x51, 0x27, 0x00},
    {0x00, 0x3A, 0x4A, 0x00},
    {0x00, 0x40, 0x44, 0x00},
    {0x00, 0x46, 0x3E, 0x00},
    {0x00, 0x4C, 0x38, 0x00},
    {0x00, 0x52, 0x32, 0x00},
    {0x00, 0x57, 0x2D, 0x00},
    {0x00, 0x40, 0x50, 0x00},
    {0x00, 0x46, 0x4A, 0x00},
    {0x00, 0x4C, 0x44, 0x00},
    {0x00, 0x52, 0x3E, 0x00},
    {0x00, 0x58, 0x38, 0x00},
    {0x00, 0x5D, 0x33, 0x00},
};  // 0x085ACDB4
// clang-format on

const u8 u8_ARRAY_085ace18[1][16] = {
    {0x16, 0x2C, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x3E},
};  // 0x085ACE18

const u8 u8_ARRAY_085ace28[1][4] = {
    {0x00, 0x2C, 0x48, 0x00},
};  // 0x085ACE28

const u8 u8_ARRAY_085ace2c[1][16] = {
    {0x16, 0x2C, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x59},
};  // 0x085ACE2C

const u8 u8_ARRAY_085ace3c[7][4] = {
    {0x00, 0x00, 0x00, 0x40},
    {0x3E, 0x1E, 0x00, 0x41},
    {0x52, 0x5E, 0x00, 0x42},
    {0x62, 0x42, 0x00, 0x43},
    {0x22, 0x2E, 0x00, 0x44},
    {0x64, 0x1C, 0x00, 0x45},
    {0x64, 0x1C, 0x00, 0x46},
};  // 0x085ACE3C

const u8 u8_ARRAY_085ace58[18][4] = {
    {0x17, 0x59, 0x00, 0x47},
    {0x27, 0x69, 0x00, 0x48},
    {0x43, 0x25, 0x00, 0x49},
    {0x49, 0x65, 0x00, 0x4A},
    {0x5B, 0x3D, 0x00, 0x4B},
    {0x1B, 0x37, 0x00, 0x4C},
    {0x65, 0x2B, 0x00, 0x4D},
    {0x65, 0x2B, 0x00, 0x4E},
    {0x2A, 0x56, 0x00, 0x4F},
    {0x38, 0x2C, 0x00, 0x50},
    {0x44, 0x58, 0x00, 0x51},
    {0x54, 0x48, 0x00, 0x52},
    {0x28, 0x3C, 0x00, 0x53},
    {0x52, 0x2E, 0x00, 0x54},
    {0x5C, 0x24, 0x00, 0x55},
    {0x37, 0x49, 0x00, 0x56},
    {0x3E, 0x42, 0x00, 0x57},
    {0x45, 0x3B, 0x00, 0x58},
};  // 0x085ACE58

const u8 u8_ARRAY_085acea0[10][4] = {
    {0x1A, 0x2A, 0x00, 0x0F},
    {0x14, 0x24, 0x00, 0x10},
    {0x1E, 0x26, 0x01, 0x11},
    {0x18, 0x20, 0x01, 0x12},
    {0x25, 0x27, 0x00, 0x13},
    {0x17, 0x19, 0x00, 0x14},
    {0x24, 0x20, 0x01, 0x15},
    {0x28, 0x1C, 0x00, 0x16},
    {0x24, 0x1A, 0x00, 0x17},
    {0x22, 0x16, 0x00, 0x18},
};  // 0x085ACEA0

// FUN_0808fc14 / FUN_08091598 が引く
const u8 (*const PTR_ARRAY_085acec8[15])[16] = {
    u8_ARRAY_085ac084,
    u8_ARRAY_085ac0d8,
    u8_ARRAY_085ac210,
    u8_ARRAY_085ac390,
    u8_ARRAY_085ac5cc,
    u8_ARRAY_085ac68c,
    u8_ARRAY_085ac894,
    u8_ARRAY_085aca1c,
    u8_ARRAY_085acb34,
    u8_ARRAY_085acb48,
    u8_ARRAY_085acc10,
    u8_ARRAY_085acc80,
    u8_ARRAY_085acda4,
    u8_ARRAY_085ace18,
    u8_ARRAY_085ace2c,
};  // 0x085ACEC8

// FUN_0808fc14 / FUN_08091598 が引く
const u8 (*const PTR_ARRAY_085acf04[15])[4] = {
    u8_ARRAY_085ac0a4,
    u8_ARRAY_085ac138,
    u8_ARRAY_085ac280,
    u8_ARRAY_085ac400,
    u8_ARRAY_085ac62c,
    u8_ARRAY_085ac75c,
    u8_ARRAY_085ac8f4,
    u8_ARRAY_085aca6c,
    u8_ARRAY_085acb44,
    u8_ARRAY_085acb78,
    u8_ARRAY_085acc30,
    u8_ARRAY_085accc0,
    u8_ARRAY_085acdb4,
    u8_ARRAY_085ace28,
    u8_ARRAY_085ace3c,
};  // 0x085ACF04

// FUN_08091598 が引く, 4件だけ16バイトレコードの配列を指している
const u8 (*const PTR_ARRAY_085acf40[15])[4] = {
    NULL,
    u8_ARRAY_085ac1d8,
    u8_ARRAY_085ac370,
    u8_ARRAY_085ac5a0,
    u8_ARRAY_085ac680,
    u8_ARRAY_085ac850,
    u8_ARRAY_085ac9ec,
    u8_ARRAY_085acb1c,
    (void*)u8_ARRAY_085acb48,
    u8_ARRAY_085acc04,
    (void*)u8_ARRAY_085acc80,
    u8_ARRAY_085acd7c,
    (void*)u8_ARRAY_085ace18,
    (void*)u8_ARRAY_085ace2c,
    u8_ARRAY_085ace3c,
};  // 0x085ACF40

void FUN_080917e4(struct EntityCC28* p, s32 param_2, s32 param_3);
void FUN_08091860(struct EntityCC28* p, s32 param_2, s32 param_3);
void FUN_0809193c(struct EntityCC28* p, u32 param_2);
void FUN_08091a34(struct EntityCC28* p, s32 param_2, u8 param_3);
void FUN_080919a4(struct EntityCC28* p, u16 param_2, s16 param_3);
void FUN_08091adc(struct EntityCC28* p, s8 param_2, u16 param_3);
void FUN_08091b40(struct EntityCC28* p, u8 val);
void FUN_08091b68(struct EntityCC28* p);
void FUN_08091bbc(struct EntityCC28* p);
void FUN_08091be0(struct EntityCC28* p);
void FUN_08091c50(struct EntityCC28* p, u8 val);
void FUN_08091c78(void);
void FUN_08091c90(void);

// ItemEffectType で引くアイテム効果の処理表, FUN_08091e64 が (p, arg2, arg3) で呼ぶ
void (*const gItemEffectHandlers[15])(struct EntityCC28*, s32, s32) = {
    NULL,
    FUN_080917e4,
    FUN_08091860,
    (void*)FUN_0809193c,
    (void*)FUN_08091a34,
    (void*)FUN_080919a4,
    (void*)FUN_08091adc,
    (void*)FUN_08091b40,
    (void*)FUN_08091b68,
    (void*)FUN_08091bbc,
    (void*)FUN_08091be0,
    NULL,
    (void*)FUN_08091c50,
    (void*)FUN_08091c78,
    (void*)FUN_08091c90,
};  // 0x085ACF7C

// 推測: 12バイト×3組, どの組も `0xAA 0x91 0xB8 0x01` を含む, charmap.txt の範囲外なので文字コードは不明
const u8 u8_ARRAY_085acfb8[3][12] = {
    {0xB4, 0x91, 0xAF, 0xA9, 0xB3, 0x01, 0xAA, 0x91, 0xB8, 0x01, 0x01, 0x01},
    {0xB7, 0xA9, 0xB0, 0xB2, 0xAD, 0xB3, 0xAC, 0x01, 0xAA, 0x91, 0xB8, 0x01},
    {0xAB, 0xA9, 0xB3, 0xAE, 0x01, 0xAA, 0x91, 0xB8, 0x01, 0x01, 0x01, 0x01},
};  // 0x085ACFB8

void FUN_08091598(struct EntityCC28* p);
void FUN_080948ac(struct EntityCC28* p);
void FUN_080949b0(struct EntityCC28* p);
void FUN_0809651c(struct EntityCC28* p);
void FUN_080979b8(struct EntityCC28* p);
void FUN_080989c4(struct EntityCC28* p);
void FUN_08099968(struct EntityCC28* p);
void FUN_0809a084(struct EntityCC28* p);
void FUN_0809a274(struct EntityCC28* p);
void FUN_0809a5d8(struct EntityCC28* p);

// EntityCC28.state2 で引く状態関数表, FUN_0809a67c が引く
void (*const sEntityCC28State2Fns[10])(struct EntityCC28*) = {
    FUN_08091598,
    FUN_080948ac,
    FUN_080949b0,
    FUN_0809651c,
    FUN_080979b8,
    FUN_080989c4,
    FUN_08099968,
    FUN_0809a084,
    FUN_0809a274,
    FUN_0809a5d8,
};  // 0x085ACFDC

// FUN_08099650 ほかが引く
const u16 u16_ARRAY_085ad004[8] = {100, 100, 112, 112, 128, 100, 112, 112};  // 0x085AD004
