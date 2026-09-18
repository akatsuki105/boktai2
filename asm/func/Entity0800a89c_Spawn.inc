	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #4]
	adds r4, r1, #0
	adds r5, r2, #0
	str r3, [sp, #8]
	ldr r0, _0800A914 @ =0x03000044
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800A91C
	ldr r0, _0800A918 @ =0x0000FC73
	movs r1, #0
	bl Entity0800a89c_Create
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _0800A91C
	movs r0, #1
	rsbs r0, r0, #0
	b _0800AC6E
	.align 2, 0
_0800A914: .4byte 0x03000044
_0800A918: .4byte 0x0000FC73
_0800A91C:
	ldr r0, _0800A97C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	bne _0800A926
	b _0800AC6C
_0800A926:
	movs r0, #0xf0
	ands r0, r4
	rsbs r1, r0, #0
	orrs r1, r0
	lsrs r3, r1, #0x1f
	movs r0, #0xf
	ands r4, r0
	ldr r0, [sp, #4]
	cmp r0, #4
	ble _0800A93E
	movs r1, #4
	str r1, [sp, #4]
_0800A93E:
	ldr r2, [sp, #0x50]
	cmp r2, #0
	bne _0800A948
	movs r0, #1
	str r0, [sp, #0x50]
_0800A948:
	ldr r0, _0800A980 @ =0x085AA700
	lsls r1, r4, #2
	adds r0, r1, r0
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r2, #0
	str r1, [sp, #0x18]
	ldr r1, [sp, #0x10]
	adds r1, #0x28
	str r1, [sp, #0x24]
	str r1, [sp, #0x20]
_0800A95E:
	ldr r1, [sp, #0x20]
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800A968
	b _0800AC54
_0800A968:
	strb r4, [r1, #2]
	strb r5, [r1, #3]
	mov r2, sp
	ldrb r2, [r2, #4]
	strb r2, [r1, #1]
	cmp r3, #0
	beq _0800A984
	strb r0, [r1, #4]
	b _0800A98A
	.align 2, 0
_0800A97C: .4byte 0x03002BE0
_0800A980: .4byte 0x085AA700
_0800A984:
	movs r0, #0xe
	ldr r3, [sp, #0x20]
	strb r0, [r3, #4]
_0800A98A:
	movs r0, #0
	str r0, [sp, #0x14]
	mov sl, r0
	ldr r1, [sp, #4]
	cmp sl, r1
	blt _0800A998
	b _0800AC1A
_0800A998:
	ldr r7, _0800AB4C @ =0x030046B8
	ldr r5, [sp, #0x24]
	adds r5, #0x10
	ldr r2, [sp, #0x24]
	adds r2, #0x20
	mov sb, r2
	ldr r3, [sp, #0x24]
	adds r3, #8
	mov r8, r3
	ldr r0, [sp, #0x24]
	adds r0, #0x30
	str r0, [sp, #0x1c]
	mov sl, r1
_0800A9B2:
	movs r2, #1
	mov r1, r8
	strb r2, [r1]
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [sp, #0x50]
	bl Mod
	ldr r2, [sp, #0x4c]
	adds r0, r2, r0
	mov r3, r8
	strh r0, [r3, #4]
	mov r0, sp
	ldrh r0, [r0, #0xc]
	strh r0, [r3, #6]
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _0800AB50 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _0800AB54 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #4
	strb r0, [r3, #1]
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r1, r8
	strb r0, [r1, #2]
	ldr r0, [r7]
	adds r0, #1
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x80
	rsbs r1, r1, #0
	orrs r0, r1
	mov r2, r8
	strb r0, [r2, #3]
	ldr r0, [r5, #0x20]
	adds r1, #0x7e
	ands r0, r1
	str r0, [r5, #0x20]
	ldr r3, [sp, #8]
	ldrh r0, [r3]
	strh r0, [r5, #0x38]
	ldr r1, [sp, #0x48]
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0800AA5E
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x48]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Mod
	ldrh r1, [r5, #0x38]
	adds r1, r1, r0
	strh r1, [r5, #0x38]
_0800AA5E:
	ldr r1, [sp, #8]
	ldrh r0, [r1, #2]
	strh r0, [r5, #0x3a]
	ldr r2, [sp, #0x48]
	movs r3, #2
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _0800AA90
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _0800AB50 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _0800AB54 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r3, [sp, #0x48]
	movs r2, #2
	ldrsh r1, [r3, r2]
	bl Mod
	ldrh r1, [r5, #0x3a]
	adds r1, r1, r0
	strh r1, [r5, #0x3a]
_0800AA90:
	ldr r3, [sp, #8]
	ldrh r0, [r3, #4]
	strh r0, [r5, #0x3c]
	ldr r1, [sp, #0x48]
	movs r2, #4
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _0800AAC2
	ldr r0, [r7]
	adds r0, #1
	ldr r3, _0800AB50 @ =0x000003FF
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _0800AB54 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r2, [sp, #0x48]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl Mod
	ldrh r1, [r5, #0x3c]
	adds r1, r1, r0
	strh r1, [r5, #0x3c]
_0800AAC2:
	ldr r0, [sp, #0x10]
	ldr r1, [r0, #0x24]
	ldr r3, _0800AB58 @ =0x085AA6D0
	ldr r2, [r0, #0x18]
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #2
	ldr r2, [sp, #0x18]
	adds r0, r2, r0
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r3, #0
	str r3, [sp]
	mov r0, sb
	bl FUN_08236fac
	mov r0, sp
	ldrh r0, [r0, #0x14]
	strh r0, [r5, #0x18]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	cmp r1, #2
	ble _0800AAF6
	movs r2, #0
	str r2, [sp, #0x14]
_0800AAF6:
	movs r3, #0
	strh r3, [r5]
	strh r3, [r5, #2]
	strh r3, [r5, #4]
	ldr r0, [r5, #0x38]
	ldr r1, [r5, #0x3c]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	ldr r0, [sp, #0x10]
	ldr r0, [r0, #0x20]
	mov ip, r0
	mov r4, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x10]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x1a]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x1b]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	mov r1, ip
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r5, #0x28]
	ldrb r0, [r4, #4]
	movs r2, #1
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	movs r3, #1
	ands r0, r3
	cmp r2, r0
	beq _0800AB5C
	ldr r0, [r5, #0x20]
	movs r1, #4
	orrs r0, r1
	b _0800AB64
	.align 2, 0
_0800AB4C: .4byte 0x030046B8
_0800AB50: .4byte 0x000003FF
_0800AB54: .4byte 0x0203B400
_0800AB58: .4byte 0x085AA6D0
_0800AB5C:
	ldr r0, [r5, #0x20]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0800AB64:
	str r0, [r5, #0x20]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _0800AB88
	ldr r0, [r5, #0x20]
	movs r1, #8
	orrs r0, r1
	b _0800AB90
_0800AB88:
	ldr r0, [r5, #0x20]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0800AB90:
	str r0, [r5, #0x20]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0800ABC8 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0800ABF2
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0800ABCC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0800ABC0
	ldrb r0, [r4, #5]
_0800ABC0:
	subs r0, #1
	strh r0, [r4, #8]
	b _0800ABDC
	.align 2, 0
_0800ABC8: .4byte 0x0000FFFF
_0800ABCC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0800ABDC
	strh r1, [r4, #8]
_0800ABDC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_0800ABF2:
	ldr r0, [sp, #0x1c]
	movs r1, #0
	bl FUN_0822da50
	adds r5, #0x50
	movs r3, #0x50
	add sb, r3
	add r8, r3
	ldr r0, [sp, #0x1c]
	adds r0, #0x50
	str r0, [sp, #0x1c]
	movs r1, #1
	rsbs r1, r1, #0
	add sl, r1
	mov r2, sl
	cmp r2, #0
	beq _0800AC16
	b _0800A9B2
_0800AC16:
	ldr r3, [sp, #4]
	mov sl, r3
_0800AC1A:
	mov r0, sl
	cmp r0, #3
	bgt _0800AC48
	lsls r0, r0, #2
	add r0, sl
	lsls r0, r0, #4
	adds r0, #0x30
	ldr r1, [sp, #0x24]
	adds r4, r0, r1
_0800AC2C:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822da50
	adds r4, #0x50
	movs r2, #1
	add sl, r2
	mov r3, sl
	cmp r3, #3
	ble _0800AC2C
_0800AC48:
	movs r0, #0x28
	ldr r1, [sp, #0x20]
	strh r0, [r1, #6]
	movs r0, #1
	strb r0, [r1]
	b _0800AC6C
_0800AC54:
	ldr r0, [sp, #0x20]
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	adds r0, r0, r1
	str r0, [sp, #0x24]
	adds r2, #1
	cmp r2, #5
	bgt _0800AC6C
	b _0800A95E
_0800AC6C:
	movs r0, #0
_0800AC6E:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
