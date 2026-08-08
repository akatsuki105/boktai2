	push {lr}
	ldr r0, _082380C0 @ =0x030046D0
	ldr r1, _082380C4 @ =0x030046BC
	ldrh r2, [r0]
	ldrh r0, [r1]
	orrs r0, r2
	ldr r1, _082380C8 @ =0x0000FFFF
	cmp r0, r1
	bne _082380CC
	movs r0, #0
	b _082380CE
	.align 2, 0
_082380C0: .4byte 0x030046D0
_082380C4: .4byte 0x030046BC
_082380C8: .4byte 0x0000FFFF
_082380CC:
	movs r0, #1
_082380CE:
	pop {r1}
	bx r1
	.align 2, 0
