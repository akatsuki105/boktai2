	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #0x10]
	adds r7, r1, #0
	mov r8, r7
	adds r4, r7, #0
	adds r4, #0x2c
	adds r3, r7, #0
	adds r3, #0xf0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F2B2E
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	adds r2, r7, #0
	adds r2, #0xee
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r3]
_081F2B2E:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _081F2B5A
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F2B62
_081F2B5A:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F2B62:
	str r0, [r7]
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
	beq _081F2B8C
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _081F2B98
_081F2B8C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081F2B98:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F2BCC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F2C04
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F2BD0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F2BC6
	ldrb r0, [r4, #5]
_081F2BC6:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F2BE0
	.align 2, 0
_081F2BCC: .4byte 0x0000FFFF
_081F2BD0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F2BE0
	strh r1, [r4, #8]
_081F2BE0:
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
	bne _081F2C04
	movs r0, #1
	strb r0, [r4, #7]
_081F2C04:
	mov r4, r8
	adds r4, #0x1c
	adds r5, r7, #0
	adds r5, #0x88
	mov r3, r8
	ldrh r0, [r3, #0x1c]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	ldrh r0, [r4, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r4, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r7, #0x44]
	str r1, [r7, #0x48]
	movs r1, #0
	ldrsh r0, [r5, r1]
	adds r6, r7, #0
	adds r6, #0x8c
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl ArcTan2_8
	mov ip, r0
	mov r3, sp
	ldr r2, _081F2C60 @ =gSineTable
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	mov sb, r4
	mov sl, r5
	cmp r0, #0
	blt _081F2C64
	asrs r1, r0, #0xc
	b _081F2C6A
	.align 2, 0
_081F2C60: .4byte gSineTable
_081F2C64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F2C6A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _081F2C8C @ =gSineTable
	movs r0, #0xff
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _081F2C90
	asrs r0, r0, #0xc
	b _081F2C96
	.align 2, 0
_081F2C8C: .4byte gSineTable
_081F2C90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F2C96:
	strh r0, [r3, #4]
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r3, r8
	ldrh r3, [r3, #0x1c]
	adds r0, r0, r3
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	mov r1, sb
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	mov r3, sb
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r2, #1
	adds r1, r7, #0
	adds r1, #0xe8
	ldrh r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081F2CD0
	movs r0, #1
	b _081F2CD2
_081F2CD0:
	movs r0, #0
_081F2CD2:
	cmp r0, #0
	bne _081F2D1A
	add r4, sp, #8
	adds r3, r7, #0
	adds r3, #0x44
	adds r2, r7, #0
	adds r2, #0x80
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _081F2D50 @ =0x0000BD0F
	cmp r1, r0
	bgt _081F2D24
	ldrh r0, [r5]
	movs r1, #1
	orrs r0, r1
	strh r0, [r5]
_081F2D1A:
	adds r1, r7, #0
	adds r1, #0x8a
	ldrh r0, [r1]
	subs r0, #4
	strh r0, [r1]
_081F2D24:
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F2D4C
	cmp r1, #0
	blt _081F2D4C
	ldr r0, _081F2D54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F2D4C
	ldr r0, _081F2D58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F2D5C
_081F2D4C:
	movs r4, #0
	b _081F2D6A
	.align 2, 0
_081F2D50: .4byte 0x0000BD0F
_081F2D54: .4byte 0x030046A8
_081F2D58: .4byte 0x030046AC
_081F2D5C:
	ldr r0, _081F2D7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F2D6A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F2D80
	adds r0, #4
	b _081F2D8C
	.align 2, 0
_081F2D7C: .4byte 0x030046A4
_081F2D80:
	ldr r0, _081F2DA0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F2D8C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081F2DA4
	cmp r2, #2
	beq _081F2DA8
	b _081F2DAC
	.align 2, 0
_081F2DA0: .4byte 0x030046A4
_081F2DA4:
	ldrb r0, [r5, #4]
	b _081F2DAA
_081F2DA8:
	ldrb r0, [r5]
_081F2DAA:
	subs r1, r1, r0
_081F2DAC:
	lsls r0, r1, #0x10
	lsrs r5, r0, #0x10
	adds r4, r7, #0
	adds r4, #0x98
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r1, r7, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #0
	strh r0, [r1]
	mov r0, r8
	ldrh r4, [r0, #0x1e]
	movs r2, #0x1e
	ldrsh r1, [r0, r2]
	cmp r1, #0
	bgt _081F2E0A
	ldr r0, [r0]
	movs r1, #1
	orrs r0, r1
	mov r3, r8
	str r0, [r3]
	adds r0, r7, #0
	adds r0, #0xeb
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	lsls r1, r0
	ldr r2, [sp, #0x10]
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r7, #0
	bl AuxSprite_Remove
	adds r1, r7, #0
	adds r1, #0xea
	movs r0, #0
	strb r0, [r1]
	b _081F2E58
_081F2E0A:
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	bgt _081F2E58
	mov r1, r8
	ldrh r0, [r1, #0x1c]
	mov r2, sl
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #0x1c]
	adds r2, r7, #0
	adds r2, #0x8a
	ldrh r0, [r2]
	subs r0, r4, r0
	strh r0, [r1, #0x1e]
	ldrh r0, [r1, #0x20]
	ldrh r1, [r6]
	subs r0, r0, r1
	mov r1, r8
	strh r0, [r1, #0x20]
	mov r0, sl
	strh r3, [r0]
	strh r3, [r2]
	strh r3, [r6]
	adds r1, r7, #0
	adds r1, #0xea
	movs r0, #3
	strb r0, [r1]
	adds r1, #6
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r7, #0x44]
	str r1, [r7, #0x48]
	movs r0, #0xf2
	bl PlaySound_082406e0
_081F2E58:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
