	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r4, r2, #0
	adds r6, r3, #0
	movs r1, #0
	strb r1, [r5, #0xc]
	movs r1, #1
	strb r1, [r5, #0xd]
	bl FUN_082381e8
	strb r0, [r5, #0xe]
	strb r6, [r5, #0xf]
	strb r0, [r5, #8]
	movs r0, #0xf0
	lsls r0, r0, #1
	strh r0, [r5, #0xa]
	adds r0, r6, #4
	strb r0, [r5, #9]
	adds r1, r5, #0
	adds r1, #0x10
	cmp r6, #0
	ble _0823828C
	adds r3, r6, #0
_0823827E:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r1, #1
	adds r4, #1
	subs r3, #1
	cmp r3, #0
	bne _0823827E
_0823828C:
	adds r0, r5, #0
	bl FUN_08238228
	ldrb r0, [r5, #9]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
