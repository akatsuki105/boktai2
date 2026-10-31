#include "enemy.h"

#include "collision_map.h"
#include "constants/miscs.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy_manager.h"
#include "enemy_target.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "inventory.h"
#include "item.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"

// 原典のファイル名は enemy.c, 根拠: FUN_080e6794 / FUN_080e6834 / FUN_080e68d8 が、抜き取られた assert の引数として文字列 "enemy.c" (0x08251F60) と行番号をレジスタに積んでから Enemy_ClearPendingState を呼ぶ
// 引数の個数と void/値返しはアセンブリから機械的に出したもの, 型は第1引数が Enemy だと言えるものだけ Enemy*, 残りは未解析の unknown*

const s16 s16_ARRAY_085ad3c4[4] = {8, 4, 2};  // 0x085AD3C4

const s16 s16_ARRAY_085ad3cc[4] = {1600, 0, 1600};  // 0x085AD3CC

const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251e14[] = "../../skoba/enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251e3c[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251e58[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251e74[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251e90[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251eac[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251ec8[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251ee4[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251f00[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251f1c[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251f38[] = "../enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_eneinline_h_08251f54[] = "eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_enemy_c_08251f60[] = "enemy.c";

s32 FUN_08240b98(Vec3* param_1, s8 param_2);
s32 FUN_081fa26c(Vec3* pos);
void FUN_080867a0(void);
void FUN_080e7b6c(Enemy* p);
void FUN_080e6794(Enemy* p, s32 priority);
void FUN_0809c344(s32 param_1, s32 param_2, u16 param_3, u16 param_4, s32 param_5);
void FUN_080ec5b4(u16 a, u16 b);
void FUN_080f54e4(Enemy* p, s32 param_2);
bool8 FUN_080e4b3c(Enemy* p);
void Enemy_SnapToFloor(Enemy* p);
void Map_StepNavPath(NavAgent* agent, Vec3* pos);
bool32 Entity1DBE_TouchElemNear(WorldPos* pos);
s32 FUN_082340c8(Vec3* pos, Vec3* dir, s32 count, s32 limit);
s32 Entity080146e0_SpawnAtAngle(s32 count, s32 kind, Vec3* pos, s32 angle, s32 angleRange, s32 speed, s32 speedRange, s32 velY, s32 velYRange, s32 lifeBase, s32 lifeRandMask);
void FUN_08240cf0(s32 x, s32 z, s16 param_3, s32 param_4, u8 param_5, u16 param_6);
void FUN_080ee2c8(Enemy* p);
void FUN_080ee538(Enemy* p);
void FUN_080ee738(Enemy* p);
void FUN_080f0b3c(Enemy* p);
bool8 FUN_080e7078(Enemy* p);
s32 FUN_080dbcec(Vec3* pos, Vec3* param_2, Vec3* param_3, u32 param_4, u32 param_5, u32 param_6);

static inline void Enemy_EnterState(Enemy* p, void* handlerState, s32 state) {
  p->stateBegun = TRUE;
  p->subStateDone = 0;
  p->state = state;
  p->handlerState = handlerState;
  p->stateTimer = 0;
}

static inline void Enemy_SetSubStates(Enemy* p, u8 subState0, u8 subState1, u8 subState2) {
  p->subState0 = subState0;
  p->subState1 = subState1;
  p->subState2 = subState2;
}

// 下位状態を指定の組に戻して経過フレームを0に巻き戻す, subStateBegun は巻き戻した印
static inline void Enemy_ResetState(Enemy* p, u8 subState0, u8 subState1, u8 subState2) {
  p->subState0 = subState0;
  p->subState1 = subState1;
  p->subState2 = subState2;
  p->subStateTimer = 0;
  p->subStateBegun = 1;
}

static inline bool8 AuxSprite_TestFlags(AuxSprite* sprite, SpriteFlags bits) {
  if (sprite->flags & bits) return TRUE;
  return FALSE;
}

static inline bool8 MainSprite_TestFlags(MainSprite* sprite, SpriteFlags bits) {
  if (sprite->flags & bits) return TRUE;
  return FALSE;
}

static inline bool8 Enemy_TestSpriteFlags(Enemy* p, SpriteFlags bits) {
  if (p->spriteKind == 0) {
    return AuxSprite_TestFlags((AuxSprite*)p->sprite, bits);
  }
  return MainSprite_TestFlags(&p->sprite->s, bits);
}

static inline bool8 Enemy_TestFlag4(Enemy* p, EnemyFlags4 bit) {
  if (p->flags4 & bit) {
    return TRUE;
  }
  return FALSE;
}

// スプライトの座標を指す, spriteKind で AuxSprite か MainSprite かが変わる
static inline Vec3* Enemy_GetSpritePos(Enemy* p) {
  if (p->spriteKind == 0) {
    return &((AuxSprite*)p->sprite)->pos;
  }
  return &p->sprite->s.pos;
}

static inline bool8 Enemy_TestFlag5(Enemy* p, EnemyFlags5 bit) {
  if (p->flags5 & bit) {
    return TRUE;
  }
  return FALSE;
}

// 小さい敵 (クロロホルルン, バット, クロウ, ビー) かどうかを判定 (ただし、小さいことではなく別の共通点で判定している可能性もあるので、その場合はリネームする)
static inline bool8 IsSmallEnemy(Enemy* p) {
  if (p->kind >= ENEK_CURORO && p->kind <= ENEK_BEE) {
    return TRUE;
  }
  return FALSE;
}

// スプライトの座標を pos にする, spriteKind で AuxSprite か MainSprite かが変わる
static inline void Enemy_SetSpritePos(Enemy* p, WorldPos* pos) {
  if (p->spriteKind == 0) {
    ((AuxSprite*)p->sprite)->pos = *pos;
  } else {
    p->sprite->s.pos = *pos;
  }
}

// 索引 idx のタイルを返す, 上書きがあればそちらを返す
static inline CollisionMapTile* TileAtIndex(s32 idx) {
  MapTileOverride* ov = Map_FindTileOverride(idx, 1);

  if (ov != NULL) {
    return &ov->tile;
  }
  return &gCollisionMap->tiledata->tiles[idx];
}

// 索引 idx のタイルの高さを返す, 階段タイルなら上る向きの座標の端数ぶんだけ下げる
static inline u32 TileHeightAtIndex(s32 idx, WorldPos* pos) {
  CollisionMapTile* tile = TileAtIndex(idx);
  s32 stairs = tile->heightStairs >> 4;
  u32 height = (tile->heightStairs & 0xF) << 8;

  switch (stairs) {
    case STAIRS_VERTICAL: {
      height -= pos->z & 0xFF;
      break;
    }
    case STAIRS_HORIZONTAL: {
      height -= pos->x & 0xFF;
      break;
    }
  }
  return height;
}

// 索引 idx のタイルの中心の座標を pos に入れる, y はタイルの高さ
static inline void TilePosAtIndex(WorldPos* pos, s32 idx) {
  s32 x = Mod(idx, gCollisionMap->tiledata->width);
  s32 z = Div(idx, gCollisionMap->tiledata->width);

  pos->x = (x << 8) + 0x80;
  pos->y = (TileAtIndex(idx)->heightStairs & 0xF) << 8;
  pos->z = (z << 8) + 0x80;
}

// 経路の今のノードへ向かって一歩動けるか調べ, 動けなければ経路を外れたことにする
static inline bool8 Enemy_StepToward(Enemy* p, WorldPos* dst) {
  NavAgent* agent = p->navAgent;

  if (Map_IsPosInAgentIsland(agent, &p->mover.pos, dst)) {
    s32 result = FUN_08235f40(agent, &p->mover.pos, dst);

    if (result != 0) {
      if (result != 2) {
        ClearMemory(&p->mover.delta, 8);
      }
      return TRUE;
    }
  }
  Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
  return FALSE;
}

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

static inline bool8 IsLinkPlay(void) {
  if (gGameFlags & (FLAG030047A4_LINK | FLAG030047A4_UNK_14)) return TRUE;
  return FALSE;
}

static inline bool8 Enemy_TestUnk48c(Enemy* p) {
  if (p->unk_48c & 4) {
    return TRUE;
  }
  return FALSE;
}

// 活動停止のときに破棄対象の印を立てるか, 通信プレイ中は立てない
static inline bool8 Enemy_IsDisposable(Enemy* p) {
  if (IsLinkPlay()) {
    return FALSE;
  }
  if (p->kind == ENEK_SPIDER || p->kind == ENEK_BAT || p->kind == ENEK_CROW || p->kind == ENEK_CENTIPEDE || p->kind == ENEK_CURORO || p->kind == ENEK_BEE || p->kind == ENEK_OCTOPUS || p->kind == ENEK_MIMIC || p->kind == ENEK_GHOST || p->kind == ENEK_SLIME) {
    return TRUE;
  }
  return FALSE;
}

// 敵の毎フレームの共通処理, アニメを1コマ進め, 生きていれば移動と床合わせをして, 新しく踏んだタイルが氷なら状態22へ, 凍った溶岩ならダメージを控え, 経路を進めてゾーンイベントを更新する
// 700/702命令, AuxAnim の手動送りは AuxSprite_AdvanceAnim で揃った, 残差は &p->flags4 / &p->flags / &p->kind / &p->mover.pos を原典が分岐の両側でレジスタやスタックに作って持ち越す (PRE らしい) 点とフレーム 0x20 (こちらは 0x18)
// 試済: flags4 の立て方を |= 直書きにする, delta と prevPos の条件を1つの if にまとめる (どちらも悪化), FUN_080e35b4 も同じ &p->flags4 の持ち越しで止まっている
NON_MATCH s32 FUN_080e191c(Enemy* p) {
#ifdef NONMATCHING_C
  p->unk_46f = 1;
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_0)) {
    SET_FLAGS(p->flags3, ENEFLAG3_UNK_6);
  }

  if (p->animForceRestart != 1) {
    if (p->spriteKind == 0) {
      EnemyAuxSpriteData* aux = (EnemyAuxSpriteData*)p->sprite;

      p->animForceRestart = AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
    } else {
      MainSprite* s = &p->sprite->s;
      bool32 done = MainSprite_AdvanceAnim(s, &p->sprite->gfx);

      if ((s->animEvents & MAIN_ANIM_EVENT_WILL_END) || done) {
        p->animForceRestart = 1;
      }
    }
  }

  if (Enemy_IsDead(p)) {
    return 1;
  }
  FUN_080e4b3c(p);
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_13) && !Enemy_TestFlag5(p, ENEFLAG5_UNK_5)) {
    p->mover.tile = &p->moverTile;
  } else {
    p->mover.tile = NULL;
  }
  if (p->mover.delta.x != 0 || p->mover.delta.z != 0) {
    SET_FLAGS(p->flags4, ENEFLAG4_UNK_13);
  } else if (p->prevPos.x == p->mover.pos.x && p->prevPos.z == p->mover.pos.z) {
    SET_FLAGS(p->flags4, ENEFLAG4_UNK_13);
  }
  if (Enemy_TestFlag4(p, ENEFLAG4_UNK_13)) {
    Mover_ApplyMove(&p->mover);
  }
  p->prevTileIdx = p->unk_256;
  p->unk_256 = GetCollisionTileIdx(&p->mover.pos);
  Enemy_SnapToFloor(p);

  if (Enemy_TestFlag4(p, ENEFLAG4_UNK_13) && p->unk_256 != p->prevTileIdx && !IsSmallEnemy(p) && p->kind != ENEK_SERPENT) {
    TileAttr attr = TileAtIndex(p->unk_256)->attr;

    if ((attr & TATTR_FALLDEATH) && p->mover.pos.y + p->heightAboveFloor <= p->floorY) {
      if (!Enemy_IsDead(p)) {
        void* handler = p->unk_5d8;

        if (handler == NULL) {
          handler = FUN_080f54e4;
        }
        Enemy_EnterState(p, handler, 22);
        Enemy_ResetState(p, 3, 0, 0);
        SET_FLAGS(p->flags2, ENEFLAG2_UNK_17);
      }
    } else if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_HOT)) {
      WorldPos tilePos;
      Vec3 d;

      TilePosAtIndex(&tilePos, p->unk_256);
      Vec3_Diff(&d, &tilePos, &p->mover.pos);
      p->angle = ArcTan2_8(d.x, d.z) >> 5;
      p->unk_4a0 = 0x20;
      p->hitbox.damage = p->hp;
      p->unk_48a = p->hp;
      p->hitbox.knockbackPower = 40;
      p->weaponExpMask = 0x40;
      p->unk_48c = 1;
      SET_FLAGS(p->flags, ENEFLAG_UNK_13);
    } else {
      u16 tick;

      if (p->kind == ENEK_GOLEM && TEST_FLAGS(p->flags3, ENEFLAG3_UNK_8)) {
        SET_FLAGS(p->flags2, ENEFLAG2_UNK_16);
      }
      if (p->spriteKind == 0) {
        tick = ((EnemyAuxSpriteData*)p->sprite)->anim.tick;
      } else {
        tick = p->sprite->s.animCmdTimer;
      }
      if (tick == 0 && TEST_FLAGS(p->flags2, ENEFLAG2_UNK_16)) {
        Entity1DBE_TouchElemNear(&p->mover.pos);
        CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_16);
      }
    }
  }

  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_22)) {
    TileAttr attr = TileAtIndex(p->unk_256)->attr;

    if ((attr & (TATTR_UNK_0 | TATTR_WALL)) != (TATTR_UNK_0 | TATTR_WALL) && !(attr & (TATTR_FALLDEATH | TATTR_WALLISH))) {
      Map_StepNavPath(p->navAgent, &p->mover.pos);
    }
  }
  p->unk_1ca++;
  if (p->unk_544 != 0) {
    p->unk_544--;
  }
  if (!IsSmallEnemy(p)) {
    FUN_08234660(&p->zoneSource);
  }
  p->prevPos = p->mover.pos;
  CLEAR_FLAGS(p->flags4, ENEFLAG4_UNK_13);
  return 1;
#else
  INCFUNC("asm/func/FUN_080e191c.inc");
#endif
}

NAKED s32 FUN_080e1f48(Enemy* p) { INCFUNC("asm/func/FUN_080e1f48.inc"); }

