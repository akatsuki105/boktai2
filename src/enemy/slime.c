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
  u8 unk_654[0x658 - 0x654];  // 0x654
  u16 unk_658;                // 0x658, unk_65a 以上になると ES_UNK_41 へ移る
  u16 unk_65a;                // 0x65A
  u16 unk_65c;                // 0x65C, 前のフレームの floorY
  u8 unk_65e[0x688 - 0x65E];  // 0x65E
  u16 unk_688;                // 0x688, '.s[0]'
  u16 unk_68a;                // 0x68A, '.s[1]'
  u16 unk_68c;                // 0x68C, 待ち時間, 64〜127 から数え下ろす
  u16 unk_68e;                // 0x68E, bit4 が立っていれば分裂の SE を鳴らして落とす
  u8 unk_690[1680 - 0x690];   // 0x690
} Slime;
static_assert(sizeof(Slime) == 1680);

extern const char s_slimecom_c_08252120[];  // "slimecom.c"

static inline bool8 Slime_TestUnk68e(Slime* p, u16 bit) {
  if (p->unk_68e & bit) return TRUE;
  return FALSE;
}

void FUN_08163604(Slime* p, s32 arg);
void FUN_081636d4(Slime* p);
void FUN_08163848(Slime* p);
void FUN_08164da8(Slime* p);
void Slime_SpawnDroplets(Slime* p);
void FUN_08164a48(Slime* p);
s32 Entity081efa9c_Spawn(Vec3* pos, Vec3* vel, u32 spriteID, u32 animID, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12, s32 param_13, s32 param_14, s32 param_15);
bool8 CanWalkToAdjacentTile(s32 fromIdx, s32 idx, s32 fromHeight, s32 fromStairs);
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

NAKED void Slime_OnHurt(HitboxData* a, HitboxData* b, Slime* p) { INCFUNC("asm/func/Slime_OnHurt.inc"); }

void FUN_08162cf4(Slime* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnimNoFacing(&p->e, 1);
}

void FUN_08162d18(Slime* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 1);
    (p->e).animSpeedDiv = 1;
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)(p->e).sprite)->anim, 64);
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
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)(p->e).sprite)->anim, 64);
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
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)(p->e).sprite)->anim, 64);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, FUN_08162fa8, ES_UNK_33);
  }
}

void FUN_08162efc(Slime* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 18);
    (p->e).animSpeedDiv = 1;
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)(p->e).sprite)->anim, 64);
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
      EnemyAuxSpriteData* s;

      (p->e).playingAnim = anim;
      s = (EnemyAuxSpriteData*)(p->e).sprite;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, 0, 0);
      (p->e).animForceRestart = FALSE;
    } else {
      MainSprite* s = &(p->e).sprite->s;

      if ((p->e).playingAnim != anim || (p->e).animForceRestart || (s->flags & SPRFLAG_XFLIP)) {
        (p->e).playingAnim = anim;
        MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, anim, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        s->flags &= ~SPRFLAG_XFLIP;
        (p->e).animForceRestart = FALSE;
      }
    }
    (p->e).animSpeedDiv = Random() & 63;
    if ((p->e).animSpeedDiv == 0) {
      (p->e).animSpeedDiv = 1;
    }
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)(p->e).sprite)->anim, (p->e).animSpeedDiv);
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
      EnemyAuxSpriteData* s;

      (p->e).playingAnim = anim;
      s = (EnemyAuxSpriteData*)(p->e).sprite;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, 1, 0);
      (p->e).animForceRestart = FALSE;
    } else {
      MainSprite* s = &(p->e).sprite->s;
      u16 a = anim + 1;

      if ((p->e).playingAnim != a || (p->e).animForceRestart || (s->flags & SPRFLAG_XFLIP)) {
        (p->e).playingAnim = a;
        MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
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
  Slime* q = (p->e).unk_1cc;

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
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)(p->e).sprite)->anim, 64);
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
  Slime* q = (p->e).unk_1cc;
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

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
  Slime* q = (p->e).unk_1cc;
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->unk_658 = 0;
    (p->e).animSpeedDiv = 1;
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)(p->e).sprite)->anim, 64);
    Enemy_PlayAnimNoFacing(&p->e, 1);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  }
  anim->cmdIdx = 0;
  anim->tick = 5;
  if (Mod(arg, 4) == 0) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if (arg > 30) {
    Enemy_EnterState(&p->e, FUN_081636d4, ES_UNK_42);
  }
}

