#include "camera_inline.h"
#include "entity.h"
#include "global.h"
#include "player.h"
#include "video.h"
#include "vm.h"

// 操作キャラをジャンゴとサバタで入れ替えるときの, プレイヤーを中心にした円形ワイプ
// チェンジ魔方陣や螺旋の塔のイベントで Scr_StartChangePlayerWipe(0) が閉じ, 行き先で Scr_AddPosEntrance が Scr_StartChangePlayerWipe(1) で開く
// 走査線ごとの WIN0H を2面バッファに焼いて HBlank で流す
typedef struct {
  Entity e;          // 0x000, ENTITY_UNK_9 または ENTITY_UNK_11
  s16 radius;        // 0x018, '.r=250' << 4 (4000 で頭打ち), 使うときは >> 4
  u16 expand;        // 0x01A, '.m=0', 非0 なら radius を広げ, 0 なら狭める
  s16 radiusStep;    // 0x01C, '.s=8' << 4
  bool8 killAtEnd;   // 0x01E, '.d=0', radius が端まで届いたら自分を消す
  u8 unk_1f;         // 0x01F
  u16 frame;         // 0x020, 毎フレーム +1
  u16 bufIdx;        // 0x022, HBlank に流している winH の添字, 毎フレーム 0 と 1 を行き来する
  u16 winH[2][180];  // 0x024, ChangePlayerWipe_DrawScanlines(p, i) が 0x24 + i*0x168 に走査線1本ぶんの WIN0H (左<<8 | 右) を Sqrt(r*r - dy*dy) で焼く
  Vec3 center;       // 0x2F4, プレイヤーを投影した画面座標, x は 0..240, y は 0..180 に丸める
  u8 unk_2fc[4];     // 0x2FC, padding?
} ChangePlayerWipe;
static_assert(sizeof(ChangePlayerWipe) == 768);

IWRAM_DATA ChangePlayerWipe* gChangePlayerWipe = NULL;  // 0x03000094

void ChangePlayerWipe_ClearInstance(void) { gChangePlayerWipe = NULL; }

// 走査線1本ずつ円の左右端を求めて WIN0H のバッファに焼く
// 残差は dead な r - center.y (subs r0, r2, r0) と r の複写の 2 命令だけ, 原典はこの値を使う経路が後段で消えている
NON_MATCH void ChangePlayerWipe_DrawScanlines(ChangePlayerWipe* p, s32 bufIdx) {
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
  INCFUNC("asm/func/ChangePlayerWipe_DrawScanlines.inc");
#endif
}

// HBlank エフェクトを止める
void ChangePlayerWipe_StopHBlank(void) {
  gHBlankEffectBuffer = NULL;
  gHBlankEffectReg = NULL;
  gHBlankDmaCount = 1;
  gHBlankDmaMode = 0;
}

s32 ChangePlayerWipe_Update(ChangePlayerWipe* p) {
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
  ChangePlayerWipe_DrawScanlines(p, 1 - p->bufIdx);
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

s32 ChangePlayerWipe_Destroy(ChangePlayerWipe* p) {
  ChangePlayerWipe_StopHBlank();
  VBlankIntrWait();
  Video_SetWindowRect(0, 0, 0, 240, 180);
  gChangePlayerWipe = NULL;
  return 0;
}

s32 ChangePlayerWipe_Init(ChangePlayerWipe* p, u16 param_2) {
  Player* player;
  s32 i;

  gChangePlayerWipe = p;
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
    ChangePlayerWipe_DrawScanlines(p, i);
  }
}

// '.a' で所属する更新リストを切り替える
ChangePlayerWipe* ChangePlayerWipe_Create(s32 param_1) {
  ChangePlayerWipe* p;
  s32 useAltList = VM_GetNamedArgValue('a', 0);

  if (gChangePlayerWipe != NULL) {
    return gChangePlayerWipe;
  }
  if (useAltList != 0) {
    p = CreateEntity(ENTITY_UNK_11, sizeof(ChangePlayerWipe));
  } else {
    p = CreateEntity(ENTITY_UNK_9, sizeof(ChangePlayerWipe));
  }
  if (p != NULL) {
    SetEntityRoutine(p, ChangePlayerWipe_Update, ChangePlayerWipe_Destroy);
    if (ChangePlayerWipe_Init(p, param_1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
