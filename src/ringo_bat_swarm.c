#include "constants/miscs.h"
#include "constants/sprite.h"
#include "constants/sprite_palette.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "inline.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite_aux.h"
#include "sprite_pltt.h"
#include "trig.h"
#include "vec3.h"
#include "video.h"

void Ringo_ReappearAt(Vec3* pos);
void Ringo_AddPendingHeal(s32 n);
void Ringo_AddPendingDamage(s32 n);
bool32 BlackHole_IsActive(void);
void BlackHole_GetCenter(Vec3* out);

// コウモリ1匹
typedef struct {
  bool8 stateEntered;     // 0x000, state が変わると 1, 各 state の最初のフレームで 0 に戻す
  u8 state;               // 0x001, sRingoBatStates の添字 (0: 散開, 1: target の近くへ寄る, 2: target を狙う, 3: うろつく, 4: 突進, 5: ブラックホールへ寄る, 6: 被弾してブラックホールへ飛ぶ, 7: ブラックホールの中を漂う, 8: 被弾, 9: goal へ戻る, 10: goal で待つ, 11: 止まる)
  bool8 animLooped;       // 0x002, anim が先頭のコマへ戻ったフレームだけ 1, 読み手は見つかっていない
  u8 bobAngle;            // 0x003, 毎フレーム 4 進む, sprite.pos.y を gSineTable で上下に揺らす
  u16 timer;              // 0x004, state に入ってからのフレーム数
  u8 angle;               // 0x006, 進む向き, gSineTable の添字
  u8 turnTimer;           // 0x007, 0 になると angle を選び直し, 乱数で入れ直す
  s8 targetIdx;           // 0x008, RingoBatSwarm.targets の添字, -1 なら追わない
  u8 retargetTimer;       // 0x009, 0 になると targetIdx を targetCount から決め直す, 被弾すると 250 にして targetIdx を 0 にする (-1 のときを除く)
  u8 unk_a[4];            // 0x00A
  u16 baseY;              // 0x00E, 開始時の pos.y, state 7 以外では pos.y が毎フレーム 1 ずつここへ寄る
  u16 speed;              // 0x010, 1フレームの移動量, gSineTable との積を 12bit 右シフトして足す, state 9 では 16
  u16 unk_12;             // 0x012, 10 が入るだけ
  Vec3 pos;               // 0x014, sprite.pos へ写す
  Vec3 dest;              // 0x01C, state 1, 5, 6, 7, 9 で向かう点
  Vec3 lungeOrigin;       // 0x024, state 4 の突進の起点, ここから angle の向きへ最大 256 出て戻る
  HitboxData hitbox;      // 0x02C, state 4 の間だけ登録する, 攻撃力は power
  HitboxData hurtbox;     // 0x07C, 防御力は defense, 当たると state 6 か 8 へ移る
  AuxAnimState anim;      // 0x0CC, コマ送りは自前で行う
  AuxSprite sprite;       // 0x0DC
  AuxSpriteGfx gfx;       // 0x108, SPRITE_BAT, パレット 611 (被弾直後の 6 フレームは 306), pltt は RingoBatSwarm.pltt を指す
  ParticleShadow shadow;  // 0x124
} RingoBat;
static_assert(sizeof(RingoBat) == 356);

// Ringo がブラックホールの拘束から解けたときにコウモリ16匹に分かれて襲う技 (攻略本に技名はない), 散開して targets を狙い, 600 フレームで goal へ集まり, 終わると Ringo を goal に戻す
typedef struct RingoBatSwarm {
  Entity e;               // 0x000, ENTITY_UNK_8
  bool32 active;          // 0x018, 0 の間は何も更新しない
  bool8 blackHoleActive;  // 0x01C, gBlackHole が state 6 の間 1, 立つと要素はブラックホールへ吸われる
  bool8 finished;         // 0x01D, 全要素が state 7 か 10 に揃うか timer が 1200 に達すると 1, 立つと全要素を隠して Ringo を goal に戻す
  bool8 returning;        // 0x01E, timer が 600 に達すると 1, 立つと要素は goal へ戻る
  u8 targetCount;         // 0x01F, targets の数, 2 なら前半8匹が targets[1] を, 後半8匹が targets[0] を追い, 0 なら全員 targets[0], それ以外は追わない
  u16 power;              // 0x020, 10
  u16 defense;            // 0x022, 100
  u32 timer;              // 0x024, 開始からのフレーム数
  WorldPos* targets[2];   // 0x028, &gPlayerPtr[i]->mover.pos (0: ジャンゴ, 1: 共闘サバタ)
  Vec3 blackHolePos;      // 0x030, ブラックホールがいなければ前の値のまま
  Vec3 goal;              // 0x038
  AuxAnimFile* anim;      // 0x040, ANIM_BAT
  RingoBat elems[16];     // 0x044
  s8 fadeMode;            // 0x1684, -1: 止める, 0: fadeLevel を 63 まで上げる, 1: 0 まで下げる, 2: 32 まで上げる
  s8 fadeLevel;           // 0x1685, pltt をパレット 611 から 612 へ寄せる度合い, 64 で 612 そのもの
  u8 unk_1686[2];         // 0x1686
  rgb555 pltt[16];        // 0x1688, elems[i].gfx.pltt がここを指す
} RingoBatSwarm;
static_assert(sizeof(RingoBatSwarm) == 5800);

