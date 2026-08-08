	push {lr}
	ldr r0, _08231DAC @ =0x03004690
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #3
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0
_08231DAC: .4byte 0x03004690
