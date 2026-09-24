#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_8
  u16 id;                        // 0x18
  bool8 breakable;               // 0x1A, '.t', 1 なら hp を消費して破壊できる (パレットも別)
  bool8 broken;                  // 0x1B, 1 になると消滅処理に入る
  u16 hp;                        // 0x1C, '.l' (default: 50), 被弾で HitboxData.damage の分だけ減る
  u8 damageTimer;                // 0x1E, 被弾時に 10 がセットされ毎フレーム減る (この間だけ点滅と振動をする)
  u8 unk_1f;                     // 0x1F, padding?
  u32 timer;                     // 0x20, 毎フレーム +1, 被弾して unk_1b が立つときに 0 に戻る
  s32 scriptID;                  // 0x24, '.e', 消滅時に Script_ExecById に渡す
  Vec3 pos;                      // 0x28, '.p'
  HitboxData hitbox;             // 0x30
  MapTileOverride tileOverride;  // 0x80
  AuxSpriteGfx gfx;              // 0x90
  AuxSprite sprite;              // 0xAC
} EntityEC96;
static_assert(sizeof(EntityEC96) == 216);

// 被弾時に呼ばれる。破壊できる相手なら hp を削って 0 未満で壊し、そうでなければ点滅させるだけ
NON_MATCH void FUN_08013288(HitboxData* a, HitboxData* b, EntityEC96* p) {
#ifdef NONMATCHING_C
  Hitbox_ApplyDamage(a, b);
  if (b->damage != 0) {
    if (!p->breakable) {
      p->damageTimer = 10;
      PlaySound_082406e0(0x13E);
    } else {
      if ((s16)(p->hp -= b->damage) < 0) {
        p->broken = TRUE;
        p->timer = 0;
        PlaySound_082406e0(0x14A);
      } else {
        p->damageTimer = 10;
        Video_SetAuxSpritePltt(&p->gfx, 0x132);
        PlaySound_082406e0(0x13E);
      }
    }
    b->damage = 0;
  }
#else
  INCFUNC("asm/func/FUN_08013288.inc");
#endif
}

s32 FUN_08014da0(s32 param_1, s32 param_2, Vec3* pos, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);

// 被弾中は描画位置を揺らし、壊れたら破片を出してスクリプトを実行してから自身を消す
NON_MATCH s32 EntityEC96_Update(EntityEC96* p) {
#ifdef NONMATCHING_C
  u32 idx;

  if (p->broken == 0) {
    if (p->damageTimer != 0) {
      p->sprite.pos = p->pos;
      if (--p->damageTimer == 0) {
        if (p->breakable) Video_SetAuxSpritePltt(&p->gfx, 0x288);
        Hitbox_ClearFlags(&p->hitbox, HBFLAG_UNK_2);
      } else {
        idx = (gRandTableIdx + 1) & 0x3FF;
        p->sprite.pos.x = p->sprite.pos.x - 8 + (gRandomTable[idx] & 0xF);
        gRandTableIdx = (idx + 1) & 0x3FF;
        p->sprite.pos.z = p->sprite.pos.z - 8 + (gRandomTable[gRandTableIdx] & 0xF);
        p->hitbox.flags |= HBFLAG_UNK_2;
      }
    }
  } else {
    FUN_08014da0(3, 4, &p->pos, 0x3C, 0x1E, 0x10, 8, 8, 0, 0x100, 0x18, 0x10);
    FUN_08014da0(8, 8, &p->pos, 0x3C, 0x1E, 0x16, 8, 8, 0, 0x100, 0x18, 0x10);
    if (p->scriptID != 0) Script_ExecById(p->scriptID, NULL);
    KillEntity((Entity*)p);
  }
  p->timer++;
  return 0;
#else
  INCFUNC("asm/func/EntityEC96_Update.inc");
#endif
}

// 当たり判定・マップノード・描画ノードをそれぞれのリストから外す
s32 EntityEC96_Destroy(EntityEC96* p) {
  Hitbox_Unregister(&p->hitbox);
  FUN_082342a8(&p->tileOverride);
  AuxSprite_Remove(&p->sprite);
  return 0;
}

void FUN_08234270(MapTileOverride* p, s32 tileIdx, s32 param_3, s32 height, s32 param_5, s32 param_6);

// スクリプトから位置と耐久を読み、スプライト・当たり判定・マップノードを用意する
s32 EntityEC96_Init(EntityEC96* p, u32 id) {
  AuxSpriteGfx* gfx;
  HitboxData* hitbox;
  Vec3* pos;
  u8* tile;
  s32 bx, bz, idx;
  s32 h;
  u32 z;
  Vec3 size, offset;

  p->id = id;
  p->breakable = VM_GetKeywordValue('t', 0);
  p->broken = 0;
  p->hp = VM_GetKeywordValue('l', 50);
  z = VM_SeekToKeyword('p');
  if (z != 0) {
    p->pos.x = Script_GetValue();
    p->pos.y = Script_GetValue();
    z = Script_GetValue();
  } else {
    p->pos.x = 0;
    p->pos.y = 0;
  }
  p->pos.z = z;
  p->scriptID = VM_GetKeywordValue('e', 0);
  gfx = &p->gfx;
  if (!Video_GetAuxSprite(gfx, SPRITE_PLANT_2567)) {
    return -1;
  }
  AuxSprite_Add(&p->sprite, gfx, 0);
  p->sprite.pos = p->pos;
  if (p->breakable == 1) {
    Video_SetAuxSpritePltt(gfx, 0x288);
  } else {
    Video_SetAuxSpritePltt(gfx, 0x287);
  }
  hitbox = &p->hitbox;
  size.x = 0x82, size.y = 0x80, size.z = 0x82;
  offset.x = 0, offset.y = 0x80, offset.z = 0;
  Hitbox_Init(hitbox, p->id, HBFLAG_UNK_14 | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  pos = &p->pos;
  Hitbox_SetPos(hitbox, pos, 0);
  Hitbox_SetPowerAndAttributes(hitbox, 0, 0, 0);
  Hitbox_SetHandler(hitbox, FUN_08013288, p);
  Hitbox_Register(hitbox);
  bx = p->pos.x >> 8;
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
  h = *tile & 0xF;
  if (h < 0xF) {
    h++;
  }
  FUN_08234270(&p->tileOverride, idx, 0, h, 0xFF, 0);
  return 0;
}

EntityEC96* EntityEC96_Create(u32 id) {
  EntityEC96* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityEC96));
  if (p != NULL) {
    SetEntityRoutine(p, EntityEC96_Update, EntityEC96_Destroy);
    if (EntityEC96_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
