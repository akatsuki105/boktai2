	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805dde0
FUN_0805dde0: @ 0x0805DDE0
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r3, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805DDFC
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805DE14
_0805DDFC:
	movs r1, #0x24
	ldrsh r0, [r5, r1]
	movs r2, #0x24
	ldrsh r1, [r3, r2]
	subs r0, r0, r1
	movs r2, #0x28
	ldrsh r1, [r5, r2]
	movs r5, #0x28
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl ArcTan2_8
_0805DE14:
	strb r0, [r4]
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	str r1, [r4, #4]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805de28
FUN_0805de28: @ 0x0805DE28
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805de2c
FUN_0805de2c: @ 0x0805DE2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov sl, r1
	movs r0, #0
	strb r0, [r1]
	strb r0, [r1, #1]
	strb r0, [r1, #2]
	movs r0, #1
	strb r0, [r1, #3]
	movs r0, #0
	str r0, [r1, #4]
	mov r4, sl
	adds r4, #0xf0
	ldr r1, _0805DF70 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	ldr r1, _0805DF74 @ =0x00000263
	bl Video_SetAuxSpritePltt
	mov r5, sl
	adds r5, #0xc4
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #2
	strb r0, [r5, #7]
	movs r1, #0xe0
	add r1, sl
	mov sb, r1
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _0805DF78 @ =0x05000002
	bl CpuSet
	movs r4, #0x86
	lsls r4, r4, #1
	add r4, sl
	adds r0, r4, #0
	mov r1, sb
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	mov r7, sl
	adds r7, #0x64
	ldr r2, _0805DF7C @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x20
	mov r8, r1
	orrs r0, r1
	ldr r1, _0805DF80 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	mov r1, r8
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _0805DF84 @ =0x00005005
	movs r6, #0x10
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805DF88 @ =FUN_0805dde0
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0x80
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r7, #0
	bl Hitbox_Register
	subs r7, #0x50
	mov r0, r8
	strh r0, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	mov r1, r8
	strh r1, [r5, #4]
	movs r0, #0
	strh r0, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	movs r1, #0
	strh r1, [r4, #4]
	ldr r2, _0805DF8C @ =0x00002001
	str r6, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805DF90 @ =FUN_0805de28
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0
	str r0, [sp]
	movs r0, #8
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0xa
	movs r2, #0x1e
	bl Hitbox_SetAttack
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805DF70: .4byte 0x0000DA6D
_0805DF74: .4byte 0x00000263
_0805DF78: .4byte 0x05000002
_0805DF7C: .4byte 0xFFFF0000
_0805DF80: .4byte 0x0000FFFF
_0805DF84: .4byte 0x00005005
_0805DF88: .4byte FUN_0805dde0
_0805DF8C: .4byte 0x00002001
_0805DF90: .4byte FUN_0805de28

	thumb_func_start FUN_0805df94
FUN_0805df94: @ 0x0805DF94
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x64
	bl Hitbox_Unregister
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Remove
	adds r0, r4, #0
	adds r0, #0xc4
	bl AuxSprite_Remove
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805dfb8
FUN_0805dfb8: @ 0x0805DFB8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r3, r1, #0
	adds r6, r2, #0
	adds r1, #0xc4
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	adds r2, r3, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r3, r1
	bl ParticleShadow_Hide
	lsls r4, r6
	ldr r1, [r5, #0x18]
	bics r1, r4
	str r1, [r5, #0x18]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805dff0
FUN_0805dff0: @ 0x0805DFF0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r1, r0, #1
	movs r0, #3
	ands r1, r0
	add r4, sp, #4
	mov r3, sp
	adds r3, #5
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r7, r3, #0
	cmp r0, #1
	bhi _0805E01E
	movs r0, #1
	b _0805E020
_0805E01E:
	movs r0, #0
_0805E020:
	strb r0, [r4]
	cmp r1, #1
	bls _0805E02A
	movs r0, #1
	b _0805E02C
_0805E02A:
	movs r0, #0
_0805E02C:
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xb4
	ldr r1, [r6, #0x20]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r7]
	str r4, [sp]
	bl FUN_08236fac
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805e04c
FUN_0805e04c: @ 0x0805E04C
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805e050
FUN_0805e050: @ 0x0805E050
	push {r4, r5, r6, r7, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	adds r6, r4, #0
	adds r6, #0xc4
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E0D0
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805dff0
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4]
	ldrb r7, [r4, #9]
	ldr r2, _0805E0A0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805E0A4
	asrs r1, r0, #0xc
	b _0805E0AA
	.align 2, 0
_0805E0A0: .4byte 0x085B0A08
_0805E0A4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E0AA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805E0C4 @ =0x085B0A08
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _0805E0C8
	asrs r0, r0, #0xc
	b _0805E0CE
	.align 2, 0
_0805E0C4: .4byte 0x085B0A08
_0805E0C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E0CE:
	strh r0, [r3, #4]
_0805E0D0:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r2, r4, #0
	adds r2, #0xc
	ldrh r0, [r4, #0xc]
	ldrh r3, [r6, #0x1c]
	adds r0, r0, r3
	strh r0, [r6, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldr r0, [r4, #4]
	ldrb r3, [r4, #8]
	cmp r0, r3
	blo _0805E104
	movs r0, #2
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	movs r0, #0
	b _0805E106
_0805E104:
	adds r0, #1
_0805E106:
	str r0, [r4, #4]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805e110
FUN_0805e110: @ 0x0805E110
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	movs r0, #0xc4
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E142
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805dff0
_0805E142:
	ldr r0, [r4, #4]
	movs r1, #0xf
	ands r0, r1
	ands r5, r1
	adds r6, r4, #0
	adds r6, #0xe0
	cmp r0, r5
	bne _0805E17C
	ldr r1, _0805E1DC @ =0x00001508
	adds r2, r7, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	mov r5, r8
	movs r3, #0x1c
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805dff0
_0805E17C:
	adds r0, r4, #0
	adds r0, #0x64
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [r4, #4]
	ldrb r5, [r4, #0xa]
	cmp r0, r5
	blo _0805E1EC
	ldr r0, _0805E1DC @ =0x00001508
	adds r2, r7, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r3, r8
	movs r5, #0x1c
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r5, #4
	ldrsh r2, [r6, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r3, _0805E1E0 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0805E1E4 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0805E1E8 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0xf
	ands r1, r2
	adds r0, r0, r1
	subs r0, #8
	movs r1, #0
	strb r0, [r4]
	movs r0, #3
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	str r1, [r4, #4]
	b _0805E1F0
	.align 2, 0
_0805E1DC: .4byte 0x00001508
_0805E1E0: .4byte 0x030046B8
_0805E1E4: .4byte 0x000003FF
_0805E1E8: .4byte 0x0203B400
_0805E1EC:
	adds r0, #1
	str r0, [r4, #4]
_0805E1F0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805e1fc
FUN_0805e1fc: @ 0x0805E1FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r5, r1, #0
	mov sb, r2
	adds r7, r5, #0
	adds r7, #0xc4
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0805E284
	movs r0, #0
	strb r0, [r5, #3]
	adds r2, r5, #0
	adds r2, #0x64
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805dff0
	adds r3, r5, #0
	adds r3, #0xc
	ldrb r4, [r5]
	ldrb r6, [r5, #1]
	ldr r2, _0805E254 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805E258
	asrs r1, r0, #0xc
	b _0805E25E
	.align 2, 0
_0805E254: .4byte 0x085B0A08
_0805E258:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E25E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805E278 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805E27C
	asrs r0, r0, #0xc
	b _0805E282
	.align 2, 0
_0805E278: .4byte 0x085B0A08
_0805E27C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E282:
	strh r0, [r3, #4]
_0805E284:
	adds r6, r7, #0
	adds r6, #0x1c
	adds r1, r5, #0
	adds r1, #0xc
	ldrh r0, [r5, #0xc]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r0, #0x64
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	movs r0, #1
	mov r2, sb
	ands r0, r2
	ldr r1, _0805E2E8 @ =0x000014E7
	add r1, r8
	ldrb r1, [r1]
	cmp r0, r1
	bne _0805E2D4
	adds r4, r5, #0
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_0805E2D4:
	ldr r0, [r5, #4]
	cmp r0, #0x77
	bls _0805E2EC
	mov r0, r8
	adds r1, r5, #0
	mov r2, sb
	bl FUN_0805dfb8
	b _0805E2F0
	.align 2, 0
_0805E2E8: .4byte 0x000014E7
_0805E2EC:
	adds r0, #1
	str r0, [r5, #4]
_0805E2F0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805e2fc
FUN_0805e2fc: @ 0x0805E2FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	adds r7, r4, #0
	adds r7, #0xc4
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E344
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r0, r4, #0
	adds r0, #0xf0
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetAuxSpritePltt
	mov r0, r8
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0805dff0
	bl FUN_0821bd3c
	movs r0, #0xe8
	bl PlaySound_082406e0
_0805E344:
	ldr r1, [r4, #4]
	movs r0, #0x14
	subs r0, r0, r1
	adds r3, r4, #0
	adds r3, #0xc
	ldrb r5, [r4]
	lsls r6, r0, #1
	ldr r2, _0805E370 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	mov ip, r3
	cmp r0, #0
	blt _0805E374
	asrs r1, r0, #0xc
	b _0805E37A
	.align 2, 0
_0805E370: .4byte 0x085B0A08
_0805E374:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E37A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805E392
	asrs r0, r0, #0xc
	b _0805E398
_0805E392:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E398:
	strh r0, [r3, #4]
	adds r1, r7, #0
	adds r1, #0x1c
	ldrh r0, [r4, #0xc]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	mov r2, ip
	ldrh r0, [r2, #2]
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	strh r0, [r1, #2]
	mov r2, ip
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	ldr r0, [r4, #4]
	cmp r0, #0x13
	bls _0805E3CC
	mov r0, r8
	adds r1, r4, #0
	mov r2, sb
	bl FUN_0805dfb8
	b _0805E408
_0805E3CC:
	cmp r0, #6
	bne _0805E3DA
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, _0805E3F4 @ =0x00000263
	bl Video_SetAuxSpritePltt
_0805E3DA:
	ldr r0, [r4, #4]
	lsrs r0, r0, #2
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0805E3F8
	adds r0, r4, #0
	adds r0, #0xc4
	ldr r1, [r0]
	subs r2, #3
	ands r1, r2
	str r1, [r0]
	b _0805E402
	.align 2, 0
_0805E3F4: .4byte 0x00000263
_0805E3F8:
	adds r1, r4, #0
	adds r1, #0xc4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0805E402:
	ldr r0, [r4, #4]
	adds r0, #1
	str r0, [r4, #4]
_0805E408:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start Entity0805e67c_Update
Entity0805e67c_Update: @ 0x0805E414
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, [r7, #0x18]
	cmp r0, #0
	bne _0805E42A
	b _0805E602
_0805E42A:
	ldr r0, _0805E48C @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0805E43E
	ldr r1, _0805E490 @ =0x00001508
	adds r2, r7, r1
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
_0805E43E:
	ldr r2, _0805E494 @ =0x000014E4
	adds r6, r7, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805E4C4
	ldr r0, _0805E498 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805E49C @ =0x00004C60
	adds r1, r2, r3
	ldr r4, _0805E4A0 @ =0x00004CE0
	adds r2, r2, r4
	ldr r3, _0805E4A4 @ =0x000014E8
	adds r0, r7, r3
	ldr r4, _0805E4A8 @ =0x000014E5
	adds r5, r7, r4
	movs r3, #0
	ldrsb r3, [r5, r3]
	movs r4, #5
	str r4, [sp]
	bl BlendPltt
	ldr r0, _0805E4AC @ =0x000014E6
	adds r2, r7, r0
	ldrb r0, [r2]
	cmp r0, #0
	bne _0805E4B0
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1e
	ble _0805E4C4
	movs r0, #0x1f
	strb r0, [r5]
	movs r0, #1
	strb r0, [r2]
	b _0805E4C4
	.align 2, 0
_0805E48C: .4byte 0x03002BE0
_0805E490: .4byte 0x00001508
_0805E494: .4byte 0x000014E4
_0805E498: .4byte 0x03003584
_0805E49C: .4byte 0x00004C60
_0805E4A0: .4byte 0x00004CE0
_0805E4A4: .4byte 0x000014E8
_0805E4A8: .4byte 0x000014E5
_0805E4AC: .4byte 0x000014E6
_0805E4B0:
	ldrb r0, [r5]
	subs r0, #1
	movs r1, #0
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0805E4C4
	strb r1, [r5]
	strb r1, [r2]
	strb r1, [r6]
_0805E4C4:
	ldr r0, [r7, #0x1c]
	movs r1, #1
	ands r0, r1
	ldr r2, _0805E53C @ =0x000014E7
	adds r1, r7, r2
	strb r0, [r1]
	movs r3, #0x24
	adds r3, r3, r7
	mov r8, r3
	movs r4, #0
	mov sb, r4
	movs r0, #1
	mov sl, r0
	adds r6, r7, #0
	adds r6, #0xd8
_0805E4E2:
	mov r1, sl
	mov r2, sb
	lsls r1, r2
	ldr r0, [r7, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805E5E8
	ldr r1, _0805E540 @ =0x085ABA5C
	mov r3, r8
	movs r0, #2
	ldrsb r0, [r3, r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r3, [r0]
	adds r0, r7, #0
	mov r1, r8
	bl _call_via_r3
	mov r5, r8
	adds r5, #0xc4
	adds r3, r6, #0
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r4, r1, r0
	ldrh r0, [r4]
	lsrs r0, r0, #6
	strh r0, [r6, #0x20]
	ldrb r0, [r6, #4]
	mov r2, sl
	ands r2, r0
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r1, sl
	ands r0, r1
	cmp r2, r0
	beq _0805E544
	ldr r0, [r6, #0x10]
	movs r1, #4
	orrs r0, r1
	str r0, [r6, #0x10]
	b _0805E54E
	.align 2, 0
_0805E53C: .4byte 0x000014E7
_0805E540: .4byte 0x085ABA5C
_0805E544:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
_0805E54E:
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
	beq _0805E570
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0805E578
_0805E570:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805E578:
	str r0, [r5]
	ldrh r0, [r3, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r3, #0xe]
	ldr r4, _0805E5B0 @ =0x0000FFFF
	adds r2, r4, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r4, [r3, #7]
	cmp r0, r4
	blo _0805E5E8
	strh r1, [r3, #0xe]
	ldrb r1, [r3, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805E5B4
	ldrh r0, [r3, #8]
	cmp r0, #0
	bne _0805E5A8
	ldrb r0, [r3, #5]
_0805E5A8:
	subs r0, #1
	strh r0, [r3, #8]
	b _0805E5C4
	.align 2, 0
_0805E5B0: .4byte 0x0000FFFF
_0805E5B4:
	ldrh r0, [r3, #8]
	adds r0, #1
	strh r0, [r3, #8]
	ands r0, r2
	ldrb r2, [r3, #5]
	cmp r0, r2
	blo _0805E5C4
	strh r1, [r3, #8]
_0805E5C4:
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
	bne _0805E5E8
	mov r4, sl
	strb r4, [r3, #7]
_0805E5E8:
	movs r0, #1
	add sb, r0
	movs r1, #0xa6
	lsls r1, r1, #1
	adds r6, r6, r1
	add r8, r1
	mov r2, sb
	cmp r2, #0xf
	bgt _0805E5FC
	b _0805E4E2
_0805E5FC:
	ldr r0, [r7, #0x1c]
	adds r0, #1
	str r0, [r7, #0x1c]
_0805E602:
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity0805e67c_Destroy
Entity0805e67c_Destroy: @ 0x0805E614
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805E61E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805df94
	adds r4, #1
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805E61E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity0805e67c_Init
Entity0805e67c_Init: @ 0x0805E63C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	ldr r0, _0805E674 @ =0x0000922E
	ldr r1, _0805E678 @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x20]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_0805E654:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805de2c
	adds r4, #1
	movs r0, #0xa6
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805E654
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805E674: .4byte 0x0000922E
_0805E678: .4byte 0x00005BB7

	thumb_func_start Entity0805e67c_Create
Entity0805e67c_Create: @ 0x0805E67C
	push {r4, lr}
	ldr r1, _0805E6A8 @ =0x00001510
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805E6B4
	ldr r1, _0805E6AC @ =Entity0805e67c_Update
	ldr r2, _0805E6B0 @ =Entity0805e67c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity0805e67c_Init
	cmp r0, #0
	bge _0805E6B4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805E6B6
	.align 2, 0
_0805E6A8: .4byte 0x00001510
_0805E6AC: .4byte Entity0805e67c_Update
_0805E6B0: .4byte Entity0805e67c_Destroy
_0805E6B4:
	adds r0, r4, #0
_0805E6B6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805e6bc
FUN_0805e6bc: @ 0x0805E6BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	mov ip, r1
	mov sl, r3
	mov r4, sb
	adds r4, #0x24
	movs r0, #0
	movs r1, #1
	mov r6, sb
	adds r6, #0x88
	movs r7, #0x82
	lsls r7, r7, #1
	add r7, sb
_0805E6E0:
	mov r8, r1
	mov r3, r8
	lsls r3, r0
	mov r8, r3
	mov r3, sb
	ldr r5, [r3, #0x18]
	mov r3, r8
	ands r5, r3
	cmp r5, #0
	bne _0805E778
	movs r0, #3
	strb r0, [r4, #2]
	strb r1, [r4, #3]
	str r5, [r4, #4]
	strb r2, [r4]
	mov r0, sl
	strb r0, [r4, #1]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7]
	str r1, [r7, #4]
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, _0805E774 @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r0, [r6, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x60]
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805dff0
	movs r3, #0x86
	lsls r3, r3, #1
	adds r0, r4, r3
	bl ParticleShadow_Show
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	str r5, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x28]
	ldr r2, [sp, #0x2c]
	movs r3, #0x80
	lsls r3, r3, #5
	bl Hitbox_SetAttack
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r6, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r6, #6]
	mov r1, sb
	ldr r0, [r1, #0x18]
	mov r2, r8
	orrs r0, r2
	str r0, [r1, #0x18]
	b _0805E788
	.align 2, 0
_0805E774: .4byte 0x00000263
_0805E778:
	adds r0, #1
	movs r3, #0xa6
	lsls r3, r3, #1
	adds r6, r6, r3
	adds r7, r7, r3
	adds r4, r4, r3
	cmp r0, #0xf
	ble _0805E6E0
_0805E788:
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805e79c
FUN_0805e79c: @ 0x0805E79C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	str r1, [sp, #0x10]
	str r3, [sp, #0x14]
	adds r0, r2, #0
	subs r0, #0x60
	str r0, [sp, #8]
	adds r2, #0x60
	str r2, [sp, #0xc]
	mov r6, r8
	adds r6, #0x24
	movs r0, #0
	str r0, [sp, #0x18]
	movs r1, #0xe8
	add r1, r8
	mov sb, r1
_0805E7C6:
	movs r2, #1
	mov sl, r2
	mov r0, sl
	ldr r1, [sp, #0x18]
	lsls r0, r1
	mov sl, r0
	mov r2, r8
	ldr r7, [r2, #0x18]
	ands r7, r0
	cmp r7, #0
	bne _0805E8BA
	movs r0, #1
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	str r7, [r6, #4]
	ldr r2, _0805E918 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0805E91C @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _0805E920 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #4
	strb r0, [r6, #8]
	movs r0, #0x14
	strb r0, [r6, #9]
	ldr r2, [sp, #0x18]
	lsls r0, r2, #3
	adds r0, #0xf
	strb r0, [r6, #0xa]
	adds r1, #1
	ldr r0, _0805E91C @ =0x000003FF
	ands r1, r0
	ldr r2, _0805E918 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0805E920 @ =0x0203B400
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, #0x18]
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	adds r0, #8
	ldr r1, [r0]
	movs r0, #0x3f
	ands r2, r0
	adds r1, r1, r2
	subs r1, #0x20
	strb r1, [r6]
	mov r2, sp
	ldrb r2, [r2, #0x14]
	strb r2, [r6, #1]
	adds r5, r6, #0
	adds r5, #0xe0
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805dff0
	adds r0, r6, #0
	adds r0, #0xf0
	ldr r1, _0805E924 @ =0x00000267
	bl Video_SetAuxSpritePltt
	ldr r0, _0805E928 @ =0x000014E8
	add r0, r8
	mov r1, sb
	str r0, [r1, #0x38]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r6, r2
	bl ParticleShadow_Show
	adds r4, r6, #0
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	str r7, [sp]
	ldr r0, [sp, #0x44]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	movs r3, #0x80
	lsls r3, r3, #5
	bl Hitbox_SetAttack
	adds r4, #0x50
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	mov r1, r8
	ldr r0, [r1, #0x18]
	mov r2, sl
	orrs r0, r2
	str r0, [r1, #0x18]
_0805E8BA:
	ldr r0, [sp, #0x18]
	adds r0, #1
	str r0, [sp, #0x18]
	movs r1, #0xa6
	lsls r1, r1, #1
	add sb, r1
	adds r6, r6, r1
	cmp r0, #0xf
	bgt _0805E8CE
	b _0805E7C6
_0805E8CE:
	ldr r1, _0805E92C @ =0x000014E4
	add r1, r8
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0805E930 @ =0x000014E5
	add r3, r8
	movs r0, #0x14
	strb r0, [r3]
	ldr r0, _0805E934 @ =0x000014E6
	add r0, r8
	strb r2, [r0]
	ldr r0, _0805E938 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805E93C @ =0x00004C60
	adds r1, r2, r0
	adds r0, #0x80
	adds r2, r2, r0
	ldr r0, _0805E928 @ =0x000014E8
	add r0, r8
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #5
	str r4, [sp]
	bl BlendPltt
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805E918: .4byte 0x030046B8
_0805E91C: .4byte 0x000003FF
_0805E920: .4byte 0x0203B400
_0805E924: .4byte 0x00000267
_0805E928: .4byte 0x000014E8
_0805E92C: .4byte 0x000014E4
_0805E930: .4byte 0x000014E5
_0805E934: .4byte 0x000014E6
_0805E938: .4byte 0x03003584
_0805E93C: .4byte 0x00004C60

	thumb_func_start FUN_0805e940
FUN_0805e940: @ 0x0805E940
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	mov r8, r0
	str r1, [sp, #0x10]
	str r3, [sp, #0x14]
	adds r0, r2, #0
	subs r0, #0x60
	str r0, [sp, #8]
	adds r2, #0x60
	str r2, [sp, #0xc]
	mov r6, r8
	adds r6, #0x24
	movs r0, #0
	str r0, [sp, #0x18]
	ldr r1, [sp, #0x48]
	cmp r0, r1
	blt _0805E96C
	b _0805EA7C
_0805E96C:
	movs r2, #0xe8
	add r2, r8
	mov sb, r2
_0805E972:
	movs r0, #1
	mov sl, r0
	mov r1, sl
	ldr r2, [sp, #0x18]
	lsls r1, r2
	mov sl, r1
	mov r0, r8
	ldr r7, [r0, #0x18]
	ands r7, r1
	cmp r7, #0
	bne _0805EA66
	movs r1, #1
	strb r1, [r6, #2]
	strb r1, [r6, #3]
	str r7, [r6, #4]
	ldr r2, _0805EAC4 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _0805EAC8 @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _0805EACC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0x1f
	ands r0, r2
	adds r0, #4
	strb r0, [r6, #8]
	movs r0, #0x14
	strb r0, [r6, #9]
	ldr r2, [sp, #0x18]
	lsls r0, r2, #3
	adds r0, #0xf
	strb r0, [r6, #0xa]
	adds r1, #1
	ldr r0, _0805EAC8 @ =0x000003FF
	ands r1, r0
	ldr r2, _0805EAC4 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _0805EACC @ =0x0203B400
	adds r1, r1, r0
	ldrh r2, [r1]
	ldr r0, [sp, #0x18]
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #2
	add r0, sp
	adds r0, #8
	ldr r1, [r0]
	movs r0, #0x3f
	ands r2, r0
	adds r1, r1, r2
	subs r1, #0x20
	strb r1, [r6]
	mov r2, sp
	ldrb r2, [r2, #0x14]
	strb r2, [r6, #1]
	adds r5, r6, #0
	adds r5, #0xe0
	ldr r2, [sp, #0x10]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	mov r0, r8
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805dff0
	adds r0, r6, #0
	adds r0, #0xf0
	ldr r1, _0805EAD0 @ =0x00000267
	bl Video_SetAuxSpritePltt
	ldr r0, _0805EAD4 @ =0x000014E8
	add r0, r8
	mov r1, sb
	str r0, [r1, #0x38]
	movs r2, #0x86
	lsls r2, r2, #1
	adds r0, r6, r2
	bl ParticleShadow_Show
	adds r4, r6, #0
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	str r7, [sp]
	ldr r0, [sp, #0x44]
	str r0, [sp, #4]
	adds r0, r4, #0
	ldr r1, [sp, #0x3c]
	ldr r2, [sp, #0x40]
	movs r3, #0x80
	lsls r3, r3, #5
	bl Hitbox_SetAttack
	adds r4, #0x50
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r4, #6]
	mov r1, r8
	ldr r0, [r1, #0x18]
	mov r2, sl
	orrs r0, r2
	str r0, [r1, #0x18]
_0805EA66:
	ldr r0, [sp, #0x18]
	adds r0, #1
	str r0, [sp, #0x18]
	movs r1, #0xa6
	lsls r1, r1, #1
	add sb, r1
	adds r6, r6, r1
	ldr r2, [sp, #0x48]
	cmp r0, r2
	bge _0805EA7C
	b _0805E972
_0805EA7C:
	ldr r1, _0805EAD8 @ =0x000014E4
	add r1, r8
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r3, _0805EADC @ =0x000014E5
	add r3, r8
	movs r0, #0x14
	strb r0, [r3]
	ldr r0, _0805EAE0 @ =0x000014E6
	add r0, r8
	strb r2, [r0]
	ldr r0, _0805EAE4 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805EAE8 @ =0x00004C60
	adds r1, r2, r0
	adds r0, #0x80
	adds r2, r2, r0
	ldr r0, _0805EAD4 @ =0x000014E8
	add r0, r8
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #5
	str r4, [sp]
	bl BlendPltt
	movs r0, #0
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805EAC4: .4byte 0x030046B8
_0805EAC8: .4byte 0x000003FF
_0805EACC: .4byte 0x0203B400
_0805EAD0: .4byte 0x00000267
_0805EAD4: .4byte 0x000014E8
_0805EAD8: .4byte 0x000014E4
_0805EADC: .4byte 0x000014E5
_0805EAE0: .4byte 0x000014E6
_0805EAE4: .4byte 0x03003584
_0805EAE8: .4byte 0x00004C60
