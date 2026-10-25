	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r1, #0
	adds r5, r6, #0
	adds r5, #0x20
	movs r0, #0x64
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _08208A22
	movs r4, #0
	strb r4, [r6, #9]
	strb r4, [r6, #7]
	movs r0, #0x40
	strb r0, [r6, #0x1b]
	adds r1, #0x61
	strb r0, [r1]
	movs r0, #5
	strb r0, [r6, #0x1a]
	movs r0, #2
	strb r0, [r6, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
	strh r4, [r5, #0xc]
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r5, #0x10]
	ldrh r0, [r1, #2]
	strh r0, [r5, #0x12]
	ldrh r0, [r1, #4]
	strh r0, [r5, #0x14]
	adds r0, r6, #0
	adds r0, #0x56
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5, #0x12]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	rsbs r0, r0, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	movs r1, #0xa
	bl Mod
	cmp r0, #4
	ble _08208A18
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r0, #1
	b _08208A20
_08208A18:
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
_08208A20:
	strh r0, [r5, #0xe]
_08208A22:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08208A3A
	b _08208B42
_08208A3A:
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r6, #0xe]
	movs r7, #0
	orrs r0, r1
	strh r0, [r6, #0xe]
	ldrh r0, [r5, #4]
	cmp r0, #1
	beq _08208A78
	cmp r0, #1
	bgt _08208A56
	cmp r0, #0
	beq _08208A5C
	b _08208B42
_08208A56:
	cmp r0, #2
	beq _08208B16
	b _08208B42
_08208A5C:
	adds r4, r6, #0
	adds r4, #0x20
	strh r7, [r4, #6]
	adds r0, r6, #0
	adds r0, #0xd0
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _08208B42
	movs r0, #1
	strh r0, [r4, #4]
	strh r0, [r4, #6]
	str r7, [r4, #8]
	b _08208B42
_08208A78:
	adds r0, r6, #0
	adds r0, #0x20
	ldrh r1, [r0, #6]
	strh r7, [r0, #6]
	adds r7, r0, #0
	cmp r1, #0
	beq _08208A96
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208A96:
	adds r0, r6, #0
	adds r0, #0x54
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5, #0x10]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r4, [r0, r2]
	ldrh r0, [r5, #0x14]
	subs r4, r4, r0
	ldr r0, [r5, #8]
	muls r0, r1, r0
	ldrh r1, [r5, #0xe]
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	mov r0, r8
	strh r1, [r0]
	ldr r0, [r5, #8]
	muls r0, r4, r0
	ldrh r1, [r5, #0xe]
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	mov r2, r8
	strh r1, [r2, #4]
	ldr r1, [r5, #8]
	rsbs r0, r1, #0
	muls r0, r1, r0
	cmp r0, #0
	blt _08208AE0
	asrs r2, r0, #1
	b _08208AE6
_08208AE0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r2, r0, #0
_08208AE6:
	movs r0, #0xc
	ldrsh r1, [r5, r0]
	ldr r0, [r5, #8]
	muls r0, r1, r0
	ldrh r1, [r5, #0x12]
	adds r0, r0, r1
	adds r0, r0, r2
	mov r2, r8
	strh r0, [r2, #2]
	ldr r0, [r5, #8]
	ldrh r5, [r5, #0xe]
	cmp r0, r5
	blo _08208B42
	adds r0, r6, #0
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r2, #2]
	movs r0, #2
	strh r0, [r7, #4]
	movs r0, #1
	strh r0, [r7, #6]
	movs r0, #0
	str r0, [r7, #8]
	b _08208B42
_08208B16:
	adds r0, r6, #0
	adds r0, #0x20
	ldrh r1, [r0, #6]
	strh r7, [r0, #6]
	cmp r1, #0
	beq _08208B32
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #9
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208B32:
	adds r0, r6, #0
	adds r0, #0xd0
	bl SpriteHolder_IsAnimEnded
	cmp r0, #0
	beq _08208B42
	movs r0, #1
	strb r0, [r6, #7]
_08208B42:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
