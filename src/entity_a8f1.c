#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "particle.h"
#include "sprite_aux.h"

typedef struct {
  Particle ptcl;  // 0x00
  u8 unk_28[8];   // 0x28, まだ未解析
} EntityA8F1Ptcl;
static_assert(sizeof(EntityA8F1Ptcl) == 48);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_9
  MsgQueue mq;              // 0x018, targetClass 10
  u16 unk_4c;               // 0x04C, まだ未解析
  u16 spriteParam;          // 0x04E, sprite と sprite2 の +0x10 に入れる値
  AuxSprite sprite;         // 0x050, flags に 0x200 が立つ
  AuxSpriteGfx gfx;         // 0x07C, SPRITE_MAGIC_CIRCLE
  Vec3 pos;                 // 0x098, '.p', y はタイルの attr から計算し直す
  AuxSprite sprite2;        // 0x0A0
  AuxSpriteGfx gfx2;        // 0x0CC, SPRITE_MAGIC_CIRCLE
  AuxSprite subSprites[3];  // 0x0E8
  AuxSpriteGfx subGfx[3];   // 0x16C, SPRITE_MAGIC_CIRCLE, パレットは plttID + 2
  u16 unk_1c0;              // 0x1C0, '.s' があるとき 7
  s8 unk_1c2;               // 0x1C2, '.s' の値
  u8 unk_1c3;               // 0x1C3, まだ未解析
  u16 plttID;               // 0x1C4
  u16 unk_1c6;              // 0x1C6, '.s' があるとき 8, 無いとき 0
  EntityA8F1Ptcl ptcls[8];  // 0x1C8
  u8 unk_348[32];           // 0x348, まだ未解析
  u8 unk_368;               // 0x368, '.s' があるとき 0x18, 無いとき 0
  s8 unk_369;               // 0x369, '.a'
  u16 unk_36a;              // 0x36A, '.s' があるとき 10, 無いとき 0
  s32 unk_36c;              // 0x36C, '.C'
  s32 unk_370;              // 0x370, '.i'
  u8 unk_374[4];            // 0x374, まだ未解析
  s32 unk_378;              // 0x378, '.n'
  s32 unk_37c;              // 0x37C, '.c'
  u16 unk_380;              // 0x380, '.s' があるとき 1
  u8 unk_382[6];            // 0x382, まだ未解析
} EntityA8F1;
static_assert(sizeof(EntityA8F1) == 904);

NAKED void FUN_080a251c(Particle* param_1) { INCFUNC("asm/func/FUN_080a251c.inc"); }

NAKED void FUN_080a25c8(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/FUN_080a25c8.inc"); }

NAKED void FUN_080a2678(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/FUN_080a2678.inc"); }

NAKED s32 FUN_080a271c(s32 param_1) { INCFUNC("asm/func/FUN_080a271c.inc"); }

NAKED s32 FUN_080a2778(s32 param_1) { INCFUNC("asm/func/FUN_080a2778.inc"); }

NAKED void FUN_080a2804(s32 param_1) { INCFUNC("asm/func/FUN_080a2804.inc"); }

NAKED void FUN_080a2a14(s32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_080a2a14.inc"); }

NAKED void FUN_080a2a2c(s32 param_1) { INCFUNC("asm/func/FUN_080a2a2c.inc"); }

NAKED void FUN_080a2a4c(s32 param_1) { INCFUNC("asm/func/FUN_080a2a4c.inc"); }

NAKED void FUN_080a2b30(s32 param_1) { INCFUNC("asm/func/FUN_080a2b30.inc"); }

NAKED void FUN_080a2b78(s32 param_1) { INCFUNC("asm/func/FUN_080a2b78.inc"); }

NAKED void FUN_080a2bdc(s32 param_1) { INCFUNC("asm/func/FUN_080a2bdc.inc"); }

NAKED void FUN_080a2c2c(s32 param_1) { INCFUNC("asm/func/FUN_080a2c2c.inc"); }

NAKED void FUN_080a2c58(s32 param_1) { INCFUNC("asm/func/FUN_080a2c58.inc"); }

NAKED void FUN_080a2cb0(s32 param_1) { INCFUNC("asm/func/FUN_080a2cb0.inc"); }

NAKED void FUN_080a2d18(s32 param_1) { INCFUNC("asm/func/FUN_080a2d18.inc"); }

NAKED void FUN_080a2e20(s32 param_1) { INCFUNC("asm/func/FUN_080a2e20.inc"); }

NAKED void FUN_080a3004(s32 param_1) { INCFUNC("asm/func/FUN_080a3004.inc"); }

NAKED void FUN_080a30bc(s32 param_1) { INCFUNC("asm/func/FUN_080a30bc.inc"); }

NAKED void FUN_080a310c(s32 param_1) { INCFUNC("asm/func/FUN_080a310c.inc"); }

NAKED void FUN_080a3138(s32 param_1) { INCFUNC("asm/func/FUN_080a3138.inc"); }

NAKED void FUN_080a31dc(s32 param_1) { INCFUNC("asm/func/FUN_080a31dc.inc"); }

NAKED void FUN_080a3208(s32 param_1) { INCFUNC("asm/func/FUN_080a3208.inc"); }

NAKED void FUN_080a3278(s32 param_1) { INCFUNC("asm/func/FUN_080a3278.inc"); }

NAKED void FUN_080a32a4(s32 param_1) { INCFUNC("asm/func/FUN_080a32a4.inc"); }

NAKED void FUN_080a3340(unknown* param_1) { INCFUNC("asm/func/FUN_080a3340.inc"); }

NAKED void FUN_080a3448(s32 param_1) { INCFUNC("asm/func/FUN_080a3448.inc"); }

NAKED s32 EntityA8F1_Update(EntityA8F1* p) { INCFUNC("asm/func/EntityA8F1_Update.inc"); }

NAKED s32 EntityA8F1_Destroy(EntityA8F1* p) { INCFUNC("asm/func/EntityA8F1_Destroy.inc"); }

NAKED void FUN_080a3568(s32 param_1) { INCFUNC("asm/func/FUN_080a3568.inc"); }

NAKED s32 EntityA8F1_Init(EntityA8F1* p, u32 id) { INCFUNC("asm/func/EntityA8F1_Init.inc"); }

NAKED EntityA8F1* EntityA8F1_Create(u32 id, u32 param_2) { INCFUNC("asm/func/EntityA8F1_Create.inc"); }
