#include "parser.h"

#include <stdexcept>

namespace bokasm {

Value Value::Int(int64_t x) {
  Value v;
  v.kind = INT;
  v.i = x;
  return v;
}

Value Value::Str(const std::string& x) {
  Value v;
  v.kind = STR;
  v.s = x;
  return v;
}

Value Value::Bytes(const std::vector<uint8_t>& x) {
  Value v;
  v.kind = BYTES;
  v.b = x;
  return v;
}

namespace {

[[noreturn]] void Unexpected(const std::string& msg, const Token& token) {
  throw std::runtime_error(msg + " (token ID " + std::to_string(static_cast<int>(token.type)) + " at line " +
                            std::to_string(token.line) + ")");
}

Value TokenToValue(const Token& t) {
  switch (t.type) {
    case T_IMMEDIATE:
      return Value::Int(t.int_arg);
    case T_STRING:
      return Value::Bytes(t.bytes_arg);
    case T_IDENTIFIER:
      return Value::Str(t.str_arg);
    default:
      Unexpected("Expected argument", t);
  }
}

// Walks the flat token vector with a single position cursor, mirroring
// bokasm's TokenBuffer (which wraps a Python generator with one token of
// lookahead).
class TokenCursor {
 public:
  explicit TokenCursor(const std::vector<Token>& tokens) : tokens_(tokens), pos_(0) {}

  bool HasToken() const { return pos_ < tokens_.size(); }
  const Token& tok() const { return tokens_[pos_]; }
  void Next() { pos_++; }

