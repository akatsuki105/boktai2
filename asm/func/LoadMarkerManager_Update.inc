	push {r4, lr}
	adds r3, r0, #0
	movs r1, #0
	ldrh r2, [r3, #0x18]
	cmp r2, #0
	bne _080A6BBC
	ldr r0, _080A6BB8 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x14
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _080A6BBC
	ldrh r0, [r3, #0x1e]
	cmp r0, #0x2f
	bhi _080A6BA8
	movs r1, #1
_080A6BA8:
	adds r0, #1
	strh r0, [r3, #0x1e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x47
	bls _080A6BBE
	strh r2, [r3, #0x1e]
	b _080A6BBE
	.align 2, 0
_080A6BB8: .4byte 0x030046A0
_080A6BBC:
	strh r1, [r3, #0x1e]
_080A6BBE:
	cmp r1, #0
	beq _080A6BE4
	movs r2, #0
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	bge _080A6C02
	movs r4, #2
	rsbs r4, r4, #0
	adds r1, r3, #0
	adds r1, #0x20
_080A6BD2:
	ldr r0, [r1]
	ands r0, r4
	str r0, [r1]
	adds r1, #0x28
	adds r2, #1
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	blt _080A6BD2
	b _080A6C02
_080A6BE4:
	movs r2, #0
	ldrh r4, [r3, #0x1c]
	cmp r2, r4
	bge _080A6C02
	movs r4, #1
	adds r1, r3, #0
	adds r1, #0x20
_080A6BF2:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x28
	adds r2, #1
	ldrh r0, [r3, #0x1c]
	cmp r2, r0
	blt _080A6BF2
_080A6C02:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
