#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

// 不使用?
// スプライト8枚を数珠つなぎに追従させる蛇, 先頭を下げながら 51 フレームだけ動く
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_8
  u32 frameCounter;       // 0x018, 51 に達すると _Update が何もしなくなる
  AuxSpriteGfx gfx;       // 0x01C, SPRITE_WORM_0
  AuxSprite sprites[8];   // 0x038, [0] が先頭, 後続は前の節へ一定距離まで引き寄せられる
  AuxAnimState anim;      // 0x198, 8枚で共有する再生状態
  AuxAnimFile* animFile;  // 0x1A8, ANIM_WORM
  u8 unk_1ac[64];         // 0x1AC, この型の Create/Init/Update/Destroy からは触られていない
  u16 unk_1ec;            // 0x1EC, _Init が 0 を入れる
  u16 unk_1ee;            // 0x1EE, _Init が 0 を入れる
  u16 unk_1f0;            // 0x1F0, _Init が 0 を入れる
  u16 unk_1f2;            // 0x1F2, _Init が 0 を入れる
} Entity3FFD;
static_assert(sizeof(Entity3FFD) == 500);

s32 FUN_081fa26c(Vec3* _) { return 0; }

NAKED s32 Entity3FFD_Update(Entity3FFD* p) { INCFUNC("asm/func/Entity3FFD_Update.inc"); }

s32 Entity3FFD_Destroy(Entity3FFD* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    AuxSprite_Remove(&p->sprites[i]);
  }
}

NAKED s32 Entity3FFD_Init(Entity3FFD* p, u32 id) { INCFUNC("asm/func/Entity3FFD_Init.inc"); }

Entity3FFD* Entity3FFD_Create(u32 id, u32 _) {
  Entity3FFD* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity3FFD));

  if (p != NULL) {
    SetEntityRoutine(p, Entity3FFD_Update, Entity3FFD_Destroy);
    if (Entity3FFD_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
