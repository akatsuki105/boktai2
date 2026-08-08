	push {lr}
	ldr r0, _0824141C @ =gUnkPtr_030047a8
	ldr r2, [r0]
	ldrb r1, [r2, #8]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2, #8]
	bl FUN_082410bc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0824141C: .4byte gUnkPtr_030047a8
