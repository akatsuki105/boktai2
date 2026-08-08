	push {lr}
	adds r2, r0, #0
	ldr r1, _082317C0 @ =0x03000768
	ldr r0, [r1]
	cmp r0, r2
	bne _082317AC
	ldr r0, [r2]
	str r0, [r1]
_082317AC:
	ldr r0, [r1]
	adds r1, r0, #0
	cmp r0, #0
	beq _082317CC
_082317B4:
	cmp r0, r2
	bne _082317C4
	ldr r0, [r0]
	str r0, [r1]
	movs r0, #0
	b _082317D0
	.align 2, 0
_082317C0: .4byte 0x03000768
_082317C4:
	adds r1, r0, #0
	ldr r0, [r0]
	cmp r0, #0
	bne _082317B4
_082317CC:
	movs r0, #1
	rsbs r0, r0, #0
_082317D0:
	pop {r1}
	bx r1
