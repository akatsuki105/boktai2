#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "inline.h"
#include "malloc.h"
#include "map_inline.h"
#include "mover.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// プレイヤーの位置をアイソメトリック投影したもの, MapItem_TryAutoPickup が拾える距離の判定に使う
typedef struct {
  s16 x;      // 0x00, (px - pz) * 0x30 >> 8
  s16 y;      // 0x02, ((px + pz) * 0x30 >> 8) - (py * 0x18 >> 8)
  s16 unk_4;  // 0x04, ((px + pz) * 0x30 >> 8) + (py * 0x18 >> 8), このモジュールに読み手がいない
  s16 unk_6;  // 0x06
} PlayerScreenPos;
static_assert(sizeof(PlayerScreenPos) == 8);

struct MapItemManager;

// マップに置かれたアイテム1個, 歩いて近づくと拾え (MapItem_TryAutoPickup)、宝箱は調べて開ける (MapItemManager_TryOpen)
typedef struct MapItem {
  ItemCategory16 category;                                  // 0x00, CheckEmptySlotExist の第1引数
  s16 itemID;                                               // 0x02, CheckEmptySlotExist の第2引数
  s8 owner;                                                 // 0x04, 生成時は -1, 拾ったプレイヤーの番号が入る
  u8 kind;                                                  // 0x05, 0 = パーティクル表示 (FUN_080070a8), 1 = AuxSprite 表示 (FUN_08007310)
  u8 flags;                                                 // 0x06, bit0 が立つと MapItemManager_Update が解放する
  u8 unk_7;                                                 // 0x07, FUN_08007310 の第4引数, 0 以外なら AuxSprite の flags に 4 を立てる
  u8 permanent;                                             // 0x08, 0 以外なら MapItem_UpdateOnGround の 900F の寿命を無視する, FUN_080070a8 の第7引数
  u8 unk_9;                                                 // 0x09, FUN_08007310 の第10引数, 点滅させるかどうか
  u8 unk_a;                                                 // 0x0A, MapItemManager_Update の点滅ステート
  u8 blinkTimer;                                            // 0x0B, MapItemManager_Update が減らし、bit3 で表示と非表示を切り替える
  u8 unk_c;                                                 // 0x0C, 点滅のカウンタ, 0x30 未満で表示、0x48 で折り返す
  u8 retryDelay;                                            // 0x0D, MapItem_TryAutoPickup で持ちきれなかったとき 0x24
  u8 unk_e;                                                 // 0x0E, MapItem_TryAutoPickup が毎フレーム書く, 誰も範囲内にいなければ 1
  u8 shakeTimer;                                            // 0x0F, 0 でない間 MapItem_UpdateShake が pos を揺らす
  s16 shakeBaseX;                                           // 0x10, 揺らし終わりに pos->x へ戻す値
  s16 shakeBaseZ;                                           // 0x12, 同じく pos->z
  u8 unk_14;                                                // 0x14, FUN_080070a8 の第8引数
  u8 unk_15;                                                // 0x15, FUN_08007310 の第11引数, パレットの選択と、サバタが開けられるかの判定に使う
  ZoneID16s zoneID;                                         // 0x16, GetZoneAt(pos) の結果, gStat->zoneID と一致しないと隠す
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
  ParticleGroup* particles;         // 0x18, PTCL_GROUP_0
  AuxAnimFile* anim;                // 0x1C, ANIM_MIMIC
  SpriteID16 spriteID;              // 0x20, SPRITE_MIMIC (このスプライトはミミックと普通の宝箱を兼ねる)
  u16 unk_22;                       // 0x22
  u8 ngDelay;                       // 0x24, MapItemManager_TryOpen が SE_NG を鳴らすと 0xF, Update が減らす
  u8 unk_25[3];                     // 0x25
  MapItem* items;                   // 0x28, 双方向リストの先頭, MapItem_Link が先頭挿入する
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
bool32 CheckEmptySlotExist(ItemCategory32 category, item32_t itemID);
s32 FUN_082342cc(Vec3* pos, s32 limit);

extern s32 gLightningTimer;
s32 ItemIconPopupManager_AddIcon(s32 category, item32_t itemID, u32 kind, u32 playerIdx, Vec3* pos, Vec3* destPos, u32 duration, u32 key);

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
  if (owner == -1 || (gPlayerStates[owner] & (FLAG03002BC0_UNK_3 | FLAG03002BC0_UNK_2))) {
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
  return VM_ExecByID(scriptID, &args);
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
      u16* table = gRandomTable;
      item->pos->x = item->shakeBaseX + ((_Random(table) % 16) - 4);
      item->pos->z = item->shakeBaseZ + ((_Random(table) % 8) - 4);
    }
  }
