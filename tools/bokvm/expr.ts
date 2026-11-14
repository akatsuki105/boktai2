import { type BokVM, OP } from "./vm.ts";

// src/vm_expr.c の移植。

// 評価スタックの深さ (C の ExprSlot stack[8])
const EXPR_STACK_SIZE = 8;
const OPERATOR_ASSIGN = 22;

// C の Div / Mod と同じく 0 方向に切り捨てる, 0 除算は BIOS の Div が返す値を再現していないので警告して 0 にする
const div = (vm: BokVM, a: number, b: number): number => {
  if (b === 0) {
    vm.trace.warn("0 で割りました");
    return 0;
  }
  return Math.trunc(a / b) | 0;
};

const mod = (vm: BokVM, a: number, b: number): number => {
  if (b === 0) {
    vm.trace.warn("0 で剰余を取りました");
    return 0;
  }
  return (a % b) | 0;
};

// ARM のレジスタ指定のシフトは下位8bitを見て, 32 以上なら 0 になる (JS は下位5bitしか見ない)
const shiftAmount = (b: number): number => b & 0xFF;

// VM_RunOperator, op は opcode の下位5ビット
export const runOperator = (vm: BokVM, op: number, a: number, b: number): number => {
  switch (op - 1) {
    case 0:
      return -b | 0;
    case 1:
      return b === 0 ? 1 : 0;
    case 2:
      return ~b;
    case 3:
      return (a + b) | 0;
    case 4:
      return (a - b) | 0;
    case 5:
      return Math.imul(a, b);
    case 6:
      return div(vm, a, b);
    case 7:
      return mod(vm, a, b);
    case 8:
      return shiftAmount(b) >= 32 ? 0 : a << shiftAmount(b);
    case 9:
      return shiftAmount(b) >= 32 ? 0 : (a >>> shiftAmount(b)) | 0;
    case 10:
      return a === b ? 1 : 0;
    case 11:
      return a !== b ? 1 : 0;
    case 12:
      return a < b ? 1 : 0;
    case 13:
      return a <= b ? 1 : 0;
    case 14:
      return a > b ? 1 : 0;
    case 15:
      return a >= b ? 1 : 0;
    case 16:
      return a | b;
    case 17:
      return a & b;
    case 18:
      return a ^ b;
    case 19:
      return a !== 0 || b !== 0 ? 1 : 0;
    case 20:
      return a !== 0 && b !== 0 ? 1 : 0;
    case 22:
      return b;
    default:
      return 0;
  }
};

type Slot = { value: number; lvaluePc: number | null };

// VM_RunExpression, 逆ポーランド記法の式を評価する
// オペランドを積むときにそのバイト位置を覚えておき, 代入ではそこを左辺として書き戻す
export const runExpression = (vm: BokVM, pc: number): number => {
  const stack: Slot[] = [];
  let top = -1;
  const slot = (i: number): Slot => (stack[i] ??= { value: 0, lvaluePc: null });

  while (true) {
    const tag = vm.mem.u8(pc);
    if ((tag & 0xE0) === OP.END_EXPRESSION) {
      const op = tag & 0x1F;
      top--;
      if (op === 0) return slot(top + 1).value;
      if (op === OPERATOR_ASSIGN) {
        const lhsPc = slot(top).lvaluePc!;
        const lhs = vm.mem.u8(lhsPc);
        const val = slot(top + 1).value;
        if ((lhs & 0xF0) === OP.VARIABLE) {
          vm.storeVariable(lhs & 0xF, val);
        } else {
          vm.storePointer(lhsPc, val);
        }
        slot(top).value = val;
      } else {
        slot(top).value = runOperator(vm, op, slot(top).value, slot(top + 1).value);
        slot(top).lvaluePc = null;
      }
      pc++;
    } else {
      if (top + 1 >= EXPR_STACK_SIZE) vm.trace.warn(`式の評価スタック (${EXPR_STACK_SIZE}段) があふれました`);
      slot(top + 1).lvaluePc = pc;
      const d = vm.decodeValue(pc);
      if (d.type === OP.BLOCK) {
        vm.execBlock(d.val, null, 0);
        slot(top + 1).value = vm.result;
      } else {
        slot(top + 1).value = d.val;
      }
      if (d.next === null) throw new Error(`0x${pc.toString(16).toUpperCase()}: 式の途中に終端があります`);
      pc = d.next;
      top++;
    }
  }
};
