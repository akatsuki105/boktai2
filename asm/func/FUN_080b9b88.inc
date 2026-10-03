	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #1
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9BC4
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0xc
	movs r0, #0x2c
	adds r0, r0, r5
	mov r8, r0
	adds r7, r4, #0
	movs r6, #0xff
_080B9BAA:
	adds r1, r3, r7
	movs r2, #3
_080B9BAE:
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9BAE
	adds r3, #1
	cmp r3, #3
	ble _080B9BAA
	b _080B9BEE
_080B9BC4:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0xc
	movs r1, #0x2c
	adds r1, r1, r5
	mov r8, r1
	adds r6, r4, #0
_080B9BD2:
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #3
	adds r0, r3, r6
	adds r0, #0xc
_080B9BDC:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9BDC
	adds r3, #1
	cmp r3, #3
	ble _080B9BD2
_080B9BEE:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9C1E
	movs r3, #0
	movs r6, #0xff
	adds r7, r4, #0
	adds r7, #0x10
_080B9C02:
	adds r4, r3, #1
	adds r1, r3, r7
	movs r2, #3
_080B9C08:
	ldrb r0, [r1]
	orrs r0, r6
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C08
	adds r3, r4, #0
	cmp r3, #3
	ble _080B9C02
	b _080B9CDC
_080B9C1E:
	ldrb r1, [r5]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B9C9E
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9C54
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0x10
_080B9C3A:
	adds r4, r3, #1
	adds r1, r3, r6
	movs r2, #3
_080B9C40:
	ldrb r0, [r5, #6]
	strb r0, [r1]
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C40
	adds r3, r4, #0
	cmp r3, #3
	ble _080B9C3A
	b _080B9CDC
_080B9C54:
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xf
	movs r0, #0xe
	adds r0, r0, r5
	mov ip, r0
	adds r7, r4, #0
	adds r7, #0x10
_080B9C64:
	adds r4, r3, #1
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #0
	adds r1, #0x13
	adds r0, r3, r7
	adds r0, #0xc
_080B9C72:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C72
	adds r3, r4, #0
	cmp r3, #2
	ble _080B9C64
	mov r3, ip
	adds r3, #0x10
	adds r1, r6, #0
	adds r1, #0x10
	movs r2, #3
_080B9C8E:
	ldrb r0, [r3]
	strb r0, [r1]
	adds r3, #4
	adds r1, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9C8E
	b _080B9CDC
_080B9C9E:
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xf
	adds r7, r4, #0
	adds r7, #0x10
_080B9CA8:
	adds r4, r3, #1
	lsls r0, r3, #2
	movs r2, #3
	adds r1, r0, #0
	adds r1, #0x13
	adds r0, r3, r7
	adds r0, #0xc
_080B9CB6:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9CB6
	adds r3, r4, #0
	cmp r3, #2
	ble _080B9CA8
	movs r2, #3
	movs r1, #0x1f
	adds r0, r6, #0
	adds r0, #0x1c
_080B9CD0:
	strb r1, [r0]
	subs r1, #1
	subs r0, #4
	subs r2, #1
	cmp r2, #0
	bge _080B9CD0
_080B9CDC:
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D24
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D0A
	movs r3, #0
	mov r2, r8
	movs r4, #0xff
_080B9CFA:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r4
	strb r0, [r1]
	adds r3, #1
	cmp r3, #3
	ble _080B9CFA
	b _080B9D8A
_080B9D0A:
	movs r3, #0
	adds r4, r5, #0
	adds r4, #0x2f
	mov r2, r8
	movs r5, #0xff
_080B9D14:
	adds r1, r2, r3
	ldrb r0, [r1]
	orrs r0, r5
	strb r0, [r1]
	adds r3, #1
	cmp r3, #2
	ble _080B9D14
	b _080B9D4E
_080B9D24:
	ldrb r0, [r5]
	cmp r0, #1
	bne _080B9D54
	adds r4, r5, #0
	adds r4, #0x2f
	mov r1, r8
	movs r2, #0x22
	adds r0, r1, #2
_080B9D34:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _080B9D34
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D4E
	movs r0, #0x22
	strb r0, [r4]
	b _080B9D8A
_080B9D4E:
	movs r0, #0x21
	strb r0, [r4]
	b _080B9D8A
_080B9D54:
	movs r0, #0x22
	mov r1, r8
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x2d
	movs r0, #0xff
	strb r0, [r1]
	adds r1, #1
	movs r0, #1
	rsbs r0, r0, #0
	adds r4, r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080b9da0
	cmp r0, #0
	beq _080B9D82
	adds r1, r5, #0
	adds r1, #0x2f
	ldrb r0, [r1]
	orrs r0, r4
	b _080B9D88
_080B9D82:
	adds r1, r5, #0
	adds r1, #0x2f
	movs r0, #0x21
_080B9D88:
	strb r0, [r1]
_080B9D8A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
