	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r1, [r0]
	ldrb r0, [r6, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _08104258
	ldr r4, _08104254 @ =0xFFFFFF00
	adds r1, r1, r4
	b _08104266
	.align 2, 0
_08104254: .4byte 0xFFFFFF00
_08104258:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08104266
	movs r5, #0x80
	lsls r5, r5, #1
	adds r1, r1, r5
_08104266:
	adds r4, r1, #0
	cmp r4, #0
	bge _0810426E
	rsbs r4, r4, #0
_0810426E:
	adds r0, r6, #0
	bl Skeleton_CanAttack
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08104346
	ldr r0, _08104304 @ =0x00000716
	adds r0, r0, r7
	mov r8, r0
	ldrh r5, [r0]
	cmp r5, #0
	beq _08104288
	b _0810463A
_08104288:
	adds r1, r4, #0
	cmp r1, #0
	bge _08104290
	rsbs r1, r1, #0
_08104290:
	cmp r1, #0x1f
	bgt _08104320
	ldrb r1, [r6, #5]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r6, #5]
	adds r0, r6, #0
	bl Skeleton_PickWalkDestRandom
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081042B0
	b _0810463A
_081042B0:
	ldr r2, _08104308 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _0810430C @ =0x0000046D
	adds r0, r6, r3
	movs r3, #1
	strb r3, [r0]
	ldr r4, _08104310 @ =0x0000046B
	adds r0, r6, r4
	strb r5, [r0]
	ldr r7, _08104314 @ =0x00000553
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r5, [r0]
	movs r2, #0x12
	subs r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08104318 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0810431C @ =0x00000484
	adds r0, r6, r2
	str r5, [r0]
	adds r4, #4
	adds r0, r6, r4
	strb r3, [r0]
	movs r0, #0x78
	mov r5, r8
	strh r0, [r5]
	b _0810463A
	.align 2, 0
_08104304: .4byte 0x00000716
_08104308: .4byte Enemy_ClearStateBegun
_0810430C: .4byte 0x0000046D
_08104310: .4byte 0x0000046B
_08104314: .4byte 0x00000553
_08104318: .4byte 0x0000046A
_0810431C: .4byte 0x00000484
_08104320:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xe6
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104336
	movs r0, #1
	b _08104338
_08104336:
	movs r0, #0
_08104338:
	cmp r0, #0
	beq _0810433E
	b _0810463A
_0810433E:
	adds r0, r6, #0
	bl Skeleton_LichRelocate
	b _0810463A
_08104346:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r4, #0
	ldrsh r1, [r0, r4]
	ldr r5, _081043D8 @ =0x00000546
	adds r0, r6, r5
	ldrh r0, [r0]
	cmp r1, r0
	blt _0810435C
	b _0810449A
_0810435C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #0xe7
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081043FC
	ldr r3, _081043DC @ =0x00000746
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _081043FC
	bl Entity081f4554_IsFull
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _081043FC
	ldr r2, _081043E0 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r7, _081043E4 @ =0x0000046D
	adds r0, r6, r7
	movs r4, #1
	strb r4, [r0]
	ldr r3, _081043E8 @ =0x0000046B
	adds r0, r6, r3
	strb r5, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r5, [r0]
	movs r2, #2
	movs r3, #5
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _081043EC @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _081043F0 @ =0x0000046A
	adds r0, r6, r2
	strb r3, [r0]
	ldr r3, _081043F4 @ =0x00000484
	adds r0, r6, r3
	str r5, [r0]
	ldr r5, _081043F8 @ =0x0000046C
	adds r0, r6, r5
	strb r4, [r0]
	b _0810463A
	.align 2, 0
_081043D8: .4byte 0x00000546
_081043DC: .4byte 0x00000746
_081043E0: .4byte Enemy_ClearStateBegun
_081043E4: .4byte 0x0000046D
_081043E8: .4byte 0x0000046B
_081043EC: .4byte 0x00000469
_081043F0: .4byte 0x0000046A
_081043F4: .4byte 0x00000484
_081043F8: .4byte 0x0000046C
_081043FC:
	ldr r1, _08104468 @ =0x00000744
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _08104484
	ldr r2, _0810446C @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r3, _08104470 @ =0x0000046D
	adds r0, r6, r3
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r4, _08104474 @ =0x0000046B
	adds r0, r6, r4
	strb r3, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #4
	mov r8, r4
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _08104478 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _0810447C @ =0x0000046A
	adds r0, r6, r2
	mov r4, r8
	strb r4, [r0]
	adds r1, #0x1b
	adds r0, r6, r1
	str r3, [r0]
	adds r2, #2
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _08104480 @ =0x0000070D
	adds r1, r7, r3
	movs r0, #3
	strb r0, [r1]
	b _0810463A
	.align 2, 0
_08104468: .4byte 0x00000744
_0810446C: .4byte Enemy_ClearStateBegun
_08104470: .4byte 0x0000046D
_08104474: .4byte 0x0000046B
_08104478: .4byte 0x00000469
_0810447C: .4byte 0x0000046A
_08104480: .4byte 0x0000070D
_08104484:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r4, #0xe6
	lsls r4, r4, #3
	adds r0, r7, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08104498
	b _081045CA
_08104498:
	b _081045CE
_0810449A:
	movs r5, #0xf2
	lsls r5, r5, #1
	adds r0, r6, r5
	ldr r2, _08104518 @ =0x0000073C
	adds r1, r7, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _08104538
	movs r3, #0xe9
	lsls r3, r3, #3
	adds r0, r7, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _08104538
	adds r0, r6, #0
	bl Skeleton_CanSummonSkeleton
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081045B8
	ldr r2, _0810451C @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r5, _08104520 @ =0x0000046D
	adds r0, r6, r5
	movs r3, #0
	movs r5, #1
	strb r5, [r0]
	ldr r7, _08104524 @ =0x0000046B
	adds r0, r6, r7
	strb r3, [r0]
	ldr r4, _08104528 @ =0x00000553
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r6, r7
	str r2, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r1, #0
	strh r3, [r0]
	movs r2, #2
	movs r4, #6
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _0810452C @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08104530 @ =0x0000046A
	adds r0, r6, r2
	strb r4, [r0]
	ldr r4, _08104534 @ =0x00000484
	adds r0, r6, r4
	str r3, [r0]
	adds r7, #4
	adds r0, r6, r7
	strb r5, [r0]
	b _0810463A
	.align 2, 0
_08104518: .4byte 0x0000073C
_0810451C: .4byte Enemy_ClearStateBegun
_08104520: .4byte 0x0000046D
_08104524: .4byte 0x0000046B
_08104528: .4byte 0x00000553
_0810452C: .4byte 0x00000469
_08104530: .4byte 0x0000046A
_08104534: .4byte 0x00000484
_08104538:
	ldr r1, _081045A0 @ =0x00000744
	adds r0, r7, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bgt _081045B8
	ldr r3, _081045A4 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r4, _081045A8 @ =0x0000046D
	adds r0, r6, r4
	movs r2, #0
	movs r5, #1
	strb r5, [r0]
	subs r4, #2
	adds r0, r6, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r6, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0
	strh r2, [r0]
	movs r4, #2
	movs r0, #4
	mov r8, r0
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r1, [r0]
	ldr r1, _081045AC @ =0x00000469
	adds r0, r6, r1
	strb r4, [r0]
	adds r3, #2
	adds r0, r6, r3
	mov r1, r8
	strb r1, [r0]
	adds r3, #0x1a
	adds r0, r6, r3
	str r2, [r0]
	ldr r1, _081045B0 @ =0x0000046C
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _081045B4 @ =0x0000070D
	adds r0, r7, r2
	strb r4, [r0]
	b _0810463A
	.align 2, 0
_081045A0: .4byte 0x00000744
_081045A4: .4byte Enemy_ClearStateBegun
_081045A8: .4byte 0x0000046D
_081045AC: .4byte 0x00000469
_081045B0: .4byte 0x0000046C
_081045B4: .4byte 0x0000070D
_081045B8:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r3, #0xe6
	lsls r3, r3, #3
	adds r0, r7, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081045CE
_081045CA:
	movs r0, #1
	b _081045D0
_081045CE:
	movs r0, #0
_081045D0:
	adds r4, r0, #0
	cmp r4, #0
	bne _0810463A
	ldrb r1, [r6, #5]
	movs r5, #0xfe
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrb r0, [r0]
	adds r0, #0x80
	strb r0, [r6, #5]
	adds r0, r6, #0
	bl Skeleton_PickWalkDestRandom
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0810463A
	ldr r2, _08104644 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r7, _08104648 @ =0x0000046D
	adds r0, r6, r7
	movs r3, #1
	strb r3, [r0]
	ldr r5, _0810464C @ =0x0000046B
	adds r0, r6, r5
	strb r4, [r0]
	adds r7, #0xe6
	adds r0, r6, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #0x12
	subs r5, #3
	adds r0, r6, r5
	strb r1, [r0]
	subs r7, #0xea
	adds r0, r6, r7
	strb r1, [r0]
	ldr r1, _08104650 @ =0x0000046A
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08104654 @ =0x00000484
	adds r0, r6, r2
	str r4, [r0]
	ldr r4, _08104658 @ =0x0000046C
	adds r0, r6, r4
	strb r3, [r0]
_0810463A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08104644: .4byte Enemy_ClearStateBegun
_08104648: .4byte 0x0000046D
_0810464C: .4byte 0x0000046B
_08104650: .4byte 0x0000046A
_08104654: .4byte 0x00000484
_08104658: .4byte 0x0000046C
