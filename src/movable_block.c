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
#include "puff.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "sprite_pltt.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"

// 移動ブロック(Movable Block), プレイヤーが押して動かせるブロック

// MovableBlock.kind
typedef enum {
  B_ROCK = 0,       // 岩ブロック, SPRITE_BLOCK_ROCK
  B_ICE = 1,        // 氷ブロック (一度押すと、壁で止まるまで滑る), SPRITE_BLOCK_ICE
  B_WOOD = 2,       // 木箱, SPRITE_WOODEN_BOX
  B_UNK3 = 3,       // 不使用?, SPRITE_BLOCK_9D43
  B_ARITH = 4,      // 算術ブロック (不使用?), SPRITE_BLOCK_ARITH
  B_TOMBSTONE = 5,  // 大聖堂の(偽物の)墓, 移動ブロックのように押せる, SPRITE_TOMBSTONE
  B_EMBLEM = 6,     // 紋章ブロック, SPRITE_BLOCK_EMBLEM
} MovableBlockKind;

// MovableBlockManager が count 個まわす1要素, プレイヤーが押せるブロック
typedef struct MovableBlock {
  u8 kind;                                       // 0x000, '.t', see MovableBlockKind
  u8 flags;                                      // 0x001, '.f', bit1: FUN_08002a48 に失敗, bit2: 出現演出あり, bit3: 落下後に壊れる, bit4: ゾーンに所属, bit5: 待機中以外はゾーンイベントを見ない
  u16 timer;                                     // 0x002
  u16 state;                                     // 0x004, 0: 待機, 1: 移動, 2: 移動して落下, 3: 破壊
  u8 unk_6[2];                                   // 0x006
  s32 zone;                                      // 0x008, 0 ならゾーンに属さない
  s16 moveX;                                     // 0x00C
  s16 moveZ;                                     // 0x00E
  u8 dir;                                        // 0x010
  bool8 stateEntered;                            // 0x011
  u16 targetY;                                   // 0x012, 落下先の高さ
  u16 moveFrames;                                // 0x014, 16 か 64
  s16 hp;                                        // 0x016, '.l=0x80'
  u8 hitCooldown;                                // 0x018
  u8 phase;                                      // 0x019, 0: 動作中, 2: そのまま解放, 3: 破壊エフェクトを出して解放
  u16 plttID;                                    // 0x01A, '.d=-1'
  u16 flashPlttID;                               // 0x01C
  bool8 active;                                  // 0x01E, 0 なら空き枠
  u8 flashTimer;                                 // 0x01F
  u8 breakStep;                                  // 0x020
  u8 seCooldown;                                 // 0x021
  u8 unk_22;                                     // 0x022
  u8 unk_23;                                     // 0x023
  bool8 pushLimited;                             // 0x024, kind == 5 なら押せる回数に限りがある
  u8 pushCount;                                  // 0x025, 押せる残り回数
  u8 unk_26[2];                                  // 0x026
  u32 breakScript;                               // 0x028, '.b', 壊れたときに実行するスクリプト
  Mover mover;                                   // 0x02C
  AuxSpriteGfx gfx;                              // 0x070, '.a'
  AuxSprite sprite;                              // 0x08C
  MapTileOverride tile;                          // 0x0B8
  HitboxData hurtbox;                            // 0x0C8
  HitboxData hitbox;                             // 0x118
  ZoneEventSource zoneEvents;                    // 0x168
  void (*updateCallback)(struct MovableBlock*);  // 0x198
} MovableBlock;
static_assert(sizeof(MovableBlock) == 412);

// OBJ パレット4行を抱えて、count 個の要素 (1個 412バイト) を回すシングルトン
typedef struct {
  Entity blk;            // 0x00, ENTITY_UNK_8
  u16 count;             // 0x18, blocks の要素数, _Create が '.m=8' を入れ、0 なら 8 にする
  u8 oddFrame;           // 0x1A, 毎フレーム 0 と 1 を行き来する
  u8 fadeBack;           // 0x1B, 1 の間は fadeLevel を 0 へ戻していく
  u16 fadeLevel;         // 0x1C, 0〜32, pltt[2]/pltt[3] へ寄せる割合
  u8 fadeEnabled;        // 0x1E, kind 6 (紋章ブロック) を置くと立ち, パレットの明滅を回す
  u8 unk_1f;             // 0x1F, Cmd_B76C が紋章ブロックを光らせると 1, 明滅が戻りきると 0
  rgb555* pltt[4];       // 0x20, &gObjPlttData[0x20/0x30/0x40/0x50] (OBJ パレットの4行)
  rgb555 savedPltt[16];  // 0x30, _Init が pltt[2] の16色をコピーする
  rgb555 unk_50[16];     // 0x50, _Init が pltt[3] の16色をコピーする (savedPltt と同じ内容)
  MovableBlock* blocks;  // 0x70
} MovableBlockManager;
static_assert(sizeof(MovableBlockManager) == 116);

static MovableBlockManager* sMovableBlockManager;  // 0x03000020

const u8 u8_ARRAY_085aa650[8] = {2, 2, 3, 3, 0, 0, 1, 1};  // 0x085AA650

void MovableBlock_UpdateMove(MovableBlock* blk);
void MovableBlock_UpdateFall(MovableBlock* blk);
void MovableBlock_UpdateBreak(MovableBlock* blk);
s32 FUN_08014da0(s32 param_1, s32 param_2, Vec3* pos, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12);
s32 FUN_08016110(u32 val1, u32 val2, u32 val3, u32 val4, Vec3* pos);

