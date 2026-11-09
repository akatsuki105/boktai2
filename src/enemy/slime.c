#include "cwolf_target.h"
#include "eff_elemcond.h"
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

// ENEK_SLIME(variant: V_SLIME_Y, V_SLIME_G, V_SLIME_P, V_SLIME_B)
// HPが半分以下になると分裂する, 触れるとダメージに加えて種類に応じた状態異常をプレイヤーに与える
// V_SLIME_Y: 状態異常なし, V_SLIME_G: 毒, V_SLIME_P: 石化, V_SLIME_B: 引火or氷結
typedef struct {
  Enemy e;
  u8 unk_654[0x658 - 0x654];  // 0x654
  u16 unk_658;                // 0x658, unk_65a 以上になると ES_UNK_41 へ移る
  u16 unk_65a;                // 0x65A
  u16 unk_65c;                // 0x65C, 前のフレームの floorY
  u8 unk_65e[0x664 - 0x65E];  // 0x65E
  NavAgent navAgent;          // 0x664, Enemy.navAgent が指す
  u16 unk_688;                // 0x688, '.s[0]'
  u16 unk_68a;                // 0x68A, '.s[1]'
  u16 unk_68c;                // 0x68C, 待ち時間, 64〜127 から数え下ろす
  u16 unk_68e;                // 0x68E, bit4 が立っていれば分裂の SE を鳴らして落とす
  u8 unk_690[1680 - 0x690];   // 0x690
} Slime;
static_assert(sizeof(Slime) == 1680);

const STRING_DATA char s_slimecom_c_08252120[] = "slimecom.c";

static inline bool8 Slime_TestUnk68e(Slime* p, u16 bit) {
  if (p->unk_68e & bit) return TRUE;
  return FALSE;
}

void FUN_08163604(Slime* p, s32 arg);
void Slime_StateJumpAttack(Slime* p);
void FUN_08163848(Slime* p);
void Slime_ScatterDroplets(Slime* p);
void Slime_SpawnDroplets(Slime* p);
void Slime_ShootDroplets(Slime* p);
void Slime_TakeFatalDamage(Slime* p);
s32 Entity081efa9c_Spawn(Vec3* pos, Vec3* vel, u32 spriteID, u32 animID, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12, s32 param_13, s32 param_14, s32 param_15);
void Slime_PickWalkDest(Slime* p, u32 arg);
void FUN_08162df4(Slime* p);
void FUN_081631d8(Slime* p);
void FUN_08162efc(Slime* p);
void FUN_08162fa8(Slime* p);
void FUN_081630dc(Slime* p);
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

// 食らい判定, HBFLAG_UNK_11 の攻撃では攻撃の中心から見た向きの軸へ 192 押し出され, 押し出し先の床の高さが違えば倒れる
// 998/1001命令, 押し出し前の next = pos + delta で原典は &pos を先に作り pos.x を先に読む, 残りは Crow_OnHurt と同じ共通処理の残差
NON_MATCH void Slime_OnHurt(HitboxData* a, HitboxData* b, Slime* p) {
#ifdef NONMATCHING_C
  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (Hitbox_TestFlags(a, HBFLAG_UNK_11)) {
    Slime* self = p;
    Vec3 next;
    Vec3 push;
    WorldPos tile;
    Vec3 diff;
    WorldPos dst;
    s32 idx;

    Vec3_Sum(&next, &(p->e).mover.delta, &(p->e).mover.pos);
    Vec3_Delta(&push, &next, &a->center);
    TilePosAtIndex(&tile, (self->e).tileIdx);
    Vec3_Delta(&diff, &a->center, &tile);
    switch (FixToInt(6, ArcTan2_8(diff.x, diff.z) + 32)) {
      case 0: {
        push.x += 192;
        push.z = 0;
        break;
      }
      case 1: {
        push.x = 0;
        push.z += 192;
        break;
      }
      case 2: {
        push.x -= 192;
        push.z = 0;
        break;
      }
      case 3: {
        push.x = 0;
        push.z -= 192;
        break;
      }
    }
    Vec3_Sum(&dst, &push, &(self->e).mover.pos);
    idx = GetCollisionTileIdx(&dst);
    if ((self->e).floorY != ((TileAtIndex(idx)->heightStairs & 0xF) << 8)) {
      Slime_TakeFatalDamage(self);
      return;
    }
    (self->e).mover.pos.x += push.x;
    (self->e).mover.pos.z += push.z;
    (self->e).mover.delta.x = 0;
    (self->e).mover.delta.z = 0;
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
#else
  INCFUNC("asm/func/Slime_OnHurt.inc");
#endif
}

void FUN_08162cf4(Slime* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnimNoFacing(&p->e, 1);
}

void FUN_08162d18(Slime* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 1);
    (p->e).animSpeedDiv = 1;
    AuxAnim_SetAnimSpeed(&(p->e).s->aux.anim, Q6(1));
  }
  if ((p->e).animForceRestart) {
    if ((Random() & 31) < 24) {
      Enemy_EnterState(&p->e, FUN_08162df4, ES_UNK_0);
    } else {
      Enemy_EnterState(&p->e, FUN_08162d18, ES_UNK_40);
    }
  }
}

