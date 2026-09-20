#include "global.h"
#include "sprite.h"

extern u16 u16_030044b8;

s32 MainSprite_AddDrawList(MainSprite* p, s32 idx);
void MainSprite_RemoveDrawList(MainSprite* p, s32 idx);

s32 FUN_0822f1b0(void) {
  u16_030044b8 = 0;
  return 0;
}

void MainSprite_Remove(MainSprite* p) {
  if (p->active) {
    MainSprite_RemoveDrawList(p, p->listIdx);
  }
}

// 描画リストに繋がれている MainSprite を全て外す
void UNUSED MainSprite_RemoveAll(void) {
  MainSprite* p = gMainSpriteLists[gSpriteListIdx];
  while (p != NULL) {
    MainSprite* next = p->next;
    MainSprite_Remove(p);
    p = next;
  }
}

// sprite_main_arm.c の ARMステートの関数を呼び出すためのトランポリン関数
#define ARM_TRAMPOLINE(armFunc) \
  asm(".syntax unified\n\
	push {lr}\n\
	adr r1, 1f\n\
	bx r1\n\
	.arm\n\
1:\n\
	bl " #armFunc           \
      "\n\
	adr r2, 2f + 1\n\
	bx r2\n\
	.thumb\n\
2:\n\
	adds r3, #0\n\
	adds r3, #0\n\
	pop {r0}\n\
	bx r0\n\
  /* トランポリンの間にある4バイト。何もせずに戻るだけで、呼び出し元も見つかっていない */ \
	movs r0, r0\n\
	bx lr\n\
 .syntax divided\n")

NAKED void FUN_0822f204(void) { ARM_TRAMPOLINE(FUN_08230134); }

NAKED void FUN_0822f224(void) { ARM_TRAMPOLINE(FUN_082302e8); }

NAKED void FUN_0822f244(void) { ARM_TRAMPOLINE(FUN_082303c8); }

NAKED void FUN_0822f264(void) { ARM_TRAMPOLINE(FUN_08230594); }

// spriteset ファイルのヘッダをコピーし、各オフセットをファイル先頭からのポインタに変換する
s32 OpenMainSpriteFile(MainSpriteGfx* data, MainSpriteFile* f) {
  *data = *(MainSpriteGfx*)f;
  data->sprites = (MainSpritePose*)((u32)data->sprites + (u32)f);
  data->unk1 = (MainAnim*)((u32)data->unk1 + (u32)f);
  data->subsprites = (MainSubsprite*)((u32)data->subsprites + (u32)f);
  data->unk2 = (MainAnimCmd*)((u32)data->unk2 + (u32)f);
  data->tiles = (u8*)((u32)data->tiles + (u32)f);
  return 0;
}

// Unused?
NAKED unknown* FUN_0822f2bc(unknown* a, unknown* b) { INCFUNC("asm/func/FUN_0822f2bc.inc"); }

// MainSpriteGfx の spriteIdx 番目のメタスプライトを MainSprite に読み込む (パレットは未設定のときだけ設定する)
s32 MainSprite_LoadPose(MainSprite* p, MainSpriteGfx* gfx, u16 spriteIdx) {
  MainSpritePose* m = &gfx->sprites[spriteIdx];

  if (m == NULL) return -1;

  p->unk_0 = m->unk_0;
  p->offsetX = m->offsetX, p->offsetY = m->offsetY;
  p->boxRight = m->boxRight, p->boxBottom = m->boxBottom, p->boxLeft = m->boxLeft, p->boxTop = m->boxTop;
  p->scaleX = 0x40, p->scaleY = 0x40;
  p->rotation = 0;
  if (p->pltt == NULL) {
    p->plttID = gfx->palStart;
    p->pltt = &gObjPlttData[p->plttID * 16];
  }
  p->subspriteCount = m->subspriteCount;
  p->subsprites = (MainSubsprite*)((u8*)gfx->subsprites + m->subspriteOffset);
  p->tiles = gfx->tiles;
  return 0;
}

