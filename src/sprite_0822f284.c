#include "global.h"
#include "sprite.h"

extern rgb555* gObjPlttData;
extern u16 u16_030044b8;

// spriteset ファイルのヘッダをコピーし、各オフセットをファイル先頭からのポインタに変換する
s32 OpenSpriteSetFile(SpriteSet* data, spriteset_header* f) {
  *data = *(SpriteSet*)f;
  data->sprites = (Metasprite*)((u32)data->sprites + (u32)f);
  data->unk1 = (spriteset_unk1*)((u32)data->unk1 + (u32)f);
  data->subsprites = (Subsprite*)((u32)data->subsprites + (u32)f);
  data->unk2 = (spriteset_unk2*)((u32)data->unk2 + (u32)f);
  data->tiles = (u8*)((u32)data->tiles + (u32)f);
  return 0;
}

// Unused?
NAKED unknown* FUN_0822f2bc(unknown* a, unknown* b) { INCFUNC("asm/func/FUN_0822f2bc.inc"); }

// SpriteSet の spriteIdx 番目のメタスプライトを SpriteState に読み込む (パレットは未設定のときだけ設定する)
s32 Sprite_LoadSprite(SpriteState* p, SpriteSet* src, u16 spriteIdx) {
  Metasprite* m = &src->sprites[spriteIdx];

  if (m == NULL) return -1;

  p->unk_0 = m->unk_0;
  p->offsetX = m->unk_4;
  p->offsetY = m->unk_6;
  p->q_boxRight = m->unk_8;
  p->q_boxBottom = m->unk_a;
  p->q_boxLeft = m->unk_c;
  p->q_boxTop = m->unk_e;
  p->q_scaleX = 0x40;
  p->q_scaleY = 0x40;
  p->q_rotation = 0;
  if (p->pltt == NULL) {
    p->plttID = src->palStart;
    p->pltt = &gObjPlttData[p->plttID * 16];
  }
  p->subspriteCount = m->subspriteCount;
  p->subsprites = (Subsprite*)((u8*)src->subsprites + m->subspriteOffset);
  p->tiles = src->tiles;
  return 0;
}

NON_MATCH s32 FUN_0822f364(SpriteState* p, SpriteSet* src, u16 spriteIdx, SpriteFlags flags, u8 prio, u8 param_6, u8 param_7, Vec3* pos) {
#ifdef NONMATCHING_C
  if (Sprite_LoadSprite(p, src, spriteIdx) < 0) return -1;

  *(u16*)&p->unk_2 = u16_030044b8;  // unk_2, unk_3 をまとめて書く (Sprite_SetSprite と同じ)
  p->flags |= flags;
  p->unk_c = 0;  // 元は movs r1, #0 が unk_2 の strh より前に来て、flags の OR は r2 を使う
  p->unk_10 = 0x40;
  p->unk_e = param_7;
  p->priority = prio;
  p->unk_1b = param_6;
  p->pos = *pos;
  return 0;
#else
  INCFUNC("asm/func/FUN_0822f364.inc");
#endif
}

s32 Sprite_SetSprite(SpriteState* p, SpriteSet* src, u16 spriteIdx, u8 param_4) {
  if (Sprite_LoadSprite(p, src, spriteIdx) < 0) return -1;

  *(u16*)&p->unk_2 = u16_030044b8;  // unk_2, unk_3 をまとめて書く (FUN_080609dc は 1 バイトずつ書く)
  p->unk_1b = param_4;
  return 0;
}

NAKED s32 FUN_0822f3fc(SpriteState* p, SpriteSet* src, u16 spriteIdx, SpriteFlags flags, u8 prio, u8 param_6, u8 param_7, Vec3* pos) { INCFUNC("asm/func/FUN_0822f3fc.inc"); }

NAKED s32 FUN_0822f4d8(SpriteState* p, SpriteSet* src, u16 spriteIdx, SpriteFlags flags, u8 prio, u8 param_6, u8 param_7, Vec3* pos) { INCFUNC("asm/func/FUN_0822f4d8.inc"); }

void FUN_0822f584(void) {}

NAKED void FUN_0822f588(unknown* a, unknown* b, u32 val) { INCFUNC("asm/func/FUN_0822f588.inc"); }

void Sprite_SetPlttID(SpriteState* p, u32 plttID) {
  u16 id;

  p->plttID = plttID;
  id = p->plttID;
  p->pltt = &gObjPlttData[id * 16];
}
