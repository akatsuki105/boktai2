#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// 暗黒樹のツタ, 触るとダメージを受ける植物の障害物で通路を塞ぐ (奥の楔の部屋への入口を塞いでいるらしい), インスタンスIDはクラスと同じ 0xEC96
// '.t' が 1 なら hp を削って壊せ, 壊れると破片を出して '.e' のスクリプトを実行してから消える, 0 なら壊せず被弾で点滅して揺れるだけ
// 暗黒街 (st03_26_slum) では入ってきた入口によって壊せる/壊せないを出し分け, 壊すと W_DARK_VINE_BROKEN が立って以降は出なくなる, 闘技場のドゥラスロール再戦 (Scr_0x0FD2, W_ARENA_RANK で強さが変わる側) にも壊せない形で置かれる
typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_8
  u16 id;                        // 0x18
  bool8 breakable;               // 0x1A, '.t', 1 なら hp を消費して破壊できる (パレットも別)
  bool8 broken;                  // 0x1B, 1 になると消滅処理に入る
  u16 hp;                        // 0x1C, '.l' (default: 50), 被弾で Hitbox.damage の分だけ減る
  u8 damageTimer;                // 0x1E, 被弾時に 10 がセットされ毎フレーム減る (この間だけ点滅と振動をする)
  u8 unk_1f;                     // 0x1F, padding?
  u32 timer;                     // 0x20, 毎フレーム +1, 被弾して unk_1b が立つときに 0 に戻る
  s32 scriptID;                  // 0x24, '.e', 消滅時に VM_ExecByID に渡す
  Vec3 pos;                      // 0x28, '.p'
  Hitbox hurtbox;                // 0x30
  MapTileOverride tileOverride;  // 0x80
  AuxSpriteGfx gfx;              // 0x90, SPRITE_PLANT_2567
  AuxSprite sprite;              // 0xAC
} DarkVine;
static_assert(sizeof(DarkVine) == 216);

// 被弾時に呼ばれる, 破壊できる相手なら hp を削って 0 未満で壊し、そうでなければ点滅させるだけ
NON_MATCH void DarkVine_OnHurt(Hitbox* a, Hitbox* b, DarkVine* p) {
#ifdef NONMATCHING_C
  Hitbox_ApplyDamage(a, b);
  if (b->damage != 0) {
    if (!p->breakable) {
      p->damageTimer = 10;
      PlaySound_082406e0(SE_ENEMY_DAMAGED);
    } else {
      if ((s16)(p->hp -= b->damage) < 0) {
        p->broken = TRUE;
        p->timer = 0;
        PlaySound_082406e0(SE_330);
      } else {
        p->damageTimer = 10;
        Video_SetAuxSpritePltt(&p->gfx, OBP_WHITE_306);
        PlaySound_082406e0(SE_ENEMY_DAMAGED);
      }
    }
    b->damage = 0;
  }
#else
  INCFUNC("asm/func/DarkVine_OnHurt.inc");
#endif
}

s32 FUN_08014da0(s32 param_1, s32 param_2, Vec3* pos, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);

// 被弾中は描画位置を揺らし、壊れたら破片を出してスクリプトを実行してから自身を消す
NON_MATCH s32 DarkVine_Update(DarkVine* p) {
#ifdef NONMATCHING_C
  u32 idx;

  if (p->broken == 0) {
    if (p->damageTimer != 0) {
      p->sprite.pos = p->pos;
      if (--p->damageTimer == 0) {
        if (p->breakable) Video_SetAuxSpritePltt(&p->gfx, 648);
        Hitbox_ClearFlags(&p->hurtbox, HBF_HIDDEN);
      } else {
        idx = (gRandTableIdx + 1) & 0x3FF;
        p->sprite.pos.x = p->sprite.pos.x - 8 + (gRandomTable[idx] & 0xF);
        gRandTableIdx = (idx + 1) & 0x3FF;
        p->sprite.pos.z = p->sprite.pos.z - 8 + (gRandomTable[gRandTableIdx] & 0xF);
        p->hurtbox.flags |= HBF_HIDDEN;
      }
    }
  } else {
    FUN_08014da0(3, 4, &p->pos, 0x3C, 0x1E, 0x10, 8, 8, 0, 0x100, 0x18, 0x10);
    FUN_08014da0(8, 8, &p->pos, 0x3C, 0x1E, 0x16, 8, 8, 0, 0x100, 0x18, 0x10);
    if (p->scriptID != 0) VM_ExecByID(p->scriptID, NULL);
    KillEntity((Entity*)p);
  }
  p->timer++;
  return 0;
#else
  INCFUNC("asm/func/DarkVine_Update.inc");
#endif
}

// 当たり判定・マップノード・描画ノードをそれぞれのリストから外す
s32 DarkVine_Destroy(DarkVine* p) {
  Hitbox_Unregister(&p->hurtbox);
  Map_RemoveTileOverride(&p->tileOverride);
  AuxSprite_Remove(&p->sprite);
  return 0;
}

// スクリプトから位置と耐久を読み、スプライト・当たり判定・マップノードを用意する
s32 DarkVine_Init(DarkVine* p, u32 id) {
  AuxSpriteGfx* gfx;
  Hitbox* hurtbox;
  Vec3* pos;
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 tx, tz, idx;
  s32 h;
  Vec3 size, offset;

  p->id = id;
  p->breakable = VM_GetNamedArgValue('t', 0);
  p->broken = 0;
  p->hp = VM_GetNamedArgValue('l', 50);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(p->pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(p->pos, 0, 0, 0);
  }
  p->scriptID = VM_GetNamedArgValue('e', 0);
  gfx = &p->gfx;
  if (!Video_GetAuxSprite(gfx, SPRITE_PLANT_2567)) {
    return -1;
  }
  AuxSprite_Add(&p->sprite, gfx, 0);
  p->sprite.pos = p->pos;
  if (p->breakable == 1) {
    Video_SetAuxSpritePltt(gfx, 648);
  } else {
    Video_SetAuxSpritePltt(gfx, 647);
  }

  hurtbox = &p->hurtbox;
  VEC3_SET(size, Q8(0.51), Q8(0.5), Q8(0.51));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, p->id, HBF_HURTBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  pos = &p->pos;
  Hitbox_SetPos(hurtbox, pos, 0);
  Hitbox_SetPowerAndAttributes(hurtbox, 0, 0, 0);
  Hitbox_SetHandler(hurtbox, DarkVine_OnHurt, p);
  Hitbox_Register(hurtbox);

  tx = pos->x >> 8;
  tz = pos->z >> 8;
  if (IsOutsideMap(tx, tz)) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[tz] + tx;
  }
  ov = Map_FindTileOverride(idx, 1);
  tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
  h = tile->heightStairs & 0xF;
  if (h < 0xF) {
    h++;
  }
  Map_AddTileOverride(&p->tileOverride, idx, STAIRS_NONE, h, 0xFF, 0);
  return 0;
}

// 0xEC96, HashName("暗黒つた")?
DarkVine* DarkVine_Create(u32 id) {
  DarkVine* p = CreateEntity(ENTITY_UNK_8, sizeof(DarkVine));
  if (p != NULL) {
    SetEntityRoutine(p, DarkVine_Update, DarkVine_Destroy);
    if (DarkVine_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