// 残差は Random の展開で gRandTableIdx のアドレスと新しい添字のレジスタが入れ替わるのみ, 試済: u8/s32 の受け, & 0xFF, フラグの OR を1か所にまとめる形, 宣言順
NON_MATCH void FUN_08162df4(Slime* p) {
#ifdef NONMATCHING_C
  EnemyFlags4 bits;
  s32 r;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animSpeedDiv = 1;
    AuxAnim_SetAnimSpeed(&(p->e).s->aux.anim, Q6(1));
    Enemy_PlayAnimNoFacing(&p->e, 16);
  }
  r = (u8)Random();
  if (r < 8) {
    bits = ENEFLAG4_UNK_4;
  } else if (r < 14) {
    bits = ENEFLAG4_UNK_5;
  } else {
    return;
  }
  SET_FLAGS((p->e).flags4, bits);
#else
  INCFUNC("asm/func/FUN_08162df4.inc");
#endif
}

void FUN_08162e74(Slime* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 17);
    (p->e).animSpeedDiv = 1;
    AuxAnim_SetAnimSpeed(&(p->e).s->aux.anim, Q6(1));
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, FUN_08162fa8, ES_UNK_33);
  }
}

void FUN_08162efc(Slime* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 18);
    (p->e).animSpeedDiv = 1;
    AuxAnim_SetAnimSpeed(&(p->e).s->aux.anim, Q6(1));
  }
  if ((p->e).animForceRestart) {
    Enemy_ResetState(&p->e, 0, 0, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
}

// 状態に入った最初だけ animTable[15] のアニメを流し, アニメの速さを乱数で決める, アニメが終わったら FUN_081630dc へ移る
// 再生部分を (Enemy* p, u32 anim) を取る static inline にし, 変化がなければ return, 最後に animForceRestart = FALSE とすると残差は MainSprite_SetAnim の第5引数 4 を作る位置だけ (122/122命令), anim を u8 にすると anim と spriteKind のレジスタが入れ替わる
NON_MATCH void FUN_08162fa8(Slime* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    u8 anim = (p->e).animTable[15].anim;

    if ((p->e).spriteKind == 0) {
      EnemyAuxSprite* s;

      (p->e).playingAnim = anim;
      s = &(p->e).s->aux;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, 0, 0);
      (p->e).animForceRestart = FALSE;
    } else {
      MainSprite* s = &(p->e).s->main.spr;

      if ((p->e).playingAnim != anim || (p->e).animForceRestart || (s->flags & SPRFLAG_XFLIP)) {
        (p->e).playingAnim = anim;
        MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, anim, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        s->flags &= ~SPRFLAG_XFLIP;
        (p->e).animForceRestart = FALSE;
      }
    }
    (p->e).animSpeedDiv = Random() & 63;
    if ((p->e).animSpeedDiv == 0) {
      (p->e).animSpeedDiv = 1;
    }
    AuxAnim_SetAnimSpeed(&(p->e).s->aux.anim, (p->e).animSpeedDiv);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, FUN_081630dc, ES_UNK_34);
  }
#else
  INCFUNC("asm/func/FUN_08162fa8.inc");
#endif
}

// 101/102 命令, 原典は anim に variant を足したものを同じレジスタで使い回す, 試済: anim/a の型 (u8/u16), 足し込みを anim 自身にする形, aux 側の代入順
NON_MATCH void FUN_081630dc(Slime* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    u8 anim = (p->e).animTable[15].anim;

    if ((p->e).spriteKind == 0) {
      EnemyAuxSprite* s;

      (p->e).playingAnim = anim;
      s = &(p->e).s->aux;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, 1, 0);
      (p->e).animForceRestart = FALSE;
    } else {
      MainSprite* s = &(p->e).s->main.spr;
      u16 a = anim + 1;

      if ((p->e).playingAnim != a || (p->e).animForceRestart || (s->flags & SPRFLAG_XFLIP)) {
        (p->e).playingAnim = a;
        MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        s->flags &= ~SPRFLAG_XFLIP;
        (p->e).animForceRestart = FALSE;
      }
    }
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, FUN_081631d8, ES_UNK_35);
  }
