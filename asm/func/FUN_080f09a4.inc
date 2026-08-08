	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080F09D8
	movs r5, #1
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0]
	ands r5, r1
	cmp r5, #0
	bne _080F09D8
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _080F09D8
	adds r0, r4, #0
	bl FUN_080ee738
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_080F09D8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
