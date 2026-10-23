	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081eeed8
FUN_081eeed8: @ 0x081EEED8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081eeedc
FUN_081eeedc: @ 0x081EEEDC
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	ldr r0, _081EEEF8 @ =0x00000838
	adds r4, r2, r0
	movs r5, #1
_081EEEE8:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081EEEFC
	movs r0, #1
	b _081EEEFE
	.align 2, 0
_081EEEF8: .4byte 0x00000838
_081EEEFC:
	movs r0, #0
_081EEEFE:
	cmp r0, #0
	bne _081EEF1C
	movs r0, #0xd0
	muls r0, r3, r0
	adds r0, #0x18
	adds r0, r2, r0
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	adds r1, r0, #0
	adds r1, #0xbd
	strb r3, [r1]
	b _081EEF24
_081EEF1C:
	adds r3, #1
	cmp r3, #9
	ble _081EEEE8
	movs r0, #0
_081EEF24:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081eef2c
FUN_081eef2c: @ 0x081EEF2C
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

	thumb_func_start FUN_081ef3fc
FUN_081ef3fc: @ 0x081EF3FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r1, #0
	mov ip, r5
	adds r2, r5, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EF420
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0
	strb r0, [r2]
_081EF420:
	adds r0, r5, #0
	adds r0, #0x1c
	ldrh r1, [r5, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r0
	cmp r2, #0
	blt _081EF44A
	cmp r1, #0
	blt _081EF44A
	ldr r0, _081EF450 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081EF44A
	ldr r0, _081EF454 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081EF458
_081EF44A:
	movs r1, #0
	b _081EF466
	.align 2, 0
_081EF450: .4byte 0x030046A8
_081EF454: .4byte 0x030046AC
_081EF458:
	ldr r0, _081EF4A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081EF466:
	adds r0, r5, #0
	adds r0, #0xc8
	strh r1, [r0]
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x2c]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EF4A4
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081EF4B0
	.align 2, 0
_081EF4A0: .4byte 0x030046A4
_081EF4A4:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081EF4B0:
	str r0, [r2]
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
	beq _081EF4D6
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081EF4E0
_081EF4D6:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EF4E0:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EF51C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081EF562
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EF526
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EF520
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r7, #1
	b _081EF53C
	.align 2, 0