#else
  INCFUNC("asm/func/FUN_081630dc.inc");
#endif
}

// 64〜127 フレーム待ってから次の状態へ移る
void FUN_081631d8(Slime* p) {
  Slime* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->unk_68c = (Random() & 63) + 64;
  }
  if (q->unk_68c != 0) {
    q->unk_68c--;
  } else if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, FUN_08162fa8, ES_UNK_33);
  }
}

void FUN_0816328c(Slime* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 14);
    AuxAnim_SetAnimSpeed(&(p->e).s->aux.anim, Q6(1));
  }
  if ((p->e).animForceRestart) {
    if ((Random() & 31) < 24) {
      Enemy_EnterState(&p->e, FUN_08162df4, ES_UNK_0);
    } else {
      Enemy_EnterState(&p->e, FUN_08162d18, ES_UNK_40);
    }
  }
}

void FUN_0816335c(Slime* p) {}

// 被弾して後ろへ滑る状態, 滑る間はアニメを止め, 滑り終えてアニメも終わったら, 体力が 1/4 を切っていれば止まり, そうでなければ待機へ戻る
void Slime_StateDamaged(Slime* p) {
  Slime* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).jumpVel.x = FixToInt(2, (p->e).jumpVel.x);
    (p->e).jumpVel.z = FixToInt(2, (p->e).jumpVel.z);
    Enemy_PlayAnimNoFacing(&p->e, 3);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_0);
    (p->e).animForceRestart = FALSE;
  }
  Enemy_SetFlag(&p->e, ENEFLAG_UNK_13);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
  if (!Enemy_StepSlide(&p->e)) {
    anim->tick = 0;
    return;
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_ClearFlag(&p->e, ENEFLAG_UNK_7);
    if ((p->e).hp < (p->e).unk_546 || Slime_TestUnk68e(q, 8)) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 2);
      CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    } else {
      Enemy_EnterState(&p->e, FUN_08162df4, ES_UNK_0);
      Enemy_ResetState(&p->e, 0, 0, 0);
    }
  }
}

void FUN_08163604(Slime* p, s32 arg) {
  Slime* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->unk_658 = 0;
    (p->e).animSpeedDiv = 1;
    AuxAnim_SetAnimSpeed(&(p->e).s->aux.anim, Q6(1));
    Enemy_PlayAnimNoFacing(&p->e, 1);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  }
  anim->cmdIdx = 0;
  anim->tick = 5;
  if (Mod(arg, 4) == 0) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if (arg > 30) {
    Enemy_EnterState(&p->e, Slime_StateJumpAttack, ES_UNK_42);
  }
}

// 向いている方へ跳ね, 上りは縦に伸ばし下りは縮めて戻す, ENEFLAG2_UNK_4 が立つと分裂して状態43へ移る
void Slime_StateJumpAttack(Slime* p) {
  AuxSprite* sprite = &(p->e).s->aux.spr;
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animSpeedDiv = 2;
    AuxAnim_SetAnimSpeed(&(p->e).s->aux.anim, Q6(1));
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).playerAngle, 18);
    (p->e).jumpVel.y = 40;
    sprite->flags |= SPRFLAG_AFFINE;
    sprite->scaleX = 64;
    sprite->scaleY = 64;
    PlaySound_082406e0(SE_SLIME_ATK);
    (p->e).unk_1bc = 0;
  }
  if (anim->cmdIdx == 3) {
    anim->tick = 0;
  }
  if ((p->e).jumpVel.y > 0) {
    if (sprite->scaleY < 127) {
      sprite->scaleY++;
    }
  } else {
    if (sprite->scaleY > 64) {
      sprite->scaleY -= 2;
    }
    if (sprite->scaleY < 64) {
      sprite->scaleY = 64;
    }
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    Enemy_EnterState(&p->e, FUN_08163848, ES_UNK_43);
    Slime_ScatterDroplets(p);
    Slime_ScatterDroplets(p);
    PlaySound_082406e0(SE_SLIME_FISSION);
  }
}

