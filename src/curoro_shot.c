#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vec3.h"

// BOSS_DAINN の 技"クロロホルルン+"(追尾性のエネルギー弾)
typedef struct {
  bool8 stateBegun;      // 0x000, state を切り替えると 1, 各 state の最初のフレームで入場処理をして 0 に戻す
  u8 state;              // 0x001, sCuroroShotStates の添字
  u8 unk_2[2];           // 0x002, まだ未解析
  bool8 animDone;        // 0x004, 毎フレーム CuroroShot_UpdateSprites が sprites[0] のアニメを進めた結果を入れる, 一巡したら 1
  u8 bobPhase;           // 0x005, sprites[0] を上下に揺らす gSineTable の添字, 毎フレーム +4
  u16 timer;             // 0x006, state ごとの経過フレーム数, state を切り替えると 0
  u16 lifeTimer;         // 0x008, state 2 で毎フレーム +1, 599 を超えると state 3 で消える
  u8 angle;              // 0x00A, 進む向き, 被弾したとき攻撃元への角度を入れる
  u8 targetAngle;        // 0x00B, target への向き, CuroroShot_TurnToTarget が angle をここへ 2 ずつ寄せる
  u8 trailIdx;           // 0x00C, trail に次に書く添字 (0..3)
  u8 unk_d[3];           // 0x00D, まだ未解析
  u16 speed;             // 0x010, 1フレームに進む距離, 生成時の第5引数, state 2 に入ると 10
  s16 hp;                // 0x012, 被弾で相手の damage の分だけ減り、0 で state 6 へ移る
  Vec3 pos;              // 0x014, 両方の Hitbox_SetPos に渡す
  Vec3 trail[4];         // 0x01C, 4フレームごとに pos を記録する輪, sprites[1..3] が新しい順に古い位置をなぞる
  u8 unk_3c[8];          // 0x03C, まだ未解析, 読み書きする関数が見つかっていない
  Vec3* target;          // 0x044, 向きを合わせる相手の座標
  Hitbox hitbox;         // 0x048
  Hitbox hurtbox;        // 0x098
  AuxAnimState anim;     // 0x0E8, sprites[0] の再生状態
  AuxSprite sprites[4];  // 0x0F8, [0] は priority 1 でアニメ付き, [1..3] は priority 2, 0 と 1..3 を別のメンバにした方がいいかも？
  AuxSpriteGfx gfx;      // 0x1A8, SPR_CURORO_SHOTS, パレット 200
} CuroroShot;
static_assert(sizeof(CuroroShot) == 452);

typedef struct CuroroShotManager {
  Entity e;               // 0x000, ENTITY_UNK_8
  u32 activeMask;         // 0x018, 立っているビットの枠だけ Update が回す
  u16 attackID;           // 0x01C, Init の第2引数, 各枠の Hitbox_SetAttack に渡す
  u16 power;              // 0x01E, Init の第3引数, 各枠の Hitbox_SetPowerAndAttributes に渡す
  AuxAnimFile* animFile;  // 0x020, ANIM_CURORO_SHOTS
  CuroroShot elems[8];    // 0x024
} CuroroShotManager;
static_assert(sizeof(CuroroShotManager) == 3652);

// 状態を入れ替えて経過フレームを0に戻す
static inline void CuroroShot_SetState(CuroroShot* p, u8 state) {
  p->state = state;
  p->stateBegun = TRUE;
  p->timer = 0;
}

// 空いている枠を返し, 添字を *outIdx に入れる, 無ければ NULL
CuroroShot* CuroroShotManager_AllocShot(CuroroShotManager* p, u32* outIdx) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!(p->activeMask & 1 << i)) {
      *outIdx = i;
      return &p->elems[i];
    }
  }
  return NULL;
}

