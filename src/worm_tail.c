#include "enemy.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vec3.h"

struct WormTail;

// WormTail.flags (0x6E4)
typedef s16 WormTailFlags;
#define WORMTAILFLAG_WAVE (1 << 0)  // 0x01, Spawn の pattern が 0, くねりながら進む
#define WORMTAILFLAG_HOP (1 << 1)   // 0x02, Spawn の pattern が 0 以外, 跳ねながら進む
#define WORMTAILFLAG_HURT (1 << 2)  // 0x04, 被弾した

// WormTailSegment.flags (0x0FD)
typedef u8 WormTailSegmentFlags;
#define WORMTAILSEGFLAG_FLASH (1 << 0)   // 0x01, 被弾してパレットを白くしている
#define WORMTAILSEGFLAG_BURIED (1 << 1)  // 0x02, 地面より下にいて隠れている
#define WORMTAILSEGFLAG_ATTACK (1 << 2)  // 0x04, 攻撃判定を有効にしてよい

// ワームの尻尾の節1つ
typedef struct {
  AuxSprite sprite;            // 0x000
  AuxSpriteGfx gfx;            // 0x02C, SPR_WORM
  Hitbox atkHitbox;            // 0x048, 攻撃判定, 地上に出ていて WORMTAILSEGFLAG_ATTACK が立っている間だけ毎フレーム登録する
  Hitbox hurtbox;              // 0x098, 食らい判定, 防御力は segs[5] だけ Spawn の defense, ほかはその2倍
  AuxAnimState anim;           // 0x0E8, segs[0] は animIdx 6 の variant 1, segs[1]〜[4] は 6 の variant 2, segs[5] は 7
  AuxAnimFile* animFile;       // 0x0F8, ANIM_WORM
  u8 phase;                    // 0x0FC, 体をくねらせる波の位相 (256 で1周)
  WormTailSegmentFlags flags;  // 0x0FD
  u8 unk_fe[2];                // 0x0FE
  u16 dustCooldown;            // 0x100, 0 のときに地面へ着くと砂煙を出して 30 に戻す
  u16 attackDelay;             // 0x102, 0 になると WORMTAILSEGFLAG_ATTACK を立てて 3 に戻す, 1フレームに立てるのは2節まで
  u8 unk_104[2];               // 0x104
  u8 unk_106;                  // 0x106, 生成時に節の番号 * 24 が入るだけ
  u8 flashTime;                // 0x107, 被弾すると 6, 0 になるとパレットを戻して flags bit0 を落とす
  u8 unk_108[8];               // 0x108
  Vec3 targetPos;              // 0x110, 1つ前の節の位置 (先頭は先頭の節), 生成時は sprite.pos と同じ
  Vec3 vel;                    // 0x118, 毎フレーム sprite.pos に足してから半分にする
  struct WormTail* owner;      // 0x120
} WormTailSegment;
static_assert(sizeof(WormTailSegment) == 292);

// 6つの節が連なったワームの尻尾1本, サンドワームの尻尾攻撃, 地中から飛び出してプレイヤーの方へ進み, また潜る
typedef struct WormTail {
  WormTailSegment segs[6];  // 0x000
  u8 headIdx;               // 0x6D8, 先頭の節の添字 (0 か 5), ほかの節は先頭から順に1つ前の節を追いかける
  u8 emergeDelay;           // 0x6D9, state 1 の残りフレーム数, 10 未満になると砂を噴く間隔が 20 から 4 フレームに縮む
  u8 angle;                 // 0x6DA, state 3 に入ったときのプレイヤーへの向き (256 で1周)
  u8 landSeCooldown;        // 0x6DB, 0 のときに segs[5] が着地すると SE 0x3D9 を鳴らして 20 にする
  Vec3 vel;                 // 0x6DC, 先頭の節の速さ, state 2 は y を 124 から毎フレーム 8 ずつ, state 5 は 0 から 12 ずつ減らす
  WormTailFlags flags;      // 0x6E4
  u8 state;                 // 0x6E6, sWormTailStates の添字 (0:待機 1:地中で待つ 2:飛び出す 3:進む 4:被弾 5:潜る 6:片付け)
  s8 slotIdx;               // 0x6E7, usedMask 上の自分のビット番号, 空きは -1
  s16 timer;                // 0x6E8, state に入ってからのフレーム数
  bool8 stateBegun;         // 0x6EA, 立っていると次の更新で state の初期化をする
  u8 moveTime;              // 0x6EB, state 3 の残りフレーム数, 尽きると state 5 へ移る
} WormTail;
static_assert(sizeof(WormTail) == 1772);

// サンドワームが呼び出すワームの尻尾を1本だけ出すシングルトン
typedef struct {
  Entity e;           // 0x000, ENTITY_UNK_8
  u8 unk_18[32];      // 0x018
  u32 usedMask;       // 0x038, elems のどのスロットが使用中かのビットマスク
  WormTail elems[1];  // 0x03C
} WormTailManager;
static_assert(sizeof(WormTailManager) == 1832);

static WormTailManager* gWormTailManager;  // 0x030001FC

