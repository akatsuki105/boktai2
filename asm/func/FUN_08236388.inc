	push {lr}
	adds r3, r0, #0
	ldr r0, _0823639C @ =0x03000780
	ldr r2, [r0]
	adds r1, r0, #0
	cmp r2, #0
	beq _082363BE
	ldr r0, [r2, #0x18]
	b _082363A4
	.align 2, 0
_0823639C: .4byte 0x03000780
_082363A0:
	cmp r0, r3
	beq _082363BE
_082363A4:
	ldr r0, [r0]
	cmp r0, #0
	bne _082363A0
	ldr r1, [r1]
	ldr r0, [r1, #0x20]
	str r3, [r0]
	movs r0, #0
	str r0, [r3]
	str r3, [r1, #0x20]
	adds r1, #0xc8
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_082363BE:
	pop {r0}
	bx r0
	.align 2, 0
