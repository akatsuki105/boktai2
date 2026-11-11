#include "cwolf_target.h"
#include "eff_elemcond.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "global.h"
#include "link_session.h"
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

// 暗黒の根, ENEK_DARKROOT(ENEID_DARKROOT)
// 地面から生えた触手型の敵, ダーク属性での攻撃でしか倒せない
typedef u32 DarkRootFlags;
#define DARKFLAG_WITHERED (1 << 0)  // 0x00000001, 枯れさせるメッセージを受けた, 立っていると食らい判定もメッセージも受けない
#define DARKFLAG_GRABBING (1 << 1)  // 0x00000002, 相手を掴んでいる, 放すときに落とす

typedef struct {
  Enemy e;
  u8 unk_654[12];       // 0x654
  DarkRootFlags flags;  // 0x660, see DarkRootFlags
  u8 unk_664[4];        // 0x664
  s16 lostTimer;        // 0x668, 隣のタイルに相手がいないフレーム数, いれば 0 に戻す
  u16 unk_66a;          // 0x66A, '.P[0]'
  s16 regrowScriptID;   // 0x66C, '.d', 倒れて生え直すときに VM_ExecByID するスクリプト, 一度呼ぶと 0
  u8 unk_66e[2];        // 0x66E
  u8 mashCountBase;     // 0x670, 掴んだときのプレイヤーの mashCount
  u8 escapeMashCount;   // 0x671, '.P[2]', この回数を超えて連打されると放す
  u8 squeezeInterval;   // 0x672, '.P[1]', 締め付ける間隔のフレーム数
  u8 unk_673;           // 0x673
  NavAgent navAgent;    // 0x674, Enemy.navAgent が指す
  Vec3 pathNodePos;     // 0x698, Enemy.pathNodePos が指す
} DarkRoot;
static_assert(sizeof(DarkRoot) == 1696);

static inline bool8 DarkRoot_TestFlags(DarkRoot* p, DarkRootFlags bit) {
  if (p->flags & bit) return TRUE;
  return FALSE;
}

static inline void DarkRoot_SetFlags(DarkRoot* p, DarkRootFlags bits) { p->flags |= bits; }
static inline void DarkRoot_ClearFlags(DarkRoot* p, DarkRootFlags bits) { p->flags &= ~bits; }

s32 FUN_0803712c(Vec3* out);
s32 Entity081efa9c_Spawn(Vec3* pos, Vec3* vel, u32 spriteID, u32 animID, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12, s32 param_13, s32 param_14, s32 param_15);
void DefeatedEnemyLog_Add(u16 a, u16 b);
void Enemy_AddKillCount(Enemy* p);
s32 DarkRoot_GetGrabbedAnimOffset(DarkRoot* p);
void HUD_ShowEnemyGauge(s32 param_1, s32 param_2, u16 param_3, u16 param_4, s32 param_5);
void DarkRoot_StateRetract(DarkRoot* p);
void DarkRoot_StateHold(DarkRoot* p, s32 timer);
Mover* DarkRoot_FindAdjacentTarget(DarkRoot* p, s32 faceTarget);

// 掴んだ相手を持つ位置, Enemy_SetAnimFacing の flags ごとに 5 コマ分 (0x085ADBFC の先頭10要素と同じ中身)
const Vec3 vec3_ARRAY_085ade10[10] = {
    {82,  250, 0  },
    {112, 270, -5 },
    {118, 270, -5 },
    {118, 270, -5 },
    {92,  260, -5 },
    {-24, 250, 82 },
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106}
};  // 0x085ADE10

void FUN_081a483c(DarkRoot*);
void DarkRoot_SubHold(DarkRoot*);
void DarkRoot_SubReleaseGrab(DarkRoot*);
void DarkRoot_SubRetract(DarkRoot*);

void (*const PTR_ARRAY_085ade60[4])(DarkRoot*) = {
    FUN_081a483c,
    DarkRoot_SubHold,
    DarkRoot_SubReleaseGrab,
    DarkRoot_SubRetract,
};  // 0x085ADE60

void DarkRoot_SubWatch(DarkRoot*);
void DarkRoot_SubEmerge(DarkRoot*);
void DarkRoot_SubCooldown(DarkRoot*);
void DarkRoot_SubVanish(DarkRoot*);

void (*const PTR_ARRAY_085ade70[4])(DarkRoot*) = {
    DarkRoot_SubWatch,
    DarkRoot_SubEmerge,
    DarkRoot_SubCooldown,
    DarkRoot_SubVanish,
};  // 0x085ADE70

void FUN_081a4a44(DarkRoot*);
void DarkRoot_SubDeactivate(DarkRoot*);

