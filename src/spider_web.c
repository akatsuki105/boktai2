#include "coffin.h"
#include "collision_map.h"
#include "enemy_manager.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"

// SpiderWeb.flags
typedef u16 SpiderWebFlags;
#define SPIDERWEB_BREAK (1 << 1)        // 0x02, 攻撃が当たったか外から壊されたときに立つ, SpiderWeb_UpdateActive が見て state 2 へ移す
#define SPIDERWEB_SHAKE (1 << 2)        // 0x04, 立っていると SpiderWeb_UpdateActive が SpiderWeb_Shake で揺らしてから下ろす
#define SPIDERWEB_HOLD_PLAYER (1 << 4)  // 0x10, プレイヤーを捕まえている, どの巣にも立っていないと SpiderWebManager_ReleaseHolds が gPlayerPtr[0]->spiderWebIdx を -1 に戻す
#define SPIDERWEB_SKYLIGHT (1 << 5)     // 0x20, 巣のエリアに光柱が差している (Skylight_IsAreaLit), 太陽ゲージがあれば姿を見せる
#define SPIDERWEB_HOLD_COFFIN (1 << 6)  // 0x40, 棺桶を捕まえている, どの巣にも立っていないと SpiderWebManager_ReleaseHolds が gCoffin->spiderWebIdx を -1 に戻す

typedef struct {
  AuxSprite spr;         // 0x00, _Destroy が AuxSprite_Remove に渡す
  AuxAnimState anim;     // 0x2C, ANIM_3DC2
  s16 timer;             // 0x3C, 毎フレーム +1, 90 を越えると枠を解放する
  s16 state;             // 0x3E, 0: 空き, 1: 張られている, 2: 壊れて点滅中, sSpiderWebUpdates の添字
  SpiderWebFlags flags;  // 0x40
  s16 idx;               // 0x42, 自分の枠番号, 空き枠では -1
  s16 shakeTimer;        // 0x44, 20 から数え下げ, 10 を超えている間はスプライトを揺らす
  ZoneID16 zoneID;       // 0x46, gStat->zoneID と一致するかを SpiderWeb_IsInDaylight が見る
  u16 grabMashBase;      // 0x48, 掴んだ瞬間のプレイヤーの mashCount
  u16 prevAngleDelta;    // 0x4A, 前回 SpiderWeb_Shake を回したときの角度差
  Hitbox hurtbox;        // 0x4C
  Vec3 pos;              // 0x9C, Hitbox_SetPos と spr.pos へ渡される
} SpiderWeb;
static_assert(sizeof(SpiderWeb) == 164);

typedef struct {
  Entity e;            // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;    // 0x018, SPR_EFF_1C1B
  AuxAnimFile* anim;   // 0x034, ANIM_3DC2
  u32 activeMask;      // 0x038, 使用中の elems のビットマスク
  SpiderWeb elems[8];  // 0x03C, 根拠: _Destroy の stride 0xA4 × 8
} SpiderWebManager;
static_assert(sizeof(SpiderWebManager) == 1372);

bool32 Skylight_IsAreaLit(s32 mapArea);
void SpiderWeb_TryCatch(SpiderWeb* elem);

IWRAM_DATA SpiderWebManager* gSpiderWebManager = NULL;  // 0x03000160

static inline bool8 SpiderWebManager_IsActive(SpiderWebManager* p, s32 i) {
  if (TEST_FLAGS(p->activeMask, 1 << i)) return TRUE;
  return FALSE;
}

static inline bool8 IsCurrentZone(u32 zoneID) {
  if (gStat->zoneID == zoneID) return TRUE;
  return FALSE;
}

// timer が進むほど短い周期になる, SpiderWeb_UpdateBreaking の点滅間隔
const u8 sBlinkIntervals[4] = {8, 4, 2, 1};  // 0x085AD310

// idx 番の巣を壊す, 捕まっている側が攻撃を受けたときに呼ばれる
void SpiderWeb_Break(s32 idx) {
  SpiderWebManager* p = gSpiderWebManager;
  SpiderWeb* e;

  if (idx < 0) {
    return;
  }

  e = &p->elems[idx];
  if (e->idx < 0) {
    return;
  }
  if (e->state == 2) {
    return;
  }

  e->flags |= SPIDERWEB_BREAK;
  e->hurtbox.flags |= HBF_HIDDEN;
}

