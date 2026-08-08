	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	adds r7, r1, #0
	adds r3, r7, #0
	adds r3, #0xf3
	ldrb r0, [r3]
	cmp r0, #0
	beq _080DEBEE
	adds r2, r7, #0
	adds r2, #0xe4
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, [r7]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0
	strb r0, [r3]
_080DEBEE:
	add r4, sp, #0x14
	adds r3, r7, #0
	adds r3, #0x1c
	adds r2, r7, #0
	adds r2, #0xdc
	ldrh r0, [r7, #0x1c]
	ldrh r1, [r2]
	adds r0, r0, r1
	adds r1, r4, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r5, [r2, #2]
	adds r0, r0, r5
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r6, [r2, #4]
	adds r1, r1, r6
	strh r1, [r4, #4]
	adds r0, r4, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r3, [sp, #0x3c]
	mov r8, r2
	cmp r4, #0
	blt _080DEC3A
	cmp r1, #0
	blt _080DEC3A
	ldr r0, _080DEC40 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080DEC3A
	ldr r0, _080DEC44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DEC48
_080DEC3A:
	movs r4, #0
	b _080DEC56
	.align 2, 0
_080DEC40: .4byte 0x030046A8
_080DEC44: .4byte 0x030046AC
_080DEC48:
	ldr r0, _080DEC70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080DEC56:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	add r5, sp, #0x14
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DEC74
	adds r0, #4
	b _080DEC80
	.align 2, 0
_080DEC70: .4byte 0x030046A4
_080DEC74:
	ldr r0, _080DEC94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DEC80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DEC98
	cmp r2, #2
	beq _080DEC9C
	b _080DECA0
	.align 2, 0
_080DEC94: .4byte 0x030046A4
_080DEC98:
	ldrb r0, [r5, #4]
	b _080DEC9E
_080DEC9C:
	ldrb r0, [r5]
_080DEC9E:
	subs r1, r1, r0
_080DECA0:
	cmp r1, #0
	ble _080DECA6
	b _080DEE64
_080DECA6:
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r6, r7, #0
	adds r6, #0xe0
	movs r3, #0
	ldrsh r1, [r6, r3]
	bl FUN_0823785c
	mov sb, r0
	ldr r5, _080DED08 @ =0x0203B400
	ldr r4, _080DED0C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _080DED10 @ =0x000003FF
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r2, [r1]
	movs r1, #0x1f
	ands r2, r1
	adds r2, #0x3f
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0xf
	ands r1, r0
	mov r4, r8
	mov r5, sb
	adds r3, r5, r2
	adds r5, r1, #0
	adds r5, #8
	ldr r2, _080DED14 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080DED18
	asrs r1, r0, #0xc
	b _080DED1E
	.align 2, 0
_080DED08: .4byte 0x0203B400
_080DED0C: .4byte 0x030046B8
_080DED10: .4byte 0x000003FF
_080DED14: .4byte 0x085B0A08
_080DED18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DED1E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _080DED3C @ =0x085B0A08
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _080DED40
	asrs r0, r0, #0xc
	b _080DED46
	.align 2, 0
_080DED3C: .4byte 0x085B0A08
_080DED40:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DED46:
	strh r0, [r4, #4]
	adds r0, r7, #0
	adds r0, #0xf4
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080DED58
	b _080DEE6C
_080DED58:
	mov r3, r8
	movs r5, #0
	ldrsh r0, [r3, r5]
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl FUN_0823785c
	mov sb, r0
	adds r3, r7, #0
	adds r3, #0xf3
	str r3, [sp, #0x34]
	mov r5, sp
	adds r5, #0x1c
	str r5, [sp, #0x40]
	adds r6, r7, #0
	adds r6, #0xf0
	str r6, [sp, #0x30]
	adds r0, r7, #0
	adds r0, #0x78
	str r0, [sp, #0x24]
	adds r1, r7, #0
	adds r1, #0x7c
	str r1, [sp, #0x28]
	adds r2, r7, #0
	adds r2, #0x80
	str r2, [sp, #0x2c]
	adds r3, #3
	str r3, [sp, #0x38]
	ldr r5, _080DEDE8 @ =0x000003FF
	mov sl, r5
	movs r6, #0xff
	mov r8, r6
	movs r5, #5
	ldr r4, [sp, #0x40]
_080DED9C:
	ldr r1, _080DEDEC @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	lsls r1, r0, #1
	ldr r3, _080DEDF0 @ =0x0203B400
	adds r1, r1, r3
	ldrh r2, [r1]
	mov r6, r8
	ands r2, r6
	adds r0, #1
	mov r1, sl
	ands r0, r1
	ldr r3, _080DEDEC @ =0x030046B8
	str r0, [r3]
	lsls r0, r0, #1
	ldr r6, _080DEDF0 @ =0x0203B400
	adds r0, r0, r6
	ldrh r1, [r0]
	movs r0, #1
	ands r1, r0
	add r2, sb
	adds r3, r1, #4
	ldr r1, _080DEDF4 @ =0x085B0A08
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
	blt _080DEDF8
	asrs r1, r0, #0xc
	b _080DEDFE
	.align 2, 0
_080DEDE8: .4byte 0x000003FF
_080DEDEC: .4byte 0x030046B8
_080DEDF0: .4byte 0x0203B400
_080DEDF4: .4byte 0x085B0A08
_080DEDF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DEDFE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	mov r6, r8
	ands r2, r6
	lsls r0, r2, #1
	ldr r1, _080DEE1C @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080DEE20
	asrs r0, r0, #0xc
	b _080DEE26
	.align 2, 0
_080DEE1C: .4byte 0x085B0A08
_080DEE20:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DEE26:
	strh r0, [r4, #4]
	ldr r6, [sp, #0x30]
	ldrh r3, [r6]
	movs r0, #0xc
	str r0, [sp]
	ldr r1, [sp, #0x24]
	ldrh r0, [r1]
	str r0, [sp, #4]
	ldr r2, [sp, #0x28]
	ldrh r0, [r2]
	str r0, [sp, #8]
	ldr r0, [r7, #0x74]
	str r0, [sp, #0xc]
	ldr r6, [sp, #0x2c]
	ldrh r0, [r6]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x3c]
	ldr r1, [sp, #0x40]
	movs r2, #4
	bl FUN_080df148
	subs r5, #1
	cmp r5, #0
	bge _080DED9C
	movs r0, #3
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	movs r0, #1
	ldr r2, [sp, #0x34]
	strb r0, [r2]
	b _080DEFC0
_080DEE64:
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
_080DEE6C:
	adds r2, r7, #0
	adds r2, #0xf2
	ldrb r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080DEE8C @ =0x085B0A08
	adds r0, r0, r3
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080DEE90
	asrs r1, r0, #0xc
	b _080DEE96
	.align 2, 0
_080DEE8C: .4byte 0x085B0A08
_080DEE90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DEE96:
	adds r3, r7, #0
	adds r3, #0xe6
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
	movs r6, #0
	ldrsh r1, [r3, r6]
	ldr r0, _080DEEB8 @ =0x03002BE0
	ldr r4, [r0]
	movs r5, #0x2e
	ldrsh r0, [r4, r5]
	adds r0, #0xdc
	cmp r1, r0
	ble _080DEEBC
	ldrh r0, [r3]
	subs r0, #4
	b _080DEEC0
	.align 2, 0
_080DEEB8: .4byte 0x03002BE0
_080DEEBC:
	ldrh r0, [r4, #0x2e]
	adds r0, #0xdc
_080DEEC0:
	strh r0, [r3]
	ldrb r0, [r2]
	adds r0, #4
	strb r0, [r2]
	adds r4, r7, #0
	adds r4, #0x2c
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
	beq _080DEEF8
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _080DEF00
_080DEEF8:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DEF00:
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
	beq _080DEF24
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080DEF2C
_080DEF24:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DEF2C:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _080DEF64 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080DEF9C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DEF68
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DEF5C
	ldrb r0, [r4, #5]
_080DEF5C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DEF78
	.align 2, 0
_080DEF64: .4byte 0x0000FFFF
_080DEF68:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DEF78
	strh r1, [r4, #8]
_080DEF78:
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
	bne _080DEF9C
	movs r0, #1
	strb r0, [r4, #7]
_080DEF9C:
	adds r0, r7, #0
	bl FUN_080de7a0
	adds r1, r7, #0
	adds r1, #0xf0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080DEFB2
	subs r0, #1
	strh r0, [r1]
	b _080DEFC0
_080DEFB2:
	adds r1, r7, #0
	adds r1, #0xf6
	movs r0, #3
	strb r0, [r1]
	subs r1, #3
	movs r0, #1
	strb r0, [r1]
_080DEFC0:
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
