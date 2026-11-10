#include "collision_map.h"
#include "dust.h"
#include "eff_scatter.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "sprite_pltt.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"

// EntityD9AE が count 個まわす1要素, プレイヤーが押せるブロック
typedef struct EntityD9AEElem {
  u8 kind;                                         // 0x000, '.t', 0-6, 1 は押した後も止まるまで滑る
  u8 flags;                                        // 0x001, '.f', bit1: FUN_08002a48 に失敗, bit2: 出現演出あり, bit3: 落下後に壊れる, bit4: ゾーンに所属, bit5: 待機中以外はゾーンイベントを見ない
  u16 timer;                                       // 0x002
  u16 state;                                       // 0x004, 0: 待機, 1: 移動, 2: 移動して落下, 3: 破壊
  u8 unk_6[2];                                     // 0x006
  s32 zone;                                        // 0x008, 0 ならゾーンに属さない
  s16 moveX;                                       // 0x00C
  s16 moveZ;                                       // 0x00E
  u8 dir;                                          // 0x010
  bool8 stateEntered;                              // 0x011
  u16 targetY;                                     // 0x012, 落下先の高さ
  u16 moveFrames;                                  // 0x014, 16 か 64
  s16 hp;                                          // 0x016, '.l=0x80'
  u8 hitCooldown;                                  // 0x018
  u8 phase;                                        // 0x019, 0: 動作中, 2: そのまま解放, 3: 破壊エフェクトを出して解放
  u16 plttID;                                      // 0x01A, '.d=-1'
  u16 flashPlttID;                                 // 0x01C
  bool8 active;                                    // 0x01E, 0 なら空き枠
  u8 flashTimer;                                   // 0x01F
  u8 breakStep;                                    // 0x020
  u8 seCooldown;                                   // 0x021
  u8 unk_22;                                       // 0x022
  u8 unk_23;                                       // 0x023
  bool8 pushLimited;                               // 0x024, kind == 5 なら押せる回数に限りがある
  u8 pushCount;                                    // 0x025, 押せる残り回数
  u8 unk_26[2];                                    // 0x026
  u32 breakScript;                                 // 0x028, '.b', 壊れたときに実行するスクリプト
  Mover mover;                                     // 0x02C
  AuxSpriteGfx gfx;                                // 0x070, '.a'
  AuxSprite sprite;                                // 0x08C
  MapTileOverride tile;                            // 0x0B8
  HitboxData hurtbox;                              // 0x0C8
  HitboxData hitbox;                               // 0x118
  ZoneEventSource zoneEvents;                      // 0x168
  void (*updateCallback)(struct EntityD9AEElem*);  // 0x198
} EntityD9AEElem;
static_assert(sizeof(EntityD9AEElem) == 412);

// OBJ パレット4行を抱えて、count 個の要素 (1個 412バイト) を回すシングルトン
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_8
  u16 count;              // 0x18, elems の要素数, _Create が '.m=8' を入れ、0 なら 8 にする
  u8 oddFrame;            // 0x1A, 毎フレーム 0 と 1 を行き来する
  u8 fadeBack;            // 0x1B, 1 の間は fadeLevel を 0 へ戻していく
  u16 fadeLevel;          // 0x1C, 0〜32, pltt[2]/pltt[3] へ寄せる割合
  u8 fadeEnabled;         // 0x1E, kind 6 (紋章ブロック) を置くと立ち, パレットの明滅を回す
  u8 unk_1f;              // 0x1F, Cmd_B76C が紋章ブロックを光らせると 1, 明滅が戻りきると 0
  rgb555* pltt[4];        // 0x20, &gObjPlttData[0x20/0x30/0x40/0x50] (OBJ パレットの4行)
  rgb555 savedPltt[16];   // 0x30, _Init が pltt[2] の16色をコピーする
  rgb555 unk_50[16];      // 0x50, _Init が pltt[3] の16色をコピーする (savedPltt と同じ内容)
  EntityD9AEElem* elems;  // 0x70, Malloc(count * sizeof(EntityD9AEElem))
} EntityD9AE;
static_assert(sizeof(EntityD9AE) == 116);

IWRAM_DATA EntityD9AE* gEntityD9AE = NULL;  // 0x03000020

const u8 u8_ARRAY_085aa650[8] = {2, 2, 3, 3, 0, 0, 1, 1};  // 0x085AA650

void EntityD9AEElem_UpdateMove(EntityD9AEElem* elem);
void EntityD9AEElem_UpdateFall(EntityD9AEElem* elem);
void EntityD9AEElem_UpdateBreak(EntityD9AEElem* elem);
s32 FUN_08014da0(s32 param_1, s32 param_2, Vec3* pos, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);
void Entity08015584_SpawnSprayEx(s32 count, u32 kind, u32 flags, u32 animSpeed, u32 angleXZ, u32 angleXZRand, u32 speedXZ, s32 speedXZRand, u32 speedY, s32 speedYRand, WorldPos* pos);
s32 FUN_08016110(u32 val1, u32 val2, u32 val3, u32 val4, Vec3* pos);
void Entity08015584_SpawnSprayOne(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand);

// 状態を切り替えてタイマーを戻し, 入場の印を立てる
static inline void EntityD9AEElem_SetState(EntityD9AEElem* elem, void (*fn)(EntityD9AEElem*), s32 state) {
  elem->updateCallback = fn;
  elem->timer = 0;
  elem->stateEntered = TRUE;
  elem->state = state;
}

void FUN_08003008(void) { gEntityD9AE = NULL; }

