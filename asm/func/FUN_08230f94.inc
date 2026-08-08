	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	bl FUN_08230e88
	ldr r1, _08230FBC @ =0x03000740
	ldr r1, [r1]
	movs r2, #1
	subs r2, r2, r1
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #4
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r5, r0, r1
	adds r1, r5, #0
	adds r1, #8
	movs r3, #0
	b _08230FF2
	.align 2, 0
_08230FBC: .4byte 0x03000740
_08230FC0:
	ldrh r0, [r1]
	cmp r0, r6
	bne _08230FEE
	str r1, [r4]
	adds r1, #8
	adds r3, #1
	movs r4, #1
	cmp r3, r2
	bge _08230FEA
	ldrh r0, [r1]
	cmp r0, r6
	bne _08230FEA
	ldr r2, [r5]
_08230FDA:
	adds r3, #1
	adds r4, #1
	adds r1, #8
	cmp r3, r2
	bge _08230FEA
	ldrh r0, [r1]
	cmp r0, r6
	beq _08230FDA
_08230FEA:
	adds r0, r4, #0
	b _08230FFA
_08230FEE:
	adds r3, #1
	adds r1, #8
_08230FF2:
	ldr r2, [r5]
	cmp r3, r2
	blt _08230FC0
	movs r0, #0
_08230FFA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
