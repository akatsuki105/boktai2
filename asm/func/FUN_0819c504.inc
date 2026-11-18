	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r3, [r0]
	ldr r2, [r5, #0x44]
	ldr r6, _0819C528 @ =0x0000046D
	adds r1, r5, r6
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819C52C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819C52E
	.align 2, 0
_0819C528: .4byte 0x0000046D
_0819C52C:
	movs r0, #0
_0819C52E:
	cmp r0, #0
	beq _0819C548
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r6, _0819C554 @ =0x00000ECF
	adds r0, r3, r6
	strb r1, [r0]
_0819C548:
	ldrb r1, [r2, #6]
	cmp r1, #0x80
	ble _0819C55C
	ldr r0, _0819C558 @ =0xFFFFFF00
	adds r1, r1, r0
	b _0819C56A
	.align 2, 0
_0819C554: .4byte 0x00000ECF
_0819C558: .4byte 0xFFFFFF00
_0819C55C:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C56A
	movs r6, #0x80
	lsls r6, r6, #1
	adds r1, r1, r6
_0819C56A:
	adds r0, r1, #0
	cmp r0, #0
	bge _0819C572
	rsbs r0, r0, #0
_0819C572:
	cmp r0, #0x30
	ble _0819C5B8
	cmp r4, #0x2a
	ble _0819C5F2
	ldr r4, _0819C5A8 @ =FUN_0819c5f8
	movs r3, #0x31
	ldr r0, _0819C5AC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C5B0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	ldr r6, _0819C5B4 @ =0x00000553
	adds r0, r5, r6
	strb r3, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r4, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r2, [r0]
	b _0819C5F2
	.align 2, 0
_0819C5A8: .4byte FUN_0819c5f8
_0819C5AC: .4byte 0x0000046D
_0819C5B0: .4byte 0x0000046B
_0819C5B4: .4byte 0x00000553
_0819C5B8:
	ldr r1, _0819C5CC @ =0x00000ECF
	adds r0, r3, r1
	ldrb r1, [r0]
	movs r0, #0x20
	subs r1, r0, r1
	cmp r1, #0x80
	ble _0819C5D4
	ldr r6, _0819C5D0 @ =0xFFFFFF00
	adds r1, r1, r6
	b _0819C5E2
	.align 2, 0
_0819C5CC: .4byte 0x00000ECF
_0819C5D0: .4byte 0xFFFFFF00
_0819C5D4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _0819C5E2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_0819C5E2:
	cmp r1, #0
	bge _0819C5EC
	ldrb r0, [r2, #6]
	subs r0, #2
	b _0819C5F0
_0819C5EC:
	ldrb r0, [r2, #6]
	adds r0, #2
_0819C5F0:
	strb r0, [r2, #6]
_0819C5F2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