// 132/102命令, 1回目の下書きで切り上げ, 原典は毎回の先頭で gRandTableIdx だけ進めて捨てる
NON_MATCH void EntityD9AE_SpawnDust(Vec3* pos, s16 param_2) {
#ifdef NONMATCHING_C
  Vec3 size, at;
  s32 i;

  VEC3_SET(size, 32, 0, 32);
  for (i = 0; i < 10; i++) {
    RandomNext();
    at = *pos;
    if (!(i & 1)) {
      at.x = (RandomNext() & 0xF) + param_2 + at.x;
      at.z = at.z - 128 + (u8)RandomNext();
    } else {
      at.x = at.x - 128 + (u8)RandomNext();
      at.z = (RandomNext() & 0xF) + param_2 + at.z;
    }
    DustManager_Spawn(&at, NULL, &size, 1, 3, 4);
  }
#else
  INCFUNC("asm/func/EntityD9AE_SpawnDust.inc");
#endif
}

// 78/79命令, 末尾の attr の判定の後の分岐の向き (原典は bne で FALSE へ跳ぶ) と FALSE の置き場所が違う, || の分解は試済
NON_MATCH bool8 EntityD9AEElem_IsSideBlocked(EntityD9AEElem* elem, s32 param_2, s32 param_3) {
#ifdef NONMATCHING_C
  CollisionMapTile* self = &elem->tile.tile;
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 offset = 0;
  s32 idx;

  switch (param_3) {
    case 0: {
      offset = -gCollisionMap->tiledata->width;
      break;
    }
    case 1: {
      offset = 1;
      break;
    }
    case 2: {
      offset = gCollisionMap->tiledata->width;
      break;
    }
    case 3: {
      offset = -1;
      break;
    }
  }
  idx = param_2 + offset;
  ov = Map_FindTileOverride(idx, 1);
  tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
  if (tile == NULL) {
    return FALSE;
  }
  if ((tile->heightStairs >> 4) == 0) {
    if ((tile->heightStairs & 0xF) < (self->heightStairs & 0xF) || (tile->attr & TATTR_UNK_3)) {
      return FALSE;
    }
  } else if ((tile->heightStairs & 0xF) < (self->heightStairs & 0xF)) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/EntityD9AEElem_IsSideBlocked.inc");
#endif
}

void EntityD9AE_PlayHitWallSound(u32 kind) {
  if (kind == 5) {
    PlaySound_082406e0(SE_THUD);
  } else {
    PlaySound_082406e0(SE_THUD);
  }
}

bool8 EntityD9AEElem_IsFacingWall(EntityD9AEElem* elem, s32 param_2, s32 param_3) {
  CollisionMapTile* self = &elem->tile.tile;
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 offset = 0;
  s32 idx;

  switch (param_3) {
    case 0: {
      offset = -gCollisionMap->tiledata->width;
      break;
    }
    case 1: {
      offset = 1;
      break;
    }
    case 2: {
      offset = gCollisionMap->tiledata->width;
      break;
    }
    case 3: {
      offset = -1;
      break;
    }
  }
  idx = param_2 + offset;
  ov = Map_FindTileOverride(idx, 1);
  tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
  if (tile != NULL) {
    if ((tile->heightStairs & 0xF) >= (self->heightStairs & 0xF)) {
      return TRUE;
    }
    if (elem->kind == 5) {
      EntityD9AE_PlayHitWallSound(elem->kind);
    }
  }
  return FALSE;
}

bool8 EntityD9AEElem_IsEnclosed(EntityD9AEElem* elem) {
  s32 count = 0;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (EntityD9AEElem_IsSideBlocked(elem, elem->tile.tileIdx, i)) {
      count++;
    }
  }
  if (count > 2) {
    return TRUE;
  }
  return FALSE;
}

// mapFlags の判定を bool8 を返す inline にすると 105/111 命令まで寄るが, 原典は sprite.pos を2語で写した時点で y + 442 をレジスタの中で済ませてから置く, Vec3_CopyOffsetY は試済 (悪化)
NON_MATCH void EntityD9AEElem_OnLanded(EntityD9AEElem* elem) {
#ifdef NONMATCHING_C
  if (gStat->mapFlags & MPF_UNK_8) {
    Vec3 pos;

    PlaySound_082406e0(SONG_325);
    pos = elem->sprite.pos;
    pos.y += 442;
    pos.x += 128;
    pos.z += 128;
    FUN_08016110(1, 0, 0, 30, &pos);
  }
  switch (elem->kind) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6: {
      PlaySound_082406e0(SE_BLOCK_COLLISION);
      break;
    }
    default: {
      PlaySound_082406e0(SE_BLOCK_COLLISION);
      break;
    }
  }
  if (!EntityD9AEElem_IsEnclosed(elem)) {
    EntityD9AE_SpawnDust(&elem->mover.pos, 0x90);
  } else {
    Entity08015584_SpawnSprayEx(4, 1, 1, Q6(1), 0, 0xFF, 2, 4, 6, 6, &elem->sprite.pos);
  }
#else
  INCFUNC("asm/func/EntityD9AEElem_OnLanded.inc");
#endif
}

void EntityD9AEElem_OnHitWall(EntityD9AEElem* elem) {
  if (EntityD9AEElem_IsFacingWall(elem, elem->tile.tileIdx, elem->dir)) {
    Vec3 pos = elem->sprite.pos;
    s32 angle = 0;

    switch (elem->dir) {
      case 0: {
        pos.z -= 128;
        angle = 0xB0;
        break;
      }
      case 1: {
        pos.x += 128;
        angle = -16;
        break;
      }
      case 2: {
        pos.z += 128;
        angle = 0x30;
        break;
      }
      case 3: {
        pos.x -= 128;
        angle = 0x70;
        break;
      }
    }
    Entity08015584_SpawnSprayEx(2, 1, 1, Q6(1), angle, 0x1F, 2, 4, 6, 6, &pos);
    EntityD9AE_PlayHitWallSound(elem->kind);
  }
}

