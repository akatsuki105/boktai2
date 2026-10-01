	push {lr}
	ldr r1, _0800106C @ =0x03000010
	movs r2, #0
	adds r0, r1, #0
	adds r0, #0xc
_0800105E:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _0800105E
	pop {r0}
	bx r0
	.align 2, 0
_0800106C: .4byte 0x03000010
