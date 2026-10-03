	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080AC5F0 @ =0x0000A854
	bl Registry_Find
	cmp r0, #0
	beq _080AC5E8
	movs r5, #1
	adds r1, r0, #0
	adds r1, #0x18
	movs r3, #0
	movs r2, #3
_080AC5CC:
	ldrh r0, [r1, #0x36]
	cmp r0, #0
	beq _080AC5E0
	ldrh r0, [r1, #0x34]
	cmp r0, r4
	bne _080AC5E0
	ldr r0, [r1]
	orrs r0, r5
	str r0, [r1]
	strh r3, [r1, #0x36]
_080AC5E0:
	adds r1, #0x40
	subs r2, #1
	cmp r2, #0
	bge _080AC5CC
_080AC5E8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AC5F0: .4byte 0x0000A854
