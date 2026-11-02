	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r3, #0
	adds r0, #0xc9
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #1
	cmp r0, #1
	bhi _08203C98
	movs r3, #0
_08203C98:
	movs r0, #0
	cmp r1, #1
	bls _08203CA0
	movs r0, #1
_08203CA0:
	ldr r1, [r4, #0x18]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	orrs r0, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	bl AuxAnim_SetAnim
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
