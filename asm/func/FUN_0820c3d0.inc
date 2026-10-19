	push {lr}
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	bl MsgQueue_Unregister
	pop {r1}
	bx r1
