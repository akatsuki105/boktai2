#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sprite.h"
#include "vm.h"

extern u32 u32_03002bc0[];  // 0x03002BC0, プレイヤーごとのフラグ

bool8 FUN_082375c8(u32* flags, s32 t, s32 t1, s32 t2);

// プレイヤーの位置をアイソメトリック投影したもの。MapItem_TryAutoPickup が拾える距離の判定に使う
typedef struct {
  s16 x;      // 0x00, (px - pz) * 0x30 >> 8
  s16 y;      // 0x02, ((px + pz) * 0x30 >> 8) - (py * 0x18 >> 8)
  s16 unk_4;  // 0x04, ((px + pz) * 0x30 >> 8) + (py * 0x18 >> 8), このモジュールに読み手がいない
  s16 unk_6;  // 0x06
} PlayerScreenPos;
static_assert(sizeof(PlayerScreenPos) == 8);

struct MapItemManager;

// マップに置かれたアイテム1個。歩いて近づくと拾え (MapItem_TryAutoPickup)、宝箱は調べて開ける (MapItemManager_TryOpen)
typedef struct MapItem {
  ItemCategory16 category;                                  // 0x00, CheckEmptySlotExist の第1引数
  s16 itemID;                                               // 0x02, CheckEmptySlotExist の第2引数
  s8 owner;                                                 // 0x04, 生成時は -1。拾ったプレイヤーの番号が入る
  u8 kind;                                                  // 0x05, 0 = パーティクル表示 (FUN_080070a8), 1 = AuxSprite 表示 (FUN_08007310)
  u8 flags;                                                 // 0x06, bit0 が立つと MapItemManager_Update が解放する
  u8 unk_7;                                                 // 0x07, FUN_08007310 の第4引数。0 以外なら AuxSprite の flags に 4 を立てる
  u8 permanent;                                             // 0x08, 0 以外なら MapItem_UpdateOnGround の 900F の寿命を無視する。FUN_080070a8 の第7引数
  u8 unk_9;                                                 // 0x09, FUN_08007310 の第10引数。点滅させるかどうか
  u8 unk_a;                                                 // 0x0A, MapItemManager_Update の点滅ステート
  u8 blinkTimer;                                            // 0x0B, MapItemManager_Update が減らし、bit3 で表示と非表示を切り替える
  u8 unk_c;                                                 // 0x0C, 点滅のカウンタ。0x30 未満で表示、0x48 で折り返す
  u8 retryDelay;                                            // 0x0D, MapItem_TryAutoPickup で持ちきれなかったとき 0x24
  u8 unk_e;                                                 // 0x0E, MapItem_TryAutoPickup が毎フレーム書く。誰も範囲内にいなければ 1
  u8 shakeTimer;                                            // 0x0F, 0 でない間 MapItem_UpdateShake が pos を揺らす
  s16 shakeBaseX;                                           // 0x10, 揺らし終わりに pos->x へ戻す値
  s16 shakeBaseZ;                                           // 0x12, 同じく pos->z
  u8 unk_14;                                                // 0x14, FUN_080070a8 の第8引数
  u8 unk_15;                                                // 0x15, FUN_08007310 の第11引数。パレットの選択と、サバタが開けられるかの判定に使う
  s16 mapArea;                                              // 0x16, FUN_08241574(pos) の結果。gStat->unk_248 と一致しないと隠す
  u32 stateTimer;                                           // 0x18, update が毎フレーム +1 し、状態が変わると 0 に戻す
  Particle* ptcl;                                           // 0x1C, Malloc(0x28) = sizeof(Particle)
  AuxSprite* sprite;                                        // 0x20, Malloc(0x2C) = sizeof(AuxSprite)
  AuxSpriteGfx* gfx;                                        // 0x24, Malloc(0x1C) = sizeof(AuxSpriteGfx)
  AuxAnimState* anim;                                       // 0x28, Malloc(0x10) = sizeof(AuxAnimState)
  Vec3* pos;                                                // 0x2C, &ptcl->pos または &sprite->pos
  u32 scriptOnOpen;                                         // 0x30, 宝箱を開けたときに走らせる (MapItemManager_TryOpen)
  u32 scriptOnPickup;                                       // 0x34, 歩いて拾ったときに走らせる (MapItem_TryAutoPickup)
  u32 scriptArgs[3];                                        // 0x38, MapItem_ExecScript が argv[5..7] に置く
  void (*update)(struct MapItemManager*, struct MapItem*);  // 0x44, MapItemManager_Update が毎フレーム呼ぶ
  AuxShadow shadow;                                         // 0x48, AuxShadow_Init / AuxShadow_Remove
  struct MapItem* prev;                                     // 0xB4
  struct MapItem* next;                                     // 0xB8
} MapItem;
static_assert(sizeof(MapItem) == 188);

