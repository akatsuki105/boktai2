#include "eff_elemcond.h"

#include "camera.h"
#include "camera_inline.h"
#include "eff_scatter.h"
#include "entity.h"
#include "file.h"
#include "global.h"

// エレメント系の状態異常 (引火, 氷結, 石化) にかかったキャラにまとわりつく粒子のエフェクト

typedef struct ElementalCondEffect {
  Entity e;                        // 0x00
  ParticleGroup* group0;           // 0x18, PTCL_GROUP_0
  AuxAnimFile* anim;               // 0x1C, ANIM_D1B8
  ElementalCondEmitter* emitters;  // 0x20, 登録されているエミッタの双方向リストの先頭
} ElementalCondEffect;
static_assert(sizeof(ElementalCondEffect) == 36);

static ElementalCondEffect* sElementalCondEffect;  // 0x030026B0

const u16 sElementalCondAnimIdxs[4] = {3, 3, 1, 2};  // 0x08DBD810

void ElementalCondEmitter_UpdateBurning(ElementalCondEffect* p, ElementalCondEmitter* e);
void ElementalCondEmitter_UpdateFrozen(ElementalCondEffect* p, ElementalCondEmitter* e);
void ElementalCondEmitter_UpdatePetrified(ElementalCondEffect* p, ElementalCondEmitter* e);

void ElementalCondEffect_ClearGlobal(void) { sElementalCondEffect = NULL; }

// kind 0 の更新, 何もしない
void ElementalCondEmitter_UpdateIdle(ElementalCondEffect* p, ElementalCondEmitter* e) {}

// エミッタをリストの先頭に繋ぐ, 既に繋がっていれば -1
s32 ElementalCondEmitter_Register(ElementalCondEffect* p, ElementalCondEmitter* e) {
  if (e->isRegistered) return -1;
  e->prev = NULL;
  e->next = p->emitters;
  if (e->next != NULL) {
    e->next->prev = e;
  }
  p->emitters = e;
  e->isRegistered = TRUE;
  return 0;
}

// エミッタをリストから外す, 繋がっていなければ -1
s32 ElementalCondEmitter_Unregister(ElementalCondEffect* p, ElementalCondEmitter* e) {
  ElementalCondEmitter* prev = e->prev;
  ElementalCondEmitter* next = e->next;

  if (!e->isRegistered) return -1;
  if (prev != NULL) {
    prev->next = next;
  } else {
    p->emitters = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  e->isRegistered = FALSE;
  return 0;
}

// 生きている枠をひとつだけ消えかけ (state 2) にする
s32 ElementalCondEmitter_FadeParticle(ElementalCondEmitter* e) {
  bool32 found = FALSE;
  s32 i;

  for (i = 0; i < 4; i++) {
    ElementalCondParticle* ptcl = &e->ptcls[i];
    if (ptcl->state == 1) {
      ptcl->state = 2;
      ptcl->blinkInterval = 10;
      ptcl->timer = 0;
      found = TRUE;
      break;
    }
  }
  if (found) {
    e->aliveCount--;
  }
  return 0;
}

// 生きている枠をひとつ解放して、その場に粒子を撒き散らす
s32 ElementalCondEmitter_BurstParticle(ElementalCondEmitter* e, s32 count, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask) {
  bool32 found = FALSE;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (e->ptcls[i].state == 1) {
      Particle_Hide(&e->ptcls[i].ptcl);
      e->ptcls[i].state = 0;
      e->ptcls[i].blinkInterval = 10;
      e->ptcls[i].timer = 0;
      found = TRUE;
      ScatterEffect_Spawn(count, e->kind, pos, vel, velRange, lifeBase, lifeRandMask);
      break;
    }
  }
  if (found) {
    e->aliveCount--;
    e->activeCount--;
  }
  return 0;
}

