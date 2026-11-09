	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08182690 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08182694
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08182696
	.align 2, 0
_08182690: .4byte 0x0000046C
_08182694:
	movs r0, #0
_08182696:
	cmp r0, #0
	beq _081826CE
	movs r4, #0xb4
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _08182728 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _0818272C @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	adds r0, r5, #0
	bl FUN_0817ce48
_081826CE:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081826F0
	adds r0, r5, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081826F0
	b _081829D8
_081826F0:
	adds r0, r5, #0
	movs r1, #1
	bl Enemy_PlayAnim
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	mov r8, r0
	ldr r2, _08182730 @ =0x0000A02F
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r1, r5, r4
	ldrh r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _08182738
	ldr r0, _08182734 @ =0x00000482
	adds r1, r5, r0
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08182748
	.align 2, 0
_08182728: .4byte 0x0000046D
_0818272C: .4byte 0x0000046B
_08182730: .4byte 0x0000A02F
_08182734: .4byte 0x00000482
_08182738:
	ldr r1, _0818276C @ =0x00000482
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08182748
	movs r0, #1
	strh r0, [r2]
_08182748:
	ldr r4, _08182770 @ =0x0000025D
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _08182774
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
	b _0818278C
	.align 2, 0
_0818276C: .4byte 0x00000482
_08182770: .4byte 0x0000025D
_08182774:
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
_0818278C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _081827B0 @ =0x0000FFFE
	cmp r1, r0
	bhi _081827F4
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrb r1, [r0]
	ldrb r0, [r5, #5]
	subs r1, r1, r0
	cmp r1, #0x80
	ble _081827B8
	ldr r4, _081827B4 @ =0xFFFFFF00
	adds r1, r1, r4
	b _081827C6
	.align 2, 0
_081827B0: .4byte 0x0000FFFE
_081827B4: .4byte 0xFFFFFF00
_081827B8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081827C6
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081827C6:
	cmp r1, #0
	bge _081827CC
	rsbs r1, r1, #0
_081827CC:
	cmp r1, #0x1f
	bgt _081827DC
	ldr r2, _081827D8 @ =0x0000087C
	adds r1, r6, r2
	b _081827E2
	.align 2, 0
_081827D8: .4byte 0x0000087C
_081827DC:
	movs r4, #0x88
	lsls r4, r4, #4
	adds r1, r6, r4
_081827E2:
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_0817ba7c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081827F4
	b _081829D8
_081827F4:
	ldr r1, _08182868 @ =0x000004A4
	adds r0, r5, r1
	ldr r1, [r0]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #0x20
	movs r3, #0x20
	bl FUN_0817d204
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	beq _08182812
	b _081829CE
_08182812:
	movs r1, #0x80
	lsls r1, r1, #0xe
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08182852
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0818286C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08182870 @ =0xFFFFFDFF
	ldrh r0, [r7]
	ands r1, r0
	movs r2, #0
	movs r3, #0
	strh r1, [r7]
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _08182874 @ =0x0000021E
	adds r0, r5, r2
	strh r3, [r0]
	adds r4, #0x8a
	adds r0, r5, r4
	strh r3, [r0]
_08182852:
	movs r2, #0x80
	lsls r2, r2, #7
	ldr r0, _08182878 @ =0x00000898
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r3, r1, #0
	cmp r0, #0
	beq _0818287C
	movs r0, #1
	b _0818287E
	.align 2, 0
_08182868: .4byte 0x000004A4
_0818286C: .4byte 0xFEFFFFFF
_08182870: .4byte 0xFFFFFDFF
_08182874: .4byte 0x0000021E
_08182878: .4byte 0x00000898
_0818287C:
	movs r0, #0
_0818287E:
	adds r4, r0, #0
	cmp r4, #0
	beq _08182970
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #0xb
	cmp r1, r0
	bhi _08182922
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081828B8
	cmp r1, #0
	blt _081828B8
	ldr r0, _081828BC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081828B8
	ldr r0, _081828C0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081828C4
_081828B8:
	movs r4, #0
	b _081828D2
	.align 2, 0
_081828BC: .4byte 0x030046A8
_081828C0: .4byte 0x030046AC
_081828C4:
	ldr r0, _08182900 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081828D2:
	ldr r1, _08182904 @ =0x00000854
	adds r0, r6, r1
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081828FA
	cmp r1, #0
	blt _081828FA
	ldr r0, _08182908 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081828FA
	ldr r0, _0818290C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08182910
_081828FA:
	movs r0, #0
	b _0818291E
	.align 2, 0
_08182900: .4byte 0x030046A4
_08182904: .4byte 0x00000854
_08182908: .4byte 0x030046A8
_0818290C: .4byte 0x030046AC
_08182910:
	ldr r0, _08182954 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0818291E:
	cmp r4, r0
	bne _08182960
_08182922:
	movs r2, #0x14
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08182958 @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r4, #2
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0818295C @ =0xFFFFBFFF
	ldr r0, [r3]
	ands r0, r1
	str r0, [r3]
	b _081829D8
	.align 2, 0
_08182954: .4byte 0x030046A4
_08182958: .4byte 0x00000484
_0818295C: .4byte 0xFFFFBFFF
_08182960:
	ldr r0, _0818296C @ =0x00000854
	adds r1, r6, r0
	adds r0, r5, #0
	bl FUN_0817ec04
	b _081829CE
	.align 2, 0
_0818296C: .4byte 0x00000854
_08182970:
	ldr r1, _0818298C @ =0x00000256
	adds r2, r5, r1
	ldr r0, _08182990 @ =0x03002BE0
	ldr r3, [r0]
	ldr r1, [r3, #0x3c]
	ldrh r0, [r2]
	ldrh r1, [r1, #6]
	cmp r0, r1
	bne _08182994
	movs r2, #0x88
	lsls r2, r2, #4
	adds r0, r6, r2
	strh r4, [r0]
	b _081829CE
	.align 2, 0
_0818298C: .4byte 0x00000256
_08182990: .4byte 0x03002BE0
_08182994:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r3, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081829C4
	ldr r0, _081829C0 @ =0x00000854
	adds r4, r6, r0
	adds r2, r3, #0
	adds r2, #0x2c
	movs r3, #0x80
	lsls r3, r3, #0xf
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0817e910
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0817ec04
	b _081829CE
	.align 2, 0
_081829C0: .4byte 0x00000854
_081829C4:
	adds r1, r3, #0
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_0817ec04
_081829CE:
	ldr r2, _081829E4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081829D8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081829E4: .4byte 0x00000484
