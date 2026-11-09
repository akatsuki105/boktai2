	push {lr}
	ldr r2, _0817FAC4 @ =0x0000046D
	adds r1, r0, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0817FAC0
	movs r0, #0
	strb r0, [r1]
_0817FAC0:
	pop {r0}
	bx r0
	.align 2, 0
_0817FAC4: .4byte 0x0000046D
