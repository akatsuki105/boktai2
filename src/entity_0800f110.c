#include "animation.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"

typedef struct Entity0800f110Data {
  u8 unk_0[0x20];
  HitboxData* hitbox_20;            // 0x20
  void* unk_24;                     // 0x24
  u8 unk_28[0xEC - 0x28];           // 0x28
  struct Entity0800f110Data* prev;  // 0xEC
  struct Entity0800f110Data* next;  // 0xF0
} Entity0800f110Data;
static_assert(sizeof(Entity0800f110Data) == 244);

typedef struct Entity0800f110 {
  Entity e;                  // ENTITY_UNK_8
  AnimationFile* anim;       // 0x18
  Entity0800f110Data* list;  // 0x1C
} Entity0800f110;
static_assert(sizeof(Entity0800f110) == 32);

extern Entity0800f110* gEntity0800f110;  // 0x03002B3C

const ActorSpriteID16 u16_ARRAY_085aa790[8] = {
    SPRITE_863A,
    SPRITE_9D3F,
    SPRITE_SPIKEBALL,
    0x0,
};  // 0x085aa790

void FUN_0800e9e8(Entity0800f110Data*);
void FUN_0800eacc(Entity0800f110Data*);
void FUN_0800ee3c(Entity0800f110Data*);
void FUN_0800ef08(Entity0800f110Data*);
void FUN_0800ec08(Entity0800f110Data*);
void FUN_0800ed14(Entity0800f110Data*);

void (*const PTR_ARRAY_085aa7a0[28])(Entity0800f110Data*) = {
    FUN_0800e9e8, FUN_0800eacc, FUN_0800ee3c, FUN_0800ef08, FUN_0800e9e8, FUN_0800ec08, FUN_0800ec08, FUN_0800ec08, FUN_0800e9e8, FUN_0800ed14, FUN_0800ed14, FUN_0800ed14,
};  // 0x085aa7a0

void FUN_0800e49c(void) { gEntity0800f110 = NULL; }

INCASM("asm/entity_0800f110.inc");

NAKED void FUN_0800ef08(Entity0800f110Data* p) { INCFUNC("asm/func/FUN_0800ef08.inc"); }

NAKED s32 Entity0800f110_Update(Entity0800f110* p) { INCFUNC("asm/func/Entity0800f110_Update.inc"); }

NAKED s32 Entity0800f110_Destroy(Entity0800f110* p) { INCFUNC("asm/func/Entity0800f110_Destroy.inc"); }

s32 Entity0800f110_Init(Entity0800f110* p, u32 _) {
  gEntity0800f110 = p;
  p->anim = GetFile(DIR_ANIMATION, 0x931E);
  p->list = NULL;
  return 0;
}

Entity0800f110* Entity0800f110_Create(u32 _) {
  Entity0800f110* p;
  if (gEntity0800f110 == NULL) {
    p = CreateEntity(ENTITY_UNK_8, sizeof(Entity0800f110));
    if (p != NULL) {
      SetEntityRoutine(p, Entity0800f110_Update, Entity0800f110_Destroy);
      if (Entity0800f110_Init(p, _) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity0800f110;
}
