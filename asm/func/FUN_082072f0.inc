	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820731A
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #9
	movs r2, #1
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_0820731A:
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r5, #0xe]
	movs r7, #0
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08207382
	ldrh r0, [r6, #2]
	adds r0, #1
	strh r0, [r6, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x45
	bls _08207372
	strh r7, [r6, #2]
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x5c
	str r7, [sp]
	str r7, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #2
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
_08207372:
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08207382
	movs r0, #1
	strb r0, [r5, #7]
_08207382:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
