#include "entity.h"
#include "global.h"
#include "video.h"
#include "vm.h"

void Video_SetBLDYDirect(u32 bldy);

// オープニングで「続・ボクらの太陽」のタイトルロゴを浮かび上がらせて消す, BLDCNT と BLDALPHA / BLDY を指定フレーム数かけて動かし、終わると自分を消すブレンド演出
// スクリプトが渡すインスタンスIDは HashName("出現") = 0xD81E (係数 0→16) と HashName("消滅") = 0x26A9 (16→0), Scr_0x0334 がタイトルの一枚絵を浮かび上がらせて消すのに使う
typedef struct {
  Entity e;      // 0x00, ENTITY_UNK_11
  u8 mode;       // 0x18, '.m=1', 1 なら BLDALPHA, それ以外は BLDY を動かす
  s8 from[2];    // 0x19, '.i', 補間の初期値 (BLDY は [0] だけ使う)
  s8 delta[2];   // 0x1B, '.a' から from を引いた差分, timer/duration を掛けて from に足す
  u8 unk_1d[3];  // 0x1D, 触られていない
  u16 target1;   // 0x20, '.s=0', BLDCNT の第1対象
  u16 target2;   // 0x22, '.d=0', BLDCNT の第2対象
  u32 timer;     // 0x24, 毎フレーム +1, duration 以上になると自分を消す
  u32 duration;  // 0x28, '.t=60', 0 を渡されたときも 60 になる
} OpTitleFader;
static_assert(sizeof(OpTitleFader) == 44);

s32 OpTitleFader_Update(OpTitleFader* p) {
  s32 value;

  Video_SetBLDCNTDirect(p->mode, p->target1, p->target2);
  value = p->from[0] + Div(p->delta[0] * p->timer, p->duration);
  if (p->mode == 1) {
    Video_SetBLDALPHADirect(value, p->from[1] + Div(p->delta[1] * p->timer, p->duration));
  } else {
    Video_SetBLDYDirect(value);
  }
  if (p->timer >= p->duration) {
    KillEntity(&p->e);
  }
  p->timer++;
  return 0;
}

s32 OpTitleFader_Destroy(OpTitleFader* p) { return 0; }

// 命令数は一致, 残差は from + 1 がループ外へ出る点とレジスタ
NON_MATCH s32 OpTitleFader_Init(OpTitleFader* p) {
#ifdef NONMATCHING_C
  s8* from;
  s8* v;
  s8* delta;
  s32 i;

  p->mode = VM_GetNamedArgValue('m', 1);
  if (VM_SeekToNamedArg('i')) {
    from = p->from;
    delta = p->delta;
    v = from;
    do {
      u32 value = (u32)VM_GetPC();

      if (value) {
        value = VM_GetValue();
      }
      *v = value;
      v++;
    } while ((s32)v <= (s32)(from + 1));
  } else {
    from = p->from;
    delta = p->delta;
    v = from + 1;
    do {
      *v = 0;
      v--;
    } while ((s32)v >= (s32)from);
  }
  if (VM_SeekToNamedArg('a')) {
    v = delta;
    for (i = 0; i < 2; i++) {
      u32 value = (u32)VM_GetPC();

      if (value) {
        value = VM_GetValue() - from[i];
      }
      *v = value;
      v++;
    }
  } else {
    v = delta + 1;
    do {
      *v = 0;
      v--;
    } while ((s32)v >= (s32)delta);
  }
  p->target1 = VM_GetNamedArgValue('s', 0);
  p->target2 = VM_GetNamedArgValue('d', 0);
  p->duration = VM_GetNamedArgValue('t', 60);
  p->timer = 0;
  if (p->duration == 0) {
    p->duration = 60;
  }
  Video_SetBLDCNTDirect(p->mode, p->target1, p->target2);
  if (p->mode == 1) {
    Video_SetBLDALPHADirect(p->from[0], p->from[1]);
  } else {
    Video_SetBLDYDirect(p->from[0]);
  }
  return 0;
#else
  INCFUNC("asm/func/OpTitleFader_Init.inc");
#endif
}

OpTitleFader* OpTitleFader_Create(void) {
  OpTitleFader* p = CreateEntity(ENTITY_UNK_11, sizeof(OpTitleFader));

  if (p != NULL) {
    SetEntityRoutine(p, OpTitleFader_Update, OpTitleFader_Destroy);
    if (OpTitleFader_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
