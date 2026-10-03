#include "entity.h"
#include "global.h"
#include "sprite_pltt.h"
#include "time.h"
#include "video.h"
#include "vm.h"

extern s32 gObjPlttSlotCursor;
extern s32 gObjPlttSlotReserved;
extern s32 gObjPlttSlotCount;
s32 FUN_0822d190(u32 plttID, rgb555* pltt);
s32 FUN_0823ce10(u16* a, u16* b);
u32 FUN_0823cdf8(u16 id);

// 1枚ぶんの補間スロット, 同じ絵の時刻帯バリエーション3枚を srcs に持ち、2枚の間を混ぜた結果を pltt に書く
typedef struct {
  u16 id;           // 0x00, スクリプトの '.p', FUN_0823cdf8 に渡して plttID を引く
  u16 plttID;       // 0x02, '.o[i]' + FUN_0823cdf8(id), FUN_0822d190 に渡す OBJ パレットのID
  rgb555 pltt[16];  // 0x04, 混ぜた結果, これを FUN_0822d190 で OBJ パレットスロットに載せる
  rgb555* srcs[3];  // 0x24, gObjPlttData の plttID * 32 から 32 バイトおきの3枚
} ObjPlttBlend;
static_assert(sizeof(ObjPlttBlend) == 48);

// OBJ パレットの補間スロットを最大6件持ち、時刻帯に応じて2枚の間を混ぜて毎フレーム OBJ パレットスロットに載せるシングルトン
// BG 側の BgPlttBlender と対になる, 混ぜ先の2枚は FUN_0823ce10 が gClock.spanOfTime から選ぶ
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_12
  u16 unk_18;             // 0x18, ObjPlttBlender_Init の第2引数をそのまま保存, 読み手が見つかっていない
  u16 count;              // 0x1A, 使用中のスロット数, _Init が '.p' を1件読むごとに +1 (最大6)
  u16 srcFrom;            // 0x1C, 混ぜ始めの srcs[] の添字
  u16 srcTo;              // 0x1E, 混ぜ終わりの srcs[] の添字
  u16 blend;              // 0x20, srcFrom から srcTo への混ぜ具合 (6.6固定小数, 0..0x40), Update が毎フレーム +1 して 0x40 で止める
  u16 unk_22;             // 0x22
  u16 unk_24;             // 0x24, gClock.unk_0f の控え, 書くだけで読み手がいない
  u16 spanOfTime;         // 0x26, gClock.spanOfTime の控え, Update が変化を見て blend を 0 に戻す
  ObjPlttBlend slots[6];  // 0x28
} ObjPlttBlender;
static_assert(sizeof(ObjPlttBlender) == 328);

// 1スロットぶん, srcs[srcFrom] と srcs[srcTo] を blend の割合で混ぜて pltt に書く
// 残差3命令: 原典は 0x1F を2本のレジスタに分けて持ち srcA も退避するが、こちらは 0x1F が1本に畳まれる (Tier A-B 試済, 未: Tier C)
NON_MATCH void ObjPlttBlender_UpdateSlot(ObjPlttBlender* p, ObjPlttBlend* slot) {
#ifdef NONMATCHING_C
  rgb555* dst = slot->pltt;
  rgb555* srcA = slot->srcs[p->srcFrom];
  rgb555* srcB = slot->srcs[p->srcTo];
  s32 t = p->blend;
  s32 inv;
  s32 i;

  if (t > 0x40) {
    t = 0x40;
  }
  inv = 0x40 - t;
  for (i = 15; i >= 0; i--) {
    s32 ar = *srcA & 0x1F;
    s32 ag = (*srcA >> 5) & 0x1F;
    s32 ab = (*srcA >> 10) & 0x1F;
    s32 br = *srcB & 0x1F;
    s32 bg = (*srcB >> 5) & 0x1F;
    s32 bb = (*srcB >> 10) & 0x1F;
    s32 r = (t * br + inv * ar) >> 6;
    s32 g = (t * bg + inv * ag) >> 6;
    s32 b = (t * bb + inv * ab) >> 6;

    *dst++ = (r & 0x1F) | ((g & 0x1F) << 5) | ((b & 0x1F) << 10);
    srcA++;
    srcB++;
  }
#else
  INCFUNC("asm/func/ObjPlttBlender_UpdateSlot.inc");
#endif
}

