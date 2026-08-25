// Renders an AssembleResult as GNU-as source: each label becomes a plain
// "NAME:" line followed by its bytes as .byte directives. This is an
// intermediate/machine-generated file, not meant for humans to read, so no
// comments or other annotations are emitted.
#ifndef BOKASM_RENDER_H
#define BOKASM_RENDER_H

#include <string>

#include "assembler.h"

namespace bokasm {

std::string RenderAsm(const AssembleResult& result);

}  // namespace bokasm

#endif  // BOKASM_RENDER_H
