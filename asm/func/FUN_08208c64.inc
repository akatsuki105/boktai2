	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r4, #0
	adds r7, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08208C7A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
_08208C7A:
	adds r0, r6, #0
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _08208C9A
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	movs r1, #0x3c
	subs r1, r1, r0
	b _08208CA4
_08208C9A:
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	adds r1, r0, #0
_08208CA4:
	adds r0, r4, #0
	movs r2, #0x3c
	bl FUN_08208350
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08208CE2
	ands r5, r0
	cmp r5, #0
	beq _08208CD8
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	movs r1, #0x3c
	subs r1, r1, r0
	str r1, [r7, #0x1c]
	b _08208CE2
_08208CD8:
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	str r0, [r7, #0x1c]
_08208CE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