WormTailManager* WormTail_Create(void);
void WormTail_SpawnDust(Vec3* pos, s32 count);
s32 Entity081efa9c_Spawn(Vec3* pos, Vec3* vel, u32 spriteID, u32 animID, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12, s32 param_13, s32 param_14, s32 param_15);
void Entity081ee7a8_SpawnEx(Vec3* pos, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10, s32 a11, s32 a12, s32 a13, s32 a14, s32 a15, s32 a16, s32 a17);

static inline bool8 WormTail_TestFlags(WormTail* elem, u32 bit) {
  if (elem->flags & bit) return TRUE;
  return FALSE;
}

static inline bool8 WormTail_IsUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void WormTail_UpdateIdle(WormTailManager*, WormTail*);
void WormTail_UpdateRemove(WormTailManager*, WormTail*);
void WormTail_UpdateDive(WormTailManager*, WormTail*);
void WormTail_UpdateMove(WormTailManager*, WormTail*);
void WormTail_UpdateHurt(WormTailManager*, WormTail*);
void WormTail_UpdateWait(WormTailManager*, WormTail*);
void WormTail_UpdateEmerge(WormTailManager*, WormTail*);

void (*const sWormTailStates[7])(WormTailManager*, WormTail*) = {
    WormTail_UpdateIdle,
    WormTail_UpdateWait,
    WormTail_UpdateEmerge,
    WormTail_UpdateMove,
    WormTail_UpdateHurt,
    WormTail_UpdateDive,
    WormTail_UpdateRemove,
};  // 0x085AE588

// 6 つの節を作り, 尾 (segs[5]) はアニメ 7, 頭は 6 の variant 1, 胴は 6 の variant 2 を流して, 隠して埋まった状態にする
// 209/207命令, 残差は AuxSprite_AdvanceAnim に渡す &seg->anim を両方の枝へ複製してしまう点, 試済: ループ変数の初期化と増やす位置, 三項演算子の向き, 添字で渡す
NON_MATCH void WormTail_InitSegs(WormTail* elem, SpriteID32 spriteId, u32 animFileID, u32 phase) {
#ifdef NONMATCHING_C
  s32 n;
  s32 i;

  for (i = 0, n = 0; i < 6; i++) {
    WormTailSegment* seg = &elem->segs[i];

    Video_GetAuxSprite(&seg->gfx, spriteId);
    AuxSprite_Add(&seg->sprite, &seg->gfx, 0);
    Video_SetAuxSpritePltt(&seg->gfx, 418);
    seg->phase = phase;
    seg->animFile = GetFile(DIR_ANIMATION, animFileID);
    if (i == 5) {
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 7, 0, 0);
    } else {
      AuxAnim_SetAnim(&seg->anim, seg->animFile, 6, i <= 0 ? 1 : 2, 0);
    }
    AuxSprite_AdvanceAnim(&seg->sprite, &seg->anim);
    seg->sprite.flags |= SPRFLAG_HIDDEN;
    seg->flags = WORMTAILSEGFLAG_BURIED;
    seg->owner = elem;
    seg->unk_106 = n;
    seg->attackDelay = 0;
    n += 24;
  }
  elem->headIdx = 5;
#else
  INCFUNC("asm/func/WormTail_InitSegs.inc");
#endif
}

// 床より下に潜った節を隠して砂煙を出し, 床へ出てきた節を見せて砂煙を出す, 全部出ていれば 1, 全部潜っていれば -1, それ以外は 0
// 172/172命令, 残差は入口の範囲判定とループ変数の割り当て (原典は節の番地を r7 と r8 の2本に持ち, elem をスタックに置いて入口で判定しない), 試済: 添字ループ, 節ポインタのループ, 枝ごとに書き方を変える
NON_MATCH s32 WormTail_UpdateBuried(WormTail* elem) {
#ifdef NONMATCHING_C
  WormTailSegment* seg;
  Vec3 v;
  s32 n = 0;

  for (seg = elem->segs; seg <= &elem->segs[5]; seg++) {
    s32 height = TileHeightAtIndex(GetCollisionTileIdx(&seg->sprite.pos), &seg->sprite.pos);

    if (seg->sprite.pos.y < height) {
      if (!(seg->sprite.flags & SPRFLAG_HIDDEN)) {
        seg->sprite.flags |= SPRFLAG_HIDDEN;
        v = seg->sprite.pos;
        v.y = height - 1;
        WormTail_SpawnDust(&v, 1);
        SET_FLAGS(seg->flags, WORMTAILSEGFLAG_BURIED);
      }
      n--;
    } else {
      if ((seg->flags & WORMTAILSEGFLAG_BURIED) && (seg->sprite.flags & SPRFLAG_HIDDEN)) {
        seg->sprite.flags &= ~SPRFLAG_HIDDEN;
        v = seg->sprite.pos;
        v.y = height;
        WormTail_SpawnDust(&v, 1);
        seg->flags &= (u8)~WORMTAILSEGFLAG_BURIED;
      }
      n++;
    }
  }
  if (n > 5) {
    return 1;
  }
  if (n <= -6) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/WormTail_UpdateBuried.inc");
#endif
}

void WormTail_RemoveSprites(WormTail* elem) {
  s32 i;

  for (i = 0; i < 6; i++) {
    AuxSprite_Remove(&elem->segs[i].sprite);
  }
}

