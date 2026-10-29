#include "entity.h"
#include "global.h"
#include "preview_stage.h"
#include "video.h"
#include "vm.h"

void FUN_0820fe94(PreviewStage* p, u32 val);
void FUN_0820fe98(PreviewStage* p, u32 modelID);
void FUN_0820feb8(PreviewStage* p, s32 x, s32 y);

// スライド1枚ぶん, '.t' が holdTime / fadeInTime / fadeOutTime を、'.c' が x / y / previewID を同じ添字に書き込む
typedef struct Entity4DDFData {
  s16 holdTime;     // 0x0, 絵を出したまま待つフレーム数, Init で -1 ならリストの終端
  u16 fadeInTime;   // 0x2, 明るさを 0 から 64 まで上げるフレーム数
  u16 fadeOutTime;  // 0x4, 明るさを 64 から 0 まで下げるフレーム数
  u16 x;            // 0x6, 絵の表示位置
  u16 y;            // 0x8, 同上
  s16 previewID;    // 0xA, sPreviewModels の添字, 0x46 なら絵を出さずに待つだけ、-1 でスライドショー終了
} Entity4DDFData;
static_assert(sizeof(Entity4DDFData) == 12);  // 0x08211db8

// スクリプトから貰った絵を1枚ずつ、画面の明るさをフェードさせながら順に見せる, スタッフロールの右下で行われるキャラクターのスライドショーを担当すると思われるがまだ未確定
typedef struct Entity4DDF {
  Entity e;                   // 0x000, ENTITY_UNK_8
  Entity4DDFData slides[64];  // 0x018, _Init が '.t' と '.c' から読む
  PreviewStage* preview;      // 0x318, 絵を出す担当, _Init が PreviewStage_Create(arg, 0) で作る
  s32 lastSlide;              // 0x31C, 最後のスライドの添字 (件数 - 1), _Update はここを超えたら何もしない
  s16 curSlide;               // 0x320, 再生中のスライドの添字
  s16 timer;                  // 0x322, step に入ってからのフレーム数, Entity4DDF_SetStep が 0 に戻す
  u8 step;                    // 0x324, 0: フェードイン, 1: 表示待ち, 2: フェードアウト, 3: 絵なしで待つ, 4: 終了
  u8 unk_325[3];              // 0x325, 読み手も書き手も見つかっていない, padding?
} Entity4DDF;
static_assert(sizeof(Entity4DDF) == 808);

void Entity4DDF_SetStep(Entity4DDF* p, u32 step) {
  p->step = step;
  p->timer = 0;
}

// 絵を出して明るさを fadeInTime かけて上げる, 70 なら絵なしの待ち, -1 なら終了へ
void Entity4DDF_StepFadeIn(Entity4DDF* p, Entity4DDFData* slide) {
  if (p->timer == 0) {
    if (slide->previewID == 70) {
      Entity4DDF_SetStep(p, 3);
      FUN_0820fea8(p->preview);
      return;
    }
    if (slide->previewID == -1) {
      Entity4DDF_SetStep(p, 4);
      FUN_0820fea8(p->preview);
      return;
    }
    FUN_0820fe98(p->preview, slide->previewID);
    FUN_0820feb0(p->preview);
    FUN_0820feb8(p->preview, slide->x, slide->y);
    gObjBrightness = 0;
    gObjPlttBlendColor = 0x1084;
  }
  if (++p->timer >= slide->fadeInTime) {
    gObjBrightness = 64;
    Entity4DDF_SetStep(p, 1);
  } else {
    gObjBrightness = Div(p->timer << 6, slide->fadeInTime);
  }
}

void Entity4DDF_StepHold(Entity4DDF* p, Entity4DDFData* slide) {
  p->timer++;

  if (p->timer >= slide->holdTime) {
    Entity4DDF_SetStep(p, 2);
  }
}

// 明るさを fadeOutTime かけて下げ, 終わったら次のスライドへ
void Entity4DDF_StepFadeOut(Entity4DDF* p, Entity4DDFData* slide) {
  if (p->timer == 0) {
    gObjPlttBlendColor = 0x1084;
  }
  if (++p->timer >= slide->fadeOutTime) {
    Entity4DDF_SetStep(p, 0);
    p->curSlide++;
    gObjBrightness = 0;
  } else {
    gObjBrightness = 64 - Div(p->timer << 6, slide->fadeOutTime);
  }
}

// 絵を出さずに待つ, 3つの時間の合計を過ぎたら次のスライドへ
void Entity4DDF_StepBlank(Entity4DDF* p, Entity4DDFData* slide) {
  FUN_0820fea8(p->preview);

  if (++p->timer > slide->fadeOutTime + slide->fadeInTime + slide->holdTime) {
    Entity4DDF_SetStep(p, 0);
    p->curSlide++;
  }
}

void Entity4DDF_StepEnd(Entity4DDF* p, Entity4DDFData* slide) { FUN_0820fea8(p->preview); }

__attribute__((section(".rodata.faraddr"))) void (*const PTR_ARRAY_08252738[6])(Entity4DDF*, Entity4DDFData*) = {
    Entity4DDF_StepFadeIn,
    Entity4DDF_StepHold,
    Entity4DDF_StepFadeOut,
    Entity4DDF_StepBlank,
    Entity4DDF_StepEnd,
    NULL,
};  // 0x08252738

// step に応じた処理を今のスライドで呼ぶ
s32 Entity4DDF_Update(Entity4DDF* p) {
  void (*steps[6])(Entity4DDF*, Entity4DDFData*);

  memcpy(steps, PTR_ARRAY_08252738, sizeof(steps));
  if (p->curSlide <= p->lastSlide) {
    Entity4DDFData* slide = &p->slides[p->curSlide];

    if (steps[p->step] != NULL) {
      steps[p->step](p, slide);
    }
  }
  return 0;
}

s32 Entity4DDF_Destroy(Entity4DDF* _) { return 0; }

// '.t' と '.c' からスライドの並びを読み, PreviewStage を作る
s32 Entity4DDF_Init(Entity4DDF* p, void* _) {
  Entity4DDFData* slide;
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
  p->preview = PreviewStage_Create((u32)_, 0);
  FUN_0820fea8(p->preview);
  FUN_0820fe94(p->preview, 1);
  return 0;
}

Entity4DDF* Entity4DDF_Create(void* _) {
  Entity4DDF* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity4DDF));
  if (p != NULL) {
    SetEntityRoutine(p, Entity4DDF_Update, Entity4DDF_Destroy);
    if (Entity4DDF_Init(p, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
