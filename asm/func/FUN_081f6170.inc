	push {r4, r5, r6, lr}
	movs r5, #0
	adds r2, r0, #0
	adds r2, #0xfd
	adds r3, r0, #0
	movs r6, #0x92
	lsls r6, r6, #1
	movs r4, #5
_081F6180:
	movs r0, #0x81
	lsls r0, r0, #1
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081F6192
	subs r0, #1
	strh r0, [r1]
	b _081F61A4
_081F6192:
	cmp r5, #1
	bgt _081F61A4
	movs r0, #3
	strh r0, [r1]
	ldrb r1, [r2]
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	adds r5, #1
_081F61A4:
	adds r2, r2, r6
	adds r3, r3, r6
	subs r4, #1
	cmp r4, #0
	bge _081F6180
	pop {r4, r5, r6}
	pop {r0}
	bx r0
