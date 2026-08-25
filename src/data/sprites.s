.include "asm/macros.inc"

.balign 4, 0
.section .rodata

.global gParticlesDirectory
gParticlesDirectory: @ 0x08A2011C
  @ ./tmp/bin.sh ./baserom.gba 0x08a2011c 0x08a22900 ./data/gParticlesDirectory.bin
  .incbin "data/gParticlesDirectory.bin"

.global gActorSpritesDirectory
gActorSpritesDirectory: @ 0x08A22900
  @ ./tmp/bin.sh ./baserom.gba 0x08a22900 0x08b79944 ./data/gActorSpritesDirectory.bin
  .incbin "data/gActorSpritesDirectory.bin"

.global gSpriteSetsDirectory
gSpriteSetsDirectory: @ 0x08B79944
  @ ./tmp/bin.sh ./baserom.gba 0x08b79944 0x08CB9228 ./data/gSpriteSetsDirectory.bin
  .incbin "data/gSpriteSetsDirectory.bin"

.global gSpriteSetPlttsDirectory
gSpriteSetPlttsDirectory: @ 0x08CB9228
  @ ./tmp/bin.sh ./baserom.gba 0x08CB9228 0x08cbf248 ./data/gSpriteSetPlttsDirectory.bin
  .incbin "data/gSpriteSetPlttsDirectory.bin"

