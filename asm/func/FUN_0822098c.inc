	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r4, r3, r0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r2, _082209C8 @ =0x00010010
	adds r1, r3, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	bne _082209C2
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
_082209C2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082209C8: .4byte 0x00010010
