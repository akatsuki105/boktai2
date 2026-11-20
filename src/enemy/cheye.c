#include "dust.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "global.h"
#include "link_session.h"
#include "malloc.h"
#include "map_inline.h"
#include "sound.h"
#include "vm.h"

extern s32 gLightningTimer;

// Shaian.flags (0x898)
typedef u32 ShaianFlags;
#define SHAIANFLAG_UNK_0 (1 << 0)          // 0x1, _Init の最後で立つ
#define SHAIANFLAG_UNK_3 (1 << 3)          // 0x8
#define SHAIANFLAG_CHASING (1 << 4)        // 0x10, プレイヤーを追っている
#define SHAIANFLAG_UNK_5 (1 << 5)          // 0x20
#define SHAIANFLAG_FADING (1 << 7)         // 0x80, フェードでパレットを寄せている
#define SHAIANFLAG_USE_ITEM0 (1 << 9)      // 0x200, items[0] (体力の回復) を使う途中
#define SHAIANFLAG_USE_ITEM1 (1 << 10)     // 0x400, items[1] (足を速くする) を使う途中
#define SHAIANFLAG_USE_ITEM2 (1 << 11)     // 0x800, items[2] (姿を消す) を使う途中
#define SHAIANFLAG_SEARCHING (1 << 12)     // 0x1000, アイテムを探っている間, 攻撃を受けるとそのアイテムを落とす
#define SHAIANFLAG_ITEM_ACTION (1 << 13)   // 0x2000, アイテムを探って使い終わるまでの間, ひるまず見切りもしない
#define SHAIANFLAG_RETREATING (1 << 14)    // 0x4000, retreatDest へ逃げている
#define SHAIANFLAG_HASTE (1 << 15)         // 0x8000, items[1] が効いている間, アニメを倍の速さで送る
#define SHAIANFLAG_CLOAK (1 << 16)         // 0x10000, items[2] が効いている間
#define SHAIANFLAG_CLOAK_SHOWN (1 << 17)   // 0x20000, CLOAK の間, 姿を現している
#define SHAIANFLAG_CLOAK_HIDDEN (1 << 18)  // 0x40000, CLOAK の間, 姿を消している
#define SHAIANFLAG_LONG_WAIT (1 << 19)     // 0x80000, 1/4 で立ち, 副状態 0 で次の行動までの待ちを 8 フレームにする
#define SHAIANFLAG_SPINNING (1 << 20)      // 0x100000, 回転斬りの最中

// 16色パレットを別のパレットへ少しずつ寄せる, WormPaletteFade と同じ流れだが出力の後に3本のパレットを挟む
typedef struct {
  rgb555 pltt[16];       // 0x00, r/g/b から合成した出力, フェード中はスプライトがこれを指す
  rgb555 unk_20[3][16];  // 0x20, どれも OBJ パレット 629 の写し
  u16 timer;             // 0x80, 残りの歩数, 256 にしておくとフェード元を pltt でなく元のパレットから取る
  u16 plttID;            // 0x82, 遷移先のパレット番号
  s16 r[16];             // 0x84, 8.8固定小数の現在値
  s16 g[16];             // 0xA4
  s16 b[16];             // 0xC4
  s16 stepR[16];         // 0xE4, (遷移先 - 遷移元) を歩数で割ったもの
  s16 stepG[16];         // 0x104
  s16 stepB[16];         // 0x124
} ShaianPaletteFade;
static_assert(sizeof(ShaianPaletteFade) == 324);

// 中ボス, シャイアン(ENEID_SHAIAN)
// 攻撃: トマホーク, 回転斬り, 振り下ろし
// HPが減るとアイテムを使おうとする, そのときに怯ませれば妨害できそのアイテムも落とす
typedef struct {
  Enemy e;
  u8 unk_654[4];            // 0x654
  ShaianPaletteFade fade;   // 0x658
  Vec3 itemIconPos;         // 0x79C, 取り出したアイテムのアイコンを飛ばす先, 頭の右上
  s8 items[3];              // 0x7A4, '.i[1,3,5]=-1', 体力が減ると使うアイテムの ID, 使ったら -1
  u8 unk_7a7;               // 0x7A7
  u16 itemValues[3];        // 0x7A8, '.i[2,4,6]=0', items と対の効き目, 0 番は maxHp の 1/10 単位の回復量
  u16 itemDropScriptID;     // 0x7AE, '.i[0]=0', 探っている途中で叩かれてアイテムを落としたときに流すスクリプト
  s16 itemTimer;            // 0x7B0, 足を速くする/姿を消すアイテムの残りフレーム, itemValues から写す
  u16 blinkTimer;           // 0x7B2, 姿を消す/現すときの点滅の残りフレーム, 30 から減る
  Hitbox chopHitbox;        // 0x7B4, 振り下ろしの攻撃判定
  Hitbox spinHitbox;        // 0x804, 回転斬りの攻撃判定
  Vec3 retreatDest;         // 0x854, プレイヤーから離れた経路ノード, SHAIANFLAG_RETREATING の間ここへ向かう
  Vec3 shadowPos;           // 0x85C, Enemy.auxShadow が指す位置, 体の向きに合わせて足もとからずらす
  u32 unk_864;              // 0x864
  u8 unk_868[20];           // 0x868
  u16 attackCooldowns[6];   // 0x87C, 技ごとの待ち, 毎フレーム減り 0 の技だけ出せる, [0] 振り下ろし, [1] トマホーク, [2] 回転斬り
  u16 attackIntervals[6];   // 0x888, '.P[0..5]=0', 技を出したときに attackCooldowns に入れる
  u32 lastHitWeapon;        // 0x894, 前に受けた攻撃の Enemy.weaponExpMask
  ShaianFlags flags;        // 0x898
  u8 sameWeaponHits;        // 0x89C, 同じ種類の攻撃を続けて受けた数, 2 以上になると見切って受け止める (VO_SHAIAN_MIKK)
  u8 hitStreak;             // 0x89D, hitStreakTimer の間に重ねて受けた数, 2 になるとひるむ
  u8 hitStreakTimer;        // 0x89E, 最初の被弾で 180 になり毎フレーム減る, 0 になったら hitStreak を 0 に戻す
  u8 recoverStun;           // 0x89F, 技の後に動きを止める長さ, hp が maxHp の 1/4 以下なら回転斬りの後は半分
  u32 nearDistSq;           // 0x8A0, プレイヤーとの距離の2乗がこれより小さいと離れる
  u32 farDistSq;            // 0x8A4, Enemy.unk_1e8 の写し, プレイヤーとの距離の2乗が nearDistSq との間にある間だけ向かっていく
  u16 itemSearchTime;       // 0x8A8, '.T=120', アイテムを探っている時間
  u16 recoverTime;          // 0x8AA, 技の後の副状態 3 で次へ動き出すまで待つフレーム
  s8 recentNodes[3];        // 0x8AC, 直近に向かった経路ノード, -1 は空き
  u8 recentNodeIdx;         // 0x8AF, recentNodes の次に書く位置
  u16 itemHpThresholds[3];  // 0x8B0, hp がこれを下回ると items の同じ番号を使う, 最大 hp の 3/10, 6/10, 2/10
  u8 unk_8b6;               // 0x8B6
  u8 soundCooldown;         // 0x8B7, 効果音を鳴らすと 10 になり毎フレーム減る, 0 の間だけ次を鳴らす
  NavAgent navAgent;        // 0x8B8, Enemy.navAgent が指す
  Vec3 pathNodePos;         // 0x8DC, Enemy.pathNodePos が指す
} Shaian;
static_assert(sizeof(Shaian) == 2276);

static inline bool8 Shaian_TestFlags(Shaian* p, ShaianFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

// anim 番の variant を流す, MainSprite では anim + variant 番を flags の向きと逆再生で流し, 同じものが流れていれば何もしない
static inline void Shaian_PlayDirAnim(Shaian* p, u32 anim, u32 variant, u32 flags) {
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* s;

    (p->e).playingAnim = anim;
    s = &(p->e).s->aux;
    AuxAnim_SetAnim(&s->anim, s->animFile, anim, variant, flags);
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 mode;

    anim += variant;
    if ((p->e).playingAnim == anim && !(p->e).animForceRestart && ((flags == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) || (flags == 0 && !(s->flags & SPRFLAG_XFLIP)))) {
      return;
    }
    (p->e).playingAnim = anim;
    mode = (flags & ANIM_PLAY_REVERSE) ? MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE : MAIN_ANIM_FORCE_POSE;
    MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, mode);
    if (flags & ANIM_PLAY_XFLIP) {
      s->flags |= SPRFLAG_XFLIP;
    } else {
      s->flags &= ~SPRFLAG_XFLIP;
    }
  }
  (p->e).animForceRestart = FALSE;
}

static inline void Shaian_SetFlags(Shaian* p, ShaianFlags bit) { p->flags |= bit; }
static inline void Shaian_ClearFlags(Shaian* p, ShaianFlags bit) { p->flags &= ~bit; }

// 自分が何番目の参加者かを返す, セッションが無ければ -1
static inline s32 LinkSession_GetPlayerIdx(void) {
  LinkSession* p = gLinkSession;

  if (p == NULL) {
    return -1;
  }
  return p->playerIdx;
}

// 通信対戦で, この敵を攻撃したのが自分の画面のプレイヤーか (通信対戦でなければ常に TRUE)
static inline bool8 Enemy_IsHitByLocalPlayer(Enemy* p) {
  if (IsLinkPlay() && !(p->unk_4a0 & 0x20) && p->unk_4a0 != 0) {
    switch (LinkSession_GetPlayerIdx()) {
      case 0: {
        if (p->unk_4a0 != 1) return FALSE;
        break;
      }
      case 1: {
        if (p->unk_4a0 != 2) return FALSE;
        break;
      }
      case 2: {
        if (p->unk_4a0 != 4) return FALSE;
        break;
      }
      case 3: {
        if (p->unk_4a0 != 8) return FALSE;
        break;
      }
    }
  }
  return TRUE;
}

static inline void Shaian_ClearOwnerFlags(Shaian* p, ShaianFlags bit) {
  Shaian* q = (p->e).owner;

  q->flags &= ~bit;
}

const STRING_DATA char s_eneinline_08252180[] = "../system/eneinline.h";
const STRING_DATA char s_cheyecom_c_08252198[] = "cheyecom.c";

// アニメのコマ (animCmdIdx の下位3ビット) ごとの歩く速さ, SHAIANFLAG_UNK_0 が立っていれば [0], 無ければ [1]
const u16 sShaianWalkSpeeds[2][8] = {
    {576, 696, 864,  480, 576, 624, 840,  696},
    {748, 904, 1123, 624, 748, 811, 1092, 904},
};  // 0x085ADB6C

void Entity081f7de4_Spawn(Vec3* pos, u32 rotation);
s32 ItemIconPopupManager_AddIcon(ItemCategory32 category, item32_t itemID, u32 kind, u32 playerIdx, Vec3* pos, Vec3* destPos, u32 duration, u32 key);
void Entity081f7de4_RemoveAll(void);
void TomahawkManager_VanishAll(void);
void Tomahawk_Spawn(Vec3* pos, s32 angle, s32 homingTime, s32 turnSpeed, s32 homingDelay, s32 speed, s32 rotation, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes);
void HUD_ShowEnemyGauge(s32 moverID, s32 hp, u16 maxHP, u16 cells, s32 flash);
void Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, u32 kind);
void Shaian_SpawnFootDust(Shaian* p, u32 count);
void Shaian_OnHurt(Hitbox* a, Hitbox* b, Shaian* p);
void Shaian_DropItem(Shaian* p);
void Shaian_UpdateCloakBlink(Shaian* p);
void Shaian_OnHit(Hitbox* a, Hitbox* b, Shaian* p);
void Shaian_OnChopHit(Hitbox* a, Hitbox* b, Shaian* p);
void Shaian_ClearRecentNodes(Shaian* p);
void Shaian_SetSpritePltt(Shaian* p, rgb555* pltt, u16 plttID);
void Shaian_StateUseItem(Shaian* p, s32 timer);
void Shaian_StateTakeOutItem(Shaian* p);
void FUN_08180494(Shaian* p);
void FUN_0817fd8c(Shaian* p);
bool8 Shaian_IsPlayerInFront(Shaian* p);
bool8 Shaian_IsPosInFront(Shaian* p, Vec3* pos);
void Shaian_SpawnGuardSpark(Shaian* p);
void Shaian_StateWaitForRoute(Shaian* p);
void Shaian_StateChase(Shaian* p);
void Shaian_AnimNotice(Shaian* p);
void Shaian_RouteTo(Shaian* p, WorldPos* pos);
void Shaian_StepTowardDest(Shaian* p);
bool8 Shaian_TryUseItem(Shaian* p);
void Shaian_PickFarPathNode(Shaian* p, Vec3* to, Vec3* from, s32 minDist);
void Shaian_StateTomahawk(Shaian* p);
void Shaian_StateSpin(Shaian* p);
void Shaian_StateStunned(Shaian* p);
void Shaian_StateWait(Shaian* p);

void Shaian_SubNotice(Shaian*);
void Shaian_SubLostPlayer(Shaian*);

void (*const sShaianHandlerTable3[2])(Shaian*) = {
    Shaian_SubNotice,
    Shaian_SubLostPlayer,
};  // 0x085ADB8C

void Shaian_SubChop(Shaian*);
void Shaian_SubTomahawk(Shaian*);
void Shaian_SubSpin(Shaian*);
void Shaian_SubRecover(Shaian*);

void (*const sShaianHandlerTable4[4])(Shaian*) = {
    Shaian_SubChop,
    Shaian_SubTomahawk,
    Shaian_SubSpin,
    Shaian_SubRecover,
};  // 0x085ADB94

void Shaian_SubDecide(Shaian*);
void Shaian_SubWalk(Shaian*);
void Shaian_SubChase(Shaian*);
void Shaian_SubTurn(Shaian*);
void Shaian_SubTurnThenWait(Shaian*);
void FUN_08182d1c(Shaian*);
void Shaian_SubSearchItem(Shaian*);
void FUN_08182de8(Shaian*);
void Shaian_SubCenterOnTile(Shaian*);

// clang-format off
void (*const sShaianHandlerTable2[22])(Shaian*) = {
    Shaian_SubDecide,
    NULL,
    Shaian_SubWalk,
    (void*)FUN_080f2364,
    NULL,
    (void*)FUN_080f2ec0,
    (void*)FUN_080f2d04,
    (void*)FUN_080f2a40,
    (void*)FUN_080f31c4,
    (void*)FUN_080f19cc,
    (void*)FUN_080f33e8,
    (void*)FUN_080f34a0,
    (void*)FUN_080f0e78,
    (void*)FUN_080f11d0,
    (void*)FUN_080f12c4,
    Shaian_SubChase,
    Shaian_SubTurn,
    Shaian_SubTurnThenWait,
    FUN_08182d1c,
    Shaian_SubSearchItem,
    FUN_08182de8,
    Shaian_SubCenterOnTile,
};  // 0x085ADBA4
// clang-format on

