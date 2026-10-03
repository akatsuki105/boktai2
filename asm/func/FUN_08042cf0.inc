	push {r4, r5, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r2, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08042D1E
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	movs r0, #0xf6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_08042D1E:
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
	beq _08042D46
	cmp r5, #7
	ble _08042D46
	movs r0, #1
	strb r0, [r4, #7]
_08042D46:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
