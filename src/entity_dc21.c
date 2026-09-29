#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "sprite.h"

typedef struct {
  Entity e;                    // 0x000, ENTITY_UNK_8
  AuxSprite sprite;            // 0x018, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx solarStandGfx;  // 0x044, SPRITE_SOLAR_STATION
  MainSpriteGfx mainGfx;       // 0x060, SPRITE_UI_START_MENU
  MainSprite mainSprites[4];   // 0x080, _Destroy が MainSprite_Remove に渡す4枚
  HitboxData hitbox;           // 0x200, _Destroy が Hitbox_Unregister に渡す
  Vec3 unk_250;                // 0x250, FUN_0809f4b0 が sprite.pos を写して補正する
  Player* player;              // 0x258, _Init が gPlayerPtr[0] を入れる, NULL なら _Init が失敗する
  u16 id;                      // 0x25C, _Create / _Init の第2引数, Hitbox_Init の第2引数にもなる
  u8 unk_25e;                  // 0x25E, _Init が 0 を入れる
  u8 unk_25f;                  // 0x25F, _Init が 0 を入れる
  u8 unk_260;                  // 0x260, _Init が 0 を入れる
  u8 unk_261;                  // 0x261, _Init が 0 を入れる
  u16 unk_262;                 // 0x262, _Init が sprite.flags bit2 のとき 7、そうでなければ 1 を入れる
} EntityDC21;
static_assert(sizeof(EntityDC21) == 612);

INCASM("asm/entity_dc21.inc");
