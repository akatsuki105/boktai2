#include "entity.h"
#include "global.h"
#include "video.h"

// OBJ パレット4行を抱えて、count 個の要素 (1個 412バイト) を回すシングルトン
typedef struct {
  Entity e;              // 0x00, ENTITY_UNK_8
  u16 count;             // 0x18, elems の要素数, _Create が '.m=8' を入れ、0 なら 8 にする
  u8 unk_1a;             // 0x1A, _Init が 0 を入れる
  u8 unk_1b;             // 0x1B, _Init が 0 を入れる
  u16 unk_1c;            // 0x1C, _Init が 0 を入れる
  u8 unk_1e;             // 0x1E, _Init が 0 を入れる
  u8 unk_1f;             // 0x1F, 読み手も書き手も見つかっていない
  rgb555* pltt[4];       // 0x20, &gObjPlttData[0x20/0x30/0x40/0x50] (OBJ パレットの4行)
  rgb555 savedPltt[16];  // 0x30, _Init が pltt[3] の16色をコピーする
  rgb555 unk_50[16];     // 0x50, _Init が pltt[3] の16色をコピーする (savedPltt と同じ内容)
  void* elems;           // 0x70, Malloc(count * 0x19C), 1要素 412バイトで、+0x1E が使用中フラグ
} EntityD9AE;
static_assert(sizeof(EntityD9AE) == 116);

IWRAM_DATA EntityD9AE* gEntityD9AE = NULL;  // 0x03000020

const u8 u8_ARRAY_085aa650[8] = {2, 2, 3, 3, 0, 0, 1, 1};  // 0x085AA650

void FUN_080037c8(void*);
void FUN_080038bc(void*);
void FUN_08003970(void*);

void (*const PTR_ARRAY_085aa658[5])(void*) = {
    FUN_080037c8, FUN_080038bc, FUN_08003970, NULL, NULL,
};  // 0x085AA658

void FUN_08003008(void) { gEntityD9AE = NULL; }

INCASM("asm/entity_d9ae.inc");
