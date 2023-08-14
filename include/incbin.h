#ifndef GUARD_ZOKTAI_INCBIN_H
#define GUARD_ZOKTAI_INCBIN_H

// https://gist.github.com/mmozeiko/ed9655cf50341553d282

#define STR2(x) #x
#define STR(x) STR2(x)

#define INC4BPP(name)      \
  __asm__(                 \
      ".section .rodata\n" \
      ".incbin \"" name    \
      ".4bpp\"\n"          \
      ".incbin \"" name ".gbapal\"\n");

#define INCLZ(name)        \
  __asm__(                 \
      ".section .rodata\n" \
      ".incbin \"" name    \
      ".lz\"\n"            \
      ".incbin \"" name ".lz.gbapal\"\n");

#define INCBIN(section, file) \
  __asm__(".section " section \
          "\n"                \
          ".incbin \"" file "\"\n");

#define INCBIN8(name, file)      \
  __asm__(".section .rodata\n" \
            ".global " STR(name) "\n" \
            STR(name) ":\n" \
            ".incbin \"" file "\"\n" \
    ); \
  extern const u8* name;

#define INCBIN16(name, file)     \
  __asm__(".section .rodata\n" \
            ".global " STR(name) "\n" \
            ".balign 2\n" \
            STR(name) ":\n" \
            ".incbin \"" file "\"\n" \
    ); \
  extern const u16* name;

#define INCBINCODE(file) \
  __asm__(               \
      ".section .text\n" \
      ".balign 4, 0\n"   \
      ".incbin \"" file "\"\n");

#define INCASM(file) \
  asm(".section .text\n\
  .include \"" file  \
      "\"\n\
          .align 2, 0\n    \
 .syntax divided\n");

#define INCDATA(file) \
  asm(".section .rodata\n\
  .include \"" file   \
      "\"\n\
 .syntax divided\n");

#define INCCODE(file) \
  asm(".syntax unified\n\
  .include \"" file   \
      "\"\n\
    .align 2, 0\n    \
 .syntax divided\n");

#endif  // GUARD_ZOKTAI_INCBIN_H
