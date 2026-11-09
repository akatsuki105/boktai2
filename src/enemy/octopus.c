#include "camera.h"
#include "cwolf_target.h"
#include "eff_elemcond.h"
#include "enemy.h"
#include "enemy_inline.h"
#include "enemy_manager.h"
#include "global.h"
#include "malloc.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// ENEK_OCTOPUS(ENEID_OCTOPUS)
// 水面から生えた触手型の敵
typedef u32 OctopusFlags;

typedef struct {
  Enemy e;
  u8 unk_654[4];       // 0x654
  u8 unk_658[6];       // 0x658, 倒れるときに spinSpeed とまとめて 0 にする
  s16 spinSpeed;       // 0x65E, 倒れて飛んでいくときに毎フレーム sprite.rotation へ足す回転の速さ
  OctopusFlags flags;  // 0x660, see OctopusFlags
  u32 groupID;         // 0x664, '.B', variant 1 のときに作る OctopusGroup の mover.id
  s16 lostTimer;       // 0x668, 隣のタイルに相手がいないフレーム数, いれば 0 に戻す
  s16 lostTimeout;     // 0x66A, '.P[0]', lostTimer がこれを超えると探し直す
  u8 mashCountBase;    // 0x66C, 掴んだときのプレイヤーの mashCount
  u8 escapeMashCount;  // 0x66D, '.P[2]', この回数を超えて連打されると放す
  u8 squeezeInterval;  // 0x66E, '.P[1]', 締め付ける間隔のフレーム数
  u8 unk_66f;          // 0x66F
  NavAgent navAgent;   // 0x670, Enemy.navAgent が指す
  Vec3 pathNodePos;    // 0x694, Enemy.pathNodePos が指す
} Octopus;
static_assert(sizeof(Octopus) == 1692);

typedef struct {
  u16 id;    // 0x00, 触手の mover.id
  u16 kind;  // 0x02, 触手の kind
} OctopusGroupMember;

// ENEK_15, variant 1 のオクトパスが '.B' の id で作る, 集まった触手を数えて全部いなくなったら倒した扱いにする
typedef struct {
  Enemy e;
  u8 unk_654[4];                   // 0x654
  s32 memberCount;                 // 0x658
  OctopusGroupMember members[16];  // 0x65C
} OctopusGroup;
static_assert(sizeof(OctopusGroup) == 1692);

void Enemy_AddKillCount(Enemy* p);
s32 OctopusGroup_Destroy(OctopusGroup* p);
s32 OctopusGroup_Init(OctopusGroup* p, u32 id);
void OctopusGroup_Create(u32 id);
void Enemy_Reactivate(Enemy* p);
void FUN_080e68d8(Enemy* p, s32 timer);
Mover* Octopus_FindAdjacentTarget(Octopus* p, s32 faceTarget);
Mover* Octopus_FindNearestPlayer(Octopus* p);
void Octopus_StateRetract(Octopus* p);
s32 Octopus_GetGrabbedAnimOffset(Octopus* p);
void Enemy_PlayVoice(Enemy* p);
void Octopus_StateHold(Octopus* p, s32 timer);
s32 Entity081ea120_Spawn(Vec3* pos, s32 count, u32 priority, u32 animIdx, s32 plttID);
s32 Octorok_ThrowAt(Mover* src, Mover* target, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes);

// clang-format off
// 掴んだ相手を持つ位置, Enemy_SetAnimFacing の flags ごとに 5 コマ分
const Vec3 vec3_ARRAY_085adbfc[10] = {
    {82,  250, 0  },
    {112, 270, -5 },
    {118, 270, -5 },
    {118, 270, -5 },
    {92,  260, -5 },
    {-24, 250, 82 },
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
    {-20, 270, 106},
};  // 0x085ADBFC

const Vec3 vec3_ARRAY_085adc4c[4] = {
    {28, 250, 48},
    {38, 0,   24},
    {42, 250, 48},
    {12, 0,   24},
};  // 0x085ADC4C
// clang-format on

void FUN_08186a7c(Octopus*);
void Octopus_SubHold(Octopus*);
void Octopus_SubPullUnder(Octopus*);
void FUN_08186b10(Octopus*);
void FUN_08186c88(Octopus*);
void Octopus_SubFindThrowTarget(Octopus*);

void (*const PTR_ARRAY_085adc6c[6])(Octopus*) = {
    FUN_08186a7c,
    Octopus_SubHold,
    Octopus_SubPullUnder,
    FUN_08186b10,
    FUN_08186c88,
    Octopus_SubFindThrowTarget,
};  // 0x085ADC6C

void Octopus_SubHide(Octopus*);
void Octopus_SubLurk(Octopus*);
void Octopus_SubWatch(Octopus*);
void Octopus_SubMissCooldown(Octopus*);
void Octopus_SubEmergeAndWait(Octopus*);

void (*const PTR_ARRAY_085adc84[5])(Octopus*) = {
    Octopus_SubHide,
    Octopus_SubLurk,
    Octopus_SubWatch,
    Octopus_SubMissCooldown,
    Octopus_SubEmergeAndWait,
};  // 0x085ADC84

void Octopus_SubDamageCooldown(Octopus*);
void Octopus_SubDeactivate(Octopus*);
void Octopus_SubDamagedSubmerge(Octopus*);

void (*const PTR_ARRAY_085adc98[4])(Octopus*) = {
    Octopus_SubDamageCooldown,
    (void*)FUN_080f1cb8,
    Octopus_SubDeactivate,
    Octopus_SubDamagedSubmerge,
};  // 0x085ADC98

