	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _082072C2
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_082072C2:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082072E8
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082072E8
	movs r0, #1
	strb r0, [r5, #7]
_082072E8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
