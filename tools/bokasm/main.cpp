// CLI entry point. Default output is GNU-as source (see render.h); pass
// --bin to get raw bytecode instead. With no positional arguments, reads
// from stdin and writes to stdout. With one positional argument, it is
// INPUT_FILE and output goes to stdout. With two, the second is
// OUTPUT_FILE.
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "assembler.h"
#include "render.h"

namespace {

void WriteBytes(std::ostream& out, const std::vector<uint8_t>& bytes) {
  out.write(reinterpret_cast<const char*>(bytes.data()), static_cast<std::streamsize>(bytes.size()));
}

}  // namespace

int main(int argc, char** argv) {
  bool bin_mode = false;
  std::vector<std::string> positional;
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "--bin") {
      bin_mode = true;
    } else {
      positional.push_back(arg);
    }
  }

  if (positional.size() > 2) {
    std::cerr << "usage: bokasm [--bin] [INPUT_FILE [OUTPUT_FILE]]" << std::endl;
    return 1;
  }

  try {
    std::ifstream in_file;
    std::istream* in = &std::cin;
    if (!positional.empty()) {
      in_file.open(positional[0]);
      if (!in_file) {
        std::cerr << "bokasm: cannot open '" << positional[0] << "'" << std::endl;
        return 1;
      }
      in = &in_file;
    }

    bokasm::AssembleResult result = bokasm::Assemble(*in);

    std::ofstream out_file;
    std::ostream* out = &std::cout;
    if (positional.size() == 2) {
      out_file.open(positional[1], bin_mode ? std::ios::binary : std::ios::out);
      if (!out_file) {
        std::cerr << "bokasm: cannot open '" << positional[1] << "' for writing" << std::endl;
        return 1;
      }
      out = &out_file;
    }

    if (bin_mode) {
      WriteBytes(*out, result.bytes);
    } else {
      *out << bokasm::RenderAsm(result);
    }
  } catch (const std::exception& e) {
    std::cerr << "bokasm: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
