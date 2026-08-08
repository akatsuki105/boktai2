	push {lr}
	adds r3, r0, #0
	ldr r0, _082363FC @ =0x03000780
	ldr r2, [r0]
	adds r1, r0, #0
	cmp r2, #0
	beq _082363F6
	ldr r0, [r2, #0x1c]
	ldr r2, [r0]
	cmp r2, #0
	beq _082363E4
_082363DA:
	cmp r2, r3
	beq _082363F6
	ldr r2, [r2]
	cmp r2, #0
	bne _082363DA
_082363E4:
	ldr r1, [r1]
	ldr r2, [r1, #0x1c]
	ldr r0, [r2]
	str r0, [r3]
	str r3, [r2]
	adds r1, #0xca
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_082363F6:
	pop {r0}
	bx r0
	.align 2, 0
_082363FC: .4byte 0x03000780