// animTable の各動作にシャイアンのアニメ番号を割り当てる
void Shaian_InitAnims(Shaian* p) {
  Enemy_SetAnimEntry(&p->e, 16, 0, 0);
  Enemy_SetAnimEntry(&p->e, 0, 2, 0);
  Enemy_SetAnimEntry(&p->e, 1, 12, 0);
  Enemy_SetAnimEntry(&p->e, 15, 16, 0);
  Enemy_SetAnimEntry(&p->e, 17, 18, 0);
  Enemy_SetAnimEntry(&p->e, 18, 20, 0);
  Enemy_SetAnimEntry(&p->e, 19, 22, 0);
  Enemy_SetAnimEntry(&p->e, 20, 23, 0);
  Enemy_SetAnimEntry(&p->e, 21, 24, 0);
  Enemy_SetAnimEntry(&p->e, 3, 25, 0);
  Enemy_SetAnimEntry(&p->e, 14, 29, 0);
  Enemy_SetAnimEntry(&p->e, 10, 34, 0);
  Enemy_SetAnimEntry(&p->e, 22, 38, 0);
  Enemy_SetAnimEntry(&p->e, 23, 36, 0);
}

// 向かっていく間 (SHAIANFLAG_UNK_0) とそれ以外で, 待機・歩き・振り向きのアニメを切り替える
void Shaian_SelectAnimSet(Shaian* p) {
  if (Shaian_TestFlags((p->e).owner, SHAIANFLAG_UNK_0)) {
    Enemy_SetAnimEntry(&p->e, 16, 0, 0);
    Enemy_SetAnimEntry(&p->e, 0, 2, 0);
    Enemy_SetAnimEntry(&p->e, 1, 12, 0);
    Enemy_SetAnimEntry(&p->e, 3, 25, 0);
  } else {
    Enemy_SetAnimEntry(&p->e, 16, 1, 0);
    Enemy_SetAnimEntry(&p->e, 0, 7, 0);
    Enemy_SetAnimEntry(&p->e, 1, 14, 0);
    Enemy_SetAnimEntry(&p->e, 3, 27, 0);
  }
}

// 106/106命令, 残差は return FALSE の置き場所だけ, 原典はフラグが立っていない枝と attackCooldowns[1] が残っている枝が真ん中の同じ return FALSE へ飛ぶ
// 試済: 早期 return, 内側の return FALSE, 最後の枝を else で return FALSE
NON_MATCH bool8 Shaian_TryStartAttack(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;

  if (Shaian_TestFlags(q, SHAIANFLAG_UNK_0)) {
    if ((p->e).playerDistSq < 0xFFFF) {
      if (q->attackCooldowns[0] == 0 && Shaian_IsPlayerInFront(p)) {
        Enemy_ResetState(&p->e, 0, 2, 0);
        return TRUE;
      }
      if (q->attackCooldowns[2] == 0) {
        Enemy_ResetState(&p->e, 0, 2, 2);
        return TRUE;
      }
    }
    if (q->attackCooldowns[1] == 0) {
      Enemy_ResetState(&p->e, 0, 2, 1);
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Shaian_TryStartAttack.inc");
#endif
}

// プレイヤーが unk_1e8 以内で, 向いている方から unk_1fd 以内の角度にいれば気付く
bool8 Shaian_TryDetectPlayer(Shaian* p) {
  if ((p->e).playerDistSq <= (p->e).unk_1e8) {
    s32 d = (p->e).playerAngle - (p->e).mover.angle;

    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (abs(d) <= (p->e).unk_1fd) {
      return TRUE;
    }
  }
  return FALSE;
}

void Shaian_OnAttackRequest(Shaian* p) {}

void FUN_0817bbe4(Shaian* p) {}

// 歩くアニメのコマごとの速さを返し, 踏み込むコマで砂ぼこりを立てる
s32 Shaian_GetMoveSpeed(Shaian* p) {
  MainSprite* s = &(p->e).s->main.spr;

  if (s->animCmdTimer == 0) {
    if (s->animCmdIdx == 0 || s->animCmdIdx == 4) {
      Shaian_SpawnFootDust(p, 3);
    }
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    if (Shaian_TestFlags((p->e).owner, SHAIANFLAG_UNK_0)) {
      return sShaianWalkSpeeds[0][s->animCmdIdx & 7];
    }
    return sShaianWalkSpeeds[1][s->animCmdIdx & 7];
  }
  return 0;
}

// 428/428命令の下書き, 段差と階段の判定の分岐の並びが原典 (goto で合流する形) と違い 45 箇所ずれる, 呼び出し元が無い関数, 1回目の下書きで切り上げ
// angle の向きから 90 度ずつ回して, 逆向き以外で段差を越えて 1 歩で移れる隣のタイルの向きを返す, 無ければ -1
NON_MATCH s32 Shaian_FindWalkableDir(Shaian* p, s32 angle) {
#ifdef NONMATCHING_C
  s32 dir = ((angle + 0x10) & 0xFF) >> 6;
  s32 back = (dir + 2) & 3;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (dir != back) {
      u32 to;
      s32 toStairs, fromStairs;
      TileAttr attr;
      WorldPos pos;
      s32 toHeight, fromHeight, diff, step;
      bool8 ok;

      switch (dir) {
        case 0: {
          to = (p->e).tileIdx + 1;
          break;
        }
        case 1: {
          to = (p->e).tileIdx + gCollisionMap->tiledata->width;
          break;
        }
        case 2: {
          to = (p->e).tileIdx - 1;
          break;
        }
        case 3: {
          to = (p->e).tileIdx - gCollisionMap->tiledata->width;
          break;
        }
        default: {
          to = (p->e).tileIdx;
          break;
        }
      }
      toStairs = TileAtIndex(to)->heightStairs >> 4;
      fromStairs = TileAtIndex((p->e).tileIdx)->heightStairs >> 4;
      attr = TileAtIndex(to)->attr;
      TilePosAtIndex(&pos, to);
      toHeight = TileHeightAtIndex(to, &pos);
      TilePosAtIndex(&pos, (p->e).tileIdx);
      fromHeight = TileHeightAtIndex((p->e).tileIdx, &pos);
      diff = toHeight - fromHeight;
      step = (((fromHeight + 0xFF) >> 8) - ((toHeight + 0xFF) >> 8)) << 8;
      ok = FALSE;
      if (!(attr & (TATTR_PLAYER_WALL | TATTR_ENEMY_WALL | TATTR_FALLDEATH))) {
        if (diff == 0) {
          ok = TRUE;
        } else {
          bool8 blocked = FALSE;

          if (toStairs == STAIRS_VERTICAL) {
            if (dir == 1) {
              blocked = (fromStairs == STAIRS_VERTICAL ? step - 256 : step) != 0;
            } else if (dir == 3) {
              blocked = step + 256 != 0;
            } else {
              blocked = TRUE;
            }
          } else if (toStairs == STAIRS_HORIZONTAL) {
            if (dir == 0) {
              blocked = (fromStairs == STAIRS_HORIZONTAL ? step - 256 : step) != 0;
            } else if (dir == 2) {
              blocked = step + 256 != 0;
            } else {
              blocked = TRUE;
            }
          }
          if (!blocked) {
            if (fromStairs == STAIRS_VERTICAL) {
              if (dir == 1) {
                blocked = toStairs == STAIRS_VERTICAL ? step - 256 != 0 : step != 256;
              } else if (dir == 3) {
                blocked = (toStairs == STAIRS_VERTICAL ? step + 256 : step) != 0;
              } else {
                blocked = TRUE;
              }
            } else if (fromStairs == STAIRS_HORIZONTAL) {
              if (dir == 0) {
                blocked = toStairs == STAIRS_HORIZONTAL ? step != 256 : step - 256 != 0;
              } else if (dir == 2) {
                blocked = (toStairs == STAIRS_HORIZONTAL ? step + 256 : step) != 0;
              } else {
                blocked = TRUE;
              }
            }
          }
          if (!blocked) {
            if ((fromStairs == STAIRS_VERTICAL && toStairs == STAIRS_VERTICAL) || (fromStairs == STAIRS_HORIZONTAL && toStairs == STAIRS_HORIZONTAL)) {
              ok = abs(diff) <= 256;
            } else {
              ok = abs(diff) < 256;
            }
          }
        }
      }
      if (ok) {
        return dir;
      }
    }
    dir = (dir + 1) & 3;
  }
  return -1;
#else
  INCFUNC("asm/func/Shaian_FindWalkableDir.inc");
#endif
}

// プレイヤーとの距離の閾値 (nearDistSq / farDistSq) を決める
void Shaian_InitDistances(Shaian* p) {
  Shaian* q = (p->e).owner;

  q->unk_864 = 0x19000;
  q->nearDistSq = 0x19000;
  q->farDistSq = (p->e).unk_1e8;
}

// 技ごとの待ちを減らす
void Shaian_TickAttackCooldowns(Shaian* p) {
  Shaian* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 6; i++) {
    if (q->attackCooldowns[i] != 0) {
      q->attackCooldowns[i]--;
    }
  }
}

// 292/298命令, Skeleton_PickWalkDest / Dog_PickWalkDest と同じタイル探索の割り当ての壁 (原典はフレーム 0x1C で &mover.pos をスタックに2つ置く), 1回目の下書きで切り上げ
// angle から 90 度ずつ回して 2 マス先までの歩けるタイルを探し, そこへ経路を引けたら TRUE, 向きは angle に戻す
NON_MATCH bool8 Shaian_PickWalkDest(Shaian* p, s32 angle) {
#ifdef NONMATCHING_C
  u32 target;
  s32 i;
  WorldPos pos;

  for (i = 0; i < 4; i++) {
    u32 tileIdx = (p->e).tileIdx;
    s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
    s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
    s32 idx;
    s32 n;

    switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
      case 0: {
        idx = tileIdx + 1;
        for (n = 0; n < 2; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx++;
        }
        target = idx - 1;
        break;
      }
      case 1: {
        idx = tileIdx + gCollisionMap->tiledata->width;
        for (n = 0; n < 2; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx += gCollisionMap->tiledata->width;
        }
        target = idx - gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        idx = tileIdx - 1;
        for (n = 0; n < 2; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx--;
        }
        target = idx + 1;
        break;
      }
      case 3: {
        idx = tileIdx - gCollisionMap->tiledata->width;
        for (n = 0; n < 2; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx -= gCollisionMap->tiledata->width;
        }
        target = idx + gCollisionMap->tiledata->width;
        break;
      }
      default: {
        target = (p->e).tileIdx;
        break;
      }
    }
    if (target != (p->e).tileIdx) {
      break;
    }
    (p->e).mover.angle += 64;
  }
  (p->e).mover.angle = angle;
  TilePosAtIndex(&pos, target);
  if (Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &pos)) {
    return TRUE;
  }
  (p->e).onRouteFailed(&p->e);
  return FALSE;
#else
  INCFUNC("asm/func/Shaian_PickWalkDest.inc");
#endif
}

// 攻撃を当ててきた相手がいれば, その相手を追う対象にして向き直る
bool8 Shaian_NoticeAttacker(Shaian* p) {
  if ((p->e).hitTargetID > 0) {
    Vec3 diff;

    Enemy_Alert(&p->e);
    CLEAR_FLAGS((p->e).unk_222, ENEMY222_UNK_1);
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
    (p->e).playerMover = EnemyTargetManager_FindOwnerByID((p->e).hitTargetID);
    (p->e).unk_25e = GetCollisionTileIdx(&(p->e).playerMover->pos);
    Vec3_Delta(&diff, &(p->e).mover.pos, &(p->e).playerMover->pos);
    (p->e).mover.angle = ArcTan2_8(diff.x, diff.z);
    Shaian_ClearOwnerFlags(p, SHAIANFLAG_CHASING | SHAIANFLAG_UNK_5);
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  }
  return FALSE;
}

// 169/168命令, 残差は経路の向きから角度を作る式の & 7 の定数を原典は1本のレジスタで使い回すのに2回作る所だけ (他の敵の _Init と同じ式)
// 試済: flags を Shaian_SetFlags で立てる (これで &flags の持ち越しは一致), if の向き
// '.p' があればその位置に置き, 無ければ経路に乗せて最初のノードの向きを向く, '.P' で技の間隔を読む
NON_MATCH void Shaian_InitPosAndIntervals(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  s32 i;

  if (VM_SeekToNamedArg('p')) {
    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).tileIdx = GetCollisionTileIdx(&(p->e).mover.pos);
    (p->e).floorY = TileHeightAtIndex((p->e).tileIdx, &(p->e).mover.pos);
    (p->e).heightAboveFloor = (p->e).mover.pos.y - (p->e).floorY;
    (p->e).mover.pos.y = (p->e).floorY;
  } else {
    Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_250, (p->e).unk_251, (p->e).unk_252);
    (p->e).mover.angle = ((((p->e).pathWalker.node->delay >> 12 & 7) + 5) & 7) << 5;
  }
  if (VM_SeekToNamedArg('P')) {
    for (i = 0; i < 6; i++) {
      q->attackIntervals[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  Shaian_SetFlags(q, SHAIANFLAG_UNK_0);
  Shaian_ClearRecentNodes(p);
#else
  INCFUNC("asm/func/Shaian_InitPosAndIntervals.inc");
#endif
}

// 830/849命令, 後半は Shaian_SubNotice / enedefault.c の FUN_080f12c4 と同じ壁 (原典は状態や下位状態のフィールドのアドレスをスタックに作り置く), 1回目の下書きで切り上げ
// プレイヤーとの距離で次を決める, nearDistSq より近ければ反対へ離れ, farDistSq 以内なら経路が引けるまで待ち, それより遠ければ追いかけるか見回す
NON_MATCH void Shaian_ReactToDistance(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  s32 tile;
  s32 idx;
  bool8 chased;

  Enemy_ClearPendingState(&p->e, s_cheyecom_c_08252198, 383);
  if ((p->e).playerDistSq < q->nearDistSq) {
    u8 angle = (p->e).mover.angle;

    (p->e).mover.angle = (p->e).playerAngle + 128;
    if (!Shaian_PickWalkDest(p, angle)) {
      return;
    }
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 15);
    return;
  }
  if ((p->e).playerDistSq <= q->farDistSq) {
    Enemy_ResetState(&p->e, 3, 1, 0);
    Enemy_EnterState(&p->e, Shaian_StateWaitForRoute, ES_UNK_39);
    return;
  }
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->kind <= 3) {
      idx = m->kind;
    }
    if (m == NULL || idx < 0) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }
  if (tile != (p->e).tileIdx && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    chased = Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos);
    if (!chased) {
      (p->e).onRouteFailed(&p->e);
    }
  } else if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
    chased = FALSE;
  } else {
    (p->e).unk_222 &= ~ENEMY222_UNK_2;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 5);
      {
        Vec3* dst = (p->e).pathNodePos;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
      (p->e).pathNodePos->val = 0;
    }
    {
      u8 angle = (p->e).mover.angle;

      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
        s32 i;
        u32 a;

        for (i = 0; i <= 3; i++) {
          a = (Random() & 3) << 6;
          if (a != angle) {
            break;
          }
        }
        if (i > 3) {
          a = angle;
        }
        (p->e).lookAngle = a;
        (p->e).savedHandlerState = (p->e).handlerState;
        (p->e).savedState = (p->e).state;
        (p->e).savedSubState0 = (p->e).subState0;
        (p->e).savedSubState1 = (p->e).subState1;
        (p->e).savedSubState2 = (p->e).subState2;
        (p->e).lookBaseAngle = angle;
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
        Enemy_ResetState(&p->e, 3, 1, 0);
        (p->e).unk_542 = 6;
      }
    }
    Enemy_StepToFloorEdge(&p->e);
    (p->e).animSpeedDiv = 2;
    chased = FALSE;
  }
  if (chased) {
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
    Enemy_ResetState(&p->e, 0, 0, 12);
  }
