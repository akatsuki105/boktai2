	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
	adds r7, r2, #0
	mov r5, sp
	adds r5, #5
	add r1, sp, #4
	adds r2, r5, #0
	bl FUN_080e5d44
	lsls r4, r4, #2
	adds r4, r6, r4
	movs r0, #0x98
	lsls r0, r0, #3
	adds r2, r4, r0
	ldr r1, _080EFCA0 @ =0x000004C1
	adds r4, r4, r1
	ldrb r1, [r5]
	ldrb r0, [r4]
	ldrb r2, [r2]
	adds r5, r1, #0
	orrs r5, r0
	ldr r1, _080EFCA4 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EFCB0
	ldr r1, _080EFCA8 @ =0x000004B7
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r7, #0x18
	lsrs r3, r3, #0x18
	str r5, [sp]
	bl FUN_08236fac
	ldr r0, _080EFCAC @ =0x0000046E
	adds r7, r6, r0
	b _080EFD32
	.align 2, 0
_080EFCA0: .4byte 0x000004C1
_080EFCA4: .4byte 0x0000025D
_080EFCA8: .4byte 0x000004B7
_080EFCAC: .4byte 0x0000046E
_080EFCB0:
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r7
	ldr r1, _080EFD20 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _080EFD24 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _080EFCEA
	ldrb r0, [r7]
	cmp r0, #0
	bne _080EFCEA
	cmp r5, #1
	bne _080EFCDC
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080EFD36
_080EFCDC:
	cmp r5, #0
	bne _080EFCEA
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080EFD36
_080EFCEA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r5, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _080EFCFC
	movs r3, #6
_080EFCFC:
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	beq _080EFD28
	ldr r0, [r4, #8]
	mov r1, r8
	orrs r0, r1
	b _080EFD30
	.align 2, 0
_080EFD20: .4byte 0x000004B7
_080EFD24: .4byte 0x0000046E
_080EFD28:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080EFD30:
	str r0, [r4, #8]
_080EFD32:
	movs r0, #0
	strb r0, [r7]
_080EFD36:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
