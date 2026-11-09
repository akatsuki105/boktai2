	push {lr}
	adds r3, r0, #0
	ldr r0, _08204928 @ =0x03000220
	ldr r0, [r0]
	cmp r3, #0
	beq _08204922
	adds r1, r0, #0
	adds r1, #0x3c
	ldrb r0, [r1]
	subs r0, #1
	movs r2, #0
	strb r0, [r1]
	movs r1, #0
	strh r2, [r3, #0x3c]
	adds r0, r3, #0
	adds r0, #0x40
	strb r1, [r0]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_08204922:
	pop {r0}
	bx r0
	.align 2, 0
_08204928: .4byte 0x03000220
