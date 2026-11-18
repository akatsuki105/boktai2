	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r0, _0819C4BC @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C4C0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C4C2
	.align 2, 0
_0819C4BC: .4byte 0x0000046D
_0819C4C0:
	movs r0, #0
_0819C4C2:
	ldr r2, [r4, #0x44]
	cmp r0, #0
	beq _0819C4D0
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
_0819C4D0:
	ldrb r0, [r2, #6]
	subs r1, r0, #6
	strb r1, [r2, #6]
	ldr r1, [r4, #0x44]
	ldrb r1, [r1, #6]
	cmp r0, r1
	bge _0819C4E4
	ldr r0, _0819C4FC @ =0x00000169
	bl PlaySound_082406e0
_0819C4E4:
	cmp r5, #0x2b
	ble _0819C4F6
	ldr r1, [r4, #0x44]
	movs r0, #0
	strb r0, [r1, #6]
	ldr r0, _0819C500 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0819C4F6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819C4FC: .4byte 0x00000169
_0819C500: .4byte 0x0000046B
