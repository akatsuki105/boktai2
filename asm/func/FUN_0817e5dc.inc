	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r2, _0817E5FC @ =0x00000898
	adds r0, r7, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817E600
	movs r0, #1
	b _0817E602
	.align 2, 0
_0817E5FC: .4byte 0x00000898
_0817E600:
	movs r0, #0
_0817E602:
	ldr r3, _0817E620 @ =0x00000898
	adds r5, r7, r3
	cmp r0, #0
	beq _0817E648
	movs r4, #0xf6
	lsls r4, r4, #3
	adds r2, r7, r4
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	ble _0817E628
	ldr r3, _0817E624 @ =0x00000482
	adds r1, r6, r3
	movs r0, #2
	b _0817E632
	.align 2, 0
_0817E620: .4byte 0x00000898
_0817E624: .4byte 0x00000482
_0817E628:
	cmp r0, #0
	bne _0817E640
	ldr r4, _0817E63C @ =0x00000482
	adds r1, r6, r4
	movs r0, #1
_0817E632:
	strh r0, [r1]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	b _0817E648
	.align 2, 0
_0817E63C: .4byte 0x00000482
_0817E640:
	ldr r1, _0817E658 @ =0xFFFF7FFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
_0817E648:
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E65C
	movs r0, #1
	b _0817E65E
	.align 2, 0
_0817E658: .4byte 0xFFFF7FFF
_0817E65C:
	movs r0, #0
_0817E65E:
	cmp r0, #0
	bne _0817E664
	b _0817E82C
_0817E664:
	movs r0, #0xf6
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r2, #0
	ldrsh r1, [r4, r2]
	cmp r1, #0x1e
	bne _0817E686
	ldr r3, _0817E6B4 @ =0x000007B2
	adds r0, r7, r3
	strh r1, [r0]
	ldr r1, _0817E6B8 @ =0xFFFBFFFF
	ldr r0, [r5]
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xa
	orrs r0, r1
	str r0, [r5]
_0817E686:
	adds r0, r6, #0
	bl FUN_0817e51c
	ldrh r1, [r4]
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	ble _0817E6C4
	subs r0, r1, #1
	strh r0, [r4]
	ldr r0, _0817E6BC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0817E750
	ldr r0, _0817E6C0 @ =0x03002BE0
	ldr r1, [r0]
	cmp r1, #0
	beq _0817E74C
	b _0817E728
	.align 2, 0
_0817E6B4: .4byte 0x000007B2
_0817E6B8: .4byte 0xFFFBFFFF
_0817E6BC: .4byte 0x030047A4
_0817E6C0: .4byte 0x03002BE0
_0817E6C4:
	ldr r3, [r6, #0x44]
	adds r2, r3, #0
	adds r2, #0x20
	ldr r0, [r2, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #8]
	ldr r1, _0817E700 @ =0xFFFEFFFF
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	ldr r4, _0817E704 @ =0x0000047A
	adds r0, r6, r4
	ldrh r1, [r0]
	adds r4, #6
	adds r0, r6, r4
	ldrh r0, [r0]
	adds r1, r1, r0
	ldr r4, _0817E708 @ =0x0000025D
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _0817E70C
	adds r0, r3, #0
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _0817E716
	.align 2, 0
_0817E700: .4byte 0xFFFEFFFF
_0817E704: .4byte 0x0000047A
_0817E708: .4byte 0x0000025D
_0817E70C:
	ldr r0, _0817E720 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x48]
_0817E716:
	ldr r0, [r6, #0x44]
	adds r0, #0x20
	ldr r1, _0817E724 @ =0x00000272
	strh r1, [r0, #0x3a]
	b _0817E82C
	.align 2, 0
_0817E720: .4byte 0x03003584
_0817E724: .4byte 0x00000272
_0817E728:
	ldr r2, _0817E744 @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _0817E740
	ldr r3, _0817E748 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _0817E740
	movs r2, #1
_0817E740:
	adds r0, r2, #0
	b _0817E780
	.align 2, 0
_0817E744: .4byte 0x00000446
_0817E748: .4byte 0x00000442
_0817E74C:
	movs r0, #0
	b _0817E780
_0817E750:
	ldr r0, _0817E794 @ =0x03002B48
	ldr r0, [r0]
	cmp r0, #0
	bgt _0817E784
	ldr r0, _0817E798 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #2
	beq _0817E784
	ldr r0, _0817E79C @ =0x03002B8C
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _0817E77E
	ldr r0, _0817E7A0 @ =0x03002B60
	ldrh r0, [r0]
	cmp r0, #4
	bne _0817E77E
	movs r1, #1
_0817E77E:
	adds r0, r1, #0
_0817E780:
	cmp r0, #0
	beq _0817E7DC
_0817E784:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E7A4
	movs r0, #1
	b _0817E7A6
	.align 2, 0
_0817E794: .4byte 0x03002B48
_0817E798: .4byte 0x030046A0
_0817E79C: .4byte 0x03002B8C
_0817E7A0: .4byte 0x03002B60
_0817E7A4:
	movs r0, #0
_0817E7A6:
	cmp r0, #0
	bne _0817E82C
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E7BA
	movs r0, #1
	b _0817E7BC
_0817E7BA:
	movs r0, #0
_0817E7BC:
	cmp r0, #0
	beq _0817E82C
	ldr r2, _0817E7D4 @ =0x000007B2
	adds r1, r7, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5]
	orrs r0, r1
	ldr r1, _0817E7D8 @ =0xFFFBFFFF
	b _0817E828
	.align 2, 0
_0817E7D4: .4byte 0x000007B2
_0817E7D8: .4byte 0xFFFBFFFF
_0817E7DC:
	movs r3, #0xf6
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0x1e
	ble _0817E82C
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E7FA
	movs r0, #1
	b _0817E7FC
_0817E7FA:
	movs r0, #0
_0817E7FC:
	cmp r0, #0
	bne _0817E82C
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0817E810
	movs r0, #1
	b _0817E812
_0817E810:
	movs r0, #0
_0817E812:
	cmp r0, #0
	beq _0817E82C
	ldr r0, _0817E834 @ =0x000007B2
	adds r1, r7, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5]
	orrs r0, r1
	ldr r1, _0817E838 @ =0xFFFDFFFF
_0817E828:
	ands r0, r1
	str r0, [r5]
_0817E82C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0817E834: .4byte 0x000007B2
_0817E838: .4byte 0xFFFDFFFF
