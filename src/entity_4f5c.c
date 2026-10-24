#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "trig.h"
#include "vm.h"

// 粒子3枚を1組にした要素, Entity4F5C_ElemFall がプレイヤーの高さまで落とし、Entity4F5C_ElemScatter が円状に散らす
typedef struct {
  u8 state;           // 0x00, PTR_ARRAY_085aa974 の添字, 0 は終了済み
  u8 ptclIdx;         // 0x01, ptcls の添字, 1 と 2 を巡回する
  u8 unk_02;          // 0x02, 0x18 から毎フレーム減るカウンタ, 0x17 と 0x14 で分岐する
  u8 speed;           // 0x03, gSineTable との積が1フレームの移動量になる
  u8 angle;           // 0x04, gSineTable の添字 (散る向き)
  u8 unk_05;          // 0x05, 着地と判定する高さのずれ, Entity4F5C_Init が (rand & 0x1F) - 0x24 を入れる
  u16 timer;          // 0x06, 毎フレーム +1
  Vec3 pos;           // 0x08, ptcls[].pos の基準位置
  u8 animIdx[3];      // 0x10, 粒子ごとのアニメ番号 (0 か 1)
  u8 animTimer[3];    // 0x13, u16_ARRAY_085aa970[animIdx] に達したら animIdx を進める
  u8 unk_16[2];       // 0x16, まだ未解析, padding?
  Particle ptcls[3];  // 0x18
} Entity4F5CElem;
static_assert(sizeof(Entity4F5CElem) == 144);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u16 unk_18;               // 0x018, Entity4F5C_Init が 0 を書く, 読み手は未発見
  u16 scriptID;             // 0x01A, '.e' の値, elems が全部終わったら VM_ExecByID に渡す
  WorldPos playerPos;       // 0x01C, player->mover.pos の写し
  ParticleGroup* group1;    // 0x024, PTCL_GROUP_1
  ParticleGroup* group2;    // 0x028, PTCL_GROUP_2
  Entity4F5CElem elems[3];  // 0x02C
  Player* player;           // 0x1DC, gPlayerPtr[0]
} Entity4F5C;
static_assert(sizeof(Entity4F5C) == 480);

const u16 u16_ARRAY_085aa970[2] = {3, 3};  // 0x085AA970

void nop_0801a170(Entity4F5C*, Entity4F5CElem*);
void Entity4F5C_ElemFall(Entity4F5C*, Entity4F5CElem*);
void Entity4F5C_ElemScatter(Entity4F5C*, Entity4F5CElem*);

void (*const PTR_ARRAY_085aa974[3])(Entity4F5C*, Entity4F5CElem*) = {
    nop_0801a170,
    Entity4F5C_ElemFall,
    Entity4F5C_ElemScatter,
};  // 0x085AA974

const u16 u16_ARRAY_085aa980[4] = {0x0, 0x80, 0x258};  // 0x085AA980

void nop_0801a170(Entity4F5C* p, Entity4F5CElem* elem) {}

