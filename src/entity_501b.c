#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "tilemap.h"

typedef struct Entity501B Entity501B;
typedef void(Entity501BFunc)(Entity501B* p);

// 通信対戦のスコア精算画面, 稼いだ点を1フレームずつ所持スコアへ移していく
struct Entity501B {
  Entity e;                        // 0x000, ENTITY_UNK_11
  MainSprite digits[8];            // 0x018, [0..3] が上段 (y=0x40), [4..7] が下段 (y=0x78), 各段とも [0] が1の位
  MainSpriteGfx gfx;               // 0x318, SPRITE_UI_LINK
  u8 unk_338[0x358 - 0x338];       // 0x338, まだ未解析
  MainSpriteGfxFile* file;         // 0x358, SPRITE_SOLAR_STATION
  u8 unk_35c[4];                   // 0x35C, まだ未解析
  u16 poses[8];                    // 0x360, digits ごとの MainSprite_Add のポーズ番号
  AuxSprite solarStandSpr;         // 0x370
  AuxSpriteGfx solarStandGfx;      // 0x39C, SPRITE_SOLAR_STATION
  u8 unk_3b8[2];                   // 0x3B8, まだ未解析
  s16 timer;                       // 0x3BA, 90 から毎フレーム減り, 0 で次の状態へ, ボタンで 1 に飛ばせる
  u16 score;                       // 0x3BC, gEntity9A9F->unk_138[playerIdx] (9999 で頭打ち), 精算で減っていく
  s16 step;                        // 0x3BE, 1フレームに score から gStat->field_0x912 へ移す量, 初期 2, ボタンで <<3
  s32 unk_3c0;                     // 0x3C0, gEntity9A9F->unk_144[playerIdx] (±9999 で頭打ち)
  Tilemaps* tilemap0;              // 0x3C4, TILEMAP_CD91 を BG2 に敷く
  Tilemaps* tilemap1;              // 0x3C8, TILEMAP_A413 を BG0 に敷く
  rgb555* bgPltt;                  // 0x3CC, BGP_26BB
  Entity501BFunc* updateCallback;  // 0x3D0
  u8* unk_3d4;                     // 0x3D4, '.s', TextPanel_SetScript に渡す
  u8* unk_3d8;                     // 0x3D8, '.e'
  u32 flags;                       // 0x3DC, bit0 を立てて step の <<3 を一度だけにする
  s32 textPanels[2];               // 0x3E0, TextPanel_Create の戻り値
  u8 phase;                        // 0x3E8, 状態を切り替えるたびに 0/1/2/3 が入る
  bool8 entered;                   // 0x3E9, 状態に入った最初のフレームだけ立つ, 各状態が初期化を済ませて 0 に戻す
  u16 stateTimer;                  // 0x3EA, 状態に入ってからのフレーム数
};
static_assert(sizeof(Entity501B) == 1004);

INCASM("asm/entity_501b.inc");
