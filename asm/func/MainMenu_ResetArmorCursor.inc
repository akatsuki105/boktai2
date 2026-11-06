	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	adds r7, r1, #0
	ldr r0, _08096680 @ =0x00003AE8
	adds r6, r2, r0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08096688
	movs r0, #0
	strb r0, [r6]
	movs r4, #0
	ldr r0, _08096684 @ =0x00003AF0
	adds r7, r2, r0
	movs r5, #0xff
_0809665E:
	adds r2, r4, #1
	adds r1, r4, r7
	movs r3, #8
_08096664:
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r1, #4
	subs r3, #1
	cmp r3, #0
	bge _08096664
	adds r4, r2, #0
	cmp r4, #3
	ble _0809665E
	movs r0, #0
	strb r0, [r6, #8]
	b _08096732
	.align 2, 0
_08096680: .4byte 0x00003AE8
_08096684: .4byte 0x00003AF0
_08096688:
	strb r7, [r6]
	movs r4, #0
	ldr r0, _080966E4 @ =0x00003AF0
	adds r1, r2, r0
	adds r0, #0x20
	adds r0, r0, r2
	mov r8, r0
	ldr r0, _080966E8 @ =0x00003B13
	adds r0, r0, r2
	mov ip, r0
	adds r5, r1, #0
_0809669E:
	lsls r0, r4, #2
	movs r3, #3
	adds r2, r0, #3
	adds r0, r4, r5
	adds r0, #0xc
_080966A8:
	strb r2, [r0]
	subs r2, #1
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _080966A8
	adds r4, #1
	cmp r4, #3
	ble _0809669E
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	beq _080966EC
	movs r4, #0
	movs r2, #0x10
	adds r5, r1, #0
	adds r5, #0x10
_080966CA:
	movs r3, #3
	adds r0, r4, r5
	adds r0, #0xc
_080966D0:
	strb r2, [r0]
	subs r0, #4
	subs r3, #1
	cmp r3, #0
	bge _080966D0
	adds r4, #1
	cmp r4, #3
	ble _080966CA
	b _0809670C
	.align 2, 0
_080966E4: .4byte 0x00003AF0
_080966E8: .4byte 0x00003B13
_080966EC:
	movs r4, #0
	movs r5, #0xff
	adds r6, r1, #0
	adds r6, #0x10
_080966F4:
	adds r2, r4, r6
	movs r3, #3
_080966F8:
	ldrb r0, [r2]
	orrs r0, r5
	strb r0, [r2]
	adds r2, #4
	subs r3, #1
	cmp r3, #0
	bge _080966F8
	adds r4, #1
	cmp r4, #3
	ble _080966F4
_0809670C:
	movs r4, #0
	mov r2, r8
	movs r3, #0xff
_08096712:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #2
	ble _08096712
	movs r0, #0x20
	ands r0, r7
	cmp r0, #0
	beq _0809672C
	movs r0, #0x15
	b _0809672E
_0809672C:
	movs r0, #0xff
_0809672E:
	mov r1, ip
	strb r0, [r1]
_08096732:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