void EntityD9AE_PlayPushSound(s32 kind) {
  switch (kind) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5: {
      PlaySound_082406e0(SONG_322);
      break;
    }
    case 1: {
      PlaySound_082406e0(SONG_311);
      break;
    }
    default: {
      PlaySound_082406e0(SONG_322);
      break;
    }
  }
}

void EntityD9AEElem_OnDamaged(HitboxData* hurtbox, HitboxData* b, void* owner) {
  bool8 hit = FALSE;
  EntityD9AEElem* elem = owner;

  if (elem->kind == 0) {
    if (TEST_FLAGS(hurtbox->weakness, 7) && TEST_FLAGS(hurtbox->attributes, 0x10)) {
      elem->hp -= 24;
      elem->hitCooldown = 10;
      elem->flashTimer = 2;
      Video_SetAuxSpritePltt(&elem->gfx, elem->flashPlttID);
      hit = TRUE;
    }
  } else if (elem->kind == 1) {
    if (TEST_FLAGS(hurtbox->attributes, 4) && TEST_FLAGS(hurtbox->weakness, 0x10007) && !(hurtbox->weakness & 0x40)) {
      elem->hp -= 24;
      elem->hitCooldown = 10;
      elem->flashTimer = 2;
      Video_SetAuxSpritePltt(&elem->gfx, elem->flashPlttID);
      if (elem->seCooldown == 0) {
        elem->seCooldown = 10;
        PlaySound_082406e0(SONG_348);
        Entity08015584_SpawnSprayOne(&elem->mover.pos, 0, 0, Q6(1), 12, 12, 4, 4);
      }
      hit = TRUE;
    }
  } else if (elem->kind == 2) {
    if (TEST_FLAGS(hurtbox->weakness, 4)) {
      elem->hp -= 24;
      elem->hitCooldown = 10;
      elem->flashTimer = 2;
      Video_SetAuxSpritePltt(&elem->gfx, elem->flashPlttID);
      hit = TRUE;
    }
  }
  if (!hit) {
    return;
  }
  if ((elem->state == 1 || elem->state == 2) && elem->hp <= 0) {
    elem->hp = 1;
  }
  if (elem->hp < 0) {
    elem->hp = 0;
    return;
  }
  if (!TEST_FLAGS(hurtbox->weakness, 4)) {
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
  }
}

void FUN_080035e0(void) {}

// 90/86命令, 原典は elem を r12, 要素を r3 に置き -256 を pool からループの外で読む, 状態切り替えの inline と直書きは試済
NON_MATCH void EntityD9AEElem_DropUpper(EntityD9AEElem* elem) {
#ifdef NONMATCHING_C
  EntityD9AE* p = gEntityD9AE;
  EntityD9AEElem* e = p->elems;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (e->active && e != elem && e->tile.tileIdx == elem->tile.tileIdx && e->state == 0 && (elem->tile.tile.heightStairs & 0xF) < (e->tile.tile.heightStairs & 0xF)) {
      e->updateCallback = EntityD9AEElem_UpdateFall;
      e->timer = 0;
      e->stateEntered = TRUE;
      e->state = 2;
      e->moveX = 0;
      e->moveZ = 0;
      e->dir = 0;
      e->targetY = e->mover.pos.y;
      if (e->targetY < 256) {
        e->targetY = 0;
      } else {
        e->targetY -= 256;
      }
    }
    e++;
  }
#else
  INCFUNC("asm/func/EntityD9AEElem_DropUpper.inc");
#endif
}

s32 EntityD9AEElem_Release(EntityD9AEElem* elem) {
  AuxSprite_Remove(&elem->sprite);
  Map_RemoveTileOverride(&elem->tile);
  Hitbox_Unregister(&elem->hurtbox);
  if (!(elem->flags & 2)) {
    FUN_08002a58(&elem->mover);
  }
  Mover_Unlink(&elem->mover);
  elem->active = FALSE;
  return 0;
}

s32 EntityD9AE_ReleaseAll(void) {
  EntityD9AE* p = gEntityD9AE;
  EntityD9AEElem* e;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  e = p->elems;
  for (i = 0; i < p->count; i++) {
    if (e->active) {
      EntityD9AEElem_Release(e);
    }
    e++;
  }
  return 0;
}

s32 Cmd_5C0B(void) {
  EntityD9AE* p = gEntityD9AE;
  EntityD9AEElem* e;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  e = p->elems;
  for (i = 0; i < p->count; i++) {
    if (e->active && e->kind == 1) {
      e->hp = 0;
      if (e->state == 0) {
        e->updateCallback = EntityD9AEElem_UpdateBreak;
        e->timer = 0;
        e->stateEntered = TRUE;
        e->state = 3;
      }
    }
    e++;
  }
  return 0;
}

s32 Cmd_0E76(void) {
  EntityD9AE* p = gEntityD9AE;
  u32 id;
  EntityD9AEElem* e;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  id = VM_GetNamedArgValue('n', 0);
  e = p->elems;
  for (i = 0; i < p->count; i++) {
    if (e->active && e->mover.id == id) {
      EntityD9AEElem_Release(e);
    }
    e++;
  }
  return 0;
}

void EntityD9AEElem_BreakEffect0(EntityD9AEElem* elem) {
  WorldPos* pos;
  Vec3 at, vel, velRange;

  PlaySound_082406e0(SONG_347);
  pos = &elem->mover.pos;
  FUN_08014da0(3, 2, pos, 60, 30, 16, 8, 8, 0, 0x100, 24, 16);
  FUN_08014da0(8, 6, pos, 60, 30, 22, 8, 8, 0, 0x100, 24, 16);
  at.x = elem->mover.pos.x;
  at.y = elem->mover.pos.y + 128;
  at.z = elem->mover.pos.z;
  VEC3_SET(vel, -15, 8, -15);
  VEC3_SET(velRange, 30, 22, 30);
  ScatterEffect_Spawn(8, SCATTER_STONE, &at, &vel, &velRange, 60, 60);
}

