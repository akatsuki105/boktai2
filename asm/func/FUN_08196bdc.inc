	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08196C02
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08196C02
	ldr r0, _08196C20 @ =0x00000CC3
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_08196C02:
	ldr r0, _08196C20 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #2
	ble _08196C1A
	movs r0, #0
	strb r0, [r1]
	ldr r0, _08196C24 @ =0x00000C4C
	adds r1, r4, r0
	ldr r0, _08196C28 @ =FUN_08196c2c
	str r0, [r1]
_08196C1A:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08196C20: .4byte 0x00000CC3
_08196C24: .4byte 0x00000C4C
_08196C28: .4byte FUN_08196c2c
