#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "sprite.h"
#include "vm.h"

// 未使用っぽい, スクリプトから置かれる当たり判定付きのオブジェクト, 位置はマップのタイル座標から決まる
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_8
  u16 id;              // 0x18, EntityE06A_Init の引数, ヒットボックスの所有者IDとして Hitbox_Init に渡る
  u8 unk_1a[2];        // 0x1A, padding?
  AuxSprite sprite;    // 0x1C
  AuxSpriteGfx gfx;    // 0x48, SPRITE_NODATA_9DA7
  HitboxData hitbox;   // 0x64
  HitboxData hurtbox;  // 0xB4
} EntityE06A;
static_assert(sizeof(EntityE06A) == 260);

void nop_080cb254(void) {}

void nop_080cb258(void) {}

s32 EntityE06A_Update(EntityE06A* p) {
  Hitbox_SetPos(&p->hitbox, &p->sprite.pos, 0);
  Hitbox_Register(&p->hitbox);
  return 0;
}

s32 EntityE06A_Destroy(EntityE06A* p) {
  AuxSprite_Remove(&p->sprite);
  return 0;
}

// '.p' から位置を読み、足元のタイルの高さと階段の向きで y を補正する
void EntityE06A_SetupSprite(EntityE06A* p) {
  AuxSpriteGfx* gfx = &p->gfx;

  Video_GetAuxSprite(gfx, SPRITE_NODATA_9DA7);
  AuxSprite_Add(&p->sprite, gfx, 0);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(p->sprite.pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(p->sprite.pos, 0, 0, 0);
  }
  p->sprite.pos.y = TileHeightAt(&p->sprite.pos);
}

// hitbox を組み立てて登録する
void EntityE06A_SetupHitbox(EntityE06A* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size, offset;

  VEC3_SET(size, 50, 100, 50);
  VEC3_SET(offset, 0, 100, 0);
  Hitbox_Init(hitbox, p->id, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetAttack(hitbox, 100, 0x78, 0, HBATTR_18 | HBATTR_DARK, 0x1E);
  Hitbox_SetHandler(hitbox, nop_080cb254, p);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  Hitbox_Register(hitbox);
}

// hurtbox を組み立てて登録する, 呼び出し元は未発見
void EntityE06A_SetupHurtbox(EntityE06A* p) {
  HitboxData* hitbox = &p->hurtbox;
  Vec3 size, offset;

  VEC3_SET(size, 50, 100, 50);
  VEC3_SET(offset, 0, 100, 0);
  Hitbox_Init(hitbox, p->id, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, 10, HBATTR_DARK, HBATTR_SOL);
  Hitbox_SetHandler(hitbox, nop_080cb258, p);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  Hitbox_Register(hitbox);
}

s32 EntityE06A_Init(EntityE06A* p, u32 id, u32 _) {
  p->id = id;
  EntityE06A_SetupSprite(p);
  EntityE06A_SetupHitbox(p);
  return 0;
}

// 0xE06A
EntityE06A* EntityE06A_Create(u32 id, u32 _) {
  EntityE06A* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityE06A));

  if (p != NULL) {
    SetEntityRoutine(p, EntityE06A_Update, EntityE06A_Destroy);
    if (EntityE06A_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