void EntityD9AEElem_BreakEffect1(EntityD9AEElem* elem) {
  Vec3 pos, vel, velRange;

  PlaySound_082406e0(SONG_309);
  FUN_08014da0(4, 0, &elem->mover.pos, 60, 30, 20, 8, 8, 0, 0x100, 24, 16);
  pos.x = elem->mover.pos.x;
  pos.y = elem->mover.pos.y + 128;
  pos.z = elem->mover.pos.z;
  VEC3_SET(vel, -15, 8, -15);
  VEC3_SET(velRange, 30, 22, 30);
  ScatterEffect_Spawn(8, SCATTER_ICE, &pos, &vel, &velRange, 60, 60);
}

void EntityD9AEElem_BreakEffect2(EntityD9AEElem* elem) {
  WorldPos* pos;

  PlaySound_082406e0(SONG_336);
  pos = &elem->mover.pos;
  FUN_08014da0(3, 1, pos, 60, 30, 16, 8, 8, 0, 0x100, 24, 16);
  FUN_08014da0(8, 5, pos, 60, 30, 22, 8, 8, 0, 0x100, 24, 16);
}

// 190/183命令, 1回目の下書きで切り上げ, 乱数の & 0xFF と & 0xF の並びが違う
NON_MATCH void EntityD9AEElem_SpawnMoveDust(EntityD9AEElem* elem) {
#ifdef NONMATCHING_C
  Vec3 size, at;
  s32 i;

  VEC3_SET(size, 32, 0, 32);
  for (i = 0; i < 3; i++) {
    at = elem->mover.pos;
    switch (elem->dir) {
      case 0: {
        at.x = at.x - 128 + (u8)RandomNext();
        at.z = at.z + 120 + (RandomNext() & 0xF);
        break;
      }
      case 1: {
        at.x = at.x - 120 - (RandomNext() & 0xF);
        at.z = at.z - 128 + (u8)RandomNext();
        break;
      }
      case 2: {
        at.x = at.x - 128 + (u8)RandomNext();
        at.z = at.z - 120 - (RandomNext() & 0xF);
        break;
      }
      case 3: {
        at.x = at.x + 120 + (RandomNext() & 0xF);
        at.z = at.z - 128 + (u8)RandomNext();
        break;
      }
    }
    DustManager_Spawn(&at, NULL, &size, 1, 2, 4);
  }
#else
  INCFUNC("asm/func/EntityD9AEElem_SpawnMoveDust.inc");
#endif
}

// 194/196命令, 原典は moveX/moveZ/frames をスタックに置き dir を r8 に持つ, 1回目の下書きで切り上げ
NON_MATCH s32 EntityD9AEElem_TryMove(EntityD9AEElem* elem, s32 tileIdx, s32 dir) {
#ifdef NONMATCHING_C
  CollisionMapTile* self = &elem->tile.tile;
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 offset = 0;
  s16 moveX = 0;
  s16 moveZ = 0;
  s32 step;
  u16 frames;
  s32 idx, height, selfHeight;

  if ((gGoodCondTimer != 0 && gGoodCondID == GOOD_POWER) || elem->kind == 1) {
    step = 16;
    frames = 16;
  } else {
    step = 4;
    frames = 64;
  }
  switch (dir) {
    case 0: {
      offset = -gCollisionMap->tiledata->width;
      moveZ = -step;
      break;
    }
    case 1: {
      offset = 1;
      moveX = step;
      break;
    }
    case 2: {
      offset = gCollisionMap->tiledata->width;
      moveZ = step;
      break;
    }
    case 3: {
      offset = -1;
      moveX = -step;
      break;
    }
  }
  idx = tileIdx + offset;
  ov = Map_FindTileOverride(idx, 1);
  tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
  if (tile == NULL || (tile->heightStairs >> 4) != 0) {
    return 0;
  }
  height = tile->heightStairs & 0xF;
  selfHeight = self->heightStairs & 0xF;
  if (height >= selfHeight || (tile->attr & TATTR_UNK_3)) {
    return 0;
  }
  if (selfHeight - height > 1) {
    elem->targetY = height << 8;
    elem->dir = dir;
    elem->updateCallback = EntityD9AEElem_UpdateMove;
    elem->timer = 0;
    elem->stateEntered = TRUE;
    elem->moveX = moveX;
    elem->moveZ = moveZ;
    elem->state = 2;
    elem->tile.tileIdx = idx;
    elem->moveFrames = frames;
    return 3;
  }
  elem->targetY = height << 8;
  {
    s32 h = self->heightStairs & 0xF;

    if (h > 0) {
      h--;
    }
    self->heightStairs = (self->heightStairs & 0xF0) | h;
  }
  self->occluder = tile->occluder;
  elem->dir = dir;
  elem->updateCallback = EntityD9AEElem_UpdateMove;
  elem->timer = 0;
  elem->stateEntered = TRUE;
  elem->moveX = moveX;
  elem->moveZ = moveZ;
  elem->state = 1;
  elem->tile.tileIdx = idx;
  elem->moveFrames = frames;
  return 1;
#else
  INCFUNC("asm/func/EntityD9AEElem_TryMove.inc");
#endif
}

