	push {lr}
	ldr r1, _08000458 @ =0x03000000
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xc
_0800044A:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0800044A
	pop {r0}
	bx r0
	.align 2, 0
_08000458: .4byte 0x03000000