void FUN_08163848(Slime* p) {
  AuxSprite* aux = &(p->e).s->aux.spr;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    aux->scaleX = 64;
    aux->scaleY = 64;
    aux->flags &= ~SPRFLAG_AFFINE;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  }
  if ((p->e).animForceRestart) {
    (p->e).animSpeedDiv = 1;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 2);
  }
}

// 倒されたときの状態, 点滅して消えたら倒されたスクリプトを呼び図鑑に載せて止まる
void Slime_StateDying(Slime* p, s32 arg) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 10);
    PlayEnemyDeathCry(&p->e);
    Slime_SpawnDroplets(p);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_3 | ENEFLAG3_UNK_4 | ENEFLAG3_UNK_5);
  }
  if (Enemy_TestFlag(&p->e, ENEFLAG_UNK_15)) {
    return;
  }
  if (Sprite_UpdateVanishBlink(&(p->e).s->aux.spr.flags, arg, 10, 30)) {
    s32 idx;

    (p->e).subStateDone = 1;
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
    idx = EnemyDex_GetEntryIdx((p->e).kind, (p->e).variant);
    if (idx < 32) {
      gStat->enemyDexSeen[0] |= 1 << idx;
    } else {
      gStat->enemyDexSeen[1] |= 1 << (idx - 32);
    }
    if (!Enemy_TestFlag(&p->e, ENEFLAG_UNK_10)) {
      FUN_080e6658(&p->e);
    }
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    return;
  }
  if (Enemy_TestSpriteFlags(&p->e, SPRFLAG_HIDDEN)) {
    ParticleShadow_Hide(&(p->e).shadow);
  } else {
    ParticleShadow_Show(&(p->e).shadow);
  }
}

void FUN_08163b04(Slime* p) {
  Slime* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_RunScript(&p->e);
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).chaseTimer = (p->e).chaseTimeMax;
  }
  if ((p->e).subStateDone) {
    SET_FLAGS(q->unk_68e, 4);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_08163bac(Slime* p) { (p->e).handlerTables[3] = (void*)PTR_ARRAY_085ad9c4; }

// 経路の目的地へ向かって歩く
void FUN_08163bbc(Slime* p) {
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    Slime_PickWalkDest(p, (p->e).mover.angle);
    (p->e).animSpeedDiv = 1;
    return;
  }
  (p->e).tryDetectPlayer(&p->e);
  speed = (p->e).getMoveSpeed(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Slime_PickWalkDest(p, (p->e).mover.angle);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).subStateTimer++;
}

void FUN_08163d94(Slime* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
  }
  (p->e).tryDetectPlayer(&p->e);
  (p->e).subStateTimer++;
}

void FUN_08163e10(Slime* p) {
  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  if (!(p->e).tryDetectPlayer(&p->e)) {
    Enemy_EnterState(&p->e, FUN_08162efc, ES_UNK_38);
    Enemy_ResetState(&p->e, 3, 1, 0);
  }
  (p->e).subStateTimer++;
}

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

// 復帰時に作業値と予約していた状態を消し, 待機アニメを流して1コマ送る
// 残差1命令 (128/129), 原典は p->sprite を r0 に読んでから r5 へ移す (Boku_OnReset / Mimic_OnReset と同じ壁), 試済: sprite を受ける inline, Enemy* を受ける inline, sprite と anim のローカル, anim を先に取る形
NON_MATCH void Slime_OnReset(Slime* p) {
#ifdef NONMATCHING_C
  Slime* q = (p->e).owner;
  EnemyAuxSprite* aux;

  q->unk_68e = 0;
  q->unk_658 = 0;
  Enemy_ClearPendingState(&p->e, s_slimecom_c_08252120, 69);
  Enemy_PlayAnim(&p->e, 0);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
#else
  INCFUNC("asm/func/Slime_OnReset.inc");
#endif
}

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
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (anim->tick == 0) {
    s32 i;

    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    i = Mod(anim->cmdIdx, 6);
    return u16_ARRAY_085ada08[i];
  }
  return 0;
}

