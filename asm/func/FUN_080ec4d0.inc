	push {lr}
	ldr r0, _080EC4E8 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xc2
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #0x80
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
_080EC4E8: .4byte 0x030046A0
