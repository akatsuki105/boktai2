	push {lr}
	cmp r0, #0
	beq _0822EC8A
	cmp r0, #1
	beq _0822EC94
_0822EC8A:
	ldr r1, _0822EC90 @ =0x0000529C
	b _0822EC96
	.align 2, 0
_0822EC90: .4byte 0x0000529C
_0822EC94:
	ldr r1, _0822ECB0 @ =0x0000539C
_0822EC96:
	ldr r0, _0822ECB4 @ =0x000092B3
	bl FUN_082310cc
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r1, _0822ECB8 @ =0x03004410
	ldr r2, _0822ECBC @ =0x04000010
	bl CpuSet
	pop {r0}
	bx r0
	.align 2, 0
_0822ECB0: .4byte 0x0000539C
_0822ECB4: .4byte 0x000092B3
_0822ECB8: .4byte 0x03004410
_0822ECBC: .4byte 0x04000010
