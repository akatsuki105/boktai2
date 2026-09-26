	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081dbc60
FUN_081dbc60: @ 0x081DBC60
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DBCD8 @ =0x0000CB05
	ldr r1, _081DBCDC @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xe0
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xc8
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenMainSpriteFile
	movs r0, #4
	mov r8, r0
	movs r7, #0
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r6, r5, r1
_081DBC92:
	mov r2, r8
	lsls r4, r2, #1
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r0, r5, r3
	adds r0, r0, r4
	ldrh r2, [r0]
	str r7, [sp]
	str r7, [sp, #4]
	str r7, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r6, #0
	subs r3, #0x40
	adds r1, r5, r3
	movs r3, #0x10
	bl MainSprite_Add
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r4
	ldr r1, _081DBCE0 @ =0x0000FFFF
	strh r1, [r0]
	adds r6, #0x60
	movs r2, #1
	add r8, r2
	mov r3, r8
	cmp r3, #7
	ble _081DBC92
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DBCD8: .4byte 0x0000CB05
_081DBCDC: .4byte 0x0000DCC1
_081DBCE0: .4byte 0x0000FFFF

	thumb_func_start FUN_081dbce4
FUN_081dbce4: @ 0x081DBCE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r1, r0, #0
	movs r2, #0
	adds r4, r1, #0
	adds r4, #0x40
	movs r0, #0x1d
	mov r8, r0
	movs r7, #0x40
	mov ip, r7
	movs r0, #0xd3
	mov sb, r0
	movs r6, #0x70
	adds r3, r4, #0
	movs r5, #0
_081DBD06:
	cmp r2, #1
	beq _081DBD28
	cmp r2, #1
	bgt _081DBD14
	cmp r2, #0
	beq _081DBD1E
	b _081DBD5C
_081DBD14:
	cmp r2, #2
	beq _081DBD38
	cmp r2, #3
	beq _081DBD48
	b _081DBD5C
_081DBD1E:
	mov r7, r8
	strh r7, [r4]
	adds r0, r1, #0
	adds r0, #0x42
	b _081DBD32
_081DBD28:
	adds r0, r1, #0
	adds r0, #0xa0
	mov r7, sb
	strh r7, [r0]
	adds r0, #2
_081DBD32:
	mov r7, ip
	strh r7, [r0]
	b _081DBD60
_081DBD38:
	movs r7, #0x80
	lsls r7, r7, #1
	adds r0, r1, r7
	mov r7, r8
	strh r7, [r0]
	movs r7, #0x81
	lsls r7, r7, #1
	b _081DBD56
_081DBD48:
	movs r7, #0xb0
	lsls r7, r7, #1
	adds r0, r1, r7
	mov r7, sb
	strh r7, [r0]
	movs r7, #0xb1
	lsls r7, r7, #1
_081DBD56:
	adds r0, r1, r7
	strh r6, [r0]
	b _081DBD60
_081DBD5C:
	strh r5, [r3]
	strh r5, [r3, #2]
_081DBD60:
	adds r3, #0x60
	adds r2, #1
	cmp r2, #7
	ble _081DBD06
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbd74
FUN_081dbd74: @ 0x081DBD74
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081DBDE8 @ =0x0000CB05
	ldr r1, _081DBDEC @ =0x0000DE23
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenMainSpriteFile
	movs r4, #0
	mov sb, r4
	movs r7, #0
	adds r6, r5, #0
	adds r6, #0x20
	movs r0, #0
	mov r8, r0
_081DBDAA:
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r7
	ldrh r2, [r0]
	mov r3, r8
	str r3, [sp]
	movs r0, #1
	str r0, [sp, #4]
	str r3, [sp, #8]
	str r3, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0x10
	bl MainSprite_Add
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r0, r0, r7
	ldr r1, _081DBDF0 @ =0x0000FFFF
	strh r1, [r0]
	cmp r4, #1
	beq _081DBE02
	cmp r4, #1
	bgt _081DBDF4
	cmp r4, #0
	beq _081DBDFE
	b _081DBE0E
	.align 2, 0
_081DBDE8: .4byte 0x0000CB05
_081DBDEC: .4byte 0x0000DE23
_081DBDF0: .4byte 0x0000FFFF
_081DBDF4:
	cmp r4, #2
	beq _081DBE06
	cmp r4, #3
	beq _081DBE0A
	b _081DBE0E
_081DBDFE:
	movs r3, #0x22
	b _081DBE10
_081DBE02:
	movs r3, #0x23
	b _081DBE10
_081DBE06:
	movs r3, #0x24
	b _081DBE10
_081DBE0A:
	movs r3, #0x25
	b _081DBE10
_081DBE0E:
	movs r3, #0
_081DBE10:
	adds r1, r5, #0
	adds r1, #0x68
	add r1, sb
	ldr r0, _081DBE40 @ =0x03003584
	lsls r2, r3, #5
	ldr r0, [r0]
	adds r0, r0, r2
	str r0, [r1]
	strh r3, [r6, #0x3a]
	movs r2, #0x60
	add sb, r2
	adds r7, #2
	adds r6, #0x60
	adds r4, #1
	cmp r4, #3
	ble _081DBDAA
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DBE40: .4byte 0x03003584

	thumb_func_start FUN_081dbe44
FUN_081dbe44: @ 0x081DBE44
	push {r4, lr}
	adds r4, r0, #0
	bl MainSprite_AdvanceAnim
	adds r2, r0, #0
	ldrb r1, [r4, #0x1d]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081DBE5C
	cmp r2, #0
	beq _081DBE60
_081DBE5C:
	movs r0, #1
	b _081DBE62
_081DBE60:
	movs r0, #0
_081DBE62:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dbe68
FUN_081dbe68: @ 0x081DBE68
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x28
	movs r2, #7
_081DBE72:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DBE72
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbe84
FUN_081dbe84: @ 0x081DBE84
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x20
	movs r5, #7
_081DBE8C:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DBE8C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dbea0
FUN_081dbea0: @ 0x081DBEA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r1, r6, r1
	str r1, [sp, #4]
	adds r2, r6, #0
	adds r2, #0x20
	str r2, [sp, #8]
	movs r3, #0xd0
	lsls r3, r3, #1
	adds r3, r6, r3
	str r3, [sp, #0xc]
	str r0, [sp, #0x10]
	movs r1, #0x28
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0
	str r2, [sp, #0x14]
	movs r3, #0xd4
	lsls r3, r3, #1
	adds r7, r6, r3
	movs r0, #0xda
	lsls r0, r0, #2
	adds r0, r6, r0
	str r0, [sp, #0x18]
_081DBEE2:
	ldr r0, _081DBF24 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _081DBF04
	mov r1, sb
	cmp r1, #0
	blt _081DBF04
	mov r3, sb
	lsls r0, r3, #3
	add r0, sb
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r3, r2, r0
	cmp r3, #0
	bne _081DBF28
_081DBF04:
	ldr r0, [r7]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7]
	mov r0, sb
	adds r0, #0x3a
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	mov r1, r8
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, r8
	b _081DC01C
	.align 2, 0
_081DBF24: .4byte 0x03002C68
_081DBF28:
	mov r1, sb
	lsls r0, r1, #2
	adds r0, r6, r0
	movs r1, #0xeb
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r1, [r0]
	cmp r1, #1
	bls _081DC000
	ldrb r0, [r2, #0x1c]
	cmp r0, #5
	bgt _081DBF5C
	mov r2, r8
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r0, sb
	adds r0, #0x36
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	ldr r0, [r7]
	subs r1, #3
	ands r0, r1
	str r0, [r7]
	b _081DC01E
_081DBF5C:
	mov r1, r8
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r0, [r7]
	movs r1, #1
	orrs r0, r1
	str r0, [r7]
	mov r2, sb
	adds r2, #4
	movs r0, #0x28
	adds r0, r0, r6
	mov sl, r0
	mov r1, sb
	cmp r1, #1
	bgt _081DBFC0
	adds r0, r3, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DBFA6
	cmp r0, #1
	bgt _081DBF94
	cmp r0, #0
	beq _081DBF9A
	b _081DC050
_081DBF94:
	cmp r0, #2
	beq _081DBFB2
	b _081DC050
_081DBF9A:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #8
	strh r0, [r1]
	b _081DC050
_081DBFA6:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xcf
	strh r0, [r1]
	b _081DC050
_081DBFB2:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xd3
	lsls r0, r0, #1
	strh r0, [r1]
	b _081DC050
_081DBFC0:
	adds r0, r3, #0
	adds r0, #0x40
	ldrb r0, [r0]
	cmp r0, #1
	beq _081DBFE6
	cmp r0, #1
	bgt _081DBFD4
	cmp r0, #0
	beq _081DBFDA
	b _081DC050
_081DBFD4:
	cmp r0, #2
	beq _081DBFF2
	b _081DC050
_081DBFDA:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #6
	strh r0, [r1]
	b _081DC050
_081DBFE6:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xcd
	strh r0, [r1]
	b _081DC050
_081DBFF2:
	ldr r3, [sp, #4]
	ldr r0, [sp, #0x14]
	adds r1, r3, r0
	movs r0, #0xd2
	lsls r0, r0, #1
	strh r0, [r1]
	b _081DC050
_081DC000:
	cmp r1, #1
	bne _081DC02A
	ldr r0, [r7]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r7]
	mov r0, sb
	adds r0, #0x36
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	mov r2, r8
	ldr r0, [r2]
	orrs r0, r1
_081DC01C:
	str r0, [r2]
_081DC01E:
	mov r2, sb
	adds r2, #4
	movs r3, #0x28
	adds r3, r3, r6
	mov sl, r3
	b _081DC050
_081DC02A:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	mov r0, sb
	adds r0, #0x3a
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	mov r2, sb
	adds r2, #4
	movs r0, #0x28
	adds r0, r0, r6
	mov sl, r0
_081DC050:
	lsls r0, r2, #1
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r4, r6, r1
	adds r1, r4, r0
	ldrh r2, [r1]
	movs r3, #0xdc
	lsls r3, r3, #2
	adds r5, r6, r3
	adds r0, r5, r0
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r2, r0
	beq _081DC076
	ldr r0, [sp, #0xc]
	subs r3, #0x50
	adds r1, r6, r3
	bl MainSprite_LoadPose
_081DC076:
	ldr r0, [sp, #0x14]
	adds r4, r4, r0
	ldrh r1, [r4]
	adds r5, r5, r0
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r1, r0
	beq _081DC0AE
	ldr r2, [sp, #0x10]
	add r2, sl
	ldr r0, _081DC0FC @ =0x085AE204
	add r0, sb
	ldrb r1, [r0]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	ldrh r2, [r4]
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #8]
	movs r3, #0xd0
	lsls r3, r3, #2
	adds r1, r6, r3
	movs r3, #1
	bl MainSprite_SetAnim
	ldrh r0, [r4]
	strh r0, [r5]
_081DC0AE:
	ldr r0, [sp, #8]
	movs r2, #0xd0
	lsls r2, r2, #2
	adds r1, r6, r2
	bl MainSprite_AdvanceAnim
	ldr r3, [sp, #8]
	adds r3, #0x60
	str r3, [sp, #8]
	ldr r0, [sp, #0xc]
	adds r0, #0x60
	str r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	adds r1, #0x60
	str r1, [sp, #0x10]
	movs r2, #0x60
	add r8, r2
	ldr r3, [sp, #0x14]
	adds r3, #2
	str r3, [sp, #0x14]
	adds r7, #0x60
	ldr r0, [sp, #0x18]
	adds r0, #2
	str r0, [sp, #0x18]
	movs r1, #1
	add sb, r1
	mov r2, sb
	cmp r2, #3
	bgt _081DC0EA
	b _081DBEE2
_081DC0EA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC0FC: .4byte 0x085AE204

	thumb_func_start FUN_081dc100
FUN_081dc100: @ 0x081DC100
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	bge _081DC144
	ldr r0, _081DC140 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	bne _081DC11E
	b _081DC2D4
_081DC11E:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #2
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC140: .4byte 0x000003D1
_081DC144:
	bl FUN_081dfa04
	adds r2, r0, #0
	subs r0, r2, #5
	cmp r0, #1
	bhi _081DC184
	ldr r0, _081DC180 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #4
	bne _081DC15E
	b _081DC2D4
_081DC15E:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #4
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #4
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC180: .4byte 0x000003D1
_081DC184:
	ldr r0, _081DC198 @ =0x03002C68
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #0
	beq _081DC19C
	ldrb r0, [r1, #0x1d]
	cmp r0, #0
	beq _081DC19C
	movs r0, #1
	b _081DC19E
	.align 2, 0
_081DC198: .4byte 0x03002C68
_081DC19C:
	movs r0, #0
_081DC19E:
	cmp r0, #0
	beq _081DC1D8
	cmp r2, #8
	bne _081DC1D8
	ldr r0, _081DC1D4 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #6
	bne _081DC1B4
	b _081DC2D4
_081DC1B4:
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #6
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #6
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC1D4: .4byte 0x000003D1
_081DC1D8:
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r0, [r3]
	cmp r0, #0
	bne _081DC1EA
	movs r6, #0
	b _081DC1F0
_081DC1EA:
	adds r0, #0x68
	adds r0, r0, r1
	ldrb r6, [r0]
_081DC1F0:
	cmp r6, #2
	beq _081DC234
	cmp r6, #2
	ble _081DC1FE
	cmp r6, #3
	beq _081DC264
	b _081DC2D4
_081DC1FE:
	cmp r6, #0
	blt _081DC2D4
	ldr r0, _081DC230 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #1
	beq _081DC2D4
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #1
	bl Textbox_LookupString
	bl FUN_08049e30
	movs r0, #1
	strb r0, [r5]
	b _081DC2D4
	.align 2, 0
_081DC230: .4byte 0x000003D1
_081DC234:
	ldr r0, _081DC260 @ =0x000003D1
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #2
	beq _081DC2D4
	bl FUN_08049e5c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #2
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r6, [r5]
	b _081DC2D4
	.align 2, 0
_081DC260: .4byte 0x000003D1
_081DC264:
	movs r0, #0xf3
	lsls r0, r0, #2
	adds r5, r4, r0
	adds r0, #6
	adds r1, r4, r0
	ldr r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	beq _081DC2A4
	bl FUN_08049e5c
	ldr r1, [r5]
	movs r0, #0
	bl FUN_08049e6c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl FUN_08049e30
	ldr r1, _081DC2A0 @ =0x000003D1
	adds r0, r4, r1
	strb r6, [r0]
	b _081DC2D4
	.align 2, 0
_081DC2A0: .4byte 0x000003D1
_081DC2A4:
	ldr r0, _081DC2DC @ =0x000003D1
	adds r7, r4, r0
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #3
	beq _081DC2D4
	bl FUN_08049e5c
	ldr r1, [r5]
	movs r0, #0
	bl FUN_08049e6c
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	bl VM_ParseStringRef
	adds r0, #3
	bl Textbox_LookupString
	bl FUN_08049e30
	strb r6, [r7]
_081DC2D4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC2DC: .4byte 0x000003D1

	thumb_func_start FUN_081dc2e0
FUN_081dc2e0: @ 0x081DC2E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08049e5c
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	adds r0, r4, #0
	bl FUN_081dbe68
	movs r0, #2
	bl FUN_081df95c
	ldr r0, _081DC328 @ =0x000003DA
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DC322
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081DC322:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC328: .4byte 0x000003DA

	thumb_func_start FUN_081dc32c
FUN_081dc32c: @ 0x081DC32C
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xf6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DC348
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_081DC348:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dc350
FUN_081dc350: @ 0x081DC350
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DC36C
	ldr r1, _081DC388 @ =0x000003D6
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DC36C:
	ldr r0, _081DC388 @ =0x000003D6
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0xa
	bne _081DC37C
	adds r0, r3, #0
	bl FUN_081dc2e0
_081DC37C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC388: .4byte 0x000003D6

	thumb_func_start FUN_081dc38c
FUN_081dc38c: @ 0x081DC38C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xf5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081DC3F2
	ldr r2, _081DC42C @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, [r5, #0x18]
	movs r0, #3
	movs r2, #7
	bl FUN_0822c398
	movs r0, #0
	str r0, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	movs r4, #0
	movs r6, #3
_081DC3C4:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r6, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC3C4
	ldr r3, _081DC430 @ =0x000003D6
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	movs r4, #0xf5
	lsls r4, r4, #2
	adds r0, r5, r4
	strb r2, [r0]
_081DC3F2:
	bl FUN_0823812c
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	ldr r3, _081DC434 @ =0x03002C68
	ldr r0, [r3]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #0
	beq _081DC40C
	ldrh r2, [r0, #0x1a]
_081DC40C:
	movs r4, #0xf3
	lsls r4, r4, #2
	adds r0, r5, r4
	str r2, [r0]
	movs r4, #0
	adds r2, r1, #0
	movs r0, #0xeb
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r6, #0
_081DC420:
	ldr r0, [r2]
	cmp r0, #0
	bge _081DC438
	strb r6, [r1]
	b _081DC44A
	.align 2, 0
_081DC42C: .4byte 0x000003D1
_081DC430: .4byte 0x000003D6
_081DC434: .4byte 0x03002C68
_081DC438:
	ldr r0, [r3]
	cmp r0, #0
	bne _081DC442
	movs r0, #0
	b _081DC448
_081DC442:
	adds r0, #0x68
	adds r0, r0, r4
	ldrb r0, [r0]
_081DC448:
	strb r0, [r1]
_081DC44A:
	adds r1, #4
	adds r4, #1
	cmp r4, #3
	ble _081DC420
	adds r0, r5, #0
	bl FUN_081dbea0
	adds r0, r5, #0
	bl FUN_081dba78
	adds r0, r5, #0
	bl FUN_081dc100
	movs r1, #0xf3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _081DC484 @ =0x000003D2
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _081DC488 @ =0x000003D6
	adds r1, r5, r3
	ldrh r0, [r1]
	cmp r0, #0x3b
	bhi _081DC48C
	adds r0, #1
	strh r0, [r1]
	b _081DC524
	.align 2, 0
_081DC484: .4byte 0x000003D2
_081DC488: .4byte 0x000003D6
_081DC48C:
	ldr r0, _081DC4A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DC4A4
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #1
	bne _081DC4A4
	movs r0, #1
	b _081DC4A6
	.align 2, 0
_081DC4A0: .4byte 0x03002C68
_081DC4A4:
	movs r0, #0
_081DC4A6:
	cmp r0, #0
	bne _081DC506
	ldr r0, _081DC4DC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081DC4E4
	ldr r1, _081DC4E0 @ =FUN_081dc350
	movs r2, #1
	movs r4, #0xef
	lsls r4, r4, #2
	adds r0, r5, r4
	str r1, [r0]
	movs r1, #0xf5
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	movs r3, #0xf4
	lsls r3, r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DC524
	.align 2, 0
_081DC4DC: .4byte 0x030044E0
_081DC4E0: .4byte FUN_081dc350
_081DC4E4:
	movs r4, #0
	movs r5, #3
_081DC4E8:
	adds r0, r4, #0
	adds r0, #0x19
	adds r1, r4, #0
	adds r1, #0x16
	str r1, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC4E8
	b _081DC524
_081DC506:
	movs r4, #0
	movs r6, #1
	movs r5, #3
_081DC50C:
	adds r0, r4, #0
	adds r0, #0x19
	str r6, [sp]
	str r5, [sp, #4]
	movs r1, #0x10
	movs r2, #1
	movs r3, #1
	bl FUN_080e1238
	adds r4, #1
	cmp r4, #4
	ble _081DC50C
_081DC524:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start LinkBattleLobby_Update
LinkBattleLobby_Update: @ 0x081DC52C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DC548
	bl FUN_08049fa8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DC55C
_081DC548:
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DC55A
	adds r0, r4, #0
	bl _call_via_r1
_081DC55A:
	movs r0, #1
_081DC55C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start LinkBattleLobby_Destroy
LinkBattleLobby_Destroy: @ 0x081DC564
	push {lr}
	bl FUN_081dbe84
	ldr r1, _081DC578 @ =0x030001A8
	movs r0, #0
	str r0, [r1]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081DC578: .4byte 0x030001A8

	thumb_func_start LinkBattleLobby_Init
LinkBattleLobby_Init: @ 0x081DC57C
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DC5A2
	bl FUN_0823d340
	movs r2, #0xf0
	lsls r2, r2, #2
	adds r1, r5, r2
	str r0, [r1]
	cmp r0, #0
	bne _081DC5A2
	movs r0, #1
	rsbs r0, r0, #0
	b _081DC622
_081DC5A2:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081DC62C @ =0x000003DA
	adds r1, r5, r2
	movs r4, #0
	strh r0, [r1]
	movs r0, #0
	bl ClearBGTilemapBuffer
	adds r0, r5, #0
	bl FUN_081db9f4
	adds r0, r5, #0
	bl FUN_081dbc14
	adds r0, r5, #0
	bl FUN_081dbc60
	adds r0, r5, #0
	bl FUN_081dbd74
	adds r0, r5, #0
	bl FUN_081dbce4
	adds r0, r5, #0
	bl FUN_081dba54
	ldr r1, _081DC630 @ =FUN_081dc38c
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xf4
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081DC61C
	movs r0, #4
	str r0, [sp]
	ldr r0, _081DC634 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_081DC61C:
	ldr r0, _081DC638 @ =0x030001A8
	str r5, [r0]
	movs r0, #1
_081DC622:
	add sp, #0xc
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081DC62C: .4byte 0x000003DA
_081DC630: .4byte FUN_081dc38c
_081DC634: .4byte 0x0000FFFF
_081DC638: .4byte 0x030001A8

	thumb_func_start LinkBattleLobby_Create
LinkBattleLobby_Create: @ 0x081DC63C
	push {r4, lr}
	ldr r0, _081DC674 @ =0x030001A8
	ldr r0, [r0]
	cmp r0, #0
	bne _081DC682
	movs r1, #0xf7
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DC680
	ldr r1, _081DC678 @ =LinkBattleLobby_Update
	ldr r2, _081DC67C @ =LinkBattleLobby_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl LinkBattleLobby_Init
	cmp r0, #0
	bge _081DC680
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DC682
	.align 2, 0
_081DC674: .4byte 0x030001A8
_081DC678: .4byte LinkBattleLobby_Update
_081DC67C: .4byte LinkBattleLobby_Destroy
_081DC680:
	adds r0, r4, #0
_081DC682:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081dc688
FUN_081dc688: @ 0x081DC688
	ldr r1, _081DC690 @ =0x030001A8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081DC690: .4byte 0x030001A8

	thumb_func_start FUN_081dc694
FUN_081dc694: @ 0x081DC694
	push {r4, lr}
	ldr r4, _081DC6CC @ =0x030001A8
	ldr r0, [r4]
	cmp r0, #0
	beq _081DC6C4
	bl FUN_081dbe68
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	bl FUN_08049e5c
	ldr r0, [r4]
	bl KillEntity
_081DC6C4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DC6CC: .4byte 0x030001A8
