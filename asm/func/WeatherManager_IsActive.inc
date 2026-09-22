	push {lr}
	ldr r0, _08017B80 @ =0x03000084
	ldr r0, [r0]
	cmp r0, #0
	bne _08017B84
	movs r0, #0
	b _08017B86
	.align 2, 0
_08017B80: .4byte 0x03000084
_08017B84:
	movs r0, #1
_08017B86:
	pop {r1}
	bx r1
	.align 2, 0
