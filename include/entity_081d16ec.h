#ifndef __INCLUDE_ENTITY_081D16EC_H__
#define __INCLUDE_ENTITY_081D16EC_H__

#include "animation.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "sprite_aux.h"
#include "types.h"

typedef u16 Entity081d16ecItemFlags;  // Entity081d16ecItem.flags
#define E081D16EC_FLAG_0 (1 << 0)     // まだ不明
#define E081D16EC_FLAG_1 (1 << 1)     // まだ不明
#define E081D16EC_FLAG_2 (1 << 2)     // まだ不明
#define E081D16EC_FLAG_3 (1 << 3)     // まだ不明
#define E081D16EC_FLAG_4 (1 << 4)     // まだ不明

// Entity081d16ec が抱える要素。スプライトとヒットボックスを1つずつ持つ
typedef struct Entity081d16ecItem {
  AuxSprite sprite;               // 0x00, Entity081d16ec_Destroy が要素そのものを AuxSprite_Remove に渡す
  AuxAnimState anim;              // 0x2C, FUN_08236fac で再生する
  u8 unk_3c[28];                  // 0x3C
  Vec3 basePos;                   // 0x58, 揺れの基準位置, sprite.pos へ複写する
  HitboxData hitbox;              // 0x60, _Destroy が Hitbox_Unregister に渡す
  u16 state;                      // 0xB0, _Update が PTR_ARRAY_085AE0B8[state](p, item) を呼ぶ
  u16 unk_b2;                     // 0xB2
  u16 slotIndex;                  // 0xB4, FUN_081d0eac が確保時に自分のスロット番号を入れる
  Entity081d16ecItemFlags flags;  // 0xB6, see Entity081d16ecItemFlags
  u8 unk_b8[2];                   // 0xB8
  s16 unk_ba;                     // 0xBA, 0 か 1 でパレットを切り替える
  u8 unk_bc;                      // 0xBC
  u8 unk_bd;                      // 0xBD, 0 でない間はパレット 0x132 を強制して減らす
  u16 unk_be;                     // 0xBE, ヒットボックスの unk_4 に入れる
  u16 unk_c0;                     // 0xC0, bit0 で判定に使うフラグを切り替える
  u16 unk_c2;                     // 0xC2
  u16 unk_c4;                     // 0xC4, unk_c2 がこれ以下なら反応する
  u8 unk_c6;                      // 0xC6
  u8 unk_c7;                      // 0xC7, 0 でない間はスプライトを ±10 揺らして減らす
} Entity081d16ecItem;
static_assert(sizeof(Entity081d16ecItem) == 200);

Entity081d16ecItem* FUN_081d0f08(s32 id);
void FUN_081d11b8(Entity081d16ecItem* item);
bool8 FUN_081d0e94(Entity081d16ecItem* item, Entity081d16ecItemFlags n);
void FUN_081d0e74(Entity081d16ecItem* item, Entity081d16ecItemFlags n);
void FUN_081d0e84(Entity081d16ecItem* item, Entity081d16ecItemFlags n);

#endif  // __INCLUDE_ENTITY_081D16EC_H__
