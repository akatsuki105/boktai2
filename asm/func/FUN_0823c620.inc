	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r0, #0x68
	ldrh r0, [r0]
	cmp r0, #7
	bls _0823C632
	b _0823C918
_0823C632:
	lsls r0, r0, #2
	ldr r1, _0823C63C @ =_0823C640
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0823C63C: .4byte _0823C640
_0823C640: @ jump table
	.4byte _0823C660 @ case 0
	.4byte _0823C698 @ case 1
	.4byte _0823C6B8 @ case 2
	.4byte _0823C72C @ case 3
	.4byte _0823C76C @ case 4
	.4byte _0823C814 @ case 5
	.4byte _0823C888 @ case 6
	.4byte _0823C8FC @ case 7
_0823C660:
	ldr r2, _0823C678 @ =0x03003540
	movs r1, #0x12
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bne _0823C680
	ldr r0, _0823C67C @ =0x030046A0
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	strh r0, [r2]
	ldrh r0, [r1, #0x32]
	adds r0, #0x96
	b _0823C68C
	.align 2, 0
_0823C678: .4byte 0x03003540
_0823C67C: .4byte 0x030046A0
_0823C680:
	ldr r0, _0823C694 @ =0x030046A0
	ldr r1, [r0]
	ldrh r0, [r1, #0x30]
	strh r0, [r2]
	ldrh r0, [r1, #0x32]
	subs r0, #0x96
_0823C68C:
	strh r0, [r2, #2]
	ldrh r0, [r1, #0x34]
	strh r0, [r2, #4]
	b _0823C918
	.align 2, 0
_0823C694: .4byte 0x030046A0
_0823C698:
	ldr r1, _0823C6B4 @ =0x03003540
	adds r0, r6, #0
	adds r0, #0x6c
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x6e
	ldrh r0, [r0]
	strh r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x70
	ldrh r0, [r0]
	strh r0, [r1, #4]
	b _0823C918
	.align 2, 0
_0823C6B4: .4byte 0x03003540
_0823C6B8:
	ldr r4, _0823C728 @ =0x03003540
	movs r3, #0
	ldrsh r2, [r4, r3]
	adds r5, r6, #0
	adds r5, #0x6a
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x6c
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x6e
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #2]
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x70
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #4]
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0823C71C
	b _0823C918
_0823C71C:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #1
	strh r0, [r1]
	b _0823C8EE
	.align 2, 0
_0823C728: .4byte 0x03003540
_0823C72C:
	adds r0, r6, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	bl FUN_0823b2d0
	adds r5, r0, #0
	cmp r5, #0
	bne _0823C73E
	b _0823C918
_0823C73E:
	ldr r1, _0823C768 @ =0x03003540
	adds r0, r6, #0
	adds r0, #0x74
	ldrh r0, [r0]
	ldrh r2, [r5, #8]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r6, #0
	adds r0, #0x76
	ldrh r0, [r0]
	ldrh r3, [r5, #0xa]
	adds r0, r0, r3
	strh r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0x78
	ldrh r0, [r0]
	ldrh r5, [r5, #0xc]
	adds r0, r0, r5
	strh r0, [r1, #4]
	b _0823C918
	.align 2, 0
_0823C768: .4byte 0x03003540
_0823C76C:
	adds r0, r6, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	bl FUN_0823b2d0
	adds r5, r0, #0
	cmp r5, #0
	bne _0823C77E
	b _0823C918
_0823C77E:
	ldr r4, _0823C810 @ =0x03003540
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r7, r6, #0
	adds r7, #0x6a
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	movs r3, #8
	ldrsh r2, [r5, r3]
	mov ip, r2
	movs r2, #0x74
	adds r2, r2, r6
	mov r8, r2
	movs r3, #0
	ldrsh r2, [r2, r3]
	mov r8, r2
	mov r2, ip
	add r2, r8
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	movs r3, #0xa
	ldrsh r2, [r5, r3]
	mov ip, r2
	movs r2, #0x76
	adds r2, r2, r6
	mov r8, r2
	movs r3, #0
	ldrsh r2, [r2, r3]
	mov r8, r2
	mov r2, ip
	add r2, r8
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #2]
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	movs r3, #0xc
	ldrsh r2, [r5, r3]
	adds r3, r6, #0
	adds r3, #0x78
	movs r5, #0
	ldrsh r3, [r3, r5]
	adds r2, r2, r3
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #4]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _0823C804
	b _0823C918
_0823C804:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	strh r0, [r1]
	b _0823C8EE
	.align 2, 0
_0823C810: .4byte 0x03003540
_0823C814:
	ldr r4, _0823C880 @ =0x03003540
	movs r0, #0
	ldrsh r2, [r4, r0]
	adds r7, r6, #0
	adds r7, #0x6a
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r5, _0823C884 @ =0x030046A0
	ldr r2, [r5]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r2, [r5]
	movs r3, #0x32
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	adds r0, #0x96
	bl Div
	strh r0, [r4, #2]
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrh r1, [r7]
	subs r0, r1, #1
	muls r0, r2, r0
	ldr r2, [r5]
	movs r3, #0x34
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #4]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0823C918
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #0
	strh r0, [r1]
	b _0823C8EE
	.align 2, 0
_0823C880: .4byte 0x03003540
_0823C884: .4byte 0x030046A0
_0823C888:
	ldr r4, _0823C8F8 @ =0x03003540
	movs r5, #0
	ldrsh r2, [r4, r5]
	adds r5, r6, #0
	adds r5, #0x6a
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x58
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4]
	movs r0, #2
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x5a
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #2]
	movs r0, #4
	ldrsh r2, [r4, r0]
	ldrh r1, [r5]
	subs r0, r1, #1
	muls r0, r2, r0
	adds r2, r6, #0
	adds r2, #0x5c
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r0, r0, r2
	bl Div
	strh r0, [r4, #4]
	ldrh r0, [r5]
	subs r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _0823C918
	movs r0, #0
	strh r0, [r6, #0x1c]
_0823C8EE:
	adds r0, r6, #0
	bl FUN_0823c228
	b _0823C918
	.align 2, 0
_0823C8F8: .4byte 0x03003540
_0823C8FC:
	adds r0, r6, #0
	adds r0, #0xa0
	ldr r0, [r0]
	ldr r0, [r0]
	cmp r0, #0
	beq _0823C918
	ldr r2, _0823C924 @ =0x03003540
	adds r0, r6, #0
	adds r0, #0x9c
	ldr r0, [r0]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_0823C918:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823C924: .4byte 0x03003540
