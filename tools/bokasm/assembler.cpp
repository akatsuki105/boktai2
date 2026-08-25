#include "assembler.h"

#include <cstdint>
#include <stdexcept>
#include <string>

#include "lexer.h"
#include "parser.h"

namespace bokasm {

namespace {

void PushU8(std::vector<uint8_t>* buf, int64_t x, int64_t lo, int64_t hi, const char* what) {
  if (x < lo || x > hi) {
    throw std::runtime_error(std::string(what) + " out of range: " + std::to_string(x));
  }
  buf->push_back(static_cast<uint8_t>(x));
}

void PushI16LE(std::vector<uint8_t>* buf, int64_t x) {
  if (x < -0x8000 || x > 0x7fff) {
    throw std::runtime_error("i16 out of range: " + std::to_string(x));
  }
  uint16_t u = static_cast<uint16_t>(static_cast<int16_t>(x));
  buf->push_back(static_cast<uint8_t>(u & 0xff));
  buf->push_back(static_cast<uint8_t>((u >> 8) & 0xff));
}

void PushU16LE(std::vector<uint8_t>* buf, int64_t x) {
  if (x < 0 || x > 0xffff) {
    throw std::runtime_error("u16 out of range: " + std::to_string(x));
  }
  buf->push_back(static_cast<uint8_t>(x & 0xff));
  buf->push_back(static_cast<uint8_t>((x >> 8) & 0xff));
}

void PushU16BE(std::vector<uint8_t>* buf, int64_t x) {
  if (x < 0 || x > 0xffff) {
    throw std::runtime_error("Pointer out of range: " + std::to_string(x));
  }
  buf->push_back(static_cast<uint8_t>((x >> 8) & 0xff));
  buf->push_back(static_cast<uint8_t>(x & 0xff));
}

void PushI32LE(std::vector<uint8_t>* buf, int64_t x) {
  if (x < INT32_MIN || x > INT32_MAX) {
    throw std::runtime_error("i32 out of range: " + std::to_string(x));
  }
  uint32_t u = static_cast<uint32_t>(static_cast<int32_t>(x));
  buf->push_back(static_cast<uint8_t>(u & 0xff));
  buf->push_back(static_cast<uint8_t>((u >> 8) & 0xff));
  buf->push_back(static_cast<uint8_t>((u >> 16) & 0xff));
  buf->push_back(static_cast<uint8_t>((u >> 24) & 0xff));
}

// Port of asm.py's _encode(): serializes a single instruction, choosing the
// most compact concrete opcode where the format allows it (e.g. the 0xc0-
// 0xff compressed form for small i32 values).
void Encode(const Instruction& insn, std::vector<uint8_t>* buf) {
  switch (insn.opcode) {
    case OP_END:
      buf->push_back(0x00);
      break;
    case OP_I32: {
      int64_t x = insn.args.at(0);
      if (insn.has_forced_opcode) {
        // An explicit alias mnemonic (i32_0x0a/i32_0x0d) always forces the
        // full-width form, even if x would fit the compressed encoding.
        buf->push_back(static_cast<uint8_t>(insn.forced_opcode));
        PushI32LE(buf, x);
      } else if (x >= -1 && x <= 62) {
        buf->push_back(static_cast<uint8_t>(0xc0 | (x + 1)));
      } else {
        buf->push_back(0x09);
        PushI32LE(buf, x);
      }
      break;
    }
    case OP_I16:
      buf->push_back(0x01);
      PushI16LE(buf, insn.args.at(0));
      break;
    case OP_U8:
      buf->push_back(static_cast<uint8_t>(insn.has_forced_opcode ? insn.forced_opcode : 0x02));
      PushU8(buf, insn.args.at(0), 0, 0xff, "u8");
      break;
    case OP_U16:
      buf->push_back(static_cast<uint8_t>(insn.has_forced_opcode ? insn.forced_opcode : 0x06));
      PushU16LE(buf, insn.args.at(0));
      break;
    case OP_STRING_IMM: {
      if (insn.str_arg.size() > 255) {
        throw std::runtime_error("Immediate string too long (maximum 255 bytes)");
      }
      buf->push_back(0x07);
      buf->push_back(static_cast<uint8_t>(insn.str_arg.size()));
      buf->insert(buf->end(), insn.str_arg.begin(), insn.str_arg.end());
      break;
    }
    case OP_STRING_REF:
      buf->push_back(0x0e);
      PushU16LE(buf, insn.args.at(0));
      break;
    case OP_PTR:
    case OP_PTR_INDEXED: {
      int dt = static_cast<int>(insn.args.at(0));
      uint8_t dt_byte;
      switch (dt) {
        case DT_I16:
          dt_byte = 0x1;
          break;
        case DT_U8:
          dt_byte = 0x2;
          break;
        case DT_BOOL:
          dt_byte = 0x4;
          break;
        case DT_U16:
          dt_byte = 0x8;
          break;
        case DT_I32:
          dt_byte = 0x9;
          break;
        default:
          throw std::runtime_error("Invalid pointer data type: " + std::to_string(dt));
      }
      if (insn.has_forced_opcode) {
        // i16_0x6 / u8_0x3: force the alias type nibble instead of the
        // default computed above.
        dt_byte = static_cast<uint8_t>(insn.forced_opcode);
      }

      int64_t base = insn.args.at(1);
      int64_t offset = insn.args.at(2);
      int64_t bit = insn.has_bit ? insn.bit : 0;

      uint8_t p = (insn.opcode == OP_PTR) ? 0x10 : 0x20;
      buf->push_back(static_cast<uint8_t>(p | dt_byte));
      buf->push_back(static_cast<uint8_t>(base | bit));
      PushU16BE(buf, offset);
      break;
    }
    case OP_EXPR:
      buf->push_back(0x30);
      break;
    case OP_PARAM: {
      int64_t x = insn.args.at(0);
      if (x < 0 || x > 0x10e) {
        throw std::runtime_error("Parameter out of range: " + std::to_string(x));
      } else if (x >= 0xf) {
        // x == 0xf is reachable both as the compact form below and as
        // this two-byte form (0x4f, 0); every real occurrence in the
        // corpus uses the two-byte form, so that's the default here
        // (unlike asm.py's "x > 0xf", which always picks compact and can
        // never reproduce the two-byte encoding for x == 0xf).
        buf->push_back(0x4f);
        buf->push_back(static_cast<uint8_t>(x - 0xf));
      } else {
        buf->push_back(static_cast<uint8_t>(0x40 | x));
      }
      break;
    }
    case OP_KEYWORD:
      buf->push_back(0x50);
      PushU8(buf, insn.args.at(0), 0, 0xff, "keyword");
      break;
    case OP_CONTROL:
      buf->push_back(0x60);
      PushU16LE(buf, insn.args.at(0));
      break;
    case OP_CALL:
      buf->push_back(0x70);
      PushU16LE(buf, insn.args.at(0));
      break;
    case OP_BLOCK:
      buf->push_back(0x80);
      break;
    case OP_VAR: {
      int64_t x = insn.args.at(0);
      if (x < 0 || x > 0xf) {
        throw std::runtime_error("Variable out of range: " + std::to_string(x));
      }
      buf->push_back(static_cast<uint8_t>(0x90 | x));
      break;
    }
    case OP_OPERATOR: {
      int64_t x = insn.args.at(0);
      if (x < 0 || x > 0x1f) {
        throw std::runtime_error("Operator out of range: " + std::to_string(x));
      }
      buf->push_back(static_cast<uint8_t>(0xa0 | x));
      break;
    }
    default:
      throw std::runtime_error("Invalid opcode");
  }
}

bool IsContainerOpener(Opcode op) {
  return op == OP_EXPR || op == OP_CONTROL || op == OP_KEYWORD || op == OP_CALL || op == OP_BLOCK;
}

}  // namespace

void Assembler::Write(const Instruction& instruction) {
  Opcode opcode = instruction.opcode;

  if (opcode == OP_LABEL) {
    for (const auto& entry : labels_) {
      if (entry.first == instruction.label_name) {
        throw std::runtime_error("Duplicate label '" + instruction.label_name + "'");
      }
    }
    labels_.emplace_back(instruction.label_name, buffer_->size());
    return;
  }

  if ((opcode == OP_KEYWORD || opcode == OP_END) && !container_stack_.empty()) {
    Container& top = container_stack_.back();
    if (top.opcode == OP_KEYWORD) {
      size_t offset = top.offset;
      container_stack_.pop_back();
      SetContainerSize(offset);
    } else if (top.opcode == OP_CONTROL && !top.nextkw_set) {
      top.nextkw_set = true;
      SetNextKeyword(top.offset);
    }
  }

  if (IsContainerOpener(opcode)) {
    Container c;
    c.opcode = opcode;
    c.offset = buffer_->size();
    container_stack_.push_back(c);
  }

  Encode(instruction, buffer_);

  if (opcode == OP_OPERATOR && instruction.args.at(0) == OPER_END_EXPR) {
    if (container_stack_.empty()) {
      throw std::runtime_error("end-expr: no open expression");
    }
    Container c = container_stack_.back();
    container_stack_.pop_back();
    if (c.opcode != OP_EXPR) {
      throw std::runtime_error("end-expr: expected termination of expression instruction");
    }
    SetContainerSize(c.offset);
  } else if (opcode == OP_END) {
    if (container_stack_.empty()) {
      throw std::runtime_error("end: no open control/call/block");
    }
    Container c = container_stack_.back();
    container_stack_.pop_back();
    if (c.opcode != OP_CONTROL && c.opcode != OP_CALL && c.opcode != OP_BLOCK) {
      throw std::runtime_error("end: expected termination of control/call/block instruction");
    }
    SetContainerSize(c.offset);
  }
}

void Assembler::SetContainerSize(size_t p) {
  uint8_t opcode = (*buffer_)[p];
  size_t size = buffer_->size() - p - 1;
  if ((opcode & 0x0f) != 0) {
    throw std::runtime_error("SetContainerSize: opcode already has a size nibble");
  }

  if (size > 0xffffff) {
    throw std::runtime_error("Container size out of range: " + std::to_string(size));
  } else if (size > 0xffff) {
    (*buffer_)[p] = static_cast<uint8_t>(opcode | 0xf);
    std::vector<uint8_t> extra = {
        static_cast<uint8_t>(size & 0xff),
        static_cast<uint8_t>((size >> 8) & 0xff),
        static_cast<uint8_t>((size >> 16) & 0xff),
    };
    buffer_->insert(buffer_->begin() + p + 1, extra.begin(), extra.end());
  } else if (size > 0xff) {
    (*buffer_)[p] = static_cast<uint8_t>(opcode | 0xe);
    std::vector<uint8_t> extra = {
        static_cast<uint8_t>(size & 0xff),
        static_cast<uint8_t>((size >> 8) & 0xff),
    };
    buffer_->insert(buffer_->begin() + p + 1, extra.begin(), extra.end());
  } else if (size > 0xc) {
    (*buffer_)[p] = static_cast<uint8_t>(opcode | 0xd);
    buffer_->insert(buffer_->begin() + p + 1, static_cast<uint8_t>(size));
  } else {
    (*buffer_)[p] = static_cast<uint8_t>(opcode | size);
  }
}

void Assembler::SetNextKeyword(size_t p) {
  uint8_t opcode = (*buffer_)[p];
  if (opcode != 0x60) {
    throw std::runtime_error("SetNextKeyword: expected a control instruction");
  }
  size_t pos = p + 3;
  size_t size = buffer_->size() - pos;

  if (size > 0x7fff) {
    throw std::runtime_error("Nextkw size out of range: " + std::to_string(size));
  } else if (size >= 0x80) {
    std::vector<uint8_t> extra = {
        static_cast<uint8_t>((size >> 8) | 0x80),
        static_cast<uint8_t>(size & 0xff),
    };
    buffer_->insert(buffer_->begin() + pos, extra.begin(), extra.end());
  } else {
    buffer_->insert(buffer_->begin() + pos, static_cast<uint8_t>(size));
  }
}

void Assembler::Finish() {
  if (!container_stack_.empty()) {
    std::string s;
    for (const Container& c : container_stack_) {
      if (!s.empty()) s += ", ";
      s += std::to_string(static_cast<int>(c.opcode));
    }
    throw std::runtime_error("Unterminated instructions: [" + s + "]");
  }
}

AssembleResult Assemble(std::istream& in) {
  std::vector<Token> tokens = lex(in);
  std::vector<RawInstruction> raw_insns = parse(tokens);

  AssembleResult result;
  Assembler asm_(&result.bytes);
  for (const RawInstruction& raw : raw_insns) {
    asm_.Write(convert(raw));
  }
  asm_.Finish();
  result.labels = asm_.labels();

  return result;
}

}  // namespace bokasm
