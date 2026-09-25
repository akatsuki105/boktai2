	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080dc4a4
FUN_080dc4a4: @ 0x080DC4A4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dc4a8
FUN_080dc4a8: @ 0x080DC4A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r2, #0
	mov r4, sp
	adds r3, r1, #0
	adds r3, #0xc
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r3, r0, #0
	adds r0, #0x10
	movs r5, #0xff
	ands r0, r5
	asrs r0, r0, #5
	lsls r3, r0, #5
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _080DC570
	add r2, sp, #8
	ldr r0, _080DC514 @ =0x085B0A08
	adds r1, r3, #0
	adds r1, #0x40
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r1, [r1, r4]
	lsls r1, r1, #2
	adds r4, r2, #0
	adds r5, r0, #0
	cmp r1, #0
	blt _080DC518
	asrs r1, r1, #0xc
	b _080DC51E
	.align 2, 0
_080DC514: .4byte 0x085B0A08
_080DC518:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DC51E:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _080DC53C
	asrs r0, r0, #0xc
	b _080DC542
_080DC53C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DC542:
	strh r0, [r2, #4]
	ldr r0, _080DC56C @ =0x0000FFFC
	strh r0, [r4, #2]
	add r0, sp, #8
	ldrh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r0, [r4, #2]
	movs r3, #0x8f
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r4, #4]
	movs r4, #0x90
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	b _080DC5F2
	.align 2, 0
_080DC56C: .4byte 0x0000FFFC
_080DC570:
	add r2, sp, #8
	movs r7, #0x12
	ldr r0, _080DC594 @ =0x085B0A08
	adds r1, r3, #0
	adds r1, #0x40
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r1, [r1, r4]
	muls r1, r7, r1
	adds r4, r2, #0
	adds r5, r0, #0
	cmp r1, #0
	blt _080DC598
	asrs r1, r1, #0xc
	b _080DC59E
	.align 2, 0
_080DC594: .4byte 0x085B0A08
_080DC598:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DC59E:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080DC5BA
	asrs r0, r0, #0xc
	b _080DC5C0
_080DC5BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DC5C0:
	strh r0, [r2, #4]
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r4, #2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0x90
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r4, #4]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_080DC5F2:
	ldrh r0, [r6, #0x1e]
	adds r0, #1
	strh r0, [r6, #0x1e]
	ldr r0, _080DC610 @ =0x00000131
	adds r1, r6, r0
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC610: .4byte 0x00000131

	thumb_func_start FUN_080dc614
FUN_080dc614: @ 0x080DC614
	push {lr}
	adds r3, r2, #0
	mov ip, r3
	movs r1, #4
	ldr r2, [r0, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _080DC62E
	movs r0, #0x99
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	b _080DC64A
_080DC62E:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _080DC64C
	movs r1, #0x99
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	cmp r0, #0x59
	bls _080DC64C
	movs r0, #0x9f
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
_080DC64A:
	strh r0, [r1]
_080DC64C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080dc650
FUN_080dc650: @ 0x080DC650
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r2, _080DC74C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _080DC750 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sp
	adds r0, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r6, sp, #0x14
	ldr r0, [r6, #4]
	ands r0, r2
	str r0, [r6, #4]
	movs r1, #0x3c
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	ldrh r1, [r2]
	ldr r2, _080DC754 @ =0x00002003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, sb
	movs r3, #0
	bl Hitbox_Init
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	mov r8, r1
	str r1, [sp]
	str r1, [sp, #4]
	mov r0, sb
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r5, r7, #0
	adds r5, #0x1c
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080DC758 @ =FUN_080dc4a8
	mov r0, sb
	adds r2, r7, #0
	bl Hitbox_SetHandler
	movs r1, #0x40
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x80
	ldr r2, [sp, #0x1c]
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	mov r1, r8
	strh r1, [r6]
	strh r0, [r6, #2]
	strh r1, [r6, #4]
	adds r4, r7, #0
	adds r4, #0x8c
	mov r2, sl
	ldrh r1, [r2]
	ldr r2, _080DC75C @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080DC760 @ =FUN_080dc614
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC74C: .4byte 0xFFFF0000
_080DC750: .4byte 0x0000FFFF
_080DC754: .4byte 0x00002003
_080DC758: .4byte FUN_080dc4a8
_080DC75C: .4byte 0x00004001
_080DC760: .4byte FUN_080dc614

	thumb_func_start FUN_080dc764
FUN_080dc764: @ 0x080DC764
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r1, _080DC788 @ =0x00000F68
	adds r4, r0, r1
	movs r5, #1
	adds r2, r0, #0
	adds r2, #0x38
	movs r6, #0xa2
	lsls r6, r6, #1
_080DC776:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DC78C
	movs r0, #1
	b _080DC78E
	.align 2, 0
_080DC788: .4byte 0x00000F68
_080DC78C:
	movs r0, #0
_080DC78E:
	cmp r0, #0
	bne _080DC7AC
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _080DC7A8 @ =0x0000012F
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r2, #0
	b _080DC7B6
	.align 2, 0
_080DC7A8: .4byte 0x0000012F
_080DC7AC:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #0xb
	ble _080DC776
	movs r0, #0
_080DC7B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc7bc
FUN_080dc7bc: @ 0x080DC7BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x14]
	adds r6, r1, #0
	mov sl, r6
	movs r0, #0x98
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080DC7F2
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r3]
_080DC7F2:
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r0, [sp, #0x24]
	cmp r2, #0
	blt _080DC81C
	cmp r1, #0
	blt _080DC81C
	ldr r0, _080DC820 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080DC81C
	ldr r0, _080DC824 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DC828
_080DC81C:
	movs r0, #0
	b _080DC836
	.align 2, 0
_080DC820: .4byte 0x030046A8
_080DC824: .4byte 0x030046AC
_080DC828:
	ldr r0, _080DC870 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080DC836:
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	movs r5, #0x96
	lsls r5, r5, #1
	adds r5, r5, r6
	mov r8, r5
	ldrh r5, [r5]
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _080DC8AC
	mov r0, sl
	movs r2, #0x1e
	ldrsh r7, [r0, r2]
	ldrh r5, [r1]
	mov r4, sl
	adds r4, #0x1c
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	adds r3, r4, #0
	cmp r0, #0
	beq _080DC874
	adds r0, #4
	b _080DC880
	.align 2, 0
_080DC870: .4byte 0x030046A4
_080DC874:
	ldr r0, _080DC894 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DC880:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DC898
	cmp r2, #2
	beq _080DC89C
	b _080DC8A0
	.align 2, 0
_080DC894: .4byte 0x030046A4
_080DC898:
	ldrb r0, [r4, #4]
	b _080DC89E
_080DC89C:
	ldrb r0, [r4]
_080DC89E:
	subs r1, r1, r0
_080DC8A0:
	cmp r7, r1
	bls _080DC912
	movs r5, #0x8f
	lsls r5, r5, #1
	adds r1, r6, r5
	b _080DC90C
_080DC8AC:
	add r3, sp, #4
	mov r4, sl
	adds r4, #0x1c
	movs r7, #0x92
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	mov r7, sl
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
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
	ldr r0, _080DC940 @ =0x0003FFFF
	adds r3, r4, #0
	cmp r1, r0
	ble _080DC8FE
	movs r7, #0xa0
	lsls r7, r7, #1
	adds r0, r6, r7
	ldrh r0, [r0]
	cmp r0, #8
	bls _080DC912
_080DC8FE:
	movs r0, #1
	orrs r0, r5
	mov r1, r8
	strh r0, [r1]
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r1, r6, r2
_080DC90C:
	ldrh r0, [r1]
	subs r0, #4
	strh r0, [r1]
_080DC912:
	movs r5, #0x9a
	lsls r5, r5, #1
	adds r0, r6, r5
	mov r8, r3
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r4, r6, r7
	ldrh r0, [r0]
	str r0, [sp, #0x18]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	ldr r0, [sp, #0x18]
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DC944
	adds r0, #4
	b _080DC952
	.align 2, 0
_080DC940: .4byte 0x0003FFFF
_080DC944:
	ldr r0, _080DC968 @ =0x030046A4
	ldr r1, [r0]
	ldr r3, [sp, #0x18]
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DC952:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DC96C
	cmp r2, #2
	beq _080DC972
	b _080DC978
	.align 2, 0
_080DC968: .4byte 0x030046A4
_080DC96C:
	mov r5, r8
	ldrb r0, [r5, #4]
	b _080DC976
_080DC972:
	mov r7, r8
	ldrb r0, [r7]
_080DC976:
	subs r1, r1, r0
_080DC978:
	str r1, [sp, #0x1c]
	movs r0, #0
	ldrsh r2, [r4, r0]
	movs r1, #4
	ldrsh r0, [r4, r1]
	adds r0, r2, r0
	movs r3, #2
	ldrsh r1, [r4, r3]
	adds r5, r6, #0
	adds r5, #0x8c
	cmn r0, r1
	bne _080DC992
	b _080DCBE4
_080DC992:
	mov r5, r8
	movs r7, #2
	ldrsh r0, [r5, r7]
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	bgt _080DCA02
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	movs r5, #0
	strh r0, [r4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r4, #4]
	movs r7, #0
	ldrsh r0, [r4, r7]
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	bge _080DC9E6
	rsbs r0, r0, #0
_080DC9E6:
	cmp r0, #2
	bgt _080DC9F2
	strh r5, [r4]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	b _080DC9FA
_080DC9F2:
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080DC9FA:
	mov r5, sp
	ldrh r7, [r5, #0x1c]
	mov r5, r8
	strh r7, [r5, #2]
_080DCA02:
	ldrh r0, [r4]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080DCA68 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0xc]
	ldrh r1, [r4, #2]
	mov r5, r8
	ldrh r5, [r5, #2]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	ldr r0, _080DCA6C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r4, #4]
	mov r7, r8
	ldrh r7, [r7, #4]
	adds r1, r1, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0xc
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080DCA64
	cmp r1, #0
	blt _080DCA64
	ldr r0, _080DCA70 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080DCA64
	ldr r0, _080DCA74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DCA78
_080DCA64:
	movs r5, #0
	b _080DCA86
	.align 2, 0
_080DCA68: .4byte 0xFFFF0000
_080DCA6C: .4byte 0x0000FFFF
_080DCA70: .4byte 0x030046A8
_080DCA74: .4byte 0x030046AC
_080DCA78:
	ldr r0, _080DCA98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_080DCA86:
	add r7, sp, #0xc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCA9C
	adds r0, #4
	b _080DCAA8
	.align 2, 0
_080DCA98: .4byte 0x030046A4
_080DCA9C:
	ldr r0, _080DCABC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCAA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DCAC0
	cmp r2, #2
	beq _080DCAC4
	b _080DCAC8
	.align 2, 0
_080DCABC: .4byte 0x030046A4
_080DCAC0:
	ldrb r0, [r7, #4]
	b _080DCAC6
_080DCAC4:
	ldrb r0, [r7]
_080DCAC6:
	subs r1, r1, r0
_080DCAC8:
	mov sb, r1
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCADA
	adds r0, #4
	b _080DCAE6
_080DCADA:
	ldr r0, _080DCB04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCAE6:
	ldrh r7, [r0, #2]
	ldr r0, [sp, #0x18]
	cmp r0, r5
	beq _080DCB4A
	ldr r1, [sp, #0x1c]
	cmp r1, sb
	blt _080DCB1E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCB08
	adds r0, #4
	b _080DCB14
	.align 2, 0
_080DCB04: .4byte 0x030046A4
_080DCB08:
	ldr r0, _080DCBB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCB14:
	ldrh r0, [r0, #2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080DCB4A
_080DCB1E:
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4]
	movs r3, #4
	ldrsh r1, [r4, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #4]
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080DCB4A:
	mov r5, sb
	cmp r5, #0
	ble _080DCB58
	movs r0, #0x40
	ands r7, r0
	cmp r7, #0
	beq _080DCBC4
_080DCB58:
	mov r7, sp
	movs r1, #0xe
	ldrsh r0, [r7, r1]
	cmp r0, sb
	bgt _080DCBC4
	ldr r0, _080DCBB8 @ =0x0300016C
	ldr r2, [r0]
	ldr r3, _080DCBBC @ =0x0000012F
	adds r7, r6, r3
	movs r0, #0
	ldrsb r0, [r7, r0]
	ldr r5, _080DCBC0 @ =0x00000F68
	adds r2, r2, r5
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0xdc
	bl ParticleShadow_Remove
	adds r5, r6, #0
	adds r5, #0x8c
	adds r0, r5, #0
	bl Hitbox_Unregister
	movs r0, #0xff
	strb r0, [r7]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	movs r3, #0x99
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	b _080DCBE4
	.align 2, 0
_080DCBB4: .4byte 0x030046A4
_080DCBB8: .4byte 0x0300016C
_080DCBBC: .4byte 0x0000012F
_080DCBC0: .4byte 0x00000F68
_080DCBC4:
	ldrh r0, [r4]
	mov r5, r8
	ldrh r5, [r5]
	adds r0, r0, r5
	mov r7, r8
	strh r0, [r7]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r7, #4]
	adds r5, r6, #0
	adds r5, #0x8c
_080DCBE4:
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r3, _080DCC00 @ =0x00000131
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DCC04
	subs r0, #1
	strb r0, [r1]
	b _080DCC18
	.align 2, 0
_080DCC00: .4byte 0x00000131
_080DCC04:
	adds r4, r6, #0
	adds r4, #0x3c
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_080DCC18:
	movs r5, #0x9d
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrb r1, [r0]
	str r0, [sp, #0x20]
	cmp r1, #0
	beq _080DCC32
	subs r0, r1, #1
	ldr r7, [sp, #0x20]
	strb r0, [r7]
	adds r4, r6, #0
	adds r4, #0x2c
	b _080DCCB0
_080DCC32:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080DCC42
	movs r7, #3
	b _080DCC54
_080DCC42:
	cmp r0, #0x31
	bhi _080DCC4A
	movs r7, #2
	b _080DCC54
_080DCC4A:
	adds r4, r6, #0
	adds r4, #0x2c
	cmp r0, #0x59
	bhi _080DCCB0
	movs r7, #1
_080DCC54:
	ldrh r2, [r6, #0x3a]
	mov r8, r2
	ldrh r3, [r6, #0x34]
	mov sb, r3
	ldr r0, _080DCC80 @ =0x0000013B
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #1
	bne _080DCC84
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r2, [sp, #0x14]
	ldr r1, [r2, #0x34]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	movs r0, #2
	b _080DCC9C
	.align 2, 0
_080DCC80: .4byte 0x0000013B
_080DCC84:
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r3, [sp, #0x14]
	ldr r1, [r3, #0x34]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
_080DCC9C:
	strb r0, [r5]
	mov r5, r8
	strh r5, [r6, #0x3a]
	mov r0, sb
	strh r0, [r6, #0x34]
	ldr r0, _080DCCE4 @ =0x085AD338
	adds r0, r7, r0
	ldrb r0, [r0]
	ldr r1, [sp, #0x20]
	strb r0, [r1]
_080DCCB0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r2, sl
	strh r0, [r2, #0x10]
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
	beq _080DCCE8
	mov r3, sl
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _080DCCF4
	.align 2, 0
_080DCCE4: .4byte 0x085AD338
_080DCCE8:
	mov r7, sl
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
_080DCCF4:
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
	beq _080DCD1C
	mov r1, sl
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, sl
	str r0, [r2]
	b _080DCD28
_080DCD1C:
	mov r3, sl
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080DCD28:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _080DCD5C @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r7, [r4, #7]
	cmp r0, r7
	blo _080DCD94
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DCD60
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DCD56
	ldrb r0, [r4, #5]
_080DCD56:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DCD70
	.align 2, 0
_080DCD5C: .4byte 0x0000FFFF
_080DCD60:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DCD70
	strh r1, [r4, #8]
_080DCD70:
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
	bne _080DCD94
	movs r0, #1
	strb r0, [r4, #7]
_080DCD94:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r5, #0x99
	lsls r5, r5, #1
	adds r1, r6, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _080DCDB2
	subs r0, #1
	strh r0, [r1]
	b _080DCDC6
_080DCDB2:
	movs r7, #0x97
	lsls r7, r7, #1
	adds r1, r6, r7
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_080DCDC6:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dcdd8
FUN_080dcdd8: @ 0x080DCDD8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r1, #0
	movs r0, #0x98
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080DCE2A
	adds r0, r5, #0
	adds r0, #0x1c
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r3, [r1]
	movs r4, #0
	str r4, [sp]
	movs r1, #0x20
	bl Entity080d84f8_Create
	movs r7, #0x1c
	ldrsh r0, [r5, r7]
	movs r2, #0x20
	ldrsh r1, [r5, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #1
	str r3, [sp]
	movs r7, #0x9e
	lsls r7, r7, #1
	adds r3, r5, r7
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	strb r4, [r6]
_080DCE2A:
	ldr r0, _080DCE80 @ =0x0300016C
	ldr r2, [r0]
	ldr r0, _080DCE84 @ =0x0000012F
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _080DCE88 @ =0x00000F68
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r2, #0x97
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0xdc
	bl ParticleShadow_Remove
	adds r0, r5, #0
	adds r0, #0x8c
	bl Hitbox_Unregister
	movs r0, #0xff
	strb r0, [r6]
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r7, #0x99
	lsls r7, r7, #1
	adds r0, r5, r7
	strh r4, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DCE80: .4byte 0x0300016C
_080DCE84: .4byte 0x0000012F
_080DCE88: .4byte 0x00000F68

	thumb_func_start FUN_080dce8c
FUN_080dce8c: @ 0x080DCE8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	mov r8, r1
	adds r4, r2, #0
	mov sl, r3
	ldr r0, _080DCEE4 @ =0x0300016C
	ldr r5, [r0]
	cmp r5, #0
	bne _080DCEB2
	bl Entity080dd1f8_Create
	adds r5, r0, #0
	cmp r5, #0
	beq _080DCEDE
_080DCEB2:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DCEE8 @ =0x030047A4
	ldr r1, _080DCEEC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DCEDE
	ldr r0, _080DCEF0 @ =0x03002BC0
	ldr r7, [r0]
	movs r0, #4
	ands r7, r0
	cmp r7, #0
	bne _080DCEDE
	adds r0, r5, #0
	bl FUN_080dc764
	adds r6, r0, #0
	cmp r6, #0
	bne _080DCEF4
_080DCEDE:
	movs r0, #0
	b _080DD0A2
	.align 2, 0
_080DCEE4: .4byte 0x0300016C
_080DCEE8: .4byte 0x030047A4
_080DCEEC: .4byte 0x030047A0
_080DCEF0: .4byte 0x03002BC0
_080DCEF4:
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #1
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r7, [r0]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	subs r3, #8
	adds r2, r6, r3
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sl
	strh r2, [r0]
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sp
	ldrh r2, [r2, #0x2c]
	strh r2, [r0]
	subs r3, #6
	adds r0, r6, r3
	mov r1, sp
	ldrh r1, [r1, #0x2c]
	strh r1, [r0]
	ldr r2, _080DCFC8 @ =0x00000131
	adds r1, r6, r2
	movs r0, #0x1e
	strb r0, [r1]
	adds r3, #0xa
	adds r1, r6, r3
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	ldr r1, _080DCFCC @ =0x0000013B
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	mov r8, r6
	ldr r3, [sp, #4]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, [r5, #0x34]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _080DCFD0
	ldr r0, [r6]
	movs r3, #4
	orrs r0, r3
	b _080DCFD8
	.align 2, 0
_080DCFC8: .4byte 0x00000131
_080DCFCC: .4byte 0x0000013B
_080DCFD0:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DCFD8:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DD002
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080DD00E
_080DD002:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080DD00E:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DD044 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DD07C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DD048
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DD03C
	ldrb r0, [r4, #5]
_080DD03C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DD058
	.align 2, 0
_080DD044: .4byte 0x0000FFFF
_080DD048:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DD058
	strh r1, [r4, #8]
_080DD058:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _080DD07C
	movs r0, #1
	strb r0, [r4, #7]
_080DD07C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	strb r1, [r3, #7]
	adds r0, r6, #0
	adds r0, #0xdc
	mov r1, r8
	adds r1, #0x1c
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dc650
	adds r0, r6, #0
_080DD0A2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080dd1f8_Update
Entity080dd1f8_Update: @ 0x080DD0B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r3, r7, #0
	adds r3, #0x38
	ldr r1, _080DD114 @ =0x00000F68
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DD14C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DD118 @ =0x030047A4
	ldr r1, _080DD11C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DD14C
	movs r1, #4
	ldr r0, _080DD120 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080DD14C
	movs r6, #0
	ldr r2, _080DD114 @ =0x00000F68
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _080DD124 @ =0x085AD33C
	mov sb, r0
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r5, r7, r1
	adds r4, r3, #0
_080DD100:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080DD128
	movs r0, #1
	b _080DD12A
	.align 2, 0
_080DD114: .4byte 0x00000F68
_080DD118: .4byte 0x030047A4
_080DD11C: .4byte 0x030047A0
_080DD120: .4byte 0x03002BC0
_080DD124: .4byte 0x085AD33C
_080DD128:
	movs r0, #0
_080DD12A:
	cmp r0, #0
	beq _080DD13E
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_080DD13E:
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0xb
	ble _080DD100
_080DD14C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080dd1f8_Destroy
Entity080dd1f8_Destroy: @ 0x080DD15C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r1, _080DD180 @ =0x00000F68
	adds r7, r0, r1
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r5, r0, r1
	adds r4, r0, #0
	adds r4, #0x38
_080DD16E:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DD184
	movs r0, #1
	b _080DD186
	.align 2, 0
_080DD180: .4byte 0x00000F68
_080DD184:
	movs r0, #0
_080DD186:
	cmp r0, #0
	beq _080DD196
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	bl ParticleShadow_Remove
_080DD196:
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0xb
	ble _080DD16E
	movs r1, #0
	ldr r0, _080DD1B4 @ =0x0300016C
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1B4: .4byte 0x0300016C

	thumb_func_start Entity080dd1f8_Init
Entity080dd1f8_Init: @ 0x080DD1B8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _080DD1E4 @ =0x0000E74B
	bl Video_GetAuxSprite
	ldr r0, _080DD1E8 @ =0x0000922E
	ldr r1, _080DD1EC @ =0x0000871C
	bl GetFile
	str r0, [r4, #0x34]
	ldr r0, _080DD1F0 @ =0x00000F68
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _080DD1F4 @ =0x0300016C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1E4: .4byte 0x0000E74B
_080DD1E8: .4byte 0x0000922E
_080DD1EC: .4byte 0x0000871C
_080DD1F0: .4byte 0x00000F68
_080DD1F4: .4byte 0x0300016C

	thumb_func_start Entity080dd1f8_Create
Entity080dd1f8_Create: @ 0x080DD1F8
	push {r4, lr}
	ldr r0, _080DD22C @ =0x0300016C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD23E
	ldr r1, _080DD230 @ =0x00000F6C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DD23C
	ldr r1, _080DD234 @ =Entity080dd1f8_Update
	ldr r2, _080DD238 @ =0x080DD15D
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080dd1f8_Init
	cmp r0, #0
	bge _080DD23C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DD23E
	.align 2, 0
_080DD22C: .4byte 0x0300016C
_080DD230: .4byte 0x00000F6C
_080DD234: .4byte Entity080dd1f8_Update
_080DD238: .4byte 0x080DD15D
_080DD23C:
	adds r0, r4, #0
_080DD23E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dd244
FUN_080dd244: @ 0x080DD244
	ldr r1, _080DD24C @ =0x0300016C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DD24C: .4byte 0x0300016C

	thumb_func_start FUN_080dd250
FUN_080dd250: @ 0x080DD250
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _080DD274 @ =0x0300016C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DD30C
	adds r2, r0, #0
	adds r2, #0x38
	ldr r3, _080DD278 @ =0x00000F68
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bne _080DD286
	b _080DD30C
	.align 2, 0
_080DD274: .4byte 0x0300016C
_080DD278: .4byte 0x00000F68
_080DD27C:
	adds r0, r3, #0
	adds r1, r2, #0
	bl ArcTan2_8
	b _080DD310
_080DD286:
	movs r5, #0
	adds r7, r1, #0
	mov r4, sp
	mov ip, r2
	movs r0, #0xa2
	lsls r0, r0, #1
	mov r8, r0
_080DD294:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DD2A4
	movs r0, #1
	b _080DD2A6
_080DD2A4:
	movs r0, #0
_080DD2A6:
	cmp r0, #0
	beq _080DD304
	ldr r0, _080DD31C @ =0x0000012F
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080DD304
	movs r0, #0x99
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #0
	beq _080DD304
	movs r0, #0x97
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #2
	beq _080DD304
	mov r1, ip
	ldrh r0, [r1, #0x1c]
	ldrh r1, [r6]
	subs r0, r0, r1
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0x1e]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #0x20]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r0, #0
	ldrsh r3, [r4, r0]
	adds r1, r3, #0
	muls r1, r3, r1
	movs r0, #4
	ldrsh r2, [r4, r0]
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	ldr r0, _080DD320 @ =0x00018FFF
	cmp r1, r0
	ble _080DD27C
_080DD304:
	add ip, r8
	adds r5, #1
	cmp r5, #0xb
	ble _080DD294
_080DD30C:
	movs r0, #1
	rsbs r0, r0, #0
_080DD310:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD31C: .4byte 0x0000012F
_080DD320: .4byte 0x00018FFF
