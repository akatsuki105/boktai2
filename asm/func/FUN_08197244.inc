	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xc6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0819726A
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0819726A
	ldr r2, _08197294 @ =0x00000CC3
	adds r1, r4, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0819726A:
	ldr r0, _08197294 @ =0x00000CC3
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #1
	ble _0819728E
	movs r0, #0
	strb r0, [r1]
	ldr r1, _08197298 @ =0x00000AC4
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _0819729C @ =0x00000AC6
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _081972A0 @ =0x00000C54
	adds r1, r4, r0
	ldr r0, _081972A4 @ =FUN_081972a8
	str r0, [r1]
_0819728E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08197294: .4byte 0x00000CC3
_08197298: .4byte 0x00000AC4
_0819729C: .4byte 0x00000AC6
_081972A0: .4byte 0x00000C54
_081972A4: .4byte FUN_081972a8
