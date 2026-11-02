	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldr r0, _0807F56C @ =0x03002BF8
	ldr r1, [r0]
	adds r5, r0, #0
	cmp r1, #0
	bne _0807F570
	movs r0, #0
	b _0807F590
	.align 2, 0
_0807F56C: .4byte 0x03002BF8
_0807F570:
	str r4, [r3]
	str r2, [r3, #8]
	ldr r0, [r1, #0x18]
	cmp r0, #0
	beq _0807F584
_0807F57A:
	cmp r0, r3
	beq _0807F58E
	ldr r0, [r0, #0xc]
	cmp r0, #0
	bne _0807F57A
_0807F584:
	ldr r0, [r5]
	ldr r0, [r0, #0x18]
	str r0, [r3, #0xc]
	ldr r0, [r5]
	str r3, [r0, #0x18]
_0807F58E:
	movs r0, #1
_0807F590:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
