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
  u8 unk_00[2];       // 0x00, まだ未解析
  u8 unk_02;          // 0x02, FUN_08009e28 が 2 を入れる
  u8 kind;            // 0x03, 精霊虫の種類, see SpiritBugKind
  u8 count;           // 0x04, この太陽タケノコから出す精霊虫の数
  bool8 active;       // 0x05, 0 の枠を FUN_08009b10 が空きとして返す
  u8 unk_06;          // 0x06, FUN_08009e54 がアニメが一巡したら 1 にする
  bool8 unk_07;       // 0x07, FUN_08009c28 が読んで落とす目印
  bool8 unk_08;       // 0x08, FUN_08009c44 / FUN_08009e54 がアニメが一巡したフレームだけ TRUE にする
  u8 unk_09;          // 0x09, まだ未解析, padding?
  u16 unk_0a;         // 0x0A, FUN_08009e28 が毎フレーム +1 して 30 を超えたら 0 に戻す
  u16 unk_0c;         // 0x0C, unk_0a がこれを超えたら粒子を出し直す, 120..247 の乱数
  u16 amount;         // 0x0E, この太陽タケノコから出す精霊虫の効果量
  u16 lifetime;       // 0x10, SpawnSpiritBugs の lifetime
  u16 lifetimeRand;   // 0x12, SpawnSpiritBugs の lifetimeRand
  HitboxData hitbox;  // 0x14
  Particle ptcl;      // 0x64
  AuxAnimState anim;  // 0x8C
} BambooShoot;
static_assert(sizeof(BambooShoot) == 156);

// 太陽タケノコ (設定的には 太陽ダケの子だが、処理的にはあまり関係ない) の管理構造体
// 最初は隠れていて、プレイヤーが攻撃すると結晶が出現して、そこから 精霊虫 が出現する
typedef struct {
  Entity e;                // 0x0, ENTITY_UNK_10
  bool8 revealed;          // 0x18, Init が夜, 雷の最中, バットに変身中, 千里眼の実の効果中なら TRUE にする
  u8 unk_19[3];            // padding?
  ParticleGroup* group0;   // 0x1C, PTCL_GROUP_0
  ParticleGroup* group1;   // 0x20, PTCL_GROUP_1
  AuxAnimFile* anim_24;    // 0x24
  AuxAnimFile* anim_28;    // 0x28
  BambooShoot shoots[16];  // 0x2C
} BambooShootManager;
static_assert(sizeof(BambooShootManager) == 2540);

static BambooShootManager* sBambooShootManager;  // 0x03000040

extern s32 gLightningTimer;

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

void FUN_08009b30(HitboxData* a, HitboxData* b, BambooShoot* elem) {
  if (!Hitbox_TestAttr(a, HBATTR_14) && !Hitbox_HasWeakness(a, HBATTR_ALL | HBATTR_BEAST | HBATTR_THING)) {
    b->hitResult = HBRESULT_NORMAL;
    elem->unk_02 = 1;
    elem->unk_0a = 0;
    elem->unk_07 = TRUE;
    elem->hitbox.flags |= HBFLAG_HIDDEN;
  }
}

NAKED s32 FUN_08009b6c(BambooShootManager* p, BambooShoot* param_2) { INCFUNC("asm/func/FUN_08009b6c.inc"); }

s32 FUN_08009c08(BambooShootManager* p, BambooShoot* e) {
  Particle_Remove(&e->ptcl);
  Hitbox_Unregister(&e->hitbox);
  e->active = FALSE;
  return 0;
}

void FUN_08009c28(BambooShootManager* p, BambooShoot* e) {
  if (e->unk_07) {
    e->unk_07 = FALSE;
    e->ptcl.flags |= SPRFLAG_HIDDEN;
  }
}

