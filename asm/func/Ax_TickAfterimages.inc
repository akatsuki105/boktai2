	push {r4, r5, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _0819F3C8 @ =0x0000073C
	adds r2, r0, r1
	adds r3, r0, #0
	movs r5, #0xf3
	lsls r5, r5, #3
	movs r4, #3
_0819F39E:
	adds r1, r3, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _0819F3B8
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0819F3B8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_0819F3B8:
	adds r2, #0x60
	adds r3, #0x60
	subs r4, #1
	cmp r4, #0
	bge _0819F39E
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819F3C8: .4byte 0x0000073C