// 乱数の向きから 90 度ずつ回して, 2 タイル先まで歩けるタイルが見つかった向きの行き先を経路の目的地にする, 向きは arg に戻す
// 268/279命令, 原典は p と回数と &tileIdx / &mover.pos をスタック (sp+8..0x18) に退避してループで読み直す (フレーム 0x1c), こちらは p を r9 に置く, 試済: &tileIdx と &mover.pos のポインタのローカル (273命令), Boku の FUN_080fb4d0 と同じ探索の形
NON_MATCH void Slime_PickWalkDest(Slime* p, u32 arg) {
#ifdef NONMATCHING_C
  u32 target;
  s32 i;
  WorldPos pos;

  (p->e).mover.angle = Random();
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
  (p->e).mover.angle = arg;
  TilePosAtIndex(&pos, target);
  (p->e).navAgent->dest = pos;
#else
  INCFUNC("asm/func/Slime_PickWalkDest.inc");
#endif
}

bool8 FUN_08164388(Slime* p) {
  Slime* q = (p->e).owner;

  (p->e).animSpeedDiv = 1;
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    s32 dy = abs((p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y);

    if (dy <= 512 && (p->e).playerDistSq <= (p->e).range0Sq) {
      goto found;
    }
  }
  return FALSE;

found:
  if ((p->e).hp < (p->e).unk_546 || Slime_TestUnk68e(q, 8)) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
    (p->e).animSpeedDiv = 2;
    q->unk_658++;
  } else {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_8);
  }
  return TRUE;
}

void FUN_0816446c(Slime* p) {
  Slime* q = (p->e).owner;

  SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  (p->e).navAgent->dest = gPlayerPtr[0]->mover.pos;
  if (q->unk_658 >= q->unk_65a) {
    Enemy_EnterState(&p->e, FUN_08163604, ES_UNK_41);
    Enemy_ResetState(&p->e, 3, 0, 0);
  }
}

void FUN_08164520(Slime* p) {
  u8 state = (p->e).state;

  if (state != ES_UNK_37 && state != ES_UNK_33 && state != ES_UNK_34 && state != ES_UNK_35) {
    Enemy_EnterState(&p->e, FUN_08162e74, ES_UNK_37);
    Enemy_ResetState(&p->e, 0, 0, 15);
  }
}

void Slime_ReadNamedArgs(Slime* p) {
  if (VM_SeekToNamedArg('s')) {
    p->unk_688 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_68a = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    p->unk_688 = 0;
    p->unk_68a = 0;
  }
}

// 分裂のスクリプト (.s[0]) を位置や向き, 体力を引数にして呼び, 自身は止まる
void Slime_Split(Slime* p) {
  Slime* q = (p->e).owner;

  if (q->unk_688 != 0) {
    u32 argv[10];
    Vec3 v;
    ScriptArgs sa;

    argv[0] = (p->e).mover.pos.x;
    argv[1] = (p->e).mover.pos.y;
    argv[2] = (p->e).mover.pos.z;
    argv[3] = (p->e).hp;
    Vec3_SetPolar(&v, (p->e).angle, 12);
    argv[4] = v.x;
    argv[5] = 24;
    argv[6] = v.z;
    argv[7] = (p->e).variant;
    argv[8] = q->unk_68a;
    argv[9] = (p->e).maxHp;
    sa.argc = 10;
    sa.argv = argv;
    VM_ExecByID(q->unk_688, &sa);
    Slime_SpawnDroplets(p);
    q->unk_688 = 0;
    SET_FLAGS(q->unk_68e, 8);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 2);
    CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  }
}

// ブラックスライムだけ, 当てたときの属性を乱数で引火か氷結に決める
u32 Slime_PickHitAttributes(Slime* p) {
  if ((p->e).variant != 3) {
    return 0;
  }
  return (u8)Random() < 180 ? HBATTR_HYOKETU | HBATTR_FROST : HBATTR_INKA | HBATTR_FLAME;
}

// 分裂の飛沫を3つ, 乱数の向きと速さで飛ばす
// 270/269命令, 乱数の取り方 (ブロックで table を取る形) は揃う, 残差は p と pos の割り当てが入れ替わる (原典 p=r8, pos=r6) こと, 試済: 宣言順, pos を直接渡す形, 飛沫1つ分の inline (274命令)
NON_MATCH void Slime_SpawnDroplets(Slime* p) {
#ifdef NONMATCHING_C
  Vec3 vel;
  WorldPos* pos;

  {
    u16* table = gRandomTable;
    u32 angle = _Random(table) & 0xFF;
    s32 speed = (_Random(table) & 15) + 6;

    Vec3_SetPolar(&vel, angle, speed);
  }
  vel.y = 48;
  pos = &(p->e).mover.pos;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 6, 24, 0x200, 0, (p->e).plttBase + (p->e).variant, 0, 0, 0, 0, 0, 0);
  {
    u16* table = gRandomTable;
    u32 angle = _Random(table) & 0xFF;
    s32 speed = (_Random(table) & 15) + 6;

    Vec3_SetPolar(&vel, angle, speed);
  }
  vel.y = 37;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 7, 24, 0x200, 0, (p->e).plttBase + (p->e).variant, 0, 0, 0, 0, 0, 0);
  {
    u16* table = gRandomTable;
    u32 angle = _Random(table) & 0xFF;
    s32 speed = (_Random(table) & 15) + 6;

    Vec3_SetPolar(&vel, angle, speed);
  }
  vel.y = 32;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 7, 24, 0x200, 0, (p->e).plttBase + (p->e).variant, 1, 0, 0, 0, 0, 0);
