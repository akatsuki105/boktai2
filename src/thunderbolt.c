#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

// プレイヤー付近へ曲線を描いて飛び, y を 340 下げた位置に Entity081f0b90 の攻撃判定を出すのを attackCount 回くり返す1体
typedef struct {
  AuxSprite sprite;     // 0x000, パレットは 0xFB, 攻撃判定を出してからアニメが一巡するまでは 0xFE
  AuxSpriteGfx gfx;     // 0x02C, SPR_SKELETON_MISC
  AuxAnimState anim;    // 0x048, アニメ 0x17 (出現, 消滅は逆再生), 0x0E (飛行, 滞空, 攻撃)
  PathWalker path;      // 0x058, 経路 3, 曲線を作り直すたびに別のノードへ進めるが, その座標は使わない
  AuxShadow shadow;     // 0x064
  Vec3 dest;            // 0x0D0, 曲線の終点 (プレイヤーの位置を乱数でずらし y は 0), state 1 では y だけ上昇先 (生成位置 + 968) に使う
  Vec3 curve[12];       // 0x0D8, sprite.pos から dest へ向かう曲線上の点, state 2 で順にたどる
  Vec3 unk_138;         // 0x138, 曲線を作るたびに dest と同じ値が入る, 読み手は未発見
  Vec3 vel;             // 0x140, x と z だけ使う, state 1 では出現先の座標, state 2 では1フレームの移動量で, 曲線の始点の向きにもなる
  Vec3 basePos;         // 0x148, 上下の揺れを足す前の座標, state 4 ではここへ戻す
  u16 unk_150;          // 0x150, 0 が入るだけ
  u8 state;             // 0x152, sThunderboltStates の添字 (0:待機 1:出現 2:飛行 3:滞空 4:攻撃 5:消滅)
  s8 slotIdx;           // 0x153, usedMask 上の自分のビット番号, 空きは -1
  u16 timer;            // 0x154, state に入ってからのフレーム数 (state 2 は曲線を作り直すたびに 0), state 2 では moveTime から毎フレーム引く量にもなる
  bool8 stateBegun;     // 0x156, 立っていると次の更新で state の初期化をする
  u8 unk_157;           // 0x157, state 2 へ移るときに 1 が入るだけ
  bool8 animEnded;      // 0x158, state 1 で出現アニメが一巡すると立つ
  u8 appearAngle;       // 0x159, 出現先を決める向き (256 で1周), 距離は 64〜319 の乱数
  u8 phase;             // 0x15A, 上下に揺れる位相 (256 で1周), state 2 は毎フレーム +6, state 3 は 0 から +4 ずつ 128 まで
  s8 shadowId;          // 0x15B, 0 のときだけ片付けで影を外す
  u8 pointIdx;          // 0x15C, curve のいま向かっている点, 12 を超えると曲線を作り直す
  u8 knockback;         // 0x15D, Entity081f0b90 の攻撃判定に渡す
  u8 iframes;           // 0x15E, Entity081f0b90 の攻撃判定に渡す
  u8 unk_15f;           // 0x15F, スケルトンは 20 を渡す, 読み手は未発見
  HitboxAttrs attrs;    // 0x160, Entity081f0b90 の攻撃判定に渡す
  u16 power;            // 0x164, Entity081f0b90 の攻撃判定に渡す
  u8 unk_166;           // 0x166, 曲線を作ると 0, state 2 へ移ると 1, 読み手は未発見
  u8 unk_167;           // 0x167
  u16 attackCount;      // 0x168, 残りの攻撃回数, 攻撃のたびに -1 して 0 になると消滅へ移る
  u16 flyTime;          // 0x16A, state 2 の最短フレーム数
  u16 flyTimer;         // 0x16C, state 2 の残りフレーム数, 0 になったあと曲線を作り直すと state 3 へ移る
  s16 moveTime;         // 0x16E, state 1 は出現先までの残りフレーム数 (初期値 20), state 2 は曲線ごとに 1120 から毎フレーム timer ずつ減り, 1/64 を次の点までのフレーム数にする
  u16 scriptID;         // 0x170, 攻撃判定を出すときに 0 でなければ VM_ExecByID で実行する
  u16 explodeScriptID;  // 0x172, Entity081f0b90 の攻撃判定の scriptID に渡す
} Thunderbolt;
static_assert(sizeof(Thunderbolt) == 372);

