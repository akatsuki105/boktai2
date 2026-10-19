	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820723A
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_0820723A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820728E
	ldrh r4, [r5, #0x20]
	cmp r4, #0
	beq _0820725C
	cmp r4, #1
	beq _08207282
	b _0820728E
_0820725C:
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _0820728E
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #1
	movs r3, #1
	bl FUN_08041480
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	strh r4, [r6, #2]
	b _0820728E
_08207282:
	movs r1, #0
	strb r4, [r5, #7]
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	strh r1, [r6, #2]
_0820728E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
