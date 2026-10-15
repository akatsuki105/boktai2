#include "entity.h"
#include "global.h"
#include "particle.h"
#include "sprite_aux.h"

struct Entity080c1abc;

typedef void(Entity080c1abcFunc)(struct Entity080c1abc* p);

typedef struct {
  Particle ptcl;  // 0x00, コマ 0x11, パレット 1, オフセット (-4,-4)
  bool8 active;   // 0x28, 初期化で 0 を書く
  u8 unk_29[7];   // 0x29, まだ未解析
} Entity080c1abcPtcl;
static_assert(sizeof(Entity080c1abcPtcl) == 48);

typedef struct Entity080c1abc {
  Entity e;                            // 0x000, ENTITY_UNK_8
  u32 unk_18;                          // 0x018, Init の第2引数
  AuxSprite sprite;                    // 0x01C
  AuxSpriteGfx gfx;                    // 0x048, SPRITE_EFF_210E, パレット 46
  u8 unk_64[8];                        // 0x064, まだ未解析
  u16 unk_6c;                          // 0x06C, Init の第3引数
  u8 unk_6e;                           // 0x06E, まだ未解析
  u8 unk_6f;                           // 0x06F, Init が 0 を書く
  u16 stateTimer;                      // 0x070, updateCallback を差し替えるたびに 0 に戻る
  u16 unk_72;                          // 0x072, Init の第4引数
  u8 unk_74[3];                        // 0x074, まだ未解析
  u8 unk_77;                           // 0x077, 初期化で 0 を書く
  ParticleGroup* group;                // 0x078, PTCL_GROUP_2
  Entity080c1abcPtcl ptcls[4];         // 0x07C
  Entity080c1abcFunc* updateCallback;  // 0x13C
} Entity080c1abc;
static_assert(sizeof(Entity080c1abc) == 320);

NAKED void Entity080c1abc_SetUpdateCallback(Entity080c1abc* p, Entity080c1abcFunc* fn) { INCFUNC("asm/func/Entity080c1abc_SetUpdateCallback.inc"); }

NAKED void FUN_080c13f8(Entity080c1abc* p) { INCFUNC("asm/func/FUN_080c13f8.inc"); }

NAKED void FUN_080c1574(Entity080c1abc* p) { INCFUNC("asm/func/FUN_080c1574.inc"); }

NAKED void FUN_080c1664(Entity080c1abc* p) { INCFUNC("asm/func/FUN_080c1664.inc"); }

NAKED void FUN_080c17e8(Entity080c1abc* p) { INCFUNC("asm/func/FUN_080c17e8.inc"); }

NAKED void FUN_080c1810(Entity080c1abc* p) { INCFUNC("asm/func/FUN_080c1810.inc"); }

NAKED void FUN_080c18dc(Entity080c1abc* p) { INCFUNC("asm/func/FUN_080c18dc.inc"); }

NAKED void FUN_080c191c(Entity080c1abc* p) { INCFUNC("asm/func/FUN_080c191c.inc"); }

NAKED s32 Entity080c1abc_Update(Entity080c1abc* p) { INCFUNC("asm/func/Entity080c1abc_Update.inc"); }

NAKED s32 Entity080c1abc_Destroy(Entity080c1abc* p) { INCFUNC("asm/func/Entity080c1abc_Destroy.inc"); }

NAKED void Entity080c1abc_InitSprite(Entity080c1abc* p) { INCFUNC("asm/func/Entity080c1abc_InitSprite.inc"); }

NAKED void Entity080c1abc_InitParticles(Entity080c1abc* p) { INCFUNC("asm/func/Entity080c1abc_InitParticles.inc"); }

NAKED s32 Entity080c1abc_Init(Entity080c1abc* p, u32 param_2, u16 param_3, u16 param_4) { INCFUNC("asm/func/Entity080c1abc_Init.inc"); }

NAKED Entity080c1abc* Entity080c1abc_Create(u32 param_1, u16 param_2, u16 param_3) { INCFUNC("asm/func/Entity080c1abc_Create.inc"); }