void WormTail_UnregisterHurtboxes(WormTail* elem) {
  s32 i;

  for (i = 0; i < 6; i++) {
    Hitbox_Unregister(&elem->segs[i].hurtbox);
  }
}

void WormTail_SetSegPos(WormTail* elem, s32 idx, Vec3* pos) { elem->segs[idx].sprite.pos = *pos; }

void WormTail_SetSegVel(WormTail* elem, Vec3* vel, s32 idx) { elem->segs[idx].vel = *vel; }

// startPos から endPos への曲線上に first から last の手前までの節を等間隔に並べる
// 204/206命令, Sandworm/Serpent/Salamander/Centipede_PlaceSegmentsOnCurve と同じ Hermite 曲線の壁, 呼び出し元は見つからない, 1回目の下書きで切り上げ
NON_MATCH void WormTail_PlaceSegsOnCurve(WormTail* elem, Vec3* startPos, Vec3* endPos, s32 first, s32 last) {
#ifdef NONMATCHING_C
  WorldPos start = *startPos;
  WorldPos end = *endPos;
  s32 step = Div(1024, last - (first - 1));
  s32 n = 0;
  s32 i;

  for (i = first; i < last; i++) {
    Vec3 d, v, pos;
    s32 t, t2, t3, k, m;

    n++;
    t = step * n;
    Vec3_Diff(&d, &end, &start);
    CpuFill32(0, &v, sizeof(v));
    t2 = FixToInt(10, t * t);
    t3 = FixToInt(10, t2 * t);
    k = 0;
    k *= t3 - 2 * t2 + t;
    m = v.x * (2 * t3 - 3 * t2 + 1) + d.x * (3 * t2 - 2 * t3) + k;
    pos.x = start.x + FixToInt(10, m);
    m = v.y * (2 * t3 - 3 * t2 + 1) + d.y * (3 * t2 - 2 * t3) + k;
    pos.y = start.y + FixToInt(10, m);
    m = v.z * (2 * t3 - 3 * t2 + 1) + d.z * (3 * t2 - 2 * t3) + k;
    pos.z = start.z + FixToInt(10, m);
    WormTail_SetSegPos(elem, i, &pos);
  }
#else
  INCFUNC("asm/func/WormTail_PlaceSegsOnCurve.inc");
#endif
}

// 先頭から順に, 1つ前の節から離れすぎた節を差の 1/div ずつ寄せる
void WormTail_FollowHead(WormTail* elem, s32 div, s32 distSq) {
  Vec3 prev;
  s32 i;

  prev = elem->segs[elem->headIdx].sprite.pos;
  if (elem->headIdx == 0) {
    for (i = 0; i < 6; i++) {
      Vec3 d;

      Vec3_Diff(&d, &prev, &elem->segs[i].sprite.pos);
      if (d.x * d.x + d.y * d.y + d.z * d.z > distSq) {
        elem->segs[i].sprite.pos.x += Div(d.x, div);
        elem->segs[i].sprite.pos.y += Div(d.y, div);
        elem->segs[i].sprite.pos.z += Div(d.z, div);
      }
      prev = elem->segs[i].sprite.pos;
    }
  } else {
    for (i = elem->headIdx; i >= 0; i--) {
      Vec3 d;

      Vec3_Diff(&d, &prev, &elem->segs[i].sprite.pos);
      if (d.x * d.x + d.y * d.y + d.z * d.z > distSq) {
        elem->segs[i].sprite.pos.x += Div(d.x, div);
        elem->segs[i].sprite.pos.y += Div(d.y, div);
        elem->segs[i].sprite.pos.z += Div(d.z, div);
      }
      prev = elem->segs[i].sprite.pos;
    }
  }
}

void WormTail_SetAllSegPos(WormTail* elem, Vec3* pos) {
  s32 i;

  for (i = 0; i < 6; i++) {
    elem->segs[i].sprite.pos = *pos;
    elem->segs[i].targetPos = *pos;
  }
}

// 各節の targetPos を1つ前の節の位置 (先頭は先頭の節の位置) に送る
void WormTail_ShiftTargets(WormTail* elem) {
  Vec3 prev = elem->segs[elem->headIdx].sprite.pos;
  s32 i;

  for (i = 0; i < 6; i++) {
    Vec3 cur = elem->segs[i].sprite.pos;

    elem->segs[i].targetPos = prev;
    prev = cur;
  }
}

// 各節を床の高さに合わせる, 床と 256 以上離れていれば先頭の節の高さへ, 潜っていれば床へ上げて砂煙を出し, 浮いていれば差の 1/30 ずつ下げる, 尾が着地したら音を鳴らす
// 148/146命令, 残差は dustCooldown の番地をループの外へ出してしまう点 (原典は枝の中で作る) とループ変数の割り当て, 試済: 添字, 節ポインタ, pos 経由の格納
NON_MATCH void WormTail_SnapToGround(WormTail* elem) {
#ifdef NONMATCHING_C
  bool32 landed = FALSE;
  s32 i;

  for (i = 0; i < 6; i++) {
    WormTailSegment* seg = &elem->segs[i];
    Vec3* pos = &seg->sprite.pos;
    s32 height = TileHeightAtIndex(GetCollisionTileIdx(pos), pos);

    if (pos->y != height) {
      if (pos->y < height) {
        if (abs(height - pos->y) > 255) {
          pos->y = elem->segs[elem->headIdx].sprite.pos.y;
        } else {
          pos->y = height;
          if (seg->dustCooldown == 0) {
            WormTail_SpawnDust(pos, 1);
            seg->dustCooldown = 30;
          }
          if (i == 5) {
            landed = TRUE;
          }
        }
      } else {
        pos->y += Div(height - pos->y, 30);
      }
    }
  }
  if (elem->landSeCooldown == 0 && landed) {
    PlaySound_082406e0(SONG_985);
    elem->landSeCooldown = 20;
  }
#else
  INCFUNC("asm/func/WormTail_SnapToGround.inc");
#endif
}

