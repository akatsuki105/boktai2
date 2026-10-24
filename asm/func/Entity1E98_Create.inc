	push {lr}
	ldr r0, _080A4E90 @ =0x03002C44
	ldr r0, [r0]
	cmp r0, #0
	bne _080A4E86
	bl Entity1E98_Create_Internal
_080A4E86:
	bl Entity1E98_Init
	pop {r1}
	bx r1
	.align 2, 0
_080A4E90: .4byte 0x03002C44
