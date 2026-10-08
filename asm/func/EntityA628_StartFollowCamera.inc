	push {lr}
	ldr r3, _080A0790 @ =0x03002C3C
	ldr r1, [r3]
	cmp r1, #0
	beq _080A078A
	adds r1, #0x36
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r3]
	strh r2, [r0, #0x34]
_080A078A:
	pop {r0}
	bx r0
	.align 2, 0
_080A0790: .4byte 0x03002C3C
