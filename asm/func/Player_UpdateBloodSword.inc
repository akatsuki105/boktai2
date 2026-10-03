	push {r4, lr}
	sub sp, #8
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _080640D0
	movs r1, #4
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080640D0
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r2, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08064098
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #1
	bls _080640D0
	subs r3, #2
	adds r1, r2, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080640D0
_08064098:
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r3, r2, r4
	ldr r1, _080640D8 @ =0x00000366
	adds r0, r2, r1
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	bhs _080640D0
	adds r0, r1, #1
	strh r0, [r3]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r2, r3
	adds r3, r2, #0
	adds r3, #0x2c
	movs r4, #0x97
	lsls r4, r4, #4
	adds r1, r2, r4
	str r1, [sp]
	adds r4, #8
	adds r1, r2, r4
	ldrb r1, [r1]
	str r1, [sp, #4]
	movs r1, #1
	movs r2, #1
	bl FUN_0805fe7c
_080640D0:
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080640D8: .4byte 0x00000366
