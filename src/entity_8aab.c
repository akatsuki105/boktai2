#include "entity.h"
#include "global.h"
#include "player.h"
#include "shadow.h"
#include "sprite.h"
#include "video.h"

typedef struct {
  AuxSprite sprite;       // 0x00, Entity8AAB_Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx;       // 0x2C, SPRITE_HINT_PANEL
  u8 unk_48[216 - 0x48];  // 0x48, まだ未解析
} Entity8AABElem;
static_assert(sizeof(Entity8AABElem) == 216);

typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  Player* player;             // 0x018, _Init が gPlayerPtr[0] を入れる
  Entity8AABElem elems[16];   // 0x01C, _Init が16個ぶん Video_GetAuxSprite / AuxSprite_Add する
  AuxSprite sprite;           // 0xD9C, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx;           // 0xDC8, SPRITE_OTNK_97D3
  u8 unk_de4[0xDF4 - 0xDE4];  // 0xDE4, まだ未解析
  ParticleShadow shadow;      // 0xDF4, ParticleShadow_Init(&shadow, &sprite.pos, 0) のあと Hide する
  AuxAnimFile* anim;          // 0xE34, ANIM_C6A0
  u16 unk_e38;                // 0xE38, _Init が 0 を入れる
  u8 unk_e3a;                 // 0xE3A, _Init が 1 を入れる
  u8 unk_e3b;                 // 0xE3B, まだ未解析
  u16 unk_e3c;                // 0xE3C, _Init が 0 を入れる
  u8 unk_e3e[2];              // 0xE3E, まだ未解析
  Mover unk_e40;              // 0xE40, _Destroy が Mover_Unlink に渡す
  u16 unk_e84;                // 0xE84, _Init が書き込む
  u16 unk_e86;                // 0xE86, _Init が書き込む
  u16 unk_e88;                // 0xE88, _Init が書き込む
  u8 unk_e8a[2];              // 0xE8A, まだ未解析
  u16 unk_e8c;                // 0xE8C, _Init が 0x19 を入れる
  u16 unk_e8e;                // 0xE8E, _Init が 0x66 を入れる
  u16 unk_e90;                // 0xE90, _Init が 0 を入れる
  u8 unk_e92[0xE9C - 0xE92];  // 0xE92, まだ未解析
  u16 unk_e9c;                // 0xE9C, _Init が書き込む
  u8 unk_e9e[0xEA4 - 0xE9E];  // 0xE9E, まだ未解析
  rgb555 pltt0[16];           // 0xEA4, _Init が gfx.pltt の 0x10..0x1F 番を写す
  rgb555 pltt1[32];           // 0xEC4, _Init が gfx.pltt の 0x00..0x0F 番を2組ぶん写す
  rgb555* plttSrc;            // 0xF04, gfx.pltt の写し
  u8 unk_f08[0xF1A - 0xF08];  // 0xF08, まだ未解析
  u16 unk_f1a;                // 0xF1A, _Init が 200 を入れる
  u16 unk_f1c;                // 0xF1C, _Init が 0 を入れる
  u8 unk_f1e[4];              // 0xF1E, まだ未解析
  u8 unk_f22;                 // 0xF22, _Init が 0 を入れる
  u8 unk_f23[4];              // 0xF23, まだ未解析
  u8 unk_f27;                 // 0xF27, _Init が 0 を入れる
  u8 unk_f28[0xF36 - 0xF28];  // 0xF28, まだ未解析
  u16 unk_f36;                // 0xF36, _Init が 0 を入れる
  u8 unk_f38[0xF46 - 0xF38];  // 0xF38, まだ未解析
  u16 unk_f46;                // 0xF46, _Destroy が Mover_FindByID_Proxy に渡す ID
  u8 unk_f48[0xF50 - 0xF48];  // 0xF48, まだ未解析
  u32 unk_f50;                // 0xF50, _Init が 0 を入れる
  u32 unk_f54;                // 0xF54, _Init が 0 を入れる
  u8 unk_f58[4];              // 0xF58, まだ未解析
  u32 unk_f5c;                // 0xF5C, _Init が 0 を入れる
} Entity8AAB;
static_assert(sizeof(Entity8AAB) == 3936);

IWRAM_DATA Entity8AAB* gEntity8AAB = NULL;  // 0x03000248

void FUN_08222cd4(void) { gEntity8AAB = NULL; }

INCASM("asm/entity_8aab.inc");

NAKED s32 Entity8AAB_Update(Entity8AAB* p) { INCFUNC("asm/func/Entity8AAB_Update.inc"); }

NAKED s32 Entity8AAB_Destroy(Entity8AAB* p) { INCFUNC("asm/func/Entity8AAB_Destroy.inc"); }

NAKED void FUN_08229394(void) { INCFUNC("asm/func/FUN_08229394.inc"); }

NAKED void FUN_0822970c(void) { INCFUNC("asm/func/FUN_0822970c.inc"); }

NAKED s32 Entity8AAB_Init(Entity8AAB* p) { INCFUNC("asm/func/Entity8AAB_Init.inc"); }

Entity8AAB* Entity8AAB_Create(u32 val) {
  Entity8AAB* p;

  if (gEntity8AAB != NULL) {
    return gEntity8AAB;
  }

  p = CreateEntity(ENTITY_UNK_11, sizeof(Entity8AAB));
  if (p != NULL) {
    p->unk_f46 = val;
    SetEntityRoutine(p, Entity8AAB_Update, Entity8AAB_Destroy);
    if (Entity8AAB_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

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
};  // 0x085b0084

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
};  // 0x085b00c4

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
