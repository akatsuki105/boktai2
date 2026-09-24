#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// プレイヤーを中心にした円形ワイプ。走査線ごとの WIN0H を2面バッファに焼いて流す
typedef struct {
  Entity e;          // 0x000, ENTITY_UNK_9 または ENTITY_UNK_11
  s16 radius;        // 0x018, '.r=250' << 4 (4000 で頭打ち)。使うときは >> 4
  s16 unk_1a;        // 0x01A, '.m=0'
  s16 radiusStep;    // 0x01C, '.s=8' << 4
  s8 unk_1e;         // 0x01E, '.d=0'
  u8 unk_1f;         // 0x01F
  u16 unk_20;        // 0x020, _Init が 0 を入れる
  u16 unk_22;        // 0x022, _Init が 0 を入れる
  u16 winH[2][180];  // 0x024, FUN_0801ad78(p, i) が 0x24 + i*0x168 に走査線1本ぶんの WIN0H (左<<8 | 右) を Sqrt(r*r - dy*dy) で焼く
  s16 centerX;       // 0x2F4, プレイヤーを投影して 0..0xF0 に丸めたもの, これ以降は Vec3?
  s16 centerY;       // 0x2F6, 同じく 0..0xB4
  s16 unk_2f8;       // 0x2F8, 投影した奥行き。読み手が見つかっていない
  u8 unk_2fa[6];     // 0x2FA, padding?
} Entity12C4;
static_assert(sizeof(Entity12C4) == 768);

IWRAM_DATA Entity12C4* gEntity12C4 = NULL;  // 0x03000094

void FUN_0801ad6c(void) { gEntity12C4 = NULL; }

// 走査線1本ずつ円の左右端を求めて WIN0H のバッファに焼く
NON_MATCH void FUN_0801ad78(Entity12C4* p, s32 bufIdx) {
#ifdef NONMATCHING_C
  s32 r = p->radius >> 4;
  s32 rr = r * r;
  s32 top = p->centerY - r;
  s32 bottom;
  u16* dst;
  s32 y;

  if (top < 0) {
    top = 0;
  }
  bottom = p->centerY + r;
  if (bottom > 180) {
    bottom = 180;
  }
  dst = p->winH[bufIdx];
  for (y = 0; y < top; y++) {
    *dst++ = 0;
  }
  for (y = top; y < bottom; y++) {
    s32 dy = p->centerY - y;
    s32 half = Sqrt(rr - dy * dy);
    s32 left = p->centerX - half;
    s32 right = p->centerX + half;

    if (left < 0) {
      left = 0;
    }
    if (right > 240) {
      right = 240;
    }
    *dst++ = ((left & 0xFF) << 8) | (right & 0xFF);
  }
  for (y = bottom; y < 180; y++) {
    *dst++ = 0;
  }
  p->winH[bufIdx][179] = 0;
#else
  INCFUNC("asm/func/FUN_0801ad78.inc");
#endif
}

// HBlank エフェクトを止める
void FUN_0801ae64(void) {
  gHBlankEffectBuffer = NULL;
  gHBlankEffectReg = NULL;
  u16_03003510 = 1;
  u16_03003514 = 0;
}

NAKED s32 Entity12C4_Update(Entity12C4* p) { INCFUNC("asm/func/Entity12C4_Update.inc"); }

s32 Entity12C4_Destroy(Entity12C4* p) {
  FUN_0801ae64();
  VBlankIntrWait();
  Video_SetWindowRect(0, 0, 0, 240, 180);
  gEntity12C4 = NULL;
  return 0;
}

NAKED s32 Entity12C4_Init(Entity12C4* p, u16 param_2) { INCFUNC("asm/func/Entity12C4_Init.inc"); }

// スクリプトの 'a' で所属する更新リストを切り替える
Entity12C4* Entity12C4_Create(s32 param_1) {
  Entity12C4* p;
  s32 useAltList = VM_GetKeywordValue('a', 0);

  if (gEntity12C4 != NULL) {
    return gEntity12C4;
  }
  if (useAltList != 0) {
    p = CreateEntity(ENTITY_UNK_11, sizeof(Entity12C4));
  } else {
    p = CreateEntity(ENTITY_UNK_9, sizeof(Entity12C4));
  }
  if (p != NULL) {
    SetEntityRoutine(p, Entity12C4_Update, Entity12C4_Destroy);
    if (Entity12C4_Init(p, param_1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