// 被弾したら攻撃の向きへはじかれ, ダメージの数字を出して hp を減らし, 尽きたら撃ち落とされる
void CuroroShot_OnHurt(Hitbox* a, Hitbox* b, CuroroShot* owner) {
  Vec3 ofs;

  if (TEST_FLAGS(a->flags, HBF_ANGLE)) {
    owner->angle = a->angle;
  } else {
    owner->angle = ArcTan2_8(b->center.x - a->center.x, b->center.z - a->center.z);
  }
  Hitbox_ApplyDamage(a, b);
  VEC3_SET(ofs, 16, 0, 16);
  CreateDamageNumber(b, b->damage, 0, &owner->pos, &ofs, 1);
  a->damage += 2;
  owner->hp -= b->damage;
  if (owner->hp <= 0) {
    owner->hp = 0;
    CuroroShot_SetState(owner, 6);
    PlaySound_082406e0(SONG_825);
  } else {
    CuroroShot_SetState(owner, 5);
    PlaySound_082406e0(SONG_820);
  }
}

// 当たったら状態4 (被弾) へ入れ直す
void CuroroShot_OnHit(Hitbox* a, Hitbox* b, CuroroShot* owner) { CuroroShot_SetState(owner, 4); }

// 枠を初期化する, スプライト4枚と食らい判定 (闇属性のファントム, ソルが弱点) と攻撃判定を作る, 原典は return を書き忘れている
// 残差は 165 対 165 命令で 0 の使い回しだけ, 原典は state と angle / targetAngle に同じ 0 を使い timer に別の 0 を作るが, こちらは state と timer で共有する
// SetState を使わず直接書く形, 連鎖代入, 向きを揃える inline, SetState の state を s32 にする形は試済
NON_MATCH s32 CuroroShot_Init(CuroroShotManager* p, CuroroShot* elem, s32 index) {
#ifdef NONMATCHING_C
  Vec3 size;
  Vec3 offset;
  AuxSprite* spr;
  Hitbox* hitbox;
  s32 i;

  CuroroShot_SetState(elem, 0);
  elem->angle = 0;
  elem->targetAngle = 0;
  Video_GetAuxSprite(&elem->gfx, SPR_CURORO_SHOTS);
  Video_SetAuxSpritePltt(&elem->gfx, 200);
  spr = elem->sprites;
  for (i = 0; i < 4; i++, spr++) {
    AuxSprite_Add(spr, &elem->gfx, 1);
    if (i == 0) {
      AuxAnim_SetAnim(&elem->anim, p->animFile, 1, 0, 0);
      spr->priority = 1;
    } else {
      spr->poseIdx = i + 3;
      spr->priority = 2;
    }
    Vec3_Clear(&spr->pos);
  }

  hitbox = &elem->hurtbox;
  VEC3_SET(size, 32, 100, 32);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBF_HURTBOX | HBF_ACTOR | HBF_HIDDEN | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(hitbox, &elem->pos, 0);
  Hitbox_SetHandler(hitbox, CuroroShot_OnHurt, elem);
  Hitbox_SetPowerAndAttributes(hitbox, p->power, HBATTR_PHANTOM | HBATTR_DARK, HBATTR_SOL);
  Hitbox_Register(hitbox);

  hitbox = &elem->hitbox;
  VEC3_SET(size, 32, 100, 32);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(hitbox, &elem->pos, 0);
  Hitbox_SetHandler(hitbox, CuroroShot_OnHit, elem);
  Hitbox_SetAttack(hitbox, p->attackID, 30, 0, 2, 30);
#else
  INCFUNC("asm/func/CuroroShot_Init.inc");
#endif
}

// 原典は return を書き忘れている
s32 CuroroShot_Destroy(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  AuxSprite* spr;
  s32 i;

  Hitbox_Unregister(&elem->hurtbox);

  spr = &elem->sprites[0];
  for (i = 0; i < 4; i++, spr++) {
    AuxSprite_Remove(spr);
  }
}