// 毎フレームの当たり判定の出し入れ, 攻撃判定の登録, 点滅や攻撃対象の後始末をする
// 残差は218/248命令, 原典は同じ処理 (判定を隠して ENEFLAG4_UNK_14 を落とす) を分岐ごとに別々に持ち, &p->flags4 を r7, &p->kind を r9 に置いて後半まで持ち越すが, こちらは同じ処理が1つに畳まれる
// 試済: flags4 の落とし方を Enemy_ClearFlags4 / CLEAR_FLAGS にする (変化なし)
NON_MATCH s32 FUN_080e35b4(Enemy* p) {
#ifdef NONMATCHING_C
  p->unk_1d4 = 0;
  if (Enemy_IsDead(p)) {
    return 1;
  }

  if (Enemy_TestFlag5(p, ENEFLAG5_UNK_11)) {
    p->hitbox.flags |= HBFLAG_HIDDEN;
    p->flags4 &= ~ENEFLAG4_UNK_14;
  } else if (p->kind == ENEK_AX || p->kind == ENEK_GHOST) {
    p->flags4 &= ~ENEFLAG4_UNK_14;
  } else if ((u8)(p->state - 21) <= 1 || TEST_FLAGS(p->flags3, ENEFLAG3_UNK_15)) {
    p->hitbox.flags |= HBFLAG_HIDDEN;
    p->flags4 &= ~ENEFLAG4_UNK_14;
  } else if (!Enemy_TestFlag4(p, ENEFLAG4_UNK_14)) {
    p->hitbox.flags |= HBFLAG_HIDDEN;
  } else {
    p->hitbox.flags &= ~HBFLAG_HIDDEN;
    p->flags4 &= ~ENEFLAG4_UNK_14;
    if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_4 | ENEFLAG3_UNK_8) || (FUN_080e7078(p) && !TEST_FLAGS(p->flags3, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2))) {
      if (!(p->atkHitbox.flags & HBFLAG_HIDDEN)) {
        Hitbox_SetPos(&p->atkHitbox, &p->mover.pos, 0);
        Hitbox_Register(&p->atkHitbox);
      }
    }
    Hitbox_SetPos(&p->hitbox, &p->mover.pos, 0);
  }

  if (!IsSmallEnemy(p)) {
    if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_13)) {
      p->unk_48d = 0;
    } else {
      if (p->unk_4be != 0) {
        if (p->unk_4be & 4) {
          Enemy_SetFlag4(p, ENEFLAG4_UNK_5);
        }
        p->unk_4be--;
      }
      if (p->unk_48d != 0) {
        p->unk_48d--;
      }
    }
    if (p->target != NULL && !FUN_080f8d20(p->target)) {
      p->unk_5f0(p);
      p->target = NULL;
    }
  }
  return 1;
#else
  INCFUNC("asm/func/FUN_080e35b4.inc");
#endif
}

// 状態ハンドラに渡す引数と、スプライトの種類を差し替える
void FUN_080e37e8(Enemy* p, void* arg, u8 spriteKind) {
  p->unk_1cc = arg;
  p->spriteKind = spriteKind;
}

// AuxSprite 系のエネミーにアニメーションファイルを読み込ませて先頭から再生する
void EnemyAuxSprite_LoadAnim(EnemyAuxSpriteData* p, FileID animID) {
  p->animFile = GetFile(DIR_ANIMATION, animID);
  AuxAnim_SetAnim(&p->anim, p->animFile, 0, 0, 0);
}