// 233/233命令, 残差はスタックの退避の並びと原典のフレームが 4 バイト小さいことだけ
NON_MATCH s32 EntityD9AE_PushAt(Vec3* pos, s32 dir) {
#ifdef NONMATCHING_C
  EntityD9AE* p = gEntityD9AE;
  CollisionMapTile* tile;
  EntityD9AEElem* e;
  s32 idx, offset, i;

  if (p == NULL) {
    return -1;
  }
  tile = GetTileAt(pos);
  idx = GetCollisionTileIdx(pos);
  offset = 0;
  switch (dir) {
    case 0: {
      offset = -gCollisionMap->tiledata->width;
      break;
    }
    case 1: {
      offset = 1;
      break;
    }
    case 2: {
      offset = gCollisionMap->tiledata->width;
      break;
    }
    case 3: {
      offset = -1;
      break;
    }
  }
  e = p->elems;
  for (i = 0; i < p->count; i++) {
    if (e->active && e->state == 0) {
      s32 target = idx + offset;

      if (target == e->tile.tileIdx && (tile->heightStairs & 0xF) + 1 == (e->tile.tile.heightStairs & 0xF)) {
        MapTileOverride* ov = Map_FindTileOverride(target, 1);
        CollisionMapTile* dst = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[target];

        if ((dst->heightStairs & 0xF) == (e->tile.tile.heightStairs & 0xF)) {
          s32 result;

          if (e->pushLimited && e->pushCount == 0) {
            return 0;
          }
          result = EntityD9AEElem_TryMove(e, e->tile.tileIdx, dir);
          if (result > 0) {
            EntityD9AE_PlayPushSound(e->kind);
            if (e->kind == 1) {
              result = -1;
            }
            if (e->pushCount != 0) {
              e->pushCount--;
            }
          }
          return result;
        }
      }
    }
    e++;
  }
  return 0;
#else
  INCFUNC("asm/func/EntityD9AE_PushAt.inc");
#endif
}

s32 EntityD9AE_PushAtDir8(Vec3* pos, u32 dir) { return EntityD9AE_PushAt(pos, u8_ARRAY_085aa650[dir]); }

// 34/34命令, 原典は kind == 1 の 1 を stateEntered に使い回して退避レジスタが r4 だけ, 状態切り替えの inline を通すと r5 が増え, 直書きだと関数ポインタの読みが後ろに回る
NON_MATCH void EntityD9AEElem_UpdateIdle(EntityD9AEElem* elem) {
#ifdef NONMATCHING_C
  if (elem->kind == 1) {
    if (elem->hp <= 0) {
      EntityD9AEElem_SetState(elem, EntityD9AEElem_UpdateBreak, 3);
    }
  } else if (elem->hp <= 0) {
    elem->phase = 3;
    elem->updateCallback = NULL;
  }
#else
  INCFUNC("asm/func/EntityD9AEElem_UpdateIdle.inc");
#endif
}

void EntityD9AEElem_UpdateMove(EntityD9AEElem* elem) {
  Mover* mover = &elem->mover;
  CollisionMapTile* tile = &elem->tile.tile;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    tile->attr |= TATTR_UNK_0;
  }
  mover->delta.x = elem->moveX;
  mover->delta.z = elem->moveZ;
  mover->pos.y = (tile->heightStairs & 0xF) << 8;
  if (elem->state == 2) {
    mover->pos.y -= 256;
  }
  elem->sprite.pos.y = mover->pos.y;
  Hitbox_SetPos(&elem->hitbox, &mover->pos, 0);
  Hitbox_Register(&elem->hitbox);
  if (elem->kind != 1 && !(elem->timer & 3)) {
    EntityD9AEElem_SpawnMoveDust(elem);
  }
  if (++elem->timer >= elem->moveFrames) {
    s32 height = tile->heightStairs & 0xF;

    if (height < 15) {
      height++;
    }
    tile->heightStairs = (tile->heightStairs & 0xF0) | height;
    tile->occluder = 0xFF;
    if (elem->kind == 1) {
      if (elem->state == 2) {
        EntityD9AEElem_SetState(elem, EntityD9AEElem_UpdateFall, 2);
        elem->moveX = 0;
        elem->moveZ = 0;
        elem->dir = 0;
      } else if (!EntityD9AEElem_TryMove(elem, elem->tile.tileIdx, elem->dir)) {
        EntityD9AEElem_OnHitWall(elem);
        EntityD9AEElem_SetState(elem, EntityD9AEElem_UpdateIdle, 0);
        elem->moveX = 0;
        elem->moveZ = 0;
        elem->dir = 0;
        tile->attr &= ~TATTR_UNK_0;
      }
    } else {
      if (elem->state == 2) {
        EntityD9AEElem_SetState(elem, EntityD9AEElem_UpdateFall, 2);
      } else {
        EntityD9AEElem_OnHitWall(elem);
        EntityD9AEElem_SetState(elem, EntityD9AEElem_UpdateIdle, 0);
        tile->attr &= ~TATTR_UNK_0;
      }
      elem->moveX = 0;
      elem->moveZ = 0;
      elem->dir = 0;
    }
  }
}

// 99/97命令, 残差は dy の符号拡張と最後の状態切り替えで関数ポインタを先に読む形, 状態切り替えの inline は途中に moveX などが挟まるので使えない
NON_MATCH void EntityD9AEElem_UpdateFall(EntityD9AEElem* elem) {
#ifdef NONMATCHING_C
  Mover* mover = &elem->mover;
  CollisionMapTile* tile = &elem->tile.tile;
  s16 dy;

  if (elem->stateEntered) {
    s32 height;

    elem->stateEntered = FALSE;
    height = (elem->targetY >> 8) + 1;
    if (height > 15) {
      tile->heightStairs = (tile->heightStairs & 0xF0) | 0xF;
    } else {
      tile->heightStairs = (tile->heightStairs & 0xF0) | height;
    }
    if (TEST_FLAGS(elem->flags, 8)) {
      elem->tile.tile.attr |= TATTR_UNK_0 | TATTR_UNK_5;
    }
  }
  dy = elem->targetY - mover->pos.y;
  mover->delta.y = dy;
  if (dy < -16) {
    mover->delta.y = -16;
  } else if (dy > 0) {
    mover->delta.y = 0;
  }
  if (mover->delta.y == 0) {
    if (TEST_FLAGS(elem->flags, 8)) {
      elem->tile.tile.attr |= TATTR_UNK_0 | TATTR_UNK_5;
      elem->hp = 0;
    } else {
      elem->tile.tile.attr &= ~(TATTR_UNK_0 | TATTR_UNK_5);
      EntityD9AEElem_OnLanded(elem);
    }
    elem->updateCallback = EntityD9AEElem_UpdateIdle;
    elem->timer = 0;
    elem->stateEntered = TRUE;
    elem->moveX = 0;
    elem->moveZ = 0;
    elem->dir = 0;
    elem->state = 0;
  }
#else
  INCFUNC("asm/func/EntityD9AEElem_UpdateFall.inc");
#endif
}