// ポーズ読み込み＋フラグ・優先度・座標の設定
NON_MATCH s32 MainSprite_Load(MainSprite* p, MainSpriteGfx* gfx, u16 spriteIdx, SpriteFlags flags, u8 prio, u8 playMode, u8 animCmdDuration, Vec3* pos) {
#ifdef NONMATCHING_C
  if (MainSprite_LoadPose(p, gfx, spriteIdx) < 0) return -1;

  *(u16*)&p->unk_2 = u16_030044b8;  // unk_2, unk_3 をまとめて書く (MainSprite_SetPose と同じ)
  p->flags |= flags;
  p->animCmdTimer = 0;  // 元は movs r1, #0 が unk_2 の strh より前に来て、flags の OR は r2 を使う
  p->animSpeed = 0x40;
  p->animCmdDuration = animCmdDuration;
  p->priority = prio;
  p->playMode = playMode;
  p->pos = *pos;
  return 0;
#else
  INCFUNC("asm/func/MainSprite_Load.inc");
#endif
}

s32 MainSprite_SetPose(MainSprite* p, MainSpriteGfx* gfx, u16 spriteIdx, u8 playMode) {
  if (MainSprite_LoadPose(p, gfx, spriteIdx) < 0) return -1;

  *(u16*)&p->unk_2 = u16_030044b8;  // unk_2, unk_3 をまとめて書く (FUN_080609dc は 1 バイトずつ書く)
  p->playMode = playMode;
  return 0;
}

static inline void _MainSprite_Setup(MainSprite* p, MainSpriteGfx* gfx, u16 spriteIdx, SpriteFlags flags, u8 prio, u8 playMode, u8 animCmdDuration, Vec3* pos) {
  p->unk_0 = 0;
  p->unk_12 = 0;
  p->animCmdIdx = 0;
  p->animCmdLength = 0;
  p->animFlags = 0;
  p->animEvents = 0;
  p->offsetX = 0, p->offsetY = 0;
  p->boxRight = 0, p->boxBottom = 0, p->boxLeft = 0, p->boxTop = 0;
  p->scaleX = 0, p->scaleY = 0;
  p->rotation = 0;
  p->oamAttr = 0;
  p->animCmds = NULL;
  p->pltt = NULL;
  p->subsprites = NULL;
  p->tiles = NULL;
  MainSprite_Load(p, gfx, spriteIdx, flags, prio, playMode, animCmdDuration, pos);
  if (++u16_030044b8 == 0xFFFF) {
    u16_030044b8 = 0;
  }
  p->q_unk_40 = -1;
  p->q_unk_44 = -1;
  p->prev = NULL, p->next = NULL;
}

// MainSprite を初期化してスプライトを読み込み、描画リストに繋ぐ (pos が NULL なら原点に置く)
s32 MainSprite_Add(MainSprite* p, MainSpriteGfx* gfx, u16 spriteIdx, SpriteFlags flags, u8 prio, u8 playMode, u8 animCmdDuration, Vec3* pos) {
  Vec3 v;

  if (pos == NULL) {
    v.x = 0, v.y = 0, v.z = 0;
  } else {
    v = *pos;
  }
  if (!p->active) {
    _MainSprite_Setup(p, gfx, spriteIdx, flags, prio, playMode, animCmdDuration, &v);
    MainSprite_AddDrawList(p, (u32) - (flags & 0x80) >> 31);
    return 0;
  }
  return -1;
}

// MainSprite を初期化してスプライトを読み込む (MainSprite_Add と違い描画リストには繋がない)
s32 MainSprite_Setup(MainSprite* p, MainSpriteGfx* gfx, u16 spriteIdx, SpriteFlags flags, u8 prio, u8 playMode, u8 animCmdDuration, Vec3* pos) {
  if (p->active != 0) return -1;
  _MainSprite_Setup(p, gfx, spriteIdx, flags, prio, playMode, animCmdDuration, pos);
  return 0;
}

void FUN_0822f584(void) {}

NAKED void FUN_0822f588(MainSprite* p, unknown* data, u32 val) { INCFUNC("asm/func/FUN_0822f588.inc"); }

void MainSprite_SetPlttID(MainSprite* p, u32 plttID) {
  u16 id;

  p->plttID = plttID;
  id = p->plttID;
  p->pltt = &gObjPlttData[id * 16];
}