// 自前の Hitbox を固定フラグで組んで登録する
void FUN_080e3834(Enemy* p, Vec3* halfSize, Vec3* offset, void* handler, void* owner) {
  Hitbox_Init(&p->hitbox, p->mover.id, (HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_ANGLE | HBFLAG_UNK_3 | HBFLAG_UNK_0), 0, 0x10, halfSize, offset);
  Hitbox_SetPowerAndAttributes(&p->hitbox, p->power, p->attrs, p->weakness);
  Hitbox_SetPos(&p->hitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(&p->hitbox, handler, owner);
  Hitbox_Register(&p->hitbox);
}

// 自前の Hitbox をフラグ指定で組んで登録する
void Enemy_RegisterOwnHitbox(Enemy* p, Vec3* halfSize, Vec3* offset, void* handler, void* owner, HitboxFlags32 flags) {
  Hitbox_Init(&p->hitbox, p->mover.id, (u16)flags, 0, 0x10, halfSize, offset);
  Hitbox_SetPowerAndAttributes(&p->hitbox, p->power, p->attrs, p->weakness);
  Hitbox_SetPos(&p->hitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(&p->hitbox, handler, owner);
  Hitbox_Register(&p->hitbox);
}

// 敵の攻撃力と属性を載せた Hitbox を組んで登録する
void Enemy_RegisterHitbox(Enemy* p, HitboxData* hitbox, Vec3* halfSize, Vec3* offset, void* handler, void* owner, HitboxFlags32 flags) {
  Hitbox_Init(hitbox, p->mover.id, (u16)flags, 0, 0x10, halfSize, offset);
  Hitbox_SetPowerAndAttributes(hitbox, p->power, p->attrs, p->weakness);
  Hitbox_SetPos(hitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(hitbox, handler, owner);
  Hitbox_Register(hitbox);
}

// 攻撃判定を組む, 攻撃パラメータは idx 番目の atk テーブルから取る (登録はしない)
void Enemy_InitAtkHitbox(Enemy* p, Vec3* halfSize, Vec3* offset, void* handler, s32 idx, void* owner) {
  HitboxFlags32 flags = HBFLAG_HITBOX | HBFLAG_UNK_10 | HBFLAG_UNK_0;

  Hitbox_Init(&p->atkHitbox, p->mover.id, flags, 0, 0x10, halfSize, offset);
  Hitbox_SetAttack(&p->atkHitbox, p->atkPower[idx], p->atkUnk40[idx], 0, p->atkAttrs[idx], p->atkInvincibleTime[idx]);
  Hitbox_SetPos(&p->atkHitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(&p->atkHitbox, handler, owner);
}

// index 番目の攻撃データを載せた Hitbox を組む (登録はしない)
void FUN_080e3a14(Enemy* p, HitboxData* hitbox, Vec3* halfSize, Vec3* offset, void* handler, s32 index, void* owner) {
  HitboxFlags32 flags = HBFLAG_HITBOX | HBFLAG_UNK_0;

  Hitbox_Init(hitbox, p->mover.id, flags, 0, 0x10, halfSize, offset);
  Hitbox_SetAttack(hitbox, p->atkPower[index], p->atkUnk40[index], 0, p->atkAttrs[index], p->atkInvincibleTime[index]);
  Hitbox_SetPos(hitbox, &p->mover.pos, 0);
  Hitbox_SetHandler(hitbox, handler, owner);
}

// 3つの距離しきい値を二乗つきで設定する, 第2引数は読まれない
void Enemy_SetRanges(Enemy* p, s32 _, u16 range0, u16 range1, u16 range2, u8 param_6) {
  p->playerMover = NULL;
  p->range0 = range0;
  p->range1 = range1;
  p->range2 = range2;
  p->range0Sq = range0 * range0;
  p->range1Sq = range1 * range1;
  p->range2Sq = p->range2 * p->range2;
  p->unk_1fd = param_6;
}

// pos の足元の索引 idx から dir の向きに隣のタイルへ, pos の高さ + 0xFF 以下で上がれるか
bool8 FUN_080e3afc(s32 dir, s32 idx, Vec3* pos) {
  Vec3 next;
  u32 limit = pos->y + 0xFF;

  switch (dir) {
    case 0: {
      idx += 1;
      TilePosAtIndex(&next, idx);
      break;
    }
    case 1: {
      idx += gCollisionMap->tiledata->width;
      TilePosAtIndex(&next, idx);
      break;
    }
    case 2: {
      idx -= 1;
      TilePosAtIndex(&next, idx);
      break;
    }
    case 3: {
      idx -= gCollisionMap->tiledata->width;
      TilePosAtIndex(&next, idx);
      break;
    }
  }

  if (TileHeightAtIndex(idx, &next) > limit) {
    return FALSE;
  }
  return TRUE;
}

// pos のタイルから dir の向きに count 個まで, 今より高くないタイルをたどって最後に乗れるタイルの索引を返す
s32 FUN_080e3cc8(Vec3* pos, s32 dir, s32 count) {
  s32 idx;
  s32 height;
  s32 cur;
  s32 i;
  s32 bx = (s8)(pos->x >> 8);
  s32 bz = (s8)(pos->z >> 8);

  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  height = (TileAtIndex(idx)->heightStairs & 0xF) << 8;
  cur = idx;

  switch (dir) {
    case 0: {
      for (i = 0; i < count; i++) {
        if (height - ((TileAtIndex(cur)->heightStairs & 0xF) << 8) < 0) {
          return cur - 1;
        }
        cur++;
      }
      cur--;
      return cur;
    }
    case 1: {
      for (i = 0; i < count; i++) {
        if (height - ((TileAtIndex(cur)->heightStairs & 0xF) << 8) < 0) {
          return cur - gCollisionMap->tiledata->width;
        }
        cur += gCollisionMap->tiledata->width;
      }
      cur -= gCollisionMap->tiledata->width;
      return cur;
    }
    case 2: {
      for (i = 0; i < count; i++) {
        if (height - ((TileAtIndex(cur)->heightStairs & 0xF) << 8) < 0) {
          return cur + 1;
        }
        cur--;
      }
      cur++;
      return cur;
    }
    case 3: {
      for (i = 0; i < count; i++) {
        if (height - ((TileAtIndex(cur)->heightStairs & 0xF) << 8) < 0) {
          return cur + gCollisionMap->tiledata->width;
        }
        cur -= gCollisionMap->tiledata->width;
      }
      cur += gCollisionMap->tiledata->width;
      return cur;
    }
  }
  return idx;
}

// a と b の距離をブロック数に直して FUN_080e3cc8 に渡し, 結果が expected と違うかどうかを返す
bool8 FUN_080e3ed8(Vec3* a, Vec3* b, s32 kind, s32 expected) {
  s32 n;

  switch (kind) {
    case 0:
    case 2: {
      n = FixToInt(8, abs(a->x - b->x) + 0x80) + 1;
      break;
    }
    case 1:
    case 3: {
      n = FixToInt(8, abs(a->z - b->z) + 0x80) + 1;
      break;
    }
    default: {
      n = 0;
      break;
    }
  }

  if (FUN_080e3cc8(a, kind, n) != expected) {
    return TRUE;
  }
  return FALSE;
}

// 今のタイルから dst のタイルへ段差を越えられるか調べる, 同じ高さなら 0, 1段下りなら 1, 上りで越えられれば 0 か 2 (2段目に届くとき), 越えられなければ -1
// 差分は Vec3_Diff で取ると d がスタックに置かれて 474/479 命令, FUN_080e3ed8 は呼び出し側が戻り値の下位8bitだけ見るので bool8
// 残差はレジスタ割当で, 原典は dstIdx をスタックに置き dst を r9, &b を r10 に持ち越して後の b の読み書きに使うが, こちらは dstIdx を r9 に置く
NON_MATCH s32 FUN_080e3f50(Enemy* p, WorldPos* pos, WorldPos* dst) {
#ifdef NONMATCHING_C
  s32 dstIdx = GetCollisionTileIdx(dst);
  s32 h0 = TileHeightAtIndex(p->unk_256, pos);
  s32 h1 = TileHeightAtIndex(dstIdx, dst);
  s32 result = 0;
  Vec3 delta;
  Vec3 a;
  Vec3 b;
  Vec3 d;
  s32 dh;
  s32 dir;

  if (h0 == h1) {
    return result;
  }
  if (h0 > h1) {
    Vec3_Diff(&delta, dst, pos);
    dh = h0 - h1;
    if (dh > 0xFF) {
      dh >>= 8;
      if (dh > 1) {
        return -1;
      }
      result = 1;
    }
    TilePosAtIndex(&a, p->unk_256);
    TilePosAtIndex(&b, dstIdx);
    a.y = h0;
    b.y = h1;
    Vec3_Diff(&d, &a, &b);
    if (!FUN_080e3afc(((ArcTan2_8(d.x, d.z) + 0x20) >> 6) & 3, dstIdx, &b)) {
      return -1;
    }
    Vec3_Diff(&d, &b, &a);
    dir = ((ArcTan2_8(d.x, d.z) + 0x20) >> 6) & 3;
    if (!FUN_080e3afc(dir, p->unk_256, &p->mover.pos)) {
      return -1;
    }
    if (FUN_080e3ed8(&a, &b, dir, dstIdx)) {
      return -1;
    }
  } else {
    dh = h1 - h0;
    if (dh > 0x17F) {
      return -1;
    }
    TilePosAtIndex(&a, p->unk_256);
    TilePosAtIndex(&b, dstIdx);
    a.y = h0;
    b.y = h1;
    Vec3_Diff(&d, &b, &a);
    dir = ((ArcTan2_8(d.x, d.z) + 0x20) >> 6) & 3;
    if (!FUN_080e3afc(dir, p->unk_256, &p->mover.pos)) {
      return -1;
    }
    if (FUN_080e3ed8(&b, &a, (dir + 2) & 3, p->unk_256)) {
      return -1;
    }
    if (dh > 0xFF) {
      result = 2;
    } else {
      pos->y = dst->y;
      result = 0;
    }
  }
  return result;
#else
  INCFUNC("asm/func/FUN_080e3f50.inc");
#endif
}

// pos が unk_256 のタイルの上にあり, かつ自分の向きから ±0x30 以内の方角にいるか
bool8 FUN_080e4384(Enemy* p, Vec3* pos) {
  Vec3 d;
  s32 idx = GetCollisionTileIdx(pos);
  s32 angle;
  s32 diff;

  if (p->unk_256 != idx) {
    return FALSE;
  }

  Vec3_Diff(&d, pos, &p->mover.pos);
  angle = p->mover.angle;
  diff = ArcTan2_8(d.x, d.z) - angle;
  if (diff > 0x80) {
    diff -= 0x100;
  } else if (diff < -0x80) {
    diff += 0x100;
  }
  if (abs(diff) <= 0x30) {
    return TRUE;
  }
  return FALSE;
}

// 1P が見える範囲 (向きの差が unk_1fd 以内で range0Sq 以内, 隣のタイルか段差を越えて見通せる) にいれば playerMover に入れて 1P の Mover を返す
// 床の判定を bool8 を返す static inline (属性は TileAttr を返す inline 経由), 隣接の4方向を (cur, dir, tile, height) の inline で書くと 521/518 命令
// 残差は隣接4方向の後半が原典では1か所に飛び込んで共有される (こちらは別々), found / near の割当, 見つけたときの後始末がこちらは else 側と共有される点
NON_MATCH Mover* FUN_080e4444(Enemy* p) {
#ifdef NONMATCHING_C
  Mover* found = NULL;
  Player* pl = gPlayerPtr[0];
  Vec3 d;
  Vec3 pos;
  s32 diff;
  s32 distSq;
  s32 limit;
  s32 near;
  s32 tile;
  s32 cur;
  s32 height;
  bool8 adjacent;
  bool32 isMini;

  if (pl == NULL) {
    return NULL;
  }
  if (pl->flag20 & PFLAG20_INVISIBLE) {
    return NULL;
  }
  if (pl->flag20 & PFLAG20_UNK_12) {
    return NULL;
  }
  if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_3)) {
    return NULL;
  }
  CLEAR_FLAGS(p->flags, ENEFLAG_UNK_3);

  pos = p->mover.pos;
  Vec3_Diff(&d, &pl->mover.pos, &pos);
  diff = ArcTan2_8(d.x, d.z) - p->mover.angle;
  if (diff > 0x80) {
    diff -= 0x100;
  } else if (diff < -0x80) {
    diff += 0x100;
  }
  if (FUN_080e4384(p, &pl->mover.pos)) {
    p->unk_1f8 = 1;
    p->playerMover = &pl->mover;
    return &pl->mover;
  }
  if (abs(diff) > p->unk_1fd) {
    return NULL;
  }

  distSq = d.x * d.x + d.z * d.z;
  isMini = gGoodCondTimer != 0 && gGoodCondID == GOOD_MINI;
  if (isMini || !TestMapFlag(MPF_BRIGHT)) {  // プレイヤーが小さい or マップが暗い時は敵の視認距離を短くする
    limit = p->range0Sq >> 1;
    if (Enemy_TestFlag5(p, ENEFLAG5_UNK_3)) {
      near = limit;
    } else {
      near = Div(limit * 7, 10);
    }
  } else {
    limit = p->range0Sq;
    near = p->unk_1e8;
  }
  if (distSq > limit) {
    return NULL;
  }
  if (distSq > 0x7FFFFFFF) {
    return NULL;
  }

  tile = pl->mover.tile->tileIdx[1];
  cur = p->unk_256;
  height = (s8)(p->mover.pos.y >> 8);
  adjacent = FALSE;
  if (tile - 1 == cur || tile == cur + gCollisionMap->tiledata->width || tile + 1 == cur || tile == cur - gCollisionMap->tiledata->width) {
    if ((TileAtIndex(tile)->heightStairs & 0xF) == height && !(TileAtIndex(tile)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
      adjacent = TRUE;
    }
  }

  if (adjacent) {
    found = &pl->mover;
    if (!Enemy_TestFlag5(p, ENEFLAG5_UNK_3)) {
      if (!Map_IsPosInAgentIsland(p->navAgent, &p->mover.pos, &found->pos)) {
        return NULL;
      }
    }
    p->unk_1f8 = 1;
    p->playerMover = found;
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    return found;
  } else {
    s32 step = FUN_080e3f50(p, &pos, &pl->mover.pos);
    u8 visible;
    bool8 flag;

    if (step < 0) {
      return NULL;
    }
    if (step == 2) {
      visible = 1;
    } else {
      visible = FUN_082340c8(&pos, &pl->mover.pos, 10, 0x100);
    }
    flag = Enemy_TestFlag5(p, ENEFLAG5_UNK_3);
    if (!flag && (step == 2 || distSq > near)) {
      p->unk_1f8 = flag;
    } else {
      p->unk_1f8 = 1;
    }
    if (visible == 1) {
      found = &pl->mover;
    }
    if (found != NULL) {
      if (!Enemy_TestFlag5(p, ENEFLAG5_UNK_3)) {
        if (!Map_IsPosInAgentIsland(p->navAgent, &p->mover.pos, &found->pos)) {
          return NULL;
        }
      }
      p->playerMover = found;
      Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    }
    return found;
  }
#else
  INCFUNC("asm/func/FUN_080e4444.inc");
#endif
}

// 入場フラグを食うだけの状態ハンドラ, 入場処理は何もしない
void Enemy_ClearStateBegun(Enemy* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
}

// HP と状態を初期化して入場フラグだけ立てたハンドラに差し替える
void FUN_080e48e8(Enemy* p, s32 hp, s32 param_3, s32 param_4) {
  p->flags3 = 0;
  p->handlerState = Enemy_ClearStateBegun;
  p->stateBegun = TRUE;
  p->subStateDone = 0;
  p->hp = hp;
  p->unk_192 = 0;

  if (param_4 <= 0) {
    param_4 = param_3;
  }

  p->unk_18e = param_3;
  p->unk_190 = param_4;
  p->unk_21c = 0;
  p->emote = NULL;
  p->zoneID = 0;
}

// 状態タイマーを進めて, 進める前の値を渡して状態ハンドラを呼ぶ
void Enemy_RunStateHandler(Enemy* p) {
  u16 prev;

  p->subStateDone = 0;
  prev = p->stateTimer++;
  if (p->handlerState != NULL) {
    ((void (*)(Enemy*, u16))p->handlerState)(p, prev);
  }
}

void FUN_080e499c(Enemy* p) {
  p->hitbox.damage = 0;
  p->unk_48a = 0;
  p->unk_48c = 0;
}

// 敵を活動停止させる, 種族が特定の10種なら破棄対象の印も立てる
void FUN_080e49c4(Enemy* p) {
  Enemy_SetFlag(p, ENEFLAG_UNK_0 | ENEFLAG_UNK_1);
  p->hitbox.flags |= HBFLAG_HIDDEN;
  FUN_080eeee0(p);
  if (Enemy_GetFlag2(p, ENEFLAG2_UNK_11)) {
    if (Enemy_IsDisposable(p)) {
      Enemy_SetFlag4(p, ENEFLAG4_UNK_12);
    }
  }
}

// 姿を見せて「数えない敵」の印を落とす
void FUN_080e4a68(Enemy* p) {
  Enemy_ClearFlag(p, ENEFLAG_UNK_0 | ENEFLAG_UNK_1);
  Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
}

// a から b へ向かう速度ベクトルと向きを出す, 両軸の距離がどちらも範囲内なら TRUE
bool32 FUN_080e4aac(Vec3* a, Vec3* b, Vec3* out, u8* outAngle, u32 rangeX, u32 rangeZ, s32 speed) {
  s16 dx = b->x - a->x;
  s16 dz = b->z - a->z;
  u8 angle = ArcTan2_8(dx, dz);
  s32 d;

  out->x = (speed * COS(angle)) >> 16;
  out->z = (speed * SIN(angle)) >> 16;
  *outAngle = angle;

  d = abs(a->x - b->x);
  if ((u32)d > rangeX) {
    return FALSE;
  }
  d = abs(a->z - b->z);
  if ((u32)d > rangeZ) {
    return FALSE;
  }
  return TRUE;
}

// 跳ねている間の更新, 重力で落として着地したら跳ね返りを弱め, 止まったら TRUE
// 残差は341/341命令で並びだけ, 原典は落下側の TileAtIndex の上書きが無いときの塊を ENEFLAG2_UNK_20 側の後ろへ置く
// 速さの2乗の和を Vec3* を受ける inline, 2つの CpuFill32 を Vec3* を受ける inline にすると (一時変数のスタックを共有して 0x14 になる), flags2 を Enemy_GetFlag2 / Enemy_SetFlag2 にすると残りはこの並びだけになる
NON_MATCH bool8 FUN_080e4b3c(Enemy* p) {
#ifdef NONMATCHING_C
  if (p->jumpVel.x * p->jumpVel.x + p->jumpVel.y * p->jumpVel.y + p->jumpVel.z * p->jumpVel.z == 0 && p->heightAboveFloor == 0) {
    CLEAR_FLAGS(p->flags2, ENEFLAG2_UNK_4);
    return TRUE;
  }

  if (p->kind != ENEK_COCKA) {
    SET_FLAGS(p->flags, ENEFLAG_UNK_13);
  }
  if (!Enemy_GetFlag2(p, ENEFLAG2_UNK_20)) {
    s32 height;
    s32 y;

    p->jumpVel.y -= 2;
    p->heightAboveFloor += p->jumpVel.y;
    p->mover.delta.x += p->jumpVel.x;
    p->mover.delta.z += p->jumpVel.z;
    height = TileHeightAtIndex(p->unk_256, &p->mover.pos);
    y = p->heightAboveFloor + height;
    if (y <= height) {
      Vec3 range;

      range.x = 0x52, range.y = 0, range.z = 0x52;
      if (p->unk_1bc == 0) {
        CpuFill32(0, &p->jumpVel, sizeof(p->jumpVel));
        p->heightAboveFloor = 0;
      } else {
        p->jumpVel.x = Div(p->jumpVel.x * 5, 10);
        p->jumpVel.y = Div(abs(p->jumpVel.y) * p->unk_1bc, 10);
        p->jumpVel.z = Div(p->jumpVel.z * 5, 10);
      }
      if (p->kind != ENEK_CURORO && p->kind != ENEK_GHOST && p->kind != ENEK_CROW && p->kind != ENEK_BAT && p->kind != ENEK_SANDWORM && p->kind != ENEK_OCTOPUS && p->kind != ENEK_SERPENT && p->kind != ENEK_AX && p->kind != ENEK_31) {
        FUN_080dbcec(&p->mover.pos, &p->jumpVel, &range, 6, 2, 4);
      }
      if (p->unk_5b4 != NULL) {
        p->unk_5b4(p);
      }
      p->heightAboveFloor = 0;
    }
    if (p->jumpVel.x * p->jumpVel.x + p->jumpVel.y * p->jumpVel.y + p->jumpVel.z * p->jumpVel.z == 0 && p->heightAboveFloor == 0) {
      p->heightAboveFloor = 0;
      CpuFill32(0, &p->jumpVel, sizeof(p->jumpVel));
      Enemy_SetFlag2(p, ENEFLAG2_UNK_4);
      return TRUE;
    }
  } else {
    if (Mod(p->unk_1ca, 4) == 0) {
      p->jumpVel.x = FixToInt(1, p->jumpVel.x);
      p->jumpVel.z = FixToInt(1, p->jumpVel.z);
    }
    p->mover.delta.x += p->jumpVel.x;
    p->mover.delta.z += p->jumpVel.z;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080e4b3c.inc");
#endif
}

// 床の高さ floorY を取り直し, ENEFLAG5_UNK_5 が無ければ mover.pos.y を床 + heightAboveFloor にしてスプライトの座標へ写す
void Enemy_SnapToFloor(Enemy* p) {
  if (p->kind == ENEK_SLIME) {
    u32 height = TileHeightAtIndex(p->unk_256, &p->mover.pos);

    if (p->floorY != height) {
      p->heightAboveFloor -= height - p->floorY;
    }
    p->floorY = height;
  } else if (!Enemy_TestFlag3(p, ENEFLAG3_UNK_14) && IsSmallEnemy(p)) {
    p->floorY = gPlayerPtr[0]->mover.pos.y;
  } else {
    p->floorY = TileHeightAtIndex(p->unk_256, &p->mover.pos);
  }

  if (!Enemy_TestFlag5(p, ENEFLAG5_UNK_5)) {
    p->mover.pos.y = p->floorY;
    p->mover.pos.y += p->heightAboveFloor;
  }
  if (p->spriteKind == 0) {
    ((AuxSprite*)p->sprite)->pos = p->mover.pos;
  } else {
    p->sprite->s.pos = p->mover.pos;
  }
}

// 床に着いたら縦の速さを半分にして跳ねさせる, 十分小さくなったら止めて 1 を返す
s32 FUN_080e4f90(Enemy* p, Vec3* vel) {
  Mover* mover = &p->mover;

  p->mover.delta.x = vel->x;
  p->mover.delta.z = vel->z;
  if (p->mover.pos.y <= TileHeightAtIndex(p->unk_256, &p->mover.pos)) {
    Vec3 dir, size;
    vel->y = Div(abs(vel->y) * 5, 10);
    if (vel->y <= 3) {
      vel->x = 0;
      vel->y = 0;
      vel->z = 0;
      return 1;
    }

    dir.x = -mover->delta.x, dir.y = 0, dir.z = -mover->delta.z;
    size.x = Q8(0.321), size.y = 0, size.z = Q8(0.321);
    FUN_080dbcec(&mover->pos, &dir, &size, 12, 3, 4);
    Enemy_SetFlag2(p, ENEFLAG2_UNK_4);
  }
  return 0;
}

// angle 方向へ伸ばした点を unk_20c に, 現在位置の控えを unk_214 に入れる
void FUN_080e5098(Enemy* p, s32 dx, s32 dz) {
  s32 ax = dx << 2;
  s32 az = dz << 2;

  p->unk_20c.x = ((ax * COS(p->angle)) >> 12) + p->mover.pos.x;
  p->unk_20c.y = p->mover.pos.y;
  p->unk_20c.z = ((az * SIN(p->angle)) >> 12) + p->mover.pos.z;
  p->unk_214 = p->mover.pos;
}

// 種族 enemyKind の鳴き声のうち type (0..3) 番目を鳴らす
void PlayEnemyEmoteCry(u8 emoteVariant, u8 enemyKind, u8 enemyVariant) {
  switch (enemyKind) {
    case ENEK_BOKU:
    case ENEK_28: {
      switch (emoteVariant) {
        case 0:
        case 3: {
          PlaySound_082406e0(CRY_BOKU_ALERT);
          break;
        }
        case 1: {
          PlaySound_082406e0(CRY_BOKU_DETECT);
          break;
        }
        case 2: {
          PlaySound_082406e0(CRY_BOKU_QUESTION);
          break;
        }
      }
      break;
    }
    case ENEK_MUMMY: {
      switch (emoteVariant) {
        case 0:
        case 3: {
          PlaySound_082406e0(CRY_MUMMY_ALERT);
          break;
        }
        case 1: {
          PlaySound_082406e0(CRY_MUMMY_DETECT);
          break;
        }
        case 2: {
          PlaySound_082406e0(CRY_MUMMY_QUESTION);
          break;
        }
      }
      break;
    }
    case ENEK_GOLEM:
    case ENEK_30: {
      switch (emoteVariant) {
        case 0:
        case 3: {
          switch (enemyVariant) {
            case 0:
            case 1:
            case 3:
            case 5: {
              PlaySound_082406e0(CRY_GOLEM_ALERT);
              break;
            }
          }
          break;
        }
        case 1: {
          switch (enemyVariant) {
            case 0:
            case 1:
            case 3:
            case 5: {
              PlaySound_082406e0(CRY_GOLEM_DETECT);
              break;
            }
          }
          break;
        }
        case 2: {
          switch (enemyVariant) {
            case 0:
            case 1:
            case 3:
            case 5: {
              PlaySound_082406e0(CRY_GOLEM_391);
              break;
            }
          }
          break;
        }
      }
      break;
    }
    case ENEK_COCKA: {
      switch (emoteVariant) {
        case 0:
        case 3: {
          PlaySound_082406e0(CRY_COCKA_456);
          break;
        }
        case 1: {
          PlaySound_082406e0(CRY_COCKA_455);
          break;
        }
        case 2: {
          PlaySound_082406e0(CRY_COCKA_457);
          break;
        }
      }
      break;
    }
    case ENEK_DOG: {
      switch (emoteVariant) {
        case 0:
        case 3: {
          PlaySound_082406e0(CRY_DOG_ALERT);
          break;
        }
        case 1: {
          PlaySound_082406e0(CRY_DOG_DETECT);
          break;
        }
        case 2: {
          PlaySound_082406e0(SE_QUESTION);
          break;
        }
      }
      break;
    }
    case ENEK_MIMIC: {
      switch (emoteVariant) {
        case 0:
        case 3: {
          PlaySound_082406e0(CRY_MIMIC_ALERT);
          break;
        }
        case 1: {
          PlaySound_082406e0(CRY_MIMIC_ALERT);
          break;
        }
        case 2: {
          PlaySound_082406e0(CRY_MIMIC_QUESTION);
          break;
        }
      }
      break;
    }
    case ENEK_SKELETON:
    case ENEK_SKELETON_F:
    case ENEK_SKELETON_A:
    case ENEK_LICH: {
      switch (emoteVariant) {
        case 0:
        case 3: {
          PlaySound_082406e0(SE_DETECT);
          break;
        }
        case 1: {
          PlaySound_082406e0(SE_ALERT);
          break;
        }
        case 2: {
          PlaySound_082406e0(SE_QUESTION);
          break;
        }
      }
      break;
    }
    case ENEK_GHOST: {
      switch (emoteVariant) {
        case 0:
        case 3: {
          PlaySound_082406e0(SE_DETECT);
          break;
        }
        case 1: {
          PlaySound_082406e0(SE_ALERT);
          break;
        }
        case 2: {
          PlaySound_082406e0(SE_QUESTION);
          break;
        }
      }
      break;
    }
  }
}

void FUN_080e5388(u8 emoteType, u8 emoteVariant, u8 enemyKind, u8 enemyVariant) {
  if (emoteType == 0) {
    PlayEnemyEmoteCry(emoteVariant, enemyKind, enemyVariant);
  }
}

void FUN_080e53a8(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 400, *outY = 320;
      break;
    }
    case 1: {
      *outX = 0, *outY = 340;
      break;
    }
    case 2: {
      *outX = 0, *outY = 260;
      break;
    }
    case 3: {
      *outX = 0, *outY = 260;
      break;
    }
  }
}

void FUN_080e53ec(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 470, *outY = 390;
      break;
    }
    case 1: {
      *outX = 0, *outY = 310;
      break;
    }
    case 2: {
      *outX = 0, *outY = 260;
      break;
    }
    case 3: {
      *outX = 0, *outY = 240;
      break;
    }
  }
}

