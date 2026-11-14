#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "spirit_bugs.h"
#include "sprite.h"
#include "sprite_animation.h"
#include "vm.h"

// 太陽タケノコ1つ
typedef struct {
  u16 id;              // 0x00, '.n'
  u8 state;            // 0x02, PTR_ARRAY_085aa6b8[visible * 3 + state] で状態関数を選ぶ
  u8 kind;             // 0x03, 精霊虫の種類, see SpiritBugKind
  u8 count;            // 0x04, この太陽タケノコから出す精霊虫の数
  bool8 active;        // 0x05, 0 の枠を FUN_08009b10 が空きとして返す
  u8 unk_06;           // 0x06, FUN_08009e54 がアニメが一巡したら 1 にする
  bool8 stateEntered;  // 0x07, state を変えたときに立ち, 状態関数が最初のフレームで落とす
  bool8 unk_08;        // 0x08, FUN_08009c44 / FUN_08009e54 がアニメが一巡したフレームだけ TRUE にする
  u8 unk_09;           // 0x09, まだ未解析, padding?
  u16 timer;           // 0x0A, state を変えるたびに 0 に戻る, FUN_08009e28 が毎フレーム +1 して 30 を超えたら state 2 へ
  u16 unk_0c;          // 0x0C, timer がこれを超えたら粒子を出し直す, 120..247 の乱数
  u16 amount;          // 0x0E, この太陽タケノコから出す精霊虫の効果量
  u16 lifetime;        // 0x10, SpawnSpiritBugs の lifetime
  u16 lifetimeRand;    // 0x12, SpawnSpiritBugs の lifetimeRand
  HitboxData hurtbox;  // 0x14
  Particle ptcl;       // 0x64
  AuxAnimState anim;   // 0x8C
} BambooShoot;
static_assert(sizeof(BambooShoot) == 156);

// 太陽タケノコ (設定的には 太陽ダケの子だが、処理的にはあまり関係ない) の管理構造体
// 最初は隠れていて、プレイヤーが攻撃すると結晶が出現して、そこから 精霊虫 が出現する
typedef struct {
  Entity e;                // 0x0, ENTITY_UNK_10
  bool8 visible;           // 0x18, 本来、太陽タケノコは攻撃されるまで見えないが、いくつかの条件下(e.g. 千里眼の実の効果中)では最初から見える
  u8 unk_19[3];            // padding?
  ParticleGroup* group0;   // 0x1C, PTCL_GROUP_0
  ParticleGroup* group1;   // 0x20, PTCL_GROUP_1
  AuxAnimFile* anim_24;    // 0x24, ANIM_D1B8
  AuxAnimFile* anim_28;    // 0x28, ANIM_D41F
  BambooShoot shoots[16];  // 0x2C
} BambooShootManager;
static_assert(sizeof(BambooShootManager) == 2540);

static BambooShootManager* sBambooShootManager;  // 0x03000040

extern s32 gLightningTimer;

// state を切り替えて timer を 0 に戻す
static inline void BambooShoot_SetState(BambooShoot* shoot, u8 state) {
  shoot->state = state;
  shoot->timer = 0;
  shoot->stateEntered = TRUE;
}

void FUN_08009b04(void) { sBambooShootManager = NULL; }

// 空いている枠を返す, 無ければ NULL
BambooShoot* FUN_08009b10(BambooShootManager* p) {
  BambooShoot* e;
  s32 i;

  for (i = 0, e = p->shoots; i < 16; i++) {
    if (e->active == 0) {
      return e;
    }

    e++;
  }

  return NULL;
}

void BambooShoot_OnHurt(HitboxData* a, HitboxData* b, BambooShoot* shoot) {
  if (!Hitbox_TestAttr(a, HBATTR_SEKIKA) && !Hitbox_HasWeakness(a, 0x40 | 0x80 | 0x100)) {
    b->hitResult = HBRESULT_NORMAL;
    shoot->state = 1;
    shoot->timer = 0;
    shoot->stateEntered = TRUE;
    shoot->hurtbox.flags |= HBFLAG_HIDDEN;
  }
}

