	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r2, #0
	movs r1, #0x20
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F4752
	adds r5, r6, #0
	adds r5, #0x1c
	adds r4, #0x42
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_081f4a08
	ldrb r1, [r4]
	adds r0, r5, #0
	bl FUN_081f4a08
	adds r2, r6, #0
	adds r2, #0x58
	ldrh r0, [r2, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r2, #0x50
	ldrh r0, [r2, #6]
	orrs r1, r0
	strh r1, [r2, #6]
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #3
	strb r0, [r1]
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_081F4752:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