// 4 方向の向き dir を左右反転とアニメの variant に分ける, cutscene_bat_swarm.c の CutsceneBatSwarm_GetAnimVariant と同じ
static inline void RingoBat_GetAnimVariant(u8 dir, u8* variant, u8* xflip) {
  if (dir == DIR4_EAST || dir == DIR4_SOUTH) {
    *variant = 1;
  } else {
    *variant = 0;
  }
  if (dir > DIR4_EAST) {
    *xflip = TRUE;
  } else {
    *xflip = FALSE;
  }
}

// 要素のパレットを plttID に戻し, 色はブレンド済みの p->pltt を使わせる
static inline void RingoBat_SetPltt(RingoBatSwarm* p, AuxSpriteGfx* gfx, s32 plttID) {
  Video_SetAuxSpritePltt(gfx, plttID);
  gfx->pltt = p->pltt;
}

// 追う targets の添字を入れる, -1 なら追わない
static inline void RingoBat_SetTarget(RingoBat* elem, u8 targetIdx) { elem->targetIdx = targetIdx; }

// 状態を入れ替えて経過フレームを0に戻す
static inline void RingoBat_SetState(RingoBat* elem, u8 state) {
  elem->state = state;
  elem->stateEntered = TRUE;
  elem->timer = 0;
}

// 攻撃の向きへ弾かれ, ダメージの数字を出してそのぶん Ringo にもダメージを与える, ブラックホールがあればそこへ飛ぶ
// 残差は原典が targetIdx の判定の前に 0 を r8 に作り, targetIdx = 0 と state 6 の timer = 0 で使い回す点 (86/92命令, 差は r8 の退避と 0 の作り方)
// 試済: SetState の展開, 引数で 0 を渡す inline, ofs の設定を前に移す, 未: 0 を分岐前に作る自然な形
NON_MATCH void RingoBat_OnHurt(HitboxData* a, HitboxData* b, RingoBat* elem) {
#ifdef NONMATCHING_C
  Vec3 ofs;

  if (TEST_FLAGS(a->flags, HBFLAG_ANGLE)) {
    elem->angle = a->angle;
  } else {
    elem->angle = ArcTan2_8(b->center.x - a->center.x, b->center.z - a->center.z);
  }
  if (elem->targetIdx >= 0) {
    elem->retargetTimer = 250;
    elem->targetIdx = 0;
  }
  Hitbox_ApplyDamage(a, b);
  VEC3_SET(ofs, 16, 0, 16);
  CreateDamageNumber(b, b->damage, 0, &elem->pos, &ofs, 1);
  a->damage += 2;
  Ringo_AddPendingDamage(b->damage);
  if (BlackHole_IsActive()) {
    RingoBat_SetState(elem, 6);
  } else {
    RingoBat_SetState(elem, 8);
  }
  PlaySound_082406e0(CRY_BAT_DAMAGED);
#else
  INCFUNC("asm/func/RingoBat_OnHurt.inc");
#endif
}

// 当てたダメージを回復の数字で出し, そのぶん Ringo の HP を回復させる
void RingoBat_OnHit(HitboxData* a, HitboxData* b, RingoBat* elem) {
  Vec3 ofs;

  Hitbox_ApplyDamage(a, b);
  VEC3_SET(ofs, 16, 0, 16);
  CreateDamageNumber(a, b->damage, 1, &elem->pos, &ofs, 1);
  Ringo_AddPendingHeal(b->damage);
}

// 要素1つ分のスプライトと影と当たり判定を用意する, 原典は return を書き忘れている
// 残差は冒頭で原典が 0 を r1 に1本置いて state / timer / angle に使い, elem を sl の写しから書く点 (153/154命令), CutsceneBat_Init / VampireSword_Init と同じ壁
// 試済: 状態と角度をまとめて受ける inline, 未: 冒頭の 0 を1本の擬似レジスタにする形
NON_MATCH s32 RingoBat_Init(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSpriteGfx* gfx;
  AuxSprite* sprite;
  Vec3* pos;
  HitboxData* hitbox;
  Vec3 halfSize, offset;

  RingoBat_SetState(elem, 0);
  elem->angle = 0;
  gfx = &elem->gfx;
  Video_GetAuxSprite(gfx, SPRITE_BAT);
  RingoBat_SetPltt(p, gfx, 611);
  sprite = &elem->sprite;
  AuxSprite_Add(sprite, gfx, SPRFLAG_HIDDEN);
  sprite->priority = 2;
  pos = &sprite->pos;
  Vec3_Clear(pos);
  ParticleShadow_Init(&elem->shadow, pos, 0);
  ParticleShadow_Hide(&elem->shadow);

  hitbox = &elem->hurtbox;
  VEC3_SET(halfSize, 32, 240, 32);
  VEC3_SET(offset, 0, 120, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HURTBOX | HBFLAG_HIDDEN | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &elem->pos, 0);
  Hitbox_SetHandler(hitbox, RingoBat_OnHurt, elem);
  Hitbox_SetPowerAndAttributes(hitbox, p->defense, HBATTR_BEAST, 0);
  Hitbox_Register(hitbox);

  hitbox = &elem->hitbox;
  VEC3_SET(halfSize, 32, 240, 32);
  VEC3_SET(offset, 0, 120, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &elem->pos, 0);
  Hitbox_SetHandler(hitbox, RingoBat_OnHit, elem);
  Hitbox_SetAttack(hitbox, p->power, 30, 0x1000, 0, 30);
#else
  INCFUNC("asm/func/RingoBat_Init.inc");
#endif
}

