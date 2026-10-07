	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x54
	bl GetEntityC9BC
	str r0, [sp, #0x24]
	cmp r0, #0
	beq _0800DBB8
	ldr r0, [sp, #0x24]
	bl EntityC9BC_FindFreeElem
	adds r5, r0, #0
	cmp r5, #0
	beq _0800DBB8
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetNamedArgValue
	mov r8, r0
	ldr r0, [sp, #0x24]
	mov r1, r8
	bl EntityC9BC_FindElemById
	cmp r0, #0
	beq _0800DBBE
_0800DBB8:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800E0C0
_0800DBBE:
	movs r0, #0x61
	movs r1, #0
	bl VM_GetNamedArgValue
	strb r0, [r5, #2]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0800DBEE
	movs r0, #1
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	bne _0800DBEE
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800DBE4
	movs r2, #1
	b _0800DBF0
_0800DBE4:
	movs r0, #4
	ands r1, r0
	movs r2, #6
	cmp r1, #0
	beq _0800DBF0
_0800DBEE:
	movs r2, #0
_0800DBF0:
	movs r0, #0
	strb r2, [r5, #3]
	str r0, [r5, #4]
	movs r0, #1
	strb r0, [r5, #1]
	movs r0, #0x70
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800DC40
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0800DC38 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0800DC3C @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _0800DC4A
	.align 2, 0
_0800DC38: .4byte 0xFFFF0000
_0800DC3C: .4byte 0x0000FFFF
_0800DC40:
	ldr r1, _0800DCA0 @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_0800DC4A:
	ldr r0, _0800DCA4 @ =0xFFFFFF00
	adds r3, r0, #0
	add r0, sp, #0xc
	ldrh r1, [r0]
	ands r1, r3
	movs r0, #0x80
	orrs r1, r0
	ldr r2, _0800DCA0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	ands r1, r3
	movs r0, #0x80
	orrs r1, r0
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r6, sp, #0xc
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800DC9C
	cmp r1, #0
	blt _0800DC9C
	ldr r0, _0800DCA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800DC9C
	ldr r0, _0800DCAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800DCB0
_0800DC9C:
	movs r4, #0
	b _0800DCBE
	.align 2, 0
_0800DCA0: .4byte 0xFFFF0000
_0800DCA4: .4byte 0xFFFFFF00
_0800DCA8: .4byte 0x030046A8
_0800DCAC: .4byte 0x030046AC
_0800DCB0:
	ldr r0, _0800DCD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800DCBE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0800DCD4
	adds r0, #4
	b _0800DCE0
	.align 2, 0
_0800DCD0: .4byte 0x030046A4
_0800DCD4:
	ldr r0, _0800DCF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800DCE0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0800DCF8
	cmp r2, #2
	beq _0800DCFC
	b _0800DD00
	.align 2, 0
_0800DCF4: .4byte 0x030046A4
_0800DCF8:
	ldrb r0, [r6, #4]
	b _0800DCFE
_0800DCFC:
	ldrb r0, [r6]
_0800DCFE:
	subs r1, r1, r0
_0800DD00:
	add r0, sp, #0xc
	strh r1, [r0, #2]
	movs r0, #0x50
	movs r1, #0
	bl VM_GetNamedArgValue
	str r0, [r5, #8]
	movs r0, #0x52
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _0800DD8A
	adds r6, r5, #0
	adds r6, #0xc
	adds r1, r5, #0
	adds r1, #0x42
	str r1, [sp, #0x48]
	adds r2, r5, #0
	adds r2, #0x30
	str r2, [sp, #0x38]
	adds r3, r5, #0
	adds r3, #0x31
	str r3, [sp, #0x3c]
	adds r4, r5, #0
	adds r4, #0x40
	str r4, [sp, #0x40]
	adds r0, r5, #0
	adds r0, #0x41
	str r0, [sp, #0x44]
	adds r1, #0x66
	str r1, [sp, #0x50]
	adds r7, r5, #0
	adds r7, #0x8c
	adds r2, #0xc0
	str r2, [sp, #0x28]
	movs r3, #0xd4
	adds r3, r3, r5
	mov sb, r3
	movs r4, #0x86
	lsls r4, r4, #1
	adds r4, r5, r4
	str r4, [sp, #0x2c]
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	mov r1, r8
	lsls r1, r1, #0x10
	str r1, [sp, #0x34]
	subs r2, #0xa0
	str r2, [sp, #0x4c]
	add r3, sp, #0x14
	mov r8, r3
	mov r4, sp
	adds r4, #0x1c
	str r4, [sp, #0x30]
	adds r4, r6, #0
_0800DD70:
	bl VM_GetPC
	cmp r0, #0
	beq _0800DD7C
	bl VM_GetValue
_0800DD7C:
	str r0, [r4]
	adds r4, #4
	adds r0, r6, #0
	adds r0, #0xc
	cmp r4, r0
	ble _0800DD70
	b _0800DDEC
_0800DD8A:
	adds r0, r5, #0
	adds r0, #0x42
	str r0, [sp, #0x48]
	adds r1, r5, #0
	adds r1, #0x30
	str r1, [sp, #0x38]
	adds r2, r5, #0
	adds r2, #0x31
	str r2, [sp, #0x3c]
	adds r3, r5, #0
	adds r3, #0x40
	str r3, [sp, #0x40]
	adds r4, r5, #0
	adds r4, #0x41
	str r4, [sp, #0x44]
	adds r0, #0x66
	str r0, [sp, #0x50]
	adds r7, r5, #0
	adds r7, #0x8c
	adds r1, #0xc0
	str r1, [sp, #0x28]
	movs r2, #0xd4
	adds r2, r2, r5
	mov sb, r2
	movs r3, #0x86
	lsls r3, r3, #1
	adds r3, r5, r3
	str r3, [sp, #0x2c]
	movs r4, #0x48
	adds r4, r4, r5
	mov sl, r4
	mov r0, r8
	lsls r0, r0, #0x10
	str r0, [sp, #0x34]
	subs r1, #0xa0
	str r1, [sp, #0x4c]
	add r2, sp, #0x14
	mov r8, r2
	mov r3, sp
	adds r3, #0x1c
	str r3, [sp, #0x30]
	subs r1, #0x44
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x18
_0800DDE4:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0800DDE4
_0800DDEC:
	movs r4, #0
	str r4, [r5, #0x1c]
	str r4, [r5, #0x20]
	str r4, [r5, #0x24]
	movs r0, #0x66
	movs r1, #0
	bl VM_GetNamedArgValue
	strh r0, [r5, #0x28]
	strh r4, [r5, #0x2a]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetNamedArgValue
	cmp r0, #0
	beq _0800DE12
	add r0, sp, #0xc
	bl GetMapAreaAt
_0800DE12:
	strh r0, [r5, #0x2c]
	ldrb r0, [r5, #2]
	cmp r0, #0
	bne _0800DE1E
	movs r0, #0x78
	b _0800DE44
_0800DE1E:
	movs r0, #8
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800DE2C
	movs r0, #0x7b
	b _0800DE44
_0800DE2C:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800DE38
	movs r0, #0x7c
	b _0800DE44
_0800DE38:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800DE44
	movs r0, #0x79
_0800DE44:
	strh r0, [r5, #0x2e]
	movs r1, #1
	rsbs r1, r1, #0
	movs r0, #0x46
	bl VM_GetNamedArgValue
	adds r2, r0, #0
	ldr r4, [sp, #0x48]
	strh r2, [r4]
	movs r0, #1
	ldrb r1, [r5, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800DE64
	strh r2, [r5, #0x38]
	b _0800DE66
_0800DE64:
	strh r1, [r5, #0x38]
_0800DE66:
	movs r0, #0
	movs r2, #0
	strh r2, [r5, #0x3a]
	ldr r1, [sp, #0x38]
	strb r0, [r1]
	ldr r3, [sp, #0x3c]
	strb r0, [r3]
	add r0, sp, #0xc
	ldrh r0, [r0, #2]
	strh r0, [r5, #0x32]
	movs r1, #0x28
	strh r1, [r5, #0x36]
	ldrb r0, [r5, #3]
	cmp r0, #1
	beq _0800DE88
	cmp r0, #3
	bne _0800DE8C
_0800DE88:
	strh r2, [r5, #0x34]
	b _0800DE8E
_0800DE8C:
	strh r1, [r5, #0x34]
_0800DE8E:
	movs r0, #0x6c
	movs r1, #1
	bl VM_GetNamedArgValue
	movs r1, #0
	strh r0, [r5, #0x3e]
	ldr r4, [sp, #0x40]
	strb r1, [r4]
	ldr r0, [sp, #0x44]
	strb r1, [r0]
	ldr r6, [sp, #0x50]
	ldr r1, _0800DEC0 @ =0x0000BCA8
	adds r0, r7, #0
	bl Video_GetAuxSprite
	ldrh r1, [r5, #0x2e]
	adds r0, r7, #0
	bl Video_SetAuxSpritePltt
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800DEC4
	ldr r0, [sp, #0x24]
	adds r0, #0x34
	b _0800DECC
	.align 2, 0
_0800DEC0: .4byte 0x0000BCA8
_0800DEC4:
	cmp r0, #0x7a
	bne _0800DECE
	ldr r0, [sp, #0x24]
	adds r0, #0x54
_0800DECC:
	str r0, [r7, #0xc]
_0800DECE:
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0
	strh r0, [r6, #0x10]
	add r4, sp, #0xc
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldrh r0, [r5, #0x34]
	ldrh r1, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
	ldr r6, [sp, #0x28]
	ldr r1, _0800DF3C @ =0x0000BCA8
	mov r0, sb
	bl Video_GetAuxSprite
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r6, #0
	mov r1, sb
	bl AuxSprite_Add
	movs r0, #1
	strh r0, [r6, #0x10]
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	add r0, sp, #0xc
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800DF38
	cmp r1, #0
	blt _0800DF38
	ldr r0, _0800DF40 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800DF38
	ldr r0, _0800DF44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800DF48
_0800DF38:
	movs r6, #0
	b _0800DF56
	.align 2, 0
_0800DF3C: .4byte 0x0000BCA8
_0800DF40: .4byte 0x030046A8
_0800DF44: .4byte 0x030046AC
_0800DF48:
	ldr r0, _0800DF68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_0800DF56:
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0800DF6C
	adds r0, #4
	b _0800DF78
	.align 2, 0
_0800DF68: .4byte 0x030046A4
_0800DF6C:
	ldr r0, _0800E0D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800DF78:
	ldrb r0, [r0]
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0xe
	bgt _0800DF84
	adds r3, #1
_0800DF84:
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r0, #0xff
	str r0, [sp]
	movs r0, #9
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Map_AddTileOverride
	ldrh r0, [r4]
	movs r6, #2
	movs r7, #0
	orrs r0, r6
	strh r0, [r4]
	mov r4, sl
	ldr r2, [sp, #0x34]
	lsrs r1, r2, #0x10
	movs r0, #7
	str r0, [sp]
	str r5, [sp, #4]
	adds r0, r4, #0
	add r2, sp, #0xc
	movs r3, #0
	bl Mover_Init
	adds r0, r4, #0
	ldr r1, [sp, #0x50]
	bl Mover_SetAuxSprite
	ldrb r0, [r5, #3]
	cmp r0, #1
	beq _0800DFD4
	adds r1, r5, #0
	adds r1, #0x4a
	ldrh r0, [r1]
	orrs r0, r6
	strh r0, [r1]
_0800DFD4:
	mov r3, sl
	ldrh r1, [r3]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r1, [r0]
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [sp, #0x4c]
	str r2, [r0]
	ldr r2, _0800E0D4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800E0D8 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	mov r4, r8
	ldr r0, [r4, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r4, #4]
	str r1, [sp, #0x1c]
	ldr r1, [sp, #0x30]
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r6, r5, r2
	mov r3, sl
	ldrh r1, [r3]
	ldr r2, _0800E0DC @ =0x00004041
	movs r0, #0x10
	str r0, [sp]
	str r4, [sp, #4]
	ldr r4, [sp, #0x30]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r6, #0
	ldr r1, [sp, #0x4c]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0800E0E0 @ =FUN_0800cbd0
	adds r0, r6, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r6, #0
	bl Hitbox_Register
	movs r1, #0x90
	add r0, sp, #0x14
	strh r1, [r0]
	movs r0, #0x80
	mov r2, r8
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r6, r5, r3
	mov r4, sl
	ldrh r1, [r4]
	ldr r2, _0800E0E4 @ =0x00002801
	movs r4, #1
	str r4, [sp]
	mov r0, r8
	str r0, [sp, #4]
	ldr r3, [sp, #0x30]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r6, #0
	ldr r1, [sp, #0x4c]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0800E0E8 @ =nop_0800cc04
	adds r0, r6, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r6, #0
	movs r1, #0x32
	movs r2, #0
	bl Hitbox_SetPower
	ldr r0, _0800E0EC @ =0x00010100
	str r0, [r6, #0x34]
	movs r0, #4
	str r0, [r6, #0x38]
	ldrh r0, [r5, #0x28]
	ands r4, r0
	cmp r4, #0
	bne _0800E0BA
	mov r0, sl
	bl FUN_08002a48
	cmp r0, #0
	bge _0800E0BA
	ldrh r0, [r5, #0x28]
	movs r1, #1
	orrs r0, r1
	strh r0, [r5, #0x28]
_0800E0BA:
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
_0800E0C0:
	add sp, #0x54
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800E0D0: .4byte 0x030046A4
_0800E0D4: .4byte 0xFFFF0000
_0800E0D8: .4byte 0x0000FFFF
_0800E0DC: .4byte 0x00004041
_0800E0E0: .4byte FUN_0800cbd0
_0800E0E4: .4byte 0x00002801
_0800E0E8: .4byte nop_0800cc04
_0800E0EC: .4byte 0x00010100