// 各節を vel だけ動かし, vel を半分に減らす
void WormTail_ApplySegVel(WormTail* elem) {
  s32 i;

  for (i = 0; i < 6; i++) {
    elem->segs[i].sprite.pos.x += elem->segs[i].vel.x;
    elem->segs[i].sprite.pos.y += elem->segs[i].vel.y;
    elem->segs[i].sprite.pos.z += elem->segs[i].vel.z;
    elem->segs[i].vel.x = FixToInt(1, elem->segs[i].vel.x);
    elem->segs[i].vel.y = FixToInt(1, elem->segs[i].vel.y);
    elem->segs[i].vel.z = FixToInt(1, elem->segs[i].vel.z);
  }
}

void WormTail_StartFlash(WormTailSegment* seg) {
  seg->flags |= WORMTAILSEGFLAG_FLASH;
  Video_SetAuxSpritePltt(&seg->gfx, OBP_WHITE_306);
  seg->flashTime = 6;
}

// 被弾で白くした節を flashTime が尽きたら元の色に戻し, 埋まっている節は隠し, 地上の節は無敵時間中に点滅させる
void WormTail_UpdateFlash(WormTail* elem) {
  s32 i;

  for (i = 0; i < 6; i++) {
    if (elem->segs[i].flags & WORMTAILSEGFLAG_FLASH) {
      if (elem->segs[i].flashTime != 0) {
        elem->segs[i].flashTime--;
      } else {
        Video_SetAuxSpritePltt(&elem->segs[i].gfx, 418);
        elem->segs[i].flashTime = 0;
        elem->segs[i].flags &= (u8)~WORMTAILSEGFLAG_FLASH;
      }
    }
    if (elem->segs[i].flags & WORMTAILSEGFLAG_BURIED) {
      if (elem->segs[i].hurtbox.iframes != 0) {
        elem->segs[i].hurtbox.iframes--;
      }
      elem->segs[i].sprite.flags |= SPRFLAG_HIDDEN;
    } else if (elem->segs[i].hurtbox.iframes != 0) {
      if ((elem->segs[i].hurtbox.iframes >> 2) & 1) {
        elem->segs[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      } else {
        elem->segs[i].sprite.flags |= SPRFLAG_HIDDEN;
      }
      elem->segs[i].hurtbox.iframes--;
      if (elem->segs[i].hurtbox.iframes == 0) {
        elem->segs[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      }
    }
  }
}

void WormTail_OnHit(Hitbox* a, Hitbox* b, WormTail* elem) {}

// 節の食らい判定に当たったとき, ダメージを受けて白く光り, サンドワームへダメージを知らせる, 弱点に当たっていれば当たった向きに煙を出す
// 204/208命令, Sandworm/Serpent_OnSegmentHurt と同じ壁 (乱数の添字を作る順と callee-saved の数), 試済: Vec3_Delta の向き, Random/RandomNext
NON_MATCH void WormTail_OnHurt(Hitbox* a, Hitbox* b, WormTailSegment* seg) {
#ifdef NONMATCHING_C
  WormTail* elem = seg->owner;

  if (b->iframes == 0) {
    Vec3 v;
    u16 msg[2];

    Hitbox_ApplyDamage(a, b);
    b->iframes = a->iframes;
    WormTail_StartFlash(seg);
    Vec3_Clear(&v);
    CreateDamageNumber(b, b->damage, 0, &seg->sprite.pos, &v, 1);
    msg[0] = 6;
    msg[1] = b->damage;
    Enemy_SendMsgByKind(ENEK_SANDWORM, msg);
    elem->flags |= WORMTAILFLAG_HURT;
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
    if (b->hitResult & HBRESULT_WEAK) {
      u8 angle;
      Vec3 size;
      WorldPos pos;

      if (a->flags & HBF_ANGLE) {
        angle = a->angle;
      } else {
        Vec3 d;

        Vec3_Delta(&d, &b->pos, &a->pos);
        if (d.x == 0 && d.z == 0) {
          angle = Random();
        } else {
          angle = ArcTan2_8(d.x, d.z);
        }
      }
      pos = seg->sprite.pos;
      pos.y += (u8)Random();
      angle = (s8)angle + (Random() & 0x1F) - 16;
      VEC3_SET(size, 60, 120, 40);
      EmitSmoke(&pos, 2, &size, angle, (Random() & 7) + 4, (Random() & 7) + 8, 2, 1);
    }
  }
#else
  INCFUNC("asm/func/WormTail_OnHurt.inc");
#endif
}

// 節ごとに攻撃判定と食らい判定を組む, 食らい判定の防御力は尾 (segs[5]) が defense, ほかはその2倍
// 130/133命令, 残差は引数を置く場所 (原典は knockback をスタック, weakness を sl に置く) と2つ目のループの形, 試済: 添字ループ, 節ポインタのループ, 尾の判定を &segs[5] で直接書く
NON_MATCH void WormTail_InitHitbox(WormTail* elem, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, u32 defense, HitboxAttrs hurtAttrs, u32 weakness) {
#ifdef NONMATCHING_C
  Vec3 halfSize, offset;
  WormTailSegment* tail;
  s32 i;

  VEC3_SET(halfSize, 32, 128, 32);
  VEC3_SET(offset, 0, 128, 0);
  for (i = 0; i < 6; i++) {
    WormTailSegment* seg = &elem->segs[i];

    Hitbox_Init(&seg->atkHitbox, 0, HBF_HITBOX | HBF_ONCE | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    Hitbox_SetAttack(&seg->atkHitbox, power, knockback, 0, attrs, iframes);
    Hitbox_SetHandler(&seg->atkHitbox, WormTail_OnHit, elem);
    Hitbox_SetPos(&seg->atkHitbox, &seg->sprite.pos, 0);
  }
  for (tail = elem->segs; tail <= &elem->segs[5]; tail++) {
    Hitbox_Init(&tail->hurtbox, 0, HBF_HURTBOX | HBF_NPC | HBF_HIDDEN | HBF_DAMAGE, 0, 16, &halfSize, &offset);
    if (tail == &elem->segs[5]) {
      Hitbox_SetPowerAndAttributes(&elem->segs[5].hurtbox, defense, hurtAttrs, weakness);
    } else {
      Hitbox_SetPowerAndAttributes(&tail->hurtbox, defense * 2, hurtAttrs, weakness);
    }
    Hitbox_SetPos(&tail->hurtbox, &tail->sprite.pos, 0);
    Hitbox_SetHandler(&tail->hurtbox, WormTail_OnHurt, tail);
    Hitbox_Register(&tail->hurtbox);
  }
#else
  INCFUNC("asm/func/WormTail_InitHitbox.inc");
#endif
}

// attackDelay を数え下ろし, 尽きた節の攻撃判定を有効にする, 1フレームに有効にするのは2節まで
void WormTail_UpdateAttackDelay(WormTail* elem) {
  s32 n = 0;
  s32 i;

  for (i = 0; i < 6; i++) {
    if (elem->segs[i].attackDelay != 0) {
      elem->segs[i].attackDelay--;
    } else if (n <= 1) {
      elem->segs[i].attackDelay = 3;
      elem->segs[i].flags |= WORMTAILSEGFLAG_ATTACK;
      n++;
    }
  }
}

// 地上に出ていて攻撃してよい節だけ攻撃判定と食らい判定を載せ, それ以外は隠す
void WormTail_UpdateHitbox(WormTail* elem) {
  s32 i;

  for (i = 0; i < 6; i++) {
    WormTailSegment* seg = &elem->segs[i];

    if (!(seg->flags & WORMTAILSEGFLAG_BURIED) && TEST_FLAGS(seg->flags, WORMTAILSEGFLAG_ATTACK)) {
      Hitbox_SetPos(&seg->atkHitbox, &seg->sprite.pos, 0);
      Hitbox_Register(&seg->atkHitbox);
      Hitbox_SetPos(&seg->hurtbox, &seg->sprite.pos, 0);
      Hitbox_ClearFlags(&seg->atkHitbox, HBF_HIDDEN);
      Hitbox_ClearFlags(&seg->hurtbox, HBF_HIDDEN);
    } else {
      Hitbox_Hide(&seg->atkHitbox);
      Hitbox_Hide(&seg->hurtbox);
    }
  }
}

// pos から 64 ずつ向きを回して SPR_EFF_F422 の砂煙を count 個撒く
void WormTail_SpawnDust(Vec3* pos, s32 count) {
  s32 i;

  for (i = 0; i < count; i++) {
    if (i & 1) {
      Entity081ee7a8_SpawnEx(pos, 8, 16, 4, 12, 18, i << 6, 8, 48, 1, 2, 0x200, 0, SPR_EFF_F422, ANIM_121B, 0, 0, 0xD8);
    } else {
      Entity081ee7a8_SpawnEx(pos, 8, 16, 4, 12, 18, i << 6, 8, 48, 1, 2, 0x400, 0, SPR_EFF_F422, ANIM_121B, 0, 0, 0xD8);
    }
  }
}

void WormTail_UpdateIdle(WormTailManager* p, WormTail* elem) {}

// state 6, 節の絵と食らい判定を外してスロットを空け, 待機 (state 0) に戻す
void WormTail_UpdateRemove(WormTailManager* p, WormTail* elem) {
  if (elem->stateBegun) {
    WormTail_RemoveSprites(elem);
    WormTail_UnregisterHurtboxes(elem);
    CLEAR_BIT(p->usedMask, elem->slotIdx);
    elem->slotIdx = -1;
    elem->state = 0;
    elem->stateBegun = FALSE;
  }
}

// state 5, 先頭の節を沈めながら地中へ潜り, 全部の節が埋まったら片付ける (state 6)
void WormTail_UpdateDive(WormTailManager* p, WormTail* elem) {
  if (elem->stateBegun) {
    Vec3_Clear(&elem->vel);
    elem->headIdx = 0;
    elem->stateBegun = FALSE;
    if (WormTail_TestFlags(elem, WORMTAILFLAG_WAVE)) {
      PlaySound_082406e0(SONG_421);
    }
  }
  {
    Vec3* pos = &elem->segs[elem->headIdx].sprite.pos;

    Vec3_Sum(pos, pos, &elem->vel);
  }
  elem->vel.y -= 12;
  WormTail_FollowHead(elem, 4, 25000);
  WormTail_UpdateBuried(elem);
  WormTail_UpdateHitbox(elem);
  WormTail_UpdateFlash(elem);
  if (WormTail_UpdateBuried(elem) < 0) {
    elem->state = 6;
    elem->stateBegun = TRUE;
  }
}

// くねりながら進むとき, 先頭 (segs[0]) から後ろの節へ波の位相を 32 ずつずらす
void WormTail_InitWavePhases(WormTail* elem) {
  s32 i;

  for (i = 1; i < 6; i++) {
    elem->segs[i].phase = i * 32;
  }
}

// 跳ねながら進むとき, 先頭 (segs[5]) から前の節へ波の位相を 8 ずつずらす
// 15/15命令, 残差は位相の += 8 が節のポインタを進める前か後かだけ, 試済: 位相の変数, (5 - i) * 8, 昇順の添字
NON_MATCH void WormTail_InitHopPhases(WormTail* elem) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 5; i > 0; i--) {
    elem->segs[i].phase = (5 - i) * 8;
  }
#else
  INCFUNC("asm/func/WormTail_InitHopPhases.inc");
#endif
}

// くねりながら進むとき, 先頭以外の節を位相に合わせて円を描くように揺らし, 30 フレームごとに先頭の節の足元へ砂煙を出す
void WormTail_MoveWave(WormTail* elem) {
  s32 i;

  for (i = 1; i < 6; i++) {
    Vec3 v;

    elem->segs[i].phase += 2;
    Vec3_SetPolar(&v, elem->segs[i].phase, 2);
    WormTail_SetSegVel(elem, &v, i);
  }
  if (Mod(elem->timer, 30) == 0) {
    WorldPos pos = elem->segs[elem->headIdx].sprite.pos;

    pos.y = TileHeightAtIndex(GetCollisionTileIdx(&pos), &pos);
    WormTail_SpawnDust(&pos, 2);
  }
  WormTail_ApplySegVel(elem);
}

// 跳ねながら進むとき, 尾 (segs[5]) を跳ねさせ, 着地後は後ろの節を順に波打たせて進ませる, 30 フレームごとに砂煙を出し, 節と着地音の待ちを数え下ろす
// 415/423命令の下書き, 残差は分岐の末尾の cross-jump のまとめ方と, ループで速さの変数を退避するスタック, 1回目の下書きで切り上げ
NON_MATCH void WormTail_MoveHop(WormTail* elem) {
#ifdef NONMATCHING_C
  Vec3 v;
  s32 i;

  Vec3_Clear(&v);
  if (elem->timer <= 5) {
    Vec3_SetPolar(&v, (elem->angle + 0x80) & 0xFF, 64);
    v.y = 32;
    WormTail_SetSegVel(elem, &v, 5);
  } else if (elem->timer <= 11) {
    v.y = -24;
    WormTail_SetSegVel(elem, &v, 5);
  } else if (elem->timer <= 21) {
    v.y = -8;
    WormTail_SetSegVel(elem, &v, 5);
  } else if (elem->timer <= 29) {
    Vec3_SetPolar(&v, elem->angle, 12);
    v.y = 42;
    WormTail_SetSegVel(elem, &v, 5);
  } else if (elem->timer <= 39) {
    Vec3_SetPolar(&v, elem->angle, 32);
    v.y = 12;
    WormTail_SetSegVel(elem, &v, 5);
  } else if (elem->timer <= 53) {
    Vec3_SetPolar(&v, elem->angle, 48);
    v.y = -32;
    WormTail_SetSegVel(elem, &v, 5);
  } else {
    elem->headIdx = 0;
    for (i = 1; i < 6; i++) {
      Vec3_SetPolar(&v, elem->angle, i * 8);
      elem->segs[i].phase += 10;
      v.y = FixToInt(12, SIN(elem->segs[i].phase) * (22 * i));
      WormTail_SetSegVel(elem, &v, i);
    }
  }
  if (Mod(elem->timer, 30) == 0) {
    v = elem->segs[elem->headIdx].sprite.pos;
    v.y = TileHeightAtIndex(GetCollisionTileIdx(&v), &v);
    WormTail_SpawnDust(&v, 1);
  }
  WormTail_ApplySegVel(elem);
  WormTail_SnapToGround(elem);
  for (i = 0; i < 6; i++) {
    if (elem->segs[i].dustCooldown != 0) {
      elem->segs[i].dustCooldown--;
    }
  }
  if (elem->landSeCooldown != 0) {
    elem->landSeCooldown--;
  }
#else
  INCFUNC("asm/func/WormTail_MoveHop.inc");
#endif
}

// 被弾中, 後ろの4節を左右に揺らし, 10 フレームごとに先頭の節の足元へ砂煙を出してから, 当たり判定と移動を進める
void WormTail_Wriggle(WormTail* elem) {
  s32 i;

  for (i = 2; i < 6; i++) {
    s32 amplitude = i * 8;
    Vec3 v;

    elem->segs[i].phase += (elem->timer >> 1) + 16;
    v.x = FixToInt(12, SIN(elem->segs[i].phase) * amplitude);
    v.z = 0;
    v.y = 0;
    WormTail_SetSegVel(elem, &v, i);
  }
  if (Mod(elem->timer, 10) == 0) {
    WorldPos pos = elem->segs[elem->headIdx].sprite.pos;

    pos.y = TileHeightAtIndex(GetCollisionTileIdx(&pos), &pos);
    WormTail_SpawnDust(&pos, 1);
  }
  WormTail_UpdateHitbox(elem);
  WormTail_ApplySegVel(elem);
}

// state 3, プレイヤーの方へくねりながら (または跳ねながら) 進み, 被弾したら state 4, moveTime が尽きたら潜る (state 5)
void WormTail_UpdateMove(WormTailManager* p, WormTail* elem) {
  if (elem->stateBegun) {
    Vec3 d;

    Vec3_Clear(&elem->vel);
    elem->timer = 0;
    elem->stateBegun = FALSE;
    Vec3_Delta(&d, &elem->segs[0].sprite.pos, &gPlayerPtr[0]->mover.pos);
    elem->angle = ArcTan2_8(d.x, d.z);
    if (WormTail_TestFlags(elem, WORMTAILFLAG_WAVE)) {
      WormTail_InitWavePhases(elem);
      elem->headIdx = 0;
    } else {
      WormTail_InitHopPhases(elem);
      elem->headIdx = 5;
    }
  }
  if (WormTail_TestFlags(elem, WORMTAILFLAG_WAVE)) {
    WormTail_MoveWave(elem);
    WormTail_FollowHead(elem, 8, 28000);
  } else {
    WormTail_MoveHop(elem);
    WormTail_FollowHead(elem, 4, 20000);
  }
  WormTail_UpdateBuried(elem);
  WormTail_UpdateHitbox(elem);
  WormTail_UpdateFlash(elem);
  if (elem->flags & WORMTAILFLAG_HURT) {
    elem->state = 4;
    elem->stateBegun = TRUE;
  } else {
    elem->timer++;
    if (elem->moveTime != 0) {
      elem->moveTime--;
    } else {
      elem->state = 5;
      elem->stateBegun = TRUE;
    }
  }
}

// state 4, 被弾して身をよじり, 30 フレーム後に潜る (state 5)
void WormTail_UpdateHurt(WormTailManager* p, WormTail* elem) {
  if (elem->stateBegun) {
    Vec3_Clear(&elem->vel);
    elem->timer = 0;
    elem->stateBegun = FALSE;
    elem->headIdx = 0;
    WormTail_InitWavePhases(elem);
    PlaySound_082406e0(SONG_418);
  }
  WormTail_Wriggle(elem);
  WormTail_FollowHead(elem, 8, 28000);
  WormTail_UpdateBuried(elem);
  WormTail_UpdateFlash(elem);
  if (elem->timer < 30) {
    elem->timer++;
  } else {
    elem->state = 5;
    elem->stateBegun = TRUE;
  }
}

// state 1, 地中で待つ間, 先頭の節の足元から砂煙を出して小石を噴き上げる, 出る直前の 10 フレームは 4 フレームごとに勢いよく噴く, 待ち終えたら音を鳴らして飛び出す (state 2)
// 410/410命令, 残差はレジスタ割り当てだけ (原典は elem を r7, 0xFF を r5, 向きを r6 に置く), 試済: 向きの (u8)/& 0xFF, Random/RandomNext, 高さを節の座標から引く, 局所変数の宣言位置
NON_MATCH void WormTail_UpdateWait(WormTailManager* p, WormTail* elem) {
#ifdef NONMATCHING_C
  WorldPos pos;
  Vec3 vel;

  if (elem->stateBegun) {
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  if (elem->emergeDelay < 10) {
    if (Mod(elem->timer, 4) == 0) {
      Vec3* head = &elem->segs[elem->headIdx].sprite.pos;

      pos = *head;
      pos.y = TileHeightAtIndex(GetCollisionTileIdx(head), head);
      WormTail_SpawnDust(&pos, 2);
      Vec3_SetPolar(&vel, RandomNext() & 0xFF, (Random() & 3) + 10);
      vel.y = (Random() & 0x1F) + 24;
      Entity081efa9c_Spawn(&pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 2, 40, 0, 0, 573, 0, 1, 0, 0, 0, 0);
    }
  } else if (Mod(elem->timer, 20) == 0) {
    Vec3* head = &elem->segs[elem->headIdx].sprite.pos;

    pos = *head;
    pos.y = TileHeightAtIndex(GetCollisionTileIdx(head), head);
    WormTail_SpawnDust(&pos, 1);
    Vec3_SetPolar(&vel, RandomNext() & 0xFF, (Random() & 7) + 6);
    vel.y = (Random() & 7) + 16;
    Entity081efa9c_Spawn(&pos, &vel, SPR_BLOCK_ROCK, ANIM_E677, 2, 30, 0, 0, 573, 0, 1, 0, 0, 0, 0);
  }
  elem->timer++;
  if (elem->emergeDelay != 0) {
    elem->emergeDelay--;
  } else {
    if (elem->flags & WORMTAILFLAG_WAVE) {
      PlaySound_082406e0(SONG_413);
    } else {
      PlaySound_082406e0(SONG_986);
    }
    elem->state = 2;
    elem->stateBegun = TRUE;
  }
#else
  INCFUNC("asm/func/WormTail_UpdateWait.inc");
#endif
}

// state 2, 先頭の節を真上へ飛び出させ, 上がりきったら進む (state 3)
void WormTail_UpdateEmerge(WormTailManager* p, WormTail* elem) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    Vec3_Clear(&elem->vel);
    elem->vel.y = 124;
    elem->timer = 0;
  }
  if (elem->vel.y > 0) {
    Vec3* pos = &elem->segs[elem->headIdx].sprite.pos;

    Vec3_Sum(pos, pos, &elem->vel);
    elem->vel.y -= 8;
  } else {
    elem->state = 3;
    elem->stateBegun = TRUE;
  }
  WormTail_FollowHead(elem, 4, 32000);
  WormTail_UpdateBuried(elem);
  WormTail_UpdateHitbox(elem);
  WormTail_UpdateFlash(elem);
}

