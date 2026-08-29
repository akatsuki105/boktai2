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
	bl FUN_0822b20c
	pop {r0}
	bx r0

	thumb_func_start FUN_08200b48
FUN_08200b48: @ 0x08200B48
	push {lr}
	ldr r0, [r0, #0xc]
	ldr r1, _08200B58 @ =0x00000231
	bl FUN_0822b20c
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
	bl FUN_082364c4
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
	bl FUN_082364c4
	mov r1, sl
	ldrb r0, [r1]
	cmp r0, #0
	bne _08200D4C
	adds r0, r7, #0
	bl FUN_08236400
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
	bl FUN_0823785c
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
	bl FUN_0823785c
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
	bl FUN_082364c4
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
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
	bl FUN_0823785c
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

	thumb_func_start FUN_08202940
FUN_08202940: @ 0x08202940
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

	thumb_func_start FUN_08202998
FUN_08202998: @ 0x08202998
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x28
	movs r5, #7
_082029A0:
	adds r0, r4, #0
	bl FUN_0822a4e0
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
	bl FUN_08236524
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

	thumb_func_start FUN_08202a14
FUN_08202a14: @ 0x08202A14
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
	bl FUN_0822b16c
	ldr r1, _08202B24 @ =0x00002E7B
	ldr r0, [sp, #0x28]
	bl FUN_0822b16c
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
	bl FUN_0822a470
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
	bl FUN_0822a470
	movs r0, #8
	strh r0, [r6, #0x10]
	b _08202B50
_08202B42:
	adds r0, r6, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl FUN_0822a470
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
	bl FUN_0823646c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	ldr r1, _08202CB8 @ =FUN_082029b8
	adds r2, r7, #0
	bl FUN_0823651c
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
	bl FUN_082364f8
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
	bl FUN_0823646c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	ldr r1, _08202CC0 @ =FUN_082029bc
	adds r2, r7, #0
	bl FUN_0823651c
	ldr r1, _08202CC4 @ =0x000006E2
	adds r0, r7, r1
	ldrh r1, [r0]
	adds r0, r5, #0
	movs r2, #8
	movs r3, #4
	bl FUN_08236514
	adds r0, r5, #0
	bl FUN_08236400
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

	thumb_func_start FUN_08202cd8
FUN_08202cd8: @ 0x08202CD8
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
	ldr r1, _08202D14 @ =FUN_08202940
	ldr r2, _08202D18 @ =FUN_08202998
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_08202a14
	cmp r0, #0
	bge _08202D1C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08202D1E
	.align 2, 0
_08202D14: .4byte FUN_08202940
_08202D18: .4byte FUN_08202998
_08202D1C:
	adds r0, r4, #0
_08202D1E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08202d24
FUN_08202d24: @ 0x08202D24
	adds r3, r0, #0
	adds r3, #0xfa
	movs r2, #0
	strb r1, [r3]
	adds r0, #0xfb
	strb r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08202d34
FUN_08202d34: @ 0x08202D34
	push {lr}
	adds r0, r2, #0
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _08202D48
	adds r0, r2, #0
	movs r1, #1
	bl FUN_08202d24
_08202D48:
	pop {r0}
	bx r0

	thumb_func_start FUN_08202d4c
FUN_08202d4c: @ 0x08202D4C
	push {r4, lr}
	sub sp, #4
	adds r4, r2, #0
	adds r0, r4, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #0
	beq _08202D88
	adds r0, r4, #0
	adds r0, #0xfa
	ldrb r0, [r0]
	cmp r0, #0
	bne _08202D88
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r4, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #4
	movs r1, #2
	movs r3, #0x40
	bl FUN_08015c90
	adds r0, r4, #0
	bl FUN_08202ff8
_08202D88:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08202d90
FUN_08202d90: @ 0x08202D90
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r2, _08202E08 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _08202E0C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _08202E10 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08202E14 @ =FUN_08202d4c
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
	adds r0, r4, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08202E08: .4byte 0xFFFF0000
_08202E0C: .4byte 0x0000FFFF
_08202E10: .4byte 0x00004001
_08202E14: .4byte FUN_08202d4c

	thumb_func_start FUN_08202e18
FUN_08202e18: @ 0x08202E18
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
	ldr r2, _08202EA4 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _08202EA8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x8c
	ldr r2, _08202EAC @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _08202EB0 @ =FUN_08202d34
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r5, #0x1c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08202EA4: .4byte 0xFFFF0000
_08202EA8: .4byte 0x0000FFFF
_08202EAC: .4byte 0x00002001
_08202EB0: .4byte FUN_08202d34

	thumb_func_start FUN_08202eb4
FUN_08202eb4: @ 0x08202EB4
	push {r4, lr}
	ldr r0, _08202EC8 @ =0x03000218
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #7
	bls _08202ED0
	b _08202EF4
	.align 2, 0
_08202EC8: .4byte 0x03000218
_08202ECC:
	adds r0, r1, #0
	b _08202EF6
_08202ED0:
	adds r1, #0x40
	movs r2, #0
	movs r4, #1
	movs r3, #0x82
	lsls r3, r3, #1
_08202EDA:
	adds r0, r1, #0
	adds r0, #0xec
	ldrh r0, [r0]
	cmp r0, #0
	bne _08202EEC
	ldr r0, [r1]
	ands r0, r4
	cmp r0, #0
	bne _08202ECC
_08202EEC:
	adds r1, r1, r3
	adds r2, #1
	cmp r2, #7
	ble _08202EDA
_08202EF4:
	movs r0, #0
_08202EF6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08202efc
FUN_08202efc: @ 0x08202EFC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	mov sb, r3
	ldr r0, _08202F4C @ =0x03000218
	ldr r5, [r0]
	bl FUN_08202eb4
	adds r4, r0, #0
	cmp r4, #0
	beq _08202FE8
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08202d24
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	cmp r7, #0
	bne _08202F54
	adds r1, r4, #0
	adds r1, #0xdc
	str r7, [sp, #4]
	add r0, sp, #4
	ldr r2, _08202F50 @ =0x05000002
	bl CpuSet
	b _08202F60
	.align 2, 0
_08202F4C: .4byte 0x03000218
_08202F50: .4byte 0x05000002
_08202F54:
	adds r2, r4, #0
	adds r2, #0xdc
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
_08202F60:
	cmp r6, #0
	bne _08202F84
	adds r1, r4, #0
	adds r1, #0xe4
	str r6, [sp, #4]
	add r0, sp, #4
	ldr r2, _08202F80 @ =0x05000002
	bl CpuSet
	adds r0, r4, #0
	adds r0, #0xfe
	strb r6, [r0]
	subs r0, #2
	strh r6, [r0]
	b _08202FA0
	.align 2, 0
_08202F80: .4byte 0x05000002
_08202F84:
	adds r2, r4, #0
	adds r2, #0xe4
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r1, [r7]
	adds r0, r4, #0
	adds r0, #0xfc
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xfe
	movs r0, #1
	strb r0, [r1]
_08202FA0:
	adds r1, r4, #0
	adds r1, #0xec
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r0, [sp, #0x2c]
	str r0, [sp]
	adds r0, r4, #0
	mov r1, sb
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl FUN_08202e18
	adds r1, r4, #0
	adds r1, #0xf0
	ldr r0, [sp, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x3c]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x40]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x44]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x48]
	strh r0, [r1]
_08202FE8:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08202ff8
FUN_08202ff8: @ 0x08202FF8
	push {lr}
	adds r3, r0, #0
	ldr r0, _08203030 @ =0x03000218
	ldr r0, [r0]
	cmp r3, #0
	beq _0820302A
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xec
	strh r2, [r0]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r2, r3, #0
	adds r2, #0x3c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0820302A:
	pop {r0}
	bx r0
	.align 2, 0
_08203030: .4byte 0x03000218

	thumb_func_start FUN_08203034
FUN_08203034: @ 0x08203034
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r1, #0
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	adds r0, #0xfe
	ldrb r0, [r0]
	cmp r0, #0
	beq _0820312E
	adds r4, r7, #0
	adds r4, #0xdc
	adds r5, r7, #0
	adds r5, #0xe4
	movs r1, #0x1c
	adds r1, r1, r7
	mov sb, r1
	ldrh r0, [r5]
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r5, #2]
	mov r2, sb
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r3, #0xfc
	adds r3, r3, r7
	mov r8, r3
	ldrh r0, [r3]
	mov sl, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #2
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [sp, #4]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	str r5, [sp, #8]
	mov r5, r8
	cmp r6, #0
	bne _082030BC
	movs r1, #1
	rsbs r1, r1, #0
	b _082030F4
_082030BC:
	movs r1, #0
	ldrsh r0, [r4, r1]
	mov r2, sl
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4]
	movs r3, #2
	ldrsh r0, [r4, r3]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #2]
	movs r2, #4
	ldrsh r0, [r4, r2]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r6, #0
	bl Div
	strh r0, [r4, #4]
	ldr r1, [sp, #4]
_082030F4:
	ldrh r0, [r5]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r1, r0
	bgt _08203110
	ldr r3, [sp, #8]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r0, #1
	str r0, [sp]
	b _08203150
_08203110:
	ldrh r0, [r4]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r0, [r4, #2]
	mov r2, sb
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	mov r3, sb
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r3, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	b _08203150
_0820312E:
	adds r2, r7, #0
	adds r2, #0x1c
	adds r1, r7, #0
	adds r1, #0xdc
	ldrh r0, [r1]
	ldrh r3, [r7, #0x1c]
	adds r0, r0, r3
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	mov sb, r2
_08203150:
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
	beq _08203180
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _08203188
_08203180:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08203188:
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
	beq _082031AC
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _082031B4
_082031AC:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082031B4:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _082031EC @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08203224
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082031F0
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082031E4
	ldrb r0, [r4, #5]
_082031E4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08203200
	.align 2, 0
_082031EC: .4byte 0x0000FFFF
_082031F0:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08203200
	strh r1, [r4, #8]
_08203200:
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
	bne _08203224
	movs r0, #1
	strb r0, [r4, #7]
_08203224:
	adds r4, r7, #0
	adds r4, #0x8c
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	subs r4, #0x50
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl FUN_082364c4
	adds r1, r7, #0
	adds r1, #0xee
	ldrh r0, [r1]
	cmp r0, #0
	beq _0820325A
	subs r0, #1
	strh r0, [r1]
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _08203262
_0820325A:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
_08203262:
	strh r0, [r4, #6]
	adds r1, r7, #0
	adds r1, #0xfb
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	subs r1, #0xf
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _08203282
	movs r3, #1
	str r3, [sp]
_08203282:
	ldr r0, [sp]
	cmp r0, #0
	beq _08203290
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08202d24
_08203290:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_082032a0
FUN_082032a0: @ 0x082032A0
	push {r4, lr}
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0xfb
	ldrb r0, [r3]
	cmp r0, #0
	bne _082032BE
	movs r0, #0x1e
	strh r0, [r4, #0x10]
	adds r2, r4, #0
	adds r2, #0x3c
	subs r0, #0x23
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_082032BE:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _082032D4
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08202d24
_082032D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082032dc
FUN_082032dc: @ 0x082032DC
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xfb
	ldrb r0, [r3]
	cmp r0, #0
	bne _082032FC
	movs r0, #0x1f
	strh r0, [r5, #0x10]
	adds r2, r5, #0
	adds r2, #0x3c
	subs r0, #0x24
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_082032FC:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xa
	bls _08203340
	adds r0, r5, #0
	adds r0, #0x1c
	adds r1, r5, #0
	adds r1, #0xf0
	ldrh r1, [r1]
	adds r2, r5, #0
	adds r2, #0xf2
	ldrh r2, [r2]
	adds r3, r5, #0
	adds r3, #0xf4
	ldrh r3, [r3]
	adds r4, r5, #0
	adds r4, #0xf6
	ldrh r4, [r4]
	str r4, [sp]
	adds r4, r5, #0
	adds r4, #0xf8
	ldrh r4, [r4]
	str r4, [sp, #4]
	bl FUN_08203b1c
	movs r0, #0xf2
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08202ff8
_08203340:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08203348
FUN_08203348: @ 0x08203348
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r7, #0
	ldr r0, _08203394 @ =0x085AE818
	mov r8, r0
	movs r0, #0x96
	lsls r0, r0, #1
	adds r4, r6, r0
_08203360:
	ldrh r0, [r4]
	cmp r0, #0
	beq _0820337A
	ldrb r0, [r4, #0xe]
	cmp r0, #2
	bhi _08203388
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r2
_0820337A:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #7
	ble _08203360
_08203388:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08203394: .4byte 0x085AE818

	thumb_func_start FUN_08203398
FUN_08203398: @ 0x08203398
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #7
_082033A0:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _082033AC
	adds r0, r4, #0
	bl FUN_0822a4e0
_082033AC:
	adds r0, r4, #0
	adds r0, #0x3c
	bl FUN_08236424
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r5, #1
	cmp r5, #0
	bge _082033A0
	ldr r1, _082033CC @ =0x03000218
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082033CC: .4byte 0x03000218

	thumb_func_start FUN_082033d0
FUN_082033d0: @ 0x082033D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x18
	ldr r1, _08203474 @ =0x00002E78
	adds r0, r4, #0
	bl FUN_0822b16c
	ldr r1, _08203478 @ =0x00000236
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r0, _0820347C @ =0x0000922E
	ldr r1, _08203480 @ =0x000038E2
	bl GetFile
	str r0, [r7, #0x34]
	mov sb, r0
	adds r5, r7, #0
	adds r5, #0x40
	movs r6, #0
	movs r0, #7
	mov r8, r0
_08203406:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	adds r0, #0x2c
	str r6, [sp]
	mov r1, sb
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r5, #0
	bl FUN_08202d90
	str r6, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08202e18
	str r6, [sp, #4]
	add r0, sp, #4
	adds r4, r5, #0
	adds r4, #0xdc
	adds r1, r4, #0
	ldr r2, _08203484 @ =0x05000002
	bl CpuSet
	strh r6, [r4, #0x10]
	strh r6, [r4, #0x12]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r0, r8
	cmp r0, #0
	bge _08203406
	movs r0, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203474: .4byte 0x00002E78
_08203478: .4byte 0x00000236
_0820347C: .4byte 0x0000922E
_08203480: .4byte 0x000038E2
_08203484: .4byte 0x05000002

	thumb_func_start FUN_08203488
FUN_08203488: @ 0x08203488
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _082034B0 @ =0x00002E78
	bl FUN_0822b16c
	adds r0, r4, #0
	bl FUN_082033d0
	cmp r0, #0
	blt _082034B4
	movs r0, #0
	b _082034B8
	.align 2, 0
_082034B0: .4byte 0x00002E78
_082034B4:
	movs r0, #1
	rsbs r0, r0, #0
_082034B8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082034c0
FUN_082034c0: @ 0x082034C0
	push {r4, lr}
	ldr r0, _082034F8 @ =0x03000218
	ldr r0, [r0]
	cmp r0, #0
	bne _08203506
	movs r1, #0x86
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08203504
	ldr r1, _082034FC @ =FUN_08203348
	ldr r2, _08203500 @ =FUN_08203398
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08203488
	cmp r0, #0
	bge _08203504
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08203506
	.align 2, 0
_082034F8: .4byte 0x03000218
_082034FC: .4byte FUN_08203348
_08203500: .4byte FUN_08203398
_08203504:
	adds r0, r4, #0
_08203506:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820350c
FUN_0820350c: @ 0x0820350C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	mov r8, r3
	ldr r4, _08203548 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _0820352A
	bl FUN_082034c0
	str r0, [r4]
_0820352A:
	add r3, sp, #0x28
	ldr r2, _0820354C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08203550
	asrs r1, r0, #0xc
	b _08203556
	.align 2, 0
_08203548: .4byte 0x03000218
_0820354C: .4byte 0x085B0A08
_08203550:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08203556:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08203572
	asrs r0, r0, #0xc
	b _08203578
_08203572:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08203578:
	strh r0, [r3, #4]
	ldr r0, [sp, #0x48]
	str r0, [sp]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x50]
	str r0, [sp, #8]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0x24]
	adds r0, r7, #0
	add r1, sp, #0x28
	movs r2, #0
	mov r3, r8
	bl FUN_08202efc
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082035bc
FUN_082035bc: @ 0x082035BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	ldr r4, _08203618 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _082035DA
	bl FUN_082034c0
	str r0, [r4]
_082035DA:
	str r5, [sp]
	ldr r0, [sp, #0x40]
	str r0, [sp, #4]
	ldr r0, [sp, #0x44]
	str r0, [sp, #8]
	ldr r0, [sp, #0x48]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x50]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x24]
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	mov r3, r8
	bl FUN_08202efc
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203618: .4byte 0x03000218

	thumb_func_start FUN_0820361c
FUN_0820361c: @ 0x0820361C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x30
	adds r6, r0, #0
	mov r8, r1
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r4, _08203688 @ =0x03000218
	ldr r0, [r4]
	cmp r0, #0
	bne _0820363A
	bl FUN_082034c0
	str r0, [r4]
_0820363A:
	add r2, sp, #0x28
	movs r1, #0
	adds r0, r2, #0
	strh r5, [r0]
	strh r1, [r2, #2]
	strh r1, [r2, #4]
	ldr r0, [sp, #0x48]
	str r0, [sp]
	ldr r0, [sp, #0x4c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x50]
	str r0, [sp, #8]
	ldr r0, [sp, #0x54]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x58]
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x5c]
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x60]
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x64]
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x68]
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x6c]
	str r0, [sp, #0x24]
	adds r0, r6, #0
	adds r1, r2, #0
	mov r2, r8
	adds r3, r7, #0
	bl FUN_08202efc
	add sp, #0x30
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203688: .4byte 0x03000218

	thumb_func_start FUN_0820368c
FUN_0820368c: @ 0x0820368C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08203690
FUN_08203690: @ 0x08203690
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
	ldr r2, _0820371C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _08203720 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	adds r4, r5, #0
	adds r4, #0x3c
	ldr r2, _08203724 @ =0x00002001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r6, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0
	bl FUN_082364f8
	ldr r1, _08203728 @ =FUN_0820368c
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r5, #0x8c
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820371C: .4byte 0xFFFF0000
_08203720: .4byte 0x0000FFFF
_08203724: .4byte 0x00002001
_08203728: .4byte FUN_0820368c

	thumb_func_start FUN_0820372c
FUN_0820372c: @ 0x0820372C
	push {lr}
	ldr r0, _08203740 @ =0x0300021C
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #7
	bls _08203748
	b _08203768
	.align 2, 0
_08203740: .4byte 0x0300021C
_08203744:
	adds r0, r1, #0
	b _0820376A
_08203748:
	adds r1, #0x40
	movs r2, #0
	movs r3, #1
_0820374E:
	adds r0, r1, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _08203760
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _08203744
_08203760:
	adds r1, #0x98
	adds r2, #1
	cmp r2, #7
	ble _0820374E
_08203768:
	movs r0, #0
_0820376A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08203770
FUN_08203770: @ 0x08203770
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r4, r0, #0
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, _082037E4 @ =0x0300021C
	ldr r6, [r0]
	bl FUN_0820372c
	adds r5, r0, #0
	cmp r5, #0
	beq _0820384C
	adds r1, r6, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	adds r2, r5, #0
	adds r2, #0x8c
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r1, #2
	ldrsh r2, [r4, r1]
	movs r1, #4
	ldrsh r3, [r4, r1]
	adds r1, r5, #0
	adds r1, #0x1c
	subs r0, #0x80
	strh r0, [r5, #0x1c]
	strh r2, [r1, #2]
	strh r3, [r1, #4]
	ldrh r0, [r5, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	asrs r1, r3, #8
	cmp r2, #0
	blt _082037DE
	cmp r1, #0
	blt _082037DE
	ldr r0, _082037E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _082037DE
	ldr r0, _082037EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _082037F0
_082037DE:
	movs r4, #0
	b _082037FE
	.align 2, 0
_082037E4: .4byte 0x0300021C
_082037E8: .4byte 0x030046A8
_082037EC: .4byte 0x030046AC
_082037F0:
	ldr r0, _08203810 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_082037FE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08203814
	adds r0, #4
	b _08203820
	.align 2, 0
_08203810: .4byte 0x030046A4
_08203814:
	ldr r0, _0820385C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08203820:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r5, #0x1e]
	adds r1, r5, #0
	adds r1, #0x94
	ldr r0, [sp, #0x24]
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	mov r2, r8
	mov r3, sb
	bl FUN_08203690
_0820384C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820385C: .4byte 0x030046A4

	thumb_func_start FUN_08203860
FUN_08203860: @ 0x08203860
	push {lr}
	adds r3, r0, #0
	ldr r0, _0820388C @ =0x0300021C
	ldr r0, [r0]
	cmp r3, #0
	beq _08203886
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0x94
	strh r2, [r0]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_08203886:
	pop {r0}
	bx r0
	.align 2, 0
_0820388C: .4byte 0x0300021C

	thumb_func_start FUN_08203890
FUN_08203890: @ 0x08203890
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r5, #0x40
	movs r1, #1
	mov sb, r1
	movs r2, #7
	mov r8, r2
	adds r7, r0, #0
	adds r7, #0xd4
_082038A8:
	ldrh r0, [r7]
	cmp r0, #0
	bne _082038B0
	b _082039C0
_082038B0:
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
	mov r2, sb
	ands r2, r0
	ldrh r1, [r6]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r3, sb
	ands r0, r3
	cmp r2, r0
	beq _082038E0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _082038E8
_082038E0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082038E8:
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
	beq _0820390C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08203914
_0820390C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08203914:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _0820394C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08203984
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08203950
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08203944
	ldrb r0, [r4, #5]
_08203944:
	subs r0, #1
	strh r0, [r4, #8]
	b _08203960
	.align 2, 0
_0820394C: .4byte 0x0000FFFF
_08203950:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08203960
	strh r1, [r4, #8]
_08203960:
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
	bne _08203984
	mov r3, sb
	strb r3, [r4, #7]
_08203984:
	adds r4, r5, #0
	adds r4, #0x3c
	adds r1, r5, #0
	adds r1, #0x8c
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	ldrh r0, [r7]
	cmp r0, #0x3b
	bhi _082039AE
	movs r1, #0x3c
	subs r1, r1, r0
	adds r0, r5, #0
	movs r2, #0x14
	movs r3, #0x1e
	bl FUN_082375c8
_082039AE:
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _082039C0
	adds r0, r5, #0
	bl FUN_08203860
_082039C0:
	adds r7, #0x98
	adds r5, #0x98
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	blt _082039D2
	b _082038A8
_082039D2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082039e0
FUN_082039e0: @ 0x082039E0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #7
_082039E8:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _082039F4
	adds r0, r4, #0
	bl FUN_0822a4e0
_082039F4:
	adds r4, #0x98
	subs r5, #1
	cmp r5, #0
	bge _082039E8
	ldr r1, _08203A08 @ =0x0300021C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08203A08: .4byte 0x0300021C

	thumb_func_start FUN_08203a0c
FUN_08203a0c: @ 0x08203A0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x18
	ldr r1, _08203A88 @ =0x0000A5B3
	adds r0, r4, #0
	bl FUN_0822b16c
	ldr r1, _08203A8C @ =0x00000236
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r0, _08203A90 @ =0x0000922E
	ldr r1, _08203A94 @ =0x00001752
	bl GetFile
	mov r8, r0
	adds r4, #0x28
	movs r6, #0
	movs r5, #7
_08203A3A:
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_0822a470
	adds r0, r4, #0
	adds r0, #0x2c
	str r6, [sp]
	mov r1, r8
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	str r6, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08203690
	adds r0, r4, #0
	adds r0, #0x94
	strh r6, [r0]
	adds r4, #0x98
	subs r5, #1
	cmp r5, #0
	bge _08203A3A
	movs r0, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203A88: .4byte 0x0000A5B3
_08203A8C: .4byte 0x00000236
_08203A90: .4byte 0x0000922E
_08203A94: .4byte 0x00001752

	thumb_func_start FUN_08203a98
FUN_08203a98: @ 0x08203A98
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _08203AC0 @ =0x0000A5B3
	bl FUN_0822b16c
	adds r0, r4, #0
	bl FUN_08203a0c
	cmp r0, #0
	blt _08203AC4
	movs r0, #0
	b _08203AC8
	.align 2, 0
_08203AC0: .4byte 0x0000A5B3
_08203AC4:
	movs r0, #1
	rsbs r0, r0, #0
_08203AC8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08203ad0
FUN_08203ad0: @ 0x08203AD0
	push {r4, lr}
	ldr r0, _08203B08 @ =0x0300021C
	ldr r0, [r0]
	cmp r0, #0
	bne _08203B16
	movs r1, #0xa0
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08203B14
	ldr r1, _08203B0C @ =FUN_08203890
	ldr r2, _08203B10 @ =FUN_082039e0
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08203a98
	cmp r0, #0
	bge _08203B14
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08203B16
	.align 2, 0
_08203B08: .4byte 0x0300021C
_08203B0C: .4byte FUN_08203890
_08203B10: .4byte FUN_082039e0
_08203B14:
	adds r0, r4, #0
_08203B16:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08203b1c
FUN_08203b1c: @ 0x08203B1C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov r8, r3
	ldr r4, _08203B5C @ =0x0300021C
	ldr r0, [r4]
	cmp r0, #0
	bne _08203B3A
	bl FUN_08203ad0
	str r0, [r4]
_08203B3A:
	ldr r0, [sp, #0x20]
	str r0, [sp]
	ldr r0, [sp, #0x24]
	str r0, [sp, #4]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_08203770
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203B5C: .4byte 0x0300021C

	thumb_func_start FUN_08203b60
FUN_08203b60: @ 0x08203B60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r6, #0xc0
	mov r5, sp
	ldr r1, _08203BB0 @ =0x085B0A08
	mov r8, r1
	movs r7, #1
	movs r1, #0xff
	mov ip, r1
	adds r4, r0, #0
	adds r4, #0x64
_08203B7C:
	ldr r0, [r6]
	ldrb r0, [r0, #5]
	subs r0, #0x20
	movs r1, #0x40
	rsbs r1, r1, #0
	ands r0, r1
	adds r2, r0, #0
	adds r2, #0x40
	movs r0, #0x12
	ldrsb r0, [r4, r0]
	adds r2, r2, r0
	movs r0, #0x10
	ldrsh r3, [r4, r0]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, ip
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08203BB4
	asrs r1, r0, #0xc
	b _08203BBA
	.align 2, 0
_08203BB0: .4byte 0x085B0A08
_08203BB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08203BBA:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	mov r0, ip
	ands r2, r0
	lsls r0, r2, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _08203BD6
	asrs r3, r0, #0xc
	b _08203BDC
_08203BD6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08203BDC:
	strh r3, [r5, #4]
	ldr r1, [r6]
	adds r2, r1, #0
	adds r2, #8
	ldrh r0, [r5]
	ldrh r1, [r1, #8]
	adds r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r5, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	adds r4, #0x44
	subs r7, #1
	cmp r7, #0
	bge _08203B7C
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08203c10
FUN_08203c10: @ 0x08203C10
	push {lr}
	adds r1, r0, #0
	adds r1, #0x38
	movs r3, #1
	movs r2, #1
_08203C1A:
	ldr r0, [r1, #0x10]
	orrs r0, r3
	str r0, [r1, #0x10]
	adds r1, #0x44
	subs r2, #1
	cmp r2, #0
	bge _08203C1A
	pop {r0}
	bx r0

	thumb_func_start FUN_08203c2c
FUN_08203c2c: @ 0x08203C2C
	push {lr}
	adds r1, r0, #0
	adds r1, #0x38
	movs r3, #2
	rsbs r3, r3, #0
	movs r2, #1
_08203C38:
	ldr r0, [r1, #0x10]
	ands r0, r3
	str r0, [r1, #0x10]
	adds r1, #0x44
	subs r2, #1
	cmp r2, #0
	bge _08203C38
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08203c4c
FUN_08203c4c: @ 0x08203C4C
	adds r0, #0xc4
	ldr r2, [r0]
	orrs r2, r1
	str r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08203c58
FUN_08203c58: @ 0x08203C58
	adds r0, #0xc4
	ldr r2, [r0]
	bics r2, r1
	str r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08203c64
FUN_08203c64: @ 0x08203C64
	push {lr}
	adds r2, r0, #0
	adds r2, #0x38
	movs r3, #1
_08203C6C:
	ldr r0, [r2, #0x1c]
	str r1, [r0, #0xc]
	adds r2, #0x44
	subs r3, #1
	cmp r3, #0
	bge _08203C6C
	pop {r0}
	bx r0

	thumb_func_start FUN_08203c7c
FUN_08203c7c: @ 0x08203C7C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r6, r1, #0
	adds r5, r3, #0
	adds r0, #0xc9
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #1
	cmp r0, #1
	bhi _08203C98
	movs r3, #0
_08203C98:
	movs r0, #0
	cmp r1, #1
	bls _08203CA0
	movs r0, #1
_08203CA0:
	ldr r1, [r4, #0x18]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	orrs r0, r5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp]
	adds r0, r6, #0
	bl FUN_08236fac
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08203cbc
FUN_08203cbc: @ 0x08203CBC
	push {r4, lr}
	sub sp, #0x40
	movs r1, #0
	movs r2, #0
	str r1, [sp, #0x38]
	str r2, [sp, #0x3c]
	ldr r2, _08203D00 @ =0x0000F422
	ldr r3, _08203D04 @ =0x0000121B
	movs r1, #6
	str r1, [sp]
	movs r1, #0
	str r1, [sp, #4]
	movs r4, #9
	str r4, [sp, #8]
	ldr r4, _08203D08 @ =0x00000237
	str r4, [sp, #0xc]
	movs r4, #1
	str r4, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	str r1, [sp, #0x2c]
	str r1, [sp, #0x30]
	str r1, [sp, #0x34]
	add r1, sp, #0x38
	bl FUN_081f22c0
	add sp, #0x40
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08203D00: .4byte 0x0000F422
_08203D04: .4byte 0x0000121B
_08203D08: .4byte 0x00000237

	thumb_func_start FUN_08203d0c
FUN_08203d0c: @ 0x08203D0C
	push {lr}
	adds r2, r0, #0
	adds r3, r2, #0
	adds r3, #0xca
	movs r0, #0
	strb r1, [r3]
	adds r1, r2, #0
	adds r1, #0xcb
	strb r0, [r1]
	subs r1, #0x93
	movs r3, #0
	movs r2, #1
_08203D24:
	adds r0, r1, #0
	adds r0, #0x42
	strb r3, [r0, #1]
	strb r3, [r0]
	adds r1, #0x44
	subs r2, #1
	cmp r2, #0
	bge _08203D24
	pop {r0}
	bx r0

	thumb_func_start FUN_08203d38
FUN_08203d38: @ 0x08203D38
	adds r0, #0xcb
	movs r1, #1
	strb r1, [r0]
	bx lr

	thumb_func_start FUN_08203d40
FUN_08203d40: @ 0x08203D40
	movs r0, #0
	bx lr

	thumb_func_start FUN_08203d44
FUN_08203d44: @ 0x08203D44
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x42
	ldrb r6, [r0]
	cmp r6, #1
	bne _08203D5C
	b _08203EF0
_08203D5C:
	cmp r6, #1
	bgt _08203D66
	cmp r6, #0
	beq _08203D6E
	b _082040C0
_08203D66:
	cmp r6, #2
	bne _08203D6C
	b _082040A4
_08203D6C:
	b _082040C0
_08203D6E:
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _08203DE8
	cmp r2, #0
	bne _08203D86
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0xe2
	b _08203D8C
_08203D86:
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0x1e
_08203D8C:
	strb r0, [r1]
	movs r0, #0xfa
	strh r0, [r4, #0x3c]
	adds r0, r7, #0
	bl FUN_08203c2c
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	ands r3, r0
	adds r0, r7, #0
	adds r0, #0xc9
	strb r3, [r0]
	ldr r2, _08203E18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08203E1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08203E20 @ =0x0203B400
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #1
	ands r5, r0
	ldr r1, [r7, #0x18]
	movs r0, #0
	cmp r3, #1
	bls _08203DD6
	movs r0, #1
_08203DD6:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #7
	adds r3, r5, #0
	bl FUN_08236fac
	movs r0, #1
	mov r2, r8
	strb r0, [r2]
_08203DE8:
	adds r6, r4, #0
	adds r6, #0x10
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
	beq _08203E24
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08203E2C
	.align 2, 0
_08203E18: .4byte 0x030046B8
_08203E1C: .4byte 0x000003FF
_08203E20: .4byte 0x0203B400
_08203E24:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08203E2C:
	str r0, [r4, #0x10]
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
	beq _08203E50
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08203E58
_08203E50:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08203E58:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08203E90 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08203ED6
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08203E9A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08203E94
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08203EB0
	.align 2, 0
_08203E90: .4byte 0x0000FFFF
_08203E94:
	subs r0, #1
	strh r0, [r4, #8]
	b _08203EAE
_08203E9A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08203EAE
	strh r1, [r4, #8]
	movs r2, #1
	b _08203EB0
_08203EAE:
	movs r2, #0
_08203EB0:
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
	bne _08203ED8
	movs r0, #1
	strb r0, [r4, #7]
	b _08203ED8
_08203ED6:
	movs r2, #0
_08203ED8:
	adds r0, r4, #0
	adds r0, #0x3f
	strb r2, [r0]
	cmp r2, #0
	bne _08203EE4
	b _082040C0
_08203EE4:
	adds r1, r4, #0
	adds r1, #0x42
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _082040C0
_08203EF0:
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r1, [r0]
	mov r8, r0
	cmp r1, #0
	bne _08203F4A
	adds r0, r7, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r3, #3
	ands r3, r0
	adds r0, r7, #0
	adds r0, #0xc9
	strb r3, [r0]
	ldr r2, _08203F7C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08203F80 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08203F84 @ =0x0203B400
	adds r0, r0, r1
	ldrh r5, [r0]
	movs r0, #1
	ands r5, r0
	ldr r1, [r7, #0x18]
	movs r0, #0
	cmp r3, #1
	bls _08203F3A
	movs r0, #1
_08203F3A:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #7
	adds r3, r5, #0
	bl FUN_08236fac
	mov r2, r8
	strb r6, [r2]
_08203F4A:
	adds r6, r4, #0
	adds r6, #0x10
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
	beq _08203F88
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08203F90
	.align 2, 0
_08203F7C: .4byte 0x030046B8
_08203F80: .4byte 0x000003FF
_08203F84: .4byte 0x0203B400
_08203F88:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08203F90:
	str r0, [r4, #0x10]
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
	beq _08203FB4
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08203FBC
_08203FB4:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08203FBC:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08203FF4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0820403A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08203FFE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08203FF8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204014
	.align 2, 0
_08203FF4: .4byte 0x0000FFFF
_08203FF8:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204012
_08203FFE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204012
	strh r1, [r4, #8]
	movs r2, #1
	b _08204014
_08204012:
	movs r2, #0
_08204014:
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
	bne _0820403C
	movs r0, #1
	strb r0, [r4, #7]
	b _0820403C
_0820403A:
	movs r2, #0
_0820403C:
	adds r6, r4, #0
	adds r6, #0x3f
	strb r2, [r6]
	cmp r2, #0
	beq _082040C0
	adds r0, r7, #0
	adds r0, #0xcb
	ldrb r5, [r0]
	cmp r5, #0
	beq _08204060
	adds r0, r4, #0
	adds r0, #0x42
	movs r1, #2
	strb r1, [r0]
	movs r0, #0
	mov r1, r8
	strb r0, [r1]
	b _082040C0
_08204060:
	ldr r2, _08204098 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0820409C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _082040A0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r3, [r0]
	movs r0, #1
	ands r3, r0
	ldr r1, [r7, #0x18]
	movs r2, #0
	adds r0, r7, #0
	adds r0, #0xc9
	ldrb r0, [r0]
	cmp r0, #1
	bls _08204088
	movs r2, #1
_08204088:
	str r2, [sp]
	adds r0, r4, #0
	movs r2, #7
	bl FUN_08236fac
	strb r5, [r6]
	b _082040C0
	.align 2, 0
_08204098: .4byte 0x030046B8
_0820409C: .4byte 0x000003FF
_082040A0: .4byte 0x0203B400
_082040A4:
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_08203cbc
	movs r0, #0xdb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r4, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x10]
	movs r0, #1
	b _082040C2
_082040C0:
	movs r0, #0
_082040C2:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082040d0
FUN_082040d0: @ 0x082040D0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x42
	ldrb r0, [r3]
	cmp r0, #1
	bne _082040E2
	b _0820424A
_082040E2:
	cmp r0, #1
	bgt _082040EC
	cmp r0, #0
	beq _082040F4
	b _08204388
_082040EC:
	cmp r0, #2
	bne _082040F2
	b _08204264
_082040F2:
	b _08204388
_082040F4:
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _0820414A
	cmp r2, #0
	bne _0820410C
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0xec
	b _08204112
_0820410C:
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0x14
_08204112:
	strb r0, [r1]
	movs r0, #0xfa
	strh r0, [r4, #0x3c]
	adds r0, r5, #0
	bl FUN_08203c2c
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xc9
	strb r1, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #4
	movs r3, #0
	bl FUN_08203c7c
	movs r0, #1
	strb r0, [r7]
_0820414A:
	adds r6, r4, #0
	adds r6, #0x10
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
	beq _0820417A
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08204182
_0820417A:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08204182:
	str r0, [r4, #0x10]
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
	beq _082041A6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _082041AE
_082041A6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082041AE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _082041E8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0820422E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082041F2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082041EC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204208
	.align 2, 0
_082041E8: .4byte 0x0000FFFF
_082041EC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204206
_082041F2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204206
	strh r1, [r4, #8]
	movs r2, #1
	b _08204208
_08204206:
	movs r2, #0
_08204208:
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
	bne _08204230
	movs r0, #1
	strb r0, [r4, #7]
	b _08204230
_0820422E:
	movs r2, #0
_08204230:
	adds r0, r4, #0
	adds r0, #0x3f
	strb r2, [r0]
	cmp r2, #0
	bne _0820423C
	b _08204388
_0820423C:
	movs r0, #0
	strb r0, [r7]
	adds r1, r4, #0
	adds r1, #0x42
	movs r0, #1
	strb r0, [r1]
	b _08204388
_0820424A:
	adds r0, r5, #0
	adds r0, #0xcb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08204256
	b _08204388
_08204256:
	adds r0, r4, #0
	adds r0, #0x43
	movs r1, #0
	strb r1, [r0]
	movs r0, #2
	strb r0, [r3]
	b _08204388
_08204264:
	adds r6, r4, #0
	adds r6, #0x43
	ldrb r0, [r6]
	cmp r0, #0
	bne _0820427E
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #4
	movs r3, #4
	bl FUN_08203c7c
	movs r0, #1
	strb r0, [r6]
_0820427E:
	adds r6, r4, #0
	adds r6, #0x10
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
	beq _082042AE
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _082042B6
_082042AE:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082042B6:
	str r0, [r4, #0x10]
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
	beq _082042DA
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _082042E2
_082042DA:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082042E2:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0820431C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08204362
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08204326
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08204320
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0820433C
	.align 2, 0
_0820431C: .4byte 0x0000FFFF
_08204320:
	subs r0, #1
	strh r0, [r4, #8]
	b _0820433A
_08204326:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0820433A
	strh r1, [r4, #8]
	movs r2, #1
	b _0820433C
_0820433A:
	movs r2, #0
_0820433C:
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
	bne _08204364
	movs r0, #1
	strb r0, [r4, #7]
	b _08204364
_08204362:
	movs r2, #0
_08204364:
	adds r0, r4, #0
	adds r0, #0x3f
	strb r2, [r0]
	cmp r2, #0
	beq _08204388
	subs r0, #0x13
	bl FUN_08203cbc
	movs r0, #0xdb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r4, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x10]
	movs r0, #1
	b _0820438A
_08204388:
	movs r0, #0
_0820438A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08204390
FUN_08204390: @ 0x08204390
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	adds r2, r4, #0
	adds r2, #0x42
	ldrb r0, [r2]
	cmp r0, #1
	bne _082043A4
	b _0820452C
_082043A4:
	cmp r0, #1
	bgt _082043AE
	cmp r0, #0
	beq _082043B6
	b _08204678
_082043AE:
	cmp r0, #2
	bne _082043B4
	b _08204546
_082043B4:
	b _08204678
_082043B6:
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _0820442E
	cmp r6, #0
	bne _082043CE
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0xec
	b _082043D4
_082043CE:
	adds r1, r4, #0
	adds r1, #0x3e
	movs r0, #0x14
_082043D4:
	strb r0, [r1]
	movs r0, #0xfa
	strh r0, [r4, #0x3c]
	adds r0, r5, #0
	bl FUN_08203c2c
	adds r0, r5, #0
	adds r0, #0xc0
	ldr r0, [r0]
	ldrb r0, [r0, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r0, r5, #0
	adds r0, #0xc9
	strb r1, [r0]
	cmp r1, #1
	bls _0820440C
	cmp r6, #0
	bne _08204410
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #6
	b _08204416
_0820440C:
	cmp r6, #0
	bne _0820441E
_08204410:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #5
_08204416:
	movs r3, #0
	bl FUN_08203c7c
	b _0820442A
_0820441E:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #6
	movs r3, #0
	bl FUN_08203c7c
_0820442A:
	movs r0, #1
	strb r0, [r7]
_0820442E:
	adds r6, r4, #0
	adds r6, #0x10
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
	beq _0820445E
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08204466
_0820445E:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08204466:
	str r0, [r4, #0x10]
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
	beq _0820448A
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08204492
_0820448A:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08204492:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _082044CC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08204512
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082044D6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082044D0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _082044EC
	.align 2, 0
_082044CC: .4byte 0x0000FFFF
_082044D0:
	subs r0, #1
	strh r0, [r4, #8]
	b _082044EA
_082044D6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _082044EA
	strh r1, [r4, #8]
	movs r2, #1
	b _082044EC
_082044EA:
	movs r2, #0
_082044EC:
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
	bne _08204514
	movs r0, #1
	strb r0, [r4, #7]
	b _08204514
_08204512:
	movs r2, #0
_08204514:
	adds r0, r4, #0
	adds r0, #0x3f
	strb r2, [r0]
	cmp r2, #0
	bne _08204520
	b _08204678
_08204520:
	adds r1, r4, #0
	adds r1, #0x42
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _08204678
_0820452C:
	adds r0, r5, #0
	adds r0, #0xcb
	ldrb r0, [r0]
	cmp r0, #0
	bne _08204538
	b _08204678
_08204538:
	adds r0, r4, #0
	adds r0, #0x43
	movs r1, #0
	strb r1, [r0]
	movs r0, #2
	strb r0, [r2]
	b _08204678
_08204546:
	adds r0, r4, #0
	adds r0, #0x43
	ldrb r0, [r0]
	cmp r0, #0
	bne _0820456E
	cmp r6, #0
	bne _08204562
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #5
	movs r3, #4
	bl FUN_08203c7c
	b _0820456E
_08204562:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #6
	movs r3, #4
	bl FUN_08203c7c
_0820456E:
	adds r6, r4, #0
	adds r6, #0x10
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
	beq _0820459E
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _082045A6
_0820459E:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_082045A6:
	str r0, [r4, #0x10]
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
	beq _082045CA
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _082045D2
_082045CA:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082045D2:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0820460C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08204652
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08204616
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08204610
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0820462C
	.align 2, 0
_0820460C: .4byte 0x0000FFFF
_08204610:
	subs r0, #1
	strh r0, [r4, #8]
	b _0820462A
_08204616:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0820462A
	strh r1, [r4, #8]
	movs r2, #1
	b _0820462C
_0820462A:
	movs r2, #0
_0820462C:
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
	bne _08204654
	movs r0, #1
	strb r0, [r4, #7]
	b _08204654
_08204652:
	movs r2, #0
_08204654:
	adds r0, r4, #0
	adds r0, #0x3f
	strb r2, [r0]
	cmp r2, #0
	beq _08204678
	subs r0, #0x13
	bl FUN_08203cbc
	movs r0, #0xdb
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, [r4, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x10]
	movs r0, #1
	b _0820467A
_08204678:
	movs r0, #0
_0820467A:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08204680
FUN_08204680: @ 0x08204680
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #4
	ldr r0, _08204700 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _082046F2
	adds r0, r6, #0
	adds r0, #0xc4
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _082046AE
	adds r0, r6, #0
	bl FUN_08203b60
_082046AE:
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
	adds r7, r6, #0
	adds r7, #0xca
	ldr r0, _08204704 @ =0x085AE824
	mov sb, r0
_082046BC:
	ldrb r0, [r7]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl _call_via_r3
	cmp r0, #0
	ble _082046D6
	movs r0, #1
	add r8, r0
_082046D6:
	adds r5, #0x44
	adds r4, #1
	cmp r4, #1
	ble _082046BC
	mov r0, r8
	cmp r0, #1
	ble _082046F2
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08203d0c
	adds r0, r6, #0
	bl FUN_08203c10
_082046F2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08204700: .4byte 0x03002BC0
_08204704: .4byte 0x085AE824

	thumb_func_start FUN_08204708
FUN_08204708: @ 0x08204708
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x38
	movs r5, #1
_08204710:
	ldrb r0, [r4, #0x14]
	cmp r0, #0
	beq _0820471E
	adds r0, r4, #0
	adds r0, #0x10
	bl FUN_0822a4e0
_0820471E:
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _08204710
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08204730
FUN_08204730: @ 0x08204730
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _08204778 @ =0x0000922E
	ldr r1, _0820477C @ =0x000038E2
	bl GetFile
	str r0, [r6, #0x18]
	adds r0, r6, #0
	adds r0, #0x1c
	ldr r1, _08204780 @ =0x00002E78
	bl FUN_0822b16c
	adds r0, r6, #0
	adds r0, #0xc0
	str r4, [r0]
	adds r1, r6, #0
	adds r1, #0xca
	movs r0, #0
	strb r0, [r1]
	adds r5, r6, #0
	adds r5, #0x38
	mov r8, r0
	movs r7, #0
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x74
_0820476E:
	mov r0, r8
	cmp r0, #0
	bne _08204784
	movs r0, #0xe2
	b _08204786
	.align 2, 0
_08204778: .4byte 0x0000922E
_0820477C: .4byte 0x000038E2
_08204780: .4byte 0x00002E78
_08204784:
	movs r0, #0x1e
_08204786:
	strb r0, [r4, #2]
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0x10
	adds r1, r6, #0
	adds r1, #0x1c
	movs r2, #0
	bl FUN_0822a470
	ldr r1, [r6, #0x18]
	mov r0, sb
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #5
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r5, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x10]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	strb r7, [r4, #5]
	strb r7, [r4, #6]
	strb r7, [r4, #7]
	adds r4, #0x44
	adds r5, #0x44
	add r8, r1
	mov r0, r8
	cmp r0, #1
	ble _0820476E
	adds r0, r6, #0
	bl FUN_08203b60
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08203d0c
	adds r1, r6, #0
	adds r1, #0xc4
	movs r0, #0
	str r0, [r1]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082047f0
FUN_082047f0: @ 0x082047F0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08204828
	ldr r1, _08204820 @ =FUN_08204680
	ldr r2, _08204824 @ =FUN_08204708
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08204730
	cmp r0, #0
	bge _08204828
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0820482A
	.align 2, 0
_08204820: .4byte FUN_08204680
_08204824: .4byte FUN_08204708
_08204828:
	adds r0, r4, #0
_0820482A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08204830
FUN_08204830: @ 0x08204830
	push {r4, lr}
	ldr r0, _08204844 @ =0x03000220
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0xf
	bls _0820484C
	b _0820486A
	.align 2, 0
_08204844: .4byte 0x03000220
_08204848:
	adds r0, r1, #0
	b _0820486C
_0820484C:
	adds r1, #0x40
	movs r2, #0
	movs r3, #1
_08204852:
	movs r4, #0x3c
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bgt _08204862
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _08204848
_08204862:
	adds r1, #0x44
	adds r2, #1
	cmp r2, #0xf
	ble _08204852
_0820486A:
	movs r0, #0
_0820486C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08204874
FUN_08204874: @ 0x08204874
	adds r3, r0, #0
	adds r3, #0x3e
	movs r2, #0
	strb r1, [r3]
	adds r0, #0x3f
	strb r2, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_08204884
FUN_08204884: @ 0x08204884
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	ldr r0, _082048D8 @ =0x03000220
	ldr r4, [r0]
	bl FUN_08204830
	adds r5, r0, #0
	cmp r5, #0
	beq _082048EC
	adds r4, #0x3c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08204874
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	strh r7, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #1
	strb r1, [r0]
	ldr r2, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r2, r0
	str r2, [r5]
	ldrb r0, [r4]
	ands r1, r0
	cmp r1, #0
	bne _082048E0
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r2, r0
	ldr r0, _082048DC @ =0xFFFFFBFF
	b _082048E8
	.align 2, 0
_082048D8: .4byte 0x03000220
_082048DC: .4byte 0xFFFFFBFF
_082048E0:
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r2, r0
	ldr r0, _082048F4 @ =0xFFFFFDFF
_082048E8:
	ands r2, r0
	str r2, [r5]
_082048EC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082048F4: .4byte 0xFFFFFDFF

	thumb_func_start FUN_082048f8
FUN_082048f8: @ 0x082048F8
	push {lr}
	adds r3, r0, #0
	ldr r0, _08204928 @ =0x03000220
	ldr r0, [r0]
	cmp r3, #0
	beq _08204922
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r1, #0
	strh r2, [r3, #0x3c]
	adds r0, r3, #0
	adds r0, #0x40
	strb r1, [r0]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_08204922:
	pop {r0}
	bx r0
	.align 2, 0
_08204928: .4byte 0x03000220

	thumb_func_start FUN_0820492c
FUN_0820492c: @ 0x0820492C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x3f
	ldrb r2, [r4]
	cmp r2, #0
	bne _08204952
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r3, #0x34]
	str r2, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
	strb r0, [r4]
_08204952:
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
	cmp r1, r0
	beq _08204982
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _0820498A
_08204982:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0820498A:
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
	beq _082049AE
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _082049B6
_082049AE:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_082049B6:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _082049F0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08204A36
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _082049FA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _082049F4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204A10
	.align 2, 0
_082049F0: .4byte 0x0000FFFF
_082049F4:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204A0E
_082049FA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204A0E
	strh r1, [r4, #8]
	movs r2, #1
	b _08204A10
_08204A0E:
	movs r2, #0
_08204A10:
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
	bne _08204A38
	movs r0, #1
	strb r0, [r4, #7]
	b _08204A38
_08204A36:
	movs r2, #0
_08204A38:
	ldrh r1, [r5, #0x3c]
	movs r3, #0x3c
	ldrsh r0, [r5, r3]
	cmp r0, #0
	ble _08204A46
	subs r0, r1, #1
	strh r0, [r5, #0x3c]
_08204A46:
	movs r1, #0x3c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bne _08204A5A
	cmp r2, #0
	beq _08204A5A
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08204874
_08204A5A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08204a64
FUN_08204a64: @ 0x08204A64
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r3, r0, #0
	adds r6, r1, #0
	adds r4, r6, #0
	adds r4, #0x3f
	ldrb r2, [r4]
	cmp r2, #0
	bne _08204A8A
	adds r0, r6, #0
	adds r0, #0x2c
	ldr r1, [r3, #0x34]
	str r2, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
	strb r0, [r4]
_08204A8A:
	adds r4, r6, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
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
	beq _08204ABA
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _08204AC2
_08204ABA:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08204AC2:
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
	beq _08204AE6
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08204AEE
_08204AE6:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08204AEE:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08204B28 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08204B6E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08204B32
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08204B2C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08204B48
	.align 2, 0
_08204B28: .4byte 0x0000FFFF
_08204B2C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08204B46
_08204B32:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08204B46
	strh r1, [r4, #8]
	movs r2, #1
	b _08204B48
_08204B46:
	movs r2, #0
_08204B48:
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
	bne _08204B70
	movs r0, #1
	strb r0, [r4, #7]
	b _08204B70
_08204B6E:
	movs r2, #0
_08204B70:
	cmp r2, #0
	beq _08204B7A
	adds r0, r6, #0
	bl FUN_082048f8
_08204B7A:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08204b84
FUN_08204b84: @ 0x08204B84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x40
	movs r7, #0
	ldr r0, _08204BC8 @ =0x085AE834
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x7e
_08204B9A:
	ldrb r0, [r4, #2]
	cmp r0, #1
	bne _08204BB4
	ldrb r0, [r4]
	cmp r0, #1
	bhi _08204BBE
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r2
_08204BB4:
	adds r4, #0x44
	adds r5, #0x44
	adds r7, #1
	cmp r7, #0xf
	ble _08204B9A
_08204BBE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08204BC8: .4byte 0x085AE834

	thumb_func_start FUN_08204bcc
FUN_08204bcc: @ 0x08204BCC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x40
	movs r5, #0xf
_08204BD4:
	ldrb r0, [r4, #4]
	cmp r0, #0
	beq _08204BE0
	adds r0, r4, #0
	bl FUN_0822a4e0
_08204BE0:
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _08204BD4
	ldr r1, _08204BF4 @ =0x03000220
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08204BF4: .4byte 0x03000220

	thumb_func_start FUN_08204bf8
FUN_08204bf8: @ 0x08204BF8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x18
	ldr r1, _08204C70 @ =0x00002E78
	adds r0, r4, #0
	bl FUN_0822b16c
	ldr r1, _08204C74 @ =0x00000235
	adds r0, r4, #0
	bl FUN_0822b20c
	ldr r0, _08204C78 @ =0x0000922E
	ldr r1, _08204C7C @ =0x000038E2
	bl GetFile
	str r0, [r7, #0x34]
	mov r8, r0
	adds r4, #0x28
	movs r6, #0
	movs r5, #0xf
_08204C28:
	adds r0, r4, #0
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0
	bl FUN_0822a470
	movs r0, #3
	strb r0, [r4, #7]
	adds r0, r4, #0
	adds r0, #0x2c
	str r6, [sp]
	mov r1, r8
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	strh r6, [r4, #0x3c]
	adds r0, r4, #0
	adds r0, #0x40
	strb r6, [r0]
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _08204C28
	movs r0, #0
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08204C70: .4byte 0x00002E78
_08204C74: .4byte 0x00000235
_08204C78: .4byte 0x0000922E
_08204C7C: .4byte 0x000038E2

	thumb_func_start FUN_08204c80
FUN_08204c80: @ 0x08204C80
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	movs r0, #0
	strb r0, [r1]
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _08204CA8 @ =0x00002E78
	bl FUN_0822b16c
	adds r0, r4, #0
	bl FUN_08204bf8
	cmp r0, #0
	blt _08204CAC
	movs r0, #0
	b _08204CB0
	.align 2, 0
_08204CA8: .4byte 0x00002E78
_08204CAC:
	movs r0, #1
	rsbs r0, r0, #0
_08204CB0:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08204cb8
FUN_08204cb8: @ 0x08204CB8
	push {r4, lr}
	ldr r0, _08204CF0 @ =0x03000220
	ldr r0, [r0]
	cmp r0, #0
	bne _08204CFE
	movs r1, #0x90
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08204CFC
	ldr r1, _08204CF4 @ =FUN_08204b84
	ldr r2, _08204CF8 @ =FUN_08204bcc
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08204c80
	cmp r0, #0
	bge _08204CFC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08204CFE
	.align 2, 0
_08204CF0: .4byte 0x03000220
_08204CF4: .4byte FUN_08204b84
_08204CF8: .4byte FUN_08204bcc
_08204CFC:
	adds r0, r4, #0
_08204CFE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08204d04
FUN_08204d04: @ 0x08204D04
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r4, _08204D28 @ =0x03000220
	ldr r0, [r4]
	cmp r0, #0
	bne _08204D18
	bl FUN_08204cb8
	str r0, [r4]
_08204D18:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_08204884
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08204D28: .4byte 0x03000220

	thumb_func_start FUN_08204d2c
FUN_08204d2c: @ 0x08204D2C
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08204D40
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0xe
	strb r0, [r2, #5]
_08204D40:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08204D5C
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_08204D5C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08204d60
FUN_08204d60: @ 0x08204D60
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08204D72
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xf
	strb r0, [r1, #5]
_08204D72:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08204D8E
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08204D8E:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08204d94
FUN_08204d94: @ 0x08204D94
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08204DB4
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0x10
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08204DB4:
	ldrb r0, [r4, #4]
	ldr r2, _08204DD4 @ =0x00000227
	adds r1, r4, r2
	strb r0, [r1]
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08204DCE
	movs r0, #0xa
	strb r0, [r4, #4]
	movs r0, #0
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
_08204DCE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08204DD4: .4byte 0x00000227

	thumb_func_start FUN_08204dd8
FUN_08204dd8: @ 0x08204DD8
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08204DEA
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x11
	strb r0, [r1, #5]
_08204DEA:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08204E06
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08204E06:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08204e0c
FUN_08204e0c: @ 0x08204E0C
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08204E20
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0x12
	strb r0, [r2, #5]
_08204E20:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08204E3C
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_08204E3C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08204e40
FUN_08204e40: @ 0x08204E40
	push {lr}
	ldr r3, _08204E54 @ =0x085AE83C
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08204E54: .4byte 0x085AE83C

	thumb_func_start FUN_08204e58
FUN_08204e58: @ 0x08204E58
	push {lr}
	bl FUN_08204e40
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08204e64
FUN_08204e64: @ 0x08204E64
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08204E86
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08204E86:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08204F8C
	adds r3, r5, #0
	adds r3, #0x64
	adds r2, r5, #0
	adds r2, #0x54
	movs r4, #0
	ldrsh r1, [r2, r4]
	movs r4, #0
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r3, r2]
	subs r2, r1, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	movs r0, #0x80
	lsls r0, r0, #3
	adds r6, r3, #0
	cmp r1, r0
	bgt _08204EDA
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	movs r0, #1
	strb r0, [r5, #7]
	b _08204F8C
_08204EDA:
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_0823785c
	strb r0, [r5, #0x1b]
	add r3, sp, #4
	ldrb r4, [r5, #0x1b]
	ldr r2, _08204F04 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _08204F08
	asrs r1, r0, #0xc
	b _08204F0E
	.align 2, 0
_08204F04: .4byte 0x085B0A08
_08204F08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08204F0E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _08204F2C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x10
	muls r0, r1, r0
	cmp r0, #0
	blt _08204F30
	asrs r0, r0, #0xc
	b _08204F36
	.align 2, 0
_08204F2C: .4byte 0x085B0A08
_08204F30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08204F36:
	strh r0, [r3, #4]
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r4, [r6]
	adds r0, r0, r4
	strh r0, [r6]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r4, [r6, #4]
	adds r0, r0, r4
	strh r0, [r6, #4]
	ldrb r2, [r5, #0x1b]
	adds r0, r5, #0
	adds r0, #0x61
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08204F8C:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08204f94
FUN_08204f94: @ 0x08204F94
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08204FB6
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08204FB6:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08205010
	ldrb r2, [r5, #0x1b]
	adds r6, r5, #0
	adds r6, #0x61
	movs r4, #0
	strb r2, [r6]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	str r4, [sp]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	ldrb r0, [r6]
	ldrb r1, [r5, #0x1b]
	cmp r0, r1
	bne _08205010
	movs r0, #1
	strb r0, [r5, #7]
_08205010:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08205018
FUN_08205018: @ 0x08205018
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x20
	movs r6, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08205076
	strb r6, [r5, #9]
	strb r6, [r5, #7]
	ldrb r2, [r5, #0x1b]
	adds r0, r5, #0
	adds r0, #0x61
	movs r4, #0
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #4
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	movs r6, #1
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	strh r4, [r7, #6]
_08205076:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082050F0
	cmp r6, #0
	beq _08205098
	movs r0, #0x8f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08205098:
	ldrh r0, [r5, #0xe]
	movs r4, #1
	movs r6, #0
	orrs r0, r4
	strh r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082050F0
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	ldr r1, _082050F8 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r5, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0
	str r0, [r5, #0x10]
	strb r4, [r5, #9]
	strb r6, [r5, #0x18]
	ldrh r0, [r5, #0xc]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _082050F0
	movs r0, #0x90
	lsls r0, r0, #1
	bl PlaySound_082406e0
	mvns r0, r4
	ldrh r1, [r5, #0xc]
	ands r0, r1
	strh r0, [r5, #0xc]
_082050F0:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082050F8: .4byte FUN_080421bc

	thumb_func_start FUN_082050fc
FUN_082050fc: @ 0x082050FC
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08205124
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	ldr r0, _08205170 @ =0x0000011F
	bl PlaySound_082406e0
_08205124:
	ldrh r0, [r4, #0xe]
	movs r5, #1
	movs r6, #0
	orrs r0, r5
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08205166
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08205166
	strb r5, [r4, #7]
	ldr r0, _08205174 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #0
	str r0, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
_08205166:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08205170: .4byte 0x0000011F
_08205174: .4byte FUN_08042178

	thumb_func_start FUN_08205178
FUN_08205178: @ 0x08205178
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #0xc]
	adds r5, r1, #0
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r0, r1
	ldr r7, [r0]
	movs r2, #0x5c
	adds r2, r2, r5
	mov r8, r2
	adds r6, r5, #0
	adds r6, #0x64
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _082051B6
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_082051B6:
	ldr r0, _08205298 @ =0x00000402
	ldrh r1, [r5, #0xe]
	movs r2, #0
	mov r3, sp
	strh r2, [r3, #0x14]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _082051DC
	b _08205422
_082051DC:
	cmp r7, #0
	bne _082051E2
	b _08205412
_082051E2:
	adds r0, r7, #0
	adds r0, #0x29
	ldrb r0, [r0]
	str r0, [sp, #0x10]
	adds r4, r7, #0
	adds r4, #0x2c
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	mov r2, r8
	movs r3, #8
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r7, r1]
	mov sb, r0
	mov r2, r8
	movs r1, #8
	ldrsh r0, [r2, r1]
	mov r2, sb
	subs r2, r2, r0
	mov ip, r2
	movs r1, #4
	ldrsh r0, [r4, r1]
	mov sl, r0
	movs r0, #4
	ldrsh r2, [r6, r0]
	mov r1, sl
	subs r0, r1, r2
	mov r2, ip
	mov r1, ip
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0x90
	lsls r0, r0, #0xc
	mov sl, r6
	mov sb, r4
	cmp r1, r0
	ble _082052F4
	adds r0, r5, #0
	adds r0, #0x61
	strb r3, [r0]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	add r4, sp, #4
	mov r0, r8
	ldrb r6, [r0, #5]
	ldr r1, _0820529C @ =0xFFFFFD00
	mov ip, r1
	ldr r1, _082052A0 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _082052A4
	asrs r2, r0, #0xc
	b _082052AA
	.align 2, 0
_08205298: .4byte 0x00000402
_0820529C: .4byte 0xFFFFFD00
_082052A0: .4byte 0x085B0A08
_082052A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_082052AA:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _082052C6
	asrs r0, r0, #0xc
	b _082052CC
_082052C6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_082052CC:
	strh r0, [r4, #4]
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r7, [r7, #0x2c]
	adds r0, r0, r7
	mov r3, r8
	strh r0, [r3, #8]
	ldrh r0, [r1, #2]
	mov r2, sb
	ldrh r2, [r2, #2]
	adds r0, r0, r2
	mov r3, sl
	strh r0, [r3, #2]
	ldrh r0, [r1, #4]
	mov r1, sb
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r3, #4]
	b _08205412
_082052F4:
	ldr r0, _08205348 @ =0x0000FFFF
	cmp r1, r0
	ble _08205378
	adds r0, r5, #0
	adds r0, #0x61
	strb r3, [r0]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	adds r4, r5, #0
	adds r4, #0x6c
	mov r2, r8
	ldrb r6, [r2, #5]
	movs r7, #0x18
	ldr r1, _0820534C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _08205350
	asrs r2, r0, #0xc
	b _08205356
	.align 2, 0
_08205348: .4byte 0x0000FFFF
_0820534C: .4byte 0x085B0A08
_08205350:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08205356:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0820536E
	asrs r0, r0, #0xc
	b _08205374
_0820536E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08205374:
	strh r0, [r4, #4]
	b _08205412
_08205378:
	adds r4, r5, #0
	adds r4, #0x61
	strb r3, [r4]
	lsls r2, r3, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	mov r2, r8
	movs r3, #0xa
	ldrsh r1, [r2, r3]
	ldr r2, [sp, #0xc]
	ldr r3, _08205434 @ =0x00000434
	adds r0, r2, r3
	ldr r2, [r0]
	movs r3, #2
	ldrsh r0, [r2, r3]
	subs r0, r1, r0
	cmp r0, #0
	bge _082053BC
	rsbs r0, r0, #0
_082053BC:
	cmp r0, #0xff
	bgt _08205412
	movs r1, #0
	ldrsh r0, [r6, r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r6, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	ldr r1, [sp, #0x10]
	subs r0, r1, r0
	ldrb r1, [r4]
	adds r1, #0x80
	ldr r2, [sp, #0x10]
	subs r1, r2, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _082053F6
	rsbs r0, r0, #0
_082053F6:
	cmp r0, #0x3f
	bgt _08205412
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08205404
	rsbs r0, r0, #0
_08205404:
	cmp r0, #0x1f
	bgt _08205412
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
_08205412:
	movs r0, #1
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08205422:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08205434: .4byte 0x00000434

	thumb_func_start FUN_08205438
FUN_08205438: @ 0x08205438
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r4, #0
	adds r7, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08205460
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08205460:
	ldrh r1, [r4, #0xe]
	movs r0, #1
	movs r6, #0
	orrs r0, r1
	strh r0, [r4, #0xe]
	cmp r5, #0x1e
	bne _08205488
	add r2, sp, #4
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x68]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldrh r0, [r2, #2]
	ldr r1, _082054E4 @ =0x00000109
	adds r0, r0, r1
	strh r0, [r2, #2]
	adds r0, r2, #0
	bl Entity0821b7fc_Create
	str r0, [r4, #0x20]
_08205488:
	cmp r5, #0x1e
	ble _082054B2
	movs r0, #7
	adds r1, r5, #0
	ands r1, r0
	asrs r2, r5, #3
	subs r0, r0, r2
	cmp r1, r0
	blt _082054A4
	movs r0, #0xc0
	lsls r0, r0, #2
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_082054A4:
	cmp r5, #0x55
	ble _082054B2
	movs r0, #0xc0
	lsls r0, r0, #2
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_082054B2:
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08205558
	cmp r5, #0
	bne _082054F0
	ldr r0, _082054E8 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x8c
	lsls r3, r3, #6
	adds r0, r0, r3
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _082054EC @ =0x04000008
	bl CpuSet
	b _08205538
	.align 2, 0
_082054E4: .4byte 0x00000109
_082054E8: .4byte 0x03003584
_082054EC: .4byte 0x04000008
_082054F0:
	adds r6, r5, #0
	subs r6, #0x50
	cmp r6, #0x1f
	bhi _08205520
	ldr r0, _08205518 @ =0x03003584
	ldr r2, [r0]
	movs r3, #0x8c
	lsls r3, r3, #6
	adds r1, r2, r3
	ldr r0, _0820551C @ =0x000022E0
	adds r2, r2, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #5
	str r3, [sp]
	adds r3, r6, #0
	bl rgb555_08237468
	b _08205538
	.align 2, 0
_08205518: .4byte 0x03003584
_0820551C: .4byte 0x000022E0
_08205520:
	cmp r5, #0x70
	bne _08205538
	ldr r0, _08205560 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _08205564 @ =0x000022E0
	adds r0, r0, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _08205568 @ =0x04000008
	bl CpuSet
_08205538:
	adds r1, r4, #0
	adds r1, #0xdc
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	str r0, [r1, #0xc]
	ldr r0, [r7]
	bl FUN_0821b84c
	cmp r0, #0
	beq _08205558
	ldr r0, [r7]
	bl FUN_0821b840
	movs r0, #1
	strb r0, [r4, #7]
_08205558:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08205560: .4byte 0x03003584
_08205564: .4byte 0x000022E0
_08205568: .4byte 0x04000008

	thumb_func_start FUN_0820556c
FUN_0820556c: @ 0x0820556C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082055A6
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	ldr r0, _082055CC @ =0x03003584
	ldr r0, [r0]
	movs r1, #0x8c
	lsls r1, r1, #6
	adds r0, r0, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _082055D0 @ =0x04000008
	bl CpuSet
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_082055A6:
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _082055D8
	adds r1, r4, #0
	adds r1, #0xdc
	ldr r0, _082055CC @ =0x03003584
	ldr r0, [r0]
	ldr r2, _082055D4 @ =0x000022E0
	adds r0, r0, r2
	b _0820564E
	.align 2, 0
_082055CC: .4byte 0x03003584
_082055D0: .4byte 0x04000008
_082055D4: .4byte 0x000022E0
_082055D8:
	cmp r6, #0
	bne _082055FC
	ldr r0, _082055F4 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x8c
	lsls r3, r3, #6
	adds r0, r0, r3
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _082055F8 @ =0x04000008
	bl CpuSet
	b _08205644
	.align 2, 0
_082055F4: .4byte 0x03003584
_082055F8: .4byte 0x04000008
_082055FC:
	adds r5, r6, #0
	subs r5, #0x50
	cmp r5, #0x1f
	bhi _0820562C
	ldr r0, _08205624 @ =0x03003584
	ldr r2, [r0]
	movs r3, #0x8c
	lsls r3, r3, #6
	adds r1, r2, r3
	ldr r0, _08205628 @ =0x000022E0
	adds r2, r2, r0
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r3, #5
	str r3, [sp]
	adds r3, r5, #0
	bl rgb555_08237468
	b _08205644
	.align 2, 0
_08205624: .4byte 0x03003584
_08205628: .4byte 0x000022E0
_0820562C:
	cmp r6, #0x70
	bne _08205644
	ldr r0, _08205658 @ =0x03003584
	ldr r0, [r0]
	ldr r1, _0820565C @ =0x000022E0
	adds r0, r0, r1
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _08205660 @ =0x04000008
	bl CpuSet
_08205644:
	adds r1, r4, #0
	adds r1, #0xdc
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
_0820564E:
	str r0, [r1, #0xc]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08205658: .4byte 0x03003584
_0820565C: .4byte 0x000022E0
_08205660: .4byte 0x04000008

	thumb_func_start FUN_08205664
FUN_08205664: @ 0x08205664
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x12
	bhi _08205698
	ldr r1, _08205694 @ =0x085AE890
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820569A
	.align 2, 0
_08205694: .4byte 0x085AE890
_08205698:
	movs r0, #0
_0820569A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_082056a0
FUN_082056a0: @ 0x082056A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _082056C4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _082058BA
	.align 2, 0
_082056C4: .4byte 0x03002B4C
_082056C8:
	ldr r0, _082056FC @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x29
	bls _082056F0
	b _082058AC
_082056F0:
	lsls r0, r0, #2
	ldr r1, _08205700 @ =_08205704
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082056FC: .4byte 0x03002B4C
_08205700: .4byte _08205704
_08205704: @ jump table
	.4byte _082057AC @ case 0
	.4byte _082058AC @ case 1
	.4byte _082057FC @ case 2
	.4byte _082057B6 @ case 3
	.4byte _08205812 @ case 4
	.4byte _08205816 @ case 5
	.4byte _0820581A @ case 6
	.4byte _08205866 @ case 7
	.4byte _0820586A @ case 8
	.4byte _08205882 @ case 9
	.4byte _0820586E @ case 10
	.4byte _082058AC @ case 11
	.4byte _082058AC @ case 12
	.4byte _082058AC @ case 13
	.4byte _082058AC @ case 14
	.4byte _082058AC @ case 15
	.4byte _082058AC @ case 16
	.4byte _082058AC @ case 17
	.4byte _082058AC @ case 18
	.4byte _082058AC @ case 19
	.4byte _082058AC @ case 20
	.4byte _082058AC @ case 21
	.4byte _082058AC @ case 22
	.4byte _082058AC @ case 23
	.4byte _082058AC @ case 24
	.4byte _082058AC @ case 25
	.4byte _082058AC @ case 26
	.4byte _082058AC @ case 27
	.4byte _082058AC @ case 28
	.4byte _082058AC @ case 29
	.4byte _082058AC @ case 30
	.4byte _082058AC @ case 31
	.4byte _082058AC @ case 32
	.4byte _082058AC @ case 33
	.4byte _082058AC @ case 34
	.4byte _082058AC @ case 35
	.4byte _082058AC @ case 36
	.4byte _082058AC @ case 37
	.4byte _082058AC @ case 38
	.4byte _082058AC @ case 39
	.4byte _082058AC @ case 40
	.4byte _08205894 @ case 41
_082057AC:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _0820588C
_082057B6:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820588E
_082057FC:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _0820588E
_08205812:
	movs r1, #4
	b _08205884
_08205816:
	movs r1, #5
	b _08205884
_0820581A:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r4, #0
	strb r0, [r6, #0x1b]
	ldrh r0, [r7, #4]
	cmp r0, #1
	bne _08205832
	ldrh r1, [r6, #0xc]
	movs r0, #1
	orrs r0, r1
	strh r0, [r6, #0xc]
_08205832:
	ldrb r2, [r6, #0x1b]
	adds r0, r6, #0
	adds r0, #0x61
	strb r2, [r0]
	adds r1, r2, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r0, #7
	ands r0, r1
	strb r0, [r6, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r6, #0x19]
	movs r0, #0x10
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r4, [r6, #0x14]
	b _0820588E
_08205866:
	movs r1, #0x11
	b _08205884
_0820586A:
	movs r1, #0x13
	b _08205884
_0820586E:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _082058AC
_08205882:
	movs r1, #0x14
_08205884:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_0820588C:
	str r0, [r6, #0x14]
_0820588E:
	movs r0, #1
	strb r0, [r6, #8]
	b _082058AC
_08205894:
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x68
	strh r1, [r0]
_082058AC:
	movs r1, #1
	add r8, r1
	ldr r0, _082058D4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_082058BA:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _082058C6
	b _082056C8
_082058C6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082058D4: .4byte 0x03002B4C

	thumb_func_start FUN_082058d8
FUN_082058d8: @ 0x082058D8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x20
	adds r0, r4, #0
	bl FUN_082056a0
	movs r0, #2
	ldrh r1, [r4, #0xe]
	ands r0, r1
	cmp r0, #0
	beq _0820590C
	ldr r2, _08205950 @ =0x00000434
	adds r0, r6, r2
	ldr r2, [r0]
	cmp r2, #0
	beq _0820590C
	movs r0, #0x80
	lsls r0, r0, #3
	orrs r1, r0
	strh r1, [r4, #0xe]
	ldrh r0, [r2, #2]
	adds r1, r4, #0
	adds r1, #0x66
	strh r0, [r1]
_0820590C:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldrh r0, [r1, #2]
	adds r0, #0xa0
	strh r0, [r1, #2]
	movs r1, #1
	ldrh r0, [r4, #0xe]
	ands r0, r1
	cmp r0, #0
	bne _08205986
	ldrb r1, [r5, #5]
	movs r2, #3
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08205972
	subs r3, #0x30
	adds r0, r4, r3
	ldrh r0, [r0]
	ands r2, r0
	cmp r2, #0
	beq _08205948
	cmp r2, #3
	bne _08205954
_08205948:
	ldrh r0, [r5, #6]
	subs r0, #8
	b _08205958
	.align 2, 0
_08205950: .4byte 0x00000434
_08205954:
	ldrh r0, [r5, #6]
	adds r0, #8
_08205958:
	strh r0, [r5, #6]
	movs r2, #6
	ldrsh r0, [r5, r2]
	cmp r0, #0x40
	ble _08205968
	movs r0, #0x40
	strh r0, [r5, #6]
	b _08205972
_08205968:
	movs r2, #0x40
	rsbs r2, r2, #0
	cmp r0, r2
	bge _08205972
	strh r2, [r5, #6]
_08205972:
	adds r0, r1, #1
	strb r0, [r5, #5]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	ldrh r0, [r5, #6]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
_08205986:
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08205990
FUN_08205990: @ 0x08205990
	push {r4, r5, lr}
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x20
	bl FUN_080412fc
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _082059B0
	ldrb r0, [r5, #6]
	cmp r0, #0x10
	bhi _082059B0
	ldr r0, _082059B8 @ =0x00000402
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
_082059B0:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_082059B8: .4byte 0x00000402

	thumb_func_start FUN_082059bc
FUN_082059bc: @ 0x082059BC
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	ldr r2, _082059D4 @ =0x03002C90
	movs r1, #0
	str r1, [r2]
	pop {r1}
	bx r1
	.align 2, 0
_082059D4: .4byte 0x03002C90

	thumb_func_start FUN_082059d8
FUN_082059d8: @ 0x082059D8
	push {lr}
	bl FUN_08204e58
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_082059e4
FUN_082059e4: @ 0x082059E4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08205A0E
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_08205A0E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08205a18
FUN_08205a18: @ 0x08205A18
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _08205A84 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08205A30
	b _08205C96
_08205A30:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #0xd
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08205A90
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08205A88 @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08205A8C @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _08205A9A
	.align 2, 0
_08205A84: .4byte 0x03002B50
_08205A88: .4byte 0xFFFF0000
_08205A8C: .4byte 0x0000FFFF
_08205A90:
	ldr r1, _08205BB0 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_08205A9A:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	mov r0, r8
	adds r1, r6, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _08205AB4
	b _08205C96
_08205AB4:
	ldr r0, _08205BB4 @ =0x03002C90
	str r4, [r0]
	adds r0, r4, #0
	mov r1, r8
	add r2, sp, #8
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _08205ACA
	b _08205C96
_08205ACA:
	ldr r0, _08205BB8 @ =0x000097D3
	mov sl, r0
	ldr r3, _08205BBC @ =0x0000C6A0
	movs r7, #0
	str r7, [sp]
	adds r0, r4, #0
	movs r1, #1
	mov r2, sl
	bl FUN_08040f48
	cmp r0, #0
	bge _08205AE4
	b _08205C96
_08205AE4:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r6, #0
	strh r7, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r7, [r0, #0x34]
	subs r1, #0x34
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	mov r1, r8
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r2, r5, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	ldr r1, _08205BC0 @ =FUN_08205664
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08205BC4 @ =FUN_082058d8
	movs r2, #0xb4
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08205BC8 @ =FUN_082059d8
	subs r3, #0x10
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08205BCC @ =FUN_082059e4
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08205BD0 @ =FUN_08205990
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08205BD4 @ =FUN_082059bc
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	mov r2, sl
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	adds r0, r4, #0
	adds r0, #0x20
	strh r7, [r4, #0xc]
	strb r6, [r0, #8]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r2, r0, #0
	cmp r2, #1
	beq _08205BF4
	cmp r2, #1
	bgt _08205BD8
	cmp r2, #0
	beq _08205BDE
	b _08205C50
	.align 2, 0
_08205BB0: .4byte 0xFFFF0000
_08205BB4: .4byte 0x03002C90
_08205BB8: .4byte 0x000097D3
_08205BBC: .4byte 0x0000C6A0
_08205BC0: .4byte FUN_08205664
_08205BC4: .4byte FUN_082058d8
_08205BC8: .4byte FUN_082059d8
_08205BCC: .4byte FUN_082059e4
_08205BD0: .4byte FUN_08205990
_08205BD4: .4byte FUN_082059bc
_08205BD8:
	cmp r2, #2
	beq _08205C28
	b _08205C50
_08205BDE:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08205BF0 @ =FUN_080421bc
	movs r0, #2
	b _08205C40
	.align 2, 0
_08205BF0: .4byte FUN_080421bc
_08205BF4:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r7, [r4, #0x14]
	strb r2, [r4, #8]
	ldr r0, _08205C24 @ =FUN_08042178
	strb r2, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r1, r4, r3
	str r0, [r1]
	str r7, [r4, #0x10]
	strb r2, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _08205C50
	.align 2, 0
_08205C24: .4byte FUN_08042178
_08205C28:
	ldr r1, _08205CA8 @ =0x00000217
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r0, #0x12
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08205CAC @ =FUN_08205178
	movs r0, #0x10
_08205C40:
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	str r7, [r4, #0x10]
	strb r1, [r4, #9]
	strb r6, [r4, #0x18]
_08205C50:
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0804135c
	movs r1, #0x10
	movs r2, #0x14
	movs r3, #0xf8
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r1, [r0]
	adds r3, #2
	adds r0, r4, r3
	strh r2, [r0]
	adds r3, #2
	adds r0, r4, r3
	str r1, [r0]
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r1]
	adds r3, #0xc
	adds r1, r4, r3
	adds r0, #0x90
	str r0, [r1]
_08205C96:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08205CA8: .4byte 0x00000217
_08205CAC: .4byte FUN_08205178

	thumb_func_start FUN_08205cb0
FUN_08205cb0: @ 0x08205CB0
	push {r4, r5, lr}
	ldr r4, _08205CE8 @ =0x03002C90
	ldr r0, [r4]
	cmp r0, #0
	bne _08205CBC
	b _08205DDC
_08205CBC:
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08205CF0
	ldr r0, _08205CEC @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	bne _08205CD0
	b _08205DDC
_08205CD0:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	adds r4, r0, #0
	cmp r4, #0
	beq _08205DDC
	b _08205CF2
	.align 2, 0
_08205CE8: .4byte 0x03002C90
_08205CEC: .4byte 0x03002B50
_08205CF0:
	ldr r4, [r4]
_08205CF2:
	movs r0, #0x10
	movs r1, #0
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	movs r3, #1
	strb r3, [r4, #8]
	ldr r2, _08205DE4 @ =FUN_08205018
	movs r0, #0xe
	strb r0, [r4, #6]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r2, [r0]
	str r1, [r4, #0x10]
	strb r3, [r4, #9]
	strb r1, [r4, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08205D3E
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x64
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x66
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r4, #0
	adds r1, #0x68
	strh r0, [r1]
_08205D3E:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _08205D7E
	bl Script_GetValue
	movs r1, #0x61
	adds r1, r1, r4
	mov ip, r1
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
	mov r5, ip
	ldrb r0, [r5]
	strb r0, [r4, #0x1b]
_08205D7E:
	movs r0, #0x77
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #0
	ble _08205DDC
	ldr r0, _08205DE8 @ =0x03002BE0
	ldr r2, [r0]
	adds r3, r4, #0
	adds r3, #0x64
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #0x30
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	movs r1, #0x61
	adds r1, r1, r4
	mov ip, r1
	strb r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
	mov r5, ip
	ldrb r0, [r5]
	strb r0, [r4, #0x1b]
_08205DDC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08205DE4: .4byte FUN_08205018
_08205DE8: .4byte 0x03002BE0

	thumb_func_start FUN_08205dec
FUN_08205dec: @ 0x08205DEC
	push {r4, r5, lr}
	ldr r4, _08205E20 @ =0x03002C90
	ldr r0, [r4]
	cmp r0, #0
	beq _08205E5E
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08205E28
	ldr r0, _08205E24 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08205E5E
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	adds r4, r0, #0
	cmp r4, #0
	beq _08205E5E
	b _08205E2A
	.align 2, 0
_08205E20: .4byte 0x03002C90
_08205E24: .4byte 0x03002B50
_08205E28:
	ldr r4, [r4]
_08205E2A:
	movs r0, #0x11
	movs r1, #0
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	movs r3, #1
	strb r3, [r4, #8]
	ldr r2, _08205E64 @ =FUN_082050fc
	movs r0, #0xf
	strb r0, [r4, #6]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r2, [r0]
	str r1, [r4, #0x10]
	strb r3, [r4, #9]
	strb r1, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
_08205E5E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08205E64: .4byte FUN_082050fc

	thumb_func_start FUN_08205e68
FUN_08205e68: @ 0x08205E68
	push {r4, r5, lr}
	ldr r4, _08205E9C @ =0x03002C90
	ldr r0, [r4]
	cmp r0, #0
	beq _08205ED0
	movs r0, #0x6e
	bl prepare_08231510
	cmp r0, #0
	beq _08205EA4
	ldr r0, _08205EA0 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _08205ED0
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	adds r4, r0, #0
	cmp r4, #0
	beq _08205ED0
	b _08205EA6
	.align 2, 0
_08205E9C: .4byte 0x03002C90
_08205EA0: .4byte 0x03002B50
_08205EA4:
	ldr r4, [r4]
_08205EA6:
	ldr r1, _08205ED8 @ =0x00000217
	adds r0, r4, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r0, #0x12
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	strb r2, [r4, #8]
	ldr r3, _08205EDC @ =FUN_08205178
	movs r0, #0x10
	strb r0, [r4, #6]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r0, r4, r5
	str r3, [r0]
	str r1, [r4, #0x10]
	strb r2, [r4, #9]
	strb r1, [r4, #0x18]
_08205ED0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08205ED8: .4byte 0x00000217
_08205EDC: .4byte FUN_08205178

	thumb_func_start FUN_08205ee0
FUN_08205ee0: @ 0x08205EE0
	push {lr}
	ldr r0, _08205EF8 @ =0x03002C90
	ldr r0, [r0]
	cmp r0, #0
	beq _08205EF2
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1, #8]
_08205EF2:
	pop {r0}
	bx r0
	.align 2, 0
_08205EF8: .4byte 0x03002C90

	thumb_func_start FUN_08205efc
FUN_08205efc: @ 0x08205EFC
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08205F10
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xe
	strb r0, [r4, #5]
_08205F10:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08205F2C
	movs r1, #1
	movs r0, #0
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08205F2C:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08205f38
FUN_08205f38: @ 0x08205F38
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08205F4C
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xf
	strb r0, [r4, #5]
_08205F4C:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08205F68
	movs r1, #1
	movs r0, #0
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08205F68:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08205f74
FUN_08205f74: @ 0x08205F74
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08205F88
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0x10
	strb r0, [r4, #5]
_08205F88:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08205FA4
	movs r1, #1
	movs r0, #0
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08205FA4:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08205fb0
FUN_08205fb0: @ 0x08205FB0
	push {lr}
	ldr r3, _08205FC4 @ =0x085AE8DC
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08205FC4: .4byte 0x085AE8DC

	thumb_func_start FUN_08205fc8
FUN_08205fc8: @ 0x08205FC8
	push {lr}
	bl FUN_08205fb0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08205fd4
FUN_08205fd4: @ 0x08205FD4
	push {lr}
	bl FUN_08205fc8
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08205fe0
FUN_08205fe0: @ 0x08205FE0
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820600C
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bhi _08205FFC
	movs r0, #2
	strb r0, [r4, #0x19]
_08205FFC:
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #6
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_0820600C:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820602c
FUN_0820602c: @ 0x0820602C
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r5, r2, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820605A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bhi _0820604A
	movs r0, #2
	strb r0, [r4, #0x19]
_0820604A:
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_0820605A:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	cmp r5, #8
	ble _0820606C
	movs r0, #1
	strb r0, [r4, #7]
_0820606C:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08206084
FUN_08206084: @ 0x08206084
	push {r4, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082060DE
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
	ldr r0, [r4, #0x64]
	ldr r1, [r4, #0x68]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r2, [sp, #4]
	asrs r1, r2, #0x10
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r1, r1, r0
	lsls r1, r1, #0x10
	ldr r0, _0820610C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	add r0, sp, #4
	movs r1, #0
	bl FUN_081f7b8c
	add r0, sp, #4
	movs r1, #0x80
	bl FUN_081f7b8c
	ldr r0, _08206110 @ =0x000003CF
	bl PlaySound_082406e0
	ldr r0, _08206114 @ =0x000002D2
	bl PlaySound_082406e0
_082060DE:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08206102
	bl FUN_081f7e3c
_08206102:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820610C: .4byte 0x0000FFFF
_08206110: .4byte 0x000003CF
_08206114: .4byte 0x000002D2

	thumb_func_start FUN_08206118
FUN_08206118: @ 0x08206118
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bhi _0820614C
	ldr r1, _08206148 @ =0x085AE928
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820614E
	.align 2, 0
_08206148: .4byte 0x085AE928
_0820614C:
	movs r0, #0
_0820614E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08206154
FUN_08206154: @ 0x08206154
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0820617E
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_0820617E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08206188
FUN_08206188: @ 0x08206188
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _082061AC @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _08206336
	.align 2, 0
_082061AC: .4byte 0x03002B4C
_082061B0:
	ldr r0, _082061E4 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x24
	bls _082061D8
	b _08206328
_082061D8:
	lsls r0, r0, #2
	ldr r1, _082061E8 @ =_082061EC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082061E4: .4byte 0x03002B4C
_082061E8: .4byte _082061EC
_082061EC: @ jump table
	.4byte _08206280 @ case 0
	.4byte _0820628A @ case 1
	.4byte _082062E6 @ case 2
	.4byte _082062A0 @ case 3
	.4byte _08206328 @ case 4
	.4byte _08206328 @ case 5
	.4byte _08206328 @ case 6
	.4byte _08206328 @ case 7
	.4byte _08206328 @ case 8
	.4byte _08206328 @ case 9
	.4byte _082062FC @ case 10
	.4byte _08206328 @ case 11
	.4byte _08206328 @ case 12
	.4byte _08206328 @ case 13
	.4byte _08206328 @ case 14
	.4byte _08206328 @ case 15
	.4byte _08206328 @ case 16
	.4byte _08206328 @ case 17
	.4byte _08206328 @ case 18
	.4byte _08206328 @ case 19
	.4byte _08206328 @ case 20
	.4byte _08206328 @ case 21
	.4byte _08206328 @ case 22
	.4byte _08206328 @ case 23
	.4byte _08206328 @ case 24
	.4byte _08206328 @ case 25
	.4byte _08206328 @ case 26
	.4byte _08206328 @ case 27
	.4byte _08206328 @ case 28
	.4byte _08206328 @ case 29
	.4byte _08206328 @ case 30
	.4byte _08206328 @ case 31
	.4byte _08206328 @ case 32
	.4byte _08206328 @ case 33
	.4byte _08206310 @ case 34
	.4byte _08206314 @ case 35
	.4byte _08206318 @ case 36
_08206280:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _08206322
_0820628A:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08206326
_082062A0:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _08206324
_082062E6:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08206324
_082062FC:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _08206328
_08206310:
	movs r1, #0x10
	b _0820631A
_08206314:
	movs r1, #0x11
	b _0820631A
_08206318:
	movs r1, #0x12
_0820631A:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_08206322:
	str r0, [r6, #0x14]
_08206324:
	movs r0, #1
_08206326:
	strb r0, [r6, #8]
_08206328:
	movs r1, #1
	add r8, r1
	ldr r0, _08206350 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_08206336:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08206342
	b _082061B0
_08206342:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08206350: .4byte 0x03002B4C

	thumb_func_start FUN_08206354
FUN_08206354: @ 0x08206354
	push {r4, lr}
	adds r2, r0, #0
	adds r0, #0x61
	ldrb r0, [r0]
	adds r4, r0, #0
	adds r4, #0x20
	movs r0, #0xff
	ands r4, r0
	movs r0, #0xac
	lsls r0, r0, #2
	adds r3, r2, r0
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [r3]
	str r1, [r3, #4]
	ldrb r0, [r2, #6]
	cmp r0, #2
	beq _0820637C
	cmp r0, #9
	bne _08206394
_0820637C:
	ldrb r0, [r2, #0x1a]
	cmp r0, #4
	bne _08206394
	ldrh r0, [r3]
	subs r0, #0xc
	strh r0, [r3]
	movs r0, #0xad
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #0x10
	b _082063E2
_08206394:
	asrs r0, r4, #6
	cmp r0, #1
	beq _082063AE
	cmp r0, #1
	bgt _082063A4
	cmp r0, #0
	beq _082063D8
	b _082063E4
_082063A4:
	cmp r0, #2
	beq _082063B4
	cmp r0, #3
	beq _082063CC
	b _082063E4
_082063AE:
	movs r0, #0xac
	lsls r0, r0, #2
	b _082063DC
_082063B4:
	movs r0, #0xac
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #0x18
	strh r0, [r1]
	movs r0, #0xad
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #6
	b _082063E2
_082063CC:
	movs r0, #0xac
	lsls r0, r0, #2
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #6
	strh r0, [r1]
_082063D8:
	movs r0, #0xad
	lsls r0, r0, #2
_082063DC:
	adds r1, r2, r0
	ldrh r0, [r1]
	subs r0, #0x20
_082063E2:
	strh r0, [r1]
_082063E4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082063ec
FUN_082063ec: @ 0x082063EC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08206188
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820640c
FUN_0820640c: @ 0x0820640C
	push {r4, lr}
	adds r4, r1, #0
	bl FUN_080412fc
	adds r0, r4, #0
	bl FUN_08206354
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08206424
FUN_08206424: @ 0x08206424
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_08206434
FUN_08206434: @ 0x08206434
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _082064A0 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820644C
	b _082066B2
_0820644C:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #1
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _082064AC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _082064A4 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _082064A8 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _082064B6
	.align 2, 0
_082064A0: .4byte 0x03002B50
_082064A4: .4byte 0xFFFF0000
_082064A8: .4byte 0x0000FFFF
_082064AC:
	ldr r1, _082065CC @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_082064B6:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _082064D4
	b _082066B2
_082064D4:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _082064E4
	b _082066B2
_082064E4:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _082065D0 @ =0x0000D3EA
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _082064FA
	b _082066B2
_082064FA:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xac
	lsls r3, r3, #2
	adds r1, r4, r3
	ldr r2, [r4, #0x64]
	ldr r3, [r4, #0x68]
	str r2, [r1]
	str r3, [r1, #4]
	movs r0, #0x30
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #7
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _082065D4 @ =FUN_08206118
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082065D8 @ =FUN_082063ec
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082065DC @ =FUN_08205fd4
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082065E0 @ =FUN_08206154
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082065E4 @ =FUN_0820640c
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082065E8 @ =FUN_08206424
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _082065D0 @ =0x0000D3EA
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820661C
	cmp r5, #1
	bgt _082065EC
	cmp r5, #0
	beq _082065F2
	b _082066B2
	.align 2, 0
_082065CC: .4byte 0xFFFF0000
_082065D0: .4byte 0x0000D3EA
_082065D4: .4byte FUN_08206118
_082065D8: .4byte FUN_082063ec
_082065DC: .4byte FUN_08205fd4
_082065E0: .4byte FUN_08206154
_082065E4: .4byte FUN_0820640c
_082065E8: .4byte FUN_08206424
_082065EC:
	cmp r5, #2
	beq _08206654
	b _082066B2
_082065F2:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08206618 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _082066B0
	.align 2, 0
_08206618: .4byte FUN_080421bc
_0820661C:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _08206650 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _082066B2
	.align 2, 0
_08206650: .4byte FUN_08042178
_08206654:
	ldr r1, _08206684 @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _08206688 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08206690
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820668C @ =FUN_080421bc
	strb r5, [r4, #6]
	b _082066A4
	.align 2, 0
_08206684: .4byte 0x00000217
_08206688: .4byte 0x000001EF
_0820668C: .4byte FUN_080421bc
_08206690:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _082066C4 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_082066A4:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_082066B0:
	strb r7, [r4, #0x18]
_082066B2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082066C4: .4byte FUN_08042868

	thumb_func_start FUN_082066c8
FUN_082066c8: @ 0x082066C8
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _082066DA
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xe
	strb r0, [r1, #5]
_082066DA:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _082066EC
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_082066EC:
	pop {r0}
	bx r0

	thumb_func_start FUN_082066f0
FUN_082066f0: @ 0x082066F0
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08206702
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xf
	strb r0, [r1, #5]
_08206702:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08206714
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08206714:
	pop {r0}
	bx r0

	thumb_func_start FUN_08206718
FUN_08206718: @ 0x08206718
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08206736
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x11
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08206736:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820673c
FUN_0820673c: @ 0x0820673C
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820674E
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x12
	strb r0, [r1, #5]
_0820674E:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08206760
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08206760:
	pop {r0}
	bx r0

	thumb_func_start FUN_08206764
FUN_08206764: @ 0x08206764
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08206776
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x13
	strb r0, [r1, #5]
_08206776:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08206788
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08206788:
	pop {r0}
	bx r0

	thumb_func_start FUN_0820678c
FUN_0820678c: @ 0x0820678C
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _082067A0
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0x14
	strb r0, [r2, #5]
_082067A0:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _082067BC
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_082067BC:
	pop {r0}
	bx r0

	thumb_func_start FUN_082067c0
FUN_082067c0: @ 0x082067C0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldrb r0, [r3, #8]
	cmp r0, #0
	beq _082067EC
	movs r1, #0
	strb r1, [r3, #8]
	strb r1, [r3, #7]
	adds r2, r3, #0
	adds r2, #0x20
	ldrb r0, [r2, #4]
	cmp r0, #1
	bne _082067E4
	movs r0, #0x11
	strb r0, [r3, #5]
	strb r1, [r2, #4]
	b _082067E8
_082067E4:
	movs r0, #0xf
	strb r0, [r3, #5]
_082067E8:
	movs r0, #0
	str r0, [r3, #0x14]
_082067EC:
	ldr r1, _0820685C @ =0x00000434
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08206848
	adds r4, r3, #0
	adds r4, #0x64
	movs r6, #0x87
	lsls r6, r6, #2
	adds r0, r3, r6
	ldr r5, [r0]
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r6, #0
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08206812
	rsbs r1, r1, #0
_08206812:
	cmp r1, r5
	bge _08206840
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r6, #2
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _08206826
	rsbs r1, r1, #0
_08206826:
	cmp r1, #0xff
	bgt _08206840
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _0820683A
	rsbs r0, r0, #0
_0820683A:
	movs r1, #1
	cmp r0, r5
	blt _08206842
_08206840:
	movs r1, #0
_08206842:
	movs r0, #1
	cmp r1, #0
	bne _0820684A
_08206848:
	movs r0, #0
_0820684A:
	cmp r0, #0
	beq _08206880
	ldrb r0, [r3, #6]
	cmp r0, #0x10
	beq _08206860
	movs r0, #0x10
	strb r0, [r3, #5]
	b _08206890
	.align 2, 0
_0820685C: .4byte 0x00000434
_08206860:
	ldrb r4, [r3, #7]
	cmp r4, #1
	bne _08206890
	ldrb r1, [r3, #4]
	ldr r6, _0820687C @ =0x00000227
	adds r0, r3, r6
	movs r2, #0
	strb r1, [r0]
	movs r0, #0xa
	strb r0, [r3, #4]
	str r2, [r3, #0x14]
	strb r4, [r3, #8]
	b _08206890
	.align 2, 0
_0820687C: .4byte 0x00000227
_08206880:
	ldrb r0, [r3, #6]
	cmp r0, #0x10
	bne _0820688A
	movs r0, #0xf
	strb r0, [r3, #5]
_0820688A:
	ldr r0, [r3, #0x14]
	adds r0, #1
	str r0, [r3, #0x14]
_08206890:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08206898
FUN_08206898: @ 0x08206898
	push {lr}
	ldr r3, _082068AC @ =0x085AE96C
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_082068AC: .4byte 0x085AE96C

	thumb_func_start FUN_082068b0
FUN_082068b0: @ 0x082068B0
	push {lr}
	bl FUN_08206898
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082068bc
FUN_082068bc: @ 0x082068BC
	push {lr}
	bl FUN_082068b0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_082068c8
FUN_082068c8: @ 0x082068C8
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082068EA
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_082068EA:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08206910
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08206910
	movs r0, #1
	strb r0, [r4, #7]
_08206910:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08206918
FUN_08206918: @ 0x08206918
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820693A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_0820693A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08206960
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08206960
	movs r0, #1
	strb r0, [r4, #7]
_08206960:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08206968
FUN_08206968: @ 0x08206968
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820698A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #6
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_0820698A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082069B0
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082069B0
	movs r0, #1
	strb r0, [r4, #7]
_082069B0:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_082069b8
FUN_082069b8: @ 0x082069B8
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082069DA
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_082069DA:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08206A00
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08206A00
	movs r0, #1
	strb r0, [r4, #7]
_08206A00:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08206a08
FUN_08206a08: @ 0x08206A08
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08206A32
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_08206A32:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08206A74
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08206A74
	ldrh r0, [r5, #0x20]
	cmp r0, #0
	bne _08206A70
	adds r0, #1
	strh r0, [r5, #0x20]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #9
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	b _08206A74
_08206A70:
	movs r0, #1
	strb r0, [r5, #7]
_08206A74:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08206a7c
FUN_08206a7c: @ 0x08206A7C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08206AA6
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_08206AA6:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08206ACC
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08206ACC
	movs r0, #1
	strb r0, [r5, #7]
_08206ACC:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08206ad4
FUN_08206ad4: @ 0x08206AD4
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08206AF6
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #6
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_08206AF6:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08206b0c
FUN_08206b0c: @ 0x08206B0C
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bhi _08206B40
	ldr r1, _08206B3C @ =0x085AE9C8
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _08206B42
	.align 2, 0
_08206B3C: .4byte 0x085AE9C8
_08206B40:
	movs r0, #0
_08206B42:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08206b48
FUN_08206b48: @ 0x08206B48
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08206B72
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_08206B72:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08206b7c
FUN_08206b7c: @ 0x08206B7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _08206BA0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _08206D6E
	.align 2, 0
_08206BA0: .4byte 0x03002B4C
_08206BA4:
	ldr r0, _08206BD8 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x29
	bls _08206BCC
	b _08206D60
_08206BCC:
	lsls r0, r0, #2
	ldr r1, _08206BDC @ =_08206BE0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08206BD8: .4byte 0x03002B4C
_08206BDC: .4byte _08206BE0
_08206BE0: @ jump table
	.4byte _08206C88 @ case 0
	.4byte _08206C92 @ case 1
	.4byte _08206CF0 @ case 2
	.4byte _08206CAA @ case 3
	.4byte _08206D06 @ case 4
	.4byte _08206D0A @ case 5
	.4byte _08206D60 @ case 6
	.4byte _08206D60 @ case 7
	.4byte _08206D60 @ case 8
	.4byte _08206D60 @ case 9
	.4byte _08206D0E @ case 10
	.4byte _08206D22 @ case 11
	.4byte _08206D60 @ case 12
	.4byte _08206D26 @ case 13
	.4byte _08206D2A @ case 14
	.4byte _08206D2E @ case 15
	.4byte _08206D60 @ case 16
	.4byte _08206D60 @ case 17
	.4byte _08206D32 @ case 18
	.4byte _08206D36 @ case 19
	.4byte _08206D60 @ case 20
	.4byte _08206D60 @ case 21
	.4byte _08206D60 @ case 22
	.4byte _08206D60 @ case 23
	.4byte _08206D60 @ case 24
	.4byte _08206D60 @ case 25
	.4byte _08206D60 @ case 26
	.4byte _08206D60 @ case 27
	.4byte _08206D60 @ case 28
	.4byte _08206D60 @ case 29
	.4byte _08206D60 @ case 30
	.4byte _08206D60 @ case 31
	.4byte _08206D60 @ case 32
	.4byte _08206D60 @ case 33
	.4byte _08206D60 @ case 34
	.4byte _08206D60 @ case 35
	.4byte _08206D60 @ case 36
	.4byte _08206D60 @ case 37
	.4byte _08206D60 @ case 38
	.4byte _08206D60 @ case 39
	.4byte _08206D60 @ case 40
	.4byte _08206D48 @ case 41
_08206C88:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _08206D40
_08206C92:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	strb r0, [r6, #8]
	b _08206D60
_08206CAA:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _08206D42
_08206CF0:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08206D42
_08206D06:
	movs r1, #4
	b _08206D38
_08206D0A:
	movs r1, #5
	b _08206D38
_08206D0E:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _08206D60
_08206D22:
	movs r1, #0x10
	b _08206D38
_08206D26:
	movs r1, #0x11
	b _08206D38
_08206D2A:
	movs r1, #0x12
	b _08206D38
_08206D2E:
	movs r1, #0x13
	b _08206D38
_08206D32:
	movs r1, #0x14
	b _08206D38
_08206D36:
	movs r1, #0x15
_08206D38:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_08206D40:
	str r0, [r6, #0x14]
_08206D42:
	movs r0, #1
	strb r0, [r6, #8]
	b _08206D60
_08206D48:
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x68
	strh r1, [r0]
_08206D60:
	movs r1, #1
	add r8, r1
	ldr r0, _08206D88 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_08206D6E:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08206D7A
	b _08206BA4
_08206D7A:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08206D88: .4byte 0x03002B4C

	thumb_func_start FUN_08206d8c
FUN_08206d8c: @ 0x08206D8C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08206b7c
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08206dac
FUN_08206dac: @ 0x08206DAC
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08206db8
FUN_08206db8: @ 0x08206DB8
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_08206dc8
FUN_08206dc8: @ 0x08206DC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08206E34 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08206DE0
	b _082070A8
_08206DE0:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #2
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08206E40
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08206E38 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08206E3C @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _08206E4A
	.align 2, 0
_08206E34: .4byte 0x03002B50
_08206E38: .4byte 0xFFFF0000
_08206E3C: .4byte 0x0000FFFF
_08206E40:
	ldr r1, _08206F58 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_08206E4A:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	ldr r0, _08206F5C @ =0x0000DFDE
	mov sl, r0
	movs r7, #0
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08040ed8
	adds r5, r0, #0
	cmp r5, #0
	bne _08206E6A
	b _082070A8
_08206E6A:
	mov r1, r8
	add r2, sp, #4
	adds r3, r6, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _08206E7A
	b _082070A8
_08206E7A:
	str r7, [sp]
	adds r0, r5, #0
	movs r1, #2
	mov r2, sl
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _08206E8E
	b _082070A8
_08206E8E:
	adds r0, r5, #0
	adds r0, #0x5c
	movs r1, #0xaf
	lsls r1, r1, #1
	movs r4, #0
	strh r7, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r7, [r0, #0x34]
	subs r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r5, r2
	mov r1, r8
	movs r2, #5
	bl FUN_080223f4
	adds r0, r5, #0
	adds r0, #0x61
	strb r6, [r0]
	lsls r2, r6, #0x10
	lsrs r2, r2, #0x10
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	ldr r1, _08206F60 @ =FUN_08206b0c
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F64 @ =FUN_08206d8c
	subs r2, #0x14
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F68 @ =FUN_082068bc
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F6C @ =FUN_08206b48
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F70 @ =FUN_08206dac
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	ldr r1, _08206F74 @ =FUN_08206db8
	adds r2, #4
	adds r0, r5, r2
	str r1, [r0]
	mov r0, sb
	adds r1, r5, #0
	mov r2, sl
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r5, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r5, #0
	bl FUN_08041e10
	adds r6, r5, #0
	adds r6, #0x20
	strb r4, [r6, #4]
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	cmp r0, #4
	bls _08206F4C
	b _082070A8
_08206F4C:
	lsls r0, r0, #2
	ldr r1, _08206F78 @ =_08206F7C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08206F58: .4byte 0xFFFF0000
_08206F5C: .4byte 0x0000DFDE
_08206F60: .4byte FUN_08206b0c
_08206F64: .4byte FUN_08206d8c
_08206F68: .4byte FUN_082068bc
_08206F6C: .4byte FUN_08206b48
_08206F70: .4byte FUN_08206dac
_08206F74: .4byte FUN_08206db8
_08206F78: .4byte _08206F7C
_08206F7C: @ jump table
	.4byte _08206F90 @ case 0
	.4byte _08206FB8 @ case 1
	.4byte _08206FEC @ case 2
	.4byte _08207050 @ case 3
	.4byte _08207084 @ case 4
_08206F90:
	movs r2, #1
	movs r1, #0
	strb r1, [r5, #2]
	strb r1, [r5, #3]
	strb r2, [r5, #4]
	str r1, [r5, #0x14]
	strb r2, [r5, #8]
	ldr r3, _08206FB4 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r5, #6]
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r3, [r0]
	str r1, [r5, #0x10]
	strb r2, [r5, #9]
	b _082070A6
	.align 2, 0
_08206FB4: .4byte FUN_080421bc
_08206FB8:
	movs r2, #0
	strb r2, [r5, #2]
	strb r2, [r5, #3]
	strb r2, [r5, #4]
	str r2, [r5, #0x14]
	movs r1, #1
	strb r1, [r5, #8]
	ldr r3, _08206FE8 @ =FUN_08042178
	strb r1, [r5, #6]
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r3, [r0]
	str r2, [r5, #0x10]
	strb r1, [r5, #9]
	strb r2, [r5, #0x18]
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055ef8
	adds r0, r5, #0
	bl FUN_0804106c
	b _082070A8
	.align 2, 0
_08206FE8: .4byte FUN_08042178
_08206FEC:
	ldr r1, _0820701C @ =0x00000217
	adds r0, r5, r1
	movs r4, #0
	movs r6, #1
	strb r6, [r0]
	ldr r2, _08207020 @ =0x000001EF
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08207028
	adds r0, r5, #0
	bl FUN_08043510
	strb r4, [r5, #2]
	strb r4, [r5, #3]
	strb r0, [r5, #4]
	str r4, [r5, #0x14]
	strb r6, [r5, #8]
	ldr r1, _08207024 @ =FUN_080421bc
	movs r0, #2
	b _08207038
	.align 2, 0
_0820701C: .4byte 0x00000217
_08207020: .4byte 0x000001EF
_08207024: .4byte FUN_080421bc
_08207028:
	movs r0, #6
	strb r4, [r5, #2]
	strb r4, [r5, #3]
	strb r0, [r5, #4]
	str r4, [r5, #0x14]
	strb r6, [r5, #8]
	ldr r1, _0820704C @ =FUN_08042868
	movs r0, #7
_08207038:
	strb r0, [r5, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	str r4, [r5, #0x10]
	strb r6, [r5, #9]
	strb r4, [r5, #0x18]
	b _082070A8
	.align 2, 0
_0820704C: .4byte FUN_08042868
_08207050:
	ldr r4, _0820707C @ =0x00000217
	adds r0, r5, r4
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	strb r2, [r6, #4]
	movs r0, #0x16
	strb r1, [r5, #2]
	strb r1, [r5, #3]
	strb r0, [r5, #4]
	str r1, [r5, #0x14]
	strb r2, [r5, #8]
	ldr r3, _08207080 @ =FUN_08042868
	movs r0, #7
	strb r0, [r5, #6]
	adds r4, #0xb5
	adds r0, r5, r4
	str r3, [r0]
	str r1, [r5, #0x10]
	strb r2, [r5, #9]
	b _082070A6
	.align 2, 0
_0820707C: .4byte 0x00000217
_08207080: .4byte FUN_08042868
_08207084:
	movs r0, #0x12
	movs r1, #0
	strb r1, [r5, #2]
	strb r1, [r5, #3]
	strb r0, [r5, #4]
	str r1, [r5, #0x14]
	movs r3, #1
	strb r3, [r5, #8]
	ldr r2, _082070B8 @ =FUN_08206ad4
	movs r0, #0x11
	strb r0, [r5, #6]
	movs r4, #0xb3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r2, [r0]
	str r1, [r5, #0x10]
	strb r3, [r5, #9]
_082070A6:
	strb r1, [r5, #0x18]
_082070A8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082070B8: .4byte FUN_08206ad4

	thumb_func_start FUN_082070bc
FUN_082070bc: @ 0x082070BC
	push {r4, r5, r6, lr}
	ldr r0, _08207114 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _0820710C
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	adds r5, r0, #0
	cmp r5, #0
	beq _0820710C
	adds r4, r5, #0
	adds r4, #0x20
	ldr r1, _08207118 @ =0x00000217
	adds r0, r5, r1
	movs r1, #0
	movs r2, #1
	strb r2, [r0]
	movs r0, #0x16
	strb r1, [r5, #2]
	strb r1, [r5, #3]
	strb r0, [r5, #4]
	str r1, [r5, #0x14]
	strb r2, [r5, #8]
	ldr r3, _0820711C @ =FUN_08042868
	movs r0, #7
	strb r0, [r5, #6]
	movs r6, #0xb3
	lsls r6, r6, #2
	adds r0, r5, r6
	str r3, [r0]
	str r1, [r5, #0x10]
	strb r2, [r5, #9]
	strb r1, [r5, #0x18]
	strb r2, [r4, #4]
_0820710C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08207114: .4byte 0x03002B50
_08207118: .4byte 0x00000217
_0820711C: .4byte FUN_08042868

	thumb_func_start FUN_08207120
FUN_08207120: @ 0x08207120
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08207142
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_08207142:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08207168
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08207168
	movs r0, #1
	strb r0, [r4, #7]
_08207168:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08207170
FUN_08207170: @ 0x08207170
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08207192
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #6
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_08207192:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082071B8
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082071B8
	movs r0, #1
	strb r0, [r4, #7]
_082071B8:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_082071c0
FUN_082071c0: @ 0x082071C0
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082071E2
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_082071E2:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08207208
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08207208
	movs r0, #1
	strb r0, [r4, #7]
_08207208:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08207210
FUN_08207210: @ 0x08207210
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820723A
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #6
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_0820723A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820728E
	ldrh r4, [r5, #0x20]
	cmp r4, #0
	beq _0820725C
	cmp r4, #1
	beq _08207282
	b _0820728E
_0820725C:
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _0820728E
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #7
	movs r2, #1
	movs r3, #1
	bl FUN_08041480
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	strh r4, [r6, #2]
	b _0820728E
_08207282:
	movs r1, #0
	strb r4, [r5, #7]
	ldrh r0, [r5, #0x20]
	adds r0, #1
	strh r0, [r5, #0x20]
	strh r1, [r6, #2]
_0820728E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08207298
FUN_08207298: @ 0x08207298
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _082072C2
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #8
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_082072C2:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082072E8
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082072E8
	movs r0, #1
	strb r0, [r5, #7]
_082072E8:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_082072f0
FUN_082072f0: @ 0x082072F0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820731A
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #9
	movs r2, #1
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_0820731A:
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r5, #0xe]
	movs r7, #0
	orrs r0, r1
	movs r1, #0x80
	lsls r1, r1, #5
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08207382
	ldrh r0, [r6, #2]
	adds r0, #1
	strh r0, [r6, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x45
	bls _08207372
	strh r7, [r6, #2]
	movs r0, #0xb0
	lsls r0, r0, #2
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x5c
	str r7, [sp]
	str r7, [sp, #4]
	movs r2, #0xfa
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #2
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
_08207372:
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08207382
	movs r0, #1
	strb r0, [r5, #7]
_08207382:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820738c
FUN_0820738c: @ 0x0820738C
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082073AE
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_082073AE:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082073D4
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082073D4
	movs r0, #1
	strb r0, [r4, #7]
_082073D4:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_082073dc
FUN_082073dc: @ 0x082073DC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x14
	bhi _08207410
	ldr r1, _0820740C @ =0x085AEA1C
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _08207412
	.align 2, 0
_0820740C: .4byte 0x085AEA1C
_08207410:
	movs r0, #0
_08207412:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08207418
FUN_08207418: @ 0x08207418
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08207442
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_08207442:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820744c
FUN_0820744c: @ 0x0820744C
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820745E
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xe
	strb r0, [r1, #5]
_0820745E:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08207470
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08207470:
	pop {r0}
	bx r0

	thumb_func_start FUN_08207474
FUN_08207474: @ 0x08207474
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08207488
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0xf
	strb r0, [r2, #5]
_08207488:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _082074A4
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_082074A4:
	pop {r0}
	bx r0

	thumb_func_start FUN_082074a8
FUN_082074a8: @ 0x082074A8
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _082074BA
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x10
	strb r0, [r1, #5]
_082074BA:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _082074CC
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_082074CC:
	pop {r0}
	bx r0

	thumb_func_start FUN_082074d0
FUN_082074d0: @ 0x082074D0
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _082074E2
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x11
	strb r0, [r1, #5]
_082074E2:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _082074F4
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_082074F4:
	pop {r0}
	bx r0

	thumb_func_start FUN_082074f8
FUN_082074f8: @ 0x082074F8
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _0820750C
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0x12
	strb r0, [r2, #5]
_0820750C:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08207528
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_08207528:
	pop {r0}
	bx r0

	thumb_func_start FUN_0820752c
FUN_0820752c: @ 0x0820752C
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820754A
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x13
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_0820754A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08207550
FUN_08207550: @ 0x08207550
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08207562
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x14
	strb r0, [r1, #5]
_08207562:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08207574
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08207574:
	pop {r0}
	bx r0

	thumb_func_start FUN_08207578
FUN_08207578: @ 0x08207578
	push {lr}
	ldr r3, _0820758C @ =0x085AEA70
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_0820758C: .4byte 0x085AEA70

	thumb_func_start FUN_08207590
FUN_08207590: @ 0x08207590
	push {lr}
	bl FUN_08207578
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820759c
FUN_0820759c: @ 0x0820759C
	push {lr}
	bl FUN_08207590
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_082075a8
FUN_082075a8: @ 0x082075A8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _082075CC @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _0820779E
	.align 2, 0
_082075CC: .4byte 0x03002B4C
_082075D0:
	ldr r0, _08207604 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x29
	bls _082075F8
	b _08207790
_082075F8:
	lsls r0, r0, #2
	ldr r1, _08207608 @ =_0820760C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08207604: .4byte 0x03002B4C
_08207608: .4byte _0820760C
_0820760C: @ jump table
	.4byte _082076B4 @ case 0
	.4byte _082076BE @ case 1
	.4byte _0820771C @ case 2
	.4byte _082076D6 @ case 3
	.4byte _08207732 @ case 4
	.4byte _08207736 @ case 5
	.4byte _08207790 @ case 6
	.4byte _08207790 @ case 7
	.4byte _08207790 @ case 8
	.4byte _08207790 @ case 9
	.4byte _0820773A @ case 10
	.4byte _0820774E @ case 11
	.4byte _08207752 @ case 12
	.4byte _08207790 @ case 13
	.4byte _08207790 @ case 14
	.4byte _08207756 @ case 15
	.4byte _0820775A @ case 16
	.4byte _0820775E @ case 17
	.4byte _08207790 @ case 18
	.4byte _08207790 @ case 19
	.4byte _08207790 @ case 20
	.4byte _08207790 @ case 21
	.4byte _08207790 @ case 22
	.4byte _08207762 @ case 23
	.4byte _08207766 @ case 24
	.4byte _08207790 @ case 25
	.4byte _08207790 @ case 26
	.4byte _08207790 @ case 27
	.4byte _08207790 @ case 28
	.4byte _08207790 @ case 29
	.4byte _08207790 @ case 30
	.4byte _08207790 @ case 31
	.4byte _08207790 @ case 32
	.4byte _08207790 @ case 33
	.4byte _08207790 @ case 34
	.4byte _08207790 @ case 35
	.4byte _08207790 @ case 36
	.4byte _08207790 @ case 37
	.4byte _08207790 @ case 38
	.4byte _08207790 @ case 39
	.4byte _08207790 @ case 40
	.4byte _08207778 @ case 41
_082076B4:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _08207770
_082076BE:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	strb r0, [r6, #8]
	b _08207790
_082076D6:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _08207772
_0820771C:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08207772
_08207732:
	movs r1, #4
	b _08207768
_08207736:
	movs r1, #5
	b _08207768
_0820773A:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _08207790
_0820774E:
	movs r1, #0x10
	b _08207768
_08207752:
	movs r1, #0x11
	b _08207768
_08207756:
	movs r1, #0x12
	b _08207768
_0820775A:
	movs r1, #0x13
	b _08207768
_0820775E:
	movs r1, #0x14
	b _08207768
_08207762:
	movs r1, #0x15
	b _08207768
_08207766:
	movs r1, #0x16
_08207768:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_08207770:
	str r0, [r6, #0x14]
_08207772:
	movs r0, #1
	strb r0, [r6, #8]
	b _08207790
_08207778:
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x68
	strh r1, [r0]
_08207790:
	movs r1, #1
	add r8, r1
	ldr r0, _082077B8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_0820779E:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _082077AA
	b _082075D0
_082077AA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082077B8: .4byte 0x03002B4C

	thumb_func_start FUN_082077bc
FUN_082077bc: @ 0x082077BC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_082075a8
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082077dc
FUN_082077dc: @ 0x082077DC
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_082077e8
FUN_082077e8: @ 0x082077E8
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_082077f8
FUN_082077f8: @ 0x082077F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08207864 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08207810
	b _08207AAE
_08207810:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x6b
	movs r1, #3
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08207870
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08207868 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820786C @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820787A
	.align 2, 0
_08207864: .4byte 0x03002B50
_08207868: .4byte 0xFFFF0000
_0820786C: .4byte 0x0000FFFF
_08207870:
	ldr r1, _0820798C @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820787A:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _08207898
	b _08207AAE
_08207898:
	adds r1, r7, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _082078A8
	b _08207AAE
_082078A8:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _08207990 @ =0x0000DFEE
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _082078BE
	b _08207AAE
_082078BE:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xaf
	lsls r1, r1, #1
	movs r6, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r7, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _08207994 @ =FUN_082073dc
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08207998 @ =FUN_082077bc
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820799C @ =FUN_0820759c
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082079A0 @ =FUN_08207418
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082079A4 @ =FUN_082077dc
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082079A8 @ =FUN_082077e8
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _08207990 @ =0x0000DFEE
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _082079E0
	cmp r5, #1
	bgt _082079AC
	cmp r5, #0
	beq _082079B6
	b _08207AAE
	.align 2, 0
_0820798C: .4byte 0xFFFF0000
_08207990: .4byte 0x0000DFEE
_08207994: .4byte FUN_082073dc
_08207998: .4byte FUN_082077bc
_0820799C: .4byte FUN_0820759c
_082079A0: .4byte FUN_08207418
_082079A4: .4byte FUN_082077dc
_082079A8: .4byte FUN_082077e8
_082079AC:
	cmp r5, #2
	beq _08207A18
	cmp r5, #3
	beq _08207A88
	b _08207AAE
_082079B6:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _082079DC @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _08207AAC
	.align 2, 0
_082079DC: .4byte FUN_080421bc
_082079E0:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _08207A14 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _08207AAE
	.align 2, 0
_08207A14: .4byte FUN_08042178
_08207A18:
	ldr r1, _08207A54 @ =0x00000217
	adds r0, r4, r1
	movs r7, #1
	strb r7, [r0]
	ldr r2, _08207A58 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08207A60
	adds r0, r4, #0
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r7, [r4, #8]
	ldr r1, _08207A5C @ =FUN_080421bc
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r7, [r4, #9]
	b _08207AAC
	.align 2, 0
_08207A54: .4byte 0x00000217
_08207A58: .4byte 0x000001EF
_08207A5C: .4byte FUN_080421bc
_08207A60:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r7, [r4, #8]
	ldr r1, _08207A84 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r7, [r4, #9]
	b _08207AAC
	.align 2, 0
_08207A84: .4byte FUN_08042868
_08207A88:
	movs r0, #0x15
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _08207AC0 @ =FUN_082072f0
	movs r0, #0x13
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r2, [r4, #9]
_08207AAC:
	strb r6, [r4, #0x18]
_08207AAE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08207AC0: .4byte FUN_082072f0

	thumb_func_start FUN_08207ac4
FUN_08207ac4: @ 0x08207AC4
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08207AE4
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xe
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08207AE4:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08207af0
FUN_08207af0: @ 0x08207AF0
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08207B10
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xf
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08207B10:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08207b1c
FUN_08207b1c: @ 0x08207B1C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08207B3C
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0x10
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08207B3C:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08207b48
FUN_08207b48: @ 0x08207B48
	push {lr}
	ldr r3, _08207B5C @ =0x085AEACC
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08207B5C: .4byte 0x085AEACC

	thumb_func_start FUN_08207b60
FUN_08207b60: @ 0x08207B60
	push {lr}
	bl FUN_08207b48
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08207b6c
FUN_08207b6c: @ 0x08207B6C
	push {lr}
	bl FUN_08207b60
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08207b78
FUN_08207b78: @ 0x08207B78
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08207B9A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
_08207B9A:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08207bbc
FUN_08207bbc: @ 0x08207BBC
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08207BDE
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #6
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
_08207BDE:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08207c00
FUN_08207c00: @ 0x08207C00
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08207C22
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_08207C22:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08207c44
FUN_08207c44: @ 0x08207C44
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bhi _08207C78
	ldr r1, _08207C74 @ =0x085AEB18
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _08207C7A
	.align 2, 0
_08207C74: .4byte 0x085AEB18
_08207C78:
	movs r0, #0
_08207C7A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08207c80
FUN_08207c80: @ 0x08207C80
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08207CAA
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_08207CAA:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08207cb4
FUN_08207cb4: @ 0x08207CB4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _08207CD8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _08207E76
	.align 2, 0
_08207CD8: .4byte 0x03002B4C
_08207CDC:
	ldr r0, _08207D10 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x27
	bls _08207D04
	b _08207E68
_08207D04:
	lsls r0, r0, #2
	ldr r1, _08207D14 @ =_08207D18
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08207D10: .4byte 0x03002B4C
_08207D14: .4byte _08207D18
_08207D18: @ jump table
	.4byte _08207DB8 @ case 0
	.4byte _08207DC2 @ case 1
	.4byte _08207E1E @ case 2
	.4byte _08207DD8 @ case 3
	.4byte _08207E34 @ case 4
	.4byte _08207E38 @ case 5
	.4byte _08207E68 @ case 6
	.4byte _08207E68 @ case 7
	.4byte _08207E68 @ case 8
	.4byte _08207E68 @ case 9
	.4byte _08207E3C @ case 10
	.4byte _08207E68 @ case 11
	.4byte _08207E68 @ case 12
	.4byte _08207E68 @ case 13
	.4byte _08207E68 @ case 14
	.4byte _08207E68 @ case 15
	.4byte _08207E68 @ case 16
	.4byte _08207E68 @ case 17
	.4byte _08207E68 @ case 18
	.4byte _08207E68 @ case 19
	.4byte _08207E68 @ case 20
	.4byte _08207E68 @ case 21
	.4byte _08207E68 @ case 22
	.4byte _08207E68 @ case 23
	.4byte _08207E68 @ case 24
	.4byte _08207E68 @ case 25
	.4byte _08207E68 @ case 26
	.4byte _08207E68 @ case 27
	.4byte _08207E68 @ case 28
	.4byte _08207E68 @ case 29
	.4byte _08207E68 @ case 30
	.4byte _08207E68 @ case 31
	.4byte _08207E68 @ case 32
	.4byte _08207E68 @ case 33
	.4byte _08207E68 @ case 34
	.4byte _08207E68 @ case 35
	.4byte _08207E68 @ case 36
	.4byte _08207E50 @ case 37
	.4byte _08207E54 @ case 38
	.4byte _08207E58 @ case 39
_08207DB8:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _08207E62
_08207DC2:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08207E66
_08207DD8:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _08207E64
_08207E1E:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08207E64
_08207E34:
	movs r1, #4
	b _08207E5A
_08207E38:
	movs r1, #5
	b _08207E5A
_08207E3C:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _08207E68
_08207E50:
	movs r1, #0x10
	b _08207E5A
_08207E54:
	movs r1, #0x11
	b _08207E5A
_08207E58:
	movs r1, #0x12
_08207E5A:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_08207E62:
	str r0, [r6, #0x14]
_08207E64:
	movs r0, #1
_08207E66:
	strb r0, [r6, #8]
_08207E68:
	movs r1, #1
	add r8, r1
	ldr r0, _08207E90 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_08207E76:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08207E82
	b _08207CDC
_08207E82:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08207E90: .4byte 0x03002B4C

	thumb_func_start FUN_08207e94
FUN_08207e94: @ 0x08207E94
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08207cb4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08207eb4
FUN_08207eb4: @ 0x08207EB4
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08207ec0
FUN_08207ec0: @ 0x08207EC0
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_08207ed0
FUN_08207ed0: @ 0x08207ED0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08207F3C @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08207EE8
	b _0820814A
_08207EE8:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #4
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08207F48
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08207F40 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08207F44 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _08207F52
	.align 2, 0
_08207F3C: .4byte 0x03002B50
_08207F40: .4byte 0xFFFF0000
_08207F44: .4byte 0x0000FFFF
_08207F48:
	ldr r1, _08208064 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_08207F52:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _08207F70
	b _0820814A
_08207F70:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _08207F80
	b _0820814A
_08207F80:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _08208068 @ =0x0000DFFE
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _08207F96
	b _0820814A
_08207F96:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0x96
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820806C @ =FUN_08207c44
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08208070 @ =FUN_08207e94
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08208074 @ =FUN_08207b6c
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08208078 @ =FUN_08207c80
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820807C @ =FUN_08207eb4
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08208080 @ =FUN_08207ec0
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _08208068 @ =0x0000DFFE
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _082080B4
	cmp r5, #1
	bgt _08208084
	cmp r5, #0
	beq _0820808A
	b _0820814A
	.align 2, 0
_08208064: .4byte 0xFFFF0000
_08208068: .4byte 0x0000DFFE
_0820806C: .4byte FUN_08207c44
_08208070: .4byte FUN_08207e94
_08208074: .4byte FUN_08207b6c
_08208078: .4byte FUN_08207c80
_0820807C: .4byte FUN_08207eb4
_08208080: .4byte FUN_08207ec0
_08208084:
	cmp r5, #2
	beq _082080EC
	b _0820814A
_0820808A:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _082080B0 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _08208148
	.align 2, 0
_082080B0: .4byte FUN_080421bc
_082080B4:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _082080E8 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _0820814A
	.align 2, 0
_082080E8: .4byte FUN_08042178
_082080EC:
	ldr r1, _0820811C @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _08208120 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08208128
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _08208124 @ =FUN_080421bc
	strb r5, [r4, #6]
	b _0820813C
	.align 2, 0
_0820811C: .4byte 0x00000217
_08208120: .4byte 0x000001EF
_08208124: .4byte FUN_080421bc
_08208128:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820815C @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_0820813C:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_08208148:
	strb r7, [r4, #0x18]
_0820814A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820815C: .4byte FUN_08042868

	thumb_func_start FUN_08208160
FUN_08208160: @ 0x08208160
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08208174
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0xe
	strb r0, [r2, #5]
_08208174:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08208190
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_08208190:
	pop {r0}
	bx r0

	thumb_func_start FUN_08208194
FUN_08208194: @ 0x08208194
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _082081A6
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xf
	strb r0, [r1, #5]
_082081A6:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _082081BC
	movs r0, #0x12
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_082081BC:
	pop {r0}
	bx r0

	thumb_func_start FUN_082081c0
FUN_082081c0: @ 0x082081C0
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _082081D2
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x10
	strb r0, [r1, #5]
_082081D2:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _082081E8
	movs r0, #0x12
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_082081E8:
	pop {r0}
	bx r0

	thumb_func_start FUN_082081ec
FUN_082081ec: @ 0x082081EC
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _082081FE
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x11
	strb r0, [r1, #5]
_082081FE:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08208210
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08208210:
	pop {r0}
	bx r0

	thumb_func_start FUN_08208214
FUN_08208214: @ 0x08208214
	push {r4, lr}
	adds r4, r1, #0
	adds r4, #0x20
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820823A
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x12
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
	movs r0, #1
	strh r0, [r4, #0x16]
_0820823A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08208240
FUN_08208240: @ 0x08208240
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08208254
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0x13
	strb r0, [r2, #5]
_08208254:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _08208270
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_08208270:
	pop {r0}
	bx r0

	thumb_func_start FUN_08208274
FUN_08208274: @ 0x08208274
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08208286
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x14
	strb r0, [r1, #5]
_08208286:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _08208298
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_08208298:
	pop {r0}
	bx r0

	thumb_func_start FUN_0820829c
FUN_0820829c: @ 0x0820829C
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _082082BA
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x15
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_082082BA:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082082c0
FUN_082082c0: @ 0x082082C0
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _082082D4
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0x16
	strb r0, [r2, #5]
_082082D4:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _082082F0
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_082082F0:
	pop {r0}
	bx r0

	thumb_func_start FUN_082082f4
FUN_082082f4: @ 0x082082F4
	push {r4, lr}
	adds r4, r1, #0
	adds r4, #0x20
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820831A
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x17
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
	movs r0, #1
	strh r0, [r4, #0x16]
_0820831A:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08208320
FUN_08208320: @ 0x08208320
	push {lr}
	ldr r3, _08208334 @ =0x085AEB5C
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08208334: .4byte 0x085AEB5C

	thumb_func_start FUN_08208338
FUN_08208338: @ 0x08208338
	push {lr}
	bl FUN_08208320
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08208344
FUN_08208344: @ 0x08208344
	push {lr}
	bl FUN_08208338
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08208350
FUN_08208350: @ 0x08208350
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r1
	adds r7, r2, #0
	ldr r1, _0820844C @ =0x03003584
	ldr r1, [r1]
	ldr r2, _08208450 @ =0x000051E0
	adds r2, r1, r2
	str r2, [sp]
	movs r3, #0xa4
	lsls r3, r3, #7
	adds r3, r3, r1
	mov sb, r3
	ldr r1, _08208454 @ =0x03000228
	str r1, [sp, #4]
	adds r0, #0xdc
	str r1, [r0, #0x68]
	mov r2, r8
	lsls r2, r2, #2
	mov r8, r2
	lsls r7, r7, #2
	subs r2, r7, r2
	str r2, [sp, #0xc]
	movs r3, #0
	mov sl, r3
	movs r0, #0
	str r0, [sp, #0x14]
	movs r1, #0
	str r1, [sp, #0x10]
	movs r2, #0x1f
	movs r3, #0xf
	str r3, [sp, #8]
_08208398:
	ldr r1, [sp]
	ldrh r0, [r1]
	movs r4, #0x1f
	ands r4, r0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x15
	ands r5, r2
	lsrs r6, r0, #0x1a
	ands r6, r2
	mov r3, sb
	cmp r3, #0
	beq _082083CC
	ldrh r0, [r3]
	movs r1, #0x1f
	ands r1, r0
	str r1, [sp, #0x10]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x15
	ands r3, r2
	str r3, [sp, #0x14]
	lsrs r0, r0, #0x1a
	mov sl, r0
	ands r0, r2
	mov sl, r0
	movs r1, #2
	add sb, r1
_082083CC:
	ldr r3, [sp, #0xc]
	adds r0, r4, #0
	muls r0, r3, r0
	ldr r3, [sp, #0x10]
	mov r1, r8
	muls r1, r3, r1
	adds r0, r0, r1
	adds r1, r7, #0
	str r2, [sp, #0x18]
	bl Div
	adds r4, r0, #0
	ldr r2, [sp, #0x18]
	ands r4, r2
	ldr r1, [sp, #0xc]
	adds r0, r5, #0
	muls r0, r1, r0
	ldr r3, [sp, #0x14]
	mov r1, r8
	muls r1, r3, r1
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	adds r5, r0, #0
	ldr r2, [sp, #0x18]
	ands r5, r2
	ldr r1, [sp, #0xc]
	adds r0, r6, #0
	muls r0, r1, r0
	mov r3, r8
	mov r1, sl
	muls r1, r3, r1
	adds r0, r0, r1
	adds r1, r7, #0
	bl Div
	ldr r2, [sp, #0x18]
	ands r0, r2
	lsls r0, r0, #0xa
	lsls r1, r5, #5
	orrs r0, r1
	orrs r4, r0
	ldr r0, [sp, #4]
	strh r4, [r0]
	ldr r1, [sp]
	adds r1, #2
	str r1, [sp]
	adds r0, #2
	str r0, [sp, #4]
	ldr r3, [sp, #8]
	subs r3, #1
	str r3, [sp, #8]
	cmp r3, #0
	bge _08208398
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820844C: .4byte 0x03003584
_08208450: .4byte 0x000051E0
_08208454: .4byte 0x03000228

	thumb_func_start FUN_08208458
FUN_08208458: @ 0x08208458
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r6, [sp, #0x14]
	cmp r4, #9
	bgt _0820847A
	ldrh r0, [r5, #0x20]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	adds r1, r4, r1
	str r6, [sp]
	adds r0, r5, #0
	bl FUN_08041480
	b _08208484
_0820847A:
	str r6, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08041480
_08208484:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820848c
FUN_0820848c: @ 0x0820848C
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082084D6
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	ldrb r2, [r4, #0x1b]
	adds r0, r4, #0
	adds r0, #0x61
	strb r2, [r0]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #1
	bl FUN_08208458
_082084D6:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_082084ec
FUN_082084ec: @ 0x082084EC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08208514
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_08208514:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208618
	adds r3, r5, #0
	adds r3, #0x64
	adds r4, r5, #0
	adds r4, #0x54
	movs r6, #0
	ldrsh r2, [r4, r6]
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r6, #4
	ldrsh r0, [r4, r6]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov ip, r3
	adds r7, r4, #0
	cmp r1, #0x64
	bgt _08208568
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	movs r0, #1
	strb r0, [r5, #7]
	b _08208618
_08208568:
	adds r3, r5, #0
	adds r3, #0x61
	adds r4, r5, #0
	adds r4, #0x6c
	ldrb r6, [r3]
	movs r0, #5
	mov r8, r0
	ldr r2, _08208598 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r3
	cmp r0, #0
	blt _0820859C
	asrs r1, r0, #0xc
	b _082085A2
	.align 2, 0
_08208598: .4byte 0x085B0A08
_0820859C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_082085A2:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _082085BE
	asrs r0, r0, #0xc
	b _082085C4
_082085BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_082085C4:
	strh r0, [r4, #4]
	movs r4, #0
	ldrsh r0, [r7, r4]
	mov r6, ip
	movs r2, #0
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r4, #4
	ldrsh r2, [r6, r4]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #0x1b]
	ldrb r2, [r5, #0x1b]
	mov r6, sb
	strb r2, [r6]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_08208618:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08208628
FUN_08208628: @ 0x08208628
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820864A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_0820864A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082086D0
	ldrb r1, [r4, #0x1b]
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r2, [r0]
	subs r1, r1, r2
	adds r3, r1, #0
	adds r5, r0, #0
	cmp r1, #0
	bge _08208674
	rsbs r3, r1, #0
_08208674:
	cmp r3, #8
	bgt _0820867C
	adds r0, r2, r1
	b _0820868E
_0820867C:
	lsls r0, r1, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x7f
	ble _0820868A
	adds r0, r2, #0
	subs r0, #8
	b _0820868E
_0820868A:
	adds r0, r2, #0
	adds r0, #8
_0820868E:
	strb r0, [r5]
	ldrb r2, [r5]
	strb r2, [r5]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
	ldrb r0, [r5]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _082086D0
	movs r0, #1
	strb r0, [r4, #7]
_082086D0:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_082086d8
FUN_082086d8: @ 0x082086D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r1, #0
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _082086FE
	movs r0, #0
	strb r0, [r5, #9]
	strb r0, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_082086FE:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082087FA
	adds r3, r5, #0
	adds r3, #0x64
	adds r4, r5, #0
	adds r4, #0x54
	movs r6, #0
	ldrsh r2, [r4, r6]
	movs r1, #0
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r6, #4
	ldrsh r0, [r4, r6]
	movs r6, #4
	ldrsh r1, [r3, r6]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	mov ip, r3
	adds r7, r4, #0
	cmp r1, #0x64
	bgt _08208752
	ldr r0, [r5, #0x54]
	ldr r1, [r5, #0x58]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	movs r0, #1
	strb r0, [r5, #7]
	b _082087FA
_08208752:
	adds r3, r5, #0
	adds r3, #0x61
	adds r4, r5, #0
	adds r4, #0x6c
	ldrb r6, [r3]
	ldr r2, _0820877C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	mov r8, r3
	cmp r0, #0
	blt _08208780
	asrs r1, r0, #0xc
	b _08208786
	.align 2, 0
_0820877C: .4byte 0x085B0A08
_08208780:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08208786:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _082087A0
	asrs r0, r0, #0xc
	b _082087A6
_082087A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_082087A6:
	strh r0, [r4, #4]
	movs r3, #0
	ldrsh r0, [r7, r3]
	mov r4, ip
	movs r6, #0
	ldrsh r1, [r4, r6]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r7, r2]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r5, #0x1b]
	ldrb r2, [r5, #0x1b]
	mov r4, r8
	strb r2, [r4]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r5, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r5, #0x19]
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_082087FA:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08208808
FUN_08208808: @ 0x08208808
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820882A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_0820882A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208850
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08208850
	movs r0, #1
	strb r0, [r4, #7]
_08208850:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08208858
FUN_08208858: @ 0x08208858
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820887A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_0820887A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082088A0
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082088A0
	movs r0, #1
	strb r0, [r4, #7]
_082088A0:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_082088a8
FUN_082088a8: @ 0x082088A8
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _082088CA
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #6
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_082088CA:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _082088F0
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _082088F0
	movs r0, #1
	strb r0, [r4, #7]
_082088F0:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_082088f8
FUN_082088f8: @ 0x082088F8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r1, #0
	adds r7, r2, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820893E
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
	movs r0, #0x88
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #3
	strh r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	adds r0, #0xfc
	adds r1, r5, #0
	adds r1, #0xdc
	bl FUN_082372cc
_0820893E:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208986
	ldrh r0, [r6, #0x16]
	cmp r0, #0
	beq _08208986
	cmp r7, #0
	ble _08208986
	adds r0, r7, #0
	movs r1, #0x46
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	bne _08208986
	ldr r0, [r6, #0x18]
	adds r1, r5, #0
	adds r1, #0x5c
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #0x80
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r6, #0x18]
_08208986:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08208990
FUN_08208990: @ 0x08208990
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r1, #0
	adds r5, r6, #0
	adds r5, #0x20
	movs r0, #0x64
	adds r0, r0, r6
	mov r8, r0
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _08208A22
	movs r4, #0
	strb r4, [r6, #9]
	strb r4, [r6, #7]
	movs r0, #0x40
	strb r0, [r6, #0x1b]
	adds r1, #0x61
	strb r0, [r1]
	movs r0, #5
	strb r0, [r6, #0x1a]
	movs r0, #2
	strb r0, [r6, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
	strh r4, [r5, #0xc]
	mov r1, r8
	ldrh r0, [r1]
	strh r0, [r5, #0x10]
	ldrh r0, [r1, #2]
	strh r0, [r5, #0x12]
	ldrh r0, [r1, #4]
	strh r0, [r5, #0x14]
	adds r0, r6, #0
	adds r0, #0x56
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5, #0x12]
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	rsbs r0, r0, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	movs r1, #0xa
	bl Mod
	cmp r0, #4
	ble _08208A18
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	adds r0, #1
	b _08208A20
_08208A18:
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
_08208A20:
	strh r0, [r5, #0xe]
_08208A22:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08208A3A
	b _08208B42
_08208A3A:
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r6, #0xe]
	movs r7, #0
	orrs r0, r1
	strh r0, [r6, #0xe]
	ldrh r0, [r5, #4]
	cmp r0, #1
	beq _08208A78
	cmp r0, #1
	bgt _08208A56
	cmp r0, #0
	beq _08208A5C
	b _08208B42
_08208A56:
	cmp r0, #2
	beq _08208B16
	b _08208B42
_08208A5C:
	adds r4, r6, #0
	adds r4, #0x20
	strh r7, [r4, #6]
	adds r0, r6, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08208B42
	movs r0, #1
	strh r0, [r4, #4]
	strh r0, [r4, #6]
	str r7, [r4, #8]
	b _08208B42
_08208A78:
	adds r0, r6, #0
	adds r0, #0x20
	ldrh r1, [r0, #6]
	strh r7, [r0, #6]
	adds r7, r0, #0
	cmp r1, #0
	beq _08208A96
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208A96:
	adds r0, r6, #0
	adds r0, #0x54
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5, #0x10]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r4, [r0, r2]
	ldrh r0, [r5, #0x14]
	subs r4, r4, r0
	ldr r0, [r5, #8]
	muls r0, r1, r0
	ldrh r1, [r5, #0xe]
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	mov r0, r8
	strh r1, [r0]
	ldr r0, [r5, #8]
	muls r0, r4, r0
	ldrh r1, [r5, #0xe]
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	mov r2, r8
	strh r1, [r2, #4]
	ldr r1, [r5, #8]
	rsbs r0, r1, #0
	muls r0, r1, r0
	cmp r0, #0
	blt _08208AE0
	asrs r2, r0, #1
	b _08208AE6
_08208AE0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r2, r0, #0
_08208AE6:
	movs r0, #0xc
	ldrsh r1, [r5, r0]
	ldr r0, [r5, #8]
	muls r0, r1, r0
	ldrh r1, [r5, #0x12]
	adds r0, r0, r1
	adds r0, r0, r2
	mov r2, r8
	strh r0, [r2, #2]
	ldr r0, [r5, #8]
	ldrh r5, [r5, #0xe]
	cmp r0, r5
	blo _08208B42
	adds r0, r6, #0
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r2, #2]
	movs r0, #2
	strh r0, [r7, #4]
	movs r0, #1
	strh r0, [r7, #6]
	movs r0, #0
	str r0, [r7, #8]
	b _08208B42
_08208B16:
	adds r0, r6, #0
	adds r0, #0x20
	ldrh r1, [r0, #6]
	strh r7, [r0, #6]
	cmp r1, #0
	beq _08208B32
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #9
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208B32:
	adds r0, r6, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08208B42
	movs r0, #1
	strb r0, [r6, #7]
_08208B42:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08208b50
FUN_08208b50: @ 0x08208B50
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r1, #0
	adds r5, r6, #0
	adds r5, #0x20
	adds r7, r6, #0
	adds r7, #0x64
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _08208B98
	movs r0, #0
	strb r0, [r6, #9]
	strb r0, [r6, #7]
	strb r0, [r6, #0x1b]
	adds r1, #0x61
	strb r0, [r1]
	movs r0, #3
	strb r0, [r6, #0x1a]
	movs r0, #1
	strb r0, [r6, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
	movs r0, #0x14
	strh r0, [r5, #0xc]
	ldrh r0, [r5, #0x10]
	strh r0, [r7]
	ldrh r0, [r5, #0x12]
	strh r0, [r7, #2]
	ldrh r0, [r5, #0x14]
	strh r0, [r7, #4]
_08208B98:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208C5A
	movs r0, #0x80
	lsls r0, r0, #3
	ldrh r1, [r6, #0xe]
	movs r2, #0
	orrs r0, r1
	strh r0, [r6, #0xe]
	ldrh r0, [r5, #4]
	cmp r0, #0
	beq _08208BC6
	cmp r0, #1
	beq _08208C58
	b _08208C5A
_08208BC6:
	strh r2, [r5, #6]
	adds r0, r6, #0
	adds r0, #0x54
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5, #0x10]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0x58
	movs r2, #0
	ldrsh r4, [r0, r2]
	ldrh r0, [r5, #0x14]
	subs r4, r4, r0
	ldr r0, [r5, #8]
	muls r0, r1, r0
	ldrh r1, [r5, #0xe]
	bl Div
	ldrh r1, [r5, #0x10]
	adds r1, r1, r0
	strh r1, [r7]
	ldr r0, [r5, #8]
	muls r0, r4, r0
	ldrh r1, [r5, #0xe]
	bl Div
	ldrh r1, [r5, #0x14]
	adds r1, r1, r0
	strh r1, [r7, #4]
	ldr r0, [r5, #8]
	lsls r0, r0, #7
	ldrh r1, [r5, #0xe]
	bl Div
	ldr r2, _08208C28 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r0, #0
	ldrsh r1, [r1, r0]
	movs r0, #0xc8
	muls r0, r1, r0
	adds r2, r5, #0
	cmp r0, #0
	blt _08208C2C
	asrs r1, r0, #0xc
	b _08208C32
	.align 2, 0
_08208C28: .4byte 0x085B0A08
_08208C2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08208C32:
	ldrh r0, [r5, #0x12]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldr r0, [r5, #8]
	ldrh r5, [r5, #0xe]
	cmp r0, r5
	blo _08208C5A
	adds r0, r6, #0
	adds r0, #0x56
	ldrh r0, [r0]
	strh r0, [r7, #2]
	movs r0, #1
	movs r1, #1
	strh r0, [r2, #4]
	strh r0, [r2, #6]
	movs r0, #0
	str r0, [r2, #8]
	strb r1, [r6, #7]
	b _08208C5A
_08208C58:
	strh r2, [r5, #6]
_08208C5A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08208c64
FUN_08208c64: @ 0x08208C64
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0
	adds r6, r2, #0
	adds r7, r4, #0
	adds r7, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08208C7A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
_08208C7A:
	adds r0, r6, #0
	movs r1, #0x3c
	bl Div
	adds r5, r0, #0
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _08208C9A
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	movs r1, #0x3c
	subs r1, r1, r0
	b _08208CA4
_08208C9A:
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	adds r1, r0, #0
_08208CA4:
	adds r0, r4, #0
	movs r2, #0x3c
	bl FUN_08208350
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08208CE2
	ands r5, r0
	cmp r5, #0
	beq _08208CD8
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	movs r1, #0x3c
	subs r1, r1, r0
	str r1, [r7, #0x1c]
	b _08208CE2
_08208CD8:
	adds r0, r6, #0
	movs r1, #0x3c
	bl Mod
	str r0, [r7, #0x1c]
_08208CE2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08208ce8
FUN_08208ce8: @ 0x08208CE8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r6, r4, #0
	adds r6, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08208D32
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	ldrb r0, [r4, #0x19]
	movs r2, #0xc0
	cmp r0, #1
	bls _08208D08
	movs r2, #0x80
_08208D08:
	adds r0, r4, #0
	adds r0, #0x61
	strb r2, [r0]
	lsrs r1, r2, #5
	adds r1, #3
	movs r0, #7
	ands r0, r1
	strb r0, [r4, #0x1a]
	lsrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_08208D32:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208E0E
	ldrh r5, [r6, #4]
	cmp r5, #1
	beq _08208D94
	cmp r5, #1
	bgt _08208D58
	cmp r5, #0
	beq _08208D62
	b _08208E0E
_08208D58:
	cmp r5, #2
	beq _08208DAC
	cmp r5, #3
	beq _08208DE2
	b _08208E0E
_08208D62:
	adds r6, r4, #0
	adds r6, #0x20
	ldrh r0, [r6, #6]
	strh r5, [r6, #6]
	cmp r0, #0
	beq _08208D7E
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208D7E:
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08208E0E
	movs r0, #1
	strh r0, [r6, #4]
	strh r0, [r6, #6]
	str r5, [r6, #8]
	b _08208E0E
_08208D94:
	adds r1, r4, #0
	adds r1, #0x20
	movs r2, #0
	strh r2, [r1, #6]
	ldr r0, [r6, #8]
	cmp r0, #0x1e
	bls _08208E0E
	movs r0, #2
	strh r0, [r1, #4]
	strh r5, [r1, #6]
	str r2, [r1, #8]
	b _08208E0E
_08208DAC:
	adds r5, r4, #0
	adds r5, #0x20
	ldrh r0, [r5, #6]
	movs r6, #0
	strh r6, [r5, #6]
	cmp r0, #0
	beq _08208DCA
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208DCA:
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08208E0E
	movs r0, #3
	strh r0, [r5, #4]
	movs r0, #1
	strh r0, [r5, #6]
	str r6, [r5, #8]
	b _08208E0E
_08208DE2:
	adds r0, r4, #0
	adds r0, #0x20
	ldrh r2, [r0, #6]
	movs r1, #0
	strh r1, [r0, #6]
	cmp r2, #0
	beq _08208DFE
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
_08208DFE:
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r0, [r0]
	ldrb r1, [r4, #0x1b]
	cmp r0, r1
	bne _08208E0E
	movs r0, #1
	strb r0, [r4, #7]
_08208E0E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08208e18
FUN_08208e18: @ 0x08208E18
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r1, #0
	adds r7, r2, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08208E5E
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #5
	movs r2, #2
	movs r3, #0
	bl FUN_08208458
	movs r0, #0x88
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #3
	strh r0, [r1]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r4, [r0]
	adds r0, r5, #0
	adds r0, #0xfc
	adds r1, r5, #0
	adds r1, #0xdc
	bl FUN_082372cc
_08208E5E:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08208EC0
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	adds r0, r5, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _08208E8E
	movs r0, #1
	strb r0, [r5, #7]
_08208E8E:
	ldrh r0, [r6, #0x16]
	cmp r0, #0
	beq _08208EC0
	cmp r7, #0
	ble _08208EC0
	adds r0, r7, #0
	movs r1, #0x46
	bl Mod
	adds r3, r0, #0
	cmp r3, #0
	bne _08208EC0
	ldr r0, [r6, #0x18]
	adds r1, r5, #0
	adds r1, #0x5c
	str r3, [sp]
	str r3, [sp, #4]
	movs r2, #0x80
	str r2, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #2
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r6, #0x18]
_08208EC0:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08208ec8
FUN_08208ec8: @ 0x08208EC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x64
	ldr r1, _08208F34 @ =0x00000434
	adds r0, r6, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08208F80
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r7, #0
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl FUN_0823785c
	adds r3, r4, #0
	adds r3, #0x61
	ldrb r1, [r3]
	subs r0, r0, r1
	lsls r0, r0, #0x18
	asrs r1, r0, #0x18
	cmp r1, #8
	ble _08208F38
	ldrb r2, [r3]
	adds r2, #8
	strb r2, [r3]
	adds r0, r2, #0
	adds r0, #0x10
	movs r3, #0xff
	ands r0, r3
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	strb r1, [r4, #0x1a]
	adds r2, #0x20
	ands r2, r3
	asrs r2, r2, #6
	adds r2, #1
	movs r0, #3
	ands r0, r2
	strb r0, [r4, #0x19]
	b _08208F70
	.align 2, 0
_08208F34: .4byte 0x00000434
_08208F38:
	movs r0, #8
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08208F46
	ldrb r0, [r3]
	subs r0, #8
	b _08208F4A
_08208F46:
	ldrb r0, [r3]
	adds r0, r0, r1
_08208F4A:
	strb r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r0, #0
	adds r1, #0x10
	movs r3, #0xff
	ands r1, r3
	asrs r1, r1, #5
	adds r1, #3
	movs r2, #7
	ands r2, r1
	strb r2, [r4, #0x1a]
	adds r0, #0x20
	ands r0, r3
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	strb r1, [r4, #0x19]
_08208F70:
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	adds r0, #0x29
	ldrb r0, [r0]
	mov r8, r0
	b _08208F84
_08208F80:
	movs r2, #0
	mov r8, r2
_08208F84:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _08209048
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
	movs r3, #0xf6
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r1, [r0]
	ldr r7, _08209038 @ =0x00000225
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0x87
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08209058
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _08209014
	movs r3, #0xe0
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08209014
	ldr r7, _0820903C @ =0x00000446
	adds r0, r1, r7
	ldrh r0, [r0]
	cmp r0, #0
	beq _08208FFC
	ldr r2, _08209040 @ =0x00000442
	adds r0, r1, r2
	ldrh r0, [r0]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bls _08209014
_08208FFC:
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	movs r1, #1
	cmp r0, #1
	bls _08209010
	cmp r0, #7
	beq _08209010
	movs r1, #0
_08209010:
	cmp r1, #0
	bne _08209058
_08209014:
	ldr r0, _08209044 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08209058
	ldrb r0, [r4, #0xb]
	cmp r0, #0
	beq _08209058
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	movs r3, #0
	bl FUN_080415cc
	b _08209058
	.align 2, 0
_08209038: .4byte 0x00000225
_0820903C: .4byte 0x00000446
_08209040: .4byte 0x00000442
_08209044: .4byte 0x030047A4
_08209048:
	movs r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08208458
_08209058:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r7, #0xb9
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _08209124
	ldr r1, _08209130 @ =0x00000434
	adds r0, r6, r1
	ldr r2, [r0]
	movs r3, #0x8a
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r3, [r0]
	movs r7, #0
	ldrsh r1, [r2, r7]
	movs r7, #0
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _08209096
	rsbs r1, r1, #0
_08209096:
	cmp r1, r3
	bge _082090C4
	movs r0, #2
	ldrsh r1, [r2, r0]
	movs r7, #2
	ldrsh r0, [r5, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _082090AA
	rsbs r1, r1, #0
_082090AA:
	cmp r1, #0xff
	bgt _082090C4
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #4
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _082090BE
	rsbs r0, r0, #0
_082090BE:
	movs r1, #1
	cmp r0, r3
	blt _082090C6
_082090C4:
	movs r1, #0
_082090C6:
	cmp r1, #0
	beq _08209124
	ldr r3, _08209130 @ =0x00000434
	adds r0, r6, r3
	ldr r2, [r0]
	movs r7, #0
	ldrsh r0, [r5, r7]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	mov r7, r8
	subs r0, r7, r0
	adds r1, r4, #0
	adds r1, #0x61
	ldrb r1, [r1]
	adds r1, #0x80
	subs r1, r7, r1
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08209108
	rsbs r0, r0, #0
_08209108:
	cmp r0, #0x3f
	bgt _08209124
	lsls r0, r1, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _08209116
	rsbs r0, r0, #0
_08209116:
	cmp r0, #0x1f
	bgt _08209124
	movs r0, #0x80
	lsls r0, r0, #4
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_08209124:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08209130: .4byte 0x00000434

	thumb_func_start FUN_08209134
FUN_08209134: @ 0x08209134
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r3, r0, #0
	adds r6, r3, #0
	adds r6, #0x20
	ldrb r0, [r3, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x17
	bhi _08209190
	ldr r1, _0820918C @ =0x085AEBC4
	ldrb r2, [r3, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r4, #0
	strb r2, [r3, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r3, r2
	str r1, [r0]
	str r4, [r3, #0x10]
	movs r5, #1
	strb r5, [r3, #9]
	strb r4, [r3, #0x18]
	ldr r0, [r6, #0x18]
	adds r1, r3, #0
	adds r1, #0x5c
	str r4, [sp]
	str r4, [sp, #4]
	movs r2, #0x80
	str r2, [sp, #8]
	str r4, [sp, #0xc]
	movs r2, #2
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r6, #0x18]
	strh r4, [r6, #4]
	strh r5, [r6, #6]
	str r4, [r6, #8]
	movs r0, #1
	b _08209192
	.align 2, 0
_0820918C: .4byte 0x085AEBC4
_08209190:
	movs r0, #0
_08209192:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820919c
FUN_0820919c: @ 0x0820919C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r4, #0
	adds r5, #0x20
	movs r1, #0
	movs r0, #0
	strh r0, [r4, #0xe]
	strb r1, [r4, #7]
	ldr r2, [r4, #0x10]
	adds r0, r2, #1
	str r0, [r4, #0x10]
	ldrh r0, [r5, #6]
	cmp r0, #0
	bne _082091C0
	ldr r0, [r5, #8]
	adds r0, #1
	str r0, [r5, #8]
_082091C0:
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _082091E6
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r3
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	ble _082091E6
	subs r1, #1
	str r1, [r5, #0x1c]
	adds r0, r4, #0
	movs r2, #0x3c
	bl FUN_08208350
_082091E6:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082091f0
FUN_082091f0: @ 0x082091F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sl, r0
	movs r1, #0x20
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0
	mov sb, r2
	ldr r0, _0820921C @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r3, #0xb5
	lsls r3, r3, #1
	adds r0, r6, r3
	b _082094D8
	.align 2, 0
_0820921C: .4byte 0x03002B4C
_08209220:
	ldr r0, _08209254 @ =0x03002B4C
	ldr r0, [r0]
	mov r7, sb
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sl
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sl
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x29
	bls _08209248
	b _082094CA
_08209248:
	lsls r0, r0, #2
	ldr r1, _08209258 @ =_0820925C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08209254: .4byte 0x03002B4C
_08209258: .4byte _0820925C
_0820925C: @ jump table
	.4byte _08209304 @ case 0
	.4byte _0820930E @ case 1
	.4byte _08209326 @ case 2
	.4byte _08209382 @ case 3
	.4byte _082094CA @ case 4
	.4byte _082094CA @ case 5
	.4byte _082094CA @ case 6
	.4byte _082094CA @ case 7
	.4byte _082094CA @ case 8
	.4byte _082094CA @ case 9
	.4byte _0820949E @ case 10
	.4byte _082094CA @ case 11
	.4byte _082094CA @ case 12
	.4byte _082094CA @ case 13
	.4byte _082094CA @ case 14
	.4byte _082094CA @ case 15
	.4byte _082094CA @ case 16
	.4byte _082094CA @ case 17
	.4byte _082094CA @ case 18
	.4byte _082094CA @ case 19
	.4byte _0820933C @ case 20
	.4byte _082093C8 @ case 21
	.4byte _082093DE @ case 22
	.4byte _082093F4 @ case 23
	.4byte _0820940A @ case 24
	.4byte _0820940E @ case 25
	.4byte _08209424 @ case 26
	.4byte _0820944C @ case 27
	.4byte _08209488 @ case 28
	.4byte _0820948C @ case 29
	.4byte _082094CA @ case 30
	.4byte _082094CA @ case 31
	.4byte _082094CA @ case 32
	.4byte _082094CA @ case 33
	.4byte _082094CA @ case 34
	.4byte _082094CA @ case 35
	.4byte _082094CA @ case 36
	.4byte _082094CA @ case 37
	.4byte _082094CA @ case 38
	.4byte _082094CA @ case 39
	.4byte _082094CA @ case 40
	.4byte _082094B2 @ case 41
_08209304:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _08209496
_0820930E:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	strb r0, [r6, #8]
	b _082094CA
_08209326:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _08209498
_0820933C:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _08209498
_08209382:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #0x10
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _08209498
_082093C8:
	movs r0, #0x11
	movs r1, #0
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	movs r0, #1
	strb r0, [r6, #8]
	mov r7, r8
	strh r1, [r7, #0x16]
	b _082094CA
_082093DE:
	movs r0, #0x14
	movs r1, #0
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	movs r0, #1
	strb r0, [r6, #8]
	mov r0, r8
	strh r1, [r0, #0x16]
	b _082094CA
_082093F4:
	movs r0, #0x12
	movs r1, #0
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	movs r0, #1
	strb r0, [r6, #8]
	mov r1, r8
	strh r0, [r1, #0x16]
	b _082094CA
_0820940A:
	movs r1, #0x13
	b _0820948E
_0820940E:
	movs r0, #0x14
	movs r1, #0
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	movs r0, #1
	strb r0, [r6, #8]
	mov r2, r8
	strh r0, [r2, #0x16]
	b _082094CA
_08209424:
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	adds r0, #0x54
	movs r2, #0
	movs r3, #0
	strh r1, [r0]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	movs r0, #0x15
	strb r2, [r6, #2]
	strb r2, [r6, #3]
	strb r0, [r6, #4]
	str r3, [r6, #0x14]
	b _08209498
_0820944C:
	ldrh r0, [r7, #8]
	movs r2, #0
	movs r3, #0
	mov r1, r8
	strh r0, [r1, #0x10]
	ldrh r0, [r7, #0xa]
	strh r0, [r1, #0x12]
	ldrh r0, [r7, #0xc]
	strh r0, [r1, #0x14]
	ldrh r1, [r7, #0xe]
	adds r0, r6, #0
	adds r0, #0x54
	strh r1, [r0]
	ldrh r0, [r7, #0x10]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0x12]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	ldrh r0, [r7, #0x14]
	mov r7, r8
	strh r0, [r7, #0xe]
	movs r0, #0x16
	strb r2, [r6, #2]
	strb r2, [r6, #3]
	strb r0, [r6, #4]
	str r3, [r6, #0x14]
	b _08209498
_08209488:
	movs r1, #0x17
	b _0820948E
_0820948C:
	movs r1, #0x18
_0820948E:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_08209496:
	str r0, [r6, #0x14]
_08209498:
	movs r0, #1
	strb r0, [r6, #8]
	b _082094CA
_0820949E:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _082094CA
_082094B2:
	ldrh r1, [r7, #8]
	adds r0, r6, #0
	adds r0, #0x64
	strh r1, [r0]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x66
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x68
	strh r1, [r0]
_082094CA:
	movs r1, #1
	add sb, r1
	ldr r0, _082094F4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sl
	adds r0, #6
_082094D8:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp sb, r0
	bge _082094E4
	b _08209220
_082094E4:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082094F4: .4byte 0x03002B4C

	thumb_func_start FUN_082094f8
FUN_082094f8: @ 0x082094F8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_082091f0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08209518
FUN_08209518: @ 0x08209518
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08209524
FUN_08209524: @ 0x08209524
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_08209534
FUN_08209534: @ 0x08209534
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov sl, r0
	ldr r0, _082095A0 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820954E
	b _082097C6
_0820954E:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #5
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _082095AC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _082095A4 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _082095A8 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _082095B6
	.align 2, 0
_082095A0: .4byte 0x03002B50
_082095A4: .4byte 0xFFFF0000
_082095A8: .4byte 0x0000FFFF
_082095AC:
	ldr r1, _082096CC @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_082095B6:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r7, #0
	mov r0, r8
	adds r1, r6, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _082095D2
	b _082097C6
_082095D2:
	mov r1, r8
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _082095E2
	b _082097C6
_082095E2:
	str r7, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _082096D0 @ =0x0000E00E
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _082095F6
	b _082097C6
_082095F6:
	adds r0, r4, #0
	adds r0, #0x20
	movs r6, #0
	mov r1, sl
	strh r1, [r4, #0x20]
	strh r7, [r0, #0x16]
	str r7, [r0, #0x18]
	str r7, [r0, #0x1c]
	adds r0, #0x3c
	movs r1, #0xc8
	strh r7, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r7, [r0, #0x34]
	movs r2, #0xae
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r3, #0xb2
	lsls r3, r3, #1
	adds r0, r4, r3
	mov r1, r8
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov r8, r3
	mov r3, r8
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _082096D4 @ =FUN_08209134
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082096D8 @ =FUN_082094f8
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082096DC @ =FUN_08208344
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082096E0 @ =FUN_0820919c
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _082096E4 @ =FUN_08209518
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _082096E8 @ =FUN_08209524
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	strb r5, [r4, #0x1b]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _082096D0 @ =0x0000E00E
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820971C
	cmp r5, #1
	bgt _082096EC
	cmp r5, #0
	beq _082096F6
	b _082097C6
	.align 2, 0
_082096CC: .4byte 0xFFFF0000
_082096D0: .4byte 0x0000E00E
_082096D4: .4byte FUN_08209134
_082096D8: .4byte FUN_082094f8
_082096DC: .4byte FUN_08208344
_082096E0: .4byte FUN_0820919c
_082096E4: .4byte FUN_08209518
_082096E8: .4byte FUN_08209524
_082096EC:
	cmp r5, #2
	beq _08209750
	cmp r5, #3
	beq _082097A4
	b _082097C6
_082096F6:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08209718 @ =FUN_0820848c
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	str r7, [r4, #0x10]
	strb r1, [r4, #9]
	b _082097C4
	.align 2, 0
_08209718: .4byte FUN_0820848c
_0820971C:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r7, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820974C @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	str r7, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _082097C6
	.align 2, 0
_0820974C: .4byte FUN_08042178
_08209750:
	ldr r3, _08209780 @ =0x00000217
	adds r0, r4, r3
	movs r2, #1
	strb r2, [r0]
	ldr r1, _08209784 @ =0x000001EF
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820978C
	adds r0, r4, #0
	str r2, [sp, #0xc]
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	ldr r2, [sp, #0xc]
	strb r2, [r4, #8]
	ldr r1, _08209788 @ =FUN_080421bc
	strb r5, [r4, #6]
	b _082097B8
	.align 2, 0
_08209780: .4byte 0x00000217
_08209784: .4byte 0x000001EF
_08209788: .4byte FUN_080421bc
_0820978C:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	strb r2, [r4, #8]
	ldr r1, _082097A0 @ =FUN_08042868
	mov r0, r8
	b _082097B6
	.align 2, 0
_082097A0: .4byte FUN_08042868
_082097A4:
	movs r0, #0x14
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _082097D8 @ =FUN_082088f8
	movs r0, #0x12
_082097B6:
	strb r0, [r4, #6]
_082097B8:
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	str r7, [r4, #0x10]
	strb r2, [r4, #9]
_082097C4:
	strb r6, [r4, #0x18]
_082097C6:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082097D8: .4byte FUN_082088f8

	thumb_func_start FUN_082097dc
FUN_082097dc: @ 0x082097DC
	push {lr}
	movs r0, #0
	bl FUN_08209534
	pop {r0}
	bx r0

	thumb_func_start FUN_082097e8
FUN_082097e8: @ 0x082097E8
	push {lr}
	movs r0, #1
	bl FUN_08209534
	pop {r0}
	bx r0

	thumb_func_start FUN_082097f4
FUN_082097f4: @ 0x082097F4
	push {r4, lr}
	ldr r0, _08209830 @ =0x03002B50
	ldr r4, [r0]
	cmp r4, #0
	beq _0820982A
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08040eb0
	adds r3, r0, #0
	cmp r3, #0
	beq _0820982A
	ldr r0, _08209834 @ =0x00000217
	adds r1, r3, r0
	movs r0, #0
	movs r2, #1
	strb r2, [r1]
	movs r1, #0x19
	strb r0, [r3, #2]
	strb r0, [r3, #3]
	strb r1, [r3, #4]
	str r0, [r3, #0x14]
	strb r2, [r3, #8]
_0820982A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08209830: .4byte 0x03002B50
_08209834: .4byte 0x00000217

	thumb_func_start FUN_08209838
FUN_08209838: @ 0x08209838
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0820984C
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xe
	strb r0, [r4, #5]
_0820984C:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _08209868
	movs r1, #1
	movs r0, #0
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_08209868:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08209874
FUN_08209874: @ 0x08209874
	push {lr}
	ldr r3, _08209888 @ =0x085AEC24
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08209888: .4byte 0x085AEC24

	thumb_func_start FUN_0820988c
FUN_0820988c: @ 0x0820988C
	push {lr}
	bl FUN_08209874
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08209898
FUN_08209898: @ 0x08209898
	push {lr}
	bl FUN_0820988c
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_082098a4
FUN_082098a4: @ 0x082098A4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _082098D8
	ldr r1, _082098D4 @ =0x085AEC68
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _082098DA
	.align 2, 0
_082098D4: .4byte 0x085AEC68
_082098D8:
	movs r0, #0
_082098DA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_082098e0
FUN_082098e0: @ 0x082098E0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0820990A
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_0820990A:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08209914
FUN_08209914: @ 0x08209914
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _08209938 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r7, r2
	b _08209AB6
	.align 2, 0
_08209938: .4byte 0x03002B4C
_0820993C:
	ldr r0, _08209970 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r6, [r0]
	mov r0, sb
	adds r1, r6, #0
	bl FUN_08022474
	ldrb r0, [r6, #6]
	cmp r0, #0x14
	bls _08209964
	b _08209AA8
_08209964:
	lsls r0, r0, #2
	ldr r1, _08209974 @ =_08209978
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08209970: .4byte 0x03002B4C
_08209974: .4byte _08209978
_08209978: @ jump table
	.4byte _082099CC @ case 0
	.4byte _082099D8 @ case 1
	.4byte _08209A7C @ case 2
	.4byte _082099F0 @ case 3
	.4byte _08209AA8 @ case 4
	.4byte _08209AA8 @ case 5
	.4byte _08209AA8 @ case 6
	.4byte _08209AA8 @ case 7
	.4byte _08209AA8 @ case 8
	.4byte _08209AA8 @ case 9
	.4byte _08209A96 @ case 10
	.4byte _08209AA8 @ case 11
	.4byte _08209AA8 @ case 12
	.4byte _08209AA8 @ case 13
	.4byte _08209AA8 @ case 14
	.4byte _08209AA8 @ case 15
	.4byte _08209AA8 @ case 16
	.4byte _08209AA8 @ case 17
	.4byte _08209AA8 @ case 18
	.4byte _08209AA8 @ case 19
	.4byte _08209A36 @ case 20
_082099CC:
	movs r0, #0
	strb r0, [r7, #2]
	strb r0, [r7, #3]
	strb r0, [r7, #4]
	str r0, [r7, #0x14]
	b _08209A90
_082099D8:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #1
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
	strb r0, [r7, #8]
	b _08209AA8
_082099F0:
	ldrh r0, [r6, #8]
	adds r3, r7, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r6, #0xa]
	adds r1, r7, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r6, #0xc]
	adds r0, r7, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x64
	movs r6, #0
	ldrsh r0, [r3, r6]
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #0x1b]
	movs r0, #0x10
	strb r4, [r7, #2]
	strb r4, [r7, #3]
	strb r0, [r7, #4]
	str r5, [r7, #0x14]
	b _08209A90
_08209A36:
	ldrh r0, [r6, #8]
	adds r3, r7, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r6, #0xa]
	adds r1, r7, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r6, #0xc]
	adds r0, r7, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x64
	movs r6, #0
	ldrsh r0, [r3, r6]
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #0x1b]
	movs r0, #2
	strb r4, [r7, #2]
	strb r4, [r7, #3]
	strb r0, [r7, #4]
	str r5, [r7, #0x14]
	b _08209A90
_08209A7C:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #3
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
_08209A90:
	movs r0, #1
	strb r0, [r7, #8]
	b _08209AA8
_08209A96:
	movs r0, #8
	ldrsh r1, [r6, r0]
	movs r3, #0xa
	ldrsh r2, [r6, r3]
	movs r0, #0xc
	ldrsh r3, [r6, r0]
	adds r0, r7, #0
	bl FUN_080415cc
_08209AA8:
	movs r1, #1
	add r8, r1
	ldr r0, _08209AD0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_08209AB6:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08209AC2
	b _0820993C
_08209AC2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08209AD0: .4byte 0x03002B4C

	thumb_func_start FUN_08209ad4
FUN_08209ad4: @ 0x08209AD4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08209914
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08209af4
FUN_08209af4: @ 0x08209AF4
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08209b00
FUN_08209b00: @ 0x08209B00
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_08209b10
FUN_08209b10: @ 0x08209B10
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _08209B7C @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08209B28
	b _08209D8A
_08209B28:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #7
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08209B88
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08209B80 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08209B84 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _08209B92
	.align 2, 0
_08209B7C: .4byte 0x03002B50
_08209B80: .4byte 0xFFFF0000
_08209B84: .4byte 0x0000FFFF
_08209B88:
	ldr r1, _08209CA4 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_08209B92:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _08209BB0
	b _08209D8A
_08209BB0:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _08209BC0
	b _08209D8A
_08209BC0:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _08209CA8 @ =0x0000E01E
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _08209BD6
	b _08209D8A
_08209BD6:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xbe
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _08209CAC @ =FUN_082098a4
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08209CB0 @ =FUN_08209ad4
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08209CB4 @ =FUN_08209898
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08209CB8 @ =FUN_082098e0
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _08209CBC @ =FUN_08209af4
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _08209CC0 @ =FUN_08209b00
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _08209CA8 @ =0x0000E01E
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _08209CF4
	cmp r5, #1
	bgt _08209CC4
	cmp r5, #0
	beq _08209CCA
	b _08209D8A
	.align 2, 0
_08209CA4: .4byte 0xFFFF0000
_08209CA8: .4byte 0x0000E01E
_08209CAC: .4byte FUN_082098a4
_08209CB0: .4byte FUN_08209ad4
_08209CB4: .4byte FUN_08209898
_08209CB8: .4byte FUN_082098e0
_08209CBC: .4byte FUN_08209af4
_08209CC0: .4byte FUN_08209b00
_08209CC4:
	cmp r5, #2
	beq _08209D2C
	b _08209D8A
_08209CCA:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _08209CF0 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _08209D88
	.align 2, 0
_08209CF0: .4byte FUN_080421bc
_08209CF4:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _08209D28 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _08209D8A
	.align 2, 0
_08209D28: .4byte FUN_08042178
_08209D2C:
	ldr r1, _08209D5C @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _08209D60 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08209D68
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _08209D64 @ =FUN_080421bc
	strb r5, [r4, #6]
	b _08209D7C
	.align 2, 0
_08209D5C: .4byte 0x00000217
_08209D60: .4byte 0x000001EF
_08209D64: .4byte FUN_080421bc
_08209D68:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _08209D9C @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_08209D7C:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_08209D88:
	strb r7, [r4, #0x18]
_08209D8A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08209D9C: .4byte FUN_08042868

	thumb_func_start FUN_08209da0
FUN_08209da0: @ 0x08209DA0
	push {lr}
	ldr r3, _08209DB4 @ =0x085AECA4
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_08209DB4: .4byte 0x085AECA4

	thumb_func_start FUN_08209db8
FUN_08209db8: @ 0x08209DB8
	push {lr}
	bl FUN_08209da0
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08209dc4
FUN_08209dc4: @ 0x08209DC4
	push {lr}
	bl FUN_08209db8
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08209dd0
FUN_08209dd0: @ 0x08209DD0
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bhi _08209E04
	ldr r1, _08209E00 @ =0x085AECE4
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _08209E06
	.align 2, 0
_08209E00: .4byte 0x085AECE4
_08209E04:
	movs r0, #0
_08209E06:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08209e0c
FUN_08209e0c: @ 0x08209E0C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _08209E36
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_08209E36:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08209e40
FUN_08209e40: @ 0x08209E40
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _08209E64 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r7, r2
	b _08209F70
	.align 2, 0
_08209E64: .4byte 0x03002B4C
_08209E68:
	ldr r0, _08209E98 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r6, [r0]
	mov r0, sb
	adds r1, r6, #0
	bl FUN_08022474
	ldrb r0, [r6, #6]
	cmp r0, #0xa
	bhi _08209F62
	lsls r0, r0, #2
	ldr r1, _08209E9C @ =_08209EA0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08209E98: .4byte 0x03002B4C
_08209E9C: .4byte _08209EA0
_08209EA0: @ jump table
	.4byte _08209ECC @ case 0
	.4byte _08209ED8 @ case 1
	.4byte _08209F36 @ case 2
	.4byte _08209EF0 @ case 3
	.4byte _08209F62 @ case 4
	.4byte _08209F62 @ case 5
	.4byte _08209F62 @ case 6
	.4byte _08209F62 @ case 7
	.4byte _08209F62 @ case 8
	.4byte _08209F62 @ case 9
	.4byte _08209F50 @ case 10
_08209ECC:
	movs r0, #0
	strb r0, [r7, #2]
	strb r0, [r7, #3]
	strb r0, [r7, #4]
	str r0, [r7, #0x14]
	b _08209F4A
_08209ED8:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #1
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
	strb r0, [r7, #8]
	b _08209F62
_08209EF0:
	ldrh r0, [r6, #8]
	adds r3, r7, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r6, #0xa]
	adds r1, r7, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r6, #0xc]
	adds r0, r7, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x64
	movs r6, #0
	ldrsh r0, [r3, r6]
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #0x1b]
	movs r0, #2
	strb r4, [r7, #2]
	strb r4, [r7, #3]
	strb r0, [r7, #4]
	str r5, [r7, #0x14]
	b _08209F4A
_08209F36:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #3
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
_08209F4A:
	movs r0, #1
	strb r0, [r7, #8]
	b _08209F62
_08209F50:
	movs r0, #8
	ldrsh r1, [r6, r0]
	movs r3, #0xa
	ldrsh r2, [r6, r3]
	movs r0, #0xc
	ldrsh r3, [r6, r0]
	adds r0, r7, #0
	bl FUN_080415cc
_08209F62:
	movs r1, #1
	add r8, r1
	ldr r0, _08209F88 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_08209F70:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _08209F7C
	b _08209E68
_08209F7C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08209F88: .4byte 0x03002B4C

	thumb_func_start FUN_08209f8c
FUN_08209f8c: @ 0x08209F8C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_08209e40
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08209fac
FUN_08209fac: @ 0x08209FAC
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_08209fb8
FUN_08209fb8: @ 0x08209FB8
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_08209fc8
FUN_08209fc8: @ 0x08209FC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0820A034 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _08209FE0
	b _0820A242
_08209FE0:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #8
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0820A040
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820A038 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820A03C @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820A04A
	.align 2, 0
_0820A034: .4byte 0x03002B50
_0820A038: .4byte 0xFFFF0000
_0820A03C: .4byte 0x0000FFFF
_0820A040:
	ldr r1, _0820A15C @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820A04A:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _0820A068
	b _0820A242
_0820A068:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820A078
	b _0820A242
_0820A078:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _0820A160 @ =0x0000E02E
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820A08E
	b _0820A242
_0820A08E:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820A164 @ =FUN_08209dd0
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A168 @ =FUN_08209f8c
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820A16C @ =FUN_08209dc4
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A170 @ =FUN_08209e0c
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820A174 @ =FUN_08209fac
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A178 @ =FUN_08209fb8
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _0820A160 @ =0x0000E02E
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820A1AC
	cmp r5, #1
	bgt _0820A17C
	cmp r5, #0
	beq _0820A182
	b _0820A242
	.align 2, 0
_0820A15C: .4byte 0xFFFF0000
_0820A160: .4byte 0x0000E02E
_0820A164: .4byte FUN_08209dd0
_0820A168: .4byte FUN_08209f8c
_0820A16C: .4byte FUN_08209dc4
_0820A170: .4byte FUN_08209e0c
_0820A174: .4byte FUN_08209fac
_0820A178: .4byte FUN_08209fb8
_0820A17C:
	cmp r5, #2
	beq _0820A1E4
	b _0820A242
_0820A182:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _0820A1A8 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _0820A240
	.align 2, 0
_0820A1A8: .4byte FUN_080421bc
_0820A1AC:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820A1E0 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _0820A242
	.align 2, 0
_0820A1E0: .4byte FUN_08042178
_0820A1E4:
	ldr r1, _0820A214 @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _0820A218 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820A220
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820A21C @ =FUN_080421bc
	strb r5, [r4, #6]
	b _0820A234
	.align 2, 0
_0820A214: .4byte 0x00000217
_0820A218: .4byte 0x000001EF
_0820A21C: .4byte FUN_080421bc
_0820A220:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820A254 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_0820A234:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_0820A240:
	strb r7, [r4, #0x18]
_0820A242:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820A254: .4byte FUN_08042868

	thumb_func_start FUN_0820a258
FUN_0820a258: @ 0x0820A258
	push {lr}
	ldr r3, _0820A26C @ =0x085AED1C
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_0820A26C: .4byte 0x085AED1C

	thumb_func_start FUN_0820a270
FUN_0820a270: @ 0x0820A270
	push {lr}
	bl FUN_0820a258
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820a27c
FUN_0820a27c: @ 0x0820A27C
	push {lr}
	bl FUN_0820a270
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820a288
FUN_0820a288: @ 0x0820A288
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bhi _0820A2BC
	ldr r1, _0820A2B8 @ =0x085AED5C
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820A2BE
	.align 2, 0
_0820A2B8: .4byte 0x085AED5C
_0820A2BC:
	movs r0, #0
_0820A2BE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820a2c4
FUN_0820a2c4: @ 0x0820A2C4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0820A2EE
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_0820A2EE:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820a2f8
FUN_0820a2f8: @ 0x0820A2F8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _0820A31C @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0820A428
	.align 2, 0
_0820A31C: .4byte 0x03002B4C
_0820A320:
	ldr r0, _0820A350 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r6, [r0]
	mov r0, sb
	adds r1, r6, #0
	bl FUN_08022474
	ldrb r0, [r6, #6]
	cmp r0, #0xa
	bhi _0820A41A
	lsls r0, r0, #2
	ldr r1, _0820A354 @ =_0820A358
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820A350: .4byte 0x03002B4C
_0820A354: .4byte _0820A358
_0820A358: @ jump table
	.4byte _0820A384 @ case 0
	.4byte _0820A390 @ case 1
	.4byte _0820A3EE @ case 2
	.4byte _0820A3A8 @ case 3
	.4byte _0820A41A @ case 4
	.4byte _0820A41A @ case 5
	.4byte _0820A41A @ case 6
	.4byte _0820A41A @ case 7
	.4byte _0820A41A @ case 8
	.4byte _0820A41A @ case 9
	.4byte _0820A408 @ case 10
_0820A384:
	movs r0, #0
	strb r0, [r7, #2]
	strb r0, [r7, #3]
	strb r0, [r7, #4]
	str r0, [r7, #0x14]
	b _0820A402
_0820A390:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #1
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
	strb r0, [r7, #8]
	b _0820A41A
_0820A3A8:
	ldrh r0, [r6, #8]
	adds r3, r7, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r6, #0xa]
	adds r1, r7, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r6, #0xc]
	adds r0, r7, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x64
	movs r6, #0
	ldrsh r0, [r3, r6]
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #0x1b]
	movs r0, #2
	strb r4, [r7, #2]
	strb r4, [r7, #3]
	strb r0, [r7, #4]
	str r5, [r7, #0x14]
	b _0820A402
_0820A3EE:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #3
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
_0820A402:
	movs r0, #1
	strb r0, [r7, #8]
	b _0820A41A
_0820A408:
	movs r0, #8
	ldrsh r1, [r6, r0]
	movs r3, #0xa
	ldrsh r2, [r6, r3]
	movs r0, #0xc
	ldrsh r3, [r6, r0]
	adds r0, r7, #0
	bl FUN_080415cc
_0820A41A:
	movs r1, #1
	add r8, r1
	ldr r0, _0820A440 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_0820A428:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0820A434
	b _0820A320
_0820A434:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820A440: .4byte 0x03002B4C

	thumb_func_start FUN_0820a444
FUN_0820a444: @ 0x0820A444
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_0820a2f8
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820a464
FUN_0820a464: @ 0x0820A464
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820a470
FUN_0820a470: @ 0x0820A470
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_0820a480
FUN_0820a480: @ 0x0820A480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0820A4EC @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820A498
	b _0820A6FA
_0820A498:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #9
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0820A4F8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820A4F0 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820A4F4 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820A502
	.align 2, 0
_0820A4EC: .4byte 0x03002B50
_0820A4F0: .4byte 0xFFFF0000
_0820A4F4: .4byte 0x0000FFFF
_0820A4F8:
	ldr r1, _0820A614 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820A502:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _0820A520
	b _0820A6FA
_0820A520:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820A530
	b _0820A6FA
_0820A530:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _0820A618 @ =0x0000E03E
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820A546
	b _0820A6FA
_0820A546:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820A61C @ =FUN_0820a288
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A620 @ =FUN_0820a444
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820A624 @ =FUN_0820a27c
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A628 @ =FUN_0820a2c4
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820A62C @ =FUN_0820a464
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820A630 @ =FUN_0820a470
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _0820A618 @ =0x0000E03E
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820A664
	cmp r5, #1
	bgt _0820A634
	cmp r5, #0
	beq _0820A63A
	b _0820A6FA
	.align 2, 0
_0820A614: .4byte 0xFFFF0000
_0820A618: .4byte 0x0000E03E
_0820A61C: .4byte FUN_0820a288
_0820A620: .4byte FUN_0820a444
_0820A624: .4byte FUN_0820a27c
_0820A628: .4byte FUN_0820a2c4
_0820A62C: .4byte FUN_0820a464
_0820A630: .4byte FUN_0820a470
_0820A634:
	cmp r5, #2
	beq _0820A69C
	b _0820A6FA
_0820A63A:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _0820A660 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _0820A6F8
	.align 2, 0
_0820A660: .4byte FUN_080421bc
_0820A664:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820A698 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _0820A6FA
	.align 2, 0
_0820A698: .4byte FUN_08042178
_0820A69C:
	ldr r1, _0820A6CC @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _0820A6D0 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820A6D8
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820A6D4 @ =FUN_080421bc
	strb r5, [r4, #6]
	b _0820A6EC
	.align 2, 0
_0820A6CC: .4byte 0x00000217
_0820A6D0: .4byte 0x000001EF
_0820A6D4: .4byte FUN_080421bc
_0820A6D8:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820A70C @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_0820A6EC:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_0820A6F8:
	strb r7, [r4, #0x18]
_0820A6FA:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820A70C: .4byte FUN_08042868

	thumb_func_start FUN_0820a710
FUN_0820a710: @ 0x0820A710
	push {lr}
	ldr r3, _0820A724 @ =0x085AED94
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_0820A724: .4byte 0x085AED94

	thumb_func_start FUN_0820a728
FUN_0820a728: @ 0x0820A728
	push {lr}
	bl FUN_0820a710
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820a734
FUN_0820a734: @ 0x0820A734
	push {lr}
	bl FUN_0820a728
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820a740
FUN_0820a740: @ 0x0820A740
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xd
	bhi _0820A774
	ldr r1, _0820A770 @ =0x085AEDD4
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820A776
	.align 2, 0
_0820A770: .4byte 0x085AEDD4
_0820A774:
	movs r0, #0
_0820A776:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820a77c
FUN_0820a77c: @ 0x0820A77C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0820A7A6
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_0820A7A6:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820a7b0
FUN_0820a7b0: @ 0x0820A7B0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _0820A7D4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r7, r2
	b _0820A8E0
	.align 2, 0
_0820A7D4: .4byte 0x03002B4C
_0820A7D8:
	ldr r0, _0820A808 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r6, [r0]
	mov r0, sb
	adds r1, r6, #0
	bl FUN_08022474
	ldrb r0, [r6, #6]
	cmp r0, #0xa
	bhi _0820A8D2
	lsls r0, r0, #2
	ldr r1, _0820A80C @ =_0820A810
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820A808: .4byte 0x03002B4C
_0820A80C: .4byte _0820A810
_0820A810: @ jump table
	.4byte _0820A83C @ case 0
	.4byte _0820A848 @ case 1
	.4byte _0820A8A6 @ case 2
	.4byte _0820A860 @ case 3
	.4byte _0820A8D2 @ case 4
	.4byte _0820A8D2 @ case 5
	.4byte _0820A8D2 @ case 6
	.4byte _0820A8D2 @ case 7
	.4byte _0820A8D2 @ case 8
	.4byte _0820A8D2 @ case 9
	.4byte _0820A8C0 @ case 10
_0820A83C:
	movs r0, #0
	strb r0, [r7, #2]
	strb r0, [r7, #3]
	strb r0, [r7, #4]
	str r0, [r7, #0x14]
	b _0820A8BA
_0820A848:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #1
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
	strb r0, [r7, #8]
	b _0820A8D2
_0820A860:
	ldrh r0, [r6, #8]
	adds r3, r7, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r6, #0xa]
	adds r1, r7, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r6, #0xc]
	adds r0, r7, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x64
	movs r6, #0
	ldrsh r0, [r3, r6]
	movs r6, #0
	ldrsh r1, [r2, r6]
	subs r0, r0, r1
	movs r6, #4
	ldrsh r1, [r3, r6]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r7, #0x1b]
	movs r0, #2
	strb r4, [r7, #2]
	strb r4, [r7, #3]
	strb r0, [r7, #4]
	str r5, [r7, #0x14]
	b _0820A8BA
_0820A8A6:
	ldrb r0, [r6, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r7, #0x1b]
	movs r0, #3
	strb r1, [r7, #2]
	strb r1, [r7, #3]
	strb r0, [r7, #4]
	str r1, [r7, #0x14]
_0820A8BA:
	movs r0, #1
	strb r0, [r7, #8]
	b _0820A8D2
_0820A8C0:
	movs r0, #8
	ldrsh r1, [r6, r0]
	movs r3, #0xa
	ldrsh r2, [r6, r3]
	movs r0, #0xc
	ldrsh r3, [r6, r0]
	adds r0, r7, #0
	bl FUN_080415cc
_0820A8D2:
	movs r1, #1
	add r8, r1
	ldr r0, _0820A8F8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_0820A8E0:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0820A8EC
	b _0820A7D8
_0820A8EC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820A8F8: .4byte 0x03002B4C

	thumb_func_start FUN_0820a8fc
FUN_0820a8fc: @ 0x0820A8FC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_0820a7b0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820a91c
FUN_0820a91c: @ 0x0820A91C
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820a928
FUN_0820a928: @ 0x0820A928
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_0820a938
FUN_0820a938: @ 0x0820A938
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0820A9A4 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820A950
	b _0820ABB2
_0820A950:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #0xa
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0820A9B0
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820A9A8 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820A9AC @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820A9BA
	.align 2, 0
_0820A9A4: .4byte 0x03002B50
_0820A9A8: .4byte 0xFFFF0000
_0820A9AC: .4byte 0x0000FFFF
_0820A9B0:
	ldr r1, _0820AACC @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820A9BA:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _0820A9D8
	b _0820ABB2
_0820A9D8:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820A9E8
	b _0820ABB2
_0820A9E8:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _0820AAD0 @ =0x0000E04E
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820A9FE
	b _0820ABB2
_0820A9FE:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xaf
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820AAD4 @ =FUN_0820a740
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820AAD8 @ =FUN_0820a8fc
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820AADC @ =FUN_0820a734
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820AAE0 @ =FUN_0820a77c
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820AAE4 @ =FUN_0820a91c
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820AAE8 @ =FUN_0820a928
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _0820AAD0 @ =0x0000E04E
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820AB1C
	cmp r5, #1
	bgt _0820AAEC
	cmp r5, #0
	beq _0820AAF2
	b _0820ABB2
	.align 2, 0
_0820AACC: .4byte 0xFFFF0000
_0820AAD0: .4byte 0x0000E04E
_0820AAD4: .4byte FUN_0820a740
_0820AAD8: .4byte FUN_0820a8fc
_0820AADC: .4byte FUN_0820a734
_0820AAE0: .4byte FUN_0820a77c
_0820AAE4: .4byte FUN_0820a91c
_0820AAE8: .4byte FUN_0820a928
_0820AAEC:
	cmp r5, #2
	beq _0820AB54
	b _0820ABB2
_0820AAF2:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _0820AB18 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _0820ABB0
	.align 2, 0
_0820AB18: .4byte FUN_080421bc
_0820AB1C:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820AB50 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _0820ABB2
	.align 2, 0
_0820AB50: .4byte FUN_08042178
_0820AB54:
	ldr r1, _0820AB84 @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _0820AB88 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820AB90
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820AB8C @ =FUN_080421bc
	strb r5, [r4, #6]
	b _0820ABA4
	.align 2, 0
_0820AB84: .4byte 0x00000217
_0820AB88: .4byte 0x000001EF
_0820AB8C: .4byte FUN_080421bc
_0820AB90:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820ABC4 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_0820ABA4:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_0820ABB0:
	strb r7, [r4, #0x18]
_0820ABB2:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820ABC4: .4byte FUN_08042868

	thumb_func_start FUN_0820abc8
FUN_0820abc8: @ 0x0820ABC8
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820ABE6
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xe
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_0820ABE6:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820abec
FUN_0820abec: @ 0x0820ABEC
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820AC0A
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xf
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_0820AC0A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820ac10
FUN_0820ac10: @ 0x0820AC10
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _0820AC24
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #0x10
	strb r0, [r2, #5]
_0820AC24:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _0820AC40
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_0820AC40:
	pop {r0}
	bx r0

	thumb_func_start FUN_0820ac44
FUN_0820ac44: @ 0x0820AC44
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0820AC58
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0x11
	strb r0, [r4, #5]
_0820AC58:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _0820AC74
	movs r1, #1
	movs r0, #0
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0820AC74:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820ac80
FUN_0820ac80: @ 0x0820AC80
	push {lr}
	ldr r3, _0820AC94 @ =0x085AEE0C
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_0820AC94: .4byte 0x085AEE0C

	thumb_func_start FUN_0820ac98
FUN_0820ac98: @ 0x0820AC98
	push {lr}
	bl FUN_0820ac80
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820aca4
FUN_0820aca4: @ 0x0820ACA4
	push {lr}
	bl FUN_0820ac98
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820acb0
FUN_0820acb0: @ 0x0820ACB0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r6, r1, #0
	movs r0, #0x20
	adds r0, r0, r6
	mov sl, r0
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _0820ACE6
	movs r4, #0
	strb r4, [r6, #9]
	strb r4, [r6, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #5
	movs r2, #1
	movs r3, #1
	bl FUN_08041480
	strh r4, [r6, #0x20]
	mov r1, sl
	strh r4, [r1, #2]
_0820ACE6:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0820ACFE
	b _0820AF8E
_0820ACFE:
	ldrh r4, [r6, #0x20]
	cmp r4, #1
	beq _0820AD46
	cmp r4, #1
	bgt _0820AD0E
	cmp r4, #0
	beq _0820AD18
	b _0820AF8E
_0820AD0E:
	cmp r4, #2
	beq _0820AD6E
	cmp r4, #3
	beq _0820AD96
	b _0820AF8E
_0820AD18:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _0820AD2A
	b _0820AF8E
_0820AD2A:
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #6
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldrh r0, [r6, #0x20]
	adds r0, #1
	strh r0, [r6, #0x20]
	mov r0, sl
	strh r4, [r0, #2]
	b _0820AF8E
_0820AD46:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _0820AD58
	b _0820AF8E
_0820AD58:
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #7
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldrh r0, [r6, #0x20]
	adds r0, #1
	b _0820AF86
_0820AD6E:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0820AD80
	b _0820AF8E
_0820AD80:
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #8
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldrh r0, [r6, #0x20]
	adds r0, #1
	b _0820AF86
_0820AD96:
	mov r0, sl
	ldrh r7, [r0, #2]
	cmp r7, #4
	beq _0820ADA0
	b _0820AF60
_0820ADA0:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	add r0, sp, #0x1c
	ldrh r0, [r0]
	adds r0, #0xb4
	add r1, sp, #0x1c
	strh r0, [r1]
	ldr r4, _0820AFA0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r5, #5
	str r5, [sp, #0xc]
	movs r1, #8
	mov r8, r1
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_080149dc
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, r8
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x40
	bl FUN_080149dc
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, r8
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x80
	bl FUN_080149dc
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	movs r0, #0xa
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, r8
	str r1, [sp, #0x10]
	str r1, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #4
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0xc0
	bl FUN_080149dc
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	movs r1, #0xe
	mov sb, r1
	str r1, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_080149dc
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	mov r1, sb
	str r1, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x40
	bl FUN_080149dc
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	mov r1, sb
	str r1, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0x80
	bl FUN_080149dc
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0820AFA4 @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	ldr r1, _0820AFA8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	str r7, [sp, #0x10]
	mov r1, sb
	str r1, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #2
	movs r1, #0x26
	add r2, sp, #0x1c
	movs r3, #0xc0
	bl FUN_080149dc
	ldr r0, _0820AFAC @ =0x00000395
	bl PlaySound_082406e0
_0820AF60:
	mov r1, sl
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
	adds r0, r6, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _0820AF8E
	movs r0, #4
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #6
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	movs r0, #1
_0820AF86:
	strh r0, [r6, #0x20]
	movs r0, #0
	mov r1, sl
	strh r0, [r1, #2]
_0820AF8E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820AFA0: .4byte 0x030046B8
_0820AFA4: .4byte 0x000003FF
_0820AFA8: .4byte 0x0203B400
_0820AFAC: .4byte 0x00000395

	thumb_func_start FUN_0820afb0
FUN_0820afb0: @ 0x0820AFB0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820AFDA
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #9
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_0820AFDA:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820aff0
FUN_0820aff0: @ 0x0820AFF0
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r1, #0
	adds r7, r2, #0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820B01C
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0xa
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
_0820B01C:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820B03A
	cmp r7, #0xf
	ble _0820B03A
	movs r0, #1
	strb r0, [r5, #7]
_0820B03A:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820b044
FUN_0820b044: @ 0x0820B044
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bhi _0820B078
	ldr r1, _0820B074 @ =0x085AEE5C
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820B07A
	.align 2, 0
_0820B074: .4byte 0x085AEE5C
_0820B078:
	movs r0, #0
_0820B07A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820b080
FUN_0820b080: @ 0x0820B080
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0820B0AA
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_0820B0AA:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820b0b4
FUN_0820b0b4: @ 0x0820B0B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _0820B0D8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _0820B29E
	.align 2, 0
_0820B0D8: .4byte 0x03002B4C
_0820B0DC:
	ldr r0, _0820B110 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x21
	bls _0820B104
	b _0820B290
_0820B104:
	lsls r0, r0, #2
	ldr r1, _0820B114 @ =_0820B118
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820B110: .4byte 0x03002B4C
_0820B114: .4byte _0820B118
_0820B118: @ jump table
	.4byte _0820B1A0 @ case 0
	.4byte _0820B1AA @ case 1
	.4byte _0820B24E @ case 2
	.4byte _0820B208 @ case 3
	.4byte _0820B290 @ case 4
	.4byte _0820B290 @ case 5
	.4byte _0820B290 @ case 6
	.4byte _0820B290 @ case 7
	.4byte _0820B290 @ case 8
	.4byte _0820B290 @ case 9
	.4byte _0820B27E @ case 10
	.4byte _0820B290 @ case 11
	.4byte _0820B290 @ case 12
	.4byte _0820B290 @ case 13
	.4byte _0820B290 @ case 14
	.4byte _0820B290 @ case 15
	.4byte _0820B290 @ case 16
	.4byte _0820B290 @ case 17
	.4byte _0820B290 @ case 18
	.4byte _0820B290 @ case 19
	.4byte _0820B1C2 @ case 20
	.4byte _0820B290 @ case 21
	.4byte _0820B268 @ case 22
	.4byte _0820B290 @ case 23
	.4byte _0820B26C @ case 24
	.4byte _0820B290 @ case 25
	.4byte _0820B290 @ case 26
	.4byte _0820B290 @ case 27
	.4byte _0820B290 @ case 28
	.4byte _0820B290 @ case 29
	.4byte _0820B290 @ case 30
	.4byte _0820B290 @ case 31
	.4byte _0820B290 @ case 32
	.4byte _0820B264 @ case 33
_0820B1A0:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _0820B276
_0820B1AA:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	strb r0, [r6, #8]
	b _0820B290
_0820B1C2:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820B278
_0820B208:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #0x13
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820B278
_0820B24E:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _0820B278
_0820B264:
	movs r1, #0x10
	b _0820B26E
_0820B268:
	movs r1, #0x11
	b _0820B26E
_0820B26C:
	movs r1, #0x12
_0820B26E:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_0820B276:
	str r0, [r6, #0x14]
_0820B278:
	movs r0, #1
	strb r0, [r6, #8]
	b _0820B290
_0820B27E:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
_0820B290:
	movs r1, #1
	add r8, r1
	ldr r0, _0820B2B8 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_0820B29E:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0820B2AA
	b _0820B0DC
_0820B2AA:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820B2B8: .4byte 0x03002B4C

	thumb_func_start FUN_0820b2bc
FUN_0820b2bc: @ 0x0820B2BC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_0820b0b4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820b2dc
FUN_0820b2dc: @ 0x0820B2DC
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820b2e8
FUN_0820b2e8: @ 0x0820B2E8
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_0820b2f8
FUN_0820b2f8: @ 0x0820B2F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0820B364 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820B310
	b _0820B5AE
_0820B310:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x6b
	movs r1, #0xb
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0820B370
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820B368 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820B36C @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820B37A
	.align 2, 0
_0820B364: .4byte 0x03002B50
_0820B368: .4byte 0xFFFF0000
_0820B36C: .4byte 0x0000FFFF
_0820B370:
	ldr r1, _0820B48C @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820B37A:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _0820B398
	b _0820B5AE
_0820B398:
	adds r1, r7, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820B3A8
	b _0820B5AE
_0820B3A8:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _0820B490 @ =0x0000DFCE
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820B3BE
	b _0820B5AE
_0820B3BE:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xe1
	lsls r1, r1, #1
	movs r6, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x20
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #7
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r7, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820B494 @ =FUN_0820b044
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820B498 @ =FUN_0820b2bc
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820B49C @ =FUN_0820aca4
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820B4A0 @ =FUN_0820b080
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820B4A4 @ =FUN_0820b2dc
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820B4A8 @ =FUN_0820b2e8
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _0820B490 @ =0x0000DFCE
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820B4E0
	cmp r5, #1
	bgt _0820B4AC
	cmp r5, #0
	beq _0820B4B6
	b _0820B5AE
	.align 2, 0
_0820B48C: .4byte 0xFFFF0000
_0820B490: .4byte 0x0000DFCE
_0820B494: .4byte FUN_0820b044
_0820B498: .4byte FUN_0820b2bc
_0820B49C: .4byte FUN_0820aca4
_0820B4A0: .4byte FUN_0820b080
_0820B4A4: .4byte FUN_0820b2dc
_0820B4A8: .4byte FUN_0820b2e8
_0820B4AC:
	cmp r5, #2
	beq _0820B518
	cmp r5, #3
	beq _0820B588
	b _0820B5AE
_0820B4B6:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _0820B4DC @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _0820B5AC
	.align 2, 0
_0820B4DC: .4byte FUN_080421bc
_0820B4E0:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820B514 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _0820B5AE
	.align 2, 0
_0820B514: .4byte FUN_08042178
_0820B518:
	ldr r1, _0820B554 @ =0x00000217
	adds r0, r4, r1
	movs r7, #1
	strb r7, [r0]
	ldr r2, _0820B558 @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820B560
	adds r0, r4, #0
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r7, [r4, #8]
	ldr r1, _0820B55C @ =FUN_080421bc
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r7, [r4, #9]
	b _0820B5AC
	.align 2, 0
_0820B554: .4byte 0x00000217
_0820B558: .4byte 0x000001EF
_0820B55C: .4byte FUN_080421bc
_0820B560:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r7, [r4, #8]
	ldr r1, _0820B584 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r7, [r4, #9]
	b _0820B5AC
	.align 2, 0
_0820B584: .4byte FUN_08042868
_0820B588:
	movs r0, #0x11
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _0820B5C0 @ =FUN_0820afb0
	movs r0, #0xf
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r2, [r4, #9]
_0820B5AC:
	strb r6, [r4, #0x18]
_0820B5AE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820B5C0: .4byte FUN_0820afb0

	thumb_func_start FUN_0820b5c4
FUN_0820b5c4: @ 0x0820B5C4
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _0820B5D8
	movs r0, #0
	strb r0, [r2, #8]
	strb r0, [r2, #7]
	movs r0, #5
	strb r0, [r2, #5]
_0820B5D8:
	ldrb r0, [r2, #7]
	cmp r0, #0
	beq _0820B5F4
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #4]
	str r0, [r2, #0x14]
	strb r1, [r2, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r2, r1
	movs r1, #1
	bl FUN_08022488
_0820B5F4:
	pop {r0}
	bx r0

	thumb_func_start FUN_0820b5f8
FUN_0820b5f8: @ 0x0820B5F8
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820B60A
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #6
	strb r0, [r1, #5]
_0820B60A:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _0820B626
	movs r0, #0
	strb r0, [r1, #4]
	str r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #8]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_0820B626:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820b62c
FUN_0820b62c: @ 0x0820B62C
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820B64A
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xe
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_0820B64A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820b650
FUN_0820b650: @ 0x0820B650
	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0820B662
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0xf
	strb r0, [r1, #5]
_0820B662:
	ldrb r0, [r1, #7]
	cmp r0, #0
	beq _0820B674
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl FUN_08022488
_0820B674:
	pop {r0}
	bx r0

	thumb_func_start FUN_0820b678
FUN_0820b678: @ 0x0820B678
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0820B68C
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0x10
	strb r0, [r4, #5]
_0820B68C:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _0820B6AC
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r0, [r4, #4]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
_0820B6AC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820b6b4
FUN_0820b6b4: @ 0x0820B6B4
	push {lr}
	ldr r3, _0820B6C8 @ =0x085AEEA4
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_0820B6C8: .4byte 0x085AEEA4

	thumb_func_start FUN_0820b6cc
FUN_0820b6cc: @ 0x0820B6CC
	push {lr}
	bl FUN_0820b6b4
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820b6d8
FUN_0820b6d8: @ 0x0820B6D8
	push {lr}
	bl FUN_0820b6cc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820b6e4
FUN_0820b6e4: @ 0x0820B6E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r1, #0
	adds r7, r2, #0
	movs r0, #0x5c
	adds r0, r0, r5
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820B72C
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
	mov r2, r8
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	movs r0, #0xca
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0820B72C:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820B7B6
	ldr r0, [r6, #0xc]
	ldr r1, [r6, #0x10]
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	cmp r7, #0x1f
	ble _0820B760
	movs r0, #1
	strb r0, [r5, #7]
	b _0820B7B6
_0820B760:
	movs r1, #3
	bics r1, r7
	movs r0, #0x20
	subs r0, r0, r7
	adds r4, r5, #0
	adds r4, #0x6c
	lsls r5, r1, #6
	lsls r6, r0, #3
	ldr r2, _0820B78C @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0820B790
	asrs r3, r0, #0xc
	b _0820B796
	.align 2, 0
_0820B78C: .4byte 0x085B0A08
_0820B790:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0820B796:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0820B7AE
	asrs r0, r0, #0xc
	b _0820B7B4
_0820B7AE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0820B7B4:
	strh r0, [r4, #4]
_0820B7B6:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820b7c4
FUN_0820b7c4: @ 0x0820B7C4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r1, #0
	adds r7, r2, #0
	movs r0, #0x5c
	adds r0, r0, r5
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820B80C
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
	mov r2, r8
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	movs r0, #0xca
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0820B80C:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820B892
	ldr r0, [r6, #0xc]
	ldr r1, [r6, #0x10]
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	movs r0, #3
	ands r0, r7
	adds r3, r5, #0
	adds r3, #0x6c
	lsls r4, r0, #6
	lsls r6, r7, #3
	ldr r2, _0820B860 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0820B864
	asrs r1, r0, #0xc
	b _0820B86A
	.align 2, 0
_0820B860: .4byte 0x085B0A08
_0820B864:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0820B86A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0820B882
	asrs r0, r0, #0xc
	b _0820B888
_0820B882:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0820B888:
	strh r0, [r3, #4]
	cmp r7, #0x1f
	ble _0820B892
	movs r0, #1
	strb r0, [r5, #7]
_0820B892:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820b8a0
FUN_0820b8a0: @ 0x0820B8A0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r6, r4, #0
	adds r6, #0x5c
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820B8D2
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r5, #4]
	str r1, [r5, #8]
_0820B8D2:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820B91E
	ldr r0, [r5, #4]
	ldr r1, [r5, #8]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	ldr r5, _0820B928 @ =0x0203B400
	ldr r2, _0820B92C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _0820B930 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #0x1f
	ands r1, r3
	subs r1, #0x10
	strh r1, [r6, #0x10]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #0x10
	strh r0, [r6, #0x14]
_0820B91E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0820B928: .4byte 0x0203B400
_0820B92C: .4byte 0x030046B8
_0820B930: .4byte 0x000003FF

	thumb_func_start FUN_0820b934
FUN_0820b934: @ 0x0820B934
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r1, #0
	adds r7, r2, #0
	adds r6, r4, #0
	adds r6, #0x5c
	adds r5, r4, #0
	adds r5, #0x20
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820B968
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #4
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r5, #4]
	str r1, [r5, #8]
_0820B968:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820B9D4
	cmp r7, #0x3f
	ble _0820B990
	movs r0, #1
	strb r0, [r4, #7]
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x10]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	b _0820B9A6
_0820B990:
	adds r0, r4, #0
	adds r0, #0x64
	adds r1, r4, #0
	adds r1, #0x24
	adds r2, r4, #0
	adds r2, #0x2c
	movs r3, #6
	str r3, [sp]
	adds r3, r7, #0
	bl FUN_08237970
_0820B9A6:
	ldr r5, _0820B9DC @ =0x0203B400
	ldr r2, _0820B9E0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _0820B9E4 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	movs r3, #0x1f
	ands r1, r3
	subs r1, #0x10
	strh r1, [r6, #0x10]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r0, r3
	subs r0, #0x10
	strh r0, [r6, #0x14]
_0820B9D4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820B9DC: .4byte 0x0203B400
_0820B9E0: .4byte 0x030046B8
_0820B9E4: .4byte 0x000003FF

	thumb_func_start FUN_0820b9e8
FUN_0820b9e8: @ 0x0820B9E8
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820BA0A
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #5
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
_0820BA0A:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820BA30
	adds r0, r4, #0
	adds r0, #0xd0
	bl FUN_08055d20
	cmp r0, #0
	beq _0820BA30
	movs r0, #1
	strb r0, [r4, #7]
_0820BA30:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820ba38
FUN_0820ba38: @ 0x0820BA38
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x10
	bhi _0820BA6C
	ldr r1, _0820BA68 @ =0x085AEEF0
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820BA6E
	.align 2, 0
_0820BA68: .4byte 0x085AEEF0
_0820BA6C:
	movs r0, #0
_0820BA6E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820ba74
FUN_0820ba74: @ 0x0820BA74
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0820BA9E
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_0820BA9E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820baa8
FUN_0820baa8: @ 0x0820BAA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sl, r0
	movs r1, #0x20
	adds r1, r1, r6
	mov sb, r1
	movs r2, #0
	mov r8, r2
	ldr r0, _0820BAD4 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r3, #0xb5
	lsls r3, r3, #1
	adds r0, r6, r3
	b _0820BC70
	.align 2, 0
_0820BAD4: .4byte 0x03002B4C
_0820BAD8:
	ldr r0, _0820BB0C @ =0x03002B4C
	ldr r0, [r0]
	mov r7, r8
	lsls r1, r7, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sl
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sl
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x20
	bls _0820BB00
	b _0820BC62
_0820BB00:
	lsls r0, r0, #2
	ldr r1, _0820BB10 @ =_0820BB14
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820BB0C: .4byte 0x03002B4C
_0820BB10: .4byte _0820BB14
_0820BB14: @ jump table
	.4byte _0820BB98 @ case 0
	.4byte _0820BBA2 @ case 1
	.4byte _0820BBFE @ case 2
	.4byte _0820BBB8 @ case 3
	.4byte _0820BC28 @ case 4
	.4byte _0820BC2C @ case 5
	.4byte _0820BC62 @ case 6
	.4byte _0820BC62 @ case 7
	.4byte _0820BC62 @ case 8
	.4byte _0820BC62 @ case 9
	.4byte _0820BC14 @ case 10
	.4byte _0820BC62 @ case 11
	.4byte _0820BC62 @ case 12
	.4byte _0820BC62 @ case 13
	.4byte _0820BC62 @ case 14
	.4byte _0820BC62 @ case 15
	.4byte _0820BC62 @ case 16
	.4byte _0820BC62 @ case 17
	.4byte _0820BC62 @ case 18
	.4byte _0820BC62 @ case 19
	.4byte _0820BC62 @ case 20
	.4byte _0820BC62 @ case 21
	.4byte _0820BC62 @ case 22
	.4byte _0820BC62 @ case 23
	.4byte _0820BC62 @ case 24
	.4byte _0820BC62 @ case 25
	.4byte _0820BC62 @ case 26
	.4byte _0820BC62 @ case 27
	.4byte _0820BC62 @ case 28
	.4byte _0820BC62 @ case 29
	.4byte _0820BC30 @ case 30
	.4byte _0820BC34 @ case 31
	.4byte _0820BC52 @ case 32
_0820BB98:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _0820BC5C
_0820BBA2:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _0820BC60
_0820BBB8:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820BC5E
_0820BBFE:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _0820BC5E
_0820BC14:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
	b _0820BC62
_0820BC28:
	movs r1, #4
	b _0820BC54
_0820BC2C:
	movs r1, #5
	b _0820BC54
_0820BC30:
	movs r1, #0x10
	b _0820BC54
_0820BC34:
	ldrh r0, [r7, #8]
	movs r1, #0
	movs r2, #0
	mov r3, sb
	strh r0, [r3, #0xc]
	ldrh r0, [r7, #0xa]
	strh r0, [r3, #0xe]
	ldrh r0, [r7, #0xc]
	strh r0, [r3, #0x10]
	movs r0, #0x11
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r2, [r6, #0x14]
	b _0820BC5E
_0820BC52:
	movs r1, #0x12
_0820BC54:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_0820BC5C:
	str r0, [r6, #0x14]
_0820BC5E:
	movs r0, #1
_0820BC60:
	strb r0, [r6, #8]
_0820BC62:
	movs r7, #1
	add r8, r7
	ldr r0, _0820BC8C @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sl
	adds r0, #6
_0820BC70:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0820BC7C
	b _0820BAD8
_0820BC7C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820BC8C: .4byte 0x03002B4C

	thumb_func_start FUN_0820bc90
FUN_0820bc90: @ 0x0820BC90
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_0820baa8
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820bcb0
FUN_0820bcb0: @ 0x0820BCB0
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820bcbc
FUN_0820bcbc: @ 0x0820BCBC
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_0820bccc
FUN_0820bccc: @ 0x0820BCCC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0820BD38 @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820BCE4
	b _0820BF46
_0820BCE4:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6b
	movs r1, #0xc
	bl Script_GetKeywordValue
	adds r7, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0820BD44
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820BD3C @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820BD40 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820BD4E
	.align 2, 0
_0820BD38: .4byte 0x03002B50
_0820BD3C: .4byte 0xFFFF0000
_0820BD40: .4byte 0x0000FFFF
_0820BD44:
	ldr r1, _0820BE60 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820BD4E:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _0820BD6C
	b _0820BF46
_0820BD6C:
	adds r1, r6, #0
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820BD7C
	b _0820BF46
_0820BD7C:
	mov r1, r8
	str r1, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, _0820BE64 @ =0x0000E349
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820BD92
	b _0820BF46
_0820BD92:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r7, #0
	mov r2, r8
	strh r2, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r2, [r0, #0x34]
	movs r3, #0xae
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r1, [r0]
	movs r0, #0x20
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #7
	bl FUN_08040fc0
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r6, #0
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sl, r3
	mov r3, sl
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820BE68 @ =FUN_0820ba38
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820BE6C @ =FUN_0820bc90
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820BE70 @ =FUN_0820b6d8
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820BE74 @ =FUN_0820ba74
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820BE78 @ =FUN_0820bcb0
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820BE7C @ =FUN_0820bcbc
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	ldr r2, _0820BE64 @ =0x0000E349
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820BEB0
	cmp r5, #1
	bgt _0820BE80
	cmp r5, #0
	beq _0820BE86
	b _0820BF46
	.align 2, 0
_0820BE60: .4byte 0xFFFF0000
_0820BE64: .4byte 0x0000E349
_0820BE68: .4byte FUN_0820ba38
_0820BE6C: .4byte FUN_0820bc90
_0820BE70: .4byte FUN_0820b6d8
_0820BE74: .4byte FUN_0820ba74
_0820BE78: .4byte FUN_0820bcb0
_0820BE7C: .4byte FUN_0820bcbc
_0820BE80:
	cmp r5, #2
	beq _0820BEE8
	b _0820BF46
_0820BE86:
	movs r1, #1
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r1, [r4, #4]
	mov r0, r8
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _0820BEAC @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	mov r0, r8
	str r0, [r4, #0x10]
	strb r1, [r4, #9]
	b _0820BF44
	.align 2, 0
_0820BEAC: .4byte FUN_080421bc
_0820BEB0:
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r7, [r4, #4]
	mov r1, r8
	str r1, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820BEE4 @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	mov r3, r8
	str r3, [r4, #0x10]
	strb r5, [r4, #9]
	strb r7, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _0820BF46
	.align 2, 0
_0820BEE4: .4byte FUN_08042178
_0820BEE8:
	ldr r1, _0820BF18 @ =0x00000217
	adds r0, r4, r1
	movs r6, #1
	strb r6, [r0]
	ldr r2, _0820BF1C @ =0x000001EF
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820BF24
	adds r0, r4, #0
	bl FUN_08043510
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820BF20 @ =FUN_080421bc
	strb r5, [r4, #6]
	b _0820BF38
	.align 2, 0
_0820BF18: .4byte 0x00000217
_0820BF1C: .4byte 0x000001EF
_0820BF20: .4byte FUN_080421bc
_0820BF24:
	movs r0, #6
	strb r7, [r4, #2]
	strb r7, [r4, #3]
	strb r0, [r4, #4]
	mov r3, r8
	str r3, [r4, #0x14]
	strb r6, [r4, #8]
	ldr r1, _0820BF58 @ =FUN_08042868
	mov r0, sl
	strb r0, [r4, #6]
_0820BF38:
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	strb r6, [r4, #9]
_0820BF44:
	strb r7, [r4, #0x18]
_0820BF46:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820BF58: .4byte FUN_08042868

	thumb_func_start FUN_0820bf5c
FUN_0820bf5c: @ 0x0820BF5C
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0820BF7C
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xe
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0820BF7C:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820bf88
FUN_0820bf88: @ 0x0820BF88
	push {lr}
	ldr r3, _0820BF9C @ =0x085AEF34
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_0820BF9C: .4byte 0x085AEF34

	thumb_func_start FUN_0820bfa0
FUN_0820bfa0: @ 0x0820BFA0
	push {lr}
	bl FUN_0820bf88
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820bfac
FUN_0820bfac: @ 0x0820BFAC
	push {lr}
	bl FUN_0820bfa0
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820bfb8
FUN_0820bfb8: @ 0x0820BFB8
	push {r4, lr}
	sub sp, #4
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820BFDA
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08041480
_0820BFDA:
	ldr r0, _0820C010 @ =0x03002CF0
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0820BFF0
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_0820BFF0:
	movs r0, #0x80
	lsls r0, r0, #5
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0820C010: .4byte 0x03002CF0

	thumb_func_start FUN_0820c014
FUN_0820c014: @ 0x0820C014
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0xd0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08055ef8
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x40
	movs r3, #0
	bl FUN_08055f80
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820c034
FUN_0820c034: @ 0x0820C034
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0xd0
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08055f1c
	adds r0, r4, #0
	movs r1, #0x40
	movs r2, #0x40
	movs r3, #0
	bl FUN_08055f80
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820c054
FUN_0820c054: @ 0x0820C054
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0820C07C
	movs r0, #0
	strb r0, [r4, #9]
	strb r0, [r4, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08041480
	adds r0, r4, #0
	bl FUN_0820c014
_0820C07C:
	ldr r0, _0820C0AC @ =0x03002CF0
	ldr r0, [r0]
	movs r3, #1
	ands r0, r3
	cmp r0, #0
	beq _0820C092
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r4, #0xe]
	orrs r0, r1
	strh r0, [r4, #0xe]
_0820C092:
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #1
	bls _0820C0B4
	subs r0, #1
	strb r0, [r1]
	ldr r2, _0820C0B0 @ =0x00000131
	adds r1, r4, r2
	strb r0, [r1]
	b _0820C0C8
	.align 2, 0
_0820C0AC: .4byte 0x03002CF0
_0820C0B0: .4byte 0x00000131
_0820C0B4:
	ldr r0, _0820C0F0 @ =FUN_08042178
	movs r2, #0
	strb r3, [r4, #6]
	movs r5, #0xb3
	lsls r5, r5, #2
	adds r1, r4, r5
	str r0, [r1]
	str r2, [r4, #0x10]
	strb r3, [r4, #9]
	strb r2, [r4, #0x18]
_0820C0C8:
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _0820C0F4
	adds r0, r4, #0
	bl FUN_0820c034
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	b _0820C19C
	.align 2, 0
_0820C0F0: .4byte FUN_08042178
_0820C0F4:
	add r6, sp, #4
	adds r2, r4, #0
	adds r2, #0x54
	adds r3, r4, #0
	adds r3, #0x64
	ldrh r0, [r2]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r1, r6, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r6, #0
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r5, #2
	ldrsh r0, [r6, r5]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r5, #4
	ldrsh r0, [r6, r5]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r5, #0x82
	lsls r5, r5, #2
	adds r0, r4, r5
	ldr r0, [r0]
	cmp r1, r0
	bhi _0820C150
	ldr r0, [r4, #0x54]
	ldr r1, [r4, #0x58]
	str r0, [r4, #0x64]
	str r1, [r4, #0x68]
	b _0820C19C
_0820C150:
	movs r2, #0x81
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r7, [r0]
	adds r0, r1, #0
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _0820C194
	add r0, sp, #4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	add r1, sp, #4
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r6, r2]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r6, #2]
	movs r1, #4
	ldrsh r0, [r6, r1]
	muls r0, r7, r0
	adds r1, r5, #0
	bl Div
	strh r0, [r6, #4]
_0820C194:
	ldr r0, [sp, #4]
	ldr r1, [sp, #8]
	str r0, [r4, #0x6c]
	str r1, [r4, #0x70]
_0820C19C:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820c1a4
FUN_0820c1a4: @ 0x0820C1A4
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _0820C1D8
	ldr r1, _0820C1D4 @ =0x085AEF78
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820C1DA
	.align 2, 0
_0820C1D4: .4byte 0x085AEF78
_0820C1D8:
	movs r0, #0
_0820C1DA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820c1e0
FUN_0820c1e0: @ 0x0820C1E0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0820C20A
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_0820C20A:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820c214
FUN_0820c214: @ 0x0820C214
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r7, r4, r0
	movs r6, #0
	ldr r0, _0820C230 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r4, r2
	b _0820C38E
	.align 2, 0
_0820C230: .4byte 0x03002B4C
_0820C234:
	ldr r0, _0820C264 @ =0x03002B4C
	ldr r0, [r0]
	lsls r1, r6, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	adds r0, r7, #0
	adds r0, #8
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08022474
	ldrb r0, [r5, #6]
	cmp r0, #0x28
	bls _0820C25A
	b _0820C384
_0820C25A:
	lsls r0, r0, #2
	ldr r1, _0820C268 @ =_0820C26C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820C264: .4byte 0x03002B4C
_0820C268: .4byte _0820C26C
_0820C26C: @ jump table
	.4byte _0820C310 @ case 0
	.4byte _0820C31A @ case 1
	.4byte _0820C384 @ case 2
	.4byte _0820C384 @ case 3
	.4byte _0820C35C @ case 4
	.4byte _0820C360 @ case 5
	.4byte _0820C384 @ case 6
	.4byte _0820C384 @ case 7
	.4byte _0820C384 @ case 8
	.4byte _0820C384 @ case 9
	.4byte _0820C372 @ case 10
	.4byte _0820C384 @ case 11
	.4byte _0820C384 @ case 12
	.4byte _0820C384 @ case 13
	.4byte _0820C384 @ case 14
	.4byte _0820C384 @ case 15
	.4byte _0820C384 @ case 16
	.4byte _0820C384 @ case 17
	.4byte _0820C384 @ case 18
	.4byte _0820C384 @ case 19
	.4byte _0820C384 @ case 20
	.4byte _0820C384 @ case 21
	.4byte _0820C384 @ case 22
	.4byte _0820C384 @ case 23
	.4byte _0820C384 @ case 24
	.4byte _0820C384 @ case 25
	.4byte _0820C384 @ case 26
	.4byte _0820C384 @ case 27
	.4byte _0820C384 @ case 28
	.4byte _0820C384 @ case 29
	.4byte _0820C384 @ case 30
	.4byte _0820C384 @ case 31
	.4byte _0820C384 @ case 32
	.4byte _0820C384 @ case 33
	.4byte _0820C384 @ case 34
	.4byte _0820C384 @ case 35
	.4byte _0820C384 @ case 36
	.4byte _0820C384 @ case 37
	.4byte _0820C384 @ case 38
	.4byte _0820C384 @ case 39
	.4byte _0820C332 @ case 40
_0820C310:
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r0, [r4, #4]
	b _0820C36A
_0820C31A:
	ldrb r0, [r5, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r4, #0x1b]
	movs r0, #1
	strb r1, [r4, #2]
	strb r1, [r4, #3]
	strb r0, [r4, #4]
	str r1, [r4, #0x14]
	strb r0, [r4, #8]
	b _0820C384
_0820C332:
	movs r1, #0x10
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	ldrh r1, [r5, #8]
	adds r0, r4, #0
	adds r0, #0x54
	strh r1, [r0]
	ldrh r0, [r5, #0xa]
	adds r1, r4, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r5, #0xc]
	adds r0, r4, #0
	adds r0, #0x58
	strh r1, [r0]
	b _0820C384
_0820C35C:
	movs r1, #4
	b _0820C362
_0820C360:
	movs r1, #5
_0820C362:
	movs r0, #0
	strb r0, [r4, #2]
	strb r0, [r4, #3]
	strb r1, [r4, #4]
_0820C36A:
	str r0, [r4, #0x14]
	movs r0, #1
	strb r0, [r4, #8]
	b _0820C384
_0820C372:
	movs r0, #8
	ldrsh r1, [r5, r0]
	movs r0, #0xa
	ldrsh r2, [r5, r0]
	movs r0, #0xc
	ldrsh r3, [r5, r0]
	adds r0, r4, #0
	bl FUN_080415cc
_0820C384:
	adds r6, #1
	ldr r0, _0820C3A0 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	adds r0, r7, #6
_0820C38E:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r6, r0
	bge _0820C39A
	b _0820C234
_0820C39A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820C3A0: .4byte 0x03002B4C

	thumb_func_start FUN_0820c3a4
FUN_0820c3a4: @ 0x0820C3A4
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_0820c214
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820c3c4
FUN_0820c3c4: @ 0x0820C3C4
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820c3d0
FUN_0820c3d0: @ 0x0820C3D0
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_0820c3e0
FUN_0820c3e0: @ 0x0820C3E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r0, _0820C44C @ =0x03002B50
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	bne _0820C3F8
	b _0820C642
_0820C3F8:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov r8, r0
	movs r0, #0x6b
	movs r1, #0xf
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0820C458
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820C450 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820C454 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820C462
	.align 2, 0
_0820C44C: .4byte 0x03002B50
_0820C450: .4byte 0xFFFF0000
_0820C454: .4byte 0x0000FFFF
_0820C458:
	ldr r1, _0820C570 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820C462:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	ldr r0, _0820C574 @ =0x0000AF82
	mov sl, r0
	movs r7, #0
	mov r0, r8
	adds r1, r6, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _0820C482
	b _0820C642
_0820C482:
	mov r1, r8
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820C492
	b _0820C642
_0820C492:
	str r7, [sp]
	adds r0, r4, #0
	movs r1, #2
	mov r2, sl
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820C4A6
	b _0820C642
_0820C4A6:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r6, #0
	strh r7, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r7, [r0, #0x34]
	subs r1, #0x34
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	mov r1, r8
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov r8, r3
	mov r3, r8
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820C578 @ =FUN_0820c1a4
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820C57C @ =FUN_0820c3a4
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820C580 @ =FUN_0820bfac
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820C584 @ =FUN_0820c1e0
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820C588 @ =FUN_0820c3c4
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820C58C @ =FUN_0820c3d0
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sb
	adds r1, r4, #0
	mov r2, sl
	movs r3, #0
	bl FUN_08040df4
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sb
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820C5BC
	cmp r5, #1
	bgt _0820C590
	cmp r5, #0
	beq _0820C596
	b _0820C642
	.align 2, 0
_0820C570: .4byte 0xFFFF0000
_0820C574: .4byte 0x0000AF82
_0820C578: .4byte FUN_0820c1a4
_0820C57C: .4byte FUN_0820c3a4
_0820C580: .4byte FUN_0820bfac
_0820C584: .4byte FUN_0820c1e0
_0820C588: .4byte FUN_0820c3c4
_0820C58C: .4byte FUN_0820c3d0
_0820C590:
	cmp r5, #2
	beq _0820C5F0
	b _0820C642
_0820C596:
	movs r1, #1
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r1, [r4, #4]
	str r7, [r4, #0x14]
	strb r1, [r4, #8]
	ldr r2, _0820C5B8 @ =FUN_080421bc
	movs r0, #2
	strb r0, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r2, [r0]
	str r7, [r4, #0x10]
	strb r1, [r4, #9]
	b _0820C640
	.align 2, 0
_0820C5B8: .4byte FUN_080421bc
_0820C5BC:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r7, [r4, #0x14]
	strb r5, [r4, #8]
	ldr r0, _0820C5EC @ =FUN_08042178
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	str r7, [r4, #0x10]
	strb r5, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _0820C642
	.align 2, 0
_0820C5EC: .4byte FUN_08042178
_0820C5F0:
	ldr r3, _0820C618 @ =0x000001EF
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820C620
	adds r0, r4, #0
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _0820C61C @ =FUN_080421bc
	strb r5, [r4, #6]
	b _0820C634
	.align 2, 0
_0820C618: .4byte 0x000001EF
_0820C61C: .4byte FUN_080421bc
_0820C620:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	movs r2, #1
	strb r2, [r4, #8]
	ldr r1, _0820C654 @ =FUN_08042868
	mov r0, r8
	strb r0, [r4, #6]
_0820C634:
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	str r7, [r4, #0x10]
	strb r2, [r4, #9]
_0820C640:
	strb r6, [r4, #0x18]
_0820C642:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820C654: .4byte FUN_08042868

	thumb_func_start FUN_0820c658
FUN_0820c658: @ 0x0820C658
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #5]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xe
	bhi _0820C68C
	ldr r1, _0820C688 @ =0x085AEFB4
	ldrb r2, [r4, #5]
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r3, #0
	strb r2, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r3, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #9]
	strb r3, [r4, #0x18]
	b _0820C68E
	.align 2, 0
_0820C688: .4byte 0x085AEFB4
_0820C68C:
	movs r0, #0
_0820C68E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820c694
FUN_0820c694: @ 0x0820C694
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	movs r1, #0
	movs r0, #0
	strh r0, [r3, #0xe]
	strb r1, [r3, #7]
	ldr r0, [r3, #0x10]
	adds r2, r0, #0
	adds r0, #1
	str r0, [r3, #0x10]
	movs r1, #0xb3
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r4, [r0]
	cmp r4, #0
	beq _0820C6BE
	adds r0, r5, #0
	adds r1, r3, #0
	bl _call_via_r4
_0820C6BE:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820c6c8
FUN_0820c6c8: @ 0x0820C6C8
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _0820C6DC
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #0xe
	strb r0, [r4, #5]
_0820C6DC:
	ldrb r0, [r4, #7]
	cmp r0, #0
	beq _0820C6F8
	movs r1, #1
	movs r0, #0
	strb r1, [r4, #4]
	str r0, [r4, #0x14]
	strb r1, [r4, #8]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl FUN_08022488
_0820C6F8:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820c704
FUN_0820c704: @ 0x0820C704
	push {lr}
	ldr r3, _0820C718 @ =0x085AEFF0
	ldrb r2, [r1, #4]
	lsls r2, r2, #2
	adds r2, r2, r3
	ldr r2, [r2]
	bl _call_via_r2
	pop {r0}
	bx r0
	.align 2, 0
_0820C718: .4byte 0x085AEFF0

	thumb_func_start FUN_0820c71c
FUN_0820c71c: @ 0x0820C71C
	push {lr}
	bl FUN_0820c704
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820c728
FUN_0820c728: @ 0x0820C728
	push {lr}
	bl FUN_0820c71c
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820c734
FUN_0820c734: @ 0x0820C734
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r0, _0820C758 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	movs r2, #0xb5
	lsls r2, r2, #1
	adds r0, r6, r2
	b _0820C8E6
	.align 2, 0
_0820C758: .4byte 0x03002B4C
_0820C75C:
	ldr r0, _0820C790 @ =0x03002B4C
	ldr r0, [r0]
	mov r3, r8
	lsls r1, r3, #2
	adds r0, #0x24
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r1, r1, r0
	mov r0, sb
	adds r0, #8
	adds r0, r0, r1
	ldr r7, [r0]
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08022474
	ldrb r0, [r7, #6]
	cmp r0, #0x14
	bls _0820C784
	b _0820C8D8
_0820C784:
	lsls r0, r0, #2
	ldr r1, _0820C794 @ =_0820C798
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820C790: .4byte 0x03002B4C
_0820C794: .4byte _0820C798
_0820C798: @ jump table
	.4byte _0820C7EC @ case 0
	.4byte _0820C7F6 @ case 1
	.4byte _0820C89A @ case 2
	.4byte _0820C80E @ case 3
	.4byte _0820C8B0 @ case 4
	.4byte _0820C8B4 @ case 5
	.4byte _0820C8D8 @ case 6
	.4byte _0820C8D8 @ case 7
	.4byte _0820C8D8 @ case 8
	.4byte _0820C8D8 @ case 9
	.4byte _0820C8C6 @ case 10
	.4byte _0820C8D8 @ case 11
	.4byte _0820C8D8 @ case 12
	.4byte _0820C8D8 @ case 13
	.4byte _0820C8D8 @ case 14
	.4byte _0820C8D8 @ case 15
	.4byte _0820C8D8 @ case 16
	.4byte _0820C8D8 @ case 17
	.4byte _0820C8D8 @ case 18
	.4byte _0820C8D8 @ case 19
	.4byte _0820C854 @ case 20
_0820C7EC:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r0, [r6, #4]
	b _0820C8BE
_0820C7F6:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	strb r0, [r6, #8]
	b _0820C8D8
_0820C80E:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #0x10
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820C8C0
_0820C854:
	ldrh r0, [r7, #8]
	adds r3, r6, #0
	adds r3, #0x54
	movs r4, #0
	movs r5, #0
	strh r0, [r3]
	ldrh r0, [r7, #0xa]
	adds r1, r6, #0
	adds r1, #0x56
	strh r0, [r1]
	ldrh r1, [r7, #0xc]
	adds r0, r6, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0x64
	movs r7, #0
	ldrsh r0, [r3, r7]
	movs r7, #0
	ldrsh r1, [r2, r7]
	subs r0, r0, r1
	movs r7, #4
	ldrsh r1, [r3, r7]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r6, #0x1b]
	movs r0, #2
	strb r4, [r6, #2]
	strb r4, [r6, #3]
	strb r0, [r6, #4]
	str r5, [r6, #0x14]
	b _0820C8C0
_0820C89A:
	ldrb r0, [r7, #8]
	adds r0, #5
	lsls r0, r0, #5
	movs r1, #0
	strb r0, [r6, #0x1b]
	movs r0, #3
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	strb r0, [r6, #4]
	str r1, [r6, #0x14]
	b _0820C8C0
_0820C8B0:
	movs r1, #4
	b _0820C8B6
_0820C8B4:
	movs r1, #5
_0820C8B6:
	movs r0, #0
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r1, [r6, #4]
_0820C8BE:
	str r0, [r6, #0x14]
_0820C8C0:
	movs r0, #1
	strb r0, [r6, #8]
	b _0820C8D8
_0820C8C6:
	movs r0, #8
	ldrsh r1, [r7, r0]
	movs r3, #0xa
	ldrsh r2, [r7, r3]
	movs r0, #0xc
	ldrsh r3, [r7, r0]
	adds r0, r6, #0
	bl FUN_080415cc
_0820C8D8:
	movs r1, #1
	add r8, r1
	ldr r0, _0820C900 @ =0x03002B4C
	ldr r1, [r0]
	adds r1, #0x24
	mov r0, sb
	adds r0, #6
_0820C8E6:
	ldrb r1, [r1]
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r8, r0
	bge _0820C8F2
	b _0820C75C
_0820C8F2:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820C900: .4byte 0x03002B4C

	thumb_func_start FUN_0820c904
FUN_0820c904: @ 0x0820C904
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_0820c734
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080411d8
	movs r0, #0
	strb r0, [r4, #5]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820c924
FUN_0820c924: @ 0x0820C924
	push {lr}
	bl FUN_080412fc
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_0820c930
FUN_0820c930: @ 0x0820C930
	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl FUN_08022428
	pop {r1}
	bx r1

	thumb_func_start FUN_0820c940
FUN_0820c940: @ 0x0820C940
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	ldr r0, _0820C9AC @ =0x03002B50
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _0820C958
	b _0820CBC8
_0820C958:
	movs r0, #0x6e
	movs r1, #0
	bl Script_GetKeywordValue
	mov sb, r0
	movs r0, #0x6b
	movs r1, #0xe
	bl Script_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _0820C9B8
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0820C9B0 @ =0xFFFF0000
	ldr r1, [sp, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0820C9B4 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	b _0820C9C2
	.align 2, 0
_0820C9AC: .4byte 0x03002B50
_0820C9B0: .4byte 0xFFFF0000
_0820C9B4: .4byte 0x0000FFFF
_0820C9B8:
	ldr r1, _0820CAD8 @ =0xFFFF0000
	str r0, [sp, #4]
	ldr r0, [sp, #8]
	ands r0, r1
	str r0, [sp, #8]
_0820C9C2:
	movs r0, #0x64
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	ldr r1, _0820CADC @ =0x0000DFCE
	movs r0, #0x63
	bl Script_GetKeywordValue
	str r0, [sp, #0xc]
	movs r7, #0
	movs r0, #1
	mov r8, r0
	mov r0, sb
	adds r1, r6, #0
	bl FUN_08040ed8
	adds r4, r0, #0
	cmp r4, #0
	bne _0820C9EC
	b _0820CBC8
_0820C9EC:
	mov r1, sb
	add r2, sp, #4
	adds r3, r5, #0
	bl FUN_08040f0c
	cmp r0, #0
	bge _0820C9FC
	b _0820CBC8
_0820C9FC:
	str r7, [sp]
	adds r0, r4, #0
	movs r1, #2
	ldr r2, [sp, #0xc]
	movs r3, #0
	bl FUN_08040f48
	cmp r0, #0
	bge _0820CA10
	b _0820CBC8
_0820CA10:
	adds r0, r4, #0
	adds r0, #0x5c
	movs r1, #0xc8
	lsls r1, r1, #1
	movs r6, #0
	strh r7, [r0, #0x30]
	strh r1, [r0, #0x32]
	strh r7, [r0, #0x34]
	subs r1, #0x34
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0x40
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08040fc0
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r4, r2
	mov r1, sb
	movs r2, #5
	bl FUN_080223f4
	adds r0, r4, #0
	adds r0, #0x61
	strb r5, [r0]
	lsls r1, r5, #0x10
	lsrs r1, r1, #0x10
	adds r0, r1, #0
	adds r0, #0x10
	movs r2, #0xff
	ands r0, r2
	asrs r0, r0, #5
	adds r0, #3
	movs r3, #7
	mov sb, r3
	mov r3, sb
	ands r0, r3
	strb r0, [r4, #0x1a]
	adds r1, #0x20
	ands r1, r2
	asrs r1, r1, #6
	adds r1, #1
	movs r0, #3
	ands r0, r1
	strb r0, [r4, #0x19]
	ldr r1, _0820CAE0 @ =FUN_0820c658
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820CAE4 @ =FUN_0820c904
	movs r3, #0xb4
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820CAE8 @ =FUN_0820c728
	subs r2, #0x10
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820CAEC @ =FUN_0820c694
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	ldr r1, _0820CAF0 @ =FUN_0820c924
	adds r2, #8
	adds r0, r4, r2
	str r1, [r0]
	ldr r1, _0820CAF4 @ =FUN_0820c930
	adds r3, #8
	adds r0, r4, r3
	str r1, [r0]
	mov r0, sl
	adds r1, r4, #0
	ldr r2, [sp, #0xc]
	movs r3, #1
	bl FUN_08040df4
	mov r0, sl
	adds r1, r4, #0
	bl FUN_08040e34
	mov r0, sl
	adds r1, r4, #0
	bl FUN_08041e10
	movs r0, #0x69
	movs r1, #0
	bl Script_GetKeywordValue
	adds r5, r0, #0
	cmp r5, #1
	beq _0820CB24
	cmp r5, #1
	bgt _0820CAF8
	cmp r5, #0
	beq _0820CAFE
	b _0820CBC8
	.align 2, 0
_0820CAD8: .4byte 0xFFFF0000
_0820CADC: .4byte 0x0000DFCE
_0820CAE0: .4byte FUN_0820c658
_0820CAE4: .4byte FUN_0820c904
_0820CAE8: .4byte FUN_0820c728
_0820CAEC: .4byte FUN_0820c694
_0820CAF0: .4byte FUN_0820c924
_0820CAF4: .4byte FUN_0820c930
_0820CAF8:
	cmp r5, #2
	beq _0820CB5C
	b _0820CBC8
_0820CAFE:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	mov r0, r8
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	strb r0, [r4, #8]
	ldr r0, _0820CB20 @ =FUN_080421bc
	movs r1, #2
	strb r1, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	str r7, [r4, #0x10]
	mov r3, r8
	strb r3, [r4, #9]
	b _0820CBC6
	.align 2, 0
_0820CB20: .4byte FUN_080421bc
_0820CB24:
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r6, [r4, #4]
	str r7, [r4, #0x14]
	mov r0, r8
	strb r0, [r4, #8]
	ldr r0, _0820CB58 @ =FUN_08042178
	mov r1, r8
	strb r1, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	str r7, [r4, #0x10]
	mov r3, r8
	strb r3, [r4, #9]
	strb r6, [r4, #0x18]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #1
	bl FUN_08055ef8
	adds r0, r4, #0
	bl FUN_0804106c
	b _0820CBC8
	.align 2, 0
_0820CB58: .4byte FUN_08042178
_0820CB5C:
	ldr r1, _0820CB98 @ =0x00000217
	adds r0, r4, r1
	mov r2, r8
	strb r2, [r0]
	ldr r3, _0820CB9C @ =0x000001EF
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0820CBA4
	adds r0, r4, #0
	bl FUN_08043510
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	mov r0, r8
	strb r0, [r4, #8]
	ldr r1, _0820CBA0 @ =FUN_080421bc
	strb r5, [r4, #6]
	movs r2, #0xb3
	lsls r2, r2, #2
	adds r0, r4, r2
	str r1, [r0]
	str r7, [r4, #0x10]
	mov r3, r8
	strb r3, [r4, #9]
	b _0820CBC6
	.align 2, 0
_0820CB98: .4byte 0x00000217
_0820CB9C: .4byte 0x000001EF
_0820CBA0: .4byte FUN_080421bc
_0820CBA4:
	movs r0, #6
	strb r6, [r4, #2]
	strb r6, [r4, #3]
	strb r0, [r4, #4]
	str r7, [r4, #0x14]
	mov r0, r8
	strb r0, [r4, #8]
	ldr r1, _0820CBD8 @ =FUN_08042868
	mov r2, sb
	strb r2, [r4, #6]
	movs r3, #0xb3
	lsls r3, r3, #2
	adds r0, r4, r3
	str r1, [r0]
	str r7, [r4, #0x10]
	mov r0, r8
	strb r0, [r4, #9]
_0820CBC6:
	strb r6, [r4, #0x18]
_0820CBC8:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820CBD8: .4byte FUN_08042868

	thumb_func_start FUN_0820cbdc
FUN_0820cbdc: @ 0x0820CBDC
	ldr r1, _0820CBE8 @ =0x085AF034
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0820CBE8: .4byte 0x085AF034

	thumb_func_start FUN_0820cbec
FUN_0820cbec: @ 0x0820CBEC
	ldr r1, _0820CBF8 @ =0x085AF058
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0820CBF8: .4byte 0x085AF058

	thumb_func_start FUN_0820cbfc
FUN_0820cbfc: @ 0x0820CBFC
	ldr r1, _0820CC08 @ =0x085AF07C
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	bx lr
	.align 2, 0
_0820CC08: .4byte 0x085AF07C

	thumb_func_start FUN_0820cc0c
FUN_0820cc0c: @ 0x0820CC0C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	movs r4, #0
	cmp r6, r5
	bge _0820CC26
_0820CC18:
	adds r0, r4, #0
	bl FUN_0820cbfc
	adds r6, r6, r0
	adds r4, #1
	cmp r4, r5
	blt _0820CC18
_0820CC26:
	adds r0, r6, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0820cc30
FUN_0820cc30: @ 0x0820CC30
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r5, #0
	movs r0, #0x26
	add r0, r8
	mov sb, r0
	mov r7, sb
	mov r6, r8
	adds r6, #0x25
_0820CC48:
	ldrb r4, [r7]
	adds r0, r5, #0
	bl FUN_0820cbdc
	cmp r4, r0
	bge _0820CC62
	subs r0, r5, #1
	strb r0, [r6]
	ldrb r0, [r6]
	bl FUN_0820cbdc
	ldrb r1, [r7]
	b _0820CC78
_0820CC62:
	adds r5, #1
	cmp r5, #8
	ble _0820CC48
	mov r1, r8
	adds r1, #0x25
	movs r0, #8
	strb r0, [r1]
	bl FUN_0820cbdc
	mov r2, sb
	ldrb r1, [r2]
_0820CC78:
	subs r1, r1, r0
	mov r0, r8
	adds r0, #0x48
	strb r1, [r0]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0820cc8c
FUN_0820cc8c: @ 0x0820CC8C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #3
	bl FUN_0820cbdc
	cmp r4, r0
	bge _0820CC9E
	movs r0, #0
	b _0820CCCA
_0820CC9E:
	movs r0, #4
	bl FUN_0820cbdc
	cmp r4, r0
	bge _0820CCAC
	movs r0, #1
	b _0820CCCA
_0820CCAC:
	movs r0, #6
	bl FUN_0820cbdc
	cmp r4, r0
	bge _0820CCBA
	movs r0, #2
	b _0820CCCA
_0820CCBA:
	movs r0, #8
	bl FUN_0820cbdc
	cmp r4, r0
	blt _0820CCC8
	movs r0, #4
	b _0820CCCA
_0820CCC8:
	movs r0, #3
_0820CCCA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0820ccd0
FUN_0820ccd0: @ 0x0820CCD0
	push {lr}
	adds r2, r1, #0
	cmp r0, #0x1f
	bls _0820CCDA
	b _0820CF3C
_0820CCDA:
	lsls r0, r0, #2
	ldr r1, _0820CCE4 @ =_0820CCE8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0820CCE4: .4byte _0820CCE8
_0820CCE8: @ jump table
	.4byte _0820CF3C @ case 0
	.4byte _0820CD68 @ case 1
	.4byte _0820CD88 @ case 2
	.4byte _0820CDA4 @ case 3
	.4byte _0820CDC4 @ case 4
	.4byte _0820CDE4 @ case 5
	.4byte _0820CDF6 @ case 6
	.4byte _0820CDFA @ case 7
	.4byte _0820CDFE @ case 8
	.4byte _0820CE10 @ case 9
	.4byte _0820CE14 @ case 10
	.4byte _0820CE26 @ case 11
	.4byte _0820CE2A @ case 12
	.4byte _0820CE3C @ case 13
	.4byte _0820CE4E @ case 14
	.4byte _0820CF3C @ case 15
	.4byte _0820CF3C @ case 16
	.4byte _0820CE52 @ case 17
	.4byte _0820CE72 @ case 18
	.4byte _0820CE8E @ case 19
	.4byte _0820CEAA @ case 20
	.4byte _0820CECA @ case 21
	.4byte _0820CEF2 @ case 22
	.4byte _0820CF1A @ case 23
	.4byte _0820CF2C @ case 24
	.4byte _0820CF30 @ case 25
	.4byte _0820CF34 @ case 26
	.4byte _0820CF38 @ case 27
	.4byte _0820CF3C @ case 28
	.4byte _0820CF3C @ case 29
	.4byte _0820CF3C @ case 30
	.4byte _0820CF3C @ case 31
_0820CD68:
	cmp r2, #1
	beq _0820CD80
	cmp r2, #1
	bgt _0820CD76
	cmp r2, #0
	beq _0820CD7C
	b _0820CF3C
_0820CD76:
	cmp r2, #2
	beq _0820CD84
	b _0820CF3C
_0820CD7C:
	movs r0, #0x18
	b _0820CF40
_0820CD80:
	movs r0, #0x19
	b _0820CF40
_0820CD84:
	movs r0, #0x1a
	b _0820CF40
_0820CD88:
	cmp r2, #1
	beq _0820CD9C
	cmp r2, #1
	bgt _0820CD96
	cmp r2, #0
	beq _0820CDA0
	b _0820CF3C
_0820CD96:
	cmp r2, #2
	beq _0820CDA0
	b _0820CF3C
_0820CD9C:
	movs r0, #1
	b _0820CF40
_0820CDA0:
	movs r0, #0
	b _0820CF40
_0820CDA4:
	cmp r2, #1
	beq _0820CDBC
	cmp r2, #1
	bgt _0820CDB2
	cmp r2, #0
	beq _0820CDB8
	b _0820CF3C
_0820CDB2:
	cmp r2, #3
	beq _0820CDC0
	b _0820CF3C
_0820CDB8:
	movs r0, #0x21
	b _0820CF40
_0820CDBC:
	movs r0, #0x22
	b _0820CF40
_0820CDC0:
	movs r0, #0x23
	b _0820CF40
_0820CDC4:
	cmp r2, #2
	beq _0820CDDC
	cmp r2, #2
	bgt _0820CDD2
	cmp r2, #1
	beq _0820CDD8
	b _0820CF3C
_0820CDD2:
	cmp r2, #3
	beq _0820CDE0
	b _0820CF3C
_0820CDD8:
	movs r0, #0x15
	b _0820CF40
_0820CDDC:
	movs r0, #0x16
	b _0820CF40
_0820CDE0:
	movs r0, #0x17
	b _0820CF40
_0820CDE4:
	cmp r2, #0
	beq _0820CDEE
	cmp r2, #5
	beq _0820CDF2
	b _0820CF3C
_0820CDEE:
	movs r0, #0x1b
	b _0820CF40
_0820CDF2:
	movs r0, #0x1e
	b _0820CF40
_0820CDF6:
	movs r0, #0x1c
	b _0820CF40
_0820CDFA:
	movs r0, #0x1d
	b _0820CF40
_0820CDFE:
	cmp r2, #2
	beq _0820CE08
	cmp r2, #8
	beq _0820CE0C
	b _0820CF3C
_0820CE08:
	movs r0, #0x1f
	b _0820CF40
_0820CE0C:
	movs r0, #0x20
	b _0820CF40
_0820CE10:
	movs r0, #9
	b _0820CF40
_0820CE14:
	cmp r2, #0
	beq _0820CE1E
	cmp r2, #1
	beq _0820CE22
	b _0820CF3C
_0820CE1E:
	movs r0, #0x11
	b _0820CF40
_0820CE22:
	movs r0, #0x12
	b _0820CF40
_0820CE26:
	movs r0, #0x24
	b _0820CF40
_0820CE2A:
	cmp r2, #0
	beq _0820CE34
	cmp r2, #1
	beq _0820CE38
	b _0820CF3C
_0820CE34:
	movs r0, #0x25
	b _0820CF40
_0820CE38:
	movs r0, #0x26
	b _0820CF40
_0820CE3C:
	cmp r2, #0
	beq _0820CE46
	cmp r2, #1
	beq _0820CE4A
	b _0820CF3C
_0820CE46:
	movs r0, #0x27
	b _0820CF40
_0820CE4A:
	movs r0, #0x28
	b _0820CF40
_0820CE4E:
	movs r0, #0x10
	b _0820CF40
_0820CE52:
	cmp r2, #1
	beq _0820CE6A
	cmp r2, #1
	bgt _0820CE60
	cmp r2, #0
	beq _0820CE66
	b _0820CF3C
_0820CE60:
	cmp r2, #2
	beq _0820CE6E
	b _0820CF3C
_0820CE66:
	movs r0, #0x29
	b _0820CF40
_0820CE6A:
	movs r0, #0x2a
	b _0820CF40
_0820CE6E:
	movs r0, #0x2b
	b _0820CF40
_0820CE72:
	cmp r2, #1
	beq _0820CE86
	cmp r2, #1
	bgt _0820CE80
	cmp r2, #0
	beq _0820CE8A
	b _0820CF3C
_0820CE80:
	cmp r2, #2
	beq _0820CE8A
	b _0820CF3C
_0820CE86:
	movs r0, #6
	b _0820CF40
_0820CE8A:
	movs r0, #5
	b _0820CF40
_0820CE8E:
	cmp r2, #1
	beq _0820CEA2
	cmp r2, #1
	bgt _0820CE9C
	cmp r2, #0
	beq _0820CEA6
	b _0820CF3C
_0820CE9C:
	cmp r2, #2
	beq _0820CEA6
	b _0820CF3C
_0820CEA2:
	movs r0, #8
	b _0820CF40
_0820CEA6:
	movs r0, #7
	b _0820CF40
_0820CEAA:
	cmp r2, #1
	beq _0820CEC2
	cmp r2, #1
	bgt _0820CEB8
	cmp r2, #0
	beq _0820CEBE
	b _0820CF3C
_0820CEB8:
	cmp r2, #2
	beq _0820CEC6
	b _0820CF3C
_0820CEBE:
	movs r0, #2
	b _0820CF40
_0820CEC2:
	movs r0, #4
	b _0820CF40
_0820CEC6:
	movs r0, #3
	b _0820CF40
_0820CECA:
	cmp r2, #1
	beq _0820CEE6
	cmp r2, #1
	bgt _0820CED8
	cmp r2, #0
	beq _0820CEE2
	b _0820CF3C
_0820CED8:
	cmp r2, #2
	beq _0820CEEA
	cmp r2, #4
	beq _0820CEEE
	b _0820CF3C
_0820CEE2:
	movs r0, #0xa
	b _0820CF40
_0820CEE6:
	movs r0, #0xc
	b _0820CF40
_0820CEEA:
	movs r0, #0xb
	b _0820CF40
_0820CEEE:
	movs r0, #0xd
	b _0820CF40
_0820CEF2:
	cmp r2, #1
	beq _0820CF0E
	cmp r2, #1
	bgt _0820CF00
	cmp r2, #0
	beq _0820CF0A
	b _0820CF3C
_0820CF00:
	cmp r2, #2
	beq _0820CF12
	cmp r2, #3
	beq _0820CF16
	b _0820CF3C
_0820CF0A:
	movs r0, #0x2c
	b _0820CF40
_0820CF0E:
	movs r0, #0x2d
	b _0820CF40
_0820CF12:
	movs r0, #0x2e
	b _0820CF40
_0820CF16:
	movs r0, #0x2f
	b _0820CF40
_0820CF1A:
	cmp r2, #0
	beq _0820CF24
	cmp r2, #1
	beq _0820CF28
	b _0820CF3C
_0820CF24:
	movs r0, #0x30
	b _0820CF40
_0820CF28:
	movs r0, #0x31
	b _0820CF40
_0820CF2C:
	movs r0, #0xe
	b _0820CF40
_0820CF30:
	movs r0, #0x13
	b _0820CF40
_0820CF34:
	movs r0, #0x14
	b _0820CF40
_0820CF38:
	movs r0, #0xf
	b _0820CF40
_0820CF3C:
	movs r0, #1
	rsbs r0, r0, #0
_0820CF40:
	pop {r1}
	bx r1

	thumb_func_start FUN_0820cf44
FUN_0820cf44: @ 0x0820CF44
	ldr r2, _0820CF68 @ =0x030046A0
	ldr r2, [r2]
	movs r3, #0xe4
	lsls r3, r3, #2
	adds r2, r2, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	lsrs r1, r0, #5
	lsls r1, r1, #2
	adds r2, r2, r1
	movs r1, #0x1f
	ands r0, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	bx lr
	.align 2, 0
_0820CF68: .4byte 0x030046A0

	thumb_func_start FUN_0820cf6c
FUN_0820cf6c: @ 0x0820CF6C
	push {r4, r5, r6, lr}
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _0820CF80
	bl Script_GetValue
	adds r6, r0, #0
	b _0820CF82
_0820CF80:
	movs r6, #0
_0820CF82:
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _0820CF94
	bl Script_GetValue
	adds r5, r0, #0
	b _0820CF96
_0820CF94:
	movs r5, #0
_0820CF96:
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _0820CFA8
	bl Script_GetValue
	adds r4, r0, #0
	b _0820CFAA
_0820CFA8:
	movs r4, #0
_0820CFAA:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0820ccd0
	adds r1, r4, #0
	bl FUN_0820cf44
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0820cfc0
FUN_0820cfc0: @ 0x0820CFC0
	push {lr}
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x6b
	bl Script_GetKeywordValue
	adds r3, r0, #0
	cmp r3, #0x38
	bhi _0820D004
	cmp r3, #0x1f
	bgt _0820CFEC
	ldr r0, _0820CFE8 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe2
	lsls r0, r0, #2
	adds r2, r2, r0
	movs r1, #1
	lsls r1, r3
	b _0820CFFE
	.align 2, 0
_0820CFE8: .4byte 0x030046A0
_0820CFEC:
	ldr r0, _0820D008 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	movs r1, #1
	lsls r1, r0
_0820CFFE:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_0820D004:
	pop {r0}
	bx r0
	.align 2, 0
_0820D008: .4byte 0x030046A0

