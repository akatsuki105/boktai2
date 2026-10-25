	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	str r7, [sp, #0x10]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r0, r0, r7
	mov sb, r0
	adds r1, r7, #0
	adds r1, #0xa8
	ldrb r0, [r1]
	cmp r0, #0
	beq _081FBB36
	movs r0, #0
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	movs r0, #1
	b _081FBB38
_081FBB36:
	movs r0, #0
_081FBB38:
	cmp r0, #0
	beq _081FBC0E
	mov r0, sb
	bl NestedState_Reset0
	ldr r3, _081FBC24 @ =0x0203B400
	ldr r2, _081FBC28 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FBC2C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r4, [r0]
	movs r0, #1
	ands r4, r0
	movs r6, #0
	mov r8, r3
	movs r1, #0x81
	lsls r1, r1, #4
	adds r5, r7, r1
	movs r3, #0
_081FBB66:
	strb r3, [r5]
	strb r4, [r5, #8]
	adds r4, #1
	adds r0, r6, #5
	cmp r4, r0
	bge _081FBB8C
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081FBC2C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _081FBB8C
	adds r4, #1
_081FBB8C:
	adds r5, #1
	adds r6, #1
	cmp r6, #7
	ble _081FBB66
	movs r6, #0
	ldr r2, _081FBC28 @ =0x030046B8
	mov r8, r2
	ldr r3, _081FBC2C @ =0x000003FF
	mov sl, r3
_081FBB9E:
	adds r6, #1
_081FBBA0:
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _081FBC24 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #8
	bl Mod
	adds r5, r0, #0
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _081FBC24 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #8
	bl Mod
	adds r4, r0, #0
	cmp r5, r4
	beq _081FBBA0
	ldr r0, _081FBC30 @ =0x00000818
	adds r1, r7, r0
	adds r2, r1, r5
	movs r3, #0
	ldrsb r3, [r2, r3]
	adds r1, r1, r4
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	movs r2, #0x81
	lsls r2, r2, #4
	adds r1, r7, r2
	adds r2, r1, r5
	movs r3, #0
	ldrsb r3, [r2, r3]
	adds r1, r1, r4
	ldrb r0, [r1]
	strb r0, [r2]
	strb r3, [r1]
	cmp r6, #7
	ble _081FBB9E
	ldr r3, _081FBC34 @ =0x00000838
	adds r1, r7, r3
	movs r0, #0
	strb r0, [r1]
_081FBC0E:
	mov r1, sb
	ldrb r0, [r1]
	cmp r0, #6
	bls _081FBC18
	b _081FC08E
_081FBC18:
	lsls r0, r0, #2
	ldr r1, _081FBC38 @ =_081FBC3C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081FBC24: .4byte 0x0203B400
_081FBC28: .4byte 0x030046B8
_081FBC2C: .4byte 0x000003FF
_081FBC30: .4byte 0x00000818
_081FBC34: .4byte 0x00000838
_081FBC38: .4byte _081FBC3C
_081FBC3C: @ jump table
	.4byte _081FBC58 @ case 0
	.4byte _081FBD2A @ case 1
	.4byte _081FBD88 @ case 2
	.4byte _081FBDC0 @ case 3
	.4byte _081FC020 @ case 4
	.4byte _081FC02E @ case 5
	.4byte _081FC084 @ case 6
_081FBC58:
	mov r2, sb
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FBD18
	movs r5, #0
	mov r6, sp
_081FBC64:
	movs r3, #0x81
	lsls r3, r3, #4
	adds r0, r7, r3
	adds r0, r0, r5
	ldrb r1, [r0]
	ldr r2, _081FBCA4 @ =0x00000818
	adds r0, r7, r2
	adds r0, r0, r5
	ldrb r2, [r0]
	mov r0, sp
	bl Map_GetPathNodePos
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081FBCA0
	cmp r1, #0
	blt _081FBCA0
	ldr r0, _081FBCA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FBCA0
	ldr r0, _081FBCAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FBCB0
_081FBCA0:
	movs r4, #0
	b _081FBCBE
	.align 2, 0
_081FBCA4: .4byte 0x00000818
_081FBCA8: .4byte 0x030046A8
_081FBCAC: .4byte 0x030046AC
_081FBCB0:
	ldr r0, _081FBCD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FBCBE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FBCD4
	adds r0, #4
	b _081FBCE0
	.align 2, 0
_081FBCD0: .4byte 0x030046A4
_081FBCD4:
	ldr r0, _081FBD10 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FBCE0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	lsls r0, r5, #2
	ldr r3, _081FBD14 @ =0x0000083C
	adds r4, r7, r3
	adds r4, r4, r0
	ldr r0, [r4]
	mov r1, sp
	bl FUN_08201054
	ldr r0, [r4]
	bl FUN_082010b4
	adds r5, #1
	cmp r5, #1
	ble _081FBC64
	movs r0, #1
	mov r1, sb
	str r0, [r1, #4]
	b _081FBD1E
	.align 2, 0
_081FBD10: .4byte 0x030046A4
_081FBD14: .4byte 0x0000083C
_081FBD18:
	adds r0, #1
	mov r2, sb
	str r0, [r2, #4]
_081FBD1E:
	mov r3, sb
	ldr r0, [r3, #4]
	cmp r0, #0x96
	bhi _081FBD28
	b _081FC08E
_081FBD28:
	b _081FC070
_081FBD2A:
	mov r1, sb
	ldr r0, [r1, #4]
	cmp r0, #0
	bne _081FBD5C
	ldr r2, _081FBD54 @ =0x0000083C
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r2, _081FBD58 @ =0x000006DB
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
	mov r0, sb
	str r1, [r0, #4]
	b _081FBD62
	.align 2, 0
_081FBD54: .4byte 0x0000083C
_081FBD58: .4byte 0x000006DB
_081FBD5C:
	adds r0, #1
	mov r1, sb
	str r0, [r1, #4]
_081FBD62:
	ldr r2, _081FBD80 @ =0x0000083C
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r3, _081FBD84 @ =0x000006D9
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FBD74
	b _081FC08E
_081FBD74:
	movs r1, #0x84
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	adds r0, r0, r3
	b _081FC06A
	.align 2, 0
_081FBD80: .4byte 0x0000083C
_081FBD84: .4byte 0x000006D9
_081FBD88:
	mov r2, sb
	ldr r0, [r2, #4]
	cmp r0, #0
	bne _081FBDA8
	ldr r3, _081FBDB8 @ =0x0000083C
	adds r0, r7, r3
	ldr r0, [r0]
	ldr r2, _081FBDBC @ =0x000006DB
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	adds r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FBDA8:
	mov r1, sb
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #0x14
	bhi _081FBDB6
	b _081FC08E
_081FBDB6:
	b _081FC070
	.align 2, 0
_081FBDB8: .4byte 0x0000083C
_081FBDBC: .4byte 0x000006DB
_081FBDC0:
	mov r2, sb
	ldrb r1, [r2, #1]
	cmp r1, #1
	beq _081FBE10
	cmp r1, #1
	bgt _081FBDD2
	cmp r1, #0
	beq _081FBDE0
	b _081FC08E
_081FBDD2:
	cmp r1, #2
	bne _081FBDD8
	b _081FBFE0
_081FBDD8:
	cmp r1, #3
	bne _081FBDDE
	b _081FC070
_081FBDDE:
	b _081FC08E
_081FBDE0:
	mov r3, sb
	ldr r0, [r3, #8]
	cmp r0, #0
	beq _081FBDEA
	b _081FC08E
_081FBDEA:
	ldr r1, _081FBE08 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FBE0C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #2
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
	b _081FC00E
	.align 2, 0
_081FBE08: .4byte 0x0000083C
_081FBE0C: .4byte 0x000006DB
_081FBE10:
	mov r2, sb
	ldr r0, [r2, #8]
	cmp r0, #0
	bne _081FBE26
	str r1, [r2, #8]
	ldr r3, _081FBE64 @ =0x00000838
	adds r0, r7, r3
	movs r1, #2
	strb r1, [r0]
	movs r0, #0x1f
	str r0, [r2, #4]
_081FBE26:
	movs r0, #0
	str r0, [sp, #0x18]
	movs r1, #0
	str r1, [sp, #0x1c]
	mov r2, sp
	adds r2, #8
	str r2, [sp, #0x20]
	mov r8, r1
	movs r3, #1
	str r3, [sp, #0x14]
_081FBE3A:
	ldr r1, _081FBE68 @ =0x0000083C
	adds r0, r7, r1
	add r0, r8
	ldr r5, [r0]
	ldr r2, _081FBE6C @ =0x000006D9
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _081FBE4E
	b _081FBF9C
_081FBE4E:
	ldr r3, _081FBE70 @ =0x000006DC
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #2
	beq _081FBE7E
	cmp r0, #2
	bgt _081FBE74
	cmp r0, #1
	bne _081FBE62
	b _081FBF94
_081FBE62:
	b _081FBF9C
	.align 2, 0
_081FBE64: .4byte 0x00000838
_081FBE68: .4byte 0x0000083C
_081FBE6C: .4byte 0x000006D9
_081FBE70: .4byte 0x000006DC
_081FBE74:
	cmp r0, #3
	beq _081FBEA8
	cmp r0, #5
	beq _081FBECC
	b _081FBF9C
_081FBE7E:
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	bne _081FBE9E
	mov r1, sb
	ldr r0, [r1, #4]
	adds r0, #1
	str r0, [r1, #4]
	cmp r0, #0x1e
	bls _081FBE9E
	ldr r2, _081FBEA4 @ =0x000006DB
	adds r1, r5, r2
	movs r0, #3
	strb r0, [r1]
	ldr r3, [sp, #0x1c]
	mov r0, sb
	str r3, [r0, #4]
_081FBE9E:
	movs r1, #1
	str r1, [sp, #0x1c]
	b _081FBF9C
	.align 2, 0
_081FBEA4: .4byte 0x000006DB
_081FBEA8:
	ldr r2, _081FBEBC @ =0x00000838
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #7
	bhi _081FBEC4
	ldr r3, _081FBEC0 @ =0x000006DB
	adds r1, r5, r3
	movs r0, #5
	b _081FBF9A
	.align 2, 0
_081FBEBC: .4byte 0x00000838
_081FBEC0: .4byte 0x000006DB
_081FBEC4:
	ldr r0, [sp, #0x18]
	adds r0, #1
	str r0, [sp, #0x18]
	b _081FBF9C
_081FBECC:
	ldr r2, _081FBF1C @ =0x00000838
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #7
	bhi _081FBF9C
	adds r2, r0, #0
	movs r3, #0x81
	lsls r3, r3, #4
	adds r0, r7, r3
	adds r0, r0, r2
	ldrb r1, [r0]
	adds r3, #8
	adds r0, r7, r3
	adds r0, r0, r2
	ldrb r2, [r0]
	ldr r0, [sp, #0x20]
	bl Map_GetPathNodePos
	ldr r6, [sp, #0x20]
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sl, r6
	cmp r2, #0
	blt _081FBF18
	cmp r1, #0
	blt _081FBF18
	ldr r0, _081FBF20 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081FBF18
	ldr r0, _081FBF24 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081FBF28
_081FBF18:
	movs r4, #0
	b _081FBF36
	.align 2, 0
_081FBF1C: .4byte 0x00000838
_081FBF20: .4byte 0x030046A8
_081FBF24: .4byte 0x030046AC
_081FBF28:
	ldr r0, _081FBF48 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081FBF36:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081FBF4C
	adds r0, #4
	b _081FBF58
	.align 2, 0
_081FBF48: .4byte 0x030046A4
_081FBF4C:
	ldr r0, _081FBF84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081FBF58:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r6, #2]
	adds r0, r5, #0
	mov r1, sl
	bl FUN_08201054
	ldr r1, _081FBF88 @ =0x0000083C
	adds r0, r7, r1
	add r0, r8
	ldr r0, [r0]
	ldr r2, _081FBF8C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081FBF90 @ =0x00000838
	adds r1, r7, r3
	ldrb r0, [r1]
	adds r0, #1
	b _081FBF9A
	.align 2, 0
_081FBF84: .4byte 0x030046A4
_081FBF88: .4byte 0x0000083C
_081FBF8C: .4byte 0x000006DB
_081FBF90: .4byte 0x00000838
_081FBF94:
	ldr r0, _081FBFD8 @ =0x000006DB
	adds r1, r5, r0
	movs r0, #2
_081FBF9A:
	strb r0, [r1]
_081FBF9C:
	movs r1, #4
	add r8, r1
	ldr r2, [sp, #0x14]
	subs r2, #1
	str r2, [sp, #0x14]
	cmp r2, #0
	blt _081FBFAC
	b _081FBE3A
_081FBFAC:
	ldr r3, _081FBFDC @ =0x00000838
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #7
	bls _081FBFBC
	ldr r0, [sp, #0x18]
	cmp r0, #1
	bgt _081FBFCC
_081FBFBC:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [sp, #0x10]
	adds r0, #0x98
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081FC08E
_081FBFCC:
	mov r0, sb
	movs r1, #2
	bl NestedState_Set1
	b _081FC08E
	.align 2, 0
_081FBFD8: .4byte 0x000006DB
_081FBFDC: .4byte 0x00000838
_081FBFE0:
	mov r1, sb
	ldr r0, [r1, #8]
	cmp r0, #0
	bne _081FC002
	ldr r2, _081FC018 @ =0x0000083C
	adds r0, r7, r2
	ldr r0, [r0]
	ldr r2, _081FC01C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #5
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FC002:
	mov r1, sb
	ldr r0, [r1, #8]
	adds r0, #1
	str r0, [r1, #8]
	cmp r0, #0x1e
	bls _081FC08E
_081FC00E:
	mov r0, sb
	bl NestedState_Advance1
	b _081FC08E
	.align 2, 0
_081FC018: .4byte 0x0000083C
_081FC01C: .4byte 0x000006DB
_081FC020:
	mov r2, sb
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	cmp r0, #0x3c
	bls _081FC08E
	b _081FC070
_081FC02E:
	mov r3, sb
	ldr r0, [r3, #4]
	cmp r0, #0
	bne _081FC050
	ldr r1, _081FC078 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FC07C @ =0x000006DB
	adds r0, r0, r2
	movs r1, #5
	strb r1, [r0]
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
	strb r1, [r0]
_081FC050:
	ldr r1, _081FC078 @ =0x0000083C
	adds r0, r7, r1
	ldr r0, [r0]
	ldr r2, _081FC080 @ =0x000006D9
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FC08E
	movs r3, #0x84
	lsls r3, r3, #4
	adds r0, r7, r3
	ldr r0, [r0]
	adds r0, r0, r2
_081FC06A:
	ldrb r0, [r0]
	cmp r0, #0
	beq _081FC08E
_081FC070:
	mov r0, sb
	bl NestedState_Advance0
	b _081FC08E
	.align 2, 0
_081FC078: .4byte 0x0000083C
_081FC07C: .4byte 0x000006DB
_081FC080: .4byte 0x000006D9
_081FC084:
	movs r0, #0xfb
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
_081FC08E:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
