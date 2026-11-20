	push {lr}
	ldr r0, _082385AC @ =0x03000820
	ldr r0, [r0]
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	bne _082385A4
	str r1, [r0]
_082385A4:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_082385AC: .4byte 0x03000820
