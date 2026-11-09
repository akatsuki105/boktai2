	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0818B4C8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0818B4CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0818B4CE
	.align 2, 0
_0818B4C8: .4byte 0x0000046C
_0818B4CC:
	movs r0, #0
_0818B4CE:
	cmp r0, #0
	beq _0818B55E
	movs r3, #0xf3
	lsls r3, r3, #4
	adds r0, r6, r3
	movs r4, #0
	movs r1, #1
	strb r1, [r0]
	ldr r7, _0818B52C @ =0x00000F34
	adds r0, r6, r7
	movs r2, #0
	strh r4, [r0]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	ldr r7, _0818B530 @ =0x0000046D
	adds r0, r5, r7
	strb r1, [r0]
	subs r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	ldr r2, _0818B534 @ =0x00000553
	adds r0, r5, r2
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r5, r7
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_0818f918
	movs r2, #0x80
	lsls r2, r2, #8
	ldr r3, _0818B538 @ =0x00000F2C
	adds r1, r6, r3
	ldrh r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _0818B53C
	movs r0, #1
	b _0818B53E
	.align 2, 0
_0818B52C: .4byte 0x00000F34
_0818B530: .4byte 0x0000046D
_0818B534: .4byte 0x00000553
_0818B538: .4byte 0x00000F2C
_0818B53C:
	movs r0, #0
_0818B53E:
	cmp r0, #0
	bne _0818B552
	ldr r0, _0818B58C @ =0x000003E5
	bl PlaySound_082406e0
	movs r0, #0x80
	lsls r0, r0, #8
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
_0818B552:
	adds r0, r5, #0
	movs r1, #2
	movs r2, #6
	movs r3, #1
	bl FUN_0819328c
_0818B55E:
	movs r7, #0xb1
	lsls r7, r7, #3
	adds r0, r5, r7
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r7, r0, #0
	ldr r1, _0818B590 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0818B598
	ldr r3, _0818B594 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0818B5A8
	.align 2, 0
_0818B58C: .4byte 0x000003E5
_0818B590: .4byte 0x0000A02F
_0818B594: .4byte 0x00000482
_0818B598:
	ldr r1, _0818B5CC @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0818B5A8
	movs r0, #1
	strh r0, [r2]
_0818B5A8:
	ldr r3, _0818B5D0 @ =0x0000025D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0818B5D4
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl AuxAnim_SetAnimSpeed
	b _0818B5EC
	.align 2, 0
_0818B5CC: .4byte 0x00000482
_0818B5D0: .4byte 0x0000025D
_0818B5D4:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
_0818B5EC:
	ldr r1, _0818B624 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0818B60E
	rsbs r2, r2, #0
_0818B60E:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0818B628
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0818B61C
	rsbs r2, r2, #0
_0818B61C:
	cmp r2, #0x20
	bgt _0818B628
	movs r0, #1
	b _0818B692
	.align 2, 0
_0818B624: .4byte 0x000004A4
_0818B628:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0818B634
	cmp r1, #0
	beq _0818B690
_0818B634:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _0818B658 @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818B65C
	asrs r1, r0, #0xc
	b _0818B662
	.align 2, 0
_0818B658: .4byte gSineTable
_0818B65C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818B662:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _0818B680 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _0818B684
	asrs r1, r0, #0xc
	b _0818B68A
	.align 2, 0
_0818B680: .4byte gSineTable
_0818B684:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0818B68A:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_0818B690:
	movs r0, #0
_0818B692:
	cmp r0, #0
	beq _0818B73C
	adds r0, r5, #0
	bl FUN_0818e6fc
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _0818B6EC @ =0x000004A4
	adds r0, r5, r1
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
	ldrb r1, [r1]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _0818B6F4
	ldr r3, _0818B6F0 @ =0xFFFFFF00
	adds r1, r1, r3
	b _0818B702
	.align 2, 0
_0818B6EC: .4byte 0x000004A4
_0818B6F0: .4byte 0xFFFFFF00
_0818B6F4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0818B702
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0818B702:
	cmp r1, #0
	bge _0818B708
	rsbs r1, r1, #0
_0818B708:
	cmp r1, #0x20
	ble _0818B73C
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _0818B734 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r7, _0818B738 @ =0x0000046A
	adds r0, r5, r7
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r7, #2
	adds r0, r5, r7
	strb r2, [r0]
	b _0818B80A
	.align 2, 0
_0818B734: .4byte 0x00000469
_0818B738: .4byte 0x0000046A
_0818B73C:
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08190804
	movs r3, #0x80
	lsls r3, r3, #7
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #8
	bl FUN_0818fdd8
	ldr r1, _0818B76C @ =gSineTable
	ldr r2, _0818B770 @ =0x00000484
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _0818B774
	asrs r1, r0, #8
	b _0818B77A
	.align 2, 0
_0818B76C: .4byte gSineTable
_0818B770: .4byte 0x00000484
_0818B774:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r1, r0, #0
_0818B77A:
	ldr r7, _0818B7E0 @ =0x00000BFE
	adds r0, r6, r7
	movs r4, #0
	strh r1, [r0]
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x1e
	bl FUN_08191774
	movs r3, #0xed
	lsls r3, r3, #4
	adds r2, r6, r3
	ldr r7, _0818B7E4 @ =0x00000D52
	adds r0, r6, r7
	ldrh r1, [r2]
	ldrh r0, [r0]
	cmp r1, r0
	bls _0818B7FC
	movs r1, #0x12
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _0818B7E8 @ =0x00000469
	adds r0, r5, r3
	strb r4, [r0]
	ldr r7, _0818B7EC @ =0x0000046A
	adds r0, r5, r7
	strb r1, [r0]
	ldr r0, _0818B7F0 @ =0x00000484
	adds r1, r5, r0
	movs r0, #0
	str r0, [r1]
	adds r2, #4
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0818B7F4 @ =0x00000D56
	adds r0, r6, r3
	ldrh r1, [r0]
	ldr r7, _0818B7F8 @ =0x00000D4E
	adds r0, r6, r7
	strb r1, [r0]
	b _0818B80A
	.align 2, 0
_0818B7E0: .4byte 0x00000BFE
_0818B7E4: .4byte 0x00000D52
_0818B7E8: .4byte 0x00000469
_0818B7EC: .4byte 0x0000046A
_0818B7F0: .4byte 0x00000484
_0818B7F4: .4byte 0x00000D56
_0818B7F8: .4byte 0x00000D4E
_0818B7FC:
	adds r0, r1, #1
	strh r0, [r2]
	ldr r0, _0818B814 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0818B80A:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0818B814: .4byte 0x00000484
