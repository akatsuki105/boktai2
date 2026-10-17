	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081f7e68
FUN_081f7e68: @ 0x081F7E68
	movs r0, #0x8f
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x91
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #1
	strb r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f7e80
FUN_081f7e80: @ 0x081F7E80
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
	ldr r2, _081F7F0C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ldr r1, _081F7F10 @ =0x0000FFFF
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
	adds r4, #0xa8
	ldr r2, _081F7F14 @ =0x00002403
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
	ldr r1, _081F7F18 @ =FUN_081f7e68
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
_081F7F0C: .4byte 0xFFFF0000
_081F7F10: .4byte 0x0000FFFF
_081F7F14: .4byte 0x00002403
_081F7F18: .4byte FUN_081f7e68

	thumb_func_start FUN_081f7f1c
FUN_081f7f1c: @ 0x081F7F1C
	push {r4, lr}
	adds r1, r0, #0
	adds r4, r1, #0
	adds r4, #0xa8
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

	thumb_func_start FUN_081f7f3c
FUN_081f7f3c: @ 0x081F7F3C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r3, #0
	movs r5, #1
	adds r2, r4, #0
	adds r2, #0x3c
	movs r6, #0x92
	lsls r6, r6, #1
_081F7F4C:
	adds r0, r5, #0
	lsls r0, r3
	ldr r1, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F7F5C
	movs r0, #1
	b _081F7F5E
_081F7F5C:
	movs r0, #0
