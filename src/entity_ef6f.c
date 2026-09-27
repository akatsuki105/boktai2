#include "entity.h"
#include "global.h"
#include "particle.h"
#include "sprite_main.h"
#include "weapon.h"

typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  u8 unk_18[0x01B - 0x018];   // 0x018, まだ未解析
  u8 unk_1b;                  // 0x01B, _Init が 0 を入れる
  u8 unk_1c[2];               // 0x01C, まだ未解析
  u16 unk_1e;                 // 0x01E, _Init が 0 を入れる
  u8 unk_20[0x090 - 0x020];   // 0x020, まだ未解析
  s32 unk_90;                 // 0x090, _Init が書き込む
  u8 unk_94[0x0B0 - 0x094];   // 0x094, まだ未解析
  MainSpriteGfx gfx0;         // 0x0B0, SPRITE_UI_MISC
  MainSpriteGfx gfx1;         // 0x0D0, SPRITE_UI_START_MENU
  MainSpriteGfx gfx2;         // 0x0F0, OpenSpriteSetFile で開くスプライトセット
  MainSpriteGfx gfx3;         // 0x110, OpenSpriteSetFile で開くスプライトセット
  s32 unk_130;                // 0x130, _Init が書き込み先として使う
  Particle ptcls[4];          // 0x134, _Destroy が stride 0x28 で4個 Particle_Remove する
  WeaponData weapon;          // 0x1D4, _Init が gWeaponDB[0x0F] を丸ごとコピーする
  u8 unk_1f8[0x6D8 - 0x1F8];  // 0x1F8, まだ未解析
  MainSprite sprite;          // 0x6D8, _Destroy が MainSprite_Remove に渡す
  u8 unk_738[0x758 - 0x738];  // 0x738, まだ未解析
  u8* unk_758;                // 0x758, _Init がポインタを入れる
  u8 unk_75c[1884 - 0x75C];   // 0x75C, まだ未解析
} EntityEF6F;
static_assert(sizeof(EntityEF6F) == 1884);

INCASM("asm/entity_ef6f.inc");
