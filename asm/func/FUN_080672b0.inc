	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_08067068
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0806731C
	adds r0, r4, #0
	bl FUN_08066fd4
	adds r5, r0, #0
	bl FUN_080670d4
	ldr r2, _08067348 @ =0x00000446
	adds r0, r4, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _08067306
	subs r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _08067306
	movs r1, #1
_08067306:
	cmp r1, #0
	beq _08067314
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	muls r0, r5, r0
	asrs r5, r0, #6
_08067314:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08060aa4
_0806731C:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080670fc
	adds r0, r4, #0
	bl FUN_080609dc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08067348: .4byte 0x00000446