void FUN_080e5438(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 400, *outY = 320;
      break;
    }
    case 1: {
      *outX = 0, *outY = 340;
      break;
    }
    case 2: {
      *outX = 0, *outY = 260;
      break;
    }
    case 3: {
      *outX = 0, *outY = 260;
      break;
    }
  }
}

void FUN_080e547c(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 400, *outY = 320;
      break;
    }
    case 1: {
      *outX = 0, *outY = 340;
      break;
    }
    case 2: {
      *outX = 0, *outY = 260;
      break;
    }
    case 3: {
      *outX = 0, *outY = 390;
      break;
    }
  }
}

void FUN_080e54c8(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 360, *outY = 280;
      break;
    }
    case 1: {
      *outX = 0, *outY = 260;
      break;
    }
    case 2: {
      *outX = 0, *outY = 210;
      break;
    }
    case 3: {
      *outX = 0, *outY = 260;
      break;
    }
  }
}

void FUN_080e5508(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 390, *outY = 310;
      break;
    }
    case 1: {
      *outX = 0, *outY = 320;
      break;
    }
    case 2: {
      *outX = 0, *outY = 260;
      break;
    }
    case 3: {
      *outX = 0, *outY = 260;
      break;
    }
  }
}

void FUN_080e554c(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 390, *outY = 310;
      break;
    }
    case 1: {
      *outX = 0, *outY = 320;
      break;
    }
    case 2: {
      *outX = 0, *outY = 260;
      break;
    }
    case 3: {
      *outX = 0, *outY = 260;
      break;
    }
  }
}

void FUN_080e5590(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 250, *outY = 200;
      break;
    }
    case 1: {
      *outX = 0, *outY = 340;
      break;
    }
    case 2: {
      *outX = 0, *outY = 260;
      break;
    }
    case 3: {
      *outX = 0, *outY = 260;
      break;
    }
  }
}

void FUN_080e55d0(u8 dir, s32* outX, s32* outY) {
  switch (dir) {
    case 0: {
      *outX = 190, *outY = 120;
      break;
    }
    case 1: {
      *outX = 0, *outY = 340;
      break;
    }
    case 2: {
      *outX = 0, *outY = 260;
      break;
    }
    case 3: {
      *outX = 0, *outY = 260;
      break;
    }
  }
}

// 種族ごとの表から, 向きに応じて Enemy_SetEmote が使う2つの値を引く
void FUN_080e5610(u8 enemyKind, u8 dir, s32* outX, s32* outY) {
  switch (enemyKind) {
    case ENEK_BOKU:
    case ENEK_28: {
      FUN_080e53a8(dir, outX, outY);
      break;
    }
    case ENEK_MUMMY: {
      FUN_080e53ec(dir, outX, outY);
      break;
    }
    case ENEK_GOLEM:
    case ENEK_30: {
      FUN_080e54c8(dir, outX, outY);
      break;
    }
    case ENEK_COCKA: {
      FUN_080e5508(dir, outX, outY);
      break;
    }
    case ENEK_MIMIC: {
      FUN_080e5590(dir, outX, outY);
      break;
    }
    case ENEK_SKELETON:
    case ENEK_SKELETON_F:
    case ENEK_SKELETON_A:
    case ENEK_LICH: {
      FUN_080e5438(dir, outX, outY);
      break;
    }
    case ENEK_DOG: {
      FUN_080e554c(dir, outX, outY);
      break;
    }
    case ENEK_GHOST: {
      FUN_080e55d0(dir, outX, outY);
      break;
    }
    case ENEK_SHAIAN: {
      FUN_080e547c(dir, outX, outY);
      break;
    }
  }
}

// 感情表現 (0-3) を出し直す, 第3引数が 0x7F なら消す
// 感情アイコン emote を種類 variant で出す (0x7F なら消す), 位置は種族 kind ごとの表から引く
// 残差は299/296命令でレジスタ割当のずれ, 原典は emote を r6 のまま使い (こちらは r10 に退避), &p->emote を r6, variant を r8, kind を r7 に置く
// ENEFLAG2_UNK_9 の 0/1 は Enemy_GetFlag2(p, X) != 0 で rsbs/lsrs の形に揃う, 試済: case 1 の FUN_080e5388 の第1引数を 1 / emote, case 3 の既定値を三項演算子 / if
NON_MATCH void Enemy_SetEmote(Enemy* p, u8 emote, u8 variant, u8 kind) {
#ifdef NONMATCHING_C
  Mover* mover = &p->mover;
  s32 x;
  s32 y;

  if (variant == 0x7F) {
    switch (emote) {
      case 0: {
        p->emote = Emote_Remove(p->emote, 0, p->mover.id);
        break;
      }
      case 1: {
        p->emote = Emote_Remove(p->emote, 1, p->mover.id);
        break;
      }
      case 3: {
        p->emote = Emote_RemovePtcl(p->emote, 3, p->mover.id);
        break;
      }
      case 2: {
        p->emote = Emote_Remove(p->emote, 2, p->mover.id);
        break;
      }
    }
    return;
  }

  switch (emote) {
    case 0: {
      p->emote = Emote_Remove(p->emote, 0, p->mover.id);
      p->emote = Emote_Remove(p->emote, 1, p->mover.id);
      p->emote = Emote_Remove(p->emote, 2, p->mover.id);
      FUN_080e5610(kind, 0, &x, &y);
      if (variant == 0 && TEST_FLAGS(p->flags2, ENEFLAG2_UNK_15)) {
        variant = 3;
      }
      p->emote = FUN_080d9b3c(variant, &mover->pos, mover->id, x, y, kind, p, mover);
      FUN_080e5388(emote, variant, kind, p->variant);
      if (variant == 0) {
        FUN_08240cf0(p->mover.pos.x, p->mover.pos.z, p->unk_1fe, 0, 1, mover->id);
      }
      break;
    }
    case 1: {
      if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_1)) {
        break;
      }
      p->emote = Emote_Remove(p->emote, 0, p->mover.id);
      p->emote = Emote_Remove(p->emote, 1, p->mover.id);
      p->emote = Emote_Remove(p->emote, 2, p->mover.id);
      if (!Emote_IsInactive(p->emote)) {
        break;
      }
      FUN_080e5610(kind, 1, &x, &y);
      p->emote = FUN_080d9cec(variant, &p->mover.pos, p->mover.id, x, y, kind, &p->unk_192, p->unk_190, Enemy_GetFlag2(p, ENEFLAG2_UNK_9) != 0, p, &p->mover);
      FUN_080e5388(emote, variant, kind, p->variant);
      break;
    }
    case 2: {
      FUN_080e5610(kind, 2, &x, &y);
      p->emote = FUN_080d9f5c(1, &p->mover.pos, p->mover.id, y, kind, &p->mover);
      break;
    }
    case 3: {
      p->emote = Emote_Remove(p->emote, 0, p->mover.id);
      p->emote = Emote_Remove(p->emote, 1, p->mover.id);
      p->emote = Emote_Remove(p->emote, 2, p->mover.id);
      p->emote = Emote_RemovePtcl(p->emote, 3, p->mover.id);
      FUN_080e5610(kind, 3, &x, &y);
      p->emote = FUN_080da6c4(7, &p->mover.pos, p->mover.id, y, kind, &p->unk_192, p->unk_190, variant ? variant : 3, &p->mover, p);
      break;
    }
  }
#else
  INCFUNC("asm/func/Enemy_SetEmote.inc");
#endif
}

// pathWalker を初期化する
void FUN_080e59c4(Enemy* p, u32 pathIdx, u32 param_3, u32 nodeIdx) { Map_InitPathWalker(&p->pathWalker, pathIdx, param_3, nodeIdx); }

// msg[0] が 0 なら活動停止から復帰, 1 なら復帰しつつ FUN_080ee538, それ以外は停止中なら FUN_080ee738, 1回だけ受け付ける
// 残差は157/157命令のレジスタ順列だけ, 原典は p を r4, 0x800 を r5, 0 を r6, msg[0] を r7, flags3 の検査結果を r8 に置くが, こちらは1つずつずれる
// 試済: Enemy_TestFlag3 / 素の & / Enemy_SetFlag3 / msg[0] や検査結果のローカル / if-else の連鎖, いずれも同じか悪化
NON_MATCH void FUN_080e59d0(Enemy* p, u16* msg) {
#ifdef NONMATCHING_C
  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_11)) {
    return;
  }
  SET_FLAGS(p->flags3, ENEFLAG3_UNK_11);

  switch (msg[0]) {
    case 0: {
      if (Enemy_TestFlag(p, ENEFLAG_UNK_0)) {
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_0 | ENEFLAG_UNK_1);
        FUN_080ee2c8(p);
        Enemy_SetSubStates(p, 3, 0, 0);
        p->subStateTimer = 0;
        p->subStateBegun = 1;
        Enemy_EnterState(p, p->unk_584, 12);
      }
      break;
    }
    case 1: {
      if (!Enemy_IsDead(p)) {
        CLEAR_FLAGS(p->flags, ENEFLAG_UNK_0 | ENEFLAG_UNK_1);
        FUN_080ee538(p);
        Enemy_SetSubStates(p, 3, 0, 0);
        p->subStateTimer = 0;
        p->subStateBegun = 1;
        Enemy_EnterState(p, p->unk_584, 12);
      }
      break;
    }
    default: {
      if (Enemy_TestFlag(p, ENEFLAG_UNK_0)) {
        FUN_080ee738(p);
        p->hitbox.invincibleTime = 0;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_080e59d0.inc");
#endif
}

// 活動停止中なら, 経路 pathIdx のノード nodeIdx に向き angle で置き直して状態12で活動を再開させる
void FUN_080e5b2c(Enemy* p, s32 pathIdx, s32 nodeIdx, s32 angle) {
  Mover* mover = &p->mover;

  if (!TEST_FLAGS(p->flags, ENEFLAG_UNK_0)) {
    return;
  }

  p->flags &= ~(ENEFLAG_UNK_0 | ENEFLAG_UNK_1);
  p->prevPathNode = p->unk_252;
  Map_GetPathNodePos(&p->mover.pos, pathIdx, nodeIdx);
  p->unk_256 = GetCollisionTileIdx(&p->mover.pos);
  mover->pos.y = TileHeightAtIndex(p->unk_256, &p->mover.pos);
  Enemy_SetSpritePos(p, &mover->pos);
  mover->angle = angle;
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
  p->hitbox.flags &= ~HBFLAG_HIDDEN;
  Enemy_SetSpriteFlags(p, SPRFLAG_AFFINE);
  Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
  Enemy_ResetState(p, 3, 0, 0);
  Enemy_EnterState(p, p->unk_584, 12);
}

// mover.angle を 4方向に丸めて, 左右反転とコマ番号に振り分ける
// 残差1命令, 原典は dir を別レジスタへ複写してから比較に使うが agbcc は複写せず同じレジスタで済ませる (命令列は 29 対 30)
NON_MATCH void Enemy_SetAnimFacing(Enemy* p, u8* variant, AuxAnimPlayFlags* flags) {
#ifdef NONMATCHING_C
  u32 dir = ((((p->mover.angle + 0x20) & 0xFF) >> 6) + 1) & 3;

  p->facing = dir;
  if (dir > 1) {
    *flags = ANIM_PLAY_XFLIP;
    *variant = 3 - dir;
  } else {
    *flags = 0;
    *variant = dir;
  }
#else
  INCFUNC("asm/func/Enemy_SetAnimFacing.inc");
#endif
}

// (dx, dz) の長さを dx / cos から出す, 真横は cos が 0 になるので |dz| で代用する
s16 VectorLength(s16 dx, s16 dz) {
  s32 angle = (u8)ArcTan2_8(dx, dz);
  s32 d;

  if (angle == 0x40 || angle == 0xC0) {
    return abs(dz);
  }

  d = Div(dx << 12, COS(angle));
  return abs(d);
}

// 種族によって影とパーティクルを持たせるかどうかを決める
void Enemy_Init_080e5dd4(Enemy* p) {
  if (p->kind == ENEK_CURORO || p->kind == ENEK_GHOST || p->kind == ENEK_CENTIPEDE || p->kind == ENEK_SANDWORM || p->kind == ENEK_SERPENT || p->kind == ENEK_OCTOPUS || p->kind == ENEK_SHAIAN || p->kind == ENEK_DARKROOT || p->kind == ENEK_31) {
    p->unk_44c = 1;
  } else {
    p->unk_44c = ParticleShadow_Init(&p->shadow, &p->mover.pos, 0);
  }

  if (p->kind == ENEK_BOKU || p->kind == ENEK_28 || p->kind == ENEK_SKELETON || p->kind == ENEK_SKELETON_F || p->kind == ENEK_SKELETON_A || p->kind == ENEK_MUMMY || p->kind == ENEK_GOLEM || p->kind == ENEK_30 || p->kind == ENEK_COCKA) {
    Eff082473e0Emitter_Init(&p->emitter, &p->mover.pos, 0, 0, 0);
    p->unk_44d = 0;
  } else {
    p->unk_44d = 1;
  }
}

// pos が自分の位置を中心とした rx × rz の矩形に入っているか
bool8 Enemy_IsPosInRect(Enemy* p, WorldPos* pos, u32 rx, u32 rz) {
  s16 dx = pos->x - p->mover.pos.x;
  s16 dz = pos->z - p->mover.pos.z;

  if (abs(dx) <= rx && abs(dz) <= rz) {
    return TRUE;
  }
  return FALSE;
}

// 経路の目標に着いていれば TRUE, まだなら次の通過点 (unk_1c) の方を向いて speed ぶんの移動量を足す
bool8 FUN_080e5ed4(Enemy* p, NavAgent* agent, u32 rangeX, u32 rangeZ, s32 speed) {
  s32 dx = agent->unk_1c.x - p->mover.pos.x;
  s32 dz = agent->unk_1c.z - p->mover.pos.z;

  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_12)) {
    if (!(agent->flags & 1) && dx * dx + dz * dz <= Q8(0.5) * Q8(0.5)) {
      return TRUE;
    }
  } else {
    if (abs(agent->unk_0c.x - p->mover.pos.x) <= rangeX && abs(agent->unk_0c.z - p->mover.pos.z) <= rangeZ) {
      return TRUE;
    }
  }

  if (dx != 0 || dz != 0) {
    s32 vx, vz;
    p->mover.angle = ArcTan2_8(dx, dz);
    vx = FixToInt(16, speed * COS(p->mover.angle));
    vz = FixToInt(16, speed * SIN(p->mover.angle));
    p->mover.delta.x += abs(vx) > 10 ? vx : 0;
    p->mover.delta.z += abs(vz) > 10 ? vz : 0;
  }
  return FALSE;
}

