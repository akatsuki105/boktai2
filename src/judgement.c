#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"

struct JudgementParticle;
typedef void (*JudgementParticleFunc)(struct JudgementParticle* ptcl);
struct Judgement;
typedef void (*JudgementFunc)(struct Judgement* p);

// 演出で飛ばす粒子1個ぶんの枠, 8個を使い回す
typedef struct JudgementParticle {
  Particle ptcl;             // 0x00, _Destroy が Particle_Remove に渡す
  u16 timer;                 // 0x28, JudgementParticle_UpdateStill が毎フレーム +1, 7 を超えると枠を畳む
  u16 active;                // 0x2A, FUN_080a98c0 が 0 の枠を飛ばす
  s16 vx;                    // 0x2C, FUN_080a95d4 が毎フレーム pos.x に足す
  s16 vy;                    // 0x2E, 毎フレーム pos.y に足す, FUN_080a95d4 が重力として +1 する
  u16 unk_30;                // 0x30
  u8 unk_32[2];              // 0x32
  ParticleGroup* group;      // 0x34, FUN_0822dafc の第2引数
  JudgementParticleFunc fn;  // 0x38, FUN_080a98c0 が active な枠について呼ぶ
} JudgementParticle;
static_assert(sizeof(JudgementParticle) == 60);

// "審判のカード" (ITEM_JUDGEMENT, 全回復して復活) の 効果処理 及び 演出
typedef struct Judgement {
  Entity e;                      // 0x000, ENTITY_UNK_11
  Player* player;                // 0x018, _Init の第2引数
  MainSprite sprite;             // 0x01C, _Destroy が MainSprite_Remove に渡す
  u8 unk_7c[8];                  // 0x07C
  Vec3 screen;                   // 0x084, player->mover.pos の y に +0x96 した点を投影した画面座標
  JudgementParticle ptcls[8];    // 0x08C, 根拠: _Destroy の stride 0x3C × 8
  u8 unk_26c[4];                 // 0x26C
  u16 timer;                     // 0x270, _Init が 0, 各状態関数が +1 する
  u8 unk_272[2];                 // 0x272
  JudgementFunc updateCallback;  // 0x274, _Update が毎フレーム呼ぶ
} Judgement;
static_assert(sizeof(Judgement) == 632);

NAKED void FUN_080a95d4(Judgement* p) { INCFUNC("asm/func/FUN_080a95d4.inc"); }

NAKED void FUN_080a962c(Judgement* p) { INCFUNC("asm/func/FUN_080a962c.inc"); }

// 16フレームで畳む, その間は2コマのアニメを出しながら vy ぶん動かす
// 残差1命令: 原典は timer+1 を別レジスタに置いて使うたびに16bit化する, こちらは <<16 の中間値が残って else 側が1命令短くなる, Tier A/B と C のローカル分割・キャスト・アクセサ有無は試済
NON_MATCH void JudgementParticle_UpdateMoving(JudgementParticle* ptcl) {
#ifdef NONMATCHING_C
  ptcl->timer++;
  if (ptcl->timer > 15) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->active = 0;
  } else {
    FUN_0822dafc(&ptcl->ptcl, ptcl->group, ((ptcl->timer >> 2) & 1) + 2);
    ptcl->ptcl.pos.y += ptcl->vy;
  }
#else
  INCFUNC("asm/func/JudgementParticle_UpdateMoving.inc");
#endif
}

NAKED void FUN_080a975c(JudgementParticle* ptcl) { INCFUNC("asm/func/FUN_080a975c.inc"); }

// 8フレームで畳む, その間はその場で2コマのアニメを出す
// 残差1命令: 原典は timer+1 を別レジスタに残して使うたびに16bit化し直す, こちらは1回目の <<16 の中間値を else 側が使い回して1命令短くなる
// 試済: ptcl->timer++ とフィールド再読み / u16 ローカル / int ローカル + 各使用箇所で (u16) キャスト / 切り詰めた値を別ローカルに分離 / Particle_Hide 経由と直書き
// 試済 (Tier D, 診断): -fno-cse-follow-jumps / -fno-gcse / -fno-rerun-cse-after-loop / -fno-expensive-optimizations はいずれも無変化
// -O1 だと使用箇所ごとの切り詰めが出て命令数も26で一致する (残差は adds の形だけ) が、同じファイルの一致済み関数が壊れるのでファイル単位のフラグとしては採れない
NON_MATCH void JudgementParticle_UpdateStill(JudgementParticle* ptcl) {
#ifdef NONMATCHING_C
  int timer = ptcl->timer + 1;

  ptcl->timer = timer;
  if ((u16)timer > 7) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    ptcl->active = 0;
  } else {
    FUN_0822dafc(&ptcl->ptcl, ptcl->group, (((u16)timer >> 2) & 1) + 2);
  }
#else
  INCFUNC("asm/func/JudgementParticle_UpdateStill.inc");
#endif
}

NAKED void FUN_080a9840(JudgementParticle* ptcl) { INCFUNC("asm/func/FUN_080a9840.inc"); }

void FUN_080a98c0(Judgement* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->ptcls[i].active != 0) {
      p->ptcls[i].fn(&p->ptcls[i]);
    }
  }
}

NAKED void FUN_080a98f0(Judgement* p) { INCFUNC("asm/func/FUN_080a98f0.inc"); }

NAKED void FUN_080a9954(Judgement* p) { INCFUNC("asm/func/FUN_080a9954.inc"); }

NAKED void FUN_080a9ac8(Judgement* p) { INCFUNC("asm/func/FUN_080a9ac8.inc"); }

NAKED void FUN_080a9b84(Judgement* p) { INCFUNC("asm/func/FUN_080a9b84.inc"); }

s32 Judgement_Update(Judgement* p) {
  FUN_080a98c0(p);
  p->updateCallback(p);
  return 0;
}

s32 Judgement_Destroy(Judgement* p) {
  s32 i;

  MainSprite_Remove(&p->sprite);
  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
  return 0;
}

NAKED void FUN_080a9ccc(Judgement* p) { INCFUNC("asm/func/FUN_080a9ccc.inc"); }

NAKED void FUN_080a9d30(Judgement* p) { INCFUNC("asm/func/FUN_080a9d30.inc"); }

NAKED s32 Judgement_Init(Judgement* p, Player* player) { INCFUNC("asm/func/Judgement_Init.inc"); }

Judgement* Judgement_Create(Player* player) {
  Judgement* p = CreateEntity(ENTITY_UNK_11, sizeof(Judgement));

  if (p != NULL) {
    SetEntityRoutine(p, Judgement_Update, Judgement_Destroy);
    if (Judgement_Init(p, player) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
