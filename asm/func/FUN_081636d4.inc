	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r6, [r5, #0x44]
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	ldr r2, _081636F8 @ =0x0000046D
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081636FC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081636FE
	.align 2, 0
_081636F8: .4byte 0x0000046D
_081636FC:
	movs r0, #0
_081636FE:
	cmp r0, #0
	beq _0816379C
	ldr r0, _08163740 @ =0x00000482
	adds r1, r5, r0
	movs r0, #2
	strh r0, [r1]
	ldr r0, [r5, #0x44]
	adds r0, #0x48
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r3, r5, r2
	ldrb r4, [r0]
	movs r7, #0x12
	ldr r2, _08163744 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _08163748
	asrs r1, r0, #0xc
	b _0816374E
	.align 2, 0
_08163740: .4byte 0x00000482
_08163744: .4byte gSineTable
_08163748:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0816374E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08163768 @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0816376C
	asrs r0, r0, #0xc
	b _08163772
	.align 2, 0
_08163768: .4byte gSineTable
_0816376C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08163772:
	movs r4, #0
	strh r0, [r3, #4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x28
	strh r0, [r1]
	ldr r0, [r6]
	movs r1, #2
	orrs r0, r1
	str r0, [r6]
	movs r0, #0x40
	strb r0, [r6, #8]
	strb r0, [r6, #9]
	ldr r0, _081637C4 @ =0x000003C1
	bl PlaySound_082406e0
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
_0816379C:
	mov r2, r8
	ldrh r0, [r2, #8]
	cmp r0, #3
	bne _081637A8
	movs r0, #0
	strh r0, [r2, #0xe]
_081637A8:
	movs r1, #0xe1
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	ble _081637C8
	ldrb r1, [r6, #9]
	movs r0, #9
	ldrsb r0, [r6, r0]
	cmp r0, #0x7e
	bgt _081637E2
	adds r0, r1, #1
	b _081637E0
	.align 2, 0
_081637C4: .4byte 0x000003C1
_081637C8:
	ldrb r1, [r6, #9]
	movs r0, #9
	ldrsb r0, [r6, r0]
	cmp r0, #0x40
	ble _081637D6
	subs r0, r1, #2
	strb r0, [r6, #9]
_081637D6:
	movs r0, #9
	ldrsb r0, [r6, r0]
	cmp r0, #0x3f
	bgt _081637E2
	movs r0, #0x40
_081637E0:
	strb r0, [r6, #9]
_081637E2:
	movs r1, #0x10
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0816382C
	ldr r4, _08163838 @ =FUN_08163848
	movs r3, #0x2b
	ldr r0, _0816383C @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08163840 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_08164da8
	adds r0, r5, #0
	bl FUN_08164da8
	ldr r0, _08163844 @ =0x000003C2
	bl PlaySound_082406e0
_0816382C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08163838: .4byte FUN_08163848
_0816383C: .4byte 0x0000046D
_08163840: .4byte 0x0000046B
_08163844: .4byte 0x000003C2
