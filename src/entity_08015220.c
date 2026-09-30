#include "entity.h"
#include "global.h"
#include "sprite.h"

// 破片の1グループ, Entity08015220_Init が 4 グループぶんまとめて初期化する
typedef struct {
  bool8 active;             // 0x000, 0 以外なら _Update が FUN_08015074 を呼び、_Destroy がスプライトを外す
  u8 unk_001[0x2C - 1];     // 0x001
  bool8 used[6];            // 0x02C, sprites の各要素が登録済みか, _Init が 0 で埋める
  u8 unk_032[0x70 - 0x32];  // 0x032
  AuxSprite sprites[6];     // 0x070, _Destroy が使用済みのものを AuxSprite_Remove に渡す
} Entity08015220Group;
static_assert(sizeof(Entity08015220Group) == 376);

typedef struct {
  Entity e;                       // 0x000, ENTITY_UNK_10
  s32 timer;                      // 0x018, _Update が毎フレーム +1 する
  u8 unk_01c[4];                  // 0x01C
  Entity08015220Group groups[4];  // 0x020
} Entity08015220;
static_assert(sizeof(Entity08015220) == 1536);

IWRAM_DATA Entity08015220* gEntity08015220 = NULL;  // 0x0300005C

const u16 u16_ARRAY_085aa8f0[9] = {
    0x3, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
};  // 0x085AA8F0

const SpriteID16 u16_ARRAY_085aa902[9] = {
    SPRITE_CUBE_ICE, SPRITE_CUBE_WOOD_DEBRIS_L, SPRITE_CUBE_ROCK_DEBRIS_L, SPRITE_DEBRIS_C42D, 0xDF0E, SPRITE_CUBE_WOOD_DEBRIS_S, SPRITE_CUBE_ROCK_DEBRIS_S, SPRITE_DEBRIS_0334, 0x1E15,
};  // 0x085AA902

void FUN_08014d94(void) { gEntity08015220 = NULL; }

NAKED s32 FUN_08014da0(s32 param_1, unknown* param_2, unknown* param_3, unknown* param_4, unknown* param_5, unknown* param_6, unknown* param_7, unknown* param_8, unknown* param_9, unknown* param_10, unknown* param_11, unknown* param_12) { INCFUNC("asm/func/FUN_08014da0.inc"); }

NAKED void FUN_08015074(Entity08015220* p, unknown* data) { INCFUNC("asm/func/FUN_08015074.inc"); }

s32 Entity08015220_Update(Entity08015220* p) {
  Entity08015220Group* g = p->groups;
  s32 i;

  for (i = 0; i < 4; g++, i++) {
    if (g->active) {
      FUN_08015074(p, g);
    }
  }
  p->timer++;
  return 0;
}

s32 Entity08015220_Destroy(Entity08015220* p) {
  Entity08015220Group* g;
  s32 i;
  s32 j;

  for (i = 0; i < 4; i++) {
    g = &p->groups[i];
    if (g->active) {
      for (j = 0; j < 6; j++) {
        if (g->used[j]) {
          AuxSprite_Remove(&g->sprites[j]);
        }
      }
    }
  }
  gEntity08015220 = NULL;
  return 0;
}

s32 Entity08015220_Init(Entity08015220* p, u32 _) {
  Entity08015220Group* g;
  s32 i;
  s32 j;

  for (i = 0; i < 4; i++) {
    g = &p->groups[i];
    g->active = FALSE;
    for (j = 0; j < 6; j++) {
      g->used[j] = FALSE;
    }
  }
  p->timer = 0;
  gEntity08015220 = p;
  return 0;
}

Entity08015220* Entity08015220_Create(u32 val, u32 _) {
  Entity08015220* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity08015220));
  if (p != NULL) {
    SetEntityRoutine(p, Entity08015220_Update, Entity08015220_Destroy);
    if (Entity08015220_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
