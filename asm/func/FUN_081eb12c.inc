	push {r4, r5, r6, lr}
	movs r2, #0
	movs r1, #0x92
	lsls r1, r1, #4
	adds r5, r0, r1
	movs r6, #1
	adds r3, r0, #0
	adds r3, #0x63
	adds r4, r0, #0
	adds r4, #0x20
_081EB140:
	adds r1, r6, #0
	lsls r1, r2
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081EB150
	movs r0, #1
	b _081EB152
_081EB150:
	movs r0, #0
_081EB152:
	cmp r0, #0
	bne _081EB166
	strb r2, [r3]
	adds r1, r6, #0
	lsls r1, r2
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
	adds r0, r4, #0
	b _081EB172
_081EB166:
	adds r3, #0x48
	adds r4, #0x48
	adds r2, #1
	cmp r2, #0x1f
	ble _081EB140
	movs r0, #0
_081EB172:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