// リッチ (ENEID_LICH) の技 "サンダーボルト", Skeleton_StateCurveShot から呼ばれ, 最大4体まで同時に飛ばすシングルトン
typedef struct {
  Entity e;              // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;     // 0x018, ANIM_1DC3
  u32 usedMask;          // 0x01C, elems のどのスロットが使用中かのビットマスク
  Thunderbolt elems[4];  // 0x020
} ThunderboltManager;
static_assert(sizeof(ThunderboltManager) == 1520);

static ThunderboltManager* gThunderboltManager;  // 0x030001F4

ThunderboltManager* ThunderboltManager_Create(void);
void Entity081f0b90_Spawn(Vec3* pos, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 _, u32 scriptID);

static inline bool8 ThunderboltManager_IsUsed(ThunderboltManager* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

void Thunderbolt_ExecScript(Thunderbolt* elem) {
  if (elem->scriptID != 0) {
    VM_ExecByID(elem->scriptID, NULL);
  }
}

void Thunderbolt_StateIdle(ThunderboltManager* p, Thunderbolt* elem) {}

// state 5, 出現アニメを逆再生し, 終わったらスロットを空ける
void Thunderbolt_StateVanish(ThunderboltManager* p, Thunderbolt* elem) {
  if (elem->stateBegun) {
    AuxAnim_SetAnim(&elem->anim, p->anim, 0x17, 0, ANIM_PLAY_REVERSE);
    elem->stateBegun = FALSE;
  }
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim)) {
    CLEAR_BIT(p->usedMask, elem->slotIdx);
    elem->state = 0;
    if (elem->sprite.active) {
      AuxSprite_Remove(&elem->sprite);
    }
    if (elem->shadowId == 0) {
      AuxShadow_Remove(&elem->shadow);
    }
    elem->slotIdx = -1;
    elem->unk_150 = 0;
  }
}

// state 1, 出現アニメを流しながら乱数で決めた向きと距離の先へ dest.y の高さまで 20 フレームかけて昇り, 着いたら飛行へ移る
void Thunderbolt_StateAppear(ThunderboltManager* p, Thunderbolt* elem) {
  if (elem->stateBegun) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    elem->moveTime = 20;
    elem->animEnded = FALSE;
    elem->appearAngle = RandomNext();
    Vec3_SetPolar(&elem->vel, elem->appearAngle, (RandomNext() & 0xFF) + 64);
    Vec3_Sum(&elem->vel, &elem->sprite.pos, &elem->vel);
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  if (elem->moveTime > 0) {
    elem->sprite.pos.x += Div(elem->vel.x - elem->sprite.pos.x, elem->moveTime);
    elem->sprite.pos.y += Div(elem->dest.y - elem->sprite.pos.y, elem->moveTime);
    elem->sprite.pos.z += Div(elem->vel.z - elem->sprite.pos.z, elem->moveTime);
    elem->moveTime--;
  }
  if (!elem->animEnded) {
    elem->animEnded = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  }
  if (elem->animEnded && elem->moveTime <= 0) {
    elem->basePos = elem->sprite.pos;
    elem->state = 2;
    elem->unk_157 = 1;
    elem->unk_166 = 1;
    elem->stateBegun = TRUE;
  }
}

