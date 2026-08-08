	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xf3
	ldrb r0, [r3]
	cmp r0, #0
	beq _080DE848
	adds r0, r5, #0
	adds r0, #0xe4
	ldr r1, [r5, #0x1c]
	ldr r2, [r5, #0x20]
	str r1, [r0]
	str r2, [r0, #4]
	movs r0, #0
	strb r0, [r3]
_080DE848:
	add r4, sp, #0x14
	adds r3, r5, #0
	adds r3, #0x1c
	adds r2, r5, #0
	adds r2, #0xdc
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r2]
	adds r0, r0, r1
	adds r1, r4, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r6, [r2, #2]
	adds r0, r0, r6
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r0, [r2, #4]
	adds r1, r1, r0
	strh r1, [r4, #4]
	adds r0, r4, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r3, [sp, #0x30]
	adds r7, r2, #0
	cmp r4, #0
	blt _080DE894
	cmp r1, #0
	blt _080DE894
	ldr r0, _080DE898 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080DE894
	ldr r0, _080DE89C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DE8A0
_080DE894:
	movs r4, #0
	b _080DE8AE
	.align 2, 0
_080DE898: .4byte 0x030046A8
_080DE89C: .4byte 0x030046AC
_080DE8A0:
	ldr r0, _080DE8C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080DE8AE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	add r6, sp, #0x14
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DE8CC
	adds r0, #4
	b _080DE8D8
	.align 2, 0
_080DE8C8: .4byte 0x030046A4
_080DE8CC:
	ldr r0, _080DE8EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DE8D8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DE8F0
	cmp r2, #2
	beq _080DE8F4
	b _080DE8F8
	.align 2, 0
_080DE8EC: .4byte 0x030046A4
_080DE8F0:
	ldrb r0, [r6, #4]
	b _080DE8F6
_080DE8F4:
	ldrb r0, [r6]
_080DE8F6:
	subs r1, r1, r0
_080DE8F8:
	cmp r1, #0
	ble _080DE8FE
	b _080DEA34
_080DE8FE:
	movs r1, #0
	ldrsh r0, [r7, r1]
	rsbs r0, r0, #0
	strh r0, [r7]
	adds r2, r5, #0
	adds r2, #0xe0
	movs r3, #0
	ldrsh r0, [r2, r3]
	rsbs r0, r0, #0
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf4
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DE922
	b _080DEA3C
_080DE922:
	movs r6, #0
	ldrsh r0, [r7, r6]
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	str r0, [sp, #0x24]
	adds r6, r5, #0
	adds r6, #0xf3
	str r6, [sp, #0x2c]
	mov r0, sp
	adds r0, #0x1c
	str r0, [sp, #0x44]
	adds r1, r5, #0
	adds r1, #0xf0
	str r1, [sp, #0x28]
	adds r2, r5, #0
	adds r2, #0x78
	str r2, [sp, #0x38]
	adds r3, r5, #0
	adds r3, #0x7c
	str r3, [sp, #0x3c]
	subs r6, #0x73
	str r6, [sp, #0x40]
	adds r0, r5, #0
	adds r0, #0xf6
	str r0, [sp, #0x34]
	ldr r1, _080DE9B8 @ =0x030046B8
	mov sl, r1
	ldr r2, _080DE9BC @ =0x000003FF
	mov sb, r2
	movs r3, #0xff
	mov r8, r3
	movs r7, #5
	ldr r4, [sp, #0x44]
_080DE968:
	mov r6, sl
	ldr r0, [r6]
	adds r0, #1
	mov r1, sb
	ands r0, r1
	lsls r1, r0, #1
	ldr r2, _080DE9C0 @ =0x0203B400
	adds r1, r1, r2
	ldrh r2, [r1]
	mov r3, r8
	ands r2, r3
	adds r0, #1
	mov r6, sb
	ands r0, r6
	mov r1, sl
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _080DE9C0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	ldr r6, [sp, #0x24]
	adds r2, r6, r2
	adds r3, r1, #5
	ldr r1, _080DE9C4 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	mov r6, r8
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080DE9C8
	asrs r1, r0, #0xc
	b _080DE9CE
	.align 2, 0
_080DE9B8: .4byte 0x030046B8
_080DE9BC: .4byte 0x000003FF
_080DE9C0: .4byte 0x0203B400
_080DE9C4: .4byte 0x085B0A08
_080DE9C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DE9CE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	mov r6, r8
	ands r2, r6
	lsls r0, r2, #1
	ldr r1, _080DE9EC @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080DE9F0
	asrs r0, r0, #0xc
	b _080DE9F6
	.align 2, 0
_080DE9EC: .4byte 0x085B0A08
_080DE9F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DE9F6:
	strh r0, [r4, #4]
	ldr r6, [sp, #0x28]
	ldrh r3, [r6]
	movs r0, #0xc
	str r0, [sp]
	ldr r1, [sp, #0x38]
	ldrh r0, [r1]
	str r0, [sp, #4]
	ldr r2, [sp, #0x3c]
	ldrh r0, [r2]
	str r0, [sp, #8]
	ldr r0, [r5, #0x74]
	str r0, [sp, #0xc]
	ldr r6, [sp, #0x40]
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x44]
	movs r2, #4
	bl FUN_080df148
	subs r7, #1
	cmp r7, #0
	bge _080DE968
	movs r0, #3
	ldr r1, [sp, #0x34]
	strb r0, [r1]
	movs r0, #1
	ldr r2, [sp, #0x2c]
	strb r0, [r2]
	b _080DEBAA
_080DEA34:
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
_080DEA3C:
	ldr r1, _080DEA5C @ =0x085B0A08
	adds r2, r5, #0
	adds r2, #0xf2
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080DEA60
	asrs r1, r0, #0xc
	b _080DEA66
	.align 2, 0
_080DEA5C: .4byte 0x085B0A08
_080DEA60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DEA66:
	adds r3, r5, #0
	adds r3, #0xe6
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r5, #0x1e]
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldr r0, _080DEA88 @ =0x03002BE0
	ldr r4, [r0]
	movs r6, #0x2e
	ldrsh r0, [r4, r6]
	adds r0, #0xdc
	cmp r1, r0
	ble _080DEA8C
	ldrh r0, [r3]
	subs r0, #4
	b _080DEA90
	.align 2, 0
_080DEA88: .4byte 0x03002BE0
_080DEA8C:
	ldrh r0, [r4, #0x2e]
	adds r0, #0xdc
_080DEA90:
	strh r0, [r3]
	ldrb r0, [r2]
	adds r0, #4
	strb r0, [r2]
	adds r0, r5, #0
	bl FUN_080de7a0
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	adds r7, r4, #0
	cmp r1, r0
	beq _080DEAD0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080DEAD8
_080DEAD0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DEAD8:
	str r0, [r5]
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
	beq _080DEAFC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080DEB04
_080DEAFC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DEB04:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DEB3C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DEB82
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DEB46
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DEB40
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DEB5C
	.align 2, 0
_080DEB3C: .4byte 0x0000FFFF
_080DEB40:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DEB5A
_080DEB46:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _080DEB5A
	strh r1, [r4, #8]
	movs r2, #1
	b _080DEB5C
_080DEB5A:
	movs r2, #0
_080DEB5C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080DEB84
	movs r0, #1
	strb r0, [r4, #7]
	b _080DEB84
_080DEB82:
	movs r2, #0
_080DEB84:
	cmp r2, #0
	beq _080DEBAA
	adds r0, r5, #0
	adds r0, #0xec
	ldr r1, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r1, r5, #0
	adds r1, #0xf6
	movs r0, #2
	strb r0, [r1]
	subs r1, #3
	movs r0, #1
	strb r0, [r1]
_080DEBAA:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