// エミッタを待機状態に戻す, 枠は全部空きにして粒子も隠す
missing ElementalCondEmitter_Reset(ElementalCondEmitter* e) {
  s32 i;

  e->activeCount = 0;
  e->aliveCount = 0;
  e->kind = ELEMCOND_NONE;
  e->update = ElementalCondEmitter_UpdateIdle;
  for (i = 0; i < 4; i++) {
    e->ptcls[i].state = 0;
    e->ptcls[i].timer = 0;
    e->ptcls[i].blinkInterval = 10;
    Particle_Hide(&e->ptcls[i].ptcl);
  }
}

// 空いている枠に粒子をひとつ出す, kind が変わったら更新関数を差し替え, kind 0 なら全部消す
s32 ElementalCondEmitter_AddParticle(ElementalCondEmitter* e, u32 kind, u32 param_3, Vec3* spread) {
  ElementalCondEffect* p = sElementalCondEffect;
  bool32 added;
  Vec3 screen;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  if (kind == ELEMCOND_NONE) {
    ElementalCondEmitter_Reset(e);
    return 0;
  }
  if ((e->activeCount != 0 && e->kind != kind) || e->activeCount > 3) {
    return -1;
  }
  if (e->kind != kind) {
    e->kind = kind;
    switch (e->kind) {
      case ELEMCOND_NONE: {
        e->update = ElementalCondEmitter_UpdateIdle;
        break;
      }
      case ELEMCOND_INKA: {
        e->update = ElementalCondEmitter_UpdateBurning;
        break;
      }
      case ELEMCOND_HYOKETU: {
        e->update = ElementalCondEmitter_UpdateFrozen;
        break;
      }
      case ELEMCOND_SEKIKA: {
        e->update = ElementalCondEmitter_UpdatePetrified;
        break;
      }
    }
  }

  added = FALSE;
  WorldToScreen(&screen, e->pos);
  for (i = 0; i < 4; i++) {
    ElementalCondParticle* ptcl = &e->ptcls[i];

    if (ptcl->state == 0) {
      ptcl->state = 1;
      ptcl->timer = 0;
      ptcl->lifetime = param_3;
      ptcl->pos = *spread;
      ptcl->ptcl.pos.x = screen.x + ptcl->pos.x;
      ptcl->ptcl.pos.y = screen.y + ptcl->pos.y;
      ptcl->ptcl.pos.z = screen.z + ptcl->pos.z;
      ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
      AuxAnim_SetAnim(&ptcl->anim, p->anim, sElementalCondAnimIdxs[e->kind], 0, 0);
      added = TRUE;
      break;
    }
  }
  if (e->kind == ELEMCOND_HYOKETU) {
    for (i = 0; i < 4; i++) {
      Particle_SetFlags(&e->ptcls[i].ptcl, SPRFLAG_BLINK_ODD);
    }
  } else {
    for (i = 0; i < 4; i++) {
      Particle_ClearFlags(&e->ptcls[i].ptcl, SPRFLAG_BLINK_ODD);
    }
  }
  if (added) {
    e->activeCount++;
    e->aliveCount++;
  }
  return 0;
}

// 枠を空きに戻して粒子を隠す
void ElementalCondParticle_Clear(ElementalCondParticle* ptcl) {
  ptcl->state = 0;
  ptcl->timer = 0;
  ptcl->blinkInterval = 10;
  ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
}

