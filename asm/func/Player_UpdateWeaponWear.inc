	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r3, r5, r0
	ldrh r2, [r3, #0x3e]
	cmp r2, #0
	ble _08064830
	movs r6, #0x40
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ands r6, r1
	cmp r6, #0
	beq _0806478A
	movs r0, #0
	strh r0, [r3, #0x3e]
	b _08064830
_0806478A:
	ldr r3, _080647C8 @ =0x00000A75
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #2
	bhi _08064826
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	beq _0806479E
	asrs r2, r2, #1
_0806479E:
	movs r0, #0xa7
	lsls r0, r0, #4
	adds r4, r5, r0
	ldr r1, [r4]
	movs r0, #1
	ldrsb r0, [r1, r0]
	cmp r0, #0
	ble _080647CC
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xc7
	bls _08064826
	ldr r1, [r4]
	ldrb r0, [r1, #1]
	subs r0, #1
	strb r0, [r1, #1]
	b _080647E6
	.align 2, 0
_080647C8: .4byte 0x00000A75
_080647CC:
	ldrb r3, [r1, #0x18]
	cmp r3, #0
	beq _080647FC
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	ldr r1, _080647F8 @ =0x07CF0000
	cmp r0, r1
	bls _08064826
	ldr r1, [r4]
	movs r0, #0
	strb r0, [r1, #0x18]
_080647E6:
	ldr r0, [r4]
	strh r6, [r0, #2]
	bl FUN_0809c4f4
	ldr r1, [r4]
	adds r0, r5, #0
	bl weapon_08064664
	b _08064826
	.align 2, 0
_080647F8: .4byte 0x07CF0000
_080647FC:
	ldrb r0, [r1, #0x14]
	cmp r0, #0
	beq _08064826
	ldrh r0, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	ldr r1, _08064838 @ =0x07CF0000
	cmp r0, r1
	bls _08064826
	ldr r1, [r4]
	movs r0, #0
	strb r0, [r1, #0x14]
	ldr r0, [r4]
	strh r3, [r0, #2]
	bl FUN_0809c4f4
	ldr r1, [r4]
	adds r0, r5, #0
	bl weapon_08064664
_08064826:
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1, #0x3e]
_08064830:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08064838: .4byte 0x07CF0000
