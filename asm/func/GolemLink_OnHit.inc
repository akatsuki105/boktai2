	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081B948E
	b _081B972A
_081B948E:
	mov r2, sb
	ldr r0, [r2, #0x24]
	ldr r1, [r2, #0x28]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _081B94C8
	cmp r0, #1
	bgt _081B94B0
	cmp r0, #0
	beq _081B94BA
	b _081B9510
_081B94B0:
	cmp r0, #2
	beq _081B94D8
	cmp r0, #3
	beq _081B94F8
	b _081B9510
_081B94BA:
	mov r0, sp
	ldrh r1, [r0]
	ldr r3, _081B94C4 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081B94E2
	.align 2, 0
_081B94C4: .4byte 0xFFFFFF00
_081B94C8:
	mov r0, sp
	ldrh r1, [r0, #4]
	ldr r0, _081B94D4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081B9502
	.align 2, 0
_081B94D4: .4byte 0xFFFFFF00
_081B94D8:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081B94E2:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081B94F4 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _081B9510
	.align 2, 0
_081B94F4: .4byte 0xFFFF0000
_081B94F8:
	mov r0, sp
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_081B9502:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081B9590 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_081B9510:
	add r2, sp, #8
	mov r4, sp
	adds r3, r6, #0
	adds r3, #0x24
	ldrh r0, [r6, #0x24]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	mov r1, sb
	adds r1, #0x42
	strb r0, [r1]
	ldrh r1, [r6, #0xa]
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _081B9552
	b _081B96FC
_081B9552:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081B9566
	b _081B96AC
_081B9566:
	ldr r3, _081B9594 @ =0x00000553
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0x28
	beq _081B95D2
	ldrb r2, [r7, #5]
	ldr r0, [r6, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081B95C8
	adds r1, r2, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081B9598
	asrs r0, r1, #6
	b _081B959E
	.align 2, 0
_081B9590: .4byte 0xFFFF0000
_081B9594: .4byte 0x00000553
_081B9598:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081B959E:
	adds r2, r0, #0
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081B95B6
	asrs r0, r1, #6
	b _081B95BC
_081B95B6:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081B95BC:
	subs r0, r2, r0
	cmp r0, #0
	bge _081B95C4
	rsbs r0, r0, #0
_081B95C4:
	cmp r0, #2
	bne _081B95CC
_081B95C8:
	movs r0, #1
	b _081B95CE
_081B95CC:
	movs r0, #0
_081B95CE:
	cmp r0, #0
	beq _081B9638
_081B95D2:
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B9600
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081B9600
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _081B9630 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081B9600:
	ldr r1, _081B9634 @ =0x000006BC
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0xc8
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _081B9618
	strh r2, [r1]
_081B9618:
	adds r2, r6, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	ldrh r1, [r6, #4]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, r8
	strh r1, [r0]
	b _081B972A
	.align 2, 0
_081B9630: .4byte 0xFEFFFFFF
_081B9634: .4byte 0x000006BC
_081B9638:
	ldr r0, _081B964C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B9650
	movs r0, #1
	b _081B9652
	.align 2, 0
_081B964C: .4byte 0x030047A4
_081B9650:
	movs r0, #0
_081B9652:
	cmp r0, #0
	beq _081B9688
	ldrh r1, [r6, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081B9664
	movs r2, #0
	b _081B967C
_081B9664:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081B9670
	movs r2, #1
	b _081B967C
_081B9670:
	movs r0, #4
	ands r0, r1
	movs r2, #3
	cmp r0, #0
	beq _081B967C
	movs r2, #2
_081B967C:
	ldr r1, _081B9684 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _081B968A
	.align 2, 0
_081B9684: .4byte 0x03002BE0
_081B9688:
	ldr r0, _081B96A4 @ =0x03002BE0
_081B968A:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B972A
	ldr r1, _081B96A8 @ =0x000006BC
	add r1, r8
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
	b _081B972A
	.align 2, 0
_081B96A4: .4byte 0x03002BE0
_081B96A8: .4byte 0x000006BC
_081B96AC:
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B96DA
	ldrh r1, [r6, #0xa]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081B96DA
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r1, _081B96F4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081B96DA:
	ldr r1, _081B96F8 @ =0x000006BC
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0xc8
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _081B972A
	strh r2, [r1]
	b _081B972A
	.align 2, 0
_081B96F4: .4byte 0xFEFFFFFF
_081B96F8: .4byte 0x000006BC
_081B96FC:
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081B972A
	ldrh r1, [r6, #0xa]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081B972A
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _081B9738 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081B972A:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081B9738: .4byte 0xFEFFFFFF
