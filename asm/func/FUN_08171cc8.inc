	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r6, r0, #0
	str r1, [sp]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08171CF4 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08171CF8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08171CFA
	.align 2, 0
_08171CF4: .4byte 0x0000046D
_08171CF8:
	movs r0, #0
_08171CFA:
	cmp r0, #0
	beq _08171D06
	ldr r1, _08171D1C @ =0x00000FAD
	add r1, r8
	movs r0, #0
	strb r0, [r1]
_08171D06:
	ldr r0, _08171D1C @ =0x00000FAD
	add r0, r8
	ldrb r1, [r0]
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _08171D20
	ldrb r3, [r6, #5]
	b _08171D2A
	.align 2, 0
_08171D1C: .4byte 0x00000FAD
_08171D20:
	ldrb r0, [r6, #5]
	adds r3, r0, #0
	adds r3, #0x80
	movs r0, #0xff
	ands r3, r0
_08171D2A:
	movs r0, #0x7f
	ands r0, r1
	lsrs r4, r0, #4
	ldr r2, _08171D4C @ =gSineTable
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
	blt _08171D50
	asrs r1, r0, #0xc
	b _08171D56
	.align 2, 0
_08171D4C: .4byte gSineTable
_08171D50:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08171D56:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _08171D6E
	asrs r2, r0, #0xc
	b _08171D74
_08171D6E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08171D74:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldr r1, _08171D8C @ =0x00000FAD
	add r1, r8
	ldrb r0, [r1]
	adds r0, #0xc
	strb r0, [r1]
	movs r3, #0
	str r3, [sp, #4]
	movs r7, #0
	b _08171F2A
	.align 2, 0
_08171D8C: .4byte 0x00000FAD
_08171D90:
	lsls r2, r7, #3
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	movs r1, #2
	ldr r3, _08171DB0 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	mov sb, r2
	cmp r0, #0
	beq _08171DB4
	movs r0, #1
	b _08171DB6
	.align 2, 0
_08171DB0: .4byte 0x00000755
_08171DB4:
	movs r0, #0
_08171DB6:
	adds r1, r7, #1
	mov sl, r1
	cmp r0, #0
	bne _08171DC0
	b _08171F28
_08171DC0:
	mov r2, sb
	adds r0, r2, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	movs r1, #5
	ldr r3, _08171DE0 @ =0x00000755
	adds r0, r0, r3
	ldrb r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08171DE4
	movs r0, #1
	b _08171DE6
	.align 2, 0
_08171DE0: .4byte 0x00000755
_08171DE4:
	movs r0, #0
_08171DE6:
	adds r5, r0, #0
	adds r0, r7, #1
	mov sl, r0
	cmp r5, #0
	beq _08171DF2
	b _08171F28
_08171DF2:
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	mov r2, sb
	adds r1, r2, r7
	lsls r1, r1, #3
	adds r1, r1, r7
	lsls r1, r1, #2
	mov r3, r8
	adds r4, r3, r1
	ldr r2, _08171E44 @ =0x0000076C
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, _08171E48 @ =0x0000076E
	adds r0, r4, r3
	strh r5, [r0]
	movs r1, #0x14
	ldrsh r0, [r6, r1]
	mov r1, sl
	bl Div
	movs r2, #0xee
	lsls r2, r2, #3
	adds r1, r4, r2
	strh r0, [r1]
	ldr r3, [sp, #4]
	cmp r3, #0
	beq _08171E4C
	cmp r3, #1
	beq _08171EA4
	ldrh r1, [r6, #8]
	subs r2, #0xfc
	adds r0, r4, r2
	strh r1, [r0]
	ldrh r1, [r6, #0xc]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r4, r3
	b _08171F20
	.align 2, 0
_08171E44: .4byte 0x0000076C
_08171E48: .4byte 0x0000076E
_08171E4C:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _08171E6C @ =gSineTable
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	ldr r2, _08171E6C @ =gSineTable
	cmp r0, #0
	blt _08171E70
	asrs r3, r0, #0xc
	b _08171E76
	.align 2, 0
_08171E6C: .4byte gSineTable
_08171E70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08171E76:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08171EA0 @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x36
	muls r0, r1, r0
	cmp r0, #0
	bge _08171EFC
	b _08171F04
	.align 2, 0
_08171EA0: .4byte 0x00000674
_08171EA4:
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _08171EC8 @ =gSineTable
	adds r0, r0, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r3, #0
	cmp r0, #0
	blt _08171ECC
	asrs r3, r0, #0xc
	b _08171ED2
	.align 2, 0
_08171EC8: .4byte gSineTable
_08171ECC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08171ED2:
	mov r1, sb
	adds r0, r1, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #8]
	subs r1, r1, r3
	ldr r3, _08171F00 @ =0x00000674
	adds r0, r0, r3
	strh r1, [r0]
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	cmp r0, #0
	blt _08171F04
_08171EFC:
	asrs r2, r0, #0xc
	b _08171F0A
	.align 2, 0
_08171F00: .4byte 0x00000674
_08171F04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_08171F0A:
	mov r3, sb
	adds r0, r3, r7
	lsls r0, r0, #3
	adds r0, r0, r7
	lsls r0, r0, #2
	add r0, r8
	ldrh r1, [r6, #0xc]
	subs r1, r1, r2
	movs r2, #0xcf
	lsls r2, r2, #3
	adds r0, r0, r2
_08171F20:
	strh r1, [r0]
	ldr r3, [sp, #4]
	adds r3, #1
	str r3, [sp, #4]
_08171F28:
	mov r7, sl
_08171F2A:
	ldr r0, _08171F84 @ =0x00001012
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r7, r0
	bge _08171F38
	b _08171D90
_08171F38:
	ldr r3, _08171F88 @ =0x0000FFFF
	adds r0, r6, #0
	movs r1, #0x40
	movs r2, #0xc
	bl FUN_08177d34
	ldr r2, [sp]
	cmp r2, #0x3c
	ble _08171F74
	ldr r4, _08171F8C @ =FUN_08171f98
	movs r3, #0x23
	ldr r0, _08171F90 @ =0x0000046D
	adds r1, r6, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08171F94 @ =0x0000046B
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
_08171F74:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08171F84: .4byte 0x00001012
_08171F88: .4byte 0x0000FFFF
_08171F8C: .4byte FUN_08171f98
_08171F90: .4byte 0x0000046D
_08171F94: .4byte 0x0000046B