void (*const PTR_ARRAY_085ade80[3])(DarkRoot*) = {
    FUN_081a4a44,
    (void*)FUN_080f1cb8,
    DarkRoot_SubDeactivate,
};  // 0x085ADE80

void DarkRoot_OnWitherMsg(DarkRoot*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085ade8c[7])(DarkRoot*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    DarkRoot_OnWitherMsg,
};  // 0x085ADE8C

// 枯れていなければ敵共通の被弾処理を行う
// 775/787命令, 敵共通の Enemy_HandleHurt だけ, Golem_OnHurt と同じ共通 inline の壁, 1回目の下書きで切り上げ
NON_MATCH void DarkRoot_OnHurt(HitboxData* a, HitboxData* b, DarkRoot* p) {
#ifdef NONMATCHING_C
  if (!Enemy_IsDead(&p->e) && !DarkRoot_TestFlags((p->e).owner, DARKFLAG_WITHERED)) {
    Enemy_HandleHurt(a, b, &p->e);
  }
#else
  INCFUNC("asm/func/DarkRoot_OnHurt.inc");
#endif
}

void DarkRoot_OnHit(HitboxData* a, HitboxData* b, DarkRoot* p) {}

void DarkRoot_StateWait(DarkRoot* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).s->aux.spr.priority = 2;
    (p->e).hurtbox.flags = ((p->e).hurtbox.flags & ~HBFLAG_HIDDEN) | HBFLAG_UNK_3;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  Enemy_PlayAnimFlipOnly(&p->e, 14);
}

void DarkRoot_StateEmerge(DarkRoot* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).s->aux.spr.priority = 2;
    (p->e).hurtbox.iframes = 0;
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    Enemy_PlayAnimFlipOnly(&p->e, 15);
    PlaySound_082406e0(SONG_475);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

void FUN_081a3360(DarkRoot* p) {}

void FUN_081a3364(DarkRoot* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).s->aux.spr.priority = 3;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_PlayAnimFlipOnly(&p->e, 20);
  }
}

// 地中から伸びて掴みかかる, 4コマ目で隣のタイルに相手がいれば掴んで状態36へ移り, いなければアニメの終わりに引っ込む (状態38)
// 316/327命令, 原典は持つ位置を WorldPos の DImode のまま x / y / z を書き換え (表を毎回引き直す), 状態の切り替えと定数 0 のレジスタ (r8 / sb) の割当も違う, 試済: 表の要素を指すポインタのローカル (302)
NON_MATCH void DarkRoot_StateGrab(DarkRoot* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 5);
  }
  if (anim->cmdIdx == 3 && anim->tick == 0) {
    PlaySound_082406e0(SONG_477);
  }
  if (anim->cmdIdx == 3 && anim->tick > 6) {
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    if (DarkRoot_FindAdjacentTarget(p, 0)) {
      u8 variant;
      AuxAnimPlayFlags flags;
      WorldPos pos;
      Mover* m;

      Enemy_EnterState(&p->e, DarkRoot_StateHold, ES_UNK_36);
      Enemy_ResetState(&p->e, 0, 2, 1);
      Enemy_SetAnimFacing(&p->e, &variant, &flags);
      pos.x = vec3_ARRAY_085ade10[flags * 5 + anim->cmdIdx].x + (p->e).mover.pos.x;
      pos.y = vec3_ARRAY_085ade10[flags * 5 + anim->cmdIdx].y + (p->e).mover.pos.y;
      pos.z = vec3_ARRAY_085ade10[flags * 5 + anim->cmdIdx].z + (p->e).mover.pos.z;
      m = (p->e).playerMover;
      if (m->unk_4 < 4) {
        Player_HoldGrabbed(gPlayerPtr[m->unk_4], &pos, NULL, 0, flags, 0, 0, 0, 0);
      } else if (m->unk_4 == 4) {
        Enemy* e = m->owner;

        e->hurtbox.iframes = 0;
        Enemy_ClearDamage(e);
        CLEAR_FLAGS(e->flags3, ENEFLAG3_UNK_5);
        Enemy_OnCrushed(e, 0, &pos, 0, flags);
      }
      DarkRoot_SetFlags((p->e).owner, DARKFLAG_GRABBING);
      return;
    }
  } else if (anim->cmdIdx < 2) {
    (p->e).hurtbox.flags &= ~HBFLAG_HIDDEN;
    (p->e).hurtbox.flags |= HBFLAG_UNK_3;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  } else {
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  if ((p->e).animForceRestart) {
    (p->e).hurtbox.flags &= ~HBFLAG_HIDDEN;
    (p->e).hurtbox.flags |= HBFLAG_UNK_3;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_EnterState(&p->e, DarkRoot_StateRetract, ES_UNK_38);
    Enemy_ResetState(&p->e, 0, 2, 3);
  }
#else
  INCFUNC("asm/func/DarkRoot_StateGrab.inc");
#endif
}

