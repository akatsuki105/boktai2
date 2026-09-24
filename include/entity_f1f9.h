#ifndef __INCLUDE_ENTITY_F1F9_H__
#define __INCLUDE_ENTITY_F1F9_H__

#include "hitbox.h"
#include "shadow.h"
#include "sprite_aux.h"
#include "types.h"

// EntityF1F9 が抱える要素。スプライト・ヒットボックス・影を1つずつ持つ
typedef struct EntityF1F9Item {
  AuxSprite sprite;   // 0x000, EntityF1F9_Destroy が要素そのものを AuxSprite_Remove に渡す
  u8 unk_2c[44];      // 0x02C
  HitboxData hitbox;  // 0x058, _Destroy が Hitbox_Unregister に渡す
  AuxShadow shadow;   // 0x0A8, shadowId が -1 でなければ _Destroy が AuxShadow_Remove に渡す
  Vec3 basePos;       // 0x114, 揺れの基準位置。sprite.pos へ複写する
  u8 unk_11c[16];     // 0x11C
  s32 unk_12c;        // 0x12C, 1フレーム前の距離の2乗
  s32 unk_130;        // 0x130, プレイヤーとの距離の2乗
  s32 unk_134;        // 0x134, この距離まで近づかれると反応する
  u8 unk_138[2];      // 0x138
  u16 unk_13a;        // 0x13A, 1マスぶんの距離
  u8 unk_13c;         // 0x13C, 全体のマス数
  u8 unk_13d;         // 0x13D, 現在のマス番号
  u8 unk_13e[2];      // 0x13E
  s16 unk_140;        // 0x140, 移動の始点
  s16 unk_142;        // 0x142, 現在位置
  u8 unk_144[4];      // 0x144
  u16 state;          // 0x148, _Update が PTR_FUN_081D5D14_085AE104[state](p, item) を呼ぶ
  u8 unk_14a[2];      // 0x14A
  u16 flags;          // 0x14C, FUN_081d5820 が立て、FUN_081d5834 が落とし、FUN_081d5848 が読む
  s8 shadowId;        // 0x14E, -1 なら影なし。_Destroy が影を外して -1 を書き戻す
  u8 unk_14f;         // 0x14F
  u16 unk_150;        // 0x150, ヒットボックスの unk_4 に入れる
  u8 unk_152;         // 0x152
  u8 unk_153;         // 0x153, 0 でない間はパレット 0x132 を強制して減らす
  u16 unk_154;        // 0x154, FUN_081d5d18 が毎フレーム 1 足すカウンタ
  u8 unk_156;         // 0x156, 立っていると FUN_081d5d18 が状態を初期化して落とす
  u8 unk_157;         // 0x157, 0 でない間はスプライトを ±10 揺らして減らす
} EntityF1F9Item;
static_assert(sizeof(EntityF1F9Item) == 344);

#endif  // __INCLUDE_ENTITY_F1F9_H__
