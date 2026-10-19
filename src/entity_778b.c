#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// スクリプトから積まれた生成要求1件, 生成物が死ぬと Entity778B_Update が同じ設定で作り直す
typedef struct {
  Vec3 pos;       // 0x00, '.p'
  Vec3 unk_08;    // 0x08, '.a'
  s16 unk_10;     // 0x10, '.f[1]'..'.f[2]' の乱数, 太陽ゲージが満たないときは (10 - sunGauge) / 10 倍される
  s16 unk_12;     // 0x12, '.t', 同じく太陽ゲージで減る
  u16 unk_14;     // 0x14, '.n'
  u16 unk_16;     // 0x16, 0 で固定
  u8 unk_18;      // 0x18, '.d'
  u8 unk_19;      // 0x19, '.f[0]'
  u16 slotIdx;    // 0x1A, usedMask 上の自分のビット番号
  void* spawned;  // 0x1C, 生成物, +0x136 が負になったら作り直す
} Entity778BElem;
static_assert(sizeof(Entity778BElem) == 32);

// 生成要求を12件まで抱えるシングルトン, ゲームオーバー中と u32_03002bc0 の FLAG03002BC0_UNK_2 が立っている間は止まる
typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_10
  Entity778BElem elems[12];  // 0x018
  u32 usedMask;              // 0x198, elems のどのスロットが使用中かのビットマスク
} Entity778B;
static_assert(sizeof(Entity778B) == 412);

IWRAM_DATA Entity778B* gEntity778B = NULL;  // 0x03000180

void Entity081eaf6c_Create(void);

const u8 u8_ARRAY_085ad374[80] = {
    0, 0, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 3, 2, 2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 0, 2, 2, 2, 2, 0, 0,
};  // 0x085AD374

NAKED s32 FUN_080e0404(s32 param_1, s32 param_2, unknown* param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e0404.inc"); }

NAKED void FUN_080e0588(s32 param_1, s32 param_2, unknown* param_3, unknown* param_4) { INCFUNC("asm/func/FUN_080e0588.inc"); }

NAKED s32 FUN_080e05f0(s32 param_1, unknown* param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080e05f0.inc"); }

NAKED s32 FUN_080e0748(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e0748.inc"); }

NAKED s32 FUN_080e0884(unknown* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e0884.inc"); }

NAKED s32 FUN_080e09b8(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_080e09b8.inc"); }

NAKED s32 FUN_080e0c28(unknown* param_1, unknown* param_2, unknown* param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080e0c28.inc"); }

NAKED void FUN_080e0fbc(void) { INCFUNC("asm/func/FUN_080e0fbc.inc"); }

NAKED s32 FUN_080e1080(unknown* param_1, unknown* param_2, unknown* param_3) { INCFUNC("asm/func/FUN_080e1080.inc"); }

NAKED s32 FUN_080e1100(Vec3* pos, Vec3* size, u32* out) { INCFUNC("asm/func/FUN_080e1100.inc"); }

NAKED s32 FUN_080e11a8(Vec3* pos, Vec3* size, s32 idx) { INCFUNC("asm/func/FUN_080e11a8.inc"); }

// 指定BGのタイルマップから (x, y) のエントリのアドレスを返す
BgMapEntry* FUN_080e1218(s32 bgIdx, s32 x, s32 y) {
  BgState* s = &gBgStates[bgIdx];
  BgMapEntry* map = s->tilemap;

  return map + (x & 31) + (y & 31) * 32;
}

// 指定BGのタイルマップの (x, y) から width × height を value で塗る
void FUN_080e1238(s32 x, s32 y, s32 width, s32 height, s32 value, s32 bgIdx) {
  s32 i;

  for (i = 0; i < height; i++) {
    BgMapEntry* dst = FUN_080e1218(bgIdx, x, y + i);
    s32 j;

    for (j = 0; j < width; j++) {
      *dst = value;
      dst++;
    }
  }
}

NAKED void FUN_080e1280(void) { INCFUNC("asm/func/FUN_080e1280.inc"); }

NAKED Entity778BElem* FUN_080e1334(void) { INCFUNC("asm/func/FUN_080e1334.inc"); }

// 空いている枠を確保して返す, 無ければ NULL
// 残差7命令 (28 対 35), 原典は使用中判定の結果を 1/0 として一度作ってから改めて 0 と比べる (いわゆる 0/1 の作り置き)
// attack_box.c の AttackBoxManager_IsSlotUsed と同じ static inline bool32 でも 30 対 35 までで, 作り置きは出ない
NON_MATCH Entity778BElem* Entity778B_AllocElem(Entity778B* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!(p->usedMask & (1 << i))) {
      p->usedMask |= 1 << i;
      p->elems[i].slotIdx = i;
      return &p->elems[i];
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/Entity778B_AllocElem.inc");
#endif
}

NAKED s32 Entity778B_Update(Entity778B* p) { INCFUNC("asm/func/Entity778B_Update.inc"); }

s32 Entity778B_Destroy(Entity778B* p) {
  gEntity778B = NULL;
  return 0;
}

s32 Entity778B_Init(Entity778B* p, s32 unused) {
  Entity081eaf6c_Create();
  gEntity778B = p;
  return 0;
}

// 0x778B
Entity778B* Entity778B_Create(s32 param_1) {
  if (gEntity778B == NULL) {
    Entity778B* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity778B));

    if (p != NULL) {
      SetEntityRoutine(p, Entity778B_Update, Entity778B_Destroy);
      if (Entity778B_Init(p, param_1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity778B;
}

NAKED void Entity778B_AddElemScripted(void) { INCFUNC("asm/func/Entity778B_AddElemScripted.inc"); }

void Entity778B_ClearGlobal(void) { gEntity778B = NULL; }

// '.n' で指された生成要求を使用中マスクから外して消す
void FUN_080e16f4(void) {
  Entity778B* p = gEntity778B;
  Entity778BElem* e;
  s32 slot;

  if (p == NULL || VM_GetNamedArgValue('n', -1) < 0) {
    return;
  }

  e = FUN_080e1334();
  if (e == NULL) {
    return;
  }

  slot = (s16)e->slotIdx;
  p->usedMask &= ~(1 << slot);
  ClearMemory(e, sizeof(Entity778BElem));
}
