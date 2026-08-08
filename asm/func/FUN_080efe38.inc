	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r4, r0, #0
	lsls r1, r1, #2
	adds r1, r4, r1
	movs r2, #0x98
	lsls r2, r2, #3
	adds r0, r1, r2
	adds r2, #1
	adds r1, r1, r2
	ldrb r2, [r0]
	ldrb r5, [r1]
	ldr r1, _080EFE7C @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EFE88
	ldr r1, _080EFE80 @ =0x000004B7
	adds r0, r4, r1
	strb r2, [r0]
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r5, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, _080EFE84 @ =0x0000046E
	adds r7, r4, r2
	b _080EFF02
	.align 2, 0
_080EFE7C: .4byte 0x0000025D
_080EFE80: .4byte 0x000004B7
_080EFE84: .4byte 0x0000046E
_080EFE88:
	ldr r0, [r4, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	ldr r1, _080EFEF0 @ =0x000004B7
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _080EFEF4 @ =0x0000046E
	adds r7, r4, r0
	cmp r1, r2
	bne _080EFEC0
	ldrb r0, [r7]
	cmp r0, #0
	bne _080EFEC0
	cmp r5, #1
	bne _080EFEB2
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080EFF06
_080EFEB2:
	cmp r5, #0
	bne _080EFEC0
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080EFF06
_080EFEC0:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r5, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _080EFED2
	movs r3, #6
_080EFED2:
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	beq _080EFEF8
	ldr r0, [r6, #8]
	mov r2, r8
	orrs r0, r2
	b _080EFF00
	.align 2, 0
_080EFEF0: .4byte 0x000004B7
_080EFEF4: .4byte 0x0000046E
_080EFEF8:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080EFF00:
	str r0, [r6, #8]
_080EFF02:
	movs r0, #0
	strb r0, [r7]
_080EFF06:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