// 状態を切り替えてタイマーを戻し, 入場の印を立てる
static inline void MovableBlock_SetState(MovableBlock* blk, void (*fn)(MovableBlock*), s32 state) {
  blk->updateCallback = fn;
  blk->timer = 0;
  blk->stateEntered = TRUE;
  blk->state = state;
}

void FUN_08003008(void) { sMovableBlockManager = NULL; }

// 132/102命令, 1回目の下書きで切り上げ, 原典は毎回の先頭で gRandTableIdx だけ進めて捨てる
NON_MATCH void MovableBlock_SpawnDust(Vec3* pos, s16 edgeOffset) {
#ifdef NONMATCHING_C
  Vec3 size, at;
  s32 i;

  VEC3_SET(size, 32, 0, 32);
  for (i = 0; i < 10; i++) {
    RandomNext();
    at = *pos;
    if (!(i & 1)) {
      at.x = (RandomNext() & 0xF) + edgeOffset + at.x;
      at.z = at.z - 128 + (u8)RandomNext();
    } else {
      at.x = at.x - 128 + (u8)RandomNext();
      at.z = (RandomNext() & 0xF) + edgeOffset + at.z;
    }
    DustManager_Spawn(&at, NULL, &size, 1, 3, 4);
  }
#else
  INCFUNC("asm/func/MovableBlock_SpawnDust.inc");
#endif
}

// 78/79命令, 末尾の attr の判定の後の分岐の向き (原典は bne で FALSE へ跳ぶ) と FALSE の置き場所が違う, || の分解は試済
NON_MATCH bool8 MovableBlock_IsSideBlocked(MovableBlock* blk, s32 tileIdx, s32 dir) {
#ifdef NONMATCHING_C
  CollisionMapTile* self = &blk->tile.tile;
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 offset = 0;
  s32 idx;

  switch (dir) {
    case DIR4_NORTH: {
      offset = -gCollisionMap->tiledata->width;
      break;
    }
    case DIR4_EAST: {
      offset = 1;
      break;
    }
    case DIR4_SOUTH: {
      offset = gCollisionMap->tiledata->width;
      break;
    }
    case DIR4_WEST: {
      offset = -1;
      break;
    }
  }
  idx = tileIdx + offset;
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
  INCFUNC("asm/func/MovableBlock_IsSideBlocked.inc");
#endif
}

void MovableBlock_PlayHitWallSound(u32 kind) {
  if (kind == B_TOMBSTONE) {
    PlaySound_082406e0(SE_THUD);
  } else {
    PlaySound_082406e0(SE_THUD);
  }
}

bool8 MovableBlock_IsFacingWall(MovableBlock* blk, s32 tileIdx, s32 dir) {
  CollisionMapTile* self = &blk->tile.tile;
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 offset = 0;
  s32 idx;

  switch (dir) {
    case DIR4_NORTH: {
      offset = -gCollisionMap->tiledata->width;
      break;
    }
    case DIR4_EAST: {
      offset = 1;
      break;
    }
    case DIR4_SOUTH: {
      offset = gCollisionMap->tiledata->width;
      break;
    }
    case DIR4_WEST: {
      offset = -1;
      break;
    }
  }
  idx = tileIdx + offset;
  ov = Map_FindTileOverride(idx, 1);
  tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
  if (tile != NULL) {
    if ((tile->heightStairs & 0xF) >= (self->heightStairs & 0xF)) {
      return TRUE;
    }
    if (blk->kind == B_TOMBSTONE) {
      MovableBlock_PlayHitWallSound(blk->kind);
    }
  }
  return FALSE;
}

bool8 MovableBlock_IsEnclosed(MovableBlock* blk) {
  s32 count = 0;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (MovableBlock_IsSideBlocked(blk, blk->tile.tileIdx, i)) {
      count++;
    }
  }
  if (count > 2) {
    return TRUE;
  }
  return FALSE;
}

