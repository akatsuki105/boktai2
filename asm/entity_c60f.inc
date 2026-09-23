	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081d6444
FUN_081d6444: @ 0x081D6444
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r0, _081D6468 @ =0x00000157
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D646C
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	b _081D64BE
	.align 2, 0
_081D6468: .4byte 0x00000157
_081D646C:
	ldr r6, _081D64C8 @ =0x0203B400
	ldr r4, _081D64CC @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _081D64D0 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x1c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	movs r1, #0x14
	bl Mod
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #0xa
	strh r1, [r7, #0x20]
	mov r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_081D64BE:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D64C8: .4byte 0x0203B400
_081D64CC: .4byte 0x030046B8
_081D64D0: .4byte 0x000003FF

	thumb_func_start FUN_081d64d4
FUN_081d64d4: @ 0x081D64D4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r4, r0, #0
	mov sb, r1
	adds r5, r2, #0
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _081D65C8
	adds r0, r4, #0
	bl Hitbox_ApplyDamage
	adds r0, r4, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, sb
	adds r0, #0x44
	strh r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	adds r0, #0x96
	ldrh r2, [r0]
	subs r6, r1, r2
	adds r1, r0, #0
	cmp r6, #0
	bge _081D651C
	adds r6, r6, r2
	b _081D651E
_081D651C:
	adds r6, r2, #0
_081D651E:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r7, r5, r3
	ldrh r0, [r7]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r4, #0
	mov r8, r4
	strh r0, [r7]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D653A
	mov r0, r8
	strh r0, [r7]
_081D653A:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r7, r2]
	movs r3, #0xa1
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r4, #0
	ldrsh r2, [r2, r4]
	ldr r4, _081D65D8 @ =0x00000147
	adds r3, r5, r4
	ldrb r3, [r3]
	mov r4, r8
	str r4, [sp]
	bl FUN_0809c344
	add r4, sp, #0xc
	mov r0, r8
	str r0, [sp, #8]
	add r0, sp, #8
	adds r1, r4, #0
	ldr r2, _081D65DC @ =0x05000002
	bl CpuSet
	adds r3, r5, #0
	adds r3, #0x1c
	str r4, [sp]
	movs r4, #1
	str r4, [sp, #4]
	mov r0, sb
	adds r1, r6, #0
	movs r2, #0
	bl FUN_0805fe7c
	ldr r2, _081D65E0 @ =0x00000153
	adds r1, r5, r2
	movs r0, #3
	strb r0, [r1]
	ldr r3, _081D65E4 @ =0x00000157
	adds r1, r5, r3
	movs r0, #0xa
	strb r0, [r1]
	adds r1, r5, #0
	adds r1, #0x9c
	movs r0, #0x18
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_081d65e8
	adds r0, r5, #0
	bl FUN_081d6bc0
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r0, #0
	bgt _081D65C8
	movs r2, #0xa4
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #4
	strh r0, [r1]
	movs r3, #0xab
	lsls r3, r3, #1
	adds r0, r5, r3
	strb r4, [r0]
_081D65C8:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D65D8: .4byte 0x00000147
_081D65DC: .4byte 0x05000002
_081D65E0: .4byte 0x00000153
_081D65E4: .4byte 0x00000157

	thumb_func_start FUN_081d65e8
FUN_081d65e8: @ 0x081D65E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r6, r0, #0
	add r0, sp, #0x10
	mov r8, r0
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov r1, r8
	ldr r2, _081D66A8 @ =0x05000002
	bl CpuSet
	movs r0, #0x10
	mov r1, r8
	strh r0, [r1, #2]
	ldr r5, _081D66AC @ =0x0203B400
	ldr r7, _081D66B0 @ =0x030046B8
	mov ip, r7
	mov r0, ip
	ldr r2, [r0]
	adds r2, #1
	ldr r4, _081D66B4 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #3
	mov sb, r1
	mov r7, sb
	ands r0, r7
	adds r0, #0xf
	ldr r1, _081D66B8 @ =0xFFFF0000
	mov sl, r1
	ldr r3, [sp, #0x18]
	ands r3, r1
	orrs r3, r0
	str r3, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0xf
	lsls r1, r1, #0x10
	ldr r0, _081D66BC @ =0x0000FFFF
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x18]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	ands r1, r7
	adds r1, #0xf
	add r3, sp, #0x18
	ldr r0, [r3, #4]
	mov r7, sl
	ands r0, r7
	orrs r0, r1
	str r0, [r3, #4]
	adds r2, #1
	ands r2, r4
	mov r0, ip
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r0, [r2]
	movs r1, #3
	ands r0, r1
	adds r0, #2
	adds r6, #0x1c
	str r3, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #0xf
	str r1, [sp, #8]
	movs r1, #0x11
	adds r2, r6, #0
	mov r3, r8
	bl FUN_08014730
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D66A8: .4byte 0x05000002
_081D66AC: .4byte 0x0203B400
_081D66B0: .4byte 0x030046B8
_081D66B4: .4byte 0x000003FF
_081D66B8: .4byte 0xFFFF0000
_081D66BC: .4byte 0x0000FFFF

	thumb_func_start FUN_081d66c0
FUN_081d66c0: @ 0x081D66C0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	mov sb, r3
	adds r4, r7, #0
	adds r4, #0x58
	ldr r2, _081D6754 @ =0xFFFF0000
	ldr r5, _081D6758 @ =0x0000FFFF
	movs r1, #0xa0
	lsls r1, r1, #0xf
	str r1, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r2
	movs r3, #0x40
	orrs r0, r3
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	orrs r0, r3
	str r0, [r1, #4]
	movs r2, #0xa8
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	strh r0, [r4, #4]
	ldr r2, _081D675C @ =0x00005001
	movs r0, #0x10
	str r0, [sp]
	str r1, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, r8
	mov r3, sb
	bl Hitbox_SetPowerAndAttributes
	adds r1, r7, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D6760 @ =FUN_081d64d4
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6754: .4byte 0xFFFF0000
_081D6758: .4byte 0x0000FFFF
_081D675C: .4byte 0x00005001
_081D6760: .4byte FUN_081d64d4

	thumb_func_start FUN_081d6764
FUN_081d6764: @ 0x081D6764
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x34
	mov r8, r0
	ldr r2, _081D67A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D67A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D67AC @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r4, sp, #0x2c
	movs r5, #0xa
	ldr r1, _081D67B0 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081D67B4
	asrs r1, r0, #0xc
	b _081D67BA
	.align 2, 0
_081D67A4: .4byte 0x030046B8
_081D67A8: .4byte 0x000003FF
_081D67AC: .4byte 0x0203B400
_081D67B0: .4byte 0x085B0A08
_081D67B4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D67BA:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	ldr r1, _081D67D4 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _081D67D8
	asrs r0, r0, #0xc
	b _081D67DE
	.align 2, 0
_081D67D4: .4byte 0x085B0A08
_081D67D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D67DE:
	movs r1, #0
	strh r0, [r4, #4]
	add r2, sp, #0x2c
	movs r0, #0x40
	strh r0, [r2, #2]
	mov r4, r8
	adds r4, #0x1c
	ldr r2, _081D6850 @ =0x00009385
	ldr r3, _081D6854 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r4, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6858 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D685C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D6860 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r6, #0xa
	ldr r1, _081D6864 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _081D6868
	asrs r1, r0, #0xc
	b _081D686E
	.align 2, 0
_081D6850: .4byte 0x00009385
_081D6854: .4byte 0x000074C9
_081D6858: .4byte 0x030046B8
_081D685C: .4byte 0x000003FF
_081D6860: .4byte 0x0203B400
_081D6864: .4byte 0x085B0A08
_081D6868:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D686E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6888 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _081D688C
	asrs r0, r0, #0xc
	b _081D6892
	.align 2, 0
_081D6888: .4byte 0x085B0A08
_081D688C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D6892:
	movs r1, #0
	strh r0, [r5, #4]
	add r2, sp, #0x2c
	movs r0, #0x22
	strh r0, [r2, #2]
	ldr r2, _081D68FC @ =0x00009385
	ldr r3, _081D6900 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r1, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r1, [sp, #0x20]
	str r1, [sp, #0x24]
	str r1, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6904 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D6908 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D690C @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D6910 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6914
	asrs r1, r0, #0xc
	b _081D691A
	.align 2, 0
_081D68FC: .4byte 0x00009385
_081D6900: .4byte 0x000074C9
_081D6904: .4byte 0x030046B8
_081D6908: .4byte 0x000003FF
_081D690C: .4byte 0x0203B400
_081D6910: .4byte 0x085B0A08
_081D6914:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D691A:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6934 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6938
	asrs r0, r0, #0xc
	b _081D693E
	.align 2, 0
_081D6934: .4byte 0x085B0A08
_081D6938:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D693E:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D69A8 @ =0x00009385
	ldr r3, _081D69AC @ =0x000074C9
	movs r1, #1
	str r1, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r4, [sp, #0x14]
	str r1, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D69B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D69B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D69B8 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D69BC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D69C0
	asrs r1, r0, #0xc
	b _081D69C6
	.align 2, 0
_081D69A8: .4byte 0x00009385
_081D69AC: .4byte 0x000074C9
_081D69B0: .4byte 0x030046B8
_081D69B4: .4byte 0x000003FF
_081D69B8: .4byte 0x0203B400
_081D69BC: .4byte 0x085B0A08
_081D69C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D69C6:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D69E0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D69E4
	asrs r0, r0, #0xc
	b _081D69EA
	.align 2, 0
_081D69E0: .4byte 0x085B0A08
_081D69E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D69EA:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D6A54 @ =0x00009385
	ldr r3, _081D6A58 @ =0x000074C9
	movs r1, #1
	str r1, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #2
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	ldr r2, _081D6A5C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081D6A60 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _081D6A64 @ =0x0203B400
	adds r0, r0, r1
	movs r2, #0xff
	ldrb r3, [r0]
	add r5, sp, #0x2c
	movs r4, #0xa
	ldr r1, _081D6A68 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6A6C
	asrs r1, r0, #0xc
	b _081D6A72
	.align 2, 0
_081D6A54: .4byte 0x00009385
_081D6A58: .4byte 0x000074C9
_081D6A5C: .4byte 0x030046B8
_081D6A60: .4byte 0x000003FF
_081D6A64: .4byte 0x0203B400
_081D6A68: .4byte 0x085B0A08
_081D6A6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081D6A72:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _081D6A8C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081D6A90
	asrs r0, r0, #0xc
	b _081D6A96
	.align 2, 0
_081D6A8C: .4byte 0x085B0A08
_081D6A90:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_081D6A96:
	movs r4, #0
	strh r0, [r5, #4]
	add r1, sp, #0x2c
	movs r0, #0x22
	strh r0, [r1, #2]
	ldr r2, _081D6AE0 @ =0x00009385
	ldr r3, _081D6AE4 @ =0x000074C9
	movs r0, #1
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r4, [sp, #0xc]
	movs r0, #0xbe
	lsls r0, r0, #1
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	str r4, [sp, #0x18]
	str r4, [sp, #0x1c]
	str r4, [sp, #0x20]
	str r4, [sp, #0x24]
	str r4, [sp, #0x28]
	adds r0, r7, #0
	add r1, sp, #0x2c
	bl FUN_081ef708
	mov r0, r8
	bl FUN_081d65e8
	add sp, #0x34
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6AE0: .4byte 0x00009385
_081D6AE4: .4byte 0x000074C9

	thumb_func_start FUN_081d6ae8
FUN_081d6ae8: @ 0x081D6AE8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r2, r1, #0
	cmp r2, #0
	ble _081D6BA0
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _081D6BA0
	ldr r1, _081D6BB0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r1
	movs r1, #4
	orrs r0, r1
	str r0, [sp, #0x10]
	add r0, sp, #0x10
	mov r7, sp
	str r7, [r0, #4]
	mov sl, r0
	cmp r2, #0
	ble _081D6BA0
	ldr r0, _081D6BB4 @ =0x0203B400
	mov r8, r0
	ldr r1, _081D6BB8 @ =0x030046B8
	mov sb, r1
	ldr r3, _081D6BBC @ =0x000003FF
	adds r6, r2, #0
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r5, r4, r2
_081D6B32:
	mov r7, sb
	ldr r1, [r7]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r7, #0x1c
	ldrsh r0, [r4, r7]
	subs r0, #0x40
	movs r7, #0x7f
	ands r2, r7
	adds r0, r0, r2
	str r0, [sp]
	adds r1, #1
	ands r1, r3
	lsls r0, r1, #1
	add r0, r8
	ldrh r2, [r0]
	movs r7, #0x1e
	ldrsh r0, [r4, r7]
	subs r0, #0x40
	movs r7, #0x7f
	ands r2, r7
	adds r0, r0, r2
	str r0, [sp, #4]
	adds r1, #1
	ands r1, r3
	mov r0, sb
	str r1, [r0]
	lsls r1, r1, #1
	add r1, r8
	ldrh r1, [r1]
	movs r2, #0x20
	ldrsh r0, [r4, r2]
	subs r0, #0x40
	ands r1, r7
	adds r0, r0, r1
	str r0, [sp, #8]
	ldrb r0, [r5]
	str r0, [sp, #0xc]
	adds r7, #0xb9
	adds r0, r4, r7
	ldrh r0, [r0]
	mov r1, sl
	str r3, [sp, #0x18]
	bl Script_ExecById
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	subs r6, #1
	ldr r3, [sp, #0x18]
	cmp r6, #0
	bne _081D6B32
_081D6BA0:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6BB0: .4byte 0xFFFF0000
_081D6BB4: .4byte 0x0203B400
_081D6BB8: .4byte 0x030046B8
_081D6BBC: .4byte 0x000003FF

	thumb_func_start FUN_081d6bc0
FUN_081d6bc0: @ 0x081D6BC0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081D6C20 @ =0x0000013D
	adds r0, r4, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r6, r4, r2
	ldrb r0, [r0]
	ldrb r1, [r6]
	cmp r0, r1
	bls _081D6C1A
	adds r2, #6
	adds r0, r4, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r5, r1, r0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D6C00
	adds r0, r4, #0
	movs r1, #2
	bl FUN_081d6ae8
_081D6C00:
	movs r1, #0x9d
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrb r1, [r6]
	subs r1, #1
	muls r0, r1, r0
	cmp r5, r0
	blt _081D6C1A
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081d6ae8
_081D6C1A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081D6C20: .4byte 0x0000013D

	thumb_func_start FUN_081d6c24
FUN_081d6c24: @ 0x081D6C24
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #1
	bl FUN_081d5848
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D6C9E
	ldr r0, _081D6CA8 @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #0x1c
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r5, #0x1c]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r3, #4
	ldrsh r0, [r2, r3]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r3, #0x98
	lsls r3, r3, #1
	adds r0, r5, r3
	str r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	bge _081D6C9E
	adds r0, r5, #0
	movs r1, #2
	bl FUN_081d6ae8
	adds r0, r5, #0
	movs r1, #1
	bl FUN_081d5820
	ldr r0, _081D6CAC @ =0x000003C7
	bl PlaySound_082406e0
_081D6C9E:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D6CA8: .4byte 0x03002BE0
_081D6CAC: .4byte 0x000003C7

	thumb_func_start FUN_081d6cb0
FUN_081d6cb0: @ 0x081D6CB0
	push {r4, lr}
	sub sp, #8
	mov ip, r0
	ldr r0, _081D6D18 @ =0x03002BE0
	mov r3, sp
	movs r2, #0x8a
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r0]
	adds r4, r0, #0
	adds r4, #0x2c
	ldrh r0, [r0, #0x2c]
	ldrh r1, [r2]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0x96
	lsls r1, r1, #1
	add r1, ip
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	str r0, [r1]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r4, #4
	ldrsh r0, [r3, r4]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	str r1, [r2]
	movs r0, #0x9a
	lsls r0, r0, #1
	add r0, ip
	ldr r0, [r0]
	cmp r1, r0
	blt _081D6D1C
	movs r0, #0
	b _081D6D1E
	.align 2, 0
_081D6D18: .4byte 0x03002BE0
_081D6D1C:
	movs r0, #1
_081D6D1E:
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d6d28
FUN_081d6d28: @ 0x081D6D28
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r2, #0
	movs r1, #8
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D6D4A
	movs r0, #1
	b _081D6D4C
_081D6D4A:
	movs r0, #0
_081D6D4C:
	cmp r0, #0
	beq _081D6D52
	b _081D6EA8
_081D6D52:
	ldr r1, _081D6D70 @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6D74
	movs r2, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	bne _081D6D90
	b _081D6D94
	.align 2, 0
_081D6D70: .4byte 0x00000109
_081D6D74:
	movs r1, #0x10
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	bne _081D6D9A
	movs r2, #2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov r8, r1
	cmp r0, #0
	beq _081D6D94
_081D6D90:
	movs r0, #1
	b _081D6D96
_081D6D94:
	movs r0, #0
_081D6D96:
	cmp r0, #0
	beq _081D6DA6
_081D6D9A:
	movs r1, #0
	strh r1, [r7, #0x3e]
	adds r0, r7, #0
	adds r0, #0x40
	strh r1, [r0]
	b _081D6EA8
_081D6DA6:
	movs r1, #8
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081D6E80
	adds r1, r7, #0
	adds r1, #0x43
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081D6DEC @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081D6DF4
	ldr r2, _081D6DF0 @ =0x00000105
	adds r4, r5, r2
	ldrb r0, [r4]
	cmp r0, #0
	bne _081D6E02
	adds r0, r5, #0
	adds r0, #0x9c
	str r0, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
	movs r0, #3
	strb r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081D6E2A
	.align 2, 0
_081D6DEC: .4byte 0x00000109
_081D6DF0: .4byte 0x00000105
_081D6DF4:
	cmp r0, #1
	bne _081D6E2A
	ldr r0, _081D6E08 @ =0x00000105
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D6E0C
_081D6E02:
	subs r0, #1
	strb r0, [r4]
	b _081D6E2A
	.align 2, 0
_081D6E08: .4byte 0x00000105
_081D6E0C:
	adds r0, r5, #0
	adds r0, #0x9c
	str r0, [sp]
	movs r0, #2
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
	movs r0, #2
	strb r0, [r4]
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081D6E2A:
	movs r1, #4
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D6E3A
	movs r0, #1
	b _081D6E3C
_081D6E3A:
	movs r0, #0
_081D6E3C:
	cmp r0, #0
	beq _081D6E80
	ldr r1, _081D6E64 @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6E68
	adds r1, r5, #0
	adds r1, #0xf4
	ldrh r0, [r1]
	subs r0, #0xc8
	strh r0, [r1]
	adds r2, r0, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D6E5E
	movs r2, #0
_081D6E5E:
	strh r2, [r1]
	b _081D6E80
	.align 2, 0
_081D6E64: .4byte 0x00000109
_081D6E68:
	adds r2, r5, #0
	adds r2, #0xf4
	ldrh r0, [r2]
	ldrh r1, [r6, #0x3e]
	subs r0, r0, r1
	strh r0, [r2]
	adds r1, r0, #0
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _081D6E7E
	movs r1, #0
_081D6E7E:
	strh r1, [r2]
_081D6E80:
	ldr r2, _081D6EB4 @ =0x00000109
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6EA8
	ldr r2, [r6, #0x4c]
	cmp r2, #0
	beq _081D6EA8
	ldr r3, [r6, #0x48]
	cmp r3, #0
	beq _081D6EA8
	movs r1, #0x10
	ldr r0, [r6, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _081D6EA8
	adds r0, r6, #0
	adds r1, r7, #0
	bl _call_via_r3
_081D6EA8:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D6EB4: .4byte 0x00000109

	thumb_func_start FUN_081d6eb8
FUN_081d6eb8: @ 0x081D6EB8
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	ldr r1, _081D6EDC @ =0x00000109
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081D6EE8
	ldr r2, _081D6EE0 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x56
	orrs r0, r3
	ldr r1, _081D6EE4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	b _081D6EFA
	.align 2, 0
_081D6EDC: .4byte 0x00000109
_081D6EE0: .4byte 0xFFFF0000
_081D6EE4: .4byte 0x0000FFFF
_081D6EE8:
	ldr r2, _081D6F50 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x60
	orrs r0, r3
	ldr r1, _081D6F54 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xd
_081D6EFA:
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
	adds r4, r5, #0
	adds r4, #0xa4
	ldr r2, _081D6F58 @ =0x00004003
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
	adds r1, #0x9c
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _081D6F5C @ =FUN_081d6d28
	adds r0, r4, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081D6F50: .4byte 0xFFFF0000
_081D6F54: .4byte 0x0000FFFF
_081D6F58: .4byte 0x00004003
_081D6F5C: .4byte FUN_081d6d28

	thumb_func_start FUN_081d6f60
FUN_081d6f60: @ 0x081D6F60
	bx lr
	.align 2, 0

	thumb_func_start FUN_081d6f64
FUN_081d6f64: @ 0x081D6F64
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	movs r5, #0
	mov r6, r8
	adds r6, #0xa0
	movs r0, #1
	mov sb, r0
	movs r7, #0x8e
	lsls r7, r7, #1
_081D6F7C:
	mov r1, sb
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D6F8C
	movs r0, #1
	b _081D6F8E
_081D6F8C:
	movs r0, #0
_081D6F8E:
	cmp r0, #0
	bne _081D6FBE
	adds r0, r7, #0
	bl Malloc
	adds r4, r0, #0
	adds r1, r7, #0
	bl ClearMemory
	mov r1, sb
	lsls r1, r5
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	adds r0, r4, #0
	adds r0, #0xfc
	strh r5, [r0]
	lsls r1, r5, #2
	mov r0, r8
	adds r0, #0x20
	adds r0, r0, r1
	str r4, [r0]
	adds r0, r4, #0
	b _081D6FC6
_081D6FBE:
	adds r5, #1
	cmp r5, #0x1f
	ble _081D6F7C
	movs r0, #0
_081D6FC6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081d6fd4
FUN_081d6fd4: @ 0x081D6FD4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D7014 @ =0x0300019C
	ldr r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _081D6FEE
	b _081D7342
_081D6FEE:
	adds r2, r5, #0
	adds r2, #0xe7
	ldrb r1, [r2]
	movs r0, #1
	ands r0, r1
	mov sl, r2
	cmp r0, #0
	bne _081D7020
	movs r2, #4
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D7018
	movs r0, #1
	b _081D701A
	.align 2, 0
_081D7014: .4byte 0x0300019C
_081D7018:
	movs r0, #0
_081D701A:
	cmp r0, #0
	bne _081D7020
	b _081D72A0
_081D7020:
	adds r0, r5, #0
	adds r0, #0xf4
	movs r2, #0
	ldrsh r1, [r0, r2]
	adds r6, r0, #0
	cmp r1, #0
	ble _081D7030
	b _081D713A
_081D7030:
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x28
	str r0, [r1]
	adds r4, r5, #0
	adds r4, #0x8c
	mov r0, r8
	ldr r1, [r0, #0x18]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _081D707C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7084
_081D707C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7084:
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
	beq _081D70A8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D70B0
_081D70A8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D70B0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D70E8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r6, [r4, #7]
	cmp r0, r6
	blo _081D7120
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D70EC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D70E0
	ldrb r0, [r4, #5]
_081D70E0:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D70FC
	.align 2, 0
_081D70E8: .4byte 0x0000FFFF
_081D70EC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D70FC
	strh r1, [r4, #8]
_081D70FC:
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
	bne _081D7120
	movs r0, #1
	strb r0, [r4, #7]
_081D7120:
	adds r1, r5, #0
	adds r1, #0xfe
	movs r2, #0
	movs r0, #3
	strh r0, [r1]
	movs r6, #0x82
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #1
	strb r0, [r1]
	mov r0, sl
	strb r2, [r0]
	b _081D7342
_081D713A:
	movs r2, #1
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	mov sb, r1
	cmp r0, #0
	beq _081D7150
	movs r0, #1
	b _081D7152
_081D7150:
	movs r0, #0
_081D7152:
	adds r7, r0, #0
	cmp r7, #0
	beq _081D7194
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r1, [r0]
	adds r6, r0, #0
	cmp r1, #3
	beq _081D7188
	ldrh r4, [r6]
	cmp r4, #3
	ble _081D7174
	subs r0, r4, #6
	cmp r0, #0
	bge _081D7172
	rsbs r0, r0, #0
_081D7172:
	adds r4, r0, #0
_081D7174:
	adds r0, r5, #0
	adds r0, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r2, #0
	str r2, [sp]
	movs r3, #0
	bl FUN_08237040
	strh r4, [r6]
_081D7188:
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x22
	str r0, [r1]
	b _081D7342
_081D7194:
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0x24
	str r0, [r1]
	movs r1, #0
	ldrsh r0, [r6, r1]
	adds r1, r5, #0
	adds r1, #0xf8
	ldr r1, [r1]
	bl Div
	adds r4, r0, #0
	movs r0, #3
	subs r4, r0, r4
	adds r6, r5, #0
	adds r6, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	str r7, [sp]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, r4
	bge _081D72A0
	adds r4, r6, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _081D71FE
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7206
_081D71FE:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7206:
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
	beq _081D722A
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7232
_081D722A:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7232:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _081D7268 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D72A0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D726C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7262
	ldrb r0, [r4, #5]
_081D7262:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D727C
	.align 2, 0
_081D7268: .4byte 0x0000FFFF
_081D726C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D727C
	strh r1, [r4, #8]
_081D727C:
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
	bne _081D72A0
	movs r0, #1
	strb r0, [r4, #7]
_081D72A0:
	mov r6, sl
	ldrb r1, [r6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081D733C
	adds r0, r5, #0
	adds r0, #0xf4
	adds r2, r5, #0
	adds r2, #0xf6
	ldrh r4, [r0]
	movs r1, #0
	ldrsh r3, [r0, r1]
	movs r6, #0
	ldrsh r1, [r2, r6]
	adds r6, r0, #0
	adds r7, r2, #0
	cmp r3, r1
	bge _081D72CE
	adds r0, r4, #0
	adds r0, #0xa
	strh r0, [r6]
	b _081D7334
_081D72CE:
	movs r1, #4
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D72DE
	movs r0, #1
	b _081D72E0
_081D72DE:
	movs r0, #0
_081D72E0:
	cmp r0, #0
	beq _081D7334
	adds r0, r5, #0
	adds r0, #0x8c
	mov r2, r8
	ldr r1, [r2, #0x18]
	movs r4, #4
	str r4, [sp]
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	mov r1, sb
	ldr r0, [r1]
	ands r0, r4
	cmp r0, #0
	beq _081D7306
	movs r0, #1
	b _081D7308
_081D7306:
	movs r0, #0
_081D7308:
	cmp r0, #0
	beq _081D7326
	movs r2, #0
	ldrsh r0, [r6, r2]
	adds r1, r5, #0
	adds r1, #0xf8
	ldr r1, [r1]
	bl Div
	adds r4, r0, #0
	movs r0, #3
	subs r0, r0, r4
	adds r1, r5, #0
	adds r1, #0x94
	strh r0, [r1]
_081D7326:
	ldrh r0, [r7]
	strh r0, [r6]
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r5, r6
	movs r0, #0x30
	str r0, [r1]
_081D7334:
	ldr r0, _081D7354 @ =0x00000105
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
_081D733C:
	movs r0, #0
	mov r1, sl
	strb r0, [r1]
_081D7342:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D7354: .4byte 0x00000105

	thumb_func_start FUN_081d7358
FUN_081d7358: @ 0x081D7358
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r6, r0, #0
	mov ip, r6
	ldr r0, _081D7390 @ =0x0300019C
	ldr r7, [r0]
	cmp r7, #0
	bne _081D736E
	b _081D76B0
_081D736E:
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r2, #0x10
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D7394
	movs r0, #1
	b _081D7396
	.align 2, 0
_081D7390: .4byte 0x0300019C
_081D7394:
	movs r0, #0
_081D7396:
	cmp r0, #0
	bne _081D739C
	b _081D74B8
_081D739C:
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	mov r8, r4
	cmp r1, r0
	beq _081D73D2
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D73DE
_081D73D2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D73DE:
	str r0, [r2]
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
	beq _081D7404
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D740E
_081D7404:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D740E:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7448 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D748E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7452
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D744C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D7468
	.align 2, 0
_081D7448: .4byte 0x0000FFFF
_081D744C:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7466
_081D7452:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7466
	strh r1, [r4, #8]
	movs r2, #1
	b _081D7468
_081D7466:
	movs r2, #0
_081D7468:
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
	bne _081D7490
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7490
_081D748E:
	movs r2, #0
_081D7490:
	cmp r2, #0
	bne _081D7496
	b _081D76B0
_081D7496:
	ldr r1, [r7, #0x18]
	movs r0, #0
	str r0, [sp]
	mov r0, r8
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r1, r6, #0
	adds r1, #0x94
	movs r0, #3
	strh r0, [r1]
	adds r0, #0xfd
	adds r1, r6, r0
	movs r0, #0x21
	str r0, [r1]
	b _081D76B0
_081D74B8:
	movs r1, #2
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081D74C6
	movs r0, #1
	b _081D74C8
_081D74C6:
	movs r0, #0
_081D74C8:
	cmp r0, #0
	beq _081D75C2
	adds r4, r6, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
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
	beq _081D7500
	mov r2, ip
	ldr r0, [r2]
	movs r1, #4
	orrs r0, r1
	b _081D750C
_081D7500:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_081D750C:
	str r0, [r2]
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
	beq _081D7532
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _081D753C
_081D7532:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D753C:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7574 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D75AC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7578
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D756E
	ldrb r0, [r4, #5]
_081D756E:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7588
	.align 2, 0
_081D7574: .4byte 0x0000FFFF
_081D7578:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7588
	strh r1, [r4, #8]
_081D7588:
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
	bne _081D75AC
	movs r0, #1
	strb r0, [r4, #7]
_081D75AC:
	adds r0, r6, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #3
	bne _081D76B0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x24
	str r0, [r1]
	b _081D76B0
_081D75C2:
	adds r0, r6, #0
	bl FUN_081d6fd4
	movs r1, #1
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081D75D6
	movs r0, #1
	b _081D75D8
_081D75D6:
	movs r0, #0
_081D75D8:
	cmp r0, #0
	beq _081D76B0
	adds r4, r6, #0
	adds r4, #0x8c
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
	beq _081D760C
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D7614
_081D760C:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7614:
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
	beq _081D7638
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D7640
_081D7638:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7640:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7678 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D76B0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D767C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7670
	ldrb r0, [r4, #5]
_081D7670:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D768C
	.align 2, 0
_081D7678: .4byte 0x0000FFFF
_081D767C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D768C
	strh r1, [r4, #8]
_081D768C:
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
	bne _081D76B0
	movs r0, #1
	strb r0, [r4, #7]
_081D76B0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d76bc
FUN_081d76bc: @ 0x081D76BC
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	mov r7, ip
	ldr r5, [r0]
	movs r0, #2
	rsbs r0, r0, #0
	ands r5, r0
	mov r1, ip
	str r5, [r1]
	ldr r0, _081D770C @ =0x0300019C
	ldr r0, [r0]
	cmp r0, #0
	bne _081D76D8
	b _081D780E
_081D76D8:
	mov r4, ip
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r2, ip
	strh r0, [r2, #0x10]
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
	beq _081D7710
	movs r0, #4
	orrs r5, r0
	mov r0, ip
	str r5, [r0]
	b _081D771A
	.align 2, 0
_081D770C: .4byte 0x0300019C
_081D7710:
	movs r0, #5
	rsbs r0, r0, #0
	ands r5, r0
	mov r1, ip
	str r5, [r1]
_081D771A:
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
	beq _081D773C
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _081D7744
_081D773C:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7744:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D777C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D77B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7780
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7774
	ldrb r0, [r4, #5]
_081D7774:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7790
	.align 2, 0
_081D777C: .4byte 0x0000FFFF
_081D7780:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7790
	strh r1, [r4, #8]
_081D7790:
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
	bne _081D77B4
	movs r0, #1
	strb r0, [r4, #7]
_081D77B4:
	mov r2, ip
	adds r2, #0xe7
	ldrb r1, [r2]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _081D77F2
	mov r0, ip
	adds r0, #0xf4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _081D77EC
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0x28
	str r0, [r1]
	mov r1, ip
	adds r1, #0xfe
	movs r0, #4
	strh r0, [r1]
	movs r0, #0x82
	lsls r0, r0, #1
	add r0, ip
	strb r3, [r0]
	b _081D780E
_081D77EC:
	movs r0, #0
	strb r0, [r2]
	b _081D780E
_081D77F2:
	mov r2, ip
	adds r2, #0xf4
	mov r0, ip
	adds r0, #0xf6
	ldrh r3, [r2]
	movs r4, #0
	ldrsh r1, [r2, r4]
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	bge _081D780E
	adds r0, r3, #0
	adds r0, #0xa
	strh r0, [r2]
_081D780E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d7814
FUN_081d7814: @ 0x081D7814
	push {r4, lr}
	adds r3, r0, #0
	adds r0, #0xfe
	ldrh r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081D7856
	movs r2, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r3, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D783C
	movs r0, #1
	b _081D783E
_081D783C:
	movs r0, #0
_081D783E:
	cmp r0, #0
	beq _081D7856
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r3, r1
	bl FUN_082342a8
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081D7856:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d785c
FUN_081d785c: @ 0x081D785C
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081D78BC @ =0x0300019C
	ldr r7, [r0]
	cmp r7, #0
	bne _081D786C
	b _081D7A58
_081D786C:
	movs r0, #0x82
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081D788C
	adds r0, r5, #0
	bl FUN_081d7814
	movs r1, #0x83
	lsls r1, r1, #1
	adds r2, r5, r1
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	strb r1, [r4]
_081D788C:
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _081D78C0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D78C8
	.align 2, 0
_081D78BC: .4byte 0x0300019C
_081D78C0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D78C8:
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
	beq _081D78EC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D78F4
_081D78EC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D78F4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D792C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7972
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7936
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7930
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D794C
	.align 2, 0
_081D792C: .4byte 0x0000FFFF
_081D7930:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D794A
_081D7936:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D794A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D794C
_081D794A:
	movs r2, #0
_081D794C:
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
	bne _081D7974
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7974
_081D7972:
	movs r2, #0
_081D7974:
	movs r0, #0x83
	lsls r0, r0, #1
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1f
	bhi _081D7A4C
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _081D79BA
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081D7A48 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	add r1, sp, #4
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D79BA:
	ldrh r0, [r4]
	movs r1, #0xa
	bl Mod
	cmp r0, #0
	bne _081D79EA
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r0, sp, #4
	ldrh r0, [r0]
	adds r0, #0x40
	add r1, sp, #4
	strh r0, [r1]
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D79EA:
	ldrh r0, [r4]
	movs r1, #0x10
	bl Mod
	cmp r0, #0
	bne _081D7A18
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #4]
	str r1, [sp, #8]
	add r1, sp, #4
	ldrh r0, [r1, #4]
	adds r0, #0x20
	strh r0, [r1, #4]
	str r1, [sp]
	movs r0, #1
	movs r1, #0
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7A18:
	ldrh r0, [r4]
	movs r1, #7
	bl Mod
	cmp r0, #0
	bne _081D7A3C
	adds r4, r7, #0
	adds r4, #0xa4
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _081D7A3C
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4]
_081D7A3C:
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	b _081D7A56
	.align 2, 0
_081D7A48: .4byte 0xFFFF0000
_081D7A4C:
	cmp r2, #0
	beq _081D7A58
	adds r1, r5, #0
	adds r1, #0xfe
	movs r0, #0
_081D7A56:
	strh r0, [r1]
_081D7A58:
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081d7a60
FUN_081d7a60: @ 0x081D7A60
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081D7AC8 @ =0x0300019C
	ldr r4, [r0]
	cmp r4, #0
	bne _081D7A70
	b _081D7C9E
_081D7A70:
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r7, r5, #0
	adds r7, #0x8c
	cmp r0, #0
	bne _081D7A82
	b _081D7B96
_081D7A82:
	adds r0, r5, #0
	bl FUN_081d7814
	ldr r1, [r4, #0x1c]
	movs r0, #0
	str r0, [sp]
	adds r0, r7, #0
	movs r2, #4
	movs r3, #0
	bl FUN_08236fac
	adds r4, r7, #0
	ldrh r0, [r7, #8]
	lsls r0, r0, #1
	ldr r1, [r7]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r7, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D7ACC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7AD4
	.align 2, 0
_081D7AC8: .4byte 0x0300019C
_081D7ACC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7AD4:
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
	beq _081D7AF8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7B00
_081D7AF8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7B00:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7B38 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7B70
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7B3C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7B30
	ldrb r0, [r4, #5]
_081D7B30:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7B4C
	.align 2, 0
_081D7B38: .4byte 0x0000FFFF
_081D7B3C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7B4C
	strh r1, [r4, #8]
_081D7B4C:
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
	bne _081D7B70
	movs r0, #1
	strb r0, [r4, #7]
_081D7B70:
	movs r0, #0x83
	lsls r0, r0, #1
	adds r2, r5, r0
	movs r1, #0
	movs r0, #0
	strh r0, [r2]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #1
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7B96:
	adds r4, r7, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _081D7BC4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081D7BCC
_081D7BC4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7BCC:
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
	beq _081D7BF0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081D7BF8
_081D7BF0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D7BF8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D7C30 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D7C76
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7C3A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D7C34
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D7C50
	.align 2, 0
_081D7C30: .4byte 0x0000FFFF
_081D7C34:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D7C4E
_081D7C3A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D7C4E
	strh r1, [r4, #8]
	movs r2, #1
	b _081D7C50
_081D7C4E:
	movs r2, #0
_081D7C50:
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
	bne _081D7C78
	movs r0, #1
	strb r0, [r4, #7]
	b _081D7C78
_081D7C76:
	movs r2, #0
_081D7C78:
	cmp r2, #0
	beq _081D7C9E
	adds r1, r5, #0
	adds r1, #0xfe
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r5, #0
	adds r0, #0x1c
	str r0, [sp]
	movs r0, #3
	movs r1, #2
	movs r2, #0
	movs r3, #0x40
	bl FUN_08015c90
_081D7C9E:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081d7ca8
FUN_081d7ca8: @ 0x081D7CA8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	ldr r0, _081D7D18 @ =0x0300019C
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _081D7CC0
	b _081D7FD2
_081D7CC0:
	bl FUN_081d6f64
	adds r7, r0, #0
	cmp r7, #0
	bne _081D7CCC
	b _081D7FD2
_081D7CCC:
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #1
	str r1, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r2, r7, #0
	adds r2, #0x9c
	str r2, [sp, #0x14]
	cmp r0, #0
	beq _081D7D02
	bl Script_GetValue
	ldr r1, [sp, #0x14]
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0x9e
	strh r0, [r1]
	bl Script_GetValue
	adds r1, r7, #0
	adds r1, #0xa0
	strh r0, [r1]
_081D7D02:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081D7D1C
	bl Script_GetValue
	str r0, [sp, #8]
	bl Script_GetValue
	b _081D7D22
	.align 2, 0
_081D7D18: .4byte 0x0300019C
_081D7D1C:
	movs r2, #0
	str r2, [sp, #8]
	movs r0, #0
_081D7D22:
	str r0, [sp, #0xc]
	movs r0, #0x68
	movs r1, #0
	bl VM_GetKeywordValue
	movs r1, #0xf4
	adds r1, r1, r7
	mov sb, r1
	strh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xf6
	strh r0, [r1]
	mov r8, r7
	ldr r2, [sp, #0x14]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r4, r7, #0
	adds r4, #0x2c
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r6, r7, #0
	adds r6, #0x8c
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r6, #4]
	movs r3, #1
	adds r2, r3, #0
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	ands r0, r3
	mov r1, sb
	str r1, [sp, #0x18]
	mov sb, r4
	str r6, [sp, #0x10]
	cmp r2, r0
	beq _081D7D8C
	ldr r0, [r7]
	movs r1, #4
	orrs r0, r1
	b _081D7D94
_081D7D8C:
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D7D94:
	str r0, [r7]
	ldrb r0, [r6, #4]
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
	beq _081D7DBA
	mov r2, r8
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _081D7DC6
_081D7DBA:
	mov r1, r8
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, r8
_081D7DC6:
	str r0, [r2]
	ldrh r0, [r6, #0xe]
	adds r0, #1
	strh r0, [r6, #0xe]
	ldr r1, _081D7DFC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r6, #7]
	cmp r0, r1
	blo _081D7E34
	movs r0, #0
	strh r0, [r6, #0xe]
	ldrb r1, [r6, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D7E00
	ldrh r0, [r6, #8]
	cmp r0, #0
	bne _081D7DF6
	ldrb r0, [r6, #5]
_081D7DF6:
	subs r0, #1
	strh r0, [r6, #8]
	b _081D7E10
	.align 2, 0
_081D7DFC: .4byte 0x0000FFFF
_081D7E00:
	ldrh r0, [r6, #8]
	adds r0, #1
	strh r0, [r6, #8]
	ands r0, r2
	ldrb r2, [r6, #5]
	cmp r0, r2
	blo _081D7E10
	strh r1, [r6, #8]
_081D7E10:
	ldrh r0, [r6, #8]
	lsls r0, r0, #1
	ldr r1, [r6]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r6, #6]
	ldrb r1, [r6, #6]
	ldrh r0, [r6, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r6, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D7E34
	movs r0, #1
	strb r0, [r6, #7]
_081D7E34:
	mov r1, r8
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r0, #0x6d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r2, _081D7E60 @ =0x00000109
	adds r1, r7, r2
	movs r6, #0
	strb r0, [r1]
	ldrb r0, [r1]
	cmp r0, #0
	beq _081D7E64
	cmp r0, #1
	beq _081D7E94
	movs r0, #0x80
	lsls r0, r0, #1
	adds r4, r7, r0
	b _081D7EC8
	.align 2, 0
_081D7E60: .4byte 0x00000109
_081D7E64:
	ldr r1, _081D7E90 @ =0x00004FDA
	mov r0, sb
	bl Video_GetAuxSprite
	mov r2, sl
	ldr r1, [r2, #0x18]
	str r6, [sp]
	ldr r0, [sp, #0x10]
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	adds r0, r7, #0
	adds r0, #0xfe
	strh r4, [r0]
	movs r0, #3
	mov r1, r8
	strb r0, [r1, #7]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r4, r7, r2
	b _081D7EC8
	.align 2, 0
_081D7E90: .4byte 0x00004FDA
_081D7E94:
	ldr r1, _081D7F1C @ =0x0000863A
	mov r0, sb
	bl Video_GetAuxSprite
	mov r0, sl
	ldr r1, [r0, #0x1c]
	str r6, [sp]
	ldr r0, [sp, #0x10]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r1, r7, #0
	adds r1, #0xfe
	movs r3, #2
	movs r0, #2
	strh r0, [r1]
	movs r2, #4
	adds r0, #0xfe
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, r8
	strb r3, [r2, #7]
	adds r4, r1, #0
_081D7EC8:
	ldr r0, _081D7F20 @ =0x00000105
	adds r1, r7, r0
	movs r0, #0
	strb r0, [r1]
	ldr r1, [sp, #0x18]
	movs r2, #0
	ldrsh r0, [r1, r2]
	movs r1, #3
	bl Div
	adds r1, r7, #0
	adds r1, #0xf8
	str r0, [r1]
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	asrs r1, r1, #0x10
	ldr r0, [sp, #0xc]
	lsls r2, r0, #0x10
	asrs r2, r2, #0x10
	adds r0, r7, #0
	bl FUN_081d6eb8
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081D7F18
	cmp r1, #0
	blt _081D7F18
	ldr r0, _081D7F24 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081D7F18
	ldr r0, _081D7F28 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081D7F2C
_081D7F18:
	movs r2, #0
	b _081D7F3A
	.align 2, 0
_081D7F1C: .4byte 0x0000863A
_081D7F20: .4byte 0x00000105
_081D7F24: .4byte 0x030046A8
_081D7F28: .4byte 0x030046AC
_081D7F2C:
	ldr r0, _081D7FC4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r2, r0, r2
_081D7F3A:
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r3, [r7, #0x1e]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x18
	movs r1, #0
	str r1, [sp]
	movs r5, #0x80
	str r5, [sp, #4]
	adds r1, r2, #0
	movs r2, #0
	bl FUN_08234270
	movs r1, #0x20
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x50
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D7F70
	ldr r0, [r4]
	orrs r0, r5
	str r0, [r4]
_081D7F70:
	ldr r0, [sp, #0x14]
	bl FUN_08241574
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r7, r2
	strh r0, [r1]
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _081D7FC8
	movs r0, #0x84
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	adds r4, r7, #0
	adds r4, #0x48
	adds r0, r7, #0
	adds r0, #0xfc
	ldrh r1, [r0]
	adds r1, #0x6f
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	ldr r2, [sp, #0x14]
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_0823b46c
	adds r0, r4, #0
	bl FUN_08002a48
	b _081D7FD2
	.align 2, 0
_081D7FC4: .4byte 0x030046A4
_081D7FC8:
	movs r2, #0x84
	lsls r2, r2, #1
	adds r1, r7, r2
	movs r0, #0
	strb r0, [r1]
_081D7FD2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityC60F_Update
EntityC60F_Update: @ 0x081D7FE4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r1, r0, #0
	adds r3, r1, #0
	adds r3, #0x20
	adds r2, r1, #0
	adds r2, #0xa0
	ldr r0, [r2]
	cmp r0, #0
	beq _081D8092
	movs r5, #0
	adds r6, r2, #0
	adds r7, r1, #0
	adds r7, #0xa4
	ldr r0, _081D8018 @ =0x085AE118
	mov r8, r0
	adds r4, r3, #0
_081D8008:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D801C
	movs r0, #1
	b _081D801E
	.align 2, 0
_081D8018: .4byte 0x085AE118
_081D801C:
	movs r0, #0
_081D801E:
	cmp r0, #0
	beq _081D8086
	ldr r0, [r4]
	movs r1, #0x80
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D8038
	movs r0, #1
	b _081D803A
_081D8038:
	movs r0, #0
_081D803A:
	cmp r0, #0
	beq _081D8072
	ldr r0, [r4]
	movs r2, #0x85
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, _081D805C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081D8060
	movs r0, #1
	b _081D8062
	.align 2, 0
_081D805C: .4byte 0x030046A0
_081D8060:
	movs r0, #0
_081D8062:
	cmp r0, #0
	bne _081D8072
	ldr r0, [r4]
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _081D8086
_081D8072:
	ldr r0, [r4]
	adds r1, r0, #0
	adds r1, #0xfe
	movs r2, #0
	ldrsh r1, [r1, r2]
	lsls r1, r1, #2
	add r1, r8
	ldr r1, [r1]
	bl _call_via_r1
_081D8086:
	adds r4, #4
	adds r5, #1
	cmp r5, #0x1f
	ble _081D8008
	movs r0, #0xff
	strb r0, [r7]
_081D8092:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityC60F_Destroy
EntityC60F_Destroy: @ 0x081D80A0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r6, #0
_081D80A6:
	adds r0, r7, #0
	adds r0, #0xa0
	movs r1, #1
	lsls r1, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D80BA
	movs r0, #1
	b _081D80BC
_081D80BA:
	movs r0, #0
_081D80BC:
	cmp r0, #0
	beq _081D8122
	lsls r1, r6, #2
	adds r0, r7, #0
	adds r0, #0x20
	adds r0, r0, r1
	ldr r5, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	movs r1, #0x84
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081D80EC
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	bl FUN_08002a58
	adds r0, r4, #0
	bl FUN_0823b284
_081D80EC:
	movs r2, #0x20
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081D8102
	movs r0, #1
	b _081D8104
_081D8102:
	movs r0, #0
_081D8104:
	cmp r0, #0
	beq _081D811C
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	bl FUN_082342a8
	movs r1, #0x21
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
_081D811C:
	adds r0, r5, #0
	bl Free
_081D8122:
	adds r6, #1
	cmp r6, #0x1f
	ble _081D80A6
	ldr r1, _081D8134 @ =0x0300019C
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D8134: .4byte 0x0300019C

	thumb_func_start EntityC60F_Init
EntityC60F_Init: @ 0x081D8138
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _081D816C @ =0x0000922E
	ldr r1, _081D8170 @ =0x00001003
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x18]
	ldr r1, _081D8174 @ =0x0000931E
	adds r0, r5, #0
	bl GetFile
	str r0, [r4, #0x1c]
	ldr r0, _081D8178 @ =0x0300019C
	str r4, [r0]
	adds r1, r4, #0
	adds r1, #0xa0
	movs r0, #0
	str r0, [r1]
	adds r4, #0xa4
	movs r0, #0xff
	strb r0, [r4]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081D816C: .4byte 0x0000922E
_081D8170: .4byte 0x00001003
_081D8174: .4byte 0x0000931E
_081D8178: .4byte 0x0300019C

	thumb_func_start EntityC60F_Create
EntityC60F_Create: @ 0x081D817C
	push {r4, lr}
	movs r0, #0xa
	movs r1, #0xa8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081D81B0
	ldr r1, _081D81A8 @ =EntityC60F_Update
	ldr r2, _081D81AC @ =EntityC60F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityC60F_Init
	cmp r0, #0
	bge _081D81B0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081D81B2
	.align 2, 0
_081D81A8: .4byte EntityC60F_Update
_081D81AC: .4byte EntityC60F_Destroy
_081D81B0:
	adds r0, r4, #0
_081D81B2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_081d81b8
FUN_081d81b8: @ 0x081D81B8
	ldr r1, _081D81C0 @ =0x0300019C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081D81C0: .4byte 0x0300019C
