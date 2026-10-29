	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805b894
FUN_0805b894: @ 0x0805B894
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	movs r1, #0x80
	lsls r1, r1, #1
	ldrh r0, [r5, #6]
	ands r0, r1
	cmp r0, #0
	beq _0805B8B6
	adds r0, r5, #0
	adds r0, #0x42
	ldrb r0, [r0]
	b _0805B8CE
_0805B8B6:
	movs r1, #0x24
	ldrsh r0, [r6, r1]
	movs r2, #0x24
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #0x28
	ldrsh r1, [r6, r3]
	movs r3, #0x28
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
_0805B8CE:
	strb r0, [r4, #6]
	movs r0, #0
	mov r8, r0
	movs r0, #8
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _0805B8E4
	movs r0, #0xfa
	strb r0, [r4, #9]
	mov r1, r8
	strb r1, [r4, #8]
_0805B8E4:
	adds r0, r5, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamage
	ldr r3, _0805B93C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805B940 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r6, #0x3e]
	adds r3, r4, #0
	adds r3, #0x14
	add r2, sp, #8
	str r2, [sp]
	movs r7, #1
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r2, #0
	bl CreateDamageNumber
	ldrh r0, [r5, #0x3e]
	adds r0, #2
	strh r0, [r5, #0x3e]
	ldrh r0, [r6, #0x3e]
	bl FUN_08029864
	bl FUN_08084710
	adds r1, r0, #0
	cmp r1, #0
	beq _0805B944
	movs r0, #6
	strb r0, [r4, #1]
	strb r7, [r4]
	mov r3, r8
	strh r3, [r4, #4]
	b _0805B94C
	.align 2, 0
_0805B93C: .4byte 0xFFFF0000
_0805B940: .4byte 0x0000FFFF
_0805B944:
	movs r0, #8
	strb r0, [r4, #1]
	strb r7, [r4]
	strh r1, [r4, #4]
_0805B94C:
	movs r0, #0x84
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805b960
FUN_0805b960: @ 0x0805B960
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r6, r0, #0
	adds r5, r1, #0
	adds r4, r2, #0
	bl Hitbox_ApplyDamage
	ldr r3, _0805B9AC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r3
	movs r2, #0x10
	orrs r0, r2
	ldr r1, _0805B9B0 @ =0x0000FFFF
	ands r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r3
	orrs r0, r2
	str r0, [sp, #0xc]
	ldrh r1, [r5, #0x3e]
	adds r4, #0x14
	add r0, sp, #8
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r2, #1
	adds r3, r4, #0
	bl CreateDamageNumber
	ldrh r0, [r5, #0x3e]
	bl FUN_080298b8
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805B9AC: .4byte 0xFFFF0000
_0805B9B0: .4byte 0x0000FFFF

	thumb_func_start FUN_0805b9b4
FUN_0805b9b4: @ 0x0805B9B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	mov r8, r0
	mov sl, r1
	movs r1, #0
	mov r0, sl
	strb r1, [r0, #1]
	movs r0, #1
	mov r2, sl
	strb r0, [r2]
	strh r1, [r2, #4]
	strb r1, [r2, #6]
	movs r4, #0x84
	lsls r4, r4, #1
	add r4, sl
	ldr r1, _0805BB08 @ =0x0000DA6D
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	ldr r1, _0805BB0C @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r0, _0805BB10 @ =0x00001688
	add r0, r8
	str r0, [r4, #0xc]
	mov r5, sl
	adds r5, #0xdc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #1
	bl AuxSprite_Add
	movs r0, #2
	strb r0, [r5, #7]
	adds r5, #0x1c
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r5, #0
	ldr r2, _0805BB14 @ =0x05000002
	bl CpuSet
	movs r4, #0x92
	lsls r4, r4, #1
	add r4, sl
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r4, #0
	bl ParticleShadow_Hide
	mov r7, sl
	adds r7, #0x7c
	ldr r2, _0805BB18 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r1, #0x20
	orrs r0, r1
	ldr r1, _0805BB1C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xf0
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x10]
	add r5, sp, #0x10
	ldr r0, [r5, #4]
	ands r0, r2
	movs r1, #0x20
	orrs r0, r1
	str r0, [r5, #4]
	movs r0, #0xf0
	lsls r0, r0, #0xf
	str r0, [sp, #0x18]
	add r4, sp, #0x18
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldr r2, _0805BB20 @ =0x00004005
	movs r0, #0x10
	mov sb, r0
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	mov r6, sl
	adds r6, #0x14
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805BB24 @ =FUN_0805b894
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	mov r2, r8
	ldrh r1, [r2, #0x22]
	adds r0, r7, #0
	movs r2, #0x80
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	adds r0, r7, #0
	bl Hitbox_Register
	subs r7, #0x50
	movs r0, #0x20
	strh r0, [r5]
	movs r0, #0xf0
	strh r0, [r5, #2]
	movs r1, #0x20
	strh r1, [r5, #4]
	movs r2, #0
	strh r2, [r4]
	movs r0, #0x78
	strh r0, [r4, #2]
	strh r2, [r4, #4]
	ldr r2, _0805BB28 @ =0x00002001
	mov r0, sb
	str r0, [sp]
	str r5, [sp, #4]
	str r4, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0805BB2C @ =FUN_0805b960
	adds r0, r7, #0
	mov r2, sl
	bl Hitbox_SetHandler
	mov r2, r8
	ldrh r1, [r2, #0x20]
	movs r3, #0x80
	lsls r3, r3, #5
	movs r0, #0
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r7, #0
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
_0805BB08: .4byte 0x0000DA6D
_0805BB0C: .4byte 0x00000263
_0805BB10: .4byte 0x00001688
_0805BB14: .4byte 0x05000002
_0805BB18: .4byte 0xFFFF0000
_0805BB1C: .4byte 0x0000FFFF
_0805BB20: .4byte 0x00004005
_0805BB24: .4byte FUN_0805b894
_0805BB28: .4byte 0x00002001
_0805BB2C: .4byte FUN_0805b960

	thumb_func_start FUN_0805bb30
FUN_0805bb30: @ 0x0805BB30
	push {r4, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	adds r0, #0x7c
	bl Hitbox_Unregister
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r4, r1
	bl ParticleShadow_Remove
	adds r0, r4, #0
	adds r0, #0xdc
	bl AuxSprite_Remove
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805bb54
FUN_0805bb54: @ 0x0805BB54
	push {lr}
	adds r3, r1, #0
	adds r2, r3, #0
	adds r2, #0xdc
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	subs r2, #0x60
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x92
	lsls r1, r1, #1
	adds r0, r3, r1
	bl ParticleShadow_Hide
	pop {r1}
	bx r1

	thumb_func_start FUN_0805bb7c
FUN_0805bb7c: @ 0x0805BB7C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_0805BB86:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805bb54
	adds r4, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805BB86
	adds r0, r6, #0
	adds r0, #0x38
	bl FUN_080297fc
	movs r0, #0
	str r0, [r6, #0x18]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bbb0
FUN_0805bbb0: @ 0x0805BBB0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5, #6]
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
	bhi _0805BBDE
	movs r0, #1
	b _0805BBE0
_0805BBDE:
	movs r0, #0
_0805BBE0:
	strb r0, [r4]
	cmp r1, #1
	bls _0805BBEA
	movs r0, #1
	b _0805BBEC
_0805BBEA:
	movs r0, #0
_0805BBEC:
	strb r0, [r3]
	adds r0, r5, #0
	adds r0, #0xcc
	ldr r1, [r6, #0x40]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r3, sp, #4
	ldrb r3, [r3]
	ldrb r4, [r7]
	str r4, [sp]
	bl AuxAnim_SetAnim
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805bc0c
FUN_0805bc0c: @ 0x0805BC0C
	push {r4, r5, r6, lr}
	mov ip, r0
	mov r6, ip
	adds r6, #0xdc
	mov r2, ip
	adds r2, #0xf8
	mov r3, ip
	ldr r0, [r3, #0x14]
	ldr r1, [r3, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
	mov r4, ip
	adds r4, #0xcc
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
	beq _0805BC52
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _0805BC5A
_0805BC52:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0805BC5A:
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
	beq _0805BC7E
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _0805BC86
_0805BC7E:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0805BC86:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _0805BCC0 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0805BD06
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0805BCCA
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0805BCC4
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _0805BCE0
	.align 2, 0
_0805BCC0: .4byte 0x0000FFFF
_0805BCC4:
	subs r0, #1
	strh r0, [r4, #8]
	b _0805BCDE
_0805BCCA:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0805BCDE
	strh r1, [r4, #8]
	movs r2, #1
	b _0805BCE0
_0805BCDE:
	movs r2, #0
_0805BCE0:
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
	bne _0805BD08
	movs r0, #1
	strb r0, [r4, #7]
	b _0805BD08
_0805BD06:
	movs r2, #0
_0805BD08:
	mov r3, ip
	strb r2, [r3, #2]
	ldrb r0, [r3, #1]
	cmp r0, #7
	beq _0805BD58
	movs r0, #0x16
	ldrsh r1, [r3, r0]
	ldrh r0, [r3, #0xe]
	cmp r1, r0
	ble _0805BD24
	ldrh r0, [r3, #0x16]
	subs r0, #1
	strh r0, [r3, #0x16]
	b _0805BD30
_0805BD24:
	cmp r1, r0
	bge _0805BD30
	mov r1, ip
	ldrh r0, [r1, #0x16]
	adds r0, #1
	strh r0, [r1, #0x16]
_0805BD30:
	ldr r0, _0805BD48 @ =gSineTable
	mov r2, ip
	ldrb r1, [r2, #3]
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0805BD4C
	asrs r1, r0, #0xc
	b _0805BD52
	.align 2, 0
_0805BD48: .4byte gSineTable
_0805BD4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805BD52:
	ldrh r0, [r6, #0x1e]
	adds r0, r0, r1
	strh r0, [r6, #0x1e]
_0805BD58:
	mov r1, ip
	ldrb r0, [r1, #3]
	adds r0, #4
	strb r0, [r1, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bd68
FUN_0805bd68: @ 0x0805BD68
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805BD80
	movs r0, #0
	strb r0, [r4]
_0805BD80:
	ldrh r0, [r4, #0x10]
	mov r3, sp
	ldrb r5, [r4, #6]
	lsls r6, r0, #1
	ldr r2, _0805BDA4 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805BDA8
	asrs r1, r0, #0xc
	b _0805BDAE
	.align 2, 0
_0805BDA4: .4byte gSineTable
_0805BDA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805BDAE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805BDC6
	asrs r0, r0, #0xc
	b _0805BDCC
_0805BDC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805BDCC:
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r1, [r4, #4]
	mov r0, r8
	adds r0, #2
	cmp r1, r0
	blt _0805BE16
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #4]
_0805BE16:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805be28
FUN_0805be28: @ 0x0805BE28
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r4, r1, #0
	mov sb, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805BE58
	movs r0, #0
	strb r0, [r4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r1, #5
	rsbs r1, r1, #0
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
	adds r1, r4, #0
	adds r1, #0x14
	movs r2, #0
	bl Hitbox_SetPos
_0805BE58:
	mov r0, r8
	ldrb r1, [r0, #0x1c]
	cmp r1, #0
	beq _0805BE66
	movs r0, #5
	movs r1, #0
	b _0805BE70
_0805BE66:
	mov r2, r8
	ldrb r0, [r2, #0x1e]
	cmp r0, #0
	beq _0805BE7A
	movs r0, #9
_0805BE70:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805BF52
_0805BE7A:
	movs r0, #8
	ldrsb r0, [r4, r0]
	adds r5, r4, #0
	adds r5, #0x14
	cmp r0, #0
	blt _0805BEF4
	ldrh r0, [r4, #4]
	movs r3, #7
	ands r3, r0
	movs r6, #8
	ldrsb r6, [r4, r6]
	movs r7, #0x28
	add r7, r8
	mov ip, r7
	cmp r3, #0
	bne _0805BED4
	lsls r0, r6, #2
	add r0, ip
	ldr r1, [r0]
	movs r0, #0
	ldrsh r2, [r1, r0]
	movs r7, #0x14
	ldrsh r0, [r4, r7]
	subs r2, r2, r0
	movs r7, #4
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r5, r7]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0805BED0 @ =0x00022E24
	cmp r1, r0
	ble _0805BED4
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r3, [r4, #4]
	b _0805BF52
	.align 2, 0
_0805BED0: .4byte 0x00022E24
_0805BED4:
	lsls r0, r6, #2
	add r0, ip
	ldr r2, [r0]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r7, #0x14
	ldrsh r1, [r4, r7]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r7, #4
	ldrsh r2, [r5, r7]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
_0805BEF4:
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, r8
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #0x3f
	bls _0805BF1C
	movs r0, #4
	movs r1, #0
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
_0805BF1C:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0805BF4C
	subs r0, #1
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	bne _0805BF4C
	mov r2, r8
	ldrb r0, [r2, #0x1f]
	cmp r0, #2
	bne _0805BF44
	mov r3, sb
	cmp r3, #7
	bgt _0805BF40
	movs r0, #1
	b _0805BF4A
_0805BF40:
	strb r1, [r4, #8]
	b _0805BF4C
_0805BF44:
	cmp r0, #0
	beq _0805BF4A
	movs r0, #0xff
_0805BF4A:
	strb r0, [r4, #8]
_0805BF4C:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805BF52:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805bf60
FUN_0805bf60: @ 0x0805BF60
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	adds r5, r1, #0
	mov sl, r2
	ldrb r0, [r5]
	cmp r0, #0
	bne _0805BF7A
	b _0805C084
_0805BF7A:
	movs r0, #0
	strb r0, [r5]
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r7, r5, #0
	adds r7, #0x1c
	cmp r0, #0
	blt _0805C026
	ldr r2, _0805BFBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805BFC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805BFC4 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r4, sp
	ldrb r6, [r0]
	ldr r1, _0805BFC8 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805BFCC
	asrs r3, r0, #0xc
	b _0805BFD2
	.align 2, 0
_0805BFBC: .4byte 0x030046B8
_0805BFC0: .4byte 0x000003FF
_0805BFC4: .4byte 0x0203B400
_0805BFC8: .4byte gSineTable
_0805BFCC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805BFD2:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805BFEE
	asrs r0, r0, #0xc
	b _0805BFF4
_0805BFEE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805BFF4:
	strh r0, [r4, #4]
	movs r0, #8
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	mov r1, sb
	adds r1, #0x28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x1c
	ldr r1, [r1]
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r5, #0x1c]
	ldrh r0, [r3, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r7, r2, #0
_0805C026:
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r4, #0x18
	ldrsh r2, [r5, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #6]
	ldr r4, _0805C094 @ =0x0203B400
	ldr r2, _0805C098 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C09C @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x20
	ldrb r1, [r5, #6]
	adds r0, r0, r1
	strb r0, [r5, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r5, #7]
	adds r2, r5, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C084:
	mov r2, sb
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	beq _0805C0A0
	movs r0, #5
	movs r1, #0
	b _0805C0AA
	.align 2, 0
_0805C094: .4byte 0x0203B400
_0805C098: .4byte 0x030046B8
_0805C09C: .4byte 0x000003FF
_0805C0A0:
	mov r3, sb
	ldrb r0, [r3, #0x1e]
	cmp r0, #0
	beq _0805C0B4
	movs r0, #9
_0805C0AA:
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	strh r1, [r5, #4]
	b _0805C320
_0805C0B4:
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _0805C0BC
	b _0805C210
_0805C0BC:
	ldr r6, _0805C110 @ =0x0203B400
	ldr r2, _0805C114 @ =0x030046B8
	ldr r0, [r2]
	adds r1, r0, #1
	ldr r3, _0805C118 @ =0x000003FF
	ands r1, r3
	str r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r6
	movs r4, #0xff
	ldrb r0, [r0]
	cmp r0, #0xbf
	ble _0805C0D8
	b _0805C1CC
_0805C0D8:
	movs r0, #8
	ldrsb r0, [r5, r0]
	adds r7, r5, #0
	adds r7, #0x1c
	cmp r0, #0
	blt _0805C180
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	mov r3, sp
	ands r2, r4
	ldr r1, _0805C11C @ =gSineTable
	adds r0, r2, #0
	adds r0, #0x40
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r0, [r0, r4]
	lsls r0, r0, #8
	cmp r0, #0
	blt _0805C120
	asrs r1, r0, #0xc
	b _0805C126
	.align 2, 0
_0805C110: .4byte 0x0203B400
_0805C114: .4byte 0x030046B8
_0805C118: .4byte 0x000003FF
_0805C11C: .4byte gSineTable
_0805C120:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C126:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805C144 @ =gSineTable
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C148
	asrs r0, r0, #0xc
	b _0805C14E
	.align 2, 0
_0805C144: .4byte gSineTable
_0805C148:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C14E:
	strh r0, [r3, #4]
	movs r0, #8
	ldrsb r0, [r5, r0]
	lsls r0, r0, #2
	mov r1, sb
	adds r1, #0x28
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0x1c
	ldr r1, [r1]
	mov r3, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r5, #0x1c]
	ldrh r0, [r3, #2]
	ldrh r4, [r1, #2]
	adds r0, r0, r4
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r2, #4]
	adds r7, r2, #0
_0805C180:
	adds r4, r5, #0
	adds r4, #0x14
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x14
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r3, #4
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r5, #6]
	ldr r2, _0805C1C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C1C4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C1C8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	subs r0, #0x20
	ldrb r2, [r5, #6]
	adds r0, r0, r2
	strb r0, [r5, #6]
	b _0805C1E4
	.align 2, 0
_0805C1C0: .4byte 0x030046B8
_0805C1C4: .4byte 0x000003FF
_0805C1C8: .4byte 0x0203B400
_0805C1CC:
	adds r0, r1, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805C204 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r5, #6]
	adds r7, r5, #0
	adds r7, #0x1c
	adds r4, r5, #0
	adds r4, #0x14
_0805C1E4:
	ldr r2, _0805C208 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C20C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C204 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r5, #7]
	b _0805C21C
	.align 2, 0
_0805C204: .4byte 0x0203B400
_0805C208: .4byte 0x030046B8
_0805C20C: .4byte 0x000003FF
_0805C210:
	subs r0, #1
	strb r0, [r5, #7]
	adds r7, r5, #0
	adds r7, #0x1c
	adds r4, r5, #0
	adds r4, #0x14
_0805C21C:
	mov r6, sp
	ldrb r2, [r5, #6]
	mov ip, r2
	ldrh r3, [r5, #0x10]
	mov r8, r3
	ldr r2, _0805C248 @ =gSineTable
	mov r0, ip
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	cmp r0, #0
	blt _0805C24C
	asrs r3, r0, #0xc
	b _0805C252
	.align 2, 0
_0805C248: .4byte gSineTable
_0805C24C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C252:
	movs r0, #0
	strh r3, [r6]
	strh r0, [r6, #2]
	mov r2, ip
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805C270
	asrs r0, r0, #0xc
	b _0805C276
_0805C270:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C276:
	movs r2, #0
	mov r8, r2
	strh r0, [r6, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r4, #4]
	adds r0, r0, r3
	strh r0, [r4, #4]
	adds r0, r5, #0
	adds r0, #0x7c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805bbb0
	movs r0, #0x1c
	ldrsh r2, [r5, r0]
	movs r1, #0x14
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r7, r3]
	movs r3, #4
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0805C2E0 @ =0x00003FFF
	cmp r1, r0
	bgt _0805C2E4
	movs r0, #2
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
	b _0805C31E
	.align 2, 0
_0805C2E0: .4byte 0x00003FFF
_0805C2E4:
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0805C31A
	subs r0, #1
	strb r0, [r5, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C31A
	mov r1, sb
	ldrb r0, [r1, #0x1f]
	cmp r0, #2
	bne _0805C30C
	mov r2, sl
	cmp r2, #7
	bgt _0805C306
	movs r0, #1
	b _0805C318
_0805C306:
	mov r3, r8
	strb r3, [r5, #8]
	b _0805C31A
_0805C30C:
	cmp r0, #0
	bne _0805C316
	mov r4, r8
	strb r4, [r5, #8]
	b _0805C31A
_0805C316:
	movs r0, #0xff
_0805C318:
	strb r0, [r5, #8]
_0805C31A:
	ldrh r0, [r5, #4]
	adds r0, #1
_0805C31E:
	strh r0, [r5, #4]
_0805C320:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c330
FUN_0805c330: @ 0x0805C330
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	mov r8, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805C382
	movs r0, #0
	strb r0, [r4]
	ldr r3, _0805C390 @ =0x0203B400
	ldr r1, _0805C394 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805C398 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r4, #7]
	adds r2, r4, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C382:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	beq _0805C39C
	movs r0, #5
	movs r1, #0
	b _0805C3A4
	.align 2, 0
_0805C390: .4byte 0x0203B400
_0805C394: .4byte 0x030046B8
_0805C398: .4byte 0x000003FF
_0805C39C:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _0805C3AE
	movs r0, #9
_0805C3A4:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805C4B8
_0805C3AE:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0805C3EC
	ldr r3, _0805C3E0 @ =0x0203B400
	ldr r1, _0805C3E4 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805C3E8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	b _0805C3EE
	.align 2, 0
_0805C3E0: .4byte 0x0203B400
_0805C3E4: .4byte 0x030046B8
_0805C3E8: .4byte 0x000003FF
_0805C3EC:
	subs r0, #1
_0805C3EE:
	strb r0, [r4, #7]
	mov r3, sp
	ldrb r5, [r4, #6]
	ldrh r6, [r4, #0x10]
	ldr r2, _0805C414 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805C418
	asrs r1, r0, #0xc
	b _0805C41E
	.align 2, 0
_0805C414: .4byte gSineTable
_0805C418:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C41E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805C436
	asrs r0, r0, #0xc
	b _0805C43C
_0805C436:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C43C:
	movs r5, #0
	strh r0, [r3, #4]
	adds r1, r4, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #0x1f
	bls _0805C486
	movs r0, #2
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805C4B6
_0805C486:
	ldrb r0, [r4, #9]
	cmp r0, #0
	beq _0805C4B2
	subs r0, #1
	strb r0, [r4, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C4B2
	ldrb r0, [r7, #0x1f]
	cmp r0, #2
	bne _0805C4A6
	mov r3, r8
	cmp r3, #7
	bgt _0805C4AA
	movs r0, #1
	b _0805C4B0
_0805C4A6:
	cmp r0, #0
	bne _0805C4AE
_0805C4AA:
	strb r5, [r4, #8]
	b _0805C4B2
_0805C4AE:
	movs r0, #0xff
_0805C4B0:
	strb r0, [r4, #8]
_0805C4B2:
	ldrh r0, [r4, #4]
	adds r0, #1
_0805C4B6:
	strh r0, [r4, #4]
_0805C4B8:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c4c4
FUN_0805c4c4: @ 0x0805C4C4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	mov sb, r2
	ldrb r0, [r6]
	cmp r0, #0
	beq _0805C524
	movs r0, #0
	strb r0, [r6]
	adds r2, r6, #0
	adds r2, #0x7c
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	adds r3, r6, #0
	adds r3, #0x14
	ldr r0, [r6, #0x14]
	ldr r1, [r6, #0x18]
	str r0, [r6, #0x24]
	str r1, [r6, #0x28]
	movs r0, #8
	ldrsb r0, [r6, r0]
	cmp r0, #0
	blt _0805C524
	adds r1, r0, #0
	lsls r1, r1, #2
	adds r0, r7, #0
	adds r0, #0x28
	adds r0, r0, r1
	ldr r2, [r0]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0x14
	ldrsh r1, [r6, r4]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r4, #4
	ldrsh r2, [r3, r4]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #6]
_0805C524:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	beq _0805C530
	movs r0, #5
	movs r1, #0
	b _0805C538
_0805C530:
	ldrb r0, [r7, #0x1e]
	cmp r0, #0
	beq _0805C542
	movs r0, #9
_0805C538:
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r1, [r6, #4]
	b _0805C636
_0805C542:
	ldrh r0, [r6, #4]
	cmp r0, #0xf
	bls _0805C54E
	ldrh r1, [r6, #4]
	movs r0, #0x20
	subs r0, r0, r1
_0805C54E:
	lsls r3, r0, #4
	mov r4, sp
	ldrb r5, [r6, #6]
	ldr r2, _0805C570 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0805C574
	asrs r1, r0, #0xc
	b _0805C57A
	.align 2, 0
_0805C570: .4byte gSineTable
_0805C574:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805C57A:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _0805C592
	asrs r0, r0, #0xc
	b _0805C598
_0805C592:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C598:
	movs r3, #0
	mov r8, r3
	strh r0, [r4, #4]
	adds r4, r6, #0
	adds r4, #0x14
	adds r2, r6, #0
	adds r2, #0x24
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r6, #0x24]
	adds r0, r0, r3
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r3, [r2, #2]
	adds r0, r0, r3
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x2c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	adds r0, #0x7c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	adds r0, r7, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r6, #4]
	cmp r0, #0x1f
	bls _0805C5FE
	movs r0, #2
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _0805C634
_0805C5FE:
	ldrb r0, [r6, #9]
	cmp r0, #0
	beq _0805C630
	subs r0, #1
	strb r0, [r6, #9]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0805C630
	ldrb r0, [r7, #0x1f]
	cmp r0, #2
	bne _0805C622
	mov r4, sb
	cmp r4, #7
	bgt _0805C61E
	movs r0, #1
	b _0805C62E
_0805C61E:
	mov r0, r8
	b _0805C62E
_0805C622:
	cmp r0, #0
	bne _0805C62C
	mov r1, r8
	strb r1, [r6, #8]
	b _0805C630
_0805C62C:
	movs r0, #0xff
_0805C62E:
	strb r0, [r6, #8]
_0805C630:
	ldrh r0, [r6, #4]
	adds r0, #1
_0805C634:
	strh r0, [r6, #4]
_0805C636:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c644
FUN_0805c644: @ 0x0805C644
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r7, r1, #0
	ldrb r0, [r7]
	cmp r0, #0
	beq _0805C748
	movs r0, #0
	strb r0, [r7]
	ldr r2, _0805C68C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805C690 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805C694 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r4, sp
	ldrb r5, [r0]
	ldr r1, _0805C698 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	cmp r0, #0
	blt _0805C69C
	asrs r3, r0, #0xc
	b _0805C6A2
	.align 2, 0
_0805C68C: .4byte 0x030046B8
_0805C690: .4byte 0x000003FF
_0805C694: .4byte 0x0203B400
_0805C698: .4byte gSineTable
_0805C69C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C6A2:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C6BC
	asrs r0, r0, #0xc
	b _0805C6C2
_0805C6BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C6C2:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	mov r3, r8
	adds r3, #0x30
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r4, r8
	ldrh r4, [r4, #0x30]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	movs r3, #0x14
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r5, #0x18
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805C758 @ =0x0203B400
	ldr r2, _0805C75C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C760 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x60
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x20
	strb r0, [r7, #7]
	adds r2, r7, #0
	adds r2, #0x7c
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0805C748:
	mov r2, r8
	ldrb r1, [r2, #0x1c]
	cmp r1, #0
	bne _0805C764
	movs r0, #1
	strb r0, [r7, #1]
	b _0805C80A
	.align 2, 0
_0805C758: .4byte 0x0203B400
_0805C75C: .4byte 0x030046B8
_0805C760: .4byte 0x000003FF
_0805C764:
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _0805C7D0
	adds r6, r7, #0
	adds r6, #0x14
	adds r5, r7, #0
	adds r5, #0x1c
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r4, #0x14
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r5, r2]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805C7C4 @ =0x0203B400
	ldr r2, _0805C7C8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805C7CC @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r0, #0x60
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x20
	strb r0, [r7, #7]
	b _0805C7DC
	.align 2, 0
_0805C7C4: .4byte 0x0203B400
_0805C7C8: .4byte 0x030046B8
_0805C7CC: .4byte 0x000003FF
_0805C7D0:
	subs r0, #1
	strb r0, [r7, #7]
	adds r5, r7, #0
	adds r5, #0x1c
	adds r6, r7, #0
	adds r6, #0x14
_0805C7DC:
	movs r3, #0x1c
	ldrsh r2, [r7, r3]
	movs r4, #0x14
	ldrsh r0, [r7, r4]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r5, r1]
	movs r3, #4
	ldrsh r1, [r6, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _0805C810 @ =0x00000FFF
	cmp r1, r0
	bhi _0805C814
	movs r0, #7
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
_0805C80A:
	strb r0, [r7]
	strh r1, [r7, #4]
	b _0805C9A8
	.align 2, 0
_0805C810: .4byte 0x00000FFF
_0805C814:
	ldr r0, _0805C848 @ =0x0000FFFF
	cmp r1, r0
	bhi _0805C898
	ldrb r0, [r7, #6]
	add r5, sp, #8
	adds r4, r0, #0
	adds r4, #0x80
	movs r1, #5
	mov ip, r1
	ldr r2, _0805C84C @ =gSineTable
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _0805C850
	asrs r3, r0, #0xc
	b _0805C856
	.align 2, 0
_0805C848: .4byte 0x0000FFFF
_0805C84C: .4byte gSineTable
_0805C850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C856:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r4, ip
	muls r4, r0, r4
	adds r0, r4, #0
	cmp r0, #0
	blt _0805C876
	asrs r0, r0, #0xc
	b _0805C87C
_0805C876:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C87C:
	strh r0, [r5, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r5, [r7, #0x14]
	adds r0, r0, r5
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	b _0805C98A
_0805C898:
	ldrh r0, [r7, #4]
	movs r1, #0x7f
	ands r1, r0
	cmp r1, #0x3f
	bgt _0805C912
	ldrb r0, [r7, #6]
	add r5, sp, #8
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _0805C8C8 @ =gSineTable
	adds r0, #0xc0
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #3
	adds r1, r2, #0
	adds r2, r5, #0
	cmp r0, #0
	blt _0805C8CC
	asrs r3, r0, #0xc
	b _0805C8D2
	.align 2, 0
_0805C8C8: .4byte gSineTable
_0805C8CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C8D2:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r4, r0
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #8
	muls r0, r1, r0
	cmp r0, #0
	blt _0805C8F0
	asrs r0, r0, #0xc
	b _0805C8F6
_0805C8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C8F6:
	strh r0, [r5, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r5, [r7, #0x14]
	adds r0, r0, r5
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	adds r0, r0, r1
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r6, #4]
	adds r0, r0, r2
	b _0805C98A
_0805C912:
	cmp r1, #0x5f
	bgt _0805C98C
	add r4, sp, #8
	ldrb r5, [r7, #6]
	movs r3, #6
	mov ip, r3
	ldr r2, _0805C944 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r2, #0
	adds r2, r4, #0
	cmp r0, #0
	blt _0805C948
	asrs r3, r0, #0xc
	b _0805C94E
	.align 2, 0
_0805C944: .4byte gSineTable
_0805C948:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805C94E:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805C96A
	asrs r0, r0, #0xc
	b _0805C970
_0805C96A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805C970:
	strh r0, [r4, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r3, [r7, #0x14]
	adds r0, r0, r3
	strh r0, [r7, #0x14]
	ldrh r0, [r2, #2]
	ldrh r4, [r6, #2]
	adds r0, r0, r4
	strh r0, [r6, #2]
	ldrh r0, [r2, #4]
	ldrh r5, [r6, #4]
	adds r0, r0, r5
_0805C98A:
	strh r0, [r6, #4]
_0805C98C:
	adds r0, r7, #0
	adds r0, #0x7c
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r7, #4]
	adds r0, #1
	strh r0, [r7, #4]
_0805C9A8:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805c9b4
FUN_0805c9b4: @ 0x0805C9B4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805CA82
	movs r0, #0
	strb r0, [r4]
	ldr r2, _0805CA00 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805CA04 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805CA08 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	mov r5, sp
	ldrb r6, [r0]
	ldr r1, _0805CA0C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #5
	adds r2, r1, #0
	cmp r0, #0
	blt _0805CA10
	asrs r3, r0, #0xc
	b _0805CA16
	.align 2, 0
_0805CA00: .4byte 0x030046B8
_0805CA04: .4byte 0x000003FF
_0805CA08: .4byte 0x0203B400
_0805CA0C: .4byte gSineTable
_0805CA10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805CA16:
	movs r0, #0
	strh r3, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x20
	muls r0, r1, r0
	cmp r0, #0
	blt _0805CA30
	asrs r0, r0, #0xc
	b _0805CA36
_0805CA30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CA36:
	strh r0, [r5, #4]
	adds r2, r4, #0
	adds r2, #0x1c
	adds r3, r7, #0
	adds r3, #0x30
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r7, #0x30]
	adds r0, r0, r5
	strh r0, [r4, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4, #6]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805CA82:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0805CA8E
	movs r0, #1
	strb r0, [r4, #1]
	b _0805CAC2
_0805CA8E:
	adds r3, r4, #0
	adds r3, #0x14
	movs r5, #0x1c
	ldrsh r2, [r4, r5]
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r5, #0x20
	ldrsh r0, [r4, r5]
	movs r5, #4
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _0805CAC8 @ =0x00000FFF
	adds r5, r3, #0
	cmp r1, r0
	bhi _0805CACC
	movs r0, #7
	movs r1, #0
	strb r0, [r4, #1]
	movs r0, #1
_0805CAC2:
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805CB6E
	.align 2, 0
_0805CAC8: .4byte 0x00000FFF
_0805CACC:
	add r3, sp, #8
	ldrb r6, [r4, #6]
	movs r0, #0x18
	mov ip, r0
	ldr r2, _0805CAF8 @ =gSineTable
	adds r0, r6, #0
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
	mov r8, r3
	cmp r0, #0
	blt _0805CAFC
	asrs r1, r0, #0xc
	b _0805CB02
	.align 2, 0
_0805CAF8: .4byte gSineTable
_0805CAFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CB02:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805CB1E
	asrs r0, r0, #0xc
	b _0805CB24
_0805CB1E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CB24:
	strh r0, [r3, #4]
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r2, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	mov r3, r8
	ldrh r0, [r3, #2]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r0, [r3, #4]
	ldrh r2, [r5, #4]
	adds r0, r0, r2
	strh r0, [r5, #4]
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #1
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	cmp r0, #9
	bls _0805CB6A
	movs r0, #5
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	movs r0, #0
	b _0805CB6C
_0805CB6A:
	adds r0, #1
_0805CB6C:
	strh r0, [r4, #4]
_0805CB6E:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805cb7c
FUN_0805cb7c: @ 0x0805CB7C
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805CBCE
	movs r0, #0
	strb r0, [r4]
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r2, #0x14
	ldrsh r1, [r4, r2]
	subs r0, r0, r1
	movs r3, #0x20
	ldrsh r1, [r4, r3]
	movs r5, #0x18
	ldrsh r2, [r4, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r2, _0805CBE0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0805CBE4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0805CBE8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	strb r0, [r4, #7]
_0805CBCE:
	ldrb r1, [r7, #0x1c]
	cmp r1, #0
	bne _0805CBEC
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805CD00
	.align 2, 0
_0805CBE0: .4byte 0x030046B8
_0805CBE4: .4byte 0x000003FF
_0805CBE8: .4byte 0x0203B400
_0805CBEC:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0805CC2C
	ldr r3, _0805CC20 @ =0x0203B400
	ldr r1, _0805CC24 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _0805CC28 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	strb r0, [r4, #6]
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x10
	b _0805CC2E
	.align 2, 0
_0805CC20: .4byte 0x0203B400
_0805CC24: .4byte 0x030046B8
_0805CC28: .4byte 0x000003FF
_0805CC2C:
	subs r0, #1
_0805CC2E:
	strb r0, [r4, #7]
	adds r3, r4, #0
	adds r3, #0x14
	movs r5, #0x1c
	ldrsh r2, [r4, r5]
	movs r1, #0x14
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	movs r5, #0x20
	ldrsh r0, [r4, r5]
	movs r5, #4
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r1, r0
	ldrh r1, [r4, #0x16]
	movs r5, #0x16
	ldrsh r0, [r4, r5]
	movs r5, #0x1e
	ldrsh r2, [r4, r5]
	adds r5, r3, #0
	cmp r0, r2
	ble _0805CC68
	subs r0, r1, #1
	b _0805CC6E
_0805CC68:
	cmp r0, r2
	bge _0805CC70
	adds r0, r1, #1
_0805CC6E:
	strh r0, [r4, #0x16]
_0805CC70:
	ldr r0, _0805CC98 @ =0x00000FFF
	cmp r6, r0
	bhi _0805CCE4
	mov r3, sp
	ldrb r6, [r4, #6]
	ldr r2, _0805CC9C @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0805CCA0
	asrs r1, r0, #0xc
	b _0805CCA6
	.align 2, 0
_0805CC98: .4byte 0x00000FFF
_0805CC9C: .4byte gSineTable
_0805CCA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CCA6:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0805CCC0
	asrs r0, r0, #0xc
	b _0805CCC6
_0805CCC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CCC6:
	strh r0, [r3, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r4, #0x14]
	adds r0, r0, r3
	strh r0, [r4, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
_0805CCE4:
	adds r0, r4, #0
	adds r0, #0x7c
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805CD00:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805cd08
FUN_0805cd08: @ 0x0805CD08
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _0805CD32
	movs r0, #0
	strb r0, [r5]
	adds r2, r5, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, #0x2a
	bl Video_SetAuxSpritePltt
_0805CD32:
	ldrh r1, [r5, #4]
	movs r0, #0x14
	subs r0, r0, r1
	mov r3, sp
	ldrb r4, [r5, #6]
	lsls r6, r0, #1
	ldr r2, _0805CD5C @ =gSineTable
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
	blt _0805CD60
	asrs r1, r0, #0xc
	b _0805CD66
	.align 2, 0
_0805CD5C: .4byte gSineTable
_0805CD60:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805CD66:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805CD7E
	asrs r0, r0, #0xc
	b _0805CD84
_0805CD7E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CD84:
	strh r0, [r3, #4]
	adds r1, r5, #0
	adds r1, #0x14
	mov r2, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r2, #2]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r1, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r1, #4]
	adds r0, r0, r2
	strh r0, [r1, #4]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #1
	bl FUN_0805bbb0
	ldrh r0, [r5, #4]
	cmp r0, #0x13
	bls _0805CDD0
	movs r0, #1
	strb r0, [r5, #1]
	strb r0, [r5]
	movs r0, #0
	strh r0, [r5, #4]
	adds r2, r5, #0
	adds r2, #0xdc
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	b _0805CE1E
_0805CDD0:
	cmp r0, #6
	bne _0805CDE8
	movs r3, #0x84
	lsls r3, r3, #1
	adds r4, r5, r3
	adds r0, r4, #0
	ldr r1, _0805CE04 @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r1, _0805CE08 @ =0x00001688
	adds r0, r7, r1
	str r0, [r4, #0xc]
_0805CDE8:
	ldrh r0, [r5, #4]
	lsrs r0, r0, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0805CE0C
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _0805CE16
	.align 2, 0
_0805CE04: .4byte 0x00000263
_0805CE08: .4byte 0x00001688
_0805CE0C:
	adds r0, r5, #0
	adds r0, #0xdc
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_0805CE16:
	str r1, [r0]
	ldrh r0, [r5, #4]
	adds r0, #1
	strh r0, [r5, #4]
_0805CE1E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805ce28
FUN_0805ce28: @ 0x0805CE28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	ldrb r0, [r7]
	cmp r0, #0
	bne _0805CE3C
	b _0805CF40
_0805CE3C:
	movs r0, #0
	strb r0, [r7]
	adds r2, r7, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	ldr r4, _0805CE90 @ =0x0203B400
	ldr r3, _0805CE94 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _0805CE98 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	adds r1, r1, r4
	movs r6, #0xff
	ldrb r5, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r1, [r0]
	movs r0, #0x3f
	ands r1, r0
	mov r4, sp
	adds r2, r1, #0
	adds r2, #0x10
	ldr r1, _0805CE9C @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0805CEA0
	asrs r3, r0, #0xc
	b _0805CEA6
	.align 2, 0
_0805CE90: .4byte 0x0203B400
_0805CE94: .4byte 0x030046B8
_0805CE98: .4byte 0x000003FF
_0805CE9C: .4byte gSineTable
_0805CEA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805CEA6:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r5, #0
	ldrsh r0, [r0, r5]
	muls r0, r2, r0
	cmp r0, #0
	blt _0805CEBE
	asrs r0, r0, #0xc
	b _0805CEC4
_0805CEBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805CEC4:
	strh r0, [r4, #4]
	adds r2, r7, #0
	adds r2, #0x1c
	mov r3, r8
	adds r3, #0x38
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	mov r4, r8
	ldrh r4, [r4, #0x38]
	adds r0, r0, r4
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r5, [r3, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0x1c
	ldrsh r0, [r7, r1]
	movs r3, #0x14
	ldrsh r1, [r7, r3]
	subs r0, r0, r1
	movs r4, #4
	ldrsh r1, [r2, r4]
	movs r5, #0x18
	ldrsh r2, [r7, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805CF58 @ =0x0203B400
	ldr r2, _0805CF5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805CF60 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	subs r0, #8
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r7, #7]
	movs r0, #0x10
	strh r0, [r7, #0x10]
_0805CF40:
	mov r2, r8
	ldrb r0, [r2, #0x1c]
	cmp r0, #0
	beq _0805CF64
	movs r0, #5
	movs r1, #0
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	strh r1, [r7, #4]
	b _0805D092
	.align 2, 0
_0805CF58: .4byte 0x0203B400
_0805CF5C: .4byte 0x030046B8
_0805CF60: .4byte 0x000003FF
_0805CF64:
	ldrb r0, [r7, #7]
	cmp r0, #0
	bne _0805CFCC
	adds r5, r7, #0
	adds r5, #0x14
	movs r3, #0x1c
	ldrsh r0, [r7, r3]
	movs r4, #0x14
	ldrsh r1, [r7, r4]
	subs r0, r0, r1
	movs r2, #0x20
	ldrsh r1, [r7, r2]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r7, #6]
	ldr r4, _0805CFC0 @ =0x0203B400
	ldr r2, _0805CFC4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0805CFC8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	subs r0, #1
	ldrb r1, [r7, #6]
	adds r0, r0, r1
	strb r0, [r7, #6]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strb r0, [r7, #7]
	b _0805CFD4
	.align 2, 0
_0805CFC0: .4byte 0x0203B400
_0805CFC4: .4byte 0x030046B8
_0805CFC8: .4byte 0x000003FF
_0805CFCC:
	subs r0, #1
	strb r0, [r7, #7]
	adds r5, r7, #0
	adds r5, #0x14
_0805CFD4:
	mov r4, sp
	ldrb r6, [r7, #6]
	ldrh r2, [r7, #0x10]
	mov ip, r2
	ldr r2, _0805D000 @ =gSineTable
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r2, #0
	cmp r0, #0
	blt _0805D004
	asrs r3, r0, #0xc
	b _0805D00A
	.align 2, 0
_0805D000: .4byte gSineTable
_0805D004:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_0805D00A:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r3, ip
	muls r3, r0, r3
	adds r0, r3, #0
	cmp r0, #0
	blt _0805D026
	asrs r0, r0, #0xc
	b _0805D02C
_0805D026:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805D02C:
	strh r0, [r4, #4]
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r4, [r7, #0x14]
	adds r0, r0, r4
	strh r0, [r7, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r5, #2]
	adds r0, r0, r2
	strh r0, [r5, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r5, #4]
	adds r0, r0, r3
	strh r0, [r5, #4]
	mov r0, r8
	adds r1, r7, #0
	movs r2, #0
	bl FUN_0805bbb0
	mov r4, r8
	movs r0, #0x38
	ldrsh r2, [r4, r0]
	movs r1, #0x14
	ldrsh r0, [r7, r1]
	subs r2, r2, r0
	movs r3, #0x3c
	ldrsh r0, [r4, r3]
	movs r4, #4
	ldrsh r1, [r5, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r5, r0, #0
	muls r5, r0, r5
	adds r0, r5, #0
	adds r1, r1, r0
	ldr r0, _0805D088 @ =0x00003FFF
	cmp r1, r0
	bgt _0805D08C
	movs r0, #0xa
	strb r0, [r7, #1]
	movs r0, #1
	strb r0, [r7]
	movs r0, #0
	b _0805D090
	.align 2, 0
_0805D088: .4byte 0x00003FFF
_0805D08C:
	ldrh r0, [r7, #4]
	adds r0, #1
_0805D090:
	strh r0, [r7, #4]
_0805D092:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0805d0a0
FUN_0805d0a0: @ 0x0805D0A0
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805D0BC
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805D0BC:
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrb r1, [r5, #0x1d]
	cmp r1, #0
	beq _0805D0D2
	movs r0, #0xb
	movs r1, #0
	b _0805D0DA
_0805D0D2:
	ldrb r0, [r5, #0x1c]
	cmp r0, #0
	beq _0805D0E4
	movs r0, #5
_0805D0DA:
	strb r0, [r4, #1]
	movs r0, #1
	strb r0, [r4]
	strh r1, [r4, #4]
	b _0805D0EA
_0805D0E4:
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
_0805D0EA:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805d0f0
FUN_0805d0f0: @ 0x0805D0F0
	push {r4, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _0805D10C
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0x7c
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0805D10C:
	adds r0, r3, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0805bbb0
	ldrh r0, [r4, #4]
	adds r0, #1
	strh r0, [r4, #4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity0805d364_Update
Entity0805d364_Update: @ 0x0805D124
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x18]
	cmp r0, #0
	bne _0805D138
	b _0805D288
_0805D138:
	bl FUN_08084710
	strb r0, [r5, #0x1c]
	adds r0, r5, #0
	adds r0, #0x30
	bl FUN_08084734
	ldr r1, [r5, #0x24]
	ldr r0, _0805D188 @ =0x00000257
	cmp r1, r0
	bls _0805D166
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	bne _0805D15E
	movs r0, #1
	strb r0, [r5, #0x1e]
	movs r0, #0xea
	bl PlaySound_082406e0
_0805D15E:
	ldr r0, _0805D18C @ =0x00001684
	adds r1, r5, r0
	movs r0, #2
	strb r0, [r1]
_0805D166:
	ldr r1, _0805D18C @ =0x00001684
	adds r2, r5, r1
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	bne _0805D194
	ldr r3, _0805D190 @ =0x00001685
	adds r1, r5, r3
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x3e
	ble _0805D1CE
	movs r0, #0x3f
	b _0805D1C8
	.align 2, 0
_0805D188: .4byte 0x00000257
_0805D18C: .4byte 0x00001684
_0805D190: .4byte 0x00001685
_0805D194:
	cmp r0, #1
	bne _0805D1B0
	ldr r4, _0805D1AC @ =0x00001685
	adds r1, r5, r4
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0805D1CE
	movs r0, #0
	b _0805D1C8
	.align 2, 0
_0805D1AC: .4byte 0x00001685
_0805D1B0:
	cmp r0, #2
	bne _0805D1CE
	ldr r0, _0805D20C @ =0x00001685
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x1f
	ble _0805D1CE
	movs r0, #0x20
_0805D1C8:
	strb r0, [r1]
	movs r0, #0xff
	strb r0, [r2]
_0805D1CE:
	ldr r1, _0805D210 @ =0x00001684
	adds r0, r5, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _0805D1FE
	ldr r0, _0805D214 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805D218 @ =0x00004C60
	adds r1, r2, r3
	ldr r4, _0805D21C @ =0x00004CA0
	adds r2, r2, r4
	ldr r3, _0805D220 @ =0x00001688
	adds r0, r5, r3
	ldr r4, _0805D20C @ =0x00001685
	adds r3, r5, r4
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	movs r4, #6
	str r4, [sp]
	bl BlendPltt
_0805D1FE:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	beq _0805D224
	adds r0, r5, #0
	bl FUN_0805bb7c
	b _0805D288
	.align 2, 0
_0805D20C: .4byte 0x00001685
_0805D210: .4byte 0x00001684
_0805D214: .4byte 0x03003584
_0805D218: .4byte 0x00004C60
_0805D21C: .4byte 0x00004CA0
_0805D220: .4byte 0x00001688
_0805D224:
	movs r7, #0
	movs r0, #0
	mov r8, r0
	adds r4, r5, #0
	adds r4, #0x44
	movs r6, #0
	ldr r1, _0805D298 @ =0x085ABA2C
	mov sb, r1
_0805D234:
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl _call_via_r3
	adds r0, r4, #0
	bl FUN_0805bc0c
	ldrb r0, [r4, #1]
	cmp r0, #7
	bne _0805D254
	adds r7, #1
_0805D254:
	cmp r0, #0xa
	bne _0805D25C
	movs r3, #1
	add r8, r3
_0805D25C:
	adds r6, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r6, #0xf
	ble _0805D234
	ldr r1, [r5, #0x24]
	cmp r7, #0x10
	beq _0805D27A
	mov r3, r8
	cmp r3, #0x10
	beq _0805D27A
	ldr r0, _0805D29C @ =0x000004AF
	cmp r1, r0
	bls _0805D284
_0805D27A:
	ldrb r0, [r5, #0x1d]
	cmp r0, #0
	bne _0805D284
	movs r0, #1
	strb r0, [r5, #0x1d]
_0805D284:
	adds r0, r1, #1
	str r0, [r5, #0x24]
_0805D288:
	movs r0, #0
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805D298: .4byte 0x085ABA2C
_0805D29C: .4byte 0x000004AF

	thumb_func_start Entity0805d364_Destroy
Entity0805d364_Destroy: @ 0x0805D2A0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x44
	movs r4, #0
_0805D2AA:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0805bb30
	adds r4, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r5, r5, r0
	cmp r4, #0xf
	ble _0805D2AA
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity0805d364_Init
Entity0805d364_Init: @ 0x0805D2C8
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r2, #0
	movs r3, #0
	movs r0, #0xa
	strh r0, [r6, #0x20]
	movs r0, #0x64
	strh r0, [r6, #0x22]
	strb r2, [r6, #0x1d]
	str r3, [r6, #0x18]
	strb r1, [r6, #0x1f]
	ldr r0, _0805D348 @ =0x0000922E
	ldr r1, _0805D34C @ =0x00005BB7
	bl GetFile
	str r0, [r6, #0x40]
	ldr r0, _0805D350 @ =0x03003584
	ldr r2, [r0]
	ldr r0, _0805D354 @ =0x00004C60
	adds r1, r2, r0
	ldr r3, _0805D358 @ =0x00004CA0
	adds r2, r2, r3
	ldr r3, _0805D35C @ =0x00001688
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x40
	bl BlendPltt
	adds r4, r6, #0
	adds r4, #0x44
	movs r5, #0
_0805D30A:
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0805b9b4
	adds r5, #1
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r4, r0
	cmp r5, #0xf
	ble _0805D30A
	movs r5, #0
	ldrb r3, [r6, #0x1f]
	cmp r5, r3
	bge _0805D33C
	adds r1, r6, #0
	adds r1, #0x28
	ldr r2, _0805D360 @ =0x03002BE0
_0805D32E:
	ldm r2!, {r0}
	adds r0, #0x2c
	stm r1!, {r0}
	adds r5, #1
	ldrb r0, [r6, #0x1f]
	cmp r5, r0
	blt _0805D32E
_0805D33C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0805D348: .4byte 0x0000922E
_0805D34C: .4byte 0x00005BB7
_0805D350: .4byte 0x03003584
_0805D354: .4byte 0x00004C60
_0805D358: .4byte 0x00004CA0
_0805D35C: .4byte 0x00001688
_0805D360: .4byte 0x03002BE0

	thumb_func_start Entity0805d364_Create
Entity0805d364_Create: @ 0x0805D364
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _0805D394 @ =0x000016A8
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805D3A0
	ldr r1, _0805D398 @ =Entity0805d364_Update
	ldr r2, _0805D39C @ =Entity0805d364_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl Entity0805d364_Init
	cmp r0, #0
	bge _0805D3A0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805D3A2
	.align 2, 0
_0805D394: .4byte 0x000016A8
_0805D398: .4byte Entity0805d364_Update
_0805D39C: .4byte Entity0805d364_Destroy
_0805D3A0:
	adds r0, r4, #0
_0805D3A2:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805d3a8
FUN_0805d3a8: @ 0x0805D3A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	str r1, [sp, #4]
	adds r4, r2, #0
	str r3, [sp, #8]
	movs r0, #0
	strb r0, [r6, #0x1c]
	strb r0, [r6, #0x1d]
	strb r0, [r6, #0x1e]
	str r0, [r6, #0x24]
	ldr r0, _0805D45C @ =0x00001684
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _0805D460 @ =0x00001685
	adds r1, r6, r2
	movs r0, #0x3f
	strb r0, [r1]
	ldr r0, _0805D464 @ =0x03003584
	ldr r2, [r0]
	ldr r3, _0805D468 @ =0x00004C60
	adds r1, r2, r3
	ldr r0, _0805D46C @ =0x00004CA0
	adds r2, r2, r0
	ldr r3, _0805D470 @ =0x00001688
	adds r0, r6, r3
	movs r3, #6
	str r3, [sp]
	movs r3, #0x3f
	bl BlendPltt
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
	adds r5, r6, #0
	adds r5, #0x44
	movs r0, #0
	str r0, [sp, #0xc]
	mov sl, r0
	ldr r1, _0805D474 @ =0x030046B8
	mov r8, r1
	adds r7, r6, #0
	adds r7, #0xc0
_0805D40A:
	mov r2, sl
	strb r2, [r5, #1]
	movs r3, #1
	strb r3, [r5]
	mov r0, sl
	strh r0, [r5, #4]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D478 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D47C @ =0x0203B400
	adds r0, r0, r3
	ldrh r1, [r0]
	ldr r0, [sp, #0xc]
	lsls r2, r0, #5
	movs r0, #0x1f
	ands r1, r0
	adds r2, r2, r1
	strb r2, [r5, #6]
	mov r1, sp
	ldrh r1, [r1, #8]
	strh r1, [r5, #0x10]
	mov r2, sp
	ldrh r2, [r2, #0x30]
	strh r2, [r5, #0x12]
	ldrb r0, [r6, #0x1f]
	movs r3, #0xdc
	adds r3, r3, r5
	mov sb, r3
	cmp r0, #2
	bne _0805D486
	ldr r0, [sp, #0xc]
	cmp r0, #7
	bgt _0805D480
	movs r1, #1
	strb r1, [r5, #8]
	b _0805D494
	.align 2, 0
_0805D45C: .4byte 0x00001684
_0805D460: .4byte 0x00001685
_0805D464: .4byte 0x03003584
_0805D468: .4byte 0x00004C60
_0805D46C: .4byte 0x00004CA0
_0805D470: .4byte 0x00001688
_0805D474: .4byte 0x030046B8
_0805D478: .4byte 0x000003FF
_0805D47C: .4byte 0x0203B400
_0805D480:
	mov r2, sl
	strb r2, [r5, #8]
	b _0805D494
_0805D486:
	cmp r0, #0
	bne _0805D490
	mov r3, sl
	strb r3, [r5, #8]
	b _0805D494
_0805D490:
	movs r0, #0xff
	strb r0, [r5, #8]
_0805D494:
	mov r0, sl
	strb r0, [r5, #9]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D4D8 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D4DC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x10
	ldr r2, _0805D4E0 @ =gSineTable
	ldrb r3, [r5, #6]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov ip, r3
	cmp r0, #0
	blt _0805D4E4
	asrs r1, r0, #0xc
	b _0805D4EA
	.align 2, 0
_0805D4D8: .4byte 0x000003FF
_0805D4DC: .4byte 0x0203B400
_0805D4E0: .4byte gSineTable
_0805D4E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805D4EA:
	ldr r3, [sp, #4]
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
	ldrh r0, [r3, #2]
	strh r0, [r5, #0x16]
	mov r1, ip
	lsls r0, r1, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _0805D50A
	asrs r2, r0, #0xc
	b _0805D510
_0805D50A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0805D510:
	ldr r3, [sp, #4]
	ldrh r0, [r3, #4]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	ldrh r0, [r5, #0x16]
	strh r0, [r5, #0xe]
	mov r1, r8
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0805D5C4 @ =0x000003FF
	ands r0, r1
	mov r2, r8
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0805D5C8 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #7
	strb r0, [r5, #7]
	adds r4, r5, #0
	adds r4, #0x14
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r7, #0x60]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7, #0x60]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_0805bbb0
	movs r3, #0x84
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, _0805D5CC @ =0x00000263
	bl Video_SetAuxSpritePltt
	ldr r1, _0805D5D0 @ =0x00001688
	adds r0, r6, r1
	mov r2, sb
	str r0, [r2, #0x38]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r0, r5, r3
	bl ParticleShadow_Show
	adds r0, r5, #0
	adds r0, #0x2c
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldrh r0, [r7, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r7, #6]
	ldr r0, [sp, #0xc]
	adds r0, #1
	str r0, [sp, #0xc]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r7, r7, r1
	adds r5, r5, r1
	cmp r0, #0xf
	bgt _0805D5AC
	b _0805D40A
_0805D5AC:
	movs r0, #1
	str r0, [r6, #0x18]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805D5C4: .4byte 0x000003FF
_0805D5C8: .4byte 0x0203B400
_0805D5CC: .4byte 0x00000263
_0805D5D0: .4byte 0x00001688

	thumb_func_start FUN_0805d5d4
FUN_0805d5d4: @ 0x0805D5D4
	movs r1, #0x96
	lsls r1, r1, #2
	str r1, [r0, #0x24]
	bx lr
