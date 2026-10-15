	push {lr}
	ldr r0, _080A5E64 @ =0x0300014C
	ldr r0, [r0]
	cmp r0, #0
	beq _080A5E5E
	adds r1, r0, #0
	adds r1, #0x9c
	movs r0, #1
	str r0, [r1]
_080A5E5E:
	pop {r0}
	bx r0
	.align 2, 0
_080A5E64: .4byte 0x0300014C
