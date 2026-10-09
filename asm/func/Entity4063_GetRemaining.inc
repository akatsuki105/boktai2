	push {lr}
	ldr r0, _080A94D0 @ =0x03002C50
	ldr r0, [r0]
	cmp r0, #0
	beq _080A94D4
	ldrh r0, [r0, #0x18]
	b _080A94D6
	.align 2, 0
_080A94D0: .4byte 0x03002C50
_080A94D4:
	movs r0, #0
_080A94D6:
	pop {r1}
	bx r1
	.align 2, 0