void Octopus_OnGroupDefeatedMsg(Octopus*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085adca8[10])(Octopus*, u16*) = {
    (void*)FUN_080f09a4,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    NULL,
    NULL,
    NULL,
    Octopus_OnGroupDefeatedMsg,
};  // 0x085ADCA8

void OctopusGroup_OnJoinMsg(OctopusGroup*, u16*);
void OctopusGroup_OnLeaveMsg(OctopusGroup*, u16*);

// メッセージ表
void (*const PTR_ARRAY_085adcd0[9])(OctopusGroup*, u16*) = {
    NULL,
    (void*)Enemy_Suspend,
    (void*)Enemy_Resume,
    (void*)FUN_080f0868,
    (void*)FUN_080e6624,
    (void*)FUN_080e664c,
    NULL,
    OctopusGroup_OnJoinMsg,
    OctopusGroup_OnLeaveMsg,
};  // 0x085ADCD0

// 食らい判定, 敵共通の処理だけ
// 752/763命令, 敵共通の Enemy_HandleHurt だけ, Golem_OnHurt / Mummy_OnHurt と同じ共通 inline の壁
NON_MATCH void Octopus_OnHurt(HitboxData* a, HitboxData* b, Octopus* p) {
#ifdef NONMATCHING_C
  Enemy_HandleHurt(a, b, &p->e);
#else
  INCFUNC("asm/func/Octopus_OnHurt.inc");
#endif
}

void Octopus_OnHit(HitboxData* a, HitboxData* b, Octopus* p) {}

void Octopus_StateWait(Octopus* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).hurtbox.flags = ((p->e).hurtbox.flags & ~HBFLAG_HIDDEN) | HBFLAG_UNK_3;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  Enemy_PlayAnimFlipOnly(&p->e, 14);
}

void Octopus_StateEmerge(Octopus* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).s->aux.spr.priority = 2;
    (p->e).hurtbox.iframes = 0;
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    (p->e).hurtbox.flags = ((p->e).hurtbox.flags & ~HBFLAG_HIDDEN) | HBFLAG_UNK_3;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_PlayAnimFlipOnly(&p->e, 15);
    PlaySound_082406e0(SONG_672);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Octopus_StateWait, ES_UNK_33);
  }
}

void FUN_08184dd8(Octopus* p) {}

void Octopus_StateThrow(Octopus* p, s32 timer) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    Mover* m = (p->e).playerMover;
    u8 idx = m->unk_4;

    if (idx == 4) {
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      Enemy_ResetState(&p->e, 0, 0, 1);
      return;
    }
    if (idx < 4) {
      Player* pl = m->owner;

      Entity081ea120_Spawn(&(p->e).mover.pos, 1, 2, 0, 276);
      Octorok_ThrowAt(&(p->e).mover, &pl->mover, (p->e).atkPower[0], (p->e).atkKnockback[0], (p->e).atkAttrs[0], (p->e).atkIframes[0]);
      PlaySound_082406e0(SONG_480);
    }
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  if (timer > 60) {
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    Enemy_ResetState(&p->e, 0, 0, 4);
  }
}

void Octopus_StateSubmerge(Octopus* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_PlayAnimFlipOnly(&p->e, 16);
  }
  if ((p->e).animForceRestart) {
    (p->e).hurtbox.iframes = 0;
    (p->e).subStateDone = 1;
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  }
}

// 地中から伸びて掴みかかる, 4コマ目で隣のタイルに相手がいれば掴んで状態36へ移り, いなければアニメの終わりに引っ込む (状態38)
// 329/336命令, DarkRoot_StateGrab と同じ形と同じ壁 (原典は持つ位置を WorldPos の DImode のまま書き換える), 違いは variant 1 で速く伸びる点と掴んだあとの Octopus_FindAdjacentTarget の向き, 1回目の下書きで切り上げ
NON_MATCH void Octopus_StateGrab(Octopus* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;

  u16 wait;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnim(&p->e, 5);
    if ((p->e).variant == 1) {
      AuxAnim_SetAnimSpeed(anim, Q6(0.75));
    }
  }
  if (anim->cmdIdx == 3 && anim->tick == 0) {
    PlaySound_082406e0(SONG_477);
  }
  wait = 6;
  if ((p->e).variant == 1) {
    wait = 3;
  }
  if (anim->cmdIdx == 3 && anim->tick > wait) {
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    if (Octopus_FindAdjacentTarget(p, 0)) {
      u8 variant;
      AuxAnimPlayFlags flags;
      WorldPos pos;
      Mover* m;

      Enemy_EnterState(&p->e, Octopus_StateHold, ES_UNK_36);
      Enemy_ResetState(&p->e, 0, 2, 1);
      Enemy_PlayAnimFlipOnly(&p->e, 18);
      Enemy_SetAnimFacing(&p->e, &variant, &flags);
      pos.x = vec3_ARRAY_085adbfc[flags * 5 + anim->cmdIdx].x + (p->e).mover.pos.x;
      pos.y = vec3_ARRAY_085adbfc[flags * 5 + anim->cmdIdx].y + (p->e).mover.pos.y;
      pos.z = vec3_ARRAY_085adbfc[flags * 5 + anim->cmdIdx].z + (p->e).mover.pos.z;
      m = (p->e).playerMover;
      if (m->unk_4 < 4) {
        Player_HoldGrabbed(gPlayerPtr[m->unk_4], &pos, NULL, 0, flags, 0, 0, 0, 0);
      } else if (m->unk_4 == 4) {
        Enemy* e = m->owner;

        e->hurtbox.iframes = 0;
        Enemy_ClearDamage(e);
        CLEAR_FLAGS(e->flags3, ENEFLAG3_UNK_5);
        FUN_080e6978(e, 0, &pos, 0, flags);
      }
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
    Enemy_EnterState(&p->e, Octopus_StateRetract, ES_UNK_38);
    Enemy_ResetState(&p->e, 0, 2, 3);
  }
#else
  INCFUNC("asm/func/Octopus_StateGrab.inc");
#endif
}

