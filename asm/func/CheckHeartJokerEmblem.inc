	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x34
	bl CheckItemOwn
	cmp r0, #0
	beq _08064ADE
	movs r2, #0x80
	lsls r2, r2, #0x15
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08064ADE:
	movs r0, #0x37
	bl CheckItemOwn
	cmp r0, #0
	beq _08064AF8
	movs r2, #0x80
	lsls r2, r2, #0x16
	movs r0, #0xde
	lsls r0, r0, #2
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08064AF8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
