	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080569f4
FUN_080569f4: @ 0x080569F4
	mov ip, r0
	movs r1, #0x80
	lsls r1, r1, #1
	strh r1, [r0, #0x3c]
	strh r1, [r0, #0x3e]
	adds r0, #0x40
	movs r2, #0x80
	lsls r2, r2, #2
	strh r2, [r0]
	adds r0, #4
	movs r3, #0x80
	lsls r3, r3, #4
	strh r3, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	adds r0, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	movs r2, #0x90
	lsls r2, r2, #4
	strh r2, [r0]
	adds r0, #4
	strh r3, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r0, #2
	strh r2, [r0]
	bx lr

	thumb_func_start FUN_08056a34
FUN_08056a34: @ 0x08056A34
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r2, r0, #0
	adds r7, r1, #0
	ldr r1, _08056AD0 @ =0x00000EBC
	adds r2, r2, r1
	ldr r2, [r2]
	mov r8, r2
	movs r4, #0x2c
	add r4, r8
	mov ip, r4
	adds r6, r7, #0
	adds r6, #0x4c
	ldrh r4, [r6, #0x1c]
	ldr r5, _08056AD4 @ =0xFFFFFC00
	adds r3, r5, #0
	adds r2, r4, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r5, _08056AD8 @ =0xFFFF0000
	ldr r1, [sp]
	ands r1, r5
	orrs r1, r2
	str r1, [sp]
	ldrh r2, [r6, #0x20]
	adds r3, r2, r3
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	mov r6, sp
	ldr r1, [sp, #4]
	ands r1, r5
	orrs r1, r3
	str r1, [sp, #4]
	movs r1, #0x80
	lsls r1, r1, #3
	adds r3, r1, #0
	adds r4, r4, r3
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r1, [sp, #8]
	ands r1, r5
	orrs r1, r4
	str r1, [sp, #8]
	adds r2, r2, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #8
	ldr r1, [r3, #4]
	ands r1, r5
	orrs r1, r2
	str r1, [r3, #4]
	mov r1, sp
	mov r4, r8
	movs r5, #0x2c
	ldrsh r2, [r4, r5]
	movs r4, #0
	ldrsh r1, [r1, r4]
	cmp r2, r1
	blt _08056ADC
	movs r5, #0
	ldrsh r1, [r3, r5]
	cmp r2, r1
	bgt _08056ADC
	mov r1, ip
	movs r4, #4
	ldrsh r2, [r1, r4]
	movs r5, #4
	ldrsh r1, [r6, r5]
	cmp r2, r1
	blt _08056ADC
	movs r4, #4
	ldrsh r1, [r3, r4]
	cmp r2, r1
	bgt _08056ADC
	movs r1, #1
	b _08056ADE
	.align 2, 0
_08056AD0: .4byte 0x00000EBC
_08056AD4: .4byte 0xFFFFFC00
_08056AD8: .4byte 0xFFFF0000
_08056ADC:
	movs r1, #0
_08056ADE:
	adds r2, r1, #0
	cmp r2, #0
	beq _08056AEA
	movs r0, #0
	strb r0, [r7, #0xc]
	b _08056AFC
_08056AEA:
	ldrb r1, [r7, #0xc]
	adds r1, #1
	strb r1, [r7, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x1f
	bls _08056AFC
	strb r2, [r7, #0xc]
	movs r0, #1
_08056AFC:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08056b08
FUN_08056b08: @ 0x08056B08
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

	thumb_func_start FUN_08056f90
FUN_08056f90: @ 0x08056F90
	bx lr
	.align 2, 0

	thumb_func_start FUN_08056f94
FUN_08056f94: @ 0x08056F94
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	bl Hitbox_ApplyDamage
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r6, #6]
	ands r0, r1
	cmp r0, #0
	beq _08056FBA
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r3, [r0]
	b _08056FD4
_08056FBA:
	movs r1, #0x24
	ldrsh r0, [r7, r1]
	movs r2, #0x24
	ldrsh r1, [r6, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r7, r3]
	movs r3, #0x28
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
_08056FD4:
	movs r0, #1
	ldr r1, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08057004
	ldr r0, _08057000 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0xc
	ldrsh r0, [r7, r1]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #0x10
	ldrsh r1, [r7, r3]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	movs r0, #0x10
	b _08057044
	.align 2, 0
_08057000: .4byte 0x03002BE0
_08057004:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08057012
	movs r1, #0x20
	mov ip, r1
	b _08057046
_08057012:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08057038
	movs r2, #0xc
	ldrsh r0, [r7, r2]
	movs r3, #0xc
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	movs r2, #0x10
	ldrsh r1, [r7, r2]
	movs r3, #0x10
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r3, r0, #0
	movs r0, #0x18
	b _08057044
_08057038:
	movs r0, #8
	ands r1, r0
	movs r2, #0x10
	mov ip, r2
	cmp r1, #0
	beq _08057046
_08057044:
	mov ip, r0
_08057046:
	ldr r2, _08057088 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805708C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08057090 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	subs r2, r3, #4
	movs r1, #7
	ands r0, r1
	adds r3, r2, r0
	adds r5, r4, #0
	adds r5, #0x20
	ldr r2, _08057094 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08057098
	asrs r1, r0, #0xc
	b _0805709E
	.align 2, 0
_08057088: .4byte 0x030046B8
_0805708C: .4byte 0x000003FF
_08057090: .4byte 0x0203B400
_08057094: .4byte 0x085B0A08
_08057098:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805709E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _080570BE
	asrs r0, r0, #0xc
	b _080570C4
_080570BE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080570C4:
	movs r1, #0
	mov r8, r1
	strh r0, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x30
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	movs r0, #0xa
	strb r0, [r4, #9]
	ldr r3, _08057134 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _08057138 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r7, #0x3e]
	adds r3, r4, #0
	adds r3, #0x68
	add r2, sp, #8
	str r2, [sp]
	movs r5, #1
	str r5, [sp, #4]
	adds r0, r7, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldrh r0, [r6, #0x3e]
	adds r0, #2
	strh r0, [r6, #0x3e]
	movs r0, #0x89
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldrh r0, [r4]
	ldrh r1, [r7, #0x3e]
	subs r0, r0, r1
	strh r0, [r4]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0805713C
	mov r3, r8
	strh r3, [r4]
	movs r0, #7
	strb r0, [r4, #4]
	strb r5, [r4, #8]
	mov r0, r8
	str r0, [r4, #0x14]
	b _08057146
	.align 2, 0
_08057134: .4byte 0xFFFF0000
_08057138: .4byte 0x0000FFFF
_0805713C:
	movs r0, #6
	strb r0, [r4, #4]
	strb r5, [r4, #8]
	mov r1, r8
	str r1, [r4, #0x14]
_08057146:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08057154
FUN_08057154: @ 0x08057154
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	str r1, [sp, #0x1c]
	movs r0, #0
	strh r0, [r7, #0x24]
	ldr r0, _08057200 @ =0xFFFF0000
	mov sl, r0
	add r6, sp, #0xc
	ldr r1, _08057204 @ =0x00000D7C
	mov sb, r1
	add r5, sp, #0x14
	movs r0, #3
	mov r8, r0
_08057178:
	mov r1, sb
	adds r4, r7, r1
	ldr r0, [sp, #0xc]
	mov r1, sl
	ands r0, r1
	movs r1, #0x18
	orrs r0, r1
	ldr r1, _08057208 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [r6, #4]
	mov r1, sl
	ands r0, r1
	movs r1, #0x18
	orrs r0, r1
	str r0, [r6, #4]
	movs r0, #0x80
	lsls r0, r0, #0xe
	str r0, [sp, #0x14]
	ldr r0, [r5, #4]
	mov r1, sl
	ands r0, r1
	str r0, [r5, #4]
	movs r0, #0x10
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	ldr r2, _0805720C @ =0x00002001
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	ldr r1, _08057210 @ =FUN_08056f90
	adds r2, r7, #0
	bl Hitbox_SetHandler
	movs r0, #0
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x1e
	movs r3, #0
	bl Hitbox_SetAttack
	movs r0, #0x50
	add sb, r0
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r0, r8
	cmp r0, #0
	bge _08057178
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08057200: .4byte 0xFFFF0000
_08057204: .4byte 0x00000D7C
_08057208: .4byte 0x0000FFFF
_0805720C: .4byte 0x00002001
_08057210: .4byte FUN_08056f90

	thumb_func_start FUN_08057214
FUN_08057214: @ 0x08057214
	push {r4, r5, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r2, r1, #0
	ldrh r0, [r4, #0x24]
	cmp r0, #3
	bhi _080572AA
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #4
	ldr r0, _08057248 @ =0x00000D7C
	adds r1, r1, r0
	adds r5, r4, r1
	ldr r0, [r2, #0x68]
	ldr r1, [r2, #0x6c]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r1, [r2, #5]
	cmp r1, #1
	beq _0805725E
	cmp r1, #1
	bgt _0805724C
	cmp r1, #0
	beq _08057256
	b _08057294
	.align 2, 0
_08057248: .4byte 0x00000D7C
_0805724C:
	cmp r1, #2
	beq _08057266
	cmp r1, #3
	beq _08057280
	b _08057294
_08057256:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, #0x30
	b _0805726C
_0805725E:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, #0x30
	b _08057286
_08057266:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, #0x30
_0805726C:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0805727C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	b _08057294
	.align 2, 0
_0805727C: .4byte 0xFFFF0000
_08057280:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, #0x30
_08057286:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080572B4 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
_08057294:
	adds r0, r5, #0
	mov r1, sp
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	ldrh r0, [r4, #0x24]
	adds r0, #1
	strh r0, [r4, #0x24]
_080572AA:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080572B4: .4byte 0xFFFF0000

	thumb_func_start FUN_080572b8
FUN_080572b8: @ 0x080572B8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r1, #0
	adds r4, r5, #0
	adds r4, #0x88
	ldr r2, _08057334 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _08057338 @ =0x0000FFFF
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
	ldr r2, _0805733C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r1, r5, #0
	adds r1, #0x68
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08057340 @ =FUN_08056f94
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	movs r0, #2
	ldrsh r1, [r5, r0]
	adds r0, r4, #0
	movs r2, #0x80
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08057334: .4byte 0xFFFF0000
_08057338: .4byte 0x0000FFFF
_0805733C: .4byte 0x00005001
_08057340: .4byte FUN_08056f94

	thumb_func_start FUN_08057344
FUN_08057344: @ 0x08057344
	push {lr}
	adds r0, r1, #0
	adds r0, #0x88
	bl Hitbox_Unregister
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08057354
FUN_08057354: @ 0x08057354
	push {lr}
	sub sp, #0x14
	ldr r2, [r0, #0x38]
	cmp r2, #0
	beq _08057394
	adds r0, r1, #0
	adds r0, #0x68
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp]
	adds r0, r1, #0
	adds r0, #0x6a
	movs r3, #0
	ldrsh r0, [r0, r3]
	str r0, [sp, #4]
	adds r0, r1, #0
	adds r0, #0x6c
	movs r1, #0
	ldrsh r0, [r0, r1]
	str r0, [sp, #8]
	ldr r1, _0805739C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0xc]
	add r1, sp, #0xc
	mov r3, sp
	str r3, [r1, #4]
	adds r0, r2, #0
	bl VM_ExecByID
_08057394:
	add sp, #0x14
	pop {r0}
	bx r0
	.align 2, 0
_0805739C: .4byte 0xFFFF0000

	thumb_func_start FUN_080573a0
FUN_080573a0: @ 0x080573A0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080573E2
	movs r0, #0
	strb r0, [r4, #8]
	adds r5, r4, #0
	adds r5, #0x78
	ldr r1, [r6, #0x18]
	movs r3, #0
	ldrb r2, [r4, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080573C8
	movs r3, #1
_080573C8:
	movs r0, #0
	cmp r2, #1
	bls _080573D0
	movs r0, #1
_080573D0:
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	bl AuxAnim_SetAnim
	adds r0, r5, #0
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
_080573E2:
	ldrb r0, [r4, #0xe]
	cmp r0, #0
	beq _080573EE
	subs r0, #1
	strb r0, [r4, #0xe]
	b _08057422
_080573EE:
	ldr r1, [r4, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057422
	ldrb r0, [r4, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057406
	subs r0, #1
	strb r0, [r4, #0xf]
	b _08057422
_08057406:
	movs r0, #0x1e
	strb r0, [r4, #0xf]
	movs r0, #0x78
	strb r0, [r4, #0xe]
	movs r1, #5
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _08057418
	movs r1, #8
_08057418:
	strb r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r2, [r4, #0x14]
	b _0805746E
_08057422:
	ldrb r3, [r4, #0x10]
	cmp r3, #0
	bne _0805744E
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r4, #0x18]
	movs r2, #0
	cmp r0, r1
	bhi _08057436
	movs r2, #1
_08057436:
	cmp r2, #0
	beq _0805744E
	movs r1, #4
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _08057444
	movs r1, #8
_08057444:
	strb r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r3, [r4, #0x14]
	b _0805746E
_0805744E:
	ldr r0, [r4, #0x14]
	cmp r0, #0x3b
	bls _0805746A
	movs r2, #2
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _0805745E
	movs r2, #8
_0805745E:
	movs r1, #0
	strb r2, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r1, [r4, #0x14]
	b _0805746E
_0805746A:
	adds r0, #1
	str r0, [r4, #0x14]
_0805746E:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08057478
FUN_08057478: @ 0x08057478
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r8, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r7, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080574B6
	movs r2, #0
	strb r2, [r4, #8]
	adds r0, r4, #0
	adds r0, #0x78
	mov r3, r8
	ldr r1, [r3, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r4, #0x4c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Show
_080574B6:
	ldrh r0, [r7, #0x1e]
	subs r0, #0x20
	strh r0, [r7, #0x1e]
	adds r6, r4, #0
	adds r6, #0x68
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080574E4
	cmp r1, #0
	blt _080574E4
	ldr r0, _080574E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080574E4
	ldr r0, _080574EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080574F0
_080574E4:
	movs r5, #0
	b _080574FE
	.align 2, 0
_080574E8: .4byte 0x030046A8
_080574EC: .4byte 0x030046AC
_080574F0:
	ldr r0, _08057510 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080574FE:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08057514
	adds r0, #4
	b _08057520
	.align 2, 0
_08057510: .4byte 0x030046A4
_08057514:
	ldr r0, _08057534 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057520:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08057538
	cmp r2, #2
	beq _0805753C
	b _08057540
	.align 2, 0
_08057534: .4byte 0x030046A4
_08057538:
	ldrb r0, [r6, #4]
	b _0805753E
_0805753C:
	ldrb r0, [r6]
_0805753E:
	subs r1, r1, r0
_08057540:
	movs r2, #0x1e
	ldrsh r0, [r7, r2]
	cmp r0, r1
	bgt _08057578
	movs r2, #0
	strh r1, [r7, #0x1e]
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bhi _0805755A
	movs r1, #4
	b _0805755C
_0805755A:
	movs r1, #2
_0805755C:
	mov r3, r8
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _08057566
	movs r1, #8
_08057566:
	strb r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r2, [r4, #0x14]
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Hide
	b _0805757E
_08057578:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
_0805757E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805758c
FUN_0805758c: @ 0x0805758C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r0
	adds r7, r1, #0
	mov sb, r2
	adds r0, r7, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r7, #8]
	cmp r0, #0
	beq _080575EE
	movs r0, #0
	strb r0, [r7, #8]
	ldr r6, _08057624 @ =0x0203B400
	ldr r4, _08057628 @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _0805762C @ =0x000003FF
	ands r1, r3
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r2, #3
	mov r5, sb
	ands r2, r5
	lsls r2, r2, #3
	add r2, r8
	ands r0, r3
	ldrh r5, [r2, #0x3c]
	adds r0, r0, r5
	movs r5, #0
	strh r0, [r7, #0x1c]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	adds r2, #0x40
	ands r0, r3
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r7, #0x1e]
	strb r5, [r7, #0x10]
_080575EE:
	mov r6, r8
	ldr r1, [r6, #0x18]
	movs r3, #0
	ldrb r2, [r7, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r7, #0
	adds r4, #0x78
	cmp r0, #1
	bhi _08057606
	movs r3, #1
_08057606:
	movs r0, #0
	cmp r2, #1
	bls _0805760E
	movs r0, #1
_0805760E:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	ldrb r0, [r7, #0xe]
	cmp r0, #0
	beq _08057630
	subs r0, #1
	strb r0, [r7, #0xe]
	b _08057666
	.align 2, 0
_08057624: .4byte 0x0203B400
_08057628: .4byte 0x030046B8
_0805762C: .4byte 0x000003FF
_08057630:
	ldr r1, [r7, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057666
	ldrb r0, [r7, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057648
	subs r0, #1
	strb r0, [r7, #0xf]
	b _08057666
_08057648:
	movs r0, #0x1e
	strb r0, [r7, #0xf]
	movs r0, #0x78
	strb r0, [r7, #0xe]
	movs r1, #5
	mov r3, r8
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _0805765C
	movs r1, #8
_0805765C:
	strb r1, [r7, #4]
	movs r0, #1
	strb r0, [r7, #8]
	str r2, [r7, #0x14]
	b _08057992
_08057666:
	ldrb r3, [r7, #0x10]
	cmp r3, #0
	bne _08057694
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r7, #0x18]
	movs r2, #0
	cmp r0, r1
	bhi _0805767A
	movs r2, #1
_0805767A:
	cmp r2, #0
	beq _08057694
	movs r1, #4
	mov r5, r8
	ldr r0, [r5, #0x30]
	cmp r0, #0
	beq _0805768A
	movs r1, #8
_0805768A:
	strb r1, [r7, #4]
	movs r0, #1
	strb r0, [r7, #8]
	str r3, [r7, #0x14]
	b _08057992
_08057694:
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne _080576B4
	ldr r2, _080576B0 @ =0x085AB9A4
	ldrh r1, [r4, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #3
	asrs r0, r0, #6
	b _080576B6
	.align 2, 0
_080576B0: .4byte 0x085AB9A4
_080576B4:
	movs r0, #0
_080576B6:
	movs r4, #0
	strb r0, [r7, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080576C2
	b _0805798C
_080576C2:
	adds r2, r7, #0
	adds r2, #0x4c
	movs r6, #0x1c
	ldrsh r1, [r7, r6]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r5, #0x1e
	ldrsh r1, [r7, r5]
	movs r6, #0x20
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _080576E2
	rsbs r0, r3, #0
_080576E2:
	cmp r0, #0x17
	bgt _0805771E
	adds r0, r1, #0
	cmp r1, #0
	bge _080576EE
	rsbs r0, r1, #0
_080576EE:
	cmp r0, #0x17
	bgt _08057710
	strb r4, [r7, #6]
	movs r0, #0xff
	strb r0, [r7, #0xb]
	movs r3, #1
	mov r0, r8
	ldr r1, [r0, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r7, #4]
	strb r3, [r7, #8]
	str r4, [r7, #0x14]
	b _08057992
_08057710:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
	ldrb r4, [r7, #0xb]
	b _08057774
_0805771E:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057726
	rsbs r0, r1, #0
_08057726:
	cmp r0, #0x17
	bgt _0805773E
	movs r2, #1
	cmp r3, #0
	bge _08057732
	movs r2, #3
_08057732:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	ldrb r4, [r7, #0xb]
	b _0805777A
_0805773E:
	movs r0, #0xb
	ldrsb r0, [r7, r0]
	ldrb r4, [r7, #0xb]
	cmp r0, #0
	blt _0805774E
	movs r0, #1
	ands r0, r4
	b _08057754
_0805774E:
	movs r0, #1
	mov r2, sb
	ands r0, r2
_08057754:
	cmp r0, #0
	bne _0805776A
	movs r2, #1
	cmp r3, #0
	bge _08057760
	movs r2, #3
_08057760:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	b _0805777A
_0805776A:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
_08057774:
	cmp r3, #0
	bge _0805777A
	movs r5, #3
_0805777A:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057790
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057790
	movs r5, #0xb
	ldrsb r5, [r7, r5]
_08057790:
	str r7, [sp, #0x10]
	mov r8, r2
	mov sl, r5
	ldrb r3, [r7, #6]
	mov sb, r3
	adds r6, r7, #0
	adds r6, #0x20
	str r6, [sp, #0x14]
_080577A0:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _080577D8 @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r6, r8
	ands r0, r6
	cmp r0, #0
	bne _080577EC
	cmp r6, #0
	bne _080577DC
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _080577E0
	.align 2, 0
_080577D8: .4byte 0xFFFF0000
_080577DC:
	ldrh r0, [r4, #4]
	add r0, sb
_080577E0:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _0805780C
_080577EC:
	mov r6, r8
	cmp r6, #1
	bne _080577FA
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08057802
_080577FA:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08057802:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_0805780C:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057834
	cmp r1, #0
	blt _08057834
	ldr r0, _08057838 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057834
	ldr r0, _0805783C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057840
_08057834:
	movs r4, #0
	b _0805784E
	.align 2, 0
_08057838: .4byte 0x030046A8
_0805783C: .4byte 0x030046AC
_08057840:
	ldr r0, _08057860 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0805784E:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08057864
	adds r0, #4
	b _08057870
	.align 2, 0
_08057860: .4byte 0x030046A4
_08057864:
	ldr r0, _080578A8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057870:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805790C
	add r6, sp, #4
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080578A2
	cmp r1, #0
	blt _080578A2
	ldr r0, _080578AC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080578A2
	ldr r0, _080578B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080578B4
_080578A2:
	movs r4, #0
	b _080578C2
	.align 2, 0
_080578A8: .4byte 0x030046A4
_080578AC: .4byte 0x030046A8
_080578B0: .4byte 0x030046AC
_080578B4:
	ldr r0, _080578D4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080578C2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080578D8
	adds r0, #4
	b _080578E4
	.align 2, 0
_080578D4: .4byte 0x030046A4
_080578D8:
	ldr r0, _080578F8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080578E4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080578FC
	cmp r2, #2
	beq _08057900
	b _08057904
	.align 2, 0
_080578F8: .4byte 0x030046A4
_080578FC:
	ldrb r0, [r6, #4]
	b _08057902
_08057900:
	ldrb r0, [r6]
_08057902:
	subs r1, r1, r0
_08057904:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08057922
_0805790C:
	mov r3, sl
	cmp r3, #0
	blt _0805791C
	mov r8, sl
	movs r6, #1
	rsbs r6, r6, #0
	mov sl, r6
	b _080577A0
_0805791C:
	movs r2, #1
	rsbs r2, r2, #0
	b _08057924
_08057922:
	mov r2, r8
_08057924:
	cmp r2, r5
	bne _0805792C
	strb r2, [r7, #0xb]
	b _08057930
_0805792C:
	movs r0, #0xff
	strb r0, [r7, #0xb]
_08057930:
	cmp r2, #0
	bge _08057938
	movs r2, #0
	strb r2, [r7, #6]
_08057938:
	strb r2, [r7, #5]
	movs r3, #0
	ldrb r1, [r7, #5]
	ldrb r0, [r7, #6]
	ldr r2, [sp, #0x14]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08057964
	cmp r1, #1
	bgt _08057952
	cmp r1, #0
	beq _0805795C
	b _08057978
_08057952:
	cmp r1, #2
	beq _0805796A
	cmp r1, #3
	beq _08057970
	b _08057978
_0805795C:
	strh r3, [r7, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _08057978
_08057964:
	strh r0, [r7, #0x20]
	strh r3, [r2, #4]
	b _08057978
_0805796A:
	strh r3, [r7, #0x20]
	strh r0, [r2, #4]
	b _08057978
_08057970:
	rsbs r0, r0, #0
	strh r0, [r7, #0x20]
	ldr r0, [sp, #0x14]
	strh r3, [r0, #4]
_08057978:
	ldrh r0, [r7, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r7, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_0805798C:
	ldr r0, [r7, #0x14]
	adds r0, #1
	str r0, [r7, #0x14]
_08057992:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080579a4
FUN_080579a4: @ 0x080579A4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r0, r6, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r6, #8]
	cmp r0, #0
	beq _08057A04
	movs r0, #0
	strb r0, [r6, #8]
	ldr r1, _08057A38 @ =0x0203B400
	mov sb, r1
	ldr r4, _08057A3C @ =0x030046B8
	ldr r1, [r4]
	adds r1, #1
	ldr r3, _08057A40 @ =0x000003FF
	ands r1, r3
	str r1, [r4]
	lsls r0, r1, #1
	add r0, sb
	ldrh r0, [r0]
	movs r2, #3
	mov r5, r8
	ands r2, r5
	lsls r2, r2, #3
	adds r2, r7, r2
	ands r0, r3
	ldrh r5, [r2, #0x3c]
	adds r0, r0, r5
	strh r0, [r6, #0x1c]
	adds r1, #1
	ands r1, r3
	str r1, [r4]
	lsls r1, r1, #1
	add r1, sb
	ldrh r0, [r1]
	adds r2, #0x40
	ands r0, r3
	ldrh r2, [r2]
	adds r0, r0, r2
	strh r0, [r6, #0x1e]
_08057A04:
	ldr r1, [r7, #0x18]
	movs r3, #0
	ldrb r2, [r6, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r4, r6, #0
	adds r4, #0x78
	cmp r0, #1
	bhi _08057A1A
	movs r3, #1
_08057A1A:
	movs r0, #0
	cmp r2, #1
	bls _08057A22
	movs r0, #1
_08057A22:
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	ldrb r0, [r6, #0xe]
	cmp r0, #0
	beq _08057A44
	subs r0, #1
	strb r0, [r6, #0xe]
	b _08057A78
	.align 2, 0
_08057A38: .4byte 0x0203B400
_08057A3C: .4byte 0x030046B8
_08057A40: .4byte 0x000003FF
_08057A44:
	ldr r1, [r6, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057A78
	ldrb r0, [r6, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057A5C
	subs r0, #1
	strb r0, [r6, #0xf]
	b _08057A78
_08057A5C:
	movs r0, #0x1e
	strb r0, [r6, #0xf]
	movs r0, #0x78
	strb r0, [r6, #0xe]
	movs r1, #5
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08057A6E
	movs r1, #8
_08057A6E:
	strb r1, [r6, #4]
	movs r0, #1
	strb r0, [r6, #8]
	str r2, [r6, #0x14]
	b _08057D9E
_08057A78:
	ldrb r3, [r6, #0x10]
	cmp r3, #0
	bne _08057AA4
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r6, #0x18]
	movs r2, #0
	cmp r0, r1
	bhi _08057A8C
	movs r2, #1
_08057A8C:
	cmp r2, #0
	beq _08057AA4
	movs r1, #4
	ldr r0, [r7, #0x30]
	cmp r0, #0
	beq _08057A9A
	movs r1, #8
_08057A9A:
	strb r1, [r6, #4]
	movs r0, #1
	strb r0, [r6, #8]
	str r3, [r6, #0x14]
	b _08057D9E
_08057AA4:
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne _08057AC4
	ldr r2, _08057AC0 @ =0x085AB9A4
	ldrh r1, [r4, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #3
	asrs r0, r0, #6
	b _08057AC6
	.align 2, 0
_08057AC0: .4byte 0x085AB9A4
_08057AC4:
	movs r0, #0
_08057AC6:
	movs r4, #0
	strb r0, [r6, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08057AD2
	b _08057D98
_08057AD2:
	adds r2, r6, #0
	adds r2, #0x4c
	movs r0, #0x1c
	ldrsh r1, [r6, r0]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r5, #0x1e
	ldrsh r1, [r6, r5]
	movs r5, #0x20
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _08057AF2
	rsbs r0, r3, #0
_08057AF2:
	cmp r0, #0x17
	bgt _08057B2C
	adds r0, r1, #0
	cmp r1, #0
	bge _08057AFE
	rsbs r0, r1, #0
_08057AFE:
	cmp r0, #0x17
	bgt _08057B1E
	strb r4, [r6, #6]
	movs r0, #0xff
	strb r0, [r6, #0xb]
	movs r3, #1
	ldr r1, [r7, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r6, #4]
	strb r3, [r6, #8]
	str r4, [r6, #0x14]
	b _08057D9E
_08057B1E:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
	ldrb r4, [r6, #0xb]
	b _08057B82
_08057B2C:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057B34
	rsbs r0, r1, #0
_08057B34:
	cmp r0, #0x17
	bgt _08057B4C
	movs r2, #1
	cmp r3, #0
	bge _08057B40
	movs r2, #3
_08057B40:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	ldrb r4, [r6, #0xb]
	b _08057B88
_08057B4C:
	movs r0, #0xb
	ldrsb r0, [r6, r0]
	ldrb r4, [r6, #0xb]
	cmp r0, #0
	blt _08057B5C
	movs r0, #1
	ands r0, r4
	b _08057B62
_08057B5C:
	movs r0, #1
	mov r7, r8
	ands r0, r7
_08057B62:
	cmp r0, #0
	bne _08057B78
	movs r2, #1
	cmp r3, #0
	bge _08057B6E
	movs r2, #3
_08057B6E:
	mvns r0, r1
	asrs r5, r0, #0x1f
	movs r0, #2
	ands r5, r0
	b _08057B88
_08057B78:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r5, #1
_08057B82:
	cmp r3, #0
	bge _08057B88
	movs r5, #3
_08057B88:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057B9E
	movs r0, #1
	adds r1, r5, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057B9E
	movs r5, #0xb
	ldrsb r5, [r6, r5]
_08057B9E:
	str r6, [sp, #0x10]
	mov r8, r2
	mov sl, r5
	ldrb r0, [r6, #6]
	mov sb, r0
	adds r1, r6, #0
	adds r1, #0x20
	str r1, [sp, #0x14]
_08057BAE:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _08057BE4 @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r7, r8
	ands r0, r7
	cmp r0, #0
	bne _08057BF8
	cmp r7, #0
	bne _08057BE8
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _08057BEC
	.align 2, 0
_08057BE4: .4byte 0xFFFF0000
_08057BE8:
	ldrh r0, [r4, #4]
	add r0, sb
_08057BEC:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _08057C18
_08057BF8:
	mov r7, r8
	cmp r7, #1
	bne _08057C06
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08057C0E
_08057C06:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08057C0E:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_08057C18:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057C40
	cmp r1, #0
	blt _08057C40
	ldr r0, _08057C44 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057C40
	ldr r0, _08057C48 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057C4C
_08057C40:
	movs r4, #0
	b _08057C5A
	.align 2, 0
_08057C44: .4byte 0x030046A8
_08057C48: .4byte 0x030046AC
_08057C4C:
	ldr r0, _08057C6C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08057C5A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08057C70
	adds r0, #4
	b _08057C7C
	.align 2, 0
_08057C6C: .4byte 0x030046A4
_08057C70:
	ldr r0, _08057CB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057C7C:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08057D18
	add r7, sp, #4
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08057CAE
	cmp r1, #0
	blt _08057CAE
	ldr r0, _08057CB8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08057CAE
	ldr r0, _08057CBC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08057CC0
_08057CAE:
	movs r4, #0
	b _08057CCE
	.align 2, 0
_08057CB4: .4byte 0x030046A4
_08057CB8: .4byte 0x030046A8
_08057CBC: .4byte 0x030046AC
_08057CC0:
	ldr r0, _08057CE0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08057CCE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08057CE4
	adds r0, #4
	b _08057CF0
	.align 2, 0
_08057CE0: .4byte 0x030046A4
_08057CE4:
	ldr r0, _08057D04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08057CF0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08057D08
	cmp r2, #2
	beq _08057D0C
	b _08057D10
	.align 2, 0
_08057D04: .4byte 0x030046A4
_08057D08:
	ldrb r0, [r7, #4]
	b _08057D0E
_08057D0C:
	ldrb r0, [r7]
_08057D0E:
	subs r1, r1, r0
_08057D10:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08057D2E
_08057D18:
	mov r3, sl
	cmp r3, #0
	blt _08057D28
	mov r8, sl
	movs r7, #1
	rsbs r7, r7, #0
	mov sl, r7
	b _08057BAE
_08057D28:
	movs r2, #1
	rsbs r2, r2, #0
	b _08057D30
_08057D2E:
	mov r2, r8
_08057D30:
	cmp r2, r5
	bne _08057D38
	strb r2, [r6, #0xb]
	b _08057D3C
_08057D38:
	movs r0, #0xff
	strb r0, [r6, #0xb]
_08057D3C:
	cmp r2, #0
	bge _08057D44
	movs r2, #0
	strb r2, [r6, #6]
_08057D44:
	strb r2, [r6, #5]
	movs r3, #0
	ldrb r1, [r6, #5]
	ldrb r0, [r6, #6]
	ldr r2, [sp, #0x14]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08057D70
	cmp r1, #1
	bgt _08057D5E
	cmp r1, #0
	beq _08057D68
	b _08057D84
_08057D5E:
	cmp r1, #2
	beq _08057D76
	cmp r1, #3
	beq _08057D7C
	b _08057D84
_08057D68:
	strh r3, [r6, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _08057D84
_08057D70:
	strh r0, [r6, #0x20]
	strh r3, [r2, #4]
	b _08057D84
_08057D76:
	strh r3, [r6, #0x20]
	strh r0, [r2, #4]
	b _08057D84
_08057D7C:
	rsbs r0, r0, #0
	strh r0, [r6, #0x20]
	ldr r0, [sp, #0x14]
	strh r3, [r0, #4]
_08057D84:
	ldrh r0, [r6, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r6, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_08057D98:
	ldr r0, [r6, #0x14]
	adds r0, #1
	str r0, [r6, #0x14]
_08057D9E:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08057db0
FUN_08057db0: @ 0x08057DB0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov sl, r0
	adds r5, r1, #0
	adds r7, r2, #0
	adds r0, r5, #0
	adds r0, #0x4c
	str r0, [sp, #0xc]
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _08057E00
	movs r0, #0
	strb r0, [r5, #8]
	ldr r0, _08057E70 @ =0x00000EBC
	add r0, sl
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	ldr r1, _08057E74 @ =0xFFFFFF00
	adds r2, r1, #0
	ands r2, r0
	movs r3, #3
	adds r0, r7, #0
	ands r0, r3
	lsls r0, r0, #5
	adds r2, r2, r0
	movs r3, #0
	strh r2, [r5, #0x1c]
	ldrh r0, [r4, #0x30]
	ands r1, r0
	asrs r0, r7, #2
	lsls r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
	strb r3, [r5, #0xc]
	movs r0, #1
	strb r0, [r5, #0x10]
_08057E00:
	adds r4, r5, #0
	adds r4, #0x78
	adds r0, r4, #0
	movs r1, #0x20
	bl AuxAnim_SetAnimSpeed
	mov r2, sl
	ldr r1, [r2, #0x18]
	movs r3, #0
	ldrb r2, [r5, #5]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r4, #0
	cmp r0, #1
	bhi _08057E22
	movs r3, #1
_08057E22:
	movs r0, #0
	cmp r2, #1
	bls _08057E2A
	movs r0, #1
_08057E2A:
	str r0, [sp]
	adds r0, r6, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	ldr r0, [r5, #0x14]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0
	bne _08057E64
	ldr r0, _08057E70 @ =0x00000EBC
	add r0, sl
	ldr r4, [r0]
	ldrh r0, [r4, #0x2c]
	ldr r1, _08057E74 @ =0xFFFFFF00
	adds r2, r1, #0
	ands r2, r0
	movs r3, #3
	adds r0, r7, #0
	ands r0, r3
	lsls r0, r0, #5
	adds r2, r2, r0
	strh r2, [r5, #0x1c]
	ldrh r0, [r4, #0x30]
	ands r1, r0
	asrs r0, r7, #2
	lsls r0, r0, #5
	adds r1, r1, r0
	strh r1, [r5, #0x1e]
_08057E64:
	ldrb r0, [r5, #0xe]
	cmp r0, #0
	beq _08057E78
	subs r0, #1
	strb r0, [r5, #0xe]
	b _08057EAE
	.align 2, 0
_08057E70: .4byte 0x00000EBC
_08057E74: .4byte 0xFFFFFF00
_08057E78:
	ldr r1, [r5, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	cmp r1, r0
	bhi _08057EAE
	ldrb r0, [r5, #0xf]
	adds r2, r0, #0
	cmp r2, #0
	beq _08057E90
	subs r0, #1
	strb r0, [r5, #0xf]
	b _08057EAE
_08057E90:
	movs r0, #0x1e
	strb r0, [r5, #0xf]
	movs r0, #0x78
	strb r0, [r5, #0xe]
	movs r1, #5
	mov r3, sl
	ldr r0, [r3, #0x30]
	cmp r0, #0
	beq _08057EA4
	movs r1, #8
_08057EA4:
	strb r1, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	str r2, [r5, #0x14]
	b _080581CA
_08057EAE:
	ldrh r0, [r6, #0xa]
	cmp r0, #1
	bne _08057ECC
	ldr r2, _08057EC8 @ =0x085AB9A4
	ldrh r1, [r6, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #4
	asrs r0, r0, #6
	b _08057ECE
	.align 2, 0
_08057EC8: .4byte 0x085AB9A4
_08057ECC:
	movs r0, #0
_08057ECE:
	movs r4, #0
	strb r0, [r5, #6]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08057EDA
	b _080581A0
_08057EDA:
	adds r2, r5, #0
	adds r2, #0x4c
	movs r6, #0x1c
	ldrsh r1, [r5, r6]
	movs r3, #0x1c
	ldrsh r0, [r2, r3]
	subs r3, r1, r0
	movs r6, #0x1e
	ldrsh r1, [r5, r6]
	movs r6, #0x20
	ldrsh r0, [r2, r6]
	subs r1, r1, r0
	adds r0, r3, #0
	cmp r3, #0
	bge _08057EFA
	rsbs r0, r3, #0
_08057EFA:
	cmp r0, #0x17
	bgt _08057F36
	adds r0, r1, #0
	cmp r1, #0
	bge _08057F06
	rsbs r0, r1, #0
_08057F06:
	cmp r0, #0x17
	bgt _08057F28
	strb r4, [r5, #6]
	movs r0, #0xff
	strb r0, [r5, #0xb]
	movs r3, #1
	mov r7, sl
	ldr r1, [r7, #0x30]
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r5, #4]
	strb r3, [r5, #8]
	str r4, [r5, #0x14]
	b _080581CA
_08057F28:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r6, #1
	ldrb r4, [r5, #0xb]
	b _08057F8A
_08057F36:
	adds r0, r1, #0
	cmp r1, #0
	bge _08057F3E
	rsbs r0, r1, #0
_08057F3E:
	cmp r0, #0x17
	bgt _08057F56
	movs r2, #1
	cmp r3, #0
	bge _08057F4A
	movs r2, #3
_08057F4A:
	mvns r0, r1
	asrs r6, r0, #0x1f
	movs r0, #2
	ands r6, r0
	ldrb r4, [r5, #0xb]
	b _08057F90
_08057F56:
	movs r0, #0xb
	ldrsb r0, [r5, r0]
	ldrb r4, [r5, #0xb]
	cmp r0, #0
	blt _08057F66
	movs r0, #1
	ands r0, r4
	b _08057F6A
_08057F66:
	movs r0, #1
	ands r0, r7
_08057F6A:
	cmp r0, #0
	bne _08057F80
	movs r2, #1
	cmp r3, #0
	bge _08057F76
	movs r2, #3
_08057F76:
	mvns r0, r1
	asrs r6, r0, #0x1f
	movs r0, #2
	ands r6, r0
	b _08057F90
_08057F80:
	mvns r0, r1
	asrs r2, r0, #0x1f
	movs r0, #2
	ands r2, r0
	movs r6, #1
_08057F8A:
	cmp r3, #0
	bge _08057F90
	movs r6, #3
_08057F90:
	lsls r0, r4, #0x18
	cmp r0, #0
	blt _08057FA6
	movs r0, #1
	adds r1, r6, #0
	ands r1, r0
	ands r0, r4
	cmp r1, r0
	bne _08057FA6
	movs r6, #0xb
	ldrsb r6, [r5, r6]
_08057FA6:
	str r5, [sp, #0x10]
	mov r8, r2
	str r6, [sp, #0x14]
	ldrb r0, [r5, #6]
	mov sb, r0
	adds r1, r5, #0
	adds r1, #0x20
	str r1, [sp, #0x18]
_08057FB6:
	ldr r0, [sp, #0x10]
	adds r0, #0x68
	ldrh r0, [r0]
	ldr r1, _08057FEC @ =0xFFFF0000
	ldr r3, [sp, #4]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #4]
	ldr r0, [sp, #0x10]
	adds r0, #0x6c
	ldrh r0, [r0]
	add r4, sp, #4
	ldr r2, [sp, #8]
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #8]
	movs r0, #1
	mov r7, r8
	ands r0, r7
	cmp r0, #0
	bne _08058000
	cmp r7, #0
	bne _08057FF0
	ldrh r0, [r4, #4]
	mov r3, sb
	subs r0, r0, r3
	b _08057FF4
	.align 2, 0
_08057FEC: .4byte 0xFFFF0000
_08057FF0:
	ldrh r0, [r4, #4]
	add r0, sb
_08057FF4:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	b _08058020
_08058000:
	mov r7, r8
	cmp r7, #1
	bne _0805800E
	add r0, sp, #4
	ldrh r0, [r0]
	add r0, sb
	b _08058016
_0805800E:
	add r0, sp, #4
	ldrh r0, [r0]
	mov r2, sb
	subs r0, r0, r2
_08058016:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #4]
_08058020:
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058048
	cmp r1, #0
	blt _08058048
	ldr r0, _0805804C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058048
	ldr r0, _08058050 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058054
_08058048:
	movs r4, #0
	b _08058062
	.align 2, 0
_0805804C: .4byte 0x030046A8
_08058050: .4byte 0x030046AC
_08058054:
	ldr r0, _08058074 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058062:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08058078
	adds r0, #4
	b _08058084
	.align 2, 0
_08058074: .4byte 0x030046A4
_08058078:
	ldr r0, _080580BC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058084:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08058120
	add r7, sp, #4
	adds r0, r7, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080580B6
	cmp r1, #0
	blt _080580B6
	ldr r0, _080580C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080580B6
	ldr r0, _080580C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080580C8
_080580B6:
	movs r4, #0
	b _080580D6
	.align 2, 0
_080580BC: .4byte 0x030046A4
_080580C0: .4byte 0x030046A8
_080580C4: .4byte 0x030046AC
_080580C8:
	ldr r0, _080580E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080580D6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080580EC
	adds r0, #4
	b _080580F8
	.align 2, 0
_080580E8: .4byte 0x030046A4
_080580EC:
	ldr r0, _0805810C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080580F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058110
	cmp r2, #2
	beq _08058114
	b _08058118
	.align 2, 0
_0805810C: .4byte 0x030046A4
_08058110:
	ldrb r0, [r7, #4]
	b _08058116
_08058114:
	ldrb r0, [r7]
_08058116:
	subs r1, r1, r0
_08058118:
	movs r0, #0x80
	lsls r0, r0, #1
	cmp r1, r0
	beq _08058136
_08058120:
	ldr r3, [sp, #0x14]
	cmp r3, #0
	blt _08058130
	mov r8, r3
	movs r7, #1
	rsbs r7, r7, #0
	str r7, [sp, #0x14]
	b _08057FB6
_08058130:
	movs r2, #1
	rsbs r2, r2, #0
	b _08058138
_08058136:
	mov r2, r8
_08058138:
	cmp r2, r6
	bne _08058140
	strb r2, [r5, #0xb]
	b _08058144
_08058140:
	movs r0, #0xff
	strb r0, [r5, #0xb]
_08058144:
	cmp r2, #0
	bge _0805814C
	movs r2, #0
	strb r2, [r5, #6]
_0805814C:
	strb r2, [r5, #5]
	movs r3, #0
	ldrb r1, [r5, #5]
	ldrb r0, [r5, #6]
	ldr r2, [sp, #0x18]
	strh r3, [r2, #2]
	cmp r1, #1
	beq _08058178
	cmp r1, #1
	bgt _08058166
	cmp r1, #0
	beq _08058170
	b _0805818C
_08058166:
	cmp r1, #2
	beq _0805817E
	cmp r1, #3
	beq _08058184
	b _0805818C
_08058170:
	strh r3, [r5, #0x20]
	rsbs r0, r0, #0
	strh r0, [r2, #4]
	b _0805818C
_08058178:
	strh r0, [r5, #0x20]
	strh r3, [r2, #4]
	b _0805818C
_0805817E:
	strh r3, [r5, #0x20]
	strh r0, [r2, #4]
	b _0805818C
_08058184:
	rsbs r0, r0, #0
	strh r0, [r5, #0x20]
	ldr r0, [sp, #0x18]
	strh r3, [r0, #4]
_0805818C:
	ldrh r0, [r5, #0x20]
	ldr r1, [sp, #0xc]
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	strh r0, [r2, #0x1c]
	ldrh r0, [r5, #0x24]
	ldrh r3, [r2, #0x20]
	adds r0, r0, r3
	strh r0, [r2, #0x20]
_080581A0:
	mov r0, sl
	adds r1, r5, #0
	bl FUN_08056a34
	cmp r0, #0
	beq _080581C4
	movs r2, #2
	mov r6, sl
	ldr r0, [r6, #0x30]
	cmp r0, #0
	beq _080581B8
	movs r2, #8
_080581B8:
	movs r1, #0
	strb r2, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	str r1, [r5, #0x14]
	b _080581CA
_080581C4:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
_080581CA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080581dc
FUN_080581dc: @ 0x080581DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	mov r8, r0
	adds r4, r1, #0
	adds r7, r4, #0
	adds r7, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08058262
	movs r0, #0
	strb r0, [r4, #8]
	ldr r0, [r7, #0x1c]
	ldr r1, [r7, #0x20]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	ldr r0, _08058280 @ =0x00000EBC
	add r0, r8
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x28
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r2, r3]
	movs r3, #0x2c
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #0xd]
	ldrb r0, [r4, #0xd]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	adds r2, r1, #0
	strb r1, [r4, #5]
	adds r5, r4, #0
	adds r5, #0x78
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r3, #0
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08058248
	movs r3, #1
_08058248:
	movs r0, #0
	cmp r2, #1
	bls _08058250
	movs r0, #1
_08058250:
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	adds r0, r5, #0
	movs r1, #0x10
	bl AuxAnim_SetAnimSpeed
_08058262:
	ldr r2, _08058284 @ =0x085B0A08
	ldr r0, [r4, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #7
	adds r6, r2, #0
	cmp r0, #0
	blt _08058288
	asrs r0, r0, #0xc
	b _0805828E
	.align 2, 0
_08058280: .4byte 0x00000EBC
_08058284: .4byte 0x085B0A08
_08058288:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805828E:
	adds r2, r0, #0
	adds r3, r4, #0
	adds r3, #0x20
	ldrb r5, [r4, #0xd]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080582B0
	asrs r1, r0, #0xc
	b _080582B6
_080582B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080582B6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080582CE
	asrs r0, r0, #0xc
	b _080582D4
_080582CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080582D4:
	strh r0, [r3, #4]
	ldr r0, [r4, #0x14]
	subs r0, #8
	cmp r0, #7
	bhi _080582E6
	ldrb r1, [r4, #0xa]
	movs r0, #2
	orrs r0, r1
	strb r0, [r4, #0xa]
_080582E6:
	ldrh r0, [r4, #0x20]
	ldrh r3, [r4, #0x28]
	adds r0, r0, r3
	lsls r0, r0, #0x10
	ldr r2, _0805833C @ =0xFFFF0000
	ldrh r1, [r4, #0x22]
	ldrh r3, [r4, #0x2a]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #4]
	ldrh r0, [r4, #0x24]
	ldrh r1, [r4, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	add r6, sp, #4
	adds r0, r6, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058338
	cmp r1, #0
	blt _08058338
	ldr r0, _08058340 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058338
	ldr r0, _08058344 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058348
_08058338:
	movs r5, #0
	b _08058356
	.align 2, 0
_0805833C: .4byte 0xFFFF0000
_08058340: .4byte 0x030046A8
_08058344: .4byte 0x030046AC
_08058348:
	ldr r0, _08058368 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08058356:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805836C
	adds r0, #4
	b _08058378
	.align 2, 0
_08058368: .4byte 0x030046A4
_0805836C:
	ldr r0, _080583AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058378:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08058412
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080583A6
	cmp r1, #0
	blt _080583A6
	ldr r0, _080583B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080583A6
	ldr r0, _080583B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080583B8
_080583A6:
	movs r5, #0
	b _080583C6
	.align 2, 0
_080583AC: .4byte 0x030046A4
_080583B0: .4byte 0x030046A8
_080583B4: .4byte 0x030046AC
_080583B8:
	ldr r0, _080583D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_080583C6:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080583DC
	adds r0, #4
	b _080583E8
	.align 2, 0
_080583D8: .4byte 0x030046A4
_080583DC:
	ldr r0, _080583FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080583E8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058400
	cmp r2, #2
	beq _08058404
	b _08058408
	.align 2, 0
_080583FC: .4byte 0x030046A4
_08058400:
	ldrb r0, [r6, #4]
	b _08058406
_08058404:
	ldrb r0, [r6]
_08058406:
	subs r1, r1, r0
_08058408:
	movs r0, #0x80
	lsls r0, r0, #1
	movs r2, #0
	cmp r1, r0
	beq _08058414
_08058412:
	movs r2, #1
_08058414:
	cmp r2, #0
	beq _08058420
	movs r2, #0
	mov r3, r8
	ldr r1, [r3, #0x30]
	b _0805843A
_08058420:
	add r0, sp, #4
	ldrh r0, [r0]
	strh r0, [r7, #0x1c]
	add r1, sp, #4
	ldrh r0, [r1, #2]
	strh r0, [r7, #0x1e]
	ldrh r0, [r1, #4]
	strh r0, [r7, #0x20]
	ldr r0, [r4, #0x14]
	cmp r0, #0x1f
	bls _0805844E
	mov r0, r8
	ldr r1, [r0, #0x30]
_0805843A:
	rsbs r0, r1, #0
	orrs r0, r1
	asrs r0, r0, #0x1f
	movs r1, #8
	ands r0, r1
	strb r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #8]
	str r2, [r4, #0x14]
	b _08058452
_0805844E:
	adds r0, #1
	str r0, [r4, #0x14]
_08058452:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08058460
FUN_08058460: @ 0x08058460
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	mov r8, r0
	adds r5, r1, #0
	adds r7, r5, #0
	adds r7, #0x4c
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _0805853C
	movs r0, #0
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0xd8
	bl ParticleShadow_Show
	adds r6, r5, #0
	adds r6, #0x68
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080584AC
	cmp r1, #0
	blt _080584AC
	ldr r0, _080584B0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080584AC
	ldr r0, _080584B4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080584B8
_080584AC:
	movs r4, #0
	b _080584C6
	.align 2, 0
_080584B0: .4byte 0x030046A8
_080584B4: .4byte 0x030046AC
_080584B8:
	ldr r0, _080584D8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080584C6:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080584DC
	adds r0, #4
	b _080584E8
	.align 2, 0
_080584D8: .4byte 0x030046A4
_080584DC:
	ldr r0, _0805851C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080584E8:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0805853C
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058516
	cmp r1, #0
	blt _08058516
	ldr r0, _08058520 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058516
	ldr r0, _08058524 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058528
_08058516:
	movs r0, #0
	b _08058536
	.align 2, 0
_0805851C: .4byte 0x030046A4
_08058520: .4byte 0x030046A8
_08058524: .4byte 0x030046AC
_08058528:
	ldr r0, _08058580 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08058536:
	movs r1, #1
	bl Map_FindTileOverride
_0805853C:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08056b08
	ldrh r0, [r5, #0x20]
	ldrh r1, [r7, #0x1c]
	adds r0, r0, r1
	strh r0, [r7, #0x1c]
	ldrh r1, [r5, #0x24]
	ldrh r2, [r7, #0x20]
	adds r1, r1, r2
	strh r1, [r7, #0x20]
	adds r6, r7, #0
	adds r6, #0x1c
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r6
	cmp r2, #0
	blt _0805857C
	cmp r1, #0
	blt _0805857C
	ldr r0, _08058584 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805857C
	ldr r0, _08058588 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0805858C
_0805857C:
	movs r4, #0
	b _0805859A
	.align 2, 0
_08058580: .4byte 0x030046A4
_08058584: .4byte 0x030046A8
_08058588: .4byte 0x030046AC
_0805858C:
	ldr r0, _080585AC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0805859A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080585B0
	adds r0, #4
	b _080585BC
	.align 2, 0
_080585AC: .4byte 0x030046A4
_080585B0:
	ldr r0, _080585D0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080585BC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080585D4
	cmp r2, #2
	beq _080585D8
	b _080585DC
	.align 2, 0
_080585D0: .4byte 0x030046A4
_080585D4:
	ldrb r0, [r6, #4]
	b _080585DA
_080585D8:
	ldrb r0, [r6]
_080585DA:
	subs r1, r1, r0
_080585DC:
	adds r3, r1, #0
	ldr r2, _080585FC @ =0x085B0A08
	ldr r0, [r5, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	blt _08058600
	asrs r0, r0, #0xc
	b _08058606
	.align 2, 0
_080585FC: .4byte 0x085B0A08
_08058600:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08058606:
	adds r0, r3, r0
	strh r0, [r7, #0x1e]
	movs r0, #0x20
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _08058614
	rsbs r1, r1, #0
_08058614:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _0805861E
	rsbs r0, r0, #0
_0805861E:
	cmp r1, r0
	bge _08058638
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	b _0805864C
_08058638:
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
_0805864C:
	ldrb r0, [r5, #0xa]
	movs r1, #1
	orrs r1, r0
	strb r1, [r5, #0xa]
	ldr r0, [r5, #0x14]
	cmp r0, #0x1f
	bhi _0805865C
	b _080587B4
_0805865C:
	movs r1, #4
	mov r2, r8
	ldr r0, [r2, #0x30]
	cmp r0, #0
	beq _08058668
	movs r1, #8
_08058668:
	strb r1, [r5, #4]
	movs r0, #1
	strb r0, [r5, #8]
	movs r0, #0
	str r0, [r5, #0x14]
	mov r6, sb
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058698
	cmp r1, #0
	blt _08058698
	ldr r0, _0805869C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058698
	ldr r0, _080586A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080586A4
_08058698:
	movs r4, #0
	b _080586B2
	.align 2, 0
_0805869C: .4byte 0x030046A8
_080586A0: .4byte 0x030046AC
_080586A4:
	ldr r0, _080586C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080586B2:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _080586C8
	adds r0, #4
	b _080586D4
	.align 2, 0
_080586C4: .4byte 0x030046A4
_080586C8:
	ldr r0, _080586E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080586D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080586EC
	cmp r2, #2
	beq _080586F0
	b _080586F4
	.align 2, 0
_080586E8: .4byte 0x030046A4
_080586EC:
	ldrb r0, [r6, #4]
	b _080586F2
_080586F0:
	ldrb r0, [r6]
_080586F2:
	subs r1, r1, r0
_080586F4:
	strh r1, [r7, #0x1e]
	mov r6, sb
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805871C
	cmp r1, #0
	blt _0805871C
	ldr r0, _08058720 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805871C
	ldr r0, _08058724 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058728
_0805871C:
	movs r4, #0
	b _08058736
	.align 2, 0
_08058720: .4byte 0x030046A8
_08058724: .4byte 0x030046AC
_08058728:
	ldr r0, _08058748 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058736:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805874C
	adds r0, #4
	b _08058758
	.align 2, 0
_08058748: .4byte 0x030046A4
_0805874C:
	ldr r0, _0805878C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058758:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080587AC
	ldrh r0, [r6]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058786
	cmp r1, #0
	blt _08058786
	ldr r0, _08058790 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058786
	ldr r0, _08058794 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058798
_08058786:
	movs r0, #0
	b _080587A6
	.align 2, 0
_0805878C: .4byte 0x030046A4
_08058790: .4byte 0x030046A8
_08058794: .4byte 0x030046AC
_08058798:
	ldr r0, _080587C8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080587A6:
	movs r1, #1
	bl Map_FindTileOverride
_080587AC:
	adds r0, r5, #0
	adds r0, #0xd8
	bl ParticleShadow_Hide
_080587B4:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080587C8: .4byte 0x030046A4

	thumb_func_start FUN_080587cc
FUN_080587cc: @ 0x080587CC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r5, r1, #0
	mov sb, r2
	adds r6, r5, #0
	adds r6, #0x4c
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _080588AC
	movs r0, #0
	strb r0, [r5, #8]
	adds r0, r5, #0
	adds r0, #0xd8
	bl ParticleShadow_Show
	adds r7, r5, #0
	adds r7, #0x68
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805881A
	cmp r1, #0
	blt _0805881A
	ldr r0, _08058820 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805881A
	ldr r0, _08058824 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058828
_0805881A:
	movs r4, #0
	b _08058836
	.align 2, 0
_08058820: .4byte 0x030046A8
_08058824: .4byte 0x030046AC
_08058828:
	ldr r0, _08058848 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058836:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805884C
	adds r0, #4
	b _08058858
	.align 2, 0
_08058848: .4byte 0x030046A4
_0805884C:
	ldr r0, _0805888C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058858:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080588AC
	ldrh r0, [r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058886
	cmp r1, #0
	blt _08058886
	ldr r0, _08058890 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058886
	ldr r0, _08058894 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058898
_08058886:
	movs r0, #0
	b _080588A6
	.align 2, 0
_0805888C: .4byte 0x030046A4
_08058890: .4byte 0x030046A8
_08058894: .4byte 0x030046AC
_08058898:
	ldr r0, _08058930 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080588A6:
	movs r1, #1
	bl Map_FindTileOverride
_080588AC:
	ldr r4, [r5, #0x14]
	movs r0, #7
	ands r4, r0
	adds r7, r6, #0
	adds r7, #0x1c
	cmp r4, #0
	bne _080588F0
	ldr r2, _08058934 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08058938 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805893C @ =0x0203B400
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0x10
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	movs r0, #3
	movs r1, #9
	adds r2, r7, #0
	bl Entity080146e0_SpawnAtAngle
_080588F0:
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08056b08
	ldrh r0, [r5, #0x20]
	ldrh r2, [r6, #0x1c]
	adds r0, r0, r2
	strh r0, [r6, #0x1c]
	ldrh r1, [r5, #0x24]
	ldrh r2, [r6, #0x20]
	adds r1, r1, r2
	strh r1, [r6, #0x20]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0805892A
	cmp r1, #0
	blt _0805892A
	ldr r0, _08058940 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0805892A
	ldr r0, _08058944 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058948
_0805892A:
	movs r4, #0
	b _08058956
	.align 2, 0
_08058930: .4byte 0x030046A4
_08058934: .4byte 0x030046B8
_08058938: .4byte 0x000003FF
_0805893C: .4byte 0x0203B400
_08058940: .4byte 0x030046A8
_08058944: .4byte 0x030046AC
_08058948:
	ldr r0, _08058968 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08058956:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0805896C
	adds r0, #4
	b _08058978
	.align 2, 0
_08058968: .4byte 0x030046A4
_0805896C:
	ldr r0, _0805898C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058978:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058990
	cmp r2, #2
	beq _08058994
	b _08058998
	.align 2, 0
_0805898C: .4byte 0x030046A4
_08058990:
	ldrb r0, [r7, #4]
	b _08058996
_08058994:
	ldrb r0, [r7]
_08058996:
	subs r1, r1, r0
_08058998:
	adds r3, r1, #0
	ldr r2, _080589B8 @ =0x085B0A08
	ldr r0, [r5, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	blt _080589BC
	asrs r0, r0, #0xc
	b _080589C2
	.align 2, 0
_080589B8: .4byte 0x085B0A08
_080589BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080589C2:
	adds r0, r3, r0
	strh r0, [r6, #0x1e]
	movs r0, #0x20
	ldrsh r1, [r5, r0]
	cmp r1, #0
	bge _080589D0
	rsbs r1, r1, #0
_080589D0:
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	cmp r0, #0
	bge _080589DA
	rsbs r0, r0, #0
_080589DA:
	cmp r1, r0
	bge _080589F4
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	b _08058A08
_080589F4:
	adds r0, r5, #0
	adds r0, #0x78
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #1
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
_08058A08:
	ldrb r1, [r5, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r5, #0xa]
	ldr r1, [r5, #0x14]
	cmp r1, #7
	bls _08058A26
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08058A3A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058A42
_08058A26:
	cmp r1, #0xf
	bls _08058A44
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _08058A3A
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058A42
_08058A3A:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08058A42:
	str r0, [r6]
_08058A44:
	ldr r0, [r5, #0x14]
	cmp r0, #0x1f
	bls _08058A84
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08057354
	adds r0, r5, #0
	adds r0, #0xd8
	bl ParticleShadow_Hide
	adds r0, r6, #0
	bl AuxSprite_Remove
	mov r0, r8
	adds r1, r5, #0
	bl FUN_08057344
	movs r1, #1
	mov r0, sb
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x1c]
	bics r0, r1
	str r0, [r2, #0x1c]
	ldr r0, [r2, #0x34]
	bl FUN_0807a798
	mov r1, r8
	ldr r0, [r1, #0x2c]
	adds r0, #1
	str r0, [r1, #0x2c]
_08058A84:
	ldr r0, [r5, #0x14]
	adds r0, #1
	str r0, [r5, #0x14]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08058a98
FUN_08058a98: @ 0x08058A98
	push {r4, lr}
	sub sp, #4
	adds r2, r0, #0
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _08058ADA
	movs r0, #0
	strb r0, [r1, #8]
	adds r4, r1, #0
	adds r4, #0x78
	ldr r2, [r2, #0x18]
	movs r3, #0
	ldrb r1, [r1, #5]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08058ABE
	movs r3, #1
_08058ABE:
	movs r0, #0
	cmp r1, #1
	bls _08058AC6
	movs r0, #1
_08058AC6:
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r2, #0
	movs r2, #0
	bl AuxAnim_SetAnim
	adds r0, r4, #0
	movs r1, #0x40
	bl AuxAnim_SetAnimSpeed
_08058ADA:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08058ae4
FUN_08058ae4: @ 0x08058AE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	adds r6, r4, #0
	adds r6, #0x4c
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _08058B16
	movs r0, #0
	strb r0, [r4, #8]
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Show
	adds r0, r4, #0
	adds r0, #0x30
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
_08058B16:
	ldrb r1, [r4, #0xa]
	movs r0, #1
	orrs r0, r1
	strb r0, [r4, #0xa]
	movs r0, #0xa
	strb r0, [r4, #9]
	ldr r5, [r4, #0x14]
	movs r0, #7
	ands r5, r0
	adds r7, r4, #0
	adds r7, #0x68
	cmp r5, #0
	bne _08058B66
	ldr r2, _08058B90 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08058B94 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08058B98 @ =0x0203B400
	adds r0, r0, r1
	ldrb r3, [r0]
	movs r0, #0x20
	str r0, [sp]
	movs r0, #6
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	movs r0, #3
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r0, #0x10
	str r0, [sp, #0x14]
	str r5, [sp, #0x18]
	movs r0, #3
	movs r1, #9
	adds r2, r7, #0
	bl Entity080146e0_SpawnAtAngle
_08058B66:
	ldrh r0, [r6, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08058B8A
	cmp r1, #0
	blt _08058B8A
	ldr r0, _08058B9C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08058B8A
	ldr r0, _08058BA0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08058BA4
_08058B8A:
	movs r5, #0
	b _08058BB2
	.align 2, 0
_08058B90: .4byte 0x030046B8
_08058B94: .4byte 0x000003FF
_08058B98: .4byte 0x0203B400
_08058B9C: .4byte 0x030046A8
_08058BA0: .4byte 0x030046AC
_08058BA4:
	ldr r0, _08058BC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08058BB2:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08058BC8
	adds r0, #4
	b _08058BD4
	.align 2, 0
_08058BC4: .4byte 0x030046A4
_08058BC8:
	ldr r0, _08058BE8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08058BD4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08058BEC
	cmp r2, #2
	beq _08058BF0
	b _08058BF4
	.align 2, 0
_08058BE8: .4byte 0x030046A4
_08058BEC:
	ldrb r0, [r7, #4]
	b _08058BF2
_08058BF0:
	ldrb r0, [r7]
_08058BF2:
	subs r1, r1, r0
_08058BF4:
	adds r3, r1, #0
	ldr r2, _08058C14 @ =0x085B0A08
	ldr r0, [r4, #0x14]
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xfa
	muls r0, r1, r0
	cmp r0, #0
	blt _08058C18
	asrs r0, r0, #0xc
	b _08058C1E
	.align 2, 0
_08058C14: .4byte 0x085B0A08
_08058C18:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08058C1E:
	adds r0, r3, r0
	movs r2, #0
	strh r0, [r6, #0x1e]
	adds r0, r4, #0
	adds r0, #0x78
	mov r3, r8
	ldr r1, [r3, #0x18]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r1, [r4, #0x14]
	cmp r1, #7
	bls _08058C4C
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	bne _08058C60
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058C68
_08058C4C:
	cmp r1, #0xf
	bls _08058C6A
	movs r0, #3
	ands r1, r0
	cmp r1, #2
	bhi _08058C60
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	b _08058C68
_08058C60:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_08058C68:
	str r0, [r6]
_08058C6A:
	ldr r0, [r4, #0x14]
	cmp r0, #0x1f
	bls _08058C94
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Hide
	adds r0, r6, #0
	bl AuxSprite_Remove
	mov r0, r8
	adds r1, r4, #0
	bl FUN_08057344
	movs r1, #1
	mov r0, sb
	lsls r1, r0
	mov r2, r8
	ldr r0, [r2, #0x1c]
	bics r0, r1
	str r0, [r2, #0x1c]
_08058C94:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity08058ffc_Update
Entity08058ffc_Update: @ 0x08058CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	strh r0, [r7, #0x24]
	strh r0, [r7, #0x26]
	adds r5, r7, #0
	adds r5, #0x5c
	mov sb, r0
	movs r0, #1
	mov sl, r0
	movs r1, #0xd4
	adds r1, r1, r7
	mov r8, r1
_08058CCC:
	mov r0, sl
	mov r2, sb
	lsls r0, r2
	ldr r1, [r7, #0x1c]
	ands r1, r0
	adds r3, r5, #0
	adds r3, #0x68
	str r3, [sp]
	cmp r1, #0
	bne _08058CE2
	b _08058E82
_08058CE2:
	adds r6, r5, #0
	adds r6, #0x4c
	mov r3, r8
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x78]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r3, #4]
	mov r2, sl
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sl
	ands r0, r1
	cmp r2, r0
	beq _08058D14
	ldr r0, [r5, #0x4c]
	movs r1, #4
	orrs r0, r1
	b _08058D1C
_08058D14:
	ldr r0, [r5, #0x4c]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08058D1C:
	str r0, [r5, #0x4c]
	ldrb r0, [r3, #4]
	movs r1, #2
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	movs r2, #2
	ands r0, r2
	cmp r1, r0
	beq _08058D40
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08058D48
_08058D40:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08058D48:
	str r0, [r6]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _08058D80 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _08058DC6
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08058D8A
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _08058D84
	ldrb r0, [r3, #5]
	subs r0, #1
	strh r0, [r3, #8]
	movs r2, #1
	b _08058DA0
	.align 2, 0
_08058D80: .4byte 0x0000FFFF
_08058D84:
	subs r0, #1
	strh r0, [r3, #8]
	b _08058D9E
_08058D8A:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _08058D9E
	strh r1, [r3, #8]
	movs r2, #1
	b _08058DA0
_08058D9E:
	movs r2, #0
_08058DA0:
	ldrh r0, [r3, #8]
	lsls r0, r0, #1
	ldr r1, [r3]
	adds r4, r1, r0
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r3, #6]
	ldrb r1, [r3, #6]
	ldrh r0, [r3, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r3, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08058DC8
	mov r4, sl
	strb r4, [r3, #7]
	b _08058DC8
_08058DC6:
	movs r2, #0
_08058DC8:
	movs r0, #0
	strb r2, [r5, #7]
	strb r0, [r5, #0xa]
	ldr r1, [r7, #0x20]
	movs r2, #3
	ands r1, r2
	mov r0, sb
	ands r0, r2
	cmp r1, r0
	bne _08058E04
	ldr r1, _08058E30 @ =0x00000EBC
	adds r0, r7, r1
	ldr r1, [r0]
	movs r3, #0x2c
	ldrsh r2, [r1, r3]
	movs r4, #0x1c
	ldrsh r0, [r6, r4]
	subs r2, r2, r0
	movs r0, #0x30
	ldrsh r1, [r1, r0]
	movs r3, #0x20
	ldrsh r0, [r6, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r4, r1, #0
	muls r4, r1, r4
	adds r1, r4, #0
	adds r0, r0, r1
	str r0, [r5, #0x18]
_08058E04:
	ldr r1, _08058E34 @ =0x085AB9B4
	ldrb r0, [r5, #4]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	adds r1, r5, #0
	mov r2, sb
	bl _call_via_r3
	ldrb r1, [r5, #0xa]
	mov r0, sl
	ands r0, r1
	cmp r0, #0
	beq _08058E38
	mov r0, r8
	ldrh r1, [r0, #0x16]
	movs r0, #4
	orrs r0, r1
	mov r1, r8
	strh r0, [r1, #0x16]
	b _08058E50
	.align 2, 0
_08058E30: .4byte 0x00000EBC
_08058E34: .4byte 0x085AB9B4
_08058E38:
	mov r2, r8
	ldrh r0, [r2, #0x16]
	ldr r3, _08058EB0 @ =0x0000FFFB
	adds r1, r3, #0
	ands r0, r1
	strh r0, [r2, #0x16]
	adds r0, r5, #0
	adds r0, #0x88
	ldr r1, [sp]
	movs r2, #0
	bl Hitbox_SetPos
_08058E50:
	ldrb r1, [r5, #0xa]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08058E62
	adds r0, r7, #0
	adds r1, r5, #0
	bl FUN_08057214
_08058E62:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _08058E7C
	subs r0, #1
	strb r0, [r5, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08058E7C
	adds r0, r5, #0
	adds r0, #0x30
	ldr r1, _08058EB4 @ =0x0000022A
	bl Video_SetAuxSpritePltt
_08058E7C:
	ldrh r0, [r7, #0x26]
	adds r0, #1
	strh r0, [r7, #0x26]
_08058E82:
	movs r4, #1
	add sb, r4
	movs r0, #0x8c
	lsls r0, r0, #1
	add r8, r0
	adds r5, r5, r0
	mov r1, sb
	cmp r1, #0xb
	bgt _08058E96
	b _08058CCC
_08058E96:
	ldr r0, [r7, #0x20]
	adds r0, #1
	str r0, [r7, #0x20]
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058EB0: .4byte 0x0000FFFB
_08058EB4: .4byte 0x0000022A

	thumb_func_start Entity08058ffc_Destroy
Entity08058ffc_Destroy: @ 0x08058EB8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x5c
	movs r7, #0
_08058EC2:
	adds r0, r4, #0
	adds r0, #0xd8
	bl ParticleShadow_Remove
	movs r6, #1
	lsls r6, r7
	ldr r0, [r5, #0x1c]
	ands r0, r6
	cmp r0, #0
	beq _08058EEC
	adds r0, r4, #0
	adds r0, #0x4c
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08057344
	ldr r0, [r5, #0x1c]
	bics r0, r6
	str r0, [r5, #0x1c]
_08058EEC:
	adds r7, #1
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r7, #0xb
	ble _08058EC2
	ldr r1, _08058F04 @ =0x0300012C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058F04: .4byte 0x0300012C

	thumb_func_start Entity08058ffc_Init
Entity08058ffc_Init: @ 0x08058F08
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r0, _08058F70 @ =0x0300012C
	str r7, [r0]
	ldr r0, _08058F74 @ =0x0000922E
	ldr r1, _08058F78 @ =0x000031F4
	bl GetFile
	str r0, [r7, #0x18]
	adds r0, r7, #0
	bl FUN_080569f4
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_08057154
	str r5, [r7, #0x34]
	str r6, [r7, #0x38]
	movs r0, #0
	str r0, [r7, #0x1c]
	strh r0, [r7, #0x26]
	str r0, [r7, #0x28]
	str r0, [r7, #0x2c]
	str r0, [r7, #0x30]
	adds r6, r7, #0
	adds r6, #0x5c
	mov sb, r0
	mov r8, r0
_08058F4E:
	mov r0, r8
	strb r0, [r6, #6]
	strb r0, [r6, #5]
	adds r4, r6, #0
	adds r4, #0x30
	adds r0, r4, #0
	ldr r1, _08058F7C @ =0x000061F9
	bl Video_GetAuxSprite
	adds r5, r6, #0
	adds r5, #0x4c
	cmp r0, #0
	bne _08058F80
	movs r0, #1
	rsbs r0, r0, #0
	b _08058FE2
	.align 2, 0
_08058F70: .4byte 0x0300012C
_08058F74: .4byte 0x0000922E
_08058F78: .4byte 0x000031F4
_08058F7C: .4byte 0x000061F9
_08058F80:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Setup
	adds r0, r6, #0
	adds r0, #0x78
	ldr r1, [r7, #0x18]
	mov r2, r8
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	movs r0, #2
	strb r0, [r5, #7]
	adds r5, r6, #0
	adds r5, #0x68
	mov r0, r8
	str r0, [sp, #4]
	add r0, sp, #4
	adds r1, r5, #0
	ldr r2, _08058FF0 @ =0x05000002
	bl CpuSet
	adds r4, r6, #0
	adds r4, #0xd8
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	movs r2, #1
	add sb, r2
	movs r0, #0x8c
	lsls r0, r0, #1
	adds r6, r6, r0
	mov r2, sb
	cmp r2, #0xb
	ble _08058F4E
	ldr r0, _08058FF4 @ =0x03002BE0
	ldr r1, [r0]
	ldr r2, _08058FF8 @ =0x00000EBC
	adds r0, r7, r2
	str r1, [r0]
	movs r0, #0
_08058FE2:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08058FF0: .4byte 0x05000002
_08058FF4: .4byte 0x03002BE0
_08058FF8: .4byte 0x00000EBC

	thumb_func_start Entity08058ffc_Create
Entity08058ffc_Create: @ 0x08058FFC
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	ldr r0, _08059040 @ =0x0300012C
	ldr r0, [r0]
	cmp r0, #0
	bne _0805904E
	movs r1, #0xec
	lsls r1, r1, #4
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805904C
	ldr r1, _08059044 @ =Entity08058ffc_Update
	ldr r2, _08059048 @ =Entity08058ffc_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl Entity08058ffc_Init
	cmp r0, #0
	bge _0805904C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805904E
	.align 2, 0
_08059040: .4byte 0x0300012C
_08059044: .4byte Entity08058ffc_Update
_08059048: .4byte Entity08058ffc_Destroy
_0805904C:
	adds r0, r4, #0
_0805904E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08059054
FUN_08059054: @ 0x08059054
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r1, _08059088 @ =0x0300012C
	ldr r5, [r1]
	cmp r5, #0
	bne _0805908C
	ldr r0, [sp, #0x48]
	movs r1, #1
	movs r2, #0
	bl Entity08058ffc_Create
	adds r5, r0, #0
	cmp r5, #0
	bne _0805908C
	movs r0, #1
	rsbs r0, r0, #0
	b _080591DA
	.align 2, 0
_08059088: .4byte 0x0300012C
_0805908C:
	movs r1, #0
	str r1, [sp, #0x14]
	mov sl, r1
	adds r2, r5, #0
	adds r2, #0xd4
	str r2, [sp, #0x18]
	adds r3, r5, #0
	adds r3, #0x8c
	str r3, [sp, #0x1c]
	movs r6, #0x7c
	adds r6, r6, r5
	mov r8, r6
	adds r4, r5, #0
	adds r4, #0x5c
	adds r1, r5, #0
	adds r1, #0xa8
	str r1, [sp, #0x20]
	str r4, [sp, #0x24]
_080590B0:
	movs r1, #1
	mov r2, sl
	lsls r1, r2
	ldr r2, [r5, #0x1c]
	ands r2, r1
	cmp r2, #0
	bne _080591AE
	ldr r7, [sp, #0x20]
	mov r3, sp
	ldrh r3, [r3, #0xc]
	strh r3, [r4]
	mov r6, sp
	ldrh r6, [r6, #0x10]
	strh r6, [r4, #2]
	mov r0, sp
	ldrb r0, [r0, #8]
	strb r0, [r4, #5]
	movs r3, #8
	strb r3, [r4, #6]
	ldrb r1, [r4, #5]
	movs r0, #8
	strh r2, [r4, #0x22]
	cmp r1, #1
	beq _080590FE
	cmp r1, #1
	bgt _080590EA
	cmp r1, #0
	beq _080590F4
	b _08059116
_080590EA:
	cmp r1, #2
	beq _08059106
	cmp r1, #3
	beq _0805910E
	b _08059116
_080590F4:
	strh r2, [r4, #0x20]
	rsbs r0, r0, #0
	mov r1, r8
	strh r0, [r1, #4]
	b _08059116
_080590FE:
	strh r0, [r4, #0x20]
	mov r3, r8
	strh r2, [r3, #4]
	b _08059116
_08059106:
	strh r2, [r4, #0x20]
	mov r6, r8
	strh r0, [r6, #4]
	b _08059116
_0805910E:
	rsbs r0, r3, #0
	strh r0, [r4, #0x20]
	mov r0, r8
	strh r2, [r0, #4]
_08059116:
	ldr r2, [sp, #0x4c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	movs r6, #0
	strb r6, [r4, #9]
	strb r6, [r4, #0xa]
	movs r0, #0xff
	strb r0, [r4, #0xb]
	strb r6, [r4, #0x10]
	movs r3, #1
	mov sb, r3
	movs r1, #1
	ldr r0, [r5, #0x30]
	cmp r0, #0
	beq _0805913A
	movs r1, #8
_0805913A:
	strb r1, [r4, #4]
	mov r0, sb
	strb r0, [r4, #8]
	str r6, [r4, #0x14]
	ldr r0, [sp, #0x1c]
	ldr r1, _080591EC @ =0x0000022A
	bl Video_SetAuxSpritePltt
	ldr r1, [r5, #0x18]
	str r6, [sp]
	ldr r0, [sp, #0x18]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	adds r0, r7, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	bl FUN_080572b8
	ldr r2, _080591F0 @ =0x00000EBC
	adds r1, r5, r2
	ldr r2, [r1]
	movs r6, #0x2c
	ldrsh r3, [r2, r6]
	movs r6, #0x1c
	ldrsh r1, [r7, r6]
	subs r3, r3, r1
	movs r1, #0x30
	ldrsh r2, [r2, r1]
	movs r6, #0x20
	ldrsh r1, [r7, r6]
	subs r2, r2, r1
	adds r1, r3, #0
	muls r1, r3, r1
	adds r3, r2, #0
	muls r3, r2, r3
	adds r2, r3, #0
	adds r1, r1, r2
	str r1, [r4, #0x18]
	mov r2, sb
	mov r6, sl
	lsls r2, r6
	ldr r1, [r5, #0x1c]
	orrs r1, r2
	str r1, [r5, #0x1c]
	ldr r1, [r5, #0x28]
	adds r1, #1
	str r1, [r5, #0x28]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	ldr r2, [sp, #4]
	cmp r1, r2
	bge _080591DA
_080591AE:
	ldr r3, [sp, #0x18]
	movs r6, #0x8c
	lsls r6, r6, #1
	adds r3, r3, r6
	str r3, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	adds r1, r1, r6
	str r1, [sp, #0x1c]
	add r8, r6
	adds r4, r4, r6
	ldr r2, [sp, #0x20]
	adds r2, r2, r6
	str r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	adds r3, r3, r6
	str r3, [sp, #0x24]
	movs r6, #1
	add sl, r6
	mov r1, sl
	cmp r1, #0xb
	bgt _080591DA
	b _080590B0
_080591DA:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080591EC: .4byte 0x0000022A
_080591F0: .4byte 0x00000EBC

	thumb_func_start FUN_080591f4
FUN_080591f4: @ 0x080591F4
	push {lr}
	ldr r0, _08059204 @ =0x0300012C
	ldr r0, [r0]
	cmp r0, #0
	beq _08059208
	ldrh r0, [r0, #0x26]
	b _0805920A
	.align 2, 0
_08059204: .4byte 0x0300012C
_08059208:
	movs r0, #0
_0805920A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059210
FUN_08059210: @ 0x08059210
	push {lr}
	ldr r0, _08059220 @ =0x0300012C
	ldr r0, [r0]
	cmp r0, #0
	beq _08059224
	ldr r0, [r0, #0x28]
	b _08059226
	.align 2, 0
_08059220: .4byte 0x0300012C
_08059224:
	movs r0, #0
_08059226:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805922c
FUN_0805922c: @ 0x0805922C
	push {lr}
	ldr r0, _0805923C @ =0x0300012C
	ldr r0, [r0]
	cmp r0, #0
	beq _08059240
	ldr r0, [r0, #0x2c]
	b _08059242
	.align 2, 0
_0805923C: .4byte 0x0300012C
_08059240:
	movs r0, #0
_08059242:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08059248
FUN_08059248: @ 0x08059248
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _0805925C @ =0x0300012C
	ldr r5, [r1]
	cmp r5, #0
	bne _08059260
	movs r0, #0
	b _0805929A
	.align 2, 0
_0805925C: .4byte 0x0300012C
_08059260:
	movs r1, #1
	str r1, [r5, #0x30]
	movs r4, #0
	movs r6, #1
	movs r1, #8
	mov r8, r1
	mov ip, r4
	adds r3, r5, #0
	adds r3, #0x60
	movs r7, #0x8c
	lsls r7, r7, #1
_08059276:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x1c]
	ands r1, r2
	cmp r1, #0
	beq _08059292
	ldrb r1, [r3]
	cmp r1, #5
	bhi _08059292
	mov r1, r8
	strb r1, [r3]
	strb r6, [r3, #4]
	mov r1, ip
	str r1, [r3, #0x10]
_08059292:
	adds r3, r3, r7
	adds r4, #1
	cmp r4, #0xb
	ble _08059276
_0805929A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080592a4
FUN_080592a4: @ 0x080592A4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r1, _080592B8 @ =0x0300012C
	ldr r5, [r1]
	cmp r5, #0
	bne _080592BC
	movs r0, #0
	b _080592F2
	.align 2, 0
_080592B8: .4byte 0x0300012C
_080592BC:
	movs r4, #0
	movs r6, #1
	movs r1, #9
	mov r8, r1
	mov ip, r4
	adds r3, r5, #0
	adds r3, #0x60
	movs r7, #0x8c
	lsls r7, r7, #1
_080592CE:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x1c]
	ands r1, r2
	cmp r1, #0
	beq _080592EA
	ldrb r1, [r3]
	cmp r1, #7
	beq _080592EA
	mov r1, r8
	strb r1, [r3]
	strb r6, [r3, #4]
	mov r1, ip
	str r1, [r3, #0x10]
_080592EA:
	adds r3, r3, r7
	adds r4, #1
	cmp r4, #0xb
	ble _080592CE
_080592F2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
