	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov r8, r1
	mov r3, r8
	adds r3, #0x4c
	mov r0, r8
	ldrh r1, [r0, #0x20]
	ldrh r2, [r3, #0x1c]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08056B84 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r4, r8
	ldrh r0, [r4, #0x24]
	ldrh r3, [r3, #0x20]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r4, #0x20
	str r4, [sp, #0x18]
	movs r0, #0x68
	add r0, r8
	mov sl, r0
	mov sb, sp
	add r7, sp, #8
	movs r1, #0
	str r1, [sp, #0x1c]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sb
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08056B7E
	cmp r1, #0
	blt _08056B7E
	ldr r0, _08056B88 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08056B7E
	ldr r0, _08056B8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08056B90
_08056B7E:
	movs r4, #0
	b _08056B9E
	.align 2, 0
_08056B84: .4byte 0xFFFF0000
_08056B88: .4byte 0x030046A8
_08056B8C: .4byte 0x030046AC
_08056B90:
	ldr r0, _08056BB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08056B9E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08056BB4
	adds r0, #4
	b _08056BC0
	.align 2, 0
_08056BB0: .4byte 0x030046A4
_08056BB4:
	ldr r0, _08056BF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08056BC0:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08056C5E
	mov r4, sb
	ldrh r0, [r4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08056BF0
	cmp r1, #0
	blt _08056BF0
	ldr r0, _08056BF8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08056BF0
	ldr r0, _08056BFC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08056C00
_08056BF0:
	movs r4, #0
	b _08056C0E
	.align 2, 0
_08056BF4: .4byte 0x030046A4
_08056BF8: .4byte 0x030046A8
_08056BFC: .4byte 0x030046AC
_08056C00:
	ldr r0, _08056C20 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08056C0E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08056C24
	adds r0, #4
	b _08056C30
	.align 2, 0
_08056C20: .4byte 0x030046A4
_08056C24:
	ldr r0, _08056C44 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08056C30:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08056C48
	cmp r2, #2
	beq _08056C4E
	b _08056C54
	.align 2, 0
_08056C44: .4byte 0x030046A4
_08056C48:
	mov r2, sb
	ldrb r0, [r2, #4]
	b _08056C52
_08056C4E:
	mov r3, sb
	ldrb r0, [r3]
_08056C52:
	subs r1, r1, r0
_08056C54:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0
	cmp r1, r0
	beq _08056C60
_08056C5E:
	movs r2, #1
_08056C60:
	cmp r2, #0
	bne _08056C66
	b _08056F7A
_08056C66:
	mov r4, sl
	ldrh r0, [r4]
	ldr r3, _08056CC4 @ =0xFFFFFF00
	adds r1, r3, #0
	ands r1, r0
	ldr r2, _08056CC8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r5
	adds r5, r0, #0
	orrs r5, r1
	ldrh r0, [r4, #4]
	ands r3, r0
	adds r0, r2, #0
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r3
	adds r3, r5, #0
	adds r1, r3, #0
	adds r1, #0xff
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	ldr r4, [sp, #0x20]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x20]
	adds r0, r6, #0
	adds r0, #0xff
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x24]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x24]
	mov r2, sb
	ldrh r1, [r2]
	strh r1, [r7]
	ldrh r0, [r2, #4]
	strh r0, [r7, #4]
	lsls r1, r1, #0x10
	lsls r3, r3, #0x10
	asrs r2, r1, #0x10
	cmp r1, r3
	bge _08056CCC
	strh r5, [r7]
	b _08056CDC
	.align 2, 0
_08056CC4: .4byte 0xFFFFFF00
_08056CC8: .4byte 0xFFFF0000
_08056CCC:
	ldr r3, [sp, #0x20]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	ble _08056CDC
	mov r4, sp
	ldrh r4, [r4, #0x20]
	strh r4, [r7]
_08056CDC:
	movs r0, #4
	ldrsh r2, [r7, r0]
	adds r3, r6, #0
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bge _08056CEE
	strh r3, [r7, #4]
	b _08056CFC
_08056CEE:
	mov r3, sp
	ldrh r1, [r3, #0x24]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	ble _08056CFC
	strh r1, [r7, #4]
_08056CFC:
	mov r4, sb
	ldrh r1, [r4]
	ldrh r0, [r7]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08056DB8 @ =0xFFFF0000
	adds r0, r2, #0
	ldr r3, [sp, #0x28]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x28]
	ldrh r1, [r4, #4]
	ldrh r0, [r7, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	ldr r4, [sp, #0x2c]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x2c]
	mov r0, sp
	ldrh r1, [r0, #0x28]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _08056D3C
	rsbs r0, r1, #0
	ldr r1, [sp, #0x18]
	strh r0, [r1]
	movs r3, #1
	str r3, [sp, #0x1c]
_08056D3C:
	mov r4, sp
	ldrh r1, [r4, #0x2c]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _08056D50
	rsbs r0, r1, #0
	ldr r1, [sp, #0x18]
	strh r0, [r1, #4]
	movs r3, #1
	str r3, [sp, #0x1c]
_08056D50:
	ldr r4, [sp, #0x1c]
	cmp r4, #0
	bne _08056D58
	b _08056F7A
_08056D58:
	mov r0, sp
	ldrh r1, [r0, #8]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	add r4, sp, #8
	ldrh r1, [r4, #4]
	add r3, sp, #0x10
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	mov r2, r8
	ldrh r1, [r2, #0x20]
	ldrh r0, [r4]
	adds r2, r1, r0
	mov r0, sp
	strh r2, [r0]
	ldrh r2, [r4, #4]
	adds r1, r1, r2
	strh r1, [r0, #4]
	movs r0, #0x20
	add r8, r0
	adds r7, r3, #0
	mov r5, sp
	adds r6, r4, #0
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08056DB2
	cmp r1, #0
	blt _08056DB2
	ldr r0, _08056DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08056DB2
	ldr r0, _08056DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08056DC4
_08056DB2:
	movs r4, #0
	b _08056DD2
	.align 2, 0
_08056DB8: .4byte 0xFFFF0000
_08056DBC: .4byte 0x030046A8
_08056DC0: .4byte 0x030046AC
_08056DC4:
	ldr r0, _08056DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08056DD2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08056DE8
	adds r0, #4
	b _08056DF4
	.align 2, 0
_08056DE4: .4byte 0x030046A4
_08056DE8:
	ldr r0, _08056E28 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08056DF4:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08056E8E
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08056E22
	cmp r1, #0
	blt _08056E22
	ldr r0, _08056E2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08056E22
	ldr r0, _08056E30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08056E34
_08056E22:
	movs r4, #0
	b _08056E42
	.align 2, 0
_08056E28: .4byte 0x030046A4
_08056E2C: .4byte 0x030046A8
_08056E30: .4byte 0x030046AC
_08056E34:
	ldr r0, _08056E54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08056E42:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08056E58
	adds r0, #4
	b _08056E64
	.align 2, 0
_08056E54: .4byte 0x030046A4
_08056E58:
	ldr r0, _08056E78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08056E64:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08056E7C
	cmp r2, #2
	beq _08056E80
	b _08056E84
	.align 2, 0
_08056E78: .4byte 0x030046A4
_08056E7C:
	ldrb r0, [r5, #4]
	b _08056E82
_08056E80:
	ldrb r0, [r5]
_08056E82:
	subs r1, r1, r0
_08056E84:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0
	cmp r1, r0
	beq _08056E90
_08056E8E:
	movs r2, #1
_08056E90:
	cmp r2, #0
	beq _08056F7A
	ldrh r0, [r7]
	ldr r3, _08056EFC @ =0xFFFFFF00
	adds r1, r3, #0
	ands r1, r0
	ldr r2, _08056F00 @ =0xFFFF0000
	adds r0, r2, #0
	ldr r4, [sp, #0x30]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x30]
	ldrh r0, [r7, #4]
	ands r3, r0
	adds r0, r2, #0
	ldr r1, [sp, #0x34]
	ands r0, r1
	orrs r0, r3
	str r0, [sp, #0x34]
	mov r4, sp
	ldrh r3, [r4, #0x30]
	adds r1, r3, #0
	adds r1, #0xff
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0
	ldr r4, [sp, #0x38]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x38]
	ldr r0, [sp, #0x34]
	adds r0, #0xff
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x3c]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x3c]
	ldrh r0, [r5]
	strh r0, [r6]
	ldrh r2, [r5, #4]
	strh r2, [r6, #4]
	lsls r1, r0, #0x10
	lsls r3, r3, #0x10
	asrs r5, r1, #0x10
	adds r4, r0, #0
	adds r7, r2, #0
	cmp r1, r3
	bge _08056F04
	mov r2, sp
	ldrh r2, [r2, #0x30]
	strh r2, [r6]
	b _08056F14
	.align 2, 0
_08056EFC: .4byte 0xFFFFFF00
_08056F00: .4byte 0xFFFF0000
_08056F04:
	ldr r3, [sp, #0x38]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r5, r0
	ble _08056F14
	mov r0, sp
	ldrh r0, [r0, #0x38]
	strh r0, [r6]
_08056F14:
	movs r1, #4
	ldrsh r2, [r6, r1]
	mov r0, sp
	ldrh r3, [r0, #0x34]
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	bge _08056F28
	strh r3, [r6, #4]
	b _08056F36
_08056F28:
	mov r3, sp
	ldrh r1, [r3, #0x3c]
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	cmp r2, r0
	ble _08056F36
	strh r1, [r6, #4]
_08056F36:
	ldrh r1, [r6]
	subs r1, r4, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08056F8C @ =0xFFFF0000
	adds r0, r2, #0
	ldr r4, [sp, #0x40]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #0x40]
	ldrh r0, [r6, #4]
	subs r0, r7, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x44]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x44]
	add r2, sp, #0x40
	ldrh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _08056F6A
	rsbs r0, r1, #0
	mov r3, r8
	strh r0, [r3]
_08056F6A:
	add r4, sp, #0x44
	ldrh r1, [r4]
	lsls r0, r1, #0x10
	cmp r0, #0
	beq _08056F7A
	rsbs r0, r1, #0
	mov r1, r8
	strh r0, [r1, #4]
_08056F7A:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08056F8C: .4byte 0xFFFF0000