// 目標点に着いていれば TRUE, まだなら unk_1c の方角へ speed 分だけ delta を積む
bool32 FUN_080e5fe4(Enemy* p, NavAgent* agent, u32 rangeX, u32 rangeZ, s32 speed) {
  s16 dx = agent->unk_1c.x - p->mover.pos.x;
  s16 dz = agent->unk_1c.z - p->mover.pos.z;
  s32 d;

  d = abs(agent->unk_0c.x - p->mover.pos.x);
  if ((u32)d <= rangeX) {
    d = abs(agent->unk_0c.z - p->mover.pos.z);
    if ((u32)d <= rangeZ) {
      return TRUE;
    }
  }
  if (dx != 0 || dz != 0) {
    u32 angle = (u8)ArcTan2_8(dx, dz);

    p->mover.delta.x = p->unk_20c.x + FixToInt(16, speed * COS(angle)) + p->mover.delta.x;
    p->mover.delta.z = p->unk_20c.z + FixToInt(16, speed * SIN(angle)) + p->mover.delta.z;
    p->mover.angle = angle;
  }
  return FALSE;
}

// 目標点が範囲外で今の向きとも象限が違うとき, unk_1dc を目標のほうの8方向に更新して TRUE を返す
// 残差は70/71命令で1命令, 原典は quad * 64 を8bitに切り詰める (quad <= 3 と分かっていないので and が残る)
// Tier A-C 試済 (quad を u32/u8, (u8) キャスト / & 3 / u8 の中間変数)
NON_MATCH bool8 FUN_080e60b8(Enemy* p, NavAgent* agent, u32 rangeX, u32 rangeZ, s32 speed) {
#ifdef NONMATCHING_C
  s16 dx = agent->unk_1c.x - p->mover.pos.x;
  s16 dz = agent->unk_1c.z - p->mover.pos.z;
  s32 d;

  d = dx;
  if (d < 0) {
    d = -d;
  }
  if ((u32)d <= rangeX) {
    d = dz;
    if (d < 0) {
      d = -d;
    }
    if ((u32)d <= rangeZ) {
      return FALSE;
    }
  }

  if (dx != 0 || dz != 0) {
    u32 angle = ArcTan2_8(dx, dz);
    u8 quad = ((angle + 0x20) & 0xFF) >> 6;

    d = quad - (((p->mover.angle + 0x20) & 0xFF) >> 6);
    if (d < 0) {
      d = -d;
    }
    if (d != 0) {
      p->unk_1dc = (FixToInt(5, (u8)(quad * 64)) + 3) & 7;
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080e60b8.inc");
#endif
}

// 経路上の次のノードのほうが近ければ dst をそこへ差し替え, そこまで歩けるかを確かめる
void FUN_080e6148(NavAgent* agent, Enemy* p, Vec3* dst) {
  PathNode* node = p->mover.path->node;
  s32 dx = node->x - p->mover.pos.x;
  s32 dz = node->y - p->mover.pos.z;
  s32 toNode = VectorLength(dx, dz);
  s32 toDst;

  dx = dst->x - p->mover.pos.x;
  dz = dst->z - p->mover.pos.z;
  toDst = VectorLength(dx, dz);

  if (toNode <= toDst) {
    dst->x = p->mover.path->node->x;
    dst->y = 0;
    dst->z = p->mover.path->node->y;
  }

  if (!Map_IsPosInAgentIsland(agent, &p->mover.pos, dst)) {
    Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
  } else {
    s32 r = FUN_08235f40(agent, &p->mover.pos, dst);

    if (r != 0) {
      if (r != 2) {
        ClearMemory(&p->mover.delta, 8);
      }
    } else {
      Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
    }
  }
}

// 経路の今のノードの XZ に, 自分の高さを合わせた点へ一歩動く
void FUN_080e6204(Enemy* p) {
  WorldPos dst;
  WorldPos* d = &dst;
  PathWalker* walker = &p->pathWalker;

  d->x = walker->node->x;
  d->z = walker->node->y;
  d->y = TileHeightAt(d);
  dst.y = p->mover.pos.y;
  if (!Enemy_StepToward(p, &dst)) {
    FUN_081fa26c(&dst);
  }
}

// (x, z) の方を向かせる
void FUN_080e6304(Enemy* p, s16 x, s16 z) {
  s16 dx = x - p->mover.pos.x;
  s16 dz = z - p->mover.pos.z;

  p->mover.angle = ArcTan2_8(dx, dz);
}

// 残り n に応じた間隔でスプライトを点滅させる, 60 を超えていれば点滅をやめて TRUE
bool32 FUN_080e6330(Enemy* p, s32 n) {
  s32 idx = 0;

  if (n <= 30) {
    idx = (n > 10) ? 1 : 2;
  }

  if (Mod(n, s16_ARRAY_085ad3c4[idx]) == 0) {
    if (Enemy_TestSpriteFlags(p, SPRFLAG_HIDDEN)) {
      Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
    } else {
      Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
    }
  }

  if (n > 60) {
    Enemy_ClearSpriteFlags(p, SPRFLAG_HIDDEN);
    return TRUE;
  }
  return FALSE;
}

// 散らばり位置を乱数で振りながらパーティクルを count 個撒く
void FUN_080e6408(Enemy* p, s32 count, u32 kind, s32 rangeX, s32 rangeY, u32 param_6) {
  Vec3 spread;
  s32 i;

  spread.z = 0;
  spread.val = 0;
  for (i = 0; i < count; i++) {
    u16* table = gRandomTable;
    spread.x = Mod(_Random(table) >> 4, rangeX) - (rangeX >> 1);
    spread.y = -Mod(_Random(table) >> 3, rangeY) - 6;
    FUN_082467d0(&p->emitter, kind, param_6, &spread);
  }
}

// パーティクルを count 個フェードさせる
void FUN_080e64b4(Enemy* p, s32 count) {
  s32 i;

  if (p->unk_44d == 0) {
    for (i = 0; i < count; i++) {
      Eff082473e0Emitter_FadeParticle(&p->emitter);
    }
  }
}

// ENEFLAG3_UNK_13 が立っていればエミッタの位置から粒子を3回まとめて吹き出させる
// 残差は145/147命令, 原典は p を r8 に置き &p->emitter と &p->emitter.pos をループの外でスタックに退避するが, こちらは p を r5 に置いて毎回組み立てる
// 試済: Eff082473e0Emitter* のローカル (142, 片方だけ退避), Vec3_CopyOffsetY (132), Vec3 を関数の先頭で宣言 (変化なし)
NON_MATCH void FUN_080e64e4(Enemy* p) {
#ifdef NONMATCHING_C
  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_13)) {
    s32 i;

    for (i = 0; i < 3; i++) {
      Vec3 vel;
      Vec3 velRange;
      Vec3 pos;

      vel.x = (Random() & 0xF) - 7;
      vel.y = (Random() & 0x1F) - 16;
      vel.z = (Random() & 0xF) - 7;
      velRange.x = 5, velRange.y = 10, velRange.z = 5;
      pos.x = p->emitter.pos->x;
      pos.y = p->emitter.pos->y + Q8(0.5);
      pos.z = p->emitter.pos->z;
      Eff082473e0Emitter_BurstParticle(&p->emitter, 3, &pos, &vel, &velRange, 40, 40);
    }
    p->unk_192 = 0;
    p->unk_4be = 0;
  }
#else
  INCFUNC("asm/func/FUN_080e64e4.inc");
#endif
}

// 生きている敵なら param_2[1..3] で pathWalker を初期化する
void FUN_080e6624(Enemy* p, u16* param_2) {
  if (p->hp > 0) {
    FUN_080e59c4(p, param_2[1], param_2[2], param_2[3]);
  }
}

// FUN_080e59d0 を1語進めた位置から呼ぶ
void FUN_080e664c(Enemy* p, u16* param_2) { FUN_080e59d0(p, param_2 + 1); }

// 足元のタイルに属性がなく高さの条件もそろったら, 位置などを引数に unk_198 のスクリプトを呼ぶ
void FUN_080e6658(Enemy* p) {
  u32 argv[10];
  ScriptArgs sa;
  TileAttr attr;

  if (TEST_FLAGS(p->flags2, ENEFLAG2_UNK_19)) {
    return;
  }
  attr = TileAtIndex(p->unk_256)->attr;
  if (attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH)) {
    return;
  }
  if (p->floorY - p->mover.pos.y > Q8(1)) {
    return;
  }
  if (Map_FindTileOverride(p->unk_256, 1) != NULL) {
    return;
  }
  if (p->unk_198 == 0) {
    return;
  }
  argv[0] = p->mover.pos.x;
  argv[1] = p->mover.pos.y;
  argv[2] = p->mover.pos.z;
  argv[3] = p->unk_19c;
  argv[4] = p->unk_1a0;
  argv[5] = p->unk_1a4;
  argv[6] = -1;
  argv[7] = 0;
  argv[8] = p->kind;
  argv[9] = p->variant;
  sa.argc = 10;
  sa.argv = argv;
  VM_ExecByID(p->unk_198, &sa);
}

// scriptID が入っていればスクリプトを実行する
void FUN_080e6750(Enemy* p) {
  if (p->scriptID != 0) {
    VM_ExecByID(p->scriptID, NULL);
  }
}

/**
 * @brief 状態遷移の要求をクリアする
 * @param filename 使われていないデバッグ用の引数, "enemy.c", "slimecom.c" などの呼び出し元のファイル名が文字列で渡される
 * @param val 使われていないデバッグ用の引数, 呼び出し元のファイルの行番号?
 */
void Enemy_ClearPendingState(Enemy* p, const char* filename, s32 val) {
  p->unk_550 = 0;
  p->unk_551 = 0;
  p->unk_552 = 0;
  p->unk_554 = 0;
  p->unk_558 = NULL;
}

// 優先度が足りていれば状態14へ遷移させる
void FUN_080e6794(Enemy* p, s32 priority) {
  if (p->unk_554 <= priority) {
    Enemy_EnterState(p, p->unk_558, 14);
    Enemy_SetSubStates(p, p->unk_550, p->unk_551, p->unk_552);
    p->subStateTimer = 0;
    p->subStateBegun = 1;
    Enemy_ClearPendingState(p, s_enemy_c_08251f60, 2306);
  }
}

// 優先度が足りていれば状態14へ遷移させる, アニメは頭から再生し直させる
void FUN_080e6834(Enemy* p, s32 priority) {
  p->animForceRestart = FALSE;
  if (p->unk_554 <= priority) {
    Enemy_EnterState(p, p->unk_558, 14);
    Enemy_SetSubStates(p, p->unk_550, p->unk_551, p->unk_552);
    p->subStateTimer = 0;
    p->subStateBegun = 1;
    Enemy_ClearPendingState(p, s_enemy_c_08251f60, 2322);
  }
}

// 優先度が足りていれば状態14へ遷移させる
void FUN_080e68d8(Enemy* p, s32 priority) {
  if (p->unk_554 <= priority) {
    Enemy_EnterState(p, p->unk_558, 14);
    Enemy_SetSubStates(p, p->unk_550, p->unk_551, p->unk_552);
    p->subStateTimer = 0;
    p->subStateBegun = 1;
    Enemy_ClearPendingState(p, s_enemy_c_08251f60, 2337);
  }
}

