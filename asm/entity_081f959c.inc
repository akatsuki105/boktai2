	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f8ab4
FUN_081f8ab4: @ 0x081F8AB4
	push {r4, r5, r6, lr}
	sub sp, #0x34
	ldr r2, _081F8B40 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	movs r1, #0x98
	lsls r1, r1, #4
	orrs r0, r1
	ldr r1, _081F8B44 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xb7
	lsls r1, r1, #0x12
	orrs r0, r1
	str r0, [sp, #0x24]
	add r5, sp, #0x24
	ldr r0, [sp, #0x28]
	ands r0, r2
	movs r1, #0x88
	lsls r1, r1, #4
	orrs r0, r1
	str r0, [sp, #0x28]
	ldr r6, _081F8B48 @ =0x03002BE0
	add r2, sp, #0x2c
	ldr r0, [r6]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r1, [r0, #0x2c]
	adds r0, r5, #0
	ldrh r0, [r0]
	subs r1, r1, r0
	movs r4, #0
	strh r1, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r5, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r1, [r6]
	adds r1, #0x2c
	movs r0, #0x3c
	str r0, [sp]
	movs r2, #4
	str r2, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	movs r0, #0x18
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	add r0, sp, #0x24
	movs r2, #0x14
	bl FUN_081f86b4
	add sp, #0x34
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F8B40: .4byte 0xFFFF0000
_081F8B44: .4byte 0x0000FFFF
_081F8B48: .4byte 0x03002BE0

	thumb_func_start FUN_081f8b4c
FUN_081f8b4c: @ 0x081F8B4C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f8b50
FUN_081f8b50: @ 0x081F8B50
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
	ldr r2, _081F8BDC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x18
	orrs r0, r3
	ldr r1, _081F8BE0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
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
	adds r4, #0x3c
	ldr r2, _081F8BE4 @ =0x00002401
	movs r0, #0x10
	str r0, [sp]
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
	ldr r1, _081F8BE8 @ =FUN_081f8b4c
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
_081F8BDC: .4byte 0xFFFF0000
_081F8BE0: .4byte 0x0000FFFF
_081F8BE4: .4byte 0x00002401
_081F8BE8: .4byte FUN_081f8b4c

	thumb_func_start FUN_081f8bec
FUN_081f8bec: @ 0x081F8BEC
	push {r4, lr}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0x3c
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f8c0c
FUN_081f8c0c: @ 0x081F8C0C
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r5, #1
_081F8C14:
	adds r0, r5, #0
	lsls r0, r2
	ldr r1, [r3, #0x38]
	ands r0, r1
	adds r4, r1, #0
	cmp r0, #0
	beq _081F8C26
	movs r0, #1
	b _081F8C28
_081F8C26:
	movs r0, #0
_081F8C28:
	cmp r0, #0
	bne _081F8C44
	movs r0, #0xbc
	muls r0, r2, r0
	adds r0, #0x3c
	adds r0, r3, r0
	adds r1, r5, #0
	lsls r1, r2
	orrs r1, r4
	str r1, [r3, #0x38]
	adds r1, r0, #0
	adds r1, #0xb7
	strb r2, [r1]
	b _081F8C4C
_081F8C44:
	adds r2, #1
	cmp r2, #7
	ble _081F8C14
	movs r0, #0
_081F8C4C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f8c54
FUN_081f8c54: @ 0x081F8C54
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov ip, r0
	ldr r4, _081F8CA0 @ =0x0203B400
	ldr r3, _081F8CA4 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F8CA8 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r5, #0xff
	ldrb r7, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	mov r4, sp
	adds r6, r0, #0
	subs r6, #0x10
	ldr r1, _081F8CAC @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F8CB0
	asrs r2, r0, #0xc
	b _081F8CB6
	.align 2, 0
_081F8CA0: .4byte 0x0203B400
_081F8CA4: .4byte 0x030046B8
_081F8CA8: .4byte 0x000003FF
_081F8CAC: .4byte 0x085B0A08
_081F8CB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F8CB6:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F8CCE
	asrs r0, r0, #0xc
	b _081F8CD4
_081F8CCE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F8CD4:
	strh r0, [r4, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081F8D04 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081F8D08 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x30
	mov r1, sp
	strh r0, [r1, #2]
	mov r0, ip
	movs r2, #0x3c
	movs r3, #3
	bl FUN_081ee07c
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F8D04: .4byte 0x000003FF
_081F8D08: .4byte 0x0203B400

	thumb_func_start FUN_081f8d0c
FUN_081f8d0c: @ 0x081F8D0C
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f8d10
FUN_081f8d10: @ 0x081F8D10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0xba
	ldrb r0, [r4]
	cmp r0, #0
	beq _081F8D4A
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	adds r3, r5, #0
	adds r3, #0xaa
	movs r2, #0
	movs r1, #0
	movs r0, #0x1e
	strh r0, [r3]
	adds r0, r5, #0
	adds r0, #0xb8
	strh r1, [r0]
	strb r2, [r4]
	movs r0, #1
	strb r0, [r5, #8]
	strb r0, [r5, #9]
_081F8D4A:
	adds r4, r5, #0
	adds r4, #0xb8
	ldrh r0, [r4]
	movs r1, #0xc
	bl Mod
	mov r8, r4
	cmp r0, #0
	bne _081F8D64
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_081f8c54
_081F8D64:
	adds r0, r5, #0
	adds r0, #0xaa
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r7, r0, #0
	cmp r1, #0
	ble _081F8DA4
	movs r0, #8
	ldrsb r0, [r5, r0]
	movs r4, #0x40
	subs r0, r4, r0
	movs r2, #0
	ldrsh r1, [r7, r2]
	bl Div
	ldrb r1, [r5, #8]
	adds r1, r1, r0
	strb r1, [r5, #8]
	movs r0, #9
	ldrsb r0, [r5, r0]
	subs r4, r4, r0
	movs r0, #0
	ldrsh r1, [r7, r0]
	adds r0, r4, #0
	bl Div
	ldrb r1, [r5, #9]
	adds r1, r1, r0
	strb r1, [r5, #9]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
_081F8DA4:
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
	beq _081F8DD4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F8DDC
_081F8DD4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F8DDC:
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
	beq _081F8E00
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F8E08
_081F8E00:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F8E08:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F8E40 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F8E78
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F8E44
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F8E38
	ldrb r0, [r4, #5]
_081F8E38:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F8E54
	.align 2, 0
_081F8E40: .4byte 0x0000FFFF
_081F8E44:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F8E54
	strh r1, [r4, #8]
_081F8E54:
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
	bne _081F8E78
	movs r0, #1
	strb r0, [r4, #7]
_081F8E78:
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bgt _081F8E9C
	adds r1, r5, #0
	adds r1, #0xb6
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r1, r5, #0
	adds r1, #0xba
	movs r0, #1
	strb r0, [r1]
	b _081F8EA4
_081F8E9C:
	mov r2, r8
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
_081F8EA4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f8eb0
FUN_081f8eb0: @ 0x081F8EB0
	push {r4, r5, r6, r7, lr}
	adds r5, r1, #0
	adds r3, r5, #0
	adds r3, #0xba
	ldrb r0, [r3]
	cmp r0, #0
	beq _081F8ECA
	adds r0, r5, #0
	adds r0, #0xb8
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081F8ECA:
	adds r0, r5, #0
	adds r0, #0xa4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081F8EFC
	adds r1, r5, #0
	adds r1, #0x9c
	adds r0, r5, #0
	adds r0, #0xa0
	ldr r2, [r1]
	ldr r0, [r0]
	adds r2, r2, r0
	str r2, [r1]
	movs r0, #0xff
	lsls r0, r0, #0xc
	cmp r2, r0
	bls _081F8F0E
	ldr r3, _081F8EF8 @ =0xFFF01000
	adds r0, r2, r3
	str r0, [r1]
	b _081F8F0E
	.align 2, 0
_081F8EF8: .4byte 0xFFF01000
_081F8EFC:
	adds r2, r5, #0
	adds r2, #0x9c
	adds r1, r5, #0
	adds r1, #0xa0
	ldr r0, [r2]
	ldr r1, [r1]
	subs r0, r0, r1
	str r0, [r2]
	adds r1, r2, #0
_081F8F0E:
	ldr r1, [r1]
	adds r0, r5, #0
	adds r0, #0xa8
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r6, r5, #0
	adds r6, #0x94
	lsrs r4, r1, #0xc
	lsls r0, r0, #7
	mov ip, r0
	ldr r2, _081F8F44 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r7, r6, #0
	cmp r0, #0
	blt _081F8F48
	asrs r3, r0, #0xc
	b _081F8F4E
	.align 2, 0
_081F8F44: .4byte 0x085B0A08
_081F8F48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_081F8F4E:
	movs r0, #0
	strh r3, [r6]
	strh r0, [r6, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _081F8F6E
	asrs r1, r0, #0xc
	b _081F8F74
_081F8F6E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F8F74:
	movs r0, #0
	strh r1, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x96
	strh r0, [r1]
	adds r6, r5, #0
	adds r6, #0x1c
	subs r1, #0xa
	ldrh r0, [r1]
	ldrh r2, [r7]
	adds r0, r0, r2
	strh r0, [r5, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r3, [r7, #2]
	adds r0, r0, r3
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r7, [r7, #4]
	adds r0, r0, r7
	strh r0, [r6, #4]
	adds r4, r5, #0
	adds r4, #0xb8
	ldrh r0, [r4]
	movs r1, #0x1e
	bl Mod
	adds r7, r4, #0
	cmp r0, #0
	bne _081F8FCC
	ldr r2, _081F9004 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081F9008 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081F900C @ =0x0203B400
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _081F8FCC
	adds r0, r6, #0
	bl FUN_081f8c54
_081F8FCC:
	adds r0, r5, #0
	bl FUN_081f8bec
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
	beq _081F9010
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F9018
	.align 2, 0
_081F9004: .4byte 0x030046B8
_081F9008: .4byte 0x000003FF
_081F900C: .4byte 0x0203B400
_081F9010:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F9018:
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
	beq _081F903C
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F9044
_081F903C:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F9044:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _081F907C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F90B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F9080
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F9074
	ldrb r0, [r4, #5]
_081F9074:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F9090
	.align 2, 0
_081F907C: .4byte 0x0000FFFF
_081F9080:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F9090
	strh r1, [r4, #8]
_081F9090:
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
	bne _081F90B4
	movs r0, #1
	strb r0, [r4, #7]
_081F90B4:
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	adds r1, r5, #0
	adds r1, #0xb0
	ldr r0, [r1]
	cmp r0, #0
	ble _081F90CA
	subs r0, #1
	str r0, [r1]
	b _081F90D8
_081F90CA:
	adds r1, r5, #0
	adds r1, #0xb6
	movs r0, #3
	strb r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
_081F90D8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f90e0
FUN_081f90e0: @ 0x081F90E0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0xba
	ldrb r0, [r4]
	cmp r0, #0
	beq _081F911E
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	adds r1, r5, #0
	adds r1, #0xaa
	movs r2, #0
	movs r3, #0
	movs r0, #0x14
	strh r0, [r1]
	adds r1, #0xe
	strh r3, [r1]
	strb r2, [r4]
	movs r0, #0x40
	strb r0, [r5, #8]
	strb r0, [r5, #9]
	strh r3, [r1]
_081F911E:
	adds r4, r5, #0
	adds r4, #0xb8
	ldrh r0, [r4]
	movs r1, #6
	bl Mod
	mov r8, r4
	cmp r0, #0
	bne _081F9138
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_081f8c54
_081F9138:
	adds r0, r5, #0
	adds r0, #0xaa
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r7, r0, #0
	cmp r1, #0
	ble _081F9178
	movs r0, #8
	ldrsb r0, [r5, r0]
	movs r4, #1
	subs r0, r4, r0
	movs r3, #0
	ldrsh r1, [r7, r3]
	bl Div
	ldrb r1, [r5, #8]
	adds r1, r1, r0
	strb r1, [r5, #8]
	movs r0, #9
	ldrsb r0, [r5, r0]
	subs r4, r4, r0
	movs r0, #0
	ldrsh r1, [r7, r0]
	adds r0, r4, #0
	bl Div
	ldrb r1, [r5, #9]
	adds r1, r1, r0
	strb r1, [r5, #9]
	ldrh r0, [r7]
	subs r0, #1
	strh r0, [r7]
_081F9178:
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
	beq _081F91A8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F91B0
_081F91A8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F91B0:
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
	beq _081F91D4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F91DC
_081F91D4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F91DC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F9214 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F924C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F9218
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F920C
	ldrb r0, [r4, #5]
_081F920C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F9228
	.align 2, 0
_081F9214: .4byte 0x0000FFFF
_081F9218:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F9228
	strh r1, [r4, #8]
_081F9228:
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
	bne _081F924C
	movs r0, #1
	strb r0, [r4, #7]
_081F924C:
	movs r3, #0
	ldrsh r0, [r7, r3]
	cmp r0, #0
	bgt _081F9280
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r2, r5, #0
	adds r2, #0xb7
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	mov r3, sb
	ldr r0, [r3, #0x38]
	bics r0, r1
	str r0, [r3, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xb6
	movs r1, #0
	strb r1, [r0]
	adds r0, #4
	strb r1, [r0]
	b _081F9288
_081F9280:
	mov r1, r8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F9288:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f9294
FUN_081f9294: @ 0x081F9294
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	str r0, [sp, #0x18]
	mov r8, r1
	mov sb, r2
	mov sl, r3
	ldr r0, _081F9344 @ =0x0300020C
	ldr r6, [r0]
	cmp r6, #0
	bne _081F92BC
	bl Entity081f959c_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081F92BC
	b _081F94CC
_081F92BC:
	adds r0, r6, #0
	bl FUN_081f8c0c
	adds r7, r0, #0
	cmp r7, #0
	bne _081F92CA
	b _081F94CC
_081F92CA:
	adds r0, #0xb6
	movs r2, #0
	movs r5, #1
	strb r5, [r0]
	adds r1, r7, #0
	adds r1, #0xb0
	ldr r0, [sp, #0x40]
	str r0, [r1]
	adds r0, r7, #0
	adds r0, #0xb4
	strh r2, [r0]
	adds r4, r7, #0
	adds r4, #0x9c
	mov r1, r8
	lsls r0, r1, #0xc
	str r0, [r4]
	adds r0, r7, #0
	adds r0, #0xa0
	mov r2, sb
	str r2, [r0]
	adds r3, r7, #0
	adds r3, #0xa8
	mov r0, sl
	strh r0, [r3]
	adds r1, r7, #0
	adds r1, #0xa4
	ldr r0, [sp, #0x3c]
	strh r0, [r1]
	adds r0, r7, #0
	adds r0, #0xba
	strb r5, [r0]
	adds r2, r7, #0
	adds r2, #0x8c
	ldr r5, [sp, #0x18]
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r2]
	str r1, [r2, #4]
	mov r8, r7
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, [r4]
	movs r2, #0
	ldrsh r1, [r3, r2]
	add r4, sp, #0x10
	lsrs r3, r0, #0xc
	lsls r5, r1, #7
	ldr r2, _081F9348 @ =0x085B0A08
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
	blt _081F934C
	asrs r1, r0, #0xc
	b _081F9352
	.align 2, 0
_081F9344: .4byte 0x0300020C
_081F9348: .4byte 0x085B0A08
_081F934C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F9352:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _081F936E
	asrs r0, r0, #0xc
	b _081F9374
_081F936E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F9374:
	movs r5, #0
	mov sb, r5
	strh r0, [r4, #4]
	add r0, sp, #0x10
	ldrh r0, [r0]
	mov r1, r8
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #0x1c]
	add r0, sp, #0x10
	ldrh r0, [r0, #4]
	ldrh r5, [r2, #0x20]
	adds r0, r0, r5
	strh r0, [r2, #0x20]
	ldr r0, _081F93F8 @ =0x0000922E
	ldr r1, _081F93FC @ =0x0000121B
	bl GetFile
	adds r4, r7, #0
	adds r4, #0xac
	str r0, [r4]
	adds r1, r6, #0
	adds r1, #0x18
	mov r0, r8
	movs r2, #0
	bl AuxSprite_Add
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r4]
	mov r0, sb
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #7
	movs r3, #0
	bl AuxAnim_SetAnim
	mov r1, r8
	ldr r0, [r1, #0xc]
	movs r1, #0xd9
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _081F9400
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F9408
	.align 2, 0
_081F93F8: .4byte 0x0000922E
_081F93FC: .4byte 0x0000121B
_081F9400:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F9408:
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
	beq _081F942C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F9434
_081F942C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F9434:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081F946C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081F94A4
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F9470
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081F9464
	ldrb r0, [r5, #5]
_081F9464:
	subs r0, #1
	strh r0, [r5, #8]
	b _081F9480
	.align 2, 0
_081F946C: .4byte 0x0000FFFF
_081F9470:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081F9480
	strh r1, [r5, #8]
_081F9480:
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
	bne _081F94A4
	movs r0, #1
	strb r0, [r5, #7]
_081F94A4:
	movs r2, #0
	movs r0, #2
	mov r5, r8
	strb r0, [r5, #7]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	ldr r0, [sp, #0x50]
	str r0, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	adds r0, r7, #0
	ldr r1, [sp, #0x44]
	ldr r2, [sp, #0x48]
	ldr r3, [sp, #0x4c]
	bl FUN_081f8b50
_081F94CC:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity081f959c_Update
Entity081f959c_Update: @ 0x081F94DC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	ldr r0, [r5, #0x38]
	cmp r0, #0
	beq _081F952A
	movs r4, #0
	ldr r7, _081F9500 @ =0x085AE5D0
_081F94EE:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F9504
	movs r0, #1
	b _081F9506
	.align 2, 0
_081F9500: .4byte 0x085AE5D0
_081F9504:
	movs r0, #0
_081F9506:
	cmp r0, #0
	beq _081F9524
	movs r0, #0xbc
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0xb6
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F9524:
	adds r4, #1
	cmp r4, #7
	ble _081F94EE
_081F952A:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081f959c_Destroy
Entity081f959c_Destroy: @ 0x081F9534
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F953A:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F954A
	movs r0, #1
	b _081F954C
_081F954A:
	movs r0, #0
_081F954C:
	cmp r0, #0
	beq _081F955C
	movs r0, #0xbc
	muls r0, r4, r0
	adds r0, #0x3c
	adds r0, r5, r0
	bl AuxSprite_Remove
_081F955C:
	adds r4, #1
	cmp r4, #7
	ble _081F953A
	ldr r1, _081F9570 @ =0x0300020C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F9570: .4byte 0x0300020C

	thumb_func_start Entity081f959c_Init
Entity081f959c_Init: @ 0x081F9574
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _081F9594 @ =0x0000F422
	bl Video_GetAuxSprite
	ldr r0, _081F9598 @ =0x0300020C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F9594: .4byte 0x0000F422
_081F9598: .4byte 0x0300020C

	thumb_func_start Entity081f959c_Create
Entity081f959c_Create: @ 0x081F959C
	push {r4, lr}
	ldr r0, _081F95D0 @ =0x0300020C
	ldr r0, [r0]
	cmp r0, #0
	bne _081F95E2
	ldr r1, _081F95D4 @ =0x0000061C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F95E0
	ldr r1, _081F95D8 @ =Entity081f959c_Update
	ldr r2, _081F95DC @ =Entity081f959c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f959c_Init
	cmp r0, #0
	bge _081F95E0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F95E2
	.align 2, 0
_081F95D0: .4byte 0x0300020C
_081F95D4: .4byte 0x0000061C
_081F95D8: .4byte Entity081f959c_Update
_081F95DC: .4byte Entity081f959c_Destroy
_081F95E0:
	adds r0, r4, #0
_081F95E2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f95e8
FUN_081f95e8: @ 0x081F95E8
	ldr r1, _081F95F0 @ =0x0300020C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F95F0: .4byte 0x0300020C

	thumb_func_start FUN_081f95f4
FUN_081f95f4: @ 0x081F95F4
	push {lr}
	ldr r0, _081F9600 @ =0x0300020C
	ldr r0, [r0]
	cmp r0, #0
	bne _081F9608
	b _081F9622
	.align 2, 0
_081F9600: .4byte 0x0300020C
_081F9604:
	movs r0, #1
	b _081F9624
_081F9608:
	movs r2, #0
	adds r1, r0, #0
	adds r1, #0xf2
_081F960E:
	ldrb r0, [r1]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081F9604
	adds r1, #0xbc
	adds r2, #1
	cmp r2, #7
	ble _081F960E
_081F9622:
	movs r0, #0
_081F9624:
	pop {r1}
	bx r1

	thumb_func_start FUN_081f9628
FUN_081f9628: @ 0x081F9628
	push {lr}
	ldr r0, _081F9650 @ =0x0300020C
	ldr r0, [r0]
	cmp r0, #0
	beq _081F964C
	movs r3, #3
	adds r0, #0xf2
	movs r2, #7
_081F9638:
	ldrb r1, [r0]
	cmp r1, #3
	beq _081F9644
	cmp r1, #0
	beq _081F9644
	strb r3, [r0]
_081F9644:
	adds r0, #0xbc
	subs r2, #1
	cmp r2, #0
	bge _081F9638
_081F964C:
	pop {r0}
	bx r0
	.align 2, 0
_081F9650: .4byte 0x0300020C
