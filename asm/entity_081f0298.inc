	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081efaf4
FUN_081efaf4: @ 0x081EFAF4
	bx lr
	.align 2, 0

	thumb_func_start FUN_081efaf8
FUN_081efaf8: @ 0x081EFAF8
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
	ldr r2, _081EFB84 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _081EFB88 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xf
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
	adds r4, #0x44
	ldr r2, _081EFB8C @ =0x00002001
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
	ldr r1, _081EFB90 @ =FUN_081efaf4
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
_081EFB84: .4byte 0xFFFF0000
_081EFB88: .4byte 0x0000FFFF
_081EFB8C: .4byte 0x00002001
_081EFB90: .4byte FUN_081efaf4

	thumb_func_start FUN_081efb94
FUN_081efb94: @ 0x081EFB94
	bx lr
	.align 2, 0

	thumb_func_start FUN_081efb98
FUN_081efb98: @ 0x081EFB98
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r5, r1, #0
	adds r6, r5, #0
	adds r0, r5, #0
	adds r0, #0x98
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _081EFC18
	movs r2, #2
	cmp r0, #0x32
	bhi _081EFBB8
	movs r2, #0
	cmp r0, #0x1e
	bls _081EFBB8
	movs r2, #1
_081EFBB8:
	adds r4, r6, #0
	adds r4, #0x98
	ldrh r0, [r4]
	ldr r1, _081EFBE0 @ =0x085AE508
	adds r1, r2, r1
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _081EFBE8
	ldr r1, [r5]
	movs r2, #1
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _081EFBE4
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	b _081EFBE6
	.align 2, 0
_081EFBE0: .4byte 0x085AE508
_081EFBE4:
	orrs r1, r2
_081EFBE6:
	str r1, [r5]
