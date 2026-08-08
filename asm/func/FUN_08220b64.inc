	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #1
	movs r1, #0xe3
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r1, [r4]
	ands r0, r1
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r4]
	cmp r0, #0
	beq _08220B94
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r1, #0x17
	movs r2, #1
	movs r3, #1
	bl FUN_0821c400
_08220B94:
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08220BA6
	cmp r0, #0x63
	beq _08220BDC
	b _08220BE6
_08220BA6:
	movs r2, #2
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, _08220BD8 @ =0x000002D9
	adds r0, r5, r1
	ldrb r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _08220BE6
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #1
	bl FUN_08022488
	adds r0, r5, #0
	movs r1, #0x10
	movs r2, #1
	bl FUN_08221268
	b _08220BE6
	.align 2, 0
_08220BD8: .4byte 0x000002D9
_08220BDC:
	ldr r0, [r4]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
_08220BE6:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