void ElementalCondParticle_BurningEmpty(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {}

// 引火 (kind 1) の生存中の枠, アニメを進めて5コマ目で頭に戻しつつ lifetime を数え下げ, 0 になったら消えかけに移す
void ElementalCondParticle_BurningAlive(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {
  Particle_AdvanceAnim(&ptcl->ptcl, p->group0, &ptcl->anim);
  if (ptcl->anim.cmdIdx == 5) {
    ptcl->anim.cmdIdx = 0;
  }
  if (ptcl->lifetime > 0) {
    if (--ptcl->lifetime == 0) {
      ptcl->state = 2;
      ptcl->blinkInterval = 10;
      ptcl->timer = 0;
      e->aliveCount--;
    }
  }
}

// 引火 (kind 1) の消えかけの枠, アニメを1コマ進め, 一巡したら枠を空ける
void ElementalCondParticle_BurningFading(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {
  if (Particle_AdvanceAnim(&ptcl->ptcl, p->group0, &ptcl->anim)) {
    ElementalCondParticle_Clear(ptcl);
    e->activeCount--;
  }
}

void ElementalCondParticle_FrozenEmpty(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {}

// 氷結 (kind 2) の生存中の枠, アニメを進めつつ lifetime を数え下げ, 0 になったら消えかけに移す
void ElementalCondParticle_FrozenAlive(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {
  Particle_AdvanceAnim(&ptcl->ptcl, p->group0, &ptcl->anim);
  if (ptcl->lifetime > 0) {
    if (--ptcl->lifetime == 0) {
      ptcl->state = 2;
      ptcl->blinkInterval = 10;
      ptcl->timer = 0;
      e->aliveCount--;
    }
  }
}

// 氷結 (kind 2) の消えかけの枠, アニメを進めながら blinkInterval フレームごとに点滅させ, 間隔が詰まり切ったら枠を空ける
void ElementalCondParticle_FrozenFading(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {
  Particle_AdvanceAnim(&ptcl->ptcl, p->group0, &ptcl->anim);
  if (ptcl->timer == ptcl->blinkInterval) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    if (ptcl->blinkInterval != 0) {
      ptcl->blinkInterval--;
    }
    ptcl->timer = 0;
  } else {
    ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  }
  if (ptcl->blinkInterval == 0) {
    ElementalCondParticle_Clear(ptcl);
    e->activeCount--;
  }
}

void ElementalCondParticle_PetrifiedEmpty(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {}

// 石化 (kind 3) の生存中の枠, ElementalCondParticle_FrozenAlive と同じ処理
void ElementalCondParticle_PetrifiedAlive(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {
  Particle_AdvanceAnim(&ptcl->ptcl, p->group0, &ptcl->anim);
  if (ptcl->lifetime > 0) {
    if (--ptcl->lifetime == 0) {
      ptcl->state = 2;
      ptcl->blinkInterval = 10;
      ptcl->timer = 0;
      e->aliveCount--;
    }
  }
}

// 石化 (kind 3) の消えかけの枠, ElementalCondParticle_FrozenFading と同じ処理
void ElementalCondParticle_PetrifiedFading(ElementalCondEffect* p, ElementalCondEmitter* e, ElementalCondParticle* ptcl) {
  Particle_AdvanceAnim(&ptcl->ptcl, p->group0, &ptcl->anim);
  if (ptcl->timer == ptcl->blinkInterval) {
    ptcl->ptcl.flags |= SPRFLAG_HIDDEN;
    if (ptcl->blinkInterval != 0) {
      ptcl->blinkInterval--;
    }
    ptcl->timer = 0;
  } else {
    ptcl->ptcl.flags &= ~SPRFLAG_HIDDEN;
  }
  if (ptcl->blinkInterval == 0) {
    ElementalCondParticle_Clear(ptcl);
    e->activeCount--;
  }
}

void (*const sBurningParticleUpdates[3])(ElementalCondEffect*, ElementalCondEmitter*, ElementalCondParticle*) = {
    ElementalCondParticle_BurningEmpty,
    ElementalCondParticle_BurningAlive,
    ElementalCondParticle_BurningFading,
};  // 0x08DBD818

// 引火 (kind 1) の更新, エミッタの座標を画面座標に落として、生きている枠の粒子をそこにぶら下げる
// 残差2箇所 (113/113 命令): 投影は WorldToScreen で一致, 原典は q = e->ptcls をループ表のアドレスと &screen の後で作り, ループ末尾で q の加算をカウンタの減算より先に置く
// Tier A-C は試済 (for の初期化と更新の順, q をループ前の文に出す, 本体を q-> 経由にする, q の加算を本体の末尾に置く, 呼び出しだけ &e->ptcls[i] にする, 全部を添字にすると誘導変数が1本になる)
NON_MATCH void ElementalCondEmitter_UpdateBurning(ElementalCondEffect* p, ElementalCondEmitter* e) {
#ifdef NONMATCHING_C
  ElementalCondParticle* q;
  Vec3 screen;
  s32 i;

  WorldToScreen(&screen, e->pos);
  for (i = 0, q = e->ptcls; i < 4; i++, q++) {
    sBurningParticleUpdates[e->ptcls[i].state](p, e, q);
    if (e->ptcls[i].state != 0) {
      e->ptcls[i].ptcl.pos.x = screen.x + e->ptcls[i].pos.x;
      e->ptcls[i].ptcl.pos.y = screen.y + e->ptcls[i].pos.y;
      e->ptcls[i].ptcl.pos.z = screen.z + e->ptcls[i].pos.z;
      e->ptcls[i].timer++;
    }
  }
#else
  INCFUNC("asm/func/ElementalCondEmitter_UpdateBurning.inc");
#endif
}

void (*const sFrozenParticleUpdates[3])(ElementalCondEffect*, ElementalCondEmitter*, ElementalCondParticle*) = {
    ElementalCondParticle_FrozenEmpty,
    ElementalCondParticle_FrozenAlive,
    ElementalCondParticle_FrozenFading,
};  // 0x08DBD824

// 氷結 (kind 2) の更新, ElementalCondEmitter_UpdateBurning と同じ処理を sFrozenParticleUpdates の更新関数で回す
// 残差2箇所 (113/113 命令): 原典は &screen のアドレスを q より先に作り, ループ末尾で r4 (枠の添字側) の加算を q より先に置く
// 試済: 表を引数で受ける共通 inline (表の読み込みが関数の頭へ出る), 表を [3][3] にして kind で引く (+0xC が実行時の加算になる), Vec3_Sum, for の初期化と更新の順
NON_MATCH void ElementalCondEmitter_UpdateFrozen(ElementalCondEffect* p, ElementalCondEmitter* e) {
#ifdef NONMATCHING_C
  void (*const* funcs)(ElementalCondEffect*, ElementalCondEmitter*, ElementalCondParticle*);
  ElementalCondParticle* q;
  Vec3 screen;
  s32 i;

  WorldToScreen(&screen, e->pos);
  funcs = sFrozenParticleUpdates;
  for (i = 0, q = e->ptcls; i < 4; i++, q++) {
    funcs[e->ptcls[i].state](p, e, q);
    if (e->ptcls[i].state != 0) {
      e->ptcls[i].ptcl.pos.x = screen.x + e->ptcls[i].pos.x;
      e->ptcls[i].ptcl.pos.y = screen.y + e->ptcls[i].pos.y;
      e->ptcls[i].ptcl.pos.z = screen.z + e->ptcls[i].pos.z;
      e->ptcls[i].timer++;
    }
  }
#else
  INCFUNC("asm/func/ElementalCondEmitter_UpdateFrozen.inc");
#endif
}

void (*const sPetrifiedParticleUpdates[3])(ElementalCondEffect*, ElementalCondEmitter*, ElementalCondParticle*) = {
    ElementalCondParticle_PetrifiedEmpty,
    ElementalCondParticle_PetrifiedAlive,
    ElementalCondParticle_PetrifiedFading,
};  // 0x08DBD830

// 石化 (kind 3) の更新, ElementalCondEmitter_UpdateBurning と同じ処理を sPetrifiedParticleUpdates の更新関数で回す
// 残差は ElementalCondEmitter_UpdateFrozen と同じ 2 箇所 (113/113 命令), 試した形も同じ
NON_MATCH void ElementalCondEmitter_UpdatePetrified(ElementalCondEffect* p, ElementalCondEmitter* e) {
#ifdef NONMATCHING_C
  void (*const* funcs)(ElementalCondEffect*, ElementalCondEmitter*, ElementalCondParticle*);
  ElementalCondParticle* q;
  Vec3 screen;
  s32 i;

  WorldToScreen(&screen, e->pos);
  funcs = sPetrifiedParticleUpdates;
  for (i = 0, q = e->ptcls; i < 4; i++, q++) {
    funcs[e->ptcls[i].state](p, e, q);
    if (e->ptcls[i].state != 0) {
      e->ptcls[i].ptcl.pos.x = screen.x + e->ptcls[i].pos.x;
      e->ptcls[i].ptcl.pos.y = screen.y + e->ptcls[i].pos.y;
      e->ptcls[i].ptcl.pos.z = screen.z + e->ptcls[i].pos.z;
      e->ptcls[i].timer++;
    }
  }
#else
  INCFUNC("asm/func/ElementalCondEmitter_UpdatePetrified.inc");
#endif
}

s32 ElementalCondEffect_Update(ElementalCondEffect* p) {
  ElementalCondEmitter* e = p->emitters;

  while (e != NULL) {
    e->update(p, e);
    e = e->next;
  }
  return 0;
}

s32 ElementalCondEffect_Destroy(ElementalCondEffect* _) {
  sElementalCondEffect = NULL;
  return 0;
}

s32 ElementalCondEffect_Init(ElementalCondEffect* p, u32 _) {
  sElementalCondEffect = p;
  p->emitters = NULL;
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);
  return 0;
}

ElementalCondEffect* ElementalCondEffect_Create(u32 unused1, u32 unused2) {
  if (sElementalCondEffect == NULL) {
    ElementalCondEffect* p = CreateEntity(ENTITY_UNK_9, sizeof(ElementalCondEffect));
    if (p != NULL) {
      SetEntityRoutine(p, ElementalCondEffect_Update, ElementalCondEffect_Destroy);
      if (ElementalCondEffect_Init(p, unused1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return sElementalCondEffect;
}

// エミッタを初期化して ElementalCondEffect に登録する, エンティティがまだ無ければ先に作る
s32 ElementalCondEmitter_Init(ElementalCondEmitter* e, Vec3* pos, s32 kind, s32 unk_4, s32 unk_5) {
  ElementalCondEffect* p = sElementalCondEffect;
  s32 i;

  if (p == NULL) {
    p = ElementalCondEffect_Create(0, 0);
    if (p == NULL) {
      return -1;
    }
  }
  e->isRegistered = 0;
  e->pos = pos;
  e->activeCount = 0;
  e->aliveCount = 0;
  e->kind = kind;
  e->unk_4 = unk_4;
  e->unk_5 = unk_5;
  e->update = ElementalCondEmitter_UpdateIdle;
  for (i = 0; i < 4; i++) {
    e->ptcls[i].state = 0;
    e->ptcls[i].timer = 0;
    VEC3_SET(e->ptcls[i].pos, 0, 0, 0);
    Particle_Add(&e->ptcls[i].ptcl, sElementalCondEffect->group0, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD);
    Particle_SetOffset(&e->ptcls[i].ptcl, -8, -8);
    e->ptcls[i].ptcl.priority = 2;
    AuxAnim_SetAnim(&e->ptcls[i].anim, sElementalCondEffect->anim, 0, 0, 0);
  }
  ElementalCondEmitter_Register(p, e);
  return 0;
}

// エミッタの後始末, 粒子を消してリストから外す
s32 ElementalCondEmitter_Destroy(ElementalCondEmitter* e) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&e->ptcls[i].ptcl);
  }
  if (sElementalCondEffect != NULL) {
    ElementalCondEmitter_Unregister(sElementalCondEffect, e);
  }
  return 0;
}
