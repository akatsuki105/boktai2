	push {r4, lr}
	adds r4, r0, #0
	movs r0, #8
	bl Malloc
	str r0, [r4, #0x1c]
	movs r1, #8
	bl ClearMemory
	ldr r1, [r4, #0x1c]
	movs r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	ldr r0, _080EC63C @ =0x03002C60
	str r1, [r0]
	str r1, [r4, #0x20]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080EC63C: .4byte 0x03002C60