#else
  INCFUNC("asm/func/Slime_SpawnDroplets.inc");
#endif
}

// プレイヤーの方へ攻撃判定つきの飛沫を3つ, 少しずつ向きと速さを散らして撃つ
// 361/365命令, 乱数は1つ目の塊だけ頭の table を使い, 2つ目以降は塊ごとに table を取り直すと命令列はほぼ揃う, 残差は pos と定数 7 の割り当て (原典は2つ目の Spawn の前で pos を r8 から r9 へ写し, 7 を r8 に置いて & 7 と anim 番号に使い回す), 試済: pos を直接渡す
NON_MATCH void Slime_ShootDroplets(Slime* p) {
#ifdef NONMATCHING_C
  u32 attrs = Slime_PickHitAttributes(p);
  u16* table = gRandomTable;
  u32 r = _Random(table) & 15;
  Vec3 vel;
  WorldPos* pos;
  s32 angle;

  Vec3_Delta(&vel, &(p->e).mover.pos, &(p->e).playerMover->pos);
  angle = ArcTan2_8(vel.x, vel.z);
  Vec3_SetPolar(&vel, angle + r, (_Random(table) & 7) + 6);
  vel.y = 48;
  pos = &(p->e).mover.pos;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 6, 24, 0, 0, (p->e).plttBase + (p->e).variant, 0, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1] | attrs, (p->e).atkIframes[1]);
  {
    u16* table = gRandomTable;
    u32 r = _Random(table) & 15;
    s32 speed = _Random(table) & 7;

    Vec3_SetPolar(&vel, angle + r, speed + 6);
  }
  vel.y = 37;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 7, 24, 0, 0, (p->e).plttBase + (p->e).variant, 0, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1] | attrs, (p->e).atkIframes[1]);
  {
    u16* table = gRandomTable;
    u32 r = _Random(table) & 15;
    s32 speed = _Random(table) & 7;

    Vec3_SetPolar(&vel, angle + r, speed + 6);
  }
  vel.y = 32;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 6, 24, 0, 0, (p->e).plttBase + (p->e).variant, 1, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1] | attrs, (p->e).atkIframes[1]);
#else
  INCFUNC("asm/func/Slime_ShootDroplets.inc");
#endif
}

// 攻撃判定つきの飛沫を3つ, 乱数の向きと速さで周りへ撃つ
// 373/380命令, Slime_ShootDroplets と同じ形で, プレイヤーとの差を Vec3_Delta で作るが使わない (原典のまま), 残差は p を r9, pos を r8 に置く割り当て, 試済: pos を Delta の前に取る (悪化)
NON_MATCH void Slime_ScatterDroplets(Slime* p) {
#ifdef NONMATCHING_C
  u32 attrs = Slime_PickHitAttributes(p);
  u16* table = gRandomTable;
  u32 r = _Random(table) & 15;
  Vec3 vel;
  WorldPos* pos;
  u32 a;
  s32 speed;

  Vec3_Delta(&vel, &(p->e).mover.pos, &(p->e).playerMover->pos);
  a = (u8)_Random(table);
  speed = _Random(table) & 7;
  Vec3_SetPolar(&vel, a + r, speed + 12);
  vel.y = 48;
  pos = &(p->e).mover.pos;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 6, 24, 0, 0, (p->e).plttBase + (p->e).variant, 0, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1] | attrs, (p->e).atkIframes[1]);
  {
    u16* table = gRandomTable;
    u32 r = _Random(table) & 15;
    u32 a = (u8)_Random(table);
    s32 speed = _Random(table) & 7;

    Vec3_SetPolar(&vel, a + r, speed + 12);
  }
  vel.y = 37;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 7, 24, 0, 0, (p->e).plttBase + (p->e).variant, 0, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1] | attrs, (p->e).atkIframes[1]);
  {
    u16* table = gRandomTable;
    u32 r = _Random(table) & 15;
    u32 a = (u8)_Random(table);
    s32 speed = _Random(table) & 7;

    Vec3_SetPolar(&vel, a + r, speed + 6);
  }
  vel.y = 32;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 6, 24, 0, 0, (p->e).plttBase + (p->e).variant, 1, 0, (p->e).atkPower[1], (p->e).atkKnockback[1], (p->e).atkAttrs[1] | attrs, (p->e).atkIframes[1]);
