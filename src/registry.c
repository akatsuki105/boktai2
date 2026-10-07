#include "registry.h"

#include "global.h"

// アドレス上は 0x0203B000 から 0x0203B400 の手前までの128スロットだが、Registry_AllocEntry が 31 を超えたところで NULL を返すので実際に使われるのは32スロットまで
EWRAM_DATA RegistryEntry gRegistry[128] = {};

RegistryEntry* Registry_AllocEntry(void) {
  s32 i;
  RegistryEntry* p = &gRegistry[0];
  for (i = 0; i < gRegistryCount; i++, p++) {
    if (!(p->flags & REG_ACTIVE)) {
      return p;
    }
  }

  gRegistryCount++;
  if (gRegistryCount > 31) {
    return NULL;
  }
  return p;
}

RegistryEntry* Registry_FindEntry(u16 id) {
  s32 i;
  RegistryEntry* p = &gRegistry[0];
  for (i = 0; i < gRegistryCount; i++, p++) {
    if ((p->flags & REG_ACTIVE) && (p->id == id)) {
      return p;
    }
  }
  return NULL;
}

void Registry_Reset(void) { gRegistryCount = 0; }

NAKED void Registry_Sweep(bool32 clearAll) { INCFUNC("asm/func/Registry_Sweep.inc"); }

void Registry_Add(u16 id, void* ptr, s32 flags) {
  RegistryEntry* p = Registry_AllocEntry();
  if (p != NULL) {
    p->id = id;
    p->ptr = ptr;
    p->flags = REG_ACTIVE | flags;
  }
}

void Registry_Remove(u16 id) {
  RegistryEntry* p = Registry_FindEntry(id);
  if (p != NULL) {
    p->flags = 0;
  }
}

void* Registry_Find(u16 id) {
  RegistryEntry* p = Registry_FindEntry(id);
  if (p == NULL) {
    return NULL;
  }
  return p->ptr;
}