s32 BambooShoot_Init(BambooShootManager* p, BambooShoot* shoot) {
  Vec3 size, offset;

  VEC3_SET(size, Q8(0.12), Q8(1.25), Q8(0.12));
  VEC3_SET(offset, 0, Q8(0.625), 0);
  Hitbox_Init(&shoot->hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_5, 0, HIM_4, &size, &offset);
  Hitbox_SetHandler(&shoot->hurtbox, BambooShoot_OnHurt, shoot);
  Hitbox_Register(&shoot->hurtbox);
  Particle_Add(&shoot->ptcl, p->group0, SPRFLAG_HIDDEN);
  Particle_SetPose(&shoot->ptcl, p->group0, 12);
  Particle_SetOffset(&shoot->ptcl, -8, -8);
  shoot->active = TRUE;
}

s32 FUN_08009c08(BambooShootManager* p, BambooShoot* shoot) {
  Particle_Remove(&shoot->ptcl);
  Hitbox_Unregister(&shoot->hurtbox);
  shoot->active = FALSE;
  return 0;
}

void FUN_08009c28(BambooShootManager* p, BambooShoot* shoot) {
  if (shoot->stateEntered) {
    shoot->stateEntered = FALSE;
    shoot->ptcl.flags |= SPRFLAG_HIDDEN;
  }
}

// 隠れている間は unk_0c フレーム待って粒子を出し直し, 見えている間はアニメを進めて一巡したら隠す
// 残差は r1/r2 の入れ替わり3か所のみ (227/227), 手動送りは Particle_AdvanceAnim で一致
// 出し直しの inline 化, 比較の向き, 120 + 乱数の順, ptcl のローカル化は試済
NON_MATCH void FUN_08009c44(BambooShootManager* p, BambooShoot* shoot) {
#ifdef NONMATCHING_C
  if (shoot->stateEntered) {
    shoot->stateEntered = FALSE;
    Particle_SetOffset(&shoot->ptcl, -4, -4);
    Particle_SetPose(&shoot->ptcl, p->group1, 0);
    AuxAnim_SetAnim(&shoot->anim, p->anim_28, 8, 0, 0);
    shoot->ptcl.flags &= ~SPRFLAG_HIDDEN;
    shoot->unk_0c = (Random() & 0x7F) + 120;
  }
  if (shoot->ptcl.flags & SPRFLAG_HIDDEN) {
    if (shoot->timer++ > shoot->unk_0c) {
      shoot->timer = 0;
      shoot->unk_0c = (Random() & 0x7F) + 120;
      Particle_SetOffset(&shoot->ptcl, -4, -4);
      Particle_SetPose(&shoot->ptcl, p->group1, 0);
      AuxAnim_SetAnim(&shoot->anim, p->anim_28, 8, 0, 0);
      shoot->ptcl.flags &= ~SPRFLAG_HIDDEN;
    }
  } else {
    shoot->unk_08 = Particle_AdvanceAnim(&shoot->ptcl, p->group1, &shoot->anim);
    if (shoot->unk_08) {
      shoot->ptcl.flags |= SPRFLAG_HIDDEN;
    }
  }
#else
  INCFUNC("asm/func/FUN_08009c44.inc");
#endif
}

