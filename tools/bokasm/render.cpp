#include "render.h"

#include <cstdio>
#include <sstream>

namespace bokasm {

namespace {

constexpr size_t kBytesPerLine = 16;

void EmitBytes(std::ostringstream& out, const std::vector<uint8_t>& bytes, size_t start, size_t end) {
  for (size_t i = start; i < end; i += kBytesPerLine) {
    size_t line_end = std::min(i + kBytesPerLine, end);
    out << "  .byte ";
    for (size_t j = i; j < line_end; j++) {
      if (j > i) out << ", ";
      char hex[8];
      std::snprintf(hex, sizeof(hex), "0x%02x", bytes[j]);
      out << hex;
    }
    out << "\n";
  }
}

}  // namespace

std::string RenderAsm(const AssembleResult& result) {
  std::ostringstream out;
  const std::vector<uint8_t>& bytes = result.bytes;
  const auto& labels = result.labels;

  size_t leading_end = labels.empty() ? bytes.size() : labels.front().second;
  EmitBytes(out, bytes, 0, leading_end);

  for (size_t i = 0; i < labels.size(); i++) {
    out << labels[i].first << ":\n";
    size_t start = labels[i].second;
    size_t end = (i + 1 < labels.size()) ? labels[i + 1].second : bytes.size();
    EmitBytes(out, bytes, start, end);
  }

  return out.str();
}

}  // namespace bokasm
