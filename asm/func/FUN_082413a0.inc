	push {lr}
	ldr r0, _082413B4 @ =gUnkPtr_030047a8
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	bl FUN_08241260
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_082413B4: .4byte gUnkPtr_030047a8
