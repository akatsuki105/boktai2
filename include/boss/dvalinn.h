#ifndef __INCLUDE_BOSS_DVALINN_H__
#define __INCLUDE_BOSS_DVALINN_H__

#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "sprite_aux.h"
#include "types.h"

// 8枚のスプライトそれぞれに2種類のヒットボックスを持たせる設置型の仕掛け, おそらくドヴァリンによる水面からのタコ足攻撃
typedef struct Entity08202cd8 {
  Entity e;                                 // 0x000, ENTITY_UNK_9
  u32 unk_18;                               // 0x018, _Init で 0
  u32 unk_1c;                               // 0x01C, _Init で 0
  u16 unk_20;                               // 0x020, _Init で 0
  u16 unk_22;                               // 0x022, _Init で 0
  u8 unk_24;                                // 0x024, _Init で 0
  u8 unk_25;                                // 0x025, _Init で 0
  u16 plttID;                               // 0x026, gfx0->plttID
  AuxSprite sprites[8];                     // 0x028, i<3 は gfx1、それ以外は gfx0 で AuxSprite_Add する
  u8 unk_188[8];                            // 0x188
  HitboxData hitboxA[8];                    // 0x190, Hitbox_SetHandler(0x082029B8) と Hitbox_SetAttack を受ける組
  HitboxData hitboxB[8];                    // 0x410, Hitbox_SetHandler(0x082029BC) と Hitbox_SetPowerAndAttributes を受ける組
  u8 unk_690;                               // 0x690, 叩きつけ攻撃の段階, 0: 狙う 1: 振り下ろす 2: 当たった 3: 終わり
  u8 unk_691;                               // 0x691
  u8 unk_692;                               // 0x692, unk_690 の段階に入ってからのフレーム数
  u8 unk_693;                               // 0x693
  Vec3 pos;                                 // 0x694, Create の引数が指すマスの衝突タイルから作り、全スプライトの pos へ複写する
  AuxSpriteGfx gfx0;                        // 0x69C, SPRITE_DVALIN_2E78
  AuxSpriteGfx gfx1;                        // 0x6B8, SPRITE_DVALIN_2E7B
  void (*fn)(struct Entity08202cd8*, s32);  // 0x6D4, FUN_08202910 が p と加算前の unk_18 を渡して呼ぶ
  u8 unk_6d8;                               // 0x6D8, _Init で 1
  u8 unk_6d9;                               // 0x6D9
  u8 unk_6da;                               // 0x6DA, _Update が 0 を入れる
  u8 unk_6db;                               // 0x6DB, _Init で 0
  u8 unk_6dc;                               // 0x6DC, _Init で 0
  u8 unk_6dd;                               // 0x6DD, _Init で 0
  u8 unk_6de[2];                            // 0x6DE
  u16 unk_6e0;                              // 0x6E0, Create の第3引数, Hitbox_SetAttack に渡す
  u16 unk_6e2;                              // 0x6E2, Create の第2引数, Hitbox_SetPowerAndAttributes に渡す
  Vec3 target;                              // 0x6E4, 狙ったときのプレイヤーの位置
  s32 unk_6ec;                              // 0x6EC, _Init が 0 の4バイトを書く
} Entity08202cd8;
static_assert(sizeof(Entity08202cd8) == 1776);

Entity08202cd8* Entity08202cd8_Create(Vec3* pos, s32 param_2, s32 param_3);
void FUN_08201054(Entity08202cd8* p, Vec3* pos);
void FUN_082010b4(Entity08202cd8* p);

#endif  // __INCLUDE_BOSS_DVALINN_H__
