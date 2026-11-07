#include "cwolf_target.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// バンデット(ENEID_BANDIT), ヘルハウンド(ENEID_HELLHOUND), グレイブキーパー(ENEID_GRAVEKEEPER)
// 共通の特徴として におい でサーチする (処理の上でどうしているのかはまだ不明)
// バンデットは攻撃時にプレイヤーからアイテムを奪う, ヘルハウンドはファイヤーブレスを吐く
typedef struct {
  Enemy e;
  u8 unk_654[4];              // 0x654
  HitboxData unk_658;         // 0x658, 2つ目の攻撃判定, atkPower[1] などの攻撃値を載せる
  u8 unk_6a8[0x6C6 - 0x6A8];  // 0x6A8
  u16 unk_6c6;                // 0x6C6, 0 になるまで毎フレーム減る
  u16 unk_6c8;                // 0x6C8, 0 になるまで毎フレーム減る
  u16 unk_6ca;                // 0x6CA, 0 になるまで毎フレーム減る
  u8 unk_6cc[0x6D0 - 0x6CC];  // 0x6CC
  s16 unk_6d0;                // 0x6D0, 負なら unk_6d2/unk_6d4 は無効
  s16 unk_6d2;                // 0x6D2
  s16 unk_6d4;                // 0x6D4
  u8 unk_6d6[0x6D8 - 0x6D6];  // 0x6D6
  u8 unk_6d8;                 // 0x6D8, 0 になるまで毎フレーム減る
  u8 unk_6d9[0x708 - 0x6D9];  // 0x6D9
  Vec3 unk_708;               // 0x708, 飛びかかる直前のプレイヤーの位置
} Dog;
static_assert(sizeof(Dog) == 1808);

const u16 u16_ARRAY_085ad8c0[16] = {450, 480, 480, 540, 450, 459, 459, 540, 800, 1280, 560, 360, 300, 306, 306, 360};  // 0x085AD8C0

struct Entity081f1770Elem* Entity081f1770_Spawn(Vec3* pos, u32 angle, SpriteFlags flags);
void FUN_0814ca30(Dog* p, s32 timer);
void FUN_0814df40(Dog* p);
void Dog_OnHit(HitboxData* a, HitboxData* b, Dog* p);
void FUN_0814b89c(HitboxData* a, HitboxData* b, Dog* p);
void Dog_OnHurt(HitboxData* a, HitboxData* b, Dog* p);
void FUN_0814fba4(Dog*);
void FUN_0814fc7c(Dog*);
void FUN_08150534(Dog*);
void FUN_08150660(Dog*);
void FUN_08150790(Dog*);
void FUN_08150b18(Dog*);
void FUN_08150de8(Dog*);
void FUN_081514f0(Dog*);
void FUN_081516d8(Dog*);
void FUN_081517a8(Dog*);

void (*const PTR_ARRAY_085ad8e0[2])(Dog*) = {
    FUN_0814fba4,
    FUN_0814fc7c,
};  // 0x085AD8E0

void (*const PTR_ARRAY_085ad8e8[2])(Dog*) = {
    FUN_08150534,
    FUN_08150660,
};  // 0x085AD8E8

// clang-format off
void (*const PTR_ARRAY_085ad8f0[20])(Dog*) = {
    (void*)FUN_080f2644,
    (void*)FUN_080f2864,
    (void*)FUN_080f248c,
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
    FUN_08150de8,
    FUN_08150790,
    FUN_08150b18,
    FUN_081514f0,
    FUN_081516d8,
    FUN_081517a8,
};  // 0x085AD8F0
// clang-format on

NAKED void enemy_dog_08149f6c(Dog* p) { INCFUNC("asm/func/enemy_dog_08149f6c.inc"); }

NAKED void FUN_0814a098(Dog* p) { INCFUNC("asm/func/FUN_0814a098.inc"); }

NAKED void enemy_dog_0814a320(Dog* p) { INCFUNC("asm/func/enemy_dog_0814a320.inc"); }