void Octopus_StateRetract(Octopus* p) {
  if (Enemy_ConsumeStateBegun(&p->e)) {
    (p->e).hurtbox.flags = ((p->e).hurtbox.flags & ~HBFLAG_HIDDEN) | HBFLAG_UNK_3;
    CLEAR_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_PlayAnim(&p->e, 17);
  }
  if ((p->e).animForceRestart) {
    Enemy_EnterState(&p->e, Octopus_StateWait, ES_UNK_33);
    Enemy_ResetState(&p->e, 0, 0, 3);
  }
}

// 掴んだ相手を持ち上げて締める, プレイヤーは squeezeInterval フレームごとに締めて連打が escapeMashCount を超えるか hp が尽きたら放し, 180 フレームで副状態を終える
// 368/381命令の下書き, DarkRoot_StateHold から敵を倒す枝を外した形, 原典は持つ位置を WorldPos の DImode のまま書き換え (DarkRoot_StateGrab と同じ), 1回目の下書きで切り上げ
NON_MATCH void Octopus_StateHold(Octopus* p, s32 timer) {
#ifdef NONMATCHING_C
  Octopus* q = (p->e).owner;
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
  pos.x = vec3_ARRAY_085adbfc[flags * 5 + cmd].x + (p->e).mover.pos.x;
  pos.y = vec3_ARRAY_085adbfc[flags * 5 + cmd].y + (p->e).mover.pos.y;
  pos.z = vec3_ARRAY_085adbfc[flags * 5 + cmd].z + (p->e).mover.pos.z;
  if (m->unk_4 == 4) {
    (p->e).s->aux.spr.priority = 2;
    FUN_080e6978(m->owner, 0, &pos, 0, flags);
  } else if (m->unk_4 < 4) {
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
        Enemy_ResetState(&p->e, 0, 0, 0);
        Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
        return;
      }
      Player_HoldGrabbed(player, &pos, NULL, Octopus_GetGrabbedAnimOffset(p), flags, 0, 0, (p->e).atkPower[1], (p->e).atkAttrs[1]);
    } else {
      Player_HoldGrabbed(player, &pos, NULL, Octopus_GetGrabbedAnimOffset(p), flags, 0, 0, 0, 0);
    }
  }
  Enemy_PlayAnimFlipOnly(&p->e, 18);
  if (anim->cmdIdx == 0 && anim->tick == 0) {
    PlaySound_082406e0(SONG_478);
  }
  if (timer > 180) {
    (p->e).subStateDone = 1;
    (p->e).s->aux.spr.priority = 1;
  }
#else
  INCFUNC("asm/func/Octopus_StateHold.inc");
#endif
}

// 掴んだ相手を水中へ引きずり込み, アニメが終わったら姿を隠して水しぶきを上げる
// 222/237命令の下書き, 持つ位置の求め方は Octopus_StateHold と同じ (表は vec3_ARRAY_085adc4c の2コマ分), 原典は持つ位置を WorldPos の DImode のまま書き換える, 1回目の下書きで切り上げ
NON_MATCH void Octopus_StatePullUnder(Octopus* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim = &(p->e).s->aux.anim;
  Mover* m;
  u32 cmd;
  u8 variant;
  AuxAnimPlayFlags flags;
  WorldPos pos;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimFlipOnly(&p->e, 19);
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  }
  m = (p->e).playerMover;
  if (m->unk_4 < 4 && anim->tick + 1 >= anim->wait) {
    cmd = anim->cmdIdx + 1;
    if (cmd >= anim->cmdCount) {
      cmd = 0;
    }
  } else {
    cmd = anim->cmdIdx;
  }
  Enemy_SetAnimFacing(&p->e, &variant, &flags);
  pos.x = vec3_ARRAY_085adc4c[flags * 2 + cmd].x + (p->e).mover.pos.x;
  pos.y = vec3_ARRAY_085adc4c[flags * 2 + cmd].y + (p->e).mover.pos.y;
  pos.z = vec3_ARRAY_085adc4c[flags * 2 + cmd].z + (p->e).mover.pos.z;
  if (m->unk_4 & 4) {
    FUN_080e6978(m->owner, 1, &pos, 0, flags);
  } else if (m->unk_4 < 4) {
    Player_HoldGrabbed(m->owner, &pos, NULL, 3, flags, 0, 0, 0, 0);
  }
  if ((p->e).animForceRestart) {
    (p->e).subStateDone = 1;
    (p->e).s->aux.spr.priority = 2;
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    PlaySound_082406e0(SONG_480);
    if (m->unk_4 & 4) {
      FUN_080e6978(FindEnemyById(m->id), 2, &pos, 0, 0);
      Entity081ea120_Spawn(&(p->e).mover.pos, 1, 2, 0, 276);
    } else if (m->unk_4 < 4) {
      Player_HoldGrabbed(m->owner, &pos, NULL, 3, flags, 0, 1, 0, 0);
      Entity081ea120_Spawn(&(p->e).mover.pos, 1, 1, 0, 276);
    }
  }