// 経路のノードを1つ乱数で進め, プレイヤーの位置を乱数でずらした dest へ向かう曲線を 12 等分した点を curve に求める
// 367/363命令, Ghost/Bee_BuildCurvePoints や WormTail/Sandworm の曲線と同じ Hermite 曲線の壁, 原典は &dest をスタックに2つ持ち curve[i] を elem + i*8 + 0xD8 の順に作る
// 試済: dest のポインタ変数の有無, curve + i と step * (i + 1) (369→367), 乱数の & 0xFF, Vec3_Sum, GetPlayer inline
NON_MATCH void Thunderbolt_BuildCurve(Thunderbolt* elem) {
#ifdef NONMATCHING_C
  PathWalker* w = &elem->path;
  u8 next;
  Vec3 diff, ofs;
  WorldPos start;
  Vec3* dest;
  s32 step, k0, k1, i, t, t2, t3, m, n;

  next = Mod(RandomNext(), w->path->nodeCount);
  if (next == w->nodeIdx) {
    next = Mod(next + 1, w->path->nodeCount);
  }
  w->nodeIdx = next;
  w->waitTimer = 0;
  w->node = Map_GetPathNodes(w->path) + w->nodeIdx;

  Vec3_Diff(&diff, &elem->sprite.pos, &gPlayerPtr[0]->mover.pos);
  dest = &elem->dest;
  *dest = gPlayerPtr[0]->mover.pos;
  elem->unk_166 = 0;
  Vec3_SetPolar(&ofs, (u8)RandomNext(), (RandomNext() & 0xFF) - 128);
  Vec3_Add(dest, &ofs);
  start = elem->sprite.pos;
  start.y = 0;
  dest->y = 0;
  step = Div(1024, 12);
  k0 = elem->vel.x << 7;
  k1 = elem->vel.z << 7;
  for (i = 0; i < 12; i++) {
    Vec3* dst = elem->curve + i;
    Vec3 d, v;

    t = step * (i + 1);
    Vec3_Diff(&d, dest, &start);
    Vec3_Clear(&v);
    t2 = FixToInt(10, t * t);
    t3 = FixToInt(10, t2 * t);
    m = k1 * (t3 - 2 * t2 + t);
    n = v.x * (2 * t3 - 3 * t2 + 1) * k0 + d.x * (3 * t2 - 2 * t3) + m + (t3 - t2);
    dst->x = start.x + FixToInt(10, n);
    n = v.y * (2 * t3 - 3 * t2 + 1) * k0 + d.y * (3 * t2 - 2 * t3) + m + (t3 - t2);
    dst->y = start.y + FixToInt(10, n);
    n = v.z * (2 * t3 - 3 * t2 + 1) * k0 + d.z * (3 * t2 - 2 * t3) + m + (t3 - t2);
    dst->z = start.z + FixToInt(10, n);
  }
  elem->unk_138 = *dest;
#else
  INCFUNC("asm/func/Thunderbolt_BuildCurve.inc");
#endif
}

// state 2, 曲線上の点を順にたどって上下に揺れながら飛び, 点を使い切ったら曲線を作り直す, flyTimer が尽きてから作り直したら滞空へ移る
// 461/461命令, 残差は入場時の Random() で表の番地と phase の番地の r1/r3 と r2/r3 が入れ替わるだけ
// 試済: RandomNext, Random() & 0xFF, SetPolar の角度を (u8) に, 効いた手: 中盤は elem->sprite.pos 直書き, Vec3_Delta, frames >= 1 の三項演算子
NON_MATCH void Thunderbolt_StateFly(ThunderboltManager* p, Thunderbolt* elem) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  AuxAnimState* anim = &elem->anim;
  bool32 rebuilt = FALSE;
  Vec3 d;

  if (elem->stateBegun) {
    AuxAnim_SetAnim(anim, p->anim, 0x0E, 0, 0);
    elem->flyTimer = elem->flyTime;
    elem->phase = Random();
    Vec3_SetPolar(&elem->vel, elem->phase, 24);
    elem->moveTime = 1120;
    elem->timer = 0;
    elem->stateBegun = FALSE;
    elem->pointIdx = 0;
    Thunderbolt_BuildCurve(elem);
  }
  Vec3_Delta(&d, &elem->sprite.pos, &elem->curve[elem->pointIdx]);
  if (elem->moveTime > 0 && d.x * d.x + d.z * d.z > 0) {
    s32 frames = FixToInt(6, elem->moveTime);

    frames = frames >= 1 ? frames : 1;
    elem->vel.x = Div(elem->curve[elem->pointIdx].x - elem->sprite.pos.x, frames);
    elem->vel.z = Div(elem->curve[elem->pointIdx].z - elem->sprite.pos.z, frames);
    elem->sprite.pos.x += elem->vel.x;
    elem->sprite.pos.z += elem->vel.z;
    elem->moveTime -= elem->timer;
  } else if (++elem->pointIdx > 12) {
    elem->sprite.pos.x = elem->dest.x;
    elem->sprite.pos.z = elem->dest.z;
    Thunderbolt_BuildCurve(elem);
    elem->moveTime = 1120;
    elem->pointIdx = 0;
    elem->timer = 0;
    rebuilt = TRUE;
  } else {
    elem->sprite.pos.x = elem->curve[elem->pointIdx - 1].x;
    elem->sprite.pos.z = elem->curve[elem->pointIdx - 1].z;
  }
  elem->timer++;
  sprite->pos.y = elem->basePos.y + FixToInt(8, SIN(elem->phase));
  elem->basePos.x = sprite->pos.x;
  elem->basePos.z = sprite->pos.z;
  elem->phase += 6;
  AuxSprite_AdvanceAnim(sprite, anim);
  if (elem->flyTimer != 0) {
    elem->flyTimer--;
  } else if (rebuilt) {
    elem->state = 3;
    elem->stateBegun = TRUE;
  }
