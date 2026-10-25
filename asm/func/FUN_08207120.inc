	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08207142
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_08207142:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08207168
	adds r0, r4, #0
	adds r0, #0xd0
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _08207168
	movs r0, #1
	strb r0, [r4, #7]
_08207168:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
