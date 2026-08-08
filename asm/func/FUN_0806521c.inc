	push {lr}
	ldr r1, _0806523C @ =0x0000FFFF
	adds r3, r1, #0
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r1, r0, r2
	movs r2, #9
_0806522A:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0806522A
	pop {r0}
	bx r0
	.align 2, 0
_0806523C: .4byte 0x0000FFFF
