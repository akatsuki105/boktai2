	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, _08194300 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _08194304 @ =0x030047A4
	ldr r1, _08194308 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	beq _081942C8
	b _081943D4
_081942C8:
	movs r1, #4
	ldr r0, _0819430C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081942D6
	b _081943D4
_081942D6:
	movs r0, #2
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	ands r0, r1
	cmp r0, #0
	bne _08194398
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _08194310 @ =0x030046A0
	ldr r0, [r0]
	adds r2, #0xd0
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _08194314
	movs r0, #1
	b _08194316
	.align 2, 0
_08194300: .4byte 0x03002BE0
_08194304: .4byte 0x030047A4
_08194308: .4byte 0x030047A0
_0819430C: .4byte 0x03002BC0
_08194310: .4byte 0x030046A0
_08194314:
	movs r0, #0
_08194316:
	cmp r0, #0
	bne _08194324
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_Suspend
	b _081943D4
_08194324:
	adds r0, r4, #0
	bl FUN_0818e30c
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08194356
	ldr r1, _08194394 @ =0x00000624
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08194356
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r0, r4, r2
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_08194356:
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
	b _081943D6
	.align 2, 0
_08194394: .4byte 0x00000624
_08194398:
	movs r0, #1
	ands r1, r0
	cmp r1, #0
	bne _081943CE
	movs r0, #0x92
	lsls r0, r0, #3
	adds r1, r4, r0
	ldr r0, _081943BC @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bne _081943C0
	movs r0, #1
	b _081943C2
	.align 2, 0
_081943BC: .4byte 0x030046A0
_081943C0:
	movs r0, #0
_081943C2:
	cmp r0, #0
	beq _081943CE
	adds r0, r4, #0
	movs r1, #0
	bl Enemy_Resume
_081943CE:
	adds r0, r4, #0
	bl FUN_080f06ac
_081943D4:
	movs r0, #0
_081943D6:
	pop {r4}
	pop {r1}
	bx r1