// 時刻帯が変わったら混ぜ直しを始め、混ぜ終わるまで毎フレーム進めてから全スロットを OBJ パレットスロットに載せる
s32 ObjPlttBlender_Update(ObjPlttBlender* p) {
  s32 i;

  if (p->spanOfTime != gClock.spanOfTime) {
    FUN_0823ce10(&p->srcFrom, &p->srcTo);
    p->blend = 0;
  }

  if (p->blend <= 0x3F) {
    for (i = 0; i < p->count; i++) {
      ObjPlttBlender_UpdateSlot(p, &p->slots[i]);
    }
    p->blend++;
    if (p->blend > 0x40) {
      p->blend = 0x40;
    }
  }

  gObjPlttSlotCursor = gObjPlttSlotCount;
  gObjPlttSlotReserved = 0;
  for (i = 0; i < p->count; i++) {
    FUN_0822d190(p->slots[i].plttID, p->slots[i].pltt);
    gObjPlttSlotReserved++;
  }

  p->unk_24 = gClock.unk_0f;
  p->spanOfTime = gClock.spanOfTime;
  return 0;
}

s32 ObjPlttBlender_Destroy(ObjPlttBlender* p) { return 0; }

// スクリプトの '.p' で指定された OBJ パレットを最大6件スロットに積み、'.o' のオフセットを足した plttID から3枚のバリエーションを引く
// 残差2命令: 0 埋めの下りループが原典では符号付き比較のポインタ walk で前置ガードも無いが、こちらはガードが付いて bcs になる (Tier A-B 試済, 未: Tier C)
NON_MATCH s32 ObjPlttBlender_Init(ObjPlttBlender* p, u16 val) {
#ifdef NONMATCHING_C
  u16 ofs[6];
  s32 i;

  p->unk_18 = val;
  p->count = 0;

  if (VM_SeekToNamedArg('o')) {
    i = 0;
    while (i <= 5 && VM_GetPC() != NULL) {
      ofs[i] = VM_GetValue();
      i++;
    }
    for (; i <= 5; i++) {
      ofs[i] = 0;
    }
  } else {
    u16* q = &ofs[5];

    while (q >= ofs) {
      *q = 0;
      q--;
    }
  }

  if (VM_SeekToNamedArg('p')) {
    i = 0;
    while (i <= 5 && VM_GetPC() != NULL) {
      ObjPlttBlend* slot = &p->slots[i];

      slot->id = VM_GetValue();
      slot->plttID = ofs[i] + FUN_0823cdf8(slot->id);
      slot->srcs[0] = gObjPlttData + slot->plttID * 16;
      slot->srcs[1] = slot->srcs[0] + 16;
      slot->srcs[2] = slot->srcs[1] + 16;
      p->count++;
      i++;
    }
  }

  FUN_0823ce10(&p->srcFrom, &p->srcTo);
  p->blend = 0x40;
  p->unk_24 = gClock.unk_0f;
  p->spanOfTime = gClock.spanOfTime;
  for (i = 0; i < p->count; i++) {
    ObjPlttBlender_UpdateSlot(p, &p->slots[i]);
  }
  return 0;
#else
  INCFUNC("asm/func/ObjPlttBlender_Init.inc");
#endif
}

ObjPlttBlender* ObjPlttBlender_Create(u32 val) {
  ObjPlttBlender* p = CreateEntity(ENTITY_UNK_12, sizeof(ObjPlttBlender));

  if (p != NULL) {
    SetEntityRoutine(p, ObjPlttBlender_Update, ObjPlttBlender_Destroy);
    if (ObjPlttBlender_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