// idx 番の巣を揺らす
void SpiderWeb_RequestShake(s32 idx) {
  SpiderWebManager* p = gSpiderWebManager;

  if (idx >= 0) {
    SpiderWeb* e = &p->elems[idx];

    if (e->idx >= 0 && e->state != 2) {
      e->flags |= SPIDERWEB_SHAKE;
    }
  }
}

void SpiderWeb_UpdateFree(SpiderWebManager* p, SpiderWeb* elem) {}

// 20フレーム周期で最初の10フレームだけスプライトの位置を揺らす
// 命令数は一致 (59/59) するが2点ずれる: (1) 原典は ~SHAKE を直前の 20 から subs #0x19 で作るのに対しこちらは 0xFFFB をプール経由で読む (HImode の AND に落ちる), (2) -20 を原典は pos.x 側に畳むのにこちらは Mod の戻り値側に畳む
// マスクを u32 ローカル経由にする / Mod の戻り値をローカルに取る / 加算順4通り はいずれも効かず
NON_MATCH void SpiderWeb_Shake(SpiderWebManager* p, SpiderWeb* elem) {
#ifdef NONMATCHING_C
  if (elem->shakeTimer <= 0) {
    elem->shakeTimer = 20;
    elem->flags &= ~SPIDERWEB_SHAKE;
  } else {
    if (elem->shakeTimer > 10) {
      elem->spr.pos.x = elem->spr.pos.x - 20 + Mod(RandomNext(), 40);
      elem->spr.pos.z = elem->spr.pos.z - 20 + Mod(RandomNext(), 40);
    }
    elem->shakeTimer--;
  }
#else
  INCFUNC("asm/func/SpiderWeb_Shake.inc");
#endif
}

void SpiderWeb_OnHit(Hitbox* a, Hitbox* b, SpiderWeb* elem) {
  elem->flags |= SPIDERWEB_BREAK;
  elem->hurtbox.flags |= HBF_HIDDEN;
}

// この枠の被弾判定を作って登録する
void SpiderWeb_InitHurtbox(SpiderWeb* elem, u32 param_2, u32 param_3) {
  Vec3 offset;
  Vec3 halfSize;

  VEC3_SET(offset, Q8(0.25), Q8(0.5), Q8(0.25));
  VEC3_SET(halfSize, Q8(0.063), Q8(0.5), Q8(0.063));
  Hitbox_Init(&elem->hurtbox, 0, HBF_HURTBOX | HBF_DAMAGE, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  Hitbox_SetHandler(&elem->hurtbox, SpiderWeb_OnHit, elem);
  Hitbox_Register(&elem->hurtbox);
}

// 空いている枠を確保して返す, 無ければ NULL
SpiderWeb* SpiderWebManager_Alloc(SpiderWebManager* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!SpiderWebManager_IsActive(p, i)) {
      SpiderWeb* e = &p->elems[i];

      p->activeMask |= 1 << i;
      e->idx = i;
      return e;
    }
  }
  return NULL;
}

// 日中の屋外で, かつ今いるゾーンが巣と同じなら TRUE
bool8 SpiderWeb_IsInDaylight(SpiderWeb* elem) {
  if (gClock.spanOfTime == TIME_NIGHT_MID || gClock.spanOfTime == TIME_NIGHT_DAWN || gClock.spanOfTime == TIME_NIGHT_DUSK) {
    return FALSE;
  }
  if (!(gStat->mapFlags & MPF_OUTDOOR)) {
    return FALSE;
  }
  if (!IsCurrentZone(elem->zoneID)) {
    return FALSE;
  }
  return TRUE;
}

