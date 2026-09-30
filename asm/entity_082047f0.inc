	.include "asm/macros.inc"

	.syntax unified
	
	.text

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

	thumb_func_start Entity082047f0_Update
Entity082047f0_Update: @ 0x08204680
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

	thumb_func_start Entity082047f0_Destroy
Entity082047f0_Destroy: @ 0x08204708
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
	bl AuxSprite_Remove
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

	thumb_func_start Entity082047f0_Init
Entity082047f0_Init: @ 0x08204730
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
	bl Video_GetAuxSprite
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
	bl AuxSprite_Add
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

	thumb_func_start Entity082047f0_Create
Entity082047f0_Create: @ 0x082047F0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #8
	movs r1, #0xcc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08204828
	ldr r1, _08204820 @ =Entity082047f0_Update
	ldr r2, _08204824 @ =Entity082047f0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity082047f0_Init
	cmp r0, #0
	bge _08204828
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0820482A
	.align 2, 0
_08204820: .4byte Entity082047f0_Update
_08204824: .4byte Entity082047f0_Destroy
_08204828:
	adds r0, r4, #0
_0820482A:
	pop {r4, r5}
	pop {r1}
	bx r1
