	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r1, #0
	adds r6, r7, #0
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	adds r4, r7, #0
	adds r4, #0x2c
	movs r1, #0
	strh r1, [r4, #0xe]
	adds r0, r7, #0
	adds r0, #0x98
	ldrh r0, [r0]
	cmp r0, #3
	bne _081EFDA6
	strh r1, [r4, #8]
	b _081EFDB2
_081EFDA6:
	cmp r0, #6
	bne _081EFDAE
	movs r0, #1
	b _081EFDB0
_081EFDAE:
	movs r0, #2
_081EFDB0:
	strh r0, [r4, #8]
_081EFDB2:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EFDDE
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081EFDE6
_081EFDDE:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081EFDE6:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EFE0A
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081EFE12
_081EFE0A:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EFE12:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EFE48 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081EFE80
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EFE4C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EFE42
	ldrb r0, [r4, #5]
_081EFE42:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EFE5C
	.align 2, 0
_081EFE48: .4byte 0x0000FFFF
_081EFE4C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EFE5C
	strh r1, [r4, #8]
_081EFE5C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _081EFE80
	movs r0, #1
	strb r0, [r4, #7]
_081EFE80:
	ldr r0, [r6, #0x1c]
	ldr r1, [r6, #0x20]
	str r0, [sp]
	str r1, [sp, #4]
	mov r2, sp
	adds r3, r7, #0
	adds r3, #0x3c
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r7, #0x3c]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r7, #0x3e]
	subs r0, #1
	strh r0, [r7, #0x3e]
	adds r1, r6, #0
	adds r1, #0x1c
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov sb, r1
	cmp r3, #0
	blt _081EFEDA
	cmp r2, #0
	blt _081EFEDA
	ldr r0, _081EFEE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081EFEDA
	ldr r0, _081EFEE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _081EFEE8
_081EFEDA:
	movs r4, #0
	b _081EFEF6
	.align 2, 0
_081EFEE0: .4byte 0x030046A8
_081EFEE4: .4byte 0x030046AC
_081EFEE8:
	ldr r0, _081EFF08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_081EFEF6:
	mov r5, sb
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EFF0C
	adds r0, #4
	b _081EFF18
	.align 2, 0
_081EFF08: .4byte 0x030046A4
_081EFF0C:
	ldr r0, _081EFF2C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EFF18:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EFF30
	cmp r2, #2
	beq _081EFF34
	b _081EFF38
	.align 2, 0
_081EFF2C: .4byte 0x030046A4
_081EFF30:
	ldrb r0, [r5, #4]
	b _081EFF36
_081EFF34:
	ldrb r0, [r5]
_081EFF36:
	subs r1, r1, r0
_081EFF38:
	mov r8, r1
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081EFF62
	cmp r1, #0
	blt _081EFF62
	ldr r0, _081EFF68 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EFF62
	ldr r0, _081EFF6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EFF70
_081EFF62:
	movs r4, #0
	b _081EFF7E
	.align 2, 0
_081EFF68: .4byte 0x030046A8
_081EFF6C: .4byte 0x030046AC
_081EFF70:
	ldr r0, _081EFF90 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081EFF7E:
	mov r5, sp
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EFF94
	adds r0, #4
	b _081EFFA0
	.align 2, 0
_081EFF90: .4byte 0x030046A4
_081EFF94:
	ldr r0, _081EFFB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EFFA0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081EFFB8
	cmp r3, #2
	beq _081EFFBC
	b _081EFFC0
	.align 2, 0
_081EFFB4: .4byte 0x030046A4
_081EFFB8:
	ldrb r0, [r5, #4]
	b _081EFFBE
_081EFFBC:
	ldrb r0, [r5]
_081EFFBE:
	subs r2, r2, r0
_081EFFC0:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r1, #0x1e
	ldrsh r0, [r6, r1]
	cmp r0, r8
	blt _081EFFD4
	cmp r0, r2
	bge _081F000C
_081EFFD4:
	ldrh r0, [r6, #0x1c]
	ldrh r1, [r7, #0x3c]
	subs r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	ldrh r1, [r7, #0x3e]
	subs r0, r0, r1
	strh r0, [r6, #0x1c]
	adds r3, r7, #0
	adds r3, #0x40
	ldrh r0, [r6, #0x20]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r6, #0x20]
	strh r2, [r7, #0x3c]
	strh r2, [r7, #0x3e]
	strh r2, [r3]
	adds r0, r7, #0
	adds r0, #0x98
	strh r2, [r0]
	adds r1, r7, #0
	adds r1, #0x96
	movs r0, #2
	strb r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
	b _081F002A
_081F000C:
	adds r4, r7, #0
	adds r4, #0x44
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r1, r7, #0
	adds r1, #0x98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F002A:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
