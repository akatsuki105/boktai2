#include "global.h"

void FUN_08241f28(Entity5* p);
Entity5* FUN_08241ef4(Entity5* p);
Entity* FUN_08241f14(Entity* _);

NAKED u32 ReflectClock(void) { INCFUNC("asm/func/ReflectClock.inc"); }

NAKED void clock_08241fd0(Entity5* p) { INCFUNC("asm/func/clock_08241fd0.inc"); }

Entity5* FUN_0824211c(Entity5* p) {
  FUN_08241f28(p);
  clock_08241fd0(p);
  PTR_03001708 = p;
  return NULL;
}

Entity5* FUN_0824213c(void) {
  if (PTR_03001708 == NULL) {
    Entity5* p = (Entity5*)CreateEntity(ENTITY_UNK_5, 48);
    if (p != NULL) {
      SetEntityRoutine((Entity*)p, (EntityFunc)FUN_08241ef4, (EntityFunc)FUN_08241f14);
      if ((s32)FUN_0824211c(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return PTR_03001708;
}
