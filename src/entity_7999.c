#include "entity.h"
#include "global.h"
#include "sprite_main.h"
#include "video.h"

struct Entity7999;

typedef void Entity7999Func(struct Entity7999* p);

typedef struct Entity7999 {
  Entity e;                   // 0x000, ENTITY_UNK_11
  void* tilemap;              // 0x018, GetFile(DIR_TILE_MAP, 0xCD91)
  void* pltt;                 // 0x01C, GetFile(DIR_BGPLTT, 0x26BB) + 0x14. gBgPlttBuffer へ 0x100 ワード転送する
  MainSprite sprites[5];      // 0x020, FUN_081da468 が stride 0x60 で pos を書き換える5枚
  MainSpriteGfx gfxLink;      // 0x200, OpenSpriteSetFile(GetFile(DIR_SPRITE_SETS, UI_LINK))
  MainSpriteGfx gfxIcon;      // 0x220, OpenSpriteSetFile(GetFile(DIR_SPRITE_SETS, INVENTORY_ICON))
  void* fileLink;             // 0x240, GetFile(DIR_SPRITE_SETS, UI_LINK)
  void* fileIcon;             // 0x244, GetFile(DIR_SPRITE_SETS, INVENTORY_ICON)
  rgb555 savedPltt[16];       // 0x248, _SavePltt が gObjPlttData + 0x2930 から16色コピーする
  u16 unk_268;                // 0x268, _SavePltt が 0 を入れる
  u8 unk_26a[2];              // 0x26A, 読み手も書き手も見つかっていない
  Entity7999Func* fn;         // 0x26C, _Init が FUN_081da930 を入れる
  u8* script;                 // 0x270, '.s' の後の FUN_0823d340() の戻り値, NULL なら _Init が失敗する
  u32 flags;                  // 0x274, _InitPanels が bit0 を立てる
  s32 windowID0;              // 0x278, TextPanel_Create(0x12, 4, 10, 2)
  s32 windowID1;              // 0x27C, TextPanel_Create(0x12, 8, 10, 2)
  s32 windowID2;              // 0x280, TextPanel_Create(0x10, 0xC, 0xC, 2)
  u8 unk_284;                 // 0x284, _Init が 0 を入れる
  u8 unk_285;                 // 0x285, 読み手も書き手も見つかっていない
  u8 unk_286;                 // 0x286, gEntity9A9F->unk_15c + 0x40 の写し, 0/1/2 で分岐する種別
  u8 unk_287;                 // 0x287, 同 +0x41 の写し
  u8 unk_288;                 // 0x288, 同 +0x42 の写し
  u8 unk_289[0x298 - 0x289];  // 0x289, まだ未解析 (FUN_081da468 / FUN_081d9e50 などが触る)
  u8 unk_298;                 // 0x298, _Init が -1 を入れる
  u8 unk_299;                 // 0x299, _Init が -1 を入れる
  u8 unk_29a;                 // 0x29A, _Init が -1 を入れる
  u8 unk_29b;                 // 0x29B, _Init が 0xFF を入れる
  u8 unk_29c;                 // 0x29C, _Init が 1 を入れる
  u8 unk_29d[3];              // 0x29D, FUN_081da468 が添字として読む
  u16 unk_2a0;                // 0x2A0, _Init が '.l' を入れる
  u16 unk_2a2;                // 0x2A2, _Init が '.e' を入れる
} Entity7999;
static_assert(sizeof(Entity7999) == 676);

INCASM("asm/entity_7999.inc");
