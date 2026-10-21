#include "emote.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "mover.h"
#include "sprite.h"

// キャラクターの頭上に出るエモートアイコン(の管理構造体)
typedef struct {
  Entity e;              // 0x000, ENTITY_UNK_9
  AuxSpriteGfx gfx_18;   // 0x018, SPRITE_EMOTION_ICONS_0 (吹き出し無し)
  AuxSpriteGfx gfx_34;   // 0x034, SPRITE_EMOTION_ICONS_1 (吹き出し付き)
  AuxAnimFile* anim_50;  // 0x050, ANIM_6830
  AuxAnimFile* anim_54;  // 0x054, ANIM_D41F
  ParticleGroup* group;  // 0x058, PTCL_GROUP_1
  Emote slots[8];        // 0x05C
  u32 activeMask;        // 0x9FC, 使用中の slots のビットマスク
} EmoteManager;
static_assert(sizeof(EmoteManager) == 2560);

IWRAM_DATA EmoteManager* gEmoteManager = NULL;  // 0x0300015C

void Emote_ClearPtclState(Emote* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    p->unk_32[i] = 0;
    p->unk_35[i] = 0;
    p->unk_4c[i] = 0;
    p->unk_3e[i] = 0;
  }
}

// sEmoteKindUpdates[3] (FUN_080d8e98) と FUN_080d8788 の下請け, unk_58 が指す先の +0x490 と gStat を見る, 中身は未解析
NAKED void FUN_080d866c(Emote* p) { INCFUNC("asm/func/FUN_080d866c.inc"); }

// sEmoteKindUpdates[1] (FUN_080d9758) の下請け, emote の unk_3c / unk_32 / spr を見る, 中身は未解析
NAKED s32 FUN_080d8788(EmoteManager* p, Emote* emote) { INCFUNC("asm/func/FUN_080d8788.inc"); }

// sEmoteKindUpdates[0] / [4] の下請け, FUN_080d8788 と同じ形で emote の unk_3c / unk_32 / spr を見る
NAKED void FUN_080d8864(EmoteManager* p, Emote* emote) { INCFUNC("asm/func/FUN_080d8864.inc"); }

// 以下8本は Emote_CalcPtclOffset が第2引数で選ぶオフセット計算の変種, どの見た目に対応するかまでは追えていない
// Emote_CalcPtclOffset の第2引数が 4 か 28 のとき
NAKED void FUN_080d88ec(u32 kind, s32* outX, s32* outY, u32 quadrant) { INCFUNC("asm/func/FUN_080d88ec.inc"); }

// 向きごとの表示オフセットを返す
// Emote_CalcPtclOffset の第2引数が 1 のとき, quadrant は使わない
void FUN_080d8954(s32 kind, s32* outX, s32* outY, u32 quadrant) {
  switch (kind) {
    case 0: {
      *outX = -4;
      *outY = -15;
      break;
    }
    case 1: {
      *outX = -16;
      *outY = -8;
      break;
    }
    case 2: {
      *outX = -4;
      *outY = -4;
      break;
    }
    case 3: {
      *outX = -4;
      *outY = -4;
      break;
    }
  }
}

// 向きごとの表示オフセットを返す
// Emote_CalcPtclOffset の第2引数が 3 か 30 のとき, quadrant は使わない
void FUN_080d8990(s32 kind, s32* outX, s32* outY, u32 quadrant) {
  switch (kind) {
    case 0: {
      *outX = -4;
      *outY = -15;
      break;
    }
    case 1: {
      *outX = -16;
      *outY = -8;
      break;
    }
    case 2: {
      *outX = -4;
      *outY = -4;
      break;
    }
    case 3: {
      *outX = -4;
      *outY = -4;
      break;
    }
  }
}

// Emote_CalcPtclOffset の第2引数が 10 のとき, この変種だけ第6引数を受け取る
NAKED void FUN_080d89cc(u32 kind, s32* outX, s32* outY, u32 quadrant, u32 param_5) { INCFUNC("asm/func/FUN_080d89cc.inc"); }

