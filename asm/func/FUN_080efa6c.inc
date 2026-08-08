	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	mov r5, sp
	adds r5, #5
	add r1, sp, #4
	adds r2, r5, #0
	bl FUN_080e5d44
	lsls r4, r4, #2
	adds r4, r7, r4
	movs r0, #0x98
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrb r5, [r5]
	orrs r5, r6
	adds r0, #1
	adds r4, r4, r0
	ldrb r0, [r4]
	ldrb r2, [r1]
	orrs r5, r0
	ldr r1, _080EFAC8 @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EFAD4
	ldr r1, _080EFACC @ =0x000004B7
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r5, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, _080EFAD0 @ =0x0000046E
	adds r6, r7, r0
	b _080EFB4E
	.align 2, 0
_080EFAC8: .4byte 0x0000025D
_080EFACC: .4byte 0x000004B7
_080EFAD0: .4byte 0x0000046E
_080EFAD4:
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	ldr r1, _080EFB3C @ =0x000004B7
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _080EFB40 @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _080EFB0C
	ldrb r0, [r6]
	cmp r0, #0
	bne _080EFB0C
	cmp r5, #1
	bne _080EFAFE
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080EFB52
_080EFAFE:
	cmp r5, #0
	bne _080EFB0C
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080EFB52
_080EFB0C:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r5, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _080EFB1E
	movs r3, #6
_080EFB1E:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r5, r0
	cmp r5, #0
	beq _080EFB44
	ldr r0, [r4, #8]
	mov r1, r8
	orrs r0, r1
	b _080EFB4C
	.align 2, 0
_080EFB3C: .4byte 0x000004B7
_080EFB40: .4byte 0x0000046E
_080EFB44:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080EFB4C:
	str r0, [r4, #8]
_080EFB4E:
	movs r0, #0
	strb r0, [r6]
_080EFB52:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
