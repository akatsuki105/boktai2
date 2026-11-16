#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// スプライト (OBJ) のパレットを受け持つシングルトン, HashName("OBJパレットキャラ"), 扱うのは画面のフェードだけ
// BG 側の BgPlttController と対で, 画面全体のフェードは StartBgObjPlttFade や Scr_FadeScreenEx が両方へ同じ指示を出す
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_11
  u16 unk_18;         // 0x18, _Create の引数, 書き込むだけで読み手が見つかっていない
  u16 unk_1a;         // 0x1A, '.f', 読み手が見つかっていない
  u16 unk_1c;         // 0x1C, _Init が 0 を入れるだけ
  u16 state;          // 0x1E, いま進めているフェード, 0 なし, 1/3 フェードイン, 2/4 フェードアウト, 5 フェードアウトし終えて暗いまま, 3 以上の間は 3/4 しか受け付けない
  u16 timer;          // 0x20, フェードの経過フレーム
  u16 durationShift;  // 0x22, フェードの長さの log2, 1 << durationShift フレームで終わる
  u16 request;        // 0x24, OBJ パレットコマンドで届いたフェードの指示 (1..4, state と同じ番号), _Update が受け取って 0 に戻す
  u16 params[7];      // 0x26, [0] フェードの長さの log2, [1..3] フェード色の R/G/B, [4] フェードから外すパレットのマスク (gObjPlttFadeSkipMask)
} ObjPlttController;
static_assert(sizeof(ObjPlttController) == 52);

COMMON_DATA ObjPlttController* gObjPlttController = NULL;  // 0x03002B30

void ObjPlttController_ClearPtr(void) { gObjPlttController = NULL; }

// フェードアウト, スプライトをフェード色へ寄せていく, 4 で始めたものは終わったあとも暗いまま止める
void ObjPlttController_StepDown(ObjPlttController* p) {
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

// フェードイン, フェード色から元の色へ戻していく
void ObjPlttController_StepUp(ObjPlttController* p) {
  gObjBrightness = (p->timer << 6) >> p->durationShift;
  p->timer++;
  if (p->timer >= 1 << p->durationShift) {
    gObjBrightness = Q6(1);
    p->state = 0;
  }
}

// 0x9EC0, HashName("OBJパレットコマンド")
void Cmd_SendObjPlttCommand(void) {
  ObjPlttController* p = gObjPlttController;

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

// フェードの指示を渡す, 次の _Update で始まる, BG 側と違って積まずに上書きする
void ObjPlttController_SetRequest(u32 request, s32 count, u32* params) {
  ObjPlttController* p = gObjPlttController;
  s32 i;

  if (p == NULL) {
    return;
  }

  p->request = request;
  for (i = 0; i < count; i++) {
    p->params[i] = params[i];
  }
}

// 届いた指示でフェードを始め, 進めているフェードを1フレーム進める
// 残差は request を読んで比較し, 1 / 2 ならそのまま 3 / 4 に置き換える分岐の形 (値を r1 に載せて共通の後半へ飛ぶ), Tier A は試済
NON_MATCH s32 ObjPlttController_Update(ObjPlttController* p) {
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
      ObjPlttController_StepUp(p);
      break;
    }
    case 2:
    case 4: {
      ObjPlttController_StepDown(p);
      break;
    }
  }
  p->request = 0;
#else
  INCFUNC("asm/func/ObjPlttController_Update.inc");
#endif
}

s32 ObjPlttController_Destroy(ObjPlttController* p) { gObjPlttController = NULL; }

s32 ObjPlttController_Init(ObjPlttController* p, u16 id) {
  s32 i;

  gObjPlttController = p;
  p->unk_18 = id;
  p->unk_1a = VM_GetNamedArgValue('f', 0);
  p->unk_1c = 0;
  p->state = 0;
  p->timer = 0;
  p->durationShift = 0;
  p->request = 0;
  for (i = 0; i < 7; i++) {
    p->params[i] = 0;
  }
  gObjBrightness = Q6(1);
  gObjBrightnessApplied = Q6(1);
  gObjPlttBlendColor = 0x1084;
  gObjPlttFadeSkipMask = 0;
  return 0;
}

// 0x6978, HashName("OBJパレットキャラ")
ObjPlttController* ObjPlttController_Create(u32 id) {
  ObjPlttController* p = CreateEntity(ENTITY_UNK_11, sizeof(ObjPlttController));
  if (p != NULL) {
    SetEntityRoutine(p, ObjPlttController_Update, ObjPlttController_Destroy);
    if (ObjPlttController_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