void DarkRoot_StateRetract(DarkRoot* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).hurtbox.flags = ((p->e).hurtbox.flags & ~HBFLAG_HIDDEN) | HBFLAG_UNK_3;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_PlayAnim(&p->e, 17);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, DarkRoot_StateWait, ES_UNK_33);
    Enemy_ResetState(&p->e, 0, 0, 2);
  }
}

// 掴んだ相手を持ち上げて締める, プレイヤーは squeezeInterval フレームごとに締めて連打が escapeMashCount を超えるか hp が尽きたら放し, 敵は 140 フレームで倒す, 180 フレームで副状態を終える
// 562/583命令の下書き, 敵を倒す枝のゲージ表示の判定は enemy.c の Enemy_OnCrushed と同じ形, 原典は持つ位置を WorldPos の DImode のまま書き換え (DarkRoot_StateGrab と同じ), 1回目の下書きで切り上げ
NON_MATCH void DarkRoot_StateHold(DarkRoot* p, s32 timer) {
#ifdef NONMATCHING_C
  DarkRoot* q = (p->e).owner;
  AuxAnimState* anim = &(p->e).s->aux.anim;
  Mover* m;
  u8 variant;
  AuxAnimPlayFlags flags;
  WorldPos pos;
  u32 cmd;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    q->mashCountBase = gPlayerPtr[0]->mashCount;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  m = (p->e).playerMover;
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  // 掴んでいるのがプレイヤーなら次のコマの位置で持つ
  if (m->unk_4 < 4) {
    if (anim->tick + 1 < anim->wait) {
      cmd = anim->cmdIdx;
    } else {
      cmd = anim->cmdIdx + 1;
      if (cmd >= anim->cmdCount) {
        cmd = 0;
      }
    }
  } else {
    cmd = anim->cmdIdx;
  }
  pos.x = vec3_ARRAY_085ade10[flags * 5 + cmd].x + (p->e).mover.pos.x;
  pos.y = vec3_ARRAY_085ade10[flags * 5 + cmd].y + (p->e).mover.pos.y;
  pos.z = vec3_ARRAY_085ade10[flags * 5 + cmd].z + (p->e).mover.pos.z;
  if (m->unk_4 != 4) {
    if (m->unk_4 < 4) {
      Player* player = m->owner;

      (p->e).s->aux.spr.priority = 1;
      if (Mod(timer, q->squeezeInterval) == 0) {
        u32 base = q->mashCountBase;

        if (gPlayerPtr[0]->mashCount < base) {
          base -= 256;
        }
        if (player->hp == 0 || gPlayerPtr[0]->mashCount - base > q->escapeMashCount) {
          u8 angle = FixToInt(6, ((p->e).mover.angle + 0x20) & 0xFF) << 6;

          TilePosAtIndex(&pos, (p->e).tileIdx);
          Player_ReleaseGrabbed(player, &pos, 64, angle, 60, 0, 0, 0);
          DarkRoot_ClearFlags(q, DARKFLAG_GRABBING);
          Enemy_ResetState(&p->e, 0, 0, 2);
          Enemy_EnterState(&p->e, DarkRoot_StateWait, ES_UNK_33);
          return;
        }
        Player_HoldGrabbed(player, &pos, NULL, DarkRoot_GetGrabbedAnimOffset(p), flags, 0, 0, (p->e).atkPower[1], (p->e).atkAttrs[1]);
      } else {
        Player_HoldGrabbed(player, &pos, NULL, DarkRoot_GetGrabbedAnimOffset(p), flags, 0, 0, 0, 0);
      }
    }
  } else {
    Enemy* e = m->owner;
    bool8 show;

    (p->e).s->aux.spr.priority = 2;
    Enemy_OnCrushed(e, 0, &pos, 0, flags);
    if (timer > 140) {
      e->hurtbox.damage = e->hp;
      e->unk_48a = e->hp;
      e->hp = 0;
      show = TRUE;
      if (IsLinkPlay() && !(e->unk_4a0 & 0x20) && e->unk_4a0 != 0) {
        switch (gLinkSession != NULL ? gLinkSession->playerIdx : -1) {
          case 0: {
            show = e->unk_4a0 == 1;
            break;
          }
          case 1: {
            show = e->unk_4a0 == 2;
            break;
          }
          case 2: {
            show = e->unk_4a0 == 4;
            break;
          }
          case 3: {
            show = e->unk_4a0 == 8;
            break;
          }
        }
      }
      if (show) {
        Vec3 v;

        HUD_ShowEnemyGauge(e->mover.id, e->hp, e->maxHp, e->unk_25a, 0);
        CpuFill32(0, &v, sizeof(v));
        if (e->unk_48a != 0 || !(e->weaponExpMask & 0x4000)) {
          CreateDamageNumber(&e->hurtbox, e->unk_48a, 0, &e->mover.pos, &v, 1);
        }
      }
      Enemy_ResetState(e, 3, 0, 0);
      Enemy_EnterState(e, (p->e).unk_5dc, ES_UNK_30);
      DarkRoot_ClearFlags(q, DARKFLAG_GRABBING);
      (p->e).subStateDone = 1;
      return;
    }
  }
  Enemy_PlayAnimFlipOnly(&p->e, 18);
  if (anim->cmdIdx == 0 && anim->tick == 0) {
    PlaySound_082406e0(SONG_478);
  }
  if (timer > 180) {
    (p->e).subStateDone = 1;
  }
#else
  INCFUNC("asm/func/DarkRoot_StateHold.inc");
#endif
}

