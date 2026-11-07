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

// クロウ(ENEID_CROW), ガーゴイル(ENEID_GARGOYLE)
typedef struct {
  Enemy e;
  u8 unk_654[0x658 - 0x654];  // 0x654
  u32 unk_658;                // 0x658
  u8 unk_65c;                 // 0x65C, 羽ばたきアニメを流した回数
  u8 unk_65d[3];              // 0x65D
  u8 unk_660;                 // 0x660, プレイヤーへ直進するときの速さ
  u8 unk_661[3];              // 0x661
  u32 unk_664;                // 0x664, unk_1e4 がこれ以上ならプレイヤーへの直進を続ける
  u8 unk_668[0x671 - 0x668];  // 0x668
  u8 unk_671;                 // 0x671, 鳴くたびに 40 ずつ増える
  u8 unk_672[0x6A0 - 0x672];  // 0x672
  WorldPos curveStart;        // 0x6A0, 曲線の始点
  Vec3 curveEnd;              // 0x6A8, 曲線の終点
  Vec3 unk_6b0;               // 0x6B0, 曲線移動を始めるときに 0 に戻す
  u8 unk_6b8[1728 - 0x6B8];   // 0x6B8
} Crow;
static_assert(sizeof(Crow) == 1728);

static inline bool8 Crow_TestUnk658(Crow* p, u32 bit) {
  if (p->unk_658 & bit) return TRUE;
  return FALSE;
}

// 向いている向きとプレイヤーのいる向きの差 (0〜128) を返す
static inline s32 Crow_GetAngleDiffToPlayer(Crow* p) {
  Vec3 diff;
  s32 d;

  Vec3_Delta(&diff, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
  d = ArcTan2_8(diff.x, diff.z) - (p->e).mover.angle;
  if (d > 128) {
    d -= 256;
  } else if (d < -128) {
    d += 256;
  }
  return abs(d);
}

void Crow_PlayWingSound(Crow* p);
void FUN_081436b4(Crow*);
void FUN_081439d8(Crow*);
void FUN_08143dd4(Crow*);
void FUN_08143ef8(Crow*);
void FUN_08143fac(Crow*);
void FUN_08144cd0(Crow*);
void FUN_08144ec8(Crow*);
void FUN_081452cc(Crow*);
void Crow_GetDirAndFlip(u16 angle, s32* outDir, s32* outFlip);

void (*const PTR_ARRAY_085ad828[5])(Crow*) = {
    FUN_08143dd4,
    FUN_081439d8,
    FUN_081436b4,
    FUN_08143ef8,
    FUN_08143fac,
};  // 0x085AD828

const u32 u32_ARRAY_085ad83c[4] = {4, 6, 8, 10};  // 0x085AD83C

void (*const PTR_ARRAY_085ad84c[3])(Crow*) = {
    FUN_08144cd0,
    FUN_08144ec8,
    FUN_081452cc,
};  // 0x085AD84C

void FUN_08144160(Crow*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085ad858[7])(Crow*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    FUN_08144160,
};  // 0x085AD858

// 当たった相手が HIM_0 だけを無視する判定のときだけ攻撃対象として覚える
void Crow_OnHit(HitboxData* a, HitboxData* b, Crow* p) {
  if (b->ignoreMask == HIM_0 && Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

NAKED void Crow_OnHurt(HitboxData* a, HitboxData* b, Crow* p) { INCFUNC("asm/func/Crow_OnHurt.inc"); }

void FUN_08142fd8(Crow* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
  Crow_PlayWingSound(p);
}

void FUN_08143004(Crow* p, s32 timer) {
  Crow* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 0);
  } else if (!Crow_TestUnk658(q, 4)) {
    if (Mod(timer, 90) == 0) {
      Enemy_PlayAnim(&p->e, 16);
      q->unk_671 += 40;
    } else if ((p->e).animForceRestart) {
      Enemy_PlayAnim(&p->e, 0);
    }
  }
}

// 羽ばたきアニメを4回流し, 5回目で終わりの合図を出す
void FUN_08143094(Crow* p) {
  Crow* q = (p->e).unk_1cc;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 17);
    q->unk_65c = 0;
  }
  if (q->unk_65c != 0) {
    Crow_PlayWingSound(p);
  }
  if ((p->e).animForceRestart) {
    switch (q->unk_65c) {
      case 0:
      case 1:
      case 2:
      case 3: {
        Enemy_PlayAnim(&p->e, 15);
        break;
      }
      case 5: {
        (p->e).subStateDone = 1;
        return;
      }
    }
    q->unk_65c++;
  }
}

