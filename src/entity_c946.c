#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct EntityC946 {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[0x1c - 0x18];
  u32 unk_1c;    // 0x01C
  u8 unk_20[6];  // 0x020
  u16 unk_26;    // 0x026
  u8 unk_28[0x30c - 0x28];
  AuxSprite spr_30c;     // 0x30C
  AuxSpriteGfx gfx_338;  // 0x338
  u16 x_354;             // 0x354
  u16 y_356;             // 0x356
  u8 unk_358[884 - 0x358];
} EntityC946;
static_assert(sizeof(EntityC946) == 884);

INCASM("asm/entity_c946.inc");

NAKED s32 FUN_0820f9dc(EntityC946* p, s32 val) { INCFUNC("asm/func/FUN_0820f9dc.inc"); }

NAKED void FUN_0820fa80(EntityC946* p, s32 val) { INCFUNC("asm/func/FUN_0820fa80.inc"); }

NAKED void EntityC946_Update_Helper_0820fb20(EntityC946* p) { INCFUNC("asm/func/EntityC946_Update_Helper_0820fb20.inc"); }

NAKED s32 EntityC946_Update(EntityC946* p) { INCFUNC("asm/func/EntityC946_Update.inc"); }

NAKED s32 EntityC946_Destroy(EntityC946* p) { INCFUNC("asm/func/EntityC946_Destroy.inc"); }

NAKED s32 EntityC946_Init(EntityC946* p, u32 _) { INCFUNC("asm/func/EntityC946_Init.inc"); }

EntityC946* EntityC946_Create(u32 arg, u32 _) {
  EntityC946* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityC946));
  if (p != NULL) {
    SetEntityRoutine(p, EntityC946_Update, EntityC946_Destroy);
    if (EntityC946_Init(p, arg) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_0820fe94(EntityC946* p, u32 val) { p->unk_26 = val; }

// 多関節の魔物1体ぶんの、5枚のスプライトの並べ方
typedef struct {
  s8 offset[5][2];  // 0x00, [i][0] を x_354 に、[i][1] を 0x356 に足して i 番目の器の座標にする
  u16 pose[5];      // 0x0A, i 番目の器に渡す FUN_08055b5c の第2引数。i == 0 だけ direction 由来の向きを伴う
} EnemyDexSegments;
static_assert(sizeof(EnemyDexSegments) == 20);

// 魔物図鑑の9グループそれぞれの先頭エントリ番号。FUN_0820cbdc が返す。sEnemyDexGroupCounts の累積和
static const s32 sEnemyDexGroupStarts[9] = {0, 7, 14, 21, 27, 34, 41, 48, 50};  // 0x085AF034

// 魔物図鑑の9グループそれぞれの件数。FUN_0820cbec が返す。合計57 = EnemyDexMenu.entries[57]
static const s32 sEnemyDexGroupCounts[9] = {7, 7, 7, 6, 7, 7, 7, 2, 7};  // 0x085AF058

// 魔物図鑑の5分割それぞれの件数。FUN_0820cbfc が返し、FUN_0820cc0c がその累積和を先頭番号として返す。合計57
static const s32 sEnemyDexCategoryCounts[5] = {21, 6, 14, 9, 7};  // 0x085AF07C

// 魔物図鑑メニューの UI スプライトのポーズ番号。FUN_0820d6e4 が EnemyDexMenu+0x18C から5枚を登録するループで引く
static const u32 sEnemyDexUIPoses1[5] = {17, 18, 19, 20, 21};  // 0x085AF090

// 同上。EnemyDexMenu+0x36C から3枚
static const u32 sEnemyDexUIPoses2[3] = {1, 2, 3};  // 0x085AF0A4

// 多関節の魔物の節の並べ方。EnemyDexModel の 9 / 19 / 20 番の onLoad / onUpdate がそれぞれ [0] / [1] / [2] を名指しする
static const EnemyDexSegments sEnemyDexSegments[3] = {
    // 0x085AF0B0
    {{{0, -12}, {6, -10}, {12, -2}, {8, 6}, {0, 15}},    {0, 2, 2, 2, 1}},
    {{{-12, 0}, {0, -10}, {10, -1}, {16, 12}, {16, 27}}, {5, 6, 6, 6, 6}},
    {{{-12, 0}, {0, -10}, {10, 0}, {16, 15}, {16, 29}},  {8, 9, 9, 9, 9}},
};

INCBIN(".rodata", "data/entity_c946.bin");  // ./tmp/bin.sh ./baserom.gba 0x085af0ec 0x085af9ac ./data/entity_c946.bin
