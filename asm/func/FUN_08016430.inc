	push {lr}
	adds r2, r0, #0
	ldrh r0, [r2, #6]
	adds r1, r0, #1
	strh r1, [r2, #6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r2, #8]
	cmp r0, r1
	bls _0801644E
	movs r1, #1
	movs r0, #0
	strb r1, [r2, #2]
	strh r0, [r2, #6]
	strb r1, [r2, #1]
_0801644E:
	pop {r0}
	bx r0
	.align 2, 0
