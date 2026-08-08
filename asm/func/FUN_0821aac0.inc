	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r6, #0
	movs r0, #0x97
	lsls r0, r0, #1
	adds r5, r4, r0
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	ble _0821AB0C
	movs r2, #0x94
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r7, #0
	ldrsh r2, [r5, r7]
	muls r0, r2, r0
	movs r3, #0x95
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r7, #0
	ldrsh r3, [r1, r7]
	movs r7, #0x96
	lsls r7, r7, #1
	adds r1, r4, r7
	movs r7, #0
	ldrsh r1, [r1, r7]
	subs r2, r1, r2
	muls r2, r3, r2
	adds r0, r0, r2
	bl Div
	adds r1, r0, #0
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	b _0821AB16
_0821AB0C:
	movs r1, #0x95
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
_0821AB16:
	movs r3, #0x92
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r1, r0
	lsls r0, r0, #8
	cmp r0, #0
	blt _0821AB2C
	asrs r0, r0, #6
	b _0821AB32
_0821AB2C:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0821AB32:
	adds r1, r0, #0
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r0, r4, r7
	ldr r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0821AB46
	asrs r0, r0, #8
	b _0821AB4C
_0821AB46:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0821AB4C:
	adds r2, r0, #0
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _0821AB60
	asrs r3, r0, #8
	b _0821AB66
_0821AB60:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r3, r0, #0
_0821AB66:
	movs r5, #0x86
	lsls r5, r5, #1
	adds r1, r4, r5
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	movs r7, #0x88
	lsls r7, r7, #1
	adds r2, r4, r7
	ldr r0, [r2]
	adds r0, r0, r3
	str r0, [r2]
	ldr r0, [r1]
	cmp r0, #0
	blt _0821AB88
	asrs r1, r0, #0x10
	b _0821AB8E
_0821AB88:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_0821AB8E:
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	subs r1, r0, r1
	movs r3, #0x88
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	cmp r0, #0
	blt _0821ABA8
	asrs r0, r0, #0x10
	b _0821ABAE
_0821ABA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_0821ABAE:
	movs r5, #0x8c
	lsls r5, r5, #1
	adds r3, r4, r5
	ldr r2, [r3]
	subs r2, r2, r0
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r0, r4, r7
	ldr r0, [r0]
	muls r1, r0, r1
	adds r5, #8
	adds r0, r4, r5
	ldr r0, [r0]
	muls r0, r2, r0
	adds r1, r1, r0
	cmp r1, #0
	bgt _0821ABEC
	subs r7, #0x10
	adds r1, r4, r7
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	lsls r0, r0, #0x10
	str r0, [r1]
	subs r5, #0x10
	adds r1, r4, r5
	ldr r0, [r3]
	lsls r0, r0, #0x10
	str r0, [r1]
	movs r6, #1
_0821ABEC:
	adds r0, r4, #0
	bl FUN_0821aa3c
	adds r0, r6, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
