	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	strb r6, [r0]
	movs r4, #0
	adds r1, r0, #0
	adds r1, #8
	movs r2, #0x28
	adds r2, r2, r0
	mov ip, r2
	adds r7, r0, #0
	adds r7, #0x2b
_080916E6:
	lsls r0, r4, #2
	movs r3, #3
	adds r2, r0, #3
	adds r0, r4, r1
	adds r0, #0xc
_080916F0:
	strb r2, [r0]
	subs r2, #1
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _080916F0
	adds r4, #1
	cmp r4, #3
	ble _080916E6
	movs r0, #1
	ands r0, r6
	cmp r0, #0
	beq _0809172A
	movs r4, #0
	movs r2, #0x10
	adds r5, r1, #0
	adds r5, #0x10
_08091712:
	movs r3, #3
	adds r0, r4, r5
	adds r0, #0xc
_08091718:
	strb r2, [r0]
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _08091718
	adds r4, #1
	cmp r4, #3
	ble _08091712
	b _08091748
_0809172A:
	movs r4, #0
	movs r5, #0xff
	adds r1, #0x10
_08091730:
	adds r2, r4, r1
	movs r3, #3
_08091734:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _08091734
	adds r4, #1
	cmp r4, #3
	ble _08091730
_08091748:
	movs r4, #0
	mov r2, ip
	movs r3, #0xff
_0809174E:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #2
	ble _0809174E
	movs r0, #0x20
	ands r0, r6
	cmp r0, #0
	beq _08091768
	movs r0, #0x15
	b _0809176A
_08091768:
	movs r0, #0xff
_0809176A:
	strb r0, [r7]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