#else
  INCFUNC("asm/func/Slime_ScatterDroplets.inc");
#endif
}

void Slime_PlayFissionSound(Slime* p) {
  Slime* q = (p->e).owner;

  if (Slime_TestUnk68e(q, 0x10)) {
    PlaySound_082406e0(SE_SLIME_FISSION);
    CLEAR_FLAGS(q->unk_68e, 0x10);
  }
}

// 自分の残り HP ぶんのダメージを受けさせて倒す
void Slime_TakeFatalDamage(Slime* p) {
  u16 hp;

  (p->e).angle = 0;
  (p->e).unk_4a0 = 1;
  hp = (p->e).hp;
  (p->e).hurtbox.damage = hp;
  (p->e).unk_48a = hp;
  (p->e).hurtbox.knockback = 40;
  (p->e).weaponExpMask = 0;
  (p->e).flags6 = 0;
  (p->e).unk_48c = 1;
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
}

// 被弾したときの処理, 分裂の判定をし, ダメージ状態か, 体力が 1/4 を切っていれば止まり, そうでなければ待機へ戻す
// 258/258命令まで寄る形は, 最初の flags3 の書き換えを Enemy_ClearFlag3, ENEFLAG3_UNK_8 の検査を flags3 & bit をそのまま返す inline にしたとき (flags3 のアドレスを r5 に持ち越す形が出る), 残差は乱数の表などプールのアドレスを受ける一時レジスタ番号だけ
NON_MATCH bool8 Slime_OnDamaged(Slime* p) {
#ifdef NONMATCHING_C
  Slime* q = (p->e).owner;

  PlaySound_082406e0(SE_SLIME_DAMAGED);
  if ((p->e).variant == 3) {
    Slime_ShootDroplets(p);
  }
  Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_5);
  q->unk_658 += 80;
  if (q->unk_688 != 0) {
    if ((p->e).hp < (p->e).unk_546) {
      Slime_Split(p);
    } else if ((u8)Random() <= 24) {
      Slime_Split(p);
    }
  }
  if ((p->e).flags6 & ENEFLAG6_UNK_18) {
    CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    Enemy_EnterState(&p->e, (p->e).handlerDamaged, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  (p->e).unk_544 = 300;
  (p->e).pathNodePos->val = 0;
  if ((p->e).hp < (p->e).unk_546 || Slime_TestUnk68e(q, 8)) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 2);
    CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  } else if ((p->e).subState0 != 0 || (p->e).subState1 != 0 || (p->e).subState2 != 0) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    Enemy_ResetState(&p->e, 0, 0, 0);
  }
  return TRUE;
#else
  INCFUNC("asm/func/Slime_OnDamaged.inc");
#endif
}

s32 FUN_08165460(Slime* p) { return 1; }

