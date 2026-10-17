	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	ble _080D7BA4
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D7BA4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D7BA4
	cmp r0, #0x19
	beq _080D7BA4
	subs r5, #1
	cmp r5, #0
	beq _080D7B9C
	asrs r0, r5, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7B9C
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D7B9C:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_080D7BA4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