// プレイヤーの高さまで落としながら粒子を巡回させ, 着地したら state 2 へ移す
// 残差6命令 (282/276). 原典は p を高位レジスタ (r8) へ追い出して使うたび低位へ mov し直すが, agbcc は p を r7 に収めてしまう
NON_MATCH void Entity4F5C_ElemFall(Entity4F5C* p, Entity4F5CElem* elem) {
#ifdef NONMATCHING_C
  s32 dy = elem->pos.y - (p->playerPos.y + elem->unk_05);

  if (dy > 0x4B0) {
    Particle* ptcl = elem->ptcls;
    s32 j;

    elem->pos.y -= 0x18;
    for (j = 2; j >= 0; j--, ptcl++) {
      ptcl->flags |= SPRFLAG_HIDDEN;
    }
  } else if (dy > 0x18) {
    elem->pos.y -= 0x18;
    elem->ptcls[0].flags &= ~SPRFLAG_HIDDEN;

    if (elem->unk_02 == 0) {
      elem->unk_02 = 0x18;
      elem->ptcls[elem->ptclIdx].flags |= SPRFLAG_HIDDEN;
      elem->ptclIdx++;
      if (elem->ptclIdx > 2) {
        elem->ptclIdx = 1;
      }
      Particle_SetOffset(&elem->ptcls[elem->ptclIdx], (Random() & 1) - 4, (Random() & 1) - 4);
      Particle_SetFrame(&elem->ptcls[elem->ptclIdx], p->group2, 2);
      elem->ptcls[elem->ptclIdx].plttSlot = p->group2->plttID + 1;
      elem->ptcls[elem->ptclIdx].flags &= ~SPRFLAG_HIDDEN;
      elem->ptcls[elem->ptclIdx].flags |= SPRFLAG_BLINK_ODD;
      elem->ptcls[elem->ptclIdx].pos = elem->pos;
    } else {
      elem->unk_02--;
      if (elem->unk_02 == 0x16) {
        Particle_SetFrame(&elem->ptcls[elem->ptclIdx], p->group2, 2);
        elem->ptcls[elem->ptclIdx].plttSlot = p->group2->plttID + 1;
      }
      if (elem->unk_02 == 0x14) {
        elem->ptcls[elem->ptclIdx].flags |= SPRFLAG_HIDDEN;
      }
    }
  } else {
    Particle* ptcl = elem->ptcls;
    s32 j;

    elem->state = 2;
    elem->timer = 0;
    elem->speed = (Random() & 1) + 4;

    for (j = 0; j < 3; j++, ptcl++) {
      ptcl->flags |= SPRFLAG_BLINK_ODD;
      ptcl->flags &= ~SPRFLAG_HIDDEN;
      Particle_SetFrame(ptcl, p->group2, 2);
      ptcl->plttSlot = p->group2->plttID + 1;
      Particle_SetOffset(ptcl, -4, -4);
      ptcl->pos = elem->pos;
      elem->animIdx[j] = 1;
      elem->animTimer[j] = Random() & 3;
    }

    FUN_0807a8e0(gPlayerPtr[0]);
  }

  elem->ptcls[0].pos = elem->pos;
#else
  INCFUNC("asm/func/Entity4F5C_ElemFall.inc");
#endif
}

// 粒子3枚を円状に散らしながらアニメを進め, 0x1F フレーム経ったら隠して終わる
// 残差17命令 (153/170) でこちらが短い. 原典は angle を高位レジスタに追い出して gSineTable をアクセスごとにプールから読み直すが, agbcc は gSineTable を1本に巻き上げて angle を低位に収める (agbcc-levers.md の『キャッシュされたグローバルポインタを原典は毎回読み直す』と同じ壁)
// y は SIN(timer * 4, 0x40) で一致, x/z は FixToInt でなく素の >> 12
NON_MATCH void Entity4F5C_ElemScatter(Entity4F5C* p, Entity4F5CElem* elem) {
#ifdef NONMATCHING_C
  Particle* ptcl = elem->ptcls;
  u8 angle = elem->angle;
  s32 i;

  for (i = 0; i < 3; i++, ptcl++) {
    ptcl->pos.x += (gSineTable[(angle + 0x40) & 0xFF] * elem->speed) >> 12;
    if (elem->timer <= 0x18) {
      ptcl->pos.y = p->playerPos.y + SIN(elem->timer * 4, 0x40) + elem->unk_05;
    } else {
      ptcl->pos.y -= 10;
    }
    ptcl->pos.z += (gSineTable[angle] * elem->speed) >> 12;

    elem->animTimer[i]++;
    if (elem->animTimer[i] >= u16_ARRAY_085aa970[elem->animIdx[i]]) {
      elem->animTimer[i] = 0;
      elem->animIdx[i]++;
      if (elem->animIdx[i] > 1) {
        elem->animIdx[i] = 0;
      }
      Particle_SetFrame(ptcl, p->group2, elem->animIdx[i] + 2);
      ptcl->plttSlot = p->group2->plttID + 1;
    }

    angle = (s8)angle + (Random() & 7) + 0x4C;
  }

  if (elem->timer > 0x1F) {
    Particle* q = elem->ptcls;
    s32 j;

    for (j = 2; j >= 0; j--, q++) {
      q->flags |= SPRFLAG_HIDDEN;
    }
    elem->state = 0;
  }
#else
  INCFUNC("asm/func/Entity4F5C_ElemScatter.inc");
#endif
}

