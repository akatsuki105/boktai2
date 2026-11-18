	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _081970A8 @ =0x00000C64
	adds r1, r4, r0
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _081970A0
	ldr r0, _081970AC @ =0x00000422
	adds r5, r4, r0
	adds r1, r4, #0
	adds r1, #0x60
	adds r2, r4, #0
	adds r2, #0x7e
	adds r3, r4, #0
	adds r3, #0xe4
	movs r6, #2
	rsbs r6, r6, #0
_08197066:
	ldrh r0, [r5]
	strh r0, [r2]
	ldr r0, [r1]
	ands r0, r6
	str r0, [r1]
	adds r1, #0x2c
	adds r2, #0x2c
	cmp r1, r3
	ble _08197066
	adds r0, r4, #0
	bl FUN_08196358
	ldr r0, _081970A8 @ =0x00000C64
	adds r1, r4, r0
	movs r0, #0xf
	str r0, [r1]
	ldr r0, _081970B0 @ =0x00000C68
	adds r1, r4, r0
	movs r0, #0x14
	str r0, [r1]
	movs r0, #0xc5
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, _081970B4 @ =FUN_081970b8
	str r0, [r1]
	movs r0, #0xb6
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081970A0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081970A8: .4byte 0x00000C64
_081970AC: .4byte 0x00000422
_081970B0: .4byte 0x00000C68
_081970B4: .4byte FUN_081970b8
