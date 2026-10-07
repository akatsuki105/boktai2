#include "entity.h"
#include "global.h"
#include "player.h"
#include "shadow.h"
#include "sprite_aux.h"

// 通信対戦のコイン(対戦相手を倒したりすると落とすもので、これがプレイヤーの得点になる)

struct LinkBattleCoinManager;
struct Entity150FSlot;

typedef struct Entity150FSlot {
  s8 unk_00;                                                                                      // 0x00, FUN_081e1220 の第3引数, gEntity9A9F->unk_118[i]
  u8 unk_01;                                                                                      // 0x01, FUN_081e1220 が 0 を入れる
  u8 unk_02;                                                                                      // 0x02, FUN_081e1220 が 0 を入れる
  u8 unk_03;                                                                                      // 0x03, FUN_081e1220 が 0 を入れる
  u8 unk_04[2];                                                                                   // 0x04, まだ未解析
  u16 unk_06;                                                                                     // 0x06, FUN_081e1220 が 0 を入れる
  u8 unk_08[0x20 - 0x08];                                                                         // 0x08, まだ未解析
  void (*updateCallback)(struct LinkBattleCoinManager* p, struct Entity150FSlot* slot, s32 idx);  // 0x20
  AuxSprite sprite;                                                                               // 0x24
  ParticleShadow shadow;                                                                          // 0x50
} Entity150FSlot;
static_assert(sizeof(Entity150FSlot) == 144);

typedef struct LinkBattleCoinManager {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u32 frameCount;           // 0x018, _Update が毎フレーム +1
  s16 unk_1c;               // 0x01C, '.p=0'
  AuxSpriteGfx coinGfx;     // 0x020, SPRITE_COIN
  Vec3 playerPoss[4];       // 0x03C, players[i] の位置
  Player* players[4];       // 0x05C, gPlayerPtr[0..3] の写し
  Entity150FSlot coins[5];  // 0x06C
} LinkBattleCoinManager;
static_assert(sizeof(LinkBattleCoinManager) == 828);

extern LinkBattleCoinManager* gLinkBattleCoinManager;  // 0x030001B0

void FUN_081e0c14(void) { gLinkBattleCoinManager = NULL; }

NAKED void FUN_081e0c20(Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e0c20.inc"); }

NAKED void FUN_081e0ec0(Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e0ec0.inc"); }

NAKED void FUN_081e10b8(Entity150FSlot* slot, u32 param_2) { INCFUNC("asm/func/FUN_081e10b8.inc"); }

NAKED s32 FUN_081e1220(LinkBattleCoinManager* p, Entity150FSlot* slot, s32 param_3) { INCFUNC("asm/func/FUN_081e1220.inc"); }

s32 FUN_081e1260(LinkBattleCoinManager* p, Entity150FSlot* slot) {
  AuxSprite_Remove(&slot->sprite);
  ParticleShadow_Remove(&slot->shadow);
  return 0;
}

void FUN_081e127c(Entity150FSlot* slot) {
  slot->unk_01 = 0;
  slot->unk_02 = 0;
  slot->unk_03 = 0;
  slot->sprite.flags |= SPRFLAG_HIDDEN;
  ParticleShadow_Hide(&slot->shadow);
  slot->updateCallback = NULL;
  slot->unk_06 = 0;
  slot->unk_04[0] = 1;
}

// unk_00 が key と一致するスロットを探す
Entity150FSlot* Entity150F_FindSlot(LinkBattleCoinManager* p, s32 key) {
  Entity150FSlot* slot = p->coins;
  s32 i;

  for (i = 0; i < 5; i++, slot++) {
    if (slot->unk_00 == key) {
      return slot;
    }
  }

  return NULL;
}

NAKED s32 FUN_081e12c8(LinkBattleCoinManager* p, Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e12c8.inc"); }

NAKED s32 FUN_081e1344(LinkBattleCoinManager* p, Entity150FSlot* slot) { INCFUNC("asm/func/FUN_081e1344.inc"); }

NAKED void FUN_081e1438(LinkBattleCoinManager* p, Entity150FSlot* slot, s32 idx) { INCFUNC("asm/func/FUN_081e1438.inc"); }

NAKED void FUN_081e1524(LinkBattleCoinManager* p, Entity150FSlot* slot, s32 idx) { INCFUNC("asm/func/FUN_081e1524.inc"); }

NAKED void FUN_081e15b4(LinkBattleCoinManager* p, Entity150FSlot* slot, s32 idx) { INCFUNC("asm/func/FUN_081e15b4.inc"); }

NAKED void FUN_081e169c(LinkBattleCoinManager* p, Entity150FSlot* slot, s32 idx) { INCFUNC("asm/func/FUN_081e169c.inc"); }

NAKED void FUN_081e1734(LinkBattleCoinManager* p) { INCFUNC("asm/func/FUN_081e1734.inc"); }

NAKED s32 Entity150F_Update(LinkBattleCoinManager* p) { INCFUNC("asm/func/Entity150F_Update.inc"); }

NAKED s32 Entity150F_Destroy(LinkBattleCoinManager* p) { INCFUNC("asm/func/Entity150F_Destroy.inc"); }

NAKED s32 Entity150F_Init(LinkBattleCoinManager* p) { INCFUNC("asm/func/Entity150F_Init.inc"); }

// 0x150F
NAKED LinkBattleCoinManager* Entity150F_Create(void) { INCFUNC("asm/func/Entity150F_Create.inc"); }

NAKED s32 FUN_081e1984(unknown* param_1) { INCFUNC("asm/func/FUN_081e1984.inc"); }
