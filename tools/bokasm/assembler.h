// Port of the encoding half of bokasm/asm.py.
#ifndef BOKASM_ASSEMBLER_H
#define BOKASM_ASSEMBLER_H

#include <cstdint>
#include <istream>
#include <string>
#include <utility>
#include <vector>

#include "bytecode.h"

namespace bokasm {

// Assembles a fully parsed instruction stream into bytecode. Container
// opcodes (block/expr/control/keyword/call) are written with a placeholder
// single-byte header and back-patched (with byte-array splicing, not a
// second pass) once their closing instruction is seen, so container
// lengths never need to be known up front.
class Assembler {
 public:
  explicit Assembler(std::vector<uint8_t>* buffer) : buffer_(buffer) {}

  void Write(const Instruction& instruction);

  // Raises if any container (block/expr/control/keyword/call) was left
  // unterminated.
  void Finish();

  // Label name -> byte offset, in declaration order. Populated by
  // OP_LABEL instructions, which otherwise emit no bytes.
  const std::vector<std::pair<std::string, size_t>>& labels() const { return labels_; }

 private:
  struct Container {
    Opcode opcode;
    size_t offset;
    bool nextkw_set = false;
  };

  void SetContainerSize(size_t p);
  void SetNextKeyword(size_t p);

  std::vector<uint8_t>* buffer_;
  std::vector<Container> container_stack_;
  std::vector<std::pair<std::string, size_t>> labels_;
};

struct AssembleResult {
  std::vector<uint8_t> bytes;
  // Label name -> byte offset into `bytes`, in declaration order.
  std::vector<std::pair<std::string, size_t>> labels;
};

// Runs the lex -> parse -> convert -> assemble pipeline over `in` and
// returns the resulting bytecode plus any label declarations.
AssembleResult Assemble(std::istream& in);

}  // namespace bokasm

#endif  // BOKASM_ASSEMBLER_H