void EntityD9AEElem_UpdateBreak(EntityD9AEElem* elem) {
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    elem->breakStep = 0;
    AuxSprite_SetPoseIdx(&elem->sprite, 0);
    PlaySound_082406e0(SONG_310);
    elem->tile.tile.attr |= TATTR_UNK_0 | TATTR_UNK_5;
    if (elem->breakScript != 0) {
      u32 argv[5];
      ScriptArgs sa;

      argv[0] = elem->mover.id;
      argv[1] = elem->kind;
      argv[2] = elem->mover.pos.x;
      argv[3] = elem->mover.pos.y;
      argv[4] = elem->mover.pos.z;
      sa.argc = 5;
      sa.argv = argv;
      VM_ExecByID(elem->breakScript, &sa);
      elem->breakScript = 0;
    }
  }
  if (elem->breakStep == 0) {
    if (Mod(elem->timer, 2) == 0) {
      if (elem->sprite.poseIdx == 0) {
        AuxSprite_SetPoseIdx(&elem->sprite, 1);
      } else {
        AuxSprite_SetPoseIdx(&elem->sprite, 0);
      }
    }
    if (elem->timer++ > 29) {
      elem->timer = 0;
      elem->breakStep++;
    }
  } else if (elem->timer++ > 5) {
    elem->timer = 0;
    if (++elem->breakStep >= 4) {
      elem->phase = 2;
    } else {
      AuxSprite_SetPoseIdx(&elem->sprite, elem->breakStep);
    }
  }
}

void EntityD9AEElem_UpdateAppear(EntityD9AEElem* elem) {
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    elem->breakStep = 3;
    AuxSprite_SetPoseIdx(&elem->sprite, 3);
    PlaySound_082406e0(SONG_310);
  }
  if (elem->breakStep != 0) {
    if (elem->timer++ > 5) {
      elem->timer = 0;
      elem->breakStep--;
      AuxSprite_SetPoseIdx(&elem->sprite, elem->breakStep);
    }
  } else {
    EntityD9AEElem_SetState(elem, EntityD9AEElem_UpdateIdle, 0);
  }
}

static void (*const sEntityD9AEBreakEffects[5])(EntityD9AEElem*) = {
    EntityD9AEElem_BreakEffect0,
    EntityD9AEElem_BreakEffect1,
    EntityD9AEElem_BreakEffect2,
    NULL,
    NULL,
};  // 0x085AA658

// 244/264命令, 原典は &hurtbox.flags と &hitCooldown をループの外で作って要素ごとに足して回す, 1回目の下書きで切り上げ
NON_MATCH s32 EntityD9AE_Update(EntityD9AE* p) {
#ifdef NONMATCHING_C
  EntityD9AEElem* elem = p->elems;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (elem->active) {
      if (elem->phase == 0) {
        Mover_ApplyMove(&elem->mover);
        if (elem->updateCallback != NULL) {
          elem->updateCallback(elem);
        }
        if (!(elem->flags & 0x20)) {
          Map_UpdateZoneEvents(&elem->zoneEvents);
        } else if (elem->state == 0) {
          elem->tile.tile.attr &= ~TATTR_WALL;
          Map_UpdateZoneEvents(&elem->zoneEvents);
        } else {
          elem->tile.tile.attr |= TATTR_WALL;
        }
        if (elem->seCooldown != 0) {
          elem->seCooldown--;
        }
        if (elem->zone == 0 || gStat->zoneID == elem->zone) {
          elem->sprite.flags &= ~SPRFLAG_HIDDEN;
        } else {
          elem->sprite.flags |= SPRFLAG_HIDDEN;
        }
        if (elem->hitCooldown == 0 && elem->hp > 0) {
          if (elem->zone != 0 && gStat->zoneID != elem->zone) {
            elem->hurtbox.flags |= HBFLAG_HIDDEN;
          } else {
            elem->hurtbox.flags &= ~HBFLAG_HIDDEN;
            Hitbox_SetPos(&elem->hurtbox, &elem->mover.pos, 0);
          }
        } else {
          elem->hitCooldown--;
          elem->hurtbox.flags |= HBFLAG_HIDDEN;
        }
        if (elem->flashTimer != 0 && --elem->flashTimer == 0) {
          Video_SetAuxSpritePltt(&elem->gfx, elem->plttID);
        }
      } else {
        if (elem->phase == 3 && sEntityD9AEBreakEffects[elem->kind] != NULL) {
          sEntityD9AEBreakEffects[elem->kind](elem);
        }
        if (elem->breakScript != 0) {
          u32 argv[5];
          ScriptArgs sa;

          argv[0] = elem->mover.id;
          argv[1] = elem->kind;
          argv[2] = elem->mover.pos.x;
          argv[3] = elem->mover.pos.y;
          argv[4] = elem->mover.pos.z;
          sa.argc = 5;
          sa.argv = argv;
          VM_ExecByID(elem->breakScript, &sa);
          elem->breakScript = 0;
        }
        EntityD9AEElem_DropUpper(elem);
        EntityD9AEElem_Release(elem);
      }
    }
    elem++;
  }
  if (p->fadeEnabled) {
    BlendPltt(p->savedPltt, p->pltt[0], p->pltt[2], p->fadeLevel, 5);
    BlendPltt(p->unk_50, p->pltt[1], p->pltt[3], p->fadeLevel, 5);
    if (p->fadeBack == 0) {
      p->fadeLevel++;
      if ((s16)p->fadeLevel >= 32) {
        p->fadeLevel = 32;
        p->fadeBack = 1;
      }
    } else {
      p->fadeLevel--;
      if ((s16)p->fadeLevel <= 0) {
        p->fadeLevel = 0;
        p->fadeBack = 0;
        if (p->unk_1f) {
          p->unk_1f = 0;
        }
      }
    }
  }
  p->oddFrame = 1 - p->oddFrame;
  return 0;
