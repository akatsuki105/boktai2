#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;            // ENTITY_UNK_8
  UnkStruct52 unk_18;  // 0x18
  u8 unk_4c[400 - 0x4c];
} Entity28CB;
static_assert(sizeof(Entity28CB) == 400);

void FUN_08089ce0(Entity28CB*);
void FUN_08089d24(Entity28CB*);
void FUN_08089d50(Entity28CB*);
void FUN_08089ddc(Entity28CB*);
void FUN_08089e98(Entity28CB*);
void FUN_08089f38(Entity28CB*);
void FUN_08089f58(Entity28CB*);
void FUN_08089ff0(Entity28CB*);

void (*const PTR_ARRAY_085ac044[8])(Entity28CB*) = {
    FUN_08089ce0, FUN_08089d24, FUN_08089d50, FUN_08089ddc, FUN_08089e98, FUN_08089f38, FUN_08089f58, FUN_08089ff0,
};

const u16 u16_ARRAY_085ac064[16] = {
    0xD01B, 0xD000, 0xD000, 0xD41B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD02B, 0xD000, 0xD000, 0xD42B, 0xD81B, 0xD000, 0xD000, 0xDC1B,
};

// TODO: 他のEntityのrodataもまだ混ざってるのでちゃんと分ける
INCBIN(".rodata", "data/rodata3.bin");  // ./tmp/bin.sh ./baserom.gba 0x085ac084 0x085af0ec ./data/rodata3.bin
