	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r4, r1, #0
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
	add r0, sp, #4
	ldrb r3, [r0]
	ldr r1, _080EF8C4 @ =0x000004C1
	adds r4, r4, r1
	ldrb r1, [r5]
	ldrb r0, [r4]
	ldrb r2, [r2]
	adds r5, r1, #0
	orrs r5, r0
	ldr r1, _080EF8C8 @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EF8D4
	ldr r1, _080EF8CC @ =0x000004B7
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, [r6, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r5, [sp]
	bl FUN_08236fac
	ldr r0, _080EF8D0 @ =0x0000046E
	adds r7, r6, r0
	b _080EF956
	.align 2, 0
_080EF8C4: .4byte 0x000004C1
_080EF8C8: .4byte 0x0000025D
_080EF8CC: .4byte 0x000004B7
_080EF8D0: .4byte 0x0000046E
_080EF8D4:
	ldr r0, [r6, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _080EF944 @ =0x000004B7
	adds r0, r6, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _080EF948 @ =0x0000046E
	adds r7, r6, r0
	cmp r1, r2
	bne _080EF90E
	ldrb r0, [r7]
	cmp r0, #0
	bne _080EF90E
	cmp r5, #1
	bne _080EF900
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080EF95A
_080EF900:
	cmp r5, #0
	bne _080EF90E
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080EF95A
_080EF90E:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r5, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _080EF920
	movs r3, #6
_080EF920:
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
	beq _080EF94C
	ldr r0, [r4, #8]
	mov r1, r8
	orrs r0, r1
	b _080EF954
	.align 2, 0
_080EF944: .4byte 0x000004B7
_080EF948: .4byte 0x0000046E
_080EF94C:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080EF954:
	str r0, [r4, #8]
_080EF956:
	movs r0, #0
	strb r0, [r7]
_080EF95A:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
