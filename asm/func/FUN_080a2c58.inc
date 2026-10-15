	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080A2CA8 @ =0x00000382
	adds r0, r4, r1
	ldrh r2, [r0]
	lsls r1, r2, #0x10
	lsrs r0, r1, #0x10
	cmp r0, #0x1f
	bhi _080A2C88
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _080A2C88
	lsrs r1, r1, #0x12
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r4, r0
	adds r1, r4, #0
	adds r1, #0x98
	bl FUN_080a2678
_080A2C88:
	ldr r0, _080A2CA8 @ =0x00000382
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bne _080A2CA2
	ldr r1, _080A2CAC @ =FUN_080a2cb0
	adds r0, r4, #0
	bl FUN_080a2a14
_080A2CA2:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080A2CA8: .4byte 0x00000382
_080A2CAC: .4byte FUN_080a2cb0
