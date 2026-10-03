	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	beq _080435A8
	movs r0, #0
	strb r0, [r4, #8]
	strb r0, [r4, #7]
	movs r0, #2
	strb r0, [r4, #5]
	movs r1, #0xb2
	lsls r1, r1, #1
	adds r0, r4, r1
	movs r1, #1
	bl EntityMsgBox_EndWait
_080435A8:
	ldr r0, [r4, #0x14]
	adds r0, #1
	str r0, [r4, #0x14]
	pop {r4}
	pop {r0}
	bx r0
