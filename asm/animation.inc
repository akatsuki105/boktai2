#ifndef GUARD_BOKTAI_ANIMATION_INC
#define GUARD_BOKTAI_ANIMATION_INC

	.macro animation variant_count, cmd_idx, cmd_count
    .byte \variant_count, \cmd_count
    .2byte 4 + (ANIM_COUNT << 2) + (\cmd_idx << 1)
	.endm

	.macro animcmd spriteidx, duration, xflip=0, yflip=0
    .2byte ((\spriteidx << 6) | (\yflip << 5) | (\xflip << 4) | \duration)
	.endm

	.macro animcmd_end
    .4byte 0x0
	.endm

#endif @ GUARD_BOKTAI_ANIMATION_INC
