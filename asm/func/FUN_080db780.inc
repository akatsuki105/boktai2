	push {r4, r5, r6, lr}
	ldr r0, _080DB79C @ =0x03000160
	ldr r5, [r0]
	cmp r5, #0
	beq _080DB7DE
	movs r4, #0
_080DB78C:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DB7A0
	movs r0, #1
	b _080DB7A2
	.align 2, 0
_080DB79C: .4byte 0x03000160
_080DB7A0:
	movs r0, #0
_080DB7A2:
	cmp r0, #0
	beq _080DB7D8
	movs r0, #0xa4
	muls r0, r4, r0
	adds r0, #0x3c
	adds r3, r5, r0
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DB7D8
	movs r1, #0x3e
	ldrsh r0, [r3, r1]
	cmp r0, #2
	beq _080DB7D8
	adds r2, r3, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
_080DB7D8:
	adds r4, #1
	cmp r4, #7
	ble _080DB78C
_080DB7DE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
