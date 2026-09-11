	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b39c8
FUN_080b39c8: @ 0x080B39C8
	ldr r0, _080B39D8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_080B39D8: .4byte 0x030046A0
_080B39DC:
	.byte 0x00, 0xB5, 0x61, 0x20
	.byte 0x7D, 0xF1, 0x96, 0xFD, 0x00, 0x28, 0x0C, 0xD0, 0x7D, 0xF1, 0x7C, 0xFE, 0x01, 0x1C, 0x06, 0x48
	.byte 0x81, 0x42, 0x00, 0xDD, 0x01, 0x1C, 0x05, 0x48, 0x00, 0x68, 0x91, 0x22, 0x12, 0x01, 0x80, 0x18
	.byte 0x01, 0x80, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x0F, 0x27, 0x00, 0x00, 0xA0, 0x46, 0x00, 0x03

	thumb_func_start solar_bank_080b3a10
solar_bank_080b3a10: @ 0x080B3A10
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	ldr r0, _080B3A38 @ =0x000005D4
	add r0, r8
	ldr r4, [r0]
	cmp r4, #0
	bne _080B3A3C
	mov r7, r8
	adds r7, #0x38
	movs r1, #0
	add r0, sp, #0xc
_080B3A2C:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B3A2C
	b _080B3A7C
	.align 2, 0
_080B3A38: .4byte 0x000005D4
_080B3A3C:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
	mov r7, r8
	adds r7, #0x38
_080B3A7C:
	mov r6, sp
	movs r4, #0xee
	lsls r4, r4, #2
	add r4, r8
	movs r5, #3
_080B3A86:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B3A86
	movs r0, #0xbb
	lsls r0, r0, #3
	add r0, r8
	ldr r4, [r0]
	cmp r4, #0
	bne _080B3AB8
	movs r1, #0
	add r0, sp, #0xc
_080B3AAE:
	str r1, [r0]
	subs r0, #4
	cmp r0, sp
	bge _080B3AAE
	b _080B3AF4
