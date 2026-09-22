#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"
#include "sprite_aux.h"
#include "vm.h"

// スクリプトから置かれる当たり判定付きのオブジェクト。位置はマップのタイル座標から決まる
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_8
  u16 id;              // 0x18, EntityE06A_Init の引数。ヒットボックスの所有者IDとして Hitbox_Init に渡る
  u8 unk_1a[2];        // 0x1A, 読み書きとも未発見 (sprite の4バイト境界合わせ)
  AuxSprite sprite;    // 0x1C, 根拠: AuxSprite_Add / AuxSprite_Remove に渡される
  AuxSpriteGfx gfx;    // 0x48, 根拠: Video_GetAuxSprite(&gfx, 0x9DA7) / AuxSprite_Add に渡される
  HitboxData hitbox;   // 0x64, 根拠: EntityE06A_SetupHitbox が組み立て、EntityE06A_Update が毎フレーム更新する
  HitboxData hitbox2;  // 0xB4, 組み立てるのは EntityE06A_SetupHitbox2 だが、その呼び出し元は未発見
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

// スクリプトのキーワード 'p' から位置を読み、足元のタイルの高さと階段の向きで y を補正する
void EntityE06A_SetupSprite(EntityE06A* p) {
  Vec3* pos;
  u8* tile;
  s32 bx, bz, idx;
  s32 y, stairs;
  u32 z;

  AuxSpriteGfx* gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_NODATA_9DA7);
  AuxSprite_Add(&p->sprite, gfx, 0);
  z = VM_SeekToKeyword('p');
  if (z != 0) {
    p->sprite.pos.x = Script_GetValue();
    p->sprite.pos.y = Script_GetValue();
    z = Script_GetValue();
  } else {
    p->sprite.pos.x = 0;
    p->sprite.pos.y = 0;
  }
  p->sprite.pos.z = z;
  pos = &p->sprite.pos;
  bx = p->sprite.pos.x >> 8;
  bz = pos->z >> 8;
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  tile = (u8*)FUN_08234224(idx, 1);
  if (tile != NULL) {
    tile += 4;
  } else {
    tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
  }
  stairs = *tile >> 4;
  y = (*tile & 0xF) << 8;
  switch (stairs) {
    case 1: {
      y -= (u8)pos->z;
      break;
    }
    case 2: {
      y -= (u8)pos->x;
      break;
    }
  }
  p->sprite.pos.y = y;
}

// hitbox を組み立てて登録する
void EntityE06A_SetupHitbox(EntityE06A* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size;
  Vec3 offset;

  size.x = 0x32, size.y = 100, size.z = 0x32;
  offset.x = 0, offset.y = 100, offset.z = 0;
  Hitbox_Init(hitbox, p->id, HBFLAG_UNK_13 | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetAttack(hitbox, 100, 0x78, 0, 0x40002, 0x1E);
  Hitbox_SetHandler(hitbox, nop_080cb254, p);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  Hitbox_Register(hitbox);
}

// hitbox2 を組み立てて登録する。呼び出し元は未発見
void EntityE06A_SetupHitbox2(EntityE06A* p) {
  HitboxData* hitbox = &p->hitbox2;
  Vec3 size;
  Vec3 offset;

  size.x = 0x32, size.y = 100, size.z = 0x32;
  offset.x = 0, offset.y = 100, offset.z = 0;
  Hitbox_Init(hitbox, p->id, HBFLAG_UNK_14 | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, 10, 2, 1);
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
