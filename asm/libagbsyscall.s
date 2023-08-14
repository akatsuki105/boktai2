	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start CpuFastSet
CpuFastSet: @ 0x0824C1B4
	svc #0xc
	bx lr

	thumb_func_start CpuSet
CpuSet: @ 0x0824C1B8
	svc #0xb
	bx lr

	thumb_func_start Div
Div: @ 0x0824C1BC
	svc #6
	bx lr

	thumb_func_start DivArm
DivArm: @ 0x0824C1C0
	svc #7
	bx lr

	thumb_func_start Mod
Mod: @ 0x0824C1C4
	svc #6
	adds r0, r1, #0
	bx lr
	.align 2, 0

	thumb_func_start ModArm
ModArm: @ 0x0824C1CC
	svc #7
	adds r0, r1, #0
	bx lr
	.align 2, 0

	thumb_func_start LZ77UnCompReadNormalWrite8bit
LZ77UnCompReadNormalWrite8bit: @ 0x0824C1D4
	svc #0x11
	bx lr

	thumb_func_start RegisterRamReset
RegisterRamReset: @ 0x0824C1D8
	svc #1
	bx lr

	thumb_func_start SoundBias_0
SoundBias_0: @ 0x0824C1DC
	movs r0, #0
	svc #0x19
	bx lr

	thumb_func_start SoundBias_200
SoundBias_200: @ 0x0824C1E4
	movs r0, #1
	svc #0x19
	bx lr

	thumb_func_start Sqrt
Sqrt: @ 0x0824C1EC
	svc #8
	bx lr

	thumb_func_start VBlankIntrWait
VBlankIntrWait: @ 0x0824C1F0
	movs r2, #0
	svc #5
	bx lr
	.align 2, 0

	thumb_func_start FUN_0824c1f8
FUN_0824c1f8: @ 0x0824C1F8
	ldr r3, _0824C20C @ =0x04000208
	movs r2, #0
	strb r2, [r3]
	ldr r3, _0824C210 @ =0x03007FFA
	movs r2, #0
	strb r2, [r3]
	subs r3, #0xfa
	mov sp, r3
	svc #1
	svc #0
	.align 2, 0
_0824C20C: .4byte 0x04000208
_0824C210: .4byte 0x03007FFA
