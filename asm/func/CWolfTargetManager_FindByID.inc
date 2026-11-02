	push {lr}
	adds r3, r0, #0
	ldr r0, _0807F4A0 @ =0x03002BF8
	ldr r0, [r0]
	cmp r0, #0
	beq _0807F4A4
	ldr r1, [r0, #0x18]
	cmp r1, #0
	beq _0807F4A4
	ldr r0, [r1]
	ldrh r0, [r0]
	movs r2, #1
_0807F490:
	cmp r0, r3
	bne _0807F490
	ldr r0, [r1, #4]
	ands r0, r2
	cmp r0, #0
	bne _0807F4A4
	adds r0, r1, #0
	b _0807F4A6
	.align 2, 0
_0807F4A0: .4byte 0x03002BF8
_0807F4A4:
	movs r0, #0
_0807F4A6:
	pop {r1}
	bx r1
	.align 2, 0
