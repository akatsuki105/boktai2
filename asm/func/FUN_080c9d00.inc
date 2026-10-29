	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r4, r0, #0
	mov r8, r4
	ldr r0, _080C9D68 @ =0x0000190E
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080C9D84
	ldr r2, _080C9D6C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	movs r1, #0x80
	orrs r0, r1
	ldr r1, _080C9D70 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _080C9D74 @ =0xFF800000
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r1, #0xc0
	lsls r1, r1, #1
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r1, #0x28
	adds r0, r4, r1
	ldrh r1, [r3]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r3, r4, r2
	add r5, sp, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
	adds r0, r4, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	cmp r0, #0x1f
	beq _080C9D60
	cmp r0, #0x24
	bne _080C9D7C
_080C9D60:
	ldr r0, _080C9D78 @ =0x0000022E
	bl PlaySound_082406e0
	b _080C9D84
	.align 2, 0
_080C9D68: .4byte 0x0000190E
_080C9D6C: .4byte 0xFFFF0000
_080C9D70: .4byte 0x0000FFFF
_080C9D74: .4byte 0xFF800000
_080C9D78: .4byte 0x0000022E
_080C9D7C:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080C9D84:
	ldr r0, _080C9DD4 @ =0x00001910
	adds r3, r4, r0
	ldrh r0, [r3]
	cmp r0, #0
	beq _080C9DE8
	ldr r2, _080C9DD8 @ =0x0000FF80
	add r0, sp, #8
	strh r2, [r0]
	adds r1, r0, #0
	strh r2, [r1, #2]
	movs r0, #0xc0
	lsls r0, r0, #1
	strh r0, [r1, #4]
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r1, [r3]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r3, r4, r2
	add r5, sp, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
	adds r0, r4, #0
	adds r0, #0xa3
	ldrb r0, [r0]
	subs r0, #0x21
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080C9DE0
	ldr r0, _080C9DDC @ =0x0000022E
	bl PlaySound_082406e0
	b _080C9DE8
	.align 2, 0
_080C9DD4: .4byte 0x00001910
_080C9DD8: .4byte 0x0000FF80
_080C9DDC: .4byte 0x0000022E
_080C9DE0:
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080C9DE8:
	ldr r0, _080C9EE8 @ =0x00001914
	adds r0, r0, r4
	mov sb, r0
	ldrh r0, [r0]
	cmp r0, #0
	beq _080C9E28
	movs r2, #0
	add r0, sp, #8
	strh r2, [r0]
	adds r1, r0, #0
	ldr r0, _080C9EEC @ =0x0000FF80
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	movs r0, #0x9f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r1, #0xfc
	lsls r1, r1, #1
	adds r0, r4, r1
	mov r2, sb
	ldrh r1, [r2]
	movs r5, #0xbe
	lsls r5, r5, #2
	adds r3, r4, r5
	add r2, sp, #8
	str r2, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
_080C9E28:
	ldr r5, _080C9EF0 @ =0x00001912
	adds r7, r4, r5
	ldrh r0, [r7]
	cmp r0, #0
	beq _080C9E66
	movs r1, #0
	add r0, sp, #8
	strh r1, [r0]
	adds r1, r0, #0
	ldr r0, _080C9EEC @ =0x0000FF80
	strh r0, [r1, #2]
	movs r0, #0xa0
	lsls r0, r0, #2
	strh r0, [r1, #4]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r7]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r3, r4, r2
	add r5, sp, #8
	str r5, [sp]
	movs r2, #1
	str r2, [sp, #4]
	movs r2, #0
	bl CreateDamageNumber
	ldr r0, _080C9EF4 @ =0x0000022E
	bl PlaySound_082406e0
_080C9E66:
	ldr r0, _080C9EF8 @ =0x0000190E
	adds r3, r4, r0
	ldrh r0, [r3]
	ldr r1, _080C9EFC @ =0x00001910
	adds r2, r4, r1
	ldrh r1, [r2]
	adds r0, r0, r1
	ldrh r5, [r7]
	adds r0, r0, r5
	mov r5, sb
	ldrh r1, [r5]
	adds r5, r0, r1
	movs r6, #0
	strh r6, [r3]
	strh r6, [r2]
	strh r6, [r7]
	mov r0, sb
	strh r6, [r0]
	cmp r5, #0
	bgt _080C9E90
	b _080C9FB0
_080C9E90:
	mov r1, r8
	adds r1, #0x90
	ldrh r0, [r1]
	subs r0, r0, r5
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _080C9F0C
	strh r6, [r1]
	movs r2, #2
	adds r1, #8
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080C9F00 @ =FUN_080c994c
	movs r0, #0x28
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	mov r1, r8
	adds r1, #0xa9
	movs r0, #1
	strb r0, [r1]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	mov r0, r8
	bl FUN_08022fb8
	ldr r5, _080C9F04 @ =0x000025D0
	adds r0, r4, r5
	ldr r0, [r0]
	ldr r2, _080C9F08 @ =0x000025CE
	adds r1, r4, r2
	ldrh r1, [r1]
	bl Player_AddWeaponExp
	movs r0, #1
	b _080C9FB2
	.align 2, 0
_080C9EE8: .4byte 0x00001914
_080C9EEC: .4byte 0x0000FF80
_080C9EF0: .4byte 0x00001912
_080C9EF4: .4byte 0x0000022E
_080C9EF8: .4byte 0x0000190E
_080C9EFC: .4byte 0x00001910
_080C9F00: .4byte FUN_080c994c
_080C9F04: .4byte 0x000025D0
_080C9F08: .4byte 0x000025CE
_080C9F0C:
	movs r5, #0
	ldrsh r1, [r1, r5]
	movs r0, #0x64
	muls r0, r1, r0
	mov r1, r8
	adds r1, #0x92
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	cmp r0, #0x1d
	bgt _080C9F54
	ldr r5, _080C9F44 @ =0x0000260C
	adds r1, r4, r5
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080C9F48 @ =0x0000260E
	adds r1, r4, r0
	movs r0, #0xe
	strh r0, [r1]
	ldr r2, _080C9F4C @ =0x0000260D
	adds r1, r4, r2
	movs r0, #3
	strb r0, [r1]
	ldr r5, _080C9F50 @ =0x0000190B
	adds r1, r4, r5
	movs r0, #5
	b _080C9FA6
	.align 2, 0
_080C9F44: .4byte 0x0000260C
_080C9F48: .4byte 0x0000260E
_080C9F4C: .4byte 0x0000260D
_080C9F50: .4byte 0x0000190B
_080C9F54:
	cmp r0, #0x45
	bgt _080C9F88
	ldr r0, _080C9F78 @ =0x0000260C
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080C9F7C @ =0x0000260E
	adds r1, r4, r2
	movs r0, #0xa
	strh r0, [r1]
	ldr r5, _080C9F80 @ =0x0000260D
	adds r1, r4, r5
	movs r0, #2
	strb r0, [r1]
	ldr r0, _080C9F84 @ =0x0000190B
	adds r1, r4, r0
	b _080C9FA4
	.align 2, 0
_080C9F78: .4byte 0x0000260C
_080C9F7C: .4byte 0x0000260E
_080C9F80: .4byte 0x0000260D
_080C9F84: .4byte 0x0000190B
_080C9F88:
	ldr r2, _080C9FC0 @ =0x0000260C
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	ldr r5, _080C9FC4 @ =0x0000260E
	adds r1, r4, r5
	movs r0, #0xa
	strh r0, [r1]
	ldr r0, _080C9FC8 @ =0x0000260D
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	ldr r2, _080C9FCC @ =0x0000190B
	adds r1, r4, r2
_080C9FA4:
	movs r0, #3
_080C9FA6:
	strb r0, [r1]
	ldr r5, _080C9FD0 @ =0x00001909
	adds r1, r4, r5
	movs r0, #3
	strb r0, [r1]
_080C9FB0:
	movs r0, #0
_080C9FB2:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080C9FC0: .4byte 0x0000260C
_080C9FC4: .4byte 0x0000260E
_080C9FC8: .4byte 0x0000260D
_080C9FCC: .4byte 0x0000190B
_080C9FD0: .4byte 0x00001909