#else
  INCFUNC("asm/func/MapItem_UpdateShake.inc");
#endif
}

// 近くにいるプレイヤーに袋アイテムを拾わせる, 画面に投影した距離で判定し, 持ちきれなければアイコンを出して揺らし 36 フレーム待つ
// 残差は 269/271, ほぼレジスタ割り当て, 原典は p を sl, i を r8, &vp を sb に置き playerScreen[i] のアドレスを先に作る
// Tier A-C 試済 (WorldToVp, players[i] のローカル, TEST_FLAGS), 未: playerScreen[i] のポインタ
NON_MATCH s32 MapItem_TryAutoPickup(MapItemManager* p, MapItem* item) {
#ifdef NONMATCHING_C
  Vec3 vp;
  bool32 nobody;
  u32 i;

  WorldToVp(&vp, item->pos);
  if (item->retryDelay != 0 && --item->retryDelay == 0) {
    item->shakeTimer = 4;
    item->shakeBaseX = item->pos->x;
    item->shakeBaseZ = item->pos->z;
  }

  nobody = TRUE;
  for (i = 0; i < 4; i++) {
    Player* player = p->players[i];

    if (player != NULL && !TEST_FLAGS(gPlayerStates[i], FLAG03002BC0_UNK_3 | FLAG03002BC0_UNK_2)) {
      Vec3* pos = item->pos;
      s32 dy = vp.y - p->playerScreen[i].y;
      bool32 near;

      if (abs(pos->y - player->mover.pos.y) < 0x80 && abs(vp.x - p->playerScreen[i].x) <= 14 && dy >= -24 && dy <= 4) {
        near = TRUE;
      } else {
        near = FALSE;
      }
      if (near) {
        Vec3 iconPos = *pos;

        iconPos.y += 0x80;
        if ((gGameFlags & FLAG030047A4_LINK) || CheckEmptySlotExist(item->category, item->itemID)) {
          item->owner = i;
          if (item->category < 4) {
            ItemIconPopupManager_AddIcon(item->category, item->itemID, 0, i, &iconPos, &iconPos, 24, (u32)item);
          }
          if (!(gGameFlags & FLAG030047A4_LINK)) {
            PlaySound_0824078c(SE_PICKUP);
          }
          MapItem_ExecScript(item, item->scriptOnPickup, (gGameFlags & FLAG030047A4_LINK) || CheckEmptySlotExist(item->category, item->itemID) == TRUE);
          item->flags |= 1;
          break;
        }
        if (item->unk_e && item->retryDelay == 0) {
          if (item->category < 4) {
            ItemIconPopupManager_AddIcon(item->category, item->itemID, 1, i, &iconPos, &iconPos, 24, (u32)item);
            PlaySound_0824078c(SE_PICKUP);
          }
          item->retryDelay = 36;
          item->shakeTimer = 4;
          item->shakeBaseX = item->pos->x;
          item->shakeBaseZ = item->pos->z;
        }
        nobody = FALSE;
      }
    }
  }
  item->unk_e = nobody;
#else
  INCFUNC("asm/func/MapItem_TryAutoPickup.inc");
#endif
}

