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

// ENEK_CROW (EV_CROW, EV_GARGOYLE)
typedef struct {
  Enemy e;
  u8 unk_654[0x658 - 0x654];  // 0x654
  u32 unk_658;                // 0x658
  u8 unk_65c;                 // 0x65C, 羽ばたきアニメを流した回数
  u8 unk_65d;                 // 0x65D, 急降下の速さ
  u16 unk_65e;                // 0x65E
  u8 unk_660;                 // 0x660, プレイヤーへ直進するときの速さ
  u8 unk_661;                 // 0x661
  u16 unk_662;                // 0x662, 帰巣位置の床の高さ
  u32 unk_664;                // 0x664, playerDistSq がこれ以上ならプレイヤーへの直進を続ける
  u8 unk_668;                 // 0x668
  u8 unk_669[3];              // 0x669
  u16 homeTileIdx;            // 0x66C, homePos のタイル索引
  s16 unk_66e;                // 0x66E, 配置時の高さ
  u8 unk_670;                 // 0x670
  u8 unk_671;                 // 0x671, 鳴くたびに 40 ずつ増える
  u8 unk_672;                 // 0x672
  u8 unk_673;                 // 0x673
  NavAgent navAgent;          // 0x674, Enemy.navAgent が指す
  Vec3 pathNodePos;           // 0x698, Enemy.pathNodePos が指す
  WorldPos curveStart;        // 0x6A0, 曲線の始点
  Vec3 curveEnd;              // 0x6A8, 曲線の終点
  Vec3 unk_6b0;               // 0x6B0, 曲線移動を始めるときに 0 に戻す
  WorldPos homePos;           // 0x6B8, 復帰したときに戻る位置
  u8 unk_6c0[1728 - 0x6C0];   // 0x6C0
} Crow;
static_assert(sizeof(Crow) == 1728);

void Crow_PlayWingSound(Crow*);
void Crow_GetDirAndFlip(u16 angle, s32* outDir, s32* outFlip);
void FUN_081447cc(Crow*);

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

// 当たった相手が HIM_0 だけを無視する判定のときだけ攻撃対象として覚える
void Crow_OnHit(HitboxData* a, HitboxData* b, Crow* p) {
  if (b->ignoreMask == HIM_0 && Enemy_IsDead(&p->e) == 0) {
    if ((b->ignoreMask & (HIM_0 | HIM_1 | HIM_2 | HIM_3)) != 0) {
      (p->e).hitTargetID = b->id;
      Enemy_ClearFlag2(&p->e, ENEFLAG2_UNK_24);
    }
  }
}

// 食らい判定, 共通処理のあとノックバックを 0〜15 減らし 20 を下限にする
// 791/796命令, ノックバックの種別判定で TRUE 側ブロックが属性検査より前に来る配置と p->angle の格納先を分岐ごとに計算する形が合わない, 末尾は原典が乱数を先に読む (knockback に Random() を入れてから引くと揃うが不自然なので採らず)
NON_MATCH void Crow_OnHurt(HitboxData* a, HitboxData* b, Crow* p) {
#ifdef NONMATCHING_C
  s32 knockback;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if (Hitbox_TestFlags(a, HBFLAG_UNK_11)) {
    return;
  }
  Enemy_HandleHurt(a, b, &p->e);
  knockback = b->knockback - (Random() & 15);
  b->knockback = knockback < 20 ? 20 : knockback;
#else
  INCFUNC("asm/func/Crow_OnHurt.inc");
#endif
}

void FUN_08142fd8(Crow* p) {
  Enemy_ConsumeStateBegun(&p->e);
  Enemy_PlayAnim(&p->e, 1);
  Crow_PlayWingSound(p);
}

