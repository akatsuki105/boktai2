#include "entity.h"
#include "global.h"

typedef struct {
  Entity e;  // ENTITY_UNK_11
  u8 unk_18[1120 - 0x18];
} PasswordScreen;
static_assert(sizeof(PasswordScreen) == 1120);

const ALIGNED(4) char sChar_085aa838[] = "<WEIGHT>";   // 0x085aa838
const ALIGNED(4) char sChar_085aa844[] = "</WEIGHT>";  // 0x085aa844

INCASM("asm/password.inc");

NAKED s32 PasswordScreen_Update(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_Update.inc"); }

NAKED s32 PasswordScreen_Destroy(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_Destroy.inc"); }

NAKED s32 PasswordScreen_Init(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_Init.inc"); }

NAKED PasswordScreen* PasswordScreen_Create(void) { INCFUNC("asm/func/PasswordScreen_Create.inc"); }
