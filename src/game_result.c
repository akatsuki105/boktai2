#include "entity.h"
#include "global.h"
#include "sprite.h"

// ゲームクリア時のリザルト画面
typedef struct GameResult {
  Entity e;             // 0x000, ENTITY_UNK_11
  SpriteSet spriteSet;  // 0x018
  void* tilemapfile;    // 0x038
  rgb555* pltt;         // 0x03C
  u32 unk_40;           // 0x040, なんかのbitfield?
  u32 scriptID_44;      // 0x044, 0x08222954
  s32 unk_48;           // 0x048, sUpdates の idx (このゲームでは常に 0)
  s32 unk_4c;           // 0x04C
  s32 unk_50;           // 0x050
  s32 unk_54;           // 0x054
  u8 unk_58[0x76 - 0x58];
  char unk_76[2];                              // 0x076, 0x08222c2a
  SpriteState sprite_78[8];                    // 0x078, 0x082226a6 で 8回ループ処理してるので長さは8
  bool32 unk_378;                              // 0x378
  void (*updateCallback)(struct GameResult*);  // 0x37C, GameResult_Update で呼ばれる
} GameResult;
static_assert(sizeof(GameResult) == 896);

NAKED void FUN_08222270(GameResult* p) { INCFUNC("asm/func/FUN_08222270.inc"); }

NAKED void FUN_082222f0(GameResult* p) { INCFUNC("asm/func/FUN_082222f0.inc"); }

NAKED void FUN_0822230c(GameResult* p) { INCFUNC("asm/func/FUN_0822230c.inc"); }

NAKED static void _GameResult_Update(GameResult* p) { INCFUNC("asm/func/_GameResult_Update.inc"); }

NAKED void FUN_082229ac(GameResult* p) { INCFUNC("asm/func/FUN_082229ac.inc"); }

NAKED void FUN_082229e8(GameResult* p) { INCFUNC("asm/func/FUN_082229e8.inc"); }

NAKED void FUN_08222a18(GameResult* p) { INCFUNC("asm/func/FUN_08222a18.inc"); }

void FUN_08222a54(GameResult* p, s32 idx) {
  static void (*const sUpdates[1])(GameResult*) = {
      _GameResult_Update,
  };  // 0x085B0080

  p->unk_48 = idx;
  p->unk_4c = 0;
  p->updateCallback = sUpdates[idx];
  {
    u32 unk_40 = 1;
    p->unk_40 |= unk_40;
  }
  p->unk_50 = 0;
  p->unk_54 = 0;
  p->unk_40 |= (1 << 1);
}

s32 GameResult_Update(GameResult* p) {
  if ((p->unk_40 & (1 << 0)) == 0) p->unk_4c++;
  if ((p->unk_40 & (1 << 1)) == 0) p->unk_54++;
  p->updateCallback(p);  // このゲームでは常に _GameResult_Update
  return 0;
}

s32 GameResult_Destroy(GameResult* p) {
  FUN_082222f0(p);
  return 0;
}

NAKED s32 GameResult_Init(GameResult* p) { INCFUNC("asm/func/GameResult_Init.inc"); }

NAKED GameResult* GameResult_Create(void) { INCFUNC("asm/func/GameResult_Create.inc"); }