// 残差は定数 0 と 2 のレジスタが入れ替わるのみ (命令列は 22 対 22 で一致)
NON_MATCH void FUN_08009e28(BambooShootManager* p, BambooShoot* shoot) {
#ifdef NONMATCHING_C
  if (shoot->stateEntered) {
    shoot->stateEntered = FALSE;
  }

  if (shoot->timer++ > 30) {
    shoot->state = 2;
    shoot->timer = 0;
    shoot->stateEntered = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_08009e28.inc");
#endif
}

// 出現時に粒子とアニメを用意し, コマに合わせて上下させつつ4コマ目で太陽虫を撒き, アニメが一巡したら隠す
void FUN_08009e54(BambooShootManager* p, BambooShoot* shoot) {
  if (shoot->stateEntered) {
    shoot->stateEntered = FALSE;
    shoot->ptcl.flags &= ~SPRFLAG_HIDDEN;
    Particle_SetOffset(&shoot->ptcl, -8, -8);
    Particle_SetPose(&shoot->ptcl, p->group0, 0);
    AuxAnim_SetAnim(&shoot->anim, p->anim_24, 0, 0, 0);
    PlaySound_0824078c(SE_BAMBOO_SHOOT);
  }
  if (shoot->anim.cmdIdx == 1 && shoot->anim.tick == 0) {
    shoot->ptcl.pos.y += 16;
  }
  if (shoot->anim.cmdIdx == 2 && shoot->anim.tick == 0) {
    shoot->ptcl.pos.y -= 16;
  }
  if (shoot->anim.cmdIdx == 4 && shoot->anim.tick == 0) {
    Vec3 spread;

    VEC3_SET(spread, 10, 10, 10);
    SpawnSpiritBugs(shoot->count, shoot->kind | 0x10, shoot->amount, &shoot->ptcl.pos, &spread, shoot->lifetime, shoot->lifetimeRand);
    if (shoot->kind == DARKBUG) {
      PlaySound_0824078c(SE_POP_DARKBUGS);
    } else {
      PlaySound_0824078c(SE_POP_SPIRIT_BUGS);
    }
  }
  shoot->unk_08 = Particle_AdvanceAnim(&shoot->ptcl, p->group0, &shoot->anim);
  if (shoot->unk_08) {
    shoot->unk_06 = 1;
    shoot->ptcl.flags |= SPRFLAG_HIDDEN;
  }
}

static void (*const PTR_ARRAY_085aa6b8[2][3])(BambooShootManager*, BambooShoot*) = {
    {FUN_08009c28, FUN_08009e28, FUN_08009e54},
    {FUN_08009c44, FUN_08009e28, FUN_08009e54},
};  // 0x085AA6B8

// 見える状況 (夜, 千里眼の実, 雷の光, バット) が切り替わったら state 0 の太陽タケノコを入り直させ, 各枠の状態関数を回す
// 残差は見える判定の所だけ: 原典は千里眼の判定を 0/1 に起こし, プレイヤー NULL の FALSE を別ブロックに置いてから比べ直す (BambooShootManager_Init と同じ形), 述語を static inline にしても畳まれる
NON_MATCH s32 BambooShootManager_Update(BambooShootManager* p) {
#ifdef NONMATCHING_C
  bool8 visible = FALSE;
  bool32 revealed;
  s32 i;

  if (gClock.spanOfTime == TIME_NIGHT_DUSK || gClock.spanOfTime == TIME_NIGHT_MID || gClock.spanOfTime == TIME_NIGHT_DAWN) {
    revealed = TRUE;
  } else if (gGameFlags & GAMEFLAG_LINK) {
    revealed = gPlayerPtr[0] != NULL && gPlayerPtr[0]->goodCondTimer != 0 && gPlayerPtr[0]->goodCondID == GOOD_SEE;
  } else if (gLightningTimer > 0 || gStat->playerKind == PLAYER_BAT) {
    revealed = TRUE;
  } else {
    revealed = gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE;
  }

  if (revealed) {
    visible = TRUE;
    if (!p->visible) {
      for (i = 0; i < 16; i++) {
        if (p->shoots[i].state == 0) {
          BambooShoot_SetState(&p->shoots[i], 0);
        }
      }
    }
  } else if (p->visible == TRUE) {
    for (i = 0; i < 16; i++) {
      if (p->shoots[i].state == 0) {
        BambooShoot_SetState(&p->shoots[i], 0);
      }
    }
  }
  p->visible = visible;

  for (i = 0; i < 16; i++) {
    BambooShoot* e = &p->shoots[i];

    if (e->active) {
      if (e->unk_06) {
        FUN_08009c08(p, e);
      } else {
        e->unk_08 = FALSE;
        PTR_ARRAY_085aa6b8[visible][e->state](p, e);
      }
    }
  }

  return 0;
#else
  INCFUNC("asm/func/BambooShootManager_Update.inc");
#endif
}

s32 BambooShootManager_Destroy(BambooShootManager* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    BambooShoot* e = &p->shoots[i];

    if (e->active) {
      FUN_08009c08(p, e);
    }
  }

  sBambooShootManager = NULL;
  return 0;
}