// 高い所から落ちた先が上書きタイルなら倒れる
s32 FUN_08165464(Slime* p) {
  Slime* self = p;

  if ((p->e).floorY - p->unk_65c > 511) {
    if (Map_FindTileOverride(GetCollisionTileIdx(&(p->e).mover.pos), 1) != NULL) {
      Slime_TakeFatalDamage(self);
      (self->e).floorY = p->unk_65c;
    }
  }
  p->unk_65c = (self->e).floorY;
  return 1;
}

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
  if (Enemy_TestFlag5(&p->e, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Unregister(&(p->e).cwolfNode);
  }
  Mover_Unlink(&(p->e).mover);
  Hitbox_Unregister(&(p->e).hurtbox);
  Enemy_Unregister(&p->e);
  return 0;
}

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
// 1816/1955命令, Crow_Init の下書きを Slime 向けに直したもの (呼び出し列は一致), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline)
NON_MATCH s32 Slime_Init(Slime* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  s32 height;
  u8 kind;

  p->unk_68e = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  Slime_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_SLIME);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANM_SLIME);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_SLIME);
    spr->gfx = *f;
    OpenMainSpriteFile(&spr->gfx, f);
    MainSprite_Add(&spr->spr, &spr->gfx, 0, 0, 2, 2, 60, &origin);
    (p->e).playingAnim = 0xFF;
  }

  (p->e).kind = ENEK_SLIME;
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

  Mover_Init(&(p->e).mover, id, &pos, 0, 4, p);
  if (TEST_FLAGS((p->e).flags5, ENEFLAG5_UNK_9)) {
    CWolfTargetManager_Register(&(p->e).cwolfNode, &(p->e).mover, Enemy_OnCWolfMessage);
  }
  Mover_SetAuxSprite(&(p->e).mover, (p->e).spriteKind == 0 ? &(p->e).s->aux.spr : NULL);
  if ((p->e).kind == ENEK_DOG) {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 60, 60);
  } else {
    Mover_SetCollision(&(p->e).mover, &(p->e).tile, 64, 64);
  }
  kind = (p->e).kind;
  if (kind != ENEK_BAT && kind != ENEK_CROW && kind != ENEK_MIMIC && kind != ENEK_SLIME && kind != ENEK_BEE && kind != ENEK_CENTIPEDE && kind != ENEK_SANDWORM && kind != ENEK_SERPENT && kind != ENEK_AX && kind != ENEK_SHAIAN && kind != ENEK_31) {
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
  if (VM_SeekToNamedArg('p')) {
    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).tileIdx = GetCollisionTileIdx(&(p->e).mover.pos);
    (p->e).floorY = TileHeightAt(&(p->e).mover.pos);
    p->unk_65c = (p->e).floorY;
    Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
  }
  if (!VM_SeekToNamedArg('j')) {
    (p->e).unk_1bc = 0;
  } else {
    s32 hp;

    (p->e).jumpVel.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).jumpVel.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).jumpVel.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_68e |= 0x18;
    hp = VM_GetNamedArgValue('m', 0);
    if (hp != 0) {
      (p->e).maxHp = hp;
      (p->e).unk_546 = (p->e).maxHp >> 1;
    }
    (p->e).unk_1bc = 1;
  }
  (p->e).hurtbox.iframes = VM_GetNamedArgValue('n', 0);
  p->unk_65a = 600;
  height = VM_GetNamedArgValue('f', 0);
  (p->e).heightAboveFloor = height;
  if ((u16)height != 0) {
    p->unk_68e |= 0x10;
  }
  Slime_ReadNamedArgs(p);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 147;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 147;
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

  Slime_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = NULL;
  (p->e).handlerFrame = (EnemyHandler)FUN_08165508;
  (p->e).getMoveSpeed = (void*)Slime_GetMoveSpeed;
  (p->e).handlerTurn = NULL;
  (p->e).handlerMove = FUN_08162cf4;
  (p->e).handlerWait = FUN_08162df4;
  (p->e).unk_5c0 = NULL;
  (p->e).onRouteFailed = NULL;
  (p->e).handlerDamaged = Slime_StateDamaged;
  (p->e).handlerDying = Slime_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = FUN_0816335c;
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
  (p->e).handlerSleep = FUN_080f56ec;
  (p->e).unk_598 = FUN_080f5b34;
  (p->e).unk_59c = FUN_080f5fac;
  (p->e).unk_5b4 = NULL;
  (p->e).unk_543 = 40;
  (p->e).onReset = (EnemyHandler)Slime_OnReset;
  (p->e).unk_5fc = (void*)FUN_0816406c;
  (p->e).onAttackRequest = (EnemyHandler)FUN_0816446c;
  (p->e).unk_5b0 = (EnemyHandler)FUN_08164520;
  (p->e).onDamaged = (void*)Slime_OnDamaged;
  (p->e).tryDetectPlayer = (void*)FUN_08164388;
  (p->e).unk_5b4 = (EnemyHandler)Slime_PlayFissionSound;
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_6);
  Enemy_InitShadowAndEmitter(&p->e);

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
    (p->e).hurtbox.flags &= ~HBFLAG_ANGLE;
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
  if (p->unk_68e & 8) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 2);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_11);
  }
  Enemy_InitHandlerTables(&p->e);
  FUN_08163eac(p);
  FUN_08163bac(p);
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
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)Slime_Update;
  (p->e).handlerDestroy = (EnemyHandler)Slime_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Slime_Init.inc");
#endif
}

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