// どの巣にも捕まっていなければプレイヤーと棺桶の spiderWebIdx を -1 に戻す
void SpiderWebManager_ReleaseHolds(SpiderWebManager* p) {
  SpiderWeb* elems = p->elems;
  bool8 anyUnk4 = FALSE;
  bool8 anyUnk6 = FALSE;
  s32 i;

  for (i = 0; i < 8; i++) {
    if (SpiderWebManager_IsActive(p, i)) {
      if (elems[i].flags & SPIDERWEB_HOLD_PLAYER) {
        anyUnk4 = TRUE;
      }
      if (elems[i].flags & SPIDERWEB_HOLD_COFFIN) {
        anyUnk6 = TRUE;
      }
    }
  }

  if (!anyUnk4) {
    gPlayerPtr[0]->spiderWebIdx = -1;
  }
  if (!anyUnk6) {
    Coffin_SetSpiderWebIdx(-1);
  }
}

// state 1 の更新, 捕まえている間は連打で揺らし, 抜け出されるか壊されたら state 2 へ移す, 何も捕まえていなければ日光の有無で表示を切り替える
// 残差1命令 (218/219). 原典は HOLD_PLAYER のマスク判定と角度差を1つの s16 スクラッチで使い回しており (lsls/asrs で符号拡張して保持), こちらは代入時の切り捨てが1命令多い
// s32 のまま素直に書くと 212/219, マスクと角度差を別ローカルにすると 214/219, spr のローカル化は 223/219 でいずれも悪化
NON_MATCH void SpiderWeb_UpdateActive(SpiderWebManager* p, SpiderWeb* elem) {
#ifdef NONMATCHING_C
  s16 delta;

  elem->spr.pos = elem->pos;

  delta = elem->flags & SPIDERWEB_HOLD_PLAYER;
  if (delta != 0) {
    if (gPlayerPtr[0]->mashCount >= elem->grabMashBase) {
      delta = gPlayerPtr[0]->mashCount - elem->grabMashBase;
    } else {
      delta = gPlayerPtr[0]->mashCount - (elem->grabMashBase - 256);
    }

    if (elem->prevAngleDelta != delta && (delta & 4)) {
      elem->flags |= SPIDERWEB_SHAKE;
    }

    if (!elem->spr.active) {
      Video_AddAuxSpriteIntoDrawList(&elem->spr, 0);
    }

    if (elem->flags & SPIDERWEB_SHAKE) {
      elem->shakeTimer = 60;
      SpiderWeb_Shake(p, elem);
      FUN_0807a524(&elem->spr.pos);
      elem->prevAngleDelta = delta;
      elem->flags &= ~SPIDERWEB_SHAKE;
    }

    if (delta > 9 || (elem->flags & SPIDERWEB_BREAK)) {
      elem->timer = 0;
      elem->state = 2;
      elem->spr.flags &= ~SPRFLAG_HIDDEN;
      elem->flags &= ~(SPIDERWEB_BREAK | SPIDERWEB_HOLD_PLAYER);
      return;
    }
  } else if (elem->flags & SPIDERWEB_HOLD_COFFIN) {
    if (!elem->spr.active) {
      Video_AddAuxSpriteIntoDrawList(&elem->spr, 0);
    }

    if (elem->flags & SPIDERWEB_SHAKE) {
      SpiderWeb_Shake(p, elem);
      elem->flags &= ~SPIDERWEB_SHAKE;
    }

    if (elem->flags & SPIDERWEB_BREAK) {
      elem->timer = 0;
      elem->state = 2;
      elem->flags &= ~SPIDERWEB_BREAK;
      return;
    }
  } else {
    if ((gPlayerPtr[0]->flag20 & PFLAG20_UNK_19) || ((elem->flags & SPIDERWEB_SKYLIGHT) && gStat->sunGauge > 0) || SpiderWeb_IsInDaylight(elem)) {
      if (!elem->spr.active) {
        Video_AddAuxSpriteIntoDrawList(&elem->spr, 0);
      }
    } else {
      if (elem->spr.active) {
        Video_RemoveAuxSpriteFromDrawList(&elem->spr, 0);
      }
    }

    if (elem->flags & SPIDERWEB_BREAK) {
      if (!elem->spr.active) {
        Video_AddAuxSpriteIntoDrawList(&elem->spr, 0);
      }
      elem->timer = 0;
      elem->state = 2;
      elem->flags &= ~SPIDERWEB_BREAK;
      return;
    }
  }

  if (!(elem->flags & (SPIDERWEB_HOLD_PLAYER | SPIDERWEB_HOLD_COFFIN))) {
    SpiderWeb_TryCatch(elem);
  }
#else
  INCFUNC("asm/func/SpiderWeb_UpdateActive.inc");
#endif
}