#else
  INCFUNC("asm/func/Octopus_StatePullUnder.inc");
#endif
}

// 掴んだ相手を経路ノードの位置で2回叩きつけて画面を揺らし, 120 フレームで放り出して 60 フレーム後に止まる予約を入れる
// 438/440命令の下書き, 原典は sprite を先頭でスタックに置き, 放り出す位置を WorldPos の DImode のまま書く, 1回目の下書きで切り上げ
NON_MATCH void Octopus_StateSlam(Octopus* p, s32 timer) {
#ifdef NONMATCHING_C
  Mover* m;
  WorldPos pos;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimNoFacing(&p->e, 20);
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    {
      PathWalker* walker = &(p->e).pathWalker;

      (p->e).mover.pos.x = walker->node->x;
      (p->e).mover.pos.z = walker->node->y;
      (p->e).mover.pos.y = TileHeightAt(&(p->e).mover.pos);
    }
    (p->e).s->aux.spr.pos = (p->e).mover.pos;
  }
  m = (p->e).playerMover;
  if (timer == 60 || timer == 90) {
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    if ((p->e).spriteKind == 0) {
      Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).unk_47c);
    } else {
      (p->e).s->main.spr.pltt = &gObjPlttData[(p->e).unk_47c * 16];
    }
    (p->e).unk_492 = 8;
    SET_FLAGS((p->e).flags, ENEFLAG_UNK_15);
    if (m->unk_4 < 4) {
      Player_HoldGrabbed(m->owner, &(p->e).mover.pos, NULL, 0, 0, 0, 1, (p->e).atkPower[2], (p->e).atkAttrs[2]);
      PlaySound_082406e0(SE_DAMAGE);
    } else if (m->unk_4 & 4) {
      Enemy* e = m->owner;

      FUN_080e6978(e, 2, &pos, 0, 0);
      Enemy_PlayVoice(e);
    }
  } else {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  }
  if (timer >= 51 && timer <= 59) {
    Camera_Shake(20);
  }
  if (timer >= 81 && timer <= 89) {
    Camera_Shake(40);
  }
  if (timer > 120) {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    if (!(m->unk_4 & 4)) {
      if (m->unk_4 < 4) {
        u8 angle = FixToInt(6, ((p->e).mover.angle + 0x20) & 0xFF) << 6;

        TilePosAtIndex(&pos, (p->e).tileIdx);
        Player_ReleaseGrabbed(m->owner, &pos, 128, angle, 60, 0, 0, 0);
        Entity081ea120_Spawn(&(p->e).mover.pos, 1, 1, 1, 276);
        PlaySound_082406e0(SONG_479);
      }
    } else {
      FUN_080e6978(m->owner, 2, &pos, 0, 64);
    }
    Enemy_PlayAnimFlipOnly(&p->e, 16);
    (p->e).pendingDelay = 60;
    (p->e).pendingHandler = Enemy_ClearStateBegun;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 1;
    Enemy_EnterState(&p->e, FUN_080e68d8, ES_UNK_14);
    Enemy_ResetState(&p->e, 3, 0, 0);
    (p->e).mover.pos.x += 32;
    (p->e).mover.pos.z += 32;
    (p->e).s->aux.spr.pos = (p->e).mover.pos;
  }
#else
  INCFUNC("asm/func/Octopus_StateSlam.inc");
#endif
}

// 地中に消えて煙を出し, 活動を止めて経路ノードの位置へ戻る
// 246/232命令, パレットの差し替え2か所を plttID (u32) を引数に取る inline にすると 232/232 まで寄る, 残差は経路ノードの位置を pos へ写す並び (原典は x を p 相対, z / y を &mover.pos 相対で書く), 試済: &mover.pos のローカルを全部に使う (234)
NON_MATCH void Octopus_StateVanish(Octopus* p) {
#ifdef NONMATCHING_C
  if (!Enemy_ConsumeStateBegun(&p->e)) {
    return;
  }
  (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
  (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
  Enemy_PlayAnimNoFacing(&p->e, 20);
  if ((p->e).spriteKind == 0) {
    Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + 3);
  } else {
    (p->e).s->main.spr.pltt = &gObjPlttData[((p->e).plttBase + 3) * 16];
  }
  Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  (p->e).s->aux.spr.priority = 3;
  Entity081ea120_Spawn(&(p->e).mover.pos, 1, 2, 1, 276);
  PlaySound_082406e0(SONG_473);
  Enemy_Deactivate(&p->e);
  if ((p->e).spriteKind == 0) {
    Video_SetAuxSpritePltt(&(p->e).s->aux.gfx, (p->e).plttBase + (p->e).variant);
  } else {
    (p->e).s->main.spr.pltt = &gObjPlttData[((p->e).plttBase + (p->e).variant) * 16];
  }
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  Enemy_ResetState(&p->e, 3, 0, 0);
  {
    PathWalker* walker = &(p->e).pathWalker;

    (p->e).mover.pos.x = walker->node->x;
    (p->e).mover.pos.z = walker->node->y;
    (p->e).mover.pos.y = TileHeightAt(&(p->e).mover.pos);
  }
  Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
#else
  INCFUNC("asm/func/Octopus_StateVanish.inc");
#endif
}

void Octopus_StateDamaged(Octopus* p, s32 timer) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimFlipOnly(&p->e, 3);
    PlaySound_082406e0(SE_ENEMY_DAMAGED);
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
    Enemy_EnterState(&p->e, Octopus_StateSubmerge, ES_UNK_34);
    Enemy_ResetState(&p->e, 1, 0, 3);
    (p->e).mover.angle = (p->e).playerAngle;
  }
}

