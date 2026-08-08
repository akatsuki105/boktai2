	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r6, r0, #0
	mov r8, r1
	ldr r0, _080F9A60 @ =0x03000184
	ldr r2, [r0]
	movs r1, #0x40
	ldr r0, _080F9A64 @ =0x030046A0
	ldr r0, [r0]
	ldr r3, _080F9A68 @ =0x00000934
	adds r0, r0, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F9A6C
	movs r0, #1
	b _080F9A6E
	.align 2, 0
_080F9A60: .4byte 0x03000184
_080F9A64: .4byte 0x030046A0
_080F9A68: .4byte 0x00000934
_080F9A6C:
	movs r0, #0
_080F9A6E:
	cmp r0, #0
	bne _080F9A76
	cmp r2, #0
	bne _080F9A7A
_080F9A76:
	movs r0, #0
	b _080F9B20
_080F9A7A:
	movs r5, #0
	ldr r0, _080F9AE8 @ =0x7FFFFFFF
	str r0, [sp]
	movs r7, #1
	rsbs r7, r7, #0
	ldr r4, [r2, #0x28]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r0, r0, r6
	mov sb, r0
	cmp r4, #0
	beq _080F9AD2
_080F9A92:
	ldrb r1, [r4, #4]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080F9ACC
	ldr r0, [r4]
	cmp r0, #0
	beq _080F9ACC
	ldrb r0, [r4, #5]
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _080F9ACC
	adds r0, r4, #0
	bl FUN_080f8c2c
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F9ACC
	adds r0, r4, #0
	adds r1, r6, #0
	mov r2, sp
	bl FUN_080f8f04
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080F9ACC
	adds r5, r4, #0
	adds r7, r5, #0
_080F9ACC:
	ldr r4, [r4, #0xc]
	cmp r4, #0
	bne _080F9A92
_080F9AD2:
	cmp r7, #0
	blt _080F9B12
	ldrb r0, [r5, #5]
	cmp r0, #2
	beq _080F9AFE
	cmp r0, #2
	bgt _080F9AEC
	cmp r0, #1
	beq _080F9AF2
	b _080F9B12
	.align 2, 0
_080F9AE8: .4byte 0x7FFFFFFF
_080F9AEC:
	cmp r0, #4
	beq _080F9AFE
	b _080F9B12
_080F9AF2:
	ldrb r1, [r5, #4]
	movs r0, #2
	orrs r0, r1
	strb r0, [r5, #4]
	str r6, [r5, #8]
	b _080F9B12
_080F9AFE:
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r1, _080F9B30 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, [r5]
	bl FUN_080f8bb8
_080F9B12:
	movs r1, #9
	rsbs r1, r1, #0
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
_080F9B20:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080F9B30: .4byte 0xFEFFFFFF