#else
  INCFUNC("asm/func/EntityD9AE_Update.inc");
#endif
}

s32 EntityD9AE_Destroy(EntityD9AE* p) {
  EntityD9AE_ReleaseAll();
  Free(p->elems);
  gEntityD9AE = NULL;
  return 0;
}

s32 EntityD9AE_Init(EntityD9AE* p, u32 id) {
  gEntityD9AE = p;
  if (p->count == 0) {
    p->count = 8;
  }
  p->elems = Malloc(p->count * sizeof(EntityD9AEElem));
  if (p->elems == NULL) {
    return -1;
  }
  ClearMemory(p->elems, p->count * sizeof(EntityD9AEElem));
  p->oddFrame = 0;
  p->fadeEnabled = 0;
  p->fadeBack = 0;
  p->fadeLevel = 0;
  p->pltt[0] = &gObjPlttData[0x20];
  p->pltt[1] = &gObjPlttData[0x30];
  p->pltt[2] = &gObjPlttData[0x40];
  p->pltt[3] = &gObjPlttData[0x50];
  CpuCopy32(&gObjPlttData[0x40], p->savedPltt, sizeof(p->savedPltt));
  CpuCopy32(p->pltt[3], p->unk_50, sizeof(p->unk_50));
  return 0;
}

// 0xD9AE
EntityD9AE* EntityD9AE_Create(u32 id, u32 _) {
  EntityD9AE* p;

  if (gEntityD9AE != NULL) {
    return gEntityD9AE;
  }
  p = (EntityD9AE*)CreateEntity(ENTITY_UNK_8, sizeof(EntityD9AE));
  if (p != NULL) {
    SetEntityRoutine(&p->e, EntityD9AE_Update, EntityD9AE_Destroy);
    p->count = VM_GetNamedArgValue('m', 8);
    if (EntityD9AE_Init(p, id) < 0) {
      KillEntity(&p->e);
      return NULL;
    }
  }
  return p;
}

// 空いている枠を返す, 無ければ NULL
EntityD9AEElem* EntityD9AE_FindFreeElem(EntityD9AE* p) {
  EntityD9AEElem* e = p->elems;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (!e->active) {
      return e;
    }
    e++;
  }
  return NULL;
}

// id が一致する使用中の枠を返す, 無ければ NULL
EntityD9AEElem* EntityD9AE_FindElemByID(EntityD9AE* p, u32 id) {
  EntityD9AEElem* e = p->elems;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (e->active && e->mover.id == id) {
      return e;
    }
    e++;
  }
  return NULL;
}

