#ifndef __INCLUDE_ENTITY_CBB0_H__
#define __INCLUDE_ENTITY_CBB0_H__

#include "eff_082473e0.h"
#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "msgbus.h"
#include "particle.h"
#include "sprite_aux.h"
#include "types.h"

struct Generator;

struct PileDriver;
typedef void(PileDriverFunc)(struct PileDriver* p);

// AuxSprite と専用の AuxSpriteGfx に 0x81 周期のアニメーションカウンタを足した一式
typedef struct {
  AuxSprite spr;           // 0x00, ->gfx
  AuxSpriteGfx gfx;        // 0x2C
  u8 unk_48[0x68 - 0x48];  // 0x48, まだ未解析
  u16 unk_68;              // 0x68, 0 の間は止まっている
  u16 pose;                // 0x6A, animTimer から決まる 0〜3
  u8 unk_6c[2];            // 0x6C, まだ未解析
  u16 animTimer;           // 0x6E, 0x81 を越えると 0 に戻る
} PileDriverAnimSprite;
static_assert(sizeof(PileDriverAnimSprite) == 112);

// PileDriver が 0x0564 から32個持つ粒子の枠
typedef struct {
  Particle ptcl;           // 0x00, PTCL_GROUP_2
  u8 unk_28[0x30 - 0x28];  // 0x28, まだ未解析
  u8 unk_30;               // 0x30, FUN_080ad388 が枠を作るたびに 0 を入れる
  u8 unk_31[3];            // 0x31, padding?
} PileDriverParticle;
static_assert(sizeof(PileDriverParticle) == 52);

// パイルドライバー という 複数の 太陽ジェネレータ (struct Generator) の照射でイモータルを浄化するゲームのギミック のシーンEntity
typedef struct PileDriver {
  Entity e;                         // 0x0000, ENTITY_UNK_9
  u16 subroutineID;                 // 0x0018, 0xCBB0 (PileDriver_Create)
  u16 unk_1a;                       // 0x001A
  u8 unk_1c[0x1E - 0x1C];           // 0x001C, まだ未解析
  u8 unk_1e;                        // 0x001E, 0 以外のときだけ generators を走査する
  u8 unk_1f;                        // 0x001F, 意味は未解析
  u8 unk_20[0x22E - 0x20];          // 0x0020, まだ未解析
  u16 stateTimer;                   // 0x022E, PileDriver_SetState が updateCallback の差し替えのたびに 0 に戻す
  u16 unk_230[16];                  // 0x0230, FUN_080ad9d4 が添字つきで書く以外の用途は未解析
  PileDriverFunc* updateCallback;   // 0x0250
  PileDriverAnimSprite sprite_254;  // 0x0254
  u8 unk_2c4[0x4E0 - 0x2C4];        // 0x02C4, まだ未解析
  rgb555* plttSrc;                  // 0x04E0, 点滅用のパレット4組の先頭
  u8 unk_4e4[0x4EC - 0x4E4];        // 0x04E4, まだ未解析
  u16 plttTimer;                    // 0x04EC, 奇数フレームごとに plttSrc の組を差し替える
  u8 unk_4ee[0x4FC - 0x4EE];        // 0x04EE, まだ未解析
  u16 unk_4fc;                      // 0x04FC, _Update が PTR_ARRAY_085AD07C[unk_4fc](p) として引く状態番号
  u16 unk_4fe;                      // 0x04FE, PileDriver_SetSubState が unk_4fc の差し替えのたびに 0 に戻すカウンタ
  u8 unk_500[0x508 - 0x500];        // 0x0500, まだ未解析
  Vec3 unk_508;                     // 0x0508, FUN_080b10f8 が FUN_080b1038 に渡す座標
  WorldPos pos_510;                 // 0x0510, FUN_080b1038 が距離判定に使うワールド座標
  AuxSprite sprite_518;             // 0x0518
  u8 unk_544[0x560 - 0x544];        // 0x0544, まだ未解析
  ParticleGroup* ptclGroup;         // 0x0560, PTCL_GROUP_2
  PileDriverParticle ptcls[32];     // 0x0564
  u8 unk_be4;                       // 0x0BE4, FUN_080ad388 が 0 を入れる
  u8 unk_be5[3];                    // 0x0BE5, padding?
  struct Generator* generators[6];  // 0x0BE8, i*4 刻みで引き、要素の +0xCF / +0xEC / +0xE2 を触る
  u8 unk_c00[0xC0B - 0xC00];        // 0x0C00, まだ未解析
  u8 state_c0b;                     // 0x0C0B
  u8 unk_c0c[0xC0F - 0xC0C];        // 0x0C0C, まだ未解析
  u8 unk_c0f;                       // 0x0C0F
  u8 unk_c10;                       // 0x0C10, 現在の太陽ゲージ?
  u8 unk_c11;                       // 0x0C11
  bool8 unk_c12;                    // 0x0C12, Cmd_F993 / Cmd_44BF が 1 / 0 を入れ, FUN_080b176c が見る
  u8 unk_c13[0xC16 - 0xC13];        // 0x0C13, まだ未解析
  u16 unk_c16;                      // 0x0C16
  u8 unk_c18[0xC6C - 0xC18];        // 0x0C18, まだ未解析
  u8 unk_c6c[0x12E4 - 0xC6C];       // 0x0C6C, 根拠: FUN_080af374 の第1引数, +0x678 までを触る
  u16 unk_12e4;                     // 0x12E4, 0 の間だけ FUN_080b1888 が先に進む
  u8 unk_12e6[0x1324 - 0x12E6];     // 0x12E6, まだ未解析
  u16 unk_1324;                     // 0x1324, 0 から 0x3F で折り返すカウンタ, FUN_080adf50 が 0x30, Cmd_054A が 0x40 を入れる
  u16 unk_1326;                     // 0x1326, FUN_080adfa0 が 0..7 の値を入れる
  u8 unk_1328[0x1332 - 0x1328];     // 0x1328, まだ未解析
  u8 unk_1332;                      // 0x1332, FUN_080b165c が 0 に戻す
  bool8 unk_1333;                   // 0x1333, Cmd_29F1 が立て, FUN_080b1718 が見る
  u16 unk_1334;                     // 0x1334, Cmd_29F1 が 0 に戻す
  u8 tilemapIdx;                    // 0x1336, FileID_ARRAY_085ad048 の添字
  u8 unk_1337[0x133E - 0x1337];     // 0x1337, まだ未解析
  u8 unk_133e;                      // 0x133E
  u8 unk_133f;                      // 0x133F, unk_1340 の添字
  SoundID16 unk_1340[4];            // 0x1340, PlaySound_082406e0(unk_1340[unk_133f]) で鳴らす
  u8 unk_1348[0x135C - 0x1348];     // 0x1348, まだ未解析
  PileDriverFunc* unk_135c;         // 0x135C, FUN_080af0ac が非NULLのとき unk_135c(p) を呼ぶ
  unknown* unk_1360;                // 0x1360, 根拠: FUN_080af0c8 が FUN_0805b1a0 に渡す
  u8 unk_1364[0x1374 - 0x1364];     // 0x1364, まだ未解析
  bool16 unk_1374;                  // 0x1374, Cmd_054A が立て, FUN_080adfa0 が見る
  u8 unk_1376[0x1420 - 0x1376];     // 0x1376, まだ未解析
  u32 unk_1420;                     // 0x1420, FUN_080adb5c が 0 に戻す
  u32 unk_1424;                     // 0x1424, まだ未解析
  bool16 unk_1428;                  // 0x1428, FUN_080ad9d4 / FUN_080ad6a8 が立て, FUN_080ad96c が見て下ろす
  u8 unk_142a[0x17A4 - 0x142A];     // 0x142A, まだ未解析
  u32 unk_17a4;                     // 0x17A4, '.p'
  MsgQueue mq;                      // 0x17A8
} PileDriver;
static_assert(sizeof(PileDriver) == 6108);