_080B3AB8:
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r4, #0
	bl Div
	str r0, [sp]
	lsls r1, r0, #5
	subs r1, r1, r0
	lsls r1, r1, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	subs r4, r4, r1
	adds r0, r4, #0
	movs r1, #0x64
	bl Div
	str r0, [sp, #4]
	movs r1, #0x64
	muls r0, r1, r0
	subs r4, r4, r0
	adds r0, r4, #0
	movs r1, #0xa
	bl Div
	str r0, [sp, #8]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #1
	subs r1, r4, r1
	str r1, [sp, #0xc]
_080B3AF4:
	mov r6, sp
	movs r4, #0x8e
	lsls r4, r4, #2
	add r4, r8
	movs r5, #3
_080B3AFE:
	ldm r6!, {r2}
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	adds r1, r7, #0
	movs r3, #1
	bl Sprite_SetSprite
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080B3AFE
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b3b24
FUN_080b3b24: @ 0x080B3B24
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x60
	movs r2, #0xc
_080B3B30:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _080B3B30
	movs r4, #1
	movs r0, #0xa7
	lsls r0, r0, #3
	adds r1, r3, r0
	movs r2, #1
_080B3B48:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x2c
	subs r2, #1
	cmp r2, #0
	bge _080B3B48
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b3b5c
FUN_080b3b5c: @ 0x080B3B5C
	movs r3, #0xbe
	lsls r3, r3, #3
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080B3B70 @ =0x000005EC
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080B3B70: .4byte 0x000005EC

	thumb_func_start FUN_080b3b74
FUN_080b3b74: @ 0x080B3B74
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #0
	bl FUN_0822c398
	movs r6, #0
	str r6, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b3b24
	ldr r0, [r4, #0x60]
	movs r5, #2
	rsbs r5, r5, #0
	ands r0, r5
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r6, [sp]
	movs r2, #0
	movs r3, #2
	bl FUN_082370cc
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r5
	str r0, [r1]
	movs r0, #0
	bl FUN_08047a28
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B3C00 @ =0x0000FFFF
	str r0, [sp, #4]
	str r6, [sp, #8]
	movs r0, #2
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B3C04 @ =FUN_080b3e3c
	adds r0, r4, #0
	bl FUN_080b3b5c
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B3C00: .4byte 0x0000FFFF
_080B3C04: .4byte FUN_080b3e3c

	thumb_func_start FUN_080b3c08
FUN_080b3c08: @ 0x080B3C08
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #0
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b3b24
	ldr r0, [r4, #0x60]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r4, #0x60]
	movs r0, #0x90
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, _080B3C90 @ =0x000005EA
	adds r1, r4, r0
	movs r0, #1
	strh r0, [r1]
	adds r1, r4, #0
	adds r1, #0xc0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r4, #0
	adds r0, #0xb8
	subs r1, #0x88
	str r5, [sp]
	movs r2, #4
	movs r3, #1
	bl FUN_082370cc
	movs r0, #1
	bl FUN_08047a28
	ldr r1, _080B3C94 @ =FUN_080b3e80
	adds r0, r4, #0
	bl FUN_080b3b5c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B3C90: .4byte 0x000005EA
_080B3C94: .4byte FUN_080b3e80

	thumb_func_start FUN_080b3c98
FUN_080b3c98: @ 0x080B3C98
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #1
	bl FUN_0822c398
	movs r6, #0
	str r6, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r7, #0
	bl FUN_080b3b24
	ldr r0, [r7, #0x60]
	movs r4, #2
	rsbs r4, r4, #0
	ands r0, r4
	str r0, [r7, #0x60]
	adds r0, r7, #0
	adds r0, #0x58
	adds r5, r7, #0
	adds r5, #0x18
	str r6, [sp]
	adds r1, r5, #0
	movs r2, #1
	movs r3, #1
	bl FUN_082370cc
	movs r3, #0xf0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r2, r7, r3
	ldr r0, _080B3DB4 @ =0x030046A0
	ldr r1, [r0]
	movs r3, #0xef
	lsls r3, r3, #2
	adds r0, r1, r3
	ldr r0, [r0]
	str r0, [r2]
	ldr r0, _080B3DB8 @ =0x000005D4
	adds r2, r7, r0
	movs r3, #0x91
	lsls r3, r3, #4
	adds r1, r1, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	str r0, [r2]
	movs r0, #0xf0
	lsls r0, r0, #2
	adds r2, r7, r0
	movs r3, #0x90
	lsls r3, r3, #2
	adds r1, r7, r3
	movs r3, #3
_080B3D30:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	ldr r0, [r2]
	ands r0, r4
	str r0, [r2]
	adds r2, #0x60
	adds r1, #0x60
	subs r3, #1
	cmp r3, #0
	bge _080B3D30
	adds r0, r7, #0
	bl solar_bank_080b3a10
	movs r2, #2
	rsbs r2, r2, #0
	movs r0, #0xa7
	lsls r0, r0, #3
	adds r1, r7, r0
	movs r3, #1
_080B3D58:
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r1, #0x2c
	subs r3, #1
	cmp r3, #0
	bge _080B3D58
	movs r4, #0
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, _080B3DBC @ =0x0000013D
	bl Video_SetActorSpritePltt
	ldr r3, _080B3DC0 @ =0x000005AC
	adds r0, r7, r3
	movs r1, #0xa0
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	movs r0, #2
	bl FUN_08047a28
	ldr r1, _080B3DC4 @ =0x000005E2
	adds r0, r7, r1
	strh r4, [r0]
	ldr r3, _080B3DC8 @ =0x000005E4
	adds r0, r7, r3
	strh r4, [r0]
	adds r1, #4
	adds r0, r7, r1
	strh r4, [r0]
	adds r3, #4
	adds r0, r7, r3
	strh r4, [r0]
	subs r1, #6
	adds r0, r7, r1
	strh r4, [r0]
	ldr r1, _080B3DCC @ =solar_bank_080b3f38
	adds r0, r7, #0
	bl FUN_080b3b5c
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B3DB4: .4byte 0x030046A0
_080B3DB8: .4byte 0x000005D4
_080B3DBC: .4byte 0x0000013D
_080B3DC0: .4byte 0x000005AC
_080B3DC4: .4byte 0x000005E2
_080B3DC8: .4byte 0x000005E4
_080B3DCC: .4byte solar_bank_080b3f38

	thumb_func_start FUN_080b3dd0
FUN_080b3dd0: @ 0x080B3DD0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	movs r0, #0
	movs r2, #2
	bl FUN_0822c398
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	adds r0, r4, #0
	bl FUN_080b3b24
	ldr r0, _080B3E34 @ =0x000002BF
	bl PlaySound_082406e0
	ldr r0, [r4, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	str r5, [sp]
	movs r2, #2
	movs r3, #2
	bl FUN_082370cc
	movs r0, #3
	bl FUN_08047a28
	ldr r1, _080B3E38 @ =FUN_080b4334
	adds r0, r4, #0
	bl FUN_080b3b5c
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B3E34: .4byte 0x000002BF
_080B3E38: .4byte FUN_080b4334

	thumb_func_start FUN_080b3e3c
FUN_080b3e3c: @ 0x080B3E3C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080B3E78 @ =0x000005EC
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x20
	bne _080B3E50
	ldr r0, _080B3E7C @ =0x000002BE
	bl PlaySound_082406e0
_080B3E50:
	adds r0, r5, #0
	adds r0, #0x58
	adds r1, r5, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x68
	bls _080B3E70
	adds r0, r5, #0
	bl FUN_080b3c08
_080B3E70:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B3E78: .4byte 0x000005EC
_080B3E7C: .4byte 0x000002BE

	thumb_func_start FUN_080b3e80
FUN_080b3e80: @ 0x080B3E80
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080B3EAC @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080B3EB4
	ldr r1, _080B3EB0 @ =0x000005EA
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B3EC0
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b3c98
	b _080B3F24
	.align 2, 0
_080B3EAC: .4byte 0x030044E0
_080B3EB0: .4byte 0x000005EA
_080B3EB4:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _080B3ECE
_080B3EC0:
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080b3dd0
	b _080B3F24
_080B3ECE:
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _080B3F18
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldr r0, _080B3F00 @ =0x000005EA
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080B3F04
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r5, [sp]
	movs r2, #4
	b _080B3F10
	.align 2, 0
_080B3F00: .4byte 0x000005EA
_080B3F04:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	str r2, [sp]
	movs r2, #5
_080B3F10:
	movs r3, #1
	bl FUN_082370cc
	b _080B3F24
_080B3F18:
	adds r0, r4, #0
	adds r0, #0xb8
	adds r1, r4, #0
	adds r1, #0x38
	bl FUN_082372cc
_080B3F24:
	adds r0, r4, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_082372cc
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start solar_bank_080b3f38
solar_bank_080b3f38: @ 0x080B3F38
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	ldr r3, _080B3F84 @ =0x030044E0
	ldrh r1, [r3, #2]
	movs r0, #1
	mov sb, r0
	ands r0, r1
	cmp r0, #0
	beq _080B3F90
	ldr r2, _080B3F88 @ =0x030046A0
	ldr r0, [r2]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r1, [r1]
	str r1, [r0]
	ldr r0, [r2]
	movs r1, #0x91
	lsls r1, r1, #4
	adds r0, r0, r1
	ldr r2, _080B3F8C @ =0x000005D4
	adds r1, r5, r2
	ldr r1, [r1]
	strh r1, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b3dd0
	b _080B3FA8
	.align 2, 0
_080B3F84: .4byte 0x030044E0
_080B3F88: .4byte 0x030046A0
_080B3F8C: .4byte 0x000005D4
_080B3F90:
	movs r0, #2
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080B3FAE
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080b3c08
_080B3FA8:
	adds r1, r5, #0
	adds r1, #0x18
	b _080B4318
_080B3FAE:
	ldrh r1, [r3]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	bne _080B3FBA
	b _080B40BC
_080B3FBA:
	movs r3, #0xbb
	lsls r3, r3, #3
	adds r6, r5, r3
	ldr r1, [r6]
	ldr r0, _080B4030 @ =0x0000270E
	cmp r1, r0
	bls _080B3FCA
	b _080B41F4
_080B3FCA:
	ldr r0, _080B4034 @ =0x000005D4
	adds r4, r5, r0
	ldr r0, [r4]
	cmp r0, #0
	bne _080B3FD6
	b _080B41F4
_080B3FD6:
	ldr r1, _080B4038 @ =0x000005E2
	adds r7, r5, r1
	ldrh r0, [r7]
	cmp r0, #0
	bne _080B3FE6
	adds r3, #0xc
	adds r0, r5, r3
	strh r2, [r0]
_080B3FE6:
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r0, r5, r1
	strh r2, [r0]
	ldr r2, _080B403C @ =0x000005E6
	adds r2, r2, r5
	mov r8, r2
	movs r0, #0x10
	strh r0, [r2]
	ldrh r1, [r7]
	adds r0, r1, #0
	cmp r0, #0x7f
	bls _080B4070
	ldr r0, _080B4040 @ =0x0000037D
	bl PlaySound_082406e0
	movs r7, #0xa
	ldr r0, [r4]
	cmp r0, #0xa
	bhs _080B4010
	adds r7, r0, #0
_080B4010:
	movs r2, #0xa
	ldr r1, [r6]
	adds r0, r1, #0
	adds r0, #0xa
	ldr r3, _080B4044 @ =0x0000270F
	cmp r0, r3
	bls _080B4020
	subs r2, r3, r1
_080B4020:
	cmp r7, r2
	bge _080B4048
	adds r0, r1, r7
	str r0, [r6]
	ldr r0, [r4]
	subs r0, r0, r7
	b _080B4050
	.align 2, 0
_080B4030: .4byte 0x0000270E
_080B4034: .4byte 0x000005D4
_080B4038: .4byte 0x000005E2
_080B403C: .4byte 0x000005E6
_080B4040: .4byte 0x0000037D
_080B4044: .4byte 0x0000270F
_080B4048:
	adds r0, r1, r2
	str r0, [r6]
	ldr r0, [r4]
	subs r0, r0, r2
_080B4050:
	str r0, [r4]
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r3, _080B4068 @ =0x000005E4
	adds r1, r5, r3
	movs r0, #2
	strh r0, [r1]
	ldr r0, _080B406C @ =0x000005E6
	adds r1, r5, r0
	b _080B4174
	.align 2, 0
_080B4068: .4byte 0x000005E4
_080B406C: .4byte 0x000005E6
_080B4070:
	cmp r0, #0x3f
	bls _080B4094
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080B4082
	ldr r0, _080B4090 @ =0x0000037D
	bl PlaySound_082406e0
_080B4082:
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	b _080B41A2
	.align 2, 0
_080B4090: .4byte 0x0000037D
_080B4094:
	adds r0, r1, #1
	strh r0, [r7]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080B40A2
	b _080B420A
_080B40A2:
	ldr r0, _080B40B8 @ =0x0000037D
	bl PlaySound_082406e0
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	ldr r0, [r4]
	subs r0, #1
	str r0, [r4]
	b _080B41E6
	.align 2, 0
_080B40B8: .4byte 0x0000037D
_080B40BC:
	movs r2, #0x10
	adds r0, r2, #0
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _080B40CC
	b _080B4204
_080B40CC:
	movs r1, #0xbb
	lsls r1, r1, #3
	adds r6, r5, r1
	ldr r0, [r6]
	cmp r0, #0
	bne _080B40DA
	b _080B41F4
_080B40DA:
	ldr r3, _080B4140 @ =0x000005D4
	adds r4, r5, r3
	ldr r1, [r4]
	ldr r0, _080B4144 @ =0x0000270E
	cmp r1, r0
	bls _080B40E8
	b _080B41F4
_080B40E8:
	ldr r0, _080B4148 @ =0x000005E2
	adds r7, r5, r0
	ldrh r1, [r7]
	cmp r1, #0
	bne _080B40F8
	adds r3, #0x10
	adds r0, r5, r3
	strh r1, [r0]
_080B40F8:
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r0, r5, r1
	mov r3, sb
	strh r3, [r0]
	ldr r0, _080B414C @ =0x000005E6
	adds r0, r0, r5
	mov r8, r0
	strh r2, [r0]
	ldrh r1, [r7]
	adds r0, r1, #0
	cmp r0, #0x7f
	bls _080B4184
	ldr r0, _080B4150 @ =0x0000037D
	bl PlaySound_082406e0
	movs r7, #0xa
	ldr r0, [r6]
	cmp r0, #0xa
	bhs _080B4122
	adds r7, r0, #0
_080B4122:
	movs r2, #0xa
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0xa
	ldr r3, _080B4154 @ =0x0000270F
	cmp r0, r3
	bls _080B4132
	subs r2, r3, r1
_080B4132:
	cmp r7, r2
	bge _080B4158
	adds r0, r1, r7
	str r0, [r4]
	ldr r0, [r6]
	subs r0, r0, r7
	b _080B4160
	.align 2, 0
_080B4140: .4byte 0x000005D4
_080B4144: .4byte 0x0000270E
_080B4148: .4byte 0x000005E2
_080B414C: .4byte 0x000005E6
_080B4150: .4byte 0x0000037D
_080B4154: .4byte 0x0000270F
_080B4158:
	adds r0, r1, r2
	str r0, [r4]
	ldr r0, [r6]
	subs r0, r0, r2
_080B4160:
	str r0, [r6]
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r2, _080B417C @ =0x000005E4
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	ldr r3, _080B4180 @ =0x000005E6
	adds r1, r5, r3
_080B4174:
	movs r0, #4
	strh r0, [r1]
	b _080B420A
	.align 2, 0
_080B417C: .4byte 0x000005E4
_080B4180: .4byte 0x000005E6
_080B4184:
	cmp r0, #0x3f
	bls _080B41C8
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080B4196
	ldr r0, _080B41C0 @ =0x0000037D
	bl PlaySound_082406e0
_080B4196:
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
_080B41A2:
	adds r0, r5, #0
	bl solar_bank_080b3a10
	ldr r1, _080B41C4 @ =0x000005E4
	adds r0, r5, r1
	mov r2, sb
	strh r2, [r0]
	movs r0, #4
	mov r3, r8
	strh r0, [r3]
	ldrh r0, [r7]
	adds r0, #1
	strh r0, [r7]
	b _080B420A
	.align 2, 0
_080B41C0: .4byte 0x0000037D
_080B41C4: .4byte 0x000005E4
_080B41C8:
	adds r0, r1, #1
	strh r0, [r7]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080B420A
	ldr r0, _080B41F0 @ =0x0000037D
	bl PlaySound_082406e0
	ldr r0, [r4]
	adds r0, #1
	str r0, [r4]
	ldr r0, [r6]
	subs r0, #1
	str r0, [r6]
_080B41E6:
	adds r0, r5, #0
	bl solar_bank_080b3a10
	b _080B420A
	.align 2, 0
_080B41F0: .4byte 0x0000037D
_080B41F4:
	ldr r0, _080B4200 @ =0x000005E2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	b _080B420A
	.align 2, 0
_080B4200: .4byte 0x000005E2
_080B4204:
	ldr r2, _080B422C @ =0x000005E2
	adds r0, r5, r2
	strh r1, [r0]
_080B420A:
	ldr r3, _080B4230 @ =0x000005E6
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0
	beq _080B4264
	ldr r1, _080B4234 @ =0x000005E4
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080B4238
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #4
	b _080B4252
	.align 2, 0
_080B422C: .4byte 0x000005E2
_080B4230: .4byte 0x000005E6
_080B4234: .4byte 0x000005E4
_080B4238:
	cmp r0, #1
	bne _080B4248
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #2
	b _080B4252
_080B4248:
	movs r0, #0xbc
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
_080B4252:
	strh r0, [r1]
	ldr r2, _080B4260 @ =0x000005E6
	adds r1, r5, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080B426C
	.align 2, 0
_080B4260: .4byte 0x000005E6
_080B4264:
	movs r3, #0xbc
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
_080B426C:
	movs r1, #0xbc
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r1, [r0]
	cmp r1, #0
	bne _080B42B0
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, _080B42A8 @ =0x0000013D
	bl Video_SetActorSpritePltt
	ldr r3, _080B42AC @ =0x000005AC
	adds r0, r5, r3
	movs r1, #0xa0
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, r4, #0
	movs r2, #0x12
	movs r3, #1
	bl Sprite_SetSprite
	b _080B4316
	.align 2, 0
_080B42A8: .4byte 0x0000013D
_080B42AC: .4byte 0x000005AC
_080B42B0:
	movs r0, #0x1f
	ands r0, r1
	lsrs r0, r0, #3
	cmp r0, #1
	beq _080B42CA
	cmp r0, #1
	bgt _080B42C4
	cmp r0, #0
	beq _080B42CE
	b _080B42D2
_080B42C4:
	cmp r0, #2
	beq _080B42CE
	b _080B42D2
_080B42CA:
	movs r6, #2
	b _080B42D4
_080B42CE:
	movs r6, #1
	b _080B42D4
_080B42D2:
	movs r6, #0
_080B42D4:
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r3, _080B432C @ =0x0000013D
	adds r1, r6, r3
	bl Video_SetActorSpritePltt
	ldr r1, _080B4330 @ =0x000005AC
	adds r0, r5, r1
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r1, r6, r1
	bl Video_SetActorSpritePltt
	movs r2, #0xec
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r4, r5, #0
	adds r4, #0x18
	movs r3, #0xbd
	lsls r3, r3, #3
	adds r1, r5, r3
	ldrh r1, [r1]
	lsls r2, r1, #1
	adds r2, r2, r1
	adds r2, #0x13
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r1, r4, #0
	movs r3, #1
	bl Sprite_SetSprite
_080B4316:
	adds r1, r4, #0
_080B4318:
	adds r0, r5, #0
	adds r0, #0x58
	bl FUN_082372cc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B432C: .4byte 0x0000013D
_080B4330: .4byte 0x000005AC

	thumb_func_start FUN_080b4334
FUN_080b4334: @ 0x080B4334
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r0, #0x58
	adds r1, r4, #0
	adds r1, #0x18
	bl FUN_082372cc
	ldr r0, _080B4380 @ =0x000005EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x95
	bls _080B4376
	movs r0, #4
	str r0, [sp]
	ldr r0, _080B4384 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080B4388 @ =FUN_080b438c
	adds r0, r4, #0
	bl FUN_080b3b5c
_080B4376:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B4380: .4byte 0x000005EC
_080B4384: .4byte 0x0000FFFF
_080B4388: .4byte FUN_080b438c

	thumb_func_start FUN_080b438c
FUN_080b438c: @ 0x080B438C
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080B43C0 @ =0x000005EC
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080B43B8
	ldr r1, _080B43C4 @ =0x000005DC
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080B43B8
	movs r1, #0
	bl Script_ExecById
	adds r0, r4, #0
	bl KillEntity
_080B43B8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080B43C0: .4byte 0x000005EC
_080B43C4: .4byte 0x000005DC

