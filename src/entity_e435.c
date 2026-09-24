#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;            // 0x0, ENTITY_UNK_9 or ENTITY_UNK_11
  u16 id;              // 0x018
  u16 unk_1a;          // 0x01A, '.t' (default: 0), FUN_0822ee58 の第1引数
  u16 unk_1c;          // 0x01C, '.m' (default: 0), FUN_0822ee58 の第2引数
  u8 unk_1e;           // 0x01E, '.r' の1番目
  u8 unk_1f;           // 0x01F, '.r' の2番目 (無ければ 0xA0)
  s16 phaseStep;       // 0x020, '.o' (default: 2), 1tick ごとに phase へ加える
  s16 phase;           // 0x022, _Update が (BG の vofs + phase) & 0x7F で waveTable を引く
  u16 tickInterval;    // 0x024, '.i' (default: 5), tickTimer と比べる
  u16 tickTimer;       // 0x026, _Update が数え上げ、tickInterval で 0 に戻る
  bool32 enabled;      // 0x028, _Init が 1 を入れる。0 の間 _Update は何もしない
  u16 tableIdx;        // 0x02C, waveTable を tableIdx * 0x240 だけずらす。_Init が 0 を入れるが書き手が見つかっていない
  s16 waveTable[288];  // 0x02E, '.s' * gSineTable[i & 0x7F] >> 12  を288個
  u8 unk_26e[6];       // 0x26E, 読み書きとも無し
} EntityE435;
static_assert(sizeof(EntityE435) == 628);

IWRAM_DATA EntityE435* gEntityE435 = NULL;  // 0x03000070

void FUN_0822f0d8(void);

void FUN_080179ac(void) { gEntityE435 = NULL; }

NAKED s32 EntityE435_Update(EntityE435* p) { INCFUNC("asm/func/EntityE435_Update.inc"); }

s32 EntityE435_Destroy(EntityE435* p) {
  FUN_0822f0d8();
  gEntityE435 = NULL;
  return 0;
}

NAKED s32 EntityE435_Init(EntityE435* p, u32 id) { INCFUNC("asm/func/EntityE435_Init.inc"); }

NAKED EntityE435* EntityE435_Create(u32 id) { INCFUNC("asm/func/EntityE435_Create.inc"); }