// 点滅させながら 90 フレーム数え, 終わったら枠を解放する
// 残差1命令 (82/83), ~(HOLD_PLAYER|HOLD_COFFIN) が HImode の AND に落ちて 0xFFAF のプール読みになる. 原典は SImode で movs #0x51 + rsbs の2命令
// static inline の ClearFlags か s32 ローカル経由にすると 83/83 まで届くがそれぞれ定数の位置かレジスタ割当が1箇所ずれる. マスクの書き方4通りも試済
// spr のローカル化 (AuxSprite* spr = &elem->spr) で原典の r7 を再現できた
NON_MATCH void SpiderWeb_UpdateBreaking(SpiderWebManager* p, SpiderWeb* elem) {
#ifdef NONMATCHING_C
  AuxSprite* spr = &elem->spr;
  s32 idx;

  if (!elem->spr.active) {
    Video_AddAuxSpriteIntoDrawList(&elem->spr, 0);
  }

  if (elem->timer == 18) {
    elem->flags &= ~(SPIDERWEB_HOLD_PLAYER | SPIDERWEB_HOLD_COFFIN);
  }

  if (elem->timer > 60) {
    idx = 2;
  } else if (elem->timer > 40) {
    idx = 1;
  } else {
    idx = 0;
  }

  if (Mod(elem->timer, sBlinkIntervals[idx]) == 0) {
    if (spr->flags & SPRFLAG_HIDDEN) {
      spr->flags &= ~SPRFLAG_HIDDEN;
    } else {
      spr->flags |= SPRFLAG_HIDDEN;
    }
  }

  if (elem->timer > 90) {
    p->activeMask &= ~(1 << elem->idx);
    elem->state = 0;
    Hitbox_Unregister(&elem->hurtbox);
    Video_RemoveAuxSpriteFromDrawList(spr, 0);
    elem->idx = -1;
    elem->flags = 0;
  } else {
    elem->timer++;
  }
#else
  INCFUNC("asm/func/SpiderWeb_UpdateBreaking.inc");
#endif
}

// プレイヤーか棺桶が巣の範囲に入っていたら最初に見つかった方を捕まえる
// 残差15命令 (181/166). Vec3 のローカルをフィールド代入で埋めると1フィールドあたり ldr/ands/orrs/str の語単位 RMW になるが, 原典は strh でポインタ経由に書いている. Vec3_Sub 相当の static inline を通すと 163/166 まで寄るが一致しないので外した (agbcc-levers.md に記録)
// x の範囲判定 (-64..160) は && のペアを括弧で括ると符号なし1回の範囲テストに畳まれて原典と一致する. z 側は括らないのが正しい
// 残る差は handled の 0/1 の作り置き2ブロックとレジスタ割当. GetPlayer(0) の static inline は逆に遠のく (157/166)
NON_MATCH void SpiderWeb_TryCatch(SpiderWeb* elem) {
#ifdef NONMATCHING_C
  Player* player = gPlayerPtr[0];
  Vec3 d;
  u16 payload;

  if (player == NULL) {
    return;
  }

  d.x = player->mover.pos.x - elem->pos.x;
  d.y = player->mover.pos.y - elem->pos.y;
  d.z = player->mover.pos.z - elem->pos.z;

  if (abs(d.y) < Q8(0.125) && (d.x >= Q8(-0.25) && d.x <= Q8(0.625)) && d.z <= Q8(0.625) && d.z >= Q8(-0.23)) {
    if (player->spiderWebIdx < 0) {
      player->spiderWebIdx = elem->idx;
      elem->flags |= SPIDERWEB_HOLD_PLAYER;
      elem->hurtbox.flags |= HBF_HIDDEN;
      elem->grabMashBase = gPlayerPtr[0]->mashCount;
      payload = 6;
      Enemy_SendMsgByKindVariant(ENEK_SPIDER, 1, &payload);
      PlaySound_082406e0(SE_SPIDER_WEB_HIT);
      return;
    }
  }

  if (!Coffin_CopyPos(&d)) {
    return;
  }
  if (!Coffin_IsIdle()) {
    return;
  }

  d.x -= elem->pos.x;
  d.y -= elem->pos.y;
  d.z -= elem->pos.z;

  if (abs(d.y) <= Q8(0.122) && (d.x >= Q8(-0.25) && d.x <= Q8(0.625)) && d.z <= Q8(0.625) && d.z >= Q8(-0.23)) {
    if (Coffin_GetSpiderWebIdx() < -1) {
      Coffin_SetSpiderWebIdx(elem->idx);
      elem->flags |= SPIDERWEB_HOLD_COFFIN;
      PlaySound_082406e0(SE_SPIDER_WEB_HIT);
    }
  }
#else
  INCFUNC("asm/func/SpiderWeb_TryCatch.inc");
#endif
}

