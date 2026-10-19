#include "constants/item.h"
#include "entity.h"
#include "global.h"
#include "sprite_main.h"

// アイテムアイコン1枚, ワールド座標を持ちアイソメトリック投影でスプライトに落とす
typedef struct {
  u32 unk_00;         // 0x00
  u8 state;           // 0x04, PTR_ARRAY_085aa92c の添字 (0..6)
  bool8 justEntered;  // 0x05, state が変わると 1, ハンドラが落として sprite の SPRFLAG_HIDDEN も落とす
  u8 unk_06;          // 0x06
  u8 kind;            // 0x07, 0/1/3 で次に移る state が変わる
  item32_t itemID;    // 0x08, IsValuable に渡す
  u32 stateTimer;     // 0x0C, state に入ってからのフレーム数
  u16 duration;       // 0x10, stateTimer がここに達すると次の state へ
  u8 playerIdx;       // 0x12, gPlayerPtr の添字
  u8 unk_13[5];       // 0x13
  Vec3 pos;           // 0x18, ワールド座標, Entity08017750_ProjectPos が sprite.pos に投影する
  u16* unk_20;        // 0x20
  MainSprite sprite;  // 0x24
} Entity08017750Elem;
static_assert(sizeof(Entity08017750Elem) == 132);

// アイテムアイコンを8枚まで同時に飛ばすシングルトン
typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_9
  u32 usedMask;                 // 0x018, elems のどのスロットが使用中かのビットマスク
  MainSpriteGfx gfx;            // 0x01C, SPRITE_INVENTORY_ICONS
  Entity08017750Elem elems[8];  // 0x03C
} Entity08017750;
static_assert(sizeof(Entity08017750) == 1116);

IWRAM_DATA Entity08017750* gEntity08017750 = NULL;  // 0x0300006C

void FUN_08017098(Entity08017750*, Entity08017750Elem*, s32);
void FUN_080170e4(Entity08017750*, Entity08017750Elem*, s32);
void FUN_08017160(Entity08017750*, Entity08017750Elem*, s32);
void FUN_080171f4(Entity08017750*, Entity08017750Elem*, s32);
void FUN_080172cc(Entity08017750*, Entity08017750Elem*, s32);
void FUN_08017358(Entity08017750*, Entity08017750Elem*, s32);

void (*const PTR_ARRAY_085aa92c[7])(Entity08017750*, Entity08017750Elem*, s32) = {
    FUN_08017098,
    FUN_080170e4,
    FUN_08017160,
    FUN_080171f4,
    FUN_080170e4,
    FUN_080172cc,
    FUN_08017358,
};  // 0x085AA92C

INCASM("asm/entity_08017750.inc");
