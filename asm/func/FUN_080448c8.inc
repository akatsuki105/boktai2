	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _080448EA
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_080448EA:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08044944
	ldrb r2, [r5, #0x1b]
	adds r6, r5, #0
	adds r6, #0x61
	movs r4, #0
	strb r2, [r6]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	ldrb r0, [r6]
	ldrb r1, [r5, #0x1b]
	cmp r0, r1
	bne _08044944
	movs r0, #1
	strb r0, [r5, #7]
_08044944:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
