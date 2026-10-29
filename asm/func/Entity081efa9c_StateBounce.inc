	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r1, #0
	mov sl, r6
	adds r2, r6, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EEF54
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r0, #0
	strb r0, [r2]
_081EEF54:
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r0, [sp, #0x14]
	cmp r2, #0
	blt _081EEF7E
	cmp r1, #0
	blt _081EEF7E
	ldr r0, _081EEF84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EEF7E
	ldr r0, _081EEF88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EEF8C
_081EEF7E:
	movs r1, #0
	b _081EEF9A
	.align 2, 0
_081EEF84: .4byte 0x030046A8
_081EEF88: .4byte 0x030046AC
_081EEF8C:
	ldr r0, _081EEFCC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081EEF9A:
	adds r0, r6, #0
	adds r0, #0xc8
	strh r1, [r0]
	movs r1, #0x1c
	add r1, sl
	mov r8, r1
	adds r4, r6, #0
	adds r4, #0xac
	ldrh r0, [r0]
	str r0, [sp, #8]
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	bl ArcTan2_8
	ldr r0, [sp, #8]
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EEFD0
	adds r0, #4
	b _081EEFDE
	.align 2, 0
_081EEFCC: .4byte 0x030046A4
_081EEFD0:
	ldr r0, _081EEFF4 @ =0x030046A4
	ldr r1, [r0]
	ldr r2, [sp, #8]
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EEFDE:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EEFF8
	cmp r2, #2
	beq _081EEFFE
	b _081EF004
	.align 2, 0
_081EEFF4: .4byte 0x030046A4
_081EEFF8:
	mov r3, r8
	ldrb r0, [r3, #4]
	b _081EF002
_081EEFFE:
	mov r2, r8
	ldrb r0, [r2]
_081EF002:
	subs r1, r1, r0
_081EF004:
	str r1, [sp, #0xc]
	mov r3, r8
	movs r1, #2
	ldrsh r0, [r3, r1]
	ldr r2, [sp, #0xc]
	cmp r0, r2
	ble _081EF018
	ldrh r0, [r4, #2]
	subs r0, #4
	strh r0, [r4, #2]
_081EF018:
	mov r2, sp
	mov r3, r8
	ldrh r0, [r3]
	ldrh r1, [r4]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r3, [r4, #2]
	adds r1, r0, r3
	strh r1, [r2, #2]
	mov r3, r8
	ldrh r0, [r3, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r3, #2
	ldrsh r0, [r2, r3]
	ldr r2, [sp, #0xc]
	cmp r0, r2
	bge _081EF11C
	movs r3, #0
	ldrsh r1, [r4, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r4]
	movs r1, #2
	ldrsh r0, [r4, r1]
	lsls r0, r0, #2
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r1, [r4, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	strh r0, [r4, #4]
	ldr r0, [r6]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _081EF088
	adds r1, r6, #0
	adds r1, #0xb5
	movs r0, #0
	ldrsb r0, [r1, r0]
	rsbs r0, r0, #0
	strb r0, [r1]
_081EF088:
	adds r0, r6, #0
	adds r0, #0xc5
	ldrb r1, [r0]
	str r0, [sp, #0x10]
	cmp r1, #0
	bne _081EF0D0
	subs r0, #5
	ldr r2, [r0]
	ldr r1, _081EF0B0 @ =0x0000B96C
	adds r3, r0, #0
	cmp r2, r1
	bne _081EF0B4
	ldrh r0, [r6, #0x36]
	cmp r0, #6
	bne _081EF0B4
	movs r0, #0xf1
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _081EF0CA
	.align 2, 0
_081EF0B0: .4byte 0x0000B96C
_081EF0B4:
	ldr r1, [r3]
	ldr r0, _081EF118 @ =0x0000D45E
	cmp r1, r0
	bne _081EF0CA
	ldrh r0, [r6, #0x36]
	cmp r0, #6
	bne _081EF0CA
	movs r0, #0xec
	lsls r0, r0, #2
	bl PlaySound_082406e0
_081EF0CA:
	movs r0, #0xa
	ldr r3, [sp, #0x10]
	strb r0, [r3]
_081EF0D0:
	mov r0, sp
	ldrh r1, [r0, #0xc]
	mov r0, r8
	strh r1, [r0, #2]
	movs r2, #0
	ldrsh r0, [r4, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	cmp r1, #0
	bne _081EF126
	strh r1, [r4]
	strh r1, [r4, #2]
	strh r1, [r4, #4]
	adds r1, r6, #0
	adds r1, #0xb5
	movs r0, #0
	strb r0, [r1]
	adds r1, #7
	movs r0, #3
	strb r0, [r1]
	adds r1, #8
	movs r0, #1
	strb r0, [r1]
	b _081EF298
	.align 2, 0
_081EF118: .4byte 0x0000D45E
_081EF11C:
	mov r3, r8
	strh r1, [r3, #2]
	adds r0, r6, #0
	adds r0, #0xc5
	str r0, [sp, #0x10]
_081EF126:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081EF14E
	cmp r1, #0
	blt _081EF14E
	ldr r0, _081EF154 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EF14E
	ldr r0, _081EF158 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EF15C
_081EF14E:
	movs r5, #0
	b _081EF16A
	.align 2, 0
_081EF154: .4byte 0x030046A8
_081EF158: .4byte 0x030046AC
_081EF15C:
	ldr r0, _081EF17C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081EF16A:
	mov r7, sp
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EF180
	adds r0, #4
	b _081EF18C
	.align 2, 0
_081EF17C: .4byte 0x030046A4
_081EF180:
	ldr r0, _081EF1A0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EF18C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081EF1A4
	cmp r2, #2
	beq _081EF1A8
	b _081EF1AC
	.align 2, 0
_081EF1A0: .4byte 0x030046A4
_081EF1A4:
	ldrb r0, [r7, #4]
	b _081EF1AA
_081EF1A8:
	ldrb r0, [r7]
_081EF1AA:
	subs r1, r1, r0
_081EF1AC:
	mov sb, r1
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EF1BE
	adds r0, #4
	b _081EF1CA
_081EF1BE:
	ldr r0, _081EF1E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EF1CA:
	ldrh r7, [r0, #2]
	ldr r1, [sp, #8]
	cmp r1, r5
	beq _081EF226
	ldr r2, [sp, #0xc]
	cmp r2, sb
	blt _081EF202
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081EF1EC
	adds r0, #4
	b _081EF1F8
	.align 2, 0
_081EF1E8: .4byte 0x030046A4
_081EF1EC:
	ldr r0, _081EF278 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081EF1F8:
	ldrh r0, [r0, #2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _081EF226
_081EF202:
	movs r3, #0
	ldrsh r1, [r4, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4]
	movs r0, #4
	ldrsh r1, [r4, r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #4]
_081EF226:
	mov r1, sb
	cmp r1, #0
	ble _081EF234
	movs r0, #0x40
	ands r7, r0
	cmp r7, #0
	beq _081EF284
_081EF234:
	mov r0, sp
	movs r2, #2
	ldrsh r0, [r0, r2]
	cmp r0, sb
	bgt _081EF284
	ldr r0, _081EF27C @ =0x030001DC
	ldr r2, [r0]
	adds r5, r6, #0
	adds r5, #0xbd
	movs r0, #0
	ldrsb r0, [r5, r0]
	ldr r3, _081EF280 @ =0x00000838
	adds r2, r2, r3
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r6, #0
	adds r0, #0xbc
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r5]
	adds r0, r6, #0
	adds r0, #0xba
	strh r4, [r0]
	adds r0, #0xc
	strh r4, [r0]
	adds r7, r0, #0
	b _081EF29C
	.align 2, 0
_081EF278: .4byte 0x030046A4
_081EF27C: .4byte 0x030001DC
_081EF280: .4byte 0x00000838
_081EF284:
	ldrh r0, [r4]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2]
	ldrh r0, [r4, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
_081EF298:
	adds r7, r6, #0
	adds r7, #0xc6
_081EF29C:
	mov r1, sl
	ldr r0, [r1]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _081EF2C2
	adds r0, r6, #0
	adds r0, #0xb6
	ldrb r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	muls r0, r1, r0
	mov r2, sl
	ldrb r2, [r2, #6]
	adds r0, r0, r2
	mov r3, sl
	strb r0, [r3, #6]
_081EF2C2:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, sl
	strh r0, [r1, #0x10]
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
	beq _081EF2F8
	mov r2, sl
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	str r0, [r2]
	b _081EF304
_081EF2F8:
	mov r3, sl
	ldr r0, [r3]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081EF304:
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
	beq _081EF32C
	mov r1, sl
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, sl
	str r0, [r2]
	b _081EF338
_081EF32C:
	mov r3, sl
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_081EF338:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EF36C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081EF3A4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EF370
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EF366
	ldrb r0, [r4, #5]
_081EF366:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EF380
	.align 2, 0
_081EF36C: .4byte 0x0000FFFF
_081EF370:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EF380
	strh r1, [r4, #8]
_081EF380:
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
	bne _081EF3A4
	movs r0, #1
	strb r0, [r4, #7]
_081EF3A4:
	adds r0, r6, #0
	adds r0, #0xb7
	ldrb r1, [r0]
	movs r5, #1
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _081EF3C8
	adds r4, r6, #0
	adds r4, #0x58
	adds r0, r4, #0
	ldr r1, [sp, #0x14]
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081EF3C8:
	ldr r3, [sp, #0x10]
	ldrb r0, [r3]
	cmp r0, #0
	beq _081EF3D4
	subs r0, #1
	strb r0, [r3]
_081EF3D4:
	ldrh r0, [r7]
	cmp r0, #0
	beq _081EF3E0
	subs r0, #1
	strh r0, [r7]
	b _081EF3EC
_081EF3E0:
	adds r0, r6, #0
	adds r0, #0xbc
	movs r1, #3
	strb r1, [r0]
	adds r0, #8
	strb r5, [r0]
_081EF3EC:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