// 原典は return を書き忘れている
s32 RingoBat_Destroy(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  Hitbox_Unregister(&elem->hurtbox);
  ParticleShadow_Remove(&elem->shadow);
  AuxSprite_Remove(&elem->sprite);
}

// sprite と影を隠して食らい判定を外す, 原典は return を書き忘れている
s32 RingoBat_Hide(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  HitboxData* hurtbox;

  elem->sprite.flags |= SPRFLAG_HIDDEN;
  hurtbox = &elem->hurtbox;
  hurtbox->flags |= HBFLAG_HIDDEN;
  ParticleShadow_Hide(&elem->shadow);
}

// 全要素を隠して Ringo を goal に戻し, 群れを止める
void RingoBatSwarm_Finish(RingoBatSwarm* p) {
  RingoBat* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    RingoBat_Hide(p, elem, i);
  }
  Ringo_ReappearAt(&p->goal);
  p->active = FALSE;
}

// angle の向きに合わせた variant と左右反転で animIdx のアニメを流す
void RingoBat_SetAnim(RingoBatSwarm* p, RingoBat* elem, u32 animIdx) {
  u8 variant;
  u8 xflip;

  RingoBat_GetAnimVariant(Angle_ToDir4(elem->angle), &variant, &xflip);
  AuxAnim_SetAnim(&elem->anim, p->anim, animIdx, variant, xflip);
}

// pos をスプライトへ写してアニメを進め, ブラックホールの中以外では高さを baseY へ寄せながら上下に揺らす
void RingoBat_UpdateSprite(RingoBat* elem) {
  AuxSprite* sprite = &elem->sprite;

  elem->sprite.pos = elem->pos;
  elem->animLooped = AuxSprite_AdvanceAnim(sprite, &elem->anim);
  if (elem->state != 7) {
    if (elem->pos.y > elem->baseY) {
      elem->pos.y--;
    } else if (elem->pos.y < elem->baseY) {
      elem->pos.y++;
    }
    sprite->pos.y += POLAR_Z(32, elem->bobAngle);
  }
  elem->bobAngle += 4;
}

// angle の向きへ倍速で散り, idx + 2 フレーム経ったら target の近くへ寄りに行く
void RingoBat_UpdateSpread(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  Vec3 vel;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
  }
  Vec3_SetPolar(&vel, elem->angle, elem->speed * 2);
  Vec3_Add(&elem->pos, &vel);
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  RingoBat_SetAnim(p, elem, 0);
  if (elem->timer >= idx + 2) {
    RingoBat_SetState(elem, 1);
  }
  elem->timer++;
}

// target の方を向いて浮かび, 64 フレーム経ったら突進する, 離れすぎたら寄り直す
// 残差は targetIdx の ldrsb を原典は &elem->pos を作る前に置く位置だけ (149/149命令), SetTarget inline と x を elem->pos.x で読む形で残りは揃った
// 試済: pos を if の中に入れる (関数スコープ / ブロックスコープ), targetIdx をローカルに読む
NON_MATCH void RingoBat_UpdateAim(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
#ifdef NONMATCHING_C
  Vec3* pos;

  if (elem->stateEntered) {
    HitboxData* hurtbox;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    CLEAR_FLAGS(hurtbox->flags, HBFLAG_HIDDEN);
    Hitbox_SetPos(hurtbox, &elem->pos, 0);
  }
  if (p->blackHoleActive) {
    RingoBat_SetState(elem, 5);
    return;
  }
  if (p->returning) {
    RingoBat_SetState(elem, 9);
    return;
  }
  pos = &elem->pos;
  if (elem->targetIdx >= 0) {
    if ((elem->timer & 7) == 0) {
      s32 dx = p->targets[elem->targetIdx]->x - elem->pos.x;
      s32 dz = p->targets[elem->targetIdx]->z - pos->z;

      if (dx * dx + dz * dz > 378 * 378) {
        RingoBat_SetState(elem, 1);
        return;
      }
    }
    elem->angle = ArcTan2_8(p->targets[elem->targetIdx]->x - elem->pos.x, p->targets[elem->targetIdx]->z - pos->z);
  }
  Hitbox_SetPos(&elem->hurtbox, pos, 0);
  RingoBat_SetAnim(p, elem, 0);
  if (elem->timer >= 64) {
    RingoBat_SetState(elem, 4);
  }
  if (elem->retargetTimer != 0) {
    if (--elem->retargetTimer == 0) {
      if (p->targetCount == 2) {
        if (idx < 8) {
          RingoBat_SetTarget(elem, 1);
        } else {
          RingoBat_SetTarget(elem, 0);
        }
      } else if (p->targetCount == 0) {
        RingoBat_SetTarget(elem, 0);
      } else {
        RingoBat_SetTarget(elem, -1);
      }
    }
  }
  elem->timer++;
#else
  INCFUNC("asm/func/RingoBat_UpdateAim.inc");
#endif
}

