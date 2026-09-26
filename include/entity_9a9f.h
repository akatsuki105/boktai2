#ifndef __INCLUDE_ENTITY_9A9F_H__
#define __INCLUDE_ENTITY_9A9F_H__

#include "entity.h"
#include "types.h"

// 通信セッション1回分の相手の記録, Entity08F4 が unk_18 < 3 の要素だけを数える
typedef struct Entity9A9FRecord {
  u8 unk_00[24];  // 0x00
  u32 unk_18;     // 0x18, Entity08F4 の FUN_081daf44 が 3 未満なら選択肢を1つ増やす
  u8 unk_1c[44];  // 0x1C
} Entity9A9FRecord;
static_assert(sizeof(Entity9A9FRecord) == 72);

// 通信プレイのセッション管理, state と fn の組を Entity9A9F_SetState で進める状態機械
typedef struct Entity9A9F {
  Entity e;                     // 0x000, ENTITY_UNK_1
  s16 playerIdx;                // 0x018, gPlayerPtr の添字 (-1 は該当なし), 根拠: Entity9A9F_Create が 0xFFFF で初期化し、FUN_0823c450 が負を弾いて gPlayerPtr[playerIdx] を引く
  u16 recordCount;              // 0x01A, FUN_081ddbdc が 0 に戻す, Entity08F4 が records[] をこの数だけ走査する
  u8 state;                     // 0x01C, Entity9A9F_SetState が fn と一緒に書く, FUN_081dfa98 が全面的にこれで分岐する
  u8 unk_1d;                    // 0x01D, FUN_081dfa98 が state < 6 のときだけ見る
  u8 killRequested;             // 0x01E, 立つと FUN_081dfa98 が KillEntity する
  s8 retryTimer;                // 0x01F, unk_4c == -3 の間だけ数える, -1 は無効、14 を超えると FUN_081ddbdc へ
  u8 prevState;                 // 0x020, FUN_081ddbdc が state を退避する, Create は 3 を入れる
  u8 unk_21;                    // 0x021
  u8 unk_22;                    // 0x022, Entity9A9F_SetState が状態遷移のたびに 1 を入れる
  u8 unk_23[13];                // 0x023
  u16 unk_30;                   // 0x030, Entity9A9F_Create が 0x1C20 を入れる
  u16 unk_32;                   // 0x032, 同上
  s32 stateTimer;               // 0x034, FUN_081dfa98 が毎フレーム +1、Entity9A9F_SetState が 0 に戻す
  u8 unk_38[4];                 // 0x038
  s32 unk_3c;                   // 0x03C, '.L=5000'
  u8 unk_40[2];                 // 0x040
  u16 unk_42;                   // 0x042, FUN_081dfa98 が FUN_08238e14 に渡す
  u16* unk_44;                  // 0x044, Create が unk_6c を指す, FUN_081dfa98 が FUN_08238da8 に渡す
  s32 unk_48;                   // 0x048, Create は -1, FUN_08238e14 の戻り値
  s32 unk_4c;                   // 0x04C, Create は -1, FUN_08238da8 の戻り値, -3 を再試行の合図にする
  u8 unk_50;                    // 0x050, Create が 0 を入れる
  u8 unk_51;                    // 0x051, Create が 1 を入れる
  u8 unk_52;                    // 0x052, Create が 0 を入れる
  u8 unk_53;                    // 0x053, Create が 0 を入れる
  u8 unk_54[12];                // 0x054
  u8 unk_60[4];                 // 0x060, FUN_080a0864 が unk_60[playerIdx] を読む, 長さは人数からの推定
  u8 unk_64[2];                 // 0x064
  u16 unk_66;                   // 0x066, FUN_0809eb6c: Div(n * unk_66, 0x8C)
  u8 unk_68[4];                 // 0x068, Create が 4要素を 0 にする
  u16 unk_6c[4];                // 0x06C, Create が 4要素を 0xFFFF にする, unk_44 がここを指す
  u8 unk_74[164];               // 0x074
  u8 unk_118[5];                // 0x118, FUN_081de0dc が 0x11C から下へ 5要素に 4 を入れる
  u8 unk_11d[3];                // 0x11D
  u16 unk_120[4];               // 0x120, FUN_081de0dc が 0 にする
  u16 unk_128[4];               // 0x128, 同上
  s16 unk_130[4];               // 0x130, 同上, FUN_081dd2dc が unk_6f4 へ写す
  u16 unk_138[4];               // 0x138, 同上
  u32 unk_140;                  // 0x140, FUN_081de0dc が 0 にする
  u32 unk_144[4];               // 0x144, 同上
  s16 unk_154[4];               // 0x154, '.e' があればそこから、無ければ {2, 1, -1, -2}
  u8 unk_15c[23];               // 0x15C
  u8 unk_173;                   // 0x173, FUN_081de090 が 0xFF を入れる
  u8 unk_174[40];               // 0x174
  u8 unk_19c[4];                // 0x19C, FUN_081de090 が ClearMemory で 0 にする
  s8 unk_1a0;                   // 0x1A0, FUN_081de090 が FUN_0823e1b0() の戻り値を入れる
  u8 unk_1a1[3];                // 0x1A1
  Entity9A9FRecord records[4];  // 0x1A4, Entity08F4 が 0x48 刻みで走査する, 4個で 0x2C4 の手前まで埋まる
  u8 unk_2c4;                   // 0x2C4, FUN_081de090 が 0 にする
  u8 unk_2c5;                   // 0x2C5, 同上
  u8 unk_2c6;                   // 0x2C6, 同上
  u8 unk_2c7[13];               // 0x2C7
  EntityFunc fn;                // 0x2D4, FUN_081dfa98 が毎フレーム呼ぶ, Entity9A9F_SetState が state と一緒に書く
  u8 unk_2d8[4];                // 0x2D8
  s16 unk_2dc;                  // 0x2DC, '.l=0'
  s16 unk_2de;                  // 0x2DE, '.R=0'
  s16 unk_2e0;                  // 0x2E0, '.v=0'
  s16 unk_2e2;                  // 0x2E2, '.r=0'
  s16 unk_2e4;                  // 0x2E4, '.b=0'
  s16 exitScriptID;             // 0x2E6, '.E=0', 終了時に Script_ExecById で実行する, 0 ならソフトリセット
  s16 unk_2e8;                  // 0x2E8, '.Y=0'
  s16 unk_2ea;                  // 0x2EA, '.U=0'
  u8* unk_2ec;                  // 0x2EC, '.s' の後の FUN_0823d340()
  u8* unk_2f0;                  // 0x2F0, '.S' の後の FUN_0823d340()
} Entity9A9F;
static_assert(sizeof(Entity9A9F) == 756);

extern Entity9A9F* gEntity9A9F;  // 0x03002C68

// 自分が何番目の参加者かを返す, セッションが無ければ -1
static inline s32 Entity9A9F_GetPlayerIdx(void) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return -1;
  }
  return p->playerIdx;
}

// 通信相手の記録を1件引く, まだセッションが無ければ NULL
static inline Entity9A9FRecord* Entity9A9F_GetRecord(s32 idx) {
  Entity9A9F* p = gEntity9A9F;

  if (p == NULL) {
    return NULL;
  }
  return &p->records[idx];
}

#endif  // __INCLUDE_ENTITY_9A9F_H__