void FUN_08143004(Crow* p, s32 timer) {
  Crow* q = (p->e).owner;

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
  Crow* q = (p->e).owner;

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
      EnemyAuxSprite* s;

      (p->e).playingAnim = anim;
      s = &(p->e).s->aux;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, 0, 0);
      (p->e).animForceRestart = FALSE;
    } else {
      MainSprite* s = &(p->e).s->main.spr;
      u16 a = anim + 0;

      if ((p->e).playingAnim != a || (p->e).animForceRestart || (s->flags & SPRFLAG_XFLIP)) {
        (p->e).playingAnim = a;
        MainSprite_SetAnim(&(p->e).s->main.spr, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
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
      EnemyAuxSprite* s = &(p->e).s->aux;

      (p->e).playingAnim = anim;
      AuxAnim_SetAnim(&s->anim, s->animFile, anim, dir, flip);
    } else {
      MainSprite* s = &(p->e).s->main.spr;
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
      MainSprite_SetAnim(s, &(p->e).s->main.gfx, a, PLAYMODE_ONCE_AND_STOP, (flip & ANIM_PLAY_REVERSE) ? (MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE) : MAIN_ANIM_FORCE_POSE);
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

// 被弾して後ろへ滑る状態, 滑り終えて 30 フレーム過ぎたら少し無敵を足して止まる
void Crow_StateDamaged(Crow* p, s32 timer) {
  Crow* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    Enemy_PlayAnim(&p->e, 3);
  }
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  if (timer < 20) {
    SET_FLAGS((p->e).flags4, ENEFLAG4_UNK_5);
  }
  if (Enemy_StepSlide(&p->e) && timer > 30) {
    (p->e).hurtbox.iframes += 10;
    (p->e).subStateDone = 1;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    q->unk_670 = 0;
    FUN_081447cc(p);
    (p->e).mover.angle = (p->e).playerAngle;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 1);
    (p->e).mover.angle = (p->e).playerAngle;
    (p->e).animSpeedDiv = 1;
  }
}

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
  if (Sprite_UpdateVanishBlink(&(p->e).s->aux.spr.flags, timer, 10, 30)) {
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
    if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_10)) {
      FUN_080e6658(&p->e);
    }
    (p->e).sleepTimer = 0;
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 1, 0, 2);
    ParticleShadow_Hide(&(p->e).shadow);
  }
}

