	push {lr}
	adds r3, r0, #0
	ldr r0, _0807F5B0 @ =0x03002BF8
	ldr r2, [r0]
	cmp r2, #0
	beq _0807F5C6
	ldr r1, [r2, #0x18]
	cmp r1, r3
	bne _0807F5C0
	ldr r0, [r1, #0xc]
	str r0, [r2, #0x18]
	b _0807F5C6
	.align 2, 0
_0807F5B0: .4byte 0x03002BF8
_0807F5B4:
	ldr r0, [r0, #0xc]
	str r0, [r1, #0xc]
	b _0807F5C6
_0807F5BA:
	cmp r0, r3
	beq _0807F5B4
	ldr r1, [r1, #0xc]
_0807F5C0:
	ldr r0, [r1, #0xc]
	cmp r0, #0
	bne _0807F5BA
_0807F5C6:
	pop {r0}
	bx r0
	.align 2, 0
