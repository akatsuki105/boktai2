// Port of bokasm/bytecode.py: abstract opcode/instruction definitions.
#ifndef BOKASM_BYTECODE_H
#define BOKASM_BYTECODE_H

#include <cstdint>
#include <map>
#include <string>
#include <vector>

namespace bokasm {

// Abstract opcodes. When assembling, the best concrete opcode is chosen
// (e.g. 0xc0 vs. 0x09 for encoding i32).
enum Opcode {
  OP_END,
  OP_I32,
  OP_I16,
  OP_U8,
  OP_U16,
  OP_STRING_IMM,
  OP_STRING_REF,
  OP_PTR,
  OP_PTR_INDEXED,
  OP_EXPR,
  OP_PARAM,
  OP_KEYWORD,
  OP_CONTROL,
  OP_CALL,
  OP_BLOCK,
  OP_VAR,
  OP_OPERATOR,
  // Label declaration ("NAME:"). bokasm-proper has no equivalent; this
  // emits zero bytes and has no grammatical effect on encoding. It exists
  // so the assembler can record NAME -> byte offset for tooling that
  // consumes the assembled output later (e.g. an .s emitter).
  OP_LABEL,
};

// Data types for pointer instructions.
enum DataType {
  DT_I16,
  DT_U8,
  DT_BOOL,
  DT_U16,
  DT_I32,
};

const int CTRL_IF = 0x0d86;
const int CTRL_SWITCH = 0x4a6f;
const int CTRL_RETURN = 0xcd3a;

// Operators for opcodes 0xa0-0xbf.
const int OPER_END_EXPR = 0x00;
const int OPER_NEGATE = 0x01;
const int OPER_NOT = 0x02;
const int OPER_BIT_NOT = 0x03;
const int OPER_ADD = 0x04;
const int OPER_SUB = 0x05;
const int OPER_MUL = 0x06;
const int OPER_DIV = 0x07;
const int OPER_MOD = 0x08;
const int OPER_LSL = 0x09;
const int OPER_LSR = 0x0a;
const int OPER_EQ = 0x0b;
const int OPER_NE = 0x0c;
const int OPER_LT = 0x0d;
const int OPER_LTE = 0x0e;
const int OPER_GT = 0x0f;
const int OPER_GTE = 0x10;
const int OPER_BIT_OR = 0x11;
const int OPER_BIT_AND = 0x12;
const int OPER_XOR = 0x13;
const int OPER_OR = 0x14;
const int OPER_AND = 0x15;
const int OPER_STORE = 0x16;

// Pointer base addresses.
const int MEM_WORLD = 0x00;    // Dungeon state etc.
const int MEM_STAT = 0x80;     // Player stats, inventory, etc.
const int MEM_SCRATCH = 0x10;  // Other data (nice description)

// name -> id lookup tables, used by the parser to resolve mnemonics.
extern const std::map<std::string, int> OPERATOR_NAMES;
extern const std::map<std::string, int> CTRL_NAMES;
extern const std::map<std::string, int> MEMORY_NAMES;

// Bytecode instruction. Does not include redundant arguments that the
// assembler should fill in (e.g. block/keyword sizes).
struct Instruction {
  Opcode opcode;
  std::vector<int64_t> args;
  std::vector<uint8_t> str_arg;  // valid only for OP_STRING_IMM
  bool has_bit = false;
  int64_t bit = 0;

  // Several opcodes have one or more "unused alias" concrete byte forms
  // that decode identically but were, rarely, what the original ROM
  // actually used: u8 0x02 vs 0x03/0x04, u16 0x06 vs 0x08, i32 0x09 vs
  // 0x0a/0x0d, and the ptr/indexed-ptr type nibble 0x1 vs 0x6 (i16) or
  // 0x2 vs 0x3 (u8). When set, the encoder emits this exact byte/nibble
  // instead of the default; for OP_I32 it also forces the full-width
  // 5-byte form even if the value would fit the compressed 0xc0-0xff
  // encoding.
  bool has_forced_opcode = false;
  int forced_opcode = 0;

  std::string label_name;  // valid only for OP_LABEL

  static Instruction op_end();
  static Instruction op_label(const std::string& name);
  static Instruction op_i32(int64_t x, int forced_opcode = -1);
  static Instruction op_i16(int64_t x);
  static Instruction op_u8(int64_t x, int forced_opcode = -1);
  static Instruction op_u16(int64_t x, int forced_opcode = -1);
  static Instruction op_string_imm(const std::vector<uint8_t>& x);
  static Instruction op_string_ref(int64_t x);
  static Instruction op_ptr(int dt, int base, int64_t offset, bool has_bit, int64_t bit, int forced_type_nibble = -1);
  static Instruction op_ptr_indexed(int dt, int base, int64_t offset, bool has_bit, int64_t bit,
                                     int forced_type_nibble = -1);
  static Instruction op_expr();
  static Instruction op_param(int64_t x);
  static Instruction op_keyword(int64_t x);
  static Instruction op_control(int64_t x);
  static Instruction op_call(int64_t x);
  static Instruction op_block();
  static Instruction op_var(int64_t x);
  static Instruction op_operator(int64_t x);
};

}  // namespace bokasm

#endif  // BOKASM_BYTECODE_H
