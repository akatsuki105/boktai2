	push {lr}
	ldr r0, _080A94F0 @ =0x03002C50
	ldr r1, [r0]
	cmp r1, #0
	beq _080A94EA
	movs r0, #1
	strh r0, [r1, #0x1a]
_080A94EA:
	pop {r0}
	bx r0
	.align 2, 0
_080A94F0: .4byte 0x03002C50
