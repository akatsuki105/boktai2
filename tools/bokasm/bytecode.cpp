#include "bytecode.h"

namespace bokasm {

const std::map<std::string, int> OPERATOR_NAMES = {
    {"end-expr", OPER_END_EXPR}, {"negate", OPER_NEGATE},   {"not", OPER_NOT},
    {"bit-not", OPER_BIT_NOT},   {"add", OPER_ADD},         {"sub", OPER_SUB},
    {"mul", OPER_MUL},           {"div", OPER_DIV},         {"mod", OPER_MOD},
    {"lsl", OPER_LSL},           {"lsr", OPER_LSR},         {"eq", OPER_EQ},
    {"ne", OPER_NE},             {"lt", OPER_LT},           {"lte", OPER_LTE},
    {"gt", OPER_GT},             {"gte", OPER_GTE},         {"bit-or", OPER_BIT_OR},
    {"bit-and", OPER_BIT_AND},   {"xor", OPER_XOR},         {"or", OPER_OR},
    {"and", OPER_AND},           {"store", OPER_STORE},
};

const std::map<std::string, int> CTRL_NAMES = {
    {"if", CTRL_IF},
    {"switch", CTRL_SWITCH},
    {"return", CTRL_RETURN},
};

const std::map<std::string, int> MEMORY_NAMES = {
    {"world", MEM_WORLD},
    {"stat", MEM_STAT},
    {"scratch", MEM_SCRATCH},
};

Instruction Instruction::op_end() {
  Instruction i;
  i.opcode = OP_END;
  return i;
}

Instruction Instruction::op_label(const std::string& name) {
  Instruction i;
  i.opcode = OP_LABEL;
  i.label_name = name;
  return i;
}

Instruction Instruction::op_i32(int64_t x, int forced_opcode) {
  Instruction i;
  i.opcode = OP_I32;
  i.args.push_back(x);
  if (forced_opcode >= 0) {
    i.has_forced_opcode = true;
    i.forced_opcode = forced_opcode;
  }
  return i;
}

Instruction Instruction::op_i16(int64_t x) {
  Instruction i;
  i.opcode = OP_I16;
  i.args.push_back(x);
  return i;
}

Instruction Instruction::op_u8(int64_t x, int forced_opcode) {
  Instruction i;
  i.opcode = OP_U8;
  i.args.push_back(x);
  if (forced_opcode >= 0) {
    i.has_forced_opcode = true;
    i.forced_opcode = forced_opcode;
  }
  return i;
}

Instruction Instruction::op_u16(int64_t x, int forced_opcode) {
  Instruction i;
  i.opcode = OP_U16;
  i.args.push_back(x);
  if (forced_opcode >= 0) {
    i.has_forced_opcode = true;
    i.forced_opcode = forced_opcode;
  }
  return i;
}

Instruction Instruction::op_string_imm(const std::vector<uint8_t>& x) {
  Instruction i;
  i.opcode = OP_STRING_IMM;
  i.str_arg = x;
  return i;
}

Instruction Instruction::op_string_ref(int64_t x) {
  Instruction i;
  i.opcode = OP_STRING_REF;
  i.args.push_back(x);
  return i;
}

Instruction Instruction::op_ptr(int dt, int base, int64_t offset, bool has_bit, int64_t bit, int forced_type_nibble) {
  Instruction i;
  i.opcode = OP_PTR;
  i.args.push_back(dt);
  i.args.push_back(base);
  i.args.push_back(offset);
  i.has_bit = has_bit;
  i.bit = bit;
  if (forced_type_nibble >= 0) {
    i.has_forced_opcode = true;
    i.forced_opcode = forced_type_nibble;
  }
  return i;
}

Instruction Instruction::op_ptr_indexed(int dt, int base, int64_t offset, bool has_bit, int64_t bit,
                                         int forced_type_nibble) {
  Instruction i = op_ptr(dt, base, offset, has_bit, bit, forced_type_nibble);
  i.opcode = OP_PTR_INDEXED;
  return i;
}

Instruction Instruction::op_expr() {
  Instruction i;
  i.opcode = OP_EXPR;
  return i;
}

Instruction Instruction::op_param(int64_t x) {
  Instruction i;
  i.opcode = OP_PARAM;
  i.args.push_back(x);
  return i;
}

Instruction Instruction::op_keyword(int64_t x) {
  Instruction i;
  i.opcode = OP_KEYWORD;
  i.args.push_back(x);
  return i;
}

Instruction Instruction::op_control(int64_t x) {
  Instruction i;
  i.opcode = OP_CONTROL;
  i.args.push_back(x);
  return i;
}

Instruction Instruction::op_call(int64_t x) {
  Instruction i;
  i.opcode = OP_CALL;
  i.args.push_back(x);
  return i;
}

Instruction Instruction::op_block() {
  Instruction i;
  i.opcode = OP_BLOCK;
  return i;
}

Instruction Instruction::op_var(int64_t x) {
  Instruction i;
  i.opcode = OP_VAR;
  i.args.push_back(x);
  return i;
}

Instruction Instruction::op_operator(int64_t x) {
  Instruction i;
  i.opcode = OP_OPERATOR;
  i.args.push_back(x);
  return i;
}

}  // namespace bokasm