// 向きから象限を出して, アニメーションの variant と反転フラグを決める
void Mover_GetAnimQuadrant(Mover* mover, u8* variant, u8* flags) {
  u32 q = Angle_ToDir4(mover->angle);

  if (q > DIR4_EAST) {
    *flags = 1;
    *variant = 3 - q;
  } else {
    *flags = 0;
    *variant = q;
  }
}

// スパイダーの Mover の位置と向きで空き枠に巣を張って枠番号を返す, 枠が無ければ -1
// 残差1命令 (203/204) でこちらが短い. レジスタ割当の違い: 原典は &elem->zoneID を r10 に置いて elem をスタックへ退避するが, agbcc は elem を r7 に残して &elem->zoneID を退避する (結果 sub sp が 0xC でなく 0x10 になる)
// ANIM_PLAY_YFLIP の定数 2 を原典は1つのレジスタに作って copy するが agbcc は2回作る. anim / cmd のローカルを外す4通りは全て悪化 (209〜224)
NON_MATCH s32 SpiderWebManager_Spawn(SpiderWebManager* p, Mover* mover) {
#ifdef NONMATCHING_C
  SpiderWeb* elem = SpiderWebManager_Alloc(p);
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  u8 variant;
  u8 flags;

  if (elem == NULL) {
    return -1;
  }

  elem->state = 1;
  Mover_GetAnimQuadrant(mover, &variant, &flags);
  elem->pos = mover->pos;
  elem->zoneID = GetZoneAt(&elem->pos);
  elem->flags = 0;
  elem->grabMashBase = 0;
  elem->spr.pos = elem->pos;
  AuxSprite_Setup(&elem->spr, &p->gfx, 0);

  anim = &elem->anim;
  AuxAnim_SetAnim(anim, p->anim, 1, 0, flags);

  cmd = &anim->cmds[anim->cmdIdx];
  elem->spr.poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    elem->spr.flags |= SPRFLAG_XFLIP;
  } else {
    elem->spr.flags &= ~SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    elem->spr.flags |= SPRFLAG_YFLIP;
  } else {
    elem->spr.flags &= ~SPRFLAG_YFLIP;
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
    anim->duration = anim->cmds[anim->cmdIdx] & 0xF;
    anim->wait = (anim->duration * anim->speed) >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }

  elem->spr.flags &= ~SPRFLAG_HIDDEN;
  elem->spr.priority = 1;
  if (Skylight_IsAreaLit(elem->zoneID)) {
    elem->flags |= SPIDERWEB_SKYLIGHT;
  }
  SpiderWeb_InitHurtbox(elem, 0, 0);
  return elem->idx;
#else
  INCFUNC("asm/func/SpiderWebManager_Spawn.inc");
#endif
}

void (*const sSpiderWebUpdates[3])(SpiderWebManager*, SpiderWeb*) = {
    SpiderWeb_UpdateFree,
    SpiderWeb_UpdateActive,
    SpiderWeb_UpdateBreaking,
};  // 0x085AD314

// 使用中の巣について state ごとの更新関数を呼ぶ
s32 SpiderWebManager_Update(SpiderWebManager* p) {
  SpiderWeb* elems = p->elems;

  if (p->activeMask != 0) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (SpiderWebManager_IsActive(p, i)) {
        sSpiderWebUpdates[elems[i].state](p, &elems[i]);
      }
    }
    SpiderWebManager_ReleaseHolds(p);
  }

  return 0;
}