_081EFBE8:
	ldrh r0, [r4]
	cmp r0, #0x46
	bls _081EFC18
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r4, r6, #0
	adds r4, #0x97
	movs r0, #0
	ldrsb r0, [r4, r0]
	lsls r1, r0
	ldr r0, [r7, #0x38]
	bics r0, r1
	str r0, [r7, #0x38]
	adds r1, r6, #0
	adds r1, #0x96
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r4]
_081EFC18:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081efc20
FUN_081efc20: @ 0x081EFC20
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r1, #0
	adds r0, r5, #0
	adds r0, #0x9a
	ldrb r0, [r0]
	cmp r0, #0
	beq _081EFC88
	adds r0, r5, #0
	adds r0, #0x9b
	add r3, sp, #4
	mov r2, sp
	adds r2, #5
	ldrb r0, [r0]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	adds r4, r2, #0
	cmp r1, #1
	bls _081EFC5E
	movs r0, #1
	strb r0, [r4]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081EFC64
_081EFC5E:
	movs r0, #0
	strb r0, [r4]
	strb r1, [r3]
_081EFC64:
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r7, #0x34]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0x13
	bl AuxAnim_SetAnim
	adds r1, r5, #0
	adds r1, #0x98
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x9a
	strb r2, [r0]
_081EFC88:
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
	beq _081EFCB8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081EFCC0
_081EFCB8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081EFCC0:
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
	beq _081EFCE4
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081EFCEC
_081EFCE4:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081EFCEC:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081EFD24 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081EFD5C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081EFD28
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081EFD1C
	ldrb r0, [r4, #5]
_081EFD1C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081EFD38
	.align 2, 0
_081EFD24: .4byte 0x0000FFFF
_081EFD28:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081EFD38
	strh r1, [r4, #8]
_081EFD38:
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
	bne _081EFD5C
	movs r0, #1
	strb r0, [r4, #7]
_081EFD5C:
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_081efb98
	adds r1, r5, #0
	adds r1, #0x98
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081efd78
FUN_081efd78: @ 0x081EFD78
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

	thumb_func_start FUN_081f0038
FUN_081f0038: @ 0x081F0038
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
_081F0040:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0050
	movs r0, #1
	b _081F0052
_081F0050:
	movs r0, #0
_081F0052:
	cmp r0, #0
	bne _081F007A
	movs r0, #0x9c
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r2, r4
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x38]
	adds r0, r4, #0
	movs r1, #0x9c
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0x97
	strb r5, [r0]
	adds r0, r4, #0
	b _081F0082
_081F007A:
	adds r5, #1
	cmp r5, #0xb
	ble _081F0040
	movs r0, #0
_081F0082:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f0088
FUN_081f0088: @ 0x081F0088
	push {lr}
	bl FUN_081f0038
	cmp r0, #0
	bne _081F0094
	movs r0, #0
_081F0094:
	pop {r1}
	bx r1

	thumb_func_start FUN_081f0098
FUN_081f0098: @ 0x081F0098
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp, #8]
	adds r7, r1, #0
	mov r8, r2
	mov sb, r3
	ldr r0, _081F0130 @ =0x030001E0
	ldr r6, [r0]
	cmp r6, #0
	bne _081F00C0
	bl Entity081f0298_Create
	adds r6, r0, #0
	cmp r6, #0
	bne _081F00C0
	b _081F01BE
_081F00C0:
	adds r0, r6, #0
	bl FUN_081f0088
	adds r5, r0, #0
	cmp r5, #0
	beq _081F01BE
	adds r0, #0x96
	movs r1, #0
	movs r2, #1
	mov sl, r2
	mov r2, sl
	strb r2, [r0]
	subs r0, #2
	strh r1, [r0]
	adds r4, r5, #0
	adds r4, #0x9b
	strb r7, [r4]
	adds r0, #4
	strh r1, [r0]
	ldr r0, [sp, #0x30]
	str r0, [sp]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	ldr r3, [sp, #0x2c]
	bl FUN_081efaf8
	adds r7, r5, #0
	adds r1, r6, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	add r3, sp, #4
	mov r2, sp
	adds r2, #5
	ldrb r0, [r4]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	mov r8, r4
	adds r4, r2, #0
	cmp r1, #1
	bls _081F0134
	mov r0, sl
	strb r0, [r4]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081F013A
	.align 2, 0
_081F0130: .4byte 0x030001E0
_081F0134:
	movs r0, #0
	strb r0, [r4]
	strb r1, [r3]
_081F013A:
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r6, #0x34]
	add r2, sp, #4
	ldrb r3, [r2]
	ldrb r2, [r4]
	str r2, [sp]
	movs r2, #0x12
	bl AuxAnim_SetAnim
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r2, _081F0178 @ =0x085B0A08
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x34]
	muls r0, r1, r0
	cmp r0, #0
	blt _081F017C
	asrs r0, r0, #0xc
	b _081F0182
	.align 2, 0
_081F0178: .4byte 0x085B0A08
_081F017C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F0182:
	strh r0, [r5, #0x3c]
	ldr r0, _081F01A0 @ =0x085B0A08
	mov r2, r8
	ldrb r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	ldr r1, [sp, #0x34]
	muls r0, r1, r0
	cmp r0, #0
	blt _081F01A4
	asrs r4, r0, #0xc
	b _081F01AA
	.align 2, 0
_081F01A0: .4byte 0x085B0A08
_081F01A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r4, r0, #0
_081F01AA:
	adds r0, r5, #0
	adds r0, #0x40
	strh r4, [r0]
	movs r0, #0xa
	strh r0, [r5, #0x3e]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	strb r1, [r7, #7]
_081F01BE:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity081f0298_Update
Entity081f0298_Update: @ 0x081F01D0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	movs r4, #0
	ldr r7, _081F01EC @ =0x085AE50C
_081F01DC:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F01F0
	movs r0, #1
	b _081F01F2
	.align 2, 0
_081F01EC: .4byte 0x085AE50C
_081F01F0:
	movs r0, #0
_081F01F2:
	cmp r0, #0
	beq _081F0210
	movs r0, #0x9c
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0x96
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F0210:
	adds r4, #1
	cmp r4, #0xb
	ble _081F01DC
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081f0298_Destroy
Entity081f0298_Destroy: @ 0x081F0220
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F0226:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0236
	movs r0, #1
	b _081F0238
_081F0236:
	movs r0, #0
_081F0238:
	cmp r0, #0
	beq _081F0248
	movs r0, #0x9c
	muls r0, r4, r0
	adds r0, #0x3c
	adds r0, r5, r0
	bl AuxSprite_Remove
_081F0248:
	adds r4, #1
	cmp r4, #0xb
	ble _081F0226
	ldr r1, _081F025C @ =0x030001E0
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F025C: .4byte 0x030001E0

	thumb_func_start Entity081f0298_Init
Entity081f0298_Init: @ 0x081F0260
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081F0288 @ =0x0000D45E
	bl Video_GetAuxSprite
	ldr r0, _081F028C @ =0x0000922E
	ldr r1, _081F0290 @ =0x00001DC3
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _081F0294 @ =0x030001E0
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F0288: .4byte 0x0000D45E
_081F028C: .4byte 0x0000922E
_081F0290: .4byte 0x00001DC3
_081F0294: .4byte 0x030001E0

	thumb_func_start Entity081f0298_Create
Entity081f0298_Create: @ 0x081F0298
	push {r4, lr}
	ldr r0, _081F02CC @ =0x030001E0
	ldr r0, [r0]
	cmp r0, #0
	bne _081F02DE
	ldr r1, _081F02D0 @ =0x0000078C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F02DC
	ldr r1, _081F02D4 @ =Entity081f0298_Update
	ldr r2, _081F02D8 @ =Entity081f0298_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f0298_Init
	cmp r0, #0
	bge _081F02DC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F02DE
	.align 2, 0
_081F02CC: .4byte 0x030001E0
_081F02D0: .4byte 0x0000078C
_081F02D4: .4byte Entity081f0298_Update
_081F02D8: .4byte Entity081f0298_Destroy
_081F02DC:
	adds r0, r4, #0
_081F02DE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f02e4
FUN_081f02e4: @ 0x081F02E4
	ldr r1, _081F02EC @ =0x030001E0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F02EC: .4byte 0x030001E0
