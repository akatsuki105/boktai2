#include "entity.h"
#include "global.h"
#include "sprite_main.h"
#include "sprite_pltt.h"

typedef struct EntityA288 EntityA288;
typedef void(EntityA288Func)(EntityA288* p);

// '.I' が並べる1件, count 個ぶんだけ3つの配列が埋まる
typedef struct {
  s8 id;          // 0x00, -1 なら打ち切り
  u8 count;       // 0x01, 続く3つの配列の有効数
  s16 values[5];  // 0x02, VM_GetValueAt で読む
  u32 unk_c[5];   // 0x0C, VM_GetValue で読む
  u32 unk_20[5];  // 0x20, VM_GetValue で読む
} EntityA288Entry;
static_assert(sizeof(EntityA288Entry) == 52);

struct EntityA288 {
  Entity e;                      // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx;             // 0x0018, GetFile(DIR_SPRITE_SETS, 0x42E2)
  u32* tilemap;                  // 0x0038, GetFile(DIR_TILE_MAP, 0x33B2)
  rgb555* bgPltt;                // 0x003C, GetFile(DIR_BGPLTT, 0xE9C3) + 0x14
  s32 kind;                      // 0x0040, '.t' の値, 初期 state を選ぶ
  u32 flags;                     // 0x0044, bit0 / bit1 が立っている間は timer1 / timer2 を止める
  u32 unk_48;                    // 0x0048, '.f' の値
  u32 unk_4c;                    // 0x004C, '.l' の値
  u32 unk_50;                    // 0x0050, '.e' の値
  s32 state;                     // 0x0054, 0x085AFF84 の関数表の添字
  s32 timer1;                    // 0x0058, flags bit0 が落ちている間 _Update が 1 足す
  u32 unk_5c;                    // 0x005C, FUN_08219f34 が 0 に戻す
  s32 timer2;                    // 0x0060, flags bit1 が落ちている間 _Update が 1 足す
  s32 unk_64;                    // 0x0064, _Init が -1 を入れる
  u32 unk_68;                    // 0x0068, _Init が 0 を入れる
  u8 unk_6c[0x1CC - 0x6C];       // 0x006C, まだ未解析
  u8* unk_1cc;                   // 0x01CC, '.s'
  u8 unk_1d0[0x780 - 0x1D0];     // 0x01D0, まだ未解析
  EntityA288Entry entries[30];   // 0x0780, '.I' から読む
  u8 unk_d98[0xDAC - 0xD98];     // 0x0D98, まだ未解析
  u8* unk_dac;                   // 0x0DAC, '.a'
  u8* unk_db0;                   // 0x0DB0, '.I' の先頭
  u8 unk_db4[2];                 // 0x0DB4, まだ未解析
  s16 entryCount;                // 0x0DB6, 読めた entries の個数 - 1
  u8 unk_db8[0xE80 - 0xDB8];     // 0x0DB8, まだ未解析
  u8* unk_e80;                   // 0x0E80, '.X'
  u8 unk_e84[4];                 // 0x0E84, まだ未解析
  u32 unk_e88;                   // 0x0E88, '.E' の値
  u8 unk_e8c[0x12AC - 0xE8C];    // 0x0E8C, まだ未解析
  u8* unk_12ac;                  // 0x12AC, '.b'
  u8 unk_12b0[0x1650 - 0x12B0];  // 0x12B0, まだ未解析
  u8* unk_1650;                  // 0x1650, '.g'
  u8* unk_1654;                  // 0x1654, '.T'
  u8* unk_1658;                  // 0x1658, '.A'
  u8 unk_165c[0x178C - 0x165C];  // 0x165C, まだ未解析
  u8* unk_178c;                  // 0x178C, '.p' の PC
  u8* unk_1790;                  // 0x1790, '.S'
  u8* unk_1794;                  // 0x1794, '.P' の PC
  u8* unk_1798;                  // 0x1798, '.N' の PC
  u8* unk_179c;                  // 0x179C, '.H'
  u8* unk_17a0;                  // 0x17A0, '.K'
  u8 unk_17a4[0x1FE8 - 0x17A4];  // 0x17A4, まだ未解析
  EntityA288Func* fn;            // 0x1FE8, _Update が毎フレーム呼ぶ, FUN_08219f34 が state から差し替える
};
static_assert(sizeof(EntityA288) == 8172);

INCASM("asm/entity_a288.inc");