// Emote_CalcPtclOffset の第2引数が 5 / 6 / 7 のとき
NAKED void FUN_080d8a90(u32 kind, s32* outX, s32* outY, u32 quadrant) { INCFUNC("asm/func/FUN_080d8a90.inc"); }

// Emote_CalcPtclOffset の第2引数が 21 のとき
NAKED void FUN_080d8b58(u32 kind, s32* outX, s32* outY, u32 quadrant) { INCFUNC("asm/func/FUN_080d8b58.inc"); }

// Emote_CalcPtclOffset の第2引数が 27 のとき
NAKED void FUN_080d8c20(u32 kind, s32* outX, s32* outY, u32 quadrant) { INCFUNC("asm/func/FUN_080d8c20.inc"); }

// Emote_CalcPtclOffset の既定の行き先 (上のどれにも当たらない第2引数)
NAKED void FUN_080d8c70(u32 kind, s32* outX, s32* outY, u32 quadrant) { INCFUNC("asm/func/FUN_080d8c70.inc"); }

NAKED void Emote_CalcPtclOffset(u32 kind, u32 param_2, u32 angle, s32* outX, s32* outY, u32 param_6) { INCFUNC("asm/func/Emote_CalcPtclOffset.inc"); }

void nop_080d8ddc(Emote* _) {}

// sEmoteKindUpdates[3] (FUN_080d8e98) の下請け, idx は ptcls の添字 0..2, unk_48 を見る
NAKED void FUN_080d8de0(Emote* p, u32 idx) { INCFUNC("asm/func/FUN_080d8de0.inc"); }

// 以下5本は sEmoteKindUpdates の各エントリ (kind ごとの毎フレーム更新), 各 kind の意味が未解明なので名前は据え置き
// kind 3
NAKED void FUN_080d8e98(Emote* p) { INCFUNC("asm/func/FUN_080d8e98.inc"); }

// kind 2
NAKED void FUN_080d92ac(Emote* p) { INCFUNC("asm/func/FUN_080d92ac.inc"); }

// kind 0
NAKED void FUN_080d94b4(Emote* p) { INCFUNC("asm/func/FUN_080d94b4.inc"); }

// FUN_080d9758 の下請け, unk_32 の bit2 を見る, 表には載っていない
NAKED void FUN_080d96b8(Emote* p) { INCFUNC("asm/func/FUN_080d96b8.inc"); }

// kind 1
NAKED void FUN_080d9758(Emote* p) { INCFUNC("asm/func/FUN_080d9758.inc"); }

// kind 4 と kind 5
NAKED void FUN_080d9800(Emote* p) { INCFUNC("asm/func/FUN_080d9800.inc"); }

void (*const sEmoteKindUpdates[6])(Emote*) = {
    FUN_080d94b4,
    FUN_080d9758,
    FUN_080d92ac,
    FUN_080d8e98,
    FUN_080d9800,
    FUN_080d9800,
};  // 0x085AD2EC

NAKED void Emote_Update(Emote* p) { INCFUNC("asm/func/Emote_Update.inc"); }

NAKED static Emote* EmoteManager_AllocSlot_Internal(EmoteManager* p) { INCFUNC("asm/func/EmoteManager_AllocSlot_Internal.inc"); }

// EmoteManager_AllocSlot_Internal を呼んで NULL ならそのまま返すだけのラッパ, 挟まっている理由は不明
Emote* EmoteManager_AllocSlot(EmoteManager* p) {
  Emote* e = EmoteManager_AllocSlot_Internal(p);

  if (e == NULL) {
    return NULL;
  }

  return e;
}

NAKED Emote* Emote_Remove(Emote* emote, u32 kind, u32 moverID) { INCFUNC("asm/func/Emote_Remove.inc"); }

NAKED Emote* Emote_RemovePtcl(Emote* emote, u32 kind, u32 moverID) { INCFUNC("asm/func/Emote_RemovePtcl.inc"); }