#else
  INCFUNC("asm/func/Thunderbolt_StateFly.inc");
#endif
}

// state 3, 上下に半周だけ揺れて止まり, 60 フレーム経ってアニメが一巡したら攻撃へ移る
void Thunderbolt_StateHover(ThunderboltManager* p, Thunderbolt* elem) {
  AuxSprite* sprite = &elem->sprite;
  AuxAnimState* anim = &elem->anim;
  bool32 animDone;

  if (elem->stateBegun) {
    AuxAnim_SetAnim(anim, p->anim, 0x0E, 0, 0);
    elem->timer = 0;
    elem->stateBegun = FALSE;
    elem->phase = 0;
  }
  animDone = AuxSprite_AdvanceAnim(sprite, anim);
  if ((s8)elem->phase >= 0) {
    sprite->pos.y = elem->basePos.y - POLAR_X(64, elem->phase);
    elem->phase += 4;
  }
  if (elem->timer < 60) {
    elem->timer++;
  } else if (animDone) {
    elem->state = 4;
    elem->stateBegun = TRUE;
  }
}

// state 4, 小刻みに震え, 4 フレーム目に真下 340 の位置へ雷の攻撃判定を落とす, アニメが一巡したら残りの回数で飛行か消滅へ移る
void Thunderbolt_StateAttack(ThunderboltManager* p, Thunderbolt* elem) {
  AuxSprite* sprite = &elem->sprite;
  AuxAnimState* anim = &elem->anim;

  if (elem->stateBegun) {
    AuxAnim_SetAnim(anim, p->anim, 0x0E, 0, 0);
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  sprite->pos = elem->basePos;
  if (elem->timer < 10) {
    sprite->pos.x = elem->basePos.x + ((RandomNext() & 63) - 48);
    sprite->pos.z = elem->basePos.z + ((RandomNext() & 63) - 48);
  }
  if (elem->timer == 4) {
    Vec3 pos;

    Video_SetAuxSpritePltt(sprite->gfx, 0xFE);
    pos = sprite->pos;
    pos.y -= 340;
    Entity081f0b90_Spawn(&pos, elem->power, elem->knockback, elem->attrs, elem->iframes, 20, elem->explodeScriptID);
    Thunderbolt_ExecScript(elem);
  }
  if (AuxSprite_AdvanceAnim(sprite, anim)) {
    elem->attackCount--;
    Video_SetAuxSpritePltt(sprite->gfx, 0xFB);
    if (elem->attackCount != 0) {
      elem->state = 2;
    } else {
      elem->state = 5;
    }
    elem->stateBegun = TRUE;
  } else {
    elem->timer++;
  }
}

// 空いているスロットを1つ確保して 0 で埋める
Thunderbolt* ThunderboltManager_AllocBolt(ThunderboltManager* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!ThunderboltManager_IsUsed(p, i)) {
      Thunderbolt* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      ClearMemory(elem, sizeof(Thunderbolt));
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

// 空いているスロットを1つ確保する, 無ければ NULL
Thunderbolt* ThunderboltManager_TryAllocBolt(ThunderboltManager* p) {
  Thunderbolt* elem = ThunderboltManager_AllocBolt(p);

  if (elem == NULL) {
    return NULL;
  }
  return elem;
}

// pos の上空 968 へ昇ってから飛び始めるサンダーボルトを1体出す, target は使われない
void ThunderboltManager_Spawn(Vec3* pos, Vec3* target, s32 flyTime, s32 attackCount, s32 power, s32 knockback, HitboxAttrs attrs, s32 iframes, s32 unk_9, u32 scriptID, u32 explodeScriptID) {
  ThunderboltManager* p = gThunderboltManager;
  Thunderbolt* elem;

  if (p == NULL) {
    p = ThunderboltManager_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = ThunderboltManager_TryAllocBolt(p);
  if (elem == NULL) {
    return;
  }
  elem->state = 1;
  elem->unk_150 = 0;
  elem->timer = 0;
  elem->attackCount = attackCount;
  elem->unk_15f = unk_9;
  elem->power = power;
  elem->knockback = knockback;
  elem->attrs = attrs;
  elem->iframes = iframes;
  elem->flyTime = flyTime;
  elem->stateBegun = TRUE;
  elem->scriptID = scriptID;
  elem->explodeScriptID = explodeScriptID;
  Map_InitPathWalker(&elem->path, 3, 0, 0);
  elem->shadowId = AuxShadow_Init(&elem->shadow, &elem->sprite.pos, 0x40, 0x10, 0x60, 100, 0xE00, 1, 5, 1, 0);
  elem->dest = *pos;
  elem->dest.y += 968;
  if (Video_GetAuxSprite(&elem->gfx, SPR_SKELETON_MISC)) {
    AuxSprite_Add(&elem->sprite, &elem->gfx, 0);
    elem->sprite.flags |= SPRFLAG_HIDDEN;
    AuxAnim_SetAnim(&elem->anim, p->anim, 0x17, 0, 0);
    Video_SetAuxSpritePltt(elem->sprite.gfx, 0xFB);
    elem->sprite.pos = *pos;
    elem->sprite.priority = 1;
  }
}

void (*const sThunderboltStates[6])(ThunderboltManager*, Thunderbolt*) = {
    Thunderbolt_StateIdle,
    Thunderbolt_StateAppear,
    Thunderbolt_StateFly,
    Thunderbolt_StateHover,
    Thunderbolt_StateAttack,
    Thunderbolt_StateVanish,
};  // 0x085AE560

// ゲームオーバー中とプレイヤーが倒れている間を除き, 使用中のスロットを state ごとに動かす
s32 ThunderboltManager_Update(ThunderboltManager* p) {
  Thunderbolt* elems = p->elems;
  s32 i;

  if (p->usedMask != 0 && !TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER) && !TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    for (i = 0; i < 4; i++) {
      if (ThunderboltManager_IsUsed(p, i)) {
        sThunderboltStates[elems[i].state](p, &elems[i]);
      }
    }
  }
  return 0;
}

s32 ThunderboltManager_Destroy(ThunderboltManager* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (ThunderboltManager_IsUsed(p, i)) {
      Thunderbolt* elem = &p->elems[i];

      if (elem->sprite.active) {
        AuxSprite_Remove(&elem->sprite);
      }
      if (elem->shadowId == 0) {
        AuxShadow_Remove(&elem->shadow);
      }
    }
  }
  gThunderboltManager = NULL;
  return 0;
}

s32 ThunderboltManager_Init(ThunderboltManager* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_1DC3);
  p->usedMask = 0;
  gThunderboltManager = p;
  return 0;
}

