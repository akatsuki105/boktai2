	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08196E22
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196E22
	ldr r0, _08196E48 @ =0x00000CC3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08196E22:
	ldr r0, _08196E48 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	ble _08196E42
	movs r0, #0
	strb r0, [r1]
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _08196E4C @ =FUN_08196e54
	str r0, [r1]
	ldr r0, _08196E50 @ =0x0000016B
	bl PlaySound_082406e0
_08196E42:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196E48: .4byte 0x00000CC3
_08196E4C: .4byte FUN_08196e54
_08196E50: .4byte 0x0000016B