_081EF51C: .4byte 0x0000FFFF
_081EF520:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EF53A
_081EF526:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EF53A
	strh r1, [r4, #8]
	movs r7, #1
	b _081EF53C
_081EF53A:
	movs r7, #0
_081EF53C:
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
	bne _081EF564
	movs r0, #1
	strb r0, [r4, #7]
	b _081EF564
_081EF562:
	movs r7, #0
_081EF564:
	adds r0, r5, #0
	adds r0, #0xb7
	ldrb r1, [r0]
	movs r0, #1
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	beq _081EF588
	adds r4, r5, #0
	adds r4, #0x58
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_081EF588:
	adds r6, r5, #0
	adds r6, #0xc6
	ldrh r0, [r6]
	cmp r0, #0
	beq _081EF596
	cmp r7, #0
	beq _081EF5DC
_081EF596:
	ldr r0, _081EF5D4 @ =0x030001DC
	ldr r2, [r0]
	adds r7, r5, #0
	adds r7, #0xbd
	movs r0, #0
	ldrsb r0, [r7, r0]
	ldr r1, _081EF5D8 @ =0x00000838
	adds r2, r2, r1
	mov r1, r8
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r7]
	adds r0, r5, #0
	adds r0, #0xba
	strh r4, [r0]
	strh r4, [r6]
	adds r0, #0xa
	mov r2, r8
	strb r2, [r0]
	b _081EF5E0
	.align 2, 0
_081EF5D4: .4byte 0x030001DC
_081EF5D8: .4byte 0x00000838
_081EF5DC:
	subs r0, #1
	strh r0, [r6]
_081EF5E0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ef5ec
FUN_081ef5ec: @ 0x081EF5EC
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r2, r5, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	cmp r0, #0
	beq _081EF604
	movs r1, #0
	strb r1, [r2]
	adds r0, r5, #0
	adds r0, #0xb8
	strh r1, [r0]
_081EF604:
	adds r4, r5, #0
	adds r4, #0xb8
	ldrh r1, [r4]
	adds r0, r5, #0
	movs r2, #0x3c
	movs r3, #0x28
	bl Sprite_UpdateVanishBlink
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081EF65C
	ldr r0, _081EF654 @ =0x030001DC
	ldr r2, [r0]
	adds r6, r5, #0
	adds r6, #0xbd
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _081EF658 @ =0x00000838
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	adds r0, #0xbc
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0xba
	strh r4, [r0]
	adds r0, #0xc
	strh r4, [r0]
	b _081EF662
	.align 2, 0
_081EF654: .4byte 0x030001DC
_081EF658: .4byte 0x00000838
_081EF65C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081EF662:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081ef668
FUN_081ef668: @ 0x081EF668
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ef66c
FUN_081ef66c: @ 0x081EF66C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r6, r3, #0
	ldr r7, [sp, #0x38]
	ldr r2, _081EF6F8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _081EF6FC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x58
	ldr r2, _081EF700 @ =0x00002001
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r1, _081EF704 @ =FUN_081ef668
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EF6F8: .4byte 0xFFFF0000
_081EF6FC: .4byte 0x0000FFFF
_081EF700: .4byte 0x00002001
_081EF704: .4byte FUN_081ef668

	thumb_func_start FUN_081ef708
FUN_081ef708: @ 0x081EF708
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r5, r1, #0
	mov r8, r2
	mov sl, r3
	ldr r0, _081EF760 @ =0x030001DC
	ldr r3, [r0]
	cmp r3, #0
	bne _081EF72E
	bl Entity081efa9c_Create
	adds r3, r0, #0
	cmp r3, #0
	beq _081EF75A
_081EF72E:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EF764 @ =0x030047A4
	ldr r1, _081EF768 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EF75A
	movs r1, #4
	ldr r0, _081EF76C @ =0x03002BC0
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081EF75A
	adds r0, r3, #0
	bl FUN_081eeedc
	adds r6, r0, #0
	cmp r6, #0
	bne _081EF770
_081EF75A:
	movs r0, #0
	b _081EF98A
	.align 2, 0
_081EF760: .4byte 0x030001DC
_081EF764: .4byte 0x030047A4
_081EF768: .4byte 0x030047A0
_081EF76C: .4byte 0x03002BC0
_081EF770:
	adds r0, r6, #0
	adds r0, #0xba
	movs r3, #0
	strh r4, [r0]
	adds r0, #0xa
	movs r4, #1
	strb r4, [r0]
	adds r2, r6, #0
	adds r2, #0xac
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r6, #0
	adds r1, #0xc6
	ldr r0, [sp, #0x2c]
	strh r0, [r1]
	subs r1, #0xf
	ldr r0, [sp, #0x34]
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0xc0
	mov r2, r8
	str r2, [r0]
	adds r0, #5
	strb r3, [r0]
	ldrb r0, [r1]
	str r1, [sp, #4]
	cmp r0, #0
	bne _081EF7B4
	adds r0, r6, #0
	adds r0, #0xbc
	strb r4, [r0]
	b _081EF7BC
_081EF7B4:
	adds r1, r6, #0
	adds r1, #0xbc
	movs r0, #2
	strb r0, [r1]
_081EF7BC:
	adds r7, r6, #0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x3c
	adds r0, r5, #0
	mov r1, r8
	bl Video_GetAuxSprite
	ldr r0, _081EF844 @ =0x0000922E
	mov r2, sl
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	bl GetFile
	adds r4, r6, #0
	adds r4, #0xa8
	str r0, [r4]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	subs r5, #0x10
	ldr r1, [r4]
	ldr r2, [sp, #0x28]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r3, [sp, #0x3c]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r0, [sp, #0x40]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r5, #0
	bl AuxAnim_SetAnim
	ldr r0, [r6, #0xc]
	ldr r1, [sp, #0x38]
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r5, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081EF848
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081EF850
	.align 2, 0
_081EF844: .4byte 0x0000922E
_081EF848:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081EF850:
	str r0, [r6]
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
	beq _081EF874
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081EF87C
_081EF874:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EF87C:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081EF8B4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081EF8EC
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EF8B8
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081EF8AC
	ldrb r0, [r5, #5]
_081EF8AC:
	subs r0, #1
	strh r0, [r5, #8]
	b _081EF8C8
	.align 2, 0
_081EF8B4: .4byte 0x0000FFFF
_081EF8B8:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081EF8C8
	strh r1, [r5, #8]
_081EF8C8:
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
	bne _081EF8EC
	movs r0, #1
	strb r0, [r5, #7]
_081EF8EC:
	ldr r0, [r7]
	movs r4, #1
	orrs r0, r4
	strb r4, [r7, #7]
	ldr r1, [sp, #0x30]
	orrs r0, r1
	str r0, [r7]
	movs r0, #2
	ands r1, r0
	cmp r1, #0
	beq _081EF968
	ldr r3, _081EF938 @ =0x0203B400
	ldr r1, _081EF93C @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _081EF940 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r7, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrb r0, [r0]
	adds r2, r1, #0
	cmp r0, #0x7f
	bgt _081EF944
	adds r1, r6, #0
	adds r1, #0xb5
	movs r0, #0xff
	strb r0, [r1]
	b _081EF94A
	.align 2, 0
_081EF938: .4byte 0x0203B400
_081EF93C: .4byte 0x030046B8
_081EF940: .4byte 0x000003FF
_081EF944:
	adds r0, r6, #0
	adds r0, #0xb5
	strb r4, [r0]
_081EF94A:
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081EF99C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081EF9A0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	adds r1, r6, #0
	adds r1, #0xb6
	strb r0, [r1]
_081EF968:
	ldr r0, [sp, #0x44]
	cmp r0, #0
	ble _081EF988
	ldr r0, [sp, #0x50]
	str r0, [sp]
	adds r0, r6, #0
	ldr r1, [sp, #0x44]
	ldr r2, [sp, #0x48]
	ldr r3, [sp, #0x4c]
	bl FUN_081ef66c
	ldr r2, [sp, #4]
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
_081EF988:
	adds r0, r6, #0
_081EF98A:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EF99C: .4byte 0x000003FF
_081EF9A0: .4byte 0x0203B400

	thumb_func_start Entity081efa9c_Update
Entity081efa9c_Update: @ 0x081EF9A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x18
	ldr r1, _081EF9F4 @ =0x00000838
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EFA2E
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EF9F8 @ =0x030047A4
	ldr r1, _081EF9FC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EFA2E
	movs r1, #4
	ldr r0, _081EFA00 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081EFA2E
	movs r4, #0
	ldr r0, _081EF9F4 @ =0x00000838
	adds r6, r5, r0
	ldr r1, _081EFA04 @ =0x085AE4F8
	mov r8, r1
_081EF9E4:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EFA08
	movs r0, #1
	b _081EFA0A
	.align 2, 0
_081EF9F4: .4byte 0x00000838
_081EF9F8: .4byte 0x030047A4
_081EF9FC: .4byte 0x030047A0
_081EFA00: .4byte 0x03002BC0
_081EFA04: .4byte 0x085AE4F8
_081EFA08:
	movs r0, #0
_081EFA0A:
	cmp r0, #0
	beq _081EFA28
	movs r0, #0xd0
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081EFA28:
	adds r4, #1
	cmp r4, #9
	ble _081EF9E4
_081EFA2E:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081efa9c_Destroy
Entity081efa9c_Destroy: @ 0x081EFA3C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r4, #0
	ldr r0, _081EFA58 @ =0x00000838
	adds r6, r5, r0
_081EFA46:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EFA5C
	movs r0, #1
	b _081EFA5E
	.align 2, 0
_081EFA58: .4byte 0x00000838
_081EFA5C:
	movs r0, #0
_081EFA5E:
	cmp r0, #0
	beq _081EFA6E
	movs r0, #0xd0
	muls r0, r4, r0
	adds r0, #0x18
	adds r0, r5, r0
	bl AuxSprite_Remove
_081EFA6E:
	adds r4, #1
	cmp r4, #9
	ble _081EFA46
	ldr r1, _081EFA80 @ =0x030001DC
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081EFA80: .4byte 0x030001DC

	thumb_func_start Entity081efa9c_Init
Entity081efa9c_Init: @ 0x081EFA84
	ldr r1, _081EFA94 @ =0x00000838
	adds r2, r0, r1
	movs r1, #0
	str r1, [r2]
	ldr r1, _081EFA98 @ =0x030001DC
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_081EFA94: .4byte 0x00000838
_081EFA98: .4byte 0x030001DC

	thumb_func_start Entity081efa9c_Create
Entity081efa9c_Create: @ 0x081EFA9C
	push {r4, lr}
	ldr r0, _081EFAD0 @ =0x030001DC
	ldr r0, [r0]
	cmp r0, #0
	bne _081EFAE2
	ldr r1, _081EFAD4 @ =0x0000083C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EFAE0
	ldr r1, _081EFAD8 @ =Entity081efa9c_Update
	ldr r2, _081EFADC @ =Entity081efa9c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081efa9c_Init
	cmp r0, #0
	bge _081EFAE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081EFAE2
	.align 2, 0
_081EFAD0: .4byte 0x030001DC
_081EFAD4: .4byte 0x0000083C
_081EFAD8: .4byte Entity081efa9c_Update
_081EFADC: .4byte Entity081efa9c_Destroy
_081EFAE0:
	adds r0, r4, #0
_081EFAE2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081efae8
FUN_081efae8: @ 0x081EFAE8
	ldr r1, _081EFAF0 @ =0x030001DC
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EFAF0: .4byte 0x030001DC