extern PileDriver* gPileDriver;  // 0x03002C58

// --------------------------------------------

// 太陽ジェネレーター
// パイルドライバーで使う装置で、太陽の光をビームとして出してイモータルを攻撃する装置, イモータルに攻撃されるとオフになるが、プレイヤーがエンチャント攻撃を当てると再びオンになる
// 太陽ジェネレーターから出るビームは太陽パイルとも呼ばれる
typedef struct Generator {
  Entity e;                                   // 0x000, ENTITY_UNK_8
  AuxSprite sprite;                           // 0x018, ->gfx
  AuxSpriteGfx gfx;                           // 0x044, SPRITE_GENERATOR
  Vec3 pos;                                   // 0x060, Generator_Create の第1引数を8バイト複写したもの,Hitbox_SetPos に渡す
  HitboxData hurtbox;                         // 0x068, Generator_InitHurtbox が Hitbox_Init / _SetPowerAndAttributes / _SetPos / _SetHandler する
  AuxAnimState anim;                          // 0x0B8, ANIM_PILE, animIdx は 1 or 3
  AuxAnimFile* animFile;                      // 0x0C8, ANIM_PILE
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
  s16 unk_de;                                 // 0x0DE, state 6 (FUN_080b31b4) が 0 まで減らし, 0 になると state 2 に戻る
  u16 unk_e0;                                 // 0x0E0, _Update が 0 まで減らす
  u16 unk_e2;                                 // 0x0E2, 0 でない間 Generator_UpdateFlash が flashTimer を増やし、その後 0 に戻す
  u16 flashTimer;                             // 0x0E4, 12 でパレット 455, 1〜11 で 454, 0 で plttID に戻る
  u8 unk_e6[2];                               // 0x0E6
  u16 unk_e8;                                 // 0x0E8, gPileDriver の field_0xc10 が立ち、かつ state が 4 のときだけ減る
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
