#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "random.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

// 血のパーティクル, 敵の吸血攻撃などで使用される

#define ANIM_D1B8_BLOOD 12  // ANIM_D1B8 の animidx

typedef struct {
  Vec3* basePos;  // 0x00, 位置の基準, オフセットを足して粒子の座標にする
  Vec3 offset;    // 0x04, basePos からのずれ
  Vec3 unk_c;     // 0x0C, まだ読み手が見つかっていない
  u8 unk_14[2];   // 0x14
  u8 state;       // 0x16, PTR_ARRAY_085ad32c の添字, BloodEmitter_FreePtcl が 0 に戻す
  s8 idx;         // 0x17, 自分の添字, ptcls と activeMask のビットを指す
  u16 timer;      // 0x18, 毎フレーム +1
  s16 delay;      // 0x1A, 0 を超えている間は数え下げるだけで何もしない
} BloodPtcl;
static_assert(sizeof(BloodPtcl) == 28);

typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;      // 0x018, ANIM_D1B8
  ParticleGroup* group0;  // 0x01C, PTCL_GROUP_0
  Particle ptcls[8];      // 0x020, slots[i].idx が添字
  AuxAnimState anims[8];  // 0x160, slots[i].idx が添字, ANIM_D1B8 の再生状態
  u32 activeMask;         // 0x1E0, 使用中の slots のビットマスク
  BloodPtcl slots[8];     // 0x1E4, 根拠: _Destroy の stride 0x1C × 8
} BloodEmitter;
static_assert(sizeof(BloodEmitter) == 708);

static BloodEmitter* sBloodEmitter;  // 0x03000168

s32 BloodEmitter_SpawnImpl(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count, u32 priority);

static inline void BloodEmitter_SetGlobal(BloodEmitter* p) { sBloodEmitter = p; }

static inline bool8 BloodEmitter_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void BloodEmitter_UpdatePtclIdle(BloodEmitter* p, BloodPtcl* elem) {}

// state 1 の更新, 粒子を基準位置へ置いてアニメを1コマ進め, 一巡したら state 2 へ移す
void BloodEmitter_UpdatePtcl(BloodEmitter* p, BloodPtcl* slot) {
  Particle* ptcl = &p->ptcls[slot->idx];

  if (slot->delay > 0) {
    slot->delay--;
    return;
  }

  ptcl->flags &= ~SPRFLAG_HIDDEN;
  ptcl->pos.x = slot->basePos->x + slot->offset.x;
  ptcl->pos.y = slot->basePos->y + slot->offset.y;
  ptcl->pos.z = slot->basePos->z + slot->offset.z;

  if (Particle_AdvanceAnim(ptcl, p->group0, &p->anims[slot->idx])) {
    slot->state = 2;
  }
  slot->timer++;
}

// 枠を解放する, パーティクルを外して activeMask のビットを落とす
void BloodEmitter_FreePtcl(BloodEmitter* p, BloodPtcl* slot) {
  Particle_Remove(&p->ptcls[slot->idx]);
  slot->state = 0;
  CLEAR_BIT(p->activeMask, slot->idx);
  ClearMemory(slot, sizeof(BloodPtcl));
  slot->idx = -1;
}

// 空いている枠を確保して返す, 無ければ NULL
BloodPtcl* BloodEmitter_AllocPtcl(BloodEmitter* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!BloodEmitter_IsActive(&p->activeMask, i)) {
      BloodPtcl* slot = &p->slots[i];

      slot->idx = i;
      p->activeMask |= 1 << i;
      return slot;
    }
  }
  return NULL;
}

s32 SpawnBloodEx(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count, u32 priority) { return BloodEmitter_SpawnImpl(basePos, offset, unkRand, offsetRand, count, priority); }

s32 SpawnBlood(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count) { return BloodEmitter_SpawnImpl(basePos, offset, unkRand, offsetRand, count, 2); }

