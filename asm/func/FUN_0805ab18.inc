	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805AB4E
	movs r4, #0
	strb r4, [r5]
	adds r2, r5, #0
	adds r2, #0x98
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r5, #0
	bl FUN_0805a8d0
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r6, #0x20]
	str r4, [sp]
	movs r2, #4
	movs r3, #0
	bl AuxAnim_SetAnim
_0805AB4E:
	ldrb r0, [r5, #4]
	cmp r0, #0
	beq _0805AB60
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_0805a6ec
	b _0805AB66
_0805AB60:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
_0805AB66:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
