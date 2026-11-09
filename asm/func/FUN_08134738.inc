	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _08134758 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813475C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813475E
	.align 2, 0
_08134758: .4byte 0x0000046C
_0813475C:
	movs r0, #0
_0813475E:
	cmp r0, #0
	beq _081347BA
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _081347F4 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r4, #0
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_08136ac8
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #0x80
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, _081347F8 @ =0x00000B49
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _081347FC @ =0x00000B48
	adds r0, r7, r3
	strb r4, [r0]
	adds r0, r5, #0
	bl FUN_081355f0
_081347BA:
	ldr r4, _08134800 @ =0x00000544
	adds r1, r5, r4
	ldrh r0, [r1]
	cmp r0, #0
	bne _081347C8
	movs r0, #1
	strh r0, [r1]
_081347C8:
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	ldr r1, _08134804 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813480C
	ldr r3, _08134808 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0813481C
	.align 2, 0
_081347F4: .4byte 0x0000046D
_081347F8: .4byte 0x00000B49
_081347FC: .4byte 0x00000B48
_08134800: .4byte 0x00000544
_08134804: .4byte 0x0000A02F
_08134808: .4byte 0x00000482
_0813480C:
	ldr r4, _08134840 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0813481C
	movs r0, #1
	strh r0, [r2]
_0813481C:
	ldr r1, _08134844 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08134848
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
	b _08134860
	.align 2, 0
_08134840: .4byte 0x00000482
_08134844: .4byte 0x0000025D
_08134848:
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
_08134860:
	ldr r2, _08134898 @ =0x000004A4
	adds r0, r5, r2
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
	bge _08134882
	rsbs r2, r2, #0
_08134882:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0813489C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08134890
	rsbs r2, r2, #0
_08134890:
	cmp r2, #0x20
	bgt _0813489C
	movs r0, #1
	b _08134906
	.align 2, 0
_08134898: .4byte 0x000004A4
_0813489C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081348A8
	cmp r1, #0
	beq _08134904
_081348A8:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r5, #5]
	ldr r2, _081348CC @ =gSineTable
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _081348D0
	asrs r1, r0, #0xc
	b _081348D6
	.align 2, 0
_081348CC: .4byte gSineTable
_081348D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081348D6:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _081348F4 @ =gSineTable
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	muls r0, r6, r0
	cmp r0, #0
	blt _081348F8
	asrs r1, r0, #0xc
	b _081348FE
	.align 2, 0
_081348F4: .4byte gSineTable
_081348F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081348FE:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_08134904:
	movs r0, #0
_08134906:
	cmp r0, #0
	beq _08134950
	adds r0, r5, #0
	bl FUN_081355f0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r1, _08134978 @ =0x000004A4
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
	movs r4, #4
	ldrsh r1, [r2, r4]
	bl ArcTan2_8
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r5, r2
	strb r0, [r1]
_08134950:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08137a30
	ldr r3, _0813497C @ =0x00000B44
	adds r4, r7, r3
	ldrh r0, [r4]
	cmp r0, #0
	beq _08134980
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r5, #0
	movs r1, #0x12
	bl FUN_081370f4
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
	b _0813498C
	.align 2, 0
_08134978: .4byte 0x000004A4
_0813497C: .4byte 0x00000B44
_08134980:
	movs r2, #0xc8
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #0x14
	bl FUN_081370f4
_0813498C:
	adds r0, r5, #0
	movs r1, #0x78
	movs r2, #0xa
	bl FUN_08136ca0
	ldr r4, _081349C8 @ =0x00000484
	adds r1, r5, r4
	ldr r0, [r1]
	cmp r0, #0x50
	ble _081349D0
	movs r2, #8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081349CC @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	subs r4, #0x1a
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _081349C8 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081349D4
	.align 2, 0
_081349C8: .4byte 0x00000484
_081349CC: .4byte 0x00000469
_081349D0:
	adds r0, #1
	str r0, [r1]
_081349D4:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
