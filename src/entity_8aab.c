#include "entity.h"
#include "global.h"

typedef struct Entity8AAB {
  Entity e;  // 0x0, ENTITY_UNK_11
  u8 unk_18[3936 - 0x18];
} Entity8AAB;
static_assert(sizeof(Entity8AAB) == 3936);

extern Entity8AAB* gEntity8AAB;  // 0x03000248

void FUN_08222cd4(void) { gEntity8AAB = NULL; }

INCASM("asm/entity_8aab.inc");

NAKED Entity8AAB* Entity8AAB_Create(u32 val) { INCFUNC("asm/func/Entity8AAB_Create.inc"); }

void FUN_08224fb8(void*);
void FUN_0822517c(void*);
void FUN_082253e4(void*);
void FUN_08225658(void*);
void FUN_082258bc(void*);
void FUN_08225b18(void*);
void FUN_08225d40(void*);
void FUN_08225f50(void*);
void FUN_08226048(void*);
void FUN_08226520(void*);
void FUN_08226990(void*);
void FUN_08226fd0(void*);
void FUN_08227168(void*);
void FUN_082272f0(void*);
void FUN_08227498(void*);
void FUN_08227608(void*);

// clang-format off
const void* const PTR_ARRAY_085b0084[16] = {
    (void*)FUN_08224fb8,
    (void*)FUN_0822517c,
    (void*)FUN_082253e4,
    (void*)FUN_08225658,
    (void*)FUN_082258bc,
    (void*)FUN_08225b18,
    (void*)FUN_08225d40,
    (void*)FUN_08225f50,
    (void*)FUN_08226048,
    (void*)FUN_08226520,
    (void*)FUN_08226990,
    (void*)FUN_08226fd0,
    (void*)FUN_08227168,
    (void*)FUN_082272f0,
    (void*)FUN_08227498,
    (void*)FUN_08227608,
}; // 0x085b0084
// clang-format on

void FUN_082279e0(void*);
void FUN_082279e4(void*);
void FUN_08227c14(void*);
void FUN_08227e44(void*);
void FUN_08228074(void*);
void FUN_082282a4(void*);
void FUN_082284b8(void*);
void FUN_082286e8(void*);
void FUN_08228918(void*);
void FUN_08228b48(void*);
void FUN_08228d8c(void*);
void FUN_08228e94(void*);
void FUN_08228f9c(void*);

// clang-format off
const void* const PTR_ARRAY_085b00c4[15] = {
    (void*)FUN_082279e0,
    (void*)FUN_082279e4,
    (void*)FUN_08227c14,
    (void*)FUN_08227e44,
    (void*)FUN_08228074,
    (void*)FUN_082282a4,
    (void*)FUN_082284b8,
    (void*)FUN_082286e8,
    (void*)FUN_08228918,
    (void*)FUN_08228b48,
    (void*)FUN_08228d8c,
    (void*)FUN_08228e94,
    (void*)NULL,
    (void*)FUN_08228f9c,
    (void*)NULL,
}; // 0x085b00c4
// clang-format on

void FUN_0822913c(void*);
void FUN_08229140(void*);
void FUN_08229238(void*);
void FUN_08229288(void*);

const void* const PTR_ARRAY_085b0100[4] = {
    (void*)FUN_0822913c,
    (void*)FUN_08229140,
    (void*)FUN_08229238,
    (void*)FUN_08229288,
};