NAKED bool8 FUN_0814a5e0(Dog* p, u32 angle) { INCFUNC("asm/func/FUN_0814a5e0.inc"); }

void Dog_InitAnims(Dog* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 14, 1, 0);
  Enemy_SetAnimEntry(&p->e, 11, 2, 0);
  Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  Enemy_SetAnimEntry(&p->e, 2, 13, 0);
  Enemy_SetAnimEntry(&p->e, 15, 5, 0);
  Enemy_SetAnimEntry(&p->e, 5, 6, 0);
  Enemy_SetAnimEntry(&p->e, 16, 7, 0);
  Enemy_SetAnimEntry(&p->e, 17, 8, 0);
  Enemy_SetAnimEntry(&p->e, 3, 9, 0);
  Enemy_SetAnimEntry(&p->e, 6, 10, 0);
  Enemy_SetAnimEntry(&p->e, 7, 11, 0);
  Enemy_SetAnimEntry(&p->e, 10, 12, 0);
}

NAKED void Dog_OnReset(Dog* p) { INCFUNC("asm/func/Dog_OnReset.inc"); }

void FUN_0814a8c8(Dog* p) { CLEAR_FLAGS((p->e).flags2, ENEFLAG2_UNK_1); }

NAKED s32 FUN_0814a8dc(Dog* p) { INCFUNC("asm/func/FUN_0814a8dc.inc"); }

void FUN_0814aad4(Dog* p) {
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_7 | ENEFLAG3_UNK_9)) {
    Enemy_SetAnimEntry(&p->e, 1, 4, 0);
  } else {
    Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_9)) {
    (p->e).animSpeedDiv = 2;
  }
}

void Dog_InitHitboxes(Dog* p) {
  Dog* self = (p->e).unk_1cc;
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset, hit2Size, hit2Offset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Dog_OnHurt, p);
  VEC3_SET(hitSize, 64, 120, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Dog_OnHit, 0, p);
  VEC3_SET(hit2Size, 0, 120, 0);
  VEC3_SET(hit2Offset, 0, 128, 0);
  Enemy_InitHitboxWithAtk(&p->e, &self->unk_658, &hit2Size, &hit2Offset, FUN_0814b89c, 1, p);
  Hitbox_SetFlags(&self->unk_658, HBFLAG_ANGLE);
}

NAKED void FUN_0814ac10(Dog* p) { INCFUNC("asm/func/FUN_0814ac10.inc"); }

void FUN_0814ae80(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (q->unk_6c8 != 0) {
    q->unk_6c8--;
  }
  if (q->unk_6ca != 0) {
    q->unk_6ca--;
  }
}

void FUN_0814aeb0(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (q->unk_6c6 != 0) {
    q->unk_6c6--;
  }
}

NAKED void FUN_0814aed0(Dog* p) { INCFUNC("asm/func/FUN_0814aed0.inc"); }

// 倒されたときのスクリプトを, 位置や種族などを引数にして呼ぶ
void FUN_0814afc8(Dog* p) {
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_19)) {
    Dog* q = (p->e).unk_1cc;

    if ((p->e).unk_198 != 0) {
      u32 argv[10];
      ScriptArgs sa;

      argv[0] = (p->e).mover.pos.x;
      argv[1] = (p->e).mover.pos.y;
      argv[2] = (p->e).mover.pos.z;
      argv[3] = (p->e).unk_19c;
      argv[4] = (p->e).unk_1a0;
      argv[5] = (p->e).unk_1a4;
      if (q->unk_6d0 < 0) {
        argv[6] = -1;
        argv[7] = -1;
      } else {
        argv[6] = q->unk_6d2;
        argv[7] = q->unk_6d4;
      }
      argv[8] = (p->e).kind;
      argv[9] = (p->e).variant;
      sa.argc = 10;
      sa.argv = argv;
      VM_ExecByID((p->e).unk_198, &sa);
    }
  }
}

