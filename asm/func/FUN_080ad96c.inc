	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x94
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080AD982
	adds r0, r5, #0
	bl _call_via_r1
_080AD982:
	adds r0, r5, #0
	bl FUN_080ad6a8
	ldr r2, _080AD9C8 @ =0x00001428
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AD9C0
	movs r4, #0
_080AD994:
	lsls r1, r4, #1
	movs r2, #0x8c
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	adds r0, #0x20
	adds r0, r5, r0
	lsls r1, r4, #5
	ldr r2, _080AD9CC @ =0x03004250
	adds r1, r1, r2
	ldr r2, _080AD9D0 @ =0x04000008
	bl CpuSet
	adds r4, #1
	cmp r4, #2
	ble _080AD994
	ldr r0, _080AD9C8 @ =0x00001428
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
_080AD9C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AD9C8: .4byte 0x00001428
_080AD9CC: .4byte 0x03004250
_080AD9D0: .4byte 0x04000008