// 押し出されたり挟まれたりしたときの処理, type 0/1 は状態21へ移して警戒を解き pos から dy 上げた位置へ置き直す, 2 は姿を隠して damage があれば倒し (煙と声), 無ければ hp を半分削る
// 状態21へ入るときと直後の flags2 を Enemy_SetFlag2 で立て, ダメージ表示を bool8 の inline (自分の画面のプレイヤーが当てたか) と (p, 第5引数) の inline, 煙を (p, count, size, angle) の inline で書くと 787/787 命令
// 残差はレジスタ割当で, 原典は p を r7, pos と dy をスタックに置く (こちらは p を r6, pos を r10)
NON_MATCH void FUN_080e6978(Enemy* p, s32 type, Vec3* pos, s32 dy, s32 damage) {
#ifdef NONMATCHING_C
  bool8 show;

  p->unk_4be = 0;
  FUN_080e64e4(p);
  CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_13);

  switch (type) {
    case 0:
    case 1: {
      if (p->state != 21) {
        Enemy_ResetState(p, 3, 0, 0);
        Enemy_EnterState(p, p->unk_5d4, 21);
        p->unk_4be = 0;
        Enemy_SetFlag2(p, ENEFLAG2_UNK_18);
      }
      Enemy_SetFlag2(p, ENEFLAG2_UNK_2);
      CLEAR_FLAGS(p->flags, ENEFLAG_UNK_22);
      p->animSpeedDiv = 1;
      p->unk_222 = 0;
      p->unk_24e = 0;
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_8 | ENEFLAG3_UNK_9);
      CLEAR_FLAGS(p->flags, ENEFLAG_UNK_26 | ENEFLAG_UNK_27);
      if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
        Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
        CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
        p->unk_21c = 0;
        p->unk_21e = 0;
        p->unk_202 = 0;
      }
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_10);
      p->unk_542 = 0xFF;
      Vec3_CopyOffsetY(&p->mover.pos, pos, dy);
      Enemy_SetSpritePos(p, &p->mover.pos);
      SET_FLAGS(p->flags4, ENEFLAG4_UNK_13);
      break;
    }
    case 2: {
      Enemy_SetFlag2(p, ENEFLAG2_UNK_2);
      ParticleShadow_Hide(&p->shadow);
      Enemy_SetSpriteFlags(p, SPRFLAG_HIDDEN);
      if (damage > 0) {
        p->heightAboveFloor = 0;
        p->hitbox.damage = p->hp;
        p->unk_48a = p->hp;
        p->hp = 0;
        SET_FLAGS(p->flags3, ENEFLAG3_UNK_3);
        SET_FLAGS(p->flags, ENEFLAG_UNK_10);
        SET_FLAGS(p->flags2, ENEFLAG2_UNK_17 | ENEFLAG2_UNK_19);
        Enemy_SetEmote(p, 0, 0x7F, 0);
        Enemy_SetEmote(p, 1, 0x7F, 0);
        Enemy_SetEmote(p, 3, 0x7F, 0);
        FUN_080e64b4(p, 4);
        Enemy_EnterState(p, p->unk_5d0, 17);
        Enemy_ResetState(p, 3, 0, 0);
        show = TRUE;
        if (IsLinkPlay() && !(p->unk_4a0 & 0x20) && p->unk_4a0 != 0) {
          switch (gEntity9A9F != NULL ? gEntity9A9F->playerIdx : -1) {
            case 0: {
              show = p->unk_4a0 == 1;
              break;
            }
            case 1: {
              show = p->unk_4a0 == 2;
              break;
            }
            case 2: {
              show = p->unk_4a0 == 4;
              break;
            }
            case 3: {
              show = p->unk_4a0 == 8;
              break;
            }
          }
        }
        if (show) {
          Vec3 v;

          FUN_0809c344(p->mover.id, p->hp, p->maxHp, p->unk_25a, 0);
          CpuFill32(0, &v, sizeof(v));
          if (p->unk_48a != 0 || !(p->weaponExpMask & 0x4000)) {
            CreateDamageNumber(&p->hitbox, p->unk_48a, 0, &p->mover.pos, &v, 1);
          }
        }
        if (!IsLinkPlay() && !TEST_FLAGS(p->flags2, ENEFLAG2_UNK_11)) {
          FUN_080ec5b4(gMapInitScriptID, p->mover.id);
        }
        if (p->kind == ENEK_BOKU || p->kind == ENEK_MUMMY) {
          Vec3 size;

          size.x = 0x50, size.y = 0x3C, size.z = 0x3C;
          EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
          EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0x40, 4, 20, 2, 1);
          EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
          EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0x80, 4, 20, 2, 1);
          EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
          EmitSmoke(&p->mover.pos, (Random() & 3) + 1, &size, 0xF0, 4, 20, 2, 1);
          if (p->kind == ENEK_BOKU || p->kind == ENEK_MUMMY || p->kind == ENEK_SKELETON || p->kind == ENEK_SKELETON_A || p->kind == ENEK_SKELETON_F || p->kind == ENEK_DARKROOT) {
            PlaySound_082406e0(SONG_229);
          }
        }
      } else {
        p->hitbox.damage = FixToInt(1, p->hp);
        p->unk_48a = p->hitbox.damage;
        p->hp -= p->hitbox.damage;
        show = TRUE;
        if (IsLinkPlay() && !(p->unk_4a0 & 0x20) && p->unk_4a0 != 0) {
          switch (gEntity9A9F != NULL ? gEntity9A9F->playerIdx : -1) {
            case 0: {
              show = p->unk_4a0 == 1;
              break;
            }
            case 1: {
              show = p->unk_4a0 == 2;
              break;
            }
            case 2: {
              show = p->unk_4a0 == 4;
              break;
            }
            case 3: {
              show = p->unk_4a0 == 8;
              break;
            }
          }
        }
        if (show) {
          Vec3 v;

          FUN_0809c344(p->mover.id, p->hp, p->maxHp, p->unk_25a, 0);
          CpuFill32(0, &v, sizeof(v));
          if (p->unk_48a != 0 || !(p->weaponExpMask & 0x4000)) {
            CreateDamageNumber(&p->hitbox, p->unk_48a, 0, &p->mover.pos, &v, 1);
          }
        }
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_080e6978.inc");
#endif
}

// プレイヤーか kindMask 4 の標的が XZ 両軸とも 1ブロック以内にいるか
bool8 FUN_080e7078(Enemy* p) {
  Vec3 d;
  EnemyTarget* t;
  s32 i;

  for (i = 0; i <= gPlayerCount; i++) {
    if (gPlayerPtr[i] != NULL) {
      d.x = p->mover.pos.x - gPlayerPtr[i]->mover.pos.x;
      if (abs(d.x) <= 0xFF) {
        d.z = p->mover.pos.z - gPlayerPtr[i]->mover.pos.z;
        if (abs(d.z) <= 0xFF) {
          return TRUE;
        }
      }
    }
  }

  t = EnemyTargetManager_FindByKind(4);
  if (t == NULL) {
    return FALSE;
  }

  d.x = p->mover.pos.x - t->owner->pos.x;
  if (abs(d.x) <= 0xFF) {
    d.z = p->mover.pos.z - t->owner->pos.z;
    if (abs(d.z) <= 0xFF) {
      return TRUE;
    }
  }

  return FALSE;
}

// pos に一番近いプレイヤーを狙う相手にする (距離はXZ平面で見る)
void Enemy_TargetNearestPlayer(Enemy* p, Vec3* pos) {
  Mover* best = NULL;
  s32 bestDistSq = 0x7FFFFFFF;
  s16 d[3];
  s32 i;

  for (i = 0; i < 4; i++) {
    if (gPlayerPtr[i] != NULL) {
      Vec3* ppos = &gPlayerPtr[i]->mover.pos;
      s32 distSq;

      d[0] = ppos->x - pos->x;
      d[1] = ppos->y - pos->y;
      d[2] = ppos->z - pos->z;
      distSq = d[0] * d[0] + d[2] * d[2];
      if (bestDistSq > distSq) {
        bestDistSq = distSq;
        best = &gPlayerPtr[i]->mover;
      }
    }
  }

  if (best != NULL) {
    if (Enemy_GetFlag3(p, ENEFLAG3_UNK_12)) {
      EnemyTargetManager_Release(p->target);
      Enemy_ClearFlag3(p, ENEFLAG3_UNK_12);
      p->target = NULL;
    }
    p->playerMover = best;
  }
}

// 今いるノードと直前のノードを避けて, 次の経路ノードを乱数で選ぶ (4回外したら順送り)
// 残差は78/78命令で gRandomTable のプール定数の位置のみ, 原典は添字のスケールを先に出してから gRandomTable を読む
NON_MATCH void FUN_080e7204(Enemy* p) {
#ifdef NONMATCHING_C
  u8 cur = p->pathWalker.nodeIdx;
  s32 next;
  s32 i;

  for (i = 0; i < 4; i++) {
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    next = Mod(gRandomTable[gRandTableIdx], p->pathWalker.path->nodeCount);
    if (next != cur && next != p->prevPathNode) {
      break;
    }
  }

  if (next == cur || next == p->prevPathNode) {
    next = cur + 1;
    if (next >= p->pathWalker.path->nodeCount) {
      next = 0;
    }
  }

  p->prevPathNode = cur;
  p->pathWalker.nodeIdx = next;
  p->pathWalker.unk_3 = 0;
  p->pathWalker.node = Map_GetPathNodes(p->pathWalker.path);
  p->pathWalker.node += p->pathWalker.nodeIdx;
#else
  INCFUNC("asm/func/FUN_080e7204.inc");
#endif
}

// 60〜119 フレームの間だけ3番のアニメを流し, 再生し直しの合図で unk_5f0 を呼んで相手を手放す
// 残差は124/124命令で p->mover.angle の ldrb 1命令の位置だけ, 原典は ArcTan2_8 の引数を積んだ直後に読むが, こちらは引数の ldrsh より前に読む
// stateBegun の 0/1 の作り置きは Enemy_ConsumeStateBegun 形の bool8 inline で揃う, Vec3_Diff 周りは EnemyTarget* / Vec3* / WorldPos* のローカルで揃う, angle を式の中で読むと呼び出し後の ldrb になる
NON_MATCH void FUN_080e72b0(Enemy* p, s32 timer) {
#ifdef NONMATCHING_C
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    Enemy_PlayAnim(p, 0);
  }

  {
    EnemyTarget* target = p->target;
    Vec3 d;
    Vec3* dst = &d;
    WorldPos* pos = &p->mover.pos;
    s32 angle;
    s32 diff;

    Vec3_Diff(dst, &target->owner->pos, pos);
    angle = p->mover.angle;
    diff = ArcTan2_8(d.x, d.z) - angle;
    if (diff > 0x80) {
      diff -= 0x100;
    } else if (diff < -0x80) {
      diff += 0x100;
    }
  }

  if (timer >= 60) {
    if (timer < 120) {
      Enemy_PlayAnim(p, 3);
      if (timer == 60) {
        PlayEnemyEmoteCry(0, p->kind, p->variant);
      }
      if (timer == 100) {
        FUN_080867a0();
        EnemyTargetManager_Release(p->target);
      }
      if ((timer >> 2) & 1) {
        Enemy_SetFlag4(p, ENEFLAG4_UNK_5);
      }
      if (p->spriteKind == 0) {
        AuxAnimState* anim = &((EnemyAuxSpriteData*)p->sprite)->anim;
        anim->tick = 0;
      } else {
        p->sprite->s.animCmdTimer = 0;
      }
    }
    if (p->animForceRestart) {
      p->unk_5f0(p);
      p->target = NULL;
    }
  }
#else
  INCFUNC("asm/func/FUN_080e72b0.inc");
#endif
}

// 状態14に入り直し, ENEFLAG3_UNK_7 なら 1P のいるタイルへ向かう (FUN_080f12c4 と同じ塊), そうでなければ経路の今のノードへ一歩動いて状態1の遷移を予約する
// 1P へ向かう塊を bool8 を返す static inline (同じタイルか透明なら状態26/1と状態27の予約へ, 違えば一歩動く) にし, 乱数の向き選びを FUN_080f0e78 と同じ while の中で書き込む形, unk_222 の判定を bool8 の inline にすると 842/844 命令
// その inline 形ではフィールドのアドレスをスタックに持ち越す原典の形も出る, 残差はレジスタ割当とアドレス計算の定数の作り方
NON_MATCH void FUN_080e73c8(Enemy* p) {
#ifdef NONMATCHING_C
  bool8 moved;

  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_12)) {
    EnemyTargetManager_Release(p->target);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_12);
    p->target = NULL;
  }
  p->animSpeedDiv = 1;
  Enemy_PlayAnim(p, 0);
  Enemy_EnterState(p, FUN_080e6794, 14);
  Enemy_ResetState(p, 3, 1, 0);

  if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_7)) {
    s32 tile;
    s32 idx;

    {
      Vec3* dst = p->unk_4a8;
      PathWalker* walker = &p->pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    if (IsLinkPlay()) {
      Mover* m = p->playerMover;

      idx = -1;
      if (m != NULL && m->unk_4 <= 3) {
        idx = m->unk_4;
      }
      if (m == NULL || idx < 0) {
        p->unk_5c4(p);
        return;
      }
      tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
    } else {
      tile = GetCollisionTileIdx(&p->playerMover->pos);
      idx = 0;
    }

    if (tile == p->unk_256 || (gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
      u8 angle;

      if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_10)) {
        return;
      }
      p->unk_222 &= ~ENEMY222_UNK_2;
      if (TEST_FLAGS(p->flags3, ENEFLAG3_UNK_7)) {
        Enemy_EnterState(p, p->unk_5b8, 26);
        Enemy_ResetState(p, 0, 0, 12);
      } else {
        Enemy_EnterState(p, p->unk_5a0, 1);
        Enemy_ResetState(p, 0, 0, 5);
        {
          Vec3* dst = p->unk_4a8;
          PathWalker* walker = &p->pathWalker;

          dst->x = walker->node->x;
          dst->z = walker->node->y;
          dst->y = TileHeightAt(dst);
        }
        p->unk_4a8->y = TileHeightAt(p->unk_4a8);
        p->unk_4a8->val = 0;
      }
      angle = p->mover.angle;
      if (!TEST_FLAGS(p->flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS(p->unk_222, ENEMY222_UNK_2)) {
        s32 i = 0;
        u32 a;

        while (TRUE) {
          a = (Random() & 3) << 6;
          if (a != angle || ++i > 3) {
            p->unk_540 = a;
            p->unk_548 = p->handlerState;
            p->unk_54f = p->state;
            p->unk_54c = p->subState0;
            p->unk_54d = p->subState1;
            p->unk_54e = p->subState2;
            p->unk_541 = angle;
            Enemy_EnterState(p, p->unk_5bc, 27);
            Enemy_ResetState(p, 3, 1, 0);
            p->unk_542 = 6;
            break;
          }
        }
      }
      FUN_080e7b6c(p);
      p->animSpeedDiv = 2;
      return;
    } else {
      WorldPos tilePos;

      TilePosAtIndex(&tilePos, tile);
      if (!Enemy_StepToward(p, &tilePos)) {
        p->unk_5c4(p);
        return;
      }
    }
    p->unk_554 = 60;
    p->unk_558 = p->unk_5b8;
    p->unk_550 = 0;
    p->unk_551 = 0;
    p->unk_552 = 12;
    p->unk_222 &= ~ENEMY222_UNK_2;
    return;
  }

  p->unk_4a8->val = 1;
  moved = FALSE;
  {
    NavAgent* agent = p->navAgent;
    WorldPos* pos = &p->mover.pos;
    Vec3* dst = p->unk_4a8;

    if (Map_IsPosInAgentIsland(agent, pos, dst)) {
      s32 result = FUN_08235f40(agent, pos, dst);

      if (result != 0) {
        if (result != 2) {
          ClearMemory(&p->mover.delta, 8);
        }
        moved = TRUE;
      }
    }
    if (!moved) {
      CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    }
  }
  if (!moved) {
    p->unk_5c4(p);
    return;
  }
  p->unk_554 = 60;
  p->unk_558 = p->unk_5a0;
  p->unk_550 = 0;
  p->unk_551 = 0;
  p->unk_552 = 7;
  if (TEST_FLAGS(p->flags, ENEFLAG_UNK_21)) {
    Enemy_ClearFlag2(p, ENEFLAG2_UNK_24);
    CLEAR_FLAGS(p->flags3, ENEFLAG3_UNK_9);
    p->unk_21c = 0;
    p->unk_21e = 0;
    p->unk_202 = 0;
  }
#else
  INCFUNC("asm/func/FUN_080e73c8.inc");
#endif
}