s32 SpiderWebManager_Destroy(SpiderWebManager* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (SpiderWebManager_IsActive(p, i)) {
      SpiderWeb* e = &p->elems[i];

      if (e->spr.active) {
        AuxSprite_Remove(&e->spr);
      }
      Hitbox_Unregister(&e->hurtbox);
    }
  }

  gSpiderWebManager = NULL;
  return 0;
}

s32 SpiderWebManager_Init(SpiderWebManager* p) {
  Video_GetAuxSprite(&p->gfx, SPR_EFF_1C1B);
  p->activeMask = 0;
  p->anim = GetFile(DIR_ANIMATION, ANIM_3DC2);
  gSpiderWebManager = p;
  return 0;
}

SpiderWebManager* SpiderWebManager_Create(void) {
  if (gSpiderWebManager == NULL) {
    SpiderWebManager* p = CreateEntity(ENTITY_UNK_10, sizeof(SpiderWebManager));
    if (p != NULL) {
      SetEntityRoutine(p, SpiderWebManager_Update, SpiderWebManager_Destroy);
      if (SpiderWebManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gSpiderWebManager;
}

void SpiderWebManager_ClearGlobal(void) { gSpiderWebManager = NULL; }

// 不使用?
// スクリプトの .p (位置) と .r (反転) で空き枠に巣を張る
// 残差1命令 (242/241) でこちらが長い. 原典は elem のコピーを高位レジスタにもう1つ持って spr 系のアクセスをそちら経由で行うが, spr のローカル化では再現できず 245 に悪化する
// アニメ進行の本体は SpiderWebManager_Spawn と同一, そちらの残差と同種
NON_MATCH void SpiderWebManager_SpawnFromScript(void) {
#ifdef NONMATCHING_C
  SpiderWebManager* p = gSpiderWebManager;
  SpiderWeb* elem;
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  u8 variant;

  if (p == NULL) {
    p = SpiderWebManager_Create();
    if (p == NULL) {
      return;
    }
  }

  elem = SpiderWebManager_Alloc(p);
  if (elem == NULL) {
    return;
  }

  elem->state = 1;

  if (VM_SeekToNamedArg('p')) {
    elem->pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    elem->pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    elem->pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    elem->pos.x = 0;
    elem->pos.y = 0;
    elem->pos.z = 0;
  }

  variant = VM_GetNamedArgValue('r', 0);
  elem->zoneID = GetZoneAt(&elem->pos);
  elem->flags = 0;
  elem->grabMashBase = 0;
  elem->spr.pos = elem->pos;
  AuxSprite_Setup(&elem->spr, &p->gfx, 0);

  anim = &elem->anim;
  AuxAnim_SetAnim(anim, p->anim, 1, 0, variant);

  cmd = &anim->cmds[anim->cmdIdx];
  elem->spr.poseIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    elem->spr.flags |= SPRFLAG_XFLIP;
  } else {
    elem->spr.flags &= ~SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    elem->spr.flags |= SPRFLAG_YFLIP;
  } else {
    elem->spr.flags &= ~SPRFLAG_YFLIP;
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
    anim->duration = anim->cmds[anim->cmdIdx] & 0xF;
    anim->wait = (anim->duration * anim->speed) >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }

  elem->spr.flags &= ~SPRFLAG_HIDDEN;
  elem->spr.priority = 1;
  if (Skylight_IsAreaLit(elem->zoneID)) {
    elem->flags |= SPIDERWEB_SKYLIGHT;
  }
  SpiderWeb_InitHurtbox(elem, 0, 0);
#else
  INCFUNC("asm/func/SpiderWebManager_SpawnFromScript.inc");
#endif
}

// 不使用?
void SpiderWebManager_BreakAll(void) {
  SpiderWebManager* p = gSpiderWebManager;

  if (p != NULL) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (SpiderWebManager_IsActive(p, i)) {
        SpiderWeb* e = &p->elems[i];

        if (e->idx >= 0 && e->state != 2) {
          e->flags |= SPIDERWEB_BREAK;
          e->hurtbox.flags |= HBF_HIDDEN;
        }
      }
    }
  }
}