_081F7F5E:
	cmp r0, #0
	bne _081F7F78
	adds r0, r5, #0
	lsls r0, r3
	orrs r0, r1
	str r0, [r4, #0x38]
	ldr r1, _081F7F74 @ =0x0000011F
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r2, #0
	b _081F7F82
	.align 2, 0
_081F7F74: .4byte 0x0000011F
_081F7F78:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #7
	ble _081F7F4C
	movs r0, #0
_081F7F82:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f7f88
FUN_081f7f88: @ 0x081F7F88
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _081F7F9C @ =0x00000123
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081F7FA0
	subs r0, #1
	b _081F805C
	.align 2, 0
_081F7F9C: .4byte 0x00000123
_081F7FA0:
	movs r1, #0x85
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081F805E
	mov r3, sp
	adds r4, r5, #0
	adds r4, #0x1c
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl ArcTan2_8
	ldr r2, _081F7FF4 @ =0x00000109
	adds r1, r5, r2
	ldrb r1, [r1]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _081F7FFC
	ldr r0, _081F7FF8 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081F800A
	.align 2, 0
_081F7FF4: .4byte 0x00000109
_081F7FF8: .4byte 0xFFFFFF00
_081F7FFC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081F800A
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081F800A:
	adds r0, r1, #0
	cmp r1, #0
	bge _081F8012
	rsbs r0, r1, #0
_081F8012:
	cmp r0, #0x12
	ble _081F8054
	cmp r1, #0
	ble _081F8034
	ldr r0, _081F802C @ =0x00000109
	adds r1, r5, r0
	ldr r2, _081F8030 @ =0x0000010B
	adds r0, r5, r2
	ldrb r0, [r0]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	b _081F8044
	.align 2, 0
_081F802C: .4byte 0x00000109
_081F8030: .4byte 0x0000010B
_081F8034:
	ldr r0, _081F8050 @ =0x00000109
	adds r2, r5, r0
	adds r0, #2
	adds r1, r5, r0
	ldrb r0, [r2]
	ldrb r1, [r1]
	subs r0, r0, r1
	strb r0, [r2]
_081F8044:
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrb r0, [r1]
	subs r0, #1
	b _081F805C
	.align 2, 0
_081F8050: .4byte 0x00000109
_081F8054:
	movs r0, #0x85
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
_081F805C:
	strb r0, [r1]
_081F805E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f8068
FUN_081f8068: @ 0x081F8068
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	mov ip, r0
	ldr r4, _081F80B4 @ =0x0203B400
	ldr r3, _081F80B8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _081F80BC @ =0x000003FF
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
	ldr r1, _081F80C0 @ =gSineTable
	adds r0, r7, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F80C4
	asrs r2, r0, #0xc
	b _081F80CA
	.align 2, 0
_081F80B4: .4byte 0x0203B400
_081F80B8: .4byte 0x030046B8
_081F80BC: .4byte 0x000003FF
_081F80C0: .4byte gSineTable
_081F80C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F80CA:
	movs r0, #0
	strh r2, [r4]
	strh r0, [r4, #2]
	lsls r0, r7, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081F80E2
	asrs r0, r0, #0xc
	b _081F80E8
_081F80E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F80E8:
	strh r0, [r4, #4]
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _081F8118 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _081F811C @ =0x0203B400
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
_081F8118: .4byte 0x000003FF
_081F811C: .4byte 0x0203B400

	thumb_func_start FUN_081f8120
FUN_081f8120: @ 0x081F8120
	bx lr
	.align 2, 0

	thumb_func_start FUN_081f8124
FUN_081f8124: @ 0x081F8124
	push {r4, r5, r6, lr}
	adds r5, r1, #0
	movs r0, #0x91
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081F8160
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	movs r1, #0x89
	lsls r1, r1, #1
	adds r3, r5, r1
	movs r2, #0
	movs r1, #0
	movs r0, #0xf
	strh r0, [r3]
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
	strb r2, [r4]
	movs r0, #1
	strb r0, [r5, #8]
	strb r0, [r5, #9]
_081F8160:
	movs r1, #0x90
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _081F817A
	adds r0, r5, #0
	adds r0, #0x1c
	bl FUN_081f8068
_081F817A:
	movs r2, #0x89
	lsls r2, r2, #1
	adds r6, r5, r2
	movs r3, #0
	ldrsh r0, [r6, r3]
	cmp r0, #0
	ble _081F81BA
	movs r0, #8
	ldrsb r0, [r5, r0]
	movs r4, #0x40
	subs r0, r4, r0
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl Div
	ldrb r1, [r5, #8]
	adds r1, r1, r0
	strb r1, [r5, #8]
	movs r0, #9
	ldrsb r0, [r5, r0]
	subs r4, r4, r0
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r0, r4, #0
	bl Div
	ldrb r1, [r5, #9]
	adds r1, r1, r0
	strb r1, [r5, #9]
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
_081F81BA:
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
	beq _081F81EA
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F81F2
_081F81EA:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F81F2:
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
	beq _081F8216
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F821E
_081F8216:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F821E:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F8254 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F828C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F8258
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F824E
	ldrb r0, [r4, #5]
_081F824E:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F8268
	.align 2, 0
_081F8254: .4byte 0x0000FFFF
_081F8258:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F8268
	strh r1, [r4, #8]
_081F8268:
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
	bne _081F828C
	movs r0, #1
	strb r0, [r4, #7]
_081F828C:
	movs r3, #0x89
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bgt _081F82B8
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #2
	strb r0, [r1]
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r3, #0x10
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _081F82C4
_081F82B8:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081F82C4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f82cc
FUN_081f82cc: @ 0x081F82CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r1, #0
	movs r0, #0x91
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F8302
	movs r2, #0x90
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	movs r3, #0x88
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x3c
	bl AuxShadow_Show
	strb r4, [r6]
_081F8302:
	ldr r4, _081F8378 @ =0x00000109
	adds r6, r5, r4
	ldrb r0, [r6]
	rsbs r0, r0, #0
	strb r0, [r5, #6]
	mov r3, sp
	adds r4, r5, #0
	adds r4, #0x1c
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	mov r8, r1
	adds r0, r5, #0
	bl FUN_081f7f88
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r3, [r0]
	ldr r2, _081F837C @ =gSineTable
	ldrb r0, [r6]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _081F8380
	asrs r0, r0, #0xc
	b _081F8386
	.align 2, 0
_081F8378: .4byte 0x00000109
_081F837C: .4byte gSineTable
_081F8380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081F8386:
	adds r3, r5, #0
	adds r3, #0xf8
	strh r0, [r3]
	movs r4, #0x86
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r2, [r0]
	ldr r1, _081F83B0 @ =gSineTable
	subs r4, #3
	adds r0, r5, r4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	adds r6, r3, #0
	cmp r0, #0
	blt _081F83B4
	asrs r2, r0, #0xc
	b _081F83BA
	.align 2, 0
_081F83B0: .4byte gSineTable
_081F83B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_081F83BA:
	adds r0, r5, #0
	adds r0, #0xfc
	strh r2, [r0]
	mov r2, sp
	ldrh r0, [r6]
	ldrh r3, [r5, #0x1c]
	adds r0, r0, r3
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r6, #2]
	ldrh r4, [r7, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r1, [r6, #4]
	ldrh r0, [r7, #4]
	adds r1, r1, r0
	strh r1, [r2, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _081F8400
	cmp r1, #0
	blt _081F8400
	ldr r0, _081F8404 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081F8400
	ldr r0, _081F8408 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081F840C
_081F8400:
	movs r4, #0
	b _081F841A
	.align 2, 0
_081F8404: .4byte 0x030046A8
_081F8408: .4byte 0x030046AC
_081F840C:
	ldr r0, _081F842C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081F841A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081F8430
	adds r0, #4
	b _081F843C
	.align 2, 0
_081F842C: .4byte 0x030046A4
_081F8430:
	ldr r0, _081F8464 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081F843C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	cmp r1, r0
	bge _081F8450
	cmp r1, #0
	bne _081F8468
_081F8450:
	movs r3, #0x8f
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r0, #3
	strb r0, [r1]
	movs r4, #0x91
	lsls r4, r4, #1
	adds r1, r5, r4
	b _081F860E
	.align 2, 0
_081F8464: .4byte 0x030046A4
_081F8468:
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r7, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r7, #2]
	ldrh r0, [r7, #4]
	ldrh r6, [r6, #4]
	adds r0, r0, r6
	strh r0, [r7, #4]
	movs r3, #0x90
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _081F84BC
	movs r4, #0x86
	lsls r4, r4, #1
	adds r2, r5, r4
	movs r0, #0x87
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _081F84BA
	movs r3, #0x88
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrb r4, [r1]
	adds r0, r0, r4
	strh r0, [r2]
	ldrb r0, [r1]
	adds r0, #4
	strb r0, [r1]
	b _081F84BC
_081F84BA:
	strh r1, [r2]
_081F84BC:
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x3b
	ble _081F84DA
	movs r2, #0x90
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0x28
	bls _081F84EE
	ldr r0, _081F8544 @ =0x0003FFFF
	cmp r8, r0
	bgt _081F84EE
_081F84DA:
	adds r2, r5, #0
	adds r2, #0xfa
	ldrh r0, [r2]
	subs r0, #3
	movs r1, #0
	strh r0, [r2]
	movs r3, #0x85
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r1, [r0]
_081F84EE:
	movs r0, #0x90
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #8
	bl Mod
	cmp r0, #0
	bne _081F8506
	adds r0, r7, #0
	bl FUN_081f8068
_081F8506:
	adds r0, r5, #0
	bl FUN_081f7f1c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
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
	beq _081F8548
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081F8550
	.align 2, 0
_081F8544: .4byte 0x0003FFFF
_081F8548:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F8550:
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
	beq _081F8574
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081F857C
_081F8574:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F857C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081F85B4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _081F85EC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F85B8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081F85AC
	ldrb r0, [r4, #5]
_081F85AC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081F85C8
	.align 2, 0
_081F85B4: .4byte 0x0000FFFF
_081F85B8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081F85C8
	strh r1, [r4, #8]
_081F85C8:
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
	bne _081F85EC
	movs r0, #1
	strb r0, [r4, #7]
_081F85EC:
	movs r3, #0x8c
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	cmp r0, #0
	ble _081F85FE
	subs r0, #1
	str r0, [r1]
	b _081F8612
_081F85FE:
	movs r4, #0x8f
	lsls r4, r4, #1
	adds r1, r5, r4
	movs r0, #3
	strb r0, [r1]
	movs r0, #0x91
	lsls r0, r0, #1
	adds r1, r5, r0
_081F860E:
	movs r0, #1
	strb r0, [r1]
_081F8612:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081f8620
FUN_081f8620: @ 0x081F8620
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	adds r4, r1, #0
	movs r0, #0x91
	lsls r0, r0, #1
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081F869E
	adds r0, r4, #0
	adds r0, #0x1c
	movs r1, #0x40
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	movs r1, #0x10
	str r1, [sp, #8]
	movs r1, #2
	movs r2, #0
	movs r3, #0x80
	bl SpawnAttackBox
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	mov r8, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081F86AC @ =0x00000111
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081F8676
	adds r0, r4, #0
	adds r0, #0x3c
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r5]
_081F8676:
	adds r0, r4, #0
	bl AuxSprite_Remove
	ldr r0, _081F86B0 @ =0x0000011F
	adds r2, r4, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	movs r1, #1
	lsls r1, r0
	ldr r0, [r6, #0x38]
	bics r0, r1
	str r0, [r6, #0x38]
	movs r0, #0xff
	strb r0, [r2]
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r1, r8
	strb r1, [r0]
	strb r1, [r7]
_081F869E:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F86AC: .4byte 0x00000111
_081F86B0: .4byte 0x0000011F

	thumb_func_start FUN_081f86b4
FUN_081f86b4: @ 0x081F86B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sl, r0
	adds r6, r1, #0
	mov sb, r2
	adds r4, r3, #0
	ldr r0, _081F87E4 @ =0x03000208
	ldr r5, [r0]
	cmp r5, #0
	bne _081F86DC
	bl Entity081f8a28_Create
	adds r5, r0, #0
	cmp r5, #0
	bne _081F86DC
	b _081F8910
_081F86DC:
	adds r0, r5, #0
	bl FUN_081f7f3c
	adds r7, r0, #0
	cmp r7, #0
	bne _081F86EA
	b _081F8910
_081F86EA:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #1
	mov r8, r2
	mov r1, r8
	strb r1, [r0]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0x78
	str r0, [r1]
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r2, #0
	strh r2, [r0]
	subs r1, #0x14
	adds r0, r7, r1
	strb r4, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r1, _081F87E8 @ =0x00000109
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	ldr r0, [sp, #0x40]
	strb r0, [r1]
	ldr r0, _081F87EC @ =0x0000010B
	adds r1, r7, r0
	ldr r0, [sp, #0x44]
	strb r0, [r1]
	adds r2, #0x19
	adds r1, r7, r2
	ldr r0, [sp, #0x48]
	strb r0, [r1]
	movs r0, #0x86
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [sp, #0x4c]
	strh r0, [r1]
	subs r2, #0x15
	adds r1, r7, r2
	ldr r0, [sp, #0x50]
	strh r0, [r1]
	movs r1, #0x91
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0xf8
	movs r0, #0
	str r0, [sp, #0x1c]
	add r0, sp, #0x1c
	ldr r2, _081F87F0 @ =0x05000002
	bl CpuSet
	adds r0, r7, #0
	adds r0, #0xfa
	mov r1, sb
	strh r1, [r0]
	mov sb, r7
	mov r2, sl
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldr r0, _081F87F4 @ =0x0000922E
	ldr r1, _081F87F8 @ =0x0000121B
	bl GetFile
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r4, r7, r1
	str r0, [r4]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r7, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r5, r7, #0
	adds r5, #0x2c
	ldr r1, [r4]
	movs r2, #0
	str r2, [sp]
	adds r0, r5, #0
	movs r2, #7
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r7, #0xc]
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
	mov r1, r8
	ands r1, r0
	ldrh r2, [r4]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _081F87FC
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081F8804
	.align 2, 0
_081F87E4: .4byte 0x03000208
_081F87E8: .4byte 0x00000109
_081F87EC: .4byte 0x0000010B
_081F87F0: .4byte 0x05000002
_081F87F4: .4byte 0x0000922E
_081F87F8: .4byte 0x0000121B
_081F87FC:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081F8804:
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
	beq _081F8828
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081F8830
_081F8828:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081F8830:
	str r0, [r7]
	ldrh r0, [r5, #0xe]
	adds r0, #1
	strh r0, [r5, #0xe]
	ldr r1, _081F8868 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r5, #7]
	cmp r0, r1
	blo _081F88A0
	movs r0, #0
	strh r0, [r5, #0xe]
	ldrb r1, [r5, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081F886C
	ldrh r0, [r5, #8]
	cmp r0, #0
	bne _081F8860
	ldrb r0, [r5, #5]
_081F8860:
	subs r0, #1
	strh r0, [r5, #8]
	b _081F887C
	.align 2, 0
_081F8868: .4byte 0x0000FFFF
_081F886C:
	ldrh r0, [r5, #8]
	adds r0, #1
	strh r0, [r5, #8]
	ands r0, r2
	ldrb r2, [r5, #5]
	cmp r0, r2
	blo _081F887C
	strh r1, [r5, #8]
_081F887C:
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
	bne _081F88A0
	movs r0, #1
	strb r0, [r5, #7]
_081F88A0:
	movs r4, #0
	movs r0, #2
	mov r1, sb
	strb r0, [r1, #7]
	ldr r0, [r1]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, sb
	str r0, [r2]
	ldr r0, [sp, #0x60]
	str r0, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r7, #0
	ldr r1, [sp, #0x54]
	ldr r2, [sp, #0x58]
	ldr r3, [sp, #0x5c]
	bl FUN_081f7e80
	adds r5, r7, #0
	adds r5, #0x3c
	adds r1, r7, #0
	adds r1, #0x1c
	movs r0, #0x40
	str r0, [sp]
	movs r0, #0x64
	str r0, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #5
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r4, [sp, #0x18]
	adds r0, r5, #0
	movs r2, #0x40
	movs r3, #0x40
	bl AuxShadow_Init
	ldr r2, _081F8920 @ =0x00000111
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _081F8924 @ =0x00001C1B
	adds r0, r5, #0
	movs r2, #6
	bl AuxShadow_SetSprite
	adds r0, r5, #0
	movs r1, #0
	bl AuxShadow_SetAffine
	adds r0, r5, #0
	bl AuxShadow_Hide
_081F8910:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081F8920: .4byte 0x00000111
_081F8924: .4byte 0x00001C1B

	thumb_func_start Entity081f8a28_Update
Entity081f8a28_Update: @ 0x081F8928
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _081F8980
	movs r7, #0
	ldr r0, _081F8958 @ =0x085AE5C0
	mov r8, r0
	movs r0, #0xad
	lsls r0, r0, #1
	adds r6, r4, r0
	adds r5, r1, #0
_081F8948:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F895C
	movs r0, #1
	b _081F895E
	.align 2, 0
_081F8958: .4byte 0x085AE5C0
_081F895C:
	movs r0, #0
_081F895E:
	cmp r0, #0
	beq _081F8972
	ldrb r0, [r6]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_081F8972:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #7
	ble _081F8948
_081F8980:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity081f8a28_Destroy
Entity081f8a28_Destroy: @ 0x081F898C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r7, #0
	ldr r0, _081F89B4 @ =0x0000014D
	adds r4, r6, r0
	adds r5, r6, #0
	adds r5, #0x78
	movs r0, #0
	mov r8, r0
_081F89A2:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F89B8
	movs r0, #1
	b _081F89BA
	.align 2, 0
_081F89B4: .4byte 0x0000014D
_081F89B8:
	movs r0, #0
_081F89BA:
	cmp r0, #0
	beq _081F89D8
	ldrb r0, [r4]
	cmp r0, #0
	bne _081F89CE
	adds r0, r5, #0
	bl AuxShadow_Remove
	movs r0, #0xff
	strb r0, [r4]
_081F89CE:
	mov r0, r8
	adds r0, #0x3c
	adds r0, r6, r0
	bl AuxSprite_Remove
_081F89D8:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, r5, r0
	add r8, r0
	adds r7, #1
	cmp r7, #7
	ble _081F89A2
	movs r1, #0
	ldr r0, _081F89FC @ =0x03000208
	str r1, [r0]
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F89FC: .4byte 0x03000208

	thumb_func_start Entity081f8a28_Init
Entity081f8a28_Init: @ 0x081F8A00
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0
	str r0, [r4, #0x38]
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, _081F8A20 @ =0x0000F422
	bl Video_GetAuxSprite
	ldr r0, _081F8A24 @ =0x03000208
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081F8A20: .4byte 0x0000F422
_081F8A24: .4byte 0x03000208

	thumb_func_start Entity081f8a28_Create
Entity081f8a28_Create: @ 0x081F8A28
	push {r4, lr}
	ldr r0, _081F8A5C @ =0x03000208
	ldr r0, [r0]
	cmp r0, #0
	bne _081F8A6E
	ldr r1, _081F8A60 @ =0x0000095C
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081F8A6C
	ldr r1, _081F8A64 @ =Entity081f8a28_Update
	ldr r2, _081F8A68 @ =Entity081f8a28_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081f8a28_Init
	cmp r0, #0
	bge _081F8A6C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081F8A6E
	.align 2, 0
_081F8A5C: .4byte 0x03000208
_081F8A60: .4byte 0x0000095C
_081F8A64: .4byte Entity081f8a28_Update
_081F8A68: .4byte Entity081f8a28_Destroy
_081F8A6C:
	adds r0, r4, #0
_081F8A6E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081f8a74
FUN_081f8a74: @ 0x081F8A74
	ldr r1, _081F8A7C @ =0x03000208
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081F8A7C: .4byte 0x03000208

	thumb_func_start FUN_081f8a80
FUN_081f8a80: @ 0x081F8A80
	push {r4, lr}
	ldr r0, _081F8AB0 @ =0x03000208
	ldr r0, [r0]
	cmp r0, #0
	beq _081F8AA8
	movs r4, #3
	movs r2, #0xad
	lsls r2, r2, #1
	adds r1, r0, r2
	movs r3, #0x92
	lsls r3, r3, #1
	movs r2, #7
_081F8A98:
	ldrb r0, [r1]
	cmp r0, #2
	bne _081F8AA0
	strb r4, [r1]
_081F8AA0:
	adds r1, r1, r3
	subs r2, #1
	cmp r2, #0
	bge _081F8A98
_081F8AA8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081F8AB0: .4byte 0x03000208