// homePos のタイルの中で乱数の向きへ小さく跳ね, 着地したら副状態 (0,0,0) へ戻る
// 339/336命令, 原典は q を sl, 床の高さを r10 に置き &subStateBegun をスタックに退避する, こちらは q を r9 に置いて状態の格納の一時レジスタ番号もずれる, 試済: 宣言と代入を分ける (悪化)
NON_MATCH void FUN_081436b4(Crow* p) {
#ifdef NONMATCHING_C
  Crow* q = (p->e).owner;
  s32 floor = TileHeightAtIndex((p->e).tileIdx, &(p->e).mover.pos);

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    WorldPos home;
    u8 angle;
    s32 speed;

    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    TilePosAtIndex(&home, q->homeTileIdx);
    angle = RandomNext();
    (p->e).mover.angle = angle;
    Vec3_Clear(&q->unk_6b0);
    speed = (RandomNext() & 7) + 1;
    Vec3_SetPolar(&q->unk_6b0, angle, speed);
    q->unk_6b0.y = 14;
  }
  if (!(p->e).tryDetectPlayer(&p->e)) {
    WorldPos next;

    Vec3_Sum(&next, &(p->e).mover.pos, &q->unk_6b0);
    if (q->homeTileIdx != GetCollisionTileIdx(&next)) {
      q->unk_6b0.x = 0;
      q->unk_6b0.z = 0;
    }
    (p->e).mover.delta.x += q->unk_6b0.x;
    (p->e).mover.delta.z += q->unk_6b0.z;
    (p->e).heightAboveFloor += q->unk_6b0.y;
    q->unk_6b0.y -= 2;
    if ((p->e).heightAboveFloor > floor) {
      (p->e).subStateTimer++;
    } else {
      (p->e).mover.pos.y = floor;
      (p->e).heightAboveFloor = floor;
      Vec3_Clear(&q->unk_6b0);
      Enemy_ResetState(&p->e, 0, 0, 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_081436b4.inc");
#endif
}

// 前進しながら旋回する, unk_65e フレームを過ぎたらプレイヤーへ向き直って副状態 (0,2,0) へ, それまでは近ければプレイヤーから横へ逸れ遠ければプレイヤーへ向く
void FUN_081439d8(Crow* p) {
  Crow* q = (p->e).owner;
  Vec3 diff;
  s32 target;
  s32 speed;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).s->aux.spr.flags |= SPRFLAG_AFFINE;
    Enemy_EnterState(&p->e, (p->e).handlerTurn, ES_UNK_2);
  }
  if (q->unk_65e < (p->e).subStateTimer) {
    s32 d;
    s32 dist;

    Vec3_Delta(&diff, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
    target = ArcTan2_8(diff.x, diff.z);
    d = target - (p->e).mover.angle;
    if (d > 128) {
      d -= 256;
    } else if (d < -128) {
      d += 256;
    }
    dist = abs(d);
    if (dist < 12) {
      q->unk_668 = 0;
      (p->e).s->aux.spr.flags &= ~SPRFLAG_AFFINE;
      Enemy_ResetState(&p->e, 0, 2, 0);
      return;
    }
    speed = FixToInt(2, dist);
    speed = speed > 0 ? speed : 4;
    if (speed > 8) {
      speed = 8;
    }
    if (q->unk_668 > 20) {
      q->unk_668 = 0;
      q->unk_661 = 0;
      Enemy_ResetState(&p->e, 0, 0, 4);
      return;
    }
    q->unk_668++;
    q->unk_661 = 0;
  } else {
    if ((p->e).playerDistSq < 32000) {
      Enemy_ResetState(&p->e, 0, 0, 4);
      return;
    }
    if (q->unk_664 > (p->e).playerDistSq) {
      s32 d;
      s32 dist;

      Vec3_Delta(&diff, &gPlayerPtr[0]->mover.pos, &(p->e).mover.pos);
      target = ArcTan2_8(diff.x, diff.z);
      d = ((target + 64) & 0xFF) - (p->e).mover.angle;
      if (d > 128) {
        d -= 256;
      } else if (d < -128) {
        d += 256;
      }
      dist = abs(d);
      if (dist < 64) {
        target += 64;
      } else {
        target += 192;
      }
      target &= 0xFF;
      speed = Div(q->unk_660, 8);
      if (speed <= 0) {
        speed = 2;
      }
    } else {
      s32 d;
      s32 dist;

      Vec3_Delta(&diff, &(p->e).mover.pos, &gPlayerPtr[0]->mover.pos);
      target = ArcTan2_8(diff.x, diff.z);
      d = target - (p->e).mover.angle;
      if (d > 128) {
        d -= 256;
      } else if (d < -128) {
        d += 256;
      }
      dist = abs(d);
      if (dist < 32) {
        Enemy_ResetState(&p->e, 0, 0, 4);
        return;
      }
      speed = FixToInt(3, dist);
      speed = speed > 0 ? speed : 2;
    }
    if (speed > 6) {
      speed = 6;
    }
  }
  {
    Vec3 v;

    Vec3_SetPolar(&v, (p->e).mover.angle, q->unk_660);
    (p->e).mover.delta = v;
    if (q->unk_661 == 0) {
      s32 d = target - (p->e).mover.angle;

      if (d > 128) {
        d -= 256;
      } else if (d < -128) {
        d += 256;
      }
      if (d > 0) {
        (p->e).mover.angle += speed;
      } else {
        (p->e).mover.angle -= speed;
      }
      (p->e).s->aux.spr.rotation = 159 - (p->e).mover.angle;
      if ((p->e).variant == 0) {
        q->unk_661 = 4;
      } else {
        q->unk_661 = 2;
      }
    }
    if (q->unk_661 != 0) {
      q->unk_661--;
    }
  }
  (p->e).subStateTimer++;
}

void FUN_08143dd4(Crow* p) {
  Crow* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerWait, ES_UNK_0);
    q->unk_671 = (Random() & 127) + 20;
  }
  if (!Crow_TestUnk658(q, 4) && !(p->e).tryDetectPlayer(&p->e)) {
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
  (p->e).tryDetectPlayer(&p->e);
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

// 向いている向きへ一定の速さで飛ぶ, 一定時間が過ぎてからプレイヤーに近づきすぎたか前方 90 度から外れたら副状態1へ戻る
void FUN_08143fac(Crow* p) {
  Crow* q = (p->e).owner;
  s32 limit;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).s->aux.spr.flags &= ~SPRFLAG_AFFINE;
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
  }
  limit = (p->e).variant == 1 ? 24 : 40;
  if ((p->e).subStateTimer > limit && (q->unk_664 > (p->e).playerDistSq || Crow_GetAngleDiffToPlayer(p) > 64)) {
    Enemy_ResetState(&p->e, 0, 0, 1);
  } else {
    Vec3 v;

    Vec3_SetPolar(&v, (p->e).mover.angle, q->unk_660);
    (p->e).mover.delta = v;
    (p->e).subStateTimer++;
  }
}