// 77/75 命令, 向きを使わないアニメ再生の展開で anim と差分を足した値を別のレジスタに持つ, FUN_081630dc と同じ形
NON_MATCH void FUN_0814312c(Crow* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    u8 anim = (p->e).animTable[2].anim;

    if ((p->e).spriteKind == 0) {
      EnemyAuxSpriteData* s;

      (p->e).playingAnim = anim;
      s = (EnemyAuxSpriteData*)(p->e).sprite;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, 0, 0);
      (p->e).animForceRestart = FALSE;
    } else {
      MainSprite* s = &(p->e).sprite->s;
      u16 a = anim + 0;

      if ((p->e).playingAnim != a || (p->e).animForceRestart || (s->flags & SPRFLAG_XFLIP)) {
        (p->e).playingAnim = a;
        MainSprite_SetAnim(&(p->e).sprite->s, &(p->e).sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
        s->flags &= ~SPRFLAG_XFLIP;
        (p->e).animForceRestart = FALSE;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_0814312c.inc");
#endif
}

// 状態に入った最初だけ, 向きから8方向の番号と左右反転を決めて animTable[2] のアニメを流す
// Enemy_PlayAnim の展開, 再生部分を (p, anim, variant, f) を取る inline にして Enemy* e = &p->e で angle を読むと残差は MainSprite_SetAnim をまたいで定数 4 を r8 に置く点だけになる (Enemy_PlayAnim と同じ壁)
NON_MATCH void FUN_081431e0(Crow* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeStateBegun(&p->e)) {
    s32 dir;
    s32 flip;
    u8 anim;

    Crow_GetDirAndFlip((p->e).mover.angle, &dir, &flip);
    anim = (p->e).animTable[2].anim;
    if ((p->e).spriteKind == 0) {
      EnemyAuxSpriteData* s = (EnemyAuxSpriteData*)(p->e).sprite;

      (p->e).playingAnim = anim;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, dir, flip);
    } else {
      MainSprite* s = &(p->e).sprite->s;
      s32 a = anim + dir;

      if ((p->e).playingAnim == a && (p->e).animForceRestart == 0) {
        if (flip == ANIM_PLAY_XFLIP && (s->flags & SPRFLAG_XFLIP)) {
          return;
        }
        if (flip == 0 && !(s->flags & SPRFLAG_XFLIP)) {
          return;
        }
      }
      (p->e).playingAnim = a;
      MainSprite_SetAnim(s, &(p->e).sprite->gfx, a, PLAYMODE_ONCE_AND_STOP, (flip & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
      if (flip & ANIM_PLAY_XFLIP) {
        MainSprite_SetFlags(s, SPRFLAG_XFLIP);
      } else {
        MainSprite_ClearFlags(s, SPRFLAG_XFLIP);
      }
    }
    (p->e).animForceRestart = FALSE;
  }
#else
  INCFUNC("asm/func/FUN_081431e0.inc");
#endif
}

void FUN_081432ec(Crow* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 15);
}

NAKED void FUN_08143310(Crow* p, s32 timer) { INCFUNC("asm/func/FUN_08143310.inc"); }

// 倒されたときの状態, 点滅しながら消えたら倒されたスクリプトを呼び図鑑に載せて止まる
void Crow_StateDying(Crow* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 10);
    PlayEnemyDeathCry(&p->e);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_6 | ENEFLAG_UNK_7 | ENEFLAG_UNK_8 | ENEFLAG_UNK_14 | ENEFLAG_UNK_16);
    (p->e).unk_21e = 0;
    (p->e).unk_220 = 0;
    (p->e).unk_202 = 0;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
  }
  if (Sprite_UpdateVanishBlink(&((AuxSprite*)(p->e).sprite)->flags, timer, 10, 30)) {
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
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      FUN_080e6658(&p->e);
    }
    (p->e).unk_192 = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
  }
}

