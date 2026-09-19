	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08080c64
FUN_08080c64: @ 0x08080C64
	push {lr}
	adds r3, r0, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _08080C90
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _08080C88 @ =0x000002E6
	adds r1, r3, r2
	strb r0, [r1]
	ldr r0, _08080C8C @ =0x000002E7
	adds r1, r3, r0
	movs r0, #1
	strb r0, [r1]
	b _08080C9E
	.align 2, 0
_08080C88: .4byte 0x000002E6
_08080C8C: .4byte 0x000002E7
_08080C90:
	ldr r1, _08080CA4 @ =0x000002E6
	adds r0, r3, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _08080CA8 @ =0x000002E7
	adds r0, r3, r2
	strb r1, [r0]
_08080C9E:
	pop {r0}
	bx r0
	.align 2, 0
_08080CA4: .4byte 0x000002E6
_08080CA8: .4byte 0x000002E7

	thumb_func_start FUN_08080cac
FUN_08080cac: @ 0x08080CAC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r2, #0
	movs r3, #0
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, r1
	bne _08080CC4
	movs r3, #1
_08080CC4:
	strh r1, [r2]
	adds r4, r6, #0
	adds r4, #0x88
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _08080CFC @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, r1, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r1, _08080D00 @ =0x000002E7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08080D04
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _08080D10
	.align 2, 0
_08080CFC: .4byte 0x000002E6
_08080D00: .4byte 0x000002E7
_08080D04:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_08080D10:
	str r1, [r0]
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
	adds r0, r4, #0
	adds r1, r5, #0
	bl MainSprite_AdvanceAnim
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08080d2c
FUN_08080d2c: @ 0x08080D2C
	push {r4, lr}
	mov ip, r0
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08080D60 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080D64
	asrs r0, r0, #0xc
	b _08080D6A
	.align 2, 0
