#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// 画面全体のフェード (ブレンド係数 gObjBrightness と フェード色 gObjPlttBlendColor) を動かすシングルトン
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_11
  u16 unk_18;         // 0x18, _Create の引数, 書き込むだけで読み手が見つかっていない
  u16 unk_1a;         // 0x1A, '.f', 読み手が見つかっていない
  u16 unk_1c;         // 0x1C, _Init が 0 を入れるだけ
  u16 state;          // 0x1E, 0:停止, 1/3:係数を 0x40 へ上げる (_StepUp), 2/4:0 へ下げる (_StepDown)
  u16 timer;          // 0x20, state に入ってからのステップ数, (timer << 6) >> durationShift が係数
  u16 durationShift;  // 0x22, params[0] の写し, 1 << durationShift ステップで終わる
  u16 request;        // 0x24, 1..4 の要求, _Update が state に移して毎フレーム 0 に戻す
  u16 params[7];      // 0x26, [0]=durationShift, [1..3]=フェード色の R/G/B (gObjPlttBlendColor へ rgb555 で合成), [4]=gObjPlttFadeSkipMask
} Entity6978;
static_assert(sizeof(Entity6978) == 52);

COMMON_DATA Entity6978* gEntity6978 = NULL;  // 0x03002B30

void Entity6978_ClearPtr(void) { gEntity6978 = NULL; }

// 明るさを 1 << durationShift ステップかけて 0 まで下げる
void Entity6978_StepDown(Entity6978* p) {
  gObjBrightness = Q6(1) - ((p->timer << 6) >> p->durationShift);
  p->timer++;
  if (p->timer >= 1 << p->durationShift) {
    gObjBrightness = 0;
    if (p->state == 2) {
      p->state = 0;
    } else {
      p->state = 5;
    }
  }
}

// 明るさを 1 << durationShift ステップかけて等倍まで上げる
void Entity6978_StepUp(Entity6978* p) {
  gObjBrightness = (p->timer << 6) >> p->durationShift;
  p->timer++;
  if (p->timer >= 1 << p->durationShift) {
    gObjBrightness = Q6(1);
    p->state = 0;
  }
}

void Entity6978_SetRequestScripted(void) {
  Entity6978* p = gEntity6978;

  if (p != NULL) {
    p->request = VM_GetNamedArgValue('r', 0);
    if (VM_SeekToNamedArg('p')) {
      s32 i;
      u16* dst;

      for (i = 0, dst = p->params; VM_GetPC() != NULL && i <= 6; i++) {
        *dst++ = VM_GetValue();
      }
    }
  }
}

void Entity6978_SetRequest(u32 request, s32 count, u32* params) {
  Entity6978* p = gEntity6978;
  s32 i;

  if (p == NULL) {
    return;
  }

  p->request = request;
  for (i = 0; i < count; i++) {
    p->params[i] = params[i];
  }
}

// request を state に移し, 上げるか下げるかを 1 ステップ進める
// 残差は request を読んで比較し, 1 / 2 ならそのまま 3 / 4 に置き換える分岐の形 (値を r1 に載せて共通の後半へ飛ぶ), Tier A は試済
NON_MATCH s32 Entity6978_Update(Entity6978* p) {
#ifdef NONMATCHING_C
  if (p->state < 3) {
    switch (p->request) {
      case 1:
      case 3: {
        p->state = (p->request == 1) ? p->request : 3;
        p->timer = 0;
        p->durationShift = p->params[0];
        gObjPlttBlendColor = p->params[1] | (p->params[2] << 5) | (p->params[3] << 10);
        gObjPlttFadeSkipMask = p->params[4];
        break;
      }
      case 2:
      case 4: {
        p->state = (p->request == 2) ? p->request : 4;
        p->timer = 0;
        p->durationShift = p->params[0];
        gObjPlttBlendColor = p->params[1] | (p->params[2] << 5) | (p->params[3] << 10);
        gObjPlttFadeSkipMask = p->params[4];
        break;
      }
    }
  } else {
    switch (p->request) {
      case 3:
      case 4: {
        p->state = p->request;
        p->timer = 0;
        p->durationShift = p->params[0];
        gObjPlttBlendColor = p->params[1] | (p->params[2] << 5) | (p->params[3] << 10);
        gObjPlttFadeSkipMask = p->params[4];
        break;
      }
    }
  }
  switch (p->state) {
    case 1:
    case 3: {
      Entity6978_StepUp(p);
      break;
    }
    case 2:
    case 4: {
      Entity6978_StepDown(p);
      break;
    }
  }
  p->request = 0;
#else
  INCFUNC("asm/func/Entity6978_Update.inc");
#endif
}

s32 Entity6978_Destroy(Entity6978* p) { gEntity6978 = NULL; }

// 残差は 0 の読み込み位置だけ (ループの前に 0 を先に読む, 末尾の gObjPlttFadeSkipMask 用の 0 が 0x40 より先)
NON_MATCH s32 Entity6978_Init(Entity6978* p, u16 id) {
#ifdef NONMATCHING_C
  s32 i;

  gEntity6978 = p;
  p->unk_18 = id;
  p->unk_1a = VM_GetNamedArgValue('f', 0);
  p->unk_1c = 0;
  p->state = 0;
  p->timer = 0;
  p->durationShift = 0;
  p->request = 0;
  for (i = 6; i >= 0; i--) {
    p->params[i] = 0;
  }
  gObjBrightness = Q6(1);
  gObjBrightnessApplied = Q6(1);
  gObjPlttBlendColor = 0x1084;
  gObjPlttFadeSkipMask = 0;
  return 0;
#else
  INCFUNC("asm/func/Entity6978_Init.inc");
#endif
}

Entity6978* Entity6978_Create(u32 id) {
  Entity6978* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity6978));
  if (p != NULL) {
    SetEntityRoutine(p, Entity6978_Update, Entity6978_Destroy);
    if (Entity6978_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