// 地中へ潜りながら掴んでいたプレイヤーを自分のタイルの中心から向いている4方向へ放り出し, アニメが終わったら副状態を終える
void DarkRoot_StateReleaseGrab(DarkRoot* p) {
  DarkRoot* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Mover* m;
    WorldPos pos;
    u8 angle;

    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_PlayAnim(&p->e, 21);
    m = (p->e).playerMover;
    TilePosAtIndex(&pos, (p->e).tileIdx);
    angle = FixToInt(6, ((p->e).mover.angle + 0x20) & 0xFF) << 6;
    if (m->unk_4 < 4) {
      Player_ReleaseGrabbed(m->owner, &pos, 64, angle, 60, 0, 0, 0);
    }
    (p->e).s->aux.spr.priority = 2;
    DarkRoot_ClearFlags(q, DARKFLAG_GRABBING);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
  }
}

// 被弾して怯む, 地中に隠れて食らい判定を外し, アニメが終わったらプレイヤーの方を向いて DarkRoot_StateWait (状態33) へ戻る
void DarkRoot_StateDamaged(DarkRoot* p, s32 timer) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimFlipOnly(&p->e, 3);
    (p->e).animForceRestart = 0;
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
  }
  Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_4);
  if (timer < 18 && anim->cmdIdx == 0 && anim->tick == (anim->wait != 0) && anim->wait != 1) {
    anim->tick = 0;
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 0;
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    CLEAR_FLAGS((p->e).flags, ENEFLAG_UNK_7);
    Enemy_EnterState(&p->e, DarkRoot_StateWait, ES_UNK_33);
    Enemy_ResetState(&p->e, 0, 0, 0);
    (p->e).mover.angle = (p->e).playerAngle;
  }
}

void DarkRoot_StateVanish(DarkRoot* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimFlipOnly(&p->e, 16);
  }
  if ((p->e).animForceRestart) {
    FUN_0803712c(&(p->e).mover.pos);
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).subStateDone = 1;
  }
}

