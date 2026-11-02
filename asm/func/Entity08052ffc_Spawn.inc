	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r2, #0
	cmp r4, #0
	beq _08053086
	lsls r0, r1, #6
	adds r0, #0x34
	adds r2, r4, r0
	adds r4, r2, #0
	adds r4, #0x14
	movs r0, #0
	strb r5, [r2]
	str r0, [r2, #4]
	strh r1, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #8]
	ldr r0, [r2, #0x14]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x14]
	ldrb r0, [r2]
	cmp r0, #0
	bne _08053070
	str r0, [r2, #0x10]
	b _08053076
_08053070:
	cmp r0, #1
	bne _08053076
	str r3, [r2, #0x10]
_08053076:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	movs r0, #1
	strb r0, [r2, #1]
_08053086:
	pop {r4, r5}
	pop {r0}
	bx r0