// 向いている方向の反対から順に4方向を試し, 同じ高さで通れる床が続く端のタイルへ一歩動く
// 床の判定を bool8 の static inline, 端の探索を switch の各節から return する static inline にし, 末尾を Enemy_StepToward でなく p->navAgent の直書きにすると 439/443 命令まで縮む
// 残差は start の索引と高さのレジスタ割当 (原典は索引をスタック, 高さを r8) と, attr & 0x43 の ands の向き
NON_MATCH void FUN_080e7b6c(Enemy* p) {
#ifdef NONMATCHING_C
  s32 dir = ((((p->mover.angle + 0x20) >> 6) & 3) + 2) & 3;
  s32 i = 0;
  s32 idx;
  WorldPos dst;

  do {
    s32 start = p->unk_256;
    u32 height = TileAtIndex(start)->heightStairs & 0xF;
    s32 size = gCollisionMap->tiledata->width * gCollisionMap->tiledata->height;
    s32 cur;
    s32 x;

    idx = start;
    switch (dir) {
      case 0: {
        cur = start + 1;
        for (x = Mod(cur, gCollisionMap->tiledata->width); x < gCollisionMap->tiledata->width; x++) {
          if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
            idx = cur - 1;
            break;
          }
          cur++;
        }
        break;
      }
      case 1: {
        for (cur = start + gCollisionMap->tiledata->width; cur < size; cur += gCollisionMap->tiledata->width) {
          if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
            idx = cur - gCollisionMap->tiledata->width;
            break;
          }
        }
        break;
      }
      case 2: {
        cur = start - 1;
        for (x = Mod(cur, gCollisionMap->tiledata->width); x >= 0; x--) {
          if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
            idx = cur + 1;
            break;
          }
          cur--;
        }
        break;
      }
      case 3: {
        for (cur = start - gCollisionMap->tiledata->width; cur >= 0; cur -= gCollisionMap->tiledata->width) {
          if ((TileAtIndex(cur)->heightStairs & 0xF) != height || (TileAtIndex(cur)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
            idx = cur + gCollisionMap->tiledata->width;
            break;
          }
        }
        break;
      }
    }
    dir = (dir + 1) & 3;
    i++;
  } while (idx == p->unk_256 && i < 4);
  TilePosAtIndex(&dst, idx);
  if (Map_IsPosInAgentIsland(p->navAgent, &p->mover.pos, &dst)) {
    s32 result = FUN_08235f40(p->navAgent, &p->mover.pos, &dst);

    if (result != 0) {
      if (result != 2) {
        ClearMemory(&p->mover.delta, 8);
      }
      return;
    }
  }
  Enemy_ClearFlag3(p, ENEFLAG3_UNK_9);
#else
  INCFUNC("asm/func/FUN_080e7b6c.inc");
#endif
}

// 種族ごとの鳴き声を鳴らす, ENEFLAG3_UNK_1/2 のどちらかが立っていればダメージ音にする
void Enemy_PlayVoice(Enemy* p) {
  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_1 | ENEFLAG3_UNK_2)) {
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
    return;
  }

  switch (p->kind) {
    case ENEK_BOKU:
    case ENEK_28: {
      PlaySound_082406e0(CRY_BOKU_DAMAGED);
      break;
    }
    case ENEK_MUMMY: {
      PlaySound_082406e0(CRY_MUMMY_DAMAGED);
      break;
    }
    case ENEK_GOLEM:
    case ENEK_30: {
      switch (p->variant) {
        case 0:
        case 1:
        case 3:
        case 5: {
          PlaySound_082406e0(SONG_397);
          break;
        }
      }
      break;
    }
    case ENEK_OCTOPUS: {
      PlaySound_082406e0(SONG_476);
      break;
    }
    case ENEK_COCKA: {
      PlaySound_082406e0(SONG_461);
      break;
    }
  }
}

// 索引 fromIdx のタイル (高さ fromHeight, 階段 fromStairs) から隣の idx のタイルへ歩いて移れるか
// 残差は191/189命令, 原典は gCollisionMap のアドレスを使うたびにプールから読み直すが, こちらは2つ目の TileAtIndex の分岐から r9 に持ち越して Mod / Div / 縦の隣接判定で使い回し, 高さ (r8) と &pos (r10) の割当がずれる
// 末尾は「着地できなければ FALSE を共有」の形が原典に近い, 試済: pos を Vec3* で触る / Mod・Div を pos への代入式に直接書く / 高さのタイル引きを三項演算子で展開, いずれも悪化
NON_MATCH bool8 FUN_080e8038(s32 fromIdx, s32 idx, s32 fromHeight, s32 fromStairs) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 stairs = TileAtIndex(idx)->heightStairs >> 4;
  s32 height = TileHeightAtIndex(idx, &pos);
  s32 x = Mod(idx, gCollisionMap->tiledata->width);
  s32 z = Div(idx, gCollisionMap->tiledata->width);
  bool8 stepped;
  TileAttr attr;

  pos.x = (x << 8) + 0x80;
  pos.y = (TileAtIndex(idx)->heightStairs & 0xF) << 8;
  pos.z = (z << 8) + 0x80;

  stepped = FALSE;
  if ((stairs == STAIRS_HORIZONTAL && fromStairs == 0) || (fromStairs == STAIRS_HORIZONTAL && stairs == 0)) {
    if (abs(fromIdx - idx) == 1) {
      stepped = TRUE;
    }
  } else if ((stairs == STAIRS_VERTICAL && fromStairs == 0) || (fromStairs == STAIRS_VERTICAL && stairs == 0)) {
    if (abs(fromIdx - idx) == gCollisionMap->tiledata->width) {
      stepped = TRUE;
    }
  } else if ((stairs == STAIRS_VERTICAL && fromStairs == STAIRS_VERTICAL) || (stairs == STAIRS_HORIZONTAL && fromStairs == STAIRS_HORIZONTAL)) {
    stepped = TRUE;
  }

  attr = TileAtIndex(idx)->attr;
  if (!(attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH))) {
    if (stepped) {
      if (abs((height >> 8) - (fromHeight >> 8)) <= 1) {
        return TRUE;
      }
    } else if (height == fromHeight) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080e8038.inc");
#endif
}

// param_2 の番号ごとの効果音を, variant が 0/1/3/5 のときだけ鳴らす
void FUN_080e81dc(Enemy* p, s32 param_2) {
  switch (param_2) {
    case 2: {
      switch (p->variant) {
        case 0:
        case 1:
        case 3:
        case 5: {
          PlaySound_0824078c(SONG_392);
          break;
        }
      }
      break;
    }
    case 3: {
      switch (p->variant) {
        case 0:
        case 1:
        case 3:
        case 5: {
          PlaySound_0824078c(CRY_GOLEM_391);
          break;
        }
      }
      break;
    }
    case 1: {
      if (Enemy_TestUnk48c(p)) {
        break;
      }
      switch (p->variant) {
        case 0:
        case 1:
        case 3:
        case 5: {
          PlaySound_082406e0(SE_ENEMY_DAMAGED);
          break;
        }
      }
      break;
    }
    case 4: {
      switch (p->variant) {
        case 0:
        case 1:
        case 3:
        case 5: {
          PlaySound_082406e0(SONG_393);
          break;
        }
      }
      break;
    }
    case 5: {
      switch (p->variant) {
        case 0:
        case 1:
        case 3:
        case 5: {
          PlaySound_082406e0(SONG_394);
          break;
        }
      }
      break;
    }
    case 6: {
      switch (p->variant) {
        case 0:
        case 1:
        case 3:
        case 5: {
          PlaySound_082406e0(SONG_395);
          break;
        }
      }
      break;
    }
    case 0: {
      switch (p->variant) {
        case 0:
        case 1:
        case 3:
        case 5: {
          PlaySound_0824078c(SONG_398);
          break;
        }
      }
      break;
    }
  }
}

// 種族ごとの音を鳴らす, ENEFLAG2_UNK_22 が立っていれば今回は鳴らさずに落とすだけ
void PlayEnemyDeathCry(Enemy* p) {
  if (TEST_FLAGS(p->flags2, ENEFLAG2_UNK_22)) {
    p->flags2 &= ~ENEFLAG2_UNK_22;
    return;
  }

  switch (p->kind) {
    case ENEK_BOKU:
    case ENEK_28: {
      PlaySound_082406e0(CRY_BOKU_DEATH);
      break;
    }
    case ENEK_MUMMY: {
      PlaySound_082406e0(CRY_MUMMY_DEATH);
      break;
    }
    case ENEK_GOLEM:
    case ENEK_30: {
      FUN_080e81dc(p, 0);
      break;
    }
    case ENEK_OCTOPUS: {
      PlaySound_082406e0(CRY_TENTACLE_DEATH);
      break;
    }
    case ENEK_COCKA: {
      PlaySound_082406e0(CRY_COCKA_DEATH);
      break;
    }
    case ENEK_SKELETON:
    case ENEK_SKELETON_F:
    case ENEK_SKELETON_A: {
      PlaySound_082406e0(CRY_SKELETON_DEATH);
      break;
    }
    case ENEK_LICH: {
      PlaySound_082406e0(CRY_LICH_DEATH);
      break;
    }
    case ENEK_CENTIPEDE: {
      PlaySound_082406e0(CRY_CENTIPEDE_DEATH);
      break;
    }
    case ENEK_SPIDER:
    case ENEK_SANDWORM:
    case ENEK_SERPENT: {
      PlaySound_082406e0(CRY_SPIDER_DEATH);
      break;
    }
    case ENEK_CURORO: {
      PlaySound_082406e0(CRY_CURORO_DEATH);
      break;
    }
    case ENEK_BAT: {
      PlaySound_082406e0(CRY_BAT_DEATH);
      break;
    }
    case ENEK_CROW: {
      PlaySound_082406e0(CRY_CROW_DEATH);
      break;
    }
    case ENEK_DOG: {
      PlaySound_082406e0(CRY_DOG_DEATH);
      break;
    }
    case ENEK_SLIME: {
      PlaySound_082406e0(CRY_SLIME_DEATH);
      break;
    }
    case ENEK_BEE: {
      PlaySound_082406e0(CRY_BEE_DEATH);
      break;
    }
    case ENEK_GHOST: {
      if (Enemy_TestFlag3(p, ENEFLAG3_UNK_14)) {
        PlaySound_082406e0(SONG_542);
      } else {
        PlaySound_082406e0(CRY_GHOST_DEATH);
      }
      break;
    }
    case ENEK_SHAIAN: {
      PlaySound_082406e0(SONG_973);
      PlaySound_082406e0(VO_SHAIAN_DEATH);
      break;
    }
    case ENEK_DARKROOT: {
      PlaySound_082406e0(CRY_TENTACLE_DEATH);
      break;
    }
  }
}

// 種族ごとの音を鳴らす, ENEFLAG2_UNK_22 が立っていれば今回は鳴らさずに落とすだけ
void FUN_080e850c(Enemy* p) {
  if (TEST_FLAGS(p->flags2, ENEFLAG2_UNK_22)) {
    p->flags2 &= ~ENEFLAG2_UNK_22;
    return;
  }
  if (Enemy_TestUnk48c(p)) {
    return;
  }

  switch (p->kind) {
    case ENEK_BOKU:
    case ENEK_28: {
      PlaySound_082406e0(CRY_BOKU_DAMAGED);
      break;
    }
    case ENEK_MUMMY: {
      PlaySound_082406e0(CRY_MUMMY_DAMAGED);
      break;
    }
    case ENEK_GOLEM:
    case ENEK_30: {
      FUN_080e81dc(p, 1);
      break;
    }
    case ENEK_COCKA:
    case ENEK_OCTOPUS: {
      PlaySound_082406e0(SE_ENEMY_DAMAGED);
      break;
    }
    case ENEK_SPIDER: {
      PlaySound_082406e0(SE_UNK_274);
      break;
    }
  }
}

