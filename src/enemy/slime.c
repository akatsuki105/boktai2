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

// スライム系
// イエロースライム(ENEID_SLIME_Y), グリーンスライム(ENEID_SLIME_G), パープルスライム(ENEID_SLIME_P), ブラックスライム(ENEID_SLIME_B)
// HPが半分以下になると分裂する, 触れるとダメージに加えて種類に応じた状態異常をプレイヤーに与える
// ENEID_SLIME_Y: 状態異常なし, ENEID_SLIME_G: 毒, ENEID_SLIME_P: 石化, ENEID_SLIME_B: 引火or氷結
typedef struct {
  Enemy e;
  u8 unk_654[0x688 - 0x654];  // 0x654
  u16 unk_688;                // 0x688, '.s[0]'
  u16 unk_68a;                // 0x68A, '.s[1]'
  u8 unk_68c[2];              // 0x68C
  u16 unk_68e;                // 0x68E, bit4 が立っていれば分裂の SE を鳴らして落とす
  u8 unk_690[1680 - 0x690];   // 0x690
} Slime;
static_assert(sizeof(Slime) == 1680);

static inline bool8 Slime_TestUnk68e(Slime* p, u16 bit) {
  if (p->unk_68e & bit) return TRUE;
  return FALSE;
}

u32 Slime_PickHitAttributes(Slime* p);
void FUN_08163b04(Slime*);
void FUN_08163bbc(Slime*);
void FUN_08163d94(Slime*);
void FUN_08163e10(Slime*);

// PTR_ARRAY_085ad9c8 と くっつけた方がいいかも?
void (*const PTR_ARRAY_085ad9c4[1])(Slime*) = {
    FUN_08163b04,
};  // 0x085AD9C4

void (*const PTR_ARRAY_085ad9c8[16])(Slime*) = {
    FUN_08163d94,
    (void*)FUN_080f2864,
    FUN_08163bbc,
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
    FUN_08163e10,
};  // 0x085AD9C8

void Slime_OnHit(HitboxData* a, HitboxData* b, Slime* p) {
  if (Enemy_IsDead(&p->e) == 0 && b->ignoreMask == HIM_0) {
    Enemy_SetHitTarget(&p->e, b);
    if ((p->e).variant == 3) {
      a->attributes = Slime_PickHitAttributes(p);
    }
  }
}

NAKED void Slime_OnHurt(HitboxData* a, HitboxData* b, Slime* p) { INCFUNC("asm/func/Slime_OnHurt.inc"); }

void FUN_08162cf4(Slime* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnimNoFacing(&p->e, 1);
}

NAKED void FUN_08162d18(Slime* p) { INCFUNC("asm/func/FUN_08162d18.inc"); }

NAKED void FUN_08162df4(Slime* p) { INCFUNC("asm/func/FUN_08162df4.inc"); }

NAKED void FUN_08162e74(Slime* p) { INCFUNC("asm/func/FUN_08162e74.inc"); }

NAKED void FUN_08162efc(Slime* p) { INCFUNC("asm/func/FUN_08162efc.inc"); }

NAKED void FUN_08162fa8(Slime* p) { INCFUNC("asm/func/FUN_08162fa8.inc"); }

NAKED void FUN_081630dc(Slime* p) { INCFUNC("asm/func/FUN_081630dc.inc"); }

NAKED void FUN_081631d8(Slime* p) { INCFUNC("asm/func/FUN_081631d8.inc"); }

NAKED void FUN_0816328c(Slime* p) { INCFUNC("asm/func/FUN_0816328c.inc"); }

void FUN_0816335c(Slime* p) {}

NAKED void FUN_08163360(Slime* p) { INCFUNC("asm/func/FUN_08163360.inc"); }

NAKED void FUN_08163604(Slime* p, s32 arg) { INCFUNC("asm/func/FUN_08163604.inc"); }

NAKED void FUN_081636d4(Slime* p) { INCFUNC("asm/func/FUN_081636d4.inc"); }

NAKED void FUN_08163848(Slime* p) { INCFUNC("asm/func/FUN_08163848.inc"); }

NAKED void FUN_0816390c(Slime* p, s32 arg) { INCFUNC("asm/func/FUN_0816390c.inc"); }

NAKED void FUN_08163b04(Slime* p) { INCFUNC("asm/func/FUN_08163b04.inc"); }

void FUN_08163bac(Slime* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad9c4; }

NAKED void FUN_08163bbc(Slime* p) { INCFUNC("asm/func/FUN_08163bbc.inc"); }

NAKED void FUN_08163d94(Slime* p) { INCFUNC("asm/func/FUN_08163d94.inc"); }

NAKED void FUN_08163e10(Slime* p) { INCFUNC("asm/func/FUN_08163e10.inc"); }

void FUN_08163eac(Slime* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad9c8; }