#else
  INCFUNC("asm/func/Shaian_ReactToDistance.inc");
#endif
}

// 経路のノードを乱数で選ぶ, 今のノードと同じなら次のノードにする
void Shaian_PickRandomPathNode(Shaian* p) {
  PathWalker* w = &(p->e).pathWalker;
  u8 node = Mod(Random(), w->path->nodeCount);

  if (node == w->nodeIdx) {
    node = Mod(node + 1, w->path->nodeCount);
  }
  w->nodeIdx = node;
  w->waitTimer = 0;
  w->node = &Map_GetPathNodes(w->path)[w->nodeIdx];
}

// 向きから8方向のアニメの番号と左右反転を決める, 左向きは右向きのアニメを反転して使う
void Shaian_GetAnimVariant(u16 angle, u32* variant, u32* xflip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *variant = 8 - dir;
    *xflip = 1;
  } else {
    *variant = dir;
    *xflip = 0;
  }
}

// 408/427命令, Shaian_PickWalkDest と同じタイル探索の壁に加え, tried の 0 埋めを原典はポインタを減らすループで書く, 1回目の下書きで切り上げ
// 経路の目的地の 4 方向の向きから順に 1〜2 マス先の歩けるタイルを探し, 見つかったらそこへ経路を引き直す
NON_MATCH void Shaian_StepTowardDest(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  u32 orig = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) << 6;
  WorldPos pos;
  u8 tried[4];
  s32 dir, start, i, tries;

  Vec3_Delta(&pos, &(p->e).mover.pos, &(p->e).navAgent->dest);
  dir = ((ArcTan2_8(pos.x, pos.z) + 0x20) & 0xFF) >> 6;
  (p->e).mover.angle = dir << 6;
  start = (dir + 1) & 3;
  for (i = 3; i >= 0; i--) {
    tried[i] = 0;
  }
  tries = 0;
  while (TRUE) {
    u32 tileIdx;
    u32 target;
    s32 height;
    s32 fromStairs;
    s32 idx;
    s32 n;
    s32 steps;
    u32 prev;

    steps = 2;
    if (Shaian_TestFlags((p->e).owner, SHAIANFLAG_RETREATING)) {
      steps = 2;
      if (Shaian_IsPosInFront(p, &q->retreatDest)) {
        steps = 1;
      }
    }
    tileIdx = (p->e).tileIdx;
    height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
    fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
    switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
      case 0: {
        idx = tileIdx + 1;
        for (n = 0; n < steps; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx++;
        }
        target = idx - 1;
        break;
      }
      case 1: {
        idx = tileIdx + gCollisionMap->tiledata->width;
        for (n = 0; n < steps; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx += gCollisionMap->tiledata->width;
        }
        target = idx - gCollisionMap->tiledata->width;
        break;
      }
      case 2: {
        idx = tileIdx - 1;
        for (n = 0; n < steps; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx--;
        }
        target = idx + 1;
        break;
      }
      case 3: {
        idx = tileIdx - gCollisionMap->tiledata->width;
        for (n = 0; n < steps; n++) {
          if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
            break;
          }
          idx -= gCollisionMap->tiledata->width;
        }
        target = idx + gCollisionMap->tiledata->width;
        break;
      }
      default: {
        target = (p->e).tileIdx;
        break;
      }
    }
    if (target != (p->e).tileIdx) {
      TilePosAtIndex(&pos, target);
      Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &pos);
      (p->e).navAgent->waypoint = (p->e).navAgent->dest;
      return;
    }
    tried[(p->e).mover.angle >> 6] = 1;
    prev = (p->e).mover.angle;
    if (tries == 0 && prev != orig) {
      (p->e).mover.angle = orig;
    } else {
      for (i = 0; i < 4; i++) {
        s32 k = (start + i) & 3;

        if (tried[k] != 1) {
          (p->e).mover.angle = 64 - (64 << k);
          break;
        }
      }
      if (prev == (p->e).mover.angle) {
        return;
      }
    }
    if (++tries > 3) {
      return;
    }
  }
#else
  INCFUNC("asm/func/Shaian_StepTowardDest.inc");
#endif
}

// 546/556命令の下書き, 原典はタイル探索を向きの2つの枝それぞれに展開している (inline に切り出すと 70 箇所ずれ), Shaian_PickWalkDest と同じタイル探索の壁, 1回目で切り上げ
// Enemy_MoveAlongNav と同じく waypoint へ進み, 目的地に着いていれば 2, 逃げている間は逃げ先の横に並んだら 1 マス先へ進めるかを見て 2
NON_MATCH u8 Shaian_MoveAlongNav(Shaian* p, NavAgent* nav, u32 rangeX, u32 rangeZ, s32 speed) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  s16 dx, dz;

  if (abs(nav->dest.x - (p->e).mover.pos.x) <= rangeX && abs(nav->dest.z - (p->e).mover.pos.z) <= rangeZ) {
    return 2;
  }
  dx = nav->waypoint.x - (p->e).mover.pos.x;
  dz = nav->waypoint.z - (p->e).mover.pos.z;
  if (dx != 0 || dz != 0) {
    s32 vx, vz;

    (p->e).mover.angle = ArcTan2_8(dx, dz);
    vx = FixToInt(16, speed * COS((p->e).mover.angle));
    vz = FixToInt(16, speed * SIN((p->e).mover.angle));
    (p->e).mover.delta.x += abs(vx) > 10 ? vx : 0;
    (p->e).mover.delta.z += abs(vz) > 10 ? vz : 0;
    if (Shaian_TestFlags(q, SHAIANFLAG_RETREATING)) {
      s16 rx = q->retreatDest.x - (p->e).mover.pos.x;
      s16 rz = q->retreatDest.z - (p->e).mover.pos.z;
      u8 saved;
      u32 target;

      switch ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) {
        case 0:
        case 2: {
          if (abs(rx) >= rangeX) {
            return 0;
          }
          saved = (p->e).mover.angle;
          (p->e).mover.angle = ArcTan2_8(0, rz);
          break;
        }
        case 1:
        case 3: {
          if (abs(rz) >= rangeZ) {
            return 0;
          }
          saved = (p->e).mover.angle;
          (p->e).mover.angle = ArcTan2_8(rx, 0);
          break;
        }
        default: {
          return 0;
        }
      }
      {
        u32 tileIdx = (p->e).tileIdx;
        s32 height = TileHeightAtIndex(tileIdx, &(p->e).mover.pos);
        s32 fromStairs = TileAtIndex(tileIdx)->heightStairs >> 4;
        s32 idx;
        s32 n;

        switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
          case 0: {
            idx = tileIdx + 1;
            for (n = 0; n < 1; n++) {
              if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
                break;
              }
              idx++;
            }
            target = idx - 1;
            break;
          }
          case 1: {
            idx = tileIdx + gCollisionMap->tiledata->width;
            for (n = 0; n < 1; n++) {
              if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
                break;
              }
              idx += gCollisionMap->tiledata->width;
            }
            target = idx - gCollisionMap->tiledata->width;
            break;
          }
          case 2: {
            idx = tileIdx - 1;
            for (n = 0; n < 1; n++) {
              if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
                break;
              }
              idx--;
            }
            target = idx + 1;
            break;
          }
          case 3: {
            idx = tileIdx - gCollisionMap->tiledata->width;
            for (n = 0; n < 1; n++) {
              if (!CanWalkToAdjacentTile(tileIdx, idx, height, fromStairs)) {
                break;
              }
              idx -= gCollisionMap->tiledata->width;
            }
            target = idx + gCollisionMap->tiledata->width;
            break;
          }
          default: {
            target = (p->e).tileIdx;
            break;
          }
        }
      }
      (p->e).mover.angle = saved;
      if (target != (p->e).tileIdx) {
        return 2;
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Shaian_MoveAlongNav.inc");
#endif
}

// fade.unk_20 の3本に OBJ パレット 629 を写す
void FUN_0817d6d4(Shaian* p) {
  Shaian* q = (p->e).owner;
  rgb555* src = &gObjPlttData[629 * 16];
  s32 i, j;

  for (i = 0; i < 3; i++) {
    for (j = 0; j < 16; j++) {
      q->fade.unk_20[i][j] = src[j];
    }
  }
}

// 今の色 (フェード前なら fromPlttID の色) から toPlttID の色へ steps 歩で寄せるフェードを始める
void Shaian_StartPaletteFade(Shaian* p, s32 toPlttID, s32 fromPlttID, s32 steps) {
  Shaian* self = p;
  ShaianPaletteFade* fade = &self->fade;
  rgb555* dst = &gObjPlttData[toPlttID * 16];
  rgb555* src = &gObjPlttData[fromPlttID * 16];
  s32 i;

  fade->plttID = toPlttID;
  for (i = 0; i < 16; i++) {
    s32 color = fade->timer != 256 ? fade->pltt[i] : src[i];

    fade->stepR[i] = ((dst[i] & 31) - (color & 31)) << 8;
    fade->stepG[i] = (((dst[i] >> 5) & 31) - ((color >> 5) & 31)) << 8;
    fade->stepB[i] = (((dst[i] >> 10) & 31) - ((color >> 10) & 31)) << 8;
    fade->stepR[i] = Div(fade->stepR[i], steps);
    fade->stepG[i] = Div(fade->stepG[i], steps);
    fade->stepB[i] = Div(fade->stepB[i], steps);
    fade->r[i] = (color & 31) << 8;
    fade->g[i] = ((color >> 5) & 31) << 8;
    fade->b[i] = ((color >> 10) & 31) << 8;
  }
  fade->timer = steps;
  SET_FLAGS(self->flags, SHAIANFLAG_FADING);
}

// 201/201命令, 残差はループ前に積む pltt/r/stepR などのポインタの退避先 (sp と r10) の入れ替わりだけ
// 試済: Ax_StepPaletteFade の形, plttID のローカル, MainSprite* で plttID, flags ポインタの位置と宣言順, Shaian_ClearFlags(q) で q の割り当ては一致
NON_MATCH s32 Shaian_StepPaletteFade(Shaian* p) {
#ifdef NONMATCHING_C
  EnemyFlags* flags;
  Shaian* q;
  ShaianPaletteFade* fade;
  s32 i;

  if (Enemy_IsDead(&p->e)) {
    return FALSE;
  }
  q = (p->e).owner;
  if (!Shaian_TestFlags(q, SHAIANFLAG_FADING)) {
    return FALSE;
  }
  fade = &q->fade;
  if (fade->timer == 0) {
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
      s32 plttID = (p->e).plttBase + (p->e).variant;

      if ((p->e).spriteKind == 0) {
        Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, plttID);
      } else {
        (p->e).s->main.spr.pltt = &gObjPlttData[plttID * 16];
      }
      {
        MainSprite* spr = &(p->e).s->main.spr;

        spr->plttID = 626;
      }
      Shaian_ClearFlags(q, SHAIANFLAG_FADING);
    }
    return TRUE;
  }
  flags = &(p->e).flags;
  for (i = 0; i < 16; i++) {
    fade->r[i] += fade->stepR[i];
    fade->g[i] += fade->stepG[i];
    fade->b[i] += fade->stepB[i];
    fade->pltt[i] = FixToInt(8, fade->r[i]) | (FixToInt(8, fade->g[i]) << 5) | (FixToInt(8, fade->b[i]) << 10);
  }
  fade->timer--;
  if (!TEST_FLAGS(*flags, ENEFLAG_UNK_15 | ENEFLAG_UNK_25)) {
    Shaian_SetSpritePltt(p, fade->pltt, 627);
  }
  if (fade->timer == 0) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Shaian_StepPaletteFade.inc");
#endif
}

// unk_8b6 が残っている間, 前半は ENEFLAG4_UNK_5, 最後の 10 フレームは ENEFLAG4_UNK_4 を立てる
void FUN_0817da34(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (q->unk_8b6 != 0) {
    if (q->unk_8b6 < 10) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
    } else if (q->unk_8b6 < 30) {
      SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
    }
    q->unk_8b6--;
  }
}

// 影の位置を足もとから体の向きに合わせてずらす, 回転斬りの間はずらさない
void Shaian_UpdateShadowPos(Shaian* p) {
  Shaian* q = (p->e).owner;
  s32 a = ((p->e).mover.angle + 0x20) & 0xFF;

  q->shadowPos = (p->e).mover.pos;
  if ((p->e).state == ES_DYING) {
    switch (a >> 6) {
      case 0: {
        q->shadowPos.z -= 32;
        break;
      }
      case 1: {
        q->shadowPos.x -= 32;
        break;
      }
      case 2: {
        q->shadowPos.x -= 48;
        q->shadowPos.z += 6;
        break;
      }
      case 3: {
        q->shadowPos.x += 10;
        q->shadowPos.z -= 24;
        break;
      }
      default: {
        return;
      }
    }
  }
  if (Shaian_TestFlags(q, SHAIANFLAG_SPINNING)) {
    return;
  }
  switch (a >> 6) {
    case 0: {
      q->shadowPos.z -= 32;
      break;
    }
    case 1: {
      q->shadowPos.x -= 32;
      break;
    }
    case 2: {
      q->shadowPos.x -= 24;
      q->shadowPos.z -= 6;
      break;
    }
    case 3: {
      q->shadowPos.x -= 6;
      q->shadowPos.z -= 32;
      break;
    }
  }
}

// 足もとに count 個の砂ぼこりを立てる
void Shaian_SpawnFootDust(Shaian* p, u32 count) {
  Vec3 range;
  Vec3 vel;

  VEC3_SET(range, 32, 0, 32);
  Vec3_Clear(&vel);
  DustManager_Spawn(&(p->e).mover.pos, &vel, &range, count, 2, 4);
}

void Shaian_SetSpritePltt(Shaian* p, rgb555* pltt, u16 plttID) {
  MainSprite* spr = &(p->e).s->main.spr;

  spr->pltt = pltt;
  spr->plttID = plttID;
}