NAKED void FUN_081436b4(Crow* p) { INCFUNC("asm/func/FUN_081436b4.inc"); }

NAKED void FUN_081439d8(Crow* p) { INCFUNC("asm/func/FUN_081439d8.inc"); }

void FUN_08143dd4(Crow* p) {
  Crow* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a4, ES_UNK_0);
    q->unk_671 = (Random() & 127) + 20;
  }
  if (!Crow_TestUnk658(q, 4) && !(p->e).unk_608(&p->e)) {
    if ((p->e).subStateTimer > q->unk_671 && (p->e).animForceRestart) {
      Enemy_ResetState(&p->e, 0, 0, 2);
    } else {
      (p->e).subStateTimer++;
    }
  }
}

void FUN_08143ef8(Crow* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_08143094, ES_UNK_34);
  }
  (p->e).unk_608(&p->e);
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

// 向いている向きへ一定の速さで飛ぶ, 一定時間が過ぎてからプレイヤーに近づきすぎたか前方 90 度から外れたら副状態1へ戻る
void FUN_08143fac(Crow* p) {
  Crow* q = (p->e).unk_1cc;
  s32 limit;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    ((EnemyAuxSpriteData*)(p->e).sprite)->sprite.flags &= ~SPRFLAG_AFFINE;
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
  }
  limit = (p->e).variant == 1 ? 24 : 40;
  if ((p->e).subStateTimer > limit && (q->unk_664 > (p->e).unk_1e4 || Crow_GetAngleDiffToPlayer(p) > 64)) {
    Enemy_ResetState(&p->e, 0, 0, 1);
  } else {
    Vec3 v;

    Vec3_SetPolar(&v, (p->e).mover.angle, q->unk_660);
    (p->e).mover.delta = v;
    (p->e).subStateTimer++;
  }
}

void FUN_0814414c(Crow* p) { (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad828; }

void FUN_08144160(Crow* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && gPlayerPtr[0] != NULL) {
    Crow* q = (p->e).unk_1cc;

    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 3);
    CLEAR_FLAGS(q->unk_658, 4);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
}

NAKED void Crow_OnReset(Crow* p) { INCFUNC("asm/func/Crow_OnReset.inc"); }

NAKED void FUN_08144414(Crow* p) { INCFUNC("asm/func/FUN_08144414.inc"); }

void Crow_PickRandomPathNode(Crow* p) {
  PathWalker* walker = &(p->e).pathWalker;
  u8 idx = Mod(Random(), walker->path->nodeCount);

  if (idx == walker->nodeIdx) {
    idx = Mod(idx + 1, walker->path->nodeCount);
  }
  walker->nodeIdx = idx;
  walker->waitTimer = 0;
  walker->node = Map_GetPathNodes(walker->path) + walker->nodeIdx;
}

void Crow_InitHitboxes(Crow* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 42, 96, 42);
  VEC3_SET(hurtOffset, 0, 0, 0);
  Enemy_RegisterHurtbox(&p->e, &hurtSize, &hurtOffset, Crow_OnHurt, p);
  VEC3_SET(hitSize, 16, 84, 16);
  VEC3_SET(hitOffset, 0, 0, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Crow_OnHit, 0, p);
}

// 状態に入ってからの時間が経つほど移動を速くする
s32 Crow_GetMoveSpeed(Crow* p) {
  s32 t = (p->e).subStateTimer;
  s32 i;

  if (t < 30) {
    i = 0;
  } else if (t < 50) {
    i = 1;
  } else if (t < 70) {
    i = 2;
  } else {
    i = 3;
  }
  return u32_ARRAY_085ad83c[i];
}

void Crow_SetCurve(Crow* p, Vec3* pos) {
  Crow* q = (p->e).unk_1cc;

  q->curveStart = (p->e).mover.pos;
  q->curveEnd = *pos;
}