// target の周り 256 の点へ向きを散らしながら寄っていき, 128 以内に入ったら狙う
// 残差は向きを乱数で選び直す else 側で, 原典は乱数表のアドレスをプールから読み直すがこちらは判定の RandomNext の表を使い回す1命令と, それにつられた r4/r6/r7 の入れ替え (440/441命令)
// 試済: 判定を Random / (u8) / 表を直接引く形, else を RandomNext, 分岐の向きの入れ替え, 分岐内も外側の dest / pos を使う形
NON_MATCH void RingoBat_UpdateApproach(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 v;
  Vec3* pos;
  Vec3* dest;
  s32 dx;
  s32 dz;

  if (elem->stateEntered) {
    HitboxData* hurtbox;

    elem->stateEntered = FALSE;
    if (elem->targetIdx >= 0) {
      Vec3_SetPolar(&v, Random() & 0xFF, 256);
      Vec3_Sum(&elem->dest, p->targets[elem->targetIdx], &v);
    }
    dest = &elem->dest;
    elem->angle = ArcTan2_8(elem->dest.x - elem->pos.x, dest->z - elem->pos.z);
    elem->angle += (RandomNext() & 63) - 32;
    elem->turnTimer = (RandomNext() & 15) + 16;
    hurtbox = &elem->hurtbox;
    CLEAR_FLAGS(hurtbox->flags, HBFLAG_HIDDEN);
  }
  if (p->blackHoleActive) {
    RingoBat_SetState(elem, 5);
    return;
  }
  if (p->returning) {
    RingoBat_SetState(elem, 9);
    return;
  }
  if (elem->turnTimer == 0) {
    if ((RandomNext() & 0xFF) < 192) {
      Vec3* d;
      Vec3* cur;

      if (elem->targetIdx >= 0) {
        Vec3_SetPolar(&v, RandomNext() & 0xFF, 256);
        Vec3_Sum(&elem->dest, p->targets[elem->targetIdx], &v);
      }
      d = &elem->dest;
      cur = &elem->pos;
      elem->angle = ArcTan2_8(elem->dest.x - elem->pos.x, d->z - cur->z);
      elem->angle += (Random() & 63) - 32;
    } else {
      elem->angle = Random();
    }
    elem->turnTimer = (Random() & 15) + 16;
  } else {
    elem->turnTimer--;
  }
  Vec3_SetPolar(&v, elem->angle, elem->speed);
  Vec3_Add(&elem->pos, &v);
  pos = &elem->pos;
  dest = &elem->dest;
  Hitbox_SetPos(&elem->hurtbox, pos, 0);
  RingoBat_SetAnim(p, elem, 0);
  dx = elem->dest.x - elem->pos.x;
  dz = dest->z - pos->z;
  if (dx * dx + dz * dz < 128 * 128) {
    RingoBat_SetState(elem, 2);
    return;
  }
  if (elem->retargetTimer != 0) {
    if (--elem->retargetTimer == 0) {
      if (p->targetCount == 2) {
        if (idx < 8) {
          RingoBat_SetTarget(elem, 1);
        } else {
          RingoBat_SetTarget(elem, 0);
        }
      } else if (p->targetCount == 0) {
        RingoBat_SetTarget(elem, 0);
      } else {
        RingoBat_SetTarget(elem, -1);
      }
    }
  }
  elem->timer++;
#else
  INCFUNC("asm/func/RingoBat_UpdateApproach.inc");
#endif
}

// 乱数で向きを変えながらうろつき, 32 フレーム経ったら狙いに戻る
void RingoBat_UpdateWander(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  Vec3 vel;

  if (elem->stateEntered) {
    HitboxData* hurtbox;

    elem->stateEntered = FALSE;
    elem->angle = RandomNext();
    elem->turnTimer = (RandomNext() & 15) + 16;
    hurtbox = &elem->hurtbox;
    CLEAR_FLAGS(hurtbox->flags, HBFLAG_HIDDEN);
  }
  if (p->blackHoleActive) {
    RingoBat_SetState(elem, 5);
    return;
  }
  if (p->returning) {
    RingoBat_SetState(elem, 9);
    return;
  }
  if (elem->turnTimer == 0) {
    elem->angle = RandomNext();
    elem->turnTimer = (RandomNext() & 15) + 16;
  } else {
    elem->turnTimer--;
  }
  Vec3_SetPolar(&vel, elem->angle, elem->speed);
  Vec3_Add(&elem->pos, &vel);
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  RingoBat_SetAnim(p, elem, 0);
  if (elem->timer >= 32) {
    RingoBat_SetState(elem, 2);
    return;
  }
  if (elem->retargetTimer != 0) {
    if (--elem->retargetTimer == 0) {
      if (p->targetCount == 2) {
        if (idx < 8) {
          RingoBat_SetTarget(elem, 1);
        } else {
          RingoBat_SetTarget(elem, 0);
        }
      } else if (p->targetCount == 0) {
        RingoBat_SetTarget(elem, 0);
      } else {
        RingoBat_SetTarget(elem, -1);
      }
    }
  }
  elem->timer++;
}

