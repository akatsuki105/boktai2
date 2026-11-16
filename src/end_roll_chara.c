#include "entity.h"
#include "global.h"
#include "specimen.h"
#include "video.h"
#include "vm.h"

// スライド1枚ぶん, '.t' が holdTime / fadeInTime / fadeOutTime を、'.c' が x / y / previewID を同じ添字に書き込む
typedef struct EndRollCharaSlide {
  s16 holdTime;     // 0x0, 絵を出したまま待つフレーム数, Init で -1 ならリストの終端
  u16 fadeInTime;   // 0x2, 明るさを 0 から 64 まで上げるフレーム数
  u16 fadeOutTime;  // 0x4, 明るさを 64 から 0 まで下げるフレーム数
  u16 x;            // 0x6, 絵の表示位置
  u16 y;            // 0x8, 同上
  s16 previewID;    // 0xA, sSpecimenModels の添字, 0x46 なら絵を出さずに待つだけ、-1 でスライドショー終了
} EndRollCharaSlide;
static_assert(sizeof(EndRollCharaSlide) == 12);  // 0x08211db8

// スクリプトから貰った絵を1枚ずつ、画面の明るさをフェードさせながら順に見せる, スタッフロールの右下に登場キャラを順に出すスライドショー
// Scr_GameClear (奇数周) が作り, '.t' はスタッフロールの文字 (Narration) と同じ時間割 Bin_18F6, インスタンスIDは HashName("エンドロールキャラ") = 0x79C0
typedef struct EndRollChara {
  Entity e;                      // 0x000, ENTITY_UNK_8
  EndRollCharaSlide slides[64];  // 0x018, _Init が '.t' と '.c' から読む
  Specimen* preview;             // 0x318, 絵を出す担当, _Init が Specimen_Create(arg, 0) で作る
  s32 lastSlide;                 // 0x31C, 最後のスライドの添字 (件数 - 1), _Update はここを超えたら何もしない
  s16 curSlide;                  // 0x320, 再生中のスライドの添字
  s16 timer;                     // 0x322, step に入ってからのフレーム数, EndRollChara_SetStep が 0 に戻す
  u8 step;                       // 0x324, 0: フェードイン, 1: 表示待ち, 2: フェードアウト, 3: 絵なしで待つ, 4: 終了
  u8 unk_325[3];                 // 0x325, 読み手も書き手も見つかっていない, padding?
} EndRollChara;
static_assert(sizeof(EndRollChara) == 808);

void Specimen_SetPosOverridden(Specimen* p, u32 val);
void Specimen_ChangeModel(Specimen* p, u32 modelID);
void Specimen_SetPos(Specimen* p, s32 x, s32 y);

const STRING_DATA char gString_082526c0[] = "../../skoba/enemy/system/eneinline.h";
const STRING_DATA char gString_082526e8[] = "../../skoba/enemy/system/eneinline.h";
const STRING_DATA char gString_08252710[] = "../../skoba/enemy/system/eneinline.h";  // 0x08252710

void EndRollChara_SetStep(EndRollChara* p, u32 step) {
  p->step = step;
  p->timer = 0;
}

// 絵を出して明るさを fadeInTime かけて上げる, 70 なら絵なしの待ち, -1 なら終了へ
void EndRollChara_StepFadeIn(EndRollChara* p, EndRollCharaSlide* slide) {
  if (p->timer == 0) {
    if (slide->previewID == 70) {
      EndRollChara_SetStep(p, 3);
      Specimen_Hide(p->preview);
      return;
    }
    if (slide->previewID == -1) {
      EndRollChara_SetStep(p, 4);
      Specimen_Hide(p->preview);
      return;
    }
    Specimen_ChangeModel(p->preview, slide->previewID);
    Specimen_Show(p->preview);
    Specimen_SetPos(p->preview, slide->x, slide->y);
    gObjBrightness = 0;
    gObjPlttBlendColor = 0x1084;
  }
  if (++p->timer >= slide->fadeInTime) {
    gObjBrightness = 64;
    EndRollChara_SetStep(p, 1);
  } else {
    gObjBrightness = Div(p->timer << 6, slide->fadeInTime);
  }
}

