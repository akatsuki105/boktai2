	push {lr}
	ldr r1, _08221934 @ =0x00000BFC
	adds r0, r0, r1
	ldr r0, [r0]
	movs r3, #0
	adds r1, r0, #0
	adds r1, #0x54
	movs r2, #7
_0822191C:
	ldrb r0, [r1]
	cmp r0, #0
	beq _08221924
	movs r3, #1
_08221924:
	adds r1, #0x4c
	subs r2, #1
	cmp r2, #0
	bge _0822191C
	adds r0, r3, #0
	pop {r1}
	bx r1
	.align 2, 0
_08221934: .4byte 0x00000BFC
