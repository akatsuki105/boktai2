#include "constants/sprite.h"
#include "entity.h"
#include "game.h"
#include "global.h"
#include "inline.h"
#include "link_session.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vm.h"

struct LinkBattleCoinManager;

// 通信対戦のコイン(対戦相手を倒したりすると落とすもので、これがプレイヤーの得点になる)
typedef struct LinkBattleCoin {
  s8 owner;                                                                                       // 0x00, 拾ったプレイヤーの番号, 落ちている間は -1, gLinkSession->coinOwners[i] で初期化する
  bool8 behindWall;                                                                               // 0x01, Map_IsBehindHigherTile の結果, 立っている間は poseIdx を 4 進め影を隠す
  u8 animTimer;                                                                                   // 0x02, 回転のポーズを送る間隔を数える
  u8 animFrame;                                                                                   // 0x03, 回転のポーズ 0..3
  bool8 stateBegun;                                                                               // 0x04, updateCallback を替えると 1, 各状態の最初の更新で 0 に戻す
  u8 unk_05;                                                                                      // 0x05, padding?
  u16 timer;                                                                                      // 0x06, 状態に入ってからのフレーム数
  Vec3 startPos;                                                                                  // 0x08, 飛び出したときの位置, destPos への補間の始点
  Vec3 destPos;                                                                                   // 0x10, 落ちる先の位置
  Vec3 vpPos;                                                                                     // 0x18, sprite.pos を WorldToVp した視点座標, playerVpPos と比べて拾われたかを判定する
  void (*updateCallback)(struct LinkBattleCoinManager* p, struct LinkBattleCoin* coin, s32 idx);  // 0x20
  AuxSprite sprite;                                                                               // 0x24
  ParticleShadow shadow;                                                                          // 0x50
} LinkBattleCoin;
static_assert(sizeof(LinkBattleCoin) == 144);

typedef struct LinkBattleCoinManager {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u32 frameCount;           // 0x018, _Update が毎フレーム +1
  u16 pickupScriptID;       // 0x01C, '.p=0', コインが拾われたときに実行するスクリプト
  AuxSpriteGfx coinGfx;     // 0x020, SPR_COIN
  Vec3 playerVpPos[4];      // 0x03C, players[i] の位置を WorldToVp した視点座標
  Player* players[4];       // 0x05C, gPlayerPtr[0..3] の写し
  LinkBattleCoin coins[5];  // 0x06C
} LinkBattleCoinManager;
static_assert(sizeof(LinkBattleCoinManager) == 828);

void LinkBattleCoin_StateFly(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 idx);
void LinkBattleCoin_StateBounce(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 idx);
void LinkBattleCoin_StateOnGround(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 idx);
void LinkBattleCoin_StateCollected(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 idx);

// 状態に入った最初の呼び出しだけ TRUE, 入場フラグを下ろす
static inline bool8 LinkBattleCoin_ConsumeStateBegun(LinkBattleCoin* coin) {
  if (coin->stateBegun) {
    coin->stateBegun = FALSE;
    return TRUE;
  }
  return FALSE;
}

// 自分が何番目の参加者かを返す, セッションが無ければ -1
static inline s32 LinkSession_GetPlayerIdx(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }
  return p->playerIdx;
}

// interval フレームごとに回転のポーズを1つ送る, 壁の裏にいる間は 4 先のポーズを使う
static inline void LinkBattleCoin_Spin(LinkBattleCoin* coin, s32 interval) {
  if (++coin->animTimer >= interval) {
    s32 pose;

    coin->animTimer = 0;
    if (++coin->animFrame > 3) {
      coin->animFrame = 0;
    }
    pose = coin->animFrame;
    if (coin->behindWall) {
      pose += 4;
    }
    coin->sprite.poseIdx = pose;
  }
}

IWRAM_DATA LinkBattleCoinManager* gLinkBattleCoinManager = NULL;  // 0x030001B0

void LinkBattleCoinManager_ClearGlobal(void) { gLinkBattleCoinManager = NULL; }

