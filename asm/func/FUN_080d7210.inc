	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r5, r4, r3
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7238
	adds r0, r4, #0
	bl FUN_080ced90
	adds r2, r0, #0
_080D7238:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7248
	movs r2, #0x18
	b _080D72A0
_080D7248:
	cmp r2, #0x18
	beq _080D72A0
	cmp r2, #0x14
	beq _080D72A0
	cmp r2, #0x13
	beq _080D72A0
	cmp r2, #0x17
	beq _080D72A0
	cmp r2, #4
	beq _080D72A0
	cmp r2, #0xd
	beq _080D72A0
	ldr r2, [r5]
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7280
	adds r0, r4, #0
	adds r0, #0x24
	bl MapItemManager_TryOpen
	lsls r0, r0, #0x18
	movs r2, #4
	cmp r0, #0
	beq _080D72A0
_080D727C:
	movs r2, #0
	b _080D72A0
_080D7280:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D727C
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D727C
	movs r2, #1
_080D72A0:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1
