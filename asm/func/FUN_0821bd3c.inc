	push {lr}
	movs r0, #6
	bl FUN_08022a2c
	cmp r0, #0
	beq _0821BD52
	ldr r2, _0821BD58 @ =0x000003D9
	adds r1, r0, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_0821BD52:
	pop {r0}
	bx r0
	.align 2, 0
_0821BD58: .4byte 0x000003D9