// unk_470 の間, 粒子を出す向きを unk_452 で振りながら 4 フレームおきに種族ごとの粒子を3回に分けて撒く
// 3回の撒き方を (p, kind, Vec3* offset, angle) の static inline にし, 中で pos = p->mover.pos; pos.y += offset->y; と書くと offset->y の読み直しが揃って 505/510 命令
// 原典は各回の前に乱数を2つ空読みする, 残差は角度を r10 に置く割当と, 3回目で角度の乱数を個数の乱数より先に引く順序
NON_MATCH void FUN_080e8614(Enemy* p) {
#ifdef NONMATCHING_C
  s32 angle;
  Vec3 offset;
  Vec3 pos;

  if (p->unk_470 == 0) {
    return;
  }
  p->unk_470--;
  angle = ((p->angle + 9) & 7) << 5;
  angle += p->unk_452;
  p->unk_452 += p->unk_453 * 4;
  if (p->unk_452 > 0x40) {
    p->unk_452 = 0x40;
    p->unk_453 *= -1;
  }
  if (Mod(p->unk_470, 4) != 0) {
    return;
  }

  ClearMemory(&offset, 8);
  switch (p->kind) {
    case ENEK_SPIDER: {
      offset.y = 0;
      if (p->variant == 0) {
        Random();
        Random();
        pos = p->mover.pos;
        pos.y += offset.y;
        Entity080146e0_SpawnAtAngle((Random() & 3) + 2, 9, &pos, angle, 8, (Random() & 3) + 6, 4, 10, 8, 5, 10);
        Entity080146e0_SpawnAtAngle(3, 9, &pos, (angle + (Random() & 7)) & 0xFF, 8, (Random() & 7) + 6, 4, 14, 4, 6, 10);
        Entity080146e0_SpawnAtAngle((Random() & 3) + 1, 9, &pos, (angle + (Random() & 0xF)) & 0xFF, 8, (Random() & 7) + 4, 2, 6, 3, 5, 10);
      } else {
        Random();
        Random();
        pos = p->mover.pos;
        pos.y += offset.y;
        Entity080146e0_SpawnAtAngle((Random() & 3) + 2, 10, &pos, angle, 8, (Random() & 3) + 6, 4, 10, 8, 5, 10);
        Entity080146e0_SpawnAtAngle(3, 10, &pos, (angle + (Random() & 7)) & 0xFF, 8, (Random() & 7) + 6, 4, 14, 4, 6, 10);
        Entity080146e0_SpawnAtAngle((Random() & 3) + 1, 10, &pos, (angle + (Random() & 0xF)) & 0xFF, 8, (Random() & 7) + 4, 2, 6, 3, 5, 10);
      }
      break;
    }
    case ENEK_OCTOPUS: {
      offset.y = 40;
      Random();
      Random();
      pos = p->mover.pos;
      pos.y += offset.y;
      Entity080146e0_SpawnAtAngle((Random() & 3) + 2, 11, &pos, angle, 8, (Random() & 3) + 6, 4, 10, 8, 5, 10);
      Entity080146e0_SpawnAtAngle(3, 11, &pos, (angle + (Random() & 7)) & 0xFF, 8, (Random() & 7) + 6, 4, 14, 4, 6, 10);
      Entity080146e0_SpawnAtAngle((Random() & 3) + 1, 11, &pos, (angle + (Random() & 0xF)) & 0xFF, 8, (Random() & 7) + 4, 2, 6, 3, 5, 10);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_080e8614.inc");
#endif
}

bool8 Enemy_IsDead(Enemy* p) {
  if (p == NULL) {
    return FALSE;
  }

  if (Enemy_TestFlag3(p, ENEFLAG3_UNK_6) || Enemy_TestFlag2(p, ENEFLAG2_UNK_17) || p->hp <= 0) {
    return TRUE;
  }
  return FALSE;
}

// 8バイト2語の要素を先頭ワードの昇順に並べ替える (バブルソート)
// 残差は31/33命令, 原典は count-1 を引数レジスタ上で潰してから番兵チェック後に退避するが agbcc は別レジスタに作る
// Tier A-B 試済: count-1 を2回書く (34命令) / ローカル n に退避 / count-- 文
NON_MATCH void FUN_080e8aa0(s32* p, s32 count) {
#ifdef NONMATCHING_C
  s32 i;
  s32 j;

  count--;
  for (i = 0; i < count; i++) {
    s32* q = p;

    for (j = 0; j < count; j++) {
      if (q[0] > q[2]) {
        s32 key = q[0];
        s32 val = q[1];

        q[0] = q[2];
        q[1] = q[3];
        q[2] = key;
        q[3] = val;
      }
      q += 2;
    }
  }
#else
  INCFUNC("asm/func/FUN_080e8aa0.inc");
#endif
}

// target のタイルへ経路で行けるならそこを, 行けなければ4近傍のタイルの中心を近い順に調べて最初に行ける点を out に入れる, どれも駄目なら (30000, 0, 30000)
// 属性の判定を TileAttr を返す static inline (TileAtIndex(idx)->attr) にすると ands の向きが揃って 487/491 命令
// 残差は idx をスタックに置く (原典) かレジスタに置くかの割当と, 原典が TilePosAtIndex の pos 引数を毎回 r10 から r9 へ写す点
NON_MATCH void FUN_080e8ae4(Enemy* p, Vec3* out, Vec3* target) {
#ifdef NONMATCHING_C
  s32 cands[4][2];
  Vec3 pos;
  Vec3 d;
  s32 idx = GetCollisionTileIdx(target);
  s32 i;

  if (!(TileAtIndex(idx)->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL)) && Map_IsPosInAgentIsland(p->navAgent, &p->mover.pos, target)) {
    *out = *target;
    return;
  }

  TilePosAtIndex(&pos, idx + 1);
  Vec3_Diff(&d, &pos, &p->mover.pos);
  cands[0][0] = d.x * d.x + d.z * d.z;
  cands[0][1] = idx + 1;
  TilePosAtIndex(&pos, idx + gCollisionMap->tiledata->width);
  Vec3_Diff(&d, &pos, &p->mover.pos);
  cands[1][0] = d.x * d.x + d.z * d.z;
  cands[1][1] = idx + gCollisionMap->tiledata->width;
  TilePosAtIndex(&pos, idx - 1);
  Vec3_Diff(&d, &pos, &p->mover.pos);
  cands[2][0] = d.x * d.x + d.z * d.z;
  cands[2][1] = idx - 1;
  TilePosAtIndex(&pos, idx - gCollisionMap->tiledata->width);
  Vec3_Diff(&d, &pos, &p->mover.pos);
  cands[3][0] = d.x * d.x + d.z * d.z;
  cands[3][1] = idx - gCollisionMap->tiledata->width;
  FUN_080e8aa0(cands[0], 4);

  for (i = 0; i < 4; i++) {
    if (!(TileAtIndex(cands[i][1])->attr & (TATTR_UNK_0 | TATTR_WALL | TATTR_FALLDEATH | TATTR_SPECIAL))) {
      TilePosAtIndex(&pos, cands[i][1]);
      if (Map_IsPosInAgentIsland(p->navAgent, &p->mover.pos, &pos)) {
        *out = pos;
        return;
      }
    }
  }
  out->x = 30000, out->y = 0, out->z = 30000;
#else
  INCFUNC("asm/func/FUN_080e8ae4.inc");
#endif
}

void FUN_080e8f20(Enemy* p, s32 param_2) {
  p->unk_21e = FUN_08240b98(&p->unk_204, param_2);

  if (p->unk_21e == 0xB546) {
    FUN_080e8ae4(p, &p->unk_204, &p->unk_204);
  }
}

// 進む向きの 32 先のタイルが今の高さより高いか, 止まっていれば 0, 呼び出し元は見つかっていない
s32 FUN_080e8f5c(Enemy* p) {
  Vec3 ofs;
  Vec3 next;
  CollisionMapTile* tile;
  s32 height;

  if (p->mover.delta.x != 0) {
    if (p->mover.delta.x < 0) {
      ofs.x = -Q8(0.125), ofs.z = 0;
    } else {
      ofs.x = Q8(0.125), ofs.z = 0;
    }
  } else if (p->mover.delta.z != 0) {
    if (p->mover.delta.z < 0) {
      ofs.x = 0, ofs.z = -Q8(0.125);
    } else {
      ofs.x = 0, ofs.z = Q8(0.125);
    }
  } else {
    return FALSE;
  }

  next.x = p->mover.pos.x + p->mover.delta.x + ofs.x;
  next.y = p->mover.pos.y + p->mover.delta.y;
  next.z = p->mover.pos.z + p->mover.delta.z + ofs.z;
  tile = GetTileAt(&next);
  height = (tile->heightStairs & 0xF) << 8;
  if (p->mover.pos.y < height) {
    return TRUE;
  }
  return FALSE;
}

// Enemy の kind から family を取得
static s32 UNUSED Enemy_GetFamily(Enemy* p) {
  switch (p->kind) {
    case ENEK_MUMMY: {
      return ENEF_MUMMY;
    }
    case ENEK_SPIDER: {
      return ENEF_SPIDER;
    }
    case ENEK_GOLEM:
    case ENEK_30: {
      return ENEF_GOLEM;
    }
    case ENEK_OCTOPUS: {
      return ENEF_OCTOPUS;
    }
    case ENEK_15: {
      return EKEF_12;
    }
    case ENEK_DARKROOT: {
      return ENEF_DARKROOT;
    }
    case ENEK_COCKA: {
      return ENEF_COCKATRICE;
    }
    case ENEK_MIMIC: {
      return ENEF_MIMIC;
    }
    case ENEK_SKELETON:
    case ENEK_SKELETON_F:
    case ENEK_SKELETON_A: {
      return ENEF_SKELETON;
    }
    case ENEK_DOG: {
      return ENEF_DOG;
    }
    case ENEK_LICH: {
      return ENEF_LICH;
    }
    case ENEK_BAT: {
      return ENEF_BAT;
    }
    case ENEK_CROW: {
      return ENEF_CROW;
    }
    case ENEK_CURORO: {
      return ENEF_CURORO;
    }
    case ENEK_SLIME: {
      return ENEF_SLIME;
    }
    case ENEK_BEE: {
      return ENEF_BEE;
    }
    case ENEK_CENTIPEDE: {
      return ENEF_CENTIPEDE;
    }
    case ENEK_SANDWORM: {
      return ENEF_SANDWORM;
    }
    case ENEK_SERPENT: {
      return ENEF_SERPENT;
    }
    case ENEK_GHOST: {
      return ENEF_GHOST;
    }
    case ENEK_AX: {
      return ENEF_AX;
    }
    case ENEK_SHAIAN: {
      return ENEF_SHAIAN;
    }
    case ENEK_SWORD: {
      return ENEF_SWORD;
    }
  }
  return 0;
}

NAKED void FUN_080e9178(Enemy* p) { INCFUNC("asm/func/FUN_080e9178.inc"); }

// flags4 に溜まった要求を優先順に1つ処理して, 処理した印を落とす, 何か処理したら TRUE
bool32 FUN_080eafdc(Enemy* p) {
  if (Enemy_IsDead(p)) {
    return FALSE;
  }
  if (p->flags4 == 0) {
    return FALSE;
  }

  if (!IsSmallEnemy(p)) {
    if (Enemy_TestFlag4(p, ENEFLAG4_UNK_2)) {
      Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_2 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
      return TRUE;
    }
    if (Enemy_TestFlag4(p, ENEFLAG4_UNK_1)) {
      Enemy_ResetState(p, 3, 0, 0);
      Enemy_EnterState(p, p->unk_594, 7);
      p->unk_192 = p->unk_18e;
      Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_1 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
      return TRUE;
    }
    if (Enemy_TestFlag4(p, ENEFLAG4_UNK_11)) {
      FUN_080f0b3c(p);
      Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
      return TRUE;
    }
    if (Enemy_TestFlag4(p, ENEFLAG4_UNK_0)) {
      Enemy_ClearFlags4(p, ENEFLAG4_UNK_0 | ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8);
      return TRUE;
    }
  }

  if (Enemy_TestFlag4(p, ENEFLAG4_UNK_7)) {
    if (p->unk_5ac != NULL) {
      p->unk_5ac(p);
    }
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8);
    return TRUE;
  }
  if (Enemy_TestFlag4(p, ENEFLAG4_UNK_8)) {
    if (p->unk_5b0 != NULL) {
      p->unk_5b0(p);
    }
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8);
    return TRUE;
  }
  return FALSE;
}

// ENEFLAG4_UNK_4 / UNK_5 が立っていればスプライトの座標を乱数で ±5 / ±8 ずらして, その印を落とす
bool32 FUN_080eb168(Enemy* p) {
  if (Enemy_IsDead(p)) {
    return FALSE;
  }

  if (Enemy_TestFlag4(p, ENEFLAG4_UNK_4)) {
    Vec3* pos = Enemy_GetSpritePos(p);
    u16* table = gRandomTable;

    pos->x += Mod(_Random(table), 10) - 5;
    pos->z += Mod(_Random(table), 10) - 5;
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_4);
    return TRUE;
  }
  if (Enemy_TestFlag4(p, ENEFLAG4_UNK_5)) {
    Vec3* pos = Enemy_GetSpritePos(p);
    u16* table = gRandomTable;

    pos->x += Mod(_Random(table), 16) - 8;
    pos->z += Mod(_Random(table), 16) - 8;
    Enemy_ClearFlags4(p, ENEFLAG4_UNK_5);
    return TRUE;
  }
  return FALSE;
}

NAKED bool8 FUN_080eb2a0(Enemy* p) { INCFUNC("asm/func/FUN_080eb2a0.inc"); }

// 犬(プレイヤーに攻撃したときにアイテムを奪う)の処理
// 道具欄をランダムな位置から16スロット分走査して, 持っている道具を1つ選ぶ (チョコまみれは除く)
// 残差は62/62命令でブロック配置のみ, 原典は見つかった側のブロックをループの外 (return FALSE の後ろ) に置く
// Tier A-C 試済 (for/while(TRUE), break+i==16, s16 ローカル経由)
NON_MATCH bool32 FUN_080ec438(s16* outSlot, s16* outItem, s16* outRot) {
#ifdef NONMATCHING_C
  s16 slot;
  s16 i;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  slot = Mod(gRandomTable[gRandTableIdx], 16);

  for (i = 0; i < 16; i++) {
    *outItem = GetNormalItemID(slot);
    if (*outItem >= 0 && *outItem != ITEM_CHOCOLATE_COVERED) {
      *outSlot = slot;
      *outRot = GetRotCount(*outSlot);
      return TRUE;
    }
    slot = Mod(slot + 1, 16);
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_080ec438.inc");
#endif
}

void nop_080ec4c8(void) {}

void nop_080ec4cc(void) {}

// gStat->unk_308 を丸ごと 0 にする
void Cmd_300F(void) { ClearMemory(gStat->unk_308, sizeof(gStat->unk_308)); }

// 0x308 の表の空き (3語目の [1] が 0) を先頭から探す, 無ければ NULL
u16* FUN_080ec4ec(void) {
  u16* r;
  s32 i;

  for (i = 0, r = gStat->unk_308; i < 20; r += 3, i++) {
    if (r[1] == 0) {
      return r;
    }
  }
  return NULL;
}

// 0x308 の表から先頭2語が (a, b) の行を探す, 無ければ NULL
u16* FUN_080ec518(u32 a, u32 b) {
  u16* t;
  s32 i;

  for (i = 0, t = gStat->unk_308; i < 20; i++) {
    if (t[i * 3] == a && t[i * 3 + 1] == b) {
      return &t[i * 3];
    }
  }
  return NULL;
}

// mapFlags の MPF_UNK_2 が立っている間, unk_308 の表の使用中の件ごとに [2] を減らし, 尽きた件を空きにする
void Cmd_A2E4(void) {
  s32 i;

  if (!TestMapFlag(MPF_UNK_2)) {
    return;
  }
  for (i = 0; i < 20; i++) {
    u16* entry = &gStat->unk_308[i * 3];

    if (entry[1] != 0 && --entry[2] == 0) {
      entry[1] = 0;
    }
  }
}

// 0x308 の表に (a, b) を登録する, 既にあるか空きが無ければ何もしない
void FUN_080ec5b4(u16 a, u16 b) {
  u16* r = FUN_080ec518(a, b);
  EnemyManager* m;

  if (r != NULL) {
    return;
  }

  r = FUN_080ec4ec();
  if (r == NULL) {
    return;
  }

  m = GetEnemyManager();
  if (m == NULL) {
    return;
  }

  r[0] = a;
  r[1] = b;
  r[2] = m->unk_30;
}

bool32 FUN_080ec5f0(u16 param_1, u16 param_2) {
  if (FUN_080ec518(param_1, param_2) == 0 && FUN_080ec4ec() != 0) {
    return TRUE;
  }

  return FALSE;
}