void Crow_InitAnims(Crow* p) {
  Enemy_SetAnimEntry(&p->e, 0, 4, 0);
  Enemy_SetAnimEntry(&p->e, 1, 0, 0);
  Enemy_SetAnimEntry(&p->e, 2, 2, 0);
  Enemy_SetAnimEntry(&p->e, 3, 3, 0);
  Enemy_SetAnimEntry(&p->e, 15, 1, 0);
  Enemy_SetAnimEntry(&p->e, 16, 6, 0);
  Enemy_SetAnimEntry(&p->e, 17, 7, 0);
  Enemy_SetAnimEntry(&p->e, 18, 5, 0);
  Enemy_SetAnimEntry(&p->e, 10, 3, 0);
}

// 残差は q と flags2 のアドレスの r1/r2 入れ替えのみ, 試済: q のローカル有無, Enemy_SetFlag2
NON_MATCH void FUN_081447cc(Crow* p) {
#ifdef NONMATCHING_C
  Crow* q = (p->e).unk_1cc;

  Enemy_SetFlag2(&p->e, ENEFLAG2_UNK_20);
  q->unk_658 &= ~1;
  (p->e).atkHitbox.flags &= ~HBFLAG_HIDDEN;
#else
  INCFUNC("asm/func/FUN_081447cc.inc");
#endif
}

// 8方向の向きを, 左右反転で済む5方向とその反転の有無に分ける
void Crow_GetDirAndFlip(u16 angle, s32* outDir, s32* outFlip) {
  s32 dir = Angle_ToDir8(angle);

  if (dir > 4) {
    *outDir = 8 - dir;
    *outFlip = 1;
  } else {
    *outDir = dir;
    *outFlip = 0;
  }
}

void Crow_BeginCurveMove(Crow* p, Vec3* pos) {
  Crow* q = (p->e).unk_1cc;
  Vec3 diff;

  Crow_SetCurve(p, pos);
  Enemy_ResetState(&p->e, 0, 0, 1);
  Vec3_Diff(&diff, pos, &(p->e).mover.pos);
  (p->e).unk_1dc = ArcTan2_8(diff.x, diff.z);
  Vec3_Clear(&q->unk_6b0);
}

void FUN_081448d8(Crow* p) {
  CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_8);
  CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_26);
  (p->e).unk_24e = 0;
}

void FUN_08144910(Crow* p) {
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    (p->e).unk_24e = 0;
    return;
  }
  if ((p->e).unk_24e != 0) {
    (p->e).unk_24e--;
    return;
  }
  Crow_PickRandomPathNode(p);
  {
    WorldPos pos;
    WorldPos* dst = &pos;
    PathWalker* walker = &(p->e).pathWalker;

    dst->x = walker->node->x;
    dst->z = walker->node->y;
    dst->y = TileHeightAt(dst);
    Crow_BeginCurveMove(p, &pos);
    FUN_081448d8(p);
  }
}

// 状態36の間, 次のフレームの位置のタイルが足元より高ければ壁として速さを止め, 床より低くなるなら縦の速さだけ止める
// 172/172命令まで寄せた形は Vec3_Sum(&next, &jumpVel, &pos) と Vec3_Sum(&next, &delta, &next) (引数の向きが不自然), それでも q が r6 (原典 r7) で, &pos の作り置きが jumpVel より後になる, 試済: 各成分を pos/vel ポインタで直書き (180命令)
NON_MATCH void FUN_081449f8(Crow* p) {
#ifdef NONMATCHING_C
  Crow* q = (p->e).unk_1cc;

  CLEAR_FLAGS(q->unk_658, 2);
  if ((p->e).state == ES_UNK_36) {
    WorldPos next;
    s32 height;

    Vec3_Sum(&next, &(p->e).mover.pos, &(p->e).jumpVel);
    Vec3_Add(&next, &(p->e).mover.delta);
    height = TileHeightAt(&next);
    if ((p->e).heightAboveFloor + (p->e).floorY < height) {
      (p->e).jumpVel.x = 0;
      (p->e).jumpVel.y = 0;
      (p->e).jumpVel.z = 0;
      q->unk_6b0.x = 0;
      q->unk_6b0.y = 0;
      q->unk_6b0.z = 0;
      (p->e).mover.delta.x = 0;
      (p->e).mover.delta.z = 0;
      (p->e).mover.delta.y = 0;
      q->unk_658 |= 2;
    }
    if (next.y < height) {
      (p->e).jumpVel.y = 0;
      (p->e).mover.delta.y = 0;
      q->unk_6b0.y = 0;
    }
  }
#else
  INCFUNC("asm/func/FUN_081449f8.inc");
#endif
}