void FUN_0814414c(Crow* p) {
  static void (*const PTR_ARRAY_085ad828[5])(Crow*) = {
      FUN_08143dd4,
      FUN_081439d8,
      FUN_081436b4,
      FUN_08143ef8,
      FUN_08143fac,
  };  // 0x085AD828
  (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ad828;
}

void FUN_08144160(Crow* p, u16* msg) {
  if (!Enemy_IsDead(&p->e) && gPlayerPtr[0] != NULL) {
    Crow* q = (p->e).owner;

    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 3);
    CLEAR_FLAGS(q->unk_658, 4);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
}

// 復帰時に作業値を消して homePos へ戻し, 床の高さを取り直して待機アニメを流して1コマ送る
void Crow_OnReset(Crow* p) {
  Crow* q = (p->e).owner;
  EnemyAuxSprite* aux;

  q->unk_65c = 0;
  q->unk_672 = 0;
  q->unk_673 = 0;
  q->unk_661 = 0;
  q->unk_668 = 0;
  q->unk_658 = 0;
  (p->e).mover.pos = q->homePos;
  (p->e).tileIdx = q->homeTileIdx;
  (p->e).floorY = TileHeightAtIndex((p->e).tileIdx, &q->homePos);
  (p->e).heightAboveFloor = (p->e).mover.pos.y;
  (p->e).mover.pos.y = (p->e).floorY;
  Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
  Vec3_Clear(&q->curveStart);
  Vec3_Clear(&q->curveEnd);
  Vec3_Clear(&q->unk_6b0);
  Enemy_PlayAnim(&p->e, 0);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
}

// 高さの更新, 状態34ではタイルの上 320 まで sin で上昇し, 飛んでいる間は床から 320 の高さを保ち, 状態1/2では羽ばたきのコマに合わせて絵を上下させる
void Crow_UpdateHover(Crow* p) {
  Crow* q = (p->e).owner;
  s32 d;
  s32 y;

  if (Enemy_IsDead(&p->e)) {
    return;
  }
  if ((p->e).state == ES_UNK_0 || (p->e).state == ES_UNK_36 || (p->e).state == ES_UNK_37) {
    (p->e).mover.pos.y = (p->e).heightAboveFloor;
    return;
  }
  if (!TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_20)) {
    (p->e).mover.pos.y = (p->e).heightAboveFloor;
    return;
  }
  if ((p->e).state == ES_UNK_34) {
    s32 floor = (GetTileAt(&(p->e).mover.pos)->heightStairs & 0xF) << 8;

    if ((p->e).heightAboveFloor < floor + 320) {
      (p->e).heightAboveFloor += FixToInt(12, SIN(q->unk_670) * 8);
      if (q->unk_670 < 64) {
        q->unk_670++;
      }
    }
    (p->e).mover.pos.y = (p->e).heightAboveFloor;
    return;
  }
  d = (p->e).floorY;
  y = (p->e).mover.pos.y - 320;
  d -= y;
  if (abs(d) > 16) {
    if (d < 0) {
      (p->e).heightAboveFloor -= 2;
    } else {
      (p->e).heightAboveFloor += 2;
    }
  }
  (p->e).mover.pos.y = (p->e).heightAboveFloor;
  if ((u8)((p->e).state - 1) <= 1) {
    AuxSprite* sprite = &(p->e).s->aux.spr;
    AuxAnimState* anim = &(p->e).s->aux.anim;

    switch (anim->cmdIdx) {
      case 0: {
        sprite->pos.y += 24;
        break;
      }
      case 1: {
        sprite->pos.y += 24 + anim->tick * 4;
        break;
      }
      case 2: {
        sprite->pos.y += 62 - anim->tick * 12;
        break;
      }
      case 3: {
        sprite->pos.y += 2 - anim->tick * 8;
        break;
      }
      case 4: {
        sprite->pos.y += -22 + anim->tick * 7;
        break;
      }
    }
  }
}

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
  static const u32 u32_ARRAY_085ad83c[4] = {4, 6, 8, 10};  // 0x085AD83C

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
  Crow* q = (p->e).owner;

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

void FUN_081447cc(Crow* p) {
  Crow* q = (p->e).owner;

  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  CLEAR_FLAGS(q->unk_658, 1);
  (p->e).hitbox.flags &= ~HBFLAG_HIDDEN;
}

// 8方向の向きを, 左右反転で済む5方向とその反転の有無に分ける
void Crow_GetDirAndFlip(u16 angle, s32* outDir, s32* outFlip) {
  s32 dir = Angle_ToDir8(angle);
  if (IS_8DIR_LEFT(dir)) {
    *outDir = 8 - dir;
    *outFlip = TRUE;
  } else {
    *outDir = dir;
    *outFlip = FALSE;
  }
}

