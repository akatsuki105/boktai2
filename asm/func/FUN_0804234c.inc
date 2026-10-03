	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0804236E
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_0804236E:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0804240C
	adds r1, r4, #0
	adds r1, #0x61
	ldrb r2, [r1]
	ldrb r0, [r4, #0x1b]
	subs r0, r0, r2
	lsls r0, r0, #0x18
	asrs r3, r0, #0x18
	adds r6, r1, #0
	cmp r3, #8
	ble _080423AC
	lsls r0, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x14
	adds r0, r0, r1
	b _080423C6
_080423AC:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _080423BE
	lsls r0, r2, #0x18
	movs r1, #0xf8
	lsls r1, r1, #0x18
	adds r0, r0, r1
	b _080423C6
_080423BE:
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r3
	lsls r0, r0, #0x18
_080423C6:
	lsrs r2, r0, #0x18
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	strb r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
	movs r5, #1
	str r5, [sp]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	ldrb r0, [r6]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _0804240C
	strb r5, [r4, #7]
_0804240C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