// 使おうとしているアイテムのアイコンを頭の上に出して取り出す音を鳴らす
void Shaian_ShowItemIcon(Shaian* p) {
  Shaian* q = (p->e).owner;
  Vec3 pos = (p->e).mover.pos;
  s32 itemID;

  pos.x -= 102;
  pos.y += 320;
  q->itemIconPos = (p->e).mover.pos;
  q->itemIconPos.x += 128;
  q->itemIconPos.y += 240;
  if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM0)) {
    itemID = q->items[0];
  } else if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM1)) {
    itemID = q->items[1];
  } else if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM2)) {
    itemID = q->items[2];
  } else {
    itemID = 0;
  }
  ItemIconPopupManager_AddIcon(0, itemID, 3, 0, &pos, &q->itemIconPos, 24, (u32)p);
  PlaySound_082406e0(SE_PICKUP);
}

// 195/195命令, 残差は p を r12 (原典 r7) に置く割り当てと gRandomTable の番地の読み直し
// 試済: 位置のずらす順, Vec3_SetPolar, angle を u8
// 見切って受け止めたときに, 受けた攻撃の属性の火花を頭の上からプレイヤーの方へ散らす
NON_MATCH void Shaian_SpawnGuardSpark(Shaian* p) {
#ifdef NONMATCHING_C
  Vec3 pos = (p->e).mover.pos;
  Vec3 vel;
  u32 angle;
  s32 speed;
  u32 kind;

  pos.y += 220;
  pos.x += (Random() & 31) - 16;
  pos.z += (Random() & 31) - 16;
  angle = ((p->e).playerAngle - 32 + (Random() & 63)) & 0xFF;
  speed = (Random() & 15) + 10;
  Vec3_SetPolar(&vel, angle, speed);
  vel.y = (Random() & 31) - 16;
  if (TEST_FLAGS((p->e).flags6, HBATTR_ALL)) {
    kind = 7;
  } else if (TEST_FLAGS((p->e).flags6, HBATTR_SOL)) {
    kind = 1;
  } else if (TEST_FLAGS((p->e).flags6, HBATTR_DARK)) {
    kind = 2;
  } else if (TEST_FLAGS((p->e).flags6, HBATTR_FLAME)) {
    kind = 3;
  } else if (TEST_FLAGS((p->e).flags6, HBATTR_FROST)) {
    kind = 4;
  } else if (TEST_FLAGS((p->e).flags6, HBATTR_CLOUD)) {
    kind = 5;
  } else if (TEST_FLAGS((p->e).flags6, HBATTR_EARTH)) {
    kind = 6;
  } else {
    kind = 0;
  }
  Entity081ee2a0_SpawnDefault(&pos, &vel, 20, kind);
#else
  INCFUNC("asm/func/Shaian_SpawnGuardSpark.inc");
#endif
}

// 効果音の待ちを減らす
void Shaian_TickSoundCooldown(Shaian* p) {
  if (p->soundCooldown != 0) {
    p->soundCooldown--;
  }
}

// '.i' で持たせるアイテムと効き目を読み, 体力の割合で使い始める閾値を決める
void Shaian_InitItems(Shaian* p) {
  Shaian* q = (p->e).owner;
  s32 i;
  s32 tenth;

  if (VM_SeekToNamedArg('i')) {
    q->itemDropScriptID = VM_GetPC() != NULL ? VM_GetValue() : 0;
    for (i = 0; i < 3; i++) {
      q->items[i] = VM_GetPC() != NULL ? VM_GetValue() : -1;
      q->itemValues[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  } else {
    q->itemDropScriptID = 0;
    for (i = 0; i < 3; i++) {
      q->items[i] = -1;
      q->itemValues[i] = 0;
    }
  }
  q->itemSearchTime = VM_GetNamedArgValue('T', 120);
  tenth = Div((p->e).hp, 10);
  q->itemHpThresholds[0] = tenth * 3;
  q->itemHpThresholds[1] = tenth * 6;
  q->itemHpThresholds[2] = tenth * 2;
}

// 残っているアイテムの最初の番号を返す, 無ければ -1
s32 Shaian_FindItem(Shaian* p) {
  Shaian* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    if (q->items[i] != -1) {
      return i;
    }
  }
  return -1;
}

// idx 番のアイテムを使い切ったことにする
void Shaian_RemoveItem(Shaian* p, s32 idx) {
  Shaian* q = (p->e).owner;

  q->items[idx] = -1;
  q->itemValues[idx] = 0;
}

// hp が itemHpThresholds を下回っていて残っているアイテムがあれば, それを探る副状態 19 へ移る
bool8 Shaian_TryUseItem(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Shaian_FindItem(p) >= 0) {
    if ((p->e).hp < q->itemHpThresholds[0] && q->items[0] != -1) {
      Enemy_ResetState(&p->e, 0, 0, 19);
      SET_FLAGS(q->flags, SHAIANFLAG_USE_ITEM0 | SHAIANFLAG_SEARCHING | SHAIANFLAG_ITEM_ACTION);
      CLEAR_FLAGS(q->flags, SHAIANFLAG_USE_ITEM1 | SHAIANFLAG_USE_ITEM2);
      return TRUE;
    }
    if ((p->e).hp < q->itemHpThresholds[1] && q->items[1] != -1) {
      Enemy_ResetState(&p->e, 0, 0, 19);
      SET_FLAGS(q->flags, SHAIANFLAG_USE_ITEM1 | SHAIANFLAG_SEARCHING | SHAIANFLAG_ITEM_ACTION);
      CLEAR_FLAGS(q->flags, SHAIANFLAG_USE_ITEM0 | SHAIANFLAG_USE_ITEM2);
      return TRUE;
    }
    if ((p->e).hp < q->itemHpThresholds[2] && q->items[2] != -1) {
      Enemy_ResetState(&p->e, 0, 0, 19);
      SET_FLAGS(q->flags, SHAIANFLAG_USE_ITEM2 | SHAIANFLAG_SEARCHING | SHAIANFLAG_ITEM_ACTION);
      CLEAR_FLAGS(q->flags, SHAIANFLAG_USE_ITEM0 | SHAIANFLAG_USE_ITEM1);
      return TRUE;
    }
  }
  return FALSE;
}

// 263/260命令, 回復の部分まで一致, 残差は items[1]/[2] の枝で &q->flags をレジスタに写して持ち越す形と, 姿を出す flags 操作を MainSprite* 経由で書く形
// 試済: heal の型 (u16/s16/u32/s32), hp/maxHp のポインタ, 掛け算の順, 未: 枝のフラグ操作を Shaian_ClearFlags/SetFlags にする
// 取り出したアイテムを使う, items[0] は maxHp の 1/10 ずつ回復, [1] は足を速くし, [2] は姿を消す
NON_MATCH void Shaian_ApplyItem(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;

  if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM0)) {
    u16* maxHp = &(p->e).maxHp;
    s32 heal = Div(*maxHp, 10) * q->itemValues[0];
    s16* hp = &(p->e).hp;

    *hp += heal;
    if (*hp > *maxHp) {
      heal -= *hp - *maxHp;
      *hp = *maxHp;
    }
    (p->e).unk_48a = heal;
    if (Enemy_IsHitByLocalPlayer(&p->e)) {
      Vec3 v;

      HUD_ShowEnemyGauge((p->e).mover.id, (p->e).hp, (p->e).maxHp, (p->e).unk_25a, 0);
      Vec3_Clear(&v);
      if ((p->e).unk_48a != 0 || !((p->e).weaponExpMask & 0x4000)) {
        CreateDamageNumber(&(p->e).hurtbox, (p->e).unk_48a, 1, &(p->e).mover.pos, &v, 1);
      }
    }
    Shaian_RemoveItem(p, 0);
    CLEAR_FLAGS(q->flags, SHAIANFLAG_USE_ITEM0);
  } else if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM1)) {
    CLEAR_FLAGS(q->flags, SHAIANFLAG_CLOAK);
    (p->e).s->main.spr.flags &= ~SPRFLAG_HIDDEN;
    q->itemTimer = q->itemValues[1];
    SET_FLAGS(q->flags, SHAIANFLAG_HASTE);
    Shaian_RemoveItem(p, 1);
    CLEAR_FLAGS(q->flags, SHAIANFLAG_USE_ITEM1);
  } else if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM2)) {
    CLEAR_FLAGS(q->flags, SHAIANFLAG_HASTE);
    (p->e).animSpeedDiv = 1;
    q->itemTimer = q->itemValues[2];
    q->blinkTimer = 30;
    q->flags = (q->flags & ~SHAIANFLAG_CLOAK_SHOWN) | SHAIANFLAG_CLOAK | SHAIANFLAG_CLOAK_HIDDEN;
    Shaian_RemoveItem(p, 2);
    CLEAR_FLAGS(q->flags, SHAIANFLAG_USE_ITEM2);
  }
#else
  INCFUNC("asm/func/Shaian_ApplyItem.inc");
#endif
}

// 探っている途中のアイテムを手放して itemDropScriptID を (x, y, z, アイテム ID) で流す
void Shaian_DropItem(Shaian* p) {
  Shaian* q = (p->e).owner;
  u32 argv[4];
  ScriptArgs sa;

  if (q->itemDropScriptID == 0) {
    return;
  }
  argv[0] = (p->e).mover.pos.x;
  argv[1] = (p->e).mover.pos.y;
  argv[2] = (p->e).mover.pos.z;
  if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM0)) {
    argv[3] = q->items[0];
    Shaian_RemoveItem(p, 0);
    Shaian_ClearFlags(q, SHAIANFLAG_USE_ITEM0);
  } else if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM1)) {
    argv[3] = q->items[1];
    Shaian_RemoveItem(p, 1);
    Shaian_ClearFlags(q, SHAIANFLAG_USE_ITEM1);
  } else if (Shaian_TestFlags(q, SHAIANFLAG_USE_ITEM2)) {
    argv[3] = q->items[2];
    Shaian_RemoveItem(p, 2);
    Shaian_ClearFlags(q, SHAIANFLAG_USE_ITEM2);
  }
  sa.argc = 4;
  sa.argv = argv;
  VM_ExecByID(q->itemDropScriptID, &sa);
  PlaySound_082406e0(SONG_695);
}

// 残差は blinkTimer を ldrh の後 lsl/lsr で u16 に詰め直す形だけ (89/90命令), フラグ判定を Shaian_TestFlags(q, ...), 出し入れを MainSprite* を取る inline にするとそこまで縮む
// 試済: blinkTimer を s16, 点滅部分を u16 引数の inline に切り出し, 直接の flags 操作
NON_MATCH void Shaian_UpdateCloakBlink(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  u16 t = q->blinkTimer;

  if (t == 0) {
    if (TEST_FLAGS(q->flags, SHAIANFLAG_CLOAK_SHOWN)) {
      MainSprite_ClearFlags(&(p->e).s->main.spr, SPRFLAG_HIDDEN);
    } else if (TEST_FLAGS(q->flags, SHAIANFLAG_CLOAK_HIDDEN)) {
      MainSprite_SetFlags(&(p->e).s->main.spr, SPRFLAG_HIDDEN);
    }
  } else if (t < 20) {
    if ((t >> 2) & 1) {
      MainSprite_ClearFlags(&(p->e).s->main.spr, SPRFLAG_HIDDEN);
    } else {
      MainSprite_SetFlags(&(p->e).s->main.spr, SPRFLAG_HIDDEN);
    }
  } else if (t < 30) {
    if ((t >> 1) & 1) {
      MainSprite_ClearFlags(&(p->e).s->main.spr, SPRFLAG_HIDDEN);
    } else {
      MainSprite_SetFlags(&(p->e).s->main.spr, SPRFLAG_HIDDEN);
    }
  }
  if (q->blinkTimer != 0) {
    q->blinkTimer--;
  }
#else
  INCFUNC("asm/func/Shaian_UpdateCloakBlink.inc");
#endif
}

// 252/251命令, 残差は &q->flags を caller-saved に置いて UpdateCloakBlink の呼び出しをまたいでスタックへ退避する割り当て (原典は r5)
// 試済: flags ポインタの位置 (先頭/HASTE の後), HASTE を Shaian_ClearFlags で落とす, itemTimer の分岐の向き, 見えるかの判定を inline に切り出し
// 足を速くする/姿を消すアイテムの残りフレームを進める, 姿を消している間は千里眼の実や雷で姿を現し, 切れたら元のパレットに戻す
NON_MATCH void Shaian_UpdateItemEffects(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  ShaianFlags* flags;
  s32 see;

  if (Shaian_TestFlags(q, SHAIANFLAG_HASTE)) {
    if (q->itemTimer > 0) {
      (p->e).animSpeedDiv = 2;
      q->itemTimer--;
    } else if (q->itemTimer == 0) {
      (p->e).animSpeedDiv = 1;
      q->itemTimer--;
    } else {
      Shaian_ClearFlags(q, SHAIANFLAG_HASTE);
    }
  }
  flags = &q->flags;
  if (!Shaian_TestFlags(q, SHAIANFLAG_CLOAK)) {
    return;
  }
  if (q->itemTimer == 30) {
    q->blinkTimer = q->itemTimer;
    *flags = (*flags & ~SHAIANFLAG_CLOAK_HIDDEN) | SHAIANFLAG_CLOAK_SHOWN;
  }
  Shaian_UpdateCloakBlink(p);
  if (q->itemTimer > 0) {
    q->itemTimer--;
    if (gGameFlags & GAMEFLAG_LINK) {
      see = gPlayerPtr[0] != NULL && gPlayerPtr[0]->goodCondTimer != 0 && gPlayerPtr[0]->goodCondID == GOOD_SEE;
    } else if (gLightningTimer <= 0 && gStat->playerKind != 2) {
      see = gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE;
    } else {
      see = TRUE;
    }
    if (see) {
      if (!Shaian_TestFlags(q, SHAIANFLAG_CLOAK_SHOWN) && Shaian_TestFlags(q, SHAIANFLAG_CLOAK_HIDDEN)) {
        q->blinkTimer = 30;
        *flags = (*flags | SHAIANFLAG_CLOAK_SHOWN) & ~SHAIANFLAG_CLOAK_HIDDEN;
      }
    } else if (q->itemTimer > 30 && !Shaian_TestFlags(q, SHAIANFLAG_CLOAK_HIDDEN) && Shaian_TestFlags(q, SHAIANFLAG_CLOAK_SHOWN)) {
      q->blinkTimer = 30;
      *flags = (*flags | SHAIANFLAG_CLOAK_HIDDEN) & ~SHAIANFLAG_CLOAK_SHOWN;
    }
  } else {
    MainSprite* s = &(p->e).s->main.spr;
    s32 plttID;

    s->flags &= ~SPRFLAG_HIDDEN;
    CLEAR_FLAGS(*flags, SHAIANFLAG_CLOAK);
    plttID = (p->e).plttBase + (p->e).variant;
    if ((p->e).spriteKind == 0) {
      Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, plttID);
    } else {
      s->pltt = &gObjPlttData[plttID * 16];
    }
    (p->e).s->main.spr.plttID = 626;
  }