// 76/87命令, 原典は千里眼の判定を 0/1 に落としてから見直す bool の形 (inline の述語の戻り値らしい), 直書きだと分岐が畳まれて短くなる
// 試済: 判定を static inline (HasGoodCond / GetPlayer / BambooShoot_CanSee) にすると 87/87 命令 9 hunk まで縮むが一致せず, NULL 判定の FALSE の置き場と最後の strb の形が残る
NON_MATCH s32 BambooShootManager_Init(BambooShootManager* p, u32 _) {
#ifdef NONMATCHING_C
  bool32 visible;

  sBambooShootManager = p;
  if (gClock.spanOfTime == TIME_NIGHT_DUSK || gClock.spanOfTime == TIME_NIGHT_MID || gClock.spanOfTime == TIME_NIGHT_DAWN) {
    visible = TRUE;
  } else if (gGameFlags & GAMEFLAG_LINK) {
    visible = gPlayerPtr[0] != NULL && gPlayerPtr[0]->goodCondTimer != 0 && gPlayerPtr[0]->goodCondID == GOOD_SEE;
  } else if (gLightningTimer > 0 || gStat->playerKind == PLAYER_BAT) {
    visible = TRUE;
  } else {
    visible = gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE;
  }
  p->visible = visible;
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  p->group1 = GetParticleGroup(PTCL_GROUP_1);
  p->anim_24 = GetFile(DIR_ANIMATION, ANIM_D1B8);
  p->anim_28 = GetFile(DIR_ANIMATION, ANIM_D41F);
  return 0;
#else
  INCFUNC("asm/func/BambooShootManager_Init.inc");
#endif
}

BambooShootManager* BambooShootManager_Create(u32 _, u32 unused) {
  BambooShootManager* p = CreateEntity(ENTITY_UNK_10, sizeof(BambooShootManager));
  if (p != NULL) {
    SetEntityRoutine(p, BambooShootManager_Update, BambooShootManager_Destroy);
    if (BambooShootManager_Init(p, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 0x0866, 空き枠に太陽タケノコを1つ置く, 管理エンティティが無ければ作る
s32 Cmd_0866(void) {
  BambooShootManager* p = sBambooShootManager;
  BambooShoot* shoot;
  WorldPos pos;

  if (p == NULL) {
    p = BambooShootManager_Create(0, 0);
    if (p == NULL) {
      return -1;
    }
  }
  shoot = FUN_08009b10(p);
  if (shoot == NULL) {
    return -1;
  }

  ClearMemory(shoot, sizeof(BambooShoot));
  shoot->id = VM_GetNamedArgValue('n', 0);
  shoot->kind = VM_GetNamedArgValue('t', 0);
  shoot->count = VM_GetNamedArgValue('b', 0);
  shoot->unk_08 = FALSE;
  BambooShoot_SetState(shoot, 0);
  shoot->unk_0c = 0;
  shoot->unk_06 = 0;
  BambooShoot_Init(p, shoot);
  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
  }
  Hitbox_SetPos(&shoot->hurtbox, &pos, 0);
  shoot->ptcl.pos = pos;
  shoot->ptcl.pos.y += 230;
  if (VM_SeekToNamedArg('s')) {
    shoot->amount = VM_GetValue();
    shoot->lifetime = VM_GetValue();
    shoot->lifetimeRand = VM_GetValue();
  } else {
    shoot->amount = 50;
    shoot->lifetime = 600;
    shoot->lifetimeRand = 100;
  }
  return 0;
}

// 0x78EE, 使用中の枠の数を数えてスクリプト変数へ書き出す (使われてなさそう)
u32 Cmd_78EE(void) {
  BambooShootManager* p = sBambooShootManager;
  u8 desc[8];
  s32 count = 0;

  if (p != NULL) {
    BambooShoot* e = p->shoots;
    s32 i;

    for (i = 0; i < 16; e++, i++) {
      if (e->active) {
        count++;
      }
    }
  }

  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, count);
  return count;
}

// 0xE0A5
void Cmd_E0A5(void) {
  BambooShootManager* p = sBambooShootManager;
  s32 i;

  if (p == NULL) return;

  for (i = 0; i < 16; i++) {
    BambooShoot* e = &p->shoots[i];

    if (e->active) {
      FUN_08009c08(p, e);
    }
  }
}