// lungeOrigin から target の向きへ 256 まで突き出して戻る, 32 フレームで狙いに戻る
// 残差は dist の求め方: 原典は timer を符号なしで比べ, 上書き側で timer をメモリから読み直し, その後 dist * 16 を angle より先に作る (184/185命令)
// timer <= 15 なら timer, でなければ 32 - timer を返す inline を通すと読み直しまで揃う (185/185), 未: その inline の結果に * 16 した半径を angle より先に作る形, 狙い直しは SetTarget inline, Vec3_Sum は lungeOrigin + ofs で揃った
NON_MATCH void RingoBat_UpdateLunge(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 ofs;
  u32 dist;

  if (elem->stateEntered) {
    HitboxData* hurtbox;
    Vec3* pos;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    CLEAR_FLAGS(hurtbox->flags, HBFLAG_HIDDEN);
    pos = &elem->pos;
    elem->lungeOrigin = elem->pos;
    if (elem->targetIdx >= 0) {
      elem->angle = ArcTan2_8(p->targets[elem->targetIdx]->x - pos->x, p->targets[elem->targetIdx]->z - pos->z);
    }
  }
  if (p->blackHoleActive) {
    RingoBat_SetState(elem, 5);
    return;
  }
  if (p->returning) {
    RingoBat_SetState(elem, 9);
    return;
  }
  dist = elem->timer;
  if (dist > 15) {
    dist = 32 - elem->timer;
  }
  Vec3_SetPolar(&ofs, elem->angle, dist * 16);
  Vec3_Sum(&elem->pos, &elem->lungeOrigin, &ofs);
  Hitbox_SetPos(&elem->hitbox, &elem->pos, 0);
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  Hitbox_Register(&elem->hitbox);
  RingoBat_SetAnim(p, elem, 0);
  if (elem->timer >= 32) {
    RingoBat_SetState(elem, 2);
    return;
  }
  if (elem->retargetTimer != 0) {
    if (--elem->retargetTimer == 0) {
      if (p->targetCount == 2) {
        if (idx < 8) {
          RingoBat_SetTarget(elem, 1);
        } else {
          RingoBat_SetTarget(elem, 0);
        }
      } else if (p->targetCount == 0) {
        RingoBat_SetTarget(elem, 0);
      } else {
        RingoBat_SetTarget(elem, -1);
      }
    }
  }
  elem->timer++;
#else
  INCFUNC("asm/func/RingoBat_UpdateLunge.inc");
#endif
}

// ブラックホールの中心の周りへ回り込みながら寄っていき, 近くまで来たら中を漂う, 吸い込みが止まったら target の近くへ寄りに戻る
void RingoBat_UpdateToBlackHole(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  Vec3 vel;
  Vec3* pos;
  Vec3* dest;
  s32 dx;
  s32 dz;
  u32 distSq;

  if (elem->stateEntered) {
    HitboxData* hurtbox;
    Vec3 ofs;
    Vec3* d;

    elem->stateEntered = FALSE;
    Vec3_SetPolar(&ofs, Random() & 0xFF, 32);
    d = &elem->dest;
    Vec3_Sum(d, &p->blackHolePos, &ofs);
    elem->angle = ArcTan2_8(d->x - elem->pos.x, d->z - elem->pos.z);
    elem->angle += (RandomNext() & 63) + 0x60;
    elem->turnTimer = (RandomNext() & 31) + 32;
    hurtbox = &elem->hurtbox;
    CLEAR_FLAGS(hurtbox->flags, HBFLAG_HIDDEN);
  }
  if (!p->blackHoleActive) {
    RingoBat_SetState(elem, 1);
    return;
  }
  if (elem->turnTimer == 0) {
    Vec3* cur = &elem->pos;
    Vec3* d = &elem->dest;

    elem->angle = ArcTan2_8(elem->dest.x - elem->pos.x, d->z - cur->z);
    elem->angle += (RandomNext() & 63) + 0x60;
    elem->turnTimer = (RandomNext() & 31) + 32;
  } else {
    elem->turnTimer--;
  }
  dest = &elem->dest;
  pos = &elem->pos;
  dx = elem->dest.x - elem->pos.x;
  dz = dest->z - pos->z;
  distSq = dx * dx + dz * dz;
  if (distSq < 64 * 64) {
    RingoBat_SetState(elem, 7);
    return;
  }
  if (distSq < 256 * 256) {
    Vec3_SetPolar(&vel, elem->angle + 0x80, 5);
    Vec3_Add(&elem->pos, &vel);
  } else {
    s32 t = elem->timer & 0x7F;

    if (t < 64) {
      Vec3_SetPolar(&vel, elem->angle + 0x80, 8);
      Vec3_Add(&elem->pos, &vel);
    } else if (t < 96) {
      Vec3_SetPolar(&vel, elem->angle, 6);
      Vec3_Add(&elem->pos, &vel);
    }
  }
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  RingoBat_SetAnim(p, elem, 0);
  elem->timer++;
}

