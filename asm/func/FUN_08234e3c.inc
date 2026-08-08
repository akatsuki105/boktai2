	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2, #2]
	adds r0, #1
	movs r3, #0
	strb r0, [r2, #2]
	ldr r1, [r2, #4]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	blo _08234E56
	strb r3, [r2, #2]
_08234E56:
	strb r3, [r2, #3]
	ldr r0, _08234E74 @ =0x030046A4
	ldr r0, [r0]
	ldr r1, [r0, #0x10]
	ldr r0, [r2, #4]
	ldrh r0, [r0, #2]
	adds r1, r1, r0
	ldrb r0, [r2, #2]
	lsls r0, r0, #3
	adds r1, r1, r0
	str r1, [r2, #8]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_08234E74: .4byte 0x030046A4
