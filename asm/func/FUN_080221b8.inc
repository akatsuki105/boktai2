	push {r4, lr}
	adds r4, r1, #0
	ldrh r0, [r2, #8]
	bl FUN_080224a8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0
	beq _080221D0
	movs r1, #0
	bl Script_ExecById
_080221D0:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08022488
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