// 枠を片付けて使用中ビットを落とす, 原典は return を書き忘れている
s32 CuroroShot_Free(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  AuxSprite* spr = &elem->sprites[0];
  Hitbox* hitbox;
  s32 i;

  for (i = 0; i < 4; i++, spr++) {
    spr->flags |= SPRFLAG_HIDDEN;
  }
  hitbox = &elem->hurtbox;
  hitbox->flags |= HBF_HIDDEN;
  p->activeMask &= ~(1 << index);
}

// 本体のスプライトを pos に置いてアニメを進め上下に揺らし, 尾の3枚を trail の新しい順に置く, 4 フレームごとに本体の位置を trail に記録する
void CuroroShot_UpdateSprites(CuroroShot* elem) {
  AuxSprite* spr = elem->sprites;
  s32 idx;
  s32 i;

  elem->sprites[0].pos = elem->pos;
  elem->animDone = AuxSprite_AdvanceAnim(spr, &elem->anim);
  spr->pos.y += POLAR_Z(64, elem->bobPhase);
  spr++;
  idx = elem->trailIdx - 1;
  if (idx < 0) {
    idx = 3;
  }
  for (i = 0; i < 3; i++, spr++) {
    spr->pos = *(elem->trail + idx);
    idx--;
    if (idx < 0) {
      idx = 3;
    }
  }
  elem->bobPhase += 4;
  if ((elem->timer & 3) == 0) {
    *(elem->trail + elem->trailIdx) = elem->sprites[0].pos;
    elem->trailIdx++;
    if (elem->trailIdx > 3) {
      elem->trailIdx = 0;
    }
  }
}

// sprites[1..3] を見せる
void CuroroShot_ShowTrail(CuroroShot* elem) {
  AuxSprite* spr = &elem->sprites[1];
  s32 i;

  for (i = 0; i < 3; i++, spr++) {
    spr->flags &= ~SPRFLAG_HIDDEN;
  }
}

// sprites[1..3] を隠す
void CuroroShot_HideTrail(CuroroShot* elem) {
  AuxSprite* spr = &elem->sprites[1];
  s32 i;

  for (i = 0; i < 3; i++, spr++) {
    spr->flags |= SPRFLAG_HIDDEN;
  }
}

// target の方向へ1フレーム2刻みで向きを寄せる
void CuroroShot_TurnToTarget(CuroroShot* elem) {
  Vec3* target = elem->target;
  s32 want = ArcTan2_8(target->x - elem->pos.x, target->z - elem->pos.z);
  s8 d;

  elem->targetAngle = want;
  d = want - elem->angle;
  if (d < -2) {
    d = -2;
  } else if (d > 2) {
    d = 2;
  }
  elem->angle += d;
}

// state 0, 出現のアニメ 1 を流し, 一巡したら state 1 へ移ってアニメ 0 にする
void CuroroShot_StateSpawn(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    AuxAnim_SetAnim(&elem->anim, p->animFile, 1, 0, 0);
  }
  if (elem->animDone) {
    CuroroShot_SetState(elem, 1);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 0, 0, 0);
  }
  elem->timer++;
}

// state 1, 食らい判定と尾を出し, 32 フレーム経ったら飛び始める
void CuroroShot_StateAppear(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  if (elem->stateBegun) {
    Hitbox* hurtbox;

    elem->stateBegun = FALSE;
    hurtbox = &elem->hurtbox;
    Hitbox_ClearFlags(hurtbox, HBF_HIDDEN);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 0, 0, 0);
    CuroroShot_ShowTrail(elem);
    Hitbox_SetPos(hurtbox, &elem->pos, 0);
  }
  if (elem->timer > 31) {
    CuroroShot_SetState(elem, 2);
  }
  elem->timer++;
}

