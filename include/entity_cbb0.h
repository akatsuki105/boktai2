#ifndef __INCLUDE_ENTITY_CBB0_H__
#define __INCLUDE_ENTITY_CBB0_H__

#include "entity.h"
#include "gba/gba.h"
#include "msgbus.h"
#include "sound.h"
#include "sprite_aux.h"
#include "types.h"

struct Generator;  // include/solar_generator.h, ここではポインタしか持たないので前方宣言だけにしておく

typedef struct EntityCBB0 EntityCBB0;
typedef void(EntityCBB0Func)(EntityCBB0* p);  // EntityCBB0_SetState が 0x250 に入れて 0x22E を 0 に戻す

// 太陽ジェネレータをまとめているので、パイルドライバー(複数の太陽ジェネレータの照射でイモータルを浄化するギミック)のシーンEntity?
struct EntityCBB0 {
  Entity e;                         // 0x0000, ENTITY_UNK_9
  u16 subroutineID;                 // 0x0018, 0xCBB0 (EntityCBB0_Create)
  u16 unk_1a;                       // 0x001A
  u8 unk_1c[0x1E - 0x1C];           // 0x001C, まだ未解析
  u8 unk_1e;                        // 0x001E, 0 以外のときだけ generators を走査する
  u8 unk_1f;                        // 0x001F, 意味は未解析
  u8 unk_20[0x22E - 0x20];          // 0x0020, まだ未解析
  u16 stateTimer;                   // 0x022E, EntityCBB0_SetState が updateCallback の差し替えのたびに 0 に戻す
  u16 unk_230[16];                  // 0x0230, FUN_080ad9d4 が添字つきで書く以外の用途は未解析
  EntityCBB0Func* updateCallback;   // 0x0250
  AuxSprite sprite_254;             // 0x0254, EntityCBB0_Destroy が 0x2BC が 0 でないときだけ AuxSprite_Remove に渡す
  AuxSpriteGfx gfx_280;             // 0x0280, sprite_254 とペア, FUN_080b0b7c と同じ {AuxSprite, AuxSpriteGfx} の並び
  u8 unk_29c[0x4FC - 0x29C];        // 0x029C, まだ未解析
  u16 unk_4fc;                      // 0x04FC, _Update が PTR_ARRAY_085AD07C[unk_4fc](p) として引く状態番号
  u16 unk_4fe;                      // 0x04FE, FUN_080ad1ec が unk_4fc の差し替えのたびに 0 に戻すカウンタ
  u8 unk_500[0x508 - 0x500];        // 0x0500, まだ未解析
  Vec3 unk_508;                     // 0x0508, FUN_080b10f8 が FUN_080b1038 に渡す座標
  Vec3 pos_510;                     // 0x0510, FUN_080b1038 が距離判定に使うワールド座標
  u8 unk_518[0x68A - 0x518];        // 0x0518, まだ未解析
  u16 unk_68a;                      // 0x068A
  u8 unk_68c[0x69C - 0x68C];        // 0x068C, まだ未解析
  Vec3 unk_69c;                     // 0x069C, FUN_080b0e58 が 3成分とも 0xA0 を入れる
  Vec3 unk_6a4;                     // 0x06A4, FUN_080b0e58 が入れる当たり判定の広がりらしい値
  EntityCBB0* unk_6ac;              // 0x06AC, *(*unk_6ac + 0xBE8 + i*4) を引くので EntityCBB0 を指す (暫定)
  u8 unk_6b0[0xBE8 - 0x6B0];        // 0x06B0, まだ未解析
  struct Generator* generators[6];  // 0x0BE8, i*4 刻みで引き、要素の +0xCF / +0xEC / +0xE2 を触る
  u8 unk_c00[0xC0B - 0xC00];        // 0x0C00, まだ未解析
  u8 state_c0b;                     // 0x0C0B
  u8 unk_c0c[0xC0F - 0xC0C];        // 0x0C0C, まだ未解析
  u8 unk_c0f;                       // 0x0C0F
  u8 unk_c10;                       // 0x0C10, 現在の太陽ゲージ?
  u8 unk_c11;                       // 0x0C11
  bool8 unk_c12;                    // 0x0C12, FUN_080b2314 / FUN_080b2334 が 1 / 0 を入れ, FUN_080b176c が見る
  u8 unk_c13[0xC16 - 0xC13];        // 0x0C13, まだ未解析
  u16 unk_c16;                      // 0x0C16
  u8 unk_c18[0x12E4 - 0xC18];       // 0x0C18, まだ未解析
  u16 unk_12e4;                     // 0x12E4, 0 の間だけ FUN_080b1888 が先に進む
  u8 unk_12e6[0x1324 - 0x12E6];     // 0x12E6, まだ未解析
  u16 unk_1324;                     // 0x1324, 0 から 0x3F で折り返すカウンタ, FUN_080adf50 が 0x30, FUN_080adf60 が 0x40 を入れる
  u16 unk_1326;                     // 0x1326, FUN_080adfa0 が 0..7 の値を入れる
  u8 unk_1328[0x1332 - 0x1328];     // 0x1328, まだ未解析
  u8 unk_1332;                      // 0x1332, FUN_080b165c が 0 に戻す
  bool8 unk_1333;                   // 0x1333, FUN_080b22e8 が立て, FUN_080b1718 が見る
  u16 unk_1334;                     // 0x1334, FUN_080b22e8 が 0 に戻す
  u8 tilemapIdx;                    // 0x1336, FileID_ARRAY_085ad048 の添字
  u8 unk_1337[0x133E - 0x1337];     // 0x1337, まだ未解析
  u8 unk_133e;                      // 0x133E
  u8 unk_133f;                      // 0x133F, unk_1340 の添字
  SoundID16 unk_1340[4];            // 0x1340, PlaySound_082406e0(unk_1340[unk_133f]) で鳴らす
  u8 unk_1348[0x135C - 0x1348];     // 0x1348, まだ未解析
  EntityCBB0Func* unk_135c;         // 0x135C, FUN_080af0ac が非NULLのとき unk_135c(p) を呼ぶ
  u8 unk_1360[0x1374 - 0x1360];     // 0x1360, まだ未解析
  bool16 unk_1374;                  // 0x1374, FUN_080adf60 が立て, FUN_080adfa0 が見る
  u8 unk_1376[0x1420 - 0x1376];     // 0x1376, まだ未解析
  u32 unk_1420;                     // 0x1420, FUN_080adb5c が 0 に戻す
  u32 unk_1424;                     // 0x1424, まだ未解析
  bool16 unk_1428;                  // 0x1428, FUN_080ad9d4 / FUN_080ad6a8 が立て, FUN_080ad96c が見て下ろす
  u8 unk_142a[0x17A4 - 0x142A];     // 0x142A, まだ未解析
  u32 unk_17a4;                     // 0x17A4, '.p'
  EntityMsgBox unk_17a8;            // 0x17A8
};
static_assert(sizeof(EntityCBB0) == 6108);

extern EntityCBB0* gEntityCBB0;  // 0x03002C58

#endif  // __INCLUDE_ENTITY_CBB0_H__
