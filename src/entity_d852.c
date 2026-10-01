#include "entity.h"
#include "global.h"
#include "particle.h"
#include "registry.h"
#include "vm.h"

// ロードゾーンの目印を粒子で表示するエンティティ
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_9
  u16 mode;            // 0x18, '.m', 1 なら粒子を隠して点滅を止める
  u8 unk_1a[2];        // 0x1A, まだ未解析
  u16 count;           // 0x1C, ptcls に積んだ数
  u16 blinkTimer;      // 0x1E, 毎フレーム +1 して 0x48 で 0 に戻り、0x30 未満の間だけ表示する
  Particle ptcls[17];  // 0x20
} EntityD852;
static_assert(sizeof(EntityD852) == 712);

void Map_SetLoadingZoneIndicatorMode(void) {
  if (VM_SeekToNamedArg('m')) {
    EntityD852* p = Registry_Find(0xFD22);

    if (p != NULL) {
      p->mode = VM_GetValue();
      if (p->mode == 1) {
        s32 i;

        for (i = 0; i < p->count; i++) {
          p->ptcls[i].flags |= SPRFLAG_HIDDEN;
        }

        p->blinkTimer = 0;
      }
    }
  }
}

NAKED void Map_AddLoadingZoneIndicator(u16* param_1, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/Map_AddLoadingZoneIndicator.inc"); }

NAKED void Map_AddLoadingZoneIndicatorScripted(void) { INCFUNC("asm/func/Map_AddLoadingZoneIndicatorScripted.inc"); }

NAKED s32 FUN_080a64cc(unknown* p) { INCFUNC("asm/func/FUN_080a64cc.inc"); }

NAKED void Map_SpawnLoadingZoneIndicator(void) { INCFUNC("asm/func/Map_SpawnLoadingZoneIndicator.inc"); }

NAKED s32 EntityD852_Update(EntityD852* p) { INCFUNC("asm/func/EntityD852_Update.inc"); }

s32 EntityD852_Destroy(EntityD852* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    Particle_Remove(&p->ptcls[i]);
  }

  return 0;
}

s32 EntityD852_Init(EntityD852* p) {
  p->mode = 0;
  p->count = 0;
  p->blinkTimer = 0;
  Registry_Add(0xFD22, p, 0);
  return 0;
}

EntityD852* EntityD852_Create(void) {
  EntityD852* p = CreateEntity(ENTITY_UNK_9, sizeof(EntityD852));

  if (p != NULL) {
    SetEntityRoutine(p, EntityD852_Update, EntityD852_Destroy);
    if (EntityD852_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