void Crow_BeginCurveMove(Crow* p, Vec3* pos) {
  Crow* q = (p->e).owner;
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
  (p->e).chaseTimer = 0;
}

void FUN_08144910(Crow* p) {
  if (!TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    (p->e).chaseTimer = 0;
    return;
  }
  if ((p->e).chaseTimer != 0) {
    (p->e).chaseTimer--;
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
  Crow* q = (p->e).owner;

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
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (anim->cmdIdx == 5 && anim->tick == 0) {
    PlaySound_082406e0(CRY_CROW_WING);
  }
}

// 的を探してよい番で, 高さが近いプレイヤーが索敵範囲に入っていれば攻撃の要求を立てる
bool8 FUN_08144b90(Crow* p) {
  if (TEST_FLAGS((p->e).flags, ENEFLAG_UNK_3)) {
    s32 dy = abs((p->e).mover.pos.y - gPlayerPtr[0]->mover.pos.y);

    if (dy <= 512 && (p->e).playerDistSq < (p->e).range0Sq) {
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
    (p->e).chaseTimer = (p->e).chaseTimeMax;
  } else if (!TEST_FLAGS((p->e).flags, ENEFLAG_UNK_26)) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 3);
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_26);
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_20);
  }
}

s32 FUN_08144cb8(Crow* p) {
  Crow_UpdateHover(p);
  return 1;
}

s32 FUN_08144cc4(Crow* p) {
  FUN_081449f8(p);
  return 1;
}

