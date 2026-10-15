	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2, #0x18]
	adds r3, r2, #0
	adds r3, #0xaa
	ldrh r0, [r3]
	adds r1, r0, #1
	strh r1, [r3]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080A20DC
	adds r0, r2, #0
	adds r0, #0xae
	ldrh r0, [r0]
	adds r0, #0x1e
	strh r0, [r2, #0x36]
	movs r0, #0
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xb4
	ldr r0, _080A20D8 @ =FUN_080a1fc4
	str r0, [r1]
	b _080A20E8
	.align 2, 0
_080A20D8: .4byte FUN_080a1fc4
_080A20DC:
	adds r3, r2, #0
	adds r3, #0xae
	lsls r0, r1, #1
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r2, #0x36]
_080A20E8:
	adds r1, r2, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r3, _080A2110 @ =0x0000FFFF
	adds r1, r3, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A210C
	adds r0, r2, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r2, #0
	bl FUN_080a1e78
_080A210C:
	pop {r0}
	bx r0
	.align 2, 0
_080A2110: .4byte 0x0000FFFF
