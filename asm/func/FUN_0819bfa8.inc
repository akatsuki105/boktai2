	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r0, _0819BFC0 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0819BFC4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0819BFC6
	.align 2, 0
_0819BFC0: .4byte 0x0000046D
_0819BFC4:
	movs r0, #0
_0819BFC6:
	cmp r0, #0
	beq _0819BFD4
	ldr r0, [r5, #0x44]
	ldr r1, [r0]
	movs r2, #2
	orrs r1, r2
	str r1, [r0]
_0819BFD4:
	adds r0, r5, #0
	bl FUN_0819ef24
	ldr r1, [r5, #0x44]
	ldrb r0, [r1, #6]
	cmp r0, #0x13
	bhi _0819BFE6
	adds r0, #1
	strb r0, [r1, #6]
_0819BFE6:
	cmp r4, #0x3c
	ble _0819C018
	ldr r1, [r5, #0x44]
	movs r3, #0
	movs r0, #0x14
	strb r0, [r1, #6]
	ldr r4, _0819C020 @ =FUN_0819c02c
	movs r2, #0x27
	ldr r0, _0819C024 @ =0x0000046D
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0819C028 @ =0x0000046B
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r3, [r0]
_0819C018:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819C020: .4byte FUN_0819c02c
_0819C024: .4byte 0x0000046D
_0819C028: .4byte 0x0000046B
