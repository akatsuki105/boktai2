#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "random.h"
#include "sprite_animation.h"
#include "sprite_aux.h"

typedef struct {
  Vec3* basePos;  // 0x00, 位置の基準, オフセットを足して粒子の座標にする
  Vec3 offset;    // 0x04, basePos からのずれ
  Vec3 unk_c;     // 0x0C, まだ読み手が見つかっていない
  u8 unk_14[2];   // 0x14
  u8 state;       // 0x16, PTR_ARRAY_085ad32c の添字, FUN_080dc00c が 0 に戻す
  s8 idx;         // 0x17, 自分の添字, ptcls と activeMask のビットを指す
  u16 timer;      // 0x18, 毎フレーム +1
  s16 delay;      // 0x1A, 0 を超えている間は数え下げるだけで何もしない
} Entity080dc44cSlot;
static_assert(sizeof(Entity080dc44cSlot) == 28);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;            // 0x018, ANIM_D1B8
  ParticleGroup* group;         // 0x01C, PTCL_GROUP_0
  Particle ptcls[8];            // 0x020, slots[i].idx が添字
  AuxAnimState anims[8];        // 0x160, slots[i].idx が添字, ANIM_D1B8 の再生状態
  u32 activeMask;               // 0x1E0, 使用中の slots のビットマスク
  Entity080dc44cSlot slots[8];  // 0x1E4, 根拠: _Destroy の stride 0x1C × 8
} Entity080dc44c;
static_assert(sizeof(Entity080dc44c) == 708);

IWRAM_DATA Entity080dc44c* gEntity080dc44c = NULL;  // 0x03000168

static inline void Entity080dc44c_SetGlobal(Entity080dc44c* p) { gEntity080dc44c = p; }

static inline bool8 Entity080dc44c_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void FUN_080dbeb0(Entity080dc44c* p, Entity080dc44cSlot* elem) {}

s32 FUN_080dc0d0(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count, u32 priority);

// state 1 の更新, 粒子を基準位置へ置いてアニメを1コマ進め, 一巡したら state 2 へ移す
void FUN_080dbeb4(Entity080dc44c* p, Entity080dc44cSlot* slot) {
  Particle* ptcl = &p->ptcls[slot->idx];

  if (slot->delay > 0) {
    slot->delay--;
    return;
  }

  ptcl->flags &= ~SPRFLAG_HIDDEN;
  ptcl->pos.x = slot->basePos->x + slot->offset.x;
  ptcl->pos.y = slot->basePos->y + slot->offset.y;
  ptcl->pos.z = slot->basePos->z + slot->offset.z;

  if (Particle_AdvanceAnim(ptcl, p->group, &p->anims[slot->idx])) {
    slot->state = 2;
  }
  slot->timer++;
}

// 枠を解放する, パーティクルを外して activeMask のビットを落とす
void FUN_080dc00c(Entity080dc44c* p, Entity080dc44cSlot* slot) {
  Particle_Remove(&p->ptcls[slot->idx]);
  slot->state = 0;
  CLEAR_BIT(p->activeMask, slot->idx);
  ClearMemory(slot, sizeof(Entity080dc44cSlot));
  slot->idx = -1;
}

// 空いている枠を確保して返す, 無ければ NULL
Entity080dc44cSlot* FUN_080dc050(Entity080dc44c* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!Entity080dc44c_IsActive(&p->activeMask, i)) {
      Entity080dc44cSlot* slot = &p->slots[i];

      slot->idx = i;
      p->activeMask |= 1 << i;
      return slot;
    }
  }
  return NULL;
}

s32 FUN_080dc0a0(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count, u32 priority) { return FUN_080dc0d0(basePos, offset, unkRand, offsetRand, count, priority); }

s32 FUN_080dc0b8(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count) { return FUN_080dc0d0(basePos, offset, unkRand, offsetRand, count, 2); }

// 残差11命令 (272/283). 原典はレジスタが1本足りずスタック枠が 4 バイト多く (sub sp #0x18), slot を低位に残すために unkRand/offsetRand を高位へ追い出して mov で回すが, こちらは収まってしまう
// ループ内ローカルを関数スコープへ出しても変化なし. 第1引数は Entity ではなく Vec3* (基準位置) で, エンティティは gEntity080dc44c から取る
NON_MATCH s32 FUN_080dc0d0(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count, u32 priority) {
#ifdef NONMATCHING_C
  Entity080dc44c* p;
  s32 i;

  if (basePos == NULL) {
    return -1;
  }

  p = gEntity080dc44c;
  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < count; i++) {
    Entity080dc44cSlot* slot = FUN_080dc050(p);
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
    Particle_Add(ptcl, p->group, 0);
    Particle_SetOffset(ptcl, -8, -8);
    AuxAnim_SetAnim(&p->anims[slot->idx], p->anim, 12, 0, 0);
    ptcl->flags |= SPRFLAG_HIDDEN;
    ptcl->priority = priority;
    slot->state = 1;
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_080dc0d0.inc");
#endif
}

void (*const PTR_ARRAY_085ad32c[3])(Entity080dc44c*, Entity080dc44cSlot*) = {
    FUN_080dbeb0,
    FUN_080dbeb4,
    FUN_080dc00c,
};  // 0x085AD32C

// 使用中の枠について state ごとの更新関数を呼ぶ
// 残差7命令 (40/47). 5命令は使用中判定の 0/1 の作り置き, 残り2命令は原典が &activeMask と &slots の定数を別々に作るのに対しこちらは片方から差分で導くため
// Entity080db520_Update と同じ壁. slot の初期化を for の初期化節に移すと i=0 の位置だけは合う
// 使用中判定を bool8 を返す static inline にすると 0/1 の作り置きは出るが, 原典はループの前で &activeMask をガードとは別に作り直す (BeeNest_Update と同じ)
NON_MATCH s32 Entity080dc44c_Update(Entity080dc44c* p) {
#ifdef NONMATCHING_C
  if (p->activeMask != 0) {
    Entity080dc44cSlot* slot;
    s32 i;

    for (i = 0, slot = &p->slots[0]; i < 8; i++, slot++) {
      if (p->activeMask & (1 << i)) {
        PTR_ARRAY_085ad32c[slot->state](p, slot);
      }
    }
  }

  return 0;
#else
  INCFUNC("asm/func/Entity080dc44c_Update.inc");
#endif
}

// 使用中の枠の粒子をまとめて外す
s32 Entity080dc44c_Destroy(Entity080dc44c* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (Entity080dc44c_IsActive(&p->activeMask, i)) {
      Entity080dc44cSlot* slot = &p->slots[i];

      Particle_Remove(&p->ptcls[slot->idx]);
    }
  }
  Entity080dc44c_SetGlobal(NULL);
  return 0;
}

void FUN_080dc418(Entity080dc44c* p) {
  p->group = GetParticleGroup(PTCL_GROUP_0);
  p->anim = GetFile(DIR_ANIMATION, ANIM_D1B8);
}

s32 Entity080dc44c_Init(Entity080dc44c* p) {
  FUN_080dc418(p);
  return 0;
}

Entity080dc44c* Entity080dc44c_Create(void) {
  if (gEntity080dc44c == NULL) {
    Entity080dc44c* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080dc44c));
    Entity080dc44c_SetGlobal(p);
    if (p != NULL) {
      SetEntityRoutine(p, Entity080dc44c_Update, Entity080dc44c_Destroy);
      if (Entity080dc44c_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080dc44c;
}

void FUN_080dc498(void) { gEntity080dc44c = NULL; }
