#ifndef __INCLUDE_SOLAR_GENERATOR_H__
#define __INCLUDE_SOLAR_GENERATOR_H__

#include "eff_082473e0.h"
#include "entity.h"
#include "hitbox.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "types.h"

// 太陽ジェネレーター(太陽の光をビームとして出して攻撃する装置, 敵に攻撃されるとオフになるが、プレイヤーがエンチャント攻撃を当てると再びオンになる)
typedef struct Generator {
  Entity e;                                   // 0x000, ENTITY_UNK_8
  AuxSprite sprite;                           // 0x018, SPRITE_GENERATOR
  AuxSpriteGfx gfx;                           // 0x044, SPRITE_GENERATOR
  Vec3 pos;                                   // 0x060, Generator_Create の第1引数を8バイト複写したもの,Hitbox_SetPos に渡す
  HitboxData hitbox;                          // 0x068, Generator_InitHitbox が Hitbox_Init / _SetPowerAndAttributes / _SetPos / _SetHandler する
  AuxAnimState anim;                          // 0x0B8, ANIM_3449, animIdx は 1 or 3
  AuxAnimFile* animFile;                      // 0x0C8, ANIM_3449
  u8 animVariant;                             // 0x0CC
  AuxAnimPlayFlags animFlags;                 // 0x0CD
  u8 unk_ce;                                  // 0x0CE, Generator_Init の第6引数,読み手が見つかっていない
  u8 state;                                   // 0x0CF, Generator_SetState が書き、 sGeneratorUpdates[state] を updateCallback に入れる,3 で GENERATOR_ENABLED, 5 で GENERATOR_DISABLED を鳴らす
  u16 stateTimer;                             // 0x0D0, Generator_SetState が状態遷移のたびに 0 に戻す
  u16 unk_d2;                                 // 0x0D2, Init が 0、state が 4 のときは anim の先頭ハーフワードを入れる
  u16 unk_d4;                                 // 0x0D4, Generator_Init の第7引数
  u8 unk_d6[2];                               // 0x0D6
  s16 unk_d8;                                 // 0x0D8, Div(unk_d4, 6)
  u16 unk_da;                                 // 0x0DA, Init が 0,_Update が 0 まで減らす
  u16 unk_dc;                                 // 0x0DC, Generator_Init の第9引数,読み手が見つかっていない
  u8 unk_de[2];                               // 0x0DE
  u16 unk_e0;                                 // 0x0E0, _Update が 0 まで減らす
  u16 unk_e2;                                 // 0x0E2, 0 でない間 Generator_UpdateFlash が flashTimer を増やし、その後 0 に戻す
  u16 flashTimer;                             // 0x0E4, 12 でパレット 455, 1〜11 で 454, 0 で plttID に戻る
  u8 unk_e6[2];                               // 0x0E6
  u16 unk_e8;                                 // 0x0E8, gEntityCBB0 の field_0xc10 が立ち、かつ state が 4 のときだけ減る
  u8 unk_ea;                                  // 0x0EA, Init が 0,読み手が見つかっていない
  u8 unk_eb;                                  // 0x0EB, 0 でない間 Generator_UpdateFlash がパレット 0x132 を強制して減らす
  u8 unk_ec;                                  // 0x0EC, Init が 0,読み手が見つかっていない
  u8 unk_ed;                                  // 0x0ED
  u16 plttID;                                 // 0x0EE, 451 or 452
  u16 unk_f0;                                 // 0x0F0, 点灯時のパレットID
  bool16 unk_f2;                              // 0x0F2, 0 でない間は稼働中
  u16 unk_f4;                                 // 0x0F4, 次に音を鳴らす残り時間
  u8 unk_f6[3];                               // 0x0F6
  u8 unk_f9;                                  // 0x0F9, 0 まで減らすだけのカウンタ
  u8 unk_fa[6];                               // 0x0FA
  Eff082473e0Emitter eff_100;                 // 0x100
  void (*updateCallback)(struct Generator*);  // 0x238
} Generator;
static_assert(sizeof(Generator) == 572);

void Generator_SetState(Generator* p, s32 state);
Generator* Generator_Create(Vec3* pos, s32 param_2, s32 param_3, s32 state, s32 param_5, s32 param_6, u32 power, s32 param_8);

#endif  // __INCLUDE_SOLAR_GENERATOR_H__
