#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_9
  u8 unk_18[1116 - 0x18];
} Entity08017750;
static_assert(sizeof(Entity08017750) == 1116);

IWRAM_DATA Entity08017750* gEntity08017750 = NULL;  // 0x0300006C

void FUN_08017098(Entity08017750*, unknown*, unknown*);
void FUN_080170e4(Entity08017750*, unknown*, unknown*);
void FUN_08017160(Entity08017750*, unknown*, unknown*);
void FUN_080171f4(Entity08017750*, unknown*, unknown*);
void FUN_080172cc(Entity08017750*, unknown*, unknown*);
void FUN_08017358(Entity08017750*, unknown*, unknown*);

void (*const PTR_ARRAY_085aa92c[7])(Entity08017750*, unknown*, unknown*) = {
    FUN_08017098, FUN_080170e4, FUN_08017160, FUN_080171f4, FUN_080170e4, FUN_080172cc, FUN_08017358,
};  // 0x085AA92C

INCASM("asm/entity_08017750.inc");
