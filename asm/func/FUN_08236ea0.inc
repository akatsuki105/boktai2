	push {lr}
	ldr r0, _08236ECC @ =0x03000780
	ldr r3, [r0]
	cmp r3, #0
	beq _08236EC8
	adds r2, r3, #0
	adds r2, #0x28
	str r2, [r3, #0x18]
	adds r0, r3, #0
	adds r0, #0x78
	str r0, [r3, #0x1c]
	movs r1, #0
	str r1, [r3, #0x28]
	str r1, [r3, #0x78]
	str r2, [r3, #0x20]
	str r0, [r3, #0x24]
	adds r0, #0x50
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
_08236EC8:
	pop {r0}
	bx r0
	.align 2, 0
_08236ECC: .4byte 0x03000780
