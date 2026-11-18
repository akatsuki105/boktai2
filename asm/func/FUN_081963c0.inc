	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _081963E8 @ =0x00000CEC
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #7
	ble _081963E2
	ldr r2, _081963EC @ =0x00000AFC
	adds r0, r4, r2
	bl Map_GetTileHeightAt
	movs r2, #0xc7
	lsls r2, r2, #4
	adds r1, r4, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [r1]
_081963E2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081963E8: .4byte 0x00000CEC
_081963EC: .4byte 0x00000AFC