// マップに置かれたアイテムのリストを持ち、毎フレーム各アイテムの update を呼ぶ
typedef struct MapItemManager {
  Entity e;                         // 0x00, ENTITY_UNK_9
  ParticleGroup* particles;         // 0x18, GetParticleGroup(GROUP_0)
  AuxAnimFile* anim;                // 0x1C, GetFile(DIR_ANIMATION, 0x9AF2)
  SpriteID16 spriteID;              // 0x20, SPRITE_MIMIC (このスプライトはミミックと普通の宝箱を兼ねる), Video_GetAuxSprite に渡す
  u16 unk_22;                       // 0x22
  u8 ngDelay;                       // 0x24, MapItemManager_TryOpen が SE_NG を鳴らすと 0xF。Update が減らす
  u8 unk_25[3];                     // 0x25
  MapItem* items;                   // 0x28, 双方向リストの先頭。MapItem_Link が先頭挿入する
  Player* players[4];               // 0x2C, Init / Update が gPlayerPtr を毎フレーム写す
  PlayerScreenPos playerScreen[4];  // 0x3C, players の位置を投影したもの
} MapItemManager;
static_assert(sizeof(MapItemManager) == 92);

void MapItem_UpdateFall(MapItemManager* p, MapItem* item);
void MapItem_UpdateBounce(MapItemManager* p, MapItem* item);
void MapItem_UpdateAppear(MapItemManager* p, MapItem* item);
void MapItem_UpdateOnGround(MapItemManager* p, MapItem* item);
void MapItem_UpdateExpire(MapItemManager* p, MapItem* item);
void MapItem_UpdateIdle(MapItemManager* p, MapItem* item);
void MapItem_UpdateOpen(MapItemManager* p, MapItem* item);
void MapItem_UpdateGive(MapItemManager* p, MapItem* item);
void FUN_08006a80(MapItemManager* p, MapItem* item);
void FUN_08006ba0(MapItemManager* p, MapItem* item);

IWRAM_DATA MapItemManager* gMapItemManager = NULL;  // 0x0300002C

void MapItemManager_ClearGlobal(void) { gMapItemManager = NULL; }

// 拾ったときや開けたときのスクリプトを、位置とアイテムと拾い手を引数にして起動する
NON_MATCH s32 MapItem_ExecScript(MapItem* item, u16 scriptID, s32 param_3) {
#ifdef NONMATCHING_C
  u32 argv[10];
  ScriptArgs args;
  s32 owner;
  s32 i;

  if (scriptID == 0) {
    return -1;
  }
  owner = item->owner;
  if (owner == -1 || (u32_03002bc0[owner] & 0xC) != 0) {
    return -1;
  }
  if (item->kind == 1) {
    argv[0] = item->pos->x;
    argv[1] = item->pos->y + 0x40;
  } else {
    argv[0] = item->pos->x;
    argv[1] = item->pos->y;
  }
  argv[2] = item->pos->z;
  argv[3] = item->category;
  argv[4] = item->itemID;
  for (i = 0; i < 3; i++) {
    argv[5 + i] = item->scriptArgs[i];
  }
  argv[8] = owner;
  argv[9] = param_3;
  args.argc = 10, args.argv = argv;
  return Script_ExecById(scriptID, &args);
#else
  INCFUNC("asm/func/MapItem_ExecScript.inc");
#endif
}

// リストの先頭に挿す
s32 MapItem_Link(MapItem* item) {
  item->prev = NULL;
  item->next = gMapItemManager->items;
  if (item->next != NULL) {
    item->next->prev = item;
  }
  gMapItemManager->items = item;
  return 0;
}

