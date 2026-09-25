	push {lr}
	adds r1, r0, #0
	ldr r0, _080DAC1C @ =0x03000160
	ldr r2, [r0]
	cmp r1, #0
	blt _080DAC16
	movs r0, #0xa4
	muls r0, r1, r0
	adds r0, #0x3c
	adds r2, r2, r0
	adds r0, r2, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _080DAC16
	movs r1, #0x3e
	ldrsh r0, [r2, r1]
	cmp r0, #2
	beq _080DAC16
	adds r2, #0x40
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_080DAC16:
	pop {r0}
	bx r0
	.align 2, 0
_080DAC1C: .4byte 0x03000160
