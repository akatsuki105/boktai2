	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x32
	ldrb r0, [r1]
	cmp r0, #0
	beq _0804C7DA
	movs r0, #0
	strb r0, [r1]
_0804C7DA:
	adds r0, r4, #0
	bl FUN_0804bc28
	adds r1, r4, #0
	adds r1, #0x27
	ldrb r2, [r1]
	adds r7, r1, #0
	cmp r2, #0
	beq _0804C87C
	adds r3, r4, #0
	adds r3, #0x24
	movs r6, #0
	ldrsb r6, [r3, r6]
	ldr r2, _0804C808 @ =0x030044E0
	ldrh r5, [r2, #2]
	movs r1, #0x40
	ands r1, r5
	cmp r1, #0
	beq _0804C80C
	ldrb r1, [r3]
	subs r1, #1
	b _0804C818
	.align 2, 0
_0804C808: .4byte 0x030044E0
_0804C80C:
	movs r1, #0x80
	ands r1, r5
	cmp r1, #0
	beq _0804C81A
	ldrb r1, [r3]
	adds r1, #1
_0804C818:
	strb r1, [r3]
_0804C81A:
	movs r1, #0
	ldrsb r1, [r3, r1]
	cmp r6, r1
	beq _0804C832
	cmp r1, #7
	ble _0804C82A
	movs r1, #7
	b _0804C830
_0804C82A:
	cmp r1, #0
	bge _0804C832
	movs r1, #0
_0804C830:
	strb r1, [r3]
_0804C832:
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	ldrb r5, [r7]
	ldrh r2, [r2, #2]
	movs r1, #1
	ands r1, r2
	cmp r1, #0
	beq _0804C87C
	cmp r3, r5
	bge _0804C87C
	adds r0, r4, #0
	adds r0, #0x28
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r0, _0804C884 @ =0x03005800
	ldr r0, [r0]
	lsls r1, r1, #5
	adds r0, r0, r1
	ldrh r0, [r0, #0x14]
	movs r1, #0
	bl rfu_LMAN_CHILD_connectParent
	adds r1, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0
	bne _0804C87C
	movs r0, #0xa
	strb r1, [r4, #0x1c]
	strh r0, [r4, #0x38]
	str r1, [r4, #0x44]
	adds r1, r4, #0
	adds r1, #0x32
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_0804C87C:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0804C884: .4byte 0x03005800