#else
  INCFUNC("asm/func/Shaian_UpdateItemEffects.inc");
#endif
}

// 姿を消すアイテムが効いているか, EnemyManager がこの間だけパレットのフェードを進める
bool8 Shaian_IsCloaked(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Shaian_TestFlags(q, SHAIANFLAG_CLOAK)) {
    return TRUE;
  }
  return FALSE;
}

// 直近に向かった経路ノードの記録を消す
void Shaian_ClearRecentNodes(Shaian* p) {
  Shaian* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    q->recentNodes[i] = -1;
  }
  q->recentNodeIdx = 0;
}

// 向かった経路ノードを直近の記録に足す, 3つで一周する
void Shaian_PushRecentNode(Shaian* p, s32 node) {
  Shaian* q = (p->e).owner;

  q->recentNodes[q->recentNodeIdx] = node;
  q->recentNodeIdx++;
  if (q->recentNodeIdx > 2) {
    q->recentNodeIdx = 0;
  }
}

// 直近に向かった経路ノードか
bool8 Shaian_IsRecentNode(Shaian* p, s32 node) {
  Shaian* q = (p->e).owner;
  s32 i;

  for (i = 0; i < 3; i++) {
    if (q->recentNodes[i] == node) {
      return TRUE;
    }
  }
  return FALSE;
}

// 158/166命令, Ax_PickFarPathNode / Skeleton_PickFarPathNode と同じ壁 (原典は差の Vec3 と bestIdx を sp に退避する), 1回目の下書きで切り上げ
// from から minDist 以上離れ, プレイヤーのいる向きから 64 より外れた最近使っていない一番遠い経路ノードを選び, 無ければ乱数で選んで to にその位置を入れる
NON_MATCH void Shaian_PickFarPathNode(Shaian* p, Vec3* to, Vec3* from, s32 minDist) {
#ifdef NONMATCHING_C
  PathWalker w;
  s32 best = 0;
  s32 bestIdx = -1;
  s32 i;
  PathNode* nodes;

  Map_InitPathWalker(&w, (p->e).unk_250, 0, 0);
  for (i = 0; i < w.path->nodeCount; i++) {
    PathNode* node = &Map_GetPathNodes(w.path)[i];
    Vec3 d = *from;
    s32 dist;

    d.x = node->x - d.x;
    d.z = node->y - d.z;
    dist = d.x * d.x + d.z * d.z;
    if (dist >= minDist) {
      s32 a = ArcTan2_8(d.x, d.z) - (p->e).playerAngle;

      if (a > 128) {
        a -= 256;
      } else if (a < -128) {
        a += 256;
      }
      if (abs(a) > 63 && dist > best && !Shaian_IsRecentNode(p, i)) {
        best = dist;
        bestIdx = i;
      }
    }
  }
  if (best == 0) {
    bestIdx = Mod(Random(), w.path->nodeCount);
  }
  Shaian_PushRecentNode(p, bestIdx);
  w.nodeIdx = bestIdx;
  w.waitTimer = 0;
  nodes = Map_GetPathNodes(w.path);
  to->x = nodes[w.nodeIdx].x;
  to->y = (p->e).floorY;
  to->z = nodes[w.nodeIdx].y;
#else
  INCFUNC("asm/func/Shaian_PickFarPathNode.inc");
#endif
}

// プレイヤーが向いている方の隣のタイルにいるか
bool8 Shaian_IsPlayerInFront(Shaian* p) {
  u16 playerTile = gPlayerPtr[0]->mover.tile->tileIdx[1];
  s32 front;

  switch ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) {
    case 0: {
      front = (p->e).tileIdx + 1;
      break;
    }
    case 1: {
      front = (p->e).tileIdx + gCollisionMap->tiledata->width;
      break;
    }
    case 2: {
      front = (p->e).tileIdx - 1;
      break;
    }
    case 3: {
      front = (p->e).tileIdx - gCollisionMap->tiledata->width;
      break;
    }
    default: {
      front = (p->e).tileIdx;
      break;
    }
  }
  if (playerTile == front) {
    return TRUE;
  }
  return FALSE;
}

// pos が向いている方の隣のタイルか
bool8 Shaian_IsPosInFront(Shaian* p, Vec3* pos) {
  s32 tile = GetCollisionTileIdx(pos);
  s32 front;

  switch ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) {
    case 0: {
      front = (p->e).tileIdx + 1;
      break;
    }
    case 1: {
      front = (p->e).tileIdx + gCollisionMap->tiledata->width;
      break;
    }
    case 2: {
      front = (p->e).tileIdx - 1;
      break;
    }
    case 3: {
      front = (p->e).tileIdx - gCollisionMap->tiledata->width;
      break;
    }
    default: {
      front = (p->e).tileIdx;
      break;
    }
  }
  if (tile == front) {
    return TRUE;
  }
  return FALSE;
}

// pos への経路を引き, 進む先のタイルを選び直す
void Shaian_RouteTo(Shaian* p, WorldPos* pos) {
  Vec3 d;

  Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, pos);
  Shaian_StepTowardDest(p);
  Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
  ArcTan2_8(d.x, d.z);
}

// 続けて被弾を数える時間を減らし, 切れたら数え直す
void Shaian_TickHitStreak(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (q->hitStreakTimer != 0) {
    q->hitStreakTimer--;
  } else {
    q->hitStreakTimer = 0;
    q->hitStreak = 0;
  }
}

// 体のやられ判定と接触の攻撃判定, 振り下ろしと回転斬りの攻撃判定を用意する
void Shaian_InitHitboxes(Shaian* p) {
  Shaian* q = (p->e).owner;
  Vec3 size, offset;

  VEC3_SET(size, 128, 128, 128);
  VEC3_SET(offset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &size, &offset, Shaian_OnHurt, p);
  VEC3_SET(size, 64, 100, 64);
  VEC3_SET(offset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &size, &offset, Shaian_OnHit, 0, p);
  VEC3_SET(size, 128, 128, 128);
  VEC3_SET(offset, 0, 128, 0);
  Hitbox_Init(&q->chopHitbox, 0, HBF_HITBOX | HBF_ANGLE | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(&q->chopHitbox, (p->e).atkPower[3], (p->e).atkKnockback[3], 0, (p->e).atkAttrs[3], (p->e).atkIframes[3]);
  Hitbox_SetPos(&q->chopHitbox, &(p->e).mover.pos, 0);
  Hitbox_SetHandler(&q->chopHitbox, Shaian_OnChopHit, p);
  VEC3_SET(size, 300, 128, 300);
  VEC3_SET(offset, 0, 128, 0);
  Hitbox_Init(&q->spinHitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetAttack(&q->spinHitbox, (p->e).atkPower[2], (p->e).atkKnockback[2], 0, (p->e).atkAttrs[2], (p->e).atkIframes[2]);
  Hitbox_SetPos(&q->spinHitbox, &(p->e).mover.pos, 0);
  Hitbox_SetHandler(&q->spinHitbox, Shaian_OnHit, p);
}

// 状態ハンドラの前に, 技の待ち・アニメの組・パレットのフェード・アイテムの効き目・被弾の数えを進める
s32 Shaian_PreUpdate(Shaian* p) {
  Shaian_TickAttackCooldowns(p);
  Shaian_SelectAnimSet(p);
  Shaian_StepPaletteFade(p);
  Shaian_UpdateItemEffects(p);
  Shaian_TickHitStreak(p);
  return 1;
}

// 状態ハンドラの後に, unk_8b6 のタイマー・影の位置・効果音の待ちを進める
s32 Shaian_PostUpdate(Shaian* p) {
  FUN_0817da34(p);
  Shaian_UpdateShadowPos(p);
  Shaian_TickSoundCooldown(p);
  return 1;
}

// 当たった相手を振り下ろしの刃の後ろ側から押し出す向きにし, 攻撃対象として覚える
void Shaian_OnChopHit(Hitbox* a, Hitbox* b, Shaian* p) {
  Vec3 pos;
  Vec3 d;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  pos = a->center;
  switch ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) {
    case 0: {
      pos.x -= 256;
      break;
    }
    case 1: {
      pos.z -= 256;
      break;
    }
    case 2: {
      pos.x += 256;
      break;
    }
    case 3: {
      pos.z += 256;
      break;
    }
  }
  Vec3_Delta(&d, &pos, &b->center);
  a->angle = ArcTan2_8(d.x, d.z);
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 当たった相手を攻撃対象として覚える
void Shaian_OnHit(Hitbox* a, Hitbox* b, Shaian* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 1156/1183命令, Ax_OnHurt / Ghost_OnHurt と同じ Enemy_HandleHurt の共通 inline の壁, 1回目の下書きで切り上げ
// 被弾を受け, 同じ種類の攻撃を続けて受けると見切って受け止め火花を散らす, 28 回続くと距離に合わせて回転斬り/振り下ろし/トマホークで返す
NON_MATCH void Shaian_OnHurt(Hitbox* a, Hitbox* b, Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  u32 dir;
  u32 front;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
  if ((p->e).unk_48a == 0) {
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return;
  }
  if (!Shaian_TestFlags(q, SHAIANFLAG_UNK_0)) {
    return;
  }
  if (Shaian_TestFlags(q, SHAIANFLAG_ITEM_ACTION)) {
    return;
  }
  if (!((p->e).weaponExpMask & 0x1F) || (s16)(p->e).stunTimer > 0) {
    q->sameWeaponHits = 0;
  } else {
    if ((p->e).weaponExpMask == q->lastHitWeapon) {
      q->sameWeaponHits++;
    } else {
      q->sameWeaponHits = 0;
    }
    q->lastHitWeapon = (p->e).weaponExpMask;
  }
  if (q->sameWeaponHits < 28) {
    if (q->sameWeaponHits < 2) {
      return;
    }
    if (q->sameWeaponHits == 2) {
      PlaySound_082406e0(VO_SHAIAN_MIKK);
    }
    b->damage = 0;
    (p->e).unk_48c = 0;
    b->iframes = 0;
    if (!Shaian_TestFlags(q, SHAIANFLAG_CLOAK)) {
      (p->e).s->main.spr.flags &= ~SPRFLAG_HIDDEN;
    }
    Shaian_SpawnGuardSpark(p);
    Enemy_ResetState(&p->e, 0, 0, 18);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    return;
  }
  q->sameWeaponHits = 0;
  b->damage = 0;
  (p->e).unk_48c = 0;
  b->iframes = 0;
  if (!Shaian_TestFlags(q, SHAIANFLAG_CLOAK)) {
    (p->e).s->main.spr.flags &= ~SPRFLAG_HIDDEN;
  }
  if ((p->e).playerDistSq < 0x19000) {
    Enemy_ResetState(&p->e, 0, 2, 2);
    return;
  }
  if ((p->e).playerDistSq < 0x40000 && Shaian_IsPlayerInFront(p)) {
    Enemy_ResetState(&p->e, 0, 2, 0);
    return;
  }
  if ((p->e).playerDistSq > 0xFFFFF) {
    return;
  }
  dir = (((p->e).mover.angle + 0x20) & 0xFF) >> 6;
  switch (dir) {
    case 0: {
      front = (p->e).tileIdx + 1;
      break;
    }
    case 1: {
      front = (p->e).tileIdx + gCollisionMap->tiledata->width;
      break;
    }
    case 2: {
      front = (p->e).tileIdx - 1;
      break;
    }
    case 3: {
      front = (p->e).tileIdx - gCollisionMap->tiledata->width;
      break;
    }
    default: {
      front = (p->e).tileIdx;
      break;
    }
  }
  if ((p->e).mover.pos.y < (s32)((TileAtIndex(front)->heightStairs & 0xF) << 8)) {
    s32 best = 0x7FFFFFFF;
    u32 d = dir;
    s32 i;

    for (i = 2; i >= 0; i--) {
      s32 diff;

      d++;
      diff = (p->e).playerAngle - (d & 3) * 64;
      if (diff > 128) {
        diff -= 256;
      } else if (diff < -128) {
        diff += 256;
      }
      diff = abs(diff);
      if (diff < best) {
        dir = d & 3;
        best = diff;
      }
    }
    (p->e).mover.angle = dir << 6;
  }
  Enemy_ResetState(&p->e, 0, 2, 1);
#else
  INCFUNC("asm/func/Shaian_OnHurt.inc");
#endif
}

void Shaian_StateMove(Shaian* p) {
  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
}

// 振り下ろしのアニメを流し, 振り下ろしている間だけ向いている方の 1 マス先に攻撃判定を置く
void Shaian_StateChop(Shaian* p) {
  Shaian* q = (p->e).owner;
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
  }
  if (s->animCmdIdx == 2 && s->animCmdTimer == 0) {
    PlaySound_082406e0(SONG_976);
    PlaySound_082406e0(VO_SHAIAN_ATK1);
  }
  if (s->animCmdIdx >= 3 && s->animCmdIdx <= 6) {
    Vec3 pos = (p->e).mover.pos;

    switch ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) {
      case 0: {
        pos.x += 256;
        break;
      }
      case 1: {
        pos.z += 256;
        break;
      }
      case 2: {
        pos.x -= 256;
        break;
      }
      case 3: {
        pos.z -= 256;
        break;
      }
    }
    Hitbox_SetPos(&q->chopHitbox, &pos, 0);
    Hitbox_Register(&q->chopHitbox);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// 技の後に動きを止めるアニメ (22) を流す
void Shaian_StateRecover(Shaian* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ((Shaian*)(p->e).owner)->sameWeaponHits = 0;
  }
  Enemy_PlayAnim(&p->e, 22);
}

// 回転斬りの後に目を回して動きを止める
void Shaian_StateStunned(Shaian* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    ((Shaian*)(p->e).owner)->sameWeaponHits = 0;
    PlaySound_082406e0(SE_ENEMY_STUN);
    Enemy_SetEmote(&p->e, 3, 2, (p->e).kind);
  }
  Enemy_PlayAnim(&p->e, 23);
}

// 向いている方の待機アニメを流す
void Shaian_StateWait(Shaian* p) {
  u32 variant, flags;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Shaian_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Shaian_PlayDirAnim(p, (p->e).animTable[0].anim, variant, flags | (p->e).animTable[0].unk_1);
}

// プレイヤーの方を向いてアニメ 14 を流し, 効果音を鳴らして unk_8b6 を 30 にする
void FUN_0817fd8c(Shaian* p) {
  Shaian* q;
  u32 variant, flags;

  if (!Enemy_ConsumeStateBegun(&p->e)) {
    return;
  }
  q = (p->e).owner;
  (p->e).mover.angle = (p->e).playerAngle;
  Shaian_GetAnimVariant((p->e).mover.angle, &variant, &flags);
  Shaian_PlayDirAnim(p, (p->e).animTable[14].anim, variant, flags | (p->e).animTable[14].unk_1);
  if (q->soundCooldown == 0) {
    PlaySound_082406e0(SONG_974);
    q->soundCooldown = 10;
  }
  q->unk_8b6 = 30;
}

// 4 方向に向き直って投げるアニメを流し, 4 コマ目で 2 本のトマホークを投げる, プレイヤーが正面のタイルなら真っすぐ, 向きが近ければ少し広げて, 遠ければ大きく回り込ませる
void Shaian_StateTomahawk(Shaian* p) {
  Shaian* q = (p->e).owner;
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) << 6;
    Enemy_PlayAnim(&p->e, 15);
    PlaySound_082406e0(SONG_977);
  }
  if (s->animCmdIdx == 4 && s->animCmdTimer == 0) {
    Vec3 pos = (p->e).mover.pos;
    s32 turn;

    pos.y += 220;
    switch ((((p->e).mover.angle + 0x20) & 0xFF) >> 6) {
      case 0: {
        pos.x += 128;
        pos.z -= 48;
        break;
      }
      case 1: {
        pos.x -= 64;
        pos.z += 128;
        break;
      }
      case 2: {
        pos.x -= 256;
        break;
      }
      case 3: {
        pos.z -= 256;
        break;
      }
    }
    turn = (p->e).hp <= (p->e).unk_546 ? 6 : 2;
    if (Shaian_IsPlayerInFront(p)) {
      Tomahawk_Spawn(&pos, (p->e).mover.angle - 4, 120, turn, 8, 18, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1], (p->e).atkIframes[1]);
      Tomahawk_Spawn(&pos, (p->e).mover.angle + 4, 120, turn, 8, 18, 128, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1], (p->e).atkIframes[1]);
    } else {
      s32 d = (p->e).playerAngle - (p->e).mover.angle;

      if (d > 128) {
        d -= 256;
      } else if (d < -128) {
        d += 256;
      }
      if (abs(d) < 24) {
        Tomahawk_Spawn(&pos, (p->e).mover.angle - 12, 120, turn + 2, 12, 22, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1], (p->e).atkIframes[1]);
        Tomahawk_Spawn(&pos, (p->e).mover.angle + 12, 120, turn + 2, 12, 22, 128, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1], (p->e).atkIframes[1]);
      } else {
        Tomahawk_Spawn(&pos, (p->e).mover.angle - 32, 20, turn + 4, 20, 20, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1], (p->e).atkIframes[1]);
        Tomahawk_Spawn(&pos, (p->e).mover.angle + 32, 20, turn + 4, 20, 20, 128, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1], (p->e).atkIframes[1]);
      }
    }
    CLEAR_FLAGS(q->flags, SHAIANFLAG_UNK_0);
    PlaySound_082406e0(SONG_978);
    PlaySound_082406e0(VO_SHAIAN_ATK2);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// 回転斬りのアニメを流して回る効果を出し, 終わるまで回転斬りの攻撃判定を置く