// リストから外す
s32 MapItem_Unlink(MapItem* item) {
  MapItem* prev = item->prev;
  MapItem* next = item->next;

  if (prev != NULL) {
    prev->next = next;
  } else {
    gMapItemManager->items = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  return 0;
}

// リストから外して、確保したものを全部返す
s32 MapItem_Free(MapItem* item) {
  MapItem_Unlink(item);
  AuxShadow_Remove(&item->shadow);
  if (item->gfx != NULL) {
    Free(item->gfx);
  }
  if (item->anim != NULL) {
    Free(item->anim);
  }
  if (item->ptcl != NULL) {
    Particle_Remove(item->ptcl);
    Free(item->ptcl);
  }
  if (item->sprite != NULL) {
    AuxSprite_Remove(item->sprite);
    Free(item->sprite);
  }
  Free(item);
  return 0;
}

NON_MATCH void MapItem_UpdateShake(MapItem* item) {
#ifdef NONMATCHING_C
  if (item->shakeTimer != 0) {
    item->shakeTimer--;
    if (item->shakeTimer == 0) {
      item->pos->x = item->shakeBaseX;
      item->pos->z = item->shakeBaseZ;
    } else {
      gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
      item->pos->x = (gRandomTable[gRandTableIdx] & 0xF) + item->shakeBaseX - 4;
      gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
      item->pos->z = (gRandomTable[gRandTableIdx] & 7) + item->shakeBaseZ - 4;
    }
  }
#else
  INCFUNC("asm/func/MapItem_UpdateShake.inc");
#endif
}

NAKED s32 MapItem_TryAutoPickup(MapItemManager* p, MapItem* item) { INCFUNC("asm/func/MapItem_TryAutoPickup.inc"); }

NAKED bool32 MapItemManager_TryOpen(unknown* param_1) { INCFUNC("asm/func/MapItemManager_TryOpen.inc"); }

// 当たり判定マップの地面まで落ちる。着地したら跳ねる状態へ移る
void MapItem_UpdateFall(MapItemManager* p, MapItem* item) {
  s32 y = item->pos->y;
  Vec3* pos = item->pos;
  s32 bx = pos->x >> 8;
  s32 bz = pos->z >> 8;
  u32 idx;
  u8* tile;
  s32 ground;
  s32 stairs;
  s32 d;

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
  ground = (*tile & 0xF) << 8;
  switch (stairs) {
    case 1: {
      ground -= (u8)pos->z;
      break;
    }
    case 2: {
      ground -= (u8)pos->x;
      break;
    }
  }
  d = y - ground;
  if (d > 0) {
    Vec3* q = item->pos;
    s32 n = d;

    if (n > 0x20) {
      n = 0x20;
    }
    q->y -= n;
    MapItem_TryAutoPickup(p, item);
    item->stateTimer++;
  } else {
    item->pos->y = ground + 1;
    item->update = MapItem_UpdateBounce;
    item->stateTimer = 0;
  }
}

// 着地したあと一度だけ跳ねる。跳ね終わりに影を消して待機状態へ移る
void MapItem_UpdateBounce(MapItemManager* p, MapItem* item) {
  Vec3* pos = item->pos;
  s32 bx = pos->x >> 8;
  s32 bz = pos->z >> 8;
  u32 idx;
  u8* tile;
  s32 ground;
  s32 stairs;

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
  ground = (*tile & 0xF) << 8;
  switch (stairs) {
    case 1: {
      ground -= (u8)pos->z;
      break;
    }
    case 2: {
      ground -= (u8)pos->x;
      break;
    }
  }
  if (item->stateTimer <= 2) {
    item->pos->y += 8;
  } else if (item->stateTimer > 5) {
    item->update = MapItem_UpdateOnGround;
    item->stateTimer = 0;
    item->pos->y = ground + 1;
    AuxShadow_Hide(&item->shadow);
    return;
  } else {
    item->pos->y -= 8;
  }
  MapItem_UpdateShake(item);
  MapItem_TryAutoPickup(p, item);
  item->stateTimer++;
}

NAKED void MapItem_UpdateAppear(MapItemManager* p, MapItem* item) { INCFUNC("asm/func/MapItem_UpdateAppear.inc"); }

// 地面で揺れながら拾われるのを待つ。900F 経つか、タイルに上書きが入ると消えにいく
void MapItem_UpdateOnGround(MapItemManager* p, MapItem* item) {
  if (item->permanent == 0 && item->stateTimer > 899) {
    item->update = MapItem_UpdateExpire;
    item->stateTimer = 0;
    return;
  }
  if ((item->stateTimer & 0xF) == 0xF) {
    Vec3* pos = item->pos;
    s32 bx = pos->x >> 8;
    s32 bz = pos->z >> 8;
    u32 idx;

    if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
      idx = 0;
    } else {
      idx = gCollisionMap->rowOffsets[bz] + bx;
    }
    if (FUN_08234224(idx, 1) != NULL) {
      item->stateTimer = 900;
    }
  }
  MapItem_UpdateShake(item);
  MapItem_TryAutoPickup(p, item);
  item->stateTimer++;
}

