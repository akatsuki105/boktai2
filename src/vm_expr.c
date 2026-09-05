#include "global.h"
#include "vm.h"

void VM_StoreVariable(u32 varidx, u32 val);
u8* Script_StorePointer(u8* pc, u32 val);

/**
 * @param opcode 0xA1..0xBF, https://boktaihacking.net/wiki/Bytecode#Opcode_0xa0-0xbf_(operator)
 */
s32 VM_RunOperator(u32 opcode, s32 a, s32 b) {
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
    case 11: {
      return a != b;
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

typedef struct {
  s32 value;
  u8* lvaluePc;
} ExprSlot;

// 逆ポーランド記法で並んだ式を、オペランドを積むスタックを使って評価する
u32 VM_RunExpression(u8* pc) {
  ExprSlot stack[8];
  s32 type;
  s32 val;
  s32 op;
  u8 tag;
  u8* lhsPc;
  ExprSlot* top;
  ExprSlot* dst;

  top = stack - 1;

  while (TRUE) {
    type = *pc;
    if ((type & 0xE0) == OP_END_EXPRESSION) {
      op = type & ~0xE0;
      top--;
      if (op == 0) {
        return top[1].value;
      }
      if (op == 0x16) {
        s32 masked;
        lhsPc = top[0].lvaluePc;
        tag = *lhsPc;
        masked = tag & 0xF0;
        dst = top;
        if (masked == 0x90) {
          VM_StoreVariable(tag & 0xF, top[1].value);
        } else {
          Script_StorePointer(lhsPc, top[1].value);
        }
        dst->value = top[1].value;
      } else {
        top[0].value = VM_RunOperator(op, top[0].value, top[1].value);
        top[0].lvaluePc = NULL;
      }
      pc++;
    } else {
      top[1].lvaluePc = pc;
      pc = VM_DecodeValue(pc, &type, &val);
      if (type == OP_BLOCK) {
        Script_ExecBlock((u8*)val, NULL, 0);
        top[1].value = (s32)gVM.result;
      } else {
        top[1].value = val;
      }
      top++;
    }
  }
}