// 回りながら跳ね飛ばされ, 着地 (ENEFLAG2_UNK_4) したら煙を出して倒されたスクリプトを呼び図鑑に載せ, OctopusGroup に倒れたことを知らせる
// 404/411命令の下書き, 倒れたあとの後始末は DarkRoot_StateDying と同じ形 (原典は defeatScript の引数をスタックに作り置く壁), 1回目の下書きで切り上げ
NON_MATCH void Octopus_StateDying(Octopus* p, s32 timer) {
#ifdef NONMATCHING_C
  Octopus* q = (p->e).owner;
  EnemyAuxSprite* aux = &(p->e).s->aux;

  if (Enemy_ConsumeStateBegun(&p->e)) {
    Enemy_PlayAnimFlipOnly(&p->e, 3);
    Enemy_SetEmote(&p->e, 0, 0x7F, 0);
    Enemy_SetEmote(&p->e, 1, 0x7F, 0);
    Enemy_SetEmote(&p->e, 3, 0x7F, 0);
    Enemy_FadeParticles(&p->e, 4);
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_6);
    (p->e).hp = 1;
    (p->e).heightAboveFloor = 0;
    ClearMemory(q->unk_658, 8);
    (p->e).jumpVel.y = (Random() & 7) + 72;
    q->spinSpeed = Random() | 0xFFE0;
    (p->e).unk_1bc = 0;
    if (abs(q->spinSpeed) < 10) {
      q->spinSpeed = 10;
    }
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_AFFINE);
    PlayEnemyDeathCry(&p->e);
  }
  aux->spr.rotation += q->spinSpeed;
  {
    u32 a = (416 - aux->spr.rotation) & 0xFF;

    aux->spr.pos.z -= (gSineTable[a] * 33) >> 11;
    aux->spr.pos.x -= (gSineTable[(a + 0x40) & 0xFF] * 33) >> 11;
  }
  if (TEST_FLAGS((p->e).flags2, ENEFLAG2_UNK_4)) {
    s32 idx;
    u16 msg[1];

    SET_FLAGS((p->e).flags3, ENEFLAG3_UNK_6);
    (p->e).hp = 0;
    Entity081ea120_Spawn(&(p->e).mover.pos, 1, 2, 0, 276);
    PlaySound_082406e0(SONG_472);
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    Enemy_ClearSpriteFlags(&p->e, SPRFLAG_AFFINE);
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
    msg[0] = 8;
    if (((Octopus*)(p->e).owner)->groupID != 0) {
      Enemy_SendMsgById(ENEK_15, msg, ((Octopus*)(p->e).owner)->groupID);
    }
  } else if (Mod(timer, 4) == 0) {
    (p->e).jumpVel.y -= 8;
  }
#else
  INCFUNC("asm/func/Octopus_StateDying.inc");
#endif
}

s32 Octopus_PreUpdate(Octopus* p) {
  Hitbox_Hide(&(p->e).hitbox);
  return 1;
}

s32 Octopus_PostUpdate(Octopus* p) {
  Hitbox_SetPos(&(p->e).hurtbox, &(p->e).mover.pos, 0);
  return 1;
}

void Octopus_SubLurk(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    (p->e).hurtbox.flags |= HBFLAG_HIDDEN;
    (p->e).hurtbox.flags &= ~HBFLAG_UNK_3;
    SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_11);
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  }
  if (!Octopus_FindAdjacentTarget(p, 1)) {
    if ((p->e).subStateTimer > 60) {
      Enemy_ResetState(&p->e, 0, 2, 5);
    } else {
      (p->e).subStateTimer++;
    }
  } else {
    Enemy_ResetState(&p->e, 0, 0, 2);
    Enemy_EnterState(&p->e, Octopus_StateEmerge, ES_UNK_40);
  }
}

void Octopus_SubEmergeAndWait(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Octopus_StateEmerge, ES_UNK_40);
    (p->e).animForceRestart = 0;
  }
  if ((p->e).animForceRestart || (p->e).state == ES_UNK_33) {
    if (Octopus_FindAdjacentTarget(p, 1)) {
      Enemy_ClearSpriteFlags(&p->e, SPRFLAG_HIDDEN);
      Enemy_ResetState(&p->e, 3, 0, 0);
      Enemy_EnterState(&p->e, Octopus_StateGrab, ES_UNK_3);
    }
    if ((p->e).state == ES_UNK_33 && (p->e).subStateTimer > 180) {
      Enemy_ResetState(&p->e, 0, 0, 0);
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
      return;
    }
  }
  (p->e).subStateTimer++;
}

void Octopus_SubFindThrowTarget(Octopus* p) {
  Mover* m;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  m = Octopus_FindNearestPlayer(p);
  if (m != NULL) {
    (p->e).playerMover = m;
    Enemy_EnterState(&p->e, Octopus_StateThrow, ES_UNK_44);
    Enemy_ResetState(&p->e, 3, 0, 0);
  } else {
    if ((p->e).subStateTimer > 300 || Octopus_FindAdjacentTarget(p, 1)) {
      Enemy_ResetState(&p->e, 0, 0, 1);
      Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
    }
    (p->e).subStateTimer++;
  }
}