// 45F 経ったら点滅を始め、90F を過ぎたら自分を消す
void MapItem_UpdateExpire(MapItemManager* p, MapItem* item) {
  if (FUN_082375c8(&item->ptcl->flags, item->stateTimer, 45, 90)) {
    item->flags |= 1;
  } else {
    MapItem_TryAutoPickup(p, item);
  }
  item->stateTimer++;
}

#ifdef NONMATCHING_C
// AuxSprite のアニメーションを1コマ進める
static inline void MapItem_AdvanceAnim(MapItem* item) {
  AuxSprite* sprite = item->sprite;
  AuxAnimState* anim = item->anim;
  AuxAnimCmd* cmd = &anim->cmds[anim->cmdIdx];

  sprite->metaspriteIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) == (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    sprite->flags &= ~SPRFLAG_XFLIP;
  } else {
    sprite->flags |= SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) == (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    sprite->flags &= ~SPRFLAG_YFLIP;
  } else {
    sprite->flags |= SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount;
      }
      anim->cmdIdx--;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
      }
    }
    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = (anim->duration * anim->speed) >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }
}
#endif

NON_MATCH void MapItem_UpdateIdle(MapItemManager* p, MapItem* item) {
#ifdef NONMATCHING_C
  MapItem_AdvanceAnim(item);
  if (item->unk_7 != 0) {
    item->sprite->flags |= SPRFLAG_XFLIP;
  }
  item->stateTimer++;
#else
  INCFUNC("asm/func/MapItem_UpdateIdle.inc");
#endif
}

NAKED void MapItem_UpdateOpen(MapItemManager* p, MapItem* item) { INCFUNC("asm/func/MapItem_UpdateOpen.inc"); }

NAKED void MapItem_UpdateGive(MapItemManager* p, MapItem* item) { INCFUNC("asm/func/MapItem_UpdateGive.inc"); }

NAKED void FUN_08006a80(MapItemManager* p, MapItem* item) { INCFUNC("asm/func/FUN_08006a80.inc"); }

NAKED void FUN_08006ba0(MapItemManager* p, MapItem* item) { INCFUNC("asm/func/FUN_08006ba0.inc"); }

NAKED s32 MapItemManager_Update(MapItemManager* p) { INCFUNC("asm/func/MapItemManager_Update.inc"); }

s32 MapItemManager_Destroy(MapItemManager* p) {
  MapItem* item;
  MapItem* next;

  for (item = p->items; item != NULL; item = next) {
    next = item->next;
    MapItem_Free(item);
  }
  gMapItemManager = NULL;
  return 0;
}

NON_MATCH s32 MapItemManager_Init(MapItemManager* p, u32 param_2) {
#ifdef NONMATCHING_C
  s32 i;

  gMapItemManager = p;
  p->particles = GetParticleGroup(PTCL_GROUP_0);
  p->spriteID = SPRITE_MIMIC;
  p->anim = GetFile(DIR_ANIMATION, 0x9AF2);
  p->items = NULL;
  for (i = 0; i < 4; i++) {
    Player* player = gPlayerPtr[i];

    p->players[i] = player;
    if (player != NULL) {
      s32 x = player->unk_24.pos.x >> 1;
      s32 z = player->unk_24.pos.z >> 1;
      s32 depth = (x + z) * 48 / 256;
      s32 height = player->unk_24.pos.y * 24 / 256;

      p->playerScreen[i].x = (x - z) * 48 / 256;
      p->playerScreen[i].y = depth - height;
      p->playerScreen[i].unk_4 = depth + height;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/MapItemManager_Init.inc");
#endif
}

MapItemManager* MapItemManager_Create(u32 param_1, u32 param_2) {
  MapItemManager* p = CreateEntity(ENTITY_UNK_9, sizeof(MapItemManager));

  if (p != NULL) {
    SetEntityRoutine(p, MapItemManager_Update, MapItemManager_Destroy);
    if (MapItemManager_Init(p, param_1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// まだ無ければ作る
MapItemManager* MapItemManager_Ensure(void) {
  MapItemManager* p = gMapItemManager;

  if (p == NULL) {
    p = MapItemManager_Create(0, 0);
  }
  return p;
}

INCASM("asm/map_item.inc");
