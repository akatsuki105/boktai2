#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "inline.h"
#include "map_inline.h"
#include "random.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

// ヘルハウンド(炎属性のドッグ系) のファイヤーブレス + それが撒く火の粉

// angle を4方向に丸めた向きの前方に破片を撒くアニメを1回再生して消えるエフェクト1個
typedef struct {
  AuxSprite sprite;   // 0x00
  AuxAnimState anim;  // 0x2C, animIdx 1, variant は angle から決まる
  u8 unk_3c[80];      // 0x3C
  u16 unk_8c;         // 0x8C, 生成時と解放時に 0 が入るだけ
  u8 state;           // 0x8E, PTR_ARRAY_085ae528 の添字 (0: 待機, 1: 今のアニメが終わると animIdx 1 に替えて 2 へ, 2: 破片を撒く, 3: 点滅して消える)
  s8 slotIdx;         // 0x8F, usedMask 上の自分のビット番号, 空きは -1
  u16 timer;          // 0x90, state 3 に入ってからのフレーム数
  bool8 stateBegun;   // 0x92, 立っていると次の更新で state の初期化をする
  u8 angle;           // 0x93, 向き, gSineTable の添字
} Entity081f1770Elem;
static_assert(sizeof(Entity081f1770Elem) == 148);

// 破片を撒くエフェクトを最大20個まで管理するシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;              // 0x018, SPRITE_FIRE_BREATH
  AuxAnimFile* animFile;         // 0x034, ANIM_4EC0
  u32 usedMask;                  // 0x038, elems のどのスロットが使用中かのビットマスク
  Entity081f1770Elem elems[20];  // 0x03C
} Entity081f1770;
static_assert(sizeof(Entity081f1770) == 3020);

static Entity081f1770* gEntity081f1770;  // 0x030001E8