void Octopus_SubWatch(Octopus* p) {
  Octopus* q = (p->e).owner;
  Mover* m = (p->e).playerMover;

  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    q->lostTimer = 0;
  }
  if (!Octopus_FindAdjacentTarget(p, 1)) {
    if (q->lostTimer > q->lostTimeout) {
      Enemy_ResetState(&p->e, 0, 0, 0);
    } else {
      q->lostTimer++;
    }
  } else {
    q->lostTimer = 0;
  }
  if ((p->e).subStateTimer > 30 && q->lostTimer == 0) {
    (p->e).mover.angle = ArcTan2_8(m->pos.x - (p->e).mover.pos.x, m->pos.z - (p->e).mover.pos.z);
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, Octopus_StateGrab, ES_UNK_3);
  }
  (p->e).subStateTimer++;
}

// 引っ込む状態へ移し, 終わったら 30 フレーム後に止まる予約を入れる
// 102/102命令, Octopus_OnGroupDefeatedMsg と同じ残差 (原典は &subStateDone を r6 に持ち越し, 予約の handler と定数 1 を先に用意してから書く)
NON_MATCH void Octopus_SubHide(Octopus* p) {
#ifdef NONMATCHING_C
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_EnterState(&p->e, Octopus_StateSubmerge, ES_UNK_34);
    (p->e).subStateDone = 0;
  }
  if ((p->e).subStateDone) {
    (p->e).pendingDelay = 30;
    (p->e).pendingHandler = Enemy_ClearStateBegun;
    (p->e).pendingSubState0 = 0;
    (p->e).pendingSubState1 = 0;
    (p->e).pendingSubState2 = 1;
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_EnterState(&p->e, FUN_080e68d8, ES_UNK_14);
  }
#else
  INCFUNC("asm/func/Octopus_SubHide.inc");
#endif
}

void FUN_08186a7c(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, Octopus_StateHold, ES_UNK_36);
    Enemy_ResetState(&p->e, 0, 2, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

void FUN_08186b10(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
}

void Octopus_SubMissCooldown(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateTimer > 60) {
    Enemy_ResetState(&p->e, 0, 0, 0);
  }
  (p->e).subStateTimer++;
}

void Octopus_SubHold(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, Octopus_StatePullUnder, ES_UNK_37);
    Enemy_ResetState(&p->e, 0, 2, 2);
  }
}

void Octopus_SubPullUnder(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    Enemy_EnterState(&p->e, Octopus_StateSlam, ES_UNK_39);
    Enemy_ResetState(&p->e, 0, 2, 4);
  }
}

void FUN_08186c88(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
}

void Octopus_SubDamageCooldown(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).chaseTimeMax <= (p->e).subStateTimer) {
    Enemy_ResetState(&p->e, 0, 0, 1);
  } else {
    (p->e).subStateTimer++;
  }
}

void Octopus_SubDamagedSubmerge(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
  }
  if ((p->e).subStateDone) {
    Enemy_ResetState(&p->e, 1, 0, 0);
    Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
  }
}

void Octopus_SubDeactivate(Octopus* p) {
  if (Enemy_ConsumeSubStateBegun(&p->e)) {
    Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
    Enemy_ResetState(&p->e, 3, 0, 0);
    Enemy_Deactivate(&p->e);
  }
  (p->e).subStateTimer++;
}

void Octopus_InitHandlerTables(Octopus* p) {
  (p->e).handlerTables[2] = (void*)PTR_ARRAY_085adc84;
  (p->e).handlerTables[4] = (void*)PTR_ARRAY_085adc6c;
  (p->e).handlerTables[6] = (void*)PTR_ARRAY_085adc98;
}

s32 Octopus_OnDamaged(Octopus* p) {
  if (TEST_FLAGS((p->e).flags3, ENEFLAG3_UNK_8)) {
    CLEAR_FLAGS((p->e).flags3, ENEFLAG3_UNK_5);
    return FALSE;
  }
  Enemy_ResetState(&p->e, 3, 0, 0);
  Enemy_EnterState(&p->e, Octopus_StateDamaged, ES_UNK_41);
  return TRUE;
}

void Octopus_InitAnims(Octopus* p) {
  Enemy_SetAnimEntry(&p->e, 14, 0, 0);
  Enemy_SetAnimEntry(&p->e, 20, 8, 0);
  Enemy_SetAnimEntry(&p->e, 15, 1, 0);
  Enemy_SetAnimEntry(&p->e, 16, 2, 0);
  Enemy_SetAnimEntry(&p->e, 3, 7, 0);
  Enemy_SetAnimEntry(&p->e, 5, 3, 0);
  Enemy_SetAnimEntry(&p->e, 17, 4, 0);
  Enemy_SetAnimEntry(&p->e, 18, 5, 0);
  Enemy_SetAnimEntry(&p->e, 19, 6, 0);
}

// 復帰時に印と lostTimer を消し, 位置をタイルの中心へずらしてスプライトに写し, 待機アニメを流して1コマ送る
// 147/148命令, DarkRoot_OnReset / Dog_OnReset / Golem_OnReset と同じ壁 (p->sprite を r0 に読んでから r5 へ移す)
NON_MATCH void Octopus_OnReset(Octopus* p) {
#ifdef NONMATCHING_C
  Octopus* q = (p->e).owner;
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
  INCFUNC("asm/func/Octopus_OnReset.inc");
#endif
}