void Slime_InitHitboxes(Slime* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 64, 128, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Slime_OnHurt, p);
  VEC3_SET(hitSize, 64, 100, 64);
  VEC3_SET(hitOffset, 0, 128, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Slime_OnHit, 0, p);
}

NAKED void Slime_OnReset(Slime* p) { INCFUNC("asm/func/Slime_OnReset.inc"); }

void FUN_0816406c(Slime* p) {}

void Slime_InitAnims(Slime* p) {
  Enemy_SetAnimEntry(&p->e, 0, 0, 0);
  Enemy_SetAnimEntry(&p->e, 14, 2, 0);
  Enemy_SetAnimEntry(&p->e, 15, 1, 0);
  Enemy_SetAnimEntry(&p->e, 1, 3, 0);
  Enemy_SetAnimEntry(&p->e, 3, 4, 0);
  Enemy_SetAnimEntry(&p->e, 10, 5, 0);
  Enemy_SetAnimEntry(&p->e, 16, 8, 0);
  Enemy_SetAnimEntry(&p->e, 17, 9, 0);
  Enemy_SetAnimEntry(&p->e, 18, 9, 4);
}

const u16 u16_ARRAY_085ada08[6] = {0, 16, 32, 20, 12, 0};  // 0x085ADA08

// 歩きアニメのコマが変わる瞬間だけ移動の速さを返す
s32 Slime_GetMoveSpeed(Slime* p) {
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (anim->tick == 0) {
    s32 i;

    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    i = Mod(anim->cmdIdx, 6);
    return u16_ARRAY_085ada08[i];
  }
  return 0;
}

NAKED void FUN_08164120(Slime* p, u32 arg) { INCFUNC("asm/func/FUN_08164120.inc"); }

NAKED bool8 FUN_08164388(Slime* p) { INCFUNC("asm/func/FUN_08164388.inc"); }

NAKED void FUN_0816446c(Slime* p) { INCFUNC("asm/func/FUN_0816446c.inc"); }

NAKED void FUN_08164520(Slime* p) { INCFUNC("asm/func/FUN_08164520.inc"); }

void FUN_081645a4(Slime* p) {
  if (VM_SeekToNamedArg('s')) {
    p->unk_688 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_68a = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    p->unk_688 = 0;
    p->unk_68a = 0;
  }
}

NAKED void FUN_081645fc(Slime* p) { INCFUNC("asm/func/FUN_081645fc.inc"); }

// ブラックスライムだけ, 当てたときの属性を乱数で引火か氷結に決める
u32 Slime_PickHitAttributes(Slime* p) {
  if ((p->e).variant != 3) {
    return 0;
  }
  return (u8)Random() < 180 ? HBATTR_HYOKETU | HBATTR_FROST : HBATTR_INKA | HBATTR_FLAME;
}

NAKED void FUN_081647c8(Slime* p) { INCFUNC("asm/func/FUN_081647c8.inc"); }

NAKED void FUN_08164a48(Slime* p) { INCFUNC("asm/func/FUN_08164a48.inc"); }

NAKED void FUN_08164da8(Slime* p) { INCFUNC("asm/func/FUN_08164da8.inc"); }

void Slime_PlayFissionSound(Slime* p) {
  Slime* q = (p->e).unk_1cc;

  if (Slime_TestUnk68e(q, 0x10)) {
    PlaySound_082406e0(SE_SLIME_FISSION);
    CLEAR_FLAGS(q->unk_68e, 0x10);
  }
}

// 自分の残り HP ぶんのダメージを受けさせて倒す
void FUN_08165178(Slime* p) {
  u16 hp;

  (p->e).angle = 0;
  (p->e).unk_4a0 = 1;
  hp = (p->e).hp;
  (p->e).hurtbox.damage = hp;
  (p->e).unk_48a = hp;
  (p->e).hurtbox.knockbackPower = 40;
  (p->e).weaponExpMask = 0;
  (p->e).flags6 = 0;
  (p->e).unk_48c = 1;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
}

NAKED bool8 FUN_081651dc(Slime* p) { INCFUNC("asm/func/FUN_081651dc.inc"); }

s32 FUN_08165460(Slime* p) { return 1; }

NAKED s32 FUN_08165464(Slime* p) { INCFUNC("asm/func/FUN_08165464.inc"); }

s32 FUN_08165508(Slime* p) {
  Slime* self = p;

  FUN_08165460(p);
  if ((p->e).unk_4be == 0) {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
    Enemy_RunStateHandler(&p->e);
  }
  FUN_08165464(self);
  return 1;
}

s32 Slime_Update(Slime* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

s32 Slime_Destroy(Slime* p) {
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
NAKED s32 Slime_Init(Slime* p) { INCFUNC("asm/func/Slime_Init.inc"); }

void Slime_Create(void) {
  Slime* p = Malloc(sizeof(Slime));

  if (p != NULL) {
    ClearMemory(p, sizeof(Slime));
    if (Slime_Init(p) < 0) {
      Slime_Destroy(p);
      Free(p);
    }
  }
}
