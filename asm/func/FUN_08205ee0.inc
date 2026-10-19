	push {lr}
	ldr r0, _08205EF8 @ =0x03002C90
	ldr r0, [r0]
	cmp r0, #0
	beq _08205EF2
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #1
	strb r0, [r1, #8]
_08205EF2:
	pop {r0}
	bx r0
	.align 2, 0
_08205EF8: .4byte 0x03002C90