// 倒れるアニメを流して破片を飛ばし, 20 フレーム後に ENEFLAG6_UNK_1 がなければ hp を戻して生え直し, あれば煙を出して倒されたスクリプトを呼び図鑑と撃破数に載せて消える
// 689/685命令の下書き, 倒れたあとの後始末は Golem_StateDying / FUN_080f6604 と同じ形 (原典は defeatScript の引数や &kind をスタックに作り置く壁), 1回目の下書きで切り上げ
NON_MATCH void DarkRoot_StateDying(DarkRoot* p, s32 timer) {
#ifdef NONMATCHING_C
  DarkRoot* q = (p->e).owner;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Vec3 vel;

    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_6);
    Enemy_PlayAnimWithVariant(&p->e, 10, 1);
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    Enemy_FadeParticles(&p->e, 4);
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    PlayEnemyDeathCry(&p->e);
    Vec3_Clear(&vel);
    {
      u32 r = Random() & 0x1F;

      vel.x = POLAR_X(r, (p->e).angle);
      vel.z = POLAR_Z(r, (p->e).angle);
      vel.y = (Random() & 0x1F) + 48;
    }
    Entity081efa9c_Spawn(&(p->e).mover.pos, &vel, SPRITE_ROD, ANIM_DARKROOT, 10, 30, 2, 0, 220, 0, 0, 0, 0, 0, 0);
    if (!TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_1)) {
      if (q->regrowScriptID != 0) {
        u32 argv[1];
        ScriptArgs sa;

        argv[0] = (p->e).mover.id;
        sa.argc = 1;
        sa.argv = argv;
        VM_ExecByID(q->regrowScriptID, &sa);
        q->regrowScriptID = 0;
      }
    } else {
      PlaySound_082406e0(SE_UNDEAD_EXORCISM);
    }
  }
  if (timer > 20) {
    if (!TEST_FLAGS((p->e).flags6, ENEFLAG6_UNK_1)) {
      (p->e).hp = (p->e).maxHp;
      CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_6);
      Enemy_ResetState(&p->e, 0, 0, 1);
      Enemy_EnterState(&p->e, DarkRoot_StateEmerge, ES_UNK_41);
      (p->e).hurtbox.flags = ((p->e).hurtbox.flags & ~HBFLAG_HIDDEN) | HBFLAG_UNK_3;
      CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    } else {
      s32 idx;

      if (!TEST_FLAGS(gStat->mapFlags, MPF_UNK_9)) {
        Vec3 size;
        WorldPos* pos;
        u8 kind;

        VEC3_SET(size, 80, 60, 60);
        pos = &(p->e).mover.pos;
        EmitSmoke(pos, (Random() & 3) + 1, &size, 0x20, 4, 20, 2, 1);
        EmitSmoke(pos, (Random() & 3) + 1, &size, 0x40, 4, 20, 2, 1);
        EmitSmoke(pos, (Random() & 3) + 1, &size, 0x5E, 4, 20, 2, 1);
        EmitSmoke(pos, (Random() & 3) + 1, &size, 0x80, 4, 20, 2, 1);
        EmitSmoke(pos, (Random() & 3) + 1, &size, 0xC4, 4, 20, 2, 1);
        EmitSmoke(pos, (Random() & 3) + 1, &size, 0xF0, 4, 20, 2, 1);
        kind = (p->e).kind;
        if (kind == ENEK_BOKU || kind == ENEK_MUMMY || kind == ENEK_SKELETON || kind == ENEK_SKELETON_A || kind == ENEK_SKELETON_F || kind == ENEK_DARKROOT) {
          PlaySound_082406e0(SE_UNDEAD_EXORCISM);
        }
      } else {
        PlaySound_082406e0(SE_UNDEAD_EXORCISM);
        FUN_0803712c(&(p->e).mover.pos);
        Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_12);
      }
      Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
      FUN_080e6658(&p->e);
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
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 1, 0, 2);
      if (gStat->unk_948[0] < 9999) {
        gStat->unk_948[0]++;
      } else {
        gStat->unk_948[0] = 9999;
      }
      if (gStat->totalEnemyKillCount < 9999) {
        gStat->totalEnemyKillCount++;
      } else {
        gStat->totalEnemyKillCount = 9999;
      }
      Enemy_AddKillCount(&p->e);
      AddPlayerExp((p->e).exp);
      Player_AddWeaponExp((p->e).weaponExpMask, (p->e).weaponExp);
      if (!IsLinkPlay() && !TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_11)) {
        DefeatedEnemyLog_Add(gMapInitScriptID, (p->e).mover.id);
      }
    }
  }
#else
  INCFUNC("asm/func/DarkRoot_StateDying.inc");
#endif
}

s32 DarkRoot_PreUpdate(DarkRoot* p) {
  Hitbox_Hide(&(p->e).hitbox);
  return 1;
}

s32 DarkRoot_PostUpdate(DarkRoot* p) {
  Hitbox_SetPos(&(p->e).hurtbox, &(p->e).mover.pos, 0);
  return 1;
}

void DarkRoot_SubWatch(DarkRoot* p) {
  DarkRoot* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Hitbox_ClearFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
    Hitbox_SetFlags(&(p->e).hurtbox, HBFLAG_UNK_3);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  if (!DarkRoot_FindAdjacentTarget(p, 1)) {
    q->lostTimer++;
  } else {
    q->lostTimer = 0;
  }
  if ((p->e).subStateTimer > 30 && q->lostTimer == 0) {
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, DarkRoot_StateGrab, ES_UNK_3);
  }
  (p->e).subStateTimer++;
}

void DarkRoot_SubEmerge(DarkRoot* p) {
  DarkRoot* q = (p->e).owner;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, DarkRoot_StateEmerge, ES_UNK_41);
    q->lostTimer = 0;
  }
  if ((p->e).subStateDone) {
    Hitbox_ClearFlags(&(p->e).hurtbox, HBFLAG_HIDDEN);
    Hitbox_SetFlags(&(p->e).hurtbox, HBFLAG_UNK_3);
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_EnterState(&p->e, DarkRoot_StateWait, ES_UNK_33);
    Enemy_ResetState(&p->e, 0, 0, 2);
  }
  (p->e).subStateTimer++;
}

void FUN_081a483c(DarkRoot* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, DarkRoot_StateHold, ES_UNK_36);
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