// 隠れている間は unk_0c フレーム待って粒子を出し直し, 見えている間はアニメを進めて一巡したら隠す
// 残差は r1/r2 の入れ替わり3か所のみ (227/227), 手動送りは Particle_AdvanceAnim で一致
// 出し直しの inline 化, 比較の向き, 120 + 乱数の順, ptcl のローカル化は試済
NON_MATCH void FUN_08009c44(BambooShootManager* p, BambooShoot* e) {
#ifdef NONMATCHING_C
  if (e->unk_07) {
    e->unk_07 = FALSE;
    Particle_SetOffset(&e->ptcl, -4, -4);
    Particle_SetPose(&e->ptcl, p->group1, 0);
    AuxAnim_SetAnim(&e->anim, p->anim_28, 8, 0, 0);
    e->ptcl.flags &= ~SPRFLAG_HIDDEN;
    e->unk_0c = (Random() & 0x7F) + 120;
  }
  if (e->ptcl.flags & SPRFLAG_HIDDEN) {
    if (e->unk_0a++ > e->unk_0c) {
      e->unk_0a = 0;
      e->unk_0c = (Random() & 0x7F) + 120;
      Particle_SetOffset(&e->ptcl, -4, -4);
      Particle_SetPose(&e->ptcl, p->group1, 0);
      AuxAnim_SetAnim(&e->anim, p->anim_28, 8, 0, 0);
      e->ptcl.flags &= ~SPRFLAG_HIDDEN;
    }
  } else {
    e->unk_08 = Particle_AdvanceAnim(&e->ptcl, p->group1, &e->anim);
    if (e->unk_08) {
      e->ptcl.flags |= SPRFLAG_HIDDEN;
    }
  }
#else
  INCFUNC("asm/func/FUN_08009c44.inc");
#endif
}

// 残差は定数 0 と 2 のレジスタが入れ替わるのみ (命令列は 22 対 22 で一致)
NON_MATCH void FUN_08009e28(BambooShootManager* p, BambooShoot* e) {
#ifdef NONMATCHING_C
  if (e->unk_07) {
    e->unk_07 = FALSE;
  }

  if (e->unk_0a++ > 30) {
    e->unk_02 = 2;
    e->unk_0a = 0;
    e->unk_07 = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_08009e28.inc");
#endif
}

// 出現時に粒子とアニメを用意し, コマに合わせて上下させつつ4コマ目で太陽虫を撒き, アニメが一巡したら隠す
void FUN_08009e54(BambooShootManager* p, BambooShoot* e) {
  if (e->unk_07) {
    e->unk_07 = FALSE;
    e->ptcl.flags &= ~SPRFLAG_HIDDEN;
    Particle_SetOffset(&e->ptcl, -8, -8);
    Particle_SetPose(&e->ptcl, p->group0, 0);
    AuxAnim_SetAnim(&e->anim, p->anim_24, 0, 0, 0);
    PlaySound_0824078c(SE_BAMBOO_SHOOT);
  }
  if (e->anim.cmdIdx == 1 && e->anim.tick == 0) {
    e->ptcl.pos.y += 16;
  }
  if (e->anim.cmdIdx == 2 && e->anim.tick == 0) {
    e->ptcl.pos.y -= 16;
  }
  if (e->anim.cmdIdx == 4 && e->anim.tick == 0) {
    Vec3 spread;

    VEC3_SET(spread, 10, 10, 10);
    SpawnSpiritBugs(e->count, e->kind | 0x10, e->amount, &e->ptcl.pos, &spread, e->lifetime, e->lifetimeRand);
    if (e->kind == DARKBUG) {
      PlaySound_0824078c(SE_POP_DARKBUGS);
    } else {
      PlaySound_0824078c(SE_POP_SPIRIT_BUGS);
    }
  }
  e->unk_08 = Particle_AdvanceAnim(&e->ptcl, p->group0, &e->anim);
  if (e->unk_08) {
    e->unk_06 = 1;
    e->ptcl.flags |= SPRFLAG_HIDDEN;
  }
}

static void (*const PTR_ARRAY_085aa6b8[6])(BambooShootManager*, BambooShoot*) = {
    FUN_08009c28,
    FUN_08009e28,
    FUN_08009e54,
    FUN_08009c44,
    FUN_08009e28,
    FUN_08009e54,
};  // 0x085AA6B8

NAKED s32 BambooShootManager_Update(BambooShootManager* p) { INCFUNC("asm/func/BambooShootManager_Update.inc"); }

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
  bool32 revealed;

  sBambooShootManager = p;
  if (gClock.spanOfTime == TIME_UNK4 || gClock.spanOfTime == TIME_UNK5 || gClock.spanOfTime == TIME_NIGHT) {
    revealed = TRUE;
  } else if (gGameFlags & FLAG030047A4_LINK) {
    revealed = gPlayerPtr[0] != NULL && gPlayerPtr[0]->goodCondTimer != 0 && gPlayerPtr[0]->goodCondID == GOOD_SEE;
  } else if (gLightningTimer > 0 || gStat->playerKind == PLAYER_BAT) {
    revealed = TRUE;
  } else {
    revealed = gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE;
  }
  p->revealed = revealed;
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

// 0x0866
NAKED s32 Cmd_0866(void) { INCFUNC("asm/func/Cmd_0866.inc"); }

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
