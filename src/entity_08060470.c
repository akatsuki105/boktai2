#include "entity.h"
#include "global.h"
#include "particle.h"

// Entity08060470 が持つ粒子1個, 生成元 (Entity08060470_Spawn) が角度と速度から vel を作り、
// 以降は Entity08060470_UpdateElem が毎フレーム ptcl.pos に vel を足すだけ
typedef struct Entity08060470Elem {
  u8 state;       // 0x00, PTR_ARRAY_085abaac の添字 (0 = 何もしない, 1 = 飛行中), 根拠: Entity08060470_Update
  u8 unk_1;       // 0x01, 生成時に1、最初の更新で0にされる, 読み手は未発見, 根拠: Entity08060470_UpdateElem
  u16 timer;      // 0x02, 毎フレーム +1, 根拠: Entity08060470_Update
  u16 lifetime;   // 0x04, timer がこれ以上になると消える, 生成時は配置半径としても使われる, 根拠: Entity08060470_UpdateElem / Entity08060470_Spawn
  u8 unk_6[2];    // 0x06, 読み書きとも未発見, padding
  Particle ptcl;  // 0x08
  Vec3 vel;       // 0x30, 毎フレーム ptcl.pos に加算される, 根拠: Entity08060470_UpdateElem
} Entity08060470Elem;
static_assert(sizeof(Entity08060470Elem) == 56);

// 粒子を16個まで抱えるエンティティ, 空きスロットは activeMask のビットで管理する
typedef struct Entity08060470 {
  Entity e;                      // 0x00, ENTITY_UNK_10
  u32 unk_18;                    // 0x18, 読み手も書き手も未発見
  u32 activeMask;                // 0x1C, 1 << i で ptcls[i] が使用中, 根拠: Entity08060470_Init が0クリア、Entity08060470_ReleaseElem がビットを落とす
  ParticleGroup* group;          // 0x20, PTCL_GROUP_2
  Entity08060470Elem ptcls[16];  // 0x24
} Entity08060470;
static_assert(sizeof(Entity08060470) == 932);

extern void* gEntity08060470;  // 0x03000134

// 粒子を1個分だけ初期化する
void Entity08060470_InitElem(Entity08060470* p, Entity08060470Elem* elem, s32 idx) {
  Particle* ptcl = &elem->ptcl;

  elem->state = 0;
  elem->unk_1 = 1;
  elem->timer = 0;
  elem->lifetime = 0;
  Particle_Setup(ptcl, p->group, 1);
  Particle_SetPltt(ptcl, 1);
  Particle_SetFrame(ptcl, p->group, 3);
  Particle_SetOffset(ptcl, -4, -4);
}

void Entity08060470_ReleaseElem(Entity08060470* p, Entity08060470Elem* elem, s32 idx) {
  Particle_Remove(&elem->ptcl);
  p->activeMask &= ~(1 << idx);
}

void FUN_08060358(Entity08060470* p, Entity08060470Elem* elem, s32 idx) {}

// vel の分だけ粒子を進め, 寿命が来たら解放して枠を空ける
// 残差は37命令 vs 44命令, 原典は pos と vel のベースポインタを別に作って y/z を +2/+4 で引くが agbcc は elem からの固定オフセットに畳む, Vec3* ローカル2本/3本は試済
NON_MATCH void Entity08060470_UpdateElem(Entity08060470* p, Entity08060470Elem* elem, s32 idx) {
#ifdef NONMATCHING_C
  Particle* ptcl = &elem->ptcl;

  if (elem->unk_1) {
    elem->unk_1 = 0;
  }

  ptcl->pos.x += elem->vel.x;
  ptcl->pos.y += elem->vel.y;
  ptcl->pos.z += elem->vel.z;

  if (elem->timer >= elem->lifetime) {
    Entity08060470_ReleaseElem(p, elem, idx);
    elem->state = 0;
    elem->unk_1 = 1;
    elem->timer = 0;
  }
#else
  INCFUNC("asm/func/Entity08060470_UpdateElem.inc");
#endif
}

void (*const PTR_ARRAY_085abaac[2])(Entity08060470*, Entity08060470Elem*, s32) = {
    FUN_08060358,
    Entity08060470_UpdateElem,
};  // 0x085ABAAC

NAKED s32 Entity08060470_Update(Entity08060470* p) { INCFUNC("asm/func/Entity08060470_Update.inc"); }

s32 Entity08060470_Destroy(Entity08060470* p) {
  Entity08060470Elem* elem = p->ptcls;
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (p->activeMask & (1 << i)) {
      Entity08060470_ReleaseElem(p, elem, i);
    }
  }

  gEntity08060470 = NULL;
  return 0;
}

s32 Entity08060470_Init(Entity08060470* p) {
  Entity08060470Elem* elem;
  s32 i;

  gEntity08060470 = p;
  p->activeMask = 0;
  p->group = GetParticleGroup(PTCL_GROUP_2);

  elem = p->ptcls;
  for (i = 0; i < 16; i++, elem++) {
    Entity08060470_InitElem(p, elem, i);
  }
  return 0;
}

Entity08060470* Entity08060470_Create(void) {
  Entity08060470* p = gEntity08060470;

  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity08060470));
  if (p != NULL) {
    SetEntityRoutine(p, Entity08060470_Update, Entity08060470_Destroy);
    if (Entity08060470_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// 空きスロットを探して添字を *outIdx に入れて返す
Entity08060470Elem* Entity08060470_FindFreeElem(Entity08060470* p, u32* outIdx) {
  Entity08060470Elem* elem = p->ptcls;
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (!(p->activeMask & (1 << i))) {
      *outIdx = i;
      return elem;
    }
  }

  *outIdx = 0;
  return NULL;
}

NAKED s32 Entity08060470_Spawn(u8 angle, s32 speed, u16 radius, Vec3* pos) { INCFUNC("asm/func/Entity08060470_Spawn.inc"); }
