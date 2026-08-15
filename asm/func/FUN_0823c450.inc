	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #0x54
	adds r0, r0, r6
	mov r8, r0
	ldrh r0, [r0]
	cmp r0, #1
	beq _0823C518
	cmp r0, #1
	bgt _0823C46E
	cmp r0, #0
	beq _0823C47A
	b _0823C610
_0823C46E:
	cmp r0, #2
	beq _0823C538
	cmp r0, #3
	bne _0823C478
	b _0823C5A4
_0823C478:
	b _0823C610
_0823C47A:
	ldr r0, _0823C4C4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0823C4D0
	ldr r0, _0823C4C8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0823C492
	b _0823C610
_0823C492:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bge _0823C49C
	b _0823C610
_0823C49C:
	ldr r1, _0823C4CC @ =0x03002BE0
	lsls r0, r0, #2
	adds r2, r0, r1
	ldr r0, [r2]
	cmp r0, #0
	bne _0823C4AA
	b _0823C610
_0823C4AA:
	ldrh r1, [r0, #0x2c]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	ldr r0, [r2]
	ldrh r0, [r0, #0x2e]
	adds r0, #0x96
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	ldr r0, [r2]
	ldrh r1, [r0, #0x30]
	b _0823C50C
	.align 2, 0
_0823C4C4: .4byte 0x030047A4
_0823C4C8: .4byte 0x03002C68
_0823C4CC: .4byte 0x03002BE0
_0823C4D0:
	ldr r0, _0823C4EC @ =0x03003540
	movs r3, #0x12
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bne _0823C4F4
	ldr r0, _0823C4F0 @ =0x030046A0
	ldr r1, [r0]
	ldrh r2, [r1, #0x30]
	adds r0, r6, #0
	adds r0, #0x58
	strh r2, [r0]
	ldrh r0, [r1, #0x32]
	adds r0, #0x96
	b _0823C504
	.align 2, 0
_0823C4EC: .4byte 0x03003540
_0823C4F0: .4byte 0x030046A0
_0823C4F4:
	ldr r0, _0823C514 @ =0x030046A0
	ldr r1, [r0]
	ldrh r2, [r1, #0x30]
	adds r0, r6, #0
	adds r0, #0x58
	strh r2, [r0]
	ldrh r0, [r1, #0x32]
	subs r0, #0x96
_0823C504:
	adds r2, r6, #0
	adds r2, #0x5a
	strh r0, [r2]
	ldrh r1, [r1, #0x34]
_0823C50C:
	adds r0, r6, #0
	adds r0, #0x5c
	strh r1, [r0]
	b _0823C610
	.align 2, 0
_0823C514: .4byte 0x030046A0
_0823C518:
	adds r0, r6, #0
	adds r0, #0x60
	ldrh r1, [r0]
	subs r0, #8
	strh r1, [r0]
	adds r0, #0xa
	ldrh r0, [r0]
	adds r1, r6, #0
	adds r1, #0x5a
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x64
	ldrh r1, [r0]
	subs r0, #8
	strh r1, [r0]
	b _0823C610
_0823C538:
	adds r4, r6, #0
	adds r4, #0x58
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r5, r6, #0
	adds r5, #0x56
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x60
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	adds r4, #2
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x62
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	adds r4, #2
	movs r0, #0
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x64
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0823C610
	movs r0, #1
	b _0823C60C
_0823C5A4:
	adds r5, r6, #0
	adds r5, #0x58
	movs r3, #0
	ldrsh r2, [r5, r3]
	adds r7, r6, #0
	adds r7, #0x56
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r4, _0823C61C @ =0x030046A0
	ldr r2, [r4]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r0, #0
	ldrsh r2, [r5, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r2, [r4]
	movs r3, #0x32
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	adds r0, #0x96
	bl Div
	strh r0, [r5]
	adds r5, #2
	movs r0, #0
	ldrsh r2, [r5, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r2, [r4]
	movs r3, #0x34
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r5]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0823C610
	movs r0, #0
_0823C60C:
	mov r1, r8
	strh r0, [r1]
_0823C610:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823C61C: .4byte 0x030046A0
