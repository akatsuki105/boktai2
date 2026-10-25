#ifndef __INCLUDE_PREVIEW_STAGE_H__
#define __INCLUDE_PREVIEW_STAGE_H__

#include "entity.h"
#include "gba/gba.h"
#include "sprite.h"
#include "types.h"

// ファイル名, 及び PreviewStage という構造体名はまだ暫定

typedef struct PreviewStage {
  Entity e;                          // 0x000, ENTITY_UNK_8
  s32 swayAngle;                     // 0x018, PreviewStage_Update が毎フレーム model->swaySpeed を足し、>>5 して sin テーブルの角度にする
  u32 modelID;                       // 0x01C, sPreviewModels[modelID]
  u32 stateTimer;                    // 0x020, state に入ってからのフレーム数, FUN_0820f84c などが数え、state が変わると 0 に戻る
  u8 state;                          // 0x024, onLoad / onUpdate を持つ魔物だけが使う演出の段階 (FUN_0820f84c は 0..3)
  bool8 hidden;                      // 0x025, 1 の間は _Update が parts と subSprite を全部隠して何もしない, FUN_0820fea8 が 1、FUN_0820feb0 が 0
  u16 posOverridden;                 // 0x026, 非0なら pos を model->x / model->y で上書きしない, FUN_0820fe94 が入れる
  SpriteHolder parts[5];             // 0x028, スプライトの器, 単体の魔物は [0] だけ、多関節の魔物は sPreviewSegments に沿って5つ使う
  AuxSprite subSprite;               // 0x30C, model->subSprite が非0のときだけ出す重ね絵 (メタスプライト 5/6/7)
  AuxSpriteGfx subSpriteGfx;         // 0x338, SPRITE_EFF_1C1B
  Vec3 pos;                          // 0x354, model->x + 64, model->y + 84, FUN_0820feb8 が直接入れることもある
  u8 unk_35c[0x364 - 0x35C];         // 0x35C, 読み手も書き手も見つかっていない
  u16 poseBase;                      // 0x364, model->poseBase の写し, SpriteHolder_SetAnim の第2引数になる
  u8 frameIdx;                       // 0x366, FUN_0820efc4 が model->direction から作るコマ番号
  u8 hFlip;                          // 0x367, 同上の左右反転
  bool8 reloadRequested;             // 0x368, FUN_0820fe98 が立て、_Update が読み込み直して 0 に戻す
  u8 unk_369[0x370 - 0x369];         // 0x369, 読み手も書き手も見つかっていない
  const struct PreviewModel* model;  // 0x370, &sPreviewModels[modelID], 毎フレーム入れ直す
} PreviewStage;
static_assert(sizeof(PreviewStage) == 884);

PreviewStage* PreviewStage_Create(u32 arg, u32 _);

void FUN_0820feb0(PreviewStage* p);
void FUN_0820fea8(PreviewStage* p);

#endif  // __INCLUDE_PREVIEW_STAGE_H__