// state 2, target へ旋回しながら speed で進む, 最初は target への向きから乱数でずらしたほぼ逆向きに飛び出し, 600 フレームで消える
void CuroroShot_StateFly(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  Vec3 d;

  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    elem->speed = 10;
    Hitbox_ClearFlags(&elem->hurtbox, HBF_HIDDEN);
    elem->angle = ArcTan2_8(elem->target->x - elem->pos.x, elem->target->z - elem->pos.z) + (s8)((Random() & 63) - 128) - 32;
  }
  CuroroShot_TurnToTarget(elem);
  Vec3_SetPolar(&d, elem->angle, elem->speed);
  Vec3_Add(&elem->pos, &d);
  Hitbox_SetPos(&elem->hitbox, &elem->pos, 0);
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  Hitbox_Register(&elem->hitbox);
  elem->lifeTimer++;
  if (elem->lifeTimer > 599) {
    CuroroShot_SetState(elem, 3);
  } else {
    elem->timer++;
  }
}

// state 3, 食らい判定と尾を隠して消えるアニメを流し, 終わったら枠を空ける
void CuroroShot_StateVanish(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    Hitbox_Hide(&elem->hurtbox);
    CuroroShot_HideTrail(elem);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 4, 0, 0);
  }
  if (elem->animDone) {
    CuroroShot_Free(p, elem, index);
  } else {
    elem->timer++;
  }
}

// state 4, 何かに当たったら進む向きの前後3方向に煙を出して音を鳴らし, 進みながら消えるアニメを流して枠を空ける
void CuroroShot_StateExplode(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  Vec3 size;
  Vec3 d;

  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    Hitbox_Hide(&elem->hurtbox);
    CuroroShot_HideTrail(elem);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 4, 0, 0);
    VEC3_SET(size, 64, 64, 64);
    EmitSmoke(&elem->pos, (RandomNext() & 1) + 1, &size, elem->angle - (RandomNext() & 15) + 3, (RandomNext() & 7) + elem->speed, 1, 2, 1);
    EmitSmoke(&elem->pos, (RandomNext() & 1) + 1, &size, elem->angle, (RandomNext() & 7) + elem->speed, 1, 2, 1);
    EmitSmoke(&elem->pos, (RandomNext() & 1) + 1, &size, (RandomNext() & 15) + elem->angle + 3, (RandomNext() & 7) + elem->speed, 1, 2, 1);
    PlaySound_082406e0(SONG_825);
  }
  Vec3_SetPolar(&d, elem->angle, elem->speed);
  Vec3_Add(&elem->pos, &d);
  if (elem->animDone) {
    CuroroShot_Free(p, elem, index);
  } else {
    elem->timer++;
  }
}

// state 5, 白く光って angle の向きへ減速しながら押し戻され, 20 フレームで飛行に戻る
void CuroroShot_StateKnockback(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  Vec3 d;

  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    Hitbox_Hide(&elem->hurtbox);
    Video_SetAuxSpritePltt(&elem->gfx, OBP_WHITE_306);
  }
  Vec3_SetPolar(&d, elem->angle, (20 - elem->timer) * 2);
  Vec3_Add(&elem->pos, &d);
  if (elem->timer > 19) {
    CuroroShot_SetState(elem, 2);
  } else {
    if (elem->timer == 10) {
      Video_SetAuxSpritePltt(&elem->gfx, 200);
    }
    elem->timer++;
  }
}

// state 6, 撃ち落とされて angle の向きへ流れながら消えるアニメを流し, 4 フレームごとに煙と音を出す
void CuroroShot_StateDestroyed(CuroroShotManager* p, CuroroShot* elem, s32 index) {
  Vec3 d;
  Vec3 size;

  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    Hitbox_Hide(&elem->hurtbox);
    CuroroShot_HideTrail(elem);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 4, 0, 0);
  }
  Vec3_SetPolar(&d, elem->angle, 20);
  Vec3_Add(&elem->pos, &d);
  if ((elem->timer & 3) == 0) {
    VEC3_SET(size, 64, 64, 64);
    EmitSmoke(&elem->pos, (RandomNext() & 1) + 1, &size, (u8)RandomNext(), 0, (RandomNext() & 7) + 16, 2, 1);
    PlaySound_082406e0(SONG_825);
  }
  if (elem->animDone) {
    CuroroShot_Free(p, elem, index);
  } else {
    elem->timer++;
  }
}