void Octopus_InitHitboxes(Octopus* p) {
  Vec3 hurtSize, hurtOffset, hitSize, hitOffset;

  VEC3_SET(hurtSize, 64, 256, 64);
  VEC3_SET(hurtOffset, 0, 128, 0);
  Enemy_RegisterHurtboxWithFlags(&p->e, &hurtSize, &hurtOffset, Octopus_OnHurt, p, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_HIDDEN | HBFLAG_UNK_0);
  VEC3_SET(hitSize, 0, 0, 0);
  VEC3_SET(hitOffset, 0, 0, 0);
  Enemy_InitAtkHitbox(&p->e, &hitSize, &hitOffset, Octopus_OnHit, 1, p);
}

// 姿を隠したまま活動を再開させ, 60 フレーム後に Octopus_StateVanish の状態へ移る予約を入れる
// 79/80命令, 原典は pendingHandler の値と pendingDelay / pendingHandler の格納先を先に揃えてから書く (ip 経由), 試済: 予約の5行を inline にする (78)
NON_MATCH void Octopus_OnGroupDefeatedMsg(Octopus* p, u16* msg) {
#ifdef NONMATCHING_C
  Enemy_ResetState(&p->e, 3, 0, 0);
  (p->e).pendingDelay = 60;
  (p->e).pendingHandler = Octopus_StateVanish;
  (p->e).pendingSubState0 = 3;
  (p->e).pendingSubState1 = 0;
  (p->e).pendingSubState2 = 0;
  Enemy_EnterState(&p->e, FUN_080e68d8, ES_UNK_14);
  Enemy_Reactivate(&p->e);
  Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
#else
  INCFUNC("asm/func/Octopus_OnGroupDefeatedMsg.inc");
#endif
}

void Octopus_CreateGroup(Octopus* p) {
  if ((p->e).variant == 1) {
    Octopus* q = (p->e).owner;
    u32 id = VM_GetNamedArgValue('B', 0);
    u16 msg[3];

    OctopusGroup_Create(id);
    msg[0] = 7;
    msg[1] = (p->e).mover.id;
    msg[2] = (p->e).kind;
    Enemy_SendMsgById(ENEK_15, msg, id);
    q->groupID = id;
  }
}

void Octopus_EnterHidden(Octopus* p) {
  Enemy_PlayAnimFlipOnly(&p->e, 16);
  Enemy_SetSpriteFlags(&p->e, SPRFLAG_HIDDEN);
  Enemy_ResetState(&p->e, 0, 0, 1);
  Enemy_EnterState(&p->e, Enemy_ClearStateBegun, ES_INACTIVE);
}

