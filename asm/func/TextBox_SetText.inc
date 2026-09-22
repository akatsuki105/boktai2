	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08047B88 @ =0x030000C4
	ldr r3, [r0]
	cmp r3, #0
	beq _08047B7E
	adds r1, r3, #0
	adds r1, #0x18
	movs r2, #0xd0
	lsls r2, r2, #1
	adds r0, r3, r2
	movs r2, #0
	str r2, [r0]
	movs r5, #0xc9
	lsls r5, r5, #1
	movs r0, #0
	strh r2, [r5, r3]
	str r4, [r1, #0x1c]
	strb r0, [r1, #8]
	strb r0, [r1, #7]
	movs r0, #0x85
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_08047B7E:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08047B88: .4byte 0x030000C4