void DarkRoot_SubRetract(DarkRoot* p) { Enemy_ConsumeSubStateBegun(&p->e); }

void DarkRoot_SubCooldown(DarkRoot* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateTimer > 30) {
    Enemy_ResetState(&p->e, 0, 0, 0);
  }
  (p->e).subStateTimer++;
}

void DarkRoot_SubHold(DarkRoot* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, DarkRoot_StateReleaseGrab, ES_UNK_40);
    Enemy_ResetState(&p->e, 0, 2, 2);
  }
}

void DarkRoot_SubReleaseGrab(DarkRoot* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, DarkRoot_StateWait, ES_UNK_33);
    Enemy_ResetState(&p->e, 0, 0, 2);
  }
}

void FUN_081a4a44(DarkRoot* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).chaseTimeMax <= (p->e).subStateTimer) {
    Enemy_ResetState(&p->e, 0, 0, 0);
  } else {
    (p->e).subStateTimer++;
  }
}

void DarkRoot_SubDeactivate(DarkRoot* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_Deactivate(&p->e);
  }
  (p->e).subStateTimer++;
}

void DarkRoot_SubVanish(DarkRoot* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, DarkRoot_StateVanish, ES_UNK_45);
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_SetFlag4(&p->e, ENEFLAG4_UNK_12);
  }
}

void DarkRoot_InitHandlerTables(DarkRoot* p) {
  (p->e).handlerTables[2] = (void*)PTR_ARRAY_085ade70;
  (p->e).handlerTables[4] = (void*)PTR_ARRAY_085ade60;
  (p->e).handlerTables[6] = (void*)PTR_ARRAY_085ade80;
}

s32 DarkRoot_OnDamaged(DarkRoot* p) {
  PlaySound_082406e0(SE_ENEMY_DAMAGED);
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return FALSE;
  }
  Enemy_ResetState(&p->e, 3, 0, 0);
  Enemy_EnterState(&p->e, DarkRoot_StateDamaged, ES_UNK_42);
  return TRUE;
}

// 枯れさせるメッセージ (6 番) の処理, 掴んでいればプレイヤーを放り出し, 判定を隠して hp を 0 にし状態16で止める
void DarkRoot_OnWitherMsg(DarkRoot* p, u16* msg) {
  if (DarkRoot_TestFlags((p->e).owner, DARKFLAG_WITHERED)) {
    return;
  }
  if (DarkRoot_TestFlags((p->e).owner, DARKFLAG_GRABBING)) {
    WorldPos pos;
    s32 angle;
    Mover* m;

    TilePosAtIndex(&pos, (p->e).tileIdx);
    angle = FixToInt(6, ((p->e).mover.angle + 0x20) & 0xFF) << 6;
    m = (p->e).playerMover;
    if (m->unk_4 < 4) {
      Player_ReleaseGrabbed(m->owner, &pos, 64, angle, 60, 0, 0, 0);
      PlaySound_082406e0(SE_DAMAGE);
    }
    (p->e).s->aux.spr.priority = 2;
  }
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  Enemy_ResetState(&p->e, 0, 0, 3);
  Hitbox_Hide(&(p->e).hurtbox);
  Hitbox_Hide(&(p->e).hitbox);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  DarkRoot_SetFlags((p->e).owner, DARKFLAG_WITHERED);
  (p->e).hp = 0;
}

// すべての暗黒の根へ枯れさせるメッセージ (6 番) を送る
void DarkRoot_WitherAll(void) {
  u16 msg = 6;

  Enemy_SendMsgByKind(ENEK_DARKROOT, &msg);
}

void DarkRoot_InitAnims(DarkRoot* p) {
  Enemy_SetAnimEntry(&p->e, 14, 0, 0);
  Enemy_SetAnimEntry(&p->e, 15, 1, 0);
  Enemy_SetAnimEntry(&p->e, 16, 2, 0);
  Enemy_SetAnimEntry(&p->e, 3, 7, 0);
  Enemy_SetAnimEntry(&p->e, 5, 3, 0);
  Enemy_SetAnimEntry(&p->e, 17, 4, 0);
  Enemy_SetAnimEntry(&p->e, 18, 5, 0);
  Enemy_SetAnimEntry(&p->e, 19, 6, 0);
  Enemy_SetAnimEntry(&p->e, 20, 8, 0);
  Enemy_SetAnimEntry(&p->e, 10, 8, 0);
  Enemy_SetAnimEntry(&p->e, 21, 9, 0);
}