// 空いているスロットを1つ確保して 0 で埋める
WormTail* WormTail_AllocElem_Internal(WormTailManager* p) {
  s32 i;

  for (i = 0; i < 1; i++) {
    if (!WormTail_IsUsed(&p->usedMask, i)) {
      WormTail* elem = &p->elems[i];

      ClearMemory(elem, sizeof(WormTail));
      p->usedMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

WormTail* WormTail_AllocElem(WormTailManager* p) {
  WormTail* elem = WormTail_AllocElem_Internal(p);

  if (elem == NULL) {
    return NULL;
  }
  return elem;
}

// pos の 256 下からワームの尻尾を1本出す, pattern が 0 ならくねりながら, それ以外は跳ねながら進む
void WormTail_Spawn(Vec3* pos, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 moveTime, s32 unk_6, s32 unk_7, s32 emergeDelay, s32 pattern, u32 defense, HitboxAttrs hurtAttrs, u32 weakness) {
  WormTailManager* p = gWormTailManager;
  WormTail* elem;
  Vec3 v;

  if (p == NULL) {
    p = WormTail_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = WormTail_AllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->flags = 0;
  elem->emergeDelay = emergeDelay;
  elem->moveTime = moveTime;
  elem->stateBegun = TRUE;
  if (pattern == 0) {
    elem->flags = WORMTAILFLAG_WAVE;
  } else {
    elem->flags = WORMTAILFLAG_HOP;
  }
  v = *pos;
  v.y -= 256;
  WormTail_InitSegs(elem, SPR_WORM, ANIM_WORM, 0);
  WormTail_SetAllSegPos(elem, &v);
  WormTail_InitHitbox(elem, power, knockback, attrs, iframes, defense, hurtAttrs, weakness);
}

// 使用中のワームを state ごとに動かし, 節の攻撃判定を順に有効にする
s32 WormTail_Update(WormTailManager* p) {
  WormTail* elems = p->elems;
  s32 i;

  for (i = 0; i < 1; i++) {
    if (WormTail_IsUsed(&p->usedMask, i)) {
      sWormTailStates[elems[i].state](p, &elems[i]);
      WormTail_UpdateAttackDelay(&elems[i]);
    }
  }
  return 0;
}

s32 WormTail_Destroy(WormTailManager* p) {
  s32 i;

  for (i = 0; i < 1; i++) {
    if (WormTail_IsUsed(&p->usedMask, i)) {
      WormTail* elem = &p->elems[i];

      WormTail_RemoveSprites(elem);
      WormTail_UnregisterHurtboxes(elem);
    }
  }
  gWormTailManager = NULL;
  return 0;
}

s32 WormTail_Init(WormTailManager* p) {
  p->usedMask = 0;
  gWormTailManager = p;
  return 0;
}

WormTailManager* WormTail_Create(void) {
  if (gWormTailManager == NULL) {
    WormTailManager* p = CreateEntity(ENTITY_UNK_8, sizeof(WormTailManager));

    if (p != NULL) {
      SetEntityRoutine(p, WormTail_Update, WormTail_Destroy);
      if (WormTail_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gWormTailManager;
}

void WormTail_ClearGlobal(void) { gWormTailManager = NULL; }

// ワームが出ていなければ TRUE
bool8 WormTail_IsIdle(void) {
  if (gWormTailManager != NULL && gWormTailManager->elems[0].state != 0) {
    return FALSE;
  }
  return TRUE;
}

// 出ているワームを潜らせる (state 5 へ移す), 待機中や潜っている途中, 片付け中なら何もしない
void WormTail_RequestDive(void) {
  WormTailManager* p = gWormTailManager;

  if (p != NULL) {
    WormTail* elem = &p->elems[0];

    if (elem->state != 0 && elem->state != 5 && elem->state != 6) {
      elem->state = 5;
      elem->stateBegun = TRUE;
    }
  }
}
