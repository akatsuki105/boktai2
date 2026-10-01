#include "entity.h"
#include "global.h"
#include "menu.h"
#include "sprite.h"
#include "sprite_main.h"
#include "sprite_pltt.h"

typedef struct EntityE02E EntityE02E;
typedef void(EntityE02EFunc)(EntityE02E* p);

struct EntityE02E {
  Entity e;                      // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;            // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx gfx1;            // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;            // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[47];        // 0x0078, _Destroy がまとめて MainSprite_Remove する, [44] がカーソル
  MenuSpritePair pair0;          // 0x1218, SPRITE_INVENTORY_ICONS
  u8 unk_12f8[0x130C - 0x12F8];  // 0x12F8, まだ未解析
  MenuSpritePair pair1;          // 0x130C, SPRITE_UI_START_MENU
  u32* tilemap;                  // 0x13EC, TILEMAP_9F57
  rgb555* bgPltt;                // 0x13F0, GetFile(DIR_BGPLTT, 0xA41A) + 0x1B4
  u8* unk_13f4;                  // 0x13F4, '.i' の FUN_0823d340 の戻り値
  u8* unk_13f8;                  // 0x13F8, '.w' の FUN_0823d340 の戻り値
  u8* unk_13fc;                  // 0x13FC, '.a' の FUN_0823d340 の戻り値
  u8* unk_1400;                  // 0x1400, '.s' の FUN_0823d340 の戻り値
  u8 unk_1404[0x140E - 0x1404];  // 0x1404, まだ未解析
  u16 stateTimer;                // 0x140E, FUN_080b5ab0 が fn を差し替えるときに 0 に戻す
  u8 unk_1410;                   // 0x1410, FUN_080b8920 が 0 を入れる
  u8 count;                      // 0x1411, '.n' の値, kinds の個数
  u8 unk_1412[2];                // 0x1412, まだ未解析
  u8 kinds[5];                   // 0x1414, '.l' から count 個
  u8 unk_1419[5];                // 0x1419, kinds ごとに 'P' / 'Z' / 'S'
  u8 unk_141e[5];                // 0x141E, kinds ごとに 3 / 5 / 7
  u8 unk_1423[5];                // 0x1423, kinds ごとに 0x2C / 0x2D / 0x10
  MenuCursor cursor;             // 0x1428, FUN_080b9ff8(&cursor, 0, 0, 0, 4)
  u8 unk_1458[0x1478 - 0x1458];  // 0x1458, まだ未解析
  u8 kind;                       // 0x1478, 0=ソーラーバンク 1=闇の借金 それ以外=ソーラースタンド
  u8 unk_1479[0x1490 - 0x1479];  // 0x1479, まだ未解析
  u32 unk_1490;                  // 0x1490, '.e' の値 (なければ 0)
  EntityE02EFunc* fn;            // 0x1494, _Update が毎フレーム呼ぶ, FUN_080b5ab0 が差し替える
  u8 unk_1498[4];                // 0x1498, まだ未解析
};
static_assert(sizeof(EntityE02E) == 5276);

INCASM("asm/entity_e02e.inc");
