#include "entity.h"
#include "global.h"

void FUN_08230e30(u16 id, void *r1, s32 r2);
bool32 FUN_082326d8(void);

// 0x082324dc
s32 Arithmetic(u32 opcode, s32 a, s32 b) {
  switch (opcode - 1) {
    case 0: {
      return -b;
    }
    case 1: {
      return b == 0;
    }
    case 2: {
      return ~b;
    }
    case 3: {
      return a + b;
    }
    case 4: {
      return a - b;
    }
    case 5: {
      return a * b;
    }
    case 6: {
      return Div(a, b);
    }
    case 7: {
      return Mod(a, b);
    }
    case 8: {
      return a << b;
    }
    case 9: {
      return ((u32)a) >> b;
    }
    case 10: {
      return a == b;
    }
    case 11: {  // 同じ符号か
      return ((u32)(-(a ^ b) | (a ^ b))) >> 31;
    }
    case 12: {
      return a < b;
    }
    case 13: {
      return a <= b;
    }
    case 14: {
      return a > b;
    }
    case 15: {
      return a >= b;
    }
    case 16: {
      return a | b;
    }
    case 17: {
      return a & b;
    }
    case 18: {
      return a ^ b;
    }
    case 19: {
      return ((a != 0) || (b != 0));
    }
    case 20: {
      bool32 result = FALSE;
      if (a != 0) {
        result = ((u32)((-b) | b)) >> 31;
      }
      return result;
    }
    case 22: {
      return b;
    }
    case 21:
    default: {
      return 0;
    }
  }
}

NAKED void *FUN_08232600(u8 *code) { INCCODE("asm/todo/FUN_08232600.inc"); }

void FUN_082326a0(void) {
  struct Entity *p = AllocateEntity(0xe24);
  FUN_082309cc(p, 0xe24);
  FUN_08230e30(0x56c2, p, 1);
  gUnkPtr = p;
  FUN_082326d8();
}