// 復帰時に印と lostTimer を消し, 位置をタイルの中心へずらしてスプライトに写し, 待機アニメを流して1コマ送る
// 147/148命令, Dog_OnReset / Golem_OnReset と同じ壁 (p->sprite を r0 に読んでから r5 へ移す), 1回目の下書きで切り上げ
NON_MATCH void DarkRoot_OnReset(DarkRoot* p) {
#ifdef NONMATCHING_C
  DarkRoot* q = (p->e).owner;
  EnemyAuxSprite* aux;

  q->flags = 0;
  q->lostTimer = 0;
  (p->e).mover.pos.x += 32;
  (p->e).mover.pos.z += 32;
  Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
  Enemy_PlayAnim(&p->e, 0);
  aux = &(p->e).s->aux;
  AuxSprite_AdvanceAnim(&aux->spr, &aux->anim);
#else
  INCFUNC("asm/func/DarkRoot_OnReset.inc");
#endif
}

void DarkRoot_InitHitboxes(DarkRoot* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 64, 256, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtboxWithFlags(&p->e, &hurtSize, &hurtOffset, DarkRoot_OnHurt, p, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_HIDDEN | HBFLAG_UNK_0);
  VEC3_SET(hitSize, 0, 0, 0);
  VEC3_SET(hitOffset, 0, 0, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, DarkRoot_OnHit, 1, p);
}

void DarkRoot_EnterWait(DarkRoot* p) {
  Enemy_ResetState(&p->e, 0, 0, 0);
  Enemy_EnterState(&p->e, DarkRoot_StateWait, ES_UNK_33);
}

// range0Sq の 2 倍 (スニーク中は 0x24000) より近く, 掴まれておらず無敵でないプレイヤーのうち一番近い者の Mover を返す
Mover* DarkRoot_FindNearestPlayer(DarkRoot* p) {
  Mover* found = NULL;
  s32 best = (p->e).range0Sq * 2;
  s32 i;

  if (Player_TestFlag20(gPlayerPtr[0], PFLAG20_SNEAKING)) {
    best = 0x24000;
  }
  if ((p->e).state == ES_UNK_3 && Player_TestFlag20(gPlayerPtr[0], PFLAG20_UNK_18)) {
    return NULL;
  }
  for (i = 0; i < 1; i++) {
    Player* player = gPlayerPtr[i];

    if (player != NULL && !Player_TestFlag20(player, PFLAG20_UNK_12) && player->hurtbox.iframes == 0) {
      Vec3 d;
      s32 dist;

      Vec3_Diff(&d, &player->mover.pos, &(p->e).mover.pos);
      dist = d.x * d.x + d.z * d.z;
      if (best > dist) {
        best = dist;
        found = &gPlayerPtr[i]->mover;
      }
    }
  }
  return found;
}

// 同じ高さで range0Sq より近いプレイヤーか敵が隣のタイルにいれば playerMover にして返す, faceTarget なら4方向のどれでもよくそちらを向き, そうでなければ向いている方だけ見る
Mover* DarkRoot_FindAdjacentTarget(DarkRoot* p, s32 faceTarget) {
  u32 best = (p->e).range0Sq;
  Mover* target = DarkRoot_FindNearestPlayer(p);
  Enemy* e;
  s32 tile;
  Vec3 d;

  if (target != NULL && (p->e).mover.pos.y == target->pos.y) {
    u32 dist;

    Vec3_Delta(&d, &(p->e).mover.pos, &target->pos);
    dist = d.x * d.x + d.z * d.z;
    if ((s32)best > (s32)dist) {
      best = dist;
    } else {
      target = NULL;
    }
  }
  e = FUN_080edc40(&(p->e).mover.pos);
  if (e != NULL && (p->e).mover.pos.y == e->mover.pos.y) {
    Vec3_Diff(&d, &e->mover.pos, &(p->e).mover.pos);
    if ((s32)best > d.x * d.x + d.z * d.z) {
      target = &e->mover;
    }
  }
  if (target == NULL) {
    return NULL;
  }
  tile = GetCollisionTileIdx(&target->pos);
  if (faceTarget == 1) {
    u32 idx = (p->e).tileIdx;

    if (idx + 1 == tile) {
      (p->e).mover.angle = 0;
      (p->e).playerMover = target;
      return target;
    }
    if (idx - 1 == tile) {
      (p->e).mover.angle = 0x80;
      (p->e).playerMover = target;
      return target;
    }
    if (idx + gCollisionMap->tiledata->width == tile) {
      (p->e).mover.angle = 0x40;
      (p->e).playerMover = target;
      return target;
    }
    if (idx - gCollisionMap->tiledata->width == tile) {
      (p->e).mover.angle = 0xC0;
      (p->e).playerMover = target;
      return target;
    }
  } else {
    switch ((((p->e).mover.angle + 0x20) >> 6) & 3) {
      case 0: {
        if ((p->e).tileIdx + 1 == tile) {
          (p->e).playerMover = target;
          return target;
        }
        break;
      }
      case 1: {
        if ((p->e).tileIdx + gCollisionMap->tiledata->width == tile) {
          (p->e).playerMover = target;
          return target;
        }
        break;
      }
      case 2: {
        if ((p->e).tileIdx - 1 == tile) {
          (p->e).playerMover = target;
          return target;
        }
        break;
      }
      case 3: {
        if ((p->e).tileIdx - gCollisionMap->tiledata->width == tile) {
          (p->e).playerMover = target;
          return target;
        }
        break;
      }
    }
  }
  return NULL;
}

