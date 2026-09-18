	push {r4, lr}
	adds r4, r1, #0
	movs r1, #8
	ldrsh r0, [r2, r1]
	bl FUN_082405c0
	adds r0, r4, #0
	movs r1, #1
	bl EntityMsgBox_EndWait
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