// 落ちる先が壁や穴, 高さ 0 のタイルなら, 右, 下, 左, 上の順に乗れる隣のタイルへずらす
// 299/296命令, 原典は tile を r6 に置くが, こちらは r9 に置いて mov が増える (LinkBattleCoin_AvoidLava と同じ形の割り当て違い)
// 試済: case ごとに next の変数を持つ形 (247命令), 毎回式を書く形 (313命令), 宣言順, u32 tile, 判定を反転してループを囲む形, 効いた手: 判定は式を2回書き, 座標を書く枝でだけ next を求める
NON_MATCH void LinkBattleCoin_AvoidWall(LinkBattleCoin* coin) {
#ifdef NONMATCHING_C
  s32 tile = GetCollisionTileIdx(&coin->destPos);
  s32 i;

  if (!(TileAtIndex(tile)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH)) && (TileAtIndex(tile)->heightStairs & 0xF) != 0) {
    return;
  }
  for (i = 0; i < 4; i++) {
    switch (i) {
      case 0: {
        if (!(TileAtIndex(tile + 1)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH)) && (TileAtIndex(tile + 1)->heightStairs & 0xF) != 0) {
          s32 next = tile + 1;

          coin->destPos.x = Mod(next, gCollisionMap->tiledata->width) << 8;
          coin->destPos.z = Div(next, gCollisionMap->tiledata->width) << 8;
          return;
        }
        break;
      }
      case 1: {
        if (!(TileAtIndex(tile + gCollisionMap->tiledata->width)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH)) && (TileAtIndex(tile + gCollisionMap->tiledata->width)->heightStairs & 0xF) != 0) {
          s32 next = tile + gCollisionMap->tiledata->width;

          coin->destPos.x = Mod(next, gCollisionMap->tiledata->width) << 8;
          coin->destPos.z = Div(next, gCollisionMap->tiledata->width) << 8;
          return;
        }
        break;
      }
      case 2: {
        if (!(TileAtIndex(tile - 1)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH)) && (TileAtIndex(tile - 1)->heightStairs & 0xF) != 0) {
          s32 next = tile - 1;

          coin->destPos.x = Mod(next, gCollisionMap->tiledata->width) << 8;
          coin->destPos.z = Div(next, gCollisionMap->tiledata->width) << 8;
          return;
        }
        break;
      }
      case 3: {
        if (!(TileAtIndex(tile - gCollisionMap->tiledata->width)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH)) && (TileAtIndex(tile - gCollisionMap->tiledata->width)->heightStairs & 0xF) != 0) {
          s32 next = tile - gCollisionMap->tiledata->width;

          coin->destPos.x = Mod(next, gCollisionMap->tiledata->width) << 8;
          coin->destPos.z = Div(next, gCollisionMap->tiledata->width) << 8;
          return;
        }
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/LinkBattleCoin_AvoidWall.inc");
#endif
}