static inline bool8 Entity081f1770_IsUsed(Entity081f1770* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

// angle の向きを 4 方向に丸め, 左右反転とアニメの variant に分ける
static inline void Entity081f1770_GetAnimVariant(u8 angle, u8* variant, u8* xflip) {
  u16 dir = Angle_ToDir4(angle);

  if (dir > 1) {
    *xflip = TRUE;
    *variant = 3 - dir;
  } else {
    *xflip = FALSE;
    *variant = dir;
  }
}

s32 Entity081f1770_Update(Entity081f1770* p);
void* Entity081f26bc_Spawn(Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime, s32 ofsX, s32 ofsY);
s32 Entity081f1770_Destroy(Entity081f1770* p);
s32 Entity081f1770_Init(Entity081f1770* p);
Entity081f1770* Entity081f1770_Create(void);

void Entity081f1770_UpdateIdle(Entity081f1770* p, Entity081f1770Elem* elem) {}

// 空いているスロットを1つ確保して 0 で埋める
Entity081f1770Elem* Entity081f1770_AllocElem(Entity081f1770* p) {
  s32 i;

  for (i = 0; i < 20; i++) {
    if (!Entity081f1770_IsUsed(p, i)) {
      Entity081f1770Elem* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      ClearMemory(elem, sizeof(Entity081f1770Elem));
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

// state 1, 表示して今のアニメを最後まで流し, 終わったら向きに合わせた animIdx 1 に替えて state 2 へ移る
void Entity081f1770_UpdateAppear(Entity081f1770* p, Entity081f1770Elem* elem) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateBegun) {
    AuxSprite_Show(sprite);
    elem->stateBegun = FALSE;
  }
  if (AuxSprite_AdvanceAnim(sprite, &elem->anim)) {
    u8 variant;
    u8 xflip;

    Entity081f1770_GetAnimVariant(elem->angle, &variant, &xflip);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 1, variant, xflip);
    elem->state = 2;
    elem->stateBegun = TRUE;
  }
}

// from から dir の向きに to までタイルを辿り, 階段か高い段差に当たったら TRUE を返す, 段差の壁際なら破片を1つ撒く
// 残差: 破片の高さに足す乱数で gRandTableIdx と表のアドレスを取り直す割当 (prevHeight の再ロード先が r4) が再現できず1命令足りない
NON_MATCH bool8 Entity081f1770_IsPathBlocked(Entity081f1770Elem* elem, Vec3* pos, s32 from, s32 to, s32 dir) {
#ifdef NONMATCHING_C
  Vec3 vel;

  Vec3_Clear(&vel);
  while (from != to) {
    s32 prev = from;
    s32 prevHeight;
    MapTileOverride* ov;
    CollisionMapTile* tile;

    switch (dir) {
      case 0: {
        from++;
        break;
      }
      case 1: {
        from += gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        from--;
        break;
      }
      case 3: {
        from -= gCollisionMap->tiledata->width;
        break;
      }
    }
    ov = Map_FindTileOverride(from, 1);
    tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[from];
    if ((tile->heightStairs >> 4) != STAIRS_NONE) {
      return TRUE;
    }
    ov = Map_FindTileOverride(prev, 1);
    tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[prev];
    prevHeight = tile->heightStairs & 0xF;
    ov = Map_FindTileOverride(from, 1);
    tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[from];
    if (prevHeight < (tile->heightStairs & 0xF)) {
      Vec3 wall;
      s32 life;
      s32 x = Mod(from, gCollisionMap->tiledata->width);
      s32 z = Div(from, gCollisionMap->tiledata->width);

      wall.x = (x << 8) + 128;
      ov = Map_FindTileOverride(from, 1);
      tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[from];
      wall.y = (tile->heightStairs & 0xF) << 8;
      wall.z = (z << 8) + 128;
      switch (dir) {
        case 0: {
          pos->x = wall.x - 128;
          return TRUE;
        }
        case 1: {
          pos->z = wall.z - 128;
          return TRUE;
        }
        case 2: {
          pos->x = wall.x + 128;
          break;
        }
        case 3: {
          pos->z = wall.z + 128;
          break;
        }
      }
      pos->y = (prevHeight << 8) + (u8)Random();
      life = (Random() & 63) + 30;
      Entity081f26bc_Spawn(pos, &vel, 0x1C1A, ANIM_D1B8, 3, 0, 0x31, 0, 1, 0, 0, life, 4, 1, 0x00200004, 30, 8, 8);
      return TRUE;
    }
  }
#else
  INCFUNC("asm/func/Entity081f1770_IsPathBlocked.inc");
#endif
}

// 向きを4方向に丸めた前方に, 段差の小さい床の上にだけ破片を count 個撒く
// 残差: 引数の 0 をループ外で r9 に置く割当と from のスタック退避が再現できず, レジスタが全体にずれる
NON_MATCH void Entity081f1770_SpawnDebris(Entity081f1770Elem* elem, s32 count) {
#ifdef NONMATCHING_C
  Vec3 front;
  Vec3 vel;
  Vec3 pos;
  s32 from;
  s32 i;
  s32 angle = FixToInt(6, (elem->angle + 0x20) & 0xFF) << 6;

  Vec3_SetPolar(&front, angle, 512);
  Vec3_Add(&front, &elem->sprite.pos);
  from = GetCollisionTileIdx(&elem->sprite.pos);
  Vec3_Clear(&vel);
  for (i = 0; i < count; i++) {
    s32 to;

    VEC3_SET(pos, (Random() & 0xFF) - 128, 0, (Random() & 0xFF) - 128);
    Vec3_Add(&pos, &front);
    to = GetCollisionTileIdx(&pos);
    if (!Entity081f1770_IsPathBlocked(elem, &pos, from, to, FixToInt(6, angle))) {
      MapTileOverride* ov;
      CollisionMapTile* tile;

      ov = Map_FindTileOverride(to, 1);
      tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[to];
      if ((tile->heightStairs >> 4) == STAIRS_NONE) {
        s32 fromHeight;
        s32 toHeight;
        s32 diff;

        ov = Map_FindTileOverride(from, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[from];
        fromHeight = tile->heightStairs & 0xF;
        ov = Map_FindTileOverride(to, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[to];
        toHeight = tile->heightStairs & 0xF;
        diff = fromHeight - toHeight;
        if (diff < 0) {
          diff = -diff;
        }
        if (diff <= 1) {
          s32 life;

          pos.y = toHeight << 8;
          life = (Random() & 63) + 20;
          Entity081f26bc_Spawn(&pos, &vel, 0x1C1A, ANIM_D1B8, 3, 0, 0x31, 0, 1, 0, 0, life, 4, 1, 0x00200004, 30, 8, 8);
        }
      }
    }
  }
#else
  INCFUNC("asm/func/Entity081f1770_SpawnDebris.inc");
#endif
}

// state 2, アニメの 4 コマ目に入った瞬間に破片を撒き, アニメが終わったらスロットを空ける
void Entity081f1770_UpdateScatter(Entity081f1770* p, Entity081f1770Elem* elem) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateBegun) {
    AuxSprite_Show(&elem->sprite);
    elem->stateBegun = FALSE;
  }
  if (elem->anim.cmdIdx == 3 && elem->anim.tick == 0) {
    Entity081f1770_SpawnDebris(elem, 4);
  }
  if (AuxSprite_AdvanceAnim(sprite, &elem->anim)) {
    Entity081f1770* e = gEntity081f1770;

    CLEAR_BIT(e->usedMask, elem->slotIdx);
    elem->state = 0;
    AuxSprite_Remove(&elem->sprite);
    elem->slotIdx = -1;
    elem->unk_8c = 0;
    elem->stateBegun = TRUE;
  }
}

// state 3, 点滅させて消し, 消えきったらスロットを空ける
void Entity081f1770_UpdateVanish(Entity081f1770* p, Entity081f1770Elem* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    elem->timer = 0;
  }
  if (Sprite_UpdateVanishBlink(&elem->sprite.flags, elem->timer, 60, 40)) {
    Entity081f1770* e = gEntity081f1770;

    CLEAR_BIT(e->usedMask, elem->slotIdx);
    elem->state = 0;
    AuxSprite_Remove(&elem->sprite);
    elem->slotIdx = -1;
    elem->unk_8c = 0;
  } else {
    elem->timer++;
  }
}

