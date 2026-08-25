// Port of bokasm/asm_lexer.py.
#ifndef BOKASM_LEXER_H
#define BOKASM_LEXER_H

#include <cstdint>
#include <istream>
#include <string>
#include <vector>

namespace bokasm {

enum TokenType {
  T_NEWLINE,
  T_COMMA,
  T_EQUALS,
  T_IMMEDIATE,
  T_STRING,
  T_IDENTIFIER,
  // ':' immediately after an identifier marks a label declaration
  // (e.g. "Script_2D11:"); bokasm-proper has no such construct.
  T_COLON,
};

// A token's payload lives in exactly one of the following fields, selected
// by `type` (T_IMMEDIATE -> int_arg, T_STRING -> bytes_arg, T_IDENTIFIER ->
// str_arg; the rest carry no payload).
struct Token {
  TokenType type;
  int line;
  int64_t int_arg = 0;
  std::string str_arg;
  std::vector<uint8_t> bytes_arg;
};

// Tokenizes the whole input up front (the reference implementation streams
// tokens lazily via a generator; scripts are small enough that eager
// tokenization is simpler and behaviorally equivalent).
std::vector<Token> lex(std::istream& in);

}  // namespace bokasm

#endif  // BOKASM_LEXER_H
