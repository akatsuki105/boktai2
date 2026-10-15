	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f0be8
FUN_081f0be8: @ 0x081F0BE8
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f0bec
FUN_081f0bec: @ 0x081F0BEC
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r5, #0
	movs r3, #1
_081F0BF4:
	adds r0, r3, #0
	lsls r0, r5
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F0C04
	movs r0, #1
	b _081F0C06
_081F0C04:
	movs r0, #0
_081F0C06:
	cmp r0, #0
	bne _081F0C2E
	movs r0, #0x94
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, #0x3c
	adds r4, r2, r4
	adds r0, r3, #0
	lsls r0, r5
	orrs r0, r1
	str r0, [r2, #0x38]
	adds r0, r4, #0
	movs r1, #0x94
	bl ClearMemory
	adds r0, r4, #0
	adds r0, #0x8f
	strb r5, [r0]
	adds r0, r4, #0
	b _081F0C36
_081F0C2E:
	adds r5, #1
	cmp r5, #0x13
	ble _081F0BF4
	movs r0, #0
_081F0C36:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f0c3c
FUN_081f0c3c: @ 0x081F0C3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r6, r1, #0
	mov ip, r6
	adds r2, r6, #0
	adds r2, #0x92
	ldrb r0, [r2]
	cmp r0, #0
	beq _081F0C62
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r0, #0
	strb r0, [r2]
_081F0C62:
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
	adds r7, r4, #0
	cmp r1, r0
	beq _081F0C94
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F0C9C
_081F0C94:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F0C9C:
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
	beq _081F0CC2
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081F0CCC
_081F0CC2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F0CCC:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F0D08 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F0D4E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F0D12
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F0D0C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F0D28
	.align 2, 0
_081F0D08: .4byte 0x0000FFFF
_081F0D0C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F0D26
_081F0D12:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F0D26
	strh r1, [r4, #8]
	movs r2, #1
	b _081F0D28
_081F0D26:
	movs r2, #0
_081F0D28:
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
	bne _081F0D50
	movs r0, #1
	strb r0, [r4, #7]
	b _081F0D50
_081F0D4E:
	movs r2, #0
_081F0D50:
	cmp r2, #0
	beq _081F0DA6
	adds r0, r6, #0
	adds r0, #0x93
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
	cmp r1, #1
	bls _081F0D7E
	movs r0, #1
	strb r0, [r2]
	movs r0, #3
	subs r0, r0, r1
	strb r0, [r3]
	b _081F0D84
_081F0D7E:
	movs r0, #0
	strb r0, [r2]
	strb r1, [r3]
_081F0D84:
	mov r0, r8
	ldr r1, [r0, #0x34]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	adds r1, r6, #0
	adds r1, #0x8e
	movs r0, #2
	strb r0, [r1]
	adds r1, #4
	movs r0, #1
	strb r0, [r1]
_081F0DA6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f0db4
FUN_081f0db4: @ 0x081F0DB4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x50
	mov sl, r1
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r0, [sp, #0x70]
	mov sb, r0
	add r4, sp, #0x3c
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081F0DF4 @ =0x05000002
	bl CpuSet
	cmp r5, r7
	bne _081F0DE0
	b _081F0FCE
_081F0DE0:
	ldr r6, _081F0DF8 @ =0x030046A4
_081F0DE2:
	adds r4, r5, #0
	mov r1, sb
	cmp r1, #1
	beq _081F0E0C
	cmp r1, #1
	bgt _081F0DFC
	cmp r1, #0
	beq _081F0E08
	b _081F0E26
	.align 2, 0
_081F0DF4: .4byte 0x05000002
_081F0DF8: .4byte 0x030046A4
_081F0DFC:
	mov r2, sb
	cmp r2, #2
	beq _081F0E18
	cmp r2, #3
	beq _081F0E1C
	b _081F0E26
_081F0E08:
	adds r5, #1
	b _081F0E26
_081F0E0C:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	adds r5, r5, r0
	b _081F0E26
_081F0E18:
	subs r5, #1
	b _081F0E26
_081F0E1C:
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r0, [r0, r2]
	subs r5, r5, r0
_081F0E26:
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F0E36
	adds r0, #4
	b _081F0E40
_081F0E36:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081F0E40:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #0
	beq _081F0E4C
	movs r0, #1
	b _081F0FCE
_081F0E4C:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F0E5C
	adds r0, #4
	b _081F0E66
_081F0E5C:
	ldr r0, [r6]
	lsls r1, r4, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081F0E66:
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	str r4, [sp, #0x4c]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	adds r1, r0, #0
	cmp r1, #0
	beq _081F0E80
	adds r1, #4
	b _081F0E8A
_081F0E80:
	ldr r1, [r6]
	lsls r2, r5, #2
	adds r2, #0xc
	ldr r1, [r1, #4]
	adds r1, r1, r2
_081F0E8A:
	ldrb r2, [r1]
	movs r1, #0xf
	ands r1, r2
	ldr r2, [sp, #0x4c]
	cmp r2, r1
	blt _081F0E98
	b _081F0FC8
_081F0E98:
	add r6, sp, #0x44
	ldr r7, _081F0ED4 @ =0x030046A4
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r4, #4
	ldrsh r1, [r0, r4]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r7]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	adds r2, r6, #0
	cmp r0, #0
	beq _081F0ED8
	adds r0, #4
	b _081F0EE2
	.align 2, 0
_081F0ED4: .4byte 0x030046A4
_081F0ED8:
	ldr r0, [r7]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081F0EE2:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	strh r1, [r6, #2]
	mov r4, r8
	lsls r0, r4, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	mov r0, sb
	cmp r0, #1
	beq _081F0F1C
	cmp r0, #1
	bgt _081F0F04
	cmp r0, #0
	beq _081F0F10
	b _081F0F3A
_081F0F04:
	mov r1, sb
	cmp r1, #2
	beq _081F0F28
	cmp r1, #3
	beq _081F0F32
	b _081F0F3A
_081F0F10:
	ldrh r0, [r2]
	subs r0, #0x80
	mov r2, sl
	strh r0, [r2]
	movs r0, #1
	b _081F0FCE
_081F0F1C:
	ldrh r0, [r2, #4]
	subs r0, #0x80
	mov r4, sl
	strh r0, [r4, #4]
	movs r0, #1
	b _081F0FCE
_081F0F28:
	ldrh r0, [r2]
	adds r0, #0x80
	mov r1, sl
	strh r0, [r1]
	b _081F0F3A
_081F0F32:
	ldrh r0, [r2, #4]
	adds r0, #0x80
	mov r2, sl
	strh r0, [r2, #4]
_081F0F3A:
	ldr r4, _081F0FB0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r3, _081F0FB4 @ =0x000003FF
	ands r0, r3
	str r0, [r4]
	lsls r1, r0, #1
	ldr r2, _081F0FB8 @ =0x0203B400
	adds r1, r1, r2
	ldr r4, [sp, #0x4c]
	lsls r2, r4, #8
	ldrb r1, [r1]
	adds r2, r2, r1
	mov r1, sl
	strh r2, [r1, #2]
	adds r0, #1
	ands r0, r3
	ldr r2, _081F0FB0 @ =0x030046B8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r4, _081F0FB8 @ =0x0203B400
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x1e
	movs r0, #3
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	movs r2, #0
	str r2, [sp, #0xc]
	movs r2, #1
	str r2, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	str r4, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	ldr r0, _081F0FBC @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	mov r0, sl
	add r1, sp, #0x3c
	ldr r2, _081F0FC0 @ =0x00001C1A
	ldr r3, _081F0FC4 @ =0x0000D1B8
	bl FUN_081f22c0
	movs r0, #1
	b _081F0FCE
	.align 2, 0
_081F0FB0: .4byte 0x030046B8
_081F0FB4: .4byte 0x000003FF
_081F0FB8: .4byte 0x0203B400
_081F0FBC: .4byte 0x00200004
_081F0FC0: .4byte 0x00001C1A
_081F0FC4: .4byte 0x0000D1B8
_081F0FC8:
	cmp r5, r7
	beq _081F0FCE
	b _081F0DE2
_081F0FCE:
	add sp, #0x50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081f0fe0
FUN_081f0fe0: @ 0x081F0FE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x5c
	str r0, [sp, #0x54]
	adds r6, r1, #0
	adds r0, #0x93
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081F1004
	asrs r0, r1, #6
	b _081F100A
_081F1004:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081F100A:
	lsls r7, r0, #6
	add r3, sp, #0x3c
	ldr r2, _081F102C @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	blt _081F1030
	asrs r1, r0, #0xc
	b _081F1036
	.align 2, 0
_081F102C: .4byte 0x085B0A08
_081F1030:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081F1036:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #2
	muls r0, r1, r0
	cmp r0, #0
	blt _081F1056
	asrs r0, r0, #0xc
	b _081F105C
_081F1056:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F105C:
	strh r0, [r3, #4]
	ldr r3, [sp, #0x54]
	adds r3, #0x1c
	ldr r0, [sp, #0x54]
	ldrh r2, [r0, #0x1c]
	add r1, sp, #0x3c
	ldrh r0, [r1]
	adds r0, r2, r0
	strh r0, [r1]
	mov r1, sp
	ldrh r0, [r1, #0x3e]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1, #0x3e]
	ldrh r1, [r3, #4]
	add r3, sp, #0x40
	ldrh r0, [r3]
	adds r0, r1, r0
	strh r0, [r3]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081F10A4
	cmp r1, #0
	blt _081F10A4
	ldr r0, _081F10A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F10A4
	ldr r0, _081F10AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F10B0
_081F10A4:
	movs r0, #0
	b _081F10BE
	.align 2, 0
_081F10A8: .4byte 0x030046A8
_081F10AC: .4byte 0x030046AC
_081F10B0:
	ldr r0, _081F1168 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_081F10BE:
	str r0, [sp, #0x58]
	add r4, sp, #0x44
	movs r0, #0
	str r0, [sp, #0x38]
	add r0, sp, #0x38
	adds r1, r4, #0
	ldr r2, _081F116C @ =0x05000002
	bl CpuSet
	cmp r6, #0
	bgt _081F10D6
	b _081F12A4
_081F10D6:
	ldr r1, _081F1170 @ =0x030046B8
	mov sl, r1
	add r5, sp, #0x4c
	mov r8, r6
	movs r2, #0
	mov sb, r2
_081F10E2:
	mov r3, sl
	ldr r1, [r3]
	adds r1, #1
	ldr r0, _081F1174 @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _081F1178 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r3, #0xff
	ands r0, r3
	subs r0, #0x80
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x4c]
	adds r1, #1
	ldr r0, _081F1174 @ =0x000003FF
	ands r1, r0
	mov r2, sl
	str r1, [r2]
	lsls r1, r1, #1
	ldr r3, _081F1178 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r0, #0xff
	ands r1, r0
	subs r1, #0x80
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r5, #4]
	ldr r2, _081F117C @ =0xFFFF0000
	ands r0, r2
	orrs r0, r1
	str r0, [r5, #4]
	add r0, sp, #0x3c
	ldrh r2, [r5]
	ldrh r0, [r0]
	adds r2, r2, r0
	strh r2, [r5]
	mov r3, sp
	ldrh r0, [r3, #0x3e]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r5, #4]
	add r1, sp, #0x40
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #4]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081F1164
	cmp r1, #0
	blt _081F1164
	ldr r0, _081F1180 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F1164
	ldr r0, _081F1184 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F1188
_081F1164:
	movs r6, #0
	b _081F1196
	.align 2, 0
_081F1168: .4byte 0x030046A4
_081F116C: .4byte 0x05000002
_081F1170: .4byte 0x030046B8
_081F1174: .4byte 0x000003FF
_081F1178: .4byte 0x0203B400
_081F117C: .4byte 0xFFFF0000
_081F1180: .4byte 0x030046A8
_081F1184: .4byte 0x030046AC
_081F1188:
	ldr r0, _081F11A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_081F1196:
	cmp r7, #0
	blt _081F11A4
	asrs r0, r7, #6
	b _081F11AA
	.align 2, 0
_081F11A0: .4byte 0x030046A4
_081F11A4:
	rsbs r0, r7, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081F11AA:
	str r0, [sp]
	ldr r0, [sp, #0x54]
	adds r1, r5, #0
	ldr r2, [sp, #0x58]
	adds r3, r6, #0
	bl FUN_081f0db4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081F1296
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F11CE
	adds r0, #4
	b _081F11DA
_081F11CE:
	ldr r0, _081F11F4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F11DA:
	ldrb r0, [r0]
	lsrs r0, r0, #4
	cmp r0, #0
	bne _081F1296
	ldr r0, [sp, #0x58]
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F11F8
	adds r0, #4
	b _081F1206
	.align 2, 0
_081F11F4: .4byte 0x030046A4
_081F11F8:
	ldr r0, _081F121C @ =0x030046A4
	ldr r1, [r0]
	ldr r2, [sp, #0x58]
	lsls r0, r2, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F1206:
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	adds r0, r6, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F1220
	adds r0, #4
	b _081F122C
	.align 2, 0
_081F121C: .4byte 0x030046A4
_081F1220:
	ldr r0, _081F12B4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F122C:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	adds r1, r0, #0
	subs r0, r4, r1
	cmp r0, #0
	bge _081F123C
	rsbs r0, r0, #0
_081F123C:
	cmp r0, #1
	bgt _081F1296
	lsls r0, r1, #8
	strh r0, [r5, #2]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081F12B8 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081F12BC @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x14
	movs r0, #3
	str r0, [sp]
	mov r3, sb
	str r3, [sp, #4]
	movs r0, #0x31
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	movs r2, #1
	str r2, [sp, #0x10]
	str r3, [sp, #0x14]
	str r3, [sp, #0x18]
	str r1, [sp, #0x1c]
	movs r0, #4
	str r0, [sp, #0x20]
	str r2, [sp, #0x24]
	ldr r0, _081F12C0 @ =0x00200004
	str r0, [sp, #0x28]
	movs r0, #0x1e
	str r0, [sp, #0x2c]
	movs r0, #8
	str r0, [sp, #0x30]
	str r0, [sp, #0x34]
	adds r0, r5, #0
	add r1, sp, #0x44
	ldr r2, _081F12C4 @ =0x00001C1A
	ldr r3, _081F12C8 @ =0x0000D1B8
	bl FUN_081f22c0
_081F1296:
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r1, r8
	cmp r1, #0
	beq _081F12A4
	b _081F10E2
_081F12A4:
	add sp, #0x5c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F12B4: .4byte 0x030046A4
_081F12B8: .4byte 0x000003FF
_081F12BC: .4byte 0x0203B400
_081F12C0: .4byte 0x00200004
_081F12C4: .4byte 0x00001C1A
_081F12C8: .4byte 0x0000D1B8

	thumb_func_start FUN_081f12cc
FUN_081f12cc: @ 0x081F12CC
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	adds r5, r7, #0
	adds r2, r7, #0
	adds r2, #0x92
	ldrb r0, [r2]
	cmp r0, #0
	beq _081F12EA
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	movs r0, #0
	strb r0, [r2]
_081F12EA:
	ldrh r0, [r7, #0x34]
	cmp r0, #3
	bne _081F12FE
	ldrh r0, [r7, #0x3a]
	cmp r0, #0
	bne _081F12FE
	adds r0, r7, #0
	movs r1, #4
	bl FUN_081f0fe0
_081F12FE:
	adds r4, r7, #0
	adds r4, #0x2c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x2c]
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
	beq _081F132E
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F1336
_081F132E:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F1336:
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
	beq _081F135A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F1362
_081F135A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F1362:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F139C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F13E2
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F13A6
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F13A0
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081F13BC
	.align 2, 0
_081F139C: .4byte 0x0000FFFF
_081F13A0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F13BA
_081F13A6:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F13BA
	strh r1, [r4, #8]
	movs r2, #1
	b _081F13BC
_081F13BA:
	movs r2, #0
_081F13BC:
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
	bne _081F13E4
	movs r0, #1
	strb r0, [r4, #7]
	b _081F13E4
_081F13E2:
	movs r2, #0
_081F13E4:
	cmp r2, #0
	beq _081F141C
	ldr r0, _081F1424 @ =0x030001E8
	ldr r2, [r0]
	adds r6, r7, #0
	adds r6, #0x8f
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r5, #1
	adds r1, r5, #0
	lsls r1, r0
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r7, #0
	adds r0, #0x8e
	movs r4, #0
	strb r4, [r0]
	adds r0, r7, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r6]
	adds r0, r7, #0
	adds r0, #0x8c
	strh r4, [r0]
	adds r0, #6
	strb r5, [r0]
_081F141C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F1424: .4byte 0x030001E8

	thumb_func_start FUN_081f1428
FUN_081f1428: @ 0x081F1428
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	adds r2, r5, #0
	adds r2, #0x92
	ldrb r0, [r2]
	cmp r0, #0
	beq _081F1440
	movs r1, #0
	strb r1, [r2]
	adds r0, r5, #0
	adds r0, #0x90
	strh r1, [r0]
_081F1440:
	adds r4, r5, #0
	adds r4, #0x90
	ldrh r1, [r4]
	adds r0, r5, #0
	movs r2, #0x3c
	movs r3, #0x28
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081F148C
	ldr r0, _081F1488 @ =0x030001E8
	ldr r2, [r0]
	adds r6, r5, #0
	adds r6, #0x8f
	movs r0, #0
	ldrsb r0, [r6, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2, #0x38]
	bics r0, r1
	str r0, [r2, #0x38]
	adds r0, r5, #0
	adds r0, #0x8e
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r0, #0xff
	strb r0, [r6]
	adds r0, r5, #0
	adds r0, #0x8c
	strh r4, [r0]
	b _081F1492
	.align 2, 0
_081F1488: .4byte 0x030001E8
_081F148C:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081F1492:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081f1498
FUN_081f1498: @ 0x081F1498
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r5, r1, #0
	mov sl, r2
	ldr r0, _081F14EC @ =0x030001E8
	ldr r7, [r0]
	cmp r7, #0
	bne _081F14BC
	bl Entity081f1770_Create
	adds r7, r0, #0
	cmp r7, #0
	beq _081F14E8
_081F14BC:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F14F0 @ =0x030047A4
	ldr r1, _081F14F4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F14E8
	movs r1, #4
	ldr r0, _081F14F8 @ =0x03002BC0
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081F14E8
	adds r0, r7, #0
	bl FUN_081f0bec
	mov r8, r0
	cmp r0, #0
	bne _081F14FC
_081F14E8:
	movs r0, #0
	b _081F165C
	.align 2, 0
_081F14EC: .4byte 0x030001E8
_081F14F0: .4byte 0x030047A4
_081F14F4: .4byte 0x030047A0
_081F14F8: .4byte 0x03002BC0
_081F14FC:
	mov r0, r8
	adds r0, #0x8c
	strh r4, [r0]
	adds r0, #7
	strb r5, [r0]
	subs r0, #1
	movs r4, #1
	strb r4, [r0]
	mov r1, r8
	adds r1, #0x8e
	movs r0, #2
	strb r0, [r1]
	mov r6, r8
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, r8
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	lsls r0, r5, #0x18
	add r3, sp, #4
	mov r2, sp
	adds r2, #5
	lsrs r0, r0, #0x18
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	adds r5, r2, #0
	cmp r1, #1
	bls _081F1548
	strb r4, [r5]
	subs r0, r0, r1
	strb r0, [r3]
	b _081F154E
_081F1548:
	movs r0, #0
	strb r0, [r5]
	strb r1, [r3]
_081F154E:
	adds r1, r7, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	mov r4, r8
	adds r4, #0x2c
	ldr r1, [r7, #0x34]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r5]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl AuxAnim_SetAnim
	ldr r0, [r6, #0xc]
	movs r1, #0xfc
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, r8
	ldr r1, [r2, #0x2c]
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
	beq _081F15A8
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081F15B0
_081F15A8:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F15B0:
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
	beq _081F15D4
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081F15DC
_081F15D4:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F15DC:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F1614 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081F164C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F1618
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F160C
	ldrb r0, [r4, #5]
_081F160C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F1628
	.align 2, 0
_081F1614: .4byte 0x0000FFFF
_081F1618:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F1628
	strh r1, [r4, #8]
_081F1628:
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
	bne _081F164C
	movs r0, #1
	strb r0, [r4, #7]
_081F164C:
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	strb r1, [r6, #7]
	mov r1, sl
	orrs r0, r1
	str r0, [r6]
	mov r0, r8
_081F165C:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081f1770_Update
Entity081f1770_Update: @ 0x081F166C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x3c
	ldr r0, [r5, #0x38]
	cmp r0, #0
	beq _081F16E6
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F16B0 @ =0x030047A4
	ldr r1, _081F16B4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F16E6
	movs r1, #4
	ldr r0, _081F16B8 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081F16E6
	movs r4, #0
	ldr r7, _081F16BC @ =0x085AE528
_081F169E:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F16C0
	movs r0, #1
	b _081F16C2
	.align 2, 0
_081F16B0: .4byte 0x030047A4
_081F16B4: .4byte 0x030047A0
_081F16B8: .4byte 0x03002BC0
_081F16BC: .4byte 0x085AE528
_081F16C0:
	movs r0, #0
_081F16C2:
	cmp r0, #0
	beq _081F16E0
	movs r0, #0x94
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r6
	adds r0, r1, #0
	adds r0, #0x8e
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081F16E0:
	adds r4, #1
	cmp r4, #0x13
	ble _081F169E
_081F16E6:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity081f1770_Destroy
Entity081f1770_Destroy: @ 0x081F16F0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_081F16F6:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F1706
	movs r0, #1
	b _081F1708
_081F1706:
	movs r0, #0
_081F1708:
	cmp r0, #0
	beq _081F1720
	movs r0, #0x94
	muls r0, r4, r0
	adds r0, #0x3c
	adds r1, r5, r0
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081F1720
	adds r0, r1, #0
	bl AuxSprite_Remove
_081F1720:
	adds r4, #1
	cmp r4, #0x13
	ble _081F16F6
	ldr r1, _081F1734 @ =0x030001E8
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081F1734: .4byte 0x030001E8

	thumb_func_start Entity081f1770_Init
Entity081f1770_Init: @ 0x081F1738
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _081F1760 @ =0x000084B4
	bl Video_GetAuxSprite
	ldr r0, _081F1764 @ =0x0000922E
	ldr r1, _081F1768 @ =0x00004EC0
	bl GetFile
	str r0, [r4, #0x34]
	movs r0, #0
	str r0, [r4, #0x38]
	ldr r0, _081F176C @ =0x030001E8
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F1760: .4byte 0x000084B4
_081F1764: .4byte 0x0000922E
_081F1768: .4byte 0x00004EC0
_081F176C: .4byte 0x030001E8

	thumb_func_start Entity081f1770_Create
Entity081f1770_Create: @ 0x081F1770
	push {r4, lr}
	ldr r0, _081F17A4 @ =0x030001E8
	ldr r0, [r0]
	cmp r0, #0
	bne _081F17B6
	ldr r1, _081F17A8 @ =0x00000BCC
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F17B4
	ldr r1, _081F17AC @ =Entity081f1770_Update
	ldr r2, _081F17B0 @ =Entity081f1770_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f1770_Init
	cmp r0, #0
	bge _081F17B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F17B6
	.align 2, 0
_081F17A4: .4byte 0x030001E8
_081F17A8: .4byte 0x00000BCC
_081F17AC: .4byte Entity081f1770_Update
_081F17B0: .4byte Entity081f1770_Destroy
_081F17B4:
	adds r0, r4, #0
_081F17B6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f17bc
FUN_081f17bc: @ 0x081F17BC
	ldr r1, _081F17C4 @ =0x030001E8
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F17C4: .4byte 0x030001E8