// pos から angle の向きに破片を撒くエフェクトを1つ出す
Entity081f1770Elem* Entity081f1770_Spawn(Vec3* pos, u32 angle, SpriteFlags flags) {
  Entity081f1770* p = gEntity081f1770;
  Entity081f1770Elem* elem;
  AuxSprite* sprite;
  u8 variant;
  u8 xflip;

  if (p == NULL) {
    p = Entity081f1770_Create();
    if (p == NULL) {
      return NULL;
    }
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, FLAG030047A4_GAMEOVER)) {
    return NULL;
  }
  if (TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    return NULL;
  }
  elem = Entity081f1770_AllocElem(p);
  if (elem == NULL) {
    return NULL;
  }
  elem->unk_8c = 0;
  elem->angle = angle;
  elem->stateBegun = TRUE;
  elem->state = 2;
  sprite = &elem->sprite;
  elem->sprite.pos = *pos;
  Entity081f1770_GetAnimVariant(angle, &variant, &xflip);
  AuxSprite_Add(sprite, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, p->animFile, 1, variant, xflip);
  Video_SetAuxSpritePltt(sprite->gfx, 0x1F8);
  AuxSprite_AdvanceAnim(sprite, &elem->anim);
  AuxSprite_Hide(sprite);
  sprite->priority = 1;
  sprite->flags |= flags;
  return elem;
}

void (*const PTR_ARRAY_085ae528[4])(Entity081f1770*, Entity081f1770Elem*) = {
    Entity081f1770_UpdateIdle,
    Entity081f1770_UpdateAppear,
    Entity081f1770_UpdateScatter,
    Entity081f1770_UpdateVanish,
};  // 0x085AE528

s32 Entity081f1770_Update(Entity081f1770* p) {
  Entity081f1770Elem* elems = p->elems;
  s32 i;

  if (p->usedMask == 0) {
    return 0;
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, FLAG030047A4_GAMEOVER)) {
    return 0;
  }
  if (TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    return 0;
  }
  for (i = 0; i < 20; i++) {
    if (Entity081f1770_IsUsed(p, i)) {
      PTR_ARRAY_085ae528[elems[i].state](p, &elems[i]);
    }
  }
  return 0;
}

s32 Entity081f1770_Destroy(Entity081f1770* p) {
  s32 i;

  for (i = 0; i < 20; i++) {
    if (Entity081f1770_IsUsed(p, i)) {
      Entity081f1770Elem* elem = &p->elems[i];

      if (elem->sprite.active) {
        AuxSprite_Remove(&elem->sprite);
      }
    }
  }
  gEntity081f1770 = NULL;
  return 0;
}

s32 Entity081f1770_Init(Entity081f1770* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_FIRE_BREATH);
  p->animFile = GetFile(DIR_ANIMATION, ANIM_4EC0);
  p->usedMask = 0;
  gEntity081f1770 = p;
  return 0;
}

Entity081f1770* Entity081f1770_Create(void) {
  if (gEntity081f1770 == NULL) {
    Entity081f1770* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity081f1770));

    if (p != NULL) {
      SetEntityRoutine(p, Entity081f1770_Update, Entity081f1770_Destroy);
      if (Entity081f1770_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity081f1770;
}

void Entity081f1770_ClearGlobal(void) { gEntity081f1770 = NULL; }
