#include "entity.h"
#include "global.h"
#include "video.h"

// EntityD9AE が count 個まわす1要素, 中身はほとんど未解析
typedef struct {
  u8 unk_0[0x1E];           // 0x000
  bool8 active;             // 0x01E, 0 なら空き枠
  u8 unk_1f[0x2C - 0x1F];   // 0x01F
  u16 id;                   // 0x02C, FUN_08004694 の検索キー
  u8 unk_2e[0x19C - 0x2E];  // 0x02E
} EntityD9AEElem;
static_assert(sizeof(EntityD9AEElem) == 412);

// OBJ パレット4行を抱えて、count 個の要素 (1個 412バイト) を回すシングルトン
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_8
  u16 count;              // 0x18, elems の要素数, _Create が '.m=8' を入れ、0 なら 8 にする
  u8 unk_1a;              // 0x1A, _Init が 0 を入れる
  u8 unk_1b;              // 0x1B, _Init が 0 を入れる
  u16 unk_1c;             // 0x1C, _Init が 0 を入れる
  u8 unk_1e;              // 0x1E, _Init が 0 を入れる
  u8 unk_1f;              // 0x1F, 読み手も書き手も見つかっていない
  rgb555* pltt[4];        // 0x20, &gObjPlttData[0x20/0x30/0x40/0x50] (OBJ パレットの4行)
  rgb555 savedPltt[16];   // 0x30, _Init が pltt[3] の16色をコピーする
  rgb555 unk_50[16];      // 0x50, _Init が pltt[3] の16色をコピーする (savedPltt と同じ内容)
  EntityD9AEElem* elems;  // 0x70, Malloc(count * sizeof(EntityD9AEElem))
} EntityD9AE;
static_assert(sizeof(EntityD9AE) == 116);

IWRAM_DATA EntityD9AE* gEntityD9AE = NULL;  // 0x03000020

const u8 u8_ARRAY_085aa650[8] = {2, 2, 3, 3, 0, 0, 1, 1};  // 0x085AA650

void FUN_080037c8(void*);
void FUN_080038bc(void*);
void FUN_08003970(void*);

void (*const PTR_ARRAY_085aa658[5])(void*) = {
    FUN_080037c8,
    FUN_080038bc,
    FUN_08003970,
    NULL,
    NULL,
};  // 0x085AA658

void FUN_08003008(void) { gEntityD9AE = NULL; }

INCASM("asm/entity_d9ae.inc");

// 空いている枠を返す, 無ければ NULL
EntityD9AEElem* FUN_08004668(EntityD9AE* p) {
  EntityD9AEElem* e = p->elems;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (!e->active) {
      return e;
    }
    e++;
  }
  return NULL;
}

// id が一致する使用中の枠を返す, 無ければ NULL
EntityD9AEElem* FUN_08004694(EntityD9AE* p, u32 id) {
  EntityD9AEElem* e = p->elems;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (e->active && e->id == id) {
      return e;
    }
    e++;
  }
  return NULL;
}

NAKED s32 FUN_080046c8(u16 param_1, s32 param_2, s32 param_3, unknown* param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_080046c8.inc"); }

NAKED s32 Cmd_E02A(void) { INCFUNC("asm/func/Cmd_E02A.inc"); }

NAKED s32 Cmd_B76C(void) { INCFUNC("asm/func/Cmd_B76C.inc"); }
