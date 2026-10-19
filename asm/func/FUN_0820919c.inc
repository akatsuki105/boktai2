	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x20
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0xe]
	strb r1, [r4, #7]
	ldr r2, [r4, #0x10]
	adds r0, r2, #1
	str r0, [r4, #0x10]
	ldrh r0, [r5, #6]
	cmp r0, #0
	bne _082091C0
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
_082091C0:
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _082091E6
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r3
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	ble _082091E6
	subs r1, #1
	str r1, [r5, #0x1c]
	adds r0, r4, #0
	movs r2, #0x3c
	bl FUN_08208350
_082091E6:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
