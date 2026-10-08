	push {lr}
	ldr r2, _080A07B0 @ =0x03002C3C
	ldr r1, [r2]
	cmp r1, #0
	beq _080A07AA
	adds r1, #0x36
	movs r0, #0
	strb r0, [r1]
	ldr r1, [r2]
	movs r0, #8
	strh r0, [r1, #0x34]
_080A07AA:
	pop {r0}
	bx r0
	.align 2, 0
_080A07B0: .4byte 0x03002C3C