void Shaian_StateSpin(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Vec3 pos = (p->e).mover.pos;

    pos.y += 280;
    Entity081f7de4_Spawn(&pos, 0);
    Entity081f7de4_Spawn(&pos, 128);
    Enemy_PlayAnimNoFacing(&p->e, 16);
    SET_FLAGS(q->flags, SHAIANFLAG_SPINNING);
    PlaySound_082406e0(SONG_975);
    PlaySound_082406e0(VO_SHAIAN_ATK3);
  }
  Hitbox_SetPos(&q->spinHitbox, &(p->e).mover.pos, 0);
  Hitbox_Register(&q->spinHitbox);
  if ((p->e).animForceRestart) {
    Entity081f7de4_RemoveAll();
    CLEAR_FLAGS(q->flags, SHAIANFLAG_SPINNING);
    (p->e).subStateDone = 1;
  }
}

// itemSearchTime の間アイテムを探り, 終わったら取り出す状態へ移る
void Shaian_StateSearchItem(Shaian* p, s32 timer) {
  Shaian* q = (p->e).owner;

  if ((p->e).stateBegun) {
    (p->e).stateBegun = FALSE;
  }
  Enemy_PlayAnimNoFacing(&p->e, 19);
  if (timer > q->itemSearchTime) {
    Shaian_ClearOwnerFlags(p, SHAIANFLAG_SEARCHING);
    Enemy_EnterState(&p->e, Shaian_StateTakeOutItem, ES_UNK_42);
  }
}

// アイテムを取り出してアイコンを出し「これだ!」と言って使う状態へ移る
void Shaian_StateTakeOutItem(Shaian* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 20);
    Shaian_ShowItemIcon(p);
    PlaySound_082406e0(VO_SHAIAN_KOREDA);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Shaian_StateUseItem, ES_UNK_43);
  }
}

// 30 フレーム後にアイテムの効き目を出し, パレットを元の色へフェードで戻し始める
void Shaian_StateUseItem(Shaian* p, s32 timer) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 21);
  }
  if (timer > 30) {
    PlaySound_082406e0(SONG_327);
    q->fade.timer = 256;
    Shaian_StartPaletteFade(p, 0x272, 0x273, 32);
    Shaian_ApplyItem(p);
    (p->e).subStateDone = 1;
  }
}

// アニメ 18 を流し, 2 コマ目で効果音を鳴らす
void FUN_08180494(Shaian* p) {
  MainSprite* s = &(p->e).s->main.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 18);
  }
  if (s->animCmdIdx == 1 && s->animCmdTimer == 0) {
    PlaySound_082406e0(SONG_979);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

void Shaian_StateTurn(Shaian* p) {}

// プレイヤーに気付いたときのアニメを流す
void Shaian_AnimNotice(Shaian* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 11);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// ひるんで弾かれた方へ滑り, 止まったら副状態 0 へ戻る
void Shaian_StateDamaged(Shaian* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).mover.angle = (p->e).angle;
    Enemy_PlayAnim(&p->e, 3);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    PlaySound_082406e0(VO_SHAIAN_DAMAGE);
  }
  Enemy_SetFlag(&p->e, ENEFLAG_UNK_13);
  if (Enemy_StepSlide(&p->e)) {
    (p->e).subStateDone = 1;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_ClearFlag(&p->e, ENEFLAG_UNK_7);
    Enemy_ResetState(&p->e, 0, 0, 0);
  }
}

// プレイヤーとの距離が範囲内の間その場で待ち, 経路が引けたら追いかける副状態 15 へ移る
void Shaian_StateWaitForRoute(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
  } else if ((p->e).playerDistSq > q->farDistSq || (p->e).playerDistSq < q->nearDistSq) {
    CLEAR_FLAGS(q->flags, SHAIANFLAG_CHASING);
    Shaian_ReactToDistance(p);
  } else {
    Enemy_PlayAnim(&p->e, 0);
    if (!Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &(p->e).playerMover->pos)) {
      (p->e).onRouteFailed(&p->e);
    } else {
      CLEAR_FLAGS(q->flags, SHAIANFLAG_CHASING);
      Enemy_ResetState(&p->e, 0, 0, 15);
    }
  }
}

// 追っている間, 離れすぎたら副状態 17 へ, そうでなければ追うのをやめて距離で次を決め直す
void Shaian_StateChase(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (!Enemy_ConsumeStateBegun(&p->e)) {
    if (Shaian_TestFlags(q, SHAIANFLAG_CHASING)) {
      if ((p->e).playerDistSq > q->farDistSq) {
        Enemy_ResetState(&p->e, 0, 0, 17);
        (p->e).unk_1dc = (FixToInt(5, (p->e).playerAngle) + 3) & 7;
      } else {
        Shaian_ClearFlags(q, SHAIANFLAG_CHASING);
        Shaian_ReactToDistance(p);
      }
    } else {
      Enemy_PlayAnim(&p->e, 1);
    }
  }
}

// 倒れるアニメを流してトマホークや回る効果を消し, 撃破のスクリプトを流して図鑑に記録する
void Shaian_StateDying(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    (p->e).animForceRestart = FALSE;
    if (Shaian_TestFlags(q, SHAIANFLAG_CLOAK)) {
      q->itemTimer = 30;
    }
    Enemy_SetEmote(&p->e, 0, 127, 0);
    Enemy_SetEmote(&p->e, 1, 127, 0);
    Enemy_SetEmote(&p->e, 3, 127, 0);
    Enemy_FadeParticles(&p->e, 4);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    Hitbox_Hide(&(p->e).hurtbox);
    Entity081f7de4_RemoveAll();
    TomahawkManager_VanishAll();
    if ((p->e).defeatScriptID != 0) {
      u32 argv[8];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      argv[6] = (p->e).unk_4a0;
      argv[7] = (p->e).mover.id;
      sa.argc = 8;
      sa.argv = argv;
      VM_ExecByID((p->e).defeatScriptID, &sa);
    }
    {
      s32 idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);

      if (idx < 32) {
        gStat->enemyDexSeen[0] |= 1 << idx;
      } else {
        gStat->enemyDexSeen[1] |= 1 << (idx - 32);
      }
    }
  }
  Enemy_ClearDamage(&p->e);
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
    (p->e).stunTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
  }
}

// 742/754命令, enedefault.c の FUN_080f12c4 と同じ後半で同じ壁 (原典は状態や下位状態のフィールドのアドレスをスタックに作り置く), 1回目の下書きで切り上げ
// プレイヤーに気付いてアニメ 11 を流し, 終わったらプレイヤーのタイルへ経路を引いて追いかけ始める, 同じタイルなら追跡か経路歩きへ移って向きを乱数で変える見回しを予約する
NON_MATCH void Shaian_SubNotice(Shaian* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Shaian_AnimNotice, ES_UNK_10);
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_SetEmote(&p->e, 0, 0, (p->e).kind);
    Enemy_RunScript(&p->e);
    Enemy_BeginChase(&p->e);
    return;
  }
  if (!(p->e).subStateDone) {
    (p->e).subStateTimer++;
    return;
  }
  Enemy_ResetState(&p->e, 0, 0, 12);
  Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  if (IsLinkPlay()) {
    Mover* m = (p->e).playerMover;

    idx = -1;
    if (m != NULL && m->kind <= 3) {
      idx = m->kind;
    }
    if (m == NULL || idx < 0) {
      (p->e).onRouteFailed(&p->e);
      return;
    }
    tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
  } else {
    tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
    idx = 0;
  }
  if (tile != (p->e).tileIdx && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
    WorldPos tilePos;

    TilePosAtIndex(&tilePos, tile);
    if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos)) {
      (p->e).onRouteFailed(&p->e);
    }
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
    return;
  }
  (p->e).unk_222 &= ~ENEMY222_UNK_2;
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
    Enemy_ResetState(&p->e, 0, 0, 12);
  } else {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Enemy_ResetState(&p->e, 0, 0, 5);
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
    (p->e).pathNodePos->val = 0;
  }
  {
    u8 angle = (p->e).mover.angle;

    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
      s32 i;
      u32 a;

      for (i = 0; i <= 3; i++) {
        a = (Random() & 3) << 6;
        if (a != angle) {
          break;
        }
      }
      if (i > 3) {
        a = angle;
      }
      (p->e).lookAngle = a;
      (p->e).savedHandlerState = (p->e).handlerState;
      (p->e).savedState = (p->e).state;
      (p->e).savedSubState0 = (p->e).subState0;
      (p->e).savedSubState1 = (p->e).subState1;
      (p->e).savedSubState2 = (p->e).subState2;
      (p->e).lookBaseAngle = angle;
      Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
      Enemy_ResetState(&p->e, 3, 1, 0);
      (p->e).unk_542 = 6;
    }
  }
  Enemy_StepToFloorEdge(&p->e);
  (p->e).animSpeedDiv = 2;
#else
  INCFUNC("asm/func/Shaian_SubNotice.inc");
#endif
}

// 945/963命令, Shaian_SubNotice / enedefault.c の FUN_080f12c4 と同じ壁 (原典は状態や下位状態のフィールドのアドレスをスタックに作り置く), 1回目の下書きで切り上げ
// 見失った後 60 フレーム待ち, 追っていたならプレイヤーのタイルへ経路を引いて追い続け, そうでなければエモート 2 を出して経路のノードへ戻る状態を予約する
NON_MATCH void Shaian_SubLostPlayer(Shaian* p) {
#ifdef NONMATCHING_C
  s32 tile;
  s32 idx;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.angle = (p->e).playerAngle;
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  if (FUN_080f0a0c(&p->e)) {
    return;
  }
  if ((p->e).subStateTimer <= 60) {
    (p->e).subStateTimer++;
    return;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
    Enemy_ResetState(&p->e, 0, 0, 12);
    Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
    {
      Vec3* dst = (p->e).pathNodePos;
      PathWalker* walker = &(p->e).pathWalker;

      dst->x = walker->node->x;
      dst->z = walker->node->y;
      dst->y = TileHeightAt(dst);
    }
    if (IsLinkPlay()) {
      Mover* m = (p->e).playerMover;

      idx = -1;
      if (m != NULL && m->kind <= 3) {
        idx = m->kind;
      }
      if (m == NULL || idx < 0) {
        (p->e).onRouteFailed(&p->e);
        return;
      }
      tile = gPlayerPtr[idx]->mover.tile->tileIdx[1];
    } else {
      tile = GetCollisionTileIdx(&(p->e).playerMover->pos);
      idx = 0;
    }
    if (tile != (p->e).tileIdx && !(gPlayerPtr[idx]->flag20 & PFLAG20_INVISIBLE)) {
      WorldPos tilePos;

      TilePosAtIndex(&tilePos, tile);
      if (!Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &tilePos)) {
        (p->e).onRouteFailed(&p->e);
      }
      return;
    }
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10)) {
      return;
    }
    (p->e).unk_222 &= ~ENEMY222_UNK_2;
    if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7)) {
      Enemy_EnterState(&p->e, (p->e).handlerChase, ES_UNK_26);
      Enemy_ResetState(&p->e, 0, 0, 12);
    } else {
      Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
      Enemy_ResetState(&p->e, 0, 0, 5);
      {
        Vec3* dst = (p->e).pathNodePos;
        PathWalker* walker = &(p->e).pathWalker;

        dst->x = walker->node->x;
        dst->z = walker->node->y;
        dst->y = TileHeightAt(dst);
      }
      (p->e).pathNodePos->y = TileHeightAt((p->e).pathNodePos);
      (p->e).pathNodePos->val = 0;
    }
    {
      u8 angle = (p->e).mover.angle;

      if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_10) && !TEST_FLAGS((p->e).unk_222, ENEMY222_UNK_2)) {
        s32 i;
        u32 a;

        for (i = 0; i <= 3; i++) {
          a = (Random() & 3) << 6;
          if (a != angle) {
            break;
          }
        }
        if (i > 3) {
          a = angle;
        }
        (p->e).lookAngle = a;
        (p->e).savedHandlerState = (p->e).handlerState;
        (p->e).savedState = (p->e).state;
        (p->e).savedSubState0 = (p->e).subState0;
        (p->e).savedSubState1 = (p->e).subState1;
        (p->e).savedSubState2 = (p->e).subState2;
        (p->e).lookBaseAngle = angle;
        Enemy_EnterState(&p->e, (p->e).handlerLookAround, ES_UNK_27);
        Enemy_ResetState(&p->e, 3, 1, 0);
        (p->e).unk_542 = 6;
      }
    }
    Enemy_StepToFloorEdge(&p->e);
    (p->e).animSpeedDiv = 2;
    return;
  }
  Enemy_ResetState(&p->e, 3, 1, 0);
  Enemy_EnterState(&p->e, Enemy_WaitPendingState, ES_UNK_14);
  Enemy_SetEmote(&p->e, 0, 2, (p->e).kind);
  (p->e).pendingDelay = 30;
  (p->e).pendingHandler = (p->e).handlerMove;
  (p->e).pendingSubState0 = 0;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 7;
  {
    Vec3* dst = (p->e).pathNodePos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
  }
  if (Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, (p->e).pathNodePos)) {
    (p->e).pathNodePos->val = 1;
  } else {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_UNK_0);
    Enemy_ResetState(&p->e, 3, 0, 0);
  }
