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
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r5, [r5]
	orrs r5, r6
	ldr r0, _080EF9C8 @ =0x000004C1
	adds r4, r4, r0
	ldrb r0, [r4]
	ldrb r2, [r1]
	orrs r5, r0
	ldr r1, _080EF9CC @ =0x0000025D
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080EF9D8
	ldr r1, _080EF9D0 @ =0x000004B7
	adds r0, r7, r1
	strb r2, [r0]
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r4, r5, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _080EF9D4 @ =0x0000046E
	adds r6, r7, r0
	b _080EFA5A
	.align 2, 0
_080EF9C8: .4byte 0x000004C1
_080EF9CC: .4byte 0x0000025D
_080EF9D0: .4byte 0x000004B7
_080EF9D4: .4byte 0x0000046E
_080EF9D8:
	ldr r0, [r7, #0x44]
	adds r4, r0, #0
	adds r4, #0x20
	adds r2, r2, r3
	ldr r1, _080EFA48 @ =0x000004B7
	adds r0, r7, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _080EFA4C @ =0x0000046E
	adds r6, r7, r0
	cmp r1, r2
	bne _080EFA12
	ldrb r0, [r6]
	cmp r0, #0
	bne _080EFA12
	cmp r5, #1
	bne _080EFA04
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080EFA5E
_080EFA04:
	cmp r5, #0
	bne _080EFA12
	ldr r0, [r4, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080EFA5E
_080EFA12:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r5, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _080EFA24
	movs r3, #6
_080EFA24:
	ldr r1, [r7, #0x44]
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
	beq _080EFA50
	ldr r0, [r4, #8]
	mov r1, r8
	orrs r0, r1
	b _080EFA58
	.align 2, 0
_080EFA48: .4byte 0x000004B7
_080EFA4C: .4byte 0x0000046E
_080EFA50:
	ldr r0, [r4, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080EFA58:
	str r0, [r4, #8]
_080EFA5A:
	movs r0, #0
	strb r0, [r6]
_080EFA5E:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
