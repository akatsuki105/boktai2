	push {lr}
	ldr r1, _0822D108 @ =0x03004458
	movs r0, #0
	str r0, [r1]
	ldr r0, _0822D10C @ =0x0000FFFF
	adds r3, r0, #0
	ldr r1, _0822D110 @ =0x03004470
	movs r2, #1
_0822D0F4:
	ldrh r0, [r1]
	orrs r0, r3
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0822D0F4
	pop {r0}
	bx r0
	.align 2, 0
_0822D108: .4byte 0x03004458
_0822D10C: .4byte 0x0000FFFF
_0822D110: .4byte 0x03004470
