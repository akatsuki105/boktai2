#ifndef __INCLUDE_EMOTE_H__
#define __INCLUDE_EMOTE_H__

#include "entity.h"
#include "gba/gba.h"
#include "mover.h"
#include "particle.h"
#include "sprite.h"
#include "types.h"

// Emote.kind
typedef enum {
  EMOTE_0 = 0,
  EMOTE_1 = 1,
  EMOTE_2 = 2,
  EMOTE_3 = 3,
  EMOTE_4 = 4,
  EMOTE_5 = 5,
} EmoteKind;

typedef struct Emote {
  WorldPos* pos;         // 0x000, 持ち主の座標, ptcls の pos へ8バイトまとめて写される
  u16 unk_4[3];          // 0x004
  u8 unk_a[18];          // 0x00A
  u32 unk_1c[2];         // 0x01C, unk_2f が 0xFF なら unk_130 の +0x30 から8バイト複写し, それ以外は 0 で埋める
  u16 moverID;           // 0x024, 持ち主の Mover.id の複写, Emote_Remove が第3引数と突き合わせて自分のものか判定する
  u8 unk_26;             // 0x026
  u8 unk_27;             // 0x027
  u16 unk_28;            // 0x028
  u8 unk_2a[2];          // 0x02A
  u8 animID;             // 0x02C, AuxAnim_SetAnim に渡すアニメ番号
  u8 state;              // 0x02D, 0 なら未使用, 確保時に 1 が入る, EmoteManager_Update が sEmoteStateUpdates の添字に使う
  u8 unk_2e;             // 0x02E
  u8 unk_2f;             // 0x02F, 0xFF なら色を unk_130 から取る, unk_1c と対
  u8 unk_30[2];          // 0x030
  u8 unk_32[3];          // 0x032, ptcls ごとに1要素, 根拠: Emote_ClearPtclState が3要素を 0 で埋める
  u8 unk_35[3];          // 0x035, 同上
  u8 ptclMask;           // 0x038, bit0..2 が立っている枠だけ _Destroy が Particle_Remove する
  s8 idx;                // 0x039, EmoteManager.slots の添字 (activeMask のビット位置), 負なら未使用
  u8 animSet;            // 0x03A, 0 なら EmoteManager.anim_50, 2/3 なら anim_54 と group を使う
  u8 kind;               // 0x03B, see EmoteKind
  u8 unk_3c[2];          // 0x03C
  u16 unk_3e[3];         // 0x03E, ptcls ごとの間隔, i 番目に (第7引数 / 3) * i が入る
  u8 hasSprite;          // 0x044, 0 以外なら _Destroy が spr を AuxSprite_Remove する
  u8 unk_45[3];          // 0x045
  u32 unk_48;            // 0x048
  u32 unk_4c[3];         // 0x04C, ptcls ごとに i * 0x11 が入る
  unknown* unk_58;       // 0x058, NULL でなければ FUN_080d866c が +0x490 を読む, 0x494 バイト以上の何か
  AuxSprite spr;         // 0x05C, _Destroy が AuxSprite_Remove に渡す
  Particle ptcls[3];     // 0x088, 根拠: _Destroy の stride 0x28 × 3
  AuxAnimState anim[3];  // 0x100, ptcls と1対1, 根拠: AuxAnim_SetAnim に 0x10 刻みで渡される
  unknown* unk_130;      // 0x130, +5 のバイトと +0x30 からの8バイトが読まれる
} Emote;
static_assert(sizeof(Emote) == 308);

Emote* Emote_Show(Emote* emote, Mover* mover, u8 kind, u8 param_4, u16* param_5, s32 param_6, s32 param_7, s32 param_8);
Emote* Emote_Remove(Emote* emote, u32 kind, u32 moverID);
Emote* Emote_RemovePtcl(Emote* emote, u32 kind, u32 moverID);

#endif  // __INCLUDE_EMOTE_H__
