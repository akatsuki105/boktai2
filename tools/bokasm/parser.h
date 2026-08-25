// Port of bokasm/asm_parser.py.
#ifndef BOKASM_PARSER_H
#define BOKASM_PARSER_H

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "bytecode.h"
#include "lexer.h"

namespace bokasm {

// A parsed argument/kwarg value. Exactly one field is meaningful, selected
// by `kind` (mirrors the fact that a Python Token.arg can be int|str|bytes).
struct Value {
  enum Kind { INT, STR, BYTES } kind;
  int64_t i = 0;
  std::string s;
  std::vector<uint8_t> b;

  static Value Int(int64_t x);
  static Value Str(const std::string& x);
  static Value Bytes(const std::vector<uint8_t>& x);
};

struct RawInstruction {
  std::string mnemonic;
  std::vector<Value> args;
  std::map<std::string, Value> kwargs;
  // True for a label declaration ("NAME:"); mnemonic holds the label name
  // and args/kwargs are unused.
  bool is_label = false;
};

// Groups the flat token stream into one RawInstruction per source line.
std::vector<RawInstruction> parse(const std::vector<Token>& tokens);

// Resolves a RawInstruction's mnemonic/args into a concrete Instruction.
Instruction convert(const RawInstruction& raw);

}  // namespace bokasm

#endif  // BOKASM_PARSER_H
