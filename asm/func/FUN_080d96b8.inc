	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r1, #4
	adds r0, #0x32
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D96CC
	movs r0, #1
	b _080D96CE
_080D96CC:
	movs r0, #0
_080D96CE:
	adds r5, r0, #0
	cmp r5, #0
	bne _080D9750
	ldr r0, [r3, #0x48]
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r4, r0, #0
	cmp r1, #0
	bgt _080D96FA
	movs r0, #0x14
	strh r0, [r3, #0x3c]
	adds r2, r3, #0
	adds r2, #0x32
	ldrb r1, [r2]
	movs r0, #5
	orrs r0, r1
	strb r0, [r2]
	adds r1, r3, #0
	adds r1, #0x2c
	movs r0, #4
	strb r0, [r1]
	b _080D9750
_080D96FA:
	movs r2, #4
	movs r6, #0
	ldrsh r1, [r4, r6]
	movs r6, #0x3e
	ldrsh r0, [r3, r6]
	lsls r0, r0, #2
	movs r6, #0x32
	adds r6, r6, r3
	mov ip, r6
	adds r6, r3, #0
	adds r6, #0x2e
	cmp r1, r0
	blt _080D971C
	adds r0, r3, #0
	adds r0, #0x2c
	strb r5, [r0]
	b _080D973A
_080D971C:
	subs r2, #1
	cmp r2, #0
	ble _080D973A
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r5, #0x3e
	ldrsh r1, [r3, r5]
	muls r1, r2, r1
	cmp r0, r1
	blt _080D971C
	movs r0, #4
	subs r0, r0, r2
	adds r1, r3, #0
	adds r1, #0x2c
	strb r0, [r1]
_080D973A:
	movs r0, #0
	strh r0, [r3, #0x3c]
	subs r0, #6
	mov r2, ip
	ldrb r1, [r2]
	ands r0, r1
	strb r0, [r2]
	ldrb r1, [r6]
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r6]
_080D9750:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