// mapFlags の判定を bool8 を返す inline にすると 105/111 命令まで寄るが, 原典は sprite.pos を2語で写した時点で y + 442 をレジスタの中で済ませてから置く, Vec3_CopyOffsetY は試済 (悪化)
NON_MATCH void MovableBlock_OnLanded(MovableBlock* blk) {
#ifdef NONMATCHING_C
  if (gStat->mapFlags & MPF_UNK_8) {
    Vec3 pos;

    PlaySound_082406e0(SONG_325);
    pos = blk->sprite.pos;
    pos.y += 442;
    pos.x += 128;
    pos.z += 128;
    FUN_08016110(1, 0, 0, 30, &pos);
  }
  switch (blk->kind) {
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
  if (!MovableBlock_IsEnclosed(blk)) {
    MovableBlock_SpawnDust(&blk->mover.pos, 0x90);
  } else {
    Puff_SpawnSprayEx(4, 1, 1, Q6(1), 0, 0xFF, 2, 4, 6, 6, &blk->sprite.pos);
  }
#else
  INCFUNC("asm/func/MovableBlock_OnLanded.inc");
#endif
}

void MovableBlock_OnHitWall(MovableBlock* blk) {
  if (MovableBlock_IsFacingWall(blk, blk->tile.tileIdx, blk->dir)) {
    Vec3 pos = blk->sprite.pos;
    s32 angle = 0;

    switch (blk->dir) {
      case DIR4_NORTH: {
        pos.z -= 128;
        angle = 0xB0;
        break;
      }
      case DIR4_EAST: {
        pos.x += 128;
        angle = -16;
        break;
      }
      case DIR4_SOUTH: {
        pos.z += 128;
        angle = 0x30;
        break;
      }
      case DIR4_WEST: {
        pos.x -= 128;
        angle = 0x70;
        break;
      }
    }
    Puff_SpawnSprayEx(2, 1, 1, Q6(1), angle, 0x1F, 2, 4, 6, 6, &pos);
    MovableBlock_PlayHitWallSound(blk->kind);
  }
}

void MovableBlock_PlayPushSound(s32 kind) {
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

void MovableBlock_OnDamaged(HitboxData* hurtbox, HitboxData* b, void* owner) {
  bool8 hit = FALSE;
  MovableBlock* blk = owner;

  if (blk->kind == B_ROCK) {
    if (TEST_FLAGS(hurtbox->weakness, 7) && TEST_FLAGS(hurtbox->attributes, HBATTR_CLOUD)) {
      blk->hp -= 24;
      blk->hitCooldown = 10;
      blk->flashTimer = 2;
      Video_SetAuxSpritePltt(&blk->gfx, blk->flashPlttID);
      hit = TRUE;
    }
  } else if (blk->kind == B_ICE) {
    if (TEST_FLAGS(hurtbox->attributes, HBATTR_FLAME) && TEST_FLAGS(hurtbox->weakness, 0x10007) && !(hurtbox->weakness & 0x40)) {
      blk->hp -= 24;
      blk->hitCooldown = 10;
      blk->flashTimer = 2;
      Video_SetAuxSpritePltt(&blk->gfx, blk->flashPlttID);
      if (blk->seCooldown == 0) {
        blk->seCooldown = 10;
        PlaySound_082406e0(SONG_348);
        Puff_SpawnSprayOne(&blk->mover.pos, 0, 0, Q6(1), 12, 12, 4, 4);
      }
      hit = TRUE;
    }
  } else if (blk->kind == B_WOOD) {
    if (TEST_FLAGS(hurtbox->weakness, 4)) {
      blk->hp -= 24;
      blk->hitCooldown = 10;
      blk->flashTimer = 2;
      Video_SetAuxSpritePltt(&blk->gfx, blk->flashPlttID);
      hit = TRUE;
    }
  }
  if (!hit) {
    return;
  }
  if ((blk->state == 1 || blk->state == 2) && blk->hp <= 0) {
    blk->hp = 1;
  }
  if (blk->hp < 0) {
    blk->hp = 0;
    return;
  }
  if (!TEST_FLAGS(hurtbox->weakness, 4)) {
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
  }
}

void FUN_080035e0(void) {}

// 90/86命令, 原典は blk を r12, 要素を r3 に置き -256 を pool からループの外で読む, 状態切り替えの inline と直書きは試済
NON_MATCH void MovableBlock_DropUpper(MovableBlock* blk) {
#ifdef NONMATCHING_C
  MovableBlockManager* p = sMovableBlockManager;
  MovableBlock* other = p->blocks;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (other->active && other != blk && other->tile.tileIdx == blk->tile.tileIdx && other->state == 0 && (blk->tile.tile.heightStairs & 0xF) < (other->tile.tile.heightStairs & 0xF)) {
      other->updateCallback = MovableBlock_UpdateFall;
      other->timer = 0;
      other->stateEntered = TRUE;
      other->state = 2;
      other->moveX = 0;
      other->moveZ = 0;
      other->dir = 0;
      other->targetY = other->mover.pos.y;
      if (other->targetY < 256) {
        other->targetY = 0;
      } else {
        other->targetY -= 256;
      }
    }
    other++;
  }
#else
  INCFUNC("asm/func/MovableBlock_DropUpper.inc");
#endif
}

s32 MovableBlock_Release(MovableBlock* blk) {
  AuxSprite_Remove(&blk->sprite);
  Map_RemoveTileOverride(&blk->tile);
  Hitbox_Unregister(&blk->hurtbox);
  if (!(blk->flags & 2)) {
    FUN_08002a58(&blk->mover);
  }
  Mover_Unlink(&blk->mover);
  blk->active = FALSE;
  return 0;
}

s32 Cmd_ReleaseAllMovableBlocks(void) {
  MovableBlockManager* p = sMovableBlockManager;
  MovableBlock* blk;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  blk = p->blocks;
  for (i = 0; i < p->count; i++) {
    if (blk->active) {
      MovableBlock_Release(blk);
    }
    blk++;
  }
  return 0;
}

s32 Cmd_5C0B(void) {
  MovableBlockManager* p = sMovableBlockManager;
  MovableBlock* blk;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  blk = p->blocks;
  for (i = 0; i < p->count; i++) {
    if (blk->active && blk->kind == B_ICE) {
      blk->hp = 0;
      if (blk->state == 0) {
        blk->updateCallback = MovableBlock_UpdateBreak;
        blk->timer = 0;
        blk->stateEntered = TRUE;
        blk->state = 3;
      }
    }
    blk++;
  }
  return 0;
}

s32 Cmd_0E76(void) {
  MovableBlockManager* p = sMovableBlockManager;
  u32 id;
  MovableBlock* blk;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  id = VM_GetNamedArgValue('n', 0);
  blk = p->blocks;
  for (i = 0; i < p->count; i++) {
    if (blk->active && blk->mover.id == id) {
      MovableBlock_Release(blk);
    }
    blk++;
  }
  return 0;
}

void MovableBlock_BreakEffect0(MovableBlock* blk) {
  WorldPos* pos;
  Vec3 at, vel, velRange;

  PlaySound_082406e0(SONG_347);
  pos = &blk->mover.pos;
  FUN_08014da0(3, 2, pos, 60, 30, 16, 8, 8, 0, 0x100, 24, 16);
  FUN_08014da0(8, 6, pos, 60, 30, 22, 8, 8, 0, 0x100, 24, 16);
  at.x = blk->mover.pos.x;
  at.y = blk->mover.pos.y + 128;
  at.z = blk->mover.pos.z;
  VEC3_SET(vel, -15, 8, -15);
  VEC3_SET(velRange, 30, 22, 30);
  ScatterEffect_Spawn(8, SCATTER_STONE, &at, &vel, &velRange, 60, 60);
}

void MovableBlock_BreakEffect1(MovableBlock* blk) {
  Vec3 pos, vel, velRange;

  PlaySound_082406e0(SONG_309);
  FUN_08014da0(4, 0, &blk->mover.pos, 60, 30, 20, 8, 8, 0, 0x100, 24, 16);
  pos.x = blk->mover.pos.x;
  pos.y = blk->mover.pos.y + 128;
  pos.z = blk->mover.pos.z;
  VEC3_SET(vel, -15, 8, -15);
  VEC3_SET(velRange, 30, 22, 30);
  ScatterEffect_Spawn(8, SCATTER_ICE, &pos, &vel, &velRange, 60, 60);
}

void MovableBlock_BreakEffect2(MovableBlock* blk) {
  WorldPos* pos;

  PlaySound_082406e0(SONG_336);
  pos = &blk->mover.pos;
  FUN_08014da0(3, 1, pos, 60, 30, 16, 8, 8, 0, 0x100, 24, 16);
  FUN_08014da0(8, 5, pos, 60, 30, 22, 8, 8, 0, 0x100, 24, 16);
}

// 190/183命令, 1回目の下書きで切り上げ, 乱数の & 0xFF と & 0xF の並びが違う
NON_MATCH void MovableBlock_SpawnMoveDust(MovableBlock* blk) {
#ifdef NONMATCHING_C
  Vec3 size, at;
  s32 i;

  VEC3_SET(size, 32, 0, 32);
  for (i = 0; i < 3; i++) {
    at = blk->mover.pos;
    switch (blk->dir) {
      case DIR4_NORTH: {
        at.x = at.x - 128 + (u8)RandomNext();
        at.z = at.z + 120 + (RandomNext() & 0xF);
        break;
      }
      case DIR4_EAST: {
        at.x = at.x - 120 - (RandomNext() & 0xF);
        at.z = at.z - 128 + (u8)RandomNext();
        break;
      }
      case DIR4_SOUTH: {
        at.x = at.x - 128 + (u8)RandomNext();
        at.z = at.z - 120 - (RandomNext() & 0xF);
        break;
      }
      case DIR4_WEST: {
        at.x = at.x + 120 + (RandomNext() & 0xF);
        at.z = at.z - 128 + (u8)RandomNext();
        break;
      }
    }
    DustManager_Spawn(&at, NULL, &size, 1, 2, 4);
  }
#else
  INCFUNC("asm/func/MovableBlock_SpawnMoveDust.inc");
#endif
}

// 194/196命令, 原典は moveX/moveZ/frames をスタックに置き dir を r8 に持つ, 1回目の下書きで切り上げ
NON_MATCH s32 MovableBlock_TryMove(MovableBlock* blk, s32 tileIdx, s32 dir) {
#ifdef NONMATCHING_C
  CollisionMapTile* self = &blk->tile.tile;
  CollisionMapTile* tile;
  MapTileOverride* ov;
  s32 offset = 0;
  s16 moveX = 0;
  s16 moveZ = 0;
  s32 step;
  u16 frames;
  s32 idx, height, selfHeight;

  if ((gGoodCondTimer != 0 && gGoodCondID == GOOD_POWER) || blk->kind == B_ICE) {
    step = 16;
    frames = 16;
  } else {
    step = 4;
    frames = 64;
  }
  switch (dir) {
    case DIR4_NORTH: {
      offset = -gCollisionMap->tiledata->width;
      moveZ = -step;
      break;
    }
    case DIR4_EAST: {
      offset = 1;
      moveX = step;
      break;
    }
    case DIR4_SOUTH: {
      offset = gCollisionMap->tiledata->width;
      moveZ = step;
      break;
    }
    case DIR4_WEST: {
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
    blk->targetY = height << 8;
    blk->dir = dir;
    blk->updateCallback = MovableBlock_UpdateMove;
    blk->timer = 0;
    blk->stateEntered = TRUE;
    blk->moveX = moveX;
    blk->moveZ = moveZ;
    blk->state = 2;
    blk->tile.tileIdx = idx;
    blk->moveFrames = frames;
    return 3;
  }
  blk->targetY = height << 8;
  {
    s32 h = self->heightStairs & 0xF;

    if (h > 0) {
      h--;
    }
    self->heightStairs = (self->heightStairs & 0xF0) | h;
  }
  self->occluder = tile->occluder;
  blk->dir = dir;
  blk->updateCallback = MovableBlock_UpdateMove;
  blk->timer = 0;
  blk->stateEntered = TRUE;
  blk->moveX = moveX;
  blk->moveZ = moveZ;
  blk->state = 1;
  blk->tile.tileIdx = idx;
  blk->moveFrames = frames;
  return 1;
#else
  INCFUNC("asm/func/MovableBlock_TryMove.inc");
#endif
}

// 233/233命令, 残差はスタックの退避の並びと原典のフレームが 4 バイト小さいことだけ
NON_MATCH s32 MovableBlock_PushAt(Vec3* pos, s32 dir) {
#ifdef NONMATCHING_C
  MovableBlockManager* p = sMovableBlockManager;
  CollisionMapTile* tile;
  MovableBlock* blk;
  s32 idx, offset, i;

  if (p == NULL) {
    return -1;
  }
  tile = GetTileAt(pos);
  idx = GetCollisionTileIdx(pos);
  offset = 0;
  switch (dir) {
    case DIR4_NORTH: {
      offset = -gCollisionMap->tiledata->width;
      break;
    }
    case DIR4_EAST: {
      offset = 1;
      break;
    }
    case DIR4_SOUTH: {
      offset = gCollisionMap->tiledata->width;
      break;
    }
    case DIR4_WEST: {
      offset = -1;
      break;
    }
  }
  blk = p->blocks;
  for (i = 0; i < p->count; i++) {
    if (blk->active && blk->state == 0) {
      s32 target = idx + offset;

      if (target == blk->tile.tileIdx && (tile->heightStairs & 0xF) + 1 == (blk->tile.tile.heightStairs & 0xF)) {
        MapTileOverride* ov = Map_FindTileOverride(target, 1);
        CollisionMapTile* dst = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[target];

        if ((dst->heightStairs & 0xF) == (blk->tile.tile.heightStairs & 0xF)) {
          s32 result;

          if (blk->pushLimited && blk->pushCount == 0) {
            return 0;
          }
          result = MovableBlock_TryMove(blk, blk->tile.tileIdx, dir);
          if (result > 0) {
            MovableBlock_PlayPushSound(blk->kind);
            if (blk->kind == B_ICE) {
              result = -1;
            }
            if (blk->pushCount != 0) {
              blk->pushCount--;
            }
          }
          return result;
        }
      }
    }
    blk++;
  }
  return 0;
#else
  INCFUNC("asm/func/MovableBlock_PushAt.inc");
#endif
}

s32 MovableBlock_PushAtDir8(Vec3* pos, u32 dir) { return MovableBlock_PushAt(pos, u8_ARRAY_085aa650[dir]); }

// 34/34命令, 原典は kind == 1 の 1 を stateEntered に使い回して退避レジスタが r4 だけ, 状態切り替えの inline を通すと r5 が増え, 直書きだと関数ポインタの読みが後ろに回る
NON_MATCH void MovableBlock_UpdateIdle(MovableBlock* blk) {
#ifdef NONMATCHING_C
  if (blk->kind == B_ICE) {
    if (blk->hp <= 0) {
      MovableBlock_SetState(blk, MovableBlock_UpdateBreak, 3);
    }
  } else if (blk->hp <= 0) {
    blk->phase = 3;
    blk->updateCallback = NULL;
  }
#else
  INCFUNC("asm/func/MovableBlock_UpdateIdle.inc");
#endif
}

void MovableBlock_UpdateMove(MovableBlock* blk) {
  Mover* mover = &blk->mover;
  CollisionMapTile* tile = &blk->tile.tile;

  if (blk->stateEntered) {
    blk->stateEntered = FALSE;
    tile->attr |= TATTR_UNK_0;
  }
  mover->delta.x = blk->moveX;
  mover->delta.z = blk->moveZ;
  mover->pos.y = (tile->heightStairs & 0xF) << 8;
  if (blk->state == 2) {
    mover->pos.y -= 256;
  }
  blk->sprite.pos.y = mover->pos.y;
  Hitbox_SetPos(&blk->hitbox, &mover->pos, 0);
  Hitbox_Register(&blk->hitbox);
  if (blk->kind != 1 && !(blk->timer & 3)) {
    MovableBlock_SpawnMoveDust(blk);
  }
  if (++blk->timer >= blk->moveFrames) {
    s32 height = tile->heightStairs & 0xF;

    if (height < 15) {
      height++;
    }
    tile->heightStairs = (tile->heightStairs & 0xF0) | height;
    tile->occluder = 0xFF;
    if (blk->kind == B_ICE) {
      if (blk->state == 2) {
        MovableBlock_SetState(blk, MovableBlock_UpdateFall, 2);
        blk->moveX = 0;
        blk->moveZ = 0;
        blk->dir = 0;
      } else if (!MovableBlock_TryMove(blk, blk->tile.tileIdx, blk->dir)) {
        MovableBlock_OnHitWall(blk);
        MovableBlock_SetState(blk, MovableBlock_UpdateIdle, 0);
        blk->moveX = 0;
        blk->moveZ = 0;
        blk->dir = 0;
        tile->attr &= ~TATTR_UNK_0;
      }
    } else {
      if (blk->state == 2) {
        MovableBlock_SetState(blk, MovableBlock_UpdateFall, 2);
      } else {
        MovableBlock_OnHitWall(blk);
        MovableBlock_SetState(blk, MovableBlock_UpdateIdle, 0);
        tile->attr &= ~TATTR_UNK_0;
      }
      blk->moveX = 0;
      blk->moveZ = 0;
      blk->dir = 0;
    }
  }
}

// 99/97命令, 残差は dy の符号拡張と最後の状態切り替えで関数ポインタを先に読む形, 状態切り替えの inline は途中に moveX などが挟まるので使えない
NON_MATCH void MovableBlock_UpdateFall(MovableBlock* blk) {
#ifdef NONMATCHING_C
  Mover* mover = &blk->mover;
  CollisionMapTile* tile = &blk->tile.tile;
  s16 dy;

  if (blk->stateEntered) {
    s32 height;

    blk->stateEntered = FALSE;
    height = (blk->targetY >> 8) + 1;
    if (height > 15) {
      tile->heightStairs = (tile->heightStairs & 0xF0) | 0xF;
    } else {
      tile->heightStairs = (tile->heightStairs & 0xF0) | height;
    }
    if (TEST_FLAGS(blk->flags, 8)) {
      blk->tile.tile.attr |= TATTR_UNK_0 | TATTR_UNK_5;
    }
  }
  dy = blk->targetY - mover->pos.y;
  mover->delta.y = dy;
  if (dy < -16) {
    mover->delta.y = -16;
  } else if (dy > 0) {
    mover->delta.y = 0;
  }
  if (mover->delta.y == 0) {
    if (TEST_FLAGS(blk->flags, 8)) {
      blk->tile.tile.attr |= TATTR_UNK_0 | TATTR_UNK_5;
      blk->hp = 0;
    } else {
      blk->tile.tile.attr &= ~(TATTR_UNK_0 | TATTR_UNK_5);
      MovableBlock_OnLanded(blk);
    }
    blk->updateCallback = MovableBlock_UpdateIdle;
    blk->timer = 0;
    blk->stateEntered = TRUE;
    blk->moveX = 0;
    blk->moveZ = 0;
    blk->dir = 0;
    blk->state = 0;
  }
#else
  INCFUNC("asm/func/MovableBlock_UpdateFall.inc");
#endif
}

void MovableBlock_UpdateBreak(MovableBlock* blk) {
  if (blk->stateEntered) {
    blk->stateEntered = FALSE;
    blk->breakStep = 0;
    AuxSprite_SetPoseIdx(&blk->sprite, 0);
    PlaySound_082406e0(SONG_310);
    blk->tile.tile.attr |= TATTR_UNK_0 | TATTR_UNK_5;
    if (blk->breakScript != 0) {
      u32 argv[5];
      ScriptArgs sa;

      argv[0] = blk->mover.id;
      argv[1] = blk->kind;
      argv[2] = blk->mover.pos.x;
      argv[3] = blk->mover.pos.y;
      argv[4] = blk->mover.pos.z;
      sa.argc = 5;
      sa.argv = argv;
      VM_ExecByID(blk->breakScript, &sa);
      blk->breakScript = 0;
    }
  }
  if (blk->breakStep == 0) {
    if (Mod(blk->timer, 2) == 0) {
      if (blk->sprite.poseIdx == 0) {
        AuxSprite_SetPoseIdx(&blk->sprite, 1);
      } else {
        AuxSprite_SetPoseIdx(&blk->sprite, 0);
      }
    }
    if (blk->timer++ > 29) {
      blk->timer = 0;
      blk->breakStep++;
    }
  } else if (blk->timer++ > 5) {
    blk->timer = 0;
    if (++blk->breakStep >= 4) {
      blk->phase = 2;
    } else {
      AuxSprite_SetPoseIdx(&blk->sprite, blk->breakStep);
    }
  }
}

void MovableBlock_UpdateAppear(MovableBlock* blk) {
  if (blk->stateEntered) {
    blk->stateEntered = FALSE;
    blk->breakStep = 3;
    AuxSprite_SetPoseIdx(&blk->sprite, 3);
    PlaySound_082406e0(SONG_310);
  }
  if (blk->breakStep != 0) {
    if (blk->timer++ > 5) {
      blk->timer = 0;
      blk->breakStep--;
      AuxSprite_SetPoseIdx(&blk->sprite, blk->breakStep);
    }
  } else {
    MovableBlock_SetState(blk, MovableBlock_UpdateIdle, 0);
  }
}

static void (*const sMovableBlockBreakEffects[5])(MovableBlock*) = {
    MovableBlock_BreakEffect0,
    MovableBlock_BreakEffect1,
    MovableBlock_BreakEffect2,
    NULL,
    NULL,
};  // 0x085AA658

// 244/264命令, 原典は &hurtbox.flags と &hitCooldown をループの外で作って要素ごとに足して回す, 1回目の下書きで切り上げ
NON_MATCH s32 MovableBlockManager_Update(MovableBlockManager* p) {
#ifdef NONMATCHING_C
  MovableBlock* blk = p->blocks;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (blk->active) {
      if (blk->phase == 0) {
        Mover_ApplyMove(&blk->mover);
        if (blk->updateCallback != NULL) {
          blk->updateCallback(blk);
        }
        if (!(blk->flags & 0x20)) {
          Map_UpdateZoneEvents(&blk->zoneEvents);
        } else if (blk->state == 0) {
          blk->tile.tile.attr &= ~TATTR_WALL;
          Map_UpdateZoneEvents(&blk->zoneEvents);
        } else {
          blk->tile.tile.attr |= TATTR_WALL;
        }
        if (blk->seCooldown != 0) {
          blk->seCooldown--;
        }
        if (blk->zone == 0 || gStat->zoneID == blk->zone) {
          blk->sprite.flags &= ~SPRFLAG_HIDDEN;
        } else {
          blk->sprite.flags |= SPRFLAG_HIDDEN;
        }
        if (blk->hitCooldown == 0 && blk->hp > 0) {
          if (blk->zone != 0 && gStat->zoneID != blk->zone) {
            blk->hurtbox.flags |= HBFLAG_HIDDEN;
          } else {
            blk->hurtbox.flags &= ~HBFLAG_HIDDEN;
            Hitbox_SetPos(&blk->hurtbox, &blk->mover.pos, 0);
          }
        } else {
          blk->hitCooldown--;
          blk->hurtbox.flags |= HBFLAG_HIDDEN;
        }
        if (blk->flashTimer != 0 && --blk->flashTimer == 0) {
          Video_SetAuxSpritePltt(&blk->gfx, blk->plttID);
        }
      } else {
        if (blk->phase == 3 && sMovableBlockBreakEffects[blk->kind] != NULL) {
          sMovableBlockBreakEffects[blk->kind](blk);
        }
        if (blk->breakScript != 0) {
          u32 argv[5];
          ScriptArgs sa;

          argv[0] = blk->mover.id;
          argv[1] = blk->kind;
          argv[2] = blk->mover.pos.x;
          argv[3] = blk->mover.pos.y;
          argv[4] = blk->mover.pos.z;
          sa.argc = 5;
          sa.argv = argv;
          VM_ExecByID(blk->breakScript, &sa);
          blk->breakScript = 0;
        }
        MovableBlock_DropUpper(blk);
        MovableBlock_Release(blk);
      }
    }
    blk++;
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
  INCFUNC("asm/func/MovableBlockManager_Update.inc");
#endif
}

s32 MovableBlockManager_Destroy(MovableBlockManager* p) {
  Cmd_ReleaseAllMovableBlocks();
  Free(p->blocks);
  sMovableBlockManager = NULL;
  return 0;
}

s32 MovableBlockManager_Init(MovableBlockManager* p, u32 id) {
  sMovableBlockManager = p;
  if (p->count == 0) {
    p->count = 8;
  }
  p->blocks = Malloc(p->count * sizeof(MovableBlock));
  if (p->blocks == NULL) {
    return -1;
  }
  ClearMemory(p->blocks, p->count * sizeof(MovableBlock));
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
MovableBlockManager* MovableBlockManager_Create(u32 id, u32 _) {
  MovableBlockManager* p;

  if (sMovableBlockManager != NULL) {
    return sMovableBlockManager;
  }
  p = (MovableBlockManager*)CreateEntity(ENTITY_UNK_8, sizeof(MovableBlockManager));
  if (p != NULL) {
    SetEntityRoutine(&p->blk, MovableBlockManager_Update, MovableBlockManager_Destroy);
    p->count = VM_GetNamedArgValue('m', 8);
    if (MovableBlockManager_Init(p, id) < 0) {
      KillEntity(&p->blk);
      return NULL;
    }
  }
  return p;
}

// 空いている枠を返す, 無ければ NULL
MovableBlock* MovableBlockManager_FindFreeBlock(MovableBlockManager* p) {
  MovableBlock* blk = p->blocks;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (!blk->active) {
      return blk;
    }
    blk++;
  }
  return NULL;
}

// id が一致する使用中の枠を返す, 無ければ NULL
MovableBlock* MovableBlockManager_FindBlockByID(MovableBlockManager* p, u32 id) {
  MovableBlock* blk = p->blocks;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (blk->active && blk->mover.id == id) {
      return blk;
    }
    blk++;
  }
  return NULL;
}

// 386/355命令 (id を u32 にする前), 原典は gfx と mover のアドレスを先に作って持ち越す, 1回目の下書きで切り上げ
NON_MATCH s32 MovableBlock_Spawn(u32 id, s32 kind, s32 flags, Vec3* pos, s32 file, s32 poseIdx, s32 hp, s32 plttID, s32 flashPlttID, u32 breakScript) {
#ifdef NONMATCHING_C
  MovableBlockManager* p = sMovableBlockManager;
  MovableBlock* blk;
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
  blk = MovableBlockManager_FindFreeBlock(p);
  if (blk == NULL) {
    return -1;
  }
  ClearMemory(blk, sizeof(MovableBlock));
  blk->active = TRUE;
  blk->kind = kind;
  if ((u8)kind == B_EMBLEM) {
    p->fadeEnabled = 1;
  }
  blk->flags = flags;
  blk->timer = 0;
  blk->state = 0;
  gfx = &blk->gfx;
  Video_GetAuxSprite(gfx, file);
  AuxSprite_Add(&blk->sprite, gfx, 0);
  blk->sprite.poseIdx = poseIdx;
  blk->sprite.pos = *pos;
  mover = &blk->mover;
  Mover_Init(mover, id, pos, 0, 7, blk);
  Mover_SetAuxSprite(mover, &blk->sprite);
  blk->mover.pos = blk->sprite.pos;
  if (blk->flags & 0x10) {
    blk->zone = GetZoneAt(&blk->mover.pos);
  } else {
    blk->zone = 0;
  }
  mpos = &blk->mover.pos;
  blk->moveX = 0;
  blk->moveZ = 0;
  blk->dir = 0;
  if (blk->flags & 4) {
    blk->updateCallback = MovableBlock_UpdateAppear;
    blk->timer = 0;
  } else {
    blk->updateCallback = MovableBlock_UpdateIdle;
    blk->timer = 0;
  }
  blk->stateEntered = TRUE;
  tileIdx = GetCollisionTileIdx(&blk->mover.pos);
  height = GetTileAt(&blk->mover.pos)->heightStairs & 0xF;
  if (height < 15) {
    height++;
  }
  Map_AddTileOverride(&blk->tile, tileIdx, 0, height, 0xFF, 0);
  blk->targetY = height << 8;
  VEC3_SET(size, 130, 128, 130);
  VEC3_SET(offset, 0, 128, 0);
  hurtbox = &blk->hurtbox;
  Hitbox_Init(hurtbox, blk->mover.id, HBFLAG_HURTBOX | HBFLAG_UNK_6 | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(hurtbox, mpos, 0);
  Hitbox_SetHandler(hurtbox, MovableBlock_OnDamaged, blk);
  Hitbox_Register(hurtbox);
  VEC3_SET(size, 128, 128, 128);
  hitbox = &blk->hitbox;
  Hitbox_Init(hitbox, blk->mover.id, HBFLAG_HITBOX | HBFLAG_UNK_11 | HBFLAG_UNK_0, 0, HIM_0, &size, &offset);
  Hitbox_SetPos(hitbox, mpos, 0);
  Hitbox_SetHandler(hitbox, FUN_080035e0, blk);
  Hitbox_SetPower(hitbox, 1500, 50);
  blk->hitbox.weakness = 0x100;
  blk->hitbox.attributes = 0;
  blk->hp = hp;
  blk->hitCooldown = 0;
  blk->phase = 0;
  blk->flashTimer = 0;
  blk->breakStep = 0;
  blk->seCooldown = 0;
  blk->unk_23 = 4;
  blk->unk_22 = Mod(Random(), 16);
  if (plttID < 0) {
    blk->plttID = blk->gfx.plttID;
  } else {
    blk->plttID = plttID;
  }
  Video_SetAuxSpritePltt(gfx, blk->plttID);
  blk->flashPlttID = flashPlttID;
  blk->zoneEvents.id = blk->mover.id;
  blk->zoneEvents.pos = mpos;
  blk->breakScript = breakScript;
  if (!(blk->flags & 2) && FUN_08002a48(mover) < 0) {
    blk->flags |= 2;
  }
  limited = blk->kind == B_TOMBSTONE;
  blk->pushLimited = limited;
  blk->pushCount = limited;
  return 0;
#else
  INCFUNC("asm/func/MovableBlock_Spawn.inc");
#endif
}

// 0xE02A, 161/164命令, 原典は kind ごとの既定ファイルを分岐ごとに r1 に置いて VM_GetNamedArgValue へ渡すが, こちらは条件付きの読み込みに畳まれる, 既定値を返す inline は試済, id を原典はスタックに退避する
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
    pos.x = VM_GetValue(), pos.y = VM_GetValue(), pos.z = VM_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }
  if (kind == B_ROCK) {
    file = SPRITE_BLOCK_ROCK;
  } else if (kind == B_ICE) {
    file = SPRITE_BLOCK_ICE;
  } else if (kind == B_WOOD) {
    file = SPRITE_WOODEN_BOX;
  } else if (kind == B_UNK3) {
    file = SPRITE_BLOCK_9D43;
  } else if (kind == B_ARITH) {
    file = SPRITE_BLOCK_ARITH;
  } else if (kind == B_TOMBSTONE) {
    file = SPRITE_TOMBSTONE;
  } else if (kind == B_EMBLEM) {
    file = SPRITE_BLOCK_EMBLEM;
  } else {
    file = SPRITE_BLOCK_ROCK;
  }
  file = VM_GetNamedArgValue('a', file);
  poseIdx = VM_GetNamedArgValue('i', 0);
  hp = VM_GetNamedArgValue('l', 128);
  if (kind == B_ROCK) {
    plttID = 0x23D;
  } else if (kind == B_ICE) {
    plttID = 0x241;
  } else if (kind == B_WOOD || kind == B_ARITH) {
    plttID = 0x1FD;
  } else if (kind == B_UNK3) {
    plttID = 0x4F;
  } else if (kind == B_TOMBSTONE) {
    plttID = 0x8B;
  } else if (kind == B_EMBLEM) {
    if (poseIdx == 0 || poseIdx == 2) {
      plttID = OBP_EMBLEM_BLOCK(0);
    } else {
      plttID = OBP_EMBLEM_BLOCK(1);
    }
  } else {
    plttID = VM_GetNamedArgValue('d', -1);
  }
  MovableBlock_Spawn(id, kind, flags, &pos, file, poseIdx, hp, plttID, OBP_WHITE_306, VM_GetNamedArgValue('b', 0));
  return 0;
#else
  INCFUNC("asm/func/Cmd_E02A.inc");
#endif
}

