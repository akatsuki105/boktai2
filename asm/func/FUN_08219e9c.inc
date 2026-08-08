	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08219EC0 @ =0x000092B3
	ldr r1, _08219EC4 @ =0x0000E9C3
	bl FUN_082310cc
	adds r0, #0x14
	str r0, [r4, #0x3c]
	ldr r1, _08219EC8 @ =0x03004250
	ldr r2, _08219ECC @ =0x04000028
	bl CpuSet
	adds r0, r4, #0
	bl FUN_082138a0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08219EC0: .4byte 0x000092B3
_08219EC4: .4byte 0x0000E9C3
_08219EC8: .4byte 0x03004250
_08219ECC: .4byte 0x04000028
