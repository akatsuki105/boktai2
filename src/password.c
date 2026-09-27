#include "entity.h"
#include "global.h"
#include "text.h"

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_11
  u8 unk_18[0x44C - 0x018];  // 0x018
  s32 windowIDs[3];          // 0x44C, TextPanel_Create の戻り値, _Destroy が TextPanel_Destroy に渡す
  u8 unk_458[1120 - 0x458];  // 0x458
} PasswordScreen;
static_assert(sizeof(PasswordScreen) == 1120);

const ALIGNED(4) char sChar_085aa838[] = "<WEIGHT>";   // 0x085aa838
const ALIGNED(4) char sChar_085aa844[] = "</WEIGHT>";  // 0x085aa844

INCASM("asm/password.inc");

NAKED s32 PasswordScreen_Update(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_Update.inc"); }

s32 PasswordScreen_Destroy(PasswordScreen* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    TextPanel_Destroy(p->windowIDs[i]);
  }

  return 0;
}

NAKED s32 PasswordScreen_Init(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_Init.inc"); }

NAKED PasswordScreen* PasswordScreen_Create(void) { INCFUNC("asm/func/PasswordScreen_Create.inc"); }
