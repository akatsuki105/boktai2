	push {r4, lr}
	adds r4, r0, #0
	bl Entity080acd4c_InitElems
	movs r0, #0xcc
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _080ACD48 @ =0x03002C54
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080ACD48: .4byte 0x03002C54
