#ifndef GUARD_ZOKTAI_INCBIN_H
#define GUARD_ZOKTAI_INCBIN_H

// https://gist.github.com/mmozeiko/ed9655cf50341553d282

#define STR2(x) #x
#define STR(x) STR2(x)

#define INCRODATA(section, file) \
  __asm__(".section " section    \
          "\n"                   \
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

#endif  // GUARD_ZOKTAI_INCBIN_H
