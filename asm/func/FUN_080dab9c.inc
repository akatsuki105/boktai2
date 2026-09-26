	push {lr}
	adds r1, r0, #0
	ldr r0, _080DABE0 @ =0x03000160
	ldr r2, [r0]
	cmp r1, #0
	blt _080DABDA
	movs r0, #0xa4
	muls r0, r1, r0
	adds r0, #0x3c
	adds r3, r2, r0
	adds r0, r3, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DABDA
	movs r1, #0x3e
	ldrsh r0, [r3, r1]
	cmp r0, #2
	beq _080DABDA
	adds r2, r3, #0
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #2
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080DABDA:
	pop {r0}
	bx r0
	.align 2, 0
_080DABE0: .4byte 0x03000160
