	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	movs r1, #0xc2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _080E6644
	ldrh r1, [r3, #2]
	ldrh r2, [r3, #4]
	ldrh r3, [r3, #6]
	adds r0, r4, #0
	bl FUN_080e59c4
_080E6644:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
