#include "lexer.h"

#include <cctype>
#include <cstdlib>
#include <stdexcept>

namespace bokasm {

namespace {

// Reads characters from the input stream one at a time, keeping the current
// character and line number available, mirroring bokasm's CharBuffer.
class CharBuffer {
 public:
  explicit CharBuffer(std::istream& in) : in_(in), line_(1), ch_('\0'), eof_(false) {}

  void Next() {
    if (ch_ == '\n') {
      line_++;
    }
    int c = in_.get();
    if (c == std::istream::traits_type::eof()) {
      ch_ = '\0';
      eof_ = true;
    } else {
      ch_ = static_cast<char>(c);
    }
  }

  char ch() const { return ch_; }
  int line() const { return line_; }
  bool eof() const { return eof_; }

 private:
  std::istream& in_;
  int line_;
  char ch_;
  bool eof_;
};

void SkipComment(CharBuffer& buf) {
  while (!buf.eof()) {
    buf.Next();
    if (buf.ch() == '\n') {
      return;
    }
  }
}

// Parses a numeric literal the way Python's int(s, 0) does: an optional
// sign followed by a decimal, 0x/0X hex, 0o/0O octal, or 0b/0B binary
// literal. Deviation from CPython: a plain string with a leading zero
// (e.g. "0123") is read as decimal here instead of being rejected, since
// real script sources only use decimal or 0x-prefixed hex.
int64_t ParseIntAutoBase(const std::string& word, int line) {
  size_t i = 0;
  bool negative = false;
  if (i < word.size() && (word[i] == '+' || word[i] == '-')) {
    negative = word[i] == '-';
    i++;
  }

  std::string digits = word.substr(i);
  int base = 10;
  if (digits.size() > 2 && digits[0] == '0' && (digits[1] == 'x' || digits[1] == 'X')) {
    base = 16;
    digits = digits.substr(2);
  } else if (digits.size() > 2 && digits[0] == '0' && (digits[1] == 'o' || digits[1] == 'O')) {
    base = 8;
    digits = digits.substr(2);
  } else if (digits.size() > 2 && digits[0] == '0' && (digits[1] == 'b' || digits[1] == 'B')) {
    base = 2;
    digits = digits.substr(2);
  }

  if (digits.empty()) {
    throw std::runtime_error("Invalid immediate \"" + word + "\" (in line " + std::to_string(line) + ")");
  }

  char* end = nullptr;
  long long value = std::strtoll(digits.c_str(), &end, base);
  if (end == digits.c_str() || *end != '\0') {
    throw std::runtime_error("Invalid immediate \"" + word + "\" (in line " + std::to_string(line) + ")");
  }
  return negative ? -value : value;
}

bool IsWordTerminator(char ch) {
  return ch == ' ' || ch == '\t' || ch == '\n' || ch == ',' || ch == '=' || ch == ':';
}

// Reads a whitespace/comma/equals/newline-delimited word starting at the
// current character. Deviation from bokasm: the reference word() has no
// real EOF terminator (its EOF sentinel never matches, see asm_lexer.py),
// which would spin forever on a file with no trailing newline; treating
// EOF as an implicit terminator here avoids that hang.
std::string ReadWord(CharBuffer& buf) {
  std::string s(1, buf.ch());
  while (true) {
    buf.Next();
    if (buf.eof() || IsWordTerminator(buf.ch())) {
      return s;
    }
    s += buf.ch();
  }
}

Token ReadAsciiImmediate(CharBuffer& buf) {
  buf.Next();
  if (buf.ch() == '\n' || buf.ch() == '\'') {
    throw std::runtime_error("Invalid character; use an unquoted ASCII code instead (in line " +
                              std::to_string(buf.line()) + ")");
  }
  Token t;
  t.type = T_IMMEDIATE;
  t.line = buf.line();
  t.int_arg = static_cast<unsigned char>(buf.ch());
  buf.Next();
  if (buf.ch() != '\'') {
    throw std::runtime_error("Expected single quote, got \"" + std::string(1, buf.ch()) + "\" (in line " +
                              std::to_string(buf.line()) + ")");
  }
  buf.Next();
  return t;
}

Token ReadStringImmediate(CharBuffer& buf) {
  std::vector<uint8_t> bytes;
  while (true) {
    buf.Next();
    if (buf.ch() == '\\') {
      buf.Next();
      if (buf.ch() == '"') {
        bytes.push_back('"');
      } else if (buf.ch() == 'x') {
        buf.Next();
        char hi = buf.ch();
        buf.Next();
        char lo = buf.ch();
        std::string hex;
        hex += hi;
        hex += lo;
        bytes.push_back(static_cast<uint8_t>(std::strtoul(hex.c_str(), nullptr, 16)));
      } else {
        throw std::runtime_error("Unsupported escape sequence: \\" + std::string(1, buf.ch()) + " (in line " +
                                  std::to_string(buf.line()) + ")");
      }
    } else if (buf.ch() == '"') {
      buf.Next();
      Token t;
      t.type = T_STRING;
      t.line = buf.line();
      t.bytes_arg = bytes;
      return t;
    } else {
      bytes.push_back(static_cast<uint8_t>(buf.ch()));
    }
  }
}

Token ReadImmediate(CharBuffer& buf) {
  int line = buf.line();
  std::string w = ReadWord(buf);
  Token t;
  t.type = T_IMMEDIATE;
  t.line = line;
  t.int_arg = ParseIntAutoBase(w, line);
  return t;
}

Token ReadIdentifier(CharBuffer& buf) {
  int line = buf.line();
  std::string w = ReadWord(buf);
  Token t;
  t.type = T_IDENTIFIER;
  t.line = line;
  t.str_arg = w;
  return t;
}

}  // namespace

std::vector<Token> lex(std::istream& in) {
  std::vector<Token> tokens;
  CharBuffer buf(in);
  buf.Next();

  while (true) {
    if (buf.eof()) {
      Token t;
      t.type = T_NEWLINE;
      t.line = buf.line();
      tokens.push_back(t);
      return tokens;
    }

    char ch = buf.ch();
    // ';' is the original bokasm comment character; '@' is the ARM-asm-style
    // replacement. Both are accepted during the migration to '@'-only
    // sources; ';' support is planned for removal once tmp/scripts(2)
    // fully switch over.
    if (ch == ';' || ch == '@') {
      SkipComment(buf);
    } else if (ch == ' ' || ch == '\t') {
      buf.Next();
    } else if (ch == '\n') {
      Token t;
      t.type = T_NEWLINE;
      t.line = buf.line();
      tokens.push_back(t);
      buf.Next();
    } else if (ch == ',') {
      Token t;
      t.type = T_COMMA;
      t.line = buf.line();
      tokens.push_back(t);
      buf.Next();
    } else if (ch == '=') {
      Token t;
      t.type = T_EQUALS;
      t.line = buf.line();
      tokens.push_back(t);
      buf.Next();
    } else if (ch == ':') {
      Token t;
      t.type = T_COLON;
      t.line = buf.line();
      tokens.push_back(t);
      buf.Next();
    } else if (ch == '\'') {
      tokens.push_back(ReadAsciiImmediate(buf));
    } else if (ch == '"') {
      tokens.push_back(ReadStringImmediate(buf));
    } else if ((ch >= '0' && ch <= '9') || ch == '+' || ch == '-') {
      tokens.push_back(ReadImmediate(buf));
    } else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_') {
      // Uppercase/underscore only ever appear in label names
      // (e.g. "Script_2D11"); ordinary mnemonics stay lowercase.
      tokens.push_back(ReadIdentifier(buf));
    } else {
      throw std::runtime_error("Unexpected character \"" + std::string(1, ch) + "\" (in line " +
                                std::to_string(buf.line()) + ")");
    }
  }
}

}  // namespace bokasm