s32 DarkRoot_GetGrabbedAnimOffset(DarkRoot* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (anim->cmdIdx == 3) {
    return 1;
  }
  if (anim->cmdIdx == 4) {
    return 0;
  }
  return anim->cmdIdx;
}

s32 DarkRoot_UpdateFrame(DarkRoot* p) {
  DarkRoot_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];

    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  DarkRoot_PostUpdate(p);
  return 1;
}

s32 DarkRoot_Update(DarkRoot* p) {
  Enemy_Update(&p->e);
  return 0;
}

s32 DarkRoot_Destroy(DarkRoot* p) {
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
// 1681/1823命令, Golem_Init の下書きを暗黒の根向けに直したもの ('P' / 'd' / 'E' の名前付き引数, 位置をタイルの中心へ寄せる, MPF_UNK_9 で生えた状態から始める), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline の壁), 1回目の下書きで切り上げ
NON_MATCH s32 DarkRoot_Init(DarkRoot* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 id;
  s32 range0, range1, range2;
  u32 range3;
  s32 hpParam3, hpParam4;
  bool32 onPath;
  s32 i;
  u8 kind;

  p->flags = 0;
  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).kind = ENEK_DARKROOT;
  DarkRoot_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_ROD);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_DARKROOT);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_ROD);
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
    p->unk_66a = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->squeezeInterval = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->escapeMashCount = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  p->regrowScriptID = VM_GetNamedArgValue('d', 0);
  (p->e).mover.pos.x += 32;
  (p->e).mover.pos.z += 32;
  Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 220;
  (p->e).unk_47c = OBP_WHITE_306;
  (p->e).unk_47e = (p->e).variant + 220;
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

  (p->e).unk_476 = (p->e).plttBase + 2;
  (p->e).unk_478 = (p->e).plttBase;
  DarkRoot_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)DarkRoot_UpdateFrame;
  (p->e).getMoveSpeed = NULL;
  (p->e).handlerTurn = NULL;
  (p->e).handlerMove = NULL;
  (p->e).handlerWait = NULL;
  (p->e).unk_5c0 = NULL;
  (p->e).onRouteFailed = NULL;
  (p->e).handlerDamaged = NULL;
  (p->e).handlerDying = (void*)DarkRoot_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = (void*)FUN_081a3360;
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
  (p->e).onReset = (EnemyHandler)DarkRoot_OnReset;
  (p->e).onAttackRequest = NULL;
  (p->e).unk_5b0 = NULL;
  (p->e).onDamaged = (void*)DarkRoot_OnDamaged;
  (p->e).kind = ENEK_DARKROOT;
  Enemy_InitShadowAndEmitter(&p->e);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_10);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_6 | ENEFLAG5_UNK_7);
  if (VM_GetNamedArgValue('E', 0) != 0) {
    SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_25);
  }

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
  DarkRoot_InitHandlerTables(p);
  DarkRoot_EnterWait(p);
  if (TEST_FLAGS(gStat->mapFlags, MPF_UNK_9)) {
    Enemy_ResetState(&p->e, 0, 0, 1);
    Enemy_EnterState(&p->e, DarkRoot_StateEmerge, ES_UNK_41);
    (p->e).hurtbox.flags = ((p->e).hurtbox.flags & ~HBFLAG_HIDDEN) | HBFLAG_UNK_3;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    FUN_0803712c(&(p->e).mover.pos);
  }
  (p->e).msgHandlers = (void*)PTR_ARRAY_085ade8c;
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
  (p->e).handlerUpdate = (EnemyHandler)DarkRoot_Update;
  (p->e).handlerDestroy = (EnemyHandler)DarkRoot_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/DarkRoot_Init.inc");
#endif
}

void DarkRoot_Create(void) {
  DarkRoot* p = Malloc(sizeof(DarkRoot));

  if (p != NULL) {
    ClearMemory(p, sizeof(DarkRoot));
    if (DarkRoot_Init(p) < 0) {
      DarkRoot_Destroy(p);
      Free(p);
    }
  }
}