// 各要素を state ごとの関数で進め, 全部終わったらスクリプトを呼んで自分を消す
// 命令数・内容とも一致 (54/54) するが, 原典は i=2 の初期化を PTR_ARRAY_085aa974 のプール読みより後に置くのに対し agbcc は先に置く
// done / elem の初期化を playerPos の複写より後ろの代入文に分けると, そこまでは原典と揃う
NON_MATCH s32 Entity4F5C_Update(Entity4F5C* p) {
#ifdef NONMATCHING_C
  Entity4F5CElem* elem;
  s32 done;
  s32 i;

  p->playerPos = p->player->mover.pos;
  done = 0;
  elem = p->elems;

  for (i = 2; i >= 0; i--, elem++) {
    if (elem->state == 0) {
      done++;
    } else {
      PTR_ARRAY_085aa974[elem->state](p, elem);
      elem->timer++;
    }
  }

  if (done == 3) {
    if (p->scriptID != 0) {
      VM_ExecByID(p->scriptID, NULL);
      p->scriptID = 0;
    }
    KillEntity((Entity*)p);
  }

  return 0;
#else
  INCFUNC("asm/func/Entity4F5C_Update.inc");
#endif
}

// 残差0命令 (23/23), レジスタ名だけ違う: 原典は e を p のレジスタに重ねるが, こちらは p が別レジスタに残る
NON_MATCH s32 Entity4F5C_Destroy(Entity4F5C* p) {
#ifdef NONMATCHING_C
  Entity4F5CElem* e = p->elems;
  s32 i;
  s32 j;

  for (i = 0; i < 3; i++, e++) {
    for (j = 0; j < 3; j++) {
      Particle_Remove(&e->ptcls[j]);
    }
  }
#else
  INCFUNC("asm/func/Entity4F5C_Destroy.inc");
#endif
}

// プレイヤーの頭上に粒子3枚×3組を円状に仕込む
// 残差4命令 (239/243) でこちらが短い. elem と ptcl のレジスタが入れ替わり, 原典は i=0 に既存の 0 レジスタを使い回すところを agbcc は作り直す
// gPlayerPtr[0] をローカルに取ると &p->player の作り位置が原典と揃う (それ以前は 243 対 239 で順序もずれていた)
NON_MATCH s32 Entity4F5C_Init(Entity4F5C* p) {
#ifdef NONMATCHING_C
  WorldPos basePos;
  Entity4F5CElem* elem;
  Player* player;
  s32 i;

  player = gPlayerPtr[0];
  p->player = player;
  if (player == NULL) {
    return -1;
  }

  p->scriptID = VM_GetNamedArgValue('e', 0);
  basePos = p->player->mover.pos;
  basePos.y += 0x4B0;
  p->playerPos = p->player->mover.pos;
  p->unk_18 = 0;
  p->group1 = GetParticleGroup(PTCL_GROUP_1);
  p->group2 = GetParticleGroup(PTCL_GROUP_2);

  elem = p->elems;
  for (i = 0; i < 3; i++, elem++) {
    Particle* ptcl = elem->ptcls;
    s32 radius;
    s32 j;

    elem->state = 1;
    elem->ptclIdx = 1;
    elem->unk_02 = Random() & 0xF;
    elem->speed = 0;
    elem->angle = Div(i << 8, 3) + (Random() & 0x3F);
    elem->timer = 0;
    radius = Random() & 0x3F;
    elem->pos.x = COS(elem->angle, radius);
    elem->pos.y = 0;
    elem->pos.z = SIN(elem->angle, radius);
    elem->unk_05 = (Random() & 0x1F) - 0x24;
    elem->pos.x += basePos.x;
    elem->pos.y += basePos.y + u16_ARRAY_085aa980[i];
    elem->pos.z += basePos.z;

    for (j = 0; j < 3; j++, ptcl++) {
      Particle_Add(ptcl, p->group1, 1);
      Particle_SetOffset(ptcl, -4, -4);
      if (j == 0) {
        Particle_SetFrame(ptcl, p->group1, 0x1C);
        ptcl->plttSlot = p->group1->plttID;
      } else {
        Particle_SetFrame(ptcl, p->group2, 2);
        ptcl->plttSlot = p->group2->plttID + 1;
      }
      ptcl->pos.x += elem->pos.x;
      ptcl->pos.y += elem->pos.y;
      ptcl->pos.z += elem->pos.z;
    }
  }

  PlaySound_082406e0(SONG_636);
  return 0;
#else
  INCFUNC("asm/func/Entity4F5C_Init.inc");
#endif
}

Entity4F5C* Entity4F5C_Create(u32 id, u32 _) {
  Entity4F5C* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity4F5C));

  if (p != NULL) {
    SetEntityRoutine(p, Entity4F5C_Update, Entity4F5C_Destroy);
    if (Entity4F5C_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
