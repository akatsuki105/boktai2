#ifndef __INCLUDE_SPRITE_H__
#define __INCLUDE_SPRITE_H__

#include "gba/gba.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "sprite_common.h"
#include "sprite_main.h"
#include "sprite_pltt.h"
#include "types.h"

// SpriteHolder の kind == 1 のときの中身
typedef struct {
  AuxSpriteGfx gfx;       // 0x00, SpriteHolder_InitAux が Video_GetAuxSprite で作る
  AuxSprite sprite;       // 0x1C
  AuxAnimState anim;      // 0x48, SpriteHolder_SetAnim が AuxAnim_SetAnim に渡す
  AuxAnimFile* animFile;  // 0x58, 0 ならアニメーションなし
} SpriteHolderAux;

// SpriteHolder の kind == 2 のときの中身
typedef struct {
  MainSpriteGfx gfx;  // 0x00, SpriteHolder_InitMain が OpenMainSpriteFile で作る
  MainSprite sprite;  // 0x20, MainSprite は自身にアニメーションを持つので animFile はいらない
} SpriteHolderMain;

// SpriteHolder_InitAux / SpriteHolder_InitMain が作るスプライトの器, kind で AuxSprite と MainSprite を使い分ける
// 図鑑専用ではなく、Actor も1つ、PreviewStage は5つ持つ
typedef struct {
  u32 kind;         // 0x00, 0: 未使用, 1: AuxSprite, 2: MainSprite
  u32 animID;       // 0x04, SpriteHolder_SetAnim の pose, MainSprite のときは variant を足した値
  u8 variant;       // 0x08
  bool8 xflip;      // 0x09
  bool8 animEnded;  // 0x0A, AuxSprite のときだけ使う, SpriteHolder_AdvanceAnim がアニメの終わりで 1 にする
  u8 unk_b;
  union {
    SpriteHolderAux aux;
    SpriteHolderMain main;
  } u;                 // 0x0C
  Vec3* pos;           // 0x8C, 使っている方の sprite.pos を指す
  SpriteFlags* flags;  // 0x90, 使っている方の sprite.flags を指す
} SpriteHolder;
static_assert(sizeof(SpriteHolder) == 148);  // 根拠: 0x08055e54

s32 SpriteHolder_SetAnim(SpriteHolder* p, u32 pose, u32 variant, u32 xflip, u32 playMode, u32 auxFlags, u32 mainFlags);
s32 SpriteHolder_AdvanceAnim(SpriteHolder* p);
s32 SpriteHolder_IsAnimEnded(SpriteHolder* p);
s32 SpriteHolder_GetAdvancedCmdIdx(SpriteHolder* p, u32* out);
s32 SpriteHolder_Remove(SpriteHolder* p);
s32 SpriteHolder_InitAux(SpriteHolder* p, SpriteID32 id, u32 animFileID, SpriteFlags flags, Vec3* pos);
s32 SpriteHolder_InitMain(SpriteHolder* p, SpriteID32 id, SpriteFlags flags, Vec3* pos);
s32 SpriteHolder_SetPos(SpriteHolder* p, Vec3* pos);
s32 SpriteHolder_SetFlags(SpriteHolder* p, SpriteFlags flags);
s32 SpriteHolder_ClearFlags(SpriteHolder* p, SpriteFlags flags);
s32 SpriteHolder_TestFlags(SpriteHolder* p, SpriteFlags mask);
s32 SpriteHolder_SetPriority(SpriteHolder* p, u32 priority);
s32 SpriteHolder_SetAffine(SpriteHolder* p, u32 scaleX, u32 scaleY, u32 rotation);

// kind に応じて AuxSprite / MainSprite のパレットIDを設定する, kind == 0 なら -1
s32 SpriteHolder_SetPlttID(SpriteHolder* p, u32 plttID);

#endif  // __INCLUDE_SPRITE_H__