Mover* Octopus_FindNearestPlayer(Octopus* p) {
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

    if (player != NULL && !Player_TestFlag20(player, PFLAG20_UNK_12)) {
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

Mover* Octopus_FindAdjacentTarget(Octopus* p, s32 faceTarget) {
  u32 best = (p->e).range0Sq;
  Mover* target = Octopus_FindNearestPlayer(p);
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

s32 Octopus_GetGrabbedAnimOffset(Octopus* p) {
  AuxAnimState* anim = &(p->e).s->aux.anim;

  if (anim->cmdIdx == 3) {
    return 1;
  }
  if (anim->cmdIdx == 4) {
    return 0;
  }
  return anim->cmdIdx;
}

s32 Octopus_UpdateFrame(Octopus* p) {
  Octopus_PreUpdate(p);
  {
    u32 idx = (p->e).subState0;
    EnemyHandler* table = (p->e).handlerTables[0];

    table[idx](&p->e);
  }
  Enemy_RunStateHandler(&p->e);
  Octopus_PostUpdate(p);
  return 1;
}

s32 Octopus_Update(Octopus* p) {
  Enemy_Update(&p->e);
  return 0;
}

s32 Octopus_Destroy(Octopus* p) {
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
// 1602/1757命令, DarkRoot_Init の下書きをオクトパス向けに直したもの ('.d' が無く, variant 1 の OctopusGroup を Octopus_CreateGroup で作る), 原典は Enemy のフィールドのアドレスをスタックに作り置く (敵共通の初期化 inline の壁), 1回目の下書きで切り上げ
NON_MATCH s32 Octopus_Init(Octopus* p) {
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
  (p->e).kind = ENEK_OCTOPUS;
  Octopus_InitAnims(p);
  if ((p->e).spriteKind == 0) {
    EnemyAuxSprite* aux;
    u8 k;

    (p->e).s = Malloc(sizeof(EnemyAuxSprite));
    ClearMemory((p->e).s, sizeof(EnemyAuxSprite));
    aux = &(p->e).s->aux;
    Video_GetAuxSprite(&aux->gfx, SPRITE_OCTOPUS);
    AuxSprite_Add(&aux->spr, &aux->gfx, 0);
    EnemyAuxSprite_LoadAnim(aux, ANIM_OCTOPUS);
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
    f = GetFile(DIR_MAIN_SPRITE, SPRITE_OCTOPUS);
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
    p->lostTimeout = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->squeezeInterval = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->escapeMashCount = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  (p->e).mover.pos.x += 32;
  (p->e).mover.pos.z += 32;
  Enemy_SetSpritePos(&p->e, &(p->e).mover.pos);
  (p->e).variant = VM_GetNamedArgValue('C', 0);
  (p->e).plttBase = 447;
  (p->e).unk_47c = 306;
  (p->e).unk_47e = (p->e).variant + 447;
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

  Octopus_InitHitboxes(p);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_13);
  (p->e).navAgent = &p->navAgent;
  (p->e).pathNodePos = &p->pathNodePos;
  (p->e).handlerFrame = (EnemyHandler)Octopus_UpdateFrame;
  (p->e).getMoveSpeed = NULL;
  (p->e).handlerTurn = NULL;
  (p->e).handlerMove = NULL;
  (p->e).handlerWait = NULL;
  (p->e).unk_5c0 = NULL;
  (p->e).onRouteFailed = NULL;
  (p->e).handlerDamaged = NULL;
  (p->e).handlerDying = (void*)Octopus_StateDying;
  (p->e).unk_5d4 = FUN_080f44f4;
  (p->e).unk_5dc = FUN_080f410c;
  (p->e).unk_5c8 = NULL;
  (p->e).unk_584 = (void*)FUN_08184dd8;
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
  (p->e).onReset = (EnemyHandler)Octopus_OnReset;
  (p->e).onAttackRequest = NULL;
  (p->e).unk_5b0 = NULL;
  (p->e).onDamaged = (void*)Octopus_OnDamaged;
  (p->e).kind = ENEK_OCTOPUS;
  Enemy_InitShadowAndEmitter(&p->e);
  SET_FLAGS((p->e).flags, ENEFLAG_UNK_9);
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_3 | ENEFLAG2_UNK_10);
  SET_FLAGS((p->e).flags5, ENEFLAG5_UNK_6);
  Octopus_CreateGroup(p);
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
  Octopus_InitHandlerTables(p);
  (p->e).msgHandlers = (void*)PTR_ARRAY_085adca8;
  Octopus_EnterHidden(p);
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
  (p->e).handlerUpdate = (EnemyHandler)Octopus_Update;
  (p->e).handlerDestroy = (EnemyHandler)Octopus_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Octopus_Init.inc");
#endif
}

void Octopus_Create(void) {
  Octopus* p = Malloc(sizeof(Octopus));

  if (p != NULL) {
    ClearMemory(p, sizeof(Octopus));
    if (Octopus_Init(p) < 0) {
      Octopus_Destroy(p);
      Free(p);
    }
  }
}

void OctopusGroup_OnJoinMsg(OctopusGroup* p, u16* msg) {
  OctopusGroup* q = (p->e).owner;

  q->members[q->memberCount].id = msg[1];
  q->members[q->memberCount].kind = msg[2];
  q->memberCount++;
}

void OctopusGroup_OnLeaveMsg(OctopusGroup* p, u16* msg) { ((OctopusGroup*)(p->e).owner)->memberCount--; }

void OctopusGroup_OnAllDefeated(OctopusGroup* p) {
  OctopusGroup* q;
  u16 msg[2];
  s32 i;

  msg[0] = 9;
  q = (p->e).owner;
  for (i = 0; i < 16; i++) {
    if (q->members[i].id != 0) {
      Enemy_SendMsgById(q->members[i].kind, msg, q->members[i].id);
    }
  }
  if (gStat->unk_948[0] < 9999) {
    gStat->unk_948[0]++;
  }
  if (gStat->totalEnemyKillCount < 9999) {
    gStat->totalEnemyKillCount++;
  }
  Enemy_AddKillCount(&p->e);
}

s32 OctopusGroup_Update(OctopusGroup* p) {
  Hitbox_Hide(&(p->e).hitbox);
  Hitbox_Hide(&(p->e).hurtbox);
  if (p->memberCount < 1) {
    OctopusGroup_OnAllDefeated(p);
    OctopusGroup_Destroy(p);
    Free(p);
  }
  return 0;
}

s32 OctopusGroup_Destroy(OctopusGroup* p) {
  Enemy_Unregister(&p->e);
  return 0;
}

// OctopusGroup の初期化, mover.id を id にして倒されたスクリプトの引数を読み, メッセージ表を付けて登録する
// 79/79命令, 残差は入口で引数を退避する2命令の順だけ (原典は id を先に r4 へ移す), 1回目の下書きで切り上げ
NON_MATCH s32 OctopusGroup_Init(OctopusGroup* p, u32 id) {
#ifdef NONMATCHING_C
  s32 i;

  Enemy_SetOwnerAndSpriteKind(&p->e, p, 0);
  (p->e).mover.id = id;
  (p->e).kind = ENEK_15;
  SET_FLAGS((p->e).flags2, ENEFLAG2_UNK_25);
  (p->e).unk_198 = VM_GetNamedArgValue('I', 0);
  if (VM_SeekToNamedArg('G')) {
    u32* arg = &(p->e).unk_19c;

    for (i = 0; i < 5; i++) {
      *arg = VM_GetPC() != NULL ? VM_GetValue() : 0;
      arg++;
    }
  }
  (p->e).defeatScriptID = VM_GetNamedArgValue('D', 0);
  (p->e).msgHandlers = (void*)PTR_ARRAY_085adcd0;
  (p->e).handlerMsg = (EnemyMsgHandler)Enemy_DispatchMsg;
  (p->e).handlerUpdate = (EnemyHandler)OctopusGroup_Update;
  (p->e).handlerDestroy = (EnemyHandler)OctopusGroup_Destroy;
  if (!Enemy_Register(&p->e)) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/OctopusGroup_Init.inc");
#endif
}

void OctopusGroup_Create(u32 id) {
  OctopusGroup* p;

  if (FindEnemyById(id) == NULL) {
    p = Malloc(sizeof(OctopusGroup));
    if (p != NULL) {
      ClearMemory(p, sizeof(OctopusGroup));
      if (OctopusGroup_Init(p, id) < 0) {
        OctopusGroup_Destroy(p);
        Free(p);
      }
    }
  }
}