ThunderboltManager* ThunderboltManager_Create(void) {
  if (gThunderboltManager == NULL) {
    ThunderboltManager* p = CreateEntity(ENTITY_UNK_10, sizeof(ThunderboltManager));

    if (p != NULL) {
      SetEntityRoutine(p, ThunderboltManager_Update, ThunderboltManager_Destroy);
      if (ThunderboltManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gThunderboltManager;
}

void ThunderboltManager_ClearGlobal(void) { gThunderboltManager = NULL; }

// 飛んでいるものを全て消滅 (state 5) へ移す
void ThunderboltManager_VanishAll(void) {
  ThunderboltManager* p = gThunderboltManager;
  s32 i;

  if (p == NULL) {
    p = ThunderboltManager_Create();
    if (p == NULL) {
      return;
    }
  }
  for (i = 0; i < 4; i++) {
    if (ThunderboltManager_IsUsed(p, i)) {
      Thunderbolt* elem = &p->elems[i];

      if (elem->state != 5) {
        elem->state = 5;
        elem->stateBegun = TRUE;
      }
    }
  }
}

// 4 スロットが全て使用中なら TRUE, 管理エンティティを作れなかったときも TRUE
bool8 ThunderboltManager_IsFull(void) {
  ThunderboltManager* p = gThunderboltManager;
  s32 i;

  if (p == NULL) {
    p = ThunderboltManager_Create();
    if (p == NULL) {
      return TRUE;
    }
  }
  for (i = 0; i < 4; i++) {
    if (!ThunderboltManager_IsUsed(p, i)) {
      return FALSE;
    }
  }
  return TRUE;
}
