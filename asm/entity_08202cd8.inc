	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08200ab4
FUN_08200ab4: @ 0x08200AB4
	push {r4, r5, lr}
	adds r5, r0, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08200ADC
	cmp r1, #0
	blt _08200ADC
	ldr r0, _08200AE0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08200ADC
	ldr r0, _08200AE4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08200AE8
_08200ADC:
	movs r4, #0
	b _08200AF6
	.align 2, 0
_08200AE0: .4byte 0x030046A8
_08200AE4: .4byte 0x030046AC
_08200AE8:
	ldr r0, _08200B08 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08200AF6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08200B0C
	adds r0, #4
	b _08200B18
	.align 2, 0
_08200B08: .4byte 0x030046A4
_08200B0C:
	ldr r0, _08200B28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08200B18:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #2]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08200B28: .4byte 0x030046A4

	thumb_func_start FUN_08200b2c
FUN_08200b2c: @ 0x08200B2C
	ldr r2, _08200B34 @ =0x000006DB
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_08200B34: .4byte 0x000006DB

	thumb_func_start FUN_08200b38
FUN_08200b38: @ 0x08200B38
	push {lr}
	ldr r0, [r0, #0xc]
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	pop {r0}
	bx r0

	thumb_func_start FUN_08200b48
FUN_08200b48: @ 0x08200B48
	push {lr}
	ldr r0, [r0, #0xc]
	ldr r1, _08200B58 @ =0x00000231
	bl Video_SetAuxSpritePltt
	pop {r0}
	bx r0
	.align 2, 0
_08200B58: .4byte 0x00000231

	thumb_func_start FUN_08200b5c
FUN_08200b5c: @ 0x08200B5C
	push {lr}
	sub sp, #0x4c
	ldr r1, _08200B88 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	ldr r2, [r0, #0x44]
	ldr r3, [r0, #0x48]
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	movs r0, #0
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	add r0, sp, #8
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_081ea540
	add sp, #0x4c
	pop {r0}
	bx r0
	.align 2, 0
_08200B88: .4byte 0x03002BE0

	thumb_func_start FUN_08200b8c
FUN_08200b8c: @ 0x08200B8C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x24
	ldrb r0, [r1]
	cmp r0, #0
	beq _08200BC2
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08200BC2
	adds r4, r7, #0
	adds r4, #0x28
	movs r5, #7
_08200BB2:
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_08200b48
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _08200BB2
_08200BC2:
	adds r1, r7, #0
	adds r1, #0x25
	ldrb r0, [r1]
	mov sb, r0
	cmp r0, #0
	beq _08200BD4
	subs r0, #1
	strb r0, [r1]
	b _08200C72
_08200BD4:
	ldr r0, _08200C80 @ =0x000006EC
	adds r0, r0, r7
	mov r8, r0
	ldr r0, [r0]
	cmp r0, #0
	ble _08200C72
	bl FUN_081fa608
	add r2, sp, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r3, r7, r1
	adds r4, r7, #0
	adds r4, #0x44
	ldrh r0, [r3]
	ldrh r5, [r4]
	subs r0, r0, r5
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r6, [r4, #2]
	subs r0, r0, r6
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r3, [r4, #4]
	subs r0, r0, r3
	strh r0, [r2, #4]
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r1]
	ldrh r0, [r2, #2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	strh r0, [r2, #4]
	adds r0, r1, #0
	ldrh r0, [r0]
	adds r5, r5, r0
	adds r0, r1, #0
	strh r5, [r0]
	ldrh r0, [r2, #2]
	adds r0, r0, r6
	strh r0, [r2, #2]
	ldrh r0, [r2, #4]
	adds r3, r3, r0
	strh r3, [r2, #4]
	ldr r4, _08200C84 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r3, #0x10
	orrs r0, r3
	ldr r1, _08200C88 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	orrs r0, r3
	str r0, [r2, #4]
	movs r1, #0x82
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r3, r8
	ldr r1, [r3]
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	add r3, sp, #8
	bl FUN_0805fe7c
	mov r0, sb
	mov r1, r8
	str r0, [r1]
_08200C72:
	add sp, #0x18
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08200C80: .4byte 0x000006EC
_08200C84: .4byte 0xFFFF0000
_08200C88: .4byte 0x0000FFFF

	thumb_func_start FUN_08200c8c
FUN_08200c8c: @ 0x08200C8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r2, r0, #0
	ldr r1, _08200CD4 @ =0x000006DC
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _08200D5E
	subs r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08200CB8
	adds r0, r2, #0
	adds r0, #0x25
	ldrb r1, [r0]
	mov sl, r0
	cmp r1, #0
	beq _08200CD8
_08200CB8:
	movs r0, #0x82
	lsls r0, r0, #3
	adds r4, r2, r0
	movs r1, #4
	movs r5, #7
_08200CC2:
	ldrh r0, [r4, #6]
	orrs r0, r1
	strh r0, [r4, #6]
	adds r4, #0x50
	subs r5, #1
	cmp r5, #0
	bge _08200CC2
	b _08200D5E
	.align 2, 0
_08200CD4: .4byte 0x000006DC
_08200CD8:
	ldr r0, _08200D6C @ =0x03002CF0
	ldr r1, [r0]
	movs r0, #3
	ands r1, r0
	movs r0, #0x28
	adds r0, r0, r2
	mov r8, r0
	movs r0, #0xc8
	lsls r0, r0, #1
	adds r7, r2, r0
	movs r0, #0x82
	lsls r0, r0, #3
	adds r4, r2, r0
	movs r0, #0x2c
	muls r0, r1, r0
	add r8, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	adds r7, r7, r0
	adds r4, r4, r0
	adds r5, r1, #0
	cmp r5, #7
	bgt _08200D5E
	movs r1, #4
	mov sb, r1
_08200D0C:
	mov r6, r8
	adds r6, #0x1c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r2, sb
	mvns r0, r2
	ldrh r1, [r4, #6]
	ands r0, r1
	strh r0, [r4, #6]
	adds r0, r5, #1
	cmp r0, #7
	bgt _08200D34
	adds r1, r4, #0
	adds r1, #0x50
	ldrh r0, [r1, #6]
	orrs r0, r2
	strh r0, [r1, #6]
_08200D34:
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08200D4C
	adds r0, r7, #0
	bl Hitbox_Register
_08200D4C:
	movs r2, #0xb0
	add r8, r2
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r5, #4
	cmp r5, #7
	ble _08200D0C
_08200D5E:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08200D6C: .4byte 0x03002CF0

	thumb_func_start FUN_08200d70
FUN_08200d70: @ 0x08200D70
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov sl, r1
	mov r4, sp
	movs r0, #0x1c
	add r0, sl
	mov r8, r0
	mov r7, sb
	adds r7, #0x1c
	ldrh r0, [r1, #0x1c]
	mov r3, sb
	ldrh r1, [r3, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	mov r1, r8
	ldrh r0, [r1, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	mov r3, r8
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _08200E4C @ =0x085AE7C8
	lsls r2, r2, #1
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r1, r0
	ble _08200E3C
	ldr r0, _08200E50 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08200E1C
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	mov r1, sp
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r3, #4
	ldrsh r0, [r4, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_08200E1C:
	mov r0, sp
	ldrh r0, [r0]
	mov r1, sb
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, sl
	strh r0, [r2, #0x1c]
	ldrh r0, [r4, #2]
	ldrh r3, [r7, #2]
	adds r0, r0, r3
	mov r1, r8
	strh r0, [r1, #2]
	ldrh r0, [r4, #4]
	ldrh r7, [r7, #4]
	adds r0, r0, r7
	strh r0, [r1, #4]
_08200E3C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08200E4C: .4byte 0x085AE7C8
_08200E50: .4byte 0x085AE7B8

	thumb_func_start FUN_08200e54
FUN_08200e54: @ 0x08200E54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov ip, r0
	ldr r0, _08200EB0 @ =0x000006DA
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #0
	beq _08200E6E
	b _08201042
_08200E6E:
	movs r7, #0
	mov r0, ip
	adds r0, #0x28
	str r0, [sp, #0x48]
	ldr r1, _08200EB4 @ =0x030047C8
	mov sb, r1
	add r2, sp, #0x40
	mov sl, r2
	movs r3, #0x42
	add r3, sp
	mov r8, r3
	mov r6, sb
	mov r4, sp
_08200E88:
	movs r0, #0x2c
	adds r2, r7, #0
	muls r2, r0, r2
	add r2, ip
	adds r2, #0x44
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r5, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08200EB8
	asrs r0, r0, #8
	b _08200EBE
	.align 2, 0
_08200EB0: .4byte 0x000006DA
_08200EB4: .4byte 0x030047C8
_08200EB8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200EBE:
	strh r0, [r4]
	adds r1, r5, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08200ED0
	asrs r0, r0, #8
	b _08200ED6
_08200ED0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200ED6:
	adds r3, r0, #0
	movs r5, #2
	ldrsh r1, [r2, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08200EEA
	asrs r0, r0, #8
	b _08200EF0
_08200EEA:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200EF0:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r4]
	ldrh r1, [r6]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r6, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r6, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	adds r4, #8
	adds r7, #1
	cmp r7, #7
	ble _08200E88
	movs r0, #0xbc
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	mov r1, r8
	ldrh r0, [r1]
	subs r0, #0x40
	strh r0, [r1]
	mov r4, sl
	adds r5, r4, #0
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08200F4A
	asrs r0, r0, #8
	b _08200F50
_08200F4A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200F50:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08200F62
	asrs r0, r0, #8
	b _08200F68
_08200F62:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200F68:
	adds r3, r0, #0
	movs r2, #2
	ldrsh r1, [r5, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08200F7C
	asrs r0, r0, #8
	b _08200F82
_08200F7C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08200F82:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r4]
	mov r5, sb
	ldrh r1, [r5]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r5, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r5, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	ldr r6, [sp, #0x48]
	mov r2, sp
	movs r7, #0
	movs r0, #0xc4
	lsls r0, r0, #1
	add r0, ip
	mov r8, r0
	movs r5, #0xc4
	lsls r5, r5, #1
	add r5, ip
_08200FB4:
	cmp r7, #0
	bne _08200FEE
	adds r4, r2, #0
	adds r4, #8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #8
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #2
	ldrsh r1, [r2, r3]
	movs r3, #2
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	subs r0, #0x1f
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	mov r0, r8
	strb r1, [r0]
	b _08201024
_08200FEE:
	adds r4, r2, #0
	adds r4, #8
	adds r3, r2, #0
	subs r3, #8
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r1, #8
	ldrsh r2, [r2, r1]
	subs r0, r0, r2
	movs r2, #2
	ldrsh r1, [r3, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	subs r0, #0x1f
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5]
_08201024:
	cmp r7, #2
	ble _08201032
	cmp r7, #4
	bgt _08201032
	ldrb r0, [r5]
	adds r0, #8
	b _08201034
_08201032:
	ldrb r0, [r5]
_08201034:
	strh r0, [r6, #0x10]
	adds r6, #0x2c
	adds r2, r4, #0
	adds r5, #1
	adds r7, #1
	cmp r7, #7
	ble _08200FB4
_08201042:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08201054
FUN_08201054: @ 0x08201054
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r4, r1, #0
	ldr r2, _082010B0 @ =0x00000694
	add r2, r8
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r7, #0
	movs r6, #0x82
	lsls r6, r6, #3
	add r6, r8
	movs r5, #0xc8
	lsls r5, r5, #1
	add r5, r8
_08201078:
	movs r0, #0x2c
	adds r2, r7, #0
	muls r2, r0, r2
	add r2, r8
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2, #0x44]
	str r1, [r2, #0x48]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r6, #0x50
	adds r5, #0x50
	adds r7, #1
	cmp r7, #7
	ble _08201078
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082010B0: .4byte 0x00000694

	thumb_func_start FUN_082010b4
FUN_082010b4: @ 0x082010B4
	push {lr}
	adds r1, r0, #0
	adds r1, #0x28
	movs r3, #1
	movs r2, #7
_082010BE:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _082010BE
	pop {r0}
	bx r0

	thumb_func_start FUN_082010d0
FUN_082010d0: @ 0x082010D0
	push {lr}
	adds r1, r0, #0
	adds r1, #0x28
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #7
_082010DC:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _082010DC
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082010f0
FUN_082010f0: @ 0x082010F0
	strh r1, [r0, #0x20]
	strh r2, [r0, #0x22]
	bx lr
	.align 2, 0

	thumb_func_start FUN_082010f8
FUN_082010f8: @ 0x082010F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x64
	mov sl, r0
	str r1, [sp, #0x54]
	mov r0, sp
	adds r0, #0x3c
	str r0, [sp, #0x60]
	cmp r1, #0
	bne _082011CA
	ldr r0, _082013A4 @ =0x00000694
	add r0, sl
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r0, _082013A8 @ =0x00000696
	add r0, sl
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xd3
	lsls r0, r0, #3
	add r0, sl
	movs r7, #0
	ldrsh r0, [r0, r7]
	subs r1, #0x64
	ldr r3, [sp, #0x60]
	strh r2, [r3]
	strh r1, [r3, #2]
	strh r0, [r3, #4]
	add r6, sp, #0x44
	add r5, sp, #0x4c
	mov r0, sl
	adds r0, #0x44
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	movs r7, #7
	mov sb, r7
_08201146:
	str r1, [r0]
	str r2, [r0, #4]
	adds r0, #0x2c
	movs r3, #1
	rsbs r3, r3, #0
	add sb, r3
	mov r7, sb
	cmp r7, #0
	bge _08201146
	movs r4, #0
	mov r0, sl
	str r4, [r0, #0x1c]
	str r4, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r6, #0
	ldr r2, _082013AC @ =0x05000002
	bl CpuSet
	ldr r0, _082013A4 @ =0x00000694
	add r0, sl
	movs r1, #0
	ldrsh r3, [r0, r1]
	ldr r0, _082013A8 @ =0x00000696
	add r0, sl
	movs r7, #0
	ldrsh r2, [r0, r7]
	movs r0, #0xd3
	lsls r0, r0, #3
	add r0, sl
	movs r7, #0
	ldrsh r1, [r0, r7]
	adds r3, #0x40
	subs r2, #0x20
	adds r1, #0x40
	add r0, sp, #0x4c
	strh r3, [r0]
	strh r2, [r5, #2]
	strh r1, [r5, #4]
	ldr r2, _082013B0 @ =0x0000F422
	ldr r3, _082013B4 @ =0x0000121B
	movs r0, #6
	str r0, [sp]
	str r4, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _082013B8 @ =0x00000237
	str r0, [sp, #0xc]
	movs r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_081f22c0
	movs r0, #0xdb
	lsls r0, r0, #1
	bl PlaySound_082406e0
_082011CA:
	movs r0, #0
	str r0, [sp, #0x58]
	mov sb, r0
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, sl
	mov r1, sl
	adds r1, #0x46
_082011DA:
	ldrh r0, [r1]
	adds r0, #0x1c
	mov r3, sb
	subs r0, r0, r3
	strh r0, [r1]
	adds r1, #0x2c
	movs r7, #1
	add sb, r7
	mov r0, sb
	cmp r0, #6
	ble _082011DA
	movs r1, #0
	mov sb, r1
	ldr r3, [sp, #0x60]
	mov r8, r3
	adds r6, r2, #0
	movs r7, #0xae
	lsls r7, r7, #1
	add r7, sl
	mov r0, sp
	adds r0, #0x3c
	str r0, [sp, #0x5c]
_08201206:
	ldrh r0, [r6, #0x1c]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	ldr r1, [sp, #0x5c]
	strh r0, [r1]
	ldrh r0, [r6, #0x1e]
	ldrh r1, [r7, #0x1e]
	subs r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	ldrh r0, [r6, #0x20]
	ldrh r1, [r7, #0x20]
	subs r0, r0, r1
	strh r0, [r2, #4]
	ldr r3, [sp, #0x5c]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #2
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov r3, r8
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r3, r1, r0
	ldr r1, _082013BC @ =0x085AE7C8
	movs r0, #7
	mov r2, sb
	subs r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _082012BC
	ldr r0, _082013C0 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r5, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _082012A0
	ldr r3, [sp, #0x60]
	movs r1, #0
	ldrsh r0, [r3, r1]
	muls r0, r5, r0
	adds r1, r4, #0
	bl Div
	ldr r2, [sp, #0x5c]
	strh r0, [r2]
	mov r3, r8
	movs r1, #2
	ldrsh r0, [r3, r1]
	muls r0, r5, r0
	adds r1, r4, #0
	bl Div
	mov r2, r8
	strh r0, [r2, #2]
	movs r3, #4
	ldrsh r0, [r2, r3]
	muls r0, r5, r0
	adds r1, r4, #0
	bl Div
	mov r1, r8
	strh r0, [r1, #4]
_082012A0:
	ldr r2, [sp, #0x60]
	ldrh r0, [r2]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r6, #0x1c]
	mov r1, r8
	ldrh r0, [r1, #2]
	ldrh r2, [r7, #0x1e]
	adds r0, r0, r2
	strh r0, [r6, #0x1e]
	ldrh r0, [r1, #4]
	ldrh r3, [r7, #0x20]
	adds r0, r0, r3
	strh r0, [r6, #0x20]
_082012BC:
	ldr r0, _082013A8 @ =0x00000696
	add r0, sl
	movs r2, #0x1e
	ldrsh r1, [r6, r2]
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r1, r0
	blt _082012E2
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	ldr r0, [sp, #0x58]
	adds r0, #1
	str r0, [sp, #0x58]
_082012E2:
	subs r7, #0x2c
	subs r6, #0x2c
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #6
	ble _08201206
	ldr r3, [sp, #0x58]
	cmp r3, #6
	ble _0820131E
	movs r2, #0xae
	lsls r2, r2, #1
	add r2, sl
	ldr r0, [r2]
	subs r1, #3
	ands r0, r1
	str r0, [r2]
	movs r2, #0xbc
	lsls r2, r2, #1
	add r2, sl
	ldr r0, _082013A4 @ =0x00000694
	add r0, sl
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	mov r7, sl
	ldr r0, [r7, #0x1c]
	adds r0, #1
	str r0, [r7, #0x1c]
_0820131E:
	mov r1, sl
	ldr r0, [r1, #0x1c]
	cmp r0, #3
	bls _0820132E
	ldr r1, _082013C4 @ =0x000006D9
	add r1, sl
	movs r0, #1
	strb r0, [r1]
_0820132E:
	ldr r0, [sp, #0x54]
	movs r1, #8
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	bne _08201394
	ldr r2, _082013C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _082013CC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _082013D0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	movs r0, #0x7f
	ands r2, r0
	ldr r0, _082013A4 @ =0x00000694
	add r0, sl
	movs r1, #0xc
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #0x20
	str r1, [sp, #0x10]
	movs r1, #1
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r1, _082013B0 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _082013B4 @ =0x0000121B
	str r1, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	movs r1, #0xda
	str r1, [sp, #0x34]
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl FUN_081ee53c
_08201394:
	add sp, #0x64
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082013A4: .4byte 0x00000694
_082013A8: .4byte 0x00000696
_082013AC: .4byte 0x05000002
_082013B0: .4byte 0x0000F422
_082013B4: .4byte 0x0000121B
_082013B8: .4byte 0x00000237
_082013BC: .4byte 0x085AE7C8
_082013C0: .4byte 0x085AE7B8
_082013C4: .4byte 0x000006D9
_082013C8: .4byte 0x030046B8
_082013CC: .4byte 0x000003FF
_082013D0: .4byte 0x0203B400

	thumb_func_start FUN_082013d4
FUN_082013d4: @ 0x082013D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	str r0, [sp, #0x5c]
	cmp r1, #0
	bne _08201402
	bl FUN_082010d0
	ldr r2, _08201460 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08201464 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08201468 @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	ldr r2, [sp, #0x5c]
	str r0, [r2, #0x1c]
_08201402:
	ldr r5, [sp, #0x5c]
	movs r0, #0xae
	lsls r0, r0, #1
	adds r5, r5, r0
	mov sl, r5
	ldr r1, [sp, #0x5c]
	movs r2, #0x98
	lsls r2, r2, #1
	adds r7, r1, r2
	ldr r0, [r1, #0x1c]
	adds r0, #1
	str r0, [r1, #0x1c]
	movs r5, #0
	mov sb, r5
	mov r0, sp
	adds r0, #0x3c
	str r0, [sp, #0x64]
	ldr r6, _0820146C @ =0x085B0A08
	movs r5, #0xff
	adds r2, r1, #0
	adds r2, #0x44
	movs r4, #0
_0820142E:
	ldrh r0, [r2, #2]
	adds r0, #9
	strh r0, [r2, #2]
	movs r1, #8
	mov r0, sb
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, r0, #0
	adds r3, #0xa
	ldr r1, [sp, #0x5c]
	ldr r0, [r1, #0x1c]
	adds r0, r4, r0
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08201470
	asrs r1, r0, #0xf
	b _08201476
	.align 2, 0
_08201460: .4byte 0x030046B8
_08201464: .4byte 0x000003FF
_08201468: .4byte 0x0203B400
_0820146C: .4byte 0x085B0A08
_08201470:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r1, r0, #0
_08201476:
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	ldr r1, [sp, #0x5c]
	ldr r0, [r1, #0x1c]
	adds r0, r4, r0
	ands r0, r5
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0820149A
	asrs r1, r0, #0xf
	b _082014A0
_0820149A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r1, r0, #0
_082014A0:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r2, #0x2c
	adds r4, #0x10
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #6
	ble _0820142E
	movs r2, #0
	mov sb, r2
	ldr r5, [sp, #0x64]
	mov r0, sp
	adds r0, #0x3c
	str r0, [sp, #0x60]
	adds r7, #0x1c
_082014C2:
	ldrh r1, [r7]
	movs r2, #0x1c
	add r2, sl
	mov r8, r2
	mov r2, sl
	ldrh r0, [r2, #0x1c]
	subs r1, r1, r0
	ldr r0, [sp, #0x60]
	strh r1, [r0]
	ldrh r0, [r7, #2]
	mov r2, r8
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	ldr r1, [sp, #0x60]
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r1, r0
	ldr r1, _082015FC @ =0x085AE7C8
	movs r0, #7
	mov r2, sb
	subs r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _0820157C
	ldr r0, _08201600 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0820155C
	ldr r1, [sp, #0x64]
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	ldr r1, [sp, #0x60]
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r5, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_0820155C:
	ldr r2, [sp, #0x64]
	ldrh r0, [r2]
	mov r1, sl
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	strh r0, [r7]
	ldrh r0, [r5, #2]
	mov r2, r8
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	strh r0, [r7, #2]
	ldrh r0, [r5, #4]
	mov r1, r8
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r7, #4]
_0820157C:
	movs r2, #0x2c
	rsbs r2, r2, #0
	add sl, r2
	subs r7, #0x2c
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #6
	ble _082014C2
	ldr r2, [sp, #0x5c]
	ldr r0, [r2, #0x1c]
	movs r1, #0x20
	bl Mod
	cmp r0, #0
	beq _0820159E
	b _0820179C
_0820159E:
	ldr r4, _08201604 @ =0x030046B8
	ldr r0, [r4]
	adds r2, r0, #1
	ldr r3, _08201608 @ =0x000003FF
	ands r2, r3
	str r2, [r4]
	lsls r0, r2, #1
	ldr r5, _0820160C @ =0x0203B400
	adds r0, r0, r5
	movs r6, #0xff
	ldrb r0, [r0]
	cmp r0, #0x3f
	bgt _08201666
	ldr r1, [sp, #0x5c]
	ldr r5, _08201610 @ =0x00000694
	adds r0, r1, r5
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	adds r1, r2, #1
	ands r1, r3
	lsls r0, r1, #1
	ldr r2, _0820160C @ =0x0203B400
	adds r0, r0, r2
	ldrh r5, [r0]
	ands r5, r6
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r4, [r1]
	movs r0, #0x7f
	ands r4, r0
	ldr r1, _08201614 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _08201618
	asrs r0, r0, #0xc
	b _0820161E
	.align 2, 0
_082015FC: .4byte 0x085AE7C8
_08201600: .4byte 0x085AE7B8
_08201604: .4byte 0x030046B8
_08201608: .4byte 0x000003FF
_0820160C: .4byte 0x0203B400
_08201610: .4byte 0x00000694
_08201614: .4byte 0x085B0A08
_08201618:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0820161E:
	add r3, sp, #0x44
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0820164C @ =0xFFFF0000
	ldr r0, [sp, #0x44]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x44]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r4, r0
	cmp r0, #0
	blt _08201650
	asrs r1, r0, #0xc
	b _08201656
	.align 2, 0
_0820164C: .4byte 0xFFFF0000
_08201650:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08201656:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r1, #0
	bl FUN_08204d04
	b _0820179C
_08201666:
	ldr r1, [sp, #0x5c]
	ldr r5, _0820169C @ =0x00000694
	adds r0, r1, r5
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x4c]
	str r1, [sp, #0x50]
	adds r0, r2, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _082016A0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r4, [r0]
	ands r4, r6
	movs r5, #0x78
	ldr r1, _082016A4 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	adds r6, r1, #0
	cmp r0, #0
	blt _082016A8
	asrs r0, r0, #0xc
	b _082016AE
	.align 2, 0
_0820169C: .4byte 0x00000694
_082016A0: .4byte 0x0203B400
_082016A4: .4byte 0x085B0A08
_082016A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_082016AE:
	add r3, sp, #0x4c
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _082016E0 @ =0xFFFF0000
	ldr r0, [sp, #0x4c]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x4c]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _082016E4
	asrs r1, r0, #0xc
	b _082016EA
	.align 2, 0
_082016E0: .4byte 0xFFFF0000
_082016E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_082016EA:
	ldrh r0, [r6, #4]
	adds r0, r0, r1
	movs r4, #0
	strh r0, [r6, #4]
	add r5, sp, #0x54
	str r4, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r5, #0
	ldr r2, _08201748 @ =0x05000002
	bl CpuSet
	ldr r2, [sp, #0x5c]
	ldr r1, _0820174C @ =0x000006DD
	adds r0, r2, r1
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0820175C
	ldr r2, _08201750 @ =0x00002E78
	ldr r3, _08201754 @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _08201758 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_081f22c0
	b _08201790
	.align 2, 0
_08201748: .4byte 0x05000002
_0820174C: .4byte 0x000006DD
_08201750: .4byte 0x00002E78
_08201754: .4byte 0x000038E2
_08201758: .4byte 0x00000232
_0820175C:
	ldr r2, _082017B8 @ =0x00002E78
	ldr r3, _082017BC @ =0x000038E2
	movs r0, #3
	str r0, [sp]
	movs r0, #0x80
	lsls r0, r0, #3
	str r0, [sp, #4]
	movs r0, #9
	str r0, [sp, #8]
	ldr r0, _082017C0 @ =0x00000232
	str r0, [sp, #0xc]
	movs r0, #2
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	str r4, [sp, #0x2c]
	str r4, [sp, #0x30]
	str r4, [sp, #0x34]
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_081f22c0
_08201790:
	ldr r2, [sp, #0x5c]
	ldr r5, _082017C4 @ =0x000006DD
	adds r1, r2, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0820179C:
	ldr r0, [sp, #0x5c]
	ldr r2, _082017C8 @ =0x000006D9
	adds r1, r0, r2
	movs r0, #1
	strb r0, [r1]
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082017B8: .4byte 0x00002E78
_082017BC: .4byte 0x000038E2
_082017C0: .4byte 0x00000232
_082017C4: .4byte 0x000006DD
_082017C8: .4byte 0x000006D9

	thumb_func_start FUN_082017cc
FUN_082017cc: @ 0x082017CC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov sb, r0
	movs r0, #0
	str r0, [sp, #0x20]
	cmp r1, #0
	bne _0820180A
	ldr r0, _08201830 @ =0x00000692
	add r0, sb
	add r1, sp, #0x20
	ldrb r1, [r1]
	strb r1, [r0]
	ldr r0, _08201834 @ =0x00000693
	add r0, sb
	add r2, sp, #0x20
	ldrb r2, [r2]
	strb r2, [r0]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08201838 @ =0x00000691
	add r0, sb
	add r3, sp, #0x20
	ldrb r3, [r3]
	strb r3, [r0]
_0820180A:
	movs r0, #0xd2
	lsls r0, r0, #3
	add r0, sb
	ldrb r0, [r0]
	movs r4, #0x98
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x30]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x34]
	cmp r0, #4
	bls _08201826
	b _08201D96
_08201826:
	lsls r0, r0, #2
	ldr r1, _0820183C @ =_08201840
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08201830: .4byte 0x00000692
_08201834: .4byte 0x00000693
_08201838: .4byte 0x00000691
_0820183C: .4byte _08201840
_08201840: @ jump table
	.4byte _08201854 @ case 0
	.4byte _08201918 @ case 1
	.4byte _08201A38 @ case 2
	.4byte _08201BC8 @ case 3
	.4byte _08201D80 @ case 4
_08201854:
	mov r2, sb
	ldr r0, [r2, #0x1c]
	adds r0, #1
	str r0, [r2, #0x1c]
	movs r3, #0
	mov sl, r3
	movs r4, #0x98
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x30]
	mov r0, sp
	adds r0, #0x18
	str r0, [sp, #0x34]
	ldr r6, _082018A8 @ =0x085B0A08
	movs r5, #0xff
	adds r2, #0x44
	movs r4, #0
_08201876:
	ldrh r0, [r2, #2]
	adds r0, #9
	strh r0, [r2, #2]
	movs r1, #8
	mov r3, sl
	subs r1, r1, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	adds r3, r0, #0
	adds r3, #0xa
	mov r1, sb
	ldr r0, [r1, #0x1c]
	adds r0, r4, r0
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _082018AC
	asrs r1, r0, #0xf
	b _082018B2
	.align 2, 0
_082018A8: .4byte 0x085B0A08
_082018AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r1, r0, #0
_082018B2:
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	mov r1, sb
	ldr r0, [r1, #0x1c]
	adds r0, r4, r0
	ands r0, r5
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _082018D6
	asrs r1, r0, #0xf
	b _082018DC
_082018D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r1, r0, #0
_082018DC:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r2, #0x2c
	adds r4, #0x10
	movs r3, #1
	add sl, r3
	mov r0, sl
	cmp r0, #6
	ble _08201876
	ldr r1, _08201914 @ =0x00000692
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bhi _08201904
	b _08201D96
_08201904:
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	b _08201D96
	.align 2, 0
_08201914: .4byte 0x00000692
_08201918:
	ldr r0, _08201A28 @ =0x00000692
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08201932
	ldr r0, _08201A2C @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _08201A30 @ =0x000006E4
	add r2, sb
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_08201932:
	movs r1, #0
	mov sl, r1
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, sb
	str r2, [sp, #0x30]
	mov r3, sp
	adds r3, #0x18
	str r3, [sp, #0x34]
	mov r4, sp
	mov r6, sb
	adds r6, #0x44
	ldr r0, _08201A30 @ =0x000006E4
	add r0, sb
	mov r8, r0
_08201950:
	ldrh r0, [r6]
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r6, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r6, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #7
	mov r3, sl
	subs r1, r1, r3
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r7, r0, #1
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	movs r3, #2
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _082019CE
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_082019CE:
	ldrh r0, [r4]
	ldrh r3, [r6]
	adds r0, r0, r3
	strh r0, [r6]
	ldrh r2, [r4, #2]
	ldrh r0, [r6, #2]
	adds r2, r2, r0
	strh r2, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	ldr r1, _08201A34 @ =0x085AE7D8
	mov r3, sl
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r0, [r0]
	adds r2, r2, r0
	strh r2, [r6, #2]
	adds r6, #0x2c
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _08201950
	movs r2, #1
	str r2, [sp, #0x20]
	ldr r1, _08201A28 @ =0x00000692
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bhi _08201A18
	b _08201D96
_08201A18:
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #2
	strb r0, [r1]
	b _08201D96
	.align 2, 0
_08201A28: .4byte 0x00000692
_08201A2C: .4byte 0x03002BE0
_08201A30: .4byte 0x000006E4
_08201A34: .4byte 0x085AE7D8
_08201A38:
	movs r7, #0
	ldr r0, _08201B14 @ =0x000006E4
	add r0, sb
	movs r3, #0
	ldrsh r2, [r0, r3]
	ldr r0, _08201B18 @ =0x00000694
	add r0, sb
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r2, r2, r0
	movs r0, #0xdd
	lsls r0, r0, #3
	add r0, sb
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xd3
	lsls r0, r0, #3
	add r0, sb
	movs r4, #0
	ldrsh r0, [r0, r4]
	subs r1, r1, r0
	add r4, sp, #8
	strh r2, [r4]
	strh r7, [r4, #2]
	strh r1, [r4, #4]
	movs r6, #0x96
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	movs r3, #4
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08201AB8
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_08201AB8:
	movs r3, #0
	mov sl, r3
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, sb
	str r0, [sp, #0x30]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x34]
_08201ACA:
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	add r1, sb
	adds r2, r1, #0
	adds r2, #0x44
	ldrh r0, [r4]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	adds r1, #0x48
	add r0, sp, #8
	ldrh r0, [r0, #4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _08201B0E
	cmp r1, #0
	blt _08201B0E
	ldr r0, _08201B1C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _08201B0E
	ldr r0, _08201B20 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08201B24
_08201B0E:
	movs r5, #0
	b _08201B32
	.align 2, 0
_08201B14: .4byte 0x000006E4
_08201B18: .4byte 0x00000694
_08201B1C: .4byte 0x030046A8
_08201B20: .4byte 0x030046AC
_08201B24:
	ldr r0, _08201B44 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_08201B32:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08201B48
	adds r0, #4
	b _08201B54
	.align 2, 0
_08201B44: .4byte 0x030046A4
_08201B48:
	ldr r0, _08201BBC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08201B54:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	mov r3, sb
	adds r1, r3, r0
	adds r0, r1, #0
	adds r0, #0x46
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, r2
	bgt _08201B7C
	adds r0, r1, #0
	adds r0, #0x28
	strh r2, [r0, #0x1e]
	adds r7, #1
_08201B7C:
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _08201ACA
	cmp r7, #6
	ble _08201B9E
	mov r0, sb
	movs r1, #0x14
	movs r2, #0x14
	bl FUN_082010f0
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #3
	strb r0, [r1]
_08201B9E:
	cmp r7, #0
	bgt _08201BA4
	b _08201D96
_08201BA4:
	ldr r4, _08201BC0 @ =0x00000693
	add r4, sb
	ldrb r0, [r4]
	cmp r0, #0
	beq _08201BB0
	b _08201D96
_08201BB0:
	ldr r0, _08201BC4 @ =0x000001BB
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
	b _08201D96
	.align 2, 0
_08201BBC: .4byte 0x030046A4
_08201BC0: .4byte 0x00000693
_08201BC4: .4byte 0x000001BB
_08201BC8:
	mov r2, sb
	ldr r0, [r2, #0x1c]
	adds r0, #0x10
	str r0, [r2, #0x1c]
	movs r3, #0
	mov sl, r3
	movs r4, #0x98
	lsls r4, r4, #1
	add r4, sb
	str r4, [sp, #0x30]
	add r0, sp, #0x10
	mov r8, r0
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x34]
	mov r7, r8
	mov r5, sb
	adds r5, #0x44
	ldr r2, _08201CBC @ =0x00000694
	add r2, sb
	str r2, [sp, #0x24]
_08201BF2:
	ldrh r1, [r5]
	ldr r3, [sp, #0x24]
	ldrh r0, [r3]
	subs r1, r1, r0
	add r6, sp, #0x10
	strh r1, [r6]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r7, #4]
	movs r4, #0
	ldrsh r0, [r6, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	movs r4, #4
	ldrsh r1, [r7, r4]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08201C6C
	mov r3, r8
	movs r1, #0
	ldrsh r0, [r3, r1]
	lsls r0, r0, #3
	adds r1, r4, #0
	bl Div
	strh r0, [r6]
	movs r2, #2
	ldrsh r0, [r7, r2]
	lsls r0, r0, #3
	adds r1, r4, #0
	bl Div
	mov r3, r8
	strh r0, [r3, #2]
	movs r1, #4
	ldrsh r0, [r7, r1]
	lsls r0, r0, #3
	adds r1, r4, #0
	bl Div
	mov r2, r8
	strh r0, [r2, #4]
_08201C6C:
	mov r3, r8
	ldrh r0, [r3]
	ldrh r4, [r5]
	adds r0, r0, r4
	strh r0, [r5]
	ldrh r0, [r7, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r7, #4]
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	movs r1, #9
	mov r3, sl
	subs r1, r1, r3
	ldr r0, _08201CC0 @ =0x00000692
	add r0, sb
	ldrb r2, [r0]
	movs r0, #0x3c
	subs r0, r0, r2
	adds r3, r1, #0
	muls r3, r0, r3
	ldr r2, _08201CC4 @ =0x085B0A08
	mov r4, sl
	lsls r0, r4, #4
	mov r4, sb
	ldr r1, [r4, #0x1c]
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08201CC8
	asrs r3, r0, #0xf
	b _08201CCE
	.align 2, 0
_08201CBC: .4byte 0x00000694
_08201CC0: .4byte 0x00000692
_08201CC4: .4byte 0x085B0A08
_08201CC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xf
	rsbs r3, r0, #0
_08201CCE:
	ldrh r0, [r5, #2]
	adds r0, r0, r3
	strh r0, [r5, #2]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08201CF8
	cmp r1, #0
	blt _08201CF8
	ldr r0, _08201CFC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08201CF8
	ldr r0, _08201D00 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08201D04
_08201CF8:
	movs r4, #0
	b _08201D12
	.align 2, 0
_08201CFC: .4byte 0x030046A8
_08201D00: .4byte 0x030046AC
_08201D04:
	ldr r0, _08201D24 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08201D12:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08201D28
	adds r0, #4
	b _08201D34
	.align 2, 0
_08201D24: .4byte 0x030046A4
_08201D28:
	ldr r0, _08201D78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08201D34:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #2
	ldrsh r0, [r5, r2]
	cmp r0, r1
	bgt _08201D46
	strh r1, [r5, #2]
_08201D46:
	adds r5, #0x2c
	movs r3, #1
	add sl, r3
	mov r4, sl
	cmp r4, #6
	bgt _08201D54
	b _08201BF2
_08201D54:
	ldr r1, _08201D7C @ =0x00000692
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x28
	bls _08201D96
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #4
	strb r0, [r1]
	b _08201D96
	.align 2, 0
_08201D78: .4byte 0x030046A4
_08201D7C: .4byte 0x00000692
_08201D80:
	ldr r1, _08201E78 @ =0x000006D9
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	movs r0, #0x98
	lsls r0, r0, #1
	add r0, sb
	str r0, [sp, #0x30]
	mov r1, sp
	adds r1, #0x18
	str r1, [sp, #0x34]
_08201D96:
	ldr r2, [sp, #0x20]
	cmp r2, #0
	beq _08201E84
	movs r3, #0
	mov sl, r3
	ldr r5, [sp, #0x34]
	mov r4, sp
	adds r4, #0x18
	str r4, [sp, #0x28]
	ldr r0, [sp, #0x30]
	adds r0, #0x1c
	mov r8, r0
	movs r7, #0xbc
	lsls r7, r7, #1
	add r7, sb
_08201DB4:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldr r2, [sp, #0x28]
	strh r0, [r2]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r1, r0
	ldr r1, _08201E7C @ =0x085AE7C8
	movs r0, #7
	mov r4, sl
	subs r0, r0, r4
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _08201E62
	ldr r0, _08201E80 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08201E46
	ldr r1, [sp, #0x34]
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	ldr r3, [sp, #0x28]
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_08201E46:
	ldr r3, [sp, #0x34]
	ldrh r0, [r3]
	ldrh r4, [r7]
	adds r0, r0, r4
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r5, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
_08201E62:
	subs r7, #0x2c
	movs r4, #0x2c
	rsbs r4, r4, #0
	add r8, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _08201DB4
	b _08201F5C
	.align 2, 0
_08201E78: .4byte 0x000006D9
_08201E7C: .4byte 0x085AE7C8
_08201E80: .4byte 0x085AE7B8
_08201E84:
	movs r2, #0
	mov sl, r2
	ldr r5, [sp, #0x34]
	mov r3, sp
	adds r3, #0x18
	str r3, [sp, #0x2c]
	ldr r4, [sp, #0x30]
	adds r4, #0x1c
	mov r8, r4
	movs r7, #0xbc
	lsls r7, r7, #1
	add r7, sb
_08201E9C:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldr r2, [sp, #0x2c]
	strh r0, [r2]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r4, #0
	ldrsh r0, [r2, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r3, r1, r0
	ldr r1, _08201F6C @ =0x085AE7C8
	movs r0, #7
	mov r4, sl
	subs r0, r0, r4
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _08201F4A
	ldr r0, _08201F70 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08201F2E
	ldr r1, [sp, #0x34]
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	ldr r3, [sp, #0x2c]
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r5, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r2, #4
	ldrsh r0, [r5, r2]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_08201F2E:
	ldr r3, [sp, #0x34]
	ldrh r0, [r3]
	ldrh r4, [r7]
	adds r0, r0, r4
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r5, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
_08201F4A:
	subs r7, #0x2c
	movs r4, #0x2c
	rsbs r4, r4, #0
	add r8, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #6
	ble _08201E9C
_08201F5C:
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08201F6C: .4byte 0x085AE7C8
_08201F70: .4byte 0x085AE7B8

	thumb_func_start FUN_08201f74
FUN_08201f74: @ 0x08201F74
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x4c
	mov sb, r0
	str r1, [sp, #0x40]
	movs r0, #0
	str r0, [sp, #0x48]
	cmp r1, #0
	bne _08201F94
	movs r0, #0xcf
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08201F94:
	movs r1, #0
	str r1, [sp, #0x44]
	ldr r2, _08201FC0 @ =0x00000694
	add r2, sb
	mov sl, r2
	add r4, sp, #0x38
	mov r8, r4
_08201FA2:
	movs r0, #0x2c
	ldr r1, [sp, #0x44]
	muls r0, r1, r0
	mov r2, sb
	adds r3, r0, r2
	ldr r2, [r3, #0x28]
	adds r0, r2, #0
	movs r4, #1
	ands r0, r4
	cmp r0, #0
	beq _08201FC4
	ldr r0, [sp, #0x48]
	adds r0, #1
	str r0, [sp, #0x48]
	b _08202078
	.align 2, 0
_08201FC0: .4byte 0x00000694
_08201FC4:
	add r5, sp, #0x38
	adds r6, r3, #0
	adds r6, #0x44
	mov r1, sl
	ldrh r0, [r1]
	ldrh r1, [r6]
	subs r0, r0, r1
	mov r4, r8
	strh r0, [r4]
	mov r1, sl
	ldrh r0, [r1, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	mov r4, sl
	ldrh r0, [r4, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	mov r1, r8
	movs r4, #0
	ldrsh r0, [r1, r4]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #2
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	movs r4, #4
	ldrsh r0, [r5, r4]
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0820201C @ =0x0000018F
	cmp r1, r0
	bgt _08202020
	movs r0, #1
	orrs r2, r0
	str r2, [r3, #0x28]
	b _08202078
	.align 2, 0
_0820201C: .4byte 0x0000018F
_08202020:
	movs r7, #0x14
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0820205E
	mov r1, r8
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	adds r1, r4, #0
	bl Div
	mov r1, r8
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r5, r2]
	muls r0, r7, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	muls r0, r7, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_0820205E:
	mov r2, r8
	ldrh r0, [r2]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r5, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r5, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	strh r0, [r6, #4]
_08202078:
	ldr r4, [sp, #0x44]
	adds r4, #1
	str r4, [sp, #0x44]
	cmp r4, #7
	ble _08201FA2
	ldr r0, [sp, #0x48]
	cmp r0, #7
	ble _082020AC
	ldr r0, _082020A0 @ =0x000006D9
	add r0, sb
	movs r1, #1
	strb r1, [r0]
	ldr r0, _082020A4 @ =0x000006DA
	add r0, sb
	strb r1, [r0]
	ldr r1, _082020A8 @ =0x000006DB
	add r1, sb
	movs r0, #7
	strb r0, [r1]
	b _08202112
	.align 2, 0
_082020A0: .4byte 0x000006D9
_082020A4: .4byte 0x000006DA
_082020A8: .4byte 0x000006DB
_082020AC:
	ldr r0, [sp, #0x40]
	movs r1, #8
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	bne _08202112
	ldr r2, _08202124 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08202128 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0820212C @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0x7f
	ands r2, r0
	ldr r0, _08202130 @ =0x00000694
	add r0, sb
	movs r1, #0xc
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r1, #8
	str r1, [sp, #0xc]
	movs r1, #0x20
	str r1, [sp, #0x10]
	movs r1, #1
	str r1, [sp, #0x14]
	movs r1, #2
	str r1, [sp, #0x18]
	movs r1, #0x80
	lsls r1, r1, #2
	str r1, [sp, #0x1c]
	str r3, [sp, #0x20]
	ldr r1, _08202134 @ =0x0000F422
	str r1, [sp, #0x24]
	ldr r1, _08202138 @ =0x0000121B
	str r1, [sp, #0x28]
	str r3, [sp, #0x2c]
	str r3, [sp, #0x30]
	ldr r1, _0820213C @ =0x00000237
	str r1, [sp, #0x34]
	movs r1, #0xc
	movs r2, #8
	movs r3, #6
	bl FUN_081ee53c
_08202112:
	add sp, #0x4c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08202124: .4byte 0x030046B8
_08202128: .4byte 0x000003FF
_0820212C: .4byte 0x0203B400
_08202130: .4byte 0x00000694
_08202134: .4byte 0x0000F422
_08202138: .4byte 0x0000121B
_0820213C: .4byte 0x00000237

	thumb_func_start FUN_08202140
FUN_08202140: @ 0x08202140
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	cmp r1, #0
	bne _0820216E
	str r1, [r5, #0x1c]
	ldr r2, _0820218C @ =0x00000692
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _08202190 @ =0x00000693
	adds r0, r5, r3
	strb r1, [r0]
	movs r4, #0xd2
	lsls r4, r4, #3
	adds r0, r5, r4
	strb r1, [r0]
	ldr r6, _08202194 @ =0x00000691
	adds r0, r5, r6
	strb r1, [r0]
_0820216E:
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _0820217C
	b _082022A0
_0820217C:
	cmp r0, #1
	bgt _08202198
	cmp r0, #0
	beq _082021A6
	movs r2, #0x98
	lsls r2, r2, #1
	adds r7, r5, r2
	b _08202402
	.align 2, 0
_0820218C: .4byte 0x00000692
_08202190: .4byte 0x00000693
_08202194: .4byte 0x00000691
_08202198:
	cmp r0, #2
	bne _0820219E
	b _082023F4
_0820219E:
	movs r3, #0x98
	lsls r3, r3, #1
	adds r7, r5, r3
	b _08202402
_082021A6:
	ldr r4, _08202204 @ =0x00000692
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _082021E0
	ldr r0, _08202208 @ =0x03002BE0
	ldr r0, [r0]
	ldr r6, _0820220C @ =0x000006E4
	adds r2, r5, r6
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _08202210 @ =0x00000694
	adds r3, r5, r0
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r4, #0
	ldrsh r1, [r2, r4]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r0, #0x20
	str r0, [r5, #0x1c]
_082021E0:
	mov r4, sp
	ldr r3, [r5, #0x1c]
	movs r6, #0x64
	ldr r2, _08202214 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	mov sl, r2
	cmp r0, #0
	blt _08202218
	asrs r1, r0, #0xc
	b _0820221E
	.align 2, 0
_08202204: .4byte 0x00000692
_08202208: .4byte 0x03002BE0
_0820220C: .4byte 0x000006E4
_08202210: .4byte 0x00000694
_08202214: .4byte 0x085B0A08
_08202218:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0820221E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0820223A
	asrs r0, r0, #0xc
	b _08202240
_0820223A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08202240:
	strh r0, [r4, #4]
	movs r3, #0x98
	lsls r3, r3, #1
	adds r7, r5, r3
	mov r0, sp
	adds r1, r5, #0
	adds r1, #0x70
	ldrh r4, [r0]
	ldrh r3, [r0, #2]
	ldrh r2, [r0, #4]
	movs r6, #5
	mov sb, r6
_08202258:
	ldrh r6, [r1]
	adds r0, r4, r6
	strh r0, [r1]
	ldrh r6, [r1, #2]
	adds r0, r3, r6
	strh r0, [r1, #2]
	ldrh r6, [r1, #4]
	adds r0, r2, r6
	strh r0, [r1, #4]
	adds r1, #0x2c
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r6, sb
	cmp r6, #0
	bge _08202258
	ldr r0, _0820229C @ =0x00000692
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x3c
	bhi _0820228C
	b _08202402
_0820228C:
	movs r0, #0
	strb r0, [r1]
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _08202402
	.align 2, 0
_0820229C: .4byte 0x00000692
_082022A0:
	ldr r0, [r5, #0x1c]
	adds r0, #1
	movs r1, #0xff
	ands r0, r1
	str r0, [r5, #0x1c]
	movs r3, #0
	mov sb, r3
	movs r4, #0x98
	lsls r4, r4, #1
	adds r7, r5, r4
	mov r6, sp
	movs r0, #0x64
	mov r8, r0
	ldr r1, _082022EC @ =0x085B0A08
	mov sl, r1
_082022BE:
	movs r0, #7
	mov r2, sb
	subs r0, r0, r2
	ldr r1, [r5, #0x1c]
	muls r0, r1, r0
	lsrs r0, r0, #3
	adds r3, r0, r1
	ldr r2, _082022EC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _082022F0
	asrs r1, r0, #0xc
	b _082022F6
	.align 2, 0
_082022EC: .4byte 0x085B0A08
_082022F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_082022F6:
	movs r0, #0
	strh r1, [r6]
	strh r0, [r6, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _08202316
	asrs r3, r0, #0xc
	b _0820231C
_08202316:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0820231C:
	strh r3, [r6, #4]
	movs r0, #0x2c
	mov r1, sb
	muls r1, r0, r1
	adds r1, r5, r1
	adds r2, r1, #0
	adds r2, #0x44
	ldrh r0, [r6]
	ldrh r4, [r2]
	adds r0, r0, r4
	strh r0, [r2]
	adds r1, #0x48
	ldrh r0, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _0820235E
	cmp r1, #0
	blt _0820235E
	ldr r0, _08202364 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _0820235E
	ldr r0, _08202368 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0820236C
_0820235E:
	movs r4, #0
	b _0820237A
	.align 2, 0
_08202364: .4byte 0x030046A8
_08202368: .4byte 0x030046AC
_0820236C:
	ldr r0, _0820238C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_0820237A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08202390
	adds r0, #4
	b _0820239C
	.align 2, 0
_0820238C: .4byte 0x030046A4
_08202390:
	ldr r0, _082023EC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0820239C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r0, #0x2c
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r5, r0
	adds r0, r1, #0
	adds r0, #0x46
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, r2
	bgt _082023C0
	adds r0, r1, #0
	adds r0, #0x28
	strh r2, [r0, #0x1e]
_082023C0:
	movs r4, #1
	add sb, r4
	mov r0, sb
	cmp r0, #6
	bgt _082023CC
	b _082022BE
_082023CC:
	ldr r1, _082023F0 @ =0x00000692
	adds r3, r5, r1
	ldrb r0, [r3]
	cmp r0, #0xd1
	bls _082023E4
	movs r2, #0xd2
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	movs r1, #2
	strb r1, [r0]
	strb r2, [r3]
_082023E4:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	b _08202402
	.align 2, 0
_082023EC: .4byte 0x030046A4
_082023F0: .4byte 0x00000692
_082023F4:
	ldr r3, _082024DC @ =0x000006D9
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	movs r4, #0x98
	lsls r4, r4, #1
	adds r7, r5, r4
_08202402:
	movs r6, #0
	mov sb, r6
	mov r4, sp
	adds r7, #0x1c
	mov r8, r7
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r7, r5, r0
_08202412:
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	subs r0, r0, r1
	strh r0, [r4]
	mov r2, r8
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0
	ldrsh r0, [r4, r3]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r6, #2
	ldrsh r0, [r4, r6]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	adds r6, r0, #0
	muls r6, r0, r6
	adds r0, r6, #0
	adds r3, r1, r0
	ldr r1, _082024E0 @ =0x085AE7C8
	movs r0, #7
	mov r2, sb
	subs r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _082024B8
	ldr r0, _082024E4 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0820249E
	movs r3, #0
	ldrsh r0, [r4, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_0820249E:
	ldrh r0, [r4]
	ldrh r3, [r7]
	adds r0, r0, r3
	mov r6, r8
	strh r0, [r6]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r6, #4]
_082024B8:
	subs r7, #0x2c
	movs r3, #0x2c
	rsbs r3, r3, #0
	add r8, r3
	movs r6, #1
	add sb, r6
	mov r0, sb
	cmp r0, #6
	ble _08202412
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082024DC: .4byte 0x000006D9
_082024E0: .4byte 0x085AE7C8
_082024E4: .4byte 0x085AE7B8

	thumb_func_start FUN_082024e8
FUN_082024e8: @ 0x082024E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sb, r0
	cmp r1, #0
	bne _08202514
	ldr r0, _0820253C @ =0x00000692
	add r0, sb
	strb r1, [r0]
	ldr r0, _08202540 @ =0x00000693
	add r0, sb
	strb r1, [r0]
	movs r0, #0xd2
	lsls r0, r0, #3
	add r0, sb
	strb r1, [r0]
	ldr r0, _08202544 @ =0x00000691
	add r0, sb
	strb r1, [r0]
_08202514:
	movs r0, #0
	str r0, [sp, #0x10]
	movs r0, #0xd2
	lsls r0, r0, #3
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #1
	beq _082025FC
	cmp r0, #1
	bgt _08202548
	cmp r0, #0
	beq _0820255C
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r1, sp
	adds r1, #8
	str r1, [sp, #0x18]
	b _08202780
	.align 2, 0
_0820253C: .4byte 0x00000692
_08202540: .4byte 0x00000693
_08202544: .4byte 0x00000691
_08202548:
	cmp r0, #3
	bne _0820254E
	b _0820276C
_0820254E:
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r2, sp
	adds r2, #8
	str r2, [sp, #0x18]
	b _08202780
_0820255C:
	ldr r0, _082025F0 @ =0x00000692
	add r0, sb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08202576
	ldr r0, _082025F4 @ =0x03002BE0
	ldr r0, [r0]
	ldr r2, _082025F8 @ =0x000006E4
	add r2, sb
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_08202576:
	mov r1, sb
	adds r1, #0x46
	ldrh r0, [r1]
	adds r0, #4
	strh r0, [r1]
	movs r3, #0
	mov sl, r3
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r0, sp
	adds r0, #8
	str r0, [sp, #0x18]
	movs r4, #0xdd
	lsls r4, r4, #3
	add r4, sb
	mov r3, sb
	adds r3, #0x48
	movs r5, #7
_0820259C:
	movs r2, #0
	ldrsh r1, [r3, r2]
	movs r2, #0
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	movs r2, #1
	rsbs r2, r2, #0
	cmp r1, #0
	ble _082025B0
	movs r2, #1
_082025B0:
	lsls r0, r2, #2
	adds r0, r0, r2
	mov r2, sl
	subs r1, r5, r2
	muls r0, r1, r0
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	adds r3, #0x2c
	movs r2, #1
	add sl, r2
	mov r0, sl
	cmp r0, #3
	ble _0820259C
	ldr r1, _082025F0 @ =0x00000692
	add r1, sb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x1e
	bhi _082025E0
	b _08202780
_082025E0:
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	b _08202780
	.align 2, 0
_082025F0: .4byte 0x00000692
_082025F4: .4byte 0x03002BE0
_082025F8: .4byte 0x000006E4
_082025FC:
	movs r7, #0
	ldr r0, _082026E0 @ =0x000006E4
	add r0, sb
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r0, _082026E4 @ =0x00000694
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, r2, r0
	movs r0, #0xdd
	lsls r0, r0, #3
	add r0, sb
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xd3
	lsls r0, r0, #3
	add r0, sb
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	mov r4, sp
	mov r0, sp
	strh r2, [r0]
	ldrh r0, [r0, #0x10]
	strh r0, [r4, #2]
	strh r1, [r4, #4]
	movs r6, #0x96
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	movs r3, #4
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08202686
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	mov r1, sp
	strh r0, [r1]
	movs r1, #2
	ldrsh r0, [r4, r1]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	muls r0, r6, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_08202686:
	movs r3, #0
	mov sl, r3
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r0, sp
	adds r0, #8
	str r0, [sp, #0x18]
_08202696:
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	add r1, sb
	adds r2, r1, #0
	adds r2, #0x44
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	adds r1, #0x48
	mov r0, sp
	ldrh r0, [r0, #4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _082026DC
	cmp r1, #0
	blt _082026DC
	ldr r0, _082026E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _082026DC
	ldr r0, _082026EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082026F0
_082026DC:
	movs r4, #0
	b _082026FE
	.align 2, 0
_082026E0: .4byte 0x000006E4
_082026E4: .4byte 0x00000694
_082026E8: .4byte 0x030046A8
_082026EC: .4byte 0x030046AC
_082026F0:
	ldr r0, _08202710 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_082026FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08202714
	adds r0, #4
	b _08202720
	.align 2, 0
_08202710: .4byte 0x030046A4
_08202714:
	ldr r0, _08202768 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08202720:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	movs r0, #0x2c
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	mov r3, sb
	adds r1, r3, r0
	adds r0, r1, #0
	adds r0, #0x46
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, r2
	bgt _08202748
	adds r0, r1, #0
	adds r0, #0x28
	strh r2, [r0, #0x1e]
	adds r7, #1
_08202748:
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #3
	ble _08202696
	cmp r7, #6
	ble _08202780
	movs r2, #1
	str r2, [sp, #0x10]
	movs r1, #0xd2
	lsls r1, r1, #3
	add r1, sb
	movs r0, #2
	strb r0, [r1]
	b _08202780
	.align 2, 0
_08202768: .4byte 0x030046A4
_0820276C:
	ldr r1, _08202870 @ =0x000006D9
	add r1, sb
	movs r0, #1
	strb r0, [r1]
	movs r6, #0x98
	lsls r6, r6, #1
	add r6, sb
	mov r3, sp
	adds r3, #8
	str r3, [sp, #0x18]
_08202780:
	movs r0, #0
	mov sl, r0
	ldr r5, [sp, #0x18]
	mov r1, sp
	adds r1, #8
	str r1, [sp, #0x14]
	adds r6, #0x1c
	mov r8, r6
	movs r7, #0xbc
	lsls r7, r7, #1
	add r7, sb
_08202796:
	mov r2, r8
	ldrh r0, [r2]
	ldrh r1, [r7]
	subs r0, r0, r1
	ldr r3, [sp, #0x14]
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r5, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r5, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r3, r1, r0
	ldr r1, _08202874 @ =0x085AE7C8
	movs r0, #7
	mov r2, sl
	subs r0, r0, r2
	lsls r2, r0, #1
	adds r1, r2, r1
	ldrh r1, [r1]
	cmp r3, r1
	ble _08202842
	ldr r0, _08202878 @ =0x085AE7B8
	adds r0, r2, r0
	ldrh r6, [r0]
	adds r0, r3, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _08202826
	ldr r3, [sp, #0x18]
	movs r1, #0
	ldrsh r0, [r3, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	ldr r2, [sp, #0x14]
	strh r0, [r2]
	movs r3, #2
	ldrsh r0, [r5, r3]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #2]
	movs r1, #4
	ldrsh r0, [r5, r1]
	muls r0, r6, r0
	adds r1, r4, #0
	bl Div
	strh r0, [r5, #4]
_08202826:
	ldr r2, [sp, #0x18]
	ldrh r0, [r2]
	ldrh r3, [r7]
	adds r0, r0, r3
	mov r1, r8
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r2, [r7, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	ldrh r0, [r5, #4]
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r1, #4]
_08202842:
	subs r7, #0x2c
	movs r0, #0x2c
	rsbs r0, r0, #0
	add r8, r0
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #6
	ble _08202796
	ldr r3, [sp, #0x10]
	cmp r3, #1
	bne _08202860
	mov r0, sb
	bl FUN_08200b5c
_08202860:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08202870: .4byte 0x000006D9
_08202874: .4byte 0x085AE7C8
_08202878: .4byte 0x085AE7B8

	thumb_func_start FUN_0820287c
FUN_0820287c: @ 0x0820287C
	push {r4, r5, lr}
	adds r3, r0, #0
	cmp r1, #0
	bne _0820289C
	movs r0, #0x82
	lsls r0, r0, #3
	adds r1, r3, r0
	movs r4, #4
	movs r2, #7
_0820288E:
	ldrh r0, [r1, #6]
	orrs r0, r4
	strh r0, [r1, #6]
	adds r1, #0x50
	subs r2, #1
	cmp r2, #0
	bge _0820288E
_0820289C:
	ldr r1, _082028B0 @ =0x000006DA
	adds r0, r3, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _082028B4 @ =0x000006D9
	adds r0, r3, r2
	strb r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082028B0: .4byte 0x000006DA
_082028B4: .4byte 0x000006D9

	thumb_func_start FUN_082028b8
FUN_082028b8: @ 0x082028B8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _082028F8 @ =0x000006DB
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bhi _08202908
	ldr r1, _082028FC @ =0x000006D4
	adds r2, r4, r1
	ldr r1, _08202900 @ =0x085AE7F8
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldrb r2, [r3]
	ldr r1, _08202904 @ =0x000006DC
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	strb r1, [r3]
	str r1, [r4, #0x18]
	movs r0, #0xdb
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _0820290A
	.align 2, 0
_082028F8: .4byte 0x000006DB
_082028FC: .4byte 0x000006D4
_08202900: .4byte 0x085AE7F8
_08202904: .4byte 0x000006DC
_08202908:
	movs r0, #0
_0820290A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08202910
FUN_08202910: @ 0x08202910
	push {lr}
	adds r2, r0, #0
	ldr r0, _08202938 @ =0x000006D9
	adds r1, r2, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r2, #0x18]
	adds r1, r0, #0
	adds r0, #1
	str r0, [r2, #0x18]
	ldr r3, _0820293C @ =0x000006D4
	adds r0, r2, r3
	ldr r3, [r0]
	cmp r3, #0
	beq _08202934
	adds r0, r2, #0
	bl _call_via_r3
_08202934:
	pop {r0}
	bx r0
	.align 2, 0
_08202938: .4byte 0x000006D9
_0820293C: .4byte 0x000006D4

	thumb_func_start Entity08202cd8_Update
Entity08202cd8_Update: @ 0x08202940
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08202990 @ =0x000006DA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #4
	ldr r0, _08202994 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08202988
	adds r0, r4, #0
	bl FUN_08200b8c
	adds r0, r4, #0
	bl FUN_082028b8
	adds r0, r4, #0
	bl FUN_08202910
	adds r0, r4, #0
	bl FUN_08200e54
	adds r0, r4, #0
	bl FUN_08200c8c
	ldrh r0, [r4, #0x20]
	cmp r0, #0
	beq _08202988
	ldrh r0, [r4, #0x22]
	bl FUN_0823b9cc
	ldrh r0, [r4, #0x20]
	subs r0, #1
	strh r0, [r4, #0x20]
_08202988:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08202990: .4byte 0x000006DA
_08202994: .4byte 0x03002BC0

	thumb_func_start Entity08202cd8_Destroy
Entity08202cd8_Destroy: @ 0x08202998
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x28
	movs r5, #7
_082029A0:
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _082029A0
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082029b8
FUN_082029b8: @ 0x082029B8
	bx lr
	.align 2, 0

	thumb_func_start FUN_082029bc
FUN_082029bc: @ 0x082029BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r0, r6, #0
	adds r0, #0x24
	movs r1, #4
	strb r1, [r0]
	adds r1, r6, #0
	adds r1, #0x25
	movs r0, #0xf
	strb r0, [r1]
	adds r4, r6, #0
	adds r4, #0x28
	movs r5, #7
_082029DE:
	adds r0, r4, #0
	bl FUN_08200b38
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _082029DE
	mov r0, r8
	adds r1, r7, #0
	bl Hitbox_ApplyDamage
	ldr r1, _08202A10 @ =0x000006EC
	adds r0, r6, r1
	ldrh r1, [r7, #0x3e]
	str r1, [r0]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08202A10: .4byte 0x000006EC

	thumb_func_start Entity08202cd8_Init
Entity08202cd8_Init: @ 0x08202A14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x40
	adds r7, r0, #0
	adds r5, r1, #0
	mov r8, r2
	mov sb, r3
	movs r0, #0
	ldrsh r6, [r5, r0]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08202A50
	cmp r1, #0
	blt _08202A50
	ldr r0, _08202A54 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08202A50
	ldr r0, _08202A58 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08202A5C
_08202A50:
	movs r4, #0
	b _08202A6A
	.align 2, 0
_08202A54: .4byte 0x030046A8
_08202A58: .4byte 0x030046AC
_08202A5C:
	ldr r0, _08202A7C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08202A6A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08202A80
	adds r0, #4
	b _08202A8C
	.align 2, 0
_08202A7C: .4byte 0x030046A4
_08202A80:
	ldr r0, _08202B18 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08202A8C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #4
	ldrsh r3, [r5, r2]
	add r2, sp, #0xc
	adds r0, r2, #0
	strh r6, [r0]
	strh r1, [r2, #2]
	strh r3, [r2, #4]
	ldr r3, _08202B1C @ =0x0000069C
	adds r3, r7, r3
	str r3, [sp, #0x24]
	movs r0, #0xd7
	lsls r0, r0, #3
	adds r0, r7, r0
	str r0, [sp, #0x28]
	ldr r1, _08202B20 @ =0x00002E78
	adds r0, r3, #0
	bl Video_GetAuxSprite
	ldr r1, _08202B24 @ =0x00002E7B
	ldr r0, [sp, #0x28]
	bl Video_GetAuxSprite
	ldr r1, [sp, #0x24]
	ldrh r0, [r1, #6]
	strh r0, [r7, #0x26]
	adds r6, r7, #0
	adds r6, #0x28
	ldr r2, _08202B28 @ =0x000006E2
	adds r0, r7, r2
	mov r3, r8
	strh r3, [r0]
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r7, r1
	mov r2, sb
	strh r2, [r0]
	movs r3, #0
	str r3, [sp, #0x2c]
	adds r0, r7, #0
	adds r0, #0x24
	str r0, [sp, #0x30]
	adds r1, r7, #0
	adds r1, #0x25
	str r1, [sp, #0x34]
	mov sl, r3
	add r2, sp, #0x14
	mov sb, r2
	add r3, sp, #0x1c
	mov r8, r3
	movs r0, #0x82
	lsls r0, r0, #3
	str r0, [sp, #0x38]
	movs r1, #0xc8
	lsls r1, r1, #1
	str r1, [sp, #0x3c]
_08202B02:
	ldr r2, [sp, #0x2c]
	cmp r2, #2
	bgt _08202B2C
	adds r0, r6, #0
	ldr r1, [sp, #0x28]
	movs r2, #0
	bl AuxSprite_Add
	mov r3, sl
	strh r3, [r6, #0x10]
	b _08202B50
	.align 2, 0
_08202B18: .4byte 0x030046A4
_08202B1C: .4byte 0x0000069C
_08202B20: .4byte 0x00002E78
_08202B24: .4byte 0x00002E7B
_08202B28: .4byte 0x000006E2
_08202B2C:
	ldr r0, [sp, #0x2c]
	cmp r0, #4
	bgt _08202B42
	adds r0, r6, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #8
	strh r0, [r6, #0x10]
	b _08202B50
_08202B42:
	adds r0, r6, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl AuxSprite_Add
	mov r1, sl
	strh r1, [r6, #0x10]
_08202B50:
	ldr r0, [r6]
	movs r2, #1
	orrs r0, r2
	str r0, [r6]
	adds r4, r6, #0
	adds r4, #0x1c
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r3, [sp, #0x3c]
	adds r5, r7, r3
	ldr r0, [sp, #0x14]
	ldr r1, _08202CAC @ =0xFFFF0000
	ands r0, r1
	movs r2, #0x32
	orrs r0, r2
	ldr r3, _08202CB0 @ =0x0000FFFF
	ands r0, r3
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x14]
	mov r1, sb
	ldr r0, [r1, #4]
	ldr r2, _08202CAC @ =0xFFFF0000
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	str r0, [r1, #4]
	movs r0, #0
	str r0, [sp, #0x1c]
	mov r1, r8
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0x10
	str r2, [sp]
	mov r3, sb
	str r3, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	ldr r2, _08202CB4 @ =0x00003001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	ldr r1, _08202CB8 @ =FUN_082029b8
	adds r2, r7, #0
	bl Hitbox_SetHandler
	movs r1, #0xdc
	lsls r1, r1, #3
	adds r0, r7, r1
	ldrh r1, [r0]
	mov r2, sl
	str r2, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r5, #0
	movs r2, #0x64
	movs r3, #0
	bl Hitbox_SetAttack
	ldr r3, [sp, #0x38]
	adds r5, r7, r3
	movs r1, #0x64
	add r0, sp, #0x14
	strh r1, [r0]
	mov r0, sb
	strh r1, [r0, #2]
	strh r1, [r0, #4]
	add r0, sp, #0x1c
	mov r1, sl
	strh r1, [r0]
	mov r2, r8
	strh r1, [r2, #2]
	strh r1, [r2, #4]
	movs r3, #0x10
	str r3, [sp]
	mov r0, sb
	str r0, [sp, #4]
	str r2, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	ldr r2, _08202CBC @ =0x00005001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	ldr r1, _08202CC0 @ =FUN_082029bc
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldr r1, _08202CC4 @ =0x000006E2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #8
	movs r3, #4
	bl Hitbox_SetPowerAndAttributes
	adds r0, r5, #0
	bl Hitbox_Register
	adds r6, #0x2c
	ldr r2, [sp, #0x38]
	adds r2, #0x50
	str r2, [sp, #0x38]
	ldr r3, [sp, #0x3c]
	adds r3, #0x50
	str r3, [sp, #0x3c]
	ldr r0, [sp, #0x2c]
	adds r0, #1
	str r0, [sp, #0x2c]
	cmp r0, #7
	bgt _08202C52
	b _08202B02
_08202C52:
	movs r2, #0
	ldr r1, _08202CC8 @ =0x00000694
	adds r3, r7, r1
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r3]
	str r1, [r3, #4]
	str r2, [r7, #0x1c]
	ldr r3, [sp, #0x30]
	strb r2, [r3]
	ldr r0, [sp, #0x34]
	strb r2, [r0]
	movs r1, #0
	strh r2, [r7, #0x20]
	strh r2, [r7, #0x22]
	ldr r3, _08202CCC @ =0x000006DB
	adds r0, r7, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r7, r3
	strb r1, [r0]
	subs r3, #8
	adds r0, r7, r3
	str r2, [r0]
	str r2, [r7, #0x18]
	adds r3, #4
	adds r0, r7, r3
	movs r3, #1
	strb r3, [r0]
	ldr r3, _08202CD0 @ =0x000006EC
	adds r0, r7, r3
	str r2, [r0]
	ldr r2, _08202CD4 @ =0x000006DD
	adds r0, r7, r2
	strb r1, [r0]
	movs r0, #0
	add sp, #0x40
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08202CAC: .4byte 0xFFFF0000
_08202CB0: .4byte 0x0000FFFF
_08202CB4: .4byte 0x00003001
_08202CB8: .4byte FUN_082029b8
_08202CBC: .4byte 0x00005001
_08202CC0: .4byte FUN_082029bc
_08202CC4: .4byte 0x000006E2
_08202CC8: .4byte 0x00000694
_08202CCC: .4byte 0x000006DB
_08202CD0: .4byte 0x000006EC
_08202CD4: .4byte 0x000006DD

	thumb_func_start Entity08202cd8_Create
Entity08202cd8_Create: @ 0x08202CD8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xde
	lsls r1, r1, #3
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08202D1C
	ldr r1, _08202D14 @ =Entity08202cd8_Update
	ldr r2, _08202D18 @ =Entity08202cd8_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl Entity08202cd8_Init
	cmp r0, #0
	bge _08202D1C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08202D1E
	.align 2, 0
_08202D14: .4byte Entity08202cd8_Update
_08202D18: .4byte Entity08202cd8_Destroy
_08202D1C:
	adds r0, r4, #0
_08202D1E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