void EndRollChara_StepHold(EndRollChara* p, EndRollCharaSlide* slide) {
  p->timer++;

  if (p->timer >= slide->holdTime) {
    EndRollChara_SetStep(p, 2);
  }
}

// 明るさを fadeOutTime かけて下げ, 終わったら次のスライドへ
void EndRollChara_StepFadeOut(EndRollChara* p, EndRollCharaSlide* slide) {
  if (p->timer == 0) {
    gObjPlttBlendColor = 0x1084;
  }
  if (++p->timer >= slide->fadeOutTime) {
    EndRollChara_SetStep(p, 0);
    p->curSlide++;
    gObjBrightness = 0;
  } else {
    gObjBrightness = 64 - Div(p->timer << 6, slide->fadeOutTime);
  }
}

// 絵を出さずに待つ, 3つの時間の合計を過ぎたら次のスライドへ
void EndRollChara_StepBlank(EndRollChara* p, EndRollCharaSlide* slide) {
  Specimen_Hide(p->preview);

  if (++p->timer > slide->fadeOutTime + slide->fadeInTime + slide->holdTime) {
    EndRollChara_SetStep(p, 0);
    p->curSlide++;
  }
}

void EndRollChara_StepEnd(EndRollChara* p, EndRollCharaSlide* slide) { Specimen_Hide(p->preview); }

__attribute__((section(".rodata.faraddr"))) void (*const PTR_ARRAY_08252738[6])(EndRollChara*, EndRollCharaSlide*) = {
    EndRollChara_StepFadeIn,
    EndRollChara_StepHold,
    EndRollChara_StepFadeOut,
    EndRollChara_StepBlank,
    EndRollChara_StepEnd,
    NULL,
};  // 0x08252738

// step に応じた処理を今のスライドで呼ぶ
s32 EndRollChara_Update(EndRollChara* p) {
  void (*steps[6])(EndRollChara*, EndRollCharaSlide*);

  memcpy(steps, PTR_ARRAY_08252738, sizeof(steps));
  if (p->curSlide <= p->lastSlide) {
    EndRollCharaSlide* slide = &p->slides[p->curSlide];

    if (steps[p->step] != NULL) {
      steps[p->step](p, slide);
    }
  }
  return 0;
}

s32 EndRollChara_Destroy(EndRollChara* _) { return 0; }

// '.t' と '.c' からスライドの並びを読み, Specimen を作る
s32 EndRollChara_Init(EndRollChara* p, void* _) {
  EndRollCharaSlide* slide;
  s32 i;

  slide = p->slides;
  if (VM_SeekToNamedArg('t')) {
    VM_SetPC(VM_GetValueSafe2_Proxy());
    for (i = 0; i < 64; i++) {
      slide->holdTime = VM_GetValue();
      VM_GetValue();
      VM_GetValue();
      VM_GetValue();
      VM_GetValue();
      slide->fadeInTime = VM_GetValue();
      slide->fadeOutTime = VM_GetValue();
      if (slide->holdTime == -1) {
        p->lastSlide = i - 1;
        break;
      }
      slide++;
    }
  }

  slide = p->slides;
  if (VM_SeekToNamedArg('c')) {
    VM_SetPC(VM_GetValueSafe2_Proxy());
    for (i = 0; i < 64; i++) {
      slide->x = VM_GetValue();
      slide->y = VM_GetValue();
      slide->previewID = VM_GetValue();
      if (slide->previewID == -1) {
        break;
      }
      slide++;
    }
  }

  p->timer = 0;
  p->curSlide = 0;
  p->step = 0;
  p->preview = Specimen_Create((u32)_, 0);
  Specimen_Hide(p->preview);
  Specimen_SetPosOverridden(p->preview, 1);
  return 0;
}

EndRollChara* EndRollChara_Create(void* _) {
  EndRollChara* p = CreateEntity(ENTITY_UNK_8, sizeof(EndRollChara));
  if (p != NULL) {
    SetEntityRoutine(p, EndRollChara_Update, EndRollChara_Destroy);
    if (EndRollChara_Init(p, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