// 足元が壁や落下死のタイルでなければ, 4 フレームごとに半分になる速さで上へ飛び上がり, 止まったら副状態 (0,2,1) へ移る
void FUN_08144cd0(Crow* p) {
  Crow* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, FUN_081432ec, ES_UNK_37);
    q->unk_6b0.y = 30;
  }
  if (TEST_FLAGS(TileAtIndex((p->e).tileIdx)->attr, TATTR_WALL | TATTR_FALLDEATH)) {
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

// プレイヤーへ急降下する副状態, 入ったときに着くまでのフレーム数から落ちる速さを決め, 着いたら勢いを残して副状態 (0,2,2) へ移る
// 433/438命令, 1回目の下書き, 原典は q を r7 に置き, 入場の速さの割り算の比べ方や Vec3_SetPolar の展開の並びがまだ違う
NON_MATCH void Crow_SwoopAtPlayer(Crow* p) {
#ifdef NONMATCHING_C
  Crow* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Vec3 d;

    Enemy_EnterState(&p->e, FUN_081431e0, ES_UNK_36);
    (p->e).navAgent->dest = gPlayerPtr[0]->mover.pos;
    Vec3_Clear(&q->unk_6b0);
    Vec3_Delta(&d, &(p->e).mover.pos, &(p->e).navAgent->dest);
    (p->e).mover.angle = ArcTan2_8(d.x, d.z);
    Vec3_SetPolar(&q->unk_6b0, (p->e).mover.angle, q->unk_65d);
    if (q->unk_6b0.x != 0) {
      q->unk_6b0.x = Div(d.x, q->unk_6b0.x);
    }
    if (q->unk_6b0.z != 0) {
      q->unk_6b0.z = Div(d.z, q->unk_6b0.z);
    }
    if (q->unk_6b0.x > q->unk_6b0.z) {
      if (q->unk_6b0.x != 0) {
        q->unk_6b0.y = Div(d.y - 32, q->unk_6b0.x);
      }
    } else if (q->unk_6b0.z != 0) {
      q->unk_6b0.y = Div(d.y - 32, q->unk_6b0.z);
    }
    PlaySound_082406e0(CRY_CROW_ATK);
    q->unk_670 = 0;
  }
  (p->e).tryDetectPlayer(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  (p->e).heightAboveFloor += q->unk_6b0.y;
  if (Mod((p->e).subStateTimer, 6) == 0) {
    q->unk_6b0.y = FixToInt(1, q->unk_6b0.y);
  }
  if (Enemy_StepToDest(&p->e, q->unk_65d) || Crow_TestUnk658(q, 2)) {
    (p->e).jumpVel.x = POLAR_X(q->unk_65d * 2, (p->e).mover.angle);
    (p->e).jumpVel.z = POLAR_Z(q->unk_65d * 2, (p->e).mover.angle);
    Enemy_ResetState(&p->e, 0, 2, 2);
  } else {
    (p->e).subStateTimer++;
  }
#else
  INCFUNC("asm/func/Crow_SwoopAtPlayer.inc");
#endif
}

void FUN_081452cc(Crow* p) {
  s32 floorY;
  s32 y;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, (p->e).handlerMove, ES_UNK_1);
    (p->e).mover.angle += 128;
  }
  (p->e).tryDetectPlayer(&p->e);
  Enemy_UpdateWalkAnimSpeed(&p->e);
  floorY = (p->e).floorY;
  y = (p->e).mover.pos.y - Q8(1.25);
  if (abs(floorY - y) <= Q8(0.063) && (p->e).subStateTimer > 80) {
    Enemy_ResetState(&p->e, 0, 0, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_08145424(Crow* p) {
  static void (*const PTR_ARRAY_085ad84c[3])(Crow*) = {
      FUN_08144cd0,
      Crow_SwoopAtPlayer,
      FUN_081452cc,
  };  // 0x085AD84C
  (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ad84c;
}

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

// Enemy全体で利用されるinline関数が展開されていてサイズが膨れ上がっている, なので エネミー全体の XXX_Init を一通り NON_MATCH にして共通部分を見てから本格的に一致を目指した方が良さそう
// 1767/1909命令, Mimic_Init の下書きを Crow 向けに直したもの (呼び出し列は一致), 原典はフレーム 0x1A4 に Enemy のフィールドのアドレスを作り置く (敵共通の初期化 inline), こちらはフレーム 0x44
NON_MATCH s32 Crow_Init(Crow* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  p->unk_658 = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_CROW;
  Crow_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_CROW);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_CROW);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_CROW);
    spr->gfx = *f;
    OpenMainSpriteFile(&spr->gfx, f);
    MainSprite_Add(&spr->spr, &spr->gfx, 0, 0, 2, 2, 60, &origin);
    (p->e).playingAnim = 0xFF;
  }

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
  if (VM_SeekToNamedArg('P')) {
    u16 wait;

    p->unk_664 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_660 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_65d = VM_GetPC() != NULL ? VM_GetValue() : 0;
    wait = Random() & 63;
    if (VM_GetPC() != NULL) {
      wait += VM_GetValue();
    }
    p->unk_65e = wait;
    if (VM_GetPC() != NULL && VM_GetValue() != 0) {
      p->unk_658 |= 4;
    }
    p->unk_664 *= p->unk_664;
  }
  (p->e).mover.angle = VM_GetNamedArgValue('d', 0);
  if (VM_SeekToNamedArg('p')) {
    (p->e).mover.pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    (p->e).mover.pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->homePos = (p->e).mover.pos;
    (p->e).tileIdx = GetCollisionTileIdx(&p->homePos);
    (p->e).floorY = TileHeightAt(&p->homePos);
    (p->e).heightAboveFloor = (p->e).mover.pos.y;
    p->unk_66e = (p->e).mover.pos.y;
    (p->e).mover.pos.y = (p->e).floorY;
    p->homeTileIdx = (p->e).tileIdx;
    p->unk_662 = (p->e).floorY;
  }

  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 332;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 335;
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

  Crow_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)FUN_08145438;
  (p->e).getMoveSpeed = (void*)Crow_GetMoveSpeed;
  (p->e).handlerTurn = FUN_0814312c;
  (p->e).handlerMove = FUN_08142fd8;
  (p->e).handlerWait = FUN_08143004;
  (p->e).unk_5c0 = NULL;
  (p->e).onRouteFailed = (EnemyHandler)FUN_080f62b0;
  (p->e).handlerDamaged = Crow_StateDamaged;
  (p->e).handlerDying = Crow_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = NULL;
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
  (p->e).msgHandlers = (void*)PTR_ARRAY_085ad858;
  (p->e).onReset = (EnemyHandler)Crow_OnReset;
  (p->e).unk_5fc = NULL;
  (p->e).onAttackRequest = (EnemyHandler)FUN_08144bfc;
  (p->e).unk_5b0 = NULL;
  (p->e).tryDetectPlayer = (void*)FUN_08144b90;
  (p->e).onDamaged = (void*)FUN_080f8400;
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_10 | ENEFLAG2_UNK_20 | ENEFLAG2_UNK_25);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_5 | ENEFLAG5_UNK_6);
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
  Enemy_InitHandlerTables(&p->e);
  FUN_0814414c(p);
  FUN_08145424(p);
  (p->e).unk_1bc = 2;
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
  (p->e).handlerUpdate = (EnemyHandler)Crow_Update;
  (p->e).handlerDestroy = (EnemyHandler)Crow_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Crow_Init.inc");
#endif
}

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