// 向いている方へ跳ね, 上りは縦に伸ばし下りは縮めて戻す, ENEFLAG2_UNK_4 が立つと分裂して状態43へ移る
void FUN_081636d4(Slime* p) {
  AuxSprite* sprite = &((EnemyAuxSpriteData*)(p->e).sprite)->sprite;
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).animSpeedDiv = 2;
    AuxAnim_SetAnimSpeed(&((EnemyAuxSpriteData*)(p->e).sprite)->anim, 64);
    Vec3_SetPolar(&(p->e).jumpVel, (p->e).unk_1fc, 18);
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
    FUN_08164da8(p);
    FUN_08164da8(p);
    PlaySound_082406e0(SE_SLIME_FISSION);
  }
}

void FUN_08163848(Slime* p) {
  AuxSprite* aux = (AuxSprite*)(p->e).sprite;

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
  if (Sprite_UpdateVanishBlink(&((AuxSprite*)(p->e).sprite)->flags, arg, 10, 30)) {
    s32 idx;

    (p->e).subStateDone = 1;
    if ((p->e).unk_19a != 0) {
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
      VM_ExecByID((p->e).unk_19a, &sa);
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
  Slime* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).mover.angle = (p->e).unk_1fc;
    Enemy_RunScript(&p->e);
    if ((p->e).kind != ENEK_SPIDER) {
      SET_FLAGS((p->e).unk_222, ENEMY222_UNK_2);
    }
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_7);
    (p->e).unk_24e = (p->e).unk_24c;
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
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    Slime_PickWalkDest(p, (p->e).mover.angle);
    (p->e).animSpeedDiv = 1;
    return;
  }
  (p->e).unk_608(&p->e);
  speed = (p->e).unk_588(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  if (Enemy_StepToDest(&p->e, speed)) {
    Slime_PickWalkDest(p, (p->e).mover.angle);
  }
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).subStateTimer++;
}

void FUN_08163d94(Slime* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
  }
  (p->e).unk_608(&p->e);
  (p->e).subStateTimer++;
}

void FUN_08163e10(Slime* p) {
  if ((p->e).subStateBegun) {
    (p->e).subStateBegun = 0;
  }
  if (!(p->e).unk_608(&p->e)) {
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
  Slime* q = (p->e).unk_1cc;
  EnemyAuxSpriteData* aux;

  q->unk_68e = 0;
  q->unk_658 = 0;
  Enemy_ClearPendingState(&p->e, s_slimecom_c_08252120, 69);
  Enemy_PlayAnim(&p->e, 0);
  aux = (EnemyAuxSpriteData*)(p->e).sprite;
  AuxSprite_AdvanceAnim(&aux->sprite, &aux->anim);
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
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (anim->tick == 0) {
    s32 i;

    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_16);
    i = Mod(anim->cmdIdx, 6);
    return u16_ARRAY_085ada08[i];
  }
  return 0;
}

