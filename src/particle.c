#include "particle.h"

#include "global.h"
#include "sprite.h"
#include "video.h"

s32 Video_AddParticleIntoDrawList(Particle* p, s32 idx);
void Video_RemoveParticleFromDrawList(Particle* p, s32 idx);

// Particle を ParticleGroup の先頭フレームで初期化し、描画リストに繋ぐ
void FUN_0822d9f0(Particle* p, ParticleGroup* g, SpriteFlags flags) {
  u32 mask;
  s32 idx;

  if (!p->active) {
    p->flags = flags;
    p->oamAttr01 = 0;
    p->priority = 2;
    p->offsetZ = 0;
    p->rotation = 0;
    p->scaleX = 0x40, p->scaleY = 0x40;
    Particle_SetOffset(p, 0, 0);
    FUN_0822dafc(p, g, 0);
    p->plttSlot = FUN_0822d12c(g->plttID, &gObjPlttData[g->plttID * 16]);
    mask = SPRFLAG_DRAWLIST;
    idx = (u32)(0 - (flags & mask)) >> 31;
    p->prev = NULL, p->next = NULL;
    Video_AddParticleIntoDrawList(p, idx);
  }
}

// 描画リストに繋がれていなければ、flags の bit7 で選んだリストに Particle を繋ぐ
void FUN_0822da50(Particle* p, SpriteFlags flags) {
  if (!p->active) {
    u32 mask = SPRFLAG_DRAWLIST;
    Video_AddParticleIntoDrawList(p, (flags & mask) != 0);
  }
}

// Particle を ParticleGroup の先頭フレームで初期化する (描画リストには繋がない)
void FUN_0822da70(Particle* p, ParticleGroup* g, SpriteFlags flags) {
  if (!p->active) {
    p->flags = flags;
    p->oamAttr01 = 0;
    p->priority = 1;
    p->offsetZ = 0;
    Particle_SetOffset(p, -8, -8);
    FUN_0822dafc(p, g, 0);
    p->plttSlot = FUN_0822d12c(g->plttID, &gObjPlttData[g->plttID * 16]);
    p->prev = NULL, p->next = NULL;
  }
}

// 描画リストに繋がれていれば Particle を外す
void Particle_Remove(Particle* p) {
  if (p->active) {
    Video_RemoveParticleFromDrawList(p, p->listIdx);
  }
}

void Particle_SetOffset(Particle* p, s32 offsetX, s32 offsetY) {
  p->offsetX = offsetX;
  p->offsetY = offsetY;
}

// パーティクルに OBJ パレット plttID を割り当て、確保されたパレットスロット番号を記録する
void FUN_0822dadc(Particle* p, s32 plttID) { p->plttSlot = FUN_0822d12c(plttID, &gObjPlttData[plttID * 16]); }

// ParticleGroup の形状からパーティクルのサイズ・OAM 属性・タイル番号(val 番目のフレーム)を設定する
void FUN_0822dafc(Particle* p, ParticleGroup* g, u32 val) {
  p->spriteWidth = gSpriteSizeTable[g->shape];
  p->spriteHeight = gSpriteSizeTable[g->shape] >> 8;
  p->oamAttr01 = ((g->shape & 3) << 14) | ((g->shape & 0xC) << 28);
  if (g->flags & PGFLAG_BPP8) p->oamAttr01 |= OAM0_8BPP;
  p->tileNum = val * ((p->spriteWidth >> 3) * (p->spriteHeight >> 3)) + g->tile;
}

NAKED void FUN_0822db5c(void) { INCFUNC("asm/func/FUN_0822db5c.inc"); }

NAKED void FUN_0822de64(void) { INCFUNC("asm/func/FUN_0822de64.inc"); }

NAKED void FUN_0822e110(void) { INCFUNC("asm/func/FUN_0822e110.inc"); }

NAKED void FUN_0822e424(void) { INCFUNC("asm/func/FUN_0822e424.inc"); }

void nop_0822e738(void) {}
