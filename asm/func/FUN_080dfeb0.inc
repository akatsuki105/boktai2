	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	adds r4, r1, #0
	adds r6, r2, #0
	mov sb, r3
	ldr r0, _080DFFB0 @ =0x0300017C
	ldr r5, [r0]
	cmp r5, #0
	bne _080DFED8
	bl FUN_080e01bc
	adds r5, r0, #0
	cmp r5, #0
	bne _080DFED8
	b _080E009E
_080DFED8:
	adds r0, r5, #0
	bl FUN_080df8b0
	adds r7, r0, #0
	cmp r7, #0
	bne _080DFEE6
	b _080E009E
_080DFEE6:
	movs r1, #0xd7
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	mov r8, r2
	movs r1, #1
	strb r1, [r0]
	movs r2, #0xd4
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0x78
	str r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	subs r1, #0x10
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _080DFFB4 @ =0x0000019D
	adds r0, r7, r2
	strb r4, [r0]
	adds r1, #2
	adds r0, r7, r1
	strb r6, [r0]
	adds r2, #2
	adds r0, r7, r2
	mov r1, sb
	strb r1, [r0]
	adds r2, #0x14
	adds r1, r7, r2
	ldr r0, [sp, #0x30]
	strb r0, [r1]
	movs r0, #0xd0
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	movs r1, #0xd9
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #1
	strb r2, [r0]
	mov sb, r7
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, _080DFFB8 @ =0x0000922E
	ldr r1, _080DFFBC @ =0x00008DC7
	bl FUN_082310cc
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r4, r7, r1
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0822a470
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r4]
	mov r2, r8
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r7, #0xc]
	ldr r1, _080DFFC0 @ =0x00000272
	bl FUN_0822b20c
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r5, #4]
	movs r1, #1
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #1
	ands r0, r2
	cmp r1, r0
	beq _080DFFC4
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080DFFCC
	.align 2, 0
_080DFFB0: .4byte 0x0300017C
_080DFFB4: .4byte 0x0000019D
_080DFFB8: .4byte 0x0000922E
_080DFFBC: .4byte 0x00008DC7
_080DFFC0: .4byte 0x00000272
_080DFFC4:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DFFCC:
	str r0, [r7]
	ldrb r0, [r5, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DFFF0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080DFFF8
_080DFFF0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DFFF8:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _080E0030 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _080E0068
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080E0034
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _080E0028
	ldrb r0, [r5, #5]
_080E0028:
	subs r0, #1
	strh r0, [r5, #8]
	b _080E0044
	.align 2, 0
_080E0030: .4byte 0x0000FFFF
_080E0034:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _080E0044
	strh r1, [r5, #8]
_080E0044:
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r5]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r5, #6]
	ldrb r1, [r5, #6]
	ldrh r0, [r5, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r5, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E0068
	movs r0, #1
	strb r0, [r5, #7]
_080E0068:
	movs r4, #0
	movs r0, #1
	mov r1, sb
	strb r0, [r1, #7]
	ldr r0, [r1]
	movs r1, #2
	orrs r0, r1
	subs r1, #4
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r0, [sp, #0x38]
	strb r0, [r2, #6]
	adds r0, r7, #0
	bl FUN_080df4c4
	ldr r0, [sp, #0x48]
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r7, #0
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	ldr r3, [sp, #0x44]
	bl FUN_080df790
_080E009E:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