// 386/355命令 (id を u32 にする前), 原典は gfx と mover のアドレスを先に作って持ち越す, 1回目の下書きで切り上げ
NON_MATCH s32 EntityD9AE_SpawnElem(u32 id, s32 kind, s32 flags, Vec3* pos, s32 file, s32 poseIdx, s32 hp, s32 plttID, s32 flashPlttID, u32 breakScript) {
#ifdef NONMATCHING_C
  EntityD9AE* p = gEntityD9AE;
  EntityD9AEElem* e;
  Mover* mover;
  AuxSpriteGfx* gfx;
  WorldPos* mpos;
  HitboxData* hurtbox;
  HitboxData* hitbox;
  s32 tileIdx, height;
  Vec3 size, offset;
  bool8 limited;

  if (p == NULL) {
    return -1;
  }
  e = EntityD9AE_FindFreeElem(p);
  if (e == NULL) {
    return -1;
  }
  ClearMemory(e, sizeof(EntityD9AEElem));
  e->active = TRUE;
  e->kind = kind;
  if ((u8)kind == 6) {
    p->fadeEnabled = 1;
  }
  e->flags = flags;
  e->timer = 0;
  e->state = 0;
  gfx = &e->gfx;
  Video_GetAuxSprite(gfx, file);
  AuxSprite_Add(&e->sprite, gfx, 0);
  e->sprite.poseIdx = poseIdx;
  e->sprite.pos = *pos;
  mover = &e->mover;
  Mover_Init(mover, id, pos, 0, 7, e);
  Mover_SetAuxSprite(mover, &e->sprite);
  e->mover.pos = e->sprite.pos;
  if (e->flags & 0x10) {
    e->zone = GetZoneAt(&e->mover.pos);
  } else {
    e->zone = 0;
  }
  mpos = &e->mover.pos;
  e->moveX = 0;
  e->moveZ = 0;
  e->dir = 0;
  if (e->flags & 4) {
    e->updateCallback = EntityD9AEElem_UpdateAppear;
    e->timer = 0;
  } else {
    e->updateCallback = EntityD9AEElem_UpdateIdle;
    e->timer = 0;
  }
  e->stateEntered = TRUE;
  tileIdx = GetCollisionTileIdx(&e->mover.pos);
  height = GetTileAt(&e->mover.pos)->heightStairs & 0xF;
  if (height < 15) {
    height++;
  }
  Map_AddTileOverride(&e->tile, tileIdx, 0, height, 0xFF, 0);
  e->targetY = height << 8;
  VEC3_SET(size, 130, 128, 130);
  VEC3_SET(offset, 0, 128, 0);
  hurtbox = &e->hurtbox;
  Hitbox_Init(hurtbox, e->mover.id, HBFLAG_HURTBOX | HBFLAG_UNK_6 | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(hurtbox, mpos, 0);
  Hitbox_SetHandler(hurtbox, EntityD9AEElem_OnDamaged, e);
  Hitbox_Register(hurtbox);
  VEC3_SET(size, 128, 128, 128);
  hitbox = &e->hitbox;
  Hitbox_Init(hitbox, e->mover.id, HBFLAG_HITBOX | HBFLAG_UNK_11 | HBFLAG_UNK_0, 0, HIM_0, &size, &offset);
  Hitbox_SetPos(hitbox, mpos, 0);
  Hitbox_SetHandler(hitbox, FUN_080035e0, e);
  Hitbox_SetPower(hitbox, 1500, 50);
  e->hitbox.weakness = 0x100;
  e->hitbox.attributes = 0;
  e->hp = hp;
  e->hitCooldown = 0;
  e->phase = 0;
  e->flashTimer = 0;
  e->breakStep = 0;
  e->seCooldown = 0;
  e->unk_23 = 4;
  e->unk_22 = Mod(Random(), 16);
  if (plttID < 0) {
    e->plttID = e->gfx.plttID;
  } else {
    e->plttID = plttID;
  }
  Video_SetAuxSpritePltt(gfx, e->plttID);
  e->flashPlttID = flashPlttID;
  e->zoneEvents.id = e->mover.id;
  e->zoneEvents.pos = mpos;
  e->breakScript = breakScript;
  if (!(e->flags & 2) && FUN_08002a48(mover) < 0) {
    e->flags |= 2;
  }
  limited = e->kind == 5;
  e->pushLimited = limited;
  e->pushCount = limited;
  return 0;
#else
  INCFUNC("asm/func/EntityD9AE_SpawnElem.inc");
#endif
}

// 161/164命令, 原典は kind ごとの既定ファイルを分岐ごとに r1 に置いて VM_GetNamedArgValue へ渡すが, こちらは条件付きの読み込みに畳まれる, 既定値を返す inline は試済, id を原典はスタックに退避する
NON_MATCH s32 Cmd_E02A(void) {
#ifdef NONMATCHING_C
  s32 id = VM_GetNamedArgValue('n', 0);
  s32 kind = VM_GetNamedArgValue('t', 0);
  s32 flags = VM_GetNamedArgValue('f', 0);
  Vec3 pos;
  s32 file, poseIdx, hp, plttID;

  if (VM_SeekToNamedArg('M') && VM_GetValue() != 0) {
    flags |= 0x10;
  }
  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  if (kind == 0) {
    file = SPRITE_CUBE_ROCK;
  } else if (kind == 1) {
    file = SPRITE_CUBE_ICE;
  } else if (kind == 2) {
    file = SPRITE_9D40;
  } else if (kind == 3) {
    file = SPRITE_9D43;
  } else if (kind == 4) {
    file = SPRITE_2097;
  } else if (kind == 5) {
    file = SPRITE_05A2;
  } else if (kind == 6) {
    file = SPRITE_B306;
  } else {
    file = SPRITE_CUBE_ROCK;
  }
  file = VM_GetNamedArgValue('a', file);
  poseIdx = VM_GetNamedArgValue('i', 0);
  hp = VM_GetNamedArgValue('l', 0x80);
  if (kind == 0) {
    plttID = 0x23D;
  } else if (kind == 1) {
    plttID = 0x241;
  } else if (kind == 2 || kind == 4) {
    plttID = 0x1FD;
  } else if (kind == 3) {
    plttID = 0x4F;
  } else if (kind == 5) {
    plttID = 0x8B;
  } else if (kind == 6) {
    if (poseIdx == 0 || poseIdx == 2) {
      plttID = 2;
    } else {
      plttID = 3;
    }
  } else {
    plttID = VM_GetNamedArgValue('d', -1);
  }
  EntityD9AE_SpawnElem(id, kind, flags, &pos, file, poseIdx, hp, plttID, 306, VM_GetNamedArgValue('b', 0));
  return 0;
#else
  INCFUNC("asm/func/Cmd_E02A.inc");
#endif
}

s32 Cmd_B76C(void) {
  EntityD9AE* p = gEntityD9AE;
  EntityD9AEElem* e;
  AuxSprite* sprite;
  u32 id;
  s32 lit, playSound;

  if (p == NULL) {
    return -1;
  }
  id = VM_GetNamedArgValue('n', 0);
  if (id == 0) {
    return -1;
  }
  e = EntityD9AE_FindElemByID(p, id);
  if (e == NULL || e->kind != 6) {
    return -1;
  }
  sprite = &e->sprite;
  lit = VM_GetNamedArgValue('s', 0);
  playSound = VM_GetNamedArgValue('S', 1);
  if (lit == 0) {
    if (sprite->poseIdx == 0 || sprite->poseIdx == 2) {
      e->plttID = 2;
      Video_SetAuxSpritePltt(&e->gfx, 2);
    } else {
      e->plttID = 3;
      Video_SetAuxSpritePltt(&e->gfx, 3);
    }
  } else {
    if (sprite->poseIdx == 0 || sprite->poseIdx == 2) {
      e->plttID = 4;
      Video_SetAuxSpritePltt(&e->gfx, 4);
      e->gfx.pltt = p->savedPltt;
    } else {
      e->plttID = 5;
      Video_SetAuxSpritePltt(&e->gfx, 5);
      e->gfx.pltt = p->unk_50;
    }
    p->unk_1f = 1;
    if (playSound) {
      PlaySound_082406e0(SONG_329);
    }
  }
}
