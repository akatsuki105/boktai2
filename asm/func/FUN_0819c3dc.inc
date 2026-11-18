	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	mov r8, r1
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r5, [r6, #0x44]
	ldr r2, _0819C404 @ =0x0000046D
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C408
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C40A
	.align 2, 0
_0819C404: .4byte 0x0000046D
_0819C408:
	movs r0, #0
_0819C40A:
	cmp r0, #0
	beq _0819C426
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldr r0, _0819C434 @ =0x00000A5E
	adds r1, r7, r0
	movs r0, #0xc
	strb r0, [r1]
	ldr r2, _0819C438 @ =0x00000EAB
	adds r1, r7, r2
	movs r0, #0x1e
	strb r0, [r1]
_0819C426:
	ldrb r4, [r5, #6]
	cmp r4, #0x80
	ble _0819C440
	ldr r0, _0819C43C @ =0xFFFFFF00
	adds r4, r4, r0
	b _0819C44E
	.align 2, 0
_0819C434: .4byte 0x00000A5E
_0819C438: .4byte 0x00000EAB
_0819C43C: .4byte 0xFFFFFF00
_0819C440:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r4, r0
	bge _0819C44E
	movs r1, #0x80
	lsls r1, r1, #1
	adds r4, r4, r1
_0819C44E:
	adds r0, r6, #0
	bl FUN_0819ef24
	ldrb r1, [r5, #6]
	ldr r2, _0819C498 @ =0x00000A5E
	adds r0, r7, r2
	ldrb r0, [r0]
	subs r0, r1, r0
	strb r0, [r5, #6]
	ldr r0, [r6, #0x44]
	ldrb r0, [r0, #6]
	cmp r1, r0
	bge _0819C46E
	ldr r0, _0819C49C @ =0x00000169
	bl PlaySound_082406e0
_0819C46E:
	mov r0, r8
	cmp r0, #0x1d
	ble _0819C48C
	adds r0, r4, #0
	cmp r0, #0
	bge _0819C47C
	rsbs r0, r0, #0
_0819C47C:
	cmp r0, #0xc
	bgt _0819C48C
	movs r0, #0
	strb r0, [r5, #6]
	ldr r2, _0819C4A0 @ =0x0000046B
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
_0819C48C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819C498: .4byte 0x00000A5E
_0819C49C: .4byte 0x00000169
_0819C4A0: .4byte 0x0000046B