// 残差11命令 (272/283). 原典はレジスタが1本足りずスタック枠が 4 バイト多く (sub sp #0x18), slot を低位に残すために unkRand/offsetRand を高位へ追い出して mov で回すが, こちらは収まってしまう
// ループ内ローカルを関数スコープへ出しても変化なし. 第1引数は Entity ではなく Vec3* (基準位置) で, エンティティは sBloodEmitter から取る
NON_MATCH s32 BloodEmitter_SpawnImpl(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count, u32 priority) {
#ifdef NONMATCHING_C
  BloodEmitter* p;
  s32 i;

  if (basePos == NULL) {
    return -1;
  }

  p = sBloodEmitter;
  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < count; i++) {
    BloodPtcl* slot = BloodEmitter_AllocPtcl(p);
    Particle* ptcl;
    Vec3 v;

    if (slot == NULL) {
      return -1;
    }

    ptcl = &p->ptcls[slot->idx];
    slot->basePos = basePos;

    if (offset == NULL) {
      slot->offset.x = 0;
      slot->offset.y = 0;
      slot->offset.z = 0;
    } else {
      slot->offset = *offset;
    }

    if (offsetRand != NULL) {
      if (offsetRand->x != 0) {
        slot->offset.x = Mod(Random(), offsetRand->x * 2) - offsetRand->x + slot->offset.x;
      }
      if (offsetRand->y != 0) {
        slot->offset.y = Mod(Random(), offsetRand->y * 2) - offsetRand->y + slot->offset.y;
      }
      if (offsetRand->z != 0) {
        slot->offset.z = Mod(Random(), offsetRand->z * 2) - offsetRand->z + slot->offset.z;
      }
    }

    if (unkRand == NULL) {
      VEC3_SET(slot->unk_c, 0, 0, 0);
    } else {
      v.x = unkRand->x != 0 ? Mod(Random(), unkRand->x) : 0;
      v.y = unkRand->y != 0 ? Mod(Random(), unkRand->y) : 0;
      v.z = unkRand->z != 0 ? Mod(Random(), unkRand->z) : 0;
      slot->unk_c = v;
    }

    slot->delay = 0;
    Particle_Add(ptcl, p->group0, 0);
    Particle_SetOffset(ptcl, -8, -8);
    AuxAnim_SetAnim(&p->anims[slot->idx], p->anim, ANIM_D1B8_BLOOD, 0, 0);
    ptcl->flags |= SPRFLAG_HIDDEN;
    ptcl->priority = priority;
    slot->state = 1;
  }

  return 0;
#else
  INCFUNC("asm/func/BloodEmitter_SpawnImpl.inc");
#endif
}

void (*const PTR_ARRAY_085ad32c[3])(BloodEmitter*, BloodPtcl*) = {
    BloodEmitter_UpdatePtclIdle,
    BloodEmitter_UpdatePtcl,
    BloodEmitter_FreePtcl,
};  // 0x085AD32C

// 使用中の枠について state ごとの更新関数を呼ぶ
// 残差2命令 (45/47), 原典はループの前で &activeMask の定数 0x1E0 を判定とは別に作り直すが, こちらは判定で作ったものを使い回す, slots はループ内で &p->slots[i] を取ると原典どおり作り直される
// 試済: BloodEmitter_IsActive, slots を先頭や if の中のローカルにする形, BeeNest_Update と同じ早めの return
NON_MATCH s32 BloodEmitter_Update(BloodEmitter* p) {
#ifdef NONMATCHING_C
  if (p->activeMask != 0) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (BloodEmitter_IsActive(&p->activeMask, i)) {
        BloodPtcl* slot = &p->slots[i];

        PTR_ARRAY_085ad32c[slot->state](p, slot);
      }
    }
  }

  return 0;
#else
  INCFUNC("asm/func/BloodEmitter_Update.inc");
#endif
}

// 使用中の枠の粒子をまとめて外す
s32 BloodEmitter_Destroy(BloodEmitter* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (BloodEmitter_IsActive(&p->activeMask, i)) {
      BloodPtcl* slot = &p->slots[i];

      Particle_Remove(&p->ptcls[slot->idx]);
    }
  }
  BloodEmitter_SetGlobal(NULL);
  return 0;
}

void BloodEmitter_LoadFiles(BloodEmitter* p) {
  p->group0 = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);
}

s32 BloodEmitter_Init(BloodEmitter* p) {
  BloodEmitter_LoadFiles(p);
  return 0;
}

BloodEmitter* BloodEmitter_Create(void) {
  if (sBloodEmitter == NULL) {
    BloodEmitter* p = CreateEntity(ENTITY_UNK_10, sizeof(BloodEmitter));
    BloodEmitter_SetGlobal(p);
    if (p != NULL) {
      SetEntityRoutine(p, BloodEmitter_Update, BloodEmitter_Destroy);
      if (BloodEmitter_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return sBloodEmitter;
}

void BloodEmitter_ClearGlobal(void) { sBloodEmitter = NULL; }
