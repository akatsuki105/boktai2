	push {r4, r5, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r2, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820605A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bhi _0820604A
	movs r0, #2
	strb r0, [r4, #0x19]
_0820604A:
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_0820605A:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	cmp r5, #8
	ble _0820606C
	movs r0, #1
	strb r0, [r4, #7]
_0820606C:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
