#ifndef __INCLUDE_ENTITY_CBB0_H__
#define __INCLUDE_ENTITY_CBB0_H__

#include "eff_082473e0.h"
#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "msgbus.h"
#include "sprite_aux.h"
#include "types.h"

struct Generator;

struct EntityCBB0;
typedef void(EntityCBB0Func)(struct EntityCBB0* p);

// パイルドライバー という 複数の 太陽ジェネレータ (struct Generator) の照射でイモータルを浄化するゲームのギミック のシーンEntity
typedef struct EntityCBB0 {
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
  AuxSprite sprite_254;             // 0x0254, ->gfx_280
  AuxSpriteGfx gfx_280;             // 0x0280
  u8 unk_29c[0x4FC - 0x29C];        // 0x029C, まだ未解析
  u16 unk_4fc;                      // 0x04FC, _Update が PTR_ARRAY_085AD07C[unk_4fc](p) として引く状態番号
  u16 unk_4fe;                      // 0x04FE, FUN_080ad1ec が unk_4fc の差し替えのたびに 0 に戻すカウンタ
  u8 unk_500[0x508 - 0x500];        // 0x0500, まだ未解析
  Vec3 unk_508;                     // 0x0508, FUN_080b10f8 が FUN_080b1038 に渡す座標
  Vec3 pos_510;                     // 0x0510, FUN_080b1038 が距離判定に使うワールド座標
  u8 unk_518[0x67A - 0x518];        // 0x0518, まだ未解析
  u16 unk_67a;                      // 0x067A, 根拠: FUN_080b01b4 が毎フレーム +1 して unk_690 と比べる
  u8 unk_67c[0x68A - 0x67C];        // 0x067C, まだ未解析
  u16 unk_68a;                      // 0x068A
  u8 unk_68c[0x690 - 0x68C];        // 0x068C, まだ未解析
  u16 unk_690;                      // 0x0690, 根拠: FUN_080b01b4 が unk_67a の上限として見る
  u8 unk_692[0x69C - 0x692];        // 0x0692, まだ未解析
  Vec3 unk_69c;                     // 0x069C, FUN_080b0e58 が 3成分とも 0xA0 を入れる
  Vec3 unk_6a4;                     // 0x06A4, FUN_080b0e58 が入れる当たり判定の広がりらしい値
  struct EntityCBB0* unk_6ac;       // 0x06AC, *(*unk_6ac + 0xBE8 + i*4) を引くので EntityCBB0 を指す (暫定)
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
  u8 unk_c18[0xC6C - 0xC18];        // 0x0C18, まだ未解析
  u8 unk_c6c[0x12E4 - 0xC6C];       // 0x0C6C, 根拠: FUN_080af374 の第1引数, +0x678 までを触る
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
  unknown* unk_1360;                // 0x1360, 根拠: FUN_080af0c8 が FUN_0805b1a0 に渡す
  u8 unk_1364[0x1374 - 0x1364];     // 0x1364, まだ未解析
  bool16 unk_1374;                  // 0x1374, FUN_080adf60 が立て, FUN_080adfa0 が見る
  u8 unk_1376[0x1420 - 0x1376];     // 0x1376, まだ未解析
  u32 unk_1420;                     // 0x1420, FUN_080adb5c が 0 に戻す
  u32 unk_1424;                     // 0x1424, まだ未解析
  bool16 unk_1428;                  // 0x1428, FUN_080ad9d4 / FUN_080ad6a8 が立て, FUN_080ad96c が見て下ろす
  u8 unk_142a[0x17A4 - 0x142A];     // 0x142A, まだ未解析
  u32 unk_17a4;                     // 0x17A4, '.p'
  MsgQueue mq;                      // 0x17A8
} EntityCBB0;
static_assert(sizeof(EntityCBB0) == 6108);

extern EntityCBB0* gEntityCBB0;  // 0x03002C58

// --------------------------------------------

// 太陽ジェネレーター
// パイルドライバーで使う装置で、太陽の光をビームとして出してイモータルを攻撃する装置, イモータルに攻撃されるとオフになるが、プレイヤーがエンチャント攻撃を当てると再びオンになる
// 太陽ジェネレーターから出るビームは太陽パイルとも呼ばれる
typedef struct Generator {
  Entity e;                                   // 0x000, ENTITY_UNK_8
  AuxSprite sprite;                           // 0x018, ->gfx
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

#endif  // __INCLUDE_ENTITY_CBB0_H__