// 0xB76C
s32 Cmd_B76C(void) {
  MovableBlockManager* p = sMovableBlockManager;
  MovableBlock* blk;
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
  blk = MovableBlockManager_FindBlockByID(p, id);
  if (blk == NULL || blk->kind != B_EMBLEM) {
    return -1;
  }
  sprite = &blk->sprite;
  lit = VM_GetNamedArgValue('s', 0);
  playSound = VM_GetNamedArgValue('S', 1);
  if (lit == 0) {
    if (sprite->poseIdx == 0 || sprite->poseIdx == 2) {
      blk->plttID = OBP_EMBLEM_BLOCK(0);
      Video_SetAuxSpritePltt(&blk->gfx, blk->plttID);
    } else {
      blk->plttID = OBP_EMBLEM_BLOCK(1);
      Video_SetAuxSpritePltt(&blk->gfx, blk->plttID);
    }
  } else {
    if (sprite->poseIdx == 0 || sprite->poseIdx == 2) {
      blk->plttID = OBP_EMBLEM_BLOCK(2);
      Video_SetAuxSpritePltt(&blk->gfx, blk->plttID);
      blk->gfx.pltt = p->savedPltt;
    } else {
      blk->plttID = OBP_EMBLEM_BLOCK(3);
      Video_SetAuxSpritePltt(&blk->gfx, blk->plttID);
      blk->gfx.pltt = p->unk_50;
    }
    p->unk_1f = 1;
    if (playSound) {
      PlaySound_082406e0(SE_329);
    }
  }
}
