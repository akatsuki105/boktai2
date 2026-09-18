	push {lr}
	movs r1, #0x8c
	lsls r1, r1, #2
	adds r0, r0, r1
	bl EntityMsgBus_Unregister
	pop {r0}
	bx r0
