	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r2, #0
	adds r2, r3, #0
	ldr r6, [sp, #0x18]
	movs r3, #0xae
	lsls r3, r3, #2
	adds r0, r4, r3
	lsls r1, r1, #2
	ldr r0, [r0]
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #1
	bne _080414B2
	ldrh r1, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	str r2, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080413b8
	b _080414F4
_080414B2:
	cmp r1, #2
	bne _080414CA
	ldrh r1, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	str r2, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0804135c
	b _080414F4
_080414CA:
	cmp r1, #3
	bne _080414E2
	ldrh r1, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	str r2, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080413fc
	b _080414F4
_080414E2:
	ldrh r1, [r0, #2]
	movs r3, #1
	ldrsb r3, [r0, r3]
	str r2, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08041460
_080414F4:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