// 炎のマップで落ちる先が溶岩のタイルなら, 右, 下, 左, 上の順に溶岩でない隣のタイルへずらす
// 217/221命令, 原典は coin を r8, tile を r6 に置き callee-saved を1本多く使うが, こちらは coin を r7, tile を r9 に置く
// 試済: case ごとに判定と座標の書き込みを持つ形 (238命令), 判定を1つの if にまとめる形, TileAttrAtIndex (201命令), next の宣言位置, 効いた手: case ごとに next を求めてから TileAtIndex で調べる
NON_MATCH void LinkBattleCoin_AvoidLava(LinkBattleCoin* coin) {
#ifdef NONMATCHING_C
  s32 tile = GetCollisionTileIdx(&coin->destPos);
  s32 i;

  if (!TEST_FLAGS(gStat->mapFlags, MPF_HOT)) {
    return;
  }
  if (!(TileAtIndex(tile)->attr & TATTR_SPECIAL)) {
    return;
  }
  for (i = 0; i < 4; i++) {
    s32 next;

    switch (i) {
      case 0: {
        next = tile + 1;
        if (!(TileAtIndex(next)->attr & TATTR_SPECIAL)) {
          coin->destPos.x = Mod(next, gCollisionMap->tiledata->width) << 8;
          coin->destPos.z = Div(next, gCollisionMap->tiledata->width) << 8;
          return;
        }
        break;
      }
      case 1: {
        next = tile + gCollisionMap->tiledata->width;
        if (!(TileAtIndex(next)->attr & TATTR_SPECIAL)) {
          coin->destPos.x = Mod(next, gCollisionMap->tiledata->width) << 8;
          coin->destPos.z = Div(next, gCollisionMap->tiledata->width) << 8;
          return;
        }
        break;
      }
      case 2: {
        next = tile - 1;
        if (!(TileAtIndex(next)->attr & TATTR_SPECIAL)) {
          coin->destPos.x = Mod(next, gCollisionMap->tiledata->width) << 8;
          coin->destPos.z = Div(next, gCollisionMap->tiledata->width) << 8;
          return;
        }
        break;
      }
      case 3: {
        next = tile - gCollisionMap->tiledata->width;
        if (!(TileAtIndex(next)->attr & TATTR_SPECIAL)) {
          coin->destPos.x = Mod(next, gCollisionMap->tiledata->width) << 8;
          coin->destPos.z = Div(next, gCollisionMap->tiledata->width) << 8;
          return;
        }
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/LinkBattleCoin_AvoidLava.inc");
#endif
}

// 落ちる先を決める, 始点のタイルを基準に idx の偶奇で左右, idx で前後をずらし, 乱数で少しばらつかせて床の高さに置く
// 147/148命令, 原典は乱数表の番地を毎回読み直して callee-saved を1本少なく使うが, こちらは表の番地を r4 に持つ (durathror の Entity080601a8_StateFly と同じ形)
// 試済: x を代入し直す形 (142命令に崩れる), z の式で乱数を先に書く形, 全部 RandomNext (147命令のまま r7 が残る), 効いた手: idx は s32
NON_MATCH void LinkBattleCoin_PickDest(LinkBattleCoin* coin, s32 idx) {
#ifdef NONMATCHING_C
  coin->destPos = coin->startPos;
  LinkBattleCoin_AvoidLava(coin);
  LinkBattleCoin_AvoidWall(coin);
  coin->destPos.x &= 0xFF00;
  coin->destPos.z &= 0xFF00;
  if (idx & 1) {
    coin->destPos.x += 0x80 + (Random() & 0x7F);
  } else {
    coin->destPos.x += Random() & 0x7F;
  }
  if (idx <= 2) {
    coin->destPos.z += idx * 80 + (Random() & 0x3F);
  } else {
    coin->destPos.z += (idx - 3) * 80 + (Random() & 0x3F);
  }
  coin->destPos.y = TileHeightAt(&coin->destPos);
#else
  INCFUNC("asm/func/LinkBattleCoin_PickDest.inc");
#endif
}

s32 LinkBattleCoin_Init(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 param_3) {
  coin->owner = param_3;
  coin->behindWall = 0;
  coin->animTimer = 0;
  coin->animFrame = 0;
  coin->timer = 0;
  coin->updateCallback = NULL;
  AuxSprite_Add(&coin->sprite, &p->coinGfx, SPRFLAG_HIDDEN);
  ParticleShadow_Init(&coin->shadow, &coin->sprite.pos, 0);
  ParticleShadow_Hide(&coin->shadow);
  return 0;
}

s32 LinkBattleCoin_Destroy(LinkBattleCoinManager* p, LinkBattleCoin* coin) {
  AuxSprite_Remove(&coin->sprite);
  ParticleShadow_Remove(&coin->shadow);
  return 0;
}

void LinkBattleCoin_Deactivate(LinkBattleCoin* coin) {
  coin->behindWall = 0;
  coin->animTimer = 0;
  coin->animFrame = 0;
  coin->sprite.flags |= SPRFLAG_HIDDEN;
  ParticleShadow_Hide(&coin->shadow);
  coin->updateCallback = NULL;
  coin->timer = 0;
  coin->stateBegun = TRUE;
}

// owner が key と一致するスロットを探す
LinkBattleCoin* LinkBattleCoinManager_FindSlot(LinkBattleCoinManager* p, s32 key) {
  LinkBattleCoin* coin = p->coins;
  s32 i;

  for (i = 0; i < 5; i++, coin++) {
    if (coin->owner == key) {
      return coin;
    }
  }

  return NULL;
}

// 拾われたコインについて '.p' のスクリプトを (拾った人, x, y, z) を引数に実行する, 拾った人がいないか倒れていれば -1
// 55/56命令, 原典は owner を -1 と比べた後に r4 へ写して持つが, こちらは写さない (MapItem_ExecScript と同じ形)
// 試済: 1つの if にまとめる形, owner をローカルにしない形, -1 の判定だけ先に出す形, 効いた手: pickupScriptID を u16 に
NON_MATCH s32 LinkBattleCoin_ExecPickupScript(LinkBattleCoinManager* p, LinkBattleCoin* coin) {
#ifdef NONMATCHING_C
  u32 argv[4];
  ScriptArgs args;
  s32 owner;

  if (p->pickupScriptID == 0) {
    return -1;
  }
  owner = coin->owner;
  if (owner == -1 || (gPlayerModes[owner] & (PMODE_UNK_3 | PMODE_DEAD))) {
    return -1;
  }
  argv[0] = owner;
  argv[1] = coin->sprite.pos.x;
  argv[2] = coin->sprite.pos.y;
  argv[3] = coin->sprite.pos.z;
  args.argc = 4;
  args.argv = argv;
  return VM_ExecByID(p->pickupScriptID, &args);
#else
  INCFUNC("asm/func/LinkBattleCoin_ExecPickupScript.inc");
#endif
}

// 毎フレーム開始位置をずらしながら各プレイヤーと重なりを調べ, 最初に触れた人に拾わせて TRUE を返す
// 原典は重なり判定を TRUE/FALSE に作ってから分岐する, 判定を (pos, vp, playerPos, playerVp) を受ける static inline にすると 114/115 命令で最後の条件の分岐の並びだけになる
// 試済: inline を (vp, pos, ...) の順, 論理式で返す形, 条件を反転して FALSE を返す形, 効いた手: flags は TEST_FLAGS
NON_MATCH s32 LinkBattleCoin_CheckPickup(LinkBattleCoinManager* p, LinkBattleCoin* coin) {
#ifdef NONMATCHING_C
  s32 start = p->frameCount & 3;
  s32 i;

  for (i = start; i < start + 4; i++) {
    s32 idx = i & 3;
    Player* player = p->players[idx];

    if (player != NULL && !TEST_FLAGS(gPlayerModes[idx], PMODE_DEAD | PMODE_UNK_3) && !TEST_FLAGS(player->flag20, PFLAG20_UNK_28)) {
      Vec3* playerVp = &p->playerVpPos[idx];
      s32 dy = coin->vpPos.y - playerVp->y;

      if (abs(coin->sprite.pos.y - player->mover.pos.y) <= 127 && abs(coin->vpPos.x - playerVp->x) <= 14 && dy >= -24 && dy <= 4) {
        coin->owner = idx;
        LinkSession_AddCoin(coin->owner);
        LinkBattleCoin_ExecPickupScript(p, coin);
        coin->updateCallback = LinkBattleCoin_StateCollected;
        coin->timer = 0;
        coin->stateBegun = TRUE;
        return TRUE;
      }
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/LinkBattleCoin_CheckPickup.inc");
#endif
}

// 落とされたコイン, 速く回りながら 64 フレームかけて弧を描いて destPos へ飛び, 着いたら弾む状態へ移る
void LinkBattleCoin_StateFly(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 idx) {
  if (LinkBattleCoin_ConsumeStateBegun(coin)) {
    coin->sprite.flags &= ~SPRFLAG_HIDDEN;
    ParticleShadow_Show(&coin->shadow);
    coin->startPos = coin->sprite.pos;
    LinkBattleCoin_PickDest(coin, idx);
    PlaySound_082406e0(SE_SHOP_SELL);
  }
  LinkBattleCoin_Spin(coin, 2);
  LerpVec3(&coin->sprite.pos, &coin->startPos, &coin->destPos, coin->timer, 6);
  coin->sprite.pos.y += POLAR_Z(378, coin->timer * 2);
  if (++coin->timer > 63) {
    coin->updateCallback = LinkBattleCoin_StateBounce;
    coin->timer = 0;
    coin->stateBegun = TRUE;
  }
}

// 着地したあと destPos の高さで 32 フレーム上下に弾み, 落ちている状態へ移る
void LinkBattleCoin_StateBounce(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 idx) {
  if (coin->stateBegun) {
    coin->stateBegun = FALSE;
  }
  LinkBattleCoin_Spin(coin, 8);
  coin->sprite.pos.y = coin->destPos.y + POLAR_Z(64, coin->timer * 4);
  if (++coin->timer > 31) {
    coin->updateCallback = LinkBattleCoin_StateOnGround;
    coin->timer = 0;
    coin->stateBegun = TRUE;
  }
}

// 地面に落ちているコイン, 壁の裏なら影を消して手前に出し, 回りながら誰かに拾われるのを待つ
void LinkBattleCoin_StateOnGround(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 idx) {
  if (LinkBattleCoin_ConsumeStateBegun(coin)) {
    coin->behindWall = Map_IsBehindHigherTile(&coin->sprite.pos, 0x80);
    if (coin->behindWall) {
      coin->sprite.priority = 1;
      ParticleShadow_Hide(&coin->shadow);
    } else {
      coin->sprite.priority = 2;
    }
  }
  LinkBattleCoin_Spin(coin, 8);
  WorldToVp(&coin->vpPos, &coin->sprite.pos);
  LinkBattleCoin_CheckPickup(p, coin);
}

// 拾われたコイン, 速く回りながら 16 フレーム上へ昇って消える, 拾ったのが自分なら効果音を鳴らす
void LinkBattleCoin_StateCollected(LinkBattleCoinManager* p, LinkBattleCoin* coin, s32 idx) {
  if (LinkBattleCoin_ConsumeStateBegun(coin)) {
    coin->behindWall = FALSE;
    if (coin->owner == LinkSession_GetPlayerIdx()) {
      PlaySound_082406e0(SONG_629);
    }
  }
  LinkBattleCoin_Spin(coin, 2);
  coin->sprite.pos.y += 24;
  if (++coin->timer > 15) {
    LinkBattleCoin_Deactivate(coin);
  }
}

// 各プレイヤーの位置を視点座標にして playerVpPos に入れる
// 67/69命令, 原典はループの上限 4 を ip に置いて cmp r6, ip で比べ, こちらは cmp #3 の即値になる
// 試済: player ローカル無し, ARRAY_COUNT, 4 を返す inline (cmp #4 / blt までは揃う), 上限を引数で受ける inline
NON_MATCH void LinkBattleCoinManager_UpdatePlayerVp(LinkBattleCoinManager* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    Player* player = p->players[i];

    if (player != NULL) {
      WorldToVp(&p->playerVpPos[i], &player->mover.pos);
    }
  }
#else
  INCFUNC("asm/func/LinkBattleCoinManager_UpdatePlayerVp.inc");
#endif
}

s32 LinkBattleCoinManager_Update(LinkBattleCoinManager* p) {
  bool32 inited = FALSE;
  LinkBattleCoin* coin = p->coins;
  s32 i;

  for (i = 0; i < 5; i++, coin++) {
    if (coin->updateCallback != NULL) {
      if (!inited) {
        LinkBattleCoinManager_UpdatePlayerVp(p);
        inited = TRUE;
      }
      coin->updateCallback(p, coin, i);
    }
  }
  p->frameCount++;
  return 0;
}

s32 LinkBattleCoinManager_Destroy(LinkBattleCoinManager* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    if (LinkBattleCoin_Destroy(p, &p->coins[i]) < 0) {
      return -1;
    }
  }

  gLinkBattleCoinManager = NULL;
  return 0;
}

s32 LinkBattleCoinManager_Init(LinkBattleCoinManager* p, u32 unused) {
  LinkSession* session;
  s8* owners;
  LinkBattleCoin* coin;
  s32 i;

  gLinkBattleCoinManager = p;
  p->frameCount = 0;
  p->pickupScriptID = VM_GetNamedArgValue('p', 0);
  if (!Video_GetAuxSprite(&p->coinGfx, SPR_COIN)) {
    return -1;
  }
  session = gLinkSession;
  owners = session->coinOwners;
  if (session == NULL) {
    owners = NULL;
  }
  for (i = 0, coin = p->coins; i < 5; i++) {
    if (LinkBattleCoin_Init(p, coin, owners[i]) < 0) {
      return -1;
    }
    coin++;
  }
  for (i = 0; i < 4; i++) {
    Player* player = gPlayerPtr[i];

    p->players[i] = player;
    if (player != NULL) {
      WorldToVp(&p->playerVpPos[i], &player->mover.pos);
    }
  }
  return 0;
}

// 0x150F, HashName("対戦用コイン")
LinkBattleCoinManager* LinkBattleCoinManager_Create(u32 id) {
  LinkBattleCoinManager* p = CreateEntity(ENTITY_UNK_10, sizeof(LinkBattleCoinManager));

  if (p != NULL) {
    SetEntityRoutine(p, LinkBattleCoinManager_Update, LinkBattleCoinManager_Destroy);
    if (LinkBattleCoinManager_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// owner が持つコインを1枚 pos に落とし, 弾み出る状態にする, 管理エンティティかそのコインが無ければ -1
s32 LinkBattleCoinManager_DropCoin(Vec3* pos, s32 owner) {
  LinkBattleCoin* coin;

  if (gLinkBattleCoinManager == NULL) {
    return -1;
  }
  coin = LinkBattleCoinManager_FindSlot(gLinkBattleCoinManager, owner);
  if (coin == NULL) {
    return -1;
  }
  coin->owner = -1;
  coin->behindWall = FALSE;
  coin->animTimer = 0;
  coin->animFrame = 0;
  coin->sprite.pos = *pos;
  coin->sprite.priority = 2;
  coin->startPos = *pos;
  coin->updateCallback = LinkBattleCoin_StateFly;
  coin->timer = 0;
  coin->stateBegun = TRUE;
  return 0;
}