s32 CuroroShotManager_Update(CuroroShotManager* p) {
  static void (*const sCuroroShotStates[7])(CuroroShotManager*, CuroroShot*, s32) = {
      CuroroShot_StateSpawn,
      CuroroShot_StateAppear,
      CuroroShot_StateFly,
      CuroroShot_StateVanish,
      CuroroShot_StateExplode,
      CuroroShot_StateKnockback,
      CuroroShot_StateDestroyed,
  };  // 0x085ABA04

  CuroroShot* e = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, e++) {
    if (p->activeMask & 1 << i) {
      sCuroroShotStates[e->state](p, e, i);
      CuroroShot_UpdateSprites(e);
    }
  }
  return 0;
}

s32 CuroroShotManager_Destroy(CuroroShotManager* p) {
  CuroroShot* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    CuroroShot_Destroy(p, elem, i);
  }
  return 0;
}

s32 CuroroShotManager_Init(CuroroShotManager* p, u32 attackID, u32 power) {
  CuroroShot* elem;
  s32 i;

  p->attackID = attackID;
  p->power = power;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_CURORO_SHOTS);
  elem = &p->elems[0];
  for (i = 0; i < 8; i++, elem++) {
    CuroroShot_Init(p, elem, i);
  }
  return 0;
}

CuroroShotManager* CuroroShotManager_Create(u32 param_1, u32 param_2) {
  CuroroShotManager* p = CreateEntity(ENTITY_UNK_8, sizeof(CuroroShotManager));

  if (p != NULL) {
    SetEntityRoutine(p, CuroroShotManager_Update, CuroroShotManager_Destroy);
    if (CuroroShotManager_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// pos から angle の向きへ, target を追う弾を1発出す, 空きが無ければ -1
// 残差は 117 対 115 命令, 原典は trail[i] のアドレスを毎周 i * 8 から作るが, こちらは歩きポインタにして1レジスタ増え, &hitbox がスタックに追い出される
// sprites を添字で参照, trail のポインタ変数, hurtbox のローカル化は試済
NON_MATCH s32 CuroroShotManager_Spawn(CuroroShotManager* p, Vec3* pos, Vec3* target, s32 angle, s32 speed, u32 hp) {
#ifdef NONMATCHING_C
  CuroroShot* elem;
  AuxSprite* spr;
  u32 idx;
  s32 i;

  elem = CuroroShotManager_AllocShot(p, &idx);
  if (elem == NULL) {
    return -1;
  }
  CuroroShot_SetState(elem, 0);
  elem->angle = angle;
  elem->targetAngle = angle;
  elem->speed = speed;
  elem->hp = hp;
  elem->lifeTimer = 0;
  elem->target = target;
  elem->trailIdx = 0;
  elem->pos = *pos;
  spr = elem->sprites;
  for (i = 0; i < 4; i++, spr++) {
    elem->trail[i] = elem->pos;
    spr->pos = elem->pos;
    if (i == 0) {
      AuxSprite_Show(spr);
      AuxAnim_SetAnim(&elem->anim, p->animFile, 1, 0, 0);
    } else {
      AuxSprite_Hide(spr);
    }
  }
  Video_SetAuxSpritePltt(&elem->gfx, 200);
  Hitbox_SetPos(&elem->hitbox, &elem->pos, 0);
  Hitbox_SetPos(&elem->hurtbox, &elem->pos, 0);
  Hitbox_Hide(&elem->hurtbox);
  p->activeMask |= 1 << idx;
  return 0;
#else
  INCFUNC("asm/func/CuroroShotManager_Spawn.inc");
#endif
}

// 出始めから飛行中までの弾を全部消える状態にする, 原典は return を書き忘れている
s32 CuroroShotManager_VanishAll(CuroroShotManager* p) {
  CuroroShot* elem = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if ((p->activeMask & 1 << i) && elem->state <= 2) {
      CuroroShot_SetState(elem, 3);
    }
  }
}
