#include "camera_inline.h"
#include "entity.h"
#include "global.h"
#include "player.h"
#include "video.h"
#include "vm.h"

// プレイヤーを中心にした円形ワイプ, 走査線ごとの WIN0H を2面バッファに焼いて流す
typedef struct {
  Entity e;          // 0x000, ENTITY_UNK_9 または ENTITY_UNK_11
  s16 radius;        // 0x018, '.r=250' << 4 (4000 で頭打ち), 使うときは >> 4
  u16 expand;        // 0x01A, '.m=0', 非0 なら radius を広げ, 0 なら狭める
  s16 radiusStep;    // 0x01C, '.s=8' << 4
  bool8 killAtEnd;   // 0x01E, '.d=0', radius が端まで届いたら自分を消す
  u8 unk_1f;         // 0x01F
  u16 frame;         // 0x020, 毎フレーム +1
  u16 bufIdx;        // 0x022, HBlank に流している winH の添字, 毎フレーム 0 と 1 を行き来する
  u16 winH[2][180];  // 0x024, FUN_0801ad78(p, i) が 0x24 + i*0x168 に走査線1本ぶんの WIN0H (左<<8 | 右) を Sqrt(r*r - dy*dy) で焼く
  Vec3 center;       // 0x2F4, プレイヤーを投影した画面座標, x は 0..240, y は 0..180 に丸める
  u8 unk_2fc[4];     // 0x2FC, padding?
} Entity12C4;
static_assert(sizeof(Entity12C4) == 768);

IWRAM_DATA Entity12C4* gEntity12C4 = NULL;  // 0x03000094

void FUN_0801ad6c(void) { gEntity12C4 = NULL; }

// 走査線1本ずつ円の左右端を求めて WIN0H のバッファに焼く
// 残差は dead な r - center.y (subs r0, r2, r0) と r の複写の 2 命令だけ, 原典はこの値を使う経路が後段で消えている
NON_MATCH void FUN_0801ad78(Entity12C4* p, s32 bufIdx) {
#ifdef NONMATCHING_C
  s32 r = p->radius >> 4;
  s32 rr = r * r;
  s32 top = p->center.y - r;
  s32 bottom;
  s32 dy;
  u16* dst;
  s32 y;

  if (top < 0) {
    top = 0;
  }
  bottom = p->center.y + r;
  if (bottom > 180) {
    bottom = 180;
  }
  dy = r - p->center.y;
  dst = p->winH[bufIdx];
  for (y = 0; y < top; y++, dst++) {
    *dst = 0;
  }
  for (y = top; y < bottom; y++, dst++) {
    s32 half;
    s32 left;
    s32 right;

    dy = p->center.y - y;
    half = Sqrt(rr - dy * dy);
    left = p->center.x - half;
    right = p->center.x + half;
    if (left < 0) {
      left = 0;
    }
    if (right > 240) {
      right = 240;
    }
    *dst = ((left & 0xFF) << 8) | (right & 0xFF);
  }
  for (y = bottom; y < 180; y++, dst++) {
    *dst = 0;
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
  gHBlankDmaCount = 1;
  gHBlankDmaMode = 0;
}

s32 Entity12C4_Update(Entity12C4* p) {
  Player* player = gPlayerPtr[0];

  if (player != NULL) {
    Vec3 pos = player->mover.pos;

    pos.y += 164;
    WorldToScreen(&p->center, &pos);
    if (p->center.x < 0) {
      p->center.x = 0;
    } else if (p->center.x > 240) {
      p->center.x = 240;
    }
    if (p->center.y < 0) {
      p->center.y = 0;
    } else if (p->center.y > 180) {
      p->center.y = 180;
    }
  } else {
    p->center.x = 120;
    p->center.y = 90;
  }
  FUN_0801ad78(p, 1 - p->bufIdx);
  gHBlankEffectBuffer = p->winH[p->bufIdx];
  gHBlankEffectReg = &REG_WIN0H;
  gHBlankDmaCount = 1;
  gHBlankDmaMode = 1;
  if (p->expand) {
    p->radius += p->radiusStep;
    if (p->radius >= 4000) {
      p->radius = 4000;
      if (p->killAtEnd) {
        KillEntity((Entity*)p);
      }
    }
  } else {
    p->radius -= p->radiusStep;
    if (p->radius <= 512) {
      p->radius = 512;
      if (p->killAtEnd) {
        KillEntity((Entity*)p);
      }
    }
  }
  p->bufIdx = 1 - p->bufIdx;
  p->frame++;
  return 0;
}

s32 Entity12C4_Destroy(Entity12C4* p) {
  FUN_0801ae64();
  VBlankIntrWait();
  Video_SetWindowRect(0, 0, 0, 240, 180);
  gEntity12C4 = NULL;
  return 0;
}

s32 Entity12C4_Init(Entity12C4* p, u16 param_2) {
  Player* player;
  s32 i;

  gEntity12C4 = p;
  p->frame = 0;
  p->bufIdx = 0;
  p->expand = VM_GetNamedArgValue('m', 0);
  p->radius = VM_GetNamedArgValue('r', 250) << 4;
  if (p->radius >= 4000) {
    p->radius = 4000;
  }
  p->radiusStep = VM_GetNamedArgValue('s', 8) << 4;
  p->killAtEnd = VM_GetNamedArgValue('d', 0);
  player = gPlayerPtr[0];
  if (player != NULL) {
    WorldToScreen(&p->center, &player->mover.pos);
    if (p->center.x < 0) {
      p->center.x = 0;
    } else if (p->center.x > 240) {
      p->center.x = 240;
    }
    if (p->center.y < 0) {
      p->center.y = 0;
    } else if (p->center.y > 180) {
      p->center.y = 180;
    }
  } else {
    p->center.x = 120;
    p->center.y = 90;
  }
  for (i = 0; i < 2; i++) {
    FUN_0801ad78(p, i);
  }
}

// '.a' で所属する更新リストを切り替える
Entity12C4* Entity12C4_Create(s32 param_1) {
  Entity12C4* p;
  s32 useAltList = VM_GetNamedArgValue('a', 0);

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
