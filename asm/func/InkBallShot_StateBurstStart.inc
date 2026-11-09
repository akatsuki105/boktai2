	push {r4, lr}
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0xfb
	ldrb r0, [r3]
	cmp r0, #0
	bne _082032BE
	movs r0, #0x1e
	strh r0, [r4, #0x10]
	adds r2, r4, #0
	adds r2, #0x3c
	subs r0, #0x23
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_082032BE:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bls _082032D4
	adds r0, r4, #0
	movs r1, #2
	bl InkBallShot_SetState
_082032D4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