// 被弾してブラックホールの中心の近くへ飛ばされる, 着いたら中を漂い, 10 フレーム経ったらブラックホールへ寄りに行く
void RingoBat_UpdateHurtToBlackHole(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  Vec3 ofs;
  Vec3 vel;
  Vec3* pos;
  s32 dx;
  s32 dz;
  u32 distSq;

  if (elem->stateEntered) {
    HitboxData* hurtbox;
    Vec3* dest;

    elem->stateEntered = FALSE;
    Vec3_SetPolar(&ofs, Random() & 0xFF, 32);
    dest = &elem->dest;
    Vec3_Sum(dest, &p->blackHolePos, &ofs);
    elem->angle = ArcTan2_8(dest->x - elem->pos.x, dest->z - elem->pos.z);
    hurtbox = &elem->hurtbox;
    hurtbox->flags |= HBFLAG_HIDDEN;
  }
  if (!p->blackHoleActive) {
    RingoBat_SetState(elem, 1);
    return;
  }
  pos = &elem->pos;
  dx = elem->dest.x - elem->pos.x;
  dz = elem->dest.z - pos->z;
  distSq = dx * dx + dz * dz;
  if (distSq < 64 * 64) {
    RingoBat_SetState(elem, 7);
    return;
  }
  Vec3_SetPolar(&vel, elem->angle, 24);
  Vec3_Add(&elem->pos, &vel);
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  RingoBat_SetAnim(p, elem, 1);
  if (elem->timer >= 10) {
    RingoBat_SetState(elem, 5);
  } else {
    elem->timer++;
  }
}

// ブラックホールの中心のそばを向きを変えながら漂う, ブラックホールが消えたら target の近くへ寄りに戻る
// 残差は dest.x を読む ldrsh の添字レジスタが原典 r5 でこちら r0 の1か所だけ (176/176命令)
// y の移動は elem 直, 距離は pos 経由, Vec3_Add / Hitbox_SetPos は式で渡す形で揃った, 試済: dx も pos 経由, DistSq, ポインタで受ける距離 inline
NON_MATCH void RingoBat_UpdateInBlackHole(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3* pos;
  s32 dx;
  s32 dz;
  u32 distSq;

  if (elem->stateEntered) {
    HitboxData* hurtbox;

    elem->stateEntered = FALSE;
    ArcTan2_8(elem->dest.x - elem->pos.x, elem->dest.z - elem->pos.z);
    hurtbox = &elem->hurtbox;
    hurtbox->flags |= HBFLAG_HIDDEN;
    elem->turnTimer = (Random() & 15) + 16;
  }
  if (!p->blackHoleActive) {
    RingoBat_SetState(elem, 1);
    return;
  }
  if (elem->turnTimer == 0) {
    elem->angle = RandomNext();
    elem->turnTimer = (RandomNext() & 15) + 16;
  } else {
    elem->turnTimer--;
  }
  pos = &elem->pos;
  dx = elem->dest.x - elem->pos.x;
  dz = elem->dest.z - pos->z;
  distSq = dx * dx + dz * dz;
  if (elem->pos.y > elem->dest.y) {
    elem->pos.y--;
  } else if (elem->pos.y < elem->dest.y) {
    elem->pos.y++;
  }
  if (distSq < 64 * 64) {
    Vec3_SetPolar(&vel, elem->angle, 4);
    Vec3_Add(&elem->pos, &vel);
  }
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  RingoBat_SetAnim(p, elem, 0);
  elem->timer++;
#else
  INCFUNC("asm/func/RingoBat_UpdateInBlackHole.inc");
#endif
}

// 白く光って減速しながら弾かれ, 点滅して 20 フレームで target の近くへ寄りに戻る
void RingoBat_UpdateHurt(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  Vec3 vel;

  if (elem->stateEntered) {
    HitboxData* hurtbox;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    hurtbox->flags |= HBFLAG_HIDDEN;
    Video_SetAuxSpritePltt(&elem->gfx, OBP_WHITE_306);
  }
  Vec3_SetPolar(&vel, elem->angle, (20 - elem->timer) * 2);
  Vec3_Add(&elem->pos, &vel);
  RingoBat_SetAnim(p, elem, 1);
  if (elem->timer >= 20) {
    RingoBat_SetState(elem, 1);
    AuxSprite_Show(&elem->sprite);
  } else {
    if (elem->timer == 6) {
      RingoBat_SetPltt(p, &elem->gfx, 611);
    }
    if ((elem->timer >> 2) & 1) {
      AuxSprite_Show(&elem->sprite);
    } else {
      AuxSprite_Hide(&elem->sprite);
    }
    elem->timer++;
  }
}

