	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08196856
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196856
	ldr r2, _08196880 @ =0x00000CC3
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08196856:
	ldr r0, _08196880 @ =0x00000CC3
	adds r2, r4, r0
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #1
	ble _0819687A
	movs r1, #0
	strb r1, [r2]
	ldr r2, _08196884 @ =0x0000044C
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08196888 @ =0x00000C48
	adds r1, r4, r0
	ldr r0, _0819688C @ =FUN_08196894
	str r0, [r1]
	ldr r0, _08196890 @ =0x0000018F
	bl PlaySound_082406e0
_0819687A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196880: .4byte 0x00000CC3
_08196884: .4byte 0x0000044C
_08196888: .4byte 0x00000C48
_0819688C: .4byte FUN_08196894
_08196890: .4byte 0x0000018F
