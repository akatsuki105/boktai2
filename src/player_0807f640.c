#include "global.h"
#include "sprite.h"

// プレイヤー(ジャンゴ/サバタ)のスプライトに関連するのは確定

typedef struct {
  Entity e;            // 0x0, ENTITY_UNK_11
  Player* player;      // 0x18
  SpriteSet unk_1c;    // 0x1C, 根拠: LoadPlayerSpriteSet_0807fe48
  SpriteState unk_3c;  // 0x3C, 根拠: FUN_0807fe24
  u8 unk_9c[1220 - 0x9C];
} Entity11_080801b0;
static_assert(sizeof(Entity11_080801b0) == 1220);

INCASM("asm/player_0807f640.inc");

// FileID: 0xDE23 は ジャンゴ/サバタのスプライトセット (https://boktaihacking.net/wiki/Sprite_set_file)
NAKED void LoadPlayerSpriteSet_0807fe48(Entity11_080801b0* p) { INCFUNC("asm/func/LoadPlayerSpriteSet_0807fe48.inc"); }

NAKED void FUN_0807fed0(Entity11_080801b0* p) { INCFUNC("asm/func/FUN_0807fed0.inc"); }

NAKED void FUN_0807ff78(Entity11_080801b0* p) { INCFUNC("asm/func/FUN_0807ff78.inc"); }

// Entity11_080801b0 Init
NAKED s32 FUN_08080148(Entity11_080801b0* p, Player* player) { INCFUNC("asm/func/FUN_08080148.inc"); }

// Entity11_080801b0 Create
NAKED Entity11_080801b0* FUN_080801b0(Player* player) { INCFUNC("asm/func/FUN_080801b0.inc"); }