NAKED bool8 FUN_0814b090(Dog* p, u32 angle) { INCFUNC("asm/func/FUN_0814b090.inc"); }

// 残差1命令, 原典は 0x6C8 のオフセットに 2 を足して 0x6CA を作るがこちらはプールから読む, 試済: 2つを u16[2] にする形
NON_MATCH bool8 FUN_0814b3a0(Dog* p) {
#ifdef NONMATCHING_C
  Dog* q = (p->e).unk_1cc;

  if ((p->e).variant <= 1 || (p->e).variant == 4) {
    if (q->unk_6c8 == 0) {
      return TRUE;
    }
  } else {
    if (q->unk_6c8 == 0) {
      return TRUE;
    }
    if (q->unk_6ca == 0) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0814b3a0.inc");
#endif
}

NAKED bool8 FUN_0814b3e0(Dog* p) { INCFUNC("asm/func/FUN_0814b3e0.inc"); }

NAKED void enemy_dog_0814b500(Dog* p) { INCFUNC("asm/func/enemy_dog_0814b500.inc"); }

void FUN_0814b78c(Dog* p) {
  if (p->unk_6d8 != 0) {
    p->unk_6d8--;
  }
}

NAKED void FUN_0814b7a4(Vec3* pos) { INCFUNC("asm/func/FUN_0814b7a4.inc"); }

void Dog_OnHit(HitboxData* a, HitboxData* b, Dog* p) {
  if (Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

NAKED void FUN_0814b89c(HitboxData* a, HitboxData* b, Dog* p) { INCFUNC("asm/func/FUN_0814b89c.inc"); }

NAKED void Dog_OnHurt(HitboxData* a, HitboxData* b, Dog* p) { INCFUNC("asm/func/Dog_OnHurt.inc"); }

void FUN_0814c28c(Dog* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
}

void FUN_0814c2b0(Dog* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 0);
}

NAKED void FUN_0814c2d4(Dog* p) { INCFUNC("asm/func/FUN_0814c2d4.inc"); }

void FUN_0814c970(Dog* p) {}

void FUN_0814c974(Dog* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 6);
    if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_1)) {
      SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
    }
  }
  if (Mod(timer, 60) == 0) {
    Enemy_SetEmote(&p->e, 2, 0, (p->e).kind);
  }
  if ((p->e).nodeWait <= 0 && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_12)) {
    Enemy_EnterState(&p->e, FUN_0814ca30, ES_UNK_6);
  }
}

void FUN_0814ca30(Dog* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 7);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
  }
  if (timer == 40) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_4);
  }
  if ((p->e).animForceRestart && timer > 120) {
    (p->e).subStateDone = 1;
  }
}

NAKED void FUN_0814caa0(Dog* p) { INCFUNC("asm/func/FUN_0814caa0.inc"); }

NAKED void FUN_0814cb8c(Dog* p) { INCFUNC("asm/func/FUN_0814cb8c.inc"); }

NAKED void FUN_0814ccfc(Dog* p) { INCFUNC("asm/func/FUN_0814ccfc.inc"); }

NAKED void FUN_0814dd38(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814dd38.inc"); }

// 火を吐く, 決まったフレームの間だけ2つ目の攻撃判定を出す
void FUN_0814de34(Dog* p, s32 timer) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
    Entity081f1770_Spawn(&(p->e).mover.pos, (p->e).mover.angle, 0);
    PlaySound_082406e0(SONG_933);
  }
  if (timer >= 13 && timer <= 23) {
    Hitbox_Register(&q->unk_658);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

void FUN_0814deb0(Dog* p) {
  Dog* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 15);
    q->unk_708 = (p->e).playerMover->pos;
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, FUN_0814df40, ES_UNK_34);
  }
}

NAKED void FUN_0814df40(Dog* p) { INCFUNC("asm/func/FUN_0814df40.inc"); }

void FUN_0814e1b0(Dog* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 16);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

void FUN_0814e1fc(Dog* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 14);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

