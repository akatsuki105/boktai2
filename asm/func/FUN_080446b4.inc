	push {lr}
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _080446D2
	movs r0, #0
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #9
	strb r0, [r1, #5]
	movs r2, #0xb2
	lsls r2, r2, #1
	adds r0, r1, r2
	movs r1, #1
	bl EntityMsgBox_EndWait
_080446D2:
	pop {r0}
	bx r0
	.align 2, 0