// goal の周りの点へ向きを少し散らしながら戻り, goal から 128 以内に入ったらそこで待つ
void RingoBat_UpdateReturn(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  Vec3 vel;
  Vec3* pos;
  s32 dx;
  s32 dz;

  if (elem->stateEntered) {
    HitboxData* hurtbox;
    Vec3* dest;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    hurtbox->flags |= HBFLAG_HIDDEN;
    Vec3_SetPolar(&vel, RandomNext() & 0xFF, (RandomNext() & 63) + 16);
    dest = &elem->dest;
    Vec3_Sum(dest, &p->goal, &vel);
    elem->angle = ArcTan2_8(dest->x - elem->pos.x, dest->z - elem->pos.z);
    elem->angle += (RandomNext() & 15) - 8;
    elem->turnTimer = (RandomNext() & 7) + 8;
    elem->speed = 16;
  }
  if (p->blackHoleActive) {
    RingoBat_SetState(elem, 5);
    return;
  }
  if (elem->turnTimer == 0) {
    Vec3* cur = &elem->pos;

    elem->angle = ArcTan2_8(elem->dest.x - elem->pos.x, elem->dest.z - cur->z);
    elem->angle += (RandomNext() & 3) - 1;
    elem->turnTimer = (RandomNext() & 7) + 8;
  } else {
    elem->turnTimer--;
  }
  Vec3_SetPolar(&vel, elem->angle, elem->speed);
  Vec3_Add(&elem->pos, &vel);
  RingoBat_SetAnim(p, elem, 0);
  pos = &elem->pos;
  dx = p->goal.x - elem->pos.x;
  dz = p->goal.z - pos->z;
  if (dx * dx + dz * dz < 128 * 128) {
    RingoBat_SetState(elem, 10);
  } else {
    elem->timer++;
  }
}

// goal で待つ, 群れが終われば止まり, ブラックホールが出ればそちらへ寄る
void RingoBat_UpdateArrived(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  if (elem->stateEntered) {
    HitboxData* hurtbox;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    hurtbox->flags |= HBFLAG_HIDDEN;
  }
  RingoBat_SetAnim(p, elem, 0);
  if (p->finished) {
    RingoBat_SetState(elem, 11);
  } else if (p->blackHoleActive) {
    RingoBat_SetState(elem, 5);
  } else {
    elem->timer++;
  }
}

// 食らい判定を外して止まっている
void RingoBat_UpdateIdle(RingoBatSwarm* p, RingoBat* elem, s32 idx) {
  if (elem->stateEntered) {
    HitboxData* hurtbox;

    elem->stateEntered = FALSE;
    hurtbox = &elem->hurtbox;
    hurtbox->flags |= HBFLAG_HIDDEN;
  }
  RingoBat_SetAnim(p, elem, 0);
  elem->timer++;
}

void (*const sRingoBatStates[12])(RingoBatSwarm*, RingoBat*, s32) = {
    RingoBat_UpdateSpread,
    RingoBat_UpdateApproach,
    RingoBat_UpdateAim,
    RingoBat_UpdateWander,
    RingoBat_UpdateLunge,
    RingoBat_UpdateToBlackHole,
    RingoBat_UpdateHurtToBlackHole,
    RingoBat_UpdateInBlackHole,
    RingoBat_UpdateHurt,
    RingoBat_UpdateReturn,
    RingoBat_UpdateArrived,
    RingoBat_UpdateIdle,
};  // 0x085ABA2C

// 群れ全体を1フレーム進める, パレットの寄せと各要素の状態関数, 終了の判定をする
s32 RingoBatSwarm_Update(RingoBatSwarm* p) {
  RingoBat* elem;
  s32 i;
  s32 inBlackHole;
  s32 arrived;

  if (!p->active) {
    return 0;
  }
  p->blackHoleActive = BlackHole_IsActive();
  BlackHole_GetCenter(&p->blackHolePos);
  if (p->timer >= 600) {
    if (!p->returning) {
      p->returning = TRUE;
      PlaySound_082406e0(CRY_BAT_234);
    }
    p->fadeMode = 2;
  }
  if (p->fadeMode == 0) {
    if (++p->fadeLevel > 62) {
      p->fadeLevel = 63;
      p->fadeMode = -1;
    }
  } else if (p->fadeMode == 1) {
    if (--p->fadeLevel <= 0) {
      p->fadeLevel = 0;
      p->fadeMode = -1;
    }
  } else if (p->fadeMode == 2) {
    if (++p->fadeLevel > 31) {
      p->fadeLevel = 32;
      p->fadeMode = -1;
    }
  }
  if (p->fadeMode >= 0) {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[613 * 16];

    BlendPltt(p->pltt, src1, src2, p->fadeLevel, 6);
  }
  if (p->finished) {
    RingoBatSwarm_Finish(p);
    return 0;
  }
  inBlackHole = 0;
  arrived = 0;
  elem = &p->elems[0];
  for (i = 0; i < 16; i++, elem++) {
    sRingoBatStates[elem->state](p, elem, i);
    RingoBat_UpdateSprite(elem);
    if (elem->state == 7) {
      inBlackHole++;
    }
    if (elem->state == 10) {
      arrived++;
    }
  }
  if ((inBlackHole == 16 || arrived == 16 || p->timer >= 1200) && !p->finished) {
    p->finished = TRUE;
  }
  p->timer++;
  return 0;
}