 private:
  const std::vector<Token>& tokens_;
  size_t pos_;
};

// Returns false when there are no more instructions to parse (end of
// input), mirroring raw_instruction() returning None in bokasm.
bool ParseRawInstruction(TokenCursor& buf, RawInstruction* out) {
  while (true) {
    if (!buf.HasToken()) {
      return false;
    }
    if (buf.tok().type == T_IDENTIFIER) {
      break;
    } else if (buf.tok().type == T_NEWLINE) {
      buf.Next();
    } else {
      Unexpected("Expected mnemonic", buf.tok());
    }
  }

  out->mnemonic = buf.tok().str_arg;
  buf.Next();

  if (buf.HasToken() && buf.tok().type == T_COLON) {
    out->is_label = true;
    buf.Next();
    if (buf.HasToken() && buf.tok().type != T_NEWLINE) {
      Unexpected("Expected newline after label", buf.tok());
    }
    if (buf.HasToken()) buf.Next();
    return true;
  }

  while (true) {
    if (!buf.HasToken()) {
      // The reference lexer always terminates with a trailing T_NEWLINE
      // token, so a well-formed token stream never actually runs out here.
      return true;
    }
    if (buf.tok().type == T_NEWLINE) {
      return true;
    } else if (buf.tok().type == T_COMMA || buf.tok().type == T_EQUALS) {
      Unexpected("Expected argument", buf.tok());
    }

    Token key = buf.tok();
    buf.Next();
    if (!buf.HasToken() || buf.tok().type == T_NEWLINE) {
      out->args.push_back(TokenToValue(key));
      if (buf.HasToken()) buf.Next();
      return true;
    } else if (buf.tok().type == T_COMMA) {
      out->args.push_back(TokenToValue(key));
      buf.Next();
    } else if (buf.tok().type == T_EQUALS) {
      buf.Next();
      if (!buf.HasToken() || buf.tok().type == T_COMMA || buf.tok().type == T_EQUALS ||
          buf.tok().type == T_NEWLINE || buf.tok().type == T_IDENTIFIER) {
        Unexpected("Expected immediate", buf.tok());
      }
      out->kwargs[key.str_arg] = TokenToValue(buf.tok());
      buf.Next();
    } else {
      // key itself was not followed by a separator (e.g. two bare
      // identifiers in a row) - treat as a malformed argument list.
      Unexpected("Expected argument", buf.tok());
    }
  }
}

int ResolveMemoryName(const std::string& name) {
  auto it = MEMORY_NAMES.find(name);
  if (it != MEMORY_NAMES.end()) {
    return it->second;
  }
  // Legacy names.
  if (name == "current") return MEM_STAT;
  if (name == "committed") return MEM_WORLD;
  if (name == "other") return MEM_SCRATCH;
  throw std::runtime_error("Unknown memory base '" + name + "'");
}

}  // namespace

std::vector<RawInstruction> parse(const std::vector<Token>& tokens) {
  std::vector<RawInstruction> result;
  TokenCursor buf(tokens);
  RawInstruction raw;
  while (ParseRawInstruction(buf, &raw)) {
    result.push_back(raw);
    raw = RawInstruction();
  }
  return result;
}

Instruction convert(const RawInstruction& raw) {
  const std::string& m = raw.mnemonic;

  if (raw.is_label) {
    return Instruction::op_label(m);
  }

  if (m == "end") {
    return Instruction::op_end();
  } else if (m == "i16") {
    return Instruction::op_i16(raw.args.at(0).i);
  } else if (m == "u8") {
    return Instruction::op_u8(raw.args.at(0).i);
  } else if (m == "u8_0x03") {
    return Instruction::op_u8(raw.args.at(0).i, 0x03);
  } else if (m == "u8_0x04") {
    return Instruction::op_u8(raw.args.at(0).i, 0x04);
  } else if (m == "u16") {
    return Instruction::op_u16(raw.args.at(0).i);
  } else if (m == "u16_0x08") {
    return Instruction::op_u16(raw.args.at(0).i, 0x08);
  } else if (m == "string") {
    return Instruction::op_string_imm(raw.args.at(0).b);
  } else if (m == "i32") {
    return Instruction::op_i32(raw.args.at(0).i);
  } else if (m == "i32_0x0a") {
    return Instruction::op_i32(raw.args.at(0).i, 0x0a);
  } else if (m == "i32_0x0d") {
    return Instruction::op_i32(raw.args.at(0).i, 0x0d);
  } else if (m == "string-ref") {
    return Instruction::op_string_ref(raw.args.at(0).i);
  } else if (m == "ptr" || m == "indexed-ptr") {
    const std::string& dt_str = raw.args.at(0).s;

    bool has_bit = false;
    int64_t bit = 0;
    auto bit_it = raw.kwargs.find("bit");
    if (bit_it != raw.kwargs.end()) {
      has_bit = true;
      bit = bit_it->second.i;
    }

    int base;
    int64_t offset;
    if (raw.args.size() == 3) {
      base = ResolveMemoryName(raw.args.at(1).s);
      offset = raw.args.at(2).i;
    } else {
      // Backwards compat for absolute Boktai 1 addresses.
      int64_t address = raw.args.at(1).i;
      if (address >= 0x0203f000) {
        base = MEM_SCRATCH;
        offset = address - 0x0203f000;
      } else if (address >= 0x0203e800) {
        base = MEM_WORLD;
        offset = address - 0x0203e800;
      } else if (address >= 0x0203d800) {
        base = MEM_STAT;
        offset = address - 0x0203d800;
      } else {
        throw std::runtime_error("Address out of known range: " + std::to_string(address));
      }
    }

    // i16 (nibble 0x1, alias 0x6) and pointer-u8 (nibble 0x2, alias 0x3)
    // each have an unused-alias type nibble; bool/u16/i32 do not.
    int dt;
    int forced_type_nibble = -1;
    if (dt_str == "i16") {
      dt = DT_I16;
    } else if (dt_str == "i16_0x6") {
      dt = DT_I16;
      forced_type_nibble = 0x6;
    } else if (dt_str == "u8") {
      dt = DT_U8;
    } else if (dt_str == "u8_0x3") {
      dt = DT_U8;
      forced_type_nibble = 0x3;
    } else if (dt_str == "bool") {
      dt = DT_BOOL;
    } else if (dt_str == "u16") {
      dt = DT_U16;
    } else if (dt_str == "i32") {
      dt = DT_I32;
    } else {
      throw std::runtime_error("Invalid pointer type '" + dt_str + "'");
    }

    if (m == "indexed-ptr") {
      return Instruction::op_ptr_indexed(dt, base, offset, has_bit, bit, forced_type_nibble);
    }
    return Instruction::op_ptr(dt, base, offset, has_bit, bit, forced_type_nibble);
  } else if (m == "expr") {
    return Instruction::op_expr();
  } else if (m == "param") {
    return Instruction::op_param(raw.args.at(0).i);
  } else if (m == "keyword") {
    return Instruction::op_keyword(raw.args.at(0).i);
  } else if (m == "control") {
    return Instruction::op_control(raw.args.at(0).i);
  } else if (m == "call") {
    return Instruction::op_call(raw.args.at(0).i);
  } else if (m == "block") {
    return Instruction::op_block();
  } else if (m == "var") {
    return Instruction::op_var(raw.args.at(0).i);
  }

  auto op_it = OPERATOR_NAMES.find(m);
  if (op_it != OPERATOR_NAMES.end()) {
    return Instruction::op_operator(op_it->second);
  }
  auto ctrl_it = CTRL_NAMES.find(m);
  if (ctrl_it != CTRL_NAMES.end()) {
    return Instruction::op_control(ctrl_it->second);
  }

  // Keywords.
  if (m == "else") {
    return Instruction::op_keyword(0x65);
  } else if (m == "else-if") {
    return Instruction::op_keyword(0x69);
  } else if (m == "case") {
    return Instruction::op_keyword(0x63);
  } else if (m == "default") {
    return Instruction::op_keyword(0x64);
  }

  throw std::runtime_error("Unknown mnemonic '" + m + "'");
}

}  // namespace bokasm