// 宝箱を開けられるか
// mover の近く (横 0x60 / 高さ 0x80 未満) にある未開封の宝箱を開ける, サバタは unk_15 が 1 の宝箱を開けられず NG 音を鳴らす
// 残差は 2 命令 (144/142), 原典はループの次へ進む処理を NG 分岐の直後に置き宝箱を開ける処理をその後ろに置く, 範囲判定は 0/1 を作ってから比べる
// Tier A-C 試済: 範囲判定を bool32 を返す static inline (pos, opener) にすると prologue と r8 / r9 まで揃う (inline は一致しないので外した), flags の判定を分ける, NG 分岐を先 / continue
NON_MATCH bool8 MapItemManager_TryOpen(Mover* mover) {
#ifdef NONMATCHING_C
  MapItemManager* p = gMapItemManager;
  MapItem* item;
  u8 playerIdx;

  if (gMapItemManager == NULL) {
    return FALSE;
  }

  playerIdx = mover->unk_4;
  for (item = gMapItemManager->items; item != NULL; item = item->next) {
    if (item->flags & 1) {
      continue;
    }
    if (item->owner == -1 && item->kind == 1) {
      Vec3* pos = item->pos;

      if (abs(pos->x - mover->pos.x) < 0x60 && abs(pos->y - mover->pos.y) < 0x80 && abs(pos->z - mover->pos.z) < 0x60) {
        if (gPlayerPtr[playerIdx] != NULL && gPlayerPtr[playerIdx]->kind == PLAYER_SABATA && item->unk_15 == 1) {
          if (p->ngDelay == 0) {
            PlaySound_082406e0(SE_NG);
            p->ngDelay = 15;
          }
          continue;
        }
        item->owner = playerIdx;
        PlaySound_0824078c(SE_OPEN_TREASURE);
        item->update = MapItem_UpdateOpen;
        item->stateTimer = 0;
        item->unk_9 = 0;
        AuxAnim_SetAnim(item->anim, p->anim, 5, 0, 0);
        MapItem_ExecScript(item, item->scriptOnOpen, (gGameFlags & FLAG030047A4_LINK) || CheckEmptySlotExist(item->category, item->itemID) == TRUE);
        return TRUE;
      }
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/MapItemManager_TryOpen.inc");
#endif
}

// 当たり判定マップの地面まで落ちる, 着地したら跳ねる状態へ移る
void MapItem_UpdateFall(MapItemManager* p, MapItem* item) {
  s32 y = item->pos->y;
  s32 ground = TileHeightAt(item->pos);
  s32 d = y - ground;

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

// 着地したあと一度だけ跳ねる, 跳ね終わりに影を消して待機状態へ移る
void MapItem_UpdateBounce(MapItemManager* p, MapItem* item) {
  s32 ground = TileHeightAt(item->pos);

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

// 宝箱が出てくるときの演出, アニメを1コマ進めながら4フレーム上がって4フレーム下がり, 待機 (MapItem_UpdateIdle) に移る
void MapItem_UpdateAppear(MapItemManager* p, MapItem* item) {
  AuxSprite_AdvanceAnim(item->sprite, item->anim);
  if (item->unk_7 != 0) {
    item->sprite->flags |= SPRFLAG_XFLIP;
  }
  if (item->stateTimer <= 3) {
    item->pos->y += 8;
  } else if (item->stateTimer > 7) {
    item->update = MapItem_UpdateIdle;
    item->stateTimer = 0;
    return;
  } else {
    item->pos->y -= 8;
  }
  item->stateTimer++;
}

// 地面で揺れながら拾われるのを待つ, 900F 経つか、タイルに上書きが入ると消えにいく
void MapItem_UpdateOnGround(MapItemManager* p, MapItem* item) {
  if (item->permanent == 0 && item->stateTimer > 899) {
    item->update = MapItem_UpdateExpire;
    item->stateTimer = 0;
    return;
  }
  if ((item->stateTimer & 0xF) == 0xF) {
    if (Map_FindTileOverride(GetCollisionTileIdx(item->pos), 1) != NULL) {
      item->stateTimer = 900;
    }
  }
  MapItem_UpdateShake(item);
  MapItem_TryAutoPickup(p, item);
  item->stateTimer++;
}

// 45F 経ったら点滅を始め、90F を過ぎたら自分を消す
void MapItem_UpdateExpire(MapItemManager* p, MapItem* item) {
  if (Sprite_UpdateVanishBlink(&item->ptcl->flags, item->stateTimer, 45, 90)) {
    item->flags |= 1;
  } else {
    MapItem_TryAutoPickup(p, item);
  }
  item->stateTimer++;
}

// 待機中, AuxSprite のアニメを1コマ進め, unk_7 なら左右反転させる
void MapItem_UpdateIdle(MapItemManager* p, MapItem* item) {
  AuxSprite_AdvanceAnim(item->sprite, item->anim);
  if (item->unk_7 != 0) {
    item->sprite->flags |= SPRFLAG_XFLIP;
  }
  item->stateTimer++;
}

// 宝箱が開くアニメを流し, 開ききったら中身のアイコンを出す, 持ちきれなければ FUN_08006a80 (閉じ直す) へ, 持てれば MapItem_UpdateGive へ移る
void MapItem_UpdateOpen(MapItemManager* p, MapItem* item) {
  bool32 done = AuxSprite_AdvanceAnim(item->sprite, item->anim);

  if (item->unk_7 != 0) {
    item->sprite->flags |= SPRFLAG_XFLIP;
  }
  if (done) {
    Vec3 pos = *item->pos;

    pos.y += 0x80;
    if (!(gGameFlags & FLAG030047A4_LINK) && !CheckEmptySlotExist(item->category, item->itemID)) {
      if (item->category < 4) {
        ItemIconPopupManager_AddIcon(item->category, item->itemID, 1, item->owner, &pos, &pos, 24, (u32)item);
      }
      item->update = FUN_08006a80;
    } else {
      if (item->category < 4) {
        ItemIconPopupManager_AddIcon(item->category, item->itemID, 0, item->owner, &pos, &pos, 24, (u32)item);
      }
      item->update = MapItem_UpdateGive;
    }
    item->stateTimer = 0;
    AuxAnim_SetAnim(item->anim, gMapItemManager->anim, 6, 0, 0);
  } else {
    item->stateTimer++;
  }
}

// 宝箱の中身を渡す, アニメを進め 8 フレーム目に拾った音と拾ったときのスクリプトを出し, その後点滅して消える
void MapItem_UpdateGive(MapItemManager* p, MapItem* item) {
  AuxSprite_AdvanceAnim(item->sprite, item->anim);
  if (item->unk_7 != 0) {
    item->sprite->flags |= SPRFLAG_XFLIP;
  }
  if (item->stateTimer == 8) {
    if (!(gGameFlags & FLAG030047A4_LINK)) {
      PlaySound_0824078c(SE_PICKUP);
    }
    MapItem_ExecScript(item, item->scriptOnPickup, CheckEmptySlotExist(item->category, item->itemID) == TRUE);
  } else if (item->stateTimer > 8 && Sprite_UpdateVanishBlink(&item->sprite->flags, item->stateTimer, 30, 90)) {
    item->flags |= 1;
  }
  item->stateTimer++;
}

// 宝箱の開いたまま (アニメ 5 を進める) を 32 フレーム続け, 閉じるアニメ (5 の逆再生) で FUN_08006ba0 に移る
void FUN_08006a80(MapItemManager* p, MapItem* item) {
  AuxSprite_AdvanceAnim(item->sprite, item->anim);
  if (item->unk_7 != 0) {
    item->sprite->flags |= SPRFLAG_XFLIP;
  }
  if (item->stateTimer > 31) {
    item->update = FUN_08006ba0;
    item->stateTimer = 0;
    AuxAnim_SetAnim(item->anim, gMapItemManager->anim, 5, 0, ANIM_PLAY_REVERSE);
  }
  item->stateTimer++;
}

// 宝箱が閉じるアニメを流し, 閉じきったら持ち主を外して待機 (MapItem_UpdateIdle) に戻す
void FUN_08006ba0(MapItemManager* p, MapItem* item) {
  bool32 done = AuxSprite_AdvanceAnim(item->sprite, item->anim);

  if (item->unk_7 != 0) {
    item->sprite->flags |= SPRFLAG_XFLIP;
  }
  if (done) {
    item->update = MapItem_UpdateIdle;
    item->stateTimer = 0;
    item->owner = -1;
    AuxAnim_SetAnim(item->anim, p->anim, 0, 0, 0);
  } else {
    item->stateTimer++;
  }
}

// プレイヤーの位置を画面に投影して控え, 置きアイテムごとに解放 / ゾーン外の非表示 / 隠し宝箱の点滅を処理して update を呼ぶ
// 残差は 281/297 (初稿のみ), 先頭の投影ループの組み方 (原典は playerScreen[i] のアドレスと gPlayerPtr を先に作る) と, 隠し宝箱の点滅の分岐の並び
// Tier A-C は未着手, 千里眼の判定は FUN_08007310 と同じ形
NON_MATCH s32 MapItemManager_Update(MapItemManager* p) {
#ifdef NONMATCHING_C
  MapItem* item;
  s32 i;

  for (i = 0; i < 4; i++) {
    Player* player = gPlayerPtr[i];

    p->players[i] = player;
    if (player != NULL) {
      s32 hx = player->mover.pos.x >> 1;
      s32 hz = player->mover.pos.z >> 1;
      s32 a, b;

      p->playerScreen[i].x = FixToInt(8, (hx - hz) * 48);
      a = FixToInt(8, (hx + hz) * 48);
      b = FixToInt(8, player->mover.pos.y * 24);
      p->playerScreen[i].y = a - b;
      p->playerScreen[i].unk_4 = a + b;
    }
  }

  item = p->items;
  while (item != NULL) {
    MapItem* next = item->next;
    AuxSprite* sprite;

    if (item->flags & 1) {
      MapItem_Free(item);
      item = next;
      continue;
    }

    if (item->zoneID == 0 || gStat->zoneID == item->zoneID) {
      if (item->ptcl != NULL) {
        item->ptcl->flags &= ~SPRFLAG_HIDDEN;
      }
      sprite = item->sprite;
      if (sprite != NULL) {
        if (item->unk_9 == 0) {
          sprite->flags &= ~SPRFLAG_HIDDEN;
        } else if (gLightningTimer > 0) {
          sprite->flags &= ~SPRFLAG_HIDDEN;
          item->blinkTimer = 0;
          item->unk_c = 0;
          item->unk_a = 1;
        } else {
          bool32 unseen;

          if (gGameFlags & FLAG030047A4_LINK) {
            unseen = !(gPlayerPtr[0] != NULL && gPlayerPtr[0]->goodCondTimer != 0 && gPlayerPtr[0]->goodCondID == GOOD_SEE);
          } else if (gStat->playerKind != 2) {
            unseen = !(gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE);
          } else {
            unseen = FALSE;
          }
          if (unseen) {
            if (item->unk_a == 0) {
              item->blinkTimer = 47;
            }
            if (item->blinkTimer != 0) {
              item->blinkTimer--;
              if ((item->blinkTimer & 0xF) < 8) {
                sprite->flags &= ~SPRFLAG_HIDDEN;
              } else {
                sprite->flags |= SPRFLAG_HIDDEN;
              }
              item->unk_c = 0;
            } else {
              sprite->flags |= SPRFLAG_HIDDEN;
            }
            item->unk_a = 1;
          } else {
            if (item->unk_a != 0) {
              item->blinkTimer = 31;
            }
            if (item->blinkTimer == 0) {
              if (item->unk_c < 0x30) {
                sprite->flags &= ~SPRFLAG_HIDDEN;
              } else if (item->unk_c < 0x48) {
                sprite->flags |= SPRFLAG_HIDDEN;
              } else {
                item->unk_c = 0;
              }
              item->unk_c++;
            } else {
              item->blinkTimer--;
              if ((item->blinkTimer & 0xF) < 8) {
                sprite->flags |= SPRFLAG_HIDDEN;
              } else {
                sprite->flags &= ~SPRFLAG_HIDDEN;
              }
            }
            item->unk_a = 0;
          }
        }
      }
    } else {
      if (item->ptcl != NULL) {
        item->ptcl->flags |= SPRFLAG_HIDDEN;
      }
      if (item->sprite != NULL) {
        item->sprite->flags |= SPRFLAG_HIDDEN;
      }
    }
    item->update(p, item);
    item = next;
  }

  if (p->ngDelay != 0) {
    p->ngDelay--;
  }
  return 0;
#else
  INCFUNC("asm/func/MapItemManager_Update.inc");
#endif
}

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
  p->anim = GetFile(DIR_ANIMATION, ANIM_MIMIC);
  p->items = NULL;
  for (i = 0; i < 4; i++) {
    Player* player = gPlayerPtr[i];

    p->players[i] = player;
    if (player != NULL) {
      s32 x = player->mover.pos.x >> 1;
      s32 z = player->mover.pos.z >> 1;
      s32 depth = (x + z) * 48 / 256;
      s32 height = player->mover.pos.y * 24 / 256;

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

// pos に袋アイテム (パーティクル表示, kind 0) を置いて落とし始める, 高い所なら別の絵と前面の優先度にする
s32 FUN_080070a8(WorldPos* pos, s32 category, s32 itemID, u32 scriptOnPickup, u32* scriptArgs, s32 useZone, s32 permanent, s32 param_8) {
  MapItemManager* m = MapItemManager_Ensure();
  MapItem* item;
  s32 i;

  if (m == NULL) {
    return -1;
  }
  item = Malloc(sizeof(MapItem));
  if (item == NULL) {
    return -1;
  }
  ClearMemory(item, sizeof(MapItem));
  item->category = category;
  item->itemID = itemID;
  item->owner = -1;
  item->kind = 0;
  item->flags = 0;
  item->unk_7 = 0;
  item->stateTimer = 0;
  item->ptcl = NULL;
  item->sprite = NULL;
  item->gfx = NULL;
  item->anim = NULL;
  item->update = MapItem_UpdateFall;
  item->unk_c = 0;
  item->unk_14 = param_8;
  item->scriptOnPickup = scriptOnPickup;
  for (i = 0; i < 3; i++) {
    item->scriptArgs[i] = scriptArgs[i];
  }
  item->ptcl = Malloc(sizeof(Particle));
  if (item->ptcl == NULL) {
    Free(item);
    return -1;
  }
  ClearMemory(item->ptcl, sizeof(Particle));
  Particle_Add(item->ptcl, m->particles, 0);
  Particle_SetOffset(item->ptcl, -8, -10);
  if (FUN_082342cc(pos, 0x80)) {
    item->ptcl->tileNum = m->particles->tile + (item->ptcl->spriteWidth >> 3) * (item->ptcl->spriteHeight >> 3) * 35;
    item->ptcl->priority = 1;
  } else {
    item->ptcl->tileNum = m->particles->tile + (item->ptcl->spriteWidth >> 3) * (item->ptcl->spriteHeight >> 3) * 32;
    item->ptcl->priority = 2;
  }
  item->ptcl->pos = *pos;
  item->ptcl->offsetZ = 16;
  item->pos = &item->ptcl->pos;
  if (useZone) {
    item->zoneID = GetZoneAt(item->pos);
  } else {
    item->zoneID = 0;
  }
  item->permanent = permanent;
  AuxShadow_Init(&item->shadow, &item->ptcl->pos, 64, 24, 40, 32, 512, 1, 5, 1, 0);
  MapItem_Link(item);
  return 0;
}

// '.s' の位置に '.I' (種類, ID) のアイテムを置く, 拾ったときのスクリプトは '.p' で引数は '.a' から最大3個
s32 Cmd_0955(void) {
  WorldPos pos;
  s32 category, itemID;
  u32 scriptOnPickup;
  s32 m, permanent, o;
  u32 args[3];
  s32 i;

  if (VM_SeekToNamedArg('s')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  if (VM_SeekToNamedArg('I')) {
    category = VM_GetValue();
    itemID = VM_GetValue();
  } else {
    category = 0;
    itemID = 0;
  }
  scriptOnPickup = VM_GetNamedArgValue('p', 0);
  m = VM_GetNamedArgValue('M', 0);
  permanent = VM_GetNamedArgValue('i', 0);
  o = VM_GetNamedArgValue('O', 0);
  for (i = 0; i < 3; i++) {
    args[i] = 0;
  }
  if (VM_SeekToNamedArg('a')) {
    for (i = 0; VM_GetPC() != NULL && i < 3; i++) {
      args[i] = VM_GetValue();
    }
  }
  return FUN_080070a8(&pos, category, itemID, scriptOnPickup, args, m, permanent, o);
}

// pos に宝箱 (AuxSprite 表示, kind 1) を置く, hidden なら隠し宝箱にして千里眼などで見えないときは点滅させる, 確保に失敗したら確保した分を解放して -1
// 残差は 335/339, 千里眼の判定を 0/1 に作ってから合流させる部分と, その前後のレジスタ (r2 / r3 / r4)
// Tier A-C 試済 (param_11 の (u8) 比較, LINK 側を先に書く, see を1つに集める形は 332 に悪化), 未: 千里眼判定の static inline 化
NON_MATCH s32 FUN_08007310(WorldPos* pos, s32 category, s32 itemID, s32 xflip, s32 appear, u32 scriptOnOpen, u32 scriptOnPickup, u32* scriptArgs, s32 useZone, s32 hidden, s32 param_11) {
#ifdef NONMATCHING_C
  MapItemManager* m = MapItemManager_Ensure();
  MapItem* item;
  s32 i;
  u8 hiddenBlink;

  if (m == NULL) {
    return -1;
  }
  item = Malloc(sizeof(MapItem));
  if (item == NULL) {
    return -1;
  }
  ClearMemory(item, sizeof(MapItem));
  item->category = category;
  item->itemID = itemID;
  item->owner = -1;
  item->kind = 1;
  item->flags = 0;
  item->unk_7 = xflip;
  item->stateTimer = 0;
  item->ptcl = NULL;
  item->sprite = NULL;
  item->gfx = NULL;
  item->anim = NULL;
  if (appear) {
    item->update = MapItem_UpdateAppear;
    if (!(gGameFlags & FLAG030047A4_LINK)) {
      PlaySound_082406e0(SONG_623);
    }
  } else {
    item->update = MapItem_UpdateIdle;
  }
  item->scriptOnOpen = scriptOnOpen;
  item->scriptOnPickup = scriptOnPickup;
  for (i = 0; i < 3; i++) {
    item->scriptArgs[i] = scriptArgs[i];
  }

  item->sprite = Malloc(sizeof(AuxSprite));
  if (item->sprite == NULL) {
    Free(item);
    return -1;
  }
  ClearMemory(item->sprite, sizeof(AuxSprite));
  item->gfx = Malloc(sizeof(AuxSpriteGfx));
  if (item->gfx == NULL) {
    if (item->sprite != NULL) {
      Free(item->sprite);
    }
    Free(item);
    return -1;
  }
  ClearMemory(item->gfx, sizeof(AuxSpriteGfx));
  item->anim = Malloc(sizeof(AuxAnimState));
  if (item->anim == NULL) {
    if (item->sprite != NULL) {
      Free(item->sprite);
    }
    if (item->gfx != NULL) {
      Free(item->gfx);
    }
    Free(item);
    return -1;
  }
  ClearMemory(item->anim, sizeof(AuxAnimState));
  if (!Video_GetAuxSprite(item->gfx, m->spriteID)) {
    if (item->sprite != NULL) {
      Free(item->sprite);
    }
    if (item->gfx != NULL) {
      Free(item->gfx);
    }
    if (item->anim != NULL) {
      Free(item->anim);
    }
    Free(item);
    return -1;
  }

  AuxSprite_Add(item->sprite, item->gfx, 0);
  item->sprite->pos = *pos;
  item->sprite->pos.y = TileHeightAt(&item->sprite->pos);
  if (item->unk_7 != 0) {
    item->sprite->flags |= SPRFLAG_XFLIP;
  }
  item->pos = &item->sprite->pos;
  item->unk_9 = hidden;
  item->unk_15 = param_11;
  if ((u8)param_11 == 0) {
    Video_SetAuxSpritePltt(item->gfx, 650);
  } else if ((u8)param_11 == 1) {
    Video_SetAuxSpritePltt(item->gfx, 653);
  } else {
    Video_SetAuxSpritePltt(item->gfx, 654);
  }
  hiddenBlink = 0;
  if (item->unk_9 != 0) {
    item->sprite->flags |= SPRFLAG_HIDDEN;
    if (gGameFlags & FLAG030047A4_LINK) {
      bool32 see = gPlayerPtr[0] != NULL && gPlayerPtr[0]->goodCondTimer != 0 && gPlayerPtr[0]->goodCondID == GOOD_SEE;
      if (!see) {
        hiddenBlink = 1;
      }
    } else if (gLightningTimer <= 0 && gStat->playerKind != 2) {
      bool32 see = gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE;
      if (!see) {
        hiddenBlink = 1;
      }
    }
  }
  item->unk_a = hiddenBlink;
  AuxAnim_SetAnim(item->anim, m->anim, 0, 0, 0);
  if (useZone) {
    item->zoneID = GetZoneAt(&item->sprite->pos);
  } else {
    item->zoneID = 0;
  }
  AuxShadow_Init(&item->shadow, &item->sprite->pos, 64, 24, 40, 32, 512, 1, 5, 1, 0);
  AuxShadow_Hide(&item->shadow);
  MapItem_Link(item);
  return 0;
#else
  INCFUNC("asm/func/FUN_08007310.inc");
#endif
}

// '.s' の位置に '.I' (種類, ID) の宝箱を置く (Cmd_0955 の宝箱版), 開けたときの引数は '.a' から最大3個
s32 Cmd_DDCF(void) {
  WorldPos pos;
  s32 d;
  s32 category, itemID;
  s32 g, p, m, M, S, c;
  u32 args[3];
  s32 i;

  if (VM_SeekToNamedArg('s')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  if (VM_SeekToNamedArg('I')) {
    category = VM_GetValue();
    itemID = VM_GetValue();
  } else {
    category = 0;
    itemID = 0;
  }
  d = VM_GetNamedArgValue('d', 0);
  g = VM_GetNamedArgValue('g', 0);
  p = VM_GetNamedArgValue('p', 0);
  m = VM_GetNamedArgValue('m', 0);
  M = VM_GetNamedArgValue('M', 0);
  S = VM_GetNamedArgValue('S', 0);
  c = VM_GetNamedArgValue('c', 0);
  for (i = 0; i < 3; i++) {
    args[i] = 0;
  }
  if (VM_SeekToNamedArg('a')) {
    for (i = 0; VM_GetPC() != NULL && i < 3; i++) {
      args[i] = VM_GetValue();
    }
  }
  return FUN_08007310(&pos, category, itemID, d, m, g, p, args, M, S, c);
}

// kind が一致するマップアイテムを全部解放する
s32 FUN_08007770(s32 kind) {
  MapItemManager* m = MapItemManager_Ensure();
  MapItem* item;

  if (m == NULL) {
    return -1;
  }

  item = m->items;
  while (item != NULL) {
    MapItem* next = item->next;

    if (item->kind == kind) {
      MapItem_Free(item);
    }
    item = next;
  }
}

s32 Cmd_90B4(void) { return FUN_08007770(VM_GetNamedArgValue('t', 0)); }

// category / itemID が一致する置きアイテム (kind 0, unk_14 が立ち消えかけていないもの) を全部 pos へ移す
s32 FUN_080077bc(WorldPos* pos, s32 category, s32 itemID) {
  MapItemManager* m = MapItemManager_Ensure();
  MapItem* item;

  if (m == NULL) {
    return -1;
  }

  item = m->items;
  while (item != NULL) {
    MapItem* next = item->next;

    if (item->kind == 0 && item->unk_14 && item->category == category && item->itemID == itemID && item->update != MapItem_UpdateExpire) {
      *item->pos = *pos;
    }
    item = next;
  }
}

// '.k' / '.i' の置きアイテムを全部 '.p' へ移す
s32 Cmd_FD86(void) {
  s32 category = VM_GetNamedArgValue('k', 0);
  s32 itemID = VM_GetNamedArgValue('i', 0);
  WorldPos pos;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  }
  return FUN_080077bc(&pos, category, itemID);
}
