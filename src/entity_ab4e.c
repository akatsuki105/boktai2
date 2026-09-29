#include "entity.h"
#include "global.h"
#include "player.h"
#include "sprite_main.h"
#include "struct.h"

// '.h' / 's' で指定されるマップ上の一点
typedef struct {
  s16 x;       // 0x0, VM から読む
  s16 height;  // 0x2, 地形の attr から算出する
  s16 z;       // 0x4, VM から読む
  s16 unk_6;   // 0x6, まだ未解析
} EntityAB4EPoint;
static_assert(sizeof(EntityAB4EPoint) == 8);

typedef struct {
  u8 unk_0[4];                // 0x000, まだ未解析
  u8 state;                   // 0x004, _Update が 0x085AB434 の関数表の添字として引く
  u8 unk_5[2];                // 0x005, まだ未解析
  u8 gfxIndex;                // 0x007, EntityAB4E.gfx の添字
  u8 unk_8;                   // 0x008, まだ未解析
  bool8 active;               // 0x009, _Update / _Destroy がこれを見て処理する
  u8 unk_a[6];                // 0x00A, まだ未解析
  s32 timer;                  // 0x010, _Update が毎フレーム 1 足す
  u8 unk_14[0x37 - 0x14];     // 0x014, まだ未解析
  bool8 unk_37;               // 0x037, _Update が毎フレーム 0 に戻し, state のハンドラが立てる
  u8 unk_38[0x60 - 0x38];     // 0x038, まだ未解析
  Entity2UnkData unk_60;      // 0x060, _Update が FUN_0823b4b8 に渡す
  MainSprite sprite;          // 0x0A4, _Update が MainSprite_AdvanceAnim に渡す
  u8 unk_104[0x174 - 0x104];  // 0x104, まだ未解析
  s16 unk_174;                // 0x174, 0/1 で FUN_080da9c4 の呼び分けをする
  s16 unk_176;                // 0x176, FUN_080da9c4 に渡す
  s16 counter;                // 0x178, 毎フレーム減らし, 0 になると period に戻す
  s16 period;                 // 0x17A, counter の初期値
  u32 handle;                 // 0x17C, FUN_080da9c4 の戻り値
} EntityAB4EElem;
static_assert(sizeof(EntityAB4EElem) == 384);

typedef struct {
  Entity e;                     // 0x0000, ENTITY_UNK_5
  Vec3* playerPos;              // 0x0018, &gPlayerPtr[0]->unk_24.pos
  s16 unk_1c;                   // 0x001C, '.t' の値
  bool8 minuteChanged;          // 0x001E, 分が変わったフレームだけ立つ
  u8 prevMinute;                // 0x001F, 前フレームの GetMinute
  u8 hour;                      // 0x0020, GetHour
  u8 minute;                    // 0x0021, GetMinute
  u8 unk_22;                    // 0x0022, まだ未解析
  u8 count1;                    // 0x0023, '.h' で読めた points1 の個数
  u8 count2;                    // 0x0024, '.s' で読めた points2 の個数
  u8 unk_25;                    // 0x0025, _Update が FUN_08018a08 の戻り値を入れる
  u8 unk_26[2];                 // 0x0026, まだ未解析
  u32 unk_28;                   // 0x0028, _Init が 0 を入れる
  EntityAB4EPoint points1[16];  // 0x002C, '.h'
  EntityAB4EPoint points2[16];  // 0x00AC, '.s'
  EntityAB4EElem elems[16];     // 0x012C
  MainSpriteGfx gfx[8];         // 0x192C, '.d' の8個の ID から作る
  Player* player;               // 0x1A2C, gPlayerPtr[0]
} EntityAB4E;
static_assert(sizeof(EntityAB4E) == 6704);

IWRAM_DATA EntityAB4E* gEntityAB4E = NULL;  // 0x030000C0

INCASM("asm/entity_ab4e.inc");