_08080D60: .4byte 0x085B0A08
_08080D64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080D6A:
	mov r1, ip
	strh r0, [r1, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08080D80
	asrs r0, r0, #0xc
	b _08080D86
_08080D80:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08080D86:
	mov r1, ip
	strh r0, [r1, #0x38]
	ldr r3, _08080DAC @ =0x000001C7
	add r3, ip
	ldrb r3, [r3]
	cmp r3, #1
	bne _08080DCE
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _08080DB0
	movs r2, #0x38
	ldrsh r1, [r1, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08080DBE
	b _08080DC2
	.align 2, 0
_08080DAC: .4byte 0x000001C7
_08080DB0:
	mov r2, ip
	movs r0, #0x38
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08080DC2
_08080DBE:
	asrs r0, r0, #6
	b _08080DC8
_08080DC2:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08080DC8:
	mov r1, ip
	strh r0, [r1, #0x38]
	b _08080E06
_08080DCE:
	cmp r3, #2
	bne _08080E06
	mov r2, ip
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _08080DEA
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _08080DF8
	b _08080DFC
_08080DEA:
	mov r2, ip
	movs r0, #0x34
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _08080DFC
_08080DF8:
	asrs r0, r0, #6
	b _08080E02
_08080DFC:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_08080E02:
	mov r1, ip
	strh r0, [r1, #0x34]
_08080E06:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08080e0c
FUN_08080e0c: @ 0x08080E0C
	push {r4, lr}
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r3, r0, r4
	movs r4, #0
	strb r1, [r3]
	ldr r3, _08080E2C @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _08080E30 @ =0x0000037E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080E2C: .4byte 0x0000037D
_08080E30: .4byte 0x0000037E

	thumb_func_start FUN_08080e34
FUN_08080e34: @ 0x08080E34
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	str r0, [r4, #0x20]
	ldr r1, _08080EB4 @ =0x0000038E
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r1, _08080EB8 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r2, #0xb2
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r0, #0
	bne _08080E68
	adds r0, r4, #0
	bl FUN_0809e138
	cmp r0, #0
	beq _08080E68
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_08080E68:
	movs r1, #0x80
	lsls r1, r1, #2
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08080E84
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_08080E84:
	ldr r1, _08080EBC @ =0x00000604
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08080EC0 @ =0x00000606
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r2, _08080EC4 @ =0x0000035A
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08080EB4: .4byte 0x0000038E
_08080EB8: .4byte 0x030046A0
_08080EBC: .4byte 0x00000604
_08080EC0: .4byte 0x00000606
_08080EC4: .4byte 0x0000035A

	thumb_func_start FUN_08080ec8
FUN_08080ec8: @ 0x08080EC8
	ldr r2, _08080ED4 @ =0x0000035A
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08080ED4: .4byte 0x0000035A

	thumb_func_start FUN_08080ed8
FUN_08080ed8: @ 0x08080ED8
	ldr r2, _08080EE4 @ =0x0000035A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	bx lr
	.align 2, 0
_08080EE4: .4byte 0x0000035A

	thumb_func_start FUN_08080ee8
FUN_08080ee8: @ 0x08080EE8
	push {lr}
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _08080EFE
	movs r0, #0xd8
	bl sound_08240740
	b _08080F10
_08080EFE:
	ldr r0, _08080F14 @ =0x00000239
	bl sound_08240740
	ldr r0, _08080F18 @ =0x00000202
	bl sound_08240740
	ldr r0, _08080F1C @ =0x00000366
	bl sound_08240740
_08080F10:
	pop {r0}
	bx r0
	.align 2, 0
_08080F14: .4byte 0x00000239
_08080F18: .4byte 0x00000202
_08080F1C: .4byte 0x00000366

	thumb_func_start FUN_08080f20
FUN_08080f20: @ 0x08080F20
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08080F3E
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _08080F70
_08080F3E:
	movs r0, #0x24
	ldrsh r1, [r2, r0]
	movs r4, #0x24
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #0x28
	ldrsh r1, [r2, r0]
	movs r2, #0x28
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r4, #0
	bne _08080F66
	cmp r1, #0
	bne _08080F66
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _08080F70
_08080F66:
	adds r0, r4, #0
	bl ArcTan2_8
	adds r1, r0, #0
	adds r1, #0x60
_08080F70:
	movs r0, #0xff
	ands r1, r0
	asrs r0, r1, #6
	lsls r0, r0, #1
	adds r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08080f80
FUN_08080f80: @ 0x08080F80
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	adds r1, #0x40
	ldrh r0, [r1]
	adds r6, r5, #0
	adds r6, #0x40
	movs r7, #0
	strh r0, [r6]
	ldrh r0, [r1]
	cmp r0, #0xc8
	bls _08080F9E
	movs r0, #0xc8
	strh r0, [r6]
_08080F9E:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r2, [r3, #0x38]
	ands r2, r0
	cmp r2, #0
	beq _08080FC8
	ldr r0, _08080FC4 @ =0x000003D2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	b _08081098
	.align 2, 0
_08080FC4: .4byte 0x000003D2
_08080FC8:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08080FE0
	ldrh r0, [r5, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r5, #6]
	strh r2, [r6]
	b _0808109A
_08080FE0:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _08081084
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08081014
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r4, r2
	b _08081064
_08081014:
	movs r0, #0x24
	ldrsh r1, [r3, r0]
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	movs r0, #0x28
	ldrsh r1, [r3, r0]
	movs r3, #0x28
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _08081042
	cmp r1, #0
	bne _08081042
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _08081066
_08081042:
	adds r0, r2, #0
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #4
	ands r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
_08081064:
	strh r0, [r1]
_08081066:
	adds r3, r5, #0
	adds r3, #0x40
	ldrh r2, [r3]
	ldr r1, _08081080 @ =0x000003E6
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	strh r1, [r3]
	ldrh r1, [r5, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5, #6]
	b _0808109A
	.align 2, 0
_08081080: .4byte 0x000003E6
_08081084:
	ldr r2, _080810A0 @ =0x000003D2
	adds r0, r4, r2
	strb r7, [r0]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
_08081098:
	strb r0, [r1]
_0808109A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080810A0: .4byte 0x000003D2

	thumb_func_start FUN_080810a4
FUN_080810a4: @ 0x080810A4
	push {lr}
	adds r2, r0, #0
	ldr r1, _080810E8 @ =0x0000038E
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r1, _080810EC @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bgt _080810E4
	movs r1, #0x80
	lsls r1, r1, #3
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080810E4
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _080810E4
	cmp r1, #0
	bne _080810F0
_080810E4:
	movs r0, #1
	b _080810F2
	.align 2, 0
_080810E8: .4byte 0x0000038E
_080810EC: .4byte 0x030046A0
_080810F0:
	movs r0, #0
_080810F2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080810f8
FUN_080810f8: @ 0x080810F8
	push {r4, lr}
	movs r4, #0
_080810FC:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bls _08081110
	adds r4, #1
	cmp r4, #0xf
	ble _080810FC
	movs r0, #0
_08081110:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08081118
FUN_08081118: @ 0x08081118
	push {lr}
	sub sp, #0xc
	adds r3, r1, #0
	ldr r1, _08081148 @ =0x000009C4
	adds r0, r0, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _08081142
	ldr r1, _0808114C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r1
	movs r1, #1
	orrs r0, r1
	str r0, [sp, #4]
	str r3, [sp]
	add r1, sp, #4
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_08081142:
	add sp, #0xc
	pop {r0}
	bx r0
	.align 2, 0
_08081148: .4byte 0x000009C4
_0808114C: .4byte 0xFFFF0000

	thumb_func_start FUN_08081150
FUN_08081150: @ 0x08081150
	ldr r2, _0808115C @ =0x000009BC
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_0808115C: .4byte 0x000009BC

	thumb_func_start FUN_08081160
FUN_08081160: @ 0x08081160
	ldr r2, _0808116C @ =0x000009BC
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	bx lr
	.align 2, 0
_0808116C: .4byte 0x000009BC

	thumb_func_start FUN_08081170
FUN_08081170: @ 0x08081170
	push {lr}
	movs r1, #0x9c
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _08081184
	movs r1, #0
	bl Script_ExecById
_08081184:
	pop {r0}
	bx r0

	thumb_func_start FUN_08081188
FUN_08081188: @ 0x08081188
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r2, r0, #0
	ldr r1, _080811CC @ =0x03003584
	ldr r3, _080811D0 @ =0x0000094C
	adds r0, r2, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	ldr r0, _080811D4 @ =0x0000094E
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080811D8
	movs r5, #0
	movs r3, #0xa9
	lsls r3, r3, #2
	adds r1, r2, r3
_080811B2:
	subs r0, r5, #5
	cmp r0, #1
	bls _080811C0
	cmp r5, #0xd
	beq _080811C0
	ldrh r0, [r6]
	strh r0, [r1]
_080811C0:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080811B2
	b _08081234
	.align 2, 0
_080811CC: .4byte 0x03003584
_080811D0: .4byte 0x0000094C
_080811D4: .4byte 0x0000094E
_080811D8:
	movs r5, #0
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r2, r0
_080811E2:
	subs r0, r5, #5
	cmp r0, #1
	bls _0808122A
	cmp r5, #0xd
	beq _0808122A
	ldrh r1, [r6]
	movs r3, #0x1f
	mov ip, r3
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _08081202
	movs r4, #0x1f
_08081202:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _08081212
	movs r1, #0x1f
_08081212:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _08081220
	movs r0, #0x1f
_08081220:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_0808122A:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080811E2
_08081234:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08081240
FUN_08081240: @ 0x08081240
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _0808125C @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08081260 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08081264
	movs r0, #1
	b _08081266
	.align 2, 0
_0808125C: .4byte 0x030046A0
_08081260: .4byte 0x00000934
_08081264:
	movs r0, #0
_08081266:
	cmp r0, #0
	bne _08081278
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08081284
	movs r3, #8
	b _08081284
_08081278:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08081284
	movs r3, #4
_08081284:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0808128c
FUN_0808128c: @ 0x0808128C
	push {r4, lr}
	ldr r1, _080812C8 @ =0x03003584
	ldr r2, [r1]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r2, r2, r1
	movs r3, #0x95
	lsls r3, r3, #4
	adds r1, r0, r3
	ldrb r3, [r1]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r2, r2, r1
	ldrh r3, [r2]
	ldr r4, _080812CC @ =0x000002AE
	adds r1, r0, r4
	strh r3, [r1]
	adds r2, #2
	ldrh r3, [r2]
	adds r4, #2
	adds r1, r0, r4
	strh r3, [r1]
	ldrh r1, [r2, #2]
	ldr r2, _080812D0 @ =0x000002BE
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080812C8: .4byte 0x03003584
_080812CC: .4byte 0x000002AE
_080812D0: .4byte 0x000002BE

	thumb_func_start FUN_080812d4
FUN_080812d4: @ 0x080812D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	str r0, [sp]
	mov ip, r2
	str r3, [sp, #4]
	cmp r2, #0
	bne _080812F8
	adds r1, r0, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r0, r2
	str r0, [r1]
	b _080813BE
_080812F8:
	mov sl, r1
	movs r3, #0
	mov r8, r3
	ldr r7, [sp]
	adds r7, #0xd0
	str r7, [sp, #0xc]
	ldr r0, [sp]
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r6, r0, r1
	ldr r2, _08081324 @ =0x0000094E
	adds r2, r0, r2
	str r2, [sp, #8]
_08081312:
	mov r0, r8
	subs r0, #5
	cmp r0, #1
	bls _08081320
	mov r3, r8
	cmp r3, #0xd
	bne _08081328
_08081320:
	ldrh r0, [r6]
	b _080813A0
	.align 2, 0
_08081324: .4byte 0x0000094E
_08081328:
	mov r7, sl
	ldrh r2, [r7]
	movs r7, #0x1f
	movs r0, #0x1f
	mov sb, r0
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _08081340
	movs r4, #0x1f
_08081340:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _0808134E
	movs r2, #0x1f
_0808134E:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _0808135A
	movs r5, #0x1f
_0808135A:
	ldrh r1, [r6]
	mov r0, sb
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	adds r4, r7, #0
	ldr r7, [sp, #4]
	muls r0, r7, r0
	adds r4, r4, r0
	ldr r0, [sp, #0x30]
	asrs r4, r0
	mov r7, ip
	muls r7, r2, r7
	adds r2, r7, #0
	ldr r7, [sp, #4]
	adds r0, r3, #0
	muls r0, r7, r0
	adds r2, r2, r0
	ldr r0, [sp, #0x30]
	asrs r2, r0
	mov r0, ip
	muls r0, r5, r0
	muls r1, r7, r1
	adds r0, r0, r1
	ldr r1, [sp, #0x30]
	asrs r0, r1
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
_080813A0:
	strh r0, [r6, #0x20]
	movs r2, #2
	add sl, r2
	adds r6, #2
	movs r3, #1
	add r8, r3
	mov r7, r8
	cmp r7, #0xf
	ble _08081312
	ldr r1, [sp]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r1, r2
	ldr r3, [sp, #0xc]
	str r0, [r3]
_080813BE:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080813d0
FUN_080813d0: @ 0x080813D0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, _08081450 @ =0x00000951
	adds r0, r4, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r4, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080813F2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_0808128c
_080813F2:
	adds r0, r4, #0
	bl FUN_08081240
	adds r2, r0, #0
	ldr r6, _08081454 @ =0x0000094C
	adds r1, r4, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r5
	bne _08081410
	adds r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _0808141E
_08081410:
	strh r5, [r1]
	ldr r1, _08081458 @ =0x0000094E
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08081188
_0808141E:
	ldr r2, _0808145C @ =0x00000476
	adds r0, r4, r2
	ldrb r5, [r0]
	cmp r5, #0
	beq _0808148C
	ldr r0, _08081460 @ =0x03003584
	ldr r0, [r0]
	movs r3, #0x99
	lsls r3, r3, #6
	adds r5, r0, r3
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r1, r4, r0
	subs r0, #0x20
	adds r2, r4, r0
_08081442:
	subs r0, r3, #5
	cmp r0, #1
	bls _0808144C
	cmp r3, #0xd
	bne _08081464
_0808144C:
	ldrh r0, [r2]
	b _08081466
	.align 2, 0
_08081450: .4byte 0x00000951
_08081454: .4byte 0x0000094C
_08081458: .4byte 0x0000094E
_0808145C: .4byte 0x00000476
_08081460: .4byte 0x03003584
_08081464:
	ldrh r0, [r5]
_08081466:
	strh r0, [r1]
	adds r5, #2
	adds r1, #2
	adds r2, #2
	adds r3, #1
	cmp r3, #0xf
	ble _08081442
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6]
	ldr r2, _08081488 @ =0x00000476
	adds r1, r4, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	b _0808159C
	.align 2, 0
_08081488: .4byte 0x00000476
_0808148C:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r4, r3
	ldrh r0, [r2]
	cmp r0, #0
	bne _08081512
	ldr r6, _080814D4 @ =0x00000964
	adds r3, r4, r6
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _08081502
	ldr r1, _080814D8 @ =0x03003584
	subs r6, #2
	adds r0, r4, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080814C6
	movs r0, #0x30
	strh r0, [r3]
_080814C6:
	ldrh r0, [r3]
	cmp r0, #0x1f
	bhi _080814DC
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080814F0
	.align 2, 0
_080814D4: .4byte 0x00000964
_080814D8: .4byte 0x03003584
_080814DC:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080814F0
	strh r5, [r3]
_080814F0:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080812d4
	b _0808159C
_08081502:
	strh r5, [r3]
	adds r1, r4, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r4, r2
	str r0, [r1]
	b _0808159C
_08081512:
	ldr r3, _0808154C @ =0x00000964
	adds r0, r4, r3
	strh r5, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _08081572
	ldr r1, _08081550 @ =0x03003584
	ldr r6, _08081554 @ =0x0000095E
	adds r0, r4, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r5, r1, r0
	movs r1, #0
	adds r6, r4, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r4, r0
	subs r0, #0x20
	adds r3, r4, r0
_0808153C:
	subs r0, r1, #5
	cmp r0, #1
	bls _08081546
	cmp r1, #0xd
	bne _08081558
_08081546:
	ldrh r0, [r3]
	b _0808155A
	.align 2, 0
_0808154C: .4byte 0x00000964
_08081550: .4byte 0x03003584
_08081554: .4byte 0x0000095E
_08081558:
	ldrh r0, [r5]
_0808155A:
	strh r0, [r2]
	adds r5, #2
	adds r2, #2
	adds r3, #2
	adds r1, #1
	cmp r1, #0xf
	ble _0808153C
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r4, r1
	str r0, [r6]
	b _08081590
_08081572:
	ldr r1, _080815A4 @ =0x03003584
	ldr r3, _080815A8 @ =0x0000095E
	adds r0, r4, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_080812d4
_08081590:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r4, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_0808159C:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080815A4: .4byte 0x03003584
_080815A8: .4byte 0x0000095E

	thumb_func_start FUN_080815ac
FUN_080815ac: @ 0x080815AC
	push {r4, lr}
	ldr r1, _080815E8 @ =0x0000094A
	adds r3, r0, r1
	movs r2, #0
	movs r1, #0x27
	strh r1, [r3]
	ldr r4, _080815EC @ =0x0000094C
	adds r1, r0, r4
	strh r2, [r1]
	movs r1, #0x95
	lsls r1, r1, #4
	adds r2, r0, r1
	movs r1, #0xff
	strb r1, [r2]
	adds r2, r0, #0
	adds r2, #0xc2
	adds r1, #0x22
	strh r1, [r2]
	adds r2, #0xe
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r0, r4
	str r1, [r2]
	ldrh r1, [r3]
	bl FUN_080813d0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080815E8: .4byte 0x0000094A
_080815EC: .4byte 0x0000094C

	thumb_func_start FUN_080815f0
FUN_080815f0: @ 0x080815F0
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _08081614 @ =0x0000095C
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08081610
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08081618
_08081610:
	adds r0, r2, #0
	b _0808161E
	.align 2, 0
_08081614: .4byte 0x0000095C
_08081618:
	ldr r1, _08081624 @ =0x0000095A
	adds r0, r3, r1
	ldrh r0, [r0]
_0808161E:
	pop {r1}
	bx r1
	.align 2, 0
_08081624: .4byte 0x0000095A

	thumb_func_start FUN_08081628
FUN_08081628: @ 0x08081628
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _08081684 @ =0x0000094A
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r0, r4, #0
	bl FUN_080815f0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080813d0
	adds r1, r4, #0
	adds r1, #0xa8
	ldr r2, _08081688 @ =0x00000604
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r4, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xaa
	adds r2, #0xa
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	subs r2, #8
	adds r1, r4, r2
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xac
	adds r2, #0xa
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	movs r1, #0xc0
	lsls r1, r1, #3
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08081684: .4byte 0x0000094A
_08081688: .4byte 0x00000604

	thumb_func_start FUN_0808168c
FUN_0808168c: @ 0x0808168C
	push {lr}
	ldr r1, _0808169C @ =0x0000060C
	adds r0, r0, r1
	bl ParticleShadow_Remove
	pop {r0}
	bx r0
	.align 2, 0
_0808169C: .4byte 0x0000060C

	thumb_func_start FUN_080816a0
FUN_080816a0: @ 0x080816A0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _08081748 @ =0x000005FC
	adds r1, r4, r0
	adds r0, r4, #0
	adds r0, #0xa8
	ldr r2, [r0]
	ldr r3, [r0, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r2, _0808174C @ =0x00000604
	adds r0, r4, r2
	movs r5, #0
	movs r6, #0
	strh r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r6, [r0]
	adds r2, #4
	adds r0, r4, r2
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl FUN_080815ac
	ldr r1, _08081750 @ =0x0000097C
	adds r0, r4, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _08081754 @ =0x0000097D
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r5, [r0]
	adds r2, #1
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0x97
	lsls r1, r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	subs r2, #0x18
	adds r0, r4, r2
	strh r6, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r6, [r0]
	ldr r2, _08081758 @ =0x000003FF
	adds r4, r4, r2
	movs r0, #0xff
	strb r0, [r4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081748: .4byte 0x000005FC
_0808174C: .4byte 0x00000604
_08081750: .4byte 0x0000097C
_08081754: .4byte 0x0000097D
_08081758: .4byte 0x000003FF

	thumb_func_start FUN_0808175c
FUN_0808175c: @ 0x0808175C
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r5, r4, r0
	ldr r2, _080817DC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080817E0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xfe
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldrh r1, [r4, #0x24]
	ldr r2, _080817E4 @ =0x00004001
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r5, #0
	movs r1, #0x14
	movs r2, #2
	movs r3, #1
	bl FUN_08236514
	ldr r1, _080817E8 @ =FUN_080843ac
	adds r0, r5, #0
	adds r2, r4, #0
	bl FUN_0823651c
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080817DC: .4byte 0xFFFF0000
_080817E0: .4byte 0x0000FFFF
_080817E4: .4byte 0x00004001
_080817E8: .4byte FUN_080843ac

	thumb_func_start FUN_080817ec
FUN_080817ec: @ 0x080817EC
	movs r1, #1
	str r1, [r0, #0x1c]
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r0, r1
	ldr r1, _08081824 @ =FUN_08084330
	str r1, [r2]
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #0
	strb r2, [r1]
	ldr r3, _08081828 @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	adds r3, #1
	adds r1, r0, r3
	strh r2, [r1]
	ldr r2, _0808182C @ =0x03002B68
	adds r1, r0, #0
	adds r1, #0x28
	ldrb r1, [r1]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r0, [r0, #0x24]
	strh r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_08081824: .4byte FUN_08084330
_08081828: .4byte 0x0000037D
_0808182C: .4byte 0x03002B68

	thumb_func_start FUN_08081830
FUN_08081830: @ 0x08081830
	push {r4, r5, r6, r7, lr}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080818A0 @ =0x0000CB05
	ldr r1, _080818A4 @ =0x0000DE23
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _08081846
	b _08081AA4
_08081846:
	adds r1, r6, #0
	adds r1, #0x68
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r5, r6, #0
	adds r5, #0x88
	movs r3, #0x80
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_Add
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080818A8
	bl Script_GetValue
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	b _080818B0
	.align 2, 0
_080818A0: .4byte 0x0000CB05
_080818A4: .4byte 0x0000DE23
_080818A8:
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r6, r3
	strb r1, [r0]
_080818B0:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r2, [r0]
	cmp r2, #4
	bls _080818D8
	movs r0, #8
	subs r0, r0, r2
	ldr r2, _080818D0 @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _080818D4 @ =0x000002E7
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _080818E6
	.align 2, 0
_080818D0: .4byte 0x000002E6
_080818D4: .4byte 0x000002E7
_080818D8:
	ldr r1, _08081918 @ =0x000002E6
	adds r0, r6, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _0808191C @ =0x000002E7
	adds r0, r6, r2
	strb r1, [r0]
_080818E6:
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r6, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08081918 @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	str r1, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r3, #1
	bl FUN_082370cc
	ldr r3, _0808191C @ =0x000002E7
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08081920
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _0808192C
	.align 2, 0
_08081918: .4byte 0x000002E6
_0808191C: .4byte 0x000002E7
_08081920:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_0808192C:
	str r1, [r0]
	add r0, sp, #0x10
	bl FUN_08084734
	adds r2, r6, #0
	movs r4, #0x8f
	lsls r4, r4, #3
	adds r5, r6, r4
	movs r0, #8
	adds r0, r0, r6
	mov ip, r0
	adds r7, r6, #0
	adds r7, #0x18
_08081946:
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	str r0, [r5]
	str r1, [r5, #4]
	cmp r2, ip
	beq _08081974
	cmp r2, ip
	bgt _0808195C
	cmp r2, r6
	beq _0808196A
	b _0808198E
_0808195C:
	adds r0, r6, #0
	adds r0, #0x10
	cmp r2, r0
	beq _0808197C
	cmp r2, r7
	beq _08081986
	b _0808198E
_0808196A:
	movs r1, #0x2c
	movs r4, #0xa0
	rsbs r4, r4, #0
	movs r3, #5
	b _08081994
_08081974:
	movs r1, #0x2c
	movs r4, #0xfc
	movs r3, #1
	b _08081994
_0808197C:
	movs r1, #0xa0
	rsbs r1, r1, #0
	movs r4, #0x2c
	movs r3, #3
	b _08081994
_08081986:
	movs r1, #0xfc
	movs r4, #0x2c
	movs r3, #7
	b _08081994
_0808198E:
	movs r1, #0
	movs r4, #0
	movs r3, #0
_08081994:
	ldrh r0, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldr r0, _080819D4 @ =0x0000047C
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, r0, r4
	strh r0, [r1]
	ldr r1, _080819D8 @ =0x0000047E
	adds r0, r2, r1
	strh r3, [r0]
	adds r2, #8
	adds r5, #8
	cmp r2, r7
	ble _08081946
	ldr r2, _080819DC @ =0x000004A6
	adds r0, r6, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _080819E0 @ =0x00000466
	adds r0, r6, r3
	strb r1, [r0]
	movs r0, #0x72
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080819E8
	bl Script_GetValue
	ldr r4, _080819E4 @ =0x00000467
	adds r1, r6, r4
	b _080819EE
	.align 2, 0
_080819D4: .4byte 0x0000047C
_080819D8: .4byte 0x0000047E
_080819DC: .4byte 0x000004A6
_080819E0: .4byte 0x00000466
_080819E4: .4byte 0x00000467
_080819E8:
	ldr r5, _08081A10 @ =0x00000467
	adds r1, r6, r5
	movs r0, #0x32
_080819EE:
	strb r0, [r1]
	ldr r1, _08081A14 @ =0x00000469
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x62
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081A18
	bl Script_GetValue
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r1, r6, r2
	b _08081A20
	.align 2, 0
_08081A10: .4byte 0x00000467
_08081A14: .4byte 0x00000469
_08081A18:
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r0, #3
_08081A20:
	strb r0, [r1]
	ldr r4, _08081A50 @ =0x0000046D
	adds r0, r6, r4
	movs r1, #0
	strb r1, [r0]
	ldr r5, _08081A54 @ =0x00000474
	adds r0, r6, r5
	strh r1, [r0]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081A60
	bl Script_GetValue
	ldr r2, _08081A58 @ =0x0000046C
	adds r1, r6, r2
	strb r0, [r1]
	bl Script_GetValue
	ldr r3, _08081A5C @ =0x00000472
	adds r1, r6, r3
	b _08081A6E
	.align 2, 0
_08081A50: .4byte 0x0000046D
_08081A54: .4byte 0x00000474
_08081A58: .4byte 0x0000046C
_08081A5C: .4byte 0x00000472
_08081A60:
	ldr r4, _08081A8C @ =0x0000046C
	adds r1, r6, r4
	movs r0, #4
	strb r0, [r1]
	ldr r5, _08081A90 @ =0x00000472
	adds r1, r6, r5
	movs r0, #0xb4
_08081A6E:
	strh r0, [r1]
	ldr r1, _08081A94 @ =0x0000046B
	adds r0, r6, r1
	movs r1, #0
	strb r1, [r0]
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081A9C
	bl Script_GetValue
	ldr r2, _08081A98 @ =0x0000046A
	adds r1, r6, r2
	b _08081AA2
	.align 2, 0
_08081A8C: .4byte 0x0000046C
_08081A90: .4byte 0x00000472
_08081A94: .4byte 0x0000046B
_08081A98: .4byte 0x0000046A
_08081A9C:
	ldr r3, _08081AAC @ =0x0000046A
	adds r1, r6, r3
	movs r0, #5
_08081AA2:
	strb r0, [r1]
_08081AA4:
	add sp, #0x18
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081AAC: .4byte 0x0000046A

	thumb_func_start FUN_08081ab0
FUN_08081ab0: @ 0x08081AB0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r7, r1, #0
	movs r0, #1
	str r0, [r6, #0x18]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081B04
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _08081AFC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _08081B00 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _08081B0E
	.align 2, 0
_08081AFC: .4byte 0xFFFF0000
_08081B00: .4byte 0x0000FFFF
_08081B04:
	ldr r1, _08081B3C @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_08081B0E:
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08081B36
	cmp r1, #0
	blt _08081B36
	ldr r0, _08081B40 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08081B36
	ldr r0, _08081B44 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08081B48
_08081B36:
	movs r4, #0
	b _08081B56
	.align 2, 0
_08081B3C: .4byte 0xFFFF0000
_08081B40: .4byte 0x030046A8
_08081B44: .4byte 0x030046AC
_08081B48:
	ldr r0, _08081B68 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08081B56:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08081B6C
	adds r0, #4
	b _08081B78
	.align 2, 0
_08081B68: .4byte 0x030046A4
_08081B6C:
	ldr r0, _08081B8C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08081B78:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08081B90
	cmp r2, #2
	beq _08081B94
	b _08081B98
	.align 2, 0
_08081B8C: .4byte 0x030046A4
_08081B90:
	ldrb r0, [r5, #4]
	b _08081B96
_08081B94:
	ldrb r0, [r5]
_08081B96:
	subs r1, r1, r0
_08081B98:
	add r0, sp, #8
	strh r1, [r0, #2]
	adds r5, r6, #0
	adds r5, #0x24
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	ldrb r0, [r6, #0x18]
	str r0, [sp]
	str r6, [sp, #4]
	adds r0, r5, #0
	add r2, sp, #8
	movs r3, #0
	bl FUN_0823b400
	adds r0, r6, #0
	bl FUN_08081830
	adds r1, r6, #0
	adds r1, #0x88
	adds r0, r5, #0
	bl FUN_0823b474
	movs r0, #0xde
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r0, r4, #0
	add r1, sp, #8
	bl FUN_0823280c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r6, r1
	add r1, sp, #8
	bl FUN_082362fc
	ldr r0, _08081C00 @ =0x00000464
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_08002a48
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08081C00: .4byte 0x00000464

	thumb_func_start FUN_08081c04
FUN_08081c04: @ 0x08081C04
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x1c
	adds r7, r0, #0
	ldr r0, _08081C30 @ =0x000009C8
	adds r6, r7, r0
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08081C38
	bl Script_GetValue
	ldr r2, _08081C34 @ =0x00000A7A
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	adds r5, r0, #0
	b _08081C42
	.align 2, 0
_08081C30: .4byte 0x000009C8
_08081C34: .4byte 0x00000A7A
_08081C38:
	ldr r0, _08081CFC @ =0x00000A7A
	adds r1, r7, r0
	movs r0, #0xa
	strh r0, [r1]
	movs r5, #0x1e
_08081C42:
	adds r1, r6, #0
	adds r1, #0xb4
	movs r0, #0x20
	strh r0, [r1]
	adds r1, #2
	movs r0, #0x14
	strh r0, [r1]
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, _08081D00 @ =0x00002110
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r6, #0
	adds r1, r4, #0
	movs r2, #0x43
	bl FUN_0822a470
	movs r0, #4
	strh r0, [r6, #0x10]
	adds r0, r4, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	movs r1, #2
	mov r8, r1
	mov r2, r8
	strb r2, [r6, #7]
	movs r0, #0x7f
	strb r0, [r6, #9]
	strb r0, [r6, #8]
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r7, r0
	ldr r2, _08081D04 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xaa
	orrs r0, r3
	ldr r1, _08081D08 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _08081D0C @ =0xFFEC0000
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08081D10 @ =0x00002101
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	mov r1, r8
	str r1, [sp]
	ldr r2, _08081D14 @ =0x00000A7E
	adds r0, r7, r2
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x32
	movs r3, #0x10
	bl FUN_082364f8
	adds r0, r4, #0
	movs r1, #0
	adds r2, r7, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08081CFC: .4byte 0x00000A7A
_08081D00: .4byte 0x00002110
_08081D04: .4byte 0xFFFF0000
_08081D08: .4byte 0x0000FFFF
_08081D0C: .4byte 0xFFEC0000
_08081D10: .4byte 0x00002101
_08081D14: .4byte 0x00000A7E

	thumb_func_start FUN_08081d18
FUN_08081d18: @ 0x08081D18
	push {r4, r5, r6, lr}
	sub sp, #0x20
	adds r2, r0, #0
	adds r0, #0x90
	ldr r5, [r0]
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	bne _08081D94
	movs r0, #0xf7
	lsls r0, r0, #2
	adds r6, r2, r0
	adds r0, r1, #2
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x63
	bls _08081D94
	ldr r0, [r2, #0x2c]
	ldr r1, [r2, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x50
	lsls r1, r1, #0x10
	ldr r3, _08081D9C @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _08081DA0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ands r0, r3
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	str r5, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldrh r0, [r6]
	subs r0, #0x64
	strh r0, [r6]
_08081D94:
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08081D9C: .4byte 0x0000FFFF
_08081DA0: .4byte 0xFFFF0000

	thumb_func_start FUN_08081da4
FUN_08081da4: @ 0x08081DA4
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _08081DCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08081DD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08081DD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0x64
	bl Mod
	cmp r0, r4
	blt _08081DD8
	movs r0, #0
	b _08081DDA
	.align 2, 0
_08081DCC: .4byte 0x030046B8
_08081DD0: .4byte 0x000003FF
_08081DD4: .4byte 0x0203B400
_08081DD8:
	movs r0, #1
_08081DDA:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08081de0
FUN_08081de0: @ 0x08081DE0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x48
	mov sl, r0
	str r1, [sp, #0x40]
	str r2, [sp, #0x44]
	movs r0, #0
	mov sb, r0
	movs r6, #0
	movs r1, #0xff
	mov r8, r1
	mov r5, sp
_08081DFE:
	ldr r0, _08081E28 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5]
	str r1, [r5, #4]
	lsls r2, r6, #5
	ldr r1, _08081E2C @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #9
	cmp r0, #0
	blt _08081E30
	asrs r1, r0, #0xc
	b _08081E36
	.align 2, 0
_08081E28: .4byte 0x03002BE0
_08081E2C: .4byte 0x085B0A08
_08081E30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08081E36:
	ldrh r0, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	mov r3, r8
	ands r2, r3
	lsls r0, r2, #1
	ldr r1, _08081E54 @ =0x085B0A08
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #9
	cmp r0, #0
	blt _08081E58
	asrs r0, r0, #0xc
	b _08081E5E
	.align 2, 0
_08081E54: .4byte 0x085B0A08
_08081E58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08081E5E:
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	strh r1, [r5, #4]
	adds r7, r5, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08081E88
	cmp r1, #0
	blt _08081E88
	ldr r0, _08081E8C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08081E88
	ldr r0, _08081E90 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08081E94
_08081E88:
	movs r4, #0
	b _08081EA2
	.align 2, 0
_08081E8C: .4byte 0x030046A8
_08081E90: .4byte 0x030046AC
_08081E94:
	ldr r0, _08081EB4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08081EA2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08081EB8
	adds r0, #4
	b _08081EC4
	.align 2, 0
_08081EB4: .4byte 0x030046A4
_08081EB8:
	ldr r0, _08081ED8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08081EC4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08081EDC
	cmp r3, #2
	beq _08081EE0
	b _08081EE8
	.align 2, 0
_08081ED8: .4byte 0x030046A4
_08081EDC:
	ldrh r1, [r7, #4]
	b _08081EE2
_08081EE0:
	ldrh r1, [r7]
_08081EE2:
	mov r0, r8
	ands r0, r1
	subs r2, r2, r0
_08081EE8:
	mov r3, sl
	movs r1, #0x2e
	ldrsh r0, [r3, r1]
	cmp r2, r0
	bne _08081EFA
	movs r0, #1
	strh r0, [r5, #6]
	add sb, r0
	b _08081EFE
_08081EFA:
	movs r0, #0
	strh r0, [r5, #6]
_08081EFE:
	adds r5, #8
	adds r6, #1
	cmp r6, #7
	bgt _08081F08
	b _08081DFE
_08081F08:
	mov r2, sb
	cmp r2, #0
	bne _08081F28
	b _08081F60
_08081F10:
	ldr r0, [r1]
	ldr r1, [r1, #4]
	ldr r3, [sp, #0x40]
	str r0, [r3]
	str r1, [r3, #4]
	adds r0, r6, #7
	movs r1, #7
	ands r0, r1
	ldr r1, [sp, #0x44]
	str r0, [r1]
	movs r0, #1
	b _08081F62
_08081F28:
	ldr r2, _08081F74 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08081F78 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08081F7C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	asrs r0, r0, #3
	mov r1, sb
	bl Mod
	adds r2, r0, #0
	movs r6, #0
	mov r1, sp
_08081F4A:
	movs r3, #6
	ldrsh r0, [r1, r3]
	cmp r0, #0
	beq _08081F58
	cmp r2, #0
	beq _08081F10
	subs r2, #1
_08081F58:
	adds r1, #8
	adds r6, #1
	cmp r6, #7
	ble _08081F4A
_08081F60:
	movs r0, #0
_08081F62:
	add sp, #0x48
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08081F74: .4byte 0x030046B8
_08081F78: .4byte 0x000003FF
_08081F7C: .4byte 0x0203B400

	thumb_func_start FUN_08081f80
FUN_08081f80: @ 0x08081F80
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08081FA0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
	adds r0, r4, #0
	bl FUN_08080c64
_08081FA0:
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08081fb4
FUN_08081fb4: @ 0x08081FB4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08081FCE
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_08080e0c
_08081FCE:
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_08080ec8
	movs r2, #0x82
	lsls r2, r2, #2
	adds r3, r4, r2
	movs r1, #0
	ldrsh r0, [r3, r1]
	movs r2, #0x2c
	ldrsh r6, [r4, r2]
	subs r2, r0, r6
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r1, #0x30
	ldrsh r5, [r4, r1]
	subs r1, r0, r5
	movs r7, #0xc
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	cmp r0, #0x90
	bgt _08082074
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	ldr r1, _08082038 @ =0x00000471
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _08082040
	movs r0, #8
	subs r0, r0, r1
	subs r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _0808203C @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _0808204C
	.align 2, 0
_08082038: .4byte 0x00000471
_0808203C: .4byte 0x000002E7
_08082040:
	ldr r2, _0808206C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08082070 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
_0808204C:
	strb r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r1, #0x8e
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08080e0c
	b _08082118
	.align 2, 0
_0808206C: .4byte 0x000002E6
_08082070: .4byte 0x000002E7
_08082074:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r2, r0, r6
	movs r1, #0x87
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r0, r5
	adds r0, r2, #0
	bl ArcTan2_8
	adds r5, r0, #0
	ldr r2, _080820B0 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080820B4
	asrs r0, r0, #0xc
	b _080820BA
	.align 2, 0
_080820B0: .4byte 0x085B0A08
_080820B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080820BA:
	strh r0, [r4, #0x34]
	ldr r0, _080820D4 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080820D8
	asrs r0, r0, #0xc
	b _080820DE
	.align 2, 0
_080820D4: .4byte 0x085B0A08
_080820D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080820DE:
	strh r0, [r4, #0x38]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08235fd8
	cmp r0, #0
	beq _0808210E
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
_0808210E:
	ldr r1, _08082120 @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
_08082118:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08082120: .4byte 0x000001A3

	thumb_func_start FUN_08082124
FUN_08082124: @ 0x08082124
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0808214C
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _08082148 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _0808214C
	movs r0, #1
	b _0808214E
	.align 2, 0
_08082148: .4byte 0x0000036A
_0808214C:
	movs r0, #0
_0808214E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08082154
FUN_08082154: @ 0x08082154
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _0808216E
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_08080e0c
_0808216E:
	ldr r2, _08082184 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _0808217A
	b _08082456
_0808217A:
	lsls r0, r0, #2
	ldr r1, _08082188 @ =_0808218C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08082184: .4byte 0x0000037D
_08082188: .4byte _0808218C
_0808218C: @ jump table
	.4byte _080821A0 @ case 0
	.4byte _080821B8 @ case 1
	.4byte _080822D0 @ case 2
	.4byte _080823AC @ case 3
	.4byte _0808241C @ case 4
_080821A0:
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_08080e0c
	b _08082456
_080821B8:
	ldr r1, _08082214 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _0808226E
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08082228
	movs r0, #4
	strb r0, [r1]
	ldr r0, _08082218 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0808221C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _08082220 @ =0x00000932
	adds r1, r4, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08082224 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08082262
	.align 2, 0
_08082214: .4byte 0x0000037E
_08082218: .4byte 0x000002E6
_0808221C: .4byte 0x000002E7
_08082220: .4byte 0x00000932
_08082224: .4byte 0x00000934
_08082228:
	strb r2, [r1]
	ldr r1, _080822BC @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _080822C0 @ =0x00000932
	adds r1, r4, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080822C4 @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #0x1e
_08082262:
	strh r0, [r1]
	ldr r2, _080822C8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_0808226E:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _0808228A
	b _08082456
_0808228A:
	movs r0, #0xcb
	bl PlaySound_082406e0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080822A4
	b _080823DC
_080822A4:
	adds r0, r4, #0
	bl FUN_08082124
	adds r1, r0, #0
	cmp r1, #0
	beq _080822B2
	b _080823F2
_080822B2:
	ldr r2, _080822CC @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _0808239A
	.align 2, 0
_080822BC: .4byte 0x000002E6
_080822C0: .4byte 0x00000932
_080822C4: .4byte 0x00000934
_080822C8: .4byte 0x0000037E
_080822CC: .4byte 0x00000404
_080822D0:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _0808232C @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080822F6
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080822F6
	movs r0, #0x94
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080822F6:
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _08082330 @ =0x0000095E
	adds r1, r4, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _08082334 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _08082338
	movs r2, #0x96
	lsls r2, r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	b _08082344
	.align 2, 0
_0808232C: .4byte 0x00000404
_08082330: .4byte 0x0000095E
_08082334: .4byte 0x0000037E
_08082338:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_08082344:
	ldr r0, _0808237C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _0808235C
	movs r0, #0
	strh r0, [r1]
_0808235C:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08082384
	movs r0, #0xd8
	bl sound_08240740
	ldr r2, _08082380 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080823DC
	.align 2, 0
_0808237C: .4byte 0x0000037E
_08082380: .4byte 0x00000409
_08082384:
	adds r0, r4, #0
	bl FUN_08082124
	cmp r0, #0
	bne _08082456
	movs r0, #0xd8
	bl sound_08240740
	ldr r1, _080823A8 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_0808239A:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_08080e0c
	b _08082456
	.align 2, 0
_080823A8: .4byte 0x00000409
_080823AC:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080823E8
_080823DC:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_08080e0c
	b _08082456
_080823E8:
	adds r0, r4, #0
	bl FUN_08082124
	cmp r0, #0
	beq _08082456
_080823F2:
	movs r0, #0xd8
	bl PlaySound_082406e0
	ldr r2, _08082414 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08082418 @ =0x00000404
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_08080e0c
	b _08082456
	.align 2, 0
_08082414: .4byte 0x00000409
_08082418: .4byte 0x00000404
_0808241C:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082456
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _0808245C @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08082460 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082456:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808245C: .4byte 0x000002E6
_08082460: .4byte 0x000002E7

	thumb_func_start FUN_08082464
FUN_08082464: @ 0x08082464
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0808247C @ =0x000003FE
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082480
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_08080ec8
	b _08082488
	.align 2, 0
_0808247C: .4byte 0x000003FE
_08082480:
	adds r0, r4, #0
	movs r1, #0x3d
	bl FUN_08080ec8
_08082488:
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08082498
FUN_08082498: @ 0x08082498
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _08082520
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_08080e0c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080824E4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r5, _080824DC @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r6, _080824E0 @ =0x000002E7
	adds r1, r4, r6
	movs r0, #1
	strb r0, [r1]
	b _080824F4
	.align 2, 0
_080824DC: .4byte 0x000002E6
_080824E0: .4byte 0x000002E7
_080824E4:
	lsrs r1, r1, #0x19
	ldr r2, _08082510 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _08082514 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080824F4:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08082518 @ =0x00000366
	bl sound_08240740
	ldr r0, _0808251C @ =0x0000036A
	bl PlaySound_082406e0
	b _08082666
	.align 2, 0
_08082510: .4byte 0x000002E6
_08082514: .4byte 0x000002E7
_08082518: .4byte 0x00000366
_0808251C: .4byte 0x0000036A
_08082520:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r5, r4, r6
	ldrh r0, [r5]
	cmp r0, #0
	beq _0808260C
	ldr r1, _0808255C @ =0x00000395
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082598
	movs r2, #0x2c
	ldrsh r1, [r4, r2]
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r2, [r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	subs r3, r1, r0
	movs r6, #0x30
	ldrsh r1, [r4, r6]
	movs r5, #4
	ldrsh r0, [r2, r5]
	subs r1, r1, r0
	rsbs r0, r3, #0
	cmp r0, #0
	blt _08082560
	asrs r0, r0, #3
	b _08082564
	.align 2, 0
_0808255C: .4byte 0x00000395
_08082560:
	asrs r0, r3, #3
	rsbs r0, r0, #0
_08082564:
	strh r0, [r4, #0x34]
	rsbs r0, r1, #0
	cmp r0, #0
	blt _08082570
	asrs r0, r0, #3
	b _08082574
_08082570:
	asrs r0, r1, #3
	rsbs r0, r0, #0
_08082574:
	strh r0, [r4, #0x38]
	movs r6, #0xf5
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrh r1, [r0]
	cmp r1, #0x55
	bls _080825FA
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080825FA
	ldr r0, _08082594 @ =0x00000191
	bl PlaySound_082406e0
	b _080825FA
	.align 2, 0
_08082594: .4byte 0x00000191
_08082598:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080825C8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r5]
	muls r0, r1, r0
	cmp r0, #0
	blt _080825CC
	asrs r0, r0, #0xc
	b _080825D2
	.align 2, 0
_080825C8: .4byte 0x085B0A08
_080825CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080825D2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080825F0
	asrs r0, r0, #0xc
	b _080825F6
_080825F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080825F6:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
_080825FA:
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r2, r4, r5
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _08082666
_0808260C:
	ldr r6, _0808262C @ =0x000004C5
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _08082634
	ldr r1, _08082630 @ =0x000004C7
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08082634
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08080e0c
	b _08082666
	.align 2, 0
_0808262C: .4byte 0x000004C5
_08082630: .4byte 0x000004C7
_08082634:
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082666
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	ldr r3, _0808266C @ =0x00000395
	adds r0, r4, r3
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082666:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808266C: .4byte 0x00000395

	thumb_func_start FUN_08082670
FUN_08082670: @ 0x08082670
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _080826D8
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_08080e0c
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080826BC
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r5, _080826B4 @ =0x000002E6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r0, _080826B8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080826CC
	.align 2, 0
_080826B4: .4byte 0x000002E6
_080826B8: .4byte 0x000002E7
_080826BC:
	lsrs r1, r1, #0x19
	ldr r2, _080826F0 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080826F4 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080826CC:
	ldr r0, _080826F8 @ =0x00000366
	bl sound_08240740
	ldr r0, _080826FC @ =0x0000036B
	bl PlaySound_082406e0
_080826D8:
	ldr r5, _08082700 @ =0x0000037D
	adds r0, r4, r5
	ldrb r0, [r0]
	cmp r0, #4
	bls _080826E4
	b _0808295A
_080826E4:
	lsls r0, r0, #2
	ldr r1, _08082704 @ =_08082708
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080826F0: .4byte 0x000002E6
_080826F4: .4byte 0x000002E7
_080826F8: .4byte 0x00000366
_080826FC: .4byte 0x0000036B
_08082700: .4byte 0x0000037D
_08082704: .4byte _08082708
_08082708: @ jump table
	.4byte _0808271C @ case 0
	.4byte _0808274C @ case 1
	.4byte _0808285C @ case 2
	.4byte _080828E8 @ case 3
	.4byte _0808290C @ case 4
_0808271C:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08082748 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _0808273C
	b _0808295A
_0808273C:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082748: .4byte 0x0000037E
_0808274C:
	ldr r1, _080827A0 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08082760
	ldr r2, _080827A4 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_08082760:
	movs r1, #0xe2
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080827A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080827AC
	asrs r0, r0, #0xc
	b _080827B2
	.align 2, 0
_080827A0: .4byte 0x0000037E
_080827A4: .4byte 0x000003F6
_080827A8: .4byte 0x085B0A08
_080827AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080827B2:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _080827D4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080827D8
	asrs r0, r0, #0xc
	b _080827DE
	.align 2, 0
_080827D4: .4byte 0x085B0A08
_080827D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080827DE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _0808280C @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _08082818
	ldr r2, _08082810 @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _08082814
	subs r0, r2, r0
	b _08082816
	.align 2, 0
_0808280C: .4byte 0x0000037E
_08082810: .4byte 0x000003F6
_08082814:
	movs r0, #0
_08082816:
	strh r0, [r1]
_08082818:
	ldr r3, _08082850 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _08082830
	b _0808295A
_08082830:
	ldr r0, _08082854 @ =0x000003F6
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0808283C
	b _0808295A
_0808283C:
	strh r0, [r1]
	ldr r0, _08082858 @ =0x0000033A
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082850: .4byte 0x0000037E
_08082854: .4byte 0x000003F6
_08082858: .4byte 0x0000033A
_0808285C:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08082890 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08082894
	asrs r0, r0, #0xc
	b _0808289A
	.align 2, 0
_08082890: .4byte 0x085B0A08
_08082894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808289A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080828B8
	asrs r0, r0, #0xc
	b _080828BE
_080828B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080828BE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xe3
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _0808295A
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r1, r4, r5
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_08080e0c
	b _0808295A
_080828E8:
	ldr r0, _08082908 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _0808295A
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_08080e0c
	b _0808295A
	.align 2, 0
_08082908: .4byte 0x0000037E
_0808290C:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _0808295A
	ldr r1, _08082960 @ =0x000003D2
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	ldr r3, _08082964 @ =0x0000046D
	adds r2, r4, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	subs r3, #1
	adds r1, r4, r3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08082950
	strb r5, [r2]
	ldr r5, _08082968 @ =0x00000472
	adds r0, r4, r5
	ldrh r1, [r0]
	ldr r2, _0808296C @ =0x00000474
	adds r0, r4, r2
	strh r1, [r0]
_08082950:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_0808295A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08082960: .4byte 0x000003D2
_08082964: .4byte 0x0000046D
_08082968: .4byte 0x00000472
_0808296C: .4byte 0x00000474

	thumb_func_start FUN_08082970
FUN_08082970: @ 0x08082970
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x12
	beq _08082998
	ldr r0, _080829AC @ =0x00000366
	bl sound_08240740
	ldr r0, _080829B0 @ =0x0000036F
	bl PlaySound_082406e0
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_08080e0c
_08082998:
	ldr r3, _080829B4 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #1
	beq _08082A20
	cmp r0, #1
	bgt _080829B8
	cmp r0, #0
	beq _080829BE
	b _08082A88
	.align 2, 0
_080829AC: .4byte 0x00000366
_080829B0: .4byte 0x0000036F
_080829B4: .4byte 0x0000037D
_080829B8:
	cmp r0, #2
	beq _08082A70
	b _08082A88
_080829BE:
	movs r1, #0xf9
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082A88
	movs r6, #0x99
	lsls r6, r6, #4
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	ldr r0, _08082A14 @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldr r3, _08082A18 @ =0x00000474
	adds r2, r5, r3
	str r2, [sp]
	ldr r6, _08082A1C @ =0x00000472
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #1
	movs r3, #0
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #1
	bl FUN_08080e0c
	b _08082A88
	.align 2, 0
_08082A14: .4byte 0x0000098C
_08082A18: .4byte 0x00000474
_08082A1C: .4byte 0x00000472
_08082A20:
	ldr r6, _08082A68 @ =0x00000474
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	bne _08082A88
	ldr r0, _08082A6C @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	lsls r3, r3, #1
	str r3, [sp, #8]
	adds r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x12
	movs r2, #2
	bl FUN_08080e0c
	b _08082A88
	.align 2, 0
_08082A68: .4byte 0x00000474
_08082A6C: .4byte 0x0000098C
_08082A70:
	ldr r1, _08082A90 @ =0x000001F7
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08082A88
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08082A88:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082A90: .4byte 0x000001F7

	thumb_func_start FUN_08082a94
FUN_08082a94: @ 0x08082A94
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x13
	beq _08082AF4
	ldr r0, _08082B50 @ =0x00000366
	bl sound_08240740
	ldr r0, _08082B54 @ =0x00000369
	bl PlaySound_082406e0
	movs r3, #0x99
	lsls r3, r3, #4
	adds r1, r5, r3
	movs r0, #0
	strb r0, [r1]
	ldr r6, _08082B58 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldr r3, _08082B5C @ =0x00000474
	adds r2, r5, r3
	str r2, [sp]
	ldr r6, _08082B60 @ =0x00000472
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	str r2, [sp, #4]
	movs r2, #0x96
	lsls r2, r2, #1
	str r2, [sp, #8]
	adds r2, #0x50
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_08080e0c
_08082AF4:
	ldr r6, _08082B64 @ =0x0000037E
	adds r0, r5, r6
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08082B86
	ldr r0, _08082B68 @ =0x03002BE0
	ldr r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r2, r1]
	movs r3, #0x2c
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	movs r6, #0x30
	ldrsh r1, [r2, r6]
	movs r3, #0x30
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	movs r6, #0xba
	lsls r6, r6, #2
	adds r3, r5, r6
	ldrb r2, [r3]
	cmp r1, r2
	beq _08082B74
	adds r0, r2, #0
	subs r0, #8
	subs r0, r1, r0
	movs r1, #7
	ands r0, r1
	cmp r0, #4
	ble _08082B6C
	adds r0, r2, #7
	b _08082B70
	.align 2, 0
_08082B50: .4byte 0x00000366
_08082B54: .4byte 0x00000369
_08082B58: .4byte 0x0000098C
_08082B5C: .4byte 0x00000474
_08082B60: .4byte 0x00000472
_08082B64: .4byte 0x0000037E
_08082B68: .4byte 0x03002BE0
_08082B6C:
	adds r0, r2, #1
	movs r1, #7
_08082B70:
	ands r0, r1
	strb r0, [r3]
_08082B74:
	adds r0, r5, #0
	bl FUN_08080c64
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
_08082B86:
	ldr r0, _08082BD4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r3, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _08082BCC
	ldr r1, _08082BD8 @ =0x0000098C
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	lsls r3, r3, #1
	str r3, [sp, #8]
	adds r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
	bl FUN_080da9c4
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_08082BCC:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082BD4: .4byte 0x0000037E
_08082BD8: .4byte 0x0000098C

	thumb_func_start FUN_08082bdc
FUN_08082bdc: @ 0x08082BDC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _08082BF6
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_08082BF6:
	adds r0, r4, #0
	movs r1, #0x1c
	bl FUN_08080ec8
	movs r2, #0x82
	lsls r2, r2, #2
	adds r3, r4, r2
	movs r5, #0
	ldrsh r1, [r3, r5]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _08082C14
	rsbs r0, r0, #0
_08082C14:
	adds r6, r0, #0
	movs r5, #0x83
	lsls r5, r5, #2
	adds r2, r4, r5
	movs r0, #0
	ldrsh r1, [r2, r0]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r1, r1, r0
	cmp r1, #0
	bge _08082C2C
	rsbs r1, r1, #0
_08082C2C:
	adds r5, r1, #0
	cmp r6, #0x1f
	bgt _08082C84
	cmp r5, #0x1f
	bgt _08082C84
	ldr r0, _08082C78 @ =0x000003F2
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldrh r0, [r3]
	strh r0, [r4, #0x2c]
	ldrh r0, [r2]
	strh r0, [r4, #0x30]
	ldr r1, _08082C7C @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08080cac
	ldr r1, _08082C80 @ =0x00000471
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
	movs r5, #0x8e
	lsls r5, r5, #3
	adds r0, r4, r5
	ldrb r1, [r0]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08080e0c
	b _08082DA0
	.align 2, 0
_08082C78: .4byte 0x000003F2
_08082C7C: .4byte 0x000001A3
_08082C80: .4byte 0x00000471
_08082C84:
	ldr r0, _08082CAC @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _08082CB0 @ =0x00000127
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x18
	strh r0, [r1]
	cmp r6, #0xbf
	bgt _08082C9E
	cmp r5, #0xbf
	ble _08082CB8
_08082C9E:
	ldr r5, _08082CB4 @ =0x000003F2
	adds r1, r4, r5
	ldrb r0, [r1]
	cmp r0, #4
	bhi _08082CC6
	adds r0, #1
	b _08082CC4
	.align 2, 0
_08082CAC: .4byte 0x0000095E
_08082CB0: .4byte 0x00000127
_08082CB4: .4byte 0x000003F2
_08082CB8:
	ldr r0, _08082CDC @ =0x000003F2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08082CC6
	subs r0, #1
_08082CC4:
	strb r0, [r1]
_08082CC6:
	ldr r1, _08082CDC @ =0x000003F2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _08082CE0
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08080ec8
	b _08082CEC
	.align 2, 0
_08082CDC: .4byte 0x000003F2
_08082CE0:
	cmp r0, #0
	beq _08082CEC
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08080ec8
_08082CEC:
	movs r2, #0x86
	lsls r2, r2, #2
	adds r0, r4, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	subs r6, r1, r0
	movs r5, #0x87
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0x30
	ldrsh r0, [r4, r5]
	subs r5, r1, r0
	adds r0, r6, #0
	adds r1, r5, #0
	bl ArcTan2_8
	adds r3, r0, #0
	ldr r2, _08082D30 @ =0x085B0A08
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08082D34
	asrs r0, r0, #0xc
	b _08082D3A
	.align 2, 0
_08082D30: .4byte 0x085B0A08
_08082D34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08082D3A:
	strh r0, [r4, #0x34]
	ldr r0, _08082D54 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _08082D58
	asrs r0, r0, #0xc
	b _08082D5E
	.align 2, 0
_08082D54: .4byte 0x085B0A08
_08082D58:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08082D5E:
	strh r0, [r4, #0x38]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08235fd8
	cmp r0, #0
	beq _08082D96
	adds r0, r6, #0
	adds r1, r5, #0
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	bl FUN_08080c64
_08082D96:
	ldr r1, _08082DA8 @ =0x000001A3
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_08080cac
_08082DA0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08082DA8: .4byte 0x000001A3

	thumb_func_start FUN_08082dac
FUN_08082dac: @ 0x08082DAC
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _08082DD0
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	bl FUN_08080e0c
	ldr r2, _08082DE8 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_08082DD0:
	ldr r3, _08082DEC @ =0x0000037D
	adds r0, r4, r3
	ldrb r2, [r0]
	cmp r2, #1
	bne _08082DDC
	b _08082F30
_08082DDC:
	cmp r2, #1
	bgt _08082DF0
	cmp r2, #0
	beq _08082DFE
	b _08083012
	.align 2, 0
_08082DE8: .4byte 0x00000951
_08082DEC: .4byte 0x0000037D
_08082DF0:
	cmp r2, #2
	bne _08082DF6
	b _08082F84
_08082DF6:
	cmp r2, #3
	bne _08082DFC
	b _08082FE8
_08082DFC:
	b _08083012
_08082DFE:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08082E60
	movs r1, #4
	strb r1, [r3]
	ldr r3, _08082E50 @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08082E54 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r0, _08082E58 @ =0x00000932
	adds r1, r4, r0
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _08082E5C @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08082E9A
	.align 2, 0
_08082E50: .4byte 0x000002E6
_08082E54: .4byte 0x000002E7
_08082E58: .4byte 0x00000932
_08082E5C: .4byte 0x00000934
_08082E60:
	strb r2, [r3]
	ldr r1, _08082EBC @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _08082EC0 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _08082EC4 @ =0x00000932
	adds r1, r4, r2
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08082EC8 @ =0x00000934
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x14
_08082E9A:
	strh r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08082ECC
	ldr r2, _08082EBC @ =0x000002E6
	adds r1, r4, r2
	movs r0, #1
	b _08082ED2
	.align 2, 0
_08082EBC: .4byte 0x000002E6
_08082EC0: .4byte 0x000002E7
_08082EC4: .4byte 0x00000932
_08082EC8: .4byte 0x00000934
_08082ECC:
	ldr r3, _08082F1C @ =0x000002E6
	adds r1, r4, r3
	movs r0, #0
_08082ED2:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	movs r2, #1
	bl FUN_08080e0c
	ldr r0, _08082F20 @ =0x0000095E
	adds r1, r4, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
	ldr r0, _08082F24 @ =0x0000036E
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x2c
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r3, _08082F28 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl Entity080abd14_Create
	ldr r0, _08082F2C @ =0x00000477
	adds r1, r4, r0
	movs r0, #0x3c
	strb r0, [r1]
	b _08083012
	.align 2, 0
_08082F1C: .4byte 0x000002E6
_08082F20: .4byte 0x0000095E
_08082F24: .4byte 0x0000036E
_08082F28: .4byte 0x000003BA
_08082F2C: .4byte 0x00000477
_08082F30:
	ldr r2, _08082F80 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08082F52
	movs r0, #0x20
	strh r0, [r1]
_08082F52:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08083012
	movs r0, #0xcb
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #9
	movs r2, #2
	bl FUN_08080e0c
	b _08083012
	.align 2, 0
_08082F80: .4byte 0x0000095E
_08082F84:
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _08082FDC @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _08082FE0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08082FB6
	movs r0, #0x20
	strh r0, [r1]
_08082FB6:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, _08082FE4 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x17
	bls _08083012
	adds r0, r4, #0
	movs r1, #9
	movs r2, #3
	bl FUN_08080e0c
	b _08083012
	.align 2, 0
_08082FDC: .4byte 0x0000095E
_08082FE0: .4byte 0x0000FFFF
_08082FE4: .4byte 0x0000037E
_08082FE8:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08083012
	adds r0, r4, #0
	bl FUN_08080c64
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08083012:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808301c
FUN_0808301c: @ 0x0808301C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #8
	beq _08083038
	adds r0, r5, #0
	movs r1, #8
	movs r2, #0
	bl FUN_08080e0c
_08083038:
	ldr r2, _08083050 @ =0x00000951
	adds r0, r5, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _08083054 @ =0x0000037D
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _08083058
	cmp r0, #1
	beq _08083076
	b _080831CC
	.align 2, 0
_08083050: .4byte 0x00000951
_08083054: .4byte 0x0000037D
_08083058:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _0808306A
	b _080831CC
_0808306A:
	adds r0, r5, #0
	movs r1, #8
	movs r2, #1
	bl FUN_08080e0c
	b _080831CC
_08083076:
	bl FUN_08084754
	ldr r1, _08083098 @ =0x0000095E
	adds r0, r5, r1
	movs r1, #0x91
	lsls r1, r1, #1
	strh r1, [r0]
	ldr r2, _0808309C @ =0x0000037E
	adds r0, r5, r2
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080830A0
	movs r3, #0x96
	lsls r3, r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	b _080830AC
	.align 2, 0
_08083098: .4byte 0x0000095E
_0808309C: .4byte 0x0000037E
_080830A0:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	strh r0, [r1]
_080830AC:
	ldr r3, _08083150 @ =0x0000037E
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080830C2
	movs r0, #0
	strh r0, [r1]
_080830C2:
	ldr r1, _08083154 @ =0x000001E3
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_08080cac
	bl FUN_080230c4
	adds r6, r0, #0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r2, #0x2c
	ldrsh r0, [r5, r2]
	subs r0, r1, r0
	cmp r0, #0
	bge _080830E2
	rsbs r0, r0, #0
_080830E2:
	adds r3, r0, #0
	movs r0, #4
	ldrsh r1, [r6, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _080830F4
	rsbs r1, r1, #0
_080830F4:
	adds r2, r1, #0
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	cmp r3, #0xbf
	bgt _0808310A
	cmp r2, #0xbf
	ble _08083112
_0808310A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x59
	bls _080831CC
_08083112:
	mov r4, sp
	mov r0, sp
	bl FUN_08084734
	mov r0, sp
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0
	ldrsh r0, [r6, r3]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r4, r0]
	movs r2, #4
	ldrsh r0, [r6, r2]
	subs r2, r1, r0
	adds r0, r3, #0
	adds r1, r2, #0
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	movs r6, #0
	cmp r0, #1
	beq _08083162
	cmp r0, #1
	bgt _08083158
	cmp r0, #0
	beq _0808315E
	b _08083168
	.align 2, 0
_08083150: .4byte 0x0000037E
_08083154: .4byte 0x000001E3
_08083158:
	cmp r0, #2
	beq _08083166
	b _08083168
_0808315E:
	movs r6, #3
	b _08083168
_08083162:
	movs r6, #1
	b _08083168
_08083166:
	movs r6, #2
_08083168:
	ldr r3, _080831D4 @ =0x000004A6
	adds r7, r5, r3
	ldrb r0, [r7]
	adds r0, #3
	movs r1, #3
	ands r0, r1
	cmp r0, r6
	beq _080831C2
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	lsls r4, r6, #3
	subs r3, #0x2e
	adds r2, r4, r3
	adds r2, r5, r2
	bl FUN_08235f40
	cmp r0, #0
	beq _080831C2
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r5, r0
	movs r0, #8
	strb r0, [r1]
	adds r0, r5, r4
	ldr r1, _080831D8 @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _080831DC @ =0x00000471
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r6, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r7]
	movs r0, #0x1e
	bl FUN_08084798
	adds r0, r5, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
_080831C2:
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r0, #0
	strh r0, [r1]
_080831CC:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080831D4: .4byte 0x000004A6
_080831D8: .4byte 0x0000047E
_080831DC: .4byte 0x00000471

	thumb_func_start FUN_080831e0
FUN_080831e0: @ 0x080831E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	mov ip, r1
	adds r5, r2, #0
	adds r6, r3, #0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r2, _08083224 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08083228
	asrs r1, r0, #0xc
	b _0808322E
	.align 2, 0
_08083224: .4byte 0x085B0A08
_08083228:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808322E:
	ldrh r0, [r4, #0x2c]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r4, #0x2e]
	adds r1, #0xe6
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp, #0x14]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x96
	muls r0, r1, r0
	cmp r0, #0
	blt _08083254
	asrs r0, r0, #0xc
	b _0808325A
_08083254:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808325A:
	ldrh r1, [r4, #0x30]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080832A4 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	str r5, [sp]
	ldr r7, _080832A8 @ =0x00000A7A
	adds r0, r4, r7
	ldrh r0, [r0]
	str r0, [sp, #4]
	ldr r1, _080832AC @ =0x00000A7C
	adds r0, r4, r1
	ldrh r0, [r0]
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	ldr r2, _080832B0 @ =0x00000A7E
	adds r0, r4, r2
	ldrh r0, [r0]
	str r0, [sp, #0x10]
	add r0, sp, #0x14
	adds r1, r3, #0
	movs r2, #0x20
	mov r3, ip
	bl Entity080cbabc_Create
	ldr r0, _080832B4 @ =0x00000367
	bl PlaySound_082406e0
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080832A4: .4byte 0xFFFF0000
_080832A8: .4byte 0x00000A7A
_080832AC: .4byte 0x00000A7C
_080832B0: .4byte 0x00000A7E
_080832B4: .4byte 0x00000367

	thumb_func_start FUN_080832b8
FUN_080832b8: @ 0x080832B8
	push {r4, r5, lr}
	sub sp, #0x18
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080832D4
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_08080e0c
_080832D4:
	ldr r2, _080832F4 @ =0x00000951
	adds r0, r4, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _080832F8 @ =0x0000037D
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #7
	bls _080832E8
	b _080835CE
_080832E8:
	lsls r0, r0, #2
	ldr r1, _080832FC @ =_08083300
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080832F4: .4byte 0x00000951
_080832F8: .4byte 0x0000037D
_080832FC: .4byte _08083300
_08083300: @ jump table
	.4byte _08083320 @ case 0
	.4byte _0808337C @ case 1
	.4byte _080833E0 @ case 2
	.4byte _080835CE @ case 3
	.4byte _080835CE @ case 4
	.4byte _08083460 @ case 5
	.4byte _08083510 @ case 6
	.4byte _08083540 @ case 7
_08083320:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _08083332
	b _080835CE
_08083332:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08080e0c
	ldr r0, _08083368 @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _0808336C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08083370 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08083374 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #2
	ldr r2, _08083378 @ =0x0000046F
	adds r1, r4, r2
	strb r0, [r1]
	b _080835CE
	.align 2, 0
_08083368: .4byte 0x0000046E
_0808336C: .4byte 0x030046B8
_08083370: .4byte 0x000003FF
_08083374: .4byte 0x0203B400
_08083378: .4byte 0x0000046F
_0808337C:
	ldr r3, _080833BC @ =0x0000037E
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0
	bne _0808338C
	ldr r0, _080833C0 @ =0x000001F7
	bl PlaySound_082406e0
_0808338C:
	ldr r1, _080833C4 @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080833A6
	b _080835CE
_080833A6:
	bl FUN_080298dc
	cmp r0, #0
	beq _080833C8
	adds r0, r4, #0
	movs r1, #3
	movs r2, #2
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_080833BC: .4byte 0x0000037E
_080833C0: .4byte 0x000001F7
_080833C4: .4byte 0x000001E3
_080833C8:
	adds r0, r4, #0
	movs r1, #1
	movs r2, #6
	movs r3, #2
	bl FUN_080831e0
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_08080e0c
	b _080835CE
_080833E0:
	ldr r1, _0808343C @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _08083440 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08083448
	add r2, sp, #8
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08081de0
	cmp r0, #0
	bne _0808340C
	b _080835CE
_0808340C:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	bne _08083422
	b _080835CE
_08083422:
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #8]
	ldr r3, _08083444 @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	b _08083508
	.align 2, 0
_0808343C: .4byte 0x000001E3
_08083440: .4byte 0x0000037E
_08083444: .4byte 0x00000471
_08083448:
	ldr r0, _0808345C @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _0808345A
	b _080835CE
_0808345A:
	b _08083504
	.align 2, 0
_0808345C: .4byte 0x03002BE0
_08083460:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _080834A4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08083480
	b _080835CE
_08083480:
	ldr r3, _080834A8 @ =0x0000046E
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r2, #0xf1
	adds r0, r4, r2
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrb r0, [r0]
	cmp r1, r0
	bhs _080834AC
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_080834A4: .4byte 0x0000037E
_080834A8: .4byte 0x0000046E
_080834AC:
	ldr r0, _080834FC @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08083504
	add r5, sp, #0xc
	add r2, sp, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_08081de0
	cmp r0, #0
	bne _080834CE
	b _080835CE
_080834CE:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	adds r2, r5, #0
	bl FUN_08235f40
	cmp r0, #0
	beq _080835CE
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #0x14]
	ldr r3, _08083500 @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	b _08083508
	.align 2, 0
_080834FC: .4byte 0x03002BE0
_08083500: .4byte 0x00000471
_08083504:
	adds r0, r4, #0
	movs r1, #3
_08083508:
	movs r2, #6
	bl FUN_08080e0c
	b _080835CE
_08083510:
	ldr r1, _08083538 @ =0x000001E3
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r0, _0808353C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080835CE
	adds r0, r4, #0
	movs r1, #3
	movs r2, #7
	bl FUN_08080e0c
	b _080835CE
	.align 2, 0
_08083538: .4byte 0x000001E3
_0808353C: .4byte 0x0000037E
_08083540:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _080835B4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080835CE
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _080835B8 @ =0x000004A6
	adds r5, r4, r2
	ldrb r2, [r5]
	lsls r2, r2, #3
	movs r3, #0x8f
	lsls r3, r3, #3
	adds r2, r2, r3
	adds r2, r4, r2
	bl FUN_08235f40
	cmp r0, #0
	beq _080835C4
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r1, _080835BC @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _080835C0 @ =0x00000471
	adds r0, r4, r2
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_08080e0c
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r5]
	b _080835CE
	.align 2, 0
_080835B4: .4byte 0x0000037E
_080835B8: .4byte 0x000004A6
_080835BC: .4byte 0x0000047E
_080835C0: .4byte 0x00000471
_080835C4:
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_080835CE:
	add sp, #0x18
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080835d8
FUN_080835d8: @ 0x080835D8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x28
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080835F8
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08080e0c
_080835F8:
	ldr r2, _08083638 @ =0x00000951
	adds r0, r7, r2
	movs r1, #9
	strb r1, [r0]
	ldr r3, _0808363C @ =0x000003E6
	adds r2, r7, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0808367E
	movs r4, #0xfa
	lsls r4, r4, #2
	adds r0, r7, r4
	ldrh r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r2]
	ldr r2, _08083640 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r3, r0
	cmp r0, #0
	blt _08083644
	asrs r0, r0, #0xc
	b _0808364A
	.align 2, 0
_08083638: .4byte 0x00000951
_0808363C: .4byte 0x000003E6
_08083640: .4byte 0x085B0A08
_08083644:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808364A:
	strh r0, [r7, #0x34]
	ldr r1, _08083664 @ =0x000003E6
	adds r0, r7, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _08083668
	asrs r0, r0, #0xc
	b _0808366E
	.align 2, 0
_08083664: .4byte 0x000003E6
_08083668:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808366E:
	strh r0, [r7, #0x38]
	ldr r3, _08083698 @ =0x000003E6
	adds r2, r7, r3
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
_0808367E:
	ldr r4, _0808369C @ =0x0000037D
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #6
	bls _0808368C
	bl _08083E9C
_0808368C:
	lsls r0, r0, #2
	ldr r1, _080836A0 @ =_080836A4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08083698: .4byte 0x000003E6
_0808369C: .4byte 0x0000037D
_080836A0: .4byte _080836A4
_080836A4: @ jump table
	.4byte _080836C0 @ case 0
	.4byte _080836EC @ case 1
	.4byte _08083774 @ case 2
	.4byte _08083800 @ case 3
	.4byte _0808388C @ case 4
	.4byte _08083E44 @ case 5
	.4byte _08083E74 @ case 6
_080836C0:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	bne _080836DE
	bl _08083E9C
_080836DE:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #1
	bl FUN_08080e0c
	bl _08083E9C
_080836EC:
	ldr r6, _08083754 @ =0x0000037E
	adds r4, r7, r6
	ldrh r0, [r4]
	cmp r0, #0
	bne _080836FC
	ldr r0, _08083758 @ =0x000001F7
	bl PlaySound_082406e0
_080836FC:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _0808375C @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _08083720
	b _08083E9C
_08083720:
	ldr r0, _08083760 @ =0x00000402
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	ldr r2, _08083764 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08083768 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0808376C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	ldr r2, _08083770 @ =0x00000403
	adds r1, r7, r2
	strb r0, [r1]
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #2
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083754: .4byte 0x0000037E
_08083758: .4byte 0x000001F7
_0808375C: .4byte 0x000001E3
_08083760: .4byte 0x00000402
_08083764: .4byte 0x030046B8
_08083768: .4byte 0x000003FF
_0808376C: .4byte 0x0203B400
_08083770: .4byte 0x00000403
_08083774:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _080837C0 @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r3, _080837C4 @ =0x0000037E
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2c
	bhi _0808379C
	b _08083E9C
_0808379C:
	ldr r6, _080837C8 @ =0x00000402
	adds r4, r7, r6
	ldr r0, _080837CC @ =0x00000403
	adds r1, r7, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	blo _080837D4
	ldr r0, _080837D0 @ =0x000002E9
	bl PlaySound_082406e0
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #3
	bl FUN_08080e0c
	b _080837E4
	.align 2, 0
_080837C0: .4byte 0x000001E3
_080837C4: .4byte 0x0000037E
_080837C8: .4byte 0x00000402
_080837CC: .4byte 0x00000403
_080837D0: .4byte 0x000002E9
_080837D4:
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #2
	bl FUN_08080e0c
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
_080837E4:
	ldr r2, _080837FC @ =0x0000095E
	adds r1, r7, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r7, r3
	movs r0, #0x20
	strh r0, [r1]
	b _08083E9C
	.align 2, 0
_080837FC: .4byte 0x0000095E
_08083800:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	ldr r1, _08083874 @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r4, _08083878 @ =0x0000037E
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _08083828
	b _08083E9C
_08083828:
	ldr r0, _0808387C @ =0x00000366
	bl PlaySound_082406e0
	movs r6, #0xba
	lsls r6, r6, #2
	adds r2, r7, r6
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r3, _08083880 @ =0x00000A8A
	adds r1, r7, r3
	strh r0, [r1]
	ldr r4, _08083884 @ =0x000004A4
	adds r1, r7, r4
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r2]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r6, _08083888 @ =0x000004A7
	adds r1, r7, r6
	strb r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #2
	adds r0, r7, r1
	bl FUN_08084734
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #4
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083874: .4byte 0x000001E3
_08083878: .4byte 0x0000037E
_0808387C: .4byte 0x00000366
_08083880: .4byte 0x00000A8A
_08083884: .4byte 0x000004A4
_08083888: .4byte 0x000004A7
_0808388C:
	ldr r2, _080838F8 @ =0x000003E6
	adds r1, r7, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r7, #0
	movs r1, #0x80
	bl FUN_08080ec8
	movs r3, #0xde
	lsls r3, r3, #1
	adds r0, r7, r3
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080838AE
	b _08083B48
_080838AE:
	movs r6, #0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	ldrh r1, [r0]
	adds r1, #0x23
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080838FC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	add r5, sp, #8
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080838F4
	cmp r1, #0
	blt _080838F4
	ldr r0, _08083900 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080838F4
	ldr r0, _08083904 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083908
_080838F4:
	movs r4, #0
	b _08083916
	.align 2, 0
_080838F8: .4byte 0x000003E6
_080838FC: .4byte 0xFFFF0000
_08083900: .4byte 0x030046A8
_08083904: .4byte 0x030046AC
_08083908:
	ldr r0, _08083928 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083916:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0808392C
	adds r0, #4
	b _08083938
	.align 2, 0
_08083928: .4byte 0x030046A4
_0808392C:
	ldr r0, _0808394C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083938:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083950
	cmp r2, #2
	beq _08083954
	b _08083958
	.align 2, 0
_0808394C: .4byte 0x030046A4
_08083950:
	ldrb r0, [r5, #4]
	b _08083956
_08083954:
	ldrb r0, [r5]
_08083956:
	subs r1, r1, r0
_08083958:
	movs r4, #0x2e
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bne _080839FA
	add r0, sp, #8
	ldrh r0, [r0]
	subs r0, #0x46
	add r1, sp, #8
	strh r0, [r1]
	adds r5, r1, #0
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0808398E
	cmp r1, #0
	blt _0808398E
	ldr r0, _08083994 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808398E
	ldr r0, _08083998 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808399C
_0808398E:
	movs r4, #0
	b _080839AA
	.align 2, 0
_08083994: .4byte 0x030046A8
_08083998: .4byte 0x030046AC
_0808399C:
	ldr r0, _080839BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080839AA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080839C0
	adds r0, #4
	b _080839CC
	.align 2, 0
_080839BC: .4byte 0x030046A4
_080839C0:
	ldr r0, _080839E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080839CC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080839E4
	cmp r2, #2
	beq _080839E8
	b _080839EC
	.align 2, 0
_080839E0: .4byte 0x030046A4
_080839E4:
	ldrb r0, [r5, #4]
	b _080839EA
_080839E8:
	ldrb r0, [r5]
_080839EA:
	subs r1, r1, r0
_080839EC:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _080839F6
	movs r6, #1
_080839F6:
	cmp r6, #0
	beq _08083A0A
_080839FA:
	ldr r3, _08083A44 @ =0x000004A7
	adds r1, r7, r3
	ldrb r2, [r1]
	movs r0, #0
	ldrsb r0, [r1, r0]
	movs r0, #0x80
	subs r0, r0, r2
	strb r0, [r1]
_08083A0A:
	movs r6, #0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r0, sp, #8
	ldrh r1, [r0, #4]
	adds r1, #0x23
	strh r1, [r0, #4]
	adds r5, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08083A40
	cmp r1, #0
	blt _08083A40
	ldr r0, _08083A48 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08083A40
	ldr r0, _08083A4C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083A50
_08083A40:
	movs r4, #0
	b _08083A5E
	.align 2, 0
_08083A44: .4byte 0x000004A7
_08083A48: .4byte 0x030046A8
_08083A4C: .4byte 0x030046AC
_08083A50:
	ldr r0, _08083A70 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083A5E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08083A74
	adds r0, #4
	b _08083A80
	.align 2, 0
_08083A70: .4byte 0x030046A4
_08083A74:
	ldr r0, _08083A94 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083A80:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083A98
	cmp r2, #2
	beq _08083A9C
	b _08083AA0
	.align 2, 0
_08083A94: .4byte 0x030046A4
_08083A98:
	ldrb r0, [r5, #4]
	b _08083A9E
_08083A9C:
	ldrb r0, [r5]
_08083A9E:
	subs r1, r1, r0
_08083AA0:
	movs r4, #0x2e
	ldrsh r0, [r7, r4]
	cmp r1, r0
	bne _08083B3E
	add r0, sp, #8
	ldrh r1, [r0, #4]
	subs r1, #0x46
	strh r1, [r0, #4]
	adds r5, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08083AD4
	cmp r1, #0
	blt _08083AD4
	ldr r0, _08083AD8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08083AD4
	ldr r0, _08083ADC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08083AE0
_08083AD4:
	movs r4, #0
	b _08083AEE
	.align 2, 0
_08083AD8: .4byte 0x030046A8
_08083ADC: .4byte 0x030046AC
_08083AE0:
	ldr r0, _08083B00 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08083AEE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08083B04
	adds r0, #4
	b _08083B10
	.align 2, 0
_08083B00: .4byte 0x030046A4
_08083B04:
	ldr r0, _08083B24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08083B10:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08083B28
	cmp r2, #2
	beq _08083B2C
	b _08083B30
	.align 2, 0
_08083B24: .4byte 0x030046A4
_08083B28:
	ldrb r0, [r5, #4]
	b _08083B2E
_08083B2C:
	ldrb r0, [r5]
_08083B2E:
	subs r1, r1, r0
_08083B30:
	movs r2, #0x2e
	ldrsh r0, [r7, r2]
	cmp r1, r0
	beq _08083B3A
	movs r6, #1
_08083B3A:
	cmp r6, #0
	beq _08083B48
_08083B3E:
	ldr r3, _08083BE0 @ =0x000004A7
	adds r1, r7, r3
	ldrb r0, [r1]
	rsbs r0, r0, #0
	strb r0, [r1]
_08083B48:
	ldr r4, _08083BE4 @ =0x0000037E
	adds r0, r7, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r0, r1
	cmp r0, #0
	bne _08083BA2
	movs r6, #0xec
	lsls r6, r6, #2
	adds r4, r7, r6
	adds r0, r4, #0
	bl FUN_08084734
	ldr r0, _08083BE8 @ =0x0203B400
	mov r8, r0
	ldr r1, _08083BEC @ =0x030046B8
	mov ip, r1
	ldr r1, [r1]
	adds r1, #1
	ldr r3, _08083BF0 @ =0x000003FF
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	ldrh r0, [r4]
	subs r0, #0xff
	ldr r6, _08083BF4 @ =0x000001FF
	adds r5, r6, #0
	ands r2, r5
	adds r0, r0, r2
	strh r0, [r4]
	adds r1, #1
	ands r1, r3
	mov r0, ip
	str r1, [r0]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	subs r3, #0x4b
	adds r2, r7, r3
	ldrh r0, [r2]
	subs r0, #0xff
	ands r1, r5
	adds r0, r0, r1
	strh r0, [r2]
_08083BA2:
	movs r4, #0xec
	lsls r4, r4, #2
	adds r0, r7, r4
	movs r6, #0
	ldrsh r0, [r0, r6]
	movs r2, #0x2c
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #0xed
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r4, #0
	ldrsh r1, [r1, r4]
	movs r6, #0x30
	ldrsh r2, [r7, r6]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r1, _08083BE0 @ =0x000004A7
	adds r3, r7, r1
	ldrb r2, [r3]
	subs r0, r0, r2
	movs r4, #0x80
	lsls r4, r4, #1
	adds r1, r0, r4
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0x7f
	bgt _08083BF8
	adds r0, r2, #2
	b _08083BFC
	.align 2, 0
_08083BE0: .4byte 0x000004A7
_08083BE4: .4byte 0x0000037E
_08083BE8: .4byte 0x0203B400
_08083BEC: .4byte 0x030046B8
_08083BF0: .4byte 0x000003FF
_08083BF4: .4byte 0x000001FF
_08083BF8:
	adds r0, r2, #0
	adds r0, #0xfe
_08083BFC:
	strb r0, [r3]
	adds r0, r1, #0
	subs r0, #0x40
	cmp r0, #0x80
	bls _08083C20
	ldr r6, _08083C1C @ =0x000004A4
	adds r1, r7, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08083C36
	movs r0, #0x20
	b _08083C34
	.align 2, 0
_08083C1C: .4byte 0x000004A4
_08083C20:
	adds r0, r1, #0
	subs r0, #0x61
	cmp r0, #0x3e
	bhi _08083C36
	ldr r0, _08083C58 @ =0x000004A4
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08083C36
	subs r0, #1
_08083C34:
	strh r0, [r1]
_08083C36:
	ldr r2, _08083C5C @ =0x085B0A08
	ldr r1, _08083C60 @ =0x000004A7
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08083C64
	asrs r0, r0, #0xc
	b _08083C6A
	.align 2, 0
_08083C58: .4byte 0x000004A4
_08083C5C: .4byte 0x085B0A08
_08083C60: .4byte 0x000004A7
_08083C64:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083C6A:
	strh r0, [r7, #0x34]
	ldr r1, _08083C88 @ =0x085B0A08
	ldr r3, _08083C8C @ =0x000004A7
	adds r0, r7, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08083C90
	asrs r0, r0, #0xc
	b _08083C96
	.align 2, 0
_08083C88: .4byte 0x085B0A08
_08083C8C: .4byte 0x000004A7
_08083C90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083C96:
	strh r0, [r7, #0x38]
	ldr r6, _08083D0C @ =0x00000A8A
	adds r5, r7, r6
	ldrh r0, [r5]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r5]
	ldr r0, _08083D10 @ =0x000009E4
	adds r2, r7, r0
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _08083D14 @ =0x000009E6
	adds r1, r7, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	ldrh r1, [r5]
	ldr r3, _08083D18 @ =0x000009CE
	adds r0, r7, r3
	strb r1, [r0]
	ldrh r1, [r5]
	ldr r0, _08083D1C @ =0x0000010F
	subs r0, r0, r1
	movs r4, #0xff
	ands r0, r4
	asrs r0, r0, #5
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r7, r6
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08080c64
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrh r1, [r5]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r5, r0, r1
	ands r5, r4
	ldr r1, _08083D20 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08083D24
	asrs r1, r0, #0xc
	b _08083D2A
	.align 2, 0
_08083D0C: .4byte 0x00000A8A
_08083D10: .4byte 0x000009E4
_08083D14: .4byte 0x000009E6
_08083D18: .4byte 0x000009CE
_08083D1C: .4byte 0x0000010F
_08083D20: .4byte 0x085B0A08
_08083D24:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08083D2A:
	add r3, sp, #0x10
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08083D60 @ =0xFFFF0000
	ldr r2, [sp, #0x10]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _08083D64 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r1, _08083D68 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _08083D6C
	asrs r0, r0, #0xc
	b _08083D72
	.align 2, 0
_08083D60: .4byte 0xFFFF0000
_08083D64: .4byte 0x0000FFFF
_08083D68: .4byte 0x085B0A08
_08083D6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08083D72:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r6, _08083E2C @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r7, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08083E30 @ =0x00000A52
	adds r0, r7, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_08236400
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _08083E34 @ =0x0000037E
	adds r4, r7, r2
	ldrh r0, [r4]
	movs r1, #3
	ands r1, r0
	cmp r1, #0
	bne _08083DEE
	ldr r2, _08083E38 @ =0x0000FFFF
	str r1, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r6
	str r0, [r1, #4]
	ldr r0, [sp, #0x20]
	ands r0, r6
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r6
	orrs r0, r3
	str r0, [r2, #4]
	adds r0, r7, #0
	adds r0, #0x2c
	movs r3, #2
	str r3, [sp]
	movs r3, #4
	str r3, [sp, #4]
	movs r3, #1
	bl FUN_080dbcec
_08083DEE:
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _08083E00
	movs r0, #0x81
	lsls r0, r0, #2
	bl PlaySound_082406e0
_08083E00:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08083E3C @ =0x00000403
	adds r1, r7, r3
	ldrb r1, [r1]
	adds r1, #1
	lsls r1, r1, #5
	cmp r0, r1
	blt _08083E9C
	ldr r0, _08083E40 @ =0x00000366
	bl sound_08240740
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #5
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083E2C: .4byte 0xFFFF0000
_08083E30: .4byte 0x00000A52
_08083E34: .4byte 0x0000037E
_08083E38: .4byte 0x0000FFFF
_08083E3C: .4byte 0x00000403
_08083E40: .4byte 0x00000366
_08083E44:
	ldr r1, _08083E6C @ =0x000001E3
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r4, _08083E70 @ =0x0000037E
	adds r1, r7, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08083E9C
	adds r0, r7, #0
	movs r1, #0x14
	movs r2, #6
	bl FUN_08080e0c
	b _08083E9C
	.align 2, 0
_08083E6C: .4byte 0x000001E3
_08083E70: .4byte 0x0000037E
_08083E74:
	movs r1, #0xef
	lsls r1, r1, #1
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r6, _08083EA8 @ =0x0000037E
	adds r1, r7, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _08083E9C
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08083E9C:
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08083EA8: .4byte 0x0000037E

	thumb_func_start FUN_08083eac
FUN_08083eac: @ 0x08083EAC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r6, _08083EE8 @ =0x03002BF0
	ldrh r0, [r6]
	cmp r0, #0
	beq _08083ECC
	ldr r0, _08083EEC @ =0x0000036A
	bl PlaySound_082406e0
	ldr r1, _08083EF0 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08083EF4 @ =0x00000474
	adds r0, r4, r2
	strh r1, [r0]
_08083ECC:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _08083EFC
	ldr r1, _08083EF8 @ =0x000003D2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08083F3C
	movs r0, #0x19
	b _08084068
	.align 2, 0
_08083EE8: .4byte 0x03002BF0
_08083EEC: .4byte 0x0000036A
_08083EF0: .4byte 0x00000472
_08083EF4: .4byte 0x00000474
_08083EF8: .4byte 0x000003D2
_08083EFC:
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r5, [r0]
	adds r0, r5, #0
	subs r0, #0x18
	cmp r0, #1
	bls _08083F66
	cmp r5, #0x15
	beq _08083F66
	ldrh r0, [r6]
	cmp r0, #0
	beq _08083F48
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	ldr r1, _08083F40 @ =0xFFFFF9FE
	ands r0, r1
	str r0, [r2]
	movs r1, #0
	movs r0, #0x32
	strh r0, [r3]
	ldr r2, _08083F44 @ =0x000003D2
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
_08083F3C:
	movs r0, #0x18
	b _08084068
	.align 2, 0
_08083F40: .4byte 0xFFFFF9FE
_08083F44: .4byte 0x000003D2
_08083F48:
	cmp r5, #0x12
	beq _08083F56
	ldr r1, _08083F5C @ =0x00000474
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _08083F60
_08083F56:
	movs r0, #0x12
	b _08084068
	.align 2, 0
_08083F5C: .4byte 0x00000474
_08083F60:
	subs r0, r5, #2
	cmp r0, #1
	bhi _08083F6A
_08083F66:
	adds r0, r5, #0
	b _08084068
_08083F6A:
	cmp r5, #0x13
	bne _08083F72
	movs r0, #0x13
	b _08084068
_08083F72:
	ldr r0, _08083FD0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x15
	bne _08083FF0
	ldr r2, _08083FD4 @ =0x00000466
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08083FF6
	ldr r3, _08083FD8 @ =0x00000467
	adds r0, r4, r3
	ldrb r0, [r0]
	bl FUN_08081da4
	cmp r0, #0
	beq _08083FE0
	add r2, sp, #8
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08081de0
	cmp r0, #0
	beq _08083FE0
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	mov r2, sp
	bl FUN_08235f40
	cmp r0, #0
	beq _08083FE0
	movs r2, #0x8e
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r1, [sp, #8]
	ldr r3, _08083FDC @ =0x00000471
	adds r0, r4, r3
	strb r1, [r0]
	movs r0, #0x13
	b _08084068
	.align 2, 0
_08083FD0: .4byte 0x03002BE0
_08083FD4: .4byte 0x00000466
_08083FD8: .4byte 0x00000467
_08083FDC: .4byte 0x00000471
_08083FE0:
	ldr r0, _08083FEC @ =0x00000466
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08083FF6
	.align 2, 0
_08083FEC: .4byte 0x00000466
_08083FF0:
	ldr r2, _08084000 @ =0x00000466
	adds r0, r4, r2
	strb r1, [r0]
_08083FF6:
	cmp r5, #1
	bne _08084004
	movs r0, #1
	b _08084068
	.align 2, 0
_08084000: .4byte 0x00000466
_08084004:
	cmp r5, #0x14
	bne _0808400C
	movs r0, #0x14
	b _08084068
_0808400C:
	cmp r5, #8
	bne _08084014
	movs r0, #8
	b _08084068
_08084014:
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r4, r3
	adds r1, r4, #0
	adds r1, #0x2c
	ldr r2, _0808403C @ =0x000004A6
	adds r5, r4, r2
	ldrb r2, [r5]
	lsls r2, r2, #3
	movs r3, #0x8f
	lsls r3, r3, #3
	adds r2, r2, r3
	adds r2, r4, r2
	bl FUN_08235f40
	cmp r0, #0
	bne _08084040
	movs r0, #0
	b _08084068
	.align 2, 0
_0808403C: .4byte 0x000004A6
_08084040:
	movs r0, #0x8e
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #8
	strb r0, [r1]
	ldrb r0, [r5]
	lsls r0, r0, #3
	adds r0, r4, r0
	ldr r1, _08084070 @ =0x0000047E
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r2, _08084074 @ =0x00000471
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r5]
	movs r0, #2
_08084068:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08084070: .4byte 0x0000047E
_08084074: .4byte 0x00000471

	thumb_func_start FUN_08084078
FUN_08084078: @ 0x08084078
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldrh r1, [r5, #0x34]
	ldrh r0, [r5, #0x2c]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080840D0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	ldrh r1, [r5, #0x38]
	ldrh r0, [r5, #0x30]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r3, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080840CC
	cmp r1, #0
	blt _080840CC
	ldr r0, _080840D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080840CC
	ldr r0, _080840D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080840DC
_080840CC:
	movs r4, #0
	b _080840EA
	.align 2, 0
_080840D0: .4byte 0xFFFF0000
_080840D4: .4byte 0x030046A8
_080840D8: .4byte 0x030046AC
_080840DC:
	ldr r0, _080840FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080840EA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08084100
	adds r0, #4
	b _0808410C
	.align 2, 0
_080840FC: .4byte 0x030046A4
_08084100:
	ldr r0, _08084160 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808410C:
	ldrh r0, [r0, #2]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0808411C
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_0808411C:
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_08080ed8
	cmp r0, #0
	beq _080841C0
	movs r0, #0
	str r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_0823b4b8
	adds r6, r5, #0
	adds r6, #0x2c
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0808415C
	cmp r1, #0
	blt _0808415C
	ldr r0, _08084164 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0808415C
	ldr r0, _08084168 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0808416C
_0808415C:
	movs r4, #0
	b _0808417A
	.align 2, 0
_08084160: .4byte 0x030046A4
_08084164: .4byte 0x030046A8
_08084168: .4byte 0x030046AC
_0808416C:
	ldr r0, _0808418C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0808417A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08084190
	adds r0, #4
	b _0808419C
	.align 2, 0
_0808418C: .4byte 0x030046A4
_08084190:
	ldr r0, _080841B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0808419C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080841B4
	cmp r2, #2
	beq _080841B8
	b _080841BC
	.align 2, 0
_080841B0: .4byte 0x030046A4
_080841B4:
	ldrb r0, [r6, #4]
	b _080841BA
_080841B8:
	ldrb r0, [r6]
_080841BA:
	subs r1, r1, r0
_080841BC:
	strh r1, [r5, #0x2e]
	b _080841E0
_080841C0:
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _080841D8
	movs r1, #0xde
	lsls r1, r1, #1
	adds r4, r5, r1
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0823280c
	str r4, [r5, #0x3c]
_080841D8:
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_0823b4b8
_080841E0:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_08080ed8
	cmp r0, #0
	beq _080841FC
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _0808421A
_080841FC:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _08084230 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl FUN_082364c4
_0808421A:
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_08080ed8
	cmp r0, #0
	beq _08084238
	ldr r0, _08084234 @ =0x00000464
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	b _08084262
	.align 2, 0
_08084230: .4byte 0x0000FFFB
_08084234: .4byte 0x00000464
_08084238:
	ldr r1, _08084298 @ =0x00000464
	adds r4, r5, r1
	ldrb r0, [r4]
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r0, #0
	bne _08084256
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r6, #0
	bl FUN_082362fc
	movs r0, #1
	strb r0, [r4]
_08084256:
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r6, #0
	bl FUN_08236268
_08084262:
	adds r2, r5, #0
	adds r2, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _0808429C @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842A0
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080842AC
	.align 2, 0
_08084298: .4byte 0x00000464
_0808429C: .4byte 0x000003F6
_080842A0:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080842AC:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842C6
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _080842CC
_080842C6:
	ldr r0, [r4]
	ldr r1, _080842E4 @ =0xFFFFFDFF
	ands r0, r1
_080842CC:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08080ed8
	cmp r0, #0
	beq _080842EC
	ldr r1, _080842E8 @ =0x0000060C
	adds r0, r5, r1
	bl ParticleShadow_Hide
	b _080842F4
	.align 2, 0
_080842E4: .4byte 0xFFFFFDFF
_080842E8: .4byte 0x0000060C
_080842EC:
	ldr r2, _08084310 @ =0x0000060C
	adds r0, r5, r2
	bl ParticleShadow_Show
_080842F4:
	adds r0, r5, #0
	movs r1, #0x80
	bl FUN_08080ed8
	cmp r0, #0
	beq _08084318
	ldr r1, _08084314 @ =0x000009C8
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _08084322
	.align 2, 0
_08084310: .4byte 0x0000060C
_08084314: .4byte 0x000009C8
_08084318:
	ldr r2, _0808432C @ =0x000009C8
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_08084322:
	str r1, [r0]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0808432C: .4byte 0x000009C8

	thumb_func_start FUN_08084330
FUN_08084330: @ 0x08084330
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	beq _08084340
	cmp r0, #2
	beq _08084388
	b _080843A4
_08084340:
	ldr r0, [r4, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0808435E
	ldr r0, _0808437C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08084380 @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	asrs r1, r1, #1
	adds r0, r4, #0
	bl FUN_08081d18
_0808435E:
	adds r0, r4, #0
	bl FUN_08083eac
	ldr r1, _08084384 @ =0x085ABF54
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08084078
	b _080843A4
	.align 2, 0
_0808437C: .4byte 0x030046A0
_08084380: .4byte 0x00000942
_08084384: .4byte 0x085ABF54
_08084388:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_08080ec8
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_08084078
_080843A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080843ac
FUN_080843ac: @ 0x080843AC
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	ldr r6, [r4, #0x1c]
	cmp r6, #1
	beq _080843BC
	b _0808453A
_080843BC:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	beq _080843DE
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r1, [r2]
	adds r0, r6, #0
	ands r0, r1
	cmp r0, #0
	bne _080843D8
	b _0808453A
_080843D8:
	movs r0, #0xfe
	ands r0, r1
	strb r0, [r2]
_080843DE:
	adds r0, r3, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r5, #0
	adds r0, #0x44
	movs r2, #0
	mov ip, r2
	strh r1, [r0]
	movs r7, #0xdf
	lsls r7, r7, #2
	adds r0, r4, r7
	ldrb r0, [r0]
	cmp r0, #8
	bne _0808449C
	ldr r1, _08084440 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808449C
	ldr r2, _08084444 @ =0x00000476
	adds r1, r4, r2
	movs r0, #4
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #5
	ldr r0, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0808444C
	ldr r3, _08084448 @ =0x0000046B
	adds r2, r4, r3
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	adds r7, #0xee
	adds r1, r4, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08084490
	mov r0, ip
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_08080e0c
	b _0808453A
	.align 2, 0
_08084440: .4byte 0x0000037D
_08084444: .4byte 0x00000476
_08084448: .4byte 0x0000046B
_0808444C:
	ldr r1, _08084488 @ =0x00000469
	adds r2, r4, r1
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r1, r4, r7
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08084490
	mov r0, ip
	strb r0, [r2]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_08080f20
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _0808448C @ =0x000003D2
	adds r0, r4, r3
	strb r6, [r0]
	adds r1, r5, #0
	adds r1, #0x40
	movs r0, #0x64
	b _08084538
	.align 2, 0
_08084488: .4byte 0x00000469
_0808448C: .4byte 0x000003D2
_08084490:
	ldr r0, _08084498 @ =0x0000036A
	bl PlaySound_082406e0
	b _0808453A
	.align 2, 0
_08084498: .4byte 0x0000036A
_0808449C:
	ldr r7, _080844C8 @ =0x00000469
	adds r1, r4, r7
	movs r0, #0
	strb r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080844BC
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080844CC
_080844BC:
	adds r0, r4, #0
	adds r1, r3, #0
	adds r2, r5, #0
	bl FUN_08080f80
	b _0808453A
	.align 2, 0
_080844C8: .4byte 0x00000469
_080844CC:
	adds r0, r3, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r2, _08084500 @ =0x000003E6
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08084504
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
	b _08084538
	.align 2, 0
_08084500: .4byte 0x000003E6
_08084504:
	movs r7, #0x24
	ldrsh r0, [r3, r7]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r7, #0x28
	ldrsh r1, [r3, r7]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #4
	ands r0, r1
	movs r7, #0xfa
	lsls r7, r7, #2
	adds r1, r4, r7
_08084538:
	strh r0, [r1]
_0808453A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