// 以下7本は Emote_Show が animSet / kind で選ぶ生成の入口, 引数の意味が未解明なので名前は据え置き
NAKED Emote* FUN_080d9b3c(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_080d9b3c.inc"); }

NAKED Emote* FUN_080d9cec(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10, u32 param_11) { INCFUNC("asm/func/FUN_080d9cec.inc"); }

NAKED Emote* FUN_080d9f5c(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { INCFUNC("asm/func/FUN_080d9f5c.inc"); }

// スロットを確保して全フィールドを初期化する最奥, 上の入口から呼ばれる
NAKED Emote* FUN_080da110(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10) { INCFUNC("asm/func/FUN_080da110.inc"); }

NAKED Emote* FUN_080da358(WorldPos* pos, u16 moverID, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) { INCFUNC("asm/func/FUN_080da358.inc"); }

NAKED Emote* FUN_080da4f8(WorldPos* pos, u16 moverID, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) { INCFUNC("asm/func/FUN_080da4f8.inc"); }

Emote* FUN_080da698(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9) { return FUN_080da110(param_1, param_2, param_3, param_4, param_5, param_6, param_7, 3, param_8, param_9); }

Emote* FUN_080da6c4(u8 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10) { return FUN_080da110(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }

void (*const sEmoteStateUpdates[3])(Emote*) = {
    nop_080d8ddc,
    Emote_Update,
    NULL,
};  // 0x085AD304

// 残差1命令 (32/31): 原典はハンドラ表の先頭を r7 に抱えるが, こちらは r7 を使わずループ内で引き直す
NON_MATCH s32 EmoteManager_Update(EmoteManager* p) {
#ifdef NONMATCHING_C
  Emote* e = p->slots;

  if (p->activeMask != 0) {
    for (; e <= &p->slots[7]; e++) {
      sEmoteStateUpdates[e->state](e);
    }
  }
  return 0;
#else
  INCFUNC("asm/func/EmoteManager_Update.inc");
#endif
}

NAKED s32 EmoteManager_Destroy(EmoteManager* p) { INCFUNC("asm/func/EmoteManager_Destroy.inc"); }

// スプライト2種とアニメ2本、粒子グループを読み込む
void EmoteManager_LoadResources(EmoteManager* p) {
  Video_GetAuxSprite(&p->gfx_18, SPRITE_EMOTION_ICONS_0);
  Video_GetAuxSprite(&p->gfx_34, SPRITE_EMOTION_ICONS_1);
  p->group = GetParticleGroup(PTCL_GROUP_1);
  p->anim_50 = GetFile(DIR_ANIMATION, ANIM_6830);
  p->anim_54 = GetFile(DIR_ANIMATION, ANIM_D41F);
}

s32 EmoteManager_Init(EmoteManager* p) {
  p->activeMask = 0;
  EmoteManager_LoadResources(p);
  gEmoteManager = p;
  return 0;
}

EmoteManager* EmoteManager_Create(void) {
  if (gEmoteManager == NULL) {
    EmoteManager* p = CreateEntity(ENTITY_UNK_9, sizeof(EmoteManager));
    if (p != NULL) {
      SetEntityRoutine(p, EmoteManager_Update, EmoteManager_Destroy);
      if (EmoteManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEmoteManager;
}

void EmoteManager_Clear(void) { gEmoteManager = NULL; }

bool32 Emote_IsInactive(Emote* elem) {
  if (gEmoteManager == NULL) {
    return TRUE;
  }
  if (elem == NULL) {
    return TRUE;
  }
  if (elem->state == 0) {
    return TRUE;
  }
  return FALSE;
}

// gEmoteManager の activeMask が立っているスロットを走査する, リポジトリ中からも asm からも呼ばれていない
NAKED void FUN_080da8cc(void) { INCFUNC("asm/func/FUN_080da8cc.inc"); }

// param_6 のシグネチャが u16 っぽくみえる, ただしそうすると一致が崩れる
// 可能性としては、
//  - 呼び出し側の書き方に問題がある
//  - そもそも u16 っぽいという私の推測が間違っている
//  - ここでは u16 だが、 宣言側で s32 or s16 でしていた (可能性小)
// がある
NAKED Emote* Emote_Show(Emote* emote, Mover* mover, u8 kind, u8 param_4, u16* param_5, s32 param_6, s32 param_7, s32 param_8) { INCFUNC("asm/func/Emote_Show.inc"); }
