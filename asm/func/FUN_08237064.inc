	push {r4, r5, lr}
	adds r4, r0, #0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _08237076
	movs r0, #1
	strb r0, [r4, #7]
_08237076:
	ldrb r0, [r4, #7]
	ldrh r1, [r4, #0xe]
	muls r1, r5, r1
	bl DivArm
	strh r0, [r4, #0xe]
	strb r5, [r4, #7]
	lsls r0, r5, #0x18
	cmp r0, #0
	bne _0823708E
	movs r0, #1
	strb r0, [r4, #7]
_0823708E:
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