NAKED void FUN_0814e248(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814e248.inc"); }

void FUN_0814e420(Dog* p) {}

NAKED void FUN_0814e424(Dog* p) { INCFUNC("asm/func/FUN_0814e424.inc"); }

NAKED void FUN_0814e530(Dog* p) { INCFUNC("asm/func/FUN_0814e530.inc"); }

NAKED void FUN_0814e680(Dog* p) { INCFUNC("asm/func/FUN_0814e680.inc"); }

NAKED void FUN_0814e8ec(Dog* p, s32 timer) { INCFUNC("asm/func/FUN_0814e8ec.inc"); }

NAKED bool8 FUN_0814eacc(Dog* p) { INCFUNC("asm/func/FUN_0814eacc.inc"); }

NAKED void FUN_0814fba4(Dog* p) { INCFUNC("asm/func/FUN_0814fba4.inc"); }

NAKED void FUN_0814fc7c(Dog* p) { INCFUNC("asm/func/FUN_0814fc7c.inc"); }

void FUN_081504e8(Dog* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad8e0; }

s32 FUN_081504f8(Dog* p) {
  FUN_0814aad4(p);
  FUN_0814aed0(p);
  return 1;
}

s32 FUN_08150510(Dog* p) {
  FUN_0814ac10(p);
  FUN_0814ae80(p);
  FUN_0814aeb0(p);
  FUN_0814b78c(p);
  return 1;
}

NAKED void FUN_08150534(Dog* p) { INCFUNC("asm/func/FUN_08150534.inc"); }

NAKED void FUN_08150660(Dog* p) { INCFUNC("asm/func/FUN_08150660.inc"); }

void FUN_0815077c(Dog* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad8e8; }

NAKED void FUN_08150790(Dog* p) { INCFUNC("asm/func/FUN_08150790.inc"); }

NAKED void FUN_08150b18(Dog* p) { INCFUNC("asm/func/FUN_08150b18.inc"); }

NAKED void FUN_08150de8(Dog* p) { INCFUNC("asm/func/FUN_08150de8.inc"); }

NAKED void FUN_081514f0(Dog* p) { INCFUNC("asm/func/FUN_081514f0.inc"); }

NAKED void FUN_081516d8(Dog* p) { INCFUNC("asm/func/FUN_081516d8.inc"); }

NAKED void FUN_081517a8(Dog* p) { INCFUNC("asm/func/FUN_081517a8.inc"); }

void FUN_081518ac(Dog* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad8f0; }

s32 FUN_081518c0(Dog* p) {
  Dog* self = p;

  FUN_081504f8(p);
  if ((p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }
  FUN_08150510(self);
  return 1;
}

s32 Dog_Update(Dog* p) {
  Enemy_Update(&p->e);
  return 0;
}

s32 Dog_Destroy(Dog* p) {
  if ((p->e).spriteKind == 0) {
    AuxSprite_Remove((AuxSprite*)(p->e).sprite);
  } else {
    MainSprite_Remove(&(p->e).sprite->s);
  }
  Free((p->e).sprite);
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_8)) {
    MsgQueue_Unregister(&(p->e).mq);
  }
  if (!(p->e).unk_44c) {
    ParticleShadow_Remove(&(p->e).shadow);
    (p->e).unk_44c = 1;
  }
  if (!(p->e).unk_44d) {
    Eff082473e0Emitter_Destroy(&(p->e).emitter);
    (p->e).unk_44d = 1;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_25)) {
    FUN_08002a58(&(p->e).mover);
  }
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている
NAKED s32 Dog_Init(Dog* p) { INCFUNC("asm/func/Dog_Init.inc"); }

void Dog_Create(void) {
  Dog* p = Malloc(sizeof(Dog));

  if (p != NULL) {
    ClearMemory(p, sizeof(Dog));
    if (Dog_Init(p) < 0) {
      Dog_Destroy(p);
      Free(p);
    }
  }
}
