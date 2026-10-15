#include "entity.h"
#include "global.h"
#include "particle.h"
#include "sprite_aux.h"

struct SolarCircle;

typedef void(SolarCircleFunc)(struct SolarCircle* p);

typedef struct {
  Particle ptcl;  // 0x00
  u8 unk_28[8];   // 0x28, まだ未解析
  s16 active;     // 0x30, 0 でない枠だけ更新する
  u8 unk_32[2];   // 0x32, まだ未解析
} SolarCirclePtcl;
static_assert(sizeof(SolarCirclePtcl) == 52);

// 太陽結界(この上に置いたイモータルが入った棺桶は逃げ出さない)
typedef struct SolarCircle {
  Entity e;                         // 0x000, ENTITY_UNK_9
  AuxSprite sprite;                 // 0x018, flags に SPRFLAG_BLINK_ODD が立つ, pos より y が 0x1E 高い (立体的に見せるため)
  AuxSpriteGfx gfx;                 // 0x044, SPRITE_MAGIC_CIRCLE, パレット 99
  AuxSprite sprite2;                // 0x060, flags に SPRFLAG_BLINK_EVEN が立つ
  AuxSpriteGfx gfx2;                // 0x08C, SPRITE_MAGIC_CIRCLE, パレット 97
  u16 enabled;                      // 0x0A8, FUN_080a1f5c の結果
  u16 stateTimer;                   // 0x0AA, Init が 0 を書く
  Vec3 pos;                         // 0x0AC, '.p', y はタイルの attr から計算し直す
  SolarCircleFunc* updateCallback;  // 0x0B4, '.m' があるかで切り替える
  u32 unk_b8;                       // 0x0B8, 各枠の更新に渡す
  u8 unk_bc[4];                     // 0x0BC, まだ未解析
  SolarCirclePtcl ptcls[8];         // 0x0C0
  u32 unk_260;                      // 0x260, '.i'
  u32 unk_264;                      // 0x264, '.o'
} SolarCircle;
static_assert(sizeof(SolarCircle) == 616);

NAKED void FUN_080a1e28(SolarCirclePtcl* elem, u32 param_2) { INCFUNC("asm/func/FUN_080a1e28.inc"); }

NAKED void FUN_080a1e78(SolarCircle* p) { INCFUNC("asm/func/FUN_080a1e78.inc"); }

NAKED bool32 FUN_080a1f5c(SolarCircle* p) { INCFUNC("asm/func/FUN_080a1f5c.inc"); }

NAKED void FUN_080a1fc4(SolarCircle* p) { INCFUNC("asm/func/FUN_080a1fc4.inc"); }

NAKED void FUN_080a20a0(SolarCircle* p) { INCFUNC("asm/func/FUN_080a20a0.inc"); }

NAKED void FUN_080a2114(SolarCircle* p) { INCFUNC("asm/func/FUN_080a2114.inc"); }

NAKED s32 SolarCircle_Update(SolarCircle* p) { INCFUNC("asm/func/SolarCircle_Update.inc"); }

NAKED s32 SolarCircle_Destroy(SolarCircle* p) { INCFUNC("asm/func/SolarCircle_Destroy.inc"); }

NAKED void FUN_080a21fc(SolarCircle* p) { INCFUNC("asm/func/FUN_080a21fc.inc"); }

NAKED s32 SolarCircle_Init(SolarCircle* p, u32 id, u32 _) { INCFUNC("asm/func/SolarCircle_Init.inc"); }

// 0xF156, HashName("太陽結界")
NAKED SolarCircle* SolarCircle_Create(u32 id, u32 unused) { INCFUNC("asm/func/SolarCircle_Create.inc"); }
