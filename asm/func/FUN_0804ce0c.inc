	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0xea
	ldr r0, _0804CE38 @ =0x0000FFFF
	strh r0, [r1]
	adds r1, #2
	movs r0, #1
	rsbs r0, r0, #0
	strh r0, [r1]
	adds r3, r0, #0
	adds r1, #4
	movs r2, #4
_0804CE26:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0804CE26
	pop {r0}
	bx r0
	.align 2, 0
_0804CE38: .4byte 0x0000FFFF
