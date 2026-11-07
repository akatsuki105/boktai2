	push {lr}
	adds r2, r0, #0
	ldr r0, _0812EA8C @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0812EA7E
	movs r0, #0
	strb r0, [r1]
_0812EA7E:
	adds r0, r2, #0
	movs r1, #1
	bl Enemy_PlayAnim
	pop {r0}
	bx r0
	.align 2, 0
_0812EA8C: .4byte 0x0000046D