void Crow_PlayWingSound(Crow* p) {
  AuxAnimState* anim = &((EnemyAuxSpriteData*)(p->e).sprite)->anim;

  if (anim->cmdIdx == 5 && anim->tick == 0) {
    PlaySound_082406e0(CRY_CROW_WING);
  }
}

// 的を探してよい番で, 高さが近いプレイヤーが索敵範囲に入っていれば攻撃の要求を立てる
bool8 FUN_08144b90(Crow* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    s32 dy = abs((p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y);

    if (dy <= 512 && (p->e).unk_1e4 < (p->e).range0Sq) {
      goto found;
    }
  }
  return FALSE;

found:
  SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_7);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_27);
  return TRUE;
}

void FUN_08144bfc(Crow* p) {
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    (p->e).unk_24e = (p->e).unk_24c;
  } else if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 3);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
}

s32 FUN_08144cb8(Crow* p) {
  FUN_08144414(p);
  return 1;
}

s32 FUN_08144cc4(Crow* p) {
  FUN_081449f8(p);
  return 1;
}

// 足元が壁や落下死のタイルでなければ, 4 フレームごとに半分になる速さで上へ飛び上がり, 止まったら副状態 (0,2,1) へ移る
void FUN_08144cd0(Crow* p) {
  Crow* q = (p->e).unk_1cc;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_081432ec, ES_UNK_37);
    q->unk_6b0.y = 30;
  }
  if (TEST_FLAGS(TileAtIndex((p->e).unk_256)->attr, TATTR_WALL | TATTR_FALLDEATH)) {
    if ((p->e).subStateTimer > 20) {
      Enemy_ResetState(&p->e, 0, 0, 4);
      return;
    }
  } else {
    Enemy_UpdateWalkAnimSpeed(&p->e);
    (p->e).heightAboveFloor += q->unk_6b0.y;
    if (Mod((p->e).subStateTimer, 4) == 0) {
      q->unk_6b0.y = FixToInt(1, q->unk_6b0.y);
    }
    if (q->unk_6b0.y <= 0) {
      Enemy_ResetState(&p->e, 0, 2, 1);
      return;
    }
  }
  (p->e).subStateTimer++;
}

NAKED void FUN_08144ec8(Crow* p) { INCFUNC("asm/func/FUN_08144ec8.inc"); }

void FUN_081452cc(Crow* p) {
  s32 d;
  s32 y;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).unk_5a0, ES_UNK_1);
    (p->e).mover.angle += 128;
  }
  (p->e).unk_608(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  d = (p->e).floorY;
  y = (p->e).mover.pos.y - 320;
  d -= y;
  if (d < 0) {
    d = -d;
  }
  if (d <= 16 && (p->e).subStateTimer > 80) {
    Enemy_ResetState(&p->e, 0, 0, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_08145424(Crow* p) { (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad84c; }

s32 FUN_08145438(Crow* p) {
  FUN_08144cb8(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];
    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  FUN_08144cc4(p);
  return 1;
}

s32 Crow_Update(Crow* p) {
  (p->e).playerMover = &gPlayerPtr[0]->mover;
  Enemy_Update(&p->e);
  return 0;
}

s32 Crow_Destroy(Crow* p) {
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
NAKED s32 Crow_Init(Crow* p) { INCFUNC("asm/func/Crow_Init.inc"); }

void Crow_Create(void) {
  Crow* p = Malloc(sizeof(Crow));

  if (p != NULL) {
    ClearMemory(p, sizeof(Crow));
    if (Crow_Init(p) < 0) {
      Crow_Destroy(p);
      Free(p);
    }
  }
}
