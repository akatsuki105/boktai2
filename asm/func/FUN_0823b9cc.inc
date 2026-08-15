	push {lr}
	adds r3, r0, #0
	ldr r0, _0823B9F8 @ =gCamera
	ldr r2, [r0]
	cmp r2, #0
	beq _0823B9F2
	ldr r0, _0823B9FC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0823B9F2
	adds r0, r2, #0
	adds r0, #0x7e
	ldrh r1, [r0]
	cmp r3, r1
	ble _0823B9F2
	strh r3, [r0]
_0823B9F2:
	pop {r0}
	bx r0
	.align 2, 0
_0823B9F8: .4byte gCamera
_0823B9FC: .4byte 0x030047A4