#else
  INCFUNC("asm/func/Shaian_SubLostPlayer.inc");
#endif
}

void Shaian_SetHandlerTable3(Shaian* p) { (p->e).handlerTables[3] = (void*)sShaianHandlerTable3; }

// 振り下ろしを出し, 終わったら recoverStun だけ止まる
void Shaian_SubChop(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Shaian_StateChop, ES_UNK_34);
    q->attackCooldowns[0] = q->attackIntervals[0];
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Shaian_StateRecover, ES_UNK_45);
    Enemy_ResetState(&p->e, 0, 2, 3);
    q->recoverStun = 80;
    if ((p->e).hp <= (p->e).unk_546) {
      (p->e).stunTimer = q->recoverStun >> 1;
    } else {
      (p->e).stunTimer = q->recoverStun;
    }
    (p->e).stunTime = (p->e).stunTimer;
    q->recoverTime = (p->e).stunTimer;
  } else {
    (p->e).subStateTimer++;
  }
}

// トマホークを投げ, 終わったら待機に戻って recoverStun だけ止まる
void Shaian_SubTomahawk(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Shaian_StateTomahawk, ES_UNK_36);
    q->attackCooldowns[1] = q->attackIntervals[1];
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Shaian_StateWait, ES_UNK_0);
    Enemy_ResetState(&p->e, 0, 2, 3);
    q->sameWeaponHits = 0;
    q->recoverStun = 30;
    if ((p->e).hp <= (p->e).unk_546) {
      (p->e).stunTimer = q->recoverStun >> 1;
    } else {
      (p->e).stunTimer = q->recoverStun;
    }
    (p->e).stunTime = (p->e).stunTimer;
    q->recoverTime = (p->e).stunTimer;
  } else {
    (p->e).subStateTimer++;
  }
}

// 回転斬りを出し, 終わったら半々で目を回すか待つかして recoverStun だけ止まる
void Shaian_SubSpin(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    Enemy_EnterState(&p->e, Shaian_StateSpin, ES_UNK_35);
    q->attackCooldowns[2] = q->attackIntervals[2];
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
    if ((Random() & 0xFF) < 128) {
      Enemy_EnterState(&p->e, Shaian_StateStunned, ES_UNK_46);
      q->recoverStun = 160;
    } else {
      Enemy_EnterState(&p->e, Shaian_StateWait, ES_UNK_0);
      q->sameWeaponHits = 0;
      q->recoverStun = 30;
    }
    if ((p->e).hp <= (p->e).unk_546) {
      (p->e).stunTimer = q->recoverStun >> 1;
    } else {
      (p->e).stunTimer = q->recoverStun;
    }
    (p->e).stunTime = (p->e).stunTimer;
    q->recoverTime = (p->e).stunTimer + 40;
    Enemy_ResetState(&p->e, 0, 2, 3);
  } else {
    (p->e).subStateTimer++;
  }
}

// 技の後 recoverTime だけ待ち, タイルの中心から外れていれば向かう先へ経路を引き直して中心へ戻る副状態 21 へ移る
void Shaian_SubRecover(Shaian* p) {
  Shaian* q = (p->e).owner;

  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = FALSE;
  }
  if (q->recoverTime < (p->e).subStateTimer) {
    WorldPos center;
    Vec3 d;
    s32 a;

    TilePosAtIndex(&center, (p->e).tileIdx);
    Vec3_Delta(&d, &(p->e).mover.pos, &center);
    if (d.x * d.x + d.z * d.z < 0x400) {
      Enemy_ResetState(&p->e, 0, 0, 0);
      return;
    }
    if (Shaian_TestFlags(q, SHAIANFLAG_UNK_0)) {
      Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    } else if (Shaian_TestFlags(q, SHAIANFLAG_RETREATING)) {
      Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &q->retreatDest);
    }
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->waypoint);
    a = ArcTan2_8(d.x, d.z) - (p->e).mover.angle;
    if (a > 128) {
      a -= 256;
    } else if (a < -128) {
      a += 256;
    }
    if (abs(a) < 32) {
      Enemy_ResetState(&p->e, 0, 0, 0);
    } else {
      Enemy_ResetState(&p->e, 0, 0, 21);
    }
  } else {
    (p->e).subStateTimer++;
  }
}

void Shaian_SetHandlerTable4(Shaian* p) { (p->e).handlerTables[4] = (void*)sShaianHandlerTable4; }

// アイテムを探っている途中なら落としてひるむ, そうでなければ 180 フレームの間に3発受けるとひるむ
bool8 Shaian_OnDamaged(Shaian* p) {
  Shaian* q = (p->e).owner;

  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  if (Shaian_TestFlags(q, SHAIANFLAG_SEARCHING)) {
    Shaian_DropItem(p);
    CLEAR_FLAGS(q->flags, SHAIANFLAG_SEARCHING | SHAIANFLAG_ITEM_ACTION);
    Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    return TRUE;
  }
  if (!Enemy_TestFlag3(&p->e, ENEFLAG3_UNK_8) && !Shaian_TestFlags(q, SHAIANFLAG_ITEM_ACTION) && (s16)(p->e).stunTimer <= 0 && ((p->e).unk_48c & 8)) {
    if (q->hitStreakTimer != 0) {
      q->hitStreak++;
    }
    if (q->hitStreakTimer == 0) {
      q->hitStreakTimer = 180;
    }
    if (q->hitStreak > 1) {
      Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
      Enemy_ResetState(&p->e, 3, 0, 0);
      q->hitStreakTimer = 0;
      q->hitStreak = 0;
      return TRUE;
    }
  }
  Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_5);
  return FALSE;
}

// 今いるタイルの中心へ歩き, 着いたら副状態 0 へ戻る, 途中でプレイヤーに気付いて技を出せればそちらへ移る
void Shaian_SubCenterOnTile(Shaian* p) {
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    TilePosAtIndex(&(p->e).navAgent->waypoint, (p->e).tileIdx);
    (p->e).navAgent->dest = (p->e).navAgent->waypoint;
  }
  if ((p->e).tryDetectPlayer(&p->e) && Shaian_TryStartAttack(p)) {
    return;
  }
  Enemy_PlayAnim(&p->e, 1);
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Shaian_MoveAlongNav(p, (p->e).navAgent, 32, 32, speed) == 2) {
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
      Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
      (p->e).unk_21c = 0;
      (p->e).unk_21e = 0;
      (p->e).unk_202 = 0;
    }
    Enemy_ResetState(&p->e, 0, 0, 0);
  } else {
    (p->e).subStateTimer++;
  }
}

// 368/368命令, 残差は状態に入るところの番地の一時レジスタ (r3/r4) など割り当てだけ
// 試済: 分岐の向き, attackCooldowns を指すポインタの有無
// 経路に沿って歩き, 近くにいれば向きで振り下ろしか回転斬りの待ちを消して技を試す, 着いたら逃げ先かプレイヤーへ次の経路を引く
NON_MATCH void Shaian_SubWalk(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Shaian_StepTowardDest(p);
  }
  if ((p->e).tryDetectPlayer(&p->e) && Shaian_TryStartAttack(p)) {
    return;
  }
  Enemy_PlayAnim(&p->e, 1);
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if ((p->e).playerDistSq < 0xFFFF) {
    s32 d = (p->e).playerAngle - (p->e).mover.angle;

    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    if (abs(d) < 32) {
      q->attackCooldowns[0] = 0;
    } else {
      q->attackCooldowns[2] = 0;
    }
    if (Shaian_TryStartAttack(p)) {
      return;
    }
  }
  if (Shaian_MoveAlongNav(p, (p->e).navAgent, 32, 32, speed) == 2) {
    if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_21)) {
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
      Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_9);
      (p->e).unk_21c = 0;
      (p->e).unk_21e = 0;
      (p->e).unk_202 = 0;
    }
    if (Shaian_TestFlags(q, SHAIANFLAG_RETREATING)) {
      if ((p->e).playerDistSq > 0x40000 || GetCollisionTileIdx(&(p->e).mover.pos) == GetCollisionTileIdx(&q->retreatDest)) {
        Enemy_ResetState(&p->e, 0, 0, 20);
        Shaian_ClearFlags(q, SHAIANFLAG_RETREATING);
        return;
      }
      Shaian_RouteTo(p, &q->retreatDest);
    } else if ((p->e).tileIdx == gPlayerPtr[0]->mover.tile->tileIdx[1]) {
      q->attackCooldowns[2] = 0;
    } else if (gPlayerPtr[0]->flag20 & 0x20000) {
      Shaian_PickFarPathNode(p, &q->retreatDest, &gPlayerPtr[0]->mover.pos, 0x400000);
      Shaian_RouteTo(p, &q->retreatDest);
    } else {
      Shaian_RouteTo(p, &gPlayerPtr[0]->mover.pos);
    }
  }
  (p->e).subStateTimer++;
#else
  INCFUNC("asm/func/Shaian_SubWalk.inc");
#endif
}

// 337/340命令, 残差は待ちを半分にするとき原典は値を別のレジスタに写してから縮める所と, 経路を引く 3 本の inline の失敗の出口のまとめ方
// 試済: 待ちの三項演算子/if, 比較の中の三項演算子, フラグ操作を Shaian_SetFlags/ClearFlags (これで &flags の持ち越しは一致)
// 立ち止まって少し待ち, 向かっていくならアイテムを使うかプレイヤーへ, そうでなければプレイヤーから遠い経路ノードへ逃げる (遠く離れたら副状態 20)
NON_MATCH void Shaian_SubDecide(Shaian* p) {
#ifdef NONMATCHING_C
  Shaian* q = (p->e).owner;
  s32 wait;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    if ((Random() & 0xFF) < 64) {
      Shaian_SetFlags(q, SHAIANFLAG_LONG_WAIT);
    } else {
      Shaian_ClearFlags(q, SHAIANFLAG_LONG_WAIT);
    }
  }
  if ((p->e).tryDetectPlayer(&p->e) && Shaian_TryStartAttack(p)) {
    return;
  }
  wait = Shaian_TestFlags(q, SHAIANFLAG_LONG_WAIT) ? 8 : 4;
  if (Shaian_TestFlags(q, SHAIANFLAG_HASTE)) {
    wait >>= 1;
  }
  if ((p->e).subStateTimer > wait) {
    if (Shaian_TestFlags(q, SHAIANFLAG_UNK_0)) {
      if (Shaian_TryUseItem(p)) {
        return;
      }
      Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    } else if (Shaian_TestFlags(q, SHAIANFLAG_RETREATING)) {
      Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &q->retreatDest);
    } else if ((p->e).playerDistSq > 0x40000) {
      Enemy_ResetState(&p->e, 0, 0, 20);
      Shaian_ClearFlags(q, SHAIANFLAG_RETREATING);
      return;
    } else {
      Shaian_PickFarPathNode(p, &q->retreatDest, &gPlayerPtr[0]->mover.pos, 0x90000);
      Enemy_TryRouteTo(&p->e, (p->e).navAgent, &(p->e).mover.pos, &q->retreatDest);
      Enemy_ResetState(&p->e, 0, 0, 2);
      Shaian_SetFlags(q, SHAIANFLAG_RETREATING);
      return;
    }
    Enemy_ResetState(&p->e, 0, 0, 2);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Shaian_SubDecide.inc");
#endif
}

// FUN_0817fd8c の状態で 30 フレーム待ち, 技を出せなければ副状態 0 へ戻る
void FUN_08182d1c(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_0817fd8c, ES_UNK_40);
    SET_FLAGS(q->flags, SHAIANFLAG_UNK_3);
  }
  if ((p->e).subStateTimer > 30) {
    if (!Shaian_TryStartAttack(p)) {
      Enemy_ResetState(&p->e, 0, 0, 0);
    }
    CLEAR_FLAGS(q->flags, SHAIANFLAG_UNK_3);
  } else {
    (p->e).subStateTimer++;
  }
}

// FUN_08180494 の状態で 30 フレーム待ち, 終わったら SHAIANFLAG_UNK_0 を立てて副状態 0 へ戻る
void FUN_08182de8(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_08180494, ES_UNK_44);
  }
  if ((p->e).subStateTimer > 30) {
    Enemy_ResetState(&p->e, 0, 0, 0);
    SET_FLAGS(q->flags, SHAIANFLAG_UNK_0);
  } else {
    (p->e).subStateTimer++;
  }
}

// アイテムを探り終えたらプレイヤーへの経路を引いて副状態 2 へ移る
void Shaian_SubSearchItem(Shaian* p) {
  Shaian* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Shaian_StateSearchItem, ES_UNK_41);
  }
  if ((p->e).subStateDone) {
    CLEAR_FLAGS(q->flags, SHAIANFLAG_ITEM_ACTION);
    Enemy_TryRouteToEx(&p->e, (p->e).navAgent, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    Enemy_ResetState(&p->e, 0, 0, 2);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  } else {
    (p->e).subStateTimer++;
  }
}

// 経路に沿ってプレイヤーを追い, 着いたら追跡中にして副状態 (3, 1, 0) へ移る
void Shaian_SubChase(Shaian* p) {
  Shaian* q = (p->e).owner;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Shaian_StateChase, ES_UNK_38);
    SET_FLAGS(q->flags, SHAIANFLAG_UNK_5);
  }
  if ((p->e).tryDetectPlayer(&p->e)) {
    return;
  }
  speed = (p->e).getMoveSpeed(&p->e);
  (p->e).animSpeedDiv = 2;
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (!Map_ConsumeNavWaypointChanged((p->e).navAgent)) {
    if (Enemy_MoveAlongNav(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      SET_FLAGS(q->flags, SHAIANFLAG_CHASING);
      return;
    }
  } else {
    if (Enemy_TurnTowardWaypoint(&p->e, (p->e).navAgent, 32, 32, speed)) {
      Enemy_ResetState(&p->e, 0, 0, 16);
    }
  }
  (p->e).subStateTimer++;
}