s32 RingoBatSwarm_Destroy(RingoBatSwarm* p) {
  RingoBat* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    RingoBat_Destroy(p, elem, i);
  }
  return 0;
}

// 残差は1つ目のループの i と elem の r4/r5 の入れ替えだけ (60/60命令)
// Tier C は試済 (宣言順, 2つ目のループを別カウンタ / ポインタ送り), 未: 兄弟 CutsceneBatSwarm_Init と同じく Init の後ろに何か呼ぶ形か
NON_MATCH s32 RingoBatSwarm_Init(RingoBatSwarm* p, u32 targetCount) {
#ifdef NONMATCHING_C
  RingoBat* elem;
  s32 i;

  p->power = 10;
  p->defense = 100;
  p->finished = FALSE;
  p->active = FALSE;
  p->targetCount = targetCount;
  p->anim = GetFile(DIR_ANIMATION, ANIM_BAT);
  {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[613 * 16];

    BlendPltt(p->pltt, src1, src2, 64, 6);
  }
  elem = &p->elems[0];
  for (i = 0; i < 16; i++, elem++) {
    RingoBat_Init(p, elem, i);
  }
  for (i = 0; i < p->targetCount; i++) {
    p->targets[i] = &gPlayerPtr[i]->mover.pos;
  }
  return 0;
#else
  INCFUNC("asm/func/RingoBatSwarm_Init.inc");
#endif
}

RingoBatSwarm* RingoBatSwarm_Create(u32 targetCount) {
  RingoBatSwarm* p = CreateEntity(ENTITY_UNK_8, sizeof(RingoBatSwarm));

  if (p != NULL) {
    SetEntityRoutine(p, RingoBatSwarm_Update, RingoBatSwarm_Destroy);
    if (RingoBatSwarm_Init(p, targetCount) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// from の周りにコウモリを散らして群れを動かし始める, to が最後に集まる goal になる
// 残差は1つ目の乱数の表のアドレスをループの外に出してレジスタに持つ点と, それにつられたレジスタ番号の違い (238/238命令), 原典は表と 0x3FF をループ内でプールから読み直す
// 試済: Random / RandomNext の組み合わせ, angle の足す順, angle を2文に分ける, 狙いを決める処理を i を受ける inline に
NON_MATCH s32 RingoBatSwarm_Start(RingoBatSwarm* p, Vec3* from, Vec3* to, s32 speed, s32 param_5) {
#ifdef NONMATCHING_C
  RingoBat* elem;
  s32 i;

  p->blackHoleActive = FALSE;
  p->finished = FALSE;
  p->returning = FALSE;
  p->timer = 0;
  p->fadeMode = 1;
  p->fadeLevel = 63;
  {
    rgb555* src1 = &gObjPlttData[611 * 16];
    rgb555* src2 = &gObjPlttData[613 * 16];

    BlendPltt(p->pltt, src1, src2, 63, 6);
  }
  p->goal = *to;
  elem = &p->elems[0];
  for (i = 0; i < 16; i++, elem++) {
    AuxSprite* sprite;
    Vec3* pos;
    HitboxData* hurtbox;
    s32 r;

    RingoBat_SetState(elem, 0);
    elem->angle = i * 32 + (RandomNext() & 31);
    elem->speed = speed;
    elem->unk_12 = param_5;
    sprite = &elem->sprite;
    if (p->targetCount == 2) {
      if (i < 8) {
        RingoBat_SetTarget(elem, 1);
      } else {
        RingoBat_SetTarget(elem, 0);
      }
    } else if (p->targetCount == 0) {
      RingoBat_SetTarget(elem, 0);
    } else {
      RingoBat_SetTarget(elem, -1);
    }
    elem->retargetTimer = 0;
    r = (Random() & 31) + 16;
    elem->pos.x = from->x + POLAR_X(r, elem->angle);
    elem->pos.y = from->y;
    elem->pos.z = from->z + POLAR_Z(r, elem->angle);
    elem->baseY = elem->pos.y;
    elem->turnTimer = (Random() & 7) + 7;
    pos = &elem->pos;
    sprite->pos = elem->pos;
    AuxSprite_Show(&elem->sprite);
    RingoBat_SetAnim(p, elem, 0);
    RingoBat_SetPltt(p, &elem->gfx, 611);
    ParticleShadow_Show(&elem->shadow);
    Hitbox_SetPos(&elem->hitbox, pos, 0);
    hurtbox = &elem->hurtbox;
    Hitbox_SetPos(hurtbox, pos, 0);
    hurtbox->flags |= HBFLAG_HIDDEN;
  }
  p->active = TRUE;
  return 0;
#else
  INCFUNC("asm/func/RingoBatSwarm_Start.inc");
#endif
}

// timer を 600 に進めて goal へ戻らせる
void RingoBatSwarm_StartReturn(RingoBatSwarm* p) { p->timer = 600; }
