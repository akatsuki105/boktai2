#include "entity.h"
#include "global.h"
#include "input.h"
#include "sound.h"
#include "text.h"
#include "vm.h"

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_11
  u32 timer;                 // 0x018, 毎フレーム +1
  u8 unk_1c[0x24 - 0x01C];   // 0x01C
  u32 rngState;              // 0x024, PasswordScreen_NextRandom が回す線形合同法の状態
  u16 scriptID;              // 0x028, START を押したときに VM_ExecByID する, 実行したら 0 に戻す
  u8 unk_2a[0x44C - 0x02A];  // 0x02A
  s32 windowIDs[3];          // 0x44C, TextPanel_Create の戻り値, _Destroy が TextPanel_Destroy に渡す
  u8 unk_458[1120 - 0x458];  // 0x458
} PasswordScreen;
static_assert(sizeof(PasswordScreen) == 1120);

const ALIGNED(4) char sChar_085aa838[] = "<WEIGHT>";   // 0x085aa838
const ALIGNED(4) char sChar_085aa844[] = "</WEIGHT>";  // 0x085aa844

NAKED void FUN_08012c74(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_08012c74.inc"); }

// 線形合同法を1回まわして次の値を返す
s32 PasswordScreen_NextRandom(PasswordScreen* p) {
  p->rngState = p->rngState * 0x6262C05D + 1;
  return p->rngState;
}

NAKED s32 FUN_08012d00(PasswordScreen* p, s32 value, s32* bitPos, s32 width) { INCFUNC("asm/func/FUN_08012d00.inc"); }

NAKED s32 FUN_08012d68(PasswordScreen* p) { INCFUNC("asm/func/FUN_08012d68.inc"); }

NAKED s32 PasswordScreen_EncodeBits(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_EncodeBits.inc"); }

// 最初の40フレームは2フレームおきに文字送りの音を鳴らし, 60フレーム目以降は START でスクリプトへ戻る
s32 PasswordScreen_Update(PasswordScreen* p) {
  if (p->timer <= 40 && !(p->timer & 1)) {
    PlaySound_082406e0(SONG_628);
  }

  if (p->timer > 59 && (gInput[0].pressed & START_BUTTON)) {
    PlaySound_082406e0(SE_SELECT);
    if (p->scriptID != 0) {
      VM_ExecByID(p->scriptID, NULL);
      p->scriptID = 0;
    }
  }

  p->timer++;
  return 0;
}

s32 PasswordScreen_Destroy(PasswordScreen* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    TextPanel_Destroy(p->windowIDs[i]);
  }

  return 0;
}

NAKED s32 PasswordScreen_Init(PasswordScreen* p) { INCFUNC("asm/func/PasswordScreen_Init.inc"); }

PasswordScreen* PasswordScreen_Create(void) {
  PasswordScreen* p = CreateEntity(ENTITY_UNK_11, sizeof(PasswordScreen));

  if (p != NULL) {
    SetEntityRoutine(p, PasswordScreen_Update, PasswordScreen_Destroy);
    if (PasswordScreen_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