// 乱数の向きから 90 度ずつ回して, 2 タイル先まで歩けるタイルが見つかった向きの行き先を経路の目的地にする, 向きは arg に戻す
// 268/279命令, 原典は p と回数と &unk_256 / &mover.pos をスタック (sp+8..0x18) に退避してループで読み直す (フレーム 0x1c), こちらは p を r9 に置く, 試済: &unk_256 と &mover.pos のポインタのローカル (273命令), Boku の FUN_080fb4d0 と同じ探索の形
NON_MATCH void Slime_PickWalkDest(Slime* p, u32 arg) {
#ifdef NONMATCHING_C
  u32 target;
  s32 i;
  WorldPos pos;

  (p->e).mover.angle = Random();
  for (i = 0; i < 4; i++) {
    u32 tileIdx = (p->e).unk_256;
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
        target = (p->e).unk_256;
        break;
      }
    }
    if (target != (p->e).unk_256) {
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
  Slime* q = (p->e).unk_1cc;

  (p->e).animSpeedDiv = 1;
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    s32 dy = abs((p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y);

    if (dy <= 512 && (p->e).unk_1e4 <= (p->e).range0Sq) {
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
  Slime* q = (p->e).unk_1cc;

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

void FUN_081645a4(Slime* p) {
  if (VM_SeekToNamedArg('s')) {
    p->unk_688 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_68a = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    p->unk_688 = 0;
    p->unk_68a = 0;
  }
}

// 分裂のスクリプト (.s[0]) を位置や向き, 体力を引数にして呼び, 自身は止まる
void FUN_081645fc(Slime* p) {
  Slime* q = (p->e).unk_1cc;

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
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 6, 24, 0x200, 0, (p->e).unk_47a + (p->e).variant, 0, 0, 0, 0, 0, 0);
  {
    u16* table = gRandomTable;
    u32 angle = _Random(table) & 0xFF;
    s32 speed = (_Random(table) & 15) + 6;

    Vec3_SetPolar(&vel, angle, speed);
  }
  vel.y = 37;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 7, 24, 0x200, 0, (p->e).unk_47a + (p->e).variant, 0, 0, 0, 0, 0, 0);
  {
    u16* table = gRandomTable;
    u32 angle = _Random(table) & 0xFF;
    s32 speed = (_Random(table) & 15) + 6;

    Vec3_SetPolar(&vel, angle, speed);
  }
  vel.y = 32;
  Entity081efa9c_Spawn(pos, &vel, SPRITE_SLIME, ANM_SLIME, 7, 24, 0x200, 0, (p->e).unk_47a + (p->e).variant, 1, 0, 0, 0, 0, 0);
#else
  INCFUNC("asm/func/Slime_SpawnDroplets.inc");
#endif
}

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

// 被弾したときの処理, 分裂の判定をし, ダメージ状態か, 体力が 1/4 を切っていれば止まり, そうでなければ待機へ戻す
// 258/258命令まで寄る形は, 最初の flags3 の書き換えを Enemy_ClearFlag3, ENEFLAG3_UNK_8 の検査を flags3 & bit をそのまま返す inline にしたとき (flags3 のアドレスを r5 に持ち越す形が出る), 残差は乱数の表などプールのアドレスを受ける一時レジスタ番号だけ
NON_MATCH bool8 FUN_081651dc(Slime* p) {
#ifdef NONMATCHING_C
  Slime* q = (p->e).unk_1cc;

  PlaySound_082406e0(SE_SLIME_DAMAGED);
  if ((p->e).variant == 3) {
    FUN_08164a48(p);
  }
  Enemy_ClearFlag3(&p->e, ENEFLAG3_UNK_5);
  q->unk_658 += 80;
  if (q->unk_688 != 0) {
    if ((p->e).hp < (p->e).unk_546) {
      FUN_081645fc(p);
    } else if ((u8)Random() <= 24) {
      FUN_081645fc(p);
    }
  }
  if ((p->e).flags6 & ENEFLAG6_UNK_18) {
    CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
    Enemy_EnterState(&p->e, (p->e).unk_5cc, ES_DAMAGED);
    Enemy_ResetState(&p->e, 3, 0, 0);
    return TRUE;
  }
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    return FALSE;
  }
  (p->e).unk_544 = 300;
  (p->e).unk_4a8->val = 0;
  if ((p->e).hp < (p->e).unk_546 || Slime_TestUnk68e(q, 8)) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 2);
    CLEAR_FLAGS((p->e).flags4, ENEFLAG4_UNK_7 | ENEFLAG4_UNK_8 | ENEFLAG4_UNK_11);
  } else if ((p->e).subState0 != 0 || (p->e).subState1 != 0 || (p->e).subState2 != 0) {
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
    Enemy_ResetState(&p->e, 0, 0, 0);
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_081651dc.inc");
#endif
}

s32 FUN_08165460(Slime* p) { return 1; }

// 高い所から落ちた先が上書きタイルなら倒れる
s32 FUN_08165464(Slime* p) {
  Slime* self = p;

  if ((p->e).floorY - p->unk_65c > 511) {
    if (Map_FindTileOverride(GetCollisionTileIdx(&(p->e).mover.pos), 1) != NULL) {
      FUN_08165178(self);
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
