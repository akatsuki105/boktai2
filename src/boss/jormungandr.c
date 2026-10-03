#include "boss.h"
#include "entity.h"
#include "global.h"

// "Typo Beast"
typedef struct {
  Entity e;  // 0x0, ENTITY_UNK_8
  u8 unk_18[9744 - 0x18];
} Jormungandr;
static_assert(sizeof(Jormungandr) == 9744);

const u16 u16_ARRAY_085ad0d8[3] = {341, 345, 349};  // 0x085AD0D8

const u16 u16_ARRAY_085ad0de[14] = {0, 2, 5, 9, 13, 17, 21, 24, 27, 29, 31, 33, 35, 37};  // 0x085AD0DE

const SoundID16 u16_ARRAY_085ad0fa[3] = {0x2FB, 0x2FD, 0x2FF};  // 0x085AD0FA

void FUN_080ca004(unknown*);
void FUN_080ca008(unknown*);
void FUN_080ca00c(unknown*);
void FUN_080ca010(unknown*);
void FUN_080ca014(unknown*);
void FUN_080ca018(unknown*);
void FUN_080ca01c(unknown*);
void FUN_080ca020(unknown*);
void FUN_080ca024(unknown*);

void (*const PTR_ARRAY_085ad100[9])(unknown*) = {
    FUN_080ca004, FUN_080ca008, FUN_080ca00c, FUN_080ca010, FUN_080ca014, FUN_080ca018, FUN_080ca01c, FUN_080ca020, FUN_080ca024,
};  // 0x085AD100

void FUN_080ca028(unknown*);
void FUN_080ca02c(unknown*);

void (*const PTR_ARRAY_085ad124[2])(unknown*) = {
    FUN_080ca028,
    FUN_080ca02c,
};  // 0x085AD124

void FUN_080ca030(unknown*);

void (*const PTR_ARRAY_085ad12c[1])(unknown*) = {
    FUN_080ca030,
};  // 0x085AD12C

void FUN_080ca034(unknown*);

void (*const PTR_ARRAY_085ad130[1])(unknown*) = {
    FUN_080ca034,
};  // 0x085AD130

void FUN_080ca050(unknown*);

void (*const PTR_ARRAY_085ad134[1])(unknown*) = {
    FUN_080ca050,
};  // 0x085AD134

void FUN_080ca06c(unknown*);
void FUN_080ca088(unknown*);
void FUN_080ca0c4(unknown*);
void FUN_080ca0e0(unknown*);

void (*const PTR_ARRAY_085ad138[4])(unknown*) = {
    FUN_080ca06c,
    FUN_080ca088,
    FUN_080ca0c4,
    FUN_080ca0e0,
};  // 0x085AD138

INCASM("asm/jormungandr.inc");

NAKED s32 Jormungandr_Update(Jormungandr* p) { INCFUNC("asm/func/Jormungandr_Update.inc"); }

NAKED s32 Jormungandr_Destroy(Jormungandr* p) { INCFUNC("asm/func/Jormungandr_Destroy.inc"); }

NAKED s32 Jormungandr_Init(Jormungandr* p, unknown* param) { INCFUNC("asm/func/Jormungandr_Init.inc"); }

Jormungandr* Jormungandr_Create(unknown* param) {
  Jormungandr* p = FUN_08022a2c(BOSS_JORMUNGANDR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Jormungandr));
  if (p != NULL) {
    SetEntityRoutine(p, Jormungandr_Update, Jormungandr_Destroy);
    if (Jormungandr_Init(p, param) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
