	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _0817A3D0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _0817A3D4 @ =0x030047A4
	ldr r1, _0817A3D8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _0817A398
	b _0817A4A4
_0817A398:
	movs r1, #4
	ldr r0, _0817A3DC @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0817A3A6
	b _0817A4A4
_0817A3A6:
	movs r0, #2
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _0817A468
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0817A3E0 @ =0x030046A0
	ldr r0, [r0]
	adds r2, #0xd0
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0817A3E4
	movs r0, #1
	b _0817A3E6
	.align 2, 0
_0817A3D0: .4byte 0x03002BE0
_0817A3D4: .4byte 0x030047A4
_0817A3D8: .4byte 0x030047A0
_0817A3DC: .4byte 0x03002BC0
_0817A3E0: .4byte 0x030046A0
_0817A3E4:
	movs r0, #0
_0817A3E6:
	cmp r0, #0
	bne _0817A3F4
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_Suspend
	b _0817A4A4
_0817A3F4:
	adds r0, r4, #0
	bl FUN_081756e0
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817A426
	ldr r1, _0817A464 @ =0x00000624
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0817A426
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0817A426:
	adds r0, r4, #0
	bl Enemy_ProcessRequests
	adds r0, r4, #0
	bl FUN_080e1f48
	movs r0, #0xb0
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ldr r1, [r1]
	bl _call_via_r1
	adds r0, r4, #0
	bl Enemy_UpdateHitboxes
	adds r0, r4, #0
	bl Enemy_UpdateMovement
	adds r0, r4, #0
	bl Enemy_ShakeSprite
	adds r0, r4, #0
	bl FUN_080f06ac
	movs r0, #1
	b _0817A4A6
	.align 2, 0
_0817A464: .4byte 0x00000624
_0817A468:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _0817A49E
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _0817A48C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _0817A490
	movs r0, #1
	b _0817A492
	.align 2, 0
_0817A48C: .4byte 0x030046A0
_0817A490:
	movs r0, #0
_0817A492:
	cmp r0, #0
	beq _0817A49E
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_Resume
_0817A49E:
	adds r0, r4, #0
	bl FUN_080f06ac
_0817A4A4:
	movs r0, #0
_0817A4A6:
	pop {r4}
	pop {r1}
	bx r1
