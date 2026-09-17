#include "entity.h"
#include "global.h"
#include "particle.h"
#include "sprite.h"
#include "vm.h"

// スクリプトから ID を指定して置く影, ScriptShadowManager がリストで管理する
typedef struct ScriptShadow {
  u16 id;                     // 0x00, FUN_08013d28 がこの値で探す, FUN_08013e38 でスクリプトの値をセット
  u8 mode;                    // 0x02, 0 ならリスト外 (FUN_08013d48 で 1, FUN_08013d70 で 0), FUN_08013e38 / FUN_08013f84 がスクリプトの値を入れ 1 なら FUN_08013698, 2 なら FUN_080136b4
  u8 unk_03;                  // 0x03
  Vec3 pos;                   // 0x04, 影を置く座標, FUN_08013e38 / FUN_08013ff0 がコピーし、shadow の持ち主座標として渡す
  ParticleShadow shadow;      // 0x0C, 根拠: FUN_0801385c / FUN_080138fc
  struct ScriptShadow* prev;  // 0x4C
  struct ScriptShadow* next;  // 0x50
} ScriptShadow;
static_assert(sizeof(ScriptShadow) == 84);  // 根拠: FUN_08013e38 の Malloc(0x54)

typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_9
  ScriptShadow* shadows;  // 0x18, 影のリストの先頭, Init で 0, FUN_08013d48 / FUN_08013d70 / FUN_08013d28 / Destroy
} ScriptShadowManager;
static_assert(sizeof(ScriptShadowManager) == 28);

COMMON_DATA ScriptShadowManager* gScriptShadowManager = NULL;  // 0x03002B40

NAKED ScriptShadowManager* FUN_08013d10(void) { INCFUNC("asm/func/FUN_08013d10.inc"); }

NAKED ScriptShadow* FUN_08013d28(ScriptShadowManager* p, u32 id) { INCFUNC("asm/func/FUN_08013d28.inc"); }

NAKED s32 FUN_08013d48(ScriptShadowManager* p, ScriptShadow* shadow) { INCFUNC("asm/func/FUN_08013d48.inc"); }

NAKED s32 FUN_08013d70(ScriptShadowManager* p, ScriptShadow* shadow) { INCFUNC("asm/func/FUN_08013d70.inc"); }

s32 Entity08013df0_Update(ScriptShadowManager* _) { return 0; }

NAKED s32 Entity08013df0_Destroy(ScriptShadowManager* p) { INCFUNC("asm/func/Entity08013df0_Destroy.inc"); }

s32 Entity08013df0_Init(ScriptShadowManager* p) {
  gScriptShadowManager = p;
  p->shadows = NULL;
  return 0;
}

NAKED ScriptShadowManager* Entity08013df0_Create(void) { INCFUNC("asm/func/Entity08013df0_Create.inc"); }

NAKED s32 FUN_08013e38(u32 id, s32 mode, Vec3* pos) { INCFUNC("asm/func/FUN_08013e38.inc"); }

NAKED s32 FUN_08013ebc(void) { INCFUNC("asm/func/FUN_08013ebc.inc"); }

NAKED s32 FUN_08013f30(u32 id) { INCFUNC("asm/func/FUN_08013f30.inc"); }

s32 FUN_08013f70(void) { return FUN_08013f30(VM_GetKeywordValue('n', 0)); }

NAKED s32 FUN_08013f84(u32 id, s32 mode) { INCFUNC("asm/func/FUN_08013f84.inc"); }

NAKED s32 FUN_08013fcc(void) { INCFUNC("asm/func/FUN_08013fcc.inc"); }

NAKED s32 FUN_08013ff0(u32 id, Vec3* pos) { INCFUNC("asm/func/FUN_08013ff0.inc"); }

NAKED s32 FUN_08014020(void) { INCFUNC("asm/func/FUN_08014020.inc"); }
