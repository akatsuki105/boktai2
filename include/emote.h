#ifndef __INCLUDE_EMOTE_H__
#define __INCLUDE_EMOTE_H__

#include "entity.h"
#include "gba/gba.h"
#include "mover.h"
#include "particle.h"
#include "sprite.h"
#include "types.h"

// Emote.kind
// まだ未確定の部分が多すぎるので意味を考慮するのは控える
typedef enum {
  EMOTE_0 = 0,  // "!", "?",  variant は 0: "!"(赤), 1: "!"(白), 2: "?", 3: "!"(青)
  EMOTE_1 = 1,  // 吹き出し付き, variant　は 0: "!!", 1: "!!", 2:
  EMOTE_2 = 2,  // スリーピングのZzzで使用
  EMOTE_3 = 3,  // 気絶の⭐️
  EMOTE_4 = 4,  // 吹き出し(❤️)
  EMOTE_5 = 5,  // 吹き出し(♪)
} EmoteKind;

typedef struct Emote {
  WorldPos* pos;         // 0x000, 持ち主の座標, ptcls の pos へ8バイトまとめて写される
  Vec3 unk_4[3];         // 0x004, ptcls ごとに1要素, FUN_080d8de0 が乱数で埋める
  Vec3 unk_1c;           // 0x01C, enemyKind が 0xFF なら mover->unk_30 の複写, それ以外は Emote_CalcPtclOffset の結果か 0
  u16 moverID;           // 0x024, 持ち主の Mover.id の複写, Emote_Remove が第3引数と突き合わせて自分のものか判定する
  u16 offsetX;           // 0x026, 表示オフセット, Emote_Show の offsetX
  u16 offsetY;           // 0x028, 表示オフセット, Emote_Show の offsetY
  u16 unk_2a;            // 0x02A
  u8 animID;             // 0x02C, AuxAnim_SetAnim に渡すアニメ番号
  u8 state;              // 0x02D, 0 なら未使用, 確保時に 1 が入る, EmoteManager_Update が sEmoteStateUpdates の添字に使う
  u8 unk_2e;             // 0x02E, bit0 は Emote_PlayEnemySound で音を鳴らし済みの印
  u8 enemyKind;          // 0x02F, Emote_CalcPtclOffset がオフセットの表を選ぶ ENEK_*, 0xFF なら mover->unk_30 を使う
  u16 unk_30;            // 0x030
  u8 unk_32[3];          // 0x032, ptcls ごとに1要素, 根拠: Emote_ClearPtclState が3要素を 0 で埋める
  u8 unk_35[3];          // 0x035, 同上
  u8 ptclMask;           // 0x038, bit0..2 が立っている枠だけ _Destroy が Particle_Remove する
  s8 idx;                // 0x039, EmoteManager.slots の添字 (activeMask のビット位置), 負なら未使用
  u8 animSet;            // 0x03A, 0 なら EmoteManager.anim_50, 2/3 なら anim_54 と group を使う
  u8 kind;               // 0x03B, see EmoteKind
  s16 unk_3c;            // 0x03C
  s16 unk_3e[3];         // 0x03E, ptcls ごとの間隔, i 番目に (duration / 3) * i が入る
  u8 hasSprite;          // 0x044, 0 以外なら _Destroy が spr を AuxSprite_Remove する
  u8 unk_45[3];          // 0x045
  u16* timer;            // 0x048, ゲージの現在値 (Enemy.unk_192 など), unk_3e と比べて表示を切り替える
  s32 unk_4c[3];         // 0x04C, ptcls ごとに i * 0x11 が入る
  struct Enemy* enemy;   // 0x058, 持ち主の Enemy, 敵以外のエモートでは NULL, Emote_PlayEnemySound が zoneID を gStat と比べる
  AuxSprite spr;         // 0x05C, _Destroy が AuxSprite_Remove に渡す
  Particle ptcls[3];     // 0x088, 根拠: _Destroy の stride 0x28 × 3
  AuxAnimState anim[3];  // 0x100, ptcls と1対1, 根拠: AuxAnim_SetAnim に 0x10 刻みで渡される
  Mover* mover;          // 0x130, 持ち主の Mover, angle と unk_30 が読まれる
} Emote;
static_assert(sizeof(Emote) == 308);

Emote* Emote_Show(Emote* emote, Mover* mover, u8 kind, u8 variant, u16* timer, s16 duration, s32 offsetY, s32 offsetX);
Emote* Emote_Remove(Emote* emote, u32 kind, u32 moverID);
Emote* Emote_RemovePtcl(Emote* emote, u32 kind, u32 moverID);
Emote* FUN_080d9b3c(u8 animID, WorldPos* pos, u32 moverID, s32 offsetX, s32 offsetY, u32 enemyKind, struct Enemy* enemy, Mover* mover);
Emote* FUN_080d9cec(u8 animID, WorldPos* pos, u32 moverID, s32 offsetX, s32 offsetY, u32 enemyKind, u16* timer, s16 duration, u32 param_9, struct Enemy* enemy, Mover* mover);
Emote* FUN_080d9f5c(u8 animID, WorldPos* pos, u32 moverID, s32 offsetY, u32 enemyKind, Mover* mover);
Emote* FUN_080da6c4(u8 animID, WorldPos* pos, u32 moverID, s32 offsetY, u32 enemyKind, u16* timer, s32 duration, s32 count, Mover* mover, struct Enemy* enemy);
bool8 Emote_IsInactive(Emote* elem);

#endif  // __INCLUDE_EMOTE_H__