// その場で振り向き, 終わったら追いかける副状態 15 へ移る
void Shaian_SubTurn(Shaian* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (!(p->e).tryDetectPlayer(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 0, 0, 15);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

// その場で振り向き, 終わったら経路が引けるまで待つ状態へ移る
void Shaian_SubTurnThenWait(Shaian* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (!(p->e).tryDetectPlayer(&p->e)) {
    if ((p->e).subStateDone) {
      Enemy_ResetState(&p->e, 3, 1, 0);
      Enemy_EnterState(&p->e, Shaian_StateWaitForRoute, ES_UNK_39);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void Shaian_SetHandlerTable2(Shaian* p) { (p->e).handlerTables[2] = (void*)sShaianHandlerTable2; }

// 毎フレームの前処理, 副状態の表のハンドラ, 状態ハンドラ, 後処理の順に回す
s32 Shaian_UpdateFrame(Shaian* p) {
  Shaian_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Shaian_PostUpdate(p);
  return 1;
}

s32 Shaian_Update(Shaian* p) {
  (p->e).zoneID = gStat->zoneID;
  Enemy_Update(&p->e);
  return 0;
}

s32 Shaian_Destroy(Shaian* p) {
  if (!(p->e).shadowRemoved) {
    AuxShadow_Remove(&(p->e).auxShadow);
    (p->e).shadowRemoved = 0xFF;
  }
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove(&(p->e).s->aux.spr);
  } else {
    MainSprite_Remove(&(p->e).s->main.spr);
  }
  Free((p->e).s);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).shadowRemoved) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).shadowRemoved = 1;
  }
  if (!(p->e).emitterRemoved) {
    ElementalCondEmitter_Destroy(&(p->e).emitter);
    (p->e).emitterRemoved = 1;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a58(&(p->e).mover);
  }
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
// 1616/1776命令, Ax_Init の下書きを Shaian 用に置き換えた1回目の下書き, Ax_Init / Ghost_Init と同じ壁 (原典は大量のフィールドの番地を sp に退避して使い回す)
NON_MATCH s32 Shaian_Init(Shaian* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  p->flags = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 1);
  (p->e).kind = ENEK_SHAIAN;
  Shaian_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPR_SHAIAN);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, 0);
    k = (p->e).kind;
    if (k == ENEK_CURORO || k == ENEK_GHOST) {
      aux->spr.priority = 1;
    }
    (p->e).facing = 0;
  } else {
    EnemyMainSprite* spr;
    MainSpriteGfxFile* f;
    Vec3 origin;

    (p->e).s = Malloc(sizeof(EnemySprite));
    ClearMemory((p->e).s, sizeof(EnemySprite));
    spr = &(p->e).s->main;
    Vec3_Clear(&origin);
    f = GetFile(DIR_MAIN_SPRITE, SPR_SHAIAN);
    spr->gfx = *f;
    OpenMainSpriteFile(&spr->gfx, f);
    MainSprite_Add(&spr->spr, &spr->gfx, 0, 0, 2, 2, 60, &origin);
    (p->e).playingAnim = 0xFF;
  }

  (p->e).flags = 0;
  (p->e).flags2 = 0;
  (p->e).unk_46f = 0;
  (p->e).unk_1bc = 8;
  (p->e).flags5 = VM_GetNamedArgValue('M', 0);
  Vec3_Clear(&pos);
  (p->e).unk_4b6 = 0;
  if (!VM_SeekToNamedArg('r')) {
    (p->e).unk_250 = 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = 0;
    (p->e).prevPathNode = 0;
    (p->e).unk_4b4[(p->e).unk_4b6] = 0;
    (p->e).unk_4b4[(p->e).unk_4b6 ^ 1] = 0;
    onPath = FALSE;
  } else {
    u8 sel;

    (p->e).unk_250 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_251 = 0;
    (p->e).unk_252 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).prevPathNode = (p->e).unk_252;
    (p->e).unk_4b4[(p->e).unk_4b6] = (p->e).unk_250;
    sel = (p->e).unk_4b6;
    (p->e).unk_4b4[sel ^ 1] = VM_GetPC() != NULL ? VM_GetValue() : (p->e).unk_250;
    Map_GetPathNodePos(&pos, (p->e).unk_250, (p->e).unk_252);
    (p->e).tileIdx = GetCollisionTileIdx(&pos);
    pos.y = TileHeightAt(&pos);
    (p->e).floorY = pos.y;
    onPath = TRUE;
  }

  id = VM_GetNamedArgValue('N', 0);
  if (!VM_SeekToNamedArg('e')) {
    range0 = 48;
    range3 = 64;
  } else {
    range0 = VM_GetPC() != NULL ? VM_GetValue() : 48;
    range3 = VM_GetPC() != NULL ? (u8)VM_GetValue() : 64;
  }
  if (!VM_SeekToNamedArg('n')) {
    range1 = 0;
    (p->e).unk_1fe = 0;
  } else {
    range1 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_1fe = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  range2 = range0;

  if (VM_SeekToNamedArg('a')) {
    for (i = 0; i < 4; i++) {
      (p->e).atkPower[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkKnockback[i] = VM_GetPC() != NULL ? VM_GetValue() : 24;
      (p->e).atkAttrs[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
      (p->e).atkIframes[i] = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  if (!VM_SeekToNamedArg('l')) {
    hpParam3 = 0;
    hpParam4 = 0;
    (p->e).chaseTimeMax = 0;
  } else {
    hpParam3 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    hpParam4 = VM_GetPC() != NULL ? VM_GetValue() : 300;
    (p->e).chaseTimeMax = VM_GetPC() != NULL ? VM_GetValue() : 300;
  }
  if (VM_GetNamedArgValue('b', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_9);
  }
  (p->e).scriptID = VM_GetNamedArgValue('F', 0);
  (p->e).unk_194 = VM_GetNamedArgValue('R', 0);
  if (VM_SeekToNamedArg('A')) {
    (p->e).maxHp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_546 = (p->e).maxHp >> 1;
    (p->e).power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_187 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).unk_188 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).attrs = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weakness = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  Enemy_InitHpAndState(&p->e, (p->e).maxHp, hpParam3, hpParam4);
  Enemy_SetRanges(&p->e, 0, range0, range2, range1, range3);
  if (VM_SeekToNamedArg('X')) {
    (p->e).exp = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).weaponExp = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  (p->e).unk_25a = VM_GetNamedArgValue('K', 2);
  if (VM_GetNamedArgValue('H', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_11);
  }
  if (VM_GetNamedArgValue('L', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_15);
  }

  Mover_Init(&(p->e).mover, id, &pos, 0, MOVER_ENEMY, p);
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_CWOLF)) {
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, Enemy_OnCWolfMessage);
  }
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? &(p->e).s->aux.spr : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 64, 64);
  }
  kind = (p->e).kind;
  if (kind != ENEK_BAT && kind != ENEK_CROW && kind != ENEK_MIMIC && kind != ENEK_SLIME && kind != ENEK_BEE && kind != ENEK_CENTIPEDE && kind != ENEK_SANDWORM && kind != ENEK_SERPENT && kind != ENEK_AX && kind != ENEK_SHAIAN && kind != ENEK_SALAMANDER) {
    Mover_SetPath(&(p->e).mover, &(p->e).pathWalker, (p->e).unk_250, (p->e).unk_251, (p->e).unk_252);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_3)) {
    (p->e).unk_1e8 = Div((p->e).range0Sq * 7, 10);
  } else {
    (p->e).unk_1e8 = (p->e).range0Sq;
  }
  (p->e).zoneSource.id = (p->e).mover.id;
  (p->e).zoneSource.pos = &(p->e).mover.pos;
  if (onPath) {
    (p->e).mover.angle = ((((p->e).pathWalker.node->delay >> 12 & 7) + 5) & 7) << 5;
  }
  Shaian_InitPosAndIntervals(p);
  Shaian_InitItems(p);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 626;
  (p->e).unk_47c = 630;
  (p->e).unk_47e = (p->e).variant + 626;
  if ((p->e).spriteKind == 0) {
    Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + (p->e).variant);
  } else {
    (p->e).s->main.spr.pltt = &gObjPlttData[((p->e).plttBase + (p->e).variant) * 16];
  }
  if ((p->e).spriteKind == 1) {
    s16 n;

    if ((p->e).kind >= ENEK_SKELETON && (p->e).kind <= ENEK_LICH) {
      n = Enemy_CountByKind(ENEK_SKELETON) + 1 + Enemy_CountByKind(ENEK_SKELETON_F) + Enemy_CountByKind(ENEK_SKELETON_A) + Enemy_CountByKind(ENEK_LICH);
    } else {
      n = Enemy_CountByKind((p->e).kind) + 1;
    }
    (p->e).s->main.spr.plttID = n + 220;
  }

  (p->e).unk_476 = (p->e).plttBase;
  (p->e).unk_478 = (p->e).plttBase + 2;
  FUN_0817d6d4(p);
  Shaian_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Shaian_UpdateFrame;
  (p->e).getMoveSpeed = (void*)Shaian_GetMoveSpeed;
  (p->e).handlerTurn = Shaian_StateTurn;
  (p->e).handlerMove = Shaian_StateMove;
  (p->e).handlerWait = Shaian_StateWait;
  (p->e).handlerNap = NULL;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Shaian_StateDamaged;
  (p->e).handlerDying = Shaian_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = NULL;
  (p->e).unk_604 = FUN_080f62ac;
  (p->e).tryDetectPlayer = FUN_080f0430;
  (p->e).unk_21d = 1;
  (p->e).msgHandlers = (void*)gEnemyDefaultMsgHandlers;
  (p->e).unk_5f0 = FUN_080e73c8;
  (p->e).unk_5e4 = NULL;
  (p->e).onReset = NULL;
  (p->e).unk_5fc = NULL;
  (p->e).unk_600 = NULL;
  (p->e).unk_614 = NULL;
  (p->e).unk_618 = FUN_080f0320;
  (p->e).handlerLookAround = Enemy_080eff14;
  (p->e).unk_5e8 = FUN_080e72b0;
  (p->e).unk_5e0 = NULL;
  (p->e).unk_5ec = Enemy_StateBlownAway;
  (p->e).unk_5d8 = Enemy_StateFallDeath;
  (p->e).unk_5a8 = NULL;
  (p->e).unk_624 = FUN_080f6e64;
  (p->e).onDamaged = Enemy_OnDamaged;
  (p->e).unk_628 = (void*)FUN_080f84d4;
  (p->e).handlerChase = FUN_080f624c;
  (p->e).handlerStun = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  Map_InitNavAgent(&p->navAgent, &(p->e).mover.pos);
  Enemy_StepTowardPathNode(&p->e);
  (p->e).onReset = NULL;
  (p->e).unk_5fc = NULL;
  (p->e).tryDetectPlayer = (void*)Shaian_TryDetectPlayer;
  (p->e).unk_618 = (void*)Shaian_NoticeAttacker;
  (p->e).onAttackRequest = (EnemyHandler)Shaian_OnAttackRequest;
  (p->e).unk_5b0 = (EnemyHandler)FUN_0817bbe4;
  (p->e).onDamaged = (void*)Shaian_OnDamaged;
  (p->e).unk_1bc = 0;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9 | ENEFLAG_UNK_20 | ENEFLAG_UNK_22);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_10);
  Enemy_InitShadowAndEmitter(&p->e);
  p->shadowPos = (p->e).mover.pos;
  (p->e).shadowRemoved = AuxShadow_Init(&(p->e).auxShadow, &p->shadowPos, 64, 64, 64, 100, 0, 0, 5, 1, 0);
  AuxShadow_SetSprite(&(p->e).auxShadow, SPR_EFF_1C1B, 6);
  AuxShadow_SetAffine(&(p->e).auxShadow, 0);
  AuxShadow_Show(&(p->e).auxShadow);

  (p->e).unk_198 = VM_GetNamedArgValue('I', 0);
  if (VM_SeekToNamedArg('G')) {
    u32* arg = &(p->e).unk_19c;

    for (i = 0; i < 5; i++) {
      *arg++ = VM_GetPC() != NULL ? VM_GetValue() : 0;
    }
  }
  (p->e).defeatScriptID = VM_GetNamedArgValue('D', 0);
  {
    s32 u = VM_GetNamedArgValue('u', 0);

    (p->e).unk_496[0] = 0x21;
    (p->e).unk_496[1] = 0;
    if (u != 0) {
      SET_FLAGS((p->e).flags, ENEFLAG_UNK_18);
      if (u == 2) {
        SET_FLAGS((p->e).flags, ENEFLAG_UNK_18 | ENEFLAG_UNK_19);
      }
    }
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_2)) {
    Enemy_ResetState(&p->e, 0, 0, 0);
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  } else {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_13);
  }
  if (!TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_1)) {
    (p->e).zoneID = GetZoneAt(&(p->e).mover.pos);
  } else {
    (p->e).zoneID = gStat->zoneID;
  }
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_6)) {
    (p->e).hurtbox.flags &= ~HBF_ANGLE;
  }
  if (VM_GetNamedArgValue('S', 0) != 0 || gStat->zoneID != (p->e).zoneID) {
    Enemy_Suspend(&p->e, NULL);
  }
  Enemy_PlayAnim(&p->e, 0);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux = &(p->e).s->aux;

    AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
  } else {
    MainSprite_AdvanceAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx);
  }
  (p->e).hitTargetID = 0;
  kind = (p->e).kind;
  if (!IsLinkPlay() && (kind == ENEK_BOKU || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DOG || kind == ENEK_BEE || kind == ENEK_GHOST)) {
    MsgQueue_Register(&(p->e).mq, (p->e).mover.id, 3);
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_8);
  }
  Shaian_InitDistances(p);
  Enemy_InitHandlerTables(&p->e);
  Shaian_SetHandlerTable2(p);
  Shaian_SetHandlerTable3(p);
  Shaian_SetHandlerTable4(p);
  (p->e).initFlags5 = (p->e).flags5;
  (p->e).initHeightAboveFloor = (p->e).heightAboveFloor;
  (p->e).initFlags = (p->e).flags;
  (p->e).initFlags2 = (p->e).flags2;
  (p->e).initAngle = (p->e).mover.angle;
  (p->e).initSubState0 = (p->e).subState0;
  (p->e).initSubState1 = (p->e).subState1;
  (p->e).initSubState2 = (p->e).subState2;
  (p->e).initHandlerState = (p->e).handlerState;
  (p->e).initState = (p->e).state;
  (p->e).ownerFlagsInit = p->flags;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)Shaian_Update;
  (p->e).handlerDestroy = (EnemyHandler)Shaian_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Shaian_Init.inc");
#endif
}

// 0x8E9F, HashName("シャイアン")
void Shaian_Create(void) {
  Shaian* p = Malloc(sizeof(Shaian));

  if (p != NULL) {
    ClearMemory(p, sizeof(Shaian));
    if (Shaian_Init(p) < 0) {
      Shaian_Destroy(p);
      Free(p);
    }
  }
}
