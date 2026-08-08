	push {lr}
	cmp r0, #0
	bne _0823A908
	ldr r1, _0823A904 @ =0x03004798
	movs r0, #0xa0
	lsls r0, r0, #1
	str r0, [r1]
	b _0823A90C
	.align 2, 0
_0823A904: .4byte 0x03004798
_0823A908:
	bl SoftReset_0823a928
_0823A90C:
	pop {r0}
	bx r0
