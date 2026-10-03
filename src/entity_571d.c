#include "entity.h"
#include "global.h"
#include "menu.h"
#include "sprite.h"
#include "tilemap.h"

typedef struct Entity571D Entity571D;
typedef void(Entity571DFunc)(Entity571D* p);

// 太陽バンクのメニュー?
struct Entity571D {
  Entity e;                   // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx0;         // 0x0018, SPRITE_UI_START_MENU
  MainSpriteGfx gfx1;         // 0x0038, SPRITE_INVENTORY_ICONS
  MainSpriteGfx gfx2;         // 0x0058, SPRITE_UI_MISC
  MainSprite sprites[38];     // 0x0078, [1..16] と [17..28] がアイテム枠2面, [30] がカーソル
  Tilemaps* tilemap;          // 0x0EB8, TILEMAP_9F57
  rgb555* bgPltt;             // 0x0EBC, BGP_A41A[208]
  u8* unk_ec0;                // 0x0EC0, '.s' があれば FUN_0823d340 の戻り値
  u8* unk_ec4;                // 0x0EC4, '.i' があれば FUN_0823d340 の戻り値
  u8 unk_ec8[2];              // 0x0EC8, まだ未解析
  u16 stateTimer;             // 0x0ECA, FUN_080beadc が fn を差し替えるときに 0 に戻す
  s8 items[16];               // 0x0ECC, '.O' から12個読んで残りは -1. [12..15] には [8..11] の写し
  MenuSpritePair pair0;       // 0x0EDC, SPRITE_INVENTORY_ICONS
  u8 unk_fbc[0xFD0 - 0xFBC];  // 0x0FBC, まだ未解析
  MenuCursor cursor;          // 0x0FD0, FUN_080b9ff8(&cursor, 1, 4, 0, 29)
  MenuSpritePair pair1;       // 0x1000, SPRITE_UI_START_MENU
  u8 kind;                    // 0x10E0, 0=太陽バンク 1=暗黒ローン それ以外=太陽スタンド
  u8 unk_10e1;                // 0x10E1, _Init が 0 を入れる
  u8 unk_10e2;                // 0x10E2, _Init が 0 を入れる
  u8 unk_10e3;                // 0x10E3, まだ未解析
  u32 unk_10e4;               // 0x10E4, '.e' (なければ 0)
  Entity571DFunc* fn;         // 0x10E8, _Update が毎フレーム呼ぶ, FUN_080beadc が差し替える
  u8 unk_10ec[4];             // 0x10EC, まだ未解析
};
static_assert(sizeof(Entity571D) == 4336);

void FUN_080b94cc(s32 kind);
void FUN_080b9400(s32 kind);
void FUN_080b9a0c(MenuSpritePair* p);
void FUN_080b9894(MenuSpritePair* p);

INCASM("asm/entity_571d.inc");

s32 Entity571D_Update(Entity571D* p) {
  FUN_080b94cc(p->kind);
  FUN_080b9400(p->kind);
  p->fn(p);
  return 0;
}

s32 Entity571D_Destroy(Entity571D* p) {
  s32 i;

  for (i = 0; i < 38; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  FUN_080b9a0c(&p->pair0);
  FUN_080b9894(&p->pair1);
  return 0;
}

NAKED s32 Entity571D_Init(Entity571D* p) { INCFUNC("asm/func/Entity571D_Init.inc"); }

Entity571D* Entity571D_Create(void) {
  Entity571D* p = CreateEntity(ENTITY_UNK_11, sizeof(Entity571D));

  if (p != NULL) {
    SetEntityRoutine(p, Entity571D_Update, Entity571D_Destroy);
    if (Entity571D_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
